
// ========================================================================
// ?GetViewAxis@idProp_WeaponStatic@@QAAABVidMat3@@XZ
// EA  : 0x82D4F140
// RVA : 0x00D4F140
// PDB : w:\tech5\tungsten\game\entities\weaponstatic.cpp
// ========================================================================

const idMat3 *__fastcall idProp_WeaponStatic::GetViewAxis(idProp_WeaponStatic *this)
{
  return &this->lookAt;
}


// ========================================================================
// ?PullTrigger@idProp_WeaponStatic@@AAAXXZ
// EA  : 0x82D4F148
// RVA : 0x00D4F148
// PDB : w:\tech5\tungsten\game\entities\weaponstatic.cpp
// ========================================================================

void __fastcall idProp_WeaponStatic::PullTrigger(idProp_WeaponStatic *this)
{
  idEntity::StartSoundShader(
    this,
    channel: SND_CHANNEL_WEAPON,
    shader: this->sndFireLoop,
    soundShaderFlags: (soundShaderFlags_t)0,
    peerMask: 0xFFu);
  this->windupTimer = this->windupTime;
  this->shooting = true;
}


// ========================================================================
// ?ReleaseTrigger@idProp_WeaponStatic@@AAAXXZ
// EA  : 0x82D4F198
// RVA : 0x00D4F198
// PDB : w:\tech5\tungsten\game\entities\weaponstatic.cpp
// ========================================================================

void __fastcall idProp_WeaponStatic::ReleaseTrigger(idProp_WeaponStatic *this)
{
  this->shooting = false;
  idEntity::StopSound(this, channel: SND_CHANNEL_WEAPON, peerMask: 0xFFu);
  idEntity::StartSoundShader(
    this,
    channel: SND_CHANNEL_WEAPON2,
    shader: this->sndFireStop,
    soundShaderFlags: (soundShaderFlags_t)0,
    peerMask: 0xFFu);
  this->windupTimer = this->windupTime;
  idWeapon::StopLoopingFireSound(this: this->weapon);
}


// ========================================================================
// ?Hide@idProp_WeaponStatic@@UAAXXZ
// EA  : 0x82D4F200
// RVA : 0x00D4F200
// PDB : w:\tech5\tungsten\game\entities\weaponstatic.cpp
// ========================================================================

void __fastcall idProp_WeaponStatic::Hide(idProp_WeaponStatic *this)
{
  if ( (unsigned __int8)Get_idCombatStage_useRelaxedChatterVO(ptr: (unsigned __int8 *)this) == 0 )
  {
    idEntity::Hide(this);
    idEntity::BecomeInactive(this, flags: 5);
  }
}


// ========================================================================
// ?Show@idProp_WeaponStatic@@UAAXXZ
// EA  : 0x82D4F250
// RVA : 0x00D4F250
// PDB : w:\tech5\tungsten\game\entities\weaponstatic.cpp
// ========================================================================

void __fastcall idProp_WeaponStatic::Show(idProp_WeaponStatic *this)
{
  if ( (unsigned __int8)Get_idCombatStage_useRelaxedChatterVO(ptr: (unsigned __int8 *)this) != 0 )
  {
    idEntity::Show(this);
    idEntity::BecomeActive(this, flags: 5);
  }
}


// ========================================================================
// ??0idWeaponStatic_Armour@@QAA@XZ
// EA  : 0x82D4F550
// RVA : 0x00D4F550
// PDB : w:\tech5\tungsten\game\entities\weaponstatic.cpp
// ========================================================================

idWeaponStatic_Armour *__fastcall idWeaponStatic_Armour::idWeaponStatic_Armour(idWeaponStatic_Armour *this)
{
  this->renderModel = nullptr;
  this->brokenModel = nullptr;
  this->clipModel.str = &byte_8200D768;
  this->joint.allocedAndFlag = 20;
  this->joint.data = this->joint.baseBuffer;
  this->joint.len = 0;
  this->joint.baseBuffer[0] = 0;
  this->health = 0.0;
  this->takesDamage = false;
  this->causesImmunity = false;
  this->physicsObj = nullptr;
  this->presentable = nullptr;
  this->jointIndex.value = -1;
  this->currentHealth = 0.0;
  return this;
}


// ========================================================================
// ?GetFXDecl@idProp_WeaponStatic@@UBAPBVidDeclFX@@XZ
// EA  : 0x82D4F5B0
// RVA : 0x00D4F5B0
// PDB : w:\tech5\tungsten\game\entities\weaponstatic.cpp
// ========================================================================

const idDeclFX *__fastcall idProp_WeaponStatic::GetFXDecl(idProp_WeaponStatic *this)
{
  const idDeclFX *result; // r3

  result = this->weaponDecl->weaponFX;
  if ( result == nullptr )
    return this->fxDecl;
  return result;
}


// ========================================================================
// ?GetUseLocation@idProp_WeaponStatic@@UBAXPBVidActor@@AAVidVec3@@@Z
// EA  : 0x82D4F5D0
// RVA : 0x00D4F5D0
// PDB : w:\tech5\tungsten\game\entities\weaponstatic.cpp
// ========================================================================

void __fastcall idProp_WeaponStatic::GetUseLocation(idProp_WeaponStatic *this, const idActor *actor, idVec3 *pos)
{
  idPhysics *Physics; // r3
  idPresentable *presentable; // r11
  idPhysics *v7; // r29
  double v8; // fp31
  double v9; // fp30
  double v10; // fp29
  float *v11; // r3
  double v12; // fp3
  double v13; // fp2
  idMat3 v14; // [sp+50h] [-60h] BYREF

  if ( (unsigned __int8)idAI2::IsTypeOf(c: &actor->idAnimatedEntity) != 0
    || (unsigned __int8)idAnimatedEntity::GetTagPosition(
                          this,
                          propIndex: this->infopropIndex,
                          tagIndex: this->useTagIndex,
                          origin: pos,
                          axis: &v14) == 0 )
  {
    Physics = idEntity::GetPhysics(this);
    presentable = this->presentable;
    v7 = Physics;
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      presentable = this->presentable;
    }
    v8 = (float)(presentable->axis.mat[0].x * (float)((float)(UNITS_PER_INCH_16 * (float)2.5999999) * (float)12.0));
    v9 = (float)(presentable->axis.mat[0].y * (float)((float)(UNITS_PER_INCH_16 * (float)2.5999999) * (float)12.0));
    v10 = (float)(presentable->axis.mat[0].z * (float)((float)(UNITS_PER_INCH_16 * (float)2.5999999) * (float)12.0));
    v11 = (float *)v7->GetOrigin(this: v7, a2: 0);
    v12 = (float)(v11[1] - (float)v9);
    v13 = (float)(v11[2] - (float)v10);
    pos->x = *v11 - (float)v8;
    pos->y = v12;
    pos->z = v13;
  }
}


// ========================================================================
// ?GetVisibilityPoint@idProp_WeaponStatic@@UBAXW4visPoint_t@@AAVidVec3@@@Z
// EA  : 0x82D4F6D8
// RVA : 0x00D4F6D8
// PDB : w:\tech5\tungsten\game\entities\weaponstatic.cpp
// ========================================================================

void __fastcall idProp_WeaponStatic::GetVisibilityPoint(idProp_WeaponStatic *this, const visPoint_t type, idVec3 *pos)
{
  idPhysics *Physics; // r3
  float *v5; // r3

  Physics = idEntity::GetPhysics(this);
  v5 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
  pos->x = *v5;
  pos->y = v5[1];
  pos->z = (float)((float)(UNITS_PER_INCH_16 * (float)5.0) * (float)12.0) + v5[2];
}


// ========================================================================
// ?IsEverUsable@idProp_WeaponStatic@@UBA_NPBVidEntity@@@Z
// EA  : 0x82D4F750
// RVA : 0x00D4F750
// PDB : w:\tech5\tungsten\game\entities\weaponstatic.cpp
// ========================================================================

int __fastcall idProp_WeaponStatic::IsEverUsable(idProp_WeaponStatic *this, idActor *activator)
{
  int result; // r3
  idActor *v5; // r3
  const idActor *v6; // r31
  idPhysics *Physics; // r3
  float *v8; // r3
  float v9; // [sp+50h] [-40h]
  float v10; // [sp+54h] [-3Ch]
  float v11; // [sp+60h] [-30h] BYREF
  float v12; // [sp+64h] [-2Ch]

  if ( !idProp_Usable::IsEverUsable(this, activator) )
    return 0;
  if ( !this->enabled )
    return 0;
  if ( (unsigned __int8)idProp_Usable::IsUsable(this) == 0 )
    return 0;
  v5 = idActor::CastTo(c: activator);
  v6 = v5;
  if ( v5 == nullptr )
    return 0;
  if ( v5->IsDrivingVehicle(this: v5) )
    return 1;
  Physics = idEntity::GetPhysics(this: activator);
  v8 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
  v9 = *v8;
  v10 = v8[1];
  this->GetUseLocation(this, a2: v6, a3: (idVec3 *)&v11);
  result = 0;
  if ( (float)((float)((float)(v10 - v12) * (float)(v10 - v12)) + (float)((float)(v9 - v11) * (float)(v9 - v11))) < 6400.0 )
    return 1;
  return result;
}


// ========================================================================
// ?ModifyCrosshairInfo@idProp_WeaponStatic@@UBA_NPBVidEntity@@ABVidFocusTrace@@W4usableState_t@@AAVidCrosshairInfo@@@Z
// EA  : 0x82D4F868
// RVA : 0x00D4F868
// PDB : w:\tech5\tungsten\game\entities\weaponstatic.cpp
// ========================================================================

int __fastcall idProp_WeaponStatic::ModifyCrosshairInfo(
        idProp_WeaponStatic *this,
        const idEntity *activator,
        const idFocusTrace *ft,
        const usableState_t usable,
        idCrosshairInfo *info)
{
  info->icons.list->material = this->displayIcon;
  return 1;
}


// ========================================================================
// ?MovePlayer@idProp_WeaponStatic@@AAAXPAVidPlayer@@@Z
// EA  : 0x82D4F880
// RVA : 0x00D4F880
// PDB : w:\tech5\tungsten\game\entities\weaponstatic.cpp
// ========================================================================

void __fastcall idProp_WeaponStatic::MovePlayer(idProp_WeaponStatic *this, idPlayer *player)
{
  idPhysics *Physics; // r3
  float *v5; // r3
  float v6; // r5
  float v7; // r7
  double v8; // fp10
  double v9; // fp9
  double v10; // fp8
  idPhysics *v11; // r3
  idVec3 v12; // [sp+50h] [-30h] BYREF

  Physics = idEntity::GetPhysics(this);
  v5 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
  v6 = *v5;
  v7 = v5[1];
  v8 = (float)(this->lookAt.mat[0].x * (float)45.0);
  v9 = (float)(this->lookAt.mat[0].y * (float)45.0);
  v10 = (float)(this->lookAt.mat[0].z * (float)45.0);
  v12.z = v5[2];
  v12.y = v7 - (float)v9;
  v12.x = v6 - (float)v8;
  v12.z = v12.z - (float)v10;
  idEntity::SetOrigin(this: player, org: &v12);
  v11 = idEntity::GetPhysics(this: player);
  v11->SetLinearVelocity(this: v11, a2: &vec3_origin, a3: 0);
}


// ========================================================================
// ?GetViewOrg@idProp_WeaponStatic@@QAA_NAAVidVec3@@PAVidPlayer@@@Z
// EA  : 0x82D4F960
// RVA : 0x00D4F960
// PDB : w:\tech5\tungsten\game\entities\weaponstatic.cpp
// ========================================================================

int __fastcall idProp_WeaponStatic::GetViewOrg(idProp_WeaponStatic *this, idVec3 *pos, idPlayer *player)
{
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  double viewFov; // fp31
  idPresentable *presentable; // r3
  idPresentablePlayer *v10; // r3
  idPresentable *v11; // r3
  idPresentablePlayer *v12; // r28
  idPresentable *v13; // r3
  int v14; // r30
  const idDeclInventory *decl; // r29
  __int64 v16; // r10
  double CurrentValue; // fp1
  double v18; // fp2
  double v19; // fp11
  float x; // [sp+50h] [-80h]
  float z; // [sp+58h] [-78h]
  idVec3 v22; // [sp+60h] [-70h] BYREF
  idMat3 v23; // [sp+70h] [-60h] BYREF

  if ( (unsigned __int8)idAnimatedEntity::GetTagPosition(
                          this,
                          propIndex: this->infopropIndex,
                          tagIndex: this->cameraTagIndex,
                          origin: pos,
                          axis: &v23) != 0 )
  {
    if ( (unsigned __int8)idAnimatedEntity::GetTagPosition(
                            this,
                            propIndex: this->infopropIndex,
                            tagIndex: this->ironSightTagIndex,
                            origin: &v22,
                            axis: &v23) != 0 )
    {
      viewFov = this->viewFov;
      if ( viewFov < 0.0 )
      {
        presentable = player->presentable;
        if ( presentable != nullptr )
          v10 = presentable->GetPlayerInterface_2(this: presentable);
        else
          v10 = nullptr;
        viewFov = idPresentablePlayer::DefaultFov(this: v10);
      }
      v11 = player->presentable;
      if ( v11 != nullptr )
        v12 = v11->GetPlayerInterface_2(this: v11);
      else
        v12 = nullptr;
      v13 = player->presentable;
      if ( v13 != nullptr )
        v14 = (int)v13->GetPlayerInterface_2(this: v13);
      else
        v14 = 0;
      decl = this->weapon->decl;
      LODWORD(v16) = idPresentablePlayer::GetPlayerGameTime(this: v12);
      CurrentValue = idInterpolate<float>::GetCurrentValue(
                       this: (idInterpolate<float> *)(v14 + 46648),
                       time: (float)v16);
      z = pos->z;
      x = pos->x;
      v18 = (float)((float)(v22.x - pos->x)
                  * (float)((float)((float)viewFov - (float)CurrentValue)
                          / (float)((float)viewFov - *(float *)&decl[2].itemUse)));
      v19 = (float)((float)(v22.z - z)
                  * (float)((float)((float)viewFov - (float)CurrentValue)
                          / (float)((float)viewFov - *(float *)&decl[2].itemUse)));
      pos->y = (float)((float)(v22.y - pos->y)
                     * (float)((float)((float)viewFov - (float)CurrentValue)
                             / (float)((float)viewFov - *(float *)&decl[2].itemUse)))
             + pos->y;
      pos->x = (float)v18 + x;
      pos->z = (float)v19 + z;
    }
  }
  else
  {
    TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
    if ( TreeAnimatorFromPresentable == nullptr
      || (unsigned __int8)idTreeAnimator::GetWorldSpaceJointTransform(
                            this: TreeAnimatorFromPresentable,
                            pose: DRIVER_MODEL,
                            jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)this->jointPitch.value,
                            origin: pos,
                            axis: &v23) == 0 )
    {
      return 0;
    }
  }
  return 1;
}


// ========================================================================
// ?BreakArmourPiece@idProp_WeaponStatic@@AAAXAAVidWeaponStatic_Armour@@@Z
// EA  : 0x82D4FB40
// RVA : 0x00D4FB40
// PDB : w:\tech5\tungsten\game\entities\weaponstatic.cpp
// ========================================================================

void __fastcall idProp_WeaponStatic::BreakArmourPiece(idProp_WeaponStatic *this, idWeaponStatic_Armour *armourPiece)
{
  idPresentable *presentable; // r11
  idRenderModel *model; // r3
  idPresentable_vtbl *v6; // r11
  idPhysics *physicsObj; // r3

  presentable = this->presentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    presentable = this->presentable;
  }
  model = presentable->model;
  if ( model != nullptr )
    model->RemoveDecals(this: model);
  v6 = armourPiece->presentable->__vftable;
  if ( armourPiece->brokenModel != nullptr )
    ((void (*)(void))v6->SetRenderModel)();
  else
    ((void (*)(void))v6->Hide)();
  physicsObj = armourPiece->physicsObj;
  if ( physicsObj != nullptr )
  {
    physicsObj->DisableClip(this: physicsObj);
    armourPiece->physicsObj->UnlinkClip(this: armourPiece->physicsObj);
  }
  armourPiece->currentHealth = 0.0;
  armourPiece->brokenTimestamp = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
}


// ========================================================================
// ?HoldTrigger@idProp_WeaponStatic@@AAAX_N0@Z
// EA  : 0x82D4FC38
// RVA : 0x00D4FC38
// PDB : w:\tech5\tungsten\game\entities\weaponstatic.cpp
// ========================================================================

void __fastcall idProp_WeaponStatic::HoldTrigger(idProp_WeaponStatic *this, BOOL primary, BOOL secondary)
{
  int GameMs; // r27
  __int64 v7; // r8

  if ( this->windupTimer > 0.0 )
  {
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    LODWORD(v7) = GameMs
                - idGameTimeManager::GetPreviousGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    this->windupTimer = -(float)((float)((float)v7 * (float)0.001) - this->windupTimer);
  }
  if ( this->windupTimer <= 0.0 )
    this->Shoot(this, a2: primary, a3: secondary);
}


// ========================================================================
// ?GetOverheatRatio@idProp_WeaponStatic@@QAAMXZ
// EA  : 0x82D4FCF8
// RVA : 0x00D4FCF8
// PDB : w:\tech5\tungsten\game\entities\weaponstatic.cpp
// ========================================================================

float __fastcall idProp_WeaponStatic::GetOverheatRatio(idProp_WeaponStatic *this)
{
  idPresentable *presentable; // r3
  double v3; // fp31
  __int64 v4; // r10
  int v5; // r3
  double v6; // fp1

  presentable = this->presentable;
  v3 = 0.0;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    presentable = this->presentable;
  }
  v5 = (int)presentable->GetWeaponStaticInterface(this: presentable);
  if ( v5 != 0 )
    v3 = *(float *)(v5 + 1296);
  LODWORD(v4) = this->maxHeat;
  v6 = (float)((float)v3 / (float)v4);
  return *((float *)&v6 + 1);
}


// ========================================================================
// ?AllocPresentable@idProp_WeaponStatic@@UAAPAVidPresentable@@PAVidRenderModel@@@Z
// EA  : 0x82D4FD88
// RVA : 0x00D4FD88
// PDB : w:\tech5\tungsten\game\entities\weaponstatic.cpp
// ========================================================================

idPresentableWeaponStatic *__fastcall idProp_WeaponStatic::AllocPresentable(
        idProp_WeaponStatic *this,
        idRenderModel *renderModel_)
{
  bool v4; // r27
  _DWORD *v5; // r3
  int v6; // r11
  idPresentableWeaponStatic *v7; // r28
  int entityNumber; // r26
  const idDeclFX *v9; // r25
  idAnimStack *v10; // r3

  v4 = false;
  v5 = _RTDynamicCast(
         inptr: renderModel_,
         VfDelta: 0,
         SrcType: &idRenderModel `RTTI Type Descriptor',
         TargetType: &idTreeAnimator `RTTI Type Descriptor',
         isReference: 0);
  if ( v5 != nullptr )
  {
    v6 = v5[508];
    if ( v6 != 0 && v6 != -144 )
      v4 = idJointGroupCollection::NumJointGroupsForType(this: (idJointGroupCollection *)(v6 + 144), type: 8) != 0;
  }
  v7 = (idPresentableWeaponStatic *)idMem::AllocWithLocation(
                                      this: &mem,
                                      location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                      size: 0x5A8u,
                                      tag: TAG_PRESENTABLE,
                                      zeroBuffer: false,
                                      align: ALIGN_16,
                                      heap: HEAP_DEFAULTHEAP);
  if ( v7 == nullptr )
    return nullptr;
  entityNumber = this->entityNumber;
  v9 = this->GetFXDecl(this);
  v10 = this->GetAnimStack_2(this);
  return idPresentableWeaponStatic::idPresentableWeaponStatic(
           this: v7,
           ent: this,
           renderModel_,
           animStack_: v10,
           animJointMod_: &this->jointModAnimator,
           entityNumber_: entityNumber,
           fxDecl_: v9,
           useSphereModel_: v4);
}


// ========================================================================
// __unwind$492262
// EA  : 0x82D4FE94
// RVA : 0x00D4FE94
// PDB : w:\tech5\tungsten\game\entities\weaponstatic.cpp
// ========================================================================

void _unwind_492262()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 160 + 80), tag: TAG_PRESENTABLE);
}


// ========================================================================
// ?IsPointInFiringRange@idProp_WeaponStatic@@QBA_NABVidVec3@@M@Z
// EA  : 0x82D4FEC0
// RVA : 0x00D4FEC0
// PDB : w:\tech5\tungsten\game\entities\weaponstatic.cpp
// ========================================================================

BOOL __fastcall idProp_WeaponStatic::IsPointInFiringRange(
        idProp_WeaponStatic *this,
        const idVec3 *target,
        double safetyMargin)
{
  idPhysics *Physics; // r3
  float *v7; // r3
  double v8; // fp9
  double v9; // fp7
  double maxRange; // fp0
  long double v11; // fp2
  double v12; // fp13
  double v13; // fp30
  double v14; // fp29
  double v15; // fp28
  double v16; // fp31
  idPresentable *presentable; // r11
  double v21; // fp30
  long double v22; // fp2

  Physics = idEntity::GetPhysics(this);
  v7 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
  v8 = (float)(target->y - v7[1]);
  v9 = (float)(target->z - v7[2]);
  maxRange = this->maxRange;
  *((double *)&v11 + 1) = (float)((float)((float)(target->x - *v7) * (float)(target->x - *v7))
                                + (float)((float)((float)v9 * (float)v9) + (float)((float)v8 * (float)v8)));
  v12 = __fsqrts(*((double *)&v11 + 1));
  v13 = (float)((float)((float)1.0 / (float)v12) * (float)(target->x - *v7));
  v14 = (float)((float)(target->y - v7[1]) * (float)((float)1.0 / (float)v12));
  v15 = (float)((float)(target->z - v7[2]) * (float)((float)1.0 / (float)v12));
  if ( maxRange == 0.0 )
    maxRange = this->weaponDecl->maxRange;
  v16 = (float)((float)1.0 - (float)safetyMargin);
  if ( v12 > (float)((float)v16 * (float)maxRange) || v16 > 0.1 && v12 < (float)(this->minRange / (float)v16) )
    return false;
  presentable = this->presentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    presentable = this->presentable;
  }
  _FP7 = (float)((float)180.0 - this->maxAIYaw);
  __asm { fsel      f5, f7, f12, f0 }
  v21 = (float)((float)(presentable->axis.mat[0].x * (float)v13)
              + (float)((float)(presentable->axis.mat[0].z * (float)v15)
                      + (float)(presentable->axis.mat[0].y * (float)v14)));
  *(double *)&v11 = (float)((float)v16 * (float)((float)_FP5 * idMath::M_DEG2RAD));
  v22 = cos(x: v11);
  return v21 >= (float)*(double *)&v22;
}


// ========================================================================
// ?OnActivate@idProp_WeaponStatic@@EAAXPAVidEntity@@@Z
// EA  : 0x82D50030
// RVA : 0x00D50030
// PDB : w:\tech5\tungsten\game\entities\weaponstatic.cpp
// ========================================================================

void __fastcall idProp_WeaponStatic::OnActivate(idProp_WeaponStatic *this, idEntity *activator)
{
  ((void (__fastcall *)(idProp_WeaponStatic *, idEntity *, idEntity *, const idDeclDamage *, double))this->Damage)(
    a1: this,
    a2: activator,
    a3: activator,
    a4: gameLocal->damageSuicide,
    a5: 1.0);
}


// ========================================================================
// ?Event_EnableManualExit@idProp_WeaponStatic@@AAA?AVeventVoid@@_N@Z
// EA  : 0x82D50070
// RVA : 0x00D50070
// PDB : w:\tech5\tungsten\game\entities\weaponstatic.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __usercall idProp_WeaponStatic::Event_EnableManualExit@<r4>(
        idProp_WeaponStatic *this@<r3>,
        int result@<r4>,
        bool enable@<r5>)
{
  *(_BYTE *)(result + 5748) = (32 * ((_cntlzw(enable) & 0x20) != 0)) & 0x20 | *(_BYTE *)(result + 5748) & 0xDF;
  return result;
}


// ========================================================================
// ?GetJointIndexFromTrace@idProp_WeaponStatic@@UAA?AV?$idIndex@FW4invalidJointIndex_t@@@@Utrace_t@@@Z
// EA  : 0x82D50090
// RVA : 0x00D50090
// PDB : w:\tech5\tungsten\game\entities\weaponstatic.cpp
// ========================================================================

idProp_WeaponStatic *__fastcall idProp_WeaponStatic::GetJointIndexFromTrace(
        idProp_WeaponStatic *this,
        idIndex<short,enum invalidJointIndex_t> *result,
        trace_t *trace,
        int a4,
        int a5,
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
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        int a28,
        int a29,
        int a30,
        int a31,
        int a32,
        int a33,
        int a34,
        int a35,
        int a36,
        int a37,
        int a38,
        int a39,
        int a40,
        int a41,
        int a42,
        int a43)
{
  int v43; // r11
  int v44; // r7
  int v45; // r8
  int v46; // r10
  int v47; // r9
  int v48; // r9

  v43 = 0;
  v44 = *(_DWORD *)&result[2700].value;
  if ( v44 <= 0 )
  {
LABEL_6:
    HIWORD(this->__vftable) = NULL_JOINT_INDEX;
  }
  else
  {
    v45 = *(_DWORD *)&result[2698].value;
    v46 = 0;
    v47 = v45;
    while ( 1 )
    {
      v48 = *(_DWORD *)(v47 + 52);
      if ( v48 != 0 && *(_DWORD *)(v48 + 12) == a43 )
        break;
      ++v43;
      v46 += 72;
      v47 = v46 + v45;
      if ( v43 >= v44 )
        goto LABEL_6;
    }
    HIWORD(this->__vftable) = *(_WORD *)(72 * v43 + v45 + 60);
  }
  return this;
}


// ========================================================================
// ?GetArmourPieceFromTrace@idProp_WeaponStatic@@AAAPAVidWeaponStatic_Armour@@ABUtrace_t@@@Z
// EA  : 0x82D50120
// RVA : 0x00D50120
// PDB : w:\tech5\tungsten\game\entities\weaponstatic.cpp
// ========================================================================

idWeaponStatic_Armour *__fastcall idProp_WeaponStatic::GetArmourPieceFromTrace(
        idProp_WeaponStatic *this,
        const trace_t *trace)
{
  int num; // r7
  int v3; // r10
  idWeaponStatic_Armour *list; // r8
  int v5; // r11
  idWeaponStatic_Armour *v6; // r9
  idPhysics *physicsObj; // r9

  num = this->armourPieces.num;
  v3 = 0;
  if ( num <= 0 )
    return nullptr;
  list = this->armourPieces.list;
  v5 = 0;
  v6 = list;
  while ( 1 )
  {
    physicsObj = v6->physicsObj;
    if ( physicsObj != nullptr && physicsObj->physicsId == trace->c.physicsId )
      break;
    ++v3;
    v6 = &list[++v5];
    if ( v3 >= num )
      return nullptr;
  }
  return &list[v3];
}


// ========================================================================
// ?Event_GetUser@idProp_WeaponStatic@@AAA?AVeventEntity@@XZ
// EA  : 0x82D50188
// RVA : 0x00D50188
// PDB : w:\tech5\tungsten\game\entities\weaponstatic.cpp
// ========================================================================

idProp_WeaponStatic *__fastcall idProp_WeaponStatic::Event_GetUser(idProp_WeaponStatic *this, eventEntity *result)
{
  idEntity *value; // r10
  idActor *v4; // r3
  idActor *v5; // r4

  value = result[1354].value;
  if ( gameLocal->spawnIds.ptr[(unsigned __int16)value & 0x1FFF] == (int)value >> 13
    && (v4 = (idActor *)gameLocal->entities.ptr[(unsigned __int16)value & 0x1FFF]) != nullptr )
  {
    v5 = idActor::CastTo(c: v4);
  }
  else
  {
    v5 = nullptr;
  }
  eventEntity::eventEntity((eventEntity *)this, e: v5);
  return this;
}


// ========================================================================
// ?TestFire@idProp_WeaponStatic@@QAA_NXZ
// EA  : 0x82D50310
// RVA : 0x00D50310
// PDB : w:\tech5\tungsten\game\entities\weaponstatic.cpp
// ========================================================================

int __fastcall idProp_WeaponStatic::TestFire(idProp_WeaponStatic *this)
{
  int value; // r10
  idActor *v3; // r3
  idAI2 *v4; // r3
  idAI2 *v5; // r25
  int v6; // r9
  idGameLocal *v7; // r11
  idActor *v8; // r3
  idActor *v9; // r3
  idEntity *v10; // r30
  const idPresentable *presentable; // r28
  int v12; // r9
  idActor *v13; // r3
  idActor *v14; // r30
  idPresentable *v15; // r4
  idProp_Breakable *v16; // r3
  int v18[4]; // [sp+50h] [-A50h] BYREF
  testForBlockedTraceParms_t v19; // [sp+60h] [-A40h] BYREF
  idVec3 v20; // [sp+70h] [-A30h] BYREF
  idMat3 v21; // [sp+80h] [-A20h] BYREF
  idFireParms v22; // [sp+B0h] [-9F0h] BYREF
  idTestFireResults v23; // [sp+150h] [-950h] BYREF

  value = this->user.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v3 = (idActor *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v4 = (idAI2 *)idActor::CastTo(c: v3);
  }
  else
  {
    v4 = nullptr;
  }
  v5 = idAI2::CastTo(c: v4);
  if ( v5 != nullptr
    && (unsigned __int8)idAnimatedEntity::GetTagPosition(
                          this,
                          propIndex: this->infopropIndex,
                          tagIndex: this->muzzleTagIndex,
                          origin: &v20,
                          axis: &v21) != 0 )
  {
    idFireParms::idFireParms(this: &v22);
    memset(&v23, 0, sizeof(v23));
    v6 = this->user.spawnId.value;
    v7 = gameLocal;
    *((_BYTE *)&v22 + 128) |= 0x20u;
    if ( gameLocal->spawnIds.ptr[v6 & 0x1FFF] == v6 >> 13
      && (v8 = (idActor *)gameLocal->entities.ptr[v6 & 0x1FFF]) != nullptr )
    {
      v9 = idActor::CastTo(c: v8);
      v7 = gameLocal;
      v10 = v9;
    }
    else
    {
      v10 = nullptr;
    }
    if ( v10->presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this: v10);
      v7 = gameLocal;
    }
    presentable = v10->presentable;
    v12 = this->user.spawnId.value;
    if ( v7->spawnIds.ptr[v12 & 0x1FFF] == v12 >> 13 && (v13 = (idActor *)v7->entities.ptr[v12 & 0x1FFF]) != nullptr )
      v14 = idActor::CastTo(c: v13);
    else
      v14 = nullptr;
    v15 = v14->presentable;
    if ( v15 == nullptr )
    {
      idEntity::InitPresentableInternal(this: v14);
      v15 = v14->presentable;
    }
    if ( idWeapon::TestFire(
           this: this->weapon,
           attacker: v15,
           target: presentable,
           start: &v20,
           fireAxis: &v21,
           fp: &v22,
           tfr: &v23,
           secondaryAmmo: false) )
    {
      v18[0] = 0;
      v19.blockOnFriendly = true;
      v19.blockOnBreakableFraction = 0.5;
      v19.minImpactDelta = 128000.0;
      v19.minTravelRatio = 0.5;
      v16 = idAI2::TestForBlockedTrace(this: v5, fp: &v22, tfr: &v23, outNumBlocked: v18, testParms: &v19);
      if ( v18[0] == 0 && v16 == nullptr )
      {
        idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v22.targetList);
        return 1;
      }
    }
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v22.targetList);
  }
  return 0;
}


// ========================================================================
// __unwind$493804
// EA  : 0x82D5055C
// RVA : 0x00D5055C
// PDB : w:\tech5\tungsten\game\entities\weaponstatic.cpp
// ========================================================================

void _unwind_493804()
{
  int v0; // r12

  idFireParms::~idFireParms(this: (idAI2::idAIVolatile::idAIEventInfo *)(v0 - 2720 + 176));
}


// ========================================================================
// ?AIShouldFire@idProp_WeaponStatic@@QAA_NPBVidAI2@@@Z
// EA  : 0x82D50588
// RVA : 0x00D50588
// PDB : w:\tech5\tungsten\game\entities\weaponstatic.cpp
// ========================================================================

BOOL __fastcall idProp_WeaponStatic::AIShouldFire(idProp_WeaponStatic *this, idAI2 *ai)
{
  int nextBurstTime; // r30
  idPresentable *presentable; // r3
  idAI2 *v7; // r3
  unsigned int overheating; // r8
  int v9; // r31
  const aiSenseState_t *EnemySenseState; // r3
  aiSenseState_t *v11; // r30
  int GameMs; // r29
  int ConfirmedStimTimeSafe; // r3

  nextBurstTime = ai->aiVolatile.memory.nextBurstTime;
  if ( nextBurstTime > idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) )
    return false;
  presentable = this->presentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    presentable = this->presentable;
  }
  overheating = presentable->GetWeaponStaticInterface(this: presentable)->overheating;
  v7 = ai;
  v9 = (_cntlzw(overheating) & 0x20) != 0;
  EnemySenseState = idAI2::GetEnemySenseState(this: v7, senseType: AISENSE_MAX);
  v11 = (aiSenseState_t *)EnemySenseState;
  if ( v9 != 0 && EnemySenseState != nullptr )
  {
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    ConfirmedStimTimeSafe = aiSenseState_t::GetConfirmedStimTimeSafe(this: v11);
    v9 = __CFADD__(15000 - (GameMs - ConfirmedStimTimeSafe), (GameMs - ConfirmedStimTimeSafe) ^ 0x80000000) ? 0 : v9;
  }
  if ( (_BYTE)v9 != 0 )
    return (unsigned __int8)idProp_WeaponStatic::TestFire(this) != 0;
  return v9;
}


// ========================================================================
// ?Spawn@idProp_WeaponStatic@@QAAXXZ
// EA  : 0x82D506A0
// RVA : 0x00D506A0
// PDB : w:\tech5\tungsten\game\entities\weaponstatic.cpp
// ========================================================================

void __fastcall idProp_WeaponStatic::Spawn(idProp_WeaponStatic *this)
{
  idSplinePath *v2; // r3
  idSplinePath *v3; // r3
  idCurve_Spline<idVec3> *v4; // r3
  idPresentable *presentable; // r11
  idPresentable *v6; // r11
  idPhysics *Physics; // r29
  idPhysics *v8; // r28
  idPhysics *v9; // r3
  idPhysics_vtbl *v10; // r29
  int (__fastcall *GetContents)(idPhysics *, int); // ctr
  int v12; // r3
  idWeapon *v13; // r29
  idWeapon *v14; // r3
  const idDeclWeapon *weaponDecl; // r11
  int v16; // r28
  int v17; // r29
  const idDeclAmmo *validAmmoDecl; // r10
  int v19; // r3
  const idDeclWeapon *v20; // r11
  barrelProps_t *v21; // r29
  idIndex<short,enum invalidJointIndex_t> *TreeAnimatorFromPresentable; // r3
  idIndex<short,enum invalidJointIndex_t> *v23; // r21
  const char *v24; // r5
  __int16 *JointIndex; // r3
  int len; // r10
  const char *v27; // r5
  idPropsCollection *v28; // r11
  idPropsCollection *v29; // r27
  int PropIndex; // r3
  int TagIndex; // r3
  int num; // r6
  int v33; // r26
  int v34; // r28
  barrelProps_t *v35; // r29
  char *str; // r5
  char v37; // r11
  int infopropIndex; // r4
  int v39; // r3
  char *v40; // r11
  char v41; // r11
  bool v42; // zf
  int v43; // r3
  idGameTimeManager *v44; // r3
  int v45; // r28
  int v46; // r29
  const idDeclEntityDef *v47; // r5
  int v48; // r25
  int v49; // r26
  idWeaponStatic_Armour *v50; // r29
  char *v51; // r11
  char v52; // r11
  idClipModel *v53; // r3
  idClipModel *v54; // r28
  idPhysics_Static *v55; // r3
  idPhysics_Static *v56; // r3
  idPresentable *v57; // r28
  int entityNumber; // r17
  const idDeclFX *v59; // r3
  idPresentable *v60; // r3
  idPresentable *v61; // r4
  int v62; // r10
  int v63; // r9
  int v64; // r8
  int v65; // r7
  idPresentable *v66; // r3
  idRenderModel *model; // r11
  char v68; // r11
  idPresentable *v69; // r11
  idPresentable *v70; // r3
  idPresentableWeaponStatic *v71; // r3
  idPresentableWeaponStatic *v72; // r29
  double minPitch; // fp0
  double maxYaw; // fp11
  idRenderModel *v75; // r11
  idPhysics *v76; // r3
  idBounds *v77; // r3
  int v78; // [sp+8h] [-178h]
  int v79; // [sp+Ch] [-174h]
  int v80; // [sp+10h] [-170h]
  int v81; // [sp+14h] [-16Ch]
  int v82; // [sp+18h] [-168h]
  idPresentable *v83; // [sp+1Ch] [-164h]
  idAttachmentCollection v84; // [sp+50h] [-130h] BYREF
  float v85; // [sp+64h] [-11Ch]
  float v86; // [sp+68h] [-118h]
  float v87; // [sp+6Ch] [-114h]
  float v88; // [sp+70h] [-110h]
  float v89; // [sp+74h] [-10Ch]
  float x; // [sp+78h] [-108h]
  float y; // [sp+7Ch] [-104h]
  float z; // [sp+80h] [-100h]
  idVec3 v93; // [sp+88h] [-F8h] BYREF
  float v94[6]; // [sp+98h] [-E8h] BYREF
  idAnimatorParms_Base v95; // [sp+B0h] [-D0h] BYREF
  idIndex<short,enum invalidJointIndex_t> *v96; // [sp+E8h] [-98h]
  int v97; // [sp+ECh] [-94h]

  this->currentHealth = this->health;
  if ( gameLocal->spawnIds.ptr[this->splinePath.spawnId.value & 0x1FFF] == this->splinePath.spawnId.value >> 13 )
  {
    v2 = (idSplinePath *)gameLocal->entities.ptr[this->splinePath.spawnId.value & 0x1FFF];
    if ( v2 != nullptr )
      v3 = idSplinePath::CastTo(c: v2);
    else
      v3 = nullptr;
    v4 = idSplinePath::AllocSpline(this: v3);
    this->spline = v4;
    v84.attachments.list = (idAttachment *)v4;
    this->currentSplinePos = v4->times.list[v4->values.num - 1] * (float)0.5;
    ((void (__fastcall *)(idVec3 *, idCurve_Spline<idVec3> *))v4->GetCurrentValue)(a1: &v93, a2: v4);
    idEntity::SetOrigin(this, org: &v93);
    presentable = this->presentable;
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      presentable = this->presentable;
    }
    presentable->origin.x = v93.x;
    v84.attachments.list = (idAttachment *)&presentable->origin;
    presentable->origin.y = v93.y;
    presentable->origin.z = v93.z;
    ((void (__fastcall *)(float *, double))this->spline->GetCurrentFirstDerivative)(a1: v94, a2: this->currentSplinePos);
    v89 = -v94[2];
    v87 = -v94[0];
    x = vec3_up.x;
    y = vec3_up.y;
    z = vec3_up.z;
    v88 = -v94[1];
    idMat3::OrthoNormalizeSelf(this: (idMat3 *)&v84.parent, prio1: 1, prio2: 2);
    this->SetAxis(this, a2: (const idMat3 *)&v84.parent);
    v6 = this->presentable;
    if ( v6 == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      v6 = this->presentable;
    }
    v6->axis.mat[0].x = *(float *)&v84.parent;
    v84.attachments.list = (idAttachment *)&v6->axis.mat[2];
    v6->axis.mat[0].y = v85;
    v6->axis.mat[0].z = v86;
    v6->axis.mat[1].x = v87;
    v6->axis.mat[1].y = v88;
    v6->axis.mat[1].z = v89;
    v6->axis.mat[2].x = x;
    v6->axis.mat[2].y = y;
    v6->axis.mat[2].z = z;
  }
  Physics = idEntity::GetPhysics(this);
  v8 = idEntity::GetPhysics(this);
  v9 = Physics;
  GetContents = Physics->GetContents;
  v10 = v8->__vftable;
  v12 = GetContents(this: v9, a2: -1);
  v10->SetContents(this: v8, a2: v12 | 0x200, a3: -1);
  v13 = (idWeapon *)idInventoryItem::Create(decl: this->weaponDecl);
  v14 = idWeapon::CastTo(c: v13);
  this->weapon = v14;
  if ( v14 != nullptr )
  {
    if ( this->playerAmmoDecl == nullptr || this->aiAmmoDecl == nullptr )
    {
      weaponDecl = this->weaponDecl;
      if ( weaponDecl != nullptr )
      {
        v16 = 0;
        if ( weaponDecl->validAmmoClips.num > 0 )
        {
          v17 = 0;
          do
          {
            validAmmoDecl = this->weaponDecl->validAmmoClips.list[v17].validAmmoDecl;
            if ( validAmmoDecl != nullptr )
            {
              v84.attachments.list = (idAttachment *)&this->weaponDecl->validAmmoClips.list[v17];
              v19 = idStr::Find(
                      searchIn: validAmmoDecl->name.str,
                      searchFor: "player",
                      casesensitive: false,
                      start: 0,
                      end: -1);
              v20 = this->weaponDecl;
              if ( v19 == -1 )
              {
                if ( idStr::Find(
                       searchIn: v20->validAmmoClips.list[v17].validAmmoDecl->name.str,
                       searchFor: "ai",
                       casesensitive: false,
                       start: 0,
                       end: -1) != -1 )
                  this->aiAmmoDecl = this->weaponDecl->validAmmoClips.list[v17].validAmmoDecl;
              }
              else
              {
                this->playerAmmoDecl = v20->validAmmoClips.list[v17].validAmmoDecl;
              }
            }
            ++v16;
            ++v17;
          }
          while ( v16 < this->weaponDecl->validAmmoClips.num );
        }
        if ( this->playerAmmoDecl == nullptr || this->aiAmmoDecl == nullptr )
        {
          this->playerAmmoDecl = nullptr;
          this->aiAmmoDecl = nullptr;
        }
      }
    }
  }
  else if ( v13 != nullptr )
  {
    ((void (__fastcall *)(idWeapon *, int))v13->dtr_idClass)(a1: v13, a2: 1);
  }
  if ( this->barrels.num <= 0 )
  {
    v21 = idList<barrelProps_t,5>::Alloc(this: &this->barrels);
    idAtomicString::Set(this: &v21->muzzleTag, str_: "muzzle");
    idAtomicString::Set(this: &v21->ejectTag, str_: &byte_8200D768);
    v21->primary = true;
  }
  TreeAnimatorFromPresentable = (idIndex<short,enum invalidJointIndex_t> *)idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
  v23 = TreeAnimatorFromPresentable;
  if ( TreeAnimatorFromPresentable != nullptr )
  {
    v24 = this->namePitchJoint.len != 0 ? this->namePitchJoint.data : "gun";
    JointIndex = (__int16 *)idTreeAnimator::GetJointIndex(
                              this: (idTreeAnimator *)&v84,
                              result: TreeAnimatorFromPresentable,
                              jointName: v24);
    len = this->nameYawJoint.len;
    this->jointPitch.value = *JointIndex;
    v27 = len != 0 ? this->nameYawJoint.data : "disk";
    this->jointYaw.value = HIWORD(idTreeAnimator::GetJointIndex(
                                    this: (idTreeAnimator *)&v84,
                                    result: v23,
                                    jointName: v27)->__vftable);
    v28 = *(idPropsCollection **)&v23[1016].value;
    if ( v28 != nullptr )
    {
      v29 = v28 + 22;
      if ( v28 != (idPropsCollection *)-352 )
      {
        PropIndex = idPropsCollection::FindPropIndex(this: v29, propName: idPropInfo::INFO_PROP_NAME);
        this->infopropIndex = PropIndex;
        this->muzzleTagIndex = idPropsCollection::FindTagIndex(this: v29, propIdx: PropIndex, tagName: "muzzle");
        this->cameraTagIndex = idPropsCollection::FindTagIndex(
                                 this: v29,
                                 propIdx: this->infopropIndex,
                                 tagName: "camera");
        this->ironSightTagIndex = idPropsCollection::FindTagIndex(
                                    this: v29,
                                    propIdx: this->infopropIndex,
                                    tagName: "ironSight");
        TagIndex = idPropsCollection::FindTagIndex(this: v29, propIdx: this->infopropIndex, tagName: "use");
        num = this->barrels.num;
        this->useTagIndex = TagIndex;
        v33 = 0;
        if ( num > 0 )
        {
          v34 = 0;
          do
          {
            v35 = &this->barrels.list[v34];
            str = (char *)v35->muzzleTag.str;
            if ( v35->muzzleTag.str == &byte_8200D768 || (v37 = 0, *str == 0) )
              v37 = 1;
            if ( v37 == 0 )
            {
              infopropIndex = this->infopropIndex;
              v84.attachments.list = (idAttachment *)v35->muzzleTag.str;
              v39 = idPropsCollection::FindTagIndex(this: v29, propIdx: infopropIndex, tagName: str);
              v35->muzzleTagIndex = v39;
              if ( v39 == -1 )
                idLib::Warning(
                  fmt: "idProp_WeaponStatic: muzzle tag '%s' not found for '%s'",
                  v35->muzzleTag.str,
                  this->name.data);
            }
            v40 = (char *)v35->ejectTag.str;
            if ( v40 == &byte_8200D768 || (v42 = *v40 != 0, v41 = 0, !v42) )
              v41 = 1;
            if ( v41 == 0 )
            {
              v43 = idPropsCollection::FindTagIndex(this: v29, propIdx: this->infopropIndex, tagName: v35->ejectTag.str);
              v35->ejectTagIndex = v43;
              if ( v43 == -1 )
                idLib::Warning(
                  fmt: "idProp_WeaponStatic: shell eject tag '%s' not found for '%s'",
                  v35->ejectTag.str,
                  this->name.data);
            }
            ++v33;
            ++v34;
          }
          while ( v33 < this->barrels.num );
        }
      }
    }
  }
  if ( (unsigned __int8)Get_idCombatStage_useRelaxedChatterVO(ptr: (unsigned __int8 *)this) == 0 )
    idEntity::BecomeActive(this, flags: 5);
  v95.animStack = this->GetAnimStack_2(this);
  idStr::idStr(this: &v95.name, text: "jointmod");
  v96 = v23;
  v95.blendOp = BOP_LERP;
  memset(&v95.originBlend, 0, 12);
  v95.alpha = 1.0;
  v97 = 0;
  v44 = gameLocal->GetGameTimeManager(this: gameLocal);
  idAnimator_Base::Init(this: &this->jointModAnimator, gametimeManager: v44, parms: &v95);
  v45 = 0;
  if ( this->attachmentDefs.num > 0 )
  {
    v46 = 0;
    do
    {
      v47 = this->attachmentDefs.list[v46];
      if ( v47 != nullptr )
        idAttachmentCollection::AddAttachment(
          this: &v84,
          result: &this->attachments,
          entityDef: v47,
          tag: "default",
          forceReplicationFlags: -1);
      ++v45;
      ++v46;
    }
    while ( v45 < this->attachmentDefs.num );
  }
  v48 = 0;
  if ( this->armourPieces.num > 0 )
  {
    v49 = 0;
    do
    {
      v50 = &this->armourPieces.list[v49];
      v50->jointIndex.value = -1;
      if ( v23 != nullptr )
        v50->jointIndex.value = HIWORD(idTreeAnimator::GetJointIndex(
                                         this: (idTreeAnimator *)&v84,
                                         result: v23,
                                         jointName: v50->joint.data)->__vftable);
      v51 = (char *)v50->clipModel.str;
      if ( v51 == &byte_8200D768 || (v42 = *v51 != 0, v52 = 0, !v42) )
        v52 = 1;
      if ( v52 == 0 )
      {
        v53 = (idClipModel *)idMem::AllocWithLocation(
                               this: &mem,
                               location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                               size: 0xD8u,
                               tag: TAG_CLIPMODEL,
                               zeroBuffer: false,
                               align: ALIGN_16,
                               heap: HEAP_DEFAULTHEAP);
        v84.attachments.num = (int)v53;
        v54 = v53 != nullptr
            ? idClipModel::idClipModel(
                this: v53,
                clip: &clientGame->clip,
                name: v50->clipModel.str,
                overrideClipMaterial: nullptr)
            : nullptr;
        if ( v54 != nullptr )
        {
          v55 = (idPhysics_Static *)idMem::AllocWithLocation(
                                      this: &mem,
                                      location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                      size: 0xA8u,
                                      tag: TAG_GAME,
                                      zeroBuffer: false,
                                      align: ALIGN_16,
                                      heap: HEAP_DEFAULTHEAP);
          v84.attachments.num = (int)v55;
          if ( v55 != nullptr )
            v56 = idPhysics_Static::idPhysics_Static(this: v55);
          else
            v56 = nullptr;
          v50->physicsObj = v56;
          if ( v56 != nullptr )
          {
            idPhysics::InitPhysics(
              this: v56,
              clip_: &clientGame->clip,
              callbacks_: &this->physicsCallbacks,
              entityNumber_: this->entityNumber);
            ((void (__fastcall *)(idPhysics *, idClipModel *, double))v50->physicsObj->SetClipModel)(
              a1: v50->physicsObj,
              a2: v54,
              a3: 1.0);
            v50->physicsObj->SetClipMask(this: v50->physicsObj, a2: 1, a3: -1);
            v50->physicsObj->LinkClip(this: v50->physicsObj);
          }
          else
          {
            idClipModel::Delete(this: v54);
          }
        }
      }
      v57 = (idPresentable *)idMem::AllocWithLocation(
                               this: &mem,
                               location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                               size: 0x4B0u,
                               tag: TAG_PRESENTABLE,
                               zeroBuffer: false,
                               align: ALIGN_16,
                               heap: HEAP_DEFAULTHEAP);
      v84.attachments.num = (int)v57;
      if ( v57 != nullptr )
      {
        entityNumber = this->entityNumber;
        v59 = this->GetFXDecl(this);
        v60 = idPresentable::idPresentable(
                this: v57,
                e: this,
                renderModel_: (idTreeAnimator *)v50->renderModel,
                entityNumber_: entityNumber,
                fxDecl_: v59);
      }
      else
      {
        v60 = nullptr;
      }
      v50->presentable = v60;
      idPresentable::SetEntityNumber(this: v60, value: 0x1FFF);
      v50->presentable->debugName = idClass::GetClassname(this);
      v61 = v50->presentable;
      v50->currentHealth = v50->health;
      v50->brokenTimestamp = -1;
      idClientGame::AddPresentable(
        this: clientGame,
        presentable: v61,
        index: -1,
        skipReplication: false,
        a5: v65,
        a6: v64,
        a7: v63,
        a8: v62,
        a9: v78,
        a10: v79,
        a11: v80,
        a12: v81,
        a13: v82,
        a14: v83);
      ++v48;
      ++v49;
    }
    while ( v48 < this->armourPieces.num );
  }
  v66 = this->presentable;
  if ( v66 == nullptr
    || (model = v66->model, v84.attachments.num = (int)this->presentable, v42 = model != nullptr, v68 = 1, !v42) )
  {
    v68 = 0;
  }
  if ( v68 != 0 )
  {
    if ( v66 == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      v66 = this->presentable;
    }
    idPresentable::SetParm(this: v66, parm: rp->Color, scalar: 0.0);
    v69 = this->presentable;
    if ( v69 == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      v69 = this->presentable;
    }
    v69->Present(this: v69);
  }
  v70 = this->presentable;
  if ( v70 == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    v70 = this->presentable;
  }
  v71 = v70->GetWeaponStaticInterface(this: v70);
  v72 = v71;
  if ( v71 != nullptr )
  {
    v71->maxHeat = this->maxHeat;
    minPitch = this->minPitch;
    v71->maxPitch = this->maxPitch;
    v71->minPitch = minPitch;
    maxYaw = this->maxYaw;
    v71->minYaw = this->minYaw;
    v71->maxYaw = maxYaw;
    v71->weaponDecl = this->weaponDecl;
    idPresentableWeaponStatic::SetClientWeapon(this: v71, weapon: this->weapon);
    v72->clipForwardAmount = this->clipForwardAmount;
    v72->windupTime = this->windupTimer;
    idList<barrelProps_t,5>::operator=(this: &v72->barrels, other: &this->barrels);
    if ( (unsigned __int8)idProp_Usable::IsUsable(this) == 0 )
    {
      v75 = v72->model;
      v72->highlightColor = HIGHLIGHT_COLOR_NONE;
      v75->g.highlightColor = HIGHLIGHT_COLOR_NONE;
    }
  }
  v76 = idEntity::GetPhysics(this);
  v77 = (idBounds *)v76->GetAbsBounds(this: v76, a2: -1);
  idEntity::UpdatePVSAreas(this, bounds: v77);
  idStr::FreeData(this: &v95.name);
}


// ========================================================================
// __unwind$494265
// EA  : 0x82D5111C
// RVA : 0x00D5111C
// PDB : w:\tech5\tungsten\game\entities\weaponstatic.cpp
// ========================================================================

void _unwind_494265()
{
  int v0; // r12

  idAnimatorParms_EndAdditiveChannels::~idAnimatorParms_EndAdditiveChannels(this: (vaiAction_t::vehicleCam_t *)(v0 - 384 + 176));
}


// ========================================================================
// __unwind$494266
// EA  : 0x82D51144
// RVA : 0x00D51144
// PDB : w:\tech5\tungsten\game\entities\weaponstatic.cpp
// ========================================================================

void _unwind_494266()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 384 + 84), tag: TAG_CLIPMODEL);
}


// ========================================================================
// __unwind$494267
// EA  : 0x82D51170
// RVA : 0x00D51170
// PDB : w:\tech5\tungsten\game\entities\weaponstatic.cpp
// ========================================================================

void _unwind_494267()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 384 + 84), tag: TAG_GAME);
}


// ========================================================================
// __unwind$494268
// EA  : 0x82D5119C
// RVA : 0x00D5119C
// PDB : w:\tech5\tungsten\game\entities\weaponstatic.cpp
// ========================================================================

void _unwind_494268()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 384 + 84), tag: TAG_PRESENTABLE);
}


// ========================================================================
// ??0idProp_WeaponStatic@@QAA@XZ
// EA  : 0x82D51238
// RVA : 0x00D51238
// PDB : w:\tech5\tungsten\game\entities\weaponstatic.cpp
// ========================================================================

idProp_WeaponStatic *__fastcall idProp_WeaponStatic::idProp_WeaponStatic(idProp_WeaponStatic *this)
{
  int v2; // ctr
  idIndex<short,enum invalidJointIndex_t> *p_jointYaw; // r9
  float *p_y; // r10
  float *p_z; // r10
  float *v6; // r11
  int i; // ctr
  char flags; // r4

  idProp_Usable::idProp_Usable(this);
  this->__vftable = (idProp_WeaponStatic_vtbl *)&idProp_WeaponStatic::`vftable';
  this->nameYawJoint.len = 0;
  this->nameYawJoint.allocedAndFlag = 20;
  this->nameYawJoint.data = this->nameYawJoint.baseBuffer;
  this->nameYawJoint.baseBuffer[0] = 0;
  this->namePitchJoint.allocedAndFlag = 20;
  this->namePitchJoint.len = 0;
  this->namePitchJoint.data = this->namePitchJoint.baseBuffer;
  this->namePitchJoint.baseBuffer[0] = 0;
  this->weaponDecl = nullptr;
  this->playerAmmoDecl = nullptr;
  this->aiAmmoDecl = nullptr;
  this->playerDeferredFire = false;
  this->turnSpeed = 1.0;
  this->minPitch = 40.0;
  this->maxPitch = 40.0;
  this->minYaw = 120.0;
  this->maxYaw = 120.0;
  this->maxAIYaw = 45.0;
  this->maxRange = 0.0;
  this->minRange = 80.0;
  this->lookConeDegrees = 0.0;
  this->travelSafetyMargin = 0.5;
  this->rangeSafetyMargin = 0.2;
  this->reserveRadiusFeet = 20.0;
  this->viewFov = -1.0;
  this->armourPieces.granularity = 0;
  this->armourPieces.memTag = 5;
  this->armourPieces.listStatic = 0;
  this->armourPieces.list = nullptr;
  this->armourPieces.size = 0;
  this->armourPieces.num = 0;
  this->weapon = nullptr;
  this->user.spawnId.value = 0x1FFF;
  this->jointYaw.value = -1;
  v2 = 9;
  this->jointPitch.value = -1;
  p_jointYaw = &this->jointYaw;
  p_y = &mat2_identity.mat[1].y;
  do
  {
    ++p_y;
    p_jointYaw += 2;
    *(float *)&p_jointYaw->value = *p_y;
    --v2;
  }
  while ( v2 != 0 );
  p_z = &this->lookAt.mat[2].z;
  v6 = &mat2_identity.mat[1].y;
  for ( i = 9; i != 0; --i )
    *++p_z = *++v6;
  idAnimator_JointMod::idAnimator_JointMod(this: &this->jointModAnimator);
  this->windupTimer = 0.0;
  this->turning = 0;
  this->currentHealth = 0.0;
  this->enabled = true;
  this->windupTime = 0.5;
  this->blockCoolDown = false;
  this->health = 0.0;
  this->coolDownTime = 0;
  this->barrelIndex = 0;
  this->infopropIndex = -1;
  this->muzzleTagIndex = -1;
  this->cameraTagIndex = -1;
  this->ironSightTagIndex = -1;
  this->useTagIndex = -1;
  this->barrels.list = nullptr;
  this->barrels.granularity = 0;
  this->barrels.memTag = 5;
  this->barrels.listStatic = 0;
  this->barrels.size = 0;
  this->barrels.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->barrels);
  this->coolDownDelay = 0.0;
  this->fireInOrder = false;
  this->sndTurning = nullptr;
  this->sndFireLoop = nullptr;
  this->sndFireStop = nullptr;
  this->clipForwardAmount = 22.0;
  this->sndOverheat = nullptr;
  this->deadModel = nullptr;
  this->heatPerSecFiring = 15;
  this->heatCooledPerSec = 20;
  this->maxHeat = 100;
  this->coolHeat = 0;
  this->blockCoolDownUntil = 0;
  this->aiHeatPerSecFiring = 15;
  this->aiHeatCooledPerSec = 20;
  this->aiMaxHeat = 100;
  this->aiCoolHeat = 15;
  this->overheatParticle = nullptr;
  this->attachmentDefs.list = nullptr;
  this->attachmentDefs.granularity = 0;
  this->attachmentDefs.memTag = 5;
  this->attachmentDefs.listStatic = 0;
  this->attachmentDefs.size = 0;
  this->attachmentDefs.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->attachmentDefs);
  *((_BYTE *)this + 5748) &= 7u;
  idMQBuffer::idMQBuffer(this: &this->attachments);
  this->exitTargets.list = nullptr;
  this->exitTargets.granularity = 0;
  this->exitTargets.memTag = 5;
  this->exitTargets.listStatic = 0;
  this->exitTargets.size = 0;
  this->exitTargets.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->exitTargets);
  this->splinePath.spawnId.value = 0x1FFF;
  this->currentSplinePos = 0.0;
  this->spline = nullptr;
  this->lastUpdateTime = 0;
  this->anglesOffset.z = 0.0;
  this->anglesOffset.y = 0.0;
  this->anglesOffset.x = 0.0;
  flags = (char)this->flags;
  this->attachments.parent = this;
  *(_BYTE *)&this->flags = flags | 0x40;
  return this;
}


// ========================================================================
// __unwind$494808
// EA  : 0x82D51528
// RVA : 0x00D51528
// PDB : w:\tech5\tungsten\game\entities\weaponstatic.cpp
// ========================================================================

void _unwind_494808()
{
  int v0; // r12

  idProp_Static::~idProp_Static(this: *(idProp_Static **)(v0 - 176 + 196));
}


// ========================================================================
// __unwind$494809
// EA  : 0x82D51550
// RVA : 0x00D51550
// PDB : w:\tech5\tungsten\game\entities\weaponstatic.cpp
// ========================================================================

void _unwind_494809()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 176 + 196) + 5264));
}


// ========================================================================
// __unwind$494810
// EA  : 0x82D5157C
// RVA : 0x00D5157C
// PDB : w:\tech5\tungsten\game\entities\weaponstatic.cpp
// ========================================================================

void _unwind_494810()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 176 + 196) + 5296));
}


// ========================================================================
// __unwind$494811
// EA  : 0x82D515A8
// RVA : 0x00D515A8
// PDB : w:\tech5\tungsten\game\entities\weaponstatic.cpp
// ========================================================================

void _unwind_494811()
{
  int v0; // r12

  idList<idWeaponStatic_Armour,5>::~idList<idWeaponStatic_Armour,5>(this: (idList<idWeaponStatic_Armour,5> *)(*(_DWORD *)(v0 - 176 + 196) + 5396));
}


// ========================================================================
// __unwind$494812
// EA  : 0x82D515D4
// RVA : 0x00D515D4
// PDB : w:\tech5\tungsten\game\entities\weaponstatic.cpp
// ========================================================================

void _unwind_494812()
{
  int v0; // r12

  idAnimator_JointMod::~idAnimator_JointMod(this: (idAnimator_JointMod *)(*(_DWORD *)(v0 - 176 + 196) + 5508));
}


// ========================================================================
// __unwind$494813_0
// EA  : 0x82D51600
// RVA : 0x00D51600
// PDB : w:\tech5\tungsten\game\entities\weaponstatic.cpp
// ========================================================================

void _unwind_494813_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 176 + 196) + 5644));
}


// ========================================================================
// __unwind$494814_0
// EA  : 0x82D5162C
// RVA : 0x00D5162C
// PDB : w:\tech5\tungsten\game\entities\weaponstatic.cpp
// ========================================================================

void _unwind_494814_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 176 + 196) + 5732));
}


// ========================================================================
// __unwind$494815_0
// EA  : 0x82D51658
// RVA : 0x00D51658
// PDB : w:\tech5\tungsten\game\entities\weaponstatic.cpp
// ========================================================================

void _unwind_494815_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 176 + 196) + 5752));
}


// ========================================================================
// ??1idProp_WeaponStatic@@UAA@XZ
// EA  : 0x82D51770
// RVA : 0x00D51770
// PDB : w:\tech5\tungsten\game\entities\weaponstatic.cpp
// ========================================================================

void __fastcall idProp_WeaponStatic::~idProp_WeaponStatic(idProp_WeaponStatic *this)
{
  idPresentable *presentable; // r3
  idWeapon *weapon; // r3
  int v4; // r27
  int v5; // r28
  idWeaponStatic_Armour *v6; // r29
  idPresentable *v7; // r3
  idPhysics *physicsObj; // r3
  idEntityPtr<idEntity> *list; // r4
  idAttachment *v10; // r4
  const idDeclEntityDef **v11; // r4
  barrelProps_t *v12; // r4
  idWeaponStatic_Armour *v13; // r27
  int size; // r29
  idStr *p_joint; // r28

  this->__vftable = (idProp_WeaponStatic_vtbl *)&idProp_WeaponStatic::`vftable';
  presentable = this->presentable;
  if ( presentable == nullptr || presentable->GetWeaponStaticInterface(this: presentable) == nullptr )
  {
    weapon = this->weapon;
    if ( weapon != nullptr )
      ((void (__fastcall *)(idWeapon *, int))weapon->dtr_idClass)(a1: weapon, a2: 1);
    this->weapon = nullptr;
  }
  v4 = 0;
  if ( this->armourPieces.num > 0 )
  {
    v5 = 0;
    do
    {
      v6 = &this->armourPieces.list[v5];
      v7 = v6->presentable;
      if ( v7 != nullptr )
      {
        idPresentable::Delete(this: v7);
        v6->presentable = nullptr;
      }
      physicsObj = v6->physicsObj;
      if ( physicsObj != nullptr )
      {
        ((void (__fastcall *)(idPhysics *, int))physicsObj->dtr_idPhysics)(a1: physicsObj, a2: 1);
        v6->physicsObj = nullptr;
      }
      ++v4;
      ++v5;
    }
    while ( v4 < this->armourPieces.num );
  }
  if ( this->exitTargets.listStatic == 0 || this->exitTargets.listStatic == 2 )
  {
    list = this->exitTargets.list;
    if ( list != nullptr )
      idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
    this->exitTargets.list = nullptr;
    this->exitTargets.size = 0;
  }
  this->exitTargets.num = 0;
  if ( this->attachments.attachments.listStatic == 0 || this->attachments.attachments.listStatic == 2 )
  {
    v10 = this->attachments.attachments.list;
    if ( v10 != nullptr )
      idMem::Free(this: &mem, ptr: v10, align: ALIGN_16);
    this->attachments.attachments.list = nullptr;
    this->attachments.attachments.size = 0;
  }
  this->attachments.attachments.num = 0;
  if ( this->attachmentDefs.listStatic == 0 || this->attachmentDefs.listStatic == 2 )
  {
    v11 = this->attachmentDefs.list;
    if ( v11 != nullptr )
      idMem::Free(this: &mem, ptr: v11, align: ALIGN_16);
    this->attachmentDefs.list = nullptr;
    this->attachmentDefs.size = 0;
  }
  this->attachmentDefs.num = 0;
  if ( this->barrels.listStatic == 0 || this->barrels.listStatic == 2 )
  {
    v12 = this->barrels.list;
    if ( v12 != nullptr )
      idMem::Free(this: &mem, ptr: v12, align: ALIGN_16);
    this->barrels.list = nullptr;
    this->barrels.size = 0;
  }
  this->barrels.num = 0;
  idAnimator_JointMod::~idAnimator_JointMod(this: &this->jointModAnimator);
  if ( this->armourPieces.listStatic == 0 || this->armourPieces.listStatic == 2 )
  {
    v13 = this->armourPieces.list;
    if ( v13 != nullptr )
    {
      size = this->armourPieces.size;
      if ( size > 0 )
      {
        p_joint = &v13->joint;
        do
        {
          idStr::FreeData(this: p_joint);
          --size;
          p_joint = (idStr *)((char *)p_joint + 72);
        }
        while ( size != 0 );
      }
      idMem::Free(this: &mem, ptr: v13, align: ALIGN_16);
    }
    this->armourPieces.list = nullptr;
    this->armourPieces.size = 0;
  }
  this->armourPieces.num = 0;
  idStr::FreeData(this: &this->namePitchJoint);
  idStr::FreeData(this: &this->nameYawJoint);
  idProp_Usable::~idProp_Usable(this);
}


// ========================================================================
// __unwind$495071
// EA  : 0x82D519CC
// RVA : 0x00D519CC
// PDB : w:\tech5\tungsten\game\entities\weaponstatic.cpp
// ========================================================================

void _unwind_495071()
{
  int v0; // r12

  idProp_Static::~idProp_Static(this: *(idProp_Static **)(v0 - 160 + 180));
}


// ========================================================================
// __unwind$495072
// EA  : 0x82D519F4
// RVA : 0x00D519F4
// PDB : w:\tech5\tungsten\game\entities\weaponstatic.cpp
// ========================================================================

void _unwind_495072()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 160 + 180) + 5264));
}


// ========================================================================
// __unwind$495073_0
// EA  : 0x82D51A20
// RVA : 0x00D51A20
// PDB : w:\tech5\tungsten\game\entities\weaponstatic.cpp
// ========================================================================

void _unwind_495073_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 160 + 180) + 5296));
}


// ========================================================================
// __unwind$495074
// EA  : 0x82D51A4C
// RVA : 0x00D51A4C
// PDB : w:\tech5\tungsten\game\entities\weaponstatic.cpp
// ========================================================================

void _unwind_495074()
{
  int v0; // r12

  idList<idWeaponStatic_Armour,5>::~idList<idWeaponStatic_Armour,5>(this: (idList<idWeaponStatic_Armour,5> *)(*(_DWORD *)(v0 - 160 + 180) + 5396));
}


// ========================================================================
// __unwind$495075
// EA  : 0x82D51A78
// RVA : 0x00D51A78
// PDB : w:\tech5\tungsten\game\entities\weaponstatic.cpp
// ========================================================================

void _unwind_495075()
{
  int v0; // r12

  idAnimator_JointMod::~idAnimator_JointMod(this: (idAnimator_JointMod *)(*(_DWORD *)(v0 - 160 + 180) + 5508));
}


// ========================================================================
// __unwind$495076_0
// EA  : 0x82D51AA4
// RVA : 0x00D51AA4
// PDB : w:\tech5\tungsten\game\entities\weaponstatic.cpp
// ========================================================================

void _unwind_495076_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 5644));
}


// ========================================================================
// __unwind$495077_0
// EA  : 0x82D51AD0
// RVA : 0x00D51AD0
// PDB : w:\tech5\tungsten\game\entities\weaponstatic.cpp
// ========================================================================

void _unwind_495077_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 5732));
}


// ========================================================================
// __unwind$495078
// EA  : 0x82D51AFC
// RVA : 0x00D51AFC
// PDB : w:\tech5\tungsten\game\entities\weaponstatic.cpp
// ========================================================================

void _unwind_495078()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 5752));
}


// ========================================================================
// __unwind$495079
// EA  : 0x82D51B28
// RVA : 0x00D51B28
// PDB : w:\tech5\tungsten\game\entities\weaponstatic.cpp
// ========================================================================

void _unwind_495079()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 5772));
}


// ========================================================================
// ?Use@idProp_WeaponStatic@@UAA_NPAVidEntity@@W4usableState_t@@@Z
// EA  : 0x82D51B60
// RVA : 0x00D51B60
// PDB : w:\tech5\tungsten\game\entities\weaponstatic.cpp
// ========================================================================

int __fastcall idProp_WeaponStatic::Use(idProp_WeaponStatic *this, idActor *_user, const usableState_t usable)
{
  unsigned __int64 v5; // r6
  const char *v6; // r7
  int value; // r9
  idEntityPtr<idActor> *p_user; // r26
  idActor *v9; // r3
  idActor *v10; // r3
  idActor *v11; // r3
  idPlayer *v12; // r3
  idPlayer *v13; // r3
  idPlayer *v14; // r29
  idVehicle *v15; // r3
  idVehicle *v16; // r3
  idPhysics_Player *PhysicsObj; // r3
  idPhysics *Physics; // r3
  float *v19; // r3
  double v20; // fp2
  double v21; // fp1
  idPhysics *v22; // r3
  idPhysics *v23; // r3
  idPlayer_vtbl *v24; // r30
  int v25; // r3
  idPlayerHud *PlayerHud; // r3
  idPresentable *presentable; // r3
  int v28; // r3
  idPresentable *v29; // r3
  int v30; // r3
  idPresentable *v31; // r3
  int v32; // r3
  idPresentable *v33; // r3
  int v34; // r3
  const idAngles *v35; // r3
  int v36; // r28
  int v37; // r30
  int v38; // r9
  idEntity *v39; // r3
  int v40; // r9
  idEntity *v41; // r3
  idEntity *v42; // r3
  idActor *v43; // r3
  idActor *v45; // r3
  idActor *v46; // r3
  idActor *v47; // r3
  idPlayer *v48; // r3
  idPlayer *v49; // r3
  idPlayer *v50; // r28
  int v51; // r29
  int v52; // r30
  int v53; // r9
  idEntity *v54; // r3
  idEntity *v55; // r3
  const idDeclAmmo *playerAmmoDecl; // r5
  idPresentable *v57; // r3
  int v58; // r3
  idVehicle *v59; // r3
  idVehicle *v60; // r3
  idPresentable *v61; // r3
  int v62; // r3
  idPresentable *v63; // r3
  int v64; // r3
  idPresentable *v65; // r3
  int v66; // r11
  idPlayerHud *v67; // r3
  int v68; // r9
  idCamera *v69; // r3
  idSpringCamera *v70; // r3
  idSpringCamera *v71; // r3
  BOOL manualUpdate; // r10
  idPresentable *v73; // r3
  int v74; // r3
  idPLog *pLog; // r29
  idPLog::logEntry_t *v76; // r30
  int v77; // r3
  __int64 totalTicks; // r11
  __int64 v79; // r9
  idPLogScope v80; // [sp+58h] [-88h] BYREF
  idVec3 v81; // [sp+60h] [-80h] BYREF
  idMat3 v82[3]; // [sp+70h] [-70h] BYREF

  RD_EventBegin(name: "idProp_WeaponStatic::Use");
  LODWORD(v5) = "idProp_WeaponStatic::Use";
  HIDWORD(v5) = 2;
  idPLogScope::idPLogScope(this: &v80, pl: &::pLog, gMask: v5, label: v6);
  value = this->user.spawnId.value;
  p_user = &this->user;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
  {
    v9 = (idActor *)gameLocal->entities.ptr[value & 0x1FFF];
    if ( v9 != nullptr && idActor::CastTo(c: v9) != nullptr )
    {
      if ( _user != nullptr )
      {
        idPLogScope::~idPLogScope(this: &v80);
        RD_EventEnd();
        return 0;
      }
      if ( (*((_BYTE *)this + 5748) & 0x40) != 0 )
      {
        v10 = idEntityPtr<idActor>::operator idActor *(this: &this->user);
        idEntity::Unbind(this: v10);
      }
      if ( gameLocal->spawnIds.ptr[p_user->spawnId.value & 0x1FFF] == p_user->spawnId.value >> 13
        && (v11 = (idActor *)gameLocal->entities.ptr[p_user->spawnId.value & 0x1FFF]) != nullptr )
      {
        v12 = (idPlayer *)idActor::CastTo(c: v11);
      }
      else
      {
        v12 = nullptr;
      }
      v13 = idPlayer::CastTo(c: v12);
      v14 = v13;
      if ( v13 != nullptr )
      {
        idPlayer::RemoveControl(this: v13, entity: this);
        idPlayer::ToggleZoom(this: v14, z: false);
        if ( v14->GetVehicle_2(this: v14) != nullptr )
        {
          v15 = v14->GetVehicle_2(this: v14);
          idVehicle::AllowAccelerate(this: v15, bl: true);
          v14->GetVehicle_2(this: v14)->allowWeaponChange = true;
          v16 = v14->GetVehicle_2(this: v14);
          idVehicle::AllowWeaponFiring(this: v16, bl: true);
        }
        else
        {
          if ( (*((_BYTE *)this + 5748) & 0x40) != 0 )
          {
            PhysicsObj = idPlayer::GetPhysicsObj(this: v14);
            idPhysics_Player::SetMovementType(this: PhysicsObj, type: PM_VEHICLE_NOCLIP);
          }
          this->GetUseLocation(this, a2: v14, a3: &v81);
          Physics = idEntity::GetPhysics(this);
          v19 = (float *)Physics->GetAxis(this: Physics, a2: 0);
          v20 = (float)((float)(v19[2] * (float)-1.0) * (float)16.0);
          v21 = (float)((float)(v19[1] * (float)-1.0) * (float)16.0);
          v81.x = (float)((float)(*v19 * (float)-1.0) * (float)16.0) + v81.x;
          v81.z = (float)v20 + v81.z;
          v81.y = v81.y + (float)v21;
          v22 = idEntity::GetPhysics(this);
          v81.z = v22->GetOrigin(this: v22, a2: 0)->z;
          idEntity::SetOrigin(this: v14, org: &v81);
          v23 = idEntity::GetPhysics(this);
          v24 = v14->__vftable;
          v25 = (int)v23->GetAxis(this: v23, a2: 0);
          v24->SetAxis(this: v14, a2: (const idMat3 *)v25);
          PlayerHud = (idPlayerHud *)idPlayer::GetPlayerHud(this: v14);
          idPlayerHud::SetHudState(this: PlayerHud, state: HUDSTATE_ALL);
          presentable = v14->presentable;
          if ( presentable != nullptr )
            v28 = (int)presentable->GetPlayerInterface_2(this: presentable);
          else
            v28 = 0;
          *(float *)(v28 + 19128) = 0.0;
          v29 = v14->presentable;
          if ( v29 != nullptr )
            v30 = (int)v29->GetPlayerInterface_2(this: v29);
          else
            v30 = 0;
          if ( v30 != -37616 )
          {
            v31 = v14->presentable;
            if ( v31 != nullptr )
              v32 = (int)v31->GetPlayerInterface_2(this: v31);
            else
              v32 = 0;
            idHands::Enable(this: (idHands *)(v32 + 37616));
            v33 = v14->presentable;
            if ( v33 != nullptr )
              v34 = (int)v33->GetPlayerInterface_2(this: v33);
            else
              v34 = 0;
            *(_BYTE *)(v34 + 40606) = 1;
          }
          v35 = idMat3::ToAngles(this: v82, result: (idAngles *)&this->lookAt);
          idPlayer::SetViewAngles(this: v14, angles: v35, force: false);
        }
      }
      idWeapon::StopLoopingFireSound(this: this->weapon);
      if ( this->turning != 0 )
      {
        this->turning = 0;
        idEntity::StopSound(this, channel: SND_CHANNEL_STEERING, peerMask: 0xFFu);
      }
      v36 = 0;
      if ( this->exitTargets.num > 0 )
      {
        v37 = 0;
        do
        {
          v38 = this->exitTargets.list[v37].spawnId.value;
          if ( gameLocal->spawnIds.ptr[v38 & 0x1FFF] == v38 >> 13 )
          {
            v39 = gameLocal->entities.ptr[v38 & 0x1FFF];
            if ( v39 != nullptr && idEntity::CastTo(c: v39) != nullptr )
            {
              v40 = this->exitTargets.list[v37].spawnId.value;
              if ( gameLocal->spawnIds.ptr[v40 & 0x1FFF] == v40 >> 13
                && (v41 = gameLocal->entities.ptr[v40 & 0x1FFF]) != nullptr )
              {
                v42 = idEntity::CastTo(c: v41);
              }
              else
              {
                v42 = nullptr;
              }
              idEntity::Activate(this: v42, activator: v14);
            }
          }
          ++v36;
          ++v37;
        }
        while ( v36 < this->exitTargets.num );
      }
    }
  }
  v43 = idActor::CastTo(c: _user);
  if ( v43 != nullptr )
    p_user->spawnId.value = (gameLocal->spawnIds.ptr[v43->entityNumber] << 13) | v43->entityNumber;
  else
    p_user->spawnId.value = 0x1FFF;
  if ( _user != nullptr || this->coolDownTime != 0 )
  {
    idProp_Usable::SetUsable(this, b: false);
    if ( (*((_BYTE *)this + 5748) & 0x40) != 0 )
    {
      if ( gameLocal->spawnIds.ptr[p_user->spawnId.value & 0x1FFF] == p_user->spawnId.value >> 13
        && (v45 = (idActor *)gameLocal->entities.ptr[p_user->spawnId.value & 0x1FFF]) != nullptr )
      {
        v46 = idActor::CastTo(c: v45);
      }
      else
      {
        v46 = nullptr;
      }
      idEntity::Bind(this: v46, master: (idWorldspawn *)this, orientated: true);
    }
    if ( gameLocal->spawnIds.ptr[p_user->spawnId.value & 0x1FFF] == p_user->spawnId.value >> 13
      && (v47 = (idActor *)gameLocal->entities.ptr[p_user->spawnId.value & 0x1FFF]) != nullptr )
    {
      v48 = (idPlayer *)idActor::CastTo(c: v47);
    }
    else
    {
      v48 = nullptr;
    }
    v49 = idPlayer::CastTo(c: v48);
    v50 = v49;
    if ( v49 != nullptr )
    {
      v57 = v49->presentable;
      if ( v57 != nullptr )
        v58 = (int)v57->GetPlayerInterface_2(this: v57);
      else
        v58 = 0;
      idPhysics_Player::SetCrouch(this: (idPhysics_Player *)(v58 + 36264), crouch: false);
      if ( v50->GetVehicle_2(this: v50) != nullptr )
      {
        v59 = v50->GetVehicle_2(this: v50);
        idVehicle::AllowAccelerate(this: v59, bl: false);
        v50->GetVehicle_2(this: v50)->allowWeaponChange = false;
        v60 = v50->GetVehicle_2(this: v50);
        idVehicle::AllowWeaponFiring(this: v60, bl: false);
      }
      else
      {
        v61 = v50->presentable;
        if ( v61 != nullptr )
          v62 = (int)v61->GetPlayerInterface_2(this: v61);
        else
          v62 = 0;
        if ( v62 != -37616 )
        {
          v63 = v50->presentable;
          if ( v63 != nullptr )
            v64 = (int)v63->GetPlayerInterface_2(this: v63);
          else
            v64 = 0;
          idHands::Hide(this: (idHands *)(v64 + 37616), hideReason: HAND_HIDE_GENERIC);
          v65 = v50->presentable;
          if ( v65 != nullptr )
            v66 = (int)v65->GetPlayerInterface_2(this: v65);
          else
            v66 = 0;
          *(_BYTE *)(v66 + 40605) = 1;
          v67 = (idPlayerHud *)idPlayer::GetPlayerHud(this: v50);
          idPlayerHud::SetHudState(this: v67, state: HUDSTATE_INFO);
        }
      }
      idPlayer::AddControl(this: v50, entity: this);
      v68 = v50->controlledCameraEntity.spawnId.value;
      if ( gameLocal->spawnIds.ptr[v68 & 0x1FFF] == v68 >> 13
        && (v69 = (idCamera *)gameLocal->entities.ptr[v68 & 0x1FFF]) != nullptr )
      {
        v70 = (idSpringCamera *)idCamera::CastTo(c: v69);
      }
      else
      {
        v70 = nullptr;
      }
      v71 = idSpringCamera::CastTo(c: v70);
      if ( v71 != nullptr )
      {
        manualUpdate = v71->manualUpdate;
        v71->getPlayerLookFromView = true;
        if ( !manualUpdate )
        {
          v71->manualUpdate = true;
          v71->resetManualUpdate = true;
        }
      }
      playerAmmoDecl = this->playerAmmoDecl;
    }
    else
    {
      v51 = 0;
      if ( this->targets.num > 0 )
      {
        v52 = 0;
        do
        {
          if ( v51 < this->targets.num
            && (v53 = this->targets.list[v52].spawnId.value, gameLocal->spawnIds.ptr[v53 & 0x1FFF] == v53 >> 13)
            && (v54 = gameLocal->entities.ptr[v53 & 0x1FFF]) != nullptr )
          {
            v55 = idEntity::CastTo(c: v54);
          }
          else
          {
            v55 = nullptr;
          }
          idEntity::Activate(this: v55, activator: this);
          ++v51;
          ++v52;
        }
        while ( v51 < this->targets.num );
      }
      playerAmmoDecl = this->aiAmmoDecl;
    }
    if ( playerAmmoDecl != nullptr )
      this->weapon->LoadAmmo(
        this: this->weapon,
        a2: nullptr,
        a3: playerAmmoDecl,
        a4: nullptr,
        a5: false,
        a6: true,
        a7: false,
        a8: false);
    if ( this->sound_use != nullptr )
      idProp_Usable::PlayUseSound(this);
    if ( v50 != nullptr )
    {
      idProp_WeaponStatic::MovePlayer(this, player: v50);
      if ( (*((_BYTE *)this + 5748) & 0x40) != 0 )
      {
        v73 = v50->presentable;
        if ( v73 != nullptr )
          v74 = (int)v73->GetPlayerInterface_2(this: v73);
        else
          v74 = 0;
        idPhysics_Player::SetMovementType(this: (idPhysics_Player *)(v74 + 36264), type: PM_VEHICLE_NOCLIP);
      }
    }
  }
  else
  {
    idProp_Usable::SetUsable(this, b: true);
  }
  if ( this->triggerTargets )
    this->ActivateTargets(this, a2: _user);
  if ( v80.logIndex >= 0 )
  {
    pLog = v80.pLog;
    v76 = &v80.pLog->logEntries.list[v80.logIndex];
    v77 = (unsigned __int64)Sys_GetClockTicks() >> 32;
    totalTicks = v76->totalTicks;
    HIDWORD(totalTicks) = v76->parent;
    LODWORD(v79) = v77 - totalTicks;
    v76->totalTicks = v79;
    pLog->lastEntry = HIDWORD(totalTicks);
  }
  RD_EventEnd();
  return 1;
}


// ========================================================================
// __unwind$495444
// EA  : 0x82D5247C
// RVA : 0x00D5247C
// PDB : w:\tech5\tungsten\game\entities\weaponstatic.cpp
// ========================================================================

void _unwind_495444()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 224 + 124));
}


// ========================================================================
// __unwind$495445
// EA  : 0x82D524A4
// RVA : 0x00D524A4
// PDB : w:\tech5\tungsten\game\entities\weaponstatic.cpp
// ========================================================================

void _unwind_495445()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 224 + 88));
}


// ========================================================================
// ?Draw@idProp_WeaponStatic@@UAA_NPAVidPlayer@@@Z
// EA  : 0x82D524D8
// RVA : 0x00D524D8
// PDB : w:\tech5\tungsten\game\entities\weaponstatic.cpp
// ========================================================================

int __fastcall idProp_WeaponStatic::Draw(idProp_WeaponStatic *this, idPlayer *player)
{
  unsigned __int64 v4; // r6
  const char *v5; // r7
  idPresentable *v6; // r3
  idPresentable *presentable; // r3
  int v8; // r4
  idPresentable *v9; // r3
  int v10; // r3
  idView *v11; // r29
  idPhysics *Physics; // r3
  float *v13; // r3
  double viewFov; // fp31
  idPresentable *v15; // r3
  idPresentablePlayer *v16; // r3
  idPresentable *v17; // r3
  idPresentablePlayer *v18; // r3
  idPresentable *v20; // r3
  int v22; // r11
  idSpringCamera *ControlCamera; // r3
  idSpringCamera *v24; // r3
  idPLogScope v26; // [sp+58h] [-68h] BYREF
  idVec3 v27; // [sp+60h] [-60h] BYREF
  int v28; // [sp+70h] [-50h] BYREF

  RD_EventBegin(name: "idProp_WeaponStatic::Draw");
  LODWORD(v4) = "idProp_WeaponStatic::Draw";
  HIDWORD(v4) = 2;
  idPLogScope::idPLogScope(this: &v26, pl: &pLog, gMask: v4, label: v5);
  if ( player != nullptr
    && (v6 = player->presentable) != nullptr
    && v6->GetPlayerInterface_2(this: v6) != nullptr
    && (unsigned __int8)idProp_WeaponStatic::GetViewOrg(this, pos: &v27, player) != 0 )
  {
    presentable = this->presentable;
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      presentable = this->presentable;
    }
    presentable->GetWeaponStaticInterface(this: presentable);
    v9 = player->presentable;
    if ( v9 != nullptr )
      v10 = (int)v9->GetPlayerInterface_2(this: v9);
    else
      v10 = 0;
    v11 = (idView *)(v10 + 16224);
    if ( this->shooting && this->windupTimer <= 0.0 )
    {
      idView::SetControllerShake(
        this: (idView *)(v10 + 16224),
        highMagnitude: 0.5,
        highDuration: v8,
        lowMagnitude: 1.0,
        lowDuration: 250);
      v11->cameraShake = 0.029999999;
    }
    else
    {
      *(float *)(v10 + 19128) = 0.0;
    }
    idView::SetViewPos(this: v11, origin: &v27, axis: &this->prevLookAt);
    Physics = idEntity::GetPhysics(this);
    v13 = (float *)Physics->GetLinearVelocity(this: (idPhysics *)&v28, result: (idVec3 *)Physics, a3: 0);
    v11->viewVelocity.x = *v13;
    v11->viewVelocity.y = v13[1];
    v11->viewVelocity.z = v13[2];
    viewFov = this->viewFov;
    if ( viewFov < 0.0 )
    {
      v15 = player->presentable;
      if ( v15 != nullptr )
        v16 = v15->GetPlayerInterface_2(this: v15);
      else
        v16 = nullptr;
      viewFov = idPresentablePlayer::DefaultFov(this: v16);
    }
    v17 = player->presentable;
    if ( v17 != nullptr )
      v18 = v17->GetPlayerInterface_2(this: v17);
    else
      v18 = nullptr;
    _FP0 = (float)(idPresentablePlayer::CalcFov(this: v18, honorZoom: true) - (float)viewFov);
    v20 = player->presentable;
    __asm { fsel      f31, f0, f31, f1 }
    if ( v20 != nullptr )
      v22 = (int)v20->GetPlayerInterface_2(this: v20);
    else
      v22 = 0;
    *(float *)(v22 + 46644) = _FP31;
    idView::CalcFOV(this: v11, base_fov: _FP31);
    idView::Render(this: v11);
    ControlCamera = (idSpringCamera *)idPlayer::GetControlCamera(this: player);
    v24 = idSpringCamera::CastTo(c: ControlCamera);
    if ( v24 != nullptr )
      idSpringCamera::Update(this: v24);
    idPLogScope::~idPLogScope(this: &v26);
    RD_EventEnd();
    return 1;
  }
  else
  {
    idPLogScope::~idPLogScope(this: &v26);
    RD_EventEnd();
    return 0;
  }
}


// ========================================================================
// __unwind$496302
// EA  : 0x82D52770
// RVA : 0x00D52770
// PDB : w:\tech5\tungsten\game\entities\weaponstatic.cpp
// ========================================================================

void _unwind_496302()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 192 + 124));
}


// ========================================================================
// __unwind$496303
// EA  : 0x82D52798
// RVA : 0x00D52798
// PDB : w:\tech5\tungsten\game\entities\weaponstatic.cpp
// ========================================================================

void _unwind_496303()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 192 + 88));
}


// ========================================================================
// ?UpdateArmourPieces@idProp_WeaponStatic@@AAAXXZ
// EA  : 0x82D527C8
// RVA : 0x00D527C8
// PDB : w:\tech5\tungsten\game\entities\weaponstatic.cpp
// ========================================================================

void __fastcall idProp_WeaponStatic::UpdateArmourPieces(idProp_WeaponStatic *this)
{
  idTreeAnimator *TreeAnimatorFromPresentable; // r23
  unsigned __int64 v3; // r6
  const char *v4; // r7
  idPresentable *presentable; // r3
  int v6; // r24
  int v7; // r26
  idWeaponStatic_Armour *v8; // r29
  idPresentable *v9; // r11
  int *v10; // r10
  float *p_y; // r11
  int v12; // ctr
  idPresentable *v13; // r11
  idPhysics *physicsObj; // r11
  idPresentable *v15; // r11
  idPLog *pLog; // r29
  idPLog::logEntry_t *v17; // r30
  int v18; // r3
  __int64 totalTicks; // r11
  __int64 v20; // r9
  idPLogScope v21; // [sp+58h] [-98h] BYREF
  idVec3 v22; // [sp+60h] [-90h] BYREF
  int v23; // [sp+6Ch] [-84h] BYREF
  idMat3 v24[3]; // [sp+70h] [-80h] BYREF

  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
  if ( TreeAnimatorFromPresentable != nullptr )
  {
    RD_EventBegin(name: "idProp_WeaponStatic::UpdateArmourPieces");
    LODWORD(v3) = "idProp_WeaponStatic::UpdateArmourPieces";
    HIDWORD(v3) = 2;
    idPLogScope::idPLogScope(this: &v21, pl: &::pLog, gMask: v3, label: v4);
    presentable = this->presentable;
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      presentable = this->presentable;
    }
    idPresentable::UpdateModelTransform(this: presentable);
    v6 = 0;
    if ( this->armourPieces.num > 0 )
    {
      v7 = 0;
      do
      {
        v8 = &this->armourPieces.list[v7];
        v9 = v8->presentable;
        if ( v9 == nullptr || !v9->hidden )
        {
          v10 = &v23;
          p_y = &mat2_identity.mat[1].y;
          v12 = 9;
          v22 = vec3_origin;
          do
          {
            *++v10 = *(_DWORD *)++p_y;
            --v12;
          }
          while ( v12 != 0 );
          if ( (unsigned __int16)v8->jointIndex.value >= 0x8000u
            || (unsigned __int8)idTreeAnimator::GetWorldSpaceAttachmentTransform(
                                  this: TreeAnimatorFromPresentable,
                                  jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)v8->jointIndex.value,
                                  translationOffset: &vec3_origin,
                                  rotationOffset: (idMat3 *)&quat_identity,
                                  origin: &v22,
                                  axis: v24) == 0 )
          {
            v13 = this->presentable;
            if ( v13 == nullptr )
            {
              idEntity::InitPresentableInternal(this);
              v13 = this->presentable;
            }
            v22.x = v13->origin.x;
            v22.y = v13->origin.y;
            v22.z = v13->origin.z;
            if ( v13 == nullptr )
            {
              idEntity::InitPresentableInternal(this);
              v13 = this->presentable;
            }
            v24[0] = v13->axis;
          }
          physicsObj = v8->physicsObj;
          if ( physicsObj != nullptr )
          {
            ((void (*)(void))physicsObj->SetAxis)();
            v8->physicsObj->SetOrigin(this: v8->physicsObj, a2: &v22, a3: -1);
          }
          v15 = v8->presentable;
          if ( v15 != nullptr )
          {
            v15->axis = v24[0];
            v8->presentable->origin = v22;
            v8->presentable->Present(this: v8->presentable);
          }
        }
        ++v6;
        ++v7;
      }
      while ( v6 < this->armourPieces.num );
    }
    if ( v21.logIndex >= 0 )
    {
      pLog = v21.pLog;
      v17 = &v21.pLog->logEntries.list[v21.logIndex];
      v18 = (unsigned __int64)Sys_GetClockTicks() >> 32;
      totalTicks = v17->totalTicks;
      HIDWORD(totalTicks) = v17->parent;
      LODWORD(v20) = v18 - totalTicks;
      v17->totalTicks = v20;
      pLog->lastEntry = HIDWORD(totalTicks);
    }
    RD_EventEnd();
  }
}


// ========================================================================
// __unwind$496499
// EA  : 0x82D52AD0
// RVA : 0x00D52AD0
// PDB : w:\tech5\tungsten\game\entities\weaponstatic.cpp
// ========================================================================

void _unwind_496499()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 240 + 148));
}


// ========================================================================
// __unwind$496500
// EA  : 0x82D52AF8
// RVA : 0x00D52AF8
// PDB : w:\tech5\tungsten\game\entities\weaponstatic.cpp
// ========================================================================

void _unwind_496500()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 240 + 88));
}


// ========================================================================
// ?HandleHeat@idProp_WeaponStatic@@AAAX_N@Z
// EA  : 0x82D52B28
// RVA : 0x00D52B28
// PDB : w:\tech5\tungsten\game\entities\weaponstatic.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idProp_WeaponStatic::HandleHeat(idProp_WeaponStatic *this, bool isPlayer)
{
  unsigned __int64 v4; // r6
  const char *v5; // r7
  __int64 v6; // r9 OVERLAPPED
  char v7; // r19
  double v8; // fp30
  idPresentable *presentable; // r3
  double v11; // fp29
  double v12; // fp28
  int v13; // r3
  int v14; // r18
  int GameMs; // r27
  int PreviousGameMs; // r3
  __int128 v17; // r8
  int v18; // r3
  int v19; // r27
  int v20; // r3
  __int128 v21; // r9
  idPresentable *v22; // r3
  idRenderModel *model; // r11
  unsigned __int8 v24; // r11
  bool v25; // zf
  __int64 v26; // r10
  double v27; // fp0
  int v28; // r20
  int v29; // r21
  int v30; // r2 OVERLAPPED
  double v31; // fp13
  __int64 v32; // r9
  unsigned int v33; // r6
  int v34; // r3
  __int64 v35; // r5
  unsigned int v36; // r9
  double v37; // fp27
  int GameMsPerFrame; // r17
  int v39; // r16
  const idDeclParticle *overheatParticle; // r15
  idRenderModelEffects *MergeBranch; // r3
  const idVec3 *v42; // r7
  idPLog *pLog; // r29
  idPLog::logEntry_t *v44; // r30
  int v45; // r3
  __int64 totalTicks; // r11
  __int64 v47; // r9
  int v48; // [sp+8h] [-178h]
  int v49; // [sp+Ch] [-174h]
  int v50; // [sp+10h] [-170h]
  int v51; // [sp+14h] [-16Ch]
  int v52; // [sp+18h] [-168h]
  int v53; // [sp+1Ch] [-164h]
  int v54; // [sp+20h] [-160h]
  int v55; // [sp+24h] [-15Ch]
  int v56; // [sp+28h] [-158h]
  int v57; // [sp+2Ch] [-154h]
  int v58; // [sp+30h] [-150h]
  int v59; // [sp+34h] [-14Ch]
  int v60; // [sp+38h] [-148h]
  int v61; // [sp+3Ch] [-144h]
  int v62; // [sp+40h] [-140h]
  int v63; // [sp+44h] [-13Ch]
  int v64; // [sp+48h] [-138h]
  int v65; // [sp+4Ch] [-134h]
  int v66; // [sp+50h] [-130h]
  __int64 v67; // [sp+60h] [-120h] BYREF
  idPLogScope v68[4]; // [sp+68h] [-118h] BYREF
  idMat3 v69[2]; // [sp+88h] [-F8h] BYREF

  RD_EventBegin(name: "idProp_WeaponStatic::Think - AI");
  LODWORD(v4) = "idProp_WeaponStatic::Think - AI";
  HIDWORD(v4) = 2;
  idPLogScope::idPLogScope(this: v68, pl: &::pLog, gMask: v4, label: v5);
  if ( this->heatPerSecFiring == 0
    || !this->blockCoolDown && (g_infiniteAmmo.valueInteger != 0 || g_permaInfiniteAmmo.valueInteger != 0) )
  {
    idPLogScope::~idPLogScope(this: v68);
  }
  else
  {
    v7 = 0;
    v8 = 0.0;
    _FP31 = 0.0;
    if ( isPlayer )
    {
      LODWORD(v6) = this->maxHeat;
      HIDWORD(v6) = this->coolHeat;
    }
    else
    {
      LODWORD(v6) = this->aiMaxHeat;
      HIDWORD(v6) = this->aiCoolHeat;
    }
    v67 = *(__int64 *)((char *)&v6 + 4);
    presentable = this->presentable;
    v11 = (float)v6;
    v12 = (float)*(__int64 *)((char *)&v6 + 4);
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      presentable = this->presentable;
    }
    v13 = (int)presentable->GetWeaponStaticInterface(this: presentable);
    v14 = v13;
    if ( v13 != 0 )
    {
      _FP31 = *(float *)(v13 + 1296);
      v7 = *(_BYTE *)(v13 + 1320);
    }
    if ( this->blockCoolDown )
    {
      _FP31 = v11;
    }
    else if ( this->shooting && this->windupTimer <= 0.0 )
    {
      GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      PreviousGameMs = idGameTimeManager::GetPreviousGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      LODWORD(v17) = this->heatPerSecFiring;
      DWORD2(v17) = GameMs - PreviousGameMs;
      v67 = *(_QWORD *)((char *)&v17 + 4);
      _FP31 = (float)((float)((float)(__int64)v17 * (float)((float)*(__int64 *)((char *)&v17 + 4) * (float)0.001))
                    + (float)_FP31);
      v18 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      LODWORD(v67) = (int)(float)(this->coolDownDelay * (float)1000.0);
      this->blockCoolDownUntil = v67 + v18;
    }
    else if ( idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) > this->blockCoolDownUntil )
    {
      v19 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      v20 = idGameTimeManager::GetPreviousGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      LODWORD(v21) = this->heatCooledPerSec;
      DWORD2(v21) = v19 - v20;
      v67 = *(_QWORD *)((char *)&v21 + 4);
      _FP31 = (float)-(float)((float)((float)(__int64)v21 * (float)((float)*(__int64 *)((char *)&v21 + 4) * (float)0.001))
                            - (float)_FP31);
    }
    if ( _FP31 >= v12 )
    {
      if ( _FP31 >= v11 && v7 == 0 )
      {
        _FP31 = v11;
        v7 = 1;
        idEntity::StartSoundShader(
          this,
          channel: SND_CHANNEL_WEAPON_AMBIENT,
          shader: this->sndOverheat,
          soundShaderFlags: (soundShaderFlags_t)0,
          peerMask: 0xFFu);
      }
    }
    else
    {
      if ( v7 != 0 )
        idEntity::StopSound(this, channel: SND_CHANNEL_WEAPON_AMBIENT, peerMask: 0xFFu);
      __asm { fsel      f31, f31, f31, f30 }
      v7 = 0;
    }
    v22 = this->presentable;
    if ( v22 == nullptr || (model = v22->model, HIDWORD(v67) = this->presentable, v25 = model != nullptr, v24 = 1, !v25) )
      v24 = 0;
    HIDWORD(v26) = v24;
    if ( v24 != 0 )
    {
      LODWORD(v26) = this->maxHeat;
      v67 = v26;
      v27 = (float)((float)_FP31 / (float)v26);
      if ( v27 >= 0.0 )
      {
        if ( v27 <= 1.0 )
          v8 = (float)((float)_FP31 / (float)v26);
        else
          v8 = 1.0;
      }
      if ( v22 == nullptr )
      {
        idEntity::InitPresentableInternal(this);
        v22 = this->presentable;
      }
      idPresentable::SetParm(this: v22, parm: rp->Color, scalar: v8);
    }
    v28 = 0;
    if ( this->barrels.num > 0 )
    {
      v29 = 0;
      do
      {
        if ( (unsigned __int8)idAnimatedEntity::GetTagPosition(
                                this,
                                propIndex: this->infopropIndex,
                                tagIndex: this->barrels.list[v29].muzzleTagIndex,
                                origin: v69[0].mat,
                                axis: (idMat3 *)&v69[0].mat[2]) != 0
          && this->overheatParticle != nullptr
          && idAnimatedEntity::GetTreeAnimatorFromPresentable(this) != nullptr )
        {
          v31 = v7 != 0 ? 5.0 : 2.0;
          LODWORD(v32) = this->maxHeat;
          HIDWORD(v32) = clientGame->random.seed;
          v33 = 1664525 * clientGame->random.seed + 1013904223;
          v68[1] = (idPLogScope)v32;
          clientGame->random.seed = v33;
          v34 = (v33 >> 10) & 0x7FFF;
          v68[2] = *(idPLogScope *)(&v30 - 1);
          if ( (float)((float)*(__int64 *)(&v30 - 1) * (float)0.000030518509) < (double)(float)((float)((float)((float)_FP31 / (float)v32) * (float)v31)
                                                                                              - (float)1.0) )
          {
            HIDWORD(v35) = 1;
            HIDWORD(v67) = -1;
            v36 = 1664525 * clientGame->random.seed;
            clientGame->random.seed = v36 + 1013904223;
            LODWORD(v35) = ((v36 + 1013904223) >> 10) & 0x7FFF;
            v68[3] = (idPLogScope)v35;
            v37 = (float)((float)v35 * (float)0.000030518509);
            GameMsPerFrame = idGameTimeManager::GetGameMsPerFrame(
                               this: &clientGame->gameTimeManager,
                               type: GAMETIME_SCALED);
            v39 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
            overheatParticle = this->overheatParticle;
            MergeBranch = (idRenderModelEffects *)idAnimator_BlendEq::InternalGetMergeBranch(this: (idAnimator_BlendEq *)clientGame);
            idRenderModelEffects::AddParticles(
              this: MergeBranch,
              particle: overheatParticle,
              systemStartTime: v39,
              gameMsPerFrame: GameMsPerFrame,
              diversity: v37,
              origin: v42,
              axis: v69,
              velocity: mat3_identity.mat,
              color: &vec3_origin.x,
              a10: v48,
              a11: v49,
              a12: v50,
              a13: v51,
              a14: v52,
              a15: v53,
              a16: v54,
              a17: v55,
              a18: v56,
              a19: v57,
              a20: v58,
              a21: v59,
              a22: v60,
              a23: v61,
              a24: v62,
              a25: v63,
              a26: v64,
              a27: v65,
              a28: v66,
              a29: (unsigned int *)&v67);
          }
        }
        ++v28;
        ++v29;
      }
      while ( v28 < this->barrels.num );
    }
    if ( v14 != 0 )
    {
      *(float *)(v14 + 1296) = _FP31;
      *(_BYTE *)(v14 + 1320) = v7;
    }
    if ( v68[0].logIndex >= 0 )
    {
      pLog = v68[0].pLog;
      v44 = &v68[0].pLog->logEntries.list[v68[0].logIndex];
      v45 = (unsigned __int64)Sys_GetClockTicks() >> 32;
      totalTicks = v44->totalTicks;
      HIDWORD(totalTicks) = v44->parent;
      LODWORD(v47) = v45 - totalTicks;
      v44->totalTicks = v47;
      pLog->lastEntry = HIDWORD(totalTicks);
    }
  }
  RD_EventEnd();
}


// ========================================================================
// __unwind$496696_0
// EA  : 0x82D530C0
// RVA : 0x00D530C0
// PDB : w:\tech5\tungsten\game\entities\weaponstatic.cpp
// ========================================================================

void _unwind_496696_0()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 384 + 196));
}


// ========================================================================
// __unwind$496697_0
// EA  : 0x82D530E8
// RVA : 0x00D530E8
// PDB : w:\tech5\tungsten\game\entities\weaponstatic.cpp
// ========================================================================

void _unwind_496697_0()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 384 + 104));
}


// ========================================================================
// ?CheckAttachments@idProp_WeaponStatic@@AAAXXZ
// EA  : 0x82D53118
// RVA : 0x00D53118
// PDB : w:\tech5\tungsten\game\entities\weaponstatic.cpp
// ========================================================================

void __fastcall idProp_WeaponStatic::CheckAttachments(idProp_WeaponStatic *this)
{
  unsigned __int64 v2; // r6
  const char *v3; // r7
  int i; // r26
  int value; // r9
  idEntity *v6; // r3
  idEntity *v7; // r30
  idPhysics *Physics; // r3
  int entityNumber; // r20
  idPhysics *v10; // r20
  idPhysics *v11; // r19
  float *v12; // r20
  float *v13; // r3
  double v14; // fp9
  double v15; // fp5
  double v18; // fp11
  double v19; // fp1
  double v20; // fp13
  double v21; // fp26
  double v22; // fp25
  double v23; // fp24
  idPhysics *v24; // r20
  idPhysics *v25; // r19
  unsigned int v26; // r9
  idPhysics_vtbl *v27; // r11
  __int64 v28; // r6
  double v29; // fp23
  double v30; // fp22
  double v31; // fp21
  float *v32; // r3
  double v33; // fp4
  double v34; // fp2
  idPhysics *v35; // r20
  idPhysics *v36; // r30
  unsigned int v37; // r6
  __int64 v38; // r9
  double v39; // fp24
  double v40; // fp25
  double v41; // fp26
  float *v42; // r3
  double v43; // fp4
  double v44; // fp3
  idPLog *pLog; // r29
  idPLog::logEntry_t *v46; // r30
  int v47; // r3
  __int64 totalTicks; // r11
  __int64 v49; // r9
  idPLogScope v50[3]; // [sp+58h] [-128h] BYREF
  float v51[4]; // [sp+70h] [-110h] BYREF
  float v52[4]; // [sp+80h] [-100h] BYREF
  int v53; // [sp+90h] [-F0h] BYREF
  int v54; // [sp+A0h] [-E0h] BYREF

  RD_EventBegin(name: "idProp_WeaponStatic::CheckAttachments");
  LODWORD(v2) = "idProp_WeaponStatic::CheckAttachments";
  HIDWORD(v2) = 2;
  idPLogScope::idPLogScope(this: v50, pl: &::pLog, gMask: v2, label: v3);
  for ( i = 0; i < this->attachments.attachments.num; ++i )
  {
    value = idAttachmentCollection::ForIndex(this: &this->attachments, index: i)->entity.spawnId.value;
    if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
      && (v6 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
    {
      v7 = idEntity::CastTo(c: v6);
    }
    else
    {
      v7 = nullptr;
    }
    if ( !this->enabled || v7->IsDead(this: v7) )
    {
      Physics = idEntity::GetPhysics(this: v7);
      entityNumber = this->entityNumber;
      Physics->GetClipModel(this: Physics, a2: 0)->ownerNumber = entityNumber;
      idAttachmentCollection::RemoveAttachment(this: &this->attachments, ent: v7);
      v10 = idEntity::GetPhysics(this);
      v11 = idEntity::GetPhysics(this: v7);
      v12 = (float *)v10->GetOrigin(this: v10, a2: 0);
      v13 = (float *)v11->GetOrigin(this: v11, a2: 0);
      v14 = (float)(v13[1] - v12[1]);
      v15 = (float)(v13[2] - v12[2]);
      _FP1 = (float)((float)((float)((float)v15 * (float)v15)
                           + (float)((float)((float)(*v13 - *v12) * (float)(*v13 - *v12))
                                   + (float)((float)v14 * (float)v14)))
                   - idMath::FLT_SMALLEST_NON_DENORMAL);
      __asm { fsel      f12, f1, f2, f0 }
      v18 = __frsqrte(_FP12);
      v19 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v18
                                                                                          * (float)((float)((float)((float)v15 * (float)v15) + (float)((float)((float)(*v13 - *v12) * (float)(*v13 - *v12)) + (float)((float)v14 * (float)v14)))
                                                                                                  * (float)0.5))
                                                                                  * (float)v18)
                                                                          - (float)1.5)
                                                          * (float)v18)
                                                  * (float)((float)((float)((float)v15 * (float)v15)
                                                                  + (float)((float)((float)(*v13 - *v12)
                                                                                  * (float)(*v13 - *v12))
                                                                          + (float)((float)v14 * (float)v14)))
                                                          * (float)0.5))
                                          * (float)((float)-(float)((float)((float)((float)v18
                                                                                  * (float)((float)((float)((float)v15 * (float)v15)
                                                                                                  + (float)((float)((float)(*v13 - *v12) * (float)(*v13 - *v12)) + (float)((float)v14 * (float)v14)))
                                                                                          * (float)0.5))
                                                                          * (float)v18)
                                                                  - (float)1.5)
                                                  * (float)v18))
                                  - (float)1.5)
                  * (float)((float)-(float)((float)((float)((float)v18
                                                          * (float)((float)((float)((float)v15 * (float)v15)
                                                                          + (float)((float)((float)(*v13 - *v12)
                                                                                          * (float)(*v13 - *v12))
                                                                                  + (float)((float)v14 * (float)v14)))
                                                                  * (float)0.5))
                                                  * (float)v18)
                                          - (float)1.5)
                          * (float)v18));
      v20 = (float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v18 * (float)((float)((float)((float)v15 * (float)v15) + (float)((float)((float)(*v13 - *v12) * (float)(*v13 - *v12)) + (float)((float)v14 * (float)v14))) * (float)0.5)) * (float)v18) - (float)1.5)
                                                                                          * (float)v18)
                                                                                  * (float)((float)((float)((float)v15 * (float)v15)
                                                                                                  + (float)((float)((float)(*v13 - *v12) * (float)(*v13 - *v12)) + (float)((float)v14 * (float)v14)))
                                                                                          * (float)0.5))
                                                                          * (float)((float)-(float)((float)((float)((float)v18 * (float)((float)((float)((float)v15 * (float)v15) + (float)((float)((float)(*v13 - *v12) * (float)(*v13 - *v12)) + (float)((float)v14 * (float)v14))) * (float)0.5)) * (float)v18)
                                                                                                  - (float)1.5)
                                                                                  * (float)v18))
                                                                  - (float)1.5)
                                                  * (float)((float)-(float)((float)((float)((float)v18
                                                                                          * (float)((float)((float)((float)v15 * (float)v15) + (float)((float)((float)(*v13 - *v12) * (float)(*v13 - *v12)) + (float)((float)v14 * (float)v14)))
                                                                                                  * (float)0.5))
                                                                                  * (float)v18)
                                                                          - (float)1.5)
                                                          * (float)v18))
                                          * (float)((float)((float)((float)v15 * (float)v15)
                                                          + (float)((float)((float)(*v13 - *v12) * (float)(*v13 - *v12))
                                                                  + (float)((float)v14 * (float)v14)))
                                                  * (float)0.5))
                                  * (float)v19)
                          - (float)1.5);
      v21 = (float)((float)((float)v20
                          * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v18 * (float)((float)((float)((float)v15 * (float)v15) + (float)((float)((float)(*v13 - *v12) * (float)(*v13 - *v12)) + (float)((float)v14 * (float)v14))) * (float)0.5))
                                                                                                  * (float)v18)
                                                                                          - (float)1.5)
                                                                          * (float)v18)
                                                                  * (float)((float)((float)((float)v15 * (float)v15)
                                                                                  + (float)((float)((float)(*v13 - *v12)
                                                                                                  * (float)(*v13 - *v12))
                                                                                          + (float)((float)v14
                                                                                                  * (float)v14)))
                                                                          * (float)0.5))
                                                          * (float)((float)-(float)((float)((float)((float)v18
                                                                                                  * (float)((float)((float)((float)v15 * (float)v15) + (float)((float)((float)(*v13 - *v12) * (float)(*v13 - *v12)) + (float)((float)v14 * (float)v14))) * (float)0.5))
                                                                                          * (float)v18)
                                                                                  - (float)1.5)
                                                                  * (float)v18))
                                                  - (float)1.5)
                                  * (float)((float)-(float)((float)((float)((float)v18
                                                                          * (float)((float)((float)((float)v15
                                                                                                  * (float)v15)
                                                                                          + (float)((float)((float)(*v13 - *v12) * (float)(*v13 - *v12))
                                                                                                  + (float)((float)v14 * (float)v14)))
                                                                                  * (float)0.5))
                                                                  * (float)v18)
                                                          - (float)1.5)
                                          * (float)v18)))
                  * (float)(*v13 - *v12));
      v22 = (float)((float)((float)v20
                          * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v18 * (float)((float)((float)((float)v15 * (float)v15) + (float)((float)((float)(*v13 - *v12) * (float)(*v13 - *v12)) + (float)((float)v14 * (float)v14))) * (float)0.5))
                                                                                                  * (float)v18)
                                                                                          - (float)1.5)
                                                                          * (float)v18)
                                                                  * (float)((float)((float)((float)v15 * (float)v15)
                                                                                  + (float)((float)((float)(*v13 - *v12)
                                                                                                  * (float)(*v13 - *v12))
                                                                                          + (float)((float)v14
                                                                                                  * (float)v14)))
                                                                          * (float)0.5))
                                                          * (float)((float)-(float)((float)((float)((float)v18
                                                                                                  * (float)((float)((float)((float)v15 * (float)v15) + (float)((float)((float)(*v13 - *v12) * (float)(*v13 - *v12)) + (float)((float)v14 * (float)v14))) * (float)0.5))
                                                                                          * (float)v18)
                                                                                  - (float)1.5)
                                                                  * (float)v18))
                                                  - (float)1.5)
                                  * (float)((float)-(float)((float)((float)((float)v18
                                                                          * (float)((float)((float)((float)v15
                                                                                                  * (float)v15)
                                                                                          + (float)((float)((float)(*v13 - *v12) * (float)(*v13 - *v12))
                                                                                                  + (float)((float)v14 * (float)v14)))
                                                                                  * (float)0.5))
                                                                  * (float)v18)
                                                          - (float)1.5)
                                          * (float)v18)))
                  * (float)v14);
      v23 = (float)((float)((float)v20
                          * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v18 * (float)((float)((float)((float)v15 * (float)v15) + (float)((float)((float)(*v13 - *v12) * (float)(*v13 - *v12)) + (float)((float)v14 * (float)v14))) * (float)0.5))
                                                                                                  * (float)v18)
                                                                                          - (float)1.5)
                                                                          * (float)v18)
                                                                  * (float)((float)((float)((float)v15 * (float)v15)
                                                                                  + (float)((float)((float)(*v13 - *v12)
                                                                                                  * (float)(*v13 - *v12))
                                                                                          + (float)((float)v14
                                                                                                  * (float)v14)))
                                                                          * (float)0.5))
                                                          * (float)((float)-(float)((float)((float)((float)v18
                                                                                                  * (float)((float)((float)((float)v15 * (float)v15) + (float)((float)((float)(*v13 - *v12) * (float)(*v13 - *v12)) + (float)((float)v14 * (float)v14))) * (float)0.5))
                                                                                          * (float)v18)
                                                                                  - (float)1.5)
                                                                  * (float)v18))
                                                  - (float)1.5)
                                  * (float)((float)-(float)((float)((float)((float)v18
                                                                          * (float)((float)((float)((float)v15
                                                                                                  * (float)v15)
                                                                                          + (float)((float)((float)(*v13 - *v12) * (float)(*v13 - *v12))
                                                                                                  + (float)((float)v14 * (float)v14)))
                                                                                  * (float)0.5))
                                                                  * (float)v18)
                                                          - (float)1.5)
                                          * (float)v18)))
                  * (float)v15);
      v24 = idEntity::GetPhysics(this);
      v25 = idEntity::GetPhysics(this: v7);
      v26 = 1664525 * clientGame->random.seed + 1013904223;
      clientGame->random.seed = v26;
      v27 = v24->__vftable;
      LODWORD(v28) = (v26 >> 10) & 0x7FFF;
      v50[1] = (idPLogScope)v28;
      v29 = (float)((float)v23
                  * (float)((float)((float)((float)v28 * (float)0.000030518509) * (float)200.0) + (float)100.0));
      v30 = (float)((float)v22
                  * (float)((float)((float)((float)v28 * (float)0.000030518509) * (float)200.0) + (float)100.0));
      v31 = (float)((float)((float)((float)((float)v28 * (float)0.000030518509) * (float)200.0) + (float)100.0)
                  * (float)v21);
      v32 = (float *)v27->GetLinearVelocity(this: (idPhysics *)&v53, result: (idVec3 *)v24, a3: 0);
      v33 = (float)(v32[2] + (float)v29);
      v34 = (float)(v32[1] + (float)v30);
      v51[0] = *v32 + (float)v31;
      v51[2] = v33;
      v51[1] = v34;
      v25->SetLinearVelocity(this: v25, a2: (const idVec3 *)v51, a3: 0);
      v35 = idEntity::GetPhysics(this);
      v36 = idEntity::GetPhysics(this: v7);
      v37 = 1664525 * clientGame->random.seed;
      clientGame->random.seed = v37 + 1013904223;
      HIDWORD(v38) = v35->__vftable;
      LODWORD(v38) = ((v37 + 1013904223) >> 10) & 0x7FFF;
      v50[2] = (idPLogScope)v38;
      v39 = (float)((float)v23
                  * (float)((float)((float)((float)v38 * (float)0.000030518509) * (float)100.0) + (float)50.0));
      v40 = (float)((float)v22
                  * (float)((float)((float)((float)v38 * (float)0.000030518509) * (float)100.0) + (float)50.0));
      v41 = (float)((float)((float)((float)((float)v38 * (float)0.000030518509) * (float)100.0) + (float)50.0)
                  * (float)v21);
      v42 = (float *)(*(int (__fastcall **)(int *, idPhysics *, _DWORD))(HIDWORD(v38) + 92))(a1: &v54, a2: v35, a3: 0);
      v43 = (float)(v42[2] + (float)v39);
      v44 = (float)(v42[1] + (float)v40);
      v52[0] = *v42 + (float)v41;
      v52[2] = v43;
      v52[1] = v44;
      v36->SetAngularVelocity(this: v36, a2: (const idVec3 *)v52, a3: 0);
      --i;
    }
  }
  if ( v50[0].logIndex >= 0 )
  {
    pLog = v50[0].pLog;
    v46 = &v50[0].pLog->logEntries.list[v50[0].logIndex];
    v47 = (unsigned __int64)Sys_GetClockTicks() >> 32;
    totalTicks = v46->totalTicks;
    HIDWORD(totalTicks) = v46->parent;
    LODWORD(v49) = v47 - totalTicks;
    v46->totalTicks = v49;
    pLog->lastEntry = HIDWORD(totalTicks);
  }
  RD_EventEnd();
}


// ========================================================================
// __unwind$496921
// EA  : 0x82D53508
// RVA : 0x00D53508
// PDB : w:\tech5\tungsten\game\entities\weaponstatic.cpp
// ========================================================================

void _unwind_496921()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 384 + 172));
}


// ========================================================================
// __unwind$496922
// EA  : 0x82D53530
// RVA : 0x00D53530
// PDB : w:\tech5\tungsten\game\entities\weaponstatic.cpp
// ========================================================================

void _unwind_496922()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 384 + 88));
}


// ========================================================================
// ?Shoot@idProp_WeaponStatic@@UAAX_N0@Z
// EA  : 0x82D53560
// RVA : 0x00D53560
// PDB : w:\tech5\tungsten\game\entities\weaponstatic.cpp
// ========================================================================

void __fastcall idProp_WeaponStatic::Shoot(idProp_WeaponStatic *this, bool primary, bool secondary)
{
  unsigned __int64 v6; // r6
  const char *v7; // r7
  int value; // r9
  idActor *v9; // r3
  idAI2 *v10; // r3
  idAI2 *v11; // r19
  idFinishFireResults *v12; // r11
  int i; // ctr
  int v14; // r9
  idActor *v15; // r3
  idPlayer *v16; // r3
  idPlayer *v17; // r22
  const idDeclProjectile *CurrentProjectileDecl; // r3
  idPresentable *presentable; // r11
  const idDeclProjectile *v20; // r21
  idPresentable *v21; // r24
  idWeapon *weapon; // r10
  idPresentable *v23; // r3
  idWeapon::weaponState_t weaponState; // r29
  idPresentablePlayer *v25; // r3
  idPresentable *v26; // r11
  idFXManager *p_fxManager; // r25
  bool v28; // r23
  int v29; // r26
  int v30; // r28
  barrelProps_t *v31; // r29
  int v32; // r5
  int v33; // r5
  barrelProps_t *v34; // r29
  char v35; // r11
  int muzzleTagIndex; // r5
  int ejectTagIndex; // r5
  signed int num; // r10
  int v39; // r9
  idPresentable *v40; // r3
  idPresentablePlayer *v41; // r3
  idPLog *pLog; // r29
  idPLog::logEntry_t *v43; // r30
  int v44; // r3
  __int64 totalTicks; // r11
  __int64 v46; // r9
  idFXManager *v47; // [sp+8h] [-B58h]
  bool v48; // [sp+Fh] [-B51h]
  idVec3 v49; // [sp+60h] [-B00h] BYREF
  idPLogScope v50; // [sp+70h] [-AF0h] BYREF
  idVec3 v51[2]; // [sp+78h] [-AE8h] BYREF
  idMat3 v52; // [sp+90h] [-AD0h] BYREF
  idFireParms v53; // [sp+C0h] [-AA0h] BYREF
  idFinishFireResults v54; // [sp+160h] [-A00h] BYREF
  idMat3 v55; // [sp+1B0h] [-9B0h] BYREF
  idTestFireResults v56; // [sp+1E0h] [-980h] BYREF

  RD_EventBegin(name: "idProp_WeaponStatic::Shoot");
  LODWORD(v6) = "idProp_WeaponStatic::Shoot";
  HIDWORD(v6) = 2;
  idPLogScope::idPLogScope(this: &v50, pl: &::pLog, gMask: v6, label: v7);
  value = this->user.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
  {
    v9 = (idActor *)gameLocal->entities.ptr[value & 0x1FFF];
    if ( v9 != nullptr )
      v10 = (idAI2 *)idActor::CastTo(c: v9);
    else
      v10 = nullptr;
  }
  else
  {
    v10 = nullptr;
  }
  v11 = idAI2::CastTo(c: v10);
  if ( !idWeapon::IsReadyToFire(this: this->weapon) )
    goto LABEL_67;
  idFireParms::idFireParms(this: &v53);
  memset(&v56, 0, sizeof(v56));
  v12 = &v54;
  v54.numProjectiles = 0;
  for ( i = 16; i != 0; --i )
  {
    v12 = (idFinishFireResults *)((char *)v12 + 4);
    v12->numProjectiles = 0;
  }
  v14 = this->user.spawnId.value;
  if ( gameLocal->spawnIds.ptr[v14 & 0x1FFF] == v14 >> 13
    && (v15 = (idActor *)gameLocal->entities.ptr[v14 & 0x1FFF]) != nullptr )
  {
    v16 = (idPlayer *)idActor::CastTo(c: v15);
  }
  else
  {
    v16 = nullptr;
  }
  v17 = idPlayer::CastTo(c: v16);
  CurrentProjectileDecl = idWeapon::GetCurrentProjectileDecl(this: this->weapon, secondaryAmmo: false);
  presentable = this->presentable;
  v20 = CurrentProjectileDecl;
  *((_BYTE *)&v53 + 128) |= 0x20u;
  if ( presentable != nullptr )
  {
    v21 = presentable;
  }
  else
  {
    idEntity::InitPresentableInternal(this);
    v21 = this->presentable;
  }
  if ( v17 != nullptr )
  {
    weapon = this->weapon;
    *((_BYTE *)&v53 + 128) |= 0x10u;
    v23 = v17->presentable;
    weaponState = weapon->weaponState;
    if ( v23 != nullptr )
      v25 = v23->GetPlayerInterface_2(this: v23);
    else
      v25 = nullptr;
    v53.addSpread = idPresentablePlayer::GetCurWeaponSpread(
                      this: v25,
                      secondary: (_cntlzw(weaponState - 1) & 0x20) != 0)
                  - v20->spread;
    if ( v17->presentable == nullptr )
      idEntity::InitPresentableInternal(this: v17);
    v21 = v17->presentable;
  }
  v26 = this->presentable;
  if ( v26 == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    v26 = this->presentable;
  }
  p_fxManager = &v26->fxManager;
  v28 = (_cntlzw(this->fireInOrder) & 0x20) != 0;
  if ( this->fireInOrder )
  {
    v34 = &this->barrels.list[this->barrelIndex];
    if ( !v34->primary )
      goto LABEL_40;
    if ( primary )
    {
LABEL_41:
      v35 = 1;
      goto LABEL_43;
    }
    if ( !v34->primary )
    {
LABEL_40:
      if ( secondary )
        goto LABEL_41;
    }
    v35 = 0;
LABEL_43:
    v28 = v35;
    if ( v35 == 0 || (muzzleTagIndex = v34->muzzleTagIndex) == -1 )
    {
      idWeapon::SkipFire(this: this->weapon, secondaryAmmo: false);
    }
    else
    {
      idAnimatedEntity::GetTagPosition(
        this,
        propIndex: this->infopropIndex,
        tagIndex: muzzleTagIndex,
        origin: &v49,
        axis: &v55);
      if ( this->playerDeferredFire || v11 != nullptr )
        idWeapon::DeferredFire(
          this: this->weapon,
          attacker: v21,
          target: nullptr,
          start: &v49,
          fireAxis: &this->lookAt,
          fp: &v53,
          secondaryAmmo: false);
      else
        idWeapon::Fire(
          this: this->weapon,
          attacker: v21,
          target: nullptr,
          start: &v49,
          fireAxis: &this->lookAt,
          fp: &v53,
          tfr: &v56,
          ffr: &v54,
          fxMgr: v47,
          secondaryAmmo: v48);
      ejectTagIndex = v34->ejectTagIndex;
      if ( ejectTagIndex != -1 )
      {
        idAnimatedEntity::GetTagPosition(
          this,
          propIndex: this->infopropIndex,
          tagIndex: ejectTagIndex,
          origin: v51,
          axis: &v52);
        idWeapon::EjectShell(
          this: this->weapon,
          ejectPos: v51,
          firstPersonOffset: &vec3_origin,
          shellOrientation: &v52,
          ejectAxis: &v52,
          emitterVelocity: &vec3_origin,
          fxMgr: p_fxManager);
      }
    }
    num = this->barrels.num;
    v39 = this->barrelIndex + 1;
    __twllei(num, 0);
    this->barrelIndex = v39 % num;
    __twlgei(num & ~(__ROL4__(v39, 1) - 1), 0xFFFFFFFF);
    goto LABEL_53;
  }
  v29 = 0;
  if ( this->barrels.num > 0 )
  {
    v30 = 0;
    do
    {
      v31 = &this->barrels.list[v30];
      v32 = v31->muzzleTagIndex;
      if ( v32 != -1 )
      {
        idAnimatedEntity::GetTagPosition(this, propIndex: this->infopropIndex, tagIndex: v32, origin: &v49, axis: &v55);
        if ( this->playerDeferredFire || v11 != nullptr )
          idWeapon::DeferredFire(
            this: this->weapon,
            attacker: v21,
            target: nullptr,
            start: &v49,
            fireAxis: &this->lookAt,
            fp: &v53,
            secondaryAmmo: false);
        else
          idWeapon::Fire(
            this: this->weapon,
            attacker: v21,
            target: nullptr,
            start: &v49,
            fireAxis: &this->lookAt,
            fp: &v53,
            tfr: &v56,
            ffr: &v54,
            fxMgr: v47,
            secondaryAmmo: v48);
        v33 = v31->ejectTagIndex;
        if ( v33 != -1 )
        {
          idAnimatedEntity::GetTagPosition(this, propIndex: this->infopropIndex, tagIndex: v33, origin: v51, axis: &v52);
          idWeapon::EjectShell(
            this: this->weapon,
            ejectPos: v51,
            firstPersonOffset: &vec3_origin,
            shellOrientation: &v52,
            ejectAxis: &v52,
            emitterVelocity: &vec3_origin,
            fxMgr: p_fxManager);
        }
      }
      ++v29;
      ++v30;
    }
    while ( v29 < this->barrels.num );
  }
LABEL_53:
  if ( v28 )
  {
    if ( v17 != nullptr )
    {
      v40 = v17->presentable;
      if ( v40 != nullptr )
        v41 = v40->GetPlayerInterface_2(this: v40);
      else
        v41 = nullptr;
      idPresentablePlayer::WeaponFireFeedback(this: v41, weapon: this->weapon, projDecl: v20);
    }
    if ( v11 != nullptr )
    {
      v11->aiVolatile.memory.lastFireTime = idGameTimeManager::GetGameMs(
                                              this: &clientGame->gameTimeManager,
                                              type: GAMETIME_SCALED);
      idFocusInfo::AddWeaponFireKickback(this: v11->aiVolatile.focus.foci.ptr, owner: v11, weapon: this->weapon);
    }
  }
  if ( v53.targetList.listStatic == 0 || v53.targetList.listStatic == 2 )
  {
    if ( v53.targetList.list != nullptr )
      idMem::Free(this: &mem, ptr: v53.targetList.list, align: ALIGN_16);
    v53.targetList.list = nullptr;
    v53.targetList.size = 0;
  }
  v53.targetList.num = 0;
LABEL_67:
  if ( v50.logIndex >= 0 )
  {
    pLog = v50.pLog;
    v43 = &v50.pLog->logEntries.list[v50.logIndex];
    v44 = (unsigned __int64)Sys_GetClockTicks() >> 32;
    totalTicks = v43->totalTicks;
    HIDWORD(totalTicks) = v43->parent;
    LODWORD(v46) = v44 - totalTicks;
    v43->totalTicks = v46;
    pLog->lastEntry = HIDWORD(totalTicks);
  }
  RD_EventEnd();
}


// ========================================================================
// __unwind$497138
// EA  : 0x82D53B04
// RVA : 0x00D53B04
// PDB : w:\tech5\tungsten\game\entities\weaponstatic.cpp
// ========================================================================

void _unwind_497138()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 2912 + 2788));
}


// ========================================================================
// __unwind$497139_0
// EA  : 0x82D53B2C
// RVA : 0x00D53B2C
// PDB : w:\tech5\tungsten\game\entities\weaponstatic.cpp
// ========================================================================

void _unwind_497139_0()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 2912 + 112));
}


// ========================================================================
// __unwind$497140
// EA  : 0x82D53B54
// RVA : 0x00D53B54
// PDB : w:\tech5\tungsten\game\entities\weaponstatic.cpp
// ========================================================================

void _unwind_497140()
{
  int v0; // r12

  idFireParms::~idFireParms(this: (idAI2::idAIVolatile::idAIEventInfo *)(v0 - 2912 + 192));
}


// ========================================================================
// ?Damage@idProp_WeaponStatic@@UAAMPAVidEntity@@0PBVidDeclDamage@@MABVidVec3@@PAUtrace_t@@@Z
// EA  : 0x82D53B80
// RVA : 0x00D53B80
// PDB : w:\tech5\tungsten\game\entities\weaponstatic.cpp
// ========================================================================

float __fastcall idProp_WeaponStatic::Damage(
        idProp_WeaponStatic *this,
        idEntity *inflictor,
        idEntity *attacker,
        const idDeclDamage *damageDef,
        double damageScale,
        const idVec3 *dir,
        trace_t *trace,
        const trace_t *a8)
{
  double v14; // fp1
  double v15; // fp31
  idWeaponStatic_Armour *ArmourPieceFromTrace; // r3
  int v17; // r9
  idWeaponStatic_Armour *list; // r8
  int v19; // r11
  idEntityPtr<idActor> *p_user; // r31
  double v21; // fp31
  idActor *v22; // r3
  idPhysics *Physics; // r3
  unsigned int v24; // r30
  idPhysics *v25; // r3
  int v26; // r29
  int v27; // r30
  idPresentable *presentable; // r3
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idPhysics *v30; // r3
  int v31; // r3
  idPresentable *v32; // r11
  double v33; // fp2
  double v34; // fp0
  idPresentable *v35; // r11
  idVec3 v37; // [sp+50h] [-90h] BYREF
  idMat3 v38; // [sp+60h] [-80h] BYREF

  if ( !this->enabled || damageDef == nullptr )
    goto LABEL_2;
  v15 = (float)(idDeclDamage::DamageAmount(this: damageDef) * (float)damageScale);
  if ( damageDef == gameLocal->damageSuicide )
  {
    v15 = (float)(this->currentHealth + (float)1.0);
    goto LABEL_19;
  }
  if ( !this->TakesDamage(this) )
    goto LABEL_2;
  if ( a8 != nullptr )
  {
    ArmourPieceFromTrace = idProp_WeaponStatic::GetArmourPieceFromTrace(this, trace: a8);
    if ( ArmourPieceFromTrace == nullptr )
      goto LABEL_11;
    if ( !ArmourPieceFromTrace->takesDamage )
    {
LABEL_2:
      v14 = 0.0;
      return *((float *)&v14 + 1);
    }
    if ( v15 <= ArmourPieceFromTrace->currentHealth )
    {
      ArmourPieceFromTrace->currentHealth = ArmourPieceFromTrace->currentHealth - (float)v15;
      v14 = 0.0;
      return *((float *)&v14 + 1);
    }
    v15 = (float)((float)v15 - ArmourPieceFromTrace->currentHealth);
    idProp_WeaponStatic::BreakArmourPiece(this, armourPiece: ArmourPieceFromTrace);
  }
LABEL_11:
  v17 = 0;
  if ( this->armourPieces.num > 0 )
  {
    list = this->armourPieces.list;
    v19 = 0;
    while ( list[v19].brokenTimestamp != -1 || !list[v19].causesImmunity )
    {
      ++v17;
      ++v19;
      if ( v17 >= this->armourPieces.num )
        goto LABEL_19;
    }
    goto LABEL_2;
  }
LABEL_19:
  if ( v15 <= 0.0 )
  {
LABEL_20:
    v14 = 0.0;
    return *((float *)&v14 + 1);
  }
  if ( (*((_BYTE *)this + 5748) & 0x80) != 0 )
  {
    p_user = &this->user;
    if ( idEntityPtr<idActor>::operator idActor *(this: p_user) != nullptr )
    {
      v21 = (float)((float)v15 / (float)(idDeclDamage::DamageAmount(this: damageDef) * (float)damageScale));
      v22 = idEntityPtr<idActor>::operator idActor *(this: p_user);
      ((void (__fastcall *)(idActor *, idEntity *, idEntity *, const idDeclDamage *, double))v22->Damage)(
        a1: v22,
        a2: inflictor,
        a3: attacker,
        a4: damageDef,
        a5: v21);
      return *((float *)&v14 + 1);
    }
    goto LABEL_20;
  }
  if ( this->currentHealth <= v15 )
  {
    this->enabled = false;
    Physics = idEntity::GetPhysics(this);
    v24 = Physics->GetContents(this: Physics, a2: -1) & 0xFFFFFDFF;
    v25 = idEntity::GetPhysics(this);
    v25->SetContents(this: v25, a2: v24, a3: -1);
    if ( idEntityPtr<idActor>::operator idActor *(this: &this->user) != nullptr )
      this->Use(this, a2: nullptr, a3: USABLE_MAX);
    idProp_WeaponStatic::CheckAttachments(this);
    v26 = 0;
    if ( this->armourPieces.num > 0 )
    {
      v27 = 0;
      do
      {
        idProp_WeaponStatic::BreakArmourPiece(this, armourPiece: &this->armourPieces.list[v27]);
        ++v26;
        ++v27;
      }
      while ( v26 < this->armourPieces.num );
    }
    presentable = this->presentable;
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      presentable = this->presentable;
    }
    presentable->StopAllFX(this: presentable);
    if ( this->deadModel != nullptr )
    {
      if ( (unsigned __int16)this->jointPitch.value == 0xFFFF
        || idAnimatedEntity::GetTreeAnimatorFromPresentable(this) == nullptr )
      {
        this->SetModel(this, a2: this->deadModel);
      }
      else
      {
        this->SetModel(this, a2: this->deadModel);
        TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
        idTreeAnimator::GetWorldSpaceJointTransform(
          this: TreeAnimatorFromPresentable,
          pose: DRIVER_MODEL,
          jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)this->jointPitch.value,
          origin: &v37,
          axis: &v38);
        v30 = idEntity::GetPhysics(this);
        v31 = (int)v30->GetBounds(this: v30, a2: -1);
        v32 = this->presentable;
        v33 = (float)((float)(v38.mat[0].z * *(float *)(v31 + 12)) * (float)0.25);
        v34 = (float)(v37.y + (float)((float)(v38.mat[0].y * *(float *)(v31 + 12)) * (float)0.25));
        v37.x = (float)((float)(v38.mat[0].x * *(float *)(v31 + 12)) * (float)0.25) + v37.x;
        v37.y = v34;
        v37.z = v37.z + (float)v33;
        if ( v32 == nullptr )
        {
          idEntity::InitPresentableInternal(this);
          v32 = this->presentable;
        }
        v32->origin = v37;
        v35 = this->presentable;
        if ( v35 == nullptr )
        {
          idEntity::InitPresentableInternal(this);
          v35 = this->presentable;
        }
        v35->axis = v38;
      }
    }
    idEntity::BecomeInactive(this, flags: 7);
  }
  else
  {
    this->currentHealth = this->currentHealth - (float)v15;
  }
  v14 = v15;
  return *((float *)&v14 + 1);
}


// ========================================================================
// ?Think@idProp_WeaponStatic@@UAAXXZ
// EA  : 0x82D54090
// RVA : 0x00D54090
// PDB : w:\tech5\tungsten\game\entities\weaponstatic.cpp
// ========================================================================

void __fastcall idProp_WeaponStatic::Think(idProp_WeaponStatic *this)
{
  unsigned __int64 v2; // r6
  const char *v3; // r7
  int value; // r10
  idEntityPtr<idActor> *p_user; // r30
  idActor *v6; // r3
  idPlayer *v7; // r28
  const idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idActor *v9; // r3
  const idDeclWeapon *weaponDecl; // r11
  int entityNumber; // r6
  idWeapon *weapon; // r3
  double v13; // fp7
  double v14; // fp5
  idFinishFireResults *v15; // r11
  int i; // ctr
  idPresentable *presentable; // r11
  int v18; // r9
  int v19; // r11
  idActor *v20; // r3
  idPlayer *v21; // r3
  idPlayer *v22; // r3
  idPresentable *v23; // r3
  idPresentablePlayer *v24; // r30
  const idDeclProjectile *CurrentProjectileDecl; // r3
  int GameMs; // r3
  int coolDownTime; // r11
  idPlayer *v28; // r17
  idAI2 *v29; // r15
  int v30; // r26
  int v31; // r3
  int v32; // r3
  _DWORD *v33; // r30
  int v34; // r27
  int v35; // r28
  idTrigger_VehicleUse *v36; // r3
  idTreeAnimator *v37; // r3
  idMat3 *p_lookAt; // r30
  double y; // fp12
  double z; // fp11
  idVec3 *v41; // r24
  idVec3 *v42; // r23
  double x; // fp8
  double v44; // fp29
  double v45; // fp28
  char v46; // r18
  bool v47; // r14
  double v48; // fp27
  BOOL v49; // r20
  BOOL v50; // r21
  int UCmdTracker2; // r28
  __int64 v52; // r5
  int v53; // r3
  int v54; // r26
  int v55; // r10
  int v56; // r11
  int v57; // r11
  int v58; // r11
  int v59; // r11
  char v60; // r11
  int v61; // r11
  int v62; // r10
  int v63; // r11
  __int64 v64; // r6
  double v65; // fp1
  double v66; // fp29
  __int64 v67; // r6
  double v68; // fp1
  double v69; // fp31
  double v70; // fp1
  idPhysics *Physics; // r3
  idPresentable *v72; // r11
  idPhysics *v73; // r27
  float *v74; // r28
  float *v75; // r3
  __int64 v76; // r8
  idGameLocal *v77; // r10
  double v78; // fp31
  int v79; // r28
  int v80; // r3
  __int64 v81; // r5
  idCurve_Spline<idVec3> *spline; // r4
  __int64 v83; // fp11
  double v84; // fp13
  double v85; // fp0
  idPresentable *v86; // r11
  idPresentable *v87; // r11
  unsigned __int64 v88; // r6
  const char *v89; // r7
  const idEntity *Enemy; // r3
  double v91; // fp0
  double v92; // fp7
  idPresentable *v93; // r11
  double v94; // fp1
  double v95; // fp30
  double v96; // fp1
  double v97; // fp31
  double v98; // fp1
  double v99; // fp1
  double v100; // fp31
  double v101; // fp1
  double v102; // fp30
  double v103; // fp1
  idTreeAnimator *v112; // r27
  int v113; // r3
  char v114; // r11
  char v115; // r28
  double v116; // fp22
  int turning; // r11
  int v118; // r11
  unsigned __int64 v119; // r6
  const char *v120; // r7
  idPresentable *v121; // r11
  int *v122; // r10
  idPresentable *p_z; // r11
  int j; // ctr
  double lookConeDegrees; // fp8
  double v126; // fp12
  double minYaw; // fp28
  double minPitch; // fp29
  double maxYaw; // fp13
  double maxPitch; // fp0
  double v131; // fp1
  double v132; // fp31
  double v133; // fp1
  double v134; // fp30
  double v135; // fp1
  idMat3 *v136; // r3
  const idMat3 *v137; // r27
  idMat3 *v138; // r3
  idMat3 *v139; // r3
  long double v140; // fp4
  double v141; // fp30
  double v142; // fp27
  double v143; // fp0
  double v144; // fp28
  double v145; // fp0
  long double v146; // fp2
  double v147; // fp29
  long double v148; // fp2
  double v149; // fp31
  long double v150; // fp2
  double v151; // fp29
  long double v152; // fp2
  double v153; // fp28
  long double v154; // fp2
  long double v155; // fp2
  double v156; // fp0
  double v157; // fp31
  long double v158; // fp2
  double v159; // fp0
  double v160; // fp31
  long double v161; // fp2
  double v162; // fp31
  long double v163; // fp2
  double v164; // fp11
  double v165; // fp10
  double v166; // fp7
  double v167; // fp6
  int *v168; // r10
  float *v169; // r11
  int m; // ctr
  const idMat3 *v171; // r3
  double v172; // fp13
  double v173; // fp5
  double v174; // fp4
  double v175; // fp1
  double v176; // fp2
  double v177; // fp0
  double v178; // fp12
  const idMat3 *v179; // r27
  idMat3 *v180; // r3
  idMat3 *v181; // r3
  long double v182; // fp2
  double v183; // fp1
  double v184; // fp31
  double v185; // fp11
  double v186; // fp10
  double v187; // fp7
  double v188; // fp6
  int *v189; // r10
  float *p_y; // r11
  int k; // ctr
  const idMat3 *v192; // r3
  double v193; // fp12
  double v194; // fp3
  double v195; // fp13
  double v196; // fp11
  idMat3 *v197; // r3
  idMat3 *v198; // r3
  idMat3 *v199; // r3
  idPresentable *v200; // r11
  double v201; // fp13
  float *v202; // r11
  double v203; // fp0
  double v204; // fp13
  double v205; // fp12
  double v206; // fp11
  double v207; // fp10
  double v208; // fp9
  double v209; // fp8
  double v210; // fp7
  double v211; // fp6
  int v212; // r10
  int v213; // r9
  int v214; // r8
  int v215; // r7
  int v216; // r6
  const idMat3 *v217; // r3
  int v218; // r10
  int v219; // r9
  int v220; // r8
  int v221; // r7
  int v222; // r6
  unsigned __int64 v223; // r6
  const char *v224; // r7
  double v225; // fp11
  double v226; // fp10
  double v227; // fp6
  idPhysics *v228; // r3
  idClipModel *v229; // r3
  idPresentable *v230; // r3
  int v231; // r3
  char v232; // r11
  int v233; // r11
  const idSoundShader *v234; // r5
  const idSoundShader *sndTurning; // r9
  double max; // fp1
  idPhysics *v237; // r3
  idBounds *v238; // r3
  int v239; // [sp+8h] [-DF8h]
  int v240; // [sp+8h] [-DF8h]
  int v241; // [sp+Ch] [-DF4h]
  int v242; // [sp+Ch] [-DF4h]
  int v243; // [sp+10h] [-DF0h]
  int v244; // [sp+10h] [-DF0h]
  int v245; // [sp+14h] [-DECh]
  int v246; // [sp+14h] [-DECh]
  int v247; // [sp+18h] [-DE8h]
  int v248; // [sp+18h] [-DE8h]
  idIndex<short,enum invalidUserChannelIndex_t> *v249; // [sp+1Ch] [-DE4h]
  idIndex<short,enum invalidUserChannelIndex_t> *v250; // [sp+1Ch] [-DE4h]
  idAngles v251; // [sp+50h] [-DB0h] BYREF
  float v252[11]; // [sp+60h] [-DA0h] BYREF
  idPLog *v253; // [sp+8Ch] [-D74h]
  idPLogScope v254; // [sp+90h] [-D70h] BYREF
  idPLogScope v255; // [sp+98h] [-D68h] BYREF
  idMat3 v256; // [sp+A0h] [-D60h] BYREF
  float v257; // [sp+C4h] [-D3Ch]
  float v258; // [sp+C8h] [-D38h]
  idMat3 v259; // [sp+D0h] [-D30h] BYREF
  float v260; // [sp+F4h] [-D0Ch]
  float v261; // [sp+F8h] [-D08h]
  float v262; // [sp+FCh] [-D04h]
  float v263; // [sp+100h] [-D00h]
  float v264; // [sp+104h] [-CFCh]
  float v265; // [sp+108h] [-CF8h]
  float v266; // [sp+10Ch] [-CF4h]
  float v267; // [sp+110h] [-CF0h]
  idVec3 v268[2]; // [sp+118h] [-CE8h] BYREF
  idMat3 v269; // [sp+130h] [-CD0h] BYREF
  int v270; // [sp+15Ch] [-CA4h] BYREF
  idMat3 v271; // [sp+160h] [-CA0h] BYREF
  idVec3 v272; // [sp+188h] [-C78h] BYREF
  idVec3 v273; // [sp+198h] [-C68h] BYREF
  idVec3 v274; // [sp+1A8h] [-C58h] BYREF
  idVec3 v275[2]; // [sp+1B8h] [-C48h] BYREF
  idMat3 v276; // [sp+1D0h] [-C30h] BYREF
  float v277[4]; // [sp+1F8h] [-C08h] BYREF
  float v278[5]; // [sp+208h] [-BF8h] BYREF
  int v279; // [sp+21Ch] [-BE4h] BYREF
  idMat3 v280; // [sp+220h] [-BE0h] BYREF
  idMat3 v281; // [sp+250h] [-BB0h] BYREF
  idMat3 v282; // [sp+280h] [-B80h] BYREF
  idMat3 v283; // [sp+2B0h] [-B50h] BYREF
  idAngles v284[4]; // [sp+2E0h] [-B20h] BYREF
  idFinishFireResults v285; // [sp+310h] [-AF0h] BYREF
  idFireParms v286; // [sp+360h] [-AA0h] BYREF
  idTestFireResults v287; // [sp+400h] [-A00h] BYREF

  RD_EventBegin(name: "idProp_WeaponStatic::Think");
  LODWORD(v2) = "idProp_WeaponStatic::Think";
  HIDWORD(v2) = 2;
  v253 = &pLog;
  idPLogScope::idPLogScope(this: &v254, pl: &pLog, gMask: v2, label: v3);
  if ( (unsigned __int8)idEntity::UpdateDormant(this) != 0 )
    goto LABEL_50;
  value = this->user.spawnId.value;
  p_user = &this->user;
  LODWORD(v251.pitch) = &this->user;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
  {
    v6 = (idActor *)gameLocal->entities.ptr[value & 0x1FFF];
    if ( v6 != nullptr )
      v7 = (idPlayer *)idActor::CastTo(c: v6);
    else
      v7 = nullptr;
  }
  else
  {
    v7 = nullptr;
  }
  if ( this->weaponDecl->hasLaserUpgrade && v7 != nullptr )
  {
    TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
    if ( idWeapon::GetLaserSightWorldTransform(
           this: this->weapon,
           ta: TreeAnimatorFromPresentable,
           origin: &v274,
           axis: &v282) )
    {
      v9 = idEntityPtr<idActor>::operator idActor *(this: &this->user);
      weaponDecl = this->weaponDecl;
      entityNumber = v9->entityNumber;
      weapon = this->weapon;
      v13 = (float)(weaponDecl->maxRange * v282.mat[0].y);
      v14 = (float)(weaponDecl->maxRange * v282.mat[0].x);
      v277[2] = (float)(weaponDecl->maxRange * v282.mat[0].z) + v274.z;
      v277[1] = (float)v13 + v274.y;
      v277[0] = v274.x + (float)v14;
      weapon->UpdateLaserSight(this: weapon, a2: &v274, a3: (const idVec3 *)v277, a4: entityNumber, a5: v7);
    }
  }
  if ( idWeapon::CheckFireHandle(this: this->weapon) )
  {
    idFireParms::idFireParms(this: &v286);
    memset(&v287, 0, sizeof(v287));
    v15 = &v285;
    v285.numProjectiles = 0;
    for ( i = 16; i != 0; --i )
    {
      v15 = (idFinishFireResults *)((char *)v15 + 4);
      v15->numProjectiles = 0;
    }
    presentable = this->presentable;
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      presentable = this->presentable;
    }
    idWeapon::ResolveFire(this: this->weapon, fp: &v286, tfr: &v287, ffr: &v285, fxMgr: &presentable->fxManager);
    v18 = p_user->spawnId.value;
    v19 = p_user->spawnId.value & 0x1FFF;
    LODWORD(v251.pitch) = &this->user;
    if ( gameLocal->spawnIds.ptr[v19] == v18 >> 13 && (v20 = (idActor *)gameLocal->entities.ptr[v19]) != nullptr )
      v21 = (idPlayer *)idActor::CastTo(c: v20);
    else
      v21 = nullptr;
    v22 = idPlayer::CastTo(c: v21);
    if ( v22 != nullptr )
    {
      v23 = v22->presentable;
      if ( v23 != nullptr )
        v24 = v23->GetPlayerInterface_2(this: v23);
      else
        v24 = nullptr;
      CurrentProjectileDecl = idWeapon::GetCurrentProjectileDecl(this: this->weapon, secondaryAmmo: false);
      idPresentablePlayer::WeaponFireFeedback(this: v24, weapon: this->weapon, projDecl: CurrentProjectileDecl);
    }
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v286.targetList);
  }
  if ( this->coolDownTime > 0 )
  {
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    coolDownTime = this->coolDownTime;
    if ( GameMs >= coolDownTime )
    {
      idProp_Usable::SetUsable(this, b: true);
      this->coolDownTime = 0;
      goto LABEL_29;
    }
    if ( coolDownTime > 0 )
    {
LABEL_50:
      idPLogScope::~idPLogScope(this: &v254);
      goto LABEL_207;
    }
  }
LABEL_29:
  idAnimator_JointMod::ClearJointMods(this: &this->jointModAnimator);
  if ( v7 == nullptr )
  {
    if ( idProp_Usable::IsEverUsable(this, activator: nullptr) )
      goto LABEL_37;
LABEL_36:
    this->Use(this, a2: nullptr, a3: USABLE_MAX);
    goto LABEL_37;
  }
  if ( v7->IsDead(this: v7) || v7->IsDying(this: v7) )
    goto LABEL_36;
LABEL_37:
  v28 = idPlayer::CastTo(c: v7);
  v29 = idAI2::CastTo(c: (idAI2 *)v7);
  if ( v28 != nullptr && v28->GetVehicle_2(this: v28) != nullptr )
  {
    v30 = 1;
    v31 = (int)v28->GetVehicle_2(this: v28);
    v32 = (*(int (__fastcall **)(int))(*(_DWORD *)v31 + 416))(a1: v31);
    v33 = (_DWORD *)v32;
    if ( v32 != 0 )
    {
      v34 = 0;
      if ( *(int *)(v32 + 4) > 0 )
      {
        v35 = 0;
        do
        {
          v36 = (idTrigger_VehicleUse *)idEntityPtr<idEntity const>::operator->(this: (idEntityPtr<idEntity> *)(v35 + *v33));
          if ( v36 != nullptr )
            v30 = idTrigger_VehicleUse::CastTo(c: v36) != nullptr ? 0 : v30;
          ++v34;
          v35 += 4;
        }
        while ( v34 < v33[1] );
      }
    }
    if ( (_BYTE)v30 != 0 )
    {
      this->Use(this, a2: nullptr, a3: USABLE_MAX);
      v28 = nullptr;
    }
  }
  if ( (unsigned __int16)this->jointPitch.value >= 0x8000u )
    goto LABEL_50;
  v37 = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
  if ( (unsigned __int8)idTreeAnimator::GetWorldSpaceJointTransform(
                          this: v37,
                          pose: DRIVER_MODEL,
                          jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)this->jointPitch.value,
                          origin: (idVec3 *)&v259.mat[1].y,
                          axis: &v276) == 0 )
    goto LABEL_50;
  p_lookAt = &this->lookAt;
  if ( (unsigned __int8)idMat3::Compare(this: &this->lookAt, a: &mat3_identity, epsilon: 0.000099999997) != 0 )
  {
    p_lookAt->mat[0].x = v276.mat[0].x;
    y = v276.mat[0].y;
    z = v276.mat[0].z;
    this->lookAt.mat[1].x = v276.mat[1].x;
    this->lookAt.mat[0].y = y;
    this->lookAt.mat[0].z = z;
    this->lookAt.mat[1].y = v276.mat[1].y;
    this->lookAt.mat[1].z = v276.mat[1].z;
    LODWORD(v251.pitch) = &this->prevLookAt.mat[2];
    this->lookAt.mat[2] = v276.mat[2];
    this->prevLookAt.mat[0].x = p_lookAt->mat[0].x;
    this->prevLookAt.mat[0].y = this->lookAt.mat[0].y;
    this->prevLookAt.mat[0].z = this->lookAt.mat[0].z;
    this->prevLookAt.mat[1].x = this->lookAt.mat[1].x;
    this->prevLookAt.mat[1].y = this->lookAt.mat[1].y;
    this->prevLookAt.mat[1].z = this->lookAt.mat[1].z;
    this->prevLookAt.mat[2].x = this->lookAt.mat[2].x;
    this->prevLookAt.mat[2].y = this->lookAt.mat[2].y;
    this->prevLookAt.mat[2].z = this->lookAt.mat[2].z;
  }
  this->prevLookAt.mat[0].x = p_lookAt->mat[0].x;
  v41 = &this->lookAt.mat[1];
  this->prevLookAt.mat[0].y = this->lookAt.mat[0].y;
  LODWORD(v251.pitch) = &this->lookAt;
  v42 = &this->lookAt.mat[2];
  this->prevLookAt.mat[0].z = this->lookAt.mat[0].z;
  LODWORD(v251.pitch) = &this->lookAt.mat[1];
  this->prevLookAt.mat[1].x = this->lookAt.mat[1].x;
  LODWORD(v251.pitch) = &this->prevLookAt.mat[1];
  this->prevLookAt.mat[1].y = this->lookAt.mat[1].y;
  this->prevLookAt.mat[1].z = this->lookAt.mat[1].z;
  LODWORD(v251.pitch) = &this->lookAt.mat[2];
  x = this->lookAt.mat[2].x;
  LODWORD(v251.pitch) = &this->prevLookAt.mat[2];
  this->prevLookAt.mat[2].x = x;
  this->prevLookAt.mat[2].y = this->lookAt.mat[2].y;
  this->prevLookAt.mat[2].z = this->lookAt.mat[2].z;
  idMat3::ToAngles(this: (idMat3 *)&v252[8], result: (idAngles *)&this->lookAt);
  v44 = 0.0;
  v45 = 0.0;
  v46 = 0;
  v47 = false;
  v48 = 0.0;
  v49 = s_turretDebugMuzzle.valueInteger != 0;
  v50 = v49;
  v256.mat[0] = *(idVec3 *)&v252[8];
  if ( v28 != nullptr )
  {
    v47 = true;
    UCmdTracker2 = idPlayer::GetUCmdTracker2(this: v28);
    v53 = idPlayer::GetUCmdTracker2(this: v28);
    v54 = v53;
    if ( (*((_BYTE *)this + 5748) & 0x20) != 0 )
      goto LABEL_70;
    v55 = *(unsigned __int8 *)(v53 + 77) >> 7;
    LOBYTE(v56) = 0;
    if ( v55 == 0 )
      v56 = *(_DWORD *)(v53 + 68);
    if ( (v56 & 4) != 0 )
    {
      LOBYTE(v57) = 0;
      if ( (*(_BYTE *)(UCmdTracker2 + 17) & 0x80) == 0 )
        v57 = *(_DWORD *)(UCmdTracker2 + 8);
      if ( (v57 & 4) == 0 )
        goto LABEL_69;
    }
    LOBYTE(v58) = 0;
    if ( v55 == 0 )
      v58 = *(_DWORD *)(v53 + 68);
    if ( (v58 & 0x20) != 0 )
    {
      LOBYTE(v59) = 0;
      if ( (*(_BYTE *)(UCmdTracker2 + 17) & 0x80) == 0 )
        v59 = *(_DWORD *)(UCmdTracker2 + 8);
      if ( (v59 & 0x20) == 0 )
        goto LABEL_69;
    }
    if ( *(_BYTE *)(v53 + 76) != 0 || *(_BYTE *)(UCmdTracker2 + 16) == 0 )
LABEL_70:
      v60 = 0;
    else
LABEL_69:
      v60 = 1;
    v46 = v60;
    LOBYTE(v61) = 0;
    v62 = *(unsigned __int8 *)(v53 + 77) >> 7;
    if ( v62 == 0 )
      v61 = *(_DWORD *)(v53 + 68);
    v49 = v61 & 1;
    if ( this->weaponDecl->canZoom )
    {
      v50 = v61 & 1;
    }
    else
    {
      LOBYTE(v63) = 0;
      if ( v62 == 0 )
        v63 = *(_DWORD *)(v53 + 68);
      v50 = (v63 & 8) != 0;
    }
    LODWORD(v52) = *(__int16 *)(v53 + 78) - *(__int16 *)(UCmdTracker2 + 18);
    *(_QWORD *)&v251.pitch = v52;
    v65 = idMath::AngleNormalize360(angle: (float)((float)v52 * (float)0.0054931641));
    v66 = v65;
    if ( v65 > 180.0 )
      v66 = (float)((float)v65 - (float)360.0);
    LODWORD(v64) = *(__int16 *)(v54 + 80) - *(__int16 *)(UCmdTracker2 + 20);
    *(_QWORD *)&v251.pitch = v64;
    v68 = idMath::AngleNormalize360(angle: (float)((float)v64 * (float)0.0054931641));
    v69 = v68;
    if ( v68 > 180.0 )
      v69 = (float)((float)v68 - (float)360.0);
    LODWORD(v67) = *(__int16 *)(v54 + 82) - *(__int16 *)(UCmdTracker2 + 22);
    *(_QWORD *)&v251.pitch = v67;
    v70 = idMath::AngleNormalize360(angle: (float)((float)v67 * (float)0.0054931641));
    if ( v70 > 180.0 )
      v70 = (float)((float)v70 - (float)360.0);
    v44 = (float)((float)v66 * s_turretTurnScale.valueFloat);
    v45 = (float)((float)v69 * s_turretTurnScale.valueFloat);
    v48 = (float)((float)v70 * s_turretTurnScale.valueFloat);
    Physics = idEntity::GetPhysics(this);
    v72 = v28->presentable;
    v73 = Physics;
    if ( v72 != nullptr )
      v74 = (float *)v72->GetPlayerInterface_2(this: v28->presentable);
    else
      v74 = nullptr;
    v75 = (float *)v73->GetAxis(this: v73, a2: 0);
    v74[33] = *v75;
    v74[34] = v75[1];
    HIDWORD(v76) = v74 + 39;
    v74[35] = v75[2];
    LODWORD(v251.pitch) = v75 + 3;
    v77 = gameLocal;
    v74[36] = v75[3];
    LODWORD(v251.pitch) = v74 + 36;
    v74[37] = v75[4];
    LODWORD(v251.pitch) = v75 + 6;
    v74[38] = v75[5];
    LODWORD(v251.pitch) = &this->splinePath;
    v74[39] = v75[6];
    v74[40] = v75[7];
    v74[41] = v75[8];
    if ( v77->spawnIds.ptr[this->splinePath.spawnId.value & 0x1FFF] == this->splinePath.spawnId.value >> 13 )
    {
      LODWORD(v76) = *(char *)(v54 + 75);
      *(_QWORD *)&v251.pitch = v76;
      v78 = (float)((float)v76 * (float)0.0078740157);
      v79 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED)
          - this->lastUpdateTime;
      v80 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      LODWORD(v81) = v79;
      this->lastUpdateTime = v80;
      *(_QWORD *)&v251.pitch = v81;
      v83 = v81;
      spline = this->spline;
      v84 = spline->times.list[spline->values.num - 1];
      v85 = (float)((float)((float)((float)v83 * (float)v78) * (float)0.1) + this->currentSplinePos);
      LODWORD(v251.pitch) = spline;
      if ( v85 >= 0.0 )
      {
        if ( v85 > v84 )
          v85 = v84;
      }
      else
      {
        v85 = 0.0;
      }
      this->currentSplinePos = v85;
      ((void (__fastcall *)(idVec3 *, double))spline->GetCurrentValue)(a1: v268, a2: v85);
      idEntity::SetOrigin(this, org: v268);
      v86 = this->presentable;
      if ( v86 == nullptr )
      {
        idEntity::InitPresentableInternal(this);
        v86 = this->presentable;
      }
      v86->origin.x = v268[0].x;
      LODWORD(v251.pitch) = &v86->origin;
      v86->origin.y = v268[0].y;
      v86->origin.z = v268[0].z;
      ((void (__fastcall *)(float *, double))this->spline->GetCurrentFirstDerivative)(
        a1: v278,
        a2: this->currentSplinePos);
      v269.mat[1].z = -v278[2];
      v269.mat[1].x = -v278[0];
      v269.mat[2].x = vec3_up.x;
      v269.mat[2].y = vec3_up.y;
      v269.mat[2].z = vec3_up.z;
      v269.mat[1].y = -v278[1];
      idMat3::OrthoNormalizeSelf(this: &v269, prio1: 1, prio2: 2);
      ++this->turning;
      this->SetAxis(this, a2: &v269);
      v87 = this->presentable;
      if ( v87 == nullptr )
      {
        idEntity::InitPresentableInternal(this);
        v87 = this->presentable;
      }
      v87->axis.mat[0].x = v269.mat[0].x;
      LODWORD(v251.pitch) = &v87->axis.mat[2];
      v87->axis.mat[0].y = v269.mat[0].y;
      v87->axis.mat[0].z = v269.mat[0].z;
      v87->axis.mat[1] = v269.mat[1];
      v87->axis.mat[2] = v269.mat[2];
      idEntity::SetOrigin(this: v28, org: v268);
      v28->SetAxis(this: v28, a2: &v269);
    }
  }
  else if ( v29 != nullptr )
  {
    RD_EventBegin(name: "idProp_WeaponStatic::Think - AI");
    LODWORD(v88) = "idProp_WeaponStatic::Think - AI";
    HIDWORD(v88) = 2;
    idPLogScope::idPLogScope(this: &v255, pl: v253, gMask: v88, label: v89);
    v47 = false;
    Enemy = idAIMemory::GetEnemy(this: &v29->aiVolatile.memory);
    idAI2::SetAimFocusEntity(this: v29, ent: Enemy, keepFocusInView: false, aimPoint: AIMPOINT_BEST, timeout: -1);
    v91 = v29->aiVolatile.focus.foci.ptr[0].curFocusPoint.z;
    v92 = (float)(v29->aiVolatile.focus.foci.ptr[0].curFocusPoint.y - v259.mat[1].z);
    v272.x = v29->aiVolatile.focus.foci.ptr[0].curFocusPoint.x - v259.mat[1].y;
    LODWORD(v251.pitch) = &v29->aiVolatile.focus.foci.ptr[0].curFocusPoint;
    v272.z = (float)v91 - v259.mat[2].x;
    v272.y = v92;
    idVec3::NormalizeFast(this: &v272);
    idVec3::ToAngles(this: (idVec3 *)&v252[4], result: (idAngles *)&v272);
    v93 = this->presentable;
    if ( v93 == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      v93 = this->presentable;
    }
    idMat3::ToAngles(this: (idMat3 *)&v256.mat[1].y, result: (idAngles *)&v93->axis);
    v94 = idMath::AngleNormalize360(angle: (float)(v252[6] - v252[10]));
    v95 = v94;
    if ( v94 > 180.0 )
      v95 = (float)((float)v94 - (float)360.0);
    v96 = idMath::AngleNormalize360(angle: (float)(v252[5] - v252[9]));
    v97 = v96;
    if ( v96 > 180.0 )
      v97 = (float)((float)v96 - (float)360.0);
    v98 = idMath::AngleNormalize360(angle: (float)(v252[4] - v252[8]));
    if ( v98 > 180.0 )
      v98 = (float)((float)v98 - (float)360.0);
    v44 = v98;
    v45 = v97;
    v48 = v95;
    v99 = idMath::AngleNormalize360(angle: (float)(v252[6] - v256.mat[2].x));
    v100 = v99;
    if ( v99 > 180.0 )
      v100 = (float)((float)v99 - (float)360.0);
    v101 = idMath::AngleNormalize360(angle: (float)(v252[5] - v256.mat[1].z));
    v102 = v101;
    if ( v101 > 180.0 )
      v102 = (float)((float)v101 - (float)360.0);
    v103 = idMath::AngleNormalize360(angle: (float)(v252[4] - v256.mat[1].y));
    if ( v103 > 180.0 )
      v103 = (float)((float)v103 - (float)360.0);
    v256.mat[2].z = v103;
    v257 = v102;
    v258 = v100;
    v251.pitch = 45.0;
    v251.yaw = 45.0;
    v251.roll = 0.0;
    idAngles::Normalize180(this: (idAngles *)&v256.mat[2].z);
    v252[2] = -0.0;
    v252[0] = -45.0;
    v252[1] = -45.0;
    idAngles::Clamp(this: (idAngles *)&v256.mat[2].z, min: (const idAngles *)v252, max: &v251);
    _FP7 = (float)((float)-0.99000001 - (float)(v257 * (float)-0.022222223));
    _FP6 = (float)((float)-0.99000001 - (float)(v256.mat[2].z * (float)-0.022222223));
    __asm
    {
      fsel      f5, f7, f0, f9
      fsel      f4, f6, f0, f8
    }
    _FP3 = (float)((float)0.99000001 - (float)_FP5);
    _FP2 = (float)((float)0.99000001 - (float)_FP4);
    __asm
    {
      fsel      f31, f3, f5, f13
      fsel      f30, f2, f4, f13
    }
    v112 = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: v29);
    v113 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    v252[0] = _FP31;
    v252[1] = _FP30;
    v252[2] = 1.0;
    idAnimator_TurretNxN<3>::Update(
      this: &v29->aiVolatile.animation.turretAnimator,
      point: (const idVec3 *)v252,
      time: v113,
      animator: v112);
    if ( idProp_WeaponStatic::IsPointInFiringRange(
           this,
           target: &v29->aiVolatile.focus.foci.ptr[0].curFocusPoint,
           safetyMargin: 0.0) )
    {
      v50 = idProp_WeaponStatic::AIShouldFire(this, ai: v29);
      v49 = v50;
    }
    else
    {
      v50 = false;
      v49 = false;
    }
    v46 = 0;
    idPLogScope::~idPLogScope(this: &v255);
    RD_EventEnd();
  }
  if ( v49 || (v114 = 0, v50) )
    v114 = 1;
  v115 = v114;
  v116 = (float)((float)((float)v44 * (float)v44)
               + (float)((float)((float)v48 * (float)v48) + (float)((float)v45 * (float)v45)));
  v251.pitch = (float)((float)v44 * (float)v44)
             + (float)((float)((float)v48 * (float)v48) + (float)((float)v45 * (float)v45));
  if ( __fsqrts(v116) <= 0.0 )
  {
    if ( v28 == nullptr || (v118 = 3, this->turning <= 3) )
      v118 = 0;
    goto LABEL_125;
  }
  turning = this->turning;
  if ( turning <= 3 )
  {
    v118 = turning + 1;
LABEL_125:
    this->turning = v118;
  }
  if ( this->turning == 0
    && (unsigned __int8)idMat3::Compare(this: &this->lookAt, a: &mat3_identity, epsilon: 0.000099999997) == 0 )
  {
    goto _M499638;
  }
  RD_EventBegin(name: "idProp_WeaponStatic::Think - clamp angles");
  LODWORD(v119) = "idProp_WeaponStatic::Think - clamp angles";
  HIDWORD(v119) = 2;
  idPLogScope::idPLogScope(this: &v255, pl: v253, gMask: v119, label: v120);
  v121 = this->presentable;
  if ( v121 == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    v121 = this->presentable;
  }
  v122 = &v270;
  p_z = (idPresentable *)&v121->origin.z;
  for ( j = 9; j != 0; --j )
  {
    p_z = (idPresentable *)((char *)p_z + 4);
    *++v122 = (int)p_z->__vftable;
  }
  idMat3::ToAngles(this: &v259, result: (idAngles *)&v271);
  lookConeDegrees = this->lookConeDegrees;
  v126 = (float)(v252[10] + (float)v48);
  v252[8] = v252[8] + (float)v44;
  v252[9] = v252[9] + (float)v45;
  v252[10] = v252[10] + (float)v48;
  if ( lookConeDegrees != 0.0 )
  {
    v179 = idMat3::Inverse(this: &v281, result: &v271);
    v180 = idAngles::ToMat3(this: v284, result: (idMat3 *)&v252[8]);
    v181 = idMat3::operator*(this: &v280, result: v180, a: v179);
    p_lookAt->mat[0].x = v181->mat[0].x;
    LODWORD(v251.pitch) = &this->lookAt.mat[2];
    this->lookAt.mat[0].y = v181->mat[0].y;
    this->lookAt.mat[0].z = v181->mat[0].z;
    this->lookAt.mat[1] = v181->mat[1];
    this->lookAt.mat[2] = v181->mat[2];
    *(double *)&v182 = p_lookAt->mat[0].x;
    v183 = idMath::ACos(a: v182);
    v184 = this->lookConeDegrees;
    if ( (float)((float)v183 * idMath::M_RAD2DEG) <= v184 )
    {
LABEL_167:
      v199 = idMat3::operator*(this: &v281, result: &this->lookAt, a: &v271);
      p_lookAt->mat[0].x = v199->mat[0].x;
      LODWORD(v251.pitch) = &this->lookAt.mat[2];
      this->lookAt.mat[0].y = v199->mat[0].y;
      this->lookAt.mat[0].z = v199->mat[0].z;
      this->lookAt.mat[1] = v199->mat[1];
      this->lookAt.mat[2] = v199->mat[2];
      goto LABEL_168;
    }
    LODWORD(v251.pitch) = &this->lookAt;
    v185 = p_lookAt->mat[0].x;
    v186 = this->lookAt.mat[0].z;
    v187 = (float)(this->lookAt.mat[0].z * mat3_identity.mat[0].x);
    v188 = (float)(this->lookAt.mat[0].y * mat3_identity.mat[0].z);
    v275[0].z = (float)(this->lookAt.mat[0].y * mat3_identity.mat[0].x)
              - (float)(this->lookAt.mat[0].x * mat3_identity.mat[0].y);
    v275[0].y = (float)((float)v185 * mat3_identity.mat[0].z) - (float)v187;
    v275[0].x = (float)((float)v186 * mat3_identity.mat[0].y) - (float)v188;
    idVec3::NormalizeFast(this: v275);
    v189 = &v279;
    p_y = &mat2_identity.mat[1].y;
    for ( k = 9; k != 0; --k )
      *++v189 = *(_DWORD *)++p_y;
    v192 = idMat3::RotateSelf(this: &v280, axis: v275, angle: (float)((float)v184 * idMath::M_DEG2RAD));
    p_lookAt->mat[0].x = v192->mat[0].x;
    LODWORD(v251.pitch) = &v192->mat[1];
    this->lookAt.mat[0].y = v192->mat[0].y;
    LODWORD(v251.pitch) = &v192->mat[2];
    v193 = v192->mat[0].z;
    LODWORD(v251.pitch) = &this->lookAt.mat[2];
    this->lookAt.mat[0].z = v193;
    this->lookAt.mat[1] = v192->mat[1];
    this->lookAt.mat[2] = v192->mat[2];
    this->lookAt.mat[1].z = 0.0;
    idVec3::NormalizeFast(this: &this->lookAt.mat[1]);
    v173 = this->lookAt.mat[1].y;
    v174 = this->lookAt.mat[0].z;
    v175 = this->lookAt.mat[1].z;
    v176 = (float)(this->lookAt.mat[0].z * this->lookAt.mat[1].y);
    v177 = p_lookAt->mat[0].x;
    v178 = (float)(this->lookAt.mat[1].z * p_lookAt->mat[0].x);
LABEL_166:
    v194 = this->lookAt.mat[0].y;
    LODWORD(v251.pitch) = &this->lookAt.mat[1];
    v195 = v41->x;
    v196 = (float)(v41->x * (float)v194);
    v42->x = (float)((float)v175 * (float)v194) - (float)v176;
    this->lookAt.mat[2].y = (float)((float)v174 * (float)v195) - (float)v178;
    LODWORD(v251.pitch) = &this->lookAt.mat[2];
    this->lookAt.mat[2].z = (float)((float)v177 * (float)v173) - (float)v196;
    v197 = (idMat3 *)idMat3::ToAngles(this: (idMat3 *)v252, result: (idAngles *)&this->lookAt);
    v198 = idAngles::ToMat3(this: (idAngles *)&v281, result: v197);
    p_lookAt->mat[0].x = v198->mat[0].x;
    LODWORD(v251.pitch) = &this->lookAt.mat[2];
    this->lookAt.mat[0].y = v198->mat[0].y;
    this->lookAt.mat[0].z = v198->mat[0].z;
    this->lookAt.mat[1] = v198->mat[1];
    this->lookAt.mat[2] = v198->mat[2];
    goto LABEL_167;
  }
  if ( (*((_BYTE *)this + 5748) & 8) == 0 )
  {
    if ( v29 != nullptr )
    {
      minYaw = 45.0;
      minPitch = 45.0;
      maxYaw = 45.0;
      maxPitch = 45.0;
    }
    else
    {
      minYaw = this->minYaw;
      minPitch = this->minPitch;
      maxYaw = this->maxYaw;
      maxPitch = this->maxPitch;
    }
    v252[0] = maxPitch;
    v252[1] = maxYaw;
    v252[2] = 0.0;
    v131 = idMath::AngleNormalize360(angle: (float)((float)v126 - v259.mat[0].z));
    v132 = v131;
    if ( v131 > 180.0 )
      v132 = (float)((float)v131 - (float)360.0);
    v133 = idMath::AngleNormalize360(angle: (float)(v252[9] - v259.mat[0].y));
    v134 = v133;
    if ( v133 > 180.0 )
      v134 = (float)((float)v133 - (float)360.0);
    v135 = idMath::AngleNormalize360(angle: (float)(v252[8] - v259.mat[0].x));
    if ( v135 > 180.0 )
      v135 = (float)((float)v135 - (float)360.0);
    v252[4] = v135;
    v252[5] = v134;
    v252[6] = v132;
    v256.mat[1].y = -minPitch;
    v256.mat[2].x = -0.0;
    v256.mat[1].z = -minYaw;
    idAngles::Clamp(this: (idAngles *)&v252[4], min: (const idAngles *)&v256.mat[1].y, max: (const idAngles *)v252);
    v256.mat[0].x = v259.mat[0].x + v252[4];
    v256.mat[0].z = v259.mat[0].z + v252[6];
    v256.mat[0].y = v259.mat[0].y + v252[5];
    v136 = idAngles::ToMat3(this: (idAngles *)&v280, result: &v256);
    p_lookAt->mat[0].x = v136->mat[0].x;
    LODWORD(v251.pitch) = &this->lookAt.mat[2];
    this->lookAt.mat[0].y = v136->mat[0].y;
    this->lookAt.mat[0].z = v136->mat[0].z;
    this->lookAt.mat[1] = v136->mat[1];
    this->lookAt.mat[2] = v136->mat[2];
    idMat3::OrthoNormalizeSelf(this: &this->lookAt);
    goto LABEL_168;
  }
  v137 = idMat3::Inverse(this: &v280, result: &v271);
  v138 = idAngles::ToMat3(this: v284, result: (idMat3 *)&v252[8]);
  v139 = idMat3::operator*(this: &v281, result: v138, a: v137);
  p_lookAt->mat[0].x = v139->mat[0].x;
  LODWORD(v251.pitch) = &this->lookAt.mat[2];
  this->lookAt.mat[0].y = v139->mat[0].y;
  this->lookAt.mat[0].z = v139->mat[0].z;
  this->lookAt.mat[1] = v139->mat[1];
  this->lookAt.mat[2] = v139->mat[2];
  v141 = this->lookAt.mat[0].y;
  v142 = this->lookAt.mat[0].z;
  if ( v142 != 0.0 || v141 != 0.0 )
  {
    if ( v142 >= 0.0 )
      v143 = this->minPitch;
    else
      v143 = this->maxPitch;
    v144 = __fabs(v143);
    if ( v141 >= 0.0 )
      v145 = this->maxYaw;
    else
      v145 = this->minYaw;
    *((double *)&v146 + 1) = this->lookAt.mat[0].y;
    *(double *)&v146 = this->lookAt.mat[0].z;
    v147 = __fabs(v145);
    v148 = atan2(v: v146, u: v140);
    v149 = (float)*(double *)&v148;
    *(double *)&v148 = (float)((float)v147 * idMath::M_DEG2RAD);
    v150 = sin(x: v148);
    v151 = (float)*(double *)&v150;
    *(double *)&v150 = (float)((float)v144 * idMath::M_DEG2RAD);
    v152 = sin(x: v150);
    v153 = (float)*(double *)&v152;
    if ( __fabs(v149) == idMath::HALF_PI )
      v149 = (float)((float)v149 - (float)0.000099999997);
    *(double *)&v152 = v149;
    v154 = tan(x: v152);
    *(double *)&v154 = (float)((float)((float)v151 / (float)v153) * (float)*(double *)&v154);
    v155 = atan(x: v154);
    v156 = (float)*(double *)&v155;
    if ( v141 < 0.0 )
    {
      if ( v142 >= 0.0 )
        v156 = (float)((float)*(double *)&v155 + (float)3.1415927);
      else
        v156 = (float)((float)*(double *)&v155 - (float)3.1415927);
    }
    v157 = v156;
    *(double *)&v155 = v156;
    v158 = cos(x: v155);
    v159 = (float)*(double *)&v158;
    *(double *)&v158 = v157;
    v160 = (float)((float)v159 * (float)v151);
    v161 = sin(x: v158);
    *(double *)&v161 = __fsqrts((float)((float)((float)((float)*(double *)&v161 * (float)v153)
                                              * (float)((float)*(double *)&v161 * (float)v153))
                                      + (float)((float)v160 * (float)v160)));
    v162 = idMath::ASin(a: v161);
    *(double *)&v163 = p_lookAt->mat[0].x;
    if ( idMath::ACos(a: v163) <= v162 )
      goto LABEL_167;
    LODWORD(v251.pitch) = &this->lookAt;
    v164 = p_lookAt->mat[0].x;
    v165 = this->lookAt.mat[0].z;
    v166 = (float)(this->lookAt.mat[0].z * mat3_identity.mat[0].x);
    v167 = (float)(this->lookAt.mat[0].y * mat3_identity.mat[0].z);
    v273.z = (float)(this->lookAt.mat[0].y * mat3_identity.mat[0].x)
           - (float)(this->lookAt.mat[0].x * mat3_identity.mat[0].y);
    v273.y = (float)((float)v164 * mat3_identity.mat[0].z) - (float)v166;
    v273.x = (float)((float)v165 * mat3_identity.mat[0].y) - (float)v167;
    idVec3::NormalizeFast(this: &v273);
    v168 = &v279;
    v169 = &mat2_identity.mat[1].y;
    for ( m = 9; m != 0; --m )
      *++v168 = *(_DWORD *)++v169;
    v171 = idMat3::RotateSelf(this: &v280, axis: &v273, angle: v162);
    p_lookAt->mat[0].x = v171->mat[0].x;
    LODWORD(v251.pitch) = &this->lookAt.mat[1];
    v172 = v171->mat[0].y;
    LODWORD(v251.pitch) = &v171->mat[1];
    this->lookAt.mat[0].y = v172;
    this->lookAt.mat[0].z = v171->mat[0].z;
    LODWORD(v251.pitch) = &this->lookAt.mat[2];
    this->lookAt.mat[1] = v171->mat[1];
    this->lookAt.mat[2] = v171->mat[2];
    this->lookAt.mat[1].z = 0.0;
    idVec3::NormalizeFast(this: &this->lookAt.mat[1]);
    v173 = this->lookAt.mat[1].y;
    v174 = this->lookAt.mat[0].z;
    v175 = this->lookAt.mat[1].z;
    v176 = (float)(this->lookAt.mat[1].y * this->lookAt.mat[0].z);
    v177 = p_lookAt->mat[0].x;
    v178 = (float)(p_lookAt->mat[0].x * this->lookAt.mat[1].z);
    goto LABEL_166;
  }
LABEL_168:
  idPLogScope::~idPLogScope(this: &v255);
  RD_EventEnd();
_M499638:
  v200 = this->presentable;
  if ( v200 == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    v200 = this->presentable;
  }
  if ( !v200->model->useDeferredPosition )
  {
    this->prevLookAt.mat[0].x = p_lookAt->mat[0].x;
    LODWORD(v251.pitch) = &this->lookAt;
    v201 = this->lookAt.mat[0].y;
    LODWORD(v251.pitch) = &this->lookAt.mat[1];
    this->prevLookAt.mat[0].y = v201;
    this->prevLookAt.mat[0].z = this->lookAt.mat[0].z;
    LODWORD(v251.pitch) = &this->prevLookAt.mat[2];
    this->prevLookAt.mat[1].x = v41->x;
    this->prevLookAt.mat[1].y = this->lookAt.mat[1].y;
    this->prevLookAt.mat[1].z = this->lookAt.mat[1].z;
    this->prevLookAt.mat[2].x = v42->x;
    this->prevLookAt.mat[2].y = this->lookAt.mat[2].y;
    this->prevLookAt.mat[2].z = this->lookAt.mat[2].z;
  }
  v202 = (float *)this->presentable;
  if ( v202 == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    v202 = (float *)this->presentable;
  }
  v203 = v202[41];
  v204 = v202[38];
  v205 = v202[35];
  v206 = v202[40];
  v207 = v202[37];
  LODWORD(v251.pitch) = v202 + 33;
  v208 = v202[34];
  v209 = v202[39];
  v210 = v202[36];
  v211 = v202[33];
  v271.mat[2].z = v203;
  v271.mat[2].y = v204;
  v271.mat[2].x = v205;
  v271.mat[1].z = v206;
  v271.mat[1].y = v207;
  v271.mat[1].x = v208;
  v271.mat[0].z = v209;
  v271.mat[0].y = v210;
  v271.mat[0].x = v211;
  idMat3::operator*(this: &v283, result: &this->lookAt, a: &v271);
  idAnimator_JointMod::SetJointMod(
    this: &this->jointModAnimator,
    index: (idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)this->jointPitch.value,
    value: &v283,
    a4: v216,
    a5: v215,
    a6: v214,
    a7: v213,
    a8: v212,
    a9: v239,
    a10: v241,
    a11: v243,
    a12: v245,
    a13: v247,
    a14: v249);
  if ( this->jointYaw.value != this->jointPitch.value )
  {
    idMat3::ToAngles(this: (idMat3 *)v252, result: (idAngles *)&v283);
    v252[0] = 0.0;
    v217 = idAngles::ToMat3(this: (idAngles *)&v281, result: (idMat3 *)v252);
    idAnimator_JointMod::SetJointMod(
      this: &this->jointModAnimator,
      index: (idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)this->jointYaw.value,
      value: v217,
      a4: v222,
      a5: v221,
      a6: v220,
      a7: v219,
      a8: v218,
      a9: v240,
      a10: v242,
      a11: v244,
      a12: v246,
      a13: v248,
      a14: v250);
  }
  RD_EventBegin(name: "idProp_WeaponStatic::Think - Updates");
  LODWORD(v223) = "idProp_WeaponStatic::Think - Updates";
  HIDWORD(v223) = 2;
  idPLogScope::idPLogScope(this: &v255, pl: v253, gMask: v223, label: v224);
  idAnimatedEntity::UpdateFrameCommands(this);
  idAnimatedEntity::UpdateAnimation(this, forceNonDeferredBlend: false);
  idProp_WeaponStatic::UpdateArmourPieces(this);
  idEntity::RunPhysics(this);
  this->UpdateFX(this);
  idAnimatedEntity::UpdateDamageEffects(this);
  idPLogScope::~idPLogScope(this: &v255);
  RD_EventEnd();
  if ( this->clipModelInfo.type == CLIPMODEL_CUSTOM )
  {
    idAngles::ToMat3(this: (idAngles *)&v259.mat[2].z, result: &v256);
    v252[5] = v266;
    v252[4] = v265;
    v252[6] = v267;
    v265 = v262;
    v266 = v263;
    v267 = v264;
    v262 = -v259.mat[2].z;
    v264 = -v261;
    v263 = -v260;
    v225 = (float)(v276.mat[0].y * this->clipForwardAmount);
    v226 = (float)(v276.mat[0].x * this->clipForwardAmount);
    v227 = (float)(v259.mat[2].x + (float)(v276.mat[0].z * this->clipForwardAmount));
    v261 = v252[6];
    v259.mat[2].z = v252[4];
    v260 = v252[5];
    v252[2] = v227;
    v252[1] = v259.mat[1].z + (float)v225;
    v252[0] = v259.mat[1].y + (float)v226;
    v228 = idEntity::GetPhysics(this);
    v229 = v228->GetClipModel(this: v228, a2: 0);
    idClipModel::SetLinkedPosition(this: v229, newOrigin: (const idVec3 *)v252, newAxis: (idMat3 *)&v259.mat[2].z);
  }
  v230 = this->presentable;
  if ( v230 == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    v230 = this->presentable;
  }
  v231 = (int)v230->GetWeaponStaticInterface(this: v230);
  v232 = 0;
  if ( v231 != 0 )
    v232 = *(_BYTE *)(v231 + 1320);
  if ( v46 != 0 )
  {
    this->Use(this, a2: nullptr, a3: USABLE_MAX);
    this->turning = 0;
    if ( v28 != nullptr && v28->GetVehicle_2(this: v28) != nullptr )
    {
      this->coolDownTime = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED)
                         + 5000;
      idProp_Usable::SetUsable(this, b: false);
    }
  }
  else if ( v232 != 0 || v115 == 0 )
  {
    if ( this->shooting )
    {
      idProp_WeaponStatic::ReleaseTrigger(this);
      if ( v29 != nullptr )
        v29->aiVolatile.memory.nextBurstTime = idGameTimeManager::GetGameMs(
                                                 this: &clientGame->gameTimeManager,
                                                 type: GAMETIME_SCALED)
                                             + 500;
    }
  }
  else
  {
    if ( !this->shooting )
      idProp_WeaponStatic::PullTrigger(this);
    idProp_WeaponStatic::HoldTrigger(this, primary: v49, secondary: v50);
  }
  v233 = this->turning;
  if ( v233 != 0 && (v234 = this->sndTurning) != nullptr )
  {
    if ( v233 == 1 )
      idEntity::StartSoundShader(
        this,
        channel: SND_CHANNEL_STEERING,
        shader: v234,
        soundShaderFlags: (soundShaderFlags_t)0,
        peerMask: 0xFFu);
    sndTurning = this->sndTurning;
    v251.pitch = v116;
    max = (float)((float)((float)__fsqrts(v116) * (float)5.0) - (float)40.0);
    if ( max >= sndTurning->parms.volume.min )
    {
      if ( max > sndTurning->parms.volume.max )
        max = sndTurning->parms.volume.max;
      idEntity::SetSoundVolume(this, channel: SND_CHANNEL_STEERING, volume: max);
    }
    else
    {
      idEntity::SetSoundVolume(this, channel: SND_CHANNEL_STEERING, volume: sndTurning->parms.volume.min);
    }
  }
  else if ( idEntity::IsPlayingSound(this, channel: SND_CHANNEL_STEERING) )
  {
    idEntity::StopSound(this, channel: SND_CHANNEL_STEERING, peerMask: 0xFFu);
  }
  idProp_WeaponStatic::HandleHeat(this, isPlayer: v47);
  idProp_WeaponStatic::CheckAttachments(this);
  v237 = idEntity::GetPhysics(this);
  v238 = (idBounds *)v237->GetAbsBounds(this: v237, a2: -1);
  idEntity::UpdatePVSAreas(this, bounds: v238);
  idPLogScope::~idPLogScope(this: &v254);
LABEL_207:
  RD_EventEnd();
}


// ========================================================================
// __unwind$497704
// EA  : 0x82D55C98
// RVA : 0x00D55C98
// PDB : w:\tech5\tungsten\game\entities\weaponstatic.cpp
// ========================================================================

void _unwind_497704()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 3584 + 3332));
}


// ========================================================================
// __unwind$497705
// EA  : 0x82D55CC0
// RVA : 0x00D55CC0
// PDB : w:\tech5\tungsten\game\entities\weaponstatic.cpp
// ========================================================================

void _unwind_497705()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 3584 + 144));
}


// ========================================================================
// __unwind$497706
// EA  : 0x82D55CE8
// RVA : 0x00D55CE8
// PDB : w:\tech5\tungsten\game\entities\weaponstatic.cpp
// ========================================================================

void _unwind_497706()
{
  int v0; // r12

  idFireParms::~idFireParms(this: (idAI2::idAIVolatile::idAIEventInfo *)(v0 - 3584 + 864));
}


// ========================================================================
// __unwind$497707
// EA  : 0x82D55D10
// RVA : 0x00D55D10
// PDB : w:\tech5\tungsten\game\entities\weaponstatic.cpp
// ========================================================================

void _unwind_497707()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 3584 + 3333));
}


// ========================================================================
// __unwind$497708
// EA  : 0x82D55D38
// RVA : 0x00D55D38
// PDB : w:\tech5\tungsten\game\entities\weaponstatic.cpp
// ========================================================================

void _unwind_497708()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 3584 + 152));
}


// ========================================================================
// __unwind$497709
// EA  : 0x82D55D60
// RVA : 0x00D55D60
// PDB : w:\tech5\tungsten\game\entities\weaponstatic.cpp
// ========================================================================

void _unwind_497709()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 3584 + 3334));
}


// ========================================================================
// __unwind$497710
// EA  : 0x82D55D88
// RVA : 0x00D55D88
// PDB : w:\tech5\tungsten\game\entities\weaponstatic.cpp
// ========================================================================

void _unwind_497710()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 3584 + 152));
}


// ========================================================================
// __unwind$497711
// EA  : 0x82D55DB0
// RVA : 0x00D55DB0
// PDB : w:\tech5\tungsten\game\entities\weaponstatic.cpp
// ========================================================================

void _unwind_497711()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 3584 + 3335));
}


// ========================================================================
// __unwind$497712
// EA  : 0x82D55DD8
// RVA : 0x00D55DD8
// PDB : w:\tech5\tungsten\game\entities\weaponstatic.cpp
// ========================================================================

void _unwind_497712()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 3584 + 152));
}


// ========================================================================
// `dynamic initializer for 's_turretTurnScale''
// EA  : 0x83380050
// RVA : 0x01380050
// PDB : w:\tech5\tungsten\game\entities\weaponstatic.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__s_turretTurnScale__()
{
  idCVar::idCVar(
    this: &s_turretTurnScale,
    name: "s_turretTurnScale",
    value: "0.4",
    flags: 4,
    description: "adjusts the player turn speed of emplaced turret",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__s_turretTurnScale__);
}


// ========================================================================
// `dynamic initializer for 's_turretDebugMuzzle''
// EA  : 0x833800A8
// RVA : 0x013800A8
// PDB : w:\tech5\tungsten\game\entities\weaponstatic.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__s_turretDebugMuzzle__()
{
  idCVar::idCVar(
    this: &s_turretDebugMuzzle,
    name: "s_turretDebugMuzzle",
    value: "0",
    flags: 1,
    description: "makes the weapon statics always fire",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__s_turretDebugMuzzle__);
}

