
// ========================================================================
// ?BeforeUse@idProp_BatteryChargePoint@@UAA_NPAVidEntity@@@Z
// EA  : 0x82C0B370
// RVA : 0x00C0B370
// PDB : w:\tech5\tungsten\game\entities\batterychargepoint.cpp
// ========================================================================

int __fastcall idProp_BatteryChargePoint::BeforeUse(idProp_BatteryChargePoint *this, idPlayer *activator)
{
  idPlayer *v4; // r3
  idPlayer *v5; // r31
  idInventoryCollection *v7; // r3
  idInventoryCollection *v8; // r3

  v4 = idPlayer::CastTo(c: activator);
  v5 = v4;
  if ( v4 == nullptr )
    return 0;
  v7 = v4->GetInventory_2(this: v4);
  if ( idInventoryCollection::FindInventoryItemByName(this: v7, internalName: "lasercutter") == nullptr )
  {
    v8 = v5->GetInventory_2(this: v5);
    if ( idInventoryCollection::FindInventoryItemByName(this: v8, internalName: "laserkraftwerk") == nullptr )
      return 0;
  }
  if ( !idProp_ContinuallyUsed::BeforeUse(this, activator) )
    return 0;
  this->lastChargetTime = -1;
  this->curChargeAmount = 0.0;
  return 1;
}


// ========================================================================
// ?Use@idProp_BatteryChargePoint@@UAA_NPAVidEntity@@W4usableState_t@@@Z
// EA  : 0x82C0B430
// RVA : 0x00C0B430
// PDB : w:\tech5\tungsten\game\entities\batterychargepoint.cpp
// ========================================================================

int __fastcall idProp_BatteryChargePoint::Use(
        idProp_BatteryChargePoint *this,
        idPlayer *activator,
        usableState_t usable)
{
  idPlayer *v6; // r3
  idActor *v7; // r31
  idLaserCutter *v8; // r3
  idLaserCutter *v9; // r3

  if ( !idProp_ContinuallyUsed::Use(this, activator, usable) )
    return 0;
  idEntity::BecomeInactive(this, flags: 1);
  v6 = idPlayer::CastTo(c: activator);
  v7 = v6;
  if ( v6 != nullptr )
  {
    v8 = (idLaserCutter *)v6->GetEquippedWeapon(this: v6);
    v9 = idLaserCutter::CastTo(c: v8);
    if ( v9 != nullptr )
      idLaserCutter::SetChargingEffects(this: v9, activate: false, actor: v7);
  }
  return 1;
}


// ========================================================================
// ?ModifyCrosshairInfo@idProp_BatteryChargePoint@@UBA_NPBVidEntity@@ABVidFocusTrace@@W4usableState_t@@AAVidCrosshairInfo@@@Z
// EA  : 0x82C0B4C8
// RVA : 0x00C0B4C8
// PDB : w:\tech5\tungsten\game\entities\batterychargepoint.cpp
// ========================================================================

BOOL __fastcall idProp_BatteryChargePoint::ModifyCrosshairInfo(
        idProp_BatteryChargePoint *this,
        const idEntity *activator,
        const idFocusTrace *ft,
        usableState_t usable,
        idCrosshairInfo *info)
{
  BOOL result; // r3

  result = idProp_ContinuallyUsed::ModifyCrosshairInfo(this, activator, ft, usable, info);
  info->useAmount = -1.0;
  return result;
}


// ========================================================================
// ?GetUsableState@idPlayerControlled@@UBA?AW4usableState_t@@PBVidEntity@@ABVidFocusTrace@@@Z
// EA  : 0x82C0B500
// RVA : 0x00C0B500
// PDB : w:\tech5\tungsten\game\entities\batterychargepoint.cpp
// ========================================================================

int __fastcall idPlayerControlled::GetUsableState(
        idProp_BatteryChargePoint *this,
        const idEntity *activator,
        const idFocusTrace *ft)
{
  return (*(_BYTE *)&this->flags & 8) == 0 ? 0 : 3;
}


// ========================================================================
// ?Hide@idProp_BatteryChargePoint@@UAAXXZ
// EA  : 0x82C0B520
// RVA : 0x00C0B520
// PDB : w:\tech5\tungsten\game\entities\batterychargepoint.cpp
// ========================================================================

void __fastcall idProp_BatteryChargePoint::Hide(idProp_BatteryChargePoint *this)
{
  idPresentable *presentable; // r11

  idEntity::Hide(this);
  if ( this->loopingSound != nullptr )
  {
    presentable = this->presentable;
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      presentable = this->presentable;
    }
    idPresentable::StopSound(this: presentable, channel: SND_CHANNEL_GENERIC_AMBIENT, peerMask: 0);
  }
}


// ========================================================================
// ?Show@idProp_BatteryChargePoint@@UAAXXZ
// EA  : 0x82C0B580
// RVA : 0x00C0B580
// PDB : w:\tech5\tungsten\game\entities\batterychargepoint.cpp
// ========================================================================

void __fastcall idProp_BatteryChargePoint::Show(idProp_BatteryChargePoint *this)
{
  idPresentable *presentable; // r3

  idEntity::Show(this);
  if ( this->loopingSound != nullptr )
  {
    presentable = this->presentable;
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      presentable = this->presentable;
    }
    idPresentable::StartSoundShader(
      this: presentable,
      channel: SND_CHANNEL_GENERIC_AMBIENT,
      shader: this->loopingSound,
      soundShaderFlags: SSF_LOOPING,
      peerMask: 0);
  }
}


// ========================================================================
// ?Spawn@idProp_BatteryChargePoint@@QAAXXZ
// EA  : 0x82C0B5E8
// RVA : 0x00C0B5E8
// PDB : w:\tech5\tungsten\game\entities\batterychargepoint.cpp
// ========================================================================

void __fastcall idProp_BatteryChargePoint::Spawn(idProp_BatteryChargePoint *this)
{
  idPresentable *presentable; // r3

  if ( (unsigned __int8)Get_idCombatStage_useRelaxedChatterVO(ptr: this) == 0 && this->loopingSound != nullptr )
  {
    presentable = this->presentable;
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      presentable = this->presentable;
    }
    idPresentable::StartSoundShader(
      this: presentable,
      channel: SND_CHANNEL_GENERIC_AMBIENT,
      shader: this->loopingSound,
      soundShaderFlags: SSF_LOOPING,
      peerMask: 0);
    idEntity::UpdateVisuals(this);
  }
}


// ========================================================================
// ?GetSoundTransform@idProp_BatteryChargePoint@@UBAXAAVidVec3@@AAVidMat3@@@Z
// EA  : 0x82C0B660
// RVA : 0x00C0B660
// PDB : w:\tech5\tungsten\game\entities\batterychargepoint.cpp
// ========================================================================

void __fastcall idProp_BatteryChargePoint::GetSoundTransform(
        idProp_BatteryChargePoint *this,
        idVec3 *soundOrigin,
        idMat3 *soundAxis)
{
  idMat3 v5; // [sp+50h] [-40h] BYREF

  idEntity::GetSoundTransform(this, soundOrigin, soundAxis);
  *soundAxis = *idMat3::operator*(this: &v5, result: &this->soundTransform, a: soundAxis);
  idMat3::OrthoNormalizeSelf(this: soundAxis);
}


// ========================================================================
// ??0idProp_BatteryChargePoint@@QAA@XZ
// EA  : 0x82C0B840
// RVA : 0x00C0B840
// PDB : w:\tech5\tungsten\game\entities\batterychargepoint.cpp
// ========================================================================

idProp_BatteryChargePoint *__fastcall idProp_BatteryChargePoint::idProp_BatteryChargePoint(
        idProp_BatteryChargePoint *this)
{
  idTypesafeNumber<float,enum RadiansUnique_t> v3; // [sp+50h] [-30h] BYREF
  idVec3 v4; // [sp+58h] [-28h] BYREF

  idProp_ContinuallyUsed::idProp_ContinuallyUsed(this);
  this->curChargeAmount = 0.0;
  this->chargePerSecond = 0.0;
  this->lastChargetTime = -1;
  this->loopingSound = nullptr;
  this->__vftable = (idProp_BatteryChargePoint_vtbl *)&idProp_BatteryChargePoint::`vftable';
  v4.x = 0.0;
  v4.y = 0.0;
  v4.z = 1.0;
  v3.value = idMath::HALF_PI;
  idMat3::idMat3(this: &this->soundTransform, axis: &v4, angle: &v3);
  return this;
}


// ========================================================================
// __unwind$488448_1
// EA  : 0x82C0B8DC
// RVA : 0x00C0B8DC
// PDB : w:\tech5\tungsten\game\entities\batterychargepoint.cpp
// ========================================================================

void _unwind_488448_1()
{
  int v0; // r12

  idProp_ContinuallyUsed::~idProp_ContinuallyUsed(this: *(idProp_ContinuallyUsed **)(v0 - 128 + 148));
}


// ========================================================================
// ?Think@idProp_BatteryChargePoint@@UAAXXZ
// EA  : 0x82C0B908
// RVA : 0x00C0B908
// PDB : w:\tech5\tungsten\game\entities\batterychargepoint.cpp
// ========================================================================

void __fastcall idProp_BatteryChargePoint::Think(idProp_BatteryChargePoint *this)
{
  idPlayer *user; // r3
  idPlayer *v3; // r30
  idLaserCutter *v4; // r3
  idLaserCutter *v5; // r3
  int GameMs; // r3
  int v7; // r28
  idLaserCutter *v8; // r3
  idLaserCutter *v9; // r29
  __int64 v10; // r5
  idInventoryCollection *v11; // r3
  idWeapon *InventoryItemByName; // r3
  idInventoryCollection *v13; // r3
  idWeapon *v14; // r3
  idPresentable *v15; // r11
  idWeapon *v16; // r31
  int v17; // r3
  idPresentable *presentable; // r3
  int v19; // r3
  __int64 v20; // r7
  __int64 v21; // r5
  long double v22; // fp2
  long double v23; // fp2

  idAnimatedEntity::Think(this);
  user = (idPlayer *)this->user;
  if ( user == nullptr )
    goto LABEL_5;
  v3 = idPlayer::CastTo(c: user);
  if ( idPlayer::GetFocusEntity(this: v3) != this )
  {
    this->Use(this, a2: this, a3: USABLE_PROP);
    v4 = (idLaserCutter *)v3->GetEquippedWeapon(this: v3);
    v5 = idLaserCutter::CastTo(c: v4);
    if ( v5 != nullptr )
      idLaserCutter::SetChargingEffects(this: v5, activate: false, actor: v3);
LABEL_5:
    idEntity::BecomeInactive(this, flags: 1);
    return;
  }
  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  v7 = GameMs;
  if ( this->lastChargetTime == -1 )
    this->lastChargetTime = GameMs;
  v8 = (idLaserCutter *)v3->GetEquippedWeapon(this: v3);
  v9 = idLaserCutter::CastTo(c: v8);
  if ( v9 != nullptr )
  {
    presentable = v3->presentable;
    if ( presentable != nullptr )
      v19 = (int)presentable->GetPlayerInterface_2(this: presentable);
    else
      v19 = 0;
    if ( idHands::GetState(this: (idHands *)(v19 + 37616), animWeb: (const idAnimWebHands *)(v19 + 39208)) == HS_CHARGEWEAPONBATTERY
      && ((double (__fastcall *)(idLaserCutter *, _DWORD))v9->AmmoInClipPercentage)(a1: v9, a2: 0) < 1.0 )
    {
      LODWORD(v20) = v7 - this->lastChargetTime;
      LODWORD(v21) = timeManager.gameTimePerFrame.value * timeManager.gameHz;
      *(double *)&v22 = (float)((float)((float)((float)v20 / (float)v21) * this->chargePerSecond) + this->curChargeAmount);
      this->curChargeAmount = (float)((float)((float)v20 / (float)v21) * this->chargePerSecond) + this->curChargeAmount;
      if ( *(double *)&v22 > 1.0 )
      {
        v23 = floor(x: v22);
        this->curChargeAmount = this->curChargeAmount - (float)*(double *)&v23;
        idLaserCutter::ChargeBattery(this: v9, amount: (int)(float)*(double *)&v23);
      }
      idLaserCutter::SetChargingEffects(this: v9, activate: true, actor: v3);
      this->lastChargetTime = v7;
    }
    else
    {
      idLaserCutter::SetChargingEffects(this: v9, activate: false, actor: v3);
      this->lastChargetTime = v7;
    }
  }
  else
  {
    LODWORD(v10) = timeManager.gameTimePerFrame.value * timeManager.gameHz;
    if ( v7 > this->lastChargetTime - (int)(float)((float)v10 * (float)-0.5) )
    {
      v11 = v3->GetInventory_2(this: v3);
      InventoryItemByName = (idWeapon *)idInventoryCollection::FindInventoryItemByName(
                                          this: v11,
                                          internalName: "lasercutter");
      if ( InventoryItemByName != nullptr
        || (v13 = v3->GetInventory_2(this: v3),
            (InventoryItemByName = (idWeapon *)idInventoryCollection::FindInventoryItemByName(
                                                 this: v13,
                                                 internalName: "laserkraftwerk")) != nullptr) )
      {
        v14 = idWeapon::CastTo(c: InventoryItemByName);
        v15 = v3->presentable;
        v16 = v14;
        if ( v15 != nullptr )
          v17 = (int)v15->GetPlayerInterface_2(this: v3->presentable);
        else
          v17 = 0;
        idHands::SelectWeapon(
          this: (idHands *)(v17 + 37616),
          slot: EQUIP_RIGHT_HAND,
          weapon: v16,
          useIntroBringUp: false);
      }
    }
  }
}

