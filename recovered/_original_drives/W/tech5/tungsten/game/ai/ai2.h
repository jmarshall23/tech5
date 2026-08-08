
// ========================================================================
// ??1idAIScriptProxy@@UAA@XZ
// EA  : 0x8251D1D0
// RVA : 0x0051D1D0
// PDB : w:\tech5\tungsten\game\ai\ai2.h
// ========================================================================

void __fastcall idAIScriptProxy::~idAIScriptProxy(idAIScriptProxy *this)
{
  this->__vftable = (idAIScriptProxy_vtbl *)&idAIScriptProxy::`vftable';
  idEventReceiver::~idEventReceiver(this);
}


// ========================================================================
// ?Event_GetHealth@idAI2@@QAA?AVeventFloat@@XZ
// EA  : 0x8251D248
// RVA : 0x0051D248
// PDB : w:\tech5\tungsten\game\ai\ai2.h
// ========================================================================

idAI2 *__fastcall idAI2::Event_GetHealth(idAI2 *this, eventFloat *result)
{
  double v3; // fp1

  v3 = ((double (__fastcall *)(eventFloat *))*(_DWORD *)(LODWORD(result[15372].value) + 60))(a1: &result[15372]);
  eventFloat::eventFloat((eventFloat *)this, f: v3);
  return this;
}


// ========================================================================
// ??1idAIFSMCallback@@UAA@XZ
// EA  : 0x829F0AE8
// RVA : 0x009F0AE8
// PDB : w:\tech5\tungsten\game\ai\ai2.h
// ========================================================================

void __fastcall idAIFSMCallback::~idAIFSMCallback(idAIFSMCallback *this)
{
  this->__vftable = (idAIFSMCallback_vtbl *)&idAIFSMCallback::`vftable';
  idFSMLog::~idFSMLog(this: &this->log);
  this->__vftable = (idAIFSMCallback_vtbl *)&idFSMCallback::`vftable';
}


// ========================================================================
// __unwind$513386
// EA  : 0x829F0B40
// RVA : 0x009F0B40
// PDB : w:\tech5\tungsten\game\ai\ai2.h
// ========================================================================

void _unwind_513386()
{
  int v0; // r12

  idFSMCallback::~idFSMCallback(this: *(idFSMCallback **)(v0 - 112 + 132));
}


// ========================================================================
// ?SetSubWeb@idAI2@@QAAXW4aiSubWeb_t@@@Z
// EA  : 0x829F0BD0
// RVA : 0x009F0BD0
// PDB : w:\tech5\tungsten\game\ai\ai2.h
// ========================================================================

void __fastcall idAI2::SetSubWeb(idAI2 *this, aiSubWeb_t sw)
{
  idStr v4[2]; // [sp+50h] [-40h] BYREF

  if ( sw == AISUBWEB_HOSTILE )
  {
    v4[0].len = 0;
    v4[0].allocedAndFlag = 20;
    v4[0].data = v4[0].baseBuffer;
    v4[0].baseBuffer[0] = 0;
    idAI2::GetWeaponPrefix(this, subWebPrefix: v4);
    if ( idStr::Find(searchIn: v4[0].data, searchFor: "rifle", casesensitive: true, start: 0, end: -1) == -1 )
    {
      this->aiVolatile.animation.subWeb = AISUBWEB_COMBAT;
      idStr::FreeData(this: v4);
      return;
    }
    idStr::FreeData(this: v4);
  }
  this->aiVolatile.animation.subWeb = sw;
}


// ========================================================================
// __unwind$513719
// EA  : 0x829F0C70
// RVA : 0x009F0C70
// PDB : w:\tech5\tungsten\game\ai\ai2.h
// ========================================================================

void _unwind_513719()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 144 + 80));
}


// ========================================================================
// ?Init@idAIActionSettings@idAIEditable@@QAAXXZ
// EA  : 0x829F5F60
// RVA : 0x009F5F60
// PDB : w:\tech5\tungsten\game\ai\ai2.h
// ========================================================================

void __fastcall idAIEditable::idAIActionSettings::Init(idAIEditable::idAIActionSettings *this, long double a2)
{
  long double v3; // fp2
  long double v4; // fp2
  long double v5; // fp2
  int num; // r11
  double stageHealth; // fp6

  *(double *)&a2 = (float)(idMath::M_DEG2RAD * this->fire.aimAngle);
  v3 = cos(x: a2);
  this->fire.aimDot = *(double *)&v3;
  *(double *)&v3 = (float)((float)(this->fire.aimAngle + (float)10.0) * idMath::M_DEG2RAD);
  v4 = cos(x: v3);
  this->fire.gangstaAimDot = *(double *)&v4;
  *(double *)&v4 = (float)((float)(this->fire.aimAngle + (float)20.0) * idMath::M_DEG2RAD);
  v5 = cos(x: v4);
  num = this->customRobot.stageTriggers.num;
  stageHealth = this->customRobot.stageHealth;
  this->fire.aimDotUpsideDown = *(double *)&v5;
  this->customRobot.curStageHealth = stageHealth;
  this->customRobot.curStage = 0;
  if ( num <= 1 )
    num = 1;
  this->customRobot.numStages = num;
}


// ========================================================================
// ?GetCurrentCombatStage@idAI2@@QBAPBVidCombatStage@@XZ
// EA  : 0x829F6018
// RVA : 0x009F6018
// PDB : w:\tech5\tungsten\game\ai\ai2.h
// ========================================================================

idCombatStage *__fastcall idAI2::GetCurrentCombatStage(idAI2 *this)
{
  idHandle<short,enum invalidEncounterGroup_t,-1> *p_encounterGroupHandle; // r30
  idEncounterGroup *v2; // r3
  int curCombatStage; // r11

  p_encounterGroupHandle = &this->aiVolatile.encounterGroupHandle;
  if ( (unsigned __int16)this->aiVolatile.encounterGroupHandle.value == 0xFFFF
    || idEncounterGroupManager::GroupForHandle(
         this: &gameLocal->encounterGroupManager,
         handle: &this->aiVolatile.encounterGroupHandle) == nullptr )
  {
    return nullptr;
  }
  v2 = (unsigned __int16)p_encounterGroupHandle->value == 0xFFFF
     ? nullptr
     : idEncounterGroupManager::GroupForHandle(this: &gameLocal->encounterGroupManager, handle: p_encounterGroupHandle);
  curCombatStage = v2->curCombatStage;
  if ( curCombatStage < 0 || curCombatStage >= v2->combatStages.num )
    return nullptr;
  else
    return &v2->combatStages.list[curCombatStage];
}


// ========================================================================
// ?DebugColor@idVisibilityObscurity@idAI2@@QBAAAVidColor@@W4obscurityTest_t@12@@Z
// EA  : 0x829F60B8
// RVA : 0x009F60B8
// PDB : w:\tech5\tungsten\game\ai\ai2.h
// ========================================================================

idColor *__fastcall idAI2::idVisibilityObscurity::DebugColor(
        idAI2::idVisibilityObscurity *this,
        const idAI2::idVisibilityObscurity::obscurityTest_t test)
{
  idAI2::idVisibilityObscurity::obscurity_t v2; // r11

  v2 = this->visibilityObscurity.ptr[test];
  if ( v2 <= OBSCURITY_PATH_OPEN_WITH_OBSCURITY )
    return &idColor::colorYellow;
  if ( v2 == OBSCURITY_PATH_OPEN_WITH_COVER )
    return &idColor::colorOrange;
  return &idColor::colorGreen;
}


// ========================================================================
// ??0idAIDeathInfo@@QAA@XZ
// EA  : 0x829FC240
// RVA : 0x009FC240
// PDB : w:\tech5\tungsten\game\ai\ai2.h
// ========================================================================

idAIDeathInfo *__fastcall idAIDeathInfo::idAIDeathInfo(idAIDeathInfo *this)
{
  unsigned __int64 v1; // r11
  int v2; // ctr
  float *p_z; // r7
  idSysMutex *p_viewNoteMutex; // r8

  LODWORD(v1) = 0;
  this->attacker.spawnId.value = 0x1FFF;
  this->inflictor.spawnId.value = 0x1FFF;
  this->impulse.damageDecl = nullptr;
  this->impulse.impactDir.x = 0.0;
  this->impulse.impactDir.y = 0.0;
  HIDWORD(v1) = &this->deathBox;
  this->impulse.impactDir.z = 0.0;
  this->impulse.impactPoint.x = 0.0;
  this->impulse.impactPoint.y = 0.0;
  v2 = 6;
  this->impulse.impactPoint.z = 0.0;
  this->impulse.jointIndex.value = -1;
  this->impulse.damage = 0.0;
  this->impulse.armorPoppedOff = false;
  this->impulse.forceInjured = false;
  p_z = &this->deathBox.offset.z;
  this->startDeathTime = -1;
  p_viewNoteMutex = &analysisClient.viewNoteMutex;
  this->deathCollisionQuery.index = v1;
  this->deathBox.type = TRM_INVALID;
  this->deathBox.numVerts = 0;
  this->deathBox.numEdges = 0;
  this->deathBox.numPolys = 0;
  this->deathBox.maxPolyEdges = 0;
  this->deathBox.offset.x = 0.0;
  this->deathBox.offset.y = 0.0;
  this->deathBox.offset.z = 0.0;
  do
  {
    ++p_viewNoteMutex;
    *++p_z = *(float *)&p_viewNoteMutex->handle;
    --v2;
  }
  while ( v2 != 0 );
  this->deathBox.radius = 0.0;
  this->deathBox.isConvex = false;
  this->deathBox.pad[2] = 0;
  this->deathBox.pad[1] = 0;
  this->deathBox.pad[0] = 0;
  this->deathAnimationNode = nullptr;
  this->deathAnimSubWeb.value = -1;
  this->deathAnimState.value = -1;
  this->deathFlags = DEATH_NONE;
  return this;
}


// ========================================================================
// ??0idCheckSurroundingsState@@QAA@XZ
// EA  : 0x829FC308
// RVA : 0x009FC308
// PDB : w:\tech5\tungsten\game\ai\ai2.h
// ========================================================================

idCheckSurroundingsState *__fastcall idCheckSurroundingsState::idCheckSurroundingsState(idCheckSurroundingsState *this)
{
  float *v1; // r9
  int i; // ctr

  this->lookedAtEntitySpawnIDs.ptr[0].value = 0x1FFF;
  this->lookedAtEntitySpawnIDs.ptr[1].value = 0x1FFF;
  this->lookedAtEntitySpawnIDs.ptr[2].value = 0x1FFF;
  v1 = (float *)&this->distanceExponent.ptr[7];
  this->lookedAtEntitySpawnIDs.ptr[3].value = 0x1FFF;
  this->nextDirectionToTrace = 0;
  this->lookForwardInterest = 100.0;
  for ( i = 8; i != 0; --i )
  {
    *(v1 - 7) = 0.0;
    *++v1 = 0.0;
  }
  this->lookedAtEntitiesTime.ptr[0] = 0;
  this->lookedAtEntitiesTime.ptr[1] = 0;
  this->lookedAtEntitiesTime.ptr[2] = 0;
  this->lookedAtEntitiesTime.ptr[3] = 0;
  return this;
}


// ========================================================================
// ?HasFocus@idAI2@@QBA_NXZ
// EA  : 0x829FC368
// RVA : 0x009FC368
// PDB : w:\tech5\tungsten\game\ai\ai2.h
// ========================================================================

int __fastcall idAI2::HasFocus(idAI2 *this)
{
  char HasFocus; // r3
  unsigned __int8 v3; // r11

  if ( (unsigned __int8)idFocusInfo::HasFocus(this: this->aiVolatile.focus.foci.ptr) != 0 )
    return 1;
  HasFocus = idFocusInfo::HasFocus(this: &this->aiVolatile.focus.foci.ptr[1]);
  v3 = 0;
  if ( HasFocus != 0 )
    return 1;
  return v3;
}


// ========================================================================
// ?GetLookFocusEntity@idAI2@@QBAPBVidEntity@@XZ
// EA  : 0x829FC3C8
// RVA : 0x009FC3C8
// PDB : w:\tech5\tungsten\game\ai\ai2.h
// ========================================================================

const idEntity *__fastcall idAI2::GetLookFocusEntity(idAI2 *this)
{
  int value; // r10
  idEntity *v2; // r3

  value = this->aiVolatile.focus.foci.ptr[1].focusEntity.spawnId.value;
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
// ?GetControllingPlayer@idAI2@@QBAPAVidPlayer@@XZ
// EA  : 0x829FC410
// RVA : 0x009FC410
// PDB : w:\tech5\tungsten\game\ai\ai2.h
// ========================================================================

idPlayer *__fastcall idAI2::GetControllingPlayer(idAI2 *this)
{
  int value; // r8
  idPlayer *v2; // r3

  value = this->aiVolatile.playerControl.player.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v2 = (idPlayer *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    return idPlayer::CastTo(c: v2);
  }
  else
  {
    return nullptr;
  }
}


// ========================================================================
// ?IsPlayerControlled@idAI2@@QBA_NXZ
// EA  : 0x829FC460
// RVA : 0x009FC460
// PDB : w:\tech5\tungsten\game\ai\ai2.h
// ========================================================================

BOOL __fastcall idAI2::IsPlayerControlled(idAI2 *this)
{
  int value; // r8
  idPlayer *v2; // r3

  value = this->aiVolatile.playerControl.player.spawnId.value;
  return gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
      && (v2 = (idPlayer *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr
      && idPlayer::CastTo(c: v2) != nullptr;
}


// ========================================================================
// ?Clear@idAIActionSettings@idAIEditable@@QAAXXZ
// EA  : 0x82A02608
// RVA : 0x00A02608
// PDB : w:\tech5\tungsten\game\ai\ai2.h
// ========================================================================

void __fastcall idAIEditable::idAIActionSettings::Clear(idAIEditable::idAIActionSettings *this, long double a2)
{
  long double v3; // fp2
  long double v4; // fp2

  this->enemyTrailUpdatePeriod = 5.0;
  this->cover.usesClose = true;
  this->cover.usesIdle = true;
  this->cover.usesCombatScenePoints = true;
  this->cover.coverMinRange = 50.0;
  this->cover.scenePointSelectionFlags = SP_SELECT_DEFAULT;
  this->cover.coverMaxRange = 1000.0;
  this->cover.coverFlags = COVER_POPIN_HURT;
  this->cover.coverRandomWeight = 0.1;
  this->search.usesSearchScenePoints = true;
  this->cover.coverHistoryWeight = 1.0;
  this->roam.usesRoamScenePoints = true;
  this->cover.coverVerticalWeight = 1.0;
  this->look.usesLookScenePoints = true;
  this->cover.coverTacticalWeight = 0.25;
  this->cover.coverTargetTimeout = -1.0;
  this->search.searchMinRange = 50.0;
  this->search.searchMaxRange = -1.0;
  this->roam.roamMinRange = 50.0;
  this->roam.roamMaxRange = -1.0;
  this->look.lookMinRange = 50.0;
  this->look.lookMaxRange = -1.0;
  this->fire.gangstaPoseFraction = 0.0;
  this->fire.gangstaDuration = 3.0;
  this->fire.aimAngle = 10.0;
  *(double *)&a2 = (float)(idMath::M_DEG2RAD * (float)10.0);
  v3 = cos(x: a2);
  this->fire.aimDot = *(double *)&v3;
  *(double *)&v3 = (float)((float)(this->fire.aimAngle + (float)10.0) * idMath::M_DEG2RAD);
  v4 = cos(x: v3);
  this->fire.gangstaAimDot = *(double *)&v4;
  this->close.closeMinRange = 0.0;
  this->close.closeMaxRange = -1.0;
  this->close.closeFlags = CLOSE_STOP_ON_SPOT;
  this->dodge.dodgeMinRange = 100.0;
  this->dodge.dodgeFlags = DODGE_ALL;
  this->close.stopOnSpotRange = 500.0;
  this->dodge.dodgeMaxRange = -1.0;
  this->squad.squadLeader.spawnId.value = 0x1FFF;
  this->squad.leaderRange = 200.0;
  this->squad.playerIsLeader = false;
  this->squad.scenePointRange = 500.0;
  this->squad.squadActive = true;
  this->customRobot.frontDamageMultiplier = 0.25;
  this->customRobot.usesRobot = false;
  this->customRobot.rearDamageMultiplier = 1.0;
  this->customRobot.isBoss = true;
  this->customRobot.stageHealth = 300.0;
  this->customRobot.curStageHealth = 300.0;
  this->customRobot.bossHealth = 1.0;
  this->customRobot.chargeHealthFract = 0.15000001;
  this->customRobot.chargeTime = 5.0;
  this->customRobot.shootHealthDrain = 0.0;
  this->customRobot.triggerOnPowerOut.spawnId.value = 0x1FFF;
  this->customRobot.triggerOnChargingDone.spawnId.value = 0x1FFF;
  this->customRobot.frontImpactFX = nullptr;
  this->customRobot.frontImpactSound = nullptr;
  this->customRobot.rearImpactFX = nullptr;
  this->customRobot.rearImpactSound = nullptr;
  this->customRobot.turnfastSound = nullptr;
  this->customRobot.lastBodyDir.x = 1.0;
  this->customRobot.lastBodyDir.y = 0.0;
  this->customRobot.lastBodyDir.z = 0.0;
  this->customRobot.nextTurnfastTime = -1;
  this->customRobot.isCharging = false;
  this->customRobot.curStage = 0;
  this->customRobot.numStages = 1;
  this->customRobot.lastShootTime = -1;
  this->customRobot.chargeStartTime = -1;
  this->customRobot.chargeDoneTime = -1;
  this->customRobot.nextMTSPCheck = -1;
  this->customRobot.immuneDoneTime = -1;
  this->customRobot.noFireTime = -1;
}


// ========================================================================
// ??0idDynamicMerchantSpecialInventoryListDef@idAIEditable@@QAA@XZ
// EA  : 0x82A02800
// RVA : 0x00A02800
// PDB : w:\tech5\tungsten\game\ai\ai2.h
// ========================================================================

idAIEditable::idDynamicMerchantSpecialInventoryListDef *__fastcall idAIEditable::idDynamicMerchantSpecialInventoryListDef::idDynamicMerchantSpecialInventoryListDef(
        idAIEditable::idDynamicMerchantSpecialInventoryListDef *this)
{
  this->discount = 0.69999999;
  this->isDynamicMerchant = false;
  this->refreshDelay = 120.0;
  this->nextGiveTime = -1;
  this->shouldWipeInventoryOnGive = true;
  this->itemList.list = nullptr;
  this->itemList.granularity = 0;
  this->itemList.memTag = 5;
  this->itemList.listStatic = 0;
  this->itemList.size = 0;
  this->itemList.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->itemList);
  return this;
}


// ========================================================================
// ?GetFakeEnemy@idAI2@@QBAPBVidEntity@@XZ
// EA  : 0x82A02880
// RVA : 0x00A02880
// PDB : w:\tech5\tungsten\game\ai\ai2.h
// ========================================================================

const idEntity *__fastcall idAI2::GetFakeEnemy(idAI2 *this)
{
  int value; // r10
  idEntity *v2; // r3

  value = this->aiVolatile.world.fakeEnemy.spawnId.value;
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
// ?GetAASPositionMgr@idAI2@@UBAAAVidAASPositionMgr@@XZ
// EA  : 0x82A25CE0
// RVA : 0x00A25CE0
// PDB : w:\tech5\tungsten\game\ai\ai2.h
// ========================================================================

idAASPositionMgr *__fastcall idAI2::GetAASPositionMgr(idAI2 *this)
{
  return &this->patch1.aasPositionMgr;
}


// ========================================================================
// ?GetHealthComponent@idAI2@@UBAPBVidBaseHealth@@XZ
// EA  : 0x82A25CF0
// RVA : 0x00A25CF0
// PDB : w:\tech5\tungsten\game\ai\ai2.h
// ========================================================================

idAIHealth *__fastcall idAI2::GetHealthComponent(idAI2 *this)
{
  return &this->aiHealth;
}


// ========================================================================
// ?GetComponentTimeLine@idAI2@@UAAPAVidComponentTimeLine@@XZ
// EA  : 0x82A25D00
// RVA : 0x00A25D00
// PDB : w:\tech5\tungsten\game\ai\ai2.h
// ========================================================================

idComponentActionScript *__fastcall idAI2::GetComponentTimeLine(idAI2 *this)
{
  return &this->actionScript;
}


// ========================================================================
// ?GetAnimWebCmdCtx@idAI2@@UAAPAVidAnimWebCmdCtx@@XZ
// EA  : 0x82A25D10
// RVA : 0x00A25D10
// PDB : w:\tech5\tungsten\game\ai\ai2.h
// ========================================================================

idAnimWebCmdCtx *__fastcall idAI2::GetAnimWebCmdCtx(idAI2 *this)
{
  return &this->aiVolatile.animation.awCmdCtx;
}


// ========================================================================
// ?GetAAS@idAI2@@UBAPBVidAAS2@@XZ
// EA  : 0x82A25D20
// RVA : 0x00A25D20
// PDB : w:\tech5\tungsten\game\ai\ai2.h
// ========================================================================

const idAAS2 *__fastcall idAI2::GetAAS(idAI2 *this)
{
  return this->aiVolatile.aas.aas;
}


// ========================================================================
// ?GetWeaponSlot@idAI2@@UBA?AW4equipSlot_t@@XZ
// EA  : 0x82A25D28
// RVA : 0x00A25D28
// PDB : w:\tech5\tungsten\game\ai\ai2.h
// ========================================================================

equipSlot_t __fastcall idAI2::GetWeaponSlot(idAI2 *this)
{
  return this->aiEditable.behaviors.decl->weaponSlot;
}


// ========================================================================
// ?HasSyncedWalks@idAI2@@UBA_NXZ
// EA  : 0x82A25D38
// RVA : 0x00A25D38
// PDB : w:\tech5\tungsten\game\ai\ai2.h
// ========================================================================

BOOL __fastcall idAI2::HasSyncedWalks(idAI2 *this)
{
  return (*((_BYTE *)this->aiEditable.behaviors.decl + 428) & 0x10) != 0;
}


// ========================================================================
// ?GetInputSettings@idAI2@@UAA?AUinputSettings_t@@PAVidPlayer@@@Z
// EA  : 0x82A25D48
// RVA : 0x00A25D48
// PDB : w:\tech5\tungsten\game\ai\ai2.h
// ========================================================================

idAI2 *__fastcall idAI2::GetInputSettings(idAI2 *this, inputSettings_t *result, idPlayer *player)
{
  double valueFloat; // fp13
  bool v4; // r6
  double v5; // fp12
  double v6; // fp11

  valueFloat = joy_pitchSpeed.valueFloat;
  v4 = in_invertLook.valueInteger != 0;
  v5 = joy_yawSpeed.valueFloat;
  v6 = m_sensitivity.valueFloat;
  this->__vftable = (idAI2_vtbl *)3;
  *(float *)&this->listenerList = 1.0;
  this->name.baseBuffer[0] = 0;
  *(float *)&this->listeningToList = 1.0;
  this->name.baseBuffer[1] = v4;
  *(float *)&this->name.len = valueFloat;
  *(float *)&this->name.data = v5;
  *(float *)&this->name.allocedAndFlag = v6;
  return this;
}


// ========================================================================
// ?GetNavParms@idAI2@@UBAPBUidAINavPowerMoverParms@@XZ
// EA  : 0x82A25DB8
// RVA : 0x00A25DB8
// PDB : w:\tech5\tungsten\game\ai\ai2.h
// ========================================================================

const idAINavPowerMoverParms *__fastcall idAI2::GetNavParms(idAI2 *this)
{
  return &this->aiEditable.behaviors.decl->navpower;
}


// ========================================================================
// ?GetDynamicCoverMgr@idAI2@@EAAPAVidDynamicCoverMgr@@XZ
// EA  : 0x82A25DC8
// RVA : 0x00A25DC8
// PDB : w:\tech5\tungsten\game\ai\ai2.h
// ========================================================================

idFormationCoverMgr *__fastcall idAI2::GetDynamicCoverMgr(idAI2 *this)
{
  return &this->formationCover;
}


// ========================================================================
// ?IsDead@idAI2@@UBA_NXZ
// EA  : 0x82A25DD8
// RVA : 0x00A25DD8
// PDB : w:\tech5\tungsten\game\ai\ai2.h
// ========================================================================

BOOL __fastcall idAI2::IsDead(idAI2 *this)
{
  return this->aiHealth.IsDead_Impl(this: &this->aiHealth)
      || !idAI2::IsPlayerControlled(this) && this->aiVolatile.fsms.alertCycle == ALERTCYCLE_DEAD;
}


// ========================================================================
// ?IsDying@idAI2@@UBA_NXZ
// EA  : 0x82A25E60
// RVA : 0x00A25E60
// PDB : w:\tech5\tungsten\game\ai\ai2.h
// ========================================================================

BOOL __fastcall idAI2::IsDying(idAI2 *this)
{
  return !idAI2::IsPlayerControlled(this) && this->aiVolatile.fsms.alertCycle == ALERTCYCLE_DYING
      || this->aiHealth.IsDead_Impl(this: &this->aiHealth) && idAI2::GetAlertCycle(this) != ALERTCYCLE_DEAD;
}


// ========================================================================
// ?GetDefaultMovementMode@idAI2@@QBA?AW4aiMovementMode_t@@XZ
// EA  : 0x82A59728
// RVA : 0x00A59728
// PDB : w:\tech5\tungsten\game\ai\ai2.h
// ========================================================================

aiMovementMode_t __fastcall idAI2::GetDefaultMovementMode(idAI2 *this)
{
  if ( idAI2::IsPlayerControlled(this) )
    return !idComponentActionScript::RunningActionScript(this: &this->actionScript, entity: this) ? 9 : 1;
  else
    return this->aiConstants.movement.defaultMovementMode;
}


// ========================================================================
// ?UseTauntChatterVO@idAI2@@QBA_NXZ
// EA  : 0x82A94310
// RVA : 0x00A94310
// PDB : w:\tech5\tungsten\game\ai\ai2.h
// ========================================================================

int __fastcall idAI2::UseTauntChatterVO(idAI2 *this)
{
  idCombatStage *CurrentCombatStage; // r3
  unsigned __int8 v3; // r11

  if ( idAI2::GetCurrentCombatStage(this) == nullptr )
    return 1;
  CurrentCombatStage = idAI2::GetCurrentCombatStage(this);
  v3 = 0;
  if ( (*((_BYTE *)CurrentCombatStage + 92) & 0x20) != 0 )
    return 1;
  return v3;
}


// ========================================================================
// ?HasSquadLeader@idAIActionSettings@idAIEditable@@QBA_NXZ
// EA  : 0x82ACFB18
// RVA : 0x00ACFB18
// PDB : w:\tech5\tungsten\game\ai\ai2.h
// ========================================================================

int __fastcall idAIEditable::idAIActionSettings::HasSquadLeader(idAIEditable::idAIActionSettings *this)
{
  int value; // r10
  idActor *v3; // r3
  int v4; // r9
  idActor *v5; // r3
  idActor *v6; // r3
  int result; // r3
  bool v8; // zf

  if ( !this->squad.squadActive )
    return 0;
  value = this->squad.squadLeader.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] != value >> 13 )
    return 0;
  v3 = (idActor *)gameLocal->entities.ptr[value & 0x1FFF];
  if ( v3 == nullptr || idActor::CastTo(c: v3) == nullptr )
    return 0;
  v4 = this->squad.squadLeader.spawnId.value;
  if ( gameLocal->spawnIds.ptr[v4 & 0x1FFF] == v4 >> 13
    && (v5 = (idActor *)gameLocal->entities.ptr[v4 & 0x1FFF]) != nullptr )
  {
    v6 = idActor::CastTo(c: v5);
  }
  else
  {
    v6 = nullptr;
  }
  v8 = !v6->IsDead(this: v6);
  result = 1;
  if ( !v8 )
    return 0;
  return result;
}


// ========================================================================
// ?GetSquadLeader@idAIActionSettings@idAIEditable@@QBAPBVidActor@@XZ
// EA  : 0x82ACFC08
// RVA : 0x00ACFC08
// PDB : w:\tech5\tungsten\game\ai\ai2.h
// ========================================================================

const idActor *__fastcall idAIEditable::idAIActionSettings::GetSquadLeader(idAIEditable::idAIActionSettings *this)
{
  int value; // r10
  idActor *v2; // r3

  value = this->squad.squadLeader.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v2 = (idActor *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    return idActor::CastTo(c: v2);
  }
  else
  {
    return nullptr;
  }
}


// ========================================================================
// ?UseRelaxedChatterVO@idAI2@@QBA_NXZ
// EA  : 0x82AECA00
// RVA : 0x00AECA00
// PDB : w:\tech5\tungsten\game\ai\ai2.h
// ========================================================================

int __fastcall idAI2::UseRelaxedChatterVO(idAI2 *this)
{
  idCombatStage *CurrentCombatStage; // r3
  unsigned __int8 v3; // r11

  if ( idAI2::GetCurrentCombatStage(this) == nullptr )
    return 1;
  CurrentCombatStage = idAI2::GetCurrentCombatStage(this);
  v3 = 0;
  if ( (*((_BYTE *)CurrentCombatStage + 92) & 0x80) != 0 )
    return 1;
  return v3;
}


// ========================================================================
// ?UsesScenePointType@idAIActionSettings@idAIEditable@@QBA_NW4scenePointType_t@@@Z
// EA  : 0x82AF59B8
// RVA : 0x00AF59B8
// PDB : w:\tech5\tungsten\game\ai\ai2.h
// ========================================================================

int __fastcall idAIEditable::idAIActionSettings::UsesScenePointType(
        idAIEditable::idAIActionSettings *this,
        scenePointType_t type)
{
  int result; // r3
  BOOL usesLookScenePoints; // r11

  switch ( type )
  {
    case 4:
      return this->cover.usesCombatScenePoints;
    case 3:
      return this->search.usesSearchScenePoints;
    case 1:
      return this->roam.usesRoamScenePoints;
    default:
      break;
  }
  if ( type != LOOK )
    return 0;
  usesLookScenePoints = this->look.usesLookScenePoints;
  result = 1;
  if ( !usesLookScenePoints )
    return 0;
  return result;
}


// ========================================================================
// ?UpdateAimDot@idAIActionSettings@idAIEditable@@QAAXXZ
// EA  : 0x82C96D00
// RVA : 0x00C96D00
// PDB : w:\tech5\tungsten\game\ai\ai2.h
// ========================================================================

void __fastcall idAIEditable::idAIActionSettings::UpdateAimDot(idAIEditable::idAIActionSettings *this, long double a2)
{
  long double v3; // fp2
  long double v4; // fp2
  long double v5; // fp2

  *(double *)&a2 = (float)(idMath::M_DEG2RAD * this->fire.aimAngle);
  v3 = cos(x: a2);
  this->fire.aimDot = *(double *)&v3;
  *(double *)&v3 = (float)((float)(this->fire.aimAngle + (float)10.0) * idMath::M_DEG2RAD);
  v4 = cos(x: v3);
  this->fire.gangstaAimDot = *(double *)&v4;
  *(double *)&v4 = (float)((float)(this->fire.aimAngle + (float)20.0) * idMath::M_DEG2RAD);
  v5 = cos(x: v4);
  this->fire.aimDotUpsideDown = *(double *)&v5;
}

