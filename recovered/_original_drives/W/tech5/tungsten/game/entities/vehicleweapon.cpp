
// ========================================================================
// ?GetAnimInfo@idVehicleWeapon@@QAAABUanimInfo_t@1@XZ
// EA  : 0x82D37DD0
// RVA : 0x00D37DD0
// PDB : w:\tech5\tungsten\game\entities\vehicleweapon.cpp
// ========================================================================

const idVehicleWeapon::animInfo_t *__fastcall idVehicleWeapon::GetAnimInfo(idVehicleWeapon *this)
{
  idVehicleWeapon *dependentWeapon; // r11
  idVehicleWeapon *v2; // r10

  dependentWeapon = this->dependentWeapon;
  if ( dependentWeapon == nullptr )
    return &this->animState;
  do
  {
    v2 = dependentWeapon;
    dependentWeapon = dependentWeapon->dependentWeapon;
  }
  while ( dependentWeapon != nullptr );
  return &v2->animState;
}


// ========================================================================
// ?ClearAnimQueue@idVehicleWeapon@@QAAXXZ
// EA  : 0x82D37E00
// RVA : 0x00D37E00
// PDB : w:\tech5\tungsten\game\entities\vehicleweapon.cpp
// ========================================================================

void __fastcall idVehicleWeapon::ClearAnimQueue(idVehicleWeapon *this)
{
  this->animCount = 0;
}


// ========================================================================
// ?IsReadyToFire@idVehicleWeapon@@QAA_NXZ
// EA  : 0x82D37E10
// RVA : 0x00D37E10
// PDB : w:\tech5\tungsten\game\entities\vehicleweapon.cpp
// ========================================================================

int __fastcall idVehicleWeapon::IsReadyToFire(idVehicleWeapon *this)
{
  idVehicleWeapon *dependentWeapon; // r11
  vehicleWeaponAnimState_t state; // r11
  int result; // r3

  dependentWeapon = this->dependentWeapon;
  if ( dependentWeapon == nullptr )
    dependentWeapon = this;
  state = dependentWeapon->animState.state;
  if ( state == VW_ANIM_IDLE )
    return 1;
  if ( state == VW_ANIM_MANNED_IDLE )
    return 1;
  result = 0;
  if ( state == VW_ANIM_NONE )
    return 1;
  return result;
}


// ========================================================================
// ?GetCurrentAnimState@idVehicleWeapon@@QAA?AW4vehicleWeaponAnimState_t@@XZ
// EA  : 0x82D37E48
// RVA : 0x00D37E48
// PDB : w:\tech5\tungsten\game\entities\vehicleweapon.cpp
// ========================================================================

vehicleWeaponAnimState_t __fastcall idVehicleWeapon::GetCurrentAnimState(idVehicleWeapon *this)
{
  idVehicleWeapon *dependentWeapon; // r11
  idVehicleWeapon *v2; // r10

  dependentWeapon = this->dependentWeapon;
  if ( dependentWeapon == nullptr )
    return this->animState.state;
  do
  {
    v2 = dependentWeapon;
    dependentWeapon = dependentWeapon->dependentWeapon;
  }
  while ( dependentWeapon != nullptr );
  return v2->animState.state;
}


// ========================================================================
// ??1idVehicleWeapon@@UAA@XZ
// EA  : 0x82D37EA0
// RVA : 0x00D37EA0
// PDB : w:\tech5\tungsten\game\entities\vehicleweapon.cpp
// ========================================================================

void __fastcall idVehicleWeapon::~idVehicleWeapon(idVehicleWeapon *this)
{
  idVehicle *vehicle; // r3
  idAttachmentCollection *v3; // r3
  idWeapon *weapon; // r3

  this->__vftable = (idVehicleWeapon_vtbl *)&idVehicleWeapon::`vftable';
  vehicle = this->vehicle;
  if ( vehicle != nullptr )
  {
    v3 = vehicle->GetAttachments_2(this: vehicle);
    if ( v3 != nullptr && this->attachHandle.value != -1 )
      idAttachmentCollection::RemoveAttachment(this: v3, handle: &this->attachHandle);
  }
  weapon = this->weapon;
  if ( weapon != nullptr )
    ((void (__fastcall *)(idWeapon *, int))weapon->dtr_idClass)(a1: weapon, a2: 1);
  idLaserSight::~idLaserSight(this: &this->laserSight);
  this->__vftable = (idVehicleWeapon_vtbl *)&idClass::`vftable';
}


// ========================================================================
// __unwind$489516
// EA  : 0x82D37F50
// RVA : 0x00D37F50
// PDB : w:\tech5\tungsten\game\entities\vehicleweapon.cpp
// ========================================================================

void _unwind_489516()
{
  int v0; // r12

  idAIEvent::~idAIEvent(this: *(idAimAssist **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$489517
// EA  : 0x82D37F78
// RVA : 0x00D37F78
// PDB : w:\tech5\tungsten\game\entities\vehicleweapon.cpp
// ========================================================================

void _unwind_489517()
{
  int v0; // r12

  idLaserSight::~idLaserSight(this: (idLaserSight *)(*(_DWORD *)(v0 - 112 + 132) + 456));
}


// ========================================================================
// ?GetDeclVehicleWeapon@idVehicleWeapon@@QBAPBVidDeclVehicleWeapon@@XZ
// EA  : 0x82D37FA8
// RVA : 0x00D37FA8
// PDB : w:\tech5\tungsten\game\entities\vehicleweapon.cpp
// ========================================================================

const idDeclVehicleWeapon *__fastcall idVehicleWeapon::GetDeclVehicleWeapon(idVehicleWeapon *this)
{
  idWeapon *weapon; // r11
  const idDeclVehicleWeapon *result; // r3

  weapon = this->weapon;
  if ( weapon == nullptr )
    return nullptr;
  result = (const idDeclVehicleWeapon *)weapon->decl;
  if ( result == nullptr )
    return nullptr;
  return result;
}


// ========================================================================
// ?PullTrigger@idVehicleWeapon@@QAAXXZ
// EA  : 0x82D37FC8
// RVA : 0x00D37FC8
// PDB : w:\tech5\tungsten\game\entities\vehicleweapon.cpp
// ========================================================================

void __fastcall idVehicleWeapon::PullTrigger(idVehicleWeapon *this)
{
  idWeapon *weapon; // r11
  int nextFireTime; // r28
  int GameMs; // r28
  int v5; // r3
  idWeapon *v6; // r11

  weapon = this->weapon;
  if ( weapon->triggerState == TRIGGERSTATE_RELEASED )
  {
    if ( *(int *)&weapon->decl[1].inventoryClass.baseBuffer[16] > 0 )
    {
      nextFireTime = weapon->nextFireTime;
      if ( nextFireTime < idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) )
      {
        GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        this->weapon->nextFireTime = idRandom2::RandomInt(
                                       this: &clientGame->random,
                                       max: *(_DWORD *)&this->weapon->decl[1].inventoryClass.baseBuffer[16])
                                   + GameMs;
      }
    }
    this->weapon->PullTrigger(this: this->weapon, a2: nullptr, a3: false);
    v5 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    v6 = this->weapon;
    if ( v5 >= v6->nextFireTime )
      v6->triggerState = TRIGGERSTATE_PULLED;
  }
}


// ========================================================================
// ?ReleaseTrigger@idVehicleWeapon@@QAAXXZ
// EA  : 0x82D380A8
// RVA : 0x00D380A8
// PDB : w:\tech5\tungsten\game\entities\vehicleweapon.cpp
// ========================================================================

void __fastcall idVehicleWeapon::ReleaseTrigger(idVehicleWeapon *this)
{
  idWeapon *weapon; // r11

  weapon = this->weapon;
  if ( weapon->triggerState == TRIGGERSTATE_PULLED )
  {
    this->sequenceFired = 0;
    weapon->ReleaseTrigger(this: weapon, a2: nullptr);
  }
}


// ========================================================================
// ?GetAmmoCount@idVehicleWeapon@@QAAHXZ
// EA  : 0x82D380D8
// RVA : 0x00D380D8
// PDB : w:\tech5\tungsten\game\entities\vehicleweapon.cpp
// ========================================================================

int __fastcall idVehicleWeapon::GetAmmoCount(idVehicleWeapon *this)
{
  idPresentableVehicle *presentableVehicleCar; // r3
  const idDeclInventory *decl; // r31
  idJobManager *v4; // r3
  idJob *JobByDecl; // r3

  if ( (int)this->weapon->decl[1].declSource <= 0 )
    return 0;
  if ( (unsigned __int8)idPresentableVehicle::GetHasInfiniteAmmo(this: this->presentableVehicleCar) != 0 )
    return 0;
  presentableVehicleCar = this->presentableVehicleCar;
  decl = this->weapon->ammoClip->decl;
  v4 = (idJobManager *)presentableVehicleCar->GetInventory(this: &presentableVehicleCar->idPresentableAnimatedEntity);
  JobByDecl = idJobManager::FindJobByDecl(this: v4, jobDecl: (const idDeclJob *)decl);
  if ( JobByDecl == nullptr )
    return 0;
  else
    return ((int (__fastcall *)(idJob *))JobByDecl->__vftable[2].dtr_idClass)(a1: JobByDecl);
}


// ========================================================================
// ?IsActive@idVehicleWeapon@@QAA_NXZ
// EA  : 0x82D38180
// RVA : 0x00D38180
// PDB : w:\tech5\tungsten\game\entities\vehicleweapon.cpp
// ========================================================================

BOOL __fastcall idVehicleWeapon::IsActive(idVehicleWeapon *this)
{
  idWeapon *weapon; // r11
  const idDeclInventory *decl; // r31

  weapon = this->weapon;
  if ( weapon == nullptr || (decl = weapon->decl) == nullptr )
    decl = nullptr;
  return (_cntlzw(
            idPresentableVehicle::GetCurrentWeaponGroup(this: this->presentableVehicleCar)
          - (unsigned int)decl[1].parent)
        & 0x20) != 0;
}


// ========================================================================
// ?GetAngleLimits@idVehicleWeapon@@QAAXAAVidAngles@@0@Z
// EA  : 0x82D381E0
// RVA : 0x00D381E0
// PDB : w:\tech5\tungsten\game\entities\vehicleweapon.cpp
// ========================================================================

void __fastcall idVehicleWeapon::GetAngleLimits(idVehicleWeapon *this, idAngles *minAngles, idAngles *maxAngles)
{
  idWeapon *weapon; // r11
  float *decl; // r11
  double v5; // fp12
  idWeapon *v6; // r11
  float *v7; // r11
  double v8; // fp11

  weapon = this->weapon;
  if ( weapon == nullptr || (decl = (float *)weapon->decl) == nullptr )
    decl = nullptr;
  minAngles->pitch = decl[619];
  v5 = decl[620];
  minAngles->yaw = decl[620];
  minAngles->roll = decl[621];
  if ( v5 == 360.0 )
    minAngles->yaw = -g_fov.valueFloat;
  v6 = this->weapon;
  if ( v6 == nullptr || (v7 = (float *)v6->decl) == nullptr )
    v7 = nullptr;
  maxAngles->pitch = v7[622];
  v8 = v7[623];
  maxAngles->yaw = v7[623];
  maxAngles->roll = v7[624];
  if ( v8 == 360.0 )
    maxAngles->yaw = g_fov.valueFloat;
}


// ========================================================================
// ?GetAngleWeaponLimits@idVehicleWeapon@@QAAXAAVidAngles@@0@Z
// EA  : 0x82D38288
// RVA : 0x00D38288
// PDB : w:\tech5\tungsten\game\entities\vehicleweapon.cpp
// ========================================================================

void __fastcall idVehicleWeapon::GetAngleWeaponLimits(idVehicleWeapon *this, idAngles *minAngles, idAngles *maxAngles)
{
  idWeapon *weapon; // r11
  float *decl; // r11
  double v5; // fp12
  idWeapon *v6; // r11
  float *v7; // r11
  double v8; // fp11

  weapon = this->weapon;
  if ( weapon == nullptr || (decl = (float *)weapon->decl) == nullptr )
    decl = nullptr;
  minAngles->pitch = decl[625];
  v5 = decl[626];
  minAngles->yaw = decl[626];
  minAngles->roll = decl[627];
  if ( v5 == 360.0 )
    minAngles->yaw = -g_fov.valueFloat;
  v6 = this->weapon;
  if ( v6 == nullptr || (v7 = (float *)v6->decl) == nullptr )
    v7 = nullptr;
  maxAngles->pitch = v7[628];
  v8 = v7[629];
  maxAngles->yaw = v7[629];
  maxAngles->roll = v7[630];
  if ( v8 == 360.0 )
    maxAngles->yaw = g_fov.valueFloat;
}


// ========================================================================
// ?GetAiAngleLimits@idVehicleWeapon@@QAAXAAVidAngles@@0@Z
// EA  : 0x82D38330
// RVA : 0x00D38330
// PDB : w:\tech5\tungsten\game\entities\vehicleweapon.cpp
// ========================================================================

void __fastcall idVehicleWeapon::GetAiAngleLimits(idVehicleWeapon *this, idAngles *minAngles, idAngles *maxAngles)
{
  idWeapon *weapon; // r11
  float *decl; // r11
  double v5; // fp12
  idWeapon *v6; // r11
  float *v7; // r11
  double v8; // fp11

  weapon = this->weapon;
  if ( weapon == nullptr || (decl = (float *)weapon->decl) == nullptr )
    decl = nullptr;
  minAngles->pitch = decl[631];
  v5 = decl[632];
  minAngles->yaw = decl[632];
  minAngles->roll = decl[633];
  if ( v5 == 360.0 )
    minAngles->yaw = -g_fov.valueFloat;
  v6 = this->weapon;
  if ( v6 == nullptr || (v7 = (float *)v6->decl) == nullptr )
    v7 = nullptr;
  maxAngles->pitch = v7[634];
  v8 = v7[635];
  maxAngles->yaw = v7[635];
  maxAngles->roll = v7[636];
  if ( v8 == 360.0 )
    maxAngles->yaw = g_fov.valueFloat;
}


// ========================================================================
// ?PlayAnim@idVehicleWeapon@@QAA_NABUanimInfo_t@1@@Z
// EA  : 0x82D383D8
// RVA : 0x00D383D8
// PDB : w:\tech5\tungsten\game\entities\vehicleweapon.cpp
// ========================================================================

int __fastcall idVehicleWeapon::PlayAnim(idVehicleWeapon *this, const idVehicleWeapon::animInfo_t *animInfo)
{
  int animCount; // r11
  int v6; // r11
  idVehicleWeapon::animInfo_t *v7; // r8

  if ( animInfo->aliasHandle.value == 0xFFFF )
    return 0;
  animCount = this->animCount;
  if ( animCount > 0 && *((_DWORD *)&this->spinupFire + 2 * animCount) == animInfo->state )
    return 1;
  if ( animCount >= 4 )
    return 0;
  if ( vehicle_weapon_anim_debug.valueInteger != 0 )
    idLib::Printf(fmt: "Play: %s\n", vehicle_weapon_anim_names.ptr[animInfo->state]);
  v6 = this->animCount;
  this->animCount = v6 + 1;
  v7 = &this->animQueue.ptr[v6];
  v7->state = animInfo->state;
  *(_DWORD *)&v7->aliasHandle.value = *(_DWORD *)&animInfo->aliasHandle.value;
  return 1;
}


// ========================================================================
// ?IsMannedWeaponChange@idVehicleWeapon@@QAA_NXZ
// EA  : 0x82D384B8
// RVA : 0x00D384B8
// PDB : w:\tech5\tungsten\game\entities\vehicleweapon.cpp
// ========================================================================

int __fastcall idVehicleWeapon::IsMannedWeaponChange(idVehicleWeapon *this)
{
  idVehicleWeapon *dependentWeapon; // r8
  idVehicleWeapon *v2; // r9
  vehicleWeaponAnimState_t CurrentAnimState; // r3
  __int32 v4; // r3
  int animCount; // r8
  int v6; // r10
  idArray<idVehicleWeapon::animInfo_t,4> *i; // r11

  dependentWeapon = this->dependentWeapon;
  v2 = this;
  if ( dependentWeapon != nullptr )
    CurrentAnimState = idVehicleWeapon::GetCurrentAnimState(this: this->dependentWeapon);
  else
    CurrentAnimState = this->animState.state;
  if ( CurrentAnimState != VW_ANIM_MANNED_ENTRY )
  {
    v4 = dependentWeapon != nullptr ? idVehicleWeapon::GetCurrentAnimState(this: dependentWeapon) : v2->animState.state;
    if ( v4 != 6 )
    {
      animCount = v2->animCount;
      v6 = 0;
      if ( animCount <= 0 )
        return 0;
      for ( i = &v2->animQueue;
            i->ptr[0].state != VW_ANIM_MANNED_ENTRY && i->ptr[0].state != VW_ANIM_MANNED_EXIT;
            i = (idArray<idVehicleWeapon::animInfo_t,4> *)((char *)i + 8) )
      {
        if ( ++v6 >= animCount )
          return 0;
      }
    }
  }
  return 1;
}


// ========================================================================
// ?IsWeaponChange@idVehicleWeapon@@QAA_NXZ
// EA  : 0x82D38570
// RVA : 0x00D38570
// PDB : w:\tech5\tungsten\game\entities\vehicleweapon.cpp
// ========================================================================

int __fastcall idVehicleWeapon::IsWeaponChange(idVehicleWeapon *this)
{
  idVehicleWeapon *v1; // r9
  idVehicleWeapon *dependentWeapon; // r3
  vehicleWeaponAnimState_t CurrentAnimState; // r3
  int animCount; // r8
  int v6; // r10
  int *i; // r11

  v1 = this;
  dependentWeapon = this->dependentWeapon;
  if ( dependentWeapon != nullptr )
    CurrentAnimState = idVehicleWeapon::GetCurrentAnimState(this: dependentWeapon);
  else
    CurrentAnimState = v1->animState.state;
  if ( CurrentAnimState >= VW_FIRST_WEAPON_CHANGE_ANIM && CurrentAnimState <= VW_LAST_WEAPON_CHANGE_ANIM )
    return 1;
  animCount = v1->animCount;
  v6 = 0;
  if ( animCount > 0 )
  {
    for ( i = (int *)&v1->animQueue; *i < 2 || *i > 9; i += 2 )
    {
      if ( ++v6 >= animCount )
        return 0;
    }
    return 1;
  }
  return 0;
}


// ========================================================================
// ?InitLaserSight@idVehicleWeapon@@QAAXXZ
// EA  : 0x82D38608
// RVA : 0x00D38608
// PDB : w:\tech5\tungsten\game\entities\vehicleweapon.cpp
// ========================================================================

void __fastcall idVehicleWeapon::InitLaserSight(idVehicleWeapon *this)
{
  idWeapon *weapon; // r11
  const idDeclInventory *decl; // r11
  char list_high; // r29
  idLaserSight *p_laserSight; // r31
  double v5; // fp31
  const idMaterial *handsModelMD6Alt; // r28
  double v7; // fp30
  const idMaterial *handsModelMD6; // r27
  double v9; // fp29
  double v10; // fp28
  double v11; // fp27
  idRenderModelDecal *Flags; // r30
  idRenderModelBeam *NumContacts; // r3
  int v14; // r10
  int v15; // r9
  const idMaterial *v16; // r7
  int v17; // [sp+8h] [-B8h]
  int v18; // [sp+Ch] [-B4h]
  int v19; // [sp+10h] [-B0h]
  int v20; // [sp+14h] [-ACh]
  int v21; // [sp+18h] [-A8h]
  int v22; // [sp+1Ch] [-A4h]
  int v23; // [sp+20h] [-A0h]
  int v24; // [sp+24h] [-9Ch]
  int v25; // [sp+28h] [-98h]
  int v26; // [sp+2Ch] [-94h]
  int v27; // [sp+30h] [-90h]
  int v28; // [sp+34h] [-8Ch]
  int v29; // [sp+38h] [-88h]
  int v30; // [sp+3Ch] [-84h]
  int v31; // [sp+40h] [-80h]
  int v32; // [sp+44h] [-7Ch]
  int v33; // [sp+48h] [-78h]
  int v34; // [sp+4Ch] [-74h]
  int v35; // [sp+50h] [-70h]
  int v36; // [sp+54h] [-6Ch]
  int v37; // [sp+58h] [-68h]
  int v38; // [sp+5Ch] [-64h]
  int v39; // [sp+60h] [-60h]

  weapon = this->weapon;
  if ( weapon != nullptr )
  {
    decl = weapon->decl;
    if ( decl != nullptr && BYTE1(decl[4].itemUse) == 1 )
    {
      list_high = HIBYTE(decl[3].childItem.list);
      p_laserSight = &this->laserSight;
      v5 = *(float *)&decl[3].childItem.size;
      handsModelMD6Alt = (const idMaterial *)decl[3].handsModelMD6Alt;
      v7 = *(float *)&decl[3].childItem.num;
      handsModelMD6 = (const idMaterial *)decl[3].handsModelMD6;
      v9 = *(float *)&decl[3].thirdPersonStatic;
      v10 = *(float *)&decl[3].dualWieldItemDecl;
      v11 = *(float *)&decl[3].thirdPersonMD6;
      Flags = idParser::GetFlags(this: clientGame);
      NumContacts = (idRenderModelBeam *)idPhysics_DynamicBase::GetNumContacts(this: (idAnimator_ChannelWeight *)clientGame);
      idLaserSight::Init(
        this: p_laserSight,
        _beamEffects: NumContacts,
        _decalEffects: Flags,
        laserBeamMtr: handsModelMD6,
        laserBeamHeight: v11,
        laserPointMtr: v16,
        laserPointSize: v10,
        laserPointDepth: v9,
        fadeIn: v7,
        fadeOut: v5,
        isQuad: handsModelMD6Alt,
        a12: v15,
        a13: v14,
        a14: v17,
        a15: v18,
        a16: v19,
        a17: v20,
        a18: v21,
        a19: v22,
        a20: v23,
        a21: v24,
        a22: v25,
        a23: v26,
        a24: v27,
        a25: v28,
        a26: v29,
        a27: v30,
        a28: v31,
        a29: v32,
        a30: v33,
        a31: v34,
        a32: v35,
        a33: v36,
        a34: v37,
        a35: v38,
        a36: v39,
        a37: list_high);
      idLaserSight::Hide(this: p_laserSight);
    }
  }
}


// ========================================================================
// ?DisableLaserSight@idVehicleWeapon@@QAAXXZ
// EA  : 0x82D386C8
// RVA : 0x00D386C8
// PDB : w:\tech5\tungsten\game\entities\vehicleweapon.cpp
// ========================================================================

void __fastcall idVehicleWeapon::DisableLaserSight(idVehicleWeapon *this)
{
  idWeapon *weapon; // r11
  const idDeclInventory *decl; // r11

  weapon = this->weapon;
  if ( weapon == nullptr || (decl = weapon->decl) == nullptr )
    decl = nullptr;
  if ( BYTE1(decl[4].itemUse) == 1 )
    idLaserSight::Hide(this: &this->laserSight);
}


// ========================================================================
// ?HasInfiniteAmmo@idVehicleWeapon@@QBA_NXZ
// EA  : 0x82D38700
// RVA : 0x00D38700
// PDB : w:\tech5\tungsten\game\entities\vehicleweapon.cpp
// ========================================================================

int __fastcall idVehicleWeapon::HasInfiniteAmmo(idVehicleWeapon *this)
{
  idWeapon *weapon; // r11
  const idDeclInventory *decl; // r11

  weapon = this->weapon;
  if ( weapon != nullptr && (decl = weapon->decl) != nullptr )
    return HIBYTE(decl[1].textLength);
  else
    return MEMORY[0x220];
}


// ========================================================================
// ?InitVars@idVehicleWeapon@@QAAXXZ
// EA  : 0x82D38790
// RVA : 0x00D38790
// PDB : w:\tech5\tungsten\game\entities\vehicleweapon.cpp
// ========================================================================

void __fastcall idVehicleWeapon::InitVars(idVehicleWeapon *this)
{
  this->presentableVehicleCar = nullptr;
  this->vehicle = nullptr;
  this->treeAnimator = nullptr;
  this->weapon = nullptr;
  this->dependentWeapon = nullptr;
  this->targetAxis = mat3_identity;
  this->jointOrigin = vec3_origin;
  this->jointMat = mat3_identity;
  this->spinJointOrigin = vec3_origin;
  this->spinJointMat = mat3_identity;
  this->lastTargetPos = vec3_origin;
  this->lastWeaponAxis = mat3_identity;
  this->targetAngles = ang_zero;
  this->animCount = 0;
  this->spinupFire = false;
  this->launchDelayTime = 0;
  this->rollDelta = 0.0;
  this->firingTime = 0;
  this->rollAngle = 0.0;
  this->sequenceFired = 0;
  this->maxRollSpeed = 40.0;
  this->presentable.spawnId = 0;
  this->lastPresentable.spawnId = 0;
  this->fireSoundChannel = SND_CHANNEL_WEAPON_1;
  this->yawLockedToVehicle = true;
  this->remoteFireWeapon = nullptr;
  this->remoteFireTime = 0;
  this->remoteFireAttacker.spawnId = 0;
  this->remoteFireLockedOn = false;
  this->remoteFireTarget.spawnId = 0;
  this->remoteFireDamageScale = 1.0;
  this->remoteFireAddSpread = 0.0;
  this->remoteFireInfiniteAmmo = false;
  this->hasClearShot = false;
}


// ========================================================================
// ?Hide@idVehicleWeapon@@QAAXXZ
// EA  : 0x82D389D0
// RVA : 0x00D389D0
// PDB : w:\tech5\tungsten\game\entities\vehicleweapon.cpp
// ========================================================================

void __fastcall idVehicleWeapon::Hide(idVehicleWeapon *this)
{
  idVehicle *vehicle; // r11
  idAttachmentCollection *v3; // r3
  idWeapon *weapon; // r11
  const idDeclInventory *decl; // r11

  vehicle = this->vehicle;
  if ( vehicle != nullptr )
  {
    v3 = (idAttachmentCollection *)((int (*)(void))vehicle->GetAttachments_2)();
    if ( v3 != nullptr && this->attachHandle.value != -1 )
      idAttachmentCollection::HideAttachment(this: v3, handle: &this->attachHandle, ignoreShowAll: false);
    weapon = this->weapon;
    if ( weapon == nullptr || (decl = weapon->decl) == nullptr )
      decl = nullptr;
    if ( BYTE1(decl[4].itemUse) != 0 )
      idLaserSight::Hide(this: &this->laserSight);
  }
}


// ========================================================================
// ?Show@idVehicleWeapon@@QAAXXZ
// EA  : 0x82D38A68
// RVA : 0x00D38A68
// PDB : w:\tech5\tungsten\game\entities\vehicleweapon.cpp
// ========================================================================

void __fastcall idVehicleWeapon::Show(idVehicleWeapon *this)
{
  idVehicle *vehicle; // r11
  idAttachmentCollection *v3; // r3
  idWeapon *weapon; // r11
  const idDeclInventory *decl; // r11
  int GameMs; // r3

  vehicle = this->vehicle;
  if ( vehicle != nullptr )
  {
    v3 = (idAttachmentCollection *)((int (*)(void))vehicle->GetAttachments_2)();
    if ( v3 != nullptr && this->attachHandle.value != -1 )
      idAttachmentCollection::ShowAttachment(this: v3, handle: &this->attachHandle);
    weapon = this->weapon;
    if ( weapon == nullptr || (decl = weapon->decl) == nullptr )
      decl = nullptr;
    if ( BYTE1(decl[4].itemUse) != 0 )
    {
      GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      idLaserSight::Show(this: &this->laserSight, startTime: GameMs);
    }
  }
}


// ========================================================================
// ?InitAnims@idVehicleWeapon@@QAAXXZ
// EA  : 0x82D38B18
// RVA : 0x00D38B18
// PDB : w:\tech5\tungsten\game\entities\vehicleweapon.cpp
// ========================================================================

void __fastcall idVehicleWeapon::InitAnims(idVehicleWeapon *this)
{
  idWeapon *weapon; // r11
  const idDeclInventory *decl; // r10
  idTreeAnimator *v4; // r11
  idTreeAnimator *treeAnimator; // r11
  unsigned __int16 v6; // r11
  idWeapon *v7; // r10
  const idDeclInventory *v8; // r11
  const idDeclInventory *v9; // r11
  unsigned __int16 v10; // r8
  idWeapon *v11; // r10
  const idDeclInventory *v12; // r11
  const idDeclInventory *v13; // r11
  unsigned __int16 v14; // r8
  idWeapon *v15; // r10
  const idDeclInventory *v16; // r11
  const idDeclInventory *v17; // r11
  unsigned __int16 v18; // r8
  idWeapon *v19; // r10
  const idDeclInventory *v20; // r11
  const idDeclInventory *v21; // r11
  unsigned __int16 v22; // r8
  idWeapon *v23; // r10
  const idDeclInventory *v24; // r11
  const idDeclInventory *v25; // r11
  unsigned __int16 v26; // r8
  idWeapon *v27; // r10
  const idDeclInventory *v28; // r11
  const idDeclInventory *v29; // r11
  unsigned __int16 v30; // r8
  idWeapon *v31; // r10
  const idDeclInventory *v32; // r11
  const idDeclInventory *v33; // r11
  unsigned __int16 v34; // r8
  idWeapon *v35; // r10
  const idDeclInventory *v36; // r11
  const idDeclInventory *v37; // r11
  unsigned __int16 v38; // r8
  unsigned __int16 v39; // [sp+50h] [-40h] BYREF
  unsigned __int16 v40; // [sp+52h] [-3Eh] BYREF
  unsigned __int16 v41; // [sp+54h] [-3Ch] BYREF
  unsigned __int16 v42; // [sp+56h] [-3Ah] BYREF
  unsigned __int16 v43; // [sp+58h] [-38h] BYREF
  unsigned __int16 v44; // [sp+5Ah] [-36h] BYREF
  unsigned __int16 v45; // [sp+5Ch] [-34h] BYREF
  unsigned __int16 v46; // [sp+5Eh] [-32h] BYREF
  unsigned __int16 v47; // [sp+60h] [-30h] BYREF

  weapon = this->weapon;
  if ( weapon != nullptr )
  {
    decl = weapon->decl;
    v4 = decl[4].isWeapon ? this->dependentWeapon->treeAnimator : this->treeAnimator;
    if ( v4 != nullptr )
    {
      treeAnimator = this->treeAnimator;
      if ( treeAnimator != nullptr )
      {
        if ( decl[3].scriptUse.__vftable != nullptr )
        {
          idDeclMD6::StrongLoadAlias(
            this: (idDeclMD6 *)&v39,
            result: treeAnimator->decl,
            aliasName: (const char *)decl[3].scriptUse.type);
          v6 = v39;
          this->animTable.ptr[1].state = VW_ANIM_IDLE;
          this->animTable.ptr[1].aliasHandle.value = v6;
          this->animTable.ptr[1].looping = true;
        }
        v7 = this->weapon;
        if ( v7 == nullptr || (v8 = v7->decl) == nullptr )
          v8 = nullptr;
        if ( v8[3].dropSound != nullptr )
        {
          if ( v7 == nullptr || (v9 = v7->decl) == nullptr )
            v9 = nullptr;
          idDeclMD6::StrongLoadAlias(
            this: (idDeclMD6 *)&v40,
            result: this->treeAnimator->decl,
            aliasName: (const char *)v9[3].hoverSound);
          v10 = v40;
          this->animTable.ptr[2].state = VW_FIRST_WEAPON_CHANGE_ANIM;
          this->animTable.ptr[2].aliasHandle.value = v10;
          this->animTable.ptr[2].looping = false;
        }
        v11 = this->weapon;
        if ( v11 == nullptr || (v12 = v11->decl) == nullptr )
          v12 = nullptr;
        if ( v12[3].giveItemsOnReceive.list != nullptr )
        {
          if ( v11 == nullptr || (v13 = v11->decl) == nullptr )
            v13 = nullptr;
          idDeclMD6::StrongLoadAlias(
            this: (idDeclMD6 *)&v41,
            result: this->treeAnimator->decl,
            aliasName: (const char *)v13[3].giveItemsOnReceive.num);
          v14 = v41;
          this->animTable.ptr[3].state = VW_ANIM_EXIT;
          this->animTable.ptr[3].aliasHandle.value = v14;
          this->animTable.ptr[3].looping = false;
        }
        v15 = this->weapon;
        if ( v15 == nullptr || (v16 = v15->decl) == nullptr )
          v16 = nullptr;
        if ( v16[4].name.str != nullptr )
        {
          if ( v15 == nullptr || (v17 = v15->decl) == nullptr )
            v17 = nullptr;
          idDeclMD6::StrongLoadAlias(
            this: (idDeclMD6 *)&v42,
            result: this->treeAnimator->decl,
            aliasName: (const char *)v17[4].nextOnHashChain);
          v18 = v42;
          this->animTable.ptr[4].state = VW_ANIM_MANNED_IDLE;
          this->animTable.ptr[4].aliasHandle.value = v18;
          this->animTable.ptr[4].looping = true;
        }
        v19 = this->weapon;
        if ( v19 == nullptr || (v20 = v19->decl) == nullptr )
          v20 = nullptr;
        if ( v20[4].textLength != 0 )
        {
          if ( v19 == nullptr || (v21 = v19->decl) == nullptr )
            v21 = nullptr;
          idDeclMD6::StrongLoadAlias(
            this: (idDeclMD6 *)&v43,
            result: this->treeAnimator->decl,
            aliasName: (const char *)v21[4].md5Checksum);
          v22 = v43;
          this->animTable.ptr[5].state = VW_ANIM_MANNED_ENTRY;
          this->animTable.ptr[5].aliasHandle.value = v22;
          this->animTable.ptr[5].looping = false;
        }
        v23 = this->weapon;
        if ( v23 == nullptr || (v24 = v23->decl) == nullptr )
          v24 = nullptr;
        if ( v24[4].inventoryClass.allocedAndFlag != 0 )
        {
          if ( v23 == nullptr || (v25 = v23->decl) == nullptr )
            v25 = nullptr;
          idDeclMD6::StrongLoadAlias(
            this: (idDeclMD6 *)&v44,
            result: this->treeAnimator->decl,
            aliasName: *(const char **)v25[4].inventoryClass.baseBuffer);
          v26 = v44;
          this->animTable.ptr[6].state = VW_ANIM_MANNED_EXIT;
          this->animTable.ptr[6].aliasHandle.value = v26;
          this->animTable.ptr[6].looping = false;
        }
        v27 = this->weapon;
        if ( v27 == nullptr || (v28 = v27->decl) == nullptr )
          v28 = nullptr;
        if ( v28[4].thirdPersonMD6 != nullptr )
        {
          if ( v27 == nullptr || (v29 = v27->decl) == nullptr )
            v29 = nullptr;
          idDeclMD6::StrongLoadAlias(
            this: (idDeclMD6 *)&v45,
            result: this->treeAnimator->decl,
            aliasName: (const char *)v29[4].dualWieldItemDecl);
          v30 = v45;
          this->animTable.ptr[7].state = VW_ANIM_GUNNER_ENTER;
          this->animTable.ptr[7].aliasHandle.value = v30;
          this->animTable.ptr[7].looping = false;
        }
        v31 = this->weapon;
        if ( v31 == nullptr || (v32 = v31->decl) == nullptr )
          v32 = nullptr;
        if ( *(_DWORD *)&v32[4].childItem.granularity != 0 )
        {
          if ( v31 == nullptr || (v33 = v31->decl) == nullptr )
            v33 = nullptr;
          idDeclMD6::StrongLoadAlias(
            this: (idDeclMD6 *)&v46,
            result: this->treeAnimator->decl,
            aliasName: (const char *)v33[4].customMaterial);
          v34 = v46;
          this->animTable.ptr[8].state = VW_ANIM_GUNNER_EXIT;
          this->animTable.ptr[8].aliasHandle.value = v34;
          this->animTable.ptr[8].looping = false;
        }
        v35 = this->weapon;
        if ( v35 == nullptr || (v36 = v35->decl) == nullptr )
          v36 = nullptr;
        if ( v36[3].engineerableItems.list != nullptr )
        {
          if ( v35 == nullptr || (v37 = v35->decl) == nullptr )
            v37 = nullptr;
          idDeclMD6::StrongLoadAlias(
            this: (idDeclMD6 *)&v47,
            result: this->treeAnimator->decl,
            aliasName: (const char *)v37[3].engineerableItems.num);
          v38 = v47;
          this->animTable.ptr[10].state = VW_ANIM_FIRE;
          this->animTable.ptr[10].aliasHandle.value = v38;
          this->animTable.ptr[10].looping = false;
        }
      }
    }
  }
}


// ========================================================================
// ?InitJointIndex@idVehicleWeapon@@IAAXXZ
// EA  : 0x82D38EE8
// RVA : 0x00D38EE8
// PDB : w:\tech5\tungsten\game\entities\vehicleweapon.cpp
// ========================================================================

void __fastcall idVehicleWeapon::InitJointIndex(idVehicleWeapon *this)
{
  idWeapon *weapon; // r11
  const idDeclInventory *decl; // r11
  __int16 *JointIndex; // r3
  idWeapon *v5; // r11
  const idDeclInventory *v6; // r11
  __int16 *v7; // r3
  idWeapon *v8; // r11
  const idDeclInventory *v9; // r11
  idLobbyBase *v10; // r3
  int value; // r11
  _BYTE v12[16]; // [sp+50h] [-20h] BYREF

  weapon = this->weapon;
  if ( weapon == nullptr || (decl = weapon->decl) == nullptr )
    decl = nullptr;
  JointIndex = (__int16 *)idTreeAnimator::GetJointIndex(
                            this: (idTreeAnimator *)v12,
                            result: (idIndex<short,enum invalidJointIndex_t> *)this->treeAnimator,
                            jointName: decl[4].internalName.data);
  v5 = this->weapon;
  this->pitchJointIndex.value = *JointIndex;
  if ( v5 == nullptr || (v6 = v5->decl) == nullptr )
    v6 = nullptr;
  v7 = (__int16 *)idTreeAnimator::GetJointIndex(
                    this: (idTreeAnimator *)v12,
                    result: (idIndex<short,enum invalidJointIndex_t> *)this->treeAnimator,
                    jointName: (const char *)v6[4].boostDescription.index);
  v8 = this->weapon;
  this->yawJointIndex.value = *v7;
  if ( v8 == nullptr || (v9 = v8->decl) == nullptr )
    v9 = nullptr;
  this->rollJointIndex.value = HIWORD(idTreeAnimator::GetJointIndex(
                                        this: (idTreeAnimator *)v12,
                                        result: (idIndex<short,enum invalidJointIndex_t> *)this->treeAnimator,
                                        jointName: (const char *)v9[4].entityDef)->__vftable);
  if ( common->IsMultiplayer(this: common) )
  {
    v10 = session->GetActingGameStateLobbyBase(this: session);
    if ( v10->GetMatchParms(this: v10)->gameType == 2 )
    {
      if ( (unsigned __int16)this->rollJointIndex.value != 0xFFFF )
        idTreeAnimator::GetModelSpaceJointTransform(
          this: this->treeAnimator,
          pose: DRIVER_MODEL,
          jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)this->rollJointIndex.value,
          origin: &this->spinJointOrigin,
          axis: &this->spinJointMat);
      value = (unsigned __int16)this->pitchJointIndex.value;
LABEL_23:
      if ( value != 0xFFFF )
        idTreeAnimator::GetModelSpaceJointTransform(
          this: this->treeAnimator,
          pose: DRIVER_MODEL,
          jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)this->yawJointIndex.value,
          origin: &this->jointOrigin,
          axis: &this->jointMat);
      return;
    }
  }
  if ( this->rollJointIndex.value != -1 )
  {
    idTreeAnimator::GetModelSpaceJointTransform(
      this: this->treeAnimator,
      pose: DRIVER_MODEL,
      jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)this->rollJointIndex.value,
      origin: &this->spinJointOrigin,
      axis: &this->spinJointMat);
LABEL_20:
    if ( (unsigned __int16)this->pitchJointIndex.value != 0xFFFF )
      idTreeAnimator::GetModelSpaceJointTransform(
        this: this->treeAnimator,
        pose: DRIVER_MODEL,
        jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)this->pitchJointIndex.value,
        origin: &this->jointOrigin,
        axis: &this->jointMat);
    value = (unsigned __int16)this->yawJointIndex.value;
    goto LABEL_23;
  }
  if ( (unsigned __int16)this->pitchJointIndex.value != 0xFFFF || (unsigned __int16)this->yawJointIndex.value != 0xFFFF )
    goto LABEL_20;
}


// ========================================================================
// ?GetWeaponSlot@idVehicleWeapon@@QBAHXZ
// EA  : 0x82D390C0
// RVA : 0x00D390C0
// PDB : w:\tech5\tungsten\game\entities\vehicleweapon.cpp
// ========================================================================

idDeclTypeInfo *__fastcall idVehicleWeapon::GetWeaponSlot(idVehicleWeapon *this)
{
  idWeapon *weapon; // r11
  const idDeclInventory *decl; // r11

  weapon = this->weapon;
  if ( weapon != nullptr && (decl = weapon->decl) != nullptr )
    return decl[1].parent;
  else
    return (idDeclTypeInfo *)MEMORY[0x230];
}


// ========================================================================
// ?HasAmmo@idVehicleWeapon@@QAA_NXZ
// EA  : 0x82D390F0
// RVA : 0x00D390F0
// PDB : w:\tech5\tungsten\game\entities\vehicleweapon.cpp
// ========================================================================

BOOL __fastcall idVehicleWeapon::HasAmmo(idVehicleWeapon *this)
{
  idWeapon *weapon; // r10
  const idDeclInventory *decl; // r11
  idPresentableVehicle *presentableVehicleCar; // r3
  const idDeclInventory *v5; // r31
  idJobManager *v6; // r3
  idJob *JobByDecl; // r3

  if ( g_infiniteAmmo.valueInteger != 0 || g_permaInfiniteAmmo.valueInteger != 0 )
    return true;
  weapon = this->weapon;
  if ( weapon == nullptr || (decl = weapon->decl) == nullptr )
    decl = nullptr;
  if ( HIBYTE(decl[1].textLength) != 0 )
    return true;
  if ( (int)weapon->decl[1].declSource <= 0 )
    return true;
  if ( (unsigned __int8)idPresentableVehicle::GetHasInfiniteAmmo(this: this->presentableVehicleCar) != 0 )
    return true;
  presentableVehicleCar = this->presentableVehicleCar;
  v5 = this->weapon->ammoClip->decl;
  v6 = (idJobManager *)presentableVehicleCar->GetInventory(this: &presentableVehicleCar->idPresentableAnimatedEntity);
  JobByDecl = idJobManager::FindJobByDecl(this: v6, jobDecl: (const idDeclJob *)v5);
  return JobByDecl != nullptr && ((int (__fastcall *)(idJob *))JobByDecl->__vftable[2].dtr_idClass)(a1: JobByDecl) > 0;
}


// ========================================================================
// ?PlayAnim@idVehicleWeapon@@QAA_NW4vehicleWeaponAnimState_t@@@Z
// EA  : 0x82D391F0
// RVA : 0x00D391F0
// PDB : w:\tech5\tungsten\game\entities\vehicleweapon.cpp
// ========================================================================

int __fastcall idVehicleWeapon::PlayAnim(idVehicleWeapon *this, vehicleWeaponAnimState_t anim)
{
  idVehicleWeapon *dependentWeapon; // r3
  idWeapon *weapon; // r11
  const idDeclInventory *decl; // r9
  idWeapon *v6; // r11
  const idDeclInventory *v7; // r11

  dependentWeapon = this->dependentWeapon;
  if ( dependentWeapon == nullptr )
    return idVehicleWeapon::PlayAnim(this, animInfo: &this->animTable.ptr[anim]);
  weapon = this->weapon;
  if ( weapon == nullptr || (decl = weapon->decl) == nullptr )
    decl = nullptr;
  v6 = dependentWeapon->weapon;
  if ( v6 == nullptr || (v7 = v6->decl) == nullptr )
    v7 = nullptr;
  if ( decl[1].parent == v7[1].parent )
    return 1;
  else
    return idVehicleWeapon::PlayAnim(this: dependentWeapon, animInfo: &this->animTable.ptr[anim]);
}


// ========================================================================
// ??0idVehicleWeapon@@QAA@XZ
// EA  : 0x82D39288
// RVA : 0x00D39288
// PDB : w:\tech5\tungsten\game\entities\vehicleweapon.cpp
// ========================================================================

idVehicleWeapon *__fastcall idVehicleWeapon::idVehicleWeapon(idVehicleWeapon *this)
{
  unsigned __int64 v1; // r29
  int v3; // ctr
  bool *p_looping; // r10
  idVehicleWeapon *v5; // r3

  this->__vftable = (idVehicleWeapon_vtbl *)&idVehicleWeapon::`vftable';
  idMD6Leaf::idMD6Leaf(this: &this->leafPlay, type_: NODE_LEAF_PLAY);
  LODWORD(v1) = 0;
  this->leafPlay.startTime = 0;
  this->leafPlay.syncGroup = 0;
  this->leafPlay.syncEnabled = 0;
  this->leafPlay.rateScale = 1.0;
  this->pitchJointIndex.value = -1;
  this->yawJointIndex.value = -1;
  this->rollJointIndex.value = -1;
  this->attachHandle.value = -1;
  this->animQueue.ptr[0].state = VW_ANIM_NONE;
  this->animQueue.ptr[0].aliasHandle.value = -1;
  this->animQueue.ptr[0].looping = false;
  this->animQueue.ptr[1].state = VW_ANIM_NONE;
  this->animQueue.ptr[1].aliasHandle.value = -1;
  this->animQueue.ptr[1].looping = false;
  this->animQueue.ptr[2].state = VW_ANIM_NONE;
  v3 = 11;
  this->animQueue.ptr[2].aliasHandle.value = -1;
  p_looping = &this->animState.looping;
  this->animQueue.ptr[2].looping = false;
  this->animQueue.ptr[3].state = VW_ANIM_NONE;
  this->animQueue.ptr[3].aliasHandle.value = -1;
  this->animQueue.ptr[3].looping = false;
  this->animState.state = VW_ANIM_NONE;
  this->animState.aliasHandle.value = -1;
  this->animState.looping = false;
  do
  {
    *(_DWORD *)(p_looping + 2) = 0;
    *((_WORD *)p_looping + 3) = -1;
    p_looping += 8;
    *p_looping = false;
    --v3;
  }
  while ( v3 != 0 );
  this->presentable.spawnId = 0;
  this->lastPresentable.spawnId = 0;
  this->remoteFireAttacker.spawnId = 0;
  this->remoteFireTarget.spawnId = 0;
  idLaserSight::idLaserSight(this: &this->laserSight);
  this->deferredWeaponTrace.index = v1;
  idVehicleWeapon::InitVars(this);
  idVehicleWeapon::InitAnims(this: v5);
  idVehicleWeapon::InitLaserSight(this);
  return this;
}


// ========================================================================
// __unwind$491546
// EA  : 0x82D393E4
// RVA : 0x00D393E4
// PDB : w:\tech5\tungsten\game\entities\vehicleweapon.cpp
// ========================================================================

void _unwind_491546()
{
  int v0; // r12

  idAIEvent::~idAIEvent(this: *(idAimAssist **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$491547
// EA  : 0x82D3940C
// RVA : 0x00D3940C
// PDB : w:\tech5\tungsten\game\entities\vehicleweapon.cpp
// ========================================================================

void _unwind_491547()
{
  int v0; // r12

  idLaserSight::~idLaserSight(this: (idLaserSight *)(*(_DWORD *)(v0 - 128 + 148) + 456));
}


// ========================================================================
// ?ClearWeaponFX@idVehicleWeapon@@QAAXXZ
// EA  : 0x82D39438
// RVA : 0x00D39438
// PDB : w:\tech5\tungsten\game\entities\vehicleweapon.cpp
// ========================================================================

void __fastcall idVehicleWeapon::ClearWeaponFX(idVehicleWeapon *this)
{
  idPresentablePtr<idPresentable> *p_presentable; // r31
  int GameMs; // r30
  idPresentable *v3; // r3

  if ( this->weapon != nullptr )
  {
    p_presentable = &this->presentable;
    if ( idPresentablePtr<idPresentableProjectile>::operator->(this: &this->presentable) != nullptr )
    {
      GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      v3 = idPresentablePtr<idPresentableProjectile>::operator->(this: p_presentable);
      idFXManager::StopAllFX(this: &v3->fxManager, time: GameMs, immediateStop: true);
    }
  }
}


// ========================================================================
// ?PlayingWeaponChangeAnim@idVehicleWeapon@@QAA_NXZ
// EA  : 0x82D394B8
// RVA : 0x00D394B8
// PDB : w:\tech5\tungsten\game\entities\vehicleweapon.cpp
// ========================================================================

int __fastcall idVehicleWeapon::PlayingWeaponChangeAnim(idVehicleWeapon *this)
{
  idVehicleWeapon *dependentWeapon; // r11
  idVehicleWeapon *v2; // r30
  idVehicleWeapon **i; // r31
  int v4; // r29
  __int64 v5; // r10
  int v6; // r8
  int v7; // r7
  int v8; // r6
  int GameMs; // r3
  idVehicleWeapon *v10; // r11
  int v11; // r31
  bool v12; // zf
  idMD6LeafPlay *LeafPlay; // r3
  vehicleWeaponAnimState_t state; // r11
  int animCount; // r8
  int v17; // r10
  idArray<idVehicleWeapon::animInfo_t,4> *j; // r11

  dependentWeapon = this->dependentWeapon;
  v2 = this;
  for ( i = &this->dependentWeapon; dependentWeapon != nullptr; dependentWeapon = dependentWeapon->dependentWeapon )
  {
    i = &dependentWeapon->dependentWeapon;
    v2 = dependentWeapon;
  }
  v4 = timeManager.gameTimePerFrame.value * timeManager.gameHz;
  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  v10 = *i;
  v12 = *i != nullptr;
  v11 = GameMs;
  if ( v12 )
    LeafPlay = idVehicleWeapon::GetLeafPlay(this: v10);
  else
    LeafPlay = &v2->leafPlay;
  if ( idMD6LeafPlay::IsPlaying(this: LeafPlay, gameTime: v11, ticksPerSec: v4, a4: v8, a5: v7, a6: v6, a7: v5) )
  {
    state = v2->animState.state;
    if ( state == VW_FIRST_WEAPON_CHANGE_ANIM || state == VW_ANIM_EXIT )
      return 1;
  }
  animCount = v2->animCount;
  v17 = 0;
  if ( animCount > 0 )
  {
    for ( j = &v2->animQueue;
          j->ptr[0].state != VW_FIRST_WEAPON_CHANGE_ANIM && j->ptr[0].state != VW_ANIM_EXIT;
          j = (idArray<idVehicleWeapon::animInfo_t,4> *)((char *)j + 8) )
    {
      if ( ++v17 >= animCount )
        return 0;
    }
    return 1;
  }
  return 0;
}


// ========================================================================
// ?GetCurrentAnimLength@idVehicleWeapon@@QAAHXZ
// EA  : 0x82D395B8
// RVA : 0x00D395B8
// PDB : w:\tech5\tungsten\game\entities\vehicleweapon.cpp
// ========================================================================

int __fastcall idVehicleWeapon::GetCurrentAnimLength(idVehicleWeapon *this, int a2, int a3, int a4, __int64 a5)
{
  idVehicleWeapon *dependentWeapon; // r3
  int v7; // r31
  idMD6LeafPlay *LeafPlay; // r3

  dependentWeapon = this->dependentWeapon;
  LODWORD(a5) = &timeManager;
  v7 = timeManager.gameTimePerFrame.value * timeManager.gameHz;
  if ( dependentWeapon != nullptr )
    LeafPlay = idVehicleWeapon::GetLeafPlay(this: dependentWeapon);
  else
    LeafPlay = &this->leafPlay;
  return idMD6Leaf::GetLength(this: LeafPlay, ticksPerSec: v7, a3, a4: a5);
}


// ========================================================================
// ?Serialize@idVehicleWeapon@@QAAXAAVidSerializer@@@Z
// EA  : 0x82D39618
// RVA : 0x00D39618
// PDB : w:\tech5\tungsten\game\entities\vehicleweapon.cpp
// ========================================================================

void __fastcall idVehicleWeapon::Serialize(idVehicleWeapon *this, idSerializer *ser)
{
  idBitMsg *msg; // r3

  msg = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: msg, value: this->presentable.spawnId, numBits: 32);
  else
    this->presentable.spawnId = idBitMsg::ReadBits(this: msg, numBits: 32);
  this->weapon->Serialize(this: this->weapon, a2: ser, a3: nullptr);
}


// ========================================================================
// ?ClientInit@idVehicleWeapon@@IAAXXZ
// EA  : 0x82D39698
// RVA : 0x00D39698
// PDB : w:\tech5\tungsten\game\entities\vehicleweapon.cpp
// ========================================================================

void __fastcall idVehicleWeapon::ClientInit(idVehicleWeapon *this)
{
  unsigned int spawnId; // r11
  idPresentablePtr<idPresentable> *p_presentable; // r28
  int v4; // r30
  idPresentable *PresentableByIndex; // r27
  unsigned int v6; // r11
  int v7; // r30
  idPresentable *v8; // r3
  idPresentable *v9; // r3
  idTreeAnimator *v10; // r3

  spawnId = this->presentable.spawnId;
  p_presentable = &this->presentable;
  v4 = spawnId & 0x3FFF;
  if ( spawnId == 0
    || !idClientGame::IsPresentableIndexValid(this: clientGame, index: spawnId & 0x3FFF)
    || (PresentableByIndex = idClientGame::GetPresentableByIndex(this: clientGame, index: v4))->spawnId != p_presentable->spawnId )
  {
    PresentableByIndex = nullptr;
  }
  v6 = this->lastPresentable.spawnId;
  v7 = v6 & 0x3FFF;
  if ( v6 == 0
    || !idClientGame::IsPresentableIndexValid(this: clientGame, index: v6 & 0x3FFF)
    || (v8 = idClientGame::GetPresentableByIndex(this: clientGame, index: v7))->spawnId != this->lastPresentable.spawnId )
  {
    v8 = nullptr;
  }
  if ( PresentableByIndex != v8 )
  {
    this->lastPresentable = (idPresentablePtr<idPresentable>)p_presentable->spawnId;
    if ( idPresentablePtr<idPresentableProjectile>::operator->(this: p_presentable) != nullptr )
    {
      v9 = idPresentablePtr<idPresentableProjectile>::operator->(this: p_presentable);
      v10 = (idTreeAnimator *)_RTDynamicCast(
                                inptr: v9->model,
                                VfDelta: 0,
                                SrcType: &idRenderModel `RTTI Type Descriptor',
                                TargetType: &idTreeAnimator `RTTI Type Descriptor',
                                isReference: 0);
      this->treeAnimator = v10;
      if ( v10 != nullptr )
        idVehicleWeapon::InitJointIndex(this);
    }
    else
    {
      this->treeAnimator = nullptr;
    }
  }
}


// ========================================================================
// ?ValidateTreeAnimator@idVehicleWeapon@@IAAXXZ
// EA  : 0x82D397B8
// RVA : 0x00D397B8
// PDB : w:\tech5\tungsten\game\entities\vehicleweapon.cpp
// ========================================================================

void __fastcall idVehicleWeapon::ValidateTreeAnimator(idVehicleWeapon *this)
{
  idPresentable *v2; // r3

  if ( common->IsClient(this: common) )
  {
    if ( idPresentablePtr<idPresentableProjectile>::operator->(this: &this->presentable) != nullptr )
    {
      v2 = idPresentablePtr<idPresentableProjectile>::operator->(this: &this->presentable);
      if ( this->treeAnimator != _RTDynamicCast(
                                   inptr: v2->model,
                                   VfDelta: 0,
                                   SrcType: &idRenderModel `RTTI Type Descriptor',
                                   TargetType: &idTreeAnimator `RTTI Type Descriptor',
                                   isReference: 0) )
      {
        this->treeAnimator = nullptr;
        this->presentable.spawnId = 0;
      }
    }
    else
    {
      this->treeAnimator = nullptr;
    }
  }
}


// ========================================================================
// ??0idVehicleWeapon@@QAA@PAVidPresentableVehicle@@PAVidInventoryItem@@@Z
// EA  : 0x82D39878
// RVA : 0x00D39878
// PDB : w:\tech5\tungsten\game\entities\vehicleweapon.cpp
// ========================================================================

idVehicleWeapon *__fastcall idVehicleWeapon::idVehicleWeapon(
        idVehicleWeapon *this,
        idPresentableVehicle *vehiclePres,
        idWeapon *item)
{
  unsigned __int64 v5; // r29
  int v6; // ctr
  bool *p_looping; // r10
  idPresentablePtr<idPresentable> *p_presentable; // r25
  idVehicle *v9; // r7
  idWeapon *v10; // r3
  idAttachment *list; // r11
  int v12; // r11
  idVehicleWeapon *dependentWeapon; // r10
  idVehicleWeapon *v14; // r27
  unsigned int spawnId; // r11
  int v16; // r28
  idPresentable *PresentableByIndex; // r3
  int v18; // r28
  idPresentable *v19; // r3
  idVehicle *vehicle; // r3
  idAttachmentCollection *v21; // r28
  int *v22; // r3
  bool v23; // cr58
  const idAttachment *v24; // r3
  idAttachmentCollection v26[4]; // [sp+50h] [-50h] BYREF

  HIDWORD(v5) = vehiclePres;
  this->__vftable = (idVehicleWeapon_vtbl *)&idVehicleWeapon::`vftable';
  idMD6Leaf::idMD6Leaf(this: &this->leafPlay, type_: NODE_LEAF_PLAY);
  LODWORD(v5) = 0;
  this->leafPlay.startTime = 0;
  this->leafPlay.syncGroup = 0;
  this->leafPlay.syncEnabled = 0;
  this->leafPlay.rateScale = 1.0;
  this->pitchJointIndex.value = -1;
  this->yawJointIndex.value = -1;
  this->rollJointIndex.value = -1;
  this->attachHandle.value = -1;
  this->animQueue.ptr[0].state = VW_ANIM_NONE;
  this->animQueue.ptr[0].aliasHandle.value = -1;
  this->animQueue.ptr[0].looping = false;
  this->animQueue.ptr[1].state = VW_ANIM_NONE;
  this->animQueue.ptr[1].aliasHandle.value = -1;
  this->animQueue.ptr[1].looping = false;
  this->animQueue.ptr[2].state = VW_ANIM_NONE;
  v6 = 11;
  this->animQueue.ptr[2].aliasHandle.value = -1;
  p_looping = &this->animState.looping;
  this->animQueue.ptr[2].looping = false;
  this->animQueue.ptr[3].state = VW_ANIM_NONE;
  this->animQueue.ptr[3].aliasHandle.value = -1;
  this->animQueue.ptr[3].looping = false;
  this->animState.state = VW_ANIM_NONE;
  this->animState.aliasHandle.value = -1;
  this->animState.looping = false;
  v26[0].attachments.list = (idAttachment *)&this->animState.aliasHandle;
  do
  {
    *(_DWORD *)(p_looping + 2) = 0;
    *((_WORD *)p_looping + 3) = -1;
    p_looping += 8;
    *p_looping = false;
    --v6;
  }
  while ( v6 != 0 );
  this->presentable.spawnId = 0;
  p_presentable = &this->presentable;
  this->lastPresentable.spawnId = 0;
  this->remoteFireAttacker.spawnId = 0;
  this->remoteFireTarget.spawnId = 0;
  idLaserSight::idLaserSight(this: &this->laserSight);
  this->deferredWeaponTrace.index = v5;
  v26[0].attachments.list = (idAttachment *)&this->deferredWeaponTrace;
  idVehicleWeapon::InitVars(this);
  v9 = *(idVehicle **)(HIDWORD(v5) + 1096);
  this->presentableVehicleCar = (idPresentableVehicle *)HIDWORD(v5);
  this->vehicle = v9;
  v10 = idWeapon::CastTo(c: item);
  this->treeAnimator = nullptr;
  this->weapon = v10;
  if ( v10 == nullptr
    || (v26[0].attachments.list = (idAttachment *)v10->decl,
        list = v26[0].attachments.list,
        v26[0].attachments.list == nullptr) )
  {
    list = nullptr;
  }
  if ( HIBYTE(list[21].particleFxTagData.trans.z) != 0 )
  {
    v12 = 0;
    this->dependentWeapon = *(idVehicleWeapon **)(*(_DWORD *)(HIDWORD(v5) + 18744)
                                                + 4 * *(_DWORD *)(HIDWORD(v5) + 18748)
                                                - 4);
    do
    {
      dependentWeapon = this->dependentWeapon->dependentWeapon;
      if ( dependentWeapon == nullptr )
        break;
      ++v12;
      this->dependentWeapon = dependentWeapon;
    }
    while ( v12 < 10 );
    v14 = this->dependentWeapon;
    spawnId = v14->presentable.spawnId;
    v16 = spawnId & 0x3FFF;
    if ( spawnId == 0
      || !idClientGame::IsPresentableIndexValid(this: clientGame, index: spawnId & 0x3FFF)
      || (PresentableByIndex = idClientGame::GetPresentableByIndex(this: clientGame, index: v16))->spawnId != v14->presentable.spawnId )
    {
      PresentableByIndex = nullptr;
    }
    if ( PresentableByIndex != nullptr )
      p_presentable->spawnId = PresentableByIndex->spawnId;
    else
      p_presentable->spawnId = 0;
    this->treeAnimator = this->dependentWeapon->treeAnimator;
    v18 = p_presentable->spawnId & 0x3FFF;
    if ( p_presentable->spawnId == 0
      || !idClientGame::IsPresentableIndexValid(this: clientGame, index: p_presentable->spawnId & 0x3FFF)
      || (v19 = idClientGame::GetPresentableByIndex(this: clientGame, index: v18))->spawnId != p_presentable->spawnId )
    {
      v19 = nullptr;
    }
    idPresentable::UpdateModelTransform(this: v19);
  }
  else
  {
    vehicle = this->vehicle;
    if ( vehicle != nullptr )
    {
      v21 = vehicle->GetAttachments_2(this: vehicle);
      if ( idAnimatedEntity::GetTreeAnimatorFromPresentable(this: v21->parent) != nullptr )
      {
        v22 = (int *)idAttachmentCollection::AddAttachment(
                       this: v26,
                       result: v21,
                       item,
                       tagName: "weapon",
                       fxAttachInfo: nullptr);
        v23 = *v22 == -1;
        this->attachHandle.value = *v22;
        if ( !v23 )
        {
          v24 = idAttachmentCollection::Get(this: v21, handle: &this->attachHandle);
          if ( v24->presentable != nullptr )
            p_presentable->spawnId = v24->presentable->spawnId;
          else
            p_presentable->spawnId = 0;
          this->treeAnimator = (idTreeAnimator *)_RTDynamicCast(
                                                   inptr: v24->presentable->model,
                                                   VfDelta: 0,
                                                   SrcType: &idRenderModel `RTTI Type Descriptor',
                                                   TargetType: &idTreeAnimator `RTTI Type Descriptor',
                                                   isReference: 0);
        }
      }
      this->dependentWeapon = nullptr;
    }
  }
  if ( this->treeAnimator != nullptr )
    idVehicleWeapon::InitJointIndex(this);
  idVehicleWeapon::InitAnims(this);
  idVehicleWeapon::InitLaserSight(this);
  return this;
}


// ========================================================================
// __unwind$492103_0
// EA  : 0x82D39BE8
// RVA : 0x00D39BE8
// PDB : w:\tech5\tungsten\game\entities\vehicleweapon.cpp
// ========================================================================

void _unwind_492103_0()
{
  int v0; // r12

  idAIEvent::~idAIEvent(this: *(idAimAssist **)(v0 - 160 + 180));
}


// ========================================================================
// __unwind$492104_0
// EA  : 0x82D39C10
// RVA : 0x00D39C10
// PDB : w:\tech5\tungsten\game\entities\vehicleweapon.cpp
// ========================================================================

void _unwind_492104_0()
{
  int v0; // r12

  idLaserSight::~idLaserSight(this: (idLaserSight *)(*(_DWORD *)(v0 - 160 + 180) + 456));
}


// ========================================================================
// ?UpdateAnimation@idVehicleWeapon@@QAAXXZ
// EA  : 0x82D39C40
// RVA : 0x00D39C40
// PDB : w:\tech5\tungsten\game\entities\vehicleweapon.cpp
// ========================================================================

void __fastcall idVehicleWeapon::UpdateAnimation(idVehicleWeapon *this)
{
  idVehicleWeapon::animInfo_t v2; // r11
  int v3; // r27
  int v4; // r26
  __int64 v5; // r10
  int v6; // r8
  int v7; // r7
  int v8; // r6
  idMD6LeafPlay *p_leafPlay; // r3
  md6WeightGroup_t v10; // r23
  const idMD6Alias *Alias; // r3
  const idMD6Anim *Existing; // r27
  int v13; // r26
  int GameMs; // r25
  idMD6Leaf::wrapMode_t v15; // r8
  idMD6LeafPlay *LeafPlay; // r3
  idVehicleWeapon::animInfo_t v17; // r10
  int v18; // r11
  int v19; // r27
  int v20; // r26
  __int64 v21; // r10
  int v22; // r8
  int v23; // r7
  int v24; // r6
  idMD6LeafPlay *v25; // r3
  idMD6LeafPlay *v26; // r27
  idVehicleWeapon *dependentWeapon; // r3
  unsigned int v28; // r29
  int GameMsPerFrame; // r26
  int PreviousGameMs; // r25
  int v31; // r3
  unsigned int v32; // r29
  int v33; // r27
  int v34; // r26
  int v35; // r3
  int v36; // r3
  idTreeAnimator *treeAnimator; // r11
  idRenderModelParms *p_deferredOrigin; // r11
  float y; // r3
  float z; // r31
  idTreeAnimator *v41; // r3
  const idIndex<short,enum invalidJointIndex_t> *value; // r5
  idTreeAnimator *v43; // r10
  float *p_deferredAxis; // r11
  double v45; // fp12
  double v46; // fp13
  double v47; // fp0
  double v48; // fp31
  float *v49; // r3
  float *p_axis; // r11
  float *p_x; // r11
  double v52; // fp7
  double v53; // fp9
  idPresentableVehicle *presentableVehicleCar; // r11
  idAngles *v55; // r3
  double v56; // fp9
  double v57; // fp7
  idVec3 *v58; // r3
  double v59; // fp9
  double v60; // fp7
  float *v61; // [sp+8h] [-1B8h]
  float *v62; // [sp+Ch] [-1B4h]
  float *v63; // [sp+10h] [-1B0h]
  int v64; // [sp+14h] [-1ACh]
  int v65; // [sp+18h] [-1A8h]
  int v66; // [sp+1Ch] [-1A4h]
  int v67; // [sp+20h] [-1A0h]
  int v68; // [sp+24h] [-19Ch]
  int v69; // [sp+28h] [-198h]
  int v70; // [sp+2Ch] [-194h]
  int v71; // [sp+30h] [-190h]
  int v72; // [sp+34h] [-18Ch]
  int v73; // [sp+38h] [-188h]
  int v74; // [sp+3Ch] [-184h]
  int v75; // [sp+40h] [-180h]
  int v76; // [sp+44h] [-17Ch]
  int v77; // [sp+48h] [-178h]
  int v78; // [sp+4Ch] [-174h]
  int v79; // [sp+50h] [-170h]
  int v80; // [sp+58h] [-168h]
  int v81; // [sp+60h] [-160h]
  idVec3 v82; // [sp+70h] [-150h] BYREF
  idMat3 v83; // [sp+80h] [-140h] BYREF
  float v84; // [sp+A4h] [-11Ch]
  float v85; // [sp+A8h] [-118h]
  idMat3 v86; // [sp+B0h] [-110h] BYREF
  idVec3 v87; // [sp+D8h] [-E8h] BYREF
  idAngles v88[2]; // [sp+E8h] [-D8h] BYREF
  idMat3 v89; // [sp+100h] [-C0h] BYREF
  idAngles v90[4]; // [sp+130h] [-90h] BYREF

  idVehicleWeapon::ValidateTreeAnimator(this);
  if ( this->treeAnimator != nullptr )
  {
    if ( this->animCount != 0 )
    {
      v2 = this->animQueue.ptr[0];
      v2.state = this->animState.looping;
      *(idVehicleWeapon::animInfo_t *)&v83.mat[0].x = v2;
      if ( v2.state != VW_ANIM_NONE
        || ((v3 = timeManager.gameTimePerFrame.value * timeManager.gameHz,
             v4 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED),
             this->dependentWeapon != nullptr)
          ? (p_leafPlay = idVehicleWeapon::GetLeafPlay(this: this->dependentWeapon))
          : (p_leafPlay = &this->leafPlay),
            !idMD6LeafPlay::IsPlaying(this: p_leafPlay, gameTime: v4, ticksPerSec: v3, a4: v8, a5: v7, a6: v6, a7: v5)) )
      {
        if ( HIWORD(v83.mat[0].y) != 0xFFFF )
        {
          v10 = BYTE2(v83.mat[0].y) != 0;
          Alias = idDeclMD6::FindAlias(
                    this: this->treeAnimator->decl,
                    aliasHandle: (const idHandle<unsigned short,enum invalidAliasHandle_t,65535> *)&v83.mat[0].y,
                    includeInherited: true);
          if ( Alias == nullptr )
            return;
          Existing = (const idMD6Anim *)idResourceList::FindExisting(
                                          this: &idMD6Anim::resourceList,
                                          name: (char *)Alias->animRefs.list->str,
                                          skipStaleCheck: true);
          v13 = timeManager.gameTimePerFrame.value * timeManager.gameHz;
          GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
          if ( this->dependentWeapon != nullptr )
            LeafPlay = idVehicleWeapon::GetLeafPlay(this: this->dependentWeapon);
          else
            LeafPlay = &this->leafPlay;
          idMD6LeafPlay::Init(
            this: LeafPlay,
            anim: Existing,
            gameTime: GameMs,
            ticksPerSec: v13,
            frame: 0,
            rateScale: 1.0,
            wrapMode: v15,
            weightGroup: v10,
            a9: 0);
          v17 = *(idVehicleWeapon::animInfo_t *)&v83.mat[0].x;
          v18 = this->animCount - 1;
          this->animCount = v18;
          this->animState = v17;
          memcpy(Dst: &this->animQueue, Src: &this->animQueue.ptr[1], Size: 8 * v18);
        }
      }
    }
    else if ( !this->animState.looping )
    {
      v19 = timeManager.gameTimePerFrame.value * timeManager.gameHz;
      v20 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      v25 = this->dependentWeapon != nullptr
          ? idVehicleWeapon::GetLeafPlay(this: this->dependentWeapon)
          : &this->leafPlay;
      if ( !idMD6LeafPlay::IsPlaying(this: v25, gameTime: v20, ticksPerSec: v19, a4: v24, a5: v23, a6: v22, a7: v21) )
      {
        this->animState.state = VW_ANIM_NONE;
        this->animState.looping = false;
        this->animState.aliasHandle.value = -1;
      }
    }
    if ( this->dependentWeapon == nullptr )
    {
      v26 = &this->leafPlay;
      if ( (unsigned __int8)idMD6Node::IsValid(this: &this->leafPlay) != 0 )
      {
        dependentWeapon = this->dependentWeapon;
        if ( dependentWeapon != nullptr )
          v26 = idVehicleWeapon::GetLeafPlay(this: dependentWeapon);
        v28 = timeManager.gameTimePerFrame.value * timeManager.gameHz;
        GameMsPerFrame = idGameTimeManager::GetGameMsPerFrame(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        PreviousGameMs = idGameTimeManager::GetPreviousGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        v31 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        idTreeAnimator::BlendTreeInternal(
          this: this->treeAnimator,
          currentTime: v31,
          previousTime: PreviousGameMs,
          gameMsPerFrame: GameMsPerFrame,
          ticksPerSec: v28,
          tree: v26,
          parallelJobList: gameLocal->parallelJobList,
          localR: nullptr,
          localS: v61,
          localT: v62,
          localU: v63,
          a12: v64,
          a13: v65,
          a14: v66,
          a15: v67,
          a16: v68,
          a17: v69,
          a18: v70,
          a19: v71,
          a20: v72,
          a21: v73,
          a22: v74,
          a23: v75,
          a24: v76,
          a25: v77,
          a26: v78,
          a27: v79,
          a28: nullptr,
          a29: v80,
          a30: nullptr,
          a31: v81,
          a32: nullptr);
      }
      else
      {
        v32 = timeManager.gameTimePerFrame.value * timeManager.gameHz;
        v33 = idGameTimeManager::GetGameMsPerFrame(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        v34 = idGameTimeManager::GetPreviousGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        v35 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        idTreeAnimator::BlendTreeInternal(
          this: this->treeAnimator,
          currentTime: v35,
          previousTime: v34,
          gameMsPerFrame: v33,
          ticksPerSec: v32,
          tree: nullptr,
          parallelJobList: gameLocal->parallelJobList,
          localR: nullptr,
          localS: v61,
          localT: v62,
          localU: v63,
          a12: v64,
          a13: v65,
          a14: v66,
          a15: v67,
          a16: v68,
          a17: v69,
          a18: v70,
          a19: v71,
          a20: v72,
          a21: v73,
          a22: v74,
          a23: v75,
          a24: v76,
          a25: v77,
          a26: v78,
          a27: v79,
          a28: nullptr,
          a29: v80,
          a30: nullptr,
          a31: v81,
          a32: nullptr);
      }
      v36 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      idTreeAnimator::UpdateTime(this: this->treeAnimator, time: v36);
    }
    if ( vehicle_weapon_debug.valueInteger != 0 )
    {
      if ( (unsigned __int8)idMat3::Compare(this: &this->targetAxis, a: &mat3_identity) == 0 )
      {
        treeAnimator = this->treeAnimator;
        if ( treeAnimator->useDeferredPosition )
          p_deferredOrigin = (idRenderModelParms *)&treeAnimator->deferredOrigin;
        else
          p_deferredOrigin = &treeAnimator->g;
        y = p_deferredOrigin->origin.y;
        z = p_deferredOrigin->origin.z;
        v83.mat[0].x = p_deferredOrigin->origin.x;
        v83.mat[0].y = y;
        v83.mat[0].z = z;
        clientGame->renderWorld->DebugLine(
          this: clientGame->renderWorld,
          a2: (const idVec4 *)&idColor::colorWhite,
          a3: (const idVec3 *)&v83,
          a4: &this->lastTargetPos,
          a5: 0,
          a6: false);
      }
      v41 = this->treeAnimator;
      value = (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)this->yawJointIndex.value;
      if ( (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)this->pitchJointIndex.value == value )
      {
        if ( (unsigned __int8)idTreeAnimator::GetModelSpaceJointTransform(
                                this: v41,
                                pose: DRIVER_MODEL,
                                jointIndex: value,
                                origin: &v82,
                                axis: &v86) == 0 )
          return;
        v43 = this->treeAnimator;
        p_deferredAxis = (float *)&v43->deferredAxis;
        if ( !v43->useDeferredPosition )
          p_deferredAxis = (float *)&v43->g.axis;
        v45 = (float)((float)(p_deferredAxis[7] * v82.z)
                    + (float)((float)(p_deferredAxis[4] * v82.y) + (float)(p_deferredAxis[1] * v82.x)));
        v46 = (float)((float)(v82.x * *p_deferredAxis)
                    + (float)((float)(p_deferredAxis[3] * v82.y) + (float)(p_deferredAxis[6] * v82.z)));
        v47 = (float)((float)(p_deferredAxis[8] * v82.z)
                    + (float)((float)(p_deferredAxis[5] * v82.y) + (float)(p_deferredAxis[2] * v82.x)));
      }
      else
      {
        if ( (unsigned __int8)idTreeAnimator::GetModelSpaceJointTransform(
                                this: v41,
                                pose: DRIVER_MODEL,
                                jointIndex: value,
                                origin: &v82,
                                axis: &v86) == 0
          || (unsigned __int8)idTreeAnimator::GetModelSpaceJointTransform(
                                this: this->treeAnimator,
                                pose: DRIVER_MODEL,
                                jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)this->pitchJointIndex.value,
                                origin: &v82,
                                axis: &v89) == 0 )
        {
          return;
        }
        v48 = idMat3::ToYaw(this: &v86);
        v83.mat[2].z = idMat3::ToPitch(this: &v89);
        v84 = v48;
        v85 = 0.0;
        v49 = (float *)idAngles::ToMat3(this: v90, result: (idMat3 *)&v83.mat[2].z);
        v86.mat[0].x = *v49;
        v43 = this->treeAnimator;
        v86.mat[0].y = v49[1];
        p_axis = (float *)&v43->deferredAxis;
        v86.mat[0].z = v49[2];
        v86.mat[1].x = v49[3];
        v86.mat[1].y = v49[4];
        v86.mat[1].z = v49[5];
        v86.mat[2].x = v49[6];
        v86.mat[2].y = v49[7];
        v86.mat[2].z = v49[8];
        if ( !v43->useDeferredPosition )
          p_axis = (float *)&v43->g.axis;
        v46 = (float)((float)(*p_axis * v82.x) + (float)((float)(p_axis[6] * v82.z) + (float)(p_axis[3] * v82.y)));
        v45 = (float)((float)(p_axis[4] * v82.y) + (float)((float)(p_axis[1] * v82.x) + (float)(p_axis[7] * v82.z)));
        v47 = (float)((float)(p_axis[5] * v82.y) + (float)((float)(p_axis[2] * v82.x) + (float)(p_axis[8] * v82.z)));
      }
      p_x = &v43->deferredOrigin.x;
      if ( !v43->useDeferredPosition )
        p_x = &v43->g.origin.x;
      v52 = (float)(p_x[1] + (float)v45);
      v53 = (float)(*p_x + (float)v46);
      v82.z = p_x[2] + (float)v47;
      v82.y = v52;
      presentableVehicleCar = this->presentableVehicleCar;
      v82.x = v53;
      v55 = idMat3::ToAngles(this: &v83, result: (idAngles *)&presentableVehicleCar->axis);
      v56 = (float)(v55->roll + this->targetAngles.roll);
      v57 = (float)(v55->yaw + this->targetAngles.yaw);
      v87.x = v55->pitch + this->targetAngles.pitch;
      v87.z = v56;
      v87.y = v57;
      v58 = idAngles::ToForward(this: v88, result: &v87);
      v59 = (float)(v58->z * (float)500.0);
      v60 = (float)((float)(v58->y * (float)500.0) + v82.y);
      v83.mat[1].y = (float)(v58->x * (float)500.0) + v82.x;
      v83.mat[1].z = v60;
      v83.mat[2].x = (float)v59 + v82.z;
      ((void (__fastcall *)(idRenderWorld *, idColor *, idVec3 *, float *, double))clientGame->renderWorld->DebugArrow)(
        a1: clientGame->renderWorld,
        a2: &idColor::colorRed,
        a3: &v82,
        a4: &v83.mat[1].y,
        a5: 5.0);
    }
  }
}


// ========================================================================
// ?InRecentFrame@idVehicleWeapon@@QAA_NXZ
// EA  : 0x82D3A300
// RVA : 0x00D3A300
// PDB : w:\tech5\tungsten\game\entities\vehicleweapon.cpp
// ========================================================================

int __fastcall idVehicleWeapon::InRecentFrame(idVehicleWeapon *this)
{
  idTreeAnimator *treeAnimator; // r3
  bool IsRendered; // r3
  unsigned __int8 v4; // r11

  idVehicleWeapon::ValidateTreeAnimator(this);
  treeAnimator = this->treeAnimator;
  if ( treeAnimator == nullptr )
    return 0;
  IsRendered = idRenderModel::IsRendered(this: treeAnimator);
  v4 = 1;
  if ( !IsRendered )
    return 0;
  return v4;
}


// ========================================================================
// ?GetOrigin@idVehicleWeapon@@QAAXAAVidVec3@@@Z
// EA  : 0x82D3A358
// RVA : 0x00D3A358
// PDB : w:\tech5\tungsten\game\entities\vehicleweapon.cpp
// ========================================================================

void __fastcall idVehicleWeapon::GetOrigin(idVehicleWeapon *this, idVec3 *origin)
{
  unsigned int spawnId; // r11
  int v5; // r28
  idPresentable *v6; // r3
  double y; // fp9
  double z; // fp5
  double v9; // fp2
  double v10; // fp1
  idTreeAnimator *treeAnimator; // r10
  float *p_deferredAxis; // r11
  float *p_x; // r11
  double v14; // fp13
  double v15; // fp0
  double v16; // fp12
  double v17; // fp7
  double v18; // fp6
  idPresentableVehicle *presentableVehicleCar; // r11
  float v20[24]; // [sp+50h] [-60h] BYREF

  idVehicleWeapon::ValidateTreeAnimator(this);
  spawnId = this->presentable.spawnId;
  v5 = spawnId & 0x3FFF;
  if ( spawnId != 0
    && idClientGame::IsPresentableIndexValid(this: clientGame, index: spawnId & 0x3FFF)
    && idClientGame::GetPresentableByIndex(this: clientGame, index: v5)->spawnId == this->presentable.spawnId )
  {
    v6 = idPresentablePtr<idPresentableProjectile>::operator->(this: &this->presentable);
    v6->GetWorldTransform(this: v6, a2: origin, a3: (idMat3 *)v20);
    y = origin->y;
    z = origin->z;
    v9 = (float)((float)(this->jointOrigin.y * v20[4])
               + (float)((float)(this->jointOrigin.x * v20[1]) + (float)(this->jointOrigin.z * v20[7])));
    v10 = (float)((float)(this->jointOrigin.y * v20[5])
                + (float)((float)(this->jointOrigin.x * v20[2]) + (float)(this->jointOrigin.z * v20[8])));
    origin->x = origin->x
              + (float)((float)(this->jointOrigin.x * v20[0])
                      + (float)((float)(this->jointOrigin.z * v20[6]) + (float)(this->jointOrigin.y * v20[3])));
    origin->y = (float)v9 + (float)y;
    origin->z = (float)v10 + (float)z;
  }
  else
  {
    treeAnimator = this->treeAnimator;
    if ( treeAnimator != nullptr )
    {
      p_deferredAxis = (float *)&treeAnimator->deferredAxis;
      if ( !treeAnimator->useDeferredPosition )
        p_deferredAxis = (float *)&treeAnimator->g.axis;
      v14 = (float)((float)(p_deferredAxis[1] * this->jointOrigin.x)
                  + (float)((float)(p_deferredAxis[4] * this->jointOrigin.y)
                          + (float)(p_deferredAxis[7] * this->jointOrigin.z)));
      v15 = (float)((float)(this->jointOrigin.x * *p_deferredAxis)
                  + (float)((float)(p_deferredAxis[3] * this->jointOrigin.y)
                          + (float)(p_deferredAxis[6] * this->jointOrigin.z)));
      v16 = (float)((float)(p_deferredAxis[2] * this->jointOrigin.x)
                  + (float)((float)(p_deferredAxis[5] * this->jointOrigin.y)
                          + (float)(p_deferredAxis[8] * this->jointOrigin.z)));
      p_x = &treeAnimator->deferredOrigin.x;
      if ( !treeAnimator->useDeferredPosition )
        p_x = &treeAnimator->g.origin.x;
      v17 = (float)(p_x[1] + (float)v14);
      v18 = (float)(p_x[2] + (float)v16);
      origin->x = *p_x + (float)v15;
      origin->y = v17;
      origin->z = v18;
    }
    else
    {
      presentableVehicleCar = this->presentableVehicleCar;
      if ( presentableVehicleCar != nullptr )
      {
        origin->x = presentableVehicleCar->origin.x;
        origin->y = presentableVehicleCar->origin.y;
        origin->z = presentableVehicleCar->origin.z;
      }
    }
  }
}


// ========================================================================
// ?GetMuzzlePosition@idVehicleWeapon@@QAAXAAVidVec3@@AAVidMat3@@W4attack_t@idWeapon@@@Z
// EA  : 0x82D3A540
// RVA : 0x00D3A540
// PDB : w:\tech5\tungsten\game\entities\vehicleweapon.cpp
// ========================================================================

void __fastcall idVehicleWeapon::GetMuzzlePosition(
        idVehicleWeapon *this,
        idVec3 *origin,
        idMat3 *axis,
        idWeapon::attack_t attackType)
{
  idTreeAnimator *treeAnimator; // r4
  idPresentableVehicle *presentableVehicleCar; // r3
  idWeapon *weapon; // r11
  float *decl; // r11
  double y; // fp9
  double z; // fp5
  double v14; // fp2
  double v15; // fp1

  idVehicleWeapon::ValidateTreeAnimator(this);
  treeAnimator = this->treeAnimator;
  if ( treeAnimator != nullptr )
  {
LABEL_5:
    if ( idWeapon::GetMuzzleFlashWorldTransform(this: this->weapon, ta: treeAnimator, attackType, origin, axis) )
      return;
    goto LABEL_6;
  }
  presentableVehicleCar = this->presentableVehicleCar;
  if ( presentableVehicleCar != nullptr
    && idPresentableAnimatedEntity::GetTreeAnimator(this: &presentableVehicleCar->idPresentableAnimatedEntity) != nullptr )
  {
    treeAnimator = idPresentableAnimatedEntity::GetTreeAnimator(this: &this->presentableVehicleCar->idPresentableAnimatedEntity);
    goto LABEL_5;
  }
LABEL_6:
  idVehicleWeapon::GetOrigin(this, origin);
  weapon = this->weapon;
  if ( weapon == nullptr || (decl = (float *)weapon->decl) == nullptr )
    decl = nullptr;
  y = origin->y;
  z = origin->z;
  v14 = (float)((float)(this->targetAxis.mat[2].y * decl[647])
              + (float)((float)(this->targetAxis.mat[0].y * decl[645]) + (float)(this->targetAxis.mat[1].y * decl[646])));
  v15 = (float)((float)(this->targetAxis.mat[2].z * decl[647])
              + (float)((float)(this->targetAxis.mat[0].z * decl[645]) + (float)(this->targetAxis.mat[1].z * decl[646])));
  origin->x = origin->x
            + (float)((float)(decl[645] * this->targetAxis.mat[0].x)
                    + (float)((float)(this->targetAxis.mat[1].x * decl[646])
                            + (float)(this->targetAxis.mat[2].x * decl[647])));
  origin->y = (float)y + (float)v14;
  origin->z = (float)z + (float)v15;
  axis->mat[0].x = this->targetAxis.mat[0].x;
  axis->mat[0].y = this->targetAxis.mat[0].y;
  axis->mat[0].z = this->targetAxis.mat[0].z;
  axis->mat[1].x = this->targetAxis.mat[1].x;
  axis->mat[1].y = this->targetAxis.mat[1].y;
  axis->mat[1].z = this->targetAxis.mat[1].z;
  axis->mat[2].x = this->targetAxis.mat[2].x;
  axis->mat[2].y = this->targetAxis.mat[2].y;
  axis->mat[2].z = this->targetAxis.mat[2].z;
  this->lastWeaponAxis.mat[0].x = axis->mat[0].x;
  this->lastWeaponAxis.mat[0].y = axis->mat[0].y;
  this->lastWeaponAxis.mat[0].z = axis->mat[0].z;
  this->lastWeaponAxis.mat[1].x = axis->mat[1].x;
  this->lastWeaponAxis.mat[1].y = axis->mat[1].y;
  this->lastWeaponAxis.mat[1].z = axis->mat[1].z;
  this->lastWeaponAxis.mat[2].x = axis->mat[2].x;
  this->lastWeaponAxis.mat[2].y = axis->mat[2].y;
  this->lastWeaponAxis.mat[2].z = axis->mat[2].z;
}


// ========================================================================
// ?Fire@idVehicleWeapon@@QAA_NPAVidPresentable@@_N0MM111@Z
// EA  : 0x82D3A708
// RVA : 0x00D3A708
// PDB : w:\tech5\tungsten\game\entities\vehicleweapon.cpp
// ========================================================================

int __fastcall idVehicleWeapon::Fire(
        idVehicleWeapon *this,
        idPresentable *attacker,
        bool lockedOn,
        idPresentable *target,
        double damageScale,
        double addSpread,
        bool infiniteAmmo,
        bool beingRemoteFired,
        bool skipClientFireRecord,
        char a10,
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
        char a30)
{
  idWeapon *weapon; // r9
  idVehicleWeapon *dependentWeapon; // r11
  vehicleWeaponAnimState_t state; // r11
  char v40; // r11
  bool v41; // zf
  idWeapon *v42; // r11
  const idDeclInventory *decl; // r11
  int GameMs; // r3
  __int64 v45; // r11
  int v46; // r9
  idWeapon *v47; // r3
  __int64 v48; // r5
  idInventoryItem *v50; // r25
  idWeapon *v51; // r10
  const idDeclInventory *v52; // r11
  const idDeclInventory *v53; // r29
  idJobManager *v54; // r3
  idJob *JobByDecl; // r3
  idAmmoItem *v56; // r29
  int v57; // r3
  idWeapon *v58; // r10
  const idDeclInventory *v59; // r11
  const idDeclInventory *v60; // r11
  char v61; // r11
  idWeapon *v62; // r11
  const idDeclInventory *v63; // r29
  idWeapon *v64; // r11
  const idDeclInventory *v65; // r29
  idWeapon *v66; // r11
  const idDeclInventory *v67; // r11
  char v68; // r28
  double x; // fp0
  double y; // fp13
  double v71; // fp12
  idWeapon *v72; // r11
  const idDeclInventory *v73; // r11
  idThirdPersonCrosshair *Crosshair; // r3
  long double v75; // fp2
  idWeapon *v76; // r11
  const idDeclInventory *v77; // r11
  long double v78; // fp2
  idMat3 *v79; // r3
  double z; // fp6
  idPresentableVehicle *v81; // r3
  long double v82; // fp2
  idPresentable *Gunner; // r3
  idWeapon *v84; // r11
  const idDeclInventory *v85; // r11
  long double v86; // fp2
  double v87; // fp8
  double v88; // fp9
  double v89; // fp10
  double v90; // fp11
  presentableType_t v91; // r3
  char v92; // r10
  idPresentableVehicle *presentableVehicleCar; // r3
  idWeapon *v94; // r11
  const idDeclInventory *v95; // r11
  idFinishFireResults *v96; // r11
  int i; // ctr
  idWeapon *v98; // r29
  const idDeclProjectile *CurrentProjectileDecl; // r3
  idVehicle_Car *v100; // r4
  idLobbyBase *v101; // r3
  idPresentable *presentable; // r3
  int v103; // r3
  idLobbyBase *v104; // r3
  idPresentable *v105; // r3
  int v106; // r3
  idVehicle_Car *v107; // r4
  idWeapon *v108; // r10
  const idDeclInventory *v109; // r11
  idAmmoItem *ammoClip; // r29
  int v111; // r3
  idWeapon *v112; // r11
  const idDeclInventory *v113; // r11
  int v114; // r29
  idFXManager *v115; // [sp+8h] [-B88h]
  bool v116; // [sp+Fh] [-B81h]
  idWeapon::fireState_t fireState; // [sp+60h] [-B30h]
  idMat3 v118; // [sp+70h] [-B20h] BYREF
  idMat3 v119; // [sp+98h] [-AF8h] BYREF
  float v120; // [sp+BCh] [-AD4h]
  float v121; // [sp+C0h] [-AD0h]
  idFireParms v122; // [sp+D0h] [-AC0h] BYREF
  idFinishFireResults v123; // [sp+170h] [-A20h] BYREF
  idVec3 v124[4]; // [sp+1C0h] [-9D0h] BYREF
  idTestFireResults v125; // [sp+1F0h] [-9A0h] BYREF

  weapon = this->weapon;
  if ( weapon == nullptr
    || *(weapon->decl == nullptr ? (_BYTE *)2456 : (_BYTE *)&weapon->decl[4].itemGroupWorth) != 0 && a10 == 0 )
  {
    return 0;
  }
  dependentWeapon = this->dependentWeapon;
  if ( dependentWeapon == nullptr )
    dependentWeapon = this;
  state = dependentWeapon->animState.state;
  if ( state == VW_ANIM_IDLE || state == VW_ANIM_MANNED_IDLE || (v41 = state != VW_ANIM_NONE, v40 = 0, !v41) )
    v40 = 1;
  if ( v40 == 0 )
    return 0;
  fireState = weapon->fireState;
  if ( fireState != FIRESTATE_FIRING
    && (fireState != FIRESTATE_DELAYED_FIRE
     || this->launchDelayTime > idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED)) )
  {
    return 0;
  }
  if ( this->launchDelayTime != 0 )
  {
    this->launchDelayTime = 0;
  }
  else
  {
    v42 = this->weapon;
    if ( v42 == nullptr || (decl = v42->decl) == nullptr )
      decl = nullptr;
    if ( *(int *)&decl[2].vehicleJointName.baseBuffer[8] > 0 )
    {
      GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      LODWORD(v45) = clientGame;
      v46 = GameMs;
      clientGame->random.seed = 1664525 * clientGame->random.seed + 1013904223;
      v47 = this->weapon;
      if ( v47 == nullptr || (HIDWORD(v45) = v47->decl, HIDWORD(v45) == 0) )
        HIDWORD(v45) = 0;
      HIDWORD(v48) = 2;
      LODWORD(v48) = *(_DWORD *)(HIDWORD(v45) + 1312);
      LODWORD(v45) = (*(_DWORD *)v45 >> 10) & 0x7FFF;
      this->launchDelayTime = v46 - (int)(float)((float)((float)v45 * (float)v48) * (float)-0.000030518509);
      idWeapon::SetFireState(this: v47, fs: FIRESTATE_DELAYED_FIRE);
      return 0;
    }
  }
  if ( vehicle_weapon_rollDelay.valueInteger != 0
    && !this->spinupFire
    && (unsigned __int16)this->rollJointIndex.value != 0xFFFF
    && this->rollDelta < (double)this->maxRollSpeed )
  {
    idWeapon::SetFireState(this: this->weapon, fs: FIRESTATE_IDLE);
    return 0;
  }
  v50 = nullptr;
  if ( g_infiniteAmmo.valueInteger != 0 || g_permaInfiniteAmmo.valueInteger != 0 || skipClientFireRecord )
    goto LABEL_42;
  v51 = this->weapon;
  if ( v51 == nullptr || (v52 = v51->decl) == nullptr )
    v52 = nullptr;
  if ( HIBYTE(v52[1].textLength) != 0
    || (int)v51->decl[1].declSource <= 0
    || (unsigned __int8)idPresentableVehicle::GetHasInfiniteAmmo(this: this->presentableVehicleCar) != 0 )
  {
LABEL_42:
    idVehicleWeapon::GetMuzzlePosition(
      this,
      origin: (idVec3 *)&v119.mat[1].y,
      axis: &v118,
      attackType: this->weapon->attackType);
    if ( target == nullptr )
      goto LABEL_66;
    v58 = this->weapon;
    if ( v58 == nullptr || (v59 = v58->decl) == nullptr )
      v59 = nullptr;
    if ( v59[2].sellStack )
      goto LABEL_52;
    if ( v58 == nullptr || (v60 = v58->decl) == nullptr )
      v60 = nullptr;
    if ( *(&v60[2].sellStack + 1) && lockedOn )
LABEL_52:
      v61 = 1;
    else
LABEL_66:
      v61 = 0;
    v68 = v61;
    if ( (unsigned __int8)idVehicleWeapon::InRecentFrame(this) != 0 )
    {
      v72 = this->weapon;
      if ( v72 == nullptr || (v73 = v72->decl) == nullptr )
        v73 = nullptr;
      if ( *(float *)&v73[5].declSource <= 0.0 )
        goto LABEL_90;
      if ( v68 != 0 )
      {
        Crosshair = idPresentableVehicle::GetCrosshair(this: this->presentableVehicleCar);
        if ( idThirdPersonCrosshair::GetTargetPosition(this: Crosshair, pos: (idVec3 *)&v119.mat[2].z) )
        {
          v119.mat[0].x = v119.mat[2].z - v119.mat[1].y;
          v119.mat[0].z = v121 - v119.mat[2].x;
          v119.mat[0].y = v120 - v119.mat[1].z;
          idVec3::NormalizeFast(this: v119.mat);
          v76 = this->weapon;
          if ( v76 == nullptr || (v77 = v76->decl) == nullptr )
            v77 = nullptr;
          *(double *)&v75 = (float)(*(float *)&v77[5].declSource * idMath::M_DEG2RAD);
          v78 = cos(x: v75);
          if ( (float)((float)(v118.mat[0].y * v119.mat[0].y)
                     + (float)((float)(v118.mat[0].x * v119.mat[0].x) + (float)(v118.mat[0].z * v119.mat[0].z))) >= (double)(float)*(double *)&v78 )
          {
            v79 = idVec3::ToMat3(this: v124, result: &v119);
            v118.mat[0].x = v79->mat[0].x;
            v118.mat[0].y = v79->mat[0].y;
            v118.mat[0].z = v79->mat[0].z;
            v118.mat[1] = v79->mat[1];
            v118.mat[2].x = v79->mat[2].x;
            v118.mat[2].y = v79->mat[2].y;
            z = v79->mat[2].z;
LABEL_89:
            v118.mat[2].z = z;
          }
LABEL_90:
          idVehicleWeapon::PlayAnim(this, anim: VW_ANIM_FIRE);
          idFireParms::idFireParms(this: &v122);
          v122.damageScale = damageScale;
          if ( addSpread >= 0.0 )
            v122.addSpread = addSpread;
          else
            *((_BYTE *)&v122 + 128) |= 2u;
          if ( attacker == nullptr || (v91 = attacker->GetType(this: attacker), v92 = 1, v91 != PRESENTABLE_PLAYER) )
            v92 = 0;
          presentableVehicleCar = this->presentableVehicleCar;
          *((_BYTE *)&v122 + 128) = (16 * v92) & 0x10 | *((_BYTE *)&v122 + 128) & 0xEF;
          *((_BYTE *)&v122 + 129) = ((presentableVehicleCar != nullptr) << 6) & 0x40 | *((_BYTE *)&v122 + 129) & 0xBF;
          if ( g_infiniteAmmo.valueInteger != 0
            || g_permaInfiniteAmmo.valueInteger != 0
            || (unsigned __int8)idPresentableVehicle::GetHasInfiniteAmmo(this: presentableVehicleCar) != 0 )
          {
            goto LABEL_104;
          }
          v94 = this->weapon;
          if ( v94 == nullptr || (v95 = v94->decl) == nullptr )
            v95 = nullptr;
          if ( HIBYTE(v95[1].textLength) != 0 || skipClientFireRecord )
LABEL_104:
            *((_BYTE *)&v122 + 128) |= 0x20u;
          v122.wepDef = (const idDeclWeapon *)this->weapon->decl;
          memset(&v125, 0, sizeof(v125));
          v96 = &v123;
          v123.numProjectiles = 0;
          for ( i = 16; i != 0; --i )
          {
            v96 = (idFinishFireResults *)((char *)v96 + 4);
            v96->numProjectiles = 0;
          }
          v122.ignoreEntityNum = this->presentableVehicleCar->entityNumber;
          if ( idPresentablePtr<idPresentableProjectile>::operator->(this: &this->presentable) != nullptr )
            idPresentablePtr<idPresentableProjectile>::operator->(this: &this->presentable);
          idWeapon::Fire(
            this: this->weapon,
            attacker,
            target: v68 == 0 ? nullptr : target,
            start: (const idVec3 *)&v119.mat[1].y,
            fireAxis: &v118,
            fp: &v122,
            tfr: &v125,
            ffr: &v123,
            fxMgr: v115,
            secondaryAmmo: v116);
          if ( this->presentableVehicleCar != nullptr && a30 == 0 )
          {
            v98 = this->weapon;
            CurrentProjectileDecl = idWeapon::GetCurrentProjectileDecl(this: v98, secondaryAmmo: false);
            idPresentableVehicle::RecordClientFire(
              this: this->presentableVehicleCar,
              weapon: v98,
              projDecl: CurrentProjectileDecl,
              fp: &v122,
              tfr: &v125,
              ffr: &v123);
          }
          if ( this->vehicle != nullptr )
          {
            if ( common->IsMultiplayer(this: common) )
            {
              v101 = session->GetActingGameStateLobbyBase(this: session);
              if ( v101->GetMatchParms(this: v101)->gameType == 2 )
              {
                presentable = this->vehicle->presentable;
                v103 = presentable != nullptr ? (int)presentable->GetVehicleInterface(this: presentable) : 0;
                if ( *(float *)(v103 + 17956) != 1.0 )
                {
                  v100 = idVehicle_Car::CastTo(c: (idVehicle_Car *)this->presentableVehicleCar->entity);
                  if ( v100 != nullptr )
                    idRageMetrics::AddOverAmmoSP(this: clientGame->rageMetrics, car: v100);
                }
              }
            }
            if ( ((unsigned __int8 (__fastcall *)(idCommon *, idVehicle_Car *))common->IsMultiplayer)(
                   a1: common,
                   a2: v100) != 0 )
            {
              v104 = session->GetActingGameStateLobbyBase(this: session);
              if ( v104->GetMatchParms(this: v104)->gameType == 2 )
              {
                v105 = this->vehicle->presentable;
                v106 = v105 != nullptr ? (int)v105->GetVehicleInterface(this: v105) : 0;
                if ( *(float *)(v106 + 17964) != 1.0 )
                {
                  v107 = idVehicle_Car::CastTo(c: (idVehicle_Car *)this->presentableVehicleCar->entity);
                  if ( v107 != nullptr )
                    idRageMetrics::AddFasterFasterSP(this: clientGame->rageMetrics, car: v107);
                }
              }
            }
          }
          if ( g_infiniteAmmo.valueInteger == 0
            && g_permaInfiniteAmmo.valueInteger == 0
            && (int)this->weapon->decl[1].declSource > 0
            && (unsigned __int8)idPresentableVehicle::GetHasInfiniteAmmo(this: this->presentableVehicleCar) == 0 )
          {
            v108 = this->weapon;
            if ( v108 == nullptr || (v109 = v108->decl) == nullptr )
              v109 = nullptr;
            if ( HIBYTE(v109[1].textLength) == 0 && v50 != nullptr )
            {
              idInventoryItem::ModifyCount(this: v50, amount: -(int)v108->decl[1].declSource);
              ammoClip = this->weapon->ammoClip;
              v111 = v50->GetCount(this: v50);
              idInventoryItem::SetCount(this: &ammoClip->idInventoryItem, amount: v111);
            }
          }
          if ( this->remoteFireWeapon != nullptr && this->remoteFireTime == 0 )
          {
            if ( attacker != nullptr )
              this->remoteFireAttacker.spawnId = attacker->spawnId;
            else
              this->remoteFireAttacker.spawnId = 0;
            this->remoteFireLockedOn = lockedOn;
            if ( target != nullptr )
              this->remoteFireTarget.spawnId = target->spawnId;
            else
              this->remoteFireTarget.spawnId = 0;
            v112 = this->weapon;
            this->remoteFireDamageScale = damageScale;
            this->remoteFireAddSpread = addSpread;
            this->remoteFireInfiniteAmmo = skipClientFireRecord;
            if ( v112 == nullptr || (v113 = v112->decl) == nullptr )
              v113 = nullptr;
            v114 = (int)(float)(*(float *)&v113[4].itemGroup * (float)1000.0);
            this->remoteFireTime = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) + v114;
          }
          ++this->sequenceFired;
          idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v122.targetList);
          return 1;
        }
      }
      v81 = this->presentableVehicleCar;
      if ( v81 == nullptr )
        goto LABEL_90;
      if ( idPresentableVehicle::GetGunner(this: v81) != nullptr )
      {
        Gunner = idPresentableVehicle::GetGunner(this: this->presentableVehicleCar);
        if ( Gunner->GetPlayerInterface_2(this: Gunner) != nullptr )
          goto LABEL_90;
      }
      v84 = this->weapon;
      if ( v84 == nullptr || (v85 = v84->decl) == nullptr )
        v85 = nullptr;
      *(double *)&v82 = (float)(*(float *)&v85[5].declSource * idMath::M_DEG2RAD);
      v86 = cos(x: v82);
      if ( (float)((float)(v118.mat[0].x * this->targetAxis.mat[0].x)
                 + (float)((float)(this->targetAxis.mat[0].z * v118.mat[0].z)
                         + (float)(this->targetAxis.mat[0].y * v118.mat[0].y))) < (double)(float)*(double *)&v86 )
        goto LABEL_90;
      x = this->targetAxis.mat[0].x;
      y = this->targetAxis.mat[0].y;
      v71 = this->targetAxis.mat[0].z;
    }
    else
    {
      x = this->targetAxis.mat[0].x;
      y = this->targetAxis.mat[0].y;
      v71 = this->targetAxis.mat[0].z;
    }
    v87 = this->targetAxis.mat[2].x;
    v88 = this->targetAxis.mat[1].z;
    v89 = this->targetAxis.mat[1].y;
    v90 = this->targetAxis.mat[1].x;
    z = this->targetAxis.mat[2].z;
    v118.mat[2].y = this->targetAxis.mat[2].y;
    v118.mat[2].x = v87;
    v118.mat[1].z = v88;
    v118.mat[1].y = v89;
    v118.mat[1].x = v90;
    v118.mat[0].z = v71;
    v118.mat[0].y = y;
    v118.mat[0].x = x;
    goto LABEL_89;
  }
  v53 = this->weapon->ammoClip->decl;
  v54 = (idJobManager *)this->presentableVehicleCar->GetInventory(this: this->presentableVehicleCar);
  JobByDecl = idJobManager::FindJobByDecl(this: v54, jobDecl: (const idDeclJob *)v53);
  v50 = (idInventoryItem *)JobByDecl;
  if ( JobByDecl != nullptr && ((int (__fastcall *)(idJob *))JobByDecl->__vftable[2].dtr_idClass)(a1: JobByDecl) > 0 )
  {
    v56 = this->weapon->ammoClip;
    v57 = v50->GetCount(this: v50);
    idInventoryItem::SetCount(this: &v56->idInventoryItem, amount: v57);
    goto LABEL_42;
  }
  idWeapon::SetFireState(this: this->weapon, fs: FIRESTATE_IDLE);
  v62 = this->weapon;
  if ( v62 == nullptr || (v63 = v62->decl) == nullptr )
    v63 = nullptr;
  if ( idPresentable::GetCurrentSoundShader(
         this: &this->presentableVehicleCar->idPresentableAnimatedEntity,
         channel: (const soundChannel_t)this->fireSoundChannel) != v63[4].hoverSound )
  {
    v64 = this->weapon;
    if ( v64 == nullptr || (v65 = v64->decl) == nullptr )
      v65 = nullptr;
    if ( idPresentable::GetCurrentSoundShader(
           this: &this->presentableVehicleCar->idPresentableAnimatedEntity,
           channel: (const soundChannel_t)this->fireSoundChannel) != v65[4].dropSound )
    {
      v66 = this->weapon;
      if ( v66 == nullptr || (v67 = v66->decl) == nullptr )
        v67 = nullptr;
      this->presentableVehicleCar->StartSoundShader(
        this: this->presentableVehicleCar,
        a2: this->fireSoundChannel,
        a3: v67[4].hoverSound,
        a4: 0,
        a5: 0);
    }
  }
  idPresentableVehicle::WeaponFiredWithNoAmmo(this: this->presentableVehicleCar);
  return 0;
}


// ========================================================================
// __unwind$493453
// EA  : 0x82D3B334
// RVA : 0x00D3B334
// PDB : w:\tech5\tungsten\game\entities\vehicleweapon.cpp
// ========================================================================

void _unwind_493453()
{
  int v0; // r12

  idFireParms::~idFireParms(this: (idAI2::idAIVolatile::idAIEventInfo *)(v0 - 2960 + 208));
}


// ========================================================================
// ?SerializeNonPredictionState@idVehicleWeapon@@QAAXAAVidSerializer@@@Z
// EA  : 0x82D3B360
// RVA : 0x00D3B360
// PDB : w:\tech5\tungsten\game\entities\vehicleweapon.cpp
// ========================================================================

void __fastcall idVehicleWeapon::SerializeNonPredictionState(idVehicleWeapon *this, idSerializer *ser)
{
  if ( !ser->writing )
    idVehicleWeapon::ClientInit(this);
}


// ========================================================================
// ?UpdateLaserSight@idVehicleWeapon@@QAAXXZ
// EA  : 0x82D3B378
// RVA : 0x00D3B378
// PDB : w:\tech5\tungsten\game\entities\vehicleweapon.cpp
// ========================================================================

void __fastcall idVehicleWeapon::UpdateLaserSight(idVehicleWeapon *this)
{
  idWeapon *weapon; // r11
  const idDeclInventory *decl; // r10
  idLaserSight *p_laserSight; // r31
  int GameMs; // r3
  idVec3 v6; // [sp+50h] [-F0h] BYREF
  idVec3 v7; // [sp+60h] [-E0h] BYREF
  idMat3 v8; // [sp+70h] [-D0h] BYREF
  trace_t v9; // [sp+A0h] [-A0h] BYREF

  weapon = this->weapon;
  if ( weapon == nullptr || (decl = weapon->decl) == nullptr )
    decl = nullptr;
  if ( BYTE1(decl[4].itemUse) == 1 )
  {
    idVehicleWeapon::GetMuzzlePosition(this, origin: &v6, axis: &v8, attackType: weapon->attackType);
    v7.x = v6.x + (float)(v8.mat[0].x * (float)100000.0);
    v7.y = v6.y + (float)(v8.mat[0].y * (float)100000.0);
    v7.z = v6.z + (float)(v8.mat[0].z * (float)100000.0);
    idClip::TracePoint(
      this: &clientGame->clip,
      result: &v9,
      start: &v6,
      end: &v7,
      clipMask: 8462469,
      passEntityNumber: 0);
    p_laserSight = &this->laserSight;
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    idLaserSight::Show(this: p_laserSight, startTime: GameMs);
    idLaserSight::Update(
      this: p_laserSight,
      startPos: &v6,
      endPos: &v9.endpos,
      axis: &mat3_identity,
      sizeScale: 1.0,
      fade: 1.0);
  }
}


// ========================================================================
// ?TestClearShot@idVehicleWeapon@@QAAXVidVec3@@@Z
// EA  : 0x82D3B498
// RVA : 0x00D3B498
// PDB : w:\tech5\tungsten\game\entities\vehicleweapon.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idVehicleWeapon::TestClearShot(
        idVehicleWeapon *this,
        __int64 endpos,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        __int64 a8,
        __int64 a9,
        __int64 a10,
        __int64 a11,
        __int64 a12)
{
  unsigned __int64 v12; // r28
  idWeapon *weapon; // r11
  idClipQuery *p_deferredWeaponTrace; // r30
  unsigned __int64 index; // r11
  idClientGame *v17; // r9
  double v20; // fp4
  double v21; // fp7
  double v22; // fp3
  idColor *v23; // r27
  const idSphere *v24; // r5
  int v25; // [sp+8h] [-188h]
  bool v26; // [sp+Fh] [-181h]
  const char *v27; // [sp+10h] [-180h]
  int v28; // [sp+14h] [-17Ch]
  int v29; // [sp+18h] [-178h]
  int v30; // [sp+1Ch] [-174h]
  int v31; // [sp+20h] [-170h]
  int v32; // [sp+24h] [-16Ch]
  int v33; // [sp+28h] [-168h]
  int v34; // [sp+2Ch] [-164h]
  int v35; // [sp+30h] [-160h]
  int v36; // [sp+34h] [-15Ch]
  int v37; // [sp+38h] [-158h]
  int v38; // [sp+3Ch] [-154h]
  int v39; // [sp+40h] [-150h]
  int v40; // [sp+44h] [-14Ch]
  int v41; // [sp+48h] [-148h]
  int v42; // [sp+4Ch] [-144h]
  int v43; // [sp+50h] [-140h]
  int v44; // [sp+58h] [-138h]
  int v45; // [sp+60h] [-130h]
  idVec3 v46; // [sp+70h] [-120h] BYREF
  float v47[4]; // [sp+80h] [-110h] BYREF
  float v48[4]; // [sp+90h] [-100h] BYREF
  char v49; // [sp+A0h] [-F0h] BYREF
  idMat3 v50; // [sp+B0h] [-E0h] BYREF
  trace_t v51; // [sp+E0h] [-B0h] BYREF

  a11 = *(__int64 *)((char *)&endpos + 4);
  HIDWORD(endpos) = &v46;
  weapon = this->weapon;
  a12 = endpos;
  idVehicleWeapon::GetMuzzlePosition(this, origin: &v46, axis: &v50, attackType: weapon->attackType);
  LODWORD(v12) = 0;
  this->hasClearShot = false;
  p_deferredWeaponTrace = &this->deferredWeaponTrace;
  if ( (unsigned __int8)idClip::QueryIsValid(this: &clientGame->clip, clipQuery: &this->deferredWeaponTrace) != 0 )
  {
    index = p_deferredWeaponTrace->index;
    v17 = clientGame;
    p_deferredWeaponTrace->index = v12;
    idCollisionModelManager::GetContentsResult(
      this: collisionModelManager,
      result: &v51,
      query: &v17->clip.collisionQueries[index & 0xFFF].query,
      peek: false);
    _FP7 = (float)((float)((float)((float)(v46.x - *(float *)&a11) * (float)(v46.x - *(float *)&a11))
                         + (float)((float)((float)(v46.z - *(float *)&a12) * (float)(v46.z - *(float *)&a12))
                                 + (float)((float)(v46.y - *((float *)&a11 + 1)) * (float)(v46.y - *((float *)&a11 + 1)))))
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm { fsel      f5, f7, f8, f13 }
    v20 = __frsqrte(_FP5);
    v21 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v20
                                                                                        * (float)((float)((float)((float)(v46.x - *(float *)&a11) * (float)(v46.x - *(float *)&a11)) + (float)((float)((float)(v46.z - *(float *)&a12) * (float)(v46.z - *(float *)&a12)) + (float)((float)(v46.y - *((float *)&a11 + 1)) * (float)(v46.y - *((float *)&a11 + 1)))))
                                                                                                * (float)0.5))
                                                                                * (float)v20)
                                                                        - (float)1.5)
                                                        * (float)v20)
                                                * (float)((float)((float)((float)(v46.x - *(float *)&a11)
                                                                        * (float)(v46.x - *(float *)&a11))
                                                                + (float)((float)((float)(v46.z - *(float *)&a12)
                                                                                * (float)(v46.z - *(float *)&a12))
                                                                        + (float)((float)(v46.y - *((float *)&a11 + 1))
                                                                                * (float)(v46.y - *((float *)&a11 + 1)))))
                                                        * (float)0.5))
                                        * (float)((float)-(float)((float)((float)((float)v20
                                                                                * (float)((float)((float)((float)(v46.x - *(float *)&a11) * (float)(v46.x - *(float *)&a11))
                                                                                                + (float)((float)((float)(v46.z - *(float *)&a12) * (float)(v46.z - *(float *)&a12)) + (float)((float)(v46.y - *((float *)&a11 + 1)) * (float)(v46.y - *((float *)&a11 + 1)))))
                                                                                        * (float)0.5))
                                                                        * (float)v20)
                                                                - (float)1.5)
                                                * (float)v20))
                                - (float)1.5)
                * (float)((float)-(float)((float)((float)((float)v20
                                                        * (float)((float)((float)((float)(v46.x - *(float *)&a11)
                                                                                * (float)(v46.x - *(float *)&a11))
                                                                        + (float)((float)((float)(v46.z - *(float *)&a12)
                                                                                        * (float)(v46.z - *(float *)&a12))
                                                                                + (float)((float)(v46.y
                                                                                                - *((float *)&a11 + 1))
                                                                                        * (float)(v46.y
                                                                                                - *((float *)&a11 + 1)))))
                                                                * (float)0.5))
                                                * (float)v20)
                                        - (float)1.5)
                        * (float)v20));
    v22 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v20 * (float)((float)((float)((float)(v46.x - *(float *)&a11) * (float)(v46.x - *(float *)&a11)) + (float)((float)((float)(v46.z - *(float *)&a12) * (float)(v46.z - *(float *)&a12)) + (float)((float)(v46.y - *((float *)&a11 + 1)) * (float)(v46.y - *((float *)&a11 + 1))))) * (float)0.5)) * (float)v20) - (float)1.5) * (float)v20)
                                                                                                * (float)((float)((float)((float)(v46.x - *(float *)&a11) * (float)(v46.x - *(float *)&a11)) + (float)((float)((float)(v46.z - *(float *)&a12) * (float)(v46.z - *(float *)&a12)) + (float)((float)(v46.y - *((float *)&a11 + 1)) * (float)(v46.y - *((float *)&a11 + 1))))) * (float)0.5))
                                                                                        * (float)((float)-(float)((float)((float)((float)v20 * (float)((float)((float)((float)(v46.x - *(float *)&a11) * (float)(v46.x - *(float *)&a11)) + (float)((float)((float)(v46.z - *(float *)&a12) * (float)(v46.z - *(float *)&a12)) + (float)((float)(v46.y - *((float *)&a11 + 1)) * (float)(v46.y - *((float *)&a11 + 1))))) * (float)0.5)) * (float)v20) - (float)1.5)
                                                                                                * (float)v20))
                                                                                - (float)1.5)
                                                                * (float)((float)-(float)((float)((float)((float)v20 * (float)((float)((float)((float)(v46.x - *(float *)&a11) * (float)(v46.x - *(float *)&a11)) + (float)((float)((float)(v46.z - *(float *)&a12) * (float)(v46.z - *(float *)&a12)) + (float)((float)(v46.y - *((float *)&a11 + 1)) * (float)(v46.y - *((float *)&a11 + 1))))) * (float)0.5))
                                                                                                * (float)v20)
                                                                                        - (float)1.5)
                                                                        * (float)v20))
                                                        * (float)((float)((float)((float)(v46.x - *(float *)&a11)
                                                                                * (float)(v46.x - *(float *)&a11))
                                                                        + (float)((float)((float)(v46.z - *(float *)&a12)
                                                                                        * (float)(v46.z - *(float *)&a12))
                                                                                + (float)((float)(v46.y
                                                                                                - *((float *)&a11 + 1))
                                                                                        * (float)(v46.y
                                                                                                - *((float *)&a11 + 1)))))
                                                                * (float)0.5))
                                                * (float)v21)
                                        - (float)1.5)
                        * (float)v21)
                * (float)((float)((float)(v46.x - *(float *)&a11) * (float)(v46.x - *(float *)&a11))
                        + (float)((float)((float)(v46.z - *(float *)&a12) * (float)(v46.z - *(float *)&a12))
                                + (float)((float)(v46.y - *((float *)&a11 + 1)) * (float)(v46.y - *((float *)&a11 + 1))))));
    if ( (float)-(float)((float)(v51.fraction * (float)v22) - (float)v22) <= 200.0 )
    {
      this->hasClearShot = true;
      if ( vai_showEnemyVisibleTrace.valueInteger != 0 )
      {
        v23 = &idColor::colorGreen;
        clientGame->renderWorld->DebugLine(
          this: clientGame->renderWorld,
          a2: (const idVec4 *)&idColor::colorGreen,
          a3: &v46,
          a4: (const idVec3 *)&a11,
          a5: 0,
          a6: false);
        v24 = (const idSphere *)v48;
        v48[0] = *(float *)&a11;
        v48[1] = *((float *)&a11 + 1);
        v48[3] = 20.0;
        v48[2] = *(float *)&a12;
        goto LABEL_7;
      }
    }
    else if ( vai_showEnemyVisibleTrace.valueInteger != 0 )
    {
      v23 = &idColor::colorRed;
      clientGame->renderWorld->DebugLine(
        this: clientGame->renderWorld,
        a2: (const idVec4 *)&idColor::colorRed,
        a3: &v46,
        a4: (const idVec3 *)&a11,
        a5: 0,
        a6: false);
      v24 = (const idSphere *)v47;
      v47[1] = *((float *)&a11 + 1);
      v47[2] = *(float *)&a12;
      v47[3] = 20.0;
      v47[0] = *(float *)&a11;
LABEL_7:
      clientGame->renderWorld->DebugSphere(
        this: clientGame->renderWorld,
        a2: (const idVec4 *)v23,
        a3: v24,
        a4: 12,
        a5: 0,
        a6: false);
    }
  }
  p_deferredWeaponTrace->index = *(unsigned __int64 *)&idClip::Translation(
                                                         this: (idClip *)&v49,
                                                         result: &clientGame->clip,
                                                         a3: nullptr,
                                                         start: &v46,
                                                         end: (const idVec3 *)&a11,
                                                         clipModel: nullptr,
                                                         startAxis: &mat3_identity,
                                                         clipMask: 8462469,
                                                         passEntityNumber: v25,
                                                         moveClipModel: v26,
                                                         userName: v27,
                                                         a12: v28,
                                                         a13: v29,
                                                         a14: v30,
                                                         a15: v31,
                                                         a16: v32,
                                                         a17: v33,
                                                         a18: v34,
                                                         a19: v35,
                                                         a20: v36,
                                                         a21: v37,
                                                         a22: v38,
                                                         a23: v39,
                                                         a24: v40,
                                                         a25: v41,
                                                         a26: v42,
                                                         a27: v43,
                                                         a28: this->vehicle->entityNumber,
                                                         a29: v44,
                                                         a30: false,
                                                         a31: v45,
                                                         a32: (int)"w:\\tech5\\tungsten\\game\\entities\\VehicleWeapon.cpp(146"
                                                              "4) : Translation")->world;
}


// ========================================================================
// ?SetTarget@idVehicleWeapon@@QAAXABVidVec3@@@Z
// EA  : 0x82D3B730
// RVA : 0x00D3B730
// PDB : w:\tech5\tungsten\game\entities\vehicleweapon.cpp
// ========================================================================

void __fastcall idVehicleWeapon::SetTarget(idVehicleWeapon *this, const idVec3 *targetPos)
{
  double y; // fp12
  double z; // fp11
  double x; // fp4
  double v7; // fp3
  double v8; // fp2
  double v9; // fp10
  double v10; // fp9
  double v11; // fp8
  idTreeAnimator *treeAnimator; // r11
  double v13; // fp29
  double v14; // fp28
  double v15; // fp27
  float *p_deferredAxis; // r11
  double v17; // fp12
  double v18; // fp13
  double v19; // fp0
  float *v20; // r3
  double v21; // fp11
  double v22; // fp10
  double v23; // fp0
  double v24; // fp8
  double v25; // fp7
  idAngles *v26; // r28
  idAngles *v27; // r3
  double v28; // fp9
  double v29; // fp7
  double v30; // fp5
  double v31; // fp4
  __int16 value; // r8
  int v33; // r9
  idVehicleWeapon *dependentWeapon; // r10
  const idMat3 *v35; // r3
  const idIndex<short,enum invalidJointIndex_t> *v36; // r5
  idTreeAnimator *v37; // r3
  idTreeAnimator *v38; // r11
  double v39; // fp12
  float *p_axis; // r11
  double v41; // fp11
  double v42; // fp8
  double v43; // fp6
  idQuat *v44; // r3
  int v45; // r30
  idTreeAnimator *v46; // r11
  double v47; // fp0
  float *v48; // r11
  double v49; // fp11
  double v50; // fp8
  double v51; // fp6
  long double v52; // fp2
  idVec3 *v53; // r10
  idVec3 *v54; // r11
  int i; // ctr
  long double v56; // fp2
  idQuat *v57; // r3
  const idMat3 *v58; // r3
  const idMat3 *v59; // r3
  idMat3 v60; // [sp+50h] [-190h] BYREF
  float v61; // [sp+74h] [-16Ch]
  float v62; // [sp+78h] [-168h]
  float w; // [sp+7Ch] [-164h]
  idMat3 v64; // [sp+80h] [-160h] BYREF
  float v65; // [sp+A4h] [-13Ch]
  float v66; // [sp+A8h] [-138h]
  float v67; // [sp+ACh] [-134h]
  float v68; // [sp+B0h] [-130h]
  idVec3 v69; // [sp+B8h] [-128h] BYREF
  idVec3 v70; // [sp+C8h] [-118h] BYREF
  idVec3 v71; // [sp+D8h] [-108h] BYREF
  idMat3 v72; // [sp+F0h] [-F0h] BYREF
  idMat3 v73; // [sp+130h] [-B0h] BYREF
  idMat3 v74[2]; // [sp+160h] [-80h] BYREF

  idVehicleWeapon::GetOrigin(this, origin: &v71);
  idVehicleWeapon::ValidateTreeAnimator(this);
  y = this->lastTargetPos.y;
  z = this->lastTargetPos.z;
  x = v71.x;
  v7 = v71.y;
  v8 = v71.z;
  v9 = (float)((float)(targetPos->y - this->lastTargetPos.y) * vehicle_weapon_lag.valueFloat);
  v10 = (float)((float)(targetPos->z - this->lastTargetPos.z) * vehicle_weapon_lag.valueFloat);
  v11 = (float)(this->lastTargetPos.x
              + (float)((float)(targetPos->x - this->lastTargetPos.x) * vehicle_weapon_lag.valueFloat));
  this->lastTargetPos.x = this->lastTargetPos.x
                        + (float)((float)(targetPos->x - this->lastTargetPos.x) * vehicle_weapon_lag.valueFloat);
  this->lastTargetPos.y = (float)y + (float)v9;
  this->lastTargetPos.z = (float)z + (float)v10;
  treeAnimator = this->treeAnimator;
  v13 = (float)((float)v11 - (float)x);
  v14 = (float)((float)((float)y + (float)v9) - (float)v7);
  v15 = (float)((float)((float)z + (float)v10) - (float)v8);
  if ( treeAnimator != nullptr )
  {
    if ( treeAnimator->useDeferredPosition )
      p_deferredAxis = (float *)&treeAnimator->deferredAxis;
    else
      p_deferredAxis = (float *)&treeAnimator->g.axis;
    v17 = p_deferredAxis[6];
    v18 = p_deferredAxis[7];
    v19 = p_deferredAxis[8];
  }
  else if ( idPresentablePtr<idPresentableProjectile>::operator->(this: &this->presentable) != nullptr )
  {
    v20 = (float *)idPresentablePtr<idPresentableProjectile>::operator->(this: &this->presentable);
    v17 = v20[39];
    v18 = v20[40];
    v19 = v20[41];
  }
  else
  {
    v19 = 1.0;
    v18 = 0.0;
    v17 = 0.0;
  }
  this->targetAxis.mat[0].x = v13;
  this->targetAxis.mat[0].y = v14;
  this->targetAxis.mat[0].z = v15;
  this->targetAxis.mat[2].y = v18;
  this->targetAxis.mat[2].x = v17;
  this->targetAxis.mat[2].z = v19;
  v21 = this->targetAxis.mat[2].y;
  v22 = this->targetAxis.mat[0].y;
  v23 = this->targetAxis.mat[0].z;
  v24 = (float)(this->targetAxis.mat[0].y * this->targetAxis.mat[2].z);
  v25 = (float)(this->targetAxis.mat[0].x * this->targetAxis.mat[2].y);
  this->targetAxis.mat[1].y = (float)(this->targetAxis.mat[0].x * this->targetAxis.mat[2].z)
                            - (float)((float)v17 * this->targetAxis.mat[0].z);
  this->targetAxis.mat[1].x = (float)((float)v23 * (float)v21) - (float)v24;
  this->targetAxis.mat[1].z = (float)((float)v17 * (float)v22) - (float)v25;
  idMat3::OrthoNormalizeSelf(this: &this->targetAxis);
  if ( this->treeAnimator != nullptr
    && ((unsigned __int16)this->pitchJointIndex.value < 0x8000u || (unsigned __int16)this->yawJointIndex.value < 0x8000u) )
  {
    if ( common->IsMultiplayer(this: common) || (unsigned __int8)idVehicleWeapon::InRecentFrame(this) != 0 )
    {
      v26 = idMat3::ToAngles(this: &v60, result: (idAngles *)&this->presentableVehicleCar->axis);
      v27 = idMat3::ToAngles(this: &v72, result: (idAngles *)&this->targetAxis);
      v28 = (float)(v27->roll - v26->roll);
      v29 = (float)(v27->yaw - v26->yaw);
      v60.mat[1].y = v27->pitch - v26->pitch;
      v60.mat[2].x = v28;
      v60.mat[1].z = v29;
      idAngles::Normalize180(this: (idAngles *)&v60.mat[1].y);
      v30 = v60.mat[1].z;
      v31 = v60.mat[1].y;
      this->targetAngles.roll = 0.0;
      this->targetAngles.yaw = v30;
      this->targetAngles.pitch = v31;
      value = this->pitchJointIndex.value;
      v33 = this->yawJointIndex.value;
      v60.mat[2].x = 0.0;
      if ( value == v33 )
      {
        dependentWeapon = this->dependentWeapon;
        if ( dependentWeapon == nullptr || dependentWeapon->pitchJointIndex.value != value )
        {
          v60.mat[0].z = 0.0;
          v60.mat[0].x = v60.mat[1].y;
          v60.mat[0].y = v60.mat[1].z;
          v35 = idAngles::ToMat3(this: (idAngles *)v74, result: &v60);
          idTreeAnimator::SetJointAxis(
            this: this->treeAnimator,
            pose: (animationPose_t)0,
            jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)this->pitchJointIndex.value,
            type: JOINTMOD_LOCAL,
            axis: v35);
        }
      }
      else
      {
        v64.mat[0].x = 0.0;
        v64.mat[0].y = 0.0;
        v64.mat[0].z = 0.0;
        v64.mat[1].x = 1.0;
        v36 = (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)this->yawJointIndex.value;
        v60.mat[2].z = 0.0;
        v37 = this->treeAnimator;
        v61 = 0.0;
        v62 = 0.0;
        w = 1.0;
        idTreeAnimator::GetWorldSpaceJointTransform(
          this: v37,
          pose: (animationPose_t)0,
          jointIndex: v36,
          origin: &v69,
          axis: v74);
        v38 = this->treeAnimator;
        v39 = (float)(targetPos->z - v69.z);
        if ( v38->useDeferredPosition )
          p_axis = (float *)&v38->deferredAxis;
        else
          p_axis = (float *)&v38->g.axis;
        v41 = p_axis[2];
        v42 = (float)((float)(*p_axis * (float)(targetPos->x - v69.x))
                    + (float)((float)(targetPos->y - v69.y) * p_axis[1]));
        v43 = (float)((float)((float)(targetPos->z - v69.z) * p_axis[5])
                    + (float)((float)(p_axis[3] * (float)(targetPos->x - v69.x))
                            + (float)((float)(targetPos->y - v69.y) * p_axis[4])));
        v60.mat[0].z = (float)((float)(targetPos->z - v69.z) * p_axis[8])
                     + (float)((float)(p_axis[6] * (float)(targetPos->x - v69.x))
                             + (float)((float)(targetPos->y - v69.y) * p_axis[7]));
        v60.mat[0].y = v43;
        v60.mat[0].x = (float)((float)v39 * (float)v41) + (float)v42;
        idVec3::ProjectOntoPlane(this: v60.mat, normal: &vec3_up, overBounce: 1.0);
        idVec3::NormalizeFast(this: v60.mat);
        v66 = vec3_up.x;
        v67 = vec3_up.y;
        v68 = vec3_up.z;
        v64.mat[1].y = v60.mat[0].x;
        v64.mat[1].z = v60.mat[0].y;
        v64.mat[2].x = v60.mat[0].z;
        v64.mat[2].y = (float)(vec3_up.y * v60.mat[0].z) - (float)(vec3_up.z * v60.mat[0].y);
        v64.mat[2].z = (float)(vec3_up.z * v60.mat[0].x) - (float)(vec3_up.x * v60.mat[0].z);
        v65 = (float)(vec3_up.x * v60.mat[0].y) - (float)(vec3_up.y * v60.mat[0].x);
        idVec3::NormalizeFast(this: (idVec3 *)&v64.mat[2].y);
        v44 = idMat3::ToQuat(this: &v72, result: (idQuat *)&v64.mat[1].y);
        v64.mat[0].x = v44->x;
        v64.mat[0].y = v44->y;
        v64.mat[0].z = v44->z;
        v64.mat[1].x = v44->w;
        v45 = (unsigned __int8)idVehicleWeapon::IsWeaponChange(this);
        if ( v45 == 0 && (unsigned __int16)this->pitchJointIndex.value < 0x8000u )
        {
          idTreeAnimator::GetWorldSpaceJointTransform(
            this: this->treeAnimator,
            pose: (animationPose_t)0,
            jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)this->pitchJointIndex.value,
            origin: &v70,
            axis: &v73);
          v46 = this->treeAnimator;
          v47 = (float)(targetPos->x - v70.x);
          if ( v46->useDeferredPosition )
            v48 = (float *)&v46->deferredAxis;
          else
            v48 = (float *)&v46->g.axis;
          v49 = *v48;
          v50 = (float)((float)((float)(targetPos->z - v70.z) * v48[2]) + (float)((float)(targetPos->y - v70.y) * v48[1]));
          v51 = (float)((float)(v48[3] * (float)(targetPos->x - v70.x))
                      + (float)((float)((float)(targetPos->z - v70.z) * v48[5])
                              + (float)((float)(targetPos->y - v70.y) * v48[4])));
          v60.mat[0].z = (float)(v48[6] * (float)(targetPos->x - v70.x))
                       + (float)((float)((float)(targetPos->z - v70.z) * v48[8])
                               + (float)((float)(targetPos->y - v70.y) * v48[7]));
          v60.mat[0].y = v51;
          v60.mat[0].x = (float)((float)v49 * (float)v47) + (float)v50;
          idVec3::ProjectOntoPlane(this: v60.mat, normal: (const idVec3 *)&v64.mat[2].y, overBounce: 1.0);
          idVec3::NormalizeFast(this: v60.mat);
          v53 = &v72.mat[1];
          v54 = &v64.mat[1];
          for ( i = 9; i != 0; --i )
          {
            v54 = (idVec3 *)((char *)v54 + 4);
            v53 = (idVec3 *)((char *)v53 + 4);
            v53->x = v54->x;
          }
          *(double *)&v52 = (float)((float)(v66 * v60.mat[0].x)
                                  + (float)((float)(v68 * v60.mat[0].z) + (float)(v67 * v60.mat[0].y)));
          v56 = acos(x: v52);
          idMat3::RotateSelf(
            this: (idMat3 *)&v72.mat[1].y,
            axis: (const idVec3 *)&v72.mat[2].y,
            angle: (float)-(float)((float)((float)3.1415927 * (float)0.5) - (float)*(double *)&v56));
          v57 = idMat3::ToQuat(this: &v72, result: (idQuat *)&v72.mat[1].y);
          v60.mat[2].z = v57->x;
          v61 = v57->y;
          v62 = v57->z;
          w = v57->w;
        }
        v58 = idQuat::ToMat3(this: (idQuat *)&v73, result: &v64);
        idTreeAnimator::SetJointAxis(
          this: this->treeAnimator,
          pose: (animationPose_t)0,
          jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)this->yawJointIndex.value,
          type: JOINTMOD_MODEL_OVERRIDE,
          axis: v58);
        if ( v45 == 0 && (unsigned __int16)this->pitchJointIndex.value < 0x8000u )
        {
          v59 = idQuat::ToMat3(this: (idQuat *)&v73, result: (idMat3 *)&v60.mat[2].z);
          idTreeAnimator::SetJointAxis(
            this: this->treeAnimator,
            pose: (animationPose_t)0,
            jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)this->pitchJointIndex.value,
            type: JOINTMOD_MODEL_OVERRIDE,
            axis: v59);
        }
      }
    }
  }
  else
  {
    this->targetAngles = ang_zero;
  }
}


// ========================================================================
// ?SetTargetWorldAngles@idVehicleWeapon@@QAAXVidAngles@@@Z
// EA  : 0x82D3BDA0
// RVA : 0x00D3BDA0
// PDB : w:\tech5\tungsten\game\entities\vehicleweapon.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idVehicleWeapon::SetTargetWorldAngles(
        idVehicleWeapon *this,
        __int64 angles,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        __int64 a8,
        __int64 a9,
        __int64 a10,
        __int64 a11,
        __int64 a12)
{
  unsigned int value; // r11
  idTreeAnimator *treeAnimator; // r3
  bool IsRendered; // r3
  char v16; // r11
  double v17; // fp13
  __int16 v18; // r8
  int v19; // r7
  idVehicleWeapon *dependentWeapon; // r11
  const idMat3 *v21; // r3
  const idIndex<short,enum invalidJointIndex_t> *v22; // r5
  idTreeAnimator *v23; // r3
  idTreeAnimator *v24; // r11
  float *p_deferredAxis; // r11
  double v26; // fp2
  double v27; // fp10
  double v28; // fp8
  idQuat *v29; // r3
  int v30; // r30
  idTreeAnimator *v31; // r11
  float *p_axis; // r11
  double v33; // fp2
  double v34; // fp10
  double v35; // fp8
  long double v36; // fp2
  int *v37; // r10
  idVec3 *v38; // r11
  int i; // ctr
  long double v40; // fp2
  idQuat *v41; // r3
  const idMat3 *v42; // r3
  const idMat3 *v43; // r3
  idMat3 v44; // [sp+50h] [-150h] BYREF
  float v45; // [sp+74h] [-12Ch]
  float v46; // [sp+78h] [-128h]
  float w; // [sp+7Ch] [-124h]
  idMat3 v48; // [sp+80h] [-120h] BYREF
  float v49; // [sp+A4h] [-FCh]
  float x; // [sp+A8h] [-F8h]
  float y; // [sp+ACh] [-F4h]
  float z; // [sp+B0h] [-F0h]
  int v53; // [sp+BCh] [-E4h] BYREF
  idMat3 v54; // [sp+C0h] [-E0h] BYREF
  idMat3 v55; // [sp+F0h] [-B0h] BYREF
  idVec3 v56; // [sp+118h] [-88h] BYREF
  idVec3 v57[2]; // [sp+128h] [-78h] BYREF
  idMat3 v58; // [sp+140h] [-60h] BYREF

  value = (unsigned __int16)this->pitchJointIndex.value;
  a11 = *(__int64 *)((char *)&angles + 4);
  a12 = angles;
  if ( value < 0x8000 || (unsigned __int16)this->yawJointIndex.value < 0x8000u )
  {
    idVehicleWeapon::ValidateTreeAnimator(this);
    if ( this->treeAnimator != nullptr )
    {
      idVehicleWeapon::ValidateTreeAnimator(this);
      treeAnimator = this->treeAnimator;
      if ( treeAnimator == nullptr || (IsRendered = idRenderModel::IsRendered(this: treeAnimator), v16 = 1, !IsRendered) )
        v16 = 0;
      if ( v16 != 0 )
      {
        v17 = *((float *)&a11 + 1);
        this->targetAngles.pitch = *(float *)&a11;
        this->targetAngles.yaw = v17;
        this->targetAngles.roll = 0.0;
        v18 = this->pitchJointIndex.value;
        v19 = this->yawJointIndex.value;
        *(float *)&a12 = 0.0;
        if ( v18 == v19 )
        {
          dependentWeapon = this->dependentWeapon;
          if ( dependentWeapon == nullptr || dependentWeapon->pitchJointIndex.value != v18 )
          {
            v44.mat[2].x = 0.0;
            *(_QWORD *)&v44.mat[1].y = a11;
            v21 = idAngles::ToMat3(this: (idAngles *)&v58, result: (idMat3 *)&v44.mat[1].y);
            idTreeAnimator::SetJointAxis(
              this: this->treeAnimator,
              pose: (animationPose_t)0,
              jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)this->pitchJointIndex.value,
              type: JOINTMOD_LOCAL,
              axis: v21);
          }
        }
        else
        {
          idAngles::ToForward(this: (idAngles *)&v44.mat[1].y, result: (idVec3 *)&a11);
          v44.mat[2].z = 0.0;
          v45 = 0.0;
          v46 = 0.0;
          v48.mat[0].x = 0.0;
          v22 = (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)this->yawJointIndex.value;
          v23 = this->treeAnimator;
          w = 1.0;
          v48.mat[0].y = 0.0;
          v48.mat[0].z = 0.0;
          v48.mat[1].x = 1.0;
          idTreeAnimator::GetWorldSpaceJointTransform(
            this: v23,
            pose: (animationPose_t)0,
            jointIndex: v22,
            origin: &v56,
            axis: &v58);
          v24 = this->treeAnimator;
          if ( v24->useDeferredPosition )
            p_deferredAxis = (float *)&v24->deferredAxis;
          else
            p_deferredAxis = (float *)&v24->g.axis;
          v26 = p_deferredAxis[2];
          v27 = (float)((float)(v44.mat[1].y * *p_deferredAxis) + (float)(v44.mat[1].z * p_deferredAxis[1]));
          v28 = (float)((float)(v44.mat[2].x * p_deferredAxis[5])
                      + (float)((float)(v44.mat[1].y * p_deferredAxis[3]) + (float)(v44.mat[1].z * p_deferredAxis[4])));
          v44.mat[0].z = (float)(v44.mat[2].x * p_deferredAxis[8])
                       + (float)((float)(v44.mat[1].y * p_deferredAxis[6]) + (float)(v44.mat[1].z * p_deferredAxis[7]));
          v44.mat[0].y = v28;
          v44.mat[0].x = (float)(v44.mat[2].x * (float)v26) + (float)v27;
          idVec3::ProjectOntoPlane(this: v44.mat, normal: &vec3_up, overBounce: 1.0);
          idVec3::NormalizeFast(this: v44.mat);
          y = vec3_up.y;
          x = vec3_up.x;
          z = vec3_up.z;
          v48.mat[1].y = v44.mat[0].x;
          v48.mat[1].z = v44.mat[0].y;
          v48.mat[2].x = v44.mat[0].z;
          v48.mat[2].z = (float)(vec3_up.z * v44.mat[0].x) - (float)(vec3_up.x * v44.mat[0].z);
          v49 = (float)(vec3_up.x * v44.mat[0].y) - (float)(vec3_up.y * v44.mat[0].x);
          v48.mat[2].y = (float)(vec3_up.y * v44.mat[0].z) - (float)(vec3_up.z * v44.mat[0].y);
          idVec3::NormalizeFast(this: (idVec3 *)&v48.mat[2].y);
          v29 = idMat3::ToQuat(this: &v44, result: (idQuat *)&v48.mat[1].y);
          v44.mat[2].z = v29->x;
          v45 = v29->y;
          v46 = v29->z;
          w = v29->w;
          v30 = (unsigned __int8)idVehicleWeapon::IsWeaponChange(this);
          if ( v30 == 0 )
          {
            idTreeAnimator::GetWorldSpaceJointTransform(
              this: this->treeAnimator,
              pose: (animationPose_t)0,
              jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)this->pitchJointIndex.value,
              origin: v57,
              axis: &v55);
            v31 = this->treeAnimator;
            if ( v31->useDeferredPosition )
              p_axis = (float *)&v31->deferredAxis;
            else
              p_axis = (float *)&v31->g.axis;
            v33 = p_axis[2];
            v34 = (float)((float)(v44.mat[1].y * *p_axis) + (float)(v44.mat[1].z * p_axis[1]));
            v35 = (float)((float)(v44.mat[2].x * p_axis[5])
                        + (float)((float)(v44.mat[1].y * p_axis[3]) + (float)(v44.mat[1].z * p_axis[4])));
            v44.mat[0].z = (float)(v44.mat[2].x * p_axis[8])
                         + (float)((float)(v44.mat[1].y * p_axis[6]) + (float)(v44.mat[1].z * p_axis[7]));
            v44.mat[0].y = v35;
            v44.mat[0].x = (float)(v44.mat[2].x * (float)v33) + (float)v34;
            idVec3::ProjectOntoPlane(this: v44.mat, normal: (const idVec3 *)&v48.mat[2].y, overBounce: 1.0);
            idVec3::NormalizeFast(this: v44.mat);
            v37 = &v53;
            v38 = &v48.mat[1];
            for ( i = 9; i != 0; --i )
            {
              v38 = (idVec3 *)((char *)v38 + 4);
              *++v37 = LODWORD(v38->x);
            }
            *(double *)&v36 = (float)((float)(z * v44.mat[0].z)
                                    + (float)((float)(y * v44.mat[0].y) + (float)(x * v44.mat[0].x)));
            v40 = acos(x: v36);
            idMat3::RotateSelf(
              this: &v54,
              axis: &v54.mat[1],
              angle: (float)-(float)((float)((float)3.1415927 * (float)0.5) - (float)*(double *)&v40));
            v41 = idMat3::ToQuat(this: &v44, result: (idQuat *)&v54);
            v48.mat[0].x = v41->x;
            v48.mat[0].y = v41->y;
            v48.mat[0].z = v41->z;
            v48.mat[1].x = v41->w;
          }
          v42 = idQuat::ToMat3(this: (idQuat *)&v55, result: (idMat3 *)&v44.mat[2].z);
          idTreeAnimator::SetJointAxis(
            this: this->treeAnimator,
            pose: (animationPose_t)0,
            jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)this->yawJointIndex.value,
            type: JOINTMOD_MODEL_OVERRIDE,
            axis: v42);
          if ( v30 == 0 )
          {
            v43 = idQuat::ToMat3(this: (idQuat *)&v55, result: &v48);
            idTreeAnimator::SetJointAxis(
              this: this->treeAnimator,
              pose: (animationPose_t)0,
              jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)this->pitchJointIndex.value,
              type: JOINTMOD_MODEL_OVERRIDE,
              axis: v43);
          }
        }
      }
    }
    else
    {
      this->targetAngles = ang_zero;
    }
    this->targetAxis = *idAngles::ToMat3(this: (idAngles *)&v55, result: (idMat3 *)&this->targetAngles);
  }
}


// ========================================================================
// ?UpdateState@idVehicleWeapon@@QAAXXZ
// EA  : 0x82D3C268
// RVA : 0x00D3C268
// PDB : w:\tech5\tungsten\game\entities\vehicleweapon.cpp
// ========================================================================

void __fastcall idVehicleWeapon::UpdateState(idVehicleWeapon *this)
{
  bool remoteFireInfiniteAmmo; // r30
  double remoteFireAddSpread; // fp31
  double remoteFireDamageScale; // fp30
  idPresentable *v5; // r29
  bool remoteFireLockedOn; // r27
  idPresentable *v7; // r3
  bool v8; // r8
  bool v9; // r7
  idWeapon *weapon; // r3
  idFXManager *p_fxManager; // r5
  idWeapon *v12; // r11
  idWeapon::fireState_t fireState; // r10
  int nextFireTime; // r27
  int GameMs; // r26
  int v16; // r27
  int v17; // r11
  double maxRollSpeed; // fp0
  double v19; // fp9
  double v20; // fp12
  double rollAngle; // fp13
  double v22; // fp0
  char *v23; // r10
  float *p_z; // r11
  int i; // ctr
  idWeapon *v26; // r11
  const idDeclInventory *decl; // r10
  const idDeclInventory *v28; // r11
  int lowDuration; // r11
  float *p_x; // r11
  double v31; // fp4
  double v32; // fp3
  double v33; // fp2
  float *v34; // r11
  idTreeAnimator *treeAnimator; // r3
  int v36; // [sp+8h] [-118h]
  int v37; // [sp+Ch] [-114h]
  int v38; // [sp+10h] [-110h]
  int v39; // [sp+14h] [-10Ch]
  int v40; // [sp+18h] [-108h]
  int v41; // [sp+1Ch] [-104h]
  int v42; // [sp+20h] [-100h]
  int v43; // [sp+24h] [-FCh]
  int v44; // [sp+28h] [-F8h]
  int v45; // [sp+2Ch] [-F4h]
  int v46; // [sp+30h] [-F0h]
  int v47; // [sp+34h] [-ECh]
  int v48; // [sp+38h] [-E8h]
  int v49; // [sp+3Ch] [-E4h]
  int v50; // [sp+40h] [-E0h]
  int v51; // [sp+44h] [-DCh]
  int v52; // [sp+48h] [-D8h]
  int v53; // [sp+4Ch] [-D4h]
  int v54; // [sp+50h] [-D0h]
  char v55; // [sp+5Ch] [-C4h] BYREF
  idMat3 v56; // [sp+60h] [-C0h] BYREF
  idRotation v57; // [sp+90h] [-90h] BYREF

  if ( this->remoteFireTime > 0 && this->remoteFireTime <= gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) )
  {
    if ( this->remoteFireWeapon != nullptr )
    {
      remoteFireInfiniteAmmo = this->remoteFireInfiniteAmmo;
      remoteFireAddSpread = this->remoteFireAddSpread;
      remoteFireDamageScale = this->remoteFireDamageScale;
      v5 = idPresentablePtr<idPresentableProjectile>::operator->(this: &this->remoteFireTarget);
      remoteFireLockedOn = this->remoteFireLockedOn;
      v7 = idPresentablePtr<idPresentableProjectile>::operator->(this: &this->remoteFireAttacker);
      idVehicleWeapon::Fire(
        this: this->remoteFireWeapon,
        attacker: v7,
        lockedOn: remoteFireLockedOn,
        target: v5,
        damageScale: remoteFireDamageScale,
        addSpread: remoteFireAddSpread,
        infiniteAmmo: v9,
        beingRemoteFired: v8,
        skipClientFireRecord: remoteFireInfiniteAmmo,
        a10: 1,
        a11: v36,
        a12: v37,
        a13: v38,
        a14: v39,
        a15: v40,
        a16: v41,
        a17: v42,
        a18: v43,
        a19: v44,
        a20: v45,
        a21: v46,
        a22: v47,
        a23: v48,
        a24: v49,
        a25: v50,
        a26: v51,
        a27: v52,
        a28: v53,
        a29: v54,
        a30: 0);
    }
    this->remoteFireTime = 0;
  }
  idVehicleWeapon::ValidateTreeAnimator(this);
  weapon = this->weapon;
  if ( weapon->fireState == FIRESTATE_RELOADING )
  {
    if ( idPresentablePtr<idPresentableProjectile>::operator->(this: &this->presentable) != nullptr )
      p_fxManager = &idPresentablePtr<idPresentableProjectile>::operator->(this: &this->presentable)->fxManager;
    else
      p_fxManager = nullptr;
    this->weapon->Reload(this: this->weapon, a2: nullptr, a3: p_fxManager, a4: false, a5: false, a6: false);
  }
  else
  {
    idWeapon::UpdateState(this: weapon, inventory: nullptr, secondaryAmmo: false);
  }
  if ( (unsigned __int16)this->rollJointIndex.value != 0xFFFF )
  {
    v12 = this->weapon;
    fireState = v12->fireState;
    if ( fireState == FIRESTATE_FIRING || fireState == FIRESTATE_DELAYED_FIRE )
    {
      nextFireTime = v12->nextFireTime;
      GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      if ( nextFireTime >= idWeapon::GetFiringInterval(
                             this: this->weapon,
                             secondaryAmmo: (_cntlzw(this->weapon->weaponState - 1) & 0x20) != 0)
                         + GameMs )
      {
        v17 = this->weapon->nextFireTime;
      }
      else
      {
        v16 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        v17 = idWeapon::GetFiringInterval(
                this: this->weapon,
                secondaryAmmo: (_cntlzw(this->weapon->weaponState - 1) & 0x20) != 0)
            + v16;
      }
      this->firingTime = v17;
    }
    this->spinupFire = false;
    if ( idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) > this->firingTime )
    {
      v20 = (float)(this->rollDelta * (float)0.94999999);
      this->rollDelta = this->rollDelta * (float)0.94999999;
      if ( v20 < 1.0 )
        this->rollDelta = 0.0;
    }
    else
    {
      maxRollSpeed = this->maxRollSpeed;
      v19 = (float)((float)(this->rollDelta * (float)1.15) + (float)0.23);
      this->rollDelta = (float)(this->rollDelta * (float)1.15) + (float)0.23;
      if ( v19 > maxRollSpeed || vehicle_weapon_rollDelay.valueInteger == 0 )
        this->rollDelta = maxRollSpeed;
    }
    if ( this->rollDelta > 0.0 )
    {
      rollAngle = this->rollAngle;
      v22 = (float)(this->rollAngle + this->rollDelta);
      this->rollAngle = this->rollAngle + this->rollDelta;
      if ( v22 >= 180.0 )
        this->rollAngle = (float)v22 - (float)360.0;
      if ( rollAngle < -60.0 && this->rollAngle >= -60.0
        || rollAngle < 60.0 && this->rollAngle >= 60.0
        || rollAngle > 90.0 && this->rollAngle < -90.0 )
      {
        this->spinupFire = true;
      }
    }
    v23 = &v55;
    p_z = &this->spinJointOrigin.z;
    for ( i = 9; i != 0; --i )
    {
      ++p_z;
      v23 += 4;
      *(float *)v23 = *p_z;
    }
    v26 = this->weapon;
    if ( v26 == nullptr || (decl = v26->decl) == nullptr )
      decl = nullptr;
    if ( v26 == nullptr || (v28 = v26->decl) == nullptr )
      v28 = nullptr;
    lowDuration = v28[4].droppedControllerShake.lowDuration;
    v57.angle = decl[4].droppedControllerShake.lowMagnitude * this->rollAngle;
    v57.axisValid = false;
    v57.origin.x = vec3_origin.x;
    p_x = &v56.mat[lowDuration].x;
    v57.axis.mat[0].x = mat3_identity.mat[0].x;
    v31 = *p_x;
    v32 = p_x[1];
    v33 = p_x[2];
    v57.origin.y = vec3_origin.y;
    v57.origin.z = vec3_origin.z;
    v57.axis.mat[0].y = mat3_identity.mat[0].y;
    v57.axis.mat[0].z = mat3_identity.mat[0].z;
    v57.axis.mat[1].x = mat3_identity.mat[1].x;
    v57.axis.mat[1].y = mat3_identity.mat[1].y;
    v57.axis.mat[1].z = mat3_identity.mat[1].z;
    v57.vec.x = v31;
    v57.axis.mat[2].x = mat3_identity.mat[2].x;
    v57.vec.y = v32;
    v57.axis.mat[2].y = mat3_identity.mat[2].y;
    v57.vec.z = v33;
    v57.axis.mat[2].z = mat3_identity.mat[2].z;
    v34 = (float *)idRotation::ToMat3(this: &v57);
    treeAnimator = this->treeAnimator;
    v56.mat[0].x = *v34;
    v56.mat[0].y = v34[1];
    v56.mat[0].z = v34[2];
    v56.mat[1].x = v34[3];
    v56.mat[1].y = v34[4];
    v56.mat[1].z = v34[5];
    v56.mat[2].x = v34[6];
    v56.mat[2].y = v34[7];
    v56.mat[2].z = v34[8];
    if ( treeAnimator != nullptr )
      idTreeAnimator::SetJointAxis(
        this: treeAnimator,
        pose: (animationPose_t)0,
        jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)this->rollJointIndex.value,
        type: JOINTMOD_LOCAL,
        axis: &v56);
  }
}


// ========================================================================
// `dynamic initializer for 'vehicle_weapon_debug''
// EA  : 0x8337DC00
// RVA : 0x0137DC00
// PDB : w:\tech5\tungsten\game\entities\vehicleweapon.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_weapon_debug__()
{
  idCVar::idCVar(
    this: &vehicle_weapon_debug,
    name: "vehicle_weapon_debug",
    value: "0",
    flags: 1,
    description: "Show weapon target .. alignment",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_weapon_debug__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_weapon_anim_debug''
// EA  : 0x8337DC58
// RVA : 0x0137DC58
// PDB : w:\tech5\tungsten\game\entities\vehicleweapon.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_weapon_anim_debug__()
{
  idCVar::idCVar(
    this: &vehicle_weapon_anim_debug,
    name: "vehicle_weapon_anim_debug",
    value: "0",
    flags: 1,
    description: "Show weapon anims played",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_weapon_anim_debug__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_weapon_rollDelay''
// EA  : 0x8337DCB0
// RVA : 0x0137DCB0
// PDB : w:\tech5\tungsten\game\entities\vehicleweapon.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_weapon_rollDelay__()
{
  idCVar::idCVar(
    this: &vehicle_weapon_rollDelay,
    name: "vehicle_weapon_rollDelay",
    value: "0",
    flags: 1,
    description: "delay firing until roll reaches max speed",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_weapon_rollDelay__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_weapon_lag''
// EA  : 0x8337DD08
// RVA : 0x0137DD08
// PDB : w:\tech5\tungsten\game\entities\vehicleweapon.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_weapon_lag__()
{
  idCVar::idCVar(
    this: &vehicle_weapon_lag,
    name: "vehicle_weapon_lag",
    value: "1",
    flags: 4,
    description: "Vehicle weapon lag",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_weapon_lag__);
}

