
// ========================================================================
// ?Collide@idVehicleOccupantPhysicsCallbacks@@UAA?AW4collide_t@@HAAUtrace_t@@ABVidVec3@@@Z
// EA  : 0x82D31F18
// RVA : 0x00D31F18
// PDB : w:\tech5\tungsten\game\entities\vehicleoccupants.cpp
// ========================================================================

collide_t __fastcall idVehicleOccupantPhysicsCallbacks::Collide(
        idVehicleOccupantPhysicsCallbacks *this,
        int physId,
        trace_t *collision,
        const idVec3 *velocity)
{
  idVehicleOccupant *occupant; // r11

  occupant = this->occupant;
  if ( occupant != nullptr )
    return ((collide_t (*)(void))occupant->Collide)();
  else
    return idAnimator_AF::Collide(this: this->af, physId, collision, velocity);
}


// ========================================================================
// ??1idVehicleOccupant@@UAA@XZ
// EA  : 0x82D31F48
// RVA : 0x00D31F48
// PDB : w:\tech5\tungsten\game\entities\vehicleoccupants.cpp
// ========================================================================

void __fastcall idVehicleOccupant::~idVehicleOccupant(idVehicleOccupant *this)
{
  idTreeAnimator *TreeAnimatorFromPresentable; // r5

  this->__vftable = (idVehicleOccupant_vtbl *)&idVehicleOccupant::`vftable';
  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
  if ( TreeAnimatorFromPresentable != nullptr )
    idFaceMgr::Shutdown(this: &this->faceMgr, owner: this, ta: TreeAnimatorFromPresentable);
  idAnimator_AF::~idAnimator_AF(this: &this->afProperties);
  idFaceMgr::~idFaceMgr(this: &this->faceMgr);
  idAnimatedEntity::~idAnimatedEntity(this);
}


// ========================================================================
// __unwind$490776_0
// EA  : 0x82D31FC0
// RVA : 0x00D31FC0
// PDB : w:\tech5\tungsten\game\entities\vehicleoccupants.cpp
// ========================================================================

void _unwind_490776_0()
{
  int v0; // r12

  idAnimatedEntity::~idAnimatedEntity(this: *(idAnimatedEntity **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$490777_0
// EA  : 0x82D31FE8
// RVA : 0x00D31FE8
// PDB : w:\tech5\tungsten\game\entities\vehicleoccupants.cpp
// ========================================================================

void _unwind_490777_0()
{
  int v0; // r12

  idFaceMgr::~idFaceMgr(this: (idFaceMgr *)(*(_DWORD *)(v0 - 112 + 132) + 5204));
}


// ========================================================================
// __unwind$490778_0
// EA  : 0x82D32014
// RVA : 0x00D32014
// PDB : w:\tech5\tungsten\game\entities\vehicleoccupants.cpp
// ========================================================================

void _unwind_490778_0()
{
  int v0; // r12

  idAnimator_AF::~idAnimator_AF(this: (idAnimator_AF *)(*(_DWORD *)(v0 - 112 + 132) + 7208));
}


// ========================================================================
// ?AllocPresentable@idVehicleOccupant@@UAAPAVidPresentable@@PAVidRenderModel@@@Z
// EA  : 0x82D32048
// RVA : 0x00D32048
// PDB : w:\tech5\tungsten\game\entities\vehicleoccupants.cpp
// ========================================================================

idPresentableAnimatedEntity *__fastcall idVehicleOccupant::AllocPresentable(
        idVehicleOccupant *this,
        idTreeAnimator *renderModel)
{
  _DWORD *v4; // r3
  int v5; // r3
  char v6; // r11
  bool v7; // r28
  idPresentableAnimatedEntity *v8; // r29
  int entityNumber; // r26
  const idDeclFX *v10; // r25
  idAnimStack *v11; // r3
  int v13; // [sp+50h] [-50h]

  v4 = _RTDynamicCast(
         inptr: renderModel,
         VfDelta: 0,
         SrcType: &idRenderModel `RTTI Type Descriptor',
         TargetType: &idTreeAnimator `RTTI Type Descriptor',
         isReference: 0);
  if ( v4 == nullptr
    || (v13 = v4[508]) == 0
    || v13 == -144
    || (v5 = idJointGroupCollection::NumJointGroupsForType(this: (idJointGroupCollection *)(v13 + 144), type: 8),
        v6 = 1,
        v5 <= 0) )
  {
    v6 = 0;
  }
  v7 = v6;
  v8 = (idPresentableAnimatedEntity *)idMem::AllocWithLocation(
                                        this: &mem,
                                        location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                        size: 0x4E0u,
                                        tag: TAG_PRESENTABLE,
                                        zeroBuffer: false,
                                        align: ALIGN_16,
                                        heap: HEAP_DEFAULTHEAP);
  if ( v8 == nullptr )
    return nullptr;
  entityNumber = this->entityNumber;
  v10 = this->GetFXDecl(this);
  v11 = this->GetAnimStack_2(this);
  return idPresentableAnimatedEntity::idPresentableAnimatedEntity(
           this: v8,
           ent: this,
           renderModel_: renderModel,
           animStack_: v11,
           entityNumber_: entityNumber,
           fxDecl_: v10,
           useSphereModel_: v7);
}


// ========================================================================
// __unwind$491050
// EA  : 0x82D32160
// RVA : 0x00D32160
// PDB : w:\tech5\tungsten\game\entities\vehicleoccupants.cpp
// ========================================================================

void _unwind_491050()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 160 + 80), tag: TAG_PRESENTABLE);
}


// ========================================================================
// ?Spawn@idVehicleOccupant@@QAAXXZ
// EA  : 0x82D32190
// RVA : 0x00D32190
// PDB : w:\tech5\tungsten\game\entities\vehicleoccupants.cpp
// ========================================================================

void __fastcall idVehicleOccupant::Spawn(idVehicleOccupant *this)
{
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idPresentable *presentable; // r11
  idTreeAnimator *v4; // r29
  idPhysics *Physics; // r3
  idPhysics *v6; // r3
  idBounds *v7; // r3
  bool v8; // [sp+Bh] [-85h]
  bool v9; // [sp+Fh] [-81h]
  bool v10; // [sp+13h] [-7Dh]
  bool v11; // [sp+17h] [-79h]
  int v12; // [sp+18h] [-78h]
  int v13; // [sp+1Ch] [-74h]
  int v14; // [sp+20h] [-70h]
  int v15; // [sp+24h] [-6Ch]
  int v16; // [sp+28h] [-68h]
  int v17; // [sp+2Ch] [-64h]
  int v18; // [sp+30h] [-60h]
  int v19; // [sp+34h] [-5Ch]
  int v20; // [sp+38h] [-58h]
  int v21; // [sp+3Ch] [-54h]
  int v22; // [sp+40h] [-50h]
  int v23; // [sp+44h] [-4Ch]
  int v24; // [sp+48h] [-48h]
  int v25; // [sp+4Ch] [-44h]
  int v26; // [sp+50h] [-40h]
  int v27; // [sp+58h] [-38h]
  int v28; // [sp+60h] [-30h]
  int v29; // [sp+68h] [-28h]

  this->InternalInitAnimation(this);
  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
  presentable = this->presentable;
  v4 = TreeAnimatorFromPresentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    presentable = this->presentable;
  }
  idPresentable::UpdateModelTransform(this: presentable);
  if ( v4 != nullptr )
  {
    if ( this->usesFaceManager )
      idFaceMgr::Init(
        this: &this->faceMgr,
        owner: this,
        ta: v4,
        mood: MOOD_NONE,
        voiceChannel: SND_CHANNEL_VOICE,
        enableMoodAnimation: true,
        enableLipSyncAnimation: true,
        enableGestureAnimation: true,
        enableEyeTracking: v8,
        useFaceSetupEyeTracking_: v9,
        enableBlinking: v10,
        enableLidDeformation: v11,
        a13: v12,
        a14: v13,
        a15: v14,
        a16: v15,
        a17: v16,
        a18: v17,
        a19: v18,
        a20: v19,
        a21: v20,
        a22: v21,
        a23: v22,
        a24: v23,
        a25: v24,
        a26: v25,
        a27: v26,
        a28: 1,
        a29: v27,
        a30: false,
        a31: v28,
        a32: 1u,
        a33: v29,
        a34: 1);
    v4->useDeferredPosition = false;
  }
  this->Hide_2(this);
  Physics = idEntity::GetPhysics(this);
  Physics->SetContents(this: Physics, a2: 128, a3: -1);
  *(_BYTE *)&this->flags |= 0x40u;
  v6 = idEntity::GetPhysics(this);
  v7 = (idBounds *)v6->GetAbsBounds(this: v6, a2: -1);
  idEntity::UpdatePVSAreas(this, bounds: v7);
}


// ========================================================================
// ?StartThrow@idVehicleOccupant@@QAAXPAVidPlayer@@@Z
// EA  : 0x82D322A0
// RVA : 0x00D322A0
// PDB : w:\tech5\tungsten\game\entities\vehicleoccupants.cpp
// ========================================================================

void __fastcall idVehicleOccupant::StartThrow(idVehicleOccupant *this, idPlayer *player)
{
  const idDeclPlayerProps::playerSounds_t *PlayerSounds; // r3
  _BYTE v4[208]; // [sp+50h] [-E0h] BYREF

  this->linkedPlayer = player;
  if ( player != nullptr
    && idPlayer::GetPlayerSounds(this: (idPlayer *)v4, result: (const idDeclPlayerProps::playerSounds_t *)player)->sndThrown != nullptr )
  {
    PlayerSounds = idPlayer::GetPlayerSounds(
                     this: (idPlayer *)v4,
                     result: (const idDeclPlayerProps::playerSounds_t *)this->linkedPlayer);
    idEntity::StartSoundShader(
      this: this->linkedPlayer,
      channel: SND_CHANNEL_THROW_ACTOR,
      shader: PlayerSounds->sndThrown,
      soundShaderFlags: SSF_LOOPING,
      peerMask: 0);
  }
  this->vehicleOccupantPhysicsCallbacks.occupant = this;
  this->thrown = true;
  this->timeStartThrown = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
}


// ========================================================================
// ?StopThrow@idVehicleOccupant@@QAAXXZ
// EA  : 0x82D32338
// RVA : 0x00D32338
// PDB : w:\tech5\tungsten\game\entities\vehicleoccupants.cpp
// ========================================================================

void __fastcall idVehicleOccupant::StopThrow(idVehicleOccupant *this)
{
  idPlayer *linkedPlayer; // r4
  char v3; // [sp+50h] [-E0h] BYREF

  linkedPlayer = this->linkedPlayer;
  if ( linkedPlayer != nullptr
    && idPlayer::GetPlayerSounds(this: (idPlayer *)&v3, result: (const idDeclPlayerProps::playerSounds_t *)linkedPlayer)->sndThrown != nullptr )
  {
    idEntity::StopSound(this: this->linkedPlayer, channel: SND_CHANNEL_THROW_ACTOR, peerMask: 0xFFu);
  }
  this->vehicleOccupantPhysicsCallbacks.occupant = nullptr;
  this->thrown = false;
  this->timeStartThrown = 0;
}


// ========================================================================
// ?GetModelTransform@idVehicleOccupant@@UBAXAAVidVec3@@AAVidMat3@@@Z
// EA  : 0x82D323A0
// RVA : 0x00D323A0
// PDB : w:\tech5\tungsten\game\entities\vehicleoccupants.cpp
// ========================================================================

void __fastcall idVehicleOccupant::GetModelTransform(idVehicleOccupant *this, idVec3 *modelOrigin, idMat3 *modelAxis)
{
  idPhysics *Physics; // r3
  float *v7; // r3
  idPhysics *v8; // r3
  float *v9; // r3
  idQuat v10; // [sp+50h] [-50h] BYREF

  if ( idAnimatedEntity::GetTreeAnimatorFromPresentable(this) != nullptr
    && this->tagAnimator != nullptr
    && this->tagData.parentJoint.value != 0xFFFF )
  {
    *modelAxis = *idQuat::ToMat3(this: &v10, result: (idMat3 *)&this->tagData.rot);
    modelOrigin->x = this->tagData.trans.x;
    modelOrigin->y = this->tagData.trans.y;
    modelOrigin->z = this->tagData.trans.z;
  }
  else
  {
    Physics = idEntity::GetPhysics(this);
    v7 = (float *)Physics->GetAxis(this: Physics, a2: 0);
    modelAxis->mat[0].x = *v7;
    modelAxis->mat[0].y = v7[1];
    modelAxis->mat[0].z = v7[2];
    modelAxis->mat[1].x = v7[3];
    modelAxis->mat[1].y = v7[4];
    modelAxis->mat[1].z = v7[5];
    modelAxis->mat[2].x = v7[6];
    modelAxis->mat[2].y = v7[7];
    modelAxis->mat[2].z = v7[8];
    v8 = idEntity::GetPhysics(this);
    v9 = (float *)v8->GetOrigin(this: v8, a2: 0);
    modelOrigin->x = *v9;
    modelOrigin->y = v9[1];
    modelOrigin->z = v9[2];
  }
}


// ========================================================================
// ?PlayVoiceOver@idVehicleOccupant@@QAA_NPBVidDeclVoiceOver@@VidStrId@@@Z
// EA  : 0x82D324F8
// RVA : 0x00D324F8
// PDB : w:\tech5\tungsten\game\entities\vehicleoccupants.cpp
// ========================================================================

int __fastcall idVehicleOccupant::PlayVoiceOver(
        idVehicleOccupant *this,
        const idDeclVoiceOver *vo,
        idStrId *whoStartedMeTextId)
{
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  int index; // r11
  idSoundShader *lastSoundShader; // r30
  int GameMs; // r29
  double v10; // fp31
  __int64 v11; // r5

  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
  if ( (unsigned __int8)idFaceMgr::StartVoiceOver(
                          this: &this->faceMgr,
                          owner: (idAI2 *)this,
                          ta: TreeAnimatorFromPresentable,
                          vo) == 0 )
    return 0;
  index = whoStartedMeTextId->index;
  lastSoundShader = this->faceMgr.lastSoundShader;
  this->subtitleName.index = index;
  if ( lastSoundShader == nullptr )
    return 0;
  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  v10 = (float)((float)__SPAIR64__(&off_82040000, gameLocal->GetGameMsPerRealSec(this: gameLocal)) * (float)0.001);
  LODWORD(v11) = idSoundShader::GetMaxLength(this: lastSoundShader);
  this->nextVoiceTime = (int)(float)((float)v11 * (float)v10) + GameMs;
  return 1;
}


// ========================================================================
// ?IsVoiceOverPlaying@idVehicleOccupant@@QBA_NXZ
// EA  : 0x82D325F8
// RVA : 0x00D325F8
// PDB : w:\tech5\tungsten\game\entities\vehicleoccupants.cpp
// ========================================================================

int __fastcall idVehicleOccupant::IsVoiceOverPlaying(idVehicleOccupant *this)
{
  unsigned int GameMs; // r3

  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  return ((((this->nextVoiceTime ^ GameMs) & 0x80000000) == 0) + (GameMs >= this->nextVoiceTime)) & 1;
}


// ========================================================================
// ?Damage@idVehicleOccupant@@UAAMPAVidEntity@@0PBVidDeclDamage@@MABVidVec3@@PAUtrace_t@@@Z
// EA  : 0x82D32650
// RVA : 0x00D32650
// PDB : w:\tech5\tungsten\game\entities\vehicleoccupants.cpp
// ========================================================================

float __fastcall idVehicleOccupant::Damage(
        idVehicleOccupant *this,
        idEntity *inflictor,
        idEntity *attacker,
        const idDeclDamage *damageDef,
        double damageScale,
        const idVec3 *dir,
        trace_t *trace,
        int a8)
{
  idPhysics *Physics; // r3
  idPhysics *v13; // r3
  double v14; // fp1

  if ( this->TakesDamage(this) && damageDef != nullptr && a8 == 0 )
  {
    if ( inflictor != nullptr )
    {
      Physics = idEntity::GetPhysics(this: inflictor);
      Physics->GetOrigin(this: Physics, a2: 0);
    }
    else
    {
      v13 = idEntity::GetPhysics(this);
      v13->GetAbsBounds(this: v13, a2: -1);
    }
  }
  v14 = 0.0;
  return *((float *)&v14 + 1);
}


// ========================================================================
// ?GetVisibilityPoint@idVehicleOccupant@@UBAXW4visPoint_t@@AAVidVec3@@@Z
// EA  : 0x82D326E8
// RVA : 0x00D326E8
// PDB : w:\tech5\tungsten\game\entities\vehicleoccupants.cpp
// ========================================================================

void __fastcall idVehicleOccupant::GetVisibilityPoint(idVehicleOccupant *this, const visPoint_t type, idVec3 *pos)
{
  char v4; // r11
  const idVec3 *v5; // r3
  idPhysics *Physics; // r3

  if ( this->afProperties.isActive || (v4 = 0, this->afProperties.isClientAuthoritativeActive) )
    v4 = 1;
  if ( v4 == 0 || this == (idVehicleOccupant *)-7496 )
  {
    Physics = idEntity::GetPhysics(this);
    v5 = Physics->GetOrigin(this: Physics, a2: 0);
  }
  else
  {
    v5 = this->afProperties.physicsObj.GetOrigin(this: &this->afProperties.physicsObj, a2: 0);
  }
  pos->x = v5->x;
  pos->y = v5->y;
  pos->z = v5->z;
}


// ========================================================================
// ?AnimEvent_Occupant_SetLookPoint@idVehicleOccupant@@QAA?AVeventVoid@@PBVidMD6Anim@@ABVidVec3@@@Z
// EA  : 0x82D32788
// RVA : 0x00D32788
// PDB : w:\tech5\tungsten\game\entities\vehicleoccupants.cpp
// ========================================================================

idVehicleOccupant *__fastcall idVehicleOccupant::AnimEvent_Occupant_SetLookPoint(
        idVehicleOccupant *this,
        eventVoid *result,
        const idMD6Anim *animHandle,
        const idVec3 *point)
{
  (*(void (__fastcall **)(eventVoid *, const idVec3 *, int))(*(_DWORD *)result + 684))(a1: result, a2: point, a3: 500);
  return this;
}


// ========================================================================
// ?AnimEvent_Occupant_SetLookEntity@idVehicleOccupant@@QAA?AVeventVoid@@PBVidMD6Anim@@PBDW4aimPoint_t@@@Z
// EA  : 0x82D327E0
// RVA : 0x00D327E0
// PDB : w:\tech5\tungsten\game\entities\vehicleoccupants.cpp
// ========================================================================

idVehicleOccupant *__fastcall idVehicleOccupant::AnimEvent_Occupant_SetLookEntity(
        idVehicleOccupant *this,
        idEntity *result,
        const idMD6Anim *animHandle,
        const char *entityName,
        aimPoint_t aimPoint)
{
  idEntity *v9; // r4
  idStr v11[2]; // [sp+50h] [-50h] BYREF

  v11[0].len = 0;
  v11[0].allocedAndFlag = 20;
  v11[0].data = v11[0].baseBuffer;
  v11[0].baseBuffer[0] = 0;
  v9 = gameLocal->FindEntityForName(this: gameLocal, a2: entityName, a3: result, a4: 0, a5: v11);
  if ( v9 != nullptr )
  {
    ((void (__fastcall *)(idEntity *, idEntity *, const aimPoint_t, int))result->__vftable[1].DormantEnd)(
      a1: result,
      a2: v9,
      a3: aimPoint,
      a4: 500);
  }
  else
  {
    idLib::Warning(fmt: "AnimEvent_Occupant_SetLookEntity: could not find entity '%s'", entityName);
    ((void (__fastcall *)(idEntity *, int))result->__vftable[1].ShouldEnterDormancy)(a1: result, a2: 500);
  }
  idStr::FreeData(this: v11);
  return this;
}


// ========================================================================
// __unwind$491394
// EA  : 0x82D328AC
// RVA : 0x00D328AC
// PDB : w:\tech5\tungsten\game\entities\vehicleoccupants.cpp
// ========================================================================

void _unwind_491394()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 160 + 80));
}


// ========================================================================
// ?AnimEvent_Occupant_ClearLook@idVehicleOccupant@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA  : 0x82D328D8
// RVA : 0x00D328D8
// PDB : w:\tech5\tungsten\game\entities\vehicleoccupants.cpp
// ========================================================================

idVehicleOccupant *__fastcall idVehicleOccupant::AnimEvent_Occupant_ClearLook(
        idVehicleOccupant *this,
        eventVoid *result,
        const idMD6Anim *animHandle)
{
  (*(void (__fastcall **)(eventVoid *, int, const idMD6Anim *))(*(_DWORD *)result + 680))(
    a1: result,
    a2: 500,
    a3: animHandle);
  return this;
}


// ========================================================================
// ?Damage@idVehicleOccupant_Car@@UAAMPAVidEntity@@0PBVidDeclDamage@@MABVidVec3@@PAUtrace_t@@@Z
// EA  : 0x82D32920
// RVA : 0x00D32920
// PDB : w:\tech5\tungsten\game\entities\vehicleoccupants.cpp
// ========================================================================

float __fastcall idVehicleOccupant_Car::Damage(
        idVehicleOccupant_Car *this,
        idEntity *inflictor,
        idEntity *attacker,
        const idDeclDamage *damageDef,
        double damageScale,
        const idVec3 *dir,
        trace_t *trace)
{
  int GameMs; // r29
  const idHandle<unsigned short,enum invalidAliasHandle_t,65535> *v9; // r30
  const idAnimStack *v10; // r3
  const blendParms_t *v11; // r7
  double v12; // fp1
  blendParms_t v14[3]; // [sp+50h] [-40h] BYREF

  if ( (*((_BYTE *)this + 10026) & 0x10) != 0
    && damageDef != nullptr
    && (this->painReactionDamagetypes & damageDef->damageTypes) != 0 )
  {
    blendParms_t::blendParms_t(this: v14);
    blendParms_t::SetDestStartFrame(this: v14, frame: 0);
    blendParms_t::SetDuration(this: v14, frame: 0);
    v14[0].parms.originBlend = 1;
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    v9 = &this->painAnimations.list[idRandom2::RandomInt(this: &clientGame->random, max: this->painAnimations.num)];
    v10 = this->GetAnimStack_2(this);
    idAnimator_Channel::PlayAnim(
      this: &this->painAnimator,
      stack: v10,
      ah: v9,
      curTime: GameMs,
      rateScale: 1.0,
      blendParms: v11,
      blendOutDurationMS_: v14,
      leafStarted: (idMD6LeafPlay **)0xFFFFFFFF,
      a9: nullptr);
    v12 = 0.0;
  }
  else
  {
    v12 = 0.0;
  }
  return *((float *)&v12 + 1);
}


// ========================================================================
// ?SetLookHeadTrackingGroup@idVehicleOccupant_Car@@UAAXPBDH@Z
// EA  : 0x82D32A20
// RVA : 0x00D32A20
// PDB : w:\tech5\tungsten\game\entities\vehicleoccupants.cpp
// ========================================================================

void __fastcall idVehicleOccupant_Car::SetLookHeadTrackingGroup(
        idVehicleOccupant_Car *this,
        const char *headTrackGroupName,
        int blendDurationMS)
{
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idPresentable *presentable; // r11
  idTreeAnimator *v8; // r30
  idDeclMD6 *decl; // r3
  int HeadTrackGroupIndex; // r29
  idAnimStack *(__fastcall *GetAnimStack_2)(struct idAnimatedEntity *); // ctr
  idAnimStack *v12; // r3
  char v13; // r9
  int v14; // r29
  const idAnimStack *v15; // r3
  idAnimStack *v16; // r3
  int GameMs; // r29
  const idAnimStack *v18; // r3

  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
  presentable = this->presentable;
  v8 = TreeAnimatorFromPresentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    presentable = this->presentable;
  }
  idPresentable::UpdateModelTransform(this: presentable);
  if ( v8 != nullptr )
  {
    decl = v8->decl;
    if ( decl != nullptr )
    {
      HeadTrackGroupIndex = idDeclMD6::GetHeadTrackGroupIndex(this: decl, name: headTrackGroupName);
      GetAnimStack_2 = this->GetAnimStack_2;
      if ( HeadTrackGroupIndex < 0 )
      {
        v16 = GetAnimStack_2(this);
        idAnimator_Base::SetEnabled(this: &this->torsoAnimator, animStack: v16, enabled: false);
        GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        v18 = this->GetAnimStack_2(this);
        idAnimator_Base::End(this: &this->torsoAnimator, stack: v18, curTime: GameMs, blendDurationMS: 0, reset: true);
      }
      else
      {
        v12 = GetAnimStack_2(this);
        idAnimator_Base::SetEnabled(this: &this->torsoAnimator, animStack: v12, enabled: true);
        v13 = *((_BYTE *)this + 10026);
        this->torsoAnimator.trackGroupIndex = HeadTrackGroupIndex;
        if ( v13 < 0 )
        {
          v14 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
          v15 = this->GetAnimStack_2(this);
          idAnimator_Base::Start(this: &this->torsoAnimator, stack: v15, curTime: v14, blendDurationMS, reset: true);
        }
      }
    }
  }
}


// ========================================================================
// ?ClearLook@idVehicleOccupant_Car@@UAAXH@Z
// EA  : 0x82D32B78
// RVA : 0x00D32B78
// PDB : w:\tech5\tungsten\game\entities\vehicleoccupants.cpp
// ========================================================================

void __fastcall idVehicleOccupant_Car::ClearLook(idVehicleOccupant_Car *this, int blendDurationMS)
{
  int GameMs; // r29
  const idAnimStack *v5; // r3

  *((_BYTE *)this + 10026) &= ~0x80u;
  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  v5 = this->GetAnimStack_2(this);
  idAnimator_Base::End(this: &this->torsoAnimator, stack: v5, curTime: GameMs, blendDurationMS, reset: false);
}


// ========================================================================
// ?GetView@idVehicleOccupant_Car@@UBAXAAVidVec3@@AAVidMat3@@@Z
// EA  : 0x82D32BE8
// RVA : 0x00D32BE8
// PDB : w:\tech5\tungsten\game\entities\vehicleoccupants.cpp
// ========================================================================

void __fastcall idVehicleOccupant_Car::GetView(idVehicleOccupant_Car *this, idVec3 *origin, idMat3 *axis)
{
  idTreeAnimator *TreeAnimatorFromPresentable; // r3

  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
  if ( TreeAnimatorFromPresentable != nullptr && (unsigned __int16)this->cameraJointIndex.value < 0x8000u )
    idTreeAnimator::GetWorldSpaceJointTransform(
      this: TreeAnimatorFromPresentable,
      pose: DRIVER_MODEL,
      jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)this->cameraJointIndex.value,
      origin,
      axis);
  else
    this->GetModelTransform(this, a2: origin, a3: axis);
}


// ========================================================================
// ??1idVehicleOccupant_ATV@@UAA@XZ
// EA  : 0x82D32C60
// RVA : 0x00D32C60
// PDB : w:\tech5\tungsten\game\entities\vehicleoccupants.cpp
// ========================================================================

void __fastcall idVehicleOccupant_ATV::~idVehicleOccupant_ATV(idVehicleOccupant_ATV *this)
{
  this->__vftable = (idVehicleOccupant_ATV_vtbl *)&idVehicleOccupant_ATV::`vftable';
  idAnimator_AF::~idAnimator_AF(this: &this->ragdollAnimator);
  idAnimator_ReachIK::~idAnimator_ReachIK(this: &this->reachIKAnimator);
  idAnimator_Paused::~idAnimator_Paused(this: &this->boostAnimator);
  idAnimator_Paused::~idAnimator_Paused(this: &this->bumpUpAnimator);
  idAnimator_Paused::~idAnimator_Paused(this: &this->bumpForwardAnimator);
  idAnimator_Paused::~idAnimator_Paused(this: &this->bumpLeftAnimator);
  idAnimator_Paused::~idAnimator_Paused(this: &this->speedAnimator);
  idAnimator_Paused::~idAnimator_Paused(this: &this->steeringAnimator);
  idVehicleOccupant::~idVehicleOccupant(this);
}


// ========================================================================
// __unwind$491580
// EA  : 0x82D32CEC
// RVA : 0x00D32CEC
// PDB : w:\tech5\tungsten\game\entities\vehicleoccupants.cpp
// ========================================================================

void _unwind_491580()
{
  int v0; // r12

  idVehicleOccupant::~idVehicleOccupant(this: *(idVehicleOccupant **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$491581
// EA  : 0x82D32D14
// RVA : 0x00D32D14
// PDB : w:\tech5\tungsten\game\entities\vehicleoccupants.cpp
// ========================================================================

void _unwind_491581()
{
  int v0; // r12

  idAnimator_Paused::~idAnimator_Paused(this: (idAnimator_Paused *)(*(_DWORD *)(v0 - 112 + 132) + 8876));
}


// ========================================================================
// __unwind$491582
// EA  : 0x82D32D40
// RVA : 0x00D32D40
// PDB : w:\tech5\tungsten\game\entities\vehicleoccupants.cpp
// ========================================================================

void _unwind_491582()
{
  int v0; // r12

  idAnimator_Paused::~idAnimator_Paused(this: (idAnimator_Paused *)(*(_DWORD *)(v0 - 112 + 132) + 8928));
}


// ========================================================================
// __unwind$491583
// EA  : 0x82D32D6C
// RVA : 0x00D32D6C
// PDB : w:\tech5\tungsten\game\entities\vehicleoccupants.cpp
// ========================================================================

void _unwind_491583()
{
  int v0; // r12

  idAnimator_Paused::~idAnimator_Paused(this: (idAnimator_Paused *)(*(_DWORD *)(v0 - 112 + 132) + 8980));
}


// ========================================================================
// __unwind$491584
// EA  : 0x82D32D98
// RVA : 0x00D32D98
// PDB : w:\tech5\tungsten\game\entities\vehicleoccupants.cpp
// ========================================================================

void _unwind_491584()
{
  int v0; // r12

  idAnimator_Paused::~idAnimator_Paused(this: (idAnimator_Paused *)(*(_DWORD *)(v0 - 112 + 132) + 9032));
}


// ========================================================================
// __unwind$491585
// EA  : 0x82D32DC4
// RVA : 0x00D32DC4
// PDB : w:\tech5\tungsten\game\entities\vehicleoccupants.cpp
// ========================================================================

void _unwind_491585()
{
  int v0; // r12

  idAnimator_Paused::~idAnimator_Paused(this: (idAnimator_Paused *)(*(_DWORD *)(v0 - 112 + 132) + 9084));
}


// ========================================================================
// __unwind$491586
// EA  : 0x82D32DF0
// RVA : 0x00D32DF0
// PDB : w:\tech5\tungsten\game\entities\vehicleoccupants.cpp
// ========================================================================

void _unwind_491586()
{
  int v0; // r12

  idAnimator_Paused::~idAnimator_Paused(this: (idAnimator_Paused *)(*(_DWORD *)(v0 - 112 + 132) + 9136));
}


// ========================================================================
// __unwind$491587
// EA  : 0x82D32E1C
// RVA : 0x00D32E1C
// PDB : w:\tech5\tungsten\game\entities\vehicleoccupants.cpp
// ========================================================================

void _unwind_491587()
{
  int v0; // r12

  idAnimator_ReachIK::~idAnimator_ReachIK(this: (idAnimator_ReachIK *)(*(_DWORD *)(v0 - 112 + 132) + 9188));
}


// ========================================================================
// ?InternalExitVehicle@idVehicleOccupant_ATV@@MAAXXZ
// EA  : 0x82D32E48
// RVA : 0x00D32E48
// PDB : w:\tech5\tungsten\game\entities\vehicleoccupants.cpp
// ========================================================================

void __fastcall idVehicleOccupant_ATV::InternalExitVehicle(idVehicleOccupant_ATV *this)
{
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idPresentable *presentable; // r11
  idTreeAnimator *v4; // r30
  idAnimStack *v5; // r3

  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
  presentable = this->presentable;
  v4 = TreeAnimatorFromPresentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    presentable = this->presentable;
  }
  idPresentable::UpdateModelTransform(this: presentable);
  if ( v4 != nullptr )
  {
    v5 = this->GetAnimStack_2(this);
    idAnimator_Base::SetEnabled(this: &this->reachIKAnimator, animStack: v5, enabled: false);
  }
}


// ========================================================================
// ?Collide@idVehicleOccupant@@UAA?AW4collide_t@@HAAUtrace_t@@ABVidVec3@@@Z
// EA  : 0x82D32F88
// RVA : 0x00D32F88
// PDB : w:\tech5\tungsten\game\entities\vehicleoccupants.cpp
// ========================================================================

collide_t __fastcall idVehicleOccupant::Collide(
        idVehicleOccupant *this,
        int physId,
        trace_t *collision,
        const idVec3 *velocity)
{
  int v6; // r11
  idPhysics *PhysicsForId; // r31
  int i; // r30
  int v9; // r3
  idPlayer *linkedPlayer; // r4
  const idSoundShader *sndThrownLandingWater; // r5
  _BYTE v13[240]; // [sp+50h] [-F0h] BYREF

  if ( this->linkedPlayer != nullptr )
  {
    v6 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) - this->timeStartThrown;
    if ( this->thrown && v6 > atv_minThrowSoundDelay.valueInteger )
    {
      PhysicsForId = idPhysics::GetPhysicsForId(physicsId_: physId);
      for ( i = 0; i < PhysicsForId->GetNumContacts(this: PhysicsForId); ++i )
      {
        v9 = (int)PhysicsForId->GetContact(this: PhysicsForId, a2: i);
        if ( (*(_DWORD *)(v9 + 40) & 0x10) != 0 )
          return COLLIDE_CONTINUE_SIMULATION;
        linkedPlayer = this->linkedPlayer;
        if ( (*(_DWORD *)(v9 + 44) & 6) != 0 )
        {
          if ( idPlayer::GetPlayerSounds(
                 this: (idPlayer *)v13,
                 result: (const idDeclPlayerProps::playerSounds_t *)linkedPlayer)->sndThrownLandingWater != nullptr )
          {
            sndThrownLandingWater = idPlayer::GetPlayerSounds(
                                      this: (idPlayer *)v13,
                                      result: (const idDeclPlayerProps::playerSounds_t *)this->linkedPlayer)->sndThrownLandingWater;
LABEL_11:
            idEntity::StartSoundShader(
              this,
              channel: SND_CHANNEL_ANY,
              shader: sndThrownLandingWater,
              soundShaderFlags: SSF_PLAY_ONCE,
              peerMask: 0);
          }
        }
        else if ( idPlayer::GetPlayerSounds(
                    this: (idPlayer *)v13,
                    result: (const idDeclPlayerProps::playerSounds_t *)linkedPlayer)->sndThrownLanding != nullptr )
        {
          sndThrownLandingWater = idPlayer::GetPlayerSounds(
                                    this: (idPlayer *)v13,
                                    result: (const idDeclPlayerProps::playerSounds_t *)this->linkedPlayer)->sndThrownLanding;
          goto LABEL_11;
        }
        idVehicleOccupant::StopThrow(this);
      }
    }
  }
  return COLLIDE_CONTINUE_SIMULATION;
}


// ========================================================================
// ?ShouldEnterDormancy@idVehicleOccupant@@UAA_NXZ
// EA  : 0x82D330E0
// RVA : 0x00D330E0
// PDB : w:\tech5\tungsten\game\entities\vehicleoccupants.cpp
// ========================================================================

int __fastcall idVehicleOccupant::ShouldEnterDormancy(idVehicleOccupant *this)
{
  int value; // r10
  idVehicle *v3; // r3
  idVehicle *v4; // r3

  value = this->vehicle.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && ((v3 = (idVehicle *)gameLocal->entities.ptr[value & 0x1FFF]) == nullptr
      ? (v4 = nullptr)
      : (v4 = idVehicle::CastTo(c: v3)),
        (*((_BYTE *)&v4->flags + 1) & 0x80) != 0) )
  {
    return 1;
  }
  else
  {
    return idEntity::ShouldEnterDormancy(this);
  }
}


// ========================================================================
// ?ShouldLeaveDormancy@idVehicleOccupant@@UAA_NXZ
// EA  : 0x82D33198
// RVA : 0x00D33198
// PDB : w:\tech5\tungsten\game\entities\vehicleoccupants.cpp
// ========================================================================

int __fastcall idVehicleOccupant::ShouldLeaveDormancy(idVehicleOccupant *this)
{
  int value; // r10
  idVehicle *v2; // r3
  idVehicle *v3; // r3
  char v4; // r11
  int result; // r3

  value = this->vehicle.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] != value >> 13 )
    return 1;
  v2 = (idVehicle *)gameLocal->entities.ptr[value & 0x1FFF];
  v3 = v2 != nullptr ? idVehicle::CastTo(c: v2) : nullptr;
  v4 = *((_BYTE *)&v3->flags + 1);
  result = 0;
  if ( (v4 & 0x80) == 0 )
    return 1;
  return result;
}


// ========================================================================
// ?GetAimPoint@idVehicleOccupant@@UBAXW4aimPoint_t@@AAVidVec3@@@Z
// EA  : 0x82D33228
// RVA : 0x00D33228
// PDB : w:\tech5\tungsten\game\entities\vehicleoccupants.cpp
// ========================================================================

void __fastcall idVehicleOccupant::GetAimPoint(idVehicleOccupant *this, unsigned int aimPoint, idVec3 *pos)
{
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idPresentable *presentable; // r11
  idTreeAnimator *v8; // r27
  const idDeclMD6 *decl; // r11
  idJointGroupCollection *p_jointGroupCollection; // r31
  int JointGroupIndex; // r29
  int v12; // r3
  idJointGroup *v13; // r29
  idJointGroup *v14; // r11
  double v15; // fp7
  double v16; // fp5
  idPhysics *v17; // r3
  double y; // fp12
  double v19; // fp6
  double z; // fp11
  double v21; // fp5
  idPhysics *v22; // r3
  int v23; // r3
  char *v24; // r10
  _DWORD *v25; // r11
  int i; // ctr
  idPhysics *v27; // r3
  float *v28; // r3
  idPhysics *v29; // r3
  float *v30; // r3
  idPhysics *Physics; // r3
  float *v32; // r3
  double v33; // fp6
  double v34; // fp7
  idVec3 v35; // [sp+50h] [-C0h] BYREF
  idVec3 v36; // [sp+60h] [-B0h] BYREF
  idVec3 v37; // [sp+70h] [-A0h] BYREF
  char v38; // [sp+7Ch] [-94h] BYREF
  idMat3 v39; // [sp+80h] [-90h] BYREF
  idMat3 v40[2]; // [sp+B0h] [-60h] BYREF

  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
  presentable = this->presentable;
  v8 = TreeAnimatorFromPresentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    presentable = this->presentable;
  }
  idPresentable::UpdateModelTransform(this: presentable);
  if ( v8 != nullptr )
    decl = v8->decl;
  else
    decl = nullptr;
  if ( aimPoint > 8 )
    goto LABEL_27;
  if ( aimPoint != 1 )
  {
    switch ( aimPoint )
    {
      case 2u:
      case 3u:
LABEL_27:
        Physics = idEntity::GetPhysics(this);
        v32 = (float *)Physics->GetAbsBounds(this: Physics, a2: -1);
        v33 = (float)(v32[2] + v32[5]);
        v34 = (float)(v32[1] + v32[4]);
        pos->x = (float)(*v32 + v32[3]) * (float)0.5;
        pos->z = (float)v33 * (float)0.5;
        pos->y = (float)v34 * (float)0.5;
        return;
      case 4u:
        v22 = idEntity::GetPhysics(this);
        v23 = (int)v22->GetAbsBounds(this: v22, a2: -1);
        v24 = &v38;
        v25 = (_DWORD *)(v23 - 4);
        for ( i = 6; i != 0; --i )
        {
          ++v25;
          v24 += 4;
          *(_DWORD *)v24 = *v25;
        }
        v27 = idEntity::GetPhysics(this);
        v28 = (float *)v27->GetOrigin(this: v27, a2: 0);
        pos->x = *v28;
        pos->y = v28[1];
        pos->z = (float)((float)(v39.mat[1].z - v39.mat[0].z) * (float)0.25) + v28[2];
        return;
      case 5u:
        v29 = idEntity::GetPhysics(this);
        v30 = (float *)v29->GetOrigin(this: v29, a2: 0);
        pos->x = *v30;
        pos->y = v30[1];
        pos->z = v30[2];
        return;
      default:
        break;
    }
  }
  if ( decl == nullptr )
    goto LABEL_27;
  p_jointGroupCollection = &decl->jointGroupCollection;
  JointGroupIndex = idJointGroupCollection::GetJointGroupIndex(
                      this: &decl->jointGroupCollection,
                      type: 9,
                      name: "rightEye");
  v12 = idJointGroupCollection::GetJointGroupIndex(this: p_jointGroupCollection, type: 9, name: "leftEye");
  v13 = JointGroupIndex < 0 ? nullptr : p_jointGroupCollection->jointGroups.list[JointGroupIndex];
  v14 = v12 < 0 ? nullptr : p_jointGroupCollection->jointGroups.list[v12];
  if ( v13 == nullptr || v14 == nullptr )
    goto LABEL_27;
  idTreeAnimator::GetWorldSpaceJointTransform(
    this: v8,
    pose: DRIVER_MODEL,
    jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)v13->joints.list->value,
    origin: &v36,
    axis: &v39);
  idTreeAnimator::GetWorldSpaceJointTransform(
    this: v8,
    pose: DRIVER_MODEL,
    jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)v13->joints.list->value,
    origin: &v37,
    axis: v40);
  v15 = (float)(v36.y + v37.y);
  v16 = (float)(v37.z + v36.z);
  pos->x = (float)(v37.x + v36.x) * (float)0.5;
  pos->y = (float)v15 * (float)0.5;
  pos->z = (float)v16 * (float)0.5;
  if ( aimPoint == 8 )
  {
    v17 = idEntity::GetPhysics(this);
    v17->GetLinearVelocity(this: (idPhysics *)&v35, result: (idVec3 *)v17, a3: 0);
    idVec3::NormalizeFast(this: &v35);
    y = pos->y;
    v19 = (float)(v35.y * (float)64.0);
    z = pos->z;
    v21 = (float)(v35.z * (float)64.0);
    pos->x = pos->x + (float)(v35.x * (float)64.0);
    pos->y = (float)y + (float)v19;
    pos->z = (float)z + (float)v21;
  }
}


// ========================================================================
// ?Spawn@idVehicleOccupant_Car@@QAAXXZ
// EA  : 0x82D33568
// RVA : 0x00D33568
// PDB : w:\tech5\tungsten\game\entities\vehicleoccupants.cpp
// ========================================================================

void __fastcall idVehicleOccupant_Car::Spawn(idVehicleOccupant_Car *this)
{
  idAnimStack *v2; // r3
  idGameTimeManager *v3; // r3
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idPresentable *presentable; // r11
  idTreeAnimator *v6; // r28
  idDeclMD6 *decl; // r3
  idVarArgs<6> *UserProp; // r3
  idPhysics *Physics; // r3
  float *v10; // r3
  double v11; // fp0
  idTypesafeNumber<float,enum DegreesUnique_t> v12; // [sp+50h] [-90h] BYREF
  idTypesafeNumber<float,enum DegreesUnique_t> v13[3]; // [sp+54h] [-8Ch] BYREF
  idVec4 v14; // [sp+60h] [-80h] BYREF
  idAnimatorParms_TrackerBase v15; // [sp+70h] [-70h] BYREF

  v2 = this->GetAnimStack_2(this);
  idAnimatorParms_TrackerBase::idAnimatorParms_TrackerBase(
    this: &v15,
    animStack_: v2,
    name_: "look",
    originBlend_: ORIGINBLEND_BRANCH,
    weightGroup_: MD6_WEIGHTGROUP_ALL,
    filterGroup_: MD6_WEIGHTGROUP_ALL,
    alpha_: 0.0,
    projectReferenceOrientation_: (const bool)"merchant.",
    a9: true);
  v3 = gameLocal->GetGameTimeManager(this: gameLocal);
  idAnimator_Base::Init(this: &this->torsoAnimator, gametimeManager: v3, parms: &v15);
  this->SetLookHeadTrackingGroup(this, a2: "look", a3: 0);
  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
  presentable = this->presentable;
  v6 = TreeAnimatorFromPresentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    presentable = this->presentable;
  }
  idPresentable::UpdateModelTransform(this: presentable);
  if ( v6 != nullptr )
    decl = v6->decl;
  else
    decl = nullptr;
  if ( decl != nullptr )
  {
    UserProp = (idVarArgs<6> *)idDeclMD6::FindUserProp(this: decl, name: "lookLimits");
    if ( UserProp != nullptr )
    {
      idVarArgs<6>::GetArg(this: UserProp, index: 1, val: &v14);
      v12.value = v14.y;
      v13[0] = LODWORD(v14.x);
      idAnimator_TrackerBase::SetPitchConstraints(this: &this->torsoAnimator, up: v13, down: &v12);
      v13[0] = LODWORD(v14.w);
      v12.value = v14.z;
      idAnimator_TrackerBase::SetYawConstraints(this: &this->torsoAnimator, right: &v12, left: v13);
      *((_BYTE *)&this->torsoAnimator.idAnimator_TrackerBase + 180) |= 0x20u;
    }
  }
  idSpring<idVec3>::SetConstants(
    this: &this->reactionSpring,
    _k: atv_bumpSpringConstant.valueFloat,
    _c: atv_bumpSpringDampen.valueFloat);
  this->reactionSpring.m = atv_bumpSpringMass.valueFloat;
  Physics = idEntity::GetPhysics(this);
  v10 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
  v11 = *v10;
  this->reactionSpring.p0.x = *v10;
  this->reactionSpring.p0.y = v10[1];
  LODWORD(v13[0].value) = &this->reactionSpring.vel;
  this->reactionSpring.p0.z = v10[2];
  this->reactionSpring.p1.x = v11;
  this->reactionSpring.p1.y = this->reactionSpring.p0.y;
  this->reactionSpring.p1.z = this->reactionSpring.p0.z;
  this->reactionSpring.vel.z = 0.0;
  this->reactionSpring.vel.y = 0.0;
  this->reactionSpring.vel.x = 0.0;
  idStr::FreeData(this: &v15.name);
}


// ========================================================================
// __unwind$493103_0
// EA  : 0x82D33770
// RVA : 0x00D33770
// PDB : w:\tech5\tungsten\game\entities\vehicleoccupants.cpp
// ========================================================================

void _unwind_493103_0()
{
  int v0; // r12

  idAnimatorParms_EndAdditiveChannels::~idAnimatorParms_EndAdditiveChannels(this: (vaiAction_t::vehicleCam_t *)(v0 - 224 + 112));
}


// ========================================================================
// ?WasTeleported@idVehicleOccupant_Car@@UAAXXZ
// EA  : 0x82D33798
// RVA : 0x00D33798
// PDB : w:\tech5\tungsten\game\entities\vehicleoccupants.cpp
// ========================================================================

void __fastcall idVehicleOccupant_Car::WasTeleported(idVehicleOccupant_Car *this)
{
  idTreeAnimator *tagAnimator; // r30
  tagData_t *p_tagData; // r29
  idIndex<short,enum invalidJointIndex_t> *decl; // r4
  float *p_deferredAxis; // r11
  float *p_x; // r11
  double v7; // fp0
  double v8; // fp12
  double v9; // fp13
  const idMat3 *p_axis; // r4
  double v11; // fp7
  double v12; // fp6
  double x; // fp13
  double y; // fp12
  double z; // fp11
  unsigned __int16 v16; // [sp+50h] [-70h] BYREF
  idVec3 v17; // [sp+58h] [-68h] BYREF
  idMat3 v18[2]; // [sp+70h] [-50h] BYREF

  tagAnimator = this->tagAnimator;
  p_tagData = &this->tagData;
  if ( tagAnimator != nullptr )
  {
    decl = (idIndex<short,enum invalidJointIndex_t> *)tagAnimator->decl;
    if ( decl != nullptr && this->tagData.parentJoint.value != 0xFFFF )
    {
      idDeclMD6::GetJointIndex(this: (idDeclMD6 *)&v16, result: decl, handle: &this->tagData.parentJoint);
      if ( (v16 & 0x8000u) == 0
        && (unsigned __int8)idTreeAnimator::GetModelSpaceAttachmentTransform(
                              this: tagAnimator,
                              jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)v16,
                              translationOffset: &p_tagData->trans,
                              rotationOffset: (idMat3 *)&p_tagData->rot,
                              origin: &v17,
                              axis: v18) != 0 )
      {
        p_deferredAxis = (float *)&tagAnimator->deferredAxis;
        if ( !tagAnimator->useDeferredPosition )
          p_deferredAxis = (float *)&tagAnimator->g.axis;
        v7 = (float)((float)(*p_deferredAxis * v17.x)
                   + (float)((float)(p_deferredAxis[3] * v17.y) + (float)(p_deferredAxis[6] * v17.z)));
        v8 = (float)((float)(p_deferredAxis[1] * v17.x)
                   + (float)((float)(p_deferredAxis[4] * v17.y) + (float)(p_deferredAxis[7] * v17.z)));
        v9 = (float)((float)(p_deferredAxis[2] * v17.x)
                   + (float)((float)(p_deferredAxis[5] * v17.y) + (float)(p_deferredAxis[8] * v17.z)));
        p_x = &tagAnimator->deferredOrigin.x;
        if ( !tagAnimator->useDeferredPosition )
          p_x = &tagAnimator->g.origin.x;
        p_axis = &tagAnimator->deferredAxis;
        v11 = (float)(p_x[1] + (float)v8);
        v12 = (float)(p_x[2] + (float)v9);
        v17.x = *p_x + (float)v7;
        v17.y = v11;
        v17.z = v12;
        if ( !tagAnimator->useDeferredPosition )
          p_axis = &tagAnimator->g.axis;
        idMat3::operator*=(this: v18, a: p_axis);
        x = v17.x;
        y = v17.y;
        z = v17.z;
        this->reactionSpring.p0.x = v17.x;
        this->reactionSpring.p0.y = y;
        this->reactionSpring.p0.z = z;
        this->reactionSpring.p1.x = x;
        this->reactionSpring.p1.y = this->reactionSpring.p0.y;
        this->reactionSpring.p1.z = this->reactionSpring.p0.z;
        this->reactionSpring.vel.z = 0.0;
        this->reactionSpring.vel.y = 0.0;
        this->reactionSpring.vel.x = 0.0;
      }
    }
  }
}


// ========================================================================
// ?InternalInitAnimation@idVehicleOccupant_Car@@MAAXXZ
// EA  : 0x82D33920
// RVA : 0x00D33920
// PDB : w:\tech5\tungsten\game\entities\vehicleoccupants.cpp
// ========================================================================

void __fastcall idVehicleOccupant_Car::InternalInitAnimation(idVehicleOccupant_Car *this)
{
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idPresentable *presentable; // r11
  idTreeAnimator *v4; // r23
  char *str; // r11
  char v6; // r11
  bool v7; // zf
  const char *v8; // r5
  __int16 *JointIndex; // r3
  int value; // r9
  const idMD6Anim *v11; // r3
  const idMD6Anim *v12; // r28
  idMD6AnimData *animData; // r11
  __int64 v14; // r11
  idAnimStack *v15; // r3
  idGameTimeManager *v16; // r3
  idGameTimeManager *v17; // r3
  idGameTimeManager *v18; // r3
  idVehicleOccupant_Car_vtbl *v19; // r10
  idGameTimeManager *v20; // r3
  idHandle<unsigned short,enum invalidAliasHandle_t,65535> *reactionAnimHandles; // r28
  const idMD6Anim **reactionAnims; // r27
  idHandle<unsigned short,enum invalidAliasHandle_t,65535> *v23; // r26
  int v24; // r25
  double v25; // fp31
  idGameTimeManager *v26; // r3
  idGameTimeManager *v27; // r3
  idGameTimeManager *v28; // r3
  idHandle<unsigned short,enum invalidAliasHandle_t,65535> *headAnims; // r26
  int i; // r29
  int j; // r29
  int v32; // [sp+8h] [-288h]
  int v33; // [sp+Ch] [-284h]
  int v34; // [sp+10h] [-280h]
  int v35; // [sp+14h] [-27Ch]
  int v36; // [sp+18h] [-278h]
  int v37; // [sp+1Ch] [-274h]
  int v38; // [sp+20h] [-270h]
  int v39; // [sp+24h] [-26Ch]
  int v40; // [sp+28h] [-268h]
  int v41; // [sp+2Ch] [-264h]
  int v42; // [sp+30h] [-260h]
  int v43; // [sp+34h] [-25Ch]
  int v44; // [sp+38h] [-258h]
  int v45; // [sp+3Ch] [-254h]
  int v46; // [sp+40h] [-250h]
  int v47; // [sp+44h] [-24Ch]
  int v48; // [sp+48h] [-248h]
  int v49; // [sp+4Ch] [-244h]
  int v50; // [sp+50h] [-240h]
  int v51; // [sp+58h] [-238h]
  _QWORD v52[2]; // [sp+70h] [-220h] BYREF
  idAnimatorParms_Base v53; // [sp+80h] [-210h] BYREF
  int v54; // [sp+B8h] [-1D8h]
  float v55; // [sp+BCh] [-1D4h]
  float v56; // [sp+C0h] [-1D0h]
  idAnimatorParms_Base v57; // [sp+D0h] [-1C0h] BYREF
  int v58; // [sp+108h] [-188h]
  idAnimatorParms_Base v59; // [sp+110h] [-180h] BYREF
  idAnimatorParms_Base v60; // [sp+150h] [-140h] BYREF
  idAnimatorParms_Base v61; // [sp+190h] [-100h] BYREF
  idAnimatorParms_Pause v62; // [sp+1D0h] [-C0h] BYREF

  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
  presentable = this->presentable;
  v4 = TreeAnimatorFromPresentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    presentable = this->presentable;
  }
  idPresentable::UpdateModelTransform(this: presentable);
  if ( v4 != nullptr )
  {
    str = (char *)this->cameraJointName.str;
    if ( str == &byte_8200D768 || (v7 = *str != 0, v6 = 0, !v7) )
      v6 = 1;
    if ( v6 != 0 )
      v8 = "camera";
    else
      v8 = this->cameraJointName.str;
    JointIndex = (__int16 *)idTreeAnimator::GetJointIndex(
                              this: (idTreeAnimator *)v52,
                              result: (idIndex<short,enum invalidJointIndex_t> *)v4,
                              jointName: v8);
    value = this->steeringAnim.value;
    this->cameraJointIndex.value = *JointIndex;
    if ( value != 0xFFFF )
    {
      v11 = idDeclMD6::AnimForAlias(this: v4->decl, aliasHandle: &this->steeringAnim, load: false);
      v12 = v11;
      if ( v11 != nullptr )
      {
        animData = v11->animData;
        if ( animData != nullptr )
          LODWORD(v14) = animData->numFrames;
        else
          LODWORD(v14) = 0;
        HIDWORD(v14) = this->__vftable;
        v52[1] = v14;
        this->numSteeringFrames = (float)v14;
        v15 = (idAnimStack *)(*(int (__fastcall **)(idVehicleOccupant_Car *))(HIDWORD(v14) + 184))(a1: this);
        idAnimatorParms_Pause::idAnimatorParms_Pause(
          this: &v62,
          anim_: v12,
          startFrame_: 0.0,
          normalizedStartFrame_: 0.5,
          animStack_: (idAnimStack *)"mMaterial",
          name_: (const char *)0x82000000,
          blendOp_: v15,
          originBlend_: "steering",
          weightGroup_: BOP_LERP,
          filterGroup_: ORIGINBLEND_BRANCH,
          alpha_: 1.0,
          a12: v32,
          a13: v33,
          a14: v34,
          a15: v35,
          a16: v36,
          a17: v37,
          a18: v38,
          a19: v39,
          a20: v40,
          a21: v41,
          a22: v42,
          a23: v43,
          a24: v44,
          a25: v45,
          a26: v46,
          a27: v47,
          a28: v48,
          a29: v49,
          a30: v50,
          a31: MD6_WEIGHTGROUP_ALL,
          a32: v51,
          a33: MD6_WEIGHTGROUP_ALL);
        v16 = gameLocal->GetGameTimeManager(this: gameLocal);
        idAnimator_Base::Init(this: &this->steeringAnimator, gametimeManager: v16, parms: &v62);
        idStr::FreeData(this: &v62.name);
      }
    }
    if ( this->passengerAnim.value != 0xFFFF )
    {
      v61.animStack = this->GetAnimStack_2(this);
      idStr::idStr(this: &v61.name, text: "passenger");
      v61.alpha = 1.0;
      v61.blendOp = BOP_LERP;
      memset(&v61.originBlend, 0, 12);
      v17 = gameLocal->GetGameTimeManager(this: gameLocal);
      idAnimator_Base::Init(this: &this->passengerAnimator, gametimeManager: v17, parms: &v61);
      idStr::FreeData(this: &v61.name);
    }
    v60.animStack = this->GetAnimStack_2(this);
    idStr::idStr(this: &v60.name, text: "head");
    v60.alpha = 1.0;
    v60.blendOp = BOP_LERP;
    memset(&v60.originBlend, 0, 12);
    v18 = gameLocal->GetGameTimeManager(this: gameLocal);
    idAnimator_Base::Init(this: &this->headAnimator, gametimeManager: v18, parms: &v60);
    if ( this->additiveShakeAnim.value != 0xFFFF )
    {
      v19 = this->__vftable;
      *((_BYTE *)this + 10026) |= 0x20u;
      v57.animStack = v19->GetAnimStack_2(this);
      idStr::idStr(this: &v57.name, text: "additive");
      v57.alpha = 1.0;
      v57.blendOp = BOP_ADD_RIGHT;
      memset(&v57.originBlend, 0, 12);
      v58 = 1;
      v20 = gameLocal->GetGameTimeManager(this: gameLocal);
      idAnimator_Base::Init(this: &this->additiveShakeAnimator, gametimeManager: v20, parms: &v57);
      idStr::FreeData(this: &v57.name);
    }
    reactionAnimHandles = this->reactionAnimHandles;
    reactionAnims = this->reactionAnims;
    v23 = this->reactionAnimHandles;
    v24 = 4;
    *((_BYTE *)this + 10026) &= ~0x40u;
    do
    {
      if ( v23->value == 0xFFFF )
      {
        *reactionAnims = nullptr;
      }
      else
      {
        *reactionAnims = idDeclMD6::AnimForAlias(this: v4->decl, aliasHandle: v23, load: false);
        *((_BYTE *)this + 10026) |= 0x40u;
      }
      --v24;
      ++v23;
      ++reactionAnims;
    }
    while ( v24 != 0 );
    if ( (*((_BYTE *)this + 10026) & 0x40) != 0 )
    {
      if ( atv_bumpLeft.valueInteger != 0 )
        v25 = 1.0;
      else
        v25 = 0.0;
      v53.animStack = this->GetAnimStack_2(this);
      idStr::idStr(this: &v53.name, text: "bump_left");
      v53.alpha = v25;
      v53.blendOp = BOP_ADD_RIGHT;
      v55 = 0.0;
      memset(&v53.originBlend, 0, 12);
      v54 = 0;
      v56 = -1.0;
      v26 = gameLocal->GetGameTimeManager(this: gameLocal);
      idAnimator_Base::Init(this: &this->bumpLeftAnimator, gametimeManager: v26, parms: &v53);
      idStr::operator=(this: &v53.name, text: "bump_forward");
      if ( atv_bumpForward.valueInteger != 0 )
        v53.alpha = 1.0;
      else
        v53.alpha = 0.0;
      v27 = gameLocal->GetGameTimeManager(this: gameLocal);
      idAnimator_Base::Init(this: &this->bumpForwardAnimator, gametimeManager: v27, parms: &v53);
      idStr::FreeData(this: &v53.name);
    }
    if ( this->painAnimations.num != 0 )
    {
      v59.animStack = this->GetAnimStack_2(this);
      idStr::idStr(this: &v59.name, text: "pain");
      v59.alpha = 1.0;
      v59.blendOp = BOP_ADD_RIGHT;
      memset(&v59.originBlend, 0, 12);
      v28 = gameLocal->GetGameTimeManager(this: gameLocal);
      idAnimator_Base::Init(this: &this->painAnimator, gametimeManager: v28, parms: &v59);
      *((_BYTE *)&this->painAnimator.idAnimator_Channel + 94) |= 0x40u;
      *((_BYTE *)this + 10026) |= 0x10u;
      idStr::FreeData(this: &v59.name);
    }
    headAnims = this->headAnims;
    for ( i = 3; i != 0; --i )
      gameAnimTools->VerifyStrongAliasRefs(this: gameAnimTools, a2: v4, a3: headAnims++, a4: this->name.data);
    gameAnimTools->VerifyStrongAliasRefs(this: gameAnimTools, a2: v4, a3: &this->steeringAnim, a4: this->name.data);
    gameAnimTools->VerifyStrongAliasRefs(this: gameAnimTools, a2: v4, a3: &this->gunnerIdleAnim, a4: this->name.data);
    for ( j = 4; j != 0; --j )
      gameAnimTools->VerifyStrongAliasRefs(this: gameAnimTools, a2: v4, a3: reactionAnimHandles++, a4: this->name.data);
    idStr::FreeData(this: &v60.name);
  }
}


// ========================================================================
// __unwind$493326
// EA  : 0x82D33ECC
// RVA : 0x00D33ECC
// PDB : w:\tech5\tungsten\game\entities\vehicleoccupants.cpp
// ========================================================================

void _unwind_493326()
{
  int v0; // r12

  idAnimatorParms_EndAdditiveChannels::~idAnimatorParms_EndAdditiveChannels(this: (vaiAction_t::vehicleCam_t *)(v0 - 656 + 464));
}


// ========================================================================
// __unwind$493327
// EA  : 0x82D33EF4
// RVA : 0x00D33EF4
// PDB : w:\tech5\tungsten\game\entities\vehicleoccupants.cpp
// ========================================================================

void _unwind_493327()
{
  int v0; // r12

  idAnimatorParms_EndAdditiveChannels::~idAnimatorParms_EndAdditiveChannels(this: (vaiAction_t::vehicleCam_t *)(v0 - 656 + 400));
}


// ========================================================================
// __unwind$493328
// EA  : 0x82D33F1C
// RVA : 0x00D33F1C
// PDB : w:\tech5\tungsten\game\entities\vehicleoccupants.cpp
// ========================================================================

void _unwind_493328()
{
  int v0; // r12

  idAnimatorParms_EndAdditiveChannels::~idAnimatorParms_EndAdditiveChannels(this: (vaiAction_t::vehicleCam_t *)(v0 - 656 + 336));
}


// ========================================================================
// __unwind$493329
// EA  : 0x82D33F44
// RVA : 0x00D33F44
// PDB : w:\tech5\tungsten\game\entities\vehicleoccupants.cpp
// ========================================================================

void _unwind_493329()
{
  int v0; // r12

  idAnimatorParms_EndAdditiveChannels::~idAnimatorParms_EndAdditiveChannels(this: (vaiAction_t::vehicleCam_t *)(v0 - 656 + 208));
}


// ========================================================================
// __unwind$493330
// EA  : 0x82D33F6C
// RVA : 0x00D33F6C
// PDB : w:\tech5\tungsten\game\entities\vehicleoccupants.cpp
// ========================================================================

void _unwind_493330()
{
  int v0; // r12

  idAnimatorParms_EndAdditiveChannels::~idAnimatorParms_EndAdditiveChannels(this: (vaiAction_t::vehicleCam_t *)(v0 - 656 + 128));
}


// ========================================================================
// __unwind$493331
// EA  : 0x82D33F94
// RVA : 0x00D33F94
// PDB : w:\tech5\tungsten\game\entities\vehicleoccupants.cpp
// ========================================================================

void _unwind_493331()
{
  int v0; // r12

  idAnimatorParms_EndAdditiveChannels::~idAnimatorParms_EndAdditiveChannels(this: (vaiAction_t::vehicleCam_t *)(v0 - 656 + 272));
}


// ========================================================================
// ?InternalEnterVehicle@idVehicleOccupant_Car@@MAAXPAVidVehicle@@PAVidTreeAnimator@@PBD@Z
// EA  : 0x82D33FC0
// RVA : 0x00D33FC0
// PDB : w:\tech5\tungsten\game\entities\vehicleoccupants.cpp
// ========================================================================

void __fastcall idVehicleOccupant_Car::InternalEnterVehicle(
        idVehicleOccupant_Car *this,
        idVehicle *vehicle,
        idTreeAnimator *tagAnimator,
        const char *tagName)
{
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idPresentable *presentable; // r11
  idTreeAnimator *v8; // r29
  idPhysics *Physics; // r3
  float *v10; // r3
  double v11; // fp0
  int v12; // r30
  const idAnimStack *v13; // r3
  int GameMs; // r29
  const idAnimStack *v15; // r3
  __int64 v16; // r8
  int v17; // r29
  const idAnimStack *v18; // r3
  blendParms_t v19[3]; // [sp+50h] [-40h] BYREF

  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
  presentable = this->presentable;
  v8 = TreeAnimatorFromPresentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    presentable = this->presentable;
  }
  idPresentable::UpdateModelTransform(this: presentable);
  if ( v8 != nullptr )
  {
    Physics = idEntity::GetPhysics(this: vehicle);
    v10 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
    v11 = *v10;
    this->reactionSpring.p0.x = *v10;
    this->reactionSpring.p0.y = v10[1];
    this->reactionSpring.p0.z = v10[2];
    this->reactionSpring.p1.x = v11;
    this->reactionSpring.p1.y = this->reactionSpring.p0.y;
    this->reactionSpring.p1.z = this->reactionSpring.p0.z;
    this->reactionSpring.vel.z = 0.0;
    this->reactionSpring.vel.y = 0.0;
    this->reactionSpring.vel.x = 0.0;
    if ( vehicle != nullptr && idVehicle::GetOccupantVisual(this: vehicle, index: 0) == this )
    {
      v12 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
      v13 = this->GetAnimStack_2(this);
      idAnimator_Base::Start(this: &this->steeringAnimator, stack: v13, curTime: v12, blendDurationMS: 0, reset: true);
    }
    else
    {
      blendParms_t::blendParms_t(this: v19);
      blendParms_t::SetDestStartFrame(this: v19, frame: 0);
      blendParms_t::SetDuration(this: v19, frame: 0);
      v19[0].parms.originBlend = 1;
      GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      v15 = this->GetAnimStack_2(this);
      HIDWORD(v16) = 0x82000000;
      LODWORD(v16) = v19;
      idAnimator_Channel::CycleAnim(
        this: &this->passengerAnimator,
        stack: v15,
        ah: &this->passengerAnim,
        curTime: GameMs,
        rateScale: 1.0,
        leafStarted: v16,
        a7: nullptr);
      v17 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
      v18 = this->GetAnimStack_2(this);
      idAnimator_Base::Start(this: &this->passengerAnimator, stack: v18, curTime: v17, blendDurationMS: 0, reset: true);
    }
  }
}


// ========================================================================
// ?Spawn@idVehicleOccupant_ATV@@QAAXXZ
// EA  : 0x82D34210
// RVA : 0x00D34210
// PDB : w:\tech5\tungsten\game\entities\vehicleoccupants.cpp
// ========================================================================

void __fastcall idVehicleOccupant_ATV::Spawn(idVehicleOccupant_ATV *this)
{
  idPhysics *Physics; // r3
  idVec3 *v3; // r3
  double x; // fp0

  idSpring<idVec3>::SetConstants(
    this: &this->bumpSpring,
    _k: atv_bumpSpringConstant.valueFloat,
    _c: atv_bumpSpringDampen.valueFloat);
  this->bumpSpring.m = atv_bumpSpringMass.valueFloat;
  Physics = idEntity::GetPhysics(this);
  v3 = (idVec3 *)Physics->GetOrigin(this: Physics, a2: 0);
  x = v3->x;
  this->bumpSpring.p0 = *v3;
  this->bumpSpring.p1.x = x;
  this->bumpSpring.p1.y = this->bumpSpring.p0.y;
  this->bumpSpring.p1.z = this->bumpSpring.p0.z;
  this->bumpSpring.vel.z = 0.0;
  this->bumpSpring.vel.y = 0.0;
  this->bumpSpring.vel.x = 0.0;
}


// ========================================================================
// ?InternalInitAnimation@idVehicleOccupant_ATV@@MAAXXZ
// EA  : 0x82D342D0
// RVA : 0x00D342D0
// PDB : w:\tech5\tungsten\game\entities\vehicleoccupants.cpp
// ========================================================================

void __fastcall idVehicleOccupant_ATV::InternalInitAnimation(idVehicleOccupant_ATV *this)
{
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idPresentable *presentable; // r11
  const idTreeAnimator *v4; // r25
  idDeclMD6 *decl; // r27
  idAnimStack *v6; // r29
  const idMD6Anim *v7; // r3
  idAnimStack *v8; // r5
  idGameTimeManager *v9; // r3
  idAnimStack *v10; // r26
  const idMD6Anim *v11; // r3
  const char *v12; // r6
  idAnimStack *v13; // r5
  idGameTimeManager *v14; // r3
  double v15; // fp30
  idAnimStack *v16; // r26
  const idMD6Anim *v17; // r3
  const char *v18; // r6
  idAnimStack *v19; // r5
  idGameTimeManager *v20; // r3
  idHandle<unsigned short,enum invalidAliasHandle_t,65535> *bumpAnimAliases; // r28
  idGameTimeManager *v22; // r3
  idGameTimeManager *v23; // r3
  idGameTimeManager *v24; // r3
  const idDeclReachIK *v25; // r27
  int entityNumber; // r26
  idAnimStack *v27; // r3
  idGameTimeManager *v28; // r3
  idAnimStack *v29; // r3
  int i; // r29
  int v31; // [sp+8h] [-208h]
  int v32; // [sp+8h] [-208h]
  int v33; // [sp+8h] [-208h]
  int v34; // [sp+Ch] [-204h]
  int v35; // [sp+Ch] [-204h]
  int v36; // [sp+Ch] [-204h]
  int v37; // [sp+10h] [-200h]
  int v38; // [sp+10h] [-200h]
  int v39; // [sp+10h] [-200h]
  int v40; // [sp+14h] [-1FCh]
  int v41; // [sp+14h] [-1FCh]
  int v42; // [sp+14h] [-1FCh]
  int v43; // [sp+18h] [-1F8h]
  int v44; // [sp+18h] [-1F8h]
  int v45; // [sp+18h] [-1F8h]
  int v46; // [sp+1Ch] [-1F4h]
  int v47; // [sp+1Ch] [-1F4h]
  int v48; // [sp+1Ch] [-1F4h]
  int v49; // [sp+20h] [-1F0h]
  int v50; // [sp+20h] [-1F0h]
  int v51; // [sp+20h] [-1F0h]
  int v52; // [sp+24h] [-1ECh]
  int v53; // [sp+24h] [-1ECh]
  int v54; // [sp+24h] [-1ECh]
  int v55; // [sp+28h] [-1E8h]
  int v56; // [sp+28h] [-1E8h]
  int v57; // [sp+28h] [-1E8h]
  int v58; // [sp+2Ch] [-1E4h]
  int v59; // [sp+2Ch] [-1E4h]
  int v60; // [sp+2Ch] [-1E4h]
  int v61; // [sp+30h] [-1E0h]
  int v62; // [sp+30h] [-1E0h]
  int v63; // [sp+30h] [-1E0h]
  int v64; // [sp+34h] [-1DCh]
  int v65; // [sp+34h] [-1DCh]
  int v66; // [sp+34h] [-1DCh]
  int v67; // [sp+38h] [-1D8h]
  int v68; // [sp+38h] [-1D8h]
  int v69; // [sp+38h] [-1D8h]
  int v70; // [sp+3Ch] [-1D4h]
  int v71; // [sp+3Ch] [-1D4h]
  int v72; // [sp+3Ch] [-1D4h]
  int v73; // [sp+40h] [-1D0h]
  int v74; // [sp+40h] [-1D0h]
  int v75; // [sp+40h] [-1D0h]
  int v76; // [sp+44h] [-1CCh]
  int v77; // [sp+44h] [-1CCh]
  int v78; // [sp+44h] [-1CCh]
  int v79; // [sp+48h] [-1C8h]
  int v80; // [sp+48h] [-1C8h]
  int v81; // [sp+48h] [-1C8h]
  int v82; // [sp+4Ch] [-1C4h]
  int v83; // [sp+4Ch] [-1C4h]
  int v84; // [sp+4Ch] [-1C4h]
  int v85; // [sp+50h] [-1C0h]
  int v86; // [sp+50h] [-1C0h]
  int v87; // [sp+50h] [-1C0h]
  int v88; // [sp+58h] [-1B8h]
  int v89; // [sp+58h] [-1B8h]
  int v90; // [sp+58h] [-1B8h]
  idAnimatorParms_Pause v91; // [sp+70h] [-1A0h] BYREF
  idAnimatorParms_ReachIK v92; // [sp+C0h] [-150h] BYREF
  idAnimatorParms_Pause v93; // [sp+110h] [-100h] BYREF
  idAnimatorParms_Pause v94; // [sp+160h] [-B0h] BYREF

  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
  presentable = this->presentable;
  v4 = TreeAnimatorFromPresentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    presentable = this->presentable;
  }
  idPresentable::UpdateModelTransform(this: presentable);
  if ( v4 != nullptr )
  {
    decl = v4->decl;
    if ( decl != nullptr )
    {
      v6 = this->GetAnimStack_2(this);
      v7 = idDeclMD6::AnimForAlias(this: decl, aliasHandle: &this->sweepLeftRightAlias, load: false);
      idAnimatorParms_Pause::idAnimatorParms_Pause(
        this: &v94,
        anim_: v7,
        startFrame_: 0.0,
        normalizedStartFrame_: 0.5,
        animStack_: v8,
        name_: "DistToTarget: %f dist: %f \n",
        blendOp_: v6,
        originBlend_: "steer",
        weightGroup_: BOP_LERP,
        filterGroup_: ORIGINBLEND_BRANCH,
        alpha_: 1.0,
        a12: v31,
        a13: v34,
        a14: v37,
        a15: v40,
        a16: v43,
        a17: v46,
        a18: v49,
        a19: v52,
        a20: v55,
        a21: v58,
        a22: v61,
        a23: v64,
        a24: v67,
        a25: v70,
        a26: v73,
        a27: v76,
        a28: v79,
        a29: v82,
        a30: v85,
        a31: MD6_WEIGHTGROUP_ALL,
        a32: v88,
        a33: MD6_WEIGHTGROUP_ALL);
      v9 = gameLocal->GetGameTimeManager(this: gameLocal);
      idAnimator_Base::Init(this: &this->steeringAnimator, gametimeManager: v9, parms: &v94);
      v10 = this->GetAnimStack_2(this);
      v11 = idDeclMD6::AnimForAlias(this: decl, aliasHandle: &this->sweepUpDownAlias, load: false);
      idAnimatorParms_Pause::idAnimatorParms_Pause(
        this: &v93,
        anim_: v11,
        startFrame_: 0.0,
        normalizedStartFrame_: 0.5,
        animStack_: v13,
        name_: v12,
        blendOp_: v10,
        originBlend_: "speed",
        weightGroup_: BOP_LERP,
        filterGroup_: ORIGINBLEND_BRANCH,
        alpha_: 1.0,
        a12: v32,
        a13: v35,
        a14: v38,
        a15: v41,
        a16: v44,
        a17: v47,
        a18: v50,
        a19: v53,
        a20: v56,
        a21: v59,
        a22: v62,
        a23: v65,
        a24: v68,
        a25: v71,
        a26: v74,
        a27: v77,
        a28: v80,
        a29: v83,
        a30: v86,
        a31: MD6_WEIGHTGROUP_ALL,
        a32: v89,
        a33: MD6_WEIGHTGROUP_ALL);
      v14 = gameLocal->GetGameTimeManager(this: gameLocal);
      idAnimator_Base::Init(this: &this->speedAnimator, gametimeManager: v14, parms: &v93);
      if ( atv_bumpLeft.valueInteger != 0 )
        v15 = 1.0;
      else
        v15 = 0.0;
      v16 = this->GetAnimStack_2(this);
      v17 = idDeclMD6::AnimForAlias(this: decl, aliasHandle: &this->bumpAnimAliases[2], load: false);
      idAnimatorParms_Pause::idAnimatorParms_Pause(
        this: &v91,
        anim_: v17,
        startFrame_: 0.0,
        normalizedStartFrame_: -1.0,
        animStack_: v19,
        name_: v18,
        blendOp_: v16,
        originBlend_: "bump_left",
        weightGroup_: BOP_ADD_RIGHT,
        filterGroup_: ORIGINBLEND_BRANCH,
        alpha_: v15,
        a12: v33,
        a13: v36,
        a14: v39,
        a15: v42,
        a16: v45,
        a17: v48,
        a18: v51,
        a19: v54,
        a20: v57,
        a21: v60,
        a22: v63,
        a23: v66,
        a24: v69,
        a25: v72,
        a26: v75,
        a27: v78,
        a28: v81,
        a29: v84,
        a30: v87,
        a31: MD6_WEIGHTGROUP_ALL,
        a32: v90,
        a33: MD6_WEIGHTGROUP_ALL);
      v20 = gameLocal->GetGameTimeManager(this: gameLocal);
      idAnimator_Base::Init(this: &this->bumpLeftAnimator, gametimeManager: v20, parms: &v91);
      bumpAnimAliases = this->bumpAnimAliases;
      v91.anim = idDeclMD6::AnimForAlias(this: decl, aliasHandle: this->bumpAnimAliases, load: false);
      idStr::operator=(this: &v91.name, text: "bump_forward");
      if ( atv_bumpForward.valueInteger != 0 )
        v91.alpha = 1.0;
      else
        v91.alpha = 0.0;
      v22 = gameLocal->GetGameTimeManager(this: gameLocal);
      idAnimator_Base::Init(this: &this->bumpForwardAnimator, gametimeManager: v22, parms: &v91);
      v91.anim = idDeclMD6::AnimForAlias(this: decl, aliasHandle: &this->bumpAnimAliases[4], load: false);
      idStr::operator=(this: &v91.name, text: "bump_up");
      if ( atv_bumpUp.valueInteger != 0 )
        v91.alpha = 1.0;
      else
        v91.alpha = 0.0;
      v23 = gameLocal->GetGameTimeManager(this: gameLocal);
      idAnimator_Base::Init(this: &this->bumpUpAnimator, gametimeManager: v23, parms: &v91);
      v91.anim = idDeclMD6::AnimForAlias(this: decl, aliasHandle: &this->bumpAnimAliases[5], load: false);
      idStr::operator=(this: &v91.name, text: "boost");
      v91.alpha = 0.0;
      v24 = gameLocal->GetGameTimeManager(this: gameLocal);
      idAnimator_Base::Init(this: &this->boostAnimator, gametimeManager: v24, parms: &v91);
      v25 = (const idDeclReachIK *)idDeclInfo::FindWithInheritance(
                                     this: &idDeclReachIK::resourceList,
                                     name: "player/driver/atv",
                                     makeDefault: true);
      if ( v25 == nullptr )
        idLib::Error(fmt: "Could not find reach ik '%s'", "player/driver/atv");
      entityNumber = this->entityNumber;
      v27 = this->GetAnimStack_2(this);
      idAnimatorParms_ReachIK::idAnimatorParms_ReachIK(
        this: &v92,
        declReachIK_: v25,
        entityNum_: entityNumber,
        clip_: &clientGame->clip,
        animStack_: v27,
        name_: "reachIK",
        alpha_: 1.0);
      v28 = gameLocal->GetGameTimeManager(this: gameLocal);
      idAnimator_Base::Init(this: &this->reachIKAnimator, gametimeManager: v28, parms: &v92);
      v29 = this->GetAnimStack_2(this);
      idAnimator_Base::SetEnabled(this: &this->reachIKAnimator, animStack: v29, enabled: false);
      for ( i = 6; i != 0; --i )
        gameAnimTools->VerifyStrongAliasRefs(this: gameAnimTools, a2: v4, a3: bumpAnimAliases++, a4: this->name.data);
      gameAnimTools->VerifyStrongAliasRefs(
        this: gameAnimTools,
        a2: v4,
        a3: &this->sweepLeftRightAlias,
        a4: this->name.data);
      gameAnimTools->VerifyStrongAliasRefs(
        this: gameAnimTools,
        a2: v4,
        a3: &this->sweepUpDownAlias,
        a4: this->name.data);
      idStr::FreeData(this: &v92.name);
      idStr::FreeData(this: &v91.name);
      idStr::FreeData(this: &v93.name);
      idStr::FreeData(this: &v94.name);
    }
  }
}


// ========================================================================
// $LN85_1
// EA  : 0x82D34788
// RVA : 0x00D34788
// PDB : w:\tech5\tungsten\game\entities\vehicleoccupants.cpp
// ========================================================================

void _LN85_1()
{
  int v0; // r12

  idAnimatorParms_EndAdditiveChannels::~idAnimatorParms_EndAdditiveChannels(this: (vaiAction_t::vehicleCam_t *)(v0 - 528 + 352));
}


// ========================================================================
// __unwind$493710
// EA  : 0x82D347B0
// RVA : 0x00D347B0
// PDB : w:\tech5\tungsten\game\entities\vehicleoccupants.cpp
// ========================================================================

void _unwind_493710()
{
  int v0; // r12

  idAnimatorParms_EndAdditiveChannels::~idAnimatorParms_EndAdditiveChannels(this: (vaiAction_t::vehicleCam_t *)(v0 - 528 + 272));
}


// ========================================================================
// __unwind$493711
// EA  : 0x82D347D8
// RVA : 0x00D347D8
// PDB : w:\tech5\tungsten\game\entities\vehicleoccupants.cpp
// ========================================================================

void _unwind_493711()
{
  int v0; // r12

  idAnimatorParms_EndAdditiveChannels::~idAnimatorParms_EndAdditiveChannels(this: (vaiAction_t::vehicleCam_t *)(v0 - 528 + 112));
}


// ========================================================================
// __unwind$493712
// EA  : 0x82D34800
// RVA : 0x00D34800
// PDB : w:\tech5\tungsten\game\entities\vehicleoccupants.cpp
// ========================================================================

void _unwind_493712()
{
  int v0; // r12

  idAnimatorParms_EndAdditiveChannels::~idAnimatorParms_EndAdditiveChannels(this: (vaiAction_t::vehicleCam_t *)(v0 - 528 + 192));
}


// ========================================================================
// ?InternalEnterVehicle@idVehicleOccupant_ATV@@MAAXPAVidVehicle@@PAVidTreeAnimator@@PBD@Z
// EA  : 0x82D34828
// RVA : 0x00D34828
// PDB : w:\tech5\tungsten\game\entities\vehicleoccupants.cpp
// ========================================================================

void __fastcall idVehicleOccupant_ATV::InternalEnterVehicle(
        idVehicleOccupant_ATV *this,
        idVehicle *vehicle,
        idTreeAnimator *tagAnimator,
        const char *tagName)
{
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idPresentable *presentable; // r11
  idTreeAnimator *v8; // r30
  int v9; // r29
  const idAnimStack *v10; // r3
  int v11; // r26
  const idAnimStack *v12; // r3
  __int64 v13; // r6
  int v14; // r4
  __int64 v15; // r6
  int v16; // r4
  int v17; // r30
  const idAnimStack *v18; // r3
  int v19; // r30
  const idAnimStack *v20; // r3
  int v21; // r30
  const idAnimStack *v22; // r3
  idPhysics *Physics; // r3
  float *v24; // r3
  double v25; // fp0
  idTreeAnimator *v26; // r3
  idPresentable *v27; // r11
  idTreeAnimator *v28; // r30
  idPropsCollection *decl; // r11
  idPropsCollection *v30; // r30
  idAnimStack *v31; // r3

  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
  presentable = this->presentable;
  v8 = TreeAnimatorFromPresentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    presentable = this->presentable;
  }
  idPresentable::UpdateModelTransform(this: presentable);
  if ( v8 != nullptr )
  {
    v9 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
    v10 = this->GetAnimStack_2(this);
    idAnimator_Base::Start(this: &this->steeringAnimator, stack: v10, curTime: v9, blendDurationMS: 0, reset: true);
    v11 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
    v12 = this->GetAnimStack_2(this);
    idAnimator_Base::Start(this: &this->speedAnimator, stack: v12, curTime: v11, blendDurationMS: 0, reset: true);
    idAnimator_Paused::SetNormalizedFrame(this: &this->steeringAnimator, nf: 0.5, a3: v14, a4: v13);
    idAnimator_Base::SetAlpha(this: &this->steeringAnimator, alpha: 0.5);
    idAnimator_Paused::SetNormalizedFrame(this: &this->speedAnimator, nf: 0.5, a3: v16, a4: v15);
    idAnimator_Base::SetAlpha(this: &this->speedAnimator, alpha: 0.5);
    if ( atv_bumpLeft.valueInteger != 0 )
    {
      v17 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
      v18 = this->GetAnimStack_2(this);
      idAnimator_Base::Start(this: &this->bumpLeftAnimator, stack: v18, curTime: v17, blendDurationMS: 0, reset: true);
    }
    if ( atv_bumpForward.valueInteger != 0 )
    {
      v19 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
      v20 = this->GetAnimStack_2(this);
      idAnimator_Base::Start(
        this: &this->bumpForwardAnimator,
        stack: v20,
        curTime: v19,
        blendDurationMS: 0,
        reset: true);
    }
    if ( atv_bumpUp.valueInteger != 0 )
    {
      v21 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
      v22 = this->GetAnimStack_2(this);
      idAnimator_Base::Start(this: &this->bumpUpAnimator, stack: v22, curTime: v21, blendDurationMS: 0, reset: true);
    }
    Physics = idEntity::GetPhysics(this: vehicle);
    v24 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
    v25 = *v24;
    this->bumpSpring.p0.x = *v24;
    this->bumpSpring.p0.y = v24[1];
    this->bumpSpring.p0.z = v24[2];
    this->bumpSpring.p1.x = v25;
    this->bumpSpring.p1.y = this->bumpSpring.p0.y;
    this->bumpSpring.p1.z = this->bumpSpring.p0.z;
    this->bumpSpring.vel.z = 0.0;
    this->bumpSpring.vel.y = 0.0;
    this->bumpSpring.vel.x = 0.0;
    v26 = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: vehicle);
    v27 = vehicle->presentable;
    v28 = v26;
    if ( v27 == nullptr )
    {
      idEntity::InitPresentableInternal(this: vehicle);
      v27 = vehicle->presentable;
    }
    idPresentable::UpdateModelTransform(this: v27);
    decl = (idPropsCollection *)v28->decl;
    v30 = decl + 22;
    if ( decl == nullptr )
      v30 = nullptr;
    this->leftTagData = *idPropsCollection::GetTag(
                           this: v30,
                           propName: idPropInfo::INFO_PROP_NAME,
                           tagName: "handlebar_left");
    this->rightTagData = *idPropsCollection::GetTag(
                            this: v30,
                            propName: idPropInfo::INFO_PROP_NAME,
                            tagName: "handlebar_right");
    if ( atv_ikArms.valueInteger != 0 )
    {
      v31 = this->GetAnimStack_2(this);
      idAnimator_Base::SetEnabled(this: &this->reachIKAnimator, animStack: v31, enabled: true);
    }
  }
}


// ========================================================================
// ??0idVehicleOccupant@@QAA@XZ
// EA  : 0x82D34C08
// RVA : 0x00D34C08
// PDB : w:\tech5\tungsten\game\entities\vehicleoccupants.cpp
// ========================================================================

idVehicleOccupant *__fastcall idVehicleOccupant::idVehicleOccupant(idVehicleOccupant *this)
{
  idAnimatedEntity::idAnimatedEntity(this);
  this->__vftable = (idVehicleOccupant_vtbl *)&idVehicleOccupant::`vftable';
  this->vehicle.spawnId.value = 0x1FFF;
  idFaceMgr::idFaceMgr(this: &this->faceMgr);
  this->nextVoiceTime = 0;
  this->exitDelayTime = 0;
  this->lookingAt.spawnId.value = 0x1FFF;
  this->lookAtWeight = 0.0;
  this->lookAtTime = 0;
  this->forceLookAtTime = 0;
  this->tagAnimator = nullptr;
  this->tagData.trans.x = 0.0;
  this->tagData.trans.y = 0.0;
  this->tagData.trans.z = 0.0;
  this->tagData.rot.x = 0.0;
  this->tagData.rot.y = 0.0;
  this->tagData.rot.z = 0.0;
  this->tagData.rot.w = 0.0;
  this->tagData.parentJoint.value = -1;
  idAnimator_AF::idAnimator_AF(this: &this->afProperties);
  this->thrownEntity.spawnId.value = 0x1FFF;
  this->linkedPlayer = nullptr;
  this->thrown = false;
  this->usesFaceManager = false;
  this->timeStartThrown = 0;
  this->subtitleName.index = -1;
  this->vehicleOccupantPhysicsCallbacks.ent.spawnId.value = 0x1FFF;
  this->vehicleOccupantPhysicsCallbacks.__vftable = (idVehicleOccupantPhysicsCallbacks_vtbl *)&idVehicleOccupantPhysicsCallbacks::`vftable';
  this->vehicleOccupantPhysicsCallbacks.af = nullptr;
  this->vehicleOccupantPhysicsCallbacks.occupant = nullptr;
  return this;
}


// ========================================================================
// __unwind$494344_0
// EA  : 0x82D34D14
// RVA : 0x00D34D14
// PDB : w:\tech5\tungsten\game\entities\vehicleoccupants.cpp
// ========================================================================

void _unwind_494344_0()
{
  int v0; // r12

  idAnimatedEntity::~idAnimatedEntity(this: *(idAnimatedEntity **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$494345_0
// EA  : 0x82D34D3C
// RVA : 0x00D34D3C
// PDB : w:\tech5\tungsten\game\entities\vehicleoccupants.cpp
// ========================================================================

void _unwind_494345_0()
{
  int v0; // r12

  idFaceMgr::~idFaceMgr(this: (idFaceMgr *)(*(_DWORD *)(v0 - 128 + 148) + 5204));
}


// ========================================================================
// ?ExitVehicle@idVehicleOccupant@@QAAXHPAVidEntity@@@Z
// EA  : 0x82D34D68
// RVA : 0x00D34D68
// PDB : w:\tech5\tungsten\game\entities\vehicleoccupants.cpp
// ========================================================================

void __fastcall idVehicleOccupant::ExitVehicle(
        idVehicleOccupant *this,
        const int delayTime,
        idEntity *entityToBeThrown)
{
  idPresentable *presentable; // r11
  char v6; // r10
  idPresentable *v7; // r3
  idPhysics *Physics; // r3
  idPhysics *v9; // r3
  idPresentable *v10; // r11
  idIndex<short,enum invalidJointIndex_t> *value; // r30
  idPresentable *v12; // r11
  idPresentable *v13; // r11
  float v14[4]; // [sp+50h] [-60h] BYREF
  float v15[20]; // [sp+60h] [-50h] BYREF

  if ( delayTime <= 0 )
  {
    this->InternalExitVehicle(this);
    presentable = this->presentable;
    if ( presentable == nullptr || (v6 = 1, presentable->model == nullptr) )
      v6 = 0;
    if ( v6 != 0 )
    {
      if ( presentable == nullptr )
      {
        idEntity::InitPresentableInternal(this);
        presentable = this->presentable;
      }
      idPresentable::SetGroupMaster(this: presentable, pres: nullptr);
    }
    if ( entityToBeThrown != nullptr )
    {
      this->thrownEntity.spawnId.value = (gameLocal->spawnIds.ptr[entityToBeThrown->entityNumber] << 13)
                                       | entityToBeThrown->entityNumber;
      v7 = this->presentable;
      if ( v7 == nullptr )
      {
        idEntity::InitPresentableInternal(this);
        v7 = this->presentable;
      }
      v7->GetWorldTransform(this: v7, a2: (idVec3 *)v14, a3: (idMat3 *)v15);
      Physics = idEntity::GetPhysics(this);
      Physics->SetOrigin(this: Physics, a2: (const idVec3 *)v14, a3: -1);
      v9 = idEntity::GetPhysics(this);
      v9->SetAxis(this: v9, a2: (const idMat3 *)v15, a3: -1);
      v10 = this->presentable;
      value = (idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)NULL_JOINT_INDEX.value;
      if ( v10 == nullptr )
      {
        idEntity::InitPresentableInternal(this);
        v10 = this->presentable;
      }
      idPresentable::SetParent(this: v10, p: nullptr, j: value);
      v12 = this->presentable;
      if ( v12 == nullptr )
      {
        idEntity::InitPresentableInternal(this);
        v12 = this->presentable;
      }
      v12->origin.x = v14[0];
      v12->origin.y = v14[1];
      v12->origin.z = v14[2];
      v13 = this->presentable;
      if ( v13 == nullptr )
      {
        idEntity::InitPresentableInternal(this);
        v13 = this->presentable;
      }
      qmemcpy(&v13->axis, v15, sizeof(v13->axis));
      this->tagAnimator = nullptr;
      this->vehicle.spawnId.value = 0x1FFF;
    }
    else
    {
      this->Hide_2(this);
      this->vehicle.spawnId.value = 0x1FFF;
    }
  }
  else
  {
    this->exitDelayTime = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) + delayTime;
  }
}


// ========================================================================
// ?TransformVisual@idVehicleOccupant@@QAAXXZ
// EA  : 0x82D34FB0
// RVA : 0x00D34FB0
// PDB : w:\tech5\tungsten\game\entities\vehicleoccupants.cpp
// ========================================================================

void __fastcall idVehicleOccupant::TransformVisual(idVehicleOccupant *this)
{
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idPresentable *presentable; // r11
  idTreeAnimator *v4; // r30
  idTreeAnimator *tagAnimator; // r3
  idPhysics *v6; // r3
  idPhysics *v7; // r3
  idPresentable *v8; // r11
  idPresentable *v9; // r30
  idVehicle *v10; // r3
  idVehicle *v11; // r30
  idPresentable *v12; // r30
  idPresentable *v13; // r3
  idVehicle *Entity; // r3
  idPhysics *Physics; // r29
  idPhysics *v16; // r28
  idPhysics *v17; // r3
  idPhysics_vtbl *v18; // r29
  const idVec3 *(__fastcall *GetOrigin)(idPhysics *, int); // ctr
  int v20; // r3
  idVehicle *v21; // r3
  idPhysics *v22; // r30
  idPhysics *v23; // r31
  idPhysics *v24; // r3
  idPhysics_vtbl *v25; // r30
  const idMat3 *(__fastcall *GetAxis)(idPhysics *, int); // ctr
  int v27; // r3
  unsigned __int16 v28; // [sp+50h] [-A0h] BYREF
  idVec3 v29[2]; // [sp+58h] [-98h] BYREF
  idMat3 v30; // [sp+70h] [-80h] BYREF
  idQuat v31; // [sp+A0h] [-50h] BYREF

  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
  presentable = this->presentable;
  v4 = TreeAnimatorFromPresentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    presentable = this->presentable;
  }
  idPresentable::UpdateModelTransform(this: presentable);
  if ( v4 != nullptr )
  {
    tagAnimator = this->tagAnimator;
    if ( tagAnimator != nullptr )
    {
      if ( this->tagData.parentJoint.value == 0xFFFF )
      {
        Entity = idEntityPtr<idVehicle>::GetEntity(this: &this->vehicle);
        Physics = idEntity::GetPhysics(this: Entity);
        v16 = idEntity::GetPhysics(this);
        v17 = Physics;
        GetOrigin = Physics->GetOrigin;
        v18 = v16->__vftable;
        v20 = (int)GetOrigin(this: v17, a2: 0);
        v18->SetOrigin(this: v16, a2: (const idVec3 *)v20, a3: -1);
        v21 = idEntityPtr<idVehicle>::GetEntity(this: &this->vehicle);
        v22 = idEntity::GetPhysics(this: v21);
        v23 = idEntity::GetPhysics(this);
        v24 = v22;
        GetAxis = v22->GetAxis;
        v25 = v23->__vftable;
        v27 = (int)GetAxis(this: v24, a2: 0);
        v25->SetAxis(this: v23, a2: (const idMat3 *)v27, a3: -1);
      }
      else
      {
        idTreeAnimator::GetWorldSpaceTagTransform(this: tagAnimator, tagData: &this->tagData, origin: v29, axis: &v30);
        v6 = idEntity::GetPhysics(this);
        v6->SetOrigin(this: v6, a2: v29, a3: -1);
        v7 = idEntity::GetPhysics(this);
        v7->SetAxis(this: v7, a2: &v30, a3: -1);
        idTreeAnimator::GetJointIndex(
          this: (idTreeAnimator *)&v28,
          result: (idIndex<short,enum invalidJointIndex_t> *)this->tagAnimator,
          jointHandle: &this->tagData.parentJoint);
        v8 = this->presentable;
        if ( v8 == nullptr )
        {
          idEntity::InitPresentableInternal(this);
          v8 = this->presentable;
        }
        v8->origin.x = this->tagData.trans.x;
        v8->origin.y = this->tagData.trans.y;
        v8->origin.z = this->tagData.trans.z;
        v9 = this->presentable;
        if ( v9 == nullptr )
        {
          idEntity::InitPresentableInternal(this);
          v9 = this->presentable;
        }
        v9->axis = *idQuat::ToMat3(this: &v31, result: (idMat3 *)&this->tagData.rot);
        v10 = idEntityPtr<idVehicle>::GetEntity(this: &this->vehicle);
        v11 = v10;
        if ( v10->presentable != nullptr )
        {
          v12 = v10->presentable;
        }
        else
        {
          idEntity::InitPresentableInternal(this: v10);
          v12 = v11->presentable;
        }
        v13 = this->presentable;
        if ( v13 == nullptr )
        {
          idEntity::InitPresentableInternal(this);
          v13 = this->presentable;
        }
        idPresentable::SetParent(this: v13, p: v12, j: (idIndex<short,enum invalidJointIndex_t> *)v28);
      }
    }
  }
}


// ========================================================================
// ?Think@idVehicleOccupant@@UAAXXZ
// EA  : 0x82D35218
// RVA : 0x00D35218
// PDB : w:\tech5\tungsten\game\entities\vehicleoccupants.cpp
// ========================================================================

void __fastcall idVehicleOccupant::Think(idVehicleOccupant *this)
{
  idEntityPtr<idVehicle> *p_vehicle; // r29
  idGameLocal *v3; // r3
  idVehicleOccupant_vtbl *v4; // r10
  idPresentable *presentable; // r11
  char v6; // r10
  idVehicle *Entity; // r30
  idVehicleOccupant_vtbl *v8; // r29
  double SteerAngle; // fp1
  idTreeAnimator *TreeAnimatorFromPresentable; // r30
  const idVec3 *v11; // r3
  bool v12; // r30
  int v13; // r3
  idPresentable *v14; // r11
  idPresentable *v15; // r11
  idPlayer *v16; // r3
  idPlayer *v17; // r3
  idEntity *thrownCamera; // r30
  idPhysics *Physics; // r3
  idBounds *v20; // r3

  if ( vehicle_occupant_disable_all.valueInteger != 0 )
  {
    idEntity::BecomeInactive(this, flags: 2);
    idEntity::BecomeInactive(this, flags: 4);
    this->Hide_2(this);
    return;
  }
  if ( vehicle_occupant_disable_anim.valueInteger != 0 )
  {
    idEntity::BecomeInactive(this, flags: 2);
    idEntity::BecomeInactive(this, flags: 4);
    idEntity::UpdateVisuals(this);
    return;
  }
  if ( (unsigned __int8)idEntity::UpdateDormant(this) == 0 )
  {
    idEntity::BecomeActive(this, flags: 4);
    idAnimatedEntity::UpdateFrameCommands(this);
    p_vehicle = &this->vehicle;
    v3 = gameLocal;
    if ( gameLocal->spawnIds.ptr[this->vehicle.spawnId.value & 0x1FFF] != this->vehicle.spawnId.value >> 13 )
    {
      if ( idEntityPtr<idEntity const>::operator->(this: &this->thrownEntity) == nullptr )
        return;
      v3 = gameLocal;
    }
    if ( v3->spawnIds.ptr[p_vehicle->spawnId.value & 0x1FFF] == p_vehicle->spawnId.value >> 13
      && this->exitDelayTime > 0
      && v3->GetGameMs(this: v3, a2: GAMETIME_SCALED) > this->exitDelayTime )
    {
      v4 = this->__vftable;
      this->exitDelayTime = 0;
      v4->InternalExitVehicle(this);
      presentable = this->presentable;
      if ( presentable == nullptr || (v6 = 1, presentable->model == nullptr) )
        v6 = 0;
      if ( v6 != 0 )
      {
        if ( presentable == nullptr )
        {
          idEntity::InitPresentableInternal(this);
          presentable = this->presentable;
        }
        idPresentable::SetGroupMaster(this: presentable, pres: nullptr);
      }
      this->Hide_2(this);
      p_vehicle->spawnId.value = 0x1FFF;
    }
    else
    {
      idEntity::BecomeActive(this, flags: 2);
      if ( g_stopTime.valueInteger == 0 || g_runFrames.valueInteger > 0 )
        idEntity::TouchTriggers(this);
      if ( gameLocal->spawnIds.ptr[p_vehicle->spawnId.value & 0x1FFF] == p_vehicle->spawnId.value >> 13 )
      {
        idVehicleOccupant::TransformVisual(this);
        Entity = idEntityPtr<idVehicle>::GetEntity(this: &this->vehicle);
        if ( idAnimatedEntity::GetTreeAnimatorFromPresentable(this) != nullptr && Entity != nullptr )
        {
          v8 = this->__vftable;
          SteerAngle = idVehicle::GetSteerAngle(this: Entity);
          v8->InternalUpdateAnimations(this, a2: SteerAngle);
          if ( this->usesFaceManager )
          {
            TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
            v11 = this->GetLookPoint(this);
            idFaceMgr::Update(
              this: &this->faceMgr,
              owner: (idAI2 *)this,
              ta: TreeAnimatorFromPresentable,
              focusPoint: v11);
          }
        }
      }
      else
      {
        v12 = idEntity::GetPhysics(this) != (idPhysics *)&this->afProperties.physicsObj;
        v13 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
        idAnimator_AF::Sync(this: &this->afProperties, time: v13, runPhysics: v12);
        idEntity::RunPhysics(this);
        if ( idEntityPtr<idEntity const>::operator->(this: &this->thrownEntity) != nullptr )
        {
          v14 = this->presentable;
          if ( v14 == nullptr )
          {
            idEntity::InitPresentableInternal(this);
            v14 = this->presentable;
          }
          idEntity::SetOrigin(this, org: &v14->origin);
          v15 = this->presentable;
          if ( v15 == nullptr )
          {
            idEntity::InitPresentableInternal(this);
            v15 = this->presentable;
          }
          this->SetAxis(this, a2: &v15->axis);
          v16 = (idPlayer *)idEntityPtr<idEntity const>::operator->(this: &this->thrownEntity);
          v17 = idPlayer::CastTo(c: v16);
          if ( v17 != nullptr )
          {
            thrownCamera = v17->thrownCamera;
            if ( thrownCamera != idPlayer::GetControl(this: v17) )
              idEventReceiver::PostEventMS(this, ev: &EV_Remove, time: 0);
          }
        }
      }
      idAnimatedEntity::UpdateAnimation(this, forceNonDeferredBlend: false);
      idEntity::UpdateVisuals(this);
      Physics = idEntity::GetPhysics(this);
      v20 = (idBounds *)Physics->GetAbsBounds(this: Physics, a2: -1);
      idEntity::UpdatePVSAreas(this, bounds: v20);
      idEntity::BecomeActive(this, flags: 1);
    }
  }
}


// ========================================================================
// ?ForceOccupantLookAt@idVehicleOccupant@@QAAXPAVidEntity@@H@Z
// EA  : 0x82D35608
// RVA : 0x00D35608
// PDB : w:\tech5\tungsten\game\entities\vehicleoccupants.cpp
// ========================================================================

void __fastcall idVehicleOccupant::ForceOccupantLookAt(idVehicleOccupant *this, idEntity *target, int time)
{
  if ( target != nullptr )
    this->lookingAt.spawnId.value = (gameLocal->spawnIds.ptr[target->entityNumber] << 13) | target->entityNumber;
  else
    this->lookingAt.spawnId.value = 0x1FFF;
  this->forceLookAtTime = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) + time;
}


// ========================================================================
// ??1idVehicleOccupant_Car@@UAA@XZ
// EA  : 0x82D356A0
// RVA : 0x00D356A0
// PDB : w:\tech5\tungsten\game\entities\vehicleoccupants.cpp
// ========================================================================

void __fastcall idVehicleOccupant_Car::~idVehicleOccupant_Car(idVehicleOccupant_Car *this)
{
  this->__vftable = (idVehicleOccupant_Car_vtbl *)&idVehicleOccupant_Car::`vftable';
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->painAnimations);
  idAnimator_Pain::~idAnimator_Pain(this: &this->painAnimator);
  idAnimator_TorsoTracker::~idAnimator_TorsoTracker(this: &this->torsoAnimator);
  idAnimator_Paused::~idAnimator_Paused(this: &this->bumpForwardAnimator);
  idAnimator_Paused::~idAnimator_Paused(this: &this->bumpLeftAnimator);
  idAnimator_EndAdditiveChannels::~idAnimator_EndAdditiveChannels(this: &this->additiveShakeAnimator);
  idAnimator_Channel::~idAnimator_Channel(this: &this->passengerAnimator);
  idAnimator_Paused::~idAnimator_Paused(this: &this->steeringAnimator);
  idAnimator_Synced::~idAnimator_Synced(this: &this->headAnimator);
  idVehicleOccupant::~idVehicleOccupant(this);
}


// ========================================================================
// __unwind$495356
// EA  : 0x82D35734
// RVA : 0x00D35734
// PDB : w:\tech5\tungsten\game\entities\vehicleoccupants.cpp
// ========================================================================

void _unwind_495356()
{
  int v0; // r12

  idVehicleOccupant::~idVehicleOccupant(this: *(idVehicleOccupant **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$495357
// EA  : 0x82D3575C
// RVA : 0x00D3575C
// PDB : w:\tech5\tungsten\game\entities\vehicleoccupants.cpp
// ========================================================================

void _unwind_495357()
{
  int v0; // r12

  idAnimator_Synced::~idAnimator_Synced(this: (idAnimator_Synced *)(*(_DWORD *)(v0 - 112 + 132) + 8856));
}


// ========================================================================
// __unwind$495358
// EA  : 0x82D35788
// RVA : 0x00D35788
// PDB : w:\tech5\tungsten\game\entities\vehicleoccupants.cpp
// ========================================================================

void _unwind_495358()
{
  int v0; // r12

  idAnimator_Paused::~idAnimator_Paused(this: (idAnimator_Paused *)(*(_DWORD *)(v0 - 112 + 132) + 9144));
}


// ========================================================================
// __unwind$495359
// EA  : 0x82D357B4
// RVA : 0x00D357B4
// PDB : w:\tech5\tungsten\game\entities\vehicleoccupants.cpp
// ========================================================================

void _unwind_495359()
{
  int v0; // r12

  idAnimator_Channel::~idAnimator_Channel(this: (idAnimator_Channel *)(*(_DWORD *)(v0 - 112 + 132) + 9196));
}


// ========================================================================
// __unwind$495360
// EA  : 0x82D357E0
// RVA : 0x00D357E0
// PDB : w:\tech5\tungsten\game\entities\vehicleoccupants.cpp
// ========================================================================

void _unwind_495360()
{
  int v0; // r12

  idAnimator_EndAdditiveChannels::~idAnimator_EndAdditiveChannels(this: (idAnimator_EndAdditiveChannels *)(*(_DWORD *)(v0 - 112 + 132) + 9292));
}


// ========================================================================
// __unwind$495361
// EA  : 0x82D3580C
// RVA : 0x00D3580C
// PDB : w:\tech5\tungsten\game\entities\vehicleoccupants.cpp
// ========================================================================

void _unwind_495361()
{
  int v0; // r12

  idAnimator_Paused::~idAnimator_Paused(this: (idAnimator_Paused *)(*(_DWORD *)(v0 - 112 + 132) + 9460));
}


// ========================================================================
// __unwind$495362
// EA  : 0x82D35838
// RVA : 0x00D35838
// PDB : w:\tech5\tungsten\game\entities\vehicleoccupants.cpp
// ========================================================================

void _unwind_495362()
{
  int v0; // r12

  idAnimator_Paused::~idAnimator_Paused(this: (idAnimator_Paused *)(*(_DWORD *)(v0 - 112 + 132) + 9512));
}


// ========================================================================
// __unwind$495363
// EA  : 0x82D35864
// RVA : 0x00D35864
// PDB : w:\tech5\tungsten\game\entities\vehicleoccupants.cpp
// ========================================================================

void _unwind_495363()
{
  int v0; // r12

  idAnimator_TorsoTracker::~idAnimator_TorsoTracker(this: (idAnimator_TorsoTracker *)(*(_DWORD *)(v0 - 112 + 132) + 9564));
}


// ========================================================================
// __unwind$495364
// EA  : 0x82D35890
// RVA : 0x00D35890
// PDB : w:\tech5\tungsten\game\entities\vehicleoccupants.cpp
// ========================================================================

void _unwind_495364()
{
  int v0; // r12

  idAnimator_Pain::~idAnimator_Pain(this: (idAnimator_Pain *)(*(_DWORD *)(v0 - 112 + 132) + 9752));
}


// ========================================================================
// ?InternalUpdateAnimations@idVehicleOccupant_Car@@MAAXM@Z
// EA  : 0x82D35918
// RVA : 0x00D35918
// PDB : w:\tech5\tungsten\game\entities\vehicleoccupants.cpp
// ========================================================================

void __fastcall idVehicleOccupant_Car::InternalUpdateAnimations(idVehicleOccupant_Car *this, double currentAngle)
{
  int value; // r10
  idVehicle *v5; // r3
  idVehicle *v6; // r25
  double v7; // fp1
  double v8; // fp0
  int v9; // r9
  idEntity *v10; // r3
  int v11; // r9
  idEntity *v12; // r3
  idEntity *v13; // r3
  idPresentable *presentable; // r3
  int v15; // r11
  double v16; // fp31
  double v17; // fp1
  double v18; // fp0
  int GameMs; // r31
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idPhysics *Physics; // r3
  int v22; // r3
  char *v23; // r10
  _DWORD *v24; // r11
  int i; // ctr
  idPhysics *v26; // r3
  float *v27; // r3
  double v28; // fp1
  double v29; // fp13
  double v30; // fp25
  double v31; // fp12
  double v32; // fp24
  double v33; // fp11
  double v34; // fp23
  double v35; // fp0
  idMD6Leaf::wrapMode_t v36; // r5
  double v37; // fp10
  double valueFloat; // fp9
  double v39; // fp0
  double v40; // fp28
  double v41; // fp29
  double v42; // fp27
  double v43; // fp26
  double v44; // fp13
  double v45; // fp0
  double v49; // fp0
  double v50; // fp30
  idPhysics *v51; // r3
  __int64 v52; // r6
  __int64 v53; // r10
  __int64 v54; // r8
  va *v55; // r3
  __int64 v56; // r10
  __int64 v57; // r6
  __int64 v58; // r8
  va *v59; // r3
  double z; // fp8
  double x; // fp0
  double y; // fp12
  double v63; // fp31
  idAnimator_Paused *p_bumpLeftAnimator; // r3
  double v65; // fp1
  double v66; // fp31
  idAnimator_Paused *p_bumpForwardAnimator; // r3
  double v68; // fp1
  int v69; // [sp+8h] [-1198h]
  int v70; // [sp+8h] [-1198h]
  int v71; // [sp+Ch] [-1194h]
  int v72; // [sp+Ch] [-1194h]
  int v73; // [sp+10h] [-1190h]
  int v74; // [sp+10h] [-1190h]
  int v75; // [sp+14h] [-118Ch]
  int v76; // [sp+14h] [-118Ch]
  int v77; // [sp+18h] [-1188h]
  int v78; // [sp+18h] [-1188h]
  int v79; // [sp+1Ch] [-1184h]
  int v80; // [sp+1Ch] [-1184h]
  double v81; // [sp+20h] [-1180h]
  double v82; // [sp+20h] [-1180h]
  idMD6Leaf::wrapMode_t v83[2]; // [sp+60h] [-1140h] BYREF
  float v84; // [sp+68h] [-1138h] BYREF
  float v85; // [sp+6Ch] [-1134h]
  float v86; // [sp+70h] [-1130h]
  float v87[4]; // [sp+78h] [-1128h] BYREF
  float v88[5]; // [sp+88h] [-1118h] BYREF
  char v89; // [sp+9Ch] [-1104h] BYREF
  float v90; // [sp+A0h] [-1100h]
  float v91; // [sp+A4h] [-10FCh]
  float v92; // [sp+A8h] [-10F8h]
  float v93; // [sp+ACh] [-10F4h]
  float v94; // [sp+B0h] [-10F0h]
  float v95; // [sp+B4h] [-10ECh]
  char v96; // [sp+C8h] [-10D8h] BYREF
  va v97; // [sp+E0h] [-10C0h] BYREF

  value = this->vehicle.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v5 = (idVehicle *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v6 = idVehicle::CastTo(c: v5);
  }
  else
  {
    v6 = nullptr;
  }
  if ( idVehicle::GetOccupantVisual(this: v6, index: 0) == this )
  {
    if ( this->steeringMaxAngle == 0.0 )
    {
      v7 = (float)(this->numSteeringFrames * (float)0.5);
LABEL_14:
      idAnimator_Paused::SetFrame(this: &this->steeringAnimator, frame: v7);
      goto LABEL_15;
    }
    v8 = (float)((float)currentAngle / this->steeringMaxAngle);
    if ( v8 >= -1.0 )
    {
      if ( v8 > 1.0 )
        v8 = 1.0;
    }
    else
    {
      v8 = -1.0;
    }
    if ( this->numSteeringFrames > 0.0 )
    {
      v7 = (float)((float)((float)((float)v8 + (float)1.0) * this->numSteeringFrames) * (float)0.5);
      goto LABEL_14;
    }
  }
LABEL_15:
  v9 = this->lookEntity.spawnId.value;
  if ( gameLocal->spawnIds.ptr[v9 & 0x1FFF] == v9 >> 13 )
  {
    v10 = gameLocal->entities.ptr[v9 & 0x1FFF];
    if ( v10 != nullptr && idEntity::CastTo(c: v10) != nullptr )
    {
      v11 = this->lookEntity.spawnId.value;
      if ( gameLocal->spawnIds.ptr[v11 & 0x1FFF] == v11 >> 13
        && (v12 = gameLocal->entities.ptr[v11 & 0x1FFF]) != nullptr )
      {
        v13 = idEntity::CastTo(c: v12);
      }
      else
      {
        v13 = nullptr;
      }
      v13->GetAimPoint(this: v13, a2: this->lookAimPoint, a3: &this->lookPoint);
    }
  }
  this->torsoAnimator.focusPoint.x = this->lookPoint.x;
  this->torsoAnimator.focusPoint.y = this->lookPoint.y;
  this->torsoAnimator.focusPoint.z = this->lookPoint.z;
  if ( (*((_BYTE *)this + 10026) & 0x20) != 0 )
  {
    presentable = v6->presentable;
    if ( presentable != nullptr )
      v15 = (int)presentable->GetVehicleInterface(this: presentable);
    else
      v15 = 0;
    v16 = *(float *)(v15 + 17864);
    v17 = ((double (__fastcall *)(idVehicle *))v6->GetMaxSpeed)(a1: v6);
    v18 = (float)((float)v16 / (float)((float)v17 * (float)0.5));
    if ( v18 >= 0.0 )
    {
      if ( v18 <= 2.0 )
        *(float *)v83 = (float)v16 / (float)((float)v17 * (float)0.5);
      else
        *(float *)v83 = 2.0;
    }
    else
    {
      *(float *)v83 = 0.0;
    }
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
    idAnimator_EndAdditiveChannels::SetAnimHandlesAndWeights(
      this: &this->additiveShakeAnimator,
      animator: TreeAnimatorFromPresentable,
      curTime: GameMs,
      handles: &this->additiveShakeAnim,
      numAnims: 1,
      weights: (const float *)v83,
      numWeights: 1);
  }
  if ( (*((_BYTE *)this + 10026) & 0x40) != 0 )
  {
    Physics = idEntity::GetPhysics(this: v6);
    v22 = (int)Physics->GetAxis(this: Physics, a2: 0);
    v23 = &v89;
    v24 = (_DWORD *)(v22 - 4);
    for ( i = 9; i != 0; --i )
    {
      ++v24;
      v23 += 4;
      *(_DWORD *)v23 = *v24;
    }
    v26 = idEntity::GetPhysics(this);
    v27 = (float *)v26->GetOrigin(this: v26, a2: 0);
    this->reactionSpring.p0.x = *v27;
    this->reactionSpring.p0.y = v27[1];
    this->reactionSpring.p0.z = v27[2];
    this->reactionSpring.maxSpeed = atv_bumpSpringMaxSpeed.valueFloat;
    v28 = ((double (__fastcall *)(idGameLocal *, int))gameLocal->GetRealSecPerFrame)(a1: gameLocal, a2: 1);
    idSpring<idVec3>::Update(this: &this->reactionSpring, dt: v28);
    v29 = (float)(this->reactionSpring.p0.y - this->reactionSpring.p1.y);
    v30 = v94;
    v31 = (float)(this->reactionSpring.p0.z - this->reactionSpring.p1.z);
    v32 = v95;
    v33 = (float)(this->reactionSpring.p0.x - this->reactionSpring.p1.x);
    v34 = v93;
    v35 = (float)((float)(v93 * (float)(this->reactionSpring.p0.x - this->reactionSpring.p1.x))
                + (float)((float)(v95 * (float)(this->reactionSpring.p0.z - this->reactionSpring.p1.z))
                        + (float)(v94 * (float)(this->reactionSpring.p0.y - this->reactionSpring.p1.y))));
    *(float *)v83 = (float)(v93 * (float)(this->reactionSpring.p0.x - this->reactionSpring.p1.x))
                  + (float)((float)(v95 * (float)(this->reactionSpring.p0.z - this->reactionSpring.p1.z))
                          + (float)(v94 * (float)(this->reactionSpring.p0.y - this->reactionSpring.p1.y)));
    v36 = v83[0];
    if ( v83[0] >= WRAP_CLAMP )
      v37 = 1.0;
    else
      v37 = -1.0;
    valueFloat = atv_bumpLeftClamp.valueFloat;
    v39 = __fsqrts((float)((float)((float)(v93 * (float)v35) * (float)(v93 * (float)v35))
                         + (float)((float)((float)(v95 * (float)v35) * (float)(v95 * (float)v35))
                                 + (float)((float)(v94 * (float)v35) * (float)(v94 * (float)v35)))));
    if ( v39 >= 0.0 )
    {
      if ( v39 > valueFloat )
        v39 = atv_bumpLeftClamp.valueFloat;
    }
    else
    {
      v39 = 0.0;
    }
    v40 = v91;
    v41 = (float)((float)v39 * (float)v37);
    v42 = v92;
    v43 = v90;
    v44 = (float)((float)(v92 * (float)v31) + (float)(v91 * (float)v29));
    v45 = (float)((float)(v90 * (float)v33) + (float)v44);
    *(float *)v83 = (float)(v90 * (float)v33) + (float)v44;
    if ( v83[0] >= WRAP_CLAMP )
      _FP12 = 1.0;
    else
      _FP12 = -1.0;
    __asm { fsel      f7, f12, f0, f13 }
    __asm { fsel      f13, f12, f0, f5 }
    v49 = (float)((float)__fsqrts((float)((float)((float)(v90 * (float)v45) * (float)(v90 * (float)v45))
                                        + (float)((float)((float)(v92 * (float)v45) * (float)(v92 * (float)v45))
                                                + (float)((float)(v91 * (float)v45) * (float)(v91 * (float)v45)))))
                * (float)_FP7);
    if ( v49 >= 0.0 )
    {
      if ( v49 > _FP13 )
        v49 = _FP13;
    }
    else
    {
      v49 = 0.0;
    }
    v50 = (float)((float)v49 * (float)_FP12);
    if ( atv_bumpSpringDebug.valueInteger != 0 )
    {
      clientGame->renderWorld->DebugLine(
        this: clientGame->renderWorld,
        a2: (const idVec4 *)&idColor::colorRed,
        a3: (const idVec3 *)&this->reactionSpring,
        a4: &this->reactionSpring.p1,
        a5: 0,
        a6: false);
      clientGame->renderWorld->DebugPoint(
        this: clientGame->renderWorld,
        a2: (const idVec4 *)&idColor::colorGreen,
        a3: (const idVec3 *)&this->reactionSpring,
        a4: 0,
        a5: false);
      clientGame->renderWorld->DebugPoint(
        this: clientGame->renderWorld,
        a2: (const idVec4 *)&idColor::colorCyan,
        a3: &this->reactionSpring.p1,
        a4: 0,
        a5: false);
      v51 = idEntity::GetPhysics(this: v6);
      LODWORD(v52) = v51->GetLinearVelocity(this: (idPhysics *)&v96, result: (idVec3 *)v51, a3: 0);
      v81 = __fsqrts((float)((float)(*(float *)(v52 + 8) * *(float *)(v52 + 8))
                           + (float)((float)(*(float *)v52 * *(float *)v52)
                                   + (float)(*(float *)(v52 + 4) * *(float *)(v52 + 4)))));
      HIDWORD(v52) = LODWORD(v81);
      v55 = va::va(
              this: &v97,
              fmt: (const char *)HIDWORD(v81),
              a3: v52,
              a4: v54,
              a5: v53,
              a6: v69,
              a7: v71,
              a8: v73,
              a9: v75,
              a10: v77,
              a11: v79);
      ((void (__fastcall *)(idRenderWorld *, va *, idSpring<idVec3> *, idRenderWorld_vtbl *, idColor *, int, _DWORD, _DWORD, double))clientGame->renderWorld->DebugText)(
        a1: clientGame->renderWorld,
        a2: v55,
        a3: &this->reactionSpring,
        a4: clientGame->renderWorld->__vftable,
        a5: &idColor::colorGreen,
        a6: 1,
        a7: 0,
        a8: 0,
        a9: 0.2);
      LODWORD(v56) = &unk_822D0000;
      v82 = __fsqrts((float)((float)(this->reactionSpring.vel.z * this->reactionSpring.vel.z)
                           + (float)((float)(this->reactionSpring.vel.x * this->reactionSpring.vel.x)
                                   + (float)(this->reactionSpring.vel.y * this->reactionSpring.vel.y))));
      HIDWORD(v57) = LODWORD(v82);
      v59 = va::va(
              this: &v97,
              fmt: (const char *)HIDWORD(v82),
              a3: v57,
              a4: v58,
              a5: v56,
              a6: v70,
              a7: v72,
              a8: v74,
              a9: v76,
              a10: v78,
              a11: v80);
      ((void (__fastcall *)(idRenderWorld *, va *, idVec3 *, idRenderWorld_vtbl *, idColor *, int, _DWORD, _DWORD, double))clientGame->renderWorld->DebugText)(
        a1: clientGame->renderWorld,
        a2: v59,
        a3: &this->reactionSpring.p1,
        a4: clientGame->renderWorld->__vftable,
        a5: &idColor::colorCyan,
        a6: 1,
        a7: 0,
        a8: 0,
        a9: 0.2);
      z = this->reactionSpring.p0.z;
      x = this->reactionSpring.p0.x;
      y = this->reactionSpring.p0.y;
      v85 = this->reactionSpring.p0.y;
      v84 = x;
      v86 = (float)z + (float)32.0;
      v88[0] = (float)((float)v43 * (float)v50) + (float)x;
      v88[1] = (float)((float)v40 * (float)v50) + (float)y;
      v88[2] = (float)((float)v42 * (float)v50) + v86;
      ((void (__fastcall *)(idRenderWorld *, idColor *, float *, float *, double))clientGame->renderWorld->DebugArrow)(
        a1: clientGame->renderWorld,
        a2: &idColor::colorGreen,
        a3: &v84,
        a4: v88,
        a5: 4.0);
      v87[0] = (float)((float)v34 * (float)v41) + v84;
      v87[1] = (float)((float)v30 * (float)v41) + v85;
      v87[2] = (float)((float)v32 * (float)v41) + v86;
      ((void (__fastcall *)(idRenderWorld *, idColor *, float *, float *, double))clientGame->renderWorld->DebugArrow)(
        a1: clientGame->renderWorld,
        a2: &idColor::colorRed,
        a3: &v84,
        a4: v87,
        a5: 4.0);
      valueFloat = atv_bumpLeftClamp.valueFloat;
    }
    if ( atv_bumpLeft.valueInteger != 0 )
    {
      v63 = (float)((float)v41 / (float)valueFloat);
      *(float *)v83 = (float)v41 / (float)valueFloat;
      p_bumpLeftAnimator = &this->bumpLeftAnimator;
      if ( v83[0] >= WRAP_CLAMP )
      {
        idAnimator_Paused::SetAnim(this: p_bumpLeftAnimator, anim_: this->reactionAnims[3], a3: v36);
        v65 = v63;
      }
      else
      {
        idAnimator_Paused::SetAnim(this: p_bumpLeftAnimator, anim_: this->reactionAnims[2], a3: v36);
        v65 = __fabs(v63);
      }
      idAnimator_Base::SetAlpha(this: &this->bumpLeftAnimator, alpha: v65);
    }
    if ( atv_bumpForward.valueInteger != 0 )
    {
      v66 = (float)((float)v50 / atv_bumpForwardClamp.valueFloat);
      *(float *)v83 = (float)v50 / atv_bumpForwardClamp.valueFloat;
      p_bumpForwardAnimator = &this->bumpForwardAnimator;
      if ( v83[0] >= WRAP_CLAMP )
      {
        idAnimator_Paused::SetAnim(this: p_bumpForwardAnimator, anim_: this->reactionAnims[1], a3: v36);
        v68 = v66;
      }
      else
      {
        idAnimator_Paused::SetAnim(this: p_bumpForwardAnimator, anim_: this->reactionAnims[0], a3: v36);
        v68 = __fabs(v66);
      }
      idAnimator_Base::SetAlpha(this: &this->bumpForwardAnimator, alpha: v68);
    }
  }
}


// ========================================================================
// ?SetLookPoint@idVehicleOccupant_Car@@UAAXABVidVec3@@H@Z
// EA  : 0x82D36100
// RVA : 0x00D36100
// PDB : w:\tech5\tungsten\game\entities\vehicleoccupants.cpp
// ========================================================================

void __fastcall idVehicleOccupant_Car::SetLookPoint(
        idVehicleOccupant_Car *this,
        const idVec3 *origin,
        int blendDurationMS)
{
  char v4; // r7
  int GameMs; // r29
  const idAnimStack *v7; // r3

  this->lookPoint = *origin;
  this->lookEntity.spawnId.value = 0x1FFF;
  v4 = *((_BYTE *)this + 10026);
  this->lookAimPoint = AIMPOINT_MAX;
  *((_BYTE *)this + 10026) = v4 | 0x80;
  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  v7 = this->GetAnimStack_2(this);
  idAnimator_Base::Start(this: &this->torsoAnimator, stack: v7, curTime: GameMs, blendDurationMS, reset: false);
}


// ========================================================================
// ?SetLookEntity@idVehicleOccupant_Car@@UAAXPBVidEntity@@W4aimPoint_t@@H@Z
// EA  : 0x82D361A0
// RVA : 0x00D361A0
// PDB : w:\tech5\tungsten\game\entities\vehicleoccupants.cpp
// ========================================================================

void __fastcall idVehicleOccupant_Car::SetLookEntity(
        idVehicleOccupant_Car *this,
        const idEntity *ent,
        aimPoint_t aimPoint,
        int blendDurationMS)
{
  char v6; // r11
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idPresentable *presentable; // r11
  idTreeAnimator *v9; // r30
  int GameMs; // r30
  const idAnimStack *v11; // r3

  this->lookPoint = vec3_origin;
  if ( ent != nullptr )
    this->lookEntity.spawnId.value = (gameLocal->spawnIds.ptr[ent->entityNumber] << 13) | ent->entityNumber;
  else
    this->lookEntity.spawnId.value = 0x1FFF;
  v6 = *((_BYTE *)this + 10026);
  this->lookAimPoint = aimPoint;
  *((_BYTE *)this + 10026) = v6 | 0x80;
  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
  presentable = this->presentable;
  v9 = TreeAnimatorFromPresentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    presentable = this->presentable;
  }
  idPresentable::UpdateModelTransform(this: presentable);
  if ( v9 != nullptr )
  {
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    v11 = this->GetAnimStack_2(this);
    idAnimator_Base::Start(this: &this->torsoAnimator, stack: v11, curTime: GameMs, blendDurationMS, reset: false);
  }
}


// ========================================================================
// ??0idVehicleOccupant_ATV@@QAA@XZ
// EA  : 0x82D362A8
// RVA : 0x00D362A8
// PDB : w:\tech5\tungsten\game\entities\vehicleoccupants.cpp
// ========================================================================

idVehicleOccupant_ATV *__fastcall idVehicleOccupant_ATV::idVehicleOccupant_ATV(idVehicleOccupant_ATV *this)
{
  idVehicleOccupant::idVehicleOccupant(this);
  this->__vftable = (idVehicleOccupant_ATV_vtbl *)&idVehicleOccupant_ATV::`vftable';
  this->sweepLeftRightAlias.value = -1;
  this->sweepUpDownAlias.value = -1;
  this->bumpAnimAliases[0].value = -1;
  this->bumpAnimAliases[1].value = -1;
  this->bumpAnimAliases[2].value = -1;
  this->bumpAnimAliases[3].value = -1;
  this->bumpAnimAliases[4].value = -1;
  this->bumpAnimAliases[5].value = -1;
  this->declReachIK = nullptr;
  idAnimator_Paused::idAnimator_Paused(this: &this->steeringAnimator);
  idAnimator_Paused::idAnimator_Paused(this: &this->speedAnimator);
  idAnimator_Paused::idAnimator_Paused(this: &this->bumpLeftAnimator);
  idAnimator_Paused::idAnimator_Paused(this: &this->bumpForwardAnimator);
  idAnimator_Paused::idAnimator_Paused(this: &this->bumpUpAnimator);
  idAnimator_Paused::idAnimator_Paused(this: &this->boostAnimator);
  idAnimator_ReachIK::idAnimator_ReachIK(this: &this->reachIKAnimator);
  idAnimator_AF::idAnimator_AF(this: &this->ragdollAnimator);
  this->leftTagData.trans.x = 0.0;
  this->leftTagData.trans.y = 0.0;
  this->leftTagData.trans.z = 0.0;
  this->leftTagData.rot.x = 0.0;
  this->leftTagData.rot.y = 0.0;
  this->leftTagData.rot.z = 0.0;
  this->leftTagData.rot.w = 0.0;
  this->leftTagData.parentJoint.value = -1;
  this->rightTagData.trans.x = 0.0;
  this->rightTagData.trans.y = 0.0;
  this->rightTagData.trans.z = 0.0;
  this->rightTagData.rot.x = 0.0;
  this->rightTagData.rot.y = 0.0;
  this->rightTagData.rot.z = 0.0;
  this->rightTagData.rot.w = 0.0;
  this->rightTagData.parentJoint.value = -1;
  this->bumpSpring.restLength = 0.0;
  this->bumpSpring.k = 1.0;
  this->bumpSpring.m = 1.0;
  this->bumpSpring.c = 2.0;
  this->bumpSpring.p0.z = 0.0;
  this->bumpSpring.p0.y = 0.0;
  this->bumpSpring.p0.x = 0.0;
  this->bumpSpring.p1.z = 0.0;
  this->bumpSpring.p1.y = 0.0;
  this->bumpSpring.p1.x = 0.0;
  this->bumpSpring.vel.z = 0.0;
  this->bumpSpring.vel.y = 0.0;
  this->bumpSpring.vel.x = 0.0;
  this->bumpSpring.maxSpeed = 0.0;
  this->bumpSpring.pMin.z = 0.0;
  this->bumpSpring.pMin.y = 0.0;
  this->bumpSpring.pMin.x = 0.0;
  this->bumpSpring.hasPMin = false;
  this->bumpSpring.pMax.z = 0.0;
  this->bumpSpring.pMax.y = 0.0;
  this->bumpSpring.pMax.x = 0.0;
  this->bumpSpring.hasPMax = false;
  this->wasBoosting = false;
  return this;
}


// ========================================================================
// __unwind$496135_0
// EA  : 0x82D36464
// RVA : 0x00D36464
// PDB : w:\tech5\tungsten\game\entities\vehicleoccupants.cpp
// ========================================================================

void _unwind_496135_0()
{
  int v0; // r12

  idVehicleOccupant::~idVehicleOccupant(this: *(idVehicleOccupant **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$496136
// EA  : 0x82D3648C
// RVA : 0x00D3648C
// PDB : w:\tech5\tungsten\game\entities\vehicleoccupants.cpp
// ========================================================================

void _unwind_496136()
{
  int v0; // r12

  idAnimator_Paused::~idAnimator_Paused(this: (idAnimator_Paused *)(*(_DWORD *)(v0 - 128 + 148) + 8876));
}


// ========================================================================
// __unwind$496137
// EA  : 0x82D364B8
// RVA : 0x00D364B8
// PDB : w:\tech5\tungsten\game\entities\vehicleoccupants.cpp
// ========================================================================

void _unwind_496137()
{
  int v0; // r12

  idAnimator_Paused::~idAnimator_Paused(this: (idAnimator_Paused *)(*(_DWORD *)(v0 - 128 + 148) + 8928));
}


// ========================================================================
// __unwind$496138
// EA  : 0x82D364E4
// RVA : 0x00D364E4
// PDB : w:\tech5\tungsten\game\entities\vehicleoccupants.cpp
// ========================================================================

void _unwind_496138()
{
  int v0; // r12

  idAnimator_Paused::~idAnimator_Paused(this: (idAnimator_Paused *)(*(_DWORD *)(v0 - 128 + 148) + 8980));
}


// ========================================================================
// __unwind$496139
// EA  : 0x82D36510
// RVA : 0x00D36510
// PDB : w:\tech5\tungsten\game\entities\vehicleoccupants.cpp
// ========================================================================

void _unwind_496139()
{
  int v0; // r12

  idAnimator_Paused::~idAnimator_Paused(this: (idAnimator_Paused *)(*(_DWORD *)(v0 - 128 + 148) + 9032));
}


// ========================================================================
// __unwind$496140
// EA  : 0x82D3653C
// RVA : 0x00D3653C
// PDB : w:\tech5\tungsten\game\entities\vehicleoccupants.cpp
// ========================================================================

void _unwind_496140()
{
  int v0; // r12

  idAnimator_Paused::~idAnimator_Paused(this: (idAnimator_Paused *)(*(_DWORD *)(v0 - 128 + 148) + 9084));
}


// ========================================================================
// __unwind$496141
// EA  : 0x82D36568
// RVA : 0x00D36568
// PDB : w:\tech5\tungsten\game\entities\vehicleoccupants.cpp
// ========================================================================

void _unwind_496141()
{
  int v0; // r12

  idAnimator_Paused::~idAnimator_Paused(this: (idAnimator_Paused *)(*(_DWORD *)(v0 - 128 + 148) + 9136));
}


// ========================================================================
// __unwind$496142
// EA  : 0x82D36594
// RVA : 0x00D36594
// PDB : w:\tech5\tungsten\game\entities\vehicleoccupants.cpp
// ========================================================================

void _unwind_496142()
{
  int v0; // r12

  idAnimator_ReachIK::~idAnimator_ReachIK(this: (idAnimator_ReachIK *)(*(_DWORD *)(v0 - 128 + 148) + 9188));
}


// ========================================================================
// ?InternalUpdateAnimations@idVehicleOccupant_ATV@@MAAXM@Z
// EA  : 0x82D365C0
// RVA : 0x00D365C0
// PDB : w:\tech5\tungsten\game\entities\vehicleoccupants.cpp
// ========================================================================

void __fastcall idVehicleOccupant_ATV::InternalUpdateAnimations(
        idVehicleOccupant_ATV *this,
        double anglePercent,
        int a3,
        __int64 a4)
{
  idAnimator_Paused *p_steeringAnimator; // r27
  int value; // r9
  idVehicle *v7; // r3
  idVehicle_Car *v8; // r21
  idPhysics *Physics; // r3
  idPhysics *v10; // r3
  int v11; // r3
  char *v12; // r10
  _DWORD *v13; // r11
  int i; // ctr
  idPhysics *v15; // r3
  int v16; // r4
  float *v17; // r3
  double z; // fp21
  double y; // fp20
  __int64 v20; // r6
  double x; // fp19
  double v22; // fp13
  double v25; // fp1
  double valueFloat; // fp13
  double v29; // fp29
  idPhysics *v30; // r3
  float *v31; // r3
  double v32; // fp0
  unsigned __int8 valueInteger; // r29
  int (*GetGameMs)(void); // ctr
  int v35; // r29
  const idAnimStack *v36; // r3
  int v37; // r29
  const idAnimStack *v38; // r3
  int (*v39)(void); // ctr
  int v40; // r29
  const idAnimStack *v41; // r3
  int v42; // r29
  const idAnimStack *v43; // r3
  int (*v44)(void); // ctr
  int v45; // r29
  const idAnimStack *v46; // r3
  int v47; // r29
  const idAnimStack *v48; // r3
  idPhysics *v49; // r3
  float *v50; // r3
  double v51; // fp1
  double v52; // fp24
  double v53; // fp23
  double v54; // fp22
  double v55; // fp0
  double v56; // fp12
  double v57; // fp0
  double v58; // fp25
  double v59; // fp0
  double v63; // fp0
  double v64; // fp28
  double v65; // fp29
  double v66; // fp27
  double v67; // fp26
  double v68; // fp0
  double v69; // fp12
  double v70; // fp0
  double v71; // fp30
  idDeclMD6 *decl; // r30
  double v73; // fp31
  const idMD6Anim *v74; // r3
  idMD6Leaf::wrapMode_t v75; // r5
  double v76; // fp1
  const idMD6Anim *v77; // r3
  idMD6Leaf::wrapMode_t v78; // r5
  double v79; // fp31
  const idMD6Anim *v80; // r3
  idMD6Leaf::wrapMode_t v81; // r5
  double v82; // fp1
  const idMD6Anim *v83; // r3
  idMD6Leaf::wrapMode_t v84; // r5
  double v85; // fp31
  const idMD6Anim *v86; // r3
  idMD6Leaf::wrapMode_t v87; // r5
  double v88; // fp1
  const idMD6Anim *v89; // r3
  idMD6Leaf::wrapMode_t v90; // r5
  idVehicle_Car *v91; // r3
  idVehicle_Car *v92; // r28
  int v93; // r28
  const idAnimStack *v94; // r3
  int GameMs; // r28
  const idAnimStack *v96; // r3
  idPhysics *v97; // r3
  __int64 v98; // r6
  __int64 v99; // r10
  __int64 v100; // r8
  va *v101; // r3
  __int64 v102; // r10
  __int64 v103; // r6
  __int64 v104; // r8
  va *v105; // r3
  double v106; // fp8
  double v107; // fp0
  double v108; // fp12
  bool v109; // r29
  idAnimStack *v110; // r3
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idPresentable *presentable; // r11
  idTreeAnimator *v113; // r28
  tagData_t *p_rightTagData; // r30
  idAnimator_ReachIK *p_reachIKAnimator; // r31
  int v116; // [sp+8h] [-11E8h]
  int v117; // [sp+8h] [-11E8h]
  int v118; // [sp+Ch] [-11E4h]
  int v119; // [sp+Ch] [-11E4h]
  int v120; // [sp+10h] [-11E0h]
  int v121; // [sp+10h] [-11E0h]
  int v122; // [sp+14h] [-11DCh]
  int v123; // [sp+14h] [-11DCh]
  int v124; // [sp+18h] [-11D8h]
  int v125; // [sp+18h] [-11D8h]
  int v126; // [sp+1Ch] [-11D4h]
  int v127; // [sp+1Ch] [-11D4h]
  double v128; // [sp+20h] [-11D0h]
  double v129; // [sp+20h] [-11D0h]
  float v130; // [sp+68h] [-1188h] BYREF
  float v131; // [sp+6Ch] [-1184h]
  float v132; // [sp+70h] [-1180h]
  float v133; // [sp+78h] [-1178h] BYREF
  float v134; // [sp+7Ch] [-1174h]
  float v135; // [sp+80h] [-1170h]
  char v136; // [sp+8Ch] [-1164h] BYREF
  idMat3 v137; // [sp+90h] [-1160h] BYREF
  float v138[4]; // [sp+B8h] [-1138h] BYREF
  float v139[4]; // [sp+C8h] [-1128h] BYREF
  float v140[4]; // [sp+D8h] [-1118h] BYREF
  idVec3 v141; // [sp+E8h] [-1108h] BYREF
  idVec3 v142; // [sp+F8h] [-10F8h] BYREF
  _BYTE v143[24]; // [sp+108h] [-10E8h] BYREF
  va v144; // [sp+120h] [-10D0h] BYREF

  p_steeringAnimator = &this->steeringAnimator;
  idAnimator_Paused::SetNormalizedFrame(
    this: &this->steeringAnimator,
    nf: (float)-(float)((float)((float)((float)anglePercent + (float)1.0) * (float)0.5) - (float)1.0),
    a3,
    a4);
  value = this->vehicle.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v7 = (idVehicle *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v8 = (idVehicle_Car *)idVehicle::CastTo(c: v7);
  }
  else
  {
    v8 = nullptr;
  }
  Physics = idEntity::GetPhysics(this: v8);
  Physics->GetLinearVelocity(this: (idPhysics *)&v133, result: (idVec3 *)Physics, a3: 0);
  v10 = idEntity::GetPhysics(this: v8);
  v11 = (int)v10->GetAxis(this: v10, a2: 0);
  v12 = &v136;
  v13 = (_DWORD *)(v11 - 4);
  for ( i = 9; i != 0; --i )
  {
    ++v13;
    v12 += 4;
    *(_DWORD *)v12 = *v13;
  }
  v15 = idEntity::GetPhysics(this: v8);
  v17 = (float *)v15->GetLinearVelocity(this: (idPhysics *)v143, result: (idVec3 *)v15, a3: 0);
  z = v137.mat[0].z;
  y = v137.mat[0].y;
  LODWORD(v20) = &atv_speedZeroFraction;
  x = v137.mat[0].x;
  if ( (float)((float)(v137.mat[0].x * *v17) + (float)((float)(v17[1] * v137.mat[0].y) + (float)(v17[2] * v137.mat[0].z))) <= 0.0 )
  {
    valueFloat = __fsqrts((float)((float)(v135 * v135) + (float)((float)(v133 * v133) + (float)(v134 * v134))));
    if ( valueFloat >= atv_minBackwardSpeed.valueFloat )
    {
      if ( valueFloat > atv_maxBackwardSpeed.valueFloat )
        valueFloat = atv_maxBackwardSpeed.valueFloat;
    }
    else
    {
      valueFloat = atv_minBackwardSpeed.valueFloat;
    }
    _FP9 = (float)((float)1.0 - (float)(atv_maxBackwardSpeed.valueFloat - atv_minBackwardSpeed.valueFloat));
    __asm { fsel      f8, f9, f31, f12 }
    v25 = (float)((float)((float)1.0
                        - (float)((float)((float)valueFloat - atv_minBackwardSpeed.valueFloat) / (float)_FP8))
                * (float)((float)1.0 - (float)((float)1.0 - atv_speedZeroFraction.valueFloat)));
  }
  else
  {
    v22 = __fsqrts((float)((float)(v135 * v135) + (float)((float)(v133 * v133) + (float)(v134 * v134))));
    if ( v22 >= atv_minForwardSpeed.valueFloat )
    {
      if ( v22 > atv_maxForwardSpeed.valueFloat )
        v22 = atv_maxForwardSpeed.valueFloat;
    }
    else
    {
      v22 = atv_minForwardSpeed.valueFloat;
    }
    _FP8 = (float)((float)1.0 - (float)(atv_maxForwardSpeed.valueFloat - atv_minForwardSpeed.valueFloat));
    __asm { fsel      f7, f8, f31, f12 }
    v25 = (float)((float)((float)((float)((float)v22 - atv_minForwardSpeed.valueFloat) / (float)_FP7)
                        * (float)((float)1.0 - atv_speedZeroFraction.valueFloat))
                + atv_speedZeroFraction.valueFloat);
  }
  idAnimator_Paused::SetNormalizedFrame(this: &this->speedAnimator, nf: v25, a3: v16, a4: v20);
  if ( (atv_speedWeight.flags & 0x20000) != 0 || (atv_steerWeight.flags & 0x20000) != 0 )
  {
    v29 = (float)((float)1.0 / (float)(atv_steerWeight.valueFloat + atv_speedWeight.valueFloat));
    idAnimator_Base::SetAlpha(
      this: p_steeringAnimator,
      alpha: (float)(atv_steerWeight.valueFloat
            * (float)((float)1.0 / (float)(atv_steerWeight.valueFloat + atv_speedWeight.valueFloat))));
    idAnimator_Base::SetAlpha(this: &this->speedAnimator, alpha: (float)(atv_speedWeight.valueFloat * (float)v29));
    atv_speedWeight.flags &= ~0x20000u;
    atv_steerWeight.flags &= ~0x20000u;
  }
  if ( (atv_bumpSpringConstant.flags & 0x20000) != 0
    || (atv_bumpSpringDampen.flags & 0x20000) != 0
    || (atv_bumpSpringMass.flags & 0x20000) != 0 )
  {
    idSpring<idVec3>::SetConstants(
      this: &this->bumpSpring,
      _k: atv_bumpSpringConstant.valueFloat,
      _c: atv_bumpSpringDampen.valueFloat);
    this->bumpSpring.m = atv_bumpSpringMass.valueFloat;
    v30 = idEntity::GetPhysics(this);
    v31 = (float *)v30->GetOrigin(this: v30, a2: 0);
    v32 = *v31;
    this->bumpSpring.p0.x = *v31;
    this->bumpSpring.p0.y = v31[1];
    this->bumpSpring.p0.z = v31[2];
    this->bumpSpring.p1.x = v32;
    this->bumpSpring.p1.y = this->bumpSpring.p0.y;
    this->bumpSpring.p1.z = this->bumpSpring.p0.z;
    this->bumpSpring.vel.z = 0.0;
    this->bumpSpring.vel.y = 0.0;
    this->bumpSpring.vel.x = 0.0;
    atv_bumpSpringDampen.flags &= ~0x20000u;
    atv_bumpSpringConstant.flags &= ~0x20000u;
    atv_bumpSpringMass.flags &= ~0x20000u;
  }
  if ( (atv_bumpBlendOp.flags & 0x20000) != 0 )
  {
    valueInteger = atv_bumpBlendOp.valueInteger;
    this->bumpLeftAnimator.InternalGetMergeBranch_2(this: &this->bumpLeftAnimator)->op = valueInteger;
    this->bumpForwardAnimator.InternalGetMergeBranch_2(this: &this->bumpForwardAnimator)->op = valueInteger;
    this->bumpUpAnimator.InternalGetMergeBranch_2(this: &this->bumpUpAnimator)->op = valueInteger;
    atv_bumpBlendOp.flags &= ~0x20000u;
  }
  if ( (atv_bumpLeft.flags & 0x20000) != 0 )
  {
    GetGameMs = (int (*)(void))gameLocal->GetGameMs;
    if ( atv_bumpLeft.valueInteger != 0 )
    {
      v35 = GetGameMs();
      v36 = this->GetAnimStack_2(this);
      idAnimator_Base::Start(this: &this->bumpLeftAnimator, stack: v36, curTime: v35, blendDurationMS: 0, reset: true);
    }
    else
    {
      v37 = GetGameMs();
      v38 = this->GetAnimStack_2(this);
      idAnimator_Base::End(this: &this->bumpLeftAnimator, stack: v38, curTime: v37, blendDurationMS: 0, reset: true);
    }
    atv_bumpLeft.flags &= ~0x20000u;
  }
  if ( (atv_bumpForward.flags & 0x20000) != 0 )
  {
    v39 = (int (*)(void))gameLocal->GetGameMs;
    if ( atv_bumpForward.valueInteger != 0 )
    {
      v40 = v39();
      v41 = this->GetAnimStack_2(this);
      idAnimator_Base::Start(
        this: &this->bumpForwardAnimator,
        stack: v41,
        curTime: v40,
        blendDurationMS: 0,
        reset: true);
    }
    else
    {
      v42 = v39();
      v43 = this->GetAnimStack_2(this);
      idAnimator_Base::End(this: &this->bumpForwardAnimator, stack: v43, curTime: v42, blendDurationMS: 0, reset: true);
    }
    atv_bumpForward.flags &= ~0x20000u;
  }
  if ( (atv_bumpUp.flags & 0x20000) != 0 )
  {
    v44 = (int (*)(void))gameLocal->GetGameMs;
    if ( atv_bumpUp.valueInteger != 0 )
    {
      v45 = v44();
      v46 = this->GetAnimStack_2(this);
      idAnimator_Base::Start(this: &this->bumpUpAnimator, stack: v46, curTime: v45, blendDurationMS: 0, reset: true);
    }
    else
    {
      v47 = v44();
      v48 = this->GetAnimStack_2(this);
      idAnimator_Base::End(this: &this->bumpUpAnimator, stack: v48, curTime: v47, blendDurationMS: 0, reset: true);
    }
    atv_bumpUp.flags &= ~0x20000u;
  }
  v49 = idEntity::GetPhysics(this);
  v50 = (float *)v49->GetOrigin(this: v49, a2: 0);
  this->bumpSpring.p0.x = *v50;
  this->bumpSpring.p0.y = v50[1];
  this->bumpSpring.p0.z = v50[2];
  this->bumpSpring.maxSpeed = atv_bumpSpringMaxSpeed.valueFloat;
  v51 = ((double (__fastcall *)(idGameLocal *, int))gameLocal->GetRealSecPerFrame)(a1: gameLocal, a2: 1);
  idSpring<idVec3>::Update(this: &this->bumpSpring, dt: v51);
  v52 = v137.mat[1].y;
  v53 = v137.mat[1].z;
  v54 = v137.mat[1].x;
  if ( COERCE_INT(
         (float)((float)(this->bumpSpring.p0.x - this->bumpSpring.p1.x) * v137.mat[1].x)
       + (float)((float)((float)(this->bumpSpring.p0.z - this->bumpSpring.p1.z) * v137.mat[1].z)
               + (float)((float)(this->bumpSpring.p0.y - this->bumpSpring.p1.y) * v137.mat[1].y))) >= 0 )
    v56 = 1.0;
  else
    v56 = -1.0;
  v55 = (float)((float)((float)(this->bumpSpring.p0.x - this->bumpSpring.p1.x) * v137.mat[1].x)
              + (float)((float)((float)(this->bumpSpring.p0.z - this->bumpSpring.p1.z) * v137.mat[1].z)
                      + (float)((float)(this->bumpSpring.p0.y - this->bumpSpring.p1.y) * v137.mat[1].y)));
  v57 = __fsqrts((float)((float)((float)(v137.mat[1].x * (float)v55) * (float)(v137.mat[1].x * (float)v55))
                       + (float)((float)((float)(v137.mat[1].z * (float)v55) * (float)(v137.mat[1].z * (float)v55))
                               + (float)((float)(v137.mat[1].y * (float)v55) * (float)(v137.mat[1].y * (float)v55)))));
  if ( v57 >= 0.0 )
  {
    if ( v57 > atv_bumpLeftClamp.valueFloat )
      v57 = atv_bumpLeftClamp.valueFloat;
  }
  else
  {
    v57 = 0.0;
  }
  v58 = (float)((float)v57 * (float)v56);
  if ( COERCE_INT(
         (float)((float)x * (float)(this->bumpSpring.p0.x - this->bumpSpring.p1.x))
       + (float)((float)((float)z * (float)(this->bumpSpring.p0.z - this->bumpSpring.p1.z))
               + (float)((float)y * (float)(this->bumpSpring.p0.y - this->bumpSpring.p1.y)))) >= 0 )
    _FP13 = 1.0;
  else
    _FP13 = -1.0;
  __asm { fsel      f4, f13, f0, f12 }
  __asm { fsel      f12, f13, f0, f12 }
  v59 = (float)((float)((float)x * (float)(this->bumpSpring.p0.x - this->bumpSpring.p1.x))
              + (float)((float)((float)z * (float)(this->bumpSpring.p0.z - this->bumpSpring.p1.z))
                      + (float)((float)y * (float)(this->bumpSpring.p0.y - this->bumpSpring.p1.y))));
  v63 = (float)((float)__fsqrts((float)((float)((float)((float)x * (float)v59) * (float)((float)x * (float)v59))
                                      + (float)((float)((float)((float)z * (float)v59) * (float)((float)z * (float)v59))
                                              + (float)((float)((float)y * (float)v59) * (float)((float)y * (float)v59)))))
              * (float)_FP4);
  if ( v63 >= 0.0 )
  {
    if ( v63 > _FP12 )
      v63 = _FP12;
  }
  else
  {
    v63 = 0.0;
  }
  v64 = v137.mat[2].y;
  v65 = (float)((float)v63 * (float)_FP13);
  v66 = v137.mat[2].z;
  v67 = v137.mat[2].x;
  if ( COERCE_INT(
         (float)((float)(this->bumpSpring.p0.x - this->bumpSpring.p1.x) * v137.mat[2].x)
       + (float)((float)((float)(this->bumpSpring.p0.z - this->bumpSpring.p1.z) * v137.mat[2].z)
               + (float)((float)(this->bumpSpring.p0.y - this->bumpSpring.p1.y) * v137.mat[2].y))) >= 0 )
    v69 = 1.0;
  else
    v69 = -1.0;
  v68 = (float)((float)((float)(this->bumpSpring.p0.x - this->bumpSpring.p1.x) * v137.mat[2].x)
              + (float)((float)((float)(this->bumpSpring.p0.z - this->bumpSpring.p1.z) * v137.mat[2].z)
                      + (float)((float)(this->bumpSpring.p0.y - this->bumpSpring.p1.y) * v137.mat[2].y)));
  v70 = __fsqrts((float)((float)((float)(v137.mat[2].x * (float)v68) * (float)(v137.mat[2].x * (float)v68))
                       + (float)((float)((float)(v137.mat[2].z * (float)v68) * (float)(v137.mat[2].z * (float)v68))
                               + (float)((float)(v137.mat[2].y * (float)v68) * (float)(v137.mat[2].y * (float)v68)))));
  if ( v70 >= 0.0 )
  {
    if ( v70 > atv_bumpUpClamp.valueFloat )
      v70 = atv_bumpUpClamp.valueFloat;
  }
  else
  {
    v70 = 0.0;
  }
  v71 = (float)((float)v70 * (float)v69);
  decl = idAnimatedEntity::GetTreeAnimatorFromPresentable(this)->decl;
  if ( atv_bumpLeft.valueInteger != 0 )
  {
    v73 = (float)((float)v58 / atv_bumpLeftClamp.valueFloat);
    if ( COERCE_INT((float)v58 / atv_bumpLeftClamp.valueFloat) >= 0 )
    {
      v77 = idDeclMD6::AnimForAlias(this: decl, aliasHandle: &this->bumpAnimAliases[3], load: false);
      idAnimator_Paused::SetAnim(this: &this->bumpLeftAnimator, anim_: v77, a3: v78);
      v76 = v73;
    }
    else
    {
      v74 = idDeclMD6::AnimForAlias(this: decl, aliasHandle: &this->bumpAnimAliases[2], load: false);
      idAnimator_Paused::SetAnim(this: &this->bumpLeftAnimator, anim_: v74, a3: v75);
      v76 = __fabs(v73);
    }
    idAnimator_Base::SetAlpha(this: &this->bumpLeftAnimator, alpha: v76);
  }
  if ( atv_bumpForward.valueInteger != 0 )
  {
    v79 = (float)((float)v65 / atv_bumpForwardClamp.valueFloat);
    if ( COERCE_INT((float)v65 / atv_bumpForwardClamp.valueFloat) >= 0 )
    {
      v83 = idDeclMD6::AnimForAlias(this: decl, aliasHandle: &this->bumpAnimAliases[1], load: false);
      idAnimator_Paused::SetAnim(this: &this->bumpForwardAnimator, anim_: v83, a3: v84);
      v82 = v79;
    }
    else
    {
      v80 = idDeclMD6::AnimForAlias(this: decl, aliasHandle: this->bumpAnimAliases, load: false);
      idAnimator_Paused::SetAnim(this: &this->bumpForwardAnimator, anim_: v80, a3: v81);
      v82 = __fabs(v79);
    }
    idAnimator_Base::SetAlpha(this: &this->bumpForwardAnimator, alpha: v82);
  }
  if ( atv_bumpUp.valueInteger != 0 )
  {
    v85 = (float)((float)v71 / atv_bumpUpClamp.valueFloat);
    if ( COERCE_INT((float)v71 / atv_bumpUpClamp.valueFloat) >= 0 )
    {
      v89 = idDeclMD6::AnimForAlias(this: decl, aliasHandle: &this->bumpAnimAliases[5], load: false);
      idAnimator_Paused::SetAnim(this: &this->bumpUpAnimator, anim_: v89, a3: v90);
      v88 = v85;
    }
    else
    {
      v86 = idDeclMD6::AnimForAlias(this: decl, aliasHandle: &this->bumpAnimAliases[4], load: false);
      idAnimator_Paused::SetAnim(this: &this->bumpUpAnimator, anim_: v86, a3: v87);
      v88 = __fabs(v85);
    }
    idAnimator_Base::SetAlpha(this: &this->bumpUpAnimator, alpha: v88);
  }
  if ( atv_boostAdd.valueInteger != 0 )
  {
    v91 = idVehicle_Car::CastTo(c: v8);
    v92 = v91;
    if ( this->wasBoosting || (unsigned __int8)idVehicle_Car::IsBoosting(this: v91) == 0 )
    {
      if ( this->wasBoosting && (unsigned __int8)idVehicle_Car::IsBoosting(this: v92) == 0 )
      {
        this->wasBoosting = false;
        GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        v96 = this->GetAnimStack_2(this);
        idAnimator_Base::End(
          this: &this->boostAnimator,
          stack: v96,
          curTime: GameMs,
          blendDurationMS: 500,
          reset: false);
      }
    }
    else
    {
      this->wasBoosting = true;
      v93 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      v94 = this->GetAnimStack_2(this);
      idAnimator_Base::Start(this: &this->boostAnimator, stack: v94, curTime: v93, blendDurationMS: 500, reset: false);
    }
  }
  if ( atv_bumpSpringDebug.valueInteger != 0 )
  {
    clientGame->renderWorld->DebugLine(
      this: clientGame->renderWorld,
      a2: (const idVec4 *)&idColor::colorRed,
      a3: (const idVec3 *)&this->bumpSpring,
      a4: &this->bumpSpring.p1,
      a5: 0,
      a6: false);
    clientGame->renderWorld->DebugPoint(
      this: clientGame->renderWorld,
      a2: (const idVec4 *)&idColor::colorGreen,
      a3: (const idVec3 *)&this->bumpSpring,
      a4: 0,
      a5: false);
    clientGame->renderWorld->DebugPoint(
      this: clientGame->renderWorld,
      a2: (const idVec4 *)&idColor::colorCyan,
      a3: &this->bumpSpring.p1,
      a4: 0,
      a5: false);
    v97 = idEntity::GetPhysics(this: v8);
    LODWORD(v98) = v97->GetLinearVelocity(this: (idPhysics *)v143, result: (idVec3 *)v97, a3: 0);
    v128 = __fsqrts((float)((float)(*(float *)(v98 + 8) * *(float *)(v98 + 8))
                          + (float)((float)(*(float *)v98 * *(float *)v98)
                                  + (float)(*(float *)(v98 + 4) * *(float *)(v98 + 4)))));
    HIDWORD(v98) = LODWORD(v128);
    v101 = va::va(
             this: &v144,
             fmt: (const char *)HIDWORD(v128),
             a3: v98,
             a4: v100,
             a5: v99,
             a6: v116,
             a7: v118,
             a8: v120,
             a9: v122,
             a10: v124,
             a11: v126);
    ((void (__fastcall *)(idRenderWorld *, va *, idSpring<idVec3> *, idRenderWorld_vtbl *, idColor *, int, _DWORD, _DWORD, double))clientGame->renderWorld->DebugText)(
      a1: clientGame->renderWorld,
      a2: v101,
      a3: &this->bumpSpring,
      a4: clientGame->renderWorld->__vftable,
      a5: &idColor::colorGreen,
      a6: 1,
      a7: 0,
      a8: 0,
      a9: 0.2);
    LODWORD(v102) = &unk_822D0000;
    v129 = __fsqrts((float)((float)(this->bumpSpring.vel.z * this->bumpSpring.vel.z)
                          + (float)((float)(this->bumpSpring.vel.x * this->bumpSpring.vel.x)
                                  + (float)(this->bumpSpring.vel.y * this->bumpSpring.vel.y))));
    HIDWORD(v103) = LODWORD(v129);
    v105 = va::va(
             this: &v144,
             fmt: (const char *)HIDWORD(v129),
             a3: v103,
             a4: v104,
             a5: v102,
             a6: v117,
             a7: v119,
             a8: v121,
             a9: v123,
             a10: v125,
             a11: v127);
    ((void (__fastcall *)(idRenderWorld *, va *, idVec3 *, idRenderWorld_vtbl *, idColor *, int, _DWORD, _DWORD, double))clientGame->renderWorld->DebugText)(
      a1: clientGame->renderWorld,
      a2: v105,
      a3: &this->bumpSpring.p1,
      a4: clientGame->renderWorld->__vftable,
      a5: &idColor::colorCyan,
      a6: 1,
      a7: 0,
      a8: 0,
      a9: 0.2);
    v106 = this->bumpSpring.p0.z;
    v107 = this->bumpSpring.p0.x;
    v108 = this->bumpSpring.p0.y;
    v131 = this->bumpSpring.p0.y;
    v130 = v107;
    v132 = (float)v106 + (float)32.0;
    v140[0] = (float)((float)x * (float)v65) + (float)v107;
    v140[1] = (float)((float)y * (float)v65) + (float)v108;
    v140[2] = (float)((float)z * (float)v65) + v132;
    ((void (__fastcall *)(idRenderWorld *, idColor *, float *, float *, double))clientGame->renderWorld->DebugArrow)(
      a1: clientGame->renderWorld,
      a2: &idColor::colorGreen,
      a3: &v130,
      a4: v140,
      a5: 4.0);
    v139[0] = (float)((float)v54 * (float)v58) + v130;
    v139[1] = (float)((float)v52 * (float)v58) + v131;
    v139[2] = (float)((float)v53 * (float)v58) + v132;
    ((void (__fastcall *)(idRenderWorld *, idColor *, float *, float *, double))clientGame->renderWorld->DebugArrow)(
      a1: clientGame->renderWorld,
      a2: &idColor::colorRed,
      a3: &v130,
      a4: v139,
      a5: 4.0);
    v138[2] = (float)((float)v66 * (float)v71) + v132;
    v138[1] = (float)((float)v64 * (float)v71) + v131;
    v138[0] = (float)((float)v67 * (float)v71) + v130;
    ((void (__fastcall *)(idRenderWorld *, idColor *, float *, float *, double))clientGame->renderWorld->DebugArrow)(
      a1: clientGame->renderWorld,
      a2: &idColor::colorBlue,
      a3: &v130,
      a4: v138,
      a5: 4.0);
  }
  if ( (atv_ikArms.flags & 0x20000) != 0 )
  {
    v109 = atv_ikArms.valueInteger != 0;
    v110 = this->GetAnimStack_2(this);
    idAnimator_Base::SetEnabled(this: &this->reachIKAnimator, animStack: v110, enabled: v109);
    atv_ikArms.flags &= ~0x20000u;
  }
  if ( atv_ikArms.valueInteger != 0 )
  {
    TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: v8);
    presentable = v8->presentable;
    v113 = TreeAnimatorFromPresentable;
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this: v8);
      presentable = v8->presentable;
    }
    idPresentable::UpdateModelTransform(this: presentable);
    if ( this->leftTagData.parentJoint.value != 0xFFFF )
    {
      idTreeAnimator::GetWorldSpaceTagTransform(this: v113, tagData: &this->leftTagData, origin: &v142, axis: &v137);
      idAnimator_ReachIK::SetTargetOrigin(this: &this->reachIKAnimator, arm: 0, targetPos: &v142);
      idTreeAnimator::GetModelSpaceTagTransform(this: v113, tagData: &this->leftTagData, origin: &v142, axis: &v137);
      idAnimator_ReachIK::SetTargetAxis(this: &this->reachIKAnimator, arm: 0, targetAxis: &v137);
    }
    if ( this->rightTagData.parentJoint.value != 0xFFFF )
    {
      p_rightTagData = &this->rightTagData;
      idTreeAnimator::GetWorldSpaceTagTransform(this: v113, tagData: &this->rightTagData, origin: &v141, axis: &v137);
      p_reachIKAnimator = &this->reachIKAnimator;
      idAnimator_ReachIK::SetTargetOrigin(this: p_reachIKAnimator, arm: 1, targetPos: &v141);
      idTreeAnimator::GetModelSpaceTagTransform(this: v113, tagData: p_rightTagData, origin: &v141, axis: &v137);
      idAnimator_ReachIK::SetTargetAxis(this: p_reachIKAnimator, arm: 1, targetAxis: &v137);
    }
  }
}


// ========================================================================
// ?StartRagdoll@idVehicleOccupant@@QAA_NXZ
// EA  : 0x82D374C0
// RVA : 0x00D374C0
// PDB : w:\tech5\tungsten\game\entities\vehicleoccupants.cpp
// ========================================================================

int __fastcall idVehicleOccupant::StartRagdoll(idVehicleOccupant *this)
{
  idAnimator_AF *p_afProperties; // r29
  char v3; // r26
  idGameTimeManager *v4; // r3
  int entityNumber; // r24
  idVec3 *p_gravity; // r25
  idSoundEmitter *SoundEmitter; // r23
  idClip *p_clip; // r21
  idAnimStack *v9; // r3
  idPhysics *Physics; // r3
  idPhysics_AF_vtbl *v12; // r26
  int v13; // r3
  idPhysics *v14; // r3
  idPhysics_AF_vtbl *v15; // r26
  int v16; // r3
  idPhysics_AF_vtbl *v17; // r26
  int v18; // r3
  idPhysics *v19; // r3
  int v20; // r3
  idPhysicsCallbacks *v21; // [sp+8h] [-118h]
  int v22; // [sp+Ch] [-114h]
  int v23; // [sp+10h] [-110h]
  int v24; // [sp+14h] [-10Ch]
  int v25; // [sp+18h] [-108h]
  int v26; // [sp+1Ch] [-104h]
  int v27; // [sp+20h] [-100h]
  int v28; // [sp+24h] [-FCh]
  int v29; // [sp+28h] [-F8h]
  int v30; // [sp+2Ch] [-F4h]
  int v31; // [sp+30h] [-F0h]
  int v32; // [sp+34h] [-ECh]
  int v33; // [sp+38h] [-E8h]
  int v34; // [sp+3Ch] [-E4h]
  int v35; // [sp+40h] [-E0h]
  int v36; // [sp+44h] [-DCh]
  int v37; // [sp+48h] [-D8h]
  int v38; // [sp+4Ch] [-D4h]
  int v39; // [sp+50h] [-D0h]
  _BYTE v40[24]; // [sp+68h] [-B8h] BYREF
  idAnimatorParms_Base v41[2]; // [sp+80h] [-A0h] BYREF

  p_afProperties = &this->afProperties;
  v41[0].animStack = this->GetAnimStack_2(this);
  idStr::idStr(this: &v41[0].name, text: "af");
  v3 = 0;
  v41[0].originBlend = ORIGINBLEND_BRANCH;
  v41[0].blendOp = BOP_LERP;
  v41[0].weightGroup = MD6_WEIGHTGROUP_ALL;
  v41[0].alpha = 1.0;
  v41[0].filterGroup = MD6_WEIGHTGROUP_ALL;
  v4 = gameLocal->GetGameTimeManager(this: gameLocal);
  idAnimator_Base::Init(this: p_afProperties, gametimeManager: v4, parms: v41);
  this->vehicleOccupantPhysicsCallbacks.ent.spawnId.value = (gameLocal->spawnIds.ptr[this->entityNumber] << 13)
                                                          | this->entityNumber;
  this->vehicleOccupantPhysicsCallbacks.af = p_afProperties;
  entityNumber = this->entityNumber;
  p_gravity = &gameLocal->clientGame.gravity;
  SoundEmitter = idEntity::GetSoundEmitter(this, alloc: true);
  p_clip = &clientGame->clip;
  v9 = this->GetAnimStack_2(this);
  if ( (unsigned __int8)idAnimator_AF::InitAF(
                          this: p_afProperties,
                          animStack: v9,
                          clip: p_clip,
                          impactManager: &this->impactManager,
                          soundEmitter: SoundEmitter,
                          soundChannel: SND_CHANNEL_BODY3,
                          gravityVector: p_gravity,
                          entityNumber,
                          callback: v21,
                          a10: v22,
                          a11: v23,
                          a12: v24,
                          a13: v25,
                          a14: v26,
                          a15: v27,
                          a16: v28,
                          a17: v29,
                          a18: v30,
                          a19: v31,
                          a20: v32,
                          a21: v33,
                          a22: v34,
                          a23: v35,
                          a24: v36,
                          a25: v37,
                          a26: v38,
                          a27: v39,
                          a28: &this->vehicleOccupantPhysicsCallbacks) != 0 )
  {
    if ( p_afProperties->isActive || p_afProperties->isClientAuthoritativeActive )
      v3 = 1;
    if ( v3 == 0 )
    {
      Physics = idEntity::GetPhysics(this);
      v12 = p_afProperties->physicsObj.__vftable;
      v13 = (int)Physics->GetLinearVelocity(this: (idPhysics *)v40, result: (idVec3 *)Physics, a3: 0);
      v12->SetLinearVelocity(this: &p_afProperties->physicsObj, a2: (const idVec3 *)v13, a3: 0);
      v14 = idEntity::GetPhysics(this);
      v15 = p_afProperties->physicsObj.__vftable;
      v16 = (int)v14->GetAngularVelocity(this: (idPhysics *)v40, result: (idVec3 *)v14, a3: 0);
      v15->SetAngularVelocity(this: &p_afProperties->physicsObj, a2: (const idVec3 *)v16, a3: 0);
      p_afProperties->physicsObj.PutToRest(this: &p_afProperties->physicsObj);
      v17 = p_afProperties->physicsObj.__vftable;
      v18 = v17->GetClipMask(this: &p_afProperties->physicsObj, a2: -1);
      v17->SetClipMask(this: &p_afProperties->physicsObj, a2: v18 | 0x4000, a3: -1);
      *((_BYTE *)&this->flags + 1) |= 8u;
      v19 = idEntity::GetPhysics(this);
      v19->DisableClip(this: v19);
      p_afProperties->physicsObj.EnableClip(this: &p_afProperties->physicsObj);
      v20 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
      idAnimator_AF::StartFromCurrentPose(
        this: p_afProperties,
        time: v20,
        inheritAnimationVelocity_: false,
        inheritOverrideVelocity_: false,
        overrideVelocity_: &vec3_origin);
      idEntity::UpdateVisuals(this);
    }
    idStr::FreeData(this: &v41[0].name);
    return 1;
  }
  else
  {
    idLib::Warning(
      fmt: "idVehicleOccupant::StartRagdoll: Couldn't load articulated figure on entity '%s'",
      this->name.data);
    idStr::FreeData(this: &v41[0].name);
    return 0;
  }
}


// ========================================================================
// __unwind$497155_0
// EA  : 0x82D377A0
// RVA : 0x00D377A0
// PDB : w:\tech5\tungsten\game\entities\vehicleoccupants.cpp
// ========================================================================

void _unwind_497155_0()
{
  int v0; // r12

  idAnimatorParms_EndAdditiveChannels::~idAnimatorParms_EndAdditiveChannels(this: (vaiAction_t::vehicleCam_t *)(v0 - 288 + 128));
}


// ========================================================================
// ?EnterVehicle@idVehicleOccupant@@QAAXPAVidVehicle@@PAVidTreeAnimator@@PBD@Z
// EA  : 0x82D377C8
// RVA : 0x00D377C8
// PDB : w:\tech5\tungsten\game\entities\vehicleoccupants.cpp
// ========================================================================

void __fastcall idVehicleOccupant::EnterVehicle(
        idVehicleOccupant *this,
        idVehicle *vehicle,
        idTreeAnimator *tagAnimator,
        const char *tagName)
{
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idPresentable *presentable; // r11
  idTreeAnimator *v10; // r30
  idPhysics *Physics; // r3
  idPhysics *v12; // r3
  idPresentable *v13; // r11
  char v14; // r11
  bool v15; // zf
  idPresentable *v16; // r30
  idPresentable *v17; // r3

  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
  presentable = this->presentable;
  v10 = TreeAnimatorFromPresentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    presentable = this->presentable;
  }
  idPresentable::UpdateModelTransform(this: presentable);
  if ( v10 != nullptr )
  {
    if ( vehicle != nullptr )
      this->vehicle.spawnId.value = (gameLocal->spawnIds.ptr[vehicle->entityNumber] << 13) | vehicle->entityNumber;
    else
      this->vehicle.spawnId.value = 0x1FFF;
    this->tagAnimator = tagAnimator;
    Physics = idEntity::GetPhysics(this);
    Physics->SetContents(this: Physics, a2: 128, a3: -1);
    v12 = idEntity::GetPhysics(this);
    v12->SetClipMask(this: v12, a2: 128, a3: -1);
    v13 = this->presentable;
    if ( v13 == nullptr || (v15 = v13->model != nullptr, v14 = 1, !v15) )
      v14 = 0;
    if ( v14 != 0 )
    {
      if ( vehicle->presentable == nullptr )
        idEntity::InitPresentableInternal(this: vehicle);
      v16 = vehicle->presentable;
      v17 = this->presentable;
      if ( v17 == nullptr )
      {
        idEntity::InitPresentableInternal(this);
        v17 = this->presentable;
      }
      idPresentable::SetGroupMaster(this: v17, pres: v16);
    }
    if ( tagAnimator != nullptr )
      this->tagData = *idPropsCollection::GetTag(
                         this: &tagAnimator->decl->props,
                         propName: idPropInfo::INFO_PROP_NAME,
                         tagName);
    idVehicleOccupant::TransformVisual(this);
    this->Show(this);
    this->InternalEnterVehicle(this, a2: vehicle, a3: tagAnimator, a4: tagName);
    idEntity::BecomeActive(this, flags: 4);
    idEntity::BecomeActive(this, flags: 2);
    this->lookAtWeight = 0.5;
  }
}


// ========================================================================
// ??0idVehicleOccupant_Car@@QAA@XZ
// EA  : 0x82D379D0
// RVA : 0x00D379D0
// PDB : w:\tech5\tungsten\game\entities\vehicleoccupants.cpp
// ========================================================================

idVehicleOccupant_Car *__fastcall idVehicleOccupant_Car::idVehicleOccupant_Car(idVehicleOccupant_Car *this)
{
  __int64 v2; // r29

  idVehicleOccupant::idVehicleOccupant(this);
  this->__vftable = (idVehicleOccupant_Car_vtbl *)&idVehicleOccupant_Car::`vftable';
  idAnimator_Synced::idAnimator_Synced(this: &this->headAnimator);
  idAnimator_Paused::idAnimator_Paused(this: &this->steeringAnimator);
  idAnimator_Channel::idAnimator_Channel(this: &this->passengerAnimator);
  idAnimator_EndAdditiveChannels::idAnimator_EndAdditiveChannels(this: &this->additiveShakeAnimator);
  idAnimator_Paused::idAnimator_Paused(this: &this->bumpLeftAnimator);
  idAnimator_Paused::idAnimator_Paused(this: &this->bumpForwardAnimator);
  idAnimator_TorsoTracker::idAnimator_TorsoTracker(this: &this->torsoAnimator);
  idAnimator_Pain::idAnimator_Pain(this: &this->painAnimator);
  LODWORD(v2) = 0;
  this->painAnimations.list = nullptr;
  this->painAnimations.granularity = 0;
  this->painAnimations.memTag = 5;
  this->painAnimations.listStatic = 0;
  this->painAnimations.size = 0;
  this->painAnimations.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->painAnimations);
  this->headAnims[0].value = -1;
  this->headAnims[1].value = -1;
  this->headAnims[2].value = -1;
  this->steeringAnim.value = -1;
  this->passengerAnim.value = -1;
  this->gunnerIdleAnim.value = -1;
  this->additiveShakeAnim.value = -1;
  this->reactionAnimHandles[0].value = -1;
  this->reactionAnimHandles[1].value = -1;
  this->reactionAnimHandles[2].value = -1;
  this->reactionAnimHandles[3].value = -1;
  this->cameraJointName.str = &byte_8200D768;
  this->steeringMaxAngle = 45.0;
  this->painReactionDamagetypes = DAMAGETYPE_ALL;
  this->numSteeringFrames = 0.0;
  this->lookPoint.x = 0.0;
  this->lookPoint.y = 0.0;
  this->lookPoint.z = 0.0;
  this->lookEntity.spawnId.value = 0x1FFF;
  this->reactionSpring.k = 1.0;
  this->reactionSpring.m = 1.0;
  this->reactionSpring.restLength = 0.0;
  this->reactionSpring.c = 2.0;
  this->reactionSpring.p0.z = 0.0;
  this->reactionSpring.p0.y = 0.0;
  this->reactionSpring.p0.x = 0.0;
  this->reactionSpring.p1.z = 0.0;
  this->reactionSpring.p1.y = 0.0;
  this->reactionSpring.p1.x = 0.0;
  HIDWORD(v2) = &this->lookEntity;
  this->reactionSpring.vel.z = 0.0;
  this->reactionSpring.vel.y = 0.0;
  this->reactionSpring.vel.x = 0.0;
  this->reactionSpring.maxSpeed = 0.0;
  this->reactionSpring.pMin.z = 0.0;
  this->reactionSpring.pMin.y = 0.0;
  this->reactionSpring.pMin.x = 0.0;
  this->reactionSpring.hasPMin = false;
  this->reactionSpring.pMax.z = 0.0;
  this->reactionSpring.pMax.y = 0.0;
  this->reactionSpring.pMax.x = 0.0;
  this->reactionSpring.hasPMax = false;
  this->lookAimPoint = AIMPOINT_MAX;
  this->cameraJointIndex.value = -1;
  *((_BYTE *)this + 10026) &= 0xFu;
  *(_QWORD *)this->reactionAnims = v2;
  *(_QWORD *)&this->reactionAnims[2] = v2;
  return this;
}


// ========================================================================
// __unwind$497480
// EA  : 0x82D37BE4
// RVA : 0x00D37BE4
// PDB : w:\tech5\tungsten\game\entities\vehicleoccupants.cpp
// ========================================================================

void _unwind_497480()
{
  int v0; // r12

  idVehicleOccupant::~idVehicleOccupant(this: *(idVehicleOccupant **)(v0 - 160 + 180));
}


// ========================================================================
// __unwind$497481
// EA  : 0x82D37C0C
// RVA : 0x00D37C0C
// PDB : w:\tech5\tungsten\game\entities\vehicleoccupants.cpp
// ========================================================================

void _unwind_497481()
{
  int v0; // r12

  idAnimator_Synced::~idAnimator_Synced(this: (idAnimator_Synced *)(*(_DWORD *)(v0 - 160 + 180) + 8856));
}


// ========================================================================
// __unwind$497482
// EA  : 0x82D37C38
// RVA : 0x00D37C38
// PDB : w:\tech5\tungsten\game\entities\vehicleoccupants.cpp
// ========================================================================

void _unwind_497482()
{
  int v0; // r12

  idAnimator_Paused::~idAnimator_Paused(this: (idAnimator_Paused *)(*(_DWORD *)(v0 - 160 + 180) + 9144));
}


// ========================================================================
// __unwind$497483
// EA  : 0x82D37C64
// RVA : 0x00D37C64
// PDB : w:\tech5\tungsten\game\entities\vehicleoccupants.cpp
// ========================================================================

void _unwind_497483()
{
  int v0; // r12

  idAnimator_Channel::~idAnimator_Channel(this: (idAnimator_Channel *)(*(_DWORD *)(v0 - 160 + 180) + 9196));
}


// ========================================================================
// __unwind$497484
// EA  : 0x82D37C90
// RVA : 0x00D37C90
// PDB : w:\tech5\tungsten\game\entities\vehicleoccupants.cpp
// ========================================================================

void _unwind_497484()
{
  int v0; // r12

  idAnimator_EndAdditiveChannels::~idAnimator_EndAdditiveChannels(this: (idAnimator_EndAdditiveChannels *)(*(_DWORD *)(v0 - 160 + 180) + 9292));
}


// ========================================================================
// __unwind$497485
// EA  : 0x82D37CBC
// RVA : 0x00D37CBC
// PDB : w:\tech5\tungsten\game\entities\vehicleoccupants.cpp
// ========================================================================

void _unwind_497485()
{
  int v0; // r12

  idAnimator_Paused::~idAnimator_Paused(this: (idAnimator_Paused *)(*(_DWORD *)(v0 - 160 + 180) + 9460));
}


// ========================================================================
// __unwind$497486
// EA  : 0x82D37CE8
// RVA : 0x00D37CE8
// PDB : w:\tech5\tungsten\game\entities\vehicleoccupants.cpp
// ========================================================================

void _unwind_497486()
{
  int v0; // r12

  idAnimator_Paused::~idAnimator_Paused(this: (idAnimator_Paused *)(*(_DWORD *)(v0 - 160 + 180) + 9512));
}


// ========================================================================
// __unwind$497487
// EA  : 0x82D37D14
// RVA : 0x00D37D14
// PDB : w:\tech5\tungsten\game\entities\vehicleoccupants.cpp
// ========================================================================

void _unwind_497487()
{
  int v0; // r12

  idAnimator_TorsoTracker::~idAnimator_TorsoTracker(this: (idAnimator_TorsoTracker *)(*(_DWORD *)(v0 - 160 + 180) + 9564));
}


// ========================================================================
// __unwind$497488
// EA  : 0x82D37D40
// RVA : 0x00D37D40
// PDB : w:\tech5\tungsten\game\entities\vehicleoccupants.cpp
// ========================================================================

void _unwind_497488()
{
  int v0; // r12

  idAnimator_Pain::~idAnimator_Pain(this: (idAnimator_Pain *)(*(_DWORD *)(v0 - 160 + 180) + 9752));
}


// ========================================================================
// `dynamic initializer for 'atv_minForwardSpeed''
// EA  : 0x8337D260
// RVA : 0x0137D260
// PDB : w:\tech5\tungsten\game\entities\vehicleoccupants.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__atv_minForwardSpeed__()
{
  idCVar::idCVar(
    this: &atv_minForwardSpeed,
    name: "atv_minForwardSpeed",
    value: "250.0",
    flags: 4,
    description: "min speed of ATV for animation blending",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__atv_minForwardSpeed__);
}


// ========================================================================
// `dynamic initializer for 'atv_maxForwardSpeed''
// EA  : 0x8337D2B8
// RVA : 0x0137D2B8
// PDB : w:\tech5\tungsten\game\entities\vehicleoccupants.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__atv_maxForwardSpeed__()
{
  idCVar::idCVar(
    this: &atv_maxForwardSpeed,
    name: "atv_maxForwardSpeed",
    value: "1150.0",
    flags: 4,
    description: "max forward speed of ATV for animation blending",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__atv_maxForwardSpeed__);
}


// ========================================================================
// `dynamic initializer for 'atv_minBackwardSpeed''
// EA  : 0x8337D310
// RVA : 0x0137D310
// PDB : w:\tech5\tungsten\game\entities\vehicleoccupants.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__atv_minBackwardSpeed__()
{
  idCVar::idCVar(
    this: &atv_minBackwardSpeed,
    name: "atv_minBackwardSpeed",
    value: "100.0",
    flags: 4,
    description: "min speed of ATV for animation blending",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__atv_minBackwardSpeed__);
}


// ========================================================================
// `dynamic initializer for 'atv_maxBackwardSpeed''
// EA  : 0x8337D368
// RVA : 0x0137D368
// PDB : w:\tech5\tungsten\game\entities\vehicleoccupants.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__atv_maxBackwardSpeed__()
{
  idCVar::idCVar(
    this: &atv_maxBackwardSpeed,
    name: "atv_maxBackwardSpeed",
    value: "750.0",
    flags: 4,
    description: "max backward speed of ATV for animation blending",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__atv_maxBackwardSpeed__);
}


// ========================================================================
// `dynamic initializer for 'atv_bumpSpringConstant''
// EA  : 0x8337D3C0
// RVA : 0x0137D3C0
// PDB : w:\tech5\tungsten\game\entities\vehicleoccupants.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__atv_bumpSpringConstant__()
{
  idCVar::idCVar(
    this: &atv_bumpSpringConstant,
    name: "atv_bumpSpringConstant",
    value: "75.0",
    flags: 4,
    description: "spring constant for ATV bump spring",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__atv_bumpSpringConstant__);
}


// ========================================================================
// `dynamic initializer for 'atv_bumpSpringDampen''
// EA  : 0x8337D418
// RVA : 0x0137D418
// PDB : w:\tech5\tungsten\game\entities\vehicleoccupants.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__atv_bumpSpringDampen__()
{
  idCVar::idCVar(
    this: &atv_bumpSpringDampen,
    name: "atv_bumpSpringDampen",
    value: "5.0",
    flags: 4,
    description: "spring dampening factor for ATV bump spring",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__atv_bumpSpringDampen__);
}


// ========================================================================
// `dynamic initializer for 'atv_bumpSpringMass''
// EA  : 0x8337D470
// RVA : 0x0137D470
// PDB : w:\tech5\tungsten\game\entities\vehicleoccupants.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__atv_bumpSpringMass__()
{
  idCVar::idCVar(
    this: &atv_bumpSpringMass,
    name: "atv_bumpSpringMass",
    value: "0.75",
    flags: 4,
    description: "mass of weight at end of ATV bump spring",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__atv_bumpSpringMass__);
}


// ========================================================================
// `dynamic initializer for 'atv_bumpSpringMaxSpeed''
// EA  : 0x8337D4C8
// RVA : 0x0137D4C8
// PDB : w:\tech5\tungsten\game\entities\vehicleoccupants.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__atv_bumpSpringMaxSpeed__()
{
  idCVar::idCVar(
    this: &atv_bumpSpringMaxSpeed,
    name: "atv_bumpSpringMaxSpeed",
    value: "2000.0",
    flags: 4,
    description: "maximum magnitude of ATV bump spring velocity",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__atv_bumpSpringMaxSpeed__);
}


// ========================================================================
// `dynamic initializer for 'atv_bumpSpringDebug''
// EA  : 0x8337D520
// RVA : 0x0137D520
// PDB : w:\tech5\tungsten\game\entities\vehicleoccupants.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__atv_bumpSpringDebug__()
{
  idCVar::idCVar(
    this: &atv_bumpSpringDebug,
    name: "atv_bumpSpringDebug",
    value: "0",
    flags: 1,
    description: "1 = show debugging info for the ATV bump spring",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__atv_bumpSpringDebug__);
}


// ========================================================================
// `dynamic initializer for 'atv_bumpLeftClamp''
// EA  : 0x8337D578
// RVA : 0x0137D578
// PDB : w:\tech5\tungsten\game\entities\vehicleoccupants.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__atv_bumpLeftClamp__()
{
  idCVar::idCVar(
    this: &atv_bumpLeftClamp,
    name: "atv_bumpLeftClamp",
    value: "64.0",
    flags: 4,
    description: "max length to clamp the bump spring delta to on the left axis",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__atv_bumpLeftClamp__);
}


// ========================================================================
// `dynamic initializer for 'atv_bumpForwardClamp''
// EA  : 0x8337D5D0
// RVA : 0x0137D5D0
// PDB : w:\tech5\tungsten\game\entities\vehicleoccupants.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__atv_bumpForwardClamp__()
{
  idCVar::idCVar(
    this: &atv_bumpForwardClamp,
    name: "atv_bumpForwardClamp",
    value: "96.0",
    flags: 4,
    description: "max length to clamp the bump spring delta on the forward axis",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__atv_bumpForwardClamp__);
}


// ========================================================================
// `dynamic initializer for 'atv_bumpBackwardClamp''
// EA  : 0x8337D628
// RVA : 0x0137D628
// PDB : w:\tech5\tungsten\game\entities\vehicleoccupants.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__atv_bumpBackwardClamp__()
{
  idCVar::idCVar(
    this: &atv_bumpBackwardClamp,
    name: "atv_bumpBackwardClamp",
    value: "96.0",
    flags: 4,
    description: "max length to clamp the bump spring delta on the forward axis",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__atv_bumpBackwardClamp__);
}


// ========================================================================
// `dynamic initializer for 'atv_bumpForwardScale''
// EA  : 0x8337D680
// RVA : 0x0137D680
// PDB : w:\tech5\tungsten\game\entities\vehicleoccupants.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__atv_bumpForwardScale__()
{
  idCVar::idCVar(
    this: &atv_bumpForwardScale,
    name: "atv_bumpForwardScale",
    value: "1.0f",
    flags: 4,
    description: "extra scale applied to forwards spring delta (simulates additional spring tightness for forwards axis)",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__atv_bumpForwardScale__);
}


// ========================================================================
// `dynamic initializer for 'atv_bumpBackwardScale''
// EA  : 0x8337D6D8
// RVA : 0x0137D6D8
// PDB : w:\tech5\tungsten\game\entities\vehicleoccupants.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__atv_bumpBackwardScale__()
{
  idCVar::idCVar(
    this: &atv_bumpBackwardScale,
    name: "atv_bumpBackwardScale",
    value: "1.0",
    flags: 4,
    description: "extra scale applied to backwards spring delta (simulates additional spring tightness for backwards axis)",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__atv_bumpBackwardScale__);
}


// ========================================================================
// `dynamic initializer for 'atv_bumpUpClamp''
// EA  : 0x8337D730
// RVA : 0x0137D730
// PDB : w:\tech5\tungsten\game\entities\vehicleoccupants.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__atv_bumpUpClamp__()
{
  idCVar::idCVar(
    this: &atv_bumpUpClamp,
    name: "atv_bumpUpClamp",
    value: "48.0",
    flags: 4,
    description: "max length to clamp the bump spring delta to on the up axis",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__atv_bumpUpClamp__);
}


// ========================================================================
// `dynamic initializer for 'atv_bumpBlendOp''
// EA  : 0x8337D788
// RVA : 0x0137D788
// PDB : w:\tech5\tungsten\game\entities\vehicleoccupants.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__atv_bumpBlendOp__()
{
  idCVar::idCVar(
    this: &atv_bumpBlendOp,
    name: "atv_bumpBlendOp",
    value: "4",
    flags: 2,
    description: "blend op for additive animators",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__atv_bumpBlendOp__);
}


// ========================================================================
// `dynamic initializer for 'atv_testScale''
// EA  : 0x8337D7E0
// RVA : 0x0137D7E0
// PDB : w:\tech5\tungsten\game\entities\vehicleoccupants.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__atv_testScale__()
{
  idCVar::idCVar(
    this: &atv_testScale,
    name: "atv_testScale",
    value: "1",
    flags: 4,
    description: "blend op for additive animators",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__atv_testScale__);
}


// ========================================================================
// `dynamic initializer for 'atv_bumpLeft''
// EA  : 0x8337D838
// RVA : 0x0137D838
// PDB : w:\tech5\tungsten\game\entities\vehicleoccupants.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__atv_bumpLeft__()
{
  idCVar::idCVar(
    this: &atv_bumpLeft,
    name: "atv_bumpLeft",
    value: "1",
    flags: 1,
    description: "1 = use additive bump left animator",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__atv_bumpLeft__);
}


// ========================================================================
// `dynamic initializer for 'atv_bumpForward''
// EA  : 0x8337D890
// RVA : 0x0137D890
// PDB : w:\tech5\tungsten\game\entities\vehicleoccupants.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__atv_bumpForward__()
{
  idCVar::idCVar(
    this: &atv_bumpForward,
    name: "atv_bumpForward",
    value: "1",
    flags: 1,
    description: "1 = use additive bump forward animator",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__atv_bumpForward__);
}


// ========================================================================
// `dynamic initializer for 'atv_bumpUp''
// EA  : 0x8337D8E8
// RVA : 0x0137D8E8
// PDB : w:\tech5\tungsten\game\entities\vehicleoccupants.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__atv_bumpUp__()
{
  idCVar::idCVar(
    this: &atv_bumpUp,
    name: "atv_bumpUp",
    value: "1",
    flags: 1,
    description: "1 = use additive bump up animator",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__atv_bumpUp__);
}


// ========================================================================
// `dynamic initializer for 'atv_boostAdd''
// EA  : 0x8337D940
// RVA : 0x0137D940
// PDB : w:\tech5\tungsten\game\entities\vehicleoccupants.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__atv_boostAdd__()
{
  idCVar::idCVar(
    this: &atv_boostAdd,
    name: "atv_burstAdd",
    value: "0",
    flags: 1,
    description: "1 = use additive boost animator",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__atv_boostAdd__);
}


// ========================================================================
// `dynamic initializer for 'atv_steerWeight''
// EA  : 0x8337D998
// RVA : 0x0137D998
// PDB : w:\tech5\tungsten\game\entities\vehicleoccupants.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__atv_steerWeight__()
{
  idCVar::idCVar(
    this: &atv_steerWeight,
    name: "atv_steerWeight",
    value: "0.5",
    flags: 4,
    description: "weight of turning anim",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__atv_steerWeight__);
}


// ========================================================================
// `dynamic initializer for 'atv_speedWeight''
// EA  : 0x8337D9F0
// RVA : 0x0137D9F0
// PDB : w:\tech5\tungsten\game\entities\vehicleoccupants.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__atv_speedWeight__()
{
  idCVar::idCVar(
    this: &atv_speedWeight,
    name: "atv_speedWeight",
    value: "1.0",
    flags: 4,
    description: "weight of speed anim",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__atv_speedWeight__);
}


// ========================================================================
// `dynamic initializer for 'atv_speedZeroFraction''
// EA  : 0x8337DA48
// RVA : 0x0137DA48
// PDB : w:\tech5\tungsten\game\entities\vehicleoccupants.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__atv_speedZeroFraction__()
{
  idCVar::idCVar(
    this: &atv_speedZeroFraction,
    name: "atv_speedZeroFraction",
    value: "0.25",
    flags: 4,
    description: "the point in the speed sweep animation that is considered zero speed",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__atv_speedZeroFraction__);
}


// ========================================================================
// `dynamic initializer for 'atv_ikArms''
// EA  : 0x8337DAA0
// RVA : 0x0137DAA0
// PDB : w:\tech5\tungsten\game\entities\vehicleoccupants.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__atv_ikArms__()
{
  idCVar::idCVar(
    this: &atv_ikArms,
    name: "atv_ikArms",
    value: "1",
    flags: 1,
    description: "1 = ik the arms to the handlebars",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__atv_ikArms__);
}


// ========================================================================
// `dynamic initializer for 'atv_minThrowSoundDelay''
// EA  : 0x8337DAF8
// RVA : 0x0137DAF8
// PDB : w:\tech5\tungsten\game\entities\vehicleoccupants.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__atv_minThrowSoundDelay__()
{
  idCVar::idCVar(
    this: &atv_minThrowSoundDelay,
    name: "atv_minThrowSoundDelay",
    value: "500",
    flags: 2,
    description: "ms to wait before ending the thrown sounds on collision",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__atv_minThrowSoundDelay__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_occupant_disable_all''
// EA  : 0x8337DB50
// RVA : 0x0137DB50
// PDB : w:\tech5\tungsten\game\entities\vehicleoccupants.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_occupant_disable_all__()
{
  idCVar::idCVar(
    this: &vehicle_occupant_disable_all,
    name: "vehicle_occupant_disable_all",
    value: "0",
    flags: 1,
    description: "Prevents all vehicle occupants from spawning. Does not delete them if alreayd spawned!",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_occupant_disable_all__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_occupant_disable_anim''
// EA  : 0x8337DBA8
// RVA : 0x0137DBA8
// PDB : w:\tech5\tungsten\game\entities\vehicleoccupants.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_occupant_disable_anim__()
{
  idCVar::idCVar(
    this: &vehicle_occupant_disable_anim,
    name: "vehicle_occupant_disable_anim",
    value: "0",
    flags: 1,
    description: "Prevents all vehicle occupants from spawning. Does not delete them if alreayd spawned!",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_occupant_disable_anim__);
}

