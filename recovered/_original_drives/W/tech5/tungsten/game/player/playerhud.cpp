
// ========================================================================
// ?SetIgnoreJobUpdates@idPlayerHud@@QAAX_N@Z
// EA  : 0x82E4C4F0
// RVA : 0x00E4C4F0
// PDB : w:\tech5\tungsten\game\player\playerhud.cpp
// ========================================================================

void __fastcall idPlayerHud::SetIgnoreJobUpdates(idPlayerHud *this, bool ignore)
{
  this->ignoreJobUpdates = ignore;
}


// ========================================================================
// ?SetIgnorePickupUpdate@idPlayerHud@@QAAX_N@Z
// EA  : 0x82E4C4F8
// RVA : 0x00E4C4F8
// PDB : w:\tech5\tungsten\game\player\playerhud.cpp
// ========================================================================

void __fastcall idPlayerHud::SetIgnorePickupUpdate(idPlayerHud *this, bool ignore)
{
  this->ignorePickupUpdates = ignore;
}


// ========================================================================
// ?SetHudState@idPlayerHud@@QAAXW4hudState_t@1@@Z
// EA  : 0x82E4C500
// RVA : 0x00E4C500
// PDB : w:\tech5\tungsten\game\player\playerhud.cpp
// ========================================================================

void __fastcall idPlayerHud::SetHudState(idPlayerHud *this, idPlayerHud::hudState_t state)
{
  if ( this->hudState != HUDSTATE_BALOON )
    this->hudState = state;
}


// ========================================================================
// ?SetTempHudState@idPlayerHud@@QAAXW4hudState_t@1@@Z
// EA  : 0x82E4C518
// RVA : 0x00E4C518
// PDB : w:\tech5\tungsten\game\player\playerhud.cpp
// ========================================================================

void __fastcall idPlayerHud::SetTempHudState(idPlayerHud *this, idPlayerHud::hudState_t state)
{
  idPlayerHud::hudState_t hudState; // r11

  hudState = this->hudState;
  this->hudState = state;
  this->tempHudState = hudState;
}


// ========================================================================
// ?RestoreHudState@idPlayerHud@@QAAXXZ
// EA  : 0x82E4C528
// RVA : 0x00E4C528
// PDB : w:\tech5\tungsten\game\player\playerhud.cpp
// ========================================================================

void __fastcall idPlayerHud::RestoreHudState(idPlayerHud *this)
{
  this->hudState = this->tempHudState;
}


// ========================================================================
// ?GetReticleIndex@idPlayerHud@@SAHH_N@Z
// EA  : 0x82E4C538
// RVA : 0x00E4C538
// PDB : w:\tech5\tungsten\game\player\playerhud.cpp
// ========================================================================

int __fastcall idPlayerHud::GetReticleIndex(int cursorInfo, bool negative)
{
  int result; // r3

  switch ( cursorInfo )
  {
    case 4:
      result = 3;
      break;
    case 5:
      result = !negative ? 1 : 8;
      break;
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 14:
    case 16:
    case 17:
      result = 1;
      break;
    case 13:
      result = 7;
      break;
    case 15:
      result = 4;
      break;
    case 18:
      result = 9;
      break;
  }
  return result;
}


// ========================================================================
// ?ActivateCombatHud@idPlayerHud@@QAAXXZ
// EA  : 0x82E4C5E0
// RVA : 0x00E4C5E0
// PDB : w:\tech5\tungsten\game\player\playerhud.cpp
// ========================================================================

void __fastcall idPlayerHud::ActivateCombatHud(idPlayerHud *this)
{
  this->activateCombatTime = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
}


// ========================================================================
// ?Init@idPlayerHud@@QAAXPAVidPresentablePlayer@@@Z
// EA  : 0x82E4C628
// RVA : 0x00E4C628
// PDB : w:\tech5\tungsten\game\player\playerhud.cpp
// ========================================================================

void __fastcall idPlayerHud::Init(idPlayerHud *this, idPresentablePlayer *inPlayer)
{
  this->presPlayer = inPlayer;
  this->player = (idPlayer *)inPlayer->entity;
  this->restrictedGameplay = false;
  this->gameInhibited = false;
  this->playerChangeWeapon = false;
  this->prevChangeVisible = false;
}


// ========================================================================
// ?DelayUpdateHud@idPlayerHud@@QAAXH@Z
// EA  : 0x82E4C650
// RVA : 0x00E4C650
// PDB : w:\tech5\tungsten\game\player\playerhud.cpp
// ========================================================================

void __fastcall idPlayerHud::DelayUpdateHud(idPlayerHud *this, int msDelay)
{
  this->msDelayHudUpdate = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED)
                         + msDelay;
}


// ========================================================================
// ?ClearWatchTargets@idPlayerHud@@QAAXXZ
// EA  : 0x82E4C6A8
// RVA : 0x00E4C6A8
// PDB : w:\tech5\tungsten\game\player\playerhud.cpp
// ========================================================================

void __fastcall idPlayerHud::ClearWatchTargets(idPlayerHud *this)
{
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->hudWatchTargets);
}


// ========================================================================
// ?DamageImpulse@idPlayerHud@@QAAXVidVec3@@@Z
// EA  : 0x82E4C6B0
// RVA : 0x00E4C6B0
// PDB : w:\tech5\tungsten\game\player\playerhud.cpp
// ========================================================================

void __fastcall idPlayerHud::DamageImpulse(idPlayerHud *this, idVec3 *origin)
{
  idClientGame *v2; // r11

  this->damageOrigin.x = *(float *)&this;
  this->damageOrigin.y = *(float *)&origin;
  v2 = clientGame;
  this->damageOrigin.z = *(float *)&origin;
  this->damageImpulseTime = idGameTimeManager::GetGameMs(this: &v2->gameTimeManager, type: GAMETIME_SCALED);
}


// ========================================================================
// ?VehiclePickUp@idPlayerHud@@QBAXABVidStr@@HVidStrId@@H@Z
// EA  : 0x82E4C718
// RVA : 0x00E4C718
// PDB : w:\tech5\tungsten\game\player\playerhud.cpp
// ========================================================================

void __fastcall idPlayerHud::VehiclePickUp(
        idPlayerHud *this,
        const idStr *icon,
        int count,
        idStrId *displayName,
        int itemType)
{
  unsigned __int64 v5; // r11
  int v7; // r27
  const char *Key; // r3
  idLobbyBase_vtbl *v12; // r31
  idClientGame *LobbyUserIdFromPlayerIndex; // r3
  idBitMsg v14; // [sp+50h] [-1FA0h] BYREF
  char v15; // [sp+78h] [-1F78h] BYREF
  _BYTE v16[3952]; // [sp+80h] [-1F70h] BYREF

  HIDWORD(v5) = this->presPlayer;
  LODWORD(v5) = 0;
  v7 = *(_DWORD *)(HIDWORD(v5) + 180);
  v14.writeData = v16;
  v14.readData = v16;
  v14.maxSize = 8000;
  memset(&v14.curSize, 0, 18);
  v14.tempValue = v5;
  idBitMsg::WriteBits(this: &v14, value: v7, numBits: 8);
  idBitMsg::WriteBits(this: &v14, value: itemType, numBits: 8);
  idBitMsg::WriteBits(this: &v14, value: count, numBits: 32);
  idBitMsg::WriteString(this: &v14, s: icon->data, maxLength: -1, make7Bit: true);
  Key = idStrId::GetKey(this: displayName);
  idBitMsg::WriteString(this: &v14, s: Key, maxLength: -1, make7Bit: true);
  v12 = session->GetActingGameStateLobbyBase(this: session)->__vftable;
  LobbyUserIdFromPlayerIndex = idClientGame::GetLobbyUserIdFromPlayerIndex(
                                 this: (idClientGame *)&v15,
                                 result: (lobbyUserID_t *)clientGame,
                                 playerIndex: v7);
  v12->SendReliableToLobbyUser(
    this: (idLobbyBase *)LobbyUserIdFromPlayerIndex->random.seed,
    a2: (lobbyUserID_t *)LobbyUserIdFromPlayerIndex->renderWorld,
    a3: 32,
    a4: &v14);
}


// ========================================================================
// ?Update_HealthIndicator@idPlayerHud@@AAAXAAVidHudInfo@@@Z
// EA  : 0x82E4C838
// RVA : 0x00E4C838
// PDB : w:\tech5\tungsten\game\player\playerhud.cpp
// ========================================================================

void __fastcall idPlayerHud::Update_HealthIndicator(idPlayerHud *this, idHudInfo *hudInfo)
{
  idPlayer *player; // r11
  double v5; // fp31
  idEntity *Control; // r3
  idEntity *v7; // r3
  int v8; // r3

  if ( this->hudState >= HUDSTATE_DAMAGE_HEALTH )
  {
    player = this->player;
    if ( player != nullptr )
    {
      v5 = ((double (__fastcall *)(idTungstenHealth *))player->playerHealth.GetCurBaseHealth_Impl)(a1: &player->playerHealth);
      if ( idPlayer::GetControl(this: this->player) != nullptr )
      {
        Control = idPlayer::GetControl(this: this->player);
        if ( (unsigned __int8)idProp_WeaponStatic::IsTypeOf(c: Control) != 0 )
        {
          v7 = idPlayer::GetControl(this: this->player);
          v8 = (int)v7->GetHealthComponent_2(this: v7);
          if ( v8 != 0 )
            v5 = ((double (__fastcall *)(int))*(_DWORD *)(*(_DWORD *)v8 + 60))(a1: v8);
        }
      }
      hudInfo->healthIndicator.health = v5;
      hudInfo->healthIndicator.armor = this->player->playerHealth.GetComponentCur_Impl(
                                         this: &this->player->playerHealth,
                                         a2: 1);
    }
  }
}


// ========================================================================
// ?UpdateJobStatus@idPlayerHud@@AAAXAAVidHudInfo@@@Z
// EA  : 0x82E4C928
// RVA : 0x00E4C928
// PDB : w:\tech5\tungsten\game\player\playerhud.cpp
// ========================================================================

void __fastcall idPlayerHud::UpdateJobStatus(idPlayerHud *this, idHudInfo *hudInfo)
{
  char v4; // r11
  idJob *currentJob; // r10
  char v6; // r26
  int defaultJobShowTime; // r28
  missionStatus_t status; // r11
  idPlayerHud::updateJobInfo_t *list; // r11
  idList<idPlayerHud::updateJobInfo_t,5> *p_jobUpdateQueue; // r28
  idJob *JobByDecl; // r3
  idPlayerHud::updateJobInfo_t *v12; // r11

  if ( this->player != nullptr )
  {
    hudInfo->showJournalIcon = true;
    if ( job_alwaysShow.valueInteger == 0 || (v4 = 1, this->currentJob == nullptr) )
      v4 = 0;
    currentJob = this->currentJob;
    v6 = v4;
    defaultJobShowTime = this->defaultJobShowTime;
    if ( currentJob != nullptr )
    {
      status = currentJob->status;
      if ( status == JOBSTATUS_COMPLETED )
      {
        defaultJobShowTime = this->completedJobShowTime;
      }
      else if ( status == JOBSTATUS_ACCEPTED )
      {
        defaultJobShowTime = this->acceptedJobShowTime;
      }
    }
    if ( !this->fakeJobCurrentJob && currentJob == nullptr
      || this->jobStartShowTime + defaultJobShowTime < idGameTimeManager::GetGameMs(
                                                         this: &clientGame->gameTimeManager,
                                                         type: GAMETIME_SCALED) )
    {
      if ( this->jobUpdateQueue.num != 0 )
      {
        list = this->jobUpdateQueue.list;
        p_jobUpdateQueue = &this->jobUpdateQueue;
        if ( list->fakeJob )
        {
          this->fakeJobCurrentJob = true;
          idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->jobUpdateQueue);
        }
        else
        {
          this->fakeJobCurrentJob = false;
          JobByDecl = idJobManager::FindJobByDecl(this: &this->player->jobManager, jobDecl: list->jobDecl);
          if ( JobByDecl != nullptr )
          {
            this->currentJob = JobByDecl;
            v12 = p_jobUpdateQueue->list;
            this->currentRequirement = p_jobUpdateQueue->list->requiredNum;
            this->currentJobPlaySound = v12->playSound;
            this->currentJobTreatUpdateAsSameStatus = v12->treatAsSameStatusUpdate;
            this->jobStartShowTime = idGameTimeManager::GetGameMs(
                                       this: &clientGame->gameTimeManager,
                                       type: GAMETIME_SCALED);
          }
          idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->jobUpdateQueue);
        }
      }
      else if ( v6 == 0 )
      {
        hudInfo->showJournalIcon = false;
        this->currentJob = nullptr;
        idJobManager::MarkJobNotesSeenOnHUD(this: &this->player->jobManager);
        this->jobStartShowTime = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        this->fakeJobCurrentJob = false;
      }
    }
  }
}


// ========================================================================
// ?AcceptRespawnFromSpectate@idPlayerHud@@QAAXH@Z
// EA  : 0x82E4CAC8
// RVA : 0x00E4CAC8
// PDB : w:\tech5\tungsten\game\player\playerhud.cpp
// ========================================================================

void __fastcall idPlayerHud::AcceptRespawnFromSpectate(idPlayerHud *this, int playerIndex)
{
  unsigned __int64 v2; // r11
  idLobbyBase *v3; // r3
  _BYTE v4[16]; // [sp+50h] [-40h] BYREF
  idBitMsg v5; // [sp+60h] [-30h] BYREF

  LODWORD(v2) = 0;
  HIDWORD(v2) = v4;
  memset(&v5.curSize, 0, 18);
  v5.writeData = v4;
  v5.readData = v4;
  v5.maxSize = 4;
  v5.tempValue = v2;
  idBitMsg::WriteBits(this: &v5, value: playerIndex, numBits: 8);
  v3 = session->GetActingGameStateLobbyBase(this: session);
  v3->SendReliable(this: v3, a2: 11, a3: &v5, a4: true, a5: 255u);
}


// ========================================================================
// ?OpenGarageFromSpectate@idPlayerHud@@QAAXH@Z
// EA  : 0x82E4CB60
// RVA : 0x00E4CB60
// PDB : w:\tech5\tungsten\game\player\playerhud.cpp
// ========================================================================

void __fastcall idPlayerHud::OpenGarageFromSpectate(idPlayerHud *this, int playerIndex)
{
  __int64 v2; // r11
  idLobbyBase *v4; // r3
  int v5; // r5
  idLobbyBase_vtbl *v6; // r31
  idClientGame *LobbyUserIdFromPlayerIndex; // r3
  _BYTE v8[8]; // [sp+50h] [-50h] BYREF
  char v9; // [sp+58h] [-48h] BYREF
  _DWORD v10[7]; // [sp+60h] [-40h] BYREF
  char v11; // [sp+7Ch] [-24h]
  char v12; // [sp+7Dh] [-23h]
  __int64 v13; // [sp+80h] [-20h]

  LODWORD(v2) = 0;
  memset(&v10[3], 0, 16);
  v10[0] = v8;
  v10[1] = v8;
  HIDWORD(v2) = &joystick.joyAxis[0][2];
  v10[2] = 4;
  v11 = 0;
  v12 = 0;
  v13 = v2;
  v4 = session->GetActingGameStateLobbyBase(this: session);
  v5 = playerIndex;
  v6 = v4->__vftable;
  LobbyUserIdFromPlayerIndex = idClientGame::GetLobbyUserIdFromPlayerIndex(
                                 this: (idClientGame *)&v9,
                                 result: (lobbyUserID_t *)clientGame,
                                 playerIndex: v5);
  v6->SendReliableToLobbyUser(
    this: (idLobbyBase *)LobbyUserIdFromPlayerIndex->random.seed,
    a2: (lobbyUserID_t *)LobbyUserIdFromPlayerIndex->renderWorld,
    a3: 20,
    a4: (idBitMsg *)v10);
}


// ========================================================================
// ?GetCombinerIndex@idPlayerHud@@QAAHPAVidEntity@@@Z
// EA  : 0x82E4CC20
// RVA : 0x00E4CC20
// PDB : w:\tech5\tungsten\game\player\playerhud.cpp
// ========================================================================

int __fastcall idPlayerHud::GetCombinerIndex(idPlayerHud *this, idEntity *ent)
{
  int v2; // r7
  int num; // r8
  int v4; // r10
  int i; // r11

  if ( ent != nullptr )
    v2 = (gameLocal->spawnIds.ptr[ent->entityNumber] << 13) | ent->entityNumber;
  else
    v2 = 0x1FFF;
  num = this->combinerTargets.num;
  v4 = 0;
  if ( num <= 0 )
    return -1;
  for ( i = 0; this->combinerTargets.list[i].spawnId.value != v2; ++i )
  {
    if ( ++v4 >= num )
      return -1;
  }
  return v4;
}


// ========================================================================
// ?RemoveCombiner@idPlayerHud@@QAAXPAVidEntity@@@Z
// EA  : 0x82E4CC98
// RVA : 0x00E4CC98
// PDB : w:\tech5\tungsten\game\player\playerhud.cpp
// ========================================================================

void __fastcall idPlayerHud::RemoveCombiner(idPlayerHud *this, idEntity *ent)
{
  int v2; // r8
  idList<idEntityPtr<idEntity>,58> *p_combinerTargets; // r3
  int v4; // r4
  int num; // r10
  int i; // r11

  if ( ent != nullptr )
    v2 = (gameLocal->spawnIds.ptr[ent->entityNumber] << 13) | ent->entityNumber;
  else
    v2 = 0x1FFF;
  p_combinerTargets = (idList<idEntityPtr<idEntity>,58> *)&this->combinerTargets;
  v4 = 0;
  num = p_combinerTargets->num;
  if ( num > 0 )
  {
    for ( i = 0; p_combinerTargets->list[i].spawnId.value != v2; ++i )
    {
      if ( ++v4 >= num )
        return;
    }
    if ( v4 >= 0 )
      idList<idHandle<int,enum invalidAIEvent_t,-1>,5>::RemoveIndex(this: p_combinerTargets, index: v4);
  }
}


// ========================================================================
// ?SetMinigame@idPlayerHud@@QAAXPAVidEntity@@@Z
// EA  : 0x82E4CD10
// RVA : 0x00E4CD10
// PDB : w:\tech5\tungsten\game\player\playerhud.cpp
// ========================================================================

void __fastcall idPlayerHud::SetMinigame(idPlayerHud *this, idEntity *ent)
{
  this->newMinigame = true;
  this->minigameEntity.spawnId.value = 0x1FFF;
  if ( (unsigned __int8)idMinigame::IsTypeOf(c: ent) != 0 )
  {
    if ( ent != nullptr )
      this->minigameEntity.spawnId.value = (gameLocal->spawnIds.ptr[ent->entityNumber] << 13) | ent->entityNumber;
    else
      this->minigameEntity.spawnId.value = 0x1FFF;
  }
}


// ========================================================================
// ?ClearPickupItems@idPlayerHud@@QAAXAAVidHudInfo@@@Z
// EA  : 0x82E4CFC8
// RVA : 0x00E4CFC8
// PDB : w:\tech5\tungsten\game\player\playerhud.cpp
// ========================================================================

void __fastcall idPlayerHud::ClearPickupItems(idPlayerHud *this, idHudInfo *hudInfo)
{
  char *list; // r3

  if ( this->pickupList.listStatic == 0 || this->pickupList.listStatic == 2 )
  {
    list = (char *)this->pickupList.list;
    if ( list != nullptr )
      idListArrayDelete<idHudPickupInfo>(ptr: list, num: this->pickupList.size);
    this->pickupList.list = nullptr;
    this->pickupList.size = 0;
  }
  this->pickupList.num = 0;
}


// ========================================================================
// ??0idPlayerHud@@QAA@XZ
// EA  : 0x82E4D2C8
// RVA : 0x00E4D2C8
// PDB : w:\tech5\tungsten\game\player\playerhud.cpp
// ========================================================================

idPlayerHud *__fastcall idPlayerHud::idPlayerHud(idPlayerHud *this)
{
  this->driverNum = 0;
  this->combatCalmDownTime = 10.0;
  this->showCrosshair = true;
  this->ignoreJobUpdates = false;
  this->ignorePickupUpdates = false;
  this->activateCombatTime = -1;
  this->jobUpdateQueue.list = nullptr;
  this->jobUpdateQueue.granularity = 0;
  this->jobUpdateQueue.memTag = 5;
  this->jobUpdateQueue.listStatic = 0;
  this->jobUpdateQueue.size = 0;
  this->jobUpdateQueue.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->jobUpdateQueue);
  this->currentJob = nullptr;
  this->fakeJobCurrentJob = false;
  this->currentJobPlaySound = false;
  this->currentJobTreatUpdateAsSameStatus = false;
  this->dynamicJob = nullptr;
  this->dynamicJobPlaySound = false;
  this->dynamicJobTreatUpdateAsSameStatus = false;
  this->dynamicJobUpdateQueue.list = nullptr;
  this->dynamicJobUpdateQueue.granularity = 0;
  this->dynamicJobUpdateQueue.memTag = 5;
  this->dynamicJobUpdateQueue.listStatic = 0;
  this->dynamicJobUpdateQueue.size = 0;
  this->dynamicJobUpdateQueue.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->dynamicJobUpdateQueue);
  this->currentRequirement = -1;
  this->jobStartShowTime = 0;
  this->defaultJobShowTime = 3000;
  this->completedJobShowTime = 3000;
  this->acceptedJobShowTime = 3000;
  this->hudState = HUDSTATE_ALL;
  this->tempHudState = HUDSTATE_ALL;
  this->allowWeaponChange = true;
  this->allowDossier = true;
  this->pickupList.granularity = 0;
  this->pickupList.memTag = 5;
  this->pickupList.listStatic = 0;
  this->pickupList.list = nullptr;
  this->pickupList.size = 0;
  this->pickupList.num = 0;
  this->player = nullptr;
  this->presPlayer = nullptr;
  this->rocketTarget.spawnId.value = 0x1FFF;
  this->hudWatchTargets.list = nullptr;
  this->hudWatchTargets.granularity = 0;
  this->hudWatchTargets.memTag = 5;
  this->hudWatchTargets.listStatic = 0;
  this->hudWatchTargets.size = 0;
  this->hudWatchTargets.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->hudWatchTargets);
  this->combinerTargets.size = 3;
  this->combinerTargets.list = this->combinerTargets.staticList;
  this->combinerTargets.num = 0;
  this->combinerTargets.granularity = 1;
  this->combinerTargets.memTag = 5;
  this->combinerTargets.listStatic = 1;
  this->combinerTargets.staticList[0].spawnId.value = 0x1FFF;
  this->combinerTargets.staticList[1].spawnId.value = 0x1FFF;
  this->combinerTargets.staticList[2].spawnId.value = 0x1FFF;
  this->damageOrigin.x = 0.0;
  this->damageOrigin.y = 0.0;
  this->damageOrigin.z = 0.0;
  this->damageImpulseTime = -1;
  this->pickupSwitchTime = 0;
  this->pickupUpdate = false;
  this->canRemovePickup = false;
  this->mainMenuActive = false;
  this->clusterTargets.list = nullptr;
  this->clusterTargets.granularity = 0;
  this->clusterTargets.memTag = 5;
  this->clusterTargets.listStatic = 0;
  this->clusterTargets.size = 0;
  this->clusterTargets.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->clusterTargets);
  this->gameInhibited = false;
  this->playerChangeWeapon = false;
  this->prevChangeVisible = false;
  this->guiModel = nullptr;
  this->guiModelLoc.x = 0.0;
  this->guiModelLoc.y = 0.0;
  this->forceScoreboard = false;
  this->quickMenuIndex = -1;
  this->quickScrollWait = 0;
  this->quickMenuOffset = 0;
  this->crosshairUsed = false;
  this->msDelayHudUpdate = 0;
  this->minigameEntity.spawnId.value = 0x1FFF;
  this->newMinigame = false;
  this->helpInfo.show = false;
  this->helpInfo.icon = nullptr;
  this->helpInfo.buttonImage = nullptr;
  this->showBottomBar = true;
  this->restrictedGameplay = false;
  return this;
}


// ========================================================================
// __unwind$491242_0
// EA  : 0x82E4D4E8
// RVA : 0x00E4D4E8
// PDB : w:\tech5\tungsten\game\player\playerhud.cpp
// ========================================================================

void _unwind_491242_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 16));
}


// ========================================================================
// __unwind$491243
// EA  : 0x82E4D514
// RVA : 0x00E4D514
// PDB : w:\tech5\tungsten\game\player\playerhud.cpp
// ========================================================================

void _unwind_491243()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 48));
}


// ========================================================================
// __unwind$491244
// EA  : 0x82E4D540
// RVA : 0x00E4D540
// PDB : w:\tech5\tungsten\game\player\playerhud.cpp
// ========================================================================

void _unwind_491244()
{
  int v0; // r12

  idList<idHudPickupInfo,5>::~idList<idHudPickupInfo,5>(this: (idList<idHudPickupInfo,5> *)(*(_DWORD *)(v0 - 160 + 180)
                                                                                          + 96));
}


// ========================================================================
// __unwind$491245
// EA  : 0x82E4D56C
// RVA : 0x00E4D56C
// PDB : w:\tech5\tungsten\game\player\playerhud.cpp
// ========================================================================

void _unwind_491245()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 124));
}


// ========================================================================
// __unwind$491246_0
// EA  : 0x82E4D598
// RVA : 0x00E4D598
// PDB : w:\tech5\tungsten\game\player\playerhud.cpp
// ========================================================================

void _unwind_491246_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 140));
}


// ========================================================================
// ?UpdateForVehicle@idPlayerHud@@AAAXAAVidHudInfo@@@Z
// EA  : 0x82E4D5C8
// RVA : 0x00E4D5C8
// PDB : w:\tech5\tungsten\game\player\playerhud.cpp
// ========================================================================

void __fastcall idPlayerHud::UpdateForVehicle(idPlayerHud *this, idHudInfo *hudInfo)
{
  idPresentablePlayer *presPlayer; // r3
  idPresentableVehicle *Vehicle; // r21
  idCrosshairInfo *p_crosshairInfo; // r29
  int v7; // r26
  int v8; // r27
  int v9; // r28
  idEntityPtr<idEntity> *v10; // r3
  idPlayer *player; // r20
  idCrosshairCombinerInfo *v12; // r31
  idCombiner *v13; // r3
  idCombiner *v14; // r3
  idHudInteractionInfo *p_interact; // r31
  int num; // r28
  int v17; // ctr
  int v18; // r11
  idHudInteractionInfo::icon_t *v19; // r3
  int itemCount; // r10

  presPlayer = this->presPlayer;
  if ( presPlayer != nullptr )
    Vehicle = idPresentablePlayer::GetVehicle(this: presPlayer);
  else
    Vehicle = nullptr;
  if ( this->hudState == HUDSTATE_ALL )
  {
    if ( !common->IsMultiplayer(this: common) )
    {
      if ( Vehicle == nullptr )
      {
LABEL_23:
        idPlayerHud::UpdateJobStatus(this, hudInfo);
        goto LABEL_24;
      }
      if ( gameLocal->spawnIds.ptr[this->presPlayer->focusTracker.focusEntityOverride.spawnId.value & 0x1FFF] == this->presPlayer->focusTracker.focusEntityOverride.spawnId.value >> 13
        && this->showCrosshair )
      {
        hudInfo->reticle.show = true;
        hudInfo->reticle.pulsate = false;
        p_crosshairInfo = &this->presPlayer->focusTracker.crosshairInfo;
        idList<idCrosshairCombinerInfo,5>::SetNum(this: &hudInfo->combiners, newNum: this->combinerTargets.num);
        v7 = 0;
        if ( this->combinerTargets.num > 0 )
        {
          v8 = 0;
          v9 = 0;
          do
          {
            v10 = &this->combinerTargets.list[v8];
            if ( gameLocal->spawnIds.ptr[v10->spawnId.value & 0x1FFF] == v10->spawnId.value >> 13 )
            {
              player = this->player;
              v12 = &hudInfo->combiners.list[v9];
              v13 = (idCombiner *)idEntityPtr<idEntity const>::operator->(this: v10);
              v14 = idCombiner::CastTo(c: v13);
              idCombiner::UpdateGui(this: v14, player, info: v12);
            }
            ++v7;
            ++v9;
            ++v8;
          }
          while ( v7 < this->combinerTargets.num );
        }
        hudInfo->reticle.iconIndex = idPlayerHud::GetReticleIndex(
                                       cursorInfo: p_crosshairInfo->material,
                                       negative: (_cntlzw(p_crosshairInfo->colorState - 1) & 0x20) != 0);
        if ( p_crosshairInfo->hideCrossHairInfo )
        {
          hudInfo->reticle.iconIndex = -1;
        }
        else
        {
          p_interact = &hudInfo->interact;
          hudInfo->reticle.useAmount = p_crosshairInfo->useAmount;
          num = p_crosshairInfo->icons.num;
          idList<idHudInteractionInfo::icon_t,5>::SetNum(this: &hudInfo->interact.icons, newNum: num);
          if ( num > 0 )
          {
            v17 = num;
            v18 = 0;
            do
            {
              p_interact->icons.list[v18].material = p_crosshairInfo->icons.list[v18].material;
              p_interact->icons.list[v18].usable = p_crosshairInfo->icons.list[v18].usable;
              v19 = &p_interact->icons.list[v18];
              itemCount = p_crosshairInfo->icons.list[v18++].itemCount;
              v19->itemCount = itemCount;
              --v17;
            }
            while ( v17 != 0 );
          }
        }
      }
    }
    if ( Vehicle != nullptr && idPresentableVehicle::GetGunner(this: Vehicle) == this->presPlayer )
      hudInfo->reticle.show = true;
    goto LABEL_23;
  }
LABEL_24:
  idPlayerHud::Update_HealthIndicator(this, hudInfo);
}


// ========================================================================
// ?UpdateForFoot@idPlayerHud@@AAAXAAVidHudInfo@@@Z
// EA  : 0x82E4D800
// RVA : 0x00E4D800
// PDB : w:\tech5\tungsten\game\player\playerhud.cpp
// ========================================================================

void __fastcall idPlayerHud::UpdateForFoot(idPlayerHud *this, idHudInfo *hudInfo)
{
  bool v4; // r29
  idPresentablePlayer *presPlayer; // r3
  bool v6; // r31
  idPresentable *Control; // r3
  char v8; // r11
  idPresentablePlayer *v9; // r10
  idFocusTracker *p_focusTracker; // r31
  idCrosshairInfo *p_crosshairInfo; // r25
  idWeapon *v12; // r29
  idEntity *FocusEntity; // r28
  int GameMs; // r3
  bool v15; // r3
  bool v16; // r11
  idEntity *v17; // r3
  idAI2 *v18; // r3
  void *v19; // r3
  idEntity *v20; // r3
  idTurret *v21; // r3
  int v22; // r27
  int v23; // r28
  int v24; // r29
  idEntityPtr<idEntity> *v25; // r3
  idPlayer *player; // r19
  idCrosshairCombinerInfo *v27; // r31
  idCombiner *v28; // r3
  idCombiner *v29; // r3
  idHudInteractionInfo *p_interact; // r31
  int num; // r29
  int v32; // ctr
  int v33; // r11
  int v34; // r4
  idHudInteractionInfo::icon_t *v35; // r3
  idPlayer *v36; // r11
  double airLeft; // fp0
  bool v38; // r11
  idPresentablePlayer *v39; // r8
  char *v40; // r10
  int v41; // ctr
  idPresentablePlayer *p_z; // r11
  double v43; // fp10
  double v44; // fp7
  double v45; // fp6
  double v46; // fp13
  double v47; // fp4
  double v50; // fp11
  double v51; // fp9
  double v52; // fp9
  double v53; // fp11
  double v54; // fp10
  double v55; // fp9
  double v56; // fp2
  double v57; // fp1
  double v58; // fp11
  double v61; // fp5
  double v62; // fp9
  __int64 v63; // r11
  float x; // [sp+50h] [-C0h]
  float y; // [sp+54h] [-BCh]
  float z; // [sp+58h] [-B8h]
  char v67; // [sp+5Ch] [-B4h] BYREF
  float v68; // [sp+60h] [-B0h]
  float v69; // [sp+64h] [-ACh]
  float v70; // [sp+68h] [-A8h]
  float v71; // [sp+6Ch] [-A4h]
  float v72; // [sp+70h] [-A0h]
  float v73; // [sp+74h] [-9Ch]

  idPresentablePlayer::GetPendingWeapon(this: this->presPlayer);
  v4 = idPresentablePlayer::GetScopeGuiNum(this: this->presPlayer) == SCOPE_SKIPCROSSHAIR;
  idPlayerHud::Update_HealthIndicator(this, hudInfo);
  presPlayer = this->presPlayer;
  if ( presPlayer->playerProps == nullptr )
  {
    idLib::Warning(fmt: "PlayerProps NULL on player %d", presPlayer->entityNumber);
    return;
  }
  if ( (*((_BYTE *)presPlayer + 47033) & 4) == 0 )
  {
    if ( this->hudState < HUDSTATE_INFO )
      goto LABEL_40;
    v6 = false;
    Control = idPresentablePlayer::GetControl(this: presPlayer);
    if ( Control != nullptr )
      v6 = (_cntlzw(Control->GetType(this: Control) - 17) & 0x20) != 0;
    if ( this->showCrosshair && !this->gameInhibited || (v8 = 0, v6) )
      v8 = 1;
    if ( v8 == 0 || v4 )
      goto LABEL_40;
    hudInfo->reticle.pulsate = false;
    hudInfo->reticle.show = true;
    v9 = this->presPlayer;
    p_focusTracker = &v9->focusTracker;
    p_crosshairInfo = &v9->focusTracker.crosshairInfo;
    if ( (unsigned __int8)idPlayer::IsOnLadder(this: (idPlayer *)v9->entity) != 0 )
    {
      hudInfo->reticle.show = false;
    }
    else if ( !p_focusTracker->overFriendly )
    {
      v12 = this->presPlayer->GetEquippedWeapon(this: this->presPlayer, a2: 2);
      if ( v12 != nullptr )
      {
        FocusEntity = idFocusTracker::GetFocusEntity(this: p_focusTracker);
        if ( (unsigned __int8)idClass::IsType(this: v12, superclass: &idLaserCutter::Type) != 0 )
        {
          if ( !hudInfo->reticle.show
            || (GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED),
                v15 = v12->BlockCrosshair(this: v12, a2: GameMs),
                v16 = true,
                v15) )
          {
            v16 = false;
          }
          hudInfo->reticle.show = v16;
          hudInfo->reticle.pulsate = v12->CrosshairShouldPulsate(this: v12);
          goto LABEL_29;
        }
        if ( FocusEntity != nullptr )
        {
          v17 = idFocusTracker::GetFocusEntity(this: p_focusTracker);
          if ( (unsigned __int8)idAI2::IsTypeOf(c: v17) != 0 )
          {
            v18 = (idAI2 *)idFocusTracker::GetFocusEntity(this: p_focusTracker);
            v19 = idAI2::CastTo(c: v18);
          }
          else
          {
            v20 = idFocusTracker::GetFocusEntity(this: p_focusTracker);
            if ( (unsigned __int8)idTurret::IsTypeOf(c: v20) == 0 )
              goto LABEL_29;
            v21 = (idTurret *)idFocusTracker::GetFocusEntity(this: p_focusTracker);
            v19 = idTurret::CastTo(c: v21);
          }
          hudInfo->reticle.pulsate = (_cntlzw((*(unsigned __int8 (__fastcall **)(void *))(*(_DWORD *)v19 + 508))(a1: v19))
                                    & 0x20) != 0;
        }
      }
    }
LABEL_29:
    idList<idCrosshairCombinerInfo,5>::SetNum(this: &hudInfo->combiners, newNum: this->combinerTargets.num);
    v22 = 0;
    if ( this->combinerTargets.num > 0 )
    {
      v23 = 0;
      v24 = 0;
      do
      {
        v25 = &this->combinerTargets.list[v23];
        if ( gameLocal->spawnIds.ptr[v25->spawnId.value & 0x1FFF] == v25->spawnId.value >> 13 )
        {
          player = this->player;
          v27 = &hudInfo->combiners.list[v24];
          v28 = (idCombiner *)idEntityPtr<idEntity const>::operator->(this: v25);
          v29 = idCombiner::CastTo(c: v28);
          idCombiner::UpdateGui(this: v29, player, info: v27);
        }
        ++v22;
        ++v24;
        ++v23;
      }
      while ( v22 < this->combinerTargets.num );
    }
    hudInfo->reticle.iconIndex = idPlayerHud::GetReticleIndex(
                                   cursorInfo: p_crosshairInfo->material,
                                   negative: (_cntlzw(p_crosshairInfo->colorState - 1) & 0x20) != 0);
    if ( p_crosshairInfo->hideCrossHairInfo )
    {
      hudInfo->reticle.iconIndex = -1;
    }
    else
    {
      p_interact = &hudInfo->interact;
      hudInfo->reticle.useAmount = p_crosshairInfo->useAmount;
      hudInfo->interact.useCheckbox = p_crosshairInfo->useCheckbox;
      num = p_crosshairInfo->icons.num;
      idList<idHudInteractionInfo::icon_t,5>::SetNum(this: &hudInfo->interact.icons, newNum: num);
      if ( num > 0 )
      {
        v32 = num;
        v33 = 0;
        do
        {
          p_interact->icons.list[v33].material = p_crosshairInfo->icons.list[v33].material;
          p_interact->icons.list[v33].usable = p_crosshairInfo->icons.list[v33].usable;
          v34 = (int)&p_crosshairInfo->icons.list[v33];
          v35 = &p_interact->icons.list[v33++];
          v35->itemCount = *(_DWORD *)(v34 + 4);
          --v32;
        }
        while ( v32 != 0 );
      }
    }
LABEL_40:
    if ( this->hudState == HUDSTATE_ALL )
    {
      v36 = this->player;
      if ( v36 != nullptr )
      {
        airLeft = v36->airLeft;
        hudInfo->airSupply.percent = v36->airLeft;
        if ( airLeft < 1.0 || (v38 = false, this->presPlayer->physicsObj.currentSwimDepthState != SWIMDEPTH_STATE_NONE) )
          v38 = true;
        hudInfo->airSupply.show = v38;
      }
    }
    goto LABEL_46;
  }
  hudInfo->reticle.show = false;
  hudInfo->reticle.iconIndex = -1;
LABEL_46:
  if ( this->player != nullptr )
  {
    v39 = this->presPlayer;
    v40 = &v67;
    v41 = 9;
    p_z = (idPresentablePlayer *)&v39->firstPersonViewOrigin.z;
    x = v39->origin.x;
    y = v39->origin.y;
    z = v39->origin.z;
    do
    {
      p_z = (idPresentablePlayer *)((char *)p_z + 4);
      v40 += 4;
      *(_DWORD *)v40 = p_z->__vftable;
      --v41;
    }
    while ( v41 != 0 );
    v43 = (float)(this->damageOrigin.x - x);
    v44 = (float)(this->damageOrigin.y - y);
    v45 = this->damageOrigin.z;
    v46 = idMath::FLT_SMALLEST_NON_DENORMAL;
    hudInfo->damageLocator.intensity = 0.0;
    v47 = (float)((float)v45 - z);
    _FP11 = (float)((float)((float)((float)((float)v45 - z) * (float)((float)v45 - z))
                          + (float)((float)((float)v44 * (float)v44) + (float)((float)v43 * (float)v43)))
                  - (float)v46);
    __asm { fsel      f9, f11, f9, f13 }
    v50 = __frsqrte(_FP9);
    v51 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v50
                                                                                        * (float)((float)((float)((float)v47 * (float)v47) + (float)((float)((float)v44 * (float)v44) + (float)((float)v43 * (float)v43)))
                                                                                                * (float)0.5))
                                                                                * (float)v50)
                                                                        - (float)1.5)
                                                        * (float)v50)
                                                * (float)((float)((float)((float)v47 * (float)v47)
                                                                + (float)((float)((float)v44 * (float)v44)
                                                                        + (float)((float)v43 * (float)v43)))
                                                        * (float)0.5))
                                        * (float)((float)-(float)((float)((float)((float)v50
                                                                                * (float)((float)((float)((float)v47 * (float)v47)
                                                                                                + (float)((float)((float)v44 * (float)v44) + (float)((float)v43 * (float)v43)))
                                                                                        * (float)0.5))
                                                                        * (float)v50)
                                                                - (float)1.5)
                                                * (float)v50))
                                - (float)1.5)
                * (float)((float)-(float)((float)((float)((float)v50
                                                        * (float)((float)((float)((float)v47 * (float)v47)
                                                                        + (float)((float)((float)v44 * (float)v44)
                                                                                + (float)((float)v43 * (float)v43)))
                                                                * (float)0.5))
                                                * (float)v50)
                                        - (float)1.5)
                        * (float)v50));
    v52 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v50 * (float)((float)((float)((float)v47 * (float)v47) + (float)((float)((float)v44 * (float)v44) + (float)((float)v43 * (float)v43))) * (float)0.5)) * (float)v50) - (float)1.5)
                                                                                                * (float)v50)
                                                                                        * (float)((float)((float)((float)v47 * (float)v47) + (float)((float)((float)v44 * (float)v44) + (float)((float)v43 * (float)v43)))
                                                                                                * (float)0.5))
                                                                                * (float)((float)-(float)((float)((float)((float)v50 * (float)((float)((float)((float)v47 * (float)v47) + (float)((float)((float)v44 * (float)v44) + (float)((float)v43 * (float)v43))) * (float)0.5)) * (float)v50) - (float)1.5)
                                                                                        * (float)v50))
                                                                        - (float)1.5)
                                                        * (float)((float)-(float)((float)((float)((float)v50
                                                                                                * (float)((float)((float)((float)v47 * (float)v47) + (float)((float)((float)v44 * (float)v44) + (float)((float)v43 * (float)v43))) * (float)0.5))
                                                                                        * (float)v50)
                                                                                - (float)1.5)
                                                                * (float)v50))
                                                * (float)((float)((float)((float)v47 * (float)v47)
                                                                + (float)((float)((float)v44 * (float)v44)
                                                                        + (float)((float)v43 * (float)v43)))
                                                        * (float)0.5))
                                        * (float)v51)
                                - (float)1.5)
                * (float)v51);
    v53 = (float)((float)v43 * (float)v52);
    v56 = (float)((float)(v69 * (float)((float)v44 * (float)v52)) + (float)(v68 * (float)((float)v43 * (float)v52)));
    v54 = (float)((float)v44 * (float)v52);
    v55 = (float)((float)((float)v45 - z) * (float)v52);
    v57 = (float)((float)(v73 * (float)v55) + (float)((float)(v72 * (float)v54) + (float)(v71 * (float)v53)));
    v58 = (float)((float)(v70 * (float)v55) + (float)v56);
    _FP8 = (float)((float)((float)((float)v58 * (float)v58) + (float)((float)v57 * (float)v57)) - (float)v46);
    __asm { fsel      f6, f8, f9, f13 }
    v61 = __frsqrte(_FP6);
    v62 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v61
                                                                                        * (float)((float)((float)((float)v58 * (float)v58) + (float)((float)v57 * (float)v57))
                                                                                                * (float)0.5))
                                                                                * (float)v61)
                                                                        - (float)1.5)
                                                        * (float)v61)
                                                * (float)((float)((float)((float)v58 * (float)v58)
                                                                + (float)((float)v57 * (float)v57))
                                                        * (float)0.5))
                                        * (float)((float)-(float)((float)((float)((float)v61
                                                                                * (float)((float)((float)((float)v58 * (float)v58)
                                                                                                + (float)((float)v57 * (float)v57))
                                                                                        * (float)0.5))
                                                                        * (float)v61)
                                                                - (float)1.5)
                                                * (float)v61))
                                - (float)1.5)
                * (float)((float)-(float)((float)((float)((float)v61
                                                        * (float)((float)((float)((float)v58 * (float)v58)
                                                                        + (float)((float)v57 * (float)v57))
                                                                * (float)0.5))
                                                * (float)v61)
                                        - (float)1.5)
                        * (float)v61));
    hudInfo->damageLocator.direction.x = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v61 * (float)((float)((float)((float)v58 * (float)v58) + (float)((float)v57 * (float)v57)) * (float)0.5)) * (float)v61) - (float)1.5) * (float)v61) * (float)((float)((float)((float)v58 * (float)v58) + (float)((float)v57 * (float)v57)) * (float)0.5)) * (float)((float)-(float)((float)((float)((float)v61 * (float)((float)((float)((float)v58 * (float)v58) + (float)((float)v57 * (float)v57)) * (float)0.5)) * (float)v61) - (float)1.5) * (float)v61)) - (float)1.5)
                                                                                       * (float)((float)-(float)((float)((float)((float)v61 * (float)((float)((float)((float)v58 * (float)v58) + (float)((float)v57 * (float)v57)) * (float)0.5)) * (float)v61) - (float)1.5)
                                                                                               * (float)v61))
                                                                               * (float)((float)((float)((float)v58 * (float)v58)
                                                                                               + (float)((float)v57 * (float)v57))
                                                                                       * (float)0.5))
                                                                       * (float)v62)
                                                               - (float)1.5)
                                               * (float)v62)
                                       * (float)v57;
    hudInfo->damageLocator.direction.y = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v61 * (float)((float)((float)((float)v58 * (float)v58) + (float)((float)v57 * (float)v57)) * (float)0.5)) * (float)v61) - (float)1.5) * (float)v61) * (float)((float)((float)((float)v58 * (float)v58) + (float)((float)v57 * (float)v57)) * (float)0.5)) * (float)((float)-(float)((float)((float)((float)v61 * (float)((float)((float)((float)v58 * (float)v58) + (float)((float)v57 * (float)v57)) * (float)0.5)) * (float)v61) - (float)1.5) * (float)v61)) - (float)1.5)
                                                                                       * (float)((float)-(float)((float)((float)((float)v61 * (float)((float)((float)((float)v58 * (float)v58) + (float)((float)v57 * (float)v57)) * (float)0.5)) * (float)v61) - (float)1.5)
                                                                                               * (float)v61))
                                                                               * (float)((float)((float)((float)v58 * (float)v58)
                                                                                               + (float)((float)v57 * (float)v57))
                                                                                       * (float)0.5))
                                                                       * (float)v62)
                                                               - (float)1.5)
                                               * (float)v62)
                                       * (float)v58;
    LODWORD(v63) = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED)
                 - this->damageImpulseTime;
    if ( (int)v63 < 500 )
    {
      HIDWORD(v63) = byte_821B0000;
      hudInfo->damageLocator.intensity = -(float)((float)((float)v63 * (float)0.0020000001) - (float)1.0);
    }
  }
  if ( this->hudState == HUDSTATE_ALL )
    idPlayerHud::UpdateJobStatus(this, hudInfo);
}


// ========================================================================
// ?AddCombiner@idPlayerHud@@QAAXPAVidEntity@@@Z
// EA  : 0x82E4DDF8
// RVA : 0x00E4DDF8
// PDB : w:\tech5\tungsten\game\player\playerhud.cpp
// ========================================================================

void __fastcall idPlayerHud::AddCombiner(idPlayerHud *this, idEntity *ent)
{
  idEntityPtr<idEntity> v2; // [sp+50h] [-10h] BYREF

  if ( this->combinerTargets.num != this->combinerTargets.size )
  {
    if ( ent != nullptr )
      v2.spawnId.value = (gameLocal->spawnIds.ptr[ent->entityNumber] << 13) | ent->entityNumber;
    else
      v2.spawnId.value = 0x1FFF;
    idList<idEntityPtr<idEntity>,58>::Append(this: (idList<idEntityPtr<idEntity>,58> *)&this->combinerTargets, obj: &v2);
  }
}


// ========================================================================
// ?UpdateJob@idPlayerHud@@QAAXPBVidDeclJob@@H_N1@Z
// EA  : 0x82E4DF78
// RVA : 0x00E4DF78
// PDB : w:\tech5\tungsten\game\player\playerhud.cpp
// ========================================================================

void __fastcall idPlayerHud::UpdateJob(
        idPlayerHud *this,
        const idDeclJob *jobDecl,
        int requirementNum,
        bool playSound,
        bool treatAsSameStatusUpdate)
{
  idPlayer *player; // r9
  idJob *JobByDecl; // r3
  idJob *currentJob; // r11
  idPlayerHud::updateJobInfo_t v13; // [sp+50h] [-70h] BYREF
  idPlayerHud::updateJobInfo_t v14[4]; // [sp+70h] [-50h] BYREF

  if ( jobDecl != nullptr )
  {
    if ( (unsigned __int8)idDeclJob::UseDynamicJobHud(this: jobDecl) != 0 )
    {
      JobByDecl = idJobManager::FindJobByDecl(this: &this->player->jobManager, jobDecl);
      if ( this->dynamicJob == JobByDecl )
      {
        this->dynamicJobPlaySound = playSound;
        this->dynamicJobTreatUpdateAsSameStatus = treatAsSameStatusUpdate;
      }
      else if ( JobByDecl != nullptr && !this->ignoreJobUpdates )
      {
        v14[0].jobDecl = jobDecl;
        v14[0].requiredNum = requirementNum;
        v14[0].fakeJobName.index = -1;
        v14[0].fakeJob = false;
        v14[0].fakeJobObj.index = -1;
        v14[0].playSound = playSound;
        v14[0].treatAsSameStatusUpdate = treatAsSameStatusUpdate;
        idList<idPlayerHud::updateJobInfo_t,5>::AddUnique(this: &this->dynamicJobUpdateQueue, obj: v14);
      }
    }
    else if ( !this->ignoreJobUpdates && !idDeclJob::IsJobHidden(this: jobDecl) )
    {
      currentJob = this->currentJob;
      if ( currentJob != nullptr && currentJob->decl == jobDecl )
      {
        this->currentRequirement = requirementNum;
        this->jobStartShowTime = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        this->currentJobPlaySound = playSound;
        this->currentJobTreatUpdateAsSameStatus = treatAsSameStatusUpdate;
      }
      else
      {
        v14[0].jobDecl = jobDecl;
        v14[0].requiredNum = requirementNum;
        v14[0].fakeJobName.index = -1;
        v14[0].fakeJob = false;
        v14[0].fakeJobObj.index = -1;
        v14[0].playSound = playSound;
        v14[0].treatAsSameStatusUpdate = treatAsSameStatusUpdate;
        idList<idPlayerHud::updateJobInfo_t,5>::AddUnique(this: &this->jobUpdateQueue, obj: v14);
      }
    }
  }
  else if ( this->jobUpdateQueue.num == 0 )
  {
    player = this->player;
    v13.jobDecl = nullptr;
    v13.requiredNum = -1;
    v13.playSound = false;
    v13.treatAsSameStatusUpdate = false;
    v13.fakeJobName.index = -1;
    v13.fakeJobObj.index = -1;
    v13.fakeJob = true;
    if ( (unsigned __int8)idLobbyBackend360::StartArbitration(pexcept: (_exception *)&player->jobManager) != 0 )
      idList<idPlayerHud::updateJobInfo_t,5>::AddUnique(this: &this->jobUpdateQueue, obj: &v13);
  }
}


// ========================================================================
// ?Think@idPlayerHud@@QAAXXZ
// EA  : 0x82E4E140
// RVA : 0x00E4E140
// PDB : w:\tech5\tungsten\game\player\playerhud.cpp
// ========================================================================

void __fastcall idPlayerHud::Think(idPlayerHud *this)
{
  unsigned __int64 v2; // r6
  const char *v3; // r7
  idPresentablePlayer *presPlayer; // r3
  idEntity *v5; // r3
  __int64 v6; // r10
  __int64 v7; // r8
  int v8; // r6
  idPresentablePlayer *v9; // r3
  idUCmdTracker *p_ucmdTracker1; // r29
  BOOL allowWeaponChange; // r9
  idPLogScope v12[6]; // [sp+50h] [-30h] BYREF

  RD_EventBegin(name: "idPlayerHud::Think");
  LODWORD(v2) = "idPlayerHud::Think";
  HIDWORD(v2) = 2;
  idPLogScope::idPLogScope(this: v12, pl: &pLog, gMask: v2, label: v3);
  presPlayer = this->presPlayer;
  if ( presPlayer != nullptr )
  {
    if ( gameLocal->spawnIds.ptr[this->minigameEntity.spawnId.value & 0x1FFF] == this->minigameEntity.spawnId.value >> 13
      && idPresentablePlayer::GetLocalView(this: presPlayer)->hudRender.minigameResult > 0 )
    {
      v5 = idEntityPtr<idEntity const>::operator->(this: &this->minigameEntity);
      idEventReceiver::PostEventMS(this: v5, ev: &EV_MinigameSuccess, time: 0, a4: v8, a5: v7, a6: v6);
      this->minigameEntity.spawnId.value = 0x1FFF;
    }
    if ( g_showHud.valueInteger != 0 )
    {
      v9 = this->presPlayer;
      p_ucmdTracker1 = &v9->ucmdTracker1;
      this->gameInhibited = *((_BYTE *)&v9->ucmdTracker1.usercmd + 9) >> 7;
      if ( !idPresentablePlayer::GuiIsActive(this: v9, g: GUI_TUTORIAL) || this->presPlayer->ignoreTutorialPause )
      {
        allowWeaponChange = this->allowWeaponChange;
        this->prevChangeVisible = this->playerChangeWeapon;
        if ( allowWeaponChange && idPresentablePlayer::GetControl(this: this->presPlayer) == nullptr )
          this->playerChangeWeapon = idUCmdTracker::IsPressedForMenu(this: p_ucmdTracker1, mask: 64);
      }
    }
  }
  idPLogScope::~idPLogScope(this: v12);
  RD_EventEnd();
}


// ========================================================================
// __unwind$491974
// EA  : 0x82E4E2A8
// RVA : 0x00E4E2A8
// PDB : w:\tech5\tungsten\game\player\playerhud.cpp
// ========================================================================

void _unwind_491974()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 128 + 88));
}


// ========================================================================
// __unwind$491975
// EA  : 0x82E4E2D0
// RVA : 0x00E4E2D0
// PDB : w:\tech5\tungsten\game\player\playerhud.cpp
// ========================================================================

void _unwind_491975()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 128 + 80));
}


// ========================================================================
// ?Update@idPlayerHud@@QAAXAAVidHudInfo@@@Z
// EA  : 0x82E4E2F8
// RVA : 0x00E4E2F8
// PDB : w:\tech5\tungsten\game\player\playerhud.cpp
// ========================================================================

void __fastcall idPlayerHud::Update(idPlayerHud *this, idHudInfo *hudInfo)
{
  bool showBottomBar; // r11
  int value; // r6
  idAI2 *v6; // r3
  unsigned __int8 *v7; // r3
  idHudBossInfo *v8; // r29
  idView *p_view; // r3
  bool v10; // zf
  idPlayer *entity; // r3
  double v12; // fp3
  double v13; // fp2
  double v14; // fp1
  idMinigame *v15; // r3
  idMinigame *v16; // r3
  idPresentablePlayer *presPlayer; // r3
  char v18; // [sp+50h] [-50h] BYREF

  if ( this->presPlayer != nullptr )
  {
    showBottomBar = false;
    if ( !this->restrictedGameplay )
      showBottomBar = this->showBottomBar;
    hudInfo->showBottomBar = showBottomBar;
    hudInfo->help = this->helpInfo;
    value = gameLocal->bossEntity.spawnId.value;
    if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
      && (v6 = (idAI2 *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr
      && (v7 = (unsigned __int8 *)idAI2::CastTo(c: v6), v8 = (idHudBossInfo *)v7, v7 != nullptr)
      && (unsigned __int8)Get_idCombatStage_useRelaxedChatterVO(ptr: v7) == 0 )
    {
      hudInfo->boss = (idHudBossInfo)idAI2::GetBossHudInfo(this: (idAI2 *)&v18, result: v8)->idEventReceiver;
    }
    else
    {
      hudInfo->boss.numBars = 0;
    }
    hudInfo->reticle.show = false;
    hudInfo->airSupply.show = false;
    hudInfo->showJournalIcon = false;
    hudInfo->reticle.iconIndex = -1;
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&hudInfo->interact);
    if ( g_showHud.valueInteger != 0 && this->hudState >= (unsigned int)HUDSTATE_DAMAGE )
    {
      if ( common->IsMultiplayer(this: common) || !common->IsMainMenuActive(this: common) )
      {
        if ( this->mainMenuActive )
        {
          entity = (idPlayer *)this->presPlayer->entity;
          if ( entity != nullptr )
          {
            if ( idPlayer::GetInventoryGuiActive(this: entity) )
            {
              v12 = 0.0;
              v13 = 1.0;
              v14 = 1.0;
            }
            else
            {
              v13 = 0.0;
              v12 = 250.0;
              v14 = 1.0;
            }
            idView::ForceBlurValues(this: &this->presPlayer->view, blurBegin: v14, blurEnd: v13, blurTime: v12);
          }
          this->mainMenuActive = false;
        }
        hudInfo->minigame.type = -1;
        hudInfo->minigame.level = -1;
        hudInfo->minigame.action = 0;
        if ( this->newMinigame )
        {
          if ( gameLocal->spawnIds.ptr[this->minigameEntity.spawnId.value & 0x1FFF] == this->minigameEntity.spawnId.value >> 13 )
          {
            v15 = (idMinigame *)idEntityPtr<idEntity const>::operator->(this: &this->minigameEntity);
            v16 = idMinigame::CastTo(c: v15);
            hudInfo->minigame.action = 1;
            hudInfo->minigame.type = v16->gameType;
            hudInfo->minigame.level = v16->gameLevel;
            hudInfo->minigame.showHelp = v16->showHelp;
          }
          else
          {
            hudInfo->minigame.action = 2;
          }
          this->newMinigame = false;
        }
        presPlayer = this->presPlayer;
        if ( presPlayer != nullptr && idPresentablePlayer::GetVehicle(this: presPlayer) != nullptr )
          idPlayerHud::UpdateForVehicle(this, hudInfo);
        else
          idPlayerHud::UpdateForFoot(this, hudInfo);
      }
      else if ( !this->mainMenuActive )
      {
        v10 = !idPlayer::GetInventoryGuiActive(this: (idPlayer *)this->presPlayer->entity);
        p_view = &this->presPlayer->view;
        if ( v10 )
          idView::ForceBlurValues(this: p_view, blurBegin: 1.0, blurEnd: 1.0, blurTime: 0.0);
        else
          idView::ForceBlurValues(this: p_view, blurBegin: 1.5, blurEnd: 1.5, blurTime: 0.0);
        this->mainMenuActive = true;
      }
    }
  }
}


// ========================================================================
// ?AddWatchTarget@idPlayerHud@@QAAXPAVidEntity@@@Z
// EA  : 0x82E4E5F8
// RVA : 0x00E4E5F8
// PDB : w:\tech5\tungsten\game\player\playerhud.cpp
// ========================================================================

void __fastcall idPlayerHud::AddWatchTarget(idPlayerHud *this, idEntity *target)
{
  idEntityPtr<idAI2> *v3; // r3

  v3 = idList<idEntityPtr<idAI2>,5>::Alloc(this: (idList<idEntityPtr<idAI2>,5> *)&this->hudWatchTargets);
  if ( target != nullptr )
    v3->spawnId.value = (gameLocal->spawnIds.ptr[target->entityNumber] << 13) | target->entityNumber;
  else
    v3->spawnId.value = 0x1FFF;
}


// ========================================================================
// ?PickUp@idPlayerHud@@QAAXABVidStr@@_NH_NVidStrId@@H2@Z
// EA  : 0x82E4E7F0
// RVA : 0x00E4E7F0
// PDB : w:\tech5\tungsten\game\player\playerhud.cpp
// ========================================================================

void __fastcall idPlayerHud::PickUp(
        idPlayerHud *this,
        const idStr *icon,
        const bool isWeapon,
        int count,
        bool special,
        idStrId *displayName,
        int itemType,
        bool newItem)
{
  int v16; // r10
  idHudPickupInfo *list; // r9
  int v18; // r11
  int index; // r6
  idHudPickupInfo *v20; // r8
  idPresentablePlayer *presPlayer; // r3
  bool v22; // r29
  int len; // r30
  int v24; // r11
  int num; // [sp+50h] [-C0h]
  idHudPickupInfo v26[2]; // [sp+60h] [-B0h] BYREF

  if ( !this->ignorePickupUpdates )
  {
    v16 = 0;
    num = this->pickupList.num;
    if ( num <= 0 )
    {
LABEL_6:
      presPlayer = this->presPlayer;
      v22 = false;
      if ( presPlayer != nullptr )
        v22 = idPresentablePlayer::GetVehicle(this: presPlayer) != nullptr;
      idHudPickupInfo::idHudPickupInfo(this: v26);
      len = icon->len;
      idStr::EnsureAlloced(this: &v26[0].icon, amount: icon->len + 1, keepold: false, geometricGrowth: false);
      memcpy(Dst: v26[0].icon.data, Src: icon->data, Size: len);
      v26[0].icon.data[len] = 0;
      v26[0].displayName = (idStrId)displayName->index;
      v26[0].icon.len = len;
      v26[0].count = count;
      *(_BYTE *)v26 = (4 * ((2 * v22) & 2 | newItem & 0xFD)) & 0xC
                    | (32 * special) & 0x20
                    | (isWeapon << 6) & 0x40
                    | *(_BYTE *)v26 & 0x93;
      if ( itemType == 1 )
      {
        v26[0].itemType = 0;
      }
      else
      {
        if ( itemType == 2 || itemType == 6 || itemType == 7 )
        {
          v24 = 1;
        }
        else if ( itemType == 4 || itemType == 3 )
        {
          v24 = 2;
        }
        else
        {
          v24 = 3;
        }
        v26[0].itemType = v24;
      }
      idList<idHudPickupInfo,5>::Append(this: &this->pickupList, obj: v26);
      idStr::FreeData(this: &v26[0].icon);
    }
    else
    {
      list = this->pickupList.list;
      v18 = 0;
      index = displayName->index;
      v20 = list;
      while ( v20->displayName.index != index )
      {
        ++v16;
        v20 = &list[++v18];
        if ( v16 >= num )
          goto LABEL_6;
      }
      list[v16].count += count;
    }
  }
}


// ========================================================================
// __unwind$492351_0
// EA  : 0x82E4E990
// RVA : 0x00E4E990
// PDB : w:\tech5\tungsten\game\player\playerhud.cpp
// ========================================================================

void _unwind_492351_0()
{
  int v0; // r12

  idHudPickupInfo::~idHudPickupInfo(this: (idHudPickupInfo *)(v0 - 272 + 96));
}


// ========================================================================
// `dynamic initializer for 'swf_scopeZoomDistance''
// EA  : 0x8338EB98
// RVA : 0x0138EB98
// PDB : w:\tech5\tungsten\game\player\playerhud.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__swf_scopeZoomDistance__()
{
  idCVar::idCVar(
    this: &swf_scopeZoomDistance,
    name: "swf_scopeZoomDistance",
    value: "32768.0f",
    flags: 4,
    description: "distance check for scope UIs",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__swf_scopeZoomDistance__);
}


// ========================================================================
// `dynamic initializer for 'swf_jobnav_mindist''
// EA  : 0x8338EBF0
// RVA : 0x0138EBF0
// PDB : w:\tech5\tungsten\game\player\playerhud.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__swf_jobnav_mindist__()
{
  idCVar::idCVar(
    this: &swf_jobnav_mindist,
    name: "swf_jobnav_mindist",
    value: "100.0f",
    flags: 4,
    description: "if nav ent is below this distance don't show nav aid.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__swf_jobnav_mindist__);
}

