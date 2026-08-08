
// ========================================================================
// ?Clear@idHudPickupInfo@@QAAXXZ
// EA  : 0x8256F998
// RVA : 0x0056F998
// PDB : w:\tech5\tungsten\game\clientgame\playerhud\playerhud_info.h
// ========================================================================

void __fastcall idHudPickupInfo::Clear(idHudPickupInfo *this)
{
  char v1; // r10
  idStr v3[2]; // [sp+50h] [-40h] BYREF

  v1 = *(_BYTE *)this & 3 | 0x10;
  this->markShown = true;
  this->count = 0;
  *(_BYTE *)this = v1;
  this->wait = 0;
  this->index = 0;
  this->itemType = 0;
  v3[0].allocedAndFlag = 20;
  v3[0].data = v3[0].baseBuffer;
  v3[0].len = 0;
  v3[0].baseBuffer[0] = 0;
  idStr::EnsureAlloced(this: &this->icon, amount: 1, keepold: false, geometricGrowth: false);
  *this->icon.data = 0;
  this->icon.len = 0;
  idStr::FreeData(this: v3);
  this->displayName.index = -1;
}


// ========================================================================
// __unwind$645846
// EA  : 0x8256FA24
// RVA : 0x0056FA24
// PDB : w:\tech5\tungsten\game\clientgame\playerhud\playerhud_info.h
// ========================================================================

void _unwind_645846()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 144 + 80));
}


// ========================================================================
// ??0idHudPickupInfo@@QAA@XZ
// EA  : 0x82582EB0
// RVA : 0x00582EB0
// PDB : w:\tech5\tungsten\game\clientgame\playerhud\playerhud_info.h
// ========================================================================

idHudPickupInfo *__fastcall idHudPickupInfo::idHudPickupInfo(idHudPickupInfo *this)
{
  this->icon.len = 0;
  this->icon.allocedAndFlag = 20;
  this->icon.data = this->icon.baseBuffer;
  this->icon.baseBuffer[0] = 0;
  this->displayName.index = -1;
  idHudPickupInfo::Clear(this);
  return this;
}


// ========================================================================
// __unwind$667923
// EA  : 0x82582F20
// RVA : 0x00582F20
// PDB : w:\tech5\tungsten\game\clientgame\playerhud\playerhud_info.h
// ========================================================================

void _unwind_667923()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 20));
}


// ========================================================================
// ??0idHudInfo@@QAA@XZ
// EA  : 0x82B7B3F8
// RVA : 0x00B7B3F8
// PDB : w:\tech5\tungsten\game\clientgame\playerhud\playerhud_info.h
// ========================================================================

idHudInfo *__fastcall idHudInfo::idHudInfo(idHudInfo *this)
{
  this->damageLocator.direction.y = 0.0;
  this->damageLocator.direction.x = 0.0;
  this->damageLocator.intensity = 0.0;
  this->airSupply.show = false;
  this->airSupply.percent = 1.0;
  this->healthIndicator.health = 1.0;
  this->healthIndicator.armor = 0.0;
  this->reticle.show = false;
  this->reticle.pulsate = false;
  this->reticle.useAmount = -1.0;
  this->reticle.iconIndex = -1;
  this->interact.icons.size = 3;
  this->interact.icons.num = 0;
  this->interact.icons.granularity = 1;
  this->interact.icons.list = this->interact.icons.staticList;
  this->interact.icons.memTag = 5;
  this->interact.icons.listStatic = 1;
  this->interact.icons.staticList[0].material = nullptr;
  this->interact.icons.staticList[0].usable = true;
  this->interact.icons.staticList[0].itemCount = 0;
  this->interact.icons.staticList[1].material = nullptr;
  this->interact.icons.staticList[1].usable = true;
  this->interact.icons.staticList[1].itemCount = 0;
  this->interact.icons.staticList[2].material = nullptr;
  this->interact.icons.staticList[2].usable = true;
  this->interact.icons.staticList[2].itemCount = 0;
  this->interact.useCheckbox = false;
  idStaticList<idCrosshairCombinerInfo,3>::idStaticList<idCrosshairCombinerInfo,3>(this: &this->combiners);
  this->weaponAmmoStatus[0].show = false;
  this->weaponAmmoStatus[0].staticCounter = false;
  this->weaponAmmoStatus[0].nextAnimState = 0;
  this->weaponAmmoStatus[0].ammoClipCount = 0;
  this->weaponAmmoStatus[0].ammoTotalCount = 0;
  this->weaponAmmoStatus[0].burstMode = BURSTMODE_FULLAUTO;
  this->weaponAmmoStatus[0].dwAvailable = false;
  this->weaponAmmoStatus[0].renderReceipt = false;
  this->weaponAmmoStatus[1].show = false;
  this->weaponAmmoStatus[1].staticCounter = false;
  this->weaponAmmoStatus[1].nextAnimState = 0;
  this->weaponAmmoStatus[1].ammoClipCount = 0;
  this->weaponAmmoStatus[1].ammoTotalCount = 0;
  this->weaponAmmoStatus[1].burstMode = BURSTMODE_FULLAUTO;
  this->weaponAmmoStatus[1].dwAvailable = false;
  this->weaponAmmoStatus[1].renderReceipt = false;
  this->weaponAmmoStatus[2].show = false;
  this->weaponAmmoStatus[2].staticCounter = false;
  this->weaponAmmoStatus[2].nextAnimState = 0;
  this->weaponAmmoStatus[2].ammoClipCount = 0;
  this->weaponAmmoStatus[2].ammoTotalCount = 0;
  this->weaponAmmoStatus[2].burstMode = BURSTMODE_FULLAUTO;
  this->weaponAmmoStatus[2].dwAvailable = false;
  this->weaponAmmoStatus[2].renderReceipt = false;
  this->weaponAmmoStatus[3].show = false;
  this->weaponAmmoStatus[3].staticCounter = false;
  this->weaponAmmoStatus[3].nextAnimState = 0;
  this->weaponAmmoStatus[3].ammoClipCount = 0;
  this->weaponAmmoStatus[3].ammoTotalCount = 0;
  this->weaponAmmoStatus[3].burstMode = BURSTMODE_FULLAUTO;
  this->weaponAmmoStatus[3].dwAvailable = false;
  this->weaponAmmoStatus[3].renderReceipt = false;
  this->laserCutterStatus.charge = 0.0;
  this->laserCutterStatus.canShoot = false;
  this->laserCutterStatus.show = false;
  this->laserCutterStatus.nextAnimState = 0;
  this->laserCutterStatus.cuttingMode = true;
  this->laserCutterStatus.shootingFullAuto = false;
  this->laserCutterFuncLensStatus.showPrim = false;
  this->laserCutterFuncLensStatus.showSec = false;
  this->laserCutterFuncLensStatus.showStatic = false;
  this->laserCutterFuncLensStatus.nextAnimState = 0;
  this->laserCutterFuncLensStatus.iconPrim = FUNCTIONALITY_LENS_ZOOM;
  this->laserCutterFuncLensStatus.iconSec = FUNCTIONALITY_LENS_ZOOM;
  this->laserCutterFuncLensStatus.iconStatic = FUNCTIONALITY_LENS_ZOOM;
  this->minigame.action = 0;
  this->minigame.type = -1;
  this->minigame.level = -1;
  this->minigame.showHelp = false;
  this->help.show = false;
  this->help.icon = nullptr;
  this->help.buttonImage = nullptr;
  this->boss.amount = 0.0;
  this->boss.numBars = 0;
  this->boss.visibleBars = 0;
  this->showBottomBar = true;
  this->showJournalIcon = false;
  return this;
}

