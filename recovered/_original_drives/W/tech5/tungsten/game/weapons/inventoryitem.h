
// ========================================================================
// ?Think@idVehicleQuickItem@@UAAXXZ
// EA  : 0x82501040
// RVA : 0x00501040
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.h
// ========================================================================

// attributes: thunk
void __fastcall idVehicleQuickItem::Think(idVehicleQuickItem *this)
{
  idVehicle_Jump::VehicleDied((idHealthT<enum aiHealthComponent_t,2,0> *)this);
}


// ========================================================================
// ?GetLoadedAmmo@idWeapon@@QBAPBVidAmmoItem@@_N@Z
// EA  : 0x82A32EA0
// RVA : 0x00A32EA0
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.h
// ========================================================================

const idAmmoItem *__fastcall idWeapon::GetLoadedAmmo(idWeapon *this, bool secondaryAmmo)
{
  if ( secondaryAmmo )
    return this->ammoClipSecondary;
  else
    return this->ammoClip;
}


// ========================================================================
// ?GetPresentableWeapon@idWeapon@@QAAPAVidPresentableWeapon@@XZ
// EA  : 0x82AE5AD8
// RVA : 0x00AE5AD8
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.h
// ========================================================================

idPresentableWeapon *__fastcall idWeapon::GetPresentableWeapon(idWeapon *this)
{
  unsigned int spawnId; // r11
  int v3; // r30
  idPresentableWeapon *result; // r3

  spawnId = this->presentableWeapon.spawnId;
  v3 = spawnId & 0x3FFF;
  if ( spawnId == 0 )
    return nullptr;
  if ( !idClientGame::IsPresentableIndexValid(this: clientGame, index: spawnId & 0x3FFF) )
    return nullptr;
  result = (idPresentableWeapon *)idClientGame::GetPresentableByIndex(this: clientGame, index: v3);
  if ( result->spawnId != this->presentableWeapon.spawnId )
    return nullptr;
  return result;
}


// ========================================================================
// ?GetBurstMode@idWeapon@@QBA?AW4burstMode_t@@XZ
// EA  : 0x82B805C8
// RVA : 0x00B805C8
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.h
// ========================================================================

int __fastcall idWeapon::GetBurstMode(idWeapon *this)
{
  idAmmoItem *ammoClipSecondary; // r11
  idAmmoItem *ammoClip; // r11

  if ( this->weaponState == WEAPONSTATE_SECONDARY )
  {
    ammoClipSecondary = this->ammoClipSecondary;
    if ( ammoClipSecondary != nullptr )
      return ammoClipSecondary->burstMode;
  }
  else
  {
    ammoClip = this->ammoClip;
    if ( ammoClip != nullptr )
      return ammoClip->burstMode;
  }
  return this->decl[1].attachmentInfo.num;
}


// ========================================================================
// ?SetVehicleEntityName@idVehicleKey@@QAAXVidStr@@@Z
// EA  : 0x82C62238
// RVA : 0x00C62238
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.h
// ========================================================================

void __fastcall idVehicleKey::SetVehicleEntityName(idVehicleKey *this, idStr *vehName)
{
  int len; // r29

  len = vehName->len;
  idStr::EnsureAlloced(
    this: &this->referenceVehicleName,
    amount: vehName->len + 1,
    keepold: false,
    geometricGrowth: false);
  memcpy(Dst: this->referenceVehicleName.data, Src: vehName->data, Size: len);
  this->referenceVehicleName.data[len] = 0;
  this->referenceVehicleName.len = len;
  idStr::FreeData(this: vehName);
}


// ========================================================================
// __unwind$493815
// EA  : 0x82C6229C
// RVA : 0x00C6229C
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.h
// ========================================================================

void _unwind_493815()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v0 - 128 + 156));
}


// ========================================================================
// ?ShouldSwitchWeaponWhenOutOfAmmo@idWeapon@@UBA_NXZ
// EA  : 0x82EBFAC0
// RVA : 0x00EBFAC0
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.h
// ========================================================================

BOOL __fastcall idWeapon::ShouldSwitchWeaponWhenOutOfAmmo(_BYTE *ptr)
{
  return (ptr[453] & 0x10) != 0;
}


// ========================================================================
// ?GetCount@idWeapon@@UBAHXZ
// EA  : 0x82EBFAD0
// RVA : 0x00EBFAD0
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.h
// ========================================================================

int __fastcall idWeapon::GetCount(idWeapon *this)
{
  if ( (*((_BYTE *)this + 452) & 1) != 0 )
    return 2;
  else
    return this->count;
}


// ========================================================================
// ?Think@idVehicleQuickItem@@UAAXPAVidPresentable@@@Z
// EA  : 0x82EC2700
// RVA : 0x00EC2700
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.h
// ========================================================================

void __fastcall idVehicleQuickItem::Think(idVehicleQuickItem *this, idPresentable *presentable)
{
  ((void (__fastcall *)(idVehicleQuickItem *, idPresentable *))this->Think)(a1: this, a2: presentable);
}


// ========================================================================
// ?CrosshairShouldPulsate@idLaserCutter@@UBA_NXZ
// EA  : 0x82EC5A08
// RVA : 0x00EC5A08
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.h
// ========================================================================

BOOL __fastcall idLaserCutter::CrosshairShouldPulsate(idLaserCutter *this)
{
  return this->crosshairShouldPulsate;
}


// ========================================================================
// ?ForceIronsightSensAndMove@idLaserCutter@@UBA_NXZ
// EA  : 0x82EC5A10
// RVA : 0x00EC5A10
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.h
// ========================================================================

int __fastcall idLaserCutter::ForceIronsightSensAndMove(
        idLaserCutter *this,
        int a2,
        int a3,
        int a4,
        int a5,
        int a6,
        __int64 a7)
{
  char OkToFire; // r3
  unsigned __int8 v8; // r11

  if ( this->triggerState != TRIGGERSTATE_PULLED )
    return 0;
  if ( this->weaponState != WEAPONSTATE_SECONDARY )
    return 0;
  OkToFire = idLaserCutter::GetOkToFire(this, a2, a3, a4, a5, a6: a7);
  v8 = 1;
  if ( OkToFire == 0 )
    return 0;
  return v8;
}


// ========================================================================
// ?BlockCrosshair@idLaserCutter@@UBA_NH@Z
// EA  : 0x82EC5A60
// RVA : 0x00EC5A60
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.h
// ========================================================================

BOOL __fastcall idLaserCutter::BlockCrosshair(idLaserCutter *this, unsigned int gameMs)
{
  return idInterpolate<float>::GetCurrentValue(
           this: &this->laserBeamBounceIndicationFade,
           time: (float)((float)__SPAIR64__(&unk_82390000, gameMs) * (float)0.001)) > 0.0;
}

