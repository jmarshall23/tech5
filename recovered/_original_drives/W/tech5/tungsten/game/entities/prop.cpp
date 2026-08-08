
// ========================================================================
// ?Hide@idUse@@UAAXXZ
// EA  : 0x82C9AB80
// RVA : 0x00C9AB80
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void __fastcall idUse::Hide(idUse *this)
{
  idPhysics *Physics; // r3

  if ( (unsigned __int8)Get_idCombatStage_useRelaxedChatterVO(ptr: (unsigned __int8 *)this) == 0 )
  {
    Physics = idEntity::GetPhysics(this);
    Physics->SetContents(this: Physics, a2: 0, a3: -1);
  }
  idEntity::Hide(this);
}


// ========================================================================
// ?Show@idUse@@UAAXXZ
// EA  : 0x82C9ABE0
// RVA : 0x00C9ABE0
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void __fastcall idUse::Show(idUse *this)
{
  idPhysics *Physics; // r3

  if ( (unsigned __int8)Get_idCombatStage_useRelaxedChatterVO(ptr: (unsigned __int8 *)this) != 0 )
  {
    Physics = idEntity::GetPhysics(this);
    Physics->SetContents(this: Physics, a2: 0x200000, a3: -1);
  }
  idEntity::Show(this);
}


// ========================================================================
// ?RunUse@idUse@@AAAXPAVidEntity@@W4usableState_t@@@Z
// EA  : 0x82C9AC40
// RVA : 0x00C9AC40
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void __fastcall idUse::RunUse(idUse *this, idEntity *activator, usableState_t usable)
{
  idEventReceiver v5[2]; // [sp+50h] [-30h] BYREF

  idEntity::Use(this, activator, usable);
  this->ActivateTargets(this, a2: activator);
  idEventReceiver::ProcessEvent(this: v5, result: (idEventArg *)this, ev: &EV_NotifyProgressionOwner);
  if ( (*((_BYTE *)this + 844) & 0x80) != 0 )
    this->Hide_2(this);
}


// ========================================================================
// ??0idProp@@QAA@XZ
// EA  : 0x82C9ACC8
// RVA : 0x00C9ACC8
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

idProp *__fastcall idProp::idProp(idProp *this)
{
  idAnimatedEntity::idAnimatedEntity(this);
  this->__vftable = (idProp_vtbl *)&idProp::`vftable';
  return this;
}


// ========================================================================
// ?IsEverUsable@idProp_Usable@@UBA_NPBVidEntity@@@Z
// EA  : 0x82C9AD08
// RVA : 0x00C9AD08
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

BOOL __fastcall idProp_Usable::IsEverUsable(idProp_Usable *this, const idEntity *activator)
{
  return (_cntlzw((unsigned __int8)Get_idCombatStage_useRelaxedChatterVO(ptr: (unsigned __int8 *)this)) & 0x20) != 0;
}


// ========================================================================
// ?RunUse@idProp_Usable@@AAAXPAVidEntity@@W4usableState_t@@@Z
// EA  : 0x82C9AD38
// RVA : 0x00C9AD38
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void __fastcall idProp_Usable::RunUse(idProp_Usable *this, idEntity *activator, usableState_t usable)
{
  idEventReceiver v5[2]; // [sp+50h] [-30h] BYREF

  idEntity::Use(this, activator, usable);
  if ( this->triggerTargets )
    this->ActivateTargets(this, a2: activator);
  idEventReceiver::ProcessEvent(this: v5, result: (idEventArg *)this, ev: &EV_NotifyProgressionOwner);
}


// ========================================================================
// ?Event_GetUsePercent@idProp_ContinuallyUsed@@AAA?AVeventFloat@@XZ
// EA  : 0x82C9ADA8
// RVA : 0x00C9ADA8
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

idProp_ContinuallyUsed *__fastcall idProp_ContinuallyUsed::Event_GetUsePercent(
        idProp_ContinuallyUsed *this,
        eventFloat *result)
{
  eventFloat::eventFloat((eventFloat *)this, f: result[1317].value);
  return this;
}


// ========================================================================
// ?Spawn@idProp_Static@@QAAXXZ
// EA  : 0x82C9ADE0
// RVA : 0x00C9ADE0
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void __fastcall idProp_Static::Spawn(idProp_Static *this)
{
  idEntity::BecomeInactive(this, flags: 7);
}


// ========================================================================
// ?DormantBegin@idProp_Moveable@@UAAXXZ
// EA  : 0x82C9ADE8
// RVA : 0x00C9ADE8
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void __fastcall idProp_Moveable::DormantBegin(idProp_Moveable *this)
{
  idEntity::DormantBegin(this);
  if ( this->removeCondition == REMOVE_CONDITION_DORMANT )
    idEventReceiver::PostEventMS(this, ev: &EV_Remove, time: 0);
}


// ========================================================================
// ?BecomeSolid@idProp_Moveable@@QAAXXZ
// EA  : 0x82C9AE38
// RVA : 0x00C9AE38
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void __fastcall idProp_Moveable::BecomeSolid(idProp_Moveable *this)
{
  idPhysics *Physics; // r29
  idPhysics_vtbl *v3; // r30
  int v4; // r3
  idPhysics *v5; // r29
  idPhysics_vtbl *v6; // r30
  int v7; // r4
  idPhysics *v8; // r3

  Physics = idEntity::GetPhysics(this);
  v3 = Physics->__vftable;
  v4 = idContents::ToFlags(this: &this->clipOverride.contents);
  v3->SetContents(this: Physics, a2: v4, a3: -1);
  if ( common->IsMultiplayer(this: common) )
  {
    v5 = idEntity::GetPhysics(this);
    v6 = v5->__vftable;
    v7 = idContents::ToFlags(this: &this->clipOverride.clipMask) | 1;
  }
  else
  {
    v5 = idEntity::GetPhysics(this);
    v6 = v5->__vftable;
    v7 = idContents::ToFlags(this: &this->clipOverride.clipMask);
  }
  v6->SetClipMask(this: v5, a2: v7, a3: -1);
  v8 = idEntity::GetPhysics(this);
  v8->LinkClip(this: v8);
}


// ========================================================================
// ?Event_IsAtRest@idProp_Moveable@@IAA?AVeventInt@@XZ
// EA  : 0x82C9AF08
// RVA : 0x00C9AF08
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

idProp_Moveable *__fastcall idProp_Moveable::Event_IsAtRest(idProp_Moveable *this, idEntity *result)
{
  idPhysics *Physics; // r3
  bool v4; // r3

  Physics = idEntity::GetPhysics(this: result);
  v4 = Physics->IsAtRest(this: Physics);
  eventInt::eventInt((eventInt *)this, i: v4);
  return this;
}


// ========================================================================
// ?Event_NumPickupHands@idProp_Moveable@@IAA?AVeventFloat@@XZ
// EA  : 0x82C9AF58
// RVA : 0x00C9AF58
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

idProp_Moveable *__fastcall idProp_Moveable::Event_NumPickupHands(idProp_Moveable *this, eventFloat *result)
{
  __int64 v2; // r11

  LODWORD(v2) = result[1349];
  if ( (_DWORD)v2 != 0 )
    LODWORD(v2) = *(_DWORD *)(v2 + 348);
  eventFloat::eventFloat((eventFloat *)this, f: (float)v2);
  return this;
}


// ========================================================================
// ?GetIcon@idProp_Moveable@@UBAPBVidMaterial@@XZ
// EA  : 0x82C9AFB0
// RVA : 0x00C9AFB0
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

const idMaterial *__fastcall idProp_Moveable::GetIcon(idProp_Moveable *this)
{
  const idDeclInventory *inventoryDecl; // r11

  inventoryDecl = this->inventoryDecl;
  if ( inventoryDecl != nullptr )
    return inventoryDecl->icon;
  else
    return nullptr;
}


// ========================================================================
// ?GetOnlineUsableState@idProp_Moveable@@UBA?AW4usableState_t@@XZ
// EA  : 0x82C9AFD0
// RVA : 0x00C9AFD0
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

usableState_t __fastcall idProp_Moveable::GetOnlineUsableState(idProp_Moveable *this)
{
  const idDeclInventory *requiredInvDecl; // r11
  usableState_t result; // r3

  if ( this->inventoryDecl != nullptr )
    return USABLE_PROP;
  requiredInvDecl = this->requiredInvDecl;
  result = USABLE_NOT_USABLE;
  if ( requiredInvDecl != nullptr )
    return USABLE_PROP;
  return result;
}


// ========================================================================
// ?ShouldRespawn@idProp_Moveable@@IAA_NXZ
// EA  : 0x82C9AFF8
// RVA : 0x00C9AFF8
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

int __fastcall idProp_Moveable::ShouldRespawn(idProp_Moveable *this)
{
  int v2; // r3
  unsigned __int8 v3; // r11

  if ( this->respawnTime <= 0 )
    return 0;
  v2 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
  v3 = 1;
  if ( this->respawnTime > v2 )
    return 0;
  return v3;
}


// ========================================================================
// ?ModifyCrosshairInfo@idProp_AmmoRefill@@UBA_NPBVidEntity@@ABVidFocusTrace@@W4usableState_t@@AAVidCrosshairInfo@@@Z
// EA  : 0x82C9B060
// RVA : 0x00C9B060
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

int __fastcall idProp_AmmoRefill::ModifyCrosshairInfo(
        idProp_AmmoRefill *this,
        const idEntity *activator,
        const idFocusTrace *ft,
        const usableState_t usable,
        idCrosshairInfo *info)
{
  int result; // r3
  int v6; // r11
  idColor *v7; // r9
  crosshairMaterial_t v8; // r8
  float r; // r6
  float a; // r10

  result = 1;
  if ( usable == USABLE_AMMO_REFILL )
  {
    v6 = 0;
    v7 = &idColor::colorGreen;
    v8 = CHMATERIAL_AMMO_REFILL;
    r = idColor::colorGreen.r;
  }
  else
  {
    v6 = 1;
    v7 = &idColor::colorRed;
    v8 = CHMATERIAL_LOOT;
    r = idColor::colorRed.r;
  }
  info->color.r = r;
  info->color.g = v7->g;
  info->color.b = v7->b;
  a = v7->a;
  info->material = v8;
  info->textColorState = v6;
  info->colorState = v6;
  info->color.a = a;
  return result;
}


// ========================================================================
// ?GetUsableState@idProp_BreakableLoot@@UBA?AW4usableState_t@@PBVidEntity@@ABVidFocusTrace@@@Z
// EA  : 0x82C9B0C8
// RVA : 0x00C9B0C8
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

usableState_t __fastcall idProp_BreakableLoot::GetUsableState(
        idProp_BreakableLoot *this,
        idPlayer *activator,
        const idFocusTrace *ft)
{
  usableState_t result; // r3

  if ( idPlayer::CastTo(c: activator) == nullptr )
    return USABLE_NOT_USABLE;
  result = USABLE_LOOT;
  if ( this->lootedTime > 0 )
    return USABLE_NOT_USABLE;
  return result;
}


// ========================================================================
// ?GetOnlineUsableState@idProp_BreakableLoot@@UBA?AW4usableState_t@@XZ
// EA  : 0x82C9B118
// RVA : 0x00C9B118
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

unsigned int __fastcall idProp_BreakableLoot::GetOnlineUsableState(idProp_BreakableLoot *this)
{
  return (~((unsigned int)this->lootedTime >> 31) + (this->lootedTime != 0)) & 2;
}


// ========================================================================
// ?BecomeNoticed@idProp_Noticable@@QAAXPAVidEntity@@@Z
// EA  : 0x82C9B138
// RVA : 0x00C9B138
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void __fastcall idProp_Noticable::BecomeNoticed(idProp_Noticable *this, idEntity *ent)
{
  idProp_Noticable_vtbl *v4; // r10

  if ( !this->noticed && (!this->playerOnly || (unsigned __int8)idPlayer::IsTypeOf(c: ent) != 0) )
  {
    v4 = this->__vftable;
    this->noticed = true;
    v4->ActivateTargets(this, a2: ent);
  }
}


// ========================================================================
// ?Damage@idProp_VehicleJump@@UAAMPAVidEntity@@0PBVidDeclDamage@@MABVidVec3@@PAUtrace_t@@@Z
// EA  : 0x82C9B1B8
// RVA : 0x00C9B1B8
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

float __fastcall idProp_VehicleJump::Damage(
        idProp_VehicleJump *this,
        idEntity *inflictor,
        idEntity *attacker,
        const idDeclDamage *damageDef,
        double damageScale,
        const idVec3 *dir,
        trace_t *trace)
{
  double v7; // fp1

  idAlarm::StartFX(this, condition: FX_LASER_ON);
  v7 = 0.0;
  return *((float *)&v7 + 1);
}


// ========================================================================
// ?Spawn@idProp_GameStateInt@@QAAXXZ
// EA  : 0x82C9B1E8
// RVA : 0x00C9B1E8
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void __fastcall idProp_GameStateInt::Spawn(idProp_GameStateInt *this)
{
  idPhysics *Physics; // r3
  idPhysics *v3; // r3
  idPhysics *v4; // r3

  Physics = idEntity::GetPhysics(this);
  Physics->SetContents(this: Physics, a2: 0x4000, a3: -1);
  v3 = idEntity::GetPhysics(this);
  v3->SetClipMask(this: v3, a2: 1, a3: -1);
  v4 = idEntity::GetPhysics(this);
  v4->EnableClip(this: v4);
  idEntity::BecomeInactive(this, flags: 2);
  this->angle = 0.0;
  idAlarm::StartFX(this, condition: FX_PROP_USE);
}


// ========================================================================
// ?Spawn@idProp_VehiclePickup@@QAAXXZ
// EA  : 0x82C9B288
// RVA : 0x00C9B288
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void __fastcall idProp_VehiclePickup::Spawn(idProp_VehiclePickup *this)
{
  idPhysics *Physics; // r3
  idPhysics *v3; // r3
  idPhysics *v4; // r3

  Physics = idEntity::GetPhysics(this);
  Physics->SetContents(this: Physics, a2: 0x4000, a3: -1);
  v3 = idEntity::GetPhysics(this);
  v3->SetClipMask(this: v3, a2: 1, a3: -1);
  v4 = idEntity::GetPhysics(this);
  v4->EnableClip(this: v4);
  idEntity::BecomeInactive(this, flags: 2);
  idEntity::BecomeActive(this, flags: 1);
  this->tractored = false;
  this->angle = 0.0;
}


// ========================================================================
// ?GetOnlineUsableState@idProp_ExplosivePlunger@@UBA?AW4usableState_t@@XZ
// EA  : 0x82C9B330
// RVA : 0x00C9B330
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

usableState_t __fastcall idProp_ExplosivePlunger::GetOnlineUsableState(idProp_ExplosivePlunger *this)
{
  BOOL usedPrimer; // r11
  usableState_t result; // r3

  if ( !this->primerReady )
    return USABLE_NOT_USABLE;
  usedPrimer = this->usedPrimer;
  result = USABLE_PROP;
  if ( usedPrimer )
    return USABLE_NOT_USABLE;
  return result;
}


// ========================================================================
// ?GetUsableState@idProp_Explosive@@UBA?AW4usableState_t@@PBVidEntity@@ABVidFocusTrace@@@Z
// EA  : 0x82C9B358
// RVA : 0x00C9B358
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

unsigned int __fastcall idProp_Explosive::GetUsableState(idProp_Explosive *this)
{
  return (~((unsigned int)this->state >> 31) + (this->state != BOMB_STATE_EMPTY)) & 3;
}


// ========================================================================
// ?Spawn@idProp_JobPosting@@QAAXXZ
// EA  : 0x82C9B378
// RVA : 0x00C9B378
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void __fastcall idProp_JobPosting::Spawn(idProp_JobPosting *this)
{
  idPhysics *Physics; // r29
  idPhysics_vtbl *v3; // r31
  idClipModel *MoveableClipModel; // r3
  idPhysics *v5; // r3
  idClipModel *v6; // r3

  Physics = idEntity::GetPhysics(this);
  v3 = Physics->__vftable;
  MoveableClipModel = idEntity::CreateMoveableClipModel(this, barrelCollision: false, overrideRadius: -1.0);
  ((void (__fastcall *)(idPhysics *, idClipModel *, double))v3->SetClipModel)(
    a1: Physics,
    a2: MoveableClipModel,
    a3: 1.0);
  v5 = idEntity::GetPhysics(this);
  v6 = v5->GetClipModel(this: v5, a2: 0);
  idClipModel::SetContents(this: v6, newContents: 0x200000);
  idEntity::BecomeActive(this, flags: 1);
}


// ========================================================================
// ?MarkToCheckPlayer@idProp_JobPosting@@QAAXXZ
// EA  : 0x82C9B408
// RVA : 0x00C9B408
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void __fastcall idProp_JobPosting::MarkToCheckPlayer(idProp_JobPosting *this)
{
  this->shouldCheckPlayer = true;
  idEntity::BecomeActive(this, flags: 1);
}


// ========================================================================
// ?Use@idProp_JobPosting@@UAA_NPAVidEntity@@W4usableState_t@@@Z
// EA  : 0x82C9B418
// RVA : 0x00C9B418
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

idPlayer *__fastcall idProp_JobPosting::Use(idProp_JobPosting *this, idPlayer *user, const usableState_t usable)
{
  idPlayer *result; // r3

  result = idPlayer::CastTo(c: user);
  if ( result != nullptr )
  {
    idPlayer::ShowJobBoard(this: result, jobDecls: &this->jobDeclList);
    return (idPlayer *)1;
  }
  return result;
}


// ========================================================================
// ?GetUsableState@idProp_HealthPickup@@UBA?AW4usableState_t@@PBVidEntity@@ABVidFocusTrace@@@Z
// EA  : 0x82C9B470
// RVA : 0x00C9B470
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

int __fastcall idProp_HealthPickup::GetUsableState(
        idProp_HealthPickup *this,
        const idEntity *activator,
        const idFocusTrace *ft)
{
  if ( (this->inventoryDecl != nullptr || this->requiredInvDecl != nullptr)
    && this->removeCondition == REMOVE_CONDITION_NONE )
  {
    return 3;
  }
  else
  {
    return 0;
  }
}


// ========================================================================
// ?CheckModel@idProp_MissionPin@@AAAXH@Z
// EA  : 0x82C9B4A8
// RVA : 0x00C9B4A8
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void __fastcall idProp_MissionPin::CheckModel(idProp_MissionPin *this, int variationID)
{
  idPlayerProfileGame *v4; // r3

  v4 = (idPlayerProfileGame *)common->GetProfileFromMasterLocalUser(this: common);
  if ( v4 != nullptr && idPlayerProfileGame::GetCompleted(this: v4, completedID: variationID) )
    this->SetModel(this, a2: this->completedModel);
}


// ========================================================================
// ?IsWithinConstraints@idUseConstraints@@QBA_NPBVidEntity@@0@Z
// EA  : 0x82C9B5F0
// RVA : 0x00C9B5F0
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

BOOL __fastcall idUseConstraints::IsWithinConstraints(idUseConstraints *this, idPlayer *activator, idEntity *owner)
{
  idPhysics *Physics; // r3
  int v7; // r3
  float v8; // r7
  float v9; // r6
  idPlayer *v10; // r3
  idPresentable *presentable; // r3
  idPresentablePlayer *v12; // r3
  idPhysics *v13; // r3
  float *v14; // r3
  double v15; // fp6
  int v16; // r5
  double v17; // fp0
  double v20; // fp12
  double v21; // fp1
  double v22; // fp13
  double v23; // fp8
  idPhysics *v25; // r3
  int v26; // r3
  char *v27; // r10
  _DWORD *v28; // r11
  int i; // ctr
  double v30; // fp7
  double v31; // fp6
  long double v32; // fp4
  long double v33; // fp2
  long double v34; // fp2
  long double v35; // fp4
  long double v36; // fp2
  int useFlags; // r11
  double v38; // fp13
  idAngles v39; // [sp+50h] [-C0h] BYREF
  idVec3 v40; // [sp+60h] [-B0h] BYREF
  idVec3 v41; // [sp+70h] [-A0h] BYREF
  idMat3 v42; // [sp+80h] [-90h] BYREF
  char v43; // [sp+ACh] [-64h] BYREF
  idMat3 v44; // [sp+B0h] [-60h] BYREF

  if ( (this->useFlags & 7) == 0 )
    return true;
  Physics = idEntity::GetPhysics(this: activator);
  v7 = (int)Physics->GetOrigin(this: Physics, a2: 0);
  v8 = *(float *)(v7 + 4);
  v9 = *(float *)(v7 + 8);
  v40.x = *(float *)v7;
  v40.y = v8;
  v40.z = v9;
  v10 = idPlayer::CastTo(c: activator);
  if ( v10 != nullptr )
  {
    presentable = v10->presentable;
    if ( presentable != nullptr )
      v12 = presentable->GetPlayerInterface_2(this: presentable);
    else
      v12 = nullptr;
    idPresentablePlayer::GetViewTransform(this: v12, origin: &v40, axis: &v44);
  }
  v13 = idEntity::GetPhysics(this: owner);
  v14 = (float *)v13->GetOrigin(this: v13, a2: 0);
  v15 = (float)(v40.z - v14[2]);
  v16 = this->useFlags & 4;
  v17 = (float)((float)((float)(v40.z - v14[2]) * (float)(v40.z - v14[2]))
              + (float)((float)((float)(v40.x - *v14) * (float)(v40.x - *v14))
                      + (float)((float)(v40.y - v14[1]) * (float)(v40.y - v14[1]))));
  _FP3 = (float)((float)((float)((float)(v40.z - v14[2]) * (float)(v40.z - v14[2]))
                       + (float)((float)((float)(v40.x - *v14) * (float)(v40.x - *v14))
                               + (float)((float)(v40.y - v14[1]) * (float)(v40.y - v14[1]))))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f1, f3, f0, f12 }
  v20 = __frsqrte(_FP1);
  v21 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v20
                                                                                      * (float)((float)((float)((float)(v40.z - v14[2]) * (float)(v40.z - v14[2])) + (float)((float)((float)(v40.x - *v14) * (float)(v40.x - *v14)) + (float)((float)(v40.y - v14[1]) * (float)(v40.y - v14[1]))))
                                                                                              * (float)0.5))
                                                                              * (float)v20)
                                                                      - (float)1.5)
                                                      * (float)v20)
                                              * (float)((float)((float)((float)(v40.z - v14[2]) * (float)(v40.z - v14[2]))
                                                              + (float)((float)((float)(v40.x - *v14)
                                                                              * (float)(v40.x - *v14))
                                                                      + (float)((float)(v40.y - v14[1])
                                                                              * (float)(v40.y - v14[1]))))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v20
                                                                              * (float)((float)((float)((float)(v40.z - v14[2]) * (float)(v40.z - v14[2]))
                                                                                              + (float)((float)((float)(v40.x - *v14) * (float)(v40.x - *v14)) + (float)((float)(v40.y - v14[1]) * (float)(v40.y - v14[1]))))
                                                                                      * (float)0.5))
                                                                      * (float)v20)
                                                              - (float)1.5)
                                              * (float)v20))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v20
                                                      * (float)((float)((float)((float)(v40.z - v14[2])
                                                                              * (float)(v40.z - v14[2]))
                                                                      + (float)((float)((float)(v40.x - *v14)
                                                                                      * (float)(v40.x - *v14))
                                                                              + (float)((float)(v40.y - v14[1])
                                                                                      * (float)(v40.y - v14[1]))))
                                                              * (float)0.5))
                                              * (float)v20)
                                      - (float)1.5)
                      * (float)v20));
  v22 = (float)((float)-(float)((float)((float)((float)v21
                                              * (float)((float)((float)((float)(v40.z - v14[2]) * (float)(v40.z - v14[2]))
                                                              + (float)((float)((float)(v40.x - *v14)
                                                                              * (float)(v40.x - *v14))
                                                                      + (float)((float)(v40.y - v14[1])
                                                                              * (float)(v40.y - v14[1]))))
                                                      * (float)0.5))
                                      * (float)v21)
                              - (float)1.5)
              * (float)v21);
  v23 = (float)((float)(v40.y - v14[1])
              * (float)((float)-(float)((float)((float)((float)v21
                                                      * (float)((float)((float)((float)(v40.z - v14[2])
                                                                              * (float)(v40.z - v14[2]))
                                                                      + (float)((float)((float)(v40.x - *v14)
                                                                                      * (float)(v40.x - *v14))
                                                                              + (float)((float)(v40.y - v14[1])
                                                                                      * (float)(v40.y - v14[1]))))
                                                              * (float)0.5))
                                              * (float)v21)
                                      - (float)1.5)
                      * (float)v21));
  v39.pitch = (float)(v40.x - *v14)
            * (float)((float)-(float)((float)((float)((float)v21
                                                    * (float)((float)((float)((float)(v40.z - v14[2])
                                                                            * (float)(v40.z - v14[2]))
                                                                    + (float)((float)((float)(v40.x - *v14)
                                                                                    * (float)(v40.x - *v14))
                                                                            + (float)((float)(v40.y - v14[1])
                                                                                    * (float)(v40.y - v14[1]))))
                                                            * (float)0.5))
                                            * (float)v21)
                                    - (float)1.5)
                    * (float)v21);
  v39.yaw = v23;
  v39.roll = (float)v15 * (float)v22;
  if ( v16 != 0 && (float)((float)v22 * (float)v17) > (double)this->distanceConstraint )
    return false;
  v25 = idEntity::GetPhysics(this: owner);
  v26 = (int)v25->GetAxis(this: v25, a2: 0);
  v27 = &v43;
  v28 = (_DWORD *)(v26 - 4);
  for ( i = 9; i != 0; --i )
  {
    ++v28;
    v27 += 4;
    *(_DWORD *)v27 = *v28;
  }
  idMat3::Inverse(this: &v42, result: &v44);
  v30 = (float)((float)(v42.mat[0].y * v39.pitch)
              + (float)((float)(v42.mat[2].y * v39.roll) + (float)(v42.mat[1].y * v39.yaw)));
  v31 = (float)((float)(v42.mat[0].z * v39.pitch)
              + (float)((float)(v42.mat[2].z * v39.roll) + (float)(v42.mat[1].z * v39.yaw)));
  v39.pitch = (float)(v42.mat[0].x * v39.pitch)
            + (float)((float)(v42.mat[2].x * v39.roll) + (float)(v42.mat[1].x * v39.yaw));
  v39.yaw = v30;
  v39.roll = v31;
  idVec3::ToAngles(this: &v41, result: &v39);
  *((double *)&v32 + 1) = v41.y;
  *(double *)&v33 = (float)((float)(this->angleConstraintHorizontal.value * (float)0.5) + v41.y);
  *((double *)&v33 + 1) = 360.0;
  v34 = fmod(dX: v33, dY: v32);
  *(double *)&v35 = (float)*(double *)&v34;
  v41.y = *(double *)&v34;
  *((double *)&v34 + 1) = 360.0;
  *(double *)&v34 = (float)((float)(this->angleConstraintVertical.value * (float)0.5) + v41.x);
  v36 = fmod(dX: v34, dY: v35);
  useFlags = this->useFlags;
  v38 = (float)*(double *)&v36;
  if ( (useFlags & 1) != 0 && (v41.y < 0.0 || v41.y > (double)this->angleConstraintHorizontal.value) )
    return false;
  return (useFlags & 2) == 0 || v38 >= 0.0 && v38 <= this->angleConstraintVertical.value;
}


// ========================================================================
// ?GetUsableState@idUse@@UBA?AW4usableState_t@@PBVidEntity@@ABVidFocusTrace@@@Z
// EA  : 0x82C9B8D0
// RVA : 0x00C9B8D0
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

int __fastcall idUse::GetUsableState(idUse *this, idPlayer *activator, const idFocusTrace *ft)
{
  idPhysics *Physics; // r3
  int v6; // r3
  float v7; // r7
  float v8; // r6
  idPlayer *v9; // r3
  idPresentable *presentable; // r3
  idPresentablePlayer *v11; // r3
  idPhysics *v12; // r3
  float *v13; // r3
  double v14; // fp6
  int v15; // r5
  double v16; // fp0
  double v19; // fp12
  double v20; // fp1
  double v21; // fp13
  double v22; // fp8
  idPhysics *v24; // r3
  int v25; // r3
  char *v26; // r10
  _DWORD *v27; // r11
  int i; // ctr
  double v29; // fp7
  double v30; // fp6
  long double v31; // fp4
  long double v32; // fp2
  long double v33; // fp2
  long double v34; // fp4
  long double v35; // fp2
  int useFlags; // r11
  double v37; // fp13
  idAngles v38; // [sp+50h] [-B0h] BYREF
  idVec3 v39; // [sp+60h] [-A0h] BYREF
  idVec3 v40; // [sp+70h] [-90h] BYREF
  idMat3 v41; // [sp+80h] [-80h] BYREF
  char v42; // [sp+ACh] [-54h] BYREF
  idMat3 v43; // [sp+B0h] [-50h] BYREF

  if ( (this->useFlags & 7) == 0 )
    return 3;
  Physics = idEntity::GetPhysics(this: activator);
  v6 = (int)Physics->GetOrigin(this: Physics, a2: 0);
  v7 = *(float *)(v6 + 4);
  v8 = *(float *)(v6 + 8);
  v39.x = *(float *)v6;
  v39.y = v7;
  v39.z = v8;
  v9 = idPlayer::CastTo(c: activator);
  if ( v9 != nullptr )
  {
    presentable = v9->presentable;
    if ( presentable != nullptr )
      v11 = presentable->GetPlayerInterface_2(this: presentable);
    else
      v11 = nullptr;
    idPresentablePlayer::GetViewTransform(this: v11, origin: &v39, axis: &v43);
  }
  v12 = idEntity::GetPhysics(this);
  v13 = (float *)v12->GetOrigin(this: v12, a2: 0);
  v14 = (float)(v39.z - v13[2]);
  v15 = this->useFlags & 4;
  v16 = (float)((float)((float)(v39.z - v13[2]) * (float)(v39.z - v13[2]))
              + (float)((float)((float)(v39.x - *v13) * (float)(v39.x - *v13))
                      + (float)((float)(v39.y - v13[1]) * (float)(v39.y - v13[1]))));
  _FP3 = (float)((float)((float)((float)(v39.z - v13[2]) * (float)(v39.z - v13[2]))
                       + (float)((float)((float)(v39.x - *v13) * (float)(v39.x - *v13))
                               + (float)((float)(v39.y - v13[1]) * (float)(v39.y - v13[1]))))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f1, f3, f0, f12 }
  v19 = __frsqrte(_FP1);
  v20 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v19
                                                                                      * (float)((float)((float)((float)(v39.z - v13[2]) * (float)(v39.z - v13[2])) + (float)((float)((float)(v39.x - *v13) * (float)(v39.x - *v13)) + (float)((float)(v39.y - v13[1]) * (float)(v39.y - v13[1]))))
                                                                                              * (float)0.5))
                                                                              * (float)v19)
                                                                      - (float)1.5)
                                                      * (float)v19)
                                              * (float)((float)((float)((float)(v39.z - v13[2]) * (float)(v39.z - v13[2]))
                                                              + (float)((float)((float)(v39.x - *v13)
                                                                              * (float)(v39.x - *v13))
                                                                      + (float)((float)(v39.y - v13[1])
                                                                              * (float)(v39.y - v13[1]))))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v19
                                                                              * (float)((float)((float)((float)(v39.z - v13[2]) * (float)(v39.z - v13[2]))
                                                                                              + (float)((float)((float)(v39.x - *v13) * (float)(v39.x - *v13)) + (float)((float)(v39.y - v13[1]) * (float)(v39.y - v13[1]))))
                                                                                      * (float)0.5))
                                                                      * (float)v19)
                                                              - (float)1.5)
                                              * (float)v19))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v19
                                                      * (float)((float)((float)((float)(v39.z - v13[2])
                                                                              * (float)(v39.z - v13[2]))
                                                                      + (float)((float)((float)(v39.x - *v13)
                                                                                      * (float)(v39.x - *v13))
                                                                              + (float)((float)(v39.y - v13[1])
                                                                                      * (float)(v39.y - v13[1]))))
                                                              * (float)0.5))
                                              * (float)v19)
                                      - (float)1.5)
                      * (float)v19));
  v21 = (float)((float)-(float)((float)((float)((float)v20
                                              * (float)((float)((float)((float)(v39.z - v13[2]) * (float)(v39.z - v13[2]))
                                                              + (float)((float)((float)(v39.x - *v13)
                                                                              * (float)(v39.x - *v13))
                                                                      + (float)((float)(v39.y - v13[1])
                                                                              * (float)(v39.y - v13[1]))))
                                                      * (float)0.5))
                                      * (float)v20)
                              - (float)1.5)
              * (float)v20);
  v22 = (float)((float)(v39.y - v13[1])
              * (float)((float)-(float)((float)((float)((float)v20
                                                      * (float)((float)((float)((float)(v39.z - v13[2])
                                                                              * (float)(v39.z - v13[2]))
                                                                      + (float)((float)((float)(v39.x - *v13)
                                                                                      * (float)(v39.x - *v13))
                                                                              + (float)((float)(v39.y - v13[1])
                                                                                      * (float)(v39.y - v13[1]))))
                                                              * (float)0.5))
                                              * (float)v20)
                                      - (float)1.5)
                      * (float)v20));
  v38.pitch = (float)(v39.x - *v13)
            * (float)((float)-(float)((float)((float)((float)v20
                                                    * (float)((float)((float)((float)(v39.z - v13[2])
                                                                            * (float)(v39.z - v13[2]))
                                                                    + (float)((float)((float)(v39.x - *v13)
                                                                                    * (float)(v39.x - *v13))
                                                                            + (float)((float)(v39.y - v13[1])
                                                                                    * (float)(v39.y - v13[1]))))
                                                            * (float)0.5))
                                            * (float)v20)
                                    - (float)1.5)
                    * (float)v20);
  v38.yaw = v22;
  v38.roll = (float)v14 * (float)v21;
  if ( v15 != 0 && (float)((float)v21 * (float)v16) > (double)this->distanceConstraint )
    return 0;
  v24 = idEntity::GetPhysics(this);
  v25 = (int)v24->GetAxis(this: v24, a2: 0);
  v26 = &v42;
  v27 = (_DWORD *)(v25 - 4);
  for ( i = 9; i != 0; --i )
  {
    ++v27;
    v26 += 4;
    *(_DWORD *)v26 = *v27;
  }
  idMat3::Inverse(this: &v41, result: &v43);
  v29 = (float)((float)(v41.mat[0].y * v38.pitch)
              + (float)((float)(v41.mat[2].y * v38.roll) + (float)(v41.mat[1].y * v38.yaw)));
  v30 = (float)((float)(v41.mat[0].z * v38.pitch)
              + (float)((float)(v41.mat[2].z * v38.roll) + (float)(v41.mat[1].z * v38.yaw)));
  v38.pitch = (float)(v41.mat[0].x * v38.pitch)
            + (float)((float)(v41.mat[2].x * v38.roll) + (float)(v41.mat[1].x * v38.yaw));
  v38.yaw = v29;
  v38.roll = v30;
  idVec3::ToAngles(this: &v40, result: &v38);
  *((double *)&v31 + 1) = v40.y;
  *(double *)&v32 = (float)((float)(this->angleConstraintHorizontal.value * (float)0.5) + v40.y);
  *((double *)&v32 + 1) = 360.0;
  v33 = fmod(dX: v32, dY: v31);
  *(double *)&v34 = (float)*(double *)&v33;
  v40.y = *(double *)&v33;
  *((double *)&v33 + 1) = 360.0;
  *(double *)&v33 = (float)((float)(this->angleConstraintVertical.value * (float)0.5) + v40.x);
  v35 = fmod(dX: v33, dY: v34);
  useFlags = this->useFlags;
  v37 = (float)*(double *)&v35;
  if ( (useFlags & 1) != 0 && (v40.y < 0.0 || v40.y > (double)this->angleConstraintHorizontal.value) )
    return 0;
  if ( (useFlags & 2) != 0 && (v37 < 0.0 || v37 > this->angleConstraintVertical.value) )
    return 0;
  else
    return 3;
}


// ========================================================================
// ?ModifyCrosshairInfo@idUse@@UBA_NPBVidEntity@@ABVidFocusTrace@@W4usableState_t@@AAVidCrosshairInfo@@@Z
// EA  : 0x82C9BBB8
// RVA : 0x00C9BBB8
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

int __fastcall idUse::ModifyCrosshairInfo(
        idUse *this,
        idPlayer *activator,
        const idFocusTrace *ft,
        const usableState_t usable,
        idCrosshairInfo *info)
{
  idCrosshairCustomIcon *list; // r10
  idCrosshairCustomIcon *v9; // r8

  if ( usable == USABLE_NOT_USABLE )
    return 0;
  if ( idPlayer::CastTo(c: activator) != nullptr )
  {
    list = info->icons.list;
    info->text.index = this->displayText.index;
    list->material = this->displayIcon;
    v9 = info->icons.list;
    info->hideCrossHairInfo = (*((_BYTE *)this + 844) & 0x10) != 0;
    v9->usable = (*(_BYTE *)&this->flags & 8) != 0;
  }
  return 1;
}


// ========================================================================
// ?Event_DelayedActivation@idUse@@AAA?AVeventVoid@@PAVidEntity@@W4usableState_t@@@Z
// EA  : 0x82C9BC40
// RVA : 0x00C9BC40
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

idUse *__fastcall idUse::Event_DelayedActivation(idUse *this, idUse *result, idEntity *activator, usableState_t usable)
{
  idUse::RunUse(this: result, activator, usable);
  return this;
}


// ========================================================================
// ?SetNoBlink@idUse@@QAAX_N@Z
// EA  : 0x82C9BC80
// RVA : 0x00C9BC80
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void __fastcall idUse::SetNoBlink(idUse *this, bool noBlink_)
{
  idUse_vtbl *v2; // r9
  char flags; // r8

  v2 = this->__vftable;
  flags = (char)this->flags;
  *((_BYTE *)this + 844) = (32 * noBlink_) & 0x20 | *((_BYTE *)this + 844) & 0xDF;
  v2->OnMakeActivatable(this, a2: (flags & 8) != 0);
  idEntity::UpdateVisuals(this);
}


// ========================================================================
// ?GetUsableState@idPropSmartLoot@@UBA?AW4usableState_t@@PBVidEntity@@ABVidFocusTrace@@@Z
// EA  : 0x82C9BCD8
// RVA : 0x00C9BCD8
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

int __fastcall idPropSmartLoot::GetUsableState(idPropSmartLoot *this, idPlayer *activator, const idFocusTrace *ft)
{
  return idUse::GetUsableState(this, activator, ft) == 0 ? 0 : 2;
}


// ========================================================================
// ??1idProp_Usable@@UAA@XZ
// EA  : 0x82C9BD08
// RVA : 0x00C9BD08
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void __fastcall idProp_Usable::~idProp_Usable(idProp_Usable *this)
{
  this->__vftable = (idProp_Usable_vtbl *)&idProp::`vftable';
  idAnimatedEntity::~idAnimatedEntity(this);
}


// ========================================================================
// ?GetUseLocation@idProp_Usable@@UBAXPBVidActor@@AAVidVec3@@@Z
// EA  : 0x82C9BD18
// RVA : 0x00C9BD18
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void __fastcall idProp_Usable::GetUseLocation(idProp_Usable *this, const idActor *actor, idVec3 *pos)
{
  idPhysics *Physics; // r3
  float *v7; // r3
  idPhysics *v8; // r3
  float *v9; // r3
  double v12; // fp5
  double v13; // fp3
  double v14; // fp31
  double v15; // fp30
  double v16; // fp29
  idPhysics *v17; // r3
  float *v18; // r3
  int v19; // r30
  idPhysics *v20; // r3
  idPhysics *v21; // r3
  int v22; // r3
  idPhysics *v23; // r3
  float v24; // [sp+50h] [-50h]
  float v25; // [sp+54h] [-4Ch]
  float v26; // [sp+58h] [-48h]

  Physics = idEntity::GetPhysics(this);
  v7 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
  v24 = *v7;
  v25 = v7[1];
  v26 = v7[2];
  if ( this->use_radius == 0.0 )
  {
    v17 = idEntity::GetPhysics(this);
    v18 = (float *)v17->GetAxis(this: v17, a2: 0);
    v15 = (float)((float)((float)(this->use_vec.x * *v18)
                        + (float)((float)(v18[3] * this->use_vec.y) + (float)(v18[6] * this->use_vec.z)))
                + v24);
    v16 = (float)((float)((float)(v18[7] * this->use_vec.z)
                        + (float)((float)(v18[1] * this->use_vec.x) + (float)(v18[4] * this->use_vec.y)))
                + v25);
    v14 = (float)((float)((float)(v18[8] * this->use_vec.z)
                        + (float)((float)(v18[2] * this->use_vec.x) + (float)(v18[5] * this->use_vec.y)))
                + v26);
  }
  else
  {
    v8 = idEntity::GetPhysics(this: &actor->idAnimatedEntity);
    v9 = (float *)v8->GetOrigin(this: v8, a2: 0);
    _FP1 = (float)((float)((float)((float)(v9[1] - v25) * (float)(v9[1] - v25))
                         + (float)((float)(*v9 - v24) * (float)(*v9 - v24)))
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm { fsel      f7, f1, f2, f13 }
    v12 = __frsqrte(_FP7);
    v13 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v12
                                                                                        * (float)((float)((float)((float)(v9[1] - v25) * (float)(v9[1] - v25)) + (float)((float)(*v9 - v24) * (float)(*v9 - v24)))
                                                                                                * (float)0.5))
                                                                                * (float)v12)
                                                                        - (float)1.5)
                                                        * (float)v12)
                                                * (float)((float)((float)((float)(v9[1] - v25) * (float)(v9[1] - v25))
                                                                + (float)((float)(*v9 - v24) * (float)(*v9 - v24)))
                                                        * (float)0.5))
                                        * (float)((float)-(float)((float)((float)((float)v12
                                                                                * (float)((float)((float)((float)(v9[1] - v25) * (float)(v9[1] - v25))
                                                                                                + (float)((float)(*v9 - v24) * (float)(*v9 - v24)))
                                                                                        * (float)0.5))
                                                                        * (float)v12)
                                                                - (float)1.5)
                                                * (float)v12))
                                - (float)1.5)
                * (float)((float)-(float)((float)((float)((float)v12
                                                        * (float)((float)((float)((float)(v9[1] - v25)
                                                                                * (float)(v9[1] - v25))
                                                                        + (float)((float)(*v9 - v24) * (float)(*v9 - v24)))
                                                                * (float)0.5))
                                                * (float)v12)
                                        - (float)1.5)
                        * (float)v12));
    v14 = (float)((float)(this->use_radius
                        * (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v12 * (float)((float)((float)((float)(v9[1] - v25) * (float)(v9[1] - v25)) + (float)((float)(*v9 - v24) * (float)(*v9 - v24))) * (float)0.5)) * (float)v12) - (float)1.5) * (float)v12) * (float)((float)((float)((float)(v9[1] - v25) * (float)(v9[1] - v25)) + (float)((float)(*v9 - v24) * (float)(*v9 - v24))) * (float)0.5)) * (float)((float)-(float)((float)((float)((float)v12 * (float)((float)((float)((float)(v9[1] - v25) * (float)(v9[1] - v25)) + (float)((float)(*v9 - v24) * (float)(*v9 - v24))) * (float)0.5)) * (float)v12) - (float)1.5) * (float)v12))
                                                                                                - (float)1.5)
                                                                                * (float)((float)-(float)((float)((float)((float)v12 * (float)((float)((float)((float)(v9[1] - v25) * (float)(v9[1] - v25)) + (float)((float)(*v9 - v24) * (float)(*v9 - v24))) * (float)0.5)) * (float)v12) - (float)1.5)
                                                                                        * (float)v12))
                                                                        * (float)((float)((float)((float)(v9[1] - v25)
                                                                                                * (float)(v9[1] - v25))
                                                                                        + (float)((float)(*v9 - v24)
                                                                                                * (float)(*v9 - v24)))
                                                                                * (float)0.5))
                                                                * (float)v13)
                                                        - (float)1.5)
                                        * (float)v13)
                                * (float)0.0))
                + v26);
    v15 = (float)((float)(this->use_radius
                        * (float)((float)(*v9 - v24)
                                * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v12 * (float)((float)((float)((float)(v9[1] - v25) * (float)(v9[1] - v25)) + (float)((float)(*v9 - v24) * (float)(*v9 - v24))) * (float)0.5)) * (float)v12) - (float)1.5) * (float)v12) * (float)((float)((float)((float)(v9[1] - v25) * (float)(v9[1] - v25)) + (float)((float)(*v9 - v24) * (float)(*v9 - v24))) * (float)0.5)) * (float)((float)-(float)((float)((float)((float)v12 * (float)((float)((float)((float)(v9[1] - v25) * (float)(v9[1] - v25)) + (float)((float)(*v9 - v24) * (float)(*v9 - v24))) * (float)0.5)) * (float)v12) - (float)1.5) * (float)v12))
                                                                                                - (float)1.5)
                                                                                * (float)((float)-(float)((float)((float)((float)v12 * (float)((float)((float)((float)(v9[1] - v25) * (float)(v9[1] - v25)) + (float)((float)(*v9 - v24) * (float)(*v9 - v24))) * (float)0.5)) * (float)v12) - (float)1.5)
                                                                                        * (float)v12))
                                                                        * (float)((float)((float)((float)(v9[1] - v25)
                                                                                                * (float)(v9[1] - v25))
                                                                                        + (float)((float)(*v9 - v24)
                                                                                                * (float)(*v9 - v24)))
                                                                                * (float)0.5))
                                                                * (float)v13)
                                                        - (float)1.5)
                                        * (float)v13)))
                + v24);
    v16 = (float)((float)((float)((float)(v9[1] - v25)
                                * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v12 * (float)((float)((float)((float)(v9[1] - v25) * (float)(v9[1] - v25)) + (float)((float)(*v9 - v24) * (float)(*v9 - v24))) * (float)0.5)) * (float)v12) - (float)1.5) * (float)v12) * (float)((float)((float)((float)(v9[1] - v25) * (float)(v9[1] - v25)) + (float)((float)(*v9 - v24) * (float)(*v9 - v24))) * (float)0.5)) * (float)((float)-(float)((float)((float)((float)v12 * (float)((float)((float)((float)(v9[1] - v25) * (float)(v9[1] - v25)) + (float)((float)(*v9 - v24) * (float)(*v9 - v24))) * (float)0.5)) * (float)v12) - (float)1.5) * (float)v12))
                                                                                                - (float)1.5)
                                                                                * (float)((float)-(float)((float)((float)((float)v12 * (float)((float)((float)((float)(v9[1] - v25) * (float)(v9[1] - v25)) + (float)((float)(*v9 - v24) * (float)(*v9 - v24))) * (float)0.5)) * (float)v12) - (float)1.5)
                                                                                        * (float)v12))
                                                                        * (float)((float)((float)((float)(v9[1] - v25)
                                                                                                * (float)(v9[1] - v25))
                                                                                        + (float)((float)(*v9 - v24)
                                                                                                * (float)(*v9 - v24)))
                                                                                * (float)0.5))
                                                                * (float)v13)
                                                        - (float)1.5)
                                        * (float)v13))
                        * this->use_radius)
                + v25);
  }
  v19 = 0;
  v20 = idEntity::GetPhysics(this);
  if ( v20->GetNumContacts(this: v20) > 0 )
  {
    do
    {
      v21 = idEntity::GetPhysics(this);
      v22 = (int)v21->GetContact(this: v21, a2: v19);
      if ( *(float *)(v22 + 12) < v14 )
        v14 = *(float *)(v22 + 12);
      ++v19;
      v23 = idEntity::GetPhysics(this);
    }
    while ( v19 < v23->GetNumContacts(this: v23) );
  }
  pos->x = v15;
  pos->y = v16;
  pos->z = v14;
}


// ========================================================================
// ?IsUsable@idProp_Usable@@QBA_NXZ
// EA  : 0x82C9BF58
// RVA : 0x00C9BF58
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

int __fastcall idProp_Usable::IsUsable(idProp_Usable *this)
{
  unsigned __int8 v1; // r11

  if ( !this->isUsable )
    return 0;
  v1 = 1;
  if ( (*(_BYTE *)&this->flags & 8) == 0 )
    return 0;
  return v1;
}


// ========================================================================
// ?ModifyCrosshairInfo@idProp_Usable@@UBA_NPBVidEntity@@ABVidFocusTrace@@W4usableState_t@@AAVidCrosshairInfo@@@Z
// EA  : 0x82C9BF88
// RVA : 0x00C9BF88
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

int __fastcall idProp_Usable::ModifyCrosshairInfo(
        idProp_Usable *this,
        idPlayer *activator,
        const idFocusTrace *ft,
        usableState_t usable,
        idCrosshairInfo *info)
{
  bool v10; // r11

  if ( idPlayer::CastTo(c: activator) != nullptr )
  {
    info->icons.list->material = this->displayIcon;
    info->hoverSound = this->hoverSound;
    if ( !this->isUsable || (v10 = true, (*(_BYTE *)&this->flags & 8) == 0) )
      v10 = false;
    info->icons.list->usable = v10;
  }
  return idEntity::ModifyCrosshairInfo(this, activator, ft, usable, info);
}


// ========================================================================
// ?Event_DelayedActivation@idProp_Usable@@AAA?AVeventVoid@@PAVidEntity@@W4usableState_t@@@Z
// EA  : 0x82C9C018
// RVA : 0x00C9C018
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

idProp_Usable *__fastcall idProp_Usable::Event_DelayedActivation(
        idProp_Usable *this,
        idEntity *result,
        idEntity *activator,
        usableState_t usable)
{
  idEventReceiver v8[5]; // [sp+50h] [-40h] BYREF

  idEntity::Use(this: result, activator, usable);
  if ( HIBYTE(result[6].bindInfo.bindMaster) != 0 )
    result->ActivateTargets(this: result, a2: activator);
  idEventReceiver::ProcessEvent(this: v8, (idEventArg *)result, ev: &EV_NotifyProgressionOwner);
  return this;
}


// ========================================================================
// ?PlayUseSound@idProp_Usable@@QAAXXZ
// EA  : 0x82C9C088
// RVA : 0x00C9C088
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void __fastcall idProp_Usable::PlayUseSound(idProp_Usable *this)
{
  unsigned __int8 overrideSoundPeerMask; // r29

  overrideSoundPeerMask = clientGame->overrideSoundPeerMask;
  clientGame->overrideSoundPeerMask = -1;
  idEntity::StartSoundShader(
    this,
    channel: SND_CHANNEL_BODY,
    shader: this->sound_use,
    soundShaderFlags: (soundShaderFlags_t)0,
    peerMask: 0xFFu);
  clientGame->overrideSoundPeerMask = overrideSoundPeerMask;
}


// ========================================================================
// ?Event_IsUpright@idProp_Usable@@AAA?AVeventFloat@@XZ
// EA  : 0x82C9C0D8
// RVA : 0x00C9C0D8
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

idProp_Usable *__fastcall idProp_Usable::Event_IsUpright(idProp_Usable *this, idEntity *result)
{
  idPhysics *Physics; // r3
  double v4; // fp1

  Physics = idEntity::GetPhysics(this: result);
  if ( Physics->GetAxis(this: Physics, a2: 0)->mat[2].z < 0.99939084 )
    v4 = 0.0;
  else
    v4 = 1.0;
  eventFloat::eventFloat((eventFloat *)this, f: v4);
  return this;
}


// ========================================================================
// ?BeforeUse@idProp_ContinuallyUsed@@UAA_NPAVidEntity@@@Z
// EA  : 0x82C9C150
// RVA : 0x00C9C150
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

int __fastcall idProp_ContinuallyUsed::BeforeUse(idProp_ContinuallyUsed *this, idActor *activator)
{
  char v4; // r11
  idProp_ContinuallyUsed_vtbl *v5; // r10
  idScriptObject *v6; // r3
  idScriptObject *v7; // r3
  idScriptFunction v9; // [sp+50h] [-160h] BYREF

  if ( this->user != nullptr )
    return 0;
  if ( !this->isUsable || (v4 = 1, (*(_BYTE *)&this->flags & 8) == 0) )
    v4 = 0;
  if ( v4 == 0 )
    return 0;
  idEntity::BecomeActive(this, flags: 1);
  this->user = idActor::CastTo(c: activator);
  idEntity::StartSoundShader(
    this,
    channel: SND_CHANNEL_BODY,
    shader: this->soundProgressing,
    soundShaderFlags: (soundShaderFlags_t)0,
    peerMask: 0xFFu);
  v5 = this->__vftable;
  this->enumUseState = PROGRESSING;
  v6 = v5->GetScriptObject_2(this);
  if ( idScriptObject::HasObject(this: v6) )
  {
    v7 = this->GetScriptObject_2(this);
    if ( idScriptObject::GetFunction(this: v7, name: "activated") != nullptr )
    {
      idScriptFunction::idScriptFunction(this: &v9);
      idScriptFunction::SetFunction(this: &v9, ent: this, functionName: "activated", returnType: ev_void, numParms: 0);
      if ( idScriptFunction::GetFunction(this: &v9) != nullptr )
        idScriptFunction::CallFunction(this: &v9, defer: true);
    }
  }
  return 1;
}


// ========================================================================
// ?Use@idProp_ContinuallyUsed@@UAA_NPAVidEntity@@W4usableState_t@@@Z
// EA  : 0x82C9C290
// RVA : 0x00C9C290
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

int __fastcall idProp_ContinuallyUsed::Use(
        idProp_ContinuallyUsed *this,
        idEntity *activator,
        const usableState_t usable)
{
  idScriptObject *v5; // r3
  idScriptObject *v6; // r3
  char **SpawnId; // r3
  const idSoundShader *soundRegressing; // r5
  char v10; // [sp+50h] [-180h] BYREF
  idScriptFunction v11; // [sp+60h] [-170h] BYREF

  if ( this->enumUseState != PROGRESSING )
    return 0;
  v5 = this->GetScriptObject_2(this);
  if ( idScriptObject::HasObject(this: v5) )
  {
    v6 = this->GetScriptObject_2(this);
    if ( idScriptObject::GetFunction(this: v6, name: "deactivated") != nullptr )
    {
      idScriptFunction::idScriptFunction(this: &v11);
      idScriptFunction::SetFunction(
        this: &v11,
        ent: this,
        functionName: "deactivated",
        returnType: ev_void,
        numParms: 0);
      if ( idScriptFunction::GetFunction(this: &v11) != nullptr )
        idScriptFunction::CallFunction(this: &v11, defer: true);
    }
  }
  SpawnId = (char **)idGameLocal::GetSpawnId(this: (idGameLocal *)&v10, result: (idSpawnId *)gameLocal, ent: activator);
  idEntity::SendNotify_OnUse(this, user: *SpawnId);
  soundRegressing = this->soundRegressing;
  this->user = nullptr;
  this->enumUseState = REGRESSING;
  idEntity::StartSoundShader(
    this,
    channel: SND_CHANNEL_BODY,
    shader: soundRegressing,
    soundShaderFlags: (soundShaderFlags_t)0,
    peerMask: 0xFFu);
  return 1;
}


// ========================================================================
// ?Event_SetUsePercent@idProp_ContinuallyUsed@@AAA?AVeventVoid@@M@Z
// EA  : 0x82C9C3A0
// RVA : 0x00C9C3A0
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

idProp_ContinuallyUsed *__fastcall idProp_ContinuallyUsed::Event_SetUsePercent(
        idProp_ContinuallyUsed *this,
        idEntity *result,
        double usePercent)
{
  idScriptObject *v6; // r3
  idScriptObject *v7; // r3
  idScriptFunction v9; // [sp+50h] [-170h] BYREF

  *(float *)&result[6].dormancy.forceDormant = usePercent;
  v6 = result->GetScriptObject_2(this: result);
  if ( idScriptObject::HasObject(this: v6) )
  {
    v7 = result->GetScriptObject_2(this: result);
    if ( idScriptObject::GetFunction(this: v7, name: "useStateSet") != nullptr )
    {
      idScriptFunction::idScriptFunction(this: &v9);
      idScriptFunction::SetFunction(
        this: &v9,
        ent: result,
        functionName: "useStateSet",
        returnType: ev_void,
        numParms: 1,
        4,
        "value");
      if ( idScriptFunction::GetFunction(this: &v9) != nullptr )
      {
        idScriptFunction::SetArg_Float(this: &v9, argNum: 0, value: usePercent);
        idScriptFunction::CallFunction(this: &v9, defer: true);
      }
    }
  }
  return this;
}


// ========================================================================
// ?Event_SetRateOfIncrease@idProp_ContinuallyUsed@@AAA?AVeventVoid@@M@Z
// EA  : 0x82C9C478
// RVA : 0x00C9C478
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
__int64 __fastcall idProp_ContinuallyUsed::Event_SetRateOfIncrease(idProp_ContinuallyUsed *this, double rate)
{
  __int64 result; // r4 OVERLAPPED

  *(float *)(result + 5308) = rate;
  return result;
}


// ========================================================================
// ?Event_SetRateOfDecrease@idProp_ContinuallyUsed@@AAA?AVeventVoid@@M@Z
// EA  : 0x82C9C480
// RVA : 0x00C9C480
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
__int64 __fastcall idProp_ContinuallyUsed::Event_SetRateOfDecrease(idProp_ContinuallyUsed *this, double rate)
{
  __int64 result; // r4 OVERLAPPED

  *(float *)(result + 5312) = rate;
  return result;
}


// ========================================================================
// ?ModifyCrosshairInfo@idProp_ContinuallyUsed@@UBA_NPBVidEntity@@ABVidFocusTrace@@W4usableState_t@@AAVidCrosshairInfo@@@Z
// EA  : 0x82C9C488
// RVA : 0x00C9C488
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

int __fastcall idProp_ContinuallyUsed::ModifyCrosshairInfo(
        idProp_ContinuallyUsed *this,
        idPlayer *activator,
        const idFocusTrace *ft,
        usableState_t usable,
        idCrosshairInfo *info)
{
  int result; // r3

  result = idProp_Usable::ModifyCrosshairInfo(this, activator, ft, usable, info);
  info->useAmount = this->usedState;
  return result;
}


// ========================================================================
// ?InitPropPhysics@idProp_Moveable@@UAAXXZ
// EA  : 0x82C9C4C8
// RVA : 0x00C9C4C8
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void __fastcall idProp_Moveable::InitPropPhysics(idProp_Moveable *this)
{
  idPhysics_RigidBody *p_physicsObj; // r30
  double density; // fp31
  idPhysics_RigidBody_vtbl *v4; // r29
  idClipModel *MoveableClipModel; // r3
  idPhysics_RigidBody_vtbl *v6; // r29
  int v7; // r3
  idPhysics_RigidBody_vtbl *v8; // r29
  int v9; // r3
  int v10; // r5
  idPhysics *Physics; // r3
  int v12; // r11

  p_physicsObj = &this->physicsObj;
  idPhysics::InitPhysics(
    this: &this->physicsObj,
    clip_: &clientGame->clip,
    callbacks_: &this->physicsCallbacks,
    entityNumber_: this->entityNumber);
  idPhysics_RigidBody::SetBouncyness(this: p_physicsObj, b: this->bouncyness);
  idPhysics_RigidBody::SetFriction(
    this: p_physicsObj,
    linear: this->linearFriction,
    angular: this->angularFriction,
    contact: this->friction);
  this->physicsObj.SetGravity(this: p_physicsObj, a2: &gameLocal->clientGame.gravity);
  idPhysics_RigidBody::SetInertiaScale(this: p_physicsObj, v: &this->inertiaScale);
  density = this->density;
  v4 = this->physicsObj.__vftable;
  MoveableClipModel = idEntity::CreateMoveableClipModel(
                        this,
                        barrelCollision: (*((_BYTE *)this + 5296) & 0x10) != 0,
                        overrideRadius: -1.0);
  ((void (__fastcall *)(idPhysics_RigidBody *, idClipModel *, double))v4->SetClipModel)(
    a1: p_physicsObj,
    a2: MoveableClipModel,
    a3: density);
  this->physicsObj.SetOrigin(this: p_physicsObj, a2: &this->spawnPosition, a3: -1);
  this->physicsObj.SetAxis(this: p_physicsObj, a2: &this->spawnOrientation, a3: -1);
  v6 = this->physicsObj.__vftable;
  v7 = idContents::ToFlags(this: &this->clipOverride.contents);
  v6->SetContents(this: p_physicsObj, a2: v7, a3: -1);
  v8 = this->physicsObj.__vftable;
  v9 = idContents::ToFlags(this: &this->clipOverride.clipMask);
  v8->SetClipMask(this: p_physicsObj, a2: v9, a3: -1);
  idEntity::SetPhysics(this, phys: p_physicsObj, a3: v10);
  if ( (*((_BYTE *)this + 5296) & 1) != 0 )
  {
    *((_BYTE *)&p_physicsObj->fl + 4) |= 0xC0u;
  }
  else
  {
    Physics = idEntity::GetPhysics(this);
    this->DeactivatePhysics(this, a2: Physics->physicsId);
  }
  if ( (*((_BYTE *)this + 5296) & 4) != 0
    || (*((_BYTE *)this + 5296) & 2) != 0
    || (p_physicsObj->GetContents(this: p_physicsObj, a2: -1) & 0x400000) != 0 )
  {
    v12 = 0;
    if ( (*((_BYTE *)this + 5296) & 4) == 0 )
      v12 = 33792;
    if ( (*((_BYTE *)this + 5296) & 2) == 0 )
      v12 |= 0x10000u;
    this->physicsObj.fl.noPushMask = v12;
  }
  else
  {
    *((_BYTE *)&p_physicsObj->fl + 4) |= 0x20u;
  }
}


// ========================================================================
// ?Show@idProp_Moveable@@UAAXXZ
// EA  : 0x82C9C6F0
// RVA : 0x00C9C6F0
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void __fastcall idProp_Moveable::Show(idProp_Moveable *this)
{
  idEntity::Show(this);
  idProp_Moveable::BecomeSolid(this);
}


// ========================================================================
// ?Collide@idProp_Moveable@@UAA?AW4collide_t@@HAAUtrace_t@@ABVidVec3@@@Z
// EA  : 0x82C9C728
// RVA : 0x00C9C728
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

collide_t __fastcall idProp_Moveable::Collide(
        idProp_Moveable *this,
        const int physId,
        trace_t *collision,
        const idVec3 *velocity)
{
  char v7; // r29
  char v8; // r28
  double v9; // fp28
  double v12; // fp9
  double v13; // fp2
  double v14; // fp0
  double v15; // fp26
  long double v16; // fp2
  double v17; // fp31
  idPhysics *Physics; // r3
  float *v19; // r3
  float y; // r8
  float z; // r7
  float v22; // r6
  float v23; // r5
  float v24; // r4
  idPhysics *v25; // r3
  float *v26; // r3
  double v27; // fp31
  double v28; // fp30
  double x; // fp29
  long double v30; // fp2
  double v31; // fp3
  long double v32; // fp2
  double v33; // fp30
  const idSoundShader *sound_scrape; // r5
  const idSoundShader *v35; // r5
  int damage; // r11
  double v37; // fp12
  double v40; // fp3
  double v41; // fp7
  double v42; // fp5
  double v43; // fp4
  double v44; // fp3
  idGameLocal *v45; // r28
  idEntity *v46; // r29
  double v47; // fp31
  double v48; // fp13
  double v49; // fp12
  const idDeclDamage *damageMoverCrush; // r30
  idPhysics *v51; // r3
  int v52; // r3
  int v53; // r7
  __int64 v54; // r6
  int v55; // r4
  idEntity *v56; // r30
  __int64 v57; // r7
  idProp_Moveable_vtbl *v58; // r10
  idVec3 v60; // [sp+50h] [-D0h] BYREF
  idVec3 v61; // [sp+60h] [-C0h] BYREF
  idVec3 v62; // [sp+70h] [-B0h] BYREF

  v7 = 1;
  v8 = 0;
  v9 = (float)-(float)((float)(collision->c.normal.x * velocity->x)
                     + (float)((float)(collision->c.normal.z * velocity->z)
                             + (float)(collision->c.normal.y * velocity->y)));
  _FP12 = (float)((float)((float)(velocity->z * velocity->z)
                        + (float)((float)(velocity->x * velocity->x) + (float)(velocity->y * velocity->y)))
                - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f10, f12, f13, f8 }
  v12 = __frsqrte(_FP10);
  v13 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v12
                                                                                      * (float)((float)((float)(velocity->z * velocity->z) + (float)((float)(velocity->x * velocity->x) + (float)(velocity->y * velocity->y)))
                                                                                              * (float)0.5))
                                                                              * (float)v12)
                                                                      - (float)1.5)
                                                      * (float)v12)
                                              * (float)((float)((float)(velocity->z * velocity->z)
                                                              + (float)((float)(velocity->x * velocity->x)
                                                                      + (float)(velocity->y * velocity->y)))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v12
                                                                              * (float)((float)((float)(velocity->z * velocity->z)
                                                                                              + (float)((float)(velocity->x * velocity->x) + (float)(velocity->y * velocity->y)))
                                                                                      * (float)0.5))
                                                                      * (float)v12)
                                                              - (float)1.5)
                                              * (float)v12))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v12
                                                      * (float)((float)((float)(velocity->z * velocity->z)
                                                                      + (float)((float)(velocity->x * velocity->x)
                                                                              + (float)(velocity->y * velocity->y)))
                                                              * (float)0.5))
                                              * (float)v12)
                                      - (float)1.5)
                      * (float)v12));
  v14 = (float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v12 * (float)((float)((float)(velocity->z * velocity->z) + (float)((float)(velocity->x * velocity->x) + (float)(velocity->y * velocity->y))) * (float)0.5)) * (float)v12) - (float)1.5)
                                                                                      * (float)v12)
                                                                              * (float)((float)((float)(velocity->z * velocity->z)
                                                                                              + (float)((float)(velocity->x * velocity->x) + (float)(velocity->y * velocity->y)))
                                                                                      * (float)0.5))
                                                                      * (float)((float)-(float)((float)((float)((float)v12 * (float)((float)((float)(velocity->z * velocity->z) + (float)((float)(velocity->x * velocity->x) + (float)(velocity->y * velocity->y))) * (float)0.5)) * (float)v12)
                                                                                              - (float)1.5)
                                                                              * (float)v12))
                                                              - (float)1.5)
                                              * (float)((float)-(float)((float)((float)((float)v12
                                                                                      * (float)((float)((float)(velocity->z * velocity->z) + (float)((float)(velocity->x * velocity->x) + (float)(velocity->y * velocity->y)))
                                                                                              * (float)0.5))
                                                                              * (float)v12)
                                                                      - (float)1.5)
                                                      * (float)v12))
                                      * (float)((float)((float)(velocity->z * velocity->z)
                                                      + (float)((float)(velocity->x * velocity->x)
                                                              + (float)(velocity->y * velocity->y)))
                                              * (float)0.5))
                              * (float)v13)
                      - (float)1.5);
  v15 = (float)((float)((float)v14
                      * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v12 * (float)((float)((float)(velocity->z * velocity->z) + (float)((float)(velocity->x * velocity->x) + (float)(velocity->y * velocity->y))) * (float)0.5))
                                                                                              * (float)v12)
                                                                                      - (float)1.5)
                                                                      * (float)v12)
                                                              * (float)((float)((float)(velocity->z * velocity->z)
                                                                              + (float)((float)(velocity->x * velocity->x)
                                                                                      + (float)(velocity->y * velocity->y)))
                                                                      * (float)0.5))
                                                      * (float)((float)-(float)((float)((float)((float)v12
                                                                                              * (float)((float)((float)(velocity->z * velocity->z) + (float)((float)(velocity->x * velocity->x) + (float)(velocity->y * velocity->y))) * (float)0.5))
                                                                                      * (float)v12)
                                                                              - (float)1.5)
                                                              * (float)v12))
                                              - (float)1.5)
                              * (float)((float)-(float)((float)((float)((float)v12
                                                                      * (float)((float)((float)(velocity->z * velocity->z)
                                                                                      + (float)((float)(velocity->x * velocity->x)
                                                                                              + (float)(velocity->y * velocity->y)))
                                                                              * (float)0.5))
                                                              * (float)v12)
                                                      - (float)1.5)
                                      * (float)v12)))
              * (float)((float)(velocity->z * velocity->z)
                      + (float)((float)(velocity->x * velocity->x) + (float)(velocity->y * velocity->y))));
  if ( v9 <= this->bounceMinVelocity )
  {
    if ( (*((_BYTE *)this + 5296) & 0x10) != 0 )
    {
      Physics = idEntity::GetPhysics(this);
      v19 = (float *)Physics->GetAxis(this: Physics, a2: 0);
      y = velocity->y;
      z = velocity->z;
      v22 = v19[6];
      v23 = v19[7];
      v24 = v19[8];
      v62.x = velocity->x;
      v62.y = y;
      v60.x = v22;
      v60.y = v23;
      v60.z = v24;
      v62.z = z;
      idVec3::NormalizeFast(this: &v60);
      idVec3::NormalizeFast(this: &v62);
      v25 = idEntity::GetPhysics(this);
      v26 = (float *)v25->GetGravityNormal(this: v25);
      v27 = v60.y;
      v28 = v60.z;
      x = v60.x;
      *(double *)&v30 = (float)((float)(v60.x * *v26) + (float)((float)(v26[2] * v60.z) + (float)(v26[1] * v60.y)));
      v31 = (float)((float)90.0 - (float)(idMath::ACos(a: v30) * idMath::M_RAD2DEG));
      *(double *)&v32 = (float)((float)(v62.x * (float)x)
                              + (float)((float)(v62.z * (float)v28) + (float)(v62.y * (float)v27)));
      v33 = __fabs(v31);
      if ( __fabs((float)-(float)((float)(idMath::ACos(a: v32) * idMath::M_RAD2DEG) - (float)90.0)) < 45.0 && v33 < 30.0 )
      {
        v8 = 1;
        v7 = 0;
      }
      if ( v7 != 0 && v33 < 20.0 && v15 < (float)(this->bounceMinVelocity * (float)0.5) )
        v7 = 0;
    }
    if ( v8 == 0 && v7 == 0 || v15 < (float)(this->bounceMinVelocity * (float)0.25) )
    {
      v7 = 0;
      idEntity::StopSound(this, channel: SND_CHANNEL_BODY2, peerMask: 0xFFu);
    }
    if ( v7 != 0 )
    {
      sound_scrape = this->sound_scrape;
      if ( sound_scrape != nullptr )
        idEntity::StartSoundShader(
          this,
          channel: SND_CHANNEL_BODY2,
          shader: sound_scrape,
          soundShaderFlags: SSF_LOOPING|SSF_PLAY_ONCE,
          peerMask: 0xFFu);
    }
    else if ( v8 != 0 )
    {
      v35 = this->sound_scrape;
      if ( v35 != nullptr )
      {
        idEntity::StartSoundShader(
          this,
          channel: SND_CHANNEL_BODY2,
          shader: v35,
          soundShaderFlags: SSF_LOOPING|SSF_PLAY_ONCE,
          peerMask: 0xFFu);
        idEntity::SetSoundVolume(this, channel: SND_CHANNEL_BODY2, volume: -15.0);
      }
    }
  }
  else if ( idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) > this->nextBounceTime )
  {
    if ( v9 >= this->bounceMaxVelocity )
      *(double *)&v16 = 1.0;
    else
      *(double *)&v16 = (float)((float)((float)1.0
                                      / (float)__fsqrts((float)(this->bounceMaxVelocity - this->bounceMinVelocity)))
                              * (float)__fsqrts((float)((float)v9 - this->bounceMinVelocity)));
    if ( this->sound_bounce != nullptr )
    {
      v17 = LinearToDB(linear: v16);
      idEntity::StartSoundShader(
        this,
        channel: SND_CHANNEL_BODY,
        shader: this->sound_bounce,
        soundShaderFlags: (soundShaderFlags_t)0,
        peerMask: 0xFFu);
      idEntity::SetSoundVolume(this, channel: SND_CHANNEL_BODY, volume: v17);
    }
    this->nextBounceTime = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) + 250;
  }
  damage = this->damage;
  v37 = velocity->z;
  _FP6 = (float)((float)((float)(velocity->x * velocity->x)
                       + (float)((float)(velocity->z * velocity->z) + (float)(velocity->y * velocity->y)))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f4, f6, f7, f10 }
  v40 = __frsqrte(_FP4);
  v41 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v40
                                                                                      * (float)((float)((float)(velocity->x * velocity->x) + (float)((float)(velocity->z * velocity->z) + (float)(velocity->y * velocity->y)))
                                                                                              * (float)0.5))
                                                                              * (float)v40)
                                                                      - (float)1.5)
                                                      * (float)v40)
                                              * (float)((float)((float)(velocity->x * velocity->x)
                                                              + (float)((float)(velocity->z * velocity->z)
                                                                      + (float)(velocity->y * velocity->y)))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v40
                                                                              * (float)((float)((float)(velocity->x * velocity->x)
                                                                                              + (float)((float)(velocity->z * velocity->z) + (float)(velocity->y * velocity->y)))
                                                                                      * (float)0.5))
                                                                      * (float)v40)
                                                              - (float)1.5)
                                              * (float)v40))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v40
                                                      * (float)((float)((float)(velocity->x * velocity->x)
                                                                      + (float)((float)(velocity->z * velocity->z)
                                                                              + (float)(velocity->y * velocity->y)))
                                                              * (float)0.5))
                                              * (float)v40)
                                      - (float)1.5)
                      * (float)v40));
  v42 = (float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v40 * (float)((float)((float)(velocity->x * velocity->x) + (float)((float)(velocity->z * velocity->z) + (float)(velocity->y * velocity->y))) * (float)0.5)) * (float)v40) - (float)1.5)
                                                                                      * (float)v40)
                                                                              * (float)((float)((float)(velocity->x * velocity->x)
                                                                                              + (float)((float)(velocity->z * velocity->z) + (float)(velocity->y * velocity->y)))
                                                                                      * (float)0.5))
                                                                      * (float)((float)-(float)((float)((float)((float)v40 * (float)((float)((float)(velocity->x * velocity->x) + (float)((float)(velocity->z * velocity->z) + (float)(velocity->y * velocity->y))) * (float)0.5)) * (float)v40)
                                                                                              - (float)1.5)
                                                                              * (float)v40))
                                                              - (float)1.5)
                                              * (float)((float)-(float)((float)((float)((float)v40
                                                                                      * (float)((float)((float)(velocity->x * velocity->x) + (float)((float)(velocity->z * velocity->z) + (float)(velocity->y * velocity->y)))
                                                                                              * (float)0.5))
                                                                              * (float)v40)
                                                                      - (float)1.5)
                                                      * (float)v40))
                                      * (float)((float)((float)(velocity->x * velocity->x)
                                                      + (float)((float)(velocity->z * velocity->z)
                                                              + (float)(velocity->y * velocity->y)))
                                              * (float)0.5))
                              * (float)v41)
                      - (float)1.5);
  v43 = (float)((float)v42
              * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v40
                                                                                              * (float)((float)((float)(velocity->x * velocity->x) + (float)((float)(velocity->z * velocity->z) + (float)(velocity->y * velocity->y))) * (float)0.5))
                                                                                      * (float)v40)
                                                                              - (float)1.5)
                                                              * (float)v40)
                                                      * (float)((float)((float)(velocity->x * velocity->x)
                                                                      + (float)((float)(velocity->z * velocity->z)
                                                                              + (float)(velocity->y * velocity->y)))
                                                              * (float)0.5))
                                              * (float)((float)-(float)((float)((float)((float)v40
                                                                                      * (float)((float)((float)(velocity->x * velocity->x) + (float)((float)(velocity->z * velocity->z) + (float)(velocity->y * velocity->y)))
                                                                                              * (float)0.5))
                                                                              * (float)v40)
                                                                      - (float)1.5)
                                                      * (float)v40))
                                      - (float)1.5)
                      * (float)((float)-(float)((float)((float)((float)v40
                                                              * (float)((float)((float)(velocity->x * velocity->x)
                                                                              + (float)((float)(velocity->z * velocity->z)
                                                                                      + (float)(velocity->y * velocity->y)))
                                                                      * (float)0.5))
                                                      * (float)v40)
                                              - (float)1.5)
                              * (float)v40)));
  v44 = (float)((float)((float)v42
                      * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v40 * (float)((float)((float)(velocity->x * velocity->x) + (float)((float)(velocity->z * velocity->z) + (float)(velocity->y * velocity->y))) * (float)0.5))
                                                                                              * (float)v40)
                                                                                      - (float)1.5)
                                                                      * (float)v40)
                                                              * (float)((float)((float)(velocity->x * velocity->x)
                                                                              + (float)((float)(velocity->z * velocity->z)
                                                                                      + (float)(velocity->y * velocity->y)))
                                                                      * (float)0.5))
                                                      * (float)((float)-(float)((float)((float)((float)v40
                                                                                              * (float)((float)((float)(velocity->x * velocity->x) + (float)((float)(velocity->z * velocity->z) + (float)(velocity->y * velocity->y))) * (float)0.5))
                                                                                      * (float)v40)
                                                                              - (float)1.5)
                                                              * (float)v40))
                                              - (float)1.5)
                              * (float)((float)-(float)((float)((float)((float)v40
                                                                      * (float)((float)((float)(velocity->x * velocity->x)
                                                                                      + (float)((float)(velocity->z * velocity->z)
                                                                                              + (float)(velocity->y * velocity->y)))
                                                                              * (float)0.5))
                                                              * (float)v40)
                                                      - (float)1.5)
                                      * (float)v40)))
              * velocity->x);
  v61.y = velocity->y * (float)v43;
  v61.x = v44;
  v61.z = (float)v37 * (float)v43;
  if ( damage > 0
    && idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) > this->nextDamageTime )
  {
    v45 = gameLocal;
    v46 = gameLocal->entities.ptr[collision->c.entityNum];
    if ( v46 != nullptr && v9 > this->minDamageVelocity )
    {
      if ( v9 >= this->maxDamageVelocity )
        v47 = 1.0;
      else
        v47 = (float)((float)((float)1.0 / (float)__fsqrts((float)(this->maxDamageVelocity - this->minDamageVelocity)))
                    * (float)__fsqrts((float)((float)v9 - this->minDamageVelocity)));
      v48 = velocity->y;
      v49 = velocity->z;
      v61.x = velocity->x;
      v61.y = v48;
      v61.z = v49;
      idVec3::NormalizeFast(this: &v61);
      damageMoverCrush = v45->damageMoverCrush;
      if ( damageMoverCrush != nullptr )
      {
        v51 = idEntity::GetPhysics(this);
        v52 = (int)v51->GetClipModel(this: v51, a2: 0);
        v53 = this->damage;
        LODWORD(v54) = v53;
        HIDWORD(v54) = v46->__vftable;
        v55 = *(_DWORD *)(v52 + 16) + 21563;
        *(_QWORD *)&v60.x = v54;
        (*(void (__fastcall **)(idEntity *, idProp_Moveable *, _DWORD, const idDeclDamage *, int, idVec3 *, trace_t *, double))(HIDWORD(v54) + 312))(
          a1: v46,
          a2: this,
          a3: *((_DWORD *)&gameLocal->__vftable + v55),
          a4: damageMoverCrush,
          a5: v53,
          a6: &v61,
          a7: collision,
          a8: (float)((float)v54 * (float)v47));
      }
      this->nextDamageTime = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED)
                           + 1000;
    }
  }
  if ( this->selfDamage > 0
    && idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) > this->nextSelfDamageTime
    && v9 >= (float)(this->minDamageVelocity * (float)0.75) )
  {
    v56 = gameLocal->entities.ptr[collision->c.entityNum];
    if ( (unsigned __int8)idWorldspawn::IsTypeOf(c: v56) != 0
      || (unsigned __int8)idProp_Moveable::IsTypeOf(c: v56) != 0
      || (unsigned __int8)idActor::IsTypeOf(c: v56) != 0 )
    {
      HIDWORD(v57) = gameLocal->damageMoverCrush;
      if ( HIDWORD(v57) != 0 )
      {
        v58 = this->__vftable;
        LODWORD(v57) = this->selfDamage;
        *(_QWORD *)&v60.x = v57;
        ((void (__fastcall *)(idProp_Moveable *, idEntity *, idProp_Moveable *, double))v58->Damage)(
          a1: this,
          a2: v56,
          a3: this,
          a4: (float)v57);
      }
    }
    this->nextSelfDamageTime = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED)
                             + 500;
  }
  return COLLIDE_CONTINUE_SIMULATION;
}


// ========================================================================
// ?DropToFloor@idProp_Moveable@@QAAX_N@Z
// EA  : 0x82C9CD58
// RVA : 0x00C9CD58
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void __fastcall idProp_Moveable::DropToFloor(idProp_Moveable *this, bool set)
{
  *((_BYTE *)&this->physicsObj.fl + 4) = (set << 6) & 0x40 | (set << 7) | *((_BYTE *)&this->physicsObj.fl + 4) & 0x3F;
}


// ========================================================================
// ?Event_Pulse@idProp_Moveable@@IAA?AVeventVoid@@XZ
// EA  : 0x82C9CD80
// RVA : 0x00C9CD80
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

idProp_Moveable *__fastcall idProp_Moveable::Event_Pulse(idProp_Moveable *this, idEntity *result)
{
  idPhysics *Physics; // r3
  int v5; // r3
  float v6; // r7
  float v7; // r6
  idPhysics *v8; // r3
  int v9; // r3
  idVec3 *v10; // r10
  float *v11; // r11
  int i; // ctr
  __int64 v13; // r10
  unsigned int v14; // r6
  double v15; // fp31
  int GameMsPerFrame; // r28
  int v17; // r24
  const idDeclParticle *x_low; // r23
  idRenderModelEffects *MergeBranch; // r3
  double v20; // fp13
  unsigned int v21; // r3
  __int64 v22; // r9
  double v23; // fp0
  int v25; // [sp+8h] [-E8h]
  int v26; // [sp+Ch] [-E4h]
  int v27; // [sp+10h] [-E0h]
  int v28; // [sp+14h] [-DCh]
  int v29; // [sp+18h] [-D8h]
  int v30; // [sp+1Ch] [-D4h]
  int v31; // [sp+20h] [-D0h]
  int v32; // [sp+24h] [-CCh]
  int v33; // [sp+28h] [-C8h]
  int v34; // [sp+2Ch] [-C4h]
  int v35; // [sp+30h] [-C0h]
  int v36; // [sp+34h] [-BCh]
  int v37; // [sp+38h] [-B8h]
  int v38; // [sp+3Ch] [-B4h]
  int v39; // [sp+40h] [-B0h]
  int v40; // [sp+44h] [-ACh]
  int v41; // [sp+48h] [-A8h]
  int v42; // [sp+4Ch] [-A4h]
  int v43; // [sp+50h] [-A0h]
  unsigned int v44[2]; // [sp+60h] [-90h] BYREF
  __int64 v45; // [sp+68h] [-88h]
  idMat3 v46; // [sp+70h] [-80h] BYREF
  float v47; // [sp+94h] [-5Ch]

  if ( LODWORD(result[6].defaultPhysicsObj.current.worldAxis.mat[0].x) != 0
    && (unsigned __int8)Get_idCombatStage_useRelaxedChatterVO(ptr: (unsigned __int8 *)result) == 0 )
  {
    Physics = idEntity::GetPhysics(this: result);
    v5 = (int)Physics->GetOrigin(this: Physics, a2: 0);
    v6 = *(float *)(v5 + 4);
    v7 = *(float *)(v5 + 8);
    v46.mat[0].x = *(float *)v5;
    v46.mat[0].y = v6;
    v46.mat[0].z = v7;
    v8 = idEntity::GetPhysics(this: result);
    v9 = (int)v8->GetAbsBounds(this: v8, a2: -1);
    v10 = &v46.mat[1];
    v11 = (float *)(v9 - 4);
    for ( i = 6; i != 0; --i )
    {
      ++v11;
      v10 = (idVec3 *)((char *)v10 + 4);
      v10->x = *v11;
    }
    v46.mat[0].z = (float)(v47 - v46.mat[2].x) + v46.mat[0].z;
    *(_DWORD *)&result[8].defaultPhysicsObj.contactPhysicsIds.granularity = idGameTimeManager::GetGameMs(
                                                                              this: &clientGame->gameTimeManager,
                                                                              type: GAMETIME_SCALED);
    HIDWORD(v13) = -1;
    v44[0] = -1;
    v14 = 1664525 * clientGame->random.seed;
    clientGame->random.seed = v14 + 1013904223;
    LODWORD(v13) = ((v14 + 1013904223) >> 10) & 0x7FFF;
    v45 = v13;
    v15 = (float)((float)v13 * (float)0.000030518509);
    GameMsPerFrame = idGameTimeManager::GetGameMsPerFrame(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    v17 = *(_DWORD *)&result[8].defaultPhysicsObj.contactPhysicsIds.granularity;
    x_low = (const idDeclParticle *)LODWORD(result[6].defaultPhysicsObj.current.worldAxis.mat[0].x);
    MergeBranch = (idRenderModelEffects *)idAnimator_BlendEq::InternalGetMergeBranch(this: (idAnimator_BlendEq *)clientGame);
    idRenderModelEffects::AddParticles(
      this: MergeBranch,
      particle: x_low,
      systemStartTime: v17,
      gameMsPerFrame: GameMsPerFrame,
      diversity: v15,
      origin: (const idVec3 *)v44,
      axis: &v46,
      velocity: mat3_identity.mat,
      color: &vec3_origin.x,
      a10: v25,
      a11: v26,
      a12: v27,
      a13: v28,
      a14: v29,
      a15: v30,
      a16: v31,
      a17: v32,
      a18: v33,
      a19: v34,
      a20: v35,
      a21: v36,
      a22: v37,
      a23: v38,
      a24: v39,
      a25: v40,
      a26: v41,
      a27: v42,
      a28: v43,
      a29: v44);
    v20 = 0.5;
    v21 = 1664525 * clientGame->random.seed + 1013904223;
    clientGame->random.seed = v21;
    LODWORD(v22) = (v21 >> 10) & 0x7FFF;
    v45 = v22;
    v23 = (float)((float)v22 * (float)0.000030518509);
    if ( v23 < 0.5 || (v20 = 1.0, v23 > 1.0) )
      v23 = v20;
    idEventReceiver::PostEventSec(this: result, ev: &EV_Pulse, time: v23);
    idEntity::BecomeActive(this: result, flags: 1);
  }
  return this;
}


// ========================================================================
// ?OnActivate@idProp_Moveable@@MAAXPAVidEntity@@@Z
// EA  : 0x82C9CF90
// RVA : 0x00C9CF90
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void __fastcall idProp_Moveable::OnActivate(idProp_Moveable *this, idEntity *activator)
{
  idPhysics *Physics; // r3
  idPhysics *v4; // r30
  idPhysics *v5; // r3
  float *v6; // r3
  double v7; // fp31
  double v8; // fp30
  double v9; // fp29
  float *v10; // r3
  double v11; // fp7
  double v12; // fp5
  double v15; // fp6
  double v16; // fp10
  double v17; // fp8
  double v18; // fp6
  double v19; // fp31
  double v20; // fp30
  double v21; // fp29
  idPhysics *v22; // r3
  double impulseVelocity; // fp5
  double v24; // fp3
  idPhysics *v25; // r3
  float v26[4]; // [sp+50h] [-40h] BYREF

  Physics = idEntity::GetPhysics(this);
  this->ActivatePhysics(this, a2: Physics->physicsId);
  if ( (*((_BYTE *)this + 5297) & 8) != 0 )
  {
    v4 = idEntity::GetPhysics(this);
    v5 = idEntity::GetPhysics(this);
    v6 = (float *)v5->GetOrigin(this: v5, a2: 0);
    v7 = (float)(*v6 + this->impulseTarget.x);
    v8 = (float)(v6[1] + this->impulseTarget.y);
    v9 = (float)(v6[2] + this->impulseTarget.z);
    v10 = (float *)v4->GetOrigin(this: v4, a2: 0);
    v11 = (float)((float)v8 - v10[1]);
    v12 = (float)((float)v9 - v10[2]);
    _FP10 = (float)((float)((float)((float)((float)v7 - *v10) * (float)((float)v7 - *v10))
                          + (float)((float)((float)v12 * (float)v12) + (float)((float)v11 * (float)v11)))
                  - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm { fsel      f8, f10, f11, f13 }
    v15 = __frsqrte(_FP8);
    v16 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v15
                                                                                        * (float)((float)((float)((float)((float)v7 - *v10) * (float)((float)v7 - *v10)) + (float)((float)((float)v12 * (float)v12) + (float)((float)v11 * (float)v11)))
                                                                                                * (float)0.5))
                                                                                * (float)v15)
                                                                        - (float)1.5)
                                                        * (float)v15)
                                                * (float)((float)((float)((float)((float)v7 - *v10)
                                                                        * (float)((float)v7 - *v10))
                                                                + (float)((float)((float)v12 * (float)v12)
                                                                        + (float)((float)v11 * (float)v11)))
                                                        * (float)0.5))
                                        * (float)((float)-(float)((float)((float)((float)v15
                                                                                * (float)((float)((float)((float)((float)v7 - *v10) * (float)((float)v7 - *v10))
                                                                                                + (float)((float)((float)v12 * (float)v12) + (float)((float)v11 * (float)v11)))
                                                                                        * (float)0.5))
                                                                        * (float)v15)
                                                                - (float)1.5)
                                                * (float)v15))
                                - (float)1.5)
                * (float)((float)-(float)((float)((float)((float)v15
                                                        * (float)((float)((float)((float)((float)v7 - *v10)
                                                                                * (float)((float)v7 - *v10))
                                                                        + (float)((float)((float)v12 * (float)v12)
                                                                                + (float)((float)v11 * (float)v11)))
                                                                * (float)0.5))
                                                * (float)v15)
                                        - (float)1.5)
                        * (float)v15));
    v17 = (float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v15 * (float)((float)((float)((float)((float)v7 - *v10) * (float)((float)v7 - *v10)) + (float)((float)((float)v12 * (float)v12) + (float)((float)v11 * (float)v11))) * (float)0.5)) * (float)v15) - (float)1.5)
                                                                                        * (float)v15)
                                                                                * (float)((float)((float)((float)((float)v7 - *v10) * (float)((float)v7 - *v10))
                                                                                                + (float)((float)((float)v12 * (float)v12) + (float)((float)v11 * (float)v11)))
                                                                                        * (float)0.5))
                                                                        * (float)((float)-(float)((float)((float)((float)v15 * (float)((float)((float)((float)((float)v7 - *v10) * (float)((float)v7 - *v10)) + (float)((float)((float)v12 * (float)v12) + (float)((float)v11 * (float)v11))) * (float)0.5)) * (float)v15)
                                                                                                - (float)1.5)
                                                                                * (float)v15))
                                                                - (float)1.5)
                                                * (float)((float)-(float)((float)((float)((float)v15
                                                                                        * (float)((float)((float)((float)((float)v7 - *v10) * (float)((float)v7 - *v10)) + (float)((float)((float)v12 * (float)v12) + (float)((float)v11 * (float)v11)))
                                                                                                * (float)0.5))
                                                                                * (float)v15)
                                                                        - (float)1.5)
                                                        * (float)v15))
                                        * (float)((float)((float)((float)((float)v7 - *v10) * (float)((float)v7 - *v10))
                                                        + (float)((float)((float)v12 * (float)v12)
                                                                + (float)((float)v11 * (float)v11)))
                                                * (float)0.5))
                                * (float)v16)
                        - (float)1.5);
    v18 = (float)((float)v17
                * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v15
                                                                                                * (float)((float)((float)((float)((float)v7 - *v10) * (float)((float)v7 - *v10)) + (float)((float)((float)v12 * (float)v12) + (float)((float)v11 * (float)v11))) * (float)0.5))
                                                                                        * (float)v15)
                                                                                - (float)1.5)
                                                                * (float)v15)
                                                        * (float)((float)((float)((float)((float)v7 - *v10)
                                                                                * (float)((float)v7 - *v10))
                                                                        + (float)((float)((float)v12 * (float)v12)
                                                                                + (float)((float)v11 * (float)v11)))
                                                                * (float)0.5))
                                                * (float)((float)-(float)((float)((float)((float)v15
                                                                                        * (float)((float)((float)((float)((float)v7 - *v10) * (float)((float)v7 - *v10)) + (float)((float)((float)v12 * (float)v12) + (float)((float)v11 * (float)v11)))
                                                                                                * (float)0.5))
                                                                                * (float)v15)
                                                                        - (float)1.5)
                                                        * (float)v15))
                                        - (float)1.5)
                        * (float)((float)-(float)((float)((float)((float)v15
                                                                * (float)((float)((float)((float)((float)v7 - *v10)
                                                                                        * (float)((float)v7 - *v10))
                                                                                + (float)((float)((float)v12 * (float)v12)
                                                                                        + (float)((float)v11 * (float)v11)))
                                                                        * (float)0.5))
                                                        * (float)v15)
                                                - (float)1.5)
                                * (float)v15)));
    v19 = (float)((float)((float)v7 - *v10) * (float)v18);
    v20 = (float)((float)((float)v8 - v10[1]) * (float)v18);
    v21 = (float)((float)((float)v9 - v10[2]) * (float)v18);
    v22 = idEntity::GetPhysics(this);
    impulseVelocity = this->impulseVelocity;
    v24 = (float)((float)v20 * this->impulseVelocity);
    v26[0] = this->impulseVelocity * (float)v19;
    v26[1] = v24;
    v26[2] = (float)v21 * (float)impulseVelocity;
    v22->SetLinearVelocity(this: v22, a2: (const idVec3 *)v26, a3: 0);
    v25 = idEntity::GetPhysics(this);
    v25->SetAngularVelocity(this: v25, a2: &this->impulseAVelocity, a3: 0);
  }
}


// ========================================================================
// ?GetIconName@idProp_Moveable@@UBAPBDXZ
// EA  : 0x82C9D150
// RVA : 0x00C9D150
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

char *__fastcall idProp_Moveable::GetIconName(idProp_Moveable *this)
{
  const idDeclInventory *inventoryDecl; // r11

  inventoryDecl = this->inventoryDecl;
  if ( inventoryDecl != nullptr )
    return (char *)inventoryDecl->icon->name.str;
  else
    return &byte_8200D768;
}


// ========================================================================
// ?CheckRequirementStatus@idProp_Moveable@@QAA_NPAVidPlayer@@@Z
// EA  : 0x82C9D178
// RVA : 0x00C9D178
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

int __fastcall idProp_Moveable::CheckRequirementStatus(idProp_Moveable *this, idPlayer *player)
{
  int v5; // r28
  idJob *InventoryItemByDeclName; // r3
  const idDeclInventory *requiredInvDecl; // r29
  idJobManager *v8; // r3
  const idDeclInventory *inventoryDecl; // r29
  idJobManager *v10; // r3
  idJob *JobByDecl; // r3
  unsigned int v12; // r3

  if ( player == nullptr )
    return 0;
  v5 = 1;
  if ( this->requiredJobDecl.len != 0 )
  {
    InventoryItemByDeclName = idInventoryCollection::FindInventoryItemByDeclName(
                                this: &player->jobManager,
                                jobName: this->requiredJobDecl.data);
    if ( InventoryItemByDeclName == nullptr || InventoryItemByDeclName->status < this->requiredJobStatus )
      v5 = 0;
  }
  requiredInvDecl = this->requiredInvDecl;
  if ( requiredInvDecl != nullptr )
  {
    v8 = (idJobManager *)player->GetInventory_2(this: player);
    v5 = idJobManager::FindJobByDecl(this: v8, jobDecl: (const idDeclJob *)requiredInvDecl) == nullptr ? 0 : v5;
  }
  inventoryDecl = this->inventoryDecl;
  if ( inventoryDecl != nullptr )
  {
    v10 = (idJobManager *)player->GetInventory_2(this: player);
    JobByDecl = idJobManager::FindJobByDecl(this: v10, jobDecl: (const idDeclJob *)inventoryDecl);
    if ( JobByDecl != nullptr )
    {
      v12 = ((int (__fastcall *)(idJob *))JobByDecl->__vftable[2].dtr_idClass)(a1: JobByDecl);
      return ((__PAIR64__((unsigned int)this->inventoryDecl->maxCount >> 31, v12)
             - __PAIR64__(v12 >> 31, this->inventoryDecl->maxCount)) >> 32)
           & v5;
    }
  }
  return v5;
}


// ========================================================================
// ?AttachPlayer@idProp_Moveable@@QAA_NPAVidPlayer@@@Z
// EA  : 0x82C9D278
// RVA : 0x00C9D278
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

int __fastcall idProp_Moveable::AttachPlayer(idProp_Moveable *this, idPlayer *player)
{
  idPhysics *Physics; // r3
  idVec3 v6; // [sp+50h] [-60h] BYREF
  idMat3 v7[2]; // [sp+60h] [-50h] BYREF

  if ( idEntity::GetBindMaster(this: player) != nullptr )
  {
    if ( idEntity::GetBindMaster(this: player) == this )
    {
      idEntity::Unbind(this: player);
      return 1;
    }
  }
  else if ( (unsigned __int8)idAnimatedEntity::GetTagPosition(
                               this,
                               propName: idPropInfo::INFO_PROP_NAME,
                               tagName: "attach_origin",
                               origin: &v6,
                               axis: v7) != 0 )
  {
    Physics = idEntity::GetPhysics(this: player);
    Physics->SetOrigin(this: Physics, a2: &v6, a3: -1);
    idEntity::BindToJoint(this: player, master: this, animName: nullptr, jointName: "attach_origin", orientated: true);
    return 1;
  }
  return 0;
}


// ========================================================================
// ?Pickup@idProp_Moveable@@UAAXPAVidEntity@@_N@Z
// EA  : 0x82C9D340
// RVA : 0x00C9D340
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void __fastcall idProp_Moveable::Pickup(idProp_Moveable *this, idEntity *entity, const bool addItem)
{
  __int64 v4; // r5
  unsigned int v5; // r8
  int v6; // r30
  int v7; // r3
  idProp_Moveable_vtbl *v8; // r8
  idProp_Moveable *v9; // r3
  int removeDelay; // r5

  idAnimatedEntity::StopFX(this, condition: 112);
  idAlarm::StartFX(this, condition: FX_PROP_PICKUP);
  if ( this->minRespawnDelay <= 0.0 )
  {
    v9 = this;
    if ( this->removeDelay <= 0 )
    {
      removeDelay = 0;
    }
    else
    {
      this->Hide_2(this);
      removeDelay = this->removeDelay;
      v9 = this;
    }
    idEventReceiver::PostEventMS(this: v9, ev: &EV_Remove, time: removeDelay);
  }
  else
  {
    HIDWORD(v4) = 1;
    v5 = 1664525 * clientGame->random.seed + 1013904223;
    clientGame->random.seed = v5;
    LODWORD(v4) = (v5 >> 10) & 0x7FFF;
    v6 = (int)(float)((float)((float)((float)((float)((float)v4 * (float)0.000061037019) - (float)1.0)
                                    * (float)(this->maxRespawnDelay - this->minRespawnDelay))
                            + this->minRespawnDelay)
                    * (float)1000.0);
    v7 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
    v8 = this->__vftable;
    this->respawnTime = v7 + v6;
    v8->Hide_2(this);
    idEntity::BecomeActive(this, flags: 1);
  }
}


// ========================================================================
// ?Respawn@idProp_Moveable@@MAAXXZ
// EA  : 0x82C9D4A0
// RVA : 0x00C9D4A0
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void __fastcall idProp_Moveable::Respawn(idProp_Moveable *this)
{
  idPhysics *Physics; // r3
  idPhysics *v3; // r3
  idPhysics *v4; // r3

  this->respawnTime = 0;
  Physics = idEntity::GetPhysics(this);
  Physics->SetOrigin(this: Physics, a2: &this->spawnPosition, a3: -1);
  v3 = idEntity::GetPhysics(this);
  v3->SetAxis(this: v3, a2: &this->spawnOrientation, a3: -1);
  v4 = idEntity::GetPhysics(this);
  v4->SetLinearVelocity(this: v4, a2: &vec3_origin, a3: 0);
  this->Show(this);
  idAnimatedEntity::StopFX(this, condition: 111);
  idAlarm::StartFX(this, condition: FX_PROP_SPAWN);
}


// ========================================================================
// ?AllocPresentable@idProp_Moveable@@UAAPAVidPresentable@@PAVidRenderModel@@@Z
// EA  : 0x82C9D568
// RVA : 0x00C9D568
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

idPresentableProp *__fastcall idProp_Moveable::AllocPresentable(idProp_Moveable *this, idRenderModel *renderModel_)
{
  bool v4; // r27
  _DWORD *v5; // r3
  int v6; // r11
  idPresentableProp *v7; // r28
  int entityNumber; // r26
  bool v9; // r25
  const idDeclInventory *inventoryDecl; // r24
  const idDeclFX *v11; // r23
  idAnimStack *v12; // r3
  bool v14; // [sp+Bh] [-B5h]
  int v15; // [sp+Ch] [-B4h]
  int v16; // [sp+10h] [-B0h]
  int v17; // [sp+14h] [-ACh]
  int v18; // [sp+18h] [-A8h]
  int v19; // [sp+1Ch] [-A4h]
  int v20; // [sp+20h] [-A0h]
  int v21; // [sp+24h] [-9Ch]
  int v22; // [sp+28h] [-98h]
  int v23; // [sp+2Ch] [-94h]
  int v24; // [sp+30h] [-90h]
  int v25; // [sp+34h] [-8Ch]
  int v26; // [sp+38h] [-88h]
  int v27; // [sp+3Ch] [-84h]
  int v28; // [sp+40h] [-80h]
  int v29; // [sp+44h] [-7Ch]
  int v30; // [sp+48h] [-78h]
  int v31; // [sp+4Ch] [-74h]
  int v32; // [sp+50h] [-70h]

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
  v7 = (idPresentableProp *)idMem::AllocWithLocation(
                              this: &mem,
                              location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                              size: 0x510u,
                              tag: TAG_PRESENTABLE,
                              zeroBuffer: false,
                              align: ALIGN_16,
                              heap: HEAP_DEFAULTHEAP);
  if ( v7 == nullptr )
    return nullptr;
  entityNumber = this->entityNumber;
  v9 = this->IsEverUsable(this, a2: nullptr);
  inventoryDecl = this->inventoryDecl;
  v11 = this->GetFXDecl(this);
  v12 = this->GetAnimStack_2(this);
  return idPresentableProp::idPresentableProp(
           this: v7,
           e: this,
           renderModel_,
           animStack_: v12,
           entityNumber_: entityNumber,
           fxDecl_: v11,
           useSphereModel_: v4,
           inventoryDecl_: inventoryDecl,
           isUsable_: v14,
           a10: v15,
           a11: v16,
           a12: v17,
           a13: v18,
           a14: v19,
           a15: v20,
           a16: v21,
           a17: v22,
           a18: v23,
           a19: v24,
           a20: v25,
           a21: v26,
           a22: v27,
           a23: v28,
           a24: v29,
           a25: v30,
           a26: v31,
           a27: v32,
           a28: v9);
}


// ========================================================================
// __unwind$497327
// EA  : 0x82C9D694
// RVA : 0x00C9D694
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void _unwind_497327()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 192 + 96), tag: TAG_PRESENTABLE);
}


// ========================================================================
// ?Spawn@idProp_Loot@@QAAXXZ
// EA  : 0x82C9D6C0
// RVA : 0x00C9D6C0
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void __fastcall idProp_Loot::Spawn(idProp_Loot *this)
{
  int num; // r10
  int maxItemsToGive; // r11
  int i; // r23
  signed int v5; // r11
  idClientGame *v6; // r10
  idClientGame *v7; // r9
  int v8; // r3
  unsigned int v9; // r6
  const idDeclInventory **list; // r10
  int v11; // r29
  const idDeclJob *v12; // r30
  idJobManager *v13; // r3
  idPresentable *presentable; // r30
  const idDeclInventory **v15; // r28
  const idDeclInventory *v16; // r29
  idInventoryCollection *v17; // r3

  num = this->randomLootPool.num;
  if ( num != 0 )
  {
    maxItemsToGive = this->maxItemsToGive;
    if ( maxItemsToGive > 0 || (maxItemsToGive = idRandom2::RandomInt(this: &clientGame->random, max: num - 1) + 1) > 0 )
    {
      for ( i = maxItemsToGive; i != 0; --i )
      {
        v5 = this->randomLootPool.num;
        v6 = clientGame;
        if ( v5 != 0 )
        {
          v7 = clientGame;
          __twllei(v5, 0);
          v7->random.seed = 1664525 * v7->random.seed + 1013904223;
          v8 = (v6->random.seed >> 10) & 0x7FFF;
          v9 = v5 & ~(__ROL4__(v8, 1) - 1);
          v5 = v8 % v5;
          __twlgei(v9, 0xFFFFFFFF);
        }
        list = this->randomLootPool.list;
        v11 = v5;
        if ( list[v5] != nullptr )
        {
          v12 = (const idDeclJob *)list[v5];
          v13 = (idJobManager *)this->GetInventory_2(this);
          if ( idJobManager::FindJobByDecl(this: v13, jobDecl: v12) == nullptr )
          {
            presentable = this->presentable;
            v15 = this->randomLootPool.list;
            if ( presentable == nullptr )
            {
              idEntity::InitPresentableInternal(this);
              presentable = this->presentable;
            }
            v16 = v15[v11];
            v17 = this->GetInventory_2(this);
            idInventoryCollection::GiveItem(
              this: v17,
              owner: presentable,
              decl: v16,
              count: 1,
              forceCount: false,
              canIntro: false)->lootable = true;
          }
        }
      }
    }
  }
}


// ========================================================================
// ?GetUsableState@idProp_Loot@@UBA?AW4usableState_t@@PBVidEntity@@ABVidFocusTrace@@@Z
// EA  : 0x82C9D808
// RVA : 0x00C9D808
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

usableState_t __fastcall idProp_Loot::GetUsableState(idProp_Loot *this, idPlayer *activator, const idFocusTrace *ft)
{
  char v4; // r11
  usableState_t result; // r3

  if ( idPlayer::CastTo(c: activator) == nullptr )
    return USABLE_NOT_USABLE;
  if ( !this->isUsable || (v4 = 1, (*(_BYTE *)&this->flags & 8) == 0) )
    v4 = 0;
  result = USABLE_LOOT;
  if ( v4 == 0 )
    return USABLE_NOT_USABLE;
  return result;
}


// ========================================================================
// ?GetOnlineUsableState@idProp_Loot@@UBA?AW4usableState_t@@XZ
// EA  : 0x82C9D878
// RVA : 0x00C9D878
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

int __fastcall idProp_Loot::GetOnlineUsableState(idProp_Loot *this)
{
  char v1; // r11

  if ( !this->isUsable || (v1 = 1, (*(_BYTE *)&this->flags & 8) == 0) )
    v1 = 0;
  return v1 == 0 ? 0 : 2;
}


// ========================================================================
// ?GetUsableState@idProp_AmmoRefill@@UBA?AW4usableState_t@@PBVidEntity@@ABVidFocusTrace@@@Z
// EA  : 0x82C9D8B8
// RVA : 0x00C9D8B8
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

idPlayer *__fastcall idProp_AmmoRefill::GetUsableState(
        idProp_AmmoRefill *this,
        idPlayer *activator,
        const idFocusTrace *ft)
{
  idPlayer *result; // r3
  usableState_t v5; // r27
  char v6; // r24
  int v7; // r28
  int i; // r31
  const idDeclInventory *itemDecl; // r29
  idJobManager *v10; // r3
  idJob *v11; // r3
  idProp_AmmoRefill::caseItem_t *v12; // r29
  int v13; // r26
  bfx::Planner3D *v14; // r3
  idInventoryCollection *v15; // r3
  idWeapon *InventoryItem; // r3
  idWeapon *v17; // r3
  idWeapon *v18; // r30
  const idDeclInventory *decl; // r11
  int v20; // r28
  int v21; // r31
  const idDeclJob *v22; // r29
  idJobManager *v23; // r3
  idJob *JobByDecl; // r3
  const char *str; // r29
  bfx::Planner3D *v26; // r3

  result = idPlayer::CastTo(c: activator);
  v5 = (usableState_t)result;
  v6 = 0;
  if ( result != nullptr )
  {
    if ( this->caseContents.num <= 0 )
    {
      v13 = 0;
      v14 = (bfx::Planner3D *)result->GetInventory(this: result);
      if ( (int)idScriptObject::GetTypeDef(this: v14) > 0 )
      {
        do
        {
          v15 = (idInventoryCollection *)(*(int (__fastcall **)(usableState_t))(*(_DWORD *)v5 + 464))(a1: v5);
          InventoryItem = (idWeapon *)idInventoryCollection::GetInventoryItem(this: v15, index: v13);
          v17 = idWeapon::CastTo(c: InventoryItem);
          v18 = v17;
          if ( v17 != nullptr )
          {
            decl = v17->decl;
            v20 = 0;
            if ( (int)decl[1].nextOnHashChain > 0 )
            {
              v21 = 0;
              while ( 1 )
              {
                if ( idStr::Cmp(s1: decl->internalName.data, s2: "fists") != 0 )
                {
                  v22 = *(const idDeclJob **)&v18->decl[1].name.str[v21];
                  v23 = (idJobManager *)(*(int (__fastcall **)(usableState_t))(*(_DWORD *)v5 + 464))(a1: v5);
                  JobByDecl = idJobManager::FindJobByDecl(this: v23, jobDecl: v22);
                  if ( JobByDecl == nullptr )
                    break;
                  str = v18->decl[1].name.str;
                  if ( ((int (__fastcall *)(idJob *))JobByDecl->__vftable[2].dtr_idClass)(a1: JobByDecl) < *(_DWORD *)(*(_DWORD *)&str[v21] + 332) )
                    break;
                }
                decl = v18->decl;
                ++v20;
                v21 += 28;
                if ( v20 >= (int)decl[1].nextOnHashChain )
                  goto LABEL_19;
              }
              v6 = 1;
            }
          }
LABEL_19:
          ++v13;
          v26 = (bfx::Planner3D *)(*(int (__fastcall **)(usableState_t))(*(_DWORD *)v5 + 464))(a1: v5);
        }
        while ( v13 < (int)idScriptObject::GetTypeDef(this: v26) );
      }
    }
    else
    {
      v7 = 0;
      for ( i = 0; ; ++i )
      {
        itemDecl = this->caseContents.list[i].itemDecl;
        v10 = (idJobManager *)(*(int (__fastcall **)(usableState_t))(*(_DWORD *)v5 + 464))(a1: v5);
        v11 = idJobManager::FindJobByDecl(this: v10, jobDecl: (const idDeclJob *)itemDecl);
        if ( v11 == nullptr )
          break;
        v12 = &this->caseContents.list[i];
        if ( ((int (__fastcall *)(idJob *))v11->__vftable[2].dtr_idClass)(a1: v11) < v12->count )
          break;
        if ( ++v7 >= this->caseContents.num )
          return v6 == 0 ? nullptr : (idPlayer *)0xD;
      }
      v6 = 1;
    }
    return v6 == 0 ? nullptr : (idPlayer *)0xD;
  }
  return result;
}


// ========================================================================
// ?Use@idProp_AmmoRefill@@UAA_NPAVidEntity@@W4usableState_t@@@Z
// EA  : 0x82C9DAA8
// RVA : 0x00C9DAA8
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

int __fastcall idProp_AmmoRefill::Use(idProp_AmmoRefill *this, idPlayer *user, const usableState_t usable)
{
  int v5; // r26
  idPlayer *v6; // r3
  idPlayer *v7; // r31
  int v8; // r25
  int v9; // r28
  const idDeclInventory *itemDecl; // r30
  idJobManager *v11; // r3
  idJob *JobByDecl; // r3
  idProp_AmmoRefill::caseItem_t *list; // r11
  idInventoryItem *v14; // r30
  idProp_AmmoRefill::caseItem_t *v15; // r27
  idPresentable *presentable; // r29
  int count; // r27
  idInventoryCollection *v18; // r3
  idProp_AmmoRefill::caseItem_t *v19; // r30
  idPresentable *v20; // r29
  int v21; // r27
  const idDeclInventory *v22; // r30
  idInventoryCollection *v23; // r3
  int v24; // r21
  bfx::Planner3D *v25; // r3
  idInventoryCollection *v26; // r3
  idWeapon *InventoryItem; // r3
  idWeapon *v28; // r3
  idWeapon *v29; // r25
  const idDeclInventory *decl; // r11
  int v31; // r23
  int v32; // r27
  const idDeclJob *v33; // r30
  idJobManager *v34; // r3
  idJob *v35; // r3
  idInventoryItem *v36; // r30
  int v37; // r28
  idPresentable *v38; // r29
  idInventoryCollection *v39; // r3
  const char *v40; // r29
  idPresentable *v41; // r30
  const idDeclInventory *v42; // r29
  const char *str; // r29
  idInventoryCollection *v44; // r3
  bfx::Planner3D *v45; // r3

  v5 = 0;
  v6 = idPlayer::CastTo(c: user);
  v7 = v6;
  if ( v6 != nullptr )
  {
    if ( this->caseContents.num > 0 )
    {
      v8 = 0;
      v9 = 0;
      while ( 1 )
      {
        itemDecl = this->caseContents.list[v9].itemDecl;
        v11 = (idJobManager *)v7->GetInventory_2(this: v7);
        JobByDecl = idJobManager::FindJobByDecl(this: v11, jobDecl: (const idDeclJob *)itemDecl);
        list = this->caseContents.list;
        v14 = (idInventoryItem *)JobByDecl;
        if ( JobByDecl == nullptr )
          break;
        if ( ((int (__fastcall *)(idJob *))JobByDecl->__vftable[2].dtr_idClass)(a1: JobByDecl) < list[v9].count )
        {
          v15 = &this->caseContents.list[v9];
          if ( user->presentable == nullptr )
            idEntity::InitPresentableInternal(this: user);
          presentable = user->presentable;
          count = v15->count;
          v18 = v7->GetInventory_2(this: v7);
          idInventoryCollection::SetItemCount(this: v18, owner: presentable, item: v14, count, forceCount: true);
LABEL_12:
          v5 = 1;
        }
        ++v8;
        ++v9;
        if ( v8 >= this->caseContents.num )
          goto LABEL_38;
      }
      v19 = &list[v9];
      if ( user->presentable == nullptr )
        idEntity::InitPresentableInternal(this: user);
      v20 = user->presentable;
      v21 = v19->count;
      v22 = v19->itemDecl;
      v23 = v7->GetInventory_2(this: v7);
      idInventoryCollection::GiveItem(this: v23, owner: v20, decl: v22, count: v21, forceCount: true, canIntro: false);
      goto LABEL_12;
    }
    v24 = 0;
    v25 = (bfx::Planner3D *)v6->GetInventory_2(this: v6);
    if ( (int)idScriptObject::GetTypeDef(this: v25) > 0 )
    {
      while ( 1 )
      {
        v26 = v7->GetInventory_2(this: v7);
        InventoryItem = (idWeapon *)idInventoryCollection::GetInventoryItem(this: v26, index: v24);
        v28 = idWeapon::CastTo(c: InventoryItem);
        v29 = v28;
        if ( v28 != nullptr )
        {
          decl = v28->decl;
          v31 = 0;
          if ( (int)decl[1].nextOnHashChain > 0 )
            break;
        }
LABEL_37:
        ++v24;
        v45 = (bfx::Planner3D *)v7->GetInventory_2(this: v7);
        if ( v24 >= (int)idScriptObject::GetTypeDef(this: v45) )
          goto LABEL_38;
      }
      v32 = 0;
      while ( 1 )
      {
        if ( idStr::Cmp(s1: decl->internalName.data, s2: "fists") != 0 )
        {
          v33 = *(const idDeclJob **)&v29->decl[1].name.str[v32];
          v34 = (idJobManager *)v7->GetInventory_2(this: v7);
          v35 = idJobManager::FindJobByDecl(this: v34, jobDecl: v33);
          v36 = (idInventoryItem *)v35;
          v37 = *(_DWORD *)(*(_DWORD *)&v29->decl[1].name.str[v32] + 332);
          if ( v35 != nullptr )
          {
            if ( ((int (__fastcall *)(idJob *))v35->__vftable[2].dtr_idClass)(a1: v35) < v37 )
            {
              v38 = user->presentable;
              if ( v38 == nullptr )
              {
                idEntity::InitPresentableInternal(this: user);
                v38 = user->presentable;
              }
              v39 = v7->GetInventory_2(this: v7);
              idInventoryCollection::SetItemCount(this: v39, owner: v38, item: v36, count: v37, forceCount: true);
              goto LABEL_35;
            }
          }
          else
          {
            if ( common->IsMultiplayer(this: common) )
            {
              v40 = &v29->decl[1].name.str[v32];
              if ( v40[26] != 0 )
              {
                v41 = user->presentable;
                if ( v41 == nullptr )
                {
                  idEntity::InitPresentableInternal(this: user);
                  v41 = user->presentable;
                }
                v42 = *(const idDeclInventory **)v40;
                goto LABEL_34;
              }
            }
            if ( !common->IsMultiplayer(this: common) )
            {
              v41 = user->presentable;
              str = v29->decl[1].name.str;
              if ( v41 == nullptr )
              {
                idEntity::InitPresentableInternal(this: user);
                v41 = user->presentable;
              }
              v42 = *(const idDeclInventory **)&str[v32];
LABEL_34:
              v44 = v7->GetInventory_2(this: v7);
              idInventoryCollection::GiveItem(
                this: v44,
                owner: v41,
                decl: v42,
                count: v37,
                forceCount: true,
                canIntro: false);
LABEL_35:
              v5 = 1;
            }
          }
        }
        decl = v29->decl;
        ++v31;
        v32 += 28;
        if ( v31 >= (int)decl[1].nextOnHashChain )
          goto LABEL_37;
      }
    }
  }
LABEL_38:
  if ( (_BYTE)v5 != 0 )
    idEntity::StartSoundShader(
      this: user,
      channel: SND_CHANNEL_ANY,
      shader: this->useSound,
      soundShaderFlags: (soundShaderFlags_t)0,
      peerMask: 0xFFu);
  return v5;
}


// ========================================================================
// ?SetUpElectricShock@idProp_ElectricArmor@@QAAXXZ
// EA  : 0x82C9DE70
// RVA : 0x00C9DE70
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void __fastcall idProp_ElectricArmor::SetUpElectricShock(idProp_ElectricArmor *this)
{
  idElectricBolt *electricShock; // r29
  idElectricBolt *v3; // r3
  idElectricBolt *v4; // r3
  const idDeclElectricBolt *electricBoltSystem; // r28
  idElectricBolt *v6; // r29
  idRenderModelBeam *NumContacts; // r3

  electricShock = this->electricShock;
  if ( electricShock != nullptr )
  {
    idElectricBolt::~idElectricBolt(this: this->electricShock);
    idMem::Free(this: &mem, ptr: electricShock, align: ALIGN_16);
    this->electricShock = nullptr;
  }
  v3 = (idElectricBolt *)idMem::AllocWithLocation(
                           this: &mem,
                           location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                           size: 0x320u,
                           tag: TAG_PARTICLE,
                           zeroBuffer: false,
                           align: ALIGN_16,
                           heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
    v4 = idElectricBolt::idElectricBolt(this: v3);
  else
    v4 = nullptr;
  this->electricShock = v4;
  electricBoltSystem = this->electricBoltSystem;
  v6 = v4;
  NumContacts = (idRenderModelBeam *)idPhysics_DynamicBase::GetNumContacts(this: (idAnimator_ChannelWeight *)clientGame);
  idElectricBolt::Init(this: v6, _beamModel: NumContacts, _eboltDecl: electricBoltSystem);
  this->startElectricTime = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
}


// ========================================================================
// __unwind$497649
// EA  : 0x82C9DF48
// RVA : 0x00C9DF48
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void _unwind_497649()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_PARTICLE);
}


// ========================================================================
// ?ModifyCrosshairInfo@idProp_BreakableLoot@@UBA_NPBVidEntity@@ABVidFocusTrace@@W4usableState_t@@AAVidCrosshairInfo@@@Z
// EA  : 0x82C9DF78
// RVA : 0x00C9DF78
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

int __fastcall idProp_BreakableLoot::ModifyCrosshairInfo(
        idProp_BreakableLoot *this,
        idPlayer *activator,
        const idFocusTrace *ft,
        usableState_t usable,
        idCrosshairInfo *info)
{
  idPlayer *v9; // r3
  idPlayer *v10; // r30
  int v11; // r29
  idJob *InventoryItemByDeclName; // r3
  const idDeclInventory *requiredInvDecl; // r31
  idJobManager *v14; // r3

  if ( (unsigned __int8)idProp_Usable::ModifyCrosshairInfo(this, activator, ft, usable, info) == 0 )
    return 0;
  v9 = idPlayer::CastTo(c: activator);
  v10 = v9;
  if ( v9 == nullptr )
    return 1;
  v11 = 1;
  if ( this->inventoryDef.requiredJobDecl.len != 0 )
  {
    InventoryItemByDeclName = idInventoryCollection::FindInventoryItemByDeclName(
                                this: &v9->jobManager,
                                jobName: this->inventoryDef.requiredJobDecl.data);
    if ( InventoryItemByDeclName == nullptr || InventoryItemByDeclName->status < this->inventoryDef.requiredJobStatus )
      v11 = 0;
  }
  requiredInvDecl = this->inventoryDef.requiredInvDecl;
  if ( requiredInvDecl != nullptr )
  {
    v14 = (idJobManager *)v10->GetInventory(this: v10);
    v11 = idJobManager::FindJobByDecl(this: v14, jobDecl: (const idDeclJob *)requiredInvDecl) == nullptr ? 0 : v11;
  }
  if ( (_BYTE)v11 == 0 )
  {
    info->color = idColor::colorRed;
    info->colorState = CROSSHAIR_COLOR_NEGATIVE;
  }
  return v11;
}


// ========================================================================
// ?Activate@idProp_BreakableLoot@@AAAXPAVidPlayer@@@Z
// EA  : 0x82C9E080
// RVA : 0x00C9E080
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void __fastcall idProp_BreakableLoot::Activate(idProp_BreakableLoot *this, idPlayer *player)
{
  idPresentable *presentable; // r11
  idRenderModel *model; // r10
  idPhysics *Physics; // r3
  __int64 v7; // r9
  idPhysics *v8; // r28
  unsigned int v9; // r6
  double v10; // fp31
  int GameMsPerFrame; // r25
  int GameMs; // r29
  const idMat3 *v13; // r30
  const idDeclParticle *lootParticle; // r28
  idRenderModelEffects *MergeBranch; // r3
  const idVec3 *v16; // r7
  const idSoundShader *soundBreak; // r5
  int v18; // r28
  int v19; // r29
  idBreakable *v20; // r30
  idPhysics *v21; // r3
  double v22; // fp30
  double v23; // fp29
  double v24; // fp28
  float *v25; // r3
  double impulseMag; // fp1
  double v27; // fp9
  double v28; // fp7
  int v29; // r28
  int v30; // r30
  idBreakable *v31; // r29
  idPhysics *v32; // r3
  idBreakable *v33; // r29
  idPhysics *v34; // r3
  double v35; // fp30
  double v36; // fp29
  double v37; // fp28
  float *v38; // r3
  double v39; // fp1
  double v40; // fp9
  double v41; // fp7
  int v42; // r29
  int v43; // r30
  idEntity *v44; // r28
  idPhysics *v45; // r3
  int v46; // [sp+8h] [-F8h]
  int v47; // [sp+Ch] [-F4h]
  int v48; // [sp+10h] [-F0h]
  int v49; // [sp+14h] [-ECh]
  int v50; // [sp+18h] [-E8h]
  int v51; // [sp+1Ch] [-E4h]
  int v52; // [sp+20h] [-E0h]
  int v53; // [sp+24h] [-DCh]
  int v54; // [sp+28h] [-D8h]
  int v55; // [sp+2Ch] [-D4h]
  int v56; // [sp+30h] [-D0h]
  int v57; // [sp+34h] [-CCh]
  int v58; // [sp+38h] [-C8h]
  int v59; // [sp+3Ch] [-C4h]
  int v60; // [sp+40h] [-C0h]
  int v61; // [sp+44h] [-BCh]
  int v62; // [sp+48h] [-B8h]
  int v63; // [sp+4Ch] [-B4h]
  int v64; // [sp+50h] [-B0h]
  unsigned int v65; // [sp+60h] [-A0h] BYREF
  _QWORD v66[2]; // [sp+68h] [-98h] BYREF
  idVec3 v67; // [sp+78h] [-88h] BYREF
  idVec3 v68; // [sp+88h] [-78h] BYREF

  if ( player != nullptr )
  {
    idPlayer::LootItems(this: player, ent: this, disassemble: nullptr);
    if ( (*((_BYTE *)this + 5436) & 0x80) != 0 )
      idGameLayerManager::AddItemMemory(this: &player->gameLayerManager, itemName: this->name.data);
  }
  this->lootedTime = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  idEntity::BecomeInactive(this, flags: 2);
  presentable = this->presentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    presentable = this->presentable;
  }
  model = presentable->model;
  presentable->highlightColor = HIGHLIGHT_COLOR_NONE;
  model->g.highlightColor = HIGHLIGHT_COLOR_NONE;
  if ( this->effectsDef.lootParticle != nullptr )
  {
    v65 = -1;
    Physics = idEntity::GetPhysics(this);
    HIDWORD(v7) = 1664525;
    v8 = Physics;
    v9 = 1664525 * clientGame->random.seed;
    clientGame->random.seed = v9 + 1013904223;
    LODWORD(v7) = ((v9 + 1013904223) >> 10) & 0x7FFF;
    v66[0] = v7;
    v10 = (float)((float)v7 * (float)0.000030518509);
    GameMsPerFrame = idGameTimeManager::GetGameMsPerFrame(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    v13 = (const idMat3 *)v8->GetOrigin(this: v8, a2: 0);
    lootParticle = this->effectsDef.lootParticle;
    MergeBranch = (idRenderModelEffects *)idAnimator_BlendEq::InternalGetMergeBranch(this: (idAnimator_BlendEq *)clientGame);
    idRenderModelEffects::AddParticles(
      this: MergeBranch,
      particle: lootParticle,
      systemStartTime: GameMs,
      gameMsPerFrame: GameMsPerFrame,
      diversity: v10,
      origin: v16,
      axis: v13,
      velocity: mat3_identity.mat,
      color: &vec3_origin.x,
      a10: v46,
      a11: v47,
      a12: v48,
      a13: v49,
      a14: v50,
      a15: v51,
      a16: v52,
      a17: v53,
      a18: v54,
      a19: v55,
      a20: v56,
      a21: v57,
      a22: v58,
      a23: v59,
      a24: v60,
      a25: v61,
      a26: v62,
      a27: v63,
      a28: v64,
      a29: &v65);
  }
  soundBreak = this->effectsDef.soundBreak;
  if ( soundBreak != nullptr )
    idEntity::StartSoundShader(
      this,
      channel: SND_CHANNEL_ANY,
      shader: soundBreak,
      soundShaderFlags: (soundShaderFlags_t)0,
      peerMask: 0xFFu);
  v18 = 0;
  if ( this->spawnParts.num > 0 )
  {
    v19 = 0;
    do
    {
      v20 = idBreakable::CastTo(c: (idBreakable *)this->spawnParts.list[v19]);
      if ( v20 != nullptr )
      {
        v21 = idEntity::GetPhysics(this);
        v22 = (float)(this->effectsDef.impulseDir.x * (float)30.0);
        v23 = (float)(this->effectsDef.impulseDir.y * (float)30.0);
        v24 = (float)(this->effectsDef.impulseDir.z * (float)30.0);
        v25 = (float *)v21->GetOrigin(this: v21, a2: 0);
        impulseMag = this->effectsDef.impulseMag;
        v27 = (float)(v25[2] - (float)v24);
        v28 = (float)(v25[1] - (float)v23);
        v67.x = *v25 - (float)v22;
        v67.z = v27;
        v67.y = v28;
        idBreakable::AddExplosion(this: (idBreakable *)v66, result: v20, pos: &v67, impulse: impulseMag);
      }
      ++v18;
      ++v19;
    }
    while ( v18 < this->spawnParts.num );
  }
  v29 = 0;
  if ( this->spawnSplinters.num > 0 )
  {
    v30 = 0;
    do
    {
      v31 = (idBreakable *)this->spawnSplinters.list[v30];
      idEntity::BecomeActive(this: v31, flags: 1);
      idEntity::BecomeActive(this: v31, flags: 2);
      v31->Show(this: v31);
      v32 = idEntity::GetPhysics(this: v31);
      v32->EnableClip(this: v32);
      v33 = idBreakable::CastTo(c: v31);
      if ( v33 != nullptr )
      {
        v34 = idEntity::GetPhysics(this);
        v35 = (float)(this->effectsDef.impulseDir.x * (float)30.0);
        v36 = (float)(this->effectsDef.impulseDir.y * (float)30.0);
        v37 = (float)(this->effectsDef.impulseDir.z * (float)30.0);
        v38 = (float *)v34->GetOrigin(this: v34, a2: 0);
        v39 = this->effectsDef.impulseMag;
        v40 = (float)(v38[2] - (float)v37);
        v41 = (float)(v38[1] - (float)v36);
        v68.x = *v38 - (float)v35;
        v68.z = v40;
        v68.y = v41;
        idBreakable::AddExplosion(this: (idBreakable *)v66, result: v33, pos: &v68, impulse: v39);
      }
      ++v29;
      ++v30;
    }
    while ( v29 < this->spawnSplinters.num );
  }
  v42 = 0;
  if ( this->spawnEntitiesOnBreak.num > 0 )
  {
    v43 = 0;
    do
    {
      v44 = this->spawnEntitiesOnBreak.list[v43];
      idEntity::BecomeActive(this: v44, flags: 1);
      idEntity::BecomeActive(this: v44, flags: 2);
      v44->Show(this: v44);
      v45 = idEntity::GetPhysics(this: v44);
      v45->EnableClip(this: v45);
      ++v42;
      ++v43;
    }
    while ( v42 < this->spawnEntitiesOnBreak.num );
  }
  if ( this->triggerTargets )
    this->ActivateTargets(this, a2: player);
}


// ========================================================================
// ?OnActivate@idProp_BreakableLoot@@EAAXPAVidEntity@@@Z
// EA  : 0x82C9E488
// RVA : 0x00C9E488
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void __fastcall idProp_BreakableLoot::OnActivate(idProp_BreakableLoot *this, idPlayer *activator)
{
  idPlayer *v3; // r3

  v3 = idPlayer::CastTo(c: activator);
  idProp_BreakableLoot::Activate(this, player: v3);
}


// ========================================================================
// ?Spawn@idProp_VehicleJump@@QAAXXZ
// EA  : 0x82C9E4C8
// RVA : 0x00C9E4C8
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void __fastcall idProp_VehicleJump::Spawn(idProp_VehicleJump *this)
{
  idPhysics *Physics; // r29
  idPhysics_vtbl *v3; // r30
  int v4; // r3
  idPhysics *v5; // r29
  idPhysics_vtbl *v6; // r30
  int v7; // r3
  idPhysics *v8; // r3
  const idSoundShader *sound_spawn; // r5
  __int128 v10; // r6
  __int64 v11; // r8
  unsigned int v12; // r9

  Physics = idEntity::GetPhysics(this);
  v3 = Physics->__vftable;
  v4 = idContents::ToFlags(this: &this->clipOverride.contents);
  v3->SetContents(this: Physics, a2: v4 | 0x4000, a3: -1);
  v5 = idEntity::GetPhysics(this);
  v6 = v5->__vftable;
  v7 = idContents::ToFlags(this: &this->clipOverride.clipMask);
  v6->SetClipMask(this: v5, a2: v7 | 1, a3: -1);
  v8 = idEntity::GetPhysics(this);
  v8->EnableClip(this: v8);
  idEntity::BecomeInactive(this, flags: 2);
  if ( this->xLength <= 0.0 )
    this->xLength = 1.0;
  if ( this->yLength <= 0.0 )
    this->yLength = 1.0;
  if ( this->zLength <= 0.0 )
    this->zLength = 1.0;
  sound_spawn = this->sound_spawn;
  if ( sound_spawn != nullptr )
    idEntity::StartSoundShader(
      this,
      channel: SND_CHANNEL_BODY2,
      shader: sound_spawn,
      soundShaderFlags: (soundShaderFlags_t)0,
      peerMask: 0xFFu);
  this->lastUpdateTime = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  *(_QWORD *)((char *)&v10 + 4) = 0x3C6EF35F3C6EF35FLL;
  HIDWORD(v11) = 1664525 * clientGame->random.seed;
  clientGame->random.seed = HIDWORD(v11) + 1013904223;
  LODWORD(v11) = ((unsigned int)(HIDWORD(v11) + 1013904223) >> 10) & 0x7FFF;
  this->xTime = (float)((float)v11 * this->xLength) * (float)0.000030518509;
  v12 = 1664525 * clientGame->random.seed + 1013904223;
  clientGame->random.seed = v12;
  LODWORD(v10) = (v12 >> 10) & 0x7FFF;
  this->yTime = (float)((float)(__int64)v10 * this->yLength) * (float)0.000030518509;
  LODWORD(v11) = 1664525 * clientGame->random.seed + 1013904223;
  clientGame->random.seed = v11;
  DWORD2(v10) = ((unsigned int)v11 >> 10) & 0x7FFF;
  this->zTime = (float)((float)*(__int64 *)((char *)&v10 + 4) * this->zLength) * (float)0.000030518509;
  LODWORD(v11) = 1664525 * clientGame->random.seed + 1013904223;
  clientGame->random.seed = v11;
  LODWORD(v10) = ((unsigned int)v11 >> 10) & 0x7FFF;
  this->angle = (float)(__int64)v10 * (float)0.010986663;
}


// ========================================================================
// ?Show@idProp_VehicleJump@@UAAXXZ
// EA  : 0x82C9E6F0
// RVA : 0x00C9E6F0
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void __fastcall idProp_VehicleJump::Show(idProp_VehicleJump *this)
{
  const idSoundShader *sound_spawn; // r5

  sound_spawn = this->sound_spawn;
  if ( sound_spawn != nullptr )
    idEntity::StartSoundShader(
      this,
      channel: SND_CHANNEL_BODY2,
      shader: sound_spawn,
      soundShaderFlags: (soundShaderFlags_t)0,
      peerMask: 0xFFu);
  idEntity::BecomeActive(this, flags: 1);
  idEntity::Show(this);
  idProp_Moveable::BecomeSolid(this);
}


// ========================================================================
// ?Pickup@idProp_VehicleJump@@UAAXPAVidEntity@@_N@Z
// EA  : 0x82C9E750
// RVA : 0x00C9E750
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void __fastcall idProp_VehicleJump::Pickup(idProp_VehicleJump *this, idEntity *other, const bool addItem)
{
  idPlayer *PlayerFromEntity; // r30
  idSoundEmitter *SoundEmitter; // r3
  idPhysics *Physics; // r3

  PlayerFromEntity = idGameLocal::GetPlayerFromEntity(this: gameLocal, activator: other);
  if ( PlayerFromEntity != nullptr )
  {
    SoundEmitter = idEntity::GetSoundEmitter(this, alloc: false);
    if ( SoundEmitter != nullptr && SoundEmitter->IsCurrentlyPlaying(this: SoundEmitter, a2: SND_CHANNEL_BODY2) )
      idEntity::StopSound(this, channel: SND_CHANNEL_BODY2, peerMask: 0xFFu);
    Physics = idEntity::GetPhysics(this);
    Physics->SetContents(this: Physics, a2: 0, a3: -1);
    idJobManager::GiveSpecialEvent(
      this: &PlayerFromEntity->jobManager,
      specialEventDecl: this->specialEvent,
      fromEntity: this);
    idRageMetrics::SkillJump(this: clientGame->rageMetrics, player: PlayerFromEntity);
    idAnimatedEntity::StopFX(this, condition: 112);
    idAlarm::StartFX(this, condition: FX_PROP_PICKUP);
    idEventReceiver::PostEventMS(this, ev: &EV_BreakIt, time: 0);
    this->ActivateTargets(this, a2: PlayerFromEntity);
  }
}


// ========================================================================
// ?Event_Touch@idProp_VehicleJump@@IAA?AVeventVoid@@PAVidEntity@@H@Z
// EA  : 0x82C9E870
// RVA : 0x00C9E870
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

idProp_GameStateInt *__fastcall idProp_VehicleJump::Event_Touch(
        idProp_GameStateInt *this,
        eventVoid *result,
        idEntity *other,
        int clipModelId)
{
  if ( idGameLocal::GetPlayerFromEntity(this: gameLocal, activator: other) != nullptr )
    (*(void (__fastcall **)(eventVoid *, idEntity *, int))(*(_DWORD *)result + 680))(a1: result, a2: other, a3: 1);
  return this;
}


// ========================================================================
// ?Pickup@idProp_GameStateInt@@UAAXPAVidEntity@@_N@Z
// EA  : 0x82C9E8C8
// RVA : 0x00C9E8C8
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void __fastcall idProp_GameStateInt::Pickup(idProp_GameStateInt *this, idEntity *other, const bool addItem)
{
  idPlayer *PlayerFromEntity; // r30
  idPhysics *Physics; // r3
  const idSoundShader *sound_pickup; // r5

  PlayerFromEntity = idGameLocal::GetPlayerFromEntity(this: gameLocal, activator: other);
  if ( PlayerFromEntity != nullptr )
  {
    Physics = idEntity::GetPhysics(this);
    Physics->SetContents(this: Physics, a2: 0, a3: -1);
    idJobManager::SetGameStateIntValue(
      this: &PlayerFromEntity->jobManager,
      gameState: this->gameStateInt,
      stateValue: this->gameStateValue);
    idAnimatedEntity::StopFX(this, condition: 114);
    idAlarm::StartFX(this, condition: FX_PROP_PICKUP);
    sound_pickup = this->sound_pickup;
    if ( sound_pickup != nullptr )
      idPlayer::PlayLocalSound(
        this: PlayerFromEntity,
        channel: SND_CHANNEL_ALERT,
        shader: sound_pickup,
        soundShaderFlags: 0);
    idEventReceiver::PostEventMS(this, ev: &EV_Remove, time: 10000);
  }
}


// ========================================================================
// ?Show@idProp_VehiclePickup@@UAAXXZ
// EA  : 0x82C9E988
// RVA : 0x00C9E988
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void __fastcall idProp_VehiclePickup::Show(idProp_VehiclePickup *this)
{
  idPhysics *Physics; // r3
  idPhysics *v3; // r3

  idEntity::Show(this);
  idProp_Moveable::BecomeSolid(this);
  Physics = idEntity::GetPhysics(this);
  Physics->SetContents(this: Physics, a2: 0x4000, a3: -1);
  v3 = idEntity::GetPhysics(this);
  v3->EnableClip(this: v3);
  idEntity::BecomeActive(this, flags: 1);
  idEntity::BecomeInactive(this, flags: 2);
  *((_BYTE *)&this->physicsObj.fl + 4) |= 0xC0u;
}


// ========================================================================
// ?Event_Touch@idProp_VehiclePickup@@IAA?AVeventVoid@@PAVidEntity@@H@Z
// EA  : 0x82C9EA20
// RVA : 0x00C9EA20
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

idProp_VehiclePickup *__fastcall idProp_VehiclePickup::Event_Touch(
        idProp_VehiclePickup *this,
        eventVoid *result,
        idEntity *other,
        int clipModelId)
{
  if ( (unsigned __int8)idVehicle::IsTypeOf(c: other) != 0
    || *(_BYTE *)&result[7028] != 0 && (unsigned __int8)idPlayer::IsTypeOf(c: other) != 0 )
  {
    (*(void (__fastcall **)(eventVoid *, idEntity *, int))(*(_DWORD *)result + 680))(a1: result, a2: other, a3: 1);
  }
  return this;
}


// ========================================================================
// ?SendPlayerPickupInfo@idProp_VehiclePickup@@IAAXPBVidPlayer@@HH@Z
// EA  : 0x82C9EAA0
// RVA : 0x00C9EAA0
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void __fastcall idProp_VehiclePickup::SendPlayerPickupInfo(
        idProp_VehiclePickup *this,
        idPlayer *player,
        int count,
        int itemType)
{
  const idMaterial *pickupIcon; // r11
  idPlayerHud *PlayerHud; // r3
  idStrId v10; // [sp+50h] [-60h] BYREF
  idStr v11[2]; // [sp+60h] [-50h] BYREF

  if ( common->IsMultiplayer(this: common) && player != nullptr )
  {
    v11[0].len = 0;
    v11[0].allocedAndFlag = 20;
    v11[0].data = v11[0].baseBuffer;
    v11[0].baseBuffer[0] = 0;
    pickupIcon = this->pickupIcon;
    if ( pickupIcon != nullptr )
      idStr::operator=(this: v11, text: pickupIcon->name.str);
    v10.index = this->pickupName.index;
    PlayerHud = (idPlayerHud *)idPlayer::GetPlayerHud(this: player);
    idPlayerHud::VehiclePickUp(this: PlayerHud, icon: v11, count, displayName: &v10, itemType);
    idStr::FreeData(this: v11);
  }
}


// ========================================================================
// __unwind$498026
// EA  : 0x82C9EB54
// RVA : 0x00C9EB54
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void _unwind_498026()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 176 + 96));
}


// ========================================================================
// ?HandleInventory@idProp_VehiclePickup@@IAAXPAVidVehicle_Car@@@Z
// EA  : 0x82C9EB88
// RVA : 0x00C9EB88
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void __fastcall idProp_VehiclePickup::HandleInventory(idProp_VehiclePickup *this, idVehicle_Car *car)
{
  int v4; // r11
  char v5; // r11
  bool v6; // zf
  const idMaterial *pickupIcon; // r11
  idPlayer *v8; // r3
  idPlayerHud *PlayerHud; // r3
  idPlayer *Driver; // r3
  idPlayer *v11; // r3
  const idDeclInventory *inventoryDecl; // r4
  const idDeclInventory *v13; // r27
  int v14; // r27
  int i; // r28
  const idDeclInventory *v16; // r30
  idPresentable *presentable; // r30
  int inventoryCount; // r28
  idInventoryCollection *v19; // r3
  idJobManager *v20; // r3
  idStrId *JobByDecl; // r30
  idPlayer *v22; // r28
  bool v23; // r3
  int index; // r11
  bool v25; // r27
  int v26; // r26
  char v27; // r25
  idStrId *DisplayName; // r24
  int v29; // r29
  bool v30; // r30
  idPlayerHud *v31; // r3
  idInventoryItem v32; // [sp+50h] [-A0h] BYREF
  idStr v33[3]; // [sp+80h] [-70h] BYREF

  v4 = *(_DWORD *)(this->GetType(this) + 36);
  if ( v4 < idProp_Boost::Type.typeNum || (v6 = v4 <= idProp_Boost::Type.lastChild, v5 = 1, !v6) )
    v5 = 0;
  if ( v5 != 0 )
  {
    if ( common->IsMultiplayer(this: common) )
    {
      Driver = (idPlayer *)idVehicle::GetDriver(this: car);
      v11 = idPlayer::CastTo(c: Driver);
      idProp_VehiclePickup::SendPlayerPickupInfo(this, player: v11, count: 0, itemType: 0);
      idVehicle_Car::ResetBoostPower(this: car);
    }
    else
    {
      v32.count = 0;
      HIBYTE(v32.counttosave) = 0;
      v32.quickSlot = 20;
      *(_DWORD *)&v32.forSale = &v32.counttosave;
      pickupIcon = this->pickupIcon;
      if ( pickupIcon != nullptr )
        idStr::operator=(this: (idStr *)&v32.count, text: pickupIcon->name.str);
      v8 = idVehicle::PlayerIsOccupant(this: car);
      if ( v8 != nullptr )
      {
        v32.__vftable = (idInventoryItem_vtbl *)this->pickupName.index;
        PlayerHud = (idPlayerHud *)idPlayer::GetPlayerHud(this: v8);
        idPlayerHud::PickUp(
          this: PlayerHud,
          icon: (const idStr *)&v32.count,
          isWeapon: false,
          count: 0,
          special: false,
          displayName: (idStrId *)&v32,
          itemType: 0,
          newItem: false);
      }
      idStr::FreeData(this: (idStr *)&v32.count);
      idVehicle_Car::ResetBoostPower(this: car);
    }
  }
  else
  {
    inventoryDecl = this->inventoryDecl;
    if ( inventoryDecl != nullptr && inventoryDecl->quickSlotGroup != QUICKSLOTGROUP_NONE
      || idVehicle::UsesAmmo(this: car, ammoDecl: inventoryDecl) )
    {
      v13 = this->inventoryDecl;
    }
    else
    {
      v14 = 0;
      if ( this->alternateInventoryDecl.num <= 0 )
        return;
      for ( i = 0; ; ++i )
      {
        v16 = this->alternateInventoryDecl.list[i];
        if ( v16 != nullptr && v16->quickSlotGroup != QUICKSLOTGROUP_NONE )
          break;
        if ( idVehicle::UsesAmmo(this: car, ammoDecl: v16) )
          break;
        if ( ++v14 >= this->alternateInventoryDecl.num )
          return;
      }
      v13 = v16;
    }
    if ( v13 != nullptr )
    {
      presentable = car->presentable;
      if ( presentable == nullptr )
      {
        idEntity::InitPresentableInternal(this: car);
        presentable = car->presentable;
      }
      inventoryCount = this->inventoryCount;
      v19 = car->GetInventory_2(this: car);
      idInventoryCollection::GiveItem(
        this: v19,
        owner: presentable,
        decl: v13,
        count: inventoryCount,
        forceCount: false,
        canIntro: false);
      v20 = (idJobManager *)car->GetInventory_2(this: car);
      JobByDecl = (idStrId *)idJobManager::FindJobByDecl(this: v20, jobDecl: (const idDeclJob *)v13);
      if ( *(_BYTE *)(JobByDecl[3].index + 316) == 0 )
      {
        v22 = idVehicle::PlayerIsOccupant(this: car);
        if ( v22 != nullptr )
        {
          v33[0].len = 0;
          v33[0].baseBuffer[0] = 0;
          v33[0].allocedAndFlag = 20;
          v33[0].data = v33[0].baseBuffer;
          v32.__vftable = *(idInventoryItem_vtbl **)(JobByDecl[3].index + 212);
          if ( v32.__vftable != nullptr )
            idStr::operator=(this: v33, text: (const char *)v32.CallEvent);
          v23 = idPlayer::CheckIsNewItem(this: v22, decl: v13);
          index = JobByDecl[3].index;
          v25 = v23;
          v26 = *(_DWORD *)(index + 428);
          v27 = *(_BYTE *)(index + 380);
          v32.__vftable = (idInventoryItem_vtbl *)index;
          DisplayName = idInventoryItem::GetDisplayName(this: &v32, result: JobByDecl);
          v29 = this->inventoryCount;
          v30 = idWeapon::CastTo(c: (idWeapon *)JobByDecl) != nullptr;
          v31 = (idPlayerHud *)idPlayer::GetPlayerHud(this: v22);
          idPlayerHud::PickUp(
            this: v31,
            icon: v33,
            isWeapon: v30,
            count: v29,
            special: v27,
            displayName: DisplayName,
            itemType: v26,
            newItem: v25);
          idStr::FreeData(this: v33);
        }
      }
    }
  }
}


// ========================================================================
// __unwind$498085
// EA  : 0x82C9EEA4
// RVA : 0x00C9EEA4
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void _unwind_498085()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 240 + 96));
}


// ========================================================================
// __unwind$498086
// EA  : 0x82C9EECC
// RVA : 0x00C9EECC
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void _unwind_498086()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 240 + 128));
}


// ========================================================================
// ?Spawn@idProp_Explosive@@QAAXXZ
// EA  : 0x82C9EEF8
// RVA : 0x00C9EEF8
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void __fastcall idProp_Explosive::Spawn(idProp_Explosive *this)
{
  idPhysics *Physics; // r3
  idSoundShader *sndPreExplode; // r3

  *(_BYTE *)&this->flags |= 6u;
  Physics = idEntity::GetPhysics(this);
  this->DeactivatePhysics(this, a2: Physics->physicsId);
  sndPreExplode = this->sndPreExplode;
  if ( sndPreExplode != nullptr )
    this->preExplodeSndLength = idSoundShader::GetMaxLength(this: sndPreExplode);
}


// ========================================================================
// ?IsAIInRange@idProp_Explosive@@IBA_NPBVidActor@@ABVidVec3@@M_N@Z
// EA  : 0x82C9EF60
// RVA : 0x00C9EF60
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

BOOL __fastcall idProp_Explosive::IsAIInRange(
        idProp_Explosive *this,
        idActor *act,
        const idVec3 *position,
        double radiusSq,
        const bool checkDetonation,
        char a6)
{
  idPhysics *Physics; // r3
  float *v12; // r3
  double v13; // fp8
  const idFaction *v14; // r3
  BOOL result; // r3
  idRelationship::attitude_t v16[4]; // [sp+50h] [-40h] BYREF

  result = false;
  if ( !act->IsDead(this: act)
    && (a6 == 0
     || (this->detonateOnAIs || (unsigned __int8)idAI2::IsTypeOf(c: act) == 0)
     && (this->detonateOnPlayers || (unsigned __int8)idPlayer::IsTypeOf(c: act) == 0)) )
  {
    Physics = idEntity::GetPhysics(this: act);
    v12 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
    v13 = (float)(position->y - v12[1]);
    if ( (float)((float)((float)v13 * (float)v13) + (float)((float)(position->x - *v12) * (float)(position->x - *v12))) <= radiusSq
      && __fabs((float)(position->z - v12[2])) <= 100.0 )
    {
      if ( this->faction == nullptr )
        return true;
      v14 = act->GetFaction_2(this: act);
      idDeclFaction::GetAttitudeTowards(this: this->faction, otherFaction: v14->myFaction, attitude: v16);
      if ( v16[0] < ATTITUDE_NEUTRAL )
        return true;
    }
  }
  return result;
}


// ========================================================================
// ?Event_PreDetonate@idProp_Explosive@@IAA?AVeventVoid@@PAVidEntity@@@Z
// EA  : 0x82C9F0B8
// RVA : 0x00C9F0B8
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

idProp_Explosive *__fastcall idProp_Explosive::Event_PreDetonate(
        idProp_Explosive *this,
        idEntity *result,
        idEntity *activator)
{
  idEntity::StartSoundShader(
    this: result,
    channel: SND_CHANNEL_ANY,
    shader: (const idSoundShader *)LODWORD(result[8].defaultPhysicsObj.current.worldAxis.mat[2].y),
    soundShaderFlags: SSF_PLAY_ONCE|SSF_NO_RANDOM_OFFSET,
    peerMask: 0xFFu);
  return this;
}


// ========================================================================
// ?ModifyCrosshairInfo@idProp_JobPosting@@UBA_NPBVidEntity@@ABVidFocusTrace@@W4usableState_t@@AAVidCrosshairInfo@@@Z
// EA  : 0x82C9F100
// RVA : 0x00C9F100
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

int __fastcall idProp_JobPosting::ModifyCrosshairInfo(
        idProp_JobPosting *this,
        idPlayer *activator,
        const idFocusTrace *ft,
        const usableState_t usable,
        idCrosshairInfo *info)
{
  idPlayer *v7; // r3
  idJobManager *p_jobManager; // r29
  int v9; // r28
  int v10; // r31
  idJob *JobByDecl; // r3

  v7 = idPlayer::CastTo(c: activator);
  if ( v7 != nullptr && (p_jobManager = &v7->jobManager, v9 = 0, this->jobDeclList.num > 0) )
  {
    v10 = 0;
    while ( 1 )
    {
      if ( idJobManager::IsJobAvailable(this: p_jobManager, jobDecl: this->jobDeclList.list[v10]) )
      {
        JobByDecl = idJobManager::FindJobByDecl(this: p_jobManager, jobDecl: this->jobDeclList.list[v10]);
        if ( JobByDecl == nullptr || JobByDecl->status < (unsigned int)JOBSTATUS_ACCEPTED )
          break;
      }
      ++v9;
      ++v10;
      if ( v9 >= this->jobDeclList.num )
        goto LABEL_8;
    }
    info->text.index = this->displayName.index;
    return 1;
  }
  else
  {
LABEL_8:
    info->colorState = CROSSHAIR_COLOR_NEGATIVE;
    return 0;
  }
}


// ========================================================================
// ?Spawn@idProp_Spawnable@@QAAXXZ
// EA  : 0x82C9F1C0
// RVA : 0x00C9F1C0
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void __fastcall idProp_Spawnable::Spawn(idProp_Spawnable *this)
{
  idPhysics *Physics; // r3
  idBreakableManager *p_breakableManager; // r30
  const idVec3 *v4; // r3

  if ( this->breakable != nullptr )
  {
    Physics = idEntity::GetPhysics(this);
    p_breakableManager = &gameLocal->breakableManager;
    v4 = Physics->GetOrigin(this: Physics, a2: 0);
    idBreakableManager::AddBreakable(this: p_breakableManager, decl: this->breakable, origin: v4);
  }
  if ( this->ponyTail.declPonytail != nullptr )
    idPonytail::Init(this: &this->ponyTail, parent_: this);
  *(_BYTE *)&this->flags &= ~0x40u;
}


// ========================================================================
// ?ActivateSpawnableProp@idProp_Spawnable@@QAAXXZ
// EA  : 0x82C9F260
// RVA : 0x00C9F260
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void __fastcall idProp_Spawnable::ActivateSpawnableProp(idProp_Spawnable *this)
{
  int GameMs; // r3
  idPresentable *presentable; // r11

  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  presentable = this->presentable;
  this->activationStartTime = GameMs;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    presentable = this->presentable;
  }
  idRenderModel::SetModelFade(this: presentable->model, v: 1.0);
  this->fade.fadeStartTime = 0;
  this->fade.fadeEndTime = 0;
  this->fade.noStippleFade = false;
  this->fade.fadeFrom = 0.0;
  this->fade.fadeTo = 0.0;
  if ( this->ponyTail.declPonytail != nullptr )
    idEntity::BecomeActive(this, flags: 4);
}


// ========================================================================
// ?HideSpawnable@idProp_Spawnable@@IAAXXZ
// EA  : 0x82C9F308
// RVA : 0x00C9F308
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void __fastcall idProp_Spawnable::HideSpawnable(idProp_Spawnable *this)
{
  idPresentable *presentable; // r3
  idRenderModel *RenderModelFromPresentable; // r3

  this->Hide_2(this);
  presentable = this->presentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    presentable = this->presentable;
  }
  presentable->Present(this: presentable);
  idEntity::BecomeInactive(this, flags: 7);
  RenderModelFromPresentable = idEntity::GetRenderModelFromPresentable(this);
  RenderModelFromPresentable->RemoveDecal(
    this: RenderModelFromPresentable,
    a2: (const idHandle<int,enum invalidDecalHandle_t,-1> *)-1);
  this->activationStartTime = -1;
}


// ========================================================================
// ?Break@idProp_Spawnable@@IAAXABVidVec3@@M@Z
// EA  : 0x82C9F398
// RVA : 0x00C9F398
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void __fastcall idProp_Spawnable::Break(idProp_Spawnable *this, const idVec3 *dir, double impulse)
{
  idPhysics *Physics; // r29
  idPhysics *v7; // r28
  idPhysics *v8; // r27
  idPhysics *v9; // r3
  idBreakableManager *p_breakableManager; // r29
  const idVec3 *(__fastcall *GetOrigin)(idPhysics *, int); // ctr
  const idVec3 *v12; // r26
  const idMat3 *v13; // r28
  const idVec3 *v14; // r3
  idPhysics *v15; // r3
  const idMat3 *v16; // r28
  __int64 v17; // r6
  unsigned int v18; // r10
  double v19; // fp31
  int GameMsPerFrame; // r27
  int GameMs; // r30
  const idDeclParticle *impactParticle; // r29
  idRenderModelEffects *MergeBranch; // r3
  const idVec3 *v24; // r7
  const idSoundShader *breakableSound; // r5
  int v26; // [sp+8h] [-A8h]
  int v27; // [sp+Ch] [-A4h]
  int v28; // [sp+10h] [-A0h]
  int v29; // [sp+14h] [-9Ch]
  int v30; // [sp+18h] [-98h]
  int v31; // [sp+1Ch] [-94h]
  int v32; // [sp+20h] [-90h]
  int v33; // [sp+24h] [-8Ch]
  int v34; // [sp+28h] [-88h]
  int v35; // [sp+2Ch] [-84h]
  int v36; // [sp+30h] [-80h]
  int v37; // [sp+34h] [-7Ch]
  int v38; // [sp+38h] [-78h]
  int v39; // [sp+3Ch] [-74h]
  int v40; // [sp+40h] [-70h]
  int v41; // [sp+44h] [-6Ch]
  int v42; // [sp+48h] [-68h]
  int v43; // [sp+4Ch] [-64h]
  int v44; // [sp+50h] [-60h]
  unsigned int v45; // [sp+60h] [-50h] BYREF
  __int64 v46; // [sp+68h] [-48h]

  if ( this->breakable != nullptr )
  {
    Physics = idEntity::GetPhysics(this);
    v7 = idEntity::GetPhysics(this);
    v8 = idEntity::GetPhysics(this);
    v9 = Physics;
    GetOrigin = Physics->GetOrigin;
    p_breakableManager = &gameLocal->breakableManager;
    v12 = GetOrigin(this: v9, a2: 0);
    v13 = v7->GetAxis(this: v7, a2: 0);
    v14 = v8->GetOrigin(this: v8, a2: 0);
    idBreakableManager::UseBreakable(
      this: p_breakableManager,
      decl: this->breakable,
      origin: v14,
      axis: v13,
      dir,
      pos: v12,
      impulse,
      fadeTime: 0.0);
    idProp_Spawnable::HideSpawnable(this);
  }
  if ( this->impactParticle != nullptr )
  {
    v45 = -1;
    v15 = idEntity::GetPhysics(this);
    v16 = (const idMat3 *)v15->GetOrigin(this: v15, a2: 0);
    HIDWORD(v17) = off_822F0000;
    v18 = 1664525 * clientGame->random.seed;
    clientGame->random.seed = v18 + 1013904223;
    LODWORD(v17) = ((v18 + 1013904223) >> 10) & 0x7FFF;
    v46 = v17;
    v19 = (float)((float)v17 * (float)0.000030518509);
    GameMsPerFrame = idGameTimeManager::GetGameMsPerFrame(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    impactParticle = this->impactParticle;
    MergeBranch = (idRenderModelEffects *)idAnimator_BlendEq::InternalGetMergeBranch(this: (idAnimator_BlendEq *)clientGame);
    idRenderModelEffects::AddParticles(
      this: MergeBranch,
      particle: impactParticle,
      systemStartTime: GameMs,
      gameMsPerFrame: GameMsPerFrame,
      diversity: v19,
      origin: v24,
      axis: v16,
      velocity: mat3_identity.mat,
      color: &vec3_origin.x,
      a10: v26,
      a11: v27,
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
      a28: v44,
      a29: &v45);
  }
  breakableSound = this->breakableSound;
  if ( breakableSound != nullptr )
    idEntity::StartSoundShader(
      this,
      channel: SND_CHANNEL_ANY,
      shader: breakableSound,
      soundShaderFlags: (soundShaderFlags_t)0,
      peerMask: 0xFFu);
}


// ========================================================================
// ?Spawn@idProp_OnlineCollectible@@QAAXXZ
// EA  : 0x82C9F588
// RVA : 0x00C9F588
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void __fastcall idProp_OnlineCollectible::Spawn(idProp_OnlineCollectible *this)
{
  idPresentable *presentable; // r3
  bool shouldPlayPickupSound; // r30
  idPresentable *v4; // r3
  const idSoundShader *sound_pickup; // r30
  idPresentable *v6; // r3
  int v7; // r10
  int v8; // r8
  int v9; // r7
  int v10; // r3
  int v11; // r9
  idPresentable *v12; // r3
  idPhysics *Physics; // r30
  idPresentable *v14; // r31
  int v15; // r3
  int v16; // r10
  int v17; // r9
  int v18; // r8
  int v19; // r7
  int v20; // r6
  int v21; // r5
  int v22; // [sp+8h] [-68h]
  int v23; // [sp+Ch] [-64h]
  int v24; // [sp+10h] [-60h]
  int v25; // [sp+14h] [-5Ch]
  int v26; // [sp+18h] [-58h]
  idPresentable *v27; // [sp+1Ch] [-54h]

  presentable = this->presentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    presentable = this->presentable;
  }
  shouldPlayPickupSound = this->shouldPlayPickupSound;
  presentable->GetPropInterface(this: presentable)->shouldPlayPickupSound = shouldPlayPickupSound;
  if ( this->sound_pickup != nullptr )
  {
    v4 = this->presentable;
    if ( v4 == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      v4 = this->presentable;
    }
    sound_pickup = this->sound_pickup;
    v4->GetPropInterface(this: v4)->pickupSound = sound_pickup;
  }
  v6 = this->presentable;
  if ( v6 == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    v6 = this->presentable;
  }
  v10 = (int)v6->GetPropInterface(this: v6);
  v11 = 1;
  *(_BYTE *)(v10 + 1271) = 1;
  v12 = this->presentable;
  if ( v12 == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    v12 = this->presentable;
  }
  idPresentable::SetClipModelInfo(
    this: v12,
    clipModelInfo_: &this->clipModelInfo,
    clipModelSpawnPos_: &this->spawnPosition,
    clipModelSpawnAxis_: &this->spawnOrientation,
    a5: v9,
    a6: v8,
    a7: v11,
    a8: v7,
    a9: v22,
    a10: v23,
    a11: v24,
    a12: v25,
    a13: v26,
    a14: v27);
  Physics = idEntity::GetPhysics(this);
  if ( this->presentable == nullptr )
    idEntity::InitPresentableInternal(this);
  v14 = this->presentable;
  v15 = Physics->GetContents(this: Physics, a2: -1);
  idPresentable::SetClipModelContents(this: v14, newContents: v15, a3: v21, a4: v20, a5: v19, a6: v18, a7: v17, a8: v16);
}


// ========================================================================
// ?Hide@idProp_OnlineCollectible@@UAAXXZ
// EA  : 0x82C9F6D0
// RVA : 0x00C9F6D0
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void __fastcall idProp_OnlineCollectible::Hide(idProp_OnlineCollectible *this)
{
  idPhysics *Physics; // r3

  idEntity::Hide(this, stopFx: false);
  *((_BYTE *)&this->physicsObj.fl + 4) &= 0x3Fu;
  Physics = idEntity::GetPhysics(this);
  Physics->UnlinkClip(this: Physics);
  idEntity::BecomeInactive(this, flags: 2);
}


// ========================================================================
// ?Show@idProp_OnlineCollectible@@UAAXXZ
// EA  : 0x82C9F738
// RVA : 0x00C9F738
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void __fastcall idProp_OnlineCollectible::Show(idProp_OnlineCollectible *this)
{
  idPhysics *Physics; // r30
  idPresentable *presentable; // r31
  int v4; // r3
  int v5; // r10
  int v6; // r9
  int v7; // r8
  int v8; // r7
  int v9; // r6
  int v10; // r5

  idEntity::Show(this);
  idProp_Moveable::BecomeSolid(this);
  Physics = idEntity::GetPhysics(this);
  if ( this->presentable == nullptr )
    idEntity::InitPresentableInternal(this);
  presentable = this->presentable;
  v4 = Physics->GetContents(this: Physics, a2: -1);
  idPresentable::SetClipModelContents(
    this: presentable,
    newContents: v4,
    a3: v10,
    a4: v9,
    a5: v8,
    a6: v7,
    a7: v6,
    a8: v5);
}


// ========================================================================
// ?Pickup@idProp_OnlineCollectible@@UAAXPAVidEntity@@_N@Z
// EA  : 0x82C9F7C8
// RVA : 0x00C9F7C8
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void __fastcall idProp_OnlineCollectible::Pickup(idProp_OnlineCollectible *this, idEntity *entity, const bool addItem)
{
  idPhysics *Physics; // r3
  idPhysics *v6; // r29
  idPresentable *presentable; // r30
  int v8; // r3
  int v9; // r10
  int v10; // r9
  int v11; // r8
  int v12; // r7
  int v13; // r6
  int v14; // r5
  idPresentable *v15; // r29
  idPresentable *v16; // r30
  idPresentableProp *v17; // r3
  __int64 v18; // r5
  unsigned int v19; // r8
  int v20; // r30
  int v21; // r3
  idProp_OnlineCollectible_vtbl *v22; // r8

  Physics = idEntity::GetPhysics(this);
  Physics->SetContents(this: Physics, a2: 0, a3: -1);
  v6 = idEntity::GetPhysics(this);
  if ( this->presentable == nullptr )
    idEntity::InitPresentableInternal(this);
  presentable = this->presentable;
  v8 = v6->GetContents(this: v6, a2: -1);
  idPresentable::SetClipModelContents(
    this: presentable,
    newContents: v8,
    a3: v14,
    a4: v13,
    a5: v12,
    a6: v11,
    a7: v10,
    a8: v9);
  if ( this->presentable == nullptr )
    idEntity::InitPresentableInternal(this);
  v15 = this->presentable;
  v16 = entity->presentable;
  if ( v16 == nullptr )
  {
    idEntity::InitPresentableInternal(this: entity);
    v16 = entity->presentable;
  }
  v17 = v15->GetPropInterface(this: v15);
  idPresentableProp::PickupProp(this: v17, activator: v16);
  if ( this->minRespawnDelay <= 0.0 )
  {
    idEventReceiver::PostEventMS(this, ev: &EV_Remove, time: 0);
  }
  else
  {
    HIDWORD(v18) = 1;
    v19 = 1664525 * clientGame->random.seed + 1013904223;
    clientGame->random.seed = v19;
    LODWORD(v18) = (v19 >> 10) & 0x7FFF;
    v20 = (int)(float)((float)((float)((float)((float)((float)v18 * (float)0.000061037019) - (float)1.0)
                                     * (float)(this->maxRespawnDelay - this->minRespawnDelay))
                             + this->minRespawnDelay)
                     * (float)1000.0);
    v21 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
    v22 = this->__vftable;
    this->respawnTime = v21 + v20;
    v22->Hide_2(this);
    idEntity::BecomeActive(this, flags: 1);
  }
}


// ========================================================================
// ??1idProp_PlayerInteraction@@UAA@XZ
// EA  : 0x82C9F998
// RVA : 0x00C9F998
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void __fastcall idProp_PlayerInteraction::~idProp_PlayerInteraction(idProp_PlayerInteraction *this)
{
  this->__vftable = (idProp_PlayerInteraction_vtbl *)&idProp_PlayerInteraction::`vftable';
  idAnimator_Channel::~idAnimator_Channel(this: &this->channelAnimator);
  this->__vftable = (idProp_PlayerInteraction_vtbl *)&idProp::`vftable';
  idAnimatedEntity::~idAnimatedEntity(this);
}


// ========================================================================
// __unwind$498547
// EA  : 0x82C9F9F8
// RVA : 0x00C9F9F8
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void _unwind_498547()
{
  int v0; // r12

  idProp_Usable::~idProp_Usable(this: *(idProp_Usable **)(v0 - 112 + 132));
}


// ========================================================================
// ?Think@idProp_PlayerInteraction@@UAAXXZ
// EA  : 0x82C9FA20
// RVA : 0x00C9FA20
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void __fastcall idProp_PlayerInteraction::Think(idProp_PlayerInteraction *this)
{
  int GameMs; // r30
  const idAnimStack *v3; // r3
  __int64 v4; // r8
  blendParms_t v5[3]; // [sp+50h] [-40h] BYREF

  if ( this->nextIdleTime > 0
    && this->nextIdleTime < idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) )
  {
    blendParms_t::blendParms_t(this: v5);
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    v3 = this->GetAnimStack_2(this);
    LODWORD(v4) = v5;
    if ( (unsigned __int8)idAnimator_Channel::CycleAnim(
                            this: &this->channelAnimator,
                            stack: v3,
                            ah: &this->idleAnimAlias,
                            curTime: GameMs,
                            rateScale: 1.0,
                            leafStarted: v4,
                            a7: nullptr) != 0 )
      this->nextIdleTime = -1;
  }
  idAnimatedEntity::UpdateAnimation(this, forceNonDeferredBlend: false);
}


// ========================================================================
// ?GetUsableState@idMinigame@@UBA?AW4usableState_t@@PBVidEntity@@ABVidFocusTrace@@@Z
// EA  : 0x82C9FAE8
// RVA : 0x00C9FAE8
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

// attributes: thunk
int __fastcall idMinigame::GetUsableState(idMinigame *this, idPlayer *activator, const idFocusTrace *ft)
{
  return idUse::GetUsableState(this, activator, ft);
}


// ========================================================================
// ?Spawn@idProp_Secret@@QAAXXZ
// EA  : 0x82C9FAF0
// RVA : 0x00C9FAF0
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void __fastcall idProp_Secret::Spawn(idProp_Secret *this)
{
  int SecretForEntity; // r3
  idPlayerProfileGame *v3; // r3
  int id; // r4

  SecretForEntity = idDeclSecrets::FindSecretForEntity(name: this->name.data);
  this->id = SecretForEntity;
  if ( SecretForEntity == -1 )
  {
    idLib::Warning(
      fmt: "Secret '%s' exists in the map but doesn't have a secret declaration, removing entity",
      this->name.data);
    idEventReceiver::PostEventMS(this, ev: &EV_Remove, time: 0);
  }
  else
  {
    v3 = (idPlayerProfileGame *)common->GetProfileFromMasterLocalUser(this: common);
    if ( v3 != nullptr )
    {
      id = this->id;
      if ( id >= 0 && idPlayerProfileGame::GetSecret(this: v3, secretId: id) )
      {
        if ( g_secretDebug.valueInteger != 0 )
          idLib::Warning(fmt: "Player already has secret '%s', removing entity", this->name.data);
        this->Hide_2(this);
      }
    }
  }
}


// ========================================================================
// ??0idProp_MissionBoard@@QAA@XZ
// EA  : 0x82C9FBD8
// RVA : 0x00C9FBD8
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

idProp_MissionBoard *__fastcall idProp_MissionBoard::idProp_MissionBoard(idProp_MissionBoard *this)
{
  idAnimatedEntity::idAnimatedEntity(this);
  this->missionPinDef = nullptr;
  this->__vftable = (idProp_MissionBoard_vtbl *)&idProp_MissionBoard::`vftable';
  return this;
}


// ========================================================================
// ?PostSpawn@idProp_MissionBoard@@UAAXXZ
// EA  : 0x82C9FC20
// RVA : 0x00C9FC20
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void __fastcall idProp_MissionBoard::PostSpawn(idProp_MissionBoard *this)
{
  idPlayer *Player; // r3
  idPresentable *presentable; // r3
  idPresentablePlayer *v3; // r3

  Player = idGameLocal::GetPlayer(this: gameLocal, i: 0);
  if ( Player != nullptr )
  {
    presentable = Player->presentable;
    if ( presentable != nullptr )
    {
      v3 = presentable->GetPlayerInterface_2(this: presentable);
      if ( v3 != nullptr )
        idPresentablePlayer::InitSideMissions(this: v3);
    }
  }
}


// ========================================================================
// ?ModifyCrosshairInfo@idProp_MissionPin@@UBA_NPBVidEntity@@ABVidFocusTrace@@W4usableState_t@@AAVidCrosshairInfo@@@Z
// EA  : 0x82C9FC80
// RVA : 0x00C9FC80
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

// attributes: thunk
int __fastcall idProp_MissionPin::ModifyCrosshairInfo(
        idProp_MissionPin *this,
        idPlayer *activator,
        const idFocusTrace *ft,
        const usableState_t usable,
        idCrosshairInfo *info)
{
  return idUse::ModifyCrosshairInfo(this, activator, ft, usable, info);
}


// ========================================================================
// ?ModifyCrosshairInfo@idCombiner@@UBA_NPBVidEntity@@ABVidFocusTrace@@W4usableState_t@@AAVidCrosshairInfo@@@Z
// EA  : 0x82C9FC88
// RVA : 0x00C9FC88
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

int __fastcall idCombiner::ModifyCrosshairInfo(
        idCombiner *this,
        idPlayer *activator,
        const idFocusTrace *ft,
        usableState_t usable,
        idCrosshairInfo *info)
{
  idPlayer *v9; // r3
  int num; // r11
  idPlayer *v11; // r28
  int v12; // r27
  int v13; // r29
  int v14; // r30
  const idDeclJob *v15; // r25
  idJobManager *v16; // r3
  idJob *JobByDecl; // r3

  if ( (unsigned __int8)idUse::ModifyCrosshairInfo(this, activator, ft, usable, info) == 0 )
    return 0;
  if ( (unsigned __int8)idPlayer::IsTypeOf(c: activator) != 0 )
  {
    v9 = idPlayer::CastTo(c: activator);
    num = this->neededItemsDecl.num;
    v11 = v9;
    v12 = 0;
    v13 = 0;
    if ( num > 0 )
    {
      v14 = 0;
      do
      {
        v15 = (const idDeclJob *)this->neededItemsDecl.list[v14];
        v16 = (idJobManager *)v11->GetInventory(this: v11);
        JobByDecl = idJobManager::FindJobByDecl(this: v16, jobDecl: v15);
        if ( JobByDecl != nullptr
          && ((int (__fastcall *)(idJob *))JobByDecl->__vftable[2].dtr_idClass)(a1: JobByDecl) > 0 )
        {
          ++v12;
        }
        num = this->neededItemsDecl.num;
        ++v13;
        ++v14;
      }
      while ( v13 < num );
    }
    info->icons.list->usable = (_cntlzw(num - v12) & 0x20) != 0;
    info->hoverSound = this->hoverSound;
    info->useCheckbox = true;
  }
  return 1;
}


// ========================================================================
// ?SetNoBlink@idCombiner@@QAAX_N@Z
// EA  : 0x82C9FD80
// RVA : 0x00C9FD80
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void __fastcall idCombiner::SetNoBlink(idCombiner *this, bool noBlink_)
{
  idPresentable *presentable; // r11
  char v4; // r10
  idRenderModel *v5; // r10
  idRenderModel *model; // r10

  presentable = this->presentable;
  this->noBlink = noBlink_;
  if ( presentable == nullptr || (v4 = 1, presentable->model == nullptr) )
    v4 = 0;
  if ( v4 == 0 || noBlink_ )
  {
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      presentable = this->presentable;
    }
    model = presentable->model;
    presentable->highlightColor = HIGHLIGHT_COLOR_NONE;
    model->g.highlightColor = HIGHLIGHT_COLOR_NONE;
    idEntity::UpdateVisuals(this);
  }
  else
  {
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      presentable = this->presentable;
    }
    v5 = presentable->model;
    presentable->highlightColor = HIGHLIGHT_COLOR_USE;
    v5->g.highlightColor = HIGHLIGHT_COLOR_USE;
    idEntity::UpdateVisuals(this);
  }
}


// ========================================================================
// ?GetUsableState@idProp_CombineItem@@UBA?AW4usableState_t@@PBVidEntity@@ABVidFocusTrace@@@Z
// EA  : 0x82C9FE38
// RVA : 0x00C9FE38
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

int __fastcall idProp_CombineItem::GetUsableState(
        idProp_CombineItem *this,
        idPlayer *activator,
        const idFocusTrace *ft)
{
  char v3; // r11

  if ( !this->isUsable || (v3 = 1, (*(_BYTE *)&this->flags & 8) == 0) )
    v3 = 0;
  if ( v3 != 0 )
    return !idUseConstraints::IsWithinConstraints(this: &this->useConstraints, activator, owner: this) ? 0 : 3;
  else
    return 0;
}


// ========================================================================
// ??0idUse@@QAA@XZ
// EA  : 0x82C9FEB8
// RVA : 0x00C9FEB8
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

idUse *__fastcall idUse::idUse(idUse *this)
{
  idEntity::idEntity(this);
  this->__vftable = (idUse_vtbl *)&idUse::`vftable';
  this->displayText.index = -1;
  this->displayIcon = nullptr;
  this->angleConstraintHorizontal.value = -1.0;
  this->angleConstraintVertical.value = -1.0;
  this->distanceConstraint = -1.0;
  this->saveGameUtility.maxTension = PLAYER_TENSION_NONE;
  this->saveGameUtility.ignoreTension = true;
  this->saveGameUtility.saveGameWhenUsed = NEVER;
  this->saveGameUtility.playerSpawnSpot.spawnId.value = 0x1FFF;
  this->saveGameUtility.hasSavedGame = false;
  *((_BYTE *)this + 844) &= 0xFu;
  this->useButtonOverride = BUTTON_USE;
  this->useFlags = 0;
  return this;
}


// ========================================================================
// ?Spawn@idUse@@QAAXXZ
// EA  : 0x82C9FF50
// RVA : 0x00C9FF50
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void __fastcall idUse::Spawn(idUse *this)
{
  idPhysics *Physics; // r3
  idPresentable *presentable; // r11
  char v4; // r10
  idRenderModel *model; // r10

  Physics = idEntity::GetPhysics(this);
  Physics->SetContents(this: Physics, a2: 0x200000, a3: -1);
  presentable = this->presentable;
  if ( presentable == nullptr || (v4 = 1, presentable->model == nullptr) )
    v4 = 0;
  if ( v4 != 0 && (*(_BYTE *)&this->flags & 8) != 0 && (*((_BYTE *)this + 844) & 0x20) == 0 )
  {
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      presentable = this->presentable;
    }
    model = presentable->model;
    presentable->highlightColor = HIGHLIGHT_COLOR_USE;
    model->g.highlightColor = HIGHLIGHT_COLOR_USE;
  }
  if ( this->angleConstraintHorizontal.value >= 0.0 )
    this->useFlags |= 1u;
  if ( this->angleConstraintVertical.value >= 0.0 )
    this->useFlags |= 2u;
  if ( this->distanceConstraint >= 0.0 )
    this->useFlags |= 4u;
  if ( this->saveGameUtility.saveGameWhenUsed != NEVER
    && gameLocal->spawnIds.ptr[this->saveGameUtility.playerSpawnSpot.spawnId.value & 0x1FFF] != this->saveGameUtility.playerSpawnSpot.spawnId.value >> 13 )
  {
    idLib::Warning(
      fmt: "idUse '%s' is set to save when used but does not have a valid playerSpawnSpot specified, save is disabled",
      this->name.data);
  }
}


// ========================================================================
// ?OnMakeActivatable@idUse@@UAAX_N@Z
// EA  : 0x82CA00A0
// RVA : 0x00CA00A0
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void __fastcall idUse::OnMakeActivatable(idUse *this, const bool activatable)
{
  idPresentable *presentable; // r11
  char v4; // r10
  idRenderModel *model; // r10
  char v6; // r10
  idRenderModel *v7; // r10

  presentable = this->presentable;
  if ( presentable == nullptr || (v4 = 1, presentable->model == nullptr) )
    v4 = 0;
  if ( v4 != 0 && activatable && (*((_BYTE *)this + 844) & 0x20) == 0 )
  {
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      presentable = this->presentable;
    }
    model = presentable->model;
    presentable->highlightColor = HIGHLIGHT_COLOR_USE;
    model->g.highlightColor = HIGHLIGHT_COLOR_USE;
  }
  else
  {
    if ( presentable == nullptr || (v6 = 1, presentable->model == nullptr) )
      v6 = 0;
    if ( v6 != 0 )
    {
      if ( presentable == nullptr )
      {
        idEntity::InitPresentableInternal(this);
        presentable = this->presentable;
      }
      v7 = presentable->model;
      presentable->highlightColor = HIGHLIGHT_COLOR_NONE;
      v7->g.highlightColor = HIGHLIGHT_COLOR_NONE;
    }
  }
}


// ========================================================================
// ?Use@idPropSmartLoot@@UAA_NPAVidEntity@@W4usableState_t@@@Z
// EA  : 0x82CA0178
// RVA : 0x00CA0178
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

int __fastcall idPropSmartLoot::Use(idPropSmartLoot *this, idPlayer *user, const usableState_t usable)
{
  idPlayer *v5; // r29
  idPhysics *Physics; // r3
  idPresentable *presentable; // r11
  char v8; // r10
  idRenderModel *model; // r10
  idEventReceiver v11[5]; // [sp+50h] [-40h] BYREF

  if ( (*(_BYTE *)&this->flags & 8) == 0 )
    return 0;
  if ( usable != USABLE_LOOT )
    return 0;
  idEntity::Use(this, activator: user, usable: USABLE_LOOT);
  this->ActivateTargets(this, a2: user);
  idEventReceiver::ProcessEvent(this: v11, result: (idEventArg *)this, ev: &EV_NotifyProgressionOwner);
  v5 = idPlayer::CastTo(c: user);
  if ( v5 == nullptr )
    return 0;
  if ( !this->hasActivated )
  {
    this->hasActivated = true;
    idSmartLootComponent::Activate(this: &this->smartLootComponent, owner: this);
    this->smartLootComponent.Update(this: &this->smartLootComponent, a2: this, a3: v5);
  }
  idPlayer::LootItems(this: v5, ent: this, disassemble: nullptr);
  Physics = idEntity::GetPhysics(this);
  Physics->SetContents(this: Physics, a2: 0, a3: -1);
  presentable = this->presentable;
  if ( presentable == nullptr || (v8 = 1, presentable->model == nullptr) )
    v8 = 0;
  if ( v8 != 0 )
  {
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      presentable = this->presentable;
    }
    model = presentable->model;
    presentable->highlightColor = HIGHLIGHT_COLOR_NONE;
    model->g.highlightColor = HIGHLIGHT_COLOR_NONE;
    idEntity::UpdateVisuals(this);
  }
  return 1;
}


// ========================================================================
// ?Spawn@idProp@@QAAXXZ
// EA  : 0x82CA02C8
// RVA : 0x00CA02C8
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void __fastcall idProp::Spawn(idProp *this)
{
  idPresentable *presentable; // r11
  char v3; // r10

  presentable = this->presentable;
  if ( presentable == nullptr || (v3 = 1, presentable->model == nullptr) )
    v3 = 0;
  if ( v3 != 0 )
  {
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      presentable = this->presentable;
    }
    presentable->model->g.castDimShadows = DIMSHADOW_ON;
  }
  if ( this->GetFXDecl(this) != nullptr )
  {
    idEntity::BecomeActive(this, flags: 1);
    idAlarm::StartFX(this, condition: FX_PROP_SPAWN);
  }
}


// ========================================================================
// ??0idProp_Usable@@QAA@XZ
// EA  : 0x82CA0370
// RVA : 0x00CA0370
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

idProp_Usable *__fastcall idProp_Usable::idProp_Usable(idProp_Usable *this)
{
  idAnimatedEntity::idAnimatedEntity(this);
  this->triggerTargets = false;
  this->__vftable = (idProp_Usable_vtbl *)&idProp_Usable::`vftable';
  this->use_vec.x = 0.0;
  this->use_vec.y = 0.0;
  this->use_vec.z = 0.0;
  this->isUsable = true;
  this->use_yaw = 0.0;
  this->noBlink = false;
  this->use_radius = 0.0;
  this->sound_use = nullptr;
  this->hoverSound = nullptr;
  this->displayIcon = nullptr;
  this->saveGameUtility.maxTension = PLAYER_TENSION_NONE;
  this->saveGameUtility.ignoreTension = true;
  this->saveGameUtility.saveGameWhenUsed = NEVER;
  this->saveGameUtility.playerSpawnSpot.spawnId.value = 0x1FFF;
  this->saveGameUtility.hasSavedGame = false;
  return this;
}


// ========================================================================
// ?Spawn@idProp_Usable@@QAAXXZ
// EA  : 0x82CA0408
// RVA : 0x00CA0408
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void __fastcall idProp_Usable::Spawn(idProp_Usable *this)
{
  idPhysics *Physics; // r3
  idPresentable *presentable; // r11
  char v4; // r10
  idRenderModel *model; // r10

  Physics = idEntity::GetPhysics(this);
  Physics->SetContents(this: Physics, a2: 131073, a3: -1);
  presentable = this->presentable;
  if ( presentable == nullptr || (v4 = 1, presentable->model == nullptr) )
    v4 = 0;
  if ( v4 != 0 && this->isUsable && !this->noBlink )
  {
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      presentable = this->presentable;
    }
    model = presentable->model;
    presentable->highlightColor = HIGHLIGHT_COLOR_USE;
    model->g.highlightColor = HIGHLIGHT_COLOR_USE;
  }
  if ( this->saveGameUtility.saveGameWhenUsed != NEVER
    && gameLocal->spawnIds.ptr[this->saveGameUtility.playerSpawnSpot.spawnId.value & 0x1FFF] != this->saveGameUtility.playerSpawnSpot.spawnId.value >> 13 )
  {
    idLib::Warning(
      fmt: "idProp_Usable '%s' is set to save when used but does not have a valid playerSpawnSpot specified, save is disabled",
      this->name.data);
  }
}


// ========================================================================
// ?SetUsable@idProp_Usable@@QAAX_N@Z
// EA  : 0x82CA0508
// RVA : 0x00CA0508
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void __fastcall idProp_Usable::SetUsable(idProp_Usable *this, bool b)
{
  idPresentable *presentable; // r3
  idPresentable *v4; // r3
  bool isUsable; // r30
  idPresentable *v6; // r11
  char v7; // r10
  idRenderModel *v8; // r10
  idRenderModel *model; // r10

  presentable = this->presentable;
  this->isUsable = b;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    presentable = this->presentable;
  }
  if ( presentable->GetPropInterface(this: presentable) != nullptr )
  {
    v4 = this->presentable;
    if ( v4 == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      v4 = this->presentable;
    }
    isUsable = this->isUsable;
    v4->GetPropInterface(this: v4)->isUsable = isUsable;
  }
  v6 = this->presentable;
  if ( v6 == nullptr || (v7 = 1, v6->model == nullptr) )
    v7 = 0;
  if ( v7 != 0 )
  {
    if ( !this->isUsable || this->noBlink )
    {
      if ( v6 == nullptr )
      {
        idEntity::InitPresentableInternal(this);
        v6 = this->presentable;
      }
      model = v6->model;
      v6->highlightColor = HIGHLIGHT_COLOR_NONE;
      model->g.highlightColor = HIGHLIGHT_COLOR_NONE;
    }
    else
    {
      if ( v6 == nullptr )
      {
        idEntity::InitPresentableInternal(this);
        v6 = this->presentable;
      }
      v8 = v6->model;
      v6->highlightColor = HIGHLIGHT_COLOR_USE;
      v8->g.highlightColor = HIGHLIGHT_COLOR_USE;
    }
  }
}


// ========================================================================
// ?OnMakeActivatable@idProp_Usable@@MAAX_N@Z
// EA  : 0x82CA0618
// RVA : 0x00CA0618
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

// attributes: thunk
void __fastcall idProp_Usable::OnMakeActivatable(idProp_Usable *this, bool activatable)
{
  idProp_Usable::SetUsable(this, b: activatable);
}


// ========================================================================
// ?SetNoBlink@idProp_Usable@@QAAX_N@Z
// EA  : 0x82CA0620
// RVA : 0x00CA0620
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void __fastcall idProp_Usable::SetNoBlink(idProp_Usable *this, bool noBlink_)
{
  this->noBlink = noBlink_;
  idProp_Usable::SetUsable(this, b: this->isUsable);
  idEntity::UpdateVisuals(this);
}


// ========================================================================
// ?Event_SetUsable@idProp_Usable@@AAA?AVeventVoid@@_N@Z
// EA  : 0x82CA0660
// RVA : 0x00CA0660
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

idProp_Usable *__fastcall idProp_Usable::Event_SetUsable(idProp_Usable *this, idProp_Usable *result, bool usable)
{
  idProp_Usable::SetUsable(this: result, b: usable);
  return this;
}


// ========================================================================
// ??0idProp_ContinuallyUsed@@QAA@XZ
// EA  : 0x82CA06A0
// RVA : 0x00CA06A0
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

idProp_ContinuallyUsed *__fastcall idProp_ContinuallyUsed::idProp_ContinuallyUsed(idProp_ContinuallyUsed *this)
{
  idProp_Usable::idProp_Usable(this);
  this->user = nullptr;
  this->__vftable = (idProp_ContinuallyUsed_vtbl *)&idProp_ContinuallyUsed::`vftable';
  this->usedState = 0.0;
  this->waitTimeIfDamaged = 0.0;
  this->triggerSuccess.list = nullptr;
  this->triggerSuccess.granularity = 0;
  this->triggerSuccess.memTag = 5;
  this->triggerSuccess.listStatic = 0;
  this->triggerSuccess.size = 0;
  this->triggerSuccess.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->triggerSuccess);
  this->triggerFail.list = nullptr;
  this->triggerFail.granularity = 0;
  this->triggerFail.memTag = 5;
  this->triggerFail.listStatic = 0;
  this->triggerFail.size = 0;
  this->triggerFail.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->triggerFail);
  this->finishes = true;
  this->rateOfIncrease = 0.1;
  this->rateOfDecrease = 0.1;
  this->useRotation.pitch = 0.0;
  this->useRotation.yaw = 0.0;
  this->useRotation.roll = 0.0;
  this->soundProgressing = nullptr;
  this->soundRegressing = nullptr;
  this->soundReset = nullptr;
  this->enumUseState = INACTIVE;
  return this;
}


// ========================================================================
// __unwind$500425
// EA  : 0x82CA0774
// RVA : 0x00CA0774
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void _unwind_500425()
{
  int v0; // r12

  idProp_Usable::~idProp_Usable(this: *(idProp_Usable **)(v0 - 144 + 164));
}


// ========================================================================
// __unwind$500426
// EA  : 0x82CA079C
// RVA : 0x00CA079C
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void _unwind_500426()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 5276));
}


// ========================================================================
// ?Spawn@idProp_Moveable@@QAAXXZ
// EA  : 0x82CA07D0
// RVA : 0x00CA07D0
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void __fastcall idProp_Moveable::Spawn(idProp_Moveable *this)
{
  idLinkList<idProp_Moveable> *head; // r4
  idPresentable *presentable; // r4
  int v4; // r29
  int v5; // r28
  idPresentable *v6; // r4
  const idDeclInventory **list; // r27
  int v8; // r26
  int v9; // r27
  idProp_Moveable::idAdditionalInventoryItem *v10; // r29
  signed int randCount; // r11
  int v12; // r28
  unsigned int seed; // r9
  unsigned int v14; // r6
  int v15; // r5
  idPresentable *v16; // r4
  double friction; // fp0
  double bouncyness; // fp0
  int model; // r10
  int v20; // r9
  int v21; // r8
  int v22; // r7
  const idDeclInventory *inventoryDecl; // r11
  idPresentable *v24; // r11
  char v25; // r11
  idPresentable *v26; // r11
  const idSoundShader *sound_spawn; // r5
  idPresentable *v28; // r3
  idPhysics *Physics; // r28
  idPresentable *v30; // r29
  int v31; // r3
  int v32; // r10
  int v33; // r9
  int v34; // r8
  int v35; // r7
  int v36; // r6
  int v37; // r5
  idPresentable *v38; // r3
  int v39; // [sp+8h] [-D8h]
  int v40; // [sp+Ch] [-D4h]
  int v41; // [sp+10h] [-D0h]
  int v42; // [sp+14h] [-CCh]
  int v43; // [sp+18h] [-C8h]
  idPresentable *v44; // [sp+1Ch] [-C4h]
  idStr v45[4]; // [sp+60h] [-80h] BYREF

  v45[0].len = 0;
  v45[0].allocedAndFlag = 20;
  v45[0].data = v45[0].baseBuffer;
  v45[0].baseBuffer[0] = 0;
  head = gameLocal->propMoveableEntities.head;
  this->propNode.prev->next = this->propNode.next;
  this->propNode.next->prev = this->propNode.prev;
  this->propNode.prev = &this->propNode;
  this->propNode.head = &this->propNode;
  this->propNode.next = head;
  this->propNode.prev = head->prev;
  head->prev = &this->propNode;
  this->propNode.prev->next = &this->propNode;
  this->propNode.head = head->head;
  if ( this->inventoryDecl != nullptr )
  {
    presentable = this->presentable;
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      presentable = this->presentable;
    }
    idInventoryCollection::GiveItem(
      this: &this->inventory,
      owner: presentable,
      decl: this->inventoryDecl,
      count: this->inventoryCount,
      forceCount: false,
      canIntro: false);
    v4 = 0;
    if ( this->alternateInventoryDecl.num > 0 )
    {
      v5 = 0;
      do
      {
        v6 = this->presentable;
        list = this->alternateInventoryDecl.list;
        if ( v6 == nullptr )
        {
          idEntity::InitPresentableInternal(this);
          v6 = this->presentable;
        }
        idInventoryCollection::GiveItem(
          this: &this->inventory,
          owner: v6,
          decl: list[v5],
          count: this->inventoryCount,
          forceCount: false,
          canIntro: false);
        ++v4;
        ++v5;
      }
      while ( v4 < this->alternateInventoryDecl.num );
    }
    v8 = 0;
    if ( this->additionalInventoryDecl.num > 0 )
    {
      v9 = 0;
      do
      {
        v10 = &this->additionalInventoryDecl.list[v9];
        randCount = v10->randCount;
        if ( randCount != 0 )
        {
          seed = clientGame->random.seed;
          __twllei(randCount, 0);
          v14 = 1664525 * seed + 1013904223;
          clientGame->random.seed = v14;
          v15 = (v14 >> 10) & 0x7FFF;
          v12 = v15 % randCount;
          __twlgei(randCount & ~(__ROL4__(v15, 1) - 1), 0xFFFFFFFF);
        }
        else
        {
          v12 = 0;
        }
        v16 = this->presentable;
        if ( v16 == nullptr )
        {
          idEntity::InitPresentableInternal(this);
          v16 = this->presentable;
        }
        idInventoryCollection::GiveItem(
          this: &this->inventory,
          owner: v16,
          decl: v10->decl,
          count: v10->count + v12,
          forceCount: v10->forceCount,
          canIntro: false);
        ++v8;
        ++v9;
      }
      while ( v8 < this->additionalInventoryDecl.num );
    }
  }
  friction = this->friction;
  if ( friction >= 0.0 )
  {
    if ( friction > 1.0 )
      friction = 1.0;
  }
  else
  {
    friction = 0.0;
  }
  this->friction = friction;
  bouncyness = this->bouncyness;
  if ( bouncyness >= 0.0 )
  {
    if ( bouncyness > 1.0 )
      bouncyness = 1.0;
  }
  else
  {
    bouncyness = 0.0;
  }
  this->bouncyness = bouncyness;
  this->nextDamageTime = 0;
  this->nextBounceTime = 0;
  this->nextScrapeTime = 0;
  this->nextSelfDamageTime = 0;
  this->fade.fadeFrom = 0.0;
  this->fade.fadeEndTime = 0;
  this->fade.fadeTo = 0.0;
  this->fade.fadeStartTime = 0;
  this->fade.noStippleFade = false;
  this->InitPropPhysics(this);
  if ( this->pickupName.index >= 0
    || (inventoryDecl = this->inventoryDecl) != nullptr
    && (model = (int)&inventoryDecl->displayName, inventoryDecl->displayName.index >= 0) )
  {
    model = *((unsigned __int8 *)this + 5296);
    v24 = this->presentable;
    v20 = model & 0xF7;
    *((_BYTE *)this + 5296) = v20;
    if ( v24 == nullptr || (model = (int)v24->model, v25 = 1, model == 0) )
      v25 = 0;
    if ( v25 != 0 )
    {
      v20 = this->IsEverUsable(this, a2: nullptr);
      if ( v20 != 0 )
      {
        model = this->noBlink;
        if ( !this->noBlink )
        {
          v26 = this->presentable;
          if ( v26 == nullptr )
          {
            idEntity::InitPresentableInternal(this);
            v26 = this->presentable;
          }
          v20 = (int)v26->model;
          model = 2;
          v26->highlightColor = HIGHLIGHT_COLOR_ITEM;
          *(_DWORD *)(v20 + 240) = 2;
        }
      }
    }
  }
  sound_spawn = this->sound_spawn;
  if ( sound_spawn != nullptr )
    idEntity::StartSoundShader(
      this,
      channel: SND_CHANNEL_BODY2,
      shader: sound_spawn,
      soundShaderFlags: (soundShaderFlags_t)0,
      peerMask: 0xFFu);
  v28 = this->presentable;
  if ( v28 == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    v28 = this->presentable;
  }
  idPresentable::SetClipModelInfo(
    this: v28,
    clipModelInfo_: &this->clipModelInfo,
    clipModelSpawnPos_: &this->spawnPosition,
    clipModelSpawnAxis_: &this->spawnOrientation,
    a5: v22,
    a6: v21,
    a7: v20,
    a8: model,
    a9: v39,
    a10: v40,
    a11: v41,
    a12: v42,
    a13: v43,
    a14: v44);
  Physics = idEntity::GetPhysics(this);
  if ( this->presentable == nullptr )
    idEntity::InitPresentableInternal(this);
  v30 = this->presentable;
  v31 = Physics->GetContents(this: Physics, a2: -1);
  idPresentable::SetClipModelContents(this: v30, newContents: v31, a3: v37, a4: v36, a5: v35, a6: v34, a7: v33, a8: v32);
  if ( this->inventoryDecl != nullptr && this->IsEverUsable(this, a2: nullptr) )
  {
    v38 = this->presentable;
    if ( v38 == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      v38 = this->presentable;
    }
    v38->GetPropInterface(this: v38)->pickupOnUse = true;
  }
  if ( (*((_BYTE *)this + 5296) & 0x80) != 0 || (*((_BYTE *)this + 5296) & 0x40) != 0 )
  {
    idEntity::BecomeActive(this, flags: 1);
  }
  else if ( (*((_BYTE *)this + 5297) & 0x10) != 0 )
  {
    idEntity::BecomeInactive(this, flags: 1);
  }
  idStr::FreeData(this: v45);
}


// ========================================================================
// __unwind$500478
// EA  : 0x82CA0C68
// RVA : 0x00CA0C68
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void _unwind_500478()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 224 + 96));
}


// ========================================================================
// ?Hide@idProp_Moveable@@UAAXXZ
// EA  : 0x82CA0C90
// RVA : 0x00CA0C90
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void __fastcall idProp_Moveable::Hide(idProp_Moveable *this)
{
  idPhysics *Physics; // r3

  idEntity::Hide(this);
  *((_BYTE *)&this->physicsObj.fl + 4) &= 0x3Fu;
  Physics = idEntity::GetPhysics(this);
  Physics->UnlinkClip(this: Physics);
  idEntity::BecomeInactive(this, flags: 2);
}


// ========================================================================
// ?Fade@idProp_Moveable@@QAAXABM0ABH@Z
// EA  : 0x82CA0CF0
// RVA : 0x00CA0CF0
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void __fastcall idProp_Moveable::Fade(idProp_Moveable *this, float *from, float *to, const int *time)
{
  idPresentable *presentable; // r11
  char v6; // r11
  bool v7; // zf
  idPresentable *v8; // r11

  presentable = this->presentable;
  if ( presentable == nullptr || (v7 = presentable->model != nullptr, v6 = 1, !v7) )
    v6 = 0;
  if ( v6 != 0 )
  {
    idFadeHelper::Fade(this: &this->fade, from, to, time, _noStippleFade: false);
    v8 = this->presentable;
    if ( v8 == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      v8 = this->presentable;
    }
    v8->Present(this: v8);
  }
  else
  {
    idLib::Warning(fmt: "idProp_Moveable::Fade() called on '%s' with no render model!", this->name.data);
  }
}


// ========================================================================
// ?NaniteInspection@idProp_Moveable@@QAAXXZ
// EA  : 0x82CA0DA0
// RVA : 0x00CA0DA0
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void __fastcall idProp_Moveable::NaniteInspection(idProp_Moveable *this)
{
  idProp_Usable::SetUsable(this, b: false);
  idEventReceiver::CancelEvents(this, ev: &EV_Pulse);
  idEventReceiver::PostEventMS(this, ev: &EV_Remove, time: 0);
}


// ========================================================================
// ?Event_Fade@idProp_Moveable@@IAA?AVeventVoid@@MMM@Z
// EA  : 0x82CA0DF8
// RVA : 0x00CA0DF8
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

idProp_Moveable *__fastcall idProp_Moveable::Event_Fade(
        idProp_Moveable *this,
        idProp_Moveable *result,
        double from,
        double to,
        double secs,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        float a11,
        float a12,
        float a13,
        float a14,
        float a15,
        float a16,
        float a17,
        float a18,
        float a19,
        float a20)
{
  int v22; // [sp+50h] [-20h] BYREF
  int v23; // [sp+54h] [-1Ch]

  a18 = from;
  a20 = to;
  v23 = (int)(float)((float)secs * (float)1000.0);
  v22 = v23;
  idProp_Moveable::Fade(this: result, from: &a18, to: &a20, time: &v22);
  return this;
}


// ========================================================================
// ?Use@idProp_BreakableLoot@@UAA_NPAVidEntity@@W4usableState_t@@@Z
// EA  : 0x82CA0E60
// RVA : 0x00CA0E60
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

int __fastcall idProp_BreakableLoot::Use(idProp_BreakableLoot *this, idPlayer *user, const usableState_t usable)
{
  idPlayer *v5; // r3

  v5 = idPlayer::CastTo(c: user);
  if ( usable != USABLE_LOOT || v5 == nullptr )
    return 0;
  idProp_BreakableLoot::Activate(this, player: v5);
  return 1;
}


// ========================================================================
// ?StartFromBrokenProp@idProp_Breakable@@IAAXABVidVec3@@ABVidMat3@@10@Z
// EA  : 0x82CA0EC8
// RVA : 0x00CA0EC8
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idProp_Breakable::StartFromBrokenProp(
        idProp_Breakable *this,
        const idVec3 *origin,
        const idMat3 *axis,
        const idMat3 *hitAxis,
        const idVec3 *angularVelocity)
{
  idClientGame *v7; // r7
  __int64 v9; // r10 OVERLAPPED
  unsigned int seed; // r8
  __int64 v13; // r7 OVERLAPPED
  unsigned int v14; // r5
  double v15; // fp30
  unsigned int v16; // r5
  double v17; // fp29
  double v18; // fp28
  idPhysics *Physics; // r3
  idPhysics *v20; // r3
  idPhysics *v21; // r3
  idPhysics *v22; // r3
  idPhysics *v23; // r3
  __int64 v24; // r10
  unsigned int v25; // r7
  double y; // fp11
  double z; // fp12
  idPhysics *v28; // r3
  double v29; // fp2
  double v30; // fp13
  double v31; // fp11
  idPresentable *presentable; // r11
  double fadeTime; // fp13
  unsigned int v34; // r6
  int v35; // r29
  _BYTE v36[20]; // [sp+70h] [-110h] BYREF
  __int64 v37; // [sp+90h] [-F0h]
  float v38[4]; // [sp+98h] [-E8h] BYREF
  float v39[6]; // [sp+A8h] [-D8h] BYREF
  char v40; // [sp+C0h] [-C0h]
  float v41; // [sp+C4h] [-BCh]
  char v42; // [sp+E0h] [-A0h]
  float v43; // [sp+E4h] [-9Ch]
  const idEventArg *v44; // [sp+E8h] [-98h]
  const idEventArg *v45; // [sp+ECh] [-94h]
  int v46; // [sp+F0h] [-90h]
  float v47[5]; // [sp+100h] [-80h] BYREF

  v7 = clientGame;
  HIDWORD(v9) = 1664525 * clientGame->random.seed + 1013904223;
  clientGame->random.seed = HIDWORD(v9);
  seed = v7->random.seed;
  LODWORD(v9) = (v7->random.seed >> 10) & 0x7FFF;
  HIDWORD(v13) = clientGame->random.seed;
  v14 = 1664525 * clientGame->random.seed;
  clientGame->random.seed = v14 + 1013904223;
  LODWORD(v13) = ((v14 + 1013904223) >> 10) & 0x7FFF;
  v37 = v13;
  v15 = (float)((float)((float)((float)((float)v9 * (float)0.000061037019) - (float)1.0) * (float)300.0) + (float)100.0);
  v16 = 1664525 * clientGame->random.seed;
  clientGame->random.seed = v16 + 1013904223;
  HIDWORD(v9) = ((v16 + 1013904223) >> 10) & 0x7FFF;
  v37 = *(__int64 *)((char *)&v9 + 4);
  v17 = (float)((float)((float)((float)v13 * (float)0.000061037019) - (float)1.0) * (float)300.0);
  v18 = (float)((float)((float)((float)*(__int64 *)((char *)&v9 + 4) * (float)0.000061037019) - (float)1.0)
              * (float)300.0);
  Physics = idEntity::GetPhysics(this);
  Physics->SetContents(this: Physics, a2: 128, a3: -1);
  v20 = idEntity::GetPhysics(this);
  v20->SetClipMask(this: v20, a2: 1, a3: -1);
  v21 = idEntity::GetPhysics(this);
  v21->SetOrigin(this: v21, a2: origin, a3: -1);
  v22 = idEntity::GetPhysics(this);
  v22->SetAxis(this: v22, a2: axis, a3: -1);
  v23 = idEntity::GetPhysics(this);
  HIDWORD(v24) = clientGame->random.seed;
  v25 = 1664525 * clientGame->random.seed + 1013904223;
  clientGame->random.seed = v25;
  y = angularVelocity->y;
  z = angularVelocity->z;
  LODWORD(v24) = (v25 >> 10) & 0x7FFF;
  v37 = v24;
  v38[0] = (float)(angularVelocity->x * (float)((float)v24 * (float)0.000030518509)) * (float)25.0;
  v38[1] = (float)((float)y * (float)((float)v24 * (float)0.000030518509)) * (float)25.0;
  v38[2] = (float)((float)z * (float)((float)v24 * (float)0.000030518509)) * (float)25.0;
  v23->SetAngularVelocity(this: v23, a2: (const idVec3 *)v38, a3: 0);
  v28 = idEntity::GetPhysics(this);
  v29 = hitAxis->mat[2].z;
  v30 = (float)((float)(hitAxis->mat[1].z * (float)v17) + (float)(hitAxis->mat[0].z * (float)v18));
  v31 = (float)((float)(hitAxis->mat[2].y * (float)v15)
              + (float)((float)(hitAxis->mat[1].y * (float)v17) + (float)(hitAxis->mat[0].y * (float)v18)));
  v39[0] = (float)(hitAxis->mat[0].x * (float)v18)
         + (float)((float)(hitAxis->mat[1].x * (float)v17) + (float)(hitAxis->mat[2].x * (float)v15));
  v39[1] = v31;
  v39[2] = (float)((float)v29 * (float)v15) + (float)v30;
  v28->SetLinearVelocity(this: v28, a2: (const idVec3 *)v39, a3: 0);
  idEntity::BecomeActive(this, flags: 3);
  presentable = this->presentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    presentable = this->presentable;
  }
  *((_BYTE *)&presentable->model->g + 105) |= 0x80u;
  idProp_Usable::SetUsable(this, b: false);
  fadeTime = this->fadeTime;
  this->state = DAMAGED|EXPLODING;
  if ( fadeTime <= 0.0 )
    this->fadeTime = 1.0;
  v41 = 0.0;
  HIBYTE(v47[0]) = 102;
  v40 = 102;
  v42 = 102;
  v34 = 1664525 * clientGame->random.seed;
  v43 = 1.0;
  clientGame->random.seed = v34 + 1013904223;
  v47[1] = this->fadeTime;
  v35 = 250
      * ((((v34 + 1013904223) >> 10) & 0x7FFF)
       - 3 * ((unsigned __int64)(1431655766LL * (((v34 + 1013904223) >> 10) & 0x7FFF)) >> 32));
  memcpy(Dst: v36, Src: v47, Size: sizeof(v36));
  idEventReceiver::PostEventMS(
    this,
    ev: &EV_Fade,
    time: v35,
    arg1: v44,
    arg2: v45,
    arg3: (const idEventArg *)__ROL4__(v46, 32));
  LODWORD(v37) = (int)(float)((float)(this->fadeTime * (float)1000.0) + (float)__SPAIR64__(&unk_82150000, v35));
  idEventReceiver::PostEventMS(this, ev: &EV_Remove, time: v37);
}


// ========================================================================
// ?Break@idProp_Breakable@@IAAXPAVidEntity@@ABVidVec3@@@Z
// EA  : 0x82CA12A0
// RVA : 0x00CA12A0
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idProp_Breakable::Break(idProp_Breakable *this, idEntity *activator, idMat3 *dir)
{
  idPhysics *Physics; // r3
  const idVec3 *v7; // r19
  idPhysics *v8; // r3
  const idMat3 *v9; // r18
  idPhysics *v10; // r3
  idEntity *BindMaster; // r3
  idEntity *v12; // r3
  const idSoundShader *sound_break; // r5
  char flags; // r9
  int started; // r30
  idPhysics *v16; // r3
  double v17; // fp31
  int v18; // r26
  const idDeclEntityDef *breakable; // r11
  idPhysics *v20; // r28
  idPhysics *v21; // r27
  idPhysics *v22; // r3
  __int64 v23; // r11
  idPhysics *v24; // r30
  idPhysics *v25; // r3
  double removeDelay; // fp29
  idBreakableManager *p_breakableManager; // r28
  double v28; // fp28
  const idVec3 *v29; // r25
  const idMat3 *v30; // r27
  const idVec3 *v31; // r3
  const idDeclEntityDef *explosionProjectile; // r4
  idProjectile *v33; // r3
  idProjectile *v34; // r30
  idPhysics *v35; // r3
  const idVec3 *v36; // r3
  idPresentable *presentable; // r3
  int v38; // r3
  idPhysics *v39; // r3
  const idDeclDamage *explodeDamage; // r30
  const idVec3 *v41; // r3
  idPhysics *v42; // r30
  int GameMs; // r28
  idPhysics *v44; // r3
  idAIEventManager *p_aiEventManager; // r30
  const idVec3 *(__fastcall *GetOrigin)(idPhysics *, int); // ctr
  const idVec3 *v47; // r3
  idPhysics *v48; // r30
  idPhysics *v49; // r29
  int v50; // r27
  idPresentable *v51; // r28
  const idMat3 *v52; // r30
  const idVec3 *v53; // r3
  const idDeclEntityDef *entityToSpawnOnBreak; // r4
  idEntity *v55; // r30
  idPhysics *v56; // r3
  int *v57; // r3
  int v58; // r7
  int v59; // r6
  idPhysics *v60; // r3
  idPhysics *v61; // r29
  idPhysics *v62; // r28
  idPhysics *v63; // r3
  idPhysics_vtbl *v64; // r29
  const idMat3 *(__fastcall *GetAxis)(idPhysics *, int); // ctr
  int v66; // r3
  idPhysics *v67; // r3
  unsigned int v68; // r29
  idPhysics *v69; // r3
  idEntity *replacementPart; // r3
  idPhysics *v71; // r3
  idPhysics *v72; // r3
  idProp_Breakable::breakableState_t state; // r11
  char v74; // r24
  double v75; // fp13
  double v76; // fp12
  double v77; // fp11
  int v78; // r25
  int v79; // r26
  idProp_Breakable *v80; // r30
  idPhysics *v81; // r3
  __int64 v82; // r5 OVERLAPPED
  unsigned int v83; // r8
  unsigned int v84; // r9
  __int64 v85; // r7
  unsigned int v86; // r4
  idMat3 *v87; // r3
  idPhysics *v88; // r3
  idProp_Breakable_vtbl *v89; // r16
  int v90; // r3
  int v91; // r3
  idPhysics *v92; // r3
  idPhysics *v93; // r3
  int num; // r8
  int minSplinters; // r9
  idClientGame *v96; // r11
  signed int v97; // r10
  int v98; // r10
  unsigned int seed; // r9
  unsigned int v100; // r5
  int v101; // r4
  unsigned int v102; // r6
  int v103; // r10
  int v104; // r27
  signed int v105; // r10
  int v106; // r11
  unsigned int v107; // r9
  unsigned int v108; // r6
  int v109; // r5
  idEntity *v110; // r3
  idProp_Breakable *v111; // r30
  const idMat3 *v112; // r3
  idPhysics *v113; // r3
  idPhysics *v114; // r3
  idAIEventManager v115; // [sp+50h] [-160h] BYREF
  float y; // [sp+A0h] [-110h]
  float z; // [sp+A4h] [-10Ch]
  float x; // [sp+A8h] [-108h]
  float v119; // [sp+ACh] [-104h]
  float v120; // [sp+B0h] [-100h]
  idVec3 v121; // [sp+B8h] [-F8h] BYREF
  __int64 v122; // [sp+C8h] [-E8h]
  __int64 v123; // [sp+D0h] [-E0h]
  idVec3 v124[6]; // [sp+E0h] [-D0h] BYREF

  idEntity::ForceDormancy(this, dormant: false, durationMS: 10000);
  Physics = idEntity::GetPhysics(this);
  v7 = Physics->GetOrigin(this: Physics, a2: 0);
  v8 = idEntity::GetPhysics(this);
  v9 = v8->GetAxis(this: v8, a2: 0);
  v10 = idEntity::GetPhysics(this);
  v10->GetAngularVelocity(this: (idPhysics *)&v121, result: (idVec3 *)v10, a3: 0);
  if ( (unsigned __int8)Get_idCombatStage_useRelaxedChatterVO(ptr: (unsigned __int8 *)this) != 0 )
    return;
  if ( idEntity::IsBound(this) )
  {
    BindMaster = idEntity::GetBindMaster(this);
    if ( (unsigned __int8)idClass::IsType(this: BindMaster, superclass: &idActor::Type) != 0 )
    {
      v12 = idEntity::GetBindMaster(this);
      idEventReceiver::PostEventMS(this: v12, ev: &EV_Carry_ShowHands, time: 600);
    }
  }
  sound_break = this->sound_break;
  flags = (char)this->flags;
  this->smokeStartTime = 0;
  *(_BYTE *)&this->flags = flags & 0xFD;
  started = idEntity::StartSoundShader(
              this,
              channel: SND_CHANNEL_ANY,
              shader: sound_break,
              soundShaderFlags: (soundShaderFlags_t)0,
              peerMask: 0xFFu);
  v16 = idEntity::GetPhysics(this);
  v17 = (float)(v16->GetMass(this: v16, a2: -1) * (float)15.0);
  this->RemoveSelf(this, a2: started);
  if ( this->explodes )
  {
    breakable = this->breakable;
    v18 = 116;
    this->state = EXPLODING;
    if ( breakable != nullptr )
    {
      v20 = idEntity::GetPhysics(this);
      v21 = idEntity::GetPhysics(this);
      v22 = idEntity::GetPhysics(this);
      LODWORD(v23) = started;
      HIDWORD(v23) = v20->__vftable;
      *(_QWORD *)&v115.eventList.list = v23;
      v24 = v22;
      v25 = v20;
      removeDelay = this->removeDelay;
      p_breakableManager = &gameLocal->breakableManager;
      v28 = (float)((float)v23 * (float)0.001);
      v29 = (const idVec3 *)(*(int (__fastcall **)(idPhysics *, _DWORD))(HIDWORD(v23) + 64))(a1: v25, a2: 0);
      v30 = v21->GetAxis(this: v21, a2: 0);
      v31 = v24->GetOrigin(this: v24, a2: 0);
      idBreakableManager::UseBreakable(
        this: p_breakableManager,
        decl: this->breakable,
        origin: v31,
        axis: v30,
        dir: dir->mat,
        pos: v29,
        impulse: (float)((float)v17 * (float)30.0),
        fadeTime: (float)((float)removeDelay + (float)v28));
    }
    explosionProjectile = this->explosionProjectile;
    if ( explosionProjectile != nullptr )
    {
      v33 = (idProjectile *)gameLocal->SpawnEntityFromDef(
                              this: gameLocal,
                              a2: explosionProjectile,
                              a3: -1,
                              a4: -1,
                              a5: -1);
      v34 = idProjectile::CastTo(c: v33);
      if ( v34 != nullptr )
      {
        v35 = idEntity::GetPhysics(this);
        v36 = v35->GetOrigin(this: v35, a2: 0);
        idEntity::SetOrigin(this: v34, org: v36);
        v34->SetAxis(this: v34, a2: &mat3_identity);
        presentable = v34->presentable;
        if ( presentable != nullptr )
        {
          v38 = (int)presentable->GetProjectileInterface(this: presentable);
          if ( v38 != 0 )
            *(_BYTE *)(v38 + 1316) = 1;
        }
        v34->Explode(this: v34, a2: nullptr, a3: nullptr);
LABEL_18:
        if ( this->explosionEventDecl != nullptr )
        {
          v42 = idEntity::GetPhysics(this);
          GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
          v44 = v42;
          GetOrigin = v42->GetOrigin;
          p_aiEventManager = &gameLocal->aiEventManager;
          v47 = GetOrigin(this: v44, a2: 0);
          idAIEventManager::AddEvent(
            this: &v115,
            result: p_aiEventManager,
            eventDecl: this->explosionEventDecl,
            curTime: GameMs,
            originator: this,
            instigator: activator,
            origin: v47,
            delay: 400);
        }
        this->state = EXPLODING;
        goto LABEL_21;
      }
      idLib::Error(fmt: "idProp_Breakable '%s' has an invalid explosionEntity specified", this->name.data);
    }
    if ( this->explodeDamage != nullptr )
    {
      v39 = idEntity::GetPhysics(this);
      explodeDamage = this->explodeDamage;
      v41 = v39->GetOrigin(this: v39, a2: 0);
      idGameLocal::RadiusDamage(
        this: gameLocal,
        origin: v41,
        inflictor: this,
        attacker: this,
        damageDef: explodeDamage,
        dmgPower: 1.0);
    }
    goto LABEL_18;
  }
  v18 = 115;
  this->state = DAMAGED|EXPLODING;
LABEL_21:
  v48 = idEntity::GetPhysics(this);
  v49 = idEntity::GetPhysics(this);
  v50 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  if ( this->presentable == nullptr )
    idEntity::InitPresentableInternal(this);
  v51 = this->presentable;
  v52 = v48->GetAxis(this: v48, a2: 0);
  v53 = v49->GetOrigin(this: v49, a2: 0);
  idFXManager::StartFX(this: &v51->fxManager, org: v53, axis: v52, time: v50, startCondition: v18);
  entityToSpawnOnBreak = this->entityToSpawnOnBreak;
  if ( entityToSpawnOnBreak != nullptr )
  {
    v55 = gameLocal->SpawnEntityFromDef(this: gameLocal, a2: entityToSpawnOnBreak, a3: -1, a4: -1, a5: -1);
    if ( v55 != nullptr )
    {
      v56 = idEntity::GetPhysics(this);
      v57 = (int *)v56->GetOrigin(this: v56, a2: 0);
      v58 = v57[1];
      v59 = v57[2];
      v115.eventHash.hashSize = *v57;
      v115.eventHash.indexSize = v58;
      v115.eventHash.granularity = v59;
      v60 = idEntity::GetPhysics(this: v55);
      v60->SetOrigin(this: v60, a2: (const idVec3 *)&v115.eventHash.hashSize, a3: -1);
      v61 = idEntity::GetPhysics(this);
      v62 = idEntity::GetPhysics(this: v55);
      v63 = v61;
      GetAxis = v61->GetAxis;
      v64 = v62->__vftable;
      v66 = (int)GetAxis(this: v63, a2: 0);
      v64->SetAxis(this: v62, a2: (const idMat3 *)v66, a3: -1);
      v67 = idEntity::GetPhysics(this: v55);
      v68 = v67->GetContents(this: v67, a2: -1) & 0xFFFC5BDE;
      v69 = idEntity::GetPhysics(this: v55);
      v69->SetContents(this: v69, a2: v68 | 0x1000, a3: -1);
    }
  }
  this->ActivateTargets(this, a2: activator);
  replacementPart = this->replacementPart;
  if ( replacementPart != nullptr )
  {
    replacementPart->Show(this: replacementPart);
    v71 = idEntity::GetPhysics(this: this->replacementPart);
    v71->SetOrigin(this: v71, a2: v7, a3: -1);
    v72 = idEntity::GetPhysics(this: this->replacementPart);
    v72->SetAxis(this: v72, a2: v9, a3: -1);
    idEntity::UpdateVisuals(this: this->replacementPart);
    *(_BYTE *)&this->replacementPart->flags &= ~2u;
  }
  if ( this->parts.num != 0 )
  {
    if ( this->spawnParts.num > 0 )
    {
      idVec3::ToMat3(this: (idVec3 *)&v115.eventPools, result: dir);
      state = this->state;
      v74 = 0;
      v75 = (float)(dir->mat[0].x * (float)v17);
      v76 = (float)(dir->mat[0].y * (float)v17);
      v77 = (float)(dir->mat[0].z * (float)v17);
      *(float *)&v115.eventList.size = dir->mat[0].x * (float)v17;
      *(float *)&v115.eventList.granularity = v76;
      *(float *)&v115.eventHash.hash = v77;
      if ( state == EXPLODING )
      {
        v74 = 1;
        *(float *)&v115.eventList.size = (float)v75 * (float)20.0;
        *(float *)&v115.eventList.granularity = (float)v76 * (float)20.0;
        *(float *)&v115.eventHash.hash = (float)v77 * (float)20.0;
      }
      v78 = 0;
      if ( this->spawnParts.num > 0 )
      {
        v79 = 0;
        do
        {
          v80 = (idProp_Breakable *)this->spawnParts.list[v79];
          v80->Show(this: v80);
          v81 = idEntity::GetPhysics(this);
          v80->ActivatePhysics(this: v80, a2: v81->physicsId);
          if ( (unsigned __int8)idProp_Breakable::IsTypeOf(c: v80) != 0 )
          {
            idProp_Breakable::StartFromBrokenProp(
              this: v80,
              origin: v7,
              axis: v9,
              hitAxis: (const idMat3 *)&v115.eventPools,
              angularVelocity: &v121);
            if ( v74 != 0 )
            {
              v83 = 1664525 * clientGame->random.seed + 1013904223;
              clientGame->random.seed = v83;
              LODWORD(v82) = (v83 >> 10) & 0x7FFF;
              *(_QWORD *)&v115.eventList.list = v82;
              *(float *)&v115.eventHash.lookupMask = (float)((float)v82 * (float)0.000061037019) - (float)1.0;
              v84 = 1664525 * clientGame->random.seed + 1013904223;
              clientGame->random.seed = v84;
              HIDWORD(v85) = (v84 >> 10) & 0x7FFF;
              v123 = *(__int64 *)((char *)&v82 - 4);
              *(float *)&v115.eventHash.memTag = (float)((float)*(__int64 *)((char *)&v82 - 4) * (float)0.000061037019)
                                               - (float)1.0;
              v86 = 1664525 * clientGame->random.seed;
              clientGame->random.seed = v86 + 1013904223;
              LODWORD(v85) = ((v86 + 1013904223) >> 10) & 0x7FFF;
              v122 = v85;
              *(float *)&v115.receivers.list = (float)((float)v85 * (float)0.000061037019) - (float)1.0;
              idVec3::NormalizeFast(this: (idVec3 *)&v115.eventHash.lookupMask);
              v87 = idVec3::ToMat3(this: v124, result: (idMat3 *)&v115.eventHash.lookupMask);
              *(float *)&v115.eventPools.list = v87->mat[0].x;
              *(float *)&v115.eventPools.num = v87->mat[0].y;
              *(float *)&v115.eventPools.size = v87->mat[0].z;
              *(float *)&v115.eventPools.granularity = v87->mat[1].x;
              y = v87->mat[1].y;
              z = v87->mat[1].z;
              x = v87->mat[2].x;
              v119 = v87->mat[2].y;
              v120 = v87->mat[2].z;
            }
            v88 = idEntity::GetPhysics(this: v80);
            v89 = v80->__vftable;
            v90 = (int)v88->GetOrigin(this: v88, a2: 0);
            v89->ApplyImpulseFromEntity(
              this: v80,
              a2: activator,
              a3: 0,
              a4: (const idVec3 *)v90,
              a5: (const idVec3 *)&v115.eventList.size);
            if ( this->delaySoundAfterBreak != 0.0 )
            {
              v91 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
              v115.eventHash.indexSize = (int)(float)(this->delaySoundAfterBreak * 1000.0);
              v80->nextBounceTime = v115.eventHash.indexSize + v91;
            }
          }
          else
          {
            v92 = idEntity::GetPhysics(this: v80);
            v92->SetOrigin(this: v92, a2: v7, a3: -1);
            v93 = idEntity::GetPhysics(this: v80);
            v93->SetAxis(this: v93, a2: v9, a3: -1);
            idEntity::UpdateVisuals(this: v80);
          }
          ++v78;
          ++v79;
        }
        while ( v78 < this->spawnParts.num );
      }
    }
    num = this->splinters.num;
    if ( num != 0 )
    {
      minSplinters = this->minSplinters;
      v96 = clientGame;
      v97 = this->maxSplinters - minSplinters;
      if ( this->maxSplinters == minSplinters )
      {
        v98 = 0;
      }
      else
      {
        seed = clientGame->random.seed;
        __twllei(v97, 0);
        v100 = 1664525 * seed + 1013904223;
        clientGame->random.seed = v100;
        v96 = clientGame;
        v101 = (v100 >> 10) & 0x7FFF;
        v102 = v97 & ~(__ROL4__(v101, 1) - 1);
        v98 = v101 % v97;
        __twlgei(v102, 0xFFFFFFFF);
      }
      v103 = v98 + num;
      if ( v103 > 0 )
      {
        v104 = v103;
        while ( 1 )
        {
          v105 = this->splinters.num;
          if ( v105 != 0 )
          {
            v107 = v96->random.seed;
            __twllei(v105, 0);
            v108 = 1664525 * v107 + 1013904223;
            v96->random.seed = v108;
            v109 = (v108 >> 10) & 0x7FFF;
            v106 = v109 % v105;
            __twlgei(v105 & ~(__ROL4__(v109, 1) - 1), 0xFFFFFFFF);
          }
          else
          {
            v106 = 0;
          }
          v110 = gameLocal->SpawnEntityFromDef(this: gameLocal, a2: this->splinters.list[v106], a3: -1, a4: -1, a5: -1);
          v111 = (idProp_Breakable *)v110;
          if ( v110 != nullptr )
          {
            if ( (unsigned __int8)idProp_Breakable::IsTypeOf(c: v110) != 0 )
            {
              v112 = idVec3::ToMat3(this: v124, result: dir);
              idProp_Breakable::StartFromBrokenProp(
                this: v111,
                origin: v7,
                axis: v9,
                hitAxis: v112,
                angularVelocity: &v121);
            }
            else
            {
              v113 = idEntity::GetPhysics(this: v111);
              v113->SetOrigin(this: v113, a2: v7, a3: -1);
              v114 = idEntity::GetPhysics(this: v111);
              v114->SetAxis(this: v114, a2: v9, a3: -1);
            }
          }
          if ( --v104 == 0 )
            break;
          v96 = clientGame;
        }
      }
    }
  }
}


// ========================================================================
// ?RemoveSelf@idProp_Breakable@@MAAXH@Z
// EA  : 0x82CA1D98
// RVA : 0x00CA1D98
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void __fastcall idProp_Breakable::RemoveSelf(idProp_Breakable *this, int msecDelay)
{
  double fadeTime; // fp13
  idPhysics *Physics; // r3
  idPhysics *v6; // r3
  idPhysics *v7; // r3
  float v8; // [sp+50h] [-30h] BYREF
  float v9; // [sp+54h] [-2Ch] BYREF
  int v10; // [sp+58h] [-28h] BYREF
  int v11; // [sp+5Ch] [-24h]

  fadeTime = this->fadeTime;
  if ( fadeTime <= 0.0 )
  {
    this->Hide_2(this);
    v11 = (int)(float)(this->removeDelay * (float)1000.0);
    idEventReceiver::PostEventMS(this, ev: &EV_Remove, time: v11 + msecDelay);
  }
  else
  {
    v8 = 0.0;
    v9 = 1.0;
    v11 = (int)(float)((float)fadeTime * (float)1000.0);
    v10 = v11;
    idProp_Moveable::Fade(this, from: &v9, to: &v8, time: &v10);
    idEventReceiver::PostEventSec(this, ev: &EV_Remove, time: this->fadeTime);
  }
  Physics = idEntity::GetPhysics(this);
  this->DeactivatePhysics(this, a2: Physics->physicsId);
  v6 = idEntity::GetPhysics(this);
  v6->SetContents(this: v6, a2: 0, a3: -1);
  v7 = idEntity::GetPhysics(this);
  v7->SetClipMask(this: v7, a2: 0, a3: -1);
}


// ========================================================================
// ?Event_BreakIt@idProp_Breakable@@IAA?AVeventVoid@@XZ
// EA  : 0x82CA1ED8
// RVA : 0x00CA1ED8
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

idProp_Breakable *__fastcall idProp_Breakable::Event_BreakIt(idProp_Breakable *this, idProp_Breakable *result)
{
  idMat3 var20; // [sp+50h] [-20h] BYREF

  var20.mat[0].x = 0.0;
  var20.mat[0].y = 0.0;
  var20.mat[0].z = -1.0;
  idProp_Breakable::Break(this: result, activator: result, dir: &var20);
  return this;
}


// ========================================================================
// ?OnActivate@idProp_Breakable@@MAAXPAVidEntity@@@Z
// EA  : 0x82CA1F30
// RVA : 0x00CA1F30
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void __fastcall idProp_Breakable::OnActivate(idProp_Breakable *this, idEntity *activator)
{
  idMat3 var20; // [sp+50h] [-20h] BYREF

  if ( this->breakFromTrigger )
  {
    var20.mat[0].x = 0.0;
    var20.mat[0].y = 0.0;
    var20.mat[0].z = -1.0;
    idProp_Breakable::Break(this, activator, dir: &var20);
  }
  else
  {
    ((void (__fastcall *)(idPhysics_RigidBody *, idEntity *))this->physicsObj.Activate)(
      a1: &this->physicsObj,
      a2: activator);
  }
}


// ========================================================================
// ?Hide@idProp_VehicleJump@@UAAXXZ
// EA  : 0x82CA1FA0
// RVA : 0x00CA1FA0
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void __fastcall idProp_VehicleJump::Hide(idProp_VehicleJump *this)
{
  idPhysics *Physics; // r3

  if ( this->sound_spawn != nullptr )
    idEntity::StopSound(this, channel: SND_CHANNEL_BODY2, peerMask: 0xFFu);
  idEntity::BecomeInactive(this, flags: 7);
  idEntity::Hide(this);
  *((_BYTE *)&this->physicsObj.fl + 4) &= 0x3Fu;
  Physics = idEntity::GetPhysics(this);
  Physics->UnlinkClip(this: Physics);
  idEntity::BecomeInactive(this, flags: 2);
}


// ========================================================================
// ?Pickup@idProp_VehiclePickup@@UAAXPAVidEntity@@_N@Z
// EA  : 0x82CA2028
// RVA : 0x00CA2028
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void __fastcall idProp_VehiclePickup::Pickup(idProp_VehiclePickup *this, idVehicle_Car *other, bool addItem)
{
  idVehicle_Car *v6; // r3
  unsigned __int8 *v7; // r30
  idPhysics *Physics; // r3
  const idSoundShader *sound_pickup; // r5
  idPlayer *v10; // r3

  v6 = idVehicle_Car::CastTo(c: other);
  v7 = (unsigned __int8 *)v6;
  if ( v6 != nullptr )
  {
    idVehicle::PlayerIsOccupant(this: v6);
    if ( ((double (__fastcall *)(unsigned __int8 *))*(_DWORD *)(*(_DWORD *)v7 + 704))(a1: v7) <= 0.0
      || (unsigned __int8)Get_idCombatStage_useRelaxedChatterVO(ptr: v7) != 0 )
    {
      return;
    }
  }
  else
  {
    v10 = idPlayer::CastTo(c: (idPlayer *)other);
    if ( !this->allowPlayerPickup || v10 == nullptr )
      return;
  }
  Physics = idEntity::GetPhysics(this);
  Physics->SetContents(this: Physics, a2: 0, a3: -1);
  if ( v7 != nullptr && addItem )
    idProp_VehiclePickup::HandleInventory(this, car: (idVehicle_Car *)v7);
  sound_pickup = this->sound_pickup;
  if ( sound_pickup != nullptr && this->shouldPlayPickupSound )
    idEntity::StartSoundShader(
      this: other,
      channel: SND_CHANNEL_CRASH,
      shader: sound_pickup,
      soundShaderFlags: (soundShaderFlags_t)0,
      peerMask: 0);
  idProp_Moveable::Pickup(this, entity: other, addItem);
  this->tractored = false;
}


// ========================================================================
// ?Event_Touch@idProp_VehicleArmor@@AAA?AVeventVoid@@PAVidEntity@@H@Z
// EA  : 0x82CA2140
// RVA : 0x00CA2140
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

idProp_VehicleArmor *__fastcall idProp_VehicleArmor::Event_Touch(
        idProp_VehicleArmor *this,
        eventVoid *result,
        idVehicle_Car *other,
        int clipModelId)
{
  idVehicle_Car *v7; // r3
  idEntity *v8; // r31
  int v9; // r25
  int v10; // r27
  idAttachmentCollection *v11; // r3
  idAttachment *v12; // r3
  idInventoryItem *item; // r30
  int v14; // r11
  const idDeclInventory *decl; // r29
  idPresentable *presentable; // r28
  int count; // r29
  idInventoryCollection *v18; // r3

  v7 = idVehicle_Car::CastTo(c: other);
  v8 = v7;
  if ( v7 != nullptr && *(_DWORD *)&result[5396] != 0 )
  {
    v9 = 0;
    v10 = 0;
    if ( v7->GetAttachments_2(this: v7)->attachments.num > 0 )
    {
      while ( 1 )
      {
        v11 = v8->GetAttachments_2(this: v8);
        v12 = idAttachmentCollection::ForIndex(this: v11, index: v10);
        item = v12->item;
        if ( item != nullptr )
        {
          v14 = *(_DWORD *)&result[5396];
          decl = item->decl;
          if ( decl->equipSlot == *(_DWORD *)(v14 + 352) )
            break;
        }
        if ( ++v10 >= v8->GetAttachments_2(this: v8)->attachments.num )
          goto LABEL_13;
      }
      if ( decl->count >= *(_DWORD *)(v14 + 336) )
      {
        presentable = v8->presentable;
        if ( presentable == nullptr )
        {
          idEntity::InitPresentableInternal(this: v8);
          presentable = v8->presentable;
        }
        count = decl->count;
        v18 = v8->GetInventory_2(this: v8);
        idInventoryCollection::SetItemCount(this: v18, owner: presentable, item, count, forceCount: true);
      }
      else
      {
        v8->InventoryRemoved(this: v8, a2: v12->item);
        v9 = 1;
      }
    }
LABEL_13:
    if ( v10 == v8->GetAttachments_2(this: v8)->attachments.num )
      v9 = 1;
    (*(void (__fastcall **)(eventVoid *, idVehicle_Car *, int))(*(_DWORD *)result + 680))(a1: result, a2: other, a3: v9);
  }
  return this;
}


// ========================================================================
// ?Think@idProp_JobPosting@@UAAXXZ
// EA  : 0x82CA22C8
// RVA : 0x00CA22C8
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void __fastcall idProp_JobPosting::Think(idProp_JobPosting *this)
{
  idPlayer *DebugPlayer; // r27
  char v3; // r24
  int v4; // r28
  int v5; // r29
  const idDeclJob **list; // r11
  const idDeclJob *v7; // r31
  idJob *JobByDecl; // r3
  idPresentable *presentable; // r11
  char v10; // r10
  idRenderModel *v11; // r10
  idRenderModel *model; // r10

  idAnimatedEntity::Think(this);
  if ( !this->shouldCheckPlayer )
    goto LABEL_23;
  DebugPlayer = idGameLocal::GetDebugPlayer(this: gameLocal);
  v3 = 0;
  if ( DebugPlayer != nullptr )
  {
    v4 = 0;
    if ( this->jobDeclList.num > 0 )
    {
      v5 = 0;
      while ( 1 )
      {
        list = this->jobDeclList.list;
        v7 = list[v5];
        if ( v7 != nullptr )
        {
          JobByDecl = idJobManager::FindJobByDecl(this: &DebugPlayer->jobManager, jobDecl: list[v5]);
          if ( (JobByDecl == nullptr || JobByDecl->status <= (unsigned int)JOBSTATUS_FAILED)
            && idJobManager::IsJobAvailable(this: &DebugPlayer->jobManager, jobDecl: v7) )
          {
            break;
          }
        }
        ++v4;
        ++v5;
        if ( v4 >= this->jobDeclList.num )
          goto LABEL_12;
      }
      v3 = 1;
    }
  }
LABEL_12:
  presentable = this->presentable;
  this->shouldCheckPlayer = false;
  if ( presentable == nullptr || (v10 = 1, presentable->model == nullptr) )
    v10 = 0;
  if ( v10 == 0 )
    goto LABEL_23;
  if ( v3 == 0 )
  {
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      presentable = this->presentable;
    }
    model = presentable->model;
    presentable->highlightColor = HIGHLIGHT_COLOR_NONE;
    model->g.highlightColor = HIGHLIGHT_COLOR_NONE;
LABEL_23:
    idEntity::BecomeInactive(this, flags: 1);
    return;
  }
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    presentable = this->presentable;
  }
  v11 = presentable->model;
  presentable->highlightColor = HIGHLIGHT_COLOR_USE;
  v11->g.highlightColor = HIGHLIGHT_COLOR_USE;
  idEntity::BecomeInactive(this, flags: 1);
}


// ========================================================================
// ?Spawn@idProp_PlayerInteraction@@QAAXXZ
// EA  : 0x82CA24A0
// RVA : 0x00CA24A0
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void __fastcall idProp_PlayerInteraction::Spawn(idProp_PlayerInteraction *this)
{
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idPresentable *presentable; // r11
  const idTreeAnimator *v4; // r29
  idGameTimeManager *v5; // r3
  const idAnimStack *v6; // r3
  __int64 v7; // r8
  int v8; // [sp+54h] [-9Ch]
  blendParms_t v9; // [sp+60h] [-90h] BYREF
  idAnimatorParms_Base v10; // [sp+80h] [-70h] BYREF

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
    gameAnimTools->VerifyStrongAliasRefs(this: gameAnimTools, a2: v4, a3: &this->idleAnimAlias, a4: this->name.data);
    gameAnimTools->VerifyStrongAliasRefs(this: gameAnimTools, a2: v4, a3: &this->useOnAnimAlias, a4: this->name.data);
    gameAnimTools->VerifyStrongAliasRefs(this: gameAnimTools, a2: v4, a3: &this->useOffAnimAlias, a4: this->name.data);
    idAnimatedEntity::UpdateAnimation(this, forceNonDeferredBlend: false);
    v10.animStack = this->GetAnimStack_2(this);
    idStr::idStr(this: &v10.name, text: "all");
    memset(&v10.originBlend, 0, 12);
    v10.blendOp = BOP_LERP;
    v10.alpha = 1.0;
    v5 = gameLocal->GetGameTimeManager(this: gameLocal);
    idAnimator_Base::Init(this: &this->channelAnimator, gametimeManager: v5, parms: &v10);
    blendParms_t::blendParms_t(this: &v9);
    v8 = (int)(float)((float)__SPAIR64__(
                               &off_82040000,
                               idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED))
                    + (float)500.0);
    v6 = this->GetAnimStack_2(this);
    LODWORD(v7) = &v9;
    if ( (unsigned __int8)idAnimator_Channel::CycleAnim(
                            this: &this->channelAnimator,
                            stack: v6,
                            ah: &this->idleAnimAlias,
                            curTime: v8,
                            rateScale: 1.0,
                            leafStarted: v7,
                            a7: nullptr) != 0 )
      this->nextIdleTime = -1;
    idEntity::BecomeActive(this, flags: 5);
    idStr::FreeData(this: &v10.name);
  }
}


// ========================================================================
// __unwind$501450
// EA  : 0x82CA2688
// RVA : 0x00CA2688
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void _unwind_501450()
{
  int v0; // r12

  idAnimatorParms_EndAdditiveChannels::~idAnimatorParms_EndAdditiveChannels(this: (vaiAction_t::vehicleCam_t *)(v0 - 240 + 128));
}


// ========================================================================
// ??0idProp_MissionPin@@QAA@XZ
// EA  : 0x82CA26B8
// RVA : 0x00CA26B8
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

idProp_MissionPin *__fastcall idProp_MissionPin::idProp_MissionPin(idProp_MissionPin *this)
{
  idUse::idUse(this);
  this->sideChapter = nullptr;
  this->__vftable = (idProp_MissionPin_vtbl *)&idProp_MissionPin::`vftable';
  this->completedModel = nullptr;
  this->fromLayers.allocedAndFlag = 20;
  this->fromLayers.data = this->fromLayers.baseBuffer;
  this->fromLayers.len = 0;
  this->fromLayers.baseBuffer[0] = 0;
  this->spawn.spawnPoint.allocedAndFlag = 20;
  this->spawn.spawnPoint.len = 0;
  this->spawn.spawnPoint.data = this->spawn.spawnPoint.baseBuffer;
  this->spawn.spawnPoint.baseBuffer[0] = 0;
  this->spawn.layers.data = this->spawn.layers.baseBuffer;
  this->spawn.layers.allocedAndFlag = 20;
  this->spawn.layers.len = 0;
  this->spawn.layers.baseBuffer[0] = 0;
  this->spawn.mapName.allocedAndFlag = 20;
  this->spawn.mapName.data = this->spawn.mapName.baseBuffer;
  this->spawn.mapName.len = 0;
  this->spawn.mapName.baseBuffer[0] = 0;
  idStr::operator=(this: &this->spawn.spawnPoint, text: "player_start");
  return this;
}


// ========================================================================
// __unwind$501544
// EA  : 0x82CA2784
// RVA : 0x00CA2784
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void _unwind_501544()
{
  int v0; // r12

  idUse::~idUse(this: *(idUse **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$501545
// EA  : 0x82CA27AC
// RVA : 0x00CA27AC
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void _unwind_501545()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 872));
}


// ========================================================================
// __unwind$501546
// EA  : 0x82CA27D8
// RVA : 0x00CA27D8
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void _unwind_501546()
{
  int v0; // r12

  keyBindings_t::~keyBindings_t(this: (testReportField_t *)(*(_DWORD *)(v0 - 112 + 132) + 904));
}


// ========================================================================
// ?Initialize@idProp_MissionPin@@QAAXPBVidDeclChapter@@HHAAVidStr@@@Z
// EA  : 0x82CA2930
// RVA : 0x00CA2930
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void __fastcall idProp_MissionPin::Initialize(
        idProp_MissionPin *this,
        const idDeclChapter *chapter,
        int variationID,
        int partIndex,
        idStr *layers)
{
  int len; // r30
  idChapterVariation *list; // r11
  const idDeclChapter *sideChapter; // r28
  size_t v11; // r30
  idChapterVariation *v12; // r9
  int id; // r4

  this->fromVariationID = variationID;
  this->fromPartIndex = partIndex;
  len = layers->len;
  idStr::EnsureAlloced(this: &this->fromLayers, amount: layers->len + 1, keepold: false, geometricGrowth: false);
  memcpy(Dst: this->fromLayers.data, Src: layers->data, Size: len);
  this->fromLayers.data[len] = 0;
  this->fromLayers.len = len;
  this->sideChapter = chapter;
  if ( chapter->variations.num > 0 )
  {
    list = chapter->variations.list;
    if ( list->parts.num > 0 )
    {
      idChapterPart::GetLayersParsed(this: list->parts.list, retLayers: &this->spawn.layers);
      sideChapter = this->sideChapter;
      v11 = sideChapter->sideMap.len;
      idStr::EnsureAlloced(this: &this->spawn.mapName, amount: v11 + 1, keepold: false, geometricGrowth: false);
      memcpy(Dst: this->spawn.mapName.data, Src: sideChapter->sideMap.data, Size: v11);
      this->spawn.mapName.data[v11] = 0;
      this->spawn.mapName.len = v11;
      idStr::operator=(this: &this->spawn.spawnPoint, text: "player_spawn");
      v12 = chapter->variations.list;
      id = v12->id;
      this->spawn.varID = v12->id;
      idProp_MissionPin::CheckModel(this, variationID: id);
    }
  }
}


// ========================================================================
// ?SaveGame@idSaveGameUtility@@QAA_NXZ
// EA  : 0x82CA2BD8
// RVA : 0x00CA2BD8
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

int __fastcall idSaveGameUtility::SaveGame(idSaveGameUtility *this)
{
  int value; // r10
  idEntityPtr<idEntity> *p_playerSpawnSpot; // r27
  idGameLocal *v4; // r3
  idPlayer::tensionType_t currentPlayerTension; // r31
  int v6; // r30
  idPlayer *Player; // r3
  idEntity *v8; // r3

  if ( this->saveGameWhenUsed == NEVER )
    return 0;
  if ( this->hasSavedGame )
    return 0;
  if ( g_ignoreSaveGame.valueInteger != 0 )
    return 0;
  value = this->playerSpawnSpot.spawnId.value;
  p_playerSpawnSpot = &this->playerSpawnSpot;
  v4 = gameLocal;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] != value >> 13 )
    return 0;
  if ( !this->ignoreTension )
  {
    currentPlayerTension = PLAYER_TENSION_NONE;
    v6 = 0;
    while ( 1 )
    {
      Player = idGameLocal::GetPlayer(this: v4, i: v6);
      if ( Player != nullptr && currentPlayerTension <= Player->currentPlayerTension )
        currentPlayerTension = Player->currentPlayerTension;
      if ( ++v6 >= 6 )
        break;
      v4 = gameLocal;
    }
    if ( currentPlayerTension > this->maxTension )
      return 0;
  }
  this->hasSavedGame = true;
  v8 = idEntityPtr<idEntity const>::operator->(this: p_playerSpawnSpot);
  idGameLocal::SetSpawnSpotOverride(this: gameLocal, spawnSpot: v8->name.data);
  gameLocal->SaveGame(this: gameLocal, a2: "autosave", a3: true, a4: false);
  return 1;
}


// ========================================================================
// ??0idCombiner@@QAA@XZ
// EA  : 0x82CA2CF8
// RVA : 0x00CA2CF8
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

idCombiner *__fastcall idCombiner::idCombiner(idCombiner *this)
{
  idUse::idUse(this);
  this->__vftable = (idCombiner_vtbl *)&idCombiner::`vftable';
  this->neededItems.list = nullptr;
  this->neededItems.granularity = 0;
  this->neededItems.memTag = 5;
  this->neededItems.listStatic = 0;
  this->neededItems.size = 0;
  this->neededItems.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->neededItems);
  this->neededItemsDecl.list = nullptr;
  this->neededItemsDecl.granularity = 0;
  this->neededItemsDecl.memTag = 5;
  this->neededItemsDecl.listStatic = 0;
  this->neededItemsDecl.size = 0;
  this->neededItemsDecl.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->neededItemsDecl);
  this->onActivate.list = nullptr;
  this->onActivate.granularity = 0;
  this->onActivate.memTag = 5;
  this->onActivate.listStatic = 0;
  this->onActivate.size = 0;
  this->onActivate.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->onActivate);
  this->hoverSound = nullptr;
  this->selectSound = nullptr;
  this->completeSound = nullptr;
  this->removeItemsOnCompete = true;
  this->noBlink = false;
  return this;
}


// ========================================================================
// __unwind$502974
// EA  : 0x82CA2DAC
// RVA : 0x00CA2DAC
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void _unwind_502974()
{
  int v0; // r12

  idUse::~idUse(this: *(idUse **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$502975
// EA  : 0x82CA2DD4
// RVA : 0x00CA2DD4
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void _unwind_502975()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 856));
}


// ========================================================================
// __unwind$502976
// EA  : 0x82CA2E00
// RVA : 0x00CA2E00
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void _unwind_502976()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 876));
}


// ========================================================================
// ?UpdateGui@idCombiner@@QAAXPAVidPlayer@@PAVidCrosshairCombinerInfo@@@Z
// EA  : 0x82CA2E30
// RVA : 0x00CA2E30
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void __fastcall idCombiner::UpdateGui(idCombiner *this, idPlayer *player, idCrosshairCombinerInfo *info)
{
  int v6; // r28
  int v7; // r31
  const idDeclJob *v8; // r27
  idJobManager *v9; // r3
  idJob *JobByDecl; // r3
  int num; // r11
  int v12; // r27
  int *itemState; // r31
  int v14; // r28
  const idDeclJob *v15; // r23
  idJobManager *v16; // r3
  idJob *v17; // r3

  v6 = 0;
  if ( this->neededItemsDecl.num > 0 )
  {
    v7 = 0;
    do
    {
      v8 = (const idDeclJob *)this->neededItemsDecl.list[v7];
      v9 = (idJobManager *)player->GetInventory_2(this: player);
      JobByDecl = idJobManager::FindJobByDecl(this: v9, jobDecl: v8);
      if ( JobByDecl != nullptr )
        JobByDecl->__vftable[2].dtr_idClass(this: JobByDecl);
      ++v6;
      ++v7;
    }
    while ( v6 < this->neededItemsDecl.num );
  }
  info->hovered = (_cntlzw((char *)this - (char *)idPlayer::GetFocusUsable(this: player)) & 0x20) != 0;
  num = this->neededItemsDecl.num;
  if ( num >= 5 )
    num = 5;
  v12 = 0;
  info->itemCount = num;
  if ( num > 0 )
  {
    itemState = info->itemState;
    v14 = -12 - (_DWORD)info;
    do
    {
      itemState[5] = *(_DWORD *)(*(int *)((char *)itemState + v14 + (unsigned int)this->neededItemsDecl.list) + 212);
      v15 = *(const idDeclJob **)((char *)itemState + v14 + (unsigned int)this->neededItemsDecl.list);
      v16 = (idJobManager *)player->GetInventory_2(this: player);
      v17 = idJobManager::FindJobByDecl(this: v16, jobDecl: v15);
      *itemState = v17 != nullptr && ((int (__fastcall *)(idJob *))v17->__vftable[2].dtr_idClass)(a1: v17) > 0;
      ++v12;
      ++itemState;
    }
    while ( v12 < info->itemCount );
  }
}


// ========================================================================
// ?SetBlinkOnItems@idCombiner@@QAAX_N@Z
// EA  : 0x82CA2F78
// RVA : 0x00CA2F78
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void __fastcall idCombiner::SetBlinkOnItems(idCombiner *this, bool enable)
{
  int v4; // r28
  int v5; // r31
  int value; // r9
  idEntity *v7; // r3
  idProp_CombineItem *v8; // r3
  idProp_CombineItem *v9; // r3
  bool isUsable; // r4
  idEntity *v11; // r26

  v4 = 0;
  if ( this->neededItems.num > 0 )
  {
    v5 = 0;
    do
    {
      value = this->neededItems.list[v5].spawnId.value;
      if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
      {
        v7 = gameLocal->entities.ptr[value & 0x1FFF];
        if ( v7 != nullptr )
        {
          v8 = (idProp_CombineItem *)idEntity::CastTo(c: v7);
          if ( v8 != nullptr )
          {
            v9 = idProp_CombineItem::CastTo(c: v8);
            isUsable = v9->isUsable;
            v11 = v9;
            v9->noBlink = (_cntlzw(enable) & 0x20) != 0;
            idProp_Usable::SetUsable(this: v9, b: isUsable);
            idEntity::UpdateVisuals(this: v11);
          }
        }
      }
      ++v4;
      ++v5;
    }
    while ( v4 < this->neededItems.num );
  }
}


// ========================================================================
// ?Use@idUse@@UAA_NPAVidEntity@@W4usableState_t@@@Z
// EA  : 0x82CA3038
// RVA : 0x00CA3038
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

int __fastcall idUse::Use(idUse *this, idEntity *activator, const usableState_t usable)
{
  if ( (*(_BYTE *)&this->flags & 8) == 0 || usable != USABLE_PROP )
    return 0;
  if ( (unsigned __int8)idSaveGameUtility::SaveGame(this: &this->saveGameUtility) != 0
    && this->saveGameUtility.saveGameWhenUsed == SAVE_BEFORE_TRIGGER )
  {
    idGameLocal::AddDelayedUseEntity(this: gameLocal, activator, useObject: this, usable: USABLE_PROP);
    return 1;
  }
  else
  {
    idUse::RunUse(this, activator, usable: USABLE_PROP);
    return 1;
  }
}


// ========================================================================
// ?Use@idProp_Usable@@UAA_NPAVidEntity@@W4usableState_t@@@Z
// EA  : 0x82CA30E0
// RVA : 0x00CA30E0
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

int __fastcall idProp_Usable::Use(idProp_Usable *this, idEntity *activator, __int32 usable)
{
  if ( !this->isUsable )
    return 0;
  if ( (unsigned __int8)idSaveGameUtility::SaveGame(this: &this->saveGameUtility) != 0
    && this->saveGameUtility.saveGameWhenUsed == SAVE_BEFORE_TRIGGER )
  {
    idGameLocal::AddDelayedUseEntity(this: gameLocal, activator, useObject: this, (const usableState_t)usable);
    return 1;
  }
  else
  {
    idProp_Usable::RunUse(this, activator, (usableState_t)usable);
    return 1;
  }
}


// ========================================================================
// ?Think@idProp_ContinuallyUsed@@UAAXXZ
// EA  : 0x82CA3170
// RVA : 0x00CA3170
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void __fastcall idProp_ContinuallyUsed::Think(idProp_ContinuallyUsed *this)
{
  idProp_ContinuallyUsed::useState_t enumUseState; // r11
  double v3; // fp0
  const idSoundShader *soundReset; // r5
  idPlayer *v5; // r3
  double v6; // fp0
  int num; // r10
  int v8; // r27
  int v9; // r29
  int value; // r9
  idEntity *v11; // r3
  idEntity *v12; // r30
  idEventArg *v13; // r3
  double v14; // fp8
  double v15; // fp3
  idPhysics *Physics; // r30
  idPhysics_vtbl *v17; // r31
  idMat3 *v18; // r3
  idMat3 v19; // [sp+58h] [-A8h] BYREF
  idEventArg v20[2]; // [sp+90h] [-70h] BYREF

  idAnimatedEntity::Think(this);
  enumUseState = this->enumUseState;
  if ( enumUseState == PROGRESSING )
  {
    v5 = idPlayer::CastTo(c: (idPlayer *)this->user);
    if ( this->user == nullptr || idPlayer::GetFocusEntity(this: v5) == this )
    {
      v6 = (float)((float)((float)((float)__SPAIR64__(
                                            &off_82040000,
                                            gameLocal->GetGameMsPerFrame(this: gameLocal, a2: GAMETIME_SCALED))
                                 * this->rateOfIncrease)
                         * (float)0.001)
                 + this->usedState);
      if ( v6 >= 0.0 )
      {
        if ( v6 > 1.0 )
          v6 = 1.0;
      }
      else
      {
        v6 = 0.0;
      }
      v19.mat[2].y = v6;
      HIBYTE(v19.mat[2].x) = 102;
      idEventReceiver::PostEventMS(
        this,
        ev: &EV_SetUsePercent,
        time: SLODWORD(v19.mat[2].x),
        arg1: (const idEventArg *)LODWORD(v19.mat[2].z));
      if ( this->usedState >= 1.0 && this->finishes )
      {
        idProp_Usable::PlayUseSound(this);
        num = this->triggerSuccess.num;
        v8 = 0;
        this->enumUseState = REGRESSING|PROGRESSING;
        if ( num > 0 )
        {
          v9 = 0;
          do
          {
            value = this->triggerSuccess.list[v9].spawnId.value;
            if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
            {
              v11 = gameLocal->entities.ptr[value & 0x1FFF];
              if ( v11 != nullptr )
              {
                v12 = idEntity::CastTo(c: v11);
                if ( v12 != nullptr )
                {
                  v13 = idEventArg::idEventArg(this: v20, data: this->user);
                  idEventReceiver::PostEventMS(
                    this: v12,
                    ev: &EV_Activate,
                    time: *(_DWORD *)&v13->type,
                    arg1: (const idEventArg *)LODWORD(v13->value.v[1]));
                }
              }
            }
            ++v8;
            ++v9;
          }
          while ( v8 < this->triggerSuccess.num );
        }
        idEntity::BecomeInactive(this, flags: 1);
      }
    }
    else
    {
      this->Use(this, a2: this, a3: USABLE_PROP);
    }
  }
  else if ( enumUseState == REGRESSING )
  {
    v3 = (float)-(float)((float)((float)((float)__SPAIR64__(
                                                  &off_82040000,
                                                  gameLocal->GetGameMsPerFrame(this: gameLocal, a2: GAMETIME_SCALED))
                                       * this->rateOfDecrease)
                               * (float)0.001)
                       - this->usedState);
    if ( v3 >= 0.0 )
    {
      if ( v3 > 1.0 )
        v3 = 1.0;
    }
    else
    {
      v3 = 0.0;
    }
    v19.mat[2].y = v3;
    HIBYTE(v19.mat[2].x) = 102;
    idEventReceiver::PostEventMS(
      this,
      ev: &EV_SetUsePercent,
      time: SLODWORD(v19.mat[2].x),
      arg1: (const idEventArg *)LODWORD(v19.mat[2].z));
    if ( this->usedState <= 0.0 )
    {
      idEntity::BecomeInactive(this, flags: 1);
      soundReset = this->soundReset;
      this->enumUseState = INACTIVE;
      idEntity::StartSoundShader(
        this,
        channel: SND_CHANNEL_BODY,
        shader: soundReset,
        soundShaderFlags: (soundShaderFlags_t)0,
        peerMask: 0xFFu);
    }
  }
  idMat3::ToAngles(this: &v19, result: (idAngles *)&this->spawnOrientation);
  v14 = (float)(this->useRotation.roll * this->usedState);
  v15 = (float)(v19.mat[0].y + (float)(this->useRotation.yaw * this->usedState));
  v19.mat[0].x = v19.mat[0].x + (float)(this->usedState * this->useRotation.pitch);
  v19.mat[0].y = v15;
  v19.mat[0].z = v19.mat[0].z + (float)v14;
  Physics = idEntity::GetPhysics(this);
  v17 = Physics->__vftable;
  v18 = idAngles::ToMat3(this: (idAngles *)v20, result: &v19);
  v17->SetAxis(this: Physics, a2: v18, a3: -1);
}


// ========================================================================
// ?Damage@idProp_Moveable@@UAAMPAVidEntity@@0PBVidDeclDamage@@MABVidVec3@@PAUtrace_t@@@Z
// EA  : 0x82CA34D8
// RVA : 0x00CA34D8
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

float __fastcall idProp_Moveable::Damage(
        idProp_Moveable *this,
        idEntity *inflictor,
        idEntity *attacker,
        const idDeclDamage *damageDef,
        double damageScale,
        const idVec3 *dir,
        trace_t *trace,
        float *a8)
{
  int knockBack; // r28
  double v15; // fp13
  double v16; // fp12
  idPhysics *Physics; // r3
  float *v18; // r3
  float fraction; // r11
  float x; // r10
  float y; // r9
  idPhysics *v22; // r3
  double v23; // fp1
  __int64 v24; // r5
  void (__fastcall *ApplyImpulseFromEntity)(struct idProp_Moveable *, const idEntity *, const int, const idVec3 *, const idVec3 *); // ctr
  int GameMs; // r3
  idPresentable *presentable; // r11
  int v28; // r28
  idPresentable *v29; // r29
  const idVec3 *v30; // r30
  int v31; // r27
  int v32; // r29
  int value; // r9
  idEntity *v34; // r3
  idEntity *v35; // r30
  idEventArg *v36; // r3
  idPhysics *v37; // r3
  idPhysics *v38; // r3
  idProp_Moveable_vtbl *v39; // r4
  int v40; // r3
  idPresentable *v41; // r11
  int v42; // r28
  idPresentable *v43; // r29
  const idVec3 *v44; // r30
  idDeclFX *v45; // r3
  int v46; // r5
  double v47; // fp1
  idVec3 v49; // [sp+58h] [-98h] BYREF
  float v50; // [sp+68h] [-88h] BYREF
  float v51; // [sp+6Ch] [-84h]
  float v52; // [sp+70h] [-80h]
  idEventArg v53[5]; // [sp+80h] [-70h] BYREF

  if ( this->TakesDamage(this) )
  {
    knockBack = damageDef->knockBack;
    if ( knockBack == 0 )
      knockBack = (int)(float)(idDeclDamage::DamageAmount(this: damageDef) * (float)5.0);
    if ( inflictor != nullptr && knockBack != 0 && (*(_BYTE *)&this->flags & 4) == 0 )
    {
      if ( a8 != nullptr )
      {
        v15 = a8[2];
        v16 = a8[3];
        v50 = a8[1];
        v51 = v15;
      }
      else
      {
        Physics = idEntity::GetPhysics(this);
        v18 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
        v50 = *v18;
        v51 = v18[1];
        v16 = v18[2];
      }
      fraction = trace->fraction;
      x = trace->endpos.x;
      v52 = v16;
      y = trace->endpos.y;
      v49.x = fraction;
      v49.y = x;
      v49.z = y;
      idVec3::NormalizeFast(this: &v49);
      v49.z = v49.z + (float)1.0;
      v22 = idEntity::GetPhysics(this);
      v23 = ((double (__fastcall *)(idPhysics *, int))v22->GetMass)(a1: v22, a2: -1);
      LODWORD(v24) = knockBack;
      HIDWORD(v24) = this->__vftable;
      ApplyImpulseFromEntity = this->ApplyImpulseFromEntity;
      v49.x = v49.x * (float)((float)v23 * (float)v24);
      v49.y = v49.y * (float)((float)v23 * (float)v24);
      v49.z = (float)((float)v23 * (float)v24) * v49.z;
      ApplyImpulseFromEntity(this, a2: inflictor, a3: 0, a4: (const idVec3 *)&v50, a5: &v49);
    }
    if ( (*((_BYTE *)this + 5297) & 0x80) != 0 )
    {
      if ( this->GetFXDecl(this) != nullptr )
      {
        GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        presentable = this->presentable;
        v28 = GameMs;
        if ( presentable == nullptr )
        {
          idEntity::InitPresentableInternal(this);
          presentable = this->presentable;
        }
        v29 = presentable;
        if ( presentable == nullptr )
        {
          idEntity::InitPresentableInternal(this);
          presentable = this->presentable;
        }
        v30 = (const idVec3 *)presentable;
        if ( presentable == nullptr )
        {
          idEntity::InitPresentableInternal(this);
          presentable = this->presentable;
        }
        idFXManager::StartFX(
          this: &presentable->fxManager,
          org: v30 + 10,
          axis: &v29->axis,
          time: v28,
          startCondition: 117);
      }
      v31 = 0;
      if ( this->targets.num > 0 )
      {
        v32 = 0;
        do
        {
          if ( v31 < this->targets.num
            && (value = this->targets.list[v32].spawnId.value, gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13)
            && (v34 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
          {
            v35 = idEntity::CastTo(c: v34);
          }
          else
          {
            v35 = nullptr;
          }
          if ( v35 != nullptr )
          {
            v36 = idEventArg::idEventArg(this: v53, data: attacker);
            idEventReceiver::PostEventMS(
              this: v35,
              ev: &EV_Activate,
              time: *(_DWORD *)&v36->type,
              arg1: (const idEventArg *)LODWORD(v36->value.v[1]));
          }
          ++v31;
          ++v32;
        }
        while ( v31 < this->targets.num );
      }
    }
    if ( (*((_BYTE *)this + 5297) & 0x40) != 0 )
    {
      this->Hide_2(this);
      v37 = idEntity::GetPhysics(this);
      v37->SetContents(this: v37, a2: 0, a3: -1);
      v38 = idEntity::GetPhysics(this);
      v38->SetClipMask(this: v38, a2: 0, a3: -1);
      v39 = this->__vftable;
      this->inventoryDecl = nullptr;
      if ( v39->GetFXDecl(this) != nullptr )
      {
        v40 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        v41 = this->presentable;
        v42 = v40;
        if ( v41 == nullptr )
        {
          idEntity::InitPresentableInternal(this);
          v41 = this->presentable;
        }
        v43 = v41;
        if ( v41 == nullptr )
        {
          idEntity::InitPresentableInternal(this);
          v41 = this->presentable;
        }
        v44 = (const idVec3 *)v41;
        if ( v41 == nullptr )
        {
          idEntity::InitPresentableInternal(this);
          v41 = this->presentable;
        }
        idFXManager::StartFX(this: &v41->fxManager, org: v44 + 10, axis: &v43->axis, time: v42, startCondition: 116);
        v45 = this->GetFXDecl(this);
        v46 = idDeclFX::GetMaxDuration(this: v45, startCondition: FX_NONE) + 250;
      }
      else
      {
        v46 = 0;
      }
      idEventReceiver::PostEventMS(this, ev: &EV_Remove, time: v46);
    }
  }
  v47 = 0.0;
  return *((float *)&v47 + 1);
}


// ========================================================================
// ?Use@idProp_Loot@@UAA_NPAVidEntity@@W4usableState_t@@@Z
// EA  : 0x82CA3928
// RVA : 0x00CA3928
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

int __fastcall idProp_Loot::Use(idProp_Loot *this, idPlayer *user, const usableState_t usable)
{
  char v6; // r11
  idPlayer *v7; // r3
  idPlayer *v8; // r31
  int num; // r9
  idEntity *v10; // r3
  idAI2 *v11; // r3
  idAI2 *v12; // r31
  int v13; // r3
  char v14; // r11
  idPhysics *Physics; // r29
  idPhysics *v16; // r30
  float *v17; // r29
  float *v18; // r3
  double v19; // fp10
  double v20; // fp8

  if ( !this->isUsable || (v6 = 1, (*(_BYTE *)&this->flags & 8) == 0) )
    v6 = 0;
  if ( v6 == 0 )
    return 0;
  v7 = idPlayer::CastTo(c: user);
  v8 = v7;
  if ( usable != USABLE_LOOT || v7 == nullptr || this->hasBeenLooted )
    return 0;
  idEventReceiver::PostEventMS(this, ev: &EV_Remove, time: 0);
  num = this->loot.loot.num;
  this->hasBeenLooted = true;
  if ( num <= 0 )
    idPlayer::LootItems(this: v8, ent: this, disassemble: nullptr);
  else
    idPlayer::TakeLootBox(this: v8, loot: &this->loot, lootOneItem: true);
  if ( idEntityPtr<idEntity const>::operator->(this: &this->whoDroppedMe) != nullptr )
  {
    v10 = idEntityPtr<idEntity const>::operator->(this: &this->whoDroppedMe);
    if ( (unsigned __int8)idAI2::IsTypeOf(c: v10) != 0 )
    {
      v11 = (idAI2 *)idEntityPtr<idEntity const>::operator->(this: &this->whoDroppedMe);
      v12 = idAI2::CastTo(c: v11);
      v13 = (int)v12->GetAF_2(this: v12);
      if ( *(_BYTE *)(v13 + 267) != 0 || (v14 = 0, *(_BYTE *)(v13 + 268) != 0) )
        v14 = 1;
      if ( v14 != 0 )
        Physics = &v12->GetAF_2(this: v12)->physicsObj.idPhysics_DynamicBase;
      else
        Physics = idEntity::GetPhysics(this: v12);
      v16 = idEntity::GetPhysics(this);
      v17 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
      v18 = (float *)v16->GetOrigin(this: v16, a2: 0);
      v19 = (float)(v17[1] - v18[1]);
      v20 = (float)(v17[2] - v18[2]);
      if ( (float)((float)((float)(*v17 - *v18) * (float)(*v17 - *v18))
                 + (float)((float)((float)v20 * (float)v20) + (float)((float)v19 * (float)v19))) <= (double)(float)(g_droppedLootDistance.valueFloat * g_droppedLootDistance.valueFloat)
        && v12->IsDead(this: v12)
        && (unsigned __int8)idActor::IsLootable(this: v12) != 0
        && (!v12->looted || (unsigned __int8)idActor::HasLootableItems(this: v12) != 0) )
      {
        v12->Use(this: v12, a2: user, a3: USABLE_LOOT);
      }
    }
  }
  return 1;
}


// ========================================================================
// ?Damage@idProp_Breakable@@UAAMPAVidEntity@@0PBVidDeclDamage@@MABVidVec3@@PAUtrace_t@@@Z
// EA  : 0x82CA3CB8
// RVA : 0x00CA3CB8
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

float __fastcall idProp_Breakable::Damage(
        idProp_Breakable *this,
        idWorldspawn *inflictor,
        idWorldspawn *attacker,
        const idDeclDamage *damageDef,
        double damageScale,
        const idVec3 *dir,
        trace_t *trace,
        float *a8)
{
  const idVec3 *v15; // r7
  double v16; // fp1
  const idDeclParticle *smokeParticle; // r11
  char v18; // r25
  char v19; // r24
  weaponStatsTag_t statsTag; // r11
  char v21; // r11
  bool v22; // zf
  int num; // r8
  int v24; // r10
  int v25; // r11
  double v26; // fp11
  int *delayedCount; // r10
  int *v28; // r10
  float v30[2]; // [sp+50h] [-60h] BYREF

  if ( !this->TakesDamage(this) || this->onlyMeleeDamage && (damageDef == nullptr || !damageDef->isMelee) )
    goto LABEL_2;
  smokeParticle = this->smokeParticle;
  v18 = 0;
  this->state = DAMAGED;
  v19 = 0;
  if ( smokeParticle != nullptr )
  {
    if ( this->smokeStartTime != 0 )
    {
      v19 = 1;
    }
    else
    {
      this->smokeStartTime = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      idEntity::BecomeActive(this, flags: 1);
      statsTag = this->statsTag;
      if ( (*(_DWORD *)&statsTag & 0xFC000000) != 0
        || (*(_DWORD *)&statsTag & 0x3C00000) != 0
        || (v22 = (*(_DWORD *)&statsTag & 0x3FFFFF) == 0, v21 = 1, !v22) )
      {
        v21 = 0;
      }
      if ( v21 != 0 )
      {
        v18 = 1;
        this->statsTag = gameLocal->globStats.currentTag;
      }
    }
  }
  idProp_Moveable::Damage(this, inflictor, attacker, damageDef, damageScale, dir: v15, trace, a8);
  num = this->ammoDamage.num;
  if ( num <= 0 )
    goto LABEL_20;
  v24 = 0;
  v25 = 0;
  do
  {
    if ( this->ammoDamage.list[v25] == damageDef )
      break;
    ++v24;
    ++v25;
  }
  while ( v24 < this->ammoDamage.num );
  if ( v24 != num )
  {
LABEL_20:
    if ( inflictor == nullptr )
      inflictor = gameLocal->world;
    if ( attacker == nullptr )
      attacker = gameLocal->world;
    v30[0] = idDeclDamage::DamageAmount(this: damageDef) * (float)damageScale;
    attacker->DamageFeedback(this: attacker, a2: this, a3: inflictor, a4: damageDef, a5: v30);
    if ( v30[0] != 0.0 )
    {
      v26 = (float)(this->health - v30[0]);
      this->health = this->health - v30[0];
      if ( v26 <= 0.0 || attacker == (idWorldspawn *)this && (unsigned __int8)idActor::IsTypeOf(c: inflictor) != 0 )
      {
        if ( v19 != 0 )
        {
          delayedCount = gameLocal->globStats.delayedCount;
          if ( delayedCount != nullptr )
            --*delayedCount;
        }
        idProp_Breakable::Break(this, activator: attacker, dir: (idMat3 *)trace);
        v18 = 0;
      }
    }
    if ( v18 != 0 )
    {
      v28 = gameLocal->globStats.delayedCount;
      if ( v28 != nullptr )
        ++*v28;
    }
    v16 = v30[0];
  }
  else
  {
LABEL_2:
    v16 = 0.0;
  }
  return *((float *)&v16 + 1);
}


// ========================================================================
// ?HandleTractor@idProp_VehiclePickup@@MAAXXZ
// EA  : 0x82CA3F70
// RVA : 0x00CA3F70
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void __fastcall idProp_VehiclePickup::HandleTractor(idProp_VehiclePickup *this)
{
  int value; // r10
  idGameLocal *v3; // r3
  idPhysics *Physics; // r3
  int v5; // r9
  idPhysics *v6; // r31
  idEntity *v7; // r3
  idEntity *v8; // r3
  idPhysics *v9; // r30
  float *v10; // r31
  float *v11; // r3
  double v12; // fp31
  double v13; // fp30
  double v14; // fp29
  int v15; // r9
  idEntity *v16; // r3
  idEntity *v17; // r4
  idPhysics *v18; // r31
  idPhysics *v19; // r30
  double v20; // fp29
  double v21; // fp31
  double v22; // fp30
  float *v23; // r3
  double v24; // fp8
  double v25; // fp6
  idPlayer *v26; // r27
  int v27; // r28
  double v28; // fp31
  idPlayer *Player; // r3
  idPlayer *v30; // r31
  idVehicle_Car *v31; // r3
  idVehicle_Car *v32; // r3
  idEntity *v33; // r30
  double MagnetRange; // fp30
  idPhysics *v35; // r25
  idPhysics *v36; // r30
  float *v37; // r25
  float *v38; // r3
  double v39; // fp8
  double v40; // fp0
  int v41; // r3
  idPhysics *v42; // r3
  double valueFloat; // fp0
  float v44[6]; // [sp+50h] [-70h] BYREF

  value = this->vehicle.spawnId.value;
  v3 = gameLocal;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
  {
    Physics = idEntity::GetPhysics(this);
    v5 = this->vehicle.spawnId.value;
    v6 = Physics;
    if ( gameLocal->spawnIds.ptr[v5 & 0x1FFF] == v5 >> 13 && (v7 = gameLocal->entities.ptr[v5 & 0x1FFF]) != nullptr )
      v8 = idEntity::CastTo(c: v7);
    else
      v8 = nullptr;
    v9 = idEntity::GetPhysics(this: v8);
    v10 = (float *)v6->GetOrigin(this: v6, a2: 0);
    v11 = (float *)v9->GetOrigin(this: v9, a2: 0);
    v12 = (float)(v11[1] - v10[1]);
    v13 = (float)(v11[2] - v10[2]);
    v14 = (float)(*v11 - *v10);
    if ( (float)((float)((float)(*v11 - *v10) * (float)(*v11 - *v10))
               + (float)((float)((float)v13 * (float)v13) + (float)((float)v12 * (float)v12))) >= 5625.0 )
    {
      this->vecFrac = vehicle_tractorAccel.valueFloat + this->vecFrac;
      v18 = idEntity::GetPhysics(this);
      v19 = idEntity::GetPhysics(this);
      v20 = (float)(this->vecFrac * (float)v14);
      v21 = (float)((float)v12 * this->vecFrac);
      v22 = (float)((float)v13 * this->vecFrac);
      v23 = (float *)v18->GetOrigin(this: v18, a2: 0);
      v24 = (float)(v23[2] + (float)v22);
      v25 = (float)(v23[1] + (float)v21);
      v44[0] = (float)v20 + *v23;
      v44[2] = v24;
      v44[1] = v25;
      v19->SetOrigin(this: v19, a2: (const idVec3 *)v44, a3: -1);
    }
    else
    {
      v15 = this->vehicle.spawnId.value;
      if ( gameLocal->spawnIds.ptr[v15 & 0x1FFF] == v15 >> 13
        && (v16 = gameLocal->entities.ptr[v15 & 0x1FFF]) != nullptr )
      {
        v17 = idEntity::CastTo(c: v16);
      }
      else
      {
        v17 = nullptr;
      }
      this->Pickup(this, a2: v17, a3: true);
    }
  }
  else if ( this->tractored )
  {
    idEventReceiver::PostEventMS(this, ev: &EV_Remove, time: 0);
  }
  else
  {
    v26 = nullptr;
    v27 = 0;
    v28 = 262144.0;
    while ( 1 )
    {
      Player = idGameLocal::GetPlayer(this: v3, i: v27);
      v30 = Player;
      if ( Player != nullptr && Player->GetVehicle_2(this: Player) != nullptr )
      {
        v31 = (idVehicle_Car *)v30->GetVehicle_2(this: v30);
        v32 = idVehicle_Car::CastTo(c: v31);
        v33 = v32;
        if ( v32 != nullptr )
        {
          MagnetRange = idVehicle_Car::GetMagnetRange(this: v32);
          v35 = idEntity::GetPhysics(this);
          v36 = idEntity::GetPhysics(this: v33);
          v37 = (float *)v35->GetOrigin(this: v35, a2: 0);
          v38 = (float *)v36->GetOrigin(this: v36, a2: 0);
          v39 = (float)(v38[1] - v37[1]);
          v40 = (float)((float)((float)v39 * (float)v39) + (float)((float)(*v38 - *v37) * (float)(*v38 - *v37)));
          if ( v40 < (float)((float)MagnetRange * (float)MagnetRange) && v40 < v28 )
          {
            v26 = v30;
            v28 = (float)((float)((float)v39 * (float)v39) + (float)((float)(*v38 - *v37) * (float)(*v38 - *v37)));
          }
        }
      }
      if ( ++v27 >= 6 )
        break;
      v3 = gameLocal;
    }
    if ( v26 != nullptr )
    {
      v41 = (int)v26->GetVehicle_2(this: v26);
      if ( v41 != 0 )
        this->vehicle.spawnId.value = (gameLocal->spawnIds.ptr[*(_DWORD *)(v41 + 492)] << 13) | *(_DWORD *)(v41 + 492);
      else
        this->vehicle.spawnId.value = 0x1FFF;
      v42 = idEntity::GetPhysics(this);
      v42->SetContents(this: v42, a2: 0, a3: -1);
      valueFloat = vehicle_tractorInitialRate.valueFloat;
      this->tractored = true;
      this->vecFrac = valueFloat;
    }
  }
}


// ========================================================================
// ?Respawn@idProp_VehiclePickup@@UAAXXZ
// EA  : 0x82CA4378
// RVA : 0x00CA4378
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void __fastcall idProp_VehiclePickup::Respawn(idProp_VehiclePickup *this)
{
  idProp_Moveable::Respawn(this);
  this->tractored = false;
  this->vehicle.spawnId.value = 0x1FFF;
  this->removeTime = 0;
  this->vecFrac = 0.1;
}


// ========================================================================
// ?Use@idProp_ExplosivePlunger@@UAA_NPAVidEntity@@W4usableState_t@@@Z
// EA  : 0x82CA43C8
// RVA : 0x00CA43C8
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

int __fastcall idProp_ExplosivePlunger::Use(idProp_ExplosivePlunger *this, idEntity *user, const usableState_t usable)
{
  int v5; // r27
  int v6; // r30
  int value; // r9
  idProp_Explosive *v8; // r3
  int v9; // r9
  idProp_Explosive *v10; // r3
  idProp_Explosive *v11; // r31
  idEventArg *v12; // r3
  idEventArg v14[4]; // [sp+50h] [-60h] BYREF

  if ( !this->primerReady || this->usedPrimer )
    return 0;
  v5 = 0;
  if ( this->explosivePacks.num > 0 )
  {
    v6 = 0;
    do
    {
      value = this->explosivePacks.list[v6].spawnId.value;
      if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
      {
        v8 = (idProp_Explosive *)gameLocal->entities.ptr[value & 0x1FFF];
        if ( v8 != nullptr && idProp_Explosive::CastTo(c: v8) != nullptr )
        {
          v9 = this->explosivePacks.list[v6].spawnId.value;
          if ( gameLocal->spawnIds.ptr[v9 & 0x1FFF] == v9 >> 13
            && (v10 = (idProp_Explosive *)gameLocal->entities.ptr[v9 & 0x1FFF]) != nullptr )
          {
            v11 = idProp_Explosive::CastTo(c: v10);
          }
          else
          {
            v11 = nullptr;
          }
          v12 = idEventArg::idEventArg(this: v14, data: user);
          idEventReceiver::PostEventMS(
            this: v11,
            ev: &EV_Detonate,
            time: *(_DWORD *)&v12->type,
            arg1: (const idEventArg *)LODWORD(v12->value.v[1]));
        }
      }
      ++v5;
      ++v6;
    }
    while ( v5 < this->explosivePacks.num );
  }
  this->usedPrimer = true;
  return 1;
}


// ========================================================================
// ?PrimePlunger@idProp_ExplosivePlunger@@QAAXPAVidEntity@@@Z
// EA  : 0x82CA4510
// RVA : 0x00CA4510
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void __fastcall idProp_ExplosivePlunger::PrimePlunger(idProp_ExplosivePlunger *this, idProp_Explosive *explosive)
{
  int v4; // r26
  int v5; // r27
  idGameLocal *v6; // r10
  int value; // r9
  idProp_Explosive *v8; // r3
  idProp_Explosive *v9; // r3
  int num; // r10
  int v11; // r11
  int v12; // r11
  int v13; // r29
  int v14; // r30
  idEntityPtr<idEntity> *v15; // r11
  idEntity *v16; // r3
  idEntity *v17; // r3

  if ( explosive != nullptr )
  {
    v4 = 0;
    if ( this->explosivePacks.num > 0 )
    {
      v5 = 0;
      v6 = gameLocal;
      do
      {
        value = this->explosivePacks.list[v5].spawnId.value;
        if ( v6->spawnIds.ptr[value & 0x1FFF] == value >> 13
          && (v8 = (idProp_Explosive *)v6->entities.ptr[value & 0x1FFF]) != nullptr )
        {
          v9 = idProp_Explosive::CastTo(c: v8);
          v6 = gameLocal;
        }
        else
        {
          v9 = nullptr;
        }
        if ( explosive == v9 )
        {
          num = this->explosivePacks.num;
          v11 = this->numPrimed + 1;
          this->numPrimed = v11;
          if ( v11 == num && (v12 = this->activateList.num, v13 = 0, this->primerReady = true, v12 > 0) )
          {
            v6 = gameLocal;
            v14 = 0;
            do
            {
              v15 = &this->activateList.list[v14];
              if ( v6->spawnIds.ptr[v15->spawnId.value & 0x1FFF] == v15->spawnId.value >> 13 )
              {
                v16 = v6->entities.ptr[v15->spawnId.value & 0x1FFF];
                if ( v16 != nullptr )
                  v17 = idEntity::CastTo(c: v16);
                else
                  v17 = nullptr;
                idEntity::Activate(this: v17, activator: this);
                v6 = gameLocal;
              }
              ++v13;
              ++v14;
            }
            while ( v13 < this->activateList.num );
          }
          else
          {
            v6 = gameLocal;
          }
        }
        ++v4;
        ++v5;
      }
      while ( v4 < this->explosivePacks.num );
    }
  }
}


// ========================================================================
// ?StateOn@idProp_Explosive@@IAAXW4bombState_t@1@@Z
// EA  : 0x82CA4680
// RVA : 0x00CA4680
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void __fastcall idProp_Explosive::StateOn(idProp_Explosive *this, unsigned int state)
{
  idEventArg *v3; // r3
  idEventArg *v4; // r3
  idProp_ExplosivePlunger *v5; // r3
  int GameMs; // r3
  idPresentable *presentable; // r11
  int v8; // r28
  int v9; // r3
  idPresentable *v10; // r11
  int v11; // r28
  idPhysics *Physics; // r28
  idPhysics *v13; // r30
  int v14; // r29
  idPresentable *v15; // r27
  const idMat3 *v16; // r28
  const idVec3 *v17; // r3
  idProp_Breakable *containedExplosive; // r3
  idProp_Breakable *v19; // r3
  int v20; // r5
  idPhysics *v21; // r3
  const idDeclDamage *explodeDamage; // r30
  const idVec3 *v23; // r3
  idEventArg *v24; // r3
  idEventArg v25; // [sp+50h] [-90h] BYREF
  idEventArg v26; // [sp+70h] [-70h] BYREF
  idEventArg v27[4]; // [sp+90h] [-50h] BYREF

  if ( state <= 6 )
  {
    switch ( state )
    {
      case 1u:
        idEntity::StartSoundShader(
          this,
          channel: SND_CHANNEL_WEAPON_1,
          shader: this->sndTicking,
          soundShaderFlags: SSF_LOOPING|SSF_NO_RANDOM_OFFSET,
          peerMask: 0xFFu);
        v3 = idEventArg::idEventArg(this: &v25, data: this);
        idEventReceiver::PostEventMS(
          this,
          ev: &EV_PreDetonate,
          time: *(_DWORD *)&v3->type,
          arg1: (const idEventArg *)LODWORD(v3->value.v[1]));
        v4 = idEventArg::idEventArg(this: &v26, data: this);
        idEventReceiver::PostEventMS(
          this,
          ev: &EV_Detonate,
          time: *(_DWORD *)&v4->type,
          arg1: (const idEventArg *)LODWORD(v4->value.v[1]));
        break;
      case 2u:
      case 3u:
LABEL_32:
        break;
      case 4u:
        if ( idEntityPtr<idProp_ExplosivePlunger>::operator->(this: &this->detonator) != nullptr )
        {
          v5 = idEntityPtr<idProp_ExplosivePlunger>::operator->(this: &this->detonator);
          idProp_ExplosivePlunger::PrimePlunger(this: v5, explosive: this);
        }
        break;
      case 5u:
        GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        presentable = this->presentable;
        v8 = GameMs;
        if ( presentable == nullptr )
        {
          idEntity::InitPresentableInternal(this);
          presentable = this->presentable;
        }
        idFXManager::StopFX(this: &presentable->fxManager, time: v8, stopCondition: 114, immediateStop: false);
        v9 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        v10 = this->presentable;
        v11 = v9;
        if ( v10 == nullptr )
        {
          idEntity::InitPresentableInternal(this);
          v10 = this->presentable;
        }
        idFXManager::StopFX(this: &v10->fxManager, time: v11, stopCondition: 113, immediateStop: false);
        idEntity::StopSound(this, channel: SND_CHANNEL_WEAPON_1, peerMask: 0);
        idEntity::StartSoundShader(
          this,
          channel: SND_CHANNEL_ANY,
          shader: this->sndExplode,
          soundShaderFlags: SSF_PLAY_ONCE|SSF_NO_RANDOM_OFFSET,
          peerMask: 0xFFu);
        Physics = idEntity::GetPhysics(this);
        v13 = idEntity::GetPhysics(this);
        v14 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        if ( this->presentable == nullptr )
          idEntity::InitPresentableInternal(this);
        v15 = this->presentable;
        v16 = Physics->GetAxis(this: Physics, a2: 0);
        v17 = v13->GetOrigin(this: v13, a2: 0);
        idFXManager::StartFX(this: &v15->fxManager, org: v17, axis: v16, time: v14, startCondition: 116);
        containedExplosive = (idProp_Breakable *)this->containedExplosive;
        if ( containedExplosive != nullptr )
        {
          v19 = idProp_Breakable::CastTo(c: containedExplosive);
          v20 = 0;
          if ( v19 != nullptr )
          {
            idEventReceiver::PostEventMS(this: v19, ev: &EV_BreakIt, time: 0);
            v20 = 3000;
          }
          idEventReceiver::PostEventMS(this: this->containedExplosive, ev: &EV_Remove, time: v20);
          this->containedExplosive = nullptr;
        }
        if ( this->explodeDamage != nullptr )
        {
          v21 = idEntity::GetPhysics(this);
          explodeDamage = this->explodeDamage;
          v23 = v21->GetOrigin(this: v21, a2: 0);
          idGameLocal::RadiusDamage(
            this: gameLocal,
            origin: v23,
            inflictor: this,
            attacker: this,
            damageDef: explodeDamage,
            dmgPower: 1.0);
        }
        if ( this->state != BOMB_STATE_DEAD )
        {
          this->state = BOMB_STATE_DEAD;
          idProp_Explosive::StateOn(this, state: BOMB_STATE_DEAD);
        }
        break;
      default:
        if ( state != 0 )
        {
          if ( this->reusable )
          {
            v24 = idEventArg::idEventArg(this: v27, data: this);
            idEventReceiver::PostEventMS(
              this,
              ev: &EV_ResetContainer,
              time: *(_DWORD *)&v24->type,
              arg1: (const idEventArg *)LODWORD(v24->value.v[1]));
          }
          else
          {
            idEventReceiver::PostEventMS(this, ev: &EV_Remove, time: 0);
          }
        }
        else
        {
          this->impulseCount = 0;
          idEntity::BecomeInactive(this, flags: 7);
        }
        goto LABEL_32;
    }
  }
}


// ========================================================================
// ??0idProp_JobPosting@@QAA@XZ
// EA  : 0x82CA4A18
// RVA : 0x00CA4A18
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

idProp_JobPosting *__fastcall idProp_JobPosting::idProp_JobPosting(idProp_JobPosting *this)
{
  idProp_Usable::idProp_Usable(this);
  this->__vftable = (idProp_JobPosting_vtbl *)&idProp_JobPosting::`vftable';
  this->jobDeclList.list = nullptr;
  this->jobDeclList.granularity = 0;
  this->jobDeclList.memTag = 5;
  this->jobDeclList.listStatic = 0;
  this->jobDeclList.size = 0;
  this->jobDeclList.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->jobDeclList);
  this->displayName.index = -1;
  this->shouldCheckPlayer = true;
  return this;
}


// ========================================================================
// __unwind$504321
// EA  : 0x82CA4AA4
// RVA : 0x00CA4AA4
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void _unwind_504321()
{
  int v0; // r12

  idProp_Usable::~idProp_Usable(this: *(idProp_Usable **)(v0 - 112 + 132));
}


// ========================================================================
// ??1idProp_JobPosting@@UAA@XZ
// EA  : 0x82CA4AD8
// RVA : 0x00CA4AD8
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void __fastcall idProp_JobPosting::~idProp_JobPosting(idProp_JobPosting *this)
{
  this->__vftable = (idProp_JobPosting_vtbl *)&idProp_JobPosting::`vftable';
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->jobDeclList);
  this->__vftable = (idProp_JobPosting_vtbl *)&idProp::`vftable';
  idAnimatedEntity::~idAnimatedEntity(this);
}


// ========================================================================
// __unwind$504346
// EA  : 0x82CA4B38
// RVA : 0x00CA4B38
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void _unwind_504346()
{
  int v0; // r12

  idProp_Usable::~idProp_Usable(this: *(idProp_Usable **)(v0 - 112 + 132));
}


// ========================================================================
// ?GetUsableState@idProp_PlayerInteraction@@UBA?AW4usableState_t@@PBVidEntity@@ABVidFocusTrace@@@Z
// EA  : 0x82CA4B60
// RVA : 0x00CA4B60
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

int __fastcall idProp_PlayerInteraction::GetUsableState(
        idProp_PlayerInteraction *this,
        idPlayer *activator,
        const idFocusTrace *ft)
{
  idPlayer *v5; // r3
  idDeclInventory *itemToPickUp; // r31
  idJobManager *v7; // r3
  int value; // r10
  idVolume *v9; // r3
  idGameLocal *v10; // r11
  int v11; // r29
  int i; // r30
  int v13; // r9
  idVolume *v14; // r3
  idVolume *v15; // r3
  int v16; // r9
  idVolume *v17; // r3
  idVolume *v18; // r3
  int v19; // r9
  idEntity *v20; // r3
  idEntity *v21; // r3

  v5 = idPlayer::CastTo(c: activator);
  if ( v5 != nullptr )
  {
    itemToPickUp = this->itemToPickUp;
    if ( itemToPickUp == nullptr
      || !itemToPickUp->singular
      || (v7 = (idJobManager *)v5->GetInventory(this: v5),
          idJobManager::FindJobByDecl(this: v7, jobDecl: (const idDeclJob *)itemToPickUp) == nullptr) )
    {
      value = this->useVolume.spawnId.value;
      if ( gameLocal->spawnIds.ptr[value & 0x1FFF] != value >> 13 )
        return 3;
      v9 = (idVolume *)gameLocal->entities.ptr[value & 0x1FFF];
      if ( v9 == nullptr || idVolume::CastTo(c: v9) == nullptr )
        return 3;
      v10 = gameLocal;
      v11 = 0;
      for ( i = 0; ; ++i )
      {
        v13 = this->useVolume.spawnId.value;
        if ( v10->spawnIds.ptr[v13 & 0x1FFF] == v13 >> 13
          && (v14 = (idVolume *)v10->entities.ptr[v13 & 0x1FFF]) != nullptr )
        {
          v15 = idVolume::CastTo(c: v14);
          v10 = gameLocal;
        }
        else
        {
          v15 = nullptr;
        }
        if ( v11 >= v15->touching.num )
          break;
        v16 = this->useVolume.spawnId.value;
        if ( v10->spawnIds.ptr[v16 & 0x1FFF] == v16 >> 13
          && (v17 = (idVolume *)v10->entities.ptr[v16 & 0x1FFF]) != nullptr )
        {
          v18 = idVolume::CastTo(c: v17);
          v10 = gameLocal;
        }
        else
        {
          v18 = nullptr;
        }
        v19 = v18->touching.list[i].spawnId.value;
        if ( v10->spawnIds.ptr[v19 & 0x1FFF] == v19 >> 13 && (v20 = v10->entities.ptr[v19 & 0x1FFF]) != nullptr )
        {
          v21 = idEntity::CastTo(c: v20);
          v10 = gameLocal;
        }
        else
        {
          v21 = nullptr;
        }
        if ( v21 == activator )
          return 3;
        ++v11;
      }
    }
  }
  return 0;
}


// ========================================================================
// ?Use@idProp_PlayerInteraction@@UAA_NPAVidEntity@@W4usableState_t@@@Z
// EA  : 0x82CA4D18
// RVA : 0x00CA4D18
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

int __fastcall idProp_PlayerInteraction::Use(
        idProp_PlayerInteraction *this,
        idPlayer *user,
        const usableState_t usable)
{
  idPlayer *v5; // r3
  idPlayer *v6; // r27
  idDeclInventory *itemToPickUp; // r31
  idJobManager *v8; // r3
  idIndex<short,enum invalidJointIndex_t> *TreeAnimatorFromPresentable; // r3
  const idIndex<short,enum invalidJointIndex_t> *v10; // r28
  idTreeAnimator *v11; // r3
  idIndex<short,enum invalidJointIndex_t> *v12; // r3
  const idIndex<short,enum invalidJointIndex_t> *v13; // r28
  idTreeAnimator *v14; // r3
  int value; // r10
  idVolume *v16; // r3
  idGameLocal *v17; // r11
  int v18; // r28
  int i; // r30
  int v20; // r9
  idVolume *v21; // r3
  idVolume *v22; // r3
  int v23; // r9
  idVolume *v24; // r3
  idVolume *v25; // r3
  int v26; // r9
  idEntity *v27; // r3
  idEntity *v28; // r3
  idPresentable *presentable; // r3
  int v30; // r3
  idTreeAnimator *v31; // r3
  unsigned __int16 v33; // [sp+50h] [-90h] BYREF
  unsigned __int16 v34; // [sp+52h] [-8Eh] BYREF
  idVec3 v35; // [sp+58h] [-88h] BYREF
  idVec3 v36[2]; // [sp+68h] [-78h] BYREF
  idMat3 v37[2]; // [sp+80h] [-60h] BYREF

  v5 = idPlayer::CastTo(c: user);
  v6 = v5;
  if ( v5 == nullptr )
    return 0;
  itemToPickUp = this->itemToPickUp;
  if ( itemToPickUp != nullptr && itemToPickUp->singular )
  {
    v8 = (idJobManager *)v5->GetInventory_2(this: v5);
    if ( idJobManager::FindJobByDecl(this: v8, jobDecl: (const idDeclJob *)itemToPickUp) != nullptr )
      return 0;
  }
  TreeAnimatorFromPresentable = (idIndex<short,enum invalidJointIndex_t> *)idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
  idTreeAnimator::GetJointIndex(this: (idTreeAnimator *)&v33, result: TreeAnimatorFromPresentable, jointName: "align");
  if ( (v33 & 0x8000u) == 0 )
  {
    v10 = (const idIndex<short,enum invalidJointIndex_t> *)v33;
    v11 = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
    idTreeAnimator::GetWorldSpaceJointTransform(
      this: v11,
      pose: (animationPose_t)0,
      jointIndex: v10,
      origin: &v35,
      axis: v37);
  }
  v12 = (idIndex<short,enum invalidJointIndex_t> *)idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
  idTreeAnimator::GetJointIndex(this: (idTreeAnimator *)&v34, result: v12, jointName: "look_align");
  if ( (v34 & 0x8000u) == 0 )
  {
    v13 = (const idIndex<short,enum invalidJointIndex_t> *)v34;
    v14 = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
    idTreeAnimator::GetWorldSpaceJointTransform(
      this: v14,
      pose: (animationPose_t)0,
      jointIndex: v13,
      origin: v36,
      axis: v37);
  }
  value = this->useVolume.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
  {
    v16 = (idVolume *)gameLocal->entities.ptr[value & 0x1FFF];
    if ( v16 != nullptr && idVolume::CastTo(c: v16) != nullptr )
    {
      v17 = gameLocal;
      v18 = 0;
      for ( i = 0; ; ++i )
      {
        v20 = this->useVolume.spawnId.value;
        if ( v17->spawnIds.ptr[v20 & 0x1FFF] == v20 >> 13
          && (v21 = (idVolume *)v17->entities.ptr[v20 & 0x1FFF]) != nullptr )
        {
          v22 = idVolume::CastTo(c: v21);
          v17 = gameLocal;
        }
        else
        {
          v22 = nullptr;
        }
        if ( v18 >= v22->touching.num )
          break;
        v23 = this->useVolume.spawnId.value;
        if ( v17->spawnIds.ptr[v23 & 0x1FFF] == v23 >> 13
          && (v24 = (idVolume *)v17->entities.ptr[v23 & 0x1FFF]) != nullptr )
        {
          v25 = idVolume::CastTo(c: v24);
          v17 = gameLocal;
        }
        else
        {
          v25 = nullptr;
        }
        v26 = v25->touching.list[i].spawnId.value;
        if ( v17->spawnIds.ptr[v26 & 0x1FFF] == v26 >> 13 && (v27 = v17->entities.ptr[v26 & 0x1FFF]) != nullptr )
        {
          v28 = idEntity::CastTo(c: v27);
          v17 = gameLocal;
        }
        else
        {
          v28 = nullptr;
        }
        if ( v28 == user )
          goto LABEL_28;
        ++v18;
      }
      return 0;
    }
  }
LABEL_28:
  presentable = v6->presentable;
  if ( presentable != nullptr )
    v30 = (int)presentable->GetPlayerInterface_2(this: presentable);
  else
    v30 = 0;
  v31 = idHands::GetTreeAnimatorFromPresentable(this: (idHands *)(v30 + 37616));
  idTreeAnimator::ClearJointMods(this: v31);
  return 1;
}


// ========================================================================
// ?IsCurrentlyUsable@idProp_PlayerInteraction@@UBA_NPBVidEntity@@@Z
// EA  : 0x82CA4FB0
// RVA : 0x00CA4FB0
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

int __fastcall idProp_PlayerInteraction::IsCurrentlyUsable(idProp_PlayerInteraction *this, idPlayer *activator)
{
  idIndex<short,enum invalidJointIndex_t> *TreeAnimatorFromPresentable; // r3
  const idIndex<short,enum invalidJointIndex_t> *v5; // r26
  idTreeAnimator *v6; // r3
  idRenderWorld *v7; // r3
  idIndex<short,enum invalidJointIndex_t> *v8; // r3
  const idIndex<short,enum invalidJointIndex_t> *v9; // r26
  idTreeAnimator *v10; // r3
  idRenderWorld *v11; // r3
  int value; // r10
  idVolume *v13; // r3
  idGameLocal *v14; // r11
  int v15; // r28
  int i; // r29
  int v17; // r9
  idVolume *v18; // r3
  idVolume *v19; // r3
  int v20; // r9
  idVolume *v21; // r3
  idVolume *v22; // r3
  int v23; // r9
  idEntity *v24; // r3
  idEntity *v25; // r3
  unsigned __int16 v27; // [sp+50h] [-C0h] BYREF
  unsigned __int16 v28; // [sp+52h] [-BEh] BYREF
  idVec3 v29; // [sp+58h] [-B8h] BYREF
  idVec3 v30; // [sp+68h] [-A8h] BYREF
  float v31[4]; // [sp+80h] [-90h] BYREF
  float v32[4]; // [sp+90h] [-80h] BYREF
  idMat3 v33; // [sp+A0h] [-70h] BYREF

  if ( idPlayer::CastTo(c: activator) != nullptr )
  {
    TreeAnimatorFromPresentable = (idIndex<short,enum invalidJointIndex_t> *)idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
    idTreeAnimator::GetJointIndex(this: (idTreeAnimator *)&v27, result: TreeAnimatorFromPresentable, jointName: "align");
    if ( (v27 & 0x8000u) == 0 )
    {
      v5 = (const idIndex<short,enum invalidJointIndex_t> *)v27;
      v6 = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
      idTreeAnimator::GetWorldSpaceJointTransform(
        this: v6,
        pose: (animationPose_t)0,
        jointIndex: v5,
        origin: &v29,
        axis: &v33);
      v7 = common->RW(this: common);
      v31[0] = v29.x;
      v31[1] = v29.y;
      v31[2] = v29.z;
      v31[3] = 1.0;
      v7->DebugSphere(
        this: v7,
        a2: (const idVec4 *)&idColor::colorRed,
        a3: (const idSphere *)v31,
        a4: 12,
        a5: 1000,
        a6: false);
    }
    v8 = (idIndex<short,enum invalidJointIndex_t> *)idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
    idTreeAnimator::GetJointIndex(this: (idTreeAnimator *)&v28, result: v8, jointName: "look_align");
    if ( (v28 & 0x8000u) == 0 )
    {
      v9 = (const idIndex<short,enum invalidJointIndex_t> *)v28;
      v10 = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
      idTreeAnimator::GetWorldSpaceJointTransform(
        this: v10,
        pose: (animationPose_t)0,
        jointIndex: v9,
        origin: &v30,
        axis: &v33);
      v11 = common->RW(this: common);
      v32[0] = v30.x;
      v32[1] = v30.y;
      v32[2] = v30.z;
      v32[3] = 1.0;
      v11->DebugSphere(
        this: v11,
        a2: (const idVec4 *)&idColor::colorBlue,
        a3: (const idSphere *)v32,
        a4: 12,
        a5: 1000,
        a6: false);
    }
    value = this->useVolume.spawnId.value;
    if ( gameLocal->spawnIds.ptr[value & 0x1FFF] != value >> 13 )
      return 1;
    v13 = (idVolume *)gameLocal->entities.ptr[value & 0x1FFF];
    if ( v13 == nullptr || idVolume::CastTo(c: v13) == nullptr )
      return 1;
    v14 = gameLocal;
    v15 = 0;
    for ( i = 0; ; ++i )
    {
      v17 = this->useVolume.spawnId.value;
      if ( v14->spawnIds.ptr[v17 & 0x1FFF] == v17 >> 13
        && (v18 = (idVolume *)v14->entities.ptr[v17 & 0x1FFF]) != nullptr )
      {
        v19 = idVolume::CastTo(c: v18);
        v14 = gameLocal;
      }
      else
      {
        v19 = nullptr;
      }
      if ( v15 >= v19->touching.num )
        break;
      v20 = this->useVolume.spawnId.value;
      if ( v14->spawnIds.ptr[v20 & 0x1FFF] == v20 >> 13
        && (v21 = (idVolume *)v14->entities.ptr[v20 & 0x1FFF]) != nullptr )
      {
        v22 = idVolume::CastTo(c: v21);
        v14 = gameLocal;
      }
      else
      {
        v22 = nullptr;
      }
      v23 = v22->touching.list[i].spawnId.value;
      if ( v14->spawnIds.ptr[v23 & 0x1FFF] == v23 >> 13 && (v24 = v14->entities.ptr[v23 & 0x1FFF]) != nullptr )
      {
        v25 = idEntity::CastTo(c: v24);
        v14 = gameLocal;
      }
      else
      {
        v25 = nullptr;
      }
      if ( v25 == activator )
        return 1;
      ++v15;
    }
  }
  return 0;
}


// ========================================================================
// ??0idMinigame@@QAA@XZ
// EA  : 0x82CA52A0
// RVA : 0x00CA52A0
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

idMinigame *__fastcall idMinigame::idMinigame(idMinigame *this)
{
  idUse::idUse(this);
  this->__vftable = (idMinigame_vtbl *)&idMinigame::`vftable';
  this->animatedBox.spawnId.value = 0x1FFF;
  this->fpEvent.spawnId.value = 0x1FFF;
  this->activatingPlayer.spawnId.value = 0x1FFF;
  this->prevStage = -1;
  this->gameType = GAMETYPE_LOCKPICK;
  this->gameLevel = GAMELEVEL_1;
  this->showHelp = false;
  return this;
}


// ========================================================================
// ?Event_MinigameSuccess@idMinigame@@QAA?AVeventVoid@@XZ
// EA  : 0x82CA5370
// RVA : 0x00CA5370
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

idMinigame *__fastcall idMinigame::Event_MinigameSuccess(idMinigame *this, idEntity *result)
{
  int z_low; // r10
  idPlayer *v5; // r3
  idPlayer *v6; // r29
  float y; // r11
  idGameLocal *v9; // r11
  idAnimatedSimple *v10; // r3
  int v11; // r4
  idFirstPersonEvent *v12; // r3

  z_low = LODWORD(result[1].spawnOrientation.mat[0].z);
  if ( gameLocal->spawnIds.ptr[z_low & 0x1FFF] != z_low >> 13
    || (v5 = (idPlayer *)gameLocal->entities.ptr[z_low & 0x1FFF]) == nullptr
    || (v6 = idPlayer::CastTo(c: v5)) == nullptr )
  {
    idLib::Warning(fmt: "idMinigame: Player died during minigame, won't activate targets");
    return this;
  }
  y = result[1].spawnOrientation.mat[1].y;
  if ( LODWORD(y) == 2 )
  {
    v9 = gameLocal;
    if ( gameLocal->spawnIds.ptr[LODWORD(result[1].spawnOrientation.mat[0].x) & 0x1FFF] != SLODWORD(result[1].spawnOrientation.mat[0].x) >> 13 )
      goto LABEL_12;
    v10 = idEntityPtr<idAnimatedSimple>::operator->(this: (idEntityPtr<idAnimatedSimple> *)&result[1].spawnOrientation);
    v11 = 3;
    goto LABEL_11;
  }
  if ( LODWORD(y) == 1 )
  {
    v9 = gameLocal;
    if ( gameLocal->spawnIds.ptr[LODWORD(result[1].spawnOrientation.mat[0].x) & 0x1FFF] == SLODWORD(result[1].spawnOrientation.mat[0].x) >> 13 )
    {
      v10 = idEntityPtr<idAnimatedSimple>::operator->(this: (idEntityPtr<idAnimatedSimple> *)&result[1].spawnOrientation);
      v11 = 1;
LABEL_11:
      idAnimatedSimple::SetAnimState(this: v10, animState: v11, blendTime: 0xC8u, queue: false, checkPoint: false);
      v9 = gameLocal;
    }
LABEL_12:
    if ( v9->spawnIds.ptr[LODWORD(result[1].spawnOrientation.mat[0].y) & 0x1FFF] == SLODWORD(result[1].spawnOrientation.mat[0].y) >> 13 )
    {
      v12 = idEntityPtr<idFirstPersonEvent>::operator->(this: (idEntityPtr<idFirstPersonEvent> *)&result[1].spawnOrientation.mat[0].y);
      idFirstPersonEvent::SetCurrentState(this: v12, changeType: 2u, nextState: 2);
    }
  }
  result->ActivateTargets(this: result, a2: v6);
  result->Hide_2(this: result);
  idEntity::BecomeInactive(this: result, flags: 1);
  return this;
}


// ========================================================================
// ?StartMinigame@idMinigame@@AAAXPAVidPlayer@@@Z
// EA  : 0x82CA54F0
// RVA : 0x00CA54F0
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void __fastcall idMinigame::StartMinigame(idMinigame *this, idPlayer *player)
{
  idPresentable *presentable; // r3
  int v5; // r3
  idMinigame::minigameType_t gameType; // r11
  idGameLocal *v7; // r11
  idAnimatedSimple *v8; // r3
  idAnimatedSimple *v9; // r3
  idFirstPersonEvent *v10; // r3
  idFirstPersonEvent *v11; // r3
  idFirstPersonEvent *v12; // r31
  int value; // r9
  idPlayer *v14; // r3
  idPlayer *v15; // r3
  idGameLocal *v16; // r11
  idAnimatedSimple *v17; // r3
  idFirstPersonEvent *v18; // r29
  idFirstPersonEvent_vtbl *v19; // r31
  idPlayer *v20; // r3

  if ( player != nullptr )
  {
    presentable = player->presentable;
    if ( presentable != nullptr )
      v5 = (int)presentable->GetPlayerInterface_2(this: presentable);
    else
      v5 = 0;
    idPlayerHud::SetMinigame(this: (idPlayerHud *)(v5 + 35096), ent: this);
    idEntity::BecomeActive(this, flags: 1);
    this->activatingPlayer.spawnId.value = (gameLocal->spawnIds.ptr[player->entityNumber] << 13) | player->entityNumber;
  }
  gameType = this->gameType;
  if ( gameType == GAMETYPE_HOTWIRE )
  {
    v7 = gameLocal;
    if ( gameLocal->spawnIds.ptr[this->animatedBox.spawnId.value & 0x1FFF] == this->animatedBox.spawnId.value >> 13 )
    {
      v8 = (idAnimatedSimple *)gameLocal->entities.ptr[this->animatedBox.spawnId.value & 0x1FFF];
      if ( v8 != nullptr )
        v9 = idAnimatedSimple::CastTo(c: v8);
      else
        v9 = nullptr;
      idAnimatedSimple::SetAnimState(this: v9, animState: 0, blendTime: 0, queue: false, checkPoint: false);
      v7 = gameLocal;
    }
    if ( v7->spawnIds.ptr[this->fpEvent.spawnId.value & 0x1FFF] == this->fpEvent.spawnId.value >> 13 )
    {
      v10 = (idFirstPersonEvent *)v7->entities.ptr[this->fpEvent.spawnId.value & 0x1FFF];
      if ( v10 != nullptr )
      {
        v11 = idFirstPersonEvent::CastTo(c: v10);
        v7 = gameLocal;
        v12 = v11;
      }
      else
      {
        v12 = nullptr;
      }
      value = this->activatingPlayer.spawnId.value;
      if ( v7->spawnIds.ptr[value & 0x1FFF] == value >> 13
        && (v14 = (idPlayer *)v7->entities.ptr[value & 0x1FFF]) != nullptr )
      {
        v15 = idPlayer::CastTo(c: v14);
        v12->OnActivate(this: v12, a2: v15);
      }
      else
      {
        v12->OnActivate(this: v12, a2: nullptr);
      }
    }
  }
  else if ( gameType == GAMETYPE_LOCKPICK )
  {
    v16 = gameLocal;
    if ( gameLocal->spawnIds.ptr[this->animatedBox.spawnId.value & 0x1FFF] == this->animatedBox.spawnId.value >> 13 )
    {
      v17 = idEntityPtr<idAnimatedSimple>::operator->(this: &this->animatedBox);
      idAnimatedSimple::SetAnimState(this: v17, animState: 0, blendTime: 0, queue: false, checkPoint: false);
      v16 = gameLocal;
    }
    if ( v16->spawnIds.ptr[this->fpEvent.spawnId.value & 0x1FFF] == this->fpEvent.spawnId.value >> 13 )
    {
      v18 = idEntityPtr<idFirstPersonEvent>::operator->(this: &this->fpEvent);
      v19 = v18->__vftable;
      v20 = idEntityPtr<idPlayer>::operator->(this: &this->activatingPlayer);
      v19->OnActivate(this: v18, a2: v20);
    }
  }
}


// ========================================================================
// ?Think@idMinigame@@UAAXXZ
// EA  : 0x82CA5760
// RVA : 0x00CA5760
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void __fastcall idMinigame::Think(idMinigame *this)
{
  int value; // r10
  idPlayer *v3; // r3
  idPlayer *v4; // r3
  idPresentable *presentable; // r3
  idPresentablePlayer *v6; // r3
  localView_t *LocalView; // r3
  int prevStage; // r11
  double minigameRangeIndicator; // fp31
  int minigameStage; // r10
  char v11; // r29
  idMinigame::minigameType_t gameType; // r11
  idAnimatedSimple *v13; // r3
  idAnimatedSimple *v14; // r3
  int v15; // r8
  int v16; // r5
  idFirstPersonEvent *v17; // r3
  idFirstPersonEvent *v18; // r3

  value = this->activatingPlayer.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
  {
    v3 = (idPlayer *)gameLocal->entities.ptr[value & 0x1FFF];
    v4 = v3 != nullptr ? idPlayer::CastTo(c: v3) : nullptr;
    presentable = v4->presentable;
    if ( presentable != nullptr )
    {
      v6 = presentable->GetPlayerInterface_2(this: presentable);
      if ( v6 != nullptr )
      {
        LocalView = idPresentablePlayer::GetLocalView(this: v6);
        if ( LocalView != nullptr )
        {
          prevStage = this->prevStage;
          minigameRangeIndicator = LocalView->hudRender.minigameRangeIndicator;
          minigameStage = LocalView->hudRender.minigameStage;
          if ( prevStage < 0 || (v11 = 1, minigameStage <= prevStage) )
            v11 = 0;
          gameType = this->gameType;
          this->prevStage = minigameStage;
          if ( gameType == GAMETYPE_HOTWIRE )
          {
            if ( gameLocal->spawnIds.ptr[this->animatedBox.spawnId.value & 0x1FFF] == this->animatedBox.spawnId.value >> 13 )
            {
              v13 = idEntityPtr<idAnimatedSimple>::operator->(this: &this->animatedBox);
              idAnimatedSimple::SetExternalTime(this: v13, normalizedTime: minigameRangeIndicator);
              if ( v11 != 0 )
              {
                v14 = idEntityPtr<idAnimatedSimple>::operator->(this: &this->animatedBox);
                idAnimatedSimple::SetAnimState(
                  this: v14,
                  animState: 2,
                  blendTime: 0xC8u,
                  queue: false,
                  checkPoint: false);
              }
            }
            v15 = this->fpEvent.spawnId.value >> 13;
            v16 = gameLocal->spawnIds.ptr[this->fpEvent.spawnId.value & 0x1FFF];
          }
          else
          {
            if ( gameType != GAMETYPE_LOCKPICK )
              return;
            v15 = this->fpEvent.spawnId.value >> 13;
            v16 = gameLocal->spawnIds.ptr[this->fpEvent.spawnId.value & 0x1FFF];
          }
          if ( v16 == v15 )
          {
            v17 = idEntityPtr<idFirstPersonEvent>::operator->(this: &this->fpEvent);
            idFirstPersonEvent::SetExternalTime(this: v17, normalizedTime: minigameRangeIndicator);
            if ( v11 != 0 )
            {
              v18 = idEntityPtr<idFirstPersonEvent>::operator->(this: &this->fpEvent);
              idFirstPersonEvent::SetCurrentState(this: v18, changeType: 2u, nextState: 1);
            }
          }
        }
      }
    }
  }
}


// ========================================================================
// ?Spawn@idProp_MissionBoard@@QAAXXZ
// EA  : 0x82CA5928
// RVA : 0x00CA5928
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void __fastcall idProp_MissionBoard::Spawn(idProp_MissionBoard *this)
{
  float y; // r10
  float z; // r9
  int v4; // r26
  idResource *v5; // r3
  int *v6; // r29
  double v7; // fp31
  double v8; // fp30
  double v9; // fp29
  idResource *v10; // r3
  idResource *v11; // r27
  idProp_MissionPin *v12; // r3
  idProp_MissionPin *v13; // r3
  idProp_MissionPin *v14; // r30
  int v15; // r5
  int v16; // [sp+50h] [-C0h] BYREF
  int v17; // [sp+54h] [-BCh] BYREF
  int v18; // [sp+58h] [-B8h] BYREF
  __int64 v19; // [sp+60h] [-B0h]
  float v20; // [sp+68h] [-A8h]
  float v21[4]; // [sp+70h] [-A0h] BYREF
  idMat3 v22; // [sp+80h] [-90h] BYREF

  y = this->spawnPosition.y;
  z = this->spawnPosition.z;
  *(float *)&v19 = this->spawnPosition.x;
  *((float *)&v19 + 1) = y;
  v20 = z;
  idMat3::ToAngles(this: &v22, result: (idAngles *)&this->spawnOrientation);
  v4 = 0;
  v22.mat[1].y = 0.0;
  LODWORD(v22.mat[2].x) = 20;
  LODWORD(v22.mat[1].z) = &v22.mat[2].y;
  HIBYTE(v22.mat[2].y) = 0;
  if ( (unsigned __int8)idDeclChapter::FindCurrentEntry(chapterIndex: &v17, variationIndex: &v18, partIndex: &v16) != 0 )
  {
    v5 = idResourceList::Index(this: &idDeclChapter::resourceList, index: v17);
    v6 = (int *)((char *)v5[3].nextOnHashChain + 28 * v18);
    if ( idDeclChapter::resourceList.num > 0 )
    {
      v7 = v20;
      v8 = *((float *)&v19 + 1);
      v9 = *(float *)&v19;
      do
      {
        v10 = idResourceList::Index(this: &idDeclChapter::resourceList, index: v4);
        v11 = v10;
        if ( v10 != nullptr && v10[2].trackedMemory == 1 )
        {
          idChapterPart::GetLayersParsed(this: (idChapterPart *)(v6[2] + 20 * v16), retLayers: (idStr *)&v22.mat[1].y);
          v12 = (idProp_MissionPin *)gameLocal->SpawnEntityFromDef(
                                       this: gameLocal,
                                       a2: this->missionPinDef,
                                       a3: -1,
                                       a4: -1,
                                       a5: -1);
          v13 = idProp_MissionPin::CastTo(c: v12);
          v14 = v13;
          if ( v13 != nullptr )
          {
            v15 = *v6;
            v19 = *(_QWORD *)&v11[2].name.str;
            idProp_MissionPin::Initialize(
              this: v13,
              chapter: (const idDeclChapter *)v11,
              variationID: v15,
              partIndex: v16,
              layers: (idStr *)&v22.mat[1].y);
            v21[0] = *(float *)&v19 + (float)v9;
            v21[1] = *((float *)&v19 + 1) + (float)v8;
            v21[2] = v7;
            v14->Teleport(this: v14, a2: (const idVec3 *)v21, a3: (const idAngles *)&v22);
          }
        }
        ++v4;
      }
      while ( v4 < idDeclChapter::resourceList.num );
    }
  }
  else
  {
    idLib::Warning(fmt: "idTarget_NextMap '%s' couldn't find the current map", this->name.data);
  }
  idStr::FreeData(this: (idStr *)&v22.mat[1].y);
}


// ========================================================================
// __unwind$505829
// EA  : 0x82CA5AF0
// RVA : 0x00CA5AF0
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void _unwind_505829()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 272 + 144));
}


// ========================================================================
// ?Use@idCombiner@@UAA_NPAVidEntity@@W4usableState_t@@@Z
// EA  : 0x82CA5E08
// RVA : 0x00CA5E08
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

int __fastcall idCombiner::Use(idCombiner *this, idPlayer *activator, usableState_t usable)
{
  idPlayer *v7; // r27
  idPlayerHud *PlayerHud; // r3
  int v9; // r28
  int num; // r11
  int v11; // r29
  int v12; // r30
  const idDeclJob *v13; // r24
  idJobManager *v14; // r3
  idJob *JobByDecl; // r3
  int v16; // r29
  int v17; // r30
  const idDeclInventory *v18; // r28
  idInventoryCollection *v19; // r3
  idPresentable *v20; // r3
  int v21; // r3
  const idSoundShader *selectSound; // r5
  int v23; // r30
  int value; // r9
  idEntity *v25; // r3
  idEntity *v26; // r3
  idPresentable *presentable; // r3
  int v28; // r3

  if ( usable == USABLE_NOT_USABLE )
    return 0;
  if ( (unsigned __int8)idPlayer::IsTypeOf(c: activator) != 0 )
  {
    v7 = idPlayer::CastTo(c: activator);
    PlayerHud = (idPlayerHud *)idPlayer::GetPlayerHud(this: v7);
    v9 = 0;
    if ( idPlayerHud::GetCombinerIndex(this: PlayerHud, ent: this) < 0 )
    {
      if ( this->onActivate.num > 0 )
      {
        v23 = 0;
        do
        {
          value = this->onActivate.list[v23].spawnId.value;
          if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
          {
            v25 = gameLocal->entities.ptr[value & 0x1FFF];
            if ( v25 != nullptr )
            {
              v26 = idEntity::CastTo(c: v25);
              if ( v26 != nullptr )
                idEntity::Activate(this: v26, activator);
            }
          }
          ++v9;
          ++v23;
        }
        while ( v9 < this->onActivate.num );
      }
      idCombiner::SetBlinkOnItems(this, enable: true);
      presentable = v7->presentable;
      if ( presentable != nullptr )
        v28 = (int)presentable->GetPlayerInterface_2(this: presentable);
      else
        v28 = 0;
      idPlayerHud::AddCombiner(this: (idPlayerHud *)(v28 + 35096), ent: this);
      selectSound = this->selectSound;
    }
    else
    {
      num = this->neededItemsDecl.num;
      v11 = 0;
      if ( num > 0 )
      {
        v12 = 0;
        do
        {
          v13 = (const idDeclJob *)this->neededItemsDecl.list[v12];
          v14 = (idJobManager *)v7->GetInventory_2(this: v7);
          JobByDecl = idJobManager::FindJobByDecl(this: v14, jobDecl: v13);
          if ( JobByDecl != nullptr
            && ((int (__fastcall *)(idJob *))JobByDecl->__vftable[2].dtr_idClass)(a1: JobByDecl) > 0 )
          {
            ++v9;
          }
          num = this->neededItemsDecl.num;
          ++v11;
          ++v12;
        }
        while ( v11 < num );
      }
      if ( v9 != num )
        return 1;
      if ( this->removeItemsOnCompete )
      {
        v16 = 0;
        if ( num > 0 )
        {
          v17 = 0;
          do
          {
            v18 = this->neededItemsDecl.list[v17];
            v19 = v7->GetInventory_2(this: v7);
            idInventoryCollection::DeleteInventoryItem(this: v19, owner: nullptr, decl: v18, count: 10000);
            ++v16;
            ++v17;
          }
          while ( v16 < this->neededItemsDecl.num );
        }
      }
      idUse::Use(this, activator, usable);
      idEventReceiver::PostEventMS(this, ev: &EV_Remove, time: 0);
      v20 = v7->presentable;
      if ( v20 != nullptr )
        v21 = (int)v20->GetPlayerInterface_2(this: v20);
      else
        v21 = 0;
      idPlayerHud::RemoveCombiner(this: (idPlayerHud *)(v21 + 35096), ent: this);
      selectSound = this->completeSound;
    }
    idEntity::StartSoundShader(
      this: activator,
      channel: SND_CHANNEL_ANY,
      shader: selectSound,
      soundShaderFlags: (soundShaderFlags_t)0,
      peerMask: 0xFFu);
  }
  return 1;
}


// ========================================================================
// ??0idPropSmartLoot@@QAA@XZ
// EA  : 0x82CA6088
// RVA : 0x00CA6088
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

idPropSmartLoot *__fastcall idPropSmartLoot::idPropSmartLoot(idPropSmartLoot *this)
{
  idUse::idUse(this);
  this->__vftable = (idPropSmartLoot_vtbl *)&idPropSmartLoot::`vftable';
  idSmartLootComponent::idSmartLootComponent(this: &this->smartLootComponent);
  idInventoryCollection::idInventoryCollection(this: &this->inventory);
  this->hasActivated = false;
  return this;
}


// ========================================================================
// __unwind$506514
// EA  : 0x82CA60EC
// RVA : 0x00CA60EC
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void _unwind_506514()
{
  int v0; // r12

  idUse::~idUse(this: *(idUse **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$506515
// EA  : 0x82CA6114
// RVA : 0x00CA6114
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void _unwind_506515()
{
  int v0; // r12

  idSmartLootComponent::~idSmartLootComponent(this: (idSmartLootComponent *)(*(_DWORD *)(v0 - 112 + 132) + 856));
}


// ========================================================================
// ??0idProp_Moveable@@QAA@XZ
// EA  : 0x82CA6210
// RVA : 0x00CA6210
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

idProp_Moveable *__fastcall idProp_Moveable::idProp_Moveable(idProp_Moveable *this)
{
  float z; // r11
  float v3; // r6
  char flags; // r5

  idProp_Usable::idProp_Usable(this);
  this->bouncyness = 0.60000002;
  this->linearFriction = 0.60000002;
  this->__vftable = (idProp_Moveable_vtbl *)&idProp_Moveable::`vftable';
  this->angularFriction = 0.60000002;
  this->density = 0.0020000001;
  this->friction = 0.050000001;
  this->inertiaScale.x = 1.0;
  this->inertiaScale.y = 1.0;
  this->inertiaScale.z = 1.0;
  *((_BYTE *)this + 5296) = 1;
  *((_BYTE *)this + 5297) &= 0x27u;
  this->impulseTarget.x = vec3_origin.x;
  this->impulseTarget.y = vec3_origin.y;
  z = vec3_origin.z;
  this->impulseVelocity = 0.0;
  this->impulseTarget.z = z;
  this->impulseAVelocity.x = vec3_origin.x;
  this->impulseAVelocity.y = vec3_origin.y;
  v3 = vec3_origin.z;
  this->minDamageVelocity = 100.0;
  this->maxDamageVelocity = 200.0;
  this->impulseAVelocity.z = v3;
  this->fadeTimeDelay = 0.0;
  this->damage = 0;
  this->fadeTime = 3.0;
  this->selfDamage = 0;
  this->removeCondition = REMOVE_CONDITION_NONE;
  idContents::idContents(this: &this->clipOverride.contents);
  idContents::idContents(this: &this->clipOverride.clipMask);
  this->bounceMaxVelocity = 200.0;
  this->sound_spawn = nullptr;
  this->sound_bounce = nullptr;
  this->sound_scrape = nullptr;
  this->sound_pickup = nullptr;
  this->bounceMinVelocity = 80.0;
  this->pickupParticle = nullptr;
  this->particleModel = nullptr;
  this->inventoryDecl = nullptr;
  this->inventoryCount = 1;
  this->backupInventoryDecl = nullptr;
  this->backupInventoryCount = 1;
  this->alternateInventoryDecl.list = nullptr;
  this->alternateInventoryDecl.granularity = 0;
  this->alternateInventoryDecl.memTag = 5;
  this->alternateInventoryDecl.listStatic = 0;
  this->alternateInventoryDecl.size = 0;
  this->alternateInventoryDecl.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->alternateInventoryDecl);
  this->additionalInventoryDecl.list = nullptr;
  this->additionalInventoryDecl.granularity = 0;
  this->additionalInventoryDecl.memTag = 5;
  this->additionalInventoryDecl.listStatic = 0;
  this->additionalInventoryDecl.size = 0;
  this->additionalInventoryDecl.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->additionalInventoryDecl);
  this->requiredInvDecl = nullptr;
  this->requiredJobDecl.len = 0;
  this->requiredJobDecl.allocedAndFlag = 20;
  this->requiredJobDecl.data = this->requiredJobDecl.baseBuffer;
  this->requiredJobDecl.baseBuffer[0] = 0;
  this->minRespawnDelay = 0.0;
  this->requiredJobStatus = JOBSTATUS_ACCEPTED;
  this->maxRespawnDelay = 0.0;
  this->removeDelay = 0;
  this->pickupName.index = -1;
  this->respawnTime = 0;
  idInventoryCollection::idInventoryCollection(this: &this->inventory);
  idPhysics_RigidBody::idPhysics_RigidBody(this: &this->physicsObj);
  this->nextDamageTime = 0;
  this->nextBounceTime = 0;
  this->nextScrapeTime = 0;
  this->nextSelfDamageTime = 0;
  this->nextImpulseTime = 0;
  this->fade.fadeFrom = 0.0;
  this->fade.fadeTo = 0.0;
  this->fade.fadeStartTime = 0;
  this->fade.fadeEndTime = 0;
  this->fade.noStippleFade = false;
  this->pulseTime = -1;
  this->startFadingAtTime = -1;
  this->propNode.head = &this->propNode;
  this->propNode.owner = nullptr;
  this->propNode.next = &this->propNode;
  this->propNode.prev = &this->propNode;
  this->useAlias.value = -1;
  *(_WORD *)&this->useLock = 1;
  this->whoDroppedMe.spawnId.value = 0x1FFF;
  flags = (char)this->flags;
  this->propNode.owner = this;
  *(_BYTE *)&this->flags = flags | 0x42;
  return this;
}


// ========================================================================
// __unwind$506630
// EA  : 0x82CA64A4
// RVA : 0x00CA64A4
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void _unwind_506630()
{
  int v0; // r12

  idProp_Usable::~idProp_Usable(this: *(idProp_Usable **)(v0 - 160 + 180));
}


// ========================================================================
// __unwind$506631
// EA  : 0x82CA64CC
// RVA : 0x00CA64CC
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void _unwind_506631()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 5412));
}


// ========================================================================
// __unwind$506632
// EA  : 0x82CA64F8
// RVA : 0x00CA64F8
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void _unwind_506632()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 5428));
}


// ========================================================================
// __unwind$506633
// EA  : 0x82CA6524
// RVA : 0x00CA6524
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void _unwind_506633()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 160 + 180) + 5448));
}


// ========================================================================
// __unwind$506634
// EA  : 0x82CA6550
// RVA : 0x00CA6550
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void _unwind_506634()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 5504));
}


// ========================================================================
// ??1idProp_Moveable@@UAA@XZ
// EA  : 0x82CA6588
// RVA : 0x00CA6588
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void __fastcall idProp_Moveable::~idProp_Moveable(idProp_Moveable *this)
{
  idInventoryCollection *p_inventory; // r29
  int v3; // r5
  idRenderModel *particleModel; // r3

  this->__vftable = (idProp_Moveable_vtbl *)&idProp_Moveable::`vftable';
  p_inventory = &this->inventory;
  idInventoryCollection::FreeInventory(this: &this->inventory, owner: nullptr);
  particleModel = this->particleModel;
  if ( particleModel != nullptr )
  {
    particleModel->unlinked = true;
    particleModel->deleteOnSync = true;
    idRenderModel::CommitThisFrame(this: particleModel);
  }
  idEntity::SetPhysics(this, phys: nullptr, a3: v3);
  this->propNode.prev->next = this->propNode.next;
  this->propNode.next->prev = this->propNode.prev;
  this->propNode.next = &this->propNode;
  this->propNode.prev = &this->propNode;
  this->propNode.head = &this->propNode;
  idLinkList<idEvent>::Clear(this: (idLinkList<idProp_VehiclePickup> *)&this->propNode);
  idPhysics_RigidBody::~idPhysics_RigidBody(this: &this->physicsObj);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)p_inventory);
  idStr::FreeData(this: &this->requiredJobDecl);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->additionalInventoryDecl);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->alternateInventoryDecl);
  this->__vftable = (idProp_Moveable_vtbl *)&idProp::`vftable';
  idAnimatedEntity::~idAnimatedEntity(this);
}


// ========================================================================
// __unwind$506846
// EA  : 0x82CA6660
// RVA : 0x00CA6660
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void _unwind_506846()
{
  int v0; // r12

  idProp_Usable::~idProp_Usable(this: *(idProp_Usable **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$506847
// EA  : 0x82CA6688
// RVA : 0x00CA6688
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void _unwind_506847()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 5412));
}


// ========================================================================
// __unwind$506848
// EA  : 0x82CA66B4
// RVA : 0x00CA66B4
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void _unwind_506848()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 5428));
}


// ========================================================================
// __unwind$506849
// EA  : 0x82CA66E0
// RVA : 0x00CA66E0
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void _unwind_506849()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 128 + 148) + 5448));
}


// ========================================================================
// __unwind$506850
// EA  : 0x82CA670C
// RVA : 0x00CA670C
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void _unwind_506850()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 5504));
}


// ========================================================================
// __unwind$506851
// EA  : 0x82CA6738
// RVA : 0x00CA6738
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void _unwind_506851()
{
  int v0; // r12

  idPhysics_RigidBody::~idPhysics_RigidBody(this: (idPhysics_RigidBody *)(*(_DWORD *)(v0 - 128 + 148) + 6304));
}


// ========================================================================
// __unwind$506852
// EA  : 0x82CA6764
// RVA : 0x00CA6764
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void _unwind_506852()
{
  int v0; // r12

  idLinkList<idWaypoint>::~idLinkList<idWaypoint>(this: (idLinkList<idProp_VehiclePickup> *)(*(_DWORD *)(v0 - 128 + 148)
                                                                                           + 6976));
}


// ========================================================================
// ?ModifyCrosshairInfo@idProp_Moveable@@UBA_NPBVidEntity@@ABVidFocusTrace@@W4usableState_t@@AAVidCrosshairInfo@@@Z
// EA  : 0x82CA6798
// RVA : 0x00CA6798
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

int __fastcall idProp_Moveable::ModifyCrosshairInfo(
        idProp_Moveable *this,
        idPlayer *activator,
        const idFocusTrace *ft,
        usableState_t usable,
        idCrosshairInfo *info)
{
  int index; // r11
  const idDeclInventory *inventoryDecl; // r11
  idPlayer *v11; // r3
  idPlayer *v12; // r24
  char v13; // r30
  int v14; // r20
  idJob *InventoryItemByDeclName; // r3
  const idDeclInventory *requiredInvDecl; // r28
  idJobManager *v17; // r3
  bool v18; // r23
  idAI2 *v19; // r3
  idAI2 *v20; // r3
  idAI2 *v21; // r26
  int v22; // r3
  idSmartLootComponent *v23; // r28
  int num; // ctr
  int v25; // r11
  bfx::Planner3D *v26; // r3
  idInventoryCollection *v27; // r3
  idInventoryItem *InventoryItem; // r3
  idCrosshairCustomIcon *list; // r11
  idPickupHudInfo v30; // [sp+60h] [-E0h] BYREF
  idList<idVehicleState *,5> v31; // [sp+A0h] [-A0h] BYREF
  _DWORD v32[36]; // [sp+B0h] [-90h] BYREF

  if ( (unsigned __int8)idProp_Usable::ModifyCrosshairInfo(this, activator, ft, usable, info) == 0 )
    return 0;
  index = this->pickupName.index;
  if ( index < 0 )
  {
    inventoryDecl = this->inventoryDecl;
    if ( inventoryDecl != nullptr )
      index = inventoryDecl->displayName.index;
    else
      index = -1;
  }
  info->text.index = index;
  v11 = idPlayer::CastTo(c: activator);
  v12 = v11;
  if ( v11 == nullptr )
    return 1;
  v13 = 0;
  v14 = 1;
  if ( this->requiredJobDecl.len != 0 )
  {
    InventoryItemByDeclName = idInventoryCollection::FindInventoryItemByDeclName(
                                this: &v11->jobManager,
                                jobName: this->requiredJobDecl.data);
    if ( InventoryItemByDeclName == nullptr || InventoryItemByDeclName->status < this->requiredJobStatus )
      v14 = 0;
  }
  requiredInvDecl = this->requiredInvDecl;
  if ( requiredInvDecl != nullptr )
  {
    v17 = (idJobManager *)v12->GetInventory(this: v12);
    v14 = idJobManager::FindJobByDecl(this: v17, jobDecl: (const idDeclJob *)requiredInvDecl) == nullptr ? 0 : v14;
  }
  if ( this->inventoryDecl != nullptr )
  {
    v18 = (_cntlzw((unsigned int)info->icons.list->material) & 0x20) != 0;
    if ( this->whoDroppedMe.spawnId.value != 0x1FFF )
    {
      v19 = (idAI2 *)idEntityPtr<idEntity const>::operator->(this: &this->whoDroppedMe);
      v20 = idAI2::CastTo(c: v19);
      v21 = v20;
      if ( v20 == nullptr )
        return 0;
      v14 = 0;
      v18 = false;
      v22 = (int)v20->GetSmartLootComponent_2(this: v20);
      v23 = (idSmartLootComponent *)v22;
      if ( v22 != 0 )
      {
        v30.items.size = 3;
        v30.items.num = 0;
        v30.items.granularity = 1;
        v30.items.list = v30.items.staticList;
        v30.items.memTag = 5;
        v30.items.listStatic = 1;
        v30.items.staticList[0].icon = nullptr;
        v30.items.staticList[0].count = 0;
        v30.items.staticList[0].canPickup = true;
        v30.items.staticList[1].icon = nullptr;
        v30.items.staticList[1].count = 0;
        v30.items.staticList[1].canPickup = true;
        v30.items.staticList[2].icon = nullptr;
        v30.items.staticList[2].count = 0;
        v30.items.staticList[2].canPickup = true;
        (*(void (__fastcall **)(int, idAI2 *, idPlayer *))(*(_DWORD *)v22 + 4))(a1: v22, a2: v21, a3: v12);
        idSmartLootComponent::GetPickupHudInfo(this: v23, user: v12, info: &v30, weaponStuffOnly: true);
        if ( v30.items.num > 0 )
        {
          num = v30.items.num;
          v14 = 1;
          v25 = 0;
          do
          {
            info->icons.list[v25].material = v30.items.list[v25].icon;
            info->icons.list[v25].itemCount = v30.items.list[v25].count;
            info->icons.list[v25].usable = v30.items.list[v25].canPickup;
            ++v25;
            --num;
          }
          while ( num != 0 );
        }
        idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v30);
      }
    }
    info->hoverSound = this->inventoryDecl->hoverSound;
    if ( v18 )
    {
      info->icons.list->material = this->inventoryDecl->icon;
      v26 = (bfx::Planner3D *)this->GetInventory(this);
      if ( idScriptObject::GetTypeDef(this: v26) != nullptr )
      {
        v31.size = 3;
        v31.num = 0;
        v31.granularity = 1;
        v31.list = (idVehicleState **)v32;
        v31.memTag = 5;
        v31.listStatic = 1;
        v32[0] = 0;
        v32[1] = 0;
        HIBYTE(v32[2]) = 1;
        v32[3] = 0;
        v32[4] = 0;
        HIBYTE(v32[5]) = 1;
        v32[6] = 0;
        v32[7] = 0;
        HIBYTE(v32[8]) = 1;
        v27 = (idInventoryCollection *)this->GetInventory(this);
        InventoryItem = idInventoryCollection::GetInventoryItem(this: v27, index: 0);
        InventoryItem->GetPickupHudInfo(this: InventoryItem, a2: v12, a3: (idPickupHudInfo *)&v31);
        info->icons.list->material = (const idMaterial *)*v31.list;
        info->icons.list->itemCount = *((_DWORD *)v31.list + 1);
        list = info->icons.list;
        if ( list->usable && *((_BYTE *)v31.list + 8) != 0 )
          v13 = 1;
        list->usable = v13;
        idList<idThread *,58>::Clear(this: &v31);
      }
    }
  }
  if ( (_BYTE)v14 == 0 )
  {
    info->color = idColor::colorRed;
    info->colorState = CROSSHAIR_COLOR_NEGATIVE;
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&info->icons);
  }
  return v14;
}


// ========================================================================
// __unwind$506950
// EA  : 0x82CA6B24
// RVA : 0x00CA6B24
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void _unwind_506950()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 320 + 96));
}


// ========================================================================
// __unwind$506951
// EA  : 0x82CA6B4C
// RVA : 0x00CA6B4C
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void _unwind_506951()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 320 + 160));
}


// ========================================================================
// ?Use@idProp_Moveable@@UAA_NPAVidEntity@@W4usableState_t@@@Z
// EA  : 0x82CA6B80
// RVA : 0x00CA6B80
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

int __fastcall idProp_Moveable::Use(idProp_Moveable *this, idPlayer *activator, __int32 usable)
{
  int v6; // r30
  idPlayer *v7; // r3
  idPlayer *v8; // r27
  char v9; // r29
  idAI2 *v10; // r3
  idAI2 *v11; // r3
  idSmartLootComponent *v12; // r3
  char v13; // r10
  int v14; // r26
  int v15; // r29
  idPresentable *presentable; // r30
  idInventoryCollection *v17; // r3
  idPresentable *v18; // r30
  idInventoryCollection *v19; // r3
  idVehicleState *v20; // [sp+50h] [-80h] BYREF
  idList<idVehicleState *,5> v21; // [sp+60h] [-70h] BYREF
  int v22; // [sp+70h] [-60h] BYREF

  if ( this->useLock )
    return 0;
  this->useLock = true;
  v6 = idProp_Usable::Use(this, activator, usable);
  if ( (_BYTE)v6 != 0 )
  {
    v7 = idPlayer::CastTo(c: activator);
    v8 = v7;
    if ( v7 != nullptr )
    {
      if ( (unsigned __int8)idProp_Moveable::AttachPlayer(this, player: v7) != 0 )
        return 1;
      v9 = 1;
      if ( this->whoDroppedMe.spawnId.value != 0x1FFF )
      {
        v10 = (idAI2 *)idEntityPtr<idEntity const>::operator->(this: &this->whoDroppedMe);
        v11 = idAI2::CastTo(c: v10);
        if ( v11 == nullptr )
          return 0;
        v12 = v11->GetSmartLootComponent_2(this: v11);
        if ( v12 != nullptr )
        {
          v21.num = 0;
          v21.granularity = 1;
          v21.size = 3;
          v21.list = (idVehicleState **)&v22;
          v21.memTag = 5;
          v21.listStatic = 1;
          idSmartLootComponent::GetLootItems(this: v12, output: &v21, weaponStuffOnly: true);
          v13 = 0;
          v14 = 0;
          if ( v21.num > 0 )
          {
            v15 = 0;
            do
            {
              v20 = v21.list[v15];
              if ( v20 != nullptr )
              {
                presentable = v8->presentable;
                if ( presentable == nullptr )
                {
                  idEntity::InitPresentableInternal(this: v8);
                  presentable = v8->presentable;
                }
                v17 = v8->GetInventory_2(this: v8);
                idInventoryCollection::TransferItem(
                  this: v17,
                  owner: nullptr,
                  to: presentable,
                  item: (idInventoryItem **)&v20,
                  deleteOwnerItem: true,
                  canIntro: false);
                v13 = 1;
              }
              ++v14;
              ++v15;
            }
            while ( v14 < v21.num );
          }
          if ( v13 != 0 )
            idPlayer::PlayPickupSound(this: v8, prop: this);
          v18 = this->presentable;
          if ( v18 == nullptr )
          {
            idEntity::InitPresentableInternal(this);
            v18 = this->presentable;
          }
          v19 = this->GetInventory_2(this);
          idInventoryCollection::FreeInventory(this: v19, owner: v18);
          idProp_Moveable::NaniteInspection(this);
          v9 = 0;
          v6 = 1;
          idList<idThread *,58>::Clear(this: &v21);
        }
      }
      if ( v9 != 0 )
      {
        v6 = idPlayer::PickupItem(this: v8, prop: this);
        if ( (_BYTE)v6 != 0 && (*((_BYTE *)this + 5296) & 0x80) != 0 )
          idGameLayerManager::AddItemMemory(this: &v8->gameLayerManager, itemName: this->name.data);
      }
    }
  }
  this->useLock = false;
  return v6;
}


// ========================================================================
// __unwind$507208
// EA  : 0x82CA6DB4
// RVA : 0x00CA6DB4
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void _unwind_507208()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 208 + 96));
}


// ========================================================================
// ?ModifyCrosshairInfo@idProp_Loot@@UBA_NPBVidEntity@@ABVidFocusTrace@@W4usableState_t@@AAVidCrosshairInfo@@@Z
// EA  : 0x82CA6DE0
// RVA : 0x00CA6DE0
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

BOOL __fastcall idProp_Loot::ModifyCrosshairInfo(
        idProp_Loot *this,
        idPlayer *activator,
        const idFocusTrace *ft,
        usableState_t usable,
        idCrosshairInfo *info)
{
  return (unsigned __int8)idProp_Moveable::ModifyCrosshairInfo(this, activator, ft, usable, info) != 0;
}


// ========================================================================
// ??0idProp_AIArmor@@QAA@XZ
// EA  : 0x82CA6E10
// RVA : 0x00CA6E10
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

idProp_AIArmor *__fastcall idProp_AIArmor::idProp_AIArmor(idProp_AIArmor *this)
{
  idProp_Moveable::idProp_Moveable(this);
  this->__vftable = (idProp_AIArmor_vtbl *)&idProp_AIArmor::`vftable';
  this->tagName.len = 0;
  this->tagName.allocedAndFlag = 20;
  this->tagName.data = this->tagName.baseBuffer;
  this->tagName.baseBuffer[0] = 0;
  return this;
}


// ========================================================================
// ??1idProp_AIArmor@@UAA@XZ
// EA  : 0x82CA6E78
// RVA : 0x00CA6E78
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void __fastcall idProp_AIArmor::~idProp_AIArmor(idProp_AIArmor *this)
{
  this->__vftable = (idProp_AIArmor_vtbl *)&idProp_AIArmor::`vftable';
  idStr::FreeData(this: &this->tagName);
  idProp_Moveable::~idProp_Moveable(this);
}


// ========================================================================
// __unwind$507318
// EA  : 0x82CA6ECC
// RVA : 0x00CA6ECC
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void _unwind_507318()
{
  int v0; // r12

  idProp_Moveable::~idProp_Moveable(this: *(idProp_Moveable **)(v0 - 112 + 132));
}


// ========================================================================
// ??0idProp_ElectricArmor@@QAA@XZ
// EA  : 0x82CA6EF8
// RVA : 0x00CA6EF8
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

idProp_ElectricArmor *__fastcall idProp_ElectricArmor::idProp_ElectricArmor(idProp_ElectricArmor *this)
{
  idProp_Moveable::idProp_Moveable(this);
  this->__vftable = (idProp_ElectricArmor_vtbl *)&idProp_AIArmor::`vftable';
  this->tagName.len = 0;
  this->tagName.data = this->tagName.baseBuffer;
  this->tagName.allocedAndFlag = 20;
  this->tagName.baseBuffer[0] = 0;
  this->__vftable = (idProp_ElectricArmor_vtbl *)&idProp_ElectricArmor::`vftable';
  this->owner.spawnId.value = 0x1FFF;
  this->OwnerJoint.value = -1;
  this->electricPulseTime = 500;
  this->electricBoltSystem = nullptr;
  this->electricShock = nullptr;
  this->startElectricTime = 0;
  this->nextShockTime = 0;
  this->electricShockDelay = 16;
  this->electricDistance = 100;
  return this;
}


// ========================================================================
// ??1idProp_ElectricArmor@@UAA@XZ
// EA  : 0x82CA6FA0
// RVA : 0x00CA6FA0
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void __fastcall idProp_ElectricArmor::~idProp_ElectricArmor(idProp_ElectricArmor *this)
{
  idElectricBolt *electricShock; // r30

  this->__vftable = (idProp_ElectricArmor_vtbl *)&idProp_ElectricArmor::`vftable';
  electricShock = this->electricShock;
  if ( electricShock != nullptr )
  {
    idElectricBolt::~idElectricBolt(this: this->electricShock);
    idMem::Free(this: &mem, ptr: electricShock, align: ALIGN_16);
    this->electricShock = nullptr;
  }
  idProp_AIArmor::~idProp_AIArmor(this);
}


// ========================================================================
// __unwind$507466_0
// EA  : 0x82CA7008
// RVA : 0x00CA7008
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void _unwind_507466_0()
{
  int v0; // r12

  idProp_AIArmor::~idProp_AIArmor(this: *(idProp_AIArmor **)(v0 - 128 + 148));
}


// ========================================================================
// ??0idProp_BreakableLoot@@QAA@XZ
// EA  : 0x82CA7038
// RVA : 0x00CA7038
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

idProp_BreakableLoot *__fastcall idProp_BreakableLoot::idProp_BreakableLoot(idProp_BreakableLoot *this)
{
  idProp_Usable::idProp_Usable(this);
  this->__vftable = (idProp_BreakableLoot_vtbl *)&idProp_BreakableLoot::`vftable';
  idProp_BreakableLoot::effectsDef_t::effectsDef_t(this: &this->effectsDef);
  idProp_BreakableLoot::inventoryDef_t::inventoryDef_t(this: &this->inventoryDef);
  idContents::idContents(this: &this->clipOverride.contents);
  idContents::idContents(this: &this->clipOverride.clipMask);
  this->entitiesSpawnedOnBreak.list = nullptr;
  this->entitiesSpawnedOnBreak.granularity = 0;
  this->entitiesSpawnedOnBreak.memTag = 5;
  this->entitiesSpawnedOnBreak.listStatic = 0;
  this->entitiesSpawnedOnBreak.size = 0;
  this->entitiesSpawnedOnBreak.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->entitiesSpawnedOnBreak);
  *((_BYTE *)this + 5436) &= 0x3Fu;
  this->spawnParts.list = nullptr;
  this->spawnParts.granularity = 0;
  this->spawnParts.memTag = 5;
  this->spawnParts.listStatic = 0;
  this->spawnParts.size = 0;
  this->spawnParts.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->spawnParts);
  this->spawnSplinters.list = nullptr;
  this->spawnSplinters.granularity = 0;
  this->spawnSplinters.memTag = 5;
  this->spawnSplinters.listStatic = 0;
  this->spawnSplinters.size = 0;
  this->spawnSplinters.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->spawnSplinters);
  this->spawnEntitiesOnBreak.list = nullptr;
  this->spawnEntitiesOnBreak.granularity = 0;
  this->spawnEntitiesOnBreak.memTag = 5;
  this->spawnEntitiesOnBreak.listStatic = 0;
  this->spawnEntitiesOnBreak.size = 0;
  this->spawnEntitiesOnBreak.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->spawnEntitiesOnBreak);
  this->lootedTime = -1;
  idInventoryCollection::idInventoryCollection(this: &this->inventory);
  this->fade.fadeStartTime = 0;
  this->fade.fadeEndTime = 0;
  this->fade.noStippleFade = false;
  this->fade.fadeFrom = 0.0;
  this->fade.fadeTo = 0.0;
  return this;
}


// ========================================================================
// __unwind$507493
// EA  : 0x82CA7158
// RVA : 0x00CA7158
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void _unwind_507493()
{
  int v0; // r12

  idProp_Usable::~idProp_Usable(this: *(idProp_Usable **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$507494
// EA  : 0x82CA7180
// RVA : 0x00CA7180
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void _unwind_507494()
{
  int v0; // r12

  idProp_BreakableLoot::effectsDef_t::~effectsDef_t(this: (idProp_BreakableLoot::effectsDef_t *)(*(_DWORD *)(v0 - 128 + 148)
                                                                                               + 5264));
}


// ========================================================================
// __unwind$507495
// EA  : 0x82CA71AC
// RVA : 0x00CA71AC
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void _unwind_507495()
{
  int v0; // r12

  idProp_BreakableLoot::inventoryDef_t::~inventoryDef_t(this: (idProp_BreakableLoot::inventoryDef_t *)(*(_DWORD *)(v0 - 128 + 148) + 5352));
}


// ========================================================================
// __unwind$507496
// EA  : 0x82CA71D8
// RVA : 0x00CA71D8
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void _unwind_507496()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 5420));
}


// ========================================================================
// __unwind$507497
// EA  : 0x82CA7204
// RVA : 0x00CA7204
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void _unwind_507497()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 5440));
}


// ========================================================================
// __unwind$507498
// EA  : 0x82CA7230
// RVA : 0x00CA7230
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void _unwind_507498()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 5456));
}


// ========================================================================
// __unwind$507499
// EA  : 0x82CA725C
// RVA : 0x00CA725C
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void _unwind_507499()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 5472));
}


// ========================================================================
// ??1idProp_BreakableLoot@@UAA@XZ
// EA  : 0x82CA7298
// RVA : 0x00CA7298
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void __fastcall idProp_BreakableLoot::~idProp_BreakableLoot(idProp_BreakableLoot *this)
{
  this->__vftable = (idProp_BreakableLoot_vtbl *)&idProp_BreakableLoot::`vftable';
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->inventory);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->spawnEntitiesOnBreak);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->spawnSplinters);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->spawnParts);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->entitiesSpawnedOnBreak);
  idProp_BreakableLoot::inventoryDef_t::~inventoryDef_t(this: &this->inventoryDef);
  idProp_BreakableLoot::effectsDef_t::~effectsDef_t(this: &this->effectsDef);
  this->__vftable = (idProp_BreakableLoot_vtbl *)&idProp::`vftable';
  idAnimatedEntity::~idAnimatedEntity(this);
}


// ========================================================================
// __unwind$507580
// EA  : 0x82CA7328
// RVA : 0x00CA7328
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void _unwind_507580()
{
  int v0; // r12

  idProp_Usable::~idProp_Usable(this: *(idProp_Usable **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$507581
// EA  : 0x82CA7350
// RVA : 0x00CA7350
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void _unwind_507581()
{
  int v0; // r12

  idProp_BreakableLoot::effectsDef_t::~effectsDef_t(this: (idProp_BreakableLoot::effectsDef_t *)(*(_DWORD *)(v0 - 112 + 132)
                                                                                               + 5264));
}


// ========================================================================
// __unwind$507582
// EA  : 0x82CA737C
// RVA : 0x00CA737C
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void _unwind_507582()
{
  int v0; // r12

  idProp_BreakableLoot::inventoryDef_t::~inventoryDef_t(this: (idProp_BreakableLoot::inventoryDef_t *)(*(_DWORD *)(v0 - 112 + 132) + 5352));
}


// ========================================================================
// __unwind$507583
// EA  : 0x82CA73A8
// RVA : 0x00CA73A8
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void _unwind_507583()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 5420));
}


// ========================================================================
// __unwind$507584
// EA  : 0x82CA73D4
// RVA : 0x00CA73D4
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void _unwind_507584()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 5440));
}


// ========================================================================
// __unwind$507585
// EA  : 0x82CA7400
// RVA : 0x00CA7400
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void _unwind_507585()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 5456));
}


// ========================================================================
// __unwind$507586
// EA  : 0x82CA742C
// RVA : 0x00CA742C
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void _unwind_507586()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 5472));
}


// ========================================================================
// ?Spawn@idProp_BreakableLoot@@QAAXXZ
// EA  : 0x82CA7458
// RVA : 0x00CA7458
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void __fastcall idProp_BreakableLoot::Spawn(idProp_BreakableLoot *this)
{
  int num; // r11
  signed int v3; // r10
  idClientGame *v4; // r11
  bool v5; // zf
  int v6; // r9
  unsigned int seed; // r9
  unsigned int v8; // r6
  int v9; // r5
  int randomLootQuantity; // r10
  int v11; // r22
  int v12; // r26
  signed int v13; // r10
  int v14; // r10
  unsigned int v15; // r8
  int v16; // r4
  unsigned int v17; // r7
  int v18; // r30
  const idDeclInventory *v19; // r10
  const idDeclJob *v20; // r29
  idJobManager *v21; // r3
  idPresentable *presentable; // r29
  const idDeclInventory **list; // r28
  const idDeclInventory *v24; // r28
  idInventoryCollection *v25; // r3
  idInventoryItem *v26; // r3
  int v27; // r27
  int v28; // r28
  idBreakable *v29; // r30
  idPhysics *Physics; // r29
  idPhysics *v31; // r25
  idPhysics *v32; // r3
  idPhysics_vtbl *v33; // r29
  const idVec3 *(__fastcall *GetOrigin)(idPhysics *, int); // ctr
  int v35; // r3
  idPhysics *v36; // r29
  idPhysics *v37; // r25
  idPhysics *v38; // r3
  idPhysics_vtbl *v39; // r29
  const idMat3 *(__fastcall *GetAxis)(idPhysics *, int); // ctr
  int v41; // r3
  idPhysics *v42; // r3
  idBreakable *v43; // r3
  int v44; // r27
  int v45; // r28
  idBreakable *v46; // r30
  idPhysics *v47; // r29
  idPhysics *v48; // r25
  idPhysics *v49; // r3
  idPhysics_vtbl *v50; // r29
  const idVec3 *(__fastcall *v51)(idPhysics *, int); // ctr
  int v52; // r3
  idPhysics *v53; // r29
  idPhysics *v54; // r25
  idPhysics *v55; // r3
  idPhysics_vtbl *v56; // r29
  const idMat3 *(__fastcall *v57)(idPhysics *, int); // ctr
  int v58; // r3
  idPhysics *v59; // r3
  idBreakable *v60; // r3
  int v61; // r27
  int v62; // r29
  idEntity *v63; // r30
  idPhysics *v64; // r28
  idPhysics *v65; // r25
  idPhysics *v66; // r3
  idPhysics_vtbl *v67; // r28
  const idVec3 *(__fastcall *v68)(idPhysics *, int); // ctr
  int v69; // r3
  idPhysics *v70; // r28
  idPhysics *v71; // r25
  idPhysics *v72; // r3
  idPhysics_vtbl *v73; // r28
  const idMat3 *(__fastcall *v74)(idPhysics *, int); // ctr
  int v75; // r3
  idPhysics *v76; // r3
  idPhysics *v77; // r29
  idPhysics_vtbl *v78; // r30
  int v79; // r3
  idPhysics *v80; // r29
  idPhysics_vtbl *v81; // r30
  int v82; // r3
  idPresentable *v83; // r11
  highlightColor_t highlightColor; // r10
  idRenderModel *v85; // r9
  idRenderModel *model; // r10
  encounterGroupRole_t v87[2]; // [sp+50h] [-70h] BYREF

  num = this->inventoryDef.randomLootPool.num;
  if ( num != 0 )
  {
    v3 = num - 1;
    v5 = num != 1;
    v4 = clientGame;
    if ( v5 )
    {
      seed = clientGame->random.seed;
      __twllei(v3, 0);
      v8 = 1664525 * seed + 1013904223;
      clientGame->random.seed = v8;
      v4 = clientGame;
      v9 = (v8 >> 10) & 0x7FFF;
      v6 = v9 % v3;
      __twlgei(v3 & ~(__ROL4__(v9, 1) - 1), 0xFFFFFFFF);
    }
    else
    {
      v6 = 0;
    }
    randomLootQuantity = this->inventoryDef.randomLootQuantity;
    v11 = v6 + 1;
    if ( randomLootQuantity > 0 )
    {
      v11 = this->inventoryDef.randomLootQuantity;
      if ( randomLootQuantity >= this->inventoryDef.randomLootPool.num )
        v11 = this->inventoryDef.randomLootPool.num;
    }
    v12 = 0;
    while ( v12 < v11 )
    {
      v13 = this->inventoryDef.randomLootPool.num;
      if ( v13 != 0 )
      {
        v15 = v4->random.seed;
        __twllei(v13, 0);
        v4->random.seed = 1664525 * v15 + 1013904223;
        v16 = (v4->random.seed >> 10) & 0x7FFF;
        v4 = clientGame;
        v17 = v13 & ~(__ROL4__(v16, 1) - 1);
        v14 = v16 % v13;
        __twlgei(v17, 0xFFFFFFFF);
      }
      else
      {
        v14 = 0;
      }
      v18 = v14;
      v19 = this->inventoryDef.randomLootPool.list[v14];
      if ( v19 != nullptr )
      {
        v20 = (const idDeclJob *)v19;
        v21 = (idJobManager *)this->GetInventory_2(this);
        if ( idJobManager::FindJobByDecl(this: v21, jobDecl: v20) == nullptr )
        {
          presentable = this->presentable;
          list = this->inventoryDef.randomLootPool.list;
          if ( presentable == nullptr )
          {
            idEntity::InitPresentableInternal(this);
            presentable = this->presentable;
          }
          v24 = list[v18];
          v25 = this->GetInventory_2(this);
          v26 = idInventoryCollection::GiveItem(
                  this: v25,
                  owner: presentable,
                  decl: v24,
                  count: 1,
                  forceCount: false,
                  canIntro: false);
          ++v12;
          this->inventoryDef.randomLootPool.list[v18] = nullptr;
          v26->lootable = true;
        }
        v4 = clientGame;
      }
    }
  }
  v27 = 0;
  if ( this->effectsDef.parts.num > 0 )
  {
    v28 = 0;
    do
    {
      v29 = (idBreakable *)gameLocal->SpawnEntityFromDef(
                             this: gameLocal,
                             a2: this->effectsDef.parts.list[v28],
                             a3: -1,
                             a4: -1,
                             a5: -1);
      v87[0] = (encounterGroupRole_t)v29;
      if ( v29 != nullptr )
      {
        Physics = idEntity::GetPhysics(this);
        v31 = idEntity::GetPhysics(this: v29);
        v32 = Physics;
        GetOrigin = Physics->GetOrigin;
        v33 = v31->__vftable;
        v35 = (int)GetOrigin(this: v32, a2: 0);
        v33->SetOrigin(this: v31, a2: (const idVec3 *)v35, a3: -1);
        v36 = idEntity::GetPhysics(this);
        v37 = idEntity::GetPhysics(this: v29);
        v38 = v36;
        GetAxis = v36->GetAxis;
        v39 = v37->__vftable;
        v41 = (int)GetAxis(this: v38, a2: 0);
        v39->SetAxis(this: v37, a2: (const idMat3 *)v41, a3: -1);
        v42 = idEntity::GetPhysics(this: v29);
        v42->EnableClip(this: v42);
        idEntity::BecomeActive(this: v29, flags: 2);
        idEntity::BecomeActive(this: v29, flags: 1);
        v29->Show(this: v29);
        idList<idAnimWebBlendTree *,5>::Append(this: (idList<enum encounterGroupRole_t,5> *)&this->spawnParts, obj: v87);
        v43 = idBreakable::CastTo(c: v29);
        if ( v43 != nullptr )
        {
          if ( this->effectsDef.breakableFadeTime > 0.0 )
            v43->fadeTime = this->effectsDef.breakableFadeTime;
          if ( this->effectsDef.breakableFadeDelay > 0.0 )
            v43->fadeDelay = this->effectsDef.breakableFadeDelay;
        }
      }
      ++v27;
      ++v28;
    }
    while ( v27 < this->effectsDef.parts.num );
  }
  v44 = 0;
  if ( this->effectsDef.splinters.num > 0 )
  {
    v45 = 0;
    do
    {
      v46 = (idBreakable *)gameLocal->SpawnEntityFromDef(
                             this: gameLocal,
                             a2: this->effectsDef.splinters.list[v45],
                             a3: -1,
                             a4: -1,
                             a5: -1);
      v87[0] = (encounterGroupRole_t)v46;
      if ( v46 != nullptr )
      {
        v47 = idEntity::GetPhysics(this);
        v48 = idEntity::GetPhysics(this: v46);
        v49 = v47;
        v51 = v47->GetOrigin;
        v50 = v48->__vftable;
        v52 = (int)v51(this: v49, a2: 0);
        v50->SetOrigin(this: v48, a2: (const idVec3 *)v52, a3: -1);
        v53 = idEntity::GetPhysics(this);
        v54 = idEntity::GetPhysics(this: v46);
        v55 = v53;
        v57 = v53->GetAxis;
        v56 = v54->__vftable;
        v58 = (int)v57(this: v55, a2: 0);
        v56->SetAxis(this: v54, a2: (const idMat3 *)v58, a3: -1);
        v59 = idEntity::GetPhysics(this: v46);
        v59->DisableClip(this: v59);
        idEntity::BecomeInactive(this: v46, flags: 2);
        idEntity::BecomeInactive(this: v46, flags: 1);
        v46->Hide_2(this: v46);
        idList<idAnimWebBlendTree *,5>::Append(
          this: (idList<enum encounterGroupRole_t,5> *)&this->spawnSplinters,
          obj: v87);
        v60 = idBreakable::CastTo(c: v46);
        if ( v60 != nullptr )
        {
          if ( this->effectsDef.breakableFadeTime > 0.0 )
            v60->fadeTime = this->effectsDef.breakableFadeTime;
          if ( this->effectsDef.breakableFadeDelay > 0.0 )
            v60->fadeDelay = this->effectsDef.breakableFadeDelay;
        }
      }
      ++v44;
      ++v45;
    }
    while ( v44 < this->effectsDef.splinters.num );
  }
  v61 = 0;
  if ( this->entitiesSpawnedOnBreak.num > 0 )
  {
    v62 = 0;
    do
    {
      v63 = gameLocal->SpawnEntityFromDef(
              this: gameLocal,
              a2: this->entitiesSpawnedOnBreak.list[v62],
              a3: -1,
              a4: -1,
              a5: -1);
      v87[0] = (encounterGroupRole_t)v63;
      if ( v63 != nullptr )
      {
        v64 = idEntity::GetPhysics(this);
        v65 = idEntity::GetPhysics(this: v63);
        v66 = v64;
        v68 = v64->GetOrigin;
        v67 = v65->__vftable;
        v69 = (int)v68(this: v66, a2: 0);
        v67->SetOrigin(this: v65, a2: (const idVec3 *)v69, a3: -1);
        v70 = idEntity::GetPhysics(this);
        v71 = idEntity::GetPhysics(this: v63);
        v72 = v70;
        v74 = v70->GetAxis;
        v73 = v71->__vftable;
        v75 = (int)v74(this: v72, a2: 0);
        v73->SetAxis(this: v71, a2: (const idMat3 *)v75, a3: -1);
        v76 = idEntity::GetPhysics(this: v63);
        v76->DisableClip(this: v76);
        idEntity::BecomeInactive(this: v63, flags: 2);
        idEntity::BecomeInactive(this: v63, flags: 1);
        v63->Hide_2(this: v63);
        idList<idAnimWebBlendTree *,5>::Append(
          this: (idList<enum encounterGroupRole_t,5> *)&this->spawnEntitiesOnBreak,
          obj: v87);
      }
      ++v61;
      ++v62;
    }
    while ( v61 < this->entitiesSpawnedOnBreak.num );
  }
  v77 = idEntity::GetPhysics(this);
  v78 = v77->__vftable;
  v79 = idContents::ToFlags(this: &this->clipOverride.contents);
  v78->SetContents(this: v77, a2: v79, a3: -1);
  v80 = idEntity::GetPhysics(this);
  v81 = v80->__vftable;
  v82 = idContents::ToFlags(this: &this->clipOverride.clipMask);
  v81->SetClipMask(this: v80, a2: v82, a3: -1);
  v83 = this->presentable;
  if ( this->noBlink )
  {
    if ( v83 == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      v83 = this->presentable;
    }
    model = v83->model;
    v83->highlightColor = HIGHLIGHT_COLOR_NONE;
    model->g.highlightColor = HIGHLIGHT_COLOR_NONE;
  }
  else
  {
    if ( v83 == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      v83 = this->presentable;
    }
    highlightColor = this->effectsDef.highlightColor;
    v85 = v83->model;
    v83->highlightColor = highlightColor;
    v85->g.highlightColor = highlightColor;
  }
  idEntity::BecomeActive(this, flags: 1);
  idEntity::BecomeInactive(this, flags: 2);
}


// ========================================================================
// ??0idProp_Breakable@@QAA@XZ
// EA  : 0x82CA7B38
// RVA : 0x00CA7B38
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

idProp_Breakable *__fastcall idProp_Breakable::idProp_Breakable(idProp_Breakable *this)
{
  idProp_Moveable::idProp_Moveable(this);
  this->__vftable = (idProp_Breakable_vtbl *)&idProp_Breakable::`vftable';
  this->parts.list = nullptr;
  this->parts.granularity = 0;
  this->parts.memTag = 5;
  this->parts.listStatic = 0;
  this->parts.size = 0;
  this->parts.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->parts);
  this->splinters.list = nullptr;
  this->splinters.granularity = 0;
  this->splinters.memTag = 5;
  this->splinters.listStatic = 0;
  this->splinters.size = 0;
  this->splinters.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->splinters);
  this->spawnParts.list = nullptr;
  this->spawnParts.granularity = 0;
  this->spawnParts.memTag = 5;
  this->spawnParts.listStatic = 0;
  this->spawnParts.size = 0;
  this->spawnParts.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->spawnParts);
  this->spawnSplinters.list = nullptr;
  this->spawnSplinters.granularity = 0;
  this->spawnSplinters.memTag = 5;
  this->spawnSplinters.listStatic = 0;
  this->spawnSplinters.size = 0;
  this->spawnSplinters.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->spawnSplinters);
  this->statsTag = 0;
  this->ammoDamage.list = nullptr;
  this->ammoDamage.granularity = 0;
  this->ammoDamage.memTag = 5;
  this->ammoDamage.listStatic = 0;
  this->ammoDamage.size = 0;
  this->ammoDamage.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->ammoDamage);
  this->state = 0;
  this->onlyMeleeDamage = false;
  this->replacement = nullptr;
  this->minSplinters = 2;
  this->maxSplinters = 5;
  this->health = 25.0;
  this->sound_break = nullptr;
  this->fadeTime = 0.0;
  this->delaySoundAfterBreak = 0.0;
  this->removeDelay = 0.0;
  this->smokeParticle = nullptr;
  this->breakFromTrigger = false;
  this->explodes = false;
  this->explosionProjectile = nullptr;
  this->explosionEventDecl = (const idDeclAiEvent *)idDeclInfo::FindWithInheritance(
                                                      this: &idDeclAiEvent::resourceList,
                                                      name: "base/explosion/small",
                                                      makeDefault: true);
  this->explodeDamage = nullptr;
  this->breakable = nullptr;
  this->entityToSpawnOnBreak = nullptr;
  this->smokeStartTime = 0;
  this->replacementPart = nullptr;
  this->nextCollideTime = 0;
  this->highlightColor = HIGHLIGHT_COLOR_NONE;
  return this;
}


// ========================================================================
// __unwind$507816
// EA  : 0x82CA7CA4
// RVA : 0x00CA7CA4
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void _unwind_507816()
{
  int v0; // r12

  idProp_Moveable::~idProp_Moveable(this: *(idProp_Moveable **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$507817
// EA  : 0x82CA7CCC
// RVA : 0x00CA7CCC
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void _unwind_507817()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 7016));
}


// ========================================================================
// __unwind$507818
// EA  : 0x82CA7CF8
// RVA : 0x00CA7CF8
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void _unwind_507818()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 7032));
}


// ========================================================================
// __unwind$507819
// EA  : 0x82CA7D24
// RVA : 0x00CA7D24
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void _unwind_507819()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 7100));
}


// ========================================================================
// __unwind$507820
// EA  : 0x82CA7D50
// RVA : 0x00CA7D50
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void _unwind_507820()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 7116));
}


// ========================================================================
// __unwind$507821
// EA  : 0x82CA7D7C
// RVA : 0x00CA7D7C
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void _unwind_507821()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 7144));
}


// ========================================================================
// ?Spawn@idProp_Breakable@@QAAXXZ
// EA  : 0x82CA7DB8
// RVA : 0x00CA7DB8
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void __fastcall idProp_Breakable::Spawn(idProp_Breakable *this)
{
  char v2; // r10
  int num; // r11
  int v4; // r26
  int v5; // r29
  idEntity *v6; // r30
  idPhysics *Physics; // r28
  idPhysics *v8; // r24
  idPhysics *v9; // r3
  idPhysics_vtbl *v10; // r28
  const idVec3 *(__fastcall *GetOrigin)(idPhysics *, int); // ctr
  int v12; // r3
  const idDeclEntityDef *replacement; // r4
  idEntity *v14; // r3
  idPhysics *v15; // r30
  idPhysics *v16; // r29
  idPhysics *v17; // r3
  idPhysics_vtbl *v18; // r30
  const idVec3 *(__fastcall *v19)(idPhysics *, int); // ctr
  int v20; // r3
  idPhysics *v21; // r30
  idPhysics *v22; // r29
  idPhysics *v23; // r3
  idPhysics_vtbl *v24; // r30
  const idMat3 *(__fastcall *GetAxis)(idPhysics *, int); // ctr
  int v26; // r3
  idPhysics *v27; // r3
  idBreakableManager *p_breakableManager; // r30
  const idVec3 *v29; // r3
  BOOL noBlink; // r11
  idPresentable *presentable; // r11
  bool v32; // zf
  highlightColor_t highlightColor; // r10
  idRenderModel *v34; // r9
  idRenderModel *model; // r10
  idEntity *v36; // [sp+50h] [-50h] BYREF

  if ( this->health <= 0.0 )
    v2 = *(_BYTE *)&this->flags & 0xFD;
  else
    v2 = *(_BYTE *)&this->flags | 2;
  num = this->parts.num;
  *(_BYTE *)&this->flags = v2;
  v4 = 0;
  if ( num > 0 )
  {
    v5 = 0;
    do
    {
      v6 = gameLocal->SpawnEntityFromDef(this: gameLocal, a2: this->parts.list[v5], a3: -1, a4: -1, a5: -1);
      v36 = v6;
      if ( v6 != nullptr )
      {
        Physics = idEntity::GetPhysics(this);
        v8 = idEntity::GetPhysics(this: v6);
        v9 = Physics;
        GetOrigin = Physics->GetOrigin;
        v10 = v8->__vftable;
        v12 = (int)GetOrigin(this: v9, a2: 0);
        v10->SetOrigin(this: v8, a2: (const idVec3 *)v12, a3: -1);
        v6->Hide_2(this: v6);
        idList<idAnimWebBlendTree *,5>::Append(
          this: (idList<enum encounterGroupRole_t,5> *)&this->spawnParts,
          obj: (encounterGroupRole_t *)&v36);
      }
      ++v4;
      ++v5;
    }
    while ( v4 < this->parts.num );
  }
  replacement = this->replacement;
  if ( replacement != nullptr )
  {
    v14 = gameLocal->SpawnEntityFromDef(this: gameLocal, a2: replacement, a3: -1, a4: -1, a5: -1);
    this->replacementPart = v14;
    if ( v14 != nullptr )
    {
      v15 = idEntity::GetPhysics(this);
      v16 = idEntity::GetPhysics(this: this->replacementPart);
      v17 = v15;
      v19 = v15->GetOrigin;
      v18 = v16->__vftable;
      v20 = (int)v19(this: v17, a2: 0);
      v18->SetOrigin(this: v16, a2: (const idVec3 *)v20, a3: -1);
      v21 = idEntity::GetPhysics(this);
      v22 = idEntity::GetPhysics(this: this->replacementPart);
      v23 = v21;
      GetAxis = v21->GetAxis;
      v24 = v22->__vftable;
      v26 = (int)GetAxis(this: v23, a2: 0);
      v24->SetAxis(this: v22, a2: (const idMat3 *)v26, a3: -1);
      this->replacementPart->Hide_2(this: this->replacementPart);
    }
  }
  if ( this->breakable != nullptr )
  {
    v27 = idEntity::GetPhysics(this);
    p_breakableManager = &gameLocal->breakableManager;
    v29 = v27->GetOrigin(this: v27, a2: 0);
    idBreakableManager::AddBreakable(this: p_breakableManager, decl: this->breakable, origin: v29);
  }
  noBlink = this->noBlink;
  this->state = 0;
  v32 = noBlink;
  presentable = this->presentable;
  if ( v32 )
  {
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      presentable = this->presentable;
    }
    model = presentable->model;
    presentable->highlightColor = HIGHLIGHT_COLOR_NONE;
    model->g.highlightColor = HIGHLIGHT_COLOR_NONE;
  }
  else
  {
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      presentable = this->presentable;
    }
    highlightColor = this->highlightColor;
    v34 = presentable->model;
    presentable->highlightColor = highlightColor;
    v34->g.highlightColor = highlightColor;
  }
}


// ========================================================================
// ??0idProp_Noticable@@QAA@XZ
// EA  : 0x82CA8060
// RVA : 0x00CA8060
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

idProp_Noticable *__fastcall idProp_Noticable::idProp_Noticable(idProp_Noticable *this)
{
  idProp_Moveable::idProp_Moveable(this);
  this->noticed = false;
  this->__vftable = (idProp_Noticable_vtbl *)&idProp_Noticable::`vftable';
  this->playerOnly = false;
  return this;
}


// ========================================================================
// ?ModifyCrosshairInfo@idProp_Noticable@@UBA_NPBVidEntity@@ABVidFocusTrace@@W4usableState_t@@AAVidCrosshairInfo@@@Z
// EA  : 0x82CA80A8
// RVA : 0x00CA80A8
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

int __fastcall idProp_Noticable::ModifyCrosshairInfo(
        idProp_Noticable *this,
        idPlayer *activator,
        const idFocusTrace *ft,
        usableState_t usable,
        idCrosshairInfo *info)
{
  int index; // r11
  const idDeclInventory *inventoryDecl; // r11
  idCrosshairCustomIcon *list; // r29

  if ( (unsigned __int8)idProp_Moveable::ModifyCrosshairInfo(this, activator, ft, usable, info) == 0 )
    return 0;
  index = this->pickupName.index;
  if ( index < 0 )
  {
    inventoryDecl = this->inventoryDecl;
    if ( inventoryDecl != nullptr )
      index = inventoryDecl->displayName.index;
    else
      index = -1;
  }
  info->text.index = index;
  list = info->icons.list;
  info->material = CHMATERIAL_CUSTOM;
  list->material = this->GetIcon(this);
  return 1;
}


// ========================================================================
// ??0idProp_VehiclePickup@@QAA@XZ
// EA  : 0x82CA8130
// RVA : 0x00CA8130
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

idProp_VehiclePickup *__fastcall idProp_VehiclePickup::idProp_VehiclePickup(idProp_VehiclePickup *this)
{
  idLinkList<idProp_VehiclePickup> *head; // r8

  idProp_Moveable::idProp_Moveable(this);
  this->angle = 0.0;
  this->__vftable = (idProp_VehiclePickup_vtbl *)&idProp_VehiclePickup::`vftable';
  this->removeTime = 0;
  this->tractored = false;
  this->vehicle.spawnId.value = 0x1FFF;
  this->vecFrac = 0.1;
  this->pickupIcon = nullptr;
  this->pickupName.index = -1;
  this->allowPlayerPickup = false;
  this->controlNode.head = &this->controlNode;
  this->controlNode.owner = nullptr;
  this->controlNode.next = &this->controlNode;
  this->controlNode.prev = &this->controlNode;
  head = gameLocal->propVehiclePickupEntities.head;
  this->controlNode.next = &this->controlNode;
  this->controlNode.next->prev = this->controlNode.prev;
  this->controlNode.prev = &this->controlNode;
  this->controlNode.head = &this->controlNode;
  this->controlNode.next = head;
  this->controlNode.prev = head->prev;
  head->prev = &this->controlNode;
  this->controlNode.prev->next = &this->controlNode;
  this->controlNode.head = head->head;
  this->controlNode.owner = this;
  return this;
}


// ========================================================================
// ??0idProp_ExplosivePlunger@@QAA@XZ
// EA  : 0x82CA8220
// RVA : 0x00CA8220
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

idProp_ExplosivePlunger *__fastcall idProp_ExplosivePlunger::idProp_ExplosivePlunger(idProp_ExplosivePlunger *this)
{
  idProp_Moveable::idProp_Moveable(this);
  this->primerReady = false;
  this->__vftable = (idProp_ExplosivePlunger_vtbl *)&idProp_ExplosivePlunger::`vftable';
  this->usedPrimer = false;
  this->numPrimed = 0;
  this->explosivePacks.list = nullptr;
  this->explosivePacks.granularity = 0;
  this->explosivePacks.memTag = 5;
  this->explosivePacks.listStatic = 0;
  this->explosivePacks.size = 0;
  this->explosivePacks.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->explosivePacks);
  this->activateList.list = nullptr;
  this->activateList.granularity = 0;
  this->activateList.memTag = 5;
  this->activateList.listStatic = 0;
  this->activateList.size = 0;
  this->activateList.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->activateList);
  return this;
}


// ========================================================================
// __unwind$508068
// EA  : 0x82CA82A8
// RVA : 0x00CA82A8
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void _unwind_508068()
{
  int v0; // r12

  idProp_Moveable::~idProp_Moveable(this: *(idProp_Moveable **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$508069
// EA  : 0x82CA82D0
// RVA : 0x00CA82D0
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void _unwind_508069()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 7008));
}


// ========================================================================
// ??0idProp_Explosive@@QAA@XZ
// EA  : 0x82CA8300
// RVA : 0x00CA8300
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

idProp_Explosive *__fastcall idProp_Explosive::idProp_Explosive(idProp_Explosive *this)
{
  idProp_Moveable::idProp_Moveable(this);
  this->radiusProximityMine = 160.0;
  this->radiusAttract = 400.0;
  this->radiusAIAttractOthers = 960.0;
  this->__vftable = (idProp_Explosive_vtbl *)&idProp_Explosive::`vftable';
  this->explosiveType = PE_TIME_BOMB;
  this->attachedProp = nullptr;
  this->explodeDamage = nullptr;
  this->sndTicking = nullptr;
  this->sndPreExplode = nullptr;
  this->sndExplode = nullptr;
  this->explodeOnDamage = true;
  this->explodeTimerMS = 3000;
  this->proximityStartDelay = 2000;
  this->faction = nullptr;
  this->detonateOnPlayers = true;
  this->detonateOnAIs = true;
  this->resetTimeMS = 3000;
  this->reusable = true;
  this->attractMaxPropogationDelay = 2000;
  this->attractMinPropogationDelay = 0;
  this->fleeRandomness = 2000;
  *(_WORD *)&this->fleeOnTicking = 1;
  this->hideModelWhenPropAttached = false;
  this->ignoreDamageType = DAMAGETYPE_NONE;
  this->detonator.spawnId.value = 0x1FFF;
  this->state = BOMB_STATE_EMPTY;
  this->containedExplosive = nullptr;
  this->impulseCount = 0;
  this->preExplodeSndLength = 0;
  this->useTime = 0;
  this->random.seed = 0;
  return this;
}


// ========================================================================
// ?ModifyCrosshairInfo@idProp_Explosive@@UBA_NPBVidEntity@@ABVidFocusTrace@@W4usableState_t@@AAVidCrosshairInfo@@@Z
// EA  : 0x82CA83E8
// RVA : 0x00CA83E8
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

int __fastcall idProp_Explosive::ModifyCrosshairInfo(
        idProp_Explosive *this,
        idPlayer *activator,
        const idFocusTrace *ft,
        usableState_t usable,
        idCrosshairInfo *info)
{
  int result; // r3
  idPlayer *v9; // r3
  const idDeclInventory *requiredInvDecl; // r31
  idJobManager *v11; // r3

  if ( (unsigned __int8)idProp_Moveable::ModifyCrosshairInfo(this, activator, ft, usable, info) == 0 )
    return 0;
  v9 = idPlayer::CastTo(c: activator);
  if ( v9 == nullptr )
    return 1;
  requiredInvDecl = this->requiredInvDecl;
  v11 = (idJobManager *)v9->GetInventory(this: v9);
  result = (int)idJobManager::FindJobByDecl(this: v11, jobDecl: (const idDeclJob *)requiredInvDecl);
  if ( result != 0 )
    return 1;
  info->colorState = CROSSHAIR_COLOR_NEGATIVE;
  return result;
}


// ========================================================================
// ?Event_Detonate@idProp_Explosive@@IAA?AVeventVoid@@PAVidEntity@@@Z
// EA  : 0x82CA8470
// RVA : 0x00CA8470
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

idProp_Explosive *__fastcall idProp_Explosive::Event_Detonate(
        idProp_Explosive *this,
        idProp_Explosive *result,
        idEntity *activator)
{
  if ( result->state != BOMB_STATE_DETONATE )
  {
    result->state = BOMB_STATE_DETONATE;
    idProp_Explosive::StateOn(this: result, state: 5u);
  }
  return this;
}


// ========================================================================
// ?Event_ResetContainer@idProp_Explosive@@IAA?AVeventVoid@@PAVidEntity@@@Z
// EA  : 0x82CA84C0
// RVA : 0x00CA84C0
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

idProp_Explosive *__fastcall idProp_Explosive::Event_ResetContainer(
        idProp_Explosive *this,
        idEntity *result,
        idEntity *activator)
{
  if ( HIDWORD(result[8].touchTriggersQuery.index) != 0 )
  {
    HIDWORD(result[8].touchTriggersQuery.index) = 0;
    result[8].numPVSAreas = 0;
    idEntity::BecomeInactive(this: result, flags: 7);
  }
  return this;
}


// ========================================================================
// ?Damage@idProp_Explosive@@UAAMPAVidEntity@@0PBVidDeclDamage@@MABVidVec3@@PAUtrace_t@@@Z
// EA  : 0x82CA8510
// RVA : 0x00CA8510
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

float __fastcall idProp_Explosive::Damage(
        idProp_Explosive *this,
        idEntity *inflictor,
        idActor *attacker,
        const idDeclDamage *damageDef,
        double damageScale,
        const idVec3 *dir,
        trace_t *trace,
        float *a8)
{
  idProp_Explosive::bombState_t state; // r11
  bool isMelee; // r29
  double v16; // fp1

  if ( damageDef == nullptr || (damageDef->damageTypes & ~this->ignoreDamageType) != 0 )
  {
    state = this->state;
    isMelee = true;
    if ( state > BOMB_STATE_EMPTY && state < BOMB_STATE_DEAD )
    {
      if ( !this->explodeOnDamage && idActor::CastTo(c: attacker) != nullptr && damageDef != nullptr )
        isMelee = damageDef->isMelee;
      if ( !isMelee )
      {
        v16 = idProp_Moveable::Damage(this, inflictor: nullptr, attacker, damageDef, damageScale, dir, trace, a8);
        return *((float *)&v16 + 1);
      }
      if ( this->state != BOMB_STATE_DETONATE )
      {
        this->state = BOMB_STATE_DETONATE;
        idProp_Explosive::StateOn(this, state: 5u);
      }
    }
  }
  v16 = 0.0;
  return *((float *)&v16 + 1);
}


// ========================================================================
// ?Collide@idProp_Explosive@@UAA?AW4collide_t@@HAAUtrace_t@@ABVidVec3@@@Z
// EA  : 0x82CA8610
// RVA : 0x00CA8610
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

collide_t __fastcall idProp_Explosive::Collide(
        idProp_Explosive *this,
        int physId,
        trace_t *collision,
        const idVec3 *velocity)
{
  collide_t v6; // r29
  idEntity *v7; // r31

  v6 = idProp_Moveable::Collide(this, physId, collision, velocity);
  if ( this->state > BOMB_STATE_EMPTY )
  {
    v7 = gameLocal->entities.ptr[collision->c.entityNum];
    if ( ((unsigned __int8)idActor::IsTypeOf(c: v7) != 0
       || (unsigned __int8)idWorldspawn::IsTypeOf(c: v7) != 0
       || (unsigned __int8)idProp_Moveable::IsTypeOf(c: v7) != 0)
      && this->state != BOMB_STATE_DETONATE )
    {
      this->state = BOMB_STATE_DETONATE;
      idProp_Explosive::StateOn(this, state: 5u);
    }
  }
  return v6;
}


// ========================================================================
// ?ApplyImpulse@idProp_Explosive@@UAAXHHABVidVec3@@0@Z
// EA  : 0x82CA86B8
// RVA : 0x00CA86B8
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void __fastcall idProp_Explosive::ApplyImpulse(
        idProp_Explosive *this,
        int physId,
        const int bodyId,
        const idVec3 *point,
        const idVec3 *impulse)
{
  idPhysics *PhysicsForId; // r3
  idEntity *v7; // r31

  if ( this->state > BOMB_STATE_EMPTY )
  {
    PhysicsForId = idPhysics::GetPhysicsForId(physicsId_: physId);
    if ( PhysicsForId != nullptr )
      v7 = gameLocal->entities.ptr[PhysicsForId->entityNumber];
    else
      v7 = nullptr;
    if ( ((unsigned __int8)idActor::IsTypeOf(c: v7) != 0 || (unsigned __int8)idProp_Moveable::IsTypeOf(c: v7) != 0)
      && this->state != BOMB_STATE_DETONATE )
    {
      this->state = BOMB_STATE_DETONATE;
      idProp_Explosive::StateOn(this, state: 5u);
    }
  }
}


// ========================================================================
// ??0idProp_Spawnable@@QAA@XZ
// EA  : 0x82CA87D8
// RVA : 0x00CA87D8
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

idProp_Spawnable *__fastcall idProp_Spawnable::idProp_Spawnable(idProp_Spawnable *this)
{
  idProp_Moveable::idProp_Moveable(this);
  this->breakable = nullptr;
  this->activationStartTime = -1;
  this->__vftable = (idProp_Spawnable_vtbl *)&idProp_Spawnable::`vftable';
  this->breakableSound = nullptr;
  this->impactParticle = nullptr;
  idPonytail::idPonytail(this: &this->ponyTail);
  return this;
}


// ========================================================================
// __unwind$508494
// EA  : 0x82CA8844
// RVA : 0x00CA8844
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void _unwind_508494()
{
  int v0; // r12

  idProp_Moveable::~idProp_Moveable(this: *(idProp_Moveable **)(v0 - 112 + 132));
}


// ========================================================================
// ??1idProp_Spawnable@@UAA@XZ
// EA  : 0x82CA8878
// RVA : 0x00CA8878
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void __fastcall idProp_Spawnable::~idProp_Spawnable(idProp_Spawnable *this)
{
  idPonytail *p_ponyTail; // r29

  this->__vftable = (idProp_Spawnable_vtbl *)&idProp_Spawnable::`vftable';
  p_ponyTail = &this->ponyTail;
  if ( this->ponyTail.declPonytail != nullptr )
    idPonytail::Shutdown(this: &this->ponyTail);
  idPonytail::~idPonytail(this: p_ponyTail);
  idProp_Moveable::~idProp_Moveable(this);
}


// ========================================================================
// __unwind$508511
// EA  : 0x82CA88CC
// RVA : 0x00CA88CC
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void _unwind_508511()
{
  int v0; // r12

  idProp_Moveable::~idProp_Moveable(this: *(idProp_Moveable **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$508512
// EA  : 0x82CA88F4
// RVA : 0x00CA88F4
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void _unwind_508512()
{
  int v0; // r12

  idPonytail::~idPonytail(this: (idPonytail *)(*(_DWORD *)(v0 - 112 + 132) + 7016));
}


// ========================================================================
// ?Use@idProp_OnlineCollectible@@UAA_NPAVidEntity@@W4usableState_t@@@Z
// EA  : 0x82CA8920
// RVA : 0x00CA8920
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

int __fastcall idProp_OnlineCollectible::Use(idProp_OnlineCollectible *this, idPlayer *activator, __int32 usable)
{
  int v4; // r31
  idGameChallenge_Coop *ChallengeEntity; // r3
  idGameChallenge_Coop *v6; // r3

  v4 = idProp_Moveable::Use(this, activator, usable);
  if ( (_BYTE)v4 != 0 )
  {
    ChallengeEntity = (idGameChallenge_Coop *)idGameLocal::GetChallengeEntity(this: gameLocal);
    v6 = idGameChallenge_Coop::CastTo(c: ChallengeEntity);
    if ( v6 != nullptr )
      idGameChallenge_Coop::SetCollectibleFound(this: v6, ent: this, found_: true);
  }
  return v4;
}


// ========================================================================
// ??0idProp_PlayerInteraction@@QAA@XZ
// EA  : 0x82CA8998
// RVA : 0x00CA8998
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

idProp_PlayerInteraction *__fastcall idProp_PlayerInteraction::idProp_PlayerInteraction(idProp_PlayerInteraction *this)
{
  float z; // r9

  idProp_Usable::idProp_Usable(this);
  this->__vftable = (idProp_PlayerInteraction_vtbl *)&idProp_PlayerInteraction::`vftable';
  idAnimator_Channel::idAnimator_Channel(this: &this->channelAnimator);
  this->nextIdleTime = 0;
  this->idleAnimAlias.value = -1;
  this->useOnAnimAlias.value = -1;
  this->useOffAnimAlias.value = -1;
  this->useVolume.spawnId.value = 0x1FFF;
  this->shouldLockCamera = false;
  this->playerPos = vec3_origin;
  this->playerLookAtPos.x = vec3_origin.x;
  this->playerLookAtPos.y = vec3_origin.y;
  z = vec3_origin.z;
  this->itemToPickUp = nullptr;
  this->playerLookAtPos.z = z;
  return this;
}


// ========================================================================
// __unwind$508543
// EA  : 0x82CA8A74
// RVA : 0x00CA8A74
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void _unwind_508543()
{
  int v0; // r12

  idProp_Usable::~idProp_Usable(this: *(idProp_Usable **)(v0 - 112 + 132));
}


// ========================================================================
// ?completeMinigame_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82CA8AA0
// RVA : 0x00CA8AA0
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void __fastcall completeMinigame_f(const idCmdArgs *args)
{
  idPlayer *DebugPlayer; // r3
  idPlayer *v2; // r30
  int v3; // r9
  idEntity *v4; // r3
  idEntity *v5; // r31
  idPlayerHud *PlayerHud; // r3

  DebugPlayer = idGameLocal::GetDebugPlayer(this: gameLocal);
  v2 = DebugPlayer;
  if ( DebugPlayer != nullptr && idGameLocal::CheckCheats(this: gameLocal, player: DebugPlayer) )
  {
    v3 = *(_DWORD *)(idPlayer::GetPlayerHud(this: v2) + 248);
    if ( gameLocal->spawnIds.ptr[v3 & 0x1FFF] == v3 >> 13 && (v4 = gameLocal->entities.ptr[v3 & 0x1FFF]) != nullptr )
      v5 = idEntity::CastTo(c: v4);
    else
      v5 = nullptr;
    PlayerHud = (idPlayerHud *)idPlayer::GetPlayerHud(this: v2);
    idPlayerHud::SetMinigame(this: PlayerHud, ent: nullptr);
    if ( v5 != nullptr )
      idEventReceiver::PostEventMS(this: v5, ev: &EV_MinigameSuccess, time: 0);
  }
}


// ========================================================================
// ?Use@idMinigame@@UAA_NPAVidEntity@@W4usableState_t@@@Z
// EA  : 0x82CA8B78
// RVA : 0x00CA8B78
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

int __fastcall idMinigame::Use(idMinigame *this, idPlayer *user, const usableState_t usable)
{
  idPlayer *v4; // r3

  v4 = idPlayer::CastTo(c: user);
  idMinigame::StartMinigame(this, player: v4);
  return 0;
}


// ========================================================================
// ??0idProp_Secret@@QAA@XZ
// EA  : 0x82CA8BB8
// RVA : 0x00CA8BB8
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

idProp_Secret *__fastcall idProp_Secret::idProp_Secret(idProp_Secret *this)
{
  idProp_Moveable::idProp_Moveable(this);
  this->id = -1;
  this->__vftable = (idProp_Secret_vtbl *)&idProp_Secret::`vftable';
  return this;
}


// ========================================================================
// ?Use@idProp_Secret@@UAA_NPAVidEntity@@W4usableState_t@@@Z
// EA  : 0x82CA8C00
// RVA : 0x00CA8C00
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

int __fastcall idProp_Secret::Use(idProp_Secret *this, idPlayer *user, __int32 usable)
{
  idPlayerProfileGame *v4; // r3
  int id; // r4

  if ( (unsigned __int8)idProp_Moveable::Use(this, activator: user, usable) == 0 )
    return 0;
  v4 = (idPlayerProfileGame *)common->GetProfileFromMasterLocalUser(this: common);
  if ( v4 != nullptr )
  {
    id = this->id;
    if ( id >= 0 )
      idPlayerProfileGame::SetSecret(this: v4, secretId: id);
  }
  return 1;
}


// ========================================================================
// ??0idProp_CombineItem@@QAA@XZ
// EA  : 0x82CA9090
// RVA : 0x00CA9090
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

idProp_CombineItem *__fastcall idProp_CombineItem::idProp_CombineItem(idProp_CombineItem *this)
{
  idProp_Moveable::idProp_Moveable(this);
  this->combineIconSound = nullptr;
  this->__vftable = (idProp_CombineItem_vtbl *)&idProp_CombineItem::`vftable';
  this->useConstraints.angleConstraintHorizontal.value = -1.0;
  this->useConstraints.angleConstraintVertical.value = -1.0;
  this->useConstraints.useFlags = 0;
  this->useConstraints.distanceConstraint = -1.0;
  return this;
}


// ========================================================================
// ?Use@idProp_CombineItem@@UAA_NPAVidEntity@@W4usableState_t@@@Z
// EA  : 0x82CA9158
// RVA : 0x00CA9158
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

int __fastcall idProp_CombineItem::Use(idProp_CombineItem *this, idPlayer *user, __int32 usable)
{
  int v5; // r24
  idPlayer *v6; // r26
  int v7; // r29
  int v8; // r30
  int value; // r9
  idEntity *v10; // r3
  idCombiner *v11; // r31
  idCombiner *v12; // r30
  idPresentable *presentable; // r3
  int v14; // r3
  idPresentable *v15; // r3
  int v16; // r3

  v5 = idProp_Moveable::Use(this, activator: user, usable);
  if ( (_BYTE)v5 != 0 )
  {
    v6 = idPlayer::CastTo(c: user);
    if ( v6 != nullptr )
    {
      v7 = 0;
      if ( this->targets.num > 0 )
      {
        v8 = 0;
        while ( 1 )
        {
          value = this->targets.list[v8].spawnId.value;
          if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
            && (v10 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
          {
            v11 = (idCombiner *)idEntity::CastTo(c: v10);
          }
          else
          {
            v11 = nullptr;
          }
          if ( v11 != nullptr && (unsigned __int8)idCombiner::IsTypeOf(c: v11) != 0 )
            break;
          ++v7;
          ++v8;
          if ( v7 >= this->targets.num )
            goto LABEL_21;
        }
        v12 = idCombiner::CastTo(c: v11);
        presentable = v6->presentable;
        if ( presentable != nullptr )
          v14 = (int)presentable->GetPlayerInterface_2(this: presentable);
        else
          v14 = 0;
        if ( idPlayerHud::GetCombinerIndex(this: (idPlayerHud *)(v14 + 35096), ent: v12) < 0 )
        {
          v15 = v6->presentable;
          if ( v15 != nullptr )
            v16 = (int)v15->GetPlayerInterface_2(this: v15);
          else
            v16 = 0;
          idPlayerHud::AddCombiner(this: (idPlayerHud *)(v16 + 35096), ent: v12);
        }
      }
LABEL_21:
      idEntity::StartSoundShader(
        this: user,
        channel: SND_CHANNEL_ANY,
        shader: this->combineIconSound,
        soundShaderFlags: (soundShaderFlags_t)0,
        peerMask: 0xFFu);
    }
  }
  return v5;
}


// ========================================================================
// ?ModifyCrosshairInfo@idProp_CombineItem@@UBA_NPBVidEntity@@ABVidFocusTrace@@W4usableState_t@@AAVidCrosshairInfo@@@Z
// EA  : 0x82CA92D8
// RVA : 0x00CA92D8
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

int __fastcall idProp_CombineItem::ModifyCrosshairInfo(
        idProp_CombineItem *this,
        idPlayer *activator,
        const idFocusTrace *ft,
        usableState_t usable,
        idCrosshairInfo *info)
{
  int result; // r3
  const idDeclInventory *inventoryDecl; // r11

  if ( usable == USABLE_NOT_USABLE )
    return 0;
  result = idProp_Moveable::ModifyCrosshairInfo(this, activator, ft, usable, info);
  inventoryDecl = this->inventoryDecl;
  if ( inventoryDecl != nullptr )
  {
    info->icons.list->material = inventoryDecl->icon;
    info->hoverSound = this->inventoryDecl->hoverSound;
  }
  return result;
}


// ========================================================================
// ?ModifyCrosshairInfo@idPropSmartLoot@@UBA_NPBVidEntity@@ABVidFocusTrace@@W4usableState_t@@AAVidCrosshairInfo@@@Z
// EA  : 0x82CA93B8
// RVA : 0x00CA93B8
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

int __fastcall idPropSmartLoot::ModifyCrosshairInfo(
        idPropSmartLoot *this,
        idPlayer *activator,
        const idFocusTrace *ft,
        const usableState_t usable,
        idCrosshairInfo *info)
{
  idPlayer *v7; // r26
  int num; // r11
  int v9; // r27
  idStaticList<idCrosshairCustomIcon,3> *p_icons; // r30
  int v11; // r11
  int i; // ctr
  int v13; // r3
  bool canPickup; // r10
  idPickupHudInfo v16[2]; // [sp+50h] [-80h] BYREF

  if ( usable == USABLE_LOOT )
  {
    v16[0].items.num = 0;
    v16[0].items.granularity = 1;
    v16[0].items.size = 3;
    v16[0].items.list = v16[0].items.staticList;
    v7 = idPlayer::CastTo(c: activator);
    v16[0].items.memTag = 5;
    v16[0].items.listStatic = 1;
    v16[0].items.staticList[0].icon = nullptr;
    v16[0].items.staticList[0].count = 0;
    v16[0].items.staticList[0].canPickup = true;
    v16[0].items.staticList[1].icon = nullptr;
    v16[0].items.staticList[1].count = 0;
    v16[0].items.staticList[1].canPickup = true;
    v16[0].items.staticList[2].icon = nullptr;
    v16[0].items.staticList[2].count = 0;
    v16[0].items.staticList[2].canPickup = true;
    if ( !this->hasActivated )
    {
      this->hasActivated = true;
      idSmartLootComponent::Activate(this: &this->smartLootComponent, owner: this);
    }
    this->smartLootComponent.Update(this: &this->smartLootComponent, a2: this, a3: v7);
    idSmartLootComponent::GetPickupHudInfo(this: &this->smartLootComponent, user: v7, info: v16, weaponStuffOnly: false);
    num = v16[0].items.num;
    v9 = v16[0].items.num;
    if ( v16[0].items.num < 1 )
      num = 1;
    p_icons = &info->icons;
    idList<idCrosshairCustomIcon,5>::SetNum(this: &info->icons, newNum: num);
    if ( v9 > 0 )
    {
      v11 = 0;
      for ( i = v9; i != 0; --i )
      {
        p_icons->list[v11].material = v16[0].items.list[v11].icon;
        p_icons->list[v11].itemCount = v16[0].items.list[v11].count;
        v13 = (int)&p_icons->list[v11];
        canPickup = v16[0].items.list[v11++].canPickup;
        *(_BYTE *)(v13 + 8) = canPickup;
      }
    }
    if ( (v16[0].items.listStatic == 0 || v16[0].items.listStatic == 2) && v16[0].items.list != nullptr )
      idMem::Free(this: &mem, ptr: v16[0].items.list, align: ALIGN_16);
  }
  return 1;
}


// ========================================================================
// __unwind$509236
// EA  : 0x82CA953C
// RVA : 0x00CA953C
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void _unwind_509236()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 208 + 80));
}


// ========================================================================
// ??0idProp_VehicleJump@@QAA@XZ
// EA  : 0x82CA96E8
// RVA : 0x00CA96E8
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

idProp_VehicleJump *__fastcall idProp_VehicleJump::idProp_VehicleJump(idProp_VehicleJump *this)
{
  idProp_Breakable::idProp_Breakable(this);
  this->specialEvent = nullptr;
  this->__vftable = (idProp_VehicleJump_vtbl *)&idProp_VehicleJump::`vftable';
  this->xScale = 25.0;
  this->xTable = nullptr;
  this->xLength = 2.5;
  this->yTable = nullptr;
  this->yScale = 50.0;
  this->zTable = nullptr;
  this->yLength = 7.0;
  this->lastUpdateTime = 0;
  this->zScale = 100.0;
  this->hasCheckedPlayer = false;
  this->zLength = 5.0;
  this->rotateSpeed = 0.15000001;
  this->xTime = 0.0;
  this->yTime = 0.0;
  this->zTime = 0.0;
  this->angle = 0.0;
  return this;
}


// ========================================================================
// ?Think@idProp_Explosive@@UAAXXZ
// EA  : 0x82CA9828
// RVA : 0x00CA9828
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void __fastcall idProp_Explosive::Think(idProp_Explosive *this)
{
  idProp_Explosive::bombState_t state; // r11
  double v3; // fp31
  idPhysics *Physics; // r3
  const idVec3 *v5; // r3
  int y_low; // r7
  float z; // r6
  idLinkList<idActor> *next; // r11
  idActor *owner; // r30
  idLinkList<idActor> *v10; // r11
  const idSoundShader *sndTicking; // r5
  idEventArg *v12; // r3
  idEventArg *v13; // r3
  idPhysics *v14; // r3
  float *v15; // r3
  float v16; // r10
  float v17; // r9
  float v18; // r3
  double v19; // fp31
  double v20; // fp30
  double v21; // fp29
  idPhysics *v22; // r3
  const idVec3 *v23; // r3
  char v24; // r23
  int v25; // r7
  float v26; // r6
  idLinkList<idActor> *v27; // r11
  idActor *v28; // r30
  bool v29; // r6
  char IsTypeOf; // r3
  idActor *v31; // r4
  idProp_Explosive *v32; // r3
  bool v33; // zf
  idLinkList<idActor> *v34; // r11
  int i; // r28
  void **v36; // r25
  int v37; // r20
  int v38; // r24
  int v39; // r26
  idEntity *v40; // r27
  idPhysics *v41; // r3
  float *v42; // r3
  float v43; // r10
  float v44; // r9
  float v45; // r3
  idLinkList<idActor> *v46; // r11
  idVoiceEvent *v47; // r30
  idPhysics *v48; // r3
  const idVec3 *v49; // r3
  bool v50; // r6
  bool v51; // r6
  int v52; // r10
  void **v53; // r11
  idVoiceEvent_vtbl *v54; // r11
  const idVoiceEvent *IsInstantaneous; // r11
  const idSoundShader *v56; // r5
  idEventArg *v57; // r3
  idEventArg *v58; // r3
  idProp_Explosive::bombState_t v59; // r11
  idPhysics *v60; // r3
  idRenderWorld_vtbl *v61; // r30
  int v62; // r3
  idPhysics *v63; // r3
  idRenderWorld_vtbl *v64; // r30
  int v65; // r3
  idPhysics *v66; // r3
  idRenderWorld_vtbl *v67; // r30
  int v68; // r3
  idPhysics *v69; // r3
  float *v70; // r3
  float v71; // r10
  float v72; // r9
  float v73; // r3
  idPhysics *v74; // r3
  idRenderWorld_vtbl *v75; // r30
  int v76; // r3
  idPhysics *v77; // r3
  float *v78; // r3
  float v79; // r10
  float v80; // r9
  float v81; // r3
  idPhysics *v82; // r3
  idRenderWorld_vtbl *v83; // r30
  int v84; // r3
  const idVoiceEvent *v85[4]; // [sp+60h] [-150h] BYREF
  idEventArg v86; // [sp+70h] [-140h] BYREF
  idEventArg v87; // [sp+90h] [-120h] BYREF
  idEventArg v88; // [sp+B0h] [-100h] BYREF
  float v89[4]; // [sp+D0h] [-E0h] BYREF
  float v90[4]; // [sp+E0h] [-D0h] BYREF
  float v91[4]; // [sp+F0h] [-C0h] BYREF
  float v92[4]; // [sp+100h] [-B0h] BYREF

  idEntity::RunPhysics(this);
  idEntity::UpdateVisuals(this);
  state = this->state;
  if ( state == BOMB_STATE_PROXIMITY_WAIT )
  {
    if ( idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) - this->useTime > this->proximityStartDelay )
    {
      v3 = (float)(this->radiusProximityMine * this->radiusProximityMine);
      Physics = idEntity::GetPhysics(this);
      v5 = Physics->GetOrigin(this: Physics, a2: 0);
      y_low = LODWORD(v5->y);
      z = v5->z;
      *(float *)&v87.type = v5->x;
      v87.value.i = y_low;
      v87.value.v[1] = z;
      next = gameLocal->actorEntities.next;
      if ( next != nullptr && next != gameLocal->actorEntities.head )
      {
        owner = next->owner;
        if ( owner != nullptr )
        {
          while ( !idProp_Explosive::IsAIInRange(
                     this,
                     act: owner,
                     position: (const idVec3 *)&v87,
                     radiusSq: v3,
                     checkDetonation: SLOBYTE(z),
                     a6: 1) )
          {
            v10 = owner->actorNode.next;
            if ( v10 == nullptr || v10 == owner->actorNode.head )
              owner = nullptr;
            else
              owner = v10->owner;
            if ( owner == nullptr )
              goto LABEL_67;
          }
          if ( this->state != BOMB_STATE_TICKING )
          {
            sndTicking = this->sndTicking;
            this->state = BOMB_STATE_TICKING;
            idEntity::StartSoundShader(
              this,
              channel: SND_CHANNEL_WEAPON_1,
              shader: sndTicking,
              soundShaderFlags: SSF_LOOPING|SSF_NO_RANDOM_OFFSET,
              peerMask: 0xFFu);
            v12 = idEventArg::idEventArg(this: &v88, data: this);
            idEventReceiver::PostEventMS(
              this,
              ev: &EV_PreDetonate,
              time: *(_DWORD *)&v12->type,
              arg1: (const idEventArg *)LODWORD(v12->value.v[1]));
            v13 = idEventArg::idEventArg(this: &v87, data: this);
            idEventReceiver::PostEventMS(
              this,
              ev: &EV_Detonate,
              time: *(_DWORD *)&v13->type,
              arg1: (const idEventArg *)LODWORD(v13->value.v[1]));
          }
        }
      }
    }
    goto LABEL_67;
  }
  if ( state != BOMB_STATE_ATTRACTING )
    goto LABEL_67;
  if ( r_explosivesDebug.valueInteger != 0 )
  {
    v14 = idEntity::GetPhysics(this);
    v15 = (float *)v14->GetOrigin(this: v14, a2: 0);
    v16 = v15[2];
    v17 = *v15;
    v18 = v15[1];
    v89[3] = this->radiusAttract;
    v86.value.v[1] = v16;
    v89[2] = v16;
    *(float *)&v86.type = v17;
    v86.value.f = v18;
    v89[1] = v18;
    v89[0] = v17;
    clientGame->renderWorld->DebugSphere(
      this: clientGame->renderWorld,
      a2: (const idVec4 *)&idColor::colorYellow,
      a3: (const idSphere *)v89,
      a4: 36,
      a5: 0,
      a6: true);
  }
  v19 = (float)(this->radiusProximityMine * this->radiusProximityMine);
  v20 = (float)(this->radiusAttract * this->radiusAttract);
  v21 = (float)(this->radiusAIAttractOthers * this->radiusAIAttractOthers);
  v22 = idEntity::GetPhysics(this);
  v23 = v22->GetOrigin(this: v22, a2: 0);
  v24 = 0;
  v25 = LODWORD(v23->y);
  v26 = v23->z;
  *(float *)&v86.type = v23->x;
  v86.value.i = v25;
  v86.value.v[1] = v26;
  idList<idVehicleKey *,5>::idList<idVehicleKey *,5>(this: (idList<idDeclVehicleUpgrade const *,5> *)&v88);
  v27 = gameLocal->actorEntities.next;
  if ( v27 == nullptr || v27 == gameLocal->actorEntities.head )
    v28 = nullptr;
  else
    v28 = v27->owner;
  for ( v85[0] = (const idVoiceEvent *)v28; v28 != nullptr; v85[0] = (const idVoiceEvent *)v28 )
  {
    IsTypeOf = idPlayer::IsTypeOf(c: v28);
    v31 = v28;
    v33 = IsTypeOf != 0;
    v32 = this;
    if ( !v33 )
    {
      if ( !idProp_Explosive::IsAIInRange(
              this,
              act: v28,
              position: (const idVec3 *)&v86,
              radiusSq: v20,
              checkDetonation: v29,
              a6: 0) )
        goto LABEL_27;
      idList<idDeclMD6 const *,5>::AddUnique(this: (idList<idVoiceEvent const *,5> *)&v88, obj: v85);
      v31 = v28;
      v32 = this;
    }
    v24 |= idProp_Explosive::IsAIInRange(
             this: v32,
             act: v31,
             position: (const idVec3 *)&v86,
             radiusSq: v19,
             checkDetonation: v29,
             a6: 1);
LABEL_27:
    v34 = v28->actorNode.next;
    if ( v34 == nullptr || v34 == v28->actorNode.head )
      v28 = nullptr;
    else
      v28 = v34->owner;
  }
  i = v88.value.i;
  v36 = *(void ***)&v88.type;
  if ( v88.value.i != 0 )
  {
    do
    {
      v37 = i;
      v38 = 0;
      if ( i <= 0 )
        break;
      v39 = 0;
      do
      {
        v40 = (idEntity *)v36[v39];
        if ( r_explosivesDebug.valueInteger != 0 )
        {
          v41 = idEntity::GetPhysics(this: (idEntity *)v36[v39]);
          v42 = (float *)v41->GetOrigin(this: v41, a2: 0);
          v43 = *v42;
          v44 = v42[2];
          v45 = v42[1];
          v90[3] = this->radiusAIAttractOthers;
          *(float *)&v87.type = v43;
          v87.value.v[1] = v44;
          v87.value.f = v45;
          v90[0] = v43;
          v90[2] = v44;
          v90[1] = v45;
          clientGame->renderWorld->DebugSphere(
            this: clientGame->renderWorld,
            a2: (const idVec4 *)&idColor::colorBlue,
            a3: (const idSphere *)v90,
            a4: 10,
            a5: 0,
            a6: true);
        }
        v46 = gameLocal->actorEntities.next;
        if ( v46 == nullptr || v46 == gameLocal->actorEntities.head )
          v47 = nullptr;
        else
          v47 = (idVoiceEvent *)v46->owner;
        v85[0] = v47;
        if ( v47 != nullptr )
        {
          do
          {
            if ( (unsigned __int8)idPlayer::IsTypeOf(c: (idClass *)v47) == 0 )
            {
              v48 = idEntity::GetPhysics(this: v40);
              v49 = v48->GetOrigin(this: v48, a2: 0);
              if ( idProp_Explosive::IsAIInRange(
                     this,
                     act: (idActor *)v47,
                     position: v49,
                     radiusSq: v21,
                     checkDetonation: v50,
                     a6: 0) )
              {
                v52 = 0;
                if ( i <= 0 )
                  goto LABEL_50;
                v53 = v36;
                while ( *v53 != v47 )
                {
                  ++v52;
                  ++v53;
                  if ( v52 >= i )
                    goto LABEL_50;
                }
                if ( v52 < 0 )
                {
LABEL_50:
                  idList<idAnimWebBlendTree *,5>::Append(
                    this: (idList<enum encounterGroupRole_t,5> *)&v88,
                    obj: (encounterGroupRole_t *)v85);
                  i = v88.value.i;
                  v36 = *(void ***)&v88.type;
                }
                v24 |= idProp_Explosive::IsAIInRange(
                         this,
                         act: (idActor *)v47,
                         position: (const idVec3 *)&v86,
                         radiusSq: v19,
                         checkDetonation: v51,
                         a6: 1);
              }
            }
            v54 = v47[790].__vftable;
            if ( v54 == nullptr || v54 == *(idVoiceEvent_vtbl **)&v47[789].durationMS )
              IsInstantaneous = nullptr;
            else
              IsInstantaneous = (const idVoiceEvent *)v54->IsInstantaneous;
            v47 = (idVoiceEvent *)IsInstantaneous;
            v85[0] = IsInstantaneous;
          }
          while ( IsInstantaneous != nullptr );
        }
        ++v38;
        ++v39;
      }
      while ( v38 < i );
    }
    while ( v37 != i );
  }
  if ( idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) - this->useTime > this->proximityStartDelay
    && v24 != 0
    && this->state != BOMB_STATE_TICKING )
  {
    v56 = this->sndTicking;
    this->state = BOMB_STATE_TICKING;
    idEntity::StartSoundShader(
      this,
      channel: SND_CHANNEL_WEAPON_1,
      shader: v56,
      soundShaderFlags: SSF_LOOPING|SSF_NO_RANDOM_OFFSET,
      peerMask: 0xFFu);
    v57 = idEventArg::idEventArg(this: &v87, data: this);
    idEventReceiver::PostEventMS(
      this,
      ev: &EV_PreDetonate,
      time: *(_DWORD *)&v57->type,
      arg1: (const idEventArg *)LODWORD(v57->value.v[1]));
    v58 = idEventArg::idEventArg(this: &v86, data: this);
    idEventReceiver::PostEventMS(
      this,
      ev: &EV_Detonate,
      time: *(_DWORD *)&v58->type,
      arg1: (const idEventArg *)LODWORD(v58->value.v[1]));
  }
  if ( (*((_BYTE *)&v88.value.l + 11) == 0 || *((unsigned __int8 *)&v88.value.l + 11) == 2) && v36 != nullptr )
    idMem::Free(this: &mem, ptr: v36, align: ALIGN_16);
LABEL_67:
  if ( r_explosivesDebug.valueInteger != 0 )
  {
    v59 = this->state;
    if ( (unsigned int)v59 <= BOMB_STATE_DEAD )
    {
      switch ( v59 )
      {
        case BOMB_STATE_TICKING:
          v63 = idEntity::GetPhysics(this);
          v64 = clientGame->renderWorld->__vftable;
          v65 = (int)v63->GetOrigin(this: v63, a2: 0);
          ((void (__fastcall *)(idRenderWorld *, const char *, int, bool (__fastcall **)(idLobbyBackend360 *__hidden), idColor *, int, _DWORD, _DWORD, double))v64->DebugText)(
            a1: clientGame->renderWorld,
            a2: "ticking",
            a3: v65,
            a4: off_822F0000,
            a5: &idColor::colorRed,
            a6: 1,
            a7: 0,
            a8: 0,
            a9: 1.0);
          break;
        case BOMB_STATE_PROXIMITY_WAIT:
          v66 = idEntity::GetPhysics(this);
          v67 = clientGame->renderWorld->__vftable;
          v68 = (int)v66->GetOrigin(this: v66, a2: 0);
          ((void (__fastcall *)(idRenderWorld *, const char *, int, char *, idColor *, int, _DWORD, _DWORD, double))v67->DebugText)(
            a1: clientGame->renderWorld,
            a2: "proximity",
            a3: v68,
            a4: &aAvSsobjectVCom[20],
            a5: &idColor::colorRed,
            a6: 1,
            a7: 0,
            a8: 0,
            a9: 1.0);
          v69 = idEntity::GetPhysics(this);
          v70 = (float *)v69->GetOrigin(this: v69, a2: 0);
          v71 = v70[2];
          v72 = *v70;
          v73 = v70[1];
          v91[3] = this->radiusProximityMine;
          v87.value.v[1] = v71;
          *(float *)&v87.type = v72;
          v87.value.f = v73;
          v91[2] = v71;
          v91[0] = v72;
          v91[1] = v73;
          clientGame->renderWorld->DebugSphere(
            this: clientGame->renderWorld,
            a2: (const idVec4 *)&idColor::colorRed,
            a3: (const idSphere *)v91,
            a4: 20,
            a5: 0,
            a6: true);
          break;
        case BOMB_STATE_ATTRACTING:
          v74 = idEntity::GetPhysics(this);
          v75 = clientGame->renderWorld->__vftable;
          v76 = (int)v74->GetOrigin(this: v74, a2: 0);
          ((void (__fastcall *)(idRenderWorld *, const char *, int, char *, idColor *, int, _DWORD, _DWORD, double))v75->DebugText)(
            a1: clientGame->renderWorld,
            a2: "attracting",
            a3: v76,
            a4: &aAvSsobjectVCom[20],
            a5: &idColor::colorRed,
            a6: 1,
            a7: 0,
            a8: 0,
            a9: 1.0);
          v77 = idEntity::GetPhysics(this);
          v78 = (float *)v77->GetOrigin(this: v77, a2: 0);
          v79 = v78[2];
          v80 = *v78;
          v81 = v78[1];
          v92[3] = this->radiusProximityMine;
          v87.value.v[1] = v79;
          *(float *)&v87.type = v80;
          v87.value.f = v81;
          v92[2] = v79;
          v92[0] = v80;
          v92[1] = v81;
          clientGame->renderWorld->DebugSphere(
            this: clientGame->renderWorld,
            a2: (const idVec4 *)&idColor::colorRed,
            a3: (const idSphere *)v92,
            a4: 20,
            a5: 0,
            a6: true);
          break;
        case BOMB_STATE_ARMED:
          v82 = idEntity::GetPhysics(this);
          v83 = clientGame->renderWorld->__vftable;
          v84 = (int)v82->GetOrigin(this: v82, a2: 0);
          ((void (__fastcall *)(idRenderWorld *, const char *, int, bool (__fastcall **)(idLobbyBackend360 *__hidden), idColor *, int, _DWORD, _DWORD, double))v83->DebugText)(
            a1: clientGame->renderWorld,
            a2: "ARMED",
            a3: v84,
            a4: off_822F0000,
            a5: &idColor::colorRed,
            a6: 1,
            a7: 0,
            a8: 0,
            a9: 1.0);
          break;
        case BOMB_STATE_EMPTY:
          v60 = idEntity::GetPhysics(this);
          v61 = clientGame->renderWorld->__vftable;
          v62 = (int)v60->GetOrigin(this: v60, a2: 0);
          ((void (__fastcall *)(idRenderWorld *, const char *, int, void (__fastcall *)(idRenderWorld *, const char *, const idVec3 *, float, const idVec4 *, const int, const int, const bool, const bool), idColor *, int, _DWORD, _DWORD, double))v61->DebugText)(
            a1: clientGame->renderWorld,
            a2: "empty",
            a3: v62,
            a4: v61->DebugText,
            a5: &idColor::colorRed,
            a6: 1,
            a7: 0,
            a8: 0,
            a9: 1.0);
          break;
        default:
          break;
      }
    }
  }
}


// ========================================================================
// __unwind$509487
// EA  : 0x82CAA23C
// RVA : 0x00CAA23C
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void _unwind_509487()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 432 + 176));
}


// ========================================================================
// ?Use@idProp_Explosive@@UAA_NPAVidEntity@@W4usableState_t@@@Z
// EA  : 0x82CAA268
// RVA : 0x00CAA268
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

int __fastcall idProp_Explosive::Use(idProp_Explosive *this, idPlayer *activator, const usableState_t usable)
{
  idPlayer *v5; // r3
  const idDeclInventory *requiredInvDecl; // r29
  idEntity *v7; // r30
  idJobManager *v8; // r3
  idInventoryItem *JobByDecl; // r28
  idPresentable *presentable; // r29
  idInventoryCollection *v11; // r3
  idEntity *v12; // r30
  idPhysics *Physics; // r3
  const idVec3 *v14; // r3
  idPhysics *v15; // r3
  idEntity_vtbl *v16; // r29
  int v17; // r3
  idPhysics *v18; // r3
  idPhysics_vtbl *v19; // r10
  idPresentable *v20; // r3
  idPhysics *v21; // r29
  idPhysics *v22; // r28
  int GameMs; // r25
  idPresentable *v24; // r26
  const idMat3 *v25; // r29
  const idVec3 *v26; // r3
  int v27; // r3
  idProp_Explosive::propExplosiveType_t explosiveType; // r11
  idEventArg *v29; // r3
  idEventArg *v30; // r3
  idProp_ExplosivePlunger *v31; // r3
  idEventArg v33; // [sp+50h] [-80h] BYREF
  idEventArg v34[4]; // [sp+70h] [-60h] BYREF

  if ( (unsigned __int8)idPlayer::IsTypeOf(c: activator) != 0 )
  {
    v5 = idPlayer::CastTo(c: activator);
    requiredInvDecl = this->requiredInvDecl;
    v7 = v5;
    v8 = (idJobManager *)v5->GetInventory_2(this: v5);
    JobByDecl = (idInventoryItem *)idJobManager::FindJobByDecl(this: v8, jobDecl: (const idDeclJob *)requiredInvDecl);
    if ( JobByDecl != nullptr )
    {
      presentable = v7->presentable;
      if ( presentable == nullptr )
      {
        idEntity::InitPresentableInternal(this: v7);
        presentable = v7->presentable;
      }
      v11 = v7->GetInventory_2(this: v7);
      idInventoryCollection::DeleteInventoryItem(this: v11, owner: presentable, item: JobByDecl, count: 1);
      v12 = gameLocal->SpawnEntityFromDef(this: gameLocal, a2: this->attachedProp, a3: -1, a4: -1, a5: -1);
      this->containedExplosive = v12;
      if ( v12 != nullptr )
      {
        Physics = idEntity::GetPhysics(this);
        v14 = Physics->GetOrigin(this: Physics, a2: 0);
        idEntity::SetOrigin(this: v12, org: v14);
        v15 = idEntity::GetPhysics(this);
        v16 = v12->__vftable;
        v17 = (int)v15->GetAxis(this: v15, a2: 0);
        v16->SetAxis(this: v12, a2: (const idMat3 *)v17);
        if ( idEntity::GetPhysics(this: v12)->type == PHYSICS_RIGIDBODY )
        {
          v18 = idEntity::GetPhysics(this: v12);
          v19 = v18->__vftable;
          HIBYTE(v18[5].entityNumber) = HIBYTE(v18[5].entityNumber) & 0x1F | 0x20;
          ((void (*)(void))v19->PutToRest)();
        }
        idProp_Usable::SetUsable(this: (idProp_Usable *)v12, b: false);
        *(_BYTE *)&v12->flags |= 4u;
        idProp_Usable::PlayUseSound(this: (idProp_Usable *)v12);
        *(_BYTE *)&v12->flags &= ~2u;
        idEntity::BecomeInactive(this: v12, flags: 2);
        idEntity::BecomeActive(this: v12, flags: 4);
        v12[6].defaultPhysicsObj.clipModel = nullptr;
        *(float *)&v12[6].defaultPhysicsObj.collisionResidency = 0.0;
        if ( this->hideModelWhenPropAttached )
        {
          v20 = this->presentable;
          if ( v20 == nullptr )
          {
            idEntity::InitPresentableInternal(this);
            v20 = this->presentable;
          }
          v20->Hide(this: v20, a2: true);
        }
        v21 = idEntity::GetPhysics(this);
        v22 = idEntity::GetPhysics(this);
        GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        if ( this->presentable == nullptr )
          idEntity::InitPresentableInternal(this);
        v24 = this->presentable;
        v25 = v21->GetAxis(this: v21, a2: 0);
        v26 = v22->GetOrigin(this: v22, a2: 0);
        idFXManager::StartFX(this: &v24->fxManager, org: v26, axis: v25, time: GameMs, startCondition: 113);
        v27 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        explosiveType = this->explosiveType;
        this->useTime = v27;
        if ( explosiveType != PE_TIME_BOMB )
        {
          if ( explosiveType == PE_PROXIMITY_MINE )
          {
            if ( this->state != BOMB_STATE_PROXIMITY_WAIT )
              this->state = BOMB_STATE_PROXIMITY_WAIT;
          }
          else if ( explosiveType == PE_ATTRACTION_MINE )
          {
            if ( this->state != BOMB_STATE_ATTRACTING )
              this->state = BOMB_STATE_ATTRACTING;
          }
          else if ( explosiveType == PE_C4 && this->state != BOMB_STATE_ARMED )
          {
            this->state = BOMB_STATE_ARMED;
            if ( idEntityPtr<idProp_ExplosivePlunger>::operator->(this: &this->detonator) != nullptr )
            {
              v31 = idEntityPtr<idProp_ExplosivePlunger>::operator->(this: &this->detonator);
              idProp_ExplosivePlunger::PrimePlunger(this: v31, explosive: this);
            }
          }
        }
        else if ( this->state != BOMB_STATE_TICKING )
        {
          this->state = BOMB_STATE_TICKING;
          idEntity::StartSoundShader(
            this,
            channel: SND_CHANNEL_WEAPON_1,
            shader: this->sndTicking,
            soundShaderFlags: SSF_LOOPING|SSF_NO_RANDOM_OFFSET,
            peerMask: 0xFFu);
          v29 = idEventArg::idEventArg(this: &v33, data: this);
          idEventReceiver::PostEventMS(
            this,
            ev: &EV_PreDetonate,
            time: *(_DWORD *)&v29->type,
            arg1: (const idEventArg *)LODWORD(v29->value.v[1]));
          v30 = idEventArg::idEventArg(this: v34, data: this);
          idEventReceiver::PostEventMS(
            this,
            ev: &EV_Detonate,
            time: *(_DWORD *)&v30->type,
            arg1: (const idEventArg *)LODWORD(v30->value.v[1]));
        }
        idEntity::BecomeActive(this, flags: 1);
      }
    }
  }
  return 0;
}


// ========================================================================
// ?AddNeededItem@idCombiner@@QAAXPAVidEntity@@PBVidDeclInventory@@@Z
// EA  : 0x82CAA6C0
// RVA : 0x00CAA6C0
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void __fastcall idCombiner::AddNeededItem(
        idCombiner *this,
        idEntity *entity,
        const idDeclInventory *inventoryDecl,
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
        const idDeclInventory *a16)
{
  idEntityPtr<idAI2> *v19; // r3
  int num; // r9
  char v21; // r7
  int v22; // r10
  int v23; // r11

  a16 = inventoryDecl;
  v19 = idList<idEntityPtr<idAI2>,5>::Alloc(this: (idList<idEntityPtr<idAI2>,5> *)&this->neededItems);
  if ( entity != nullptr )
    v19->spawnId.value = (gameLocal->spawnIds.ptr[entity->entityNumber] << 13) | entity->entityNumber;
  else
    v19->spawnId.value = 0x1FFF;
  if ( inventoryDecl != nullptr )
  {
    num = this->neededItemsDecl.num;
    v21 = 0;
    v22 = 0;
    if ( num > 0 )
    {
      v23 = 0;
      while ( this->neededItemsDecl.list[v23] != inventoryDecl )
      {
        ++v22;
        ++v23;
        if ( v22 >= num )
          goto LABEL_11;
      }
      v21 = 1;
    }
LABEL_11:
    if ( v21 == 0 )
      idList<idAnimWebBlendTree *,5>::Append(
        this: (idList<enum encounterGroupRole_t,5> *)&this->neededItemsDecl,
        obj: (encounterGroupRole_t *)&a16);
  }
}


// ========================================================================
// ?Spawn@idProp_CombineItem@@QAAXXZ
// EA  : 0x82CAA788
// RVA : 0x00CAA788
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void __fastcall idProp_CombineItem::Spawn(idProp_CombineItem *this)
{
  int v2; // r27
  int v3; // r29
  int value; // r9
  idEntity *v5; // r3
  idCombiner *v6; // r31
  idCombiner *v7; // r3
  int v8; // r10
  int v9; // r9
  int v10; // r8
  int v11; // r7
  int v12; // r6
  bool isUsable; // r4
  int v14; // [sp+8h] [-78h]
  int v15; // [sp+Ch] [-74h]
  int v16; // [sp+10h] [-70h]
  int v17; // [sp+14h] [-6Ch]
  int v18; // [sp+18h] [-68h]
  int v19; // [sp+1Ch] [-64h]
  int v20; // [sp+20h] [-60h]
  const idDeclInventory *v21; // [sp+24h] [-5Ch]

  v2 = 0;
  if ( this->targets.num > 0 )
  {
    v3 = 0;
    do
    {
      if ( v2 < this->targets.num
        && (value = this->targets.list[v3].spawnId.value, gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13)
        && (v5 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
      {
        v6 = (idCombiner *)idEntity::CastTo(c: v5);
      }
      else
      {
        v6 = nullptr;
      }
      if ( v6 != nullptr && (unsigned __int8)idCombiner::IsTypeOf(c: v6) != 0 )
      {
        v7 = idCombiner::CastTo(c: v6);
        idCombiner::AddNeededItem(
          this: v7,
          entity: this,
          inventoryDecl: this->inventoryDecl,
          a4: v12,
          a5: v11,
          a6: v10,
          a7: v9,
          a8: v8,
          a9: v14,
          a10: v15,
          a11: v16,
          a12: v17,
          a13: v18,
          a14: v19,
          a15: v20,
          a16: v21);
      }
      ++v2;
      ++v3;
    }
    while ( v2 < this->targets.num );
  }
  isUsable = this->isUsable;
  this->noBlink = true;
  idProp_Usable::SetUsable(this, b: isUsable);
  idEntity::UpdateVisuals(this);
  if ( this->useConstraints.angleConstraintHorizontal.value != -1.0 )
    this->useConstraints.useFlags |= 1u;
  if ( this->useConstraints.angleConstraintVertical.value != -1.0 )
    this->useConstraints.useFlags |= 2u;
  if ( this->useConstraints.distanceConstraint != -1.0 )
    this->useConstraints.useFlags |= 4u;
}


// ========================================================================
// ?Think@idProp_Moveable@@UAAXXZ
// EA  : 0x82CAA8D0
// RVA : 0x00CAA8D0
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void __fastcall idProp_Moveable::Think(idProp_Moveable *this)
{
  unsigned __int64 v2; // r6
  const char *v3; // r7
  idPhysics *Physics; // r3
  idBounds *v5; // r3
  idPhysics *v6; // r3
  idPlayer *DebugPlayer; // r3
  idPlayer *v8; // r29
  const idDeclInventory *inventoryDecl; // r28
  idJobManager *v10; // r3
  idJob *JobByDecl; // r3
  int v12; // r8
  removeCond_t removeCondition; // r10
  int fadeEndTime; // r11
  idPresentable *v15; // r4
  idPresentable *presentable; // r4
  idPhysics *v17; // r3
  int GameMs; // r3
  double v19; // fp13
  idPhysics *v20; // r3
  int *v21; // r3
  float v22; // r7
  float v23; // r6
  idPhysics *v24; // r3
  int v25; // r3
  idPLog **p_pLog; // r10
  _DWORD *v27; // r11
  int i; // ctr
  idRenderModel *particleModel; // r11
  double v30; // fp13
  double v31; // fp12
  double v32; // fp0
  idRenderModel *v33; // r3
  float v34; // [sp+50h] [-80h] BYREF
  float v35; // [sp+54h] [-7Ch] BYREF
  float v36; // [sp+58h] [-78h] BYREF
  int v37; // [sp+5Ch] [-74h]
  float v38; // [sp+60h] [-70h]
  idPLogScope v39[2]; // [sp+68h] [-68h] BYREF
  float v40; // [sp+78h] [-58h]
  float v41; // [sp+84h] [-4Ch]

  RD_EventBegin(name: "idProp_Moveable::Think");
  LODWORD(v2) = "idProp_Moveable::Think";
  HIDWORD(v2) = 2;
  idPLogScope::idPLogScope(this: v39, pl: &pLog, gMask: v2, label: v3);
  if ( (unsigned __int8)idEntity::UpdateDormant(this) != 0 )
  {
LABEL_45:
    idPLogScope::~idPLogScope(this: v39);
    goto LABEL_46;
  }
  idAnimatedEntity::Think(this);
  Physics = idEntity::GetPhysics(this);
  v5 = (idBounds *)Physics->GetAbsBounds(this: Physics, a2: -1);
  idEntity::UpdatePVSAreas(this, bounds: v5);
  v6 = idEntity::GetPhysics(this);
  if ( v6->IsAtRest(this: v6) )
    idEntity::StopSound(this, channel: SND_CHANNEL_BODY2, peerMask: 0xFFu);
  if ( (*((_BYTE *)this + 5296) & 0x80) == 0 && (*((_BYTE *)this + 5296) & 0x40) == 0
    || (*((_BYTE *)this + 5296) & 0x20) != 0 )
  {
_M511465:
    removeCondition = this->removeCondition;
    if ( removeCondition != REMOVE_CONDITION_NONE )
    {
      fadeEndTime = this->fade.fadeEndTime;
      if ( fadeEndTime <= 0 )
      {
        if ( fadeEndTime == -1 )
        {
          presentable = this->presentable;
          if ( presentable == nullptr )
          {
            idEntity::InitPresentableInternal(this);
            presentable = this->presentable;
          }
          idFadeHelper::Update(this: &this->fade, presentable);
          idEventReceiver::PostEventMS(this, ev: &EV_Remove, time: 0);
        }
        else if ( removeCondition == REMOVE_CONDITION_DORMANT
               && (v17 = idEntity::GetPhysics(this), v17->IsAtRest(this: v17))
               || this->removeCondition == REMOVE_CONDITION_TIMEOUT )
        {
          if ( this->fadeTimeDelay > 0.0 )
          {
            GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
            v37 = (int)(float)(1000.0 * this->fadeTimeDelay);
            this->startFadingAtTime = v37 + GameMs;
          }
          if ( this->startFadingAtTime < 0
            || this->startFadingAtTime > idGameTimeManager::GetGameMs(
                                           this: &clientGame->gameTimeManager,
                                           type: GAMETIME_SCALED) )
          {
            if ( this->fadeTime <= 0.0 )
            {
              idEntity::BecomeInactive(this, flags: 1);
            }
            else
            {
              v19 = (float)(this->fadeTime * 1000.0);
              v34 = 0.0;
              v35 = 1.0;
              v37 = (int)v19;
              LODWORD(v36) = (int)v19;
              idProp_Moveable::Fade(this, from: &v35, to: &v34, time: (const int *)&v36);
              idEntity::BecomeActive(this, flags: 1);
            }
          }
        }
      }
      else
      {
        v15 = this->presentable;
        if ( v15 == nullptr )
        {
          idEntity::InitPresentableInternal(this);
          v15 = this->presentable;
        }
        idFadeHelper::Update(this: &this->fade, presentable: v15);
      }
    }
    if ( (unsigned __int8)idProp_Moveable::ShouldRespawn(this) != 0 )
      this->Respawn(this);
    if ( this->particleModel != nullptr
      && (unsigned __int8)Get_idCombatStage_useRelaxedChatterVO(ptr: (unsigned __int8 *)this) == 0 )
    {
      v20 = idEntity::GetPhysics(this);
      v21 = (int *)v20->GetOrigin(this: v20, a2: 0);
      v22 = *((float *)v21 + 1);
      v23 = *((float *)v21 + 2);
      v36 = *(float *)v21;
      *(float *)&v37 = v22;
      v38 = v23;
      v24 = idEntity::GetPhysics(this);
      v25 = (int)v24->GetBounds(this: v24, a2: -1);
      p_pLog = &v39[0].pLog;
      v27 = (_DWORD *)(v25 - 4);
      for ( i = 6; i != 0; --i )
        *++p_pLog = (idPLog *)*++v27;
      particleModel = this->particleModel;
      v30 = *(float *)&v37;
      v31 = v36;
      v32 = (float)((float)(v41 - v40) + v38);
      if ( !particleModel->deferredPositionInitialized || !particleModel->useDeferredPosition )
      {
        particleModel->g.origin.x = v36;
        particleModel->g.origin.y = v30;
        particleModel->g.origin.z = v32;
        LODWORD(v36) = &particleModel->g;
      }
      particleModel->deferredOrigin.x = v31;
      particleModel->deferredOrigin.y = v30;
      particleModel->deferredOrigin.z = v32;
      v33 = this->particleModel;
      LODWORD(v36) = &particleModel->deferredOrigin;
      idRenderModel::CommitThisFrame(this: v33);
    }
    goto LABEL_45;
  }
  DebugPlayer = idGameLocal::GetDebugPlayer(this: gameLocal);
  v8 = DebugPlayer;
  if ( DebugPlayer == nullptr
    || ((*((_BYTE *)this + 5296) & 0x80) == 0
     || (unsigned __int8)idGameLayerManager::ContainsItemMemory(
                           this: &DebugPlayer->gameLayerManager,
                           itemName: this->name.data) == 0)
    && ((*((_BYTE *)this + 5296) & 0x40) == 0
     || (inventoryDecl = this->inventoryDecl) == nullptr
     || (v10 = (idJobManager *)v8->GetInventory_2(this: v8),
         (JobByDecl = idJobManager::FindJobByDecl(this: v10, jobDecl: (const idDeclJob *)inventoryDecl)) == nullptr)
     || ((int (__fastcall *)(idJob *))JobByDecl->__vftable[2].dtr_idClass)(a1: JobByDecl) <= 0) )
  {
    v12 = *((_BYTE *)this + 5297) & 0x10;
    *((_BYTE *)this + 5296) |= 0x20u;
    if ( v12 != 0 )
    {
      idEntity::BecomeInactive(this, flags: 1);
      idPLogScope::~idPLogScope(this: v39);
      goto LABEL_46;
    }
    goto _M511465;
  }
  idEventReceiver::PostEventMS(this, ev: &EV_Remove, time: 0);
  idPLogScope::~idPLogScope(this: v39);
LABEL_46:
  RD_EventEnd();
}


// ========================================================================
// __unwind$511273
// EA  : 0x82CAAD8C
// RVA : 0x00CAAD8C
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void _unwind_511273()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 208 + 136));
}


// ========================================================================
// __unwind$511274
// EA  : 0x82CAADB4
// RVA : 0x00CAADB4
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void _unwind_511274()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 208 + 104));
}


// ========================================================================
// ?ApplyImpulseToTouching@idProp_Moveable@@QAAXHHABVidVec3@@0@Z
// EA  : 0x82CAADE8
// RVA : 0x00CAADE8
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

// bad sp value at call has been detected, the output may be wrong!
void __fastcall idProp_Moveable::ApplyImpulseToTouching(
        idProp_Moveable *this,
        const int physId,
        const int bodyId,
        const idVec3 *point,
        const idVec3 *impulse)
{
  __int64 v5; // r4
  idEntity *v6; // r23
  int v7; // r26
  int v8; // r5
  int v9; // r25
  const idVec3 *v10; // r6
  const idVec3 *v11; // r24
  float *v12; // r7
  float *v13; // r29
  unsigned __int64 v14; // r6
  const char *v15; // r7
  idPhysics *Physics; // r3
  const idBounds *v17; // r3
  const char *ClipModelsTouchingBounds; // r3
  idClipModel **v19; // r27
  const char *i; // r21
  int v21; // r7
  idProp_Moveable *v22; // r30
  struct idProp_Moveable *v23; // r3
  double v24; // fp13
  double v25; // fp12
  int v26; // r11
  char v27; // r11
  bool v28; // zf
  idPLog *pLog; // r29
  idPLog::logEntry_t *v30; // r30
  int v31; // r3
  __int64 totalTicks; // r11
  __int64 v33; // r9
  idVec3 v34; // [sp+50h] [-8090h] BYREF
  idPLogScope v35; // [sp+60h] [-8080h] BYREF
  idClipModel *v36[8194]; // [sp+70h] [-8070h] BYREF

  v5 = ((__int64 (*)(void))RtlCheckStack12)();
  v6 = (idEntity *)HIDWORD(v5);
  v7 = v5;
  v9 = v8;
  v11 = v10;
  v13 = v12;
  RD_EventBegin(name: "idProp_Moveable::ApplyImpulseToTouching");
  LODWORD(v14) = "idProp_Moveable::ApplyImpulseToTouching";
  HIDWORD(v14) = 2;
  idPLogScope::idPLogScope(this: &v35, pl: &::pLog, gMask: v14, label: v15);
  Physics = idEntity::GetPhysics(this: v6);
  v17 = Physics->GetAbsBounds(this: Physics, a2: -1);
  ClipModelsTouchingBounds = idClip::GetClipModelsTouchingBounds(
                               this: &clientGame->clip,
                               bounds: v17,
                               clipMask: 0x20000,
                               clipModelList: v36,
                               maxCount: (const char *)0x2000);
  if ( (int)ClipModelsTouchingBounds > 0 )
  {
    v19 = v36;
    for ( i = ClipModelsTouchingBounds; i != nullptr; --i )
    {
      v21 = 4 * ((*v19)->entityNumber + 21563);
      v22 = *(idProp_Moveable **)((char *)&gameLocal->__vftable + v21);
      if ( v22 != v6 && (*v19)->traceModels.num != 0 )
      {
        v23 = *(struct idProp_Moveable **)((char *)&gameLocal->__vftable + v21);
        v24 = v13[1];
        v25 = (float)(v13[2] * (float)0.89999998);
        v34.x = *v13 * (float)0.89999998;
        v34.z = v25;
        v34.y = (float)v24 * (float)0.89999998;
        v26 = *(_DWORD *)(v22->GetType(this: v23) + 36);
        if ( v26 < idProp_Moveable::Type.typeNum || (v28 = v26 <= idProp_Moveable::Type.lastChild, v27 = 1, !v28) )
          v27 = 0;
        if ( v27 != 0 )
          idProp_Moveable::ApplySharedImpulse(this: v22, physId: v7, bodyId: v9, point: v11, impulse: &v34);
        else
          v22->ApplyImpulse(this: v22, a2: v7, a3: v9, a4: v11, a5: &v34);
      }
      ++v19;
    }
  }
  if ( v35.logIndex >= 0 )
  {
    pLog = v35.pLog;
    v30 = &v35.pLog->logEntries.list[v35.logIndex];
    v31 = (unsigned __int64)Sys_GetClockTicks() >> 32;
    totalTicks = v30->totalTicks;
    HIDWORD(totalTicks) = v30->parent;
    LODWORD(v33) = v31 - totalTicks;
    v30->totalTicks = v33;
    pLog->lastEntry = HIDWORD(totalTicks);
  }
  RD_EventEnd();
}


// ========================================================================
// __unwind$511487
// EA  : 0x82CAAFC0
// RVA : 0x00CAAFC0
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void _unwind_511487()
{
  idRDScopedEvent *v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: v0 + 65424);
}


// ========================================================================
// __unwind$511488
// EA  : 0x82CAAFF0
// RVA : 0x00CAAFF0
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void _unwind_511488()
{
  idPLogScope *v0; // r12

  idPLogScope::~idPLogScope(this: v0 + 4080);
}


// ========================================================================
// ?ApplySharedImpulse@idProp_Moveable@@QAAXHHABVidVec3@@0@Z
// EA  : 0x82CAB018
// RVA : 0x00CAB018
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void __fastcall idProp_Moveable::ApplySharedImpulse(
        idProp_Moveable *this,
        int physId,
        int bodyId,
        const idVec3 *point,
        const idVec3 *impulse)
{
  idAnimatedEntity::ApplyImpulse(this, physId, bodyId, point, impulse);
  if ( idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) > this->nextImpulseTime )
  {
    this->nextImpulseTime = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED)
                          + 250;
    idProp_Moveable::ApplyImpulseToTouching(this, physId, bodyId, point, impulse);
  }
}


// ========================================================================
// ?ApplyImpulse@idProp_Moveable@@UAAXHHABVidVec3@@0@Z
// EA  : 0x82CAB0A0
// RVA : 0x00CAB0A0
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void __fastcall idProp_Moveable::ApplyImpulse(
        idProp_Moveable *this,
        int physId,
        int bodyId,
        const idVec3 *point,
        const idVec3 *impulse)
{
  idPhysics *PhysicsForId; // r3
  idEntity *v11; // r26

  PhysicsForId = idPhysics::GetPhysicsForId(physicsId_: physId);
  if ( PhysicsForId != nullptr )
    v11 = gameLocal->entities.ptr[PhysicsForId->entityNumber];
  else
    v11 = nullptr;
  if ( (unsigned __int8)idVehicle::IsTypeOf(c: v11) != 0 || (unsigned __int8)idProp_Moveable::IsTypeOf(c: v11) != 0 )
    idProp_Moveable::ApplySharedImpulse(this, physId, bodyId, point, impulse);
  else
    idAnimatedEntity::ApplyImpulse(this, physId, bodyId, point, impulse);
}


// ========================================================================
// ?Think@idProp_AIArmor@@UAAXXZ
// EA  : 0x82CAB158
// RVA : 0x00CAB158
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

// attributes: thunk
void __fastcall idProp_AIArmor::Think(idProp_AIArmor *this)
{
  idProp_Moveable::Think(this);
}


// ========================================================================
// ?Think@idProp_ElectricArmor@@UAAXXZ
// EA  : 0x82CAB160
// RVA : 0x00CAB160
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void __fastcall idProp_ElectricArmor::Think(idProp_ElectricArmor *this)
{
  idElectricBolt *v2; // r30
  int value; // r10
  idEntity *v4; // r3
  int v5; // r9
  idEntity *v6; // r3
  idAI2 *v7; // r3
  idAI2 *v8; // r3
  int v9; // r9
  idAnimatedEntity *v10; // r28
  idEntity *v11; // r3
  idEntity *v12; // r3
  idPhysics *Physics; // r3
  float *v14; // r3
  double v15; // fp6
  char *v16; // r10
  float *p_y; // r11
  int v18; // ctr
  double v19; // fp4
  const idIndex<short,enum invalidJointIndex_t> *v20; // r30
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idPhysics *v22; // r3
  int electricDistance; // r30
  float *v24; // r3
  __int64 v25; // r8
  idElectricBolt *electricShock; // r30
  int v27; // r3
  char v28; // r11
  int v29; // r3
  float *v30; // r7
  const idIndex<short,enum invalidJointIndex_t> *v31; // r30
  double v32; // fp6
  double v33; // fp4
  idTreeAnimator *v34; // r3
  idPhysics *v35; // r30
  int GameMs; // r3
  idElectricBolt *v37; // r28
  int v38; // r26
  double v39; // fp31
  const idVec3 *v40; // r3
  int v41; // r3
  idVec3 v42; // [sp+58h] [-88h] BYREF
  char v43; // [sp+6Ch] [-74h] BYREF
  idMat3 v44; // [sp+70h] [-70h] BYREF

  idProp_Moveable::Think(this);
  if ( this->electricPulseTime + this->startElectricTime >= idGameTimeManager::GetGameMs(
                                                              this: &clientGame->gameTimeManager,
                                                              type: GAMETIME_SCALED) )
  {
    value = this->owner.spawnId.value;
    if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
    {
      v4 = gameLocal->entities.ptr[value & 0x1FFF];
      if ( v4 != nullptr && idEntity::CastTo(c: v4) != nullptr )
      {
        v5 = this->owner.spawnId.value;
        if ( gameLocal->spawnIds.ptr[v5 & 0x1FFF] == v5 >> 13 && (v6 = gameLocal->entities.ptr[v5 & 0x1FFF]) != nullptr )
          v7 = (idAI2 *)idEntity::CastTo(c: v6);
        else
          v7 = nullptr;
        v8 = idAI2::CastTo(c: v7);
        v9 = this->owner.spawnId.value;
        v10 = v8;
        if ( gameLocal->spawnIds.ptr[v9 & 0x1FFF] == v9 >> 13 && (v11 = gameLocal->entities.ptr[v9 & 0x1FFF]) != nullptr )
          v12 = idEntity::CastTo(c: v11);
        else
          v12 = nullptr;
        Physics = idEntity::GetPhysics(this: v12);
        v14 = (float *)Physics->GetAbsBounds(this: Physics, a2: -1);
        v15 = (float)(v14[3] + *v14);
        v16 = &v43;
        p_y = &mat2_identity.mat[1].y;
        v18 = 9;
        v19 = (float)((float)(v14[1] + v14[4]) * (float)0.5);
        v42.z = (float)(v14[2] + v14[5]) * (float)0.5;
        v42.y = v19;
        v42.x = (float)v15 * (float)0.5;
        do
        {
          ++p_y;
          v16 += 4;
          *(float *)v16 = *p_y;
          --v18;
        }
        while ( v18 != 0 );
        if ( v10 != nullptr )
        {
          v20 = (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)this->OwnerJoint.value;
          TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: v10);
          idTreeAnimator::GetWorldSpaceJointTransform(
            this: TreeAnimatorFromPresentable,
            pose: (animationPose_t)0,
            jointIndex: v20,
            origin: &v42,
            axis: &v44);
          v22 = idEntity::GetPhysics(this);
          electricDistance = this->electricDistance;
          v24 = (float *)v22->GetOrigin(this: v22, a2: 0);
          LODWORD(v25) = electricDistance * electricDistance;
          if ( (float)((float)((float)(*v24 - v42.x) * (float)(*v24 - v42.x))
                     + (float)((float)((float)(v24[2] - v42.z) * (float)(v24[2] - v42.z))
                             + (float)((float)(v24[1] - v42.y) * (float)(v24[1] - v42.y)))) > (double)(float)v25 )
          {
            electricShock = this->electricShock;
            if ( electricShock != nullptr )
            {
              idElectricBolt::~idElectricBolt(this: this->electricShock);
              idMem::Free(this: &mem, ptr: electricShock, align: ALIGN_16);
            }
            this->electricShock = nullptr;
          }
        }
        if ( this->nextShockTime < idGameTimeManager::GetGameMs(
                                     this: &clientGame->gameTimeManager,
                                     type: GAMETIME_SCALED) )
        {
          if ( this->electricShock != nullptr )
          {
            if ( v10 != nullptr )
            {
              v27 = (int)v10->GetAF_2(this: v10);
              if ( *(_BYTE *)(v27 + 267) != 0 || (v28 = 0, *(_BYTE *)(v27 + 268) != 0) )
                v28 = 1;
              if ( v28 != 0 )
              {
                v29 = (int)v10->GetAF_2(this: v10);
                v30 = (float *)(*(int (__fastcall **)(int, int))(*(_DWORD *)(v29 + 288) + 44))(a1: v29 + 288, a2: -1);
                v31 = (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)this->OwnerJoint.value;
                v32 = (float)(v30[5] + v30[2]);
                v33 = (float)((float)(v30[4] + v30[1]) * (float)0.5);
                v42.x = (float)(v30[3] + *v30) * (float)0.5;
                v42.y = v33;
                v42.z = (float)v32 * (float)0.5;
                v34 = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: v10);
                idTreeAnimator::GetWorldSpaceJointTransform(
                  this: v34,
                  pose: (animationPose_t)0,
                  jointIndex: v31,
                  origin: &v42,
                  axis: &v44);
              }
            }
            v35 = idEntity::GetPhysics(this);
            GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
            v37 = this->electricShock;
            v38 = GameMs;
            v39 = RandomFloat();
            v40 = v35->GetOrigin(this: v35, a2: 0);
            idElectricBolt::StartElectricBolt(
              this: v37,
              _startTime: v38,
              _startPos: v40,
              _endPos: &v42,
              _diversity: v39);
            this->nextShockTime = this->electricShockDelay
                                + idGameTimeManager::GetGameMs(
                                    this: &clientGame->gameTimeManager,
                                    type: GAMETIME_SCALED);
          }
          this->nextShockTime = this->electricShockDelay
                              + idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        }
      }
    }
  }
  else
  {
    v2 = this->electricShock;
    if ( v2 != nullptr )
    {
      idElectricBolt::~idElectricBolt(this: this->electricShock);
      idMem::Free(this: &mem, ptr: v2, align: ALIGN_16);
      this->electricShock = nullptr;
    }
  }
  if ( this->electricShock != nullptr )
  {
    v41 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    idElectricBolt::Update(this: this->electricShock, currTime: v41);
  }
}


// ========================================================================
// ?Think@idProp_BreakableLoot@@UAAXXZ
// EA  : 0x82CAB5E0
// RVA : 0x00CAB5E0
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void __fastcall idProp_BreakableLoot::Think(idProp_BreakableLoot *this)
{
  unsigned __int64 v2; // r6
  const char *v3; // r7
  idPlayer *DebugPlayer; // r3
  int v5; // r27
  int v6; // r28
  idEntity *v7; // r29
  idPhysics *Physics; // r3
  idBounds *v9; // r3
  __int128 v10; // r9
  double v11; // fp7
  int fadeEndTime; // r11
  idPhysics *v13; // r3
  idClipModel *v14; // r3
  idPresentable *presentable; // r4
  float v16; // [sp+50h] [-80h] BYREF
  float v17; // [sp+54h] [-7Ch] BYREF
  __int64 v18; // [sp+58h] [-78h] BYREF
  idPLogScope v19[2]; // [sp+60h] [-70h] BYREF
  idEventReceiver v20[2]; // [sp+70h] [-60h] BYREF

  RD_EventBegin(name: "idProp_BreakableLoot::Think");
  LODWORD(v2) = "idProp_BreakableLoot::Think";
  HIDWORD(v2) = 2;
  idPLogScope::idPLogScope(this: v19, pl: &pLog, gMask: v2, label: v3);
  if ( (unsigned __int8)idEntity::UpdateDormant(this) != 0 )
    goto LABEL_27;
  if ( (*((_BYTE *)this + 5436) & 0x80) != 0 && (*((_BYTE *)this + 5436) & 0x40) == 0 && gameLocal != nullptr )
  {
    DebugPlayer = idGameLocal::GetDebugPlayer(this: gameLocal);
    if ( DebugPlayer != nullptr
      && (unsigned __int8)idGameLayerManager::ContainsItemMemory(
                            this: &DebugPlayer->gameLayerManager,
                            itemName: this->name.data) != 0 )
    {
      this->Hide_2(this);
      idEventReceiver::PostEventMS(this, ev: &EV_Remove, time: 0);
      v5 = 0;
      if ( this->spawnParts.num > 0 )
      {
        v6 = 0;
        do
        {
          v7 = this->spawnParts.list[v6];
          if ( v7 != nullptr )
          {
            v7->Hide_2(this: v7);
            idEventReceiver::PostEventMS(this: v7, ev: &EV_Remove, time: 0);
          }
          ++v5;
          ++v6;
        }
        while ( v5 < this->spawnParts.num );
      }
      goto LABEL_27;
    }
    *((_BYTE *)this + 5436) |= 0x40u;
  }
  if ( (this->thinkFlags & 1) != 0 )
  {
    idEntity::UpdateVisuals(this);
    if ( this->lootedTime > 0 )
    {
      Physics = idEntity::GetPhysics(this);
      v9 = (idBounds *)Physics->GetAbsBounds(this: Physics, a2: -1);
      idEntity::UpdatePVSAreas(this, bounds: v9);
    }
    if ( this->lootedTime > 0 && this->effectsDef.fadeTime > 0.0 )
    {
      LODWORD(v10) = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      DWORD2(v10) = this->lootedTime;
      v11 = (float)((float)(this->effectsDef.fadeDelay * (float)1000.0) + (float)*(__int64 *)((char *)&v10 + 4));
      v18 = *(_QWORD *)((char *)&v10 + 4);
      if ( (float)(__int64)v10 >= v11 )
      {
        fadeEndTime = this->fade.fadeEndTime;
        if ( fadeEndTime == -1 )
        {
          this->Hide_2(this);
          idEventReceiver::ProcessEvent(this: v20, result: (idEventArg *)this, ev: &EV_Remove);
        }
        else if ( fadeEndTime > 0 )
        {
          presentable = this->presentable;
          if ( presentable == nullptr )
          {
            idEntity::InitPresentableInternal(this);
            presentable = this->presentable;
          }
          idFadeHelper::Update(this: &this->fade, presentable);
        }
        else
        {
          v13 = idEntity::GetPhysics(this);
          v14 = v13->GetClipModel(this: v13, a2: 0);
          idClipModel::Unlink(this: v14);
          v16 = 0.0;
          v17 = 1.0;
          LODWORD(v18) = (int)(float)(this->effectsDef.fadeTime * (float)1000.0);
          HIDWORD(v18) = v18;
          idFadeHelper::Fade(this: &this->fade, from: &v17, to: &v16, time: (const int *)&v18, _noStippleFade: false);
        }
      }
    }
  }
LABEL_27:
  idPLogScope::~idPLogScope(this: v19);
  RD_EventEnd();
}


// ========================================================================
// __unwind$511997
// EA  : 0x82CAB8DC
// RVA : 0x00CAB8DC
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void _unwind_511997()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 208 + 132));
}


// ========================================================================
// __unwind$511998
// EA  : 0x82CAB904
// RVA : 0x00CAB904
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void _unwind_511998()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 208 + 96));
}


// ========================================================================
// ?Think@idProp_Breakable@@UAAXXZ
// EA  : 0x82CAB930
// RVA : 0x00CAB930
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void __fastcall idProp_Breakable::Think(idProp_Breakable *this)
{
  weaponStatsTag_t *statsTag; // r4
  idProp_Breakable::breakableState_t state; // r11
  idPhysics *Physics; // r3
  __int64 v5; // r9
  idPhysics *v6; // r28
  unsigned int v7; // r6
  double v8; // fp31
  int GameMsPerFrame; // r27
  int GameMs; // r30
  const idMat3 *v11; // r29
  const idDeclParticle *smokeParticle; // r31
  idRenderModelEffects *MergeBranch; // r3
  const idVec3 *v14; // r7
  int v15; // [sp+8h] [-A8h]
  int v16; // [sp+Ch] [-A4h]
  int v17; // [sp+10h] [-A0h]
  int v18; // [sp+14h] [-9Ch]
  int v19; // [sp+18h] [-98h]
  int v20; // [sp+1Ch] [-94h]
  int v21; // [sp+20h] [-90h]
  int v22; // [sp+24h] [-8Ch]
  int v23; // [sp+28h] [-88h]
  int v24; // [sp+2Ch] [-84h]
  int v25; // [sp+30h] [-80h]
  int v26; // [sp+34h] [-7Ch]
  int v27; // [sp+38h] [-78h]
  int v28; // [sp+3Ch] [-74h]
  int v29; // [sp+40h] [-70h]
  int v30; // [sp+44h] [-6Ch]
  int v31; // [sp+48h] [-68h]
  int v32; // [sp+4Ch] [-64h]
  int v33; // [sp+50h] [-60h]
  int v34[2]; // [sp+60h] [-50h] BYREF
  __int64 v35; // [sp+68h] [-48h]

  idProp_Moveable::Think(this);
  if ( this->smokeParticle != nullptr && this->smokeStartTime != 0 )
  {
    if ( this->state <= (unsigned int)DAMAGED
      && idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) > this->smokeStartTime
                                                                                                 + 5000 )
    {
      statsTag = (weaponStatsTag_t *)this->statsTag;
      v34[0] = 0;
      idGameLocal::SetCurrentStatsDamage(this: gameLocal, tag: statsTag, delayedCount: v34);
      idProp_Breakable::Break(this, activator: this, dir: (idMat3 *)&vec3_up);
      idGameLocal::WeaponFiredDone(this: gameLocal, tag: *(weaponStatsTag_t **)&this->statsTag, carryoverCount: v34[0]);
      idGameLocal::ClearCurrentStatsDamage(this: gameLocal);
    }
    state = this->state;
    if ( state == EXPLODING || state == DAMAGED )
    {
      v34[0] = -1;
      Physics = idEntity::GetPhysics(this);
      HIDWORD(v5) = 1664525;
      v6 = Physics;
      v7 = 1664525 * clientGame->random.seed;
      clientGame->random.seed = v7 + 1013904223;
      LODWORD(v5) = ((v7 + 1013904223) >> 10) & 0x7FFF;
      v35 = v5;
      v8 = (float)((float)v5 * (float)0.000030518509);
      GameMsPerFrame = idGameTimeManager::GetGameMsPerFrame(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      v11 = (const idMat3 *)v6->GetOrigin(this: v6, a2: 0);
      smokeParticle = this->smokeParticle;
      MergeBranch = (idRenderModelEffects *)idAnimator_BlendEq::InternalGetMergeBranch(this: (idAnimator_BlendEq *)clientGame);
      idRenderModelEffects::AddParticles(
        this: MergeBranch,
        particle: smokeParticle,
        systemStartTime: GameMs,
        gameMsPerFrame: GameMsPerFrame,
        diversity: v8,
        origin: v14,
        axis: v11,
        velocity: mat3_identity.mat,
        color: &vec3_origin.x,
        a10: v15,
        a11: v16,
        a12: v17,
        a13: v18,
        a14: v19,
        a15: v20,
        a16: v21,
        a17: v22,
        a18: v23,
        a19: v24,
        a20: v25,
        a21: v26,
        a22: v27,
        a23: v28,
        a24: v29,
        a25: v30,
        a26: v31,
        a27: v32,
        a28: v33,
        a29: (unsigned int *)v34);
    }
  }
}


// ========================================================================
// ?Think@idProp_VehicleJump@@UAAXXZ
// EA  : 0x82CABAF0
// RVA : 0x00CABAF0
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void __fastcall idProp_VehicleJump::Think(idProp_VehicleJump *this)
{
  unsigned __int64 v2; // r6
  const char *v3; // r7
  idPhysics *Physics; // r3
  idBounds *v5; // r3
  idSoundEmitter *SoundEmitter; // r3
  __int64 v7; // r7
  double v8; // fp30
  const idDeclTable *xTable; // r11
  char x_low; // r4
  double v11; // fp13
  double xLength; // fp0
  double v13; // fp12
  double x; // fp29
  const idDeclTable *yTable; // r11
  double v16; // fp13
  double yLength; // fp0
  double v18; // fp12
  double y; // fp31
  const idDeclTable *zTable; // r11
  double v21; // fp13
  double zLength; // fp0
  double v23; // fp12
  double z; // fp0
  double v25; // fp11
  double v26; // fp9
  idPhysics *v27; // r3
  idPresentable *presentable; // r11
  const idMat3 *v29; // r3
  idPLog **p_pLog; // r10
  _DWORD *p_z; // r11
  int i; // ctr
  double v33; // fp0
  idPhysics *v34; // r3
  idPresentable *v35; // r11
  idPlayer *DebugPlayer; // r3
  float v37; // [sp+58h] [-E8h] BYREF
  float v38; // [sp+5Ch] [-E4h]
  float v39; // [sp+60h] [-E0h]
  idVec3 v40; // [sp+68h] [-D8h]
  idPLogScope v41; // [sp+78h] [-C8h] BYREF
  _BYTE v42[48]; // [sp+80h] [-C0h] BYREF
  idRotation v43; // [sp+B0h] [-90h] BYREF

  RD_EventBegin(name: "idProp_VehicleJump::Think()");
  LODWORD(v2) = "idProp_VehicleJump::Think()";
  HIDWORD(v2) = 2;
  idPLogScope::idPLogScope(this: &v41, pl: &pLog, gMask: v2, label: v3);
  if ( (unsigned __int8)idEntity::UpdateDormant(this) != 0 )
    goto LABEL_36;
  idProp_Moveable::Think(this);
  Physics = idEntity::GetPhysics(this);
  v5 = (idBounds *)Physics->GetAbsBounds(this: Physics, a2: -1);
  idEntity::UpdatePVSAreas(this, bounds: v5);
  if ( this->sound_spawn != nullptr )
  {
    SoundEmitter = idEntity::GetSoundEmitter(this, alloc: false);
    if ( SoundEmitter != nullptr && !SoundEmitter->IsCurrentlyPlaying(this: SoundEmitter, a2: SND_CHANNEL_BODY2) )
      idEntity::StartSoundShader(
        this,
        channel: SND_CHANNEL_BODY2,
        shader: this->sound_spawn,
        soundShaderFlags: (soundShaderFlags_t)0,
        peerMask: 0xFFu);
  }
  idEntity::BecomeInactive(this, flags: 2);
  if ( (unsigned __int8)Get_idCombatStage_useRelaxedChatterVO(ptr: (unsigned __int8 *)this) == 0 )
  {
    LODWORD(v7) = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED)
                - this->lastUpdateTime;
    v8 = (float)((float)v7 * (float)0.001);
    this->lastUpdateTime = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    xTable = this->xTable;
    x_low = LOBYTE(vec3_origin.x);
    v40 = vec3_origin;
    if ( xTable != nullptr )
    {
      v11 = (float)(this->xTime + (float)v8);
      xLength = this->xLength;
      this->xTime = this->xTime + (float)v8;
      if ( v11 > xLength )
      {
        do
        {
          v13 = (float)(this->xTime - (float)xLength);
          this->xTime = this->xTime - (float)xLength;
        }
        while ( v13 > this->xLength );
      }
      x = (float)(this->xScale
                * idLookupTable::TableLookupNormalized(
                    this: xTable->table,
                    time: (float)(this->xTime / (float)xLength),
                    fastSearch: x_low));
    }
    else
    {
      x = v40.x;
    }
    yTable = this->yTable;
    if ( yTable != nullptr )
    {
      v16 = (float)((float)v8 + this->yTime);
      yLength = this->yLength;
      this->yTime = (float)v8 + this->yTime;
      if ( v16 > yLength )
      {
        do
        {
          v18 = (float)(this->yTime - (float)yLength);
          this->yTime = this->yTime - (float)yLength;
        }
        while ( v18 > this->yLength );
      }
      y = (float)(this->yScale
                * idLookupTable::TableLookupNormalized(
                    this: yTable->table,
                    time: (float)(this->yTime / (float)yLength),
                    fastSearch: x_low));
    }
    else
    {
      y = v40.y;
    }
    zTable = this->zTable;
    if ( zTable != nullptr )
    {
      v21 = (float)(this->zTime + (float)v8);
      zLength = this->zLength;
      this->zTime = this->zTime + (float)v8;
      if ( v21 > zLength )
      {
        do
        {
          v23 = (float)(this->zTime - (float)zLength);
          this->zTime = this->zTime - (float)zLength;
        }
        while ( v23 > this->zLength );
      }
      z = (float)(this->zScale
                * idLookupTable::TableLookupNormalized(
                    this: zTable->table,
                    time: (float)(this->zTime / (float)zLength),
                    fastSearch: x_low));
    }
    else
    {
      z = v40.z;
    }
    v25 = (float)(this->spawnPosition.z + (float)z);
    v26 = (float)(this->spawnPosition.y + (float)y);
    v37 = this->spawnPosition.x + (float)x;
    v39 = v25;
    v38 = v26;
    v27 = idEntity::GetPhysics(this);
    v27->SetOrigin(this: v27, a2: (const idVec3 *)&v37, a3: -1);
    presentable = this->presentable;
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      presentable = this->presentable;
    }
    presentable->origin.x = v37;
    presentable->origin.y = v38;
    presentable->origin.z = v39;
    idRotation::idRotation(this: &v43, rotationOrigin: &vec3_origin, rotationVec: &vec3_up, rotationAngle: this->angle);
    v29 = idRotation::ToMat3(this: &v43);
    p_pLog = &v41.pLog;
    p_z = (_DWORD *)&v29[-1].mat[2].z;
    for ( i = 9; i != 0; --i )
      *++p_pLog = (idPLog *)*++p_z;
    v33 = (float)(this->rotateSpeed + this->angle);
    this->angle = this->rotateSpeed + this->angle;
    if ( v33 >= 360.0 )
      this->angle = (float)v33 - (float)360.0;
    v34 = idEntity::GetPhysics(this);
    v34->SetAxis(this: v34, a2: (const idMat3 *)v42, a3: -1);
    v35 = this->presentable;
    if ( v35 == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      v35 = this->presentable;
    }
    qmemcpy(&v35->axis, v42, sizeof(v35->axis));
  }
  if ( this->hasCheckedPlayer )
    goto LABEL_36;
  this->hasCheckedPlayer = true;
  DebugPlayer = idGameLocal::GetDebugPlayer(this: gameLocal);
  if ( DebugPlayer != nullptr )
  {
    if ( idJobManager::HasSpecialEvent(this: &DebugPlayer->jobManager, specialEventDecl: this->specialEvent) )
      idEventReceiver::PostEventMS(this, ev: &EV_Remove, time: 0);
LABEL_36:
    idPLogScope::~idPLogScope(this: &v41);
    goto LABEL_37;
  }
  idLib::Warning(fmt: " no player");
  idPLogScope::~idPLogScope(this: &v41);
LABEL_37:
  RD_EventEnd();
}


// ========================================================================
// __unwind$512118
// EA  : 0x82CABFBC
// RVA : 0x00CABFBC
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void _unwind_512118()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 320 + 244));
}


// ========================================================================
// __unwind$512119
// EA  : 0x82CABFE4
// RVA : 0x00CABFE4
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void _unwind_512119()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 320 + 120));
}


// ========================================================================
// ?Think@idProp_GameStateInt@@UAAXXZ
// EA  : 0x82CAC010
// RVA : 0x00CAC010
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void __fastcall idProp_GameStateInt::Think(idProp_GameStateInt *this)
{
  const idMat3 *v2; // r3
  int *v3; // r10
  _DWORD *p_z; // r11
  int i; // ctr
  double v6; // fp0
  idPhysics *Physics; // r3
  idPresentable *presentable; // r11
  int v9; // [sp+4Ch] [-94h] BYREF
  float v10[12]; // [sp+50h] [-90h] BYREF
  idRotation v11; // [sp+80h] [-60h] BYREF

  idProp_Moveable::Think(this);
  idEntity::BecomeInactive(this, flags: 2);
  if ( (unsigned __int8)Get_idCombatStage_useRelaxedChatterVO(ptr: (unsigned __int8 *)this) == 0 )
  {
    v11.angle = this->angle;
    v11.axisValid = false;
    v11.origin.x = vec3_origin.x;
    v11.origin.y = vec3_origin.y;
    v11.origin.z = vec3_origin.z;
    v11.vec.x = 0.0;
    v11.vec.y = 0.0;
    v11.vec.z = 1.0;
    v11.axis.mat[0].x = mat3_identity.mat[0].x;
    v11.axis.mat[0].y = mat3_identity.mat[0].y;
    v11.axis.mat[0].z = mat3_identity.mat[0].z;
    v11.axis.mat[1].x = mat3_identity.mat[1].x;
    v11.axis.mat[1].y = mat3_identity.mat[1].y;
    v11.axis.mat[1].z = mat3_identity.mat[1].z;
    v11.axis.mat[2].x = mat3_identity.mat[2].x;
    v11.axis.mat[2].y = mat3_identity.mat[2].y;
    v11.axis.mat[2].z = mat3_identity.mat[2].z;
    v2 = idRotation::ToMat3(this: &v11);
    v3 = &v9;
    p_z = (_DWORD *)&v2[-1].mat[2].z;
    for ( i = 9; i != 0; --i )
      *++v3 = *++p_z;
    v6 = (float)(this->angle + (float)1.5);
    this->angle = this->angle + (float)1.5;
    if ( v6 >= 360.0 )
      this->angle = (float)v6 - (float)360.0;
    Physics = idEntity::GetPhysics(this);
    Physics->SetAxis(this: Physics, a2: (const idMat3 *)v10, a3: -1);
    presentable = this->presentable;
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      presentable = this->presentable;
    }
    qmemcpy(&presentable->axis, v10, sizeof(presentable->axis));
  }
}


// ========================================================================
// ?Think@idProp_VehiclePickup@@UAAXXZ
// EA  : 0x82CAC1D0
// RVA : 0x00CAC1D0
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void __fastcall idProp_VehiclePickup::Think(idProp_VehiclePickup *this)
{
  idVec3 *p_spawnPosition; // r29
  char v3; // r11
  idPhysics *Physics; // r3
  idPhysics *v5; // r3
  float *v6; // r3
  idPhysics *v7; // r3
  idPresentable *presentable; // r11
  double angle; // fp30
  const idMat3 *v10; // r3
  int *v11; // r10
  _DWORD *p_z; // r9
  int i; // ctr
  double TimeScale; // fp1
  double v15; // fp0
  idPhysics *v16; // r3
  idPresentable *v17; // r11
  int v18; // [sp+4Ch] [-B4h] BYREF
  float v19[12]; // [sp+50h] [-B0h] BYREF
  idRotation v20; // [sp+80h] [-80h] BYREF

  idProp_Moveable::Think(this);
  idEntity::BecomeInactive(this, flags: 2);
  if ( (unsigned __int8)Get_idCombatStage_useRelaxedChatterVO(ptr: (unsigned __int8 *)this) == 0 )
  {
    if ( this->removeTime <= 0 || this->removeTime > gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) )
    {
      this->HandleTractor(this);
      if ( this->tractored )
      {
        idEntity::RunPhysics(this);
      }
      else
      {
        p_spawnPosition = &this->spawnPosition;
        if ( this->spawnPosition.x != vec3_origin.x
          || this->spawnPosition.y != vec3_origin.y
          || (v3 = 1, this->spawnPosition.z != vec3_origin.z) )
        {
          v3 = 0;
        }
        if ( v3 != 0 )
        {
          Physics = idEntity::GetPhysics(this);
          if ( Physics->IsAtRest(this: Physics) )
          {
            v5 = idEntity::GetPhysics(this);
            v6 = (float *)v5->GetOrigin(this: v5, a2: 0);
            p_spawnPosition->x = *v6;
            this->spawnPosition.y = v6[1];
            this->spawnPosition.z = v6[2];
            this->spawnOrientation = mat3_identity;
          }
        }
        else
        {
          v7 = idEntity::GetPhysics(this);
          v7->SetOrigin(this: v7, a2: &this->spawnPosition, a3: -1);
          presentable = this->presentable;
          if ( presentable == nullptr )
          {
            idEntity::InitPresentableInternal(this);
            presentable = this->presentable;
          }
          presentable->origin.x = p_spawnPosition->x;
          presentable->origin.y = this->spawnPosition.y;
          presentable->origin.z = this->spawnPosition.z;
        }
      }
      v20.axisValid = false;
      angle = this->angle;
      v20.origin.x = vec3_origin.x;
      v20.origin.y = vec3_origin.y;
      v20.origin.z = vec3_origin.z;
      v20.vec.x = vec3_up.x;
      v20.vec.y = vec3_up.y;
      v20.angle = angle;
      v20.vec.z = vec3_up.z;
      v20.axis.mat[0].x = mat3_identity.mat[0].x;
      v20.axis.mat[0].y = mat3_identity.mat[0].y;
      v20.axis.mat[0].z = mat3_identity.mat[0].z;
      v20.axis.mat[1].x = mat3_identity.mat[1].x;
      v20.axis.mat[1].y = mat3_identity.mat[1].y;
      v20.axis.mat[1].z = mat3_identity.mat[1].z;
      v20.axis.mat[2].x = mat3_identity.mat[2].x;
      v20.axis.mat[2].y = mat3_identity.mat[2].y;
      v20.axis.mat[2].z = mat3_identity.mat[2].z;
      v10 = idRotation::ToMat3(this: &v20);
      v11 = &v18;
      p_z = (_DWORD *)&v10[-1].mat[2].z;
      for ( i = 9; i != 0; --i )
        *++v11 = *++p_z;
      TimeScale = idGameTimeManager::GetTimeScale(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      v15 = (float)((float)((float)TimeScale * (float)1.5) + this->angle);
      this->angle = (float)((float)TimeScale * (float)1.5) + this->angle;
      if ( v15 >= 360.0 )
        this->angle = (float)v15 - (float)360.0;
      v16 = idEntity::GetPhysics(this);
      v16->SetAxis(this: v16, a2: (const idMat3 *)v19, a3: -1);
      v17 = this->presentable;
      if ( v17 == nullptr )
      {
        idEntity::InitPresentableInternal(this);
        v17 = this->presentable;
      }
      qmemcpy(&v17->axis, v19, sizeof(v17->axis));
    }
    else
    {
      idEventReceiver::PostEventMS(this, ev: &EV_Remove, time: 0);
    }
  }
}


// ========================================================================
// ?UpdateDamage@idProp_Spawnable@@IAAXXZ
// EA  : 0x82CAC570
// RVA : 0x00CAC570
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void __fastcall idProp_Spawnable::UpdateDamage(idProp_Spawnable *this)
{
  unsigned __int64 v2; // r6
  const char *v3; // r7
  idPhysics *Physics; // r29
  idPhysics *v5; // r28
  idPhysics *v6; // r3
  const idVec3 *v7; // r26
  const idMat3 *v8; // r29
  const idBounds *v9; // r3
  idPhysics *v10; // r3
  idVec3 *v11; // r3
  idPhysics *v12; // r3
  idBounds *v13; // r3
  double Radius; // fp1
  idWeaponTraceManager *WeaponTraceMgr; // r3
  int v16; // r26
  int v17; // r28
  const idSpawnId *v18; // r4
  idEntity *v19; // r3
  idVehicleState **v20; // r11
  idVehicleState *v21; // r10
  const idVec3 *v22; // r4
  double valueFloat; // fp1
  const idSpawnId *v24; // r4
  idEntity *v25; // r30
  idPhysics *v26; // r29
  idPhysics *v27; // r23
  idPhysics *v28; // r3
  const idVec3 *v29; // r29
  const idMat3 *(__fastcall *GetAxis)(idPhysics *, int); // ctr
  const idMat3 *v31; // r22
  const idBounds *v32; // r3
  idPhysics *v33; // r3
  double v34; // fp31
  idPLog *pLog; // r29
  idPLog::logEntry_t *v36; // r30
  int v37; // r3
  __int64 totalTicks; // r11
  __int64 v39; // r9
  idList<idVehicleState *,5> v40; // [sp+50h] [-130h] BYREF
  idVehicleState **v41; // [sp+60h] [-120h]
  idBounds v42; // [sp+70h] [-110h] BYREF
  idPLogScope v43; // [sp+88h] [-F8h] BYREF
  float v44[4]; // [sp+90h] [-F0h] BYREF
  idBox v45; // [sp+A0h] [-E0h] BYREF
  idBox v46; // [sp+E0h] [-A0h] BYREF

  RD_EventBegin(name: "idProp_Spawnable::UpdateDamage");
  LODWORD(v2) = "idProp_Spawnable::UpdateDamage";
  HIDWORD(v2) = 2;
  idPLogScope::idPLogScope(this: &v43, pl: &::pLog, gMask: v2, label: v3);
  if ( idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) < this->activationStartTime
                                                                                               + 250 )
  {
    idPLogScope::~idPLogScope(this: &v43);
    goto LABEL_27;
  }
  Physics = idEntity::GetPhysics(this);
  v5 = idEntity::GetPhysics(this);
  v6 = idEntity::GetPhysics(this);
  v7 = v6->GetOrigin(this: v6, a2: 0);
  v8 = Physics->GetAxis(this: Physics, a2: 0);
  v9 = v5->GetBounds(this: v5, a2: -1);
  idBox::idBox(this: &v45, bounds: v9, origin: v7, axis: v8);
  v10 = idEntity::GetPhysics(this);
  v11 = (idVec3 *)v10->GetOrigin(this: v10, a2: 0);
  v42.b[0] = *v11;
  v42.b[1] = *v11;
  v12 = idEntity::GetPhysics(this);
  v13 = (idBounds *)v12->GetBounds(this: v12, a2: -1);
  Radius = idBounds::GetRadius(this: v13);
  memset(&v40, 0, 14);
  v42.b[0].x = v42.b[0].x - (float)Radius;
  *(_WORD *)&v40.memTag = 1280;
  v42.b[0].y = v42.b[0].y - (float)Radius;
  v42.b[0].z = v42.b[0].z - (float)Radius;
  v42.b[1].x = v42.b[1].x + (float)Radius;
  v42.b[1].y = v42.b[1].y + (float)Radius;
  v42.b[1].z = v42.b[1].z + (float)Radius;
  idList<idThread *,58>::Clear(this: &v40);
  WeaponTraceMgr = idClientGame::GetWeaponTraceMgr(this: clientGame);
  idWeaponTraceManager::GetCollisions(this: WeaponTraceMgr, inBounds: &v42, outTraces: &v40);
  v16 = 0;
  if ( v40.num <= 0 )
    goto LABEL_20;
  v17 = 0;
  while ( 1 )
  {
    if ( v40.list[v17 + 14] == nullptr )
      goto LABEL_15;
    v18 = (const idSpawnId *)v40.list[v17 + 12];
    v41 = &v40.list[v17];
    v19 = gameLocal->GetEntityForSpawnId(this: gameLocal, a2: v18);
    if ( (unsigned __int8)idPlayer::IsTypeOf(c: v19) == 0 )
      goto LABEL_15;
    v20 = &v40.list[v17];
    v21 = v40.list[v17 + 16];
    if ( v21 == (idVehicleState *)1 )
    {
      v22 = (const idVec3 *)v44;
      valueFloat = g_SpawnablePropShotImpulse.valueFloat;
      v44[0] = 0.0;
      v44[1] = 0.0;
      v44[2] = 1.0;
      goto LABEL_19;
    }
    if ( v21 != nullptr )
      break;
    v41 = &v40.list[v17];
    if ( idBox::LineIntersection(this: &v45, start: (const idVec3 *)v20, end: (const idVec3 *)v20 + 1) )
    {
      v22 = (const idVec3 *)&v40.list[17 * v16 + 9];
      valueFloat = g_SpawnablePropShotImpulse.valueFloat;
      goto LABEL_19;
    }
LABEL_15:
    ++v16;
    v17 += 17;
    if ( v16 >= v40.num )
      goto LABEL_20;
  }
  if ( v21 != (idVehicleState *)2 )
    goto LABEL_15;
  v24 = (const idSpawnId *)v20[13];
  v41 = &v40.list[v17];
  v25 = gameLocal->GetEntityForSpawnId(this: gameLocal, a2: v24);
  if ( v25 == nullptr )
    goto LABEL_15;
  if ( v25 == idEntity::GetBindMaster(this) )
    goto LABEL_15;
  v26 = idEntity::GetPhysics(this: v25);
  v27 = idEntity::GetPhysics(this: v25);
  v28 = v26;
  GetAxis = v26->GetAxis;
  v29 = (const idVec3 *)&v40.list[v17];
  v31 = GetAxis(this: v28, a2: 0);
  v32 = v27->GetBounds(this: v27, a2: -1);
  idBox::idBox(this: &v46, bounds: v32, origin: v29, axis: v31);
  if ( !idBox::IntersectsBox(this: &v46, a: &v45) )
    goto LABEL_15;
  v33 = idEntity::GetPhysics(this: v25);
  v34 = g_SpawnablePropShotImpulse.valueFloat;
  v22 = (const idVec3 *)v33->GetAxis(this: v33, a2: 0);
  valueFloat = v34;
LABEL_19:
  idProp_Spawnable::Break(this, dir: v22, impulse: valueFloat);
LABEL_20:
  if ( v40.listStatic == 0 || v40.listStatic == 2 )
  {
    if ( v40.list != nullptr )
      idMem::Free(this: &mem, ptr: v40.list, align: ALIGN_16);
    v40.list = nullptr;
    v40.size = 0;
  }
  v40.num = 0;
  if ( v43.logIndex >= 0 )
  {
    pLog = v43.pLog;
    v36 = &v43.pLog->logEntries.list[v43.logIndex];
    v37 = (unsigned __int64)Sys_GetClockTicks() >> 32;
    totalTicks = v36->totalTicks;
    HIDWORD(totalTicks) = v36->parent;
    LODWORD(v39) = v37 - totalTicks;
    v36->totalTicks = v39;
    pLog->lastEntry = HIDWORD(totalTicks);
  }
LABEL_27:
  RD_EventEnd();
}


// ========================================================================
// __unwind$512556
// EA  : 0x82CAC9D0
// RVA : 0x00CAC9D0
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void _unwind_512556()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 384 + 284));
}


// ========================================================================
// __unwind$512557
// EA  : 0x82CAC9F8
// RVA : 0x00CAC9F8
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void _unwind_512557()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 384 + 136));
}


// ========================================================================
// __unwind$512558
// EA  : 0x82CACA20
// RVA : 0x00CACA20
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void _unwind_512558()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 384 + 80));
}


// ========================================================================
// ?Think@idProp_Spawnable@@UAAXXZ
// EA  : 0x82CACA50
// RVA : 0x00CACA50
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void __fastcall idProp_Spawnable::Think(idProp_Spawnable *this)
{
  unsigned __int64 v2; // r6
  const char *v3; // r7
  int fadeEndTime; // r11
  idPresentable *presentable; // r4
  int v6; // [sp+50h] [-50h] BYREF
  float v7; // [sp+54h] [-4Ch] BYREF
  float v8; // [sp+58h] [-48h] BYREF
  idPLogScope v9[8]; // [sp+60h] [-40h] BYREF

  RD_EventBegin(name: "idProp_Spawnable::Think");
  LODWORD(v2) = "idProp_Spawnable::Think";
  HIDWORD(v2) = 2;
  idPLogScope::idPLogScope(this: v9, pl: &pLog, gMask: v2, label: v3);
  if ( this->activationStartTime != -1 )
  {
    idAnimatedEntity::Think(this);
    if ( idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) > this->activationStartTime
                                                                                                 + 10000 )
    {
      fadeEndTime = this->fade.fadeEndTime;
      if ( fadeEndTime <= 0 )
      {
        if ( fadeEndTime == -1 )
        {
          idProp_Spawnable::HideSpawnable(this);
        }
        else
        {
          v6 = 5000;
          v7 = 0.0;
          v8 = 1.0;
          idFadeHelper::Fade(this: &this->fade, from: &v8, to: &v7, time: &v6, _noStippleFade: false);
        }
      }
      else
      {
        presentable = this->presentable;
        if ( presentable == nullptr )
        {
          idEntity::InitPresentableInternal(this);
          presentable = this->presentable;
        }
        idFadeHelper::Update(this: &this->fade, presentable);
      }
    }
    if ( idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) > this->activationStartTime
                                                                                                 + 2000
      && idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) < this->activationStartTime
                                                                                                 + 12500 )
    {
      idProp_Spawnable::UpdateDamage(this);
    }
    if ( this->ponyTail.declPonytail != nullptr )
      idPonytail::Update(this: &this->ponyTail);
  }
  idPLogScope::~idPLogScope(this: v9);
  RD_EventEnd();
}


// ========================================================================
// __unwind$512859
// EA  : 0x82CACBC4
// RVA : 0x00CACBC4
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void _unwind_512859()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 160 + 104));
}


// ========================================================================
// __unwind$512860
// EA  : 0x82CACBEC
// RVA : 0x00CACBEC
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void _unwind_512860()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 160 + 96));
}


// ========================================================================
// ?Use@idProp_MissionPin@@UAA_NPAVidEntity@@W4usableState_t@@@Z
// EA  : 0x82CACC20
// RVA : 0x00CACC20
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

int __fastcall idProp_MissionPin::Use(idProp_MissionPin *this, idPlayer *user, const usableState_t usable)
{
  idPlayer *v5; // r3
  idPlayer *v6; // r27
  idPresentable *presentable; // r3
  idPresentablePlayer *v8; // r3
  idSWF *PlayerGui; // r26
  int index; // r25
  int v11; // r25
  idPresentable *v12; // r3
  int v13; // r3
  idSWFScriptVar v15; // [sp+50h] [-F0h] BYREF
  idSWFScriptVar v16; // [sp+58h] [-E8h] BYREF
  int entityNumber; // [sp+60h] [-E0h]
  idStaticList<idSWFScriptVar,16> v18; // [sp+70h] [-D0h] BYREF

  v5 = idPlayer::CastTo(c: user);
  v6 = v5;
  if ( v5 != nullptr )
  {
    presentable = v5->presentable;
    if ( presentable != nullptr )
      v8 = presentable->GetPlayerInterface_2(this: presentable);
    else
      v8 = nullptr;
    PlayerGui = idPresentablePlayer::GetPlayerGui(this: v8, g: GUI_SIDEMISSION);
    idSWF::Activate(this: PlayerGui, b: true);
    idStaticList<idSWFScriptVar,16>::idStaticList<idSWFScriptVar,16>(this: &v18);
    idList<idSWFScriptVar,72>::~idList<idSWFScriptVar,72>(this: &v18);
    index = this->sideChapter->displayName.index;
    v15.type = SWF_VAR_UNDEF;
    idSWFScriptVar::Free(this: &v15);
    v15.value.i = index;
    v15.type = SWF_VAR_STRINGID;
    idSWFParmList::Append(this: (idSWFParmList *)&v18, other: &v15);
    idSWFScriptVar::Free(this: &v15);
    v11 = this->sideChapter->lockedName.index;
    v16.type = SWF_VAR_UNDEF;
    idSWFScriptVar::Free(this: &v16);
    v16.value.i = v11;
    v16.type = SWF_VAR_STRINGID;
    idSWFParmList::Append(this: (idSWFParmList *)&v18, other: &v16);
    idSWFScriptVar::Free(this: &v16);
    idSWF::Invoke(this: PlayerGui, functionName: "AddSideMissionData", parms: (const idSWFParmList *)&v18);
    v12 = v6->presentable;
    if ( v12 != nullptr )
      v13 = (int)v12->GetPlayerInterface_2(this: v12);
    else
      v13 = 0;
    entityNumber = this->entityNumber;
    *(_DWORD *)(v13 + 46676) = (gameLocal->spawnIds.ptr[entityNumber] << 13) | entityNumber;
    idStaticList<idSWFScriptVar,16>::~idStaticList<idSWFScriptVar,16>(this: &v18);
    return 1;
  }
  else
  {
    idLib::Warning(fmt: "idProp_MissionPin: activated by non-player '%s'", user->name.data);
    return 0;
  }
}


// ========================================================================
// __unwind$512991
// EA  : 0x82CACD94
// RVA : 0x00CACD94
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void _unwind_512991()
{
  int v0; // r12

  idSWFParmList::~idSWFParmList(this: (idSWFParmList *)(v0 - 320 + 112));
}


// ========================================================================
// __unwind$512992
// EA  : 0x82CACDBC
// RVA : 0x00CACDBC
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void _unwind_512992()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 320 + 80));
}


// ========================================================================
// __unwind$512993
// EA  : 0x82CACDE4
// RVA : 0x00CACDE4
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void _unwind_512993()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 320 + 88));
}


// ========================================================================
// `dynamic initializer for 'r_explosivesDebug''
// EA  : 0x83377F48
// RVA : 0x01377F48
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_explosivesDebug__()
{
  idCVar::idCVar(
    this: &r_explosivesDebug,
    name: "r_explosivesDebug",
    value: "0",
    flags: 1,
    description: "draws debug geometry for idProp_Exposive based entities",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_explosivesDebug__);
}


// ========================================================================
// `dynamic initializer for 'g_droppedLootDistance''
// EA  : 0x83377FA0
// RVA : 0x01377FA0
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_droppedLootDistance__()
{
  idCVar::idCVar(
    this: &g_droppedLootDistance,
    name: "g_droppedLootDistance",
    value: "140",
    flags: 4,
    description: "max distance the lootable can be away from its owner to loot both",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_droppedLootDistance__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_tractorRange''
// EA  : 0x83377FF8
// RVA : 0x01377FF8
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_tractorRange__()
{
  idCVar::idCVar(
    this: &vehicle_tractorRange,
    name: "vehicle_tractorRange",
    value: "150",
    flags: 4,
    description: "distance of the tractor test",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_tractorRange__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_tractorInitialRate''
// EA  : 0x83378050
// RVA : 0x01378050
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_tractorInitialRate__()
{
  idCVar::idCVar(
    this: &vehicle_tractorInitialRate,
    name: "vehicle_tractorInitialRate",
    value: ".2",
    flags: 4,
    description: "starting frac along vector-to-vehicle",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_tractorInitialRate__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_tractorAccel''
// EA  : 0x833780A8
// RVA : 0x013780A8
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_tractorAccel__()
{
  idCVar::idCVar(
    this: &vehicle_tractorAccel,
    name: "vehicle_tractorAccel",
    value: ".1",
    flags: 4,
    description: "acceleration to frac along vector-to-vehicle",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_tractorAccel__);
}


// ========================================================================
// `dynamic initializer for 'g_SpawnablePropShotImpulse''
// EA  : 0x83378100
// RVA : 0x01378100
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_SpawnablePropShotImpulse__()
{
  idCVar::idCVar(
    this: &g_SpawnablePropShotImpulse,
    name: "g_SpawnablePropShotImpulse",
    value: "150",
    flags: 4,
    description: "impulse to apply when shot",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_SpawnablePropShotImpulse__);
}


// ========================================================================
// `dynamic initializer for 'completeMinigame_v''
// EA  : 0x83378158
// RVA : 0x01378158
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__completeMinigame_v__()
{
  return idCommandLink::idCommandLink(
           this: &completeMinigame_v,
           cmdName: "completeMinigame",
           function: completeMinigame_f,
           description: "completes the current minigame",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'g_secretDebug''
// EA  : 0x83378180
// RVA : 0x01378180
// PDB : w:\tech5\tungsten\game\entities\prop.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_secretDebug__()
{
  idCVar::idCVar(
    this: &g_secretDebug,
    name: "g_secretDebug",
    value: "0",
    flags: 1,
    description: "If true then print status when spawning secrets",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_secretDebug__);
}

