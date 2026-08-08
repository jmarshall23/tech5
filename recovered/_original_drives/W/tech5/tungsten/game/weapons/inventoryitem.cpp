
// ========================================================================
// ??0idInventoryItem@@QAA@XZ
// EA  : 0x82EB9618
// RVA : 0x00EB9618
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

idInventoryItem *__fastcall idInventoryItem::idInventoryItem(idInventoryItem *this)
{
  idEventReceiver::idEventReceiver(this);
  this->decl = nullptr;
  this->count = 0;
  this->__vftable = (idInventoryItem_vtbl *)&idInventoryItem::`vftable';
  this->forSale = false;
  this->lootable = false;
  this->buyBackItem = false;
  this->alreadyDropped = false;
  this->quickSlot = -1;
  this->counttosave = -1;
  this->coolDownTime = 0;
  this->skinPreload = nullptr;
  return this;
}


// ========================================================================
// ??1idInventoryItem@@UAA@XZ
// EA  : 0x82EB9688
// RVA : 0x00EB9688
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __fastcall idInventoryItem::~idInventoryItem(idInventoryItem *this)
{
  this->__vftable = (idInventoryItem_vtbl *)&idInventoryItem::`vftable';
  idEventReceiver::~idEventReceiver(this);
}


// ========================================================================
// ?Init@idInventoryItem@@UAAXPBVidDeclInventory@@@Z
// EA  : 0x82EB9698
// RVA : 0x00EB9698
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __fastcall idInventoryItem::Init(idInventoryItem *this, const idDeclInventory *decl)
{
  this->decl = decl;
  this->count = decl->count;
  this->counttosave = -1;
  this->forSale = false;
  this->lootable = false;
}


// ========================================================================
// ?GetSellPrice@idInventoryItem@@QBAHXZ
// EA  : 0x82EB96C0
// RVA : 0x00EB96C0
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

int __fastcall idInventoryItem::GetSellPrice(idInventoryItem *this)
{
  return this->decl->sellPrice;
}


// ========================================================================
// ?PlayerCanSell@idInventoryItem@@QBA_NXZ
// EA  : 0x82EB96D0
// RVA : 0x00EB96D0
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

int __fastcall idInventoryItem::PlayerCanSell(idInventoryItem *this)
{
  const idDeclInventory *decl; // r11
  unsigned __int8 v2; // r11

  decl = this->decl;
  if ( !decl->playerCanSell )
    return 0;
  if ( decl->sellPrice <= 0 )
    return 0;
  v2 = 1;
  if ( this->decl->isContainer )
    return 0;
  return v2;
}


// ========================================================================
// ?GetCountToSave@idInventoryItem@@QBAHXZ
// EA  : 0x82EB9710
// RVA : 0x00EB9710
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

int __fastcall idInventoryItem::GetCountToSave(idInventoryItem *this)
{
  int result; // r3

  result = this->counttosave;
  if ( result <= -1 )
    return this->count;
  return result;
}


// ========================================================================
// ??0idAmmoItem@@QAA@XZ
// EA  : 0x82EB9728
// RVA : 0x00EB9728
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

idAmmoItem *__fastcall idAmmoItem::idAmmoItem(idAmmoItem *this)
{
  idEventReceiver::idEventReceiver(this: &this->idInventoryItem);
  this->decl = nullptr;
  this->count = 0;
  this->__vftable = (idAmmoItem_vtbl *)&idAmmoItem::`vftable';
  this->forSale = false;
  this->lootable = false;
  this->buyBackItem = false;
  this->alreadyDropped = false;
  this->quickSlot = -1;
  this->counttosave = -1;
  this->coolDownTime = 0;
  this->skinPreload = nullptr;
  this->burstMode = BURSTMODE_DEFAULT;
  return this;
}


// ========================================================================
// ??0idActorModifierItem@@QAA@XZ
// EA  : 0x82EB9798
// RVA : 0x00EB9798
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

idActorModifierItem *__fastcall idActorModifierItem::idActorModifierItem(idActorModifierItem *this)
{
  idEventReceiver::idEventReceiver(this);
  this->decl = nullptr;
  this->count = 0;
  this->__vftable = (idActorModifierItem_vtbl *)&idActorModifierItem::`vftable';
  this->forSale = false;
  this->lootable = false;
  this->buyBackItem = false;
  this->alreadyDropped = false;
  this->quickSlot = -1;
  this->counttosave = -1;
  this->coolDownTime = 0;
  this->skinPreload = nullptr;
  return this;
}


// ========================================================================
// ??0idHealthItem@@QAA@XZ
// EA  : 0x82EB9808
// RVA : 0x00EB9808
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

idHealthItem *__fastcall idHealthItem::idHealthItem(idHealthItem *this)
{
  idEventReceiver::idEventReceiver(this);
  this->decl = nullptr;
  this->count = 0;
  this->__vftable = (idHealthItem_vtbl *)&idHealthItem::`vftable';
  this->forSale = false;
  this->lootable = false;
  this->buyBackItem = false;
  this->alreadyDropped = false;
  this->quickSlot = -1;
  this->counttosave = -1;
  this->coolDownTime = 0;
  this->skinPreload = nullptr;
  return this;
}


// ========================================================================
// ??0idDamageBoostItem@@QAA@XZ
// EA  : 0x82EB9878
// RVA : 0x00EB9878
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

idDamageBoostItem *__fastcall idDamageBoostItem::idDamageBoostItem(idDamageBoostItem *this)
{
  idEventReceiver::idEventReceiver(this);
  this->decl = nullptr;
  this->count = 0;
  this->__vftable = (idDamageBoostItem_vtbl *)&idDamageBoostItem::`vftable';
  this->forSale = false;
  this->lootable = false;
  this->buyBackItem = false;
  this->alreadyDropped = false;
  this->quickSlot = -1;
  this->counttosave = -1;
  this->coolDownTime = 0;
  this->skinPreload = nullptr;
  return this;
}


// ========================================================================
// ??0idThrowableItem@@QAA@XZ
// EA  : 0x82EB98F0
// RVA : 0x00EB98F0
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

idThrowableItem *__fastcall idThrowableItem::idThrowableItem(idThrowableItem *this)
{
  idEventReceiver::idEventReceiver(this);
  this->decl = nullptr;
  this->count = 0;
  this->forSale = false;
  this->lootable = false;
  this->buyBackItem = false;
  this->alreadyDropped = false;
  this->quickSlot = -1;
  this->counttosave = -1;
  this->coolDownTime = 0;
  this->skinPreload = nullptr;
  this->__vftable = (idThrowableItem_vtbl *)&idThrowableItem::`vftable';
  idFXManager::idFXManager(this: &this->fxManager);
  return this;
}


// ========================================================================
// __unwind$495728
// EA  : 0x82EB9974
// RVA : 0x00EB9974
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void _unwind_495728()
{
  int v0; // r12

  idInventoryItem::~idInventoryItem(this: *(idInventoryItem **)(v0 - 112 + 132));
}


// ========================================================================
// ??1idThrowableItem@@UAA@XZ
// EA  : 0x82EB99A8
// RVA : 0x00EB99A8
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __fastcall idThrowableItem::~idThrowableItem(idThrowableItem *this)
{
  this->__vftable = (idThrowableItem_vtbl *)&idThrowableItem::`vftable';
  idFXManager::~idFXManager(this: &this->fxManager);
  this->__vftable = (idThrowableItem_vtbl *)&idInventoryItem::`vftable';
  idEventReceiver::~idEventReceiver(this);
}


// ========================================================================
// __unwind$495750_0
// EA  : 0x82EB9A08
// RVA : 0x00EB9A08
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void _unwind_495750_0()
{
  int v0; // r12

  idInventoryItem::~idInventoryItem(this: *(idInventoryItem **)(v0 - 112 + 132));
}


// ========================================================================
// ?Show@idWeapon@@UAAXXZ
// EA  : 0x82EB9A30
// RVA : 0x00EB9A30
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __fastcall idWeapon::Show(idWeapon *this)
{
  idPieceEmitter *pieceEmitterEntity; // r11

  pieceEmitterEntity = this->pieceEmitterEntity;
  if ( pieceEmitterEntity != nullptr )
    ((void (*)(void))pieceEmitterEntity->Show)();
}


// ========================================================================
// ?AmmoInClip@idWeapon@@QBAH_N@Z
// EA  : 0x82EB9A58
// RVA : 0x00EB9A58
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

idAmmoItem *__fastcall idWeapon::AmmoInClip(idWeapon *this, bool secondaryAmmo)
{
  idAmmoItem *result; // r3

  if ( secondaryAmmo )
    result = this->ammoClipSecondary;
  else
    result = this->ammoClip;
  if ( result != nullptr )
    return (idAmmoItem *)result->GetCount(this: result);
  return result;
}


// ========================================================================
// ?AmmoInClipToSave@idWeapon@@UBAH_N@Z
// EA  : 0x82EB9A90
// RVA : 0x00EB9A90
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

int __fastcall idWeapon::AmmoInClipToSave(idWeapon *this, bool secondaryAmmo)
{
  int result; // r3

  result = this->ammoInClipToSave;
  if ( result <= -1 )
  {
    if ( secondaryAmmo )
      result = (int)this->ammoClipSecondary;
    else
      result = (int)this->ammoClip;
    if ( result != 0 )
      return (*(int (__fastcall **)(int))(*(_DWORD *)result + 52))(a1: result);
  }
  return result;
}


// ========================================================================
// ?SetWeaponMode@idWeapon@@QAAX_N@Z
// EA  : 0x82EB9AD8
// RVA : 0x00EB9AD8
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __fastcall idWeapon::SetWeaponMode(idWeapon *this, bool secondary)
{
  if ( secondary )
  {
    if ( this->ammoClipSecondary != nullptr )
      this->weaponState = WEAPONSTATE_SECONDARY;
  }
  else if ( this->ammoClip != nullptr )
  {
    this->weaponState = WEAPONSTATE_NORMAL;
  }
}


// ========================================================================
// ?TotalLoadedAmmoCount@idLaserCutter@@UBAHPBVidInventoryCollection@@_N@Z
// EA  : 0x82EB9B18
// RVA : 0x00EB9B18
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

int __fastcall idLaserCutter::TotalLoadedAmmoCount(
        idLaserCutter *this,
        const idInventoryCollection *inventory,
        bool secondaryAmmo)
{
  return this->batteryCount;
}


// ========================================================================
// ?SetAmmoInClipToLoad@idLaserCutter@@UAAX_NH@Z
// EA  : 0x82EB9B20
// RVA : 0x00EB9B20
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __fastcall idLaserCutter::SetAmmoInClipToLoad(idLaserCutter *this, bool secondaryAmmo, int count)
{
  this->batteryCount = count;
}


// ========================================================================
// ?AmmoInClipPercentage@idLaserCutter@@UBAM_N@Z
// EA  : 0x82EB9B28
// RVA : 0x00EB9B28
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
float __fastcall idLaserCutter::AmmoInClipPercentage(
        idLaserCutter *this,
        bool secondaryAmmo,
        int a3,
        int a4,
        __int64 a5)
{
  int maxBattery; // r9
  double v6; // fp1

  maxBattery = this->maxBattery;
  LODWORD(a5) = this->batteryCount;
  v6 = (float)((float)a5 / (float)*(__int64 *)((char *)&a5 - 4));
  return *((float *)&v6 + 1);
}


// ========================================================================
// ?NextFunctionalityLens@idLaserCutter@@QAAXXZ
// EA  : 0x82EB9B60
// RVA : 0x00EB9B60
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __fastcall idLaserCutter::NextFunctionalityLens(idLaserCutter *this)
{
  idLaserCutter::functionalityLens_t currentFunctionalityLens; // r11
  int v2; // r5

  currentFunctionalityLens = this->currentFunctionalityLens;
  v2 = 0;
  while ( 1 )
  {
    currentFunctionalityLens = (currentFunctionalityLens + 1) % 3;
    if ( ((1 << currentFunctionalityLens) & this->availableFunctionalityLenses) != 0 )
      break;
    if ( ++v2 >= 3 )
      return;
  }
  this->currentFunctionalityLens = currentFunctionalityLens;
}


// ========================================================================
// ?OverrideShootingLaserBeam@idLaserCutter@@QAAXABUlaserSightInfo_t@@@Z
// EA  : 0x82EB9BC0
// RVA : 0x00EB9BC0
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __fastcall idLaserCutter::OverrideShootingLaserBeam(
        idLaserCutter *this,
        const laserSightInfo_t *overrideInfo,
        int a3,
        int a4,
        const idMaterial *a5,
        int a6,
        int a7,
        int a8)
{
  int v10; // r9
  const idMaterial *v11; // r7
  int v12; // [sp+8h] [-78h]
  int v13; // [sp+8h] [-78h]
  int v14; // [sp+Ch] [-74h]
  int v15; // [sp+Ch] [-74h]
  int v16; // [sp+10h] [-70h]
  int v17; // [sp+10h] [-70h]
  int v18; // [sp+14h] [-6Ch]
  int v19; // [sp+14h] [-6Ch]
  int v20; // [sp+18h] [-68h]
  int v21; // [sp+18h] [-68h]
  int v22; // [sp+1Ch] [-64h]
  int v23; // [sp+1Ch] [-64h]
  int v24; // [sp+20h] [-60h]
  int v25; // [sp+20h] [-60h]
  int v26; // [sp+24h] [-5Ch]
  int v27; // [sp+24h] [-5Ch]
  int v28; // [sp+28h] [-58h]
  int v29; // [sp+28h] [-58h]
  int v30; // [sp+2Ch] [-54h]
  int v31; // [sp+2Ch] [-54h]
  int v32; // [sp+30h] [-50h]
  int v33; // [sp+30h] [-50h]
  int v34; // [sp+34h] [-4Ch]
  int v35; // [sp+34h] [-4Ch]
  int v36; // [sp+38h] [-48h]
  int v37; // [sp+38h] [-48h]
  int v38; // [sp+3Ch] [-44h]
  int v39; // [sp+3Ch] [-44h]
  int v40; // [sp+40h] [-40h]
  int v41; // [sp+40h] [-40h]
  int v42; // [sp+44h] [-3Ch]
  int v43; // [sp+44h] [-3Ch]
  int v44; // [sp+48h] [-38h]
  int v45; // [sp+48h] [-38h]
  int v46; // [sp+4Ch] [-34h]
  int v47; // [sp+4Ch] [-34h]
  int v48; // [sp+50h] [-30h]
  int v49; // [sp+50h] [-30h]
  int v50; // [sp+54h] [-2Ch]
  int v51; // [sp+54h] [-2Ch]
  int v52; // [sp+58h] [-28h]
  int v53; // [sp+58h] [-28h]
  int v54; // [sp+5Ch] [-24h]
  int v55; // [sp+5Ch] [-24h]
  int v56; // [sp+60h] [-20h]
  int v57; // [sp+60h] [-20h]

  idLaserSight::Init(
    this: &this->laserBeamShoot,
    _beamEffects: this->beamModelFPView,
    _decalEffects: this->decalModelFPView,
    laserBeamMtr: overrideInfo->laserBeamMtr,
    laserBeamHeight: overrideInfo->laserBeamHeight,
    laserPointMtr: a5,
    laserPointSize: overrideInfo->laserDotSize,
    laserPointDepth: overrideInfo->laserDotDepth,
    fadeIn: overrideInfo->fadeIn,
    fadeOut: overrideInfo->fadeOut,
    isQuad: overrideInfo->laserDotMtr,
    a12: a7,
    a13: a8,
    a14: v12,
    a15: v14,
    a16: v16,
    a17: v18,
    a18: v20,
    a19: v22,
    a20: v24,
    a21: v26,
    a22: v28,
    a23: v30,
    a24: v32,
    a25: v34,
    a26: v36,
    a27: v38,
    a28: v40,
    a29: v42,
    a30: v44,
    a31: v46,
    a32: v48,
    a33: v50,
    a34: v52,
    a35: v54,
    a36: v56,
    a37: overrideInfo->laserDotQuad);
  idLaserSight::Init(
    this: &this->laserBeamShootBounce,
    _beamEffects: this->beamModelWorldView,
    _decalEffects: this->decalModelworldView,
    laserBeamMtr: overrideInfo->laserBeamMtr,
    laserBeamHeight: overrideInfo->laserBeamHeight,
    laserPointMtr: v11,
    laserPointSize: overrideInfo->laserDotSize,
    laserPointDepth: overrideInfo->laserDotDepth,
    fadeIn: overrideInfo->fadeIn,
    fadeOut: overrideInfo->fadeOut,
    isQuad: overrideInfo->laserDotMtr,
    a12: v10,
    a13: overrideInfo->laserDotQuad,
    a14: v13,
    a15: v15,
    a16: v17,
    a17: v19,
    a18: v21,
    a19: v23,
    a20: v25,
    a21: v27,
    a22: v29,
    a23: v31,
    a24: v33,
    a25: v35,
    a26: v37,
    a27: v39,
    a28: v41,
    a29: v43,
    a30: v45,
    a31: v47,
    a32: v49,
    a33: v51,
    a34: v53,
    a35: v55,
    a36: v57,
    a37: overrideInfo->laserDotQuad);
}


// ========================================================================
// ??0idVehicleUpgrade@@QAA@XZ
// EA  : 0x82EB9C60
// RVA : 0x00EB9C60
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

idVehicleUpgrade *__fastcall idVehicleUpgrade::idVehicleUpgrade(idVehicleUpgrade *this)
{
  idEventReceiver::idEventReceiver(this);
  this->decl = nullptr;
  this->damage = 0.0;
  this->count = 0;
  this->forSale = false;
  this->lootable = false;
  this->buyBackItem = false;
  this->alreadyDropped = false;
  this->quickSlot = -1;
  this->counttosave = -1;
  this->coolDownTime = 0;
  this->skinPreload = nullptr;
  this->__vftable = (idVehicleUpgrade_vtbl *)&idVehicleUpgrade::`vftable';
  this->newUpgrade = true;
  return this;
}


// ========================================================================
// ?SetHealth@idVehicleKey@@QAAXM@Z
// EA  : 0x82EB9CE0
// RVA : 0x00EB9CE0
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __fastcall idVehicleKey::SetHealth(idVehicleKey *this, double h)
{
  this->health = h;
}


// ========================================================================
// ?SetCurrentWeaponGroup@idVehicleKey@@QAAXABH_N@Z
// EA  : 0x82EB9CE8
// RVA : 0x00EB9CE8
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __fastcall idVehicleKey::SetCurrentWeaponGroup(idVehicleKey *this, int *weaponGroup, const bool force)
{
  if ( force || this->currentWeaponGroup == -1 )
    this->currentWeaponGroup = *weaponGroup;
}


// ========================================================================
// ??0idPlayerArmor@@QAA@XZ
// EA  : 0x82EB9D10
// RVA : 0x00EB9D10
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

idPlayerArmor *__fastcall idPlayerArmor::idPlayerArmor(idPlayerArmor *this)
{
  idEventReceiver::idEventReceiver(this);
  this->decl = nullptr;
  this->count = 0;
  this->curArmorValue = 0.0;
  this->forSale = false;
  this->lootable = false;
  this->buyBackItem = false;
  this->alreadyDropped = false;
  this->quickSlot = -1;
  this->counttosave = -1;
  this->coolDownTime = 0;
  this->skinPreload = nullptr;
  this->__vftable = (idPlayerArmor_vtbl *)&idPlayerArmor::`vftable';
  return this;
}


// ========================================================================
// ??0idSecretItem@@QAA@XZ
// EA  : 0x82EB9D88
// RVA : 0x00EB9D88
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

idSecretItem *__fastcall idSecretItem::idSecretItem(idSecretItem *this)
{
  idEventReceiver::idEventReceiver(this);
  this->decl = nullptr;
  this->count = 0;
  this->__vftable = (idSecretItem_vtbl *)&idSecretItem::`vftable';
  this->forSale = false;
  this->lootable = false;
  this->buyBackItem = false;
  this->alreadyDropped = false;
  this->quickSlot = -1;
  this->counttosave = -1;
  this->coolDownTime = 0;
  this->skinPreload = nullptr;
  this->secretId = -1;
  this->needSetup = true;
  return this;
}


// ========================================================================
// ?Use@idSecretItem@@UAA_NPAVidActor@@@Z
// EA  : 0x82EB9E00
// RVA : 0x00EB9E00
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

int __fastcall idSecretItem::Use(idSecretItem *this, idPlayer *user)
{
  idPlayerProfileGame *v3; // r3

  if ( idPlayer::CastTo(c: user) == nullptr )
    return 0;
  if ( this->secretId < 0 )
    return 0;
  v3 = (idPlayerProfileGame *)common->GetProfileFromMasterLocalUser(this: common);
  if ( v3 == nullptr )
    return 0;
  idPlayerProfileGame::SetSecret(this: v3, secretId: this->secretId);
  return 1;
}


// ========================================================================
// ?VehicleDied@idVehicle_Teleporter@@UAAXXZ
// EA  : 0x82EB9E88
// RVA : 0x00EB9E88
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __fastcall idVehicle_Teleporter::VehicleDied(idVehicle_Teleporter *this)
{
  idLib::Printf(fmt: "Teleporter deleted by death\n");
  this->teleporterPlaced = false;
  this->active = false;
}


// ========================================================================
// ??0idClientServerInterfaceClient@@QAA@XZ
// EA  : 0x82EB9EC8
// RVA : 0x00EB9EC8
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

idClientServerInterfaceClient *__fastcall idClientServerInterfaceClient::idClientServerInterfaceClient(
        idClientServerInterfaceClient *this)
{
  this->entity = nullptr;
  this->__vftable = (idClientServerInterfaceClient_vtbl *)&idClientServerInterfaceClient::`vftable';
  return this;
}


// ========================================================================
// ?GetDisplayName@idInventoryItem@@QBA?AVidStrId@@XZ
// EA  : 0x82EBA108
// RVA : 0x00EBA108
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

idInventoryItem *__fastcall idInventoryItem::GetDisplayName(idInventoryItem *this, idStrId *result)
{
  this->__vftable = *(idInventoryItem_vtbl **)(result[3].index + 164);
  return this;
}


// ========================================================================
// ?DebugGetContentsString@idInventoryItem@@QBAXAAVidStr@@@Z
// EA  : 0x82EBA118
// RVA : 0x00EBA118
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __fastcall idInventoryItem::DebugGetContentsString(idInventoryItem *this, idStr *itemString)
{
  idWeapon *v4; // r3
  _DWORD *v5; // r30
  const idDeclAmmo *v6; // r4
  const idDeclInventory *decl; // r11
  const char *str; // r31
  int ClipSize; // r28
  int v10; // r3
  idInventoryItem *v11; // r3
  int maxCount; // r30
  const char *v13; // r31
  int (__fastcall *GetCount)(idInventoryItem *); // ctr
  int v15; // r3

  v4 = idWeapon::CastTo(c: (idWeapon *)this);
  if ( v4 != nullptr )
  {
    v5 = &v4->ammoClip->__vftable;
    v6 = (const idDeclAmmo *)v5[3];
    decl = this->decl;
    if ( v6->stackable )
    {
      str = decl->name.str;
      ClipSize = idDeclWeapon::GetClipSize(
                   this: (idDeclWeapon *)v4->decl,
                   ammoDecl: v6,
                   weaponUpgraded: (*((_BYTE *)v4 + 452) & 4) != 0,
                   secondary: false);
      v10 = (*(int (__fastcall **)(_DWORD *))(*v5 + 52))(a1: v5);
      idStr::Format(this: itemString, fmt: "   %s (%d rounds/%d)", str, v10, ClipSize);
      return;
    }
    goto LABEL_8;
  }
  decl = this->decl;
  if ( !decl->stackable )
  {
LABEL_8:
    idStr::Format(this: itemString, fmt: "   %s", decl->name.str);
    return;
  }
  v11 = this;
  maxCount = decl->maxCount;
  GetCount = this->GetCount;
  v13 = decl->name.str;
  v15 = GetCount(this: v11);
  if ( maxCount < 0 )
    idStr::Format(this: itemString, fmt: "   %s (%d/unlimited)", v13, v15);
  else
    idStr::Format(this: itemString, fmt: "   %s (%d/%d)", v13, v15, maxCount);
}


// ========================================================================
// ?Create@idInventoryItem@@SAPAV1@PBVidDeclInventory@@@Z
// EA  : 0x82EBA240
// RVA : 0x00EBA240
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

idInventoryItem *__fastcall idInventoryItem::Create(const idDeclInventory *decl)
{
  idInventoryItem *Instance; // r3
  idInventoryItem *v3; // r3
  idInventoryItem *v4; // r31

  if ( decl == nullptr )
    return nullptr;
  Instance = (idInventoryItem *)idClass::CreateInstance(name: decl->inventoryClass.data);
  v3 = idInventoryItem::CastTo(c: Instance);
  v4 = v3;
  if ( v3 == nullptr )
    return nullptr;
  v3->Init(this: v3, a2: decl);
  return v4;
}


// ========================================================================
// ?GetPrice@idInventoryItem@@QBAHXZ
// EA  : 0x82EBA2B8
// RVA : 0x00EBA2B8
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

int __fastcall idInventoryItem::GetPrice(idInventoryItem *this)
{
  double VendorSalePriceScale; // fp1
  __int64 v3; // r7
  double v4; // fp0

  VendorSalePriceScale = idGameLocal::GetVendorSalePriceScale(this: gameLocal);
  LODWORD(v3) = this->decl->price;
  v4 = (float)((float)VendorSalePriceScale * (float)v3);
  if ( v4 >= 1.0 )
    return (int)v4;
  else
    return 1;
}


// ========================================================================
// ?ModifyCount@idInventoryItem@@QAAHH@Z
// EA  : 0x82EBA340
// RVA : 0x00EBA340
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

int __fastcall idInventoryItem::ModifyCount(idInventoryItem *this, const int amount)
{
  const idDeclInventory *decl; // r30
  __int16 maxCountOverride; // r11
  int maxCount; // r10
  int count; // r11

  decl = this->decl;
  this->count += amount;
  if ( !common->IsMultiplayer(this: common)
    || (maxCountOverride = decl->maxCountOverride, maxCount = maxCountOverride, maxCountOverride < 0) )
  {
    maxCount = decl->maxCount;
  }
  count = this->count;
  if ( count >= 0 )
  {
    if ( count <= maxCount )
    {
      this->count = count;
      return count;
    }
    else
    {
      this->count = maxCount;
      return maxCount;
    }
  }
  else
  {
    this->count = 0;
    return 0;
  }
}


// ========================================================================
// ?SetCount@idInventoryItem@@QAAXH@Z
// EA  : 0x82EBA3F0
// RVA : 0x00EBA3F0
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __fastcall idInventoryItem::SetCount(idInventoryItem *this, int amount)
{
  const idDeclInventory *decl; // r30
  int setCountOverride; // r11
  const idDeclInventory *v6; // r30
  __int16 maxCountOverride; // r11
  int maxCount; // r10
  int count; // r11

  decl = this->decl;
  if ( !common->IsMultiplayer(this: common) || (setCountOverride = decl->setCountOverride) < 0 )
    setCountOverride = amount;
  this->count = setCountOverride;
  v6 = this->decl;
  if ( !common->IsMultiplayer(this: common)
    || (maxCountOverride = v6->maxCountOverride, maxCount = maxCountOverride, maxCountOverride < 0) )
  {
    maxCount = v6->maxCount;
  }
  count = this->count;
  if ( count < 0 )
  {
    count = 0;
LABEL_9:
    this->count = count;
    return;
  }
  if ( count <= maxCount )
    goto LABEL_9;
  this->count = maxCount;
}


// ========================================================================
// ?SerializeNonPrediction@idWeapon@@UAAXAAVidSerializer@@PAVidInventoryCollection@@@Z
// EA  : 0x82EBA4B0
// RVA : 0x00EBA4B0
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __fastcall idWeapon::SerializeNonPrediction(idWeapon *this, idSerializer *ser, idInventoryCollection *inventory)
{
  idTracerManager::Serialize(this: &this->tracerManager, ser);
}


// ========================================================================
// ?ClientUpdate@idWeapon@@UAAXXZ
// EA  : 0x82EBA4B8
// RVA : 0x00EBA4B8
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __fastcall idWeapon::ClientUpdate(idWeapon *this)
{
  int GameMs; // r3

  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  idTracerManager::Update(this: &this->tracerManager, time: GameMs);
}


// ========================================================================
// ?Init@idAmmoItem@@UAAXPBVidDeclInventory@@@Z
// EA  : 0x82EBA508
// RVA : 0x00EBA508
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __fastcall idAmmoItem::Init(idAmmoItem *this, const idDeclInventory *decl)
{
  this->decl = decl;
  this->count = decl->count;
  this->counttosave = -1;
  this->forSale = false;
  this->lootable = false;
  this->burstMode = decl[1].requiredName.index;
}


// ========================================================================
// ?GetProjectileDef@idAmmoItem@@QBAPBVidDeclProjectile@@XZ
// EA  : 0x82EBA538
// RVA : 0x00EBA538
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

idDeclInventory_vtbl *__fastcall idAmmoItem::GetProjectileDef(idAmmoItem *this)
{
  const idDeclInventory *decl; // r11
  idDeclInventory_vtbl *result; // r3

  decl = this->decl;
  result = nullptr;
  if ( decl != nullptr )
    return decl[1].__vftable;
  return result;
}


// ========================================================================
// ?CanUseForHealth@idHealthItem@@AAA_NPBVidEntity@@@Z
// EA  : 0x82EBA5B8
// RVA : 0x00EBA5B8
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

int __fastcall idHealthItem::CanUseForHealth(idHealthItem *this, const idEntity *user)
{
  const idBaseHealth *v3; // r3
  bool v4; // r3
  unsigned __int8 v5; // r11

  if ( *(float *)&this->decl[1].__vftable <= 0.0 )
    return 0;
  if ( user->GetHealthComponent(this: user) == nullptr )
    return 0;
  v3 = user->GetHealthComponent(this: user);
  v4 = v3->IsDead_Impl(this: (idBaseHealth *)v3);
  v5 = 1;
  if ( v4 )
    return 0;
  return v5;
}


// ========================================================================
// ?Use@idHealthItem@@UAA_NPAVidActor@@@Z
// EA  : 0x82EBA668
// RVA : 0x00EBA668
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

int __fastcall idHealthItem::Use(idHealthItem *this, idActor *user)
{
  int v5; // r29
  double v6; // fp31
  idBaseHealth *v7; // r3
  const idDeclInventory *decl; // r11
  const idSoundShader *useSound; // r5

  if ( user == nullptr )
    return 0;
  v5 = 0;
  if ( (unsigned __int8)idHealthItem::CanUseForHealth(this, user) != 0 )
  {
    v6 = *(float *)&this->decl[1].__vftable;
    v7 = user->GetHealthComponent_2(this: user);
    v7->Heal_Impl(this: v7, a2: v6);
    v5 = 1;
  }
  decl = this->decl;
  if ( decl != nullptr )
  {
    useSound = decl->useSound;
    if ( useSound != nullptr )
      idEntity::StartSoundShader(
        this: user,
        channel: SND_CHANNEL_ITEM,
        shader: useSound,
        soundShaderFlags: (soundShaderFlags_t)0,
        peerMask: 0xFFu);
  }
  return v5;
}


// ========================================================================
// ?ClientUse@idHealthItem@@UAA_NPAVidPresentablePlayer@@@Z
// EA  : 0x82EBA728
// RVA : 0x00EBA728
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

int __fastcall idHealthItem::ClientUse(idHealthItem *this, idPresentablePlayer *player)
{
  int result; // r3
  const idDeclInventory *decl; // r11
  const idSoundShader *useSound; // r5

  result = (int)player;
  if ( player != nullptr )
  {
    decl = this->decl;
    if ( decl != nullptr )
    {
      useSound = decl->useSound;
      if ( useSound != nullptr )
        idPresentablePlayer::PlayLocalSound(
          this: player,
          channel: SND_CHANNEL_ITEM,
          shader: useSound,
          soundShaderFlags: (soundShaderFlags_t)0);
    }
    return 1;
  }
  return result;
}


// ========================================================================
// ?Use@idDamageBoostItem@@UAA_NPAVidActor@@@Z
// EA  : 0x82EBA790
// RVA : 0x00EBA790
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

int __fastcall idDamageBoostItem::Use(idDamageBoostItem *this, idActor *user)
{
  if ( user == nullptr )
    return 0;
  user->SetApplyDamageScale(
    this: user,
    a2: *(float *)&this->decl[1].__vftable,
    a3: *(float *)&this->decl[1].trackedMemory);
  return 1;
}


// ========================================================================
// ?Use@idAuthorityBoostItem@@UAA_NPAVidActor@@@Z
// EA  : 0x82EBA7F0
// RVA : 0x00EBA7F0
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

int __fastcall idAuthorityBoostItem::Use(idAuthorityBoostItem *this, idPlayer *user)
{
  int v4; // r11
  char v5; // r11
  bool v6; // zf
  idPlayer *v7; // r26
  __int64 v8; // r8
  int v9; // r5
  int v10; // r4
  double v11; // fp31
  const idDeclInventory *decl; // r11
  int v13; // r27
  int v14; // r31
  const idDeclJob *v15; // r25
  idJobManager *v16; // r3
  double v17; // fp2

  if ( user == nullptr )
    return 0;
  v4 = *(_DWORD *)(user->GetType(this: user) + 36);
  if ( v4 < idPlayer::Type.typeNum || (v6 = v4 <= idPlayer::Type.lastChild, v5 = 1, !v6) )
    v5 = 0;
  if ( v5 == 0 )
    return 0;
  v7 = idPlayer::CastTo(c: user);
  if ( idPlayer::GetAuthorityDetonationTimeRatio(this: v7, a2: v10, a3: v9, a4: v8) != 0.0 )
    return 0;
  v11 = *(float *)&this->decl[1].resourceListPtr;
  ((void (__fastcall *)(idPlayer *, double))user->SetApplyAuthorityForce)(a1: user, a2: v11);
  idEntity::StartSoundShader(
    this: user,
    channel: SND_CHANNEL_JET_PACK,
    shader: this->decl->useSound,
    soundShaderFlags: (soundShaderFlags_t)0,
    peerMask: 0xFFu);
  decl = this->decl;
  v13 = 0;
  if ( decl[1].trackedMemory > 0 )
  {
    v14 = 0;
    do
    {
      v15 = *(const idDeclJob **)((char *)&decl[1].dtr_idResource + v14);
      v16 = (idJobManager *)v7->GetInventory_2(this: v7);
      if ( idJobManager::FindJobByDecl(this: v16, jobDecl: v15) != nullptr )
      {
        if ( *(float *)((char *)&this->decl[1].LoadResource + v14) > 1.0 )
          ((void (__fastcall *)(idPlayer *))user->SetApplyDamageScale)(a1: user);
        if ( *((_BYTE *)&this->decl[1].ReloadIfStale + v14) != 0 )
          user->SetApplyInvulnerability(this: user, a2: v11);
        v17 = *(float *)((char *)&this->decl[1].WriteResourceFile + v14);
        if ( v17 > 0.0 && v17 < 1.0 )
          ((void (__fastcall *)(idPlayer *, double))user->SetApplyBulletTime)(a1: user, a2: v11);
      }
      decl = this->decl;
      ++v13;
      v14 += 16;
    }
    while ( v13 < decl[1].trackedMemory );
  }
  return 1;
}


// ========================================================================
// ?GetClipSize@idWeapon@@UBAHPBVidAmmoItem@@PBVidDeclAmmo@@_N2@Z
// EA  : 0x82EBAA60
// RVA : 0x00EBAA60
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

int __fastcall idWeapon::GetClipSize(
        idWeapon *this,
        const idAmmoItem *ammo,
        const idDeclAmmo *ammoDecl,
        bool weaponUpgraded,
        bool secondaryAmmo)
{
  return idDeclWeapon::GetClipSize(this: (idDeclWeapon *)this->decl, ammoDecl, weaponUpgraded, secondary: secondaryAmmo);
}


// ========================================================================
// ?Init@idWeapon@@UAAXPBVidDeclInventory@@@Z
// EA  : 0x82EBAA78
// RVA : 0x00EBAA78
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __fastcall idWeapon::Init(idWeapon *this, const idDeclInventory *decl)
{
  int count; // r11
  char thirdPersonMD6_high; // r5
  char v6; // r9
  __int64 v7; // r10
  __int64 v8; // r8
  __int64 v9; // r6
  const idDeclEntityDef *entityDef; // r4
  idPieceEmitter *v11; // r29
  idPieceEmitter *v12; // r3
  idDeclInventory_vtbl *v13; // r5
  va *v14; // r3
  const idDeclAmmo *trackedMemory; // r5
  int index; // r29
  idRenderModelEffects *MergeBranch; // r3
  char v18; // r9
  char v19; // r8
  char v20; // r9
  char noPickupMessage; // r3
  int v22; // [sp+8h] [-1078h]
  int v23; // [sp+Ch] [-1074h]
  int v24; // [sp+10h] [-1070h]
  int v25; // [sp+14h] [-106Ch]
  int v26; // [sp+18h] [-1068h]
  int v27; // [sp+1Ch] [-1064h]
  va v28; // [sp+50h] [-1030h] BYREF

  this->decl = decl;
  count = decl->count;
  this->counttosave = -1;
  this->forSale = false;
  this->lootable = false;
  this->count = count;
  thirdPersonMD6_high = HIBYTE(decl[1].thirdPersonMD6);
  this->fireChannel = 6;
  v6 = *((_BYTE *)this + 452);
  this->quadFireChannel = 73;
  *((_BYTE *)this + 452) = (32 * thirdPersonMD6_high) & 0x20 | v6 & 0xDF;
  HIDWORD(v7) = common->IsServer(this: common);
  if ( HIDWORD(v7) != 0 )
  {
    entityDef = decl[3].entityDef;
    if ( entityDef != nullptr )
    {
      v11 = (idPieceEmitter *)gameLocal->SpawnEntityFromDef(this: gameLocal, a2: entityDef, a3: -1, a4: -1, a5: -1);
      v12 = idPieceEmitter::CastTo(c: v11);
      this->pieceEmitterEntity = v12;
      if ( v12 != nullptr )
      {
        v12->emitFovScale = decl->handsFovScale;
      }
      else if ( v11 != nullptr )
      {
        ((void (__fastcall *)(idPieceEmitter *, int))v11->dtr_idClass)(a1: v11, a2: 1);
      }
    }
  }
  LODWORD(v7) = (4 * HIBYTE(decl[3].networkID)) & 4 | *((_BYTE *)this + 452) & 0xFB;
  *((_BYTE *)this + 452) = v7;
  v13 = decl[1].__vftable;
  if ( v13 != nullptr )
  {
    this->LoadAmmo(
      this,
      a2: nullptr,
      a3: (const idDeclAmmo *)v13,
      a4: nullptr,
      a5: false,
      a6: true,
      a7: false,
      a8: false);
  }
  else if ( decl[1].trackedMemory == 0 )
  {
    HIDWORD(v9) = decl->name.str;
    v14 = va::va(
            this: &v28,
            fmt: "Weapon '%s' with invalid initialAmmoDecl!",
            a3: v9,
            a4: v8,
            a5: v7,
            a6: v22,
            a7: v23,
            a8: v24,
            a9: v25,
            a10: v26,
            a11: v27);
    idLib::Warning(fmt: v14->buffer);
    return;
  }
  trackedMemory = (const idDeclAmmo *)decl[1].trackedMemory;
  if ( trackedMemory != nullptr )
    this->LoadAmmo(this, a2: nullptr, a3: trackedMemory, a4: nullptr, a5: false, a6: true, a7: false, a8: true);
  if ( this->ammoClip == nullptr && this->ammoClipSecondary != nullptr )
    this->weaponState = WEAPONSTATE_SECONDARY;
  if ( idClientGame::GetLocalPresentablePlayer(this: clientGame) != nullptr )
    index = idClientGame::GetLocalPresentablePlayer(this: clientGame)->index;
  else
    index = 0;
  MergeBranch = (idRenderModelEffects *)idAnimator_BlendEq::InternalGetMergeBranch(this: (idAnimator_BlendEq *)clientGame);
  idTracerManager::Init(this: &this->tracerManager, _effectsModel: MergeBranch, playerIndex: index);
  if ( *(_DWORD *)&decl[3].giveable != 0 && *(_DWORD *)decl[3].vehicleJointName.baseBuffer != 0 )
    *((_BYTE *)this + 452) |= 0x80u;
  v18 = *((_BYTE *)this + 453);
  v19 = (16 * HIBYTE(decl[2].scriptUse.type)) & 0x10 | *((_BYTE *)this + 452) & 0xEF;
  *((_BYTE *)this + 452) = v19;
  *((_BYTE *)this + 452) = (2 * decl[3].hasBeenParsedAtLeastOnce) & 2 | v19 & 0xFD;
  v20 = (HIBYTE(decl[3].childItem.granularity) << 6) & 0x40 | v18 & 0xBF;
  *((_BYTE *)this + 453) = v20;
  noPickupMessage = decl[2].noPickupMessage;
  *((_BYTE *)this + 453) = (noPickupMessage << 7) | v20 & 0x7F;
  *((_BYTE *)this + 453) = (16 * HIBYTE(decl[3].merchantIcon)) & 0x10 | (noPickupMessage << 7) | v20 & 0x6F;
}


// ========================================================================
// ?GetInitialBurstCount@idWeapon@@IAAHW4burstMode_t@@_N@Z
// EA  : 0x82EBACF8
// RVA : 0x00EBACF8
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

int __fastcall idWeapon::GetInitialBurstCount(idWeapon *this, const burstMode_t mode, bool secondaryAmmo)
{
  idDeclWeapon *decl; // r3
  idAmmoItem *ammoClipSecondary; // r11
  const idDeclInventory *v7; // r10
  int ClipSize; // r11

  decl = (idDeclWeapon *)this->decl;
  if ( secondaryAmmo )
    ammoClipSecondary = this->ammoClipSecondary;
  else
    ammoClipSecondary = this->ammoClip;
  if ( ammoClipSecondary == nullptr )
    return 0;
  v7 = ammoClipSecondary->decl;
  ClipSize = decl->burstCounts[mode];
  if ( v7[1].requiredName.index != 3 )
    ClipSize = *((_DWORD *)&v7[1].icon + mode);
  if ( ClipSize < 0 )
    return 1;
  if ( ClipSize == 0 )
  {
    ClipSize = idDeclWeapon::GetClipSize(
                 this: decl,
                 ammoDecl: (const idDeclAmmo *)v7,
                 weaponUpgraded: (*((_BYTE *)this + 452) & 4) != 0,
                 secondary: secondaryAmmo);
    if ( ClipSize <= 0 )
      return 0x7FFFFFFF;
  }
  return ClipSize;
}


// ========================================================================
// ?NeedsReload@idWeapon@@UBA_N_N@Z
// EA  : 0x82EBADC8
// RVA : 0x00EBADC8
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

int __fastcall idWeapon::NeedsReload(idWeapon *this, bool secondaryAmmo)
{
  idDeclSource *ammoClipSecondary; // r3

  if ( this->decl[1].declSource == nullptr )
    return 0;
  if ( secondaryAmmo )
    ammoClipSecondary = (idDeclSource *)this->ammoClipSecondary;
  else
    ammoClipSecondary = (idDeclSource *)this->ammoClip;
  if ( ammoClipSecondary != nullptr )
    ammoClipSecondary = (idDeclSource *)(*((int (__fastcall **)(idDeclSource *))ammoClipSecondary->name.str + 13))(a1: ammoClipSecondary);
  return (((((int)this->decl[1].declSource ^ (unsigned int)ammoClipSecondary) & 0x80000000) == 0)
        + (ammoClipSecondary >= this->decl[1].declSource))
       & 1;
}


// ========================================================================
// ?SetAmmoInClipToLoad@idWeapon@@UAAX_NH@Z
// EA  : 0x82EBAE68
// RVA : 0x00EBAE68
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __fastcall idWeapon::SetAmmoInClipToLoad(idWeapon *this, bool secondaryAmmo, int count)
{
  idAmmoItem *ammoClipSecondary; // r3

  if ( secondaryAmmo )
    ammoClipSecondary = this->ammoClipSecondary;
  else
    ammoClipSecondary = this->ammoClip;
  if ( ammoClipSecondary != nullptr )
    idInventoryItem::SetCount(this: &ammoClipSecondary->idInventoryItem, amount: count);
}


// ========================================================================
// ?TotalLoadedAmmoCount@idWeapon@@UBAHPBVidInventoryCollection@@_N@Z
// EA  : 0x82EBAE98
// RVA : 0x00EBAE98
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

int __fastcall idWeapon::TotalLoadedAmmoCount(idWeapon *this, idInventoryCollection *inventory, bool secondaryAmmo)
{
  idAmmoItem *ammoClipSecondary; // r31
  int TotalInventoryItemCount; // r30

  if ( secondaryAmmo )
    ammoClipSecondary = this->ammoClipSecondary;
  else
    ammoClipSecondary = this->ammoClip;
  if ( ammoClipSecondary == nullptr )
    return 0;
  TotalInventoryItemCount = idInventoryCollection::FindTotalInventoryItemCount(
                              this: inventory,
                              decl: ammoClipSecondary->decl);
  return ammoClipSecondary->GetCount(this: ammoClipSecondary) + TotalInventoryItemCount;
}


// ========================================================================
// ?IsValidAmmo@idWeapon@@QBA_NPBVidDeclAmmo@@_N@Z
// EA  : 0x82EBAF18
// RVA : 0x00EBAF18
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

int __fastcall idWeapon::IsValidAmmo(idWeapon *this, const idDeclAmmo *ammoDecl, bool secondaryAmmo)
{
  const idDeclInventory *decl; // r11
  int *p_networkID; // r11
  int v5; // r8
  int v6; // r10
  int v7; // r9
  int i; // r11

  decl = this->decl;
  if ( secondaryAmmo )
    p_networkID = &decl[1].networkID;
  else
    p_networkID = (int *)&decl[1].name;
  v5 = p_networkID[1];
  v6 = 0;
  if ( v5 <= 0 )
    return 0;
  v7 = *p_networkID;
  for ( i = 0; *(const idDeclAmmo **)(i + v7) != ammoDecl; i += 28 )
  {
    if ( ++v6 >= v5 )
      return 0;
  }
  return 1;
}


// ========================================================================
// ?LoadAmmo@idWeapon@@UAAXPAVidInventoryCollection@@PBVidDeclAmmo@@PAVidFXManager@@_N333@Z
// EA  : 0x82EBAF78
// RVA : 0x00EBAF78
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __fastcall idWeapon::LoadAmmo(
        idWeapon *this,
        idInventoryCollection *inventory,
        const idDeclAmmo *ammoDecl,
        idFXManager *fxMgr,
        const bool sameAmmoCount,
        const bool allowForceFullClip,
        const bool skipAddingToClip,
        BOOL secondaryAmmo)
{
  char v16; // r5
  idInventoryItem **p_ammoClipSecondary; // r25
  const idDeclAmmo **v18; // r3
  int v19; // r26
  idInventoryItem *v20; // r3
  idAmmoItem *v21; // r30
  idAmmoItem *v22; // r3
  idAmmoItem *v23; // r28
  idAmmoItem *JobByDecl; // r3
  const idDeclInventory *decl; // r30
  idDeclWeapon *v26; // r24
  int AmmoPerReload; // r29
  idInventoryItem *v28; // r23
  int v29; // r24
  int v30; // r3
  int v31; // r10
  int v32; // r9
  int v33; // r8
  int v34; // r7
  int ClipSize; // r3
  int index; // r11
  int v37; // [sp+8h] [-A8h]
  int v38; // [sp+Ch] [-A4h]
  int v39; // [sp+10h] [-A0h]
  int v40; // [sp+14h] [-9Ch]
  int v41; // [sp+18h] [-98h]
  int v42; // [sp+1Ch] [-94h]
  int v43; // [sp+20h] [-90h]
  lobbyUser_t *v44; // [sp+24h] [-8Ch]

  if ( (unsigned __int8)idWeapon::IsValidAmmo(this, ammoDecl, secondaryAmmo) == 0 )
    return;
  p_ammoClipSecondary = (idInventoryItem **)&this->ammoClipSecondary;
  if ( v16 == 0 )
    p_ammoClipSecondary = (idInventoryItem **)&this->ammoClip;
  v18 = (const idDeclAmmo **)*p_ammoClipSecondary;
  v19 = 0;
  if ( *p_ammoClipSecondary == nullptr )
    goto LABEL_7;
  if ( v18[3] != ammoDecl )
  {
    v19 = ((int (__fastcall *)(const idDeclAmmo **))(*v18)->declSource)(a1: v18);
    this->UnloadAmmo(this, a2: inventory, a3: fxMgr, a4: secondaryAmmo);
LABEL_7:
    v20 = idInventoryItem::Create(decl: ammoDecl);
    v21 = (idAmmoItem *)v20;
    if ( v20 == nullptr )
    {
      idLib::Warning(fmt: "Unknown initial ammo type of '%s' for weapon '%s'", ammoDecl->name.str, this->decl->name.str);
      return;
    }
    if ( (unsigned __int8)idAmmoItem::IsTypeOf(c: v20) == 0 )
    {
      idLib::Warning(fmt: "Invalid initial ammo type of '%s' for weapon '%s'", ammoDecl->name.str, this->decl->name.str);
      ((void (__fastcall *)(idAmmoItem *, int))v21->dtr_idClass)(a1: v21, a2: 1);
      return;
    }
    v22 = idAmmoItem::CastTo(c: v21);
    *p_ammoClipSecondary = &v22->idInventoryItem;
    idInventoryItem::SetCount(this: &v22->idInventoryItem, amount: 0);
  }
  if ( *p_ammoClipSecondary != nullptr )
  {
    v23 = nullptr;
    if ( inventory != nullptr )
    {
      JobByDecl = (idAmmoItem *)idJobManager::FindJobByDecl(
                                  this: (idJobManager *)inventory,
                                  jobDecl: (const idDeclJob *)ammoDecl);
      v23 = idAmmoItem::CastTo(c: JobByDecl);
    }
    decl = (*p_ammoClipSecondary)->decl;
    if ( v23 == nullptr || skipAddingToClip )
    {
      if ( allowForceFullClip && !skipAddingToClip )
      {
        ClipSize = idDeclWeapon::GetClipSize(
                     this: (idDeclWeapon *)this->decl,
                     ammoDecl: (const idDeclAmmo *)(*p_ammoClipSecondary)->decl,
                     weaponUpgraded: (*((_BYTE *)this + 452) & 4) != 0,
                     secondary: secondaryAmmo);
        idInventoryItem::SetCount(this: *p_ammoClipSecondary, amount: ClipSize);
      }
      index = decl[1].requiredName.index;
      if ( index == 3 )
        index = this->decl[1].attachmentInfo.num;
      (*p_ammoClipSecondary)[1].__vftable = (idInventoryItem_vtbl *)index;
    }
    else
    {
      v26 = (idDeclWeapon *)this->decl;
      AmmoPerReload = v23->GetCount(this: v23);
      v28 = *p_ammoClipSecondary;
      v29 = idDeclWeapon::GetClipSize(
              this: v26,
              ammoDecl: (const idDeclAmmo *)decl,
              weaponUpgraded: (*((_BYTE *)this + 452) & 4) != 0,
              secondary: secondaryAmmo);
      v30 = v28->GetCount(this: v28);
      if ( v29 - v30 < AmmoPerReload )
        AmmoPerReload = v29 - v30;
      if ( sameAmmoCount && v19 > 0 )
      {
        if ( AmmoPerReload >= v19 )
          AmmoPerReload = v19;
      }
      else if ( idDeclWeapon::GetAmmoPerReload(
                  this: (idDeclWeapon *)this->decl,
                  ammoDecl: (const idDeclAmmo *)decl,
                  weaponUpgraded: (*((_BYTE *)this + 452) & 4) != 0,
                  secondary: secondaryAmmo) != -1
             && AmmoPerReload > idDeclWeapon::GetAmmoPerReload(
                                  this: (idDeclWeapon *)this->decl,
                                  ammoDecl: (const idDeclAmmo *)decl,
                                  weaponUpgraded: (*((_BYTE *)this + 452) & 4) != 0,
                                  secondary: secondaryAmmo) )
      {
        AmmoPerReload = idDeclWeapon::GetAmmoPerReload(
                          this: (idDeclWeapon *)this->decl,
                          ammoDecl: (const idDeclAmmo *)decl,
                          weaponUpgraded: (*((_BYTE *)this + 452) & 4) != 0,
                          secondary: secondaryAmmo);
      }
      idInventoryItem::ModifyCount(this: &v23->idInventoryItem, amount: -AmmoPerReload);
      idInventoryItem::ModifyCount(this: *p_ammoClipSecondary, amount: AmmoPerReload);
      if ( v23->GetCount(this: v23) <= 0 )
        idInventoryCollection::DeleteInventoryItem(
          this: inventory,
          owner: nullptr,
          item: (lobbyUser_t *)v23,
          count: 1,
          a5: v34,
          a6: v33,
          a7: v32,
          a8: v31,
          a9: v37,
          a10: v38,
          a11: v39,
          a12: v40,
          a13: v41,
          a14: v42,
          a15: v43,
          a16: v44);
    }
  }
}


// ========================================================================
// ?UseAmmo@idWeapon@@QAAXH_N@Z
// EA  : 0x82EBB290
// RVA : 0x00EBB290
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __fastcall idWeapon::UseAmmo(idWeapon *this, const int count, bool secondaryAmmo)
{
  idAmmoItem *ammoClipSecondary; // r11

  if ( secondaryAmmo )
    ammoClipSecondary = this->ammoClipSecondary;
  else
    ammoClipSecondary = this->ammoClip;
  if ( ammoClipSecondary != nullptr
    && g_infiniteAmmo.valueInteger == 0
    && g_permaInfiniteAmmo.valueInteger == 0
    && HIBYTE(this->decl[1].textLength) == 0 )
  {
    idInventoryItem::ModifyCount(this: &ammoClipSecondary->idInventoryItem, amount: -count);
  }
}


// ========================================================================
// ?UpdateAttackType@idWeapon@@IAAXXZ
// EA  : 0x82EBB2F8
// RVA : 0x00EBB2F8
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __fastcall idWeapon::UpdateAttackType(idWeapon *this)
{
  unsigned int v1; // r4

  switch ( this->decl[1].internalName.len )
  {
    case 0:
      this->attackType = ATTACK_DEFAULT;
      return;
    case 1:
      this->attackType = ((_cntlzw(this->attackType - 1) & 0x20) != 0) + 1;
      return;
    case 2:
      v1 = 1664525 * clientGame->random.seed + 1013904223;
      clientGame->random.seed = v1;
      if ( ((v1 >> 10) & 0x7FFF) % 0x64 >= 0x32 )
        goto LABEL_8;
      goto LABEL_12;
    case 3:
      if ( (unsigned int)(this->attackType - 1) > 3 )
        goto LABEL_12;
      switch ( this->attackType )
      {
        case ATTACK_RIGHT:
LABEL_10:
          this->attackType = ATTACK_LEFT2;
          break;
        case ATTACK_LEFT2:
LABEL_9:
          this->attackType = ATTACK_RIGHT2;
          break;
        case ATTACK_LEFT:
LABEL_8:
          this->attackType = ATTACK_RIGHT;
          break;
        default:
LABEL_12:
          this->attackType = ATTACK_LEFT;
          break;
      }
      return;
    case 4:
      goto LABEL_8;
    case 5:
      goto LABEL_12;
    case 6:
      goto LABEL_9;
    case 7:
      goto LABEL_10;
    case 8:
      this->attackType = ATTACK_RIGHT3;
      return;
    case 9:
      this->attackType = ATTACK_LEFT3;
      return;
  }
}


// ========================================================================
// ?Merge@idWeapon@@UAAXPAVidPresentable@@PAVidInventoryCollection@@PBVidDeclInventory@@@Z
// EA  : 0x82EBB430
// RVA : 0x00EBB430
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __fastcall idWeapon::Merge(
        idWeapon *this,
        idPresentable *owner,
        idJobManager *inventory,
        const idDeclInventory *decl)
{
  idDeclInventory_vtbl *trackedMemory; // r31
  int i; // r30
  idAmmoItem *JobByDecl; // r3
  idAmmoItem *v10; // r3

  if ( decl != nullptr && inventory != nullptr && owner != nullptr )
  {
    trackedMemory = decl[1].__vftable;
    for ( i = 2; i != 0; --i )
    {
      if ( trackedMemory != nullptr )
      {
        JobByDecl = (idAmmoItem *)idJobManager::FindJobByDecl(
                                    this: inventory,
                                    jobDecl: (const idDeclJob *)trackedMemory);
        v10 = idAmmoItem::CastTo(c: JobByDecl);
        if ( v10 != nullptr )
          idInventoryItem::ModifyCount(this: &v10->idInventoryItem, amount: (const int)trackedMemory[5].GetResourceList);
        else
          idInventoryCollection::GiveItem(
            this: (idInventoryCollection *)inventory,
            owner,
            decl: (const idDeclJob *)trackedMemory,
            count: 1,
            forceCount: false,
            canIntro: false);
      }
      trackedMemory = (idDeclInventory_vtbl *)decl[1].trackedMemory;
    }
  }
}


// ========================================================================
// ?SetupDualWieldItem@idWeapon@@QAAPAV1@PAVidPresentable@@PBVidDeclInventory@@1@Z
// EA  : 0x82EBB4C8
// RVA : 0x00EBB4C8
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

idWeapon *__fastcall idWeapon::SetupDualWieldItem(
        idWeapon *this,
        idPresentable *owner,
        const idDeclInventory *decl,
        const idDeclInventory *dwItemDecl)
{
  idWeapon *v7; // r3
  idWeapon *v8; // r29
  idWeapon *v9; // r3
  char v10; // r11
  idPresentableActor *v11; // r3
  idPlayer *ActorEntity; // r3
  idPlayer *v13; // r3
  idPlayer *v14; // r30
  idPresentable *v15; // r3
  int v16; // r3
  idPresentable *presentable; // r3
  int v19; // r3

  if ( decl == nullptr || (*((_BYTE *)this + 453) & 0x80) == 0 || (*((_BYTE *)this + 452) & 1) != 0 )
    return nullptr;
  v7 = (idWeapon *)idInventoryItem::Create(decl);
  v8 = idWeapon::CastTo(c: v7);
  if ( v8->dualWieldItem == nullptr )
  {
    v9 = (idWeapon *)idInventoryItem::Create(decl: dwItemDecl);
    v8->dualWieldItem = idWeapon::CastTo(c: v9);
  }
  v10 = *((_BYTE *)this + 453);
  this->dualWieldItem = v8;
  *((_BYTE *)v8 + 453) = v10 & 0x40 | *((_BYTE *)v8 + 453) & 0xBF;
  *((_BYTE *)this + 452) |= 1u;
  v11 = owner->GetActorInterface_2(this: owner);
  ActorEntity = (idPlayer *)idPresentableActor::GetActorEntity(this: v11);
  v13 = idPlayer::CastTo(c: ActorEntity);
  v14 = v13;
  if ( v13 == nullptr )
    return v8;
  if ( this == idActor::GetEquippedWeapon(this: v13, slot: EQUIP_RIGHT_HAND) )
  {
    presentable = v14->presentable;
    if ( presentable != nullptr )
      v19 = (int)presentable->GetPlayerInterface_2(this: presentable);
    else
      v19 = 0;
    idHands::SetPendingAction(this: (idHands *)(v19 + 37616), action: HANDSACTION_TOGGLEDUALWIELD, secondary: false);
    return v8;
  }
  this->wasDualWielding = true;
  v15 = v14->presentable;
  if ( v15 != nullptr )
    v16 = (int)v15->GetPlayerInterface_2(this: v15);
  else
    v16 = 0;
  idHands::SelectWeapon(this: (idHands *)(v16 + 37616), slot: EQUIP_RIGHT_HAND, weapon: this, useIntroBringUp: false);
  return v8;
}


// ========================================================================
// ?GetZoomMode@idWeapon@@QBA?AW4zoomMode_t@idDeclWeapon@@XZ
// EA  : 0x82EBB630
// RVA : 0x00EBB630
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

idDeclWeapon::zoomMode_t __fastcall idWeapon::GetZoomMode(idWeapon *this)
{
  const idDeclAmmo *nextAmmo; // r11
  unsigned int zoomOverride; // r10
  idDeclWeapon::zoomMode_t result; // r3
  idAmmoItem *ammoClip; // r11

  nextAmmo = this->nextAmmo;
  zoomOverride = 0;
  result = ZOOM_NONE;
  if ( nextAmmo != nullptr
    || (ammoClip = this->ammoClip) != nullptr && (nextAmmo = (const idDeclAmmo *)ammoClip->decl) != nullptr )
  {
    zoomOverride = nextAmmo->zoomOverride;
  }
  if ( zoomOverride == 0 )
    return (idDeclWeapon::zoomMode_t)this->decl[2].dropEventDecl;
  if ( zoomOverride == 1 )
    return ZOOM_NONE;
  if ( zoomOverride < 3 )
    return ZOOM_WEAPON;
  return result;
}


// ========================================================================
// ?GetCurrentProjectileDecl@idWeapon@@QBAPBVidDeclProjectile@@_N@Z
// EA  : 0x82EBB698
// RVA : 0x00EBB698
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

idDeclInventory_vtbl *__fastcall idWeapon::GetCurrentProjectileDecl(idWeapon *this, bool secondaryAmmo)
{
  idAmmoItem *ammoClipSecondary; // r11
  const idDeclInventory *decl; // r11

  if ( secondaryAmmo )
    ammoClipSecondary = this->ammoClipSecondary;
  else
    ammoClipSecondary = this->ammoClip;
  if ( ammoClipSecondary != nullptr && (decl = ammoClipSecondary->decl) != nullptr )
    return decl[1].__vftable;
  else
    return nullptr;
}


// ========================================================================
// ?GetMuzzleFlashTagData@idWeapon@@QBA_NPBVidTreeAnimator@@W4attack_t@1@AAUtagData_t@@@Z
// EA  : 0x82EBB6D8
// RVA : 0x00EBB6D8
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

int __fastcall idWeapon::GetMuzzleFlashTagData(
        idWeapon *this,
        const idTreeAnimator *ta,
        int attackType,
        tagData_t *tagData)
{
  const idDeclMD6 *decl; // r11
  const tagData_t *Tag; // r3
  int value; // r7
  int result; // r3

  if ( ta == nullptr )
    return 0;
  decl = ta->decl;
  if ( decl == nullptr )
    return 0;
  if ( decl == (const idDeclMD6 *)-352 )
    return 0;
  if ( attackType >= 7 )
    return 0;
  Tag = idPropsCollection::GetTag(
          this: &decl->props,
          propName: idPropInfo::INFO_PROP_NAME,
          tagName: idWeapon::MUZZLE_FLASH_TAG[attackType]);
  tagData->trans = Tag->trans;
  tagData->rot = Tag->rot;
  value = Tag->parentJoint.value;
  tagData->parentJoint.value = value;
  result = 1;
  if ( value == 0xFFFF )
    return 0;
  return result;
}


// ========================================================================
// ?CheckFireHandle@idWeapon@@QAA_NXZ
// EA  : 0x82EBB798
// RVA : 0x00EBB798
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

BOOL __fastcall idWeapon::CheckFireHandle(idWeapon *this)
{
  return (unsigned __int8)idDeferredFireManager::IsHandleFinished(
                            this: &clientGame->deferredFireManager,
                            handle: this->fireHandle) != 0;
}


// ========================================================================
// ?GetDeferredFireResults@idWeapon@@QAA_NAAVidFireParms@@AAVidTestFireResults@@@Z
// EA  : 0x82EBB7D8
// RVA : 0x00EBB7D8
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

int __fastcall idWeapon::GetDeferredFireResults(idWeapon *this, idFireParms *fp, idTestFireResults *tfr)
{
  return idDeferredFireManager::GetFireQuery(this: &clientGame->deferredFireManager, handle: this->fireHandle, fp, tfr);
}


// ========================================================================
// ?AddFireDelay@idWeapon@@QAAXH@Z
// EA  : 0x82EBB800
// RVA : 0x00EBB800
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __fastcall idWeapon::AddFireDelay(idWeapon *this, const int delayMS)
{
  this->nextFireTime += delayMS;
}


// ========================================================================
// ?IsFullyLoaded@idWeapon@@QBA_N_N@Z
// EA  : 0x82EBB810
// RVA : 0x00EBB810
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

int __fastcall idWeapon::IsFullyLoaded(idWeapon *this, bool secondaryAmmo)
{
  const idDeclInventory *decl; // r11
  int result; // r3
  idAmmoItem *v6; // r11
  const idDeclAmmo *v7; // r29
  idAmmoItem *v8; // r3
  int v9; // r30
  bool v10; // zf

  decl = this->decl;
  if ( decl == nullptr )
    return 0;
  if ( decl[1].declSource == nullptr )
    return 1;
  v6 = secondaryAmmo ? this->ammoClipSecondary : this->ammoClip;
  if ( v6 == nullptr )
    return 0;
  v7 = (const idDeclAmmo *)v6->decl;
  if ( v7 == nullptr )
    return 0;
  v8 = secondaryAmmo ? this->ammoClipSecondary : this->ammoClip;
  v9 = v8 != nullptr ? v8->GetCount(this: v8) : 0;
  v10 = v9 == idDeclWeapon::GetClipSize(
                this: (idDeclWeapon *)this->decl,
                ammoDecl: v7,
                weaponUpgraded: (*((_BYTE *)this + 452) & 4) != 0,
                secondary: secondaryAmmo);
  result = 1;
  if ( !v10 )
    return 0;
  return result;
}


// ========================================================================
// ?AmmoInClipPercentage@idWeapon@@UBAM_N@Z
// EA  : 0x82EBB8E0
// RVA : 0x00EBB8E0
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

float __fastcall idWeapon::AmmoInClipPercentage(
        idWeapon *this,
        bool secondaryAmmo,
        int a3,
        int a4,
        int a5,
        int a6,
        __int64 a7)
{
  const idDeclInventory *decl; // r11
  double v10; // fp1
  idAmmoItem *v11; // r11
  const idDeclAmmo *v12; // r30
  idAmmoItem *ammoClipSecondary; // r3
  __int64 v14; // r9
  __int64 v16; // [sp+50h] [-30h]

  decl = this->decl;
  if ( decl != nullptr )
  {
    if ( decl[1].declSource == nullptr )
    {
      v10 = 1.0;
      return *((float *)&v10 + 1);
    }
    v11 = secondaryAmmo ? this->ammoClipSecondary : this->ammoClip;
    if ( v11 != nullptr )
    {
      v12 = (const idDeclAmmo *)v11->decl;
      if ( v12 != nullptr )
      {
        if ( secondaryAmmo )
          ammoClipSecondary = this->ammoClipSecondary;
        else
          ammoClipSecondary = this->ammoClip;
        if ( ammoClipSecondary != nullptr )
          ammoClipSecondary = (idAmmoItem *)ammoClipSecondary->GetCount(this: ammoClipSecondary);
        LODWORD(a7) = ammoClipSecondary;
        v16 = a7;
        LODWORD(v14) = idDeclWeapon::GetClipSize(
                         this: (idDeclWeapon *)this->decl,
                         ammoDecl: v12,
                         weaponUpgraded: (*((_BYTE *)this + 452) & 4) != 0,
                         secondary: secondaryAmmo);
        v10 = (float)((float)v16 / (float)v14);
        return *((float *)&v10 + 1);
      }
    }
  }
  v10 = 0.0;
  return *((float *)&v10 + 1);
}


// ========================================================================
// ?CanReload@idWeapon@@QBA_NPBVidInventoryCollection@@PBVidDeclAmmo@@_N@Z
// EA  : 0x82EBB9D0
// RVA : 0x00EBB9D0
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

int __fastcall idWeapon::CanReload(
        idWeapon *this,
        idJobManager *inventory,
        const idDeclJob *ammoDecl,
        bool secondaryAmmo)
{
  const idDeclInventory *decl; // r29
  idAmmoItem *v7; // r11
  int result; // r3
  idAmmoItem *JobByDecl; // r3
  idAmmoItem *v10; // r3
  bool v11; // zf

  decl = this->decl;
  if ( decl[1].declSource == nullptr )
    return 0;
  v7 = secondaryAmmo ? this->ammoClipSecondary : this->ammoClip;
  if ( v7 != nullptr
    && (const idDeclJob *)v7->decl == ammoDecl
    && (unsigned __int8)idWeapon::IsFullyLoaded(this, secondaryAmmo) != 0 )
  {
    return 0;
  }
  if ( inventory == nullptr )
    return 1;
  JobByDecl = (idAmmoItem *)idJobManager::FindJobByDecl(this: inventory, jobDecl: ammoDecl);
  v10 = idAmmoItem::CastTo(c: JobByDecl);
  if ( v10 == nullptr )
    return 0;
  v11 = v10->GetCount(this: v10) >= (int)decl[1].declSource;
  result = 1;
  if ( !v11 )
    return 0;
  return result;
}


// ========================================================================
// ?CanReload@idWeapon@@QBA_NPBVidInventoryCollection@@_N@Z
// EA  : 0x82EBBA90
// RVA : 0x00EBBA90
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

int __fastcall idWeapon::CanReload(idWeapon *this, idJobManager *inventory, bool secondaryAmmo)
{
  idAmmoItem *ammoClipSecondary; // r11
  const idDeclJob *decl; // r11

  if ( secondaryAmmo )
    ammoClipSecondary = this->ammoClipSecondary;
  else
    ammoClipSecondary = this->ammoClip;
  if ( ammoClipSecondary != nullptr )
    decl = (const idDeclJob *)ammoClipSecondary->decl;
  else
    decl = nullptr;
  return idWeapon::CanReload(this, inventory, ammoDecl: decl, secondaryAmmo);
}


// ========================================================================
// ?MultipleReloads@idWeapon@@QBA_NPBVidDeclAmmo@@_N@Z
// EA  : 0x82EBBAC8
// RVA : 0x00EBBAC8
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

int __fastcall idWeapon::MultipleReloads(idWeapon *this, const idDeclAmmo *ammoDecl, bool secondaryAmmo)
{
  const idDeclAmmo *nextAmmo; // r30
  int result; // r3
  idDeclWeapon *decl; // r28
  int ClipSize; // r3
  bool v9; // zf

  nextAmmo = ammoDecl;
  if ( ammoDecl != nullptr || (nextAmmo = this->nextAmmo) != nullptr )
  {
    if ( idDeclWeapon::GetAmmoPerReload(
           this: (idDeclWeapon *)this->decl,
           ammoDecl: nextAmmo,
           weaponUpgraded: (*((_BYTE *)this + 452) & 4) != 0,
           secondary: secondaryAmmo) <= 0 )
      return 0;
    decl = (idDeclWeapon *)this->decl;
    ClipSize = idDeclWeapon::GetClipSize(
                 this: decl,
                 ammoDecl: nextAmmo,
                 weaponUpgraded: (*((_BYTE *)this + 452) & 4) != 0,
                 secondary: secondaryAmmo);
    v9 = idDeclWeapon::GetAmmoPerReload(
           this: decl,
           ammoDecl: nextAmmo,
           weaponUpgraded: (*((_BYTE *)this + 452) & 4) != 0,
           secondary: secondaryAmmo) < ClipSize;
    result = 1;
    if ( !v9 )
      return 0;
  }
  else
  {
    idLib::Warning(fmt: "No ammoDecl to test against in idWeapon::MultipleReloads");
    return 0;
  }
  return result;
}


// ========================================================================
// ?MaxRange@idWeapon@@QBAH_N@Z
// EA  : 0x82EBBB80
// RVA : 0x00EBBB80
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void (__fastcall *__fastcall idWeapon::MaxRange(idWeapon *this, bool secondaryAmmo))(struct idDeclInventory *this)
{
  idAmmoItem *ammoClipSecondary; // r11

  if ( secondaryAmmo )
    ammoClipSecondary = this->ammoClipSecondary;
  else
    ammoClipSecondary = this->ammoClip;
  if ( ammoClipSecondary != nullptr )
    return ammoClipSecondary->decl[1].__vftable[7].Print;
  else
    return nullptr;
}


// ========================================================================
// ?GetFiringInterval@idWeapon@@QBAH_N@Z
// EA  : 0x82EBBBB8
// RVA : 0x00EBBBB8
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

int __fastcall idWeapon::GetFiringInterval(idWeapon *this, bool secondaryAmmo)
{
  int v2; // r9
  signed int v3; // r11
  unsigned int seed; // r8
  signed int v5; // r9
  idAmmoItem *ammoClipSecondary; // r11
  idAmmoItem *ammoClip; // r11
  int burstMode; // r11
  const idDeclInventory *decl; // r11
  int v10; // r8
  int v11; // r10

  v2 = 0;
  v3 = *(_DWORD *)&this->decl[1].inventoryClass.baseBuffer[16];
  if ( v3 > 0 )
  {
    seed = clientGame->random.seed;
    __twllei(v3, 0);
    clientGame->random.seed = 1664525 * seed + 1013904223;
    v5 = ((1664525 * seed + 1013904223) >> 10) & 0x7FFF;
    __twlgei(v3 & ~(__ROL4__(v5, 1) - 1), 0xFFFFFFFF);
    v2 = v5 % v3;
  }
  if ( secondaryAmmo )
    ammoClipSecondary = this->ammoClipSecondary;
  else
    ammoClipSecondary = this->ammoClip;
  if ( ammoClipSecondary != nullptr )
    v2 += ammoClipSecondary->decl[1].textLength;
  if ( secondaryAmmo )
    ammoClip = this->ammoClipSecondary;
  else
    ammoClip = this->ammoClip;
  if ( ammoClip != nullptr )
    burstMode = ammoClip->burstMode;
  else
    burstMode = this->decl[1].attachmentInfo.num;
  if ( burstMode == 1 )
    burstMode = this->burstCount != 1;
  v10 = 4 * (burstMode + 471);
  decl = this->decl;
  v11 = *(int *)((char *)&decl->__vftable + v10);
  if ( v11 <= 0 )
    return *(_DWORD *)&decl[3].useRaceCertificates + v2;
  else
    return v11 + v2;
}


// ========================================================================
// ?UpdateRibbon@idWeapon@@QAAXXZ
// EA  : 0x82EBBCD0
// RVA : 0x00EBBCD0
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __fastcall idWeapon::UpdateRibbon(idWeapon *this)
{
  const idDeclInventory *decl; // r29

  if ( this->ribbonStartTime > 0 )
  {
    decl = this->decl;
    if ( decl[3].numHands + this->ribbonStartTime > idGameTimeManager::GetGameMs(
                                                      this: &clientGame->gameTimeManager,
                                                      type: GAMETIME_SCALED)
      && g_weaponShowRibbon.valueInteger != 0 )
    {
      clientGame->renderWorld->DebugLine(
        this: clientGame->renderWorld,
        a2: (const idVec4 *)&idColor::colorRed,
        a3: &this->ribbonStart,
        a4: &this->ribbonEnd,
        a5: 0,
        a6: false);
    }
  }
}


// ========================================================================
// ?AttackerHasQuad@idWeapon@@ABA_NPAVidPresentable@@@Z
// EA  : 0x82EBBD68
// RVA : 0x00EBBD68
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

BOOL __fastcall idWeapon::AttackerHasQuad(idWeapon *this, idPresentable *attacker)
{
  idPresentablePlayer *PlayerDriver; // r30
  idPresentableVehicle *v4; // r3
  idPresentableVehicle *v5; // r31

  if ( attacker == nullptr )
    return false;
  PlayerDriver = attacker->GetPlayerInterface_2(this: attacker);
  v4 = attacker->GetVehicleInterface(this: attacker);
  v5 = v4;
  if ( PlayerDriver != nullptr )
    goto LABEL_5;
  if ( v4 == nullptr )
    return false;
  PlayerDriver = idPresentableVehicle::GetPlayerDriver(this: v4);
  if ( PlayerDriver != nullptr )
  {
LABEL_5:
    if ( (*((_BYTE *)PlayerDriver + 47032) & 2) != 0 )
      return true;
  }
  return v5 != nullptr && v5->hasQuad;
}


// ========================================================================
// ?GetAmmoDeclIndex@idWeapon@@QBAHPBVidDeclAmmo@@_N@Z
// EA  : 0x82EBBE28
// RVA : 0x00EBBE28
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

int __fastcall idWeapon::GetAmmoDeclIndex(idWeapon *this, const idDeclAmmo *ammo, bool secondaryAmmo)
{
  const idDeclInventory *decl; // r11
  int *p_networkID; // r11
  int v5; // r9
  int result; // r3
  int v7; // r10
  int i; // r11

  decl = this->decl;
  if ( secondaryAmmo )
    p_networkID = &decl[1].networkID;
  else
    p_networkID = (int *)&decl[1].name;
  v5 = p_networkID[1];
  result = 0;
  if ( v5 <= 0 )
    return -1;
  v7 = *p_networkID;
  for ( i = 0; ammo != *(const idDeclAmmo **)(i + v7); i += 28 )
  {
    if ( ++result >= v5 )
      return -1;
  }
  return result;
}


// ========================================================================
// ?ToggleWeaponMode@idWeapon@@QAAXXZ
// EA  : 0x82EBBE80
// RVA : 0x00EBBE80
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __fastcall idWeapon::ToggleWeaponMode(idWeapon *this)
{
  idWeapon::weaponState_t weaponState; // r11
  idAmmoItem *ammoClipSecondary; // r10
  int index; // r11

  weaponState = this->weaponState;
  if ( weaponState == WEAPONSTATE_SECONDARY )
    ammoClipSecondary = this->ammoClipSecondary;
  else
    ammoClipSecondary = this->ammoClip;
  if ( ammoClipSecondary != nullptr )
  {
    this->weaponState = weaponState != WEAPONSTATE_SECONDARY;
    index = ammoClipSecondary->decl[1].requiredName.index;
    if ( index == 3 )
      index = this->decl[1].attachmentInfo.num;
    ammoClipSecondary->burstMode = index;
  }
}


// ========================================================================
// ?CanToggleWeaponMode@idWeapon@@QBA_NXZ
// EA  : 0x82EBBED0
// RVA : 0x00EBBED0
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

BOOL __fastcall idWeapon::CanToggleWeaponMode(idWeapon *this)
{
  idWeapon::weaponState_t weaponState; // r11

  if ( (*((_BYTE *)this + 453) & 0x40) == 0 )
    return false;
  weaponState = this->weaponState;
  return weaponState == WEAPONSTATE_NORMAL && this->ammoClipSecondary != nullptr
      || weaponState == WEAPONSTATE_SECONDARY && this->ammoClip != nullptr;
}


// ========================================================================
// ?GetZoomedFOV@idWeapon@@QBAMXZ
// EA  : 0x82EBBF30
// RVA : 0x00EBBF30
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

float __fastcall idWeapon::GetZoomedFOV(idWeapon *this)
{
  const idDeclInventory *decl; // r11
  double v2; // fp1

  decl = this->decl;
  if ( (*((_BYTE *)this + 452) & 0x10) != 0 )
    v2 = *((float *)&decl[2].engineerableItems.list->len + 13 * this->currentZoomLevel);
  else
    v2 = *(float *)&decl[2].itemUse;
  return *((float *)&v2 + 1);
}


// ========================================================================
// ?GetIronSightsOffset@idWeapon@@QBAABVidVec3@@XZ
// EA  : 0x82EBBF60
// RVA : 0x00EBBF60
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

const idVec3 *__fastcall idWeapon::GetIronSightsOffset(idWeapon *this)
{
  const idDeclInventory *decl; // r11

  decl = this->decl;
  if ( (*((_BYTE *)this + 452) & 0x10) != 0 )
    return (const idVec3 *)(&decl[2].engineerableItems.list[1].allocedAndFlag + 13 * this->currentZoomLevel);
  else
    return (const idVec3 *)&decl[2].giveItemsOnRecieveWithCount.num;
}


// ========================================================================
// ?HideHandsOnZoom@idWeapon@@QBA_NXZ
// EA  : 0x82EBBF98
// RVA : 0x00EBBF98
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

int __fastcall idWeapon::HideHandsOnZoom(idWeapon *this)
{
  const idDeclInventory *decl; // r11

  decl = this->decl;
  if ( (*((_BYTE *)this + 452) & 0x10) != 0 )
    return (unsigned __int8)decl[2].engineerableItems.list->baseBuffer[52 * this->currentZoomLevel + 16];
  else
    return HIBYTE(decl[2].giveItemsOnReceive.size);
}


// ========================================================================
// ?GetZoomTime@idWeapon@@QBAHXZ
// EA  : 0x82EBBFD0
// RVA : 0x00EBBFD0
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

const idDeclInventory **__fastcall idWeapon::GetZoomTime(idWeapon *this)
{
  const idDeclInventory *decl; // r11

  decl = this->decl;
  if ( (*((_BYTE *)this + 452) & 0x10) != 0 )
    return *(const idDeclInventory ***)&decl[2].engineerableItems.list->baseBuffer[52 * this->currentZoomLevel + 8];
  else
    return decl[2].giveItemsOnReceive.list;
}


// ========================================================================
// ?SetZoomLevel@idWeapon@@QAAXH@Z
// EA  : 0x82EBC008
// RVA : 0x00EBC008
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __fastcall idWeapon::SetZoomLevel(idWeapon *this, int inZoomLevel)
{
  char v3; // r11
  const idDeclInventory *decl; // r11
  bool v5; // zf
  const idDeclInventory **list; // r30
  __int64 v7; // r7

  if ( inZoomLevel != this->currentZoomLevel )
  {
    v3 = *((_BYTE *)this + 452);
    this->currentZoomLevel = inZoomLevel;
    v5 = (v3 & 0x10) == 0;
    decl = this->decl;
    if ( v5 )
      list = decl[2].giveItemsOnReceive.list;
    else
      list = *(const idDeclInventory ***)&decl[2].engineerableItems.list->baseBuffer[52 * inZoomLevel + 8];
    LODWORD(v7) = (char *)list + gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
    this->changeZoomLevelTime = (float)v7;
  }
}


// ========================================================================
// ?GetScopeGuiNum@idWeapon@@QBA?AW4scopeGuiNum_t@idDeclWeapon@@XZ
// EA  : 0x82EBC0B0
// RVA : 0x00EBC0B0
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

idDeclWeapon::scopeGuiNum_t __fastcall idWeapon::GetScopeGuiNum(idWeapon *this)
{
  const idDeclInventory *decl; // r11

  decl = this->decl;
  if ( (*((_BYTE *)this + 452) & 0x10) != 0 )
    return *(&decl[2].engineerableItems.list[1].len + 13 * this->currentZoomLevel);
  else
    return *(_DWORD *)&decl[2].giveItemsOnReceive.granularity;
}


// ========================================================================
// ?GetSensitivityScale@idWeapon@@QAAXAAM0@Z
// EA  : 0x82EBC0E8
// RVA : 0x00EBC0E8
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __fastcall idWeapon::GetSensitivityScale(idWeapon *this, float *mouseSensScale, float *joySensScale)
{
  if ( (*((_BYTE *)this + 452) & 0x10) != 0 )
  {
    *mouseSensScale = *((float *)&this->decl[2].engineerableItems.list->data + 13 * this->currentZoomLevel);
    *joySensScale = *((float *)&this->decl[2].engineerableItems.list->allocedAndFlag + 13 * this->currentZoomLevel);
  }
  *mouseSensScale = *(float *)&this->decl[2].initiallyHidden;
  *joySensScale = *(float *)&this->decl[2].itemGroup;
}


// ========================================================================
// ?GetMovementScale@idWeapon@@QBAMXZ
// EA  : 0x82EBC150
// RVA : 0x00EBC150
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

float __fastcall idWeapon::GetMovementScale(idWeapon *this)
{
  const idDeclInventory *decl; // r11
  double v2; // fp1

  decl = this->decl;
  if ( (*((_BYTE *)this + 452) & 0x10) != 0 )
    v2 = *(float *)&decl[2].engineerableItems.list->baseBuffer[52 * this->currentZoomLevel];
  else
    v2 = *(float *)&decl[2].itemGroupWorth;
  return *((float *)&v2 + 1);
}


// ========================================================================
// ?GetCrouchedScale@idWeapon@@QBAMXZ
// EA  : 0x82EBC188
// RVA : 0x00EBC188
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

float __fastcall idWeapon::GetCrouchedScale(idWeapon *this)
{
  const idDeclInventory *decl; // r11
  double v2; // fp1

  decl = this->decl;
  if ( (*((_BYTE *)this + 452) & 0x10) != 0 )
    v2 = *(float *)&decl[2].engineerableItems.list->baseBuffer[52 * this->currentZoomLevel + 4];
  else
    v2 = *(float *)&decl[2].aimWeaponSettings;
  return *((float *)&v2 + 1);
}


// ========================================================================
// ?GetSpreadReductionWithZoom@idWeapon@@QBAMXZ
// EA  : 0x82EBC1C0
// RVA : 0x00EBC1C0
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

float __fastcall idWeapon::GetSpreadReductionWithZoom(idWeapon *this)
{
  const idDeclInventory *decl; // r11
  double v2; // fp1

  decl = this->decl;
  if ( (*((_BYTE *)this + 452) & 0x10) != 0 )
    v2 = *(float *)&decl[2].engineerableItems.list->baseBuffer[52 * this->currentZoomLevel + 12];
  else
    v2 = *(float *)&decl[2].giveItemsOnReceive.num;
  return *((float *)&v2 + 1);
}


// ========================================================================
// ?GetChainFire@idWeapon@@QBA_NXZ
// EA  : 0x82EBC1F8
// RVA : 0x00EBC1F8
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

BOOL __fastcall idWeapon::GetChainFire(idWeapon *this)
{
  idAmmoItem *ammoClip; // r11

  ammoClip = this->ammoClip;
  return ammoClip != nullptr && ammoClip->decl[1].vehiclePermAttachment;
}


// ========================================================================
// ?GetChargeFire@idWeapon@@QBA_NXZ
// EA  : 0x82EBC218
// RVA : 0x00EBC218
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

BOOL __fastcall idWeapon::GetChargeFire(idWeapon *this)
{
  idAmmoItem *ammoClip; // r11

  ammoClip = this->ammoClip;
  return ammoClip != nullptr && ammoClip->decl[1].vehicleArmor;
}


// ========================================================================
// ?GetLaserFire@idWeapon@@QBA_N_N@Z
// EA  : 0x82EBC238
// RVA : 0x00EBC238
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

int __fastcall idWeapon::GetLaserFire(idWeapon *this, bool secondary)
{
  idAmmoItem *ammoClipSecondary; // r11

  if ( secondary )
    ammoClipSecondary = this->ammoClipSecondary;
  else
    ammoClipSecondary = this->ammoClip;
  if ( ammoClipSecondary != nullptr )
    return *((unsigned __int8 *)&ammoClipSecondary->decl[1].vehicleArmor + 1);
  else
    return 0;
}


// ========================================================================
// ?IsMelee@idWeapon@@QBA_NXZ
// EA  : 0x82EBC270
// RVA : 0x00EBC270
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

int __fastcall idWeapon::IsMelee(idWeapon *this)
{
  idAmmoItem *ammoClip; // r11
  const idDeclInventory *decl; // r11
  idDeclInventory_vtbl *v4; // r11
  unsigned int (__fastcall *Size)(struct idDeclInventory *); // r11

  ammoClip = this->ammoClip;
  if ( ammoClip == nullptr && (_cntlzw(this->weaponState - 1) & 0x20) != 0 )
    ammoClip = this->ammoClipSecondary;
  if ( ammoClip != nullptr
    && (decl = ammoClip->decl) != nullptr
    && (v4 = decl[1].__vftable) != nullptr
    && (Size = v4[6].Size) != nullptr )
  {
    return *((unsigned __int8 *)Size + 154);
  }
  else
  {
    return 0;
  }
}


// ========================================================================
// ?UsesFireControl@idWeapon@@QBA_NXZ
// EA  : 0x82EBC2E0
// RVA : 0x00EBC2E0
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

int __fastcall idWeapon::UsesFireControl(idWeapon *this)
{
  int v1; // r8

  if ( (unsigned __int8)idWeapon::IsMelee(this) != 0 )
    return 0;
  else
    return *(unsigned __int8 *)(*(_DWORD *)(v1 + 12) + 610);
}


// ========================================================================
// ?AddSpreadToFireAxis@idWeapon@@QBAXABVidMat3@@W4aiAccuracy_t@@AAV2@@Z
// EA  : 0x82EBC330
// RVA : 0x00EBC330
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idWeapon::AddSpreadToFireAxis(
        idWeapon *this,
        const idMat3 *inAxis,
        const aiAccuracy_t accuracy,
        idMat3 *outAxis)
{
  int v4; // r2 OVERLAPPED
  __int64 v6; // r7
  double x; // fp13
  float *v8; // r3
  double v9; // fp8
  double v10; // fp7
  unsigned int v11; // r5
  double y; // fp5
  double v13; // fp9
  unsigned int v14; // r9
  unsigned int v15; // r3
  double v16; // fp2
  double v17; // fp1
  double v18; // fp11
  double v20; // fp4
  double v22; // fp2
  double v23; // fp5
  double v24; // fp4
  idMat3 v25[2]; // [sp+58h] [-58h] BYREF

  HIDWORD(v6) = &ai_useTurnTransitions.valueString.baseBuffer[12];
  x = inAxis->mat[0].x;
  v8 = (float *)((char *)this->decl + 32 * accuracy);
  v9 = (float)(inAxis->mat[0].z * (float)1024.0);
  v25[0].mat[0].y = inAxis->mat[0].y * (float)1024.0;
  v25[0].mat[0].z = v9;
  v25[0].mat[0].x = (float)x * (float)1024.0;
  v10 = v8[257];
  v11 = 1664525 * clientGame->random.seed + 1013904223;
  clientGame->random.seed = v11;
  LODWORD(v6) = (v11 >> 10) & 0x7FFF;
  y = inAxis->mat[1].y;
  v13 = (float)(inAxis->mat[1].z
              * (float)((float)((float)((float)((float)v6 * (float)0.000030518509) * (float)v10) * (float)2.0)
                      - (float)v10));
  v25[0].mat[0].x = (float)(inAxis->mat[1].x
                          * (float)((float)((float)((float)((float)v6 * (float)0.000030518509) * (float)v10) * (float)2.0)
                                  - (float)v10))
                  + v25[0].mat[0].x;
  v25[0].mat[0].y = (float)((float)y
                          * (float)((float)((float)((float)((float)v6 * (float)0.000030518509) * (float)v10) * (float)2.0)
                                  - (float)v10))
                  + v25[0].mat[0].y;
  v25[0].mat[0].z = (float)v13 + v25[0].mat[0].z;
  v14 = 1664525 * clientGame->random.seed;
  clientGame->random.seed = v14 + 1013904223;
  v15 = ((v14 + 1013904223) >> 10) & 0x7FFF;
  v16 = (float)(inAxis->mat[2].x
              * (float)((float)((float)((float)((float)*(__int64 *)(&v4 - 1) * (float)0.000030518509) * (float)v10)
                              * (float)2.0)
                      - (float)v10));
  v17 = (float)((float)(inAxis->mat[2].y
                      * (float)((float)((float)((float)((float)*(__int64 *)(&v4 - 1) * (float)0.000030518509)
                                              * (float)v10)
                                      * (float)2.0)
                              - (float)v10))
              + v25[0].mat[0].y);
  v18 = (float)((float)(inAxis->mat[2].z
                      * (float)((float)((float)((float)((float)*(__int64 *)(&v4 - 1) * (float)0.000030518509)
                                              * (float)v10)
                                      * (float)2.0)
                              - (float)v10))
              + v25[0].mat[0].z);
  _FP5 = (float)((float)((float)((float)((float)v16 + v25[0].mat[0].x) * (float)((float)v16 + v25[0].mat[0].x))
                       + (float)((float)((float)v18 * (float)v18) + (float)((float)v17 * (float)v17)))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  v20 = (float)((float)((float)((float)((float)v16 + v25[0].mat[0].x) * (float)((float)v16 + v25[0].mat[0].x))
                      + (float)((float)((float)v18 * (float)v18) + (float)((float)v17 * (float)v17)))
              * (float)0.5);
  __asm { fsel      f3, f5, f6, f12 }
  v22 = __frsqrte(_FP3);
  v23 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v22 * (float)v20)
                                                                              * (float)v22)
                                                                      - (float)1.5)
                                                      * (float)v22)
                                              * (float)v20)
                                      * (float)((float)-(float)((float)((float)((float)v22 * (float)v20) * (float)v22)
                                                              - (float)1.5)
                                              * (float)v22))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v22 * (float)v20) * (float)v22) - (float)1.5) * (float)v22));
  v24 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v22 * (float)v20)
                                                                                      * (float)v22)
                                                                              - (float)1.5)
                                                              * (float)v22)
                                                      * (float)v20)
                                              * (float)((float)-(float)((float)((float)((float)v22 * (float)v20)
                                                                              * (float)v22)
                                                                      - (float)1.5)
                                                      * (float)v22))
                                      - (float)1.5)
                      * (float)((float)-(float)((float)((float)((float)v22 * (float)v20) * (float)v22) - (float)1.5)
                              * (float)v22))
              * (float)v20);
  v25[0].mat[0].x = (float)((float)-(float)((float)((float)v24 * (float)v23) - (float)1.5) * (float)v23)
                  * (float)((float)(inAxis->mat[2].x
                                  * (float)((float)((float)((float)((float)*(__int64 *)(&v4 - 1) * (float)0.000030518509)
                                                          * (float)v10)
                                                  * (float)2.0)
                                          - (float)v10))
                          + v25[0].mat[0].x);
  v25[0].mat[0].y = (float)((float)-(float)((float)((float)v24 * (float)v23) - (float)1.5) * (float)v23) * (float)v17;
  v25[0].mat[0].z = (float)v18 * (float)((float)-(float)((float)((float)v24 * (float)v23) - (float)1.5) * (float)v23);
  *outAxis = *idVec3::ToMat3(this: &v25[0].mat[2], result: v25);
}


// ========================================================================
// ?IsReadyToFire@idWeapon@@QAA_NXZ
// EA  : 0x82EBC560
// RVA : 0x00EBC560
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

BOOL __fastcall idWeapon::IsReadyToFire(idWeapon *this)
{
  return idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) >= this->nextFireTime;
}


// ========================================================================
// ?SpeedBarrelSpinUp@idWeapon@@QAAXXZ
// EA  : 0x82EBC5B8
// RVA : 0x00EBC5B8
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __fastcall idWeapon::SpeedBarrelSpinUp(idWeapon *this)
{
  int GameMs; // r29
  __int64 v3; // r8
  int PreviousGameMs; // r3
  BOOL fullSpinThrottle; // r11
  double v6; // fp0
  float *decl; // r10
  double v8; // fp0

  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  PreviousGameMs = idGameTimeManager::GetPreviousGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  fullSpinThrottle = this->fullSpinThrottle;
  if ( this->fullSpinThrottle )
    v6 = 1.5;
  else
    v6 = 1.0;
  decl = (float *)this->decl;
  LODWORD(v3) = GameMs - PreviousGameMs;
  v8 = (float)((float)((float)(decl[424] * (float)v6) * (float)((float)v3 * (float)0.001)) + this->barrelSpinSpeed);
  this->barrelSpinSpeed = v8;
  if ( fullSpinThrottle )
  {
    if ( decl[422] < v8 )
      this->barrelSpinSpeed = decl[422];
  }
  else if ( decl[423] < v8 )
  {
    this->barrelSpinSpeed = decl[422];
  }
}


// ========================================================================
// ?SlowBarrelSpinDown@idWeapon@@QAAXXZ
// EA  : 0x82EBC690
// RVA : 0x00EBC690
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __fastcall idWeapon::SlowBarrelSpinDown(idWeapon *this)
{
  int GameMs; // r29
  int PreviousGameMs; // r3
  const idDeclInventory *decl; // r9
  __int64 v5; // r7
  double v6; // fp5

  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  PreviousGameMs = idGameTimeManager::GetPreviousGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  decl = this->decl;
  LODWORD(v5) = GameMs - PreviousGameMs;
  HIDWORD(v5) = &off_82040000;
  v6 = (float)-(float)((float)((float)(*(float *)&decl[3].internalName.baseBuffer[4] * (float)0.5)
                             * (float)((float)v5 * (float)0.001))
                     - this->barrelSpinSpeed);
  this->barrelSpinSpeed = -(float)((float)((float)(*(float *)&decl[3].internalName.baseBuffer[4] * (float)0.5)
                                         * (float)((float)v5 * (float)0.001))
                                 - this->barrelSpinSpeed);
  if ( v6 < 0.0 )
    this->barrelSpinSpeed = 0.0;
}


// ========================================================================
// ?GetAttackVariation@idWeapon@@QAAHH@Z
// EA  : 0x82EBC730
// RVA : 0x00EBC730
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

int __fastcall idWeapon::GetAttackVariation(idWeapon *this, int slot)
{
  const idDeclInventory *decl; // r7
  int v3; // r6
  int v4; // r11
  int result; // r3

  decl = this->decl;
  v3 = 0;
  v4 = 0;
  do
  {
    result = v4 % 3;
    if ( *((_BYTE *)&decl[2].maxCount + v4 % 3) != 0 )
    {
      if ( slot == v3 )
        return result;
      ++v3;
    }
    ++v4;
  }
  while ( (v4 != 3 || v3 != 0) && v3 < 3 );
  return 0;
}


// ========================================================================
// ?ForceReplaceAmmo@idWeapon@@QAAXPBVidDeclAmmo@@_N@Z
// EA  : 0x82EBC7A0
// RVA : 0x00EBC7A0
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __fastcall idWeapon::ForceReplaceAmmo(idWeapon *this, const idDeclAmmo *newAmmoDecl, bool secondaryAmmo)
{
  idAmmoItem **p_ammoClipSecondary; // r31
  const idDeclAmmo **v5; // r3
  idAmmoItem *v6; // r3

  p_ammoClipSecondary = &this->ammoClipSecondary;
  if ( !secondaryAmmo )
    p_ammoClipSecondary = &this->ammoClip;
  v5 = (const idDeclAmmo **)*p_ammoClipSecondary;
  if ( *p_ammoClipSecondary != nullptr )
  {
    if ( v5[3] == newAmmoDecl )
      return;
    ((void (__fastcall *)(const idDeclAmmo **, int))(*v5)->trackedMemory)(a1: v5, a2: 1);
  }
  v6 = (idAmmoItem *)idInventoryItem::Create(decl: newAmmoDecl);
  *p_ammoClipSecondary = idAmmoItem::CastTo(c: v6);
}


// ========================================================================
// ?Init@idLaserCutter@@UAAXPBVidDeclInventory@@@Z
// EA  : 0x82EBC820
// RVA : 0x00EBC820
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __fastcall idLaserCutter::Init(idLaserCutter *this, const idDeclInventory *decl)
{
  const idDeclInventory *v3; // r31
  idRenderModelBeam *v4; // r3
  idClientGame *v5; // r11
  idRenderModelBeam *v6; // r3
  idRenderModelDecal *v7; // r3
  idClientGame *v8; // r11
  idRenderModelDecal *v9; // r3
  idRenderModelDecal *decalModelFPView; // r5
  idRenderModelBeam *beamModelFPView; // r4
  const idMaterial *list; // r7
  int v13; // r10
  int v14; // r9
  int v15; // r9
  const idMaterial *v16; // r7
  int v17; // r10
  const idMaterial *v18; // r7
  int v19; // r10
  int v20; // r9
  int v21; // r10
  int v22; // r9
  const idMaterial *v23; // r7
  int v24; // r9
  const idMaterial *v25; // r7
  int v26; // [sp+8h] [-B8h]
  int v27; // [sp+8h] [-B8h]
  int v28; // [sp+8h] [-B8h]
  int v29; // [sp+8h] [-B8h]
  int v30; // [sp+8h] [-B8h]
  int v31; // [sp+8h] [-B8h]
  int v32; // [sp+Ch] [-B4h]
  int v33; // [sp+Ch] [-B4h]
  int v34; // [sp+Ch] [-B4h]
  int v35; // [sp+Ch] [-B4h]
  int v36; // [sp+Ch] [-B4h]
  int v37; // [sp+Ch] [-B4h]
  int v38; // [sp+10h] [-B0h]
  int v39; // [sp+10h] [-B0h]
  int v40; // [sp+10h] [-B0h]
  int v41; // [sp+10h] [-B0h]
  int v42; // [sp+10h] [-B0h]
  int v43; // [sp+10h] [-B0h]
  int v44; // [sp+14h] [-ACh]
  int v45; // [sp+14h] [-ACh]
  int v46; // [sp+14h] [-ACh]
  int v47; // [sp+14h] [-ACh]
  int v48; // [sp+14h] [-ACh]
  int v49; // [sp+14h] [-ACh]
  int v50; // [sp+18h] [-A8h]
  int v51; // [sp+18h] [-A8h]
  int v52; // [sp+18h] [-A8h]
  int v53; // [sp+18h] [-A8h]
  int v54; // [sp+18h] [-A8h]
  int v55; // [sp+18h] [-A8h]
  int v56; // [sp+1Ch] [-A4h]
  int v57; // [sp+1Ch] [-A4h]
  int v58; // [sp+1Ch] [-A4h]
  int v59; // [sp+1Ch] [-A4h]
  int v60; // [sp+1Ch] [-A4h]
  int v61; // [sp+1Ch] [-A4h]
  int v62; // [sp+20h] [-A0h]
  int v63; // [sp+20h] [-A0h]
  int v64; // [sp+20h] [-A0h]
  int v65; // [sp+20h] [-A0h]
  int v66; // [sp+20h] [-A0h]
  int v67; // [sp+20h] [-A0h]
  int v68; // [sp+24h] [-9Ch]
  int v69; // [sp+24h] [-9Ch]
  int v70; // [sp+24h] [-9Ch]
  int v71; // [sp+24h] [-9Ch]
  int v72; // [sp+24h] [-9Ch]
  int v73; // [sp+24h] [-9Ch]
  int v74; // [sp+28h] [-98h]
  int v75; // [sp+28h] [-98h]
  int v76; // [sp+28h] [-98h]
  int v77; // [sp+28h] [-98h]
  int v78; // [sp+28h] [-98h]
  int v79; // [sp+28h] [-98h]
  int v80; // [sp+2Ch] [-94h]
  int v81; // [sp+2Ch] [-94h]
  int v82; // [sp+2Ch] [-94h]
  int v83; // [sp+2Ch] [-94h]
  int v84; // [sp+2Ch] [-94h]
  int v85; // [sp+2Ch] [-94h]
  int v86; // [sp+30h] [-90h]
  int v87; // [sp+30h] [-90h]
  int v88; // [sp+30h] [-90h]
  int v89; // [sp+30h] [-90h]
  int v90; // [sp+30h] [-90h]
  int v91; // [sp+30h] [-90h]
  int v92; // [sp+34h] [-8Ch]
  int v93; // [sp+34h] [-8Ch]
  int v94; // [sp+34h] [-8Ch]
  int v95; // [sp+34h] [-8Ch]
  int v96; // [sp+34h] [-8Ch]
  int v97; // [sp+34h] [-8Ch]
  int v98; // [sp+38h] [-88h]
  int v99; // [sp+38h] [-88h]
  int v100; // [sp+38h] [-88h]
  int v101; // [sp+38h] [-88h]
  int v102; // [sp+38h] [-88h]
  int v103; // [sp+38h] [-88h]
  int v104; // [sp+3Ch] [-84h]
  int v105; // [sp+3Ch] [-84h]
  int v106; // [sp+3Ch] [-84h]
  int v107; // [sp+3Ch] [-84h]
  int v108; // [sp+3Ch] [-84h]
  int v109; // [sp+3Ch] [-84h]
  int v110; // [sp+40h] [-80h]
  int v111; // [sp+40h] [-80h]
  int v112; // [sp+40h] [-80h]
  int v113; // [sp+40h] [-80h]
  int v114; // [sp+40h] [-80h]
  int v115; // [sp+40h] [-80h]
  int v116; // [sp+44h] [-7Ch]
  int v117; // [sp+44h] [-7Ch]
  int v118; // [sp+44h] [-7Ch]
  int v119; // [sp+44h] [-7Ch]
  int v120; // [sp+44h] [-7Ch]
  int v121; // [sp+44h] [-7Ch]
  int v122; // [sp+48h] [-78h]
  int v123; // [sp+48h] [-78h]
  int v124; // [sp+48h] [-78h]
  int v125; // [sp+48h] [-78h]
  int v126; // [sp+48h] [-78h]
  int v127; // [sp+48h] [-78h]
  int v128; // [sp+4Ch] [-74h]
  int v129; // [sp+4Ch] [-74h]
  int v130; // [sp+4Ch] [-74h]
  int v131; // [sp+4Ch] [-74h]
  int v132; // [sp+4Ch] [-74h]
  int v133; // [sp+4Ch] [-74h]
  int v134; // [sp+50h] [-70h]
  int v135; // [sp+50h] [-70h]
  int v136; // [sp+50h] [-70h]
  int v137; // [sp+50h] [-70h]
  int v138; // [sp+50h] [-70h]
  int v139; // [sp+50h] [-70h]
  int v140; // [sp+54h] [-6Ch]
  int v141; // [sp+54h] [-6Ch]
  int v142; // [sp+54h] [-6Ch]
  int v143; // [sp+54h] [-6Ch]
  int v144; // [sp+54h] [-6Ch]
  int v145; // [sp+54h] [-6Ch]
  int v146; // [sp+58h] [-68h]
  int v147; // [sp+58h] [-68h]
  int v148; // [sp+58h] [-68h]
  int v149; // [sp+58h] [-68h]
  int v150; // [sp+58h] [-68h]
  int v151; // [sp+58h] [-68h]
  int v152; // [sp+5Ch] [-64h]
  int v153; // [sp+5Ch] [-64h]
  int v154; // [sp+5Ch] [-64h]
  int v155; // [sp+5Ch] [-64h]
  int v156; // [sp+5Ch] [-64h]
  int v157; // [sp+5Ch] [-64h]
  int v158; // [sp+60h] [-60h]
  int v159; // [sp+60h] [-60h]
  int v160; // [sp+60h] [-60h]
  int v161; // [sp+60h] [-60h]
  int v162; // [sp+60h] [-60h]
  int v163; // [sp+60h] [-60h]

  idWeapon::Init(this, decl);
  v3 = this->decl;
  v4 = (idRenderModelBeam *)clientGame->renderWorld->AllocRenderModel(
                              this: clientGame->renderWorld,
                              a2: "_beam",
                              a3: 1,
                              a4: -1);
  this->beamModelFPView = v4;
  idRenderModel::CommitThisFrame(this: v4);
  v5 = clientGame;
  this->beamModelFPView->g.modelDepthHack = 0.1;
  v6 = (idRenderModelBeam *)v5->renderWorld->AllocRenderModel(this: v5->renderWorld, a2: "_beam", a3: true, a4: -1);
  this->beamModelWorldView = v6;
  idRenderModel::CommitThisFrame(this: v6);
  v7 = (idRenderModelDecal *)clientGame->renderWorld->AllocRenderModel(
                               this: clientGame->renderWorld,
                               a2: "_decal",
                               a3: 1,
                               a4: -1);
  this->decalModelFPView = v7;
  idRenderModel::CommitThisFrame(this: v7);
  v8 = clientGame;
  this->decalModelFPView->g.modelDepthHack = 0.1;
  v9 = (idRenderModelDecal *)v8->renderWorld->AllocRenderModel(this: v8->renderWorld, a2: "_decal", a3: true, a4: -1);
  this->decalModelworldView = v9;
  idRenderModel::CommitThisFrame(this: v9);
  decalModelFPView = this->decalModelFPView;
  beamModelFPView = this->beamModelFPView;
  this->maxBattery = (int)v3[4].customMaterial;
  list = (const idMaterial *)v3[4].attachmentInfo.list;
  this->batteryCount = (int)list;
  idLaserSight::Init(
    this: &this->laserBeamCut,
    _beamEffects: beamModelFPView,
    _decalEffects: decalModelFPView,
    laserBeamMtr: (const idMaterial *)v3[3].scriptUse.__vftable,
    laserBeamHeight: *(float *)&v3[3].scriptUse.data,
    laserPointMtr: list,
    laserPointSize: *(float *)&v3[3].isContainer,
    laserPointDepth: *(float *)&v3[3].containerDecl,
    fadeIn: *(float *)&v3[3].dropSound,
    fadeOut: *(float *)&v3[3].hoverSound,
    isQuad: (const idMaterial *)v3[3].scriptUse.type,
    a12: v14,
    a13: v13,
    a14: v26,
    a15: v32,
    a16: v38,
    a17: v44,
    a18: v50,
    a19: v56,
    a20: v62,
    a21: v68,
    a22: v74,
    a23: v80,
    a24: v86,
    a25: v92,
    a26: v98,
    a27: v104,
    a28: v110,
    a29: v116,
    a30: v122,
    a31: v128,
    a32: v134,
    a33: v140,
    a34: v146,
    a35: v152,
    a36: v158,
    a37: HIBYTE(v3[3].useSound));
  idLaserSight::Init(
    this: &this->laserBeamCutBounce,
    _beamEffects: this->beamModelWorldView,
    _decalEffects: this->decalModelworldView,
    laserBeamMtr: (const idMaterial *)v3[3].scriptUse.__vftable,
    laserBeamHeight: *(float *)&v3[3].scriptUse.data,
    laserPointMtr: v16,
    laserPointSize: *(float *)&v3[3].isContainer,
    laserPointDepth: *(float *)&v3[3].containerDecl,
    fadeIn: *(float *)&v3[3].dropSound,
    fadeOut: *(float *)&v3[3].hoverSound,
    isQuad: (const idMaterial *)v3[3].scriptUse.type,
    a12: v15,
    a13: HIBYTE(v3[3].useSound),
    a14: v27,
    a15: v33,
    a16: v39,
    a17: v45,
    a18: v51,
    a19: v57,
    a20: v63,
    a21: v69,
    a22: v75,
    a23: v81,
    a24: v87,
    a25: v93,
    a26: v99,
    a27: v105,
    a28: v111,
    a29: v117,
    a30: v123,
    a31: v129,
    a32: v135,
    a33: v141,
    a34: v147,
    a35: v153,
    a36: v159,
    a37: HIBYTE(v3[3].useSound));
  idLaserSight::Init(
    this: &this->laserBeamShoot,
    _beamEffects: this->beamModelFPView,
    _decalEffects: this->decalModelFPView,
    laserBeamMtr: (const idMaterial *)v3[3].dropEventDecl,
    laserBeamHeight: *(float *)&v3[3].initiallyHidden,
    laserPointMtr: v18,
    laserPointSize: *(float *)&v3[3].itemGroup,
    laserPointDepth: *(float *)&v3[3].itemGroupWorth,
    fadeIn: *(float *)&v3[3].giveItemsOnReceive.size,
    fadeOut: *(float *)&v3[3].giveItemsOnReceive.granularity,
    isQuad: (const idMaterial *)v3[3].itemUse,
    a12: HIBYTE(v3[3].giveItemsOnReceive.num),
    a13: v17,
    a14: v28,
    a15: v34,
    a16: v40,
    a17: v46,
    a18: v52,
    a19: v58,
    a20: v64,
    a21: v70,
    a22: v76,
    a23: v82,
    a24: v88,
    a25: v94,
    a26: v100,
    a27: v106,
    a28: v112,
    a29: v118,
    a30: v124,
    a31: v130,
    a32: v136,
    a33: v142,
    a34: v148,
    a35: v154,
    a36: v160,
    a37: HIBYTE(v3[3].giveItemsOnReceive.num));
  idLaserSight::Init(
    this: &this->laserBeamShootBounce,
    _beamEffects: this->beamModelWorldView,
    _decalEffects: this->decalModelworldView,
    laserBeamMtr: (const idMaterial *)v3[3].dropEventDecl,
    laserBeamHeight: *(float *)&v3[3].initiallyHidden,
    laserPointMtr: (const idMaterial *)HIBYTE(v3[3].giveItemsOnReceive.num),
    laserPointSize: *(float *)&v3[3].itemGroup,
    laserPointDepth: *(float *)&v3[3].itemGroupWorth,
    fadeIn: *(float *)&v3[3].giveItemsOnReceive.size,
    fadeOut: *(float *)&v3[3].giveItemsOnReceive.granularity,
    isQuad: (const idMaterial *)v3[3].itemUse,
    a12: v20,
    a13: v19,
    a14: v29,
    a15: v35,
    a16: v41,
    a17: v47,
    a18: v53,
    a19: v59,
    a20: v65,
    a21: v71,
    a22: v77,
    a23: v83,
    a24: v89,
    a25: v95,
    a26: v101,
    a27: v107,
    a28: v113,
    a29: v119,
    a30: v125,
    a31: v131,
    a32: v137,
    a33: v143,
    a34: v149,
    a35: v155,
    a36: v161,
    a37: HIBYTE(v3[3].giveItemsOnReceive.num));
  idLaserSight::Init(
    this: &this->laserBeamShootIndication,
    _beamEffects: this->beamModelFPView,
    _decalEffects: this->decalModelFPView,
    laserBeamMtr: (const idMaterial *)v3[3].giveItemsOnRecieveWithCount.list,
    laserBeamHeight: *(float *)&v3[3].giveItemsOnRecieveWithCount.size,
    laserPointMtr: v23,
    laserPointSize: *(float *)&v3[3].giveItemsOnRecieveWithCount.granularity,
    laserPointDepth: *(float *)&v3[3].engineerableItems.list,
    fadeIn: *(float *)&v3[3].weaponFX,
    fadeOut: *(float *)&v3[3].equipWeaponOnUse,
    isQuad: (const idMaterial *)v3[3].giveItemsOnRecieveWithCount.num,
    a12: v22,
    a13: v21,
    a14: v30,
    a15: v36,
    a16: v42,
    a17: v48,
    a18: v54,
    a19: v60,
    a20: v66,
    a21: v72,
    a22: v78,
    a23: v84,
    a24: v90,
    a25: v96,
    a26: v102,
    a27: v108,
    a28: v114,
    a29: v120,
    a30: v126,
    a31: v132,
    a32: v138,
    a33: v144,
    a34: v150,
    a35: v156,
    a36: v162,
    a37: HIBYTE(v3[3].engineerableItems.granularity));
  idLaserSight::Init(
    this: &this->laserBeamShootBounceIndication,
    _beamEffects: this->beamModelWorldView,
    _decalEffects: this->decalModelworldView,
    laserBeamMtr: (const idMaterial *)v3[3].giveItemsOnRecieveWithCount.list,
    laserBeamHeight: *(float *)&v3[3].giveItemsOnRecieveWithCount.size,
    laserPointMtr: v25,
    laserPointSize: *(float *)&v3[3].giveItemsOnRecieveWithCount.granularity,
    laserPointDepth: *(float *)&v3[3].engineerableItems.list,
    fadeIn: *(float *)&v3[3].weaponFX,
    fadeOut: *(float *)&v3[3].equipWeaponOnUse,
    isQuad: (const idMaterial *)v3[3].giveItemsOnRecieveWithCount.num,
    a12: v24,
    a13: HIBYTE(v3[3].engineerableItems.granularity),
    a14: v31,
    a15: v37,
    a16: v43,
    a17: v49,
    a18: v55,
    a19: v61,
    a20: v67,
    a21: v73,
    a22: v79,
    a23: v85,
    a24: v91,
    a25: v97,
    a26: v103,
    a27: v109,
    a28: v115,
    a29: v121,
    a30: v127,
    a31: v133,
    a32: v139,
    a33: v145,
    a34: v151,
    a35: v157,
    a36: v163,
    a37: HIBYTE(v3[3].engineerableItems.granularity));
  this->laserBeamCutFade.startTime = 0.0;
  this->laserBeamCutFade.duration = 0.0;
  this->laserBeamCutFade.startValue = 0.0;
  this->laserBeamCutFade.endValue = 0.0;
  this->laserBeamCutFade.currentValue = 0.0;
  this->laserBeamCutFade.currentTime = -1.0;
  this->laserBeamBounceIndicationFade.startTime = 0.0;
  this->laserBeamBounceIndicationFade.duration = 0.0;
  this->laserBeamBounceIndicationFade.startValue = 0.0;
  this->laserBeamBounceIndicationFade.endValue = 0.0;
  this->laserBeamBounceIndicationFade.currentTime = -1.0;
  this->laserBeamBounceIndicationFade.currentValue = 0.0;
  idLaserSight::Hide(this: &this->laserBeamCut);
  idLaserSight::Hide(this: &this->laserBeamCutBounce);
  idLaserSight::Hide(this: &this->laserBeamShoot);
  idLaserSight::Hide(this: &this->laserBeamShootBounce);
  idLaserSight::Hide(this: &this->laserBeamShootIndication);
  idLaserSight::Hide(this: &this->laserBeamShootBounceIndication);
  this->hasBatteryUpgrade = HIBYTE(v3[4].__vftable);
  this->hasRemoteCuttingUpgrade = BYTE1(v3[4].__vftable);
  this->hasMobileReactorUpgrade = BYTE2(v3[4].__vftable);
  this->availableFunctionalityLenses = 0;
  if ( HIBYTE(v3[4].childItem.granularity) != 0 )
    this->availableFunctionalityLenses = 1;
  if ( LOBYTE(v3[4].childItem.granularity) != 0 )
    this->availableFunctionalityLenses |= 2u;
  if ( v3[4].childItem.memTag != 0 )
    this->availableFunctionalityLenses |= 4u;
  if ( this->ammoClipSecondary != nullptr )
    this->weaponState = WEAPONSTATE_SECONDARY;
}


// ========================================================================
// ?SetBatteryUpgradeValues@idLaserCutter@@QAAX_NH@Z
// EA  : 0x82EBCB70
// RVA : 0x00EBCB70
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __fastcall idLaserCutter::SetBatteryUpgradeValues(idLaserCutter *this, bool hasTheUpgrade, int maxBatteryAmount)
{
  char v3; // r11

  v3 = *((_BYTE *)&this->idWeapon + 453);
  this->maxBattery = maxBatteryAmount;
  this->hasBatteryUpgrade = hasTheUpgrade;
  if ( (v3 & 0x40) == 0 )
    *((_BYTE *)&this->idWeapon + 453) = (hasTheUpgrade << 6) & 0x40 | v3 & 0xBF;
}


// ========================================================================
// ?ChargeBattery@idLaserCutter@@QAAXH@Z
// EA  : 0x82EBCB98
// RVA : 0x00EBCB98
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __fastcall idLaserCutter::ChargeBattery(idLaserCutter *this, int amount)
{
  int maxBattery; // r11
  int v3; // r10

  maxBattery = this->maxBattery;
  v3 = amount + this->batteryCount;
  if ( maxBattery >= v3 )
    this->batteryCount = v3;
  else
    this->batteryCount = maxBattery;
}


// ========================================================================
// ?GetOkToFire@idLaserCutter@@QBA_NXZ
// EA  : 0x82EBCBC0
// RVA : 0x00EBCBC0
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

int __fastcall idLaserCutter::GetOkToFire(idLaserCutter *this, int a2, int a3, int a4, int a5, __int64 a6)
{
  unsigned __int8 v6; // r11
  idAmmoItem *ammoClip; // r11
  const idDeclInventory *decl; // r11

  if ( this->weaponState != WEAPONSTATE_SECONDARY )
  {
    ammoClip = this->ammoClip;
    if ( ammoClip != nullptr )
      decl = ammoClip->decl;
    else
      decl = nullptr;
    if ( (*((_BYTE *)&this->idWeapon + 453) & 0x40) != 0 && decl != nullptr )
    {
      LODWORD(a6) = this->batteryCount;
      v6 = 1;
      if ( (float)a6 > 0.0 )
        return v6;
    }
  }
  else if ( this->lastOkToCutTime != 0 )
  {
    v6 = 1;
    if ( this->batteryCount == 0 )
      return 0;
    return v6;
  }
  return 0;
}


// ========================================================================
// ?IsReadyToFire@idLaserCutter@@QAA_NXZ
// EA  : 0x82EBCC60
// RVA : 0x00EBCC60
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

unsigned int __fastcall idLaserCutter::IsReadyToFire(idLaserCutter *this)
{
  int GameMs; // r3

  if ( this->weaponState == WEAPONSTATE_SECONDARY && this->lastOkToCutTime == 0 )
    return 0;
  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  return (GameMs >> 31) + ((unsigned int)GameMs >= this->nextFireTime) + ((unsigned int)this->nextFireTime >> 31);
}


// ========================================================================
// ?SetChargingEffects@idLaserCutter@@QAAX_NPAVidActor@@@Z
// EA  : 0x82EBCCE8
// RVA : 0x00EBCCE8
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __fastcall idLaserCutter::SetChargingEffects(idLaserCutter *this, bool activate, idActor *actor)
{
  idFXManager *v4; // r31
  int GameMs; // r3

  v4 = actor->GetFXMgrForAttachment(this: actor, a2: this);
  if ( v4 != nullptr )
  {
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    if ( activate )
      idFXManager::StartFX(this: v4, org: &vec3_origin, axis: &mat3_identity, time: GameMs, startCondition: 79);
    else
      idFXManager::StopFX(this: v4, time: GameMs, stopCondition: 80, immediateStop: false);
  }
}


// ========================================================================
// ?GetClipSize@idLaserCutter@@UBAHPBVidAmmoItem@@PBVidDeclAmmo@@_N2@Z
// EA  : 0x82EBCDA0
// RVA : 0x00EBCDA0
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

int __fastcall idLaserCutter::GetClipSize(
        idLaserCutter *this,
        const idAmmoItem *ammo,
        const idDeclAmmo *ammoDecl,
        bool weaponUpgraded,
        bool secondaryAmmo)
{
  return this->maxBattery;
}


// ========================================================================
// ?ShouldSwitchWeaponWhenOutOfAmmo@idLaserCutter@@UBA_NXZ
// EA  : 0x82EBCDA8
// RVA : 0x00EBCDA8
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

__int32 __fastcall idLaserCutter::ShouldSwitchWeaponWhenOutOfAmmo(idLaserCutter *this)
{
  return this->weaponState - 1 - (this->weaponState - 2 + (this->weaponState == WEAPONSTATE_SECONDARY));
}


// ========================================================================
// ?LoadAmmo@idLaserCutter@@UAAXPAVidInventoryCollection@@PBVidDeclAmmo@@PAVidFXManager@@_N333@Z
// EA  : 0x82EBCDC0
// RVA : 0x00EBCDC0
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __fastcall idLaserCutter::LoadAmmo(
        idLaserCutter *this,
        idInventoryCollection *inventory,
        const idDeclAmmo *ammoDecl,
        idFXManager *fxMgr,
        const bool sameAmmoCount,
        const bool allowForceFullClip,
        const bool skipAddingToClip,
        bool secondaryAmmo)
{
  BOOL v8; // r29
  idAmmoItem *ammoClipSecondary; // r11
  idInventoryItem *v13; // r3
  idAmmoItem *v14; // r30
  idAmmoItem *v15; // r3
  __int32 initialBurstModeOverride; // r11
  idAmmoItem *JobByDecl; // r3
  idAmmoItem *v18; // r5

  v8 = secondaryAmmo;
  if ( secondaryAmmo )
    ammoClipSecondary = this->ammoClipSecondary;
  else
    ammoClipSecondary = this->ammoClip;
  if ( ammoClipSecondary != nullptr )
  {
    if ( ammoClipSecondary->decl == ammoDecl )
      return;
    this->UnloadAmmo(this, a2: inventory, a3: fxMgr, a4: secondaryAmmo);
  }
  v13 = idInventoryItem::Create(decl: ammoDecl);
  v14 = (idAmmoItem *)v13;
  if ( v13 != nullptr )
  {
    if ( (unsigned __int8)idAmmoItem::IsTypeOf(c: v13) != 0 )
    {
      v15 = idAmmoItem::CastTo(c: v14);
      if ( v8 )
        this->ammoClipSecondary = v15;
      else
        this->ammoClip = v15;
      this->burstCount = 0;
      initialBurstModeOverride = ammoDecl->initialBurstModeOverride;
      if ( initialBurstModeOverride == 3 )
        initialBurstModeOverride = this->decl[1].attachmentInfo.num;
      v15->burstMode = initialBurstModeOverride;
      if ( inventory != nullptr )
      {
        JobByDecl = (idAmmoItem *)idJobManager::FindJobByDecl(
                                    this: (idJobManager *)inventory,
                                    jobDecl: (const idDeclJob *)ammoDecl);
        v18 = idAmmoItem::CastTo(c: JobByDecl);
        if ( v18 != nullptr )
          idInventoryCollection::RemoveItemFromInventory(this: inventory, owner: nullptr, item: &v18->idInventoryItem);
      }
    }
    else
    {
      idLib::Warning(fmt: "Invalid initial ammo type of '%s' for weapon '%s'", ammoDecl->name.str, this->decl->name.str);
      ((void (__fastcall *)(idAmmoItem *, int))v14->dtr_idClass)(a1: v14, a2: 1);
    }
  }
  else
  {
    idLib::Warning(fmt: "Unknown initial ammo type of '%s' for weapon '%s'", ammoDecl->name.str, this->decl->name.str);
  }
}


// ========================================================================
// ?NeedsReload@idLaserCutter@@UBA_N_N@Z
// EA  : 0x82EBCF18
// RVA : 0x00EBCF18
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

int __fastcall idLaserCutter::NeedsReload(idLaserCutter *this, bool secondaryAmmo)
{
  idAmmoItem *ammoClipSecondary; // r11
  unsigned __int8 v3; // r11

  if ( secondaryAmmo )
    ammoClipSecondary = this->ammoClipSecondary;
  else
    ammoClipSecondary = this->ammoClip;
  if ( ammoClipSecondary == nullptr )
    return 1;
  v3 = 0;
  if ( this->batteryCount <= 0 )
    return 1;
  return v3;
}


// ========================================================================
// ?FakeCutEffect@idLaserCutter@@QAAXXZ
// EA  : 0x82EBCF58
// RVA : 0x00EBCF58
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __fastcall idLaserCutter::FakeCutEffect(idLaserCutter *this)
{
  __int64 v2; // r9
  double CurrentValue; // fp1
  double fadeInDuration; // fp31
  double v5; // fp30
  __int64 v6; // [sp+50h] [-40h]

  this->cuttingWeldEffectRunning = true;
  LODWORD(v2) = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  CurrentValue = idInterpolate<float>::GetCurrentValue(
                   this: &this->laserBeamCutFade,
                   time: (float)((float)v2 * (float)0.001));
  fadeInDuration = this->laserBeamCut.fadeInDuration;
  v5 = CurrentValue;
  v6 = __PAIR64__(0x82000000, idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED));
  this->laserBeamCutFade.startValue = v5;
  this->laserBeamCutFade.endValue = 1.0;
  this->laserBeamCutFade.currentValue = v5;
  this->laserBeamCutFade.startTime = (float)v6 * (float)0.001;
  this->laserBeamCutFade.duration = (float)((float)1.0 - (float)v5) * (float)fadeInDuration;
  this->laserBeamCutFade.currentTime = (float)((float)v6 * (float)0.001) - (float)1.0;
}


// ========================================================================
// ?SetFunctionalityLensState@idLaserCutter@@QAAX_N@Z
// EA  : 0x82EBD030
// RVA : 0x00EBD030
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __fastcall idLaserCutter::SetFunctionalityLensState(idLaserCutter *this, bool on)
{
  idLaserCutter::functionalityLens_t currentFunctionalityLens; // r10
  idGameTimeManager *p_gameTimeManager; // r3
  __int64 v5; // r10
  double CurrentValue; // fp31
  __int64 v7; // r10
  idInterpolate<float> *p_laserBeamBounceIndicationFade; // r31
  double v9; // fp31
  __int64 v10; // [sp+50h] [-40h]
  __int64 v11; // [sp+50h] [-40h]

  if ( this->functionalityLensActive != on )
  {
    currentFunctionalityLens = this->currentFunctionalityLens;
    this->functionalityLensActive = on;
    if ( currentFunctionalityLens == FUNCTIONALITY_LENS_REFLECTION )
    {
      p_gameTimeManager = &clientGame->gameTimeManager;
      if ( on )
      {
        LODWORD(v5) = idGameTimeManager::GetGameMs(this: p_gameTimeManager, type: GAMETIME_SCALED);
        CurrentValue = idInterpolate<float>::GetCurrentValue(
                         this: &this->laserBeamCutFade,
                         time: (float)((float)v5 * (float)0.001));
        v10 = __PAIR64__(
                0x82000000,
                idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED));
        this->laserBeamBounceIndicationFade.startValue = CurrentValue;
        this->laserBeamBounceIndicationFade.endValue = 1.0;
        this->laserBeamBounceIndicationFade.currentValue = CurrentValue;
        this->laserBeamBounceIndicationFade.startTime = (float)v10 * (float)0.001;
        this->laserBeamBounceIndicationFade.duration = (float)((float)1.0 - (float)CurrentValue) * (float)0.25;
        this->laserBeamBounceIndicationFade.currentTime = (float)((float)v10 * (float)0.001) - (float)1.0;
      }
      else
      {
        LODWORD(v7) = idGameTimeManager::GetGameMs(this: p_gameTimeManager, type: GAMETIME_SCALED);
        p_laserBeamBounceIndicationFade = &this->laserBeamBounceIndicationFade;
        v9 = idInterpolate<float>::GetCurrentValue(
               this: p_laserBeamBounceIndicationFade,
               time: (float)((float)v7 * (float)0.001));
        v11 = __PAIR64__(
                &unk_82150000,
                idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED));
        p_laserBeamBounceIndicationFade->duration = (float)v9 * (float)0.25;
        p_laserBeamBounceIndicationFade->startValue = v9;
        p_laserBeamBounceIndicationFade->endValue = 0.0;
        p_laserBeamBounceIndicationFade->currentValue = v9;
        p_laserBeamBounceIndicationFade->startTime = (float)v11 * (float)0.001;
        p_laserBeamBounceIndicationFade->currentTime = (float)((float)v11 * (float)0.001) - (float)1.0;
      }
    }
  }
}


// ========================================================================
// ?CanUse@idWeaponUpgrade@@UAA_NPAVidActor@@@Z
// EA  : 0x82EBD1C8
// RVA : 0x00EBD1C8
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

int __fastcall idWeaponUpgrade::CanUse(idWeaponUpgrade *this, idActor *user)
{
  const idDeclInventory *decl; // r30
  const char *trackedMemory; // r31
  idInventoryCollection *v4; // r3
  idInventoryItem *InventoryItemByName; // r3
  idWeapon *v6; // r31
  idWeapon *v7; // r3
  int result; // r3
  char v9; // r11

  if ( user == nullptr )
    return 0;
  decl = this->decl;
  trackedMemory = (const char *)decl[1].trackedMemory;
  v4 = user->GetInventory_2(this: user);
  InventoryItemByName = idInventoryCollection::FindInventoryItemByName(this: v4, internalName: trackedMemory);
  v6 = (idWeapon *)InventoryItemByName;
  if ( InventoryItemByName == nullptr )
    return 0;
  if ( (unsigned __int8)idWeapon::IsTypeOf(c: InventoryItemByName) == 0 )
    return 0;
  v7 = idWeapon::CastTo(c: v6);
  if ( v7 == nullptr )
    return 0;
  if ( HIBYTE(decl[1].textSource) != 0 && (*((_BYTE *)v7 + 452) & 0x10) == 0
    || BYTE1(decl[1].textSource) != 0 && (*((_BYTE *)v7 + 452) & 4) == 0
    || BYTE2(decl[1].textSource) != 0 && (*((_BYTE *)v7 + 452) & 2) == 0 )
  {
    return 1;
  }
  if ( LOBYTE(decl[1].textSource) == 0 )
    return 0;
  v9 = *((_BYTE *)v7 + 453);
  result = 1;
  if ( (v9 & 0x40) != 0 )
    return 0;
  return result;
}


// ========================================================================
// ?Use@idWeaponUpgrade@@UAA_NPAVidActor@@@Z
// EA  : 0x82EBD2D0
// RVA : 0x00EBD2D0
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

int __fastcall idWeaponUpgrade::Use(idWeaponUpgrade *this, idPlayer *user)
{
  const idDeclInventory *decl; // r28
  const char *trackedMemory; // r31
  idInventoryCollection *v7; // r3
  idInventoryItem *InventoryItemByName; // r3
  idWeapon *v9; // r31
  idWeapon *v10; // r3
  idWeapon *v11; // r31
  int v12; // r27
  idAmmoItem *ammoClip; // r11
  const idDeclAmmo *v14; // r30
  idWeapon_vtbl *v15; // r29
  idFXManager *v16; // r27
  idInventoryCollection *v17; // r3
  idPlayer *v18; // r3
  idPlayer *v19; // r29
  idPresentable *presentable; // r3
  bool v21; // zf
  int v22; // r3
  idPresentable *v23; // r3
  const char *v24; // r31
  int v25; // r3
  const char *md5Checksum; // r31
  int v27; // r3
  const idDeclInventory *v28; // r11
  const idSoundShader *useSound; // r5

  if ( user == nullptr )
    return 0;
  decl = this->decl;
  trackedMemory = (const char *)decl[1].trackedMemory;
  v7 = user->GetInventory_2(this: user);
  InventoryItemByName = idInventoryCollection::FindInventoryItemByName(this: v7, internalName: trackedMemory);
  v9 = (idWeapon *)InventoryItemByName;
  if ( InventoryItemByName == nullptr || (unsigned __int8)idWeapon::IsTypeOf(c: InventoryItemByName) == 0 )
    return 0;
  v10 = idWeapon::CastTo(c: v9);
  v11 = v10;
  v12 = 0;
  if ( HIBYTE(decl[1].textSource) != 0 && (*((_BYTE *)v10 + 452) & 0x10) == 0 )
  {
    v12 = 1;
    *((_BYTE *)v10 + 452) |= 0x10u;
  }
  if ( BYTE1(decl[1].textSource) != 0 && (*((_BYTE *)v10 + 452) & 4) == 0 )
  {
    ammoClip = v10->ammoClip;
    *((_BYTE *)v10 + 452) |= 4u;
    if ( ammoClip != nullptr )
    {
      v14 = (const idDeclAmmo *)ammoClip->decl;
      if ( v14 != nullptr )
      {
        v15 = v10->__vftable;
        v16 = user->GetFXMgrForAttachment(this: user, a2: v10);
        v17 = user->GetInventory_2(this: user);
        v15->LoadAmmo(this: v11, a2: v17, a3: v14, a4: v16, a5: false, a6: true, a7: false, a8: false);
      }
    }
    v12 = 1;
  }
  if ( BYTE2(decl[1].textSource) != 0 && (*((_BYTE *)v11 + 452) & 2) == 0 )
  {
    v12 = 1;
    *((_BYTE *)v11 + 452) |= 2u;
  }
  if ( LOBYTE(decl[1].textSource) != 0 )
  {
    v12 = 1;
    *((_BYTE *)v11 + 453) |= 0x40u;
  }
  if ( (_BYTE)v12 != 0 )
  {
    v18 = idPlayer::CastTo(c: user);
    v19 = v18;
    if ( v18 != nullptr )
    {
      v21 = v11 == idActor::GetEquippedWeapon(this: v18, slot: EQUIP_RIGHT_HAND);
      presentable = v19->presentable;
      if ( v21 )
      {
        md5Checksum = (const char *)decl[1].md5Checksum;
        if ( presentable != nullptr )
          v27 = (int)presentable->GetPlayerInterface_2(this: presentable);
        else
          v27 = 0;
        idHands::SetPendingAction(
          this: (idHands *)(v27 + 37616),
          action: HANDSACTION_UPGRADEWEAPON,
          nodeInfo: md5Checksum);
      }
      else
      {
        if ( presentable != nullptr )
          v22 = (int)presentable->GetPlayerInterface_2(this: presentable);
        else
          v22 = 0;
        idHands::SelectWeapon(
          this: (idHands *)(v22 + 37616),
          slot: EQUIP_RIGHT_HAND,
          weapon: v11,
          useIntroBringUp: false);
        v23 = v19->presentable;
        v24 = (const char *)decl[1].md5Checksum;
        if ( v23 != nullptr )
          v25 = (int)v23->GetPlayerInterface_2(this: v23);
        else
          v25 = 0;
        idHands::SetLingeringAction(
          this: (idHands *)(v25 + 37616),
          action: HANDSACTION_UPGRADEWEAPON,
          ammoDecl: nullptr,
          secondary: false,
          leftHand: false,
          nodeInfo: v24);
      }
    }
  }
  v28 = this->decl;
  if ( v28 != nullptr )
  {
    useSound = v28->useSound;
    if ( useSound != nullptr )
      idEntity::StartSoundShader(
        this: user,
        channel: SND_CHANNEL_ITEM,
        shader: useSound,
        soundShaderFlags: (soundShaderFlags_t)0,
        peerMask: 0xFFu);
  }
  return v12;
}


// ========================================================================
// ?ClientUse@idWeaponUpgrade@@UAA_NPAVidPresentablePlayer@@@Z
// EA  : 0x82EBD588
// RVA : 0x00EBD588
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

int __fastcall idWeaponUpgrade::ClientUse(idWeaponUpgrade *this, idPresentablePlayer *player)
{
  int result; // r3
  const idDeclInventory *decl; // r28
  const char *trackedMemory; // r31
  idInventoryCollection *v6; // r3
  idInventoryItem *InventoryItemByName; // r3
  idWeapon *v8; // r31
  idWeapon *v9; // r31
  idAmmoItem *ammoClip; // r11
  idEntity *entity; // r3
  int v12; // r30
  idPresentablePlayer *v13; // r3
  idWeapon_vtbl *v14; // r29
  const idDeclInventory *v15; // r27
  idInventoryCollection *(__fastcall *GetInventory)(idPresentableAnimatedEntity *); // ctr
  int v17; // r3

  if ( player == nullptr )
    return 0;
  decl = this->decl;
  trackedMemory = (const char *)decl[1].trackedMemory;
  v6 = player->GetInventory(this: player);
  InventoryItemByName = idInventoryCollection::FindInventoryItemByName(this: v6, internalName: trackedMemory);
  v8 = (idWeapon *)InventoryItemByName;
  if ( InventoryItemByName == nullptr || (unsigned __int8)idWeapon::IsTypeOf(c: InventoryItemByName) == 0 )
    return 0;
  v9 = idWeapon::CastTo(c: v8);
  result = 0;
  if ( v9 != nullptr )
  {
    if ( HIBYTE(decl[1].textSource) != 0 && (*((_BYTE *)v9 + 452) & 0x10) == 0 )
    {
      result = 1;
      *((_BYTE *)v9 + 452) |= 0x10u;
    }
    if ( BYTE1(decl[1].textSource) != 0 && (*((_BYTE *)v9 + 452) & 4) == 0 )
    {
      ammoClip = v9->ammoClip;
      *((_BYTE *)v9 + 452) |= 4u;
      if ( ammoClip != nullptr && ammoClip->decl != nullptr )
      {
        entity = player->entity;
        if ( entity != nullptr )
          v12 = ((int (__fastcall *)(idEntity *, idWeapon *))entity->__vftable[1].GetColor_3)(a1: entity, a2: v9);
        else
          v12 = 0;
        v13 = player;
        v15 = v9->ammoClip->decl;
        GetInventory = player->GetInventory;
        v14 = v9->__vftable;
        v17 = (int)GetInventory(this: v13);
        v14->LoadAmmo(
          this: v9,
          a2: (idInventoryCollection *)v17,
          a3: (const idDeclAmmo *)v15,
          a4: (idFXManager *)v12,
          a5: false,
          a6: true,
          a7: false,
          a8: false);
      }
      result = 1;
    }
    if ( BYTE2(decl[1].textSource) != 0 && (*((_BYTE *)v9 + 452) & 2) == 0 )
    {
      result = 1;
      *((_BYTE *)v9 + 452) |= 2u;
    }
    if ( LOBYTE(decl[1].textSource) != 0 )
    {
      *((_BYTE *)v9 + 453) |= 0x40u;
      return 1;
    }
  }
  return result;
}


// ========================================================================
// ?CanUse@idLaserCutterUpgrade@@UAA_NPAVidActor@@@Z
// EA  : 0x82EBD740
// RVA : 0x00EBD740
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

int __fastcall idLaserCutterUpgrade::CanUse(idLaserCutterUpgrade *this, idActor *user)
{
  const idDeclInventory *decl; // r30
  const char *nextOnHashChain; // r31
  idInventoryCollection *v4; // r3
  idInventoryItem *InventoryItemByName; // r3
  idLaserCutter *v6; // r31
  idLaserCutter *v7; // r3
  idDeclInventory_vtbl *v8; // r10
  idAmmoItem *ammoClip; // r11
  idDeclInventory_vtbl *v10; // r11
  int result; // r3
  int trackedMemory; // r10
  idAmmoItem *ammoClipSecondary; // r11
  const idDeclInventory *v14; // r11
  BOOL hasMobileReactorUpgrade; // r11

  if ( user == nullptr )
    return 0;
  decl = this->decl;
  nextOnHashChain = (const char *)decl[1].nextOnHashChain;
  v4 = user->GetInventory_2(this: user);
  InventoryItemByName = idInventoryCollection::FindInventoryItemByName(this: v4, internalName: nextOnHashChain);
  v6 = (idLaserCutter *)InventoryItemByName;
  if ( InventoryItemByName == nullptr )
    return 0;
  if ( (unsigned __int8)idLaserCutter::IsTypeOf(c: InventoryItemByName) == 0 )
    return 0;
  v7 = idLaserCutter::CastTo(c: v6);
  if ( v7 == nullptr )
    return 0;
  v8 = decl[1].__vftable;
  if ( v8 != nullptr )
  {
    ammoClip = v7->ammoClip;
    v10 = ammoClip != nullptr ? (idDeclInventory_vtbl *)ammoClip->decl : nullptr;
    if ( v10 != v8 )
      return 1;
  }
  trackedMemory = decl[1].trackedMemory;
  if ( trackedMemory != 0 )
  {
    ammoClipSecondary = v7->ammoClipSecondary;
    v14 = ammoClipSecondary != nullptr ? ammoClipSecondary->decl : nullptr;
    if ( v14 != (const idDeclInventory *)trackedMemory )
      return 1;
  }
  if ( HIBYTE(decl[1].textLength) != 0 || decl[1].programaticallyDefined && !v7->hasRemoteCuttingUpgrade )
    return 1;
  if ( !*(&decl[1].programaticallyDefined + 1) )
    return 0;
  hasMobileReactorUpgrade = v7->hasMobileReactorUpgrade;
  result = 1;
  if ( hasMobileReactorUpgrade )
    return 0;
  return result;
}


// ========================================================================
// ?Use@idLaserCutterUpgrade@@UAA_NPAVidActor@@@Z
// EA  : 0x82EBD870
// RVA : 0x00EBD870
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

int __fastcall idLaserCutterUpgrade::Use(idLaserCutterUpgrade *this, idPlayer *user)
{
  const idDeclInventory *decl; // r30
  const char *nextOnHashChain; // r31
  idInventoryCollection *v7; // r3
  idInventoryItem *InventoryItemByName; // r3
  idLaserCutter *v9; // r31
  idLaserCutter *v10; // r31
  int maxBattery; // r10
  __int64 v12; // r9
  const idMaterial *v13; // r7
  int v14; // r6
  int v15; // r5
  int v16; // r27
  idPlayer *v17; // r3
  idPresentable *presentable; // r3
  int v19; // r3
  idDeclInventory_vtbl *v20; // r27
  idLaserCutter_vtbl *v21; // r29
  int GetResourceList_low; // r24
  int v23; // r3
  idPlayer *v24; // r3
  idPresentable *v25; // r3
  int v26; // r3
  int trackedMemory; // r27
  idLaserCutter_vtbl *v28; // r29
  int v29; // r24
  int v30; // r3
  unsigned int md5Checksum; // r11
  idDeclSource *declSource; // r11
  double v33; // fp0
  idPlayer *v34; // r3
  idPlayer *v35; // r28
  idPresentable *v36; // r3
  bool v37; // zf
  int v38; // r3
  idPresentable *v39; // r3
  const char *v40; // r31
  int v41; // r3
  const char *len; // r31
  int v43; // r3
  const idDeclInventory *v44; // r11
  const idSoundShader *useSound; // r5

  if ( user == nullptr )
    return 0;
  decl = this->decl;
  nextOnHashChain = (const char *)decl[1].nextOnHashChain;
  v7 = user->GetInventory_2(this: user);
  InventoryItemByName = idInventoryCollection::FindInventoryItemByName(this: v7, internalName: nextOnHashChain);
  v9 = (idLaserCutter *)InventoryItemByName;
  if ( InventoryItemByName == nullptr || (unsigned __int8)idLaserCutter::IsTypeOf(c: InventoryItemByName) == 0 )
    return 0;
  v10 = idLaserCutter::CastTo(c: v9);
  v16 = 0;
  if ( decl[1].__vftable != nullptr )
  {
    v17 = idPlayer::CastTo(c: user);
    if ( v17 != nullptr )
    {
      presentable = v17->presentable;
      if ( presentable != nullptr )
        v19 = (int)presentable->GetPlayerInterface_2(this: presentable);
      else
        v19 = 0;
      v20 = decl[1].__vftable;
      v21 = v10->__vftable;
      GetResourceList_low = LOBYTE(v20[12].GetResourceList);
      v23 = (*(int (__fastcall **)(int))(*(_DWORD *)v19 + 324))(a1: v19);
      v21->LoadAmmo(
        this: v10,
        a2: (idInventoryCollection *)v23,
        a3: (const idDeclAmmo *)v20,
        a4: nullptr,
        a5: false,
        a6: true,
        a7: false,
        a8: GetResourceList_low);
      v16 = 1;
    }
  }
  if ( decl[1].trackedMemory != 0 )
  {
    v24 = idPlayer::CastTo(c: user);
    if ( v24 != nullptr )
    {
      v25 = v24->presentable;
      if ( v25 != nullptr )
        v26 = (int)v25->GetPlayerInterface_2(this: v25);
      else
        v26 = 0;
      trackedMemory = decl[1].trackedMemory;
      v28 = v10->__vftable;
      v29 = *(unsigned __int8 *)(trackedMemory + 787);
      v30 = (*(int (__fastcall **)(int))(*(_DWORD *)v26 + 324))(a1: v26);
      v28->LoadAmmo(
        this: v10,
        a2: (idInventoryCollection *)v30,
        a3: (const idDeclAmmo *)trackedMemory,
        a4: nullptr,
        a5: false,
        a6: true,
        a7: false,
        a8: v29);
      v16 = 1;
    }
  }
  if ( HIBYTE(decl[1].textLength) != 0 )
  {
    md5Checksum = decl[1].md5Checksum;
    v16 = 1;
    maxBattery = v10->maxBattery;
    LODWORD(v12) = *((unsigned __int8 *)&v10->idWeapon + 453);
    HIDWORD(v12) = md5Checksum + maxBattery;
    v10->hasBatteryUpgrade = true;
    v13 = (const idMaterial *)(v12 | 0x40);
    v10->maxBattery = md5Checksum + maxBattery;
    v10->batteryCount = md5Checksum;
    *((_BYTE *)&v10->idWeapon + 453) = v12 | 0x40;
  }
  if ( !v10->hasRemoteCuttingUpgrade && decl[1].programaticallyDefined )
  {
    v16 = 1;
    v10->hasRemoteCuttingUpgrade = true;
  }
  if ( *(&decl[1].programaticallyDefined + 1) )
  {
    declSource = decl[1].declSource;
    maxBattery = 968;
    v33 = *(float *)&decl[1].parent;
    v10->hasMobileReactorUpgrade = true;
    LODWORD(v12) = declSource;
    v16 = 1;
    v10->chargeDelaySec = (int)v33;
    v10->chargePerSecond = (float)v12;
  }
  if ( *(_DWORD *)&decl[1].inventoryClass.baseBuffer[16] != 0 )
    idLaserCutter::OverrideShootingLaserBeam(
      this: v10,
      overrideInfo: (const laserSightInfo_t *)&decl[1].inventoryClass.baseBuffer[16],
      a3: v15,
      a4: v14,
      a5: v13,
      a6: SHIDWORD(v12),
      a7: v12,
      a8: maxBattery);
  if ( (_BYTE)v16 != 0 )
  {
    v34 = idPlayer::CastTo(c: user);
    v35 = v34;
    if ( v34 != nullptr )
    {
      v37 = v10 == idActor::GetEquippedWeapon(this: v34, slot: EQUIP_RIGHT_HAND);
      v36 = v35->presentable;
      if ( v37 )
      {
        len = (const char *)decl[1].inventoryClass.len;
        if ( v36 != nullptr )
          v43 = (int)v36->GetPlayerInterface_2(this: v36);
        else
          v43 = 0;
        idHands::SetPendingAction(this: (idHands *)(v43 + 37616), action: HANDSACTION_UPGRADEWEAPON, nodeInfo: len);
      }
      else
      {
        if ( v36 != nullptr )
          v38 = (int)v36->GetPlayerInterface_2(this: v36);
        else
          v38 = 0;
        idHands::SelectWeapon(
          this: (idHands *)(v38 + 37616),
          slot: EQUIP_RIGHT_HAND,
          weapon: v10,
          useIntroBringUp: false);
        v39 = v35->presentable;
        v40 = (const char *)decl[1].inventoryClass.len;
        if ( v39 != nullptr )
          v41 = (int)v39->GetPlayerInterface_2(this: v39);
        else
          v41 = 0;
        idHands::SetLingeringAction(
          this: (idHands *)(v41 + 37616),
          action: HANDSACTION_UPGRADEWEAPON,
          ammoDecl: nullptr,
          secondary: false,
          leftHand: false,
          nodeInfo: v40);
      }
    }
  }
  v44 = this->decl;
  if ( v44 != nullptr )
  {
    useSound = v44->useSound;
    if ( useSound != nullptr )
      idEntity::StartSoundShader(
        this: user,
        channel: SND_CHANNEL_ITEM,
        shader: useSound,
        soundShaderFlags: (soundShaderFlags_t)0,
        peerMask: 0xFFu);
  }
  return v16;
}


// ========================================================================
// ?IsValidUpgrade@idVehicleKey@@QBA_NPBVidVehicleUpgrade@@@Z
// EA  : 0x82EBDBD8
// RVA : 0x00EBDBD8
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

int __fastcall idVehicleKey::IsValidUpgrade(idVehicleKey *this, const idVehicleUpgrade *upgrade)
{
  int num; // r31
  int v3; // r6
  idList<idDeclVehicleUpgrade const *,5> *i; // r7
  int v5; // r8
  int v6; // r10
  int v7; // r11

  num = this->validUpgrades.num;
  v3 = 0;
  if ( num <= 0 )
    return 0;
  for ( i = this->validUpgrades.list; ; ++i )
  {
    v5 = i->num;
    v6 = 0;
    if ( v5 > 0 )
      break;
LABEL_7:
    if ( ++v3 >= num )
      return 0;
  }
  v7 = 0;
  while ( i->list[v7] != upgrade->decl )
  {
    ++v6;
    ++v7;
    if ( v6 >= v5 )
      goto LABEL_7;
  }
  return 1;
}


// ========================================================================
// ?IsUpgradeEquipped@idVehicleKey@@QBA_NPBVidDeclVehicleUpgrade@@@Z
// EA  : 0x82EBDC50
// RVA : 0x00EBDC50
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

int __fastcall idVehicleKey::IsUpgradeEquipped(idVehicleKey *this, const idDeclVehicleUpgrade *decl)
{
  int num; // r9
  int v3; // r10
  int i; // r11

  num = this->equippedUpgrades.num;
  v3 = 0;
  if ( num <= 0 )
    return 0;
  for ( i = 0; this->equippedUpgrades.list[i] != decl; ++i )
  {
    if ( ++v3 >= num )
      return 0;
  }
  return 1;
}


// ========================================================================
// ?GetUpgradeDef@idVehicleKey@@QBAPAVidDeclEntityDef@@H@Z
// EA  : 0x82EBDC98
// RVA : 0x00EBDC98
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

idDeclEntityDef *__fastcall idVehicleKey::GetUpgradeDef(idVehicleKey *this, const int index)
{
  return this->equippedUpgrades.list[index]->upgradedDef;
}


// ========================================================================
// ?RemoveArmorInfo@idVehicleKey@@QAAXPBVidDeclInventory@@@Z
// EA  : 0x82EBDCB0
// RVA : 0x00EBDCB0
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __fastcall idVehicleKey::RemoveArmorInfo(idVehicleKey *this, const idDeclInventory *decl)
{
  int num; // r7
  int v3; // r10
  int i; // r11
  int v5; // r11
  int v6; // r11
  int v7; // r9
  idVehicleKey::armorInfo_t *v8; // r11

  if ( decl->vehicleArmor )
  {
    num = this->armorInfo.num;
    v3 = 0;
    if ( num > 0 )
    {
      for ( i = 0; this->armorInfo.list[i].decl != decl; ++i )
      {
        if ( ++v3 >= num )
          return;
      }
      if ( v3 >= 0 )
      {
        v5 = this->armorInfo.num;
        if ( v3 < v5 )
        {
          v6 = v5 - 1;
          this->armorInfo.num = v6;
          if ( v3 < v6 )
          {
            v7 = v3;
            do
            {
              ++v3;
              v8 = &this->armorInfo.list[v7++];
              v8->decl = v8[1].decl;
              v8->health = v8[1].health;
            }
            while ( v3 < this->armorInfo.num );
          }
        }
      }
    }
  }
}


// ========================================================================
// ?SetMinValuesForGarage@idVehicleKey@@QAAXXZ
// EA  : 0x82EBDD50
// RVA : 0x00EBDD50
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __fastcall idVehicleKey::SetMinValuesForGarage(idVehicleKey *this)
{
  if ( this->health < (double)(float)(this->maxHealth * (float)0.25) && this->maxHealth > 0.0 )
    this->health = this->maxHealth * (float)0.25;
}


// ========================================================================
// ?Init@idPlayerArmor@@UAAXPBVidDeclInventory@@@Z
// EA  : 0x82EBDD88
// RVA : 0x00EBDD88
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __fastcall idPlayerArmor::Init(idPlayerArmor *this, const idDeclInventory *decl)
{
  this->decl = decl;
  this->count = decl->count;
  this->counttosave = -1;
  this->forSale = false;
  this->lootable = false;
  this->curArmorValue = *(float *)&decl[1].name.str;
}


// ========================================================================
// ?CanUse@idSecretItem@@UAA_NPAVidActor@@@Z
// EA  : 0x82EBDDB8
// RVA : 0x00EBDDB8
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

BOOL __fastcall idSecretItem::CanUse(idSecretItem *this, idPlayer *user)
{
  int SecretForEntity; // r3
  idPlayerProfileGame *v5; // r3
  signed int secretId; // r4

  if ( this->needSetup )
  {
    this->needSetup = false;
    SecretForEntity = idDeclSecrets::FindSecretForEntity(name: user->name.data);
    this->secretId = SecretForEntity;
    if ( SecretForEntity == -1 )
    {
      idLib::Warning(fmt: "Secret '%s' exists in the map but doesn't have a secret declaration", user->name.data);
    }
    else
    {
      v5 = (idPlayerProfileGame *)common->GetProfileFromMasterLocalUser(this: common);
      if ( v5 != nullptr )
      {
        secretId = this->secretId;
        if ( secretId >= 0 )
          idPlayerProfileGame::GetSecret(this: v5, secretId);
      }
    }
  }
  return idPlayer::CastTo(c: user) != nullptr;
}


// ========================================================================
// ?Activate@idVehicleQuickItem@@QAAXXZ
// EA  : 0x82EBDE68
// RVA : 0x00EBDE68
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __fastcall idVehicleQuickItem::Activate(idVehicleQuickItem *this)
{
  this->activateTime = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  this->active = true;
}


// ========================================================================
// ?GetCooldown@idVehicleQuickItem@@UBAHXZ
// EA  : 0x82EBDEB8
// RVA : 0x00EBDEB8
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

idResourceList *__fastcall idVehicleQuickItem::GetCooldown(idVehicleQuickItem *this)
{
  const idDeclInventory *decl; // r11

  decl = this->decl;
  if ( decl != nullptr )
    return decl[1].resourceListPtr;
  else
    return nullptr;
}


// ========================================================================
// ?Think@idVehicle_Shockwave@@UAAXPAVidPresentable@@@Z
// EA  : 0x82EBDED8
// RVA : 0x00EBDED8
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __fastcall idVehicle_Shockwave::Think(idVehicle_Shockwave *this, idPresentable *presentable)
{
  idClientServerInterface *csInterface; // r11

  if ( presentable != nullptr )
  {
    csInterface = presentable->csInterface;
    if ( csInterface != nullptr )
      csInterface->VehicleShockwaveThink(this: csInterface, a2: this, a3: presentable);
  }
}


// ========================================================================
// ?GetCooldown@idVehicle_Shockwave@@UBAHXZ
// EA  : 0x82EBDF10
// RVA : 0x00EBDF10
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

int __fastcall idVehicle_Shockwave::GetCooldown(idVehicle_Shockwave *this)
{
  return vehicle_shockwaveDuration.valueInteger;
}


// ========================================================================
// ?Think@idVehicle_Aftershocker@@UAAXPAVidPresentable@@@Z
// EA  : 0x82EBDF20
// RVA : 0x00EBDF20
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __fastcall idVehicle_Aftershocker::Think(idVehicle_Aftershocker *this, idPresentable *presentable)
{
  idClientServerInterface *csInterface; // r11

  if ( presentable != nullptr )
  {
    csInterface = presentable->csInterface;
    if ( csInterface != nullptr )
      csInterface->VehicleAftershockerThink(this: csInterface, a2: this, a3: presentable);
  }
}


// ========================================================================
// ?Think@idVehicle_Teleporter@@UAAXPAVidPresentable@@@Z
// EA  : 0x82EBDF58
// RVA : 0x00EBDF58
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __fastcall idVehicle_Teleporter::Think(idVehicle_Teleporter *this, idPresentable *presentable)
{
  idClientServerInterface *csInterface; // r11

  if ( presentable != nullptr )
  {
    csInterface = presentable->csInterface;
    if ( csInterface != nullptr )
      csInterface->VehicleTeleporterThink(this: csInterface, a2: this, a3: presentable);
  }
}


// ========================================================================
// ?Think@idVehicle_Jump@@UAAXPAVidPresentable@@@Z
// EA  : 0x82EBDF90
// RVA : 0x00EBDF90
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __fastcall idVehicle_Jump::Think(idVehicle_Jump *this, idPresentable *presentable)
{
  idClientServerInterface *csInterface; // r11

  if ( presentable != nullptr )
  {
    csInterface = presentable->csInterface;
    if ( csInterface != nullptr )
      csInterface->VehicleJumpThink(this: csInterface, a2: this, a3: presentable);
  }
}


// ========================================================================
// ?Think@idVehicle_Megabooster@@UAAXPAVidPresentable@@@Z
// EA  : 0x82EBDFC8
// RVA : 0x00EBDFC8
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __fastcall idVehicle_Megabooster::Think(idVehicle_Megabooster *this, idPresentable *presentable)
{
  idClientServerInterface *csInterface; // r11

  if ( presentable != nullptr )
  {
    csInterface = presentable->csInterface;
    if ( csInterface != nullptr )
      csInterface->VehicleMegaboosterThink(this: csInterface, a2: this, a3: presentable);
  }
}


// ========================================================================
// ?Think@idVehicle_Health@@UAAXPAVidPresentable@@@Z
// EA  : 0x82EBE000
// RVA : 0x00EBE000
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __fastcall idVehicle_Health::Think(idVehicle_Health *this, idPresentable *presentable)
{
  idClientServerInterface *csInterface; // r11

  if ( presentable != nullptr )
  {
    csInterface = presentable->csInterface;
    if ( csInterface != nullptr )
      csInterface->VehicleHealthThink(this: csInterface, a2: this, a3: presentable);
  }
}


// ========================================================================
// ?Think@idVehicle_Stomp@@UAAXPAVidPresentable@@@Z
// EA  : 0x82EBE038
// RVA : 0x00EBE038
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __fastcall idVehicle_Stomp::Think(idVehicle_Stomp *this, idPresentable *presentable)
{
  idClientServerInterface *csInterface; // r11

  if ( presentable != nullptr )
  {
    csInterface = presentable->csInterface;
    if ( csInterface != nullptr )
      csInterface->VehicleStompThink(this: csInterface, a2: this, a3: presentable);
  }
}


// ========================================================================
// ?Think@idVehicle_InstantDamage@@UAAXPAVidPresentable@@@Z
// EA  : 0x82EBE070
// RVA : 0x00EBE070
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __fastcall idVehicle_InstantDamage::Think(idVehicle_InstantDamage *this, idPresentable *presentable)
{
  idClientServerInterface *csInterface; // r11

  if ( presentable != nullptr )
  {
    csInterface = presentable->csInterface;
    if ( csInterface != nullptr )
      csInterface->VehicleInstantDamageThink(this: csInterface, a2: this, a3: presentable);
  }
}


// ========================================================================
// ?Think@idVehicle_QuickUseWeapon@@UAAXPAVidPresentable@@@Z
// EA  : 0x82EBE0A8
// RVA : 0x00EBE0A8
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __fastcall idVehicle_QuickUseWeapon::Think(idVehicle_QuickUseWeapon *this, idPresentable *presentable)
{
  idClientServerInterface *csInterface; // r11

  if ( presentable != nullptr )
  {
    csInterface = presentable->csInterface;
    if ( csInterface != nullptr )
      csInterface->VehicleQuickUseWeaponThink(this: csInterface, a2: this, a3: presentable);
  }
}


// ========================================================================
// ??0idClientServerInterfaceServer@@QAA@XZ
// EA  : 0x82EBE0E0
// RVA : 0x00EBE0E0
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

idClientServerInterfaceServer *__fastcall idClientServerInterfaceServer::idClientServerInterfaceServer(
        idClientServerInterfaceServer *this)
{
  this->entity = nullptr;
  this->__vftable = (idClientServerInterfaceServer_vtbl *)&idClientServerInterfaceServer::`vftable';
  return this;
}


// ========================================================================
// ?Init@idClientServerInterfaceServer@@UAA_NPAVidEntity@@@Z
// EA  : 0x82EBE0F8
// RVA : 0x00EBE0F8
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

int __fastcall idClientServerInterfaceServer::Init(idClientServerInterfaceServer *this, idEntity *e)
{
  if ( e == nullptr )
    return 0;
  this->entity = e;
  return 1;
}


// ========================================================================
// ?VehicleStompThink@idClientServerInterfaceServer@@UAAXPAVidInventoryItem@@PAVidPresentable@@@Z
// EA  : 0x82EBE118
// RVA : 0x00EBE118
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __fastcall idClientServerInterfaceServer::VehicleStompThink(
        idClientServerInterfaceServer *this,
        idVehicle_Stomp *item,
        idPresentable *presentable)
{
  idVehicleQuickItem *v6; // r3
  idVehicleQuickItem *v7; // r24
  idVehicle_Car *v8; // r3
  idEntity *v9; // r26
  idPhysics *Physics; // r31
  idVehicle_Stomp *v11; // r3
  idVehicle_Stomp *v12; // r27
  idPresentable *v13; // r3
  int v14; // r3
  idPresentable *v15; // r3
  const idDeclInventory *decl; // r28
  idPresentableVehicle *v17; // r3
  const idDeclDamage *trackedMemory; // r28
  idPlayer *DriverEntity; // r22
  const idVec3 *v20; // r3
  __int64 v21; // r10
  idPresentableVehicle *v22; // r28
  int GameMs; // r26
  idFXManager *PredictedFXMgr; // r3
  int v25; // r26
  const idMat3 *v26; // r25
  const idVec3 *v27; // r31
  idFXManager *v28; // r3

  v6 = idVehicleQuickItem::CastTo(c: item);
  v7 = v6;
  if ( v6 != nullptr && v6->active )
  {
    v8 = idVehicle_Car::CastTo(c: (idVehicle_Car *)this->entity);
    v9 = v8;
    if ( v8 != nullptr )
    {
      Physics = idEntity::GetPhysics(this: v8);
      if ( Physics != nullptr )
      {
        v11 = idVehicle_Stomp::CastTo(c: item);
        v12 = v11;
        if ( v11 != nullptr )
        {
          if ( !v11->hasFired )
          {
            if ( Physics->HasGroundContacts(this: Physics)
              || ((v13 = v9->presentable) == nullptr ? (v14 = 0) : (v14 = (int)v13->GetVehicleInterface(this: v13)),
                  *(int *)(v14 + 17752) >= 2) )
            {
              Physics->SetLinearVelocity(this: Physics, a2: &vec3_origin, a3: 0);
              v15 = v9->presentable;
              decl = v12->decl;
              if ( v15 != nullptr )
                v17 = v15->GetVehicleInterface(this: v15);
              else
                v17 = nullptr;
              trackedMemory = (const idDeclDamage *)decl[1].trackedMemory;
              DriverEntity = (idPlayer *)idPresentableVehicle::GetDriverEntity(this: v17);
              v20 = Physics->GetOrigin(this: Physics, a2: 0);
              HIDWORD(v21) = &idEventDef::eventDefList[3154];
              idGameLocal::RadiusDamage(
                this: gameLocal,
                origin: v20,
                inflictor: v9,
                attacker: DriverEntity,
                damageDef: trackedMemory,
                dmgPower: 1.0,
                a7: 0x82000000,
                a8: v21);
              v22 = presentable->GetVehicleInterface(this: presentable);
              GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
              PredictedFXMgr = idPresentableVehicle::GetPredictedFXMgr(this: v22);
              idFXManager::StopFX(this: PredictedFXMgr, time: GameMs, stopCondition: 13, immediateStop: false);
              v25 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
              v26 = Physics->GetAxis(this: Physics, a2: 0);
              v27 = Physics->GetOrigin(this: Physics, a2: 0);
              v28 = idPresentableVehicle::GetPredictedFXMgr(this: v22);
              idFXManager::StartFX(this: v28, org: v27, axis: v26, time: v25, startCondition: 14);
              v12->hasFired = true;
            }
          }
          if ( idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) >= (int)v7->decl[1].resourceListPtr + v7->activateTime )
          {
            v7->active = false;
            v12->hasFired = false;
          }
        }
      }
    }
  }
}


// ========================================================================
// ?VehicleBoostExtenderUse@idClientServerInterfaceClient@@UAA_NPAVidInventoryItem@@PAVidPresentable@@@Z
// EA  : 0x82EBE370
// RVA : 0x00EBE370
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

int __fastcall idClientServerInterfaceClient::VehicleBoostExtenderUse(
        idClientServerInterfaceClient *this,
        idVehicle_BoostExtender *item,
        idPresentable *presentable)
{
  idVehicle_BoostExtender *v4; // r30
  idPresentableVehicle *v6; // r3

  v4 = idVehicle_BoostExtender::CastTo(c: item);
  if ( v4 == nullptr )
    return 0;
  v6 = presentable->GetVehicleInterface(this: presentable);
  if ( v6 == nullptr )
    return 0;
  v4->cooldown = vehicle_online_boostExtenderCooldown.valueInteger;
  idPresentableVehicle::TriggerBoostExtender(this: v6);
  return 1;
}


// ========================================================================
// ?VehicleSmashUse@idClientServerInterfaceClient@@UAA_NPAVidInventoryItem@@PAVidPresentable@@@Z
// EA  : 0x82EBE3F0
// RVA : 0x00EBE3F0
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

int __fastcall idClientServerInterfaceClient::VehicleSmashUse(
        idClientServerInterfaceClient *this,
        idVehicle_Smash *item,
        idPresentable *presentable)
{
  idVehicle_Smash *v4; // r30
  idPresentableVehicle *v6; // r3

  v4 = idVehicle_Smash::CastTo(c: item);
  if ( v4 == nullptr )
    return 0;
  v6 = presentable->GetVehicleInterface(this: presentable);
  if ( v6 == nullptr )
    return 0;
  v4->cooldown = vehicle_online_smashDuration.valueInteger;
  idPresentableVehicle::TriggerSmashActive(this: v6);
  return 1;
}


// ========================================================================
// ?VehicleShockwaveThink@idClientServerInterfaceClient@@UAAXPAVidInventoryItem@@PAVidPresentable@@@Z
// EA  : 0x82EBE470
// RVA : 0x00EBE470
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __fastcall idClientServerInterfaceClient::VehicleShockwaveThink(
        idClientServerInterfaceClient *this,
        idVehicle_Shockwave *item,
        idPresentable *presentable)
{
  idVehicleQuickItem *v5; // r3
  idVehicleQuickItem *v6; // r29
  idPresentableVehicle *v7; // r3
  idPresentableVehicle *v8; // r28
  idVehicle_Shockwave *v9; // r27
  int GameMs; // r26
  idFXManager *PredictedFXMgr; // r3

  v5 = idVehicleQuickItem::CastTo(c: item);
  v6 = v5;
  if ( v5 != nullptr && v5->active )
  {
    v7 = presentable->GetVehicleInterface(this: presentable);
    v8 = v7;
    if ( v7 != nullptr && v7 != (idPresentableVehicle *)-16512 )
    {
      v9 = idVehicle_Shockwave::CastTo(c: item);
      if ( v9 != nullptr )
      {
        if ( idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) >= v6->activateTime + vehicle_shockwaveDuration.valueInteger )
        {
          GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
          PredictedFXMgr = idPresentableVehicle::GetPredictedFXMgr(this: v8);
          idFXManager::StopFX(this: PredictedFXMgr, time: GameMs, stopCondition: 16, immediateStop: false);
          v8->StopSound_Predicted(this: &v8->idPresentableAnimatedEntity, a2: SND_CHANNEL_ITEM);
          v6->active = false;
        }
        v9->lastThinkTime = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      }
    }
  }
}


// ========================================================================
// ?VehicleShockwaveUse@idClientServerInterfaceClient@@UAA_NPAVidInventoryItem@@PAVidPresentable@@@Z
// EA  : 0x82EBE580
// RVA : 0x00EBE580
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

int __fastcall idClientServerInterfaceClient::VehicleShockwaveUse(
        idClientServerInterfaceClient *this,
        idVehicle_Shockwave *item,
        idPresentable *presentable)
{
  idVehicleQuickItem *v5; // r29
  idPresentableVehicle *v6; // r3
  idPresentableVehicle *v7; // r30
  idPhysics_AF *p_physicsObj; // r31
  idVehicle_Shockwave *v9; // r3
  int activateTime; // r29
  const idMat3 *v12; // r28
  const idVec3 *v13; // r31
  idFXManager *PredictedFXMgr; // r3

  v5 = idVehicleQuickItem::CastTo(c: item);
  if ( v5 == nullptr )
    return 0;
  v6 = presentable->GetVehicleInterface(this: presentable);
  v7 = v6;
  if ( v6 == nullptr )
    return 0;
  p_physicsObj = &v6->physicsObj;
  if ( v6 == (idPresentableVehicle *)-16512 )
    return 0;
  v9 = idVehicle_Shockwave::CastTo(c: item);
  if ( v9 == nullptr )
    return 0;
  if ( *(float *)&v9->decl[1].name.str < 0.0 )
  {
    idLib::Warning(fmt: "Shockwave must have damagePerSecond.");
    return 0;
  }
  v9->lastThinkTime = v5->activateTime;
  activateTime = v5->activateTime;
  v12 = p_physicsObj->GetAxis(this: p_physicsObj, a2: 0);
  v13 = p_physicsObj->GetOrigin(this: p_physicsObj, a2: 0);
  PredictedFXMgr = idPresentableVehicle::GetPredictedFXMgr(this: v7);
  idFXManager::StartFX(this: PredictedFXMgr, org: v13, axis: v12, time: activateTime, startCondition: 15);
  return 1;
}


// ========================================================================
// ?VehicleAftershockerThink@idClientServerInterfaceClient@@UAAXPAVidInventoryItem@@PAVidPresentable@@@Z
// EA  : 0x82EBE680
// RVA : 0x00EBE680
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __fastcall idClientServerInterfaceClient::VehicleAftershockerThink(
        idClientServerInterfaceClient *this,
        idVehicleQuickItem *item,
        idPresentable *presentable)
{
  idVehicleQuickItem *v4; // r29
  idPresentableVehicle *v5; // r28
  int GameMs; // r31
  idFXManager *PredictedFXMgr; // r3

  v4 = idVehicleQuickItem::CastTo(c: item);
  if ( v4 != nullptr )
  {
    v5 = presentable->GetVehicleInterface(this: presentable);
    if ( v5 != nullptr
      && idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) >= v4->activateTime + vehicle_aftershockerDuration.valueInteger )
    {
      GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      PredictedFXMgr = idPresentableVehicle::GetPredictedFXMgr(this: v5);
      idFXManager::StopFX(this: PredictedFXMgr, time: GameMs, stopCondition: 18, immediateStop: false);
      v4->active = false;
    }
  }
}


// ========================================================================
// ?VehicleAftershockerUse@idClientServerInterfaceClient@@UAA_NPAVidInventoryItem@@PAVidPresentable@@@Z
// EA  : 0x82EBE738
// RVA : 0x00EBE738
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

int __fastcall idClientServerInterfaceClient::VehicleAftershockerUse(
        idClientServerInterfaceClient *this,
        idVehicleQuickItem *item,
        idPresentable *presentable)
{
  idPresentableVehicle *v5; // r3
  idPresentableVehicle *v6; // r30
  idPhysics_AF *p_physicsObj; // r31
  int GameMs; // r29
  const idMat3 *v9; // r28
  const idVec3 *v10; // r31
  idFXManager *PredictedFXMgr; // r3

  if ( idVehicleQuickItem::CastTo(c: item) == nullptr )
    return 0;
  v5 = presentable->GetVehicleInterface(this: presentable);
  v6 = v5;
  if ( v5 == nullptr )
    return 0;
  p_physicsObj = &v5->physicsObj;
  if ( v5 == (idPresentableVehicle *)-16512 )
    return 0;
  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  v9 = p_physicsObj->GetAxis(this: p_physicsObj, a2: 0);
  v10 = p_physicsObj->GetOrigin(this: p_physicsObj, a2: 0);
  PredictedFXMgr = idPresentableVehicle::GetPredictedFXMgr(this: v6);
  idFXManager::StartFX(this: PredictedFXMgr, org: v10, axis: v9, time: GameMs, startCondition: 17);
  return 1;
}


// ========================================================================
// ?VehicleTeleporterUse@idClientServerInterfaceClient@@UAA_NPAVidInventoryItem@@PAVidPresentable@@@Z
// EA  : 0x82EBE808
// RVA : 0x00EBE808
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

int __fastcall idClientServerInterfaceClient::VehicleTeleporterUse(
        idClientServerInterfaceClient *this,
        idVehicle_Teleporter *item,
        idPresentable *presentable)
{
  idPresentableVehicle *v6; // r3
  idPresentableVehicle *v7; // r30
  idPhysics_AF *p_physicsObj; // r29
  idVehicle_Teleporter *v9; // r3
  idVehicle_Teleporter *v10; // r31
  int GameMs; // r26
  const idMat3 *v12; // r25
  const idVec3 *v13; // r24
  idFXManager *PredictedFXMgr; // r3
  idPhysics_AF_vtbl *v15; // r6
  void (__fastcall *SetAngularVelocity)(struct idPhysics_AF *, const idVec3 *, int); // r11
  int v17; // r28
  idFXManager *v18; // r3
  float *v19; // r3
  const idMat3 *(__fastcall *GetAxis)(struct idPhysics_AF *, int); // r7
  float *v21; // r3
  idPhysics_AF_vtbl *v22; // r11
  idVec3 *(__fastcall *GetAngularVelocity)(struct idPhysics_AF *, idVec3 *, int); // r10
  float *v24; // r3
  idPhysics_AF_vtbl *v25; // r8
  idVec3 *(__fastcall *GetLinearVelocity)(struct idPhysics_AF *, idVec3 *, int); // r7
  float *v27; // r3
  idClientGame *v28; // r11
  int v29; // r29
  idFXManager *v30; // r3
  char v31; // [sp+50h] [-70h] BYREF
  char v32; // [sp+60h] [-60h] BYREF

  if ( idVehicleQuickItem::CastTo(c: item) == nullptr )
    return 0;
  v6 = presentable->GetVehicleInterface(this: presentable);
  v7 = v6;
  if ( v6 == nullptr )
    return 0;
  p_physicsObj = &v6->physicsObj;
  if ( v6 == (idPresentableVehicle *)-16512 )
    return 0;
  v9 = idVehicle_Teleporter::CastTo(c: item);
  v10 = v9;
  if ( v9 == nullptr )
    return 0;
  if ( v9->teleporterPlaced )
  {
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    v12 = p_physicsObj->GetAxis(this: p_physicsObj, a2: 0);
    v13 = p_physicsObj->GetOrigin(this: p_physicsObj, a2: 0);
    PredictedFXMgr = idPresentableVehicle::GetPredictedFXMgr(this: v7);
    idFXManager::StartFX(this: PredictedFXMgr, org: v13, axis: v12, time: GameMs, startCondition: 9);
    v7->origin.x = v10->location.x;
    v15 = p_physicsObj->__vftable;
    v7->origin.y = v10->location.y;
    SetAngularVelocity = v15->SetAngularVelocity;
    v7->origin.z = v10->location.z;
    v7->axis.mat[0].x = v10->orientation.mat[0].x;
    v7->axis.mat[0].y = v10->orientation.mat[0].y;
    v7->axis.mat[0].z = v10->orientation.mat[0].z;
    v7->axis.mat[1].x = v10->orientation.mat[1].x;
    v7->axis.mat[1].y = v10->orientation.mat[1].y;
    v7->axis.mat[1].z = v10->orientation.mat[1].z;
    v7->axis.mat[2].x = v10->orientation.mat[2].x;
    v7->axis.mat[2].y = v10->orientation.mat[2].y;
    v7->axis.mat[2].z = v10->orientation.mat[2].z;
    SetAngularVelocity(this: p_physicsObj, a2: &v10->angularVel, a3: 0);
    p_physicsObj->SetLinearVelocity(this: p_physicsObj, a2: &v10->linearVel, a3: 0);
    v10->teleporterPlaced = false;
    v17 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    v18 = idPresentableVehicle::GetPredictedFXMgr(this: v7);
    idFXManager::StopFX(this: v18, time: v17, stopCondition: 11, immediateStop: false);
    v10->active = false;
    return 0;
  }
  else
  {
    v19 = (float *)p_physicsObj->GetOrigin(this: p_physicsObj, a2: 0);
    GetAxis = p_physicsObj->GetAxis;
    v10->location.x = *v19;
    v10->location.y = v19[1];
    v10->location.z = v19[2];
    v21 = (float *)GetAxis(this: p_physicsObj, a2: 0);
    v22 = p_physicsObj->__vftable;
    v10->orientation.mat[0].x = *v21;
    GetAngularVelocity = v22->GetAngularVelocity;
    v10->orientation.mat[0].y = v21[1];
    v10->orientation.mat[0].z = v21[2];
    v10->orientation.mat[1].x = v21[3];
    v10->orientation.mat[1].y = v21[4];
    v10->orientation.mat[1].z = v21[5];
    v10->orientation.mat[2].x = v21[6];
    v10->orientation.mat[2].y = v21[7];
    v10->orientation.mat[2].z = v21[8];
    v24 = (float *)GetAngularVelocity(this: (struct idPhysics_AF *)&v31, result: (idVec3 *)p_physicsObj, a3: 0);
    v25 = p_physicsObj->__vftable;
    v10->angularVel.x = *v24;
    GetLinearVelocity = v25->GetLinearVelocity;
    v10->angularVel.y = v24[1];
    v10->angularVel.z = v24[2];
    v27 = (float *)GetLinearVelocity(this: (struct idPhysics_AF *)&v32, result: (idVec3 *)p_physicsObj, a3: 0);
    v10->linearVel.x = *v27;
    v10->linearVel.y = v27[1];
    v28 = clientGame;
    v10->linearVel.z = v27[2];
    v29 = idGameTimeManager::GetGameMs(this: &v28->gameTimeManager, type: GAMETIME_SCALED);
    v30 = idPresentableVehicle::GetPredictedFXMgr(this: v7);
    idFXManager::StartFX(this: v30, org: &v10->location, axis: &v10->orientation, time: v29, startCondition: 11);
    v10->teleporterPlaced = true;
    return 1;
  }
}


// ========================================================================
// ?VehicleTeleporterThink@idClientServerInterfaceClient@@UAAXPAVidInventoryItem@@PAVidPresentable@@@Z
// EA  : 0x82EBEB30
// RVA : 0x00EBEB30
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __fastcall idClientServerInterfaceClient::VehicleTeleporterThink(
        idClientServerInterfaceClient *this,
        idVehicle_Teleporter *item,
        idPresentable *presentable)
{
  idVehicleQuickItem *v5; // r3
  idVehicleQuickItem *v6; // r29
  idPresentableVehicle *v7; // r27
  idVehicle_Teleporter *v8; // r28
  int GameMs; // r31
  idFXManager *PredictedFXMgr; // r3

  v5 = idVehicleQuickItem::CastTo(c: item);
  v6 = v5;
  if ( v5 != nullptr && v5->active )
  {
    v7 = presentable->GetVehicleInterface(this: presentable);
    if ( v7 != nullptr )
    {
      v8 = idVehicle_Teleporter::CastTo(c: item);
      if ( v8 != nullptr
        && idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) >= v6->activateTime + 30000 )
      {
        idLib::Printf(fmt: "Teleporter timed out\n");
        GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        PredictedFXMgr = idPresentableVehicle::GetPredictedFXMgr(this: v7);
        idFXManager::StopFX(this: PredictedFXMgr, time: GameMs, stopCondition: 11, immediateStop: false);
        v8->teleporterPlaced = false;
        v6->active = false;
      }
    }
  }
}


// ========================================================================
// ?VehicleJumpUse@idClientServerInterfaceClient@@UAA_NPAVidInventoryItem@@PAVidPresentable@@@Z
// EA  : 0x82EBEC10
// RVA : 0x00EBEC10
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

int __fastcall idClientServerInterfaceClient::VehicleJumpUse(
        idClientServerInterfaceClient *this,
        idVehicleQuickItem *item,
        idPresentable *presentable)
{
  idPresentableVehicle *v5; // r3
  const idDeclVehicleProps *vehicleProps; // r30
  idPhysics_AF *p_physicsObj; // r31
  int v8; // r3
  float v9; // r6
  float v10; // r5
  const idMat3 *(__fastcall *GetAxis)(struct idPhysics_AF *, int); // r11
  _DWORD *v12; // r3
  float v13; // r7
  float v14; // r6
  float *v15; // r3
  double jumpImpulse; // fp11
  double v17; // fp9
  idPhysics_AF_vtbl *v18; // r30
  int v19; // r3
  float v20; // [sp+50h] [-50h] BYREF
  float v21; // [sp+54h] [-4Ch] BYREF
  float v22; // [sp+58h] [-48h] BYREF
  float v23; // [sp+5Ch] [-44h]
  float v24; // [sp+60h] [-40h]
  float v25; // [sp+68h] [-38h]
  float v26; // [sp+6Ch] [-34h]
  float v27; // [sp+70h] [-30h]
  float v28; // [sp+78h] [-28h]
  float v29; // [sp+7Ch] [-24h]
  float v30; // [sp+80h] [-20h]

  if ( idVehicleQuickItem::CastTo(c: item) == nullptr )
    return 0;
  v5 = presentable->GetVehicleInterface(this: presentable);
  if ( v5 == nullptr )
    return 0;
  vehicleProps = v5->vehicleProps;
  if ( vehicleProps == nullptr )
    return 0;
  p_physicsObj = &v5->physicsObj;
  if ( v5 == (idPresentableVehicle *)-16512 )
    return 0;
  v8 = (int)p_physicsObj->GetAxis(this: &v5->physicsObj, a2: 0);
  v9 = *(float *)(v8 + 4);
  v10 = *(float *)(v8 + 8);
  GetAxis = p_physicsObj->GetAxis;
  v28 = *(float *)v8;
  v29 = v9;
  v30 = v10;
  v12 = (_DWORD *)GetAxis(this: p_physicsObj, a2: 0);
  v13 = *((float *)v12 + 6);
  v14 = *((float *)v12 + 7);
  v15 = *((float **)v12 + 8);
  v25 = v13;
  v26 = v14;
  v27 = *(float *)&v15;
  idMath::SinCos16(a: (float)(vehicle_jump_angle.valueFloat * idMath::M_DEG2RAD), s: v15, c: &v20, a4: &v21);
  v22 = (float)(v28 * v21) + (float)(v25 * v20);
  v23 = (float)(v29 * v21) + (float)(v26 * v20);
  v24 = (float)(v30 * v21) + (float)(v27 * v20);
  jumpImpulse = vehicleProps->jumpImpulse;
  v17 = (float)(v23 * vehicleProps->jumpImpulse);
  v22 = v22 * vehicleProps->jumpImpulse;
  v23 = v17;
  v24 = v24 * (float)jumpImpulse;
  v18 = p_physicsObj->__vftable;
  v19 = (int)p_physicsObj->GetOrigin(this: p_physicsObj, a2: 0);
  v18->ApplyImpulse(this: p_physicsObj, a2: 0, a3: (const idVec3 *)v19, a4: (const idVec3 *)&v22);
  return 1;
}


// ========================================================================
// ?VehicleMegaboosterUse@idClientServerInterfaceClient@@UAA_NPAVidVehicle_Megabooster@@PAVidPresentable@@@Z
// EA  : 0x82EBEDB8
// RVA : 0x00EBEDB8
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

int __fastcall idClientServerInterfaceClient::VehicleMegaboosterUse(
        idClientServerInterfaceClient *this,
        idVehicle_Megabooster *item,
        idPresentable *presentable)
{
  idPresentableVehicle *v4; // r3
  idPresentableVehicle *v5; // r30
  idPhysics_AF *p_physicsObj; // r31
  int GameMs; // r29
  const idMat3 *v8; // r28
  const idVec3 *v9; // r31
  idFXManager *PredictedFXMgr; // r3

  if ( item == nullptr )
    return 0;
  v4 = presentable->GetVehicleInterface(this: presentable);
  v5 = v4;
  if ( v4 == nullptr )
    return 0;
  p_physicsObj = &v4->physicsObj;
  if ( v4 == (idPresentableVehicle *)-16512
    || v4->IsLocallyControlled(this: &v4->idPresentableAnimatedEntity) && v5->numWheelsOnGround < 2 )
  {
    return 0;
  }
  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  v8 = p_physicsObj->GetAxis(this: p_physicsObj, a2: 0);
  v9 = p_physicsObj->GetOrigin(this: p_physicsObj, a2: 0);
  PredictedFXMgr = idPresentableVehicle::GetPredictedFXMgr(this: v5);
  idFXManager::StartFX(this: PredictedFXMgr, org: v9, axis: v8, time: GameMs, startCondition: 9);
  return 1;
}


// ========================================================================
// ?VehicleMegaboosterThink@idClientServerInterfaceClient@@UAAXPAVidVehicle_Megabooster@@PAVidPresentable@@@Z
// EA  : 0x82EBEEA8
// RVA : 0x00EBEEA8
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __fastcall idClientServerInterfaceClient::VehicleMegaboosterThink(
        idClientServerInterfaceClient *this,
        idVehicle_Megabooster *item,
        idPresentable *presentable)
{
  idPresentableVehicle *v4; // r3

  if ( item != nullptr && item->active )
  {
    v4 = presentable->GetVehicleInterface(this: presentable);
    if ( v4 != nullptr && v4 != (idPresentableVehicle *)-16512 )
    {
      if ( v4->accelerating )
        idPresentableVehicle::BoostForce(this: v4, f: item->acceleration);
      if ( idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) >= item->time + item->activateTime )
        item->active = false;
    }
  }
}


// ========================================================================
// ?VehicleHealthUse@idClientServerInterfaceClient@@UAA_NPAVidInventoryItem@@PAVidPresentable@@@Z
// EA  : 0x82EBEF50
// RVA : 0x00EBEF50
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

int __fastcall idClientServerInterfaceClient::VehicleHealthUse(
        idClientServerInterfaceClient *this,
        idVehicleQuickItem *item,
        idPresentable *presentable)
{
  idPresentableVehicle *v5; // r3

  if ( idVehicleQuickItem::CastTo(c: item) != nullptr
    && (v5 = presentable->GetVehicleInterface(this: presentable)) != nullptr )
  {
    return 16512 - ((&v5->physicsObj == nullptr) + 16511);
  }
  else
  {
    return 0;
  }
}


// ========================================================================
// ?VehicleInstantDamageThink@idClientServerInterfaceClient@@UAAXPAVidInventoryItem@@PAVidPresentable@@@Z
// EA  : 0x82EBEFC8
// RVA : 0x00EBEFC8
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __fastcall idClientServerInterfaceClient::VehicleInstantDamageThink(
        idClientServerInterfaceClient *this,
        idVehicleQuickItem *item,
        idPresentable *presentable)
{
  idVehicleQuickItem *v3; // r3
  idVehicleQuickItem *v4; // r31

  v3 = idVehicleQuickItem::CastTo(c: item);
  v4 = v3;
  if ( v3 != nullptr
    && v3->active
    && idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) >= (int)v3->decl[1].resourceListPtr
                                                                                                + v3->activateTime )
  {
    v4->active = false;
  }
}


// ========================================================================
// ?VehicleStompUse@idClientServerInterfaceClient@@UAA_NPAVidInventoryItem@@PAVidPresentable@@@Z
// EA  : 0x82EBF048
// RVA : 0x00EBF048
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

int __fastcall idClientServerInterfaceClient::VehicleStompUse(
        idClientServerInterfaceClient *this,
        idVehicleQuickItem *item,
        idPresentable *presentable)
{
  idPresentableVehicle *v5; // r3
  idPresentableVehicle *v6; // r30
  idPhysics_AF *p_physicsObj; // r31
  idPhysics_AF_vtbl *v8; // r29
  int v9; // r3
  int GameMs; // r29
  const idMat3 *v11; // r28
  const idVec3 *v12; // r31
  idFXManager *PredictedFXMgr; // r3
  float v14[16]; // [sp+50h] [-40h] BYREF

  if ( idVehicleQuickItem::CastTo(c: item) == nullptr )
    return 0;
  v5 = presentable->GetVehicleInterface(this: presentable);
  v6 = v5;
  if ( v5 == nullptr )
    return 0;
  p_physicsObj = &v5->physicsObj;
  if ( v5 == (idPresentableVehicle *)-16512 )
    return 0;
  p_physicsObj->SetLinearVelocity(this: &v5->physicsObj, a2: &vec3_origin, a3: 0);
  v14[0] = 0.0;
  v14[1] = 0.0;
  v14[2] = vehicle_stomp_verticalImpulse.valueFloat;
  v8 = p_physicsObj->__vftable;
  v9 = (int)p_physicsObj->GetOrigin(this: p_physicsObj, a2: 0);
  v8->ApplyImpulse(this: p_physicsObj, a2: 0, a3: (const idVec3 *)v9, a4: (const idVec3 *)v14);
  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  v11 = p_physicsObj->GetAxis(this: p_physicsObj, a2: 0);
  v12 = p_physicsObj->GetOrigin(this: p_physicsObj, a2: 0);
  PredictedFXMgr = idPresentableVehicle::GetPredictedFXMgr(this: v6);
  idFXManager::StartFX(this: PredictedFXMgr, org: v12, axis: v11, time: GameMs, startCondition: 12);
  return 1;
}


// ========================================================================
// ?VehicleStompThink@idClientServerInterfaceClient@@UAAXPAVidInventoryItem@@PAVidPresentable@@@Z
// EA  : 0x82EBF190
// RVA : 0x00EBF190
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __fastcall idClientServerInterfaceClient::VehicleStompThink(
        idClientServerInterfaceClient *this,
        idVehicle_Stomp *item,
        idPresentable *presentable)
{
  idVehicleQuickItem *v5; // r3
  idVehicleQuickItem *v6; // r26
  idPresentableVehicle *v7; // r3
  idPresentableVehicle *v8; // r28
  idPhysics_AF *p_physicsObj; // r31
  idVehicle_Stomp *v10; // r3
  idVehicle_Stomp *v11; // r27
  int GameMs; // r25
  idFXManager *PredictedFXMgr; // r3
  int v14; // r25
  const idMat3 *v15; // r24
  const idVec3 *v16; // r31
  idFXManager *v17; // r3

  v5 = idVehicleQuickItem::CastTo(c: item);
  v6 = v5;
  if ( v5 != nullptr && v5->active )
  {
    v7 = presentable->GetVehicleInterface(this: presentable);
    v8 = v7;
    if ( v7 != nullptr )
    {
      p_physicsObj = &v7->physicsObj;
      if ( v7 != (idPresentableVehicle *)-16512 )
      {
        v10 = idVehicle_Stomp::CastTo(c: item);
        v11 = v10;
        if ( v10 != nullptr )
        {
          if ( !v10->hasFired && (p_physicsObj->HasGroundContacts(this: p_physicsObj) || v8->numWheelsOnGround >= 2) )
          {
            p_physicsObj->SetLinearVelocity(this: p_physicsObj, a2: &vec3_origin, a3: 0);
            GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
            PredictedFXMgr = idPresentableVehicle::GetPredictedFXMgr(this: v8);
            idFXManager::StopFX(this: PredictedFXMgr, time: GameMs, stopCondition: 13, immediateStop: false);
            v14 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
            v15 = p_physicsObj->GetAxis(this: p_physicsObj, a2: 0);
            v16 = p_physicsObj->GetOrigin(this: p_physicsObj, a2: 0);
            v17 = idPresentableVehicle::GetPredictedFXMgr(this: v8);
            idFXManager::StartFX(this: v17, org: v16, axis: v15, time: v14, startCondition: 14);
            v11->hasFired = true;
          }
          if ( idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) >= (int)v6->decl[1].resourceListPtr + v6->activateTime )
          {
            v6->active = false;
            v11->hasFired = false;
          }
        }
      }
    }
  }
}


// ========================================================================
// ?VehicleQuickUseWeaponThink@idClientServerInterfaceClient@@UAAXPAVidInventoryItem@@PAVidPresentable@@@Z
// EA  : 0x82EBF340
// RVA : 0x00EBF340
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __fastcall idClientServerInterfaceClient::VehicleQuickUseWeaponThink(
        idClientServerInterfaceClient *this,
        idVehicleQuickItem *item,
        idPresentable *presentable)
{
  idVehicleQuickItem *v3; // r3
  idVehicleQuickItem *v4; // r31
  int GameMs; // r30

  v3 = idVehicleQuickItem::CastTo(c: item);
  v4 = v3;
  if ( v3 != nullptr && v3->active )
  {
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    if ( GameMs >= v4->GetCooldown(this: v4) + v4->activateTime )
      v4->active = false;
  }
}


// ========================================================================
// ?VehicleInstantDamageUse@idClientServerInterfaceClient@@UAA_NPAVidInventoryItem@@PAVidPresentable@@@Z
// EA  : 0x82EBF3D8
// RVA : 0x00EBF3D8
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

int __fastcall idClientServerInterfaceClient::VehicleInstantDamageUse(
        idClientServerInterfaceClient *this,
        idVehicle_InstantDamage *item,
        idPresentable *presentable)
{
  idPresentableVehicle *v4; // r3
  idPresentableVehicle *v5; // r30
  idPhysics_AF *p_physicsObj; // r31
  idVehicle_InstantDamage *v8; // r3
  const idDeclInventory *decl; // r29
  int GameMs; // r28
  int nextOnHashChain; // r29
  const idMat3 *v12; // r27
  const idVec3 *v13; // r31
  idFXManager *PredictedFXMgr; // r3

  v4 = presentable->GetVehicleInterface(this: presentable);
  v5 = v4;
  if ( v4 == nullptr )
    return 0;
  p_physicsObj = &v4->physicsObj;
  if ( v4 == (idPresentableVehicle *)-16512 )
    return 0;
  v8 = idVehicle_InstantDamage::CastTo(c: item);
  if ( v8 == nullptr )
    return 0;
  decl = v8->decl;
  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  nextOnHashChain = (int)decl[1].nextOnHashChain;
  v12 = p_physicsObj->GetAxis(this: &v5->physicsObj, a2: 0);
  v13 = p_physicsObj->GetOrigin(this: &v5->physicsObj, a2: 0);
  PredictedFXMgr = idPresentableVehicle::GetPredictedFXMgr(this: v5);
  idFXManager::StartFX(this: PredictedFXMgr, org: v13, axis: v12, time: GameMs, startCondition: nextOnHashChain);
  return 1;
}


// ========================================================================
// ?OnClone@idInventoryItem@@UAAXPBV1@@Z
// EA  : 0x82EBF520
// RVA : 0x00EBF520
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __fastcall idInventoryItem::OnClone(idInventoryItem *this, idInventoryItem *fromItem)
{
  int v4; // r3

  v4 = fromItem->GetCount(this: fromItem);
  idInventoryItem::SetCount(this, amount: v4);
  this->quickSlot = fromItem->quickSlot;
}


// ========================================================================
// ?ClientUse@idInventoryItem@@UAA_NPAVidPresentablePlayer@@@Z
// EA  : 0x82EBF580
// RVA : 0x00EBF580
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

int __fastcall idInventoryItem::ClientUse(idInventoryItem *this, idPresentablePlayer *player)
{
  int result; // r3
  const idDeclInventory *decl; // r11
  const idSoundShader *useSound; // r5
  const idVec3 *v7; // r3
  double x; // fp31
  double y; // fp30
  double z; // fp29
  int entityNumber; // r9
  bool v12; // r25
  idClientGame *v13; // r31
  idVec3 *v14; // r10
  int v15; // ctr
  float *p_z; // r11
  idColor *v17; // r27
  idRenderWorld *renderWorld; // r31
  idRenderWorld_vtbl *v19; // r24
  idMat3 *v20; // r3
  idColor *v21; // r4
  idMat3 v22; // [sp+50h] [-190h] BYREF
  idVec3 v23; // [sp+78h] [-168h] BYREF
  idVec3 v24[2]; // [sp+88h] [-158h] BYREF
  idMat3 v25; // [sp+A0h] [-140h] BYREF
  idVec3 v26[4]; // [sp+D0h] [-110h] BYREF
  trace_t v27; // [sp+100h] [-E0h] BYREF

  if ( player == nullptr )
    return 0;
  decl = this->decl;
  if ( decl != nullptr )
  {
    useSound = decl->useSound;
    if ( useSound != nullptr )
      idPresentablePlayer::PlayLocalSound(
        this: player,
        channel: SND_CHANNEL_ITEM,
        shader: useSound,
        soundShaderFlags: (soundShaderFlags_t)0);
  }
  if ( !this->decl->dropable )
    return 1;
  if ( (unsigned __int8)idPlayer::IsOnLadder(this: (idPlayer *)player->entity) != 0 )
    return 0;
  idPresentablePlayer::GetViewTransform(this: player, origin: &v23, axis: &v25);
  v7 = player->physicsObj.GetOrigin(this: &player->physicsObj, a2: 0);
  x = v7->x;
  v23.x = v7->x;
  y = v7->y;
  v23.y = v7->y;
  z = v7->z;
  v23.z = v7->z;
  v22.mat[0] = v25.mat[0];
  idVec3::ProjectOntoPlane(this: v22.mat, normal: &vec3_up, overBounce: 1.0);
  idVec3::NormalizeFast(this: v22.mat);
  entityNumber = player->entityNumber;
  v24[0].x = (float)(g_clientDrop_Dist.valueFloat * v22.mat[0].x) + (float)x;
  v24[0].y = (float)(v22.mat[0].y * g_clientDrop_Dist.valueFloat) + (float)y;
  v24[0].z = (float)(v22.mat[0].z * g_clientDrop_Dist.valueFloat) + (float)z;
  v12 = idClip::TraceBounds(
          this: &clientGame->clip,
          result: &v27,
          start: &v23,
          end: v24,
          trm: clientGame->clip.clip32x32x96,
          clipMask: 1,
          passEntityNumber: entityNumber);
  if ( g_clientDrop_debug.valueInteger != 0 )
  {
    v13 = clientGame;
    v14 = &v22.mat[1];
    v15 = 6;
    p_z = &clientGame->clip.clip32x32x96->axis.mat[2].z;
    do
    {
      ++p_z;
      v14 = (idVec3 *)((char *)v14 + 4);
      v14->x = *p_z;
      --v15;
    }
    while ( v15 != 0 );
    v22.mat[2].y = v22.mat[2].y + g_clientDrop_Dist.valueFloat;
    v22.mat[1].y = v22.mat[1].y + g_clientDrop_Dist.valueFloat;
    idBounds::AddBounds(this: (idBounds *)&v22.mat[1].y, a: &v13->clip.clip32x32x96->bounds);
    v17 = &idColor::colorRed;
    if ( !v12 )
      v17 = &idColor::colorGreen;
    renderWorld = v13->renderWorld;
    v19 = renderWorld->__vftable;
    v20 = idVec3::ToMat3(this: v26, result: &v22);
    v19->DebugOrientedBounds(
      this: renderWorld,
      a2: (const idVec4 *)v17,
      a3: (const idBounds *)&v22.mat[1].y,
      a4: &v23,
      a5: v20,
      a6: 10000,
      a7: false);
    v21 = &idColor::colorRed;
    if ( !v12 )
      v21 = &idColor::colorGreen;
    clientGame->renderWorld->DebugLine(
      this: clientGame->renderWorld,
      a2: (const idVec4 *)v21,
      a3: &v23,
      a4: v24,
      a5: 10000,
      a6: false);
  }
  result = 0;
  if ( !v12 )
    return 1;
  return result;
}


// ========================================================================
// ?CanUse@idHealthItem@@UAA_NPAVidActor@@@Z
// EA  : 0x82EBF838
// RVA : 0x00EBF838
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

// attributes: thunk
int __fastcall idHealthItem::CanUse(idHealthItem *this, const idEntity *user)
{
  return idHealthItem::CanUseForHealth(this, user);
}


// ========================================================================
// ?GetDeclThrowable@idThrowableItem@@QBAPBVidDeclThrowable@@XZ
// EA  : 0x82EBF840
// RVA : 0x00EBF840
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

const idDeclThrowable *__fastcall idThrowableItem::GetDeclThrowable(idThrowableItem *this)
{
  const idDeclInventory *decl; // r31

  decl = this->decl;
  return &idDeclThrowable::resourceList != decl->GetDeclInfo(this: decl) ? nullptr : (const idDeclThrowable *)decl;
}


// ========================================================================
// ?GetProjectileDef@idThrowableItem@@QBAPBVidDeclProjectile@@XZ
// EA  : 0x82EBF898
// RVA : 0x00EBF898
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

const idDeclProjectile *__fastcall idThrowableItem::GetProjectileDef(idThrowableItem *this)
{
  const idDeclInventory *decl; // r31
  int v2; // r4
  const idDeclProjectile *result; // r3

  decl = this->decl;
  v2 = (&idDeclThrowable::resourceList != decl->GetDeclInfo(this: decl)) - 1;
  if ( (v2 & (unsigned int)decl) == 0 )
    return nullptr;
  result = *(const idDeclProjectile **)((v2 & (unsigned int)decl) + 0x1F8);
  if ( result == nullptr )
    return nullptr;
  return result;
}


// ========================================================================
// ??0idWeapon@@QAA@XZ
// EA  : 0x82EBF910
// RVA : 0x00EBF910
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

idWeapon *__fastcall idWeapon::idWeapon(idWeapon *this)
{
  char v2; // r6
  float z; // r8

  idEventReceiver::idEventReceiver(this);
  this->decl = nullptr;
  this->count = 0;
  this->forSale = false;
  this->lootable = false;
  this->buyBackItem = false;
  this->alreadyDropped = false;
  this->quickSlot = -1;
  this->counttosave = -1;
  this->coolDownTime = 0;
  this->skinPreload = nullptr;
  this->ammoClip = nullptr;
  this->nextAmmo = nullptr;
  this->ammoClipSecondary = nullptr;
  this->ammoInClipToSave = -1;
  this->firingIntervalModifier = 1.0;
  this->fireHandle = 0x7FFFFFFF;
  this->__vftable = (idWeapon_vtbl *)&idWeapon::`vftable';
  this->dualWieldItem = nullptr;
  this->wasDualWielding = false;
  this->triggerState = TRIGGERSTATE_RELEASED;
  this->fireState = FIRESTATE_IDLE;
  this->weaponState = WEAPONSTATE_NORMAL;
  this->nextFireTime = 0;
  this->finishReloadTime = 0;
  this->burstCount = 0;
  this->tracerCount = 0;
  this->fireChannel = 6;
  this->quadFireChannel = 73;
  this->attackType = ATTACK_DEFAULT;
  this->loopingFireSoundList = nullptr;
  this->loopingFireSoundEntity.spawnId = 0;
  this->loopingFireEndSound = nullptr;
  this->loopStartSoundTime = 0;
  this->loopStopedGameTime = 0;
  this->loopingFireSoundInterval = 0;
  this->loopingFireSoundSkipEndOnEarlyRelease = false;
  this->pieceEmitterEntity = nullptr;
  idTracerManager::idTracerManager(this: &this->tracerManager);
  v2 = *((_BYTE *)this + 453);
  *((_BYTE *)this + 452) = 0;
  this->currentZoomLevel = 0;
  this->spinBarrelNextShootTime = 0;
  this->changeZoomLevelTime = 0.0;
  *((_BYTE *)this + 453) = v2 & 0xF | 0x10;
  this->barrelSpinSpeed = 0.0;
  this->barrelJointRotation.value = -1;
  this->barrelTotalSpin = 0.0;
  this->fullSpinThrottle = false;
  this->ribbonStart = vec3_origin;
  this->ribbonEnd.x = vec3_origin.x;
  this->ribbonEnd.y = vec3_origin.y;
  z = vec3_origin.z;
  this->ribbonStartTime = -1;
  this->lastDecalTime = -1;
  this->ribbonEnd.z = z;
  this->presentableWeapon.spawnId = 0;
  return this;
}


// ========================================================================
// __unwind$503491_0
// EA  : 0x82EBFA94
// RVA : 0x00EBFA94
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void _unwind_503491_0()
{
  int v0; // r12

  idInventoryItem::~idInventoryItem(this: *(idInventoryItem **)(v0 - 144 + 164));
}


// ========================================================================
// ?HideChamberedAmmo@idWeapon@@QAAXPAVidTreeAnimator@@@Z
// EA  : 0x82EBFAF0
// RVA : 0x00EBFAF0
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __fastcall idWeapon::HideChamberedAmmo(idWeapon *this, idTreeAnimator *animator)
{
  idAmmoItem *ammoClip; // r11
  const idDeclInventory *decl; // r30
  int v6; // r28
  int v7; // r31
  int MeshIndex; // r3
  idAmmoItem *ammoClipSecondary; // r11
  const idDeclInventory *v10; // r30
  int v11; // r28
  int v12; // r31
  int v13; // r3

  ammoClip = this->ammoClip;
  if ( ammoClip != nullptr )
  {
    decl = ammoClip->decl;
    if ( decl != nullptr )
    {
      v6 = 0;
      if ( *(int *)&decl[1].usable > 0 )
      {
        v7 = 0;
        do
        {
          MeshIndex = idTreeAnimator::GetMeshIndex(
                        this: animator,
                        meshName: *(const char **)((char *)&decl[1].boostEntityDef->trackedMemory + v7));
          if ( MeshIndex >= 0 )
            animator->meshVisibility.list[MeshIndex] = false;
          ++v6;
          v7 += 32;
        }
        while ( v6 < *(_DWORD *)&decl[1].usable );
      }
    }
  }
  ammoClipSecondary = this->ammoClipSecondary;
  if ( ammoClipSecondary != nullptr )
  {
    v10 = ammoClipSecondary->decl;
    if ( v10 != nullptr )
    {
      v11 = 0;
      if ( *(int *)&v10[1].usable > 0 )
      {
        v12 = 0;
        do
        {
          v13 = idTreeAnimator::GetMeshIndex(
                  this: animator,
                  meshName: *(const char **)((char *)&v10[1].boostEntityDef->trackedMemory + v12));
          if ( v13 >= 0 )
            animator->meshVisibility.list[v13] = false;
          ++v11;
          v12 += 32;
        }
        while ( v11 < *(_DWORD *)&v10[1].usable );
      }
    }
  }
}


// ========================================================================
// ?ShowChamberedAmmo@idWeapon@@QAAXPAVidTreeAnimator@@@Z
// EA  : 0x82EBFBD8
// RVA : 0x00EBFBD8
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __fastcall idWeapon::ShowChamberedAmmo(idWeapon *this, idTreeAnimator *animator)
{
  idAmmoItem *ammoClip; // r11
  const idDeclInventory *decl; // r30
  int v6; // r28
  int v7; // r31
  int MeshIndex; // r3
  idAmmoItem *ammoClipSecondary; // r11
  const idDeclInventory *v10; // r30
  int v11; // r28
  int v12; // r31
  int v13; // r3

  ammoClip = this->ammoClip;
  if ( ammoClip != nullptr )
  {
    decl = ammoClip->decl;
    if ( decl != nullptr )
    {
      v6 = 0;
      if ( *(int *)&decl[1].usable > 0 )
      {
        v7 = 0;
        do
        {
          MeshIndex = idTreeAnimator::GetMeshIndex(
                        this: animator,
                        meshName: *(const char **)((char *)&decl[1].boostEntityDef->trackedMemory + v7));
          if ( MeshIndex >= 0 )
            animator->meshVisibility.list[MeshIndex] = true;
          ++v6;
          v7 += 32;
        }
        while ( v6 < *(_DWORD *)&decl[1].usable );
      }
    }
  }
  ammoClipSecondary = this->ammoClipSecondary;
  if ( ammoClipSecondary != nullptr )
  {
    v10 = ammoClipSecondary->decl;
    if ( v10 != nullptr )
    {
      v11 = 0;
      if ( *(int *)&v10[1].usable > 0 )
      {
        v12 = 0;
        do
        {
          v13 = idTreeAnimator::GetMeshIndex(
                  this: animator,
                  meshName: *(const char **)((char *)&v10[1].boostEntityDef->trackedMemory + v12));
          if ( v13 >= 0 )
            animator->meshVisibility.list[v13] = true;
          ++v11;
          v12 += 32;
        }
        while ( v11 < *(_DWORD *)&v10[1].usable );
      }
    }
  }
}


// ========================================================================
// ?PullTrigger@idWeapon@@UAAXPAVidActor@@_N@Z
// EA  : 0x82EBFCC0
// RVA : 0x00EBFCC0
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __fastcall idWeapon::PullTrigger(idWeapon *this, idActor *user, bool secondaryAmmo)
{
  idWeapon::triggerState_t triggerState; // r11
  idAmmoItem *ammoClipSecondary; // r11
  burstMode_t burstMode; // r4

  triggerState = this->triggerState;
  if ( secondaryAmmo )
  {
    if ( triggerState == TRIGGERSTATE_PULLED || !idWeapon::IsReadyToFire(this) )
      return;
    ammoClipSecondary = this->ammoClipSecondary;
  }
  else
  {
    if ( triggerState == TRIGGERSTATE_PULLED || !idWeapon::IsReadyToFire(this) )
      return;
    ammoClipSecondary = this->ammoClip;
  }
  burstMode = BURSTMODE_DEFAULT;
  this->triggerState = TRIGGERSTATE_PULLED;
  if ( ammoClipSecondary != nullptr )
    burstMode = ammoClipSecondary->burstMode;
  this->burstCount = idWeapon::GetInitialBurstCount(this, mode: burstMode, secondaryAmmo);
}


// ========================================================================
// ?GetFXExtraCondition@idWeapon@@QBA?AW4fxExtraCondition_t@@_N@Z
// EA  : 0x82EBFD68
// RVA : 0x00EBFD68
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

__int32 __fastcall idWeapon::GetFXExtraCondition(idWeapon *this, bool secondary)
{
  idWeapon::attack_t attackType; // r8
  idAmmoItem *ammoClipSecondary; // r11
  idAmmoItem *ammoClip; // r11
  const idDeclInventory *decl; // r11
  unsigned int textSource; // r9
  fxExtraCondition_t v7; // r10

  attackType = this->attackType;
  if ( secondary )
    ammoClipSecondary = this->ammoClipSecondary;
  else
    ammoClipSecondary = this->ammoClip;
  if ( ammoClipSecondary != nullptr
    && (!secondary ? (ammoClip = this->ammoClip) : (ammoClip = this->ammoClipSecondary), ammoClip->decl != nullptr) )
  {
    if ( secondary )
      decl = this->ammoClipSecondary->decl;
    else
      decl = this->ammoClip->decl;
    textSource = (unsigned int)decl[1].textSource;
  }
  else
  {
    textSource = 0;
  }
  v7 = FX_EXTRA_COND_NONE;
  if ( (unsigned int)attackType <= ATTACK_RIGHT3 )
    v7 = FX_CONDITION_ATTACK_FLAG[attackType];
  if ( textSource >= 4 )
    return v7;
  else
    return FX_CONDITION_AMMOSLOT_FLAG[textSource] | v7;
}


// ========================================================================
// ?GetMuzzleFlashWorldTransform@idWeapon@@QBA_NPBVidTreeAnimator@@W4attack_t@1@AAVidVec3@@AAVidMat3@@@Z
// EA  : 0x82EBFE30
// RVA : 0x00EBFE30
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

int __fastcall idWeapon::GetMuzzleFlashWorldTransform(
        idWeapon *this,
        idTreeAnimator *ta,
        int attackType,
        idVec3 *origin,
        idMat3 *axis)
{
  tagData_t v9[2]; // [sp+50h] [-40h] BYREF

  v9[0].parentJoint.value = -1;
  v9[0].trans.x = 0.0;
  v9[0].trans.y = 0.0;
  v9[0].trans.z = 0.0;
  v9[0].rot.x = 0.0;
  v9[0].rot.y = 0.0;
  v9[0].rot.z = 0.0;
  v9[0].rot.w = 0.0;
  if ( (unsigned __int8)idWeapon::GetMuzzleFlashTagData(this, ta, attackType, tagData: v9) != 0
    && (unsigned __int8)idTreeAnimator::GetWorldSpaceTagTransform(this: ta, tagData: v9, origin, axis) != 0 )
  {
    return 1;
  }
  *origin = vec3_origin;
  *axis = mat3_identity;
  return 0;
}


// ========================================================================
// ?SkipFire@idWeapon@@QAAX_N@Z
// EA  : 0x82EBFF30
// RVA : 0x00EBFF30
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __fastcall idWeapon::SkipFire(idWeapon *this, bool secondaryAmmo)
{
  int GameMs; // r29

  idWeapon::UpdateAttackType(this);
  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  this->nextFireTime = idWeapon::GetFiringInterval(this, secondaryAmmo) + GameMs;
}


// ========================================================================
// ?TestFire@idWeapon@@QAA_NPAVidPresentable@@PBV2@ABVidVec3@@ABVidMat3@@AAVidFireParms@@AAVidTestFireResults@@_N@Z
// EA  : 0x82EBFF80
// RVA : 0x00EBFF80
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

int __fastcall idWeapon::TestFire(
        idWeapon *this,
        idPresentable *attacker,
        const idPresentable *target,
        const idVec3 *start,
        const idMat3 *fireAxis,
        idFireParms *fp,
        idTestFireResults *tfr,
        bool secondaryAmmo)
{
  unsigned int spawnId; // r5
  idAmmoItem *ammoClipSecondary; // r11
  const idDeclInventory *decl; // r11
  const idDeclProjectile *v12; // r11
  char v13; // r7

  spawnId = 0;
  if ( attacker != nullptr )
    spawnId = attacker->spawnId;
  fp->attacker.spawnId = spawnId;
  if ( target != nullptr )
    fp->target.spawnId = target->spawnId;
  fp->wepDef = (const idDeclWeapon *)this->decl;
  fp->start = *start;
  fp->fireAxis = *fireAxis;
  if ( secondaryAmmo )
    ammoClipSecondary = this->ammoClipSecondary;
  else
    ammoClipSecondary = this->ammoClip;
  if ( ammoClipSecondary != nullptr && (decl = ammoClipSecondary->decl) != nullptr )
    v12 = (const idDeclProjectile *)decl[1].__vftable;
  else
    v12 = nullptr;
  v13 = *((_BYTE *)fp + 129);
  fp->projDef = v12;
  *((_BYTE *)fp + 129) = (32 * secondaryAmmo) & 0x20 | v13 & 0xDF;
  if ( v12 != nullptr )
    return idClientGame::TestFire(this: clientGame, fp, tfr);
  else
    return 0;
}


// ========================================================================
// ?GetFirstLoadableAmmo@idWeapon@@QBAPBVidAmmoItem@@PAVidInventoryCollection@@_N@Z
// EA  : 0x82EC0080
// RVA : 0x00EC0080
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

const idAmmoItem *__fastcall idWeapon::GetFirstLoadableAmmo(
        idWeapon *this,
        idJobManager *inventory,
        bool secondaryAmmo)
{
  const idDeclInventory *decl; // r11
  BOOL v4; // r23
  _DWORD *p_networkID; // r28
  int v9; // r25
  int i; // r29
  const idDeclInventory *v11; // r30
  const idDeclJob *v12; // r31
  idAmmoItem *v13; // r11
  char v14; // r11
  idAmmoItem *JobByDecl; // r3
  idAmmoItem *v16; // r3
  int v17; // r3
  idAmmoItem *v18; // r3
  const idAmmoItem *result; // r3

  decl = this->decl;
  v4 = secondaryAmmo;
  p_networkID = &decl[1].networkID;
  if ( !secondaryAmmo )
    p_networkID = &decl[1].name.str;
  v9 = 0;
  if ( (int)p_networkID[1] > 0 )
  {
    for ( i = 0; ; i += 28 )
    {
      v11 = this->decl;
      v12 = *(const idDeclJob **)(*p_networkID + i);
      if ( v11[1].declSource == nullptr )
        break;
      v13 = v4 ? this->ammoClipSecondary : this->ammoClip;
      if ( v13 != nullptr
        && (const idDeclJob *)v13->decl == v12
        && (unsigned __int8)idWeapon::IsFullyLoaded(this, secondaryAmmo) != 0 )
      {
        break;
      }
      if ( inventory != nullptr )
      {
        JobByDecl = (idAmmoItem *)idJobManager::FindJobByDecl(this: inventory, jobDecl: v12);
        v16 = idAmmoItem::CastTo(c: JobByDecl);
        if ( v16 == nullptr )
          break;
        v17 = v16->GetCount(this: v16);
        v14 = 1;
        if ( v17 < (int)v11[1].declSource )
          break;
      }
      else
      {
        v14 = 1;
      }
LABEL_17:
      if ( v14 != 0 )
      {
        v18 = (idAmmoItem *)idJobManager::FindJobByDecl(
                              this: inventory,
                              jobDecl: *(const idDeclJob **)(*p_networkID + i));
        result = idAmmoItem::CastTo(c: v18);
        if ( result != nullptr )
          return result;
      }
      if ( ++v9 >= p_networkID[1] )
        return nullptr;
    }
    v14 = 0;
    goto LABEL_17;
  }
  return nullptr;
}


// ========================================================================
// ?FindNextLoadableAmmo@idWeapon@@QBAPBVidDeclAmmo@@PAVidInventoryCollection@@PBVidAmmoItem@@_N@Z
// EA  : 0x82EC01B0
// RVA : 0x00EC01B0
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

const idAmmoItem *__fastcall idWeapon::FindNextLoadableAmmo(
        idWeapon *this,
        idJobManager *inventory,
        const idDeclAmmo *curAmmo,
        bool secondaryAmmo)
{
  const idDeclInventory *decl; // r31
  const idDeclAmmo *v8; // r26
  const idAmmoItem *result; // r3
  _DWORD *p_networkID; // r29
  int v11; // r10
  int v12; // r9
  int i; // r11
  int v14; // r31
  int v15; // r27
  int j; // r28
  const idDeclInventory *v17; // r30
  idAmmoItem *JobByDecl; // r3
  idAmmoItem *v19; // r3
  const idAmmoItem *LoadedAmmo; // r3

  decl = this->decl;
  v8 = curAmmo;
  if ( curAmmo == nullptr )
  {
    result = idWeapon::GetFirstLoadableAmmo(this, inventory, secondaryAmmo);
    v8 = (const idDeclAmmo *)result;
    if ( result == nullptr )
      return result;
  }
  p_networkID = &decl[1].networkID;
  if ( !secondaryAmmo )
    p_networkID = &decl[1].name.str;
  v11 = p_networkID[1];
  v12 = 0;
  if ( v11 <= 0 )
    return (const idAmmoItem *)v8->nextOnHashChain;
  for ( i = 0; v8->nextOnHashChain != *(idResource **)(i + *p_networkID); i += 28 )
  {
    if ( ++v12 >= v11 )
      return (const idAmmoItem *)v8->nextOnHashChain;
  }
  v14 = v12 + 1;
  v15 = v12;
  if ( v12 + 1 >= v11 )
  {
    v14 = 0;
    goto LABEL_13;
  }
  if ( v12 == -2 )
    return (const idAmmoItem *)v8->nextOnHashChain;
LABEL_13:
  for ( j = 0; j < v11; ++j )
  {
    if ( v14 > -1 )
    {
      v17 = *(const idDeclInventory **)(28 * v14 + *p_networkID);
      if ( v17 != nullptr )
      {
        JobByDecl = (idAmmoItem *)idJobManager::FindJobByDecl(
                                    this: inventory,
                                    jobDecl: *(const idDeclJob **)(28 * v14 + *p_networkID));
        v19 = idAmmoItem::CastTo(c: JobByDecl);
        if ( v19 != nullptr )
        {
          if ( v19->GetCount(this: v19) > 0 )
            return (const idAmmoItem *)v17;
        }
        else
        {
          LoadedAmmo = idWeapon::GetLoadedAmmo(this, secondaryAmmo);
          if ( LoadedAmmo != nullptr && LoadedAmmo->decl == v17 )
            return (const idAmmoItem *)v17;
        }
      }
      v11 = p_networkID[1];
      v14 = ((__PAIR64__((unsigned int)v11 >> 31, v14 + 1) - __PAIR64__((unsigned int)(v14 + 1) >> 31, v11)) >> 32)
          & (v14 + 1);
      if ( v14 == v15 )
        return (const idAmmoItem *)v8->nextOnHashChain;
    }
  }
  return (const idAmmoItem *)v8->nextOnHashChain;
}


// ========================================================================
// ?SetFireState@idWeapon@@QAAXW4fireState_t@1@@Z
// EA  : 0x82EC0330
// RVA : 0x00EC0330
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __fastcall idWeapon::SetFireState(idWeapon *this, const idWeapon::fireState_t fs)
{
  int v2; // r8
  int v3; // r4

  if ( (unsigned __int8)idWeapon::IsMelee(this) != 0 )
    *(_DWORD *)(v2 + 72) = 0;
  else
    *(_DWORD *)(v2 + 72) = v3;
}


// ========================================================================
// ?ToggleFireMode@idWeapon@@QAA?AW4burstMode_t@@_N0@Z
// EA  : 0x82EC0380
// RVA : 0x00EC0380
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

int __fastcall idWeapon::ToggleFireMode(idWeapon *this, bool justFetchNextMode, bool ignoreMode)
{
  int v4; // r9
  idAmmoItem *ammoClipSecondary; // r3
  const idDeclInventory *decl; // r11
  burstMode_t burstMode; // r7
  int *p_size; // r6
  int v9; // r11
  int v10; // r8

  v4 = 0;
  if ( this->weaponState == WEAPONSTATE_SECONDARY )
    ammoClipSecondary = this->ammoClipSecondary;
  else
    ammoClipSecondary = this->ammoClip;
  decl = ammoClipSecondary->decl;
  if ( decl == nullptr )
    return v4;
  burstMode = ammoClipSecondary->burstMode;
  if ( decl[1].requiredName.index == 3 )
    p_size = &this->decl[1].attachmentInfo.size;
  else
    p_size = (int *)&decl[1].icon;
  v4 = (burstMode + 1) % 3;
  if ( v4 != burstMode )
  {
    v9 = v4;
    do
    {
      if ( p_size[v9] >= 0 )
        break;
      v4 = (v4 + 1) % 3;
      v9 = v4;
    }
    while ( v4 != burstMode );
  }
  if ( !justFetchNextMode )
  {
    if ( burstMode != v4 )
      this->burstCount = 0;
    ammoClipSecondary->burstMode = v4;
  }
  if ( ignoreMode || v4 > burstMode || !idWeapon::CanToggleWeaponMode(this) )
    return v4;
  if ( v10 == 0 )
    idWeapon::ToggleWeaponMode(this);
  return 3;
}


// ========================================================================
// ?ShowHideUpgradeMeshes@idWeapon@@QAAXPAVidTreeAnimator@@_NPBVupgradeInfoMD6@@@Z
// EA  : 0x82EC04C8
// RVA : 0x00EC04C8
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __fastcall idWeapon::ShowHideUpgradeMeshes(
        idWeapon *this,
        idTreeAnimator *animator,
        bool hasTheUpgrade,
        const upgradeInfoMD6 *upgradeMD6Info)
{
  int num; // r11
  int v7; // r28
  int v8; // r29
  int MeshIndex; // r3
  int v10; // r28
  int v11; // r29
  int v12; // r3
  int v13; // r29
  int v14; // r3
  int v15; // r28
  int v16; // r29
  int v17; // r3

  num = upgradeMD6Info->meshesHiddenWithUpgrade.num;
  v7 = 0;
  if ( hasTheUpgrade )
  {
    if ( num > 0 )
    {
      v8 = 0;
      do
      {
        MeshIndex = idTreeAnimator::GetMeshIndex(
                      this: animator,
                      meshName: upgradeMD6Info->meshesHiddenWithUpgrade.list[v8].data);
        if ( MeshIndex >= 0 )
          animator->meshVisibility.list[MeshIndex] = false;
        ++v7;
        ++v8;
      }
      while ( v7 < upgradeMD6Info->meshesHiddenWithUpgrade.num );
    }
    v10 = 0;
    if ( upgradeMD6Info->meshesShownWithUpgrade.num > 0 )
    {
      v11 = 0;
      do
      {
        v12 = idTreeAnimator::GetMeshIndex(
                this: animator,
                meshName: upgradeMD6Info->meshesShownWithUpgrade.list[v11].data);
        if ( v12 >= 0 )
          animator->meshVisibility.list[v12] = true;
        ++v10;
        ++v11;
      }
      while ( v10 < upgradeMD6Info->meshesShownWithUpgrade.num );
    }
  }
  else
  {
    if ( num > 0 )
    {
      v13 = 0;
      do
      {
        v14 = idTreeAnimator::GetMeshIndex(
                this: animator,
                meshName: upgradeMD6Info->meshesHiddenWithUpgrade.list[v13].data);
        if ( v14 >= 0 )
          animator->meshVisibility.list[v14] = true;
        ++v7;
        ++v13;
      }
      while ( v7 < upgradeMD6Info->meshesHiddenWithUpgrade.num );
    }
    v15 = 0;
    if ( upgradeMD6Info->meshesShownWithUpgrade.num > 0 )
    {
      v16 = 0;
      do
      {
        v17 = idTreeAnimator::GetMeshIndex(
                this: animator,
                meshName: upgradeMD6Info->meshesShownWithUpgrade.list[v16].data);
        if ( v17 >= 0 )
          animator->meshVisibility.list[v17] = false;
        ++v15;
        ++v16;
      }
      while ( v15 < upgradeMD6Info->meshesShownWithUpgrade.num );
    }
  }
}


// ========================================================================
// ?ShowHideAmmoMeshes@idWeapon@@QAAXPAVidTreeAnimator@@PBVidAmmoItem@@@Z
// EA  : 0x82EC0630
// RVA : 0x00EC0630
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __fastcall idWeapon::ShowHideAmmoMeshes(idWeapon *this, idTreeAnimator *animator, const idAmmoItem *checkAmmoClip)
{
  const idDeclInventory *decl; // r31
  int v6; // r28
  int v7; // r30
  int MeshIndex; // r3
  int v9; // r28
  int v10; // r30
  int v11; // r3
  int v12; // r28
  int v13; // r30
  int v14; // r3

  if ( checkAmmoClip != nullptr )
  {
    decl = checkAmmoClip->decl;
    if ( decl != nullptr )
    {
      v6 = 0;
      if ( (int)decl[1].merchantIcon > 0 )
      {
        v7 = 0;
        do
        {
          MeshIndex = idTreeAnimator::GetMeshIndex(
                        this: animator,
                        meshName: *(const char **)((char *)&decl[1].engineeringIcon->trackedMemory + v7));
          if ( MeshIndex >= 0 )
            animator->meshVisibility.list[MeshIndex] = false;
          ++v6;
          v7 += 32;
        }
        while ( v6 < (int)decl[1].merchantIcon );
      }
      v9 = 0;
      if ( *(int *)&decl[1].usable > 0 )
      {
        v10 = 0;
        do
        {
          v11 = idTreeAnimator::GetMeshIndex(
                  this: animator,
                  meshName: *(const char **)((char *)&decl[1].boostEntityDef->trackedMemory + v10));
          if ( v11 >= 0 )
            animator->meshVisibility.list[v11] = true;
          ++v9;
          v10 += 32;
        }
        while ( v9 < *(_DWORD *)&decl[1].usable );
      }
      if ( checkAmmoClip->GetCount(this: checkAmmoClip) == 0 )
      {
        v12 = 0;
        if ( decl[1].droppedControllerShake.highDuration > 0 )
        {
          v13 = 0;
          do
          {
            v14 = idTreeAnimator::GetMeshIndex(
                    this: animator,
                    meshName: *(const char **)(v13 + LODWORD(decl[1].droppedControllerShake.highMagnitude) + 4));
            if ( v14 >= 0 )
              animator->meshVisibility.list[v14] = false;
            ++v12;
            v13 += 32;
          }
          while ( v12 < decl[1].droppedControllerShake.highDuration );
        }
      }
    }
  }
}


// ========================================================================
// ?UpdateHiddenMeshes@idWeapon@@UAAXPAVidTreeAnimator@@@Z
// EA  : 0x82EC0768
// RVA : 0x00EC0768
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __fastcall idWeapon::UpdateHiddenMeshes(idWeapon *this, idTreeAnimator *animator)
{
  const idDeclInventory *decl; // r31

  decl = this->decl;
  idWeapon::ShowHideUpgradeMeshes(
    this,
    animator,
    hasTheUpgrade: (*((_BYTE *)this + 452) & 0x10) != 0,
    upgradeMD6Info: (const upgradeInfoMD6 *)&decl[2].scriptUse.data);
  idWeapon::ShowHideUpgradeMeshes(
    this,
    animator,
    hasTheUpgrade: (*((_BYTE *)this + 452) & 4) != 0,
    upgradeMD6Info: (const upgradeInfoMD6 *)&decl[3].staleCount);
  idWeapon::ShowHideUpgradeMeshes(
    this,
    animator,
    hasTheUpgrade: (*((_BYTE *)this + 452) & 2) != 0,
    upgradeMD6Info: (const upgradeInfoMD6 *)&decl[3].inventoryClass);
  idWeapon::ShowHideUpgradeMeshes(
    this,
    animator,
    hasTheUpgrade: (*((_BYTE *)this + 453) & 0x40) != 0,
    upgradeMD6Info: (const upgradeInfoMD6 *)&decl[3].customMaterial);
  idWeapon::ShowHideAmmoMeshes(this, animator, checkAmmoClip: this->ammoClip);
  idWeapon::ShowHideAmmoMeshes(this, animator, checkAmmoClip: this->ammoClipSecondary);
}


// ========================================================================
// ?SpinBarrel@idWeapon@@QAA_NPAVidTreeAnimator@@@Z
// EA  : 0x82EC0808
// RVA : 0x00EC0808
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

int __fastcall idWeapon::SpinBarrel(idWeapon *this, idTreeAnimator *parentModel)
{
  int v4; // r26
  int GameMs; // r25
  int PreviousGameMs; // r3
  double barrelTotalSpin; // fp13
  __int64 v8; // r6
  double barrelSpinSpeed; // fp12
  idWeapon::weaponState_t weaponState; // r29
  int v11; // r3
  idMat3 v13; // [sp+58h] [-98h] BYREF
  __int16 v14; // [sp+7Ch] [-74h]
  char v15; // [sp+7Eh] [-72h]
  char v16; // [sp+7Fh] [-71h]
  idMat3 v17; // [sp+80h] [-70h] BYREF

  memset(&v13.mat[2], 0, sizeof(v13.mat[2]));
  v14 = 0;
  v16 = 0;
  v4 = 0;
  v15 = 5;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v13.mat[2]);
  idTreeAnimator::GetJointList(
    this: parentModel,
    jointNames: *(const char **)&this->decl[3].internalName.baseBuffer[12],
    jointList: (idList<idIndex<short,enum invalidJointIndex_t>,5> *)&v13.mat[2]);
  if ( LODWORD(v13.mat[2].y) == 1 )
  {
    this->barrelJointRotation.value = *(_WORD *)LODWORD(v13.mat[2].x);
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    PreviousGameMs = idGameTimeManager::GetPreviousGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    barrelTotalSpin = this->barrelTotalSpin;
    LODWORD(v8) = GameMs - PreviousGameMs;
    barrelSpinSpeed = this->barrelSpinSpeed;
    HIDWORD(v8) = 0x82000000;
    v13.mat[0].x = 0.0;
    v13.mat[0].y = 0.0;
    this->barrelTotalSpin = (float)((float)barrelSpinSpeed * (float)((float)v8 * (float)0.001)) + (float)barrelTotalSpin;
    v13.mat[0].z = (float)((float)barrelSpinSpeed * (float)((float)v8 * (float)0.001)) + (float)barrelTotalSpin;
    idAngles::ToMat3(this: (idAngles *)&v17, result: &v13);
    idTreeAnimator::SetJointAxis(
      this: parentModel,
      pose: (animationPose_t)0,
      jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)this->barrelJointRotation.value,
      type: JOINTMOD_MODEL_OVERRIDE,
      axis: &v17);
    if ( idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) > this->spinBarrelNextShootTime
      && this->barrelSpinSpeed > 0.0
      && this->triggerState == TRIGGERSTATE_PULLED
      && this->ammoClip->decl[1].vehiclePermAttachment )
    {
      weaponState = this->weaponState;
      v11 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      v4 = 1;
      this->spinBarrelNextShootTime = idWeapon::GetFiringInterval(
                                        this,
                                        secondaryAmmo: (_cntlzw(weaponState - 1) & 0x20) != 0)
                                    + v11;
    }
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v13.mat[2]);
    return v4;
  }
  else
  {
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v13.mat[2]);
    return 0;
  }
}


// ========================================================================
// __unwind$504554
// EA  : 0x82EC09D0
// RVA : 0x00EC09D0
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void _unwind_504554()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 240 + 112));
}


// ========================================================================
// ?UpdateLaserSight@idLaserCutter@@UAAXABVidVec3@@0HPAVidActor@@@Z
// EA  : 0x82EC09F8
// RVA : 0x00EC09F8
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __fastcall idLaserCutter::UpdateLaserSight(
        idLaserCutter *this,
        const idVec3 *startPos,
        const idVec3 *endPos,
        int passEntityNumber,
        idPlayer *actor)
{
  idPlayer *v9; // r3
  unsigned __int64 v10; // r23
  idAmmoItem *ammoClipSecondary; // r11
  __int64 v12; // r11
  idPresentable *presentable; // r3
  int v14; // r3
  double FovScale; // fp1
  idRenderModelBeam *beamModelFPView; // r11
  double v17; // fp31
  int GameMs; // r3
  idRenderModelDecal *decalModelFPView; // r11
  int v20; // r3
  int v21; // r3
  int v22; // r3
  idWeapon::weaponState_t weaponState; // r9
  __int64 v24; // r11
  idAmmoItem *ammoClip; // r11
  int v26; // r3
  int v27; // r3
  idTrigger_Damage *ValidTraceResultFocusEntity; // r18
  char v29; // r19
  bool v30; // r16
  double y; // fp13
  idClipQuery *p_pointTrace; // r28
  double v33; // fp12
  unsigned __int64 index; // r11
  idClientGame *v35; // r9
  idEntity *v36; // r27
  int v37; // r25
  const idTypeInfo **v38; // r26
  double v39; // fp6
  double v40; // fp5
  idClip *v41; // r3
  double z; // fp0
  idClientGame *v43; // r28
  idClipQuery *v44; // r25
  unsigned __int64 v45; // r11
  idClientGame *v46; // r28
  idClipQuery *p_bouncePointTrace; // r27
  unsigned __int64 v48; // r11
  double v49; // fp11
  double v50; // fp10
  double v51; // fp8
  idClip *v52; // r3
  double v53; // fp31
  double v54; // fp30
  double v55; // fp29
  idFocusTracker *FocusTracker; // r3
  const trace_t *ValidpointTraceResultWithinRange; // r3
  double v58; // fp12
  double v59; // fp4
  double v60; // fp10
  double v61; // fp6
  double x; // fp9
  double v63; // fp3
  double v64; // fp7
  double v65; // fp1
  double v66; // fp8
  double v67; // fp13
  double v68; // fp2
  double v71; // fp13
  double v72; // fp8
  char canLasercutterActivate; // r28
  idTrigger_Damage *v74; // r3
  int v75; // r3
  idWeapon::weaponState_t v76; // r11
  idFXManager *v77; // r28
  idGameTimeManager *p_gameTimeManager; // r3
  int v79; // r27
  fxExtraCondition_t v80; // r3
  idGameTimeManager *v81; // r3
  __int32 v82; // r3
  unsigned int v83; // r6
  __int32 v84; // r3
  unsigned int v85; // r6
  int v86; // r27
  fxExtraCondition_t v87; // r3
  int v88; // r27
  fxExtraCondition_t v89; // r3
  int v90; // r27
  fxExtraCondition_t FXExtraCondition; // r3
  int v92; // r27
  fxExtraCondition_t v93; // r3
  __int64 v94; // r10
  int v95; // r7
  int v96; // r6
  int v97; // r5
  int v98; // r4
  __int64 v99; // r10
  int v100; // r7
  int v101; // r6
  int v102; // r5
  int v103; // r4
  int v104; // r27
  fxExtraCondition_t v105; // r3
  int v106; // r27
  fxExtraCondition_t v107; // r3
  __int64 v108; // r11
  double v109; // fp1
  double v110; // fp30
  double v111; // fp27
  __int64 v112; // r10
  __int32 v113; // r3
  unsigned int v114; // r6
  int v115; // r27
  fxExtraCondition_t v116; // r3
  __int32 v117; // r3
  unsigned int v118; // r6
  __int32 v119; // r3
  unsigned int v120; // r6
  __int64 v121; // r10
  double CurrentValue; // fp1
  double fadeInDuration; // fp30
  double v124; // fp27
  __int64 v125; // r9
  int v126; // r27
  fxExtraCondition_t v127; // r3
  int v128; // r27
  fxExtraCondition_t v129; // r3
  int v130; // r27
  fxExtraCondition_t v131; // r3
  idWeapon::weaponState_t v132; // r11
  int nextFireTime; // r28
  int v134; // r28
  __int64 v135; // r7
  double v138; // fp0
  double v139; // fp30
  __int64 v140; // r9
  __int64 v141; // r6
  __int64 v144; // r11
  int v145; // r3
  int v146; // r3
  double v147; // fp0
  double v148; // fp13
  double v149; // fp12
  idLaserSight *p_laserBeamShootBounce; // r3
  __int64 v151; // r11
  double v152; // fp31
  int *v153; // r10
  int *v154; // r11
  int i; // ctr
  int v156; // r3
  int v157; // r3
  __int64 v158; // r11
  double v159; // fp31
  int v160; // r3
  int v161; // r3
  double v162; // fp6
  double v163; // fp5
  double v164; // fp4
  idWeapon::weaponState_t v165; // r11
  void *v166; // r3
  int v167; // [sp+8h] [-3D8h]
  bool v168; // [sp+Fh] [-3D1h]
  const char *v169; // [sp+10h] [-3D0h]
  int v170; // [sp+14h] [-3CCh]
  int v171; // [sp+18h] [-3C8h]
  int v172; // [sp+1Ch] [-3C4h]
  int v173; // [sp+20h] [-3C0h]
  int v174; // [sp+24h] [-3BCh]
  int v175; // [sp+28h] [-3B8h]
  int v176; // [sp+2Ch] [-3B4h]
  int v177; // [sp+30h] [-3B0h]
  int v178; // [sp+34h] [-3ACh]
  int v179; // [sp+38h] [-3A8h]
  int v180; // [sp+3Ch] [-3A4h]
  int v181; // [sp+40h] [-3A0h]
  int v182; // [sp+44h] [-39Ch]
  int v183; // [sp+48h] [-398h]
  int v184; // [sp+4Ch] [-394h]
  int v185; // [sp+50h] [-390h]
  int entityNumber; // [sp+54h] [-38Ch]
  int v187; // [sp+54h] [-38Ch]
  int v188; // [sp+54h] [-38Ch]
  int v189; // [sp+58h] [-388h]
  int v190; // [sp+60h] [-380h]
  idVec3 v191; // [sp+70h] [-370h] BYREF
  __int64 v192; // [sp+80h] [-360h] BYREF
  idVec3 v193; // [sp+88h] [-358h] BYREF
  int v194; // [sp+94h] [-34Ch] BYREF
  int v195; // [sp+9Ch] [-344h] BYREF
  float v196; // [sp+A0h] [-340h] BYREF
  float v197; // [sp+A4h] [-33Ch]
  float v198; // [sp+A8h] [-338h]
  float v199; // [sp+ACh] [-334h]
  float v200; // [sp+B0h] [-330h]
  float v201; // [sp+B4h] [-32Ch]
  float v202; // [sp+B8h] [-328h]
  float v203; // [sp+BCh] [-324h]
  float v204; // [sp+C0h] [-320h]
  idVec3 v205; // [sp+C8h] [-318h] BYREF
  float v206[3]; // [sp+D4h] [-30Ch] BYREF
  float v207[6]; // [sp+E0h] [-300h] BYREF
  __int64 v208; // [sp+F8h] [-2E8h]
  const idTypeInfo *v209[6]; // [sp+100h] [-2E0h] BYREF
  idVec3 v210; // [sp+118h] [-2C8h] BYREF
  idVec3 v211; // [sp+128h] [-2B8h] BYREF
  int v212; // [sp+13Ch] [-2A4h] BYREF
  idMat3 v213; // [sp+140h] [-2A0h] BYREF
  idVec3 v214; // [sp+168h] [-278h] BYREF
  idVec3 v215; // [sp+178h] [-268h] BYREF
  idVec3 v216; // [sp+188h] [-258h] BYREF
  trace_t v217; // [sp+1A0h] [-240h] BYREF
  trace_t v218; // [sp+220h] [-1C0h] BYREF
  trace_t v219; // [sp+2A0h] [-140h] BYREF

  v9 = idPlayer::CastTo(c: actor);
  HIDWORD(v10) = v9;
  if ( v9 == nullptr )
    return;
  if ( this->weaponState == WEAPONSTATE_SECONDARY )
    ammoClipSecondary = this->ammoClipSecondary;
  else
    ammoClipSecondary = this->ammoClip;
  LODWORD(v10) = 0;
  if ( ammoClipSecondary != nullptr )
    LODWORD(v12) = ammoClipSecondary->decl[1].__vftable[7].Print;
  else
    LODWORD(v12) = 0;
  HIDWORD(v12) = this->beamModelFPView;
  v208 = v12;
  v206[0] = (float)v12;
  if ( HIDWORD(v12) != 0 || this->decalModelFPView != nullptr )
  {
    presentable = v9->presentable;
    if ( presentable != nullptr )
      v14 = (int)presentable->GetPlayerInterface_2(this: presentable);
    else
      v14 = 0;
    FovScale = idHands::GetFovScale(this: (idHands *)(v14 + 37616));
    beamModelFPView = this->beamModelFPView;
    v17 = FovScale;
    if ( beamModelFPView != nullptr )
    {
      beamModelFPView->g.fovScale = FovScale;
      GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      idRenderModelBeam::Update(this: this->beamModelFPView, currTime: GameMs);
    }
    decalModelFPView = this->decalModelFPView;
    if ( decalModelFPView != nullptr )
    {
      decalModelFPView->g.fovScale = v17;
      v20 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      idRenderModelDecal::Update(this: this->decalModelFPView, currTime: v20);
    }
  }
  if ( this->beamModelWorldView != nullptr )
  {
    v21 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    idRenderModelBeam::Update(this: this->beamModelWorldView, currTime: v21);
  }
  if ( this->decalModelworldView != nullptr )
  {
    v22 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    idRenderModelDecal::Update(this: this->decalModelworldView, currTime: v22);
  }
  weaponState = this->weaponState;
  v207[0] = v206[0];
  HIDWORD(v24) = &idInfoNavFlightVolume::Type;
  v209[2] = &idAI2::Type;
  HIDWORD(v208) = &idTurret::Type;
  v209[0] = &idCuttable::Type;
  v209[1] = &idFuncChain::Type;
  v209[3] = &idTurret::Type;
  v209[4] = &idTrigger_Damage::Type;
  if ( weaponState == WEAPONSTATE_SECONDARY )
    ammoClip = this->ammoClipSecondary;
  else
    ammoClip = this->ammoClip;
  if ( ammoClip != nullptr )
  {
    HIDWORD(v24) = ammoClip->decl[1].__vftable;
    LODWORD(v24) = *(_DWORD *)(HIDWORD(v24) + 476);
  }
  else
  {
    LODWORD(v24) = 0;
  }
  v26 = *(_DWORD *)(HIDWORD(v10) + 488);
  v207[2] = v206[0];
  v194 = 0;
  v192 = v24;
  v207[3] = v206[0];
  v207[4] = v206[0];
  v207[1] = (float)v24;
  if ( v26 != 0 )
    v27 = (*(int (__fastcall **)(int))(*(_DWORD *)v26 + 104))(a1: v26);
  else
    v27 = 0;
  ValidTraceResultFocusEntity = (idTrigger_Damage *)idFocusTracker::GetValidTraceResultFocusEntity(
                                                      this: (idFocusTracker *)(v27 + 47160),
                                                      includeBoundCheck: false,
                                                      checkTypes: v209,
                                                      numCheckTypes: 5,
                                                      maxRanges: v207,
                                                      resultEndPos: &v191,
                                                      resultID: &v194);
  v205 = v191;
  (*(void (__fastcall **)(_DWORD, idVec3 *, float *))(*(_DWORD *)HIDWORD(v10) + 676))(
    a1: HIDWORD(v10),
    a2: &v193,
    a3: &v196);
  v29 = 0;
  v30 = ValidTraceResultFocusEntity != nullptr;
  if ( ValidTraceResultFocusEntity != nullptr )
  {
    this->pointTrace.index = v10;
    v53 = (float)((float)(v196 * v206[0]) + v193.x);
    v54 = (float)(v193.y + (float)(v197 * v206[0]));
    v55 = (float)(v193.z + (float)(v198 * v206[0]));
    FocusTracker = (idFocusTracker *)idPlayer::GetFocusTracker(this: (idPlayer *)HIDWORD(v10));
    ValidpointTraceResultWithinRange = idFocusTracker::GetValidpointTraceResultWithinRange(
                                         this: FocusTracker,
                                         maxRange: v206);
    if ( ValidpointTraceResultWithinRange != nullptr )
    {
      v191.x = ValidpointTraceResultWithinRange->endpos.x;
      v191.y = ValidpointTraceResultWithinRange->endpos.y;
      z = ValidpointTraceResultWithinRange->endpos.z;
    }
    else
    {
      v191.x = v53;
      z = v55;
      v191.y = v54;
    }
  }
  else if ( this->weaponState == WEAPONSTATE_SECONDARY )
  {
    y = endPos->y;
    p_pointTrace = &this->pointTrace;
    v33 = endPos->z;
    v191.x = endPos->x;
    v191.y = y;
    v191.z = v33;
    if ( (unsigned __int8)idClip::QueryIsValid(this: &clientGame->clip, clipQuery: &this->pointTrace) != 0 )
    {
      index = p_pointTrace->index;
      v35 = clientGame;
      p_pointTrace->index = v10;
      idCollisionModelManager::GetContentsResult(
        this: collisionModelManager,
        result: &v218,
        query: &v35->clip.collisionQueries[index & 0xFFF].query,
        peek: false);
      v36 = gameLocal->entities.ptr[v218.c.entityNum];
      if ( v36 != nullptr )
      {
        v37 = 0;
        v38 = v209;
        while ( (unsigned __int8)idClass::IsType(this: v36, superclass: *v38) == 0 )
        {
          ++v37;
          ++v38;
          if ( v37 >= 5 )
            goto LABEL_37;
        }
        if ( (float)((float)((float)((float)(v218.endpos.x - v193.x) * (float)(v218.endpos.x - v193.x))
                           + (float)((float)((float)(v218.endpos.z - v193.z) * (float)(v218.endpos.z - v193.z))
                                   + (float)((float)(v218.endpos.y - v193.y) * (float)(v218.endpos.y - v193.y))))
                   / (float)(v207[v37] * v207[v37])) < 1.0 )
        {
          ValidTraceResultFocusEntity = (idTrigger_Damage *)v36;
          goto LABEL_39;
        }
LABEL_37:
        if ( (float)((float)((float)((float)(v218.endpos.x - v193.x) * (float)(v218.endpos.x - v193.x))
                           + (float)((float)((float)(v218.endpos.z - v193.z) * (float)(v218.endpos.z - v193.z))
                                   + (float)((float)(v218.endpos.y - v193.y) * (float)(v218.endpos.y - v193.y))))
                   / (float)((float)(v207[0] * v207[0]) * (float)0.75)) >= 1.0 )
          goto LABEL_40;
        v30 = true;
LABEL_39:
        v191.z = v218.endpos.z;
        v191.y = v218.endpos.y;
        v191.x = v218.endpos.x;
      }
    }
LABEL_40:
    entityNumber = actor->entityNumber;
    v39 = (float)(v197 * v207[v194]);
    v40 = (float)(v198 * v207[v194]);
    v216.x = (float)(v196 * v207[v194]) + v193.x;
    v216.y = (float)v39 + v193.y;
    v216.z = (float)v40 + v193.z;
    v41 = idClip::Translation(
            this: (idClip *)&v192,
            result: &clientGame->clip,
            a3: nullptr,
            start: &v193,
            end: &v216,
            clipModel: nullptr,
            startAxis: &mat3_identity,
            clipMask: 8462469,
            passEntityNumber: v167,
            moveClipModel: v168,
            userName: v169,
            a12: v170,
            a13: v171,
            a14: v172,
            a15: v173,
            a16: v174,
            a17: v175,
            a18: v176,
            a19: v177,
            a20: v178,
            a21: v179,
            a22: v180,
            a23: v181,
            a24: v182,
            a25: v183,
            a26: v184,
            a27: v185,
            a28: entityNumber,
            a29: v189,
            a30: false,
            a31: v190,
            a32: (int)"w:\\tech5\\tungsten\\game\\weapons\\InventoryItem.cpp(4167) : Translation");
    z = v191.z;
    p_pointTrace->index = *(unsigned __int64 *)&v41->world;
  }
  else
  {
    v43 = clientGame;
    v44 = &this->pointTrace;
    if ( (unsigned __int8)idClip::QueryIsValid(this: &clientGame->clip, clipQuery: &this->pointTrace) != 0 )
    {
      v45 = v44->index;
      v44->index = v10;
      idCollisionModelManager::GetContentsResult(
        this: collisionModelManager,
        result: &v217,
        query: &v43->clip.collisionQueries[v45 & 0xFFF].query,
        peek: false);
      v46 = clientGame;
      p_bouncePointTrace = &this->bouncePointTrace;
      v191.x = v217.endpos.x;
      v191.y = v217.endpos.y;
      v191.z = v217.endpos.z;
      if ( (unsigned __int8)idClip::QueryIsValid(this: &clientGame->clip, clipQuery: &this->bouncePointTrace) != 0 )
      {
        v48 = p_bouncePointTrace->index;
        p_bouncePointTrace->index = v10;
        idCollisionModelManager::GetContentsResult(
          this: collisionModelManager,
          result: &v219,
          query: &v46->clip.collisionQueries[v48 & 0xFFF].query,
          peek: false);
        v46 = clientGame;
        v29 = 1;
        v205.x = v219.endpos.x;
        v205.y = v219.endpos.y;
        v205.z = v219.endpos.z;
      }
      v187 = actor->entityNumber;
      v49 = (float)(v207[v194]
                  * (float)(v197
                          - (float)((float)((float)(v197 * v217.c.normal.y)
                                          + (float)((float)(v217.c.normal.x * v196) + (float)(v198 * v217.c.normal.z)))
                                  * (float)(v217.c.normal.y * (float)2.0))));
      v50 = (float)(v207[v194]
                  * (float)(v198
                          - (float)((float)((float)(v197 * v217.c.normal.y)
                                          + (float)((float)(v217.c.normal.x * v196) + (float)(v198 * v217.c.normal.z)))
                                  * (float)(v217.c.normal.z * (float)2.0))));
      v214.x = (float)((float)(v196
                             - (float)((float)(v217.c.normal.x * (float)2.0)
                                     * (float)((float)(v197 * v217.c.normal.y)
                                             + (float)((float)(v217.c.normal.x * v196) + (float)(v198 * v217.c.normal.z)))))
                     * v207[v194])
             + v193.x;
      v214.y = v193.y + (float)v49;
      v214.z = v193.z + (float)v50;
      p_bouncePointTrace->index = *(unsigned __int64 *)&idClip::Translation(
                                                          this: (idClip *)&v192,
                                                          result: &v46->clip,
                                                          a3: nullptr,
                                                          start: &v217.endpos,
                                                          end: &v214,
                                                          clipModel: nullptr,
                                                          startAxis: &mat3_identity,
                                                          clipMask: 8462469,
                                                          passEntityNumber: v167,
                                                          moveClipModel: v168,
                                                          userName: v169,
                                                          a12: v170,
                                                          a13: v171,
                                                          a14: v172,
                                                          a15: v173,
                                                          a16: v174,
                                                          a17: v175,
                                                          a18: v176,
                                                          a19: v177,
                                                          a20: v178,
                                                          a21: v179,
                                                          a22: v180,
                                                          a23: v181,
                                                          a24: v182,
                                                          a25: v183,
                                                          a26: v184,
                                                          a27: v185,
                                                          a28: v187,
                                                          a29: v189,
                                                          a30: false,
                                                          a31: v190,
                                                          a32: (int)"w:\\tech5\\tungsten\\game\\weapons\\InventoryItem.cpp(418"
                                                               "2) : Translation")->world;
      v43 = clientGame;
    }
    v188 = actor->entityNumber;
    v51 = v207[v194];
    v210.x = (float)(v207[v194] * v196) + v193.x;
    v210.y = v193.y + (float)(v197 * (float)v51);
    v210.z = v193.z + (float)(v198 * (float)v51);
    v52 = idClip::Translation(
            this: (idClip *)&v192,
            result: &v43->clip,
            a3: nullptr,
            start: &v193,
            end: &v210,
            clipModel: nullptr,
            startAxis: &mat3_identity,
            clipMask: 8462469,
            passEntityNumber: v167,
            moveClipModel: v168,
            userName: v169,
            a12: v170,
            a13: v171,
            a14: v172,
            a15: v173,
            a16: v174,
            a17: v175,
            a18: v176,
            a19: v177,
            a20: v178,
            a21: v179,
            a22: v180,
            a23: v181,
            a24: v182,
            a25: v183,
            a26: v184,
            a27: v185,
            a28: v188,
            a29: v189,
            a30: false,
            a31: v190,
            a32: (int)"w:\\tech5\\tungsten\\game\\weapons\\InventoryItem.cpp(4185) : Translation");
    z = v191.z;
    v44->index = *(unsigned __int64 *)&v52->world;
  }
  v58 = startPos->z;
  v59 = (float)((float)z - startPos->z);
  v60 = (float)(endPos->z - startPos->z);
  v61 = startPos->y;
  x = startPos->x;
  v63 = (float)(endPos->y - startPos->y);
  v64 = (float)(endPos->x - startPos->x);
  v65 = (float)(v191.x - startPos->x);
  v66 = (float)(v191.y - startPos->y);
  v67 = idMath::FLT_SMALLEST_NON_DENORMAL;
  this->lastOkToCutTime = 0;
  v68 = __fsqrts((float)((float)((float)v66 * (float)v66)
                       + (float)((float)((float)v65 * (float)v65) + (float)((float)v59 * (float)v59))));
  _FP5 = (float)((float)((float)((float)v63 * (float)v63)
                       + (float)((float)((float)v64 * (float)v64) + (float)((float)v60 * (float)v60)))
               - (float)v67);
  __asm { fsel      f1, f5, f11, f13 }
  v71 = __frsqrte(_FP1);
  v72 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v71
                                                                                      * (float)((float)((float)((float)v63 * (float)v63) + (float)((float)((float)v64 * (float)v64) + (float)((float)v60 * (float)v60)))
                                                                                              * (float)0.5))
                                                                              * (float)v71)
                                                                      - (float)1.5)
                                                      * (float)v71)
                                              * (float)((float)((float)((float)v63 * (float)v63)
                                                              + (float)((float)((float)v64 * (float)v64)
                                                                      + (float)((float)v60 * (float)v60)))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v71
                                                                              * (float)((float)((float)((float)v63 * (float)v63)
                                                                                              + (float)((float)((float)v64 * (float)v64) + (float)((float)v60 * (float)v60)))
                                                                                      * (float)0.5))
                                                                      * (float)v71)
                                                              - (float)1.5)
                                              * (float)v71))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v71
                                                      * (float)((float)((float)((float)v63 * (float)v63)
                                                                      + (float)((float)((float)v64 * (float)v64)
                                                                              + (float)((float)v60 * (float)v60)))
                                                              * (float)0.5))
                                              * (float)v71)
                                      - (float)1.5)
                      * (float)v71));
  v191.x = (float)((float)((float)v64
                         * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v71 * (float)((float)((float)((float)v63 * (float)v63) + (float)((float)((float)v64 * (float)v64) + (float)((float)v60 * (float)v60))) * (float)0.5)) * (float)v71) - (float)1.5) * (float)v71) * (float)((float)((float)((float)v63 * (float)v63) + (float)((float)((float)v64 * (float)v64) + (float)((float)v60 * (float)v60))) * (float)0.5))
                                                                                                 * (float)((float)-(float)((float)((float)((float)v71 * (float)((float)((float)((float)v63 * (float)v63) + (float)((float)((float)v64 * (float)v64) + (float)((float)v60 * (float)v60))) * (float)0.5)) * (float)v71) - (float)1.5) * (float)v71))
                                                                                         - (float)1.5)
                                                                         * (float)((float)-(float)((float)((float)((float)v71 * (float)((float)((float)((float)v63 * (float)v63) + (float)((float)((float)v64 * (float)v64) + (float)((float)v60 * (float)v60))) * (float)0.5)) * (float)v71)
                                                                                                 - (float)1.5)
                                                                                 * (float)v71))
                                                                 * (float)((float)((float)((float)v63 * (float)v63)
                                                                                 + (float)((float)((float)v64
                                                                                                 * (float)v64)
                                                                                         + (float)((float)v60
                                                                                                 * (float)v60)))
                                                                         * (float)0.5))
                                                         * (float)v72)
                                                 - (float)1.5)
                                 * (float)v72))
                 * (float)v68)
         + (float)x;
  v191.y = (float)v61
         + (float)((float)v68
                 * (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v71 * (float)((float)((float)((float)v63 * (float)v63) + (float)((float)((float)v64 * (float)v64) + (float)((float)v60 * (float)v60))) * (float)0.5)) * (float)v71) - (float)1.5) * (float)v71) * (float)((float)((float)((float)v63 * (float)v63) + (float)((float)((float)v64 * (float)v64) + (float)((float)v60 * (float)v60))) * (float)0.5))
                                                                                                 * (float)((float)-(float)((float)((float)((float)v71 * (float)((float)((float)((float)v63 * (float)v63) + (float)((float)((float)v64 * (float)v64) + (float)((float)v60 * (float)v60))) * (float)0.5)) * (float)v71) - (float)1.5) * (float)v71))
                                                                                         - (float)1.5)
                                                                         * (float)((float)-(float)((float)((float)((float)v71 * (float)((float)((float)((float)v63 * (float)v63) + (float)((float)((float)v64 * (float)v64) + (float)((float)v60 * (float)v60))) * (float)0.5)) * (float)v71)
                                                                                                 - (float)1.5)
                                                                                 * (float)v71))
                                                                 * (float)((float)((float)((float)v63 * (float)v63)
                                                                                 + (float)((float)((float)v64
                                                                                                 * (float)v64)
                                                                                         + (float)((float)v60
                                                                                                 * (float)v60)))
                                                                         * (float)0.5))
                                                         * (float)v72)
                                                 - (float)1.5)
                                 * (float)v72)
                         * (float)v63));
  v191.z = (float)v58
         + (float)((float)v68
                 * (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v71 * (float)((float)((float)((float)v63 * (float)v63) + (float)((float)((float)v64 * (float)v64) + (float)((float)v60 * (float)v60))) * (float)0.5)) * (float)v71) - (float)1.5) * (float)v71) * (float)((float)((float)((float)v63 * (float)v63) + (float)((float)((float)v64 * (float)v64) + (float)((float)v60 * (float)v60))) * (float)0.5))
                                                                                                 * (float)((float)-(float)((float)((float)((float)v71 * (float)((float)((float)((float)v63 * (float)v63) + (float)((float)((float)v64 * (float)v64) + (float)((float)v60 * (float)v60))) * (float)0.5)) * (float)v71) - (float)1.5) * (float)v71))
                                                                                         - (float)1.5)
                                                                         * (float)((float)-(float)((float)((float)((float)v71 * (float)((float)((float)((float)v63 * (float)v63) + (float)((float)((float)v64 * (float)v64) + (float)((float)v60 * (float)v60))) * (float)0.5)) * (float)v71)
                                                                                                 - (float)1.5)
                                                                                 * (float)v71))
                                                                 * (float)((float)((float)((float)v63 * (float)v63)
                                                                                 + (float)((float)((float)v64
                                                                                                 * (float)v64)
                                                                                         + (float)((float)v60
                                                                                                 * (float)v60)))
                                                                         * (float)0.5))
                                                         * (float)v72)
                                                 - (float)1.5)
                                 * (float)v72)
                         * (float)v60));
  if ( ValidTraceResultFocusEntity != nullptr )
  {
    canLasercutterActivate = 1;
    v74 = idTrigger_Damage::CastTo(c: ValidTraceResultFocusEntity);
    if ( v74 != nullptr )
      canLasercutterActivate = v74->canLasercutterActivate;
    if ( canLasercutterActivate != 0 )
    {
      v75 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      v76 = this->weaponState;
      this->lastOkToCutTime = v75;
      if ( v76 == WEAPONSTATE_SECONDARY )
        idPlayer::SetTension(this: (idPlayer *)HIDWORD(v10), tension: PLAYER_TENSION_HOSTILE);
    }
  }
  if ( actor != nullptr )
  {
    v77 = actor->GetFXMgrForAttachment(this: actor, a2: this);
    if ( v77 != nullptr )
    {
      p_gameTimeManager = &clientGame->gameTimeManager;
      if ( this->weaponState == WEAPONSTATE_SECONDARY )
      {
        v90 = idGameTimeManager::GetGameMs(this: p_gameTimeManager, type: GAMETIME_SCALED);
        FXExtraCondition = idWeapon::GetFXExtraCondition(this, secondary: false);
        idFXManager::StopFX(
          this: v77,
          time: v90,
          stopCondition: 83,
          extraCondition: FXExtraCondition,
          immediateStop: false);
        v92 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        v93 = idWeapon::GetFXExtraCondition(this, secondary: false);
        idFXManager::StopFX(this: v77, time: v92, stopCondition: 84, extraCondition: v93, immediateStop: false);
        if ( (unsigned __int8)idLaserCutter::GetOkToFire(this, a2: v98, a3: v97, a4: v96, a5: v95, a6: v94) != 0
          || this->triggerState != TRIGGERSTATE_PULLED )
        {
          if ( (unsigned __int8)idLaserCutter::GetOkToFire(this, a2: v103, a3: v102, a4: v101, a5: v100, a6: v99) == 0
            || this->triggerState != TRIGGERSTATE_PULLED )
          {
            v126 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
            v127 = idWeapon::GetFXExtraCondition(this, secondary: true);
            idFXManager::StopFX(this: v77, time: v126, stopCondition: 74, extraCondition: v127, immediateStop: false);
            v128 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
            v129 = idWeapon::GetFXExtraCondition(this, secondary: true);
            idFXManager::StopFX(this: v77, time: v128, stopCondition: 76, extraCondition: v129, immediateStop: false);
            v130 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
            v131 = idWeapon::GetFXExtraCondition(this, secondary: true);
            idFXManager::StopFX(this: v77, time: v130, stopCondition: 78, extraCondition: v131, immediateStop: false);
            this->endEffectActive = false;
          }
          else if ( !this->cuttingWeldEffectRunning )
          {
            this->cuttingWeldEffectRunning = true;
            v115 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
            v116 = idWeapon::GetFXExtraCondition(this, secondary: true);
            idFXManager::StopFX(this: v77, time: v115, stopCondition: 78, extraCondition: v116, immediateStop: false);
            idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
            v117 = idWeapon::GetFXExtraCondition(this, secondary: true);
            idFXManager::StartFX(
              this: v77,
              org: &vec3_origin,
              axis: &mat3_identity,
              time: v118,
              startCondition: 73,
              extraCond: v117);
            idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
            v119 = idWeapon::GetFXExtraCondition(this, secondary: true);
            idFXManager::StartFX(
              this: v77,
              org: &vec3_origin,
              axis: &mat3_identity,
              time: v120,
              startCondition: 75,
              extraCond: v119);
            this->burstCount = 0;
            LODWORD(v121) = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
            v192 = v121;
            CurrentValue = idInterpolate<float>::GetCurrentValue(
                             this: &this->laserBeamCutFade,
                             time: (float)((float)v121 * 0.001));
            fadeInDuration = this->laserBeamCut.fadeInDuration;
            v124 = CurrentValue;
            LODWORD(v125) = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
            v192 = v125;
            this->laserBeamCutFade.startValue = v124;
            this->laserBeamCutFade.endValue = 1.0;
            this->laserBeamCutFade.currentValue = v124;
            this->laserBeamCutFade.duration = (float)((float)1.0 - (float)v124) * (float)fadeInDuration;
            this->laserBeamCutFade.startTime = (float)v125 * (float)0.001;
            this->laserBeamCutFade.currentTime = (float)((float)v125 * (float)0.001) - (float)1.0;
          }
        }
        else
        {
          if ( this->cuttingWeldEffectRunning )
          {
            this->cuttingWeldEffectRunning = false;
            v104 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
            v105 = idWeapon::GetFXExtraCondition(this, secondary: true);
            idFXManager::StopFX(this: v77, time: v104, stopCondition: 74, extraCondition: v105, immediateStop: false);
            v106 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
            v107 = idWeapon::GetFXExtraCondition(this, secondary: true);
            idFXManager::StopFX(this: v77, time: v106, stopCondition: 76, extraCondition: v107, immediateStop: false);
            LODWORD(v108) = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
            v192 = v108;
            v109 = idInterpolate<float>::GetCurrentValue(
                     this: &this->laserBeamCutFade,
                     time: (float)((float)v108 * 0.001));
            v110 = this->laserBeamCut.fadeInDuration;
            v111 = v109;
            LODWORD(v112) = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
            v192 = v112;
            this->laserBeamCutFade.duration = (float)v110 * (float)v111;
            this->laserBeamCutFade.startValue = v111;
            this->laserBeamCutFade.endValue = 0.0;
            this->laserBeamCutFade.currentValue = v111;
            this->laserBeamCutFade.startTime = (float)v112 * (float)0.001;
            this->laserBeamCutFade.currentTime = (float)((float)v112 * (float)0.001) - (float)1.0;
          }
          if ( this->batteryCount != 0 )
          {
            idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
            v113 = idWeapon::GetFXExtraCondition(this, secondary: true);
            idFXManager::StartFX(
              this: v77,
              org: &vec3_origin,
              axis: &mat3_identity,
              time: v114,
              startCondition: 77,
              extraCond: v113);
          }
        }
      }
      else
      {
        v79 = idGameTimeManager::GetGameMs(this: p_gameTimeManager, type: GAMETIME_SCALED);
        v80 = idWeapon::GetFXExtraCondition(this, secondary: true);
        idFXManager::StopFX(this: v77, time: v79, stopCondition: 78, extraCondition: v80, immediateStop: false);
        v81 = &clientGame->gameTimeManager;
        if ( (*((_BYTE *)&this->idWeapon + 453) & 0x40) != 0 )
        {
          idGameTimeManager::GetGameMs(this: v81, type: GAMETIME_SCALED);
          v82 = idWeapon::GetFXExtraCondition(this, secondary: false);
          idFXManager::StartFX(
            this: v77,
            org: &vec3_origin,
            axis: &mat3_identity,
            time: v83,
            startCondition: 83,
            extraCond: v82);
          idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
          v84 = idWeapon::GetFXExtraCondition(this, secondary: false);
          idFXManager::StartFX(
            this: v77,
            org: &vec3_origin,
            axis: &mat3_identity,
            time: v85,
            startCondition: 84,
            extraCond: v84);
        }
        else
        {
          v86 = idGameTimeManager::GetGameMs(this: v81, type: GAMETIME_SCALED);
          v87 = idWeapon::GetFXExtraCondition(this, secondary: false);
          idFXManager::StopFX(this: v77, time: v86, stopCondition: 83, extraCondition: v87, immediateStop: false);
          v88 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
          v89 = idWeapon::GetFXExtraCondition(this, secondary: false);
          idFXManager::StopFX(this: v77, time: v88, stopCondition: 84, extraCondition: v89, immediateStop: false);
        }
      }
    }
  }
  v132 = this->weaponState;
  if ( v132 == WEAPONSTATE_SECONDARY || (*((_BYTE *)&this->idWeapon + 453) & 0x40) == 0 )
    goto LABEL_97;
  nextFireTime = this->nextFireTime;
  if ( this->laserBeamShoot.fadeOutDuration <= 0.0 )
  {
    LODWORD(v140) = nextFireTime
                  - idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    HIDWORD(v140) = this->weaponState - 1;
    v192 = v140;
    LODWORD(v141) = idWeapon::GetFiringInterval(this, secondaryAmmo: (_cntlzw(HIDWORD(v140)) & 0x20) != 0);
    __asm { fsel      f11, f12, f12, f31 }
    v192 = v141;
    v139 = (float)((float)_FP11 / (float)v141);
    if ( v139 <= 0.0 )
      goto LABEL_90;
  }
  else
  {
    v134 = nextFireTime - idWeapon::GetFiringInterval(this, secondaryAmmo: (_cntlzw(v132 - 1) & 0x20) != 0);
    LODWORD(v135) = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) - v134;
    _FP9 = (float)v135;
    __asm { fsel      f8, f9, f9, f31 }
    v138 = (float)((float)_FP8 / (float)(this->laserBeamShoot.fadeOutDuration * (float)1000.0));
    v192 = v135;
    if ( v138 <= 0.0 )
      v138 = 0.0;
    v139 = (float)((float)1.0 - (float)v138);
  }
  if ( v139 > 0.0 )
  {
    if ( this->currentFunctionalityLens == FUNCTIONALITY_LENS_REFLECTION && this->functionalityLensActive )
    {
      LODWORD(v144) = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      v192 = v144;
      this->laserBeamBounceIndicationFade.duration = 0.5;
      this->laserBeamBounceIndicationFade.startValue = 0.0;
      this->laserBeamBounceIndicationFade.endValue = 1.0;
      this->laserBeamBounceIndicationFade.currentValue = 0.0;
      this->laserBeamBounceIndicationFade.startTime = (float)v144 * (float)0.001;
      this->laserBeamBounceIndicationFade.currentTime = (float)((float)v144 * (float)0.001) - (float)1.0;
    }
    v145 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    idLaserSight::Show(this: &this->laserBeamShoot, startTime: v145);
    idLaserSight::Update(
      this: &this->laserBeamShoot,
      startPos,
      endPos: &v191,
      axis: &mat3_identity,
      sizeScale: 1.0,
      fade: v139);
    if ( this->currentFunctionalityLens == FUNCTIONALITY_LENS_REFLECTION
      && this->functionalityLensActive
      && this->storedBeamImpactPosIsValid )
    {
      v146 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      idLaserSight::Show(this: &this->laserBeamShootBounce, startTime: v146);
      v147 = (float)((float)(this->storedBeamImpactPos.y * v199)
                   + (float)((float)(v196 * this->storedBeamImpactPos.x) + (float)(this->storedBeamImpactPos.z * v202)));
      v148 = (float)((float)(this->storedBeamImpactPos.y * v200)
                   + (float)((float)(v197 * this->storedBeamImpactPos.x) + (float)(this->storedBeamImpactPos.z * v203)));
      v149 = (float)((float)(this->storedBeamImpactPos.y * v201)
                   + (float)((float)(v198 * this->storedBeamImpactPos.x) + (float)(this->storedBeamImpactPos.z * v204)));
      v205.y = (float)(this->storedBeamImpactPos.y * v200)
             + (float)((float)(v197 * this->storedBeamImpactPos.x) + (float)(this->storedBeamImpactPos.z * v203));
      v205.x = v147;
      v205.z = v149;
      v211.x = (float)v147 + v191.x;
      v211.y = v191.y + (float)v148;
      v211.z = v191.z + (float)v149;
      idLaserSight::Update(
        this: &this->laserBeamShootBounce,
        startPos: &v191,
        endPos: &v211,
        axis: &mat3_identity,
        sizeScale: 1.0,
        fade: v139);
      goto LABEL_100;
    }
    p_laserBeamShootBounce = &this->laserBeamShootBounce;
    goto LABEL_99;
  }
LABEL_90:
  LODWORD(v151) = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  v192 = v151;
  v152 = idInterpolate<float>::GetCurrentValue(
           this: &this->laserBeamBounceIndicationFade,
           time: (float)((float)v151 * 0.001));
  if ( v152 > 0.00000011920929 )
  {
    v153 = &v212;
    v154 = &v195;
    for ( i = 9; i != 0; --i )
      *++v153 = *++v154;
    v213.mat[0].x = v202;
    v213.mat[0].y = v203;
    v213.mat[0].z = v204;
    v213.mat[1].x = v199;
    v213.mat[1].y = v200;
    v213.mat[1].z = v201;
    v213.mat[2].x = v196;
    v213.mat[2].y = v197;
    v213.mat[2].z = v198;
    v156 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    idLaserSight::Show(this: &this->laserBeamShootIndication, startTime: v156);
    idLaserSight::Update(
      this: &this->laserBeamShootIndication,
      startPos,
      endPos: &v191,
      axis: &v213,
      sizeScale: 1.0,
      fade: v152);
    if ( this->currentFunctionalityLens == FUNCTIONALITY_LENS_REFLECTION && this->functionalityLensActive && v29 != 0 )
    {
      v157 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      idLaserSight::Show(this: &this->laserBeamShootBounceIndication, startTime: v157);
      idLaserSight::Update(
        this: &this->laserBeamShootBounceIndication,
        startPos: &v191,
        endPos: &v205,
        axis: &v213,
        sizeScale: 1.0,
        fade: v152);
      goto LABEL_100;
    }
    goto LABEL_98;
  }
LABEL_97:
  idLaserSight::Hide(this: &this->laserBeamShoot);
  idLaserSight::Hide(this: &this->laserBeamShootBounce);
  idLaserSight::Hide(this: &this->laserBeamShootIndication);
LABEL_98:
  p_laserBeamShootBounce = &this->laserBeamShootBounceIndication;
LABEL_99:
  idLaserSight::Hide(this: p_laserBeamShootBounce);
LABEL_100:
  LODWORD(v158) = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  v192 = v158;
  v159 = idInterpolate<float>::GetCurrentValue(this: &this->laserBeamCutFade, time: (float)((float)v158 * 0.001));
  if ( v159 >= 0.00000011920929 )
  {
    v160 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    idLaserSight::Show(this: &this->laserBeamCut, startTime: v160);
    idLaserSight::Update(
      this: &this->laserBeamCut,
      startPos,
      endPos: &v191,
      axis: &mat3_identity,
      sizeScale: 1.0,
      fade: v159);
    if ( this->currentFunctionalityLens == FUNCTIONALITY_LENS_REFLECTION
      && this->functionalityLensActive
      && this->storedBeamImpactPosIsValid
      && v30
      && ValidTraceResultFocusEntity == nullptr )
    {
      v161 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      idLaserSight::Show(this: &this->laserBeamCutBounce, startTime: v161);
      v162 = (float)((float)(v196 * this->storedBeamImpactPos.x)
                   + (float)((float)(this->storedBeamImpactPos.z * v202) + (float)(this->storedBeamImpactPos.y * v199)));
      v163 = (float)((float)(this->storedBeamImpactPos.y * v200)
                   + (float)((float)(v197 * this->storedBeamImpactPos.x) + (float)(this->storedBeamImpactPos.z * v203)));
      v164 = (float)((float)(this->storedBeamImpactPos.y * v201)
                   + (float)((float)(v198 * this->storedBeamImpactPos.x) + (float)(this->storedBeamImpactPos.z * v204)));
      v205.y = (float)(this->storedBeamImpactPos.y * v200)
             + (float)((float)(v197 * this->storedBeamImpactPos.x) + (float)(this->storedBeamImpactPos.z * v203));
      v205.x = v162;
      v205.z = v164;
      v215.x = (float)v162 + v191.x;
      v215.y = v191.y + (float)v163;
      v215.z = v191.z + (float)v164;
      idLaserSight::Update(
        this: &this->laserBeamCutBounce,
        startPos: &v191,
        endPos: &v215,
        axis: &mat3_identity,
        sizeScale: 1.0,
        fade: v159);
    }
  }
  else
  {
    idLaserSight::Hide(this: &this->laserBeamCut);
    idLaserSight::Hide(this: &this->laserBeamCutBounce);
  }
  v165 = this->weaponState;
  this->crosshairShouldPulsate = false;
  if ( v165 == WEAPONSTATE_SECONDARY && ValidTraceResultFocusEntity != nullptr )
  {
    this->crosshairShouldPulsate = true;
    return;
  }
  if ( (*((_BYTE *)&this->idWeapon + 453) & 0x40) != 0 && ValidTraceResultFocusEntity != nullptr )
  {
    if ( (unsigned __int8)idClass::IsType(this: ValidTraceResultFocusEntity, superclass: &idAI2::Type) != 0 )
    {
      v166 = idAI2::CastTo(c: (idAI2 *)ValidTraceResultFocusEntity);
    }
    else
    {
      if ( (unsigned __int8)idClass::IsType(
                              this: ValidTraceResultFocusEntity,
                              superclass: (const idTypeInfo *)HIDWORD(v208)) == 0 )
        return;
      v166 = idTurret::CastTo(c: (idTurret *)ValidTraceResultFocusEntity);
    }
    this->crosshairShouldPulsate = (_cntlzw((*(unsigned __int8 (__fastcall **)(void *))(*(_DWORD *)v166 + 508))(a1: v166))
                                  & 0x20) != 0;
  }
}


// ========================================================================
// ?UpdateHiddenMeshes@idLaserCutter@@UAAXPAVidTreeAnimator@@@Z
// EA  : 0x82EC1E88
// RVA : 0x00EC1E88
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __fastcall idLaserCutter::UpdateHiddenMeshes(idLaserCutter *this, idTreeAnimator *animator)
{
  idWeapon::ShowHideUpgradeMeshes(
    this,
    animator,
    hasTheUpgrade: this->hasBatteryUpgrade,
    upgradeMD6Info: (const upgradeInfoMD6 *)&this->decl[4].trackedMemory);
  idWeapon::ShowHideUpgradeMeshes(
    this,
    animator,
    hasTheUpgrade: this->hasRemoteCuttingUpgrade,
    upgradeMD6Info: (const upgradeInfoMD6 *)&this->decl[4].textSource);
  idWeapon::ShowHideUpgradeMeshes(
    this,
    animator,
    hasTheUpgrade: this->hasMobileReactorUpgrade,
    upgradeMD6Info: (const upgradeInfoMD6 *)&this->decl[4].inventoryClass.data);
  idWeapon::UpdateHiddenMeshes(this, animator);
}


// ========================================================================
// ?UnloadAmmo@idLaserCutter@@UAAXPAVidInventoryCollection@@PAVidFXManager@@_N@Z
// EA  : 0x82EC1F08
// RVA : 0x00EC1F08
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __fastcall idLaserCutter::UnloadAmmo(
        idLaserCutter *this,
        idInventoryCollection *inventory,
        idFXManager *fxMgr,
        bool secondaryAmmo)
{
  BOOL v4; // r27
  idAmmoItem *ammoClipSecondary; // r28
  int GameMs; // r26
  fxExtraCondition_t FXExtraCondition; // r3

  v4 = secondaryAmmo;
  if ( secondaryAmmo )
    ammoClipSecondary = this->ammoClipSecondary;
  else
    ammoClipSecondary = this->ammoClip;
  if ( ammoClipSecondary != nullptr )
  {
    if ( fxMgr != nullptr )
    {
      GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      FXExtraCondition = idWeapon::GetFXExtraCondition(this, secondary: secondaryAmmo);
      idFXManager::StopFX(
        this: fxMgr,
        time: GameMs,
        stopCondition: 67,
        extraCondition: FXExtraCondition,
        immediateStop: false);
    }
    if ( v4 )
      this->ammoClipSecondary = nullptr;
    else
      this->ammoClip = nullptr;
    ((void (__fastcall *)(idAmmoItem *, int))ammoClipSecondary->dtr_idClass)(a1: ammoClipSecondary, a2: 1);
  }
}


// ========================================================================
// ?ClickWeapon@idLaserCutter@@UAAXPAVidActor@@_N@Z
// EA  : 0x82EC1FC0
// RVA : 0x00EC1FC0
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __fastcall idLaserCutter::ClickWeapon(idLaserCutter *this, idActor *user, bool secondaryAmmo)
{
  int GameMs; // r26
  int FiringInterval; // r3
  idFXManager *v7; // r28
  int v8; // r27
  fxExtraCondition_t FXExtraCondition; // r3
  __int32 v10; // r3
  unsigned int v11; // r6

  if ( !secondaryAmmo && this->triggerState != TRIGGERSTATE_PULLED )
  {
    this->burstCount = 0;
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    FiringInterval = idWeapon::GetFiringInterval(this, secondaryAmmo: false);
    this->triggerState = TRIGGERSTATE_PULLED;
    this->nextFireTime = FiringInterval + GameMs;
    idWeapon::IsMelee(this);
    this->fireState = FIRESTATE_IDLE;
    v7 = user->GetFXMgrForAttachment(this: user, a2: this);
    v8 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    FXExtraCondition = idWeapon::GetFXExtraCondition(this, secondary: false);
    idFXManager::StopFX(this: v7, time: v8, stopCondition: 82, extraCondition: FXExtraCondition, immediateStop: false);
    idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    v10 = idWeapon::GetFXExtraCondition(this, secondary: false);
    idFXManager::StartFX(
      this: v7,
      org: &vec3_origin,
      axis: &mat3_identity,
      time: v11,
      startCondition: 81,
      extraCond: v10);
  }
}


// ========================================================================
// ?GetVehicleFromKey@idVehicleKey@@QBAPAVidVehicle@@XZ
// EA  : 0x82EC20E0
// RVA : 0x00EC20E0
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

idVehicle *__fastcall idVehicleKey::GetVehicleFromKey(idVehicleKey *this)
{
  idLinkList<idVehicle> *next; // r11
  idVehicle *owner; // r31
  idLinkList<idVehicle> *v4; // r11

  if ( this->referenceVehicleName.len == 0 )
    return nullptr;
  next = gameLocal->vehicleEntities.next;
  if ( next == nullptr )
    return nullptr;
  if ( next == gameLocal->vehicleEntities.head )
    return nullptr;
  owner = next->owner;
  if ( owner == nullptr )
    return nullptr;
  while ( idStr::Icmp(s1: this->referenceVehicleName.data, s2: owner->name.data) != 0 )
  {
    v4 = owner->controlNode.next;
    if ( v4 == nullptr || v4 == owner->controlNode.head )
      owner = nullptr;
    else
      owner = v4->owner;
    if ( owner == nullptr )
      return nullptr;
  }
  return owner;
}


// ========================================================================
// ?WriteToFile@idVehicleKey@@QBAXPAVidFile@@@Z
// EA  : 0x82EC21A0
// RVA : 0x00EC21A0
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __fastcall idVehicleKey::WriteToFile(idVehicleKey *this, idFile *file)
{
  double health; // fp0
  unsigned int (__fastcall *Write)(idFile *, const void *, unsigned int); // ctr
  idFile_vtbl *v6; // r6
  int v7; // r29
  int v8; // r28
  idFile_vtbl *v9; // r10
  int v10; // r28
  int v11; // r29
  idFile_vtbl *v12; // r8
  char v13; // r11
  char v14; // r7
  int len; // [sp+50h] [-40h] BYREF
  float v16; // [sp+54h] [-3Ch] BYREF
  int num; // [sp+58h] [-38h] BYREF
  int v18; // [sp+5Ch] [-34h] BYREF

  health = this->health;
  if ( health == -1.0 || health > 0.0 )
  {
    file->Write(this: file, a2: &this->health, a3: 4u);
  }
  else
  {
    Write = file->Write;
    v16 = this->maxHealth * (float)0.25;
    Write(this: file, a2: &v16, a3: 4u);
  }
  file->Write(this: file, a2: &this->vehicleGarage, a3: 4u);
  file->Write(this: file, a2: &this->enterVehicle, a3: 1u);
  file->Write(this: file, a2: &this->shouldGarageView, a3: 1u);
  file->Write(this: file, a2: &this->position, a3: 12u);
  file->Write(this: file, a2: &this->orientation, a3: 36u);
  file->Write(this: file, a2: &this->initArmorFromVehicle, a3: 1u);
  file->Write(this: file, a2: &this->currentWeaponGroup, a3: 4u);
  file->Write(this: file, a2: &this->upgradeAvailable, a3: 1u);
  v6 = file->__vftable;
  num = this->equippedUpgrades.num;
  v6->Write(this: file, a2: &num, a3: 4u);
  v7 = 0;
  if ( this->equippedUpgrades.num > 0 )
  {
    v8 = 0;
    do
    {
      idFile::WriteString(this: file, string: this->equippedUpgrades.list[v8]->name.str);
      ++v7;
      ++v8;
    }
    while ( v7 < this->equippedUpgrades.num );
  }
  v9 = file->__vftable;
  v18 = this->armorInfo.num;
  v9->Write(this: file, a2: &v18, a3: 4u);
  v10 = 0;
  if ( this->armorInfo.num > 0 )
  {
    v11 = 0;
    do
    {
      idFile::WriteString(this: file, string: this->armorInfo.list[v11].decl->name.str);
      file->Write(this: file, a2: &this->armorInfo.list[v11].health, a3: 4u);
      ++v10;
      ++v11;
    }
    while ( v10 < this->armorInfo.num );
  }
  file->Write(this: file, a2: &this->doTotalRepairOnSpawn, a3: 1u);
  v12 = file->__vftable;
  len = this->referenceVehicleName.len;
  v13 = BYTE1(len);
  v14 = HIBYTE(len);
  BYTE1(len) = BYTE2(len);
  HIBYTE(len) = len;
  LOBYTE(len) = v14;
  BYTE2(len) = v13;
  v12->Write(this: file, a2: &len, a3: 4u);
  file->Write(this: file, a2: this->referenceVehicleName.data, a3: this->referenceVehicleName.len);
  file->Write(this: file, a2: &this->numVehicleKills, a3: 4u);
}


// ========================================================================
// ?CanUse@idPlayerArmor@@UAA_NPAVidActor@@@Z
// EA  : 0x82EC2480
// RVA : 0x00EC2480
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

int __fastcall idPlayerArmor::CanUse(idPlayerArmor *this, idPlayer *user)
{
  idBaseHealth *v3; // r3
  idTungstenHealth *p_playerHealth; // r30
  double v5; // fp31
  double v6; // fp1
  int result; // r3

  v3 = user->GetHealthComponent_2(this: user);
  if ( v3 == nullptr )
    return 0;
  if ( v3->IsDead_Impl(this: v3) )
    return 0;
  if ( (unsigned __int8)idPlayer::IsTypeOf(c: user) == 0 )
    return 0;
  p_playerHealth = &idPlayer::CastTo(c: user)->playerHealth;
  v5 = ((double (__fastcall *)(idTungstenHealth *, int))p_playerHealth->GetComponentCur_Impl)(a1: p_playerHealth, a2: 1);
  v6 = ((double (__fastcall *)(idTungstenHealth *, int))p_playerHealth->GetComponentMax_Impl)(a1: p_playerHealth, a2: 1);
  result = 1;
  if ( v5 >= v6 )
    return 0;
  return result;
}


// ========================================================================
// ?Use@idPlayerArmor@@UAA_NPAVidActor@@@Z
// EA  : 0x82EC2558
// RVA : 0x00EC2558
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

int __fastcall idPlayerArmor::Use(idPlayerArmor *this, idPlayer *user)
{
  idPlayer *v3; // r3
  idPlayer *v4; // r31
  struct idTungstenHealth *p_playerHealth; // r30
  double v6; // fp31

  v3 = idPlayer::CastTo(c: user);
  v4 = v3;
  if ( v3 != nullptr )
  {
    p_playerHealth = &v3->playerHealth;
    v6 = ((double (__fastcall *)(idTungstenHealth *, int))v3->playerHealth.GetComponentMax_Impl)(
           a1: &v3->playerHealth,
           a2: 1);
    _FP12 = (float)((float)(this->curArmorValue + v4->playerHealth.GetComponentCur_Impl(this: p_playerHealth, a2: 1))
                  - (float)v6);
    __asm { fsel      f1, f12, f31, f13# value }
    idPlayer::SetArmor(this: v4, value: _FP1);
    return 1;
  }
  else
  {
    idLib::Warning(fmt: "got use idPlayerArmor for something other then a player");
    return 0;
  }
}


// ========================================================================
// ?OnClone@idSecretItem@@UAAXPBVidInventoryItem@@@Z
// EA  : 0x82EC2600
// RVA : 0x00EC2600
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __fastcall idSecretItem::OnClone(idSecretItem *this, idSecretItem *fromItem)
{
  int v4; // r3
  int secretId; // r8

  v4 = fromItem->GetCount(this: fromItem);
  idInventoryItem::SetCount(this, amount: v4);
  this->quickSlot = fromItem->quickSlot;
  secretId = idSecretItem::CastTo(c: fromItem)->secretId;
  this->needSetup = false;
  this->secretId = secretId;
}


// ========================================================================
// ??0idVehicleQuickItem@@QAA@XZ
// EA  : 0x82EC2678
// RVA : 0x00EC2678
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

idVehicleQuickItem *__fastcall idVehicleQuickItem::idVehicleQuickItem(idVehicleQuickItem *this)
{
  idEventReceiver::idEventReceiver(this);
  this->decl = nullptr;
  this->count = 0;
  this->__vftable = (idVehicleQuickItem_vtbl *)&idVehicleQuickItem::`vftable';
  this->forSale = false;
  this->lootable = false;
  this->buyBackItem = false;
  this->alreadyDropped = false;
  this->quickSlot = -1;
  this->counttosave = -1;
  this->coolDownTime = 0;
  this->skinPreload = nullptr;
  this->vehicle.spawnId.value = 0x1FFF;
  this->active = false;
  this->activateTime = 0;
  this->deleteWhenInactive = false;
  this->presentableOwner.spawnId = 0;
  return this;
}


// ========================================================================
// ?Use@idVehicleQuickItem@@UAA_NPAVidPresentableVehicle@@@Z
// EA  : 0x82EC2710
// RVA : 0x00EC2710
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

int __fastcall idVehicleQuickItem::Use(idVehicleQuickItem *this, idPresentableVehicle *presentable)
{
  idPresentableVehicle *v5; // r29
  int v6; // r10
  int v7; // r7
  int v8; // r6
  int v9; // r5
  int GameMs; // r3
  const idDeclInventory *decl; // r9
  int singular; // r8
  idInventoryCollection *v13; // r3
  const idDeclInventory *v14; // r11
  const idSoundShader *useSound; // r5
  int v16; // [sp+8h] [-78h]
  int v17; // [sp+Ch] [-74h]
  int v18; // [sp+10h] [-70h]
  int v19; // [sp+14h] [-6Ch]
  int v20; // [sp+18h] [-68h]
  idVehicleQuickItem *v21; // [sp+1Ch] [-64h]

  if ( this->active )
    return 0;
  v5 = presentable->GetVehicleInterface(this: presentable);
  if ( v5 == nullptr )
    return 0;
  this->presentableOwner.spawnId = presentable->spawnId;
  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  decl = this->decl;
  this->activateTime = GameMs;
  this->active = true;
  singular = decl->singular;
  if ( !decl->singular && idInventoryItem::ModifyCount(this, amount: -1) <= 0 )
  {
    singular = common->IsMultiplayer(this: common);
    if ( singular == 0 )
    {
      v13 = v5->GetInventory(this: &v5->idPresentableAnimatedEntity);
      idInventoryCollection::RemoveItemFromInventory(
        this: v13,
        owner: &presentable->idPresentableAnimatedEntity,
        item: this);
    }
    this->deleteWhenInactive = true;
  }
  idPresentableVehicle::AddQuickItemThink(
    this: v5,
    item: this,
    a3: v9,
    a4: v8,
    a5: v7,
    a6: singular,
    a7: (int)decl,
    a8: v6,
    a9: v16,
    a10: v17,
    a11: v18,
    a12: v19,
    a13: v20,
    a14: v21);
  v14 = this->decl;
  if ( v14 != nullptr )
  {
    useSound = v14->useSound;
    if ( useSound != nullptr )
      v5->StartSoundShader_Predicted(this: v5, a2: SND_CHANNEL_ITEM, a3: useSound, a4: 0);
  }
  return 1;
}


// ========================================================================
// ?Use@idVehicle_BoostExtender@@UAA_NPAVidPresentableVehicle@@@Z
// EA  : 0x82EC2840
// RVA : 0x00EC2840
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

int __fastcall idVehicle_BoostExtender::Use(idVehicle_BoostExtender *this, idPresentableVehicle *presentable)
{
  const idDeclInventory *decl; // r30
  idClientServerInterface *csInterface; // r30
  bool v6; // r3
  unsigned __int8 v7; // r11

  decl = this->decl;
  if ( decl == nullptr || presentable == nullptr )
    return 0;
  if ( this->active
    && idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) - this->activateTime > (int)decl[1].resourceListPtr )
  {
    this->active = false;
  }
  csInterface = presentable->csInterface;
  if ( csInterface == nullptr )
    return 0;
  if ( (unsigned __int8)idVehicleQuickItem::Use(this, presentable) == 0 )
    return 0;
  v6 = csInterface->VehicleBoostExtenderUse(this: csInterface, a2: this, a3: &presentable->idPresentableAnimatedEntity);
  v7 = 1;
  if ( !v6 )
    return 0;
  return v7;
}


// ========================================================================
// ?Use@idVehicle_Smash@@UAA_NPAVidPresentableVehicle@@@Z
// EA  : 0x82EC2918
// RVA : 0x00EC2918
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

int __fastcall idVehicle_Smash::Use(idVehicle_Smash *this, idPresentableVehicle *presentable)
{
  const idDeclInventory *decl; // r30
  idClientServerInterface *csInterface; // r30
  bool v6; // r3
  unsigned __int8 v7; // r11

  decl = this->decl;
  if ( decl == nullptr || presentable == nullptr )
    return 0;
  if ( this->active
    && idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) - this->activateTime > (int)decl[1].resourceListPtr )
  {
    this->active = false;
  }
  csInterface = presentable->csInterface;
  if ( csInterface == nullptr )
    return 0;
  if ( (unsigned __int8)idVehicleQuickItem::Use(this, presentable) == 0 )
    return 0;
  v6 = csInterface->VehicleSmashUse(this: csInterface, a2: this, a3: &presentable->idPresentableAnimatedEntity);
  v7 = 1;
  if ( !v6 )
    return 0;
  return v7;
}


// ========================================================================
// ?Use@idVehicle_Shockwave@@UAA_NPAVidPresentableVehicle@@@Z
// EA  : 0x82EC29F0
// RVA : 0x00EC29F0
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

int __fastcall idVehicle_Shockwave::Use(idVehicle_Shockwave *this, idPresentableVehicle *presentable)
{
  idClientServerInterface *csInterface; // r30
  bool v5; // r3
  unsigned __int8 v6; // r11

  if ( presentable == nullptr )
    return 0;
  csInterface = presentable->csInterface;
  if ( csInterface == nullptr )
    return 0;
  if ( (unsigned __int8)idVehicleQuickItem::Use(this, presentable) == 0 )
    return 0;
  v5 = csInterface->VehicleShockwaveUse(this: csInterface, a2: this, a3: &presentable->idPresentableAnimatedEntity);
  v6 = 1;
  if ( !v5 )
    return 0;
  return v6;
}


// ========================================================================
// ?Use@idVehicle_Aftershocker@@UAA_NPAVidPresentableVehicle@@@Z
// EA  : 0x82EC2A70
// RVA : 0x00EC2A70
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

int __fastcall idVehicle_Aftershocker::Use(idVehicle_Aftershocker *this, idPresentableVehicle *presentable)
{
  idClientServerInterface *csInterface; // r29
  idVehicle_Car *entity; // r30
  bool v6; // r3
  unsigned __int8 v7; // r11

  if ( presentable == nullptr )
    return 0;
  csInterface = presentable->csInterface;
  if ( csInterface == nullptr )
    return 0;
  entity = (idVehicle_Car *)presentable->entity;
  if ( entity == nullptr || (unsigned __int8)idVehicle_Car::CanActivateQuickUse(this: entity, t: 0) == 0 )
    return 0;
  idVehicle_Car::AddQuickUseActive(this: entity, t: 0, timeMS: 3000);
  if ( (unsigned __int8)idVehicleQuickItem::Use(this, presentable) == 0 )
    return 0;
  v6 = csInterface->VehicleAftershockerUse(this: csInterface, a2: this, a3: &presentable->idPresentableAnimatedEntity);
  v7 = 1;
  if ( !v6 )
    return 0;
  return v7;
}


// ========================================================================
// ?Use@idVehicle_Aftershock_MP@@UAA_NPAVidPresentableVehicle@@@Z
// EA  : 0x82EC2B30
// RVA : 0x00EC2B30
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

int __fastcall idVehicle_Aftershock_MP::Use(
        idVehicle_Aftershock_MP *this,
        idPresentableVehicle *presentable,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
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
        float a35,
        float a36,
        float a37,
        int a38,
        unsigned int *a39,
        int a40,
        float a41,
        float a42,
        float a43,
        int a44,
        int a45,
        int a46,
        float a47,
        float a48,
        float a49,
        float a50,
        float a51,
        float a52,
        int a53,
        int a54,
        int *a55,
        int *a56,
        int a57,
        int a58,
        int a59,
        int a60,
        int a61,
        int a62,
        __int64 a63,
        float a64)
{
  float a65; // [sp+867Ch] [+CCh]
  float a66; // [sp+8680h] [+D0h]
  int a70; // [sp+8690h] [+E0h] BYREF
  __int64 v70; // r4
  idVehicleQuickItem *v71; // r31
  idPresentableVehicle *v72; // r16
  const idDeclInventory *decl; // r30
  __int64 v75; // r29
  idPhysics_AF *p_physicsObj; // r21
  float *v77; // r3
  double v78; // fp8
  double v79; // fp7
  double v80; // fp6
  int EntitiesTouchingBounds; // r3
  int *v82; // r30
  int v83; // r14
  idPresentable *PresentableByEntityNum; // r3
  idPresentableVehicle *v85; // r3
  idPhysics_AF *v86; // r31
  idPresentablePlayer *PlayerDriver; // r11
  int entityNumber; // r30
  float *v89; // r14
  float *v90; // r3
  double v91; // fp13
  double v92; // fp10
  double v93; // fp9
  double v94; // fp31
  double v95; // fp30
  double v96; // fp29
  double v97; // fp28
  float *v98; // r3
  double v99; // fp12
  double v100; // fp10
  double v101; // fp11
  double v102; // fp12
  double v103; // fp30
  double v104; // fp29
  double v105; // fp28
  double v106; // fp31
  double v107; // fp1
  idPresentablePlayer *v108; // r3
  float *v109; // r3
  int v110; // r31
  int *v111; // r30
  double v112; // fp7
  double v113; // fp6
  int v114; // r31
  int *v115; // r30
  idLobbyBase *v116; // r3

  v70 = ((__int64 (*)(void))RtlCheckStack12)();
  v71 = (idVehicleQuickItem *)HIDWORD(v70);
  v72 = (idPresentableVehicle *)v70;
  if ( (_DWORD)v70 == 0 )
    return 0;
  if ( (unsigned __int8)idPresentableVehicle::IsLocallyControlledByPlayer(this: (idPresentableVehicle *)v70) == 0 )
    return 0;
  decl = v71->decl;
  if ( decl == nullptr )
    return 0;
  LODWORD(v75) = 0;
  if ( v71->active
    && idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) - v71->activateTime > (int)decl[1].resourceListPtr )
  {
    v71->active = false;
  }
  if ( (unsigned __int8)idVehicleQuickItem::Use(this: v71, presentable: v72) == 0 )
    return 0;
  p_physicsObj = &v72->physicsObj;
  if ( v72 == (idPresentableVehicle *)-16512 )
    return 0;
  v77 = (float *)p_physicsObj->GetOrigin(this: &v72->physicsObj, a2: 0);
  a47 = *v77;
  a48 = v77[1];
  a49 = v77[2];
  v78 = (float)(*v77 + aftershock_radius.valueFloat);
  a50 = *v77;
  v79 = (float)(v77[1] + aftershock_radius.valueFloat);
  a51 = v77[1];
  v80 = v77[2];
  a47 = a47 - aftershock_radius.valueFloat;
  a48 = a48 - aftershock_radius.valueFloat;
  a49 = a49 - aftershock_radius.valueFloat;
  a50 = v78;
  a51 = v79;
  a52 = (float)v80 + aftershock_radius.valueFloat;
  EntitiesTouchingBounds = idClip::GetEntitiesTouchingBounds(
                             this: &clientGame->clip,
                             bounds: (const idBounds *)&a47,
                             clipMask: 0x10000,
                             entityList: (int *)&STACK[0x8A90],
                             maxCount: 0x2000);
  if ( EntitiesTouchingBounds > 0 )
  {
    v82 = (int *)&STACK[0x8A90];
    a39 = &STACK[0x8A90];
    v83 = EntitiesTouchingBounds;
    a40 = EntitiesTouchingBounds;
    do
    {
      if ( v72->entityNumber != *v82 )
      {
        PresentableByEntityNum = idClientGame::GetPresentableByEntityNum(this: clientGame, entityNum: *v82);
        if ( PresentableByEntityNum != nullptr )
        {
          v85 = PresentableByEntityNum->GetVehicleInterface(this: PresentableByEntityNum);
          HIDWORD(v75) = v85;
          if ( v85 != nullptr )
          {
            v86 = &v85->physicsObj;
            if ( v85 != (idPresentableVehicle *)-16512 )
            {
              PlayerDriver = idPresentableVehicle::GetPlayerDriver(this: v85);
              if ( PlayerDriver != nullptr )
              {
                entityNumber = PlayerDriver->entityNumber;
                v89 = (float *)p_physicsObj->GetOrigin(this: &v72->physicsObj, a2: 0);
                v90 = (float *)v86->GetOrigin(this: v86, a2: 0);
                v91 = v89[1];
                v92 = v90[1];
                v93 = (float)(v90[2] - v89[2]);
                a35 = *v90 - *v89;
                a37 = v93;
                a36 = (float)v92 - (float)v91;
                v94 = idVec3::NormalizeFast(this: (idVec3 *)&a35);
                v95 = (float)(a35 * aftershock_offset.valueFloat);
                v96 = (float)(a36 * aftershock_offset.valueFloat);
                v97 = (float)(aftershock_offset.valueFloat * a37);
                v98 = (float *)v86->GetOrigin(this: v86, a2: 0);
                v99 = (float)(v98[2] - (float)v97);
                v100 = (float)(v98[1] - (float)v96);
                a41 = *v98 - (float)v95;
                a43 = v99;
                a42 = v100;
                v101 = (float)((float)(aftershock_radius.valueFloat - (float)v94) / aftershock_radius.valueFloat);
                if ( v101 >= 0.0 )
                {
                  if ( v101 > 1.0 )
                    v101 = 1.0;
                }
                else
                {
                  v101 = 0.0;
                }
                v102 = 0.0;
                v103 = a36;
                v104 = a35;
                v105 = idMath::HALF_PI;
                v106 = (float)((float)((float)(aftershock_impulse_max.valueFloat - aftershock_impulse_min.valueFloat)
                                     * (float)v101)
                             + aftershock_impulse_min.valueFloat);
                if ( a37 > 0.0 )
                {
                  v107 = idMath::ATan16(y: a37, x: __fsqrts((float)((float)(a36 * a36) + (float)(a35 * a35))));
                  v102 = v107;
                  if ( v107 >= 0.0 )
                  {
                    if ( v107 > v105 )
                      v102 = v105;
                  }
                  else
                  {
                    v102 = 0.0;
                  }
                }
                a37 = idMath::Tan16(a: (float)((float)((float)((float)((float)-(float)((float)(aftershock_angle.valueFloat
                                                                                             * idMath::M_DEG2RAD)
                                                                                     - (float)v105)
                                                                     * idMath::ONE_OVER_PI)
                                                             * (float)v102)
                                                     * (float)2.0)
                                             + (float)(aftershock_angle.valueFloat * idMath::M_DEG2RAD)))
                    * (float)__fsqrts((float)((float)((float)v103 * (float)v103) + (float)((float)v104 * (float)v104)));
                idVec3::NormalizeFast(this: (idVec3 *)&a35);
                a35 = a35 * (float)v106;
                a36 = a36 * (float)v106;
                a37 = a37 * (float)v106;
                if ( aftershock_skipPredict.valueInteger == 0 )
                {
                  *(_BYTE *)(HIDWORD(v75) + 20456) = 1;
                  v86->ApplyImpulse(this: v86, a2: 0, a3: (const idVec3 *)&a41, a4: (const idVec3 *)&a35);
                }
                a57 = 1024;
                a58 = 0;
                a55 = &a70;
                a56 = &a70;
                a59 = 0;
                a60 = 0;
                a61 = 0;
                HIWORD(a62) = 0;
                a63 = v75;
                idBitMsg::WriteBits(this: (idBitMsg *)&a55, value: entityNumber, numBits: 8);
                v108 = idPresentableVehicle::GetPlayerDriver(this: v72);
                idBitMsg::WriteBits(this: (idBitMsg *)&a55, value: v108->entityNumber, numBits: 8);
                v109 = (float *)v86->GetOrigin(this: v86, a2: 0);
                v110 = 3;
                v111 = (int *)&a63 + 1;
                v112 = (float)(a42 - v109[1]);
                v113 = (float)(a43 - v109[2]);
                a64 = a41 - *v109;
                a65 = v112;
                a66 = v113;
                do
                {
                  a38 = *++v111;
                  idBitMsg::WriteBits(this: (idBitMsg *)&a55, value: a38, numBits: 32);
                  --v110;
                }
                while ( v110 != 0 );
                v114 = 3;
                v115 = &a34;
                do
                {
                  a38 = *++v115;
                  idBitMsg::WriteBits(this: (idBitMsg *)&a55, value: a38, numBits: 32);
                  --v114;
                }
                while ( v114 != 0 );
                v116 = session->GetActingGameStateLobbyBase(this: session);
                v116->SendReliableToHost(this: v116, a2: 51, a3: (idBitMsg *)&a55);
                v83 = a40;
                v82 = (int *)a39;
              }
            }
          }
        }
      }
      --v83;
      ++v82;
      a40 = v83;
      a39 = (unsigned int *)v82;
    }
    while ( v83 != 0 );
  }
  return 1;
}


// ========================================================================
// ?Use@idVehicle_EMP@@UAA_NPAVidPresentableVehicle@@@Z
// EA  : 0x82EC30A0
// RVA : 0x00EC30A0
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __fastcall idVehicle_EMP::Use(
        idVehicle_EMP *this,
        idPresentableVehicle *presentable,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        float a17,
        float a18,
        float a19,
        float a20,
        float a21,
        float a22,
        float a23,
        float a24,
        float a25,
        float a26,
        float a27,
        float a28,
        float a29,
        float a30,
        float a31,
        float a32,
        float a33,
        float a34,
        float a35,
        float a36,
        float a37,
        float a38,
        float a39,
        float a40,
        float a41,
        float a42,
        int *a43,
        int *a44,
        int a45,
        int a46,
        int a47,
        int a48,
        int a49,
        int a50,
        __int64 a51,
        float a52,
        float a53,
        int a54)
{
  __int64 v54; // r4
  idVehicleQuickItem *v55; // r30
  idPresentableVehicle *v56; // r28
  const idDeclInventory *decl; // r29
  int v59; // r31 OVERLAPPED
  float *v60; // r3
  double v61; // fp8
  double v62; // fp7
  double v63; // fp6
  int EntitiesTouchingBounds; // r3
  int *v65; // r25
  int i; // r24
  idPresentable *PresentableByEntityNum; // r3
  idPresentableVehicle *v68; // r3
  idPresentableVehicle *v69; // r30 OVERLAPPED
  idPresentablePlayer *PlayerDriver; // r29
  idPresentablePlayer *v71; // r3
  idLobbyBase *v72; // r3

  v54 = ((__int64 (*)(void))RtlCheckStack12)();
  v55 = (idVehicleQuickItem *)HIDWORD(v54);
  v56 = (idPresentableVehicle *)v54;
  if ( (_DWORD)v54 == 0 )
    return 0;
  if ( (unsigned __int8)idPresentableVehicle::IsLocallyControlledByPlayer(this: (idPresentableVehicle *)v54) == 0 )
  {
    idPresentableVehicle::StartPredictedFX(this: v56, cond: 30, extraCondition: 0);
    return 0;
  }
  decl = v55->decl;
  if ( decl == nullptr )
    return 0;
  v59 = 0;
  if ( v55->active
    && idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) - v55->activateTime > (int)decl[1].resourceListPtr )
  {
    v55->active = false;
  }
  if ( (unsigned __int8)idVehicleQuickItem::Use(this: v55, presentable: v56) == 0
    || v56 == (idPresentableVehicle *)-16512 )
  {
    return 0;
  }
  v60 = (float *)v56->physicsObj.GetOrigin(this: &v56->physicsObj, a2: 0);
  a35 = *v60;
  a36 = v60[1];
  a37 = v60[2];
  v61 = (float)(*v60 + aftershock_radius.valueFloat);
  a38 = *v60;
  v62 = (float)(v60[1] + aftershock_radius.valueFloat);
  a39 = v60[1];
  v63 = v60[2];
  a35 = a35 - aftershock_radius.valueFloat;
  a36 = a36 - aftershock_radius.valueFloat;
  a37 = a37 - aftershock_radius.valueFloat;
  a38 = v61;
  a39 = v62;
  a40 = (float)v63 + aftershock_radius.valueFloat;
  EntitiesTouchingBounds = idClip::GetEntitiesTouchingBounds(
                             this: &clientGame->clip,
                             bounds: (const idBounds *)&a35,
                             clipMask: 0x10000,
                             entityList: (int *)&STACK[0x8990],
                             maxCount: 0x2000);
  if ( EntitiesTouchingBounds > 0 )
  {
    v65 = (int *)&STACK[0x8990];
    for ( i = EntitiesTouchingBounds; i != 0; --i )
    {
      if ( v56->entityNumber != *v65 )
      {
        PresentableByEntityNum = idClientGame::GetPresentableByEntityNum(this: clientGame, entityNum: *v65);
        if ( PresentableByEntityNum != nullptr )
        {
          v68 = PresentableByEntityNum->GetVehicleInterface(this: PresentableByEntityNum);
          v69 = v68;
          if ( v68 != nullptr )
          {
            PlayerDriver = idPresentableVehicle::GetPlayerDriver(this: v68);
            if ( PlayerDriver != nullptr )
            {
              idPresentableVehicle::StartPredictedFX(this: v69, cond: 29, extraCondition: 0);
              a45 = 1024;
              a44 = &a54;
              a47 = 0;
              a49 = 0;
              a43 = &a54;
              a46 = 0;
              a48 = 0;
              HIWORD(a50) = 0;
              a51 = *(_QWORD *)&v59;
              idBitMsg::WriteBits(this: (idBitMsg *)&a43, value: PlayerDriver->entityNumber, numBits: 8);
              v71 = idPresentableVehicle::GetPlayerDriver(this: v56);
              idBitMsg::WriteBits(this: (idBitMsg *)&a43, value: v71->entityNumber, numBits: 8);
              v72 = session->GetActingGameStateLobbyBase(this: session);
              v72->SendReliableToHost(this: v72, a2: 55, a3: (idBitMsg *)&a43);
            }
          }
        }
      }
      ++v65;
    }
  }
  idPresentableVehicle::StartPredictedFX(this: v56, cond: 30, extraCondition: 0);
  return 1;
}


// ========================================================================
// ?Use@idVehicle_Teleporter@@UAA_NPAVidPresentableVehicle@@@Z
// EA  : 0x82EC3328
// RVA : 0x00EC3328
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

int __fastcall idVehicle_Teleporter::Use(idVehicle_Teleporter *this, idPresentableVehicle *presentable)
{
  idClientServerInterface *csInterface; // r3
  char v5; // r3
  unsigned __int8 v6; // r11

  if ( presentable == nullptr )
    return 0;
  csInterface = presentable->csInterface;
  if ( csInterface == nullptr )
    return 0;
  if ( !csInterface->VehicleTeleporterUse(this: csInterface, a2: this, a3: &presentable->idPresentableAnimatedEntity) )
    return 0;
  v5 = idVehicleQuickItem::Use(this, presentable);
  v6 = 1;
  if ( v5 == 0 )
    return 0;
  return v6;
}


// ========================================================================
// ?Use@idVehicle_Jump@@UAA_NPAVidPresentableVehicle@@@Z
// EA  : 0x82EC33C0
// RVA : 0x00EC33C0
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

int __fastcall idVehicle_Jump::Use(idVehicle_Jump *this, idPresentableVehicle *carPresentable)
{
  idClientServerInterface *csInterface; // r30
  bool v6; // r3
  unsigned __int8 v7; // r11

  if ( carPresentable == nullptr )
    return 0;
  csInterface = carPresentable->csInterface;
  if ( csInterface == nullptr
    || carPresentable->IsLocallyControlled(this: (struct idPresentableAnimatedEntity *)carPresentable)
    && carPresentable->numWheelsOnGround == 0 )
  {
    return 0;
  }
  if ( (unsigned __int8)idVehicleQuickItem::Use(this, presentable: carPresentable) == 0 )
    return 0;
  v6 = csInterface->VehicleJumpUse(this: csInterface, a2: this, a3: &carPresentable->idPresentableAnimatedEntity);
  v7 = 1;
  if ( !v6 )
    return 0;
  return v7;
}


// ========================================================================
// ?Use@idVehicle_Megabooster@@UAA_NPAVidPresentableVehicle@@@Z
// EA  : 0x82EC3478
// RVA : 0x00EC3478
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

int __fastcall idVehicle_Megabooster::Use(idVehicle_Megabooster *this, idPresentableVehicle *presentable)
{
  idClientServerInterface *csInterface; // r30
  bool v5; // r3
  unsigned __int8 v6; // r11

  if ( presentable == nullptr )
    return 0;
  csInterface = presentable->csInterface;
  if ( csInterface == nullptr )
    return 0;
  if ( (unsigned __int8)idVehicleQuickItem::Use(this, presentable) == 0 )
    return 0;
  v5 = csInterface->VehicleMegaboosterUse(this: csInterface, a2: this, a3: &presentable->idPresentableAnimatedEntity);
  v6 = 1;
  if ( !v5 )
    return 0;
  return v6;
}


// ========================================================================
// ?Use@idVehicle_Health@@UAA_NPAVidPresentableVehicle@@@Z
// EA  : 0x82EC34F8
// RVA : 0x00EC34F8
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

int __fastcall idVehicle_Health::Use(idVehicle_Health *this, idPresentableVehicle *presentable)
{
  idClientServerInterface *csInterface; // r30
  bool v5; // r3
  unsigned __int8 v6; // r11

  if ( presentable == nullptr )
    return 0;
  csInterface = presentable->csInterface;
  if ( csInterface == nullptr )
    return 0;
  if ( (unsigned __int8)idVehicleQuickItem::Use(this, presentable) == 0 )
    return 0;
  v5 = csInterface->VehicleHealthUse(this: csInterface, a2: this, a3: &presentable->idPresentableAnimatedEntity);
  v6 = 1;
  if ( !v5 )
    return 0;
  return v6;
}


// ========================================================================
// ?Use@idVehicle_Stomp@@UAA_NPAVidPresentableVehicle@@@Z
// EA  : 0x82EC3578
// RVA : 0x00EC3578
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

int __fastcall idVehicle_Stomp::Use(idVehicle_Stomp *this, idPresentableVehicle *presentable)
{
  idClientServerInterface *csInterface; // r30
  bool v5; // r3
  unsigned __int8 v6; // r11

  if ( presentable == nullptr )
    return 0;
  csInterface = presentable->csInterface;
  if ( csInterface == nullptr )
    return 0;
  if ( (unsigned __int8)idVehicleQuickItem::Use(this, presentable) == 0 )
    return 0;
  v5 = csInterface->VehicleStompUse(this: csInterface, a2: this, a3: &presentable->idPresentableAnimatedEntity);
  v6 = 1;
  if ( !v5 )
    return 0;
  return v6;
}


// ========================================================================
// ?Use@idVehicle_InstantDamage@@UAA_NPAVidPresentableVehicle@@@Z
// EA  : 0x82EC35F8
// RVA : 0x00EC35F8
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

int __fastcall idVehicle_InstantDamage::Use(idVehicle_InstantDamage *this, idPresentableVehicle *presentable)
{
  idClientServerInterface *csInterface; // r30
  bool v5; // r3
  unsigned __int8 v6; // r11

  if ( presentable == nullptr )
    return 0;
  csInterface = presentable->csInterface;
  if ( csInterface == nullptr )
    return 0;
  if ( (unsigned __int8)idVehicleQuickItem::Use(this, presentable) == 0 )
    return 0;
  v5 = csInterface->VehicleInstantDamageUse(this: csInterface, a2: this, a3: &presentable->idPresentableAnimatedEntity);
  v6 = 1;
  if ( !v5 )
    return 0;
  return v6;
}


// ========================================================================
// ?Use@idVehicle_QuickUseWeapon@@UAA_NPAVidPresentableVehicle@@@Z
// EA  : 0x82EC3678
// RVA : 0x00EC3678
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

int __fastcall idVehicle_QuickUseWeapon::Use(idVehicle_QuickUseWeapon *this, idPresentableVehicle *presentable)
{
  idClientServerInterface *csInterface; // r30
  bool v5; // r3
  unsigned __int8 v6; // r11

  if ( presentable == nullptr )
    return 0;
  csInterface = presentable->csInterface;
  if ( csInterface == nullptr )
    return 0;
  if ( (unsigned __int8)idVehicleQuickItem::Use(this, presentable) == 0 )
    return 0;
  v5 = csInterface->VehicleQuickUseWeaponUse(this: csInterface, a2: this, a3: &presentable->idPresentableAnimatedEntity);
  v6 = 1;
  if ( !v5 )
    return 0;
  return v6;
}


// ========================================================================
// ?VehicleBoostExtenderUse@idClientServerInterfaceServer@@UAA_NPAVidInventoryItem@@PAVidPresentable@@@Z
// EA  : 0x82EC3750
// RVA : 0x00EC3750
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

// attributes: thunk
int __fastcall idClientServerInterfaceServer::VehicleBoostExtenderUse(
        idClientServerInterfaceServer *this,
        idVehicle_BoostExtender *item,
        idPresentable *presentable)
{
  return idClientServerInterfaceClient::VehicleBoostExtenderUse(this, item, presentable);
}


// ========================================================================
// ?VehicleSmashUse@idClientServerInterfaceServer@@UAA_NPAVidInventoryItem@@PAVidPresentable@@@Z
// EA  : 0x82EC3758
// RVA : 0x00EC3758
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

// attributes: thunk
int __fastcall idClientServerInterfaceServer::VehicleSmashUse(
        idClientServerInterfaceServer *this,
        idVehicle_Smash *item,
        idPresentable *presentable)
{
  return idClientServerInterfaceClient::VehicleSmashUse(this, item, presentable);
}


// ========================================================================
// ?VehicleShockwaveUse@idClientServerInterfaceServer@@UAA_NPAVidInventoryItem@@PAVidPresentable@@@Z
// EA  : 0x82EC3760
// RVA : 0x00EC3760
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

// attributes: thunk
int __fastcall idClientServerInterfaceServer::VehicleShockwaveUse(
        idClientServerInterfaceServer *this,
        idVehicle_Shockwave *item,
        idPresentable *presentable)
{
  return idClientServerInterfaceClient::VehicleShockwaveUse(this, item, presentable);
}


// ========================================================================
// ?VehicleShockwaveThink@idClientServerInterfaceServer@@UAAXPAVidInventoryItem@@PAVidPresentable@@@Z
// EA  : 0x82EC3768
// RVA : 0x00EC3768
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __fastcall idClientServerInterfaceServer::VehicleShockwaveThink(
        idClientServerInterfaceServer *this,
        idInventoryItem *item,
        idPresentable *presentable,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        float a17,
        float a18,
        float a19,
        float a20,
        float a21,
        float a22,
        float a23,
        float a24,
        float a25,
        float a26,
        float a27,
        float a28,
        float a29,
        float a30,
        float a31,
        float a32,
        float a33,
        float a34,
        float a35,
        float a36,
        float a37,
        float a38,
        float a39,
        float a40,
        __int64 a41,
        float a42,
        float a43,
        float a44,
        float a45,
        int a46)
{
  __int64 v46; // r23
  idPresentable *v47; // r5
  idPresentable *v48; // r21
  idVehicleQuickItem *v49; // r3
  idVehicle_Car *v50; // r3
  idVehicle_Car *v51; // r29
  idPhysics *Physics; // r28
  idVehicle_Shockwave *v53; // r3
  idVehicle_Shockwave *v54; // r27
  double v55; // fp31
  __int64 v56; // r7
  __int64 v57; // r5
  double v58; // fp29
  float *v59; // r3
  double v60; // fp12
  double v61; // fp11
  double v62; // fp10
  double v63; // fp9
  int trackedMemory; // r8
  double v65; // fp5
  double v66; // fp3
  int EntitiesTouchingBounds; // r3
  int *v68; // r26
  int i; // r24
  idEntity *v70; // r3
  int *v71; // r31
  idPhysics *v72; // r3
  float *v73; // r3
  double v74; // fp28
  double v75; // fp27
  double v76; // fp26
  float *v77; // r3
  double v78; // fp5
  double v79; // fp1
  double v80; // fp1
  idPresentable *v81; // r3
  const idDeclInventory *decl; // r30
  idPresentableVehicle *v83; // r3
  int v84; // r20
  int v85; // r30
  idEntity *DriverEntity; // r3

  v46 = ((__int64 (*)(void))RtlCheckStack12)();
  v48 = v47;
  v49 = idVehicleQuickItem::CastTo(c: (idVehicleQuickItem *)v46);
  if ( v49 != nullptr && v49->active )
  {
    v50 = idVehicle_Car::CastTo(c: *(idVehicle_Car **)(HIDWORD(v46) + 4));
    v51 = v50;
    if ( v50 != nullptr )
    {
      Physics = idEntity::GetPhysics(this: v50);
      if ( Physics != nullptr )
      {
        v53 = idVehicle_Shockwave::CastTo(c: (idVehicle_Shockwave *)v46);
        v54 = v53;
        if ( v53 != nullptr )
        {
          v55 = (float)(*(float *)&v53->decl[1].name.str * (float)0.001);
          LODWORD(v56) = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
          HIDWORD(v56) = Physics->__vftable;
          LODWORD(v57) = v54->lastThinkTime;
          a41 = v57;
          v58 = (float)((float)((float)v56 - (float)v57) * (float)v55);
          v59 = (float *)(*(int (__fastcall **)(idPhysics *, _DWORD))(HIDWORD(v56) + 64))(a1: Physics, a2: 0);
          a35 = *v59;
          a36 = v59[1];
          v60 = v59[2];
          a37 = v59[2];
          v61 = *v59;
          a38 = *v59;
          v62 = v59[1];
          a39 = v59[1];
          v63 = v59[2];
          a40 = v59[2];
          trackedMemory = v54->decl[1].trackedMemory;
          v65 = *(float *)(trackedMemory + 200);
          v66 = (float)(a36 - *(float *)(trackedMemory + 200));
          a35 = a35 - *(float *)(trackedMemory + 200);
          a36 = v66;
          a37 = (float)v60 - (float)v65;
          a38 = (float)v61 + (float)v65;
          a39 = (float)v62 + (float)v65;
          a40 = (float)v63 + (float)v65;
          EntitiesTouchingBounds = idClip::GetEntitiesTouchingBounds(
                                     this: &clientGame->clip,
                                     bounds: (const idBounds *)&a35,
                                     clipMask: -1,
                                     entityList: &a46,
                                     maxCount: 0x2000);
          if ( EntitiesTouchingBounds > 0 )
          {
            v68 = &a46;
            for ( i = EntitiesTouchingBounds; i != 0; --i )
            {
              v70 = gameLocal->GetEntity(this: gameLocal, a2: *v68);
              v71 = (int *)v70;
              if ( v70 != v51 )
              {
                v72 = idEntity::GetPhysics(this: v70);
                v73 = (float *)v72->GetAbsBounds(this: v72, a2: -1);
                v74 = (float)((float)(v73[3] + *v73) * (float)0.5);
                v75 = (float)((float)(v73[4] + v73[1]) * (float)0.5);
                v76 = (float)((float)(v73[5] + v73[2]) * (float)0.5);
                v77 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
                v78 = v77[2];
                v79 = (float)((float)v75 - v77[1]);
                a42 = (float)v74 - *v77;
                a43 = v79;
                a44 = (float)((float)v76 - (float)v78) + (float)24.0;
                v80 = idVec3::NormalizeFast(this: (idVec3 *)&a42);
                v81 = v51->presentable;
                decl = v54->decl;
                if ( v81 != nullptr )
                  v83 = (idPresentableVehicle *)((int (__fastcall *)(idPresentable *, double))v81->GetVehicleInterface)(
                                                  a1: v81,
                                                  a2: v80);
                else
                  v83 = nullptr;
                v84 = *v71;
                v85 = decl[1].trackedMemory;
                DriverEntity = idPresentableVehicle::GetDriverEntity(this: v83);
                (*(void (__fastcall **)(int *, idVehicle_Car *, idEntity *, int, double))(v84 + 312))(
                  a1: v71,
                  a2: v51,
                  a3: DriverEntity,
                  a4: v85,
                  a5: v58);
              }
              ++v68;
            }
          }
          idClientServerInterfaceClient::VehicleShockwaveThink(
            this: (idClientServerInterfaceClient *)HIDWORD(v46),
            item: (idVehicle_Shockwave *)v46,
            presentable: v48);
        }
      }
    }
  }
}


// ========================================================================
// ?VehicleAftershockerUse@idClientServerInterfaceServer@@UAA_NPAVidInventoryItem@@PAVidPresentable@@@Z
// EA  : 0x82EC3A58
// RVA : 0x00EC3A58
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

int __fastcall idClientServerInterfaceServer::VehicleAftershockerUse(
        idClientServerInterfaceServer *this,
        idVehicle_Aftershocker *item,
        idPresentable *presentable)
{
  idVehicleQuickItem *v6; // r27
  idVehicle_Car *v8; // r3
  idVehicle_Aftershocker *v9; // r29

  v6 = idVehicleQuickItem::CastTo(c: item);
  if ( v6 == nullptr )
    return 0;
  v8 = idVehicle_Car::CastTo(c: (idVehicle_Car *)this->entity);
  if ( v8 == nullptr )
    return 0;
  if ( idEntity::GetPhysics(this: v8) == nullptr )
    return 0;
  v9 = idVehicle_Aftershocker::CastTo(c: item);
  if ( v9 == nullptr
    || (unsigned __int8)idClientServerInterfaceClient::VehicleAftershockerUse(this, item, presentable) == 0 )
  {
    return 0;
  }
  v9->lastThinkTime = v6->activateTime;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v9->damagedEntList);
  return 1;
}


// ========================================================================
// ?VehicleTeleporterUse@idClientServerInterfaceServer@@UAA_NPAVidInventoryItem@@PAVidPresentable@@@Z
// EA  : 0x82EC3AF8
// RVA : 0x00EC3AF8
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

// attributes: thunk
int __fastcall idClientServerInterfaceServer::VehicleTeleporterUse(
        idClientServerInterfaceServer *this,
        idVehicle_Teleporter *item,
        idPresentable *presentable)
{
  return idClientServerInterfaceClient::VehicleTeleporterUse(this, item, presentable);
}


// ========================================================================
// ?VehicleTeleporterThink@idClientServerInterfaceServer@@UAAXPAVidInventoryItem@@PAVidPresentable@@@Z
// EA  : 0x82EC3B00
// RVA : 0x00EC3B00
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

// attributes: thunk
void __fastcall idClientServerInterfaceServer::VehicleTeleporterThink(
        idClientServerInterfaceServer *this,
        idVehicle_Teleporter *item,
        idPresentable *presentable)
{
  idClientServerInterfaceClient::VehicleTeleporterThink(this, item, presentable);
}


// ========================================================================
// ?VehicleJumpUse@idClientServerInterfaceServer@@UAA_NPAVidInventoryItem@@PAVidPresentable@@@Z
// EA  : 0x82EC3B08
// RVA : 0x00EC3B08
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

// attributes: thunk
int __fastcall idClientServerInterfaceServer::VehicleJumpUse(
        idClientServerInterfaceServer *this,
        idVehicleQuickItem *item,
        idPresentable *presentable)
{
  return idClientServerInterfaceClient::VehicleJumpUse(this, item, presentable);
}


// ========================================================================
// ?VehicleMegaboosterUse@idClientServerInterfaceServer@@UAA_NPAVidVehicle_Megabooster@@PAVidPresentable@@@Z
// EA  : 0x82EC3B10
// RVA : 0x00EC3B10
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

// attributes: thunk
int __fastcall idClientServerInterfaceServer::VehicleMegaboosterUse(
        idClientServerInterfaceServer *this,
        idVehicle_Megabooster *item,
        idPresentable *presentable)
{
  return idClientServerInterfaceClient::VehicleMegaboosterUse(this, item, presentable);
}


// ========================================================================
// ?VehicleMegaboosterThink@idClientServerInterfaceServer@@UAAXPAVidVehicle_Megabooster@@PAVidPresentable@@@Z
// EA  : 0x82EC3B18
// RVA : 0x00EC3B18
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

// attributes: thunk
void __fastcall idClientServerInterfaceServer::VehicleMegaboosterThink(
        idClientServerInterfaceServer *this,
        idVehicle_Megabooster *item,
        idPresentable *presentable)
{
  idClientServerInterfaceClient::VehicleMegaboosterThink(this, item, presentable);
}


// ========================================================================
// ?VehicleHealthUse@idClientServerInterfaceServer@@UAA_NPAVidInventoryItem@@PAVidPresentable@@@Z
// EA  : 0x82EC3B20
// RVA : 0x00EC3B20
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

int __fastcall idClientServerInterfaceServer::VehicleHealthUse(
        idClientServerInterfaceServer *this,
        idVehicleQuickItem *item,
        idPresentable *presentable)
{
  idVehicle_Car *v7; // r3
  idVehicle *v8; // r31
  idPresentable *v9; // r3

  if ( idVehicleQuickItem::CastTo(c: item) == nullptr )
    return 0;
  v7 = idVehicle_Car::CastTo(c: (idVehicle_Car *)this->entity);
  v8 = v7;
  if ( v7 == nullptr
    || idEntity::GetPhysics(this: v7) == nullptr
    || (unsigned __int8)idClientServerInterfaceClient::VehicleHealthUse(this, item, presentable) == 0 )
  {
    return 0;
  }
  idVehicle::GetArmoredHealth(this: v8);
  v9 = v8->presentable;
  if ( v9 != nullptr )
    v9->GetVehicleInterface(this: v9);
  common->IsMultiplayer(this: common);
  ((void (__fastcall *)(idVehicle *))v8->IncreaseHealth)(a1: v8);
  return 1;
}


// ========================================================================
// ?VehicleHealthThink@idClientServerInterfaceServer@@UAAXPAVidInventoryItem@@PAVidPresentable@@@Z
// EA  : 0x82EC3C78
// RVA : 0x00EC3C78
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

// attributes: thunk
void __fastcall idClientServerInterfaceServer::VehicleHealthThink(
        idClientServerInterfaceServer *this,
        idVehicleQuickItem *item,
        idPresentable *presentable)
{
  idClientServerInterfaceClient::VehicleInstantDamageThink(this, item, presentable);
}


// ========================================================================
// ?VehicleStompUse@idClientServerInterfaceServer@@UAA_NPAVidInventoryItem@@PAVidPresentable@@@Z
// EA  : 0x82EC3C80
// RVA : 0x00EC3C80
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

// attributes: thunk
int __fastcall idClientServerInterfaceServer::VehicleStompUse(
        idClientServerInterfaceServer *this,
        idVehicleQuickItem *item,
        idPresentable *presentable)
{
  return idClientServerInterfaceClient::VehicleStompUse(this, item, presentable);
}


// ========================================================================
// ?VehicleInstantDamageUse@idClientServerInterfaceServer@@UAA_NPAVidInventoryItem@@PAVidPresentable@@@Z
// EA  : 0x82EC3C88
// RVA : 0x00EC3C88
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

int __fastcall idClientServerInterfaceServer::VehicleInstantDamageUse(
        idClientServerInterfaceServer *this,
        idVehicle_InstantDamage *item,
        idPresentable *presentable)
{
  idVehicleQuickItem *v6; // r3
  idVehicle_Car *v7; // r3
  idEntity *v8; // r30
  idPhysics *Physics; // r26
  idVehicle_InstantDamage *v10; // r27
  idPresentable *v11; // r3
  int v12; // r3
  double v13; // fp31
  idPresentable *v14; // r3
  const idDeclInventory *decl; // r31
  idPresentableVehicle *v16; // r3
  const idDeclDamage *trackedMemory; // r31
  idPlayer *DriverEntity; // r29
  const idVec3 *v19; // r3
  __int64 v20; // r10
  int v21; // r8

  v6 = idVehicleQuickItem::CastTo(c: item);
  if ( v6 == nullptr )
    return 0;
  if ( !v6->active )
    return 0;
  v7 = idVehicle_Car::CastTo(c: (idVehicle_Car *)this->entity);
  v8 = v7;
  if ( v7 == nullptr )
    return 0;
  Physics = idEntity::GetPhysics(this: v7);
  if ( Physics == nullptr )
    return 0;
  v10 = idVehicle_InstantDamage::CastTo(c: item);
  if ( v10 == nullptr
    || (unsigned __int8)idClientServerInterfaceClient::VehicleInstantDamageUse(this, item, presentable) == 0 )
  {
    return 0;
  }
  v11 = v8->presentable;
  if ( v11 != nullptr )
    v12 = (int)v11->GetVehicleInterface(this: v11);
  else
    v12 = 0;
  if ( *(_BYTE *)(v12 + 17860) != 0 )
    v13 = 4.0;
  else
    v13 = 1.0;
  v14 = v8->presentable;
  decl = v10->decl;
  if ( v14 != nullptr )
    v16 = v14->GetVehicleInterface(this: v14);
  else
    v16 = nullptr;
  trackedMemory = (const idDeclDamage *)decl[1].trackedMemory;
  DriverEntity = (idPlayer *)idPresentableVehicle::GetDriverEntity(this: v16);
  v19 = Physics->GetOrigin(this: Physics, a2: 0);
  HIDWORD(v20) = &idEventDef::eventDefList[3154];
  idGameLocal::RadiusDamage(
    this: gameLocal,
    origin: v19,
    inflictor: v8,
    attacker: DriverEntity,
    damageDef: trackedMemory,
    dmgPower: v13,
    a7: v21,
    a8: v20);
  return 1;
}


// ========================================================================
// ?VehicleQuickUseWeaponThink@idClientServerInterfaceServer@@UAAXPAVidInventoryItem@@PAVidPresentable@@@Z
// EA  : 0x82EC3DE8
// RVA : 0x00EC3DE8
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

// attributes: thunk
void __fastcall idClientServerInterfaceServer::VehicleQuickUseWeaponThink(
        idClientServerInterfaceServer *this,
        idVehicleQuickItem *item,
        idPresentable *presentable)
{
  idClientServerInterfaceClient::VehicleQuickUseWeaponThink(this, item, presentable);
}


// ========================================================================
// ?VehicleQuickUseWeaponUse@idClientServerInterfaceClient@@UAA_NPAVidInventoryItem@@PAVidPresentable@@@Z
// EA  : 0x82EC3DF0
// RVA : 0x00EC3DF0
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

int __fastcall idClientServerInterfaceClient::VehicleQuickUseWeaponUse(
        idClientServerInterfaceClient *this,
        idVehicle_QuickUseWeapon *item,
        idPresentable *presentable)
{
  idPresentableVehicle *v4; // r31
  idVehicle_QuickUseWeapon *v5; // r3
  int num; // r5
  int v7; // r6
  int i; // r11
  idVehicleWeapon *v9; // r7
  int v11; // r8
  idVehicleWeapon *v12; // r7
  const idDeclInventory *decl; // r11
  const idSoundShader *useSound; // r5
  int v15; // [sp+8h] [-78h]
  int v16; // [sp+Ch] [-74h]
  int v17; // [sp+10h] [-70h]
  int v18; // [sp+14h] [-6Ch]
  int v19; // [sp+18h] [-68h]
  int v20; // [sp+1Ch] [-64h]
  int v21; // [sp+20h] [-60h]
  int v22; // [sp+24h] [-5Ch]
  int v23; // [sp+28h] [-58h]
  int v24; // [sp+2Ch] [-54h]
  int v25; // [sp+30h] [-50h]
  int v26; // [sp+34h] [-4Ch]
  int v27; // [sp+38h] [-48h]
  int v28; // [sp+3Ch] [-44h]
  int v29; // [sp+40h] [-40h]
  int v30; // [sp+44h] [-3Ch]
  int v31; // [sp+48h] [-38h]
  int v32; // [sp+4Ch] [-34h]
  int v33; // [sp+50h] [-30h]

  v4 = presentable->GetVehicleInterface(this: presentable);
  if ( v4 == nullptr )
    return 0;
  v5 = idVehicle_QuickUseWeapon::CastTo(c: item);
  if ( v5 == nullptr )
    return 0;
  num = v4->weapons.num;
  v7 = 0;
  if ( num <= 0 )
    return 0;
  for ( i = 0; ; ++i )
  {
    v9 = v4->weapons.list[i];
    if ( v9->weapon->decl == (const idDeclInventory *)v5->decl[1].__vftable )
      break;
    if ( ++v7 >= num )
      return 0;
  }
  *(_DWORD *)(v11 + 72) = (unsigned __int8)idWeapon::IsMelee(this: v9->weapon) == 0;
  v12->weapon->attackType = ATTACK_LEFT;
  idVehicleWeapon::Fire(
    this: v12,
    attacker: &v4->idPresentableAnimatedEntity,
    lockedOn: false,
    target: nullptr,
    damageScale: 1.0,
    addSpread: 0.0,
    infiniteAmmo: (bool)v12,
    beingRemoteFired: 0x82000000,
    skipClientFireRecord: true,
    a10: 0,
    a11: v15,
    a12: v16,
    a13: v17,
    a14: v18,
    a15: v19,
    a16: v20,
    a17: v21,
    a18: v22,
    a19: v23,
    a20: v24,
    a21: v25,
    a22: v26,
    a23: v27,
    a24: v28,
    a25: v29,
    a26: v30,
    a27: v31,
    a28: v32,
    a29: v33,
    a30: 1);
  decl = item->decl;
  if ( decl != nullptr )
  {
    useSound = decl->useSound;
    if ( useSound != nullptr )
      v4->StartSoundShader_Predicted(this: v4, a2: SND_CHANNEL_ITEM, a3: useSound, a4: 0);
  }
  return 1;
}


// ========================================================================
// ?Serialize@idInventoryItem@@UAAXAAVidSerializer@@PAVidInventoryCollection@@@Z
// EA  : 0x82EC3FA0
// RVA : 0x00EC3FA0
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __fastcall idInventoryItem::Serialize(idInventoryItem *this, idSerializer *ser, idInventoryCollection *inventory)
{
  idBitMsg *msg; // r3
  idBitMsg *v6; // r3

  idSerializer::Serialize<idDeclInventory>(this: ser, decl: &this->decl);
  msg = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: msg, value: this->count, numBits: 32);
  else
    this->count = idBitMsg::ReadBits(this: msg, numBits: 32);
  v6 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v6, value: this->quickSlot, numBits: 32);
  else
    this->quickSlot = idBitMsg::ReadBits(this: v6, numBits: 32);
}


// ========================================================================
// ?Serialize@idVehicleKey@@UAAXAAVidSerializer@@PAVidInventoryCollection@@@Z
// EA  : 0x82EC4038
// RVA : 0x00EC4038
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

// attributes: thunk
void __fastcall idVehicleKey::Serialize(idVehicleKey *this, idSerializer *ser, idInventoryCollection *inventory)
{
  idInventoryItem::Serialize(this, ser, inventory);
}


// ========================================================================
// ?Serialize@idWeapon@@UAAXAAVidSerializer@@PAVidInventoryCollection@@@Z
// EA  : 0x82EC4040
// RVA : 0x00EC4040
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __fastcall idWeapon::Serialize(idWeapon *this, idSerializer *ser, idInventoryCollection *inventory)
{
  BOOL writing; // r11
  idAmmoItem *ammoClip; // r11
  const idDecl *decl; // r11
  const idDeclInventory *v9; // r29
  idAmmoItem *v10; // r3
  idAmmoItem *v11; // r3
  idAmmoItem *ammoClipSecondary; // r11
  const idDecl *v13; // r11
  const idDeclInventory *v14; // r29
  idAmmoItem *v15; // r3
  idAmmoItem *v16; // r3
  char v17; // r7
  char v18; // r11
  char v19; // r7
  char v20; // r11
  char v21; // r7
  bool v22; // r3
  int v23; // r4
  char v24; // r8
  const idDecl *v25[16]; // [sp+50h] [-40h] BYREF

  if ( inventory != nullptr )
  {
    idInventoryItem::Serialize(this, ser, inventory);
    writing = ser->writing;
    v25[0] = nullptr;
    if ( writing )
    {
      ammoClip = this->ammoClip;
      if ( ammoClip != nullptr )
        decl = ammoClip->decl;
      else
        decl = nullptr;
      v25[0] = decl;
    }
    idSerializer::Serialize<idDeclInventory>(this: ser, decl: v25);
    v9 = (const idDeclInventory *)v25[0];
    if ( v25[0] == nullptr )
    {
      this->ammoClip = nullptr;
LABEL_14:
      if ( ser->writing )
      {
        ammoClipSecondary = this->ammoClipSecondary;
        if ( ammoClipSecondary != nullptr )
          v13 = ammoClipSecondary->decl;
        else
          v13 = nullptr;
        v25[0] = v13;
      }
      idSerializer::Serialize<idDeclInventory>(this: ser, decl: v25);
      v14 = (const idDeclInventory *)v25[0];
      if ( v25[0] == nullptr )
      {
        this->ammoClipSecondary = nullptr;
        goto LABEL_26;
      }
      v15 = this->ammoClipSecondary;
      if ( v15 != nullptr )
      {
        if ( v15->decl == v25[0] )
        {
LABEL_24:
          this->ammoClipSecondary->Serialize(this: this->ammoClipSecondary, a2: ser, a3: inventory);
LABEL_26:
          v17 = (32 * idSerializer::SerializeBoolNonRef(this: ser, value: (*((_BYTE *)this + 452) & 0x20) != 0)) & 0x20
              | *((_BYTE *)this + 452) & 0xDF;
          *((_BYTE *)this + 452) = v17;
          v18 = (16 * idSerializer::SerializeBoolNonRef(this: ser, value: (v17 & 0x10) != 0)) & 0x10
              | *((_BYTE *)this + 452) & 0xEF;
          *((_BYTE *)this + 452) = v18;
          v19 = (8 * idSerializer::SerializeBoolNonRef(this: ser, value: (v18 & 8) != 0)) & 8
              | *((_BYTE *)this + 452) & 0xF7;
          *((_BYTE *)this + 452) = v19;
          v20 = (4 * idSerializer::SerializeBoolNonRef(this: ser, value: (v19 & 4) != 0)) & 4
              | *((_BYTE *)this + 452) & 0xFB;
          *((_BYTE *)this + 452) = v20;
          v21 = (2 * idSerializer::SerializeBoolNonRef(this: ser, value: (v20 & 2) != 0)) & 2
              | *((_BYTE *)this + 452) & 0xFD;
          *((_BYTE *)this + 452) = v21;
          v22 = idSerializer::SerializeBoolNonRef(this: ser, value: v21 & 1);
          v23 = *((unsigned __int8 *)this + 453) >> 7;
          *((_BYTE *)this + 452) = *((_BYTE *)this + 452) & 0xFE | v22;
          v24 = (idSerializer::SerializeBoolNonRef(this: ser, value: v23) << 7) | *((_BYTE *)this + 453) & 0x7F;
          *((_BYTE *)this + 453) = v24;
          *((_BYTE *)this + 453) = (idSerializer::SerializeBoolNonRef(this: ser, value: (v24 & 0x40) != 0) << 6) & 0x40
                                 | *((_BYTE *)this + 453) & 0xBF;
          return;
        }
        ((void (__fastcall *)(idAmmoItem *, int))v15->dtr_idClass)(a1: v15, a2: 1);
      }
      v16 = (idAmmoItem *)idInventoryItem::Create(decl: v14);
      this->ammoClipSecondary = idAmmoItem::CastTo(c: v16);
      goto LABEL_24;
    }
    v10 = this->ammoClip;
    if ( v10 != nullptr )
    {
      if ( v10->decl == v25[0] )
      {
LABEL_12:
        this->ammoClip->Serialize(this: this->ammoClip, a2: ser, a3: inventory);
        goto LABEL_14;
      }
      ((void (__fastcall *)(idAmmoItem *, int))v10->dtr_idClass)(a1: v10, a2: 1);
    }
    v11 = (idAmmoItem *)idInventoryItem::Create(decl: v9);
    this->ammoClip = idAmmoItem::CastTo(c: v11);
    goto LABEL_12;
  }
}


// ========================================================================
// ??1idWeapon@@UAA@XZ
// EA  : 0x82EC42E0
// RVA : 0x00EC42E0
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __fastcall idWeapon::~idWeapon(idWeapon *this)
{
  idAmmoItem *ammoClip; // r3
  idAmmoItem *ammoClipSecondary; // r3
  unsigned int spawnId; // r11
  int v5; // r29
  idPresentableWeapon *v6; // r3

  this->__vftable = (idWeapon_vtbl *)&idWeapon::`vftable';
  ammoClip = this->ammoClip;
  if ( ammoClip != nullptr )
  {
    ((void (__fastcall *)(idAmmoItem *, int))ammoClip->dtr_idClass)(a1: ammoClip, a2: 1);
    this->ammoClip = nullptr;
  }
  ammoClipSecondary = this->ammoClipSecondary;
  if ( ammoClipSecondary != nullptr )
  {
    ((void (__fastcall *)(idAmmoItem *, int))ammoClipSecondary->dtr_idClass)(a1: ammoClipSecondary, a2: 1);
    this->ammoClipSecondary = nullptr;
  }
  spawnId = this->presentableWeapon.spawnId;
  v5 = spawnId & 0x3FFF;
  if ( spawnId != 0
    && idClientGame::IsPresentableIndexValid(this: clientGame, index: spawnId & 0x3FFF)
    && idClientGame::GetPresentableByIndex(this: clientGame, index: v5)->spawnId == this->presentableWeapon.spawnId )
  {
    v6 = (idPresentableWeapon *)idPresentablePtr<idPresentableProjectile>::operator->(this: (idPresentablePtr<idPresentable> *)&this->presentableWeapon);
    idPresentableWeapon::WeaponDeleted(this: v6);
  }
  idMD6PhaseTrack::idMD6PhaseTrack(this: (idStreamFileLog *)&this->tracerManager);
  idMD6PhaseTrack::idMD6PhaseTrack(this: (idStreamFileLog *)&this->tracerManager);
  this->__vftable = (idWeapon_vtbl *)&idInventoryItem::`vftable';
  idEventReceiver::~idEventReceiver(this);
}


// ========================================================================
// __unwind$508182
// EA  : 0x82EC43E0
// RVA : 0x00EC43E0
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void _unwind_508182()
{
  int v0; // r12

  idInventoryItem::~idInventoryItem(this: *(idInventoryItem **)(v0 - 144 + 164));
}


// ========================================================================
// __unwind$508183
// EA  : 0x82EC4408
// RVA : 0x00EC4408
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void _unwind_508183()
{
  int v0; // r12

  idMD6PhaseTrack::idMD6PhaseTrack(this: (idStreamFileLog *)(*(_DWORD *)(v0 - 144 + 164) + 144));
}


// ========================================================================
// ?OnChamberAmmo@idWeapon@@QAAXPAVidFXManager@@@Z
// EA  : 0x82EC4438
// RVA : 0x00EC4438
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __fastcall idWeapon::OnChamberAmmo(idWeapon *this, idFXManager *fxMgr)
{
  idAmmoItem *ammoClip; // r3
  __int32 FXExtraCondition; // r3
  unsigned int v6; // r6
  unsigned int GameMs; // r26
  idPresentable *v8; // r31
  __int32 v9; // r3

  if ( fxMgr != nullptr )
  {
    ammoClip = this->ammoClip;
    if ( ammoClip != nullptr && ammoClip->GetCount(this: ammoClip) > 0 )
    {
      idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      FXExtraCondition = idWeapon::GetFXExtraCondition(this, secondary: false);
      idFXManager::StartFX(
        this: fxMgr,
        org: &vec3_origin,
        axis: &mat3_identity,
        time: v6,
        startCondition: 68,
        extraCond: FXExtraCondition);
      if ( idPresentablePtr<idPresentableProjectile>::operator->(this: (idPresentablePtr<idPresentable> *)&this->presentableWeapon) != nullptr
        && fxMgr != &idPresentablePtr<idPresentableProjectile>::operator->(this: (idPresentablePtr<idPresentable> *)&this->presentableWeapon)->fxManager )
      {
        GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        v8 = idPresentablePtr<idPresentableProjectile>::operator->(this: (idPresentablePtr<idPresentable> *)&this->presentableWeapon);
        v9 = idWeapon::GetFXExtraCondition(this, secondary: false);
        idFXManager::StartFX(
          this: &v8->fxManager,
          org: &vec3_origin,
          axis: &mat3_identity,
          time: GameMs,
          startCondition: 68,
          extraCond: v9);
      }
    }
  }
}


// ========================================================================
// ?UnloadAmmo@idWeapon@@UAAXPAVidInventoryCollection@@PAVidFXManager@@_N@Z
// EA  : 0x82EC4548
// RVA : 0x00EC4548
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __fastcall idWeapon::UnloadAmmo(idWeapon *this, idJobManager *inventory, idFXManager *fxMgr, bool secondaryAmmo)
{
  idAmmoItem **p_ammoClipSecondary; // r25
  int GameMs; // r29
  fxExtraCondition_t FXExtraCondition; // r3
  int v11; // r28
  idPresentable *v12; // r31
  fxExtraCondition_t v13; // r3
  idInventoryItem *JobByDecl; // r31
  int v15; // r3
  idAmmoItem *v16; // r3
  idAmmoItem *v17; // r3

  p_ammoClipSecondary = &this->ammoClipSecondary;
  if ( !secondaryAmmo )
    p_ammoClipSecondary = &this->ammoClip;
  if ( *p_ammoClipSecondary != nullptr )
  {
    if ( fxMgr != nullptr )
    {
      GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      FXExtraCondition = idWeapon::GetFXExtraCondition(this, secondary: secondaryAmmo);
      idFXManager::StopFX(
        this: fxMgr,
        time: GameMs,
        stopCondition: 67,
        extraCondition: FXExtraCondition,
        immediateStop: false);
      if ( idPresentablePtr<idPresentableProjectile>::operator->(this: (idPresentablePtr<idPresentable> *)&this->presentableWeapon) != nullptr
        && fxMgr != &idPresentablePtr<idPresentableProjectile>::operator->(this: (idPresentablePtr<idPresentable> *)&this->presentableWeapon)->fxManager )
      {
        v11 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        v12 = idPresentablePtr<idPresentableProjectile>::operator->(this: (idPresentablePtr<idPresentable> *)&this->presentableWeapon);
        v13 = idWeapon::GetFXExtraCondition(this, secondary: secondaryAmmo);
        idFXManager::StopFX(
          this: &v12->fxManager,
          time: v11,
          stopCondition: 67,
          extraCondition: v13,
          immediateStop: false);
      }
    }
    if ( inventory != nullptr && (*p_ammoClipSecondary)->GetCount(this: *p_ammoClipSecondary) > 0 )
    {
      JobByDecl = (idInventoryItem *)idJobManager::FindJobByDecl(
                                       this: inventory,
                                       jobDecl: (const idDeclJob *)(*p_ammoClipSecondary)->decl);
      if ( JobByDecl != nullptr )
      {
        v15 = (*p_ammoClipSecondary)->GetCount(this: *p_ammoClipSecondary);
        idInventoryItem::ModifyCount(this: JobByDecl, amount: v15);
      }
      else
      {
        v16 = (idAmmoItem *)idInventoryCollection::CloneItem(
                              this: (idInventoryCollection *)inventory,
                              ownerEnt: nullptr,
                              item: *p_ammoClipSecondary,
                              canIntro: false);
        v17 = idAmmoItem::CastTo(c: v16);
        if ( v17 != nullptr )
          v17->burstMode = (*p_ammoClipSecondary)->burstMode;
      }
    }
    if ( *p_ammoClipSecondary != nullptr )
      ((void (__fastcall *)(idAmmoItem *, int))(*p_ammoClipSecondary)->dtr_idClass)(a1: *p_ammoClipSecondary, a2: 1);
    *p_ammoClipSecondary = nullptr;
  }
}


// ========================================================================
// ?BeginFiring@idWeapon@@QAAXXZ
// EA  : 0x82EC4700
// RVA : 0x00EC4700
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __fastcall idWeapon::BeginFiring(idWeapon *this)
{
  char IsMelee; // r3
  int v2; // r8

  IsMelee = idWeapon::IsMelee(this);
  *(_DWORD *)(v2 + 72) = IsMelee == 0;
  idWeapon::UpdateAttackType(this: (idWeapon *)v2);
}


// ========================================================================
// ?GetLaserSightWorldTransform@idWeapon@@QBA_NPBVidTreeAnimator@@AAVidVec3@@AAVidMat3@@@Z
// EA  : 0x82EC4748
// RVA : 0x00EC4748
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

int __fastcall idWeapon::GetLaserSightWorldTransform(idWeapon *this, idTreeAnimator *ta, idVec3 *origin, idMat3 *axis)
{
  unsigned int spawnId; // r11
  int v9; // r31
  idPresentableWeapon *PresentableByIndex; // r3

  spawnId = this->presentableWeapon.spawnId;
  v9 = spawnId & 0x3FFF;
  if ( spawnId == 0
    || !idClientGame::IsPresentableIndexValid(this: clientGame, index: spawnId & 0x3FFF)
    || (PresentableByIndex = (idPresentableWeapon *)idClientGame::GetPresentableByIndex(this: clientGame, index: v9))->spawnId != this->presentableWeapon.spawnId )
  {
    PresentableByIndex = nullptr;
  }
  return idPresentableWeapon::GetLaserSightWorldTransform(this: PresentableByIndex, parentModel: ta, origin, axis);
}


// ========================================================================
// ?DeferredFire@idWeapon@@QAAXPAVidPresentable@@PBV2@ABVidVec3@@ABVidMat3@@AAVidFireParms@@_N@Z
// EA  : 0x82EC47C8
// RVA : 0x00EC47C8
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __fastcall idWeapon::DeferredFire(
        idWeapon *this,
        idPresentable *attacker,
        const idPresentable *target,
        const idVec3 *start,
        const idMat3 *fireAxis,
        idFireParms *fp,
        bool secondaryAmmo)
{
  idAmmoItem *ammoClipSecondary; // r11
  const idDeclInventory *decl; // r11
  const idDeclProjectile *v16; // r11
  char v17; // r9

  if ( (unsigned __int8)idDeferredFireManager::IsHandleFinished(
                          this: &clientGame->deferredFireManager,
                          handle: this->fireHandle) != 0 )
    idLib::Warning(fmt: "WE ARE TRYING TO SUBMIT A NEW DEFERRED FIRE QUERY WITH A FINISHED ON STILL IN THE QUEUE");
  if ( (unsigned __int8)idDeferredFireManager::IsHandleSubmitted(
                          this: &clientGame->deferredFireManager,
                          handle: this->fireHandle) != 0 )
    idLib::Warning(fmt: "WE HAVE SUBMITTED 2 DEFERRED FIRE QUERIES IN A FRAME");
  if ( attacker != nullptr )
    fp->attacker.spawnId = attacker->spawnId;
  else
    fp->attacker.spawnId = 0;
  if ( target != nullptr )
    fp->target.spawnId = target->spawnId;
  fp->wepDef = (const idDeclWeapon *)this->decl;
  fp->start.x = start->x;
  fp->start.y = start->y;
  fp->start.z = start->z;
  fp->fireAxis.mat[0].x = fireAxis->mat[0].x;
  fp->fireAxis.mat[0].y = fireAxis->mat[0].y;
  fp->fireAxis.mat[0].z = fireAxis->mat[0].z;
  fp->fireAxis.mat[1].x = fireAxis->mat[1].x;
  fp->fireAxis.mat[1].y = fireAxis->mat[1].y;
  fp->fireAxis.mat[1].z = fireAxis->mat[1].z;
  fp->fireAxis.mat[2].x = fireAxis->mat[2].x;
  fp->fireAxis.mat[2].y = fireAxis->mat[2].y;
  fp->fireAxis.mat[2].z = fireAxis->mat[2].z;
  if ( secondaryAmmo )
    ammoClipSecondary = this->ammoClipSecondary;
  else
    ammoClipSecondary = this->ammoClip;
  if ( ammoClipSecondary != nullptr && (decl = ammoClipSecondary->decl) != nullptr )
    v16 = (const idDeclProjectile *)decl[1].__vftable;
  else
    v16 = nullptr;
  v17 = *((_BYTE *)fp + 129);
  fp->projDef = v16;
  *((_BYTE *)fp + 129) = (32 * secondaryAmmo) & 0x20 | v17 & 0xDF;
  this->fireHandle = idDeferredFireManager::SubmitFireQuery(this: &clientGame->deferredFireManager, fp);
  this->fireState = (unsigned __int8)idWeapon::IsMelee(this) == 0;
  idWeapon::UpdateAttackType(this);
}


// ========================================================================
// ?ResolveFire@idWeapon@@QAAXAAVidFireParms@@AAVidTestFireResults@@AAVidFinishFireResults@@PAVidFXManager@@@Z
// EA  : 0x82EC4980
// RVA : 0x00EC4980
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __fastcall idWeapon::ResolveFire(
        idWeapon *this,
        idFireParms *fp,
        idTestFireResults *tfr,
        idFinishFireResults *ffr,
        idFXManager *fxMgr)
{
  const idDeclInventory *decl; // r11
  const idDeclInventory *v11; // r30
  idAmmoItem *ammoClipSecondary; // r3

  if ( (unsigned __int8)idDeferredFireManager::GetFireQuery(
                          this: &clientGame->deferredFireManager,
                          handle: this->fireHandle,
                          fp,
                          tfr) != 0 )
  {
    this->FinishFire(this, a2: fp, a3: tfr, a4: ffr, a5: fxMgr, a6: (*((_BYTE *)fp + 129) & 0x20) != 0);
    decl = this->decl;
    if ( decl != nullptr && (int)decl[3].raceRewardImage > 0 )
    {
      if ( gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) >= this->lastDecalTime )
      {
        v11 = this->decl;
        this->lastDecalTime = (int)v11[3].raceRewardImage + gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
      }
      else
      {
        *((_BYTE *)fp + 128) |= 1u;
      }
    }
    if ( (*((_BYTE *)fp + 129) & 0x20) != 0 )
      ammoClipSecondary = this->ammoClipSecondary;
    else
      ammoClipSecondary = this->ammoClip;
    if ( ammoClipSecondary != nullptr )
      ammoClipSecondary->GetCount(this: ammoClipSecondary);
    idPresentablePtr<idPresentableProjectile>::operator->(this: &fp->attacker);
  }
}


// ========================================================================
// ?Fire@idWeapon@@QAA_NPAVidPresentable@@PBV2@ABVidVec3@@ABVidMat3@@AAVidFireParms@@AAVidTestFireResults@@AAVidFinishFireResults@@PAVidFXManager@@_N@Z
// EA  : 0x82EC4AB8
// RVA : 0x00EC4AB8
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

int __fastcall idWeapon::Fire(
        idWeapon *this,
        idPresentable *attacker,
        const idPresentable *target,
        const idVec3 *start,
        const idMat3 *fireAxis,
        idFireParms *fp,
        idTestFireResults *tfr,
        idFinishFireResults *ffr,
        idFXManager *fxMgr,
        bool secondaryAmmo,
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
        bool a30)
{
  idAmmoItem *ammoClipSecondary; // r21
  const idDeclInventory *decl; // r11
  idAmmoItem *ammoClip; // r3
  int v39; // r29
  int v40; // r30
  idAmmoItem *v41; // r3
  int v42; // r3
  int v43; // r11
  soundShaderParms_t v44; // [sp+50h] [-100h] BYREF

  if ( a30 )
    ammoClipSecondary = this->ammoClipSecondary;
  else
    ammoClipSecondary = this->ammoClip;
  if ( (unsigned __int8)idWeapon::TestFire(this, attacker, target, start, fireAxis, fp, tfr, secondaryAmmo: a30) == 0 )
    return 0;
  decl = this->decl;
  if ( decl != nullptr && (int)decl[3].raceRewardImage > 0 )
  {
    if ( idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) >= this->lastDecalTime )
      this->lastDecalTime = (int)this->decl[3].raceRewardImage
                          + idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    else
      *((_BYTE *)fp + 128) |= 1u;
  }
  this->fireState = (unsigned __int8)idWeapon::IsMelee(this) == 0;
  idWeapon::UpdateAttackType(this);
  if ( a30 )
    ammoClip = this->ammoClipSecondary;
  else
    ammoClip = this->ammoClip;
  if ( ammoClip != nullptr )
    v39 = ammoClip->GetCount(this: ammoClip);
  else
    v39 = 0;
  v40 = ((int (__fastcall *)(idWeapon *, idFireParms *, idTestFireResults *, idFinishFireResults *, int, bool))this->FinishFire)(
          a1: this,
          a2: fp,
          a3: tfr,
          a4: ffr,
          a5: a28,
          a6: a30);
  if ( attacker != nullptr && *(_DWORD *)&ammoClipSecondary->decl[1].removeOnUse != 0 )
  {
    if ( a30 )
      v41 = this->ammoClipSecondary;
    else
      v41 = this->ammoClip;
    if ( v41 != nullptr )
      v42 = v41->GetCount(this: v41);
    else
      v42 = 0;
    v43 = *(_DWORD *)&ammoClipSecondary->decl[1].isWeapon;
    if ( v42 <= v43 && v39 > v43 )
    {
      soundShaderParms_t::Clear(this: &v44);
      v44.soundShaderFlags = 0;
      idPresentable::StartSoundShader(
        this: attacker,
        channel: SND_CHANNEL_WEAPON_AMBIENT,
        shader: *(const idSoundShader **)&ammoClipSecondary->decl[1].removeOnUse,
        parms: &v44,
        peerMask: 0);
    }
  }
  return v40;
}


// ========================================================================
// ?StopLoopingFireSound@idWeapon@@QAAXXZ
// EA  : 0x82EC4CC0
// RVA : 0x00EC4CC0
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idWeapon::StopLoopingFireSound(idWeapon *this)
{
  idPresentablePtr<idPresentable> *p_loopingFireSoundEntity; // r29
  signed int v3; // r16
  idSoundWorld *v4; // r3
  int v5; // r3
  idGameLocal *v6; // r11
  int loopStartSoundTime; // r7
  signed int v8; // r15
  __int64 v9; // r7
  int v10; // r5
  unsigned int v11; // r8
  double (__fastcall *v12)(idGameLocal *, int); // ctr
  int v13; // r31
  double v14; // fp1
  __int128 v15; // r8
  int v16; // r24
  int GameMs; // r3
  const idDeclInventory *decl; // r9
  int v19; // r31
  idPresentable *v20; // r14
  idEntity *entity; // r19
  int v22; // r3
  unsigned int v23; // r5
  int v24; // r24
  int v25; // r3
  int v26; // r7
  int v27; // r11
  int v28; // r26
  __int64 v29; // r11
  int i; // r29
  __int64 v31; // r8
  int v32; // r8 OVERLAPPED
  __int128 v33; // r7 OVERLAPPED
  __int128 v34; // r7 OVERLAPPED
  int v35; // r8
  int j; // r29
  char v37; // r11
  __int128 v38; // r9
  int fireChannel; // r9
  int v40; // r11
  __int64 v41; // [sp+8h] [-1B8h]
  __int64 v42; // [sp+10h] [-1B0h]
  __int64 v43; // [sp+18h] [-1A8h]
  __int64 v44; // [sp+20h] [-1A0h]
  __int64 v45; // [sp+28h] [-198h]
  __int64 v46; // [sp+30h] [-190h]
  __int64 v47; // [sp+38h] [-188h]
  __int64 v48; // [sp+40h] [-180h]
  __int64 v49; // [sp+48h] [-178h]
  __int64 v50; // [sp+50h] [-170h]
  __int64 v51; // [sp+58h] [-168h]
  int v52; // [sp+64h] [-15Ch]
  int v53; // [sp+68h] [-158h]
  int v54; // [sp+6Ch] [-154h]
  int v55[8]; // [sp+70h] [-150h] BYREF
  int v56; // [sp+90h] [-130h]
  signed int v57; // [sp+94h] [-12Ch]
  signed int loopingFireSoundInterval; // [sp+98h] [-128h]
  __int64 v59; // [sp+A0h] [-120h]
  __int64 v60; // [sp+A8h] [-118h]
  __int64 v61; // [sp+B0h] [-110h]
  char v62; // [sp+C0h] [-100h]
  float v63; // [sp+C4h] [-FCh]
  __int64 v64; // [sp+C8h] [-F8h]
  int v65; // [sp+D0h] [-F0h]
  int v66; // [sp+E0h] [-E0h]
  int v67; // [sp+E4h] [-DCh]
  __int64 v68; // [sp+E8h] [-D8h]
  int v69; // [sp+F0h] [-D0h]
  _QWORD v70[4]; // [sp+100h] [-C0h] BYREF

  if ( this->loopingFireSoundList != nullptr )
  {
    p_loopingFireSoundEntity = &this->loopingFireSoundEntity;
    if ( idPresentablePtr<idPresentableProjectile>::operator->(this: &this->loopingFireSoundEntity) != nullptr )
    {
      loopingFireSoundInterval = this->loopingFireSoundInterval;
      v3 = loopingFireSoundInterval;
      v4 = gameLocal->GetSoundWorld(this: gameLocal);
      v5 = v4->GetSoundTime(this: v4);
      v6 = gameLocal;
      loopStartSoundTime = this->loopStartSoundTime;
      __twllei(loopingFireSoundInterval, 0);
      v8 = v5 - loopStartSoundTime;
      HIDWORD(v9) = v6->__vftable;
      v57 = v8;
      v10 = (v5 - loopStartSoundTime) / v3 + 1;
      v11 = v3 & ~(__ROL4__(v5 - loopStartSoundTime, 1) - 1);
      v12 = *(double (__fastcall **)(idGameLocal *, int))(HIDWORD(v9) + 172);
      LODWORD(v9) = v5 - loopStartSoundTime;
      __twlgei(v11, 0xFFFFFFFF);
      v59 = v9;
      v13 = v10 * v3 - v8;
      if ( (float)v9 <= v12(a1: v6, a2: 1) )
      {
        v14 = ((double (__fastcall *)(idGameLocal *, int))gameLocal->GetRealMsPerFrame)(a1: gameLocal, a2: 1);
        __twllei(v3, 0);
        LODWORD(v59) = (int)(float)((float)v14 + (float)1.0);
        v13 += ((int)v59 - v8) / loopingFireSoundInterval * loopingFireSoundInterval;
        __twlgei(loopingFireSoundInterval & ~(__ROL4__(v59 - v8, 1) - 1), 0xFFFFFFFF);
      }
      LODWORD(v15) = gameLocal->GetGameMsPerRealSec(this: gameLocal);
      *(_QWORD *)((char *)&v15 + 4) = (unsigned int)v13 | 0x3E800000000LL;
      HIDWORD(v15) = v15 * v13;
      v16 = (_QWORD)v15 * *(_QWORD *)((char *)&v15 + 4) / *(__int64 *)&v15;
      GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      decl = this->decl;
      v19 = 20;
      this->loopStopedGameTime = GameMs + v16;
      if ( decl->equipSlot != EQUIP_LEFT_HAND )
        v19 = 17;
      v20 = idPresentablePtr<idPresentableProjectile>::operator->(this: p_loopingFireSoundEntity);
      HIDWORD(v59) = v20;
      entity = idPresentablePtr<idPresentableProjectile>::operator->(this: p_loopingFireSoundEntity)->entity;
      if ( entity != nullptr )
      {
        v22 = gameLocal->GetGameMsPerFrame(this: gameLocal, a2: GAMETIME_SCALED);
        v23 = v16 - v22 + 0x80000000;
        v24 = __CFADD__(v16 - v22, 0x80000000) ? 0 : v16 - v22;
        v25 = ((int (__fastcall *)(idGameLocal *, int, unsigned int))gameLocal->GetGameMsPerFrame)(
                a1: gameLocal,
                a2: 1,
                a3: v23);
        v26 = this->loopingFireSoundInterval;
        v27 = 2 * v25;
        if ( v26 / 4 > 2 * v25 )
          v27 = v26 / 4;
        v28 = v24;
        if ( v24 >= v27 )
          v28 = v27;
        if ( v28 < v24 - 2 * gameLocal->GetGameMsPerFrame(this: gameLocal, a2: GAMETIME_SCALED) )
          v28 -= gameLocal->GetGameMsPerFrame(this: gameLocal, a2: GAMETIME_SCALED);
        v56 = gameLocal->GetGameMsPerFrame(this: gameLocal, a2: GAMETIME_SCALED);
        HIDWORD(v29) = &s_memTag[218];
        for ( i = 3; i != 0; --i )
        {
          if ( v28 > v56 )
          {
            LODWORD(v29) = v28;
            HIBYTE(v70[0]) = 102;
            v60 = v29;
            LODWORD(v31) = gameLocal->GetGameMsPerRealSec(this: gameLocal);
            v61 = v31;
            v63 = -60.0;
            v62 = 102;
            HIBYTE(v66) = 105;
            v67 = v19;
            *((float *)v70 + 1) = (float)v60 / (float)v31;
            memcpy(Dst: v55, Src: v70, Size: 0x14u);
            v32 = __ROL4__(v69, 32);
            DWORD1(v33) = v66;
            *((_QWORD *)&v33 + 1) = v68;
            idEventReceiver::PostEventMS(
              this: entity,
              ev: &EV_FadeSound,
              arg1: *(__int64 *)((char *)&v33 + 4),
              arg3: *(__int64 *)&v32,
              a5: v64,
              a6: v41,
              a7: v42,
              a8: v43,
              a9: v44,
              a10: v45,
              a11: v46,
              a12: v47,
              a13: v48,
              a14: v49,
              a15: v50,
              a16: v51,
              a17: v65,
              a18: v52,
              a19: v53,
              a20: v54,
              a21: v55[0]);
            v8 = v57;
            v3 = loopingFireSoundInterval;
            v20 = (idPresentable *)HIDWORD(v59);
          }
          v67 = 255;
          LODWORD(v70[0]) = v19;
          HIBYTE(v70[0]) = 105;
          HIBYTE(v66) = 105;
          DWORD1(v34) = HIDWORD(v70[0]);
          *((_QWORD *)&v34 + 1) = v70[1];
          v35 = __ROL4__(HIDWORD(v70[2]), 32);
          idEventReceiver::PostEventMS(
            this: entity,
            ev: &EV_StopSound,
            arg1: *(__int64 *)((char *)&v34 + 4),
            arg2: *(__int64 *)((char *)&v34 - 4),
            a5: (unsigned int)v68 | 0xFF00000000LL,
            a6: v41,
            a7: v42,
            a8: v43,
            a9: v44,
            a10: v45,
            a11: v46,
            a12: v47,
            a13: v48,
            a14: v49,
            a15: v50,
            a16: v51);
          ++v19;
        }
      }
      else
      {
        for ( j = 0; j < 3; ++j )
          idPresentable::StopSound(this: v20, channel: (soundChannel_t)(j + v19), peerMask: 0);
      }
      if ( !this->loopingFireSoundSkipEndOnEarlyRelease || (v37 = 1, v8 >= v3) )
        v37 = 0;
      if ( this->loopingFireEndSound != nullptr && v37 == 0 )
      {
        LODWORD(v38) = gameLocal->GetGameMsPerRealSec(this: gameLocal);
        *(_QWORD *)((char *)&v38 + 4) = (unsigned int)v3 | 0x3E800000000LL;
        HIDWORD(v38) = v38 * v3;
        this->loopStopedGameTime += (_QWORD)v38 * *(_QWORD *)((char *)&v38 + 4) / *(__int64 *)&v38;
        if ( entity != nullptr )
        {
          fireChannel = this->fireChannel;
          HIBYTE(v66) = 105;
          LODWORD(v70[0]) = this->loopingFireEndSound;
          HIBYTE(v70[0]) = 100;
          v67 = fireChannel;
          idEventReceiver::PostEventMS(
            this: entity,
            ev: &EV_StartSoundShader,
            arg1: *(_QWORD *)HIDWORD(v70[1]),
            arg2: __SPAIR64__(v70[1], __ROL4__(HIDWORD(v70[2]), 32)),
            a5: v68,
            a6: v41,
            a7: v42,
            a8: v43,
            a9: v44,
            a10: v45,
            a11: v46,
            a12: v47,
            a13: v48,
            a14: v49,
            a15: v50,
            a16: v51);
        }
        else
        {
          idPresentable::StartSoundShader(
            this: v20,
            channel: (soundChannel_t)this->fireChannel,
            shader: this->loopingFireEndSound,
            soundShaderFlags: (soundShaderFlags_t)0,
            peerMask: 0);
        }
        v40 = this->fireChannel + 1;
        this->fireChannel = v40;
        if ( v40 > 14 )
          this->fireChannel = 6;
      }
      this->loopingFireEndSound = nullptr;
      this->loopingFireSoundEntity.spawnId = 0;
      this->loopingFireSoundList = nullptr;
    }
  }
}


// ========================================================================
// ?BeginReloading@idWeapon@@QAAXPBVidDeclAmmo@@_N@Z
// EA  : 0x82EC51D0
// RVA : 0x00EC51D0
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __fastcall idWeapon::BeginReloading(idWeapon *this, const idDeclAmmo *ammoDecl, bool secondaryAmmo)
{
  char IsMelee; // r3
  idWeapon::fireState_t v6; // r11

  if ( ammoDecl != nullptr )
  {
    IsMelee = idWeapon::IsMelee(this);
    v6 = FIRESTATE_IDLE;
    if ( IsMelee == 0 )
      v6 = FIRESTATE_RELOADING;
    this->fireState = v6;
    idWeapon::StopLoopingFireSound(this);
  }
  this->nextAmmo = ammoDecl;
  this->finishReloadTime = (int)this->decl[1].handsModelMD6
                         + idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
}


// ========================================================================
// ?UpdateLaserSight@idWeapon@@UAAXABVidVec3@@0HPAVidActor@@@Z
// EA  : 0x82EC5260
// RVA : 0x00EC5260
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __fastcall idWeapon::UpdateLaserSight(
        idWeapon *this,
        const idVec3 *startPos,
        const idVec3 *endPos,
        int passEntityNumber,
        idActor *actor)
{
  idPresentablePtr<idPresentable> *p_presentableWeapon; // r31
  idPresentableWeapon *v9; // r3

  if ( g_weaponUpdateLaser.valueInteger != 0 )
  {
    p_presentableWeapon = (idPresentablePtr<idPresentable> *)&this->presentableWeapon;
    if ( idPresentablePtr<idPresentableProjectile>::operator->(this: (idPresentablePtr<idPresentable> *)&this->presentableWeapon) != nullptr )
    {
      v9 = (idPresentableWeapon *)idPresentablePtr<idPresentableProjectile>::operator->(this: p_presentableWeapon);
      idPresentableWeapon::UpdateLaserSight(this: v9, startPos, endPos, passEntityNumber);
    }
  }
}


// ========================================================================
// ?ShowLaserSight@idWeapon@@QAAXXZ
// EA  : 0x82EC52C0
// RVA : 0x00EC52C0
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __fastcall idWeapon::ShowLaserSight(idWeapon *this)
{
  unsigned int spawnId; // r11
  idPresentablePtr<idPresentable> *p_presentableWeapon; // r29
  int v3; // r31
  idPresentableWeapon *v4; // r3

  spawnId = this->presentableWeapon.spawnId;
  p_presentableWeapon = (idPresentablePtr<idPresentable> *)&this->presentableWeapon;
  v3 = spawnId & 0x3FFF;
  if ( spawnId != 0
    && idClientGame::IsPresentableIndexValid(this: clientGame, index: spawnId & 0x3FFF)
    && idClientGame::GetPresentableByIndex(this: clientGame, index: v3)->spawnId == p_presentableWeapon->spawnId )
  {
    v4 = (idPresentableWeapon *)idPresentablePtr<idPresentableProjectile>::operator->(this: p_presentableWeapon);
    idPresentableWeapon::ShowLaserSight(this: v4);
  }
}


// ========================================================================
// ?HideLaserSight@idWeapon@@QAAXXZ
// EA  : 0x82EC5330
// RVA : 0x00EC5330
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __fastcall idWeapon::HideLaserSight(idWeapon *this)
{
  unsigned int spawnId; // r11
  idPresentablePtr<idPresentable> *p_presentableWeapon; // r29
  int v3; // r31
  idPresentable *v4; // r3

  spawnId = this->presentableWeapon.spawnId;
  p_presentableWeapon = (idPresentablePtr<idPresentable> *)&this->presentableWeapon;
  v3 = spawnId & 0x3FFF;
  if ( spawnId != 0
    && idClientGame::IsPresentableIndexValid(this: clientGame, index: spawnId & 0x3FFF)
    && idClientGame::GetPresentableByIndex(this: clientGame, index: v3)->spawnId == p_presentableWeapon->spawnId )
  {
    v4 = idPresentablePtr<idPresentableProjectile>::operator->(this: p_presentableWeapon);
    idLaserSight::Hide(this: (idLaserSight *)&v4[1].axes[1].mat[1]);
  }
}


// ========================================================================
// ?EjectShell@idWeapon@@QAAXABVidVec3@@0ABVidMat3@@10PAVidFXManager@@@Z
// EA  : 0x82EC53A0
// RVA : 0x00EC53A0
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __fastcall idWeapon::EjectShell(
        idWeapon *this,
        const idVec3 *ejectPos,
        const idVec3 *firstPersonOffset,
        const idMat3 *shellOrientation,
        idMat3 *ejectAxis,
        const idVec3 *emitterVelocity,
        idFXManager *fxMgr)
{
  float *decl; // r11
  idPieceEmitter *pieceEmitterEntity; // r3
  long double v11; // fp2
  int GameMs; // r3
  idPresentablePtr<idPresentable> *p_presentableWeapon; // r30
  int v14; // r31
  idPresentable *v15; // r3

  decl = (float *)this->decl;
  pieceEmitterEntity = this->pieceEmitterEntity;
  if ( pieceEmitterEntity != nullptr )
  {
    *((double *)&v11 + 1) = decl[439];
    *(double *)&v11 = decl[438];
    idPieceEmitter::Emit(
      a1: (int)pieceEmitterEntity,
      a2: ejectPos,
      a3: &firstPersonOffset->x,
      a4: &emitterVelocity->x,
      a5: shellOrientation,
      a6: (float *)ejectAxis,
      deltaSpeed: v11,
      deltaAngle: decl[440]);
    if ( fxMgr != nullptr )
    {
      GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      idFXManager::StartFX(this: fxMgr, org: &vec3_origin, axis: &mat3_identity, time: GameMs, startCondition: 64);
      p_presentableWeapon = (idPresentablePtr<idPresentable> *)&this->presentableWeapon;
      if ( idPresentablePtr<idPresentableProjectile>::operator->(this: p_presentableWeapon) != nullptr
        && fxMgr != &idPresentablePtr<idPresentableProjectile>::operator->(this: p_presentableWeapon)->fxManager )
      {
        v14 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        v15 = idPresentablePtr<idPresentableProjectile>::operator->(this: p_presentableWeapon);
        idFXManager::StartFX(
          this: &v15->fxManager,
          org: &vec3_origin,
          axis: &mat3_identity,
          time: v14,
          startCondition: 64);
      }
    }
  }
}


// ========================================================================
// ?SetPresentableWeapon@idWeapon@@QAAXPAVidPresentableWeapon@@@Z
// EA  : 0x82EC54C0
// RVA : 0x00EC54C0
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __fastcall idWeapon::SetPresentableWeapon(idWeapon *this, idPresentableWeapon *presentableWeapon_)
{
  unsigned int spawnId; // r11
  idPresentablePtr<idPresentable> *p_presentableWeapon; // r31
  int v6; // r30

  spawnId = this->presentableWeapon.spawnId;
  p_presentableWeapon = (idPresentablePtr<idPresentable> *)&this->presentableWeapon;
  v6 = spawnId & 0x3FFF;
  if ( spawnId != 0
    && idClientGame::IsPresentableIndexValid(this: clientGame, index: spawnId & 0x3FFF)
    && idClientGame::GetPresentableByIndex(this: clientGame, index: v6)->spawnId == p_presentableWeapon->spawnId )
  {
    idLib::Warning(fmt: "Setting %s idWeapons presentable weapon twice? ", this->decl->name.str);
    if ( (idWeapon *)LODWORD(idPresentablePtr<idPresentableProjectile>::operator->(this: p_presentableWeapon)[1].axes[0].mat[2].z) == this )
      idPresentablePtr<idPresentableProjectile>::operator->(this: p_presentableWeapon)[1].axes[0].mat[2].z = 0.0;
  }
  if ( presentableWeapon_ != nullptr )
    p_presentableWeapon->spawnId = presentableWeapon_->spawnId;
  else
    p_presentableWeapon->spawnId = 0;
}


// ========================================================================
// ?SetZoomed@idWeapon@@QAAX_NPAVidFXManager@@@Z
// EA  : 0x82EC5580
// RVA : 0x00EC5580
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __fastcall idWeapon::SetZoomed(idWeapon *this, bool zoomed, idFXManager *fxMgr)
{
  BOOL v3; // r31
  const idDeclInventory *decl; // r10
  idPieceEmitter *pieceEmitterEntity; // r3
  idPieceEmitter_vtbl *v8; // r11
  void (*Hide_2)(void); // r10
  int v10; // r3
  idPresentablePtr<idPresentable> *v11; // r30
  int v12; // r31
  idPresentable *v13; // r3
  int GameMs; // r3
  idPresentablePtr<idPresentable> *p_presentableWeapon; // r30
  int v16; // r31
  idPresentable *v17; // r3

  v3 = zoomed;
  decl = this->decl;
  *((_BYTE *)this + 452) = (8 * zoomed) & 8 | *((_BYTE *)this + 452) & 0xF7;
  if ( HIBYTE(decl[3].buyCount) != 0 )
  {
    pieceEmitterEntity = this->pieceEmitterEntity;
    if ( pieceEmitterEntity != nullptr )
    {
      v8 = pieceEmitterEntity->__vftable;
      if ( zoomed )
        Hide_2 = (void (*)(void))v8->Hide_2;
      else
        Hide_2 = (void (*)(void))v8->Show;
      Hide_2();
    }
  }
  if ( (*((_BYTE *)this + 452) & 2) != 0 )
  {
    if ( v3 )
    {
      idWeapon::HideLaserSight(this);
      if ( fxMgr != nullptr )
      {
        GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        idFXManager::StopFX(this: fxMgr, time: GameMs, stopCondition: 84, immediateStop: false);
        p_presentableWeapon = (idPresentablePtr<idPresentable> *)&this->presentableWeapon;
        if ( idPresentablePtr<idPresentableProjectile>::operator->(this: p_presentableWeapon) != nullptr
          && fxMgr != &idPresentablePtr<idPresentableProjectile>::operator->(this: p_presentableWeapon)->fxManager )
        {
          v16 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
          v17 = idPresentablePtr<idPresentableProjectile>::operator->(this: p_presentableWeapon);
          idFXManager::StopFX(this: &v17->fxManager, time: v16, stopCondition: 84, immediateStop: false);
        }
      }
    }
    else
    {
      idWeapon::ShowLaserSight(this);
      if ( fxMgr != nullptr )
      {
        v10 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        idFXManager::StartFX(this: fxMgr, org: &vec3_origin, axis: &mat3_identity, time: v10, startCondition: 83);
        v11 = (idPresentablePtr<idPresentable> *)&this->presentableWeapon;
        if ( idPresentablePtr<idPresentableProjectile>::operator->(this: v11) != nullptr
          && fxMgr != &idPresentablePtr<idPresentableProjectile>::operator->(this: v11)->fxManager )
        {
          v12 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
          v13 = idPresentablePtr<idPresentableProjectile>::operator->(this: v11);
          idFXManager::StartFX(
            this: &v13->fxManager,
            org: &vec3_origin,
            axis: &mat3_identity,
            time: v12,
            startCondition: 83);
        }
      }
    }
  }
}


// ========================================================================
// ??0idLaserCutter@@QAA@XZ
// EA  : 0x82EC5758
// RVA : 0x00EC5758
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

idLaserCutter *__fastcall idLaserCutter::idLaserCutter(idLaserCutter *this)
{
  unsigned __int64 v1; // r29
  double currentValue; // fp13
  double v4; // fp12
  float z; // r4

  idWeapon::idWeapon(this);
  LODWORD(v1) = 0;
  this->beamModelFPView = nullptr;
  this->__vftable = (idLaserCutter_vtbl *)&idLaserCutter::`vftable';
  this->decalModelFPView = nullptr;
  this->decalModelworldView = nullptr;
  idLaserSight::idLaserSight(this: &this->laserBeamCut);
  idLaserSight::idLaserSight(this: &this->laserBeamCutBounce);
  idLaserSight::idLaserSight(this: &this->laserBeamShoot);
  idLaserSight::idLaserSight(this: &this->laserBeamShootBounce);
  idLaserSight::idLaserSight(this: &this->laserBeamShootIndication);
  idLaserSight::idLaserSight(this: &this->laserBeamShootBounceIndication);
  this->laserBeamCutFade.duration = 0.0;
  this->laserBeamCutFade.startTime = 0.0;
  this->laserBeamCutFade.currentTime = 0.0;
  this->laserBeamCutFade.currentValue = 0.0;
  currentValue = this->laserBeamCutFade.currentValue;
  this->laserBeamCutFade.endValue = this->laserBeamCutFade.currentValue;
  this->laserBeamCutFade.startValue = currentValue;
  this->laserBeamBounceIndicationFade.duration = 0.0;
  this->laserBeamBounceIndicationFade.startTime = 0.0;
  this->laserBeamBounceIndicationFade.currentTime = 0.0;
  this->laserBeamBounceIndicationFade.currentValue = 0.0;
  v4 = this->laserBeamBounceIndicationFade.currentValue;
  this->laserBeamBounceIndicationFade.endValue = this->laserBeamBounceIndicationFade.currentValue;
  this->laserBeamBounceIndicationFade.startValue = v4;
  this->currentClipSpinAngle = 0.0;
  this->clipJoint.value = -1;
  this->nextTakeBatteryTime = 0;
  this->maxBattery = 0;
  this->batteryCount = 0;
  this->endEffectActive = false;
  this->cuttingWeldEffectRunning = false;
  this->lastOkToCutTime = 0;
  this->hasBatteryUpgrade = false;
  this->hasRemoteCuttingUpgrade = false;
  this->hasMobileReactorUpgrade = false;
  this->crosshairShouldPulsate = false;
  this->currentFunctionalityLens = FUNCTIONALITY_LENS_ZOOM;
  this->functionalityLensActive = false;
  this->pointTrace.index = v1;
  this->bouncePointTrace.index = v1;
  this->storedBeamImpactPosIsValid = false;
  this->storedBeamImpactPos.x = vec3_origin.x;
  this->storedBeamImpactPos.y = vec3_origin.y;
  z = vec3_origin.z;
  this->chargePerSecond = 50.0;
  this->curChargeAmount = 0.0;
  this->lastChargetTime = -1;
  this->blockChargeUntil = -1;
  this->chargeDelaySec = 1;
  this->storedBeamImpactPos.z = z;
  this->laserBeamCutFade.startTime = 0.0;
  this->laserBeamCutFade.duration = 0.0;
  this->laserBeamCutFade.startValue = 0.0;
  this->laserBeamCutFade.endValue = 0.0;
  this->laserBeamCutFade.currentTime = -1.0;
  this->laserBeamCutFade.currentValue = 0.0;
  this->laserBeamBounceIndicationFade.startTime = 0.0;
  this->laserBeamBounceIndicationFade.duration = 0.0;
  this->laserBeamBounceIndicationFade.startValue = 0.0;
  this->laserBeamBounceIndicationFade.endValue = 0.0;
  this->laserBeamBounceIndicationFade.currentTime = -1.0;
  this->laserBeamBounceIndicationFade.currentValue = 0.0;
  return this;
}


// ========================================================================
// __unwind$509008
// EA  : 0x82EC5904
// RVA : 0x00EC5904
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void _unwind_509008()
{
  int v0; // r12

  idWeapon::~idWeapon(this: *(idWeapon **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$509009
// EA  : 0x82EC592C
// RVA : 0x00EC592C
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void _unwind_509009()
{
  int v0; // r12

  idLaserSight::~idLaserSight(this: (idLaserSight *)(*(_DWORD *)(v0 - 128 + 148) + 536));
}


// ========================================================================
// __unwind$509010
// EA  : 0x82EC5958
// RVA : 0x00EC5958
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void _unwind_509010()
{
  int v0; // r12

  idLaserSight::~idLaserSight(this: (idLaserSight *)(*(_DWORD *)(v0 - 128 + 148) + 584));
}


// ========================================================================
// __unwind$509011
// EA  : 0x82EC5984
// RVA : 0x00EC5984
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void _unwind_509011()
{
  int v0; // r12

  idLaserSight::~idLaserSight(this: (idLaserSight *)(*(_DWORD *)(v0 - 128 + 148) + 632));
}


// ========================================================================
// __unwind$509012
// EA  : 0x82EC59B0
// RVA : 0x00EC59B0
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void _unwind_509012()
{
  int v0; // r12

  idLaserSight::~idLaserSight(this: (idLaserSight *)(*(_DWORD *)(v0 - 128 + 148) + 680));
}


// ========================================================================
// __unwind$509013
// EA  : 0x82EC59DC
// RVA : 0x00EC59DC
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void _unwind_509013()
{
  int v0; // r12

  idLaserSight::~idLaserSight(this: (idLaserSight *)(*(_DWORD *)(v0 - 128 + 148) + 728));
}


// ========================================================================
// ??1idLaserCutter@@UAA@XZ
// EA  : 0x82EC5AC8
// RVA : 0x00EC5AC8
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __fastcall idLaserCutter::~idLaserCutter(idLaserCutter *this)
{
  idLaserSight *p_laserBeamCut; // r27
  idRenderModelBeam *beamModelFPView; // r3
  idRenderModelBeam *beamModelWorldView; // r3
  idRenderModelDecal *decalModelFPView; // r3
  idRenderModelDecal *decalModelworldView; // r3

  this->__vftable = (idLaserCutter_vtbl *)&idLaserCutter::`vftable';
  p_laserBeamCut = &this->laserBeamCut;
  idLaserSight::Shutdown(this: &this->laserBeamCut);
  idLaserSight::Shutdown(this: &this->laserBeamCutBounce);
  idLaserSight::Shutdown(this: &this->laserBeamShoot);
  idLaserSight::Shutdown(this: &this->laserBeamShootBounce);
  idLaserSight::Shutdown(this: &this->laserBeamShootIndication);
  idLaserSight::Shutdown(this: &this->laserBeamShootBounceIndication);
  beamModelFPView = this->beamModelFPView;
  if ( beamModelFPView != nullptr )
  {
    beamModelFPView->unlinked = true;
    beamModelFPView->deleteOnSync = true;
    idRenderModel::CommitThisFrame(this: beamModelFPView);
    this->beamModelFPView = nullptr;
  }
  beamModelWorldView = this->beamModelWorldView;
  if ( beamModelWorldView != nullptr )
  {
    beamModelWorldView->unlinked = true;
    beamModelWorldView->deleteOnSync = true;
    idRenderModel::CommitThisFrame(this: beamModelWorldView);
    this->beamModelWorldView = nullptr;
  }
  decalModelFPView = this->decalModelFPView;
  if ( decalModelFPView != nullptr )
  {
    decalModelFPView->unlinked = true;
    decalModelFPView->deleteOnSync = true;
    idRenderModel::CommitThisFrame(this: decalModelFPView);
    this->decalModelFPView = nullptr;
  }
  decalModelworldView = this->decalModelworldView;
  if ( decalModelworldView != nullptr )
  {
    decalModelworldView->unlinked = true;
    decalModelworldView->deleteOnSync = true;
    idRenderModel::CommitThisFrame(this: decalModelworldView);
    this->decalModelworldView = nullptr;
  }
  idLaserSight::~idLaserSight(this: &this->laserBeamShootBounceIndication);
  idLaserSight::~idLaserSight(this: &this->laserBeamShootIndication);
  idLaserSight::~idLaserSight(this: &this->laserBeamShootBounce);
  idLaserSight::~idLaserSight(this: &this->laserBeamShoot);
  idLaserSight::~idLaserSight(this: &this->laserBeamCutBounce);
  idLaserSight::~idLaserSight(this: p_laserBeamCut);
  idWeapon::~idWeapon(this);
}


// ========================================================================
// __unwind$509118
// EA  : 0x82EC5BFC
// RVA : 0x00EC5BFC
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void _unwind_509118()
{
  int v0; // r12

  idWeapon::~idWeapon(this: *(idWeapon **)(v0 - 176 + 196));
}


// ========================================================================
// __unwind$509119
// EA  : 0x82EC5C24
// RVA : 0x00EC5C24
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void _unwind_509119()
{
  int v0; // r12

  idLaserSight::~idLaserSight(this: (idLaserSight *)(*(_DWORD *)(v0 - 176 + 196) + 536));
}


// ========================================================================
// __unwind$509120
// EA  : 0x82EC5C50
// RVA : 0x00EC5C50
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void _unwind_509120()
{
  int v0; // r12

  idLaserSight::~idLaserSight(this: (idLaserSight *)(*(_DWORD *)(v0 - 176 + 196) + 584));
}


// ========================================================================
// __unwind$509121
// EA  : 0x82EC5C7C
// RVA : 0x00EC5C7C
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void _unwind_509121()
{
  int v0; // r12

  idLaserSight::~idLaserSight(this: (idLaserSight *)(*(_DWORD *)(v0 - 176 + 196) + 632));
}


// ========================================================================
// __unwind$509122
// EA  : 0x82EC5CA8
// RVA : 0x00EC5CA8
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void _unwind_509122()
{
  int v0; // r12

  idLaserSight::~idLaserSight(this: (idLaserSight *)(*(_DWORD *)(v0 - 176 + 196) + 680));
}


// ========================================================================
// __unwind$509123
// EA  : 0x82EC5CD4
// RVA : 0x00EC5CD4
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void _unwind_509123()
{
  int v0; // r12

  idLaserSight::~idLaserSight(this: (idLaserSight *)(*(_DWORD *)(v0 - 176 + 196) + 728));
}


// ========================================================================
// __unwind$509124_0
// EA  : 0x82EC5D00
// RVA : 0x00EC5D00
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void _unwind_509124_0()
{
  int v0; // r12

  idLaserSight::~idLaserSight(this: (idLaserSight *)(*(_DWORD *)(v0 - 176 + 196) + 776));
}


// ========================================================================
// ?UpdateWeaponFunctionality@idLaserCutter@@UAAXPBVidPresentablePlayer@@@Z
// EA  : 0x82EC5D30
// RVA : 0x00EC5D30
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __fastcall idLaserCutter::UpdateWeaponFunctionality(idLaserCutter *this, const idPresentablePlayer *owner)
{
  __int64 v4; // r6
  __int64 v5; // r4
  long double v6; // fp2
  int v7; // r30
  long double v8; // fp2
  int maxBattery; // r11
  int v10; // r10
  int GameMs; // r3
  __int64 v12; // r7
  char v13; // r3
  bool v14; // r4

  if ( this->hasMobileReactorUpgrade )
  {
    if ( this->triggerState != TRIGGERSTATE_PULLED )
    {
      HIDWORD(v5) = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      v7 = HIDWORD(v5);
      if ( SHIDWORD(v5) > this->blockChargeUntil )
      {
        if ( this->lastChargetTime == -1 )
          this->lastChargetTime = HIDWORD(v5);
        LODWORD(v4) = HIDWORD(v5) - this->lastChargetTime;
        LODWORD(v5) = timeManager.gameTimePerFrame.value * timeManager.gameHz;
        *(double *)&v6 = (float)((float)((float)((float)v4 / (float)v5) * this->chargePerSecond) + this->curChargeAmount);
        this->curChargeAmount = (float)((float)((float)v4 / (float)v5) * this->chargePerSecond) + this->curChargeAmount;
        if ( *(double *)&v6 > 1.0 )
        {
          v8 = floor(x: v6);
          maxBattery = this->maxBattery;
          v10 = (int)(float)*(double *)&v8 + this->batteryCount;
          this->curChargeAmount = this->curChargeAmount - (float)*(double *)&v8;
          if ( maxBattery >= v10 )
            maxBattery = v10;
          this->batteryCount = maxBattery;
        }
        this->lastChargetTime = v7;
      }
    }
    else
    {
      this->lastChargetTime = -1;
      GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      LODWORD(v12) = this->chargeDelaySec;
      this->blockChargeUntil = GameMs - (int)(float)((float)v12 * (float)-1000.0);
    }
  }
  if ( owner == nullptr
    || !idUCmdTracker::IsPressedForPlayer(this: &owner->ucmdTracker1, mask: 8)
    || owner->environmentAnalyzer.forwardCollision
    || (v13 = idHands::IsInRestState(this: &owner->hands), v14 = true, v13 != 0) )
  {
    v14 = false;
  }
  idLaserCutter::SetFunctionalityLensState(this, on: v14);
}


// ========================================================================
// ?UpdateJointMods@idLaserCutter@@UAAXPAVidTreeAnimator@@@Z
// EA  : 0x82EC5F00
// RVA : 0x00EC5F00
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idLaserCutter::UpdateJointMods(
        idLaserCutter *this,
        idIndex<short,enum invalidJointIndex_t> *parentModel,
        int a3,
        __int64 a4)
{
  const idDeclMD6 *v6; // r11
  const idDeclInventory *decl; // r28
  const idMD6Skel *v8; // r11
  int v9; // r31
  int maxBattery; // r8
  double v11; // fp31
  idMat3x4 *v12; // r31
  double v13; // fp7
  double v14; // fp6
  double v15; // fp5
  double v16; // fp4
  double v17; // fp3
  double v18; // fp2
  double v19; // fp1
  double v20; // fp0
  int GameMsPerFrame; // r3
  double v22; // fp0
  double currentClipSpinAngle; // fp13
  __int64 v24; // r6
  int v25; // r9
  const idMat3 *v26; // r3
  idVec3 v27; // [sp+50h] [-F0h] BYREF
  char v28; // [sp+5Ch] [-E4h] BYREF
  idMat3 v29; // [sp+60h] [-E0h] BYREF
  float v30; // [sp+84h] [-BCh]
  float v31; // [sp+88h] [-B8h]
  float v32; // [sp+8Ch] [-B4h]
  float v33; // [sp+90h] [-B0h]
  idVec3 v34[2]; // [sp+98h] [-A8h] BYREF
  idMat3 v35; // [sp+B0h] [-90h] BYREF
  idMat3 v36; // [sp+E0h] [-60h] BYREF

  if ( parentModel != nullptr )
  {
    v6 = *(const idDeclMD6 **)&parentModel[1016].value;
    if ( v6 != nullptr && v6->model != nullptr )
    {
      decl = this->decl;
      if ( (unsigned __int16)this->clipJoint.value >= 0x8000u )
        this->clipJoint.value = HIWORD(idTreeAnimator::GetJointIndex(
                                         this: (idTreeAnimator *)&v28,
                                         result: parentModel,
                                         jointName: (const char *)decl[4].dualWieldItemDecl)->__vftable);
      if ( (unsigned __int16)this->clipJoint.value < 0x8000u )
      {
        v8 = *(const idMD6Skel **)(*(_DWORD *)(*(_DWORD *)&parentModel[1016].value + 60) + 212);
        if ( v8 != nullptr )
          v9 = (int)v8->data + v8->data->inverseBasePoseOffset;
        else
          v9 = 0;
        maxBattery = this->maxBattery;
        LODWORD(a4) = this->batteryCount;
        *(_QWORD *)&v27.x = a4;
        v11 = (float)((float)a4 / (float)*(__int64 *)((char *)&a4 - 4));
        idRenderModel::SetParm(this: (idRenderModel *)parentModel, parm: rp->Diversity, scalar: v11);
        idTreeAnimator::GetModelSpaceJointTransform(
          this: (idTreeAnimator *)parentModel,
          pose: (animationPose_t)0,
          jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)this->clipJoint.value,
          origin: v34,
          axis: &v36);
        v12 = (idMat3x4 *)(48 * this->clipJoint.value + v9);
        idMat3x4::Transform(this: v12, result: &v27, v: v34);
        v13 = v12->mat[6];
        v14 = v12->mat[2];
        v15 = v12->mat[9];
        v16 = v12->mat[5];
        v17 = v12->mat[1];
        v18 = v12->mat[8];
        v19 = v12->mat[4];
        v20 = v12->mat[0];
        v33 = v12->mat[10];
        v32 = v13;
        v31 = v14;
        v30 = v15;
        v29.mat[2].z = v16;
        v29.mat[2].y = v17;
        v29.mat[2].x = v18;
        v29.mat[1].z = v19;
        v29.mat[1].y = v20;
        idMat3::operator*(this: &v35, result: (idMat3 *)&v29.mat[1].y, a: &v36);
        if ( __fsqrts((float)((float)(v27.x * v27.x) + (float)((float)(v27.y * v27.y) + (float)(v27.z * v27.z)))) < 1.0
          && (unsigned __int8)idMat3::Compare(this: &v35, a: &mat3_identity, epsilon: 0.000099999997) != 0 )
        {
          GameMsPerFrame = idGameTimeManager::GetGameMsPerFrame(
                             this: &clientGame->gameTimeManager,
                             type: GAMETIME_SCALED);
          v22 = *(float *)&decl[4].handsModelMD6Alt;
          currentClipSpinAngle = this->currentClipSpinAngle;
          LODWORD(v24) = timeManager.gameTimePerFrame.value * timeManager.gameHz;
          *(_QWORD *)&v27.x = v24;
          this->currentClipSpinAngle = (float)((float)((float)((float)__SPAIR64__(&timeManager, GameMsPerFrame)
                                                             / (float)v24)
                                                     * (float)v22)
                                             * (float)v11)
                                     + (float)currentClipSpinAngle;
        }
        if ( this->currentClipSpinAngle > 360.0 )
          this->currentClipSpinAngle = this->currentClipSpinAngle - (float)360.0;
        v25 = *(_DWORD *)&parentModel[1030].value;
        v29.mat[0].x = this->currentClipSpinAngle;
        v29.mat[0].y = 0.0;
        v29.mat[0].z = 0.0;
        if ( *(int *)&parentModel[8 * v25 + 1036].value <= 0 )
        {
          v26 = idAngles::ToMat3(this: (idAngles *)&v35, result: &v29);
          idTreeAnimator::SetJointAxis(
            this: (idTreeAnimator *)parentModel,
            pose: DRIVER_MODEL,
            jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)this->clipJoint.value,
            type: JOINTMOD_LOCAL,
            axis: v26);
        }
      }
    }
  }
}


// ========================================================================
// ?GetTotalRepairCost@idVehicleKey@@QBAHXZ
// EA  : 0x82EC61B0
// RVA : 0x00EC61B0
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

int __fastcall idVehicleKey::GetTotalRepairCost(idVehicleKey *this)
{
  idVehicle *VehicleFromKey; // r3
  double maxArmoredHealth; // fp31
  const idMaterial *quickIcon; // r31

  VehicleFromKey = idVehicleKey::GetVehicleFromKey(this);
  if ( VehicleFromKey == nullptr )
    return 0;
  maxArmoredHealth = VehicleFromKey->maxArmoredHealth;
  quickIcon = this->decl[1].quickIcon;
  return (int)(float)((float)((float)1.0
                            - (float)(idVehicle::GetArmoredHealth(this: VehicleFromKey) / (float)maxArmoredHealth))
                    * (float)__SPAIR64__(0x82000000, (unsigned int)quickIcon));
}


// ========================================================================
// ?GetDamagePercent@idVehicleKey@@QBAMXZ
// EA  : 0x82EC6238
// RVA : 0x00EC6238
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

float __fastcall idVehicleKey::GetDamagePercent(idVehicleKey *this)
{
  idVehicle *VehicleFromKey; // r3
  double maxArmoredHealth; // fp31
  double ArmoredHealth; // fp1
  double v4; // fp13
  double v5; // fp0
  double v6; // fp1

  VehicleFromKey = idVehicleKey::GetVehicleFromKey(this);
  if ( VehicleFromKey != nullptr )
  {
    maxArmoredHealth = VehicleFromKey->maxArmoredHealth;
    ArmoredHealth = idVehicle::GetArmoredHealth(this: VehicleFromKey);
    v4 = 0.0;
    v5 = (float)((float)((float)maxArmoredHealth - (float)ArmoredHealth) / (float)maxArmoredHealth);
    if ( v5 < 0.0 || (v4 = 1.0, v5 > 1.0) )
      v5 = v4;
    v6 = v5;
  }
  else
  {
    v6 = 0.0;
  }
  return *((float *)&v6 + 1);
}


// ========================================================================
// ?DoPartialRepair@idVehicleKey@@QAAXH@Z
// EA  : 0x82EC62C0
// RVA : 0x00EC62C0
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __fastcall idVehicleKey::DoPartialRepair(idVehicleKey *this, int cash)
{
  idVehicle *VehicleFromKey; // r31
  __int64 v5; // r11
  __int64 v6; // r10
  double maxArmoredHealth; // fp30
  double v8; // fp31
  double ArmoredHealth; // fp1
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idPresentable *presentable; // r11
  idTreeAnimator *v12; // r30
  unsigned int v13; // r4
  __int64 v14; // [sp+50h] [-40h]

  VehicleFromKey = idVehicleKey::GetVehicleFromKey(this);
  if ( VehicleFromKey != nullptr )
  {
    LODWORD(v5) = cash;
    v14 = v5;
    LODWORD(v6) = idVehicleKey::GetTotalRepairCost(this);
    maxArmoredHealth = VehicleFromKey->maxArmoredHealth;
    v8 = (float)((float)v14 / (float)v6);
    ArmoredHealth = idVehicle::GetArmoredHealth(this: VehicleFromKey);
    VehicleFromKey->IncreaseHealth(
      this: VehicleFromKey,
      a2: (float)((float)((float)maxArmoredHealth - (float)ArmoredHealth) * (float)v8));
    idVehicle::UpdateDamageDecals(
      this: VehicleFromKey,
      trace: nullptr,
      damageDef: nullptr,
      dir: &vec3_origin,
      damageScale: 1.0);
    this->health = idVehicle::GetArmoredHealth(this: VehicleFromKey);
    TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: VehicleFromKey);
    presentable = VehicleFromKey->presentable;
    v12 = TreeAnimatorFromPresentable;
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this: VehicleFromKey);
      presentable = VehicleFromKey->presentable;
    }
    idPresentable::UpdateModelTransform(this: presentable);
    if ( v12 != nullptr )
    {
      if ( v8 >= 0.75 )
      {
        idTreeAnimator::ClearMorphPoints(this: v12);
        return;
      }
      if ( v8 > 0.25 && v8 <= 0.5 )
      {
        v13 = 1;
LABEL_13:
        idTreeAnimator::BitShiftMorphPoints(this: v12, bitShift: v13);
        return;
      }
      if ( v8 > 0.5 && v8 < 0.75 )
      {
        v13 = 2;
        goto LABEL_13;
      }
    }
  }
}


// ========================================================================
// ?DoTotalRepair@idVehicleKey@@QAAXXZ
// EA  : 0x82EC6428
// RVA : 0x00EC6428
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __fastcall idVehicleKey::DoTotalRepair(idVehicleKey *this)
{
  idVehicle *VehicleFromKey; // r3
  idVehicle *v3; // r31
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idPresentable *presentable; // r11
  idTreeAnimator *v6; // r30

  VehicleFromKey = idVehicleKey::GetVehicleFromKey(this);
  v3 = VehicleFromKey;
  if ( VehicleFromKey != nullptr )
  {
    VehicleFromKey->IncreaseHealth(this: VehicleFromKey, a2: VehicleFromKey->maxArmoredHealth);
    idVehicle::UpdateDamageDecals(this: v3, trace: nullptr, damageDef: nullptr, dir: &vec3_origin, damageScale: 0.0);
    this->health = v3->maxArmoredHealth;
    TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: v3);
    presentable = v3->presentable;
    v6 = TreeAnimatorFromPresentable;
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this: v3);
      presentable = v3->presentable;
    }
    idPresentable::UpdateModelTransform(this: presentable);
    if ( v6 != nullptr )
      idTreeAnimator::ClearMorphPoints(this: v6);
  }
  else
  {
    idLib::Warning(fmt: "no vehicle found in idVehicleKey::DoTotalRepair!");
  }
}


// ========================================================================
// ??1idVehicleQuickItem@@UAA@XZ
// EA  : 0x82EC6500
// RVA : 0x00EC6500
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __fastcall idVehicleQuickItem::~idVehicleQuickItem(idVehicleQuickItem *this)
{
  idPresentablePtr<idPresentable> *p_presentableOwner; // r30
  idPresentable *v3; // r3
  idPresentableVehicle *v4; // r3
  idPresentableVehicle *v5; // r30
  int GameMs; // r28
  idFXManager *PredictedFXMgr; // r3

  this->__vftable = (idVehicleQuickItem_vtbl *)&idVehicleQuickItem::`vftable';
  p_presentableOwner = &this->presentableOwner;
  if ( idPresentablePtr<idPresentable>::IsValid(this: (idPresentablePtr<idPresentableActor> *)&this->presentableOwner) )
  {
    v3 = idPresentablePtr<idPresentableProjectile>::operator->(this: p_presentableOwner);
    v4 = v3->GetVehicleInterface(this: v3);
    v5 = v4;
    if ( v4 != nullptr )
    {
      idPresentableVehicle::RemoveQuickItemThink(this: v4, item: this);
      GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      PredictedFXMgr = idPresentableVehicle::GetPredictedFXMgr(this: v5);
      idFXManager::StopFX(this: PredictedFXMgr, time: GameMs, stopCondition: 114, immediateStop: false);
    }
  }
  this->__vftable = (idVehicleQuickItem_vtbl *)&idInventoryItem::`vftable';
  idEventReceiver::~idEventReceiver(this);
}


// ========================================================================
// __unwind$509823
// EA  : 0x82EC65B8
// RVA : 0x00EC65B8
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void _unwind_509823()
{
  int v0; // r12

  idInventoryItem::~idInventoryItem(this: *(idInventoryItem **)(v0 - 128 + 148));
}


// ========================================================================
// ?SetVehicle@idVehicleQuickItem@@QAAXPAVidEntity@@@Z
// EA  : 0x82EC65E0
// RVA : 0x00EC65E0
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __fastcall idVehicleQuickItem::SetVehicle(idVehicleQuickItem *this, idVehicle_Car *entity)
{
  idVehicle_Car *v3; // r3

  v3 = idVehicle_Car::CastTo(c: entity);
  if ( v3 != nullptr )
    this->vehicle.spawnId.value = (gameLocal->spawnIds.ptr[v3->entityNumber] << 13) | v3->entityNumber;
}


// ========================================================================
// ?CanUseInVehicle@idVehicleQuickItem@@UAA_NPAVidActor@@@Z
// EA  : 0x82EC6640
// RVA : 0x00EC6640
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

unsigned int __fastcall idVehicleQuickItem::CanUseInVehicle(idVehicleQuickItem *this, idActor *actor)
{
  int value; // r10
  idEntityPtr<idEntity> *p_vehicle; // r30
  idEntity *v5; // r3
  unsigned int v7; // r31
  idVehicle_Car *v8; // r3
  idVehicle_Car *v9; // r3

  value = this->vehicle.spawnId.value;
  p_vehicle = &this->vehicle;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
  {
    v5 = gameLocal->entities.ptr[value & 0x1FFF];
    if ( v5 != nullptr && idEntity::CastTo(c: v5) != nullptr && !this->active )
    {
      v7 = *(_DWORD *)&this->decl[1].hasBeenParsedAtLeastOnce;
      if ( v7 == 10 )
        return 1;
      v8 = (idVehicle_Car *)idEntityPtr<idEntity const>::operator->(this: p_vehicle);
      v9 = idVehicle_Car::CastTo(c: v8);
      if ( v9 != nullptr )
        return idVehicle_Car::CanActivateQuickUse(this: v9, t: v7);
    }
  }
  return 0;
}


// ========================================================================
// ??0idVehicle_BoostExtender@@QAA@XZ
// EA  : 0x82EC6708
// RVA : 0x00EC6708
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

idVehicle_BoostExtender *__fastcall idVehicle_BoostExtender::idVehicle_BoostExtender(idVehicle_BoostExtender *this)
{
  idVehicleQuickItem::idVehicleQuickItem(this);
  this->useTimeMS = -1;
  this->__vftable = (idVehicle_BoostExtender_vtbl *)&idVehicle_BoostExtender::`vftable';
  this->cooldown = 0;
  return this;
}


// ========================================================================
// ??0idVehicle_Smash@@QAA@XZ
// EA  : 0x82EC6758
// RVA : 0x00EC6758
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

idVehicle_Smash *__fastcall idVehicle_Smash::idVehicle_Smash(idVehicle_Smash *this)
{
  idVehicleQuickItem::idVehicleQuickItem(this);
  this->useTimeMS = -1;
  this->__vftable = (idVehicle_Smash_vtbl *)&idVehicle_Smash::`vftable';
  this->cooldown = 0;
  return this;
}


// ========================================================================
// ??0idVehicle_Shockwave@@QAA@XZ
// EA  : 0x82EC67A8
// RVA : 0x00EC67A8
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

idVehicle_Shockwave *__fastcall idVehicle_Shockwave::idVehicle_Shockwave(idVehicle_Shockwave *this)
{
  idVehicleQuickItem::idVehicleQuickItem(this);
  this->lastThinkTime = 0;
  this->__vftable = (idVehicle_Shockwave_vtbl *)&idVehicle_Shockwave::`vftable';
  return this;
}


// ========================================================================
// ??0idVehicle_Aftershocker@@QAA@XZ
// EA  : 0x82EC67F8
// RVA : 0x00EC67F8
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

idVehicle_Aftershocker *__fastcall idVehicle_Aftershocker::idVehicle_Aftershocker(idVehicle_Aftershocker *this)
{
  idVehicleQuickItem::idVehicleQuickItem(this);
  this->lastThinkTime = 0;
  this->__vftable = (idVehicle_Aftershocker_vtbl *)&idVehicle_Aftershocker::`vftable';
  this->damagedEntList.list = nullptr;
  this->damagedEntList.granularity = 0;
  this->damagedEntList.memTag = 5;
  this->damagedEntList.listStatic = 0;
  this->damagedEntList.size = 0;
  this->damagedEntList.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->damagedEntList);
  return this;
}


// ========================================================================
// __unwind$510020
// EA  : 0x82EC6870
// RVA : 0x00EC6870
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void _unwind_510020()
{
  int v0; // r12

  idVehicleQuickItem::~idVehicleQuickItem(this: *(idVehicleQuickItem **)(v0 - 112 + 132));
}


// ========================================================================
// ??1idVehicle_Aftershocker@@UAA@XZ
// EA  : 0x82EC68A0
// RVA : 0x00EC68A0
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __fastcall idVehicle_Aftershocker::~idVehicle_Aftershocker(idVehicle_Aftershocker *this)
{
  this->__vftable = (idVehicle_Aftershocker_vtbl *)&idVehicle_Aftershocker::`vftable';
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->damagedEntList);
  idVehicleQuickItem::~idVehicleQuickItem(this);
}


// ========================================================================
// __unwind$510041
// EA  : 0x82EC68F4
// RVA : 0x00EC68F4
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void _unwind_510041()
{
  int v0; // r12

  idVehicleQuickItem::~idVehicleQuickItem(this: *(idVehicleQuickItem **)(v0 - 112 + 132));
}


// ========================================================================
// ??0idVehicle_Aftershock_MP@@QAA@XZ
// EA  : 0x82EC6920
// RVA : 0x00EC6920
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

idVehicle_Aftershock_MP *__fastcall idVehicle_Aftershock_MP::idVehicle_Aftershock_MP(idVehicle_Aftershock_MP *this)
{
  idVehicleQuickItem::idVehicleQuickItem(this);
  this->__vftable = (idVehicle_Aftershock_MP_vtbl *)&idVehicle_Aftershock_MP::`vftable';
  return this;
}


// ========================================================================
// ??0idVehicle_EMP@@QAA@XZ
// EA  : 0x82EC6960
// RVA : 0x00EC6960
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

idVehicle_EMP *__fastcall idVehicle_EMP::idVehicle_EMP(idVehicle_EMP *this)
{
  idVehicleQuickItem::idVehicleQuickItem(this);
  this->__vftable = (idVehicle_EMP_vtbl *)&idVehicle_EMP::`vftable';
  return this;
}


// ========================================================================
// ??0idVehicle_Teleporter@@QAA@XZ
// EA  : 0x82EC69A0
// RVA : 0x00EC69A0
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

idVehicle_Teleporter *__fastcall idVehicle_Teleporter::idVehicle_Teleporter(idVehicle_Teleporter *this)
{
  float *p_z; // r10
  int v3; // ctr
  float *p_y; // r11

  idVehicleQuickItem::idVehicleQuickItem(this);
  this->__vftable = (idVehicle_Teleporter_vtbl *)&idVehicle_Teleporter::`vftable';
  p_z = &this->angularVel.z;
  this->location = vec3_origin;
  v3 = 9;
  p_y = &mat2_identity.mat[1].y;
  this->linearVel = vec3_origin;
  this->angularVel = vec3_origin;
  do
  {
    *++p_z = *++p_y;
    --v3;
  }
  while ( v3 != 0 );
  this->teleporterPlaced = false;
  return this;
}


// ========================================================================
// ??0idVehicle_Jump@@QAA@XZ
// EA  : 0x82EC6A68
// RVA : 0x00EC6A68
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

idVehicle_Jump *__fastcall idVehicle_Jump::idVehicle_Jump(idVehicle_Jump *this)
{
  idVehicleQuickItem::idVehicleQuickItem(this);
  this->__vftable = (idVehicle_Jump_vtbl *)&idVehicle_Jump::`vftable';
  return this;
}


// ========================================================================
// ??0idVehicle_Megabooster@@QAA@XZ
// EA  : 0x82EC6AA8
// RVA : 0x00EC6AA8
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

idVehicle_Megabooster *__fastcall idVehicle_Megabooster::idVehicle_Megabooster(idVehicle_Megabooster *this)
{
  idVehicleQuickItem::idVehicleQuickItem(this);
  this->__vftable = (idVehicle_Megabooster_vtbl *)&idVehicle_Megabooster::`vftable';
  this->acceleration = vehicle_megabooster_force.valueFloat;
  this->time = vehicle_megabooster_time.valueInteger;
  return this;
}


// ========================================================================
// ??1idVehicle_Megabooster@@UAA@XZ
// EA  : 0x82EC6B08
// RVA : 0x00EC6B08
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __fastcall idVehicle_Megabooster::~idVehicle_Megabooster(idVehicle_Megabooster *this)
{
  this->__vftable = (idVehicle_Megabooster_vtbl *)&idVehicle_Megabooster::`vftable';
  idVehicleQuickItem::~idVehicleQuickItem(this);
}


// ========================================================================
// ??0idVehicle_Health@@QAA@XZ
// EA  : 0x82EC6B18
// RVA : 0x00EC6B18
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

idVehicle_Health *__fastcall idVehicle_Health::idVehicle_Health(idVehicle_Health *this)
{
  idVehicleQuickItem::idVehicleQuickItem(this);
  this->__vftable = (idVehicle_Health_vtbl *)&idVehicle_Health::`vftable';
  return this;
}


// ========================================================================
// ??0idVehicle_Stomp@@QAA@XZ
// EA  : 0x82EC6B58
// RVA : 0x00EC6B58
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

idVehicle_Stomp *__fastcall idVehicle_Stomp::idVehicle_Stomp(idVehicle_Stomp *this)
{
  idVehicleQuickItem::idVehicleQuickItem(this);
  this->hasFired = false;
  this->__vftable = (idVehicle_Stomp_vtbl *)&idVehicle_Stomp::`vftable';
  return this;
}


// ========================================================================
// ??0idVehicle_InstantDamage@@QAA@XZ
// EA  : 0x82EC6BA0
// RVA : 0x00EC6BA0
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

idVehicle_InstantDamage *__fastcall idVehicle_InstantDamage::idVehicle_InstantDamage(idVehicle_InstantDamage *this)
{
  idVehicleQuickItem::idVehicleQuickItem(this);
  this->__vftable = (idVehicle_InstantDamage_vtbl *)&idVehicle_InstantDamage::`vftable';
  return this;
}


// ========================================================================
// ?VehicleQuickUseWeaponUse@idClientServerInterfaceServer@@UAA_NPAVidInventoryItem@@PAVidPresentable@@@Z
// EA  : 0x82EC6BE0
// RVA : 0x00EC6BE0
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

int __fastcall idClientServerInterfaceServer::VehicleQuickUseWeaponUse(
        idClientServerInterfaceServer *this,
        idVehicle_QuickUseWeapon *item,
        idPresentable *presentable)
{
  idEntity *entity; // r31
  idPresentable *v6; // r3
  int v7; // r31
  idVehicle_QuickUseWeapon *v8; // r3
  int v9; // r7
  int v10; // r10
  int i; // r11

  if ( (unsigned __int8)idClientServerInterfaceClient::VehicleQuickUseWeaponUse(this, item, presentable) == 0 )
    return 0;
  entity = this->entity;
  if ( entity == nullptr )
    return 0;
  v6 = entity->presentable;
  if ( v6 == nullptr )
  {
    idEntity::InitPresentableInternal(this: entity);
    v6 = entity->presentable;
  }
  v7 = (int)v6->GetVehicleInterface(this: v6);
  if ( v7 == 0 )
    return 0;
  v8 = idVehicle_QuickUseWeapon::CastTo(c: item);
  if ( v8 == nullptr )
    return 0;
  v9 = *(_DWORD *)(v7 + 18748);
  v10 = 0;
  if ( v9 <= 0 )
    return 0;
  for ( i = 0;
        *(idDeclInventory_vtbl **)(*(_DWORD *)(*(_DWORD *)(i + *(_DWORD *)(v7 + 18744)) + 40) + 12) != v8->decl[1].__vftable;
        i += 4 )
  {
    if ( ++v10 >= v9 )
      return 0;
  }
  return 1;
}


// ========================================================================
// ?CanUse@idInventoryItem@@UAA_NPAVidActor@@@Z
// EA  : 0x82EC6E60
// RVA : 0x00EC6E60
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

int __fastcall idInventoryItem::CanUse(idInventoryItem *this, idActor *user)
{
  const idDeclInventory *decl; // r11
  const function_t *Function; // r28
  const function_t *v6; // r3
  const idDeclInventory *v7; // r11
  const idDeclRecipe *recipe; // r27
  int num; // r11
  int v10; // r29
  char *v11; // r30
  const idDeclInventory *v12; // r25
  idInventoryCollection *v13; // r3
  int result; // r3
  idThread *v15; // r3
  idThread *v16; // r30
  int GameMs; // r3
  const idDeclInventory *v18; // r11
  int v19; // r29
  const char *Key; // r3
  __int64 v21; // r10
  __int64 v22; // r8
  va *v23; // r3
  __int64 v24; // r6
  __int64 v25; // r8
  BOOL v26; // r29
  int v27; // [sp+8h] [-1098h]
  int v28; // [sp+Ch] [-1094h]
  int v29; // [sp+10h] [-1090h]
  int v30; // [sp+14h] [-108Ch]
  int v31; // [sp+18h] [-1088h]
  int v32; // [sp+1Ch] [-1084h]
  va v33; // [sp+60h] [-1040h] BYREF

  decl = this->decl;
  if ( decl->isWeapon && gameLocal->world->mapType == MAPTYPE_TOWN )
    return 0;
  Function = idScriptObject::GetFunction(this: &decl->scriptUse, name: "canUse");
  v6 = idScriptObject::GetFunction(this: &this->decl->scriptUse, name: "use");
  if ( Function != nullptr )
  {
    v15 = (idThread *)idMem::AllocWithLocation(
                        this: &mem,
                        location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                        size: 0x1B94u,
                        tag: TAG_NEW,
                        zeroBuffer: false,
                        align: ALIGN_16,
                        heap: HEAP_DEFAULTHEAP);
    if ( v15 != nullptr )
      v16 = idThread::idThread(this: v15);
    else
      v16 = nullptr;
    idThread::ManualDelete(this: v16);
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    v18 = this->decl;
    v19 = GameMs;
    Key = idStrId::GetKey(this: &v18->displayName);
    LODWORD(v21) = &unk_822D0000;
    v23 = va::va(
            this: &v33,
            fmt: "%s_%d",
            a3: __SPAIR64__((unsigned int)Key, v19),
            a4: v22,
            a5: v21,
            a6: v27,
            a7: v28,
            a8: v29,
            a9: v30,
            a10: v31,
            a11: v32);
    idThread::SetThreadName(this: v16, name: v23->buffer);
    idInterpreter::PushEntity(this: &v16->interpreter, ent: user);
    LODWORD(v24) = 0;
    HIDWORD(v24) = Function;
    idInterpreter::EnterObjectFunction(this: &v16->interpreter, self: user, clearStack: v24, a4: v25);
    user->ExecuteThread(this: user, a2: v16);
    v26 = *gameLocal->program.returnDef->value.value.ip != 0;
    if ( v16 != nullptr )
      ((void (__fastcall *)(idThread *, int))v16->dtr_idClass)(a1: v16, a2: 1);
    return v26;
  }
  else
  {
    if ( v6 != nullptr )
      return 1;
    v7 = this->decl;
    recipe = v7->recipe;
    if ( recipe != nullptr )
    {
      num = recipe->ingredients.num;
      v10 = 0;
      if ( num > 0 )
      {
        while ( 1 )
        {
          if ( v10 >= 0 && v10 <= num )
          {
            v11 = (char *)recipe->ingredients.list + (unsigned int)Function;
            if ( v11 != nullptr )
            {
              v12 = *(const idDeclInventory **)v11;
              v13 = user->GetInventory_2(this: user);
              if ( idInventoryCollection::FindTotalInventoryItemCount(this: v13, decl: v12) < *((_DWORD *)v11 + 1) )
                break;
            }
          }
          num = recipe->ingredients.num;
          ++v10;
          Function = (const function_t *)((char *)Function + 12);
          if ( v10 >= num )
            return 1;
        }
        return 0;
      }
      return 1;
    }
    if ( v7->dropable )
      return 1;
    if ( v7->equipWeaponOnUse == nullptr )
      return 0;
    result = 1;
    if ( gameLocal->world->mapType == MAPTYPE_TOWN )
      return 0;
  }
  return result;
}


// ========================================================================
// __unwind$510593_0
// EA  : 0x82EC70C8
// RVA : 0x00EC70C8
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __fastcall _unwind_510593_0(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 4256 + 80), tag: a2);
}


// ========================================================================
// ?Use@idInventoryItem@@UAA_NPAVidActor@@@Z
// EA  : 0x82EC70F8
// RVA : 0x00EC70F8
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

int __fastcall idInventoryItem::Use(idInventoryItem *this, idPlayer *user)
{
  const function_t *Function; // r28
  idThread *v5; // r3
  idThread *v6; // r30
  int GameMs; // r29
  const char *Key; // r3
  __int64 v9; // r10
  __int64 v10; // r8
  va *v11; // r3
  __int64 v12; // r6
  __int64 v13; // r8
  BOOL v14; // r29
  const idDeclInventory *decl; // r11
  const idSoundShader *useSound; // r5
  const idDeclInventory *v18; // r11
  _DWORD *v19; // r26
  int v20; // r11
  int v21; // r29
  int v22; // r28
  int v23; // r30
  const idDeclInventory *v24; // r25
  idInventoryCollection *v25; // r3
  int v26; // r28
  int v27; // r25
  int v28; // r30
  idPresentable *presentable; // r29
  int v30; // r24
  const idDeclInventory *v31; // r30
  idInventoryCollection *v32; // r3
  int v33; // r9
  signed int v34; // r11
  int v35; // r11
  unsigned int seed; // r7
  unsigned int v37; // r3
  int v38; // r8
  unsigned int v39; // r4
  int v40; // r28
  const idDeclJob *v41; // r29
  idPresentable *v42; // r30
  idInventoryCollection *v43; // r3
  idPlayer *v44; // r4
  idPlayer *v45; // r3
  idPlayer *v46; // r29
  idEntity *v47; // r3
  idEntity *v48; // r30
  idPlayer *v49; // r3
  _DWORD *v50; // r30
  int v51; // r3
  int v52; // r3
  int v53; // r3
  const idDeclWeapon *equipWeaponOnUse; // r29
  idJobManager *v55; // r3
  idJob *JobByDecl; // r3
  int v57; // r11
  idWeapon *v58; // r29
  int v59; // r30
  idWeapon *v60; // r5
  int v61; // [sp+8h] [-10A8h]
  int v62; // [sp+Ch] [-10A4h]
  int v63; // [sp+10h] [-10A0h]
  int v64; // [sp+14h] [-109Ch]
  int v65; // [sp+18h] [-1098h]
  int v66; // [sp+1Ch] [-1094h]
  va v67; // [sp+60h] [-1050h] BYREF

  if ( user == nullptr )
    return 0;
  if ( common->IsServer(this: common) )
  {
    Function = idScriptObject::GetFunction(this: &this->decl->scriptUse, name: "use");
    if ( Function != nullptr )
    {
      v5 = (idThread *)idMem::AllocWithLocation(
                         this: &mem,
                         location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                         size: 0x1B94u,
                         tag: TAG_NEW,
                         zeroBuffer: false,
                         align: ALIGN_16,
                         heap: HEAP_DEFAULTHEAP);
      if ( v5 != nullptr )
        v6 = idThread::idThread(this: v5);
      else
        v6 = nullptr;
      idThread::ManualDelete(this: v6);
      GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      Key = idStrId::GetKey(this: &this->decl->displayName);
      LODWORD(v9) = &unk_822D0000;
      v11 = va::va(
              this: &v67,
              fmt: "%s_%d",
              a3: __SPAIR64__((unsigned int)Key, GameMs),
              a4: v10,
              a5: v9,
              a6: v61,
              a7: v62,
              a8: v63,
              a9: v64,
              a10: v65,
              a11: v66);
      idThread::SetThreadName(this: v6, name: v11->buffer);
      idInterpreter::Reset(this: &v6->interpreter);
      idInterpreter::PushEntity(this: &v6->interpreter, ent: user);
      LODWORD(v12) = 0;
      HIDWORD(v12) = Function;
      idInterpreter::EnterObjectFunction(this: &v6->interpreter, self: user, clearStack: v12, a4: v13);
      user->ExecuteThread(this: user, a2: v6);
      v14 = *gameLocal->program.returnDef->value.value.ip != 0;
      if ( v6 != nullptr )
        ((void (__fastcall *)(idThread *, int))v6->dtr_idClass)(a1: v6, a2: 1);
      return v14;
    }
  }
  decl = this->decl;
  if ( decl != nullptr )
  {
    useSound = decl->useSound;
    if ( useSound != nullptr )
      idEntity::StartSoundShader(
        this: user,
        channel: SND_CHANNEL_ITEM,
        shader: useSound,
        soundShaderFlags: (soundShaderFlags_t)0,
        peerMask: 0);
  }
  v18 = this->decl;
  v19 = &v18->recipe->__vftable;
  if ( v19 == nullptr )
  {
    if ( !v18->dropable )
    {
      if ( v18->equipWeaponOnUse != nullptr && gameLocal->world->mapType != MAPTYPE_TOWN )
      {
        v49 = idPlayer::CastTo(c: user);
        v50 = &v49->__vftable;
        if ( v49 != nullptr && v49->GetInventory_2(this: v49) != nullptr )
        {
          v51 = v50[122];
          if ( v51 != 0 && (*(int (__fastcall **)(int))(*(_DWORD *)v51 + 104))(a1: v51) != 0 )
          {
            v52 = v50[122];
            v53 = v52 != 0 ? (*(int (__fastcall **)(int))(*(_DWORD *)v52 + 104))(a1: v52) : 0;
            if ( v53 != -37616 )
            {
              equipWeaponOnUse = this->decl->equipWeaponOnUse;
              v55 = (idJobManager *)(*(int (__fastcall **)(_DWORD *))(*v50 + 468))(a1: v50);
              JobByDecl = idJobManager::FindJobByDecl(this: v55, jobDecl: (const idDeclJob *)equipWeaponOnUse);
              v57 = v50[122];
              v58 = (idWeapon *)JobByDecl;
              v59 = v57 != 0 ? (*(int (__fastcall **)(_DWORD))(*(_DWORD *)v57 + 104))(a1: v50[122]) : 0;
              if ( v58 != nullptr )
              {
                v60 = idWeapon::CastTo(c: v58);
                if ( v60 != nullptr )
                {
                  idHands::SelectWeapon(
                    this: (idHands *)(v59 + 37616),
                    slot: EQUIP_RIGHT_HAND,
                    weapon: v60,
                    useIntroBringUp: false);
                  return 1;
                }
              }
            }
          }
        }
      }
      return 0;
    }
    if ( v18->isWeapon && gameLocal->world->mapType == MAPTYPE_TOWN )
      return 0;
    v45 = idPlayer::CastTo(c: user);
    v46 = v45;
    if ( this->decl->droppedBot )
    {
      if ( v45 == nullptr )
      {
LABEL_47:
        v47 = user->DropItem(this: user, a2: this, a3: 1, a4: 0, a5: 1, a6: &vec3_origin, a7: &vec3_origin);
        v48 = v47;
        if ( v47 != nullptr )
        {
          if ( this->decl->droppedBot && v46 != nullptr )
            idPlayer::AddDroppableInfo(this: v46, ent: v47);
          v48->Dropped(this: v48, a2: user, a3: this->decl);
          return 1;
        }
        idLib::Warning(fmt: "Failed to drop item");
        return 0;
      }
      if ( !idPlayer::CanAddDroppable(this: v45) )
        return 0;
    }
    if ( v46 != nullptr && (unsigned __int8)idPlayer::IsOnLadder(this: v46) != 0 )
      return 0;
    goto LABEL_47;
  }
  v20 = v19[23];
  v21 = 0;
  if ( v20 > 0 )
  {
    v22 = 0;
    do
    {
      if ( v21 >= 0 && v21 <= v20 )
      {
        v23 = v19[22] + v22;
        if ( v23 != 0 )
        {
          v24 = *(const idDeclInventory **)v23;
          v25 = user->GetInventory_2(this: user);
          if ( idInventoryCollection::FindTotalInventoryItemCount(this: v25, decl: v24) < *(_DWORD *)(v23 + 4) )
            return 0;
        }
      }
      v20 = v19[23];
      ++v21;
      v22 += 12;
    }
    while ( v21 < v20 );
  }
  v26 = 0;
  if ( v20 > 0 )
  {
    v27 = 0;
    do
    {
      if ( v26 >= 0 && v26 <= v20 )
      {
        v28 = v19[22] + v27;
        if ( v28 != 0 && *(_BYTE *)(v28 + 8) != 0 )
        {
          presentable = user->presentable;
          if ( presentable == nullptr )
          {
            idEntity::InitPresentableInternal(this: user);
            presentable = user->presentable;
          }
          v30 = *(_DWORD *)(v28 + 4);
          v31 = *(const idDeclInventory **)v28;
          v32 = user->GetInventory_2(this: user);
          idInventoryCollection::DeleteInventoryItem(this: v32, owner: presentable, decl: v31, count: v30);
        }
      }
      v20 = v19[23];
      ++v26;
      v27 += 12;
    }
    while ( v26 < v20 );
  }
  v33 = v19[18];
  v34 = v19[19] - v33;
  if ( v19[19] == v33 )
  {
    v35 = 0;
  }
  else
  {
    seed = clientGame->random.seed;
    __twllei(v34, 0);
    v37 = 1664525 * seed + 1013904223;
    clientGame->random.seed = v37;
    v38 = (v37 >> 10) & 0x7FFF;
    v39 = v34 & ~(__ROL4__(v38, 1) - 1);
    v35 = v38 % v34;
    __twlgei(v39, 0xFFFFFFFF);
  }
  v40 = v35 + v33;
  v41 = (const idDeclJob *)v19[16];
  if ( user->presentable == nullptr )
    idEntity::InitPresentableInternal(this: user);
  v42 = user->presentable;
  v43 = user->GetInventory_2(this: user);
  idInventoryCollection::GiveItem(this: v43, owner: v42, decl: v41, count: v40, forceCount: false, canIntro: false);
  v44 = idPlayer::CastTo(c: user);
  if ( v44 != nullptr )
    idRageMetrics::EngineeredItem(this: clientGame->rageMetrics, player: (idVehicle *)v44);
  return 1;
}


// ========================================================================
// __unwind$510718
// EA  : 0x82EC7710
// RVA : 0x00EC7710
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __fastcall _unwind_510718(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 4272 + 80), tag: a2);
}


// ========================================================================
// ?OnEquip@idWeapon@@UAAXPBVidPresentable@@PAVidFXManager@@@Z
// EA  : 0x82EC7798
// RVA : 0x00EC7798
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __fastcall idWeapon::OnEquip(idWeapon *this, const idPresentable *owner, idFXManager *fxMgr)
{
  idAmmoItem *ammoClip; // r3
  __int32 FXExtraCondition; // r3
  unsigned int v7; // r6
  unsigned int GameMs; // r24
  idPresentable *v9; // r26
  __int32 v10; // r3
  int v11; // r3
  idPresentablePtr<idPresentable> *p_presentableWeapon; // r30
  int v13; // r31
  idPresentable *v14; // r3

  if ( fxMgr != nullptr )
  {
    ammoClip = this->ammoClip;
    if ( ammoClip != nullptr && ammoClip->GetCount(this: ammoClip) > 0 )
    {
      idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      FXExtraCondition = idWeapon::GetFXExtraCondition(this, secondary: false);
      idFXManager::StartFX(
        this: fxMgr,
        org: &vec3_origin,
        axis: &mat3_identity,
        time: v7,
        startCondition: 65,
        extraCond: FXExtraCondition);
      if ( idPresentablePtr<idPresentableProjectile>::operator->(this: (idPresentablePtr<idPresentable> *)&this->presentableWeapon) != nullptr
        && fxMgr != &idPresentablePtr<idPresentableProjectile>::operator->(this: (idPresentablePtr<idPresentable> *)&this->presentableWeapon)->fxManager )
      {
        GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        v9 = idPresentablePtr<idPresentableProjectile>::operator->(this: (idPresentablePtr<idPresentable> *)&this->presentableWeapon);
        v10 = idWeapon::GetFXExtraCondition(this, secondary: false);
        idFXManager::StartFX(
          this: &v9->fxManager,
          org: &vec3_origin,
          axis: &mat3_identity,
          time: GameMs,
          startCondition: 65,
          extraCond: v10);
      }
    }
  }
  if ( (*((_BYTE *)this + 452) & 2) != 0 )
  {
    idWeapon::ShowLaserSight(this);
    if ( fxMgr != nullptr )
    {
      v11 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      idFXManager::StartFX(this: fxMgr, org: &vec3_origin, axis: &mat3_identity, time: v11, startCondition: 83);
      p_presentableWeapon = (idPresentablePtr<idPresentable> *)&this->presentableWeapon;
      if ( idPresentablePtr<idPresentableProjectile>::operator->(this: p_presentableWeapon) != nullptr
        && fxMgr != &idPresentablePtr<idPresentableProjectile>::operator->(this: p_presentableWeapon)->fxManager )
      {
        v13 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        v14 = idPresentablePtr<idPresentableProjectile>::operator->(this: p_presentableWeapon);
        idFXManager::StartFX(
          this: &v14->fxManager,
          org: &vec3_origin,
          axis: &mat3_identity,
          time: v13,
          startCondition: 83);
      }
    }
  }
}


// ========================================================================
// ?StopAllFX@idWeapon@@QAAXPAVidFXManager@@@Z
// EA  : 0x82EC7948
// RVA : 0x00EC7948
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __fastcall idWeapon::StopAllFX(idWeapon *this, idFXManager *fxMgr)
{
  int GameMs; // r3
  int v5; // r26
  idPresentable *v6; // r3
  int v7; // r3
  int v8; // r31
  idPresentable *v9; // r3

  if ( (*((_BYTE *)this + 452) & 2) != 0 )
  {
    idWeapon::HideLaserSight(this);
    if ( fxMgr == nullptr )
      return;
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    idFXManager::StopFX(this: fxMgr, time: GameMs, stopCondition: 84, immediateStop: false);
    if ( idPresentablePtr<idPresentableProjectile>::operator->(this: (idPresentablePtr<idPresentable> *)&this->presentableWeapon) != nullptr
      && fxMgr != &idPresentablePtr<idPresentableProjectile>::operator->(this: (idPresentablePtr<idPresentable> *)&this->presentableWeapon)->fxManager )
    {
      v5 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      v6 = idPresentablePtr<idPresentableProjectile>::operator->(this: (idPresentablePtr<idPresentable> *)&this->presentableWeapon);
      idFXManager::StopFX(this: &v6->fxManager, time: v5, stopCondition: 84, immediateStop: false);
    }
  }
  if ( fxMgr != nullptr )
  {
    v7 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    idFXManager::StopAllFX(this: fxMgr, time: v7, immediateStop: true);
    if ( idPresentablePtr<idPresentableProjectile>::operator->(this: (idPresentablePtr<idPresentable> *)&this->presentableWeapon) != nullptr
      && fxMgr != &idPresentablePtr<idPresentableProjectile>::operator->(this: (idPresentablePtr<idPresentable> *)&this->presentableWeapon)->fxManager )
    {
      v8 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      v9 = idPresentablePtr<idPresentableProjectile>::operator->(this: (idPresentablePtr<idPresentable> *)&this->presentableWeapon);
      idFXManager::StopAllFX(this: &v9->fxManager, time: v8, immediateStop: true);
    }
  }
}


// ========================================================================
// ?ReleaseTrigger@idWeapon@@UAAXPAVidActor@@@Z
// EA  : 0x82EC7A88
// RVA : 0x00EC7A88
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __fastcall idWeapon::ReleaseTrigger(idWeapon *this, idPlayer *user)
{
  idPlayer *v3; // r3
  idPresentable *presentable; // r3
  idPresentablePlayer *v5; // r3

  if ( this->triggerState != TRIGGERSTATE_RELEASED )
  {
    this->triggerState = TRIGGERSTATE_RELEASED;
    idWeapon::StopLoopingFireSound(this);
    v3 = idPlayer::CastTo(c: user);
    if ( v3 != nullptr )
    {
      presentable = v3->presentable;
      if ( presentable != nullptr )
        v5 = presentable->GetPlayerInterface_2(this: presentable);
      else
        v5 = nullptr;
      idPresentablePlayer::ReleaseWeaponKickRecoveryDelay(this: v5);
    }
  }
}


// ========================================================================
// ?UpdateState@idWeapon@@QAAXPAVidInventoryCollection@@_N@Z
// EA  : 0x82EC7B00
// RVA : 0x00EC7B00
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __fastcall idWeapon::UpdateState(idWeapon *this, idJobManager *inventory, BOOL secondaryAmmo)
{
  idAmmoItem *ammoClipSecondary; // r11
  const idDeclAmmo *decl; // r30

  if ( this->triggerState == TRIGGERSTATE_PULLED && this->fireState == FIRESTATE_IDLE && idWeapon::IsReadyToFire(this) )
  {
    if ( this->NeedsReload(this, a2: secondaryAmmo) )
    {
      if ( secondaryAmmo )
        ammoClipSecondary = this->ammoClipSecondary;
      else
        ammoClipSecondary = this->ammoClip;
      if ( ammoClipSecondary != nullptr )
        decl = (const idDeclAmmo *)ammoClipSecondary->decl;
      else
        decl = nullptr;
      if ( decl != nullptr
        && (unsigned __int8)idWeapon::CanReload(this, inventory, ammoDecl: (const idDeclJob *)decl, secondaryAmmo) != 0 )
      {
        idWeapon::BeginReloading(this, ammoDecl: decl, secondaryAmmo);
        return;
      }
    }
    else if ( this->burstCount <= 0 )
    {
      return;
    }
    this->fireState = (_cntlzw((unsigned __int8)idWeapon::IsMelee(this)) & 0x20) != 0;
    idWeapon::UpdateAttackType(this);
  }
}


// ========================================================================
// ?OnEquip@idLaserCutter@@UAAXPBVidPresentable@@PAVidFXManager@@@Z
// EA  : 0x82EC7C68
// RVA : 0x00EC7C68
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __fastcall idLaserCutter::OnEquip(idLaserCutter *this, const idPresentable *owner, idFXManager *fxMgr)
{
  idAmmoItem *ammoClipSecondary; // r11
  __int64 v5; // r10
  __int64 v6; // r11
  idPlayer *Player; // r31
  idPresentable *presentable; // r3
  int v9; // r3
  idPresentable *v10; // r3
  eventVoid *v11; // r3
  idHands::setRestStateType_t v12; // r6
  idPresentable *v13; // r3
  char v14; // [sp+50h] [-50h] BYREF
  __int64 v15; // [sp+58h] [-48h] BYREF
  float v16[2]; // [sp+60h] [-40h] BYREF
  const idTypeInfo *v17[2]; // [sp+68h] [-38h] BYREF
  idVec3 v18[2]; // [sp+70h] [-30h] BYREF

  idWeapon::OnEquip(this, owner, fxMgr);
  if ( this->weaponState == WEAPONSTATE_SECONDARY )
  {
    ammoClipSecondary = this->ammoClipSecondary;
    HIDWORD(v5) = &idInfoNavFlightVolume::Type;
    v17[0] = &idCuttable::Type;
    v17[1] = &idFuncChain::Type;
    if ( ammoClipSecondary != nullptr )
    {
      HIDWORD(v5) = ammoClipSecondary->decl[1].__vftable;
      LODWORD(v5) = *(_DWORD *)(HIDWORD(v5) + 468);
    }
    else
    {
      LODWORD(v5) = 0;
    }
    LODWORD(v16[1]) = v5;
    v16[0] = (float)v5;
    if ( ammoClipSecondary != nullptr )
      LODWORD(v6) = ammoClipSecondary->decl[1].__vftable[7].GetDeclTimestamp;
    else
      LODWORD(v6) = 0;
    HIDWORD(v6) = &idEventDef::eventDefList[3154];
    v15 = (unsigned int)v6;
    v16[1] = (float)v6;
    Player = idGameLocal::GetPlayer(this: gameLocal, i: 0);
    presentable = Player->presentable;
    if ( presentable != nullptr )
      v9 = (int)presentable->GetPlayerInterface_2(this: presentable);
    else
      v9 = 0;
    if ( idFocusTracker::GetValidTraceResultFocusEntity(
           this: (idFocusTracker *)(v9 + 47160),
           includeBoundCheck: true,
           checkTypes: v17,
           numCheckTypes: 2,
           maxRanges: v16,
           resultEndPos: v18,
           resultID: (int *)&v15) != nullptr
      || (this->availableFunctionalityLenses & 1) != 0 )
    {
      this->lastOkToCutTime = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      v13 = Player->presentable;
      if ( v13 != nullptr )
        v11 = (eventVoid *)v13->GetPlayerInterface_2(this: v13);
      else
        v11 = nullptr;
      v12 = SET_RESTSTATE_COMBAT;
    }
    else
    {
      v10 = Player->presentable;
      if ( v10 != nullptr )
        v11 = (eventVoid *)v10->GetPlayerInterface_2(this: v10);
      else
        v11 = nullptr;
      v12 = SET_RESTSTATE_REST;
    }
    idHands::AnimEvent_SetWeaponRelaxed(this: (idHands *)&v14, result: v11 + 37616, anim: nullptr, setType: v12);
  }
}


// ========================================================================
// ?GetDamagePercentInt@idVehicleKey@@QBAHXZ
// EA  : 0x82EC7E30
// RVA : 0x00EC7E30
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

int __fastcall idVehicleKey::GetDamagePercentInt(idVehicleKey *this)
{
  return (int)(float)(idVehicleKey::GetDamagePercent(this) * (float)100.0);
}


// ========================================================================
// ?ClearGarageBayReference@idVehicleKey@@QAAXXZ
// EA  : 0x82EC81A8
// RVA : 0x00EC81A8
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __fastcall idVehicleKey::ClearGarageBayReference(idVehicleKey *this)
{
  int value; // r10
  idEntity *v3; // r3
  idInfoGarageBay *v4; // r3
  idInfoGarageBay *v5; // r3

  value = this->garageBay.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
  {
    v3 = gameLocal->entities.ptr[value & 0x1FFF];
    if ( v3 != nullptr )
      v4 = (idInfoGarageBay *)idEntity::CastTo(c: v3);
    else
      v4 = nullptr;
    v5 = idInfoGarageBay::CastTo(c: v4);
    if ( v5 != nullptr )
      v5->vehicle.spawnId.value = 0x1FFF;
    this->garageBay.spawnId.value = 0x1FFF;
  }
}


// ========================================================================
// ?EquipUpgrade@idVehicleKey@@QAAXPBVidDeclVehicleUpgrade@@_N@Z
// EA  : 0x82EC8248
// RVA : 0x00EC8248
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __fastcall idVehicleKey::EquipUpgrade(
        idVehicleKey *this,
        const idDeclVehicleUpgrade *upgrade,
        const bool init,
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
        const idDeclVehicleUpgrade *a14)
{
  int num; // r9
  char v15; // r6
  int v16; // r10
  const idDeclVehicleUpgrade **list; // r8
  int v18; // r11

  a14 = upgrade;
  if ( upgrade != nullptr )
  {
    num = this->equippedUpgrades.num;
    v15 = 0;
    v16 = 0;
    if ( num > 0 )
    {
      list = this->equippedUpgrades.list;
      v18 = 0;
      while ( list[v18]->upgradeType != upgrade->upgradeType )
      {
        ++v16;
        ++v18;
        if ( v16 >= num )
          goto LABEL_10;
      }
      if ( !init )
        list[v16] = upgrade;
      v15 = 1;
    }
LABEL_10:
    if ( v15 == 0 )
    {
      if ( init )
        idList<idAnimWebBlendTree *,5>::Append(
          this: (idList<enum encounterGroupRole_t,5> *)&this->equippedUpgrades,
          obj: (encounterGroupRole_t *)&a14);
      else
        idLib::Warning(fmt: "Vehicle upgrade type not found in equipped list.");
    }
  }
}


// ========================================================================
// ?Hide@idWeapon@@UAAXXZ
// EA  : 0x82EC88A0
// RVA : 0x00EC88A0
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __fastcall idWeapon::Hide(idWeapon *this)
{
  idPieceEmitter *pieceEmitterEntity; // r11

  idWeapon::HideLaserSight(this);
  idWeapon::StopLoopingFireSound(this);
  if ( (*((_BYTE *)this + 452) & 2) != 0 )
    idWeapon::HideLaserSight(this);
  pieceEmitterEntity = this->pieceEmitterEntity;
  if ( pieceEmitterEntity != nullptr )
    ((void (*)(void))pieceEmitterEntity->Hide_2)();
}


// ========================================================================
// ?OnUnequip@idWeapon@@UAAXPBVidPresentable@@PAVidFXManager@@@Z
// EA  : 0x82EC8910
// RVA : 0x00EC8910
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __fastcall idWeapon::OnUnequip(idWeapon *this, const idPresentable *owner, idFXManager *fxMgr)
{
  idWeapon::StopAllFX(this, fxMgr);
  this->Hide(this);
}


// ========================================================================
// ?OnUnequip@idLaserCutter@@UAAXPBVidPresentable@@PAVidFXManager@@@Z
// EA  : 0x82EC8958
// RVA : 0x00EC8958
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __fastcall idLaserCutter::OnUnequip(idLaserCutter *this, const idPresentable *owner, idFXManager *fxMgr)
{
  int GameMs; // r3
  int v5; // r3
  int v6; // r3
  int v7; // r3

  idWeapon::StopAllFX(this, fxMgr);
  this->Hide(this);
  idLaserSight::Hide(this: &this->laserBeamCut);
  idLaserSight::Hide(this: &this->laserBeamCutBounce);
  idLaserSight::Hide(this: &this->laserBeamShoot);
  idLaserSight::Hide(this: &this->laserBeamShootBounce);
  idLaserSight::Hide(this: &this->laserBeamShootIndication);
  idLaserSight::Hide(this: &this->laserBeamShootBounceIndication);
  if ( this->beamModelFPView != nullptr )
  {
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    idRenderModelBeam::Update(this: this->beamModelFPView, currTime: GameMs);
  }
  if ( this->beamModelWorldView != nullptr )
  {
    v5 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    idRenderModelBeam::Update(this: this->beamModelWorldView, currTime: v5);
  }
  if ( this->decalModelFPView != nullptr )
  {
    v6 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    idRenderModelDecal::Update(this: this->decalModelFPView, currTime: v6);
  }
  if ( this->decalModelworldView != nullptr )
  {
    v7 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    idRenderModelDecal::Update(this: this->decalModelworldView, currTime: v7);
  }
}


// ========================================================================
// ?SaveVehicleArmor@idVehicleKey@@QAAXPBVidVehicle@@@Z
// EA  : 0x82EC8A68
// RVA : 0x00EC8A68
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __fastcall idVehicleKey::SaveVehicleArmor(idVehicleKey *this, const idVehicle *vehicle)
{
  idStaticList<idVehicleKey::armorInfo_t,50> *p_armorInfo; // r25
  int v4; // r28
  bfx::Planner3D *v5; // r3
  idInventoryCollection *v6; // r3
  idInventoryItem *InventoryItem; // r31
  int (__fastcall *GetCount)(idInventoryItem *); // ctr
  __int64 v9; // r8
  bfx::Planner3D *v10; // r3
  idVehicleKey::armorInfo_t v11[10]; // [sp+50h] [-50h] BYREF

  if ( vehicle != nullptr )
  {
    p_armorInfo = &this->armorInfo;
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->armorInfo);
    v4 = 0;
    v5 = (bfx::Planner3D *)vehicle->GetInventory(this: vehicle);
    if ( (int)idScriptObject::GetTypeDef(this: v5) > 0 )
    {
      do
      {
        v6 = (idInventoryCollection *)vehicle->GetInventory(this: vehicle);
        InventoryItem = idInventoryCollection::GetInventoryItem(this: v6, index: v4);
        if ( _RTDynamicCast(
               inptr: (void *)InventoryItem->decl,
               VfDelta: 0,
               SrcType: &idDeclInventory `RTTI Type Descriptor',
               TargetType: &idDeclVehicleArmorKit `RTTI Type Descriptor',
               isReference: 0) == nullptr
          && _RTDynamicCast(
               inptr: (void *)InventoryItem->decl,
               VfDelta: 0,
               SrcType: &idDeclInventory `RTTI Type Descriptor',
               TargetType: &idDeclVehicleArmor `RTTI Type Descriptor',
               isReference: 0) != nullptr )
        {
          GetCount = InventoryItem->GetCount;
          v11[0].decl = InventoryItem->decl;
          LODWORD(v9) = GetCount(this: InventoryItem);
          v11[1] = (idVehicleKey::armorInfo_t)v9;
          v11[0].health = (float)v9;
          idList<idVehicleKey::armorInfo_t,5>::Append(this: p_armorInfo, obj: v11);
        }
        ++v4;
        v10 = (bfx::Planner3D *)vehicle->GetInventory(this: vehicle);
      }
      while ( v4 < (int)idScriptObject::GetTypeDef(this: v10) );
    }
  }
  else
  {
    idLib::Warning(fmt: "NULL vehicle passed into idVehicleKey::SaveVehicleArmor");
  }
}


// ========================================================================
// ?InternalReadFromFile@idVehicleKey@@AAAXPAVidFile@@_N@Z
// EA  : 0x82EC8BB0
// RVA : 0x00EC8BB0
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __fastcall idVehicleKey::InternalReadFromFile(idVehicleKey *this, idFile *file, bool allocResources)
{
  int i; // r25
  int v7; // r10
  int v8; // r9
  int v9; // r8
  int v10; // r7
  int v11; // r6
  const idDeclVehicleUpgrade *v12; // r4
  int j; // r25
  const idDeclInventory *v14; // r3
  int v15; // [sp+8h] [-F8h]
  int v16; // [sp+Ch] [-F4h]
  int v17; // [sp+10h] [-F0h]
  int v18; // [sp+14h] [-ECh]
  int v19; // [sp+18h] [-E8h]
  const idDeclVehicleUpgrade *v20; // [sp+1Ch] [-E4h]
  _DWORD v21[2]; // [sp+50h] [-B0h] BYREF
  idVehicleKey::armorInfo_t v22; // [sp+58h] [-A8h] BYREF
  idStr v23; // [sp+60h] [-A0h] BYREF
  idStr v24; // [sp+80h] [-80h] BYREF

  file->Read(this: file, a2: &this->health, a3: 4u);
  file->Read(this: file, a2: &this->vehicleGarage, a3: 4u);
  file->Read(this: file, a2: &this->enterVehicle, a3: 1u);
  file->Read(this: file, a2: &this->shouldGarageView, a3: 1u);
  file->Read(this: file, a2: &this->position, a3: 12u);
  file->Read(this: file, a2: &this->orientation, a3: 36u);
  file->Read(this: file, a2: &this->initArmorFromVehicle, a3: 1u);
  file->Read(this: file, a2: &this->currentWeaponGroup, a3: 4u);
  file->Read(this: file, a2: &this->upgradeAvailable, a3: 1u);
  file->Read(this: file, a2: v21, a3: 4u);
  for ( i = 0; i < v21[0]; ++i )
  {
    v23.allocedAndFlag = 20;
    v23.len = 0;
    v23.data = v23.baseBuffer;
    v23.baseBuffer[0] = 0;
    idFile::ReadString(this: file, string: &v23);
    if ( allocResources )
    {
      if ( v23.data != nullptr )
        v12 = (const idDeclVehicleUpgrade *)idDeclInfo::FindWithInheritance(
                                              this: &idDeclVehicleUpgrade::resourceList,
                                              name: v23.data,
                                              makeDefault: false);
      else
        v12 = nullptr;
      idVehicleKey::EquipUpgrade(
        this,
        upgrade: v12,
        init: false,
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
    idStr::FreeData(this: &v23);
  }
  file->Read(this: file, a2: v21, a3: 4u);
  for ( j = 0; j < v21[0]; ++j )
  {
    v22.health = 0.0;
    v22.decl = nullptr;
    v24.allocedAndFlag = 20;
    v24.data = v24.baseBuffer;
    v24.len = 0;
    v24.baseBuffer[0] = 0;
    idFile::ReadString(this: file, string: &v24);
    file->Read(this: file, a2: &v22.health, a3: 4u);
    if ( allocResources )
    {
      if ( v24.data != nullptr )
        v14 = (const idDeclInventory *)idDeclInfo::FindWithInheritance(
                                         this: &idDeclInventory::resourceList,
                                         name: v24.data,
                                         makeDefault: false);
      else
        v14 = nullptr;
      v22.decl = v14;
      idList<idVehicleKey::armorInfo_t,5>::Append(this: &this->armorInfo, obj: &v22);
    }
    idStr::FreeData(this: &v24);
  }
  file->Read(this: file, a2: &this->doTotalRepairOnSpawn, a3: 1u);
  idFile::ReadString(this: file, string: &this->referenceVehicleName);
  file->Read(this: file, a2: &this->numVehicleKills, a3: 4u);
}


// ========================================================================
// __unwind$512083
// EA  : 0x82EC8EA0
// RVA : 0x00EC8EA0
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void _unwind_512083()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 256 + 96));
}


// ========================================================================
// __unwind$512084
// EA  : 0x82EC8EC8
// RVA : 0x00EC8EC8
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void _unwind_512084()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 256 + 128));
}


// ========================================================================
// ?ReadFromFile@idVehicleKey@@QAAXPAVidFile@@@Z
// EA  : 0x82EC8EF0
// RVA : 0x00EC8EF0
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __fastcall idVehicleKey::ReadFromFile(idVehicleKey *this, idFile *file)
{
  idVehicleKey::InternalReadFromFile(this, file, allocResources: true);
}


// ========================================================================
// ?VehicleAftershockerThink@idClientServerInterfaceServer@@UAAXPAVidInventoryItem@@PAVidPresentable@@@Z
// EA  : 0x82EC8EF8
// RVA : 0x00EC8EF8
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __fastcall idClientServerInterfaceServer::VehicleAftershockerThink(
        idClientServerInterfaceServer *this,
        idInventoryItem *item,
        idPresentable *presentable,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        __int64 a17,
        __int64 a18,
        __int64 a19,
        __int64 a20,
        __int64 a21,
        __int64 a22,
        __int64 a23,
        __int64 a24,
        __int64 a25,
        __int64 a26,
        float a27,
        __int64 a28,
        int a29,
        int a30,
        float a31,
        float a32,
        float a33,
        float a34,
        float a35,
        float a36,
        __int64 a37,
        float a38,
        int a39,
        float a40,
        float a41,
        float a42,
        int a43,
        float a44,
        float a45,
        float a46,
        int a47,
        int a48,
        int a49,
        int a50)
{
  __int64 v50; // r4
  unsigned int v51; // r31
  idVehicle_Aftershocker *v52; // r14
  idPresentable *v53; // r5
  idPresentable *v54; // r16
  idVehicleQuickItem *v55; // r3
  idVehicle_Car *v56; // r3
  idVehicle_Car *v57; // r15
  idPhysics *Physics; // r22
  idVehicle_Aftershocker *v59; // r3
  idVehicle_Aftershocker *v60; // r27
  double v61; // fp29
  float *v62; // r3
  __int64 v63; // r3
  double v64; // fp0
  double v65; // fp0
  int EntitiesTouchingBounds; // r3
  int *v67; // r23
  int i; // r18
  idVehicle_Car *v69; // r30
  int v70; // r29
  int v71; // r31
  int value; // r9
  idEntity *v73; // r3
  idEntity *v74; // r3
  idPhysics *v75; // r29
  int v76; // r3
  idPhysics_vtbl *v77; // r9
  float *v78; // r3
  double v79; // fp13
  double v80; // fp10
  double v81; // fp26
  double v82; // fp0
  double v83; // fp26
  double v84; // fp25
  double v85; // fp24
  double v86; // fp23
  idPhysics *v87; // r3
  idPhysics *v88; // r3
  idPhysics *v89; // r3
  idPhysics *v90; // r3
  idVehicle_Car *v91; // r3
  const idDeclDamage *collisionDeathDecl; // r4
  int valueInteger; // r11
  const idEntity *entity; // r6

  v50 = ((__int64 (*)(void))RtlCheckStack12)();
  v51 = HIDWORD(v50);
  STACK[0x10354] = HIDWORD(v50);
  v52 = (idVehicle_Aftershocker *)v50;
  v54 = v53;
  v55 = idVehicleQuickItem::CastTo(c: (idVehicleQuickItem *)v50);
  if ( v55 != nullptr && v55->active )
  {
    v56 = idVehicle_Car::CastTo(c: *(idVehicle_Car **)(v51 + 4));
    v57 = v56;
    if ( v56 != nullptr )
    {
      Physics = idEntity::GetPhysics(this: v56);
      if ( Physics != nullptr )
      {
        v59 = idVehicle_Aftershocker::CastTo(c: v52);
        v60 = v59;
        if ( v59 != nullptr )
        {
          v61 = *(float *)(v59->decl[1].trackedMemory + 200);
          v62 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
          a31 = *v62;
          a32 = v62[1];
          a33 = v62[2];
          a34 = *v62;
          a35 = v62[1];
          a36 = v62[2];
          LODWORD(v63) = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED)
                       - v60->activateTime;
          a28 = v63;
          v64 = (float)((float)v63 / vehicle_aftershockerDuration.valueFloat);
          if ( v64 >= 0.0 )
          {
            if ( v64 > 1.0 )
              v64 = 1.0;
          }
          else
          {
            v64 = 0.0;
          }
          v65 = (float)((float)v64 * (float)v61);
          a31 = a31 - (float)v65;
          a32 = a32 - (float)v65;
          a33 = a33 - (float)v65;
          a34 = a34 + (float)v65;
          a35 = a35 + (float)v65;
          a36 = a36 + (float)v65;
          EntitiesTouchingBounds = idClip::GetEntitiesTouchingBounds(
                                     this: &clientGame->clip,
                                     bounds: (const idBounds *)&a31,
                                     clipMask: 196608,
                                     entityList: &a50,
                                     maxCount: 0x2000);
          if ( EntitiesTouchingBounds > 0 )
          {
            v67 = &a50;
            for ( i = EntitiesTouchingBounds; i != 0; --i )
            {
              v69 = (idVehicle_Car *)gameLocal->GetEntity(this: gameLocal, a2: *v67);
              if ( v69 != v57 )
              {
                v70 = 0;
                if ( v60->damagedEntList.num > 0 )
                {
                  v71 = 0;
                  do
                  {
                    value = v60->damagedEntList.list[v71].spawnId.value;
                    if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
                      && (v73 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
                    {
                      v74 = idEntity::CastTo(c: v73);
                    }
                    else
                    {
                      v74 = nullptr;
                    }
                    if ( v74 == v69 )
                      break;
                    ++v70;
                    ++v71;
                  }
                  while ( v70 < v60->damagedEntList.num );
                  v51 = STACK[0x10354];
                }
                if ( v70 >= v60->damagedEntList.num )
                {
                  v75 = idEntity::GetPhysics(this: v69);
                  v76 = (int)Physics->GetOrigin(this: Physics, a2: 0);
                  v77 = v75->__vftable;
                  HIDWORD(a28) = v76;
                  v78 = (float *)v77->GetOrigin(this: v75, a2: 0);
                  v79 = *(float *)(HIDWORD(a28) + 4);
                  v80 = v78[1];
                  *(float *)&a26 = *v78 - *(float *)HIDWORD(a28);
                  *((float *)&a26 + 1) = (float)v80 - (float)v79;
                  a27 = v78[2] - *(float *)(HIDWORD(a28) + 8);
                  v81 = idVec3::NormalizeFast(this: (idVec3 *)&a26);
                  a38 = 0.0;
                  a37 = a26;
                  idVec3::NormalizeFast(this: (idVec3 *)&a37);
                  a27 = (float)(a27 + (float)1.0) * (float)0.5;
                  idVec3::NormalizeFast(this: (idVec3 *)&a26);
                  v82 = (float)((float)v81 / (float)((float)v61 * (float)1.5));
                  if ( v82 >= 0.0 )
                  {
                    if ( v82 > 1.0 )
                      v82 = 1.0;
                  }
                  else
                  {
                    v82 = 0.0;
                  }
                  v83 = (float)((float)1.0 - (float)v82);
                  v84 = (float)((float)(*(float *)&a26 * (float)((float)1.0 - (float)v82))
                              * vehicle_aftershockerMaxVelocity.valueFloat);
                  v85 = (float)((float)(*((float *)&a26 + 1) * (float)((float)1.0 - (float)v82))
                              * vehicle_aftershockerMaxVelocity.valueFloat);
                  v86 = (float)((float)(a27 * (float)((float)1.0 - (float)v82))
                              * vehicle_aftershockerMaxVelocity.valueFloat);
                  v87 = idEntity::GetPhysics(this: v69);
                  v87->GetLinearVelocity(this: (idPhysics *)&a40, result: (idVec3 *)v87, a3: 0);
                  a40 = (float)v84 + a40;
                  a41 = a41 + (float)v85;
                  a42 = a42 + (float)v86;
                  v88 = idEntity::GetPhysics(this: v69);
                  v88->SetLinearVelocity(this: v88, a2: (const idVec3 *)&a40, a3: 0);
                  v89 = idEntity::GetPhysics(this: v69);
                  v89->GetAngularVelocity(this: (idPhysics *)&a44, result: (idVec3 *)v89, a3: 0);
                  a44 = a44
                      - (float)((float)((float)((float)(*((float *)&a37 + 1) * vec3_up.z) - (float)(vec3_up.y * a38))
                                      * (float)v83)
                              * vehicle_aftershockerMaxAngularVelocity.valueFloat);
                  a45 = a45
                      - (float)((float)((float)((float)(vec3_up.x * a38) - (float)(*(float *)&a37 * vec3_up.z))
                                      * (float)v83)
                              * vehicle_aftershockerMaxAngularVelocity.valueFloat);
                  a46 = a46
                      - (float)((float)((float)((float)(*(float *)&a37 * vec3_up.y)
                                              - (float)(*((float *)&a37 + 1) * vec3_up.x))
                                      * (float)v83)
                              * vehicle_aftershockerMaxAngularVelocity.valueFloat);
                  v90 = idEntity::GetPhysics(this: v69);
                  v90->SetAngularVelocity(this: v90, a2: (const idVec3 *)&a44, a3: 0);
                  if ( v69 != nullptr )
                    HIDWORD(a28) = (gameLocal->spawnIds.ptr[v69->entityNumber] << 13) | v69->entityNumber;
                  else
                    HIDWORD(a28) = 0x1FFF;
                  idList<idEntityPtr<idEntity>,58>::Append(
                    this: (idList<idEntityPtr<idEntity>,58> *)&v60->damagedEntList,
                    obj: (const idEntityPtr<idEntity> *)&a28);
                  v91 = idVehicle_Car::CastTo(c: v69);
                  if ( v91 != nullptr )
                  {
                    collisionDeathDecl = v91->damages.collisionDeathDecl;
                    if ( collisionDeathDecl != nullptr )
                    {
                      valueInteger = vehicle_aftershockerDuration.valueInteger;
                      if ( 2 * valueInteger >= valueInteger )
                      {
                        valueInteger = 1000;
                        if ( 2 * vehicle_aftershockerDuration.valueInteger <= 1000 )
                          valueInteger = 2 * vehicle_aftershockerDuration.valueInteger;
                      }
                      entity = nullptr;
                      if ( v54 != nullptr )
                        entity = v54->entity;
                      idVehicle::SetCollisionDamage(
                        this: v91,
                        decl: collisionDeathDecl,
                        delayMS: valueInteger,
                        attacker: entity);
                    }
                  }
                }
              }
              ++v67;
            }
          }
          idClientServerInterfaceClient::VehicleAftershockerThink(
            this: (idClientServerInterfaceClient *)v51,
            item: v52,
            presentable: v54);
          v60->lastThinkTime = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        }
      }
    }
  }
}


// ========================================================================
// ?GetPickupHudInfo@idInventoryItem@@UAAXPBVidEntity@@PAVidPickupHudInfo@@@Z
// EA  : 0x82EC94C0
// RVA : 0x00EC94C0
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __fastcall idInventoryItem::GetPickupHudInfo(idInventoryItem *this, const idEntity *user, idPickupHudInfo *info)
{
  idPickupHudInfo::item_t *v4; // r30

  v4 = idList<idPickupHudInfo::item_t,5>::Alloc(this: &info->items);
  v4->icon = this->decl->icon;
  v4->count = this->GetCount(this);
  v4->canPickup = true;
}


// ========================================================================
// ?GetPickupHudInfo@idHealthItem@@UAAXPBVidEntity@@PAVidPickupHudInfo@@@Z
// EA  : 0x82EC9528
// RVA : 0x00EC9528
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __fastcall idHealthItem::GetPickupHudInfo(idHealthItem *this, const idEntity *user, idPickupHudInfo *info)
{
  idPickupHudInfo::item_t *v6; // r28
  idHealthItem *v7; // r3
  int num; // r11
  idPickupHudInfo::item_t *v9; // r31

  v6 = idList<idPickupHudInfo::item_t,5>::Alloc(this: &info->items);
  v6->icon = this->decl->icon;
  v6->count = this->GetCount(this);
  v6->canPickup = true;
  v7 = this;
  num = info->items.num;
  info->items.list[num - 1].count = (int)*(float *)&this->decl[1].__vftable;
  v9 = &info->items.list[num];
  v9[-1].canPickup = idHealthItem::CanUseForHealth(this: v7, user);
}


// ========================================================================
// ?PlayFireSound@idWeapon@@QAAXPAVidPresentable@@PBV2@ABVidVec3@@PBVidDeclProjectile@@_N@Z
// EA  : 0x82EC95D0
// RVA : 0x00EC95D0
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idWeapon::PlayFireSound(
        idWeapon *this,
        idPresentable *attacker,
        const idPresentable *target,
        const idVec3 *start,
        const idDeclProjectile *projDef,
        bool secondaryAmmo)
{
  const idPresentable *v8; // r17
  idAmmoItem *ammoClipSecondary; // r30
  unsigned __int64 v12; // r6
  const char *v13; // r7
  unsigned int v14; // r3
  const idDeclInventory *decl; // r25
  const idSoundShader *lastShotSound; // r30
  bool v17; // r29
  const idSoundShader *onlineLastShotSound; // r24
  int num; // r11
  idList<projectileEnvSound,5> *p_envLastShotSound; // r28
  idList<projectileEnvSound,5> *p_envOnlineLastShotSound; // r26
  BOOL v22; // r27
  bool v23; // r3
  int size; // r21
  const idDeclAiEvent *fadeDelay_low; // r25
  unsigned __int64 v26; // r6
  const char *v27; // r7
  idList<projectileEnvSound,5> *v28; // r24
  idPresentablePlayer *v29; // r3
  soundChannel_t v30; // r21
  projectileEnvSound *list; // r26
  idSoundWorld *soundWorld; // r30
  idSoundWorld_vtbl *v33; // r29
  int v34; // r3
  int v35; // r6
  int v36; // r4
  projectileEnvSound *v37; // r30
  int v38; // r7
  signed int v39; // r11
  int v40; // r7
  int v41; // r6
  char v42; // r17
  int sound2; // r8
  int sound0; // r11
  equipSlot_t equipSlot; // r7
  int v46; // r28
  int loopInterVal; // r27
  int v48; // r3
  int v49; // r29
  int GameMs; // r30
  __int64 v51; // r5
  __int64 v52; // r3
  __int64 v53; // r11
  int GameMsPerFrame; // r30
  int v55; // r30
  int v56; // r3
  int v57; // r10
  idEntity *entity; // r3
  int v59; // r8 OVERLAPPED
  __int128 v60; // r7 OVERLAPPED
  __int128 v61; // r7
  unsigned __int64 v62; // r11
  bool skipEndSoundOnEarlyRelease; // r8
  int v64; // r27
  int *p_hashSize; // r26
  int v66; // r29
  soundChannel_t fireChannel; // r30
  __int128 v68; // r7 OVERLAPPED
  idEntityPtr<idEntity> *v69; // r8
  idPresentablePlayer *v70; // r3
  soundChannel_t v71; // r4
  int v72; // r11
  idActor *User; // r30
  idProp_WeaponStatic *v74; // r3
  idProp_WeaponStatic *v75; // r29
  const idEntity *v76; // r29
  int v77; // r3
  __int64 v78; // [sp+8h] [-398h]
  __int64 v79; // [sp+10h] [-390h]
  __int64 v80; // [sp+18h] [-388h]
  __int64 v81; // [sp+20h] [-380h]
  __int64 v82; // [sp+28h] [-378h]
  __int64 v83; // [sp+30h] [-370h]
  __int64 v84; // [sp+38h] [-368h]
  __int64 v85; // [sp+40h] [-360h]
  __int64 v86; // [sp+48h] [-358h]
  __int64 v87; // [sp+50h] [-350h]
  __int64 v88; // [sp+58h] [-348h]
  idAIEventManager v89; // [sp+70h] [-330h] BYREF
  int v90; // [sp+C0h] [-2E0h]
  soundChannel_t v91; // [sp+C4h] [-2DCh]
  __int64 v92; // [sp+C8h] [-2D8h]
  float v93[12]; // [sp+E0h] [-2C0h] BYREF
  int v94; // [sp+110h] [-290h]
  float v95; // [sp+114h] [-28Ch]
  float v96; // [sp+118h] [-288h]
  idPLogScope v97[2]; // [sp+120h] [-280h] BYREF
  soundShaderParms_t v98; // [sp+130h] [-270h] BYREF
  soundShaderParms_t v99; // [sp+1D0h] [-1D0h] BYREF
  soundShaderParms_t v100[2]; // [sp+270h] [-130h] BYREF

  v8 = target;
  if ( secondaryAmmo )
    ammoClipSecondary = this->ammoClipSecondary;
  else
    ammoClipSecondary = this->ammoClip;
  RD_EventBegin(name: "idWeapon::PlayFireSound");
  LODWORD(v12) = "idWeapon::PlayFireSound";
  HIDWORD(v12) = 2;
  idPLogScope::idPLogScope(this: (idPLogScope *)&v89.eventHash, pl: &pLog, gMask: v12, label: v13);
  v14 = ammoClipSecondary->GetCount(this: ammoClipSecondary);
  decl = this->decl;
  lastShotSound = nullptr;
  v17 = (_cntlzw(v14) & 0x20) != 0;
  onlineLastShotSound = nullptr;
  if ( projDef != nullptr && decl != nullptr )
  {
    num = projDef->envFireSounds.num;
    p_envLastShotSound = nullptr;
    p_envOnlineLastShotSound = nullptr;
    v22 = num != 0;
    if ( num == 0 || (v23 = true, projDef->fireSound == nullptr) )
      v23 = false;
    idLib::WarningIf(
      condition: v23,
      fmt: "projectile %s has both old style and env aware sounds, using env sounds",
      projDef->name.str);
    size = v17;
    v89.eventList.size = v17;
    if ( v22 )
    {
      if ( v17 && projDef->envLastShotSound.num != 0 )
      {
        p_envLastShotSound = &projDef->envLastShotSound;
        p_envOnlineLastShotSound = &projDef->envOnlineLastShotSound;
      }
      else
      {
        p_envLastShotSound = &projDef->envFireSounds;
        p_envOnlineLastShotSound = &projDef->envOnlineFireSounds;
      }
    }
    else if ( v17 && projDef->lastShotSound != nullptr )
    {
      onlineLastShotSound = projDef->onlineLastShotSound;
      lastShotSound = projDef->lastShotSound;
    }
    else
    {
      lastShotSound = projDef->fireSound;
      onlineLastShotSound = projDef->onlineFireSound;
    }
    if ( (*((_BYTE *)this + 452) & 0x20) != 0 )
      fadeDelay_low = (const idDeclAiEvent *)LODWORD(decl[2].fadeDelay);
    else
      fadeDelay_low = (const idDeclAiEvent *)decl[2].quickUseCoolDown;
    v89.eventList.num = (int)fadeDelay_low;
    if ( g_weaponSkipSound.valueInteger == 0 && (p_envLastShotSound != nullptr || lastShotSound != nullptr) )
    {
      if ( attacker != nullptr )
      {
        RD_EventBegin(name: "idWeapon::PlayFireSound - StartSoundShader");
        LODWORD(v26) = "idWeapon::PlayFireSound - StartSoundShader";
        HIDWORD(v26) = 2;
        idPLogScope::idPLogScope(this: v97, pl: &pLog, gMask: v26, label: v27);
        if ( v22 )
        {
          v28 = p_envLastShotSound;
          if ( attacker->GetPlayerInterface_2(this: attacker) != nullptr )
          {
            v29 = attacker->GetPlayerInterface_2(this: attacker);
            if ( !v29->IsLocallyControlled(this: v29) && p_envOnlineLastShotSound != nullptr )
              v28 = p_envOnlineLastShotSound;
          }
          v30 = SND_CHANNEL_WEAPON_LOOP_LEFT_HAND;
          v94 = 0;
          v93[0] = 0.0;
          v93[1] = -60.0;
          LODWORD(v93[3]) = 100;
          v93[2] = 0.0;
          LODWORD(v93[4]) = 200;
          v93[5] = -60.0;
          LODWORD(v93[7]) = 20;
          v93[6] = -60.0;
          LODWORD(v93[8]) = 40;
          v93[9] = 1.0;
          v93[10] = 1.0;
          list = nullptr;
          v93[11] = 5000.0;
          v95 = 0.0;
          v96 = 0.0;
          soundWorld = clientGame->soundWorld;
          v33 = soundWorld->__vftable;
          v34 = soundWorld->FindEnvironment(this: soundWorld, a2: &attacker->origin);
          v33->GetEnvironmentParams(this: soundWorld, a2: v34, a3: (soundEnvironment_t *)v93);
          v35 = 255;
          v36 = 0;
          v89.eventList.list = (idAIEvent **)v28->num;
          if ( (int)v89.eventList.list <= 0 )
          {
LABEL_42:
            list = v28->list;
            if ( v28 == &projDef->envOnlineFireSounds || (v40 = 0, v28 == &projDef->envOnlineLastShotSound) )
              v40 = 1;
            if ( v28 == &projDef->envLastShotSound || (v41 = 0, v28 == &projDef->envOnlineLastShotSound) )
              v41 = 1;
            idLib::Warning(
              fmt: "projectile %s has no matching sound for env %d (last shot: %d, online: %d)",
              projDef->name.str,
              v94,
              v41,
              v40);
            goto LABEL_49;
          }
          v37 = v28->list;
          v38 = 0;
          while ( 1 )
          {
            if ( (unsigned __int8)v37[v38].envType == (unsigned __int8)v94 )
            {
              v39 = abs32((v37[v38].envType >> 8) - (v94 >> 8));
              if ( v39 < v35 )
              {
                v35 = v39;
                list = &v37[v38];
                if ( v39 == 0 )
                {
LABEL_41:
                  if ( list == nullptr )
                    goto LABEL_42;
LABEL_49:
                  v42 = 1;
                  if ( v28 == this->loopingFireSoundList )
                    v42 = 0;
                  else
                    idWeapon::StopLoopingFireSound(this);
                  sound2 = (int)list->sound2;
                  sound0 = (int)list->sound0;
                  equipSlot = this->decl->equipSlot;
                  v89.eventHash.indexSize = (int)list->sound1;
                  v89.eventHash.granularity = sound2;
                  v89.eventHash.hashSize = sound0;
                  if ( equipSlot != EQUIP_LEFT_HAND )
                    v30 = SND_CHANNEL_WEAPON_LOOP;
                  v46 = 0;
                  if ( sound0 != 0 && (*(_DWORD *)(sound0 + 168) & 0x100200) != 0 && v42 != 0 )
                  {
                    loopInterVal = list->loopInterVal;
                    if ( loopInterVal == 0 )
                    {
                      idLib::Warning(
                        fmt: "projectile %s looping sound %s has no loop interval specified",
                        projDef->name.str,
                        *(const char **)(sound0 + 8));
                      loopInterVal = idWeapon::GetFiringInterval(this, secondaryAmmo);
                    }
                    v48 = ((int (__fastcall *)(idGameLocal *, int))gameLocal->GetSoundWorld)(a1: gameLocal, a2: v36);
                    v49 = (*(int (__fastcall **)(int))(*(_DWORD *)v48 + 112))(a1: v48);
                    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
                    LODWORD(v51) = gameLocal->GetGameMsPerRealSec(this: gameLocal);
                    HIDWORD(v51) = this->loopStopedGameTime;
                    LODWORD(v53) = 1000;
                    HIDWORD(v53) = v51 * loopInterVal;
                    LODWORD(v52) = loopInterVal;
                    if ( SHIDWORD(v51) < (int)(v51 * v52 / v53 + GameMs) )
                    {
                      GameMsPerFrame = idGameTimeManager::GetGameMsPerFrame(
                                         this: &clientGame->gameTimeManager,
                                         type: GAMETIME_SCALED);
                      if ( this->loopStopedGameTime + GameMsPerFrame < idGameTimeManager::GetGameMs(
                                                                         this: &clientGame->gameTimeManager,
                                                                         type: GAMETIME_SCALED) )
                      {
                        soundShaderParms_t::Clear(this: &v98);
                        v98.soundShaderFlags = 0;
                        idPresentable::StartSoundShader(
                          this: attacker,
                          channel: v30,
                          shader: list->sound0,
                          parms: &v98,
                          peerMask: 0);
                        this->loopStartSoundTime = v49;
                      }
                      else
                      {
                        v55 = this->loopStopedGameTime
                            + idGameTimeManager::GetGameMsPerFrame(
                                this: &clientGame->gameTimeManager,
                                type: GAMETIME_SCALED);
                        v56 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
                        v57 = (int)list->sound0;
                        HIBYTE(v90) = 105;
                        v91 = v30;
                        HIBYTE(v89.receivers.list) = 100;
                        v46 = v55 - v56;
                        entity = attacker->entity;
                        v89.receivers.num = v57;
                        v59 = __ROL4__(v89.eventPools.list, 32);
                        DWORD1(v60) = v89.receivers.list;
                        *((_QWORD *)&v60 + 1) = *(_QWORD *)&v89.receivers.size;
                        idEventReceiver::PostEventMS(
                          this: entity,
                          ev: &EV_StartSoundShader,
                          arg1: *(__int64 *)((char *)&v60 + 4),
                          arg2: *(__int64 *)&v59,
                          a5: __SPAIR64__(v30, v92),
                          a6: v78,
                          a7: v79,
                          a8: v80,
                          a9: v81,
                          a10: v82,
                          a11: v83,
                          a12: v84,
                          a13: v85,
                          a14: v86,
                          a15: v87,
                          a16: v88);
                        LODWORD(v61) = gameLocal->GetGameMsPerRealSec(this: gameLocal);
                        DWORD2(v61) = 1000 * v46;
                        HIDWORD(v62) = *(_QWORD *)((char *)&v61 + 4) / (__int64)v61;
                        this->loopStartSoundTime = HIDWORD(v62) + v49;
                        LODWORD(v62) = v61 & ~(__ROL4__(1000 * v46, 1) - 1);
                        __tdllei(v61, 0);
                        __tdlgei(v62, 0xFFFFFFFF);
                        idLib::Printf(fmt: "PlayFireSound: delayed play %d, loopStartSoundTime: %d\n", v46);
                      }
                      this->loopingFireSoundInterval = loopInterVal;
                      this->loopingFireEndSound = list->sound0LoopingEndSound;
                      this->loopingFireSoundList = v28;
                      this->loopingFireSoundEntity.spawnId = attacker->spawnId;
                      skipEndSoundOnEarlyRelease = projDef->skipEndSoundOnEarlyRelease;
                      v89.eventList.list = (idAIEvent **)&this->loopingFireSoundEntity;
                      this->loopingFireSoundSkipEndOnEarlyRelease = skipEndSoundOnEarlyRelease;
                    }
                  }
                  v64 = 0;
                  p_hashSize = &v89.eventHash.hashSize;
                  while ( 2 )
                  {
                    v66 = *p_hashSize;
                    if ( *p_hashSize != 0 )
                    {
                      if ( (*(_DWORD *)(v66 + 168) & 0x100200) != 0 )
                      {
                        if ( v64 != 0 && v42 != 0 )
                        {
                          fireChannel = ++v30;
                          goto LABEL_72;
                        }
                      }
                      else
                      {
                        fireChannel = this->fireChannel;
                        this->fireChannel = fireChannel + 1;
                        if ( fireChannel + 1 > 14 )
                          this->fireChannel = 6;
LABEL_72:
                        if ( v46 != 0 )
                        {
                          HIBYTE(v90) = 100;
                          v91 = v66;
                          HIBYTE(v89.receivers.list) = 105;
                          v89.receivers.num = fireChannel;
                          DWORD1(v68) = v90;
                          *((_QWORD *)&v68 + 1) = v92;
                          v69 = v89.receivers.list;
                          idEventReceiver::PostEventMS(
                            this: attacker->entity,
                            ev: &EV_StartSoundShader,
                            arg1: *(__int64 *)((char *)&v68 + 4),
                            arg2: *(__int64 *)((char *)&v68 - 4),
                            a5: *(__int64 *)&v89.receivers.size,
                            a6: v78,
                            a7: v79,
                            a8: v80,
                            a9: v81,
                            a10: v82,
                            a11: v83,
                            a12: v84,
                            a13: v85,
                            a14: v86,
                            a15: v87,
                            a16: v88);
                        }
                        else
                        {
                          soundShaderParms_t::Clear(this: &v99);
                          v99.soundShaderFlags = 0;
                          idPresentable::StartSoundShader(
                            this: attacker,
                            channel: fireChannel,
                            shader: (const idSoundShader *)v66,
                            parms: &v99,
                            peerMask: 0);
                        }
                      }
                    }
                    ++v64;
                    ++p_hashSize;
                    if ( v64 >= 3 )
                    {
                      size = v89.eventList.size;
                      fadeDelay_low = (const idDeclAiEvent *)v89.eventList.num;
                      v8 = target;
                      goto LABEL_83;
                    }
                    continue;
                  }
                }
              }
            }
            else if ( (unsigned __int8)v37[v38].envType == SET_DEFAULT && list == nullptr )
            {
              list = &v37[v38];
            }
            ++v36;
            ++v38;
            if ( v36 >= (int)v89.eventList.list )
              goto LABEL_41;
          }
        }
        idWeapon::StopLoopingFireSound(this);
        if ( attacker->GetPlayerInterface_2(this: attacker) != nullptr )
        {
          v70 = attacker->GetPlayerInterface_2(this: attacker);
          if ( !v70->IsLocallyControlled(this: v70) && onlineLastShotSound != nullptr )
            lastShotSound = onlineLastShotSound;
        }
        soundShaderParms_t::Clear(this: v100);
        v71 = this->fireChannel;
        v100[0].soundShaderFlags = 0;
        idPresentable::StartSoundShader(this: attacker, channel: v71, shader: lastShotSound, parms: v100, peerMask: 0);
        v72 = this->fireChannel + 3;
        this->fireChannel = v72;
        if ( v72 > 14 )
          this->fireChannel = 6;
LABEL_83:
        idPLogScope::~idPLogScope(this: v97);
        RD_EventEnd();
      }
      else
      {
        idLib::Warning(fmt: "No attacker in idWeapon::PlayFireSound");
      }
    }
    if ( fadeDelay_low != nullptr && common->IsServer(this: common) )
    {
      User = (idActor *)attacker->entity;
      v89.eventList.list = (idAIEvent **)User;
      v74 = idProp_WeaponStatic::CastTo(c: (idProp_WeaponStatic *)User);
      v75 = v74;
      if ( v74 != nullptr && idProp_WeaponStatic::GetUser(this: v74) != nullptr )
        User = idProp_WeaponStatic::GetUser(this: v75);
      if ( v8 != nullptr )
        v76 = v8->entity;
      else
        v76 = nullptr;
      v77 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      idAIEventManager::AddEvent(
        this: &v89,
        result: &gameLocal->aiEventManager,
        eventDecl: fadeDelay_low,
        curTime: v77,
        originator: User,
        instigator: v76,
        origin: start,
        delay: 0);
    }
    if ( size != 0 )
      idWeapon::StopLoopingFireSound(this);
  }
  idPLogScope::~idPLogScope(this: (idPLogScope *)&v89.eventHash);
  RD_EventEnd();
}


// ========================================================================
// __unwind$512842
// EA  : 0x82EC9ED8
// RVA : 0x00EC9ED8
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void _unwind_512842()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 928 + 772));
}


// ========================================================================
// __unwind$512843
// EA  : 0x82EC9F00
// RVA : 0x00EC9F00
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void _unwind_512843()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 928 + 128));
}


// ========================================================================
// __unwind$512844
// EA  : 0x82EC9F28
// RVA : 0x00EC9F28
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void _unwind_512844()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 928 + 773));
}


// ========================================================================
// __unwind$512845
// EA  : 0x82EC9F50
// RVA : 0x00EC9F50
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void _unwind_512845()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 928 + 288));
}


// ========================================================================
// ?FinishFire@idWeapon@@UAA_NABVidFireParms@@AAVidTestFireResults@@AAVidFinishFireResults@@PAVidFXManager@@_N@Z
// EA  : 0x82EC9F80
// RVA : 0x00EC9F80
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

unsigned int __fastcall idWeapon::FinishFire(
        idWeapon *this,
        const idFireParms *fp,
        idTestFireResults *tfr,
        idFinishFireResults *ffr,
        idFXManager *fxMgr,
        bool secondaryAmmo)
{
  unsigned __int64 v12; // r6
  const char *v13; // r7
  idAmmoItem *ammoClipSecondary; // r3
  int v15; // r28
  idPresentableWeapon *v16; // r3
  idLobbyBase *v17; // r3
  int GameMs; // r28
  __int64 v19; // r9
  int v20; // r28
  const idDeclProjectile *projDef; // r11
  unsigned __int64 v22; // r6
  const char *v23; // r7
  idPresentable *v24; // r3
  idPresentable *v25; // r3
  int v26; // r3
  idPresentable *v27; // r3
  idPresentablePlayer *v28; // r3
  idPresentable *Control; // r3
  char v30; // r9
  const idDeclInventory *decl; // r11
  char size_high; // r11
  idPresentable *v33; // r3
  int v34; // r28
  idPresentable *v35; // r3
  __int32 FXExtraCondition; // r3
  unsigned int v37; // r6
  int v38; // r27
  idPresentable *v39; // r3
  unsigned int v40; // r16
  idPresentable *v41; // r28
  __int32 v42; // r3
  const idDeclInventory *v43; // r11
  char v44; // r11
  int v45; // r28
  fxExtraCondition_t v46; // r3
  int v47; // r27
  idPresentable *v48; // r29
  fxExtraCondition_t v49; // r3
  unsigned __int64 v50; // r6
  const char *v51; // r7
  unsigned int spawnId; // r8
  int v53; // r29
  const idPresentable *PresentableByIndex; // r28
  unsigned int v55; // r29
  idPresentable *v56; // r4
  unsigned int v57; // r30
  idPresentable *v58; // r3
  idPresentableActor *v59; // r3
  idPlayer *ActorEntity; // r3
  int v61; // r28
  int *p_surfaceFlags; // r29
  int v63; // r9
  idAnimatedSimple *v64; // r30
  idAI2 *v65; // r3
  idAnimatedSimple *v66; // r3
  unsigned int v67; // r28
  idPLog *pLog; // r29
  idPLog::logEntry_t *v69; // r30
  int v70; // r3
  __int64 totalTicks; // r11
  __int64 v72; // r9
  idPLog *v74; // r29
  idPLog::logEntry_t *v75; // r30
  int v76; // r3
  __int64 v77; // r11
  __int64 v78; // r9
  idPLogScope v79; // [sp+50h] [-B0h] BYREF
  idPLogScope v80[3]; // [sp+58h] [-A8h] BYREF

  RD_EventBegin(name: "idWeapon::FinishFire");
  LODWORD(v12) = "idWeapon::FinishFire";
  HIDWORD(v12) = 2;
  idPLogScope::idPLogScope(this: v80, pl: &::pLog, gMask: v12, label: v13);
  if ( common->IsMultiplayer(this: common)
    && common->IsServer(this: common)
    && idPresentablePtr<idPresentable>::IsValid(this: (idPresentablePtr<idPresentableActor> *)&this->presentableWeapon) )
  {
    if ( secondaryAmmo )
      ammoClipSecondary = this->ammoClipSecondary;
    else
      ammoClipSecondary = this->ammoClip;
    v15 = ammoClipSecondary->GetCount(this: ammoClipSecondary);
    v16 = (idPresentableWeapon *)idPresentablePtr<idPresentableProjectile>::operator->(this: (idPresentablePtr<idPresentable> *)&this->presentableWeapon);
    idPresentableWeapon::RecordFireEvent(this: v16, fp, tfr, ffr, loadedCount: v15);
  }
  if ( common->IsMultiplayer(this: common)
    && (v17 = session->GetGameLobbyBase(this: session), v17->GetMatchParms(this: v17)->gameType == 2) )
  {
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    LODWORD(v19) = idWeapon::GetFiringInterval(this, secondaryAmmo);
    v79.pLog = (idPLog *)(int)(float)((float)v19 * this->firingIntervalModifier);
    this->nextFireTime = (int)v79.pLog + GameMs;
  }
  else
  {
    v20 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    this->nextFireTime = idWeapon::GetFiringInterval(this, secondaryAmmo) + v20;
  }
  idWeapon::IsMelee(this);
  this->fireState = FIRESTATE_IDLE;
  if ( (*((_BYTE *)fp + 128) & 0x20) == 0 )
    idWeapon::UseAmmo(this, count: (const int)this->decl[1].declSource, secondaryAmmo);
  projDef = fp->projDef;
  if ( projDef != nullptr && projDef->hitscan && projDef->ribbonEffect )
  {
    this->ribbonStartTime = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    this->ribbonEnd.x = tfr->traces[0].endpos.x;
    this->ribbonEnd.y = tfr->traces[0].endpos.y;
    v79.logIndex = (int)&this->ribbonEnd;
    this->ribbonEnd.z = tfr->traces[0].endpos.z;
  }
  this->burstCount = __CFADD__(this->burstCount - 1, 0x80000000) ? 0 : this->burstCount - 1;
  if ( fxMgr != nullptr )
  {
    RD_EventBegin(name: "idWeapon::FinishFire - fxManager.StartFX");
    LODWORD(v22) = "idWeapon::FinishFire - fxManager.StartFX";
    HIDWORD(v22) = 2;
    idPLogScope::idPLogScope(this: &v79, pl: &::pLog, gMask: v22, label: v23);
    if ( idPresentablePtr<idPresentableProjectile>::operator->(this: &fp->attacker) == nullptr
      || (v24 = idPresentablePtr<idPresentableProjectile>::operator->(this: &fp->attacker),
          v24->GetPlayerInterface_2(this: v24) == nullptr)
      || (v25 = idPresentablePtr<idPresentableProjectile>::operator->(this: &fp->attacker),
          v26 = (int)v25->GetPlayerInterface_2(this: v25),
          (*(unsigned __int8 (__fastcall **)(int))(*(_DWORD *)v26 + 300))(a1: v26) != 0)
      || (v27 = idPresentablePtr<idPresentableProjectile>::operator->(this: &fp->attacker),
          v28 = v27->GetPlayerInterface_2(this: v27),
          Control = idPresentablePlayer::GetControl(this: v28),
          v30 = 1,
          Control != nullptr) )
    {
      v30 = 0;
    }
    if ( (*((_BYTE *)this + 452) & 8) == 0
      || ((decl = this->decl, (*((_BYTE *)this + 452) & 0x10) == 0)
        ? (size_high = HIBYTE(decl[2].giveItemsOnReceive.size))
        : (size_high = decl[2].engineerableItems.list->baseBuffer[52 * this->currentZoomLevel + 16]),
          size_high == 0) )
    {
      if ( v30 != 0 )
      {
        v33 = idPresentablePtr<idPresentableProjectile>::operator->(this: &fp->attacker);
        v34 = !idWeapon::AttackerHasQuad(this, attacker: v33) ? 58 : 60;
      }
      else
      {
        v35 = idPresentablePtr<idPresentableProjectile>::operator->(this: &fp->attacker);
        v34 = !idWeapon::AttackerHasQuad(this, attacker: v35) ? 55 : 59;
      }
      idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      FXExtraCondition = idWeapon::GetFXExtraCondition(this, secondary: secondaryAmmo);
      idFXManager::StartFX(
        this: fxMgr,
        org: &vec3_origin,
        axis: &mat3_identity,
        time: v37,
        startCondition: v34,
        extraCond: FXExtraCondition);
    }
    if ( common->IsMultiplayer(this: common)
      && idPresentablePtr<idPresentableProjectile>::operator->(this: (idPresentablePtr<idPresentable> *)&this->presentableWeapon) != nullptr
      && fxMgr != &idPresentablePtr<idPresentableProjectile>::operator->(this: (idPresentablePtr<idPresentable> *)&this->presentableWeapon)->fxManager )
    {
      v38 = 58;
      v39 = idPresentablePtr<idPresentableProjectile>::operator->(this: &fp->attacker);
      if ( idWeapon::AttackerHasQuad(this, attacker: v39) )
        v38 = 60;
      v40 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      v41 = idPresentablePtr<idPresentableProjectile>::operator->(this: (idPresentablePtr<idPresentable> *)&this->presentableWeapon);
      v42 = idWeapon::GetFXExtraCondition(this, secondary: secondaryAmmo);
      idFXManager::StartFX(
        this: &v41->fxManager,
        org: &vec3_origin,
        axis: &mat3_identity,
        time: v40,
        startCondition: v38,
        extraCond: v42);
    }
    if ( (*((_BYTE *)this + 452) & 8) == 0
      || ((v43 = this->decl, (*((_BYTE *)this + 452) & 0x10) == 0)
        ? (v44 = HIBYTE(v43[2].giveItemsOnReceive.size))
        : (v44 = v43[2].engineerableItems.list->baseBuffer[52 * this->currentZoomLevel + 16]),
          v44 == 0) )
    {
      v45 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      v46 = idWeapon::GetFXExtraCondition(this, secondary: secondaryAmmo);
      idFXManager::StopFX(this: fxMgr, time: v45, stopCondition: 55, extraCondition: v46, immediateStop: false);
    }
    if ( idPresentablePtr<idPresentableProjectile>::operator->(this: (idPresentablePtr<idPresentable> *)&this->presentableWeapon) != nullptr
      && fxMgr != &idPresentablePtr<idPresentableProjectile>::operator->(this: (idPresentablePtr<idPresentable> *)&this->presentableWeapon)->fxManager )
    {
      v47 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      v48 = idPresentablePtr<idPresentableProjectile>::operator->(this: (idPresentablePtr<idPresentable> *)&this->presentableWeapon);
      v49 = idWeapon::GetFXExtraCondition(this, secondary: secondaryAmmo);
      idFXManager::StopFX(
        this: &v48->fxManager,
        time: v47,
        stopCondition: 55,
        extraCondition: v49,
        immediateStop: false);
    }
    idPLogScope::~idPLogScope(this: &v79);
    RD_EventEnd();
  }
  ++this->tracerCount;
  RD_EventBegin(name: "idWeapon::FinishFire - PlayFireSound");
  LODWORD(v50) = "idWeapon::FinishFire - PlayFireSound";
  HIDWORD(v50) = 2;
  idPLogScope::idPLogScope(this: &v79, pl: &::pLog, gMask: v50, label: v51);
  spawnId = fp->target.spawnId;
  v53 = spawnId & 0x3FFF;
  if ( spawnId == 0
    || !idClientGame::IsPresentableIndexValid(this: clientGame, index: spawnId & 0x3FFF)
    || (PresentableByIndex = idClientGame::GetPresentableByIndex(this: clientGame, index: v53))->spawnId != fp->target.spawnId )
  {
    PresentableByIndex = nullptr;
  }
  v55 = fp->attacker.spawnId & 0x3FFF;
  if ( fp->attacker.spawnId == 0
    || !idClientGame::IsPresentableIndexValid(this: clientGame, index: fp->attacker.spawnId & 0x3FFF)
    || (v56 = idClientGame::GetPresentableByIndex(this: clientGame, index: v55))->spawnId != fp->attacker.spawnId )
  {
    v56 = nullptr;
  }
  idWeapon::PlayFireSound(
    this,
    attacker: v56,
    target: PresentableByIndex,
    start: &fp->start,
    projDef: fp->projDef,
    secondaryAmmo);
  idPLogScope::~idPLogScope(this: &v79);
  RD_EventEnd();
  v57 = fp->attacker.spawnId & 0x3FFF;
  if ( fp->attacker.spawnId != 0
    && idClientGame::IsPresentableIndexValid(this: clientGame, index: fp->attacker.spawnId & 0x3FFF)
    && idClientGame::GetPresentableByIndex(this: clientGame, index: v57)->spawnId == fp->attacker.spawnId
    && (v58 = idPresentablePtr<idPresentableProjectile>::operator->(this: &fp->attacker),
        (v59 = v58->GetActorInterface_2(this: v58)) != nullptr)
    && (ActorEntity = (idPlayer *)idPresentableActor::GetActorEntity(this: v59),
        idPlayer::CastTo(c: ActorEntity) != nullptr)
    && (v61 = 0, tfr->numTraces > 0) )
  {
    p_surfaceFlags = &tfr->traces[0].c.surfaceFlags;
    while ( 1 )
    {
      if ( *((float *)p_surfaceFlags - 23) < 1.0 )
      {
        v63 = p_surfaceFlags[4] + 21563;
        v64 = *((idAnimatedSimple **)&gameLocal->__vftable + v63);
        if ( v64 != nullptr )
        {
          if ( (*p_surfaceFlags & 0x8000) != 0 )
            break;
          v65 = idAI2::CastTo(c: *((idAI2 **)&gameLocal->__vftable + v63));
          if ( v65 != nullptr && v65->aiEditable.interactions.playerShouldLowerWeapon )
            break;
          v66 = idAnimatedSimple::CastTo(c: v64);
          if ( v66 != nullptr && (*((_BYTE *)v66 + 5292) & 0x20) != 0 )
            break;
        }
      }
      ++v61;
      p_surfaceFlags += 32;
      if ( v61 >= tfr->numTraces )
        goto LABEL_72;
    }
    idPLogScope::~idPLogScope(this: v80);
    RD_EventEnd();
    return 0;
  }
  else
  {
LABEL_72:
    if ( common->IsServer(this: common) )
    {
      v67 = idGameLocal::FinishFire(this: gameLocal, fp, tfr, ffr);
      if ( v80[0].logIndex >= 0 )
      {
        pLog = v80[0].pLog;
        v69 = &v80[0].pLog->logEntries.list[v80[0].logIndex];
        v70 = (unsigned __int64)Sys_GetClockTicks() >> 32;
        totalTicks = v69->totalTicks;
        HIDWORD(totalTicks) = v69->parent;
        LODWORD(v72) = v70 - totalTicks;
        v69->totalTicks = v72;
        pLog->lastEntry = HIDWORD(totalTicks);
      }
    }
    else
    {
      v67 = idClientGame::FinishFire(this: clientGame, fp, tfr, ffr);
      if ( v80[0].logIndex >= 0 )
      {
        v74 = v80[0].pLog;
        v75 = &v80[0].pLog->logEntries.list[v80[0].logIndex];
        v76 = (unsigned __int64)Sys_GetClockTicks() >> 32;
        v77 = v75->totalTicks;
        HIDWORD(v77) = v75->parent;
        LODWORD(v78) = v76 - v77;
        v75->totalTicks = v78;
        v74->lastEntry = HIDWORD(v77);
      }
    }
    RD_EventEnd();
    return v67;
  }
}


// ========================================================================
// __unwind$513106
// EA  : 0x82ECA89C
// RVA : 0x00ECA89C
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void _unwind_513106()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 256 + 96));
}


// ========================================================================
// __unwind$513107
// EA  : 0x82ECA8C4
// RVA : 0x00ECA8C4
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void _unwind_513107()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 256 + 88));
}


// ========================================================================
// __unwind$513108
// EA  : 0x82ECA8EC
// RVA : 0x00ECA8EC
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void _unwind_513108()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 256 + 97));
}


// ========================================================================
// __unwind$513109
// EA  : 0x82ECA914
// RVA : 0x00ECA914
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void _unwind_513109()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 256 + 80));
}


// ========================================================================
// __unwind$513110
// EA  : 0x82ECA93C
// RVA : 0x00ECA93C
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void _unwind_513110()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 256 + 98));
}


// ========================================================================
// __unwind$513111
// EA  : 0x82ECA964
// RVA : 0x00ECA964
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void _unwind_513111()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 256 + 80));
}


// ========================================================================
// ?Reload@idWeapon@@UAAXPAVidInventoryCollection@@PAVidFXManager@@_N22@Z
// EA  : 0x82ECA998
// RVA : 0x00ECA998
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __fastcall idWeapon::Reload(
        idWeapon *this,
        idInventoryCollection *inventory,
        idFXManager *fxMgr,
        BOOL sameAmmoCount,
        BOOL forceAmmoChange,
        int secondaryAmmo)
{
  unsigned __int64 v12; // r6
  const char *v13; // r7
  const idDeclAmmo *nextAmmo; // r4
  char v15; // r9
  idInventoryItem **p_ammoClipSecondary; // r29
  int ClipSize; // r3
  __int32 FXExtraCondition; // r3
  unsigned int v19; // r6
  unsigned int GameMs; // r24
  idPresentable *v21; // r29
  __int32 v22; // r3
  idPLogScope v23[13]; // [sp+58h] [-68h] BYREF

  RD_EventBegin(name: "idWeapon::Reload");
  LODWORD(v12) = "idWeapon::Reload";
  HIDWORD(v12) = 2;
  idPLogScope::idPLogScope(this: v23, pl: &pLog, gMask: v12, label: v13);
  nextAmmo = this->nextAmmo;
  if ( nextAmmo != nullptr && this->fireState == FIRESTATE_RELOADING )
  {
    v15 = *((_BYTE *)this + 453);
    this->fireState = FIRESTATE_IDLE;
    this->burstCount = 0;
    this->barrelSpinSpeed = 0.0;
    *((_BYTE *)this + 453) = v15 & 0xDF;
    p_ammoClipSecondary = (idInventoryItem **)&this->ammoClipSecondary;
    if ( (_BYTE)secondaryAmmo == 0 )
      p_ammoClipSecondary = (idInventoryItem **)&this->ammoClip;
    if ( inventory != nullptr )
    {
      this->LoadAmmo(
        this,
        a2: inventory,
        a3: nextAmmo,
        a4: fxMgr,
        a5: sameAmmoCount,
        a6: BYTE1(this->decl[3].price),
        a7: forceAmmoChange,
        a8: secondaryAmmo);
      if ( fxMgr != nullptr )
      {
        idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        FXExtraCondition = idWeapon::GetFXExtraCondition(this, secondary: secondaryAmmo);
        idFXManager::StartFX(
          this: fxMgr,
          org: &vec3_origin,
          axis: &mat3_identity,
          time: v19,
          startCondition: 66,
          extraCond: FXExtraCondition);
        if ( idPresentablePtr<idPresentableProjectile>::operator->(this: (idPresentablePtr<idPresentable> *)&this->presentableWeapon) != nullptr
          && fxMgr != &idPresentablePtr<idPresentableProjectile>::operator->(this: (idPresentablePtr<idPresentable> *)&this->presentableWeapon)->fxManager )
        {
          GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
          v21 = idPresentablePtr<idPresentableProjectile>::operator->(this: (idPresentablePtr<idPresentable> *)&this->presentableWeapon);
          v22 = idWeapon::GetFXExtraCondition(this, secondary: secondaryAmmo);
          idFXManager::StartFX(
            this: &v21->fxManager,
            org: &vec3_origin,
            axis: &mat3_identity,
            time: GameMs,
            startCondition: 66,
            extraCond: v22);
        }
      }
      this->nextAmmo = nullptr;
      idPLogScope::~idPLogScope(this: v23);
    }
    else
    {
      ClipSize = idDeclWeapon::GetClipSize(
                   this: (idDeclWeapon *)this->decl,
                   ammoDecl: nextAmmo,
                   weaponUpgraded: (*((_BYTE *)this + 452) & 4) != 0,
                   secondary: secondaryAmmo);
      idInventoryItem::SetCount(this: *p_ammoClipSecondary, amount: ClipSize);
      idPLogScope::~idPLogScope(this: v23);
    }
  }
  else
  {
    idPLogScope::~idPLogScope(this: v23);
  }
  RD_EventEnd();
}


// ========================================================================
// __unwind$513495
// EA  : 0x82ECABA4
// RVA : 0x00ECABA4
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void _unwind_513495()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 192 + 96));
}


// ========================================================================
// __unwind$513496
// EA  : 0x82ECABCC
// RVA : 0x00ECABCC
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void _unwind_513496()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 192 + 88));
}


// ========================================================================
// ?PullTrigger@idLaserCutter@@UAAXPAVidActor@@_N@Z
// EA  : 0x82ECAC00
// RVA : 0x00ECAC00
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __fastcall idLaserCutter::PullTrigger(idLaserCutter *this, idActor *user, bool secondaryAmmo)
{
  char v6; // r28
  idWeapon::triggerState_t triggerState; // r11
  int lastOkToCutTime; // r11
  idAmmoItem *ammoClipSecondary; // r11
  burstMode_t burstMode; // r4
  idFXManager *v11; // r28
  unsigned __int64 v12; // r6
  const char *v13; // r7
  int GameMs; // r24
  fxExtraCondition_t FXExtraCondition; // r3
  int v16; // r24
  fxExtraCondition_t v17; // r3
  int v18; // r24
  fxExtraCondition_t v19; // r3
  __int32 v20; // r3
  unsigned int v21; // r6
  __int64 v22; // r10
  double CurrentValue; // fp1
  double fadeInDuration; // fp31
  double v25; // fp30
  int v26; // r3
  idPLogScope v27[3]; // [sp+50h] [-70h] BYREF

  if ( (unsigned __int8)idWeapon::IsMelee(this) == 0 )
  {
    v6 = 0;
    if ( idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) >= this->nextFireTime )
    {
      triggerState = this->triggerState;
      if ( secondaryAmmo )
      {
        if ( triggerState != TRIGGERSTATE_PULLED )
        {
          lastOkToCutTime = this->lastOkToCutTime;
          this->triggerState = TRIGGERSTATE_PULLED;
          if ( lastOkToCutTime != 0 )
          {
            v6 = 1;
            idCutterGraphManager::PreAcquire(this: &gameLocal->graphManager);
          }
        }
      }
      else if ( triggerState != TRIGGERSTATE_PULLED )
      {
        v6 = 1;
        this->triggerState = TRIGGERSTATE_PULLED;
      }
    }
    if ( v6 != 0 )
    {
      if ( secondaryAmmo )
        ammoClipSecondary = this->ammoClipSecondary;
      else
        ammoClipSecondary = this->ammoClip;
      if ( ammoClipSecondary != nullptr )
        burstMode = ammoClipSecondary->burstMode;
      else
        burstMode = this->decl[1].attachmentInfo.num;
      this->burstCount = idWeapon::GetInitialBurstCount(this, mode: burstMode, secondaryAmmo);
      v11 = user->GetFXMgrForAttachment(this: user, a2: this);
      if ( v11 != nullptr )
      {
        RD_EventBegin(name: "idLaserCutter::FinishFire - fxManager.StartFX");
        LODWORD(v12) = "idLaserCutter::FinishFire - fxManager.StartFX";
        HIDWORD(v12) = 2;
        idPLogScope::idPLogScope(this: v27, pl: &pLog, gMask: v12, label: v13);
        GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        FXExtraCondition = idWeapon::GetFXExtraCondition(this, secondary: secondaryAmmo);
        idFXManager::StopFX(
          this: v11,
          time: GameMs,
          stopCondition: 74,
          extraCondition: FXExtraCondition,
          immediateStop: false);
        v16 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        v17 = idWeapon::GetFXExtraCondition(this, secondary: secondaryAmmo);
        idFXManager::StopFX(this: v11, time: v16, stopCondition: 76, extraCondition: v17, immediateStop: false);
        v18 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        v19 = idWeapon::GetFXExtraCondition(this, secondary: secondaryAmmo);
        idFXManager::StopFX(this: v11, time: v18, stopCondition: 78, extraCondition: v19, immediateStop: false);
        if ( secondaryAmmo )
        {
          idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
          v20 = idWeapon::GetFXExtraCondition(this, secondary: secondaryAmmo);
          idFXManager::StartFX(
            this: v11,
            org: &vec3_origin,
            axis: &mat3_identity,
            time: v21,
            startCondition: 73,
            extraCond: v20);
        }
        idPLogScope::~idPLogScope(this: v27);
        RD_EventEnd();
      }
      if ( secondaryAmmo )
      {
        this->cuttingWeldEffectRunning = true;
        LODWORD(v22) = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        v27[0] = (idPLogScope)v22;
        CurrentValue = idInterpolate<float>::GetCurrentValue(
                         this: &this->laserBeamCutFade,
                         time: (float)((float)v22 * (float)0.001));
        fadeInDuration = this->laserBeamCut.fadeInDuration;
        v25 = CurrentValue;
        v26 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        this->laserBeamCutFade.startValue = v25;
        this->laserBeamCutFade.endValue = 1.0;
        this->laserBeamCutFade.currentValue = v25;
        this->laserBeamCutFade.startTime = (float)__SPAIR64__(0x82000000, v26) * (float)0.001;
        this->laserBeamCutFade.duration = (float)((float)1.0 - (float)v25) * (float)fadeInDuration;
        this->laserBeamCutFade.currentTime = (float)((float)__SPAIR64__(0x82000000, v26) * (float)0.001) - (float)1.0;
      }
    }
  }
}


// ========================================================================
// __unwind$513578
// EA  : 0x82ECAF04
// RVA : 0x00ECAF04
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void _unwind_513578()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 192 + 88));
}


// ========================================================================
// __unwind$513579
// EA  : 0x82ECAF2C
// RVA : 0x00ECAF2C
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void _unwind_513579()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 192 + 80));
}


// ========================================================================
// ?ReleaseTrigger@idLaserCutter@@UAAXPAVidActor@@@Z
// EA  : 0x82ECAF60
// RVA : 0x00ECAF60
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __fastcall idLaserCutter::ReleaseTrigger(idLaserCutter *this, idActor *user)
{
  idWeapon::triggerState_t triggerState; // r11
  idWeapon::weaponState_t weaponState; // r11
  char v5; // r7
  bool v6; // r27
  idFXManager *v7; // r26
  unsigned __int64 v8; // r6
  const char *v9; // r7
  int GameMs; // r24
  fxExtraCondition_t FXExtraCondition; // r3
  int v12; // r24
  fxExtraCondition_t v13; // r3
  __int64 v14; // r11
  double CurrentValue; // fp1
  double fadeInDuration; // fp31
  double v17; // fp30
  int v18; // r3
  idPLogScope v19[3]; // [sp+50h] [-70h] BYREF

  triggerState = this->triggerState;
  this->cuttingWeldEffectRunning = false;
  if ( triggerState != TRIGGERSTATE_RELEASED )
  {
    weaponState = this->weaponState;
    this->burstCount = 0;
    this->triggerState = TRIGGERSTATE_RELEASED;
    v5 = _cntlzw(weaponState - 1);
    v6 = (v5 & 0x20) != 0;
    if ( (v5 & 0x20) != 0 )
    {
      v7 = user->GetFXMgrForAttachment(this: user, a2: this);
      if ( v7 != nullptr )
      {
        RD_EventBegin(name: "idLaserCutter::FinishFire - fxManager.StartFX");
        LODWORD(v8) = "idLaserCutter::FinishFire - fxManager.StartFX";
        HIDWORD(v8) = 2;
        idPLogScope::idPLogScope(this: v19, pl: &pLog, gMask: v8, label: v9);
        GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        FXExtraCondition = idWeapon::GetFXExtraCondition(this, secondary: v6);
        idFXManager::StopFX(
          this: v7,
          time: GameMs,
          stopCondition: 74,
          extraCondition: FXExtraCondition,
          immediateStop: false);
        v12 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        v13 = idWeapon::GetFXExtraCondition(this, secondary: v6);
        idFXManager::StopFX(this: v7, time: v12, stopCondition: 76, extraCondition: v13, immediateStop: false);
        this->endEffectActive = false;
        idPLogScope::~idPLogScope(this: v19);
        RD_EventEnd();
      }
    }
    LODWORD(v14) = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    v19[0] = (idPLogScope)v14;
    CurrentValue = idInterpolate<float>::GetCurrentValue(
                     this: &this->laserBeamCutFade,
                     time: (float)((float)v14 * (float)0.001));
    fadeInDuration = this->laserBeamCut.fadeInDuration;
    v17 = CurrentValue;
    v18 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    this->laserBeamCutFade.duration = (float)fadeInDuration * (float)v17;
    this->laserBeamCutFade.startValue = v17;
    this->laserBeamCutFade.endValue = 0.0;
    this->laserBeamCutFade.currentValue = v17;
    this->laserBeamCutFade.startTime = (float)__SPAIR64__(0x82000000, v18) * (float)0.001;
    this->laserBeamCutFade.currentTime = (float)((float)__SPAIR64__(0x82000000, v18) * (float)0.001) - (float)1.0;
  }
}


// ========================================================================
// __unwind$513730_0
// EA  : 0x82ECB138
// RVA : 0x00ECB138
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void _unwind_513730_0()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 192 + 88));
}


// ========================================================================
// __unwind$513731_0
// EA  : 0x82ECB160
// RVA : 0x00ECB160
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void _unwind_513731_0()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 192 + 80));
}


// ========================================================================
// ?FinishFire@idLaserCutter@@UAA_NABVidFireParms@@AAVidTestFireResults@@AAVidFinishFireResults@@PAVidFXManager@@_N@Z
// EA  : 0x82ECB190
// RVA : 0x00ECB190
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

unsigned int __fastcall idLaserCutter::FinishFire(
        idLaserCutter *this,
        const idFireParms *fp,
        idTestFireResults *tfr,
        idFinishFireResults *ffr,
        idFXManager *fxMgr,
        bool secondaryAmmo)
{
  unsigned __int64 v12; // r6
  const char *v13; // r7
  int v14; // r10
  idAmmoItem *ammoClipSecondary; // r11
  const idDeclInventory *decl; // r11
  int num; // r27
  idAmmoItem *ammoClip; // r11
  idLobbyBase *v20; // r3
  int GameMs; // r27
  __int64 v22; // r11
  double v23; // fp0
  int v24; // r27
  int v25; // r21
  fxExtraCondition_t FXExtraCondition; // r3
  int v27; // r21
  fxExtraCondition_t v28; // r3
  int v29; // r21
  fxExtraCondition_t v30; // r3
  __int32 v31; // r3
  unsigned int v32; // r6
  unsigned __int64 v33; // r6
  const char *v34; // r7
  __int32 v35; // r3
  unsigned int v36; // r6
  __int32 v37; // r3
  unsigned int v38; // r6
  int v39; // r29
  fxExtraCondition_t v40; // r3
  unsigned __int64 v41; // r6
  const char *v42; // r7
  const idDeclProjectile *projDef; // r29
  const idPresentable *v44; // r27
  idPresentable *v45; // r3
  unsigned int v46; // r3
  idLaserCutter::functionalityLens_t currentFunctionalityLens; // r11
  unsigned int v48; // r20
  int v49; // r5
  idClass *v50; // r26
  char v51; // r23
  int v52; // r29
  const idTypeInfo **v53; // r28
  double y; // fp12
  double v55; // fp11
  double x; // fp10
  double v57; // fp9
  double z; // fp8
  double v59; // fp7
  double v60; // fp6
  double v61; // fp5
  double v62; // fp4
  double v63; // fp7
  double v64; // fp6
  const idPresentable *v65; // r27
  idPresentable *v66; // r3
  double v67; // fp29
  double v68; // fp30
  double v69; // fp31
  float *v70; // r11
  double v71; // fp12
  double v72; // fp11
  unsigned __int8 (*IsServer)(void); // ctr
  double v74; // fp9
  double v75; // fp8
  idPLog *pLog; // r29
  idPLog::logEntry_t *v77; // r30
  int v78; // r3
  __int64 totalTicks; // r11
  __int64 v80; // r9
  idPLogScope v82; // [sp+58h] [-188h] BYREF
  idMat3 v83; // [sp+60h] [-180h] BYREF
  idPLogScope v84; // [sp+88h] [-158h] BYREF
  idFireParms v85; // [sp+90h] [-150h] BYREF

  RD_EventBegin(name: "idLaserCutter::FinishFire");
  LODWORD(v12) = "idLaserCutter::FinishFire";
  HIDWORD(v12) = 2;
  idPLogScope::idPLogScope(this: &v84, pl: &::pLog, gMask: v12, label: v13);
  if ( this->nextTakeBatteryTime < idGameTimeManager::GetGameMs(
                                     this: &clientGame->gameTimeManager,
                                     type: GAMETIME_SCALED) )
  {
    if ( (*((_BYTE *)fp + 128) & 0x20) == 0 )
    {
      v14 = 0;
      if ( secondaryAmmo )
        ammoClipSecondary = this->ammoClipSecondary;
      else
        ammoClipSecondary = this->ammoClip;
      if ( ammoClipSecondary != nullptr )
        decl = ammoClipSecondary->decl;
      else
        decl = nullptr;
      if ( decl != nullptr )
        v14 = *(_DWORD *)decl[1].vehicleJointName.baseBuffer;
      if ( g_infiniteAmmo.valueInteger == 0 && g_permaInfiniteAmmo.valueInteger == 0 )
        this->batteryCount = __CFADD__(this->batteryCount - v14, 0x80000000) ? 0 : this->batteryCount - v14;
    }
    if ( secondaryAmmo )
      num = this->decl[4].attachmentInfo.num;
    else
      num = idWeapon::GetFiringInterval(this, secondaryAmmo);
    this->nextTakeBatteryTime = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED)
                              + num;
  }
  if ( secondaryAmmo )
    ammoClip = this->ammoClipSecondary;
  else
    ammoClip = this->ammoClip;
  if ( ammoClip == nullptr || !*(&ammoClip->decl[1].vehicleArmor + 1) )
  {
    if ( common->IsMultiplayer(this: common)
      && (v20 = session->GetActivePlatformLobbyBase(this: session), v20->GetMatchParms(this: v20)->gameType == 2) )
    {
      GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      LODWORD(v22) = idWeapon::GetFiringInterval(this, secondaryAmmo);
      this->nextFireTime = (int)(float)((float)v22 * (float)v23) + GameMs;
    }
    else
    {
      v24 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      this->nextFireTime = idWeapon::GetFiringInterval(this, secondaryAmmo) + v24;
    }
  }
  idWeapon::IsMelee(this);
  this->fireState = FIRESTATE_IDLE;
  this->burstCount = 0;
  if ( fxMgr != nullptr )
  {
    if ( !secondaryAmmo )
    {
      v25 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      FXExtraCondition = idWeapon::GetFXExtraCondition(this, secondary: secondaryAmmo);
      idFXManager::StopFX(
        this: fxMgr,
        time: v25,
        stopCondition: 74,
        extraCondition: FXExtraCondition,
        immediateStop: false);
      v27 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      v28 = idWeapon::GetFXExtraCondition(this, secondary: secondaryAmmo);
      idFXManager::StopFX(this: fxMgr, time: v27, stopCondition: 76, extraCondition: v28, immediateStop: false);
      v29 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      v30 = idWeapon::GetFXExtraCondition(this, secondary: secondaryAmmo);
      idFXManager::StopFX(this: fxMgr, time: v29, stopCondition: 78, extraCondition: v30, immediateStop: false);
      idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      v31 = idWeapon::GetFXExtraCondition(this, secondary: secondaryAmmo);
      idFXManager::StartFX(
        this: fxMgr,
        org: &vec3_origin,
        axis: &mat3_identity,
        time: v32,
        startCondition: 73,
        extraCond: v31);
    }
    RD_EventBegin(name: "idLaserCutter::FinishFire - fxManager.StartFX");
    LODWORD(v33) = "idLaserCutter::FinishFire - fxManager.StartFX";
    HIDWORD(v33) = 2;
    idPLogScope::idPLogScope(this: &v82, pl: &::pLog, gMask: v33, label: v34);
    idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    v35 = idWeapon::GetFXExtraCondition(this, secondary: secondaryAmmo);
    idFXManager::StartFX(
      this: fxMgr,
      org: &vec3_origin,
      axis: &mat3_identity,
      time: v36,
      startCondition: 55,
      extraCond: v35);
    if ( tfr->numTraces != 0 && tfr->traces[0].fraction < 1.0 )
    {
      fxMgr->externalPosition.x = tfr->traces[0].endpos.x;
      fxMgr->externalPosition.y = tfr->traces[0].endpos.y;
      fxMgr->externalPosition.z = tfr->traces[0].endpos.z;
      fxMgr->externalRotation.mat[0].x = tfr->traces[0].endAxis.mat[0].x;
      fxMgr->externalRotation.mat[0].y = tfr->traces[0].endAxis.mat[0].y;
      fxMgr->externalRotation.mat[0].z = tfr->traces[0].endAxis.mat[0].z;
      fxMgr->externalRotation.mat[1].x = tfr->traces[0].endAxis.mat[1].x;
      fxMgr->externalRotation.mat[1].y = tfr->traces[0].endAxis.mat[1].y;
      fxMgr->externalRotation.mat[1].z = tfr->traces[0].endAxis.mat[1].z;
      fxMgr->externalRotation.mat[2].x = tfr->traces[0].endAxis.mat[2].x;
      fxMgr->externalRotation.mat[2].y = tfr->traces[0].endAxis.mat[2].y;
      fxMgr->externalRotation.mat[2].z = tfr->traces[0].endAxis.mat[2].z;
      fxMgr->hasExternalPositionAndRotation = true;
      if ( !this->endEffectActive )
      {
        this->endEffectActive = true;
        idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        v37 = idWeapon::GetFXExtraCondition(this, secondary: secondaryAmmo);
        idFXManager::StartFX(
          this: fxMgr,
          org: &vec3_origin,
          axis: &mat3_identity,
          time: v38,
          startCondition: 75,
          extraCond: v37);
      }
    }
    else if ( this->endEffectActive )
    {
      this->endEffectActive = false;
      v39 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      v40 = idWeapon::GetFXExtraCondition(this, secondary: secondaryAmmo);
      idFXManager::StopFX(this: fxMgr, time: v39, stopCondition: 76, extraCondition: v40, immediateStop: false);
    }
    idPLogScope::~idPLogScope(this: &v82);
    RD_EventEnd();
  }
  if ( !secondaryAmmo )
  {
    RD_EventBegin(name: "idWeapon::FinishFire - PlayFireSound");
    LODWORD(v41) = "idWeapon::FinishFire - PlayFireSound";
    HIDWORD(v41) = 2;
    idPLogScope::idPLogScope(this: &v82, pl: &::pLog, gMask: v41, label: v42);
    projDef = fp->projDef;
    v44 = idPresentablePtr<idPresentableProjectile>::operator->(this: &fp->target);
    v45 = idPresentablePtr<idPresentableProjectile>::operator->(this: &fp->attacker);
    idWeapon::PlayFireSound(this, attacker: v45, target: v44, start: &fp->start, projDef, secondaryAmmo);
    idPLogScope::~idPLogScope(this: &v82);
    RD_EventEnd();
  }
  if ( common->IsServer(this: common) )
    v46 = idGameLocal::FinishFire(this: gameLocal, fp, tfr, ffr);
  else
    v46 = idClientGame::FinishFire(this: clientGame, fp, tfr, ffr);
  currentFunctionalityLens = this->currentFunctionalityLens;
  v48 = v46;
  this->storedBeamImpactPosIsValid = false;
  if ( currentFunctionalityLens == FUNCTIONALITY_LENS_REFLECTION && this->functionalityLensActive && tfr->numTraces != 0 )
  {
    v49 = 4 * (tfr->traces[0].c.entityNum + 21563);
    LODWORD(v83.mat[0].x) = &idAI2::Type;
    v50 = *(idClass **)((char *)&gameLocal->__vftable + v49);
    LODWORD(v83.mat[0].y) = &idTurret::Type;
    LODWORD(v83.mat[0].z) = &idTrigger_Damage::Type;
    v51 = 1;
    LODWORD(v83.mat[1].x) = &idCuttable::Type;
    LODWORD(v83.mat[1].y) = &idFuncChain::Type;
    if ( v50 != nullptr )
    {
      v52 = 0;
      v53 = (const idTypeInfo **)&v83;
      while ( (unsigned __int8)idClass::IsType(this: v50, superclass: *v53) == 0 )
      {
        ++v52;
        ++v53;
        if ( v52 >= (!secondaryAmmo ? 3 : 5) )
          goto LABEL_54;
      }
      v51 = 0;
    }
LABEL_54:
    if ( v51 != 0 && tfr->traces[0].fraction < 1.0 )
    {
      y = fp->fireAxis.mat[0].y;
      v55 = (float)(fp->fireAxis.mat[0].y * tfr->traces[0].c.normal.y);
      x = tfr->traces[0].c.normal.x;
      v57 = fp->fireAxis.mat[0].x;
      z = tfr->traces[0].c.normal.z;
      v59 = fp->fireAxis.mat[0].z;
      v60 = (float)(tfr->traces[0].c.normal.y * (float)2.0);
      v61 = (float)(tfr->traces[0].c.normal.x * (float)2.0);
      v62 = (float)(tfr->traces[0].c.normal.z * (float)2.0);
      v83.mat[1].z = 0.0;
      v83.mat[2].y = 0.0;
      v83.mat[2].x = 0.0;
      v83.mat[1].x = 0.0;
      v83.mat[2].z = 1.0;
      v83.mat[1].y = 1.0;
      v83.mat[0].z = (float)v59
                   - (float)((float)v62
                           * (float)((float)((float)v59 * (float)z)
                                   + (float)((float)((float)v57 * (float)x) + (float)v55)));
      v83.mat[0].y = (float)y
                   - (float)((float)v60
                           * (float)((float)((float)v59 * (float)z)
                                   + (float)((float)((float)v57 * (float)x) + (float)v55)));
      v83.mat[0].x = (float)v57
                   - (float)((float)v61
                           * (float)((float)((float)v59 * (float)z)
                                   + (float)((float)((float)v57 * (float)x) + (float)v55)));
      idMat3::OrthoNormalizeSelf(this: &v83, prio1: 0, prio2: 2);
      idFireParms::idFireParms(this: &v85);
      idFireParms::operator=(this: &v85, __that: fp);
      v63 = tfr->traces[0].endpos.y;
      v64 = tfr->traces[0].endpos.z;
      v85.start.x = tfr->traces[0].endpos.x;
      v85.start.y = v63;
      v85.start.z = v64;
      v65 = idPresentablePtr<idPresentableProjectile>::operator->(this: &v85.target);
      v66 = idPresentablePtr<idPresentableProjectile>::operator->(this: &v85.attacker);
      if ( (unsigned __int8)idWeapon::TestFire(
                              this,
                              attacker: v66,
                              target: v65,
                              start: &v85.start,
                              fireAxis: &v83,
                              fp: &v85,
                              tfr,
                              secondaryAmmo) != 0
        && tfr->traces[0].fraction < 0.75 )
      {
        this->storedBeamImpactPosIsValid = true;
        v67 = (float)(tfr->traces[0].endpos.x - v85.start.x);
        v68 = (float)(tfr->traces[0].endpos.y - v85.start.y);
        v69 = (float)(tfr->traces[0].endpos.z - v85.start.z);
        v70 = (float *)idMat3::Inverse(this: &v83, result: &fp->fireAxis);
        v71 = v70[8];
        v72 = v70[7];
        IsServer = (unsigned __int8 (*)(void))common->IsServer;
        v74 = (float)((float)(v70[2] * (float)v67) + (float)(v70[5] * (float)v68));
        v75 = (float)((float)(v70[1] * (float)v67) + (float)(v70[4] * (float)v68));
        this->storedBeamImpactPos.x = (float)((float)v67 * *v70)
                                    + (float)((float)(v70[3] * (float)v68) + (float)(v70[6] * (float)v69));
        this->storedBeamImpactPos.z = (float)((float)v71 * (float)v69) + (float)v74;
        this->storedBeamImpactPos.y = (float)((float)v72 * (float)v69) + (float)v75;
        if ( IsServer() != 0 )
          idGameLocal::FinishFire(this: gameLocal, fp, tfr, ffr);
        else
          idClientGame::FinishFire(this: clientGame, fp, tfr, ffr);
      }
      idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v85.targetList);
    }
  }
  if ( v84.logIndex >= 0 )
  {
    pLog = v84.pLog;
    v77 = &v84.pLog->logEntries.list[v84.logIndex];
    v78 = (unsigned __int64)Sys_GetClockTicks() >> 32;
    totalTicks = v77->totalTicks;
    HIDWORD(totalTicks) = v77->parent;
    LODWORD(v80) = v78 - totalTicks;
    v77->totalTicks = v80;
    pLog->lastEntry = HIDWORD(totalTicks);
  }
  RD_EventEnd();
  return v48;
}


// ========================================================================
// __unwind$513820
// EA  : 0x82ECBAB8
// RVA : 0x00ECBAB8
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void _unwind_513820()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 480 + 292));
}


// ========================================================================
// __unwind$513821
// EA  : 0x82ECBAE0
// RVA : 0x00ECBAE0
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void _unwind_513821()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 480 + 136));
}


// ========================================================================
// __unwind$513822
// EA  : 0x82ECBB08
// RVA : 0x00ECBB08
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void _unwind_513822()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 480 + 293));
}


// ========================================================================
// __unwind$513823
// EA  : 0x82ECBB30
// RVA : 0x00ECBB30
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void _unwind_513823()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 480 + 88));
}


// ========================================================================
// __unwind$513824
// EA  : 0x82ECBB58
// RVA : 0x00ECBB58
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void _unwind_513824()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 480 + 294));
}


// ========================================================================
// __unwind$513825
// EA  : 0x82ECBB80
// RVA : 0x00ECBB80
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void _unwind_513825()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 480 + 88));
}


// ========================================================================
// __unwind$513826
// EA  : 0x82ECBBA8
// RVA : 0x00ECBBA8
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void _unwind_513826()
{
  int v0; // r12

  idFireParms::~idFireParms(this: (idAI2::idAIVolatile::idAIEventInfo *)(v0 - 480 + 144));
}


// ========================================================================
// ?UpdateArmorInfo@idVehicleKey@@QAAX_N@Z
// EA  : 0x82ECBBD8
// RVA : 0x00ECBBD8
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __fastcall idVehicleKey::UpdateArmorInfo(idVehicleKey *this, bool initFromUpgrades)
{
  idVehicle *VehicleFromKey; // r23
  int v5; // r10
  const idDeclVehicleUpgrade **list; // r8
  int v7; // r11
  idDecl *v8; // r30
  int v9; // r29
  const char *FileName; // r28
  int v11; // r27
  const char *v12; // r3
  const idDeclVehicleProps *vehicleProps; // r30
  idStaticList<idVehicleKey::armorInfo_t,50> *p_armorInfo; // r21
  idVehicleKey::armorInfo_t *v15; // r4
  int v16; // r22
  int v17; // r26
  float v18; // r30
  int *v19; // r3
  int *v20; // r29
  int v21; // r27
  int v22; // r28
  float v23; // r30
  idJobManager *v24; // r3
  idJob *JobByDecl; // r3
  __int64 v26; // r10
  __int64 v27; // r11
  int v28; // r3
  const idVehicleKey::armorInfo_t *v29; // r4
  idJobManager *v30; // r3
  idJob *v31; // r3
  __int64 v32; // r10
  __int64 v33; // r11
  int v34; // r3
  float *v35; // r4
  int v36; // r24
  int i; // r25
  int v38; // r30
  const idDeclVehicleUpgrade *v39; // r28
  int v40; // r29
  int v41; // r26
  int v42; // r29
  float v43; // r30
  idJobManager *v44; // r3
  __int64 v45; // r10
  idJob *v46; // r3
  __int64 v47; // r11
  int v48; // r3
  float *v49; // r4
  float v50[2]; // [sp+50h] [-160h] BYREF
  float v51[2]; // [sp+58h] [-158h] BYREF
  float v52[2]; // [sp+60h] [-150h] BYREF
  __int64 v53; // [sp+68h] [-148h]
  __int64 v54; // [sp+70h] [-140h]
  _QWORD v55[3]; // [sp+78h] [-138h] BYREF
  idTypeInfoFile v56; // [sp+90h] [-120h] BYREF

  VehicleFromKey = idVehicleKey::GetVehicleFromKey(this);
  if ( VehicleFromKey != nullptr )
  {
    v5 = 0;
    v52[0] = *(float *)&this->equippedUpgrades.num;
    if ( SLODWORD(v52[0]) > 0 )
    {
      list = this->equippedUpgrades.list;
      v7 = 0;
      while ( list[v7]->upgradeType != UPGRADE_ARMOR )
      {
        ++v5;
        ++v7;
        if ( v5 >= SLODWORD(v52[0]) )
          goto LABEL_11;
      }
      v8 = &list[v5]->upgradedDef->idDecl;
      if ( v8 != nullptr )
      {
        idTypeInfoFile::idTypeInfoFile(this: &v56, indent_: 0);
        v9 = ((int (__fastcall *)(idDecl *))v8->__vftable[1].List)(a1: v8);
        FileName = idDecl::GetFileName(this: v8);
        v11 = ((int (__fastcall *)(idDecl *))v8->__vftable[1].Print)(a1: v8);
        v12 = (const char *)v8->__vftable[1].GetResourceList(this: v8);
        idTypeInfoFile::ReadMemory(this: &v56, data: v12, length: v11, name: FileName, startLine: v9);
        vehicleProps = VehicleFromKey->vehicleProps;
        idGameState::SetEntityEditState(entity: VehicleFromKey, file: &v56, includeDefVars: true);
        if ( VehicleFromKey->cleanUpVehicleProps )
          VehicleFromKey->vehicleProps = vehicleProps;
        idTypeInfoFile::~idTypeInfoFile(this: &v56);
      }
    }
LABEL_11:
    p_armorInfo = &this->armorInfo;
    if ( this->armorInfo.listStatic == 0 || this->armorInfo.listStatic == 2 )
    {
      v15 = p_armorInfo->list;
      if ( p_armorInfo->list != nullptr )
      {
        v52[0] = *(float *)&p_armorInfo->list;
        idMem::Free(this: &mem, ptr: v15, align: ALIGN_16);
      }
      p_armorInfo->list = nullptr;
      this->armorInfo.size = 0;
    }
    this->armorInfo.num = 0;
    v16 = 0;
    if ( VehicleFromKey->startingInventory.num > 0 )
    {
      v17 = 0;
      do
      {
        v18 = *(float *)&VehicleFromKey->startingInventory.list[v17].inventoryDecl;
        v19 = (int *)_RTDynamicCast(
                       inptr: (void *)LODWORD(v18),
                       VfDelta: 0,
                       SrcType: &idDeclInventory `RTTI Type Descriptor',
                       TargetType: &idDeclVehicleArmorKit `RTTI Type Descriptor',
                       isReference: 0);
        v20 = v19;
        if ( v19 != nullptr )
        {
          v21 = 0;
          if ( v19[127] > 0 )
          {
            v22 = 0;
            do
            {
              v23 = *(float *)(v22 + v20[126]);
              if ( *(_BYTE *)(LODWORD(v23) + 281) != 0 )
              {
                v24 = (idJobManager *)VehicleFromKey->GetInventory_2(this: VehicleFromKey);
                JobByDecl = idJobManager::FindJobByDecl(this: v24, jobDecl: (const idDeclJob *)LODWORD(v23));
                HIDWORD(v26) = initFromUpgrades;
                if ( !initFromUpgrades && *(_BYTE *)(LODWORD(v23) + 278) == 0 )
                {
                  if ( JobByDecl == nullptr )
                    goto LABEL_30;
                  v28 = ((int (__fastcall *)(idJob *))JobByDecl->__vftable[2].dtr_idClass)(a1: JobByDecl);
                  if ( *(_BYTE *)(LODWORD(v23) + 281) == 0 )
                    goto LABEL_30;
                  LODWORD(v27) = v28;
                  v52[0] = v23;
                  v29 = (const idVehicleKey::armorInfo_t *)v52;
                  v55[1] = v27;
                  v52[1] = (float)v27;
                  goto LABEL_29;
                }
                if ( *(_BYTE *)(LODWORD(v23) + 281) != 0 )
                {
                  v29 = (const idVehicleKey::armorInfo_t *)v55;
                  LODWORD(v26) = *(_DWORD *)(LODWORD(v23) + 336);
                  *(float *)v55 = v23;
                  v55[2] = v26;
                  *((float *)v55 + 1) = (float)v26;
LABEL_29:
                  idList<idVehicleKey::armorInfo_t,5>::Append(this: &this->armorInfo, obj: v29);
                }
              }
LABEL_30:
              ++v21;
              v22 += 4;
            }
            while ( v21 < v20[127] );
          }
        }
        else
        {
          if ( v18 == 0.0 || *(_BYTE *)(LODWORD(v18) + 281) == 0 )
            goto LABEL_42;
          v30 = (idJobManager *)VehicleFromKey->GetInventory_2(this: VehicleFromKey);
          v31 = idJobManager::FindJobByDecl(this: v30, jobDecl: (const idDeclJob *)LODWORD(v18));
          HIDWORD(v32) = initFromUpgrades;
          if ( !initFromUpgrades && *(_BYTE *)(LODWORD(v18) + 278) == 0 )
          {
            if ( v31 == nullptr )
              goto LABEL_42;
            v34 = ((int (__fastcall *)(idJob *))v31->__vftable[2].dtr_idClass)(a1: v31);
            if ( *(_BYTE *)(LODWORD(v18) + 281) == 0 )
              goto LABEL_42;
            LODWORD(v33) = v34;
            v50[0] = v18;
            v35 = v50;
            v54 = v33;
            v50[1] = (float)v33;
            goto LABEL_41;
          }
          if ( *(_BYTE *)(LODWORD(v18) + 281) != 0 )
          {
            v35 = v51;
            LODWORD(v32) = *(_DWORD *)(LODWORD(v18) + 336);
            v51[0] = v18;
            v53 = v32;
            v51[1] = (float)v32;
LABEL_41:
            idList<idVehicleKey::armorInfo_t,5>::Append(
              this: &this->armorInfo,
              obj: (const idVehicleKey::armorInfo_t *)v35);
          }
        }
LABEL_42:
        ++v16;
        ++v17;
      }
      while ( v16 < VehicleFromKey->startingInventory.num );
    }
    v36 = 0;
    if ( this->equippedUpgrades.num > 0 )
    {
      for ( i = 0; ; ++i )
      {
        v38 = 0;
        v39 = this->equippedUpgrades.list[i];
        if ( v39->removeDecl.num > 0 )
        {
          v40 = 0;
          do
          {
            idVehicleKey::RemoveArmorInfo(this, decl: v39->removeDecl.list[v40]);
            ++v38;
            ++v40;
          }
          while ( v38 < v39->removeDecl.num );
        }
        v41 = 0;
        if ( v39->appendDecl.num > 0 )
          break;
LABEL_59:
        if ( ++v36 >= this->equippedUpgrades.num )
          return;
      }
      v42 = 0;
      while ( 1 )
      {
        v43 = *(float *)&v39->appendDecl.list[v42];
        v44 = (idJobManager *)VehicleFromKey->GetInventory_2(this: VehicleFromKey);
        v46 = idJobManager::FindJobByDecl(this: v44, jobDecl: (const idDeclJob *)LODWORD(v43));
        if ( !initFromUpgrades && *(_BYTE *)(LODWORD(v43) + 278) == 0 )
          break;
        if ( *(_BYTE *)(LODWORD(v43) + 281) != 0 )
        {
          v49 = v50;
          LODWORD(v45) = *(_DWORD *)(LODWORD(v43) + 336);
          v50[0] = v43;
          v54 = v45;
          v50[1] = (float)v45;
LABEL_57:
          idList<idVehicleKey::armorInfo_t,5>::Append(
            this: &this->armorInfo,
            obj: (const idVehicleKey::armorInfo_t *)v49);
        }
LABEL_58:
        ++v41;
        ++v42;
        if ( v41 >= v39->appendDecl.num )
          goto LABEL_59;
      }
      if ( v46 == nullptr )
        goto LABEL_58;
      v48 = ((int (__fastcall *)(idJob *))v46->__vftable[2].dtr_idClass)(a1: v46);
      if ( *(_BYTE *)(LODWORD(v43) + 281) == 0 )
        goto LABEL_58;
      LODWORD(v47) = v48;
      v51[0] = v43;
      v49 = v51;
      v53 = v47;
      v51[1] = (float)v47;
      goto LABEL_57;
    }
  }
}


// ========================================================================
// __unwind$514345
// EA  : 0x82ECC0B4
// RVA : 0x00ECC0B4
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void _unwind_514345()
{
  int v0; // r12

  idTypeInfoFile::~idTypeInfoFile(this: (idTypeInfoFile *)(v0 - 432 + 144));
}


// ========================================================================
// ?DetermineFullUpgradeList@idVehicleKey@@QAAXXZ
// EA  : 0x82ECC0E0
// RVA : 0x00ECC0E0
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idVehicleKey::DetermineFullUpgradeList(idVehicleKey *this)
{
  idVehicle *VehicleFromKey; // r27
  __int64 v3; // r9 OVERLAPPED
  int v4; // r24
  int v5; // r28
  idDeclInventory *inventoryDecl; // r30
  int *v7; // r3
  int *v8; // r31
  int v9; // r29
  int v10; // r30
  int v11; // r11
  int count; // r10
  int v13; // r27
  int v14; // r28
  int v15; // r30
  const idDeclVehicleUpgrade *v16; // r31
  int v17; // r29
  int v18; // r29
  int v19; // r30
  idDeclInventory *v20; // r11
  idVehicleKey::armorInfo_t v21; // [sp+50h] [-80h] BYREF
  idVehicleKey::armorInfo_t v22[2]; // [sp+58h] [-78h] BYREF
  __int64 v23; // [sp+68h] [-68h]

  VehicleFromKey = idVehicleKey::GetVehicleFromKey(this);
  if ( VehicleFromKey != nullptr )
  {
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->upgradedArmorList);
    v4 = 0;
    if ( VehicleFromKey->startingInventory.num > 0 )
    {
      v5 = 0;
      do
      {
        inventoryDecl = (idDeclInventory *)VehicleFromKey->startingInventory.list[v5].inventoryDecl;
        v7 = (int *)_RTDynamicCast(
                      inptr: inventoryDecl,
                      VfDelta: 0,
                      SrcType: &idDeclInventory `RTTI Type Descriptor',
                      TargetType: &idDeclVehicleArmorKit `RTTI Type Descriptor',
                      isReference: 0);
        v8 = v7;
        if ( v7 != nullptr )
        {
          v9 = 0;
          if ( v7[127] > 0 )
          {
            v10 = 0;
            do
            {
              v11 = *(_DWORD *)(v8[126] + v10);
              if ( *(_BYTE *)(v11 + 281) != 0 )
              {
                LODWORD(v3) = *(_DWORD *)(v11 + 336);
                v21.decl = *(const idDeclInventory **)(v8[126] + v10);
                v22[1] = (idVehicleKey::armorInfo_t)v3;
                v21.health = (float)v3;
                idList<idVehicleKey::armorInfo_t,5>::Append(this: &this->upgradedArmorList, obj: &v21);
              }
              ++v9;
              v10 += 4;
            }
            while ( v9 < v8[127] );
          }
        }
        else if ( inventoryDecl != nullptr && inventoryDecl->vehicleArmor )
        {
          count = inventoryDecl->count;
          v22[0].decl = inventoryDecl;
          v23 = *(__int64 *)((char *)&v3 - 4);
          v22[0].health = (float)*(__int64 *)((char *)&v3 - 4);
          idList<idVehicleKey::armorInfo_t,5>::Append(this: &this->upgradedArmorList, obj: v22);
        }
        ++v4;
        ++v5;
      }
      while ( v4 < VehicleFromKey->startingInventory.num );
    }
    v13 = 0;
    if ( this->equippedUpgrades.num > 0 )
    {
      v14 = 0;
      do
      {
        v15 = 0;
        v16 = this->equippedUpgrades.list[v14];
        if ( v16->removeDecl.num > 0 )
        {
          v17 = 0;
          do
          {
            idVehicleKey::RemoveArmorInfo(this, decl: v16->removeDecl.list[v17]);
            ++v15;
            ++v17;
          }
          while ( v15 < v16->removeDecl.num );
        }
        v18 = 0;
        if ( v16->appendDecl.num > 0 )
        {
          v19 = 0;
          do
          {
            v20 = v16->appendDecl.list[v19];
            if ( v20->vehicleArmor )
            {
              LODWORD(v3) = v20->count;
              v22[0].decl = v16->appendDecl.list[v19];
              v23 = v3;
              v22[0].health = (float)v3;
              idList<idVehicleKey::armorInfo_t,5>::Append(this: &this->upgradedArmorList, obj: v22);
            }
            ++v18;
            ++v19;
          }
          while ( v18 < v16->appendDecl.num );
        }
        ++v13;
        ++v14;
      }
      while ( v13 < this->equippedUpgrades.num );
    }
  }
}


// ========================================================================
// ?SetValuesFromVehicle@idVehicleKey@@QAAXPBVidVehicle@@@Z
// EA  : 0x82ECC2F8
// RVA : 0x00ECC2F8
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __fastcall idVehicleKey::SetValuesFromVehicle(idVehicleKey *this, idVehicle *vehicle)
{
  idPhysics *Physics; // r3
  float *v5; // r3
  float v6; // r6
  double v7; // fp13
  idPhysics *v8; // r3
  int v9; // r3
  char *v10; // r10
  _DWORD *v11; // r11
  int i; // ctr
  double v13; // fp12
  double v14; // fp11
  double v15; // fp8
  double v16; // fp7
  double v17; // fp6
  idPresentable *presentable; // r3
  idPresentableVehicle *v19; // r3
  char v20; // [sp+5Ch] [-44h] BYREF
  float v21; // [sp+60h] [-40h]
  float v22; // [sp+64h] [-3Ch]
  float v23; // [sp+68h] [-38h]
  float v24; // [sp+6Ch] [-34h]
  float v25; // [sp+70h] [-30h]
  float v26; // [sp+74h] [-2Ch]
  float v27; // [sp+78h] [-28h]
  float v28; // [sp+7Ch] [-24h]
  float v29; // [sp+80h] [-20h]

  if ( vehicle != nullptr )
  {
    Physics = idEntity::GetPhysics(this: vehicle);
    v5 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
    v6 = v5[1];
    v7 = *v5;
    this->position.z = v5[2];
    this->position.y = v6;
    this->position.x = v7;
    v8 = idEntity::GetPhysics(this: vehicle);
    v9 = (int)v8->GetAxis(this: v8, a2: 0);
    v10 = &v20;
    v11 = (_DWORD *)(v9 - 4);
    for ( i = 9; i != 0; --i )
    {
      ++v11;
      v10 += 4;
      *(_DWORD *)v10 = *v11;
    }
    this->orientation.mat[0].x = v21;
    v13 = v22;
    v14 = v23;
    this->orientation.mat[1].x = v24;
    this->orientation.mat[0].y = v13;
    this->orientation.mat[0].z = v14;
    this->orientation.mat[1].y = v25;
    v15 = v27;
    this->orientation.mat[1].z = v26;
    v16 = v28;
    this->orientation.mat[2].x = v15;
    v17 = v29;
    this->orientation.mat[2].y = v16;
    this->orientation.mat[2].z = v17;
    this->health = vehicle->GetHealth(this: vehicle);
    this->maxHealth = vehicle->GetMaxHealth(this: vehicle);
    this->initArmorFromVehicle = false;
    presentable = vehicle->presentable;
    if ( presentable != nullptr )
      v19 = presentable->GetVehicleInterface(this: presentable);
    else
      v19 = nullptr;
    this->currentWeaponGroup = idPresentableVehicle::GetCurrentWeaponGroup(this: v19);
    idVehicleKey::SaveVehicleArmor(this, vehicle);
  }
  else
  {
    idLib::Warning(fmt: "NULL vehicle passed into idVehicleKey::SetValuesFromVehicle");
  }
}


// ========================================================================
// ?EquipUpgradeIfBetter@idVehicleKey@@QAAXPBVidVehicleUpgrade@@@Z
// EA  : 0x82ECC488
// RVA : 0x00ECC488
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __fastcall idVehicleKey::EquipUpgradeIfBetter(idVehicleKey *this, const idVehicleUpgrade *upgrade)
{
  const idDeclInventory *decl; // r6
  int num; // r8
  int v5; // r10
  const idDeclVehicleUpgrade **list; // r9
  int i; // r11
  idVehicle *VehicleFromKey; // r31

  if ( upgrade != nullptr )
  {
    decl = upgrade->decl;
    if ( decl != nullptr )
    {
      num = this->equippedUpgrades.num;
      v5 = 0;
      if ( num > 0 )
      {
        list = this->equippedUpgrades.list;
        for ( i = 0; (idDeclInventory_vtbl *)list[i]->upgradeType != decl[1].__vftable; ++i )
        {
          if ( ++v5 >= num )
            return;
        }
        if ( *((_DWORD *)&decl[1].idResource + 8) >= list[v5]->stage )
          list[v5] = (const idDeclVehicleUpgrade *)decl;
        VehicleFromKey = idVehicleKey::GetVehicleFromKey(this);
        if ( VehicleFromKey != nullptr )
        {
          idVehicleKey::UpdateArmorInfo(this, initFromUpgrades: true);
          idVehicle::SetArmorFromKey(this: VehicleFromKey, key: this);
          idVehicle::SetWeaponsFromKey(this: VehicleFromKey, key: this);
          idVehicle::SetThemeFromKey(this: VehicleFromKey, key: this);
        }
      }
    }
  }
}


// ========================================================================
// ?GetPickupHudInfo@idPlayerArmor@@UAAXPBVidEntity@@PAVidPickupHudInfo@@@Z
// EA  : 0x82ECC570
// RVA : 0x00ECC570
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __fastcall idPlayerArmor::GetPickupHudInfo(idPlayerArmor *this, idPlayer *user, idPickupHudInfo *info)
{
  idPickupHudInfo::item_t *v6; // r27
  idPlayer *v7; // r3
  int num; // r29
  idPlayer *v9; // r3
  idPlayer *v10; // r30
  idTungstenHealth *p_playerHealth; // r27
  double v12; // fp31

  v6 = idList<idPickupHudInfo::item_t,5>::Alloc(this: &info->items);
  v6->icon = this->decl->icon;
  v6->count = this->GetCount(this);
  v7 = user;
  v6->canPickup = true;
  num = info->items.num;
  info->items.list[num - 1].count = (int)this->curArmorValue;
  v9 = idPlayer::CastTo(c: v7);
  v10 = v9;
  if ( v9 != nullptr )
  {
    p_playerHealth = &v9->playerHealth;
    v12 = ((double (__fastcall *)(idTungstenHealth *, int))v9->playerHealth.GetComponentCur_Impl)(
            a1: &v9->playerHealth,
            a2: 1);
    if ( v12 < ((double (__fastcall *)(idTungstenHealth *, int))v10->playerHealth.GetComponentMax_Impl)(
                 a1: p_playerHealth,
                 a2: 1) )
      info->items.list[num - 1].canPickup = true;
  }
}


// ========================================================================
// ??0idVehicleKey@@QAA@XZ
// EA  : 0x82ECC7D8
// RVA : 0x00ECC7D8
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

idVehicleKey *__fastcall idVehicleKey::idVehicleKey(idVehicleKey *this)
{
  __int16 *p_granularity; // r10
  int v3; // ctr
  int v4; // ctr
  __int16 *v5; // r10

  idEventReceiver::idEventReceiver(this);
  this->decl = nullptr;
  this->count = 0;
  this->forSale = false;
  this->lootable = false;
  this->buyBackItem = false;
  this->alreadyDropped = false;
  this->quickSlot = -1;
  this->counttosave = -1;
  this->coolDownTime = 0;
  this->skinPreload = nullptr;
  this->__vftable = (idVehicleKey_vtbl *)&idVehicleKey::`vftable';
  this->performanceStats.acceleration = 0;
  this->performanceStats.suspension = 0;
  this->performanceStats.magnet = 0.0;
  this->performanceStats.traction = 0;
  this->performanceStats.armor = 0;
  this->equippedUpgrades.list = nullptr;
  this->equippedUpgrades.granularity = 0;
  this->equippedUpgrades.memTag = 5;
  this->equippedUpgrades.listStatic = 0;
  this->equippedUpgrades.size = 0;
  this->equippedUpgrades.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->equippedUpgrades);
  this->validUpgrades.granularity = 0;
  this->validUpgrades.memTag = 5;
  this->validUpgrades.listStatic = 0;
  this->validUpgrades.list = nullptr;
  this->validUpgrades.size = 0;
  this->validUpgrades.num = 0;
  this->baseParts.list = nullptr;
  this->baseParts.granularity = 0;
  this->baseParts.memTag = 5;
  this->baseParts.listStatic = 0;
  this->baseParts.size = 0;
  this->baseParts.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->baseParts);
  this->referenceVehicleName.len = 0;
  this->referenceVehicleName.allocedAndFlag = 20;
  this->referenceVehicleName.data = this->referenceVehicleName.baseBuffer;
  this->referenceVehicleName.baseBuffer[0] = 0;
  this->garageBay.spawnId.value = 0x1FFF;
  this->armorInfo.list = this->armorInfo.staticList;
  this->armorInfo.num = 0;
  p_granularity = &this->armorInfo.granularity;
  this->armorInfo.size = 50;
  v3 = 50;
  this->armorInfo.granularity = 1;
  this->armorInfo.memTag = 5;
  this->armorInfo.listStatic = 1;
  do
  {
    *((_DWORD *)p_granularity + 1) = 0;
    p_granularity += 4;
    *(float *)p_granularity = 0.0;
    --v3;
  }
  while ( v3 != 0 );
  this->upgradedArmorList.size = 50;
  this->upgradedArmorList.num = 0;
  this->upgradedArmorList.granularity = 1;
  this->upgradedArmorList.memTag = 5;
  v4 = 50;
  this->upgradedArmorList.list = this->upgradedArmorList.staticList;
  v5 = &this->upgradedArmorList.granularity;
  this->upgradedArmorList.listStatic = 1;
  do
  {
    *((_DWORD *)v5 + 1) = 0;
    v5 += 4;
    *(float *)v5 = 0.0;
    --v4;
  }
  while ( v4 != 0 );
  this->repairCost = 0.0;
  this->prestige = PRESTIGE_BRONZE;
  this->upgradeAvailable = false;
  this->enterVehicle = false;
  this->vehicleGarage = GARAGE_WELLSPRING;
  this->shouldGarageView = false;
  this->health = -1.0;
  this->maxHealth = -1.0;
  this->position = vec3_origin;
  this->orientation = mat3_identity;
  this->initArmorFromVehicle = true;
  this->currentWeaponGroup = -1;
  this->doTotalRepairOnSpawn = false;
  this->numVehicleKills = 0;
  return this;
}


// ========================================================================
// __unwind$514908
// EA  : 0x82ECCA34
// RVA : 0x00ECCA34
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void _unwind_514908()
{
  int v0; // r12

  idInventoryItem::~idInventoryItem(this: *(idInventoryItem **)(v0 - 144 + 164));
}


// ========================================================================
// __unwind$514909
// EA  : 0x82ECCA5C
// RVA : 0x00ECCA5C
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void _unwind_514909()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 84));
}


// ========================================================================
// __unwind$514910
// EA  : 0x82ECCA88
// RVA : 0x00ECCA88
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void _unwind_514910()
{
  int v0; // r12

  idList<idAAS2DebugAreaModelData::debugAreaInfo_t,5>::Clear(this: (idList<idList<idPlaytestStorage::ai2BreadCrumbInfo_t,5>,5> *)(*(_DWORD *)(v0 - 144 + 164) + 108));
}


// ========================================================================
// ?EquipBaseParts@idVehicleKey@@QAAXXZ
// EA  : 0x82ECCAC0
// RVA : 0x00ECCAC0
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __fastcall idVehicleKey::EquipBaseParts(idVehicleKey *this)
{
  idList<idGuiListBox::row_t,5> *p_validUpgrades; // r30
  int v3; // r29
  int i; // r28
  int v5; // r8
  int v6; // r7
  int v7; // r6
  int v8; // [sp+8h] [-158h]
  int v9; // [sp+Ch] [-154h]
  int v10; // [sp+10h] [-150h]
  int v11; // [sp+14h] [-14Ch]
  int v12; // [sp+18h] [-148h]
  const idDeclVehicleUpgrade *v13; // [sp+1Ch] [-144h]
  validUpgradeLists_t v14; // [sp+50h] [-110h] BYREF

  p_validUpgrades = (idList<idGuiListBox::row_t,5> *)&this->validUpgrades;
  v3 = 0;
  if ( this->validUpgrades.listStatic == 0 || this->validUpgrades.listStatic == 2 )
  {
    if ( p_validUpgrades->list != nullptr )
      idListArrayDelete<idList<idDeclVehicleUpgrade const *,5>>(
        ptr: (char *)this->validUpgrades.list,
        num: this->validUpgrades.size);
    p_validUpgrades->list = nullptr;
    p_validUpgrades->size = 0;
  }
  p_validUpgrades->num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->baseParts);
  validUpgradeLists_t::validUpgradeLists_t(this: &v14, __that: (const idList<idMD6Node *,5> *)&this->decl[1].name);
  if ( v14.suspensionUpgrades.num != 0 )
    idList<idGuiListBox::row_t,5>::Append(
      this: p_validUpgrades,
      obj: (const idList<idMD6Node *,5> *)&v14.suspensionUpgrades);
  if ( v14.tireUpgrades.num != 0 )
    idList<idGuiListBox::row_t,5>::Append(this: p_validUpgrades, obj: (const idList<idMD6Node *,5> *)&v14);
  if ( v14.armorUpgrades.num != 0 )
    idList<idGuiListBox::row_t,5>::Append(this: p_validUpgrades, obj: (const idList<idMD6Node *,5> *)&v14.armorUpgrades);
  if ( v14.frontGrillUpgrades.num != 0 )
    idList<idGuiListBox::row_t,5>::Append(
      this: p_validUpgrades,
      obj: (const idList<idMD6Node *,5> *)&v14.frontGrillUpgrades);
  if ( v14.themeUpgrades.num != 0 )
    idList<idGuiListBox::row_t,5>::Append(this: p_validUpgrades, obj: (const idList<idMD6Node *,5> *)&v14.themeUpgrades);
  if ( v14.weaponUpgrades.num != 0 )
    idList<idGuiListBox::row_t,5>::Append(
      this: p_validUpgrades,
      obj: (const idList<idMD6Node *,5> *)&v14.weaponUpgrades);
  if ( v14.flagUpgrades.num != 0 )
    idList<idGuiListBox::row_t,5>::Append(this: p_validUpgrades, obj: (const idList<idMD6Node *,5> *)&v14.flagUpgrades);
  if ( v14.exhaustUpgrades.num != 0 )
    idList<idGuiListBox::row_t,5>::Append(
      this: p_validUpgrades,
      obj: (const idList<idMD6Node *,5> *)&v14.exhaustUpgrades);
  if ( v14.superChargerUpgrades.num != 0 )
    idList<idGuiListBox::row_t,5>::Append(
      this: p_validUpgrades,
      obj: (const idList<idMD6Node *,5> *)&v14.superChargerUpgrades);
  if ( v14.boosterUpgrades.num != 0 )
    idList<idGuiListBox::row_t,5>::Append(
      this: p_validUpgrades,
      obj: (const idList<idMD6Node *,5> *)&v14.boosterUpgrades);
  if ( v14.magnetUpgrades.num != 0 )
    idList<idGuiListBox::row_t,5>::Append(
      this: p_validUpgrades,
      obj: (const idList<idMD6Node *,5> *)&v14.magnetUpgrades);
  if ( v14.transmissionUpgrades.num != 0 )
    idList<idGuiListBox::row_t,5>::Append(
      this: p_validUpgrades,
      obj: (const idList<idMD6Node *,5> *)&v14.transmissionUpgrades);
  if ( v14.tireRipperUpgrades.num != 0 )
    idList<idGuiListBox::row_t,5>::Append(
      this: p_validUpgrades,
      obj: (const idList<idMD6Node *,5> *)&v14.tireRipperUpgrades);
  for ( i = 0; i < this->validUpgrades.num; ++v3 )
  {
    idList<idAnimWebBlendTree *,5>::Append(
      this: (idList<enum encounterGroupRole_t,5> *)&this->baseParts,
      obj: (encounterGroupRole_t *)p_validUpgrades->list[v3].cells.list);
    idVehicleKey::EquipUpgrade(
      this,
      upgrade: *(const idDeclVehicleUpgrade **)p_validUpgrades->list[v3].cells.list,
      init: true,
      a4: v7,
      a5: v6,
      a6: v5,
      a7: (int)p_validUpgrades->list[v3].cells.list,
      a8: (int)p_validUpgrades->list,
      a9: v8,
      a10: v9,
      a11: v10,
      a12: v11,
      a13: v12,
      a14: v13);
    ++i;
  }
  validUpgradeLists_t::~validUpgradeLists_t(this: &v14);
}


// ========================================================================
// __unwind$515203
// EA  : 0x82ECCCC0
// RVA : 0x00ECCCC0
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void _unwind_515203()
{
  int v0; // r12

  validUpgradeLists_t::~validUpgradeLists_t(this: (validUpgradeLists_t *)(v0 - 352 + 80));
}


// ========================================================================
// ?SkipFromFile@idVehicleKey@@SAXPAVidFile@@@Z
// EA  : 0x82ECCCF0
// RVA : 0x00ECCCF0
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __fastcall idVehicleKey::SkipFromFile(idFile *file)
{
  idVehicleKey v2; // [sp+50h] [-440h] BYREF

  idVehicleKey::idVehicleKey(this: &v2);
  idVehicleKey::InternalReadFromFile(this: &v2, file, allocResources: false);
  idVehicleKey::~idVehicleKey(this: &v2);
}


// ========================================================================
// __unwind$515302
// EA  : 0x82ECCD44
// RVA : 0x00ECCD44
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void _unwind_515302()
{
  int v0; // r12

  idVehicleKey::~idVehicleKey(this: (idVehicleKey *)(v0 - 1168 + 80));
}


// ========================================================================
// ?Init@idVehicleKey@@UAAXPBVidDeclInventory@@@Z
// EA  : 0x82ECCDD0
// RVA : 0x00ECCDD0
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __fastcall idVehicleKey::Init(idVehicleKey *this, const idDeclInventory *decl)
{
  this->decl = decl;
  this->count = decl->count;
  this->forSale = false;
  this->lootable = false;
  this->counttosave = -1;
  this->decl = decl;
  this->count = decl->count;
  this->forSale = false;
  this->lootable = false;
  idVehicleKey::EquipBaseParts(this);
}


// ========================================================================
// `dynamic initializer for 'g_infiniteAmmo''
// EA  : 0x83392FE0
// RVA : 0x01392FE0
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_infiniteAmmo__()
{
  idCVar::idCVar(
    this: &g_infiniteAmmo,
    name: "g_infiniteAmmo",
    value: "0",
    flags: 1,
    description: "1 = infinite ammunition",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_infiniteAmmo__);
}


// ========================================================================
// `dynamic initializer for 'g_permaInfiniteAmmo''
// EA  : 0x83393038
// RVA : 0x01393038
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_permaInfiniteAmmo__()
{
  idCVar::idCVar(
    this: &g_permaInfiniteAmmo,
    name: "g_permaInfiniteAmmo",
    value: "0",
    flags: 1,
    description: "1 = infinite ammunition (saved in config)",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_permaInfiniteAmmo__);
}


// ========================================================================
// `dynamic initializer for 'g_debugLaserSight''
// EA  : 0x83393090
// RVA : 0x01393090
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_debugLaserSight__()
{
  idCVar::idCVar(
    this: &g_debugLaserSight,
    name: "g_debugLaserSight",
    value: "0",
    flags: 1,
    description: "if true draws debug info for the player/ai laser sight",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_debugLaserSight__);
}


// ========================================================================
// `dynamic initializer for 'g_weaponUpdateLaser''
// EA  : 0x833930E8
// RVA : 0x013930E8
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_weaponUpdateLaser__()
{
  idCVar::idCVar(
    this: &g_weaponUpdateLaser,
    name: "g_weaponUpdateLaser",
    value: "1",
    flags: 1,
    description: "if true will update the laser",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_weaponUpdateLaser__);
}


// ========================================================================
// `dynamic initializer for 'g_weaponShowRibbon''
// EA  : 0x83393140
// RVA : 0x01393140
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_weaponShowRibbon__()
{
  idCVar::idCVar(
    this: &g_weaponShowRibbon,
    name: "g_weaponShowRibbon",
    value: "0",
    flags: 1,
    description: "if this should show the ribbon",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_weaponShowRibbon__);
}


// ========================================================================
// `dynamic initializer for 'g_clientDrop_debug''
// EA  : 0x83393198
// RVA : 0x01393198
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_clientDrop_debug__()
{
  idCVar::idCVar(
    this: &g_clientDrop_debug,
    name: "g_clientDrop_debug",
    value: "0",
    flags: 1,
    description: "if this should show the ribbon",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_clientDrop_debug__);
}


// ========================================================================
// `dynamic initializer for 'g_clientDrop_Dist''
// EA  : 0x833931F0
// RVA : 0x013931F0
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_clientDrop_Dist__()
{
  idCVar::idCVar(
    this: &g_clientDrop_Dist,
    name: "g_clientDrop_Dist",
    value: "110",
    flags: 4,
    description: "if this should show the ribbon",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_clientDrop_Dist__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_jump_angle''
// EA  : 0x83393248
// RVA : 0x01393248
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_jump_angle__()
{
  idCVar::idCVar(
    this: &vehicle_jump_angle,
    name: "vehicle_jump_angle",
    value: "90",
    flags: 4,
    description: "forward to jump impulse angle. 90 for vertical jump",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_jump_angle__);
}


// ========================================================================
// `dynamic initializer for 'aftershock_impulse_max''
// EA  : 0x833932A0
// RVA : 0x013932A0
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__aftershock_impulse_max__()
{
  idCVar::idCVar(
    this: &aftershock_impulse_max,
    name: "aftershock_impulse_max",
    value: "4000000",
    flags: 4,
    description: "max impulse strength for aftershock",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__aftershock_impulse_max__);
}


// ========================================================================
// `dynamic initializer for 'aftershock_impulse_min''
// EA  : 0x833932F8
// RVA : 0x013932F8
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__aftershock_impulse_min__()
{
  idCVar::idCVar(
    this: &aftershock_impulse_min,
    name: "aftershock_impulse_min",
    value: "3000000",
    flags: 4,
    description: "min impulse strength for aftershock (at the radius's edge)",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__aftershock_impulse_min__);
}


// ========================================================================
// `dynamic initializer for 'aftershock_radius''
// EA  : 0x83393350
// RVA : 0x01393350
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__aftershock_radius__()
{
  idCVar::idCVar(
    this: &aftershock_radius,
    name: "aftershock_radius",
    value: "800",
    flags: 4,
    description: "affected radius",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__aftershock_radius__);
}


// ========================================================================
// `dynamic initializer for 'aftershock_offset''
// EA  : 0x833933A8
// RVA : 0x013933A8
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__aftershock_offset__()
{
  idCVar::idCVar(
    this: &aftershock_offset,
    name: "aftershock_offset",
    value: "40",
    flags: 4,
    description: "how far from the center of mass of the car should the impulse be applied (for flipping effect)",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__aftershock_offset__);
}


// ========================================================================
// `dynamic initializer for 'aftershock_angle''
// EA  : 0x83393400
// RVA : 0x01393400
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__aftershock_angle__()
{
  idCVar::idCVar(
    this: &aftershock_angle,
    name: "aftershock_angle",
    value: "60",
    flags: 4,
    description: "the angle of the impulse against the horizontal plane",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__aftershock_angle__);
}


// ========================================================================
// `dynamic initializer for 'aftershock_skipPredict''
// EA  : 0x83393458
// RVA : 0x01393458
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__aftershock_skipPredict__()
{
  idCVar::idCVar(
    this: &aftershock_skipPredict,
    name: "aftershock_skipPredict",
    value: "1",
    flags: 1,
    description: "skip prediction of the aftershock",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__aftershock_skipPredict__);
}


// ========================================================================
// `dynamic initializer for 'g_weaponSkipSound''
// EA  : 0x833934B0
// RVA : 0x013934B0
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_weaponSkipSound__()
{
  idCVar::idCVar(
    this: &g_weaponSkipSound,
    name: "g_weaponSkipSound",
    value: "0",
    flags: 1,
    description: "if true will skip fire sounds.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_weaponSkipSound__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_shockwaveDuration''
// EA  : 0x83393508
// RVA : 0x01393508
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_shockwaveDuration__()
{
  idCVar::idCVar(
    this: &vehicle_shockwaveDuration,
    name: "vehicle_shockwaveDuration",
    value: "5000",
    flags: 2,
    description: "duration of vehicle shockwave in MS",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_shockwaveDuration__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_aftershockerDuration''
// EA  : 0x83393560
// RVA : 0x01393560
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_aftershockerDuration__()
{
  idCVar::idCVar(
    this: &vehicle_aftershockerDuration,
    name: "vehicle_aftershockerDuration",
    value: "500",
    flags: 2,
    description: "duration of vehicle aftershocker in MS",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_aftershockerDuration__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_aftershockerMaxVelocity''
// EA  : 0x833935B8
// RVA : 0x013935B8
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_aftershockerMaxVelocity__()
{
  idCVar::idCVar(
    this: &vehicle_aftershockerMaxVelocity,
    name: "vehicle_aftershockerMaxVelocity",
    value: "4000",
    flags: 4,
    description: "max velocity of aftershocker (scaled down based on distance)",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_aftershockerMaxVelocity__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_aftershockerMaxAngularVelocity''
// EA  : 0x83393610
// RVA : 0x01393610
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_aftershockerMaxAngularVelocity__()
{
  idCVar::idCVar(
    this: &vehicle_aftershockerMaxAngularVelocity,
    name: "vehicle_aftershockerMaxAngularVelocity",
    value: "16",
    flags: 4,
    description: "max angular velocity of aftershocker (scaled down based on distance)",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_aftershockerMaxAngularVelocity__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_megabooster_force''
// EA  : 0x83393668
// RVA : 0x01393668
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_megabooster_force__()
{
  idCVar::idCVar(
    this: &vehicle_megabooster_force,
    name: "vehicle_megabooster_force",
    value: "5000000",
    flags: 4,
    description: "megabooster force",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_megabooster_force__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_megabooster_time''
// EA  : 0x833936C0
// RVA : 0x013936C0
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_megabooster_time__()
{
  idCVar::idCVar(
    this: &vehicle_megabooster_time,
    name: "vehicle_megabooster_time",
    value: "1000",
    flags: 2,
    description: "megabooster time",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_megabooster_time__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_health_amount''
// EA  : 0x83393718
// RVA : 0x01393718
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_health_amount__()
{
  idCVar::idCVar(
    this: &vehicle_health_amount,
    name: "vehicle_health_amount",
    value: "0.3",
    flags: 4,
    description: "vehicle health recharge percentage",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_health_amount__);
}


// ========================================================================
// `dynamic initializer for 'mp_vehicle_health_amount''
// EA  : 0x83393770
// RVA : 0x01393770
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__mp_vehicle_health_amount__()
{
  idCVar::idCVar(
    this: &mp_vehicle_health_amount,
    name: "mp_vehicle_health_amount",
    value: "0.5",
    flags: 4,
    description: "vehicle health recharge percentage",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__mp_vehicle_health_amount__);
}


// ========================================================================
// `dynamic initializer for 'vehicle_stomp_verticalImpulse''
// EA  : 0x833937C8
// RVA : 0x013937C8
// PDB : w:\tech5\tungsten\game\weapons\inventoryitem.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vehicle_stomp_verticalImpulse__()
{
  idCVar::idCVar(
    this: &vehicle_stomp_verticalImpulse,
    name: "vehicle_stomp_verticalImpulse",
    value: "-8000000",
    flags: 4,
    description: "stomp vertical impulse",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vehicle_stomp_verticalImpulse__);
}

