
// ========================================================================
// ?GetAttacker@idProjectile@@QBAPAVidPresentable@@XZ
// EA  : 0x82AC1220
// RVA : 0x00AC1220
// PDB : w:\tech5\tungsten\game\weapons\projectile.h
// ========================================================================

idPresentable *__fastcall idProjectile::GetAttacker(idProjectile *this)
{
  idPresentable *presentable; // r3
  int v2; // r29
  int v3; // r11
  int v4; // r30
  idPresentable *result; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
    v2 = (int)presentable->GetProjectileInterface(this: presentable);
  else
    v2 = 0;
  v3 = *(_DWORD *)(v2 + 1260);
  v4 = v3 & 0x3FFF;
  if ( v3 == 0 )
    return nullptr;
  if ( !idClientGame::IsPresentableIndexValid(this: clientGame, index: v3 & 0x3FFF) )
    return nullptr;
  result = idClientGame::GetPresentableByIndex(this: clientGame, index: v4);
  if ( result->spawnId != *(_DWORD *)(v2 + 1260) )
    return nullptr;
  return result;
}


// ========================================================================
// ?GetAttackerEntity@idProjectile@@QBAPAVidEntity@@XZ
// EA  : 0x82AC2140
// RVA : 0x00AC2140
// PDB : w:\tech5\tungsten\game\weapons\projectile.h
// ========================================================================

idEntity *__fastcall idProjectile::GetAttackerEntity(idProjectile *this)
{
  idPresentable *presentable; // r3
  idPresentableProjectile *v2; // r3

  presentable = this->presentable;
  if ( presentable == nullptr )
    return idPresentableProjectile::GetAttackerEntity(this: nullptr);
  v2 = presentable->GetProjectileInterface(this: presentable);
  return idPresentableProjectile::GetAttackerEntity(this: v2);
}


// ========================================================================
// ?GetState@idProjectile@@QBA?AW4projectileState_t@@XZ
// EA  : 0x82ECEF70
// RVA : 0x00ECEF70
// PDB : w:\tech5\tungsten\game\weapons\projectile.h
// ========================================================================

projectileState_t __fastcall idProjectile::GetState(idProjectile *this)
{
  idPresentable *presentable; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
    return presentable->GetProjectileInterface(this: presentable)->state;
  else
    return MEMORY[0x4E4];
}


// ========================================================================
// ?GetLaunchTime@idProjectile@@IBAHXZ
// EA  : 0x82ECEFC8
// RVA : 0x00ECEFC8
// PDB : w:\tech5\tungsten\game\weapons\projectile.h
// ========================================================================

int __fastcall idProjectile::GetLaunchTime(idProjectile *this)
{
  idPresentable *presentable; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
    return presentable->GetProjectileInterface(this: presentable)->launchTime;
  else
    return MEMORY[0x558];
}


// ========================================================================
// ?SetLaunchTime@idProjectile@@IAAXH@Z
// EA  : 0x82ECF020
// RVA : 0x00ECF020
// PDB : w:\tech5\tungsten\game\weapons\projectile.h
// ========================================================================

void __fastcall idProjectile::SetLaunchTime(idProjectile *this, int time)
{
  idPresentable *presentable; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
    presentable->GetProjectileInterface(this: presentable)->launchTime = time;
  else
    MEMORY[0x558] = time;
}


// ========================================================================
// ?SetState@idProjectile@@IAAXW4projectileState_t@@@Z
// EA  : 0x82ECF088
// RVA : 0x00ECF088
// PDB : w:\tech5\tungsten\game\weapons\projectile.h
// ========================================================================

void __fastcall idProjectile::SetState(idProjectile *this, projectileState_t state)
{
  idPresentable *presentable; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
    presentable->GetProjectileInterface(this: presentable)->state = state;
  else
    MEMORY[0x4E4] = state;
}


// ========================================================================
// ?GetGoalSpeed@idProjectile_Rocket@@QBAMXZ
// EA  : 0x82ECF0F0
// RVA : 0x00ECF0F0
// PDB : w:\tech5\tungsten\game\weapons\projectile.h
// ========================================================================

float __fastcall idProjectile_Rocket::GetGoalSpeed(idProjectile_Rocket *this)
{
  idPresentable *presentable; // r3
  double goalSpeed; // fp1

  presentable = this->presentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    presentable = this->presentable;
  }
  goalSpeed = presentable->GetProjectileRocketInterface(this: presentable)->goalSpeed;
  return *((float *)&goalSpeed + 1);
}


// ========================================================================
// ?SetGoalSpeed@idProjectile_Rocket@@QAAXM@Z
// EA  : 0x82ECF148
// RVA : 0x00ECF148
// PDB : w:\tech5\tungsten\game\weapons\projectile.h
// ========================================================================

void __fastcall idProjectile_Rocket::SetGoalSpeed(idProjectile_Rocket *this, double value)
{
  idPresentable *presentable; // r3

  presentable = this->presentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    presentable = this->presentable;
  }
  presentable->GetProjectileRocketInterface(this: presentable)->goalSpeed = value;
}


// ========================================================================
// ?GetThrustDelay@idProjectile_Rocket@@QBAHXZ
// EA  : 0x82ECF1A8
// RVA : 0x00ECF1A8
// PDB : w:\tech5\tungsten\game\weapons\projectile.h
// ========================================================================

int __fastcall idProjectile_Rocket::GetThrustDelay(idProjectile_Rocket *this)
{
  idPresentable *presentable; // r3

  presentable = this->presentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    presentable = this->presentable;
  }
  return presentable->GetProjectileRocketInterface(this: presentable)->calcThrustDelay;
}


// ========================================================================
// ?GetHomingState@idProjectile_Homing@@QBA?AW4homingState_t@idPresentableProjectile_Homing@@XZ
// EA  : 0x82ECF200
// RVA : 0x00ECF200
// PDB : w:\tech5\tungsten\game\weapons\projectile.h
// ========================================================================

idPresentableProjectile_Homing::homingState_t __fastcall idProjectile_Homing::GetHomingState(idProjectile_Homing *this)
{
  idPresentable *presentable; // r3

  presentable = this->presentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    presentable = this->presentable;
  }
  return presentable->GetProjectileHomingInterface(this: presentable)->homingState;
}


// ========================================================================
// ?SetHomingState@idProjectile_Homing@@QAAXW4homingState_t@idPresentableProjectile_Homing@@@Z
// EA  : 0x82ECF258
// RVA : 0x00ECF258
// PDB : w:\tech5\tungsten\game\weapons\projectile.h
// ========================================================================

void __fastcall idProjectile_Homing::SetHomingState(
        idProjectile_Homing *this,
        idPresentableProjectile_Homing::homingState_t newState)
{
  idPresentable *presentable; // r3

  presentable = this->presentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    presentable = this->presentable;
  }
  presentable->GetProjectileHomingInterface(this: presentable)->homingState = newState;
}


// ========================================================================
// ?GetFXDecl@idProjectile@@UBAPBVidDeclFX@@XZ
// EA  : 0x82ECF498
// RVA : 0x00ECF498
// PDB : w:\tech5\tungsten\game\weapons\projectile.h
// ========================================================================

const idDeclFX *__fastcall idProjectile::GetFXDecl(idProjectile *this)
{
  const idDeclProjectile *projectileDecl; // r11

  projectileDecl = this->projectileDecl;
  if ( projectileDecl != nullptr )
    return projectileDecl->fxDecl;
  else
    return nullptr;
}


// ========================================================================
// ?SetTarget@idProjectile_Homing@@AAAXABVidProjectileTarget@@@Z
// EA  : 0x82ED28A0
// RVA : 0x00ED28A0
// PDB : w:\tech5\tungsten\game\weapons\projectile.h
// ========================================================================

void __fastcall idProjectile_Homing::SetTarget(idProjectile_Homing *this, const idProjectileTarget *target_)
{
  idPresentable *presentable; // r3
  int v5; // r3

  presentable = this->presentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    presentable = this->presentable;
  }
  v5 = (int)presentable->GetProjectileHomingInterface(this: presentable);
  *(_DWORD *)(v5 + 2044) = target_->type;
  *(float *)(v5 + 2048) = target_->pos.x;
  *(float *)(v5 + 2052) = target_->pos.y;
  *(float *)(v5 + 2056) = target_->pos.z;
  *(_DWORD *)(v5 + 2060) = target_->presentable.spawnId;
}


// ========================================================================
// ?IsActorStuckOn@idProjectile_Rocket@@QBA_NPAVidEntity@@@Z
// EA  : 0x82ED36B8
// RVA : 0x00ED36B8
// PDB : w:\tech5\tungsten\game\weapons\projectile.h
// ========================================================================

int __fastcall idProjectile_Rocket::IsActorStuckOn(idProjectile_Rocket *this, idEntity *ent)
{
  int value; // r10
  idEntity *v5; // r3
  int v6; // r9
  idEntity *v7; // r3
  idEntity *v8; // r3
  unsigned __int8 v9; // r11

  value = this->stuckOnActor.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] != value >> 13 )
    return 0;
  v5 = gameLocal->entities.ptr[value & 0x1FFF];
  if ( v5 == nullptr || idEntity::CastTo(c: v5) == nullptr )
    return 0;
  v6 = this->stuckOnActor.spawnId.value;
  if ( gameLocal->spawnIds.ptr[v6 & 0x1FFF] == v6 >> 13 && (v7 = gameLocal->entities.ptr[v6 & 0x1FFF]) != nullptr )
    v8 = idEntity::CastTo(c: v7);
  else
    v8 = nullptr;
  v9 = 1;
  if ( v8 != ent )
    return 0;
  return v9;
}


// ========================================================================
// ?GetInventoryItem@idProjectile_Arrow@@UBAPBVidDeclInventory@@XZ
// EA  : 0x82EDB9D0
// RVA : 0x00EDB9D0
// PDB : w:\tech5\tungsten\game\weapons\projectile.h
// ========================================================================

const idDeclInventory *__fastcall idProjectile_Arrow::GetInventoryItem(idProjectile_Arrow *this)
{
  return this->inventoryItem;
}


// ========================================================================
// ?GetElectricBoltEffect@idProjectile_Arrow@@UAAPAVidElectricBolt@@H@Z
// EA  : 0x82EDB9D8
// RVA : 0x00EDB9D8
// PDB : w:\tech5\tungsten\game\weapons\projectile.h
// ========================================================================

idElectricBolt *__fastcall idProjectile_Arrow::GetElectricBoltEffect(idProjectile_Arrow *this, int index)
{
  return this->electricShocks.list[index];
}

