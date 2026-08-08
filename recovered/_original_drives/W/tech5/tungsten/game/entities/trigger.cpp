
// ========================================================================
// ?EnableClip@idTrigger@@QAAXXZ
// EA  : 0x82CECC90
// RVA : 0x00CECC90
// PDB : w:\tech5\tungsten\game\entities\trigger.cpp
// ========================================================================

void __fastcall idTrigger::EnableClip(idTrigger *this)
{
  idPhysics *Physics; // r3
  idPhysics *v3; // r3

  Physics = idEntity::GetPhysics(this);
  Physics->SetContents(this: Physics, a2: this->extraContents | 0x4000, a3: -1);
  v3 = idEntity::GetPhysics(this);
  v3->EnableClip(this: v3);
}


// ========================================================================
// ?DisableClip@idTrigger@@QAAXXZ
// EA  : 0x82CECCF0
// RVA : 0x00CECCF0
// PDB : w:\tech5\tungsten\game\entities\trigger.cpp
// ========================================================================

void __fastcall idTrigger::DisableClip(idTrigger *this)
{
  idPhysics *Physics; // r3
  idPhysics *v3; // r3

  Physics = idEntity::GetPhysics(this);
  Physics->SetContents(this: Physics, a2: 0, a3: -1);
  v3 = idEntity::GetPhysics(this);
  v3->DisableClip(this: v3);
}


// ========================================================================
// ?OnMakeActivatable@idTrigger@@MAAX_N@Z
// EA  : 0x82CECD50
// RVA : 0x00CECD50
// PDB : w:\tech5\tungsten\game\entities\trigger.cpp
// ========================================================================

void __fastcall idTrigger::OnMakeActivatable(idTrigger *this, const bool activatable)
{
  idPhysics *Physics; // r3
  idPhysics *v4; // r3

  if ( activatable )
  {
    idTrigger::EnableClip(this);
  }
  else
  {
    Physics = idEntity::GetPhysics(this);
    Physics->SetContents(this: Physics, a2: 0, a3: -1);
    v4 = idEntity::GetPhysics(this);
    v4->DisableClip(this: v4);
  }
}


// ========================================================================
// ?OnActivate@idTrigger_Hurt@@EAAXPAVidEntity@@@Z
// EA  : 0x82CECDD0
// RVA : 0x00CECDD0
// PDB : w:\tech5\tungsten\game\entities\trigger.cpp
// ========================================================================

void __fastcall idTrigger_Hurt::OnActivate(idTrigger_Hurt *this, idEntity *activator)
{
  if ( this->triggerFirst )
  {
    this->triggerFirst = false;
    idTrigger::EnableClip(this);
  }
}


// ========================================================================
// ?Spawn@idTrigger@@QAAXXZ
// EA  : 0x82CECDF0
// RVA : 0x00CECDF0
// PDB : w:\tech5\tungsten\game\entities\trigger.cpp
// ========================================================================

void __fastcall idTrigger::Spawn(idTrigger *this)
{
  idPhysics *Physics; // r3
  idPhysics *v3; // r3

  if ( this->triggerFirst )
  {
    Physics = idEntity::GetPhysics(this);
    Physics->SetContents(this: Physics, a2: 0, a3: -1);
    v3 = idEntity::GetPhysics(this);
    v3->DisableClip(this: v3);
  }
  else if ( (*(_BYTE *)&this->flags & 8) != 0 )
  {
    idTrigger::EnableClip(this);
  }
  else
  {
    idTrigger::DisableClip(this);
  }
}


// ========================================================================
// ?CanActivate@idTrigger@@MAA_NPAVidEntity@@@Z
// EA  : 0x82CECEA0
// RVA : 0x00CECEA0
// PDB : w:\tech5\tungsten\game\entities\trigger.cpp
// ========================================================================

unsigned int __fastcall idTrigger::CanActivate(idTrigger *this, idEntity *activator)
{
  int GameMs; // r3

  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  return (GameMs >> 31) + ((unsigned int)GameMs >= this->nextTriggerTime) + ((unsigned int)this->nextTriggerTime >> 31);
}


// ========================================================================
// ?Event_Enable@idTrigger@@IAA?AVeventVoid@@XZ
// EA  : 0x82CECEF8
// RVA : 0x00CECEF8
// PDB : w:\tech5\tungsten\game\entities\trigger.cpp
// ========================================================================

idTrigger *__fastcall idTrigger::Event_Enable(idTrigger *this, idEntity *result)
{
  idPhysics *Physics; // r3
  idPhysics *v5; // r3

  BYTE1(result[1].listeningToList) = 0;
  Physics = idEntity::GetPhysics(this: result);
  Physics->SetContents(this: Physics, a2: *(_DWORD *)&result[1].flags | 0x4000, a3: -1);
  v5 = idEntity::GetPhysics(this: result);
  v5->EnableClip(this: v5);
  return this;
}


// ========================================================================
// ?Event_Disable@idTrigger@@IAA?AVeventVoid@@XZ
// EA  : 0x82CECF78
// RVA : 0x00CECF78
// PDB : w:\tech5\tungsten\game\entities\trigger.cpp
// ========================================================================

idTrigger *__fastcall idTrigger::Event_Disable(idTrigger *this, idEntity *result)
{
  idPhysics *Physics; // r3
  idPhysics *v5; // r3

  Physics = idEntity::GetPhysics(this: result);
  Physics->SetContents(this: Physics, a2: 0, a3: -1);
  v5 = idEntity::GetPhysics(this: result);
  v5->DisableClip(this: v5);
  return this;
}


// ========================================================================
// ?Event_GetUserData@idTrigger@@IAA?AVeventString@@XZ
// EA  : 0x82CECFE8
// RVA : 0x00CECFE8
// PDB : w:\tech5\tungsten\game\entities\trigger.cpp
// ========================================================================

idTrigger *__fastcall idTrigger::Event_GetUserData(idTrigger *this, eventString *result)
{
  eventString::eventString((eventString *)this, s: result[212].value);
  return this;
}


// ========================================================================
// ?CanActivate@idTrigger_TestPlayerState@@MAA_NPAVidEntity@@@Z
// EA  : 0x82CED020
// RVA : 0x00CED020
// PDB : w:\tech5\tungsten\game\entities\trigger.cpp
// ========================================================================

int __fastcall idTrigger_TestPlayerState::CanActivate(idTrigger_TestPlayerState *this, idEntity *activator)
{
  idPlayer *PlayerFromEntity; // r3
  idPlayer *v5; // r21
  idVehicle *Control; // r3
  idVehicle *v8; // r3
  idVehicleKey *playerKey; // r11
  unsigned __int8 v10; // r20
  char v11; // r27
  char v12; // r26
  idInventoryCollection *v13; // r29
  int v14; // r28
  int v15; // r30
  idTrigger_TestPlayerState::playerState_Inventory_t *v16; // r31
  unsigned __int8 v17; // r22
  char v18; // r27
  char v19; // r29
  int v20; // r30
  int v21; // r31
  idTrigger_TestPlayerState::playerState_Job_t *v22; // r11
  idJob *InventoryItemByDeclName; // r3
  __int32 status; // r10
  idTrigger_TestPlayerState::playerState_Job_t *v25; // r11
  int maxStatus; // r11
  unsigned __int8 v27; // r23
  char v28; // r27
  char v29; // r26
  int v30; // r28
  int v31; // r30
  idTrigger_TestPlayerState::playerState_GameState_t *list; // r11
  int v33; // r31
  unsigned int GameStateIntValue; // r3
  idTrigger_TestPlayerState::playerState_GameState_t *v35; // r11
  idGameStateInt::gameStateIntCompare_t comparison; // r10
  unsigned int comparisonValue; // r11
  bool v38; // xer_ca
  unsigned int v39; // r9
  unsigned int v40; // r11
  unsigned __int8 v41; // r29
  int v42; // r30
  int v43; // r31
  bool v44; // r11
  bool v45; // r8
  bool v46; // r11
  bool v47; // r9
  bool v48; // r11
  bool v49; // r10
  bool v50; // r11
  const idDeclGameStateInt *givenGameStateInt; // r4

  if ( idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) < this->nextTriggerTime )
    return 0;
  PlayerFromEntity = idGameLocal::GetPlayerFromEntity(this: gameLocal, activator);
  v5 = PlayerFromEntity;
  if ( PlayerFromEntity == nullptr )
  {
    idLib::Warning(fmt: "No player found on idTrigger_TestPlayerState: %s", this->name.data);
    return 0;
  }
  if ( this->vehicleClassTest != VEHICLE_CLASSNONE )
  {
    Control = (idVehicle *)idPlayer::GetControl(this: PlayerFromEntity);
    v8 = idVehicle::CastTo(c: Control);
    if ( v8 == nullptr )
      return 0;
    playerKey = v8->playerKey;
    if ( playerKey == nullptr || playerKey->decl[1].__vftable != (idDeclInventory_vtbl *)this->vehicleClassTest )
      return 0;
  }
  v10 = 1;
  if ( this->requiredItemList.num <= 0 )
    goto LABEL_23;
  v10 = 0;
  v11 = 0;
  v12 = 1;
  v13 = v5->GetInventory_2(this: v5);
  if ( v13 != nullptr )
  {
    v14 = 0;
    if ( this->requiredItemList.num > 0 )
    {
      v15 = 0;
      do
      {
        v16 = &this->requiredItemList.list[v15];
        if ( idInventoryCollection::FindTotalInventoryItemCount(this: v13, decl: v16->requiredItem) < v16->requiredCount )
          v12 = 0;
        else
          v11 = 1;
        ++v14;
        ++v15;
      }
      while ( v14 < this->requiredItemList.num );
    }
    if ( this->anyItemActivates )
    {
      if ( v11 != 0 )
        goto LABEL_22;
      if ( this->anyItemActivates )
        goto LABEL_23;
    }
    if ( v12 == 0 )
      goto LABEL_23;
LABEL_22:
    v10 = 1;
    goto LABEL_23;
  }
  idLib::Warning(fmt: "idTrigger_TestPlayerState player does not have inventory %s", v5->name.data);
LABEL_23:
  v17 = 1;
  if ( this->requiredJobsList.num <= 0 )
    goto LABEL_43;
  v17 = 0;
  v18 = 0;
  v19 = 1;
  v20 = 0;
  v21 = 0;
  do
  {
    v22 = &this->requiredJobsList.list[v21];
    if ( v22->job.len != 0 )
    {
      InventoryItemByDeclName = idInventoryCollection::FindInventoryItemByDeclName(
                                  this: &v5->jobManager,
                                  jobName: v22->job.data);
      status = 0;
      if ( InventoryItemByDeclName != nullptr )
        status = InventoryItemByDeclName->status;
      v25 = &this->requiredJobsList.list[v21];
      if ( v25->mustBeNone )
      {
        if ( status == 0 )
          goto LABEL_30;
      }
      else
      {
        if ( status < v25->minStatus )
        {
          v19 = 0;
          goto LABEL_37;
        }
        maxStatus = v25->maxStatus;
        if ( maxStatus <= 0 || status <= maxStatus )
        {
LABEL_30:
          v18 = 1;
          goto LABEL_37;
        }
      }
      v19 = 0;
    }
    else
    {
      idLib::Warning(fmt: "idTrigger_TestPlayerState null job decl in job test at %d", v20);
    }
LABEL_37:
    ++v20;
    ++v21;
  }
  while ( v20 < this->requiredJobsList.num );
  if ( !this->anyJobActivates )
    goto LABEL_41;
  if ( v18 != 0 )
  {
LABEL_42:
    v17 = 1;
  }
  else if ( !this->anyJobActivates )
  {
LABEL_41:
    if ( v19 != 0 )
      goto LABEL_42;
  }
LABEL_43:
  v27 = 1;
  if ( this->requiredGameStateIntList.num <= 0 )
    goto LABEL_63;
  v27 = 0;
  v28 = 0;
  v29 = 1;
  v30 = 0;
  v31 = 0;
  while ( 2 )
  {
    list = this->requiredGameStateIntList.list;
    if ( list[v31].gameStateInt != nullptr )
    {
      LOBYTE(v33) = 0;
      GameStateIntValue = idJobManager::GetGameStateIntValue(this: &v5->jobManager, gameState: list[v31].gameStateInt);
      v35 = &this->requiredGameStateIntList.list[v31];
      comparison = v35->comparison;
      switch ( comparison )
      {
        case GAMESTATEINT_LESS_THAN:
          comparisonValue = v35->comparisonValue;
          v38 = GameStateIntValue >= comparisonValue;
          v39 = ~(comparisonValue ^ GameStateIntValue);
          goto LABEL_52;
        case GAMESTATEINT_EQUAL:
          LOBYTE(v33) = (_cntlzw(v35->comparisonValue - GameStateIntValue) & 0x20) != 0;
          break;
        case GAMESTATEINT_GREATER_THAN:
          v40 = v35->comparisonValue;
          v38 = v40 >= GameStateIntValue;
          v39 = ~(GameStateIntValue ^ v40);
LABEL_52:
          v33 = ((v39 >> 31) + v38) & 1;
          break;
        default:
          break;
      }
      if ( (_BYTE)v33 != 0 )
        v28 = 1;
      else
        v29 = 0;
    }
    else
    {
      idLib::Warning(fmt: "idTrigger_TestPlayerState null game state decl at %d", v30);
    }
    ++v30;
    ++v31;
    if ( v30 < this->requiredGameStateIntList.num )
      continue;
    break;
  }
  if ( !this->anyGameStateIntActivate )
    goto LABEL_61;
  if ( v28 != 0 )
  {
LABEL_62:
    v27 = 1;
  }
  else if ( !this->anyGameStateIntActivate )
  {
LABEL_61:
    if ( v29 != 0 )
      goto LABEL_62;
  }
LABEL_63:
  v41 = 1;
  v42 = 0;
  if ( this->requiredDLCStateList.num > 0 )
  {
    v43 = 0;
    while ( idGameLocal::IsDLCStateActive(this: gameLocal, dlcState: this->requiredDLCStateList.list[v43]) )
    {
      ++v42;
      ++v43;
      if ( v42 >= this->requiredDLCStateList.num )
        goto LABEL_69;
    }
    v41 = 0;
  }
LABEL_69:
  v44 = v41;
  if ( this->fireOnDLCStateFail )
    v44 = (_cntlzw(v41) & 0x20) != 0;
  v45 = v44;
  v46 = v10;
  if ( this->fireOnInventoryFail )
    v46 = (_cntlzw(v10) & 0x20) != 0;
  v47 = v46;
  v48 = v17;
  if ( this->fireOnJobFail )
    v48 = (_cntlzw(v17) & 0x20) != 0;
  v49 = v48;
  v50 = v27;
  if ( this->fireOnGameStateFail )
    v50 = (_cntlzw(v27) & 0x20) != 0;
  if ( !v45 || !v47 || !v49 || !v50 )
    return 0;
  givenGameStateInt = this->givenGameStateInt;
  if ( givenGameStateInt != nullptr )
    idJobManager::SetGameStateIntValue(this: &v5->jobManager, gameState: givenGameStateInt, stateValue: 1);
  return 1;
}


// ========================================================================
// ?Event_Touch@idTrigger_PlayerIndefiniteSprint@@IAA?AVeventVoid@@PAVidEntity@@H@Z
// EA  : 0x82CED500
// RVA : 0x00CED500
// PDB : w:\tech5\tungsten\game\entities\trigger.cpp
// ========================================================================

idTrigger_PlayerIndefiniteSprint *__fastcall idTrigger_PlayerIndefiniteSprint::Event_Touch(
        idTrigger_PlayerIndefiniteSprint *this,
        eventVoid *result,
        idPlayer *other,
        int clipModelId)
{
  idPlayer *v5; // r3
  idPlayer *v6; // r31
  idPresentable *presentable; // r3

  v5 = idPlayer::CastTo(c: other);
  v6 = v5;
  if ( v5 != nullptr )
  {
    presentable = v5->presentable;
    if ( presentable != nullptr && presentable->GetPlayerInterface_2(this: presentable) != nullptr )
      idPlayer::ResetSprintTimer(this: v6);
  }
  return this;
}


// ========================================================================
// ?Spawn@idTrigger_Damage@@QAAXXZ
// EA  : 0x82CED580
// RVA : 0x00CED580
// PDB : w:\tech5\tungsten\game\entities\trigger.cpp
// ========================================================================

void __fastcall idTrigger_Damage::Spawn(idTrigger_Damage *this)
{
  const idDeclDamage *damageDef; // r11

  damageDef = this->damageDef;
  *(_BYTE *)&this->flags |= 2u;
  if ( damageDef != nullptr && (damageDef->damageTypes & 0x4000) != 0 )
    this->canLasercutterActivate = true;
}


// ========================================================================
// ?CanDamage@idTrigger_Damage@@IBA_NPAVidEntity@@0PBVidDeclDamage@@@Z
// EA  : 0x82CED5B8
// RVA : 0x00CED5B8
// PDB : w:\tech5\tungsten\game\entities\trigger.cpp
// ========================================================================

int __fastcall idTrigger_Damage::CanDamage(
        idTrigger_Damage *this,
        idEntity *inflictor,
        idEntity *attacker,
        const idDeclDamage *damageDecl)
{
  idPhysics *Physics; // r3
  int result; // r3
  const idDeclEntityDef *inflictorDef; // r11
  const idDeclEntityDef *attackerDef; // r11
  const idDeclDamage *damageDef; // r11

  Physics = idEntity::GetPhysics(this);
  if ( !Physics->GetClipModel(this: Physics, a2: 0)->enabled )
    return 0;
  inflictorDef = this->inflictorDef;
  if ( inflictorDef != nullptr && (inflictor == nullptr || inflictor->entityDef != inflictorDef) )
    return 0;
  attackerDef = this->attackerDef;
  if ( attackerDef != nullptr && (attacker == nullptr || attacker->entityDef != attackerDef) )
    return 0;
  damageDef = this->damageDef;
  if ( damageDef == nullptr )
    return 1;
  result = 0;
  if ( damageDecl == damageDef )
    return 1;
  return result;
}


// ========================================================================
// ?Damage@idTrigger_Damage@@UAAMPAVidEntity@@0PBVidDeclDamage@@MABVidVec3@@PAUtrace_t@@@Z
// EA  : 0x82CED668
// RVA : 0x00CED668
// PDB : w:\tech5\tungsten\game\entities\trigger.cpp
// ========================================================================

float __fastcall idTrigger_Damage::Damage(
        idTrigger_Damage *this,
        idEntity *inflictor,
        idEntity *attacker,
        const idDeclDamage *damageDecl,
        double damageScale,
        const idVec3 *dir,
        trace_t *trace)
{
  double v11; // fp1
  double v12; // fp31
  double v13; // fp0
  idEventArg *v14; // r3
  idEventArg v16; // [sp+50h] [-40h] BYREF

  if ( (unsigned __int8)idTrigger_Damage::CanDamage(this, inflictor, attacker, damageDecl) != 0 )
  {
    v12 = (float)(idDeclDamage::DamageAmount(this: damageDecl) * (float)damageScale);
    v13 = (float)(this->health - (float)v12);
    if ( v13 >= 0.0 )
    {
      if ( v13 > 1.0e30 )
        v13 = 1.0e30;
    }
    else
    {
      v13 = 0.0;
    }
    this->health = v13;
    if ( v13 <= 0.0 )
    {
      v14 = idEventArg::idEventArg(this: &v16, data: attacker);
      idEventReceiver::PostEventMS(
        this,
        ev: &EV_Activate,
        time: *(_DWORD *)&v14->type,
        arg1: (const idEventArg *)LODWORD(v14->value.v[1]));
    }
    v11 = v12;
  }
  else
  {
    v11 = 0.0;
  }
  return *((float *)&v11 + 1);
}


// ========================================================================
// ?Spawn@idTrigger_TakeDamage@@QAAXXZ
// EA  : 0x82CED740
// RVA : 0x00CED740
// PDB : w:\tech5\tungsten\game\entities\trigger.cpp
// ========================================================================

void __fastcall idTrigger_TakeDamage::Spawn(idTrigger_TakeDamage *this)
{
  int v1; // r9
  const idDeclDamage **list; // r8
  int v3; // r11
  const idDeclDamage *v4; // r10

  v1 = 0;
  if ( this->alternativeDamageDefs.num > 0 )
  {
    list = this->alternativeDamageDefs.list;
    v3 = 0;
    do
    {
      v4 = list[v3];
      if ( v4 != nullptr && (v4->damageTypes & 0x4000) != 0 )
        this->canLasercutterActivate = true;
      ++v1;
      ++v3;
    }
    while ( v1 < this->alternativeDamageDefs.num );
  }
}


// ========================================================================
// ?CanDamage@idTrigger_TakeDamage@@IBA_NPAVidEntity@@0PBVidDeclDamage@@@Z
// EA  : 0x82CED798
// RVA : 0x00CED798
// PDB : w:\tech5\tungsten\game\entities\trigger.cpp
// ========================================================================

int __fastcall idTrigger_TakeDamage::CanDamage(
        idTrigger_TakeDamage *this,
        idEntity *inflictor,
        idEntity *attacker,
        const idDeclDamage *damageDecl)
{
  const idDeclEntityDef *inflictorDef; // r11
  int num; // r8
  int v9; // r10

  if ( (unsigned __int8)idTrigger_Damage::CanDamage(this, inflictor, attacker, damageDecl) != 0 )
    return 1;
  if ( this->attackerDef == nullptr )
  {
    inflictorDef = this->inflictorDef;
    if ( inflictorDef == nullptr )
    {
      num = this->alternativeDamageDefs.num;
      v9 = 0;
      if ( num > 0 )
      {
        while ( damageDecl != *(const idDeclDamage **)((char *)&inflictorDef->__vftable
                                                     + (unsigned int)this->alternativeDamageDefs.list) )
        {
          ++v9;
          inflictorDef = (const idDeclEntityDef *)((char *)inflictorDef + 4);
          if ( v9 >= num )
            return 0;
        }
        return 1;
      }
    }
  }
  return 0;
}


// ========================================================================
// ?Spawn@idTrigger_DamageType@@QAAXXZ
// EA  : 0x82CED830
// RVA : 0x00CED830
// PDB : w:\tech5\tungsten\game\entities\trigger.cpp
// ========================================================================

void __fastcall idTrigger_DamageType::Spawn(idTrigger_DamageType *this)
{
  *(_BYTE *)&this->flags |= 2u;
}


// ========================================================================
// ?AllocPresentable@idTrigger_Multiplayer@@UAAPAVidPresentable@@PAVidRenderModel@@@Z
// EA  : 0x82CED848
// RVA : 0x00CED848
// PDB : w:\tech5\tungsten\game\entities\trigger.cpp
// ========================================================================

idPresentableCollisionTrigger *__fastcall idTrigger_Multiplayer::AllocPresentable(
        idTrigger_Multiplayer *this,
        idTreeAnimator *renderModel_)
{
  idPresentableCollisionTrigger *v4; // r3

  v4 = (idPresentableCollisionTrigger *)idMem::AllocWithLocation(
                                          this: &mem,
                                          location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                          size: 0x4B8u,
                                          tag: TAG_PRESENTABLE,
                                          zeroBuffer: false,
                                          align: ALIGN_16,
                                          heap: HEAP_DEFAULTHEAP);
  if ( v4 != nullptr )
    return idPresentableCollisionTrigger::idPresentableCollisionTrigger(
             this: v4,
             e: this,
             renderModel_,
             entityNumber_: this->entityNumber,
             fxDecl_: nullptr);
  else
    return nullptr;
}


// ========================================================================
// __unwind$492575
// EA  : 0x82CED8B8
// RVA : 0x00CED8B8
// PDB : w:\tech5\tungsten\game\entities\trigger.cpp
// ========================================================================

void _unwind_492575()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_PRESENTABLE);
}


// ========================================================================
// ?Event_Touch@idTrigger_GameChallenge@@QAA?AVeventVoid@@PAVidEntity@@H@Z
// EA  : 0x82CED8E8
// RVA : 0x00CED8E8
// PDB : w:\tech5\tungsten\game\entities\trigger.cpp
// ========================================================================

idTrigger_GameChallenge *__fastcall idTrigger_GameChallenge::Event_Touch(
        idTrigger_GameChallenge *this,
        idTrigger_GameChallenge *result,
        idEntity *other,
        int clipModelId)
{
  idGameChallenge *ChallengeEntity; // r3

  ChallengeEntity = idGameLocal::GetChallengeEntity(this: gameLocal);
  ChallengeEntity->OnTriggerTouched(this: ChallengeEntity, a2: result, a3: other, a4: clipModelId);
  return this;
}


// ========================================================================
// ?Event_Touch@idTrigger_RemoveEntities@@QAA?AVeventVoid@@PAVidEntity@@H@Z
// EA  : 0x82CED938
// RVA : 0x00CED938
// PDB : w:\tech5\tungsten\game\entities\trigger.cpp
// ========================================================================

idTrigger_RemoveEntities *__fastcall idTrigger_RemoveEntities::Event_Touch(
        idTrigger_RemoveEntities *this,
        eventVoid *result,
        idProjectile *other,
        int clipModelId)
{
  if ( other != nullptr && idProjectile::CastTo(c: other) != nullptr )
    idEventReceiver::PostEventMS(this: other, ev: &EV_Remove, time: 0);
  return this;
}


// ========================================================================
// ?AllocPresentable@idTrigger_BoostPad@@UAAPAVidPresentable@@PAVidRenderModel@@@Z
// EA  : 0x82CED9A8
// RVA : 0x00CED9A8
// PDB : w:\tech5\tungsten\game\entities\trigger.cpp
// ========================================================================

idPresentable *__fastcall idTrigger_BoostPad::AllocPresentable(idTrigger_BoostPad *this, idTreeAnimator *renderModel_)
{
  idPresentable *v4; // r3

  v4 = (idPresentable *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                          size: 0x4B0u,
                          tag: TAG_PRESENTABLE,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
  if ( v4 != nullptr )
    return idPresentable::idPresentable(
             this: v4,
             e: this,
             renderModel_,
             entityNumber_: this->entityNumber,
             fxDecl_: this->fxDecl);
  else
    return nullptr;
}


// ========================================================================
// __unwind$492635
// EA  : 0x82CEDA18
// RVA : 0x00CEDA18
// PDB : w:\tech5\tungsten\game\entities\trigger.cpp
// ========================================================================

void _unwind_492635()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_PRESENTABLE);
}


// ========================================================================
// ??1idTrigger_DummyFire@@UAA@XZ
// EA  : 0x82CEDA50
// RVA : 0x00CEDA50
// PDB : w:\tech5\tungsten\game\entities\trigger.cpp
// ========================================================================

void __fastcall idTrigger_DummyFire::~idTrigger_DummyFire(idTrigger_DummyFire *this)
{
  idWeapon *weapon; // r3

  this->__vftable = (idTrigger_DummyFire_vtbl *)&idTrigger_DummyFire::`vftable';
  weapon = this->weapon;
  if ( weapon != nullptr )
  {
    ((void (__fastcall *)(idWeapon *, int))weapon->dtr_idClass)(a1: weapon, a2: 1);
    this->weapon = nullptr;
  }
  idTrigger::~idTrigger(this);
}


// ========================================================================
// __unwind$492662_0
// EA  : 0x82CEDAC8
// RVA : 0x00CEDAC8
// PDB : w:\tech5\tungsten\game\entities\trigger.cpp
// ========================================================================

void _unwind_492662_0()
{
  int v0; // r12

  idTrigger::~idTrigger(this: *(idTrigger **)(v0 - 112 + 132));
}


// ========================================================================
// ?Event_Touch@idTrigger_DummyFire@@QAA?AVeventVoid@@PAVidEntity@@H@Z
// EA  : 0x82CEDAF0
// RVA : 0x00CEDAF0
// PDB : w:\tech5\tungsten\game\entities\trigger.cpp
// ========================================================================

idTrigger_DummyFire *__fastcall idTrigger_DummyFire::Event_Touch(
        idTrigger_DummyFire *this,
        idEntity *result,
        idEntity *other,
        int clipModelId)
{
  idTrigger_DummyFire *v6; // r3

  idEntity::BecomeActive(this: result, flags: 1);
  v6 = this;
  if ( HIBYTE(result[1].targets.granularity) != 0 )
    LODWORD(result[1].renderModelInfo.scale.x) = result[1].targets.size;
  return v6;
}


// ========================================================================
// ?Spawn@idTrigger_DummyFire@@QAAXXZ
// EA  : 0x82CEDB48
// RVA : 0x00CEDB48
// PDB : w:\tech5\tungsten\game\entities\trigger.cpp
// ========================================================================

void __fastcall idTrigger_DummyFire::Spawn(idTrigger_DummyFire *this)
{
  const idDeclWeapon *weaponDecl; // r3
  int ammoIndex; // r11
  const idDeclAmmo *validAmmoDecl; // r10
  idWeapon *v5; // r3
  idWeapon *v6; // r30
  idWeapon *v7; // r3

  weaponDecl = this->weaponDecl;
  if ( weaponDecl != nullptr )
  {
    ammoIndex = this->ammoIndex;
    if ( ammoIndex < 0 || ammoIndex >= weaponDecl->validAmmoClips.num )
    {
      idLib::Warning(
        fmt: "idTrigger_DummyFire %s has invalid ammoIndex (%d) for weaponDecl %s",
        this->name.data,
        this->ammoIndex,
        weaponDecl->name.str);
    }
    else
    {
      validAmmoDecl = weaponDecl->validAmmoClips.list[ammoIndex].validAmmoDecl;
      if ( validAmmoDecl != nullptr )
      {
        if ( validAmmoDecl->projectileDecl != nullptr )
        {
          v5 = (idWeapon *)idInventoryItem::Create(decl: weaponDecl);
          v6 = v5;
          if ( v5 != nullptr )
          {
            v7 = idWeapon::CastTo(c: v5);
            this->weapon = v7;
            if ( v7 != nullptr )
            {
              this->currentShotsLeft = this->numShots;
              return;
            }
            ((void (__fastcall *)(idWeapon *, int))v6->dtr_idClass)(a1: v6, a2: 1);
          }
          idLib::Warning(
            fmt: "idTrigger_DummyFire %s is using weaponDecl %s which isn't a valid idWeapon derivative",
            this->name.data,
            this->weaponDecl->name.str);
        }
        else
        {
          idLib::Warning(
            fmt: "idTrigger_DummyFire %s using weaponDecl %s has ammoIndex %d with NULL projectileDecl",
            this->name.data,
            weaponDecl->name.str,
            this->ammoIndex);
        }
      }
      else
      {
        idLib::Warning(
          fmt: "idTrigger_DummyFire %s using weaponDecl %s has NULL ammoIndex %d",
          this->name.data,
          weaponDecl->name.str,
          this->ammoIndex);
      }
    }
  }
  else
  {
    idLib::Warning(fmt: "idTrigger_DummyFire %s does not have a valid weaponDecl set", this->name.data);
  }
  idEventReceiver::PostEventMS(this, ev: &EV_Remove, time: 0);
}


// ========================================================================
// ?Spawn@idTrigger_EventListener@@QAAXXZ
// EA  : 0x82CEDC90
// RVA : 0x00CEDC90
// PDB : w:\tech5\tungsten\game\entities\trigger.cpp
// ========================================================================

void __fastcall idTrigger_EventListener::Spawn(idTrigger_EventListener *this)
{
  if ( this->onShooting )
    this->eventResponseFlags |= 2u;
  if ( this->eventResponseFlags != 0 )
    idAIEventManager::AddReceiver(this: &gameLocal->aiEventManager, receiver: this);
}


// ========================================================================
// ?CanActivate@idTrigger_EventListener@@UAA_NPAVidEntity@@@Z
// EA  : 0x82CEDCD0
// RVA : 0x00CEDCD0
// PDB : w:\tech5\tungsten\game\entities\trigger.cpp
// ========================================================================

int __fastcall idTrigger_EventListener::CanActivate(idTrigger_EventListener *this, idEntity *activator)
{
  idPlayer *PlayerFromEntity; // r3
  idPlayer *v5; // r31
  idPresentable *presentable; // r3
  idPresentable *v7; // r3
  int v8; // r3
  int v9; // r9
  int result; // r3

  if ( idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) < this->nextTriggerTime
    || !this->onSprinting )
  {
    return 0;
  }
  PlayerFromEntity = idGameLocal::GetPlayerFromEntity(this: gameLocal, activator);
  v5 = PlayerFromEntity;
  if ( PlayerFromEntity == nullptr )
  {
    idLib::Warning(fmt: "Only Players can trigger onSprinting on idTrigger_EventListener: %s", this->name.data);
    return 0;
  }
  presentable = PlayerFromEntity->presentable;
  if ( presentable == nullptr || presentable->GetPlayerInterface_2(this: presentable) == nullptr )
    return 0;
  v7 = v5->presentable;
  v8 = v7 != nullptr ? (int)v7->GetPlayerInterface_2(this: v7) : 0;
  v9 = *(unsigned __int8 *)(v8 + 47121);
  result = 1;
  if ( v9 == 0 )
    return 0;
  return result;
}


// ========================================================================
// ?RespondsToAIEvent@idTrigger_EventListener@@UBA_NPBVidAIEvent@@@Z
// EA  : 0x82CEDDE0
// RVA : 0x00CEDDE0
// PDB : w:\tech5\tungsten\game\entities\trigger.cpp
// ========================================================================

int __fastcall idTrigger_EventListener::RespondsToAIEvent(idTrigger_EventListener *this, const idAIEvent *event)
{
  int result; // r3

  if ( event == nullptr )
    return 0;
  if ( (idAIEvent::GetEventClass(this: event) & this->eventResponseFlags) == 0 )
    return 0;
  result = 1;
  if ( (*(_BYTE *)&this->flags & 8) == 0 )
    return 0;
  return result;
}


// ========================================================================
// ?Event_Touch@idTrigger@@IAA?AVeventVoid@@PAVidEntity@@H@Z
// EA  : 0x82CEDE40
// RVA : 0x00CEDE40
// PDB : w:\tech5\tungsten\game\entities\trigger.cpp
// ========================================================================

idTrigger *__fastcall idTrigger::Event_Touch(idTrigger *this, idEntity *result, idVehicle *other, int clipModelId)
{
  int z_low; // r10
  idEntityPtr<idEntity> *p_z; // r30
  char v9; // r28
  idEntity *v10; // r3
  idEntity *v11; // r3
  idEntity *v12; // r3
  idVehicle *v13; // r31
  idEntity *v14; // r30
  idPlayer *v15; // r31
  idThrownCamera *Control; // r3
  bool v17; // cr58

  if ( BYTE1(result[1].listeningToList) != 0 )
    return this;
  z_low = LODWORD(result[1].spawnOrientation.mat[1].z);
  p_z = (idEntityPtr<idEntity> *)&result[1].spawnOrientation.mat[1].z;
  v9 = 0;
  if ( gameLocal->spawnIds.ptr[z_low & 0x1FFF] == z_low >> 13 )
  {
    v10 = gameLocal->entities.ptr[z_low & 0x1FFF];
    if ( v10 != nullptr && idEntity::CastTo(c: v10) != nullptr )
    {
      if ( gameLocal->spawnIds.ptr[p_z->spawnId.value & 0x1FFF] == p_z->spawnId.value >> 13
        && (v11 = gameLocal->entities.ptr[p_z->spawnId.value & 0x1FFF]) != nullptr )
      {
        v12 = idEntity::CastTo(c: v11);
      }
      else
      {
        v12 = nullptr;
      }
      if ( v12 != other )
      {
        v13 = idVehicle::CastTo(c: other);
        if ( v13 == nullptr )
          goto LABEL_31;
        v14 = idEntityPtr<idEntity const>::operator->(this: p_z);
        if ( v14 != idVehicle::GetDriver(this: v13) )
          goto LABEL_31;
      }
      goto LABEL_30;
    }
  }
  if ( HIBYTE(result[1].spawnOrientation.mat[2].x) == 0 || (unsigned __int8)idPlayer::IsTypeOf(c: other) == 0 )
  {
    if ( (LOBYTE(result[1].spawnOrientation.mat[2].x) != 0 || BYTE1(result[1].spawnOrientation.mat[2].x) != 0)
      && (unsigned __int8)idVehicle::IsTypeOf(c: other) != 0 )
    {
      if ( LOBYTE(result[1].spawnOrientation.mat[2].x) != 0 )
      {
LABEL_30:
        v9 = 1;
        goto LABEL_31;
      }
      v17 = idVehicle::PlayerIsOccupant(this: other) == nullptr;
    }
    else
    {
      if ( BYTE2(result[1].spawnOrientation.mat[2].x) != 0
        && (unsigned __int8)idVehicleOccupant::IsTypeOf(c: other) != 0 )
      {
        if ( LODWORD(other->detachableItems.staticList[28].axis.mat[2].y) == 0 )
          goto LABEL_31;
        other = (idVehicle *)LODWORD(other->detachableItems.staticList[28].axis.mat[2].y);
        goto LABEL_30;
      }
      if ( HIBYTE(result[1].spawnOrientation.mat[2].y) == 0 )
        goto LABEL_31;
      v17 = (unsigned __int8)idAI2::IsTypeOf(c: other) == 0;
    }
    if ( v17 )
      goto LABEL_31;
    goto LABEL_30;
  }
  v15 = idPlayer::CastTo(c: (idPlayer *)other);
  if ( idPlayer::GetControl(this: v15) == nullptr )
    goto LABEL_30;
  Control = (idThrownCamera *)idPlayer::GetControl(this: v15);
  if ( idThrownCamera::CastTo(c: Control) == nullptr )
    goto LABEL_30;
LABEL_31:
  if ( v9 != 0 )
    idEntity::Activate(this: result, activator: other);
  return this;
}


// ========================================================================
// ?CanDamage@idTrigger_DamageType@@IBA_NPAVidEntity@@0PBVidDeclDamage@@@Z
// EA  : 0x82CEE048
// RVA : 0x00CEE048
// PDB : w:\tech5\tungsten\game\entities\trigger.cpp
// ========================================================================

BOOL __fastcall idTrigger_DamageType::CanDamage(
        idTrigger_DamageType *this,
        idEntity *inflictor,
        idVehicle *attacker,
        const idDeclDamage *damageDecl)
{
  idPhysics *Physics; // r3
  idEntityPtr<idEntity> *p_entityCanActivate; // r30
  idVehicle *v9; // r31
  idEntity *v10; // r30
  BOOL result; // r3
  bool v12; // zf

  Physics = idEntity::GetPhysics(this);
  if ( !Physics->GetClipModel(this: Physics, a2: 0)->enabled
    || damageDecl != nullptr && (this->damageTypes & damageDecl->damageTypes) == 0 )
  {
    return false;
  }
  if ( this->allCanActivate )
    return true;
  p_entityCanActivate = &this->entityCanActivate;
  if ( idEntityPtr<idEntity const>::operator->(this: &this->entityCanActivate) != nullptr )
  {
    if ( idEntityPtr<idEntity const>::operator->(this: &this->entityCanActivate) == attacker )
      return true;
    v9 = idVehicle::CastTo(c: attacker);
    if ( v9 != nullptr )
    {
      v10 = idEntityPtr<idEntity const>::operator->(this: p_entityCanActivate);
      if ( v10 == idVehicle::GetDriver(this: v9) )
        return true;
    }
    return false;
  }
  if ( this->playerCanActivate && (unsigned __int8)idPlayer::IsTypeOf(c: attacker) != 0 )
    return true;
  if ( (this->anyVehicleCanActivate || this->playerVehicleCanActivate)
    && (unsigned __int8)idVehicle::IsTypeOf(c: attacker) != 0 )
  {
    return this->anyVehicleCanActivate || idVehicle::PlayerIsOccupant(this: attacker) != nullptr;
  }
  if ( this->aiCanActivate && (unsigned __int8)idAI2::IsTypeOf(c: attacker) != 0 )
    return true;
  if ( this->vehicleOccupantCanActivate && (unsigned __int8)idVehicleOccupant::IsTypeOf(c: attacker) != 0 )
    return LODWORD(attacker->detachableItems.staticList[28].axis.mat[2].y) != 0;
  if ( !this->turretCanActivate )
    return false;
  v12 = (unsigned __int8)idTurret::IsTypeOf(c: attacker) != 0;
  result = true;
  if ( !v12 )
    return false;
  return result;
}


// ========================================================================
// ?Damage@idTrigger_DamageType@@UAAMPAVidEntity@@0PBVidDeclDamage@@MABVidVec3@@PAUtrace_t@@@Z
// EA  : 0x82CEE208
// RVA : 0x00CEE208
// PDB : w:\tech5\tungsten\game\entities\trigger.cpp
// ========================================================================

float __fastcall idTrigger_DamageType::Damage(
        idTrigger_DamageType *this,
        idEntity *inflictor,
        idVehicle *attacker,
        const idDeclDamage *damageDecl,
        double damageScale,
        const idVec3 *dir,
        trace_t *trace)
{
  double v11; // fp1
  double v12; // fp31
  double v13; // fp0
  idEventArg *v14; // r3
  idEventArg v16; // [sp+50h] [-40h] BYREF

  if ( idTrigger_DamageType::CanDamage(this, inflictor, attacker, damageDecl) )
  {
    v12 = (float)(idDeclDamage::DamageAmount(this: damageDecl) * (float)damageScale);
    v13 = (float)(this->health - (float)v12);
    if ( v13 >= 0.0 )
    {
      if ( v13 > 1.0e30 )
        v13 = 1.0e30;
    }
    else
    {
      v13 = 0.0;
    }
    this->health = v13;
    if ( v13 <= 0.0 )
    {
      v14 = idEventArg::idEventArg(this: &v16, data: attacker);
      idEventReceiver::PostEventMS(
        this,
        ev: &EV_Activate,
        time: *(_DWORD *)&v14->type,
        arg1: (const idEventArg *)LODWORD(v14->value.v[1]));
    }
    v11 = v12;
  }
  else
  {
    v11 = 0.0;
  }
  return *((float *)&v11 + 1);
}


// ========================================================================
// ?Event_Touch@idTrigger_Multiplayer@@QAA?AVeventVoid@@PAVidEntity@@H@Z
// EA  : 0x82CEE2E0
// RVA : 0x00CEE2E0
// PDB : w:\tech5\tungsten\game\entities\trigger.cpp
// ========================================================================

idTrigger_Multiplayer *__fastcall idTrigger_Multiplayer::Event_Touch(
        idTrigger_Multiplayer *this,
        idEntity *result,
        idVehicle *other,
        int clipModelId)
{
  idTrigger::Event_Touch(this, result, other, clipModelId);
  return this;
}


// ========================================================================
// ?CanActivate@idTrigger_Multiplayer@@MAA_NPAVidEntity@@@Z
// EA  : 0x82CEE310
// RVA : 0x00CEE310
// PDB : w:\tech5\tungsten\game\entities\trigger.cpp
// ========================================================================

int __fastcall idTrigger_Multiplayer::CanActivate(idTrigger_Multiplayer *this, idEntity *activator)
{
  int v4; // r24
  int i; // r25
  idPlayer *Player; // r3
  idPlayer *v7; // r31
  char v8; // r27
  idPresentable *presentable; // r3
  int v10; // r3
  int v11; // r3
  _DWORD *v12; // r30
  int v13; // r29
  int v14; // r31
  int v15; // r9
  idEntity *v16; // r3
  idTrigger_Multiplayer *v17; // r3

  if ( idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) < this->nextTriggerTime )
    return 0;
  v4 = 1;
  if ( this->requireAllPlayers || this->ignoreIncapacitatedPlayers )
  {
    v4 = 0;
    for ( i = 0; i < 6; ++i )
    {
      Player = idGameLocal::GetPlayer(this: gameLocal, i);
      v7 = Player;
      if ( Player != nullptr )
      {
        v8 = 0;
        if ( this->ignoreIncapacitatedPlayers
          && ((presentable = Player->presentable) == nullptr
            ? (v10 = 0)
            : (v10 = (int)presentable->GetPlayerInterface_2(this: presentable)),
              (*(_BYTE *)(v10 + 47032) & 4) != 0) )
        {
          v8 = 0;
        }
        else
        {
          v11 = (int)v7->GetTriggerTouchList_2(this: v7);
          v12 = (_DWORD *)v11;
          if ( v11 != 0 )
          {
            v13 = 0;
            if ( *(int *)(v11 + 4) > 0 )
            {
              v14 = 0;
              while ( 1 )
              {
                v15 = *(_DWORD *)(*v12 + v14);
                if ( gameLocal->spawnIds.ptr[v15 & 0x1FFF] == v15 >> 13
                  && (v16 = gameLocal->entities.ptr[v15 & 0x1FFF]) != nullptr )
                {
                  v17 = (idTrigger_Multiplayer *)idEntity::CastTo(c: v16);
                }
                else
                {
                  v17 = nullptr;
                }
                if ( v17 == this )
                  break;
                ++v13;
                v14 += 4;
                if ( v13 >= v12[1] )
                  goto LABEL_24;
              }
              v8 = 1;
            }
          }
        }
LABEL_24:
        if ( this->requireAllPlayers && v8 == 0 )
          return 0;
        if ( v8 != 0 )
          v4 = 1;
      }
    }
  }
  return v4;
}


// ========================================================================
// ?Event_Touch@idTrigger_AIGroupsExit@@QAA?AVeventVoid@@PAVidEntity@@H@Z
// EA  : 0x82CEE540
// RVA : 0x00CEE540
// PDB : w:\tech5\tungsten\game\entities\trigger.cpp
// ========================================================================

idTrigger_AIGroupsExit *__fastcall idTrigger_AIGroupsExit::Event_Touch(
        idTrigger_AIGroupsExit *this,
        idEntity *result,
        idAI2 *other,
        int clipModelId)
{
  idAI2 *v8; // r3
  idEncounterGroup *EncounterGroup; // r26
  int maxVisibleRange_low; // r27
  int v11; // r29
  idEncounterGroupManager *p_encounterGroupManager; // r28
  int i; // r31
  char v15; // [sp+50h] [-60h] BYREF

  v8 = idAI2::CastTo(c: other);
  if ( v8 != nullptr )
  {
    EncounterGroup = idAI2::GetEncounterGroup(this: v8);
    if ( EncounterGroup != nullptr )
    {
      maxVisibleRange_low = LODWORD(result[1].renderModelInfo.maxVisibleRange);
      v11 = 0;
      p_encounterGroupManager = &gameLocal->encounterGroupManager;
      if ( maxVisibleRange_low > 0 )
      {
        for ( i = 0;
              idEncounterGroupManager::GroupForHandle(
                this: p_encounterGroupManager,
                handle: (const idHandle<short,enum invalidEncounterGroup_t,-1> *)(result[1].targets.size + i)) != EncounterGroup;
              i += 2 )
        {
          if ( ++v11 >= maxVisibleRange_low )
            return this;
        }
        idTrigger::Event_Touch(this: (idTrigger *)&v15, result, (idVehicle *)other, clipModelId);
      }
    }
  }
  return this;
}


// ========================================================================
// ?CanActivate@idTrigger_OpenDoor@@UAA_NPAVidEntity@@@Z
// EA  : 0x82CEE5F8
// RVA : 0x00CEE5F8
// PDB : w:\tech5\tungsten\game\entities\trigger.cpp
// ========================================================================

int __fastcall idTrigger_OpenDoor::CanActivate(idTrigger_OpenDoor *this, idVehicle *other)
{
  int value; // r10
  idEntityPtr<idEntity> *p_entityCanActivate; // r29
  int v7; // r27
  idEntity *v8; // r3
  idEntity *v9; // r3
  idEntity *v10; // r3
  idVehicle *v11; // r31
  idEntity *v12; // r30
  idPlayer *v13; // r31
  idThrownCamera *Control; // r3
  bool v15; // cr58

  if ( idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) < this->nextTriggerTime )
    return 0;
  value = this->entityCanActivate.spawnId.value;
  p_entityCanActivate = &this->entityCanActivate;
  v7 = 0;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
  {
    v8 = gameLocal->entities.ptr[value & 0x1FFF];
    if ( v8 != nullptr && idEntity::CastTo(c: v8) != nullptr )
    {
      if ( gameLocal->spawnIds.ptr[p_entityCanActivate->spawnId.value & 0x1FFF] == p_entityCanActivate->spawnId.value >> 13
        && (v9 = gameLocal->entities.ptr[p_entityCanActivate->spawnId.value & 0x1FFF]) != nullptr )
      {
        v10 = idEntity::CastTo(c: v9);
      }
      else
      {
        v10 = nullptr;
      }
      if ( v10 != other )
      {
        v11 = idVehicle::CastTo(c: other);
        if ( v11 != nullptr )
        {
          v12 = idEntityPtr<idEntity const>::operator->(this: p_entityCanActivate);
          if ( v12 == idVehicle::GetDriver(this: v11) )
            return 1;
        }
        return v7;
      }
      return 1;
    }
  }
  if ( !this->playerCanActivate || (unsigned __int8)idPlayer::IsTypeOf(c: other) == 0 )
  {
    if ( (this->anyVehicleCanActivate || this->playerVehicleCanActivate)
      && (unsigned __int8)idVehicle::IsTypeOf(c: other) != 0 )
    {
      if ( this->anyVehicleCanActivate )
        return 1;
      v15 = idVehicle::PlayerIsOccupant(this: other) == nullptr;
    }
    else if ( this->vehicleOccupantCanActivate && (unsigned __int8)idVehicleOccupant::IsTypeOf(c: other) != 0 )
    {
      v15 = LODWORD(other->detachableItems.staticList[28].axis.mat[2].y) == 0;
    }
    else
    {
      if ( !this->aiCanActivate )
        return v7;
      v15 = (unsigned __int8)idAI2::IsTypeOf(c: other) == 0;
    }
    if ( v15 )
      return v7;
    return 1;
  }
  v13 = idPlayer::CastTo(c: (idPlayer *)other);
  if ( idPlayer::GetControl(this: v13) == nullptr )
    return 1;
  Control = (idThrownCamera *)idPlayer::GetControl(this: v13);
  if ( idThrownCamera::CastTo(c: Control) == nullptr )
    return 1;
  return v7;
}


// ========================================================================
// ??0idTrigger@@QAA@XZ
// EA  : 0x82CEE878
// RVA : 0x00CEE878
// PDB : w:\tech5\tungsten\game\entities\trigger.cpp
// ========================================================================

idTrigger *__fastcall idTrigger::idTrigger(idTrigger *this)
{
  char v2; // r11

  idEntity::idEntity(this);
  this->__vftable = (idTrigger_vtbl *)&idTrigger::`vftable';
  this->call.data = this->call.baseBuffer;
  this->call.len = 0;
  this->call.allocedAndFlag = 20;
  this->call.baseBuffer[0] = 0;
  this->userData.len = 0;
  this->userData.allocedAndFlag = 20;
  this->userData.data = this->userData.baseBuffer;
  this->userData.baseBuffer[0] = 0;
  this->entityCanActivate.spawnId.value = 0x1FFF;
  this->wait = 0.5;
  this->triggerFirst = false;
  this->delay = 0.0;
  this->nextTriggerTime = 0;
  this->extraContents = 0;
  this->playerVehicleCanActivate = false;
  this->vehicleOccupantCanActivate = false;
  this->anyVehicleCanActivate = false;
  this->aiCanActivate = false;
  this->turretCanActivate = false;
  this->triggerOnce = true;
  this->playerCanActivate = true;
  this->entityCanActivate.spawnId.value = 0x1FFF;
  v2 = *(_BYTE *)&this->flags | 4;
  this->clipModelInfo.type = CLIPMODEL_RENDERMODEL;
  *(_BYTE *)&this->flags = v2;
  return this;
}


// ========================================================================
// ??0idTrigger@@QAA@H@Z
// EA  : 0x82CEE950
// RVA : 0x00CEE950
// PDB : w:\tech5\tungsten\game\entities\trigger.cpp
// ========================================================================

idTrigger *__fastcall idTrigger::idTrigger(idTrigger *this, int extraContents_)
{
  char v4; // r11

  idEntity::idEntity(this);
  this->__vftable = (idTrigger_vtbl *)&idTrigger::`vftable';
  this->call.data = this->call.baseBuffer;
  this->call.len = 0;
  this->call.allocedAndFlag = 20;
  this->call.baseBuffer[0] = 0;
  this->userData.len = 0;
  this->userData.allocedAndFlag = 20;
  this->userData.data = this->userData.baseBuffer;
  this->userData.baseBuffer[0] = 0;
  this->entityCanActivate.spawnId.value = 0x1FFF;
  this->wait = 0.5;
  this->triggerFirst = false;
  this->delay = 0.0;
  this->nextTriggerTime = 0;
  this->playerVehicleCanActivate = false;
  this->vehicleOccupantCanActivate = false;
  this->anyVehicleCanActivate = false;
  this->aiCanActivate = false;
  this->turretCanActivate = false;
  this->triggerOnce = true;
  this->extraContents = extraContents_;
  this->playerCanActivate = true;
  this->entityCanActivate.spawnId.value = 0x1FFF;
  v4 = *(_BYTE *)&this->flags | 4;
  this->clipModelInfo.type = CLIPMODEL_RENDERMODEL;
  *(_BYTE *)&this->flags = v4;
  return this;
}


// ========================================================================
// ?DrawDebugInfo@idTrigger@@SAXXZ
// EA  : 0x82CEEA30
// RVA : 0x00CEEA30
// PDB : w:\tech5\tungsten\game\entities\trigger.cpp
// ========================================================================

static void __fastcall idTrigger::DrawDebugInfo()
{
  idPlayer *DebugPlayer; // r3
  idPhysics *Physics; // r3
  float *v2; // r3
  double v3; // fp27
  double v4; // fp24
  double v5; // fp23
  double v6; // fp22
  double v7; // fp21
  double v8; // fp20
  idPlayer *v9; // r3
  idPhysics *v10; // r3
  float *v11; // r3
  double v12; // fp10
  double v13; // fp9
  double v14; // fp8
  double v15; // fp19
  double v16; // fp18
  double v17; // fp17
  idLinkList<idEntity> *next; // r11
  double v19; // fp16
  double v20; // fp15
  double z; // fp14
  idTrigger_Facing *owner; // r28
  idPhysics *v23; // r3
  idTrigger_Facing *v24; // r26
  idVolume_ShowGui_Leveltransition *v25; // r23
  idPhysics *v26; // r3
  float *v27; // r3
  char v28; // r29
  int v29; // r30
  int v30; // r31
  int value; // r9
  idEntity *v32; // r3
  idEntity *v33; // r3
  idPhysics *v34; // r3
  float *v35; // r3
  char v36; // r11
  int v37; // r10
  idInfo_Trigger_Facing_Target *v38; // r3
  int v39; // r9
  idInfo_Trigger_Facing_Target *v40; // r3
  idInfo_Trigger_Facing_Target *v41; // r3
  idPhysics *v42; // r3
  int v43; // r9
  idPhysics *v44; // r31
  idInfo_Trigger_Facing_Target *v45; // r3
  idInfo_Trigger_Facing_Target *v46; // r11
  double v47; // fp14
  const idBounds *v48; // r3
  int v49; // r10
  idInfo_Trigger_Facing_Target *v50; // r3
  int v51; // r9
  idInfo_Trigger_Facing_Target *v52; // r3
  idInfo_Trigger_Facing_Target *v53; // r3
  idPhysics *v54; // r3
  int v55; // r9
  idPhysics *v56; // r31
  idInfo_Trigger_Facing_Target *v57; // r3
  idInfo_Trigger_Facing_Target *v58; // r11
  double v59; // fp14
  const idBounds *v60; // r3
  idPhysics *v61; // r3
  idRenderWorld *renderWorld; // r31
  idRenderWorld_vtbl *v63; // r30
  int v64; // r3
  idPhysics *v65; // r3
  float *v66; // r3
  char v67; // r11
  idPhysics *v68; // r3
  float *v69; // r3
  double v70; // fp8
  double v71; // fp6
  idPhysics *v72; // r3
  float *v73; // r3
  const char *str; // r4
  double v75; // fp7
  double v76; // fp5
  const idDeclEntityDef *entityDef; // r11
  idTrigger *v78; // r3
  idTrigger *v79; // r31
  idPhysics *v80; // r3
  __int64 v81; // r10
  double v82; // fp6
  double v83; // fp5
  __int64 v84; // r6
  __int64 v85; // r8
  va *v86; // r3
  int v87; // r29
  int v88; // r30
  int v89; // r9
  idEntity *v90; // r3
  idEntity *v91; // r31
  idPhysics *v92; // r15
  idPhysics *v93; // r3
  float *v94; // r3
  double v95; // fp6
  idPhysics *v96; // r3
  double v97; // fp12
  idRenderWorld *v98; // r15
  const idVec3 *(__fastcall *GetOrigin)(idPhysics *, int); // ctr
  idRenderWorld_vtbl *v100; // r14
  int v101; // r3
  idPhysics *v102; // r3
  idRenderWorld *v103; // r15
  idRenderWorld_vtbl *v104; // r14
  int v105; // r3
  idPhysics *v106; // r3
  float *v107; // r3
  char v108; // r11
  idPhysics *v109; // r3
  float *v110; // r3
  double v111; // fp8
  double v112; // fp6
  int v113; // r10
  idInfo_Trigger_Facing_Target *v114; // r3
  int v115; // r9
  idInfo_Trigger_Facing_Target *v116; // r3
  idInfo_Trigger_Facing_Target *v117; // r3
  idPhysics *v118; // r3
  int v119; // r9
  idPhysics *v120; // r31
  idInfo_Trigger_Facing_Target *v121; // r3
  idInfo_Trigger_Facing_Target *v122; // r11
  double v123; // fp14
  float *v124; // r3
  int v125; // r8
  idInfo_Trigger_Facing_Target *v126; // r3
  idInfo_Trigger_Facing_Target *v127; // r3
  idColor *v128; // r4
  int v129; // r9
  idInfo_Trigger_Facing_Target *v130; // r3
  idInfo_Trigger_Facing_Target *v131; // r3
  idPhysics *v132; // r31
  idPhysics *v133; // r3
  float *v134; // r3
  double v135; // fp6
  idPhysics *v136; // r3
  double v137; // fp9
  idRenderWorld *v138; // r31
  const idVec3 *(__fastcall *v139)(idPhysics *, int); // r8
  idRenderWorld_vtbl *v140; // r30
  int v141; // r3
  int v142; // r10
  idInfo_Trigger_Facing_Target *v143; // r3
  int v144; // r9
  idInfo_Trigger_Facing_Target *v145; // r3
  idInfo_Trigger_Facing_Target *v146; // r3
  idPhysics *v147; // r3
  int v148; // r9
  idPhysics *v149; // r31
  idInfo_Trigger_Facing_Target *v150; // r3
  idInfo_Trigger_Facing_Target *v151; // r11
  double v152; // fp14
  float *v153; // r3
  int v154; // r8
  idInfo_Trigger_Facing_Target *v155; // r3
  idInfo_Trigger_Facing_Target *v156; // r3
  idColor *v157; // r4
  int v158; // r9
  idInfo_Trigger_Facing_Target *v159; // r3
  idInfo_Trigger_Facing_Target *v160; // r3
  idPhysics *v161; // r31
  idPhysics *v162; // r3
  float *v163; // r3
  double v164; // fp9
  idPhysics *v165; // r3
  double v166; // fp6
  idRenderWorld *v167; // r31
  const idVec3 *(__fastcall *v168)(idPhysics *, int); // ctr
  idRenderWorld_vtbl *v169; // r30
  int v170; // r3
  idLinkList<idEntity> *v171; // r11
  int v172; // [sp+8h] [-1268h]
  int v173; // [sp+Ch] [-1264h]
  int v174; // [sp+10h] [-1260h]
  int v175; // [sp+14h] [-125Ch]
  int v176; // [sp+18h] [-1258h]
  int v177; // [sp+1Ch] [-1254h]
  float v178[4]; // [sp+70h] [-1200h] BYREF
  idBounds v179; // [sp+80h] [-11F0h] BYREF
  float v180[4]; // [sp+A0h] [-11D0h] BYREF
  float v181[4]; // [sp+B0h] [-11C0h] BYREF
  float v182[4]; // [sp+C0h] [-11B0h] BYREF
  float v183[4]; // [sp+D0h] [-11A0h] BYREF
  float v184[4]; // [sp+E0h] [-1190h] BYREF
  float v185[4]; // [sp+F0h] [-1180h] BYREF
  float v186[4]; // [sp+100h] [-1170h] BYREF
  float v187[4]; // [sp+110h] [-1160h] BYREF
  float v188[8]; // [sp+120h] [-1150h] BYREF
  va v189; // [sp+140h] [-1130h] BYREF

  DebugPlayer = idGameLocal::GetDebugPlayer(this: gameLocal);
  Physics = idEntity::GetPhysics(this: DebugPlayer);
  v2 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
  v3 = (float)(*v2 - (float)128.0);
  v4 = (float)(v2[1] - (float)128.0);
  v5 = (float)(v2[2] - (float)128.0);
  v6 = (float)(*v2 + (float)128.0);
  v7 = (float)(v2[1] + (float)128.0);
  v8 = (float)(v2[2] + (float)128.0);
  v9 = idGameLocal::GetDebugPlayer(this: gameLocal);
  v10 = idEntity::GetPhysics(this: v9);
  v11 = (float *)v10->GetOrigin(this: v10, a2: 0);
  v12 = *v11;
  v13 = v11[1];
  v14 = v11[2];
  v15 = (float)(*v11 - (float)512.0);
  v16 = (float)(v11[1] - (float)512.0);
  v179.b[0].x = *v11 - (float)512.0;
  v179.b[0].y = v16;
  v17 = (float)((float)v14 - (float)512.0);
  v179.b[0].z = (float)v14 - (float)512.0;
  next = gameLocal->spawnedEntities.next;
  v19 = (float)((float)v12 + (float)512.0);
  v20 = (float)((float)v13 + (float)512.0);
  v179.b[1].x = (float)v12 + (float)512.0;
  z = (float)((float)v14 + (float)512.0);
  v179.b[1].y = (float)v13 + (float)512.0;
  v179.b[1].z = (float)v14 + (float)512.0;
  if ( next != nullptr && next != gameLocal->spawnedEntities.head )
  {
    owner = (idTrigger_Facing *)next->owner;
    if ( owner != nullptr )
    {
      while ( 1 )
      {
        v23 = idEntity::GetPhysics(this: owner);
        if ( (v23->GetContents(this: v23, a2: -1) & 0x4000) != 0 )
        {
          v24 = idTrigger_Facing::CastTo(c: owner);
          v25 = idVolume_ShowGui_Leveltransition::CastTo(c: (idVolume_ShowGui_Leveltransition *)owner);
          v26 = idEntity::GetPhysics(this: owner);
          v27 = (float *)v26->GetAbsBounds(this: v26, a2: -1);
          if ( v27[3] < v15 || v27[4] < v16 || v27[5] < v17 || *v27 > v19 || v27[1] > v20 || (v28 = 1, v27[2] > z) )
            v28 = 0;
          if ( v28 == 0 )
          {
            v29 = 0;
            if ( owner->targets.num > 0 )
            {
              v30 = 0;
              while ( 1 )
              {
                value = owner->targets.list[v30].spawnId.value;
                if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
                  && (v32 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
                {
                  v33 = idEntity::CastTo(c: v32);
                }
                else
                {
                  v33 = nullptr;
                }
                if ( v33 != nullptr )
                {
                  v34 = idEntity::GetPhysics(this: v33);
                  v35 = (float *)v34->GetAbsBounds(this: v34, a2: -1);
                  if ( v35[3] < v15
                    || v35[4] < v16
                    || v35[5] < v17
                    || *v35 > v19
                    || v35[1] > v20
                    || (v36 = 1, v35[2] > z) )
                  {
                    v36 = 0;
                  }
                  if ( v36 != 0 )
                    break;
                }
                ++v29;
                ++v30;
                if ( v29 >= owner->targets.num )
                  goto LABEL_33;
              }
              v28 = 1;
            }
          }
LABEL_33:
          if ( v28 == 0 && v24 != nullptr )
          {
            v37 = v24->facingTarget.spawnId.value;
            if ( gameLocal->spawnIds.ptr[v37 & 0x1FFF] == v37 >> 13 )
            {
              v38 = (idInfo_Trigger_Facing_Target *)gameLocal->entities.ptr[v37 & 0x1FFF];
              if ( v38 != nullptr && idInfo_Trigger_Facing_Target::CastTo(c: v38) != nullptr )
              {
                v39 = v24->facingTarget.spawnId.value;
                if ( gameLocal->spawnIds.ptr[v39 & 0x1FFF] == v39 >> 13
                  && (v40 = (idInfo_Trigger_Facing_Target *)gameLocal->entities.ptr[v39 & 0x1FFF]) != nullptr )
                {
                  v41 = idInfo_Trigger_Facing_Target::CastTo(c: v40);
                }
                else
                {
                  v41 = nullptr;
                }
                v42 = idEntity::GetPhysics(this: v41);
                v43 = v24->facingTarget.spawnId.value;
                v44 = v42;
                if ( gameLocal->spawnIds.ptr[v43 & 0x1FFF] == v43 >> 13
                  && (v45 = (idInfo_Trigger_Facing_Target *)gameLocal->entities.ptr[v43 & 0x1FFF]) != nullptr )
                {
                  v46 = idInfo_Trigger_Facing_Target::CastTo(c: v45);
                }
                else
                {
                  v46 = nullptr;
                }
                v47 = v46->radius.value;
                v48 = v44->GetAbsBounds(this: v44, a2: -1);
                if ( (unsigned __int8)idBounds::IntersectsBounds(this: &v179, a: v48, epsilon: v47) != 0 )
                  v28 = 1;
              }
            }
          }
          if ( v28 == 0 && v25 != nullptr )
          {
            v49 = v25->facingTarget.spawnId.value;
            if ( gameLocal->spawnIds.ptr[v49 & 0x1FFF] == v49 >> 13 )
            {
              v50 = (idInfo_Trigger_Facing_Target *)gameLocal->entities.ptr[v49 & 0x1FFF];
              if ( v50 != nullptr && idInfo_Trigger_Facing_Target::CastTo(c: v50) != nullptr )
              {
                v51 = v25->facingTarget.spawnId.value;
                if ( gameLocal->spawnIds.ptr[v51 & 0x1FFF] == v51 >> 13
                  && (v52 = (idInfo_Trigger_Facing_Target *)gameLocal->entities.ptr[v51 & 0x1FFF]) != nullptr )
                {
                  v53 = idInfo_Trigger_Facing_Target::CastTo(c: v52);
                }
                else
                {
                  v53 = nullptr;
                }
                v54 = idEntity::GetPhysics(this: v53);
                v55 = v25->facingTarget.spawnId.value;
                v56 = v54;
                if ( gameLocal->spawnIds.ptr[v55 & 0x1FFF] == v55 >> 13
                  && (v57 = (idInfo_Trigger_Facing_Target *)gameLocal->entities.ptr[v55 & 0x1FFF]) != nullptr )
                {
                  v58 = idInfo_Trigger_Facing_Target::CastTo(c: v57);
                }
                else
                {
                  v58 = nullptr;
                }
                v59 = v58->radius.value;
                v60 = v56->GetAbsBounds(this: v56, a2: -1);
                if ( (unsigned __int8)idBounds::IntersectsBounds(this: &v179, a: v60, epsilon: v59) != 0 )
                  v28 = 1;
              }
            }
          }
          if ( v28 != 0 )
          {
            v61 = idEntity::GetPhysics(this: owner);
            renderWorld = clientGame->renderWorld;
            v63 = renderWorld->__vftable;
            v64 = (int)v61->GetAbsBounds(this: v61, a2: -1);
            v63->DebugBounds(
              this: renderWorld,
              a2: (const idVec4 *)&idColor::colorOrange,
              a3: (const idBounds *)v64,
              a4: &vec3_origin,
              a5: 0,
              a6: false);
            v65 = idEntity::GetPhysics(this: owner);
            v66 = (float *)v65->GetAbsBounds(this: v65, a2: -1);
            if ( v66[3] < v3 || v66[4] < v4 || v66[5] < v5 || *v66 > v6 || v66[1] > v7 || (v67 = 1, v66[2] > v8) )
              v67 = 0;
            if ( v67 != 0 )
            {
              v68 = idEntity::GetPhysics(this: owner);
              v69 = (float *)v68->GetAbsBounds(this: v68, a2: -1);
              v70 = (float)(v69[1] + v69[4]);
              v71 = (float)(v69[3] + *v69);
              v186[2] = (float)(v69[2] + v69[5]) * (float)0.5;
              v186[1] = (float)v70 * (float)0.5;
              v186[0] = (float)v71 * (float)0.5;
              ((void (__fastcall *)(idRenderWorld *, char *, float *, idRenderWorld_vtbl *, idColor *, int, _DWORD, _DWORD, double))clientGame->renderWorld->DebugText)(
                a1: clientGame->renderWorld,
                a2: owner->name.data,
                a3: v186,
                a4: clientGame->renderWorld->__vftable,
                a5: &idColor::colorWhite,
                a6: 1,
                a7: 0,
                a8: 0,
                a9: 0.1);
              v72 = idEntity::GetPhysics(this: owner);
              v73 = (float *)v72->GetAbsBounds(this: v72, a2: -1);
              str = "*unknown*";
              v75 = (float)((float)(v73[5] + v73[2]) * (float)0.5);
              v76 = (float)((float)(v73[4] + v73[1]) * (float)0.5);
              v182[0] = (float)(v73[3] + *v73) * (float)0.5;
              v182[1] = v76;
              v182[2] = (float)v75 + (float)5.0;
              entityDef = owner->entityDef;
              if ( entityDef != nullptr )
                str = entityDef->name.str;
              ((void (__fastcall *)(idRenderWorld *, const char *, float *, void (__fastcall *)(idRenderWorld *, const char *, const idVec3 *, float, const idVec4 *, const int, const int, const bool, const bool), idColor *, int, _DWORD, _DWORD, double))clientGame->renderWorld->DebugText)(
                a1: clientGame->renderWorld,
                a2: str,
                a3: v182,
                a4: clientGame->renderWorld->DebugText,
                a5: &idColor::colorWhite,
                a6: 1,
                a7: 0,
                a8: 0,
                a9: 0.1);
              v78 = idTrigger::CastTo(c: owner);
              v79 = v78;
              if ( v78 != nullptr && v78->call.len != 0 )
              {
                v80 = idEntity::GetPhysics(this: owner);
                HIDWORD(v81) = v80->GetAbsBounds(this: v80, a2: -1);
                v82 = (float)(*(float *)(HIDWORD(v81) + 16) + *(float *)(HIDWORD(v81) + 4));
                v83 = (float)((float)(*(float *)(HIDWORD(v81) + 20) + *(float *)(HIDWORD(v81) + 8)) * (float)0.5);
                v183[0] = (float)(*(float *)(HIDWORD(v81) + 12) + *(float *)HIDWORD(v81)) * (float)0.5;
                v183[1] = (float)v82 * (float)0.5;
                v183[2] = (float)v83 - (float)5.0;
                HIDWORD(v84) = v79->call.data;
                v86 = va::va(
                        this: &v189,
                        fmt: "call script '%s'",
                        a3: v84,
                        a4: v85,
                        a5: v81,
                        a6: v172,
                        a7: v173,
                        a8: v174,
                        a9: v175,
                        a10: v176,
                        a11: v177);
                ((void (__fastcall *)(idRenderWorld *, va *, float *, void (__fastcall *)(idRenderWorld *, const char *, const idVec3 *, float, const idVec4 *, const int, const int, const bool, const bool), idColor *, int, _DWORD, _DWORD, double))clientGame->renderWorld->DebugText)(
                  a1: clientGame->renderWorld,
                  a2: v86,
                  a3: v183,
                  a4: clientGame->renderWorld->DebugText,
                  a5: &idColor::colorWhite,
                  a6: 1,
                  a7: 0,
                  a8: 0,
                  a9: 0.1);
              }
            }
            v87 = 0;
            if ( owner->targets.num > 0 )
            {
              v88 = 0;
              do
              {
                v89 = owner->targets.list[v88].spawnId.value;
                if ( gameLocal->spawnIds.ptr[v89 & 0x1FFF] == v89 >> 13
                  && (v90 = gameLocal->entities.ptr[v89 & 0x1FFF]) != nullptr )
                {
                  v91 = idEntity::CastTo(c: v90);
                }
                else
                {
                  v91 = nullptr;
                }
                if ( v91 != nullptr )
                {
                  v188[0] = -4.0;
                  v188[1] = -4.0;
                  v188[2] = -4.0;
                  v188[3] = 4.0;
                  v188[4] = 4.0;
                  v188[5] = 4.0;
                  v92 = idEntity::GetPhysics(this: v91);
                  v93 = idEntity::GetPhysics(this: owner);
                  v94 = (float *)v93->GetAbsBounds(this: v93, a2: -1);
                  v95 = (float)(v94[3] + *v94);
                  v97 = (float)(v94[2] + v94[5]);
                  v185[1] = (float)(v94[1] + v94[4]) * (float)0.5;
                  v96 = v92;
                  v185[0] = (float)v95 * (float)0.5;
                  v185[2] = (float)v97 * (float)0.5;
                  GetOrigin = v92->GetOrigin;
                  v98 = clientGame->renderWorld;
                  v100 = v98->__vftable;
                  v101 = (int)GetOrigin(this: v96, a2: 0);
                  ((void (__fastcall *)(idRenderWorld *, idColor *, float *, int, double))v100->DebugArrow)(
                    a1: v98,
                    a2: &idColor::colorYellow,
                    a3: v185,
                    a4: v101,
                    a5: 10.0);
                  v102 = idEntity::GetPhysics(this: v91);
                  v103 = clientGame->renderWorld;
                  v104 = v103->__vftable;
                  v105 = (int)v102->GetOrigin(this: v102, a2: 0);
                  v104->DebugBounds(
                    this: v103,
                    a2: (const idVec4 *)&idColor::colorGreen,
                    a3: (const idBounds *)v188,
                    a4: (const idVec3 *)v105,
                    a5: 0,
                    a6: false);
                  v106 = idEntity::GetPhysics(this: v91);
                  v107 = (float *)v106->GetAbsBounds(this: v106, a2: -1);
                  if ( v107[3] < v3
                    || v107[4] < v4
                    || v107[5] < v5
                    || *v107 > v6
                    || v107[1] > v7
                    || (v108 = 1, v107[2] > v8) )
                  {
                    v108 = 0;
                  }
                  if ( v108 != 0 )
                  {
                    v109 = idEntity::GetPhysics(this: v91);
                    v110 = (float *)v109->GetAbsBounds(this: v109, a2: -1);
                    v111 = (float)(v110[2] + v110[5]);
                    v112 = (float)(v110[1] + v110[4]);
                    v181[0] = (float)(v110[3] + *v110) * (float)0.5;
                    v181[2] = (float)v111 * (float)0.5;
                    v181[1] = (float)v112 * (float)0.5;
                    ((void (__fastcall *)(idRenderWorld *, char *, float *, idRenderWorld_vtbl *, idColor *, int, _DWORD, _DWORD, double))clientGame->renderWorld->DebugText)(
                      a1: clientGame->renderWorld,
                      a2: v91->name.data,
                      a3: v181,
                      a4: clientGame->renderWorld->__vftable,
                      a5: &idColor::colorWhite,
                      a6: 1,
                      a7: 0,
                      a8: 0,
                      a9: 0.1);
                  }
                }
                ++v87;
                ++v88;
              }
              while ( v87 < owner->targets.num );
            }
            if ( v24 != nullptr )
            {
              v113 = v24->facingTarget.spawnId.value;
              if ( gameLocal->spawnIds.ptr[v113 & 0x1FFF] == v113 >> 13 )
              {
                v114 = (idInfo_Trigger_Facing_Target *)gameLocal->entities.ptr[v113 & 0x1FFF];
                if ( v114 != nullptr && idInfo_Trigger_Facing_Target::CastTo(c: v114) != nullptr )
                {
                  v115 = v24->facingTarget.spawnId.value;
                  if ( gameLocal->spawnIds.ptr[v115 & 0x1FFF] == v115 >> 13
                    && (v116 = (idInfo_Trigger_Facing_Target *)gameLocal->entities.ptr[v115 & 0x1FFF]) != nullptr )
                  {
                    v117 = idInfo_Trigger_Facing_Target::CastTo(c: v116);
                  }
                  else
                  {
                    v117 = nullptr;
                  }
                  v118 = idEntity::GetPhysics(this: v117);
                  v119 = v24->facingTarget.spawnId.value;
                  v120 = v118;
                  if ( gameLocal->spawnIds.ptr[v119 & 0x1FFF] == v119 >> 13
                    && (v121 = (idInfo_Trigger_Facing_Target *)gameLocal->entities.ptr[v119 & 0x1FFF]) != nullptr )
                  {
                    v122 = idInfo_Trigger_Facing_Target::CastTo(c: v121);
                  }
                  else
                  {
                    v122 = nullptr;
                  }
                  v123 = v122->radius.value;
                  v124 = (float *)v120->GetOrigin(this: v120, a2: 0);
                  v178[0] = *v124;
                  v178[1] = v124[1];
                  v178[2] = v124[2];
                  v178[3] = v123;
                  v125 = v24->facingTarget.spawnId.value;
                  if ( gameLocal->spawnIds.ptr[v125 & 0x1FFF] == v125 >> 13
                    && (v126 = (idInfo_Trigger_Facing_Target *)gameLocal->entities.ptr[v125 & 0x1FFF]) != nullptr )
                  {
                    v127 = idInfo_Trigger_Facing_Target::CastTo(c: v126);
                  }
                  else
                  {
                    v127 = nullptr;
                  }
                  v128 = &idColor::colorPurple;
                  if ( !v127->doVerticleTest )
                    v128 = &idColor::colorRed;
                  clientGame->renderWorld->DebugSphere(
                    this: clientGame->renderWorld,
                    a2: (const idVec4 *)v128,
                    a3: (const idSphere *)v178,
                    a4: 12,
                    a5: 0,
                    a6: false);
                  v129 = v24->facingTarget.spawnId.value;
                  if ( gameLocal->spawnIds.ptr[v129 & 0x1FFF] == v129 >> 13
                    && (v130 = (idInfo_Trigger_Facing_Target *)gameLocal->entities.ptr[v129 & 0x1FFF]) != nullptr )
                  {
                    v131 = idInfo_Trigger_Facing_Target::CastTo(c: v130);
                  }
                  else
                  {
                    v131 = nullptr;
                  }
                  v132 = idEntity::GetPhysics(this: v131);
                  v133 = idEntity::GetPhysics(this: owner);
                  v134 = (float *)v133->GetAbsBounds(this: v133, a2: -1);
                  v135 = (float)(v134[3] + *v134);
                  v137 = (float)(v134[1] + v134[4]);
                  v184[2] = (float)(v134[2] + v134[5]) * (float)0.5;
                  v136 = v132;
                  v184[0] = (float)v135 * (float)0.5;
                  v184[1] = (float)v137 * (float)0.5;
                  v139 = v132->GetOrigin;
                  v138 = clientGame->renderWorld;
                  v140 = v138->__vftable;
                  v141 = (int)v139(this: v136, a2: 0);
                  ((void (__fastcall *)(idRenderWorld *, idColor *, float *, int, double))v140->DebugArrow)(
                    a1: v138,
                    a2: &idColor::colorMagenta,
                    a3: v184,
                    a4: v141,
                    a5: 10.0);
                }
              }
            }
            if ( v25 != nullptr )
            {
              v142 = v25->facingTarget.spawnId.value;
              if ( gameLocal->spawnIds.ptr[v142 & 0x1FFF] == v142 >> 13 )
              {
                v143 = (idInfo_Trigger_Facing_Target *)gameLocal->entities.ptr[v142 & 0x1FFF];
                if ( v143 != nullptr && idInfo_Trigger_Facing_Target::CastTo(c: v143) != nullptr )
                {
                  v144 = v25->facingTarget.spawnId.value;
                  if ( gameLocal->spawnIds.ptr[v144 & 0x1FFF] == v144 >> 13
                    && (v145 = (idInfo_Trigger_Facing_Target *)gameLocal->entities.ptr[v144 & 0x1FFF]) != nullptr )
                  {
                    v146 = idInfo_Trigger_Facing_Target::CastTo(c: v145);
                  }
                  else
                  {
                    v146 = nullptr;
                  }
                  v147 = idEntity::GetPhysics(this: v146);
                  v148 = v25->facingTarget.spawnId.value;
                  v149 = v147;
                  if ( gameLocal->spawnIds.ptr[v148 & 0x1FFF] == v148 >> 13
                    && (v150 = (idInfo_Trigger_Facing_Target *)gameLocal->entities.ptr[v148 & 0x1FFF]) != nullptr )
                  {
                    v151 = idInfo_Trigger_Facing_Target::CastTo(c: v150);
                  }
                  else
                  {
                    v151 = nullptr;
                  }
                  v152 = v151->radius.value;
                  v153 = (float *)v149->GetOrigin(this: v149, a2: 0);
                  v180[0] = *v153;
                  v180[1] = v153[1];
                  v180[2] = v153[2];
                  v180[3] = v152;
                  v154 = v25->facingTarget.spawnId.value;
                  if ( gameLocal->spawnIds.ptr[v154 & 0x1FFF] == v154 >> 13
                    && (v155 = (idInfo_Trigger_Facing_Target *)gameLocal->entities.ptr[v154 & 0x1FFF]) != nullptr )
                  {
                    v156 = idInfo_Trigger_Facing_Target::CastTo(c: v155);
                  }
                  else
                  {
                    v156 = nullptr;
                  }
                  v157 = &idColor::colorPurple;
                  if ( !v156->doVerticleTest )
                    v157 = &idColor::colorRed;
                  clientGame->renderWorld->DebugSphere(
                    this: clientGame->renderWorld,
                    a2: (const idVec4 *)v157,
                    a3: (const idSphere *)v180,
                    a4: 12,
                    a5: 0,
                    a6: false);
                  v158 = v25->facingTarget.spawnId.value;
                  if ( gameLocal->spawnIds.ptr[v158 & 0x1FFF] == v158 >> 13
                    && (v159 = (idInfo_Trigger_Facing_Target *)gameLocal->entities.ptr[v158 & 0x1FFF]) != nullptr )
                  {
                    v160 = idInfo_Trigger_Facing_Target::CastTo(c: v159);
                  }
                  else
                  {
                    v160 = nullptr;
                  }
                  v161 = idEntity::GetPhysics(this: v160);
                  v162 = idEntity::GetPhysics(this: owner);
                  v163 = (float *)v162->GetAbsBounds(this: v162, a2: -1);
                  v164 = (float)(v163[1] + v163[4]);
                  v166 = (float)(v163[3] + *v163);
                  v187[2] = (float)(v163[2] + v163[5]) * (float)0.5;
                  v165 = v161;
                  v187[1] = (float)v164 * (float)0.5;
                  v187[0] = (float)v166 * (float)0.5;
                  v168 = v161->GetOrigin;
                  v167 = clientGame->renderWorld;
                  v169 = v167->__vftable;
                  v170 = (int)v168(this: v165, a2: 0);
                  ((void (__fastcall *)(idRenderWorld *, idColor *, float *, int, double))v169->DebugArrow)(
                    a1: v167,
                    a2: &idColor::colorMagenta,
                    a3: v187,
                    a4: v170,
                    a5: 10.0);
                }
              }
            }
          }
        }
        v171 = owner->spawnNode.next;
        if ( v171 == nullptr )
          break;
        if ( v171 == owner->spawnNode.head )
          break;
        owner = (idTrigger_Facing *)v171->owner;
        if ( owner == nullptr )
          break;
        z = v179.b[1].z;
      }
    }
  }
}


// ========================================================================
// ?Event_TriggerStuff@idTrigger@@IAA?AVeventVoid@@PAVidEntity@@@Z
// EA  : 0x82CEFAA0
// RVA : 0x00CEFAA0
// PDB : w:\tech5\tungsten\game\entities\trigger.cpp
// ========================================================================

idTrigger *__fastcall idTrigger::Event_TriggerStuff(idTrigger *this, idEntity *result, idEntity *activator)
{
  idEntity *Target; // r29
  idScriptObject *v7; // r3
  idScriptObject *v8; // r3
  char **SpawnId; // r3
  idGameTimeManager *p_gameTimeManager; // r3
  int GameMs; // r3
  int v13; // [sp+60h] [-190h] BYREF
  int v14; // [sp+64h] [-18Ch]
  idScriptFunction v15; // [sp+70h] [-180h] BYREF

  result->ActivateTargets(this: result, a2: activator);
  if ( result[1].name.len != 0
    && !idSuperScriptSystem::InvokeNamedFunction(this: &gameLocal->superScript, callStr: result[1].name.data) )
  {
    idScriptFunction::idScriptFunction(this: &v15);
    Target = result;
    if ( result->targets.num != 0 )
    {
      v7 = result->GetScriptObject_2(this: result);
      if ( !idScriptObject::HasObject(this: v7) && idEntity::GetTarget(this: result, i: 0) != nullptr )
        Target = idEntity::GetTarget(this: result, i: 0);
    }
    idScriptFunction::SetFunction(
      this: &v15,
      ent: Target,
      functionName: result[1].name.data,
      returnType: ev_void,
      numParms: 2,
      8,
      "activatedEntity",
      8);
    idScriptFunction::SetArg_Entity(this: &v15, argNum: 0, ent: result);
    idScriptFunction::SetArg_Entity(this: &v15, argNum: 1, ent: activator);
    idScriptFunction::CallFunction(this: &v15, defer: true);
  }
  v8 = result->GetScriptObject_2(this: result);
  if ( idScriptObject::HasObject(this: v8) )
  {
    idScriptFunction::idScriptFunction(this: &v15);
    idScriptFunction::SetFunction(
      this: &v15,
      ent: result,
      functionName: "onTrigger",
      returnType: ev_void,
      numParms: 1,
      8,
      "activator");
    if ( idScriptFunction::GetFunction(this: &v15) != nullptr )
    {
      idScriptFunction::SetArg_Entity(this: &v15, argNum: 0, ent: activator);
      idScriptFunction::CallFunction(this: &v15, defer: true);
    }
  }
  SpawnId = (char **)idGameLocal::GetSpawnId(this: (idGameLocal *)&v13, result: (idSpawnId *)gameLocal, ent: activator);
  idEntity::SendNotify_OnTrigger(this: result, activator: *SpawnId);
  p_gameTimeManager = &clientGame->gameTimeManager;
  if ( HIBYTE(result[1].listeningToList) != 0 )
  {
    LODWORD(result[1].spawnOrientation.mat[2].z) = idGameTimeManager::GetGameMs(
                                                     this: p_gameTimeManager,
                                                     type: GAMETIME_SCALED)
                                                 + 1;
    idEventReceiver::PostEventMS(this: result, ev: &EV_Remove, time: 0);
  }
  else
  {
    GameMs = idGameTimeManager::GetGameMs(this: p_gameTimeManager, type: GAMETIME_SCALED);
    v14 = (int)(float)(*(float *)&result[1].__vftable * (float)1000.0);
    LODWORD(result[1].spawnOrientation.mat[2].z) = v14 + GameMs;
  }
  return this;
}


// ========================================================================
// ?OnActivate@idTrigger@@MAAXPAVidEntity@@@Z
// EA  : 0x82CEFCE0
// RVA : 0x00CEFCE0
// PDB : w:\tech5\tungsten\game\entities\trigger.cpp
// ========================================================================

void __fastcall idTrigger::OnActivate(idTrigger *this, idEntity *activator)
{
  int nextTriggerTime; // r11
  const idEventArg **v5; // r3
  char v6; // [sp+50h] [-40h] BYREF
  int v8; // [sp+5Ch] [-34h]
  idEventArg v9; // [sp+60h] [-30h] BYREF

  if ( this->triggerFirst )
  {
    this->triggerFirst = false;
    idTrigger::EnableClip(this);
  }
  else if ( this->CanActivate(this, a2: activator) )
  {
    if ( this->delay <= 0.0 )
    {
      idTrigger::Event_TriggerStuff(this: (idTrigger *)&v6, result: this, activator);
    }
    else
    {
      nextTriggerTime = this->nextTriggerTime;
      v8 = (int)(float)(this->delay * (float)1000.0);
      this->nextTriggerTime = v8 + nextTriggerTime;
      v5 = (const idEventArg **)idEventArg::idEventArg(this: &v9, data: activator);
      idEventReceiver::PostEventSec(this, ev: &EV_TriggerStuff, time: this->delay, arg1: *v5);
    }
  }
}


// ========================================================================
// ??0idTrigger_Damage@@QAA@XZ
// EA  : 0x82CEFDD0
// RVA : 0x00CEFDD0
// PDB : w:\tech5\tungsten\game\entities\trigger.cpp
// ========================================================================

idTrigger_Damage *__fastcall idTrigger_Damage::idTrigger_Damage(idTrigger_Damage *this)
{
  idTrigger::idTrigger(this);
  this->attackerDef = nullptr;
  this->__vftable = (idTrigger_Damage_vtbl *)&idTrigger_Damage::`vftable';
  this->health = 1.0;
  this->inflictorDef = nullptr;
  this->damageDef = nullptr;
  return this;
}


// ========================================================================
// ??0idTrigger_TakeDamage@@QAA@XZ
// EA  : 0x82CEFE40
// RVA : 0x00CEFE40
// PDB : w:\tech5\tungsten\game\entities\trigger.cpp
// ========================================================================

idTrigger_TakeDamage *__fastcall idTrigger_TakeDamage::idTrigger_TakeDamage(idTrigger_TakeDamage *this)
{
  idTrigger::idTrigger(this, extraContents_: 128);
  this->canLasercutterActivate = false;
  this->attackerDef = nullptr;
  this->inflictorDef = nullptr;
  this->health = 1.0;
  this->damageDef = nullptr;
  this->passAttackerToActivatedTargets = false;
  this->onlyActivateWhenNoHealth = false;
  this->__vftable = (idTrigger_TakeDamage_vtbl *)&idTrigger_TakeDamage::`vftable';
  this->lastAttacker.spawnId.value = 0x1FFF;
  this->entityToDamage.spawnId.value = 0x1FFF;
  this->lastDamage = 0.0;
  this->lastDamageTime = 0;
  this->alternativeDamageDefs.list = nullptr;
  this->alternativeDamageDefs.granularity = 0;
  this->alternativeDamageDefs.memTag = 5;
  this->alternativeDamageDefs.listStatic = 0;
  this->alternativeDamageDefs.size = 0;
  this->alternativeDamageDefs.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->alternativeDamageDefs);
  return this;
}


// ========================================================================
// __unwind$497948
// EA  : 0x82CEFF08
// RVA : 0x00CEFF08
// PDB : w:\tech5\tungsten\game\entities\trigger.cpp
// ========================================================================

void _unwind_497948()
{
  int v0; // r12

  idTrigger_Exit::~idTrigger_Exit(this: *(idTrigger_Exit **)(v0 - 112 + 132));
}


// ========================================================================
// ?Damage@idTrigger_TakeDamage@@UAAMPAVidEntity@@0PBVidDeclDamage@@MABVidVec3@@PAUtrace_t@@@Z
// EA  : 0x82CEFFA8
// RVA : 0x00CEFFA8
// PDB : w:\tech5\tungsten\game\entities\trigger.cpp
// ========================================================================

float __fastcall idTrigger_TakeDamage::Damage(
        idTrigger_TakeDamage *this,
        idEntity *inflictor,
        idTrigger_TakeDamage *attacker,
        const idDeclDamage *damageDecl,
        double damageScale,
        const idVec3 *dir,
        trace_t *trace)
{
  double lastDamage; // fp1
  int v12; // r3
  int value; // r9
  int v14; // r27
  idEntity *v15; // r3
  idEntity *v16; // r3
  idEntity *v17; // r3
  double v18; // fp1
  double v19; // fp0
  double v20; // fp31
  BOOL passAttackerToActivatedTargets; // r11
  idTrigger_TakeDamage *v22; // r5
  char v23; // r10
  idTrigger_TakeDamage *v24; // r4
  const idEventArg **v25; // r3
  char v27; // [sp+50h] [-80h] BYREF
  int v29; // [sp+5Ch] [-74h]
  idEventArg v30; // [sp+60h] [-70h] BYREF

  if ( (unsigned __int8)idTrigger_TakeDamage::CanDamage(this, inflictor, attacker, damageDecl) == 0 )
  {
    lastDamage = 0.0;
    return *((float *)&lastDamage + 1);
  }
  this->lastDamage = idDeclDamage::DamageAmount(this: damageDecl) * (float)damageScale;
  v12 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
  value = this->entityToDamage.spawnId.value;
  v14 = v12;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
  {
    v15 = gameLocal->entities.ptr[value & 0x1FFF];
    if ( v15 != nullptr && idEntity::CastTo(c: v15) != nullptr )
    {
      if ( this->wait <= 0.0 )
      {
        v17 = idEntityPtr<idEntity const>::operator->(this: &this->entityToDamage);
        ((void (__fastcall *)(idEntity *, idTrigger_TakeDamage *, idEntity *, const idDeclDamage *, double))v17->Damage)(
          a1: v17,
          a2: this,
          a3: attacker,
          a4: damageDecl,
          a5: damageScale);
        lastDamage = this->lastDamage;
        return *((float *)&lastDamage + 1);
      }
      if ( v14 >= this->nextTriggerTime )
      {
        v16 = idEntityPtr<idEntity const>::operator->(this: &this->entityToDamage);
        ((void (__fastcall *)(idEntity *, idTrigger_TakeDamage *, idEntity *, const idDeclDamage *, double))v16->Damage)(
          a1: v16,
          a2: this,
          a3: attacker,
          a4: damageDecl,
          a5: damageScale);
        lastDamage = this->lastDamage;
        v29 = (int)(float)((float)1000.0 * this->wait);
        this->nextTriggerTime = v29 + v14;
        return *((float *)&lastDamage + 1);
      }
LABEL_24:
      lastDamage = this->lastDamage;
      return *((float *)&lastDamage + 1);
    }
  }
  if ( this->lastDamageTime == v14 )
    goto LABEL_24;
  this->lastDamageTime = v14;
  if ( attacker != nullptr )
    this->lastAttacker.spawnId.value = (gameLocal->spawnIds.ptr[attacker->entityNumber] << 13) | attacker->entityNumber;
  else
    this->lastAttacker.spawnId.value = 0x1FFF;
  if ( this->onlyActivateWhenNoHealth )
  {
    v18 = ((double (__fastcall *)(idTrigger_TakeDamage *))this->GetHealth)(a1: this);
    v19 = (float)((float)v18 - this->lastDamage);
    if ( v19 >= 0.0 )
    {
      v20 = 1.0e30;
      if ( v19 <= 1.0e30 )
        v20 = (float)((float)v18 - this->lastDamage);
    }
    else
    {
      v20 = 0.0;
    }
    this->SetHealth(this, a2: v20);
    if ( v20 > 0.0 )
      goto LABEL_24;
    passAttackerToActivatedTargets = this->passAttackerToActivatedTargets;
    goto LABEL_21;
  }
  v23 = 0;
  if ( this->wait > 0.0 )
  {
    if ( v14 < this->nextTriggerTime )
      goto LABEL_29;
    v29 = (int)(float)(this->wait * (float)1000.0);
    this->nextTriggerTime = v29 + v14;
  }
  v23 = 1;
LABEL_29:
  if ( v23 == 0 )
    goto LABEL_24;
  passAttackerToActivatedTargets = this->passAttackerToActivatedTargets;
  if ( this->delay <= 0.0 )
  {
LABEL_21:
    v22 = attacker;
    if ( !passAttackerToActivatedTargets )
      v22 = this;
    idTrigger::Event_TriggerStuff(this: (idTrigger *)&v27, result: this, activator: v22);
    goto LABEL_24;
  }
  v24 = attacker;
  if ( !this->passAttackerToActivatedTargets )
    v24 = this;
  v25 = (const idEventArg **)idEventArg::idEventArg(this: &v30, data: v24);
  idEventReceiver::PostEventSec(this, ev: &EV_TriggerStuff, time: this->delay, arg1: *v25);
  lastDamage = this->lastDamage;
  return *((float *)&lastDamage + 1);
}


// ========================================================================
// ??0idTrigger_DamageType@@QAA@XZ
// EA  : 0x82CF02E8
// RVA : 0x00CF02E8
// PDB : w:\tech5\tungsten\game\entities\trigger.cpp
// ========================================================================

idTrigger_DamageType *__fastcall idTrigger_DamageType::idTrigger_DamageType(idTrigger_DamageType *this)
{
  idTrigger::idTrigger(this, extraContents_: 128);
  this->allCanActivate = false;
  this->__vftable = (idTrigger_DamageType_vtbl *)&idTrigger_DamageType::`vftable';
  this->health = 1.0;
  this->damageTypes = DAMAGETYPE_NONE;
  return this;
}


// ========================================================================
// ??0idTrigger_Hurt@@QAA@XZ
// EA  : 0x82CF0340
// RVA : 0x00CF0340
// PDB : w:\tech5\tungsten\game\entities\trigger.cpp
// ========================================================================

idTrigger_Hurt *__fastcall idTrigger_Hurt::idTrigger_Hurt(idTrigger_Hurt *this)
{
  idTrigger::idTrigger(this);
  this->damageDecl = nullptr;
  this->__vftable = (idTrigger_Hurt_vtbl *)&idTrigger_Hurt::`vftable';
  this->pushFromCenter = false;
  return this;
}


// ========================================================================
// ?Event_TriggerStuff@idTrigger_Hurt@@AAA?AVeventVoid@@PAVidEntity@@@Z
// EA  : 0x82CF0388
// RVA : 0x00CF0388
// PDB : w:\tech5\tungsten\game\entities\trigger.cpp
// ========================================================================

idTrigger_Hurt *__fastcall idTrigger_Hurt::Event_TriggerStuff(
        idTrigger_Hurt *this,
        idEntity *result,
        idEntity *activator)
{
  idEntity *Target; // r30
  idScriptObject *v7; // r3
  idScriptObject *v8; // r3
  idPhysics *Physics; // r30
  idPhysics *v10; // r29
  float *v11; // r3
  double v12; // fp30
  double v13; // fp29
  double v14; // fp28
  float *v15; // r3
  double v16; // fp12
  double v17; // fp0
  double v18; // fp13
  idPhysics *v19; // r3
  float *v20; // r3
  int v21; // r28
  int v22; // r29
  int value; // r9
  idEntity *v24; // r3
  idEntity *v25; // r30
  idPhysics *v26; // r29
  idPhysics *v27; // r30
  float *v28; // r29
  float *v29; // r3
  idGameTimeManager *p_gameTimeManager; // r3
  float v34; // [sp+60h] [-1D0h]
  float v35; // [sp+64h] [-1CCh]
  float v36; // [sp+68h] [-1C8h]
  char v37; // [sp+70h] [-1C0h] BYREF
  idScriptFunction v38; // [sp+80h] [-1B0h] BYREF

  result->ActivateTargets(this: result, a2: activator);
  if ( result[1].name.len != 0 )
  {
    idScriptFunction::idScriptFunction(this: &v38);
    Target = result;
    if ( result->targets.num != 0 )
    {
      v7 = result->GetScriptObject_2(this: result);
      if ( !idScriptObject::HasObject(this: v7) )
        Target = idEntity::GetTarget(this: result, i: 0);
    }
    idScriptFunction::SetFunction(
      this: &v38,
      ent: Target,
      functionName: result[1].name.data,
      returnType: ev_void,
      numParms: 2,
      8,
      "activatedEntity",
      8);
    idScriptFunction::SetArg_Entity(this: &v38, argNum: 0, ent: result);
    idScriptFunction::SetArg_Entity(this: &v38, argNum: 1, ent: activator);
    idScriptFunction::CallFunction(this: &v38, defer: true);
  }
  v8 = result->GetScriptObject_2(this: result);
  if ( idScriptObject::HasObject(this: v8) )
  {
    idScriptFunction::idScriptFunction(this: &v38);
    idScriptFunction::SetFunction(
      this: &v38,
      ent: result,
      functionName: "onTrigger",
      returnType: ev_void,
      numParms: 1,
      8,
      "activator");
    if ( idScriptFunction::GetFunction(this: &v38) != nullptr )
    {
      idScriptFunction::SetArg_Entity(this: &v38, argNum: 0, ent: activator);
      idScriptFunction::CallFunction(this: &v38, defer: true);
    }
  }
  if ( result[1].targets.list != nullptr )
  {
    if ( HIBYTE(result[1].targets.num) != 0 )
    {
      Physics = idEntity::GetPhysics(this: result);
      v10 = idEntity::GetPhysics(this: activator);
      v11 = (float *)Physics->GetAbsBounds(this: Physics, a2: -1);
      v12 = (float)((float)(v11[3] + *v11) * (float)0.5);
      v13 = (float)((float)(v11[4] + v11[1]) * (float)0.5);
      v14 = (float)((float)(v11[5] + v11[2]) * (float)0.5);
      v15 = (float *)v10->GetAbsBounds(this: v10, a2: -1);
      v16 = (float)((float)((float)(v15[5] + v15[2]) * (float)0.5) - (float)v14);
      v17 = (float)((float)((float)(v15[3] + *v15) * (float)0.5) - (float)v12);
      v18 = (float)((float)((float)(v15[4] + v15[1]) * (float)0.5) - (float)v13);
    }
    else
    {
      v19 = idEntity::GetPhysics(this: activator);
      v20 = (float *)v19->GetLinearVelocity(this: (idPhysics *)&v37, result: (idVec3 *)v19, a3: 0);
      v17 = -*v20;
      v18 = -v20[1];
      v16 = -v20[2];
      v34 = v17;
      v35 = v18;
      v21 = 0;
      v36 = v16;
      if ( result->targets.num > 0 )
      {
        v22 = 0;
        while ( 1 )
        {
          if ( v21 < result->targets.num
            && (value = result->targets.list[v22].spawnId.value, gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13)
            && (v24 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
          {
            v25 = idEntity::CastTo(c: v24);
          }
          else
          {
            v25 = nullptr;
          }
          if ( (unsigned __int8)idInfo::IsTypeOf(c: v25) != 0 )
            break;
          ++v21;
          ++v22;
          if ( v21 >= result->targets.num )
          {
            v16 = v36;
            v18 = v35;
            v17 = v34;
            goto LABEL_23;
          }
        }
        v26 = idEntity::GetPhysics(this: activator);
        v27 = idEntity::GetPhysics(this: v25);
        v28 = (float *)v26->GetOrigin(this: v26, a2: 0);
        v29 = (float *)v27->GetOrigin(this: v27, a2: 0);
        v17 = (float)(*v29 - *v28);
        v18 = (float)(v29[1] - v28[1]);
        v16 = (float)(v29[2] - v28[2]);
      }
    }
LABEL_23:
    _FP6 = (float)((float)((float)((float)v17 * (float)v17)
                         + (float)((float)((float)v16 * (float)v16) + (float)((float)v18 * (float)v18)))
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm { fsel      f4, f6, f7, f10 }
    ((void (__fastcall *)(idEntity *, idEntity *, idEntity *, idEntityPtr<idEntity> *, double))activator->Damage)(
      a1: activator,
      a2: result,
      a3: result,
      a4: result[1].targets.list,
      a5: 1.0);
  }
  p_gameTimeManager = &clientGame->gameTimeManager;
  if ( HIBYTE(result[1].listeningToList) != 0 )
  {
    LODWORD(result[1].spawnOrientation.mat[2].z) = idGameTimeManager::GetGameMs(
                                                     this: p_gameTimeManager,
                                                     type: GAMETIME_SCALED)
                                                 + 1;
    idEventReceiver::PostEventMS(this: result, ev: &EV_Remove, time: 0);
  }
  else
  {
    LODWORD(result[1].spawnOrientation.mat[2].z) = (int)(float)(*(float *)&result[1].__vftable * (float)1000.0)
                                                 + idGameTimeManager::GetGameMs(
                                                     this: p_gameTimeManager,
                                                     type: GAMETIME_SCALED);
  }
  return this;
}


// ========================================================================
// ?Event_Touch@idTrigger_Hurt@@AAA?AVeventVoid@@PAVidEntity@@H@Z
// EA  : 0x82CF0878
// RVA : 0x00CF0878
// PDB : w:\tech5\tungsten\game\entities\trigger.cpp
// ========================================================================

idTrigger_Hurt *__fastcall idTrigger_Hurt::Event_Touch(
        idTrigger_Hurt *this,
        idEntity *result,
        idVehicle *other,
        int clipModelId)
{
  int z_low; // r10
  eventVoid *p_z; // r30
  char v9; // r27
  idEntity *v10; // r3
  idEntity *v11; // r3
  idEntity *v12; // r3
  idVehicle *v13; // r31
  idEntity *v14; // r30
  bool v15; // cr58
  float z; // r11
  const idEventArg **v17; // r3
  char v19; // [sp+50h] [-60h] BYREF
  int v21; // [sp+5Ch] [-54h]
  idEventArg v22[4]; // [sp+60h] [-50h] BYREF

  if ( SLODWORD(result[1].spawnOrientation.mat[2].z) > idGameTimeManager::GetGameMs(
                                                         this: &clientGame->gameTimeManager,
                                                         type: GAMETIME_SCALED) )
    return this;
  z_low = LODWORD(result[1].spawnOrientation.mat[1].z);
  p_z = (eventVoid *)&result[1].spawnOrientation.mat[1].z;
  v9 = 0;
  if ( gameLocal->spawnIds.ptr[z_low & 0x1FFF] != z_low >> 13
    || (v10 = gameLocal->entities.ptr[z_low & 0x1FFF]) == nullptr
    || idEntity::CastTo(c: v10) == nullptr )
  {
    if ( HIBYTE(result[1].spawnOrientation.mat[2].x) == 0 || (unsigned __int8)idPlayer::IsTypeOf(c: other) == 0 )
    {
      if ( (LOBYTE(result[1].spawnOrientation.mat[2].x) != 0 || BYTE1(result[1].spawnOrientation.mat[2].x) != 0)
        && (unsigned __int8)idVehicle::IsTypeOf(c: other) != 0 )
      {
        if ( LOBYTE(result[1].spawnOrientation.mat[2].x) == 0 )
        {
          v15 = idVehicle::PlayerIsOccupant(this: other) == nullptr;
          goto LABEL_28;
        }
      }
      else if ( HIBYTE(result[1].spawnOrientation.mat[2].y) == 0 || (unsigned __int8)idAI2::IsTypeOf(c: other) == 0 )
      {
        if ( BYTE2(result[1].spawnOrientation.mat[2].x) != 0
          && (unsigned __int8)idVehicleOccupant::IsTypeOf(c: other) != 0 )
        {
          if ( LODWORD(other->detachableItems.staticList[28].axis.mat[2].y) == 0 )
            goto LABEL_30;
          other = (idVehicle *)LODWORD(other->detachableItems.staticList[28].axis.mat[2].y);
          goto LABEL_29;
        }
        if ( BYTE1(result[1].spawnOrientation.mat[2].y) == 0 )
          goto LABEL_30;
        v15 = (unsigned __int8)idTurret::IsTypeOf(c: other) == 0;
LABEL_28:
        if ( v15 )
          goto LABEL_30;
      }
    }
LABEL_29:
    v9 = 1;
    goto LABEL_30;
  }
  if ( gameLocal->spawnIds.ptr[*(_DWORD *)p_z & 0x1FFF] == *(_DWORD *)p_z >> 13
    && (v11 = gameLocal->entities.ptr[*(_DWORD *)p_z & 0x1FFF]) != nullptr )
  {
    v12 = idEntity::CastTo(c: v11);
  }
  else
  {
    v12 = nullptr;
  }
  if ( v12 == other )
    goto LABEL_29;
  v13 = idVehicle::CastTo(c: other);
  if ( v13 != nullptr )
  {
    v14 = idEntityPtr<idEntity const>::operator->(this: (idEntityPtr<idEntity> *)&result[1].spawnOrientation.mat[1].z);
    if ( v14 == idVehicle::GetDriver(this: v13) )
      goto LABEL_29;
  }
LABEL_30:
  if ( v9 != 0 )
  {
    if ( *(float *)&result[1].listenerList > 0.0 )
    {
      z = result[1].spawnOrientation.mat[2].z;
      v21 = (int)(float)(*(float *)&result[1].listenerList * (float)1000.0);
      LODWORD(result[1].spawnOrientation.mat[2].z) = v21 + LODWORD(z);
      v17 = (const idEventArg **)idEventArg::idEventArg(this: v22, data: other);
      idEventReceiver::PostEventSec(
        this: result,
        ev: &EV_TriggerStuff,
        time: *(float *)&result[1].listenerList,
        arg1: *v17);
      return this;
    }
    idTrigger_Hurt::Event_TriggerStuff(this: (idTrigger_Hurt *)&v19, result, activator: other);
  }
  return this;
}


// ========================================================================
// ?Event_Touch@idTrigger_VehicleAI@@QAA?AVeventVoid@@PAVidEntity@@H@Z
// EA  : 0x82CF0B08
// RVA : 0x00CF0B08
// PDB : w:\tech5\tungsten\game\entities\trigger.cpp
// ========================================================================

idTrigger_VehicleAI *__fastcall idTrigger_VehicleAI::Event_Touch(
        idTrigger_VehicleAI *this,
        eventVoid *result,
        idVehicle *other,
        int clipModelId)
{
  idVehicle *v6; // r3
  idVehicleAI *Driver; // r3
  __int64 v8; // r10
  int v9; // r8
  int v10; // r7
  int v11; // r6
  int v12; // r5
  idVehicleAI *v13; // r3
  long double v14; // fp2
  idVehicleAI *v15; // r31
  idVehicleAI *v16; // r3
  int v18; // r29
  int i; // r31
  int v20; // r9
  idEntity *v21; // r3
  idVehicleAI *v22; // r3

  v6 = idVehicle::CastTo(c: other);
  if ( v6 == nullptr )
    return this;
  Driver = (idVehicleAI *)idVehicle::GetDriver(this: v6);
  v13 = idVehicleAI::CastTo(c: Driver);
  v15 = v13;
  if ( v13 != nullptr )
  {
    *(double *)&v14 = *(float *)&result[956];
    idVehicleAI::OverrideControl(
      this: v13,
      control: (vaiControl_t *)&result[896],
      time: v14,
      a4: v12,
      a5: v11,
      a6: v10,
      a7: v9,
      a8: v8);
    v16 = v15;
  }
  else
  {
    v18 = 0;
    if ( *(int *)&result[100] <= 0 )
      return this;
    for ( i = 0; ; i += 4 )
    {
      v20 = *(_DWORD *)(*(_DWORD *)&result[96] + i);
      if ( gameLocal->spawnIds.ptr[v20 & 0x1FFF] == v20 >> 13
        && (v21 = gameLocal->entities.ptr[v20 & 0x1FFF]) != nullptr )
      {
        v22 = (idVehicleAI *)idEntity::CastTo(c: v21);
      }
      else
      {
        v22 = nullptr;
      }
      v16 = idVehicleAI::CastTo(c: v22);
      if ( v16 != nullptr )
        break;
      if ( ++v18 >= *(_DWORD *)&result[100] )
        return this;
    }
  }
  idVehicleAI::HandleActions(this: v16, actions: (vaiAction_t *)&result[960]);
  return this;
}


// ========================================================================
// ??0idTrigger_Multiplayer@@QAA@XZ
// EA  : 0x82CF0BF8
// RVA : 0x00CF0BF8
// PDB : w:\tech5\tungsten\game\entities\trigger.cpp
// ========================================================================

idTrigger_Multiplayer *__fastcall idTrigger_Multiplayer::idTrigger_Multiplayer(idTrigger_Multiplayer *this)
{
  idTrigger::idTrigger(this);
  this->requireAllPlayers = false;
  this->__vftable = (idTrigger_Multiplayer_vtbl *)&idTrigger_Multiplayer::`vftable';
  this->clientCollision.spawnId.value = 0x1FFF;
  return this;
}


// ========================================================================
// ?Spawn@idTrigger_Multiplayer@@QAAXXZ
// EA  : 0x82CF0C48
// RVA : 0x00CF0C48
// PDB : w:\tech5\tungsten\game\entities\trigger.cpp
// ========================================================================

void __fastcall idTrigger_Multiplayer::Spawn(idTrigger_Multiplayer *this)
{
  idPresentable *presentable; // r3
  int v3; // r29
  int value; // r10
  idEntity *v5; // r3
  int v6; // r9
  idEntity *v7; // r3
  idEntity *v8; // r31
  idPresentable *v9; // r11

  presentable = this->presentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    presentable = this->presentable;
  }
  v3 = (int)presentable->GetCollisionTriggerInterface(this: presentable);
  if ( v3 != 0 )
  {
    value = this->clientCollision.spawnId.value;
    if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
    {
      v5 = gameLocal->entities.ptr[value & 0x1FFF];
      if ( v5 != nullptr && idEntity::CastTo(c: v5) != nullptr )
      {
        v6 = this->clientCollision.spawnId.value;
        if ( gameLocal->spawnIds.ptr[v6 & 0x1FFF] == v6 >> 13 && (v7 = gameLocal->entities.ptr[v6 & 0x1FFF]) != nullptr )
          v8 = idEntity::CastTo(c: v7);
        else
          v8 = nullptr;
        v9 = v8->presentable;
        if ( v9 != nullptr || (idEntity::InitPresentableInternal(this: v8), (v9 = v8->presentable) != nullptr) )
          *(_DWORD *)(v3 + 1200) = v9->spawnId;
        else
          *(_DWORD *)(v3 + 1200) = 0;
      }
    }
  }
}


// ========================================================================
// ?Event_Touch@idTrigger_VehicleUse@@QAA?AVeventVoid@@PAVidEntity@@H@Z
// EA  : 0x82CF0D58
// RVA : 0x00CF0D58
// PDB : w:\tech5\tungsten\game\entities\trigger.cpp
// ========================================================================

idTrigger_VehicleUse *__fastcall idTrigger_VehicleUse::Event_Touch(
        idTrigger_VehicleUse *this,
        idEntity *result,
        idVehicle *other,
        int clipModelId)
{
  idVehicle *v6; // r3
  idEntity *v7; // r30
  idPlayer *Driver; // r3
  idPlayer *v9; // r29
  idProp_WeaponStatic *Target; // r3
  idProp_WeaponStatic *v11; // r3
  idProp_WeaponStatic *v12; // r31
  idPhysics *Physics; // r31
  idPhysics *v14; // r29
  float *v15; // r3
  double v16; // fp8
  double v17; // fp6
  idPhysics *v18; // r3
  idPhysics *v19; // r3
  idVec3 v21; // [sp+50h] [-50h] BYREF
  float v22[16]; // [sp+60h] [-40h] BYREF

  v6 = idVehicle::CastTo(c: other);
  v7 = v6;
  if ( v6 != nullptr )
  {
    Driver = (idPlayer *)idVehicle::GetDriver(this: v6);
    v9 = idPlayer::CastTo(c: Driver);
    if ( v9 != nullptr )
    {
      Target = (idProp_WeaponStatic *)idEntity::GetTarget(this: result, i: 0);
      if ( Target != nullptr )
      {
        v11 = idProp_WeaponStatic::CastTo(c: Target);
        v12 = v11;
        if ( v11 != nullptr && v11->IsCurrentlyUsable(this: v11, a2: v9) && v12->Use(this: v12, a2: v9, a3: USABLE_PROP) )
        {
          Physics = idEntity::GetPhysics(this: result);
          v14 = idEntity::GetPhysics(this: v7);
          v15 = (float *)Physics->GetAbsBounds(this: Physics, a2: -1);
          v16 = (float)(v15[1] + v15[4]);
          v17 = (float)(v15[3] + *v15);
          v22[2] = (float)(v15[2] + v15[5]) * (float)0.5;
          v22[1] = (float)v16 * (float)0.5;
          v22[0] = (float)v17 * (float)0.5;
          v14->SetOrigin(this: v14, a2: (const idVec3 *)v22, a3: -1);
          v21 = vec3_origin;
          v18 = idEntity::GetPhysics(this: v7);
          v18->SetAngularVelocity(this: v18, a2: &v21, a3: 0);
          v19 = idEntity::GetPhysics(this: v7);
          v19->SetLinearVelocity(this: v19, a2: &v21, a3: 0);
        }
      }
    }
  }
  return this;
}


// ========================================================================
// ?CanActivate@idTrigger_Facing@@MAA_NPAVidEntity@@@Z
// EA  : 0x82CF0F00
// RVA : 0x00CF0F00
// PDB : w:\tech5\tungsten\game\entities\trigger.cpp
// ========================================================================

int __fastcall idTrigger_Facing::CanActivate(idTrigger_Facing *this, idEntity *activator)
{
  idPlayer *PlayerFromEntity; // r30
  int value; // r9
  idInfo_Trigger_Facing_Target *v6; // r3
  idPresentable *presentable; // r3
  int v8; // r3
  idInfo_Trigger_Facing_Target *FacingTarget; // r3
  idPhysics *Physics; // r3
  float *v11; // r3
  double v12; // fp31
  double v13; // fp1
  int result; // r3
  double v15; // fp2
  double v20; // fp1
  double v21; // fp13
  double v22; // fp8
  double v23; // fp13
  double v24; // fp31
  double v25; // fp30
  double v26; // fp29
  double v27; // fp8
  float v28; // [sp+50h] [-90h]
  float v29; // [sp+54h] [-8Ch]
  float v30; // [sp+58h] [-88h]
  idVec3 v31; // [sp+70h] [-70h] BYREF
  idMat3 v32; // [sp+80h] [-60h] BYREF
  idVec3 v33; // 0:^60.12

  if ( idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) >= this->nextTriggerTime )
  {
    PlayerFromEntity = idGameLocal::GetPlayerFromEntity(this: gameLocal, activator);
    if ( PlayerFromEntity != nullptr )
    {
      value = this->facingTarget.spawnId.value;
      if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
      {
        v6 = (idInfo_Trigger_Facing_Target *)gameLocal->entities.ptr[value & 0x1FFF];
        if ( v6 != nullptr && idInfo_Trigger_Facing_Target::CastTo(c: v6) != nullptr )
        {
          presentable = PlayerFromEntity->presentable;
          if ( presentable != nullptr )
            v8 = (int)presentable->GetPlayerInterface_2(this: presentable);
          else
            v8 = 0;
          idView::GetViewPos(this: (idView *)(v8 + 16224), origin: &v31, axis: &v32);
          v33 = v32.mat[0];
          FacingTarget = idTrigger_Facing::GetFacingTarget(this);
          Physics = idEntity::GetPhysics(this: FacingTarget);
          v11 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
          v28 = *v11;
          v29 = v11[1];
          v30 = v11[2];
          v12 = idTrigger_Facing::GetFacingTarget(this)->radius.value;
          if ( idTrigger_Facing::GetFacingTarget(this)->doVerticleTest )
          {
            if ( (float)((float)((float)(v31.x - v28) * v33.x)
                       + (float)((float)(v33.z * (float)(v31.z - v30)) + (float)((float)(v31.y - v29) * v33.y))) <= 0.0 )
            {
              v13 = (float)((float)((float)(v33.x * (float)2.0) * (float)(v31.x - v28))
                          + (float)((float)((float)(v33.z * (float)2.0) * (float)(v31.z - v30))
                                  + (float)((float)(v33.y * (float)2.0) * (float)(v31.y - v29))));
              if ( (float)((float)((float)v13 * (float)v13)
                         - (float)((float)((float)-(float)((float)((float)v12 * (float)v12)
                                                         - (float)((float)((float)(v31.x - v28) * (float)(v31.x - v28))
                                                                 + (float)((float)((float)(v31.z - v30)
                                                                                 * (float)(v31.z - v30))
                                                                         + (float)((float)(v31.y - v29)
                                                                                 * (float)(v31.y - v29)))))
                                         * (float)((float)(v33.y * v33.y)
                                                 + (float)((float)(v33.z * v33.z) + (float)(v33.x * v33.x))))
                                 * (float)4.0)) >= 0.0 )
                return 1;
            }
          }
          else
          {
            v15 = (float)((float)((float)(v28 - v31.x) * (float)(v28 - v31.x))
                        + (float)((float)(v29 - v31.y) * (float)(v29 - v31.y)));
            _FP1 = (float)((float)((float)(v33.x * v33.x) + (float)(v33.y * v33.y)) - idMath::FLT_SMALLEST_NON_DENORMAL);
            __asm { fsel      f4, f1, f3, f13 }
            _FP7 = (float)((float)((float)((float)(v28 - v31.x) * (float)(v28 - v31.x))
                                 + (float)((float)(v29 - v31.y) * (float)(v29 - v31.y)))
                         - idMath::FLT_SMALLEST_NON_DENORMAL);
            __asm { fsel      f3, f7, f2, f13 }
            v20 = __frsqrte(_FP4);
            v21 = __frsqrte(_FP3);
            v22 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v21
                                                                                                * (float)((float)v15 * (float)0.5))
                                                                                        * (float)v21)
                                                                                - (float)1.5)
                                                                * (float)v21)
                                                        * (float)((float)v15 * (float)0.5))
                                                * (float)((float)-(float)((float)((float)((float)v21
                                                                                        * (float)((float)v15 * (float)0.5))
                                                                                * (float)v21)
                                                                        - (float)1.5)
                                                        * (float)v21))
                                        - (float)1.5)
                        * (float)((float)-(float)((float)((float)((float)v21 * (float)((float)v15 * (float)0.5))
                                                        * (float)v21)
                                                - (float)1.5)
                                * (float)v21));
            v23 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v21 * (float)((float)v15 * (float)0.5)) * (float)v21) - (float)1.5) * (float)v21) * (float)((float)v15 * (float)0.5))
                                                                                                * (float)((float)-(float)((float)((float)((float)v21 * (float)((float)v15 * (float)0.5)) * (float)v21) - (float)1.5) * (float)v21))
                                                                                        - (float)1.5)
                                                                        * (float)((float)-(float)((float)((float)((float)v21 * (float)((float)v15 * (float)0.5)) * (float)v21)
                                                                                                - (float)1.5)
                                                                                * (float)v21))
                                                                * (float)((float)v15 * (float)0.5))
                                                        * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v21 * (float)((float)v15 * (float)0.5)) * (float)v21) - (float)1.5) * (float)v21)
                                                                                                * (float)((float)v15 * (float)0.5))
                                                                                        * (float)((float)-(float)((float)((float)((float)v21 * (float)((float)v15 * (float)0.5)) * (float)v21) - (float)1.5)
                                                                                                * (float)v21))
                                                                                - (float)1.5)
                                                                * (float)((float)-(float)((float)((float)((float)v21 * (float)((float)v15 * (float)0.5))
                                                                                                * (float)v21)
                                                                                        - (float)1.5)
                                                                        * (float)v21)))
                                                - (float)1.5)
                                * (float)v22)
                        * (float)v15);
            v24 = (float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v20 * (float)((float)((float)(v33.x * v33.x) + (float)(v33.y * v33.y)) * (float)0.5)) * (float)v20) - (float)1.5)
                                                                                        * (float)v20)
                                                                                * (float)((float)((float)(v33.x * v33.x)
                                                                                                + (float)(v33.y * v33.y))
                                                                                        * (float)0.5))
                                                                        * (float)((float)-(float)((float)((float)((float)v20 * (float)((float)((float)(v33.x * v33.x) + (float)(v33.y * v33.y)) * (float)0.5)) * (float)v20)
                                                                                                - (float)1.5)
                                                                                * (float)v20))
                                                                - (float)1.5)
                                                * (float)((float)-(float)((float)((float)((float)v20
                                                                                        * (float)((float)((float)(v33.x * v33.x) + (float)(v33.y * v33.y))
                                                                                                * (float)0.5))
                                                                                * (float)v20)
                                                                        - (float)1.5)
                                                        * (float)v20))
                                        * v33.x)
                                * (float)v23)
                        - (float)(v28 - v31.x));
            v25 = (float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v20 * (float)((float)((float)(v33.x * v33.x) + (float)(v33.y * v33.y)) * (float)0.5)) * (float)v20) - (float)1.5)
                                                                                        * (float)v20)
                                                                                * (float)((float)((float)(v33.x * v33.x)
                                                                                                + (float)(v33.y * v33.y))
                                                                                        * (float)0.5))
                                                                        * (float)((float)-(float)((float)((float)((float)v20 * (float)((float)((float)(v33.x * v33.x) + (float)(v33.y * v33.y)) * (float)0.5)) * (float)v20)
                                                                                                - (float)1.5)
                                                                                * (float)v20))
                                                                - (float)1.5)
                                                * (float)((float)-(float)((float)((float)((float)v20
                                                                                        * (float)((float)((float)(v33.x * v33.x) + (float)(v33.y * v33.y))
                                                                                                * (float)0.5))
                                                                                * (float)v20)
                                                                        - (float)1.5)
                                                        * (float)v20))
                                        * v33.y)
                                * (float)v23)
                        - (float)(v29 - v31.y));
            v26 = idTrigger_Facing::GetFacingTarget(this)->radius.value;
            v27 = (float)(idTrigger_Facing::GetFacingTarget(this)->radius.value * (float)v26);
            result = 1;
            if ( (float)((float)((float)v25 * (float)v25) + (float)((float)v24 * (float)v24)) < v27 )
              return result;
          }
        }
      }
    }
  }
  return 0;
}


// ========================================================================
// ??0idTrigger_BoostPad@@QAA@XZ
// EA  : 0x82CF1228
// RVA : 0x00CF1228
// PDB : w:\tech5\tungsten\game\entities\trigger.cpp
// ========================================================================

idTrigger_BoostPad *__fastcall idTrigger_BoostPad::idTrigger_BoostPad(idTrigger_BoostPad *this)
{
  idTrigger::idTrigger(this);
  this->__vftable = (idTrigger_BoostPad_vtbl *)&idTrigger_BoostPad::`vftable';
  this->fxDecl = nullptr;
  this->fxInfo.spawnId.value = 0x1FFF;
  this->time = 1000;
  this->acceleration = 5000000.0;
  this->activationSpeed = 0.0;
  this->targetFraction = 1.0;
  this->boostUpDir.x = 0.0;
  this->boostUpDir.y = 0.0;
  this->boostUpDir.z = 0.5;
  return this;
}


// ========================================================================
// ?GetFXAxis@idMultiplayerTrigger_BoostPad@@QBAABVidMat3@@XZ
// EA  : 0x82CF12B8
// RVA : 0x00CF12B8
// PDB : w:\tech5\tungsten\game\entities\trigger.cpp
// ========================================================================

const idMat3 *__fastcall idMultiplayerTrigger_BoostPad::GetFXAxis(idMultiplayerTrigger_BoostPad *this)
{
  int value; // r10
  idInfo *v2; // r3
  idPhysics *Physics; // r3

  value = this->fxInfo.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
  {
    v2 = (idInfo *)gameLocal->entities.ptr[value & 0x1FFF];
    if ( v2 != nullptr )
      this = (idMultiplayerTrigger_BoostPad *)idInfo::CastTo(c: v2);
    else
      this = nullptr;
  }
  Physics = idEntity::GetPhysics(this);
  return Physics->GetAxis(this: Physics, a2: 0);
}


// ========================================================================
// ??0idTrigger_DummyFire@@QAA@XZ
// EA  : 0x82CF1348
// RVA : 0x00CF1348
// PDB : w:\tech5\tungsten\game\entities\trigger.cpp
// ========================================================================

idTrigger_DummyFire *__fastcall idTrigger_DummyFire::idTrigger_DummyFire(idTrigger_DummyFire *this)
{
  idTrigger::idTrigger(this);
  this->weaponDecl = nullptr;
  this->__vftable = (idTrigger_DummyFire_vtbl *)&idTrigger_DummyFire::`vftable';
  this->ammoIndex = 0;
  this->numShots = 0;
  this->shouldReset = false;
  this->resetTime = false;
  this->minResetTime = 0;
  this->maxResetTime = 0;
  this->minTargetTime = 0;
  this->maxTargetTime = 0;
  this->fromPosition.spawnId.value = 0x1FFF;
  this->weapon = nullptr;
  this->currentTarget.spawnId.value = 0x1FFF;
  this->currentShotsLeft = 0;
  this->nextFireTime = 0;
  this->nextResetTime = 0;
  this->nextTargetTime = 0;
  this->fireChannel = 0;
  return this;
}


// ========================================================================
// ?Think@idTrigger_DummyFire@@UAAXXZ
// EA  : 0x82CF13D8
// RVA : 0x00CF13D8
// PDB : w:\tech5\tungsten\game\entities\trigger.cpp
// ========================================================================

void __fastcall idTrigger_DummyFire::Think(idTrigger_DummyFire *this)
{
  double v2; // fp1
  int minResetTime; // r11
  __int64 v4; // r7
  int v5; // r3
  idEntity *Target; // r3
  double v7; // fp1
  int minTargetTime; // r11
  __int64 v9; // r7
  int value; // r9
  idEntity *v11; // r3
  int v12; // r27
  idEntity *v13; // r3
  idPhysics *Physics; // r3
  int v15; // r3
  int *v16; // r4
  int v17; // r11
  idEntity *v18; // r3
  idPhysics *v19; // r3
  int v20; // r3
  int ammoIndex; // r6
  int v22; // r11
  int v23; // r10
  idDeclWeapon::ammoClip *list; // r5
  const idDeclProjectile *projectileDecl; // r27
  idFinishFireResults *v26; // r11
  int i; // ctr
  idPresentable *presentable; // r11
  const idDeclWeapon *weaponDecl; // r11
  idMat3 *v30; // r3
  soundChannel_t fireChannel; // r28
  const idSoundShader *lastShotSound; // r27
  idEntity *entity; // r29
  int GameMs; // r3
  idProjectile *v35; // r3
  idProjectile *v36; // r26
  idEntity *v37; // r3
  idPresentable *v38; // r11
  idEntity *v39; // r28
  unsigned int spawnId; // r11
  int v41; // r3
  int v42; // r8
  idAIEventManager v43; // [sp+50h] [-B70h] BYREF
  unsigned int v44; // [sp+A0h] [-B20h]
  idFireParms v45; // [sp+B0h] [-B10h] BYREF
  idMat3 v46; // [sp+150h] [-A70h] BYREF
  idFinishFireResults v47; // [sp+180h] [-A40h] BYREF
  soundShaderParms_t v48; // [sp+1D0h] [-9F0h] BYREF
  idTestFireResults v49; // [sp+270h] [-950h] BYREF

  if ( this->targets.num <= 0 )
    goto LABEL_18;
  if ( this->resetTime
    && this->nextResetTime <= idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) )
  {
    this->currentShotsLeft = this->numShots;
    v2 = RandomFloat();
    minResetTime = this->minResetTime;
    LODWORD(v4) = this->maxResetTime - minResetTime;
    v43.eventList.num = (int)(float)((float)v4 * (float)v2);
    this->nextResetTime = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED)
                        + v43.eventList.num
                        + minResetTime;
  }
  if ( this->nextTargetTime > 0
    && this->nextTargetTime <= idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) )
  {
    v5 = RandomInt(max: this->targets.num);
    Target = idEntity::GetTarget(this, i: v5);
    if ( Target != nullptr )
    {
      v43.eventList.list = (idAIEvent **)Target->entityNumber;
      this->currentTarget.spawnId.value = (*((_DWORD *)&gameLocal->__vftable + (int)v43.eventList.list + 29755) << 13)
                                        | (int)v43.eventList.list;
    }
    else
    {
      this->currentTarget.spawnId.value = 0x1FFF;
    }
    v7 = RandomFloat();
    minTargetTime = this->minTargetTime;
    LODWORD(v9) = this->maxTargetTime - minTargetTime;
    v43.eventList.num = (int)(float)((float)v9 * (float)v7);
    this->nextTargetTime = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED)
                         + v43.eventList.num
                         + minTargetTime;
  }
  value = this->currentTarget.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] != value >> 13
    || (v11 = gameLocal->entities.ptr[value & 0x1FFF]) == nullptr
    || idEntity::CastTo(c: v11) == nullptr )
  {
    if ( this->targets.num != 1 )
      return;
    goto LABEL_18;
  }
  if ( this->currentShotsLeft <= 0 )
  {
    if ( this->resetTime )
      return;
    goto LABEL_18;
  }
  if ( this->nextFireTime <= idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) )
  {
    v12 = this->weaponDecl->firingIntervals[0];
    this->nextFireTime = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) + v12;
    v13 = idEntityPtr<idEntity const>::operator->(this: &this->fromPosition);
    Physics = idEntity::GetPhysics(this: v13);
    v15 = (int)Physics->GetOrigin(this: Physics, a2: 0);
    v16 = *(int **)(v15 + 4);
    v17 = *(_DWORD *)(v15 + 8);
    v43.eventHash.hash = *(int **)v15;
    v43.eventHash.indexChain = v16;
    v43.eventHash.hashSize = v17;
    v18 = idEntityPtr<idEntity const>::operator->(this: &this->currentTarget);
    v19 = idEntity::GetPhysics(this: v18);
    v20 = (int)v19->GetOrigin(this: v19, a2: 0);
    ammoIndex = this->ammoIndex;
    v22 = *(_DWORD *)(v20 + 4);
    v23 = *(_DWORD *)(v20 + 8);
    list = this->weaponDecl->validAmmoClips.list;
    v43.eventList.list = *(idAIEvent ***)v20;
    v43.eventList.num = v22;
    v43.eventList.size = v23;
    projectileDecl = list[ammoIndex].validAmmoDecl->projectileDecl;
    if ( projectileDecl->hitscan )
    {
      idFireParms::idFireParms(this: &v45);
      memset(&v49, 0, sizeof(v49));
      v26 = &v47;
      v47.numProjectiles = 0;
      for ( i = 16; i != 0; --i )
      {
        v26 = (idFinishFireResults *)((char *)v26 + 4);
        v26->numProjectiles = 0;
      }
      presentable = this->presentable;
      v45.addSpread = projectileDecl->spread;
      if ( presentable != nullptr
        || (idEntity::InitPresentableInternal(this), (presentable = this->presentable) != nullptr) )
      {
        v45.attacker.spawnId = presentable->spawnId;
      }
      else
      {
        v45.attacker.spawnId = 0;
      }
      weaponDecl = this->weaponDecl;
      *(float *)&v43.eventHash.granularity = *(float *)&v43.eventList.list - *(float *)&v43.eventHash.hash;
      *(float *)&v43.eventHash.lookupMask = *(float *)&v43.eventList.size - *(float *)&v43.eventHash.hashSize;
      v45.wepDef = weaponDecl;
      *(float *)&v43.eventHash.hashMask = *(float *)&v43.eventList.num - *(float *)&v43.eventHash.indexChain;
      v45.start.x = *(float *)&v43.eventHash.hash;
      v45.start.y = *(float *)&v43.eventHash.indexChain;
      v45.start.z = *(float *)&v43.eventHash.hashSize;
      idVec3::NormalizeFast(this: (idVec3 *)&v43.eventHash.granularity);
      v30 = idVec3::ToMat3(this: v46.mat, result: (idMat3 *)&v43.eventHash.granularity);
      v43.eventList.list = (idAIEvent **)&v30->mat[1];
      v45.fireAxis.mat[0].x = v30->mat[0].x;
      v43.eventList.list = (idAIEvent **)&v30->mat[2];
      v45.fireAxis.mat[0].y = v30->mat[0].y;
      v45.fireAxis.mat[0].z = v30->mat[0].z;
      v45.fireAxis.mat[1] = v30->mat[1];
      v45.fireAxis.mat[2].x = v30->mat[2].x;
      v45.fireAxis.mat[2].y = v30->mat[2].y;
      v45.fireAxis.mat[2].z = v30->mat[2].z;
      v45.projDef = projectileDecl;
      if ( (unsigned __int8)idClientGame::TestFire(this: clientGame, fp: &v45, tfr: &v49) != 0
        && idGameLocal::FinishFire(this: gameLocal, fp: &v45, tfr: &v49, ffr: &v47) )
      {
        fireChannel = this->fireChannel;
        lastShotSound = projectileDecl->lastShotSound;
        this->fireChannel = fireChannel + 1;
        soundShaderParms_t::Clear(this: &v48);
        v48.soundShaderFlags = 0;
        idEntity::StartSoundShader(this, channel: fireChannel, shader: lastShotSound, parms: &v48, peerMask: 0xFFu);
        if ( common->IsServer(this: common) )
        {
          entity = idPresentablePtr<idPresentableProjectile>::operator->(this: &v45.attacker)->entity;
          GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
          idAIEventManager::AddEvent(
            this: &v43,
            result: &gameLocal->aiEventManager,
            eventDecl: this->weaponDecl->gunfireEventDecl,
            curTime: GameMs,
            originator: entity,
            instigator: nullptr,
            origin: &v45.start,
            delay: 0);
        }
      }
      idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v45.targetList);
LABEL_39:
      --this->currentShotsLeft;
      return;
    }
    v35 = (idProjectile *)gameLocal->SpawnEntityFromDef(
                            this: gameLocal,
                            a2: projectileDecl->notHitscanInfo.entityDef,
                            a3: -1,
                            a4: -1,
                            a5: -1);
    v36 = idProjectile::CastTo(c: v35);
    if ( v36 != nullptr )
    {
      v37 = idEntityPtr<idEntity const>::operator->(this: &this->currentTarget);
      v38 = v37->presentable;
      v39 = v37;
      if ( v38 == nullptr )
      {
        idEntity::InitPresentableInternal(this: v37);
        v38 = v39->presentable;
      }
      v43.eventPools.list = (idAIEventPool **)1;
      *(idVec3 *)&v43.eventPools.num = vec3_origin;
      if ( v38 != nullptr )
        spawnId = v38->spawnId;
      else
        spawnId = 0;
      v44 = spawnId;
      *(float *)&v43.receivers.list = *(float *)&v43.eventList.list - *(float *)&v43.eventHash.hash;
      *(float *)&v43.receivers.num = *(float *)&v43.eventList.num - *(float *)&v43.eventHash.indexChain;
      *(float *)&v43.receivers.size = *(float *)&v43.eventList.size - *(float *)&v43.eventHash.hashSize;
      idVec3::NormalizeFast(this: (idVec3 *)&v43.receivers);
      idVec3::ToMat3(this: v46.mat, result: (idMat3 *)&v43.receivers);
      v41 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      idProjectile::Launch(
        this: v36,
        attacker_: this,
        start: (const idVec3 *)&v43.eventHash,
        fireAxis: &v46,
        target: (const idProjectileTarget *)&v43.eventPools,
        initialSpeed: projectileDecl->notHitscanInfo.speed,
        startTime: v42,
        launchTimeOverride: v41);
      goto LABEL_39;
    }
LABEL_18:
    idEntity::BecomeInactive(this, flags: 1);
  }
}


// ========================================================================
// __unwind$499661
// EA  : 0x82CF1A0C
// RVA : 0x00CF1A0C
// PDB : w:\tech5\tungsten\game\entities\trigger.cpp
// ========================================================================

void _unwind_499661()
{
  int v0; // r12

  idFireParms::~idFireParms(this: (idAI2::idAIVolatile::idAIEventInfo *)(v0 - 3008 + 176));
}


// ========================================================================
// ??0idTrigger_WastelandTownEnter@@QAA@XZ
// EA  : 0x82CF1A38
// RVA : 0x00CF1A38
// PDB : w:\tech5\tungsten\game\entities\trigger.cpp
// ========================================================================

idTrigger_WastelandTownEnter *__fastcall idTrigger_WastelandTownEnter::idTrigger_WastelandTownEnter(
        idTrigger_WastelandTownEnter *this)
{
  idTrigger::idTrigger(this);
  this->isEnteringTown = false;
  this->__vftable = (idTrigger_WastelandTownEnter_vtbl *)&idTrigger_WastelandTownEnter::`vftable';
  return this;
}


// ========================================================================
// ??0idTrigger_EventListener@@QAA@XZ
// EA  : 0x82CF1A80
// RVA : 0x00CF1A80
// PDB : w:\tech5\tungsten\game\entities\trigger.cpp
// ========================================================================

idTrigger_EventListener *__fastcall idTrigger_EventListener::idTrigger_EventListener(idTrigger_EventListener *this)
{
  idTrigger::idTrigger(this);
  this->onSprinting = false;
  this->__vftable = (idTrigger_EventListener_vtbl *)&idTrigger_EventListener::`vftable';
  this->onShooting = false;
  this->eventResponseFlags = 0;
  return this;
}


// ========================================================================
// ?OnAIEvent@idTrigger_EventListener@@UAAXPBVidAIEvent@@@Z
// EA  : 0x82CF1AD0
// RVA : 0x00CF1AD0
// PDB : w:\tech5\tungsten\game\entities\trigger.cpp
// ========================================================================

void __fastcall idTrigger_EventListener::OnAIEvent(idTrigger_EventListener *this, const idAIEvent *event)
{
  float y; // r10
  float z; // r9
  idPhysics *Physics; // r3
  float *v7; // r3
  char v8; // r11
  int value; // r10
  idEntity *v10; // r3
  idEntity *v11; // r29
  int v12; // r9
  idEntity *v13; // r3
  char v14; // [sp+50h] [-40h] BYREF
  float x; // [sp+58h] [-38h]
  float v16; // [sp+5Ch] [-34h]
  float v17; // [sp+60h] [-30h]

  y = event->origin.y;
  z = event->origin.z;
  x = event->origin.x;
  v16 = y;
  v17 = z;
  Physics = idEntity::GetPhysics(this);
  v7 = (float *)Physics->GetAbsBounds(this: Physics, a2: -1);
  if ( x < (double)*v7
    || v16 < (double)v7[1]
    || v17 < (double)v7[2]
    || x > (double)v7[3]
    || v16 > (double)v7[4]
    || (v8 = 1, v17 > (double)v7[5]) )
  {
    v8 = 0;
  }
  if ( v8 != 0 )
  {
    value = event->originator.spawnId.value;
    if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
    {
      v10 = gameLocal->entities.ptr[value & 0x1FFF];
      if ( v10 != nullptr )
      {
        v11 = idEntity::CastTo(c: v10);
        if ( v11 != nullptr )
        {
          if ( (v12 = this->entityCanActivate.spawnId.value, gameLocal->spawnIds.ptr[v12 & 0x1FFF] == v12 >> 13)
            && (v13 = gameLocal->entities.ptr[v12 & 0x1FFF]) != nullptr
            && idEntity::CastTo(c: v13) != nullptr
            && idEntityPtr<idEntity const>::operator->(this: &this->entityCanActivate) == v11
            || this->playerCanActivate && (unsigned __int8)idClass::IsType(this: v11, superclass: &idPlayer::Type) != 0
            || this->aiCanActivate && (unsigned __int8)idClass::IsType(this: v11, superclass: &idAI2::Type) != 0 )
          {
            idTrigger::Event_TriggerStuff(this: (idTrigger *)&v14, result: this, activator: v11);
          }
        }
      }
    }
  }
}


// ========================================================================
// ??0idTrigger_Exit@@QAA@XZ
// EA  : 0x82CF1C88
// RVA : 0x00CF1C88
// PDB : w:\tech5\tungsten\game\entities\trigger.cpp
// ========================================================================

idTrigger_Exit *__fastcall idTrigger_Exit::idTrigger_Exit(idTrigger_Exit *this)
{
  idTrigger::idTrigger(this);
  this->__vftable = (idTrigger_Exit_vtbl *)&idTrigger_Exit::`vftable';
  this->activator.spawnId.value = 0x1FFF;
  this->lastTouchTime = 0;
  return this;
}


// ========================================================================
// ?OnActivate@idTrigger_Exit@@UAAXPAVidEntity@@@Z
// EA  : 0x82CF1D38
// RVA : 0x00CF1D38
// PDB : w:\tech5\tungsten\game\entities\trigger.cpp
// ========================================================================

void __fastcall idTrigger_Exit::OnActivate(idTrigger_Exit *this, idEntity *activator)
{
  int v3; // r3
  int thinkFlags; // r10

  if ( activator != nullptr )
    this->activator.spawnId.value = (gameLocal->spawnIds.ptr[activator->entityNumber] << 13) | activator->entityNumber;
  else
    this->activator.spawnId.value = 0x1FFF;
  v3 = idAccolade::Count(this: &clientGame->gameTimeManager);
  thinkFlags = this->thinkFlags;
  this->lastTouchTime = v3;
  if ( (thinkFlags & 1) == 0 )
    idEntity::BecomeActive(this, flags: 1);
}


// ========================================================================
// ?Think@idTrigger_Exit@@UAAXXZ
// EA  : 0x82CF1DD0
// RVA : 0x00CF1DD0
// PDB : w:\tech5\tungsten\game\entities\trigger.cpp
// ========================================================================

void __fastcall idTrigger_Exit::Think(idTrigger_Exit *this)
{
  int value; // r9
  idEntity *v3; // r3
  idEntity *v4; // r4

  if ( idAccolade::Count(this: &clientGame->gameTimeManager) - this->lastTouchTime > 0 )
  {
    idEntity::BecomeInactive(this, flags: 1);
    value = this->activator.spawnId.value;
    if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
      && (v3 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
    {
      v4 = idEntity::CastTo(c: v3);
    }
    else
    {
      v4 = nullptr;
    }
    idTrigger::OnActivate(this, activator: v4);
  }
}


// ========================================================================
// ??0idTrigger_OpenDoor@@QAA@XZ
// EA  : 0x82CF1E80
// RVA : 0x00CF1E80
// PDB : w:\tech5\tungsten\game\entities\trigger.cpp
// ========================================================================

idTrigger_OpenDoor *__fastcall idTrigger_OpenDoor::idTrigger_OpenDoor(idTrigger_OpenDoor *this)
{
  idTrigger::idTrigger(this);
  this->__vftable = (idTrigger_OpenDoor_vtbl *)&idTrigger_OpenDoor::`vftable';
  this->doors.list = nullptr;
  this->doors.granularity = 0;
  this->doors.memTag = 5;
  this->doors.listStatic = 0;
  this->doors.size = 0;
  this->doors.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->doors);
  return this;
}


// ========================================================================
// __unwind$500542
// EA  : 0x82CF1EF4
// RVA : 0x00CF1EF4
// PDB : w:\tech5\tungsten\game\entities\trigger.cpp
// ========================================================================

void _unwind_500542()
{
  int v0; // r12

  idTrigger::~idTrigger(this: *(idTrigger **)(v0 - 112 + 132));
}


// ========================================================================
// ?Event_Touch@idTrigger_OpenDoor@@QAA?AVeventVoid@@PAVidEntity@@H@Z
// EA  : 0x82CF1F98
// RVA : 0x00CF1F98
// PDB : w:\tech5\tungsten\game\entities\trigger.cpp
// ========================================================================

idTrigger_OpenDoor *__fastcall idTrigger_OpenDoor::Event_Touch(
        idTrigger_OpenDoor *this,
        idEntity *result,
        idVehicle *other,
        int clipModelId)
{
  int num; // r29
  int v9; // r30
  int value; // r9
  idDoor_Base *v11; // r3
  idDoor_Base *v12; // r3
  idDoor_Base *v13; // r31

  if ( ((unsigned __int8 (__fastcall *)(idEntity *, idVehicle *))result->__vftable[1].GetType)(a1: result, a2: other) != 0 )
  {
    num = result[1].targets.num;
    if ( num != 0 )
    {
      v9 = num;
      do
      {
        --v9;
        --num;
        value = result[1].targets.list[v9].spawnId.value;
        if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
        {
          v11 = (idDoor_Base *)gameLocal->entities.ptr[value & 0x1FFF];
          if ( v11 != nullptr )
          {
            v12 = idDoor_Base::CastTo(c: v11);
            v13 = v12;
            if ( v12 != nullptr && v12->state == DOOR_CLOSED && !v12->IsLockedForEntity(this: v12, a2: other, a3: 0.0) )
              v13->Use(this: v13, a2: other, a3: USABLE_DOOR);
          }
        }
      }
      while ( num != 0 );
    }
    idTrigger::Event_Touch(this, result, other, clipModelId);
  }
  return this;
}


// ========================================================================
// ?Event_Touch@idTrigger_TurretFireArea@@QAA?AVeventVoid@@PAVidEntity@@H@Z
// EA  : 0x82CF20C8
// RVA : 0x00CF20C8
// PDB : w:\tech5\tungsten\game\entities\trigger.cpp
// ========================================================================

idTrigger_TurretFireArea *__fastcall idTrigger_TurretFireArea::Event_Touch(
        idTrigger_TurretFireArea *this,
        eventVoid *result,
        idEntity *other,
        int clipModelId)
{
  eventVoid *v5; // r30
  int v6; // r28
  int v7; // r31
  int v8; // r9
  idEntity *v9; // r3
  idTurret *v10; // r3
  idTurret *v11; // r3

  v5 = result + 96;
  v6 = 0;
  if ( *(int *)&result[100] > 0 )
  {
    v7 = 0;
    do
    {
      v8 = *(_DWORD *)(*(_DWORD *)v5 + v7);
      if ( gameLocal->spawnIds.ptr[v8 & 0x1FFF] == v8 >> 13 && (v9 = gameLocal->entities.ptr[v8 & 0x1FFF]) != nullptr )
        v10 = (idTurret *)idEntity::CastTo(c: v9);
      else
        v10 = nullptr;
      v11 = idTurret::CastTo(c: v10);
      if ( v11 != nullptr )
        v11->allowedToFire = true;
      ++v6;
      v7 += 4;
    }
    while ( v6 < *(_DWORD *)&v5[4] );
  }
  return this;
}


// ========================================================================
// ?Event_Untouch@idTrigger_TurretFireArea@@QAA?AVeventVoid@@PAVidEntity@@H@Z
// EA  : 0x82CF2170
// RVA : 0x00CF2170
// PDB : w:\tech5\tungsten\game\entities\trigger.cpp
// ========================================================================

idTrigger_TurretFireArea *__fastcall idTrigger_TurretFireArea::Event_Untouch(
        idTrigger_TurretFireArea *this,
        eventVoid *result,
        idEntity *other,
        int clipModelId)
{
  eventVoid *v5; // r30
  int v6; // r29
  int v7; // r31
  int v8; // r9
  idEntity *v9; // r3
  idTurret *v10; // r3
  idTurret *v11; // r3

  v5 = result + 96;
  v6 = 0;
  if ( *(int *)&result[100] > 0 )
  {
    v7 = 0;
    do
    {
      v8 = *(_DWORD *)(*(_DWORD *)v5 + v7);
      if ( gameLocal->spawnIds.ptr[v8 & 0x1FFF] == v8 >> 13 && (v9 = gameLocal->entities.ptr[v8 & 0x1FFF]) != nullptr )
        v10 = (idTurret *)idEntity::CastTo(c: v9);
      else
        v10 = nullptr;
      v11 = idTurret::CastTo(c: v10);
      if ( v11 != nullptr )
        v11->allowedToFire = false;
      ++v6;
      v7 += 4;
    }
    while ( v6 < *(_DWORD *)&v5[4] );
  }
  return this;
}


// ========================================================================
// ?Think@idTrigger_BoostPad@@UAAXXZ
// EA  : 0x82CF2278
// RVA : 0x00CF2278
// PDB : w:\tech5\tungsten\game\entities\trigger.cpp
// ========================================================================

void __fastcall idTrigger_BoostPad::Think(idTrigger_BoostPad *this)
{
  idPresentable *presentable; // r30
  idPresentable_vtbl *v3; // r29
  const idMat3 *FXAxis; // r28
  const idVec3 *FXOrigin; // r3

  idEntity::RunPhysics(this);
  presentable = this->presentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    presentable = this->presentable;
  }
  v3 = presentable->__vftable;
  FXAxis = idMultiplayerTrigger_BoostPad::GetFXAxis((idMultiplayerTrigger_BoostPad *)this);
  FXOrigin = idTrigger_BoostPad::GetFXOrigin((idMultiplayerTrigger_BoostPad *)this);
  v3->UpdateFX_2(this: presentable, a2: FXOrigin, a3: FXAxis);
}


// ========================================================================
// ?BoostPadActivateFX@idTrigger_BoostPad@@QBAXXZ
// EA  : 0x82CF22E0
// RVA : 0x00CF22E0
// PDB : w:\tech5\tungsten\game\entities\trigger.cpp
// ========================================================================

void __fastcall idTrigger_BoostPad::BoostPadActivateFX(idTrigger_BoostPad *this)
{
  int GameMs; // r29
  idPresentable *presentable; // r30
  const idMat3 *FXAxis; // r28
  const idVec3 *FXOrigin; // r3

  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  if ( this->presentable == nullptr )
    idEntity::InitPresentableInternal(this);
  presentable = this->presentable;
  FXAxis = idMultiplayerTrigger_BoostPad::GetFXAxis((idMultiplayerTrigger_BoostPad *)this);
  FXOrigin = idTrigger_BoostPad::GetFXOrigin((idMultiplayerTrigger_BoostPad *)this);
  idFXManager::StartFX(this: &presentable->fxManager, org: FXOrigin, axis: FXAxis, time: GameMs, startCondition: 9);
}


// ========================================================================
// ??0idTrigger_AIGroupsExit@@QAA@XZ
// EA  : 0x82CF2368
// RVA : 0x00CF2368
// PDB : w:\tech5\tungsten\game\entities\trigger.cpp
// ========================================================================

idTrigger_AIGroupsExit *__fastcall idTrigger_AIGroupsExit::idTrigger_AIGroupsExit(idTrigger_AIGroupsExit *this)
{
  idTrigger::idTrigger(this);
  this->activator.spawnId.value = 0x1FFF;
  this->lastTouchTime = 0;
  this->__vftable = (idTrigger_AIGroupsExit_vtbl *)&idTrigger_AIGroupsExit::`vftable';
  this->groupHandles.list = nullptr;
  this->groupHandles.granularity = 0;
  this->groupHandles.memTag = 5;
  this->groupHandles.listStatic = 0;
  this->groupHandles.size = 0;
  this->groupHandles.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->groupHandles);
  this->groups.granularity = 0;
  this->groups.memTag = 5;
  this->groups.listStatic = 0;
  this->groups.list = nullptr;
  this->groups.size = 0;
  this->groups.num = 0;
  return this;
}


// ========================================================================
// __unwind$501027
// EA  : 0x82CF23F8
// RVA : 0x00CF23F8
// PDB : w:\tech5\tungsten\game\entities\trigger.cpp
// ========================================================================

void _unwind_501027()
{
  int v0; // r12

  idTrigger_Exit::~idTrigger_Exit(this: *(idTrigger_Exit **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$501028
// EA  : 0x82CF2420
// RVA : 0x00CF2420
// PDB : w:\tech5\tungsten\game\entities\trigger.cpp
// ========================================================================

void _unwind_501028()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 904));
}


// ========================================================================
// ?ExportTriggers_f@idTrigger@@SAXABVidCmdArgs@@@Z
// EA  : 0x82CF26F0
// RVA : 0x00CF26F0
// PDB : w:\tech5\tungsten\game\entities\trigger.cpp
// ========================================================================

void __fastcall idTrigger::ExportTriggers_f(const idCmdArgs *args)
{
  idFile *v1; // r30
  idLinkList<idEntity> *next; // r11
  idTrigger *owner; // r28
  int num; // r29
  idPhysics *Physics; // r3
  idTrigger *v6; // r3
  int v7; // r10
  encounterGroupRole_t *list; // r11
  idLinkList<idEntity> *v9; // r11
  int GameMs; // r3
  encounterGroupRole_t v11; // r29
  int v12; // r11
  const char *v13; // r5
  idEventDef **v14; // r28
  idEventDef *v15; // r10
  idEntity *v16; // r3
  int v17; // r9
  idEventDef *v18; // r11
  idEntity *v19; // r3
  idEntity *v20; // r3
  const idDeclEntityDef *entityDef; // r10
  const char *str; // r28
  int v23; // r9
  idEntity *v24; // r3
  idEntity *v25; // r3
  idTrigger *v26; // r5
  const char *v27; // r3
  encounterGroupRole_t *v28; // [sp+54h] [-ECh]
  idTrigger *v29; // [sp+58h] [-E8h] BYREF
  const char *v30; // [sp+5Ch] [-E4h]
  const char *v31; // [sp+60h] [-E0h]
  idEventDef **v32; // [sp+64h] [-DCh]
  const char *v33; // [sp+68h] [-D8h]
  const char *v34; // [sp+6Ch] [-D4h]
  idList<enum encounterGroupRole_t,5> v35; // [sp+70h] [-D0h] BYREF
  idStr v36[6]; // [sp+80h] [-C0h] BYREF

  idStr::idStr(this: v36, text: "triggers.txt");
  v1 = fileSystem->OpenFileWrite(this: fileSystem, a2: v36[0].data, a3: 2);
  if ( v1 != nullptr )
  {
    memset(&v35, 0, 14);
    *(_WORD *)&v35.memTag = 1280;
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v35);
    v32 = &idEventDef::eventDefList[3154];
    next = gameLocal->spawnedEntities.next;
    if ( next != nullptr && next != gameLocal->spawnedEntities.head && (owner = (idTrigger *)next->owner) != nullptr )
    {
      num = v35.num;
      do
      {
        Physics = idEntity::GetPhysics(this: owner);
        if ( (Physics->GetContents(this: Physics, a2: -1) & 0x4000) != 0 )
        {
          v6 = idTrigger::CastTo(c: owner);
          v29 = v6;
          if ( v6 != nullptr )
          {
            v7 = 0;
            if ( num <= 0 )
              goto LABEL_14;
            list = v35.list;
            while ( *(idTrigger **)list != v6 )
            {
              ++v7;
              ++list;
              if ( v7 >= num )
                goto LABEL_14;
            }
            if ( v7 < 0 )
            {
LABEL_14:
              idList<idAnimWebBlendTree *,5>::Append(this: &v35, obj: (encounterGroupRole_t *)&v29);
              num = v35.num;
            }
          }
        }
        v9 = owner->spawnNode.next;
        if ( v9 == nullptr )
          break;
        if ( v9 == owner->spawnNode.head )
          break;
        owner = (idTrigger *)v9->owner;
      }
      while ( owner != nullptr );
    }
    else
    {
      num = v35.num;
    }
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    v1->Printf(this: v1, a2: "clientGame time: %d\n", GameMs);
    v1->Printf(this: v1, a2: "triggers: %d\n\n", num);
    if ( num > 0 )
    {
      v29 = (idTrigger *)num;
      v28 = v35.list;
      v30 = "\t\tcall: %s";
      v34 = "\t\tplayerCanActivate: %d\n";
      v33 = "\t\ttriggerFirst: %d\n";
      v31 = "\t\tuserData: %s";
      do
      {
        v11 = *v28;
        v1->Printf(this: v1, a2: "\t%s\n", *(_DWORD *)(*v28 + 16));
        v12 = *(_DWORD *)(v11 + 496);
        v13 = "*unknown*";
        if ( v12 != 0 )
          v13 = *(const char **)(v12 + 8);
        v1->Printf(this: v1, a2: "\t\t%s\n", v13);
        if ( *(_DWORD *)(v11 + 812) != 0 )
          v1->Printf(this: v1, a2: v30, *(_DWORD *)(v11 + 816));
        if ( *(_DWORD *)(v11 + 844) != 0 )
          v1->Printf(this: v1, a2: v31, *(_DWORD *)(v11 + 848));
        v14 = v32;
        v15 = v32[5128];
        if ( *((_DWORD *)&v15[2705].name + (*(_DWORD *)(v11 + 876) & 0x1FFF)) == *(int *)(v11 + 876) >> 13 )
        {
          v16 = *((idEntity **)&v15[1960].argNames + (*(_DWORD *)(v11 + 876) & 0x1FFF));
          if ( v16 != nullptr && idEntity::CastTo(c: v16) != nullptr )
          {
            v17 = *(_DWORD *)(v11 + 876);
            v18 = v14[5128];
            if ( *((_DWORD *)&v18[2705].name + (v17 & 0x1FFF)) == v17 >> 13
              && (v19 = *((idEntity **)&v18[1960].argNames + (v17 & 0x1FFF))) != nullptr )
            {
              v20 = idEntity::CastTo(c: v19);
              v18 = v14[5128];
            }
            else
            {
              v20 = nullptr;
            }
            entityDef = v20->entityDef;
            str = "*unknown*";
            if ( entityDef != nullptr )
              str = entityDef->name.str;
            v23 = *(_DWORD *)(v11 + 876);
            if ( *((_DWORD *)&v18[2705].name + (v23 & 0x1FFF)) == v23 >> 13
              && (v24 = *((idEntity **)&v18[1960].argNames + (v23 & 0x1FFF))) != nullptr )
            {
              v25 = idEntity::CastTo(c: v24);
            }
            else
            {
              v25 = nullptr;
            }
            v1->Printf(this: v1, a2: "\t\tentityCanActivate: %s:%s", v25->name.data, str);
          }
        }
        v1->Printf(this: v1, a2: "\t\twait: %f\n", (unsigned int)COERCE_UNSIGNED_INT64(*(float *)(v11 + 800)));
        v1->Printf(this: v1, a2: "\t\tdelay: %f\n", (unsigned int)COERCE_UNSIGNED_INT64(*(float *)(v11 + 804)));
        v1->Printf(this: v1, a2: "\t\ttriggerOnce: %d\n", *(unsigned __int8 *)(v11 + 808));
        v1->Printf(this: v1, a2: v33, *(unsigned __int8 *)(v11 + 809));
        v1->Printf(this: v1, a2: v34, *(unsigned __int8 *)(v11 + 880));
        v1->Printf(this: v1, a2: "\t\tplayerVehicleCanActivate: %d\n", *(unsigned __int8 *)(v11 + 881));
        v1->Printf(this: v1, a2: "\t\tvehicleOccupantCanActivate: %d\n", *(unsigned __int8 *)(v11 + 882));
        v1->Printf(this: v1, a2: "\t\tanyVehicleCanActivate: %d\n", *(unsigned __int8 *)(v11 + 883));
        v1->Printf(this: v1, a2: "\t\taiCanActivate: %d\n", *(unsigned __int8 *)(v11 + 884));
        v1->Printf(this: v1, a2: "\t\tnextTriggerTime: %d\n", *(_DWORD *)(v11 + 888));
        v1->Printf(this: v1, a2: "\t\textraContents: %d\n", *(_DWORD *)(v11 + 892));
        v1->Printf(this: v1, a2: "\n");
        v26 = v29;
        ++v28;
        v29 = (idTrigger *)((char *)v29 - 1);
      }
      while ( v26 != (idTrigger *)1 );
    }
    v27 = v1->GetFullPath(this: v1);
    idLib::Printf(fmt: "Done writing %s.\n", v27);
    ((void (__fastcall *)(idFile *, int))v1->dtr_idFile)(a1: v1, a2: 1);
    if ( (v35.listStatic == 0 || v35.listStatic == 2) && v35.list != nullptr )
      idMem::Free(this: &mem, ptr: v35.list, align: ALIGN_16);
  }
  idStr::FreeData(this: v36);
}


// ========================================================================
// __unwind$501265
// EA  : 0x82CF2CF8
// RVA : 0x00CF2CF8
// PDB : w:\tech5\tungsten\game\entities\trigger.cpp
// ========================================================================

void _unwind_501265()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 320 + 128));
}


// ========================================================================
// __unwind$501266
// EA  : 0x82CF2D20
// RVA : 0x00CF2D20
// PDB : w:\tech5\tungsten\game\entities\trigger.cpp
// ========================================================================

void _unwind_501266()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 320 + 112));
}


// ========================================================================
// ?exportTriggers_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82CF2D48
// RVA : 0x00CF2D48
// PDB : w:\tech5\tungsten\game\entities\trigger.cpp
// ========================================================================

// attributes: thunk
void __fastcall exportTriggers_f(const idCmdArgs *args)
{
  idTrigger::ExportTriggers_f(args);
}


// ========================================================================
// ?Boost@idTrigger_BoostPad@@QBAXAAVidVehicle_Car@@ABVidVec3@@@Z
// EA  : 0x82CF2D50
// RVA : 0x00CF2D50
// PDB : w:\tech5\tungsten\game\entities\trigger.cpp
// ========================================================================

void __fastcall idTrigger_BoostPad::Boost(idTrigger_BoostPad *this, idVehicle_Car *car, const idVec3 *pushVelocity)
{
  idPhysics *Physics; // r3
  idPhysics *v7; // r31
  const idVec3 *v8; // r27
  int v9; // r3
  idPhysics_vtbl *v10; // r11
  const idMat3 *v11; // r26
  double x; // fp31
  double y; // fp30
  double z; // fp29
  double v15; // fp1
  int GameMs; // r3
  idPresentable *presentable; // r11
  int v18; // r31
  float v19[4]; // [sp+50h] [-70h] BYREF
  float v20[4]; // [sp+60h] [-60h] BYREF

  Physics = idEntity::GetPhysics(this: car);
  v7 = Physics;
  if ( Physics != nullptr )
  {
    v8 = Physics->GetOrigin(this: Physics, a2: 0);
    v9 = (int)v7->GetAxis(this: v7, a2: 0);
    v10 = v7->__vftable;
    v11 = (const idMat3 *)v9;
    if ( __fabs((float)(this->targetFraction - (float)1.0)) > 0.00000011920929 )
    {
      v10->GetLinearVelocity(this: (idPhysics *)v19, result: (idVec3 *)v7, a3: 0);
      x = (float)((float)(pushVelocity->x - v19[0]) * this->targetFraction);
      y = (float)((float)(pushVelocity->y - v19[1]) * this->targetFraction);
      z = (float)((float)(pushVelocity->z - v19[2]) * this->targetFraction);
    }
    else
    {
      v10->PutToRest(this: v7);
      x = pushVelocity->x;
      y = pushVelocity->y;
      z = pushVelocity->z;
    }
    v15 = ((double (__fastcall *)(idPhysics *, int))v7->GetMass)(a1: v7, a2: -1);
    v20[0] = (float)x * (float)v15;
    v20[1] = (float)y * (float)v15;
    v20[2] = (float)z * (float)v15;
    v7->ApplyImpulse(this: v7, a2: 0, a3: v8, a4: (const idVec3 *)v20);
    idVehicle_Car::ActivateBoost(this: car, time: this->time);
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    presentable = car->presentable;
    v18 = GameMs;
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this: car);
      presentable = car->presentable;
    }
    idFXManager::StartFX(this: &presentable->fxManager, org: v8, axis: v11, time: v18, startCondition: 9);
    idTrigger_BoostPad::BoostPadActivateFX(this);
  }
}


// ========================================================================
// ?Spawn@idTrigger_AIGroupsExit@@QAAXXZ
// EA  : 0x82CF2F78
// RVA : 0x00CF2F78
// PDB : w:\tech5\tungsten\game\entities\trigger.cpp
// ========================================================================

void __fastcall idTrigger_AIGroupsExit::Spawn(idTrigger_AIGroupsExit *this)
{
  int num; // r4
  idList<idHandle<short,enum invalidEncounterGroup_t,-1>,5> *p_groupHandles; // r28
  idEncounterGroupManager *p_encounterGroupManager; // r27
  int v5; // r29
  int v6; // r31
  idEncounterGroupManager v7; // [sp+50h] [-40h] BYREF

  num = this->groups.num;
  p_groupHandles = &this->groupHandles;
  p_encounterGroupManager = &gameLocal->encounterGroupManager;
  if ( num > this->groupHandles.size )
    idList<idIndex<short,enum idDeclAnimWeb::invalidEdgeIndex_t>,5>::Resize(
      this: (idList<idIndex<short,enum invalidUserChannelIndex_t>,5> *)&this->groupHandles,
      newsize: num);
  v5 = 0;
  if ( this->groups.num > 0 )
  {
    v6 = 0;
    do
    {
      idEncounterGroupManager::AddGroup(
        this: &v7,
        result: p_encounterGroupManager,
        groupName: this->groups.list[v6].data);
      idList<idIndex<short,enum invalidUserChannelIndex_t>,5>::Append(
        this: (idList<idIndex<short,enum invalidUserChannelIndex_t>,5> *)p_groupHandles,
        obj: (const idIndex<short,enum invalidUserChannelIndex_t> *)&v7);
      ++v5;
      ++v6;
    }
    while ( v5 < this->groups.num );
  }
}


// ========================================================================
// ??0idTrigger_TestPlayerState@@QAA@XZ
// EA  : 0x82CF3010
// RVA : 0x00CF3010
// PDB : w:\tech5\tungsten\game\entities\trigger.cpp
// ========================================================================

idTrigger_TestPlayerState *__fastcall idTrigger_TestPlayerState::idTrigger_TestPlayerState(
        idTrigger_TestPlayerState *this)
{
  idTrigger::idTrigger(this);
  this->__vftable = (idTrigger_TestPlayerState_vtbl *)&idTrigger_TestPlayerState::`vftable';
  this->requiredItemList.list = nullptr;
  this->requiredItemList.granularity = 0;
  this->requiredItemList.memTag = 5;
  this->requiredItemList.listStatic = 0;
  this->requiredItemList.size = 0;
  this->requiredItemList.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->requiredItemList);
  this->requiredJobsList.granularity = 0;
  this->requiredJobsList.memTag = 5;
  this->requiredJobsList.listStatic = 0;
  this->requiredJobsList.list = nullptr;
  this->requiredJobsList.size = 0;
  this->requiredJobsList.num = 0;
  this->requiredGameStateIntList.list = nullptr;
  this->requiredGameStateIntList.granularity = 0;
  this->requiredGameStateIntList.memTag = 5;
  this->requiredGameStateIntList.listStatic = 0;
  this->requiredGameStateIntList.size = 0;
  this->requiredGameStateIntList.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->requiredGameStateIntList);
  this->requiredDLCStateList.list = nullptr;
  this->requiredDLCStateList.granularity = 0;
  this->requiredDLCStateList.memTag = 5;
  this->requiredDLCStateList.listStatic = 0;
  this->requiredDLCStateList.size = 0;
  this->requiredDLCStateList.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->requiredDLCStateList);
  this->anyItemActivates = false;
  this->fireOnInventoryFail = false;
  this->anyJobActivates = false;
  this->fireOnJobFail = false;
  this->anyGameStateIntActivate = false;
  this->fireOnGameStateFail = false;
  this->givenGameStateInt = nullptr;
  this->fireOnDLCStateFail = false;
  this->vehicleClassTest = VEHICLE_CLASSNONE;
  return this;
}


// ========================================================================
// __unwind$501868
// EA  : 0x82CF30F0
// RVA : 0x00CF30F0
// PDB : w:\tech5\tungsten\game\entities\trigger.cpp
// ========================================================================

void _unwind_501868()
{
  int v0; // r12

  idTrigger::~idTrigger(this: *(idTrigger **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$501869
// EA  : 0x82CF3118
// RVA : 0x00CF3118
// PDB : w:\tech5\tungsten\game\entities\trigger.cpp
// ========================================================================

void _unwind_501869()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 896));
}


// ========================================================================
// __unwind$501870
// EA  : 0x82CF3144
// RVA : 0x00CF3144
// PDB : w:\tech5\tungsten\game\entities\trigger.cpp
// ========================================================================

void _unwind_501870()
{
  int v0; // r12

  idList<idDeclSpecialEvent_Area::jobStinger_t,5>::~idList<idDeclSpecialEvent_Area::jobStinger_t,5>(this: (idList<idDeclPonytail::idPonytailJointInfo,30> *)(*(_DWORD *)(v0 - 128 + 148) + 916));
}


// ========================================================================
// __unwind$501871
// EA  : 0x82CF3170
// RVA : 0x00CF3170
// PDB : w:\tech5\tungsten\game\entities\trigger.cpp
// ========================================================================

void _unwind_501871()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 936));
}


// ========================================================================
// ?BoostToTarget@idTrigger_BoostPad@@QBAXAAVidVehicle_Car@@AAVidEntity@@@Z
// EA  : 0x82CF32D0
// RVA : 0x00CF32D0
// PDB : w:\tech5\tungsten\game\entities\trigger.cpp
// ========================================================================

void __fastcall idTrigger_BoostPad::BoostToTarget(idTrigger_BoostPad *this, idVehicle_Car *car, idEntity *target)
{
  idPhysics *Physics; // r31
  idPhysics *v7; // r3
  idPhysics *v8; // r29
  float *v9; // r27
  float *v10; // r3
  double v11; // fp31
  double v12; // fp30
  double v13; // fp29
  double v14; // fp25
  float *v15; // r31
  float *v16; // r3
  double v17; // fp6
  double v18; // fp26
  double v19; // fp28
  double v20; // fp27
  double v21; // fp0
  double v22; // fp13
  double v23; // fp12
  double v24; // fp10
  double v25; // fp9
  double v26; // fp5
  idVec3 v27[6]; // [sp+50h] [-80h] BYREF

  Physics = idEntity::GetPhysics(this: car);
  v7 = idEntity::GetPhysics(this: target);
  v8 = v7;
  if ( Physics != nullptr && v7 != nullptr )
  {
    v9 = (float *)Physics->GetGravity(this: Physics);
    v10 = (float *)Physics->GetGravityNormal(this: Physics);
    v11 = -*v10;
    v12 = -v10[1];
    v13 = -v10[2];
    v14 = (float)((float)(v9[2] * v9[2]) + (float)((float)(*v9 * *v9) + (float)(v9[1] * v9[1])));
    v15 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
    v16 = (float *)v8->GetOrigin(this: v8, a2: 0);
    v17 = v15[1];
    v18 = (float)(v16[2] - v15[2]);
    v19 = (float)(*v16 - *v15);
    v27[0].z = v16[2] - v15[2];
    v27[0].x = v19;
    v20 = (float)(v16[1] - (float)v17);
    v27[0].y = v16[1] - (float)v17;
    idVec3::NormalizeFast(this: v27);
    v21 = (float)((float)(this->boostUpDir.x * (float)v11)
                + (float)((float)(this->boostUpDir.y * (float)v12) + (float)(this->boostUpDir.z * (float)v13)));
    v22 = (float)(v27[0].y
                - (float)((float)v12
                        * (float)((float)((float)v11 * v27[0].x)
                                + (float)((float)(v27[0].y * (float)v12) + (float)(v27[0].z * (float)v13)))));
    v23 = (float)(v27[0].z
                - (float)((float)((float)((float)v11 * v27[0].x)
                                + (float)((float)(v27[0].y * (float)v12) + (float)(v27[0].z * (float)v13)))
                        * (float)v13));
    v24 = (float)((float)((float)(v27[0].x
                                - (float)((float)v11
                                        * (float)((float)((float)v11 * v27[0].x)
                                                + (float)((float)(v27[0].y * (float)v12) + (float)(v27[0].z * (float)v13)))))
                        * (float)v19)
                + (float)((float)((float)(v27[0].z
                                        - (float)((float)((float)((float)v11 * v27[0].x)
                                                        + (float)((float)(v27[0].y * (float)v12)
                                                                + (float)(v27[0].z * (float)v13)))
                                                * (float)v13))
                                * (float)v18)
                        + (float)((float)(v27[0].y
                                        - (float)((float)v12
                                                * (float)((float)((float)v11 * v27[0].x)
                                                        + (float)((float)(v27[0].y * (float)v12)
                                                                + (float)(v27[0].z * (float)v13)))))
                                * (float)v20)));
    v25 = (float)((float)((float)((float)((float)((float)(v27[0].x
                                                        - (float)((float)v11
                                                                * (float)((float)((float)v11 * v27[0].x)
                                                                        + (float)((float)(v27[0].y * (float)v12)
                                                                                + (float)(v27[0].z * (float)v13)))))
                                                * (float)v19)
                                        + (float)((float)((float)(v27[0].z
                                                                - (float)((float)((float)((float)v11 * v27[0].x)
                                                                                + (float)((float)(v27[0].y * (float)v12)
                                                                                        + (float)(v27[0].z * (float)v13)))
                                                                        * (float)v13))
                                                        * (float)v18)
                                                + (float)((float)(v27[0].y
                                                                - (float)((float)v12
                                                                        * (float)((float)((float)v11 * v27[0].x)
                                                                                + (float)((float)(v27[0].y * (float)v12)
                                                                                        + (float)(v27[0].z * (float)v13)))))
                                                        * (float)v20)))
                                * (float)((float)(this->boostUpDir.x * (float)v11)
                                        + (float)((float)(this->boostUpDir.y * (float)v12)
                                                + (float)(this->boostUpDir.z * (float)v13))))
                        - (float)((float)((float)v18 * (float)v13)
                                + (float)((float)((float)v20 * (float)v12) + (float)((float)v19 * (float)v11))))
                / (float)((float)__fsqrts(v14) * (float)0.5));
    if ( v25 > 0.0 )
    {
      v26 = __fsqrts(v25);
      v27[0].x = (float)((float)((float)v11
                               * (float)((float)(this->boostUpDir.x * (float)v11)
                                       + (float)((float)(this->boostUpDir.y * (float)v12)
                                               + (float)(this->boostUpDir.z * (float)v13))))
                       + (float)(v27[0].x
                               - (float)((float)v11
                                       * (float)((float)((float)v11 * v27[0].x)
                                               + (float)((float)(v27[0].y * (float)v12) + (float)(v27[0].z * (float)v13))))))
               * (float)((float)((float)((float)(v27[0].x
                                               - (float)((float)v11
                                                       * (float)((float)((float)v11 * v27[0].x)
                                                               + (float)((float)(v27[0].y * (float)v12)
                                                                       + (float)(v27[0].z * (float)v13)))))
                                       * (float)v19)
                               + (float)((float)((float)(v27[0].z
                                                       - (float)((float)((float)((float)v11 * v27[0].x)
                                                                       + (float)((float)(v27[0].y * (float)v12)
                                                                               + (float)(v27[0].z * (float)v13)))
                                                               * (float)v13))
                                               * (float)v18)
                                       + (float)((float)(v27[0].y
                                                       - (float)((float)v12
                                                               * (float)((float)((float)v11 * v27[0].x)
                                                                       + (float)((float)(v27[0].y * (float)v12)
                                                                               + (float)(v27[0].z * (float)v13)))))
                                               * (float)v20)))
                       / (float)v26);
      v27[0].y = (float)((float)((float)v12 * (float)v21) + (float)v22) * (float)((float)v24 / (float)v26);
      v27[0].z = (float)((float)((float)v13 * (float)v21) + (float)v23) * (float)((float)v24 / (float)v26);
      idTrigger_BoostPad::Boost(this, car, pushVelocity: v27);
    }
  }
}


// ========================================================================
// ??0idTrigger_VehicleAI@@QAA@XZ
// EA  : 0x82CF3548
// RVA : 0x00CF3548
// PDB : w:\tech5\tungsten\game\entities\trigger.cpp
// ========================================================================

idTrigger_VehicleAI *__fastcall idTrigger_VehicleAI::idTrigger_VehicleAI(idTrigger_VehicleAI *this)
{
  idTrigger::idTrigger(this);
  this->__vftable = (idTrigger_VehicleAI_vtbl *)&idTrigger_VehicleAI::`vftable';
  this->overrideControl.avoidanceType = OAT_INIT;
  this->overrideControl.powerTurnTime = -1;
  this->overrideControl.speedLimit = -1.0;
  this->overrideControl.stopDistance = -1.0;
  this->overrideControl.moveDistance = -1.0;
  this->overrideControl.decelDistance = -1.0;
  this->overrideControl.maxCurveSpeed = -1.0;
  this->overrideControl.maxCurveAngle = -1.0;
  this->overrideControl.maxStepAngle = -1.0;
  this->overrideControl.powerTurnSpeed = -1.0;
  this->overrideControl.stopPowerTurnSpeed = -1.0;
  this->overrideControl.traversalStepSize = -1.0;
  this->overrideControl.backupSpeed = -1.0;
  this->overrideControl.maxCurveCosine = -1.0;
  this->overrideControl.maxStepCosine = -1.0;
  this->overrideTime = -1.0;
  vaiAction_t::vaiAction_t(this: &this->action);
  return this;
}


// ========================================================================
// __unwind$502590
// EA  : 0x82CF35F0
// RVA : 0x00CF35F0
// PDB : w:\tech5\tungsten\game\entities\trigger.cpp
// ========================================================================

void _unwind_502590()
{
  int v0; // r12

  idTrigger::~idTrigger(this: *(idTrigger **)(v0 - 112 + 132));
}


// ========================================================================
// ?Event_Touch@idTrigger_BoostPad@@QAA?AVeventVoid@@PAVidEntity@@H@Z
// EA  : 0x82CF3690
// RVA : 0x00CF3690
// PDB : w:\tech5\tungsten\game\entities\trigger.cpp
// ========================================================================

idTrigger_BoostPad *__fastcall idTrigger_BoostPad::Event_Touch(
        idTrigger_BoostPad *this,
        idTrigger_BoostPad *result,
        idVehicle_Car *other,
        int clipModelId)
{
  idVehicle_Car *v6; // r3
  idVehicle_Car *v7; // r30
  idPresentable *presentable; // r3
  int v9; // r3
  idEntity *Target; // r5
  int v11; // r4

  v6 = idVehicle_Car::CastTo(c: other);
  v7 = v6;
  if ( v6 != nullptr )
  {
    presentable = v6->presentable;
    v9 = presentable != nullptr ? (int)presentable->GetVehicleInterface(this: presentable) : 0;
    if ( __fabs(*(float *)(v9 + 17864)) > result->activationSpeed )
    {
      Target = idEntity::GetTarget(this: result, i: 0);
      if ( Target != nullptr )
      {
        idTrigger_BoostPad::BoostToTarget(this: result, car: v7, target: Target);
        return this;
      }
      idVehicle_Car::ActivateBoostpad(this: v7, acceleration: result->acceleration, time: v11);
      idTrigger_BoostPad::BoostPadActivateFX(this: result);
    }
  }
  return this;
}


// ========================================================================
// ?Spawn@idTrigger_OpenDoor@@QAAXXZ
// EA  : 0x82CF3748
// RVA : 0x00CF3748
// PDB : w:\tech5\tungsten\game\entities\trigger.cpp
// ========================================================================

void __fastcall idTrigger_OpenDoor::Spawn(idTrigger_OpenDoor *this)
{
  int num; // r27
  int v3; // r26
  int value; // r9
  idEntity *v5; // r3
  idDoor_Base *v6; // r31
  idDoor_Base *v7; // r3
  idDoor_Base *v8; // r30
  idEntityPtr<idEntity> v9; // [sp+50h] [-40h] BYREF

  num = this->targets.num;
  if ( num != 0 )
  {
    v3 = num;
    do
    {
      --num;
      --v3;
      if ( num < this->targets.num
        && (value = this->targets.list[v3].spawnId.value, gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13)
        && (v5 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
      {
        v6 = (idDoor_Base *)idEntity::CastTo(c: v5);
      }
      else
      {
        v6 = nullptr;
      }
      v7 = idDoor_Base::CastTo(c: v6);
      v8 = v7;
      if ( v6 == nullptr || v7 != nullptr )
      {
        idEntity::RemoveTargetIndex(this, i: num);
        if ( v8 != nullptr )
        {
          v9.spawnId.value = (gameLocal->spawnIds.ptr[v8->entityNumber] << 13) | v8->entityNumber;
          idList<idEntityPtr<idEntity>,58>::Append(this: (idList<idEntityPtr<idEntity>,58> *)&this->doors, obj: &v9);
        }
      }
    }
    while ( num != 0 );
  }
}


// ========================================================================
// ??0idTrigger_AIInteraction@@QAA@XZ
// EA  : 0x82CF38A0
// RVA : 0x00CF38A0
// PDB : w:\tech5\tungsten\game\entities\trigger.cpp
// ========================================================================

idTrigger_AIInteraction *__fastcall idTrigger_AIInteraction::idTrigger_AIInteraction(idTrigger_AIInteraction *this)
{
  idTrigger::idTrigger(this);
  this->__vftable = (idTrigger_AIInteraction_vtbl *)&idTrigger_AIInteraction::`vftable';
  this->actionScript.granularity = 0;
  this->actionScript.memTag = 5;
  this->actionScript.listStatic = 0;
  this->actionScript.list = nullptr;
  this->actionScript.size = 0;
  this->actionScript.num = 0;
  return this;
}


// ========================================================================
// __unwind$503063
// EA  : 0x82CF3910
// RVA : 0x00CF3910
// PDB : w:\tech5\tungsten\game\entities\trigger.cpp
// ========================================================================

void _unwind_503063()
{
  int v0; // r12

  idTrigger::~idTrigger(this: *(idTrigger **)(v0 - 112 + 132));
}


// ========================================================================
// `dynamic initializer for 'exportTriggers_v''
// EA  : 0x8337A198
// RVA : 0x0137A198
// PDB : w:\tech5\tungsten\game\entities\trigger.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__exportTriggers_v__()
{
  return idCommandLink::idCommandLink(
           this: &exportTriggers_v,
           cmdName: "exportTriggers",
           function: exportTriggers_f,
           description: "export all trigger information to file triggers.txt",
           argCompletion: nullptr);
}

