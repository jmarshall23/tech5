
// ========================================================================
// ?Dropped@idVehicle@@UAAXPAVidEntity@@PBVidDeclInventory@@@Z
// EA  : 0x82D1C960
// RVA : 0x00D1C960
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __fastcall idVehicle::Dropped(idVehicle *this, idEntity *user, const idDeclInventory *idecl)
{
  this->EnterVehicle(this, a2: user, a3: SEAT_MAX);
}


// ========================================================================
// ?SetMaxHealth@idVehicle@@UAAXM@Z
// EA  : 0x82D1C978
// RVA : 0x00D1C978
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __fastcall idVehicle::SetMaxHealth(idVehicle *this, double h)
{
  double health; // fp0

  health = this->health;
  this->maxHealth = h;
  if ( health > h )
    this->health = h;
}


// ========================================================================
// ?Event_GetLastDamage_Damage@idVehicle@@QAA?AVeventFloat@@XZ
// EA  : 0x82D1C990
// RVA : 0x00D1C990
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

idVehicle *__fastcall idVehicle::Event_GetLastDamage_Damage(idVehicle *this, eventFloat *result)
{
  eventFloat::eventFloat((eventFloat *)this, f: result[3937].value);
  return this;
}


// ========================================================================
// ?Event_GetHealth@idVehicle@@QAA?AVeventFloat@@XZ
// EA  : 0x82D1C9C8
// RVA : 0x00D1C9C8
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

idVehicle *__fastcall idVehicle::Event_GetHealth(idVehicle *this, eventFloat *result)
{
  eventFloat::eventFloat((eventFloat *)this, f: result[3927].value);
  return this;
}


// ========================================================================
// ?SetCurrentCameraTag@idVehicle@@SA_NH@Z
// EA  : 0x82D1CA00
// RVA : 0x00D1CA00
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

int __fastcall idVehicle::SetCurrentCameraTag(unsigned int num, bool a2)
{
  bool v2; // r4

  if ( num > 0x11 )
    return 0;
  currentVehicleCameraTag = num;
  idCVar::SetFloat(this: &vehicle_cam_fwd, newValue: vehicle_cam_info[num].fwdOfs, force: a2);
  idCVar::SetFloat(
    this: &vehicle_cam_rt,
    newValue: vehicle_cam_info[currentVehicleCameraTag].rtOfs,
    force: (const bool)&vehicle_cam_info[0].rtOfs);
  idCVar::SetFloat(this: &vehicle_cam_up, newValue: vehicle_cam_info[currentVehicleCameraTag].upOfs, force: v2);
  idCVar::SetString(this: &vehicle_cam_tag, newValue: vehicle_cam_info[currentVehicleCameraTag].tagName, force: true);
  return 1;
}


// ========================================================================
// ?GetCameraTagName@idVehicle@@SAPBDH@Z
// EA  : 0x82D1CAF0
// RVA : 0x00D1CAF0
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

const char *__fastcall idVehicle::GetCameraTagName(unsigned int num)
{
  if ( num > 0x11 )
    return "<unknown>";
  else
    return vehicle_cam_info[num].tagName;
}


// ========================================================================
// ?GetCollisionDamage@idVehicle@@QAAPBVidDeclDamage@@XZ
// EA  : 0x82D1CB28
// RVA : 0x00D1CB28
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

const idDeclDamage *__fastcall idVehicle::GetCollisionDamage(idVehicle *this)
{
  const idDeclDamage *result; // r3
  bool v3; // zf

  v3 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) < this->collisionDamageTime;
  result = nullptr;
  if ( !v3 )
    return this->collisionDamage;
  return result;
}


// ========================================================================
// ?HasAlternateEngine@idVehicle@@QAA_NXZ
// EA  : 0x82D1CCF8
// RVA : 0x00D1CCF8
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

idInventoryCollection *__fastcall idVehicle::HasAlternateEngine(idVehicle *this)
{
  idInventoryCollection *result; // r3
  const idDeclInventory *alternateEngine; // r30
  idJobManager *v4; // r3

  result = this->GetInventory_2(this);
  if ( result != nullptr )
  {
    if ( this->vehicleClass == VEHICLE_CLASS1 )
    {
      return (idInventoryCollection *)1;
    }
    else
    {
      alternateEngine = this->alternateEngine;
      if ( alternateEngine != nullptr )
      {
        v4 = (idJobManager *)this->GetInventory_2(this);
        return (idInventoryCollection *)(idJobManager::FindJobByDecl(
                                           this: v4,
                                           jobDecl: (const idDeclJob *)alternateEngine) != nullptr);
      }
      else
      {
        return nullptr;
      }
    }
  }
  return result;
}


// ========================================================================
// ?InitVehiclePhysics@idVehicle@@QAA_NXZ
// EA  : 0x82D1CD90
// RVA : 0x00D1CD90
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

int __fastcall idVehicle::InitVehiclePhysics(idVehicle *this)
{
  idPresentable *presentable; // r3
  int v3; // r3
  idPresentable *v4; // r3
  int v5; // r3
  idPresentable *v6; // r3
  int v7; // r3
  idPresentable *v8; // r3
  int v9; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
    v3 = (int)presentable->GetVehicleInterface(this: presentable);
  else
    v3 = 0;
  (*(void (__fastcall **)(int, idMat3 *, int))(*(_DWORD *)(v3 + 16512) + 52))(
    a1: v3 + 16512,
    a2: &this->spawnOrientation,
    a3: -1);
  v4 = this->presentable;
  if ( v4 != nullptr )
    v5 = (int)v4->GetVehicleInterface(this: v4);
  else
    v5 = 0;
  (*(void (__fastcall **)(int, idVec3 *, int))(*(_DWORD *)(v5 + 16512) + 48))(
    a1: v5 + 16512,
    a2: &this->spawnPosition,
    a3: -1);
  v6 = this->presentable;
  if ( v6 != nullptr )
    v7 = (int)v6->GetVehicleInterface(this: v6);
  else
    v7 = 0;
  (*(void (__fastcall **)(int))(*(_DWORD *)(v7 + 16512) + 200))(a1: v7 + 16512);
  v8 = this->presentable;
  if ( v8 != nullptr )
    v9 = (int)v8->GetVehicleInterface(this: v8);
  else
    v9 = 0;
  (*(void (__fastcall **)(int))(*(_DWORD *)(v9 + 16512) + 152))(a1: v9 + 16512);
  idEntity::UpdateVisuals(this);
  idEntity::BecomeActive(this, flags: 6);
  return 1;
}


// ========================================================================
// ?RemoveAIEvents@idVehicle@@IAAXXZ
// EA  : 0x82D1CEC0
// RVA : 0x00D1CEC0
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __fastcall idVehicle::RemoveAIEvents(idVehicle *this)
{
  idHandle<int,enum invalidAIEvent_t,-1> *eventHandles; // r31
  int i; // r27

  eventHandles = this->eventHandles;
  for ( i = 2; i != 0; --i )
  {
    if ( eventHandles->value != -1 )
    {
      idAIEventManager::RemoveEvent(this: &gameLocal->aiEventManager, handle: eventHandles);
      eventHandles->value = -1;
    }
    ++eventHandles;
  }
}


// ========================================================================
// ?HasMatchingKey@idVehicle@@QBA_NPBVidEntity@@@Z
// EA  : 0x82D1CF18
// RVA : 0x00D1CF18
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

int __fastcall idVehicle::HasMatchingKey(idVehicle *this, const idEntity *activator)
{
  idInventoryCollection *v3; // r3
  int TotalInventoryItemCount; // r3
  unsigned __int8 v5; // r11

  if ( this->keys == nullptr || vehicle_playerCanEnter.valueInteger != 0 )
    return 1;
  v3 = (idInventoryCollection *)activator->GetInventory(this: activator);
  if ( v3 == nullptr )
    return 0;
  TotalInventoryItemCount = idInventoryCollection::FindTotalInventoryItemCount(this: v3, decl: this->keys);
  v5 = 1;
  if ( TotalInventoryItemCount <= 0 )
    return 0;
  return v5;
}


// ========================================================================
// ?IsEverUsable@idVehicle@@UBA_NPBVidEntity@@@Z
// EA  : 0x82D1CFB0
// RVA : 0x00D1CFB0
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

BOOL __fastcall idVehicle::IsEverUsable(_BYTE *ptr)
{
  return (ptr[92] & 8) != 0;
}


// ========================================================================
// ?ModifyCrosshairInfo@idVehicle@@UBA_NPBVidEntity@@ABVidFocusTrace@@W4usableState_t@@AAVidCrosshairInfo@@@Z
// EA  : 0x82D1CFC0
// RVA : 0x00D1CFC0
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

int __fastcall idVehicle::ModifyCrosshairInfo(
        idVehicle *this,
        const idEntity *activator,
        const idFocusTrace *ft,
        const usableState_t usable,
        idCrosshairInfo *info)
{
  switch ( usable )
  {
    case USABLE_LOOT:
    case USABLE_RC_PICKUP:
      return 1;
    case USABLE_VEHICLE_DRIVE:
      info->icons.list->material = this->enterIcon;
      info->icons.list->usable = this->isUsable;
      if ( (unsigned __int8)idVehicle::HasMatchingKey(this, activator) != 0 )
        return 1;
      info->color = idColor::colorRed;
      info->colorState = CROSSHAIR_COLOR_NEGATIVE;
      return 0;
    case USABLE_VEHICLE_GUNNER:
      idStrId::Set(this: &info->text, key: "#str_ride");
      return 1;
    default:
      return 0;
  }
}


// ========================================================================
// ?Use@idVehicle@@UAA_NPAVidEntity@@W4usableState_t@@@Z
// EA  : 0x82D1D0E0
// RVA : 0x00D1D0E0
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

int __fastcall idVehicle::Use(idVehicle *this, idPlayer *activator, usableState_t usable)
{
  int result; // r3
  BOOL v7; // r28
  idPlayer *v8; // r3
  idPlayer *v9; // r30
  idPhysics *Physics; // r3
  const idDeclInventory *inventoryItem; // r31
  const idVec3 *v12; // r3

  if ( !this->isUsable )
    return 0;
  v7 = idEntity::Use(this, activator, usable);
  v8 = idPlayer::CastTo(c: activator);
  v9 = v8;
  switch ( usable )
  {
    case USABLE_LOOT:
      idPlayer::LootItems(this: v8, ent: this, disassemble: nullptr);
      result = 1;
      break;
    case USABLE_RC_PICKUP:
      Physics = idEntity::GetPhysics(this);
      inventoryItem = this->inventoryItem;
      v12 = Physics->GetOrigin(this: Physics, a2: 0);
      idPlayer::PickupItems(this: v9, inventoryDecl: inventoryItem, location: v12);
      result = 1;
      break;
    case USABLE_VEHICLE_DRIVE:
    case USABLE_VEHICLE_GUNNER:
      this->ActivateTargets(this, a2: v8);
      this->EnterVehicle(this, a2: v9, a3: SEAT_MAX);
      result = 1;
      break;
    default:
      result = v7;
      break;
  }
  return result;
}


// ========================================================================
// ?InventoryAdded@idVehicle@@UAAXPAVidInventoryItem@@H@Z
// EA  : 0x82D1D220
// RVA : 0x00D1D220
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __fastcall idVehicle::InventoryAdded(idVehicle *this, idInventoryItem *item, int count)
{
  idPresentable *presentable; // r3
  int v7; // r3
  int num; // r8
  int v9; // r10
  idVehicle::itemSkinRef_t *list; // r9
  int i; // r11

  presentable = this->presentable;
  if ( presentable != nullptr )
    v7 = (int)presentable->GetVehicleInterface(this: presentable);
  else
    v7 = 0;
  (*(void (__fastcall **)(int, idInventoryItem *, int, _DWORD))(*(_DWORD *)v7 + 336))(
    a1: v7,
    a2: item,
    a3: count,
    a4: 0);
  num = this->itemSkinList.num;
  v9 = 0;
  if ( num > 0 )
  {
    list = this->itemSkinList.list;
    for ( i = 0; list[i].declInventory != item->decl; ++i )
    {
      if ( ++v9 >= num )
        return;
    }
    item->skinPreload = list[v9].declSkin;
  }
}


// ========================================================================
// ?PlayerIsOccupant@idVehicle@@QBAPAVidPlayer@@XZ
// EA  : 0x82D1D2D0
// RVA : 0x00D1D2D0
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

idPlayer *__fastcall idVehicle::PlayerIsOccupant(idVehicle *this)
{
  idPresentable *presentable; // r3
  idPresentableVehicle *v2; // r3
  idPresentablePlayer *v3; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
    v2 = presentable->GetVehicleInterface(this: presentable);
  else
    v2 = nullptr;
  v3 = idPresentableVehicle::PlayerIsOccupant(this: v2);
  if ( v3 != nullptr )
    return (idPlayer *)v3->entity;
  else
    return nullptr;
}


// ========================================================================
// ?GetDriver@idVehicle@@QBAPAVidEntity@@XZ
// EA  : 0x82D1D338
// RVA : 0x00D1D338
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

idEntity *__fastcall idVehicle::GetDriver(idVehicle *this)
{
  idPresentable *presentable; // r3
  idPresentableVehicle *v2; // r3
  idPresentable *Driver; // r3

  presentable = this->presentable;
  if ( presentable != nullptr
    && (v2 = presentable->GetVehicleInterface(this: presentable)) != nullptr
    && (Driver = idPresentableVehicle::GetDriver(this: v2)) != nullptr )
  {
    return Driver->entity;
  }
  else
  {
    return nullptr;
  }
}


// ========================================================================
// ?GetGunner@idVehicle@@QBAPAVidEntity@@XZ
// EA  : 0x82D1D3A0
// RVA : 0x00D1D3A0
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

idEntity *__fastcall idVehicle::GetGunner(idVehicle *this)
{
  idPresentable *presentable; // r3
  idPresentableVehicle *v3; // r3
  idPresentable *v4; // r3
  idPresentableVehicle *v5; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
    v3 = presentable->GetVehicleInterface(this: presentable);
  else
    v3 = nullptr;
  if ( idPresentableVehicle::GetGunner(this: v3) == nullptr )
    return nullptr;
  v4 = this->presentable;
  if ( v4 == nullptr )
    return idPresentableVehicle::GetGunner(this: nullptr)->entity;
  v5 = v4->GetVehicleInterface(this: v4);
  return idPresentableVehicle::GetGunner(this: v5)->entity;
}


// ========================================================================
// ?UpdateEventInstigators@idVehicle@@AAAXXZ
// EA  : 0x82D1D458
// RVA : 0x00D1D458
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __fastcall idVehicle::UpdateEventInstigators(idVehicle *this)
{
  idPresentable *presentable; // r3
  idPresentableVehicle *v3; // r3
  idPlayer *entity; // r29
  idPresentable *Driver; // r3
  idHandle<int,enum invalidAIEvent_t,-1> *eventHandles; // r31
  int i; // r27

  presentable = this->presentable;
  if ( presentable != nullptr && (v3 = presentable->GetVehicleInterface(this: presentable)) != nullptr )
  {
    Driver = idPresentableVehicle::GetDriver(this: v3);
    entity = nullptr;
    if ( Driver != nullptr )
      entity = (idPlayer *)Driver->entity;
  }
  else
  {
    entity = nullptr;
  }
  if ( idPlayer::CastTo(c: entity) == nullptr && idAI2::CastTo(c: (idAI2 *)entity) == nullptr )
    entity = (idPlayer *)this;
  eventHandles = this->eventHandles;
  for ( i = 2; i != 0; --i )
  {
    if ( eventHandles->value != -1 )
      idAIEventManager::SetEventInstigator(this: &gameLocal->aiEventManager, handle: eventHandles, instigator: entity);
    ++eventHandles;
  }
}


// ========================================================================
// ?GetNumSpikesNearPos@idVehicle@@QAAHVidVec3@@PAPAVidInventoryItem@@1@Z
// EA  : 0x82D1D518
// RVA : 0x00D1D518
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __fastcall idVehicle::GetNumSpikesNearPos(
        idVehicle *this,
        idVec3 *pos,
        idInventoryItem **spike1,
        idJob **spike2,
        idJob **a5)
{
  int v5; // r3
  int v6; // r31
  int v9; // r28
  idEntity *v10; // r3
  idPhysics *Physics; // r3
  float *v12; // r3
  double v13; // fp31
  double v14; // fp30
  double v15; // fp29
  idPhysics *v16; // r3
  float *v17; // r3
  idJob *JobByDecl; // r30
  int v19; // r11
  const idDeclJob *v20; // r30
  idJobManager *v21; // r3
  int v22; // r11
  idJob *v23; // r3
  const idDeclJob *v24; // r26
  idJobManager *v25; // r3
  bool v26; // r11
  bool v27; // r10
  bool v28; // r11
  int v29; // r11
  const idDeclJob *v30; // r30
  idJobManager *v31; // r3
  int v32; // r11
  const idDeclJob *v33; // r26
  idJobManager *v34; // r3
  bool v35; // r11
  __int64 v37; // [sp+C0h] [+20h]

  v37 = *(_QWORD *)&pos;
  v6 = v5;
  if ( vehicle_tireUpgrades.valueInteger == 1
    || vehicle_tireUpgrades.valueInteger == 3
    || vehicle_tireUpgrades.valueInteger == 4
    || vehicle_tireUpgrades.valueInteger == 6 )
  {
    return 2;
  }
  v9 = 0;
  Physics = idEntity::GetPhysics(this: v10);
  v12 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
  v13 = (float)(*(float *)&v37 - *v12);
  v14 = (float)(*((float *)&v37 + 1) - v12[1]);
  v15 = (float)(*(float *)&pos - v12[2]);
  v16 = idEntity::GetPhysics(this: (idEntity *)v6);
  v17 = (float *)v16->GetAxis(this: v16, a2: 0);
  JobByDecl = nullptr;
  if ( (float)((float)(v17[3] * (float)v13) + (float)((float)(v17[5] * (float)v15) + (float)(v17[4] * (float)v14))) >= 0.0 )
  {
    v29 = *(_DWORD *)(v6 + 15884);
    if ( v29 >= 0 )
    {
      v30 = *(const idDeclJob **)(124 * v29 + *(_DWORD *)(v6 + 5220));
      v31 = (idJobManager *)(*(int (__fastcall **)(int))(*(_DWORD *)v6 + 468))(a1: v6);
      JobByDecl = idJobManager::FindJobByDecl(this: v31, jobDecl: v30);
    }
    v32 = *(_DWORD *)(v6 + 15892);
    v23 = nullptr;
    if ( v32 >= 0 )
    {
      v33 = *(const idDeclJob **)(124 * v32 + *(_DWORD *)(v6 + 5220));
      v34 = (idJobManager *)(*(int (__fastcall **)(int))(*(_DWORD *)v6 + 468))(a1: v6);
      v23 = idJobManager::FindJobByDecl(this: v34, jobDecl: v33);
    }
    v35 = *(int *)(v6 + 15888) >= 0 && JobByDecl != nullptr;
    v27 = v35;
    if ( *(int *)(v6 + 15896) >= 0 )
    {
      v28 = v23 != nullptr;
      goto LABEL_25;
    }
LABEL_24:
    v28 = false;
    goto LABEL_25;
  }
  v19 = *(_DWORD *)(v6 + 15888);
  if ( v19 >= 0 )
  {
    v20 = *(const idDeclJob **)(124 * v19 + *(_DWORD *)(v6 + 5220));
    v21 = (idJobManager *)(*(int (__fastcall **)(int))(*(_DWORD *)v6 + 468))(a1: v6);
    JobByDecl = idJobManager::FindJobByDecl(this: v21, jobDecl: v20);
  }
  v22 = *(_DWORD *)(v6 + 15896);
  v23 = nullptr;
  if ( v22 >= 0 )
  {
    v24 = *(const idDeclJob **)(124 * v22 + *(_DWORD *)(v6 + 5220));
    v25 = (idJobManager *)(*(int (__fastcall **)(int))(*(_DWORD *)v6 + 468))(a1: v6);
    v23 = idJobManager::FindJobByDecl(this: v25, jobDecl: v24);
  }
  v26 = *(int *)(v6 + 15884) >= 0 && JobByDecl != nullptr;
  v27 = v26;
  if ( *(int *)(v6 + 15892) < 0 )
    goto LABEL_24;
  v28 = v23 != nullptr;
LABEL_25:
  if ( v27 )
  {
    if ( spike2 != nullptr )
      *spike2 = JobByDecl;
    v9 = 1;
  }
  if ( v28 )
  {
    if ( a5 != nullptr )
      *a5 = v23;
    ++v9;
  }
  return v9;
}


// ========================================================================
// ?GetNumActiveOccupants@idVehicle@@QBAHXZ
// EA  : 0x82D1D7C0
// RVA : 0x00D1D7C0
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

int __fastcall idVehicle::GetNumActiveOccupants(idVehicle *this)
{
  idPresentable *presentable; // r3
  idPresentableVehicle *v2; // r3

  presentable = this->presentable;
  if ( presentable == nullptr )
    return idPresentableVehicle::GetNumActiveOccupants(this: nullptr);
  v2 = presentable->GetVehicleInterface(this: presentable);
  return idPresentableVehicle::GetNumActiveOccupants(this: v2);
}


// ========================================================================
// ?TransformDetachable@idVehicle@@QAAXH@Z
// EA  : 0x82D1D818
// RVA : 0x00D1D818
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __fastcall idVehicle::TransformDetachable(idVehicle *this, int index)
{
  int v3; // r29
  detachable_t *v4; // r31
  detachable_t *v5; // r31
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idPhysics *Physics; // r3
  detachable_t *v8; // r31
  float *v9; // r3
  idPhysics *v10; // r3
  float *v11; // r31
  float *v12; // r3

  v3 = index;
  v4 = &this->detachableItems.list[index];
  if ( v4->transformFrame < idAccolade::Count(this: &clientGame->gameTimeManager) )
  {
    v5 = &this->detachableItems.list[v3];
    TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
    if ( (unsigned __int8)idTreeAnimator::GetWorldSpaceTagTransform(
                            this: TreeAnimatorFromPresentable,
                            tagData: &v5->tagData,
                            origin: &v5->origin,
                            axis: &v5->axis) == 0 )
    {
      Physics = idEntity::GetPhysics(this);
      v8 = &this->detachableItems.list[v3];
      v9 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
      v8->origin.x = *v9;
      v8->origin.y = v9[1];
      v8->origin.z = v9[2];
      v10 = idEntity::GetPhysics(this);
      v11 = (float *)&this->detachableItems.list[v3];
      v12 = (float *)v10->GetAxis(this: v10, a2: 0);
      v11[21] = *v12;
      v11[22] = v12[1];
      v11[23] = v12[2];
      v11[24] = v12[3];
      v11[25] = v12[4];
      v11[26] = v12[5];
      v11[27] = v12[6];
      v11[28] = v12[7];
      v11[29] = v12[8];
    }
    this->detachableItems.list[v3].transformFrame = idAccolade::Count(this: &clientGame->gameTimeManager);
  }
}


// ========================================================================
// ?GetDetachableWorldTransform@idVehicle@@QAAXPBVidDeclInventory@@AAVidVec3@@AAVidMat3@@@Z
// EA  : 0x82D1D958
// RVA : 0x00D1D958
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __fastcall idVehicle::GetDetachableWorldTransform(
        idVehicle *this,
        const idDeclInventory *declInventory,
        idVec3 *worldOrigin,
        idMat3 *worldAxis)
{
  int num; // r9
  int v8; // r11
  int v9; // r10
  idPhysics *Physics; // r3
  float *v11; // r3
  idPhysics *v12; // r3
  float *v13; // r3

  num = this->detachableItems.num;
  v8 = 0;
  if ( num <= 0 )
  {
LABEL_5:
    Physics = idEntity::GetPhysics(this);
    v11 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
    worldOrigin->x = *v11;
    worldOrigin->y = v11[1];
    worldOrigin->z = v11[2];
    v12 = idEntity::GetPhysics(this);
    v13 = (float *)v12->GetAxis(this: v12, a2: 0);
    worldAxis->mat[0].x = *v13;
    worldAxis->mat[0].y = v13[1];
    worldAxis->mat[0].z = v13[2];
    worldAxis->mat[1].x = v13[3];
    worldAxis->mat[1].y = v13[4];
    worldAxis->mat[1].z = v13[5];
    worldAxis->mat[2].x = v13[6];
    worldAxis->mat[2].y = v13[7];
    worldAxis->mat[2].z = v13[8];
  }
  else
  {
    v9 = 0;
    while ( this->detachableItems.list[v9].decl != declInventory )
    {
      ++v8;
      ++v9;
      if ( v8 >= num )
        goto LABEL_5;
    }
    *worldOrigin = this->detachableItems.list[v8].origin;
    *worldAxis = this->detachableItems.list[v8].axis;
  }
}


// ========================================================================
// ?UpdateWeapons@idVehicle@@QAAXXZ
// EA  : 0x82D1DAD0
// RVA : 0x00D1DAD0
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __fastcall idVehicle::UpdateWeapons(idVehicle *this)
{
  idPresentable *presentable; // r3
  idPresentableVehicle *v2; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
  {
    v2 = presentable->GetVehicleInterface(this: presentable);
    idPresentableVehicle::UpdateWeapons(this: v2);
  }
  else
  {
    idPresentableVehicle::UpdateWeapons(this: nullptr);
  }
}


// ========================================================================
// ?DamageFeedback@idVehicle@@UAAXPAVidEntity@@0PBVidDeclDamage@@AAM@Z
// EA  : 0x82D1DB28
// RVA : 0x00D1DB28
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __fastcall idVehicle::DamageFeedback(
        idVehicle *this,
        idEntity *victim,
        idEntity *inflictor,
        const idDeclDamage *damageDef,
        float *damage)
{
  idPresentable *presentable; // r3
  bool v9; // r30
  idPresentable *v10; // r31
  idPresentable *v11; // r3
  idPresentablePlayer *v12; // r3
  int v13; // r31

  if ( victim != nullptr && damageDef != nullptr )
  {
    if ( common->IsMultiplayer(this: common) )
    {
      if ( idVehicle::PlayerIsOccupant(this) != nullptr )
      {
        presentable = idVehicle::PlayerIsOccupant(this)->presentable;
        if ( presentable != nullptr && presentable->GetPlayerInterface_2(this: presentable) != nullptr )
        {
          v9 = damageDef->radius <= 0.0;
          if ( victim->presentable == nullptr )
            idEntity::InitPresentableInternal(this: victim);
          v10 = victim->presentable;
          v11 = idVehicle::PlayerIsOccupant(this)->presentable;
          if ( v11 != nullptr )
          {
            v12 = v11->GetPlayerInterface_2(this: v11);
            idPresentablePlayer::DamageDealtFeedback(this: v12, victim: v10, predicted: v9);
          }
          else
          {
            idPresentablePlayer::DamageDealtFeedback(this: nullptr, victim: v10, predicted: v9);
          }
        }
      }
    }
    else if ( (unsigned __int8)idActor::IsTypeOf(c: victim) != 0 || (unsigned __int8)idVehicle::IsTypeOf(c: victim) != 0 )
    {
      v13 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) + 250;
      idVehicle::GetCrosshair(this)->flashTime = v13;
    }
  }
}


// ========================================================================
// ?ZoomIn@idVehicle@@UAA_NXZ
// EA  : 0x82D1DC98
// RVA : 0x00D1DC98
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

BOOL __fastcall idVehicle::ZoomIn(idVehicle *this)
{
  double zoom_fov_x; // fp12
  double v2; // fp0
  double valueFloat; // fp13

  zoom_fov_x = this->zoom_fov_x;
  v2 = (float)(this->zoom_fov_x - (float)1.0);
  valueFloat = vehicle_maxZoomFOV.valueFloat;
  if ( v2 < vehicle_maxZoomFOV.valueFloat || (valueFloat = vehicle_baseFOV.valueFloat, v2 > vehicle_baseFOV.valueFloat) )
    v2 = valueFloat;
  this->zoom_fov_x = v2;
  return zoom_fov_x != v2;
}


// ========================================================================
// ?ZoomOut@idVehicle@@UAA_NXZ
// EA  : 0x82D1DCF0
// RVA : 0x00D1DCF0
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

BOOL __fastcall idVehicle::ZoomOut(idVehicle *this)
{
  double zoom_fov_x; // fp12
  double v2; // fp0
  double valueFloat; // fp13

  zoom_fov_x = this->zoom_fov_x;
  v2 = (float)(this->zoom_fov_x + (float)1.0);
  valueFloat = vehicle_maxZoomFOV.valueFloat;
  if ( v2 < vehicle_maxZoomFOV.valueFloat || (valueFloat = vehicle_baseFOV.valueFloat, v2 > vehicle_baseFOV.valueFloat) )
    v2 = valueFloat;
  this->zoom_fov_x = v2;
  return zoom_fov_x != v2;
}


// ========================================================================
// ?Draw@idVehicle@@UAA_NPAVidPlayer@@@Z
// EA  : 0x82D1DD48
// RVA : 0x00D1DD48
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

BOOL __fastcall idVehicle::Draw(idVehicle *this, idPlayer *player)
{
  idPresentable *presentable; // r3
  int v4; // r31
  idPresentable *v5; // r3
  int v6; // r4

  presentable = this->presentable;
  if ( presentable != nullptr )
    v4 = (int)presentable->GetVehicleInterface(this: presentable);
  else
    v4 = 0;
  v5 = player->presentable;
  if ( v5 != nullptr )
    v6 = (int)v5->GetPlayerInterface_2(this: v5);
  else
    v6 = 0;
  return (*(bool (__fastcall **)(int, int))(*(_DWORD *)v4 + 56))(a1: v4, a2: v6);
}


// ========================================================================
// ?GetDriverView@idVehicle@@QAAXAAVidVec3@@AAVidMat3@@AAMAAVidView@@@Z
// EA  : 0x82D1DDE0
// RVA : 0x00D1DDE0
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __fastcall idVehicle::GetDriverView(idVehicle *this, idVec3 *origin, idMat3 *axis, float *fov_x, idView *view)
{
  idPresentable *presentable; // r3
  idPresentableVehicle *v10; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
    v10 = presentable->GetVehicleInterface(this: presentable);
  else
    v10 = nullptr;
  idPresentableVehicle::GetDriverView(this: v10, origin, axis, fov_x, view);
}


// ========================================================================
// ?ApplyDamage@idVehicle@@UAAXHHPBVidDeclDamage@@@Z
// EA  : 0x82D1DE40
// RVA : 0x00D1DE40
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __fastcall idVehicle::ApplyDamage(idVehicle *this, int physId, int bodyId, const idDeclDamage *damageDecl)
{
  if ( ((unsigned __int8 (__fastcall *)(idVehicle *, int, int))this->TakesDamage)(a1: this, a2: physId, a3: bodyId) != 0
    && damageDecl != nullptr
    && vai_god.valueInteger == 0 )
  {
    ((void (__fastcall *)(idVehicle *, _DWORD, _DWORD, const idDeclDamage *, double))this->Damage)(
      a1: this,
      a2: 0,
      a3: 0,
      a4: damageDecl,
      a5: 1.0);
  }
}


// ========================================================================
// ?DropItem@idVehicle@@QAAPAVidEntity@@PBVidDeclEntityDef@@@Z
// EA  : 0x82D1DEE0
// RVA : 0x00D1DEE0
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

idProp_VehiclePickup *__fastcall idVehicle::DropItem(idVehicle *this, const idDeclEntityDef *def)
{
  idProp_VehiclePickup *v3; // r31
  idProp_VehiclePickup *result; // r3
  idEntity *v5; // r29
  idPhysics *Physics; // r3
  const idVec3 *v7; // r3
  float y; // r11
  float z; // r10
  idPhysics *v10; // r3
  idPhysics *v11; // r29
  idPhysics *v12; // r28
  idPhysics *v13; // r3
  idPhysics_vtbl *v14; // r29
  const idMat3 *(__fastcall *GetAxis)(idPhysics *, int); // ctr
  int v16; // r3
  idPhysics *v17; // r3
  idPhysics *v18; // r3
  idPhysics *v19; // r3
  __int64 v20; // r7
  __int64 v21; // r9
  unsigned int v22; // r4
  unsigned int v23; // r5
  idPhysics *v24; // r3
  idProp_Moveable *v25; // r3
  float v26; // [sp+58h] [-68h] BYREF
  float v27; // [sp+5Ch] [-64h]
  _DWORD v28[4]; // [sp+68h] [-58h] BYREF
  char v29; // [sp+78h] [-48h] BYREF
  float v30; // [sp+80h] [-40h]

  v3 = (idProp_VehiclePickup *)gameLocal->SpawnEntityFromDef(this: gameLocal, a2: def, a3: -1, a4: -1, a5: -1);
  result = idProp_VehiclePickup::CastTo(c: v3);
  v5 = result;
  if ( result != nullptr )
  {
    result->removeTime = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) + 10000;
    *((float *)&v5[6].physics + 1) = 0.0;
    *(float *)&v5[6].touchTriggersQuery.index = 0.0;
    Physics = idEntity::GetPhysics(this);
    v7 = Physics->GetOrigin(this: Physics, a2: 0);
    y = v7->y;
    z = v7->z;
    v28[0] = LODWORD(v7->x);
    *(float *)&v28[1] = y;
    *(float *)&v28[2] = z;
    v10 = idEntity::GetPhysics(this: v3);
    v10->SetOrigin(this: v10, a2: (const idVec3 *)v28, a3: -1);
    v11 = idEntity::GetPhysics(this);
    v12 = idEntity::GetPhysics(this: v3);
    v13 = v11;
    GetAxis = v11->GetAxis;
    v14 = v12->__vftable;
    v16 = (int)GetAxis(this: v13, a2: 0);
    v14->SetAxis(this: v12, a2: (const idMat3 *)v16, a3: -1);
    v17 = idEntity::GetPhysics(this);
    v17->GetLinearVelocity(this: (idPhysics *)&v29, result: (idVec3 *)v17, a3: 0);
    v30 = 0.0;
    v18 = idEntity::GetPhysics(this: v3);
    v18->SetLinearVelocity(this: v18, a2: &vec3_origin, a3: 0);
    v19 = idEntity::GetPhysics(this);
    v19->GetAngularVelocity(this: (idPhysics *)&v26, result: (idVec3 *)v19, a3: 0);
    HIDWORD(v20) = &ai_useTurnTransitions.valueString.baseBuffer[12];
    HIDWORD(v21) = "DistToTarget: %f dist: %f \n";
    v22 = 1664525 * clientGame->random.seed + 1013904223;
    clientGame->random.seed = v22;
    LODWORD(v20) = (v22 >> 10) & 0x7FFF;
    v26 = (float)((float)v20 * (float)0.00061037019) + v26;
    v23 = 1664525 * clientGame->random.seed;
    clientGame->random.seed = v23 + 1013904223;
    LODWORD(v21) = ((v23 + 1013904223) >> 10) & 0x7FFF;
    v27 = (float)((float)v21 * (float)0.00061037019) + v27;
    v24 = idEntity::GetPhysics(this: v3);
    v24->SetAngularVelocity(this: v24, a2: (const idVec3 *)&v26, a3: 0);
    v25 = idProp_Moveable::CastTo(c: v3);
    idProp_Moveable::DropToFloor(this: v25, set: false);
    return v3;
  }
  return result;
}


// ========================================================================
// ?ApplyArmorSave@idVehicle@@QAAMPAVidInventoryItem@@M_N@Z
// EA  : 0x82D1E158
// RVA : 0x00D1E158
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

float __fastcall idVehicle::ApplyArmorSave(
        idVehicle *this,
        idInventoryItem *item,
        double damage,
        bool throwItem,
        unsigned __int8 a5)
{
  __int64 v9; // r9
  int (__fastcall *GetCount)(idInventoryItem *); // ctr
  int v11; // r3
  __int64 v12; // r9
  double v13; // fp1
  __int64 v14; // r9
  double v15; // fp31
  idPresentable *presentable; // r29
  int v17; // r28
  idInventoryCollection *v18; // r3

  LODWORD(v9) = item->GetCount(this: item);
  GetCount = item->GetCount;
  if ( damage >= (float)v9 )
  {
    LODWORD(v14) = GetCount(this: item);
    HIDWORD(v14) = a5;
    v15 = (float)v14;
    if ( a5 != 0 )
    {
      this->ThrowAttachedItem(this, a2: item);
      v13 = v15;
    }
    else
    {
      presentable = this->presentable;
      if ( presentable == nullptr )
      {
        idEntity::InitPresentableInternal(this);
        presentable = this->presentable;
      }
      v17 = item->GetCount(this: item);
      v18 = this->GetInventory_2(this);
      idInventoryCollection::DeleteInventoryItem(this: v18, owner: presentable, item, count: v17);
      v13 = v15;
    }
  }
  else
  {
    v11 = GetCount(this: item);
    idInventoryItem::SetCount(this: item, amount: v11 - (int)damage);
    LODWORD(v12) = (int)damage;
    v13 = (float)v12;
  }
  return *((float *)&v13 + 1);
}


// ========================================================================
// ?ThrowAllDetchableItems@idVehicle@@QAAXXZ
// EA  : 0x82D1E2A8
// RVA : 0x00D1E2A8
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __fastcall idVehicle::ThrowAllDetchableItems(idVehicle *this)
{
  int v2; // r29
  int v3; // r30
  detachable_t *list; // r11
  const idDeclInventory *decl; // r10
  const idDeclJob *v6; // r28
  idJobManager *v7; // r3
  idInventoryItem *JobByDecl; // r4

  v2 = 0;
  if ( this->detachableItems.num > 0 )
  {
    v3 = 0;
    do
    {
      list = this->detachableItems.list;
      decl = list[v3].decl;
      if ( decl != nullptr && !decl->noAttachment )
      {
        v6 = (const idDeclJob *)list[v3].decl;
        v7 = (idJobManager *)this->GetInventory_2(this);
        JobByDecl = (idInventoryItem *)idJobManager::FindJobByDecl(this: v7, jobDecl: v6);
        if ( JobByDecl != nullptr )
          this->ThrowAttachedItem(this, a2: JobByDecl);
      }
      ++v2;
      ++v3;
    }
    while ( v2 < this->detachableItems.num );
  }
}


// ========================================================================
// ?CollapseJointByIndex@idVehicle@@QAAXV?$idIndex@FW4invalidJointIndex_t@@@@_N@Z
// EA  : 0x82D1E348
// RVA : 0x00D1E348
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __fastcall idVehicle::CollapseJointByIndex(
        idVehicle *this,
        idIndex<short,enum invalidJointIndex_t> *jointIndex,
        bool bl)
{
  const idVec3 *v6; // r31
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  float v8[12]; // [sp+50h] [-30h] BYREF

  if ( idAnimatedEntity::GetTreeAnimatorFromPresentable(this) != nullptr && (__int16)jointIndex >= 0 )
  {
    if ( bl )
    {
      v6 = &vec3_origin;
    }
    else
    {
      v6 = (const idVec3 *)v8;
      v8[0] = 1.0;
      v8[1] = 1.0;
      v8[2] = 1.0;
    }
    TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
    idTreeAnimator::SetJointScale(
      this: TreeAnimatorFromPresentable,
      pose: (animationPose_t)0,
      jointIndex,
      type: JOINTMOD_LOCAL,
      scale: v6);
  }
}


// ========================================================================
// ?GetArmoredHealth@idVehicle@@QBAMXZ
// EA  : 0x82D1E3D0
// RVA : 0x00D1E3D0
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

float __fastcall idVehicle::GetArmoredHealth(idVehicle *this)
{
  BOOL v2; // r8
  idVehicle_vtbl *v3; // r11
  double v4; // fp1
  int v5; // r29
  idInventoryCollection *v6; // r30
  int i; // r31
  idInventoryItem *InventoryItem; // r3
  double v9; // fp1
  __int64 v10; // r9

  v2 = common->IsMultiplayer(this: common);
  v3 = this->__vftable;
  if ( v2 )
  {
    v3->GetHealth(this);
  }
  else
  {
    v5 = 0;
    v6 = (idInventoryCollection *)v3->GetInventory(this);
    for ( i = 0; i < (int)idScriptObject::GetTypeDef(this: (bfx::Planner3D *)v6); ++i )
    {
      InventoryItem = idInventoryCollection::GetInventoryItem(this: v6, index: i);
      if ( (!InventoryItem->decl->vehicleArmor ? nullptr : InventoryItem->decl) != nullptr
        && !*(!InventoryItem->decl->vehicleArmor ? (bool *)278 : &InventoryItem->decl->noAttachment) )
      {
        v5 += InventoryItem->GetCount(this: InventoryItem);
      }
    }
    v9 = ((double (__fastcall *)(idVehicle *))this->GetHealth)(a1: this);
    LODWORD(v10) = v5;
    v4 = (float)((float)v9 + (float)v10);
  }
  return *((float *)&v4 + 1);
}


// ========================================================================
// ?Event_SetUsable@idVehicle@@QAA?AVeventVoid@@_N@Z
// EA  : 0x82D1E4D8
// RVA : 0x00D1E4D8
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __usercall idVehicle::Event_SetUsable@<r4>(idVehicle *this@<r3>, int result@<r4>, bool usable@<r5>)
{
  *(_BYTE *)(result + 14412) = usable;
  return result;
}


// ========================================================================
// ?Event_GetCurrentThrottle@idVehicle@@QAA?AVeventFloat@@XZ
// EA  : 0x82D1E4E0
// RVA : 0x00D1E4E0
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

idVehicle *__fastcall idVehicle::Event_GetCurrentThrottle(idVehicle *this, eventFloat *result)
{
  float value; // r3
  int v4; // r11

  value = result[122].value;
  if ( value == 0.0 )
    v4 = 0;
  else
    v4 = (*(int (__fastcall **)(double))(*(_DWORD *)LODWORD(value) + 76))(a1: COERCE_DOUBLE(LODWORD(value)));
  eventFloat::eventFloat((eventFloat *)this, f: *(float *)(v4 + 11888));
  return this;
}


// ========================================================================
// ?Event_GetCurrentVelocity@idVehicle@@QAA?AVeventFloat@@XZ
// EA  : 0x82D1E540
// RVA : 0x00D1E540
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

idVehicle *__fastcall idVehicle::Event_GetCurrentVelocity(idVehicle *this, eventFloat *result)
{
  float value; // r3
  int v4; // r11

  value = result[122].value;
  if ( value == 0.0 )
    v4 = 0;
  else
    v4 = (*(int (__fastcall **)(double))(*(_DWORD *)LODWORD(value) + 76))(a1: COERCE_DOUBLE(LODWORD(value)));
  eventFloat::eventFloat((eventFloat *)this, f: *(float *)(v4 + 17864));
  return this;
}


// ========================================================================
// ?Event_GetNumOccupants@idVehicle@@QAA?AVeventFloat@@XZ
// EA  : 0x82D1E5A0
// RVA : 0x00D1E5A0
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

idVehicle *__fastcall idVehicle::Event_GetNumOccupants(idVehicle *this, eventFloat *result)
{
  float value; // r3
  idPresentableVehicle *v4; // r3
  __int64 v5; // r11

  value = result[122].value;
  if ( value == 0.0 )
    v4 = nullptr;
  else
    v4 = (idPresentableVehicle *)(*(int (__fastcall **)(double))(*(_DWORD *)LODWORD(value) + 76))(a1: COERCE_DOUBLE(LODWORD(value)));
  LODWORD(v5) = idPresentableVehicle::GetNumActiveOccupants(this: v4);
  eventFloat::eventFloat((eventFloat *)this, f: (float)v5);
  return this;
}


// ========================================================================
// ?Event_SetHealth@idVehicle@@QAA?AVeventVoid@@M@Z
// EA  : 0x82D1E610
// RVA : 0x00D1E610
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

idVehicle *__fastcall idVehicle::Event_SetHealth(idVehicle *this, eventVoid *result, double health_)
{
  idVehicleKey *v4; // r3

  v4 = *(idVehicleKey **)&result[14536];
  *(float *)&result[15708] = health_;
  if ( v4 != nullptr )
    idVehicleKey::SetHealth(this: v4, h: health_);
  return this;
}


// ========================================================================
// ?Event_GetLastDamage_DamageName@idVehicle@@QAA?AVeventString@@XZ
// EA  : 0x82D1E650
// RVA : 0x00D1E650
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

idVehicle *__fastcall idVehicle::Event_GetLastDamage_DamageName(idVehicle *this, eventString *result)
{
  const char *value; // r11
  const char *v4; // r4

  value = result[3936].value;
  if ( value != nullptr )
    v4 = *((const char **)value + 17);
  else
    v4 = "none";
  eventString::eventString((eventString *)this, s: v4);
  return this;
}


// ========================================================================
// ?Event_GetLastDamage_Time@idVehicle@@QAA?AVeventFloat@@XZ
// EA  : 0x82D1E6A0
// RVA : 0x00D1E6A0
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

idVehicle *__fastcall idVehicle::Event_GetLastDamage_Time(
        idVehicle *this,
        eventFloat *result,
        int a3,
        int a4,
        int a5,
        __int64 a6)
{
  LODWORD(a6) = result[3938];
  eventFloat::eventFloat((eventFloat *)this, f: (float)((float)a6 * (float)0.001));
  return this;
}


// ========================================================================
// ?Event_GetDriverName@idVehicle@@QAA?AVeventString@@XZ
// EA  : 0x82D1E6F8
// RVA : 0x00D1E6F8
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

idVehicle *__fastcall idVehicle::Event_GetDriverName(idVehicle *this, eventString *result)
{
  eventString::eventString((eventString *)this, s: result[3625].value);
  return this;
}


// ========================================================================
// ?Event_GetLastCollision_Time@idVehicle@@QAA?AVeventFloat@@XZ
// EA  : 0x82D1E730
// RVA : 0x00D1E730
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

idVehicle *__fastcall idVehicle::Event_GetLastCollision_Time(
        idVehicle *this,
        eventFloat *result,
        int a3,
        int a4,
        int a5,
        __int64 a6)
{
  float value; // r3
  int v8; // r3

  value = result[122].value;
  if ( value == 0.0 )
    v8 = 0;
  else
    v8 = (*(int (__fastcall **)(double))(*(_DWORD *)LODWORD(value) + 76))(a1: COERCE_DOUBLE(LODWORD(value)));
  LODWORD(a6) = *(_DWORD *)(v8 + 20272);
  eventFloat::eventFloat((eventFloat *)this, f: (float)((float)a6 * (float)0.001));
  return this;
}


// ========================================================================
// ?Event_GetLastCollision_Point@idVehicle@@QAA?AVeventVector@@XZ
// EA  : 0x82D1E7B0
// RVA : 0x00D1E7B0
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

idVehicle *__fastcall idVehicle::Event_GetLastCollision_Point(idVehicle *this, eventVector *result)
{
  float z; // r3
  const idVec3 *v4; // r3

  z = result[40].value.z;
  if ( z == 0.0 )
    v4 = nullptr;
  else
    v4 = (const idVec3 *)(*(int (__fastcall **)(double))(*(_DWORD *)LODWORD(z) + 76))(a1: COERCE_DOUBLE(LODWORD(z)));
  eventVector::eventVector((eventVector *)this, v: v4 + 1691);
  return this;
}


// ========================================================================
// ?Event_GetLastCollision_Normal@idVehicle@@QAA?AVeventVector@@XZ
// EA  : 0x82D1E810
// RVA : 0x00D1E810
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

idVehicle *__fastcall idVehicle::Event_GetLastCollision_Normal(idVehicle *this, eventVector *result)
{
  float z; // r3
  const idVec3 *v4; // r3

  z = result[40].value.z;
  if ( z == 0.0 )
    v4 = nullptr;
  else
    v4 = (const idVec3 *)(*(int (__fastcall **)(double))(*(_DWORD *)LODWORD(z) + 76))(a1: COERCE_DOUBLE(LODWORD(z)));
  eventVector::eventVector((eventVector *)this, v: v4 + 1692);
  return this;
}


// ========================================================================
// ?Event_GetLastCollision_Dist@idVehicle@@QAA?AVeventFloat@@XZ
// EA  : 0x82D1E870
// RVA : 0x00D1E870
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

idVehicle *__fastcall idVehicle::Event_GetLastCollision_Dist(idVehicle *this, eventFloat *result)
{
  float value; // r3
  int v4; // r11

  value = result[122].value;
  if ( value == 0.0 )
    v4 = 0;
  else
    v4 = (*(int (__fastcall **)(double))(*(_DWORD *)LODWORD(value) + 76))(a1: COERCE_DOUBLE(LODWORD(value)));
  eventFloat::eventFloat((eventFloat *)this, f: *(float *)(v4 + 20316));
  return this;
}


// ========================================================================
// ?Event_GetLastCollision_WasOtherCar@idVehicle@@QAA?AVeventBool@@XZ
// EA  : 0x82D1E8D0
// RVA : 0x00D1E8D0
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

idVehicle *__fastcall idVehicle::Event_GetLastCollision_WasOtherCar(idVehicle *this, eventBool *result)
{
  int v3; // r3
  int v4; // r3

  v3 = *(_DWORD *)&result[488].value;
  if ( v3 != 0 )
    v4 = (*(int (__fastcall **)(int))(*(_DWORD *)v3 + 76))(a1: v3);
  else
    v4 = 0;
  eventBool::eventBool((eventBool *)this, b: (*(_BYTE *)(v4 + 20320) & 8) != 0);
  return this;
}


// ========================================================================
// ?Event_EnableVehicleControls@idVehicle@@QAA?AVeventVoid@@M@Z
// EA  : 0x82D1E930
// RVA : 0x00D1E930
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

idVehicle *__fastcall idVehicle::Event_EnableVehicleControls(idVehicle *this, eventVoid *result, double enable)
{
  int v4; // r3

  v4 = *(_DWORD *)&result[488];
  if ( v4 != 0 )
    *(_BYTE *)((*(int (__fastcall **)(int))(*(_DWORD *)v4 + 76))(a1: v4) + 11876) = enable != 0.0;
  else
    MEMORY[0x2E64] = enable != 0.0;
  return this;
}


// ========================================================================
// ?Event_ExitVehicle@idVehicle@@QAA?AVeventVoid@@H@Z
// EA  : 0x82D1E9B0
// RVA : 0x00D1E9B0
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

idVehicle *__fastcall idVehicle::Event_ExitVehicle(idVehicle *this, eventVoid *result, int occupantNum)
{
  (*(void (__fastcall **)(eventVoid *, int, _DWORD, _DWORD))(*(_DWORD *)result + 676))(
    a1: result,
    a2: occupantNum,
    a3: 0,
    a4: 0);
  return this;
}


// ========================================================================
// ?UpdateDriverViewAngles@idVehicle@@UAAXABVusercmd_t@@0@Z
// EA  : 0x82D1EA00
// RVA : 0x00D1EA00
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idVehicle::UpdateDriverViewAngles(idVehicle *this, const usercmd_t *prevcmd, const usercmd_t *usercmd)
{
  __int16 v3; // r9
  __int128 v4; // r5
  int v5; // r3
  double v6; // fp3
  double v7; // fp13
  int v8; // r3
  int v9; // r3
  double v10; // fp13
  double v11; // fp0
  int v12; // r3
  int v13; // r3
  int v14; // r3
  double v15; // fp13
  double v16; // fp0
  int v17; // r3
  int v18; // r3

  v3 = usercmd->angles[0];
  LODWORD(v4) = usercmd->angles[1];
  DWORD2(v4) = v3;
  v6 = -(float)((float)*(__int64 *)((char *)&v4 + 4) * (float)0.0054931641);
  *(float *)(DWORD1(v4) + 15992) = v6;
  *(float *)(DWORD1(v4) + 15996) = -(float)((float)((float)((float)__fabs((float)((float)(__int64)v4
                                                                                * (float)0.0054931641))
                                                          * (float)0.011111111)
                                                  * (float)((float)(__int64)v4 * (float)0.0054931641))
                                          * (float)2.0);
  v7 = *(float *)(DWORD1(v4) + 15936);
  if ( v6 < v7 || (v7 = *(float *)(v8 + 15948), v6 > v7) )
    *(float *)(v5 + 15992) = v7;
  v10 = *(float *)(v9 + 15940);
  v11 = *(float *)(v9 + 15996);
  if ( v11 < v10 || (v10 = *(float *)(v12 + 15952), v11 > v10) )
    *(float *)(v13 + 15996) = v10;
  v15 = *(float *)(v14 + 15944);
  v16 = *(float *)(v14 + 16000);
  if ( v16 < v15 || (v15 = *(float *)(v17 + 15956), v16 > v15) )
    *(float *)(v18 + 16000) = v15;
}


// ========================================================================
// ?Event_AllowAccelerate@idVehicle@@QAA?AVeventVoid@@M@Z
// EA  : 0x82D1EAD8
// RVA : 0x00D1EAD8
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

idVehicle *__fastcall idVehicle::Event_AllowAccelerate(idVehicle *this, eventVoid *result, double allow)
{
  int v4; // r3

  v4 = *(_DWORD *)&result[488];
  if ( v4 != 0 )
    *(_BYTE *)((*(int (__fastcall **)(int))(*(_DWORD *)v4 + 76))(a1: v4) + 11881) = allow != 0.0;
  else
    MEMORY[0x2E69] = allow != 0.0;
  return this;
}


// ========================================================================
// ?GetVisibilityPoint@idVehicle@@UBAXW4visPoint_t@@AAVidVec3@@@Z
// EA  : 0x82D1EB58
// RVA : 0x00D1EB58
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __fastcall idVehicle::GetVisibilityPoint(idVehicle *this, const visPoint_t type, idVec3 *pos)
{
  idPhysics *Physics; // r3
  float *v5; // r3
  double v6; // fp6
  double v7; // fp7

  Physics = idEntity::GetPhysics(this);
  v5 = (float *)Physics->GetAbsBounds(this: Physics, a2: -1);
  v6 = (float)(v5[2] + v5[5]);
  v7 = (float)(v5[1] + v5[4]);
  pos->x = (float)(*v5 + v5[3]) * (float)0.5;
  pos->z = (float)v6 * (float)0.5;
  pos->y = (float)v7 * (float)0.5;
}


// ========================================================================
// ?GetAimPoint@idVehicle@@UBAXW4aimPoint_t@@AAVidVec3@@@Z
// EA  : 0x82D1EBE0
// RVA : 0x00D1EBE0
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __fastcall idVehicle::GetAimPoint(idVehicle *this, const aimPoint_t type, idVec3 *pos)
{
  idPhysics *Physics; // r3
  float *v5; // r3
  double v6; // fp7
  double v7; // fp6

  Physics = idEntity::GetPhysics(this);
  v5 = (float *)Physics->GetAbsBounds(this: Physics, a2: -1);
  v6 = (float)(v5[1] + v5[4]);
  v7 = (float)(v5[5] + v5[2]);
  pos->x = (float)(*v5 + v5[3]) * (float)0.5;
  pos->y = (float)v6 * (float)0.5;
  pos->z = (float)v7 * (float)0.5;
}


// ========================================================================
// ?ClearDamageFX@idVehicle@@QAAXXZ
// EA  : 0x82D1EC68
// RVA : 0x00D1EC68
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __fastcall idVehicle::ClearDamageFX(idVehicle *this)
{
  idPresentable *presentable; // r3
  idPresentableVehicle *v2; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
  {
    v2 = presentable->GetVehicleInterface(this: presentable);
    idPresentableVehicle::ClearDamageFX(this: v2);
  }
  else
  {
    idPresentableVehicle::ClearDamageFX(this: nullptr);
  }
}


// ========================================================================
// ?ActivateBoost@idVehicle_Car@@QAAXH@Z
// EA  : 0x82D1ECC0
// RVA : 0x00D1ECC0
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __fastcall idVehicle_Car::ActivateBoost(idVehicle_Car *this, int time)
{
  idPresentable *presentable; // r3
  int v4; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
  {
    v4 = (int)presentable->GetVehicleInterface(this: presentable);
    if ( v4 != 0 )
      *(_DWORD *)(v4 + 17740) = time;
  }
}


// ========================================================================
// ?UpdateDamageDecals@idVehicle@@QAAXPAUtrace_t@@PBVidDeclDamage@@ABVidVec3@@M@Z
// EA  : 0x82D1ED10
// RVA : 0x00D1ED10
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __fastcall idVehicle::UpdateDamageDecals(
        idVehicle *this,
        trace_t *trace,
        const idDeclDamage *damageDef,
        const idVec3 *dir,
        double damageScale)
{
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idTreeAnimator *v10; // r23
  const idDeclMD6 *decl; // r11
  idPropsCollection *p_props; // r17
  const idDeclVehicleWindowKit *vehicleWindowKit; // r11
  int v14; // r21
  int v15; // r25
  int v16; // r26
  idVehicleWindow::window_t *v17; // r31
  idDeclVehicleWindowKit::windowDef_t *v18; // r29
  idRenderModelParms *Origin; // r3
  float y; // r9
  float z; // r8
  const idMat3 *Axis; // r3
  char *v23; // r10
  _DWORD *p_z; // r11
  int i; // ctr
  const tagData_t *Tag; // r3
  char v27; // r11
  idClipModel *collisionModel; // r11
  bool v29; // zf
  double v30; // fp12
  double v31; // fp13
  double x; // fp0
  double v33; // fp11
  double v34; // fp9
  float *v35; // r11
  double traceDepth; // fp7
  double v37; // fp5
  double v38; // fp4
  double v39; // fp12
  double v40; // fp10
  double v41; // fp13
  double v42; // fp8
  double v43; // fp11
  double v44; // fp7
  double v45; // fp6
  double v46; // fp5
  double v47; // fp13
  double v48; // fp11
  int v49; // [sp+8h] [-178h]
  const char *v50; // [sp+Ch] [-174h]
  int v51; // [sp+10h] [-170h]
  int v52; // [sp+14h] [-16Ch]
  int v53; // [sp+18h] [-168h]
  int v54; // [sp+1Ch] [-164h]
  int v55; // [sp+20h] [-160h]
  int v56; // [sp+24h] [-15Ch]
  int v57; // [sp+28h] [-158h]
  int v58; // [sp+2Ch] [-154h]
  int v59; // [sp+30h] [-150h]
  int v60; // [sp+34h] [-14Ch]
  int v61; // [sp+38h] [-148h]
  int v62; // [sp+3Ch] [-144h]
  int v63; // [sp+40h] [-140h]
  int v64; // [sp+44h] [-13Ch]
  int v65; // [sp+48h] [-138h]
  int v66; // [sp+4Ch] [-134h]
  int v67; // [sp+50h] [-130h]
  char v68; // [sp+60h] [-120h] BYREF
  idVec3 v69; // [sp+68h] [-118h] BYREF
  idVec3 v70; // [sp+78h] [-108h] BYREF
  idVec3 v71; // [sp+88h] [-F8h] BYREF
  idBounds v72; // [sp+A0h] [-E0h] BYREF
  char v73; // [sp+BCh] [-C4h] BYREF
  idMat3 v74; // [sp+C0h] [-C0h] BYREF

  if ( trace != nullptr && this->vehicleWindowKit != nullptr )
  {
    TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
    v10 = TreeAnimatorFromPresentable;
    if ( TreeAnimatorFromPresentable == nullptr )
    {
      idLib::Warning(fmt: "No tree animator for vehicle '%s'", this->name.data);
      return;
    }
    decl = TreeAnimatorFromPresentable->decl;
    if ( decl == nullptr || (p_props = &decl->props, decl == (const idDeclMD6 *)-352) )
    {
      idLib::Warning(fmt: "No propsCollection for vehicle '%s'", this->name.data);
      return;
    }
    vehicleWindowKit = this->vehicleWindowKit;
    v14 = 0;
    if ( vehicleWindowKit->windows.num > 0 )
    {
      v15 = 0;
      v16 = 0;
      do
      {
        v17 = &this->vehicleWindow.windows.list[v15];
        v18 = &vehicleWindowKit->windows.list[v16];
        if ( v17->collisionModel != nullptr && (!v18->damageWhenDriverPresent || idVehicle::GetDriver(this) != nullptr) )
        {
          if ( v18->damageDriverWhenBroken )
          {
            if ( idVehicle::GetDriver(this) != nullptr || !v17->broken )
            {
              v17->damageQuery.attacker.spawnId.value = this->lastDamage.attacker.spawnId.value;
              v17->damageQuery.inflictor.spawnId.value = this->lastDamage.inflictor.spawnId.value;
              v17->damageQuery.def = this->lastDamage.damageDef;
              v17->damageQuery.dir.x = dir->x;
              v17->damageQuery.dir.y = dir->y;
              v17->damageQuery.dir.z = dir->z;
              v17->damageQuery.scale = damageScale;
LABEL_18:
              Origin = idRenderModel::GetOrigin(this: v10);
              y = Origin->origin.y;
              z = Origin->origin.z;
              v69.x = Origin->origin.x;
              v69.y = y;
              v69.z = z;
              Axis = idRenderModel::GetAxis(this: v10);
              v23 = &v73;
              p_z = (_DWORD *)&Axis[-1].mat[2].z;
              for ( i = 9; i != 0; --i )
              {
                ++p_z;
                v23 += 4;
                *(_DWORD *)v23 = *p_z;
              }
              if ( v18->tagName.len != 0 )
              {
                Tag = idPropsCollection::GetTag(this: p_props, propName: "_info", tagName: v18->tagName.data);
                idTreeAnimator::GetWorldSpaceTagTransform(this: v10, tagData: Tag, origin: &v69, axis: &v74);
              }
              if ( v74.mat[0].x != 1.0 || v74.mat[1].y != 1.0 || (v27 = 0, v74.mat[2].z != 1.0) )
                v27 = 1;
              v29 = v27 == 0;
              collisionModel = v17->collisionModel;
              if ( v29 )
              {
                v33 = (float)(collisionModel->bounds.b[0].y + v69.y);
                v34 = (float)(collisionModel->bounds.b[0].z + v69.z);
                v72.b[0].x = v69.x + collisionModel->bounds.b[0].x;
                v72.b[0].y = v33;
                v72.b[0].z = v34;
                v35 = (float *)v17->collisionModel;
                v31 = (float)(v35[24] + v69.y);
                x = (float)(v35[23] + v69.x);
                v30 = (float)(v35[25] + v69.z);
              }
              else
              {
                idBounds::FromTransformedBounds(this: &v72, bounds: &collisionModel->bounds, origin: &v69, axis: &v74);
                v30 = v72.b[1].z;
                v31 = v72.b[1].y;
                x = v72.b[1].x;
              }
              v72.b[0].y = v72.b[0].y - (float)1.0;
              v72.b[0].z = v72.b[0].z - (float)1.0;
              v72.b[1].x = (float)x + (float)1.0;
              v72.b[1].z = (float)v30 + (float)1.0;
              v72.b[0].x = v72.b[0].x - (float)1.0;
              v72.b[1].y = (float)v31 + (float)1.0;
              traceDepth = v18->traceDepth;
              v37 = (float)(v72.b[0].y - v18->traceDepth);
              v38 = (float)(v72.b[0].z - v18->traceDepth);
              v72.b[0].x = v72.b[0].x - v18->traceDepth;
              v72.b[0].y = v37;
              v72.b[0].z = v38;
              v72.b[1].x = v72.b[1].x + (float)traceDepth;
              v72.b[1].y = v72.b[1].y + (float)traceDepth;
              v72.b[1].z = v72.b[1].z + (float)traceDepth;
              if ( (unsigned __int8)idBounds::ContainsPoint(this: &v72, p: &trace->endpos) != 0
                && LODWORD(v17->clipQuery.index) <= LODWORD(clientGame->clip.collisionQueryLastSubmittedIndex) )
              {
                v39 = dir->y;
                v40 = dir->z;
                v41 = dir->x;
                v42 = (float)(dir->z * v18->traceDepth);
                v43 = (float)(dir->x * v18->traceDepth);
                v44 = trace->endpos.x;
                v45 = trace->endpos.y;
                v46 = trace->endpos.z;
                v70.y = trace->endpos.y - (float)(dir->y * v18->traceDepth);
                v70.z = (float)v46 - (float)v42;
                v70.x = (float)v44 - (float)v43;
                v47 = (float)((float)v41 * v18->traceDepth);
                v48 = (float)((float)v45 + (float)((float)v39 * v18->traceDepth));
                v71.z = (float)v46 + (float)((float)v40 * v18->traceDepth);
                v71.y = v48;
                v71.x = (float)v44 + (float)v47;
                v17->clipQuery.index = *(_QWORD *)&idClip::TranslationTraceModel(
                                                     this: (idClip *)&v68,
                                                     result: &clientGame->clip,
                                                     a3: nullptr,
                                                     start: &v70,
                                                     end: &v71,
                                                     model: v17->collisionModel,
                                                     modelOrigin: &v69,
                                                     modelAxis: &v74,
                                                     clipMask: v49,
                                                     userName: v50,
                                                     a11: v51,
                                                     a12: v52,
                                                     a13: v53,
                                                     a14: v54,
                                                     a15: v55,
                                                     a16: v56,
                                                     a17: v57,
                                                     a18: v58,
                                                     a19: v59,
                                                     a20: v60,
                                                     a21: v61,
                                                     a22: v62,
                                                     a23: v63,
                                                     a24: v64,
                                                     a25: v65,
                                                     a26: v66,
                                                     a27: v67,
                                                     a28: 129)->world;
              }
            }
          }
          else if ( !v17->broken )
          {
            goto LABEL_18;
          }
        }
        vehicleWindowKit = this->vehicleWindowKit;
        ++v14;
        ++v16;
        ++v15;
      }
      while ( v14 < vehicleWindowKit->windows.num );
    }
  }
}


// ========================================================================
// ?GetCurrentAnimEvent@idVehicle@@QBAPBUeventAnimEntry_t@1@XZ
// EA  : 0x82D1F140
// RVA : 0x00D1F140
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

const idVehicle::eventAnimEntry_t *__fastcall idVehicle::GetCurrentAnimEvent(idVehicle *this)
{
  int currentState; // r11

  currentState = this->eventAnimSupport.currentState;
  if ( currentState == -1 )
    return nullptr;
  else
    return &this->eventAnimList.list[currentState];
}


// ========================================================================
// ?GiveItem@idVehicle@@QAAPAVidInventoryItem@@PBVidDeclInventory@@H_N@Z
// EA  : 0x82D1F3D0
// RVA : 0x00D1F3D0
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

idInventoryItem *__fastcall idVehicle::GiveItem(
        idVehicle *this,
        const idDeclVehicleWeapon *decl,
        int count,
        bool forceCount)
{
  idPresentable *v8; // r3
  idPresentableVehicle *v9; // r3
  idVehicleWeapon *v10; // r27
  idInventoryItem *weapon; // r26
  int v12; // r29
  idPresentable *presentable; // r30
  const idDeclAmmo *initialAmmoDecl; // r28
  idInventoryCollection *v15; // r3
  idPresentable *v17; // r29
  idInventoryCollection *v18; // r3

  if ( decl->quickSlotGroup != QUICKSLOTGROUP_NONE
    && (unsigned __int8)idDecl::IsType<idDeclWeapon>(this: &decl->idDeclInventory) != 0
    && ((v8 = this->presentable) == nullptr ? (v9 = nullptr) : (v9 = v8->GetVehicleInterface(this: v8)),
        (v10 = idPresentableVehicle::AddWeaponToVehicle(this: v9, decl)) != nullptr) )
  {
    weapon = v10->weapon;
    this->InventoryAdded(this, a2: weapon, a3: decl->count);
    if ( count <= 0 )
    {
      v12 = 1;
    }
    else
    {
      v12 = count;
      if ( count > 999999 )
        v12 = 999999;
    }
    presentable = this->presentable;
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      presentable = this->presentable;
    }
    initialAmmoDecl = idVehicleWeapon::GetDeclVehicleWeapon(this: v10)->initialAmmoDecl;
    v15 = this->GetInventory_2(this);
    idInventoryCollection::GiveItem(
      this: v15,
      owner: presentable,
      decl: initialAmmoDecl,
      count: v12,
      forceCount: false,
      canIntro: false);
    return weapon;
  }
  else
  {
    v17 = this->presentable;
    if ( v17 == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      v17 = this->presentable;
    }
    v18 = this->GetInventory_2(this);
    return idInventoryCollection::GiveItem(this: v18, owner: v17, decl, count, forceCount, canIntro: false);
  }
}


// ========================================================================
// ?SpawnArmorProp@idVehicle@@QAAPAVidEntity@@PBDVidVec3@@VidMat3@@@Z
// EA  : 0x82D1F540
// RVA : 0x00D1F540
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
idProp_Moveable *__fastcall idVehicle::SpawnArmorProp(
        idVehicle *this,
        const char *name,
        __int64 axis,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9,
        __int64 a10,
        __int64 a11,
        __int64 a12,
        __int64 a13,
        __int64 a14)
{
  idGameLocal_vtbl *v16; // r31
  idTypeInfoSettings *v17; // r3
  idProp_Moveable *v18; // r31
  idRenderWorld *v19; // r3
  int v20; // r3
  idPresentable *presentable; // r11
  idRenderModel *v22; // r28
  const char *v23; // r7
  idClipModel *MoveableClipModel; // r29
  idProp_Moveable *v25; // r3
  idProp_Moveable *v26; // r30
  idPhysics *Physics; // r3
  idPhysics *v29; // r3
  idPhysics *v30; // r3
  idTypeInfoSettings v31; // [sp+50h] [-70h] BYREF
  idClipModelInfo v32[2]; // [sp+60h] [-60h] BYREF

  a9 = *(__int64 *)((char *)&axis + 4);
  a10 = axis;
  a11 = *(__int64 *)((char *)&a4 + 4);
  a12 = a4;
  a13 = *(__int64 *)((char *)&a5 + 4);
  a14 = a5;
  v16 = gameLocal->__vftable;
  v17 = idTypeInfoSettings::idTypeInfoSettings(this: &v31);
  v18 = (idProp_Moveable *)v16->CreateEntityFromDef(this: gameLocal, a2: this->armorPropDef, a3: v17);
  v19 = common->RW(this: common);
  v20 = (int)v19->AllocRenderModel(this: v19, a2: name, a3: true, a4: -1);
  presentable = v18->presentable;
  v22 = (idRenderModel *)v20;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this: v18);
    presentable = v18->presentable;
  }
  presentable->SetRenderModel(this: presentable, a2: v22, a3: true);
  v32[0].clipModelName.str = &byte_8200D768;
  idClipModelInfo::Clear(this: v32);
  if ( common->IsMultiplayer(this: common) )
  {
    v32[0].type = CLIPMODEL_BOX;
  }
  else
  {
    v32[0].type = CLIPMODEL_RENDERMODEL;
    idAtomicString::Set(this: &v32[0].clipModelName, str_: name);
  }
  if ( v18->presentable == nullptr )
    idEntity::InitPresentableInternal(this: v18);
  MoveableClipModel = idPresentable::CreateMoveableClipModel(
                        clipModelInfo: v32,
                        renderModel: v22,
                        renderModelScale: &vec3_unit,
                        barrelCollision: false,
                        overrideRadius: -1.0,
                        debugName: v23,
                        a7: "Armor Piece Collision");
  gameLocal->SpawnEntity(this: gameLocal, a2: v18, a3: -1, a4: -1, a5: -1);
  v25 = idProp_Moveable::CastTo(c: v18);
  v26 = v25;
  if ( v25 != nullptr )
  {
    Physics = idEntity::GetPhysics(this: v25);
    ((void (__fastcall *)(idPhysics *, idClipModel *, double))Physics->SetClipModel)(
      a1: Physics,
      a2: MoveableClipModel,
      a3: 0.0020000001);
    v29 = idEntity::GetPhysics(this: v26);
    v29->SetOrigin(this: v29, a2: (const idVec3 *)&a9, a3: -1);
    v30 = idEntity::GetPhysics(this: v26);
    v30->SetAxis(this: v30, a2: (const idMat3 *)&a11, a3: -1);
    idProp_Moveable::DropToFloor(this: v26, set: false);
    idProp_Usable::SetUsable(this: v26, b: false);
    return v18;
  }
  else
  {
    idEventReceiver::PostEventMS(this: v18, ev: &EV_Remove, time: 0);
    return nullptr;
  }
}


// ========================================================================
// ?AttachAIEvents@idVehicle@@IAAXXZ
// EA  : 0x82D1F788
// RVA : 0x00D1F788
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __fastcall idVehicle::AttachAIEvents(idVehicle *this)
{
  idHandle<int,enum invalidAIEvent_t,-1> *eventHandles; // r30
  int i; // r22
  idPresentable *presentable; // r3
  idPresentableVehicle *v5; // r3
  idPlayer *entity; // r31
  idPresentable *Driver; // r3
  idPhysics *Physics; // r21
  int GameMs; // r20
  idPhysics *v10; // r3
  idAIEventManager *p_aiEventManager; // r21
  const idVec3 *(__fastcall *GetOrigin)(idPhysics *, int); // ctr
  const idVec3 *v13; // r3
  idAIEventManager *v14; // r3
  bool v15; // cr58
  idAIEventManager v16; // [sp+50h] [-70h] BYREF

  eventHandles = this->eventHandles;
  for ( i = 2; i != 0; --i )
  {
    if ( eventHandles->value != -1 )
    {
      idAIEventManager::RemoveEvent(this: &gameLocal->aiEventManager, handle: eventHandles);
      eventHandles->value = -1;
    }
    presentable = this->presentable;
    if ( presentable != nullptr && (v5 = presentable->GetVehicleInterface(this: presentable)) != nullptr )
    {
      Driver = idPresentableVehicle::GetDriver(this: v5);
      entity = nullptr;
      if ( Driver != nullptr )
        entity = (idPlayer *)Driver->entity;
    }
    else
    {
      entity = nullptr;
    }
    if ( idPlayer::CastTo(c: entity) == nullptr && idAI2::CastTo(c: (idAI2 *)entity) == nullptr )
      entity = (idPlayer *)this;
    if ( eventHandles[-2].value != 0 )
    {
      Physics = idEntity::GetPhysics(this);
      GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      v10 = Physics;
      GetOrigin = Physics->GetOrigin;
      p_aiEventManager = &gameLocal->aiEventManager;
      v13 = GetOrigin(this: v10, a2: 0);
      v14 = idAIEventManager::AddEvent(
              this: &v16,
              result: p_aiEventManager,
              eventDecl: (const idDeclAiEvent *)eventHandles[-2].value,
              curTime: GameMs,
              originator: this,
              instigator: entity,
              origin: v13,
              delay: 0);
      v15 = v14->eventList.list == (idAIEvent **)-1;
      eventHandles->value = (int)v14->eventList.list;
      if ( v15 )
        idLib::Warning(fmt: "Invalid ai event specified for vehicle '%s'", this->name.data);
    }
    ++eventHandles;
  }
}


// ========================================================================
// ?SetArmorFromKey@idVehicle@@QAAXPAVidVehicleKey@@@Z
// EA  : 0x82D1F8E8
// RVA : 0x00D1F8E8
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __fastcall idVehicle::SetArmorFromKey(idVehicle *this, idVehicleKey *key)
{
  idStr *v4; // r3
  int v5; // r26
  bfx::Planner3D *v6; // r3
  idInventoryCollection *v7; // r3
  idInventoryItem *InventoryItem; // r27
  idDeclInventory *decl; // r3
  int v10; // r30
  idVehicleKey::armorInfo_t *list; // r10
  int v12; // r11
  double health; // fp31
  idPresentable *presentable; // r29
  idInventoryCollection *v15; // r3
  idPresentable *v16; // r30
  int v17; // r29
  idInventoryCollection *v18; // r3
  bfx::Planner3D *v19; // r3
  int v20; // r29
  int v21; // r30
  const idDeclInventory *v22; // r27
  idJobManager *v23; // r3
  idInventoryItem *JobByDecl; // r3
  idStr v25; // [sp+60h] [-70h] BYREF

  if ( key->initArmorFromVehicle )
  {
    key->initArmorFromVehicle = false;
    v4 = idStr::idStr(this: &v25, text: this->name.data);
    idVehicleKey::SetVehicleEntityName(this: key, vehName: v4);
    idVehicleKey::SaveVehicleArmor(this: key, vehicle: this);
  }
  else
  {
    v5 = 0;
    v6 = (bfx::Planner3D *)this->GetInventory_2(this);
    if ( (int)idScriptObject::GetTypeDef(this: v6) > 0 )
    {
      do
      {
        v7 = this->GetInventory_2(this);
        InventoryItem = idInventoryCollection::GetInventoryItem(this: v7, index: v5);
        decl = (idDeclInventory *)InventoryItem->decl;
        if ( decl->vehicleArmor && (unsigned __int8)idDecl::IsType<idDeclVehicleArmorKit>(this: decl) == 0 )
        {
          v10 = 0;
          if ( key->armorInfo.num > 0 )
          {
            list = key->armorInfo.list;
            v12 = 0;
            while ( InventoryItem->decl != list[v12].decl )
            {
              ++v10;
              ++v12;
              if ( v10 >= key->armorInfo.num )
                goto LABEL_14;
            }
            health = list[v10].health;
            if ( this->presentable == nullptr )
              idEntity::InitPresentableInternal(this);
            presentable = this->presentable;
            v15 = this->GetInventory_2(this);
            idInventoryCollection::SetItemCount(
              this: v15,
              owner: presentable,
              item: InventoryItem,
              count: (int)health,
              forceCount: true);
          }
LABEL_14:
          if ( v10 == key->armorInfo.num )
          {
            v16 = this->presentable;
            if ( v16 == nullptr )
            {
              idEntity::InitPresentableInternal(this);
              v16 = this->presentable;
            }
            v17 = InventoryItem->GetCount(this: InventoryItem);
            v18 = this->GetInventory_2(this);
            idInventoryCollection::DeleteInventoryItem(this: v18, owner: v16, item: InventoryItem, count: v17);
            --v5;
          }
        }
        ++v5;
        v19 = (bfx::Planner3D *)this->GetInventory_2(this);
      }
      while ( v5 < (int)idScriptObject::GetTypeDef(this: v19) );
    }
    v20 = 0;
    if ( key->armorInfo.num > 0 )
    {
      v21 = 0;
      do
      {
        v22 = key->armorInfo.list[v21].decl;
        v23 = (idJobManager *)this->GetInventory_2(this);
        JobByDecl = (idInventoryItem *)idJobManager::FindJobByDecl(this: v23, jobDecl: (const idDeclJob *)v22);
        if ( JobByDecl != nullptr
          || (JobByDecl = idVehicle::GiveItem(
                            this,
                            decl: (const idDeclVehicleWeapon *)key->armorInfo.list[v21].decl,
                            count: (int)key->armorInfo.list[v21].health,
                            forceCount: true)) != nullptr )
        {
          JobByDecl->forSale = false;
          JobByDecl->lootable = false;
        }
        ++v20;
        ++v21;
      }
      while ( v20 < key->armorInfo.num );
    }
  }
}


// ========================================================================
// ?SetWeaponsFromKey@idVehicle@@QAAXPAVidVehicleKey@@@Z
// EA  : 0x82D1FB68
// RVA : 0x00D1FB68
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __fastcall idVehicle::SetWeaponsFromKey(idVehicle *this, idVehicleKey *key)
{
  idPresentable *presentable; // r3
  idPresentableVehicle *v5; // r3
  int num; // r9
  int v7; // r10
  int v8; // r11
  int v9; // r30
  int v10; // r31
  idPresentable *v11; // r3
  const idDeclVehicleWeapon *v12; // r29
  idPresentableVehicle *v13; // r3
  int v14; // r8
  int v15; // r10
  const idDeclVehicleUpgrade **list; // r9
  int v17; // r11
  const idDeclVehicleUpgrade *v18; // r29
  int v19; // r28
  int v20; // r30
  idDeclInfoTemplate<idDeclWeapon> *parent; // r3
  char v22; // r11
  idPresentable *v23; // r3
  const idDeclVehicleWeapon *v24; // r31
  idPresentableVehicle *v25; // r3
  idPresentable *v26; // r3
  int v27; // r3
  idPresentable *v28; // r3
  int v29; // r3
  idVehicleWeapon **v30; // r11
  idPresentable *v31; // r3
  idVehicleWeapon *v32; // r30
  idPresentableVehicle *v33; // r31
  int WeaponSlot; // r3
  idPresentable *v35; // r3
  int v36; // r3
  idPresentable *v37; // r3
  idPresentableVehicle *v38; // r3
  int v39; // [sp+50h] [-50h] BYREF

  presentable = this->presentable;
  if ( presentable != nullptr )
    v5 = presentable->GetVehicleInterface(this: presentable);
  else
    v5 = nullptr;
  idPresentableVehicle::DeleteWeapons(this: v5);
  num = key->equippedUpgrades.num;
  v7 = 0;
  if ( num > 0 )
  {
    v8 = 0;
    do
    {
      if ( key->equippedUpgrades.list[v8]->upgradeType == UPGRADE_WEAPONS )
        break;
      ++v7;
      ++v8;
    }
    while ( v7 < num );
  }
  if ( v7 == num )
  {
    v9 = 0;
    if ( this->startingWeapons.num > 0 )
    {
      v10 = 0;
      do
      {
        v11 = this->presentable;
        v12 = (const idDeclVehicleWeapon *)this->startingWeapons.list[v10];
        if ( v11 != nullptr )
          v13 = v11->GetVehicleInterface(this: v11);
        else
          v13 = nullptr;
        idPresentableVehicle::AddWeaponToVehicle(this: v13, decl: v12);
        ++v9;
        ++v10;
      }
      while ( v9 < this->startingWeapons.num );
    }
  }
  v14 = key->equippedUpgrades.num;
  v15 = 0;
  if ( v14 > 0 )
  {
    list = key->equippedUpgrades.list;
    v17 = 0;
    while ( list[v17]->upgradeType != UPGRADE_WEAPONS )
    {
      ++v15;
      ++v17;
      if ( v15 >= v14 )
        goto LABEL_33;
    }
    v18 = list[v15];
    if ( v18->appendDecl.num > 0 )
    {
      v19 = 0;
      v20 = 0;
      do
      {
        parent = (idDeclInfoTemplate<idDeclWeapon> *)v18->appendDecl.list[v20]->GetDeclInfo(this: v18->appendDecl.list[v20]);
        if ( parent != nullptr )
        {
          while ( parent != &idDeclWeapon::resourceList )
          {
            parent = (idDeclInfoTemplate<idDeclWeapon> *)parent->parent;
            if ( parent == nullptr )
              goto LABEL_25;
          }
          v22 = 1;
        }
        else
        {
LABEL_25:
          v22 = 0;
        }
        if ( v22 != 0 )
        {
          v23 = this->presentable;
          v24 = (const idDeclVehicleWeapon *)v18->appendDecl.list[v20];
          if ( v23 != nullptr )
            v25 = v23->GetVehicleInterface(this: v23);
          else
            v25 = nullptr;
          idPresentableVehicle::AddWeaponToVehicle(this: v25, decl: v24);
        }
        ++v19;
        ++v20;
      }
      while ( v19 < v18->appendDecl.num );
    }
  }
LABEL_33:
  v26 = this->presentable;
  if ( v26 != nullptr )
    v27 = (int)v26->GetVehicleInterface(this: v26);
  else
    v27 = 0;
  if ( *(int *)(v27 + 18748) > 0 )
  {
    v28 = this->presentable;
    if ( v28 != nullptr )
      v29 = (int)v28->GetVehicleInterface(this: v28);
    else
      v29 = 0;
    v30 = *(idVehicleWeapon ***)(v29 + 18744);
    v31 = this->presentable;
    v32 = *v30;
    if ( v31 != nullptr )
      v33 = v31->GetVehicleInterface(this: v31);
    else
      v33 = nullptr;
    WeaponSlot = idVehicleWeapon::GetWeaponSlot(this: v32);
    idPresentableVehicle::SetCurrentWeaponGroup(this: v33, newWeaponGroup: WeaponSlot);
    v35 = this->presentable;
    if ( v35 != nullptr )
      v36 = (int)v35->GetVehicleInterface(this: v35);
    else
      v36 = 0;
    v39 = idVehicleWeapon::GetWeaponSlot(this: **(idVehicleWeapon ***)(v36 + 18744));
    idVehicleKey::SetCurrentWeaponGroup(this: key, weaponGroup: &v39, force: false);
    v37 = this->presentable;
    if ( v37 != nullptr )
    {
      v38 = v37->GetVehicleInterface(this: v37);
      idPresentableVehicle::ActivateWeaponGroup(this: v38, notifySound: false);
    }
    else
    {
      idPresentableVehicle::ActivateWeaponGroup(this: nullptr, notifySound: false);
    }
  }
}


// ========================================================================
// ?SetThemeFromKey@idVehicle@@QAAXPAVidVehicleKey@@@Z
// EA  : 0x82D1FE58
// RVA : 0x00D1FE58
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __fastcall idVehicle::SetThemeFromKey(idVehicle *this, idVehicleKey *key)
{
  int v3; // r10
  const idDeclVehicleUpgrade **list; // r8
  int v5; // r11
  idStr *p_normalSkin; // r30
  char *data; // r11
  idDecl *v8; // r30
  int v9; // r28
  const char *FileName; // r27
  int v11; // r26
  const char *v12; // r3
  const idDeclVehicleProps *vehicleProps; // r30
  idPresentable *presentable; // r11
  idDeclSkins *v15; // r27
  char *v16; // r28
  idPresentable *v17; // r30
  int num; // [sp+50h] [-F0h]
  idTypeInfoFile v19; // [sp+60h] [-E0h] BYREF

  v3 = 0;
  num = key->equippedUpgrades.num;
  if ( num <= 0 )
    goto LABEL_5;
  list = key->equippedUpgrades.list;
  v5 = 0;
  while ( list[v5]->upgradeType != UPGRADE_THEME )
  {
    ++v3;
    ++v5;
    if ( v3 >= num )
      goto LABEL_5;
  }
  v8 = &list[v3]->upgradedDef->idDecl;
  if ( v8 != nullptr )
  {
    idTypeInfoFile::idTypeInfoFile(this: &v19, indent_: 0);
    v9 = ((int (__fastcall *)(idDecl *))v8->__vftable[1].List)(a1: v8);
    FileName = idDecl::GetFileName(this: v8);
    v11 = ((int (__fastcall *)(idDecl *))v8->__vftable[1].Print)(a1: v8);
    v12 = (const char *)v8->__vftable[1].GetResourceList(this: v8);
    idTypeInfoFile::ReadMemory(this: &v19, data: v12, length: v11, name: FileName, startLine: v9);
    vehicleProps = this->vehicleProps;
    idGameState::SetEntityEditState(entity: this, file: &v19, includeDefVars: true);
    if ( this->cleanUpVehicleProps )
      this->vehicleProps = vehicleProps;
    idTypeInfoFile::~idTypeInfoFile(this: &v19);
  }
  else
  {
LABEL_5:
    p_normalSkin = &this->normalSkin;
    if ( this->normalSkin.allocedAndFlag >= 0 )
    {
      idStr::FreeData(this: &this->normalSkin);
      p_normalSkin->len = 0;
      this->normalSkin.allocedAndFlag = 20;
      this->normalSkin.data = this->normalSkin.baseBuffer;
      this->normalSkin.baseBuffer[0] = 0;
    }
    else
    {
      data = this->normalSkin.data;
      p_normalSkin->len = 0;
      *data = 0;
    }
  }
  presentable = this->presentable;
  if ( this->normalSkin.len != 0 )
  {
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      presentable = this->presentable;
    }
    v15 = presentable->model->GetSkins(this: presentable->model);
    if ( v15 != nullptr )
    {
      v16 = this->normalSkin.data;
      if ( this->presentable == nullptr )
        idEntity::InitPresentableInternal(this);
      v17 = this->presentable;
      v17->model->g.customSkin = idDeclSkins::IndexForSkin(this: v15, name: v16);
    }
  }
  else
  {
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      presentable = this->presentable;
    }
    presentable->model->g.customSkin = -1;
  }
}


// ========================================================================
// __unwind$509741
// EA  : 0x82D20050
// RVA : 0x00D20050
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void _unwind_509741()
{
  int v0; // r12

  idTypeInfoFile::~idTypeInfoFile(this: (idTypeInfoFile *)(v0 - 320 + 96));
}


// ========================================================================
// ?IsOnElevator@idVehicle@@QAA_NXZ
// EA  : 0x82D20078
// RVA : 0x00D20078
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

int __fastcall idVehicle::IsOnElevator(idVehicle *this)
{
  idPresentable *presentable; // r3
  int v4; // r3
  int v5; // r28
  int v6; // r30
  int i; // r31
  idPresentable *v8; // r3
  int v9; // r3
  idAFConstraint_Suspension *v10; // r3
  int ContactEntity; // r3
  idMover *v12; // r3
  idPhysics *Physics; // r3

  if ( idEntity::GetPhysics(this) == nullptr )
    return 0;
  presentable = this->presentable;
  if ( presentable != nullptr )
    v4 = (int)presentable->GetVehicleInterface(this: presentable);
  else
    v4 = 0;
  v5 = *(_DWORD *)(v4 + 16492);
  v6 = 0;
  if ( v5 > 0 )
  {
    for ( i = 0; ; i += 12 )
    {
      v8 = this->presentable;
      v9 = v8 != nullptr ? (int)v8->GetVehicleInterface(this: v8) : 0;
      v10 = *(idAFConstraint_Suspension **)(*(_DWORD *)(v9 + 16488) + i + 4);
      if ( v10 == nullptr )
        break;
      ContactEntity = idAFConstraint_Suspension::GetContactEntity(this: v10);
      if ( ContactEntity <= 0 )
        break;
      if ( ContactEntity >= 0x2000 )
        break;
      v12 = idMover::CastTo(c: (idMover *)gameLocal->entities.ptr[ContactEntity]);
      if ( v12 == nullptr )
        break;
      Physics = idEntity::GetPhysics(this: v12);
      if ( Physics == nullptr
        || Physics->type != PHYSICS_PARAMETRIC
        || !idPhysics_Parametric::IsPusher(this: (idPhysics_Parametric *)Physics) )
      {
        break;
      }
      if ( ++v6 >= v5 )
        return 1;
    }
    return 0;
  }
  return 1;
}


// ========================================================================
// ?InventoryAdded_Server@idVehicle@@UAAXPAVidInventoryItem@@H@Z
// EA  : 0x82D20188
// RVA : 0x00D20188
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __fastcall idVehicle::InventoryAdded_Server(idVehicle *this, idWeapon *item, int count)
{
  const idDeclInventory *decl; // r26
  int v7; // r25
  int v8; // r27
  const idDeclJob *v9; // r30
  idJobManager *v10; // r3
  idInventoryItem *JobByDecl; // r28
  idPresentable *presentable; // r29
  int num; // r30
  idInventoryCollection *v14; // r3
  idDecl *v15; // r3
  idDeclInventory_vtbl *v16; // r4
  idAttachmentCollection v17[4]; // [sp+50h] [-60h] BYREF

  if ( (unsigned __int8)idDecl::IsType<idDeclVehicleArmorKit>(this: &item->decl->idDeclTypeInfo) != 0 )
  {
    decl = item->decl;
    v7 = 0;
    if ( decl[1].trackedMemory > 0 )
    {
      v8 = 0;
      do
      {
        v9 = *(const idDeclJob **)((char *)&decl[1].dtr_idResource + v8);
        v10 = (idJobManager *)this->GetInventory_2(this);
        JobByDecl = (idInventoryItem *)idJobManager::FindJobByDecl(this: v10, jobDecl: v9);
        if ( JobByDecl != nullptr )
        {
          presentable = this->presentable;
          if ( presentable == nullptr )
          {
            idEntity::InitPresentableInternal(this);
            presentable = this->presentable;
          }
          num = v9->jobLayerInfo.completeLayers.num;
          v14 = this->GetInventory_2(this);
          idInventoryCollection::SetItemCount(
            this: v14,
            owner: presentable,
            item: JobByDecl,
            count: num,
            forceCount: true);
        }
        else
        {
          idVehicle::GiveItem(this, decl: (const idDeclVehicleWeapon *)v9, count: 1, forceCount: false);
        }
        ++v7;
        v8 += 4;
      }
      while ( v7 < decl[1].trackedMemory );
    }
  }
  if ( item->decl->vehicleAttachment )
  {
    idAttachmentCollection::AddAttachment(
      this: v17,
      result: &this->attachments,
      item,
      tagName: "quickuse",
      fxAttachInfo: nullptr);
    idAttachmentCollection::HideAttachment(
      this: &this->attachments,
      handle: (const idHandle<int,enum invalidAttachment_t,-1> *)v17,
      ignoreShowAll: false);
  }
  if ( item->decl->vehiclePermAttachment )
    idAttachmentCollection::AddAttachment(
      this: v17,
      result: &this->attachments,
      item,
      tagName: "attachment",
      fxAttachInfo: nullptr);
  v15 = &item->decl->idDeclTypeInfo;
  if ( v15[4].networkID == 3 && (unsigned __int8)idDecl::IsType<idDeclVehicleQuickUseItem>(this: v15) != 0 )
  {
    v16 = item->decl[1].__vftable;
    if ( v16 != nullptr )
      idVehicle::GiveItem(this, decl: (const idDeclVehicleWeapon *)v16, count, forceCount: false);
  }
}


// ========================================================================
// ?InventoryRemoved@idVehicle@@UAAXPAVidInventoryItem@@@Z
// EA  : 0x82D20320
// RVA : 0x00D20320
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __fastcall idVehicle::InventoryRemoved(idVehicle *this, idInventoryItem *item)
{
  const idDeclInventory *decl; // r27
  int v5; // r26
  int v6; // r28
  const idDeclJob *v7; // r30
  idJobManager *v8; // r3
  idInventoryItem *JobByDecl; // r30
  idPresentable *presentable; // r29
  int v11; // r24
  idInventoryCollection *v12; // r3

  if ( (unsigned __int8)idDecl::IsType<idDeclVehicleArmorKit>(this: &item->decl->idDeclTypeInfo) != 0 )
  {
    decl = item->decl;
    v5 = 0;
    if ( decl[1].trackedMemory > 0 )
    {
      v6 = 0;
      do
      {
        v7 = *(const idDeclJob **)((char *)&decl[1].dtr_idResource + v6);
        v8 = (idJobManager *)this->GetInventory_2(this);
        JobByDecl = (idInventoryItem *)idJobManager::FindJobByDecl(this: v8, jobDecl: v7);
        if ( JobByDecl != nullptr )
        {
          presentable = this->presentable;
          if ( presentable == nullptr )
          {
            idEntity::InitPresentableInternal(this);
            presentable = this->presentable;
          }
          v11 = JobByDecl->GetCount(this: JobByDecl);
          v12 = this->GetInventory_2(this);
          idInventoryCollection::DeleteInventoryItem(this: v12, owner: presentable, item: JobByDecl, count: v11);
        }
        ++v5;
        v6 += 4;
      }
      while ( v5 < decl[1].trackedMemory );
    }
  }
  if ( item->decl->vehicleAttachment )
    idAttachmentCollection::RemoveAttachment(this: &this->attachments, item);
}


// ========================================================================
// ?VisualExitVehicle@idVehicle@@QAAXHHPAVidEntity@@@Z
// EA  : 0x82D20420
// RVA : 0x00D20420
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __fastcall idVehicle::VisualExitVehicle(idVehicle *this, int seat, int delayTime, idEntity *thrownEntity)
{
  idPresentable *presentable; // r3
  int v9; // r3
  int v10; // r31
  idPresentable *v11; // r3
  int v12; // r3
  idVehicleOccupant *VisualAsEntity; // r3
  idPresentable *v14; // r3
  int v15; // r3
  vehicleOccupant_t *Occupant; // r3
  idVehicleOccupant *v17; // r3
  idPresentable *v18; // r3
  int v19; // r3

  if ( vehicle_removeOccupantModel.valueInteger != 0
    || ((double (__fastcall *)(idVehicle *))this->GetHealth)(a1: this) <= 0.0 )
  {
    presentable = this->presentable;
    v9 = presentable != nullptr ? (int)presentable->GetVehicleInterface(this: presentable) : 0;
    v10 = 16 * seat;
    if ( vehicleOccupant_t::GetVisualAsEntity(this: (vehicleOccupant_t *)(*(_DWORD *)(v9 + 16472) + 16 * seat)) != nullptr )
    {
      v11 = this->presentable;
      if ( v11 != nullptr )
        v12 = (int)v11->GetVehicleInterface(this: v11);
      else
        v12 = 0;
      VisualAsEntity = vehicleOccupant_t::GetVisualAsEntity(this: (vehicleOccupant_t *)(*(_DWORD *)(v12 + 16472) + v10));
      idVehicleOccupant::ExitVehicle(this: VisualAsEntity, delayTime, entityToBeThrown: thrownEntity);
      v14 = this->presentable;
      if ( v14 != nullptr )
        v15 = (int)v14->GetVehicleInterface(this: v14);
      else
        v15 = 0;
      if ( vehicleOccupant_t::GetVisualAsEntity(this: (vehicleOccupant_t *)(*(_DWORD *)(v15 + 16472) + v10)) != nullptr
        && thrownEntity == nullptr )
      {
        Occupant = idVehicle::GetOccupant(this, i: seat);
        v17 = vehicleOccupant_t::GetVisualAsEntity(this: Occupant);
        idEventReceiver::PostEventMS(this: v17, ev: &EV_Remove, time: 0);
      }
      v18 = this->presentable;
      if ( v18 != nullptr )
        v19 = (int)v18->GetVehicleInterface(this: v18);
      else
        v19 = 0;
      *(_DWORD *)(*(_DWORD *)(v19 + 16472) + v10 + 4) = 0;
    }
  }
}


// ========================================================================
// ?AllowOccupantExitVehicle@idVehicle@@QAAXH_N@Z
// EA  : 0x82D20588
// RVA : 0x00D20588
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __fastcall idVehicle::AllowOccupantExitVehicle(idVehicle *this, int seat, bool bl)
{
  idPresentable *presentable; // r3
  int v6; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
    v6 = (int)presentable->GetVehicleInterface(this: presentable);
  else
    v6 = 0;
  *(_BYTE *)(*(_DWORD *)(v6 + 16472) + 16 * seat + 12) = (bl << 7)
                                                       | *(_BYTE *)(*(_DWORD *)(v6 + 16472) + 16 * seat + 12) & 0x7F;
}


// ========================================================================
// ?AllowOccupantSwapSeats@idVehicle@@QAAXH_N@Z
// EA  : 0x82D20600
// RVA : 0x00D20600
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __fastcall idVehicle::AllowOccupantSwapSeats(idVehicle *this, int seat, bool bl)
{
  idPresentable *presentable; // r3
  int v6; // r3
  _BYTE *v7; // r10

  presentable = this->presentable;
  if ( presentable != nullptr )
    v6 = (int)presentable->GetVehicleInterface(this: presentable);
  else
    v6 = 0;
  v7 = (_BYTE *)(*(_DWORD *)(v6 + 16472) + 16 * seat + 12);
  *v7 = (bl << 6) & 0x40 | *v7 & 0xBF;
}


// ========================================================================
// ?GetCachedPlayerDriver@idVehicle@@QBAPAVidEntity@@XZ
// EA  : 0x82D20678
// RVA : 0x00D20678
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

idEntity *__fastcall idVehicle::GetCachedPlayerDriver(idVehicle *this)
{
  int value; // r10
  idEntity *v2; // r3

  value = this->cachedPlayerDriver.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v2 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    return idEntity::CastTo(c: v2);
  }
  else
  {
    return nullptr;
  }
}


// ========================================================================
// ?GetFaction@idVehicle@@UBAPBVidFaction@@XZ
// EA  : 0x82D20700
// RVA : 0x00D20700
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

const idFaction *__fastcall idVehicle::GetFaction(idVehicle *this)
{
  idPresentable *presentable; // r3
  idPresentableVehicle *v3; // r3
  idPresentable *Driver; // r3
  idVehicle *entity; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
  {
    v3 = presentable->GetVehicleInterface(this: presentable);
    if ( v3 != nullptr )
    {
      Driver = idPresentableVehicle::GetDriver(this: v3);
      if ( Driver != nullptr )
      {
        entity = (idVehicle *)Driver->entity;
        if ( entity != nullptr )
          return entity->GetFaction(this: entity);
      }
    }
  }
  entity = (idVehicle *)idVehicle::GetGunner(this);
  if ( entity != nullptr && entity != this )
    return entity->GetFaction(this: entity);
  else
    return nullptr;
}


// ========================================================================
// ?GetFaction@idVehicle@@UAAPAVidFaction@@XZ
// EA  : 0x82D207A8
// RVA : 0x00D207A8
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

idFaction *__fastcall idVehicle::GetFaction(idVehicle *this)
{
  idPresentable *presentable; // r3
  idPresentableVehicle *v3; // r3
  idPresentable *Driver; // r3
  idFaction *result; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
  {
    v3 = presentable->GetVehicleInterface(this: presentable);
    if ( v3 != nullptr )
    {
      Driver = idPresentableVehicle::GetDriver(this: v3);
      if ( Driver != nullptr )
      {
        result = (idFaction *)Driver->entity;
        if ( result != nullptr )
          return ((idFaction *(__fastcall *)(idFaction *))result->myFaction[4].declSource)(a1: result);
      }
    }
  }
  result = (idFaction *)idVehicle::GetGunner(this);
  if ( result != nullptr )
    return ((idFaction *(__fastcall *)(idFaction *))result->myFaction[4].declSource)(a1: result);
  return result;
}


// ========================================================================
// ?GetInputSettings@idVehicle@@UAA?AUinputSettings_t@@PAVidPlayer@@@Z
// EA  : 0x82D20840
// RVA : 0x00D20840
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

idVehicle *__fastcall idVehicle::GetInputSettings(idVehicle *this, idVehicle *result, idPlayer *player)
{
  float v4; // r3
  idPresentableVehicle *v7; // r3
  idPlayer *entity; // r11
  idPresentable *Driver; // r3
  char valueInteger; // r11
  char v11; // r10
  bool v12; // xer_ca
  double valueFloat; // fp11
  char IsPassenger; // r3
  char v15; // r11
  double v16; // fp13
  double v17; // fp11
  char v18; // r10
  bool v19; // xer_ca
  idVehicle *v20; // r3
  double v21; // fp12
  bool v22; // zf
  double v23; // fp12
  double v24; // fp13

  v4 = *(float *)&result->presentable;
  if ( v4 != 0.0
    && (v7 = (idPresentableVehicle *)(*(int (__fastcall **)(double))(*(_DWORD *)LODWORD(v4) + 76))(a1: COERCE_DOUBLE(LODWORD(v4)))) != nullptr )
  {
    Driver = idPresentableVehicle::GetDriver(this: v7);
    entity = nullptr;
    if ( Driver != nullptr )
      entity = (idPlayer *)Driver->entity;
  }
  else
  {
    entity = nullptr;
  }
  if ( player == entity )
  {
    valueInteger = in_invertLook.valueInteger;
    v12 = in_invertLook.valueInteger != 0;
    v11 = LOBYTE(in_invertLook.valueInteger) - 1;
    this->__vftable = (idVehicle_vtbl *)2;
    valueFloat = m_sensitivity.valueFloat;
    this->name.baseBuffer[0] = 1;
    this->name.baseBuffer[1] = valueInteger - (v11 + !v12);
LABEL_14:
    v23 = joy_yawSpeed.valueFloat;
    v24 = joy_pitchSpeed.valueFloat;
    *(float *)&this->name.allocedAndFlag = valueFloat;
    *(float *)&this->name.data = v23;
    *(float *)&this->name.len = v24;
    *(float *)&this->listeningToList = 1.0;
    *(float *)&this->listenerList = 1.0;
    return this;
  }
  if ( player != idVehicle::GetGunner(this: result) )
  {
    this->__vftable = nullptr;
    this->name.baseBuffer[0] = 0;
    valueFloat = m_sensitivity.valueFloat;
    this->name.baseBuffer[1] = in_invertLook.valueInteger != 0;
    goto LABEL_14;
  }
  IsPassenger = idVehicle::IsPassenger(this: result, player);
  v15 = in_invertLook.valueInteger;
  v16 = joy_pitchSpeed.valueFloat;
  v17 = m_sensitivity.valueFloat;
  v19 = in_invertLook.valueInteger != 0;
  v18 = LOBYTE(in_invertLook.valueInteger) - 1;
  v21 = joy_yawSpeed.valueFloat;
  *(float *)&this->listenerList = 1.0;
  *(float *)&this->listeningToList = 1.0;
  *(float *)&this->name.len = v16;
  *(float *)&this->name.data = v21;
  *(float *)&this->name.allocedAndFlag = v17;
  v22 = IsPassenger == 0;
  v20 = this;
  if ( v22 )
  {
    this->__vftable = (idVehicle_vtbl *)5;
    this->name.baseBuffer[0] = 1;
  }
  else
  {
    this->name.baseBuffer[0] = 0;
    this->__vftable = (idVehicle_vtbl *)6;
  }
  this->name.baseBuffer[1] = v15 - (v18 + !v19);
  return v20;
}


// ========================================================================
// ?TransferPlayerAmmoToVehicle@idVehicle@@QAAXPAVidPlayer@@@Z
// EA  : 0x82D20A10
// RVA : 0x00D20A10
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __fastcall idVehicle::TransferPlayerAmmoToVehicle(idVehicle *this, idPlayer *player)
{
  idPresentable *presentable; // r3
  int v5; // r3
  int v6; // r27
  int i; // r29
  idPresentable *v8; // r3
  int v9; // r3
  idPresentable *v10; // r3
  int v11; // r3
  const idDeclJob *v12; // r31
  idJobManager *v13; // r3
  idInventoryItem *JobByDecl; // r30
  idPresentable *v15; // r31
  idInventoryCollection *v16; // r3
  int v17; // r27
  int j; // r29
  idPresentable *v19; // r3
  int v20; // r3
  idPresentable *v21; // r3
  int v22; // r3
  const idDeclJob *v23; // r31
  idJobManager *v24; // r3
  idPresentable *v25; // r30
  idPresentable *v26; // r31
  idInventoryCollection *v27; // r3
  idPresentable *v28; // r3
  int v29; // r3
  idJob *v30; // [sp+50h] [-50h] BYREF

  if ( vehicle_transferPlayerAmmo.valueInteger != 0 )
  {
    presentable = player->presentable;
    if ( presentable != nullptr )
      v5 = (int)presentable->GetPlayerInterface_2(this: presentable);
    else
      v5 = 0;
    idPlayerHud::SetIgnorePickupUpdate(this: (idPlayerHud *)(v5 + 35096), ignore: true);
    v6 = 0;
    for ( i = 0; ; i += 4 )
    {
      v8 = this->presentable;
      v9 = v8 != nullptr ? (int)v8->GetVehicleInterface(this: v8) : 0;
      if ( v6 >= *(_DWORD *)(v9 + 18748) )
        break;
      v10 = this->presentable;
      if ( v10 != nullptr )
        v11 = (int)v10->GetVehicleInterface(this: v10);
      else
        v11 = 0;
      v12 = *(const idDeclJob **)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v11 + 18744) + i) + 40) + 44) + 12);
      v13 = (idJobManager *)this->GetInventory_2(this);
      JobByDecl = (idInventoryItem *)idJobManager::FindJobByDecl(this: v13, jobDecl: v12);
      if ( JobByDecl != nullptr )
      {
        v15 = this->presentable;
        if ( v15 == nullptr )
        {
          idEntity::InitPresentableInternal(this);
          v15 = this->presentable;
        }
        v16 = this->GetInventory_2(this);
        idInventoryCollection::RemoveItemFromInventory(this: v16, owner: v15, item: JobByDecl);
      }
      ++v6;
    }
    v17 = 0;
    for ( j = 0; ; j += 4 )
    {
      v19 = this->presentable;
      v20 = v19 != nullptr ? (int)v19->GetVehicleInterface(this: v19) : 0;
      if ( v17 >= *(_DWORD *)(v20 + 18748) )
        break;
      v21 = this->presentable;
      if ( v21 != nullptr )
        v22 = (int)v21->GetVehicleInterface(this: v21);
      else
        v22 = 0;
      v23 = *(const idDeclJob **)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v22 + 18744) + j) + 40) + 44) + 12);
      v24 = (idJobManager *)player->GetInventory_2(this: player);
      v30 = idJobManager::FindJobByDecl(this: v24, jobDecl: v23);
      if ( v30 != nullptr )
      {
        if ( this->presentable == nullptr )
          idEntity::InitPresentableInternal(this);
        v25 = this->presentable;
        v26 = player->presentable;
        if ( v26 == nullptr )
        {
          idEntity::InitPresentableInternal(this: player);
          v26 = player->presentable;
        }
        v27 = player->GetInventory_2(this: player);
        idInventoryCollection::TransferItem(
          this: v27,
          owner: v26,
          to: v25,
          item: (idInventoryItem **)&v30,
          deleteOwnerItem: true,
          canIntro: false);
      }
      ++v17;
    }
    v28 = player->presentable;
    if ( v28 != nullptr )
    {
      v29 = (int)v28->GetPlayerInterface_2(this: v28);
      idPlayerHud::SetIgnorePickupUpdate(this: (idPlayerHud *)(v29 + 35096), ignore: false);
    }
    else
    {
      idPlayerHud::SetIgnorePickupUpdate(this: (idPlayerHud *)0x8918, ignore: false);
    }
  }
}


// ========================================================================
// ?TransferVehicleAmmoToPlayer@idVehicle@@QAAXPAVidPlayer@@@Z
// EA  : 0x82D20CA0
// RVA : 0x00D20CA0
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __fastcall idVehicle::TransferVehicleAmmoToPlayer(idVehicle *this, idPlayer *player)
{
  idPresentable *presentable; // r3
  int v5; // r3
  int v6; // r27
  int i; // r28
  idPresentable *v8; // r3
  int v9; // r3
  idPresentable *v10; // r3
  int v11; // r3
  const idDeclJob *v12; // r31
  idJobManager *v13; // r3
  idPresentable *v14; // r30
  idPresentable *v15; // r31
  idInventoryCollection *v16; // r3
  idPresentable *v17; // r3
  int v18; // r3
  idJob *JobByDecl; // [sp+50h] [-50h] BYREF

  if ( vehicle_transferPlayerAmmo.valueInteger != 0 )
  {
    presentable = player->presentable;
    if ( presentable != nullptr )
      v5 = (int)presentable->GetPlayerInterface_2(this: presentable);
    else
      v5 = 0;
    idPlayerHud::SetIgnorePickupUpdate(this: (idPlayerHud *)(v5 + 35096), ignore: true);
    v6 = 0;
    for ( i = 0; ; i += 4 )
    {
      v8 = this->presentable;
      v9 = v8 != nullptr ? (int)v8->GetVehicleInterface(this: v8) : 0;
      if ( v6 >= *(_DWORD *)(v9 + 18748) )
        break;
      v10 = this->presentable;
      if ( v10 != nullptr )
        v11 = (int)v10->GetVehicleInterface(this: v10);
      else
        v11 = 0;
      v12 = *(const idDeclJob **)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v11 + 18744) + i) + 40) + 44) + 12);
      v13 = (idJobManager *)this->GetInventory_2(this);
      JobByDecl = idJobManager::FindJobByDecl(this: v13, jobDecl: v12);
      if ( JobByDecl != nullptr )
      {
        if ( player->presentable == nullptr )
          idEntity::InitPresentableInternal(this: player);
        v14 = player->presentable;
        v15 = this->presentable;
        if ( v15 == nullptr )
        {
          idEntity::InitPresentableInternal(this);
          v15 = this->presentable;
        }
        v16 = this->GetInventory_2(this);
        idInventoryCollection::TransferItem(
          this: v16,
          owner: v15,
          to: v14,
          item: (idInventoryItem **)&JobByDecl,
          deleteOwnerItem: true,
          canIntro: false);
      }
      ++v6;
    }
    v17 = player->presentable;
    if ( v17 != nullptr )
    {
      v18 = (int)v17->GetPlayerInterface_2(this: v17);
      idPlayerHud::SetIgnorePickupUpdate(this: (idPlayerHud *)(v18 + 35096), ignore: false);
    }
    else
    {
      idPlayerHud::SetIgnorePickupUpdate(this: (idPlayerHud *)0x8918, ignore: false);
    }
  }
}


// ========================================================================
// ?SetExitPosition@idVehicle@@QAAXPAVidEntity@@MW4vehicleSeat_t@@@Z
// EA  : 0x82D20E50
// RVA : 0x00D20E50
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __fastcall idVehicle::SetExitPosition(
        idVehicle *this,
        idPlayer *entity,
        double zOffset,
        vehicleSeat_t seat,
        int a5)
{
  char v9; // r22
  idPhysics *Physics; // r3
  int v11; // r3
  float v12; // r6
  float v13; // r5
  int v14; // r30
  float *v15; // r11
  idPhysics *v16; // r28
  idPhysics *v17; // r3
  idPhysics *v18; // r30
  int v19; // r24
  double v20; // fp27
  float *v21; // r3
  double v22; // fp26
  double v23; // fp25
  double v24; // fp24
  double v25; // fp27
  float *v26; // r3
  double v27; // fp7
  double v28; // fp3
  int i; // r23
  idPhysics *v30; // r3
  double valueFloat; // fp27
  float *v32; // r3
  int v33; // r28
  float *v34; // r30
  double v35; // fp6
  double v36; // fp4
  idPhysics *v37; // r20
  idPhysics *v38; // r19
  double v39; // fp27
  float *v40; // r3
  double v41; // fp26
  double v42; // fp25
  double v43; // fp24
  double v44; // fp27
  float *v45; // r3
  double v46; // fp7
  double v47; // fp3
  idPhysics *v48; // r3
  idPlayer *v49; // r30
  idPhysics *v50; // r3
  int v51; // r3
  float v52; // r8
  int v53; // r6
  idPhysics *v54; // r3
  float *v55; // r3
  double v56; // fp0
  double v57; // fp12
  double v58; // fp8
  double v59; // fp7
  double v60; // fp6
  double v61; // fp5
  int v62; // [sp+8h] [-2B8h]
  bool v63; // [sp+Fh] [-2B1h]
  const char *v64; // [sp+10h] [-2B0h]
  int v65; // [sp+14h] [-2ACh]
  int v66; // [sp+18h] [-2A8h]
  int v67; // [sp+1Ch] [-2A4h]
  int v68; // [sp+20h] [-2A0h]
  int v69; // [sp+24h] [-29Ch]
  int v70; // [sp+28h] [-298h]
  int v71; // [sp+2Ch] [-294h]
  int v72; // [sp+30h] [-290h]
  int v73; // [sp+34h] [-28Ch]
  int v74; // [sp+38h] [-288h]
  int v75; // [sp+3Ch] [-284h]
  int v76; // [sp+40h] [-280h]
  int v77; // [sp+44h] [-27Ch]
  int v78; // [sp+48h] [-278h]
  int v79; // [sp+4Ch] [-274h]
  int v80; // [sp+50h] [-270h]
  int entityNumber; // [sp+54h] [-26Ch]
  int v82; // [sp+54h] [-26Ch]
  int v83; // [sp+58h] [-268h]
  int v84; // [sp+60h] [-260h]
  idVec3 v85; // [sp+70h] [-250h] BYREF
  idVec3 v86; // [sp+80h] [-240h] BYREF
  float v87; // [sp+90h] [-230h] BYREF
  float v88; // [sp+94h] [-22Ch]
  int v89; // [sp+98h] [-228h]
  idMat3 v90; // [sp+A0h] [-220h] BYREF
  float v91; // [sp+C4h] [-1FCh]
  float v92; // [sp+C8h] [-1F8h]
  float v93; // [sp+CCh] [-1F4h]
  float v94; // [sp+D0h] [-1F0h]
  float v95; // [sp+E0h] [-1E0h] BYREF
  float v96; // [sp+E4h] [-1DCh] BYREF
  float v97[10]; // [sp+E8h] [-1D8h] BYREF
  trace_t v98; // [sp+110h] [-1B0h] BYREF
  trace_t v99; // [sp+190h] [-130h] BYREF

  v95 = 0.0;
  v96 = 100.0;
  v97[0] = 0.0;
  v97[1] = 0.0;
  LODWORD(v97[3]) = 1;
  v97[2] = -100.0;
  LODWORD(v97[6]) = 2;
  v97[4] = 150.0;
  LODWORD(v97[9]) = 2;
  v97[5] = 0.0;
  v9 = 0;
  v97[7] = -150.0;
  v97[8] = 0.0;
  Physics = idEntity::GetPhysics(this);
  v11 = (int)Physics->GetOrigin(this: Physics, a2: 0);
  v12 = *(float *)(v11 + 4);
  v13 = *(float *)(v11 + 8);
  v85.x = *(float *)v11;
  v85.y = v12;
  v85.z = v13;
  if ( a5 != 2 )
  {
    v14 = 0;
    v15 = v97;
    while ( *(_DWORD *)v15 != a5 )
    {
      ++v14;
      v15 += 3;
      if ( v14 >= 4 )
        goto LABEL_8;
    }
    v16 = idEntity::GetPhysics(this);
    v17 = idEntity::GetPhysics(this);
    v19 = 12 * v14;
    v20 = v97[3 * v14 - 1];
    v18 = v17;
    v21 = (float *)v16->GetAxis(this: v16, a2: 0);
    v22 = (float)(v21[3] * (float)v20);
    v23 = (float)(v21[4] * (float)v20);
    v24 = *(float *)((char *)&v95 + v19);
    v25 = (float)(v21[5] * (float)v20);
    v26 = (float *)v18->GetAxis(this: v18, a2: 0);
    v27 = (float)(v26[2] * (float)v24);
    v28 = (float)(v26[1] * (float)v24);
    entityNumber = this->entityNumber;
    v86.x = (float)(v85.x + (float)(*v26 * (float)v24)) + (float)v22;
    v86.y = (float)(v85.y + (float)v28) + (float)v23;
    v86.z = (float)((float)(v85.z + (float)v27) + (float)v25) + (float)10.0;
    idClip::Translation(
      this: (idClip *)&v87,
      result: &clientGame->clip,
      a3: &v98,
      start: &v85,
      end: &v86,
      clipModel: clientGame->clip.clip48x48x96,
      startAxis: &mat3_identity,
      clipMask: 107529,
      passEntityNumber: v62,
      moveClipModel: v63,
      userName: v64,
      a12: v65,
      a13: v66,
      a14: v67,
      a15: v68,
      a16: v69,
      a17: v70,
      a18: v71,
      a19: v72,
      a20: v73,
      a21: v74,
      a22: v75,
      a23: v76,
      a24: v77,
      a25: v78,
      a26: v79,
      a27: v80,
      a28: entityNumber,
      a29: v83,
      a30: false,
      a31: v84,
      a32: 0);
    if ( v98.fraction == 1.0 )
      v9 = 1;
  }
LABEL_8:
  if ( v9 == 0 )
  {
    for ( i = 0; i < 5; ++i )
    {
      if ( v9 != 0 )
        break;
      v30 = idEntity::GetPhysics(this);
      valueFloat = vehicle_exitSpotZofs.valueFloat;
      v32 = (float *)v30->GetAxis(this: v30, a2: 0);
      v33 = 0;
      v34 = &v95;
      v35 = (float)(v32[8] * (float)valueFloat);
      v36 = (float)((float)(v32[7] * (float)valueFloat) + v85.y);
      v85.x = (float)((float)valueFloat * v32[6]) + v85.x;
      v85.y = v36;
      v85.z = (float)v35 + v85.z;
      while ( 1 )
      {
        v37 = idEntity::GetPhysics(this);
        v38 = idEntity::GetPhysics(this);
        v39 = v34[1];
        v40 = (float *)v37->GetAxis(this: v37, a2: 0);
        v41 = *v34;
        v42 = (float)(v40[3] * (float)v39);
        v43 = (float)(v40[4] * (float)v39);
        v44 = (float)(v40[5] * (float)v39);
        v45 = (float *)v38->GetAxis(this: v38, a2: 0);
        v46 = (float)(v45[2] * (float)v41);
        v47 = (float)(v45[1] * (float)v41);
        v82 = this->entityNumber;
        v86.x = (float)((float)(*v45 * (float)v41) + v85.x) + (float)v42;
        v86.y = (float)((float)v47 + v85.y) + (float)v43;
        v86.z = (float)((float)((float)v46 + v85.z) + (float)v44) + (float)10.0;
        idClip::Translation(
          this: (idClip *)&v87,
          result: &clientGame->clip,
          a3: &v99,
          start: &v85,
          end: &v86,
          clipModel: clientGame->clip.clip48x48x96,
          startAxis: &mat3_identity,
          clipMask: 107529,
          passEntityNumber: v62,
          moveClipModel: v63,
          userName: v64,
          a12: v65,
          a13: v66,
          a14: v67,
          a15: v68,
          a16: v69,
          a17: v70,
          a18: v71,
          a19: v72,
          a20: v73,
          a21: v74,
          a22: v75,
          a23: v76,
          a24: v77,
          a25: v78,
          a26: v79,
          a27: v80,
          a28: v82,
          a29: v83,
          a30: false,
          a31: v84,
          a32: 0);
        if ( v99.fraction == 1.0 )
          break;
        ++v33;
        v34 += 3;
        if ( v33 >= 4 )
          goto LABEL_16;
      }
      v9 = 1;
LABEL_16:
      ;
    }
  }
  v86.z = (float)(this->exitVehicleZDelta + v86.z) + (float)zOffset;
  v48 = idEntity::GetPhysics(this: entity);
  v48->SetOrigin(this: v48, a2: &v86, a3: -1);
  v49 = idPlayer::CastTo(c: entity);
  if ( v49 != nullptr )
  {
    v50 = idEntity::GetPhysics(this);
    v51 = (int)v50->GetAxis(this: v50, a2: 0);
    v52 = *(float *)v51;
    v53 = *(_DWORD *)(v51 + 8);
    v88 = *(float *)(v51 + 4);
    v90.mat[2].x = 0.0;
    v87 = v52;
    v90.mat[1].y = v52;
    v89 = v53;
    v90.mat[1].z = v88;
    v54 = idEntity::GetPhysics(this);
    v55 = (float *)v54->GetGravityNormal(this: v54);
    v56 = *v55;
    v57 = (float)(*v55 * v90.mat[1].z);
    v92 = *v55;
    v58 = (float)(v55[1] * v90.mat[2].x);
    v59 = (float)((float)(v55[1] * v90.mat[1].y) - (float)v57);
    v93 = v55[1];
    v60 = (float)(v55[2] * v90.mat[1].y);
    v61 = (float)((float)(v55[2] * v90.mat[1].z) - (float)v58);
    v94 = v55[2];
    v91 = v59;
    v90.mat[2].y = v61;
    v90.mat[2].z = (float)((float)v56 * v90.mat[2].x) - (float)v60;
    idMat3::OrthoNormalizeSelf(this: (idMat3 *)&v90.mat[1].y);
    idMat3::ToAngles(this: &v90, result: (idAngles *)&v90.mat[1].y);
    v90.mat[0].x = v90.mat[0].x + (float)10.0;
    idPlayer::SetViewAngles(this: v49, angles: (const idAngles *)&v90, force: true);
    v49->Teleport(this: v49, a2: &v86, a3: (const idAngles *)&v90);
    usercmdGen->ClearAngles(this: usercmdGen);
  }
}


// ========================================================================
// ?GetOccupantVisual@idVehicle@@QBAPAVidVehicleOccupant@@H@Z
// EA  : 0x82D21390
// RVA : 0x00D21390
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

idVehicleOccupant *__fastcall idVehicle::GetOccupantVisual(idVehicle *this, int index)
{
  idPresentable *presentable; // r3
  int v5; // r3
  idPresentable *v7; // r3
  int v8; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
    v5 = (int)presentable->GetVehicleInterface(this: presentable);
  else
    v5 = 0;
  if ( index >= *(_DWORD *)(v5 + 16476) )
    return nullptr;
  v7 = this->presentable;
  if ( v7 != nullptr )
    v8 = (int)v7->GetVehicleInterface(this: v7);
  else
    v8 = 0;
  return vehicleOccupant_t::GetVisualAsEntity(this: (vehicleOccupant_t *)(*(_DWORD *)(v8 + 16472) + 16 * index));
}


// ========================================================================
// ?GetOccupantNPC@idVehicle@@QAAPAVidAI2@@H@Z
// EA  : 0x82D21430
// RVA : 0x00D21430
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

idAI2 *__fastcall idVehicle::GetOccupantNPC(idVehicle *this, int index)
{
  idPresentable *presentable; // r3
  int v4; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
    v4 = (int)presentable->GetVehicleInterface(this: presentable);
  else
    v4 = 0;
  return vehicleOccupant_t::GetNpcAsEntity(this: (vehicleOccupant_t *)(*(_DWORD *)(v4 + 16472) + 16 * index));
}


// ========================================================================
// ?UpdateDetachableItems@idVehicle@@QAAXXZ
// EA  : 0x82D21490
// RVA : 0x00D21490
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __fastcall idVehicle::UpdateDetachableItems(idVehicle *this)
{
  int valueInteger; // r11
  int v3; // r9
  unsigned int v4; // r30
  idPlayer *v5; // r3
  int v6; // r29
  int v7; // r30
  const idDeclInventory *v8; // r28
  idJobManager *v9; // r3
  const idDeclVehicleUpgrade *tiresSpiked; // r27
  int v11; // r28
  int v12; // r29
  int num; // r7
  int v14; // r10
  int v15; // r11
  int v16; // r7
  int v17; // r10
  int v18; // r11
  const idDeclInventory *decl; // r30
  idJobManager *v20; // r3
  const idIndex<short,enum invalidJointIndex_t> *value; // r30
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  int v23; // r28
  int v24; // r29
  int v25; // r10
  int v26; // r9
  detachable_t *list; // r8
  int v28; // r11
  const idIndex<short,enum invalidJointIndex_t> *v29; // r30
  idTreeAnimator *v30; // r3
  int v31; // r28
  int v32; // r29
  int v33; // r30
  int v34; // r10
  int v35; // r11
  idPresentable *presentable; // r3
  const idIndex<short,enum invalidJointIndex_t> *v37; // r30
  idPresentable *v38; // r3
  idPresentableAnimatedEntity *v39; // r3
  idTreeAnimator *v40; // r3
  char *data; // r30
  idIndex<short,enum invalidJointIndex_t> *v42; // r3
  const idIndex<short,enum invalidJointIndex_t> *v43; // r30
  idTreeAnimator *v44; // r3
  unsigned __int16 v45; // [sp+50h] [-60h] BYREF
  idVec3 v46; // [sp+58h] [-58h] BYREF

  valueInteger = vehicle_tireUpgrades.valueInteger;
  v3 = -vehicle_tireUpgrades.valueInteger & ~vehicle_tireUpgrades.valueInteger;
  v4 = (unsigned int)v3 >> 31;
  if ( v3 < 0 && vehicle_tireUpgrades.valueInteger <= 3 )
  {
    v5 = idVehicle::PlayerIsOccupant(this);
    valueInteger = vehicle_tireUpgrades.valueInteger;
    LOBYTE(v4) = v5 == nullptr ? 0 : v4;
  }
  if ( (_BYTE)v4 != 0 )
  {
    tiresSpiked = nullptr;
    switch ( valueInteger )
    {
      case 1:
      case 4:
        tiresSpiked = this->tiresSpiked;
        break;
      case 2:
      case 5:
        tiresSpiked = this->tiresUpgraded;
        break;
      case 3:
      case 6:
        tiresSpiked = this->tiresUpgradedSpiked;
        break;
      default:
        break;
    }
    v11 = 0;
    if ( this->detachableItems.num > 0 )
    {
      v12 = 0;
      do
      {
        if ( tiresSpiked == nullptr )
          goto LABEL_34;
        num = tiresSpiked->removeDecl.num;
        v14 = 0;
        if ( num > 0 )
        {
          v15 = 0;
          do
          {
            if ( tiresSpiked->removeDecl.list[v15] == this->detachableItems.list[v12].decl )
              break;
            ++v14;
            ++v15;
          }
          while ( v14 < num );
        }
        if ( v14 >= num )
        {
          v16 = tiresSpiked->appendDecl.num;
          v17 = 0;
          if ( v16 > 0 )
          {
            v18 = 0;
            do
            {
              if ( tiresSpiked->appendDecl.list[v18] == this->detachableItems.list[v12].decl )
                break;
              ++v17;
              ++v18;
            }
            while ( v17 < v16 );
          }
          if ( v17 >= v16 )
          {
LABEL_34:
            decl = this->detachableItems.list[v12].decl;
            v20 = (idJobManager *)this->GetInventory_2(this);
            if ( idJobManager::FindJobByDecl(this: v20, jobDecl: (const idDeclJob *)decl) != nullptr )
            {
              idVehicle::TransformDetachable(this, index: v11);
            }
            else
            {
              value = (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)this->detachableItems.list[v12].jointIndex.value;
              if ( idAnimatedEntity::GetTreeAnimatorFromPresentable(this) != nullptr && (__int16)value >= 0 )
              {
                TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
                idTreeAnimator::SetJointScale(
                  this: TreeAnimatorFromPresentable,
                  pose: (animationPose_t)0,
                  jointIndex: value,
                  type: JOINTMOD_LOCAL,
                  scale: &vec3_origin);
              }
            }
          }
        }
        ++v11;
        ++v12;
      }
      while ( v11 < this->detachableItems.num );
    }
    if ( tiresSpiked != nullptr )
    {
      v23 = 0;
      if ( tiresSpiked->removeDecl.num > 0 )
      {
        v24 = 0;
        do
        {
          v25 = 0;
          v26 = this->detachableItems.num;
          if ( v26 > 0 )
          {
            list = this->detachableItems.list;
            v28 = 0;
            while ( tiresSpiked->removeDecl.list[v24] != list[v28].decl )
            {
              ++v25;
              ++v28;
              if ( v25 >= v26 )
                goto LABEL_51;
            }
            v29 = (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)list[v25].jointIndex.value;
            if ( idAnimatedEntity::GetTreeAnimatorFromPresentable(this) != nullptr && (__int16)v29 >= 0 )
            {
              v30 = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
              idTreeAnimator::SetJointScale(
                this: v30,
                pose: (animationPose_t)0,
                jointIndex: v29,
                type: JOINTMOD_LOCAL,
                scale: &vec3_origin);
            }
          }
LABEL_51:
          ++v23;
          ++v24;
        }
        while ( v23 < tiresSpiked->removeDecl.num );
      }
      v31 = 0;
      if ( tiresSpiked->appendDecl.num > 0 )
      {
        v32 = 0;
        do
        {
          v33 = 0;
          v34 = this->detachableItems.num;
          if ( v34 > 0 )
          {
            v35 = 0;
            while ( tiresSpiked->appendDecl.list[v32] != this->detachableItems.list[v35].decl )
            {
              ++v33;
              ++v35;
              if ( v33 >= v34 )
                goto LABEL_67;
            }
            idVehicle::TransformDetachable(this, index: v33);
            presentable = this->presentable;
            v37 = (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)this->detachableItems.list[v33].jointIndex.value;
            if ( presentable != nullptr && presentable->GetAnimatedEntityInterface(this: presentable) != nullptr )
            {
              v38 = this->presentable;
              v39 = v38 != nullptr ? v38->GetAnimatedEntityInterface(this: v38) : nullptr;
              if ( idPresentableAnimatedEntity::GetTreeAnimator(this: v39) != nullptr && (__int16)v37 >= 0 )
              {
                v46.x = 1.0;
                v46.y = 1.0;
                v46.z = 1.0;
                v40 = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
                idTreeAnimator::SetJointScale(
                  this: v40,
                  pose: (animationPose_t)0,
                  jointIndex: v37,
                  type: JOINTMOD_LOCAL,
                  scale: &v46);
              }
            }
          }
LABEL_67:
          ++v31;
          ++v32;
        }
        while ( v31 < tiresSpiked->appendDecl.num );
      }
    }
  }
  else
  {
    v6 = 0;
    if ( this->detachableItems.num > 0 )
    {
      v7 = 0;
      do
      {
        v8 = this->detachableItems.list[v7].decl;
        v9 = (idJobManager *)this->GetInventory_2(this);
        if ( idJobManager::FindJobByDecl(this: v9, jobDecl: (const idDeclJob *)v8) != nullptr )
          idVehicle::TransformDetachable(this, index: v6);
        else
          idVehicle::CollapseJointByIndex(
            this,
            jointIndex: (idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)this->detachableItems.list[v7].jointIndex.value,
            bl: true);
        ++v6;
        ++v7;
      }
      while ( v6 < this->detachableItems.num );
    }
  }
  data = vehicle_collapseJoint.valueString.data;
  if ( vehicle_collapseJoint.valueString.data != nullptr
    && *vehicle_collapseJoint.valueString.data != 0
    && vehicle_collapseJoint.valueString.data[1] != 0 )
  {
    v42 = (idIndex<short,enum invalidJointIndex_t> *)idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
    idTreeAnimator::GetJointIndex(this: (idTreeAnimator *)&v45, result: v42, jointName: data);
    v43 = (const idIndex<short,enum invalidJointIndex_t> *)v45;
    if ( idAnimatedEntity::GetTreeAnimatorFromPresentable(this) != nullptr && (__int16)v43 >= 0 )
    {
      v44 = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
      idTreeAnimator::SetJointScale(
        this: v44,
        pose: (animationPose_t)0,
        jointIndex: v43,
        type: JOINTMOD_LOCAL,
        scale: &vec3_origin);
    }
  }
}


// ========================================================================
// ?UsesAmmo@idVehicle@@QAA_NPBVidDeclInventory@@@Z
// EA  : 0x82D21948
// RVA : 0x00D21948
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

int __fastcall idVehicle::UsesAmmo(idVehicle *this, const idDeclInventory *ammoDecl)
{
  int v4; // r30
  int i; // r31
  idPresentable *presentable; // r3
  int v7; // r3
  idPresentable *v8; // r3
  int v9; // r3

  v4 = 0;
  for ( i = 0; ; i += 4 )
  {
    presentable = this->presentable;
    v7 = presentable != nullptr ? (int)presentable->GetVehicleInterface(this: presentable) : 0;
    if ( v4 >= *(_DWORD *)(v7 + 18748) )
      break;
    v8 = this->presentable;
    if ( v8 != nullptr )
      v9 = (int)v8->GetVehicleInterface(this: v8);
    else
      v9 = 0;
    if ( *(const idDeclInventory **)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v9 + 18744) + i) + 40) + 44) + 12) == ammoDecl )
      return 1;
    ++v4;
  }
  return 0;
}


// ========================================================================
// ?GetDifficultyRating@idVehicle@@QAAHXZ
// EA  : 0x82D219F8
// RVA : 0x00D219F8
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

int __fastcall idVehicle::GetDifficultyRating(idVehicle *this)
{
  vehicleClass_t vehicleClass; // r11
  idPresentable *presentable; // r3
  __int32 v4; // r28
  idPresentableVehicle *v5; // r3
  idVehicleAI *Driver; // r3
  __int64 v7; // r10
  idVehicleAI *v8; // r3
  int vehicleRating; // r11
  int result; // r3
  idVehicleKey *playerKey; // r30
  int num; // r3
  unsigned int v13; // r29
  int v14; // r11
  int v15; // ctr
  int v16; // r10
  unsigned int v17; // r4
  const idDeclVehicleUpgrade **list; // r31
  int v19; // ctr
  int v20; // r6
  idList<idDeclVehicleUpgrade const *,5> *v21; // r7
  int v22; // r11

  vehicleClass = this->vehicleClass;
  presentable = this->presentable;
  v4 = vehicleClass - 1;
  if ( presentable != nullptr && (v5 = presentable->GetVehicleInterface(this: presentable)) != nullptr )
  {
    Driver = (idVehicleAI *)idPresentableVehicle::GetDriver(this: v5);
    if ( Driver != nullptr )
      Driver = (idVehicleAI *)Driver->bestPickup.spawnId.value;
  }
  else
  {
    Driver = nullptr;
  }
  v8 = idVehicleAI::CastTo(c: Driver);
  if ( v8 != nullptr )
  {
    vehicleRating = v8->setup.vehicleRating;
    if ( vehicleRating <= -1 )
    {
      result = idVehicleAI::GetDifficultyRating(this: v8);
      this->lastAiDifficultyRating = result;
    }
    else
    {
      this->lastAiDifficultyRating = vehicleRating;
      return v8->setup.vehicleRating;
    }
  }
  else
  {
    result = this->lastAiDifficultyRating;
    if ( result <= -1 )
    {
      playerKey = this->playerKey;
      if ( playerKey != nullptr )
      {
        num = playerKey->validUpgrades.num;
        v13 = 0;
        if ( num > 0 )
        {
          HIDWORD(v7) = playerKey->validUpgrades.list;
          v14 = 0;
          v15 = playerKey->validUpgrades.num;
          LODWORD(v7) = HIDWORD(v7);
          do
          {
            v16 = *(_DWORD *)(v7 + 4);
            if ( v16 != 1 )
              v13 += v16;
            v14 += 16;
            LODWORD(v7) = v14 + HIDWORD(v7);
            --v15;
          }
          while ( v15 != 0 );
        }
        v17 = 0;
        if ( playerKey->equippedUpgrades.num > 0 )
        {
          list = playerKey->equippedUpgrades.list;
          v19 = playerKey->equippedUpgrades.num;
          do
          {
            v20 = 0;
            if ( num > 0 )
            {
              v21 = playerKey->validUpgrades.list;
              do
              {
                HIDWORD(v7) = v21->num;
                if ( HIDWORD(v7) != 1 )
                {
                  LODWORD(v7) = 0;
                  if ( SHIDWORD(v7) > 0 )
                  {
                    v22 = 0;
                    while ( v21->list[v22] != *list )
                    {
                      LODWORD(v7) = v7 + 1;
                      ++v22;
                      if ( (int)v7 >= SHIDWORD(v7) )
                        goto LABEL_28;
                    }
                    v17 += v7 + 1;
                    if ( (int)v7 < SHIDWORD(v7) )
                      break;
                  }
                }
LABEL_28:
                ++v20;
                ++v21;
              }
              while ( v20 < num );
            }
            ++list;
            --v19;
          }
          while ( v19 != 0 );
        }
        LODWORD(v7) = v13;
        if ( (float)((float)__SPAIR64__(v13, v17) / (float)v7) >= 0.60000002 )
          ++v4;
      }
      return v4;
    }
  }
  return result;
}


// ========================================================================
// ?Teleport@idVehicle@@UAAXABVidVec3@@ABVidAngles@@@Z
// EA  : 0x82D21BC0
// RVA : 0x00D21BC0
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __fastcall idVehicle::Teleport(idVehicle *this, const idVec3 *origin, idMat3 *angles)
{
  idPresentable *presentable; // r3
  int v5; // r3
  int v6; // r30
  int i; // r31
  idVehicleOccupant *OccupantVisual; // r3
  idVehicleOccupant *v9; // r3

  idEntity::Teleport(this, origin, angles);
  presentable = this->presentable;
  if ( presentable != nullptr )
    v5 = (int)presentable->GetVehicleInterface(this: presentable);
  else
    v5 = 0;
  v6 = *(_DWORD *)(v5 + 16476);
  for ( i = 0; i < v6; ++i )
  {
    OccupantVisual = idVehicle::GetOccupantVisual(this, index: i);
    v9 = idVehicleOccupant::CastTo(c: OccupantVisual);
    if ( v9 != nullptr )
      v9->WasTeleported(this: v9);
  }
}


// ========================================================================
// ?RestoreDetachableItems@idVehicle@@QAAXXZ
// EA  : 0x82D21C48
// RVA : 0x00D21C48
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __fastcall idVehicle::RestoreDetachableItems(idVehicle *this)
{
  int v2; // r23
  int v3; // r24
  const idDeclInventory *inventoryDecl; // r30
  idJobManager *v5; // r3
  idJob *JobByDecl; // r3
  idJob *v7; // r30
  const idDeclJob *decl; // r26
  int v9; // r25
  int v10; // r27
  const idDeclJob *v11; // r30
  idJobManager *v12; // r3
  idInventoryItem *v13; // r28
  idPresentable *presentable; // r29
  int num; // r30
  idInventoryCollection *v16; // r3

  v2 = 0;
  if ( this->startingInventory.num > 0 )
  {
    v3 = 0;
    do
    {
      inventoryDecl = this->startingInventory.list[v3].inventoryDecl;
      if ( inventoryDecl != nullptr )
      {
        v5 = (idJobManager *)this->GetInventory_2(this);
        JobByDecl = idJobManager::FindJobByDecl(this: v5, jobDecl: (const idDeclJob *)inventoryDecl);
        v7 = JobByDecl;
        if ( JobByDecl != nullptr
          && (unsigned __int8)idDecl::IsType<idDeclVehicleArmorKit>(this: &JobByDecl->decl->idDeclTypeInfo) != 0 )
        {
          decl = v7->decl;
          v9 = 0;
          if ( decl->jobAutoTransitionInfo.acceptSpawnInfo.spawnSpot.len > 0 )
          {
            v10 = 0;
            do
            {
              v11 = *(const idDeclJob **)(v10 + *(_DWORD *)&decl->jobNoteInfo.relevantMapNotes.granularity);
              v12 = (idJobManager *)this->GetInventory_2(this);
              v13 = (idInventoryItem *)idJobManager::FindJobByDecl(this: v12, jobDecl: v11);
              if ( v13 != nullptr )
              {
                presentable = this->presentable;
                if ( presentable == nullptr )
                {
                  idEntity::InitPresentableInternal(this);
                  presentable = this->presentable;
                }
                num = v11->jobLayerInfo.completeLayers.num;
                v16 = this->GetInventory_2(this);
                idInventoryCollection::SetItemCount(
                  this: v16,
                  owner: presentable,
                  item: v13,
                  count: num,
                  forceCount: true);
              }
              else
              {
                idVehicle::GiveItem(this, decl: (const idDeclVehicleWeapon *)v11, count: 1, forceCount: false);
              }
              ++v9;
              v10 += 4;
            }
            while ( v9 < decl->jobAutoTransitionInfo.acceptSpawnInfo.spawnSpot.len );
          }
        }
      }
      ++v2;
      ++v3;
    }
    while ( v2 < this->startingInventory.num );
  }
}


// ========================================================================
// ?ThrowAttachedItem@idVehicle@@UAAPAVidEntity@@PAVidInventoryItem@@@Z
// EA  : 0x82D21D90
// RVA : 0x00D21D90
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

idProp_Moveable *__fastcall idVehicle::ThrowAttachedItem(idVehicle *this, idInventoryItem *item)
{
  idPresentable *presentable; // r31
  int v5; // r30
  idInventoryCollection *v6; // r3
  const idDeclInventory *decl; // r10
  idProp_Moveable *v9; // r3
  idProp_Moveable *v10; // r31
  const idDeclInventory *v11; // r30
  idPresentable *v12; // r11
  idDeclSkins *skinPreload; // r28
  char *data; // r29
  idPresentable *v15; // r30
  idPresentable *v16; // r11
  idPhysics *Physics; // r3
  idPhysics *v18; // r3
  idPresentable *v19; // r11
  idPhysics *v20; // r30
  idPhysics *v21; // r29
  float *v22; // r30
  float *v23; // r3
  double v24; // fp7
  double v25; // fp6
  idPhysics *v26; // r25
  idPhysics *v27; // r3
  double x; // fp30
  double y; // fp29
  double z; // fp28
  idPhysics *v31; // r23
  __int64 v32; // r9
  double valueFloat; // fp5
  unsigned int v34; // r7
  idPhysics_vtbl *v35; // r10
  double v36; // fp27
  double v37; // fp26
  double v38; // fp25
  float *v39; // r3
  double v40; // fp10
  double v41; // fp8
  idPhysics *v42; // r25
  idPhysics *v43; // r24
  __int64 v44; // r9
  unsigned int v45; // r7
  double v46; // fp6
  idPhysics_vtbl *v47; // r10
  double v48; // fp31
  double v49; // fp30
  double v50; // fp29
  float *v51; // r3
  double v52; // fp11
  double v53; // fp9
  idProp_Moveable *v54; // r3
  __int64 v55; // r10
  unsigned int v56; // r4
  idPresentable *v57; // r30
  int v58; // r29
  idInventoryCollection *v59; // r3
  __int64 v60; // [sp+8h] [-148h]
  __int64 v61; // [sp+10h] [-140h]
  __int64 v62; // [sp+18h] [-138h]
  __int64 v63; // [sp+20h] [-130h]
  __int64 v64; // [sp+28h] [-128h]
  __int64 v65; // [sp+30h] [-120h]
  __int64 v66; // [sp+38h] [-118h]
  __int64 v67; // [sp+40h] [-110h]
  __int64 v68; // [sp+48h] [-108h]
  idVec3 v69; // [sp+60h] [-F0h] BYREF
  float v70[4]; // [sp+70h] [-E0h] BYREF
  float v71[4]; // [sp+80h] [-D0h] BYREF
  _BYTE v72[16]; // [sp+90h] [-C0h] BYREF
  idMat3 v73; // [sp+A0h] [-B0h] BYREF

  if ( vehicle_throwAttached_disable.valueInteger != 0 )
  {
    presentable = this->presentable;
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      presentable = this->presentable;
    }
    v5 = item->GetCount(this: item);
    v6 = this->GetInventory_2(this);
    idInventoryCollection::DeleteInventoryItem(this: v6, owner: presentable, item, count: v5);
    return nullptr;
  }
  idVehicle::GetDetachableWorldTransform(this, declInventory: item->decl, worldOrigin: &v69, worldAxis: &v73);
  decl = item->decl;
  if ( decl->thirdPersonStatic != nullptr )
  {
    v9 = idVehicle::SpawnArmorProp(
           this,
           name: (const char *)LODWORD(v69.x),
           axis: __SPAIR64__(LODWORD(v69.y), LODWORD(v73.mat[0].x)),
           a4: __SPAIR64__(LODWORD(v73.mat[0].z), LODWORD(v73.mat[1].y)),
           a5: *(__int64 *)&v73.mat[2].x,
           a6: v60,
           a7: v61,
           a8: v62,
           a9: v63,
           a10: v64,
           a11: v65,
           a12: v66,
           a13: v67,
           a14: v68);
    v10 = v9;
    if ( v9 == nullptr )
      return nullptr;
    v11 = item->decl;
    if ( v11->customMaterial != nullptr )
    {
      v12 = v9->presentable;
      if ( v12 == nullptr )
      {
        idEntity::InitPresentableInternal(this: v9);
        v12 = v10->presentable;
      }
      v12->model->g.customMaterial = v11->customMaterial;
    }
    if ( this->normalSkin.len != 0 )
    {
      skinPreload = item->skinPreload;
      if ( skinPreload != nullptr )
      {
        data = this->normalSkin.data;
        if ( v10->presentable == nullptr )
          idEntity::InitPresentableInternal(this: v10);
        v15 = v10->presentable;
        v15->model->g.customSkin = idDeclSkins::IndexForSkin(this: skinPreload, name: data);
      }
    }
    v16 = v10->presentable;
    if ( v16 == nullptr )
    {
      idEntity::InitPresentableInternal(this: v10);
      v16 = v10->presentable;
    }
    v16->model->g.castDimShadows = DIMSHADOW_OFF;
    Physics = idEntity::GetPhysics(this: v10);
    Physics->SetContents(this: Physics, a2: 0, a3: -1);
    v18 = idEntity::GetPhysics(this: v10);
    v18->SetClipMask(this: v18, a2: 1, a3: -1);
    v19 = v10->presentable;
    if ( v19 == nullptr )
    {
      idEntity::InitPresentableInternal(this: v10);
      v19 = v10->presentable;
    }
    v19->clipModelInfo.type = CLIPMODEL_NONE;
    v20 = idEntity::GetPhysics(this);
    v21 = idEntity::GetPhysics(this: v10);
    v22 = (float *)v20->GetOrigin(this: v20, a2: 0);
    v23 = (float *)v21->GetOrigin(this: v21, a2: 0);
    v24 = (float)(v23[1] - v22[1]);
    v25 = (float)(v23[2] - v22[2]);
    v69.x = *v23 - *v22;
    v69.y = v24;
    v69.z = v25;
    idVec3::NormalizeFast(this: &v69);
    v26 = idEntity::GetPhysics(this);
    v27 = idEntity::GetPhysics(this: v10);
    x = v69.x;
    y = v69.y;
    z = v69.z;
    v31 = v27;
    HIDWORD(v32) = clientGame->random.seed;
    valueFloat = vehicle_linearDebrisKnob.valueFloat;
    v34 = 1664525 * clientGame->random.seed;
    clientGame->random.seed = v34 + 1013904223;
    v35 = v26->__vftable;
    LODWORD(v32) = ((v34 + 1013904223) >> 10) & 0x7FFF;
    *(_QWORD *)&v69.x = v32;
    v36 = (float)((float)((float)((float)((float)v32 * (float)0.000030518509) * (float)valueFloat)
                        + (float)(vehicle_linearDebrisKnob.valueFloat * (float)0.5))
                * (float)x);
    v37 = (float)((float)y
                * (float)((float)((float)((float)v32 * (float)0.000030518509) * (float)valueFloat)
                        + (float)(vehicle_linearDebrisKnob.valueFloat * (float)0.5)));
    v38 = (float)((float)z
                * (float)((float)((float)((float)v32 * (float)0.000030518509) * (float)valueFloat)
                        + (float)(vehicle_linearDebrisKnob.valueFloat * (float)0.5)));
    v39 = (float *)v35->GetLinearVelocity(this: (idPhysics *)v72, result: (idVec3 *)v26, a3: 0);
    v40 = (float)(v39[2] + (float)v38);
    v41 = (float)(v39[1] + (float)v37);
    v70[0] = *v39 + (float)v36;
    v70[2] = v40;
    v70[1] = v41;
    v31->SetLinearVelocity(this: v31, a2: (const idVec3 *)v70, a3: 0);
    v42 = idEntity::GetPhysics(this);
    v43 = idEntity::GetPhysics(this: v10);
    HIDWORD(v44) = clientGame->random.seed;
    v45 = 1664525 * clientGame->random.seed;
    v46 = vehicle_angularDebrisKnob.valueFloat;
    clientGame->random.seed = v45 + 1013904223;
    v47 = v42->__vftable;
    LODWORD(v44) = ((v45 + 1013904223) >> 10) & 0x7FFF;
    *(_QWORD *)&v69.x = v44;
    v48 = (float)((float)((float)((float)((float)v44 * (float)0.000030518509) * (float)v46)
                        + (float)(vehicle_angularDebrisKnob.valueFloat * (float)0.5))
                * (float)x);
    v49 = (float)((float)y
                * (float)((float)((float)((float)v44 * (float)0.000030518509) * (float)v46)
                        + (float)(vehicle_angularDebrisKnob.valueFloat * (float)0.5)));
    v50 = (float)((float)z
                * (float)((float)((float)((float)v44 * (float)0.000030518509) * (float)v46)
                        + (float)(vehicle_angularDebrisKnob.valueFloat * (float)0.5)));
    v51 = (float *)v47->GetAngularVelocity(this: (idPhysics *)v72, result: (idVec3 *)v42, a3: 0);
    v52 = (float)(v51[2] + (float)v50);
    v53 = (float)(v51[1] + (float)v49);
    v71[0] = *v51 + (float)v48;
    v71[2] = v52;
    v71[1] = v53;
    v43->SetAngularVelocity(this: v43, a2: (const idVec3 *)v71, a3: 0);
    v54 = idProp_Moveable::CastTo(c: v10);
    if ( v54 != nullptr )
    {
      HIDWORD(v55) = &off_822B0000;
      v54->removeCondition = REMOVE_CONDITION_DORMANT;
      v54->fadeTimeDelay = 0.0;
      v56 = 1664525 * clientGame->random.seed + 1013904223;
      clientGame->random.seed = v56;
      LODWORD(v55) = (v56 >> 10) & 0x7FFF;
      *(_QWORD *)&v69.x = v55;
      v54->fadeTime = (float)((float)v55 * (float)0.000091555528) + (float)1.0;
    }
    v57 = this->presentable;
    if ( v57 == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      v57 = this->presentable;
    }
    v58 = item->GetCount(this: item);
    v59 = this->GetInventory_2(this);
    idInventoryCollection::DeleteInventoryItem(this: v59, owner: v57, item, count: v58);
    return v10;
  }
  else
  {
    idLib::Warning(fmt: "Item %s thirdPersonStatic model is NULL - can't throw attached item.", decl->name.str);
    return nullptr;
  }
}


// ========================================================================
// ?IncreaseHealth@idVehicle@@UAA_NM@Z
// EA  : 0x82D222C8
// RVA : 0x00D222C8
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
BOOL __fastcall idVehicle::IncreaseHealth(idVehicle *this, double h)
{
  BOOL v4; // r9
  idVehicle_vtbl *v5; // r11
  double v6; // fp31
  double v7; // fp1
  double v8; // fp31
  double v10; // fp30
  double v11; // fp1
  idVehicle_vtbl *v12; // r31
  double v13; // fp30
  double v14; // fp1
  double v15; // fp31
  idInventoryCollection *v16; // r3
  idVehicleKey *playerKey; // r27
  idJobManager *v18; // r22
  int num; // r11
  int v20; // r24
  int v21; // r25
  int v22; // r28
  const idDeclJob *decl; // r30
  idJob *JobByDecl; // r3
  idInventoryItem *v25; // r29
  int v26; // r31
  __int64 v27; // r9 OVERLAPPED
  idLobbyBase *v28; // r3
  __int64 v29; // r11 OVERLAPPED
  double v30; // fp30
  int v31; // r31
  __int64 v32; // r11
  double v33; // fp0
  idPresentable *presentable; // r4
  int v35; // r21
  int v36; // r23
  const idDeclInventory *inventoryDecl; // r4
  idJob *v38; // r3
  idJob *v39; // r31
  __int64 v40; // r10
  const idDeclJob *v41; // r27
  int v42; // r24
  int len; // r11
  int v44; // r25
  int v45; // r28
  const idDeclJob *v46; // r30
  idJob *v47; // r3
  idInventoryItem *v48; // r29
  int v49; // r31
  __int64 v50; // r9 OVERLAPPED
  idLobbyBase *v51; // r3
  __int64 v52; // r11 OVERLAPPED
  double v53; // fp30
  int v54; // r31
  __int64 v55; // r11
  double v56; // fp0
  idPresentable *v57; // r4
  double maxArmoredHealth; // fp31

  v4 = common->IsMultiplayer(this: common);
  v5 = this->__vftable;
  if ( v4 )
  {
    v6 = (float)(v5->GetHealth(this) + (float)h);
    this->GetMaxHealth(this);
    if ( v6 >= 0.0 )
    {
      if ( v6 <= v7 )
        v7 = v6;
    }
    else
    {
      v7 = 0.0;
    }
    this->SetHealth(this, a2: v7);
    v8 = ((double (__fastcall *)(idVehicle *))this->GetHealth)(a1: this);
    return v8 == ((double (__fastcall *)(idVehicle *))this->GetMaxHealth)(a1: this);
  }
  else
  {
    v10 = ((double (__fastcall *)(idVehicle *))v5->GetMaxHealth)(a1: this);
    v11 = ((double (__fastcall *)(idVehicle *))this->GetHealth)(a1: this);
    v12 = this->__vftable;
    v13 = (float)((float)((float)v10 - (float)v11) - (float)h);
    if ( v13 < 0.0 )
    {
      v12->GetMaxHealth(this);
      ((void (__fastcall *)(idVehicle *))v12->SetHealth)(a1: this);
      v15 = -v13;
      v16 = this->GetInventory_2(this);
      playerKey = this->playerKey;
      v18 = (idJobManager *)v16;
      if ( playerKey != nullptr )
      {
        idVehicleKey::DetermineFullUpgradeList(this: this->playerKey);
        num = playerKey->upgradedArmorList.num;
        v20 = 0;
        if ( num > 0 )
          v20 = (int)(float)((float)(this->maxArmoredHealth / (float)__SPAIR64__(&idEventDef::eventDefList[3154], num))
                           * vehicle_armorHealthPercentage.valueFloat);
        v21 = 0;
        if ( num > 0 )
        {
          v22 = 0;
          do
          {
            decl = (const idDeclJob *)playerKey->upgradedArmorList.list[v22].decl;
            JobByDecl = idJobManager::FindJobByDecl(this: v18, jobDecl: decl);
            v25 = (idInventoryItem *)JobByDecl;
            if ( JobByDecl != nullptr )
            {
              v26 = ((int (__fastcall *)(idJob *))JobByDecl->__vftable[2].dtr_idClass)(a1: JobByDecl);
            }
            else
            {
              v25 = idVehicle::GiveItem(this, (const idDeclVehicleWeapon *)decl, count: 1, forceCount: false);
              v26 = 0;
            }
            if ( common->IsMultiplayer(this: common)
              && (v28 = session->GetActingGameStateLobbyBase(this: session), v28->GetMatchParms(this: v28)->gameType == 2) )
            {
              HIDWORD(v29) = v20 - v26;
              LODWORD(v29) = v26;
              v30 = (float)*(__int64 *)((char *)&v27 - 4);
              if ( v30 <= v15 )
                v31 = (int)(float)((float)v29 + (float)*(__int64 *)((char *)&v27 - 4));
              else
                v31 = (int)(float)((float)v29 + (float)v15);
            }
            else
            {
              HIDWORD(v32) = decl->jobLayerInfo.completeLayers.num - v26;
              LODWORD(v32) = v26;
              LODWORD(v27) = HIDWORD(v32);
              v30 = (float)v27;
              if ( v30 <= v15 )
                v33 = (float)((float)v32 + (float)v27);
              else
                v33 = (float)((float)v32 + (float)v15);
              v31 = (int)v33;
            }
            presentable = this->presentable;
            if ( presentable == nullptr )
            {
              idEntity::InitPresentableInternal(this);
              presentable = this->presentable;
            }
            idInventoryCollection::SetItemCount(
              this: (idInventoryCollection *)v18,
              owner: presentable,
              item: v25,
              count: v31,
              forceCount: true);
            v15 = (float)((float)v15 - (float)v30);
            if ( v15 <= 0.0 )
              break;
            ++v21;
            ++v22;
          }
          while ( v21 < playerKey->upgradedArmorList.num );
        }
        idVehicleKey::UpdateArmorInfo(this: playerKey, initFromUpgrades: false);
      }
      else
      {
        v35 = 0;
        if ( this->startingInventory.num > 0 )
        {
          v36 = 0;
          while ( 1 )
          {
            inventoryDecl = this->startingInventory.list[v36].inventoryDecl;
            if ( inventoryDecl != nullptr )
            {
              v38 = idJobManager::FindJobByDecl(this: v18, jobDecl: (const idDeclJob *)inventoryDecl);
              v39 = v38;
              if ( v38 != nullptr
                && (unsigned __int8)idDecl::IsType<idDeclVehicleArmorKit>(this: &v38->decl->idDeclTypeInfo) != 0 )
              {
                v41 = v39->decl;
                v42 = 0;
                len = v41->jobAutoTransitionInfo.acceptSpawnInfo.spawnSpot.len;
                if ( len > 0 )
                {
                  LODWORD(v40) = v41->jobAutoTransitionInfo.acceptSpawnInfo.spawnSpot.len;
                  v42 = (int)(float)((float)(this->maxArmoredHealth / (float)v40)
                                   * vehicle_armorHealthPercentage.valueFloat);
                }
                v44 = 0;
                if ( len > 0 )
                  break;
              }
            }
LABEL_56:
            ++v35;
            ++v36;
            if ( v35 >= this->startingInventory.num )
              goto LABEL_57;
          }
          v45 = 0;
          while ( 1 )
          {
            v46 = *(const idDeclJob **)(v45 + *(_DWORD *)&v41->jobNoteInfo.relevantMapNotes.granularity);
            v47 = idJobManager::FindJobByDecl(this: v18, jobDecl: v46);
            v48 = (idInventoryItem *)v47;
            if ( v47 != nullptr )
            {
              v49 = ((int (__fastcall *)(idJob *))v47->__vftable[2].dtr_idClass)(a1: v47);
            }
            else
            {
              v48 = idVehicle::GiveItem(this, decl: (const idDeclVehicleWeapon *)v46, count: 1, forceCount: false);
              v49 = 0;
            }
            if ( common->IsMultiplayer(this: common)
              && (v51 = session->GetActingGameStateLobbyBase(this: session), v51->GetMatchParms(this: v51)->gameType == 2) )
            {
              HIDWORD(v52) = v42 - v49;
              LODWORD(v52) = v49;
              v53 = (float)*(__int64 *)((char *)&v50 - 4);
              if ( v53 <= v15 )
                v54 = (int)(float)((float)v52 + (float)*(__int64 *)((char *)&v50 - 4));
              else
                v54 = (int)(float)((float)v52 + (float)v15);
            }
            else
            {
              HIDWORD(v55) = v46->jobLayerInfo.completeLayers.num - v49;
              LODWORD(v55) = v49;
              LODWORD(v50) = HIDWORD(v55);
              v53 = (float)v50;
              if ( v53 <= v15 )
                v56 = (float)((float)v55 + (float)v50);
              else
                v56 = (float)((float)v55 + (float)v15);
              v54 = (int)v56;
            }
            v57 = this->presentable;
            if ( v57 == nullptr )
            {
              idEntity::InitPresentableInternal(this);
              v57 = this->presentable;
            }
            idInventoryCollection::SetItemCount(
              this: (idInventoryCollection *)v18,
              owner: v57,
              item: v48,
              count: v54,
              forceCount: true);
            v15 = (float)((float)v15 - (float)v53);
            if ( v15 <= 0.0 )
              break;
            ++v44;
            v45 += 4;
            if ( v44 >= v41->jobAutoTransitionInfo.acceptSpawnInfo.spawnSpot.len )
              goto LABEL_56;
          }
        }
      }
    }
    else
    {
      v14 = ((double (__fastcall *)(idVehicle *))v12->GetHealth)(a1: this);
      v12->SetHealth(this, a2: (float)((float)v14 + (float)h));
    }
LABEL_57:
    maxArmoredHealth = this->maxArmoredHealth;
    return idVehicle::GetArmoredHealth(this) == maxArmoredHealth;
  }
}


// ========================================================================
// ?Event_GetLastDamage_Inflictor@idVehicle@@QAA?AVeventEntity@@XZ
// EA  : 0x82D22940
// RVA : 0x00D22940
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

idVehicle *__fastcall idVehicle::Event_GetLastDamage_Inflictor(idVehicle *this, eventEntity *result)
{
  idEntity *value; // r10
  idEntity *v4; // r3
  idEntity *v5; // r4

  value = result[3934].value;
  if ( gameLocal->spawnIds.ptr[(unsigned __int16)value & 0x1FFF] == (int)value >> 13
    && (v4 = gameLocal->entities.ptr[(unsigned __int16)value & 0x1FFF]) != nullptr )
  {
    v5 = idEntity::CastTo(c: v4);
  }
  else
  {
    v5 = nullptr;
  }
  eventEntity::eventEntity((eventEntity *)this, e: v5);
  return this;
}


// ========================================================================
// ?Event_GetLastDamage_Attacker@idVehicle@@QAA?AVeventEntity@@XZ
// EA  : 0x82D229C0
// RVA : 0x00D229C0
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

idVehicle *__fastcall idVehicle::Event_GetLastDamage_Attacker(idVehicle *this, eventEntity *result)
{
  idEntity *value; // r10
  idEntity *v4; // r3
  idEntity *v5; // r4

  value = result[3935].value;
  if ( gameLocal->spawnIds.ptr[(unsigned __int16)value & 0x1FFF] == (int)value >> 13
    && (v4 = gameLocal->entities.ptr[(unsigned __int16)value & 0x1FFF]) != nullptr )
  {
    v5 = idEntity::CastTo(c: v4);
  }
  else
  {
    v5 = nullptr;
  }
  eventEntity::eventEntity((eventEntity *)this, e: v5);
  return this;
}


// ========================================================================
// ?Event_Damage@idVehicle@@QAA?AVeventVoid@@PAVidEntity@@0PBDMABVidVec3@@@Z
// EA  : 0x82D22A40
// RVA : 0x00D22A40
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

idVehicle *__fastcall idVehicle::Event_Damage(
        idVehicle *this,
        eventVoid *result,
        idEntity *inflictor,
        idEntity *attacker,
        const char *damageDef,
        double damageScale,
        const idVec3 *dir)
{
  const idDecl *v12; // r6

  if ( damageDef != nullptr )
  {
    v12 = idDeclInfo::FindWithInheritance(this: &idDeclDamage::resourceList, name: damageDef, makeDefault: true);
    if ( v12 != nullptr )
      (*(void (__fastcall **)(eventVoid *, idEntity *, idEntity *, const idDecl *, double))(*(_DWORD *)result + 312))(
        a1: result,
        a2: inflictor,
        a3: attacker,
        a4: v12,
        a5: damageScale);
  }
  return this;
}


// ========================================================================
// ?Event_GetLastCollision_Entity@idVehicle@@QAA?AVeventEntity@@XZ
// EA  : 0x82D22AC8
// RVA : 0x00D22AC8
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

idVehicle *__fastcall idVehicle::Event_GetLastCollision_Entity(idVehicle *this, eventEntity *result)
{
  idEntity *value; // r3
  int v4; // r3
  int v5; // r10
  idEntity *v6; // r3
  idEntity *v7; // r4

  value = result[122].value;
  if ( value != nullptr )
    v4 = ((int (__fastcall *)(idEntity *))value->GetScale)(a1: value);
  else
    v4 = 0;
  v5 = *(_DWORD *)(v4 + 20284);
  if ( gameLocal->spawnIds.ptr[v5 & 0x1FFF] == v5 >> 13 && (v6 = gameLocal->entities.ptr[v5 & 0x1FFF]) != nullptr )
    v7 = idEntity::CastTo(c: v6);
  else
    v7 = nullptr;
  eventEntity::eventEntity((eventEntity *)this, e: v7);
  return this;
}


// ========================================================================
// ?Event_RespawnInGarage@idVehicle@@QAA?AVeventVoid@@XZ
// EA  : 0x82D22B70
// RVA : 0x00D22B70
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

idVehicle *__fastcall idVehicle::Event_RespawnInGarage(idVehicle *this, const idVehicle *result)
{
  idGameLocal *v3; // r11
  int v5; // r29
  int v6; // r30
  int value; // r9
  idInfoGarageBay *v8; // r3
  idInfoGarageBay *v9; // r3
  idInfoGarageBay *v10; // r31
  idGameLocal *v11; // r11
  int v12; // r29
  int v13; // r31
  int v14; // r9
  idInfoGarageBay *v15; // r3
  idInfoGarageBay *v16; // r3
  idInfoGarageBay *v17; // r30
  idVehicle_vtbl *v19; // r30
  idAngles *v20; // r3
  idMat3 v21[2]; // [sp+50h] [-60h] BYREF

  v3 = gameLocal;
  v5 = 0;
  if ( gameLocal->infoGarageBays.num > 0 )
  {
    v6 = 0;
    do
    {
      value = v3->infoGarageBays.list[v6].spawnId.value;
      if ( v3->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
      {
        v8 = (idInfoGarageBay *)v3->entities.ptr[value & 0x1FFF];
        if ( v8 != nullptr )
        {
          v9 = idInfoGarageBay::CastTo(c: v8);
          v10 = v9;
          if ( v9 != nullptr
            && v9->vehicleClass == result->vehicleClass
            && (idInfoGarageBay::GetVehicle(this: v9) == nullptr || idInfoGarageBay::GetVehicle(this: v10) == result) )
          {
LABEL_22:
            result->Respawn(this: (idVehicle *)result);
            v19 = result->__vftable;
            v20 = idMat3::ToAngles(this: v21, result: (idAngles *)&v10->spawnOrientation);
            v19->Teleport(this: &result->idAnimatedEntity, a2: &v10->spawnPosition, a3: v20);
            return this;
          }
          v3 = gameLocal;
        }
      }
      ++v5;
      ++v6;
    }
    while ( v5 < v3->infoGarageBays.num );
  }
  idLib::Warning(fmt: "could not find specific vehicle garage bay in Event_RespawnInGarage");
  v11 = gameLocal;
  v12 = 0;
  if ( gameLocal->infoGarageBays.num > 0 )
  {
    v13 = 0;
    do
    {
      v14 = v11->infoGarageBays.list[v13].spawnId.value;
      if ( v11->spawnIds.ptr[v14 & 0x1FFF] == v14 >> 13 )
      {
        v15 = (idInfoGarageBay *)v11->entities.ptr[v14 & 0x1FFF];
        if ( v15 != nullptr )
        {
          v16 = idInfoGarageBay::CastTo(c: v15);
          v17 = v16;
          if ( v16 != nullptr
            && v16->vehicleClass == VEHICLE_CLASSNONE
            && idInfoGarageBay::GetVehicle(this: v16) == nullptr )
          {
            v10 = v17;
            goto LABEL_22;
          }
          v11 = gameLocal;
        }
      }
      ++v12;
      ++v13;
    }
    while ( v12 < v11->infoGarageBays.num );
  }
  idLib::Warning(fmt: "could not find any garage bay in Event_RespawnInGarage not respawning vehicle");
  return this;
}


// ========================================================================
// ?ClearWeaponFX@idVehicle@@QAAXXZ
// EA  : 0x82D22D50
// RVA : 0x00D22D50
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __fastcall idVehicle::ClearWeaponFX(idVehicle *this)
{
  int v2; // r31
  int i; // r30
  idPresentable *presentable; // r3
  int v5; // r3
  idPresentable *v6; // r3
  int v7; // r3

  v2 = 0;
  for ( i = 0; ; i += 4 )
  {
    presentable = this->presentable;
    v5 = presentable != nullptr ? (int)presentable->GetVehicleInterface(this: presentable) : 0;
    if ( v2 >= *(_DWORD *)(v5 + 18748) )
      break;
    v6 = this->presentable;
    if ( v6 != nullptr )
      v7 = (int)v6->GetVehicleInterface(this: v6);
    else
      v7 = 0;
    idVehicleWeapon::ClearWeaponFX(this: *(idVehicleWeapon **)(*(_DWORD *)(v7 + 18744) + i));
    ++v2;
  }
}


// ========================================================================
// ?GetVehicleCameraView@idVehicle@@SA_NAAVidVec3@@AAVidMat3@@AAMAAVidView@@@Z
// EA  : 0x82D22DE0
// RVA : 0x00D22DE0
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

int __fastcall idVehicle::GetVehicleCameraView(idVec3 *origin, idMat3 *axis, float *fov_x, idView *view)
{
  idVehicle *v8; // r31
  idVehicle *v10; // r27
  idPresentable *v11; // r3
  idPresentableVehicle *v12; // r3
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  double valueFloat; // fp31
  const idDeclVehicleProps::cameraPlacement_t *CameraPlacement; // r3
  idPresentable *presentable; // r3
  char *data; // r31
  const char *v18; // r30
  idPresentableVehicle *v19; // r3
  double v20; // fp9
  double v21; // fp7
  double x; // fp0
  double y; // fp13
  double z; // fp12
  double v25; // fp4
  double v26; // fp3
  double v27; // fp2
  double v28; // fp1
  double v29; // fp11
  double v30; // fp31
  double v31; // fp8
  double v32; // fp6
  double v33; // fp10
  double v34; // fp9
  double v35; // fp8
  double v36; // fp7
  double v37; // fp5
  double v38; // fp4
  double v39; // fp3
  double v40; // fp2
  double v41; // fp13
  double v42; // fp12
  double v43; // fp8
  double v44; // fp7
  double v45; // fp3
  idVec3 *v46; // r30
  idVec3 *v47; // r31
  idPhysics *Physics; // r3
  idClipModel *clip8x8; // r25
  const idVec3 *v50; // r3
  double v51; // fp13
  double v52; // fp12
  double v53; // fp10
  idPhysics *v54; // r3
  idClipModel *v55; // r25
  const idVec3 *v56; // r3
  double v57; // fp7
  double v58; // fp6
  idPhysics *v59; // r26
  idVec3 *v60; // r3
  double v61; // fp30
  double v62; // fp29
  double v63; // fp28
  float *v64; // r3
  double v65; // fp9
  double v66; // fp8
  double v67; // fp2
  double v68; // fp1
  idPhysics *v69; // r3
  float *v70; // r3
  double v71; // fp11
  double v72; // fp10
  double v73; // fp9
  double v74; // fp7
  double v75; // fp3
  double v76; // fp1
  double v77; // fp2
  double v78; // fp9
  double v79; // fp8
  double v80; // fp7
  double v81; // fp6
  double v82; // fp5
  double v83; // fp4
  double v84; // fp3
  double v85; // fp2
  idMat3 v86; // [sp+50h] [-190h] BYREF
  float v87; // [sp+74h] [-16Ch]
  float v88; // [sp+78h] [-168h]
  float v89; // [sp+7Ch] [-164h]
  float v90; // [sp+80h] [-160h]
  idVec3 v91; // [sp+88h] [-158h] BYREF
  idMat3 v92; // [sp+98h] [-148h] BYREF
  trace_t v93; // [sp+D0h] [-110h] BYREF
  idAngles v94[6]; // [sp+150h] [-90h] BYREF

  v8 = (idVehicle *)gameLocal->FindEntity(this: gameLocal, a2: vehicle_follow.valueString.data);
  if ( (unsigned __int8)idVehicle::IsTypeOf(c: v8) == 0 )
    return 0;
  v10 = idVehicle::CastTo(c: v8);
  if ( idStr::Cmp(s1: vehicle_cam_tag.valueString.data, s2: "actual_chase") != 0 )
  {
    v10->lastDrawTime = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: v10);
    idMat3::ToAngles(this: (idMat3 *)&v92.mat[1].y, result: (idAngles *)&TreeAnimatorFromPresentable->g.axis);
    if ( pm_vehicleFreeCam.valueInteger != 0 )
    {
      v86.mat[0].x = v10->freeAngles.pitch;
      v86.mat[0].y = v10->freeAngles.yaw;
      v86.mat[0].z = v10->freeAngles.roll;
    }
    else
    {
      v86.mat[0].y = vehicle_cam_yaw.valueFloat + v92.mat[1].z;
      valueFloat = vehicle_cam_pitch.valueFloat;
      CameraPlacement = idVehicle::GetCameraPlacement(this: v10);
      v86.mat[0].x = (float)(CameraPlacement->pitch + (float)valueFloat) + v92.mat[1].y;
      v86.mat[0].z = 0.0;
    }
    presentable = v10->presentable;
    data = vehicle_cam_tag.valueString.data;
    v18 = idPropInfo::CAMERA_PROP_NAME;
    if ( presentable != nullptr )
      v19 = presentable->GetVehicleInterface(this: presentable);
    else
      v19 = nullptr;
    if ( (unsigned __int8)idPresentableVehicle::GetTagPosition(
                            this: v19,
                            propName: v18,
                            tagName: data,
                            origin: &v91,
                            axis: (idMat3 *)&v86.mat[1].y) == 0 )
      return 0;
    idMat3::ToAngles(this: &v92, result: (idAngles *)&v86.mat[1].y);
    v20 = v89;
    v21 = v90;
    x = v91.x;
    y = v91.y;
    z = v91.z;
    v25 = v86.mat[1].y;
    v26 = v86.mat[1].z;
    v27 = v86.mat[2].x;
    v28 = v86.mat[2].y;
    v29 = v92.mat[0].x;
    v86.mat[0].x = v92.mat[0].x;
    v30 = vehicle_cam_up.valueFloat;
    v31 = (float)(v88 * vehicle_cam_up.valueFloat);
    origin->y = v91.y;
    v32 = (float)((float)v20 * (float)v30);
    origin->z = z;
    origin->x = x;
    v33 = v86.mat[2].z;
    v34 = (float)((float)v31 + (float)x);
    origin->x = (float)v31 + (float)x;
    v35 = (float)((float)v32 + (float)y);
    origin->y = (float)v32 + (float)y;
    v36 = (float)((float)((float)v21 * (float)v30) + (float)z);
    origin->z = v36;
    v37 = (float)((float)v26 * vehicle_cam_fwd.valueFloat);
    v39 = (float)((float)v27 * vehicle_cam_fwd.valueFloat);
    v40 = v92.mat[0].y;
    v41 = (float)((float)((float)v25 * vehicle_cam_fwd.valueFloat) + (float)v34);
    v38 = v87;
    origin->x = v41;
    v86.mat[0].y = v40;
    v42 = (float)((float)v35 + (float)v37);
    origin->y = (float)v35 + (float)v37;
    origin->z = (float)v36 + (float)v39;
    v43 = (float)((float)v28 * vehicle_cam_rt.valueFloat);
    v45 = (float)((float)((float)v36 + (float)v39) + (float)((float)v38 * vehicle_cam_rt.valueFloat));
    v44 = (float)((float)v33 * vehicle_cam_rt.valueFloat);
    origin->z = v45;
    origin->x = (float)v43 + (float)v41;
    origin->y = (float)v42 + (float)v44;
    if ( v29 < vc_minpitch.valueFloat )
      v86.mat[0].x = vc_minpitch.valueFloat;
    v46 = &axis->mat[1];
    v47 = &axis->mat[2];
    *axis = *idAngles::ToMat3(this: v94, result: &v86);
    Physics = idEntity::GetPhysics(this: v10);
    clip8x8 = clientGame->clip.clip8x8;
    v50 = Physics->GetOrigin(this: Physics, a2: 0);
    idClip::TraceBounds(
      this: &clientGame->clip,
      result: &v93,
      start: v50,
      end: origin,
      trm: clip8x8,
      clipMask: 1,
      passEntityNumber: 0);
    if ( v93.fraction != 1.0 )
    {
      v51 = (float)((float)1.0 - v93.fraction);
      v52 = v93.endpos.z;
      v53 = v93.endpos.y;
      origin->x = v93.endpos.x;
      origin->y = v53;
      origin->z = (float)((float)v51 * (float)32.0) + (float)v52;
      v54 = idEntity::GetPhysics(this: v10);
      v55 = clientGame->clip.clip8x8;
      v56 = v54->GetOrigin(this: v54, a2: 0);
      idClip::TraceBounds(
        this: &clientGame->clip,
        result: &v93,
        start: v56,
        end: origin,
        trm: v55,
        clipMask: 1,
        passEntityNumber: 0);
      v57 = v93.endpos.y;
      v58 = v93.endpos.z;
      origin->x = v93.endpos.x;
      origin->y = v57;
      origin->z = v58;
    }
    v59 = idEntity::GetPhysics(this: v10);
    v60 = idAngles::ToForward(this: (idAngles *)&v92.mat[2].z, result: v86.mat);
    v61 = (float)(v60->x * (float)512.0);
    v62 = (float)(v60->y * (float)512.0);
    v63 = (float)(v60->z * (float)512.0);
    v64 = (float *)v59->GetOrigin(this: v59, a2: 0);
    v65 = origin->y;
    v66 = origin->z;
    v67 = (float)(v64[1] + (float)v62);
    v68 = (float)((float)(v64[2] + (float)v63) + (float)v30);
    axis->mat[0].x = (float)(*v64 + (float)v61) - origin->x;
    axis->mat[0].y = (float)v67 - (float)v65;
    axis->mat[0].z = (float)v68 - (float)v66;
    v69 = idEntity::GetPhysics(this: v10);
    v70 = (float *)v69->GetGravityNormal(this: v69);
    v71 = *v70;
    v47->x = *v70;
    v72 = v70[1];
    axis->mat[2].y = v70[1];
    v73 = v70[2];
    axis->mat[2].z = v70[2];
    v74 = axis->mat[0].x;
    v75 = axis->mat[0].y;
    v76 = (float)(axis->mat[0].z * (float)v72);
    v77 = (float)((float)v71 * axis->mat[0].y);
    axis->mat[1].y = (float)((float)v71 * axis->mat[0].z) - (float)(axis->mat[0].x * (float)v73);
    v46->x = (float)((float)v75 * (float)v73) - (float)v76;
    axis->mat[1].z = (float)((float)v74 * (float)v72) - (float)v77;
    idMat3::OrthoNormalizeSelf(this: axis);
    v78 = v86.mat[2].y;
    v79 = v86.mat[1].z;
    v80 = v86.mat[2].x;
    axis->mat[0].x = v86.mat[1].y;
    v81 = v86.mat[2].z;
    v46->x = v78;
    axis->mat[0].y = v79;
    axis->mat[0].z = v80;
    v82 = v87;
    axis->mat[1].y = v81;
    v83 = v88;
    axis->mat[1].z = v82;
    v84 = v89;
    v47->x = v83;
    v85 = v90;
    axis->mat[2].y = v84;
    axis->mat[2].z = v85;
    return 1;
  }
  else
  {
    v11 = v10->presentable;
    if ( v11 != nullptr )
      v12 = v11->GetVehicleInterface(this: v11);
    else
      v12 = nullptr;
    idPresentableVehicle::GetDriverView(this: v12, origin, axis, fov_x, view);
    return 1;
  }
}


// ========================================================================
// ?CycleFollow@idVehicle@@SAXXZ
// EA  : 0x82D23378
// RVA : 0x00D23378
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

static void __fastcall idVehicle::CycleFollow()
{
  const char *v0; // r10
  char *data; // r11
  int v2; // r9
  int v3; // r9
  bool v4; // zf
  char *v5; // r11
  const char *v6; // r10
  int v7; // r9
  int v8; // r9
  idVehicle *v9; // r31
  idVehicle *v10; // r3
  idLinkList<idVehicle> *next; // r11
  idVehicle *owner; // r11
  idLinkList<idVehicle> *v13; // r11
  idVehicle *v14; // r31
  idLinkList<idVehicle> *prev; // r11
  idLinkList<idVehicle> *v16; // r11
  double valueFloat; // fp13
  double v18; // fp12
  unsigned int v19; // r11
  int v20; // r4
  bool v21; // r4
  double v22; // fp12
  double v23; // fp13
  bool v24; // cr32
  int v25; // ctr
  float *v26; // r11
  double v27; // fp12
  double v28; // fp13
  float *p_rtOfs; // r31
  int v30; // r7
  idLinkList<idVehicle> *v31; // r11

  v0 = "any";
  data = vehicle_follow.valueString.data;
  do
  {
    v2 = (unsigned __int8)*data;
    v4 = v2 == 0;
    v3 = v2 - *(unsigned __int8 *)v0;
    if ( v4 )
      break;
    ++data;
    ++v0;
  }
  while ( v3 == 0 );
  if ( v3 == 0 )
    goto LABEL_50;
  v5 = vehicle_follow.valueString.data;
  v6 = "1";
  do
  {
    v7 = (unsigned __int8)*v5;
    v4 = v7 == 0;
    v8 = v7 - *(unsigned __int8 *)v6;
    if ( v4 )
      break;
    ++v5;
    ++v6;
  }
  while ( v8 == 0 );
  if ( v8 != 0 )
  {
    if ( vehicle_cam_next.valueInteger != 0 )
    {
      v9 = (idVehicle *)((int (__fastcall *)(idGameLocal *))gameLocal->FindEntity)(a1: gameLocal);
      if ( (unsigned __int8)idVehicle::IsTypeOf(c: v9) == 0 )
      {
LABEL_11:
        idCVar::SetString(this: &vehicle_follow, newValue: "any", force: true);
        return;
      }
      idCVar::SetBool(this: &vehicle_cam_next, newValue: false, force: true);
      v10 = idVehicle::CastTo(c: v9);
      next = v10->controlNode.next;
      if ( next == nullptr || next == v10->controlNode.head )
        owner = nullptr;
      else
        owner = next->owner;
      if ( owner != v10 )
      {
        if ( owner == nullptr )
        {
          v13 = gameLocal->vehicleEntities.next;
          if ( v13 == nullptr || v13 == gameLocal->vehicleEntities.head || (owner = v13->owner) == nullptr )
          {
LABEL_21:
            owner = v10;
            goto LABEL_53;
          }
        }
        goto LABEL_54;
      }
      goto LABEL_53;
    }
    if ( vehicle_cam_prev.valueInteger != 0 )
    {
      v14 = (idVehicle *)((int (__fastcall *)(idGameLocal *))gameLocal->FindEntity)(a1: gameLocal);
      if ( (unsigned __int8)idVehicle::IsTypeOf(c: v14) == 0 )
        goto LABEL_11;
      idCVar::SetBool(this: &vehicle_cam_prev, newValue: false, force: true);
      v10 = idVehicle::CastTo(c: v14);
      prev = v10->controlNode.prev;
      if ( prev == nullptr || prev == v10->controlNode.head )
        owner = nullptr;
      else
        owner = prev->owner;
      if ( owner != v10 )
      {
        if ( owner != nullptr )
          goto LABEL_54;
        v16 = gameLocal->vehicleEntities.prev;
        if ( v16 == nullptr || v16 == gameLocal->vehicleEntities.head )
          goto LABEL_21;
        owner = v16->owner;
        if ( owner != nullptr )
        {
LABEL_54:
          idCVar::SetString(this: &vehicle_follow, newValue: owner->name.data, force: true);
          return;
        }
        owner = v10;
      }
LABEL_53:
      if ( owner == nullptr )
        return;
      goto LABEL_54;
    }
    if ( vehicle_cam_next_tag.valueInteger != 0 )
    {
      idCVar::SetBool(this: &vehicle_cam_next_tag, newValue: false, force: true);
      valueFloat = vehicle_cam_rt.valueFloat;
      v18 = vehicle_cam_up.valueFloat;
      v20 = currentVehicleCameraTag++;
      v19 = currentVehicleCameraTag;
      vehicle_cam_info[v20].fwdOfs = vehicle_cam_fwd.valueFloat;
      vehicle_cam_info[v20].rtOfs = valueFloat;
      vehicle_cam_info[v20].upOfs = v18;
      if ( v19 >= 0x12 )
      {
        v19 = 0;
        currentVehicleCameraTag = 0;
      }
LABEL_37:
      idCVar::SetFloat(this: &vehicle_cam_fwd, newValue: vehicle_cam_info[v19].fwdOfs, force: v20 * 20);
      idCVar::SetFloat(
        this: &vehicle_cam_rt,
        newValue: vehicle_cam_info[currentVehicleCameraTag].rtOfs,
        force: 5 * currentVehicleCameraTag);
      idCVar::SetFloat(this: &vehicle_cam_up, newValue: vehicle_cam_info[currentVehicleCameraTag].upOfs, force: v21);
      idCVar::SetString(
        this: &vehicle_cam_tag,
        newValue: vehicle_cam_info[currentVehicleCameraTag].tagName,
        force: true);
      return;
    }
    if ( vehicle_cam_prev_tag.valueInteger != 0 )
    {
      idCVar::SetBool(this: &vehicle_cam_prev_tag, newValue: false, force: true);
      v22 = vehicle_cam_up.valueFloat;
      v23 = vehicle_cam_rt.valueFloat;
      v19 = currentVehicleCameraTag - 1;
      v24 = currentVehicleCameraTag - 1 < 0;
      v20 = currentVehicleCameraTag--;
      vehicle_cam_info[v20].fwdOfs = vehicle_cam_fwd.valueFloat;
      vehicle_cam_info[v20].rtOfs = v23;
      vehicle_cam_info[v20].upOfs = v22;
      if ( v24 )
      {
        v19 = 17;
        currentVehicleCameraTag = 17;
      }
      goto LABEL_37;
    }
    if ( vehicle_cam_resetOfs.valueInteger != 0 )
    {
      idCVar::SetBool(this: &vehicle_cam_resetOfs, newValue: false, force: true);
      v25 = 18;
      v26 = (float *)&algn_835D5359[3];
      do
      {
        v26[3] = 0.0;
        v26[4] = 0.0;
        v26 += 5;
        *v26 = 0.0;
        --v25;
      }
      while ( v25 != 0 );
    }
    else if ( vehicle_cam_printOfs.valueInteger != 0 )
    {
      idCVar::SetBool(this: &vehicle_cam_printOfs, newValue: false, force: true);
      v27 = vehicle_cam_up.valueFloat;
      v28 = vehicle_cam_rt.valueFloat;
      p_rtOfs = &vehicle_cam_info[0].rtOfs;
      v30 = currentVehicleCameraTag;
      vehicle_cam_info[v30].fwdOfs = vehicle_cam_fwd.valueFloat;
      vehicle_cam_info[v30].rtOfs = v28;
      vehicle_cam_info[v30].upOfs = v27;
      do
      {
        idLib::Printf(
          fmt: "name: %s   fwd: %f    rt: %f    up: %f\n",
          (const char *)(const char *)HIDWORD(COERCE_UNSIGNED_INT64(*(p_rtOfs - 1))),
          *(p_rtOfs - 1),
          *p_rtOfs,
          p_rtOfs[1]);
        p_rtOfs += 5;
      }
      while ( (int)p_rtOfs < (int)idVehicleMountedTurret::seatStateNames );
    }
  }
  else
  {
LABEL_50:
    v31 = gameLocal->vehicleEntities.next;
    if ( v31 != nullptr && v31 != gameLocal->vehicleEntities.head )
    {
      owner = v31->owner;
      goto LABEL_53;
    }
  }
}


// ========================================================================
// ?ForceOccupantLookAt@idVehicle@@QAAXHPAVidEntity@@H@Z
// EA  : 0x82D23948
// RVA : 0x00D23948
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __fastcall idVehicle::ForceOccupantLookAt(idVehicle *this, int occupantNum, idEntity *target, int time)
{
  idPresentable *presentable; // r3
  int v9; // r3
  int v10; // r31
  idPresentable *v11; // r3
  int v12; // r3
  idVehicleOccupant *VisualAsEntity; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
    v9 = (int)presentable->GetVehicleInterface(this: presentable);
  else
    v9 = 0;
  v10 = 16 * occupantNum;
  if ( vehicleOccupant_t::GetVisualAsEntity(this: (vehicleOccupant_t *)(*(_DWORD *)(v9 + 16472) + v10)) != nullptr )
  {
    v11 = this->presentable;
    if ( v11 != nullptr )
      v12 = (int)v11->GetVehicleInterface(this: v11);
    else
      v12 = 0;
    VisualAsEntity = vehicleOccupant_t::GetVisualAsEntity(this: (vehicleOccupant_t *)(*(_DWORD *)(v12 + 16472) + v10));
    idVehicleOccupant::ForceOccupantLookAt(this: VisualAsEntity, target, time);
  }
}


// ========================================================================
// ?SetDefaultWeaponGroup@idVehicle@@QAAXXZ
// EA  : 0x82D239E8
// RVA : 0x00D239E8
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __fastcall idVehicle::SetDefaultWeaponGroup(idVehicle *this)
{
  idPresentable *presentable; // r3
  int v3; // r3
  int WeaponSlot; // r26
  idPresentable *v5; // r3
  int v6; // r3
  int v7; // r27
  int i; // r29
  idPresentable *v9; // r3
  int v10; // r3
  idPresentable *v11; // r3
  int v12; // r3
  idPresentable *v13; // r3
  int v14; // r3
  int v15; // r11
  idPresentable *v16; // r3
  idVehicleWeapon *v17; // r30
  idPresentableVehicle *v18; // r31
  int v19; // r3
  idPresentable *v20; // r3
  int v21; // r3
  idPresentable *v22; // r3
  idPresentableVehicle *v23; // r3
  idPresentable *v24; // r3
  idPresentableVehicle *v25; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
    v3 = (int)presentable->GetVehicleInterface(this: presentable);
  else
    v3 = 0;
  if ( idVehicleWeapon::GetDeclVehicleWeapon(this: **(idVehicleWeapon ***)(v3 + 18744))->quickSlotGroup == QUICKSLOTGROUP_VEHICLE )
  {
    WeaponSlot = -1;
  }
  else
  {
    v5 = this->presentable;
    if ( v5 != nullptr )
      v6 = (int)v5->GetVehicleInterface(this: v5);
    else
      v6 = 0;
    WeaponSlot = idVehicleWeapon::GetWeaponSlot(this: **(idVehicleWeapon ***)(v6 + 18744));
  }
  v7 = 0;
  for ( i = 0; ; i += 4 )
  {
    v9 = this->presentable;
    v10 = v9 != nullptr ? (int)v9->GetVehicleInterface(this: v9) : 0;
    if ( v7 >= *(_DWORD *)(v10 + 18748) )
      break;
    v11 = this->presentable;
    if ( v11 != nullptr )
      v12 = (int)v11->GetVehicleInterface(this: v11);
    else
      v12 = 0;
    if ( idVehicleWeapon::GetDeclVehicleWeapon(this: *(idVehicleWeapon **)(*(_DWORD *)(v12 + 18744) + i))->quickSlotGroup != QUICKSLOTGROUP_VEHICLE )
    {
      v13 = this->presentable;
      v14 = v13 != nullptr ? (int)v13->GetVehicleInterface(this: v13) : 0;
      v15 = *(_DWORD *)(v14 + 18744);
      v16 = this->presentable;
      v17 = *(idVehicleWeapon **)(v15 + i);
      v18 = v16 != nullptr ? v16->GetVehicleInterface(this: v16) : nullptr;
      v19 = idVehicleWeapon::GetWeaponSlot(this: v17);
      if ( (unsigned __int8)idPresentableVehicle::WeaponGroupHasAmmo(this: v18, groupnum: v19) != 0 )
      {
        v20 = this->presentable;
        if ( v20 != nullptr )
          v21 = (int)v20->GetVehicleInterface(this: v20);
        else
          v21 = 0;
        WeaponSlot = idVehicleWeapon::GetWeaponSlot(this: *(idVehicleWeapon **)(*(_DWORD *)(v21 + 18744) + 4 * v7));
        break;
      }
    }
    ++v7;
  }
  if ( WeaponSlot > -1 )
  {
    v22 = this->presentable;
    if ( v22 != nullptr )
      v23 = v22->GetVehicleInterface(this: v22);
    else
      v23 = nullptr;
    idPresentableVehicle::SetCurrentWeaponGroup(this: v23, newWeaponGroup: WeaponSlot);
    v24 = this->presentable;
    if ( v24 != nullptr )
    {
      v25 = v24->GetVehicleInterface(this: v24);
      idPresentableVehicle::ActivateWeaponGroup(this: v25, notifySound: false);
    }
    else
    {
      idPresentableVehicle::ActivateWeaponGroup(this: nullptr, notifySound: false);
    }
  }
}


// ========================================================================
// ?InitEventAnimator@idVehicle@@IAAXXZ
// EA  : 0x82D23C18
// RVA : 0x00D23C18
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __fastcall idVehicle::InitEventAnimator(idVehicle *this)
{
  idTreeAnimator *TreeAnimatorFromPresentable; // r24
  int v3; // r28
  idGameTimeManager *v4; // r3
  int i; // r26
  const idDeclMD6 *decl; // r4
  idVehicle::eventAnimEntry_t *v7; // r29
  idVehicle::eventAnimEntry_t *v8; // r11
  idAnimation_vtbl *v9; // r11
  idVehicle::eventAnimEntry_t *v10; // r11
  idAnimation_vtbl *v11; // r11
  idVehicle::eventAnimEntry_t *v12; // r11
  const idDeclEntityDef *legsDummyDef; // r4
  idEntity *v14; // r3
  double x; // fp0
  double z; // fp11
  double y; // fp10
  idQuat *v18; // r3
  double v19; // fp8
  unsigned __int16 v20; // [sp+50h] [-A0h] BYREF
  __int16 v21; // [sp+52h] [-9Eh] BYREF
  int v22; // [sp+54h] [-9Ch] BYREF
  idVehicle::eventAnimEntry_t *p_spawnPosition; // [sp+58h] [-98h]
  idMat3 v24; // [sp+60h] [-90h] BYREF
  int v25; // [sp+94h] [-5Ch]
  int v26; // [sp+98h] [-58h]
  int v27; // [sp+9Ch] [-54h]
  int v28; // [sp+A0h] [-50h]
  float v29; // [sp+A4h] [-4Ch]

  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
  if ( TreeAnimatorFromPresentable != nullptr && this->eventAnimList.num != 0 )
  {
    LODWORD(v24.mat[1].y) = this->GetAnimStack_2(this);
    idStr::idStr(this: (idStr *)&v24.mat[1].z, text: "base");
    v3 = 0;
    v26 = 0;
    v27 = 0;
    v28 = 0;
    v29 = 0.0;
    v25 = 1;
    v4 = gameLocal->GetGameTimeManager(this: gameLocal);
    idAnimator_Base::Init(
      this: &this->eventAnimator,
      gametimeManager: v4,
      parms: (const idAnimatorParms_Base *)&v24.mat[1].y);
    for ( i = 0; i < this->eventAnimList.num; ++v3 )
    {
      if ( this->eventAnimList.list[v3].animation.len != 0 )
      {
        decl = TreeAnimatorFromPresentable->decl;
        v7 = &this->eventAnimList.list[v3];
        p_spawnPosition = v7;
        idDeclMD6::StrongLoadAlias(this: (idDeclMD6 *)&v20, result: decl, aliasName: v7->animation.data);
        v7->animationHandle.value = v20;
      }
      v8 = &this->eventAnimList.list[v3];
      if ( v8->animationHands.len != 0 && v8->handsModelDecl != nullptr )
      {
        v9 = animation->__vftable;
        p_spawnPosition = &this->eventAnimList.list[v3];
        p_spawnPosition->animationHandleHands.value = v9->StrongLoadAlias(
                                                        this: (idAnimation *)&v21,
                                                        result: (idHandle<unsigned short,enum invalidAliasHandle_t,65535> *)animation,
                                                        a3: p_spawnPosition->handsModelDecl,
                                                        a4: p_spawnPosition->animationHands.data)->value;
      }
      v10 = &this->eventAnimList.list[v3];
      if ( v10->animationLegs.len != 0 && v10->legsModelDecl != nullptr )
      {
        v11 = animation->__vftable;
        p_spawnPosition = &this->eventAnimList.list[v3];
        p_spawnPosition->animationHandleLegs.value = v11->StrongLoadAlias(
                                                       this: (idAnimation *)&v22,
                                                       result: (idHandle<unsigned short,enum invalidAliasHandle_t,65535> *)animation,
                                                       a3: p_spawnPosition->legsModelDecl,
                                                       a4: p_spawnPosition->animationLegs.data)->value;
      }
      v12 = &this->eventAnimList.list[v3];
      if ( v12->legsDummyDef != nullptr )
      {
        legsDummyDef = v12->legsDummyDef;
        p_spawnPosition = &this->eventAnimList.list[v3];
        v14 = gameLocal->SpawnEntityFromDef(this: gameLocal, a2: legsDummyDef, a3: -1, a4: -1, a5: -1);
        if ( v14 != nullptr )
          ((void (__fastcall *)(idEntity *, int))v14->dtr_idClass)(a1: v14, a2: 1);
      }
      ++i;
    }
    x = this->spawnPosition.x;
    this->eventAnimSupport.orgOrigin.x = this->spawnPosition.x;
    this->eventAnimSupport.orgOrigin.y = this->spawnPosition.y;
    z = this->spawnPosition.z;
    p_spawnPosition = (idVehicle::eventAnimEntry_t *)&this->spawnPosition;
    this->eventAnimSupport.orgOrigin.z = z;
    this->eventAnimSupport.nextOrigin.x = x;
    y = this->eventAnimSupport.orgOrigin.y;
    p_spawnPosition = (idVehicle::eventAnimEntry_t *)&this->eventAnimSupport.nextOrigin;
    this->eventAnimSupport.nextOrigin.y = y;
    this->eventAnimSupport.nextOrigin.z = this->eventAnimSupport.orgOrigin.z;
    v18 = idMat3::ToQuat(this: &v24, result: (idQuat *)&this->spawnOrientation);
    v19 = v18->x;
    this->eventAnimSupport.orgRotation.x = v18->x;
    this->eventAnimSupport.orgRotation.y = v18->y;
    p_spawnPosition = (idVehicle::eventAnimEntry_t *)&this->eventAnimSupport.nextRotation;
    this->eventAnimSupport.orgRotation.z = v18->z;
    this->eventAnimSupport.orgRotation.w = v18->w;
    this->eventAnimSupport.nextRotation.x = v19;
    this->eventAnimSupport.nextRotation.y = this->eventAnimSupport.orgRotation.y;
    this->eventAnimSupport.nextRotation.z = this->eventAnimSupport.orgRotation.z;
    this->eventAnimSupport.nextRotation.w = this->eventAnimSupport.orgRotation.w;
    idStr::FreeData(this: (idStr *)&v24.mat[1].z);
  }
}


// ========================================================================
// __unwind$514677
// EA  : 0x82D23ED0
// RVA : 0x00D23ED0
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void _unwind_514677()
{
  int v0; // r12

  idAnimatorParms_EndAdditiveChannels::~idAnimatorParms_EndAdditiveChannels(this: (vaiAction_t::vehicleCam_t *)(v0 - 240 + 112));
}


// ========================================================================
// ?LeaveAnimEventState@idVehicle@@AAAXH@Z
// EA  : 0x82D23EF8
// RVA : 0x00D23EF8
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __fastcall idVehicle::LeaveAnimEventState(idVehicle *this, const int iState)
{
  idVehicle::eventAnimEntry_t *v2; // r29
  int v4; // r27
  int v5; // r30
  int value; // r9
  idEntity *v7; // r3
  idEntity *v8; // r31
  idEventArg *v9; // r3
  idPresentable *presentable; // r3
  int v11; // r3
  idPresentable *v12; // r3
  int v13; // r3
  ILeapFilter *v14; // r3
  int num; // r29
  int v16; // r28
  int v17; // r31
  int v18; // r30
  idPresentable *v19; // r3
  int v20; // r3
  int v21; // r31
  int v22; // r30
  idPresentable *v23; // r3
  int v24; // r3
  idPresentable *v25; // r3
  idPresentable *v26; // r3
  int v27; // r31
  int v28; // r3
  int v29; // r11
  int v30; // r30
  int v31; // r31
  int i; // r29
  idPresentable *v33; // r3
  int v34; // r3
  int v35; // r11
  idEventArg v36[4]; // [sp+50h] [-60h] BYREF

  v2 = &this->eventAnimList.list[iState];
  v4 = 0;
  if ( v2->triggerLeave.num > 0 )
  {
    v5 = 0;
    do
    {
      value = v2->triggerLeave.list[v5].spawnId.value;
      if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
      {
        v7 = gameLocal->entities.ptr[value & 0x1FFF];
        if ( v7 != nullptr )
        {
          v8 = idEntity::CastTo(c: v7);
          if ( v8 != nullptr )
          {
            v9 = idEventArg::idEventArg(this: v36, data: this);
            idEventReceiver::PostEventMS(
              this: v8,
              ev: &EV_Activate,
              time: *(_DWORD *)&v9->type,
              arg1: (const idEventArg *)LODWORD(v9->value.v[1]));
          }
        }
      }
      ++v4;
      ++v5;
    }
    while ( v4 < v2->triggerLeave.num );
  }
  presentable = this->presentable;
  this->eventAnimSupport.currentState = -1;
  if ( presentable != nullptr )
    v11 = (int)presentable->GetVehicleInterface(this: presentable);
  else
    v11 = 0;
  *(_BYTE *)(v11 + 17271) = 1;
  if ( (*((_BYTE *)v2 + 168) & 0x10) != 0 )
  {
    v12 = this->presentable;
    if ( v12 != nullptr )
      v13 = (int)v12->GetVehicleInterface(this: v12);
    else
      v13 = 0;
    v14 = XAUDIO2::CX2SubmixVoice::ProcessingStage(this: (XAUDIO2::CX2SubmixVoice *)(v13 + 16512));
    num = (int)v14;
    if ( (int)v14 >= this->eventAnimSupport.prevContents.num )
      num = this->eventAnimSupport.prevContents.num;
    v16 = (int)v14;
    if ( (int)v14 >= this->eventAnimSupport.prevClipMasks.num )
      v16 = this->eventAnimSupport.prevClipMasks.num;
    v17 = 0;
    if ( num > 0 )
    {
      v18 = 0;
      do
      {
        v19 = this->presentable;
        if ( v19 != nullptr )
          v20 = (int)v19->GetVehicleInterface(this: v19);
        else
          v20 = 0;
        (*(void (__fastcall **)(int, int, int))(*(_DWORD *)(v20 + 16512) + 24))(
          a1: v20 + 16512,
          a2: this->eventAnimSupport.prevContents.list[v18++],
          a3: v17++);
      }
      while ( v17 < num );
    }
    v21 = 0;
    if ( v16 > 0 )
    {
      v22 = 0;
      do
      {
        v23 = this->presentable;
        if ( v23 != nullptr )
          v24 = (int)v23->GetVehicleInterface(this: v23);
        else
          v24 = 0;
        (*(void (__fastcall **)(int, int, int))(*(_DWORD *)(v24 + 16512) + 32))(
          a1: v24 + 16512,
          a2: this->eventAnimSupport.prevClipMasks.list[v22++],
          a3: v21++);
      }
      while ( v21 < v16 );
    }
    v25 = this->presentable;
    if ( v25 != nullptr && v25->GetVehicleInterface(this: v25) != nullptr )
    {
      v26 = this->presentable;
      v27 = this->eventAnimSupport.prevWheelClipMasks.num;
      if ( v26 != nullptr )
        v28 = (int)v26->GetVehicleInterface(this: v26);
      else
        v28 = 0;
      v29 = *(_DWORD *)(v28 + 16492);
      if ( v29 >= v27 )
        v29 = v27;
      if ( v29 > 0 )
      {
        v30 = 0;
        v31 = 0;
        for ( i = v29; i != 0; --i )
        {
          v33 = this->presentable;
          if ( v33 != nullptr )
            v34 = (int)v33->GetVehicleInterface(this: v33);
          else
            v34 = 0;
          v35 = *(_DWORD *)(*(_DWORD *)(v34 + 16488) + v31 + 4);
          if ( v35 != 0 )
            *(_DWORD *)(v35 + 520) = this->eventAnimSupport.prevWheelClipMasks.list[v30];
          v31 += 12;
          ++v30;
        }
      }
    }
  }
}


// ========================================================================
// ?Hide@idVehicle@@UAAXXZ
// EA  : 0x82D243D0
// RVA : 0x00D243D0
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __fastcall idVehicle::Hide(idVehicle *this)
{
  int v2; // r28
  int v3; // r29
  idVehicleWindow::window_t *v4; // r30
  idRenderModel *brokenModel; // r31
  idRenderModel *normalModel; // r31
  int v7; // r31
  int i; // r30
  idPresentable *presentable; // r3
  int v10; // r3
  idPresentable *v11; // r3
  int v12; // r3
  idAttachmentCollection *v13; // r3
  idPhysics *Physics; // r3
  int v15; // r27
  int j; // r29
  idPresentable *v17; // r3
  int v18; // r3
  idPresentable *v19; // r3
  int v20; // r3
  int v21; // r30
  int v22; // r11
  int v23; // r31
  idPresentable *v24; // r3
  int v25; // r3
  idVehicleOccupant *VisualAsEntity; // r3

  if ( (unsigned __int8)Get_idCombatStage_useRelaxedChatterVO(ptr: (unsigned __int8 *)this) == 0 )
  {
    v2 = 0;
    if ( this->vehicleWindow.windows.num > 0 )
    {
      v3 = 0;
      do
      {
        v4 = &this->vehicleWindow.windows.list[v3];
        brokenModel = v4->brokenModel;
        if ( brokenModel != nullptr && !brokenModel->unlinked )
        {
          idRenderModel::CommitThisFrame(this: brokenModel);
          brokenModel->unlinked = true;
        }
        normalModel = v4->normalModel;
        if ( normalModel != nullptr && !normalModel->unlinked )
        {
          idRenderModel::CommitThisFrame(this: v4->normalModel);
          normalModel->unlinked = true;
        }
        ++v2;
        ++v3;
      }
      while ( v2 < this->vehicleWindow.windows.num );
    }
    v7 = 0;
    for ( i = 0; ; i += 4 )
    {
      presentable = this->presentable;
      v10 = presentable != nullptr ? (int)presentable->GetVehicleInterface(this: presentable) : 0;
      if ( v7 >= *(_DWORD *)(v10 + 18748) )
        break;
      v11 = this->presentable;
      if ( v11 != nullptr )
        v12 = (int)v11->GetVehicleInterface(this: v11);
      else
        v12 = 0;
      idVehicleWeapon::Hide(this: *(idVehicleWeapon **)(*(_DWORD *)(v12 + 18744) + i));
      ++v7;
    }
    v13 = this->GetAttachments_2(this);
    idAttachmentCollection::HideAttachments(this: v13);
  }
  idEntity::Hide(this);
  idVehicle::RemoveAIEvents(this);
  Physics = idEntity::GetPhysics(this);
  Physics->UnlinkClip(this: Physics);
  idEntity::BecomeInactive(this, flags: 3);
  v15 = 0;
  for ( j = 0; ; j += 16 )
  {
    v17 = this->presentable;
    v18 = v17 != nullptr ? (int)v17->GetVehicleInterface(this: v17) : 0;
    if ( v15 >= *(_DWORD *)(v18 + 16476) )
      break;
    v19 = this->presentable;
    if ( v19 != nullptr )
      v20 = (int)v19->GetVehicleInterface(this: v19);
    else
      v20 = 0;
    v21 = *(_DWORD *)(v20 + 16472) + j;
    v22 = *(_DWORD *)(v21 + 4);
    v23 = v22 & 0x3FFF;
    if ( v22 != 0
      && idClientGame::IsPresentableIndexValid(this: clientGame, index: v22 & 0x3FFF)
      && idClientGame::GetPresentableByIndex(this: clientGame, index: v23)->spawnId == *(_DWORD *)(v21 + 4) )
    {
      v24 = this->presentable;
      if ( v24 != nullptr )
        v25 = (int)v24->GetVehicleInterface(this: v24);
      else
        v25 = 0;
      VisualAsEntity = vehicleOccupant_t::GetVisualAsEntity(this: (vehicleOccupant_t *)(*(_DWORD *)(v25 + 16472) + j));
      VisualAsEntity->Hide_2(this: VisualAsEntity);
    }
    ++v15;
  }
}


// ========================================================================
// ?Show@idVehicle@@UAAXXZ
// EA  : 0x82D24630
// RVA : 0x00D24630
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __fastcall idVehicle::Show(idVehicle *this)
{
  int v2; // r30
  int v3; // r31
  idVehicleWindow::window_t *v4; // r11
  idRenderModel *brokenModel; // r3
  int v6; // r31
  int i; // r30
  idPresentable *presentable; // r3
  int v9; // r3
  idPresentable *v10; // r3
  int v11; // r3
  idAttachmentCollection *v12; // r3
  idPhysics *Physics; // r3
  int v14; // r26
  int j; // r29
  idPresentable *v16; // r3
  int v17; // r3
  idPresentable *v18; // r3
  int v19; // r3
  int v20; // r30
  int v21; // r11
  int v22; // r31
  idPresentable *v23; // r3
  int v24; // r3
  idVehicleOccupant *VisualAsEntity; // r3

  if ( (unsigned __int8)Get_idCombatStage_useRelaxedChatterVO(ptr: (unsigned __int8 *)this) != 0 )
  {
    v2 = 0;
    if ( this->vehicleWindow.windows.num > 0 )
    {
      v3 = 0;
      do
      {
        v4 = &this->vehicleWindow.windows.list[v3];
        if ( v4->broken )
          brokenModel = v4->brokenModel;
        else
          brokenModel = v4->normalModel;
        if ( brokenModel != nullptr )
          idRenderModel::CommitThisFrame(this: brokenModel);
        ++v2;
        ++v3;
      }
      while ( v2 < this->vehicleWindow.windows.num );
    }
    v6 = 0;
    for ( i = 0; ; i += 4 )
    {
      presentable = this->presentable;
      v9 = presentable != nullptr ? (int)presentable->GetVehicleInterface(this: presentable) : 0;
      if ( v6 >= *(_DWORD *)(v9 + 18748) )
        break;
      v10 = this->presentable;
      if ( v10 != nullptr )
        v11 = (int)v10->GetVehicleInterface(this: v10);
      else
        v11 = 0;
      idVehicleWeapon::Show(this: *(idVehicleWeapon **)(*(_DWORD *)(v11 + 18744) + i));
      ++v6;
    }
    v12 = this->GetAttachments_2(this);
    idAttachmentCollection::ShowAttachments(this: v12, hideVehicleAttachments: true);
  }
  idEntity::Show(this);
  Physics = idEntity::GetPhysics(this);
  Physics->LinkClip(this: Physics);
  idVehicle::AttachAIEvents(this);
  idEntity::BecomeActive(this, flags: 7);
  v14 = 0;
  for ( j = 0; ; j += 16 )
  {
    v16 = this->presentable;
    v17 = v16 != nullptr ? (int)v16->GetVehicleInterface(this: v16) : 0;
    if ( v14 >= *(_DWORD *)(v17 + 16476) )
      break;
    v18 = this->presentable;
    if ( v18 != nullptr )
      v19 = (int)v18->GetVehicleInterface(this: v18);
    else
      v19 = 0;
    v20 = *(_DWORD *)(v19 + 16472) + j;
    v21 = *(_DWORD *)(v20 + 4);
    v22 = v21 & 0x3FFF;
    if ( v21 != 0
      && idClientGame::IsPresentableIndexValid(this: clientGame, index: v21 & 0x3FFF)
      && idClientGame::GetPresentableByIndex(this: clientGame, index: v22)->spawnId == *(_DWORD *)(v20 + 4) )
    {
      v23 = this->presentable;
      if ( v23 != nullptr )
        v24 = (int)v23->GetVehicleInterface(this: v23);
      else
        v24 = 0;
      VisualAsEntity = vehicleOccupant_t::GetVisualAsEntity(this: (vehicleOccupant_t *)(*(_DWORD *)(v24 + 16472) + j));
      VisualAsEntity->Show(this: VisualAsEntity);
    }
    ++v14;
  }
}


// ========================================================================
// ?CanPlayerEnter@idVehicle@@QBA_NW4vehicleSeat_t@@PBVidEntity@@@Z
// EA  : 0x82D24868
// RVA : 0x00D24868
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

BOOL __fastcall idVehicle::CanPlayerEnter(idVehicle *this, int wantSeat, idPlayer *activator)
{
  int num; // r11
  int v7; // r28
  idPresentablePtr<idPresentableActor> *Occupant; // r3
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idPlayer *v11; // r3
  double x; // fp31
  double y; // fp30
  double z; // fp29
  long double v15; // fp2
  double v16; // fp31
  long double v17; // fp2
  float v18; // [sp+50h] [-100h] BYREF
  float v19; // [sp+54h] [-FCh]
  float v20; // [sp+58h] [-F8h]
  float v21; // [sp+5Ch] [-F4h]
  idVec3 v22; // [sp+60h] [-F0h] BYREF
  float v23; // [sp+70h] [-E0h] BYREF
  float v24; // [sp+74h] [-DCh]
  float v25; // [sp+78h] [-D8h]
  idVec3 v26; // [sp+80h] [-D0h] BYREF
  float v27[4]; // [sp+90h] [-C0h] BYREF
  float v28[4]; // [sp+A0h] [-B0h] BYREF
  float v29; // [sp+B0h] [-A0h] BYREF
  float v30; // [sp+B4h] [-9Ch]
  float v31; // [sp+B8h] [-98h]
  idMat3 v32; // [sp+E0h] [-70h] BYREF

  num = this->seatInfo.num;
  v7 = -1;
  if ( num == 0 )
    return false;
  if ( wantSeat < num )
  {
    Occupant = (idPresentablePtr<idPresentableActor> *)idVehicle::GetOccupant(this, i: wantSeat);
    if ( !idPresentablePtr<idPresentable>::IsValid(this: Occupant)
      && (this->seatInfo.list[wantSeat].playerCanOccupy || vehicle_playerCanEnter.valueInteger != 0) )
    {
      v7 = wantSeat;
    }
  }
  if ( this->forceEntryTagData.parentJoint.value != 0xFFFF && activator != nullptr )
  {
    TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
    if ( (unsigned __int8)idTreeAnimator::GetWorldSpaceTagTransform(
                            this: TreeAnimatorFromPresentable,
                            tagData: &this->forceEntryTagData,
                            origin: &v22,
                            axis: &v32) != 0 )
    {
      v11 = idPlayer::CastTo(c: activator);
      if ( v11 != nullptr )
      {
        v11->GetViewTransform(this: v11, a2: (idVec3 *)&v23, a3: (idMat3 *)&v29);
        x = v22.x;
        y = v22.y;
        z = v22.z;
        v26.x = v22.x - v23;
        v26.y = v22.y - v24;
        v26.z = v22.z - v25;
        if ( idVec3::NormalizeFast(this: &v26) > (double)vehicle_forceEntryDist.valueFloat )
          return false;
        v18 = x;
        v19 = y;
        v20 = z;
        v21 = 5.0;
        if ( vehicle_forceEntryDebug.valueInteger != 0 )
        {
          clientGame->renderWorld->DebugSphere(
            this: clientGame->renderWorld,
            a2: (const idVec4 *)&idColor::colorCyan,
            a3: (const idSphere *)&v18,
            a4: 12,
            a5: 0,
            a6: false);
          v27[0] = (float)(v29 * (float)100.0) + v23;
          v27[1] = (float)(v30 * (float)100.0) + v24;
          v27[2] = (float)(v31 * (float)100.0) + v25;
          clientGame->renderWorld->DebugLine(
            this: clientGame->renderWorld,
            a2: (const idVec4 *)&idColor::colorRed,
            a3: (const idVec3 *)&v23,
            a4: (const idVec3 *)v27,
            a5: 0,
            a6: false);
          v21 = 1.0;
          v18 = v23;
          v19 = v24;
          v20 = v25;
          clientGame->renderWorld->DebugSphere(
            this: clientGame->renderWorld,
            a2: (const idVec4 *)&idColor::colorRed,
            a3: (const idSphere *)&v18,
            a4: 12,
            a5: 0,
            a6: false);
          v28[0] = (float)(v26.x * (float)100.0) + v22.x;
          v28[1] = (float)(v26.y * (float)100.0) + v22.y;
          v28[2] = (float)(v26.z * (float)100.0) + v22.z;
          clientGame->renderWorld->DebugLine(
            this: clientGame->renderWorld,
            a2: (const idVec4 *)&idColor::colorMagenta,
            a3: &v22,
            a4: (const idVec3 *)v28,
            a5: 0,
            a6: false);
          v21 = 1.0;
          v18 = v22.x;
          v19 = v22.y;
          v20 = v22.z;
          clientGame->renderWorld->DebugSphere(
            this: clientGame->renderWorld,
            a2: (const idVec4 *)&idColor::colorMagenta,
            a3: (const idSphere *)&v18,
            a4: 12,
            a5: 0,
            a6: false);
        }
        *(double *)&v15 = (float)(vehicle_forceEntryAngle.valueFloat * idMath::M_DEG2RAD);
        v16 = (float)((float)(v32.mat[1].x * v29) + (float)((float)(v32.mat[1].z * v31) + (float)(v32.mat[1].y * v30)));
        v17 = cos(x: v15);
        if ( v16 < (float)*(double *)&v17 )
          return false;
        if ( vehicle_forceEntryDebug.valueInteger != 0 )
        {
          v21 = 10.0;
          clientGame->renderWorld->DebugSphere(
            this: clientGame->renderWorld,
            a2: (const idVec4 *)&idColor::colorGreen,
            a3: (const idSphere *)&v18,
            a4: 12,
            a5: 0,
            a6: false);
        }
      }
    }
  }
  return v7 != -1;
}


// ========================================================================
// ?ChangeSeatInfo@idVehicle@@QAAXHUseatInfo_t@1@@Z
// EA  : 0x82D24C50
// RVA : 0x00D24C50
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __fastcall idVehicle::ChangeSeatInfo(idVehicle *this, int seatNum, idVehicle::seatInfo_t *changeSeatInfo)
{
  int v5; // r29
  size_t len; // r26
  idVehicle::seatInfo_t *v7; // r27

  if ( seatNum < 0 || seatNum > this->seatInfo.num - 1 )
  {
    idLib::Warning(fmt: "Bad seat num in Change Seat Info seat %d, list is %d", seatNum, this->seatInfo.num);
  }
  else
  {
    v5 = seatNum;
    len = changeSeatInfo->tagName.len;
    v7 = &this->seatInfo.list[seatNum];
    idStr::EnsureAlloced(
      this: &v7->tagName,
      amount: changeSeatInfo->tagName.len + 1,
      keepold: false,
      geometricGrowth: false);
    memcpy(Dst: v7->tagName.data, Src: changeSeatInfo->tagName.data, Size: len);
    v7->tagName.data[len] = 0;
    v7->tagName.len = len;
    this->seatInfo.list[v5].model = changeSeatInfo->model;
    this->seatInfo.list[v5].weaponAttach = changeSeatInfo->weaponAttach;
    this->seatInfo.list[v5].playerCanOccupy = changeSeatInfo->playerCanOccupy;
    this->seatInfo.list[v5].isEasilyThrown = changeSeatInfo->isEasilyThrown;
  }
  idVehicle::seatInfo_t::~seatInfo_t(this: changeSeatInfo);
}


// ========================================================================
// __unwind$517416
// EA  : 0x82D24D2C
// RVA : 0x00D24D2C
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void _unwind_517416()
{
  int v0; // r12

  idVehicle::seatInfo_t::~seatInfo_t(this: *(idVehicle::seatInfo_t **)(v0 - 144 + 180));
}


// ========================================================================
// ?ActivateBoostpad@idVehicle_Car@@QAAXMH@Z
// EA  : 0x82D24D58
// RVA : 0x00D24D58
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __fastcall idVehicle_Car::ActivateBoostpad(idVehicle_Car *this, double acceleration, int time, int a4)
{
  BOOL active; // r11
  idVehicle_Megabooster *p_boostpad; // r30
  idPresentable *presentable; // r11
  idClientServerInterface *csInterface; // r3
  int v9; // r10
  int v10; // r9
  int v11; // r8
  int v12; // r7
  int v13; // r6
  int v14; // r5

  active = this->boostpad.active;
  this->boostpad.acceleration = acceleration;
  this->boostpad.time = a4;
  if ( !active )
  {
    p_boostpad = &this->boostpad;
    idVehicleQuickItem::Activate(this: &this->boostpad);
    this->boostpad.vehicle.spawnId.value = (gameLocal->spawnIds.ptr[this->entityNumber] << 13) | this->entityNumber;
    presentable = this->presentable;
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      presentable = this->presentable;
    }
    csInterface = presentable->csInterface;
    if ( csInterface != nullptr )
    {
      csInterface->VehicleMegaboosterUse(this: csInterface, a2: p_boostpad, a3: presentable);
      idVehicle_Car::AddQuickItemThink(this, item: p_boostpad, a3: v14, a4: v13, a5: v12, a6: v11, a7: v10, a8: v9);
    }
  }
}


// ========================================================================
// ?SetCollisionDamage@idVehicle@@QAAXPBVidDeclDamage@@HPBVidEntity@@@Z
// EA  : 0x82D24E18
// RVA : 0x00D24E18
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __fastcall idVehicle::SetCollisionDamage(
        idVehicle *this,
        const idDeclDamage *decl,
        int delayMS,
        const idEntity *attacker)
{
  this->collisionDamage = decl;
  this->collisionDamageTime = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) + delayMS;
  if ( attacker != nullptr )
    this->collisionDamageAttacker.spawnId.value = (gameLocal->spawnIds.ptr[attacker->entityNumber] << 13)
                                                | attacker->entityNumber;
  else
    this->collisionDamageAttacker.spawnId.value = 0x1FFF;
}


// ========================================================================
// ?EnterAnimEventState@idVehicle@@AAAXHH@Z
// EA  : 0x82D24EA0
// RVA : 0x00D24EA0
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __fastcall idVehicle::EnterAnimEventState(idVehicle *this, int iState, unsigned int blendTime)
{
  idTreeAnimator *TreeAnimatorFromPresentable; // r25
  idVehicle::eventAnimEntry_t *list; // r10
  unsigned __int16 *p_value; // r23
  int v9; // r28
  int v10; // r29
  int v11; // r9
  idEntity *v12; // r3
  idEntity *v13; // r30
  idEventArg *v14; // r3
  const idMD6Alias *Alias; // r3
  idResource *Existing; // r15
  idEntity *v17; // r3
  idPhysics *Physics; // r3
  float *v19; // r3
  idEntity *v20; // r3
  idPhysics *v21; // r3
  idQuat *v22; // r3
  idQuat *v23; // r3
  idPresentable *presentable; // r3
  int v25; // r3
  XAUDIO2::CX2SubmixVoice *AFPhysics; // r3
  ILeapFilter *v27; // r26
  int v28; // r30
  int v29; // r28
  idPresentable *v30; // r3
  int v31; // r3
  int *v32; // r29
  idPresentable *v33; // r3
  int v34; // r3
  int *v35; // r29
  idPresentable *v36; // r3
  int v37; // r3
  idPresentable *v38; // r3
  int v39; // r3
  idPresentable *v40; // r3
  idPresentable *v41; // r3
  int v42; // r11
  int v43; // r28
  int v44; // r29
  int i; // r30
  idPresentable *v46; // r3
  int v47; // r3
  idPresentable *v48; // r3
  int v49; // r3
  int v50; // r10
  int v51; // r9
  unsigned int v52; // r4
  int GameMs; // r24
  idTreeAnimator *v54; // r3
  idAnimStack *(__fastcall *GetAnimStack_2)(struct idAnimatedEntity *); // ctr
  const idAnimStack *v56; // r3
  __int64 v57; // r8
  const idAnimStack *v58; // r3
  const blendParms_t *v59; // r7
  idVehicleOccupant *OccupantVisual; // r3
  idVehicleOccupant *v61; // r30
  idAnimStack *v62; // r3
  idGameTimeManager *v63; // r3
  const idMD6Alias *v64; // r3
  const idMD6Anim *v65; // r28
  idAnimStack *(__fastcall *v66)(struct idAnimatedEntity *); // ctr
  const idAnimStack *v67; // r3
  __int64 v68; // r8
  const idAnimStack *v69; // r3
  const blendParms_t *v70; // r7
  idList<idEventReceiver *,5> *v71; // r11
  idEventReceiver *v72; // r3
  idVehicleOccupant *v73; // r3
  idEntity *v74; // r29
  idVehicleOccupant *v75; // r3
  idVehicleOccupant *v76; // r30
  char *data; // r29
  idTreeAnimator *v78; // r3
  idGameTimeManager *v79; // r3
  const idMD6Alias *v80; // r3
  const idMD6Anim *v81; // r28
  idAnimStack *(__fastcall *v82)(struct idAnimatedEntity *); // ctr
  const idAnimStack *v83; // r3
  __int64 v84; // r8
  const idAnimStack *v85; // r3
  const blendParms_t *v86; // r7
  int trackedMemory; // r10
  idVec3 *v88; // r11
  idVec3 *v89; // r9
  idQuat *v90; // r29
  double v91; // fp8
  idQuat *v92; // r4
  double v93; // fp6
  idQuat *v94; // r3
  double z; // fp12
  double x; // fp13
  double y; // fp11
  double v98; // fp10
  double v99; // fp4
  double v100; // fp3
  double v101; // fp2
  double v102; // fp1
  double v103; // fp1
  double v104; // fp0
  idQuat *v105; // r3
  double w; // fp9
  double v107; // fp13
  double v108; // fp8
  double v109; // fp11
  double v110; // fp4
  double v111; // fp5
  double v112; // fp10
  double v113; // fp3
  double v114; // fp2
  double v115; // fp0
  blendParms_t v116; // [sp+60h] [-180h] BYREF
  idMat3 v117; // [sp+80h] [-160h] BYREF
  idQuat v118; // [sp+B0h] [-130h] BYREF
  idAnimatorParms_Base v119; // [sp+C0h] [-120h] BYREF
  idAnimatorParms_Base v120; // [sp+100h] [-E0h] BYREF

  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
  if ( TreeAnimatorFromPresentable != nullptr )
  {
    if ( iState < 0 || iState >= this->eventAnimList.num )
    {
      idLib::Warning(
        fmt: "idVehicle '%s' - EnterAnimEventState iState %d is not valid, max events %d",
        this->name.data,
        iState,
        this->eventAnimList.num);
      return;
    }
    list = this->eventAnimList.list;
    this->eventAnimSupport.currentState = iState;
    p_value = &list[iState].animationHandle.value;
    v9 = 0;
    if ( *((int *)p_value + 29) > 0 )
    {
      v10 = 0;
      do
      {
        v11 = *(_DWORD *)(v10 + *((_DWORD *)p_value + 28));
        if ( gameLocal->spawnIds.ptr[v11 & 0x1FFF] == v11 >> 13 )
        {
          v12 = gameLocal->entities.ptr[v11 & 0x1FFF];
          if ( v12 != nullptr )
          {
            v13 = idEntity::CastTo(c: v12);
            if ( v13 != nullptr )
            {
              v14 = idEventArg::idEventArg(this: (idEventArg *)&v117, data: this);
              idEventReceiver::PostEventMS(
                this: v13,
                ev: &EV_Activate,
                time: *(_DWORD *)&v14->type,
                arg1: (const idEventArg *)LODWORD(v14->value.v[1]));
            }
          }
        }
        ++v9;
        v10 += 4;
      }
      while ( v9 < *((_DWORD *)p_value + 29) );
    }
    Alias = idDeclMD6::FindAlias(
              this: TreeAnimatorFromPresentable->decl,
              aliasHandle: (const idHandle<unsigned short,enum invalidAliasHandle_t,65535> *)p_value,
              includeInherited: true);
    if ( Alias != nullptr )
    {
      Existing = idResourceList::FindExisting(
                   this: &idMD6Anim::resourceList,
                   name: (char *)Alias->animRefs.list->str,
                   skipStaleCheck: false);
      if ( Existing != nullptr )
      {
        this->eventAnimSupport.animStartFrame = idAccolade::Count(this: &clientGame->gameTimeManager);
        if ( gameLocal->spawnIds.ptr[*((_DWORD *)p_value + 27) & 0x1FFF] == *((int *)p_value + 27) >> 13 )
        {
          v17 = idEntityPtr<idEntity const>::operator->(this: (idEntityPtr<idEntity> *)p_value + 27);
          Physics = idEntity::GetPhysics(this: v17);
          v19 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
          this->eventAnimSupport.orgOrigin.x = *v19;
          this->eventAnimSupport.orgOrigin.y = v19[1];
          this->eventAnimSupport.orgOrigin.z = v19[2];
          v20 = idEntityPtr<idEntity const>::operator->(this: (idEntityPtr<idEntity> *)p_value + 27);
          v21 = idEntity::GetPhysics(this: v20);
          v22 = (idQuat *)v21->GetAxis(this: v21, a2: 0);
          v23 = idMat3::ToQuat(this: &v117, result: v22);
        }
        else
        {
          if ( (p_value[84] & 0x80) == 0 )
            goto LABEL_18;
          this->eventAnimSupport.orgOrigin.x = *(float *)&Existing[2].resourceError;
          this->eventAnimSupport.orgOrigin.y = *(float *)&Existing[2].networkID;
          this->eventAnimSupport.orgOrigin.z = *(float *)&Existing[2].staleCount;
          v23 = idAngles::ToQuat(this: (idAngles *)&v117, result: (idQuat *)&Existing[2] + 2);
        }
        this->eventAnimSupport.orgRotation.x = v23->x;
        this->eventAnimSupport.orgRotation.y = v23->y;
        this->eventAnimSupport.orgRotation.z = v23->z;
        this->eventAnimSupport.orgRotation.w = v23->w;
LABEL_18:
        idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->eventAnimSupport.prevContents);
        idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->eventAnimSupport.prevClipMasks);
        idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->eventAnimSupport.prevWheelClipMasks);
        presentable = this->presentable;
        if ( presentable != nullptr )
          v25 = (int)presentable->GetVehicleInterface(this: presentable);
        else
          v25 = 0;
        *(_BYTE *)(v25 + 17271) = 0;
        if ( (p_value[84] & 0x10) != 0 )
        {
          AFPhysics = (XAUDIO2::CX2SubmixVoice *)idVehicle::GetAFPhysics(this);
          v27 = XAUDIO2::CX2SubmixVoice::ProcessingStage(this: AFPhysics);
          idList<idObstacleBuffers *,5>::SetNum(
            this: (idList<int,37> *)&this->eventAnimSupport.prevContents,
            newNum: (int)v27);
          idList<idObstacleBuffers *,5>::SetNum(
            this: (idList<int,37> *)&this->eventAnimSupport.prevClipMasks,
            newNum: (int)v27);
          v28 = 0;
          if ( (int)v27 > 0 )
          {
            v29 = 0;
            do
            {
              v30 = this->presentable;
              if ( v30 != nullptr )
                v31 = (int)v30->GetVehicleInterface(this: v30);
              else
                v31 = 0;
              v32 = this->eventAnimSupport.prevContents.list;
              v32[v29] = (*(int (__fastcall **)(int, int))(*(_DWORD *)(v31 + 16512) + 28))(a1: v31 + 16512, a2: v28);
              v33 = this->presentable;
              if ( v33 != nullptr )
                v34 = (int)v33->GetVehicleInterface(this: v33);
              else
                v34 = 0;
              v35 = this->eventAnimSupport.prevClipMasks.list;
              v35[v29] = (*(int (__fastcall **)(int, int))(*(_DWORD *)(v34 + 16512) + 36))(a1: v34 + 16512, a2: v28);
              v36 = this->presentable;
              if ( v36 != nullptr )
                v37 = (int)v36->GetVehicleInterface(this: v36);
              else
                v37 = 0;
              (*(void (__fastcall **)(int, _DWORD, int))(*(_DWORD *)(v37 + 16512) + 24))(
                a1: v37 + 16512,
                a2: 0,
                a3: v28);
              v38 = this->presentable;
              if ( v38 != nullptr )
                v39 = (int)v38->GetVehicleInterface(this: v38);
              else
                v39 = 0;
              (*(void (__fastcall **)(int, _DWORD, int))(*(_DWORD *)(v39 + 16512) + 32))(
                a1: v39 + 16512,
                a2: 0,
                a3: v28++);
              ++v29;
            }
            while ( v28 < (int)v27 );
          }
          v40 = this->presentable;
          if ( v40 != nullptr && v40->GetVehicleInterface(this: v40) != nullptr )
          {
            v41 = this->presentable;
            if ( v41 != nullptr )
              v42 = (int)v41->GetVehicleInterface(this: v41);
            else
              v42 = 0;
            idList<idObstacleBuffers *,5>::SetNum(
              this: (idList<int,37> *)&this->eventAnimSupport.prevWheelClipMasks,
              newNum: *(_DWORD *)(v42 + 16492));
            v43 = 0;
            v44 = 0;
            for ( i = 0; ; i += 12 )
            {
              v46 = this->presentable;
              v47 = v46 != nullptr ? (int)v46->GetVehicleInterface(this: v46) : 0;
              if ( v43 >= *(_DWORD *)(v47 + 16492) )
                break;
              v48 = this->presentable;
              if ( v48 != nullptr )
                v49 = (int)v48->GetVehicleInterface(this: v48);
              else
                v49 = 0;
              v50 = 0;
              v51 = *(_DWORD *)(*(_DWORD *)(v49 + 16488) + i + 4);
              if ( v51 != 0 )
              {
                v50 = *(_DWORD *)(v51 + 520);
                *(_DWORD *)(v51 + 520) = 0;
              }
              ++v43;
              this->eventAnimSupport.prevWheelClipMasks.list[v44++] = v50;
            }
          }
        }
        blendParms_t::blendParms_t(this: &v116);
        blendParms_t::SetDestStartFrame(this: &v116, frame: 0);
        v52 = blendTime;
        if ( blendTime == -1 )
          v52 = *((_DWORD *)p_value + 41);
        blendParms_t::SetDurationMS(this: &v116, ms: v52);
        v116.parms.originBlend = 1;
        GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        if ( *p_value == 0xFFFF )
        {
          v54 = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
          idLib::Warning(
            fmt: "idAnimatedSimple '%s - could not find animation alias '%d' in decl '%s",
            this->name.data,
            *p_value,
            v54->name.str);
        }
        else
        {
          idEntity::BecomeActive(this, flags: 7);
          GetAnimStack_2 = this->GetAnimStack_2;
          if ( (p_value[84] & 0x20) != 0 )
          {
            v56 = GetAnimStack_2(this);
            LODWORD(v57) = &v116;
            idAnimator_Channel::CycleAnim(
              this: &this->eventAnimator,
              stack: v56,
              ah: (const idHandle<unsigned short,enum invalidAliasHandle_t,65535> *)p_value,
              curTime: GameMs,
              rateScale: 1.0,
              leafStarted: v57,
              a7: nullptr);
          }
          else
          {
            v58 = GetAnimStack_2(this);
            idAnimator_Channel::PlayAnim(
              this: &this->eventAnimator,
              stack: v58,
              ah: (const idHandle<unsigned short,enum invalidAliasHandle_t,65535> *)p_value,
              curTime: GameMs,
              rateScale: 1.0,
              blendParms: v59,
              blendOutDurationMS_: &v116,
              leafStarted: (idMD6LeafPlay **)0xFFFFFFFF,
              a9: nullptr);
          }
        }
        if ( p_value[1] != 0xFFFF )
        {
          OccupantVisual = idVehicle::GetOccupantVisual(this, index: 0);
          v61 = OccupantVisual;
          if ( OccupantVisual != nullptr
            && idAnimatedEntity::GetTreeAnimatorFromPresentable(this: OccupantVisual) != nullptr )
          {
            v62 = v61->GetAnimStack_2(this: v61);
            if ( !idAnimator_Base::IsInitialized(this: &this->eventAnimatorHands, animStack: v62) )
            {
              v119.animStack = v61->GetAnimStack_2(this: v61);
              idStr::idStr(this: &v119.name, text: "base");
              v119.alpha = 0.0;
              v119.blendOp = BOP_LERP;
              memset(&v119.originBlend, 0, 12);
              v63 = gameLocal->GetGameTimeManager(this: gameLocal);
              idAnimator_Base::Init(this: &this->eventAnimatorHands, gametimeManager: v63, parms: &v119);
              idStr::FreeData(this: &v119.name);
            }
            v64 = idDeclMD6::FindAlias(
                    this: *((idDeclMD6 **)p_value + 37),
                    aliasHandle: (const idHandle<unsigned short,enum invalidAliasHandle_t,65535> *)p_value + 1,
                    includeInherited: true);
            if ( v64 != nullptr )
            {
              v65 = (const idMD6Anim *)idResourceList::FindExisting(
                                         this: &idMD6Anim::resourceList,
                                         name: (char *)v64->animRefs.list->str,
                                         skipStaleCheck: false);
              v66 = v61->GetAnimStack_2;
              if ( (p_value[84] & 0x20) != 0 )
              {
                v67 = v66(this: v61);
                LODWORD(v68) = &v116;
                idAnimator_Channel::CycleAnim(
                  this: &this->eventAnimatorHands,
                  stack: v67,
                  ah: v65,
                  curTime: GameMs,
                  rateScale: 1.0,
                  leafStarted: v68,
                  a7: nullptr);
              }
              else
              {
                v69 = v66(this: v61);
                idAnimator_Channel::PlayAnim(
                  this: &this->eventAnimatorHands,
                  stack: v69,
                  ah: v65,
                  curTime: GameMs,
                  rateScale: 1.0,
                  blendParms: v70,
                  blendOutDurationMS_: &v116,
                  leafStarted: (idMD6LeafPlay **)0xFFFFFFFF,
                  a9: nullptr);
              }
            }
          }
        }
        v71 = *((idList<idEventReceiver *,5> **)p_value + 39);
        if ( v71 == nullptr || *((_DWORD *)p_value + 38) == 0 || p_value[2] == 0xFFFF )
          goto LABEL_84;
        v72 = *((idEventReceiver **)p_value + 2);
        if ( v72 != nullptr )
        {
          if ( v72[41].listenerList == v71 )
          {
LABEL_84:
            trackedMemory = Existing[1].trackedMemory;
            v88 = &vec3_origin;
            v89 = &vec3_origin;
            if ( trackedMemory != 0 )
            {
              v89 = (idVec3 *)(trackedMemory + 64);
              v88 = (idVec3 *)(trackedMemory + 112);
            }
            v90 = &quat_identity;
            v91 = (float)(v88->y - v89->y);
            v92 = &quat_identity;
            v93 = (float)(v88->z - v89->z);
            v118.x = v88->x - v89->x;
            v118.y = v91;
            v118.z = v93;
            if ( trackedMemory != 0 )
            {
              v92 = (idQuat *)(trackedMemory + 32);
              v90 = (idQuat *)(trackedMemory + 80);
            }
            v94 = idQuat::Inverse(this: (idQuat *)&v117, result: v92);
            z = v90->z;
            x = v90->x;
            y = v90->y;
            v98 = v94->x;
            v99 = v94->z;
            v100 = (float)((float)(v90->w * v94->z) + (float)((float)(v94->y * v90->x) + (float)(v90->z * v94->w)));
            v101 = (float)((float)(v94->w * v90->y) + (float)((float)(v90->z * v94->x) + (float)(v94->y * v90->w)));
            v102 = (float)-(float)((float)(v94->y * v90->y)
                                 - (float)((float)(v94->w * v90->w) - (float)(v90->x * v94->x)));
            v117.mat[0].x = -(float)((float)(v90->z * v94->y)
                                   - (float)((float)(v90->y * v94->z)
                                           + (float)((float)(v90->x * v94->w) + (float)(v94->x * v90->w))));
            v117.mat[0].z = -(float)((float)((float)v98 * (float)y) - (float)v100);
            v117.mat[0].y = -(float)((float)((float)x * (float)v99) - (float)v101);
            v117.mat[1].x = -(float)((float)((float)z * (float)v99) - (float)v102);
            idQuat::operator*(
              this: (idQuat *)&v117.mat[2],
              result: (idVec3 *)&this->eventAnimSupport,
              a: (const idVec3 *)&v118);
            v103 = (float)(this->eventAnimSupport.orgOrigin.y + v117.mat[2].y);
            v104 = (float)(this->eventAnimSupport.orgOrigin.z + v117.mat[2].z);
            this->eventAnimSupport.nextOrigin.x = this->eventAnimSupport.orgOrigin.x + v117.mat[2].x;
            this->eventAnimSupport.nextOrigin.y = v103;
            this->eventAnimSupport.nextOrigin.z = v104;
            v105 = idQuat::Inverse(this: &v118, result: (idQuat *)&v117);
            w = v105->w;
            v107 = this->eventAnimSupport.orgRotation.x;
            v108 = v105->x;
            v109 = this->eventAnimSupport.orgRotation.w;
            v110 = (float)(this->eventAnimSupport.orgRotation.y * v105->x);
            v111 = v105->z;
            v112 = this->eventAnimSupport.orgRotation.z;
            v113 = v105->y;
            v114 = (float)((float)(this->eventAnimSupport.orgRotation.w * v105->y)
                         + (float)((float)(this->eventAnimSupport.orgRotation.x * v105->z)
                                 + (float)(this->eventAnimSupport.orgRotation.y * v105->w)));
            v115 = (float)-(float)((float)(this->eventAnimSupport.orgRotation.y * v105->y)
                                 - (float)((float)(this->eventAnimSupport.orgRotation.w * v105->w)
                                         - (float)(this->eventAnimSupport.orgRotation.x * v105->x)));
            this->eventAnimSupport.nextRotation.x = -(float)((float)(this->eventAnimSupport.orgRotation.y * v105->z)
                                                           - (float)((float)(this->eventAnimSupport.orgRotation.z
                                                                           * v105->y)
                                                                   + (float)((float)(this->eventAnimSupport.orgRotation.w
                                                                                   * v105->x)
                                                                           + (float)(this->eventAnimSupport.orgRotation.x
                                                                                   * v105->w))));
            this->eventAnimSupport.nextRotation.y = -(float)((float)((float)v112 * (float)v108) - (float)v114);
            this->eventAnimSupport.nextRotation.z = -(float)((float)((float)v107 * (float)v113)
                                                           - (float)((float)((float)v112 * (float)w)
                                                                   + (float)((float)((float)v109 * (float)v111)
                                                                           + (float)v110)));
            this->eventAnimSupport.nextRotation.w = -(float)((float)((float)v112 * (float)v111) - (float)v115);
            return;
          }
          idEventReceiver::PostEventMS(this: v72, ev: &EV_Remove, time: 0);
          *((_DWORD *)p_value + 2) = 0;
        }
        v73 = (idVehicleOccupant *)gameLocal->SpawnEntityFromDef(
                                     this: gameLocal,
                                     a2: *((_DWORD *)p_value + 39),
                                     a3: -1,
                                     a4: -1,
                                     a5: -1);
        v74 = v73;
        if ( v73 != nullptr )
        {
          v75 = idVehicleOccupant::CastTo(c: v73);
          v76 = v75;
          if ( v75 != nullptr )
          {
            *((_DWORD *)p_value + 2) = v75;
            data = this->seatInfo.list->tagName.data;
            v78 = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
            idVehicleOccupant::EnterVehicle(this: v76, vehicle: this, tagAnimator: v78, tagName: data);
            if ( idAnimatedEntity::GetTreeAnimatorFromPresentable(this: v76) != nullptr )
            {
              v120.animStack = v76->GetAnimStack_2(this: v76);
              idStr::idStr(this: &v120.name, text: "base");
              v120.alpha = 0.0;
              v120.blendOp = BOP_LERP;
              memset(&v120.originBlend, 0, 12);
              v79 = gameLocal->GetGameTimeManager(this: gameLocal);
              idAnimator_Base::Init(this: &this->eventAnimatorLegs, gametimeManager: v79, parms: &v120);
              v80 = idDeclMD6::FindAlias(
                      this: *((idDeclMD6 **)p_value + 38),
                      aliasHandle: (const idHandle<unsigned short,enum invalidAliasHandle_t,65535> *)p_value + 2,
                      includeInherited: true);
              if ( v80 != nullptr )
              {
                v81 = (const idMD6Anim *)idResourceList::FindExisting(
                                           this: &idMD6Anim::resourceList,
                                           name: (char *)v80->animRefs.list->str,
                                           skipStaleCheck: false);
                v82 = v76->GetAnimStack_2;
                if ( (p_value[84] & 0x20) != 0 )
                {
                  v83 = v82(this: v76);
                  LODWORD(v84) = &v116;
                  idAnimator_Channel::CycleAnim(
                    this: &this->eventAnimatorLegs,
                    stack: v83,
                    ah: v81,
                    curTime: GameMs,
                    rateScale: 1.0,
                    leafStarted: v84,
                    a7: nullptr);
                }
                else
                {
                  v85 = v82(this: v76);
                  idAnimator_Channel::PlayAnim(
                    this: &this->eventAnimatorLegs,
                    stack: v85,
                    ah: v81,
                    curTime: GameMs,
                    rateScale: 1.0,
                    blendParms: v86,
                    blendOutDurationMS_: &v116,
                    leafStarted: (idMD6LeafPlay **)0xFFFFFFFF,
                    a9: nullptr);
                }
              }
              idStr::FreeData(this: &v120.name);
            }
          }
          else
          {
            gameLocal->DeleteEntity(this: gameLocal, a2: v74);
          }
        }
        goto LABEL_84;
      }
    }
  }
}


// ========================================================================
// __unwind$518072
// EA  : 0x82D259E8
// RVA : 0x00D259E8
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void _unwind_518072()
{
  int v0; // r12

  idAnimatorParms_EndAdditiveChannels::~idAnimatorParms_EndAdditiveChannels(this: (vaiAction_t::vehicleCam_t *)(v0 - 480 + 192));
}


// ========================================================================
// __unwind$518073
// EA  : 0x82D25A10
// RVA : 0x00D25A10
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void _unwind_518073()
{
  int v0; // r12

  idAnimatorParms_EndAdditiveChannels::~idAnimatorParms_EndAdditiveChannels(this: (vaiAction_t::vehicleCam_t *)(v0 - 480 + 256));
}


// ========================================================================
// ?UpdateEventAnims@idVehicle@@AAAXXZ
// EA  : 0x82D25A38
// RVA : 0x00D25A38
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __fastcall idVehicle::UpdateEventAnims(idVehicle *this)
{
  idTreeAnimator *TreeAnimatorFromPresentable; // r30
  int v3; // r28
  const idAnimStack *v4; // r3
  int currentState; // r4
  int jumpToState; // r28
  unsigned int queuedBlendTime; // r25
  int queuedAnimState; // r11
  idPhysics *Physics; // r3
  float *v10; // r3
  double v11; // fp30
  double v12; // fp29
  double v13; // fp28
  idPhysics *v14; // r3
  idQuat *v15; // r3
  idQuat *v16; // r3
  idQuat *v17; // r3
  double z; // fp8
  double x; // fp6
  double y; // fp1
  double v21; // fp12
  double v22; // fp13
  double v23; // fp11
  double v24; // fp10
  __int64 v25; // r7
  idPhysics *v26; // r3
  idPhysics *v27; // r29
  idPhysics_vtbl *v28; // r30
  idVec3 *v29; // r3
  idVehicleOccupant *OccupantVisual; // r3
  idVehicleOccupant *v31; // r30
  idAnimStack *v32; // r3
  idAnimStack *v33; // r3
  idVehicle::eventAnimEntry_t *v34; // r28
  idQuat *v35; // r3
  double v36; // fp31
  double v37; // fp30
  double v38; // fp29
  double w; // fp28
  double v40; // fp13
  double v41; // fp11
  double v42; // fp8
  double v43; // fp4
  double v44; // fp6
  double v45; // fp2
  double v46; // fp1
  double v47; // fp0
  double v48; // fp12
  idPhysics *v49; // r3
  int v50; // r3
  float v51; // r4
  float v52; // r11
  idPhysics *v53; // r3
  idQuat *v54; // r3
  double v55; // fp30
  double v56; // fp29
  double v57; // fp28
  __int64 v58; // r6
  double v59; // fp30
  idPhysics *v60; // r3
  idPhysics_vtbl *v61; // r7
  float *v62; // r3
  double v63; // fp6
  float v64; // r8
  float v65; // r10
  idQuat *v66; // r3
  double v67; // fp6
  double v68; // fp4
  double v69; // fp5
  double v70; // fp2
  double v71; // fp3
  __int64 v72; // r8
  idPhysics *v73; // r3
  idPhysics *v74; // r3
  idPhysics *v75; // r29
  idPhysics_vtbl *v76; // r30
  idMat3 *v77; // r3
  idQuat v78; // [sp+50h] [-150h] BYREF
  __int64 v79; // [sp+60h] [-140h] BYREF
  float v80; // [sp+68h] [-138h]
  idVec3 v81; // [sp+70h] [-130h] BYREF
  idMat3 v82; // [sp+80h] [-120h] BYREF
  float v83; // [sp+A4h] [-FCh]
  float v84; // [sp+A8h] [-F8h]
  idQuat v85; // [sp+B0h] [-F0h] BYREF
  float v86[4]; // [sp+C0h] [-E0h] BYREF
  idAngles v87; // [sp+D0h] [-D0h] BYREF
  float v88; // [sp+DCh] [-C4h]
  idAngles v89; // [sp+E0h] [-C0h] BYREF
  float v90; // [sp+ECh] [-B4h]
  idQuat v91; // [sp+F0h] [-B0h] BYREF
  idMat3 v92[2]; // [sp+100h] [-A0h] BYREF

  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
  if ( TreeAnimatorFromPresentable != nullptr && this->eventAnimSupport.currentState != -1 )
  {
    v3 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
    v4 = this->GetAnimStack_2(this);
    if ( idAnimator_Channel::IsDone(this: &this->eventAnimator, stack: v4, curTime: v3, clampIgnoreExtraFrame: true) )
    {
      currentState = this->eventAnimSupport.currentState;
      jumpToState = -1;
      queuedBlendTime = -1;
      if ( currentState != -1 )
      {
        jumpToState = this->eventAnimList.list[currentState].jumpToState;
        idVehicle::LeaveAnimEventState(this, iState: currentState);
        queuedAnimState = this->eventAnimSupport.queuedAnimState;
        this->eventAnimSupport.currentState = -1;
        if ( queuedAnimState != -1 )
        {
          queuedBlendTime = this->eventAnimSupport.queuedBlendTime;
          jumpToState = queuedAnimState;
          this->eventAnimSupport.queuedAnimState = -1;
          this->eventAnimSupport.queuedBlendTime = -1;
        }
      }
      this->eventAnimSupport.orgOrigin.x = this->eventAnimSupport.nextOrigin.x;
      this->eventAnimSupport.orgOrigin.y = this->eventAnimSupport.nextOrigin.y;
      this->eventAnimSupport.orgOrigin.z = this->eventAnimSupport.nextOrigin.z;
      this->eventAnimSupport.orgRotation.x = this->eventAnimSupport.nextRotation.x;
      this->eventAnimSupport.orgRotation.y = this->eventAnimSupport.nextRotation.y;
      this->eventAnimSupport.orgRotation.z = this->eventAnimSupport.nextRotation.z;
      this->eventAnimSupport.orgRotation.w = this->eventAnimSupport.nextRotation.w;
      Physics = idEntity::GetPhysics(this);
      v10 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
      v11 = (float)(this->eventAnimSupport.nextOrigin.x - *v10);
      v12 = (float)(this->eventAnimSupport.nextOrigin.y - v10[1]);
      v13 = (float)(this->eventAnimSupport.nextOrigin.z - v10[2]);
      *(_QWORD *)&v78.x = __PAIR64__(
                            "1 - formation cover, such as behind regime shield units",
                            gameLocal->GetGameMsPerFrame(this: gameLocal, a2: GAMETIME_SCALED));
      v86[0] = (float)v11 * (float)((float)960.0 / (float)*(__int64 *)&v78.x);
      v86[1] = (float)v12 * (float)((float)960.0 / (float)*(__int64 *)&v78.x);
      v86[2] = (float)v13 * (float)((float)960.0 / (float)*(__int64 *)&v78.x);
      v14 = idEntity::GetPhysics(this);
      v15 = (idQuat *)v14->GetAxis(this: v14, a2: 0);
      v16 = idMat3::ToQuat(this: v92, result: v15);
      v17 = idQuat::Inverse(this: &v91, result: v16);
      z = this->eventAnimSupport.nextRotation.z;
      x = this->eventAnimSupport.nextRotation.x;
      y = v17->y;
      v21 = v17->z;
      v22 = (float)-(float)((float)(this->eventAnimSupport.nextRotation.y * v17->y)
                          - (float)((float)(this->eventAnimSupport.nextRotation.w * v17->w)
                                  - (float)(this->eventAnimSupport.nextRotation.x * v17->x)));
      v23 = (float)((float)(this->eventAnimSupport.nextRotation.y * v17->w)
                  + (float)((float)(this->eventAnimSupport.nextRotation.z * v17->x)
                          + (float)(this->eventAnimSupport.nextRotation.w * v17->y)));
      v24 = (float)((float)(this->eventAnimSupport.nextRotation.x * v17->w)
                  + (float)((float)(this->eventAnimSupport.nextRotation.y * v17->z)
                          + (float)(this->eventAnimSupport.nextRotation.w * v17->x)));
      v89.roll = -(float)((float)(this->eventAnimSupport.nextRotation.y * v17->x)
                        - (float)((float)(this->eventAnimSupport.nextRotation.x * v17->y)
                                + (float)((float)(this->eventAnimSupport.nextRotation.w * v17->z)
                                        + (float)(this->eventAnimSupport.nextRotation.z * v17->w))));
      v90 = -(float)((float)((float)z * (float)v21) - (float)v22);
      v89.yaw = -(float)((float)((float)x * (float)v21) - (float)v23);
      v89.pitch = -(float)((float)((float)z * (float)y) - (float)v24);
      idQuat::ToAngles(this: (idQuat *)&v82.mat[1].y, result: &v89);
      LODWORD(v25) = gameLocal->GetGameMsPerFrame(this: gameLocal, a2: GAMETIME_SCALED);
      *(_QWORD *)&v78.x = v25;
      v82.mat[1].y = v82.mat[1].y * (float)((float)960.0 / (float)v25);
      v82.mat[1].z = v82.mat[1].z * (float)((float)960.0 / (float)v25);
      v82.mat[2].x = v82.mat[2].x * (float)((float)960.0 / (float)v25);
      v26 = idEntity::GetPhysics(this);
      v26->SetLinearVelocity(this: v26, a2: (const idVec3 *)v86, a3: 0);
      v27 = idEntity::GetPhysics(this);
      v28 = v27->__vftable;
      v29 = idAngles::ToAngularVelocity(this: (idAngles *)&v78, result: (idVec3 *)&v82.mat[1].y);
      v28->SetAngularVelocity(this: v27, a2: v29, a3: 0);
      OccupantVisual = idVehicle::GetOccupantVisual(this, index: 0);
      v31 = OccupantVisual;
      if ( OccupantVisual != nullptr )
      {
        v32 = OccupantVisual->GetAnimStack_2(this: OccupantVisual);
        idAnimator_Base::Shutdown(this: &this->eventAnimatorHands, stack: v32);
        v33 = v31->GetAnimStack_2(this: v31);
        idAnimator_Base::Shutdown(this: &this->eventAnimatorLegs, stack: v33);
      }
      if ( jumpToState == -1 )
        this->eventAnimSupport.currentState = -1;
      else
        idVehicle::EnterAnimEventState(this, iState: jumpToState, blendTime: queuedBlendTime);
    }
    else if ( this->eventAnimSupport.animUpdatedFrame > this->eventAnimSupport.animStartFrame )
    {
      v34 = &this->eventAnimList.list[this->eventAnimSupport.currentState];
      idTreeAnimator::GetTotalOriginTransform(this: TreeAnimatorFromPresentable, rot: (idQuat *)&v82, trans: &v81);
      v35 = idQuat::Inverse(this: &v91, result: (idQuat *)&v82);
      v36 = v35->x;
      v82.mat[0].x = v35->x;
      v37 = v35->y;
      v82.mat[0].y = v35->y;
      v38 = v35->z;
      v82.mat[0].z = v35->z;
      w = v35->w;
      idQuat::operator*(this: &v78, result: (idVec3 *)&this->eventAnimSupport, a: &v81);
      v40 = this->eventAnimSupport.orgRotation.z;
      v41 = this->eventAnimSupport.orgRotation.x;
      v42 = this->eventAnimSupport.orgRotation.y;
      v43 = this->eventAnimSupport.orgOrigin.z;
      v44 = (float)((float)(this->eventAnimSupport.orgRotation.y * (float)v36)
                  + (float)((float)(this->eventAnimSupport.orgRotation.z * (float)w)
                          + (float)(this->eventAnimSupport.orgRotation.w * (float)v38)));
      v45 = (float)((float)(this->eventAnimSupport.orgRotation.w * (float)v36)
                  + (float)((float)(this->eventAnimSupport.orgRotation.x * (float)w)
                          + (float)(this->eventAnimSupport.orgRotation.z * (float)v37)));
      v46 = (float)((float)(this->eventAnimSupport.orgRotation.w * (float)v37)
                  + (float)((float)(this->eventAnimSupport.orgRotation.y * (float)w)
                          + (float)(this->eventAnimSupport.orgRotation.x * (float)v38)));
      v47 = (float)-(float)((float)(this->eventAnimSupport.orgRotation.y * (float)v37)
                          - (float)((float)(this->eventAnimSupport.orgRotation.w * (float)w)
                                  - (float)(this->eventAnimSupport.orgRotation.x * (float)v36)));
      v48 = (float)(this->eventAnimSupport.orgOrigin.y + v78.y);
      v81.x = this->eventAnimSupport.orgOrigin.x + v78.x;
      v81.y = v48;
      v81.z = (float)v43 + v78.z;
      v82.mat[0].z = -(float)((float)((float)v41 * (float)v37) - (float)v44);
      v82.mat[0].x = -(float)((float)((float)v42 * (float)v38) - (float)v45);
      v82.mat[0].y = -(float)((float)((float)v40 * (float)v36) - (float)v46);
      v82.mat[1].x = -(float)((float)((float)v40 * (float)v38) - (float)v47);
      v49 = idEntity::GetPhysics(this);
      v50 = (int)v49->GetOrigin(this: v49, a2: 0);
      v51 = *(float *)(v50 + 4);
      v52 = *(float *)(v50 + 8);
      v78.x = *(float *)v50;
      v78.y = v51;
      v78.z = v52;
      v53 = idEntity::GetPhysics(this);
      v54 = (idQuat *)v53->GetAxis(this: v53, a2: 0);
      idMat3::ToQuat(this: v92, result: v54);
      v55 = (float)(v81.x - v78.x);
      v56 = (float)(v81.y - v78.y);
      v57 = (float)(v81.z - v78.z);
      *(_QWORD *)&v78.x = __PAIR64__(
                            "1 - formation cover, such as behind regime shield units",
                            gameLocal->GetGameMsPerFrame(this: gameLocal, a2: GAMETIME_SCALED));
      v85.x = v82.mat[0].x;
      v85.y = v82.mat[0].y;
      v85.z = v82.mat[0].z;
      v85.w = v82.mat[1].x;
      *(float *)&v79 = (float)v55 * (float)((float)960.0 / (float)*(__int64 *)&v78.x);
      *((float *)&v79 + 1) = (float)v56 * (float)((float)960.0 / (float)*(__int64 *)&v78.x);
      v80 = (float)v57 * (float)((float)960.0 / (float)*(__int64 *)&v78.x);
      if ( idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) < this->eventAnimList.list[this->eventAnimSupport.currentState].blendTime + this->eventAnimSupport.animStartFrame )
      {
        LODWORD(v58) = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED)
                     - this->eventAnimSupport.animStartFrame;
        HIDWORD(v58) = this->eventAnimList.list[this->eventAnimSupport.currentState].blendTime;
        *(_QWORD *)&v78.x = __PAIR64__((unsigned int)this, HIDWORD(v58));
        v59 = (float)((float)v58 / (float)__SPAIR64__((unsigned int)this, HIDWORD(v58)));
        v60 = idEntity::GetPhysics(this);
        v61 = v60->__vftable;
        *(_QWORD *)&v78.x = v79;
        v78.z = v80;
        v62 = (float *)v61->GetLinearVelocity(this: (idPhysics *)&v91, result: (idVec3 *)v60, a3: 0);
        v63 = v78.z;
        v64 = *v62;
        v65 = v62[1];
        v78.z = v62[2];
        *((float *)&v79 + 1) = (float)((float)(v78.y - v65) * (float)v59) + v65;
        v78.y = v65;
        *(float *)&v79 = (float)((float)(v78.x - v64) * (float)v59) + v64;
        v78.x = v64;
        v80 = (float)((float)((float)v63 - v78.z) * (float)v59) + v78.z;
        idQuat::Slerp(this: &v85, from: (const idQuat *)v92, to: (const idQuat *)&v82, t: v59);
      }
      v66 = idQuat::Inverse(this: &v91, result: (idQuat *)v92);
      v67 = v66->z;
      v68 = v66->y;
      v69 = (float)-(float)((float)(v85.y * v66->y) - (float)((float)(v85.w * v66->w) - (float)(v85.x * v66->x)));
      v70 = (float)((float)(v85.x * v66->w) + (float)((float)(v85.y * v66->z) + (float)(v85.w * v66->x)));
      v71 = (float)((float)(v85.y * v66->w) + (float)((float)(v85.w * v66->y) + (float)(v85.z * v66->x)));
      v87.roll = -(float)((float)(v85.y * v66->x)
                        - (float)((float)(v85.x * v66->y) + (float)((float)(v85.w * v66->z) + (float)(v85.z * v66->w))));
      v88 = -(float)((float)(v85.z * (float)v67) - (float)v69);
      v87.pitch = -(float)((float)(v85.z * (float)v68) - (float)v70);
      v87.yaw = -(float)((float)(v85.x * (float)v67) - (float)v71);
      idQuat::ToAngles(this: (idQuat *)&v82.mat[2].z, result: &v87);
      LODWORD(v72) = gameLocal->GetGameMsPerFrame(this: gameLocal, a2: GAMETIME_SCALED);
      *(_QWORD *)&v78.x = v72;
      v82.mat[2].z = v82.mat[2].z * (float)((float)960.0 / (float)v72);
      v83 = v83 * (float)((float)960.0 / (float)v72);
      v84 = v84 * (float)((float)960.0 / (float)v72);
      if ( (*((_BYTE *)v34 + 168) & 0x40) != 0 )
      {
        v73 = idEntity::GetPhysics(this);
        v73->SetLinearVelocity(this: v73, a2: (const idVec3 *)&v79, a3: 0);
      }
      else
      {
        v74 = idEntity::GetPhysics(this);
        v74->SetOrigin(this: v74, a2: &v81, a3: -1);
      }
      v75 = idEntity::GetPhysics(this);
      v76 = v75->__vftable;
      v77 = idQuat::ToMat3(this: (idQuat *)&v92[0].mat[1].y, result: &v82);
      v76->SetAxis(this: v75, a2: v77, a3: -1);
    }
    this->eventAnimSupport.animUpdatedFrame = idAccolade::Count(this: &clientGame->gameTimeManager);
  }
}


// ========================================================================
// ?GetUsableState@idVehicle@@UBA?AW4usableState_t@@PBVidEntity@@ABVidFocusTrace@@@Z
// EA  : 0x82D26630
// RVA : 0x00D26630
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

int __fastcall idVehicle::GetUsableState(idVehicle *this, idPlayer *activator, const idFocusTrace *ft)
{
  if ( !this->isUsable )
    return 1;
  if ( idVehicle::CanPlayerEnter(this, wantSeat: 0, activator) )
    return 10;
  return !idVehicle::CanPlayerEnter(this, wantSeat: 1, activator) ? 0 : 0xB;
}


// ========================================================================
// ?VehicleAiIsOccupant@idVehicle@@QBAPAVidVehicleAI@@XZ
// EA  : 0x82D266C0
// RVA : 0x00D266C0
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

idVehicleAI *__fastcall idVehicle::VehicleAiIsOccupant(idVehicle *this)
{
  int v2; // r26
  int i; // r29
  idPresentable *presentable; // r3
  int v5; // r3
  idPresentable *v6; // r3
  int v7; // r3
  int v8; // r30
  int v9; // r11
  int v10; // r31
  idPresentable *v11; // r3
  int v12; // r3
  int v13; // r30
  int v14; // r11
  int v15; // r31
  idPresentable *v16; // r3
  int v17; // r11
  int v18; // r31
  idPresentable *PresentableByIndex; // r3
  idVehicleAI *entity; // r3
  idVehicleAI *result; // r3

  v2 = 0;
  for ( i = 0; ; i += 16 )
  {
    presentable = this->presentable;
    v5 = presentable != nullptr ? (int)presentable->GetVehicleInterface(this: presentable) : 0;
    if ( v2 >= *(_DWORD *)(v5 + 16476) )
      break;
    v6 = this->presentable;
    if ( v6 != nullptr )
      v7 = (int)v6->GetVehicleInterface(this: v6);
    else
      v7 = 0;
    v8 = *(_DWORD *)(v7 + 16472);
    v9 = *(_DWORD *)(v8 + i);
    v10 = v9 & 0x3FFF;
    if ( v9 != 0
      && idClientGame::IsPresentableIndexValid(this: clientGame, index: v9 & 0x3FFF)
      && idClientGame::GetPresentableByIndex(this: clientGame, index: v10)->spawnId == *(_DWORD *)(v8 + i) )
    {
      v11 = this->presentable;
      v12 = v11 != nullptr ? (int)v11->GetVehicleInterface(this: v11) : 0;
      v13 = *(_DWORD *)(v12 + 16472);
      v14 = *(_DWORD *)(v13 + i);
      v15 = v14 & 0x3FFF;
      if ( v14 != 0
        && idClientGame::IsPresentableIndexValid(this: clientGame, index: v14 & 0x3FFF)
        && (v16 = idClientGame::GetPresentableByIndex(this: clientGame, index: v15),
            v17 = *(_DWORD *)(v13 + i),
            v16->spawnId == v17) )
      {
        v18 = *(_DWORD *)(v13 + i) & 0x3FFF;
        if ( v17 == 0
          || !idClientGame::IsPresentableIndexValid(this: clientGame, index: *(_DWORD *)(v13 + i) & 0x3FFF)
          || (PresentableByIndex = idClientGame::GetPresentableByIndex(this: clientGame, index: v18))->spawnId != *(_DWORD *)(v13 + i) )
        {
          PresentableByIndex = nullptr;
        }
        entity = (idVehicleAI *)PresentableByIndex->entity;
      }
      else
      {
        entity = nullptr;
      }
      result = idVehicleAI::CastTo(c: entity);
      if ( result != nullptr )
        return result;
    }
    ++v2;
  }
  return nullptr;
}


// ========================================================================
// ?GetOccupantForEntity@idVehicle@@QBAPAVidVehicleOccupant@@PBVidEntity@@@Z
// EA  : 0x82D26858
// RVA : 0x00D26858
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

idVehicleOccupant *__fastcall idVehicle::GetOccupantForEntity(idVehicle *this, const idEntity *entity)
{
  int v4; // r27
  int i; // r29
  idPresentable *presentable; // r3
  int v7; // r3
  idPresentable *v8; // r3
  int v9; // r3
  int v10; // r30
  int v11; // r11
  int v12; // r31
  idPresentable *v13; // r3
  int v14; // r11
  int v15; // r31
  idPresentable *PresentableByIndex; // r3
  const idEntity *v17; // r11
  idPresentable *v18; // r3
  int v19; // r3

  v4 = 0;
  for ( i = 0; ; i += 16 )
  {
    presentable = this->presentable;
    if ( presentable != nullptr )
      v7 = (int)presentable->GetVehicleInterface(this: presentable);
    else
      v7 = 0;
    if ( v4 >= *(_DWORD *)(v7 + 16476) )
      return nullptr;
    v8 = this->presentable;
    v9 = v8 != nullptr ? (int)v8->GetVehicleInterface(this: v8) : 0;
    v10 = *(_DWORD *)(v9 + 16472);
    v11 = *(_DWORD *)(v10 + i);
    v12 = v11 & 0x3FFF;
    if ( v11 != 0
      && idClientGame::IsPresentableIndexValid(this: clientGame, index: v11 & 0x3FFF)
      && (v13 = idClientGame::GetPresentableByIndex(this: clientGame, index: v12),
          v14 = *(_DWORD *)(v10 + i),
          v13->spawnId == v14) )
    {
      v15 = *(_DWORD *)(v10 + i) & 0x3FFF;
      if ( v14 == 0
        || !idClientGame::IsPresentableIndexValid(this: clientGame, index: *(_DWORD *)(v10 + i) & 0x3FFF)
        || (PresentableByIndex = idClientGame::GetPresentableByIndex(this: clientGame, index: v15))->spawnId != *(_DWORD *)(v10 + i) )
      {
        PresentableByIndex = nullptr;
      }
      v17 = PresentableByIndex->entity;
    }
    else
    {
      v17 = nullptr;
    }
    if ( v17 == entity )
      break;
    ++v4;
  }
  v18 = this->presentable;
  if ( v18 == nullptr )
    return vehicleOccupant_t::GetVisualAsEntity(this: (vehicleOccupant_t *)(MEMORY[0x4058] + 16 * v4));
  v19 = (int)v18->GetVehicleInterface(this: v18);
  return vehicleOccupant_t::GetVisualAsEntity(this: (vehicleOccupant_t *)(*(_DWORD *)(v19 + 16472) + 16 * v4));
}


// ========================================================================
// ?TransferPlayerQuickItemsToVehicle@idVehicle@@QAAXPAVidPlayer@@@Z
// EA  : 0x82D269E0
// RVA : 0x00D269E0
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __fastcall idVehicle::TransferPlayerQuickItemsToVehicle(idVehicle *this, idPlayer *player)
{
  idPresentable *presentable; // r3
  int v5; // r3
  int v6; // r30
  bfx::Planner3D *v7; // r3
  idInventoryCollection *v8; // r3
  bfx::Planner3D *v9; // r3
  int num; // r30
  encounterGroupRole_t *list; // r24
  idInventoryItem **v12; // r27
  idPresentable *v13; // r28
  idInventoryItem *v14; // r29
  idInventoryCollection *v15; // r3
  int v16; // r29
  int v17; // r30
  bfx::Planner3D *v18; // r3
  idInventoryCollection *v19; // r3
  bfx::Planner3D *v20; // r3
  idInventoryItem **v21; // r28
  idPresentable *v22; // r27
  idPresentable *v23; // r30
  idInventoryCollection *v24; // r3
  idPresentable *v25; // r3
  int v26; // r3
  idVehicleQuickItem *v27[4]; // [sp+50h] [-80h] BYREF
  idList<enum encounterGroupRole_t,5> v28[7]; // [sp+60h] [-70h] BYREF

  if ( vehicle_transferQuickItems.valueInteger != 0 )
  {
    presentable = player->presentable;
    if ( presentable != nullptr )
      v5 = (int)presentable->GetPlayerInterface_2(this: presentable);
    else
      v5 = 0;
    idPlayerHud::SetIgnorePickupUpdate(this: (idPlayerHud *)(v5 + 35096), ignore: true);
    memset(v28, 0, 14);
    v28[0].memTag = 5;
    v28[0].listStatic = 0;
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)v28);
    v6 = 0;
    v7 = (bfx::Planner3D *)this->GetInventory_2(this);
    if ( (int)idScriptObject::GetTypeDef(this: v7) > 0 )
    {
      do
      {
        v8 = this->GetInventory_2(this);
        v27[0] = (idVehicleQuickItem *)idInventoryCollection::GetInventoryItem(this: v8, index: v6);
        if ( idVehicleQuickItem::CastTo(c: v27[0]) != nullptr )
          idList<idAnimWebBlendTree *,5>::Append(this: v28, obj: (encounterGroupRole_t *)v27);
        ++v6;
        v9 = (bfx::Planner3D *)this->GetInventory_2(this);
      }
      while ( v6 < (int)idScriptObject::GetTypeDef(this: v9) );
    }
    num = v28[0].num;
    list = v28[0].list;
    if ( v28[0].num > 0 )
    {
      v12 = (idInventoryItem **)(v28[0].list - 1);
      do
      {
        v13 = this->presentable;
        if ( v13 == nullptr )
        {
          idEntity::InitPresentableInternal(this);
          v13 = this->presentable;
        }
        v14 = *++v12;
        v15 = this->GetInventory_2(this);
        idInventoryCollection::RemoveItemFromInventory(this: v15, owner: v13, item: v14);
        --num;
      }
      while ( num != 0 );
    }
    if ( v28[0].listStatic == 0 || v28[0].listStatic == 2 )
    {
      if ( list != nullptr )
        idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
      list = nullptr;
      v28[0].size = 0;
      v28[0].list = nullptr;
    }
    v28[0].num = 0;
    v16 = 0;
    v17 = 0;
    v18 = (bfx::Planner3D *)player->GetInventory_2(this: player);
    if ( (int)idScriptObject::GetTypeDef(this: v18) > 0 )
    {
      do
      {
        v19 = player->GetInventory_2(this: player);
        v27[0] = (idVehicleQuickItem *)idInventoryCollection::GetInventoryItem(this: v19, index: v17);
        if ( idVehicleQuickItem::CastTo(c: v27[0]) != nullptr )
          idList<idAnimWebBlendTree *,5>::Append(this: v28, obj: (encounterGroupRole_t *)v27);
        ++v17;
        v20 = (bfx::Planner3D *)player->GetInventory_2(this: player);
      }
      while ( v17 < (int)idScriptObject::GetTypeDef(this: v20) );
      v16 = v28[0].num;
      list = v28[0].list;
    }
    if ( v16 > 0 )
    {
      v21 = (idInventoryItem **)list;
      do
      {
        if ( this->presentable == nullptr )
          idEntity::InitPresentableInternal(this);
        v22 = this->presentable;
        v23 = player->presentable;
        if ( v23 == nullptr )
        {
          idEntity::InitPresentableInternal(this: player);
          v23 = player->presentable;
        }
        v24 = player->GetInventory_2(this: player);
        idInventoryCollection::TransferItem(
          this: v24,
          owner: v23,
          to: v22,
          item: v21,
          deleteOwnerItem: true,
          canIntro: false);
        --v16;
        ++v21;
      }
      while ( v16 != 0 );
    }
    v25 = player->presentable;
    if ( v25 != nullptr )
      v26 = (int)v25->GetPlayerInterface_2(this: v25);
    else
      v26 = 0;
    idPlayerHud::SetIgnorePickupUpdate(this: (idPlayerHud *)(v26 + 35096), ignore: false);
    if ( (v28[0].listStatic == 0 || v28[0].listStatic == 2) && list != nullptr )
      idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
  }
}


// ========================================================================
// __unwind$521907
// EA  : 0x82D26CF4
// RVA : 0x00D26CF4
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void _unwind_521907()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 208 + 96));
}


// ========================================================================
// ?TransferVehicleQuickItemsToPlayer@idVehicle@@QAAXPAVidPlayer@@@Z
// EA  : 0x82D26D28
// RVA : 0x00D26D28
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __fastcall idVehicle::TransferVehicleQuickItemsToPlayer(idVehicle *this, idPlayer *player)
{
  idPresentable *presentable; // r3
  int v5; // r3
  int v6; // r29
  bfx::Planner3D *v7; // r3
  idInventoryCollection *v8; // r3
  idVehicleQuickItem *v9; // r3
  bfx::Planner3D *v10; // r3
  int num; // r28
  encounterGroupRole_t *list; // r23
  idInventoryItem **v13; // r27
  idPresentable *v14; // r26
  idPresentable *v15; // r29
  idInventoryCollection *v16; // r3
  idPresentable *v17; // r3
  int v18; // r3
  idVehicleQuickItem *InventoryItem; // [sp+50h] [-80h] BYREF
  idList<enum encounterGroupRole_t,5> v20[7]; // [sp+60h] [-70h] BYREF

  if ( vehicle_transferQuickItems.valueInteger != 0 )
  {
    presentable = player->presentable;
    if ( presentable != nullptr )
      v5 = (int)presentable->GetPlayerInterface_2(this: presentable);
    else
      v5 = 0;
    idPlayerHud::SetIgnorePickupUpdate(this: (idPlayerHud *)(v5 + 35096), ignore: true);
    memset(v20, 0, 14);
    v20[0].memTag = 5;
    v20[0].listStatic = 0;
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)v20);
    v6 = 0;
    v7 = (bfx::Planner3D *)this->GetInventory_2(this);
    if ( (int)idScriptObject::GetTypeDef(this: v7) > 0 )
    {
      do
      {
        v8 = this->GetInventory_2(this);
        InventoryItem = (idVehicleQuickItem *)idInventoryCollection::GetInventoryItem(this: v8, index: v6);
        v9 = idVehicleQuickItem::CastTo(c: InventoryItem);
        if ( v9 != nullptr )
        {
          idVehicle_Jump::VehicleDied(this: (idHealthT<enum aiHealthComponent_t,2,0> *)v9);
          idList<idAnimWebBlendTree *,5>::Append(this: v20, obj: (encounterGroupRole_t *)&InventoryItem);
        }
        ++v6;
        v10 = (bfx::Planner3D *)this->GetInventory_2(this);
      }
      while ( v6 < (int)idScriptObject::GetTypeDef(this: v10) );
    }
    num = v20[0].num;
    list = v20[0].list;
    if ( v20[0].num > 0 )
    {
      v13 = (idInventoryItem **)v20[0].list;
      do
      {
        if ( player->presentable == nullptr )
          idEntity::InitPresentableInternal(this: player);
        v14 = player->presentable;
        v15 = this->presentable;
        if ( v15 == nullptr )
        {
          idEntity::InitPresentableInternal(this);
          v15 = this->presentable;
        }
        v16 = this->GetInventory_2(this);
        idInventoryCollection::TransferItem(
          this: v16,
          owner: v15,
          to: v14,
          item: v13,
          deleteOwnerItem: true,
          canIntro: false);
        --num;
        ++v13;
      }
      while ( num != 0 );
    }
    v17 = player->presentable;
    if ( v17 != nullptr )
      v18 = (int)v17->GetPlayerInterface_2(this: v17);
    else
      v18 = 0;
    idPlayerHud::SetIgnorePickupUpdate(this: (idPlayerHud *)(v18 + 35096), ignore: false);
    if ( (v20[0].listStatic == 0 || v20[0].listStatic == 2) && list != nullptr )
      idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
  }
}


// ========================================================================
// __unwind$522102
// EA  : 0x82D26F24
// RVA : 0x00D26F24
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void _unwind_522102()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 208 + 96));
}


// ========================================================================
// ?IsAnOccupant@idVehicle@@QAA_NPAVidEntity@@@Z
// EA  : 0x82D26F50
// RVA : 0x00D26F50
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

int __fastcall idVehicle::IsAnOccupant(idVehicle *this, idEntity *entity)
{
  int v4; // r27
  int i; // r29
  idPresentable *presentable; // r3
  int v7; // r3
  idPresentable *v8; // r3
  int v9; // r3
  int v10; // r30
  int v11; // r11
  int v12; // r31
  idPresentable *v13; // r3
  int v14; // r11
  int v15; // r31
  idPresentable *PresentableByIndex; // r3
  idEntity *v17; // r11

  v4 = 0;
  for ( i = 0; ; i += 16 )
  {
    presentable = this->presentable;
    v7 = presentable != nullptr ? (int)presentable->GetVehicleInterface(this: presentable) : 0;
    if ( v4 >= *(_DWORD *)(v7 + 16476) )
      break;
    v8 = this->presentable;
    if ( v8 != nullptr )
      v9 = (int)v8->GetVehicleInterface(this: v8);
    else
      v9 = 0;
    v10 = *(_DWORD *)(v9 + 16472);
    v11 = *(_DWORD *)(v10 + i);
    v12 = v11 & 0x3FFF;
    if ( v11 != 0
      && idClientGame::IsPresentableIndexValid(this: clientGame, index: v11 & 0x3FFF)
      && (v13 = idClientGame::GetPresentableByIndex(this: clientGame, index: v12),
          v14 = *(_DWORD *)(v10 + i),
          v13->spawnId == v14) )
    {
      v15 = *(_DWORD *)(v10 + i) & 0x3FFF;
      if ( v14 == 0
        || !idClientGame::IsPresentableIndexValid(this: clientGame, index: *(_DWORD *)(v10 + i) & 0x3FFF)
        || (PresentableByIndex = idClientGame::GetPresentableByIndex(this: clientGame, index: v15))->spawnId != *(_DWORD *)(v10 + i) )
      {
        PresentableByIndex = nullptr;
      }
      v17 = PresentableByIndex->entity;
    }
    else
    {
      v17 = nullptr;
    }
    if ( v17 == entity )
      return 1;
    ++v4;
  }
  return 0;
}


// ========================================================================
// ?GetOccupantAsEntity@idVehicle@@QBAPAVidEntity@@H@Z
// EA  : 0x82D27088
// RVA : 0x00D27088
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

idEntity *__fastcall idVehicle::GetOccupantAsEntity(idVehicle *this, int index)
{
  idPresentable *presentable; // r3
  int v4; // r3
  idPresentablePtr<idPresentable> *v5; // r31

  presentable = this->presentable;
  if ( presentable != nullptr )
    v4 = (int)presentable->GetVehicleInterface(this: presentable);
  else
    v4 = 0;
  v5 = (idPresentablePtr<idPresentable> *)(*(_DWORD *)(v4 + 16472) + 16 * index);
  if ( idPresentablePtr<idPresentable>::IsValid(this: (idPresentablePtr<idPresentableActor> *)v5) )
    return idPresentablePtr<idPresentableProjectile>::operator->(this: v5)->entity;
  else
    return nullptr;
}


// ========================================================================
// ?GetOccupantNum@idVehicle@@QAAHPAVidEntity@@@Z
// EA  : 0x82D27118
// RVA : 0x00D27118
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

int __fastcall idVehicle::GetOccupantNum(idVehicle *this, idEntity *entity)
{
  int v4; // r27
  int i; // r29
  idPresentable *presentable; // r3
  int v7; // r3
  idPresentable *v8; // r3
  int v9; // r3
  int v10; // r30
  int v11; // r11
  int v12; // r31
  idPresentable *v13; // r3
  int v14; // r11
  int v15; // r31
  idPresentable *PresentableByIndex; // r3
  idEntity *v17; // r11

  v4 = 0;
  for ( i = 0; ; i += 16 )
  {
    presentable = this->presentable;
    v7 = presentable != nullptr ? (int)presentable->GetVehicleInterface(this: presentable) : 0;
    if ( v4 >= *(_DWORD *)(v7 + 16476) )
      break;
    v8 = this->presentable;
    if ( v8 != nullptr )
      v9 = (int)v8->GetVehicleInterface(this: v8);
    else
      v9 = 0;
    v10 = *(_DWORD *)(v9 + 16472);
    v11 = *(_DWORD *)(v10 + i);
    v12 = v11 & 0x3FFF;
    if ( v11 != 0
      && idClientGame::IsPresentableIndexValid(this: clientGame, index: v11 & 0x3FFF)
      && (v13 = idClientGame::GetPresentableByIndex(this: clientGame, index: v12),
          v14 = *(_DWORD *)(v10 + i),
          v13->spawnId == v14) )
    {
      v15 = *(_DWORD *)(v10 + i) & 0x3FFF;
      if ( v14 == 0
        || !idClientGame::IsPresentableIndexValid(this: clientGame, index: *(_DWORD *)(v10 + i) & 0x3FFF)
        || (PresentableByIndex = idClientGame::GetPresentableByIndex(this: clientGame, index: v15))->spawnId != *(_DWORD *)(v10 + i) )
      {
        PresentableByIndex = nullptr;
      }
      v17 = PresentableByIndex->entity;
    }
    else
    {
      v17 = nullptr;
    }
    if ( v17 == entity )
      return v4;
    ++v4;
  }
  return -1;
}


// ========================================================================
// ?Think@idVehicle@@UAAXXZ
// EA  : 0x82D27250
// RVA : 0x00D27250
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idVehicle::Think(
        idVehicle *this,
        int a2,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        idVehicle *a12)
{
  idVehicle *v13; // r17
  int i; // r31
  idPresentable *presentable; // r3
  int v16; // r3
  idPlayer *OccupantAsEntity; // r3
  idPlayer *v18; // r3
  idPresentable *v19; // r3
  int v20; // r3
  idPresentable *v21; // r3
  int v22; // r3
  idPresentable *v23; // r11
  int v24; // r31
  int v25; // r3
  idPresentable *v26; // r3
  int v27; // r3
  idPresentable *v28; // r3
  idPresentableVehicle *v29; // r3
  int v30; // r3
  idPresentable *v31; // r3
  idPresentableVehicle *v32; // r3
  idPresentablePlayer *v33; // r3
  idPlayer *entity; // r4
  idClientGame **v35; // r23
  const idDeclVehicleDecalDamage *vehicleDecalDamage; // r11
  idList<idDeclVehicleDecalDamage::vehicleDecals_t,5> *p_vehicleDecals; // r29
  int v38; // r31
  int v39; // r30
  idPhysics *Physics; // r27
  idPhysics *v41; // r3
  int v42; // r26
  idPhysics *v43; // r3
  float *p_x; // r11
  double v45; // fp4
  double v46; // fp12
  double v47; // fp11
  double v48; // fp2
  double v49; // fp9
  double v50; // fp7
  double v51; // fp8
  double v52; // fp13
  double v53; // fp3
  idRenderWorld *renderWorld; // r25
  idRenderWorld_vtbl *v55; // r27
  const idMat3 *(__fastcall *GetAxis)(idPhysics *, int); // ctr
  int v57; // r3
  idTreeAnimator *TreeAnimatorFromPresentable; // r31
  long double v59; // fp2
  idPresentable *v60; // r3
  int v61; // r3
  double v62; // fp31
  long double v63; // fp2
  idPhysics *v64; // r3
  int v65; // r3
  unsigned __int8 *p_flags; // r10
  _DWORD *v67; // r11
  int j; // ctr
  const idDeclMD6 *decl; // r11
  int num; // r10
  idCollisionModelManager **z_low; // r14
  float v72; // r8
  idPropsCollection *v73; // r31
  float v74; // r15
  idTreeAnimator *v75; // r30
  float v76; // r18
  unsigned __int64 v77; // r26
  idVehicleWindow::window_t *v81; // r28
  _DWORD *p_z; // r10
  float v83; // r4
  char *v84; // r9
  float v85; // r3
  int v86; // ctr
  idDeclVehicleWindowKit::windowDef_t *list; // r11
  idDeclVehicleWindowKit::windowDef_t *v88; // r27
  unsigned __int64 index; // r11
  __int64 v90; // r8
  __int64 v91; // r11
  char v92; // r11
  bool v93; // zf
  unsigned __int64 v94; // r11
  idClientGame *v95; // r9
  const tagData_t *Tag; // r3
  idRenderModelParms *Origin; // r3
  float *Axis; // r3
  int v99; // r11
  double x; // fp31
  double v101; // fp30
  int lastDecalIndex; // r9
  int v103; // r10
  double v104; // fp29
  double y; // fp28
  int v106; // r11
  double v107; // fp27
  double v108; // fp26
  double z; // fp25
  double v110; // fp24
  double v111; // fp23
  idClientGame *v112; // r11
  unsigned int v113; // r5
  int v114; // r3
  float v115; // r5
  float v116; // r7
  int v117; // r31
  idGameTimeManager *p_gameTimeManager; // r3
  const idMaterial *v119; // r10
  int GameMs; // r3
  int v121; // r2 OVERLAPPED
  int v122; // r7
  int v123; // r6
  double v124; // fp7
  double v125; // fp5
  float v126; // r10
  double v127; // fp13
  unsigned int v128; // r6
  int v129; // r3
  idRenderModel *normalModel; // r31
  idEntity *Driver; // r31
  const idDeclDamage *def; // r29
  idEntity_vtbl *v133; // r25
  double scale; // fp31
  idEntity *v135; // r3
  idRenderModel *brokenModel; // r24
  char v137; // r31
  const tagData_t *v139; // r3
  idRenderModelParms *v140; // r3
  float *v141; // r3
  const idMaterial *GameMsPerFrame; // r27
  int v143; // r26
  int v144; // r29
  idVehicleWindow::decal_t *v145; // r31
  double v146; // fp1
  double v147; // fp31
  double v148; // fp0
  double v149; // fp13
  double v150; // fp7
  double v151; // fp12
  double v152; // fp31
  double v153; // fp30
  double v154; // fp29
  const idMat3 *v155; // r30
  idMat3 *v156; // r3
  double v164; // fp4
  float *v167; // r10
  int v171; // ctr
  double v172; // fp0
  double v175; // fp12
  double v176; // fp11
  double v177; // fp10
  double v178; // fp9
  double v179; // fp8
  double v180; // fp7
  double v189; // fp3
  double v190; // fp4
  double v191; // fp2
  double v192; // fp1
  double v193; // fp6
  double v194; // fp13
  const idMaterial *material; // r30
  const idMaterial *fadeInTime; // r18
  const idMaterial *startTime; // r31
  idRenderModelEffects *MergeBranch; // r3
  int v199; // r7
  int v201; // [sp+8h] [-488h]
  int v202; // [sp+Ch] [-484h]
  int v203; // [sp+10h] [-480h]
  int v204; // [sp+14h] [-47Ch]
  int v205; // [sp+18h] [-478h]
  int v206; // [sp+1Ch] [-474h]
  int v207; // [sp+20h] [-470h]
  int v208; // [sp+24h] [-46Ch]
  int v209; // [sp+28h] [-468h]
  int v210; // [sp+2Ch] [-464h]
  int v211; // [sp+30h] [-460h]
  int v212; // [sp+34h] [-45Ch]
  int v213; // [sp+38h] [-458h]
  int v214; // [sp+3Ch] [-454h]
  int v215; // [sp+40h] [-450h]
  int v216; // [sp+44h] [-44Ch]
  int v217; // [sp+48h] [-448h]
  int v218; // [sp+4Ch] [-444h]
  int v219; // [sp+50h] [-440h]
  int v220; // [sp+58h] [-438h]
  idPropsCollection *v221; // [sp+60h] [-430h]
  idVec3 v222; // [sp+68h] [-428h] BYREF
  char v223; // [sp+7Ch] [-414h] BYREF
  idMat3 v224; // [sp+80h] [-410h] BYREF
  __vector4 *v225; // [sp+A4h] [-3ECh]
  idTreeAnimator *v226; // [sp+A8h] [-3E8h]
  unsigned int v227; // [sp+ACh] [-3E4h]
  unsigned int v228; // [sp+B0h] [-3E0h]
  idAnimator_BlendEq **v229; // [sp+B4h] [-3DCh]
  int v230; // [sp+B8h] [-3D8h]
  const char *v231; // [sp+BCh] [-3D4h]
  idMat3 v232; // [sp+C0h] [-3D0h] BYREF
  __vector4 *v233; // [sp+E4h] [-3ACh]
  idMat3 *v234; // [sp+E8h] [-3A8h]
  unsigned __int64 *v235; // [sp+ECh] [-3A4h]
  idEntity *v236; // [sp+F0h] [-3A0h]
  __vector4 *v237; // [sp+F4h] [-39Ch]
  idTypesafeNumber<float,enum RadiansUnique_t> v238; // [sp+F8h] [-398h] BYREF
  float *v239; // [sp+FCh] [-394h]
  void *v240; // [sp+100h] [-390h]
  idVehicleWindow::decal_t v241; // [sp+110h] [-380h] BYREF
  idMat3 v242; // [sp+140h] [-350h] BYREF
  idVec3 v243; // [sp+168h] [-328h] BYREF
  idVec4 v244; // [sp+180h] [-310h] BYREF
  float v245[4]; // [sp+190h] [-300h] BYREF
  float v246[7]; // [sp+1A0h] [-2F0h] BYREF
  char v247; // [sp+1BCh] [-2D4h] BYREF
  float v248; // [sp+1C0h] [-2D0h]
  float v249; // [sp+1C4h] [-2CCh]
  float v250; // [sp+1C8h] [-2C8h]
  float v251; // [sp+1CCh] [-2C4h]
  float v252; // [sp+1D0h] [-2C0h]
  float v253; // [sp+1D4h] [-2BCh]
  float v254; // [sp+1D8h] [-2B8h]
  float v255; // [sp+1DCh] [-2B4h]
  __int64 v256; // [sp+1E0h] [-2B0h]
  trace_t v257; // [sp+1F0h] [-2A0h] BYREF
  idAngles v258[4]; // [sp+270h] [-220h] BYREF
  idDrawVert v259; // [sp+2A0h] [-1F0h] BYREF
  idDrawVert v260; // [sp+2C0h] [-1D0h] BYREF
  idDrawVert v261; // [sp+2E0h] [-1B0h] BYREF
  idDrawVert v262; // [sp+300h] [-190h] BYREF
  idMat3 v263; // [sp+320h] [-170h] BYREF
  idVec3 v264[14]; // [sp+350h] [-140h] BYREF

  _R12 = -272;
  __asm { stvx128   v127, r1, r12 }
  a12 = this;
  v13 = this;
  if ( (vehicle_damage_player.flags & 0x20000) != 0 )
  {
    for ( i = 0; ; ++i )
    {
      presentable = v13->presentable;
      v16 = presentable != nullptr ? (int)presentable->GetVehicleInterface(this: presentable) : 0;
      if ( i >= *(_DWORD *)(v16 + 16476) )
        break;
      OccupantAsEntity = (idPlayer *)idVehicle::GetOccupantAsEntity(this: v13, index: i);
      if ( OccupantAsEntity != nullptr )
      {
        v18 = idPlayer::CastTo(c: OccupantAsEntity);
        if ( v18 != nullptr )
          *(_BYTE *)&v18->flags = (2 * (vehicle_damage_player.valueInteger != 0)) & 2 | *(_BYTE *)&v18->flags & 0xFD;
      }
    }
    vehicle_damage_player.flags &= ~0x20000u;
  }
  if ( vehicle_show.valueInteger == 0 )
    v13->Hide_2(this: v13);
  v19 = v13->presentable;
  if ( v19 != nullptr )
    v20 = (int)v19->GetVehicleInterface(this: v19);
  else
    v20 = 0;
  if ( *(_BYTE *)(v20 + 18912) != 0 )
  {
    v21 = v13->presentable;
    v22 = v21 != nullptr ? (int)v21->GetVehicleInterface(this: v21) : 0;
    v23 = v13->presentable;
    v24 = *(_DWORD *)(v22 + 17988);
    v25 = v23 != nullptr ? (int)v23->GetVehicleInterface(this: v13->presentable) : 0;
    if ( !idVehicleWeapon::PlayingWeaponChangeAnim(this: *(idVehicleWeapon **)(4 * v24 + *(_DWORD *)(v25 + 18744))) )
    {
      v26 = v13->presentable;
      if ( v26 != nullptr )
        v27 = (int)v26->GetVehicleInterface(this: v26);
      else
        v27 = 0;
      *(_BYTE *)(v27 + 18912) = 0;
    }
  }
  v28 = v13->presentable;
  if ( v28 != nullptr )
    v29 = v28->GetVehicleInterface(this: v28);
  else
    v29 = nullptr;
  idPresentableVehicle::QuickItemThink(this: v29);
  v30 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
  idDynamicCoverMgr::UpdateUsable(this: &v13->vehicleCover, owner: v13, curTime: v30);
  v31 = v13->presentable;
  if ( v31 != nullptr )
    v32 = v31->GetVehicleInterface(this: v31);
  else
    v32 = nullptr;
  v33 = idPresentableVehicle::PlayerIsOccupant(this: v32);
  if ( v33 != nullptr )
  {
    entity = (idPlayer *)v33->entity;
    if ( entity != nullptr )
      idJobTimerManager::UpdateJobTimers(this: &entity->jobTimerManager, player: entity);
  }
  v35 = &clientGame;
  v229 = (idAnimator_BlendEq **)&clientGame;
  if ( vehicle_showDamageDecals.valueInteger == 2 )
  {
    vehicleDecalDamage = v13->vehicleDecalDamage;
    if ( vehicleDecalDamage != nullptr )
    {
      p_vehicleDecals = &vehicleDecalDamage->vehicleDecals;
      v38 = 0;
      if ( vehicleDecalDamage->vehicleDecals.num > 0 )
      {
        v39 = 0;
        do
        {
          Physics = idEntity::GetPhysics(this: v13);
          v41 = idEntity::GetPhysics(this: v13);
          v42 = (int)v41->GetOrigin(this: v41, a2: 0);
          v43 = Physics;
          p_x = &p_vehicleDecals->list[v39].decalSize.x;
          v45 = p_x[30];
          v46 = p_x[31];
          v47 = (float)(p_x[30] + p_x[27]);
          v48 = (float)(p_x[27] - p_x[30]);
          v49 = p_x[32];
          v50 = p_x[29];
          v51 = (float)(p_x[31] + p_x[28]);
          v52 = (float)(p_x[28] - p_x[31]);
          v53 = p_x[28];
          v245[0] = 1.0;
          v245[1] = 1.0;
          v245[2] = 1.0;
          v245[3] = 1.0;
          v246[3] = v47;
          v246[4] = v51;
          v246[5] = (float)v49 + (float)v50;
          v246[0] = v48;
          v246[1] = v52;
          v246[2] = (float)v50 - (float)v49;
          renderWorld = clientGame->renderWorld;
          GetAxis = Physics->GetAxis;
          v55 = renderWorld->__vftable;
          v57 = ((int (__fastcall *)(idPhysics *, _DWORD, double, double, double, double))GetAxis)(
                  a1: v43,
                  a2: 0,
                  a3: v46,
                  a4: v48,
                  a5: v53,
                  a6: v45);
          v55->DebugOrientedBounds(
            this: renderWorld,
            a2: (const idVec4 *)v245,
            a3: (const idBounds *)v246,
            a4: (const idVec3 *)v42,
            a5: (const idMat3 *)v57,
            a6: 0,
            a7: false);
          ++v38;
          ++v39;
        }
        while ( v38 < p_vehicleDecals->num );
      }
    }
  }
  if ( v13->vehicleWindow.windows.num > 0
    && (unsigned __int8)Get_idCombatStage_useRelaxedChatterVO(ptr: (unsigned __int8 *)v13) == 0 )
  {
    TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: v13);
    v226 = TreeAnimatorFromPresentable;
    if ( TreeAnimatorFromPresentable != nullptr )
    {
      v60 = v13->presentable;
      v61 = v60 != nullptr ? (int)v60->GetVehicleInterface(this: v60) : 0;
      v62 = (float)((float)(*(float *)(v61 + 11900) * v13->windowMovementScale) + v13->windowMovement);
      *(double *)&v59 = v62;
      v63 = floor(x: v59);
      v13->windowMovement = (float)v62 - (float)*(double *)&v63;
      v64 = idEntity::GetPhysics(this: v13);
      v65 = (int)v64->GetAxis(this: v64, a2: 0);
      p_flags = &v257.c.flags;
      v67 = (_DWORD *)(v65 - 4);
      for ( j = 9; j != 0; --j )
      {
        ++v67;
        p_flags += 4;
        *(_DWORD *)p_flags = *v67;
      }
      idMat3::ToAngles(this: &v232, result: v258);
      idAngles::Normalize360(this: (idAngles *)&v232);
      v244.w = v13->windowMovement;
      v244.x = v232.mat[0].x * (float)0.0027777778;
      v232.mat[0].x = v244.x;
      v244.y = v232.mat[0].y * (float)0.0027777778;
      v232.mat[0].y = v244.y;
      v244.z = v232.mat[0].z * (float)0.0027777778;
      v232.mat[0].z = v244.z;
      decl = TreeAnimatorFromPresentable->decl;
      v221 = decl != nullptr ? &decl->props : nullptr;
      num = v13->vehicleWindow.windows.num;
      v230 = 0;
      if ( num > 0 )
      {
        v228 = 0;
        v227 = 0;
        v233 = &_vmx_3f8000003f8000003f8000003f800000;
        v239 = (float *)&MAX_RAND_FINV_112;
        z_low = &collisionModelManager;
        v231 = "_info";
        v72 = COERCE_FLOAT(&idCollisionQuery::finalResultsFirstSubmittedOffset);
        LODWORD(v232.mat[2].z) = &collisionModelManager;
        v73 = v221;
        v74 = COERCE_FLOAT(&idMath::M_DEG2RAD);
        v75 = v226;
        LODWORD(v232.mat[1].y) = &idMath::TWO_PI;
        LODWORD(v232.mat[1].x) = &idMath::M_DEG2RAD;
        v235 = &idCollisionQuery::finalResultsLastSubmittedOffset;
        LODWORD(v232.mat[2].x) = &idCollisionQuery::finalResultsFirstSubmittedOffset;
        v237 = &`VertexColorToByteWithScale'::`2'::SIMD_SP_255;
        v225 = &`VertexFloatToByte'::`2'::SIMD_SP_255_over_2;
        v240 = &`VertexFloatToByte'::`2'::SIMD_SP_half;
        v76 = COERCE_FLOAT(&vec3_origin);
        LODWORD(v232.mat[2].y) = &idColor::colorWhite;
        v234 = &mat3_identity;
        HIDWORD(v77) = 1013904223;
        LODWORD(v232.mat[1].z) = &vec3_origin;
        _R22 = 16;
        _R20 = 22;
        _R21 = 23;
        while ( 1 )
        {
          v81 = &v13->vehicleWindow.windows.list[v228 / 0x50];
          p_z = (_DWORD *)&v234[-1].mat[2].z;
          v83 = *(float *)(LODWORD(v76) + 4);
          v84 = &v223;
          v85 = *(float *)(LODWORD(v76) + 8);
          v86 = 9;
          list = v13->vehicleWindowKit->windows.list;
          v222.x = *(float *)LODWORD(v76);
          v88 = &list[v227 / 0x9C];
          v222.y = v83;
          v222.z = v85;
          do
          {
            ++p_z;
            v84 += 4;
            *(_DWORD *)v84 = *p_z;
            --v86;
          }
          while ( v86 != 0 );
          LODWORD(v77) = 0;
          index = v81->clipQuery.index;
          if ( (unsigned int)index < *(_DWORD *)(HIDWORD(index) + 377212)
            || (unsigned int)index > *(_DWORD *)(HIDWORD(index) + 377220) )
          {
            v92 = 0;
          }
          else
          {
            v90 = *(_QWORD *)LODWORD(v72);
            v91 = *(_QWORD *)(8 * ((index & 0xFFF) + ((2 * index) & 0x1FFE)) + HIDWORD(index) + 278920);
            if ( (unsigned int)v91 < (unsigned int)v90
              || (v93 = (unsigned int)v91 < *(_DWORD *)(HIDWORD(v90) + 4), v92 = 1, !v93) )
            {
              v92 = 0;
            }
          }
          if ( v92 != 0 )
          {
            v94 = v81->clipQuery.index;
            v95 = *v35;
            v81->clipQuery.index = v77;
            idCollisionModelManager::GetContentsResult(
              this: *z_low,
              result: &v257,
              query: &v95->clip.collisionQueries[v94 & 0xFFF].query,
              peek: false);
            if ( v257.fraction < 1.0 )
            {
              if ( v81->broken )
              {
                if ( v88->damageDriverWhenBroken )
                {
                  Driver = idVehicle::GetDriver(this: v13);
                  if ( Driver != nullptr )
                  {
                    def = v81->damageQuery.def;
                    if ( def != nullptr )
                    {
                      v133 = Driver->__vftable;
                      scale = v81->damageQuery.scale;
                      v236 = idEntityPtr<idEntity const>::operator->(this: &v81->damageQuery.attacker);
                      v135 = idEntityPtr<idEntity const>::operator->(this: &v81->damageQuery.inflictor);
                      ((void (__fastcall *)(idEntity *, idEntity *, idEntity *, const idDeclDamage *, double))v133->Damage)(
                        a1: Driver,
                        a2: v135,
                        a3: v236,
                        a4: def,
                        a5: scale);
                      v75 = v226;
                      v81->damageQuery.def = nullptr;
                      v81->damageQuery.inflictor.spawnId.value = 0x1FFF;
                      v81->damageQuery.attacker.spawnId.value = 0x1FFF;
                    }
                  }
                }
              }
              else if ( v81->decals.num >= v88->maxDecals )
              {
                normalModel = v81->normalModel;
                if ( !normalModel->unlinked )
                {
                  idRenderModel::CommitThisFrame(this: v81->normalModel);
                  normalModel->unlinked = true;
                }
                v81->broken = true;
              }
              else
              {
                if ( v73 != nullptr && v88->tagName.len != 0 )
                {
                  Tag = idPropsCollection::GetTag(this: v73, propName: v231, tagName: v88->tagName.data);
                  LOBYTE(v77) = idTreeAnimator::GetWorldSpaceTagTransform(
                                  this: v75,
                                  tagData: Tag,
                                  origin: &v222,
                                  axis: &v224);
                }
                if ( (_BYTE)v77 == 0 )
                {
                  Origin = idRenderModel::GetOrigin(this: v75);
                  v222.x = Origin->origin.x;
                  v222.y = Origin->origin.y;
                  v222.z = Origin->origin.z;
                  Axis = (float *)idRenderModel::GetAxis(this: v75);
                  v224.mat[0].x = *Axis;
                  LOBYTE(v77) = 1;
                  v224.mat[0].y = Axis[1];
                  v224.mat[0].z = Axis[2];
                  v224.mat[1].x = Axis[3];
                  v224.mat[1].y = Axis[4];
                  v224.mat[1].z = Axis[5];
                  v224.mat[2].x = Axis[6];
                  v224.mat[2].y = Axis[7];
                  v224.mat[2].z = Axis[8];
                }
                v99 = v88->decals.num;
                x = v224.mat[0].x;
                v101 = v224.mat[1].x;
                lastDecalIndex = v81->lastDecalIndex;
                v103 = v99 - 1;
                v104 = v224.mat[2].x;
                y = v224.mat[0].y;
                v107 = v224.mat[1].y;
                v108 = v224.mat[2].y;
                z = v224.mat[0].z;
                v110 = v224.mat[1].z;
                v111 = v224.mat[2].z;
                v93 = v99 == 1;
                v106 = 0;
                if ( !v93 )
                {
                  v112 = *v35;
                  if ( v103 > 0 )
                  {
                    v113 = 1664525 * v112->random.seed + 1013904223;
                    __twllei(v103 + 1, 0);
                    v112->random.seed = v113;
                    v114 = (v113 >> 10) & 0x7FFF;
                    v106 = v114 % (v103 + 1);
                    __twlgei((v103 + 1) & ~(__ROL4__(v114, 1) - 1), 0xFFFFFFFF);
                  }
                  else
                  {
                    v106 = 0;
                  }
                  if ( v106 == lastDecalIndex )
                  {
                    if ( v106 == v103 )
                      v106 = 0;
                    else
                      ++v106;
                  }
                }
                v81->lastDecalIndex = v106;
                v115 = *(float *)(LODWORD(v76) + 8);
                v116 = *(float *)LODWORD(v76);
                v117 = (int)&v88->decals.list[v106];
                p_gameTimeManager = &(*v35)->gameTimeManager;
                v119 = *(const idMaterial **)v117;
                v241.position.y = *(float *)(LODWORD(v76) + 4);
                v241.position.z = v115;
                v241.normal.x = v116;
                v241.normal.y = v241.position.y;
                v241.normal.z = v115;
                v241.position.x = v116;
                v241.material = v119;
                GameMs = idGameTimeManager::GetGameMs(this: p_gameTimeManager, type: GAMETIME_SCALED);
                v122 = *(_DWORD *)(v117 + 12);
                v123 = *(unsigned __int8 *)(v117 + 16);
                v124 = *(float *)(v117 + 4);
                v241.startTime = GameMs;
                v125 = (float)((float)v124 * *(float *)LODWORD(v74));
                v241.size = *(float *)(v117 + 8);
                v241.fadeInTime = v122;
                v241.rotation = v125;
                v241.normal.x = (float)(v257.c.normal.y * (float)y)
                              + (float)((float)(v257.c.normal.x * (float)x) + (float)(v257.c.normal.z * (float)z));
                v241.normal.y = (float)((float)v101 * v257.c.normal.x)
                              + (float)((float)(v257.c.normal.z * (float)v110) + (float)(v257.c.normal.y * (float)v107));
                v241.normal.z = (float)((float)v104 * v257.c.normal.x)
                              + (float)((float)(v257.c.normal.z * (float)v111) + (float)(v257.c.normal.y * (float)v108));
                if ( v123 != 0 )
                {
                  v126 = v232.mat[1].y;
                  v127 = *v239;
                  v128 = 1664525 * (*v35)->random.seed + 1013904223;
                  (*v35)->random.seed = v128;
                  v129 = (v128 >> 10) & 0x7FFF;
                  v241.rotation = (float)((float)*(__int64 *)(&v121 - 1) * *(float *)LODWORD(v126)) * (float)v127;
                  v256 = *(_QWORD *)(&v121 - 1);
                }
                v241.position.y = (float)((float)v101 * (float)(v257.endpos.x - v222.x))
                                + (float)((float)((float)(v257.endpos.z - v222.z) * (float)v110)
                                        + (float)((float)(v257.endpos.y - v222.y) * (float)v107));
                v241.position.z = (float)((float)v104 * (float)(v257.endpos.x - v222.x))
                                + (float)((float)((float)(v257.endpos.z - v222.z) * (float)v111)
                                        + (float)((float)(v257.endpos.y - v222.y) * (float)v108));
                v241.position.x = (float)((float)(v257.endpos.y - v222.y) * (float)y)
                                + (float)((float)((float)(v257.endpos.x - v222.x) * (float)x)
                                        + (float)((float)(v257.endpos.z - v222.z) * (float)z));
                idList<idVehicleWindow::decal_t,5>::Append(this: &v81->decals, obj: &v241);
              }
            }
          }
          if ( v81->broken )
            brokenModel = v81->brokenModel;
          else
            brokenModel = v81->normalModel;
          if ( v81->broken || (v137 = 1, v81->decals.num <= 0) )
            v137 = 0;
          if ( (_BYTE)v77 == 0 && (brokenModel != nullptr || v137 != 0) )
          {
            if ( v221 != nullptr && v88->tagName.len != 0 )
            {
              v139 = idPropsCollection::GetTag(this: v221, propName: v231, tagName: v88->tagName.data);
              LOBYTE(v77) = idTreeAnimator::GetWorldSpaceTagTransform(
                              this: v75,
                              tagData: v139,
                              origin: &v222,
                              axis: &v224);
            }
            if ( (_BYTE)v77 == 0 )
            {
              v140 = idRenderModel::GetOrigin(this: v75);
              v222.x = v140->origin.x;
              v222.y = v140->origin.y;
              v222.z = v140->origin.z;
              v141 = (float *)idRenderModel::GetAxis(this: v75);
              v224.mat[0].x = *v141;
              v224.mat[0].y = v141[1];
              v224.mat[0].z = v141[2];
              v224.mat[1].x = v141[3];
              v224.mat[1].y = v141[4];
              v224.mat[1].z = v141[5];
              v224.mat[2].x = v141[6];
              v224.mat[2].y = v141[7];
              v224.mat[2].z = v141[8];
            }
          }
          if ( v137 != 0 )
          {
            GameMsPerFrame = (const idMaterial *)idGameTimeManager::GetGameMsPerFrame(
                                                   this: (idGameTimeManager *)&(*v229)[3938],
                                                   type: GAMETIME_SCALED);
            v143 = 0;
            if ( v81->decals.num > 0 )
            {
              __asm { vspltisw128 v127, 0 }
              v144 = 0;
              do
              {
                v145 = &v81->decals.list[v144];
                v146 = v145->position.y;
                v147 = v145->position.z;
                v148 = (float)(v224.mat[1].x * v145->position.y);
                v149 = (float)(v224.mat[2].y * v145->position.z);
                v150 = v145->position.x;
                v151 = (float)(v224.mat[2].z * v145->position.z);
                v238.value = v145->rotation;
                v243.x = 1.0;
                v243.y = 0.0;
                v243.z = 0.0;
                v152 = (float)((float)((float)(v224.mat[0].x * (float)v150)
                                     + (float)((float)(v224.mat[2].x * (float)v147) + (float)v148))
                             + v222.x);
                v153 = (float)((float)((float)(v224.mat[1].y * (float)v146)
                                     + (float)((float)(v224.mat[0].y * (float)v150) + (float)v149))
                             + v222.y);
                v154 = (float)((float)((float)(v224.mat[1].z * (float)v146)
                                     + (float)((float)(v224.mat[0].z * (float)v150) + (float)v151))
                             + v222.z);
                v155 = idVec3::ToMat3(this: v264, result: (idMat3 *)&v145->normal);
                v156 = idMat3::idMat3(this: &v263, axis: &v243, angle: &v238);
                idMat3::operator*(this: &v242, result: v156, a: v155);
                idMat3::operator*=(this: &v242, a: &v224);
                _R7 = &v242.mat[2];
                __asm { vmr128    v59, v127 }
                _R6 = v232.mat[2].y;
                _R5 = v237;
                _R4 = &v242.mat[2].y;
                _R8 = &v242.mat[0].y;
                _R3 = &v242.mat[2].z;
                v164 = (float)(v145->size * (float)0.5);
                __asm { lvlx128   v57, r0, r7 }
                _R30 = &v242.mat[0].z;
                __asm { vrlimi128 v59, v57, 8, 0 }
                _R18 = &v242;
                __asm
                {
                  lvx128    v63, r0, r6
                  lvx128    v62, r0, r5
                }
                v167 = (float *)&v247;
                __asm
                {
                  lvlx128   v56, r0, r4
                  vmulfp128 v58, v95, v62
                  vor128    v54, v91, v59
                  lvlx128   v61, r0, r8
                  lvlx128   v60, r0, r18
                }
                _R7 = v233;
                __asm { lvlx128   v55, r0, r3 }
                _R6 = v240;
                _R11 = &v259.xyz.z;
                v171 = 4;
                v172 = (float)((float)1.0 / v145->size);
                _R8 = 16;
                __asm
                {
                  vrlimi128 v54, v56, 4, 3
                  lvlx128   v62, r0, r30
                  vrlimi128 v54, v55, 2, 2
                  lvx128    v63, r0, r7
                }
                _R5 = v225;
                __asm { lvx128    v11, r0, r6 }
                __asm { vcfpsxws128 v59, v58, 0 }
                v175 = v242.mat[2].z;
                __asm { vaddfp128 v0, v86, v63 }
                v176 = v242.mat[2].y;
                v177 = v242.mat[2].x;
                __asm { lvx128    v10, r0, r5 }
                v178 = v242.mat[1].z;
                v179 = v242.mat[1].y;
                v180 = v242.mat[1].x;
                v250 = v145->size * (float)0.5;
                v253 = v164;
                v254 = v164;
                v255 = v164;
                v248 = -v164;
                v249 = v248;
                __asm { vmaddfp   v0, v0, v11, v10 }
                v251 = v248;
                v252 = v248;
                __asm { vcfpsxws128 v58, v0, 0 }
                do
                {
                  __asm { vmr128    v52, v127 }
                  _R9 = _R11 - 2;
                  __asm { vmr128    v53, v127 }
                  _R7 = 12;
                  __asm { vor128    v51, v90, v58 }
                  _R6 = 13;
                  __asm { vor128    v50, v91, v59 }
                  _R5 = 14;
                  __asm { vcmpequw128 v49, v84, v52 }
                  _R4 = 17;
                  __asm
                  {
                    stvx128   v52, r0, r9
                    vrlimi128 v53, v60, 8, 0
                    vpkswss128 v48, v83, v51
                  }
                  _R3 = 18;
                  __asm { vpkswss128 v47, v82, v50 }
                  _R30 = 20;
                  __asm { vsldoi128 v46, v84, v49, 4 }
                  _R18 = 21;
                  __asm
                  {
                    vrlimi128 v53, v61, 4, 3
                    vpkshus128 v13, v80, v48
                    vpkshus128 v0, v79, v47
                    vrlimi128 v53, v62, 2, 2
                    stvx128   v46, r9, r8
                    vaddfp128 v12, v85, v63
                    vmaddfp   v12, v12, v11, v10
                  }
                  v189 = v167[2];
                  v190 = (float)(v167[1] * (float)v180);
                  __asm { vcfpsxws128 v45, v12, 0 }
                  __asm { vpkswss128 v44, v77, v45 }
                  v191 = (float)((float)(v167[1] * (float)v179) + (float)v153);
                  v192 = (float)((float)(v167[1] * (float)v178) + (float)v154);
                  v193 = (float)((float)(v167[1] * (float)v172) + (float)0.5);
                  v167 += 2;
                  __asm { vpkshus128 v12, v76, v44 }
                  v194 = (float)((float)(*v167 * (float)v172) + (float)0.5);
                  *(_R11 - 2) = (float)((float)v190 + (float)v152) + (float)((float)v189 * (float)v177);
                  *(_R11 - 1) = (float)v191 + (float)((float)v189 * (float)v176);
                  *_R11 = (float)v192 + (float)((float)v189 * (float)v175);
                  _R11[1] = v193;
                  _R11[2] = v194;
                  __asm
                  {
                    stvebx    v12, r11, r7
                    stvebx    v12, r11, r6
                    stvebx    v12, r11, r5
                    stvebx    v13, r11, r22
                    stvebx    v13, r11, r4
                    stvebx    v13, r11, r3
                  }
                  *((_BYTE *)_R11 + 19) = -1;
                  __asm
                  {
                    stvebx    v0, r11, r30
                    stvebx    v0, r11, r18
                    stvebx    v0, r11, r20
                    stvebx    v0, r11, r21
                  }
                  _R11 += 8;
                  --v171;
                }
                while ( v171 != 0 );
                material = v145->material;
                if ( v145->material != nullptr )
                {
                  fadeInTime = (const idMaterial *)v145->fadeInTime;
                  startTime = (const idMaterial *)v145->startTime;
                  MergeBranch = (idRenderModelEffects *)idAnimator_BlendEq::InternalGetMergeBranch(this: *v229);
                  idRenderModelEffects::AddDecal(
                    this: MergeBranch,
                    mat: material,
                    v0: &v259,
                    v1: &v260,
                    v2: &v261,
                    v3: &v262,
                    startTime,
                    lifeTime: GameMsPerFrame,
                    fadeInEndTime: v201,
                    fadeOutStartTime: v202,
                    a11: v203,
                    a12: v204,
                    a13: v205,
                    a14: v206,
                    a15: v207,
                    a16: v208,
                    a17: v209,
                    a18: v210,
                    a19: v211,
                    a20: v212,
                    a21: v213,
                    a22: v214,
                    a23: v215,
                    a24: v216,
                    a25: v217,
                    a26: v218,
                    a27: v219,
                    a28: fadeInTime,
                    a29: v220,
                    a30: GameMsPerFrame);
                }
                ++v143;
                ++v144;
              }
              while ( v143 < v81->decals.num );
              v76 = v232.mat[1].z;
              v74 = v232.mat[1].x;
              z_low = (idCollisionModelManager **)LODWORD(v232.mat[2].z);
              v13 = a12;
            }
          }
          if ( brokenModel != nullptr )
          {
            if ( !brokenModel->deferredPositionInitialized || !brokenModel->useDeferredPosition )
              brokenModel->g.origin = v222;
            brokenModel->deferredOrigin = v222;
            idRenderModel::SetAxis(this: brokenModel, a: &v224);
            idRenderModel::SetParm(this: brokenModel, parm: v13->rp_modelAngles, v4: &v244);
            idRenderModel::CommitThisFrame(this: brokenModel);
          }
          v199 = v13->vehicleWindow.windows.num;
          v227 += 156;
          v228 += 80;
          if ( ++v230 >= v199 )
            break;
          v35 = (idClientGame **)v229;
          v73 = v221;
          v75 = v226;
          HIDWORD(v77) = 1013904223;
          v72 = v232.mat[2].x;
        }
      }
    }
  }
  idVehicle::UpdateEventAnims(this: v13);
  _R0 = -272;
  __asm { lvx128    v127, r1, r0 }
}


// ========================================================================
// ?CheckForUseInVolume@idVehicle@@QAA_NXZ
// EA  : 0x82D28298
// RVA : 0x00D28298
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

int __fastcall idVehicle::CheckForUseInVolume(idVehicle *this)
{
  idPresentable *presentable; // r3
  int v3; // r3
  idPresentable *v4; // r3
  int v5; // r3
  idPresentablePtr<idPresentable> *v6; // r31
  idEntity *entity; // r3
  int v8; // r11
  char v9; // r11
  bool v10; // zf
  idPresentable *v11; // r3
  idPresentableVehicle *v12; // r3
  idList<idEntityPtr<idEntity>,5> *v13; // r3
  idList<idEntityPtr<idEntity>,5> *v14; // r29
  char v15; // r27
  int v16; // r28
  int v17; // r30
  idVolume *v18; // r3
  idVolume *v19; // r31
  idPlayer *v20; // r3
  int FocusTracker; // r3
  int result; // r3
  usercmd_t v23; // [sp+50h] [-C0h] BYREF
  usercmd_t v24[2]; // [sp+90h] [-80h] BYREF

  presentable = this->presentable;
  if ( presentable != nullptr )
    v3 = (int)presentable->GetVehicleInterface(this: presentable);
  else
    v3 = 0;
  if ( !idPresentablePtr<idPresentable>::IsValid(this: *(idPresentablePtr<idPresentableActor> **)(v3 + 16472)) )
    return 0;
  v4 = this->presentable;
  if ( v4 != nullptr )
    v5 = (int)v4->GetVehicleInterface(this: v4);
  else
    v5 = 0;
  v6 = *(idPresentablePtr<idPresentable> **)(v5 + 16472);
  if ( idPresentablePtr<idPresentable>::IsValid(this: (idPresentablePtr<idPresentableActor> *)v6) )
    entity = idPresentablePtr<idPresentableProjectile>::operator->(this: v6)->entity;
  else
    entity = nullptr;
  v8 = *(_DWORD *)(entity->GetType(this: entity) + 36);
  if ( v8 < idPlayer::Type.typeNum || (v10 = v8 <= idPlayer::Type.lastChild, v9 = 1, !v10) )
    v9 = 0;
  if ( v9 == 0 )
    return 0;
  usercmd_t::usercmd_t(this: v24);
  usercmd_t::usercmd_t(this: &v23);
  v11 = this->presentable;
  v12 = v11 != nullptr ? v11->GetVehicleInterface(this: v11) : nullptr;
  if ( (unsigned __int8)idPresentableVehicle::GetUserCommand(this: v12, seat: 0, previous: v24, current: &v23) == 0 )
    return 0;
  if ( (((*((_BYTE *)&v23 + 9) & 0x80) != 0 ? 0 : v23.buttons) & 1) == 0 )
    return 0;
  if ( (((*((_BYTE *)v24 + 9) & 0x80) != 0 ? 0 : v24[0].buttons) & 1) != 0 )
    return 0;
  v13 = this->GetTriggerTouchList_2(this);
  v14 = v13;
  if ( v13 == nullptr )
    return 0;
  v15 = 0;
  v16 = 0;
  if ( v13->num > 0 )
  {
    v17 = 0;
    do
    {
      v18 = (idVolume *)idEntityPtr<idEntity const>::operator->(this: &v14->list[v17]);
      if ( v18 != nullptr )
      {
        v19 = idVolume::CastTo(c: v18);
        if ( v19 != nullptr )
        {
          v20 = idVehicle::PlayerIsOccupant(this);
          if ( v20 != nullptr )
          {
            FocusTracker = idPlayer::GetFocusTracker(this: v20);
            if ( v19->Use(this: v19, a2: this, a3: *(const usableState_t *)(FocusTracker + 524)) )
              v15 = 1;
          }
        }
      }
      ++v16;
      ++v17;
    }
    while ( v16 < v14->num );
  }
  result = 1;
  if ( v15 == 0 )
    return 0;
  return result;
}


// ========================================================================
// ?Damage@idVehicle@@UAAMPAVidEntity@@0PBVidDeclDamage@@MABVidVec3@@PAUtrace_t@@@Z
// EA  : 0x82D284E0
// RVA : 0x00D284E0
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

float __fastcall idVehicle::Damage(
        idVehicle *this,
        idEntity *inflictor,
        idEntity *attacker,
        const idDeclDamage *damageDef,
        double damageScale,
        const idVec3 *dir,
        const idVec3 *trace,
        trace_t *a8)
{
  idPlayer *Driver; // r3
  const idEntity *v16; // r3
  idVehicleOccupant *OccupantForEntity; // r3
  double v18; // fp1

  if ( this->TakesDamage(this) && damageDef != nullptr && vai_god.valueInteger == 0 )
  {
    this->lastDamage.damage = idDeclDamage::DamageAmount(this: damageDef) * (float)damageScale;
    this->lastDamage.damageDef = damageDef;
    if ( attacker != nullptr )
      this->lastDamage.attacker.spawnId.value = (gameLocal->spawnIds.ptr[attacker->entityNumber] << 13)
                                              | attacker->entityNumber;
    else
      this->lastDamage.attacker.spawnId.value = 0x1FFF;
    if ( inflictor != nullptr )
      this->lastDamage.inflictor.spawnId.value = (gameLocal->spawnIds.ptr[inflictor->entityNumber] << 13)
                                               | inflictor->entityNumber;
    else
      this->lastDamage.inflictor.spawnId.value = 0x1FFF;
    this->lastDamage.time = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    this->lastDamage.actor.spawnId.value = 0x1FFF;
    this->lastDamage.actorTime = 0;
    idVehicle::UpdateDamageDecals(this, trace: a8, damageDef, dir: trace, damageScale);
    Driver = (idPlayer *)idVehicle::GetDriver(this);
    if ( idPlayer::CastTo(c: Driver) != nullptr )
    {
      v16 = idVehicle::GetDriver(this);
      OccupantForEntity = idVehicle::GetOccupantForEntity(this, entity: v16);
      if ( OccupantForEntity != nullptr )
        ((void (__fastcall *)(idVehicleOccupant *, idEntity *, idEntity *, const idDeclDamage *, double))OccupantForEntity->Damage)(
          a1: OccupantForEntity,
          a2: inflictor,
          a3: attacker,
          a4: damageDef,
          a5: damageScale);
    }
  }
  v18 = 0.0;
  return *((float *)&v18 + 1);
}


// ========================================================================
// ?GetBestArmorForDamage@idVehicle@@QAAPAVidInventoryItem@@VidVec3@@AAV?$idList@PAVidInventoryItem@@$04@@@Z
// EA  : 0x82D28670
// RVA : 0x00D28670
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
idInventoryItem *__fastcall idVehicle::GetBestArmorForDamage(
        idVehicle *this,
        idVec3 *point,
        idList<idInventoryItem *,5> *armorList,
        idList<enum encounterGroupRole_t,5> *a4)
{
  _DWORD *v4; // r3
  _DWORD *v5; // r28
  int v7; // r31
  bfx::Planner3D *v8; // r3
  idInventoryCollection *v9; // r3
  idDeclInfoTemplate<idDeclVehicleArmor> *parent; // r3
  char v11; // r11
  bfx::Planner3D *v12; // r3
  idInventoryItem *result; // r3
  double v14; // fp13
  int v15; // r11
  int num; // r8
  unsigned __int8 v17; // r6
  int v18; // r9
  int v19; // r5
  int v20; // r4
  idInventoryItem **list; // r5
  int v22; // r4
  int v23; // ctr
  idInventoryItem *v24; // r6
  int v25; // r7
  int v26; // r10
  int v27; // r11
  float *v28; // r11
  idInventoryItem *InventoryItem; // [sp+50h] [-30h] BYREF
  __int64 v30; // [sp+A0h] [+20h]

  v5 = v4;
  v30 = *(_QWORD *)&point;
  v7 = 0;
  v8 = (bfx::Planner3D *)(*(int (__fastcall **)(_DWORD *))(*v4 + 468))(a1: v4);
  if ( (int)idScriptObject::GetTypeDef(this: v8) > 0 )
  {
    do
    {
      v9 = (idInventoryCollection *)(*(int (__fastcall **)(_DWORD *))(*v5 + 468))(a1: v5);
      InventoryItem = idInventoryCollection::GetInventoryItem(this: v9, index: v7);
      parent = (idDeclInfoTemplate<idDeclVehicleArmor> *)InventoryItem->decl->GetDeclInfo(this: InventoryItem->decl);
      if ( parent != nullptr )
      {
        while ( parent != &idDeclVehicleArmor::resourceList )
        {
          parent = (idDeclInfoTemplate<idDeclVehicleArmor> *)parent->parent;
          if ( parent == nullptr )
            goto LABEL_5;
        }
        v11 = 1;
      }
      else
      {
LABEL_5:
        v11 = 0;
      }
      if ( v11 != 0 )
        idList<idAnimWebBlendTree *,5>::Append(this: a4, obj: (encounterGroupRole_t *)&InventoryItem);
      ++v7;
      v12 = (bfx::Planner3D *)(*(int (__fastcall **)(_DWORD *))(*v5 + 468))(a1: v5);
    }
    while ( v7 < (int)idScriptObject::GetTypeDef(this: v12) );
  }
  result = nullptr;
  v14 = 1.0e30;
  if ( *(float *)&v30 != vec3_origin.x
    || *((float *)&v30 + 1) != vec3_origin.y
    || (LOBYTE(v15) = 1, *(float *)&point != vec3_origin.z) )
  {
    LOBYTE(v15) = 0;
  }
  v15 = (unsigned __int8)v15;
  if ( (_BYTE)v15 == 0 )
  {
    num = a4->num;
    v17 = 1;
    v18 = 0;
    if ( num > 0 )
    {
      while ( 1 )
      {
        v19 = *(_DWORD *)(*(encounterGroupRole_t *)((char *)a4->list + v15) + 12);
        v20 = *(unsigned __int8 *)(v19 + 281);
        if ( (v20 == 0 ? 0 : v19) != 0 && *(_BYTE *)(v20 == 0 ? 508 : v19 + 0x1FC) == 0 )
          break;
        ++v18;
        v15 += 4;
        if ( v18 >= num )
          goto LABEL_21;
      }
      v17 = 0;
LABEL_21:
      list = (idInventoryItem **)a4->list;
      v22 = v17;
      v23 = a4->num;
      do
      {
        v24 = *list;
        if ( v22 != 0
          || (!v24->decl->vehicleArmor ? nullptr : v24->decl) == nullptr
          || *(!v24->decl->vehicleArmor ? (_BYTE *)508 : (_BYTE *)&v24->decl[1].trackedMemory) == 0 )
        {
          v25 = v5[1306];
          v26 = 0;
          if ( v25 > 0 )
          {
            v27 = 0;
            do
            {
              if ( v24->decl == *(const idDeclInventory **)(v27 + v5[1305]) )
                break;
              ++v26;
              v27 += 124;
            }
            while ( v26 < v25 );
          }
          if ( v26 != v25 )
          {
            v28 = (float *)(v5[1305] + 124 * v26);
            if ( *(_BYTE *)(*(_DWORD *)v28 + 278) == 0
              && (float)((float)((float)(v28[18] - *(float *)&v30) * (float)(v28[18] - *(float *)&v30))
                       + (float)((float)((float)(v28[20] - *(float *)&point) * (float)(v28[20] - *(float *)&point))
                               + (float)((float)(v28[19] - *((float *)&v30 + 1))
                                       * (float)(v28[19] - *((float *)&v30 + 1))))) < v14 )
            {
              result = *list;
              v14 = (float)((float)((float)(v28[18] - *(float *)&v30) * (float)(v28[18] - *(float *)&v30))
                          + (float)((float)((float)(v28[20] - *(float *)&point) * (float)(v28[20] - *(float *)&point))
                                  + (float)((float)(v28[19] - *((float *)&v30 + 1))
                                          * (float)(v28[19] - *((float *)&v30 + 1)))));
            }
          }
        }
        ++list;
        --v23;
      }
      while ( v23 != 0 );
    }
  }
  return result;
}


// ========================================================================
// ?DecreaseHealth@idVehicle@@QAAXM@Z
// EA  : 0x82D288F0
// RVA : 0x00D288F0
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __fastcall idVehicle::DecreaseHealth(idVehicle *this, double h)
{
  int v4; // r28
  int v5; // r30
  bfx::Planner3D *v6; // r3
  bool v7; // r5
  idInventoryCollection *v8; // r3
  idDeclInventory *decl; // r3
  BOOL noAttachment; // r9
  bfx::Planner3D *v11; // r3
  int num; // r27
  __int64 v13; // r11
  encounterGroupRole_t *list; // r26
  double v15; // fp30
  idInventoryItem **v16; // r30
  double v17; // fp1
  idInventoryItem *InventoryItem; // [sp+50h] [-80h] BYREF
  __int64 v19; // [sp+58h] [-78h]
  idList<enum encounterGroupRole_t,5> v20[3]; // [sp+60h] [-70h] BYREF

  if ( !common->IsMultiplayer(this: common) )
  {
    v4 = 0;
    memset(v20, 0, 14);
    v20[0].listStatic = 0;
    v20[0].memTag = 5;
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)v20);
    v5 = 0;
    v6 = (bfx::Planner3D *)this->GetInventory_2(this);
    if ( (int)idScriptObject::GetTypeDef(this: v6) > 0 )
    {
      do
      {
        v8 = this->GetInventory_2(this);
        InventoryItem = idInventoryCollection::GetInventoryItem(this: v8, index: v5);
        decl = (idDeclInventory *)InventoryItem->decl;
        noAttachment = decl->noAttachment;
        HIDWORD(v19) = decl;
        if ( !noAttachment )
        {
          HIDWORD(v19) = decl;
          if ( (unsigned __int8)idDecl::IsType<idDeclVehicleArmor>(this: decl) != 0 )
            idList<idAnimWebBlendTree *,5>::Append(this: v20, obj: (encounterGroupRole_t *)&InventoryItem);
        }
        ++v5;
        v11 = (bfx::Planner3D *)this->GetInventory_2(this);
      }
      while ( v5 < (int)idScriptObject::GetTypeDef(this: v11) );
    }
    num = v20[0].num;
    HIDWORD(v13) = 0x82000000;
    list = v20[0].list;
    if ( v20[0].num <= 0 )
    {
LABEL_12:
      if ( h > 0.0 )
      {
        v17 = (float)(this->GetHealth(this) - (float)h);
        if ( v17 < 1.0 )
          v17 = 1.0;
        this->SetHealth(this, a2: v17);
      }
    }
    else
    {
      LODWORD(v13) = v20[0].num;
      v19 = v13;
      v15 = (float)((float)((float)h / (float)v13) + (float)1.0);
      v16 = (idInventoryItem **)v20[0].list;
      while ( 1 )
      {
        if ( !(*v16)->decl->noAttachment )
        {
          h = (float)((float)h - idVehicle::ApplyArmorSave(this, item: *v16, damage: v15, throwItem: v7, a5: 0));
          if ( h <= 0.0 )
            break;
        }
        ++v4;
        ++v16;
        if ( v4 >= num )
          goto LABEL_12;
      }
    }
    if ( (v20[0].listStatic == 0 || v20[0].listStatic == 2) && list != nullptr )
      idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
  }
}


// ========================================================================
// $M524879_0
// EA  : 0x82D28B04
// RVA : 0x00D28B04
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void _M524879_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 208 + 96));
}


// ========================================================================
// ?RecalcMaxArmoredHealth@idVehicle@@QAAXXZ
// EA  : 0x82D28B30
// RVA : 0x00D28B30
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __fastcall idVehicle::RecalcMaxArmoredHealth(idVehicle *this)
{
  double maxArmoredHealth; // fp31
  double v3; // fp31
  idVehicleKey *playerKey; // r31
  int v5; // r30
  int v6; // r10
  int num; // ctr
  const idDeclInventory *decl; // r11
  double v9; // fp1
  __int64 v10; // r9
  double v11; // fp30
  double ArmoredHealth; // fp1
  double v13; // fp0

  maxArmoredHealth = this->maxArmoredHealth;
  if ( maxArmoredHealth <= 0.0 )
    goto LABEL_5;
  v3 = (float)(idVehicle::GetArmoredHealth(this) / (float)maxArmoredHealth);
  if ( v3 < 0.0 )
  {
    v3 = 0.0;
    goto LABEL_6;
  }
  if ( v3 > 1.0 )
LABEL_5:
    v3 = 1.0;
LABEL_6:
  if ( common->IsMultiplayer(this: common) )
  {
    this->maxArmoredHealth = this->GetMaxHealth(this);
    return;
  }
  playerKey = this->playerKey;
  if ( playerKey != nullptr )
  {
    idVehicleKey::DetermineFullUpgradeList(this: this->playerKey);
    v5 = 0;
    if ( playerKey->upgradedArmorList.num > 0 )
    {
      v6 = 0;
      num = playerKey->upgradedArmorList.num;
      do
      {
        decl = playerKey->upgradedArmorList.list[v6].decl;
        if ( !decl->noAttachment )
          v5 += decl->count;
        ++v6;
        --num;
      }
      while ( num != 0 );
    }
    v9 = ((double (__fastcall *)(idVehicle *))this->GetMaxHealth)(a1: this);
    LODWORD(v10) = v5;
    HIDWORD(v10) = this->lastMaxArmoredHealthFromKey;
    v11 = (float)((float)v9 + (float)v10);
    this->maxArmoredHealth = (float)v9 + (float)v10;
    if ( HIDWORD(v10) != 0 && v3 < 1.0 )
    {
      ArmoredHealth = idVehicle::GetArmoredHealth(this);
      v13 = (float)((float)((float)v3 - (float)((float)ArmoredHealth / (float)v11)) * this->maxArmoredHealth);
      if ( v13 > 0.0 )
      {
        this->IncreaseHealth(
          this,
          a2: (float)((float)((float)((float)v3 - (float)((float)ArmoredHealth / (float)v11)) * this->maxArmoredHealth)
                + (float)1.0));
        this->lastMaxArmoredHealthFromKey = true;
        return;
      }
      if ( v13 < 0.0 )
        idVehicle::DecreaseHealth(this, h: (float)((float)-v13 - (float)1.0));
    }
    this->lastMaxArmoredHealthFromKey = true;
  }
  else
  {
    this->maxArmoredHealth = idVehicle::GetArmoredHealth(this);
  }
}


// ========================================================================
// ?VehicleHasOccupant@idVehicle@@QAA_NPAVidEntity@@0@Z
// EA  : 0x82D28D08
// RVA : 0x00D28D08
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

int __fastcall idVehicle::VehicleHasOccupant(idVehicle *this, idVehicle *vehicle_entity, idEntity *entity)
{
  idVehicle *v3; // r30
  idEntity *BindMaster; // r3

  v3 = vehicle_entity;
  if ( vehicle_entity == nullptr )
  {
    if ( entity == nullptr )
      return 0;
    if ( idEntity::GetBindMaster(this: entity) == nullptr )
      return 0;
    BindMaster = idEntity::GetBindMaster(this: entity);
    if ( (unsigned __int8)idClass::IsType(this: BindMaster, superclass: &idVehicle_Car::Type) == 0 )
      return 0;
    v3 = (idVehicle *)idEntity::GetBindMaster(this: entity);
  }
  if ( (unsigned __int8)idVehicle_Car::IsTypeOf(c: v3) != 0 && (unsigned __int8)idActor::IsTypeOf(c: entity) != 0 )
    return idVehicle::IsAnOccupant(this: v3, entity);
  return 0;
}


// ========================================================================
// ?Event_VehicleHasOccupant@idVehicle@@QAA?AVeventFloat@@PAVidEntity@@0@Z
// EA  : 0x82D28DC8
// RVA : 0x00D28DC8
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

idVehicle *__fastcall idVehicle::Event_VehicleHasOccupant(
        idVehicle *this,
        idVehicle *result,
        idVehicle *vehicle_entity,
        idEntity *entity)
{
  __int64 v5; // r10

  LODWORD(v5) = (unsigned __int8)idVehicle::VehicleHasOccupant(this: result, vehicle_entity, entity);
  eventFloat::eventFloat((eventFloat *)this, f: (float)v5);
  return this;
}


// ========================================================================
// ?Event_GetVehicleWithOccupant@idVehicle@@QAA?AVeventEntity@@PAVidEntity@@@Z
// EA  : 0x82D28E20
// RVA : 0x00D28E20
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

idVehicle *__fastcall idVehicle::Event_GetVehicleWithOccupant(idVehicle *this, eventEntity *result, idEntity *entity)
{
  idLinkList<idVehicle> *v5; // r11
  idVehicle *owner; // r31
  idLinkList<idVehicle> *next; // r11

  if ( (unsigned __int8)idActor::IsTypeOf(c: entity) != 0
    && (v5 = gameLocal->vehicleEntities.next) != nullptr
    && v5 != gameLocal->vehicleEntities.head
    && (owner = v5->owner) != nullptr )
  {
    while ( (unsigned __int8)idVehicle::IsAnOccupant(this: owner, entity) == 0 )
    {
      next = owner->controlNode.next;
      if ( next == nullptr || next == owner->controlNode.head )
        owner = nullptr;
      else
        owner = next->owner;
      if ( owner == nullptr )
        goto LABEL_11;
    }
    eventEntity::eventEntity((eventEntity *)this, e: owner);
    return this;
  }
  else
  {
LABEL_11:
    eventEntity::eventEntity((eventEntity *)this, e: nullptr);
    return this;
  }
}


// ========================================================================
// ?SetAnimEventState@idVehicle@@QAAXHH_N@Z
// EA  : 0x82D28EF0
// RVA : 0x00D28EF0
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __fastcall idVehicle::SetAnimEventState(idVehicle *this, int animState, unsigned int blendTime, const bool queue)
{
  int v5; // r30
  signed int num; // r29
  int v9; // r3
  int currentState; // r11
  int v11; // r4
  double z; // fp8
  idPhysics *Physics; // r3
  idQuat *v14; // r3
  idPhysics *v15; // r3
  float *v16; // r3
  idMat3 v17; // [sp+50h] [-40h] BYREF

  v5 = animState;
  if ( animState >= 0 || animState == -2 )
  {
    num = this->eventAnimList.num;
    if ( num > animState )
    {
      if ( animState == -2 )
      {
        v9 = idRandom2::RandomInt(this: &clientGame->random, max: this->eventAnimList.num);
        currentState = this->eventAnimSupport.currentState;
        v5 = v9;
        if ( currentState != -1 && currentState == v9 )
        {
          __twllei(num, 0);
          v5 = (v9 + 1) % num;
          __twlgei(num & ~(__ROL4__(v9 + 1, 1) - 1), 0xFFFFFFFF);
        }
      }
      if ( !queue || this->eventAnimSupport.currentState == -1 )
      {
        v11 = this->eventAnimSupport.currentState;
        if ( v11 == -1 )
        {
          Physics = idEntity::GetPhysics(this);
          v14 = (idQuat *)Physics->GetAxis(this: Physics, a2: 0);
          this->eventAnimSupport.orgRotation = *idMat3::ToQuat(this: &v17, result: v14);
          v15 = idEntity::GetPhysics(this);
          v16 = (float *)v15->GetOrigin(this: v15, a2: 0);
          this->eventAnimSupport.orgOrigin.x = *v16;
          this->eventAnimSupport.orgOrigin.y = v16[1];
          z = v16[2];
        }
        else
        {
          idVehicle::LeaveAnimEventState(this, iState: v11);
          this->eventAnimSupport.orgRotation.x = this->eventAnimSupport.nextRotation.x;
          this->eventAnimSupport.orgRotation.y = this->eventAnimSupport.nextRotation.y;
          this->eventAnimSupport.orgRotation.z = this->eventAnimSupport.nextRotation.z;
          this->eventAnimSupport.orgRotation.w = this->eventAnimSupport.nextRotation.w;
          this->eventAnimSupport.orgOrigin.x = this->eventAnimSupport.nextOrigin.x;
          this->eventAnimSupport.orgOrigin.y = this->eventAnimSupport.nextOrigin.y;
          z = this->eventAnimSupport.nextOrigin.z;
        }
        this->eventAnimSupport.orgOrigin.z = z;
        idVehicle::EnterAnimEventState(this, iState: v5, blendTime);
      }
      else
      {
        this->eventAnimSupport.queuedAnimState = v5;
        this->eventAnimSupport.queuedBlendTime = blendTime;
      }
    }
  }
}


// ========================================================================
// ?GotoNextAnimEventState@idVehicle@@QAAXH_N@Z
// EA  : 0x82D29088
// RVA : 0x00D29088
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __fastcall idVehicle::GotoNextAnimEventState(idVehicle *this, unsigned int blendTime, bool queue)
{
  idVehicle::SetAnimEventState(this, animState: this->eventAnimSupport.currentState + 1, blendTime, queue);
}


// ========================================================================
// ?GotoPrevAnimEventState@idVehicle@@QAAXH_N@Z
// EA  : 0x82D290A0
// RVA : 0x00D290A0
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __fastcall idVehicle::GotoPrevAnimEventState(idVehicle *this, unsigned int blendTime, bool queue)
{
  idVehicle::SetAnimEventState(this, animState: this->eventAnimSupport.currentState - 1, blendTime, queue);
}


// ========================================================================
// ?RespawnArmorKit@idVehicle@@AAAXXZ
// EA  : 0x82D292A0
// RVA : 0x00D292A0
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __fastcall idVehicle::RespawnArmorKit(idVehicle *this)
{
  int v2; // r27
  int v3; // r28
  idInventoryAttachmentDef *v4; // r29
  const idDeclJob *inventoryDecl; // r30
  idJobManager *v6; // r3
  idJob *JobByDecl; // r3
  idInventoryItem *v8; // r30
  idVehicle_vtbl *v9; // r29
  int v10; // r3
  idPresentable *presentable; // r30
  const idDeclInventory *v12; // r29
  idInventoryCollection *v13; // r3
  idLobbyBase *v14; // r3
  double mpMaxHealth; // fp0
  int v16; // r30
  bfx::Planner3D *v17; // r3
  idInventoryCollection *v18; // r3
  idInventoryItem *InventoryItem; // r3
  int v20; // r10
  idVehicle::itemSkinRef_t *list; // r9
  int v22; // r11
  bfx::Planner3D *v23; // r3

  v2 = 0;
  if ( this->startingInventory.num > 0 )
  {
    v3 = 0;
    do
    {
      v4 = &this->startingInventory.list[v3];
      inventoryDecl = (const idDeclJob *)v4->inventoryDecl;
      if ( inventoryDecl != nullptr )
      {
        v6 = (idJobManager *)this->GetInventory_2(this);
        JobByDecl = idJobManager::FindJobByDecl(this: v6, jobDecl: inventoryDecl);
        v8 = (idInventoryItem *)JobByDecl;
        if ( JobByDecl != nullptr )
        {
          if ( (unsigned __int8)idDecl::IsType<idDeclVehicleArmorKit>(this: &JobByDecl->decl->idDeclTypeInfo) != 0 )
          {
            v9 = this->__vftable;
            v10 = v8->GetCount(this: v8);
            v9->InventoryAdded(this, a2: v8, a3: v10);
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
          v12 = v4->inventoryDecl;
          v13 = this->GetInventory_2(this);
          idInventoryCollection::GiveItem(
            this: v13,
            owner: presentable,
            decl: v12,
            count: 1,
            forceCount: false,
            canIntro: false);
        }
      }
      ++v2;
      ++v3;
    }
    while ( v2 < this->startingInventory.num );
  }
  if ( common->IsMultiplayer(this: common) )
  {
    v14 = session->GetActingGameStateLobbyBase(this: session);
    if ( v14->GetMatchParms(this: v14)->gameType == 2 )
    {
      mpMaxHealth = this->mpMaxHealth;
      this->health = this->mpMaxHealth;
      this->maxHealth = mpMaxHealth;
      this->maxArmoredHealth = mpMaxHealth;
    }
  }
  idVehicle::RecalcMaxArmoredHealth(this);
  v16 = 0;
  v17 = (bfx::Planner3D *)this->GetInventory_2(this);
  if ( (int)idScriptObject::GetTypeDef(this: v17) > 0 )
  {
    do
    {
      v18 = this->GetInventory_2(this);
      InventoryItem = idInventoryCollection::GetInventoryItem(this: v18, index: v16);
      v20 = 0;
      if ( this->itemSkinList.num > 0 )
      {
        list = this->itemSkinList.list;
        v22 = 0;
        while ( list[v22].declInventory != InventoryItem->decl )
        {
          ++v20;
          ++v22;
          if ( v20 >= this->itemSkinList.num )
            goto LABEL_21;
        }
        InventoryItem->skinPreload = list[v20].declSkin;
      }
LABEL_21:
      ++v16;
      v23 = (bfx::Planner3D *)this->GetInventory_2(this);
    }
    while ( v16 < (int)idScriptObject::GetTypeDef(this: v23) );
  }
}


// ========================================================================
// ?ExitVehicle@idVehicle@@UAA_NH_N0@Z
// EA  : 0x82D294D0
// RVA : 0x00D294D0
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

int __fastcall idVehicle::ExitVehicle(idVehicle *this, unsigned int occupant, bool force, bool thrown)
{
  idPresentable *presentable; // r3
  idPresentableVehicle *v9; // r3
  idPresentable *v11; // r3
  int v12; // r3
  int v13; // r18
  idPresentablePtr<idPresentableActor> *v14; // r31
  idPlayer *v15; // r3
  idPlayer *v16; // r31
  vehicleOccupant_t *v17; // r3
  idPlayer *v18; // r3
  idPlayer *v19; // r3
  idSlowMotionCamera *Control; // r3
  idPresentable *v21; // r3
  idPresentableVehicle *v22; // r3
  idVehicleKey *playerKey; // r25
  idPresentable *v24; // r3
  int v25; // r3
  idPresentable *v26; // r3
  int v27; // r3
  idPresentable *v28; // r3
  int v29; // r3
  idPresentable *v30; // r3
  int v31; // r3
  idWeapon *v32; // r30
  idPresentable *v33; // r3
  int v34; // r3
  idWeapon *v35; // r31
  idFXManager *v36; // r3
  double v37; // fp1
  idPresentable *v38; // r3
  int v39; // r3
  idActor *OccupantAsEntity; // r3
  idPlayer *v41; // r3
  idPlayer *v42; // r24
  idPlayer *v43; // r3
  idPlayer *v44; // r26
  char v45; // r27
  idPhysics *Physics; // r3
  int v47; // r3
  char *v48; // r10
  _DWORD *v49; // r11
  int i; // ctr
  idGameLocal *v51; // r11
  int v52; // r29
  int num; // r8
  double v54; // fp0
  double v55; // fp12
  double v56; // fp10
  int v57; // r30
  idEntityPtr<idInfoGarageBay> *v58; // r3
  idInfoGarageBay *Entity; // r3
  idInfoGarageBay *v60; // r3
  idPhysics *v61; // r3
  const idVec3 *v62; // r3
  idInfoGarageBay *v63; // r3
  idInfoGarageBay *v64; // r3
  idLobbyBase *v65; // r3
  int v66; // r3
  idCamera *onlineVehicleDeathCamera; // r28
  idPlayer *v68; // r3
  idEntity *v69; // r31
  int v70; // r29
  idPlayer *v71; // r3
  idPlayer *v72; // r30
  idPresentable *v73; // r3
  idPresentable *v74; // r3
  int v75; // r31
  idPresentable *v76; // r3
  int v77; // r5
  idVolume_ShowGui_Leveltransition *levelTransitionGuiVolume; // r3
  char v79; // r31
  idPhysics_Player *PhysicsObj; // r3
  double v81; // fp31
  idPhysics *v82; // r3
  vehicleSeat_t v83; // r5
  idLobbyBase *v84; // r3
  idPhysics *v85; // r3
  idPresentable *v86; // r3
  int v87; // r3
  idPresentable *v88; // r3
  int v89; // r3
  idPresentable *v90; // r3
  int v91; // r3
  idPresentable *v92; // r3
  int v93; // r3
  idHandsItem *v94; // r3
  idPresentable *v95; // r3
  int v96; // r3
  idPresentable *v97; // r3
  int v98; // r3
  idPresentable *v99; // r3
  int v100; // r3
  vehicleOccupant_t *v101; // r3
  idEntity *v102; // r31
  idPresentable *v103; // r3
  int v104; // r3
  idPresentable *v105; // r3
  int v106; // r3
  vehicleOccupant_t *v107; // r3
  idPlayer *NpcAsEntity; // r31
  vehicleSeat_t v109; // r5
  int v110; // r28
  int j; // r29
  idPresentable *v112; // r3
  int v113; // r3
  idPresentable *v114; // r3
  int v115; // r3
  int v116; // r11
  idPresentable *v117; // r3
  idVehicleWeapon *v118; // r30
  idPresentableVehicle *v119; // r31
  int *p_weaponSlot; // r30
  idPresentable *v121; // r3
  int v122; // r3
  idPresentable *v123; // r3
  int v124; // r3
  int v125; // r10
  unsigned int v126; // r29
  int v127; // r27
  int v128; // r28
  int value; // r8
  idEntity *v130; // r3
  idAnimated_AnimWeb *v131; // r30
  idEntityPtr<idEntity> *p_exitSnapToEntity; // r11
  idEntity *v133; // r3
  idEntity *v134; // r3
  idPhysics *v135; // r31
  idPhysics *v136; // r26
  idPhysics *v137; // r3
  idPhysics_vtbl *v138; // r31
  const idVec3 *(__fastcall *GetOrigin)(idPhysics *, int); // ctr
  int v140; // r3
  idEntityPtr<idEntity> *v141; // r9
  idEntity *v142; // r3
  idEntity *v143; // r3
  idPhysics *v144; // r31
  idPhysics *v145; // r26
  idPhysics *v146; // r3
  idPhysics_vtbl *v147; // r31
  const idMat3 *(__fastcall *GetAxis)(idPhysics *, int); // ctr
  int v149; // r3
  idPhysics *v150; // r31
  idPhysics *v151; // r26
  idPhysics *v152; // r3
  idPhysics_vtbl *v153; // r31
  const idVec3 *(__fastcall *v154)(idPhysics *, int); // ctr
  int v155; // r3
  idPhysics *v156; // r31
  idPhysics *v157; // r26
  idPhysics *v158; // r3
  idPhysics_vtbl *v159; // r31
  const idMat3 *(__fastcall *v160)(idPhysics *, int); // ctr
  int v161; // r3
  idAnimated_AnimWeb *v162; // r3
  idEntity *v163; // [sp+50h] [-E0h]
  idVec3 v164; // [sp+58h] [-D8h] BYREF
  char v165; // [sp+6Ch] [-C4h] BYREF
  idBounds v166; // [sp+70h] [-C0h] BYREF

  presentable = this->presentable;
  if ( presentable != nullptr )
    v9 = presentable->GetVehicleInterface(this: presentable);
  else
    v9 = nullptr;
  idPresentableVehicle::StopBlurFX(this: v9);
  if ( (((occupant >> 31) + 1) & 1) != 0 )
  {
    v11 = this->presentable;
    v12 = v11 != nullptr ? (int)v11->GetVehicleInterface(this: v11) : 0;
    v13 = 16 * occupant;
    v14 = (idPresentablePtr<idPresentableActor> *)(*(_DWORD *)(v12 + 16472) + 16 * occupant);
    v15 = idPresentablePtr<idPresentable>::IsValid(this: v14)
        ? (idPlayer *)idPresentablePtr<idPresentableProjectile>::operator->(this: (idPresentablePtr<idPresentable> *)v14)->entity
        : nullptr;
    if ( (v16 = idPlayer::CastTo(c: v15), v163 = v16, force)
      || (*(_BYTE *)&idVehicle::GetOccupant(this, i: occupant)->flags & 0x80) != 0 && this->allowExit
      || (v17 = idVehicle::GetOccupant(this, i: occupant),
          v18 = (idPlayer *)vehicleOccupant_t::GetOccupantAsEntity(this: v17),
          (v19 = idPlayer::CastTo(c: v18)) == nullptr)
      || idPlayer::GetNoclip(this: v19) )
    {
      if ( v16 == nullptr
        || (Control = (idSlowMotionCamera *)idPlayer::GetControl(this: v16),
            idSlowMotionCamera::CastTo(c: Control) == nullptr) )
      {
        v21 = this->presentable;
        if ( v21 != nullptr )
          v22 = v21->GetVehicleInterface(this: v21);
        else
          v22 = nullptr;
        idPresentableVehicle::DeactivateCrosshair(this: v22);
        playerKey = nullptr;
        if ( v16 != nullptr )
        {
          v16->lastVehicle.spawnId.value = (gameLocal->spawnIds.ptr[this->entityNumber] << 13) | this->entityNumber;
          idPlayer::ExitedVehicle(this: v16);
          idPlayer::InhibitFire(this: v16, inhibit: true);
          if ( occupant == 0 )
          {
            if ( this->allowAmmoTransfer )
              idVehicle::TransferVehicleAmmoToPlayer(this, player: v16);
            if ( this->allowQuickItemTransfer )
              idVehicle::TransferVehicleQuickItemsToPlayer(this, player: v16);
          }
          v24 = v16->presentable;
          if ( v24 != nullptr )
            v25 = (int)v24->GetPlayerInterface_2(this: v24);
          else
            v25 = 0;
          idView::ResetControllerShake(this: (idView *)(v25 + 16224));
          v26 = v16->presentable;
          if ( v26 != nullptr )
            v27 = (int)v26->GetPlayerInterface_2(this: v26);
          else
            v27 = 0;
          *(float *)(v27 + 19128) = 0.0;
          v28 = v16->presentable;
          if ( v28 != nullptr )
            v29 = (int)v28->GetPlayerInterface_2(this: v28);
          else
            v29 = 0;
          if ( v29 != -37616 )
          {
            v30 = v16->presentable;
            v31 = v30 != nullptr ? (int)v30->GetPlayerInterface_2(this: v30) : 0;
            v32 = idWeapon::CastTo(c: *(idWeapon **)(v31 + 42064));
            if ( v32 != nullptr )
            {
              v33 = v16->presentable;
              if ( v33 != nullptr )
                v34 = (int)v33->GetPlayerInterface_2(this: v33);
              else
                v34 = 0;
              v35 = idWeapon::CastTo(c: *(idWeapon **)(v34 + 42064));
              v36 = (idFXManager *)((int (__fastcall *)(idEntity *, idWeapon *))v163->__vftable[1].GetColor_3)(
                                     a1: v163,
                                     a2: v32);
              idWeapon::SetZoomed(this: v35, zoomed: false, fxMgr: v36);
            }
          }
          if ( this->playerKey != nullptr )
          {
            v37 = ((double (__fastcall *)(idVehicle *))this->GetHealth)(a1: this);
            idVehicleKey::SetHealth(this: this->playerKey, h: v37);
            playerKey = this->playerKey;
            this->playerKey = nullptr;
          }
        }
        if ( occupant == 0 )
          mediaPlayer->Pause(this: mediaPlayer);
        v38 = this->presentable;
        if ( v38 != nullptr )
          v39 = (int)v38->GetVehicleInterface(this: v38);
        else
          v39 = 0;
        OccupantAsEntity = (idActor *)vehicleOccupant_t::GetOccupantAsEntity(this: (vehicleOccupant_t *)(*(_DWORD *)(v39 + 16472) + v13));
        v41 = (idPlayer *)idActor::CastTo(c: OccupantAsEntity);
        v42 = v41;
        if ( v41 == nullptr )
          goto LABEL_131;
        v43 = idPlayer::CastTo(c: v41);
        v44 = v43;
        if ( v43 == nullptr )
          goto LABEL_94;
        *(_BYTE *)&v43->flags |= 2u;
        if ( gameLocal->world->mapType != MAPTYPE_OUTDOOR )
          goto LABEL_74;
        if ( this->health <= 0.0 )
          goto LABEL_73;
        v45 = 0;
        Physics = idEntity::GetPhysics(this);
        v47 = (int)Physics->GetAbsBounds(this: Physics, a2: -1);
        v48 = &v165;
        v49 = (_DWORD *)(v47 - 4);
        for ( i = 6; i != 0; --i )
        {
          ++v49;
          v48 += 4;
          *(_DWORD *)v48 = *v49;
        }
        v51 = gameLocal;
        v52 = 0;
        num = gameLocal->infoGarageBays.num;
        v54 = (float)(v166.b[1].x + (float)((float)(v166.b[1].x - v166.b[0].x) * (float)0.5));
        v166.b[0].x = v166.b[0].x - (float)((float)(v166.b[1].x - v166.b[0].x) * (float)0.5);
        v166.b[1].x = v54;
        v55 = (float)(v166.b[1].y + (float)((float)(v166.b[1].y - v166.b[0].y) * (float)0.5));
        v166.b[0].y = v166.b[0].y - (float)((float)(v166.b[1].y - v166.b[0].y) * (float)0.5);
        v166.b[1].y = v55;
        v56 = (float)(v166.b[1].z + (float)((float)(v166.b[1].z - v166.b[0].z) * (float)0.5));
        v166.b[0].z = v166.b[0].z - (float)((float)(v166.b[1].z - v166.b[0].z) * (float)0.5);
        v166.b[1].z = v56;
        if ( num <= 0 )
          goto LABEL_72;
        v57 = 0;
        while ( 1 )
        {
          v58 = &v51->infoGarageBays.list[v57];
          if ( v51->spawnIds.ptr[v58->spawnId.value & 0x1FFF] == v58->spawnId.value >> 13 )
            break;
LABEL_66:
          ++v52;
          ++v57;
          if ( v52 >= v51->infoGarageBays.num )
            goto LABEL_72;
        }
        Entity = idEntityPtr<idInfoGarageBay>::GetEntity(this: v58);
        if ( idInfoGarageBay::GetVehicle(this: Entity) != nullptr
          || (v60 = idEntityPtr<idInfoGarageBay>::GetEntity(this: &gameLocal->infoGarageBays.list[v57]),
              v61 = idEntity::GetPhysics(this: v60),
              v62 = v61->GetOrigin(this: v61, a2: 0),
              (unsigned __int8)idBounds::ContainsPoint(this: &v166, p: v62) == 0)
          || (v63 = idEntityPtr<idInfoGarageBay>::GetEntity(this: &gameLocal->infoGarageBays.list[v57]),
              !idPlayer::SetVehicleInfo(this: v44, vehicle: this, garage: v63->garage, markForGarageView: false)) )
        {
          v51 = gameLocal;
          goto LABEL_66;
        }
        v45 = 1;
        idEntityPtr<idInfoGarageBay>::GetEntity(this: &gameLocal->infoGarageBays.list[v52])->vehicle.spawnId.value = (gameLocal->spawnIds.ptr[this->entityNumber] << 13) | this->entityNumber;
        if ( playerKey != nullptr )
        {
          v64 = idEntityPtr<idInfoGarageBay>::GetEntity(this: &gameLocal->infoGarageBays.list[v52]);
          if ( v64 != nullptr )
            playerKey->garageBay.spawnId.value = (gameLocal->spawnIds.ptr[v64->entityNumber] << 13) | v64->entityNumber;
          else
            playerKey->garageBay.spawnId.value = 0x1FFF;
        }
LABEL_72:
        if ( v45 == 0 )
LABEL_73:
          idPlayer::SetVehicleInfo(this: v44, vehicle: this, garage: GARAGE_NONE, markForGarageView: false);
LABEL_74:
        if ( common->IsMultiplayer(this: common)
          && (v65 = session->GetActingGameStateLobbyBase(this: session), v65->GetMatchParms(this: v65)->gameType == 2)
          && (v66 = (int)v44->GetVehicle_2(this: v44),
              (*(unsigned __int8 (__fastcall **)(int))(*(_DWORD *)v66 + 508))(a1: v66) != 0) )
        {
          onlineVehicleDeathCamera = v44->onlineVehicleDeathCamera;
          v68 = (idPlayer *)idEntityPtr<idEntity const>::operator->(this: &this->lastDamage.attacker);
          v69 = v68;
          v70 = 0;
          if ( v68 != nullptr )
          {
            v71 = idPlayer::CastTo(c: v68);
            v72 = v71;
            if ( v71 == nullptr )
              goto LABEL_81;
            if ( v71->GetVehicle_2(this: v71) != nullptr )
            {
              v69 = v72->GetVehicle_2(this: v72);
LABEL_81:
              v73 = v69->presentable;
              if ( v73 == nullptr )
              {
                idEntity::InitPresentableInternal(this: v69);
                v73 = v69->presentable;
              }
              v70 = (int)v73->GetVehicleInterface(this: v73);
            }
          }
          v74 = v44->presentable;
          if ( v74 != nullptr )
            v75 = (int)v74->GetPlayerInterface_2(this: v74);
          else
            v75 = 0;
          v76 = this->presentable;
          if ( v76 != nullptr )
            v77 = (int)v76->GetVehicleInterface(this: v76);
          else
            v77 = 0;
          ((void (__fastcall *)(idCamera *, int, int, int))onlineVehicleDeathCamera->__vftable[1].dtr_idClass)(
            a1: onlineVehicleDeathCamera,
            a2: v70,
            a3: v77,
            a4: v75);
          idCamera::Activate(this: onlineVehicleDeathCamera, activator_: v44);
          idPlayer::AddControl(this: v44, entity: onlineVehicleDeathCamera);
        }
        else
        {
          idPlayer::RemoveControl(this: v44, entity: this);
        }
        levelTransitionGuiVolume = v44->levelTransitionGuiVolume;
        if ( levelTransitionGuiVolume != nullptr )
          idVolume_ShowGui_Leveltransition::RemovePlayer(this: levelTransitionGuiVolume, player: v44);
LABEL_94:
        v79 = (_cntlzw(thrown) & 0x20) != 0;
        idEntity::Unbind(this: v42);
        if ( v44 != nullptr )
        {
          PhysicsObj = idPlayer::GetPhysicsObj(this: v44);
          idPhysics_Player::SetMovementType(this: PhysicsObj, type: PM_VEHICLE_NOCLIP);
        }
        v81 = 0.0;
        v164 = vec3_origin;
        if ( (unsigned __int8)idVehicle::IsOnElevator(this) != 0 )
        {
          v82 = idEntity::GetPhysics(this);
          v82->GetLinearVelocity(this: (idPhysics *)&v166, result: (idVec3 *)v82, a3: 0);
          if ( v166.b[0].z < 0.0 )
          {
            v164.z = v166.b[0].z;
            v81 = (float)(v166.b[0].z * (float)0.1);
          }
        }
        if ( ((double (__fastcall *)(idVehicle *))this->GetHealth)(a1: this) <= 0.0 )
        {
          if ( common->IsMultiplayer(this: common) )
          {
            v84 = session->GetActingGameStateLobbyBase(this: session);
            v79 = v84->GetMatchParms(this: v84)->gameType == 2 ? 0 : v79;
          }
        }
        else
        {
          idVehicle::SetExitPosition(this, entity: v42, zOffset: v81, seat: v83, a5: occupant);
        }
        v85 = idEntity::GetPhysics(this: v42);
        v85->SetLinearVelocity(this: v85, a2: &v164, a3: 0);
        v42->Show(this: v42);
        if ( v79 != 0 )
        {
          if ( v44 != nullptr )
          {
            v86 = v44->presentable;
            v87 = v86 != nullptr ? (int)v86->GetPlayerInterface_2(this: v86) : 0;
            if ( v87 != -37616 )
            {
              v88 = v44->presentable;
              if ( v88 != nullptr )
                v89 = (int)v88->GetPlayerInterface_2(this: v88);
              else
                v89 = 0;
              idHands::ClearPendingAction(this: (idHands *)(v89 + 37616));
              v90 = v44->presentable;
              if ( v90 != nullptr )
                v91 = (int)v90->GetPlayerInterface_2(this: v90);
              else
                v91 = 0;
              idHands::Show(this: (idHands *)(v91 + 37616), hideReason: HAND_HIDE_VEHICLE);
              v92 = v44->presentable;
              if ( v92 != nullptr )
              {
                v93 = (int)v92->GetPlayerInterface_2(this: v92);
                v94 = idHands::ItemForSlot(this: (idHands *)(v93 + 37616), slot: EQUIP_RIGHT_HAND);
              }
              else
              {
                v94 = idHands::ItemForSlot(this: (idHands *)0x92F0, slot: EQUIP_RIGHT_HAND);
              }
              idHandsItem::StopVideo(this: v94);
            }
          }
        }
        else if ( v44 != nullptr )
        {
          v95 = v44->presentable;
          v96 = v95 != nullptr ? (int)v95->GetPlayerInterface_2(this: v95) : 0;
          if ( v96 != -37616 )
          {
            v97 = v44->presentable;
            if ( v97 != nullptr )
              v98 = (int)v97->GetPlayerInterface_2(this: v97);
            else
              v98 = 0;
            idHands::ClearPendingAction(this: (idHands *)(v98 + 37616));
            v99 = v44->presentable;
            if ( v99 != nullptr )
              v100 = (int)v99->GetPlayerInterface_2(this: v99);
            else
              v100 = 0;
            idHands::Hide(this: (idHands *)(v100 + 37616), hideReason: HAND_HIDE_VEHICLE);
          }
        }
LABEL_131:
        if ( thrown )
        {
          v101 = idVehicle::GetOccupant(this, i: occupant);
          v102 = vehicleOccupant_t::GetOccupantAsEntity(this: v101);
        }
        else
        {
          v102 = nullptr;
        }
        v103 = this->presentable;
        if ( v103 != nullptr )
          v104 = (int)v103->GetVehicleInterface(this: v103);
        else
          v104 = 0;
        *(_DWORD *)(*(_DWORD *)(v104 + 16472) + 16 * occupant) = 0;
        idVehicle::VisualExitVehicle(this, seat: occupant, delayTime: 0, thrownEntity: v102);
        v105 = this->presentable;
        if ( v105 != nullptr )
          v106 = (int)v105->GetVehicleInterface(this: v105);
        else
          v106 = 0;
        if ( vehicleOccupant_t::GetNpcAsEntity(this: (vehicleOccupant_t *)(*(_DWORD *)(v106 + 16472) + v13)) != nullptr )
        {
          v107 = idVehicle::GetOccupant(this, i: occupant);
          NpcAsEntity = (idPlayer *)vehicleOccupant_t::GetNpcAsEntity(this: v107);
          idEntity::Unbind(this: NpcAsEntity);
          idVehicle::SetExitPosition(this, entity: NpcAsEntity, zOffset: 0.0, seat: v109, a5: occupant);
          NpcAsEntity->Show(this: NpcAsEntity);
          idVehicle::GetOccupant(this, i: occupant)->npc.spawnId = 0;
        }
        if ( occupant == 1 )
        {
          v110 = 0;
          for ( j = 0; ; j += 4 )
          {
            v112 = this->presentable;
            v113 = v112 != nullptr ? (int)v112->GetVehicleInterface(this: v112) : 0;
            if ( v110 >= *(_DWORD *)(v113 + 18748) )
              break;
            v114 = this->presentable;
            if ( v114 != nullptr )
              v115 = (int)v114->GetVehicleInterface(this: v114);
            else
              v115 = 0;
            v116 = *(_DWORD *)(v115 + 18744);
            v117 = this->presentable;
            v118 = *(idVehicleWeapon **)(v116 + j);
            if ( v117 != nullptr )
              v119 = v117->GetVehicleInterface(this: v117);
            else
              v119 = nullptr;
            p_weaponSlot = &idVehicleWeapon::GetDeclVehicleWeapon(this: v118)->weaponSlot;
            if ( *p_weaponSlot == idPresentableVehicle::GetCurrentWeaponGroup(this: v119) )
            {
              v121 = this->presentable;
              if ( v121 != nullptr )
                v122 = (int)v121->GetVehicleInterface(this: v121);
              else
                v122 = 0;
              idVehicleWeapon::PlayAnim(
                this: *(idVehicleWeapon **)(*(_DWORD *)(v122 + 18744) + j),
                anim: VW_ANIM_GUNNER_EXIT);
            }
            v123 = this->presentable;
            if ( v123 != nullptr )
              v124 = (int)v123->GetVehicleInterface(this: v123);
            else
              v124 = 0;
            ++v110;
            v125 = *(_DWORD *)(*(_DWORD *)(v124 + 18744) + j);
            *(_BYTE *)(v125 + 257) = 1;
          }
        }
        v126 = occupant;
        v127 = 0;
        if ( this->seatInfo.list[occupant].exitAnim.num > 0 )
        {
          v128 = 0;
          do
          {
            value = this->seatInfo.list[v126].exitAnim.list[v128].spawnId.value;
            if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
            {
              v130 = gameLocal->entities.ptr[this->seatInfo.list[v126].exitAnim.list[v128].spawnId.value & 0x1FFF];
              if ( v130 != nullptr )
              {
                v131 = (idAnimated_AnimWeb *)idEntity::CastTo(c: v130);
                if ( v131 != nullptr )
                {
                  p_exitSnapToEntity = &this->seatInfo.list[v126].exitSnapToEntity;
                  if ( gameLocal->spawnIds.ptr[p_exitSnapToEntity->spawnId.value & 0x1FFF] == p_exitSnapToEntity->spawnId.value >> 13 )
                  {
                    v133 = gameLocal->entities.ptr[p_exitSnapToEntity->spawnId.value & 0x1FFF];
                    v134 = v133 != nullptr ? idEntity::CastTo(c: v133) : nullptr;
                    v135 = idEntity::GetPhysics(this: v134);
                    v136 = idEntity::GetPhysics(this: v131);
                    v137 = v135;
                    GetOrigin = v135->GetOrigin;
                    v138 = v136->__vftable;
                    v140 = (int)GetOrigin(this: v137, a2: 0);
                    v138->SetOrigin(this: v136, a2: (const idVec3 *)v140, a3: -1);
                    v141 = &this->seatInfo.list[v126].exitSnapToEntity;
                    if ( gameLocal->spawnIds.ptr[v141->spawnId.value & 0x1FFF] != v141->spawnId.value >> 13 )
                      goto LABEL_175;
                    v142 = gameLocal->entities.ptr[v141->spawnId.value & 0x1FFF];
                    if ( v142 != nullptr )
                      v143 = idEntity::CastTo(c: v142);
                    else
LABEL_175:
                      v143 = nullptr;
                    v144 = idEntity::GetPhysics(this: v143);
                    v145 = idEntity::GetPhysics(this: v131);
                    v146 = v144;
                    GetAxis = v144->GetAxis;
                    v147 = v145->__vftable;
                    v149 = (int)GetAxis(this: v146, a2: 0);
                    v147->SetAxis(this: v145, a2: (const idMat3 *)v149, a3: -1);
                  }
                  else
                  {
                    v150 = idEntity::GetPhysics(this);
                    v151 = idEntity::GetPhysics(this: v131);
                    v152 = v150;
                    v154 = v150->GetOrigin;
                    v153 = v151->__vftable;
                    v155 = (int)v154(this: v152, a2: 0);
                    v153->SetOrigin(this: v151, a2: (const idVec3 *)v155, a3: -1);
                    v156 = idEntity::GetPhysics(this);
                    v157 = idEntity::GetPhysics(this: v131);
                    v158 = v156;
                    v160 = v156->GetAxis;
                    v159 = v157->__vftable;
                    v161 = (int)v160(this: v158, a2: 0);
                    v159->SetAxis(this: v157, a2: (const idMat3 *)v161, a3: -1);
                  }
                  idEntity::Activate(this: v131, activator: v163);
                  v131->Show(this: v131);
                  v162 = idAnimated_AnimWeb::CastTo(c: v131);
                  if ( v162 != nullptr )
                    v162->ChangeAnimWebStateVia_2(
                      this: v162,
                      a2: this->seatInfo.list[v126].exitViaAnimRefStr.data,
                      a3: this->seatInfo.list[v126].exitDstAnimRefStr.data);
                }
              }
            }
            ++v127;
            ++v128;
          }
          while ( v127 < this->seatInfo.list[v126].exitAnim.num );
        }
        idVehicle::UpdateEventInstigators(this);
        return 1;
      }
    }
  }
  return 0;
}


// ========================================================================
// ?VisualEnterVehicle@idVehicle@@QAAXH@Z
// EA  : 0x82D2A4A0
// RVA : 0x00D2A4A0
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __fastcall idVehicle::VisualEnterVehicle(idVehicle *this, int seat)
{
  idPlayer *OccupantAsEntity; // r3
  idPlayer *v5; // r3
  idPlayer *v6; // r31
  bool v7; // r11
  idTreeAnimator *TreeAnimatorFromPresentable; // r25
  idPresentable *presentable; // r3
  idVehicle::seatInfo_t *v10; // r11
  char *data; // r26
  int WeaponControlIndex; // r3
  idVehicleWeapon *Weapon; // r3
  idVehicleWeapon *v14; // r30
  idPresentable *v15; // r3
  const idDeclEntityDef *passengerOccupantDef; // r4
  idVehicleOccupant *v17; // r3
  idEntity *v18; // r31
  idVehicleOccupant *v19; // r3
  idVehicleOccupant *v20; // r30
  idPresentable *v21; // r31
  vehicleOccupant_t *Occupant; // r3
  unsigned int spawnId; // r10
  idPresentable *v24; // r3
  int v25; // r3
  vehicleOccupant_t *v26; // r3
  idVehicleOccupant *VisualAsEntity; // r3

  OccupantAsEntity = (idPlayer *)idVehicle::GetOccupantAsEntity(this, index: seat);
  v5 = idPlayer::CastTo(c: OccupantAsEntity);
  v6 = v5;
  v7 = true;
  if ( seat == 1 && v5 != nullptr )
    v7 = vehicle_gunner_model_test.valueInteger != 0;
  if ( v7 )
  {
    TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
    presentable = this->presentable;
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      presentable = this->presentable;
    }
    idPresentable::UpdateModelTransform(this: presentable);
    v10 = &this->seatInfo.list[seat];
    data = v10->tagName.data;
    if ( v10->weaponAttach )
    {
      WeaponControlIndex = idVehicle::GetWeaponControlIndex(this);
      Weapon = idVehicle::GetWeapon(this, num: WeaponControlIndex);
      TreeAnimatorFromPresentable = Weapon->treeAnimator;
      v14 = Weapon;
      v15 = idVehicleWeapon::GetPresentable(this: Weapon);
      idPresentable::UpdateModelTransform(this: v15);
      data = idVehicleWeapon::GetDeclVehicleWeapon(this: v14)->npcSeatWeapon.data;
    }
    if ( seat != 0 )
      passengerOccupantDef = this->passengerOccupantDef;
    else
      passengerOccupantDef = this->occupantDef;
    if ( v6 != nullptr )
    {
      if ( this->vehicleClass == VEHICLE_CLASS1 )
        passengerOccupantDef = v6->playerDriver[0];
      else
        passengerOccupantDef = v6->playerDriver[1];
    }
    if ( passengerOccupantDef != nullptr )
    {
      v17 = (idVehicleOccupant *)gameLocal->SpawnEntityFromDef(
                                   this: gameLocal,
                                   a2: passengerOccupantDef,
                                   a3: -1,
                                   a4: -1,
                                   a5: -1);
      v18 = v17;
      if ( v17 != nullptr )
      {
        v19 = idVehicleOccupant::CastTo(c: v17);
        v20 = v19;
        if ( v19 != nullptr )
        {
          v21 = v19->presentable;
          if ( v21 == nullptr )
          {
            idEntity::InitPresentableInternal(this: v19);
            v21 = v20->presentable;
          }
          Occupant = idVehicle::GetOccupant(this, i: seat);
          spawnId = 0;
          if ( v21 != nullptr )
            spawnId = v21->spawnId;
          Occupant->visual.spawnId = spawnId;
        }
        else
        {
          gameLocal->DeleteEntity(this: gameLocal, a2: v18);
        }
      }
    }
    v24 = this->presentable;
    if ( v24 != nullptr )
      v25 = (int)v24->GetVehicleInterface(this: v24);
    else
      v25 = 0;
    if ( vehicleOccupant_t::GetVisualAsEntity(this: (vehicleOccupant_t *)(*(_DWORD *)(v25 + 16472) + 16 * seat)) != nullptr )
    {
      v26 = idVehicle::GetOccupant(this, i: seat);
      VisualAsEntity = vehicleOccupant_t::GetVisualAsEntity(this: v26);
      idVehicleOccupant::EnterVehicle(
        this: VisualAsEntity,
        vehicle: this,
        tagAnimator: TreeAnimatorFromPresentable,
        tagName: data);
    }
  }
}


// ========================================================================
// ?ThrowActor@idVehicle@@QAAXPAVidActor@@VidVec3@@1@Z
// EA  : 0x82D2A6A8
// RVA : 0x00D2A6A8
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idVehicle::ThrowActor(idVehicle *this, idPlayer *actor, idVec3 *velocity, __int64 angularVelocity)
{
  idPhysics *Physics; // r3
  float *v7; // r3
  double v8; // fp13
  double v9; // fp12
  int OccupantNum; // r29
  idVehicleOccupant *OccupantVisual; // r31
  idPlayer *v12; // r3
  idPlayer *v13; // r26
  int v14; // r27
  idPhysics *v15; // r3
  float *v16; // r3
  float v17; // r7
  double v18; // fp11
  __int64 v19; // r9
  double v20; // fp10
  unsigned int v21; // r6
  double v22; // fp28
  double v23; // fp27
  double v24; // fp26
  int v25; // r3
  int v26; // r3
  __int64 v27; // r4
  unsigned int v28; // r9
  int v29; // r29
  double v30; // fp31
  double v31; // fp30
  double i; // fp29
  idAFBody *Body; // r3
  int entityNumber; // r11
  idThrownCamera *thrownCamera; // r31
  idPhysics *v36; // r30
  idPresentable *presentable; // r11
  double valueFloat; // fp31
  int v39; // r11
  int v40; // r3
  __int128 v41; // r7 OVERLAPPED
  int v42; // r10 OVERLAPPED
  __int64 v43; // r9
  __int64 v44; // [sp+8h] [-108h]
  __int64 v45; // [sp+10h] [-100h]
  __int64 v46; // [sp+18h] [-F8h]
  __int64 v47; // [sp+20h] [-F0h]
  __int64 v48; // [sp+28h] [-E8h]
  __int64 v49; // [sp+30h] [-E0h]
  __int64 v50; // [sp+38h] [-D8h]
  __int64 v51; // [sp+40h] [-D0h]
  __int64 v52; // [sp+48h] [-C8h]
  __int64 v53; // [sp+50h] [-C0h]
  idVec3 *v54; // [sp+64h] [-ACh]
  float v55; // [sp+70h] [-A0h] BYREF
  float v56; // [sp+74h] [-9Ch]
  float v57; // [sp+78h] [-98h]
  float v58[18]; // [sp+80h] [-90h] BYREF
  float v60; // [sp+148h] [+38h]

  v60 = *((float *)&angularVelocity + 1);
  v55 = vehicle_throwScale.valueFloat * *(float *)&actor;
  v56 = *(float *)&velocity * vehicle_throwScale.valueFloat;
  v57 = v56;
  Physics = idEntity::GetPhysics(this);
  v7 = (float *)Physics->GetAxis(this: Physics, a2: 0);
  v8 = (float)(v7[7] * vehicle_throwUpMin.valueFloat);
  v9 = (float)(v7[8] * vehicle_throwUpMin.valueFloat);
  v55 = (float)(v7[6] * vehicle_throwUpMin.valueFloat) + v55;
  v57 = (float)v9 + v56;
  v56 = (float)v8 + v56;
  OccupantNum = idVehicle::GetOccupantNum(this, entity: actor);
  OccupantVisual = idVehicle::GetOccupantVisual(this, index: OccupantNum);
  this->ExitVehicle(this, a2: OccupantNum, a3: true, a4: true);
  v12 = idPlayer::CastTo(c: actor);
  v13 = v12;
  if ( v12 != nullptr )
  {
    idVehicleOccupant::StartThrow(this: OccupantVisual, player: v12);
    idVehicleOccupant::StartRagdoll(this: OccupantVisual);
    v14 = (int)OccupantVisual->GetAF_2(this: OccupantVisual);
    if ( v14 != 0 )
    {
      v15 = idEntity::GetPhysics(this);
      v16 = (float *)v15->GetAxis(this: v15, a2: 0);
      v17 = v16[5];
      v18 = v16[3];
      HIDWORD(v19) = clientGame->random.seed;
      v20 = v16[4];
      v21 = 1664525 * clientGame->random.seed;
      clientGame->random.seed = v21 + 1013904223;
      LODWORD(v19) = ((v21 + 1013904223) >> 10) & 0x7FFF;
      v22 = (float)((float)v18
                  * (float)((float)((float)((float)v19 * vehicle_throwBodyMaxAngularVel.valueFloat) * (float)3.1415927)
                          * (float)0.000030518509));
      v23 = (float)((float)v20
                  * (float)((float)((float)((float)v19 * vehicle_throwBodyMaxAngularVel.valueFloat) * (float)3.1415927)
                          * (float)0.000030518509));
      v24 = (float)(v17
                  * (float)((float)((float)((float)v19 * vehicle_throwBodyMaxAngularVel.valueFloat) * (float)3.1415927)
                          * (float)0.000030518509));
      v25 = (int)OccupantVisual->GetAF_2(this: OccupantVisual);
      (*(void (__fastcall **)(int, float *, _DWORD))(*(_DWORD *)(v25 + 288) + 80))(a1: v25 + 288, a2: &v55, a3: 0);
      v26 = (int)OccupantVisual->GetAF_2(this: OccupantVisual);
      v58[0] = *(float *)&angularVelocity + (float)v22;
      v58[1] = *((float *)&angularVelocity + 1) + (float)v23;
      v58[2] = v60 + (float)v24;
      HIDWORD(v27) = (*(int (__fastcall **)(int, float *, _DWORD))(*(_DWORD *)(v26 + 288) + 84))(
                       a1: v26 + 288,
                       a2: v58,
                       a3: 0);
      v28 = 1664525 * clientGame->random.seed;
      clientGame->random.seed = v28 + 1013904223;
      LODWORD(v27) = ((v28 + 1013904223) >> 10) & 0x7FFF;
      v29 = 1;
      v55 = (float)((float)(v55 * (float)((float)((float)((float)v27 * (float)0.000030518509) - (float)0.5) * (float)2.0))
                  * vehicle_throwBodyForceScale.valueFloat)
          + v55;
      v56 = (float)((float)(v56 * (float)((float)((float)((float)v27 * (float)0.000030518509) - (float)0.5) * (float)2.0))
                  * vehicle_throwBodyForceScale.valueFloat)
          + v56;
      v57 = (float)((float)(v57 * (float)((float)((float)((float)v27 * (float)0.000030518509) - (float)0.5) * (float)2.0))
                  * vehicle_throwBodyForceScale.valueFloat)
          + v57;
      v30 = (float)((float)((float)((float)(*(float *)&angularVelocity
                                          * (float)((float)((float)((float)v27 * (float)0.000030518509) - (float)0.5)
                                                  * (float)2.0))
                                  * vehicle_throwBodyForceScale.valueFloat)
                          + (float)v22)
                  + *(float *)&angularVelocity);
      v31 = (float)((float)((float)((float)(*((float *)&angularVelocity + 1)
                                          * (float)((float)((float)((float)v27 * (float)0.000030518509) - (float)0.5)
                                                  * (float)2.0))
                                  * vehicle_throwBodyForceScale.valueFloat)
                          + (float)v23)
                  + *((float *)&angularVelocity + 1));
      for ( i = (float)((float)((float)((float)(v60
                                              * (float)((float)((float)((float)v27 * (float)0.000030518509) - (float)0.5)
                                                      * (float)2.0))
                                      * vehicle_throwBodyForceScale.valueFloat)
                              + (float)v24)
                      + v60);
            v29 < (int)XAUDIO2::CX2SubmixVoice::ProcessingStage(this: (XAUDIO2::CX2SubmixVoice *)(v14 + 288));
            Body->current.spatialVelocity.p[5] = i )
      {
        Body = idPhysics_AF::GetBody(this: (idPhysics_AF *)(v14 + 288), id: v29++);
        Body->current.spatialVelocity.p[0] = v55;
        Body->current.spatialVelocity.p[1] = v56;
        Body->current.spatialVelocity.p[2] = v57;
        Body->current.spatialVelocity.p[3] = v30;
        Body->current.spatialVelocity.p[4] = v31;
      }
    }
    idPlayer::HideTutorialGui(this: v13);
    entityNumber = OccupantVisual->entityNumber;
    thrownCamera = v13->thrownCamera;
    thrownCamera->target.spawnId.value = (gameLocal->spawnIds.ptr[entityNumber] << 13) | entityNumber;
    v36 = idEntity::GetPhysics(this);
    presentable = this->presentable;
    valueFloat = vehicle_throwCameraTime.valueFloat;
    if ( presentable != nullptr )
      v39 = (int)presentable->GetVehicleInterface(this: this->presentable);
    else
      v39 = 0;
    v54 = *(idVec3 **)(v39 + 18868);
    v40 = (int)v36->GetAxis(this: v36, a2: 0);
    *(_QWORD *)((char *)&v41 + 4) = *(_QWORD *)v40;
    v42 = __ROL4__(*(_DWORD *)(v40 + 32), 32);
    *((_QWORD *)&v41 + 1) = *(_QWORD *)(v40 + 8);
    *(_QWORD *)((char *)&v41 - 4) = *(_QWORD *)(v40 + 16);
    v43 = *(_QWORD *)(v40 + 24);
    idThrownCamera::Init(
      this: thrownCamera,
      origin: v54,
      axis: *(__int64 *)((char *)&v41 + 4),
      inCameraFollowTime: valueFloat,
      a5: *(__int64 *)((char *)&v41 - 4),
      a6: *(__int64 *)&v42,
      a7: v44,
      a8: v45,
      a9: v46,
      a10: v47,
      a11: v48,
      a12: v49,
      a13: v50,
      a14: v51,
      a15: v52,
      a16: v53);
    idCamera::Activate(this: thrownCamera, activator_: v13);
  }
}


// ========================================================================
// ?EnterVehicle@idVehicle@@UAA_NPAVidEntity@@W4vehicleSeat_t@@@Z
// EA  : 0x82D2AB48
// RVA : 0x00D2AB48
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

int __fastcall idVehicle::EnterVehicle(idVehicle *this, idActor *other, int wantSeat)
{
  idPlayer *v6; // r26
  idPlayer *v7; // r21
  idPresentablePtr<idPresentableActor> *Occupant; // r3
  int valueInteger; // r9
  vehicleSeat_t v10; // r20
  int v11; // r28
  int v12; // r29
  int i; // r30
  idPresentable *presentable; // r3
  int v15; // r3
  idInventoryCollection *v17; // r3
  idPresentable *v18; // r3
  int v19; // r3
  idInventoryCollection *v20; // r3
  int v21; // r10
  idVehicleKey **list; // r11
  idPresentable *v23; // r3
  int currentWeaponGroup; // r30
  idPresentableVehicle *v25; // r3
  idPresentable *v26; // r3
  idPresentableVehicle *v27; // r3
  idPresentable *v28; // r3
  idPresentableVehicle *v29; // r3
  idVehicleKey *playerKey; // r11
  const idDeclJob *decl; // r30
  idJobManager *v32; // r3
  char v33; // r30
  char v34; // r11
  char v35; // r30
  char v36; // r11
  idPresentable *v37; // r3
  idPresentableVehicle *v38; // r3
  idPresentable *v39; // r30
  idPresentable *v40; // r3
  int v41; // r3
  int v42; // r11
  int v43; // r29
  idPresentable *v44; // r3
  int v45; // r3
  idPresentable *v46; // r3
  int v47; // r3
  idPhysics *Physics; // r3
  float *v49; // r3
  idPhysics *v50; // r3
  idPresentable *v51; // r3
  int v52; // r3
  idPhysics *v53; // r3
  idAngles *v54; // r3
  idPresentable *v55; // r3
  idPresentableVehicle *v56; // r3
  idPlayer *Gunner; // r3
  idPresentable *v58; // r3
  int v59; // r3
  idPresentable *v60; // r3
  int v61; // r3
  idPresentable *v62; // r3
  int v63; // r3
  idPresentable *v64; // r3
  int v65; // r3
  idPresentable *v66; // r3
  idPresentableVehicle *v67; // r3
  idPresentable *Driver; // r3
  idPresentable *v69; // r3
  idPresentableVehicle *v70; // r3
  idPhysics *v71; // r3
  idAngles *v72; // r3
  idPhysics *v73; // r3
  idAngles *v74; // r3
  idPresentable *v75; // r3
  idPresentableVehicle *v76; // r3
  idThirdPersonCrosshair *Crosshair; // r3
  idPresentable *v78; // r3
  idPresentableVehicle *v79; // r3
  idThirdPersonCrosshair *v80; // r3
  float z; // r11
  float y; // r10
  float x; // r9
  idPresentable *v84; // r3
  int v85; // r3
  int v86; // r6
  int v87; // r10
  int num; // r7
  int v89; // r11
  idVehicle::seatInfo_t *v90; // r9
  char v91; // r30
  idPresentable *v92; // r3
  int v93; // r3
  idPresentable *v94; // r3
  int v95; // r3
  int v96; // r27
  int j; // r28
  idPresentable *v98; // r3
  int v99; // r3
  idPresentable *v100; // r3
  int v101; // r3
  int v102; // r11
  idPresentable *v103; // r3
  idVehicleWeapon *v104; // r29
  idPresentableVehicle *v105; // r30
  int *p_weaponSlot; // r29
  idPresentable *v107; // r3
  int v108; // r3
  idPresentable *v109; // r3
  int v110; // r3
  int v111; // r8
  vehicleSeat_t v112; // r28
  int v113; // r26
  int v114; // r27
  int value; // r8
  idEntity *v116; // r3
  idAnimated_AnimWeb *v117; // r30
  idPhysics *v118; // r29
  idPhysics *v119; // r23
  idPhysics *v120; // r3
  idPhysics_vtbl *v121; // r29
  const idVec3 *(__fastcall *GetOrigin)(idPhysics *, int); // ctr
  int v123; // r3
  idPhysics *v124; // r29
  idPhysics *v125; // r23
  idPhysics *v126; // r3
  idPhysics_vtbl *v127; // r29
  const idMat3 *(__fastcall *GetAxis)(idPhysics *, int); // ctr
  int v129; // r3
  idAnimated_AnimWeb *v130; // r3
  idPresentable *v131; // r3
  idPresentableVehicle *v132; // r3
  unsigned int v133; // r11
  idList<idVehicleState *,5> v134; // [sp+60h] [-150h] BYREF
  idMat3 v135; // [sp+70h] [-140h] BYREF
  __int16 v136; // [sp+94h] [-11Ch]
  char v137; // [sp+96h] [-11Ah]
  char v138; // [sp+97h] [-119h]
  char v139; // [sp+98h] [-118h]
  char v140; // [sp+99h] [-117h]
  __int16 v141; // [sp+9Ah] [-116h]
  __int16 v142; // [sp+9Ch] [-114h]
  __int16 v143; // [sp+9Eh] [-112h]
  int v144; // [sp+A0h] [-110h]
  float v145; // [sp+A4h] [-10Ch]
  float v146; // [sp+A8h] [-108h]
  float v147; // [sp+ACh] [-104h]
  __int16 v148; // [sp+B0h] [-100h]
  __int16 v149; // [sp+B2h] [-FEh]
  __int16 v150; // [sp+B4h] [-FCh]
  char v151; // [sp+B6h] [-FAh]
  int v152; // [sp+B8h] [-F8h]
  __int16 v153; // [sp+BCh] [-F4h]
  __int16 v154; // [sp+BEh] [-F2h]
  __int16 v155; // [sp+C0h] [-F0h]
  __int16 v156; // [sp+C2h] [-EEh]
  __int16 v157; // [sp+C4h] [-ECh]
  __int16 v158; // [sp+C6h] [-EAh]
  char v159; // [sp+C8h] [-E8h]
  char v160; // [sp+C9h] [-E7h]
  usercmd_t v161; // [sp+D0h] [-E0h] BYREF
  float v162[4]; // [sp+110h] [-A0h] BYREF
  idVec4 v163; // [sp+120h] [-90h] BYREF

  if ( this->seatInfo.num == 0 )
    return 0;
  v6 = (idPlayer *)idActor::CastTo(c: other);
  v7 = idPlayer::CastTo(c: v6);
  if ( wantSeat >= this->seatInfo.num )
  {
    if ( wantSeat != 2 )
      return 0;
  }
  else
  {
    Occupant = (idPresentablePtr<idPresentableActor> *)idVehicle::GetOccupant(this, i: wantSeat);
    if ( !idPresentablePtr<idPresentable>::IsValid(this: Occupant) )
    {
      valueInteger = vehicle_playerCanEnter.valueInteger;
      if ( v7 == nullptr || this->seatInfo.list[wantSeat].playerCanOccupy || vehicle_playerCanEnter.valueInteger != 0 )
      {
        v10 = wantSeat;
        if ( wantSeat != -1 )
          goto LABEL_22;
      }
    }
  }
  v11 = 0;
  if ( this->seatInfo.num <= 0 )
    return 0;
  v12 = 0;
  for ( i = 0; ; i += 16 )
  {
    presentable = this->presentable;
    v15 = presentable != nullptr ? (int)presentable->GetVehicleInterface(this: presentable) : 0;
    if ( !idPresentablePtr<idPresentable>::IsValid(this: (idPresentablePtr<idPresentableActor> *)(*(_DWORD *)(v15 + 16472)
                                                                                                + i)) )
    {
      valueInteger = vehicle_playerCanEnter.valueInteger;
      if ( v7 == nullptr || this->seatInfo.list[v12].playerCanOccupy || vehicle_playerCanEnter.valueInteger != 0 )
        break;
    }
    ++v11;
    ++v12;
    if ( v11 >= this->seatInfo.num )
      return 0;
  }
  v10 = v11;
  if ( v11 == -1 )
    return 0;
LABEL_22:
  if ( this->keys != nullptr && valueInteger == 0 && v6 != nullptr )
  {
    v17 = v6->GetInventory_2(this: v6);
    if ( idInventoryCollection::FindTotalInventoryItemCount(this: v17, decl: this->keys) <= 0 )
    {
      idLib::Printf(fmt: "No Key for vehicle, so exiting\n");
      return 0;
    }
  }
  if ( v7 != nullptr )
  {
    *(_BYTE *)(idPlayer::GetBobCycle(this: v7) + 216) = 0;
    v18 = v7->presentable;
    if ( v18 != nullptr )
      v19 = (int)v18->GetPlayerInterface_2(this: v18);
    else
      v19 = 0;
    *(idVec3 *)(v19 + 19044) = vec3_origin;
    *(idAngles *)(v19 + 19056) = ang_zero;
    if ( com_multiplayer.valueInteger == 0 )
      idPlayer::HideTutorialGui(this: v7);
    *(_BYTE *)&v7->flags = (2 * (vehicle_damage_player.valueInteger != 0)) & 2 | *(_BYTE *)&v7->flags & 0xFD;
    memset(&v134, 0, 14);
    *(_WORD *)&v134.memTag = 1280;
    idList<idThread *,58>::Clear(this: &v134);
    v20 = v7->GetInventory_2(this: v7);
    idInventoryCollection::GetVehicleKeys(this: v20, vehicleList: (idList<idVehicleKey *,5> *)&v134);
    v21 = 0;
    if ( v134.num > 0 )
    {
      list = (idVehicleKey **)v134.list;
      while ( (const idDeclEntityDef *)(*list)->decl[1].trackedMemory != this->entityDef )
      {
        ++v21;
        ++list;
        if ( v21 >= v134.num )
          goto LABEL_51;
      }
      if ( this->playerKey != &this->tempPlayerKey )
        this->playerKey = *list;
      v23 = this->presentable;
      currentWeaponGroup = this->playerKey->currentWeaponGroup;
      if ( v23 != nullptr )
        v25 = v23->GetVehicleInterface(this: v23);
      else
        v25 = nullptr;
      idPresentableVehicle::SetCurrentWeaponGroup(this: v25, newWeaponGroup: currentWeaponGroup);
      v26 = this->presentable;
      if ( v26 != nullptr )
        v27 = v26->GetVehicleInterface(this: v26);
      else
        v27 = nullptr;
      idPresentableVehicle::ClearAllWeaponAnims(this: v27);
      v28 = this->presentable;
      if ( v28 != nullptr )
        v29 = v28->GetVehicleInterface(this: v28);
      else
        v29 = nullptr;
      idPresentableVehicle::ActivateWeaponGroup(this: v29, notifySound: false);
    }
LABEL_51:
    if ( gameLocal->world->mapType == MAPTYPE_OUTDOOR && this->health > 0.0 )
      idPlayer::SetVehicleInfo(this: v7, vehicle: this, garage: GARAGE_NONE, markForGarageView: false);
    playerKey = this->playerKey;
    if ( playerKey != nullptr )
    {
      decl = (const idDeclJob *)playerKey->decl;
      v32 = (idJobManager *)v7->GetInventory_2(this: v7);
      if ( idJobManager::FindJobByDecl(this: v32, jobDecl: decl) != nullptr )
      {
        idVehicleKey::ClearGarageBayReference(this: this->playerKey);
      }
      else
      {
        idLib::Warning(fmt: "Player no longer has key for vehicle");
        this->playerKey = nullptr;
      }
    }
    v33 = 1;
    if ( !common->IsMultiplayer(this: common) )
    {
      if ( this->allowAmmoTransfer || (v34 = 0, vehicle_playerTransferInv.valueInteger != 0) )
        v34 = 1;
      v33 = v34;
    }
    if ( v33 != 0 )
      idVehicle::TransferPlayerAmmoToVehicle(this, player: v7);
    v35 = 0;
    if ( !common->IsMultiplayer(this: common) )
    {
      if ( this->allowQuickItemTransfer || (v36 = 0, vehicle_playerTransferInv.valueInteger != 0) )
        v36 = 1;
      v35 = v36;
    }
    if ( v35 != 0 )
      idVehicle::TransferPlayerQuickItemsToVehicle(this, player: v7);
    v37 = this->presentable;
    if ( v37 != nullptr )
      v38 = v37->GetVehicleInterface(this: v37);
    else
      v38 = nullptr;
    idPresentableVehicle::ResetBoostFOV(this: v38);
    if ( v134.listStatic == 0 || v134.listStatic == 2 )
    {
      if ( v134.list != nullptr )
        idMem::Free(this: &mem, ptr: v134.list, align: ALIGN_16);
      v134.list = nullptr;
      v134.size = 0;
    }
    v134.num = 0;
  }
  if ( other == (idActor *)this )
  {
    v39 = nullptr;
  }
  else
  {
    v39 = other->presentable;
    if ( v39 == nullptr )
    {
      idEntity::InitPresentableInternal(this: other);
      v39 = other->presentable;
    }
  }
  v40 = this->presentable;
  if ( v40 != nullptr )
    v41 = (int)v40->GetVehicleInterface(this: v40);
  else
    v41 = 0;
  v42 = *(_DWORD *)(v41 + 16472);
  v43 = 16 * v10;
  if ( v39 != nullptr )
    *(_DWORD *)(v42 + 16 * v10) = v39->spawnId;
  else
    *(_DWORD *)(v42 + 16 * v10) = 0;
  if ( v6 != nullptr )
  {
    if ( v7 != nullptr )
      idPlayer::AddControl(this: v7, entity: this);
    v6->Hide_2(this: v6);
    if ( v7 != nullptr )
    {
      v44 = v7->presentable;
      v45 = v44 != nullptr ? (int)v44->GetPlayerInterface_2(this: v44) : 0;
      if ( v45 != -37616 )
      {
        v46 = v7->presentable;
        if ( v46 != nullptr )
          v47 = (int)v46->GetPlayerInterface_2(this: v46);
        else
          v47 = 0;
        idHands::Hide(this: (idHands *)(v47 + 37616), hideReason: HAND_HIDE_VEHICLE);
      }
    }
    Physics = idEntity::GetPhysics(this);
    v49 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
    v162[0] = *v49;
    v162[1] = v49[1];
    v162[2] = v49[2];
    v50 = idEntity::GetPhysics(this: v6);
    v50->SetOrigin(this: v50, a2: (const idVec3 *)v162, a3: -1);
    idEntity::Bind(this: v6, master: (idWorldspawn *)this, orientated: true);
    if ( v7 != nullptr )
    {
      v51 = v7->presentable;
      if ( v51 != nullptr )
        v52 = (int)v51->GetPlayerInterface_2(this: v51);
      else
        v52 = 0;
      idPhysics_Player::SetMovementType(this: (idPhysics_Player *)(v52 + 36264), type: PM_VEHICLE_NOCLIP);
    }
    v53 = idEntity::GetPhysics(this);
    v54 = (idAngles *)v53->GetAxis(this: v53, a2: 0);
    this->lastCarAngles = *idMat3::ToAngles(this: (idMat3 *)&v135.mat[1].y, result: v54);
    v55 = this->presentable;
    if ( v55 != nullptr )
      v56 = v55->GetVehicleInterface(this: v55);
    else
      v56 = nullptr;
    idPresentableVehicle::ActivateCrosshair(this: v56);
    Gunner = (idPlayer *)idVehicle::GetGunner(this);
    if ( idPlayer::CastTo(c: Gunner) != nullptr )
    {
      v58 = this->presentable;
      if ( v58 != nullptr )
        v59 = (int)v58->GetVehicleInterface(this: v58);
      else
        v59 = 0;
      *(_BYTE *)(v59 + 20168) = 1;
    }
  }
  if ( v7 != nullptr )
  {
    v163.x = 0.0;
    v163.y = 0.0;
    v163.z = 0.0;
    v163.w = 1.0;
    v60 = v7->presentable;
    if ( v60 != nullptr )
      v61 = (int)v60->GetPlayerInterface_2(this: v60);
    else
      v61 = 0;
    idView::Flash(this: (idView *)(v61 + 16224), color: &v163, time: 500);
  }
  v62 = this->presentable;
  if ( v62 != nullptr )
    v63 = (int)v62->GetVehicleInterface(this: v62);
  else
    v63 = 0;
  *(_BYTE *)(v63 + 17265) = 0;
  v64 = this->presentable;
  if ( v64 != nullptr )
    v65 = (int)v64->GetVehicleInterface(this: v64);
  else
    v65 = 0;
  (*(void (__fastcall **)(int))(*(_DWORD *)(v65 + 16512) + 152))(a1: v65 + 16512);
  v66 = this->presentable;
  if ( v66 != nullptr )
  {
    v67 = v66->GetVehicleInterface(this: v66);
    if ( v67 != nullptr )
    {
      Driver = idPresentableVehicle::GetDriver(this: v67);
      if ( Driver != nullptr && Driver->entity != nullptr )
        this->zoom_fov_x = vehicle_baseFOV.valueFloat;
    }
  }
  if ( idVehicle::GetGunner(this) != nullptr )
  {
    v69 = this->presentable;
    if ( v69 != nullptr )
      v70 = v69->GetVehicleInterface(this: v69);
    else
      v70 = nullptr;
    idPresentableVehicle::SetCurrentWeapon(this: v70);
  }
  idVehicle::VisualEnterVehicle(this, seat: v10);
  if ( v10 != SEAT_DRIVER )
  {
    if ( v10 == SEAT_GUNNER && v7 != nullptr )
    {
      v73 = idEntity::GetPhysics(this);
      v74 = (idAngles *)v73->GetAxis(this: v73, a2: 0);
      idMat3::ToAngles(this: &v135, result: v74);
      v75 = this->presentable;
      if ( v75 != nullptr )
        v76 = v75->GetVehicleInterface(this: v75);
      else
        v76 = nullptr;
      Crosshair = idPresentableVehicle::GetCrosshair(this: v76);
      Crosshair->angles = (idAngles)v135.mat[0];
      v78 = this->presentable;
      if ( v78 != nullptr )
        v79 = v78->GetVehicleInterface(this: v78);
      else
        v79 = nullptr;
      v80 = idPresentableVehicle::GetCrosshair(this: v79);
      z = v135.mat[0].z;
      y = v135.mat[0].y;
      x = v135.mat[0].x;
      v80->goalAngles.pitch = v135.mat[0].x;
      v135.mat[2].x = z;
      v135.mat[1].z = y;
      v80->goalAngles.yaw = y;
      v135.mat[1].y = x;
      v80->goalAngles.roll = v135.mat[2].x;
    }
  }
  else if ( v7 != nullptr )
  {
    v71 = idEntity::GetPhysics(this);
    v72 = (idAngles *)v71->GetAxis(this: v71, a2: 0);
    this->currentViewAngles = *idMat3::ToAngles(this: (idMat3 *)&v135.mat[1].y, result: v72);
  }
  v84 = this->presentable;
  if ( v84 != nullptr )
    v85 = (int)v84->GetVehicleInterface(this: v84);
  else
    v85 = 0;
  v86 = 0;
  v87 = 0;
  *(_BYTE *)(*(_DWORD *)(v85 + 16472) + v43 + 12) |= 0x80u;
  num = this->seatInfo.num;
  if ( num <= 0 )
    goto LABEL_159;
  v89 = 0;
  v90 = this->seatInfo.list;
  do
  {
    if ( v90->playerCanOccupy || vehicle_playerCanEnter.valueInteger != 0 )
      ++v86;
    ++v87;
    v90 = &this->seatInfo.list[++v89];
  }
  while ( v87 < num );
  v91 = 1;
  if ( v86 <= 1 )
LABEL_159:
    v91 = 0;
  v92 = this->presentable;
  if ( v92 != nullptr )
    v93 = (int)v92->GetVehicleInterface(this: v92);
  else
    v93 = 0;
  *(_BYTE *)(*(_DWORD *)(v93 + 16472) + v43 + 12) = (v91 << 6) & 0x40
                                                  | *(_BYTE *)(*(_DWORD *)(v93 + 16472) + v43 + 12) & 0xBF;
  v94 = this->presentable;
  if ( v94 != nullptr )
    v95 = (int)v94->GetVehicleInterface(this: v94);
  else
    v95 = 0;
  *(_BYTE *)(v95 + 17468) = 1;
  if ( v7 != nullptr )
    idPlayer::EnteredVehicle(this: v7, veh: this);
  if ( v10 == SEAT_GUNNER )
  {
    v96 = 0;
    for ( j = 0; ; j += 4 )
    {
      v98 = this->presentable;
      v99 = v98 != nullptr ? (int)v98->GetVehicleInterface(this: v98) : 0;
      if ( v96 >= *(_DWORD *)(v99 + 18748) )
        break;
      v100 = this->presentable;
      if ( v100 != nullptr )
        v101 = (int)v100->GetVehicleInterface(this: v100);
      else
        v101 = 0;
      v102 = *(_DWORD *)(v101 + 18744);
      v103 = this->presentable;
      v104 = *(idVehicleWeapon **)(v102 + j);
      if ( v103 != nullptr )
        v105 = v103->GetVehicleInterface(this: v103);
      else
        v105 = nullptr;
      p_weaponSlot = &idVehicleWeapon::GetDeclVehicleWeapon(this: v104)->weaponSlot;
      if ( *p_weaponSlot == idPresentableVehicle::GetCurrentWeaponGroup(this: v105) )
      {
        v107 = this->presentable;
        if ( v107 != nullptr )
          v108 = (int)v107->GetVehicleInterface(this: v107);
        else
          v108 = 0;
        idVehicleWeapon::PlayAnim(
          this: *(idVehicleWeapon **)(*(_DWORD *)(v108 + 18744) + j),
          anim: VW_ANIM_GUNNER_ENTER);
      }
      v109 = this->presentable;
      if ( v109 != nullptr )
        v110 = (int)v109->GetVehicleInterface(this: v109);
      else
        v110 = 0;
      ++v96;
      v111 = *(_DWORD *)(*(_DWORD *)(v110 + 18744) + j);
      *(_BYTE *)(v111 + 257) = (_cntlzw((unsigned int)v7) & 0x20) != 0;
    }
  }
  v112 = v10;
  v113 = 0;
  if ( this->seatInfo.list[v10].enterAnim.num > 0 )
  {
    v114 = 0;
    do
    {
      value = this->seatInfo.list[v112].enterAnim.list[v114].spawnId.value;
      if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
      {
        v116 = gameLocal->entities.ptr[this->seatInfo.list[v112].enterAnim.list[v114].spawnId.value & 0x1FFF];
        if ( v116 != nullptr )
        {
          v117 = (idAnimated_AnimWeb *)idEntity::CastTo(c: v116);
          if ( v117 != nullptr )
          {
            v118 = idEntity::GetPhysics(this);
            v119 = idEntity::GetPhysics(this: v117);
            v120 = v118;
            GetOrigin = v118->GetOrigin;
            v121 = v119->__vftable;
            v123 = (int)GetOrigin(this: v120, a2: 0);
            v121->SetOrigin(this: v119, a2: (const idVec3 *)v123, a3: -1);
            v124 = idEntity::GetPhysics(this);
            v125 = idEntity::GetPhysics(this: v117);
            v126 = v124;
            GetAxis = v124->GetAxis;
            v127 = v125->__vftable;
            v129 = (int)GetAxis(this: v126, a2: 0);
            v127->SetAxis(this: v125, a2: (const idMat3 *)v129, a3: -1);
            idEntity::Activate(this: v117, activator: v7);
            v117->Show(this: v117);
            v130 = idAnimated_AnimWeb::CastTo(c: v117);
            if ( v130 != nullptr )
              v130->ChangeAnimWebStateVia_2(
                this: v130,
                a2: this->seatInfo.list[v112].enterViaAnimRefStr.data,
                a3: this->seatInfo.list[v112].enterDstAnimRefStr.data);
          }
        }
      }
      ++v113;
      ++v114;
    }
    while ( v113 < this->seatInfo.list[v112].enterAnim.num );
  }
  idVehicle::UpdateEventInstigators(this);
  v161.pos[2] = 0.0;
  v131 = this->presentable;
  v161.pos[1] = 0.0;
  v161.pos[0] = 0.0;
  memset(&v161, 0, 9);
  v147 = 0.0;
  v146 = 0.0;
  v145 = 0.0;
  memset(v161.angles, 0, 10);
  v161.yaw = 0;
  v161.pitch = 0;
  v161.roll = 0;
  v161.predictionStateBits = 0;
  memset(&v161.serverGameTime, 0, 18);
  v135.mat[2].z = 0.0;
  v136 = 0;
  v137 = 0;
  v138 = 0;
  v139 = 0;
  v143 = 0;
  v142 = 0;
  v141 = 0;
  v144 = 0;
  v149 = 0;
  v148 = 0;
  v150 = 0;
  v151 = 0;
  v159 = 0;
  v152 = 0;
  v153 = 0;
  *((_BYTE *)&v161 + 9) &= 0x3Fu;
  v140 &= 0x3Fu;
  v155 = 0;
  v154 = 0;
  v158 = 0;
  v157 = 0;
  v156 = 0;
  v160 = 0;
  if ( v131 != nullptr )
    v132 = v131->GetVehicleInterface(this: v131);
  else
    v132 = nullptr;
  if ( (unsigned __int8)idPresentableVehicle::GetUserCommand(
                          this: v132,
                          seat: 0,
                          previous: &v161,
                          current: (usercmd_t *)&v135.mat[2].z) != 0 )
    v133 = (-v139 & (unsigned int)~v139) >> 31;
  else
    LOBYTE(v133) = 0;
  this->exitButtonDownOnEnter = v133;
  return 1;
}


// ========================================================================
// __unwind$527869
// EA  : 0x82D2BAA0
// RVA : 0x00D2BAA0
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void _unwind_527869()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 432 + 96));
}


// ========================================================================
// ?AttachNpcToVai@idVehicle@@QAAXPAVidAI2@@PAVidVehicleAI@@@Z
// EA  : 0x82D2BAC8
// RVA : 0x00D2BAC8
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __fastcall idVehicle::AttachNpcToVai(idVehicle *this, idAI2 *npc, idVehicleAI *vai)
{
  int OccupantNum; // r30
  idPresentable *presentable; // r31
  idPresentable *v7; // r3
  int v8; // r3
  unsigned int spawnId; // r10

  OccupantNum = idVehicle::GetOccupantNum(this, entity: vai);
  if ( OccupantNum >= 0 )
  {
    if ( npc->presentable == nullptr )
      idEntity::InitPresentableInternal(this: npc);
    presentable = npc->presentable;
    v7 = this->presentable;
    if ( v7 != nullptr )
      v8 = (int)v7->GetVehicleInterface(this: v7);
    else
      v8 = 0;
    spawnId = 0;
    if ( presentable != nullptr )
      spawnId = presentable->spawnId;
    *(_DWORD *)(*(_DWORD *)(v8 + 16472) + 16 * OccupantNum + 8) = spawnId;
    npc->Hide_2(this: npc);
    idEntity::Bind(this: npc, master: (idWorldspawn *)this, orientated: false);
  }
  else
  {
    idLib::Warning(fmt: "idVehicle::BindNpcToVai() vai not in vehicle!");
  }
}


// ========================================================================
// ?SwitchSeatPosition@idVehicle@@QAAXHH@Z
// EA  : 0x82D2BB98
// RVA : 0x00D2BB98
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __fastcall idVehicle::SwitchSeatPosition(idVehicle *this, int _seat, int force)
{
  idPresentable *presentable; // r3
  int v7; // r3
  int v8; // r29
  int i; // r30
  idPresentable *v10; // r3
  int v11; // r3
  idPresentable *v12; // r3
  int v13; // r3
  int v14; // r11
  idPresentable *v15; // r3
  idVehicleWeapon *v16; // r31
  idPresentableVehicle *v17; // r3
  int CurrentWeaponGroup; // r27
  idPresentable *v19; // r3
  int v20; // r3
  idPresentable *v21; // r3
  int v22; // r3
  idPresentable *v23; // r3
  int v24; // r3
  idPresentable *v25; // r3
  int v26; // r3
  vehicleOccupant_t *Occupant; // r3
  idEntity *OccupantAsEntity; // r3
  vehicleOccupant_t *v29; // r3
  idEntity *v30; // r3
  idPresentable *v31; // r3
  int v32; // r3
  _DWORD *v33; // r30
  int v34; // r31
  idPresentable *v35; // r3
  int v36; // r3
  int v37; // r30
  int v38; // r11
  int v39; // r31
  int v40; // r27
  int v41; // r28
  int j; // r29
  idPresentable *v43; // r3
  int v44; // r3
  idPresentable *v45; // r3
  int v46; // r3
  int v47; // r11
  idPresentable *v48; // r3
  idVehicleWeapon *v49; // r30
  idPresentableVehicle *v50; // r31
  int *p_weaponSlot; // r30
  idPresentable *v52; // r3
  int v53; // r3
  idPresentable *v54; // r3
  int v55; // r3
  int CurrentAnimLength; // r3
  idPresentable *v57; // r3
  int v58; // r3
  int v59; // r10
  idPresentable *v60; // r3
  idPresentableVehicle *v61; // r3
  idPresentable *v62; // r3
  int v63; // r3
  float *v64; // r11
  idPresentable *v65; // r3
  float v66; // r7
  float v67; // r6
  float v68; // r5
  int v69; // r3
  idPresentable *v70; // r11
  int v71; // r31
  int v72; // r3
  int v73; // r11
  idPresentable *v74; // r3
  int v75; // r3
  int v76; // r11
  float z; // r9
  float x; // r8
  char y_high; // r7
  idPresentable *v80; // r3
  int v81; // r3
  _DWORD *v82; // r30
  int v83; // r31
  idPresentable *v84; // r3
  int v85; // r3
  int v86; // r30
  int v87; // r11
  int v88; // r31
  idPresentable *v89; // r3
  int v90; // r3
  int v91; // r30
  int v92; // r11
  int v93; // r31
  idPresentable *v94; // r3
  int v95; // r11
  int v96; // r31
  idPresentable *PresentableByIndex; // r3
  idEntity *entity; // r3
  int v99; // r11
  char v100; // r11
  bool v101; // zf
  unsigned __int8 v102; // r27
  int v103; // r28
  int k; // r29
  idPresentable *v105; // r3
  int v106; // r3
  int v107; // r11
  idPresentable *v108; // r3
  int v109; // r3
  int v110; // r11
  idPresentable *v111; // r3
  idVehicleWeapon *v112; // r30
  idPresentableVehicle *v113; // r31
  int *v114; // r30
  idPresentable *v115; // r3
  int v116; // r3
  idPresentable *v117; // r3
  int v118; // r3
  int v119; // r7
  int v120; // r3
  int v121; // r30
  int v122; // r11
  int v123; // r31
  idPresentable *v124; // r3
  int v125; // r11
  int v126; // r31
  idPresentable *v127; // r3
  idEntity *v128; // r3
  int v129; // r11
  char v130; // r11
  idPhysics *Physics; // r3
  idAngles *v132; // r3
  idPresentable *v133; // r3
  idPresentableVehicle *v134; // r3
  idThirdPersonCrosshair *Crosshair; // r3
  idPresentable *v136; // r3
  idPresentableVehicle *v137; // r3
  idThirdPersonCrosshair *v138; // r3
  float y; // r11
  float v140; // r10
  float v141; // r9
  idPresentable *v142; // r3
  idPresentableVehicle *v143; // r3
  idPresentable *v144; // r3
  idPresentableVehicle *v145; // r3
  float yaw; // r10
  float roll; // r9
  float pitch; // r8
  idPresentable *v149; // r3
  int v150; // r3
  _DWORD *v151; // r30
  int v152; // r31
  idPresentable *v153; // r3
  int v154; // r3
  _DWORD *v155; // r30
  int v156; // r31
  int v157; // r31
  idPresentable *v158; // r3
  idEntity *v159; // r3
  int v160; // r11
  char v161; // r11
  idPresentable *v162; // r3
  idPresentableVehicle *v163; // r3
  idPresentable *v164; // r3
  int v165; // r3
  int v166; // r28
  idGameTimeManager *p_gameTimeManager; // r3
  int v168; // r3
  idPresentable *v169; // r11
  int v170; // r30
  int v171; // r29
  int v172; // r31
  int GameMs; // r3
  idPresentable *v174; // r11
  int valueInteger; // r30
  idMat3 v176; // [sp+50h] [-70h] BYREF

  if ( force == 0 )
  {
    presentable = this->presentable;
    v7 = presentable != nullptr ? (int)presentable->GetVehicleInterface(this: presentable) : 0;
    if ( (*(_BYTE *)(*(_DWORD *)(v7 + 16472) + 16 * _seat + 12) & 0x40) == 0 )
      return;
  }
  v8 = 0;
  for ( i = 0; ; i += 4 )
  {
    v10 = this->presentable;
    v11 = v10 != nullptr ? (int)v10->GetVehicleInterface(this: v10) : 0;
    if ( v8 >= *(_DWORD *)(v11 + 18748) )
      break;
    v12 = this->presentable;
    v13 = v12 != nullptr ? (int)v12->GetVehicleInterface(this: v12) : 0;
    v14 = *(_DWORD *)(v13 + 18744);
    v15 = this->presentable;
    v16 = *(idVehicleWeapon **)(v14 + i);
    v17 = v15 != nullptr ? v15->GetVehicleInterface(this: v15) : nullptr;
    CurrentWeaponGroup = idPresentableVehicle::GetCurrentWeaponGroup(this: v17);
    if ( idVehicleWeapon::GetWeaponSlot(this: v16) == CurrentWeaponGroup )
    {
      v19 = this->presentable;
      v20 = v19 != nullptr ? (int)v19->GetVehicleInterface(this: v19) : 0;
      if ( !idVehicleWeapon::IsReadyToFire(this: *(idVehicleWeapon **)(*(_DWORD *)(v20 + 18744) + i)) )
        break;
    }
    ++v8;
  }
  v21 = this->presentable;
  v22 = v21 != nullptr ? (int)v21->GetVehicleInterface(this: v21) : 0;
  if ( v8 < *(_DWORD *)(v22 + 18748) )
    return;
  if ( force == 0 )
  {
    v23 = this->presentable;
    v24 = v23 != nullptr ? (int)v23->GetVehicleInterface(this: v23) : 0;
    if ( idPresentablePtr<idPresentable>::IsValid(this: *(idPresentablePtr<idPresentableActor> **)(v24 + 16472)) )
    {
      v25 = this->presentable;
      v26 = v25 != nullptr ? (int)v25->GetVehicleInterface(this: v25) : 0;
      if ( idPresentablePtr<idPresentable>::IsValid(this: (idPresentablePtr<idPresentableActor> *)(*(_DWORD *)(v26 + 16472)
                                                                                                 + 16)) )
      {
        Occupant = idVehicle::GetOccupant(this, i: 0);
        OccupantAsEntity = vehicleOccupant_t::GetOccupantAsEntity(this: Occupant);
        if ( (unsigned __int8)idClass::IsType(this: OccupantAsEntity, superclass: &idPlayer::Type) == 0 )
          return;
        v29 = idVehicle::GetOccupant(this, i: 1);
        v30 = vehicleOccupant_t::GetOccupantAsEntity(this: v29);
        if ( (unsigned __int8)idClass::IsType(this: v30, superclass: &idPlayer::Type) == 0 )
          return;
      }
    }
  }
  v31 = this->presentable;
  if ( v31 != nullptr )
    v32 = (int)v31->GetVehicleInterface(this: v31);
  else
    v32 = 0;
  v33 = *(_DWORD **)(v32 + 16472);
  v34 = *v33 & 0x3FFF;
  if ( *v33 != 0
    && idClientGame::IsPresentableIndexValid(this: clientGame, index: *v33 & 0x3FFF)
    && idClientGame::GetPresentableByIndex(this: clientGame, index: v34)->spawnId == *v33 )
  {
    idVehicle::VisualExitVehicle(this, seat: 0, delayTime: 0, thrownEntity: nullptr);
  }
  v35 = this->presentable;
  if ( v35 != nullptr )
    v36 = (int)v35->GetVehicleInterface(this: v35);
  else
    v36 = 0;
  v37 = *(_DWORD *)(v36 + 16472);
  v38 = *(_DWORD *)(v37 + 16);
  v39 = v38 & 0x3FFF;
  if ( v38 != 0
    && idClientGame::IsPresentableIndexValid(this: clientGame, index: v38 & 0x3FFF)
    && idClientGame::GetPresentableByIndex(this: clientGame, index: v39)->spawnId == *(_DWORD *)(v37 + 16) )
  {
    v40 = 0;
    v41 = 0;
    for ( j = 0; ; j += 4 )
    {
      v43 = this->presentable;
      v44 = v43 != nullptr ? (int)v43->GetVehicleInterface(this: v43) : 0;
      if ( v41 >= *(_DWORD *)(v44 + 18748) )
        break;
      v45 = this->presentable;
      if ( v45 != nullptr )
        v46 = (int)v45->GetVehicleInterface(this: v45);
      else
        v46 = 0;
      v47 = *(_DWORD *)(v46 + 18744);
      v48 = this->presentable;
      v49 = *(idVehicleWeapon **)(v47 + j);
      if ( v48 != nullptr )
        v50 = v48->GetVehicleInterface(this: v48);
      else
        v50 = nullptr;
      p_weaponSlot = &idVehicleWeapon::GetDeclVehicleWeapon(this: v49)->weaponSlot;
      if ( *p_weaponSlot == idPresentableVehicle::GetCurrentWeaponGroup(this: v50) )
      {
        v52 = this->presentable;
        v53 = v52 != nullptr ? (int)v52->GetVehicleInterface(this: v52) : 0;
        idVehicleWeapon::PlayAnim(this: *(idVehicleWeapon **)(*(_DWORD *)(v53 + 18744) + j), anim: VW_ANIM_GUNNER_EXIT);
        v54 = this->presentable;
        v55 = v54 != nullptr ? (int)v54->GetVehicleInterface(this: v54) : 0;
        CurrentAnimLength = idVehicleWeapon::GetCurrentAnimLength(this: *(idVehicleWeapon **)(*(_DWORD *)(v55 + 18744)
                                                                                            + j));
        if ( CurrentAnimLength > v40 )
          v40 = CurrentAnimLength;
      }
      v57 = this->presentable;
      if ( v57 != nullptr )
        v58 = (int)v57->GetVehicleInterface(this: v57);
      else
        v58 = 0;
      ++v41;
      v59 = *(_DWORD *)(*(_DWORD *)(v58 + 18744) + j);
      *(_BYTE *)(v59 + 257) = 1;
    }
    idVehicle::VisualExitVehicle(this, seat: 1, delayTime: v40, thrownEntity: nullptr);
  }
  v60 = this->presentable;
  if ( v60 != nullptr )
    v61 = v60->GetVehicleInterface(this: v60);
  else
    v61 = nullptr;
  idPresentableVehicle::SetCurrentWeapon(this: v61);
  v62 = this->presentable;
  if ( v62 != nullptr )
    v63 = (int)v62->GetVehicleInterface(this: v62);
  else
    v63 = 0;
  v64 = *(float **)(v63 + 16472);
  v65 = this->presentable;
  v66 = v64[5];
  v67 = v64[6];
  v68 = v64[7];
  v176.mat[1].y = v64[4];
  v176.mat[1].z = v66;
  v176.mat[2].x = v67;
  v176.mat[2].y = v68;
  if ( v65 != nullptr )
    v69 = (int)v65->GetVehicleInterface(this: v65);
  else
    v69 = 0;
  v70 = this->presentable;
  v71 = *(_DWORD *)(v69 + 16472);
  if ( v70 != nullptr )
    v72 = (int)v70->GetVehicleInterface(this: this->presentable);
  else
    v72 = 0;
  v73 = *(_DWORD *)(v72 + 16472);
  *(_DWORD *)(v73 + 16) = *(_DWORD *)v71;
  *(_DWORD *)(v73 + 20) = *(_DWORD *)(v71 + 4);
  *(_DWORD *)(v73 + 24) = *(_DWORD *)(v71 + 8);
  *(_BYTE *)(v73 + 28) = *(_BYTE *)(v71 + 12);
  v74 = this->presentable;
  if ( v74 != nullptr )
    v75 = (int)v74->GetVehicleInterface(this: v74);
  else
    v75 = 0;
  v76 = *(_DWORD *)(v75 + 16472);
  z = v176.mat[1].z;
  x = v176.mat[2].x;
  y_high = HIBYTE(v176.mat[2].y);
  *(float *)v76 = v176.mat[1].y;
  *(float *)(v76 + 4) = z;
  *(float *)(v76 + 8) = x;
  *(_BYTE *)(v76 + 12) = y_high;
  v80 = this->presentable;
  if ( v80 != nullptr )
    v81 = (int)v80->GetVehicleInterface(this: v80);
  else
    v81 = 0;
  v82 = *(_DWORD **)(v81 + 16472);
  v83 = *v82 & 0x3FFF;
  if ( *v82 != 0
    && idClientGame::IsPresentableIndexValid(this: clientGame, index: *v82 & 0x3FFF)
    && idClientGame::GetPresentableByIndex(this: clientGame, index: v83)->spawnId == *v82 )
  {
    idVehicle::VisualEnterVehicle(this, seat: 0);
  }
  v84 = this->presentable;
  if ( v84 != nullptr )
    v85 = (int)v84->GetVehicleInterface(this: v84);
  else
    v85 = 0;
  v86 = *(_DWORD *)(v85 + 16472);
  v87 = *(_DWORD *)(v86 + 16);
  v88 = v87 & 0x3FFF;
  if ( v87 != 0
    && idClientGame::IsPresentableIndexValid(this: clientGame, index: v87 & 0x3FFF)
    && idClientGame::GetPresentableByIndex(this: clientGame, index: v88)->spawnId == *(_DWORD *)(v86 + 16) )
  {
    v89 = this->presentable;
    if ( v89 != nullptr )
      v90 = (int)v89->GetVehicleInterface(this: v89);
    else
      v90 = 0;
    v91 = *(_DWORD *)(v90 + 16472);
    v92 = *(_DWORD *)(v91 + 16);
    v93 = v92 & 0x3FFF;
    if ( v92 != 0
      && idClientGame::IsPresentableIndexValid(this: clientGame, index: v92 & 0x3FFF)
      && (v94 = idClientGame::GetPresentableByIndex(this: clientGame, index: v93),
          v95 = *(_DWORD *)(v91 + 16),
          v94->spawnId == v95) )
    {
      v96 = *(_DWORD *)(v91 + 16) & 0x3FFF;
      if ( v95 == 0
        || !idClientGame::IsPresentableIndexValid(this: clientGame, index: *(_DWORD *)(v91 + 16) & 0x3FFF)
        || (PresentableByIndex = idClientGame::GetPresentableByIndex(this: clientGame, index: v96))->spawnId != *(_DWORD *)(v91 + 16) )
      {
        PresentableByIndex = nullptr;
      }
      entity = PresentableByIndex->entity;
    }
    else
    {
      entity = nullptr;
    }
    v99 = *(_DWORD *)(entity->GetType(this: entity) + 36);
    if ( v99 < idPlayer::Type.typeNum || (v101 = v99 <= idPlayer::Type.lastChild, v100 = 1, !v101) )
      v100 = 0;
    v102 = v100;
    idVehicle::VisualEnterVehicle(this, seat: 1);
    v103 = 0;
    for ( k = 0; ; k += 4 )
    {
      v105 = this->presentable;
      v106 = v105 != nullptr ? (int)v105->GetVehicleInterface(this: v105) : 0;
      v107 = *(_DWORD *)(v106 + 18748);
      v108 = this->presentable;
      if ( v103 >= v107 )
        break;
      if ( v108 != nullptr )
        v109 = (int)v108->GetVehicleInterface(this: v108);
      else
        v109 = 0;
      v110 = *(_DWORD *)(v109 + 18744);
      v111 = this->presentable;
      v112 = *(idVehicleWeapon **)(v110 + k);
      if ( v111 != nullptr )
        v113 = v111->GetVehicleInterface(this: v111);
      else
        v113 = nullptr;
      v114 = &idVehicleWeapon::GetDeclVehicleWeapon(this: v112)->weaponSlot;
      if ( *v114 == idPresentableVehicle::GetCurrentWeaponGroup(this: v113) )
      {
        v115 = this->presentable;
        if ( v115 != nullptr )
          v116 = (int)v115->GetVehicleInterface(this: v115);
        else
          v116 = 0;
        idVehicleWeapon::PlayAnim(
          this: *(idVehicleWeapon **)(*(_DWORD *)(v116 + 18744) + k),
          anim: VW_ANIM_GUNNER_ENTER);
      }
      v117 = this->presentable;
      if ( v117 != nullptr )
        v118 = (int)v117->GetVehicleInterface(this: v117);
      else
        v118 = 0;
      ++v103;
      v119 = *(_DWORD *)(*(_DWORD *)(v118 + 18744) + k);
      *(_BYTE *)(v119 + 257) = (_cntlzw(v102) & 0x20) != 0;
    }
    if ( v108 != nullptr )
      v120 = (int)v108->GetVehicleInterface(this: v108);
    else
      v120 = 0;
    v121 = *(_DWORD *)(v120 + 16472);
    v122 = *(_DWORD *)(v121 + 16);
    v123 = v122 & 0x3FFF;
    if ( v122 != 0
      && idClientGame::IsPresentableIndexValid(this: clientGame, index: v122 & 0x3FFF)
      && (v124 = idClientGame::GetPresentableByIndex(this: clientGame, index: v123),
          v125 = *(_DWORD *)(v121 + 16),
          v124->spawnId == v125) )
    {
      v126 = *(_DWORD *)(v121 + 16) & 0x3FFF;
      if ( v125 == 0
        || !idClientGame::IsPresentableIndexValid(this: clientGame, index: *(_DWORD *)(v121 + 16) & 0x3FFF)
        || (v127 = idClientGame::GetPresentableByIndex(this: clientGame, index: v126))->spawnId != *(_DWORD *)(v121 + 16) )
      {
        v127 = nullptr;
      }
      v128 = v127->entity;
    }
    else
    {
      v128 = nullptr;
    }
    v129 = *(_DWORD *)(v128->GetType(this: v128) + 36);
    if ( v129 < idPlayer::Type.typeNum || (v101 = v129 <= idPlayer::Type.lastChild, v130 = 1, !v101) )
      v130 = 0;
    if ( v130 == 0 )
      goto LABEL_170;
    Physics = idEntity::GetPhysics(this);
    v132 = (idAngles *)Physics->GetAxis(this: Physics, a2: 0);
    idMat3::ToAngles(this: &v176, result: v132);
    v133 = this->presentable;
    if ( v133 != nullptr )
      v134 = v133->GetVehicleInterface(this: v133);
    else
      v134 = nullptr;
    Crosshair = idPresentableVehicle::GetCrosshair(this: v134);
    Crosshair->angles = (idAngles)v176.mat[0];
    v136 = this->presentable;
    if ( v136 != nullptr )
      v137 = v136->GetVehicleInterface(this: v136);
    else
      v137 = nullptr;
    v138 = idPresentableVehicle::GetCrosshair(this: v137);
    y = v176.mat[0].y;
    v140 = v176.mat[0].z;
    v141 = v176.mat[0].x;
    v138->goalAngles.pitch = v176.mat[0].x;
    v176.mat[1].z = y;
    v176.mat[2].x = v140;
    v176.mat[1].y = v141;
    v138->goalAngles.yaw = y;
  }
  else
  {
    v142 = this->presentable;
    if ( v142 != nullptr )
      v143 = v142->GetVehicleInterface(this: v142);
    else
      v143 = nullptr;
    idPresentableVehicle::GetCrosshair(this: v143)->angles = ang_zero;
    v144 = this->presentable;
    if ( v144 != nullptr )
      v145 = v144->GetVehicleInterface(this: v144);
    else
      v145 = nullptr;
    v138 = idPresentableVehicle::GetCrosshair(this: v145);
    yaw = ang_zero.yaw;
    roll = ang_zero.roll;
    pitch = ang_zero.pitch;
    v138->goalAngles.pitch = ang_zero.pitch;
    v176.mat[1].z = yaw;
    v138->goalAngles.yaw = yaw;
    v176.mat[2].x = roll;
    v176.mat[1].y = pitch;
  }
  v138->goalAngles.roll = v176.mat[2].x;
LABEL_170:
  v149 = this->presentable;
  if ( v149 != nullptr )
    v150 = (int)v149->GetVehicleInterface(this: v149);
  else
    v150 = 0;
  v151 = *(_DWORD **)(v150 + 16472);
  v152 = *v151 & 0x3FFF;
  if ( *v151 != 0
    && idClientGame::IsPresentableIndexValid(this: clientGame, index: *v151 & 0x3FFF)
    && idClientGame::GetPresentableByIndex(this: clientGame, index: v152)->spawnId == *v151 )
  {
    v153 = this->presentable;
    if ( v153 != nullptr )
      v154 = (int)v153->GetVehicleInterface(this: v153);
    else
      v154 = 0;
    v155 = *(_DWORD **)(v154 + 16472);
    v156 = *v155 & 0x3FFF;
    if ( *v155 != 0
      && idClientGame::IsPresentableIndexValid(this: clientGame, index: *v155 & 0x3FFF)
      && idClientGame::GetPresentableByIndex(this: clientGame, index: v156)->spawnId == *v155 )
    {
      v157 = *v155 & 0x3FFF;
      if ( *v155 == 0
        || !idClientGame::IsPresentableIndexValid(this: clientGame, index: *v155 & 0x3FFF)
        || (v158 = idClientGame::GetPresentableByIndex(this: clientGame, index: v157))->spawnId != *v155 )
      {
        v158 = nullptr;
      }
      v159 = v158->entity;
    }
    else
    {
      v159 = nullptr;
    }
    v160 = *(_DWORD *)(v159->GetType(this: v159) + 36);
    if ( v160 < idVehicleAI::Type.typeNum || (v101 = v160 <= idVehicleAI::Type.lastChild, v161 = 1, !v101) )
      v161 = 0;
    this->UseAiProperties(this, a2: v161 != 0);
  }
  v162 = this->presentable;
  if ( v162 != nullptr )
    v163 = v162->GetVehicleInterface(this: v162);
  else
    v163 = nullptr;
  idPresentableVehicle::ActivateCrosshair(this: v163);
  v164 = this->presentable;
  if ( v164 != nullptr )
    v165 = (int)v164->GetVehicleInterface(this: v164);
  else
    v165 = 0;
  v166 = *(_DWORD *)(v165 + 18764);
  v101 = v166 <= idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  p_gameTimeManager = &clientGame->gameTimeManager;
  if ( v101 )
  {
    GameMs = idGameTimeManager::GetGameMs(this: p_gameTimeManager, type: GAMETIME_SCALED);
    v174 = this->presentable;
    valueInteger = vehicle_seatTransitionTime.valueInteger;
    if ( v174 != nullptr )
      v174->GetVehicleInterface(this: this->presentable)->seatTransitionTime = valueInteger + GameMs;
    else
      MEMORY[0x494C] = vehicle_seatTransitionTime.valueInteger + GameMs;
  }
  else
  {
    v168 = idGameTimeManager::GetGameMs(this: p_gameTimeManager, type: GAMETIME_SCALED);
    v169 = this->presentable;
    v170 = v168;
    v171 = vehicle_seatTransitionTime.valueInteger;
    if ( v169 != nullptr )
      v172 = (int)v169->GetVehicleInterface(this: this->presentable);
    else
      v172 = 0;
    *(_DWORD *)(v172 + 18764) = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) + v171 - v166 + v170;
  }
}


// ========================================================================
// ?Respawn@idVehicle@@UAAXXZ
// EA  : 0x82D2CD10
// RVA : 0x00D2CD10
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __fastcall idVehicle::Respawn(idVehicle *this)
{
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idPresentable *presentable; // r11
  idTreeAnimator *v4; // r30
  idPhysics *Physics; // r3
  idPhysics *v6; // r3
  idPhysics *v7; // r3
  idVehicle_vtbl *v8; // r30

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
    idTreeAnimator::ClearMorphPoints(this: v4);
  Physics = idEntity::GetPhysics(this);
  Physics->SetLinearVelocity(this: Physics, a2: &vec3_origin, a3: 0);
  v6 = idEntity::GetPhysics(this);
  v6->SetAngularVelocity(this: v6, a2: &vec3_origin, a3: 0);
  v7 = idEntity::GetPhysics(this);
  v7->SetAxis(this: v7, a2: &mat3_identity, a3: -1);
  this->Show(this);
  v8 = this->__vftable;
  this->GetMaxHealth(this);
  ((void (__fastcall *)(idVehicle *))v8->SetHealth)(a1: this);
  idVehicle::RespawnArmorKit(this);
  this->IncreaseHealth(this, a2: this->maxArmoredHealth);
}


// ========================================================================
// ?InitDetachableItem@idVehicle@@QAAXAAUdetachable_t@@@Z
// EA  : 0x82D2CE48
// RVA : 0x00D2CE48
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idVehicle::InitDetachableItem(idVehicle *this, detachable_t *detachable)
{
  int v4; // r7
  int spikeDetachableFound; // r11
  int num; // r10
  char *data; // r28
  idIndex<short,enum invalidJointIndex_t> *TreeAnimatorFromPresentable; // r3
  __int16 *JointIndex; // r3
  const idDeclInventory *decl; // r11
  idStaticModel *thirdPersonStatic; // r11
  const char *str; // r28
  char *v13; // r27
  const idDeclMD6 *v14; // r11
  idPropsCollection *p_props; // r3
  const tagData_t *Tag; // r3
  int value; // r7
  __int128 v18; // r8 OVERLAPPED
  idGameLocal_vtbl *v19; // r27
  idProp_Moveable *v20; // r3
  idStaticModel *v21; // r11
  const idDecl *v22; // r28
  int v23; // r10
  int v24; // r11
  idSerializerLog::compressionEntry_t *v25; // r3
  const idDeclInventory *v26; // r11
  const idDeclInventory *v27; // r27
  idJobManager *v28; // r3
  idJob *JobByDecl; // r3
  __int64 v30; // [sp+8h] [-C8h]
  __int64 v31; // [sp+10h] [-C0h]
  __int64 v32; // [sp+18h] [-B8h]
  __int64 v33; // [sp+20h] [-B0h]
  __int64 v34; // [sp+28h] [-A8h]
  __int64 v35; // [sp+30h] [-A0h]
  __int64 v36; // [sp+38h] [-98h]
  __int64 v37; // [sp+40h] [-90h]
  __int64 v38; // [sp+48h] [-88h]
  idQuat *p_rot; // [sp+60h] [-70h] BYREF
  idStr v40[3]; // [sp+70h] [-60h] BYREF

  v4 = !detachable->decl->vehicleArmor - 1;
  if ( (v4 & (int)detachable->decl) != 0 && *(_BYTE *)((v4 & (int)detachable->decl) + 0x1FD) != 0 )
  {
    spikeDetachableFound = this->spikeDetachableFound;
    num = this->detachableItems.num;
    this->spikeDetachableFound = spikeDetachableFound + 1;
    p_rot = (idQuat *)spikeDetachableFound;
    this->spikeDetachableIndex.ptr[spikeDetachableFound] = num;
  }
  if ( detachable->jointIndex.value == NULL_JOINT_INDEX.value )
  {
    data = detachable->decl->vehicleJointName.data;
    TreeAnimatorFromPresentable = (idIndex<short,enum invalidJointIndex_t> *)idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
    JointIndex = (__int16 *)idTreeAnimator::GetJointIndex(
                              this: (idTreeAnimator *)&p_rot,
                              result: TreeAnimatorFromPresentable,
                              jointName: data);
    decl = detachable->decl;
    detachable->jointIndex.value = *JointIndex;
    if ( !decl->noAttachment )
    {
      thirdPersonStatic = decl->thirdPersonStatic;
      if ( thirdPersonStatic != nullptr )
      {
        str = thirdPersonStatic->name.str;
        v13 = detachable->tagName.data;
        v14 = idAnimatedEntity::GetTreeAnimatorFromPresentable(this)->decl;
        p_props = &v14->props;
        if ( v14 == nullptr )
          p_props = nullptr;
        Tag = idPropsCollection::GetTag(this: p_props, propName: str, tagName: v13);
        detachable->tagData.trans.x = Tag->trans.x;
        detachable->tagData.trans.y = Tag->trans.y;
        detachable->tagData.trans.z = Tag->trans.z;
        p_rot = &detachable->tagData.rot;
        detachable->tagData.rot = Tag->rot;
        value = Tag->parentJoint.value;
        detachable->tagData.parentJoint.value = Tag->parentJoint.value;
        if ( value == 0xFFFF )
          idLib::Warning(
            fmt: "Tag Data for detachable piece invalid! decl %s name %s tagName %s",
            detachable->decl->name.str,
            detachable->decl->thirdPersonStatic->name.str,
            detachable->tagName.data);
        if ( (com_production.valueInteger != 0 || (gameLocal->GetGameFlags(this: gameLocal) & 0x80) != 0)
          && detachable->decl->thirdPersonStatic != nullptr )
        {
          *(_QWORD *)((char *)&v18 + 4) = *(_QWORD *)&this->spawnOrientation.mat[0].x;
          v19 = gameLocal->__vftable;
          *((_QWORD *)&v18 + 1) = *(_QWORD *)&this->spawnOrientation.mat[0].z;
          *(_QWORD *)((char *)&v18 - 4) = *(_QWORD *)&this->spawnOrientation.mat[1].y;
          *(_QWORD *)((char *)&v18 + 12) = *(_QWORD *)&this->spawnPosition.x;
          v20 = idVehicle::SpawnArmorProp(
                  this,
                  name: (const char *)LODWORD(this->spawnPosition.x),
                  axis: *(__int64 *)&v18,
                  a4: v18,
                  a5: *(_QWORD *)&this->spawnOrientation.mat[2].x,
                  a6: v30,
                  a7: v31,
                  a8: v32,
                  a9: v33,
                  a10: v34,
                  a11: v35,
                  a12: v36,
                  a13: v37,
                  a14: v38);
          v19->DeleteEntity(this: gameLocal, a2: v20);
        }
      }
    }
    if ( !detachable->decl->noAttachment )
    {
      v21 = detachable->decl->thirdPersonStatic;
      if ( v21 != nullptr )
      {
        idStr::idStr(this: v40, text: v21->name.str);
        idStr::StripFileExtension(this: v40);
        if ( v40[0].data != nullptr )
          v22 = idDeclInfo::FindWithInheritance(this: &idDeclSkins::resourceList, name: v40[0].data, makeDefault: false);
        else
          v22 = nullptr;
        v23 = 0;
        p_rot = (idQuat *)this->itemSkinList.num;
        if ( (int)p_rot > 0 )
        {
          v24 = 0;
          do
          {
            if ( detachable->decl == this->itemSkinList.list[v24].declInventory )
              break;
            ++v23;
            ++v24;
          }
          while ( v23 < this->itemSkinList.num );
        }
        if ( (idQuat *)v23 == p_rot )
        {
          v25 = idList<idSerializerLog::compressionEntry_t,44>::Alloc(this: (idList<idSerializerLog::compressionEntry_t,44> *)&this->itemSkinList);
          v26 = detachable->decl;
          v25->csize = (int)v22;
          v25->objID = (int)v26;
        }
        v27 = detachable->decl;
        v28 = (idJobManager *)this->GetInventory_2(this);
        JobByDecl = idJobManager::FindJobByDecl(this: v28, jobDecl: (const idDeclJob *)v27);
        if ( JobByDecl != nullptr )
          JobByDecl->jobNotes.num = (int)v22;
        idStr::FreeData(this: v40);
      }
    }
  }
  idList<detachable_t,5>::Append(this: &this->detachableItems, obj: detachable);
}


// ========================================================================
// __unwind$531622
// EA  : 0x82D2D14C
// RVA : 0x00D2D14C
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void _unwind_531622()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 208 + 112));
}


// ========================================================================
// ?CheckThrowOccupant@idVehicle@@QAAXXZ
// EA  : 0x82D2D178
// RVA : 0x00D2D178
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __fastcall idVehicle::CheckThrowOccupant(idVehicle *this)
{
  idPresentable *presentable; // r3
  int v3; // r3
  int v4; // r22
  int v5; // r25
  int v6; // r29
  int i; // r26
  idPresentable *v8; // r3
  idPresentableVehicle *v9; // r3
  idPhysics *Physics; // r3
  idPhysics *v11; // r3
  idPhysics *v12; // r3
  float *v13; // r3
  double v14; // fp0
  idPresentable *v15; // r3
  double v16; // fp31
  float *v17; // r3
  idPresentable *v18; // r3
  int v19; // r3
  int v20; // r30
  int v21; // r11
  int v22; // r31
  idPresentable *v23; // r3
  int v24; // r11
  int v25; // r31
  idPresentable *PresentableByIndex; // r3
  idActor *entity; // r3
  idPresentable *v28; // r3
  int v29; // r31
  idPresentable *v30; // r3
  int v31; // r11
  __int128 v32; // r8
  float v33; // [sp+50h] [-90h] BYREF
  float v34; // [sp+54h] [-8Ch]
  float v35; // [sp+58h] [-88h]
  char v36; // [sp+60h] [-80h] BYREF

  presentable = this->presentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    presentable = this->presentable;
  }
  v3 = (int)presentable->GetVehicleInterface(this: presentable);
  if ( v3 != 0 )
    v4 = *(_DWORD *)(v3 + 17752);
  else
    v4 = 4;
  v5 = 0;
  v6 = 0;
  for ( i = 0; ; ++i )
  {
    v8 = this->presentable;
    v9 = v8 != nullptr ? v8->GetVehicleInterface(this: v8) : nullptr;
    if ( v5 >= idPresentableVehicle::GetNumActiveOccupants(this: v9) )
      break;
    if ( this->seatInfo.list[i].isEasilyThrown )
    {
      Physics = idEntity::GetPhysics(this);
      Physics->GetLinearVelocity(this: (idPhysics *)&v33, result: (idVec3 *)Physics, a3: 0);
      v11 = idEntity::GetPhysics(this);
      v11->GetAngularVelocity(this: (idPhysics *)&v36, result: (idVec3 *)v11, a3: 0);
      v12 = idEntity::GetPhysics(this);
      v13 = (float *)v12->GetAxis(this: v12, a2: 0);
      v14 = (float)((float)(v13[6] * vec3_up.x) + (float)((float)(v13[7] * vec3_up.y) + (float)(v13[8] * vec3_up.z)));
      if ( v14 < 0.173648 && v4 > 0 )
        goto LABEL_19;
      if ( v14 < 0.0
        || ((v15 = this->presentable,
             v16 = __fsqrts((float)((float)(v33 * v33) + (float)((float)(v34 * v34) + (float)(v35 * v35)))),
             v15 == nullptr)
          ? (v17 = nullptr)
          : (v17 = (float *)v15->GetVehicleInterface(this: v15)),
            __fabs((float)((float)v16
                         - (float)__fsqrts((float)((float)(v17[5096] * v17[5096])
                                                 + (float)((float)(v17[5094] * v17[5094])
                                                         + (float)(v17[5095] * v17[5095])))))) > vehicle_throwDelta.valueFloat) )
      {
LABEL_19:
        v18 = this->presentable;
        if ( v18 != nullptr )
          v19 = (int)v18->GetVehicleInterface(this: v18);
        else
          v19 = 0;
        v20 = *(_DWORD *)(v19 + 16472);
        v21 = *(_DWORD *)(v20 + v6);
        v22 = v21 & 0x3FFF;
        if ( v21 != 0
          && idClientGame::IsPresentableIndexValid(this: clientGame, index: v21 & 0x3FFF)
          && (v23 = idClientGame::GetPresentableByIndex(this: clientGame, index: v22),
              v24 = *(_DWORD *)(v20 + v6),
              v23->spawnId == v24) )
        {
          v25 = *(_DWORD *)(v20 + v6) & 0x3FFF;
          if ( v24 == 0
            || !idClientGame::IsPresentableIndexValid(this: clientGame, index: *(_DWORD *)(v20 + v6) & 0x3FFF)
            || (PresentableByIndex = idClientGame::GetPresentableByIndex(this: clientGame, index: v25))->spawnId != *(_DWORD *)(v20 + v6) )
          {
            PresentableByIndex = nullptr;
          }
          entity = (idActor *)PresentableByIndex->entity;
        }
        else
        {
          entity = nullptr;
        }
        if ( idActor::CastTo(c: entity) != nullptr )
        {
          v28 = this->presentable;
          if ( v28 != nullptr )
            v29 = (int)v28->GetVehicleInterface(this: v28);
          else
            v29 = 0;
          v30 = this->presentable;
          if ( v30 != nullptr )
            v31 = (int)v30->GetVehicleInterface(this: v30);
          else
            v31 = 0;
          LODWORD(v32) = __ROL4__(*(_DWORD *)(v29 + 20396), 32);
          *(_QWORD *)((char *)&v32 + 4) = *(_QWORD *)(v29 + 20388);
          idVehicle::ThrowActor(
            this,
            actor: *(idPlayer **)(v31 + 20376),
            velocity: *(idVec3 **)(v31 + 20380),
            angularVelocity: v32);
        }
      }
    }
    ++v5;
    v6 += 16;
  }
}


// ========================================================================
// ?CheckImpulseServerOnly@idVehicle@@QAAXW4vehicleSeat_t@@AAVusercmd_t@@1@Z
// EA  : 0x82D2D4C8
// RVA : 0x00D2D4C8
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __fastcall idVehicle::CheckImpulseServerOnly(idVehicle *this, int seat, usercmd_t *prevcmd, usercmd_t *usercmd)
{
  int buttons; // r11
  int v9; // r11
  int v10; // r11
  int v11; // r11
  int v12; // r11
  int v13; // r11
  idPlayer *v14; // r3
  idPresentable *presentable; // r3
  idPresentableVehicle *v16; // r3
  idPresentablePlayer *PlayerDriver; // r31
  idLobbyBase *v18; // r3
  idPresentableProjectile *UniqueProjectile; // r3
  idPresentableProjectile *v20; // r29
  const idDeclProjectile *projectileDecl; // r11
  int v22; // r31
  int v23; // r3
  int v24; // r11
  char v25; // r10
  idPhysics *projectilePhysics; // r3
  double x; // fp11
  double v28; // fp9
  float v29[16]; // [sp+50h] [-40h] BYREF

  LOWORD(buttons) = 0;
  if ( (*((_BYTE *)usercmd + 9) & 0x80) == 0 )
    buttons = usercmd->buttons;
  if ( (buttons & 0x8000) == 0 )
  {
    LOWORD(v9) = 0;
    if ( (*((_BYTE *)prevcmd + 9) & 0x80) == 0 )
      v9 = prevcmd->buttons;
    if ( (v9 & 0x8000) != 0 )
    {
      if ( this->exitButtonDownOnEnter )
        this->exitButtonDownOnEnter = false;
      else
        this->ExitVehicle(this, a2: seat, a3: false, a4: false);
    }
  }
  v10 = 0;
  if ( (*((_BYTE *)usercmd + 9) & 0x80) == 0 )
    v10 = usercmd->buttons;
  if ( (v10 & 0x2000000) == 0 )
  {
    v11 = 0;
    if ( (*((_BYTE *)prevcmd + 9) & 0x80) == 0 )
      v11 = prevcmd->buttons;
    if ( (v11 & 0x2000000) != 0 )
      idVehicle::SwitchSeatPosition(this, _seat: seat, force: 0);
  }
  v12 = 0;
  if ( (*((_BYTE *)usercmd + 9) & 0x80) == 0 )
    v12 = usercmd->buttons;
  if ( (v12 & 0x8000000) == 0 )
  {
    v13 = 0;
    if ( (*((_BYTE *)prevcmd + 9) & 0x80) == 0 )
      v13 = prevcmd->buttons;
    if ( (v13 & 0x8000000) != 0 )
    {
      v14 = idVehicle::PlayerIsOccupant(this);
      if ( v14 != nullptr && seat != 1 )
        idPlayer::ShowInventory(this: v14, inVehicle: true);
    }
  }
  presentable = this->presentable;
  if ( presentable != nullptr )
    v16 = presentable->GetVehicleInterface(this: presentable);
  else
    v16 = nullptr;
  PlayerDriver = idPresentableVehicle::GetPlayerDriver(this: v16);
  if ( common->IsMultiplayer(this: common) )
  {
    v18 = session->GetActingGameStateLobbyBase(this: session);
    if ( v18->GetMatchParms(this: v18)->gameType == 2 && PlayerDriver != nullptr )
    {
      UniqueProjectile = (idPresentableProjectile *)idPresentablePlayer::GetUniqueProjectile(this: PlayerDriver);
      v20 = UniqueProjectile;
      if ( UniqueProjectile != nullptr )
      {
        projectileDecl = UniqueProjectile->projectileDecl;
        if ( projectileDecl != nullptr
          && projectileDecl->notHitscanInfo.allowOnlyOne
          && idPresentableProjectile::IsActive(this: UniqueProjectile) )
        {
          v22 = PlayerDriver->uniqueTrackedProjectileClientGameFrameWhenFired;
          v23 = common->IsServer(this: common)
              ? idAccolade::Count(this: &clientGame->gameTimeManager)
              : usercmd->clientGameFrame;
          if ( v22 != -1 && v23 > projectile_InFlightControlGravityScaleDelay.valueInteger + v22 )
          {
            LOBYTE(v24) = 0;
            if ( (*((_BYTE *)prevcmd + 9) & 0x80) == 0 )
              v24 = prevcmd->buttons;
            v25 = v24 & 1;
            LOBYTE(v24) = 0;
            if ( (*((_BYTE *)usercmd + 9) & 0x80) == 0 )
              v24 = usercmd->buttons;
            if ( (v24 & 1) != 0 && v25 == 0 )
            {
              projectilePhysics = v20->projectilePhysics;
              x = clientGame->gravity.x;
              v28 = (float)(clientGame->gravity.y * projectile_InFlightControlGravityScale.valueFloat);
              v29[2] = clientGame->gravity.z * projectile_InFlightControlGravityScale.valueFloat;
              v29[1] = v28;
              v29[0] = (float)x * projectile_InFlightControlGravityScale.valueFloat;
              projectilePhysics->SetGravity(this: projectilePhysics, a2: (const idVec3 *)v29);
            }
          }
        }
      }
    }
  }
}


// ========================================================================
// ??1idVehicle@@UAA@XZ
// EA  : 0x82D2DC58
// RVA : 0x00D2DC58
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __fastcall idVehicle::~idVehicle(idVehicle *this)
{
  idPresentable *presentable; // r3
  signed int v3; // r26
  int i; // r27
  idPresentable *v5; // r3
  int v6; // r3
  idPresentable *v7; // r3
  int v8; // r3
  int v9; // r28
  int v10; // r11
  int v11; // r29
  int v12; // r28
  int v13; // r29
  idRenderModel *model; // r3
  idPresentable *v15; // r3
  idPresentableVehicle *v16; // r3
  idAttachmentCollection *p_attachments; // r26
  const idDeclVehicleProps *vehicleProps; // r3
  int v19; // r28
  int v20; // r29
  idClipModel *collisionModel; // r3
  char *list; // r3
  idEntityPtr<idEntity> *v23; // r4
  const idDeclWeapon **v24; // r4
  idInventoryAttachmentDef *v25; // r4
  idVehicle::playerRewardForKilling_t *v26; // r4
  idVehicle::seatInfo_t *v27; // r27
  int size; // r29
  idVehicle::seatInfo_t *v29; // r28
  idVehicle::itemSkinRef_t *v30; // r4
  idVehicle::eventAnimEntry_t *v31; // r27
  int v32; // r29
  idVehicle::eventAnimEntry_t *v33; // r28
  detachable_t *v34; // r27
  int v35; // r29
  idStr *p_tagName; // r28

  this->__vftable = (idVehicle_vtbl *)&idVehicle::`vftable';
  presentable = this->presentable;
  if ( presentable != nullptr && presentable->GetVehicleInterface(this: presentable) != nullptr )
  {
    v3 = 0;
    for ( i = 0; ; i += 16 )
    {
      v5 = this->presentable;
      v6 = v5 != nullptr ? (int)v5->GetVehicleInterface(this: v5) : 0;
      if ( v3 >= *(_DWORD *)(v6 + 16476) )
        break;
      v7 = this->presentable;
      if ( v7 != nullptr )
        v8 = (int)v7->GetVehicleInterface(this: v7);
      else
        v8 = 0;
      v9 = *(_DWORD *)(v8 + 16472) + i;
      v10 = *(_DWORD *)(v9 + 4);
      v11 = v10 & 0x3FFF;
      if ( v10 != 0
        && idClientGame::IsPresentableIndexValid(this: clientGame, index: v10 & 0x3FFF)
        && idClientGame::GetPresentableByIndex(this: clientGame, index: v11)->spawnId == *(_DWORD *)(v9 + 4) )
      {
        idVehicle::ExitVehicle(this, occupant: v3, force: false, thrown: false);
      }
      ++v3;
    }
  }
  mediaPlayer->Stop(this: mediaPlayer);
  idEntity::StopSound(this, channel: SND_CHANNEL_ANY, peerMask: 0xFFu);
  v12 = 0;
  if ( this->seatInfo.num > 0 )
  {
    v13 = 0;
    do
    {
      model = this->seatInfo.list[v13].model;
      if ( model != nullptr )
      {
        if ( (int)model > 10000 )
        {
          model->unlinked = true;
          model->deleteOnSync = true;
          idRenderModel::CommitThisFrame(this: model);
        }
        this->seatInfo.list[v13].model = nullptr;
      }
      ++v12;
      ++v13;
    }
    while ( v12 < this->seatInfo.num );
  }
  this->controlNode.prev->next = this->controlNode.next;
  this->controlNode.next->prev = this->controlNode.prev;
  this->controlNode.next = &this->controlNode;
  this->controlNode.prev = &this->controlNode;
  this->controlNode.head = &this->controlNode;
  v15 = this->presentable;
  if ( v15 != nullptr )
  {
    v16 = v15->GetVehicleInterface(this: v15);
    idPresentableVehicle::DeleteWeapons(this: v16);
  }
  p_attachments = &this->attachments;
  idAttachmentCollection::FreeAttachments(this: &this->attachments);
  idVehicle::RemoveAIEvents(this);
  vehicleProps = this->vehicleProps;
  if ( vehicleProps != nullptr && this->cleanUpVehicleProps )
  {
    ((void (__fastcall *)(const idDeclVehicleProps *, int))vehicleProps->dtr_idResource)(a1: vehicleProps, a2: 1);
    this->vehicleProps = nullptr;
  }
  v19 = 0;
  if ( this->vehicleWindow.windows.num > 0 )
  {
    v20 = 0;
    do
    {
      collisionModel = this->vehicleWindow.windows.list[v20].collisionModel;
      if ( collisionModel != nullptr )
      {
        idClipModel::Delete(this: collisionModel);
        this->vehicleWindow.windows.list[v20].collisionModel = nullptr;
      }
      ++v19;
      ++v20;
    }
    while ( v19 < this->vehicleWindow.windows.num );
  }
  idDynamicCoverMgr::Shutdown(this: &this->vehicleCover);
  idVehicle::eventAnimSupport_t::~eventAnimSupport_t(this: &this->eventAnimSupport);
  idDynamicCoverMgr::~idDynamicCoverMgr(this: &this->vehicleCover);
  idAnimator_Channel::~idAnimator_Channel(this: &this->eventAnimatorLegs);
  idAnimator_Channel::~idAnimator_Channel(this: &this->eventAnimatorHands);
  idAnimator_Channel::~idAnimator_Channel(this: &this->eventAnimator);
  idAnimator_VehicleCar::~idAnimator_VehicleCar(this: &this->vehicleAnimator);
  if ( this->vehicleWindow.windows.listStatic == 0 || this->vehicleWindow.windows.listStatic == 2 )
  {
    list = (char *)this->vehicleWindow.windows.list;
    if ( list != nullptr )
      idListArrayDelete<idVehicleWindow::window_t>(ptr: list, num: this->vehicleWindow.windows.size);
    this->vehicleWindow.windows.list = nullptr;
    this->vehicleWindow.windows.size = 0;
  }
  this->vehicleWindow.windows.num = 0;
  idLinkList<idEvent>::Clear(this: (idLinkList<idProp_VehiclePickup> *)&this->controlNode);
  if ( this->touching.listStatic == 0 || this->touching.listStatic == 2 )
  {
    v23 = this->touching.list;
    if ( v23 != nullptr )
      idMem::Free(this: &mem, ptr: v23, align: ALIGN_16);
    this->touching.list = nullptr;
    this->touching.size = 0;
  }
  this->touching.num = 0;
  if ( this->attachments.attachments.listStatic == 0 || this->attachments.attachments.listStatic == 2 )
  {
    if ( p_attachments->attachments.list != nullptr )
      idMem::Free(this: &mem, ptr: p_attachments->attachments.list, align: ALIGN_16);
    p_attachments->attachments.list = nullptr;
    this->attachments.attachments.size = 0;
  }
  this->attachments.attachments.num = 0;
  if ( this->startingWeapons.listStatic == 0 || this->startingWeapons.listStatic == 2 )
  {
    v24 = this->startingWeapons.list;
    if ( v24 != nullptr )
      idMem::Free(this: &mem, ptr: v24, align: ALIGN_16);
    this->startingWeapons.list = nullptr;
    this->startingWeapons.size = 0;
  }
  this->startingWeapons.num = 0;
  if ( this->startingInventory.listStatic == 0 || this->startingInventory.listStatic == 2 )
  {
    v25 = this->startingInventory.list;
    if ( v25 != nullptr )
      idMem::Free(this: &mem, ptr: v25, align: ALIGN_16);
    this->startingInventory.list = nullptr;
    this->startingInventory.size = 0;
  }
  this->startingInventory.num = 0;
  if ( this->playerRewardsForKilling.listStatic == 0 || this->playerRewardsForKilling.listStatic == 2 )
  {
    v26 = this->playerRewardsForKilling.list;
    if ( v26 != nullptr )
      idMem::Free(this: &mem, ptr: v26, align: ALIGN_16);
    this->playerRewardsForKilling.list = nullptr;
    this->playerRewardsForKilling.size = 0;
  }
  this->playerRewardsForKilling.num = 0;
  idVehicleKey::~idVehicleKey(this: &this->tempPlayerKey);
  idStr::FreeData(this: &this->driverName);
  idStr::FreeData(this: &this->forceEntryTagName);
  if ( this->seatInfo.listStatic == 0 || this->seatInfo.listStatic == 2 )
  {
    v27 = this->seatInfo.list;
    if ( v27 != nullptr )
    {
      size = this->seatInfo.size;
      if ( size > 0 )
      {
        v29 = this->seatInfo.list;
        do
        {
          idVehicle::seatInfo_t::~seatInfo_t(this: v29);
          --size;
          ++v29;
        }
        while ( size != 0 );
      }
      idMem::Free(this: &mem, ptr: v27, align: ALIGN_16);
    }
    this->seatInfo.list = nullptr;
    this->seatInfo.size = 0;
  }
  this->seatInfo.num = 0;
  if ( this->itemSkinList.listStatic == 0 || this->itemSkinList.listStatic == 2 )
  {
    v30 = this->itemSkinList.list;
    if ( v30 != nullptr )
      idMem::Free(this: &mem, ptr: v30, align: ALIGN_16);
    this->itemSkinList.list = nullptr;
    this->itemSkinList.size = 0;
  }
  this->itemSkinList.num = 0;
  if ( this->eventAnimList.listStatic == 0 || this->eventAnimList.listStatic == 2 )
  {
    v31 = this->eventAnimList.list;
    if ( v31 != nullptr )
    {
      v32 = this->eventAnimList.size;
      if ( v32 > 0 )
      {
        v33 = this->eventAnimList.list;
        do
        {
          idVehicle::eventAnimEntry_t::~eventAnimEntry_t(this: v33);
          --v32;
          ++v33;
        }
        while ( v32 != 0 );
      }
      idMem::Free(this: &mem, ptr: v31, align: ALIGN_16);
    }
    this->eventAnimList.list = nullptr;
    this->eventAnimList.size = 0;
  }
  this->eventAnimList.num = 0;
  idStr::FreeData(this: &this->normalSkin);
  idStaticList<detachable_t,70>::~idStaticList<detachable_t,70>(this: &this->detachableItems);
  if ( this->detachableItemsBaseList.listStatic == 0 || this->detachableItemsBaseList.listStatic == 2 )
  {
    v34 = this->detachableItemsBaseList.list;
    if ( v34 != nullptr )
    {
      v35 = this->detachableItemsBaseList.size;
      if ( v35 > 0 )
      {
        p_tagName = &v34->tagName;
        do
        {
          idStr::FreeData(this: p_tagName);
          --v35;
          p_tagName = (idStr *)((char *)p_tagName + 124);
        }
        while ( v35 != 0 );
      }
      idMem::Free(this: &mem, ptr: v34, align: ALIGN_16);
    }
    this->detachableItemsBaseList.list = nullptr;
    this->detachableItemsBaseList.size = 0;
  }
  this->detachableItemsBaseList.num = 0;
  idAnimatedEntity::~idAnimatedEntity(this);
}


// ========================================================================
// __unwind$532693
// EA  : 0x82D2E220
// RVA : 0x00D2E220
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void _unwind_532693()
{
  int v0; // r12

  idAnimatedEntity::~idAnimatedEntity(this: *(idAnimatedEntity **)(v0 - 160 + 180));
}


// ========================================================================
// __unwind$532694
// EA  : 0x82D2E248
// RVA : 0x00D2E248
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void _unwind_532694()
{
  int v0; // r12

  idList<detachable_t,5>::Clear(this: (idList<detachable_t,5> *)(*(_DWORD *)(v0 - 160 + 180) + 5204));
}


// ========================================================================
// __unwind$532695
// EA  : 0x82D2E274
// RVA : 0x00D2E274
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void _unwind_532695()
{
  int v0; // r12

  idStaticList<detachable_t,70>::~idStaticList<detachable_t,70>(this: (idStaticList<detachable_t,70> *)(*(_DWORD *)(v0 - 160 + 180) + 5220));
}


// ========================================================================
// __unwind$532696
// EA  : 0x82D2E2A0
// RVA : 0x00D2E2A0
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void _unwind_532696()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 160 + 180) + 13920));
}


// ========================================================================
// __unwind$532697
// EA  : 0x82D2E2CC
// RVA : 0x00D2E2CC
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void _unwind_532697()
{
  int v0; // r12

  idList<idVehicle::eventAnimEntry_t,5>::~idList<idVehicle::eventAnimEntry_t,5>(this: (idList<idVehicle::eventAnimEntry_t,5> *)(*(_DWORD *)(v0 - 160 + 180) + 13980));
}


// ========================================================================
// __unwind$532698
// EA  : 0x82D2E2F8
// RVA : 0x00D2E2F8
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void _unwind_532698()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 13996));
}


// ========================================================================
// __unwind$532699
// EA  : 0x82D2E324
// RVA : 0x00D2E324
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void _unwind_532699()
{
  int v0; // r12

  idList<idVehicle::seatInfo_t,5>::Clear(this: (idList<idVehicle::seatInfo_t,5> *)(*(_DWORD *)(v0 - 160 + 180) + 14416));
}


// ========================================================================
// __unwind$532700
// EA  : 0x82D2E350
// RVA : 0x00D2E350
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void _unwind_532700()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 160 + 180) + 14432));
}


// ========================================================================
// __unwind$532701
// EA  : 0x82D2E37C
// RVA : 0x00D2E37C
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void _unwind_532701()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 160 + 180) + 14496));
}


// ========================================================================
// __unwind$532702
// EA  : 0x82D2E3A8
// RVA : 0x00D2E3A8
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void _unwind_532702()
{
  int v0; // r12

  idVehicleKey::~idVehicleKey(this: (idVehicleKey *)(*(_DWORD *)(v0 - 160 + 180) + 14540));
}


// ========================================================================
// __unwind$532703
// EA  : 0x82D2E3D4
// RVA : 0x00D2E3D4
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void _unwind_532703()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 15604));
}


// ========================================================================
// __unwind$532704
// EA  : 0x82D2E400
// RVA : 0x00D2E400
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void _unwind_532704()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 15624));
}


// ========================================================================
// __unwind$532705
// EA  : 0x82D2E42C
// RVA : 0x00D2E42C
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void _unwind_532705()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 15664));
}


// ========================================================================
// __unwind$532706
// EA  : 0x82D2E458
// RVA : 0x00D2E458
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void _unwind_532706()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 15684));
}


// ========================================================================
// __unwind$532707
// EA  : 0x82D2E484
// RVA : 0x00D2E484
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void _unwind_532707()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 16004));
}


// ========================================================================
// __unwind$532708
// EA  : 0x82D2E4B0
// RVA : 0x00D2E4B0
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void _unwind_532708()
{
  int v0; // r12

  idLinkList<idWaypoint>::~idLinkList<idWaypoint>(this: (idLinkList<idProp_VehiclePickup> *)(*(_DWORD *)(v0 - 160 + 180)
                                                                                           + 16040));
}


// ========================================================================
// __unwind$532709
// EA  : 0x82D2E4DC
// RVA : 0x00D2E4DC
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void _unwind_532709()
{
  int v0; // r12

  idList<idVehicleWindow::window_t,5>::Clear(this: (idVehicleWindow *)(*(_DWORD *)(v0 - 160 + 180) + 16092));
}


// ========================================================================
// __unwind$532710
// EA  : 0x82D2E508
// RVA : 0x00D2E508
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void _unwind_532710()
{
  int v0; // r12

  idAnimator_VehicleCar::~idAnimator_VehicleCar(this: (idAnimator_VehicleCar *)(*(_DWORD *)(v0 - 160 + 180) + 16120));
}


// ========================================================================
// __unwind$532711
// EA  : 0x82D2E534
// RVA : 0x00D2E534
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void _unwind_532711()
{
  int v0; // r12

  idAnimator_Channel::~idAnimator_Channel(this: (idAnimator_Channel *)(*(_DWORD *)(v0 - 160 + 180) + 16276));
}


// ========================================================================
// __unwind$532712
// EA  : 0x82D2E560
// RVA : 0x00D2E560
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void _unwind_532712()
{
  int v0; // r12

  idAnimator_Channel::~idAnimator_Channel(this: (idAnimator_Channel *)(*(_DWORD *)(v0 - 160 + 180) + 16372));
}


// ========================================================================
// __unwind$532713
// EA  : 0x82D2E58C
// RVA : 0x00D2E58C
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void _unwind_532713()
{
  int v0; // r12

  idAnimator_Channel::~idAnimator_Channel(this: (idAnimator_Channel *)(*(_DWORD *)(v0 - 160 + 180) + 16468));
}


// ========================================================================
// __unwind$532714
// EA  : 0x82D2E5B8
// RVA : 0x00D2E5B8
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void _unwind_532714()
{
  int v0; // r12

  idFormationCoverMgr::~idFormationCoverMgr(this: (idVehicleCoverMgr *)(*(_DWORD *)(v0 - 160 + 180) + 16564));
}


// ========================================================================
// __unwind$532715
// EA  : 0x82D2E5E4
// RVA : 0x00D2E5E4
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void _unwind_532715()
{
  int v0; // r12

  idVehicle::eventAnimSupport_t::~eventAnimSupport_t(this: (idVehicle::eventAnimSupport_t *)(*(_DWORD *)(v0 - 160 + 180)
                                                                                           + 16588));
}


// ========================================================================
// ??0idVehicle@@QAA@XZ
// EA  : 0x82D2EA30
// RVA : 0x00D2EA30
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

idVehicle *__fastcall idVehicle::idVehicle(idVehicle *this)
{
  __int16 *p_granularity; // r11
  int i; // ctr
  int v4; // r25
  idLinkList<idVehicle> *head; // r11
  int num; // r11
  idDeclSource **list; // r10
  int v8; // r28
  const char **p_str; // r9
  const idDeclRenderParm *v10; // r3

  idAnimatedEntity::idAnimatedEntity(this);
  this->__vftable = (idVehicle_vtbl *)&idVehicle::`vftable';
  this->detachableItemsBaseList.granularity = 0;
  this->detachableItemsBaseList.memTag = 5;
  this->detachableItemsBaseList.listStatic = 0;
  this->detachableItemsBaseList.list = nullptr;
  this->detachableItemsBaseList.size = 0;
  this->detachableItemsBaseList.num = 0;
  idStaticList<detachable_t,70>::idStaticList<detachable_t,70>(this: &this->detachableItems);
  this->normalSkin.len = 0;
  this->normalSkin.allocedAndFlag = 20;
  this->normalSkin.data = this->normalSkin.baseBuffer;
  this->normalSkin.baseBuffer[0] = 0;
  this->eventAnimList.granularity = 0;
  this->eventAnimList.memTag = 5;
  this->eventAnimList.listStatic = 0;
  this->eventAnimList.list = nullptr;
  this->eventAnimList.size = 0;
  this->eventAnimList.num = 0;
  this->itemSkinList.num = 0;
  this->itemSkinList.memTag = 5;
  this->itemSkinList.size = 50;
  this->itemSkinList.list = this->itemSkinList.staticList;
  p_granularity = &this->itemSkinList.granularity;
  this->itemSkinList.granularity = 1;
  this->itemSkinList.listStatic = 1;
  for ( i = 50; i != 0; --i )
  {
    *((_DWORD *)p_granularity + 1) = 0;
    p_granularity += 4;
    *(_DWORD *)p_granularity = 0;
  }
  this->seatInfo.granularity = 0;
  this->seatInfo.memTag = 5;
  this->seatInfo.listStatic = 0;
  this->seatInfo.list = nullptr;
  this->seatInfo.size = 0;
  this->seatInfo.num = 0;
  this->forceEntryTagName.allocedAndFlag = 20;
  this->forceEntryTagName.len = 0;
  this->forceEntryTagName.data = this->forceEntryTagName.baseBuffer;
  this->forceEntryTagName.baseBuffer[0] = 0;
  this->forceEntryTagData.trans.x = 0.0;
  this->forceEntryTagData.trans.y = 0.0;
  this->forceEntryTagData.trans.z = 0.0;
  this->forceEntryTagData.rot.x = 0.0;
  this->forceEntryTagData.rot.y = 0.0;
  this->forceEntryTagData.rot.z = 0.0;
  this->forceEntryTagData.rot.w = 0.0;
  this->forceEntryTagData.parentJoint.value = -1;
  this->driverName.allocedAndFlag = 20;
  this->driverName.data = this->driverName.baseBuffer;
  this->driverName.len = 0;
  this->driverName.baseBuffer[0] = 0;
  this->cachedPlayerDriver.spawnId.value = 0x1FFF;
  idVehicleKey::idVehicleKey(this: &this->tempPlayerKey);
  this->playerRewardsForKilling.list = nullptr;
  this->playerRewardsForKilling.granularity = 0;
  this->playerRewardsForKilling.memTag = 5;
  this->playerRewardsForKilling.listStatic = 0;
  this->playerRewardsForKilling.size = 0;
  this->playerRewardsForKilling.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->playerRewardsForKilling);
  this->targetToActivateOnDeath.spawnId.value = 0x1FFF;
  this->startingInventory.list = nullptr;
  this->startingInventory.granularity = 0;
  this->startingInventory.memTag = 5;
  this->startingInventory.listStatic = 0;
  this->startingInventory.size = 0;
  this->startingInventory.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->startingInventory);
  this->startingWeapons.list = nullptr;
  this->startingWeapons.granularity = 0;
  this->startingWeapons.memTag = 5;
  this->startingWeapons.listStatic = 0;
  this->startingWeapons.size = 0;
  this->startingWeapons.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->startingWeapons);
  idMQBuffer::idMQBuffer(this: &this->attachments);
  this->lastDamage.attacker.spawnId.value = 0x1FFF;
  this->lastDamage.actor.spawnId.value = 0x1FFF;
  this->lastDamage.inflictor.spawnId.value = 0x1FFF;
  this->lastDamage.attacker.spawnId.value = 0x1FFF;
  this->lastDamage.damage = 0.0;
  this->lastDamage.damageDef = nullptr;
  this->lastDamage.time = 0;
  this->lastDamage.actor.spawnId.value = 0x1FFF;
  this->lastDamage.actorTime = 0;
  this->touching.list = nullptr;
  this->touching.granularity = 0;
  this->touching.memTag = 5;
  this->touching.listStatic = 0;
  this->touching.size = 0;
  this->touching.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->touching);
  this->eventHandles[0].value = -1;
  this->eventHandles[1].value = -1;
  this->controlNode.head = &this->controlNode;
  this->controlNode.owner = nullptr;
  this->controlNode.next = &this->controlNode;
  this->controlNode.prev = &this->controlNode;
  this->collisionDamageAttacker.spawnId.value = 0x1FFF;
  this->vehicleWindow.windows.granularity = 0;
  this->vehicleWindow.windows.memTag = 5;
  this->vehicleWindow.windows.listStatic = 0;
  this->vehicleWindow.windows.list = nullptr;
  this->vehicleWindow.windows.size = 0;
  this->vehicleWindow.windows.num = 0;
  this->influenceTrail.value = -1;
  idAnimator_VehicleCar::idAnimator_VehicleCar(this: &this->vehicleAnimator);
  idAnimator_Channel::idAnimator_Channel(this: &this->eventAnimator);
  idAnimator_Channel::idAnimator_Channel(this: &this->eventAnimatorHands);
  idAnimator_Channel::idAnimator_Channel(this: &this->eventAnimatorLegs);
  idDynamicCoverMgr::idDynamicCoverMgr(this: &this->vehicleCover);
  this->vehicleCover.__vftable = (idVehicleCoverMgr_vtbl *)&idVehicleCoverMgr::`vftable';
  idVehicle::eventAnimSupport_t::eventAnimSupport_t(this: &this->eventAnimSupport);
  this->isUsable = true;
  this->lastDrawTime = 0;
  this->giveRewardWhenKilled = true;
  this->materialTheme = VMT_BUGGY;
  this->vehicleClass = VEHICLE_CLASSNONE;
  this->respawnInGarageTime = 0;
  this->allowWeaponChange = true;
  this->inventoryItem = nullptr;
  idList<idVehicle::seatInfo_t,5>::Alloc(this: &this->seatInfo);
  this->cachedPlayerDriver.spawnId.value = 0x1FFF;
  this->healthScaledDamage = 0.0;
  this->maxArmoredHealth = 0.0;
  this->keys = nullptr;
  this->lastDamage.damage = 0.0;
  this->playerKey = nullptr;
  this->tiresSpiked = nullptr;
  this->tiresUpgraded = nullptr;
  this->tiresUpgradedSpiked = nullptr;
  this->damageAiSpeed = -1.0;
  this->provideDynamicCover = false;
  this->maxHealth = 1000.0;
  this->hasInfiniteAmmo = false;
  this->mpMaxHealth = 4500.0;
  this->enterIcon = nullptr;
  this->health = 1000.0;
  this->attachments.parent = this;
  this->lastMaxArmoredHealthFromKey = false;
  this->alternateEngine = nullptr;
  this->lastDamage.damageDef = nullptr;
  this->lastDamage.time = 0;
  this->overallDamageScale = 1.0;
  this->exitVehicleZDelta = -8.0;
  this->aiTargetPos.ptr[0] = vec3_origin;
  this->aiTargetPos.ptr[1] = vec3_origin;
  this->aiTargetPos.ptr[2] = vec3_origin;
  this->aiTargetPos.ptr[3] = vec3_origin;
  this->aiTargetPos.ptr[4] = vec3_origin;
  this->aiTargetPos.ptr[5] = vec3_origin;
  this->aiTargetPos.ptr[6] = vec3_origin;
  this->aiTargetPos.ptr[7] = vec3_origin;
  this->armorPropDef = nullptr;
  this->occupantDef = nullptr;
  this->passengerOccupantDef = nullptr;
  this->freeAngles.roll = 0.0;
  this->freeAngles.yaw = 0.0;
  this->freeAngles.pitch = 0.0;
  this->currentViewAngles.roll = 0.0;
  this->currentViewAngles.yaw = 0.0;
  this->currentViewAngles.pitch = 0.0;
  this->lastCarAngles.roll = 0.0;
  this->lastCarAngles.yaw = 0.0;
  this->lastCarAngles.pitch = 0.0;
  this->minDriverViewAngles.pitch = -180.0;
  this->minDriverViewAngles.yaw = -180.0;
  this->minDriverViewAngles.roll = 0.0;
  this->maxDriverViewAngles.pitch = 180.0;
  this->maxDriverViewAngles.yaw = 180.0;
  this->maxDriverViewAngles.roll = 0.0;
  this->wildSpinTime = 0;
  this->viewAnglesDeltaPerc = 0.0;
  this->quickTurnLastPressed = 0;
  this->quickTurnTotalTime = 0;
  this->quickTurnLastSteerDir = 1;
  this->quickTurnStartTime = 0;
  this->quickTurnActive = false;
  this->quickTurnDir = 1;
  this->driverViewAngles = ang_zero;
  this->spikeDetachableFound = 0;
  this->spikeDetachableIndex.ptr[0] = -1;
  this->spikeDetachableIndex.ptr[1] = -1;
  this->spikeDetachableIndex.ptr[2] = -1;
  this->spikeDetachableIndex.ptr[3] = -1;
  this->attachedEventDecl[0] = nullptr;
  v4 = 0;
  this->attachedEventDecl[1] = nullptr;
  head = gameLocal->vehicleEntities.head;
  this->controlNode.prev->next = this->controlNode.next;
  this->controlNode.next->prev = this->controlNode.prev;
  this->controlNode.prev = &this->controlNode;
  this->controlNode.head = &this->controlNode;
  this->controlNode.next = head;
  this->controlNode.prev = head->prev;
  head->prev = &this->controlNode;
  this->controlNode.prev->next = &this->controlNode;
  this->controlNode.head = head->head;
  this->rolloverForce = 2.0;
  this->collisionImpulse = 0.0;
  this->controlNode.owner = this;
  this->collisionVerticalImpulse = 0.0;
  this->removeWhenDead = false;
  this->zoom_fov_x = 0.0;
  this->collisionDamage = nullptr;
  this->collisionDamageTime = 0;
  this->allowAmmoTransfer = true;
  this->allowQuickItemTransfer = true;
  this->lastAiDifficultyRating = -1;
  this->vehicleProps = nullptr;
  this->cleanUpVehicleProps = false;
  num = idDeclVehicleArmor::resourceList.declSources.num;
  if ( idDeclVehicleArmor::resourceList.declSources.num > 0 )
  {
    list = idDeclVehicleArmor::resourceList.declSources.list;
    v8 = 0;
    do
    {
      p_str = &list[v8]->name.str;
      if ( *p_str != nullptr )
      {
        idDeclInfo::FindWithInheritance(this: &idDeclVehicleArmor::resourceList, name: *p_str, makeDefault: false);
        num = idDeclVehicleArmor::resourceList.declSources.num;
        list = idDeclVehicleArmor::resourceList.declSources.list;
      }
      ++v4;
      ++v8;
    }
    while ( v4 < num );
  }
  this->vehicleClan = VCLAN_NONE;
  this->allowExit = true;
  this->vehicleDecalDamage = nullptr;
  this->vehicleWindowKit = nullptr;
  this->exitButtonDownOnEnter = false;
  v10 = (const idDeclRenderParm *)idDeclInfo::FindWithInheritance(
                                    this: &idDeclRenderParm::resourceList,
                                    name: "modelAngles",
                                    makeDefault: true);
  this->windowMovement = 0.0;
  this->rp_modelAngles = v10;
  this->windowMovementScale = 0.000099999997;
  return this;
}


// ========================================================================
// __unwind$533931
// EA  : 0x82D2F0E8
// RVA : 0x00D2F0E8
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void _unwind_533931()
{
  int v0; // r12

  idAnimatedEntity::~idAnimatedEntity(this: *(idAnimatedEntity **)(v0 - 192 + 212));
}


// ========================================================================
// __unwind$533932
// EA  : 0x82D2F110
// RVA : 0x00D2F110
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void _unwind_533932()
{
  int v0; // r12

  idList<detachable_t,5>::Clear(this: (idList<detachable_t,5> *)(*(_DWORD *)(v0 - 192 + 212) + 5204));
}


// ========================================================================
// __unwind$533933
// EA  : 0x82D2F13C
// RVA : 0x00D2F13C
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void _unwind_533933()
{
  int v0; // r12

  idStaticList<detachable_t,70>::~idStaticList<detachable_t,70>(this: (idStaticList<detachable_t,70> *)(*(_DWORD *)(v0 - 192 + 212) + 5220));
}


// ========================================================================
// __unwind$533934
// EA  : 0x82D2F168
// RVA : 0x00D2F168
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void _unwind_533934()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 192 + 212) + 13920));
}


// ========================================================================
// __unwind$533935
// EA  : 0x82D2F194
// RVA : 0x00D2F194
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void _unwind_533935()
{
  int v0; // r12

  idList<idVehicle::eventAnimEntry_t,5>::~idList<idVehicle::eventAnimEntry_t,5>(this: (idList<idVehicle::eventAnimEntry_t,5> *)(*(_DWORD *)(v0 - 192 + 212) + 13980));
}


// ========================================================================
// __unwind$533936
// EA  : 0x82D2F1C0
// RVA : 0x00D2F1C0
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void _unwind_533936()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 192 + 212) + 13996));
}


// ========================================================================
// __unwind$533937
// EA  : 0x82D2F1EC
// RVA : 0x00D2F1EC
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void _unwind_533937()
{
  int v0; // r12

  idList<idVehicle::seatInfo_t,5>::Clear(this: (idList<idVehicle::seatInfo_t,5> *)(*(_DWORD *)(v0 - 192 + 212) + 14416));
}


// ========================================================================
// __unwind$533938
// EA  : 0x82D2F218
// RVA : 0x00D2F218
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void _unwind_533938()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 192 + 212) + 14432));
}


// ========================================================================
// __unwind$533939
// EA  : 0x82D2F244
// RVA : 0x00D2F244
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void _unwind_533939()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 192 + 212) + 14496));
}


// ========================================================================
// __unwind$533940
// EA  : 0x82D2F270
// RVA : 0x00D2F270
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void _unwind_533940()
{
  int v0; // r12

  idVehicleKey::~idVehicleKey(this: (idVehicleKey *)(*(_DWORD *)(v0 - 192 + 212) + 14540));
}


// ========================================================================
// __unwind$533941
// EA  : 0x82D2F29C
// RVA : 0x00D2F29C
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void _unwind_533941()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 192 + 212) + 15604));
}


// ========================================================================
// __unwind$533942
// EA  : 0x82D2F2C8
// RVA : 0x00D2F2C8
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void _unwind_533942()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 192 + 212) + 15624));
}


// ========================================================================
// __unwind$533943
// EA  : 0x82D2F2F4
// RVA : 0x00D2F2F4
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void _unwind_533943()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 192 + 212) + 15664));
}


// ========================================================================
// __unwind$533944
// EA  : 0x82D2F320
// RVA : 0x00D2F320
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void _unwind_533944()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 192 + 212) + 15684));
}


// ========================================================================
// __unwind$533945
// EA  : 0x82D2F34C
// RVA : 0x00D2F34C
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void _unwind_533945()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 192 + 212) + 16004));
}


// ========================================================================
// __unwind$533946
// EA  : 0x82D2F378
// RVA : 0x00D2F378
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void _unwind_533946()
{
  int v0; // r12

  idLinkList<idWaypoint>::~idLinkList<idWaypoint>(this: (idLinkList<idProp_VehiclePickup> *)(*(_DWORD *)(v0 - 192 + 212)
                                                                                           + 16040));
}


// ========================================================================
// __unwind$533947
// EA  : 0x82D2F3A4
// RVA : 0x00D2F3A4
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void _unwind_533947()
{
  int v0; // r12

  idList<idVehicleWindow::window_t,5>::Clear(this: (idVehicleWindow *)(*(_DWORD *)(v0 - 192 + 212) + 16092));
}


// ========================================================================
// __unwind$533948
// EA  : 0x82D2F3D0
// RVA : 0x00D2F3D0
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void _unwind_533948()
{
  int v0; // r12

  idAnimator_VehicleCar::~idAnimator_VehicleCar(this: (idAnimator_VehicleCar *)(*(_DWORD *)(v0 - 192 + 212) + 16120));
}


// ========================================================================
// __unwind$533949
// EA  : 0x82D2F3FC
// RVA : 0x00D2F3FC
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void _unwind_533949()
{
  int v0; // r12

  idAnimator_Channel::~idAnimator_Channel(this: (idAnimator_Channel *)(*(_DWORD *)(v0 - 192 + 212) + 16276));
}


// ========================================================================
// __unwind$533950
// EA  : 0x82D2F428
// RVA : 0x00D2F428
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void _unwind_533950()
{
  int v0; // r12

  idAnimator_Channel::~idAnimator_Channel(this: (idAnimator_Channel *)(*(_DWORD *)(v0 - 192 + 212) + 16372));
}


// ========================================================================
// __unwind$533951
// EA  : 0x82D2F454
// RVA : 0x00D2F454
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void _unwind_533951()
{
  int v0; // r12

  idAnimator_Channel::~idAnimator_Channel(this: (idAnimator_Channel *)(*(_DWORD *)(v0 - 192 + 212) + 16468));
}


// ========================================================================
// __unwind$533952
// EA  : 0x82D2F480
// RVA : 0x00D2F480
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void _unwind_533952()
{
  int v0; // r12

  idFormationCoverMgr::~idFormationCoverMgr(this: (idVehicleCoverMgr *)(*(_DWORD *)(v0 - 192 + 212) + 16564));
}


// ========================================================================
// __unwind$533953
// EA  : 0x82D2F4AC
// RVA : 0x00D2F4AC
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void _unwind_533953()
{
  int v0; // r12

  idVehicle::eventAnimSupport_t::~eventAnimSupport_t(this: (idVehicle::eventAnimSupport_t *)(*(_DWORD *)(v0 - 192 + 212)
                                                                                           + 16588));
}


// ========================================================================
// ?Spawn@idVehicle@@QAAXXZ
// EA  : 0x82D2F540
// RVA : 0x00D2F540
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __fastcall idVehicle::Spawn(idVehicle *this)
{
  idPhysics *AFPhysics; // r3
  int v3; // r5
  idPhysics *Physics; // r29
  idPhysics *v5; // r28
  idPhysics *v6; // r3
  idPhysics_vtbl *v7; // r29
  int (__fastcall *GetContents)(idPhysics *, int); // ctr
  int v9; // r3
  idPhysics_AF *v10; // r3
  int num; // r5
  int v12; // r29
  int v13; // r28
  idPresentable *presentable; // r3
  const idDeclWeapon **list; // r27
  idPresentableVehicle *v16; // r3
  int v17; // r25
  int i; // r26
  idPresentable *v19; // r3
  int v20; // r3
  idPresentable *v21; // r3
  int v22; // r3
  int v23; // r27
  int j; // r28
  idPresentable *v25; // r3
  int v26; // r3
  idPresentable *v27; // r3
  int v28; // r3
  int v29; // r11
  idPresentable *v30; // r3
  idVehicleWeapon *v31; // r29
  int v32; // r3
  int v33; // r11
  idVehicleWeapon *v34; // r3
  idVehicleWeapon *v35; // r29
  idDeclVehicleWeapon **p_remoteFireWeapon; // r24
  idPresentable *v37; // r3
  int v38; // r3
  int v39; // r11
  idPresentable *v40; // r3
  int v41; // r29
  int v42; // r3
  int v43; // r26
  int v44; // r27
  idInventoryAttachmentDef *v45; // r29
  const idDeclJob *inventoryDecl; // r28
  idJobManager *v47; // r3
  idInventoryItem *JobByDecl; // r3
  idPresentable *v49; // r3
  int v50; // r3
  int v51; // r10
  int v52; // r11
  idVehicle::seatInfo_t *v53; // r9
  int v54; // r28
  idPresentable *v55; // r3
  int v56; // r3
  int v57; // r29
  int v58; // r11
  int v59; // r25
  int v60; // r26
  detachable_t *v61; // r29
  idDeclInfoTemplate<idDeclVehicleArmorKit> *parent; // r3
  char v63; // r11
  const idDeclInventory *decl; // r28
  int v65; // r27
  int v66; // r29
  int v67; // r10
  const idDeclInventory *v68; // r7
  int v69; // r11
  int v70; // r26
  int v71; // r29
  const idDeclInventory *v72; // r28
  idJobManager *v73; // r3
  idJob *v74; // r3
  idPresentable *v75; // r11
  const detachable_t *v76; // r28
  bool v77; // r27
  idPresentableVehicle *v78; // r3
  idGameLocal *v79; // r3
  int v80; // r3
  const idDeclEntityDef *passengerOccupantDef; // r4
  int v82; // r3
  vehicleSeat_t v83; // r29
  int v84; // r28
  idPresentable *v85; // r3
  char *data; // r29
  idPresentable *v87; // r3
  idPresentableAnimatedEntity *v88; // r3
  idTreeAnimator *TreeAnimator; // r3
  const idDeclMD6 *v90; // r11
  idPropsCollection *p_props; // r3
  int valueInteger; // r11
  idFile *v93; // r23
  bool v94; // cr58
  idFile *v95; // r3
  idInventoryCollection *v96; // r25
  int k; // r27
  idInventoryItem *InventoryItem; // r3
  const idDeclInventory *v99; // r11
  _DWORD *v100; // r29
  int v101; // r7
  bool v102; // cr57
  const char *str; // r28
  int v104; // r3
  const char *v105; // r28
  int v106; // r3
  idFile_vtbl *v107; // r28
  int v108; // r19
  int v109; // r3
  int v110; // r27
  int m; // r28
  idPresentable *v112; // r3
  int v113; // r3
  idPresentable *v114; // r3
  int v115; // r3
  const idDeclVehicleWeapon *DeclVehicleWeapon; // r3
  const idDeclAmmo *initialAmmoDecl; // r11
  const idDeclVehicleWeapon *v118; // r29
  const idDeclProjectile *projectileDecl; // r11
  const idDeclDamage *damageDecl; // r11
  const idDeclDamage *splashDamageDecl; // r11
  int v122; // r11
  const char *v123; // r3
  const idDeclVehicleWindowKit *vehicleWindowKit; // r11
  int v125; // r4
  int v126; // r27
  int v127; // r29
  idClipModel *v128; // r3
  idClipModel *v129; // r3
  idDeclVehicleWindowKit::windowDef_t *v130; // r11
  idDeclVehicleWindowKit::windowDef_t *v131; // r11
  const idDeclVehicleWindowKit *v132; // r11
  int v133; // [sp+50h] [-150h]
  idVehicleWindow::window_t v134; // [sp+60h] [-140h] BYREF
  detachable_t v135; // [sp+B0h] [-F0h] BYREF

  this->UpdateModelTransform(this);
  if ( (unsigned __int8)idVehicle::InitVehiclePhysics(this) != 0 )
  {
    if ( this->armorPropDef == nullptr )
      idLib::Error(fmt: "armorPropDef == NULL in %s", this->name.data);
    AFPhysics = (idPhysics *)idVehicle::GetAFPhysics(this);
    idEntity::SetPhysics(this, phys: AFPhysics, a3: v3);
    Physics = idEntity::GetPhysics(this);
    v5 = idEntity::GetPhysics(this);
    v6 = Physics;
    GetContents = Physics->GetContents;
    v7 = v5->__vftable;
    v9 = GetContents(this: v6, a2: -1);
    v7->SetContents(this: v5, a2: v9 | 0x20000, a3: -1);
    v10 = (idPhysics_AF *)idVehicle::GetAFPhysics(this);
    idPhysics_AF::SetSuspendTime(this: v10, minTime: 1.0, maxTime: -1.0);
    num = this->startingWeapons.num;
    v12 = 0;
    *(_BYTE *)&this->flags |= 2u;
    if ( num > 0 )
    {
      v13 = 0;
      do
      {
        presentable = this->presentable;
        list = this->startingWeapons.list;
        if ( presentable != nullptr )
          v16 = presentable->GetVehicleInterface(this: presentable);
        else
          v16 = nullptr;
        idPresentableVehicle::AddWeaponToVehicle(this: v16, decl: (const idDeclVehicleWeapon *)list[v13]);
        ++v12;
        ++v13;
      }
      while ( v12 < this->startingWeapons.num );
    }
    v17 = 0;
    for ( i = 0; ; i += 4 )
    {
      v19 = this->presentable;
      v20 = v19 != nullptr ? (int)v19->GetVehicleInterface(this: v19) : 0;
      if ( v17 >= *(_DWORD *)(v20 + 18748) )
        break;
      v21 = this->presentable;
      if ( v21 != nullptr )
        v22 = (int)v21->GetVehicleInterface(this: v21);
      else
        v22 = 0;
      if ( idVehicleWeapon::GetDeclVehicleWeapon(this: *(idVehicleWeapon **)(*(_DWORD *)(v22 + 18744) + i))->remoteFireWeapon != nullptr )
      {
        v23 = v17 + 1;
        for ( j = i + 4; ; j += 4 )
        {
          v25 = this->presentable;
          v26 = v25 != nullptr ? (int)v25->GetVehicleInterface(this: v25) : 0;
          if ( v23 >= *(_DWORD *)(v26 + 18748) )
            break;
          v27 = this->presentable;
          if ( v27 != nullptr )
            v28 = (int)v27->GetVehicleInterface(this: v27);
          else
            v28 = 0;
          v29 = *(_DWORD *)(v28 + 18744);
          v30 = this->presentable;
          v31 = *(idVehicleWeapon **)(v29 + i);
          if ( v30 != nullptr )
            v32 = (int)v30->GetVehicleInterface(this: v30);
          else
            v32 = 0;
          v33 = *(_DWORD *)(v32 + 18744);
          v34 = v31;
          v35 = *(idVehicleWeapon **)(v33 + j);
          p_remoteFireWeapon = &idVehicleWeapon::GetDeclVehicleWeapon(this: v34)->remoteFireWeapon;
          if ( *p_remoteFireWeapon == idVehicleWeapon::GetDeclVehicleWeapon(this: v35) )
          {
            v37 = this->presentable;
            if ( v37 != nullptr )
              v38 = (int)v37->GetVehicleInterface(this: v37);
            else
              v38 = 0;
            v39 = *(_DWORD *)(v38 + 18744);
            v40 = this->presentable;
            v41 = *(_DWORD *)(v39 + 4 * v23);
            if ( v40 != nullptr )
              v42 = (int)v40->GetVehicleInterface(this: v40);
            else
              v42 = 0;
            *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v42 + 18744) + i) + 424) = v41;
            break;
          }
          ++v23;
        }
      }
      ++v17;
    }
    v43 = 0;
    if ( this->startingInventory.num > 0 )
    {
      v44 = 0;
      do
      {
        v45 = &this->startingInventory.list[v44];
        inventoryDecl = (const idDeclJob *)v45->inventoryDecl;
        if ( inventoryDecl != nullptr )
        {
          v47 = (idJobManager *)this->GetInventory_2(this);
          JobByDecl = (idInventoryItem *)idJobManager::FindJobByDecl(this: v47, jobDecl: inventoryDecl);
          if ( JobByDecl != nullptr
            || (JobByDecl = idVehicle::GiveItem(
                              this,
                              decl: (const idDeclVehicleWeapon *)v45->inventoryDecl,
                              count: v45->count,
                              forceCount: false)) != nullptr )
          {
            JobByDecl->forSale = v45->forSale;
            JobByDecl->lootable = v45->lootable;
          }
        }
        ++v43;
        ++v44;
      }
      while ( v43 < this->startingInventory.num );
    }
    v49 = this->presentable;
    if ( v49 != nullptr )
      v50 = (int)v49->GetVehicleInterface(this: v49);
    else
      v50 = 0;
    if ( *(int *)(v50 + 18748) > 0 )
      idVehicle::SetDefaultWeaponGroup(this);
    idVehicle::RecalcMaxArmoredHealth(this);
    idVehicle::AttachAIEvents(this);
    v51 = 0;
    if ( this->seatInfo.num > 0 )
    {
      v52 = 0;
      do
      {
        ++v51;
        v53 = &this->seatInfo.list[v52++];
        v53->vehicleOccupant.spawnId.value = 0x1FFF;
      }
      while ( v51 < this->seatInfo.num );
    }
    v54 = this->seatInfo.num;
    if ( v54 < 2 )
      v54 = 2;
    v55 = this->presentable;
    if ( v55 != nullptr )
      v56 = (int)v55->GetVehicleInterface(this: v55);
    else
      v56 = 0;
    v57 = v56 + 16472;
    if ( v54 <= *(_DWORD *)(v56 + 16480)
      || (unsigned __int8)idList<vehicleOccupant_t,5>::Resize(
                            this: (idList<vehicleOccupant_t,5> *)(v56 + 16472),
                            newsize: v54) != 0 )
    {
      v58 = *(_DWORD *)(v57 + 8);
      if ( v54 < v58 )
        v58 = v54;
      *(_DWORD *)(v57 + 4) = v58;
    }
    v59 = 0;
    if ( this->detachableItemsBaseList.num > 0 )
    {
      v60 = 0;
      do
      {
        v61 = &this->detachableItemsBaseList.list[v60];
        parent = (idDeclInfoTemplate<idDeclVehicleArmorKit> *)v61->decl->GetDeclInfo(this: v61->decl);
        if ( parent != nullptr )
        {
          while ( parent != &idDeclVehicleArmorKit::resourceList )
          {
            parent = (idDeclInfoTemplate<idDeclVehicleArmorKit> *)parent->parent;
            if ( parent == nullptr )
              goto LABEL_70;
          }
          v63 = 1;
        }
        else
        {
LABEL_70:
          v63 = 0;
        }
        if ( v63 != 0 )
        {
          decl = v61->decl;
          v65 = 0;
          if ( v61->decl[1].trackedMemory > 0 )
          {
            v66 = 0;
            do
            {
              detachable_t::detachable_t(this: &v135);
              v67 = 0;
              v68 = *(const idDeclInventory **)((char *)&decl[1].dtr_idResource + v66);
              v133 = this->detachableItems.num;
              v135.decl = v68;
              if ( v133 > 0 )
              {
                v69 = 0;
                do
                {
                  if ( v68 == this->detachableItems.list[v69].decl )
                    break;
                  ++v67;
                  ++v69;
                }
                while ( v67 < this->detachableItems.num );
              }
              if ( v67 >= v133 )
                idVehicle::InitDetachableItem(this, detachable: &v135);
              idStr::FreeData(this: &v135.tagName);
              ++v65;
              v66 += 4;
            }
            while ( v65 < decl[1].trackedMemory );
          }
        }
        else
        {
          idVehicle::InitDetachableItem(this, detachable: v61);
        }
        ++v59;
        ++v60;
      }
      while ( v59 < this->detachableItemsBaseList.num );
    }
    v70 = 0;
    if ( this->detachableItems.num > 0 )
    {
      v71 = 0;
      do
      {
        v72 = this->detachableItems.list[v71].decl;
        v73 = (idJobManager *)this->GetInventory_2(this);
        v74 = idJobManager::FindJobByDecl(this: v73, jobDecl: (const idDeclJob *)v72);
        v75 = this->presentable;
        v76 = &this->detachableItems.list[v71];
        v77 = (_cntlzw((unsigned int)v74) & 0x20) != 0;
        if ( v75 != nullptr )
          v78 = v75->GetVehicleInterface(this: this->presentable);
        else
          v78 = nullptr;
        idPresentableVehicle::AddDetachableItem(this: v78, item: v76, permDetach: v77);
        ++v70;
        ++v71;
      }
      while ( v70 < this->detachableItems.num );
    }
    v79 = gameLocal;
    if ( gameLocal->gamestate != GAMESTATE_ACTIVE )
    {
      if ( this->occupantDef != nullptr )
      {
        v80 = ((int (*)(void))gameLocal->SpawnEntityFromDef)();
        if ( v80 != 0 )
          (*(void (__fastcall **)(int, int))(*(_DWORD *)v80 + 4))(a1: v80, a2: 1);
        v79 = gameLocal;
      }
      passengerOccupantDef = this->passengerOccupantDef;
      if ( passengerOccupantDef != nullptr )
      {
        v82 = (int)v79->SpawnEntityFromDef(this: v79, a2: passengerOccupantDef, a3: -1, a4: -1, a5: -1);
        if ( v82 != 0 )
          (*(void (__fastcall **)(int, int))(*(_DWORD *)v82 + 4))(a1: v82, a2: 1);
      }
    }
    v83 = SEAT_DRIVER;
    if ( this->seatInfo.num > 0 )
    {
      v84 = 0;
      do
      {
        if ( this->seatInfo.list[v84].isFake )
          this->EnterVehicle(this, a2: this, a3: v83);
        ++v83;
        ++v84;
      }
      while ( v83 < this->seatInfo.num );
    }
    if ( this->forceEntryTagName.len != 0 )
    {
      v85 = this->presentable;
      data = this->forceEntryTagName.data;
      if ( v85 != nullptr && v85->GetAnimatedEntityInterface(this: v85) != nullptr )
      {
        v87 = this->presentable;
        if ( v87 != nullptr )
        {
          v88 = v87->GetAnimatedEntityInterface(this: v87);
          TreeAnimator = idPresentableAnimatedEntity::GetTreeAnimator(this: v88);
        }
        else
        {
          TreeAnimator = idPresentableAnimatedEntity::GetTreeAnimator(this: nullptr);
        }
      }
      else
      {
        TreeAnimator = nullptr;
      }
      v90 = TreeAnimator->decl;
      p_props = &v90->props;
      if ( v90 == nullptr )
        p_props = nullptr;
      this->forceEntryTagData = *idPropsCollection::GetTag(this: p_props, propName: "_info", tagName: data);
    }
    valueInteger = vehicle_showHealthStatsOnSpawn.valueInteger;
    if ( vehicle_showHealthStatsOnSpawn.valueInteger != 0 )
    {
      v93 = nullptr;
      v94 = vehicle_showHealthStatsOnSpawn.valueInteger == 1;
      if ( vehicle_showHealthStatsOnSpawn.valueInteger > 1 )
      {
        v95 = fileSystem->OpenFileAppend(this: fileSystem, a2: "vehicle_health.txt", a3: 2);
        valueInteger = vehicle_showHealthStatsOnSpawn.valueInteger;
        v93 = v95;
        v94 = vehicle_showHealthStatsOnSpawn.valueInteger == 1;
      }
      if ( v94 )
      {
        idLib::Printf(fmt: "Name: %s\n", this->name.data);
        idLib::Printf(fmt: "base health: %f\n", this->health);
        valueInteger = vehicle_showHealthStatsOnSpawn.valueInteger;
      }
      if ( valueInteger == 2 )
      {
        idLib::Printf(fmt: "%s,%f\n", this->name.data, this->maxArmoredHealth);
        idLib::Printf(fmt: ",%f,,vehicle base\n", this->health);
        if ( v93 != nullptr )
        {
          v93->Printf(
            this: v93,
            a2: "%s,%f\n",
            this->name.data,
            (unsigned int)COERCE_UNSIGNED_INT64(this->maxArmoredHealth));
          v93->Printf(
            this: v93,
            a2: (const char *)(const char *)HIDWORD(COERCE_UNSIGNED_INT64(this->health)),
            COERCE_UNSIGNED_INT64(this->health));
        }
      }
      else if ( valueInteger == 3 )
      {
        idLib::Printf(
          fmt: (const char *)(const char *)HIDWORD(COERCE_UNSIGNED_INT64(this->health)),
          (unsigned int)COERCE_UNSIGNED_INT64(this->health));
        if ( v93 != nullptr )
          v93->Printf(this: v93, a2: ",%f,,vehicle base\n", (unsigned int)COERCE_UNSIGNED_INT64(this->health));
      }
      v96 = this->GetInventory_2(this);
      for ( k = 0; k < (int)idScriptObject::GetTypeDef(this: (bfx::Planner3D *)v96); ++k )
      {
        InventoryItem = idInventoryCollection::GetInventoryItem(this: v96, index: k);
        v99 = InventoryItem->decl;
        v100 = &InventoryItem->__vftable;
        v101 = !v99->vehicleArmor - 1;
        if ( (v101 & (unsigned int)v99) != 0 && *(_BYTE *)((v101 & (unsigned int)v99) + 0x116) == 0 )
        {
          v102 = vehicle_showHealthStatsOnSpawn.valueInteger > 1;
          if ( vehicle_showHealthStatsOnSpawn.valueInteger == 1 )
          {
            str = v99->name.str;
            v104 = InventoryItem->GetCount(this: InventoryItem);
            idLib::Printf(fmt: "item health: %d - %s\n", v104, str);
            v102 = vehicle_showHealthStatsOnSpawn.valueInteger > 1;
          }
          if ( v102 )
          {
            v105 = *(const char **)(v100[3] + 8);
            v106 = (*(int (__fastcall **)(_DWORD *))(*v100 + 52))(a1: v100);
            idLib::Printf(fmt: ",%d,,%s\n", v106, v105);
            if ( v93 != nullptr )
            {
              v107 = v93->__vftable;
              v108 = *(_DWORD *)(v100[3] + 8);
              v109 = (*(int (__fastcall **)(_DWORD *))(*v100 + 52))(a1: v100);
              v107->Printf(this: v93, a2: ",%d,,%s\n", v109, v108);
            }
          }
          (*(void (__fastcall **)(_DWORD *))(*v100 + 52))(a1: v100);
        }
      }
      if ( vehicle_showHealthStatsOnSpawn.valueInteger == 1 )
        idLib::Printf(fmt: "total health: %f\n", this->maxArmoredHealth);
      if ( vehicle_showHealthStatsOnSpawn.valueInteger == 3 )
      {
        idLib::Printf(
          fmt: "%s,%f\n",
          (const char *)(const char *)HIDWORD(COERCE_UNSIGNED_INT64(this->maxArmoredHealth)),
          this->maxArmoredHealth);
        if ( v93 != nullptr )
          v93->Printf(this: v93, a2: "%s,%f\n", this->maxArmoredHealth);
      }
      if ( vehicle_showHealthStatsOnSpawn.valueInteger == 1 )
      {
        idLib::Printf(fmt: "\n weapon ammo \n");
        v110 = 0;
        for ( m = 0; ; m += 4 )
        {
          v112 = this->presentable;
          v113 = v112 != nullptr ? (int)v112->GetVehicleInterface(this: v112) : 0;
          if ( v110 >= *(_DWORD *)(v113 + 18748) )
            break;
          v114 = this->presentable;
          if ( v114 != nullptr )
            v115 = (int)v114->GetVehicleInterface(this: v114);
          else
            v115 = 0;
          DeclVehicleWeapon = idVehicleWeapon::GetDeclVehicleWeapon(this: *(idVehicleWeapon **)(*(_DWORD *)(v115 + 18744)
                                                                                              + m));
          initialAmmoDecl = DeclVehicleWeapon->initialAmmoDecl;
          v118 = DeclVehicleWeapon;
          if ( initialAmmoDecl != nullptr )
          {
            projectileDecl = initialAmmoDecl->projectileDecl;
            if ( projectileDecl != nullptr )
            {
              damageDecl = projectileDecl->damageDecl;
              if ( damageDecl != nullptr )
                idLib::Printf(
                  fmt: "%s:  %f - %f\n",
                  (const char *)(const char *)HIDWORD(COERCE_UNSIGNED_INT64(damageDecl->minDamage)),
                  damageDecl->minDamage,
                  damageDecl->maxDamage);
              splashDamageDecl = v118->initialAmmoDecl->projectileDecl->splashDamageDecl;
              if ( splashDamageDecl != nullptr )
                idLib::Printf(
                  fmt: "%s:  %f - %f\n",
                  (const char *)(const char *)HIDWORD(COERCE_UNSIGNED_INT64(splashDamageDecl->minDamage)),
                  splashDamageDecl->minDamage,
                  splashDamageDecl->maxDamage);
            }
          }
          ++v110;
        }
      }
      idLib::Printf(fmt: "\n");
      v122 = vehicle_showHealthStatsOnSpawn.valueInteger;
      if ( vehicle_showHealthStatsOnSpawn.valueInteger > 1 )
      {
        if ( v93 != nullptr )
        {
          v93->Printf(this: v93, a2: "\n");
          v122 = vehicle_showHealthStatsOnSpawn.valueInteger;
        }
        if ( v122 > 1 && v93 != nullptr )
        {
          v123 = v93->GetFullPath(this: v93);
          idLib::Printf(fmt: "Done writing %s.\n", v123);
          ((void (__fastcall *)(idFile *, int))v93->dtr_idFile)(a1: v93, a2: 1);
        }
      }
    }
    vehicleWindowKit = this->vehicleWindowKit;
    if ( vehicleWindowKit != nullptr )
    {
      v125 = vehicleWindowKit->windows.num;
      if ( v125 > this->vehicleWindow.windows.size )
        idList<idVehicleWindow::window_t,5>::Resize(this: &this->vehicleWindow.windows, newsize: v125);
      v126 = 0;
      if ( this->vehicleWindowKit->windows.num > 0 )
      {
        v127 = 0;
        do
        {
          idVehicleWindow::window_t::window_t(this: &v134);
          if ( this->vehicleWindowKit->windows.list[v127].collisionModelName.len != 0 )
          {
            v128 = (idClipModel *)idMem::AllocWithLocation(
                                    this: &mem,
                                    location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                    size: 0xD8u,
                                    tag: TAG_CLIPMODEL,
                                    zeroBuffer: false,
                                    align: ALIGN_16,
                                    heap: HEAP_DEFAULTHEAP);
            v129 = v128 != nullptr
                 ? idClipModel::idClipModel(
                     this: v128,
                     clip: &clientGame->clip,
                     name: this->vehicleWindowKit->windows.list[v127].collisionModelName.data,
                     overrideClipMaterial: nullptr)
                 : nullptr;
            v134.collisionModel = v129;
            if ( v129 != nullptr )
              idClipModel::SetContents(this: v129, newContents: 129);
          }
          v130 = &this->vehicleWindowKit->windows.list[v127];
          if ( v130->normalModelName.len != 0 )
            v134.normalModel = clientGame->renderWorld->AllocRenderModel(
                                 this: clientGame->renderWorld,
                                 a2: v130->normalModelName.data,
                                 a3: 1,
                                 a4: -1);
          v131 = &this->vehicleWindowKit->windows.list[v127];
          if ( v131->brokenModelName.len != 0 )
            v134.brokenModel = clientGame->renderWorld->AllocRenderModel(
                                 this: clientGame->renderWorld,
                                 a2: v131->brokenModelName.data,
                                 a3: 1,
                                 a4: -1);
          idList<idVehicleWindow::window_t,5>::Append(this: &this->vehicleWindow.windows, obj: &v134);
          if ( v134.decals.listStatic == 0 || v134.decals.listStatic == 2 )
          {
            if ( v134.decals.list != nullptr )
              idMem::Free(this: &mem, ptr: v134.decals.list, align: ALIGN_16);
            v134.decals.list = nullptr;
            v134.decals.size = 0;
          }
          v132 = this->vehicleWindowKit;
          ++v126;
          ++v127;
          v134.decals.num = 0;
        }
        while ( v126 < v132->windows.num );
      }
    }
  }
}


// ========================================================================
// $LN616_0
// EA  : 0x82D303D4
// RVA : 0x00D303D4
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void _LN616_0()
{
  int v0; // r12

  idAnimatorParms_EndAdditiveChannels::~idAnimatorParms_EndAdditiveChannels(this: (vaiAction_t::vehicleCam_t *)(v0 - 416 + 176));
}


// ========================================================================
// __unwind$534986
// EA  : 0x82D303FC
// RVA : 0x00D303FC
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void _unwind_534986()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 416 + 96));
}


// ========================================================================
// __unwind$534987
// EA  : 0x82D30424
// RVA : 0x00D30424
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void _unwind_534987()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 416 + 80), tag: TAG_CLIPMODEL);
}


// ========================================================================
// `dynamic initializer for 'vc_minpitch''
// EA  : 0x8337B7E8
// RVA : 0x0137B7E8
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vc_minpitch__()
{
  idCVar::idCVar(
    this: &vc_minpitch,
    name: "vc_minpitch",
    value: "-45",
    flags: 4,
    description: "Minimum camera pitch",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vc_minpitch__);
}


// ========================================================================
// `dynamic initializer for 'vc_maxpitch''
// EA  : 0x8337B840
// RVA : 0x0137B840
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vc_maxpitch__()
{
  idCVar::idCVar(
    this: &vc_maxpitch,
    name: "vc_maxpitch",
    value: "70",
    flags: 4,
    description: "Maximum camera pitch",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vc_maxpitch__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_cam''
// EA  : 0x8337B898
// RVA : 0x0137B898
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_cam__()
{
  idCVar::idCVar(
    this: &vehicle_cam,
    name: "vehicle_cam",
    value: "0",
    flags: 1,
    description: "Enable vehicle camera.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_cam__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_follow''
// EA  : 0x8337B8F0
// RVA : 0x0137B8F0
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_follow__()
{
  idCVar::idCVar(
    this: &vehicle_follow,
    name: "vehicle_follow",
    value: "any",
    flags: 0,
    description: "Name of vehicle to follow.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_follow__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_cam_next''
// EA  : 0x8337B948
// RVA : 0x0137B948
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_cam_next__()
{
  idCVar::idCVar(
    this: &vehicle_cam_next,
    name: "vehicle_cam_next",
    value: "0",
    flags: 1,
    description: "Cycle to next vehicle to follow.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_cam_next__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_cam_prev''
// EA  : 0x8337B9A0
// RVA : 0x0137B9A0
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_cam_prev__()
{
  idCVar::idCVar(
    this: &vehicle_cam_prev,
    name: "vehicle_cam_prev",
    value: "0",
    flags: 1,
    description: "Cycle to prev vehicle to follow.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_cam_prev__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_cam_next_tag''
// EA  : 0x8337B9F8
// RVA : 0x0137B9F8
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_cam_next_tag__()
{
  idCVar::idCVar(
    this: &vehicle_cam_next_tag,
    name: "vehicle_cam_next_tag",
    value: "0",
    flags: 1,
    description: "Cycle to next vehicle camera tag.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_cam_next_tag__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_cam_prev_tag''
// EA  : 0x8337BA50
// RVA : 0x0137BA50
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_cam_prev_tag__()
{
  idCVar::idCVar(
    this: &vehicle_cam_prev_tag,
    name: "vehicle_cam_prev_tag",
    value: "0",
    flags: 1,
    description: "Cycle to prev vehicle camera tag.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_cam_prev_tag__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_cam_tag''
// EA  : 0x8337BAA8
// RVA : 0x0137BAA8
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_cam_tag__()
{
  idCVar::idCVar(
    this: &vehicle_cam_tag,
    name: "vehicle_cam_tag",
    value: "front_bumper",
    flags: 0,
    description: "Name of active camera tag.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_cam_tag__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_cam_yaw''
// EA  : 0x8337BB00
// RVA : 0x0137BB00
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_cam_yaw__()
{
  idCVar::idCVar(
    this: &vehicle_cam_yaw,
    name: "vehicle_cam_yaw",
    value: "0",
    flags: 4,
    description: "Yaw offset for vehicle camera.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_cam_yaw__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_cam_pitch''
// EA  : 0x8337BB58
// RVA : 0x0137BB58
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_cam_pitch__()
{
  idCVar::idCVar(
    this: &vehicle_cam_pitch,
    name: "vehicle_cam_pitch",
    value: "0",
    flags: 4,
    description: "Pitch offset for vehicle camera.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_cam_pitch__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_cam_fwd''
// EA  : 0x8337BBB0
// RVA : 0x0137BBB0
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_cam_fwd__()
{
  idCVar::idCVar(
    this: &vehicle_cam_fwd,
    name: "vehicle_cam_fwd",
    value: "0",
    flags: 4,
    description: "Forward offset for vehicle camera.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_cam_fwd__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_cam_rt''
// EA  : 0x8337BC08
// RVA : 0x0137BC08
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_cam_rt__()
{
  idCVar::idCVar(
    this: &vehicle_cam_rt,
    name: "vehicle_cam_rt",
    value: "0",
    flags: 4,
    description: "Right offset for vehicle camera.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_cam_rt__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_cam_up''
// EA  : 0x8337BC60
// RVA : 0x0137BC60
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_cam_up__()
{
  idCVar::idCVar(
    this: &vehicle_cam_up,
    name: "vehicle_cam_up",
    value: "0",
    flags: 4,
    description: "Up offset for vehicle camera.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_cam_up__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_cam_resetOfs''
// EA  : 0x8337BCB8
// RVA : 0x0137BCB8
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_cam_resetOfs__()
{
  idCVar::idCVar(
    this: &vehicle_cam_resetOfs,
    name: "vehicle_cam_resetOfs",
    value: "0",
    flags: 1,
    description: "Resets all cam offsets to 0",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_cam_resetOfs__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_cam_printOfs''
// EA  : 0x8337BD10
// RVA : 0x0137BD10
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_cam_printOfs__()
{
  idCVar::idCVar(
    this: &vehicle_cam_printOfs,
    name: "vehicle_cam_printOfs",
    value: "0",
    flags: 1,
    description: "Prints all tag name / offsets to console",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_cam_printOfs__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_gunner_model_test''
// EA  : 0x8337BD68
// RVA : 0x0137BD68
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_gunner_model_test__()
{
  idCVar::idCVar(
    this: &vehicle_gunner_model_test,
    name: "vehicle_gunner_model_test",
    value: "0",
    flags: 1,
    description: "Test gunner model",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_gunner_model_test__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_minWorldDamage''
// EA  : 0x8337BDC0
// RVA : 0x0137BDC0
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_minWorldDamage__()
{
  idCVar::idCVar(
    this: &vehicle_minWorldDamage,
    name: "vehicle_minWorldDamage",
    value: "50",
    flags: 4,
    description: "world damage less that this is ignored",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_minWorldDamage__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_removeOccupantModel''
// EA  : 0x8337BE18
// RVA : 0x0137BE18
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_removeOccupantModel__()
{
  idCVar::idCVar(
    this: &vehicle_removeOccupantModel,
    name: "vehicle_removeOccupantModel",
    value: "1",
    flags: 1,
    description: "Removes occupant model when exiting vehicle.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_removeOccupantModel__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_collapseJoint''
// EA  : 0x8337BE70
// RVA : 0x0137BE70
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_collapseJoint__()
{
  idCVar::idCVar(
    this: &vehicle_collapseJoint,
    name: "vehicle_collapseJoint",
    value: "0",
    flags: 0,
    description: "Collapse a joint by name (ignores single character names)",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_collapseJoint__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_playerCanEnter''
// EA  : 0x8337BEC8
// RVA : 0x0137BEC8
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_playerCanEnter__()
{
  idCVar::idCVar(
    this: &vehicle_playerCanEnter,
    name: "vehicle_playerCanEnter",
    value: "0",
    flags: 1,
    description: "When 1, player can enter any vehicle",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_playerCanEnter__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_playerTransferInv''
// EA  : 0x8337BF20
// RVA : 0x0137BF20
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_playerTransferInv__()
{
  idCVar::idCVar(
    this: &vehicle_playerTransferInv,
    name: "vehicle_playerTransferInv",
    value: "0",
    flags: 1,
    description: "Items are transferred between vehicle & player",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_playerTransferInv__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_tireUpgrades''
// EA  : 0x8337BF78
// RVA : 0x0137BF78
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_tireUpgrades__()
{
  idCVar::idCVar(
    this: &vehicle_tireUpgrades,
    name: "vehicle_tireUpgrades",
    value: "0",
    flags: 2,
    description: "(mod player vehicle) 0=no upgrade, 1=spikes, 2=upgraded, 3=upgraded/spikes; 4,5,6=mod all vehicles",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_tireUpgrades__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_showDamageDecals''
// EA  : 0x8337BFD0
// RVA : 0x0137BFD0
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_showDamageDecals__()
{
  idCVar::idCVar(
    this: &vehicle_showDamageDecals,
    name: "vehicle_showDamageDecals",
    value: "0",
    flags: 2,
    description: "Draw damage decal bounds",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_showDamageDecals__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_showHealthStatsOnSpawn''
// EA  : 0x8337C028
// RVA : 0x0137C028
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_showHealthStatsOnSpawn__()
{
  idCVar::idCVar(
    this: &vehicle_showHealthStatsOnSpawn,
    name: "vehicle_showHealthStatsOnSpawn",
    value: "0",
    flags: 2,
    description: "Show health stats / weapon damage when spawned. 1=Human friendly, 2=comma delimited (name @ start), 3=comma delimited (name @ end)",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_showHealthStatsOnSpawn__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_simpleDeath''
// EA  : 0x8337C080
// RVA : 0x0137C080
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_simpleDeath__()
{
  idCVar::idCVar(
    this: &vehicle_simpleDeath,
    name: "vehicle_simpleDeath",
    value: "0",
    flags: 1,
    description: "Use a simple death. No physics or explosions on death. No throwing of attachments.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_simpleDeath__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_armorHealthPercentage''
// EA  : 0x8337C0D8
// RVA : 0x0137C0D8
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_armorHealthPercentage__()
{
  idCVar::idCVar(
    this: &vehicle_armorHealthPercentage,
    name: "vehicle_armorHealthPercentage",
    value: "0.75",
    flags: 4,
    description: "percentage of multiplayer vehicle health that will go into armor pieces.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_armorHealthPercentage__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_forceEntryDist''
// EA  : 0x8337C130
// RVA : 0x0137C130
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_forceEntryDist__()
{
  idCVar::idCVar(
    this: &vehicle_forceEntryDist,
    name: "vehicle_forceEntryDist",
    value: "112",
    flags: 4,
    description: "Max dist from force entry tag",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_forceEntryDist__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_forceEntryAngle''
// EA  : 0x8337C188
// RVA : 0x0137C188
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_forceEntryAngle__()
{
  idCVar::idCVar(
    this: &vehicle_forceEntryAngle,
    name: "vehicle_forceEntryAngle",
    value: "80",
    flags: 4,
    description: "Max angle from force entry tag",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_forceEntryAngle__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_forceEntryDebug''
// EA  : 0x8337C1E0
// RVA : 0x0137C1E0
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_forceEntryDebug__()
{
  idCVar::idCVar(
    this: &vehicle_forceEntryDebug,
    name: "vehicle_forceEntryDebug",
    value: "0",
    flags: 1,
    description: "Show debug info",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_forceEntryDebug__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_exitSpotZofs''
// EA  : 0x8337C238
// RVA : 0x0137C238
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_exitSpotZofs__()
{
  idCVar::idCVar(
    this: &vehicle_exitSpotZofs,
    name: "vehicle_exitSpotZofs",
    value: "25.0",
    flags: 4,
    description: "Vertical offset added (per attempt) when trying to find a safe exit position.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_exitSpotZofs__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_damage_player''
// EA  : 0x8337C290
// RVA : 0x0137C290
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_damage_player__()
{
  idCVar::idCVar(
    this: &vehicle_damage_player,
    name: "vehicle_damage_player",
    value: "1",
    flags: 1,
    description: "If playe rcan be damaged inside vehicles or not",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_damage_player__);
}


// ========================================================================
// `dynamic initializer for 'projectile_InFlightControlGravityScale''
// EA  : 0x8337C2E8
// RVA : 0x0137C2E8
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__projectile_InFlightControlGravityScale__()
{
  idCVar::idCVar(
    this: &projectile_InFlightControlGravityScale,
    name: "projectile_InFlightControlGravityScale",
    value: "20.0",
    flags: 4,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__projectile_InFlightControlGravityScale__);
}


// ========================================================================
// `dynamic initializer for 'projectile_InFlightControlGravityScaleDelay''
// EA  : 0x8337C340
// RVA : 0x0137C340
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__projectile_InFlightControlGravityScaleDelay__()
{
  idCVar::idCVar(
    this: &projectile_InFlightControlGravityScaleDelay,
    name: "projectile_InFlightControlGravityScaleDelay",
    value: "6",
    flags: 2,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__projectile_InFlightControlGravityScaleDelay__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_effectPercentOfTopSpeed''
// EA  : 0x8337C398
// RVA : 0x0137C398
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_effectPercentOfTopSpeed__()
{
  idCVar::idCVar(
    this: &vehicle_effectPercentOfTopSpeed,
    name: "vehicle_effectPercentOfTopSpeed",
    value: "0.8",
    flags: 4,
    description: "percent of top speed before certain vehicle effects take place, addition FOV, etc.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_effectPercentOfTopSpeed__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_maxZoomFOV''
// EA  : 0x8337C3F0
// RVA : 0x0137C3F0
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_maxZoomFOV__()
{
  idCVar::idCVar(
    this: &vehicle_maxZoomFOV,
    name: "vehicle_maxZoomFOV",
    value: "40",
    flags: 4,
    description: "max zoom FOV",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_maxZoomFOV__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_boostMinRange''
// EA  : 0x8337C448
// RVA : 0x0137C448
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_boostMinRange__()
{
  idCVar::idCVar(
    this: &vehicle_boostMinRange,
    name: "vehicle_boostMinRange",
    value: "175",
    flags: 4,
    description: "Min camera range when boosting",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_boostMinRange__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_boostMaxRange''
// EA  : 0x8337C4A0
// RVA : 0x0137C4A0
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_boostMaxRange__()
{
  idCVar::idCVar(
    this: &vehicle_boostMaxRange,
    name: "vehicle_boostMaxRange",
    value: "400",
    flags: 4,
    description: "Max camera range when boosting",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_boostMaxRange__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_boostFOV''
// EA  : 0x8337C4F8
// RVA : 0x0137C4F8
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_boostFOV__()
{
  idCVar::idCVar(
    this: &vehicle_boostFOV,
    name: "vehicle_boostFOV",
    value: "125",
    flags: 4,
    description: "FOV ( max ) when boosting",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_boostFOV__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_boostFOVrampUp''
// EA  : 0x8337C550
// RVA : 0x0137C550
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_boostFOVrampUp__()
{
  idCVar::idCVar(
    this: &vehicle_boostFOVrampUp,
    name: "vehicle_boostFOVrampUp",
    value: ".03",
    flags: 4,
    description: "FOV ramp up from start",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_boostFOVrampUp__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_boostFOVrampDown''
// EA  : 0x8337C5A8
// RVA : 0x0137C5A8
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_boostFOVrampDown__()
{
  idCVar::idCVar(
    this: &vehicle_boostFOVrampDown,
    name: "vehicle_boostFOVrampDown",
    value: ".01",
    flags: 4,
    description: "FOV ramp down from end",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_boostFOVrampDown__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_boost_fov_delay''
// EA  : 0x8337C600
// RVA : 0x0137C600
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_boost_fov_delay__()
{
  idCVar::idCVar(
    this: &vehicle_boost_fov_delay,
    name: "vehicle_boost_fov_delay",
    value: "1000",
    flags: 2,
    description: "delay (ms) before fov effect starts",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_boost_fov_delay__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_seatTransitionTime''
// EA  : 0x8337C658
// RVA : 0x0137C658
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_seatTransitionTime__()
{
  idCVar::idCVar(
    this: &vehicle_seatTransitionTime,
    name: "vehicle_seatTransitionTime",
    value: "500",
    flags: 2,
    description: "transition from driver view to gunner view",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_seatTransitionTime__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_mannedWeaponTransitionTime''
// EA  : 0x8337C6B0
// RVA : 0x0137C6B0
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_mannedWeaponTransitionTime__()
{
  idCVar::idCVar(
    this: &vehicle_mannedWeaponTransitionTime,
    name: "vehicle_mannedWeaponTransitionTime",
    value: "500",
    flags: 2,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_mannedWeaponTransitionTime__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_view_range''
// EA  : 0x8337C708
// RVA : 0x0137C708
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_view_range__()
{
  idCVar::idCVar(
    this: &vehicle_view_range,
    name: "vehicle_view_range",
    value: "0",
    flags: 4,
    description: "Amount added to view range",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_view_range__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_view_height''
// EA  : 0x8337C760
// RVA : 0x0137C760
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_view_height__()
{
  idCVar::idCVar(
    this: &vehicle_view_height,
    name: "vehicle_view_height",
    value: "0",
    flags: 4,
    description: "Amount added to view height",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_view_height__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_view_lat''
// EA  : 0x8337C7B8
// RVA : 0x0137C7B8
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_view_lat__()
{
  idCVar::idCVar(
    this: &vehicle_view_lat,
    name: "vehicle_view_lat",
    value: "0",
    flags: 4,
    description: "Amount added to view translation",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_view_lat__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_view_pitch''
// EA  : 0x8337C810
// RVA : 0x0137C810
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_view_pitch__()
{
  idCVar::idCVar(
    this: &vehicle_view_pitch,
    name: "vehicle_view_pitch",
    value: "0",
    flags: 4,
    description: "Amount added to view pitch",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_view_pitch__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_view_yaw''
// EA  : 0x8337C868
// RVA : 0x0137C868
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_view_yaw__()
{
  idCVar::idCVar(
    this: &vehicle_view_yaw,
    name: "vehicle_view_yaw",
    value: "0",
    flags: 4,
    description: "Amount added to view yaw",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_view_yaw__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_stickControl''
// EA  : 0x8337C8C0
// RVA : 0x0137C8C0
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_stickControl__()
{
  idCVar::idCVar(
    this: &vehicle_stickControl,
    name: "vehicle_stickControl",
    value: "1",
    flags: 17,
    description: "Test vehicle driving with just the stick.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_stickControl__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_remoteStaticRange''
// EA  : 0x8337C918
// RVA : 0x0137C918
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_remoteStaticRange__()
{
  idCVar::idCVar(
    this: &vehicle_remoteStaticRange,
    name: "vehicle_remoteStaticRange",
    value: "0",
    flags: 4,
    description: "Distance at end of remoteRange that static interferes with control.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_remoteStaticRange__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_throwScale''
// EA  : 0x8337C970
// RVA : 0x0137C970
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_throwScale__()
{
  idCVar::idCVar(
    this: &vehicle_throwScale,
    name: "vehicle_throwScale",
    value: "0.33",
    flags: 4,
    description: "Velocity scale transferred to ragdoll thrown.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_throwScale__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_throwUpMin''
// EA  : 0x8337C9C8
// RVA : 0x0137C9C8
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_throwUpMin__()
{
  idCVar::idCVar(
    this: &vehicle_throwUpMin,
    name: "vehicle_throwUpMin",
    value: "700",
    flags: 4,
    description: "Min upwards velocity for ragdoll thrown.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_throwUpMin__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_throwVelocity''
// EA  : 0x8337CA20
// RVA : 0x0137CA20
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_throwVelocity__()
{
  idCVar::idCVar(
    this: &vehicle_throwVelocity,
    name: "vehicle_throwVelocity",
    value: "2300",
    flags: 4,
    description: "Velocity at which a collision will throw the player.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_throwVelocity__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_throwDelta''
// EA  : 0x8337CA78
// RVA : 0x0137CA78
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_throwDelta__()
{
  idCVar::idCVar(
    this: &vehicle_throwDelta,
    name: "vehicle_throwDelta",
    value: "500",
    flags: 4,
    description: "Change of velocity that will cause the player to be thrown.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_throwDelta__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_lerp_range''
// EA  : 0x8337CAD0
// RVA : 0x0137CAD0
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_lerp_range__()
{
  idCVar::idCVar(
    this: &vehicle_lerp_range,
    name: "vehicle_lerp_range",
    value: "1",
    flags: 1,
    description: "Adjust range by min / max defined in camera.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_lerp_range__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_transferPlayerAmmo''
// EA  : 0x8337CB28
// RVA : 0x0137CB28
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_transferPlayerAmmo__()
{
  idCVar::idCVar(
    this: &vehicle_transferPlayerAmmo,
    name: "vehicle_transferPlayerAmmo",
    value: "1",
    flags: 1,
    description: "Transfer player ammo to vehicle.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_transferPlayerAmmo__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_transferQuickItems''
// EA  : 0x8337CB80
// RVA : 0x0137CB80
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_transferQuickItems__()
{
  idCVar::idCVar(
    this: &vehicle_transferQuickItems,
    name: "vehicle_transferQuickItems",
    value: "1",
    flags: 1,
    description: "Transfer player quick items to vehicle.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_transferQuickItems__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_throwCameraTime''
// EA  : 0x8337CBD8
// RVA : 0x0137CBD8
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_throwCameraTime__()
{
  idCVar::idCVar(
    this: &vehicle_throwCameraTime,
    name: "vehicle_throwCameraTime",
    value: "5.0",
    flags: 4,
    description: "Length of time throw camera will play for",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_throwCameraTime__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_throwBodyForceScale''
// EA  : 0x8337CC30
// RVA : 0x0137CC30
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_throwBodyForceScale__()
{
  idCVar::idCVar(
    this: &vehicle_throwBodyForceScale,
    name: "vehicle_throwBodyForceScale",
    value: "0.15",
    flags: 4,
    description: "Length of time throw camera will play for",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_throwBodyForceScale__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_throwBodyMaxAngularVel''
// EA  : 0x8337CC88
// RVA : 0x0137CC88
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_throwBodyMaxAngularVel__()
{
  idCVar::idCVar(
    this: &vehicle_throwBodyMaxAngularVel,
    name: "vehicle_throwBodyMaxAngularVel",
    value: "30",
    flags: 4,
    description: "this * PI radians per second",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_throwBodyMaxAngularVel__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_show''
// EA  : 0x8337CCE0
// RVA : 0x0137CCE0
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_show__()
{
  idCVar::idCVar(
    this: &vehicle_show,
    name: "vehicle_show",
    value: "1",
    flags: 1,
    description: "show the vehicle",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_show__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_fpsDriver''
// EA  : 0x8337CD38
// RVA : 0x0137CD38
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_fpsDriver__()
{
  idCVar::idCVar(
    this: &vehicle_fpsDriver,
    name: "vehicle_fpsDriver",
    value: "1",
    flags: 1,
    description: "Driver view is FPS",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_fpsDriver__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_traceView''
// EA  : 0x8337CD90
// RVA : 0x0137CD90
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_traceView__()
{
  idCVar::idCVar(
    this: &vehicle_traceView,
    name: "vehicle_traceView",
    value: "1",
    flags: 1,
    description: "Trace for obstructions between vehicle and camera",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_traceView__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_showCameraTrace''
// EA  : 0x8337CDE8
// RVA : 0x0137CDE8
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_showCameraTrace__()
{
  idCVar::idCVar(
    this: &vehicle_showCameraTrace,
    name: "vehicle_showCameraTrace",
    value: "0",
    flags: 1,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_showCameraTrace__);
}


// ========================================================================
// `dynamic initializer for 'ai_vehicle_difficultyDamageScaleEasy''
// EA  : 0x8337CE40
// RVA : 0x0137CE40
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_vehicle_difficultyDamageScaleEasy__()
{
  idCVar::idCVar(
    this: &ai_vehicle_difficultyDamageScaleEasy,
    name: "ai_vehicle_difficultyDamageScaleEasy",
    value: "1.5",
    flags: 4,
    description: "how much to scale incoming damage on easy",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_vehicle_difficultyDamageScaleEasy__);
}


// ========================================================================
// `dynamic initializer for 'ai_vehicle_difficultyDamageScaleMedium''
// EA  : 0x8337CE98
// RVA : 0x0137CE98
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_vehicle_difficultyDamageScaleMedium__()
{
  idCVar::idCVar(
    this: &ai_vehicle_difficultyDamageScaleMedium,
    name: "ai_vehicle_difficultyDamageScaleMedium",
    value: "1.0",
    flags: 4,
    description: "how much to scale incoming damage on medium",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_vehicle_difficultyDamageScaleMedium__);
}


// ========================================================================
// `dynamic initializer for 'ai_vehicle_difficultyDamageScaleHard''
// EA  : 0x8337CEF0
// RVA : 0x0137CEF0
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_vehicle_difficultyDamageScaleHard__()
{
  idCVar::idCVar(
    this: &ai_vehicle_difficultyDamageScaleHard,
    name: "ai_vehicle_difficultyDamageScaleHard",
    value: "1.0",
    flags: 4,
    description: "how much to scale incoming damage on hard",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_vehicle_difficultyDamageScaleHard__);
}


// ========================================================================
// `dynamic initializer for 'ai_vehicle_difficultyDamageScaleNightmare''
// EA  : 0x8337CF48
// RVA : 0x0137CF48
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_vehicle_difficultyDamageScaleNightmare__()
{
  idCVar::idCVar(
    this: &ai_vehicle_difficultyDamageScaleNightmare,
    name: "ai_vehicle_difficultyDamageScaleNightmare",
    value: "1.0",
    flags: 4,
    description: "how much to scale incoming damage on nightmare",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_vehicle_difficultyDamageScaleNightmare__);
}


// ========================================================================
// `dynamic initializer for 'player_vehicle_difficultyDamageScaleEasy''
// EA  : 0x8337CFA0
// RVA : 0x0137CFA0
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__player_vehicle_difficultyDamageScaleEasy__()
{
  idCVar::idCVar(
    this: &player_vehicle_difficultyDamageScaleEasy,
    name: "player_vehicle_difficultyDamageScaleEasy",
    value: "0.5",
    flags: 4,
    description: "how much to scale incoming damage on easy",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__player_vehicle_difficultyDamageScaleEasy__);
}


// ========================================================================
// `dynamic initializer for 'player_vehicle_difficultyDamageScaleMedium''
// EA  : 0x8337CFF8
// RVA : 0x0137CFF8
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__player_vehicle_difficultyDamageScaleMedium__()
{
  idCVar::idCVar(
    this: &player_vehicle_difficultyDamageScaleMedium,
    name: "player_vehicle_difficultyDamageScaleMedium",
    value: "1.0",
    flags: 4,
    description: "how much to scale incoming damage on medium",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__player_vehicle_difficultyDamageScaleMedium__);
}


// ========================================================================
// `dynamic initializer for 'player_vehicle_difficultyDamageScaleHard''
// EA  : 0x8337D050
// RVA : 0x0137D050
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__player_vehicle_difficultyDamageScaleHard__()
{
  idCVar::idCVar(
    this: &player_vehicle_difficultyDamageScaleHard,
    name: "player_vehicle_difficultyDamageScaleHard",
    value: "1.25",
    flags: 4,
    description: "how much to scale incoming damage on hard",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__player_vehicle_difficultyDamageScaleHard__);
}


// ========================================================================
// `dynamic initializer for 'player_vehicle_difficultyDamageScaleNightmare''
// EA  : 0x8337D0A8
// RVA : 0x0137D0A8
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__player_vehicle_difficultyDamageScaleNightmare__()
{
  idCVar::idCVar(
    this: &player_vehicle_difficultyDamageScaleNightmare,
    name: "player_vehicle_difficultyDamageScaleNightmare",
    value: "1.5",
    flags: 4,
    description: "how much to scale incoming damage on nightmare",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__player_vehicle_difficultyDamageScaleNightmare__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_demoDamage''
// EA  : 0x8337D100
// RVA : 0x0137D100
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_demoDamage__()
{
  idCVar::idCVar(
    this: &vehicle_demoDamage,
    name: "vehicle_demoDamage",
    value: "1.4",
    flags: 4,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_demoDamage__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_angularDebrisKnob''
// EA  : 0x8337D158
// RVA : 0x0137D158
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_angularDebrisKnob__()
{
  idCVar::idCVar(
    this: &vehicle_angularDebrisKnob,
    name: "vehicle_angularDebrisKnob",
    value: "70",
    flags: 2,
    description: "turn this up or down to adjust angular vehicle debris velocity",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_angularDebrisKnob__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_linearDebrisKnob''
// EA  : 0x8337D1B0
// RVA : 0x0137D1B0
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_linearDebrisKnob__()
{
  idCVar::idCVar(
    this: &vehicle_linearDebrisKnob,
    name: "vehicle_linearDebrisKnob",
    value: "150",
    flags: 2,
    description: "turn this up or down to adjust linear vehicle debris velocity",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_linearDebrisKnob__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_throwAttached_disable''
// EA  : 0x8337D208
// RVA : 0x0137D208
// PDB : w:\tech5\tungsten\game\entities\vehicle.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_throwAttached_disable__()
{
  idCVar::idCVar(
    this: &vehicle_throwAttached_disable,
    name: "vehicle_throwAttached_disable",
    value: "0",
    flags: 1,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_throwAttached_disable__);
}

