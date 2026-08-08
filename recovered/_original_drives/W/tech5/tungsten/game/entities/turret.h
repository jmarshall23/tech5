
// ========================================================================
// ?IsUpright@idTurret@@ABA_NXZ
// EA  : 0x82CF5598
// RVA : 0x00CF5598
// PDB : w:\tech5\tungsten\game\entities\turret.h
// ========================================================================

int __fastcall idTurret::IsUpright(idTurret *this)
{
  idPhysics *Physics; // r3
  int v2; // r3
  unsigned __int8 v3; // r11

  if ( this->isStatic )
    return 1;
  Physics = idEntity::GetPhysics(this);
  v2 = (int)Physics->GetAxis(this: Physics, a2: 0);
  v3 = 0;
  if ( *(float *)(v2 + 32) >= 0.99000001 )
    return 1;
  return v3;
}


// ========================================================================
// ?GetAF@idTurret@@UBAPBVidAnimator_AF@@XZ
// EA  : 0x82CFF6B8
// RVA : 0x00CFF6B8
// PDB : w:\tech5\tungsten\game\entities\turret.h
// ========================================================================

const idAnimator_AF *__fastcall idTurret::GetAF(idTurret *this)
{
  return &this->afProperties;
}


// ========================================================================
// ?GetHealthComponent@idTurret@@UBAPBVidBaseHealth@@XZ
// EA  : 0x82CFF6C0
// RVA : 0x00CFF6C0
// PDB : w:\tech5\tungsten\game\entities\turret.h
// ========================================================================

const idSimpleHealth *__fastcall idTurret::GetHealthComponent(idTurret *this)
{
  return &this->turretHealth;
}


// ========================================================================
// ?GetInventory@idTurret@@UBAPBVidInventoryCollection@@XZ
// EA  : 0x82CFF6C8
// RVA : 0x00CFF6C8
// PDB : w:\tech5\tungsten\game\entities\turret.h
// ========================================================================

const idInventoryCollection *__fastcall idTurret::GetInventory(idTurret *this)
{
  return &this->inventoryCollection;
}


// ========================================================================
// ?IsTargetLockable@idTurret@@EBA_NPBVidAmmoItem@@@Z
// EA  : 0x82CFF6D0
// RVA : 0x00CFF6D0
// PDB : w:\tech5\tungsten\game\entities\turret.h
// ========================================================================

int __fastcall idTurret::IsTargetLockable(idTurret *this, const idAmmoItem *ammo)
{
  char v2; // r3
  unsigned __int8 v3; // r11

  if ( !this->targetable )
    return 0;
  v2 = ((int (__fastcall *)(idTurret *, const idAmmoItem *))this->IsDead)(a1: this, a2: ammo);
  v3 = 1;
  if ( v2 != 0 )
    return 0;
  return v3;
}

