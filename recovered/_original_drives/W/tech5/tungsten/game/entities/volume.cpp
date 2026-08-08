
// ========================================================================
// ?OnActivate@idVolume_ShowGui_Leveltransition@@EAAXPAVidEntity@@@Z
// EA  : 0x82D461C8
// RVA : 0x00D461C8
// PDB : w:\tech5\tungsten\game\entities\volume.cpp
// ========================================================================

void __fastcall idVolume_ShowGui_Leveltransition::OnActivate(
        idVolume_ShowGui_Leveltransition *this,
        idEntity *activator)
{
  this->disabledUntilUntouch = false;
}


// ========================================================================
// ?ByteToScale@idPerceptionVolume@@SAME@Z
// EA  : 0x82D461D8
// RVA : 0x00D461D8
// PDB : w:\tech5\tungsten\game\entities\volume.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
float __fastcall idPerceptionVolume::ByteToScale(const unsigned __int8 b, int a2, int a3, int a4, __int64 a5)
{
  int v5; // r9
  double v6; // fp1

  v5 = b >> 4;
  LODWORD(a5) = b & 0xF;
  v6 = (float)((float)((float)a5 * (float)0.0625) + (float)*(__int64 *)((char *)&a5 - 4));
  return *((float *)&v6 + 1);
}


// ========================================================================
// ?Spawn@idVolume_ItemGroup@@QAAXXZ
// EA  : 0x82D46210
// RVA : 0x00D46210
// PDB : w:\tech5\tungsten\game\entities\volume.cpp
// ========================================================================

void __fastcall idVolume_ItemGroup::Spawn(idVolume_ItemGroup *this)
{
  idEventReceiver::PostEventMS(this, ev: &EV_GatherItems, time: 0);
}


// ========================================================================
// ?Enable@idVolume_ItemGroup@@UAAXXZ
// EA  : 0x82D46220
// RVA : 0x00D46220
// PDB : w:\tech5\tungsten\game\entities\volume.cpp
// ========================================================================

void __fastcall idVolume_ItemGroup::Enable(idVolume_ItemGroup *this)
{
  idPhysics *Physics; // r3
  idPhysics *v3; // r3

  Physics = idEntity::GetPhysics(this);
  Physics->SetContents(this: Physics, a2: 2113536, a3: -1);
  v3 = idEntity::GetPhysics(this);
  v3->EnableClip(this: v3);
}


// ========================================================================
// ?Spawn@idVolume_RegimeRegenerate@@QAAXXZ
// EA  : 0x82D46280
// RVA : 0x00D46280
// PDB : w:\tech5\tungsten\game\entities\volume.cpp
// ========================================================================

void __fastcall idVolume_RegimeRegenerate::Spawn(idVolume_RegimeRegenerate *this)
{
  if ( !this->startOff )
    idEntity::BecomeActive(this, flags: 1);
}


// ========================================================================
// ?Spawn@idVolume_ForceDormant@@QAAXXZ
// EA  : 0x82D46298
// RVA : 0x00D46298
// PDB : w:\tech5\tungsten\game\entities\volume.cpp
// ========================================================================

void __fastcall idVolume_ForceDormant::Spawn(idVolume_ForceDormant *this)
{
  idEntity::BecomeInactive(this, flags: 1);
}


// ========================================================================
// ?IsTouchable@idVolume@@QBA_NXZ
// EA  : 0x82D462A0
// RVA : 0x00D462A0
// PDB : w:\tech5\tungsten\game\entities\volume.cpp
// ========================================================================

BOOL __fastcall idVolume::IsTouchable(idVolume *this)
{
  idPhysics *Physics; // r3

  Physics = idEntity::GetPhysics(this);
  return Physics->GetClipModel(this: Physics, a2: 0)->enabled;
}


// ========================================================================
// ?Contains@idVolume_ItemGroup@@QAA_NABVidVec3@@@Z
// EA  : 0x82D462D8
// RVA : 0x00D462D8
// PDB : w:\tech5\tungsten\game\entities\volume.cpp
// ========================================================================

int __fastcall idVolume_ItemGroup::Contains(idVolume *this, const idVec3 *pos)
{
  idPhysics *Physics; // r3
  float *v4; // r3
  double x; // fp12
  double y; // fp13
  double z; // fp0
  double v8; // fp13
  int result; // r3

  Physics = idEntity::GetPhysics(this);
  v4 = (float *)Physics->GetAbsBounds(this: Physics, a2: -1);
  x = pos->x;
  if ( x < *v4 )
    return 0;
  y = pos->y;
  if ( y < v4[1] )
    return 0;
  z = pos->z;
  if ( z < v4[2] )
    return 0;
  if ( x > v4[3] )
    return 0;
  if ( y > v4[4] )
    return 0;
  v8 = v4[5];
  result = 1;
  if ( z > v8 )
    return 0;
  return result;
}


// ========================================================================
// ?Event_NumEntitiesInVolume@idVolume@@QAA?AVeventInt@@XZ
// EA  : 0x82D46378
// RVA : 0x00D46378
// PDB : w:\tech5\tungsten\game\entities\volume.cpp
// ========================================================================

idVolume *__fastcall idVolume::Event_NumEntitiesInVolume(idVolume *this, eventInt *result)
{
  eventInt::eventInt((eventInt *)this, i: result[201].value);
  return this;
}


// ========================================================================
// ?Event_Touch@idVolume_Repairs@@AAA?AVeventVoid@@PAVidEntity@@H@Z
// EA  : 0x82D463B0
// RVA : 0x00D463B0
// PDB : w:\tech5\tungsten\game\entities\volume.cpp
// ========================================================================

idVolume_Repairs *__fastcall idVolume_Repairs::Event_Touch(
        idVolume_Repairs *this,
        idEntity *result,
        idVehicle_Car *other,
        int clipModelId)
{
  idVehicle_Car *v7; // r3
  idVehicle_Car *v8; // r30
  idVehicle_Car_vtbl *v9; // r29
  const idSoundShader *v10; // r5
  __int64 v12; // [sp+50h] [-30h]

  v7 = idVehicle_Car::CastTo(c: other);
  v8 = v7;
  if ( other != nullptr )
  {
    v9 = v7->__vftable;
    v12 = __PAIR64__(&off_82040000, gameLocal->GetGameMsPerFrame(this: gameLocal, a2: GAMETIME_SCALED));
    if ( v9->IncreaseHealth(
           this: v8,
           a2: (float)((float)((float)v12 * *(float *)result[1].name.baseBuffer) * (float)0.001)) )
    {
      if ( result[1].name.baseBuffer[8] != 0 )
      {
        idEntity::StopSound(this: result, channel: SND_CHANNEL_AMBIENT, peerMask: 0xFFu);
        result[1].name.baseBuffer[8] = 0;
      }
    }
    else if ( result[1].name.baseBuffer[8] == 0 )
    {
      v10 = *(const idSoundShader **)&result[1].name.baseBuffer[4];
      if ( v10 != nullptr )
      {
        idEntity::StartSoundShader(
          this: result,
          channel: SND_CHANNEL_AMBIENT,
          shader: v10,
          soundShaderFlags: (soundShaderFlags_t)0,
          peerMask: 0xFFu);
        result[1].name.baseBuffer[8] = 1;
        return this;
      }
    }
  }
  return this;
}


// ========================================================================
// ?DeactivateGui@idVolume_ShowGui_Leveltransition@@AAAXPAVidEntity@@@Z
// EA  : 0x82D464B0
// RVA : 0x00D464B0
// PDB : w:\tech5\tungsten\game\entities\volume.cpp
// ========================================================================

void __fastcall idVolume_ShowGui_Leveltransition::DeactivateGui(
        idVolume_ShowGui_Leveltransition *this,
        idEntity *other)
{
  idPlayer *PlayerFromEntity; // r3

  PlayerFromEntity = idGameLocal::GetPlayerFromEntity(this: gameLocal, activator: other);
  if ( PlayerFromEntity != nullptr && PlayerFromEntity->levelTransitionGuiVolume == this )
    idPlayer::ClearLevelTransitionGuiVolume(this: PlayerFromEntity);
}


// ========================================================================
// ?RemovePlayer@idVolume_ShowGui_Leveltransition@@QAAXPAVidPlayer@@@Z
// EA  : 0x82D46500
// RVA : 0x00D46500
// PDB : w:\tech5\tungsten\game\entities\volume.cpp
// ========================================================================

void __fastcall idVolume_ShowGui_Leveltransition::RemovePlayer(
        idVolume_ShowGui_Leveltransition *this,
        idPlayer *player)
{
  idPlayer *PlayerFromEntity; // r3

  PlayerFromEntity = idGameLocal::GetPlayerFromEntity(this: gameLocal, activator: player);
  if ( PlayerFromEntity != nullptr && PlayerFromEntity->levelTransitionGuiVolume == this )
    idPlayer::ClearLevelTransitionGuiVolume(this: PlayerFromEntity);
  this->disabledUntilUntouch = false;
}


// ========================================================================
// ?Spawn@idPerceptionVolume@@QAAXXZ
// EA  : 0x82D46558
// RVA : 0x00D46558
// PDB : w:\tech5\tungsten\game\entities\volume.cpp
// ========================================================================

void __fastcall idPerceptionVolume::Spawn(idPerceptionVolume *this)
{
  double scale; // fp1
  double gunfireRadius; // fp1
  double distanceScale; // fp1

  scale = this->scale;
  if ( scale > 10.0 )
  {
    idLib::Warning(fmt: "perception volume %s scale clamped from %f to max value of %f", this->name.data, scale, 10.0);
    this->scale = 1092616192;
  }
  gunfireRadius = this->gunfireRadius;
  if ( gunfireRadius > 10000.0 )
  {
    idLib::Warning(
      fmt: "perception volume %s gunfireRadius clamped from %f to max value of %f",
      this->name.data,
      gunfireRadius,
      10000.0);
    this->gunfireRadius = 1176256512;
  }
  distanceScale = this->distanceScale;
  if ( distanceScale < 0.0099999998 )
  {
    idLib::Warning(
      fmt: "perception volume %s distanceScale clamped from %f to min value of %f",
      (const char *)HIDWORD(distanceScale),
      distanceScale,
      0.009999999776482582);
    this->distanceScale = 1008981770;
  }
}


// ========================================================================
// ?ScaleToByte@idPerceptionVolume@@SAEM@Z
// EA  : 0x82D46658
// RVA : 0x00D46658
// PDB : w:\tech5\tungsten\game\entities\volume.cpp
// ========================================================================

int __fastcall idPerceptionVolume::ScaleToByte(long double scale)
{
  double v1; // fp31
  long double v2; // fp2
  int v3; // r11
  char v4; // r10
  int v5; // r11

  v1 = *(double *)&scale;
  v2 = floor(x: scale);
  v3 = (int)(float)((float)v1 - (float)((float)v1 - (float)*(double *)&v2));
  if ( v3 >= 0 )
  {
    v4 = -1;
    if ( v3 <= 255 )
      v4 = v3;
  }
  else
  {
    v4 = 0;
  }
  v5 = (int)(float)((float)((float)v1 - (float)*(double *)&v2) * (float)16.0);
  if ( v5 >= 0 )
  {
    if ( v5 > 255 )
      LOBYTE(v5) = -1;
  }
  else
  {
    LOBYTE(v5) = 0;
  }
  return (unsigned __int8)(16 * v4) | (unsigned __int8)v5;
}


// ========================================================================
// ?Spawn@idVolume_PlayerViewEffect@@QAAXXZ
// EA  : 0x82D46708
// RVA : 0x00D46708
// PDB : w:\tech5\tungsten\game\entities\volume.cpp
// ========================================================================

void __fastcall idVolume_PlayerViewEffect::Spawn(idVolume_PlayerViewEffect *this)
{
  idClientGame *v2; // r8
  __int64 v3; // r8
  fxEmitterSound_t v4[2]; // [sp+50h] [-20h] BYREF

  if ( this->fxDecl != nullptr )
  {
    v4[0].emitter = idEntity::GetSoundEmitter(this, alloc: true);
    v4[0].channel = SND_CHANNEL_FX;
    v2 = clientGame;
    HIDWORD(v3) = 1664525 * clientGame->random.seed + 1013904223;
    clientGame->random.seed = HIDWORD(v3);
    LODWORD(v3) = (v2->random.seed >> 10) & 0x7FFF;
    v4[1] = (fxEmitterSound_t)v3;
    idFXManager::Init(
      this: &this->fxManager,
      declFX: this->fxDecl,
      _rw: clientGame->renderWorld,
      _soundInfo: v4,
      _gameLibEffects: &clientGame->gameLibEffects,
      diversity: (float)((float)v3 * (float)0.000030518509),
      _ta: (idTreeAnimator *)v3,
      a8: nullptr);
  }
}


// ========================================================================
// ?Think@idVolume_PlayerViewEffect@@UAAXXZ
// EA  : 0x82D467C8
// RVA : 0x00D467C8
// PDB : w:\tech5\tungsten\game\entities\volume.cpp
// ========================================================================

void __fastcall idVolume_PlayerViewEffect::Think(idVolume_PlayerViewEffect *this)
{
  idPhysics *Physics; // r29
  idPhysics *v3; // r27
  int v4; // r26
  unsigned int GameMsPerFrame; // r28
  int GameMs; // r31
  const idMat3 *v7; // r29
  const idVec3 *v8; // r3

  idEntity::Think(this);
  if ( (this->thinkFlags & 1) != 0 )
  {
    Physics = idEntity::GetPhysics(this);
    v3 = idEntity::GetPhysics(this);
    v4 = idAccolade::Count(this: &clientGame->gameTimeManager);
    GameMsPerFrame = idGameTimeManager::GetGameMsPerFrame(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    v7 = Physics->GetAxis(this: Physics, a2: 0);
    v8 = v3->GetOrigin(this: v3, a2: 0);
    idFXManager::Update(
      this: &this->fxManager,
      parentOrigin: v8,
      parentAxis: v7,
      parentVel: &vec3_origin,
      time: GameMs,
      gameMsPerFrame: GameMsPerFrame,
      frameNum: v4,
      fovScale: 1.0,
      depthHack: 0.0);
  }
}


// ========================================================================
// ?Event_Touch@idVolume_PlayerViewEffect@@AAA?AVeventVoid@@PAVidEntity@@H@Z
// EA  : 0x82D468B8
// RVA : 0x00D468B8
// PDB : w:\tech5\tungsten\game\entities\volume.cpp
// ========================================================================

idVolume_PlayerViewEffect *__fastcall idVolume_PlayerViewEffect::Event_Touch(
        idVolume_PlayerViewEffect *this,
        idEntity *result,
        idPlayer *other,
        int clipModelId)
{
  idPlayer *v6; // r3
  idPlayer *v7; // r30
  int v8; // r11
  void (__fastcall *GetColor_2)(idEntity *, idColor *); // r9
  idPresentable *v10; // r3
  int v11; // r3
  idPresentable *v13; // r3
  idPresentablePlayer *v14; // r3
  idPhysics *Physics; // r30
  idPhysics *v16; // r28
  int GameMs; // r27
  const idMat3 *v18; // r30
  const idVec3 *v19; // r3
  idPresentable *presentable; // r3
  int v21; // r3
  idVec4 v22[4]; // [sp+50h] [-40h] BYREF

  v6 = idPlayer::CastTo(c: other);
  v7 = v6;
  if ( v6 == nullptr )
    return this;
  v8 = *(_DWORD *)&result[1].name.baseBuffer[8];
  if ( v8 == 0 )
  {
    presentable = v6->presentable;
    if ( presentable != nullptr )
      v21 = (int)presentable->GetPlayerInterface_2(this: presentable);
    else
      v21 = 0;
    idView::Flash(
      this: (idView *)(v21 + 16224),
      color: (const idVec4 *)&idColor::colorWhite,
      time: *(_DWORD *)result[1].name.baseBuffer);
    return this;
  }
  if ( v8 != 2 )
  {
    if ( v8 == 3 && result[2].name.baseBuffer[12] == 0 )
    {
      GetColor_2 = result->GetColor_2;
      v22[0].w = -1.0;
      v22[0].z = -1.0;
      v22[0].y = -1.0;
      v22[0].x = -1.0;
      GetColor_2(this: result, a2: (idColor *)v22);
      v10 = v7->presentable;
      if ( v10 != nullptr )
        v11 = (int)v10->GetPlayerInterface_2(this: v10);
      else
        v11 = 0;
      idView::Fade(this: (idView *)(v11 + 16224), color: v22, time: *(_DWORD *)result[1].name.baseBuffer);
      result[2].name.baseBuffer[12] = 1;
      return this;
    }
    return this;
  }
  if ( LODWORD(result[1].spawnOrientation.mat[0].z) != 0 )
  {
    if ( result[2].name.baseBuffer[12] == 0 )
    {
      Physics = idEntity::GetPhysics(this: result);
      v16 = idEntity::GetPhysics(this: result);
      GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      v18 = Physics->GetAxis(this: Physics, a2: 0);
      v19 = v16->GetOrigin(this: v16, a2: 0);
      idFXManager::StartFX(
        this: (idFXManager *)&result[1].spawnOrientation.mat[1],
        org: v19,
        axis: v18,
        time: GameMs,
        startCondition: 0);
      result[2].name.baseBuffer[12] = 1;
      idEntity::BecomeActive(this: result, flags: 1);
      return this;
    }
    return this;
  }
  v13 = v6->presentable;
  if ( v13 != nullptr )
  {
    v14 = v13->GetPlayerInterface_2(this: v13);
    idPresentablePlayer::StartScreenParticle(
      this: v14,
      screenPrtType: LODWORD(result[1].spawnOrientation.mat[0].x),
      excludeAngle: result[1].spawnOrientation.mat[0].y);
  }
  else
  {
    idPresentablePlayer::StartScreenParticle(
      this: nullptr,
      screenPrtType: LODWORD(result[1].spawnOrientation.mat[0].x),
      excludeAngle: result[1].spawnOrientation.mat[0].y);
  }
  return this;
}


// ========================================================================
// ?Event_Untouch@idVolume_PlayerViewEffect@@AAA?AVeventVoid@@PAVidEntity@@H@Z
// EA  : 0x82D46AD0
// RVA : 0x00D46AD0
// PDB : w:\tech5\tungsten\game\entities\volume.cpp
// ========================================================================

idVolume_PlayerViewEffect *__fastcall idVolume_PlayerViewEffect::Event_Untouch(
        idVolume_PlayerViewEffect *this,
        idEventReceiver *result,
        idPlayer *other,
        int clipModelId)
{
  idPlayer *v6; // r3
  idEntity *v7; // r30
  idList<idEventReceiver *,5> *listenerList; // r11
  idTypeInfo *(__fastcall *GetType)(struct idEventReceiver *); // r9
  idPresentable *presentable; // r3
  int v11; // r3
  idPresentable *v13; // r3
  int v14; // r30
  unsigned int v15; // r31
  idPresentablePlayer *v16; // r3
  int GameMs; // r3
  idDeclFX *v18; // r3
  int MaxFadeOutTime; // r3
  idVec4 v20[3]; // [sp+50h] [-30h] BYREF

  v6 = idPlayer::CastTo(c: other);
  v7 = v6;
  if ( v6 == nullptr )
    return this;
  listenerList = result[69].listenerList;
  if ( listenerList != (idList<idEventReceiver *,5> *)2 )
  {
    if ( listenerList == (idList<idEventReceiver *,5> *)3 && HIBYTE(result[136].listenerList) != 0 )
    {
      GetType = result->__vftable[5].GetType;
      v20[0].w = -1.0;
      v20[0].z = -1.0;
      v20[0].y = -1.0;
      v20[0].x = -1.0;
      ((void (__fastcall *)(idEventReceiver *, idVec4 *))GetType)(a1: result, a2: v20);
      v20[0].w = 0.0;
      presentable = v7->presentable;
      if ( presentable != nullptr )
        v11 = (int)presentable->GetPlayerInterface_2(this: presentable);
      else
        v11 = 0;
      idView::Fade(this: (idView *)(v11 + 16224), color: v20, time: (int)result[69].__vftable);
      HIBYTE(result[136].listenerList) = 0;
      return this;
    }
    return this;
  }
  if ( result[72].__vftable != nullptr )
  {
    if ( HIBYTE(result[136].listenerList) != 0 )
    {
      GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      idFXManager::StopFX(
        this: (idFXManager *)&result[72].listenerList,
        time: GameMs,
        stopCondition: 0,
        immediateStop: false);
      v18 = (idDeclFX *)result[72].__vftable;
      HIBYTE(result[136].listenerList) = 0;
      MaxFadeOutTime = idDeclFX::GetMaxFadeOutTime(this: v18, startCondition: FX_NONE);
      idEventReceiver::PostEventMS(this: result, ev: &EV_Deactivate, time: MaxFadeOutTime);
    }
    return this;
  }
  v13 = v6->presentable;
  if ( v13 == nullptr )
  {
    idEntity::InitPresentableInternal(this: v7);
    v13 = v7->presentable;
  }
  v14 = (int)result[69].__vftable;
  v15 = (unsigned int)result[71].listenerList;
  v16 = v13->GetPlayerInterface_2(this: v13);
  idPresentablePlayer::StopScreenParticle(this: v16, screenPrtType: v15, fadeTime: v14);
  return this;
}


// ========================================================================
// ?Event_Deactivate@idVolume_PlayerViewEffect@@AAA?AVeventVoid@@XZ
// EA  : 0x82D46C60
// RVA : 0x00D46C60
// PDB : w:\tech5\tungsten\game\entities\volume.cpp
// ========================================================================

idVolume_PlayerViewEffect *__fastcall idVolume_PlayerViewEffect::Event_Deactivate(
        idVolume_PlayerViewEffect *this,
        idEntity *result)
{
  idEntity::BecomeInactive(this: result, flags: 1);
  return this;
}


// ========================================================================
// ?Event_Reset@idVolume_RegimeRegenerate@@AAA?AVeventVoid@@XZ
// EA  : 0x82D46C98
// RVA : 0x00D46C98
// PDB : w:\tech5\tungsten\game\entities\volume.cpp
// ========================================================================

idVolume_RegimeRegenerate *__fastcall idVolume_RegimeRegenerate::Event_Reset(
        idVolume_RegimeRegenerate *this,
        idEntity *result)
{
  idEntity::BecomeActive(this: result, flags: 1);
  return this;
}


// ========================================================================
// ?FindGroup@idCombatVolume@@ABAPAVidCombatVolumeGroup@@PBD@Z
// EA  : 0x82D46CD0
// RVA : 0x00D46CD0
// PDB : w:\tech5\tungsten\game\entities\volume.cpp
// ========================================================================

idCombatVolumeGroup *__fastcall idCombatVolume::FindGroup(idCombatVolume *this, const char *groupName)
{
  int v4; // r29
  int i; // r31

  v4 = 0;
  if ( this->groups.num <= 0 )
    return nullptr;
  for ( i = 0; idStr::Cmp(s1: this->groups.list[i]->groupName.data, s2: groupName) != 0; ++i )
  {
    if ( ++v4 >= this->groups.num )
      return nullptr;
  }
  return this->groups.list[v4];
}


// ========================================================================
// ??0idVolume@@QAA@XZ
// EA  : 0x82D46D50
// RVA : 0x00D46D50
// PDB : w:\tech5\tungsten\game\entities\volume.cpp
// ========================================================================

idVolume *__fastcall idVolume::idVolume(idVolume *this)
{
  char v2; // r7

  idEntity::idEntity(this);
  this->__vftable = (idVolume_vtbl *)&idVolume::`vftable';
  this->touching.list = nullptr;
  this->touching.granularity = 0;
  this->touching.memTag = 5;
  this->touching.listStatic = 0;
  this->touching.size = 0;
  this->touching.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->touching);
  v2 = *((_BYTE *)this + 816);
  this->startEnabled = true;
  this->clipModelInfo.type = CLIPMODEL_RENDERMODEL;
  *((_BYTE *)this + 816) = v2 & 0x7F;
  return this;
}


// ========================================================================
// __unwind$492317
// EA  : 0x82D46DDC
// RVA : 0x00D46DDC
// PDB : w:\tech5\tungsten\game\entities\volume.cpp
// ========================================================================

void _unwind_492317()
{
  int v0; // r12

  idEntity::~idEntity(this: *(idEntity **)(v0 - 112 + 132));
}


// ========================================================================
// ??1idVolume@@UAA@XZ
// EA  : 0x82D46E10
// RVA : 0x00D46E10
// PDB : w:\tech5\tungsten\game\entities\volume.cpp
// ========================================================================

void __fastcall idVolume::~idVolume(idVolume *this)
{
  this->__vftable = (idVolume_vtbl *)&idVolume::`vftable';
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->touching);
  idEntity::~idEntity(this);
}


// ========================================================================
// __unwind$492546
// EA  : 0x82D46E64
// RVA : 0x00D46E64
// PDB : w:\tech5\tungsten\game\entities\volume.cpp
// ========================================================================

void _unwind_492546()
{
  int v0; // r12

  idEntity::~idEntity(this: *(idEntity **)(v0 - 112 + 132));
}


// ========================================================================
// ?RemoveTouching@idVolume@@QAA_NPAVidEntity@@@Z
// EA  : 0x82D46E90
// RVA : 0x00D46E90
// PDB : w:\tech5\tungsten\game\entities\volume.cpp
// ========================================================================

int __fastcall idVolume::RemoveTouching(idVolume *this, idEntity *other)
{
  int v4; // r30
  idList<idEntityPtr<idEntity>,5> *p_touching; // r29
  int v6; // r31
  idSpawnId *v7; // r4
  int value; // r10
  idEntity *v9; // r3
  idEntity *v10; // r3
  char **SpawnId; // r3
  int num; // r11
  int v14; // r11
  char v15; // [sp+50h] [-40h] BYREF

  v4 = 0;
  if ( this->touching.num <= 0 )
    return 0;
  p_touching = &this->touching;
  v6 = 0;
  v7 = (idSpawnId *)gameLocal;
  while ( 1 )
  {
    value = p_touching->list[v6].spawnId.value;
    if ( v7[(value & 0x1FFF) + 29755].value == value >> 13
      && (v9 = (idEntity *)v7[(value & 0x1FFF) + 21563].value) != nullptr )
    {
      v10 = idEntity::CastTo(c: v9);
      v7 = (idSpawnId *)gameLocal;
    }
    else
    {
      v10 = nullptr;
    }
    if ( v10 == other )
      break;
    ++v4;
    ++v6;
    if ( v4 >= this->touching.num )
      return 0;
  }
  SpawnId = (char **)idGameLocal::GetSpawnId(this: (idGameLocal *)&v15, result: v7, ent: other);
  idEntity::SendNotify_OnExit(this, dude: *SpawnId);
  if ( v4 >= 0 )
  {
    num = p_touching->num;
    if ( v4 < num )
    {
      v14 = num - 1;
      p_touching->num = v14;
      if ( v4 != v14 )
        p_touching->list[v4].spawnId.value = p_touching->list[v14].spawnId.value;
    }
  }
  return 1;
}


// ========================================================================
// ?IsTouching@idVolume@@QBA_NPBVidEntity@@@Z
// EA  : 0x82D46F98
// RVA : 0x00D46F98
// PDB : w:\tech5\tungsten\game\entities\volume.cpp
// ========================================================================

int __fastcall idVolume::IsTouching(idVolume *this, const idEntity *other)
{
  int v4; // r29
  int v5; // r31
  idGameLocal *v6; // r10
  int value; // r9
  idEntity *v8; // r3
  idEntity *v9; // r3

  v4 = 0;
  if ( this->touching.num <= 0 )
    return 0;
  v5 = 0;
  v6 = gameLocal;
  while ( 1 )
  {
    value = this->touching.list[v5].spawnId.value;
    if ( v6->spawnIds.ptr[value & 0x1FFF] == value >> 13 && (v8 = v6->entities.ptr[value & 0x1FFF]) != nullptr )
    {
      v9 = idEntity::CastTo(c: v8);
      v6 = gameLocal;
    }
    else
    {
      v9 = nullptr;
    }
    if ( v9 == other )
      break;
    ++v4;
    ++v5;
    if ( v4 >= this->touching.num )
      return 0;
  }
  return 1;
}


// ========================================================================
// ?Event_NumEntitiesInVolumeByName@idVolume@@QAA?AVeventInt@@PBD@Z
// EA  : 0x82D47048
// RVA : 0x00D47048
// PDB : w:\tech5\tungsten\game\entities\volume.cpp
// ========================================================================

idVolume *__fastcall idVolume::Event_NumEntitiesInVolumeByName(idVolume *this, eventInt *result, const char *subStr)
{
  int v6; // r27
  int v7; // r28
  int v8; // r30
  int v9; // r9
  idEntity *v10; // r3
  idEntity *v11; // r3

  v6 = 0;
  v7 = 0;
  if ( result[201].value > 0 )
  {
    v8 = 0;
    do
    {
      v9 = *(_DWORD *)(v8 + result[200].value);
      if ( gameLocal->spawnIds.ptr[v9 & 0x1FFF] == v9 >> 13 )
      {
        v10 = gameLocal->entities.ptr[v9 & 0x1FFF];
        if ( v10 != nullptr )
        {
          v11 = idEntity::CastTo(c: v10);
          if ( v11 != nullptr
            && idStr::Find(searchIn: v11->name.data, searchFor: subStr, casesensitive: false, start: 0, end: -1) >= 0 )
          {
            ++v6;
          }
        }
      }
      ++v7;
      v8 += 4;
    }
    while ( v7 < result[201].value );
  }
  eventInt::eventInt((eventInt *)this, i: v6);
  return this;
}


// ========================================================================
// ?Event_NumAIsInVolume@idVolume@@QAA?AVeventInt@@XZ
// EA  : 0x82D47118
// RVA : 0x00D47118
// PDB : w:\tech5\tungsten\game\entities\volume.cpp
// ========================================================================

idVolume *__fastcall idVolume::Event_NumAIsInVolume(idVolume *this, eventInt *result)
{
  int v4; // r27
  int v5; // r29
  int v6; // r31
  int v7; // r9
  idEntity *v8; // r3
  idAI2 *v9; // r3

  v4 = 0;
  v5 = 0;
  if ( result[201].value > 0 )
  {
    v6 = 0;
    do
    {
      v7 = *(_DWORD *)(v6 + result[200].value);
      if ( gameLocal->spawnIds.ptr[v7 & 0x1FFF] == v7 >> 13 && (v8 = gameLocal->entities.ptr[v7 & 0x1FFF]) != nullptr )
        v9 = (idAI2 *)idEntity::CastTo(c: v8);
      else
        v9 = nullptr;
      if ( idAI2::CastTo(c: v9) != nullptr )
        ++v4;
      ++v5;
      v6 += 4;
    }
    while ( v5 < result[201].value );
  }
  eventInt::eventInt((eventInt *)this, i: v4);
  return this;
}


// ========================================================================
// ?Event_NumPlayersInVolume@idVolume@@QAA?AVeventInt@@XZ
// EA  : 0x82D471D0
// RVA : 0x00D471D0
// PDB : w:\tech5\tungsten\game\entities\volume.cpp
// ========================================================================

idVolume *__fastcall idVolume::Event_NumPlayersInVolume(idVolume *this, eventInt *result)
{
  int v4; // r27
  int v5; // r29
  int v6; // r31
  int v7; // r9
  idEntity *v8; // r3
  idPlayer *v9; // r3

  v4 = 0;
  v5 = 0;
  if ( result[201].value > 0 )
  {
    v6 = 0;
    do
    {
      v7 = *(_DWORD *)(v6 + result[200].value);
      if ( gameLocal->spawnIds.ptr[v7 & 0x1FFF] == v7 >> 13 && (v8 = gameLocal->entities.ptr[v7 & 0x1FFF]) != nullptr )
        v9 = (idPlayer *)idEntity::CastTo(c: v8);
      else
        v9 = nullptr;
      if ( idPlayer::CastTo(c: v9) != nullptr )
        ++v4;
      ++v5;
      v6 += 4;
    }
    while ( v5 < result[201].value );
  }
  eventInt::eventInt((eventInt *)this, i: v4);
  return this;
}


// ========================================================================
// ?Event_NumVehiclesInVolume@idVolume@@QAA?AVeventInt@@XZ
// EA  : 0x82D47288
// RVA : 0x00D47288
// PDB : w:\tech5\tungsten\game\entities\volume.cpp
// ========================================================================

idVolume *__fastcall idVolume::Event_NumVehiclesInVolume(idVolume *this, eventInt *result)
{
  int v4; // r27
  int v5; // r29
  int v6; // r31
  int v7; // r9
  idEntity *v8; // r3
  idVehicle *v9; // r3

  v4 = 0;
  v5 = 0;
  if ( result[201].value > 0 )
  {
    v6 = 0;
    do
    {
      v7 = *(_DWORD *)(v6 + result[200].value);
      if ( gameLocal->spawnIds.ptr[v7 & 0x1FFF] == v7 >> 13 && (v8 = gameLocal->entities.ptr[v7 & 0x1FFF]) != nullptr )
        v9 = (idVehicle *)idEntity::CastTo(c: v8);
      else
        v9 = nullptr;
      if ( idVehicle::CastTo(c: v9) != nullptr )
        ++v4;
      ++v5;
      v6 += 4;
    }
    while ( v5 < result[201].value );
  }
  eventInt::eventInt((eventInt *)this, i: v4);
  return this;
}


// ========================================================================
// ?Event_NumDronesInVolume@idVolume@@QAA?AVeventInt@@XZ
// EA  : 0x82D47340
// RVA : 0x00D47340
// PDB : w:\tech5\tungsten\game\entities\volume.cpp
// ========================================================================

idVolume *__fastcall idVolume::Event_NumDronesInVolume(idVolume *this, eventInt *result)
{
  int v4; // r27
  int v5; // r29
  int v6; // r31
  int v7; // r9
  idEntity *v8; // r3
  idDrone *v9; // r3

  v4 = 0;
  v5 = 0;
  if ( result[201].value > 0 )
  {
    v6 = 0;
    do
    {
      v7 = *(_DWORD *)(v6 + result[200].value);
      if ( gameLocal->spawnIds.ptr[v7 & 0x1FFF] == v7 >> 13 && (v8 = gameLocal->entities.ptr[v7 & 0x1FFF]) != nullptr )
        v9 = (idDrone *)idEntity::CastTo(c: v8);
      else
        v9 = nullptr;
      if ( idDrone::CastTo(c: v9) != nullptr )
        ++v4;
      ++v5;
      v6 += 4;
    }
    while ( v5 < result[201].value );
  }
  eventInt::eventInt((eventInt *)this, i: v4);
  return this;
}


// ========================================================================
// ?Event_NumDropShipsInVolume@idVolume@@QAA?AVeventInt@@XZ
// EA  : 0x82D473F8
// RVA : 0x00D473F8
// PDB : w:\tech5\tungsten\game\entities\volume.cpp
// ========================================================================

idVolume *__fastcall idVolume::Event_NumDropShipsInVolume(idVolume *this, eventInt *result)
{
  int v4; // r27
  int v5; // r29
  int v6; // r31
  int v7; // r9
  idEntity *v8; // r3
  idDropShip *v9; // r3

  v4 = 0;
  v5 = 0;
  if ( result[201].value > 0 )
  {
    v6 = 0;
    do
    {
      v7 = *(_DWORD *)(v6 + result[200].value);
      if ( gameLocal->spawnIds.ptr[v7 & 0x1FFF] == v7 >> 13 && (v8 = gameLocal->entities.ptr[v7 & 0x1FFF]) != nullptr )
        v9 = (idDropShip *)idEntity::CastTo(c: v8);
      else
        v9 = nullptr;
      if ( idDropShip::CastTo(c: v9) != nullptr )
        ++v4;
      ++v5;
      v6 += 4;
    }
    while ( v5 < result[201].value );
  }
  eventInt::eventInt((eventInt *)this, i: v4);
  return this;
}


// ========================================================================
// ?Event_IsEntityInVolume@idVolume@@QAA?AVeventBool@@PBVidEntity@@@Z
// EA  : 0x82D474B0
// RVA : 0x00D474B0
// PDB : w:\tech5\tungsten\game\entities\volume.cpp
// ========================================================================

idVolume *__fastcall idVolume::Event_IsEntityInVolume(idVolume *this, idVolume *result, const idEntity *entity)
{
  char IsTouching; // r3

  IsTouching = idVolume::IsTouching(this: result, other: entity);
  eventBool::eventBool((eventBool *)this, b: IsTouching);
  return this;
}


// ========================================================================
// ??0idPerceptionVolume@@QAA@XZ
// EA  : 0x82D474F8
// RVA : 0x00D474F8
// PDB : w:\tech5\tungsten\game\entities\volume.cpp
// ========================================================================

idPerceptionVolume *__fastcall idPerceptionVolume::idPerceptionVolume(idPerceptionVolume *this)
{
  idVolume::idVolume(this);
  this->__vftable = (idPerceptionVolume_vtbl *)&idPerceptionVolume::`vftable';
  this->scale = 0.5;
  this->distanceScale = 1.0;
  this->gunfireRadius = 2048.0;
  return this;
}


// ========================================================================
// ??0idVolume_Stairs@@QAA@XZ
// EA  : 0x82D47558
// RVA : 0x00D47558
// PDB : w:\tech5\tungsten\game\entities\volume.cpp
// ========================================================================

idVolume_Stairs *__fastcall idVolume_Stairs::idVolume_Stairs(idVolume_Stairs *this)
{
  idVolume::idVolume(this);
  this->__vftable = (idVolume_Stairs_vtbl *)&idVolume_Stairs::`vftable';
  return this;
}


// ========================================================================
// ?Event_Untouch@idVolume_Stairs@@QAA?AVeventVoid@@PAVidEntity@@H@Z
// EA  : 0x82D47598
// RVA : 0x00D47598
// PDB : w:\tech5\tungsten\game\entities\volume.cpp
// ========================================================================

idVolume_Stairs *__fastcall idVolume_Stairs::Event_Untouch(
        idVolume_Stairs *this,
        idVolume *result,
        idActor *other,
        int clipModelId)
{
  idActor *v6; // r11
  idVolume_Stairs *v7; // r3

  idVolume::RemoveTouching(this: result, other);
  v6 = idActor::CastTo(c: other);
  v7 = this;
  if ( v6 != nullptr )
    v6->actorVolatile.onStairs = false;
  return v7;
}


// ========================================================================
// ??0idVolume_DamageMultiplier@@QAA@XZ
// EA  : 0x82D475F8
// RVA : 0x00D475F8
// PDB : w:\tech5\tungsten\game\entities\volume.cpp
// ========================================================================

idVolume_DamageMultiplier *__fastcall idVolume_DamageMultiplier::idVolume_DamageMultiplier(
        idVolume_DamageMultiplier *this)
{
  idVolume::idVolume(this);
  this->playerCanActivate = true;
  this->__vftable = (idVolume_DamageMultiplier_vtbl *)&idVolume_DamageMultiplier::`vftable';
  this->damageMultiplier = 1.0;
  this->AICanActivate = false;
  return this;
}


// ========================================================================
// ?Event_Untouch@idVolume_DamageMultiplier@@QAA?AVeventVoid@@PAVidEntity@@H@Z
// EA  : 0x82D47650
// RVA : 0x00D47650
// PDB : w:\tech5\tungsten\game\entities\volume.cpp
// ========================================================================

idVolume_DamageMultiplier *__fastcall idVolume_DamageMultiplier::Event_Untouch(
        idVolume_DamageMultiplier *this,
        idVolume *result,
        idActor *other,
        int clipModelId)
{
  idActor *v7; // r3

  if ( (HIBYTE(result[1].listenerList) != 0 || (unsigned __int8)idPlayer::IsTypeOf(c: other) == 0)
    && (BYTE1(result[1].listenerList) != 0 || (unsigned __int8)idAI2::IsTypeOf(c: other) == 0) )
  {
    idVolume::RemoveTouching(this: result, other);
    v7 = idActor::CastTo(c: other);
    if ( v7 != nullptr )
      v7->actorVolatile.damageTakenMultiplier = 1.0;
  }
  return this;
}


// ========================================================================
// ??0idVolume_PlayerViewEffect@@QAA@XZ
// EA  : 0x82D476E8
// RVA : 0x00D476E8
// PDB : w:\tech5\tungsten\game\entities\volume.cpp
// ========================================================================

idVolume_PlayerViewEffect *__fastcall idVolume_PlayerViewEffect::idVolume_PlayerViewEffect(
        idVolume_PlayerViewEffect *this)
{
  idVolume::idVolume(this);
  this->fadeOutTime = 0;
  this->time = 1000;
  this->excludeAngle = -1.0;
  this->__vftable = (idVolume_PlayerViewEffect_vtbl *)&idVolume_PlayerViewEffect::`vftable';
  this->viewEffectType = 0;
  this->screenPrtType = SCREEN_PRT_WATER_DROPLETS;
  this->fxDecl = nullptr;
  idFXManager::idFXManager(this: &this->fxManager);
  this->screenEffect.screenX = -1.0;
  this->started = false;
  this->screenEffect.screenY = -1.0;
  this->screenEffect.material = nullptr;
  this->screenEffect.width = 0.0;
  this->screenEffect.height = 0.0;
  return this;
}


// ========================================================================
// __unwind$493025
// EA  : 0x82D47774
// RVA : 0x00D47774
// PDB : w:\tech5\tungsten\game\entities\volume.cpp
// ========================================================================

void _unwind_493025()
{
  int v0; // r12

  idVolume::~idVolume(this: *(idVolume **)(v0 - 128 + 148));
}


// ========================================================================
// ??1idVolume_PlayerViewEffect@@UAA@XZ
// EA  : 0x82D477A8
// RVA : 0x00D477A8
// PDB : w:\tech5\tungsten\game\entities\volume.cpp
// ========================================================================

void __fastcall idVolume_PlayerViewEffect::~idVolume_PlayerViewEffect(idVolume_PlayerViewEffect *this)
{
  idFXManager *p_fxManager; // r29

  this->__vftable = (idVolume_PlayerViewEffect_vtbl *)&idVolume_PlayerViewEffect::`vftable';
  p_fxManager = &this->fxManager;
  idFXManager::Shutdown(this: &this->fxManager);
  idFXManager::~idFXManager(this: p_fxManager);
  idVolume::~idVolume(this);
}


// ========================================================================
// __unwind$493042
// EA  : 0x82D477F0
// RVA : 0x00D477F0
// PDB : w:\tech5\tungsten\game\entities\volume.cpp
// ========================================================================

void _unwind_493042()
{
  int v0; // r12

  idVolume::~idVolume(this: *(idVolume **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$493043
// EA  : 0x82D47818
// RVA : 0x00D47818
// PDB : w:\tech5\tungsten\game\entities\volume.cpp
// ========================================================================

void _unwind_493043()
{
  int v0; // r12

  idFXManager::~idFXManager(this: (idFXManager *)(*(_DWORD *)(v0 - 112 + 132) + 868));
}


// ========================================================================
// ??0idVolume_PlayerEnvOverride@@QAA@XZ
// EA  : 0x82D47848
// RVA : 0x00D47848
// PDB : w:\tech5\tungsten\game\entities\volume.cpp
// ========================================================================

idVolume_PlayerEnvOverride *__fastcall idVolume_PlayerEnvOverride::idVolume_PlayerEnvOverride(
        idVolume_PlayerEnvOverride *this)
{
  idVolume::idVolume(this);
  this->fadeInTime = 0;
  this->__vftable = (idVolume_PlayerEnvOverride_vtbl *)&idVolume_PlayerEnvOverride::`vftable';
  this->fadeOutTime = 0;
  this->declEnv = nullptr;
  this->facingTarget.spawnId.value = 0x1FFF;
  return this;
}


// ========================================================================
// ??0idVolume_ForceDormant@@QAA@XZ
// EA  : 0x82D478A8
// RVA : 0x00D478A8
// PDB : w:\tech5\tungsten\game\entities\volume.cpp
// ========================================================================

idVolume_ForceDormant *__fastcall idVolume_ForceDormant::idVolume_ForceDormant(idVolume_ForceDormant *this)
{
  idVolume::idVolume(this);
  this->__vftable = (idVolume_ForceDormant_vtbl *)&idVolume_ForceDormant::`vftable';
  this->entitiesToForceDormant.list = nullptr;
  this->entitiesToForceDormant.granularity = 0;
  this->entitiesToForceDormant.memTag = 5;
  this->entitiesToForceDormant.listStatic = 0;
  this->entitiesToForceDormant.size = 0;
  this->entitiesToForceDormant.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->entitiesToForceDormant);
  this->forceVehiclesDormant = true;
  this->dormantDurationInFrames = 2;
  this->forceGuisDormant = true;
  this->disableVehicleSplines = true;
  this->disablePlayerVehicle = true;
  return this;
}


// ========================================================================
// __unwind$493097
// EA  : 0x82D47938
// RVA : 0x00D47938
// PDB : w:\tech5\tungsten\game\entities\volume.cpp
// ========================================================================

void _unwind_493097()
{
  int v0; // r12

  idVolume::~idVolume(this: *(idVolume **)(v0 - 112 + 132));
}


// ========================================================================
// ??1idVolume_ForceDormant@@UAA@XZ
// EA  : 0x82D47968
// RVA : 0x00D47968
// PDB : w:\tech5\tungsten\game\entities\volume.cpp
// ========================================================================

void __fastcall idVolume_ForceDormant::~idVolume_ForceDormant(idVolume_ForceDormant *this)
{
  this->__vftable = (idVolume_ForceDormant_vtbl *)&idVolume_ForceDormant::`vftable';
  gameLocal->enableVehicleSplineUpdates = true;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->entitiesToForceDormant);
  idVolume::~idVolume(this);
}


// ========================================================================
// __unwind$493118
// EA  : 0x82D479D4
// RVA : 0x00D479D4
// PDB : w:\tech5\tungsten\game\entities\volume.cpp
// ========================================================================

void _unwind_493118()
{
  int v0; // r12

  idVolume::~idVolume(this: *(idVolume **)(v0 - 112 + 132));
}


// ========================================================================
// ?Think@idVolume_ForceDormant@@UAAXXZ
// EA  : 0x82D47A00
// RVA : 0x00D47A00
// PDB : w:\tech5\tungsten\game\entities\volume.cpp
// ========================================================================

void __fastcall idVolume_ForceDormant::Think(idVolume_ForceDormant *this)
{
  int v2; // r30
  int v3; // r26
  idGameLocal *v4; // r11
  int v5; // r31
  int value; // r9
  idEntity *v7; // r3
  idEntity *v8; // r3
  idLinkList<idVehicle> *next; // r10
  idVehicle *owner; // r31
  idLinkList<idVehicle> *v11; // r11
  idLinkList<idVehicleAI> *v12; // r10
  idVehicleAI *v13; // r31
  idLinkList<idVehicleAI> *v14; // r11
  int v15; // r30
  int v16; // r31
  int v17; // r9
  idGuiEntity *v18; // r3
  idGuiEntity *v19; // r3

  if ( (this->thinkFlags & 1) != 0 )
  {
    v2 = 0;
    v3 = this->dormantDurationInFrames
       * (idGameTimeManager::GetGameMsPerFrame(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) + 1);
    v4 = gameLocal;
    if ( this->entitiesToForceDormant.num > 0 )
    {
      v5 = 0;
      do
      {
        value = this->entitiesToForceDormant.list[v5].spawnId.value;
        if ( v4->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
        {
          v7 = v4->entities.ptr[value & 0x1FFF];
          if ( v7 != nullptr )
          {
            v8 = idEntity::CastTo(c: v7);
            if ( v8 != nullptr )
              idEntity::ForceDormancy(this: v8, dormant: true, durationMS: v3);
            v4 = gameLocal;
          }
        }
        ++v2;
        ++v5;
      }
      while ( v2 < this->entitiesToForceDormant.num );
    }
    if ( this->forceVehiclesDormant )
    {
      next = v4->vehicleEntities.next;
      if ( next != nullptr && next != v4->vehicleEntities.head )
      {
        owner = next->owner;
        if ( owner != nullptr )
        {
          do
          {
            if ( idVehicle::PlayerIsOccupant(this: owner) == nullptr
              && (this->disablePlayerVehicle || !idVehicle::CanPlayerEnter(this: owner, wantSeat: 0, activator: nullptr)) )
            {
              idEntity::ForceDormancy(this: owner, dormant: true, durationMS: v3);
            }
            v11 = owner->controlNode.next;
            if ( v11 == nullptr || v11 == owner->controlNode.head )
              owner = nullptr;
            else
              owner = v11->owner;
          }
          while ( owner != nullptr );
          v4 = gameLocal;
        }
      }
      v12 = v4->vehicleAIEntities.next;
      if ( v12 != nullptr && v12 != v4->vehicleAIEntities.head )
      {
        v13 = v12->owner;
        if ( v13 != nullptr )
        {
          do
          {
            idEntity::ForceDormancy(this: v13, dormant: true, durationMS: v3);
            v14 = v13->controlNode.next;
            if ( v14 == nullptr || v14 == v13->controlNode.head )
              v13 = nullptr;
            else
              v13 = v14->owner;
          }
          while ( v13 != nullptr );
          v4 = gameLocal;
        }
      }
    }
    if ( this->forceGuisDormant )
    {
      v15 = 0;
      if ( v4->guiEntities.num > 0 )
      {
        v16 = 0;
        do
        {
          v17 = v4->guiEntities.list[v16].spawnId.value;
          if ( v4->spawnIds.ptr[v17 & 0x1FFF] == v17 >> 13 )
          {
            v18 = (idGuiEntity *)v4->entities.ptr[v17 & 0x1FFF];
            if ( v18 != nullptr )
            {
              v19 = idGuiEntity::CastTo(c: v18);
              if ( v19 != nullptr )
                idEntity::ForceDormancy(this: v19, dormant: true, durationMS: v3);
              v4 = gameLocal;
            }
          }
          ++v15;
          ++v16;
        }
        while ( v15 < v4->guiEntities.num );
      }
    }
    if ( this->disableVehicleSplines )
      v4->enableVehicleSplineUpdates = false;
  }
}


// ========================================================================
// ??0idVolume_PlayerInteraction@@QAA@XZ
// EA  : 0x82D47CA8
// RVA : 0x00D47CA8
// PDB : w:\tech5\tungsten\game\entities\volume.cpp
// ========================================================================

idVolume_PlayerInteraction *__fastcall idVolume_PlayerInteraction::idVolume_PlayerInteraction(
        idVolume_PlayerInteraction *this)
{
  idVolume::idVolume(this);
  this->__vftable = (idVolume_PlayerInteraction_vtbl *)&idVolume_PlayerInteraction::`vftable';
  this->shouldLockCamera = false;
  this->playerPos = vec3_origin;
  this->playerLookAtPos = vec3_origin;
  this->interactionObject.spawnId.value = 0x1FFF;
  this->interactionDistance = 0.0;
  this->interactionDelayTime = 1000;
  this->startDelayTime = -1;
  return this;
}


// ========================================================================
// ??0idVolume_EnterExit@@QAA@XZ
// EA  : 0x82D47D58
// RVA : 0x00D47D58
// PDB : w:\tech5\tungsten\game\entities\volume.cpp
// ========================================================================

idVolume_EnterExit *__fastcall idVolume_EnterExit::idVolume_EnterExit(idVolume_EnterExit *this)
{
  char v2; // r11

  idVolume::idVolume(this);
  v2 = *((_BYTE *)this + 824) & 7 | 0x58;
  this->__vftable = (idVolume_EnterExit_vtbl *)&idVolume_EnterExit::`vftable';
  *((_BYTE *)this + 824) = v2;
  this->enterTargets.list = nullptr;
  this->enterTargets.granularity = 0;
  this->enterTargets.memTag = 5;
  this->enterTargets.listStatic = 0;
  this->enterTargets.size = 0;
  this->enterTargets.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->enterTargets);
  this->exitTargets.list = nullptr;
  this->exitTargets.granularity = 0;
  this->exitTargets.memTag = 5;
  this->exitTargets.listStatic = 0;
  this->exitTargets.size = 0;
  this->exitTargets.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->exitTargets);
  this->validTouchers.list = nullptr;
  this->validTouchers.granularity = 0;
  this->validTouchers.memTag = 5;
  this->validTouchers.listStatic = 0;
  this->validTouchers.size = 0;
  this->validTouchers.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->validTouchers);
  *((_BYTE *)this + 884) &= 0x3Fu;
  this->enterDelay = 0.0;
  this->exitDelay = 0.0;
  return this;
}


// ========================================================================
// __unwind$493331_0
// EA  : 0x82D47E20
// RVA : 0x00D47E20
// PDB : w:\tech5\tungsten\game\entities\volume.cpp
// ========================================================================

void _unwind_493331_0()
{
  int v0; // r12

  idVolume::~idVolume(this: *(idVolume **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$493332
// EA  : 0x82D47E48
// RVA : 0x00D47E48
// PDB : w:\tech5\tungsten\game\entities\volume.cpp
// ========================================================================

void _unwind_493332()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 828));
}


// ========================================================================
// __unwind$493333
// EA  : 0x82D47E74
// RVA : 0x00D47E74
// PDB : w:\tech5\tungsten\game\entities\volume.cpp
// ========================================================================

void _unwind_493333()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 844));
}


// ========================================================================
// ?CanTouch@idVolume_EnterExit@@IAA_NPAVidEntity@@@Z
// EA  : 0x82D47F80
// RVA : 0x00D47F80
// PDB : w:\tech5\tungsten\game\entities\volume.cpp
// ========================================================================

int __fastcall idVolume_EnterExit::CanTouch(idVolume_EnterExit *this, idEntity *toucher)
{
  int num; // r11
  int v5; // r30
  int v6; // r31
  idGameLocal *v7; // r10
  int value; // r9
  idEntity *v9; // r3
  idEntity *v10; // r3

  if ( (*((_BYTE *)&this->idVolume + 816) & 0x80) != 0 )
  {
    if ( (*((_BYTE *)this + 824) & 0x40) == 0 && (*((_BYTE *)this + 824) & 0x80) == 0 && this->validTouchers.num <= 0 )
      return 1;
    num = this->validTouchers.num;
    if ( num != 0 )
    {
      v5 = this->validTouchers.num;
      v6 = num;
      v7 = gameLocal;
      while ( 1 )
      {
        --v6;
        --v5;
        value = this->validTouchers.list[v6].spawnId.value;
        if ( v7->spawnIds.ptr[value & 0x1FFF] == value >> 13 && (v9 = v7->entities.ptr[value & 0x1FFF]) != nullptr )
        {
          v10 = idEntity::CastTo(c: v9);
          v7 = gameLocal;
        }
        else
        {
          v10 = nullptr;
        }
        if ( v10 == toucher )
          break;
        if ( v5 == 0 )
          return 0;
      }
      return 1;
    }
    if ( (*((_BYTE *)this + 824) & 0x40) != 0 && (unsigned __int8)idPlayer::IsTypeOf(c: toucher) != 0
      || (*((_BYTE *)this + 824) & 0x80) != 0 && (unsigned __int8)idAI2::IsTypeOf(c: toucher) != 0 )
    {
      return 1;
    }
  }
  return 0;
}


// ========================================================================
// ?Event_TriggerEntry@idVolume_EnterExit@@IAA?AVeventVoid@@PAVidEntity@@@Z
// EA  : 0x82D480B0
// RVA : 0x00D480B0
// PDB : w:\tech5\tungsten\game\entities\volume.cpp
// ========================================================================

idVolume_EnterExit *__fastcall idVolume_EnterExit::Event_TriggerEntry(
        idVolume_EnterExit *this,
        eventVoid *result,
        idEntity *activator)
{
  int v3; // r31
  eventVoid *v6; // r30
  int v7; // r29
  int v8; // r9
  idEntity *v9; // r3
  idEntity *v10; // r3
  int v11; // r11
  int v12; // r11

  v3 = *(_DWORD *)&result[832];
  if ( v3 != 0 )
  {
    v6 = result + 828;
    v7 = 4 * v3;
    while ( 1 )
    {
      while ( 1 )
      {
        v7 -= 4;
        --v3;
        v8 = *(_DWORD *)(v7 + *(_DWORD *)v6);
        if ( gameLocal->spawnIds.ptr[v8 & 0x1FFF] != v8 >> 13 )
          break;
        v9 = gameLocal->entities.ptr[v8 & 0x1FFF];
        if ( v9 == nullptr )
          break;
        v10 = idEntity::CastTo(c: v9);
        if ( v10 == nullptr )
          break;
        idEntity::Activate(this: v10, activator);
LABEL_11:
        if ( v3 == 0 )
          return this;
      }
      if ( v3 >= 0 )
      {
        v11 = *(_DWORD *)&v6[4];
        if ( v3 < v11 )
        {
          v12 = v11 - 1;
          *(_DWORD *)&v6[4] = v12;
          if ( v3 != v12 )
            *(_DWORD *)(v7 + *(_DWORD *)v6) = *(_DWORD *)(4 * v12 + *(_DWORD *)v6);
        }
        goto LABEL_11;
      }
    }
  }
  return this;
}


// ========================================================================
// ?Event_TriggerExit@idVolume_EnterExit@@IAA?AVeventVoid@@PAVidEntity@@@Z
// EA  : 0x82D48188
// RVA : 0x00D48188
// PDB : w:\tech5\tungsten\game\entities\volume.cpp
// ========================================================================

idVolume_EnterExit *__fastcall idVolume_EnterExit::Event_TriggerExit(
        idVolume_EnterExit *this,
        eventVoid *result,
        idEntity *activator)
{
  int v3; // r31
  eventVoid *v6; // r30
  int v7; // r29
  int v8; // r9
  idEntity *v9; // r3
  idEntity *v10; // r3
  int v11; // r11
  int v12; // r11

  v3 = *(_DWORD *)&result[848];
  if ( v3 != 0 )
  {
    v6 = result + 844;
    v7 = 4 * v3;
    while ( 1 )
    {
      while ( 1 )
      {
        v7 -= 4;
        --v3;
        v8 = *(_DWORD *)(v7 + *(_DWORD *)v6);
        if ( gameLocal->spawnIds.ptr[v8 & 0x1FFF] != v8 >> 13 )
          break;
        v9 = gameLocal->entities.ptr[v8 & 0x1FFF];
        if ( v9 == nullptr )
          break;
        v10 = idEntity::CastTo(c: v9);
        if ( v10 == nullptr )
          break;
        idEntity::Activate(this: v10, activator);
LABEL_11:
        if ( v3 == 0 )
          return this;
      }
      if ( v3 >= 0 )
      {
        v11 = *(_DWORD *)&v6[4];
        if ( v3 < v11 )
        {
          v12 = v11 - 1;
          *(_DWORD *)&v6[4] = v12;
          if ( v3 != v12 )
            *(_DWORD *)(v7 + *(_DWORD *)v6) = *(_DWORD *)(4 * v12 + *(_DWORD *)v6);
        }
        goto LABEL_11;
      }
    }
  }
  return this;
}


// ========================================================================
// ?Event_Untouch@idVolume_EnterExit@@IAA?AVeventVoid@@PAVidEntity@@H@Z
// EA  : 0x82D48260
// RVA : 0x00D48260
// PDB : w:\tech5\tungsten\game\entities\volume.cpp
// ========================================================================

idVolume_EnterExit *__fastcall idVolume_EnterExit::Event_Untouch(
        idVolume_EnterExit *this,
        idVolume_EnterExit *result,
        idEntity *other,
        int clipModelId)
{
  idEventArg *v7; // r3
  idEventArg v9[3]; // [sp+60h] [-40h] BYREF

  if ( (unsigned __int8)idVolume_EnterExit::CanTouch(this: result, toucher: other) != 0
    && (unsigned __int8)idVolume::RemoveTouching(this: result, other) != 0
    && ((*((_BYTE *)result + 824) & 0x20) != 0 || result->touching.num == 0)
    && ((*((_BYTE *)result + 824) & 8) == 0 || (*((_BYTE *)result + 884) & 0x40) == 0) )
  {
    *((_BYTE *)result + 884) |= 0x40u;
    v7 = idEventArg::idEventArg(this: v9, data: other);
    idEventReceiver::PostEventMS(
      this: result,
      ev: &EV_TriggerExit,
      time: *(_DWORD *)&v7->type,
      arg1: (const idEventArg *)LODWORD(v7->value.v[1]));
  }
  return this;
}


// ========================================================================
// ??0idVolume_ScenePoints@@QAA@XZ
// EA  : 0x82D48348
// RVA : 0x00D48348
// PDB : w:\tech5\tungsten\game\entities\volume.cpp
// ========================================================================

idVolume_ScenePoints *__fastcall idVolume_ScenePoints::idVolume_ScenePoints(idVolume_ScenePoints *this)
{
  idVolume::idVolume(this);
  this->__vftable = (idVolume_ScenePoints_vtbl *)&idVolume_ScenePoints::`vftable';
  return this;
}


// ========================================================================
// ?Event_Untouch@idVolume_ScenePoints@@QAA?AVeventVoid@@PAVidEntity@@H@Z
// EA  : 0x82D48388
// RVA : 0x00D48388
// PDB : w:\tech5\tungsten\game\entities\volume.cpp
// ========================================================================

idVolume_ScenePoints *__fastcall idVolume_ScenePoints::Event_Untouch(
        idVolume_ScenePoints *this,
        idVolume_ScenePoints *result,
        idAI2 *other,
        int clipModelId)
{
  idAI2 *v7; // r3

  if ( (unsigned __int8)idAI2::IsTypeOf(c: other) != 0 )
  {
    idVolume::RemoveTouching(this: result, other);
    v7 = idAI2::CastTo(c: other);
    if ( v7 != nullptr )
      idAIMemory::RemoveScenePointVolume(this: &v7->aiVolatile.memory, spVolume: result);
  }
  return this;
}


// ========================================================================
// ?DisableTouch@idVolume@@IAAXXZ
// EA  : 0x82D48438
// RVA : 0x00D48438
// PDB : w:\tech5\tungsten\game\entities\volume.cpp
// ========================================================================

void __fastcall idVolume::DisableTouch(idVolume *this)
{
  int v2; // r28
  int v3; // r30
  int value; // r9
  idEntity *v5; // r3
  idEntity *v6; // r3
  idEntityPtr<idEntity> *list; // r4
  idPhysics *Physics; // r3
  idPhysics *v9; // r3

  if ( (*((_BYTE *)this + 816) & 0x80) != 0 )
  {
    v2 = 0;
    if ( this->touching.num > 0 )
    {
      v3 = 0;
      do
      {
        value = this->touching.list[v3].spawnId.value;
        if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
        {
          v5 = gameLocal->entities.ptr[value & 0x1FFF];
          if ( v5 != nullptr )
          {
            v6 = idEntity::CastTo(c: v5);
            if ( v6 != nullptr )
              idEntity::UntouchTrigger(this: v6, trigger: (idEventArg *)this);
          }
        }
        ++v2;
        ++v3;
      }
      while ( v2 < this->touching.num );
    }
    if ( this->touching.listStatic == 0 || this->touching.listStatic == 2 )
    {
      list = this->touching.list;
      if ( list != nullptr )
        idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
      this->touching.list = nullptr;
      this->touching.size = 0;
    }
    this->touching.num = 0;
    Physics = idEntity::GetPhysics(this);
    Physics->SetContents(this: Physics, a2: 0, a3: -1);
    v9 = idEntity::GetPhysics(this);
    v9->DisableClip(this: v9);
    *((_BYTE *)this + 816) &= ~0x80u;
  }
}


// ========================================================================
// ?Event_Untouch@idVolume@@QAA?AVeventVoid@@PAVidEntity@@H@Z
// EA  : 0x82D48568
// RVA : 0x00D48568
// PDB : w:\tech5\tungsten\game\entities\volume.cpp
// ========================================================================

idVolume *__fastcall idVolume::Event_Untouch(idVolume *this, idVolume *result, idEntity *other, int clipModelId)
{
  idVolume::RemoveTouching(this: result, other);
  return this;
}


// ========================================================================
// ?Event_Untouch@idVolume_Repairs@@AAA?AVeventVoid@@PAVidEntity@@H@Z
// EA  : 0x82D485A0
// RVA : 0x00D485A0
// PDB : w:\tech5\tungsten\game\entities\volume.cpp
// ========================================================================

idVolume_Repairs *__fastcall idVolume_Repairs::Event_Untouch(
        idVolume_Repairs *this,
        idVolume *result,
        idEntity *other,
        int clipModelId)
{
  idVolume::RemoveTouching(this: result, other);
  if ( result->touching.num == 0 && HIBYTE(result[1].listeningToList) != 0 )
  {
    idEntity::StopSound(this: result, channel: SND_CHANNEL_AMBIENT, peerMask: 0xFFu);
    HIBYTE(result[1].listeningToList) = 0;
  }
  return this;
}


// ========================================================================
// ?Event_Untouch@idVolume_ShowGui_Leveltransition@@AAA?AVeventVoid@@PAVidEntity@@H@Z
// EA  : 0x82D48618
// RVA : 0x00D48618
// PDB : w:\tech5\tungsten\game\entities\volume.cpp
// ========================================================================

idVolume_ShowGui_Leveltransition *__fastcall idVolume_ShowGui_Leveltransition::Event_Untouch(
        idVolume_ShowGui_Leveltransition *this,
        idVolume *result,
        idEntity *other,
        int clipModelId)
{
  idPlayer *PlayerFromEntity; // r3

  PlayerFromEntity = idGameLocal::GetPlayerFromEntity(this: gameLocal, activator: other);
  if ( PlayerFromEntity != nullptr && PlayerFromEntity->levelTransitionGuiVolume == result )
    idPlayer::ClearLevelTransitionGuiVolume(this: PlayerFromEntity);
  HIBYTE(result[1].targets.num) = 0;
  idVolume::RemoveTouching(this: result, other);
  return this;
}


// ========================================================================
// ?CheckFacingTarget@idVolume_ShowGui_Leveltransition@@QAA_NPAVidPlayer@@@Z
// EA  : 0x82D48678
// RVA : 0x00D48678
// PDB : w:\tech5\tungsten\game\entities\volume.cpp
// ========================================================================

BOOL __fastcall idVolume_ShowGui_Leveltransition::CheckFacingTarget(
        idVolume_ShowGui_Leveltransition *this,
        idPlayer *player)
{
  int v4; // r28
  idVec3 *v5; // r3
  float *LastViewOrigin; // r3
  idPlayer_vtbl *v7; // r8
  idVehicle *(__fastcall *GetVehicle_2)(idActor *); // r7
  idMat3 *v9; // r3
  float *LastViewAxis; // r3
  double v11; // fp31
  double v12; // fp30
  double v13; // fp29
  idPresentable *presentable; // r3
  float *v15; // r3
  idPresentable *v16; // r11
  float *v17; // r3
  idGameLocal *v18; // r11
  idInfo_Trigger_Facing_Target *v19; // r3
  int value; // r9
  idInfo_Trigger_Facing_Target *v21; // r3
  idInfo_Trigger_Facing_Target *v22; // r3
  idPhysics *Physics; // r3
  const idVec3 *v24; // r3
  int v25; // r9
  float x; // r6
  float y; // r4
  float z; // r3
  idInfo_Trigger_Facing_Target *v29; // r3
  idInfo_Trigger_Facing_Target *v30; // r3
  int v31; // r9
  double v32; // fp27
  idInfo_Trigger_Facing_Target *v33; // r3
  idInfo_Trigger_Facing_Target *v34; // r3
  double v35; // fp8
  int v36; // r7
  double v40; // fp8
  double v42; // fp4
  double v43; // fp8
  double v44; // fp4
  double v45; // fp11
  double v46; // fp6
  double v47; // fp8
  double v48; // fp4
  double v49; // fp12
  double v50; // fp11
  double v51; // fp27
  idInfo_Trigger_Facing_Target *v52; // r3
  idInfo_Trigger_Facing_Target *v53; // r3
  int v54; // r9
  double v55; // fp26
  idInfo_Trigger_Facing_Target *v56; // r3
  idInfo_Trigger_Facing_Target *v57; // r3
  idEntityPtr<idEntity> *p_traceTarget; // r30
  idEntity *v59; // r3
  idEntity *v60; // r3
  idPhysics *v61; // r3
  float *v62; // r3
  double v63; // fp2
  idEntityPtr<idEntity> *v64; // r3
  idGameLocal *v65; // r31
  int v66; // r30
  BOOL result; // r3
  int v68; // [sp+8h] [-1A8h]
  bool v69; // [sp+Fh] [-1A1h]
  const char *v70; // [sp+10h] [-1A0h]
  int v71; // [sp+14h] [-19Ch]
  int v72; // [sp+18h] [-198h]
  int v73; // [sp+1Ch] [-194h]
  int v74; // [sp+20h] [-190h]
  int v75; // [sp+24h] [-18Ch]
  int v76; // [sp+28h] [-188h]
  int v77; // [sp+2Ch] [-184h]
  int v78; // [sp+30h] [-180h]
  int v79; // [sp+34h] [-17Ch]
  int v80; // [sp+38h] [-178h]
  int v81; // [sp+3Ch] [-174h]
  int v82; // [sp+40h] [-170h]
  int v83; // [sp+44h] [-16Ch]
  int v84; // [sp+48h] [-168h]
  int v85; // [sp+4Ch] [-164h]
  int v86; // [sp+50h] [-160h]
  int entityNumber; // [sp+54h] [-15Ch]
  int v88; // [sp+58h] [-158h]
  int v89; // [sp+60h] [-150h]
  idVec3 v90; // [sp+70h] [-140h] BYREF
  float v91; // [sp+80h] [-130h] BYREF
  float v92; // [sp+84h] [-12Ch]
  float v93; // [sp+88h] [-128h]
  idVec3 v94; // [sp+90h] [-120h] BYREF
  char v95; // [sp+A0h] [-110h] BYREF
  trace_t v96; // [sp+D0h] [-E0h] BYREF

  v4 = 1;
  if ( player->IsDrivingVehicle(this: player) )
  {
    v5 = (idVec3 *)player->GetVehicle_2(this: player);
    LastViewOrigin = (float *)idVehicle::GetLastViewOrigin(this: (idVehicle *)&v91, result: v5);
    v7 = player->__vftable;
    v90.x = *LastViewOrigin;
    GetVehicle_2 = v7->GetVehicle_2;
    v90.y = LastViewOrigin[1];
    v90.z = LastViewOrigin[2];
    v9 = (idMat3 *)GetVehicle_2(this: player);
    LastViewAxis = (float *)idVehicle::GetLastViewAxis(this: (idVehicle *)&v95, result: v9);
    v11 = *LastViewAxis;
    v12 = LastViewAxis[1];
    v13 = LastViewAxis[2];
  }
  else
  {
    presentable = player->presentable;
    if ( presentable != nullptr )
      v15 = (float *)presentable->GetPlayerInterface_2(this: presentable);
    else
      v15 = nullptr;
    v16 = player->presentable;
    v90.x = v15[11633];
    v90.y = v15[11634];
    v90.z = v15[11635];
    if ( v16 != nullptr )
      v17 = (float *)v16->GetPlayerInterface_2(this: v16);
    else
      v17 = nullptr;
    v11 = v17[11636];
    v12 = v17[11637];
    v13 = v17[11638];
  }
  v18 = gameLocal;
  if ( gameLocal->spawnIds.ptr[this->facingTarget.spawnId.value & 0x1FFF] == this->facingTarget.spawnId.value >> 13 )
  {
    v19 = (idInfo_Trigger_Facing_Target *)gameLocal->entities.ptr[this->facingTarget.spawnId.value & 0x1FFF];
    if ( v19 != nullptr )
    {
      if ( idInfo_Trigger_Facing_Target::CastTo(c: v19) != nullptr )
      {
        value = this->facingTarget.spawnId.value;
        v4 = 0;
        if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
          && (v21 = (idInfo_Trigger_Facing_Target *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
        {
          v22 = idInfo_Trigger_Facing_Target::CastTo(c: v21);
        }
        else
        {
          v22 = nullptr;
        }
        Physics = idEntity::GetPhysics(this: v22);
        v24 = Physics->GetOrigin(this: Physics, a2: 0);
        v25 = this->facingTarget.spawnId.value;
        v18 = gameLocal;
        x = v24->x;
        y = v24->y;
        z = v24->z;
        v91 = x;
        v92 = y;
        v93 = z;
        if ( gameLocal->spawnIds.ptr[v25 & 0x1FFF] == v25 >> 13
          && (v29 = (idInfo_Trigger_Facing_Target *)gameLocal->entities.ptr[v25 & 0x1FFF]) != nullptr )
        {
          v30 = idInfo_Trigger_Facing_Target::CastTo(c: v29);
          v18 = gameLocal;
        }
        else
        {
          v30 = nullptr;
        }
        v31 = this->facingTarget.spawnId.value;
        v32 = v30->radius.value;
        if ( v18->spawnIds.ptr[v31 & 0x1FFF] == v31 >> 13
          && (v33 = (idInfo_Trigger_Facing_Target *)v18->entities.ptr[v31 & 0x1FFF]) != nullptr )
        {
          v34 = idInfo_Trigger_Facing_Target::CastTo(c: v33);
          v18 = gameLocal;
        }
        else
        {
          v34 = nullptr;
        }
        if ( v34->doVerticleTest )
        {
          if ( (float)((float)((float)v12 * (float)(v90.y - v92))
                     + (float)((float)((float)v11 * (float)(v90.x - v91)) + (float)((float)v13 * (float)(v90.z - v93)))) <= 0.0 )
          {
            v35 = (float)((float)((float)((float)v12 * (float)2.0) * (float)(v90.y - v92))
                        + (float)((float)((float)((float)v11 * (float)2.0) * (float)(v90.x - v91))
                                + (float)((float)((float)v13 * (float)2.0) * (float)(v90.z - v93))));
            if ( (float)((float)((float)v35 * (float)v35)
                       - (float)((float)((float)-(float)((float)((float)v32 * (float)v32)
                                                       - (float)((float)((float)(v90.y - v92) * (float)(v90.y - v92))
                                                               + (float)((float)((float)(v90.x - v91)
                                                                               * (float)(v90.x - v91))
                                                                       + (float)((float)(v90.z - v93)
                                                                               * (float)(v90.z - v93)))))
                                       * (float)((float)((float)v11 * (float)v11)
                                               + (float)((float)((float)v13 * (float)v13)
                                                       + (float)((float)v12 * (float)v12))))
                               * (float)4.0)) >= 0.0 )
              v4 = 1;
          }
        }
        else
        {
          v36 = this->facingTarget.spawnId.value;
          _FP4 = (float)((float)((float)((float)v12 * (float)v12) + (float)((float)v11 * (float)v11))
                       - idMath::FLT_SMALLEST_NON_DENORMAL);
          __asm { fsel      f1, f4, f6, f13 }
          _FP11 = (float)((float)((float)((float)(v91 - v90.x) * (float)(v91 - v90.x))
                                + (float)((float)(v92 - v90.y) * (float)(v92 - v90.y)))
                        - idMath::FLT_SMALLEST_NON_DENORMAL);
          v40 = __frsqrte(_FP1);
          __asm { fsel      f6, f11, f3, f13 }
          v42 = __frsqrte(_FP6);
          v43 = (float)((float)-(float)((float)((float)((float)v40
                                                      * (float)((float)((float)((float)v12 * (float)v12)
                                                                      + (float)((float)v11 * (float)v11))
                                                              * (float)0.5))
                                              * (float)v40)
                                      - (float)1.5)
                      * (float)v40);
          v44 = (float)((float)-(float)((float)((float)((float)v42
                                                      * (float)((float)((float)((float)(v91 - v90.x)
                                                                              * (float)(v91 - v90.x))
                                                                      + (float)((float)(v92 - v90.y)
                                                                              * (float)(v92 - v90.y)))
                                                              * (float)0.5))
                                              * (float)v42)
                                      - (float)1.5)
                      * (float)v42);
          v45 = (float)((float)v12
                      * (float)((float)-(float)((float)((float)((float)v43
                                                              * (float)((float)((float)((float)v12 * (float)v12)
                                                                              + (float)((float)v11 * (float)v11))
                                                                      * (float)0.5))
                                                      * (float)v43)
                                              - (float)1.5)
                              * (float)v43));
          v46 = (float)((float)v11
                      * (float)((float)-(float)((float)((float)((float)v43
                                                              * (float)((float)((float)((float)v12 * (float)v12)
                                                                              + (float)((float)v11 * (float)v11))
                                                                      * (float)0.5))
                                                      * (float)v43)
                                              - (float)1.5)
                              * (float)v43));
          v47 = (float)((float)-(float)((float)((float)((float)v44
                                                      * (float)((float)((float)((float)(v91 - v90.x)
                                                                              * (float)(v91 - v90.x))
                                                                      + (float)((float)(v92 - v90.y)
                                                                              * (float)(v92 - v90.y)))
                                                              * (float)0.5))
                                              * (float)v44)
                                      - (float)1.5)
                      * (float)v44);
          v48 = (float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v44
                                                                                      * (float)((float)((float)((float)(v91 - v90.x) * (float)(v91 - v90.x)) + (float)((float)(v92 - v90.y) * (float)(v92 - v90.y)))
                                                                                              * (float)0.5))
                                                                              * (float)v44)
                                                                      - (float)1.5)
                                                      * (float)v44)
                                              * (float)((float)((float)((float)(v91 - v90.x) * (float)(v91 - v90.x))
                                                              + (float)((float)(v92 - v90.y) * (float)(v92 - v90.y)))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v44
                                                                              * (float)((float)((float)((float)(v91 - v90.x) * (float)(v91 - v90.x))
                                                                                              + (float)((float)(v92 - v90.y) * (float)(v92 - v90.y)))
                                                                                      * (float)0.5))
                                                                      * (float)v44)
                                                              - (float)1.5)
                                              * (float)v44))
                              - (float)1.5);
          v49 = (float)((float)((float)v45
                              * (float)((float)((float)v48 * (float)v47)
                                      * (float)((float)((float)(v91 - v90.x) * (float)(v91 - v90.x))
                                              + (float)((float)(v92 - v90.y) * (float)(v92 - v90.y)))))
                      - (float)(v92 - v90.y));
          v50 = (float)((float)((float)v46
                              * (float)((float)((float)v48 * (float)v47)
                                      * (float)((float)((float)(v91 - v90.x) * (float)(v91 - v90.x))
                                              + (float)((float)(v92 - v90.y) * (float)(v92 - v90.y)))))
                      - (float)(v91 - v90.x));
          v51 = (float)((float)((float)v50 * (float)v50) + (float)((float)v49 * (float)v49));
          if ( v18->spawnIds.ptr[v36 & 0x1FFF] == v36 >> 13
            && (v52 = (idInfo_Trigger_Facing_Target *)v18->entities.ptr[v36 & 0x1FFF]) != nullptr )
          {
            v53 = idInfo_Trigger_Facing_Target::CastTo(c: v52);
            v18 = gameLocal;
          }
          else
          {
            v53 = nullptr;
          }
          v54 = this->facingTarget.spawnId.value;
          v55 = v53->radius.value;
          if ( v18->spawnIds.ptr[v54 & 0x1FFF] == v54 >> 13
            && (v56 = (idInfo_Trigger_Facing_Target *)v18->entities.ptr[v54 & 0x1FFF]) != nullptr )
          {
            v57 = idInfo_Trigger_Facing_Target::CastTo(c: v56);
            v18 = gameLocal;
          }
          else
          {
            v57 = nullptr;
          }
          if ( v51 < (float)(v57->radius.value * (float)v55) )
            v4 = 1;
        }
      }
      else
      {
        v18 = gameLocal;
      }
    }
  }
  if ( (_BYTE)v4 == 0 )
    return v4;
  p_traceTarget = &this->traceTarget;
  if ( v18->spawnIds.ptr[p_traceTarget->spawnId.value & 0x1FFF] != p_traceTarget->spawnId.value >> 13 )
    return v4;
  v59 = v18->entities.ptr[p_traceTarget->spawnId.value & 0x1FFF];
  if ( v59 != nullptr )
    v60 = idEntity::CastTo(c: v59);
  else
    v60 = nullptr;
  v61 = idEntity::GetPhysics(this: v60);
  v62 = (float *)v61->GetOrigin(this: v61, a2: 0);
  entityNumber = player->entityNumber;
  v63 = __fsqrts((float)((float)((float)(v90.x - *v62) * (float)(v90.x - *v62))
                       + (float)((float)((float)(v90.z - v62[2]) * (float)(v90.z - v62[2]))
                               + (float)((float)(v90.y - v62[1]) * (float)(v90.y - v62[1])))));
  v94.x = (float)((float)v11 * (float)((float)v63 * (float)2.0)) + v90.x;
  v94.y = (float)((float)v12 * (float)((float)v63 * (float)2.0)) + v90.y;
  v94.z = (float)((float)v13 * (float)((float)v63 * (float)2.0)) + v90.z;
  idClip::Translation(
    this: (idClip *)&v91,
    result: &clientGame->clip,
    a3: &v96,
    start: &v90,
    end: &v94,
    clipModel: nullptr,
    startAxis: &mat3_identity,
    clipMask: 2097161,
    passEntityNumber: v68,
    moveClipModel: v69,
    userName: v70,
    a12: v71,
    a13: v72,
    a14: v73,
    a15: v74,
    a16: v75,
    a17: v76,
    a18: v77,
    a19: v78,
    a20: v79,
    a21: v80,
    a22: v81,
    a23: v82,
    a24: v83,
    a25: v84,
    a26: v85,
    a27: v86,
    a28: entityNumber,
    a29: v88,
    a30: false,
    a31: v89,
    a32: 0);
  result = false;
  if ( v96.fraction < 1.0 )
  {
    v64 = p_traceTarget;
    v65 = gameLocal;
    v66 = 4 * (v96.c.entityNum + 21563);
    if ( *(idEntity **)((char *)&v65->__vftable + v66) == idEntityPtr<idEntity const>::operator->(this: v64) )
      return true;
  }
  return result;
}


// ========================================================================
// ?Pickup@idVolume_ItemGroup@@QAAHPAVidPlayer@@@Z
// EA  : 0x82D48D78
// RVA : 0x00D48D78
// PDB : w:\tech5\tungsten\game\entities\volume.cpp
// ========================================================================

int __fastcall idVolume_ItemGroup::Pickup(idVolume_ItemGroup *this, idPlayer *player)
{
  int v4; // r25
  const idSoundShader *sound_pickup; // r20
  char v6; // r19
  int v7; // r22
  int v8; // r24
  int value; // r9
  idEntity *v10; // r3
  idProjectile *v11; // r3
  idProp_Moveable *v12; // r27
  int inventoryCount; // r28
  idProjectile *v14; // r30
  idProp_Moveable *v15; // r3
  idProp_Moveable *v16; // r31
  int inventoryDecl; // r30
  idJobManager *v18; // r3
  idPresentable *presentable; // r31
  idInventoryCollection *v20; // r3

  v4 = 0;
  sound_pickup = nullptr;
  v6 = 1;
  v7 = 0;
  if ( this->touching.num <= 0 )
    goto LABEL_31;
  v8 = 0;
  do
  {
    value = this->touching.list[v8].spawnId.value;
    if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
    {
      v10 = gameLocal->entities.ptr[value & 0x1FFF];
      if ( v10 != nullptr )
      {
        v11 = (idProjectile *)idEntity::CastTo(c: v10);
        v12 = (idProp_Moveable *)v11;
        if ( v11 != nullptr )
        {
          inventoryCount = 1;
          v14 = idProjectile::CastTo(c: v11);
          v15 = idProp_Moveable::CastTo(c: v12);
          v16 = v15;
          if ( v14 != nullptr )
          {
            inventoryDecl = (int)v14->GetInventoryItem(this: v14);
          }
          else
          {
            if ( v15 == nullptr )
              goto LABEL_26;
            if ( (unsigned __int8)idProp_Moveable::CheckRequirementStatus(this: v15, player) == 0 )
            {
              v6 = 0;
              goto LABEL_26;
            }
            inventoryDecl = (int)v16->inventoryDecl;
            inventoryCount = v16->inventoryCount;
            if ( inventoryDecl != 0
              && player != nullptr
              && *(_BYTE *)(inventoryDecl + 275) != 0
              && player->GetInventory_2(this: player) != nullptr
              && v16->backupInventoryDecl != nullptr )
            {
              v18 = (idJobManager *)player->GetInventory_2(this: player);
              if ( idJobManager::FindJobByDecl(this: v18, jobDecl: (const idDeclJob *)inventoryDecl) != nullptr )
              {
                inventoryDecl = (int)v16->backupInventoryDecl;
                inventoryCount = v16->backupInventoryCount;
              }
            }
            if ( sound_pickup == nullptr )
              sound_pickup = v16->sound_pickup;
            if ( (*((_BYTE *)v16 + 5296) & 0x80) != 0 )
              idGameLayerManager::AddItemMemory(this: &player->gameLayerManager, itemName: v16->name.data);
          }
          if ( inventoryDecl != 0 )
          {
            presentable = player->presentable;
            if ( presentable == nullptr )
            {
              idEntity::InitPresentableInternal(this: player);
              presentable = player->presentable;
            }
            v20 = player->GetInventory_2(this: player);
            idInventoryCollection::GiveItem(
              this: v20,
              owner: presentable,
              decl: (const idDeclInventory *)inventoryDecl,
              count: inventoryCount,
              forceCount: false,
              canIntro: true);
            idEventReceiver::PostEventMS(this: v12, ev: &EV_Remove, time: 0);
            ++v4;
          }
        }
      }
    }
LABEL_26:
    ++v7;
    ++v8;
  }
  while ( v7 < this->touching.num );
  if ( v4 > 0 )
  {
    if ( sound_pickup != nullptr )
      idEntity::StartSoundShader(
        this: player,
        channel: SND_CHANNEL_ANY,
        shader: sound_pickup,
        soundShaderFlags: (soundShaderFlags_t)0,
        peerMask: 0xFFu);
    else
      idPlayer::PlayPickupSound(this: player);
  }
LABEL_31:
  if ( v6 != 0 )
  {
    this->ActivateTargets(this, a2: player);
    idEventReceiver::PostEventMS(this, ev: &EV_Remove, time: 0);
  }
  return v4;
}


// ========================================================================
// ?ModifyCrosshairInfo@idVolume_ItemGroup@@UBA_NPBVidEntity@@ABVidFocusTrace@@W4usableState_t@@AAVidCrosshairInfo@@@Z
// EA  : 0x82D48FF0
// RVA : 0x00D48FF0
// PDB : w:\tech5\tungsten\game\entities\volume.cpp
// ========================================================================

int __fastcall idVolume_ItemGroup::ModifyCrosshairInfo(
        idVolume_ItemGroup *this,
        const idEntity *activator,
        const idFocusTrace *ft,
        usableState_t usable,
        idCrosshairInfo *info)
{
  float x; // r10
  float y; // r9
  float z; // r8
  float v11; // r7
  float v12; // r6
  float v14; // r5
  int num; // r4
  idEntity *v17; // r24
  bool v18; // r26
  double v19; // fp31
  int v20; // r23
  int v21; // r25
  int value; // r9
  idEntity *v23; // r3
  idEntity *v24; // r3
  idEntity *v25; // r31
  idPhysics *Physics; // r3
  idBounds *v27; // r3
  bool v28; // r3
  bool v29; // r30
  idPhysics *v30; // r3
  float *v31; // r3
  idVec3 v33; // [sp+50h] [-A0h] BYREF
  idVec3 v34; // [sp+60h] [-90h] BYREF

  x = ft->start.x;
  y = ft->start.y;
  z = ft->start.z;
  v11 = ft->end.x;
  v12 = ft->end.y;
  v14 = ft->end.z;
  num = this->touching.num;
  v17 = nullptr;
  v18 = false;
  v34.x = x;
  v19 = 1.0e12;
  v20 = 0;
  v34.y = y;
  v34.z = z;
  v33.x = v11;
  v33.y = v12;
  v33.z = v14;
  if ( num <= 0 )
    return 0;
  v21 = 0;
  do
  {
    value = this->touching.list[v21].spawnId.value;
    if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
    {
      v23 = gameLocal->entities.ptr[value & 0x1FFF];
      if ( v23 != nullptr )
      {
        v24 = idEntity::CastTo(c: v23);
        v25 = v24;
        if ( v24 != nullptr )
        {
          Physics = idEntity::GetPhysics(this: v24);
          v27 = (idBounds *)Physics->GetAbsBounds(this: Physics, a2: -1);
          v28 = idBounds::LineIntersection(this: v27, start: &v34, end: &v33);
          v29 = v28;
          if ( !v18 || v28 )
          {
            v30 = idEntity::GetPhysics(this: v25);
            v31 = (float *)v30->GetOrigin(this: v30, a2: 0);
            if ( (float)((float)((float)(v31[1] - v33.y) * (float)(v31[1] - v33.y))
                       + (float)((float)((float)(v31[2] - v33.z) * (float)(v31[2] - v33.z))
                               + (float)((float)(*v31 - v33.x) * (float)(*v31 - v33.x)))) < v19
              || v29 && !v18 )
            {
              v17 = v25;
              v19 = (float)((float)((float)(v31[1] - v33.y) * (float)(v31[1] - v33.y))
                          + (float)((float)((float)(v31[2] - v33.z) * (float)(v31[2] - v33.z))
                                  + (float)((float)(*v31 - v33.x) * (float)(*v31 - v33.x))));
              v18 = v29;
            }
          }
        }
      }
    }
    ++v20;
    ++v21;
  }
  while ( v20 < this->touching.num );
  if ( v17 != nullptr )
    return ((int (__fastcall *)(idEntity *, const idEntity *, const idFocusTrace *, usableState_t, idCrosshairInfo *))v17->ModifyCrosshairInfo)(
             a1: v17,
             a2: activator,
             a3: ft,
             a4: usable,
             a5: info);
  else
    return 0;
}


// ========================================================================
// ?Event_Untouch@idVolume_PlayerEnvOverride@@AAA?AVeventVoid@@PAVidEntity@@H@Z
// EA  : 0x82D49230
// RVA : 0x00D49230
// PDB : w:\tech5\tungsten\game\entities\volume.cpp
// ========================================================================

idVolume_PlayerEnvOverride *__fastcall idVolume_PlayerEnvOverride::Event_Untouch(
        idVolume_PlayerEnvOverride *this,
        idVolume *result,
        idPlayer *other,
        int clipModelId)
{
  __int64 v7; // r10
  int v8; // r5
  idPlayer *v9; // r3
  idPresentable *presentable; // r3
  int v11; // r3

  idVolume::RemoveTouching(this: result, other);
  v9 = idPlayer::CastTo(c: other);
  if ( v9 != nullptr )
  {
    presentable = v9->presentable;
    if ( presentable != nullptr )
      v11 = (int)presentable->GetPlayerInterface_2(this: presentable);
    else
      v11 = 0;
    LODWORD(v7) = result[1].listenerList;
    idView::SetEnvironmentOverride(
      this: (idView *)(v11 + 16224),
      env: nullptr,
      blendDuration: (float)v7,
      modelIndex: v8);
  }
  return this;
}


// ========================================================================
// ?Think@idVolume_RegimeRegenerate@@UAAXXZ
// EA  : 0x82D492C0
// RVA : 0x00D492C0
// PDB : w:\tech5\tungsten\game\entities\volume.cpp
// ========================================================================

void __fastcall idVolume_RegimeRegenerate::Think(idVolume_RegimeRegenerate *this)
{
  bool v2; // r25
  int v3; // r29
  int v4; // r31
  int value; // r9
  idEntity *v6; // r3
  idAI2 *v7; // r3
  float *v8; // r3
  double v9; // fp0
  int v10; // r9
  idEntity *v11; // r3
  int v12; // r9
  idEntity *v13; // r3
  idEntity *v14; // r31
  idPresentable *v15; // r3
  int v16; // r9
  idEntity *v17; // r3
  idEntity *v18; // r31
  idPresentable *v19; // r11
  int v20; // r4
  int v21; // r9
  idEntity *v22; // r3
  int v23; // r9
  idEntity *v24; // r3
  idEntity *v25; // r31
  idPresentable *presentable; // r3
  int v27; // r9
  idEntity *v28; // r3
  idEntity *v29; // r31

  v2 = false;
  idEntity::Think(this);
  v3 = 0;
  if ( this->touching.num > 0 )
  {
    v4 = 0;
    do
    {
      value = this->touching.list[v4].spawnId.value;
      if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
        && (v6 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
      {
        v7 = (idAI2 *)idEntity::CastTo(c: v6);
      }
      else
      {
        v7 = nullptr;
      }
      v8 = (float *)idAI2::CastTo(c: v7);
      if ( v8 != nullptr )
      {
        v9 = v8[15377];
        if ( v9 > 0.0 && v9 > v8[15378] )
        {
          (*(void (__fastcall **)(float *, double))(*(_DWORD *)v8 + 668))(a1: v8, a2: this->shieldHealthPerFrame);
          v2 = true;
        }
      }
      ++v3;
      ++v4;
    }
    while ( v3 < this->touching.num );
  }
  if ( v2 )
  {
    if ( !this->isHealing )
    {
      idEntity::StartSoundShader(
        this,
        channel: SND_CHANNEL_BOOST,
        shader: this->soundFieldActivating,
        soundShaderFlags: (soundShaderFlags_t)0,
        peerMask: 0xFFu);
      v21 = this->baseEntity.spawnId.value;
      if ( gameLocal->spawnIds.ptr[v21 & 0x1FFF] == v21 >> 13 )
      {
        v22 = gameLocal->entities.ptr[v21 & 0x1FFF];
        if ( v22 != nullptr && idEntity::CastTo(c: v22) != nullptr )
        {
          v23 = this->baseEntity.spawnId.value;
          if ( gameLocal->spawnIds.ptr[v23 & 0x1FFF] == v23 >> 13
            && (v24 = gameLocal->entities.ptr[v23 & 0x1FFF]) != nullptr )
          {
            v25 = idEntity::CastTo(c: v24);
          }
          else
          {
            v25 = nullptr;
          }
          presentable = v25->presentable;
          if ( presentable == nullptr )
          {
            idEntity::InitPresentableInternal(this: v25);
            presentable = v25->presentable;
          }
          presentable->StartFX(this: presentable, a2: FX_PROP_USE, a3: FX_EXTRA_COND_NONE);
          v27 = this->baseEntity.spawnId.value;
          if ( gameLocal->spawnIds.ptr[v27 & 0x1FFF] == v27 >> 13
            && (v28 = gameLocal->entities.ptr[v27 & 0x1FFF]) != nullptr )
          {
            v29 = idEntity::CastTo(c: v28);
          }
          else
          {
            v29 = nullptr;
          }
          v19 = v29->presentable;
          if ( v19 == nullptr )
          {
            idEntity::InitPresentableInternal(this: v29);
            v19 = v29->presentable;
          }
          v20 = 113;
          goto LABEL_48;
        }
      }
    }
  }
  else if ( this->isHealing )
  {
    idEntity::StartSoundShader(
      this,
      channel: SND_CHANNEL_BOOST,
      shader: this->soundFieldDeactivating,
      soundShaderFlags: (soundShaderFlags_t)0,
      peerMask: 0xFFu);
    v10 = this->baseEntity.spawnId.value;
    if ( gameLocal->spawnIds.ptr[v10 & 0x1FFF] == v10 >> 13 )
    {
      v11 = gameLocal->entities.ptr[v10 & 0x1FFF];
      if ( v11 != nullptr && idEntity::CastTo(c: v11) != nullptr )
      {
        v12 = this->baseEntity.spawnId.value;
        if ( gameLocal->spawnIds.ptr[v12 & 0x1FFF] == v12 >> 13
          && (v13 = gameLocal->entities.ptr[v12 & 0x1FFF]) != nullptr )
        {
          v14 = idEntity::CastTo(c: v13);
        }
        else
        {
          v14 = nullptr;
        }
        v15 = v14->presentable;
        if ( v15 == nullptr )
        {
          idEntity::InitPresentableInternal(this: v14);
          v15 = v14->presentable;
        }
        v15->StartFX(this: v15, a2: FX_PROP_STOP_USE, a3: FX_EXTRA_COND_NONE);
        v16 = this->baseEntity.spawnId.value;
        if ( gameLocal->spawnIds.ptr[v16 & 0x1FFF] == v16 >> 13
          && (v17 = gameLocal->entities.ptr[v16 & 0x1FFF]) != nullptr )
        {
          v18 = idEntity::CastTo(c: v17);
        }
        else
        {
          v18 = nullptr;
        }
        v19 = v18->presentable;
        if ( v19 == nullptr )
        {
          idEntity::InitPresentableInternal(this: v18);
          v19 = v18->presentable;
        }
        v20 = 114;
LABEL_48:
        idPresentable::StopFX(this: v19, condition: v20, extraCondition: FX_EXTRA_COND_NONE);
      }
    }
  }
  this->isHealing = v2;
}


// ========================================================================
// ?OnActivate@idVolume_RegimeRegenerate@@EAAXPAVidEntity@@@Z
// EA  : 0x82D49660
// RVA : 0x00D49660
// PDB : w:\tech5\tungsten\game\entities\volume.cpp
// ========================================================================

void __fastcall idVolume_RegimeRegenerate::OnActivate(idVolume_RegimeRegenerate *this, idEntity *activator)
{
  int value; // r9
  idEntity *v4; // r3
  int v5; // r9
  idEntity *v6; // r3
  idEntity *v7; // r31
  idPresentable *presentable; // r3
  int v9; // r9
  idEntity *v10; // r3
  idEntity *v11; // r31
  idPresentable *v12; // r11

  if ( this->startOff )
  {
    this->startOff = false;
    idEntity::BecomeActive(this, flags: 1);
  }
  else
  {
    idEntity::BecomeInactive(this, flags: 1);
    value = this->baseEntity.spawnId.value;
    if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
    {
      v4 = gameLocal->entities.ptr[value & 0x1FFF];
      if ( v4 != nullptr && idEntity::CastTo(c: v4) != nullptr )
      {
        v5 = this->baseEntity.spawnId.value;
        if ( gameLocal->spawnIds.ptr[v5 & 0x1FFF] == v5 >> 13 && (v6 = gameLocal->entities.ptr[v5 & 0x1FFF]) != nullptr )
          v7 = idEntity::CastTo(c: v6);
        else
          v7 = nullptr;
        presentable = v7->presentable;
        if ( presentable == nullptr )
        {
          idEntity::InitPresentableInternal(this: v7);
          presentable = v7->presentable;
        }
        presentable->StartFX(this: presentable, a2: FX_PROP_BREAK, a3: FX_EXTRA_COND_NONE);
        v9 = this->baseEntity.spawnId.value;
        if ( gameLocal->spawnIds.ptr[v9 & 0x1FFF] == v9 >> 13 && (v10 = gameLocal->entities.ptr[v9 & 0x1FFF]) != nullptr )
          v11 = idEntity::CastTo(c: v10);
        else
          v11 = nullptr;
        v12 = v11->presentable;
        if ( v12 == nullptr )
        {
          idEntity::InitPresentableInternal(this: v11);
          v12 = v11->presentable;
        }
        idPresentable::StopFX(this: v12, condition: 115, extraCondition: FX_EXTRA_COND_NONE);
      }
    }
  }
}


// ========================================================================
// ?Update@idCombatVolumeGroup@@QBAXXZ
// EA  : 0x82D497D8
// RVA : 0x00D497D8
// PDB : w:\tech5\tungsten\game\entities\volume.cpp
// ========================================================================

void __fastcall idCombatVolumeGroup::Update(idCombatVolumeGroup *this)
{
  int v2; // r30
  idList<idEntityPtr<idActor>,5> *p_actors; // r28
  int v4; // r29
  int value; // r9
  idActor *v6; // r3
  idActor *v7; // r3
  idEntity *v8; // r31
  int v9; // r3
  idPhysics *Physics; // r25
  idPhysics *v11; // r24
  float *v12; // r31
  float *v13; // r3
  char v14; // r11
  int num; // r11
  int v16; // r11

  v2 = 0;
  if ( this->actors.num > 0 )
  {
    p_actors = &this->actors;
    v4 = 0;
    do
    {
      value = p_actors->list[v4].spawnId.value;
      if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
      {
        v6 = (idActor *)gameLocal->entities.ptr[value & 0x1FFF];
        if ( v6 != nullptr )
        {
          v7 = idActor::CastTo(c: v6);
          v8 = v7;
          if ( v7 != nullptr )
          {
            v9 = (int)v7->GetHealthComponent(this: v7);
            if ( ((double (__fastcall *)(int))*(_DWORD *)(*(_DWORD *)v9 + 60))(a1: v9) <= 0.0 )
              goto LABEL_24;
            Physics = idEntity::GetPhysics(this: this->combatVolume);
            v11 = idEntity::GetPhysics(this: v8);
            v12 = (float *)Physics->GetBounds(this: Physics, a2: -1);
            v13 = (float *)v11->GetBounds(this: v11, a2: -1);
            if ( v12[3] < (double)*v13
              || v12[4] < (double)v13[1]
              || v12[5] < (double)v13[2]
              || *v12 > (double)v13[3]
              || v12[1] > (double)v13[4]
              || (v14 = 1, v12[2] > (double)v13[5]) )
            {
              v14 = 0;
            }
            if ( v14 == 0 )
            {
LABEL_24:
              if ( v2 >= 0 )
              {
                num = p_actors->num;
                if ( v2 < num )
                {
                  v16 = num - 1;
                  p_actors->num = v16;
                  if ( v2 != v16 )
                    p_actors->list[v4].spawnId.value = p_actors->list[v16].spawnId.value;
                }
              }
              --v2;
              --v4;
            }
          }
        }
      }
      ++v2;
      ++v4;
    }
    while ( v2 < this->actors.num );
  }
  this->nextUpdateTime = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) + 250;
}


// ========================================================================
// ?Event_Untouch@idVolume_DynamicJob@@QAA?AVeventVoid@@PAVidEntity@@H@Z
// EA  : 0x82D499C8
// RVA : 0x00D499C8
// PDB : w:\tech5\tungsten\game\entities\volume.cpp
// ========================================================================

idVolume_DynamicJob *__fastcall idVolume_DynamicJob::Event_Untouch(
        idVolume_DynamicJob *this,
        idVolume *result,
        idEntity *other,
        int clipModelId)
{
  idPlayer *PlayerFromEntity; // r3
  const idDeclJob *v8; // r4
  int v9; // r29
  int v10; // r30
  idEntityPtr<idEntity> *v11; // r3
  idEntity *v12; // r3

  idVolume::RemoveTouching(this: result, other);
  if ( BYTE1(result[1].listenerList) != 0 && HIBYTE(result[1].spawnOrientation.mat[0].x) != 0 )
  {
    PlayerFromEntity = idGameLocal::GetPlayerFromEntity(this: gameLocal, activator: other);
    if ( PlayerFromEntity != nullptr )
    {
      v8 = (const idDeclJob *)result[1].__vftable;
      if ( v8 != nullptr )
      {
        idPlayer::StartRemovalOfDynamicJob(this: PlayerFromEntity, job: v8);
        v9 = 0;
        if ( *(int *)&result[1].name.baseBuffer[4] > 0 )
        {
          v10 = 0;
          do
          {
            v11 = (idEntityPtr<idEntity> *)(*(_DWORD *)result[1].name.baseBuffer + v10);
            if ( gameLocal->spawnIds.ptr[v11->spawnId.value & 0x1FFF] == v11->spawnId.value >> 13 )
            {
              v12 = idEntityPtr<idEntity const>::operator->(this: v11);
              idEntity::Activate(this: v12, activator: other);
            }
            ++v9;
            v10 += 4;
          }
          while ( v9 < *(_DWORD *)&result[1].name.baseBuffer[4] );
        }
      }
    }
  }
  return this;
}


// ========================================================================
// ?Event_Touch@idVolume_RunCycleHint@@QAA?AVeventVoid@@PAVidEntity@@H@Z
// EA  : 0x82D49A98
// RVA : 0x00D49A98
// PDB : w:\tech5\tungsten\game\entities\volume.cpp
// ========================================================================

idVolume_RunCycleHint *__fastcall idVolume_RunCycleHint::Event_Touch(
        idVolume_RunCycleHint *this,
        idEntity *result,
        idAI2 *other,
        int clipModelId)
{
  idAI2 *v6; // r3
  idAI2 *v7; // r25
  bool v8; // r24
  idPhysics *Physics; // r3
  int v10; // r28
  int v11; // r29
  int value; // r9
  idEntity *v13; // r3
  idEntity *v14; // r31
  idPhysics *v15; // r3
  float *v16; // r22
  idPhysics *v17; // r3
  float *v18; // r3
  double v19; // fp13
  double v20; // fp12
  double v21; // fp0
  double v22; // fp11
  double v25; // fp6
  double v26; // fp2
  double v27; // fp11
  double v28; // fp9
  idVec3 v30[4]; // [sp+50h] [-90h] BYREF

  v6 = idAI2::CastTo(c: other);
  v7 = v6;
  if ( v6 != nullptr )
  {
    v8 = (_cntlzw(result->targets.num) & 0x20) != 0;
    Physics = idEntity::GetPhysics(this: v6);
    Physics->GetLinearVelocity(this: (idPhysics *)v30, result: (idVec3 *)Physics, a3: 0);
    if ( (float)((float)(v30[0].x * v30[0].x) + (float)((float)(v30[0].z * v30[0].z) + (float)(v30[0].y * v30[0].y))) > 1.0 )
      idVec3::NormalizeFast(this: v30);
    v10 = 0;
    if ( result->targets.num > 0 )
    {
      v11 = 0;
      while ( 1 )
      {
        value = result->targets.list[v11].spawnId.value;
        if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
          && (v13 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
        {
          v14 = idEntity::CastTo(c: v13);
        }
        else
        {
          v14 = nullptr;
        }
        v15 = idEntity::GetPhysics(this: result);
        v16 = (float *)v15->GetOrigin(this: v15, a2: 0);
        v17 = idEntity::GetPhysics(this: v14);
        v18 = (float *)v17->GetOrigin(this: v17, a2: 0);
        v19 = (float)(v18[1] - v16[1]);
        v20 = (float)(v18[2] - v16[2]);
        v21 = (float)(*v18 - *v16);
        v22 = (float)((float)((float)(*v18 - *v16) * (float)(*v18 - *v16))
                    + (float)((float)((float)v20 * (float)v20) + (float)((float)v19 * (float)v19)));
        if ( v22 > 1.0 )
        {
          _FP8 = (float)((float)((float)((float)(*v18 - *v16) * (float)(*v18 - *v16))
                               + (float)((float)((float)v20 * (float)v20) + (float)((float)v19 * (float)v19)))
                       - idMath::FLT_SMALLEST_NON_DENORMAL);
          __asm { fsel      f7, f8, f11, f10 }
          v25 = __frsqrte(_FP7);
          v26 = (float)((float)-(float)((float)((float)((float)v25
                                                      * (float)((float)((float)((float)(*v18 - *v16)
                                                                              * (float)(*v18 - *v16))
                                                                      + (float)((float)((float)v20 * (float)v20)
                                                                              + (float)((float)v19 * (float)v19)))
                                                              * (float)0.5))
                                              * (float)v25)
                                      - (float)1.5)
                      * (float)v25);
          v27 = (float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v25
                                                                                      * (float)((float)v22 * (float)0.5))
                                                                              * (float)v25)
                                                                      - (float)1.5)
                                                      * (float)v25)
                                              * (float)((float)v22 * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v25
                                                                              * (float)((float)v22 * (float)0.5))
                                                                      * (float)v25)
                                                              - (float)1.5)
                                              * (float)v25))
                              - (float)1.5);
          v28 = (float)((float)((float)v27
                              * (float)((float)-(float)((float)((float)((float)v25
                                                                      * (float)((float)((float)((float)(*v18 - *v16)
                                                                                              * (float)(*v18 - *v16))
                                                                                      + (float)((float)((float)v20 * (float)v20)
                                                                                              + (float)((float)v19 * (float)v19)))
                                                                              * (float)0.5))
                                                              * (float)v25)
                                                      - (float)1.5)
                                      * (float)v25))
                      * (float)((float)((float)((float)(*v18 - *v16) * (float)(*v18 - *v16))
                                      + (float)((float)((float)v20 * (float)v20) + (float)((float)v19 * (float)v19)))
                              * (float)0.5));
          v21 = (float)((float)(*v18 - *v16)
                      * (float)((float)-(float)((float)((float)((float)((float)v27
                                                                      * (float)((float)-(float)((float)((float)((float)v25 * (float)((float)((float)((float)(*v18 - *v16) * (float)(*v18 - *v16)) + (float)((float)((float)v20 * (float)v20) + (float)((float)v19 * (float)v19))) * (float)0.5)) * (float)v25)
                                                                                              - (float)1.5)
                                                                              * (float)v25))
                                                              * (float)((float)((float)((float)(*v18 - *v16)
                                                                                      * (float)(*v18 - *v16))
                                                                              + (float)((float)((float)v20 * (float)v20)
                                                                                      + (float)((float)v19 * (float)v19)))
                                                                      * (float)0.5))
                                                      * (float)((float)v27 * (float)v26))
                                              - (float)1.5)
                              * (float)((float)v27 * (float)v26)));
          v19 = (float)((float)(v18[1] - v16[1])
                      * (float)((float)-(float)((float)((float)((float)((float)v27
                                                                      * (float)((float)-(float)((float)((float)((float)v25 * (float)((float)((float)((float)(*v18 - *v16) * (float)(*v18 - *v16)) + (float)((float)((float)v20 * (float)v20) + (float)((float)v19 * (float)v19))) * (float)0.5)) * (float)v25)
                                                                                              - (float)1.5)
                                                                              * (float)v25))
                                                              * (float)((float)((float)((float)(*v18 - *v16)
                                                                                      * (float)(*v18 - *v16))
                                                                              + (float)((float)((float)v20 * (float)v20)
                                                                                      + (float)((float)v19 * (float)v19)))
                                                                      * (float)0.5))
                                                      * (float)((float)v27 * (float)v26))
                                              - (float)1.5)
                              * (float)((float)v27 * (float)v26)));
          v20 = (float)((float)(v18[2] - v16[2])
                      * (float)((float)-(float)((float)((float)v28 * (float)((float)v27 * (float)v26)) - (float)1.5)
                              * (float)((float)v27 * (float)v26)));
        }
        if ( (float)((float)((float)v21 * v30[0].x)
                   + (float)((float)((float)v20 * v30[0].z) + (float)((float)v19 * v30[0].y))) > 0.70700002 )
          break;
        ++v10;
        ++v11;
        if ( v10 >= result->targets.num )
          goto LABEL_16;
      }
      v8 = true;
    }
LABEL_16:
    if ( v8 )
      idAI2::SetRunCycleHint(this: v7, runType: *(runIndexType_t *)result[1].name.baseBuffer);
  }
  return this;
}


// ========================================================================
// ?Event_Untouch@idVolume_RunCycleHint@@QAA?AVeventVoid@@PAVidEntity@@H@Z
// EA  : 0x82D49CD8
// RVA : 0x00D49CD8
// PDB : w:\tech5\tungsten\game\entities\volume.cpp
// ========================================================================

idVolume_RunCycleHint *__fastcall idVolume_RunCycleHint::Event_Untouch(
        idVolume_RunCycleHint *this,
        idVolume *result,
        idAI2 *other,
        int clipModelId)
{
  idAI2 *v7; // r3
  idAI2 *v8; // r25
  bool v9; // r24
  idPhysics *Physics; // r3
  int v11; // r28
  int v12; // r29
  int value; // r9
  idEntity *v14; // r3
  idEntity *v15; // r31
  idPhysics *v16; // r3
  float *v17; // r22
  idPhysics *v18; // r3
  float *v19; // r3
  double v20; // fp13
  double v21; // fp12
  double v22; // fp0
  double v23; // fp11
  double v26; // fp6
  double v27; // fp2
  double v28; // fp11
  double v29; // fp9
  idVec3 v31[4]; // [sp+50h] [-90h] BYREF

  idVolume::RemoveTouching(this: result, other);
  v7 = idAI2::CastTo(c: other);
  v8 = v7;
  if ( v7 != nullptr )
  {
    v9 = (_cntlzw(result->targets.num) & 0x20) != 0;
    Physics = idEntity::GetPhysics(this: v7);
    Physics->GetLinearVelocity(this: (idPhysics *)v31, result: (idVec3 *)Physics, a3: 0);
    if ( (float)((float)(v31[0].x * v31[0].x) + (float)((float)(v31[0].z * v31[0].z) + (float)(v31[0].y * v31[0].y))) > 1.0 )
      idVec3::NormalizeFast(this: v31);
    v11 = 0;
    if ( result->targets.num > 0 )
    {
      v12 = 0;
      while ( 1 )
      {
        value = result->targets.list[v12].spawnId.value;
        if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
          && (v14 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
        {
          v15 = idEntity::CastTo(c: v14);
        }
        else
        {
          v15 = nullptr;
        }
        v16 = idEntity::GetPhysics(this: result);
        v17 = (float *)v16->GetOrigin(this: v16, a2: 0);
        v18 = idEntity::GetPhysics(this: v15);
        v19 = (float *)v18->GetOrigin(this: v18, a2: 0);
        v20 = (float)(v19[1] - v17[1]);
        v21 = (float)(v19[2] - v17[2]);
        v22 = (float)(*v19 - *v17);
        v23 = (float)((float)((float)(*v19 - *v17) * (float)(*v19 - *v17))
                    + (float)((float)((float)v21 * (float)v21) + (float)((float)v20 * (float)v20)));
        if ( v23 > 1.0 )
        {
          _FP8 = (float)((float)((float)((float)(*v19 - *v17) * (float)(*v19 - *v17))
                               + (float)((float)((float)v21 * (float)v21) + (float)((float)v20 * (float)v20)))
                       - idMath::FLT_SMALLEST_NON_DENORMAL);
          __asm { fsel      f7, f8, f11, f10 }
          v26 = __frsqrte(_FP7);
          v27 = (float)((float)-(float)((float)((float)((float)v26
                                                      * (float)((float)((float)((float)(*v19 - *v17)
                                                                              * (float)(*v19 - *v17))
                                                                      + (float)((float)((float)v21 * (float)v21)
                                                                              + (float)((float)v20 * (float)v20)))
                                                              * (float)0.5))
                                              * (float)v26)
                                      - (float)1.5)
                      * (float)v26);
          v28 = (float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v26
                                                                                      * (float)((float)v23 * (float)0.5))
                                                                              * (float)v26)
                                                                      - (float)1.5)
                                                      * (float)v26)
                                              * (float)((float)v23 * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v26
                                                                              * (float)((float)v23 * (float)0.5))
                                                                      * (float)v26)
                                                              - (float)1.5)
                                              * (float)v26))
                              - (float)1.5);
          v29 = (float)((float)((float)v28
                              * (float)((float)-(float)((float)((float)((float)v26
                                                                      * (float)((float)((float)((float)(*v19 - *v17)
                                                                                              * (float)(*v19 - *v17))
                                                                                      + (float)((float)((float)v21 * (float)v21)
                                                                                              + (float)((float)v20 * (float)v20)))
                                                                              * (float)0.5))
                                                              * (float)v26)
                                                      - (float)1.5)
                                      * (float)v26))
                      * (float)((float)((float)((float)(*v19 - *v17) * (float)(*v19 - *v17))
                                      + (float)((float)((float)v21 * (float)v21) + (float)((float)v20 * (float)v20)))
                              * (float)0.5));
          v22 = (float)((float)(*v19 - *v17)
                      * (float)((float)-(float)((float)((float)((float)((float)v28
                                                                      * (float)((float)-(float)((float)((float)((float)v26 * (float)((float)((float)((float)(*v19 - *v17) * (float)(*v19 - *v17)) + (float)((float)((float)v21 * (float)v21) + (float)((float)v20 * (float)v20))) * (float)0.5)) * (float)v26)
                                                                                              - (float)1.5)
                                                                              * (float)v26))
                                                              * (float)((float)((float)((float)(*v19 - *v17)
                                                                                      * (float)(*v19 - *v17))
                                                                              + (float)((float)((float)v21 * (float)v21)
                                                                                      + (float)((float)v20 * (float)v20)))
                                                                      * (float)0.5))
                                                      * (float)((float)v28 * (float)v27))
                                              - (float)1.5)
                              * (float)((float)v28 * (float)v27)));
          v20 = (float)((float)(v19[1] - v17[1])
                      * (float)((float)-(float)((float)((float)((float)((float)v28
                                                                      * (float)((float)-(float)((float)((float)((float)v26 * (float)((float)((float)((float)(*v19 - *v17) * (float)(*v19 - *v17)) + (float)((float)((float)v21 * (float)v21) + (float)((float)v20 * (float)v20))) * (float)0.5)) * (float)v26)
                                                                                              - (float)1.5)
                                                                              * (float)v26))
                                                              * (float)((float)((float)((float)(*v19 - *v17)
                                                                                      * (float)(*v19 - *v17))
                                                                              + (float)((float)((float)v21 * (float)v21)
                                                                                      + (float)((float)v20 * (float)v20)))
                                                                      * (float)0.5))
                                                      * (float)((float)v28 * (float)v27))
                                              - (float)1.5)
                              * (float)((float)v28 * (float)v27)));
          v21 = (float)((float)(v19[2] - v17[2])
                      * (float)((float)-(float)((float)((float)v29 * (float)((float)v28 * (float)v27)) - (float)1.5)
                              * (float)((float)v28 * (float)v27)));
        }
        if ( (float)((float)((float)v22 * v31[0].x)
                   + (float)((float)((float)v21 * v31[0].z) + (float)((float)v20 * v31[0].y))) > 0.70700002 )
          break;
        ++v11;
        ++v12;
        if ( v11 >= result->targets.num )
          goto LABEL_16;
      }
      v9 = true;
    }
LABEL_16:
    if ( v9 )
      idAI2::SetRunCycleHint(this: v8, runType: ANIMWEBAI_RUNINDEXTYPE_NORMAL);
  }
  return this;
}


// ========================================================================
// ?Event_Touch@idVolume_KillDownedInjured@@QAA?AVeventVoid@@PAVidEntity@@H@Z
// EA  : 0x82D49F28
// RVA : 0x00D49F28
// PDB : w:\tech5\tungsten\game\entities\volume.cpp
// ========================================================================

idVolume_KillDownedInjured *__fastcall idVolume_KillDownedInjured::Event_Touch(
        idVolume_KillDownedInjured *this,
        idEntity *result,
        idAI2 *other,
        int clipModelId)
{
  idAI2 *v6; // r3
  idAI2 *v7; // r28
  idEntity *LastInflictor; // r27
  idEntity *LastAttacker; // r29
  idPhysics *Physics; // r3
  idEntity_vtbl *v11; // r30
  const idDeclAIBehavior *decl; // r28

  v6 = idAI2::CastTo(c: other);
  v7 = v6;
  if ( v6 != nullptr
    && v6->GetPosture(this: v6) == POSTURE_CROUCHED
    && v7->aiVolatile.animation.animWebAnimator.ptr[0].runIndexType == ANIMWEBAI_RUNINDEXTYPE_INJURED )
  {
    if ( idAIMemory::GetLastInflictor(this: &v7->aiVolatile.memory) != nullptr )
      LastInflictor = idAIMemory::GetLastInflictor(this: &v7->aiVolatile.memory);
    else
      LastInflictor = result;
    if ( idAIMemory::GetLastAttacker(this: &v7->aiVolatile.memory) != nullptr )
      LastAttacker = idAIMemory::GetLastAttacker(this: &v7->aiVolatile.memory);
    else
      LastAttacker = result;
    Physics = idEntity::GetPhysics(this: result);
    v11 = result->__vftable;
    decl = v7->aiEditable.behaviors.decl;
    Physics->GetGravityNormal(this: Physics);
    ((void (__fastcall *)(idEntity *, idEntity *, idEntity *, const idDeclDamage *, double))v11->Damage)(
      a1: result,
      a2: LastInflictor,
      a3: LastAttacker,
      a4: decl->damageBehaviors.bleedOutDamageDecl,
      a5: 100.0);
  }
  return this;
}


// ========================================================================
// ?Event_Untouch@idVolume_ForceDormant@@QAA?AVeventVoid@@PAVidEntity@@H@Z
// EA  : 0x82D4A088
// RVA : 0x00D4A088
// PDB : w:\tech5\tungsten\game\entities\volume.cpp
// ========================================================================

idVolume_ForceDormant *__fastcall idVolume_ForceDormant::Event_Untouch(
        idVolume_ForceDormant *this,
        idVolume *result,
        idPlayer *other,
        int clipModelId)
{
  idPlayer *v7; // r27
  int v8; // r30
  int v9; // r31
  int value; // r9
  idEntity *v11; // r3
  idPlayer *v12; // r3
  idPlayer *v13; // r3
  idVehicle *v15; // r3
  idVehicle *v16; // r30
  int v17; // r31
  idEntity *OccupantAsEntity; // r5
  char v19; // [sp+50h] [-40h] BYREF

  idVolume::RemoveTouching(this: result, other);
  v7 = idPlayer::CastTo(c: other);
  if ( v7 != nullptr )
  {
    if ( (result->thinkFlags & 1) != 0 )
    {
      v8 = 0;
      if ( result->touching.num <= 0 )
      {
LABEL_12:
        idEntity::BecomeInactive(this: result, flags: 1);
        if ( BYTE2(result[1].name.allocedAndFlag) != 0 )
        {
          gameLocal->enableVehicleSplineUpdates = true;
          return this;
        }
      }
      else
      {
        v9 = 0;
        while ( 1 )
        {
          value = result->touching.list[v9].spawnId.value;
          if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
            && (v11 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
          {
            v12 = (idPlayer *)idEntity::CastTo(c: v11);
          }
          else
          {
            v12 = nullptr;
          }
          v13 = idPlayer::CastTo(c: v12);
          if ( v13 != nullptr && v13 != v7 )
            break;
          ++v8;
          ++v9;
          if ( v8 >= result->touching.num )
            goto LABEL_12;
        }
      }
    }
  }
  else
  {
    v15 = idVehicle::CastTo(c: (idVehicle *)other);
    v16 = v15;
    if ( v15 != nullptr )
    {
      v17 = 0;
      if ( idVehicle::GetNumActiveOccupants(this: v15) > 0 )
      {
        do
        {
          OccupantAsEntity = idVehicle::GetOccupantAsEntity(this: v16, index: v17);
          if ( OccupantAsEntity != nullptr )
            idVolume_ForceDormant::Event_Untouch(
              this: (idVolume_ForceDormant *)&v19,
              (eventVoid *)result,
              other: OccupantAsEntity,
              clipModelId: 0);
          ++v17;
        }
        while ( v17 < idVehicle::GetNumActiveOccupants(this: v16) );
      }
    }
  }
  return this;
}


// ========================================================================
// ?Think@idVolume_PlayerInteraction@@UAAXXZ
// EA  : 0x82D4A268
// RVA : 0x00D4A268
// PDB : w:\tech5\tungsten\game\entities\volume.cpp
// ========================================================================

void __fastcall idVolume_PlayerInteraction::Think(idVolume_PlayerInteraction *this)
{
  int v2; // r24
  idVec3 *p_playerPos; // r28
  int v4; // r27
  int value; // r9
  idEntity *v6; // r3
  idPlayer *v7; // r3
  idPlayer *v8; // r22
  char v9; // r30
  idPhysics *Physics; // r3
  float *v11; // r3
  double v12; // fp31
  double v13; // fp30
  double v14; // fp29
  idPhysics *v15; // r3
  float *v16; // r3
  double v17; // fp3
  double v18; // fp1
  double v19; // fp31
  double v20; // fp2

  v2 = 0;
  if ( this->touching.num > 0 )
  {
    p_playerPos = &this->playerPos;
    v4 = 0;
    do
    {
      value = this->touching.list[v4].spawnId.value;
      if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
        && (v6 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
      {
        v7 = (idPlayer *)idEntity::CastTo(c: v6);
      }
      else
      {
        v7 = nullptr;
      }
      v8 = idPlayer::CastTo(c: v7);
      v9 = 0;
      Physics = idEntity::GetPhysics(this);
      v11 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
      v12 = (float)(p_playerPos->x + *v11);
      v13 = (float)(v11[1] + p_playerPos->y);
      v14 = (float)(v11[2] + p_playerPos->z);
      v15 = idEntity::GetPhysics(this: v8);
      v16 = (float *)v15->GetOrigin(this: v15, a2: 0);
      v17 = (float)((float)v14 - v16[2]);
      v18 = (float)((float)v13 - v16[1]);
      v19 = (float)((float)((float)v18 * (float)v18)
                  + (float)((float)((float)v17 * (float)v17)
                          + (float)((float)((float)v12 - *v16) * (float)((float)v12 - *v16))));
      if ( v19 < (float)(this->interactionDistance * this->interactionDistance) )
      {
        v9 = 1;
        if ( this->startDelayTime < 0 )
          this->startDelayTime = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
      }
      if ( v9 != 0 )
      {
        idLib::Printf(fmt: "GOOD HOLD!!!!\n");
        gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
      }
      else
      {
        v20 = (float)(this->interactionDistance * this->interactionDistance);
        if ( this->startDelayTime < 0 )
        {
          idLib::Printf(fmt: (const char *)HIDWORD(v19), LODWORD(v19), LODWORD(v20));
        }
        else
        {
          idLib::Printf(fmt: (const char *)HIDWORD(v19), LODWORD(v19), LODWORD(v20), v19);
          this->startDelayTime = -1;
        }
      }
      ++v2;
      ++v4;
    }
    while ( v2 < this->touching.num );
  }
}


// ========================================================================
// ?Event_Untouch@idVolume_PlayerInteraction@@QAA?AVeventVoid@@PAVidEntity@@H@Z
// EA  : 0x82D4A470
// RVA : 0x00D4A470
// PDB : w:\tech5\tungsten\game\entities\volume.cpp
// ========================================================================

idVolume_PlayerInteraction *__fastcall idVolume_PlayerInteraction::Event_Untouch(
        idVolume_PlayerInteraction *this,
        idVolume *result,
        idEntity *other,
        int clipModelId)
{
  int v7; // r11
  char v8; // r11
  bool v9; // zf

  v7 = *(_DWORD *)(other->GetType(this: other) + 36);
  if ( v7 < idPlayer::Type.typeNum || (v9 = v7 <= idPlayer::Type.lastChild, v8 = 1, !v9) )
    v8 = 0;
  if ( v8 != 0 )
  {
    idVolume::RemoveTouching(this: result, other);
    if ( result->touching.num <= 0 )
      idEntity::BecomeInactive(this: result, flags: 1);
  }
  return this;
}


// ========================================================================
// ?GetClosestEnterPoint@idVolume_Restriction@@QBAPAVidEntity@@ABVidVec3@@@Z
// EA  : 0x82D4A5D0
// RVA : 0x00D4A5D0
// PDB : w:\tech5\tungsten\game\entities\volume.cpp
// ========================================================================

idEntity *__fastcall idVolume_Restriction::GetClosestEnterPoint(idVolume_Restriction *this, const idVec3 *comparePos)
{
  int num; // r26
  idEntity *v6; // r24
  int v7; // r28
  double v8; // fp31
  int v9; // r30
  int value; // r9
  idEntity *v11; // r3
  idEntity *v12; // r31
  idPhysics *Physics; // r3
  float *v14; // r3
  double v15; // fp10
  double v16; // fp6
  double v17; // fp30
  idPhysics *v18; // r3
  const idVec3 *v19; // r3

  if ( (*(_BYTE *)&this->flags & 8) == 0 )
    return nullptr;
  num = this->targets.num;
  if ( num <= 0 )
    return nullptr;
  v6 = nullptr;
  v7 = 0;
  v8 = -1.0;
  v9 = 0;
  do
  {
    if ( v7 < this->targets.num
      && (value = this->targets.list[v9].spawnId.value, gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13)
      && (v11 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
    {
      v12 = idEntity::CastTo(c: v11);
    }
    else
    {
      v12 = nullptr;
    }
    Physics = idEntity::GetPhysics(this: v12);
    v14 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
    v15 = (float)(v14[2] - comparePos->z);
    v16 = (float)(v14[1] - comparePos->y);
    v17 = (float)((float)((float)v16 * (float)v16)
                + (float)((float)((float)(*v14 - comparePos->x) * (float)(*v14 - comparePos->x))
                        + (float)((float)v15 * (float)v15)));
    v18 = idEntity::GetPhysics(this: v12);
    v19 = v18->GetOrigin(this: v18, a2: 0);
    if ( (unsigned __int8)idVolume_ItemGroup::Contains(this, pos: v19) != 0 && (v8 < 0.0 || v17 < v8) )
    {
      v6 = v12;
      v8 = v17;
    }
    ++v7;
    ++v9;
  }
  while ( v7 < num );
  return v6;
}


// ========================================================================
// ?Use@idVolume_ShowGui_Leveltransition@@UAA_NPAVidEntity@@W4usableState_t@@@Z
// EA  : 0x82D4A8B0
// RVA : 0x00D4A8B0
// PDB : w:\tech5\tungsten\game\entities\volume.cpp
// ========================================================================

int __fastcall idVolume_ShowGui_Leveltransition::Use(
        idVolume_ShowGui_Leveltransition *this,
        idEntity *activator,
        const usableState_t usable)
{
  idPlayer *PlayerFromEntity; // r3
  idPlayer *v7; // r30
  const idSoundShader *useSound; // r5

  if ( this->disabledUntilUntouch )
    return 0;
  PlayerFromEntity = idGameLocal::GetPlayerFromEntity(this: gameLocal, activator);
  v7 = PlayerFromEntity;
  if ( PlayerFromEntity == nullptr
    || !PlayerFromEntity->levelTransitionGuiVolumeActive
    || PlayerFromEntity->levelTransitionGuiVolume != this
    || !idVolume_ShowGui_Leveltransition::CheckFacingTarget(this, player: PlayerFromEntity) )
  {
    return 0;
  }
  this->ActivateTargets(this, a2: activator);
  if ( this->deactivateOnUse )
  {
    idVolume_ShowGui_Leveltransition::DeactivateGui(this, other: activator);
    this->disabledUntilUntouch = true;
  }
  useSound = this->useSound;
  if ( useSound != nullptr )
    idPlayer::PlayLocalSound(this: v7, channel: SND_CHANNEL_ALERT, shader: useSound, soundShaderFlags: 0);
  return 1;
}


// ========================================================================
// ?Use@idVolume_ItemGroup@@UAA_NPAVidEntity@@W4usableState_t@@@Z
// EA  : 0x82D4A988
// RVA : 0x00D4A988
// PDB : w:\tech5\tungsten\game\entities\volume.cpp
// ========================================================================

int __fastcall idVolume_ItemGroup::Use(idVolume_ItemGroup *this, idPlayer *activator, const usableState_t usable)
{
  idPlayer *v4; // r3

  v4 = idPlayer::CastTo(c: activator);
  idVolume_ItemGroup::Pickup(this, player: v4);
  return 1;
}


// ========================================================================
// ?Count@idCombatVolumeGroup@@QBAHXZ
// EA  : 0x82D4A9C8
// RVA : 0x00D4A9C8
// PDB : w:\tech5\tungsten\game\entities\volume.cpp
// ========================================================================

int __fastcall idCombatVolumeGroup::Count(idCombatVolumeGroup *this)
{
  if ( idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) >= this->nextUpdateTime
    && this->actors.num > 0 )
  {
    idCombatVolumeGroup::Update(this);
  }
  return this->actors.num;
}


// ========================================================================
// ?AverageHealth@idCombatVolumeGroup@@QBAMXZ
// EA  : 0x82D4AA30
// RVA : 0x00D4AA30
// PDB : w:\tech5\tungsten\game\entities\volume.cpp
// ========================================================================

float __fastcall idCombatVolumeGroup::AverageHealth(idCombatVolumeGroup *this)
{
  double v2; // fp1
  int v3; // r27
  int v4; // r29
  double v5; // fp31
  int v6; // r31
  int value; // r9
  idActor *v8; // r3
  idActor *v9; // r3
  __int64 v10; // r11
  int v11; // r3

  if ( idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) >= this->nextUpdateTime
    && this->actors.num > 0 )
  {
    idCombatVolumeGroup::Update(this);
  }
  if ( this->actors.num >= 1 )
  {
    v3 = 0;
    v4 = 0;
    v5 = 0.0;
    v6 = 0;
    do
    {
      value = this->actors.list[v6].spawnId.value;
      if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
        && (v8 = (idActor *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
      {
        v9 = idActor::CastTo(c: v8);
      }
      else
      {
        v9 = nullptr;
      }
      v11 = (int)v9->GetHealthComponent_2(this: v9);
      if ( v11 != 0 )
      {
        v5 = (float)((float)((double (__fastcall *)(int))*(_DWORD *)(*(_DWORD *)v11 + 60))(a1: v11) + (float)v5);
        ++v3;
      }
      ++v4;
      ++v6;
    }
    while ( v4 < this->actors.num );
    if ( v3 != 0 )
    {
      LODWORD(v10) = v3;
      v2 = (float)((float)v5 / (float)v10);
    }
    else
    {
      v2 = 0.0;
    }
  }
  else
  {
    v2 = 10.0;
  }
  return *((float *)&v2 + 1);
}


// ========================================================================
// ?HighestHealth@idCombatVolumeGroup@@QBAMXZ
// EA  : 0x82D4AB98
// RVA : 0x00D4AB98
// PDB : w:\tech5\tungsten\game\entities\volume.cpp
// ========================================================================

float __fastcall idCombatVolumeGroup::HighestHealth(idCombatVolumeGroup *this)
{
  double v2; // fp1
  int v3; // r27
  double v4; // fp31
  int v5; // r30
  int value; // r9
  idActor *v7; // r3
  idActor *v8; // r3
  int v9; // r3
  int v10; // r31

  if ( idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) >= this->nextUpdateTime
    && this->actors.num > 0 )
  {
    idCombatVolumeGroup::Update(this);
  }
  if ( this->actors.num >= 1 )
  {
    v3 = 0;
    v4 = -3.4028235e38;
    v5 = 0;
    do
    {
      value = this->actors.list[v5].spawnId.value;
      if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
        && (v7 = (idActor *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
      {
        v8 = idActor::CastTo(c: v7);
      }
      else
      {
        v8 = nullptr;
      }
      v9 = (int)v8->GetHealthComponent_2(this: v8);
      v10 = v9;
      if ( v9 != 0 && ((double (__fastcall *)(int))*(_DWORD *)(*(_DWORD *)v9 + 60))(a1: v9) > v4 )
        v4 = ((double (__fastcall *)(int))*(_DWORD *)(*(_DWORD *)v10 + 60))(a1: v10);
      ++v3;
      ++v5;
    }
    while ( v3 < this->actors.num );
    v2 = v4;
  }
  else
  {
    v2 = 10.0;
  }
  return *((float *)&v2 + 1);
}


// ========================================================================
// ?LowestHealth@idCombatVolumeGroup@@QBAMXZ
// EA  : 0x82D4ACD8
// RVA : 0x00D4ACD8
// PDB : w:\tech5\tungsten\game\entities\volume.cpp
// ========================================================================

float __fastcall idCombatVolumeGroup::LowestHealth(idCombatVolumeGroup *this)
{
  double v2; // fp1
  int v3; // r27
  double v4; // fp31
  int v5; // r30
  int value; // r9
  idActor *v7; // r3
  idActor *v8; // r3
  int v9; // r31

  if ( idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) >= this->nextUpdateTime
    && this->actors.num > 0 )
  {
    idCombatVolumeGroup::Update(this);
  }
  if ( this->actors.num >= 1 )
  {
    v3 = 0;
    v4 = 3.4028235e38;
    v5 = 0;
    do
    {
      value = this->actors.list[v5].spawnId.value;
      if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
        && (v7 = (idActor *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
      {
        v8 = idActor::CastTo(c: v7);
      }
      else
      {
        v8 = nullptr;
      }
      v9 = (int)v8->GetHealthComponent_2(this: v8);
      if ( ((double (__fastcall *)(int))*(_DWORD *)(*(_DWORD *)v9 + 60))(a1: v9) < v4 )
        v4 = ((double (__fastcall *)(int))*(_DWORD *)(*(_DWORD *)v9 + 60))(a1: v9);
      ++v3;
      ++v5;
    }
    while ( v3 < this->actors.num );
    v2 = v4;
  }
  else
  {
    v2 = 50.0;
  }
  return *((float *)&v2 + 1);
}


// ========================================================================
// ?Event_CountInGroup@idCombatVolume@@QBA?AVeventInt@@PBD@Z
// EA  : 0x82D4AE10
// RVA : 0x00D4AE10
// PDB : w:\tech5\tungsten\game\entities\volume.cpp
// ========================================================================

idCombatVolume *__fastcall idCombatVolume::Event_CountInGroup(
        idCombatVolume *this,
        idCombatVolume *result,
        const char *groupName)
{
  idCombatVolumeGroup *Group; // r3
  int v5; // r4

  Group = idCombatVolume::FindGroup(this: result, groupName);
  if ( Group != nullptr )
    v5 = idCombatVolumeGroup::Count(this: Group);
  else
    v5 = 0;
  eventInt::eventInt((eventInt *)this, i: v5);
  return this;
}


// ========================================================================
// ?Event_AverageHealthInGroup@idCombatVolume@@QBA?AVeventInt@@PBD@Z
// EA  : 0x82D4AE68
// RVA : 0x00D4AE68
// PDB : w:\tech5\tungsten\game\entities\volume.cpp
// ========================================================================

idCombatVolume *__fastcall idCombatVolume::Event_AverageHealthInGroup(
        idCombatVolume *this,
        idCombatVolume *result,
        const char *groupName)
{
  idCombatVolumeGroup *Group; // r3
  int v5; // r4

  Group = idCombatVolume::FindGroup(this: result, groupName);
  if ( Group != nullptr )
    v5 = (int)idCombatVolumeGroup::AverageHealth(this: Group);
  else
    v5 = 10;
  eventInt::eventInt((eventInt *)this, i: v5);
  return this;
}


// ========================================================================
// ?Event_HighestHealthInGroup@idCombatVolume@@QBA?AVeventInt@@PBD@Z
// EA  : 0x82D4AEC8
// RVA : 0x00D4AEC8
// PDB : w:\tech5\tungsten\game\entities\volume.cpp
// ========================================================================

idCombatVolume *__fastcall idCombatVolume::Event_HighestHealthInGroup(
        idCombatVolume *this,
        idCombatVolume *result,
        const char *groupName)
{
  idCombatVolumeGroup *Group; // r3
  int v5; // r4

  Group = idCombatVolume::FindGroup(this: result, groupName);
  if ( Group != nullptr )
    v5 = (int)idCombatVolumeGroup::HighestHealth(this: Group);
  else
    v5 = 10;
  eventInt::eventInt((eventInt *)this, i: v5);
  return this;
}


// ========================================================================
// ?Event_LowestHealthInGroup@idCombatVolume@@QBA?AVeventInt@@PBD@Z
// EA  : 0x82D4AF28
// RVA : 0x00D4AF28
// PDB : w:\tech5\tungsten\game\entities\volume.cpp
// ========================================================================

idCombatVolume *__fastcall idCombatVolume::Event_LowestHealthInGroup(
        idCombatVolume *this,
        idCombatVolume *result,
        const char *groupName)
{
  idCombatVolumeGroup *Group; // r3
  int v5; // r4

  Group = idCombatVolume::FindGroup(this: result, groupName);
  if ( Group != nullptr )
    v5 = (int)idCombatVolumeGroup::LowestHealth(this: Group);
  else
    v5 = 10;
  eventInt::eventInt((eventInt *)this, i: v5);
  return this;
}


// ========================================================================
// ?AddGroup@idCombatVolume@@AAAPAVidCombatVolumeGroup@@PBD@Z
// EA  : 0x82D4AF90
// RVA : 0x00D4AF90
// PDB : w:\tech5\tungsten\game\entities\volume.cpp
// ========================================================================

idCombatVolumeGroup *__fastcall idCombatVolume::AddGroup(idCombatVolume *this, const char *groupName)
{
  char v4; // r29
  idCombatVolumeGroup *v5; // r30
  idCombatVolumeGroup *v6; // r30
  encounterGroupRole_t v8[4]; // [sp+50h] [-60h] BYREF
  idStr v9[2]; // [sp+60h] [-50h] BYREF

  v4 = 0;
  v8[0] = ROLE_NONE;
  v5 = (idCombatVolumeGroup *)idMem::AllocWithLocation(
                                this: &mem,
                                location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                size: 0x3Cu,
                                tag: TAG_NEW,
                                zeroBuffer: false,
                                align: ALIGN_16,
                                heap: HEAP_DEFAULTHEAP);
  v8[1] = (encounterGroupRole_t)v5;
  if ( v5 != nullptr )
  {
    idStr::idStr(this: v9, text: groupName);
    v4 = 1;
    v8[0] = ROLE_DEFEND;
    v6 = idCombatVolumeGroup::idCombatVolumeGroup(this: v5, rgn: this, name: v9);
  }
  else
  {
    v6 = nullptr;
  }
  v8[0] = (encounterGroupRole_t)v6;
  if ( (v4 & 1) != 0 )
    idStr::FreeData(this: v9);
  idList<idAnimWebBlendTree *,5>::Append(this: (idList<enum encounterGroupRole_t,5> *)&this->groups, obj: v8);
  return v6;
}


// ========================================================================
// __unwind$497737
// EA  : 0x82D4B048
// RVA : 0x00D4B048
// PDB : w:\tech5\tungsten\game\entities\volume.cpp
// ========================================================================

void __fastcall _unwind_497737(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 176 + 84), tag: a2);
}


// ========================================================================
// __unwind$497739
// EA  : 0x82D4B070
// RVA : 0x00D4B070
// PDB : w:\tech5\tungsten\game\entities\volume.cpp
// ========================================================================

void _unwind_497739()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 176;
  if ( (*(_DWORD *)(v0 - 176 + 80) & 1) != 0 )
  {
    *(_DWORD *)(v1 + 80) &= ~1u;
    idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v1 + 96));
  }
}


// ========================================================================
// ?FindOrAddGroup@idCombatVolume@@AAAPAVidCombatVolumeGroup@@PBD@Z
// EA  : 0x82D4B0B8
// RVA : 0x00D4B0B8
// PDB : w:\tech5\tungsten\game\entities\volume.cpp
// ========================================================================

idCombatVolumeGroup *__fastcall idCombatVolume::FindOrAddGroup(idCombatVolume *this, const char *groupName)
{
  idCombatVolumeGroup *result; // r3

  result = idCombatVolume::FindGroup(this, groupName);
  if ( result == nullptr )
    return idCombatVolume::AddGroup(this, groupName);
  return result;
}


// ========================================================================
// ?Event_Untouch@idCombatVolume@@QAA?AVeventVoid@@PAVidEntity@@H@Z
// EA  : 0x82D4B168
// RVA : 0x00D4B168
// PDB : w:\tech5\tungsten\game\entities\volume.cpp
// ========================================================================

idCombatVolume *__fastcall idCombatVolume::Event_Untouch(
        idCombatVolume *this,
        idCombatVolume *result,
        idAI2 *other,
        int clipModelId)
{
  idActor *v7; // r28
  idCombatVolumeGroup *Group; // r3
  idAI2 *v9; // r3

  v7 = idActor::CastTo(c: other);
  if ( v7 != nullptr )
  {
    if ( idPlayer::CastTo(c: (idPlayer *)other) != nullptr )
    {
      Group = idCombatVolume::FindGroup(this: result, groupName: &byte_8200D768);
    }
    else
    {
      v9 = idAI2::CastTo(c: other);
      if ( v9 == nullptr || v9->aiEditable.groupName.len <= 0 )
        return this;
      Group = idCombatVolume::FindOrAddGroup(this: result, groupName: v9->aiEditable.groupName.data);
    }
    if ( Group != nullptr )
      idCombatVolumeGroup::RemoveActor(this: Group, actor: v7);
  }
  return this;
}


// ========================================================================
// ?AddTouching@idVolume@@QAA_NPAVidEntity@@@Z
// EA  : 0x82D4B200
// RVA : 0x00D4B200
// PDB : w:\tech5\tungsten\game\entities\volume.cpp
// ========================================================================

int __fastcall idVolume::AddTouching(idVolume *this, idEntity *other)
{
  idEntityPtr<idAI2> *v4; // r3
  idEventArg *v5; // r3
  char **SpawnId; // r3
  char v8; // [sp+50h] [-50h] BYREF
  idEventArg v9[3]; // [sp+60h] [-40h] BYREF

  if ( (unsigned __int8)idVolume::IsTouching(this, other) != 0 )
    return 0;
  v4 = idList<idEntityPtr<idAI2>,5>::Alloc(this: (idList<idEntityPtr<idAI2>,5> *)&this->touching);
  if ( other != nullptr )
    v4->spawnId.value = (gameLocal->spawnIds.ptr[other->entityNumber] << 13) | other->entityNumber;
  else
    v4->spawnId.value = 0x1FFF;
  v5 = idEventArg::idEventArg(this: v9, data: other);
  idEventReceiver::PostEventMS(
    this,
    ev: &EV_VolumeMemberAdded,
    time: *(_DWORD *)&v5->type,
    arg1: (const idEventArg *)LODWORD(v5->value.v[1]));
  SpawnId = (char **)idGameLocal::GetSpawnId(this: (idGameLocal *)&v8, result: (idSpawnId *)gameLocal, ent: other);
  idEntity::SendNotify_OnEnter(this, dude: *SpawnId);
  return 1;
}


// ========================================================================
// ?Event_Touch@idVolume_Stairs@@QAA?AVeventVoid@@PAVidEntity@@H@Z
// EA  : 0x82D4B2D0
// RVA : 0x00D4B2D0
// PDB : w:\tech5\tungsten\game\entities\volume.cpp
// ========================================================================

idVolume_Stairs *__fastcall idVolume_Stairs::Event_Touch(
        idVolume_Stairs *this,
        idVolume *result,
        idActor *other,
        int clipModelId)
{
  idActor *v6; // r11
  idVolume_Stairs *v7; // r3

  idVolume::AddTouching(this: result, other);
  v6 = idActor::CastTo(c: other);
  v7 = this;
  if ( v6 != nullptr )
    v6->actorVolatile.onStairs = true;
  return v7;
}


// ========================================================================
// ?Event_Touch@idVolume_DamageMultiplier@@QAA?AVeventVoid@@PAVidEntity@@H@Z
// EA  : 0x82D4B330
// RVA : 0x00D4B330
// PDB : w:\tech5\tungsten\game\entities\volume.cpp
// ========================================================================

idVolume_DamageMultiplier *__fastcall idVolume_DamageMultiplier::Event_Touch(
        idVolume_DamageMultiplier *this,
        idVolume *result,
        idActor *other,
        int clipModelId)
{
  idActor *v7; // r3

  if ( (HIBYTE(result[1].listenerList) != 0 || (unsigned __int8)idPlayer::IsTypeOf(c: other) == 0)
    && (BYTE1(result[1].listenerList) != 0 || (unsigned __int8)idAI2::IsTypeOf(c: other) == 0) )
  {
    idVolume::AddTouching(this: result, other);
    v7 = idActor::CastTo(c: other);
    if ( v7 != nullptr )
      v7->actorVolatile.damageTakenMultiplier = *(float *)&result[1].__vftable;
  }
  return this;
}


// ========================================================================
// ?Event_GatherItems@idVolume_ItemGroup@@QAA?AVeventVoid@@XZ
// EA  : 0x82D4B3B8
// RVA : 0x00D4B3B8
// PDB : w:\tech5\tungsten\game\entities\volume.cpp
// ========================================================================

idVolume_ItemGroup *__fastcall idVolume_ItemGroup::Event_GatherItems(idVolume_ItemGroup *this, idVolume *result)
{
  idPhysics *Physics; // r3
  int v5; // r3
  int EntitiesTouchingBounds; // r31
  idPhysics *v7; // r3
  const idClipModel *v8; // r28
  int *v9; // r30
  int i; // r26
  idEntity *v11; // r31
  idPhysics *v12; // r3
  idList<idEntityPtr<idEntity>,58> *v13; // r3
  int v15[48]; // [sp+50h] [-C0h] BYREF

  Physics = idEntity::GetPhysics(this: result);
  v5 = (int)Physics->GetClipModel(this: Physics, a2: 0);
  EntitiesTouchingBounds = idClip::GetEntitiesTouchingBounds(
                             this: &clientGame->clip,
                             bounds: (const idBounds *)(v5 + 104),
                             clipMask: -1,
                             entityList: v15,
                             maxCount: 32);
  v7 = idEntity::GetPhysics(this: result);
  v8 = v7->GetClipModel(this: v7, a2: 0);
  if ( EntitiesTouchingBounds > 0 )
  {
    v9 = v15;
    for ( i = EntitiesTouchingBounds; i != 0; --i )
    {
      v11 = gameLocal->entities.ptr[*v9];
      if ( (unsigned __int8)idProjectile::IsTypeOf(c: v11) != 0
        || (unsigned __int8)idProp_Moveable::IsTypeOf(c: v11) != 0
        || (unsigned __int8)idVehicle::IsTypeOf(c: v11) != 0 )
      {
        v12 = idEntity::GetPhysics(this: v11);
        if ( v12->ClipContents(this: v12, a2: v8, a3: 0x4000) != 0 )
        {
          if ( v11->GetTriggerTouchList_2(this: v11) != nullptr )
          {
            v13 = (idList<idEntityPtr<idEntity>,58> *)v11->GetTriggerTouchList_2(this: v11);
            idEntity::TouchTrigger(this: v11, touchList: v13, trigger: result, clipModel: v8);
          }
          else
          {
            idVolume::AddTouching(this: result, other: v11);
          }
        }
      }
      ++v9;
    }
  }
  return this;
}


// ========================================================================
// ?Event_Touch@idVolume_EnterExit@@IAA?AVeventVoid@@PAVidEntity@@H@Z
// EA  : 0x82D4B528
// RVA : 0x00D4B528
// PDB : w:\tech5\tungsten\game\entities\volume.cpp
// ========================================================================

idVolume_EnterExit *__fastcall idVolume_EnterExit::Event_Touch(
        idVolume_EnterExit *this,
        idVolume_EnterExit *result,
        idEntity *other,
        int clipModelId)
{
  int num; // r29
  idEventArg *v8; // r3
  idEventArg v10[3]; // [sp+60h] [-40h] BYREF

  if ( (unsigned __int8)idVolume_EnterExit::CanTouch(this: result, toucher: other) != 0 )
  {
    num = result->touching.num;
    if ( (unsigned __int8)idVolume::AddTouching(this: result, other) != 0
      && ((*((_BYTE *)result + 824) & 0x20) != 0 || num == 0)
      && ((*((_BYTE *)result + 824) & 0x10) == 0 || (*((_BYTE *)result + 884) & 0x80) == 0) )
    {
      *((_BYTE *)result + 884) |= 0x80u;
      v8 = idEventArg::idEventArg(this: v10, data: other);
      idEventReceiver::PostEventMS(
        this: result,
        ev: &EV_TriggerEntry,
        time: *(_DWORD *)&v8->type,
        arg1: (const idEventArg *)LODWORD(v8->value.v[1]));
    }
  }
  return this;
}


// ========================================================================
// ?Event_Touch@idVolume_ScenePoints@@QAA?AVeventVoid@@PAVidEntity@@H@Z
// EA  : 0x82D4B610
// RVA : 0x00D4B610
// PDB : w:\tech5\tungsten\game\entities\volume.cpp
// ========================================================================

idVolume_ScenePoints *__fastcall idVolume_ScenePoints::Event_Touch(
        idVolume_ScenePoints *this,
        idVolume_ScenePoints *result,
        idAI2 *other,
        int clipModelId)
{
  int v7; // r10
  int v8; // r9
  int v9; // r8
  int v10; // r7
  int v11; // r6
  int v12; // r5
  idAI2 *v13; // r3
  int v15; // [sp+8h] [-68h]
  int v16; // [sp+Ch] [-64h]
  int v17; // [sp+10h] [-60h]
  int v18; // [sp+14h] [-5Ch]
  int v19; // [sp+18h] [-58h]
  idVolume_ScenePoints *v20; // [sp+1Ch] [-54h]

  if ( (unsigned __int8)idAI2::IsTypeOf(c: other) != 0
    && (*(_BYTE *)&result->flags & 8) != 0
    && (unsigned __int8)idVolume::IsTouching(this: result, other) == 0 )
  {
    idVolume::AddTouching(this: result, other);
    v13 = idAI2::CastTo(c: other);
    if ( v13 != nullptr )
      idAIMemory::AddScenePointVolume(
        this: &v13->aiVolatile.memory,
        spVolume: result,
        a3: v12,
        a4: v11,
        a5: v10,
        a6: v9,
        a7: v8,
        a8: v7,
        a9: v15,
        a10: v16,
        a11: v17,
        a12: v18,
        a13: v19,
        a14: v20);
  }
  return this;
}


// ========================================================================
// ?EnableTouch@idVolume@@IAAXXZ
// EA  : 0x82D4B790
// RVA : 0x00D4B790
// PDB : w:\tech5\tungsten\game\entities\volume.cpp
// ========================================================================

void __fastcall idVolume::EnableTouch(idVolume *this)
{
  idPhysics *Physics; // r3
  idPhysics *v3; // r3
  idPhysics *v4; // r3
  int v5; // r3
  int EntitiesTouchingBounds; // r31
  idPhysics *v7; // r3
  const idClipModel *v8; // r28
  int *v9; // r29
  int i; // r27
  int v11; // r9
  int v12; // r31
  idPhysics *v13; // r3
  idList<idEntityPtr<idEntity>,58> *v14; // r3
  int v15[48]; // [sp+50h] [-C0h] BYREF

  if ( (*((_BYTE *)this + 816) & 0x80) == 0 )
  {
    *((_BYTE *)this + 816) = *((_BYTE *)this + 816) & 0x7F | 0x80;
    Physics = idEntity::GetPhysics(this);
    Physics->SetContents(this: Physics, a2: 0x4000, a3: -1);
    v3 = idEntity::GetPhysics(this);
    v3->EnableClip(this: v3);
    v4 = idEntity::GetPhysics(this);
    v5 = (int)v4->GetClipModel(this: v4, a2: 0);
    EntitiesTouchingBounds = idClip::GetEntitiesTouchingBounds(
                               this: &clientGame->clip,
                               bounds: (const idBounds *)(v5 + 104),
                               clipMask: 99328,
                               entityList: v15,
                               maxCount: 32);
    v7 = idEntity::GetPhysics(this);
    v8 = v7->GetClipModel(this: v7, a2: 0);
    if ( EntitiesTouchingBounds > 0 )
    {
      v9 = v15;
      for ( i = EntitiesTouchingBounds; i != 0; --i )
      {
        v11 = *v9 + 21563;
        v12 = *((_DWORD *)&gameLocal->__vftable + v11);
        if ( (*(_BYTE *)(v12 + 93) & 0x10) != 0 )
        {
          v13 = idEntity::GetPhysics(this: *((idEntity **)&gameLocal->__vftable + v11));
          if ( v13->ClipContents(this: v13, a2: v8, a3: 0x4000) != 0 )
          {
            if ( (*(int (__fastcall **)(int))(*(_DWORD *)v12 + 416))(a1: v12) != 0 )
            {
              v14 = (idList<idEntityPtr<idEntity>,58> *)(*(int (__fastcall **)(int))(*(_DWORD *)v12 + 416))(a1: v12);
              idEntity::TouchTrigger(this: (idEntity *)v12, touchList: v14, trigger: this, clipModel: v8);
            }
            else
            {
              idVolume::AddTouching(this, other: (idEntity *)v12);
            }
          }
        }
        ++v9;
      }
    }
  }
}


// ========================================================================
// ?OnMakeActivatable@idVolume_ForceDormant@@UAAX_N@Z
// EA  : 0x82D4B920
// RVA : 0x00D4B920
// PDB : w:\tech5\tungsten\game\entities\volume.cpp
// ========================================================================

void __fastcall idVolume_ForceDormant::OnMakeActivatable(idVolume_ForceDormant *this, const bool activatable)
{
  if ( activatable )
    idVolume::EnableTouch(this);
  else
    idVolume::DisableTouch(this);
}


// ========================================================================
// ?Event_Touch@idVolume@@QAA?AVeventVoid@@PAVidEntity@@H@Z
// EA  : 0x82D4B938
// RVA : 0x00D4B938
// PDB : w:\tech5\tungsten\game\entities\volume.cpp
// ========================================================================

idVolume *__fastcall idVolume::Event_Touch(idVolume *this, idVolume *result, idEntity *other, int clipModelId)
{
  idVolume::AddTouching(this: result, other);
  return this;
}


// ========================================================================
// ?Event_Touch@idVolume_ShowGui_Leveltransition@@AAA?AVeventVoid@@PAVidEntity@@H@Z
// EA  : 0x82D4B970
// RVA : 0x00D4B970
// PDB : w:\tech5\tungsten\game\entities\volume.cpp
// ========================================================================

idVolume_ShowGui_Leveltransition *__fastcall idVolume_ShowGui_Leveltransition::Event_Touch(
        idVolume_ShowGui_Leveltransition *this,
        idVolume_ShowGui_Leveltransition *result,
        idPlayer *other,
        int clipModelId)
{
  idPlayer *v7; // r28
  idVehicle *v8; // r3
  idVehicle *v9; // r24
  idPlayer *v10; // r25
  bool v11; // r26
  idPlayer *Driver; // r3
  idPlayer *v13; // r29
  int v14; // r30
  idJob *InventoryItemByDeclName; // r3
  idJob *v16; // r3
  missionStatus_t status; // r11
  __int64 v18; // r10
  idStrId v20[24]; // [sp+50h] [-60h] BYREF

  if ( !result->disabledUntilUntouch )
  {
    v7 = idPlayer::CastTo(c: other);
    v8 = idVehicle::CastTo(c: (idVehicle *)other);
    v9 = v8;
    v10 = nullptr;
    v11 = false;
    if ( v8 != nullptr )
    {
      Driver = (idPlayer *)idVehicle::GetDriver(this: v8);
      v10 = idPlayer::CastTo(c: Driver);
      v11 = true;
    }
    v13 = v7;
    if ( v7 == nullptr )
      v13 = v10;
    v14 = 1;
    if ( result->availableJobDecl.len != 0 )
    {
      v14 = 0;
      if ( v13 != nullptr )
      {
        InventoryItemByDeclName = idInventoryCollection::FindInventoryItemByDeclName(
                                    this: &v13->jobManager,
                                    jobName: result->availableJobDecl.data);
        if ( InventoryItemByDeclName != nullptr )
          v14 = InventoryItemByDeclName->status >= result->availableJobStatus;
      }
    }
    if ( (_BYTE)v14 != 0 && result->unAvailableJobDecl.len != 0 && v13 != nullptr )
    {
      v16 = idInventoryCollection::FindInventoryItemByDeclName(
              this: &v13->jobManager,
              jobName: result->unAvailableJobDecl.data);
      if ( v16 != nullptr )
      {
        status = v16->status;
        LODWORD(v18) = result->unAvailableJobStatus;
        HIDWORD(v18) = (unsigned int)status >> 31;
        v14 &= (__PAIR64__((unsigned int)v18 >> 31, status) - v18) >> 32;
      }
    }
    if ( (_BYTE)v14 != 0
      && gameLocal->spawnIds.ptr[result->verifyGarageManager.spawnId.value & 0x1FFF] == result->verifyGarageManager.spawnId.value >> 13 )
    {
      v14 = __CFADD__(
              idEntityPtr<idTownGarageManager>::operator->(this: &result->verifyGarageManager)->vehicles.num - 1,
              -2147483647)
          ? 0
          : v14;
    }
    if ( (_BYTE)v14 != 0 )
    {
      if ( v7 != nullptr && result->showForPlayer )
      {
        v20[0] = result->guiSpecifics.guiString2;
        idPlayer::SetLevelTransitionGuiVolume(this: v7, volume: result, levelName: v20, active: true, inVehicle: v11);
        idVolume::AddTouching(this: result, other);
        return this;
      }
      if ( v9 != nullptr
        && result->showForVehicles
        && v10 != nullptr
        && (!result->requireKeyForVehicle || v9->playerKey != nullptr) )
      {
        v20[0] = result->guiSpecifics.guiString2;
        idPlayer::SetLevelTransitionGuiVolume(this: v10, volume: result, levelName: v20, active: true, inVehicle: v11);
        idVolume::AddTouching(this: result, other);
        return this;
      }
    }
    else if ( result->showIfUnavailable )
    {
      if ( v7 != nullptr && result->showForPlayer )
      {
        v20[0] = result->guiSpecifics.guiString2;
        idPlayer::SetLevelTransitionGuiVolume(this: v7, volume: result, levelName: v20, active: false, inVehicle: v11);
        return this;
      }
      if ( v9 != nullptr
        && result->showForVehicles
        && v10 != nullptr
        && (!result->requireKeyForVehicle || v9->playerKey != nullptr) )
      {
        v20[0] = result->guiSpecifics.guiString2;
        idPlayer::SetLevelTransitionGuiVolume(this: v10, volume: result, levelName: v20, active: false, inVehicle: v11);
        return this;
      }
    }
    if ( v13 != nullptr && v13->levelTransitionGuiVolume == result )
      idPlayer::ClearLevelTransitionGuiVolume(this: v13);
  }
  return this;
}


// ========================================================================
// ?Event_Touch@idVolume_PlayerEnvOverride@@AAA?AVeventVoid@@PAVidEntity@@H@Z
// EA  : 0x82D4BC60
// RVA : 0x00D4BC60
// PDB : w:\tech5\tungsten\game\entities\volume.cpp
// ========================================================================

idVolume_PlayerEnvOverride *__fastcall idVolume_PlayerEnvOverride::Event_Touch(
        idVolume_PlayerEnvOverride *this,
        idVolume *result,
        idPlayer *other,
        int clipModelId)
{
  idPlayer *v7; // r27
  int v8; // r5
  int len; // r10
  char v10; // r31
  __int64 v11; // r9
  idInfo_Trigger_Facing_Target *v12; // r3
  idPresentable *presentable; // r3
  int v14; // r28
  idPresentable *v15; // r3
  int v16; // r31
  int v17; // r9
  idInfo_Trigger_Facing_Target *v18; // r3
  idInfo_Trigger_Facing_Target *v19; // r3
  idPresentable *v20; // r3
  double v21; // fp31
  int v22; // r3
  const idDeclEnv *listeningToList; // r4

  idVolume::AddTouching(this: result, other);
  v7 = idPlayer::CastTo(c: other);
  if ( v7 != nullptr )
  {
    len = result[1].name.len;
    v10 = 1;
    HIDWORD(v11) = (len & 0x1FFF) + 29755;
    if ( *((_DWORD *)&gameLocal->__vftable + HIDWORD(v11)) == len >> 13 )
    {
      v12 = (idInfo_Trigger_Facing_Target *)gameLocal->entities.ptr[len & 0x1FFF];
      if ( v12 != nullptr && idInfo_Trigger_Facing_Target::CastTo(c: v12) != nullptr )
      {
        presentable = v7->presentable;
        if ( presentable != nullptr )
          v14 = (int)presentable->GetPlayerInterface_2(this: presentable);
        else
          v14 = 0;
        v15 = v7->presentable;
        if ( v15 != nullptr )
          v16 = (int)v15->GetPlayerInterface_2(this: v15);
        else
          v16 = 0;
        v17 = result[1].name.len;
        if ( gameLocal->spawnIds.ptr[v17 & 0x1FFF] == v17 >> 13
          && (v18 = (idInfo_Trigger_Facing_Target *)gameLocal->entities.ptr[v17 & 0x1FFF]) != nullptr )
        {
          v19 = idInfo_Trigger_Facing_Target::CastTo(c: v18);
        }
        else
        {
          v19 = nullptr;
        }
        v10 = idInfo_Trigger_Facing_Target::CheckIsFacing(
                this: v19,
                viewDir: (const idVec3 *)(v16 + 46544),
                viewPos: (const idVec3 *)(v14 + 46532));
      }
    }
    v20 = v7->presentable;
    if ( v10 != 0 )
    {
      LODWORD(v11) = result[1].__vftable;
      v21 = (float)((float)v11 * 0.001);
      if ( v20 != nullptr )
      {
        v22 = (int)v20->GetPlayerInterface_2(this: v20);
        listeningToList = (const idDeclEnv *)result[1].listeningToList;
      }
      else
      {
        listeningToList = (const idDeclEnv *)result[1].listeningToList;
        v22 = 0;
      }
    }
    else
    {
      LODWORD(v11) = result[1].listenerList;
      v21 = (float)((float)v11 * 0.001);
      if ( v20 != nullptr )
        v22 = (int)v20->GetPlayerInterface_2(this: v20);
      else
        v22 = 0;
      listeningToList = nullptr;
    }
    idView::SetEnvironmentOverride(
      this: (idView *)(v22 + 16224),
      env: listeningToList,
      blendDuration: v21,
      modelIndex: v8);
  }
  return this;
}


// ========================================================================
// ?Event_Touch@idCombatVolume@@QAA?AVeventVoid@@PAVidEntity@@H@Z
// EA  : 0x82D4BE58
// RVA : 0x00D4BE58
// PDB : w:\tech5\tungsten\game\entities\volume.cpp
// ========================================================================

idCombatVolume *__fastcall idCombatVolume::Event_Touch(
        idCombatVolume *this,
        idCombatVolume *result,
        idAI2 *other,
        int clipModelId)
{
  idActor *v7; // r3
  idActor *v8; // r30
  int v9; // r3
  idCombatVolumeGroup *Group; // r3
  idAI2 *v11; // r3

  v7 = idActor::CastTo(c: other);
  v8 = v7;
  if ( v7 != nullptr )
  {
    v9 = (int)v7->GetHealthComponent_2(this: v7);
    if ( v9 != 0 && (*(unsigned __int8 (__fastcall **)(int))(*(_DWORD *)v9 + 88))(a1: v9) == 0 )
    {
      if ( idPlayer::CastTo(c: (idPlayer *)other) != nullptr )
      {
        Group = idCombatVolume::FindGroup(this: result, groupName: &byte_8200D768);
      }
      else
      {
        v11 = idAI2::CastTo(c: other);
        if ( v11 == nullptr || v11->aiEditable.groupName.len <= 0 )
          return this;
        Group = idCombatVolume::FindOrAddGroup(this: result, groupName: v11->aiEditable.groupName.data);
      }
      if ( Group != nullptr )
        idCombatVolumeGroup::AddActor(this: Group, actor: v8);
    }
  }
  return this;
}


// ========================================================================
// ?Event_Touch@idVolume_DynamicJob@@QAA?AVeventVoid@@PAVidEntity@@H@Z
// EA  : 0x82D4BF28
// RVA : 0x00D4BF28
// PDB : w:\tech5\tungsten\game\entities\volume.cpp
// ========================================================================

idVolume_DynamicJob *__fastcall idVolume_DynamicJob::Event_Touch(
        idVolume_DynamicJob *this,
        idVolume *result,
        idEntity *other,
        int clipModelId)
{
  idPlayer *PlayerFromEntity; // r3
  const idDeclJob *v8; // r4
  int v9; // r29
  int v10; // r30
  idEntityPtr<idEntity> *v11; // r3
  idEntity *v12; // r3
  int len; // r11
  int v15; // r30
  idEntityPtr<idEntity> *v16; // r3
  idEntity *v17; // r3

  if ( (unsigned __int8)idVolume::IsTouching(this: result, other) != 0 )
    return this;
  idVolume::AddTouching(this: result, other);
  if ( HIBYTE(result[1].listenerList) == 0 )
    return this;
  PlayerFromEntity = idGameLocal::GetPlayerFromEntity(this: gameLocal, activator: other);
  if ( PlayerFromEntity == nullptr )
    return this;
  v8 = (const idDeclJob *)result[1].__vftable;
  if ( v8 == nullptr )
    return this;
  idPlayer::OfferDynamicJob(this: PlayerFromEntity, job: v8);
  v9 = 0;
  if ( HIBYTE(result[1].spawnOrientation.mat[0].x) == 0 )
  {
    len = result[1].name.len;
    HIBYTE(result[1].spawnOrientation.mat[0].x) = 1;
    if ( len > 0 )
    {
      v15 = 0;
      do
      {
        v16 = (idEntityPtr<idEntity> *)((char *)result[1].listeningToList + v15);
        if ( gameLocal->spawnIds.ptr[v16->spawnId.value & 0x1FFF] == v16->spawnId.value >> 13 )
        {
          v17 = idEntityPtr<idEntity const>::operator->(this: v16);
          idEntity::Activate(this: v17, activator: other);
        }
        ++v9;
        v15 += 4;
      }
      while ( v9 < result[1].name.len );
    }
    return this;
  }
  if ( SLODWORD(result[1].spawnPosition.x) <= 0 )
    return this;
  v10 = 0;
  do
  {
    v11 = (idEntityPtr<idEntity> *)(v10 + *(_DWORD *)&result[1].name.baseBuffer[16]);
    if ( gameLocal->spawnIds.ptr[v11->spawnId.value & 0x1FFF] == v11->spawnId.value >> 13 )
    {
      v12 = idEntityPtr<idEntity const>::operator->(this: v11);
      idEntity::Activate(this: v12, activator: other);
    }
    ++v9;
    v10 += 4;
  }
  while ( v9 < SLODWORD(result[1].spawnPosition.x) );
  return this;
}


// ========================================================================
// ?OnActivate@idVolume_KillDownedInjured@@UAAXPAVidEntity@@@Z
// EA  : 0x82D4C080
// RVA : 0x00D4C080
// PDB : w:\tech5\tungsten\game\entities\volume.cpp
// ========================================================================

void __fastcall idVolume_KillDownedInjured::OnActivate(idVolume_LocationCalling *this, idEntity *activator)
{
  idPhysics *Physics; // r3

  Physics = idEntity::GetPhysics(this);
  if ( Physics->GetClipModel(this: Physics, a2: 0)->enabled )
    idVolume::DisableTouch(this);
  else
    idVolume::EnableTouch(this);
}


// ========================================================================
// ?Event_Touch@idVolume_ForceDormant@@QAA?AVeventVoid@@PAVidEntity@@H@Z
// EA  : 0x82D4C0F0
// RVA : 0x00D4C0F0
// PDB : w:\tech5\tungsten\game\entities\volume.cpp
// ========================================================================

idVolume_ForceDormant *__fastcall idVolume_ForceDormant::Event_Touch(
        idVolume_ForceDormant *this,
        idVolume *result,
        idPlayer *other,
        int clipModelId)
{
  idVolume::AddTouching(this: result, other);
  if ( (result->thinkFlags & 1) == 0 && idPlayer::CastTo(c: other) != nullptr )
    idEntity::BecomeActive(this: result, flags: 1);
  return this;
}


// ========================================================================
// ?Event_Touch@idVolume_PlayerInteraction@@QAA?AVeventVoid@@PAVidEntity@@H@Z
// EA  : 0x82D4C150
// RVA : 0x00D4C150
// PDB : w:\tech5\tungsten\game\entities\volume.cpp
// ========================================================================

idVolume_PlayerInteraction *__fastcall idVolume_PlayerInteraction::Event_Touch(
        idVolume_PlayerInteraction *this,
        idVolume *result,
        idEntity *other,
        int clipModelId)
{
  int v7; // r11
  char v8; // r11
  bool v9; // zf

  v7 = *(_DWORD *)(other->GetType(this: other) + 36);
  if ( v7 < idPlayer::Type.typeNum || (v9 = v7 <= idPlayer::Type.lastChild, v8 = 1, !v9) )
    v8 = 0;
  if ( v8 != 0 )
  {
    idVolume::AddTouching(this: result, other);
    idEntity::BecomeActive(this: result, flags: 1);
  }
  return this;
}


// ========================================================================
// ?OnMakeActivatable@idVolume_ScenePoints@@UAAX_N@Z
// EA  : 0x82D4C1D8
// RVA : 0x00D4C1D8
// PDB : w:\tech5\tungsten\game\entities\volume.cpp
// ========================================================================

void __fastcall idVolume_ScenePoints::OnMakeActivatable(idVolume_ScenePoints *this, bool activatable)
{
  BOOL v2; // r31
  int num; // r22
  int v5; // r29
  int value; // r9
  idEntity *v7; // r3
  idAI2 *v8; // r3
  idAI2 *v9; // r3
  idAI2 *v10; // r31

  v2 = activatable;
  if ( activatable )
    idVolume::EnableTouch(this);
  else
    idVolume::DisableTouch(this);
  if ( !v2 && this->touching.num > 0 )
  {
    num = this->touching.num;
    v5 = 0;
    do
    {
      value = this->touching.list[v5].spawnId.value;
      if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
        && (v7 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
      {
        v8 = (idAI2 *)idEntity::CastTo(c: v7);
      }
      else
      {
        v8 = nullptr;
      }
      v9 = idAI2::CastTo(c: v8);
      v10 = v9;
      if ( v9 != nullptr )
      {
        idAIMemory::RemoveScenePointVolume(this: &v9->aiVolatile.memory, spVolume: this);
        if ( v10->aiVolatile.memory.curScenePoint != nullptr )
          v10->aiVolatile.memory.curScenePointDirty = true;
        if ( v10->aiVolatile.memory.curLookScenePoint != nullptr )
          v10->aiVolatile.memory.curLookScenePointDirty = true;
      }
      --num;
      ++v5;
    }
    while ( num != 0 );
  }
}


// ========================================================================
// ?GetScenePoints@idVolume_ScenePoints@@UAAXAAV?$idList@V?$idEntityPtr@VidScenePoint@@@@$04@@W4scenePointType_t@@V?$idEntityPtr@VidVolume_Restriction@@@@V?$idEntityPtr@VidScenePoint_UserGroup@@@@@Z
// EA  : 0x82D4C2E8
// RVA : 0x00D4C2E8
// PDB : w:\tech5\tungsten\game\entities\volume.cpp
// ========================================================================

void __fastcall idVolume_ScenePoints::GetScenePoints(
        idVolume_ScenePoints *this,
        idList<idEntityPtr<idAI2>,5> *spList,
        scenePointType_t spType,
        idEntityPtr<idVolume_Restriction> *restrictionVolume,
        idEntityPtr<idScenePoint_UserGroup> *scenePointUserGroup,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        idEntityPtr<idVolume_Restriction> a18,
        int a19,
        idEntityPtr<idScenePoint_UserGroup> a20)
{
  int num; // r26
  int v24; // r27
  int v25; // r29
  int value; // r9
  idEntity *v27; // r3
  idScenePoint *v28; // r3
  idScenePoint *v29; // r3
  idScenePoint *v30; // r31
  idScenePoint *ScenePointPos; // r23
  idVolume_Restriction *v32; // r3
  idScenePoint_UserGroup *v33; // r23
  bool v34; // cr58
  idEntityPtr<idScenePoint_UserGroup> v35[2]; // [sp+50h] [-70h] BYREF
  char v36; // [sp+58h] [-68h] BYREF

  num = this->targets.num;
  a18.spawnId.value = (int)restrictionVolume;
  a20.spawnId.value = (int)scenePointUserGroup;
  if ( num > 0 && (*(_BYTE *)&this->flags & 8) != 0 )
  {
    v24 = 0;
    v25 = 0;
    do
    {
      if ( v24 < this->targets.num
        && (value = this->targets.list[v25].spawnId.value, gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13)
        && (v27 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
      {
        v28 = (idScenePoint *)idEntity::CastTo(c: v27);
      }
      else
      {
        v28 = nullptr;
      }
      v29 = idScenePoint::CastTo(c: v28);
      v30 = v29;
      if ( v29 != nullptr && v29->type == spType && (v29->scriptFlags & 1) == 0 )
      {
        if ( idEntityPtr<idVolume_Restriction>::operator idVolume_Restriction *(this: &a18) == nullptr
          || (*(_BYTE *)&idEntityPtr<idVolume_Restriction>::operator idVolume_Restriction *(this: &a18)->flags & 8) == 0
          || (ScenePointPos = idScenePoint::GetScenePointPos(this: (idScenePoint *)&v36, result: v30),
              v32 = idEntityPtr<idVolume_Restriction>::operator idVolume_Restriction *(this: &a18),
              (unsigned __int8)idVolume_ItemGroup::Contains(this: v32, pos: (const idVec3 *)ScenePointPos) != 0) )
        {
          if ( idEntityPtr<idScenePoint_UserGroup>::operator idScenePoint_UserGroup *(this: &a20) != nullptr )
          {
            v35[0] = v30->userGroup;
            v33 = idEntityPtr<idScenePoint_UserGroup>::operator idScenePoint_UserGroup *(this: v35);
            v34 = v33 == idEntityPtr<idScenePoint_UserGroup>::operator idScenePoint_UserGroup *(this: &a20);
          }
          else
          {
            v34 = !idScenePoint::HasScenePointUserGroup(this: v30);
          }
          if ( v34 )
          {
            v35[0].spawnId.value = (gameLocal->spawnIds.ptr[v30->entityNumber] << 13) | v30->entityNumber;
            idList<idEntityPtr<idEntity>,5>::AddUnique(this: spList, obj: (const idEntityPtr<idEntity> *)v35);
          }
        }
      }
      ++v24;
      ++v25;
    }
    while ( v24 < num );
  }
}


// ========================================================================
// ?Spawn@idVolume@@QAAXXZ
// EA  : 0x82D4C498
// RVA : 0x00D4C498
// PDB : w:\tech5\tungsten\game\entities\volume.cpp
// ========================================================================

void __fastcall idVolume::Spawn(idVolume *this)
{
  idPhysics *Physics; // r3
  idPhysics *v3; // r3

  if ( this->startEnabled )
  {
    idVolume::EnableTouch(this);
  }
  else
  {
    Physics = idEntity::GetPhysics(this);
    Physics->SetContents(this: Physics, a2: 0, a3: -1);
    v3 = idEntity::GetPhysics(this);
    v3->DisableClip(this: v3);
  }
}


// ========================================================================
// `dynamic initializer for 'g_VolumeDebug''
// EA  : 0x8337FEC8
// RVA : 0x0137FEC8
// PDB : w:\tech5\tungsten\game\entities\volume.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_VolumeDebug__()
{
  idCVar::idCVar(
    this: &g_VolumeDebug,
    name: "g_VolumeDebug",
    value: "0",
    flags: 1,
    description: "used for debugging volumes",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_VolumeDebug__);
}

