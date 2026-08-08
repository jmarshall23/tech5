
// ========================================================================
// ?SetFireMode@idAIFireControl@@QAAXPAVidAI2@@W4aiFireMode_t@@@Z
// EA  : 0x82A47E70
// RVA : 0x00A47E70
// PDB : w:\tech5\tungsten\game\ai\aifirecontrol.cpp
// ========================================================================

void __fastcall idAIFireControl::SetFireMode(idAIFireControl *this, idAI2 *owner, aiFireMode_t mode)
{
  int v5; // r27
  int i; // r29
  const idAIFireControl::weaponInfo_t *v7; // r3
  idWeapon *EquippedWeapon; // r3
  idWeapon *v9; // r31

  if ( this->fireMode != mode )
  {
    this->fireMode = mode;
    v5 = this->NumWeaponInfos(this);
    for ( i = 0; i < v5; ++i )
    {
      v7 = this->GetWeaponInfo(this, a2: i);
      EquippedWeapon = idActor::GetEquippedWeapon(this: owner, slot: (const equipSlot_t)v7->slot);
      v9 = EquippedWeapon;
      if ( EquippedWeapon != nullptr )
      {
        EquippedWeapon->ReleaseTrigger(this: EquippedWeapon, a2: owner);
        idWeapon::SetFireState(this: v9, fs: FIRESTATE_IDLE);
      }
    }
  }
}


// ========================================================================
// ?GetWeaponInfo@idAIFireControl_Human@@MBAABUweaponInfo_t@idAIFireControl@@H@Z
// EA  : 0x82A47F20
// RVA : 0x00A47F20
// PDB : w:\tech5\tungsten\game\ai\aifirecontrol.cpp
// ========================================================================

const idAIFireControl::weaponInfo_t *__fastcall idAIFireControl_Human::GetWeaponInfo(
        idAIFireControl_Human *this,
        const int index)
{
  return &idAIFireControl_Human::weaponInfos[index];
}


// ========================================================================
// ?DormantEnd@idAIFireControl_Human@@UAAXH@Z
// EA  : 0x82A47F38
// RVA : 0x00A47F38
// PDB : w:\tech5\tungsten\game\ai\aifirecontrol.cpp
// ========================================================================

void __fastcall idAIFireControl_Human::DormantEnd(idAIFireControl_Human *this, const int timeDormant)
{
  int endBurstTime; // r11
  int v3; // r7
  int v4; // r6

  endBurstTime = this->weaponStates[1].endBurstTime;
  v3 = this->weaponStates[0].endBurstTime + timeDormant;
  v4 = this->weaponStates[1].nextPullTriggerTime + timeDormant;
  this->weaponStates[0].nextPullTriggerTime += timeDormant;
  this->weaponStates[0].endBurstTime = v3;
  this->weaponStates[1].nextPullTriggerTime = v4;
  this->weaponStates[1].endBurstTime = endBurstTime + timeDormant;
}


// ========================================================================
// ?InhibitFire@idAIFireControl@@QAAXPBVidWeapon@@H@Z
// EA  : 0x82A47F70
// RVA : 0x00A47F70
// PDB : w:\tech5\tungsten\game\ai\aifirecontrol.cpp
// ========================================================================

void __fastcall idAIFireControl::InhibitFire(idAIFireControl *this, const idWeapon *weapon, const int inhibitLength)
{
  int GameMs; // r26
  int v7; // r3

  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  if ( this->GetNextPullTriggerTime(this, a2: weapon) < GameMs + inhibitLength )
  {
    v7 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    this->SetNextPullTriggerTime(this, a2: weapon, a3: v7 + inhibitLength);
  }
}


// ========================================================================
// ?ClearInhibitFire@idAIFireControl@@QAAXPBVidWeapon@@@Z
// EA  : 0x82A48000
// RVA : 0x00A48000
// PDB : w:\tech5\tungsten\game\ai\aifirecontrol.cpp
// ========================================================================

void __fastcall idAIFireControl::ClearInhibitFire(idAIFireControl *this, const idWeapon *weapon)
{
  int GameMs; // r3

  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  this->SetNextPullTriggerTime(this, a2: weapon, a3: GameMs);
}


// ========================================================================
// ??0idAIFireControl_Human@@QAA@XZ
// EA  : 0x82A48068
// RVA : 0x00A48068
// PDB : w:\tech5\tungsten\game\ai\aifirecontrol.cpp
// ========================================================================

idAIFireControl_Human *__fastcall idAIFireControl_Human::idAIFireControl_Human(idAIFireControl_Human *this)
{
  int v1; // ctr
  bool *p_freeAmmo; // r10

  this->__vftable = (idAIFireControl_Human_vtbl *)&idAIFireControl_Human::`vftable';
  this->fireMode = FIREMODE_HOLDFIRE;
  *(_WORD *)&this->freeAmmo = 1;
  v1 = 6;
  this->weaponStates[0].nextPullTriggerTime = -1;
  p_freeAmmo = &this->freeAmmo;
  this->weaponStates[0].endBurstTime = -1;
  this->weaponStates[0].fireAtLastKnownDuration = -1;
  this->weaponStates[1].nextPullTriggerTime = -1;
  this->weaponStates[1].endBurstTime = -1;
  this->weaponStates[1].fireAtLastKnownDuration = -1;
  do
  {
    p_freeAmmo += 4;
    *(_DWORD *)p_freeAmmo = 0;
    --v1;
  }
  while ( v1 != 0 );
  return this;
}


// ========================================================================
// ?SetNextPullTriggerTime@idAIFireControl_Human@@MAAXPBVidWeapon@@H@Z
// EA  : 0x82A480C8
// RVA : 0x00A480C8
// PDB : w:\tech5\tungsten\game\ai\aifirecontrol.cpp
// ========================================================================

void __fastcall idAIFireControl_Human::SetNextPullTriggerTime(
        idAIFireControl_Human *this,
        const idWeapon *weapon,
        int time)
{
  this->weaponStates[idAIFireControl_Human::slotToIndexMap[weapon->decl->equipSlot]].nextPullTriggerTime = time;
}


// ========================================================================
// ?GetNextPullTriggerTime@idAIFireControl_Human@@MBAHPBVidWeapon@@@Z
// EA  : 0x82A480F8
// RVA : 0x00A480F8
// PDB : w:\tech5\tungsten\game\ai\aifirecontrol.cpp
// ========================================================================

int __fastcall idAIFireControl_Human::GetNextPullTriggerTime(idAIFireControl_Human *this, const idWeapon *weapon)
{
  return this->weaponStates[idAIFireControl_Human::slotToIndexMap[weapon->decl->equipSlot]].nextPullTriggerTime;
}


// ========================================================================
// ?ResetNextPullTriggerTime@idAIFireControl_Human@@UAAXPAVidAI2@@@Z
// EA  : 0x82A48128
// RVA : 0x00A48128
// PDB : w:\tech5\tungsten\game\ai\aifirecontrol.cpp
// ========================================================================

void __fastcall idAIFireControl_Human::ResetNextPullTriggerTime(idAIFireControl_Human *this, idAI2 *ai)
{
  int i; // r30
  const idAIFireControl::weaponInfo_t *v5; // r3
  idWeapon *EquippedWeapon; // r3
  const idDeclInventory *decl; // r11

  for ( i = 0; i < this->NumWeaponInfos(this); ++i )
  {
    v5 = this->GetWeaponInfo(this, a2: i);
    EquippedWeapon = idActor::GetEquippedWeapon(this: ai, slot: (const equipSlot_t)v5->slot);
    if ( EquippedWeapon != nullptr )
    {
      decl = EquippedWeapon->decl;
      if ( decl != nullptr )
        this->weaponStates[idAIFireControl_Human::slotToIndexMap[decl->equipSlot]].nextPullTriggerTime = 0;
    }
  }
}


// ========================================================================
// ?SetEndBurstTime@idAIFireControl_Human@@MAAXPBVidWeapon@@H@Z
// EA  : 0x82A481E8
// RVA : 0x00A481E8
// PDB : w:\tech5\tungsten\game\ai\aifirecontrol.cpp
// ========================================================================

void __fastcall idAIFireControl_Human::SetEndBurstTime(idAIFireControl_Human *this, const idWeapon *weapon, int time)
{
  this->weaponStates[idAIFireControl_Human::slotToIndexMap[weapon->decl->equipSlot]].endBurstTime = time;
}


// ========================================================================
// ?GetEndBurstTime@idAIFireControl_Human@@MBAHPBVidWeapon@@@Z
// EA  : 0x82A48218
// RVA : 0x00A48218
// PDB : w:\tech5\tungsten\game\ai\aifirecontrol.cpp
// ========================================================================

int __fastcall idAIFireControl_Human::GetEndBurstTime(idAIFireControl_Human *this, const idWeapon *weapon)
{
  return this->weaponStates[idAIFireControl_Human::slotToIndexMap[weapon->decl->equipSlot]].endBurstTime;
}


// ========================================================================
// ?SetFireAtLastKnownDuration@idAIFireControl_Human@@MAAXPBVidWeapon@@H@Z
// EA  : 0x82A48248
// RVA : 0x00A48248
// PDB : w:\tech5\tungsten\game\ai\aifirecontrol.cpp
// ========================================================================

void __fastcall idAIFireControl_Human::SetFireAtLastKnownDuration(
        idAIFireControl_Human *this,
        const idWeapon *weapon,
        int duration)
{
  this->weaponStates[idAIFireControl_Human::slotToIndexMap[weapon->decl->equipSlot]].fireAtLastKnownDuration = duration;
}


// ========================================================================
// ?GetFireAtLastKnownDuration@idAIFireControl_Human@@MBAHPBVidWeapon@@@Z
// EA  : 0x82A48278
// RVA : 0x00A48278
// PDB : w:\tech5\tungsten\game\ai\aifirecontrol.cpp
// ========================================================================

int __fastcall idAIFireControl_Human::GetFireAtLastKnownDuration(idAIFireControl_Human *this, const idWeapon *weapon)
{
  return this->weaponStates[idAIFireControl_Human::slotToIndexMap[weapon->decl->equipSlot]].fireAtLastKnownDuration;
}


// ========================================================================
// ?CanFireWeapons@idAIFireControl@@MBA_NPAVidAI2@@PBVidAIEntityState@@H@Z
// EA  : 0x82A482F0
// RVA : 0x00A482F0
// PDB : w:\tech5\tungsten\game\ai\aifirecontrol.cpp
// ========================================================================

BOOL __fastcall idAIFireControl::CanFireWeapons(
        idAIFireControl *this,
        idAI2 *owner,
        const idAIEntityState *ees,
        const int curTime)
{
  int value; // r10
  idEntity *v5; // r3
  BOOL result; // r3

  value = owner->aiVolatile.focus.foci.ptr[0].focusEntity.spawnId.value;
  result = false;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
  {
    v5 = gameLocal->entities.ptr[value & 0x1FFF];
    if ( v5 != nullptr && idEntity::CastTo(c: v5) != nullptr )
      return true;
  }
  return result;
}


// ========================================================================
// ?Update@idAIFireControl@@QAAXPAVidAI2@@H@Z
// EA  : 0x82A48378
// RVA : 0x00A48378
// PDB : w:\tech5\tungsten\game\ai\aifirecontrol.cpp
// ========================================================================

void __fastcall idAIFireControl::Update(idAIFireControl *this, idAI2 *owner, int curTime)
{
  unsigned __int64 v6; // r6
  const char *v7; // r7
  aiFireMode_t fireMode; // r11
  idPLogScope v9[8]; // [sp+50h] [-40h] BYREF

  RD_EventBegin(name: "idAIFireControl::Update");
  LODWORD(v6) = "idAIFireControl::Update";
  HIDWORD(v6) = 6;
  idPLogScope::idPLogScope(this: v9, pl: &pLog, gMask: v6, label: v7);
  if ( idComponentActionScript::NumScriptActions(this: &owner->actionScript, entity: owner) <= 0 )
  {
    fireMode = this->fireMode;
    if ( (unsigned int)fireMode <= FIREMODE_SPRAYWHENREADY )
    {
      if ( fireMode != FIREMODE_WEAPON )
      {
        if ( fireMode == FIREMODE_HOLDFIRE )
        {
          this->Update_HoldFire(this, a2: owner, a3: curTime);
        }
        else if ( fireMode == FIREMODE_FIREWHENREADY )
        {
          this->Update_FireWhenReady(this, a2: owner, a3: curTime);
        }
        else
        {
          this->Update_SprayWhenReady(this, a2: owner, a3: curTime);
        }
      }
      else
      {
        this->Update_Weapon(this, a2: owner, a3: curTime);
      }
    }
    if ( owner->aiVolatile.memory.enableGangstaPose && curTime >= owner->aiVolatile.memory.gangstaTimeout )
    {
      owner->aiVolatile.memory.gangstaTimeout = 0;
      owner->aiVolatile.memory.enableGangstaPose = false;
    }
  }
  else
  {
    this->Update_Weapon(this, a2: owner, a3: curTime);
    if ( owner->aiVolatile.memory.enableGangstaPose && curTime >= owner->aiVolatile.memory.gangstaTimeout )
    {
      owner->aiVolatile.memory.gangstaTimeout = 0;
      owner->aiVolatile.memory.enableGangstaPose = false;
    }
  }
  idPLogScope::~idPLogScope(this: v9);
  RD_EventEnd();
}


// ========================================================================
// __unwind$489464
// EA  : 0x82A484FC
// RVA : 0x00A484FC
// PDB : w:\tech5\tungsten\game\ai\aifirecontrol.cpp
// ========================================================================

void _unwind_489464()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 144 + 88));
}


// ========================================================================
// __unwind$489465
// EA  : 0x82A48524
// RVA : 0x00A48524
// PDB : w:\tech5\tungsten\game\ai\aifirecontrol.cpp
// ========================================================================

void _unwind_489465()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 144 + 80));
}


// ========================================================================
// ?CanFireWeapon@idAIFireControl@@IAA_NPAVidAI2@@PAVidWeapon@@PBVidAIEntityState@@H@Z
// EA  : 0x82A48558
// RVA : 0x00A48558
// PDB : w:\tech5\tungsten\game\ai\aifirecontrol.cpp
// ========================================================================

int __fastcall idAIFireControl::CanFireWeapon(
        idAIFireControl *this,
        idAI2 *owner,
        idWeapon *weapon,
        idAIEntityState *ees,
        int curTime)
{
  unsigned __int64 v10; // r6
  const char *v11; // r7
  idPresentable *presentable; // r11
  aiSenseState_t *v14; // r3
  int v15; // r27
  idPhysics *Physics; // r3
  float *v17; // r3
  double z; // fp0
  double y; // fp13
  double x; // fp12
  double v21; // fp9
  double v22; // fp7
  idPhysics *v23; // r3
  float *v24; // r3
  double v25; // fp5
  double v26; // fp4
  double v27; // fp3
  double v28; // fp0
  double v29; // fp12
  __int64 v30; // r10
  __int64 v31; // r8
  int v32; // r5
  const char *v33; // [sp+8h] [-198h]
  int v34; // [sp+Ch] [-194h]
  int v35; // [sp+10h] [-190h]
  int v36; // [sp+14h] [-18Ch]
  int v37; // [sp+18h] [-188h]
  int v38; // [sp+1Ch] [-184h]
  int v39; // [sp+20h] [-180h]
  int v40; // [sp+24h] [-17Ch]
  int v41; // [sp+28h] [-178h]
  int v42; // [sp+2Ch] [-174h]
  int v43; // [sp+30h] [-170h]
  int v44; // [sp+34h] [-16Ch]
  int v45; // [sp+38h] [-168h]
  int v46; // [sp+3Ch] [-164h]
  int v47; // [sp+40h] [-160h]
  int v48; // [sp+44h] [-15Ch]
  int v49; // [sp+48h] [-158h]
  int v50; // [sp+4Ch] [-154h]
  int v51; // [sp+50h] [-150h]
  idPLogScope v52; // [sp+60h] [-140h] BYREF
  idVec3 v53; // [sp+68h] [-138h] BYREF
  idVec3 v54; // [sp+78h] [-128h] BYREF
  idVec3 v55[2]; // [sp+88h] [-118h] BYREF
  idMat3 v56; // [sp+A0h] [-100h] BYREF
  trace_t v57; // [sp+D0h] [-D0h] BYREF

  RD_EventBegin(name: "idAIFireControl::CanFireWeapon");
  LODWORD(v10) = "idAIFireControl::CanFireWeapon";
  HIDWORD(v10) = 6;
  idPLogScope::idPLogScope(this: &v52, pl: &pLog, gMask: v10, label: v11);
  if ( weapon == nullptr
    || !idWeapon::UsesFireControl(this: weapon)
    || weapon->NeedsReload(this: weapon, a2: false) && !this->freeAmmo
    || owner->aiVolatile.memory.temporaryHoldFire )
  {
    goto LABEL_16;
  }
  presentable = owner->presentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this: owner);
    presentable = owner->presentable;
  }
  if ( presentable->axis.mat[2].z > 0.0
    && owner->aiVolatile.physics.moveState.IsPlayingTraversalAnim(this: &owner->aiVolatile.physics.moveState) )
  {
    idAI2::AimDebug(this: owner, text: "traversal", level: 1);
    idPLogScope::~idPLogScope(this: &v52);
    RD_EventEnd();
    return 0;
  }
  if ( idAIEntityState::IsVisible(this: ees) )
    goto LABEL_32;
  if ( owner->aiVolatile.focus.foci.ptr[0].focusType != AIFOCUS_LAST_SEEN_POS
    || (v14 = ees->senses.ptr[1])->lastUnconfirmedStimTime < 0 )
  {
LABEL_16:
    idPLogScope::~idPLogScope(this: &v52);
    RD_EventEnd();
    return 0;
  }
  if ( (v14->senseFlags & 4) == 0 )
  {
    idAI2::AimDebug(this: owner, text: "can't see", level: 1);
    idPLogScope::~idPLogScope(this: &v52);
    RD_EventEnd();
    return 0;
  }
  v15 = curTime - aiSenseState_t::GetConfirmedStimTimeSafe(this: v14);
  if ( v15 < this->GetFireAtLastKnownDuration(this, a2: weapon) )
  {
LABEL_32:
    if ( (unsigned __int8)idSysLocal::GetClipboardData(this: (D3DXShader::C30SWProgramML *)owner) != 0 )
      goto LABEL_33;
    Physics = idEntity::GetPhysics(this: owner);
    v17 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
    z = owner->aiVolatile.focus.foci.ptr[0].idealFocusPoint.z;
    y = owner->aiVolatile.focus.foci.ptr[0].idealFocusPoint.y;
    x = owner->aiVolatile.focus.foci.ptr[0].idealFocusPoint.x;
    LODWORD(v53.x) = &owner->aiVolatile.focus.foci.ptr[0].idealFocusPoint;
    v21 = (float)((float)z - v17[2]);
    v22 = (float)((float)y - v17[1]);
    v54.x = (float)x - *v17;
    v54.z = v21;
    v54.y = v22;
    v23 = idEntity::GetPhysics(this: owner);
    v24 = (float *)v23->GetOrigin(this: v23, a2: 0);
    v25 = owner->aiVolatile.focus.foci.ptr[0].curFocusPoint.z;
    v26 = owner->aiVolatile.focus.foci.ptr[0].curFocusPoint.y;
    v27 = owner->aiVolatile.focus.foci.ptr[0].curFocusPoint.x;
    LODWORD(v53.x) = &owner->aiVolatile.focus.foci.ptr[0].curFocusPoint;
    v28 = (float)((float)v25 - v24[2]);
    v29 = (float)((float)v26 - v24[1]);
    v53.x = (float)v27 - *v24;
    v53.z = v28;
    v53.y = v29;
    idVec3::NormalizeFast(this: &v54);
    idVec3::NormalizeFast(this: &v53);
    if ( (float)((float)(v53.z * v54.z) + (float)((float)(v53.y * v54.y) + (float)(v53.x * v54.x))) >= 0.89999998 )
    {
LABEL_33:
      if ( idAI2::GetMuzzlePoint(this: owner, weapon, muzzlePos: v55, muzzleAxis: &v56)
        && (idClip::Contents(
              this: (idClip *)&v53,
              result: &clientGame->clip,
              a3: &v57,
              start: v55,
              clipModel: nullptr,
              startAxis: &mat3_identity,
              clipMask: 1,
              passEntityNumber: 0x1FFF,
              userName: v33,
              a10: v34,
              a11: v35,
              a12: v36,
              a13: v37,
              a14: v38,
              a15: v39,
              a16: v40,
              a17: v41,
              a18: v42,
              a19: v43,
              a20: v44,
              a21: v45,
              a22: v46,
              a23: v47,
              a24: v48,
              a25: v49,
              a26: v50,
              a27: v51,
              a28: 0),
            LODWORD(v31) = v57.c.contentFlags,
            HIDWORD(v31) = v57.c.contentFlags & 1,
            (v57.c.contentFlags & 1) != 0) )
      {
        owner->aiVolatile.memory.muzzleInSolid = true;
        idAI2::AimDebug(this: owner, text: "muzzle in solid", level: 1);
        idPLogScope::~idPLogScope(this: &v52);
        RD_EventEnd();
        return 0;
      }
      else
      {
        LODWORD(v30) = 58714;
        owner->aiVolatile.memory.muzzleInSolid = false;
        if ( (unsigned __int8)idAI2::CanFireRobot(this: owner, _curTime: curTime, a3: v32, a4: v31, a5: v30) != 0 )
        {
          idPLogScope::~idPLogScope(this: &v52);
          RD_EventEnd();
          return 1;
        }
        else
        {
          idAI2::AimDebug(this: owner, text: "no power", level: 1);
          idPLogScope::~idPLogScope(this: &v52);
          RD_EventEnd();
          return 0;
        }
      }
    }
    else
    {
      idAI2::AimDebug(this: owner, text: "aiming", level: 1);
      idPLogScope::~idPLogScope(this: &v52);
      RD_EventEnd();
      return 0;
    }
  }
  else
  {
    idAI2::AimDebug(this: owner, text: "lost sight", level: 1);
    idPLogScope::~idPLogScope(this: &v52);
    RD_EventEnd();
    return 0;
  }
}


// ========================================================================
// __unwind$489568
// EA  : 0x82A489DC
// RVA : 0x00A489DC
// PDB : w:\tech5\tungsten\game\ai\aifirecontrol.cpp
// ========================================================================

void _unwind_489568()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 416 + 336));
}


// ========================================================================
// __unwind$489569
// EA  : 0x82A48A04
// RVA : 0x00A48A04
// PDB : w:\tech5\tungsten\game\ai\aifirecontrol.cpp
// ========================================================================

void _unwind_489569()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 416 + 96));
}


// ========================================================================
// ?CheckReleaseTrigger@idAIFireControl@@IAA_NPAVidAI2@@PAVidWeapon@@PBVidAIEntityState@@HABUweaponInfo_t@1@@Z
// EA  : 0x82A48A38
// RVA : 0x00A48A38
// PDB : w:\tech5\tungsten\game\ai\aifirecontrol.cpp
// ========================================================================

int __fastcall idAIFireControl::CheckReleaseTrigger(
        idAIFireControl *this,
        idAI2 *owner,
        idWeapon *weapon,
        idAIEntityState *ees,
        int curTime,
        const idAIFireControl::weaponInfo_t *info)
{
  unsigned __int64 v11; // r6
  const char *v12; // r7
  __int64 v13; // r10
  __int64 v14; // r8
  int v15; // r5
  idPLogScope v17[10]; // [sp+50h] [-50h] BYREF

  RD_EventBegin(name: "idAIFireControl::CheckReleaseTrigger");
  LODWORD(v11) = "idAIFireControl::CheckReleaseTrigger";
  HIDWORD(v11) = 6;
  idPLogScope::idPLogScope(this: v17, pl: &pLog, gMask: v11, label: v12);
  if ( weapon != nullptr && idWeapon::UsesFireControl(this: weapon) )
  {
    if ( (unsigned __int8)idAIFireControl::CanFireWeapon(this, owner, weapon, ees, curTime) != 0
      && curTime < this->GetEndBurstTime(this, a2: weapon)
      && weapon->burstCount > 0 )
    {
      idPLogScope::~idPLogScope(this: v17);
      RD_EventEnd();
      return 0;
    }
    idAI2::StopFireRobot(this: owner, _curTime: curTime, a3: v15, a4: v14, a5: v13);
    idPLogScope::~idPLogScope(this: v17);
  }
  else
  {
    idPLogScope::~idPLogScope(this: v17);
  }
  RD_EventEnd();
  return 1;
}


// ========================================================================
// __unwind$489806
// EA  : 0x82A48B40
// RVA : 0x00A48B40
// PDB : w:\tech5\tungsten\game\ai\aifirecontrol.cpp
// ========================================================================

void _unwind_489806()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 160 + 88));
}


// ========================================================================
// __unwind$489807
// EA  : 0x82A48B68
// RVA : 0x00A48B68
// PDB : w:\tech5\tungsten\game\ai\aifirecontrol.cpp
// ========================================================================

void _unwind_489807()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 160 + 80));
}


// ========================================================================
// ?CheckPullTrigger@idAIFireControl@@IAA_NPAVidAI2@@PAVidWeapon@@PBVidAIEntityState@@HABUweaponInfo_t@1@@Z
// EA  : 0x82A48B98
// RVA : 0x00A48B98
// PDB : w:\tech5\tungsten\game\ai\aifirecontrol.cpp
// ========================================================================

int __fastcall idAIFireControl::CheckPullTrigger(
        idAIFireControl *this,
        idAI2 *owner,
        idWeapon *weapon,
        idAIEntityState *ees,
        int curTime,
        const idAIFireControl::weaponInfo_t *info)
{
  unsigned __int64 v11; // r6
  const char *v12; // r7
  aiSenseState_t *v13; // r3
  int valueInteger; // r28
  int CanFireWeapon; // r30
  idPLogScope v17[11]; // [sp+58h] [-58h] BYREF

  RD_EventBegin(name: "idAIFireControl::CheckPullTrigger");
  LODWORD(v11) = "idAIFireControl::CheckPullTrigger";
  HIDWORD(v11) = 6;
  idPLogScope::idPLogScope(this: v17, pl: &pLog, gMask: v11, label: v12);
  if ( weapon != nullptr
    && idWeapon::UsesFireControl(this: weapon)
    && !weapon->NeedsReload(this: weapon, a2: false)
    && weapon->fireState != FIRESTATE_RELOADING
    && (unsigned __int8)idFocusInfo::HasFocus(this: owner->aiVolatile.focus.foci.ptr) != 0 )
  {
    if ( curTime >= this->GetNextPullTriggerTime(this, a2: weapon) )
    {
      if ( owner->aiVolatile.focus.foci.ptr[0].wanderingAim.convergeTime >= *((_DWORD *)&weapon->decl[2].programaticallyDefined
                                                                            + 8
                                                                            * idAI2::GetEffectiveAccuracy(this: owner)) )
      {
        v13 = ees->senses.ptr[1];
        if ( v13->lastUnconfirmedStimTime < 0
          || (valueInteger = ai_keepShootingNoSight.valueInteger,
              curTime - aiSenseState_t::GetConfirmedStimTimeSafe(this: v13) <= valueInteger) )
        {
          CanFireWeapon = idAIFireControl::CanFireWeapon(this, owner, weapon, ees, curTime);
          idPLogScope::~idPLogScope(this: v17);
          RD_EventEnd();
          return CanFireWeapon;
        }
        idAI2::AimDebug(this: owner, text: "stale sense", level: 1);
        idPLogScope::~idPLogScope(this: v17);
      }
      else
      {
        idAI2::AimDebug(this: owner, text: "required converge time", level: 1);
        idPLogScope::~idPLogScope(this: v17);
      }
    }
    else
    {
      idAI2::AimDebug(this: owner, text: "cooldown", level: 1);
      idPLogScope::~idPLogScope(this: v17);
    }
  }
  else
  {
    idPLogScope::~idPLogScope(this: v17);
  }
  RD_EventEnd();
  return 0;
}


// ========================================================================
// __unwind$489866
// EA  : 0x82A48D88
// RVA : 0x00A48D88
// PDB : w:\tech5\tungsten\game\ai\aifirecontrol.cpp
// ========================================================================

void _unwind_489866()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 176 + 96));
}


// ========================================================================
// __unwind$489867
// EA  : 0x82A48DB0
// RVA : 0x00A48DB0
// PDB : w:\tech5\tungsten\game\ai\aifirecontrol.cpp
// ========================================================================

void _unwind_489867()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 176 + 88));
}


// ========================================================================
// ?PullWeaponTrigger@idAIFireControl@@IAAXPAVidAI2@@PAVidWeapon@@PBVidAIEntityState@@H@Z
// EA  : 0x82A48DE0
// RVA : 0x00A48DE0
// PDB : w:\tech5\tungsten\game\ai\aifirecontrol.cpp
// ========================================================================

void __fastcall idAIFireControl::PullWeaponTrigger(
        idAIFireControl *this,
        idAI2 *owner,
        idWeapon *weapon,
        const idAIEntityState *ees,
        const int curTime)
{
  unsigned __int64 v9; // r6
  const char *v10; // r7
  int v11; // r3
  int v12; // r11
  int v13; // r3
  int v14; // [sp+50h] [-60h] BYREF
  int v15; // [sp+54h] [-5Ch] BYREF
  int v16; // [sp+58h] [-58h] BYREF
  int v17; // [sp+5Ch] [-54h] BYREF
  idPLogScope v18[10]; // [sp+60h] [-50h] BYREF

  RD_EventBegin(name: "idAIFireControl::PullWeaponTrigger");
  LODWORD(v9) = "idAIFireControl::PullWeaponTrigger";
  HIDWORD(v9) = 6;
  idPLogScope::idPLogScope(this: v18, pl: &pLog, gMask: v9, label: v10);
  if ( weapon != nullptr && idWeapon::UsesFireControl(this: weapon) )
  {
    weapon->PullTrigger(this: weapon, a2: owner, a3: false);
    idAI2::GetBurstDuration(this: owner, weapon, min: &v14, max: &v15);
    v11 = idRandom2::RandomInt(this: &clientGame->random, max: v15 - v14);
    v12 = v11 + v14;
    if ( (owner->aiVolatile.groupStatus.condition & 0x8000) != 0 )
      v12 = v15;
    this->SetEndBurstTime(this, a2: weapon, a3: v12 + curTime);
    idAI2::GetFireAtLastKnownDuration(this: owner, weapon, min: &v16, max: &v17);
    v13 = idRandom2::RandomInt(this: &clientGame->random, max: v17 - v16);
    this->SetFireAtLastKnownDuration(this, a2: weapon, a3: v13 + v16);
    idAIMemory::TriggerPulled(this: &owner->aiVolatile.memory);
    idPLogScope::~idPLogScope(this: v18);
  }
  else
  {
    idPLogScope::~idPLogScope(this: v18);
  }
  RD_EventEnd();
}


// ========================================================================
// __unwind$489994
// EA  : 0x82A48F4C
// RVA : 0x00A48F4C
// PDB : w:\tech5\tungsten\game\ai\aifirecontrol.cpp
// ========================================================================

void _unwind_489994()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 176 + 104));
}


// ========================================================================
// __unwind$489995
// EA  : 0x82A48F74
// RVA : 0x00A48F74
// PDB : w:\tech5\tungsten\game\ai\aifirecontrol.cpp
// ========================================================================

void _unwind_489995()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 176 + 96));
}


// ========================================================================
// ?ReleaseWeaponTrigger@idAIFireControl@@IAAXPAVidAI2@@PAVidWeapon@@H@Z
// EA  : 0x82A48FA8
// RVA : 0x00A48FA8
// PDB : w:\tech5\tungsten\game\ai\aifirecontrol.cpp
// ========================================================================

void __fastcall idAIFireControl::ReleaseWeaponTrigger(
        idAIFireControl *this,
        idAI2 *owner,
        idWeapon *weapon,
        const int curTime)
{
  unsigned __int64 v8; // r6
  const char *v9; // r7
  int v10; // r3
  int v11; // r28
  int v12; // [sp+50h] [-50h] BYREF
  int v13; // [sp+54h] [-4Ch] BYREF
  idPLogScope v14[9]; // [sp+58h] [-48h] BYREF

  RD_EventBegin(name: "idAIFireControl::ReleaseWeaponTrigger");
  LODWORD(v8) = "idAIFireControl::ReleaseWeaponTrigger";
  HIDWORD(v8) = 6;
  idPLogScope::idPLogScope(this: v14, pl: &pLog, gMask: v8, label: v9);
  if ( weapon != nullptr && idWeapon::UsesFireControl(this: weapon) )
  {
    weapon->ReleaseTrigger(this: weapon, a2: owner);
    if ( weapon->fireState != FIRESTATE_RELOADING )
      idWeapon::SetFireState(this: weapon, fs: FIRESTATE_IDLE);
    idAI2::GetRepullTriggerInterval(this: owner, weapon, min: &v12, max: &v13);
    v10 = idRandom2::RandomInt(this: &clientGame->random, max: v13 - v12);
    v11 = v10 + v12;
    if ( idAI2::GetEncounterGroup(this: owner) != nullptr && !idAI2::GetEncounterGroup(this: owner)->groupGoodWill )
      v11 = v12;
    this->SetNextPullTriggerTime(this, a2: weapon, a3: v11 + curTime);
    idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&owner->aiVolatile.memory);
    idPLogScope::~idPLogScope(this: v14);
  }
  else
  {
    idPLogScope::~idPLogScope(this: v14);
  }
  RD_EventEnd();
}


// ========================================================================
// __unwind$490047
// EA  : 0x82A490EC
// RVA : 0x00A490EC
// PDB : w:\tech5\tungsten\game\ai\aifirecontrol.cpp
// ========================================================================

void _unwind_490047()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 160 + 96));
}


// ========================================================================
// __unwind$490048
// EA  : 0x82A49114
// RVA : 0x00A49114
// PDB : w:\tech5\tungsten\game\ai\aifirecontrol.cpp
// ========================================================================

void _unwind_490048()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 160 + 88));
}


// ========================================================================
// ?UpdateWeaponState@idAIFireControl@@AAAXPAVidAI2@@PAVidWeapon@@PBVidAIEntityState@@HABUweaponInfo_t@1@ABUupdateWeaponStateParms_t@@@Z
// EA  : 0x82A49148
// RVA : 0x00A49148
// PDB : w:\tech5\tungsten\game\ai\aifirecontrol.cpp
// ========================================================================

void __fastcall idAIFireControl::UpdateWeaponState(
        idAIFireControl *this,
        idAI2 *ai,
        idWeapon *weapon,
        idAIEntityState *ees,
        int curTime,
        const idAIFireControl::weaponInfo_t *info,
        const updateWeaponStateParms_t *updateParms)
{
  unsigned __int64 v13; // r6
  const char *v14; // r7
  idWeapon::fireState_t fireState; // r11
  unsigned __int64 v16; // r6
  const char *v17; // r7
  unsigned __int64 v18; // r6
  const char *v19; // r7
  idFinishFireResults *v20; // r11
  int i; // ctr
  char v22; // r29
  bool v23; // r11
  bool v24; // cr58
  char DeferredFireResults; // r3
  idEntity *v26; // r3
  idPresentable *presentable; // r11
  idEntity *v28; // r30
  weaponFireType_t fireType; // r10
  idProp_Breakable *v30; // r3
  idAI2 *v31; // r27
  double percentBlockedShotsToReleaseTrigger; // fp0
  __int128 v33; // r5
  __int16 numShotsThisPullBlockedConsecutive; // r8
  unsigned int numBlockedShotsConsecutiveToReleaseTrigger; // r6
  char v36; // r28
  bool v37; // r29
  char v38; // r29
  char *gangstaTimeout; // r11
  unsigned __int64 v40; // r6
  const char *v41; // r7
  unsigned __int64 v42; // r6
  const char *v43; // r7
  __int64 v44; // r28
  aiFireMode_t fireMode; // r11
  __int64 v46; // r30
  __int64 v47; // r10
  aiSenseState_t *EnemySenseState; // r3
  int ConfirmedStimTimeSafe; // r26
  va *v50; // r3
  int v51; // [sp+8h] [-1BA8h]
  int v52; // [sp+Ch] [-1BA4h]
  int v53; // [sp+10h] [-1BA0h]
  int v54; // [sp+14h] [-1B9Ch]
  int v55; // [sp+18h] [-1B98h]
  int v56; // [sp+1Ch] [-1B94h]
  idPLogScope v57; // [sp+60h] [-1B50h] BYREF
  idPLogScope v58; // [sp+68h] [-1B48h] BYREF
  int v59[4]; // [sp+70h] [-1B40h] BYREF
  testFireWeaponParms_t v60; // [sp+80h] [-1B30h] BYREF
  testForBlockedTraceParms_t v61; // [sp+A0h] [-1B10h] BYREF
  idPLogScope v62[2]; // [sp+B0h] [-1B00h] BYREF
  idColor v63; // [sp+C0h] [-1AF0h] BYREF
  idVec3 v64; // [sp+D0h] [-1AE0h] BYREF
  idFireParms v65; // [sp+E0h] [-1AD0h] BYREF
  idFinishFireResults v66; // [sp+180h] [-1A30h] BYREF
  idMat3 v67; // [sp+1D0h] [-19E0h] BYREF
  idTestFireResults v68; // [sp+200h] [-19B0h] BYREF
  va v69; // [sp+B10h] [-10A0h] BYREF

  RD_EventBegin(name: "idAIFireControl::UpdateWeaponState");
  LODWORD(v13) = "idAIFireControl::UpdateWeaponState";
  HIDWORD(v13) = 6;
  idPLogScope::idPLogScope(this: v62, pl: &pLog, gMask: v13, label: v14);
  if ( !idWeapon::UsesFireControl(this: weapon) )
    goto _M490627;
  fireState = weapon->fireState;
  switch ( fireState )
  {
    case FIRESTATE_IDLE:
      RD_EventBegin(name: "idWeapon::FIRESTATE_IDLE");
      LODWORD(v40) = "idWeapon::FIRESTATE_IDLE";
      HIDWORD(v40) = 2;
      idPLogScope::idPLogScope(this: &v58, pl: &pLog, gMask: v40, label: v41);
      if ( weapon->triggerState == TRIGGERSTATE_PULLED )
        idWeapon::BeginFiring(this: weapon);
      goto LABEL_56;
    case FIRESTATE_FIRING:
      RD_EventBegin(name: "idWeapon::FIRESTATE_FIRING");
      LODWORD(v18) = "idWeapon::FIRESTATE_FIRING";
      HIDWORD(v18) = 2;
      idPLogScope::idPLogScope(this: &v58, pl: &pLog, gMask: v18, label: v19);
      if ( curTime < weapon->nextFireTime )
      {
LABEL_56:
        idPLogScope::~idPLogScope(this: &v58);
LABEL_57:
        RD_EventEnd();
        break;
      }
      idFireParms::idFireParms(this: &v65);
      memset(&v68, 0, sizeof(v68));
      v20 = &v66;
      v66.numProjectiles = 0;
      for ( i = 16; i != 0; --i )
      {
        v20 = (idFinishFireResults *)((char *)v20 + 4);
        v20->numProjectiles = 0;
      }
      v60.freeAmmo = this->freeAmmo;
      v60.useMuzzleDirForFireAxis = false;
      v60.useWeaponSpread = true;
      v60.minMuzzleDirDot = 0.99000001;
      v22 = 0;
      v60.minMuzzleDirDotGangsta = 0.94999999;
      v60.minMuzzleDirDotUpsideDown = 0.80000001;
      v60.alwaysAimingDistance = (float)(UNITS_PER_INCH_3 * (float)5.0) * (float)12.0;
      if ( idAI2::GetControllingPlayer(this: ai) != nullptr || (v23 = false, updateParms->fireType == WFT_SPRAY) )
        v23 = true;
      v60.useMuzzleDirForFireAxis = v23;
      v24 = updateParms->fireType == WFT_SPRAY;
      v60.useWeaponSpread = ai_useWeaponSpread.valueInteger != 0;
      if ( v24 )
        v60.minMuzzleDirDot = 0.69999999;
      if ( ai_useDeferredFiring.valueInteger != 0 )
      {
        if ( !idWeapon::CheckFireHandle(this: weapon) )
        {
          if ( (unsigned __int8)idAI2::TestFireWeapon(this: ai, weapon, fp: &v65, tfr: &v68, testParms: &v60) == 0 )
            idWeapon::SetFireState(this: weapon, fs: FIRESTATE_IDLE);
LABEL_23:
          if ( v22 != 0 )
          {
            if ( ees != nullptr )
            {
              v26 = gameLocal->GetEntityForSpawnId(this: gameLocal, a2: ees->spawnId.value);
              presentable = v26->presentable;
              v28 = v26;
              if ( presentable != nullptr
                || (idEntity::InitPresentableInternal(this: v26), (presentable = v28->presentable) != nullptr) )
              {
                v65.target.spawnId = presentable->spawnId;
              }
              else
              {
                v65.target.spawnId = 0;
              }
            }
            fireType = updateParms->fireType;
            v59[0] = 0;
            v61.blockOnFriendly = true;
            v61.blockOnBreakableFraction = 0.5;
            v61.minImpactDelta = 128000.0;
            v61.minTravelRatio = 0.5;
            if ( fireType == WFT_SPRAY )
              v61.minTravelRatio = 0.2;
            v30 = idAI2::TestForBlockedTrace(this: ai, fp: &v65, tfr: &v68, outNumBlocked: v59, testParms: &v61);
            v31 = (idAI2 *)v30;
            ai->aiVolatile.memory.fireBlocker.spawnId.value = 0x1FFF;
            if ( v30 != nullptr )
            {
              v57.logIndex = v30->entityNumber;
              ai->aiVolatile.memory.fireBlocker.spawnId.value = (gameLocal->spawnIds.ptr[v57.logIndex] << 13)
                                                              | v57.logIndex;
            }
            idAIMemory::WeaponFired(this: &ai->aiVolatile.memory, shotWasClear: v59[0] < v68.numTraces);
            percentBlockedShotsToReleaseTrigger = updateParms->percentBlockedShotsToReleaseTrigger;
            LODWORD(v33) = ai->aiVolatile.memory.numShotsThisPull;
            numShotsThisPullBlockedConsecutive = ai->aiVolatile.memory.numShotsThisPullBlockedConsecutive;
            DWORD2(v33) = ai->aiVolatile.memory.numShotsThisPullBlocked;
            numBlockedShotsConsecutiveToReleaseTrigger = updateParms->numBlockedShotsConsecutiveToReleaseTrigger;
            v57 = *(idPLogScope *)((char *)&v33 + 4);
            v36 = ((((numShotsThisPullBlockedConsecutive ^ numBlockedShotsConsecutiveToReleaseTrigger) & 0x80000000) == 0)
                 + (numBlockedShotsConsecutiveToReleaseTrigger >= numShotsThisPullBlockedConsecutive))
                & 1;
            v37 = (float)((float)*(__int64 *)((char *)&v33 + 4) / (float)(__int64)v33) > percentBlockedShotsToReleaseTrigger;
            if ( idAIMemory::GetFireBlocker(this: &ai->aiVolatile.memory) == nullptr && v36 == 0 && !v37 )
            {
              if ( (unsigned __int8)idAI2::FinishFireWeapon(this: ai, weapon, fp: &v65, tfr: &v68, ffr: &v66) != 0 )
              {
                idFocusInfo::AddWeaponFireKickback(this: ai->aiVolatile.focus.foci.ptr, owner: ai, weapon);
                ai->aiVolatile.memory.lastFireTime = curTime;
              }
              goto LABEL_52;
            }
            v38 = 0;
            if ( (v31 == nullptr || idAI2::CastTo(c: v31) == nullptr)
              && ai->aiEditable.actionSettings.fire.gangstaPoseFraction > 0.0
              && ees != nullptr
              && idAIEntityState::IsVisible(this: ees)
              && idAIEntityState::IsVisible(this: ees) )
            {
              gangstaTimeout = (char *)ai->aiVolatile.memory.gangstaTimeout;
              v57.pLog = (idPLog *)(int)(float)(ai->aiEditable.actionSettings.fire.gangstaDuration * (float)1000.0);
              if ( (int)gangstaTimeout <= (int)v57.pLog + curTime )
                gangstaTimeout = (char *)v57.pLog + curTime;
              ai->aiVolatile.memory.gangstaTimeout = (int)gangstaTimeout;
              v38 = 1;
              ai->aiVolatile.memory.enableGangstaPose = true;
              ai->aiVolatile.memory.numShotsThisPullBlockedConsecutive = 0;
            }
            if ( v38 != 0 )
              goto LABEL_52;
            idAI2::AimDebug(this: ai, text: "blocked", level: 1);
            if ( weapon->triggerState == TRIGGERSTATE_PULLED )
              idAIFireControl::ReleaseWeaponTrigger(this, owner: ai, weapon, curTime);
          }
          else if ( ai_useDeferredFiring.valueInteger != 0 )
          {
LABEL_52:
            idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v65.targetList);
            goto LABEL_56;
          }
          idWeapon::SetFireState(this: weapon, fs: FIRESTATE_IDLE);
          goto LABEL_52;
        }
        DeferredFireResults = idWeapon::GetDeferredFireResults(this: weapon, fp: &v65, tfr: &v68);
      }
      else
      {
        DeferredFireResults = idAI2::TestFireWeapon(this: ai, weapon, fp: &v65, tfr: &v68, testParms: &v60);
      }
      v22 = DeferredFireResults;
      goto LABEL_23;
    case FIRESTATE_RELOADING:
      RD_EventBegin(name: "idWeapon::FIRESTATE_RELOADING");
      LODWORD(v16) = "idWeapon::FIRESTATE_RELOADING";
      HIDWORD(v16) = 2;
      idPLogScope::idPLogScope(this: &v57, pl: &pLog, gMask: v16, label: v17);
      if ( curTime >= weapon->finishReloadTime )
        idAI2::ReloadWeapon(this: ai, weapon);
      idPLogScope::~idPLogScope(this: &v57);
      goto LABEL_57;
    default:
      break;
  }
_M490627:
  RD_EventBegin(name: "idAIFireControl::UpdateWeaponState - update FX");
  LODWORD(v42) = "idAIFireControl::UpdateWeaponState - update FX";
  HIDWORD(v42) = 6;
  idPLogScope::idPLogScope(this: &v58, pl: &pLog, gMask: v42, label: v43);
  if ( ai_debugAim.valueInteger > 1 && idAI2::GetDebugLevel() > 0 )
  {
    idAI2::GetMuzzlePoint(this: ai, weapon, muzzlePos: &v64, muzzleAxis: &v67);
    HIDWORD(v44) = &byte_8200D768;
    v63 = idColor::colorYellow;
    fireMode = this->fireMode;
    switch ( fireMode )
    {
      case FIREMODE_FIREWHENREADY:
        HIDWORD(v44) = "READY";
        break;
      case FIREMODE_HOLDFIRE:
        HIDWORD(v44) = "HOLD";
        break;
      case FIREMODE_WEAPON:
        HIDWORD(v44) = "WEAPON";
        break;
      default:
        break;
    }
    LODWORD(v44) = &byte_8200D768;
    v57.logIndex = weapon->triggerState;
    if ( v57.logIndex != 0 )
    {
      if ( v57.logIndex == 1 )
        LODWORD(v44) = "RELEASED";
    }
    else
    {
      LODWORD(v44) = "PULLED";
      v63 = idColor::colorRed;
    }
    HIDWORD(v46) = &byte_8200D768;
    v57.logIndex = weapon->fireState;
    if ( v57.logIndex == 1 )
    {
      HIDWORD(v46) = "FIRING";
    }
    else if ( v57.logIndex != 0 )
    {
      if ( v57.logIndex == 3 )
        HIDWORD(v46) = "RELOADING";
    }
    else
    {
      HIDWORD(v46) = "IDLE";
    }
    if ( ai->aiVolatile.memory.numShotsThisPullBlockedConsecutive <= 0 )
      LODWORD(v46) = "CLEAR";
    else
      LODWORD(v46) = "BLOCKED";
    if ( idAI2::GetEnemySenseState(this: ai, senseType: AISENSE_MAX) != nullptr )
    {
      EnemySenseState = (aiSenseState_t *)idAI2::GetEnemySenseState(this: ai, senseType: AISENSE_MAX);
      ConfirmedStimTimeSafe = aiSenseState_t::GetConfirmedStimTimeSafe(this: EnemySenseState);
      HIDWORD(v47) = ConfirmedStimTimeSafe - gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
    }
    else
    {
      HIDWORD(v47) = 99999;
    }
    v50 = va::va(
            this: &v69,
            fmt: "%s,%s,%s,%s,%d",
            a3: v44,
            a4: v46,
            a5: v47,
            a6: v51,
            a7: v52,
            a8: v53,
            a9: v54,
            a10: v55,
            a11: v56);
    ((void (__fastcall *)(idRenderWorld *, va *, idVec3 *, idRenderWorld_vtbl *, idColor *, int, _DWORD, _DWORD, double))clientGame->renderWorld->DebugText)(
      a1: clientGame->renderWorld,
      a2: v50,
      a3: &v64,
      a4: clientGame->renderWorld->__vftable,
      a5: &v63,
      a6: 1,
      a7: 0,
      a8: 0,
      a9: 0.2);
  }
  idPLogScope::~idPLogScope(this: &v58);
  RD_EventEnd();
  idPLogScope::~idPLogScope(this: v62);
  RD_EventEnd();
}


// ========================================================================
// __unwind$490113
// EA  : 0x82A499AC
// RVA : 0x00A499AC
// PDB : w:\tech5\tungsten\game\ai\aifirecontrol.cpp
// ========================================================================

void _unwind_490113()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 7088 + 6928));
}


// ========================================================================
// __unwind$490114
// EA  : 0x82A499D4
// RVA : 0x00A499D4
// PDB : w:\tech5\tungsten\game\ai\aifirecontrol.cpp
// ========================================================================

void _unwind_490114()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 7088 + 176));
}


// ========================================================================
// __unwind$490118
// EA  : 0x82A499FC
// RVA : 0x00A499FC
// PDB : w:\tech5\tungsten\game\ai\aifirecontrol.cpp
// ========================================================================

void _unwind_490118()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 7088 + 6929));
}


// ========================================================================
// __unwind$490119
// EA  : 0x82A49A24
// RVA : 0x00A49A24
// PDB : w:\tech5\tungsten\game\ai\aifirecontrol.cpp
// ========================================================================

void _unwind_490119()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 7088 + 96));
}


// ========================================================================
// __unwind$490115
// EA  : 0x82A49A4C
// RVA : 0x00A49A4C
// PDB : w:\tech5\tungsten\game\ai\aifirecontrol.cpp
// ========================================================================

void _unwind_490115()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 7088 + 6930));
}


// ========================================================================
// __unwind$490116
// EA  : 0x82A49A74
// RVA : 0x00A49A74
// PDB : w:\tech5\tungsten\game\ai\aifirecontrol.cpp
// ========================================================================

void _unwind_490116()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 7088 + 104));
}


// ========================================================================
// __unwind$490117
// EA  : 0x82A49A9C
// RVA : 0x00A49A9C
// PDB : w:\tech5\tungsten\game\ai\aifirecontrol.cpp
// ========================================================================

void _unwind_490117()
{
  int v0; // r12

  idFireParms::~idFireParms(this: (idAI2::idAIVolatile::idAIEventInfo *)(v0 - 7088 + 224));
}


// ========================================================================
// __unwind$490120
// EA  : 0x82A49AC4
// RVA : 0x00A49AC4
// PDB : w:\tech5\tungsten\game\ai\aifirecontrol.cpp
// ========================================================================

void _unwind_490120()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 7088 + 6931));
}


// ========================================================================
// __unwind$490121
// EA  : 0x82A49AEC
// RVA : 0x00A49AEC
// PDB : w:\tech5\tungsten\game\ai\aifirecontrol.cpp
// ========================================================================

void _unwind_490121()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 7088 + 104));
}


// ========================================================================
// __unwind$490122
// EA  : 0x82A49B14
// RVA : 0x00A49B14
// PDB : w:\tech5\tungsten\game\ai\aifirecontrol.cpp
// ========================================================================

void _unwind_490122()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 7088 + 6932));
}


// ========================================================================
// __unwind$490123
// EA  : 0x82A49B3C
// RVA : 0x00A49B3C
// PDB : w:\tech5\tungsten\game\ai\aifirecontrol.cpp
// ========================================================================

void _unwind_490123()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 7088 + 104));
}


// ========================================================================
// ?Update_Weapon@idAIFireControl@@MAAXPAVidAI2@@H@Z
// EA  : 0x82A49B70
// RVA : 0x00A49B70
// PDB : w:\tech5\tungsten\game\ai\aifirecontrol.cpp
// ========================================================================

void __fastcall idAIFireControl::Update_Weapon(idAIFireControl *this, idAI2 *owner, int curTime)
{
  unsigned __int64 v6; // r6
  const char *v7; // r7
  int v8; // r19
  int i; // r24
  const idAIFireControl::weaponInfo_t *v10; // r26
  idWeapon *EquippedWeapon; // r3
  idWeapon *v12; // r29
  int value; // r9
  idEntity *v14; // r3
  idEntity *v15; // r4
  idAIEntityState *v16; // r3
  idPLog *pLog; // r29
  idPLog::logEntry_t *v18; // r30
  int v19; // r3
  __int64 totalTicks; // r11
  __int64 v21; // r9
  idPLogScope v22; // [sp+50h] [-90h] BYREF
  updateWeaponStateParms_t v23; // [sp+58h] [-88h] BYREF

  RD_EventBegin(name: "idAIFireControl::Update_Weapon");
  LODWORD(v6) = "idAIFireControl::Update_Weapon";
  HIDWORD(v6) = 6;
  idPLogScope::idPLogScope(this: &v22, pl: &::pLog, gMask: v6, label: v7);
  v8 = this->NumWeaponInfos(this);
  for ( i = 0; i < v8; ++i )
  {
    v10 = this->GetWeaponInfo(this, a2: i);
    EquippedWeapon = idActor::GetEquippedWeapon(this: owner, slot: (const equipSlot_t)v10->slot);
    v12 = EquippedWeapon;
    if ( EquippedWeapon != nullptr )
    {
      if ( EquippedWeapon->triggerState == TRIGGERSTATE_PULLED
        && EquippedWeapon->NeedsReload(this: EquippedWeapon, a2: false) )
      {
        v12->ReleaseTrigger(this: v12, a2: owner);
      }
      value = owner->aiVolatile.memory.currentEnemy.spawnId.value;
      if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
        && (v14 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
      {
        v15 = idEntity::CastTo(c: v14);
      }
      else
      {
        v15 = nullptr;
      }
      v16 = idAIWorldState::StateForEntity(this: &owner->aiVolatile.world.worldState, ent: v15);
      v23.percentBlockedShotsToReleaseTrigger = 0.1;
      v23.fireType = WFT_SINGLE;
      v23.numBlockedShotsConsecutiveToReleaseTrigger = 1;
      idAIFireControl::UpdateWeaponState(this, ai: owner, weapon: v12, ees: v16, curTime, info: v10, updateParms: &v23);
    }
  }
  if ( v22.logIndex >= 0 )
  {
    pLog = v22.pLog;
    v18 = &v22.pLog->logEntries.list[v22.logIndex];
    v19 = (unsigned __int64)Sys_GetClockTicks() >> 32;
    totalTicks = v18->totalTicks;
    HIDWORD(totalTicks) = v18->parent;
    LODWORD(v21) = v19 - totalTicks;
    v18->totalTicks = v21;
    pLog->lastEntry = HIDWORD(totalTicks);
  }
  RD_EventEnd();
}


// ========================================================================
// __unwind$490688
// EA  : 0x82A49D40
// RVA : 0x00A49D40
// PDB : w:\tech5\tungsten\game\ai\aifirecontrol.cpp
// ========================================================================

void _unwind_490688()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 224 + 100));
}


// ========================================================================
// __unwind$490689
// EA  : 0x82A49D68
// RVA : 0x00A49D68
// PDB : w:\tech5\tungsten\game\ai\aifirecontrol.cpp
// ========================================================================

void _unwind_490689()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 224 + 80));
}


// ========================================================================
// ?Update_HoldFire@idAIFireControl@@MAAXPAVidAI2@@H@Z
// EA  : 0x82A49D98
// RVA : 0x00A49D98
// PDB : w:\tech5\tungsten\game\ai\aifirecontrol.cpp
// ========================================================================

void __fastcall idAIFireControl::Update_HoldFire(idAIFireControl *this, idAI2 *owner, int curTime)
{
  unsigned __int64 v6; // r6
  const char *v7; // r7
  int v8; // r19
  int i; // r23
  const idAIFireControl::weaponInfo_t *v10; // r26
  idWeapon *EquippedWeapon; // r3
  idWeapon *v12; // r28
  int value; // r9
  idEntity *v14; // r3
  idEntity *v15; // r4
  idAIEntityState *v16; // r3
  idPLog *pLog; // r29
  idPLog::logEntry_t *v18; // r30
  int v19; // r3
  __int64 totalTicks; // r11
  __int64 v21; // r9
  idPLogScope v22; // [sp+50h] [-90h] BYREF
  updateWeaponStateParms_t v23; // [sp+58h] [-88h] BYREF

  RD_EventBegin(name: "idAIFireControl::Update_HoldFire");
  LODWORD(v6) = "idAIFireControl::Update_HoldFire";
  HIDWORD(v6) = 6;
  idPLogScope::idPLogScope(this: &v22, pl: &::pLog, gMask: v6, label: v7);
  v8 = this->NumWeaponInfos(this);
  for ( i = 0; i < v8; ++i )
  {
    v10 = this->GetWeaponInfo(this, a2: i);
    EquippedWeapon = idActor::GetEquippedWeapon(this: owner, slot: (const equipSlot_t)v10->slot);
    v12 = EquippedWeapon;
    if ( EquippedWeapon != nullptr )
    {
      if ( EquippedWeapon->triggerState == TRIGGERSTATE_PULLED )
        idAIFireControl::ReleaseWeaponTrigger(this, owner, weapon: EquippedWeapon, curTime);
      value = owner->aiVolatile.memory.currentEnemy.spawnId.value;
      if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
        && (v14 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
      {
        v15 = idEntity::CastTo(c: v14);
      }
      else
      {
        v15 = nullptr;
      }
      v16 = idAIWorldState::StateForEntity(this: &owner->aiVolatile.world.worldState, ent: v15);
      v23.percentBlockedShotsToReleaseTrigger = 0.1;
      v23.fireType = WFT_SINGLE;
      v23.numBlockedShotsConsecutiveToReleaseTrigger = 1;
      idAIFireControl::UpdateWeaponState(this, ai: owner, weapon: v12, ees: v16, curTime, info: v10, updateParms: &v23);
    }
  }
  if ( v22.logIndex >= 0 )
  {
    pLog = v22.pLog;
    v18 = &v22.pLog->logEntries.list[v22.logIndex];
    v19 = (unsigned __int64)Sys_GetClockTicks() >> 32;
    totalTicks = v18->totalTicks;
    HIDWORD(totalTicks) = v18->parent;
    LODWORD(v21) = v19 - totalTicks;
    v18->totalTicks = v21;
    pLog->lastEntry = HIDWORD(totalTicks);
  }
  RD_EventEnd();
}


// ========================================================================
// __unwind$490794
// EA  : 0x82A49F44
// RVA : 0x00A49F44
// PDB : w:\tech5\tungsten\game\ai\aifirecontrol.cpp
// ========================================================================

void _unwind_490794()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 224 + 100));
}


// ========================================================================
// __unwind$490795
// EA  : 0x82A49F6C
// RVA : 0x00A49F6C
// PDB : w:\tech5\tungsten\game\ai\aifirecontrol.cpp
// ========================================================================

void _unwind_490795()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 224 + 80));
}


// ========================================================================
// ?Update_FireWhenReady@idAIFireControl@@MAAXPAVidAI2@@H@Z
// EA  : 0x82A49FA0
// RVA : 0x00A49FA0
// PDB : w:\tech5\tungsten\game\ai\aifirecontrol.cpp
// ========================================================================

void __fastcall idAIFireControl::Update_FireWhenReady(idAIFireControl *this, idAI2 *owner, int curTime)
{
  unsigned __int64 v6; // r6
  const char *v7; // r7
  int value; // r6
  idEntity *v9; // r4
  idEntity *v10; // r3
  int v11; // r3
  idInventoryItem *v12; // r29
  idFXManager *v13; // r30
  int GameMs; // r3
  idAIEntityState *v15; // r3
  idAIEntityState *v16; // r26
  aiSenseState_t *v17; // r29
  idPhysics *Physics; // r3
  float *v19; // r3
  double v20; // fp10
  double v21; // fp6
  int v22; // r21
  int i; // r24
  const idAIFireControl::weaponInfo_t *v24; // r27
  idWeapon *EquippedWeapon; // r3
  idWeapon *v26; // r29
  idWeapon::triggerState_t triggerState; // r11
  idPLogScope v28; // [sp+58h] [-88h] BYREF
  updateWeaponStateParms_t v29; // [sp+60h] [-80h] BYREF

  RD_EventBegin(name: "idAIFireControl::Update_FireWhenReady");
  LODWORD(v6) = "idAIFireControl::Update_FireWhenReady";
  HIDWORD(v6) = 6;
  idPLogScope::idPLogScope(this: &v28, pl: &pLog, gMask: v6, label: v7);
  value = owner->aiVolatile.memory.currentEnemy.spawnId.value;
  v9 = (idEntity *)((value & 0x1FFF) + 29755);
  if ( *((_DWORD *)&gameLocal->__vftable + (_DWORD)v9) == value >> 13
    && (v10 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr
    && (v9 = idEntity::CastTo(c: v10)) != nullptr )
  {
    v15 = idAIWorldState::StateForEntity(this: &owner->aiVolatile.world.worldState, ent: v9);
    v16 = v15;
    if ( v15 != nullptr )
    {
      v17 = v15->senses.ptr[v15->lastSense];
      if ( v17->lastUnconfirmedStimTime >= 0 )
      {
        Physics = idEntity::GetPhysics(this: owner);
        v19 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
        v20 = (float)(v17->unConfirmedPhysical.origin.y - v19[1]);
        v21 = (float)(v17->unConfirmedPhysical.origin.z - v19[2]);
        this->freeAmmo = __fsqrts((float)((float)((float)v21 * (float)v21)
                                        + (float)((float)((float)(v17->unConfirmedPhysical.origin.x - *v19)
                                                        * (float)(v17->unConfirmedPhysical.origin.x - *v19))
                                                + (float)((float)v20 * (float)v20)))) < owner->aiEditable.behaviors.decl->freeAmmoDistance
                      || (HIWORD(owner->aiVolatile.groupStatus.condition) & 1) != 0;
      }
      v22 = this->NumWeaponInfos(this);
      if ( this->CanFireWeapons(this, a2: owner, a3: v16, a4: curTime) )
      {
        for ( i = 0; i < v22; ++i )
        {
          v24 = this->GetWeaponInfo(this, a2: i);
          EquippedWeapon = idActor::GetEquippedWeapon(this: owner, slot: (const equipSlot_t)v24->slot);
          v26 = EquippedWeapon;
          if ( EquippedWeapon != nullptr )
          {
            triggerState = EquippedWeapon->triggerState;
            if ( triggerState != TRIGGERSTATE_PULLED )
            {
              if ( triggerState == TRIGGERSTATE_RELEASED
                && (unsigned __int8)idAIFireControl::CheckPullTrigger(
                                      this,
                                      owner,
                                      weapon: EquippedWeapon,
                                      ees: v16,
                                      curTime,
                                      info: v24) != 0 )
              {
                idAIFireControl::PullWeaponTrigger(this, owner, weapon: v26, ees: v16, curTime);
              }
            }
            else if ( (unsigned __int8)idAIFireControl::CheckReleaseTrigger(
                                         this,
                                         owner,
                                         weapon: EquippedWeapon,
                                         ees: v16,
                                         curTime,
                                         info: v24) != 0 )
            {
              idAIFireControl::ReleaseWeaponTrigger(this, owner, weapon: v26, curTime);
            }
            v29.percentBlockedShotsToReleaseTrigger = 0.1;
            v29.fireType = WFT_SINGLE;
            v29.numBlockedShotsConsecutiveToReleaseTrigger = 1;
            idAIFireControl::UpdateWeaponState(
              this,
              ai: owner,
              weapon: v26,
              ees: v16,
              curTime,
              info: v24,
              updateParms: &v29);
          }
        }
      }
    }
  }
  else
  {
    v11 = ((int (__fastcall *)(idAI2 *, idEntity *))owner->GetEquippedWeapon)(a1: owner, a2: v9);
    v12 = (idInventoryItem *)v11;
    if ( v11 != 0 && *(_DWORD *)(v11 + 68) == 0 )
    {
      idAIFireControl::ReleaseWeaponTrigger(this, owner, weapon: (idWeapon *)v11, curTime);
      v13 = owner->GetFXMgrForAttachment(this: owner, a2: v12);
      if ( v13 != nullptr )
      {
        GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        idFXManager::StopAllFX(this: v13, time: GameMs, immediateStop: true);
      }
    }
  }
  idPLogScope::~idPLogScope(this: &v28);
  RD_EventEnd();
}


// ========================================================================
// __unwind$490898
// EA  : 0x82A4A320
// RVA : 0x00A4A320
// PDB : w:\tech5\tungsten\game\ai\aifirecontrol.cpp
// ========================================================================

void _unwind_490898()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 224 + 108));
}


// ========================================================================
// __unwind$490899
// EA  : 0x82A4A348
// RVA : 0x00A4A348
// PDB : w:\tech5\tungsten\game\ai\aifirecontrol.cpp
// ========================================================================

void _unwind_490899()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 224 + 88));
}


// ========================================================================
// ?Update_SprayWhenReady@idAIFireControl@@MAAXPAVidAI2@@H@Z
// EA  : 0x82A4A378
// RVA : 0x00A4A378
// PDB : w:\tech5\tungsten\game\ai\aifirecontrol.cpp
// ========================================================================

void __fastcall idAIFireControl::Update_SprayWhenReady(idAIFireControl *this, idAI2 *owner, int curTime)
{
  unsigned __int64 v6; // r6
  const char *v7; // r7
  int value; // r6
  idEntity *v9; // r4
  idEntity *v10; // r3
  int v11; // r3
  idInventoryItem *v12; // r28
  idFXManager *v13; // r30
  int GameMs; // r3
  idAIEntityState *v15; // r25
  idAIFireControl_vtbl *v16; // r10
  int v17; // r21
  int i; // r24
  const idAIFireControl::weaponInfo_t *v19; // r26
  idWeapon *EquippedWeapon; // r3
  idWeapon *v21; // r28
  idWeapon::triggerState_t triggerState; // r11
  idPLogScope v23; // [sp+50h] [-80h] BYREF
  updateWeaponStateParms_t v24; // [sp+58h] [-78h] BYREF

  RD_EventBegin(name: "idAIFireControl::Update_FireWhenReady");
  LODWORD(v6) = "idAIFireControl::Update_FireWhenReady";
  HIDWORD(v6) = 6;
  idPLogScope::idPLogScope(this: &v23, pl: &pLog, gMask: v6, label: v7);
  value = owner->aiVolatile.memory.currentEnemy.spawnId.value;
  v9 = (idEntity *)((value & 0x1FFF) + 29755);
  if ( *((_DWORD *)&gameLocal->__vftable + (_DWORD)v9) == value >> 13
    && (v10 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr
    && (v9 = idEntity::CastTo(c: v10)) != nullptr )
  {
    v15 = idAIWorldState::StateForEntity(this: &owner->aiVolatile.world.worldState, ent: v9);
    if ( v15 != nullptr )
    {
      v16 = this->__vftable;
      this->freeAmmo = true;
      v17 = v16->NumWeaponInfos(this);
      if ( this->CanFireWeapons(this, a2: owner, a3: v15, a4: curTime) )
      {
        for ( i = 0; i < v17; ++i )
        {
          v19 = this->GetWeaponInfo(this, a2: i);
          EquippedWeapon = idActor::GetEquippedWeapon(this: owner, slot: (const equipSlot_t)v19->slot);
          v21 = EquippedWeapon;
          if ( EquippedWeapon != nullptr )
          {
            triggerState = EquippedWeapon->triggerState;
            if ( triggerState != TRIGGERSTATE_PULLED )
            {
              if ( triggerState == TRIGGERSTATE_RELEASED
                && (unsigned __int8)idAIFireControl::CheckPullTrigger(
                                      this,
                                      owner,
                                      weapon: EquippedWeapon,
                                      ees: v15,
                                      curTime,
                                      info: v19) != 0 )
              {
                idAIFireControl::PullWeaponTrigger(this, owner, weapon: v21, ees: v15, curTime);
              }
            }
            else if ( (unsigned __int8)idAIFireControl::CheckReleaseTrigger(
                                         this,
                                         owner,
                                         weapon: EquippedWeapon,
                                         ees: v15,
                                         curTime,
                                         info: v19) != 0 )
            {
              idAIFireControl::ReleaseWeaponTrigger(this, owner, weapon: v21, curTime);
            }
            v24.percentBlockedShotsToReleaseTrigger = 0.69999999;
            v24.fireType = WFT_SPRAY;
            v24.numBlockedShotsConsecutiveToReleaseTrigger = 5;
            idAIFireControl::UpdateWeaponState(
              this,
              ai: owner,
              weapon: v21,
              ees: v15,
              curTime,
              info: v19,
              updateParms: &v24);
          }
        }
      }
    }
  }
  else
  {
    v11 = ((int (__fastcall *)(idAI2 *, idEntity *))owner->GetEquippedWeapon)(a1: owner, a2: v9);
    v12 = (idInventoryItem *)v11;
    if ( v11 != 0 && *(_DWORD *)(v11 + 68) == 0 )
    {
      idAIFireControl::ReleaseWeaponTrigger(this, owner, weapon: (idWeapon *)v11, curTime);
      v13 = owner->GetFXMgrForAttachment(this: owner, a2: v12);
      if ( v13 != nullptr )
      {
        GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        idFXManager::StopAllFX(this: v13, time: GameMs, immediateStop: true);
      }
    }
  }
  idPLogScope::~idPLogScope(this: &v23);
  RD_EventEnd();
}


// ========================================================================
// __unwind$491094
// EA  : 0x82A4A654
// RVA : 0x00A4A654
// PDB : w:\tech5\tungsten\game\ai\aifirecontrol.cpp
// ========================================================================

void _unwind_491094()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 208 + 100));
}


// ========================================================================
// __unwind$491095
// EA  : 0x82A4A67C
// RVA : 0x00A4A67C
// PDB : w:\tech5\tungsten\game\ai\aifirecontrol.cpp
// ========================================================================

void _unwind_491095()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 208 + 80));
}

