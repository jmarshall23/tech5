
// ========================================================================
// ?ShouldExecuteOnInstigator@idClientGameMsg_HandsThrow@@UAA_NXZ
// EA  : 0x82B586F0
// RVA : 0x00B586F0
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_reliable.cpp
// ========================================================================

BOOL __fastcall idClientGameMsg_HandsThrow::ShouldExecuteOnInstigator(idClientGameMsg_HandsThrow *this)
{
  return this->throwType == HANDS_THROW_RELEASE || common->IsServer(this: common);
}


// ========================================================================
// ?ExecuteReliableClientGameMsg@idClientGame@@QAAXAAVidClientGameMsg@@@Z
// EA  : 0x82B587B8
// RVA : 0x00B587B8
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_reliable.cpp
// ========================================================================

void __fastcall idClientGame::ExecuteReliableClientGameMsg(idClientGame *this, idClientGameMsg *gameMsg)
{
  gameReliable_t v3; // r3

  if ( cg_reliable_debug.valueInteger != 0 )
  {
    v3 = gameMsg->GetMsgType(this: gameMsg);
    idLib::Printf(fmt: "^4Executing^7 reliable ClientGameMsg %d \n     ", v3);
    gameMsg->PrintDebug(this: gameMsg);
  }
  gameMsg->Execute(this: gameMsg);
}


// ========================================================================
// ?Execute@idClientGameMsg_DropItem@@UAAXXZ
// EA  : 0x82B58848
// RVA : 0x00B58848
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_reliable.cpp
// ========================================================================

void __fastcall idClientGameMsg_DropItem::Execute(idClientGameMsg_DropItem *this)
{
  idPlayer *Player; // r3
  _DWORD *v3; // r28
  int playerNumber; // r30
  gameReliable_t v5; // r3
  const idDeclInventory *itemDecl; // r30
  idJobManager *v7; // r3
  idJob *JobByDecl; // r30
  int v9; // r21
  int v10; // r3
  float *v11; // r3
  int v12; // r11
  double v13; // fp30
  double v14; // fp29
  double v15; // fp28
  float *v16; // r3
  double v17; // fp10
  double v18; // fp9
  int v19; // r25
  const idDeclInventory *v20; // r11
  const char *str; // r4
  int v22; // r26
  idClientGameMsg_DropItem::ammoTransfer_t *ammoTransfers; // r27
  int v24; // r3
  idPresentable *v25; // r30
  const idDeclInventory *ammoDecl; // r29
  int count; // r20
  idInventoryCollection *v28; // r3
  const idDeclJob *v29; // r30
  idJobManager *v30; // r3
  idInventoryItem *v31; // r30
  int v32; // r3
  idPresentable *v33; // r29
  int v34; // r20
  idInventoryCollection *v35; // r3
  float v36[12]; // [sp+58h] [-98h] BYREF

  Player = idGameLocal::GetPlayer(this: gameLocal, i: this->playerNumber);
  v3 = &Player->__vftable;
  if ( Player != nullptr )
  {
    itemDecl = this->itemDecl;
    v7 = (idJobManager *)Player->GetInventory_2(this: Player);
    JobByDecl = idJobManager::FindJobByDecl(this: v7, jobDecl: (const idDeclJob *)itemDecl);
    if ( JobByDecl != nullptr )
    {
      v9 = (*(int (__fastcall **)(_DWORD *))(*v3 + 468))(a1: v3);
      *(_BYTE *)(v9 + 796) = 0;
      v10 = v3[122];
      if ( v10 != 0 )
        v11 = (float *)(*(int (__fastcall **)(int))(*(_DWORD *)v10 + 104))(a1: v10);
      else
        v11 = nullptr;
      v12 = v3[122];
      v13 = (float)(v11[11644] * (float)10.0);
      v14 = (float)(v11[11643] * (float)10.0);
      v15 = (float)(v11[11642] * (float)10.0);
      if ( v12 != 0 )
        v16 = (float *)(*(int (__fastcall **)(_DWORD))(*(_DWORD *)v12 + 104))(a1: v3[122]);
      else
        v16 = nullptr;
      v17 = (float)(v16[11637] * (float)10.0);
      v18 = (float)(v16[11636] * (float)10.0);
      v36[2] = (float)(v16[11638] * (float)10.0) + (float)v13;
      v36[1] = (float)v17 + (float)v14;
      v36[0] = (float)v18 + (float)v15;
      v19 = (*(int (__fastcall **)(_DWORD *, idJob *, int, int, int, idVec3 *, float *))(*v3 + 736))(
              a1: v3,
              a2: JobByDecl,
              a3: 1,
              a4: 1,
              a5: 1,
              a6: &vec3_origin,
              a7: v36);
      if ( v19 == 0 )
      {
        v20 = this->itemDecl;
        if ( v20 != nullptr )
          str = v20->name.str;
        else
          str = "NULL";
        idLib::Warning(
          fmt: "idClientGameMsg_DropItem unable to spawn drop item. %s player: %d ",
          str,
          this->playerNumber);
      }
      v22 = 0;
      if ( this->numAmmoTransfers > 0 )
      {
        ammoTransfers = this->ammoTransfers;
        do
        {
          if ( ammoTransfers->ammoDecl != nullptr )
          {
            if ( v19 != 0 )
            {
              v24 = v3[122];
              if ( v24 != 0 )
                v25 = (idPresentable *)(*(int (__fastcall **)(int))(*(_DWORD *)v24 + 104))(a1: v24);
              else
                v25 = nullptr;
              ammoDecl = ammoTransfers->ammoDecl;
              count = ammoTransfers->count;
              v28 = (idInventoryCollection *)(*(int (__fastcall **)(int))(*(_DWORD *)v19 + 468))(a1: v19);
              idInventoryCollection::GiveItem(
                this: v28,
                owner: v25,
                decl: ammoDecl,
                count,
                forceCount: true,
                canIntro: false);
            }
            v29 = (const idDeclJob *)ammoTransfers->ammoDecl;
            v30 = (idJobManager *)(*(int (__fastcall **)(_DWORD *))(*v3 + 468))(a1: v3);
            v31 = (idInventoryItem *)idJobManager::FindJobByDecl(this: v30, jobDecl: v29);
            if ( v31 != nullptr )
            {
              v32 = v3[122];
              if ( v32 != 0 )
                v33 = (idPresentable *)(*(int (__fastcall **)(int))(*(_DWORD *)v32 + 104))(a1: v32);
              else
                v33 = nullptr;
              v34 = v31->GetCount(this: v31);
              v35 = (idInventoryCollection *)(*(int (__fastcall **)(_DWORD *))(*v3 + 468))(a1: v3);
              idInventoryCollection::DeleteInventoryItem(this: v35, owner: v33, item: v31, count: v34);
            }
          }
          else
          {
            idLib::Warning(fmt: "idClientGameMsg_DropItem unusable ammoDecl ");
          }
          ++v22;
          ++ammoTransfers;
        }
        while ( v22 < this->numAmmoTransfers );
      }
      *(_BYTE *)(v9 + 796) = 1;
    }
    else
    {
      idLib::Warning(
        fmt: "idClientGameMsg_DropItem item %s not in player %d's inventory. ",
        this->itemDecl->name.str,
        this->playerNumber);
    }
  }
  else
  {
    playerNumber = this->playerNumber;
    v5 = this->GetMsgType(this);
    idLib::Warning(fmt: "Invalid player for client game msg %d. playerNumber: %d ", v5, playerNumber);
    this->PrintDebug(this);
  }
}


// ========================================================================
// __unwind$489715_1
// EA  : 0x82B58B9C
// RVA : 0x00B58B9C
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_reliable.cpp
// ========================================================================

void _unwind_489715_1()
{
  int v0; // r12

  idInventorySerializeLock::~idInventorySerializeLock(this: (idInventorySerializeLock *)(v0 - 240 + 80));
}


// ========================================================================
// ?PrintDebug@idClientGameMsg_DropItem@@UAAXXZ
// EA  : 0x82B58BC8
// RVA : 0x00B58BC8
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_reliable.cpp
// ========================================================================

void __fastcall idClientGameMsg_DropItem::PrintDebug(idClientGameMsg_DropItem *this)
{
  const idDeclInventory *itemDecl; // r11
  const char *str; // r5
  int v4; // r31
  int *p_playerNumber; // r30
  int v6; // r11
  const char *v7; // r5

  itemDecl = this->itemDecl;
  if ( itemDecl != nullptr )
    str = itemDecl->name.str;
  else
    str = "NULL";
  idLib::Printf(
    fmt: "idClientGameMsg_DropItem. Player: %d. Item: %s. numAmmoTransfers: %d \n",
    this->playerNumber,
    str,
    this->numAmmoTransfers);
  v4 = 0;
  if ( this->numAmmoTransfers > 0 )
  {
    p_playerNumber = &this->playerNumber;
    do
    {
      v6 = p_playerNumber[1];
      if ( v6 != 0 )
        v7 = *(const char **)(v6 + 8);
      else
        v7 = "NULL";
      p_playerNumber += 2;
      idLib::Printf(fmt: "     Transfer[%d]. AmmoDel: %s Count: %d \n", v4++, v7, *p_playerNumber);
    }
    while ( v4 < this->numAmmoTransfers );
  }
}


// ========================================================================
// ?GetRealStartTime@idClientGameMsg_HandsThrow@@AAAHPAVidPresentablePlayer@@@Z
// EA  : 0x82B58C68
// RVA : 0x00B58C68
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_reliable.cpp
// ========================================================================

int __fastcall idClientGameMsg_HandsThrow::GetRealStartTime(
        idClientGameMsg_HandsThrow *this,
        idPresentablePlayer *player)
{
  int startTime; // r29
  int v5; // r28
  int v6; // r27
  int GameMs; // r3

  startTime = this->startTime;
  if ( player->IsLocallyControlled(this: player) )
    return startTime;
  v5 = this->startTime - idPresentablePlayer::GetPlayerGameTime(this: player);
  v6 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) + v5;
  if ( cg_reliable_debug.valueInteger != 0 )
  {
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    idLib::Printf(
      fmt: "idClientGameMsg_HandsThrow::ThrowItem. startTime: %d. Delta: %d. GameTime: %d realStartTime: %d \n",
      this->startTime,
      v5,
      GameMs,
      v6);
    clientGame->renderWorld->DebugAxis_2(
      this: clientGame->renderWorld,
      a2: &this->fp.start,
      a3: &this->fp.fireAxis,
      a4: 10000,
      a5: false);
  }
  return v6;
}


// ========================================================================
// ?PrintDebug@idClientGameMsg_HandsThrow@@UAAXXZ
// EA  : 0x82B58D50
// RVA : 0x00B58D50
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_reliable.cpp
// ========================================================================

void __fastcall idClientGameMsg_HandsThrow::PrintDebug(idClientGameMsg_HandsThrow *this)
{
  idClientGameMsg_HandsThrow::clientGameMsgHandsThrow_t throwType; // r5
  const idDeclThrowable *throwItem; // r11
  const char *str; // r30
  const idDeclThrowable *v5; // r11
  const char *v6; // r6
  idMat3 v7; // [sp+80h] [-30h] BYREF

  throwType = this->throwType;
  if ( throwType == HANDS_THROW_RELEASE )
  {
    idMat3::ToAngles(this: &v7, result: (idAngles *)&this->fireAxis);
    throwItem = this->throwItem;
    if ( throwItem != nullptr )
      str = throwItem->name.str;
    else
      str = "NULL";
    idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    idLib::Printf(
      fmt: "idClientGameMsg_HandsThrow. Player: %d. ThrowType: %d (RELEASE) throwItem: %s start: <%.2f, %.2f, %.2f> fireAxis: "
      "<%.2f, %.2f, %.2f> initialSpeed: %.2f startTime: %d clientTime: %d \n",
      this->playerNumber,
      this->throwType,
      str,
      this->start.x,
      this->start.y,
      this->start.z,
      v7.mat[0].x,
      v7.mat[0].y,
      v7.mat[0].z,
      this->initialSpeed,
      (unsigned int)COERCE_UNSIGNED_INT64(this->start.x),
      (unsigned int)COERCE_UNSIGNED_INT64(this->start.y));
  }
  else
  {
    v5 = this->throwItem;
    if ( v5 != nullptr )
      v6 = v5->name.str;
    else
      v6 = "NULL";
    idLib::Printf(
      fmt: "idClientGameMsg_HandsThrow. Player: %d. ThrowType: %d throwItem: %s \n",
      this->playerNumber,
      throwType,
      v6);
  }
}


// ========================================================================
// ?AddHit@idClientGameMsg_HitScanHit@@QAAXHHHVidVec3@@@Z
// EA  : 0x82B58E60
// RVA : 0x00B58E60
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_reliable.cpp
// ========================================================================

void __fastcall idClientGameMsg_HitScanHit::AddHit(
        idClientGameMsg_HitScanHit *this,
        int entityNumber,
        int jointNumber,
        int bodyId,
        idVec3 *hitPos)
{
  int numHits; // r11
  float *v6; // r11

  numHits = this->numHits;
  if ( (((numHits >= 0) + ((unsigned int)numHits >= 0x18)) & 1) != 0 )
  {
    this->hitInfos[numHits].entityNum = entityNumber;
    this->hitInfos[this->numHits].jointNum = jointNumber;
    v6 = (float *)((char *)this + 24 * this->numHits);
    v6[8] = *(float *)&bodyId;
    v6[9] = *(float *)&hitPos;
    v6[10] = *(float *)&hitPos;
    this->hitInfos[this->numHits++].bodyId = bodyId;
  }
}


// ========================================================================
// ?PrintDebug@idClientGameMsg_PostGameScoreRecap@@UAAXXZ
// EA  : 0x82B58F10
// RVA : 0x00B58F10
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_reliable.cpp
// ========================================================================

void __fastcall idClientGameMsg_PostGameScoreRecap::PrintDebug(idClientGameMsg_PostGameScoreRecap *this)
{
  int v2; // r26
  int v3; // r30
  void (*GetActingGameStateLobbyBase)(void); // ctr
  idClientGameMsg_PostGameScoreRecap::scoreItem_t *v5; // r11
  double floatValue; // fp31
  const char *v7; // r25
  const char *LocalizedString; // r3
  idClientGameMsg_PostGameScoreRecap::scoreItem_t *v9; // r11
  int intValue; // r25
  const char *v11; // r24
  const char *v12; // r3
  int v13; // r24
  int v14; // r29
  idClientGameMsg_PostGameScoreRecap::scoreItem_t *v15; // r30
  const idDeclMetric *metric; // r11
  __int64 v17; // r9
  double v18; // fp30
  double v19; // fp1
  double v20; // fp29
  double v21; // fp30
  const char *v22; // r3
  __int64 v23; // r9
  double v24; // fp30
  double v25; // fp1
  int v26; // r30
  double v27; // fp30
  const char *v28; // r3
  int index; // r31
  idRageMetrics *rageMetrics; // r30
  double v31; // fp31
  double v32; // r4
  idStrId v33; // [sp+50h] [-90h] BYREF
  idStrId v34; // [sp+54h] [-8Ch] BYREF
  idStrId v35; // [sp+58h] [-88h] BYREF
  idStrId v36; // [sp+5Ch] [-84h] BYREF
  __int64 v37; // [sp+60h] [-80h] BYREF
  __int64 v38; // [sp+68h] [-78h]

  idLib::Printf(fmt: "\n^4Post Game Scoring Recap: \n");
  v2 = 0;
  if ( this->items.num > 0 )
  {
    v3 = 0;
    do
    {
      idClientGame::GetLobbyUserIdFromPlayerIndex(
        this: (idClientGame *)&v37,
        result: (lobbyUserID_t *)clientGame,
        playerIndex: this->items.list[v3].playerIndex);
      GetActingGameStateLobbyBase = (void (*)(void))session->GetActingGameStateLobbyBase;
      if ( this->items.list[v3].isFloat )
      {
        GetActingGameStateLobbyBase();
        v5 = &this->items.list[v3];
        v33.index = v5->metric->displayName.index;
        floatValue = v5->floatValue;
        v7 = (const char *)(*(int (__fastcall **)(_DWORD, _DWORD))(*(_DWORD *)HIDWORD(v37) + 40))(
                             a1: HIDWORD(v37),
                             a2: v37);
        LocalizedString = idStrId::GetLocalizedString(this: &v33);
        idLib::Printf(fmt: "   %s: %s: %.2f\n", LocalizedString, v7, floatValue);
      }
      else
      {
        GetActingGameStateLobbyBase();
        v9 = &this->items.list[v3];
        v34.index = v9->metric->displayName.index;
        intValue = v9->intValue;
        v11 = (const char *)(*(int (__fastcall **)(_DWORD, _DWORD))(*(_DWORD *)HIDWORD(v37) + 40))(
                              a1: HIDWORD(v37),
                              a2: v37);
        v12 = idStrId::GetLocalizedString(this: &v34);
        idLib::Printf(fmt: "   %s: %s: %d\n", v12, v11, intValue);
      }
      ++v2;
      ++v3;
    }
    while ( v2 < this->items.num );
  }
  idLib::Printf(fmt: "\n^4Local User XP Awards: \n");
  v13 = 0;
  if ( this->items.num > 0 )
  {
    v14 = 0;
    do
    {
      if ( (unsigned __int8)idClientGame::PlayerIndexIsLocal(
                              this: clientGame,
                              playerNum: this->items.list[v14].playerIndex) != 0 )
      {
        v15 = &this->items.list[v14];
        metric = v15->metric;
        if ( v15->isFloat )
        {
          v35.index = metric->displayName.index;
          LODWORD(v17) = idDeclMetric::GetXPValue(this: v15->metric, delta: 1);
          HIDWORD(v17) = session->__vftable;
          v37 = v17;
          v18 = (float)v17;
          v19 = ((double (__fastcall *)(idSession *, const char *, double))*(_DWORD *)(HIDWORD(v17) + 292))(
                  a1: session,
                  a2: "xp_multiplier",
                  a3: 1.0);
          v20 = v15->floatValue;
          v21 = (float)((float)v19 * (float)v18);
          v22 = idStrId::GetLocalizedString(this: &v35);
          idLib::Printf(fmt: "   %s: %.2f  --->  +%fXP!\n", v22, v20, v21);
        }
        else
        {
          v36.index = metric->displayName.index;
          LODWORD(v23) = idDeclMetric::GetXPValue(this: v15->metric, delta: 1);
          v38 = v23;
          v24 = (float)v23;
          v25 = ((double (__fastcall *)(idSession *, const char *, double))session->GetTitleStorageFloat_2)(
                  a1: session,
                  a2: "xp_multiplier",
                  a3: 1.0);
          v26 = v15->intValue;
          v27 = (float)((float)v25 * (float)v24);
          v28 = idStrId::GetLocalizedString(this: &v36);
          idLib::Printf(fmt: "   %s: %d  --->  +%fXP!\n", v28, v26, v27);
        }
      }
      ++v13;
      ++v14;
    }
    while ( v13 < this->items.num );
  }
  if ( idClientGame::GetLocalPresentablePlayer(this: clientGame) != nullptr )
  {
    index = idClientGame::GetLocalPresentablePlayer(this: clientGame)->index;
    rageMetrics = clientGame->rageMetrics;
    v31 = ((double (__fastcall *)(idSession *, const char *, double))session->GetTitleStorageFloat_2)(
            a1: session,
            a2: "xp_multiplier",
            a3: 1.0);
    v38 = __PAIR64__(
            &off_822B0000,
            idRageMetrics::GetSessionStat(this: rageMetrics, playerId: index, stat: RAGE_STAT_SCORE_VDM));
    v32 = (float)((float)v31 * (float)v38);
    idLib::Printf(fmt: (const char *)HIDWORD(v32), LODWORD(v32));
  }
}


// ========================================================================
// ?GetNumAwards@idClientGameMsg_PostGameScoreRecap@@QAAHH@Z
// EA  : 0x82B59278
// RVA : 0x00B59278
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_reliable.cpp
// ========================================================================

int __fastcall idClientGameMsg_PostGameScoreRecap::GetNumAwards(
        idClientGameMsg_PostGameScoreRecap *this,
        int playerNum)
{
  int num; // r10
  int result; // r3
  idClientGameMsg_PostGameScoreRecap::scoreItem_t *list; // r9
  int v6; // r11
  int i; // ctr

  num = this->items.num;
  result = 0;
  if ( num > 0 )
  {
    list = this->items.list;
    v6 = 0;
    for ( i = num; i != 0; --i )
    {
      if ( list[v6].playerIndex == playerNum )
        ++result;
      ++v6;
    }
  }
  return result;
}


// ========================================================================
// ?HandleReliableGameMsg@idClientGame@@QAAXAAVidClientGameMsg@@@Z
// EA  : 0x82B59368
// RVA : 0x00B59368
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_reliable.cpp
// ========================================================================

void __fastcall idClientGame::HandleReliableGameMsg(idClientGame *this, idClientGameMsg *gameMsg)
{
  gameReliable_t v4; // r3
  gameReliable_t v5; // r3
  __int64 v6; // r11
  idLobbyBase *v7; // r30
  idClientGameMsg *v8; // r3
  int peerMask; // r29
  idLobbyBase_vtbl *v10; // r31
  gameReliable_t (__fastcall *GetMsgType)(idClientGameMsg *); // ctr
  int v12; // r3
  char v13[4]; // [sp+50h] [-60h] BYREF
  _DWORD *v14; // [sp+54h] [-5Ch]
  _DWORD v15[7]; // [sp+60h] [-50h] BYREF
  char v16; // [sp+7Ch] [-34h]
  char v17; // [sp+7Dh] [-33h]
  __int64 v18; // [sp+80h] [-30h]

  if ( !gameMsg->IsMPOnly(this: gameMsg) || common->IsMultiplayer(this: common) )
  {
    if ( cg_reliable_debug.valueInteger != 0 )
    {
      v5 = gameMsg->GetMsgType(this: gameMsg);
      idLib::Printf(fmt: "^2HandleReliableGameMsg.^7 Type: %d. \n", v5);
      gameMsg->PrintDebug(this: gameMsg);
    }
    if ( gameMsg->ShouldExecuteOnInstigator(this: gameMsg) )
      idClientGame::ExecuteReliableClientGameMsg(this, gameMsg);
    if ( !common->IsServer(this: common) || gameMsg->ShouldSendServerToClients(this: gameMsg) )
    {
      if ( cg_reliable_debug.valueInteger != 0 )
        idLib::Printf(fmt: "     Sending to peers. \n");
      HIDWORD(v6) = gameMsg->__vftable;
      LODWORD(v6) = 0;
      memset(&v15[3], 0, 16);
      v15[0] = this->reliableMsgBuffer;
      v15[2] = 8000;
      v15[1] = this->reliableMsgBuffer;
      v16 = 0;
      v17 = 0;
      v18 = v6;
      v13[0] = 1;
      v14 = v15;
      (*(void (__fastcall **)(idClientGameMsg *, char *))(HIDWORD(v6) + 4))(a1: gameMsg, a2: v13);
      v7 = session->GetActingGameStateLobbyBase(this: session);
      v8 = gameMsg;
      peerMask = gameMsg->peerMask;
      GetMsgType = gameMsg->GetMsgType;
      v10 = v7->__vftable;
      v12 = GetMsgType(this: v8);
      v10->SendReliable(this: v7, a2: v12, a3: (idBitMsg *)v15, a4: false, a5: peerMask);
    }
  }
  else if ( cg_reliable_debug.valueInteger != 0 )
  {
    v4 = gameMsg->GetMsgType(this: gameMsg);
    idLib::Printf(fmt: "^3Ignoring MP only GameMsg: ^7 Type: %d. \n", v4);
    gameMsg->PrintDebug(this: gameMsg);
  }
}


// ========================================================================
// ??0idClientGameMsg_HitScanHit@@QAA@PAVidPresentable@@PBVidDeclWeapon@@PBVidDeclProjectile@@VidVec3@@@Z
// EA  : 0x82B595B0
// RVA : 0x00B595B0
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_reliable.cpp
// ========================================================================

idClientGameMsg_HitScanHit *__fastcall idClientGameMsg_HitScanHit::idClientGameMsg_HitScanHit(
        idClientGameMsg_HitScanHit *this,
        idPresentable *attacker_,
        const idDeclWeapon *weaponDecl_,
        const idDeclProjectile *projDecl_,
        idVec3 *startPos_)
{
  idPresentablePtr<idPresentable> *p_attacker; // r11
  idClientGameMsg_HitScanHit *v7; // r10
  int i; // ctr

  this->peerMask = -1;
  p_attacker = &this->attacker;
  this->__vftable = (idClientGameMsg_HitScanHit_vtbl *)&idClientGameMsg_HitScanHit::`vftable';
  v7 = this;
  this->attacker.spawnId = 0;
  for ( i = 24; i != 0; --i )
  {
    v7->hitInfos[0].entityNum = 0;
    v7 = (idClientGameMsg_HitScanHit *)((char *)v7 + 24);
    v7->__vftable = nullptr;
  }
  if ( attacker_ != nullptr )
    p_attacker->spawnId = attacker_->spawnId;
  else
    p_attacker->spawnId = 0;
  this->weaponDecl = weaponDecl_;
  this->projDecl = projDecl_;
  this->startPos.x = *(float *)&projDecl_;
  this->startPos.y = *(float *)&startPos_;
  this->startPos.z = *(float *)&startPos_;
  this->numHits = 0;
  this->serverTime = idClientGame::GetServerGameTime(this: clientGame);
  return this;
}


// ========================================================================
// __unwind$490970
// EA  : 0x82B59684
// RVA : 0x00B59684
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_reliable.cpp
// ========================================================================

void _unwind_490970()
{
  int v0; // r12

  idClientGameMsg_MeleeHit::~idClientGameMsg_MeleeHit(this: *(idClientGameMsg_VehicleWeaponChange **)(v0 - 112 + 132));
}


// ========================================================================
// ?ExecuteQueuedClientGameMsgs@idClientGame@@QAAXXZ
// EA  : 0x82B5A378
// RVA : 0x00B5A378
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_reliable.cpp
// ========================================================================

void __fastcall idClientGame::ExecuteQueuedClientGameMsgs(idClientGame *this)
{
  int *p_num; // r26
  int v3; // r30
  int v4; // r31
  idList<idClientGameMsg *,5> *p_queuedReliableMsgs; // r29
  idClientGameMsg *v6; // r4

  p_num = &this->queuedReliableMsgs.num;
  if ( this->queuedReliableMsgs.num > 0 )
  {
    v3 = 0;
    v4 = 0;
    p_queuedReliableMsgs = &this->queuedReliableMsgs;
    do
    {
      v6 = p_queuedReliableMsgs->list[v4];
      if ( v6 != nullptr )
        idClientGame::ExecuteReliableClientGameMsg(this, gameMsg: v6);
      ++v3;
      ++v4;
    }
    while ( v3 < *p_num );
    idList<idTypeInfoSubGraph *,5>::DeleteContents(this: (idList<idTypeInfoGraphLink *,5> *)&this->queuedReliableMsgs);
  }
}


// ========================================================================
// ?Serialize@idClientGameMsg_DropItem@@UAAXAAVidSerializer@@@Z
// EA  : 0x82B5A3F0
// RVA : 0x00B5A3F0
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_reliable.cpp
// ========================================================================

void __fastcall idClientGameMsg_DropItem::Serialize(idClientGameMsg_DropItem *this, idSerializer *ser)
{
  idBitMsg *msg; // r3
  idBitMsg *v5; // r3
  int v6; // r28
  int *p_count; // r31
  idBitMsg *v8; // r3

  msg = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: msg, value: this->playerNumber, numBits: 32);
  else
    this->playerNumber = idBitMsg::ReadBits(this: msg, numBits: 32);
  idSerializer::Serialize<idDeclInventory>(this: ser, decl: &this->itemDecl);
  v5 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v5, value: this->numAmmoTransfers, numBits: 32);
  else
    this->numAmmoTransfers = idBitMsg::ReadBits(this: v5, numBits: 32);
  v6 = 0;
  if ( this->numAmmoTransfers > 0 )
  {
    p_count = &this->ammoTransfers[0].count;
    do
    {
      idSerializer::Serialize<idDeclAmmo>(this: ser, decl: (const idDecl **)p_count - 1);
      v8 = ser->msg;
      if ( ser->writing )
        idBitMsg::WriteBits(this: v8, value: *p_count, numBits: 32);
      else
        *p_count = idBitMsg::ReadBits(this: v8, numBits: 32);
      ++v6;
      p_count += 2;
    }
    while ( v6 < this->numAmmoTransfers );
  }
}


// ========================================================================
// ?Serialize@idClientGameMsg_HandsEquip@@UAAXAAVidSerializer@@@Z
// EA  : 0x82B5A4D0
// RVA : 0x00B5A4D0
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_reliable.cpp
// ========================================================================

void __fastcall idClientGameMsg_HandsEquip::Serialize(idClientGameMsg_HandsEquip *this, idSerializer *ser)
{
  idBitMsg *msg; // r3

  msg = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: msg, value: this->playerNumber, numBits: 32);
  else
    this->playerNumber = idBitMsg::ReadBits(this: msg, numBits: 32);
  idSerializer::Serialize<idDeclInventory>(this: ser, decl: &this->itemDecl);
  idSerializer::Serialize<idDeclAmmo>(this: ser, decl: &this->ammoDecl);
}


// ========================================================================
// ?Serialize@idClientGameMsg_HandsAmmoChange@@UAAXAAVidSerializer@@@Z
// EA  : 0x82B5A548
// RVA : 0x00B5A548
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_reliable.cpp
// ========================================================================

void __fastcall idClientGameMsg_HandsAmmoChange::Serialize(idClientGameMsg_HandsAmmoChange *this, idSerializer *ser)
{
  idBitMsg *msg; // r3
  idBitMsg *v5; // r3
  bool forced; // r29

  msg = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: msg, value: this->playerNumber, numBits: 32);
  else
    this->playerNumber = idBitMsg::ReadBits(this: msg, numBits: 32);
  idSerializer::Serialize<idDeclAmmo>(this: ser, decl: &this->ammoDecl);
  idSerializer::Serialize<idDeclWeapon>(this: ser, decl: &this->weaponDecl);
  v5 = ser->msg;
  forced = this->forced;
  if ( ser->writing )
  {
    idBitMsg::WriteBits(this: v5, value: this->forced, numBits: 1);
    this->forced = forced;
  }
  else
  {
    this->forced = (_cntlzw(idBitMsg::ReadBits(this: v5, numBits: 1) - 1) & 0x20) != 0;
  }
}


// ========================================================================
// ??0idClientGameMsg_HandsThrow@@QAA@HW4clientGameMsgHandsThrow_t@0@PBVidDeclThrowable@@VidVec3@@VidMat3@@MH@Z
// EA  : 0x82B5A5F8
// RVA : 0x00B5A5F8
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_reliable.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
idClientGameMsg_HandsThrow *__fastcall idClientGameMsg_HandsThrow::idClientGameMsg_HandsThrow(
        idClientGameMsg_HandsThrow *this,
        int playerNumber_,
        idClientGameMsg_HandsThrow::clientGameMsgHandsThrow_t throwType_,
        __int64 start_,
        idMat3 *fireAxis_,
        double initialSpeed_,
        __int64 startTime_,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14,
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
        float a33,
        float a34,
        float a35,
        float a36,
        float a37,
        int a38,
        int a39,
        int a40,
        int a41,
        int a42)
{
  const idDeclThrowable *v38; // r25
  idFinishFireResults *p_ffr; // r11
  int i; // ctr
  float v44; // [sp+D8h] [+38h]
  __int64 v45; // [sp+E0h] [+40h]

  v44 = *((float *)&start_ + 1);
  v45 = *(__int64 *)((char *)&startTime_ + 4);
  v38 = (const idDeclThrowable *)HIDWORD(start_);
  this->peerMask = -1;
  this->__vftable = (idClientGameMsg_HandsThrow_vtbl *)&idClientGameMsg_HandsThrow::`vftable';
  idFireParms::idFireParms(this: &this->fp);
  this->tfr.numTraces = 0;
  memset(Dst: this->tfr.traces, Val: 0, Size: sizeof(this->tfr.traces));
  memset(Dst: this->tfr.traceDirs, Val: 0, Size: sizeof(this->tfr.traceDirs));
  memset(Dst: this->tfr.traceLens, Val: 0, Size: sizeof(this->tfr.traceLens));
  this->ffr.numProjectiles = 0;
  p_ffr = &this->ffr;
  for ( i = 16; i != 0; --i )
  {
    p_ffr = (idFinishFireResults *)((char *)p_ffr + 4);
    p_ffr->numProjectiles = 0;
  }
  this->playerNumber = playerNumber_;
  this->throwType = throwType_;
  this->throwItem = v38;
  *(_QWORD *)&this->start.x = start_;
  this->start.z = v44;
  this->fireAxis.mat[0].x = *(float *)&v45;
  this->fireAxis.mat[1].x = *((float *)&startTime_ + 1);
  this->fireAxis.mat[0].y = *((float *)&v45 + 1);
  this->fireAxis.mat[0].z = *(float *)&startTime_;
  this->fireAxis.mat[1].y = a33;
  this->fireAxis.mat[1].z = a34;
  this->fireAxis.mat[2].x = a35;
  this->fireAxis.mat[2].y = a36;
  this->fireAxis.mat[2].z = a37;
  this->startTime = a42;
  this->initialSpeed = initialSpeed_;
  this->serverTime = idClientGame::GetServerGameTime(this: clientGame);
  this->predictedKey = -1;
  return this;
}


// ========================================================================
// __unwind$492362
// EA  : 0x82B5A768
// RVA : 0x00B5A768
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_reliable.cpp
// ========================================================================

void _unwind_492362()
{
  int v0; // r12

  idClientGameMsg_MeleeHit::~idClientGameMsg_MeleeHit(this: *(idClientGameMsg_VehicleWeaponChange **)(v0 - 160 + 180));
}


// ========================================================================
// __unwind$492363
// EA  : 0x82B5A790
// RVA : 0x00B5A790
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_reliable.cpp
// ========================================================================

void _unwind_492363()
{
  int v0; // r12

  idFireParms::~idFireParms(this: (idAI2::idAIVolatile::idAIEventInfo *)(*(_DWORD *)(v0 - 160 + 180) + 8));
}


// ========================================================================
// ?Serialize@idClientGameMsg_HandsThrow@@UAAXAAVidSerializer@@@Z
// EA  : 0x82B5A7C0
// RVA : 0x00B5A7C0
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_reliable.cpp
// ========================================================================

void __fastcall idClientGameMsg_HandsThrow::Serialize(idClientGameMsg_HandsThrow *this, idSerializer *ser)
{
  idBitMsg *msg; // r3
  idBitMsg *v5; // r3
  idClientGameMsg_HandsThrow::clientGameMsgHandsThrow_t throwType; // r29
  idBitMsg *v7; // r3
  unsigned int v8; // r10
  idBitMsg *v9; // r3

  msg = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: msg, value: this->playerNumber, numBits: 32);
  else
    this->playerNumber = idBitMsg::ReadBits(this: msg, numBits: 32);
  idSerializer::Serialize<idDeclThrowable>(this: ser, decl: &this->throwItem);
  v5 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v5, value: this->serverTime, numBits: 32);
  else
    this->serverTime = idBitMsg::ReadBits(this: v5, numBits: 32);
  throwType = this->throwType;
  v7 = ser->msg;
  v8 = _cntlzw(7u);
  if ( ser->writing )
    idBitMsg::WriteBits(this: v7, value: this->throwType, numBits: 32 - v8);
  else
    throwType = idBitMsg::ReadBits(this: v7, numBits: 32 - v8);
  this->throwType = throwType;
  if ( throwType == HANDS_THROW_RELEASE || throwType == HANDS_THROW_DROPONDEATH )
  {
    v9 = ser->msg;
    if ( ser->writing )
      idBitMsg::WriteBits(this: v9, value: this->startTime, numBits: 32);
    else
      this->startTime = idBitMsg::ReadBits(this: v9, numBits: 32);
  }
  if ( this->throwType == HANDS_THROW_RELEASE )
  {
    idSerializer::Serialize(this: ser, value: &this->start);
    idSerializer::Serialize(this: ser, value: this->fireAxis.mat);
    idSerializer::Serialize(this: ser, value: &this->fireAxis.mat[1]);
    idSerializer::Serialize(this: ser, value: &this->fireAxis.mat[2]);
    idSerializer::Serialize(this: ser, value: &this->initialSpeed);
    idSerializer::Serialize(this: ser, value: &this->predictedKey);
  }
}


// ========================================================================
// ?ThrowItem@idClientGameMsg_HandsThrow@@AAAXPAVidPresentablePlayer@@@Z
// EA  : 0x82B5A910
// RVA : 0x00B5A910
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_reliable.cpp
// ========================================================================

void __fastcall idClientGameMsg_HandsThrow::ThrowItem(idClientGameMsg_HandsThrow *this, idPresentablePlayer *player)
{
  idFireParms *p_fp; // r29
  char v5; // r10
  const idDeclProjectile *projectileDecl; // r7
  const idDeclThrowable *throwItem; // r30
  idJobManager *v8; // r3
  idInventoryItem *JobByDecl; // r4
  idPresentableProjectile *v10; // r5

  p_fp = &this->fp;
  if ( player != nullptr )
    p_fp->attacker.spawnId = player->spawnId;
  else
    p_fp->attacker.spawnId = 0;
  this->fp.target.spawnId = 0;
  this->fp.wepDef = nullptr;
  this->fp.start = this->start;
  this->fp.fireAxis = this->fireAxis;
  v5 = *((_BYTE *)&this->fp + 128);
  projectileDecl = this->throwItem->projectileDecl;
  this->fp.startSpeed = this->initialSpeed;
  this->fp.projDef = projectileDecl;
  *((_BYTE *)&this->fp + 128) = v5 & 0x2F | 0x10;
  this->fp.startTime = idClientGameMsg_HandsThrow::GetRealStartTime(this, player);
  if ( cg_projectile_ignoreGrenades.valueInteger == 0 && common->IsServer(this: common) )
  {
    idClientGame::TestFire(this: clientGame, fp: p_fp, tfr: &this->tfr);
    idGameLocal::FinishFire(this: gameLocal, fp: p_fp, tfr: &this->tfr, ffr: &this->ffr);
    if ( g_infiniteAmmo.valueInteger == 0 && g_permaInfiniteAmmo.valueInteger == 0 )
    {
      throwItem = this->throwItem;
      v8 = (idJobManager *)player->GetInventory(this: player);
      JobByDecl = (idInventoryItem *)idJobManager::FindJobByDecl(this: v8, jobDecl: (const idDeclJob *)throwItem);
      if ( JobByDecl != nullptr )
        idPresentablePlayer::RespondToUseItem(this: player, item: JobByDecl, used: true);
    }
  }
  v10 = nullptr;
  if ( this->ffr.numProjectiles >= 1 )
    v10 = (idPresentableProjectile *)idPresentablePtr<idPresentableProjectile>::operator->(this: (idPresentablePtr<idPresentable> *)this->ffr.projectiles);
  idPresentablePlayer::NotifyThrowRelease(this: player, throwItem: this->throwItem, spawnedProjectile: v10);
}


// ========================================================================
// ?Serialize@idClientGameMsg_HitScanHit@@UAAXAAVidSerializer@@@Z
// EA  : 0x82B5AAE0
// RVA : 0x00B5AAE0
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_reliable.cpp
// ========================================================================

void __fastcall idClientGameMsg_HitScanHit::Serialize(idClientGameMsg_HitScanHit *this, idSerializer *ser)
{
  idBitMsg *msg; // r3
  int *p_numHits; // r28
  int v6; // r29
  int *p_jointNum; // r30

  msg = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: msg, value: this->attacker.spawnId, numBits: 32);
  else
    this->attacker.spawnId = idBitMsg::ReadBits(this: msg, numBits: 32);
  p_numHits = &this->numHits;
  idSerializer::SerializePacked(this: ser, original: &this->numHits);
  idSerializer::Serialize<idDeclWeapon>(this: ser, decl: &this->weaponDecl);
  idSerializer::Serialize<idDeclProjectile>(this: ser, decl: &this->projDecl);
  idSerializer::SerializePacked(this: ser, original: &this->serverTime);
  v6 = 0;
  if ( this->numHits > 0 )
  {
    p_jointNum = &this->hitInfos[0].jointNum;
    do
    {
      idSerializer::SerializePacked(this: ser, original: p_jointNum - 1);
      idSerializer::SerializePacked(this: ser, original: p_jointNum);
      idSerializer::SerializePacked(this: ser, original: p_jointNum + 1);
      ++v6;
      p_jointNum += 6;
    }
    while ( v6 < *p_numHits );
  }
}


// ========================================================================
// ?Execute@idClientGameMsg_HitScanHit@@UAAXXZ
// EA  : 0x82B5ABA8
// RVA : 0x00B5ABA8
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_reliable.cpp
// ========================================================================

void __fastcall idClientGameMsg_HitScanHit::Execute(idClientGameMsg_HitScanHit *this)
{
  unsigned int spawnId; // r11
  idPresentablePtr<idPresentable> *p_attacker; // r29
  int v4; // r31
  gameReliable_t v5; // r3
  idPresentable *v6; // r3
  idPresentable *v7; // r3
  int v8; // r3
  char v9; // r11
  gameReliable_t v10; // r3
  int entityNum; // r23
  int v12; // r26
  idClientGameMsg_HitScanHit::hitInfo_t *hitInfos; // r30
  int v14; // r31
  idPresentable *PresentableByIndex; // r3
  int v16; // r31
  idPresentable *v17; // r3
  int v18; // r31
  idPresentable *v19; // r3

  spawnId = this->attacker.spawnId;
  p_attacker = &this->attacker;
  v4 = spawnId & 0x3FFF;
  if ( spawnId != 0
    && idClientGame::IsPresentableIndexValid(this: clientGame, index: spawnId & 0x3FFF)
    && idClientGame::GetPresentableByIndex(this: clientGame, index: v4)->spawnId == p_attacker->spawnId )
  {
    v6 = idPresentablePtr<idPresentableProjectile>::operator->(this: p_attacker);
    if ( v6->GetPlayerInterface_2(this: v6) != nullptr
      || (v7 = idPresentablePtr<idPresentableProjectile>::operator->(this: p_attacker),
          v8 = (int)v7->GetVehicleInterface(this: v7),
          v9 = 0,
          v8 != 0) )
    {
      v9 = 1;
    }
    if ( v9 == 0 )
    {
      v10 = this->GetMsgType(this);
      idLib::Warning(fmt: "Invalid attacker for client game msg %d", v10);
      this->PrintDebug(this);
    }
    entityNum = 0x1FFF;
    v12 = 0;
    if ( this->numHits > 0 )
    {
      hitInfos = this->hitInfos;
      do
      {
        v14 = p_attacker->spawnId & 0x3FFF;
        if ( p_attacker->spawnId == 0
          || !idClientGame::IsPresentableIndexValid(this: clientGame, index: p_attacker->spawnId & 0x3FFF)
          || (PresentableByIndex = idClientGame::GetPresentableByIndex(this: clientGame, index: v14))->spawnId != p_attacker->spawnId )
        {
          PresentableByIndex = nullptr;
        }
        if ( PresentableByIndex->entityNumber == hitInfos->entityNum )
        {
          idLib::Warning(fmt: "idClientGameMsg_HitScanHit::Execute Player hit self?!.");
          this->PrintDebug(this);
        }
        else if ( common->IsServer(this: common) )
        {
          entityNum = hitInfos->entityNum;
          v16 = p_attacker->spawnId & 0x3FFF;
          if ( p_attacker->spawnId == 0
            || !idClientGame::IsPresentableIndexValid(this: clientGame, index: p_attacker->spawnId & 0x3FFF)
            || (v17 = idClientGame::GetPresentableByIndex(this: clientGame, index: v16))->spawnId != p_attacker->spawnId )
          {
            v17 = nullptr;
          }
          v17->ClientHitScanHit(
            this: v17,
            a2: hitInfos->entityNum,
            a3: hitInfos->jointNum,
            a4: hitInfos->bodyId,
            a5: this->weaponDecl,
            a6: this->projDecl,
            a7: this->serverTime);
        }
        ++v12;
        ++hitInfos;
      }
      while ( v12 < this->numHits );
      if ( entityNum != 0x1FFF && common->IsServer(this: common) )
      {
        v18 = p_attacker->spawnId & 0x3FFF;
        if ( p_attacker->spawnId == 0
          || !idClientGame::IsPresentableIndexValid(this: clientGame, index: p_attacker->spawnId & 0x3FFF)
          || (v19 = idClientGame::GetPresentableByIndex(this: clientGame, index: v18))->spawnId != p_attacker->spawnId )
        {
          v19 = nullptr;
        }
        v19->ClientHitScanHit_ClientFire(this: v19, a2: entityNum, a3: this->weaponDecl, a4: this->serverTime);
      }
    }
  }
  else
  {
    v5 = this->GetMsgType(this);
    idLib::Warning(fmt: "Invalid attacker for client game msg %d", v5);
    this->PrintDebug(this);
  }
}


// ========================================================================
// ?PrintDebug@idClientGameMsg_HitScanHit@@UAAXXZ
// EA  : 0x82B5AEA8
// RVA : 0x00B5AEA8
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_reliable.cpp
// ========================================================================

void __fastcall idClientGameMsg_HitScanHit::PrintDebug(idClientGameMsg_HitScanHit *this)
{
  const idDeclProjectile *projDecl; // r11
  const char *str; // r26
  const idDeclWeapon *weaponDecl; // r11
  const char *v5; // r27
  unsigned int spawnId; // r11
  idPresentablePtr<idPresentable> *p_attacker; // r28
  int v8; // r31
  int index; // r4
  int v10; // r31
  idClientGameMsg_HitScanHit *v11; // r30
  int entityNum; // r4

  projDecl = this->projDecl;
  if ( projDecl != nullptr )
    str = projDecl->name.str;
  else
    str = "NULL";
  weaponDecl = this->weaponDecl;
  if ( weaponDecl != nullptr )
    v5 = weaponDecl->name.str;
  else
    v5 = "NULL";
  spawnId = this->attacker.spawnId;
  p_attacker = &this->attacker;
  v8 = spawnId & 0x3FFF;
  if ( spawnId != 0
    && idClientGame::IsPresentableIndexValid(this: clientGame, index: spawnId & 0x3FFF)
    && idClientGame::GetPresentableByIndex(this: clientGame, index: v8)->spawnId == p_attacker->spawnId )
  {
    index = idPresentablePtr<idPresentableProjectile>::operator->(this: &this->attacker)->index;
  }
  else
  {
    index = -1;
  }
  idLib::Printf(
    fmt: "idClientGameMsg_HitScanHit. Attacker: %d. numHits: %d. weaponDecl: %s projDecl: %s serverTime: %d \n",
    index,
    this->numHits,
    v5,
    str,
    this->serverTime);
  v10 = 0;
  if ( this->numHits > 0 )
  {
    v11 = this;
    do
    {
      entityNum = v11->hitInfos[0].entityNum;
      v11 = (idClientGameMsg_HitScanHit *)((char *)v11 + 24);
      idLib::Printf(fmt: "     entityNumber: %d jointNumber: %d \n", entityNum, v11->__vftable);
      ++v10;
    }
    while ( v10 < this->numHits );
  }
}


// ========================================================================
// ?Serialize@idClientGameMsg_QuickUse@@UAAXAAVidSerializer@@@Z
// EA  : 0x82B5AFB0
// RVA : 0x00B5AFB0
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_reliable.cpp
// ========================================================================

void __fastcall idClientGameMsg_QuickUse::Serialize(idClientGameMsg_QuickUse *this, idSerializer *ser)
{
  idBitMsg *msg; // r3

  msg = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: msg, value: this->instigator.spawnId, numBits: 32);
  else
    this->instigator.spawnId = idBitMsg::ReadBits(this: msg, numBits: 32);
  idSerializer::Serialize<idDeclInventory>(this: ser, decl: &this->invDecl);
}


// ========================================================================
// ?Execute@idClientGameMsg_QuickUse@@UAAXXZ
// EA  : 0x82B5B020
// RVA : 0x00B5B020
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_reliable.cpp
// ========================================================================

void __fastcall idClientGameMsg_QuickUse::Execute(idClientGameMsg_QuickUse *this)
{
  unsigned int spawnId; // r11
  idPresentablePtr<idPresentable> *p_instigator; // r29
  int v4; // r31
  char v5; // r11
  idPresentable *v6; // r3
  idPresentable *v7; // r3
  idPresentableVehicle *v8; // r30
  const idDeclInventory *invDecl; // r31
  idJobManager *v10; // r3
  idVehicleQuickItem *JobByDecl; // r3
  idVehicleQuickItem *v12; // r3
  idVehicleQuickItem *v13; // r31
  int v14; // r30
  idStrId *DisplayName; // r3
  const char *LocalizedString; // r31
  idPresentable *v17; // r3
  const char *str; // r29
  int v19; // r3
  idPresentable *v20; // r3
  idPresentable *v21; // r3
  idPresentablePlayer *v22; // r30
  const idDeclInventory *v23; // r31
  idJobManager *v24; // r3
  idJob *v25; // r3
  idInventoryItem *v26; // r31
  int v27; // r29
  idStrId *v28; // r3
  const char *v29; // r6
  idInventoryItem v30; // [sp+50h] [-30h] BYREF

  spawnId = this->instigator.spawnId;
  p_instigator = &this->instigator;
  v4 = spawnId & 0x3FFF;
  if ( spawnId == 0
    || !idClientGame::IsPresentableIndexValid(this: clientGame, index: spawnId & 0x3FFF)
    || idClientGame::GetPresentableByIndex(this: clientGame, index: v4)->spawnId != p_instigator->spawnId
    || (v5 = 1, this->invDecl == nullptr) )
  {
    v5 = 0;
  }
  if ( v5 != 0 )
  {
    v6 = idPresentablePtr<idPresentableProjectile>::operator->(this: p_instigator);
    if ( v6->GetVehicleInterface(this: v6) != nullptr )
    {
      v7 = idPresentablePtr<idPresentableProjectile>::operator->(this: p_instigator);
      v8 = v7->GetVehicleInterface(this: v7);
      if ( ((double (__fastcall *)(idPresentableVehicle *))v8->GetTotalCurHealth)(a1: v8) <= 0.0 )
        return;
      invDecl = this->invDecl;
      v10 = (idJobManager *)v8->GetInventory(this: &v8->idPresentableAnimatedEntity);
      JobByDecl = (idVehicleQuickItem *)idJobManager::FindJobByDecl(this: v10, jobDecl: (const idDeclJob *)invDecl);
      v12 = idVehicleQuickItem::CastTo(c: JobByDecl);
      v13 = v12;
      if ( v12 != nullptr )
      {
        if ( v12->GetCount(this: v12) > 0 )
        {
          idPresentableVehicle::UseQuickItem(this: v8, quickItem: v13);
          return;
        }
        v14 = v13->GetCount(this: v13);
        DisplayName = idInventoryItem::GetDisplayName(this: &v30, result: (idStrId *)v13);
        LocalizedString = idStrId::GetLocalizedString(this: DisplayName);
      }
      else
      {
        v14 = -1;
        LocalizedString = "NULL";
      }
      v17 = idPresentablePtr<idPresentableProjectile>::operator->(this: p_instigator);
      str = this->invDecl->name.str;
      v19 = v17->GetControllingPlayerIndex(this: v17);
      idLib::Warning(
        fmt: "Unable to use QuickItem for player %d. ItemDecl: %s Item: %s Count: %d",
        v19,
        str,
        LocalizedString,
        v14);
    }
    else
    {
      v20 = idPresentablePtr<idPresentableProjectile>::operator->(this: p_instigator);
      if ( v20->GetPlayerInterface_2(this: v20) == nullptr )
        return;
      v21 = idPresentablePtr<idPresentableProjectile>::operator->(this: p_instigator);
      v22 = v21->GetPlayerInterface_2(this: v21);
      v23 = this->invDecl;
      v24 = (idJobManager *)v22->GetInventory(this: v22);
      v25 = idJobManager::FindJobByDecl(this: v24, jobDecl: (const idDeclJob *)v23);
      v26 = (idInventoryItem *)v25;
      if ( v25 != nullptr )
      {
        if ( ((int (__fastcall *)(idJob *))v25->__vftable[2].dtr_idClass)(a1: v25) > 0 )
        {
          idPresentablePlayer::UseItem(this: v22, item: v26);
          return;
        }
        v27 = v26->GetCount(this: v26);
        v28 = idInventoryItem::GetDisplayName(this: &v30, result: (idStrId *)v26);
        v29 = idStrId::GetLocalizedString(this: v28);
      }
      else
      {
        v27 = -1;
        v29 = "NULL";
      }
      idLib::Warning(
        fmt: "Unable to use QuickItem for player %d. ItemDecl: %s Item: %s Count: %d",
        v22->index,
        this->invDecl->name.str,
        v29,
        v27);
    }
  }
}


// ========================================================================
// ?PrintDebug@idClientGameMsg_QuickUse@@UAAXXZ
// EA  : 0x82B5B2C0
// RVA : 0x00B5B2C0
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_reliable.cpp
// ========================================================================

void __fastcall idClientGameMsg_QuickUse::PrintDebug(idClientGameMsg_QuickUse *this)
{
  unsigned int spawnId; // r11
  idPresentablePtr<idPresentable> *p_instigator; // r31
  int v4; // r28
  int v5; // r30
  idPresentable *v6; // r3

  spawnId = this->instigator.spawnId;
  p_instigator = &this->instigator;
  v4 = -1;
  v5 = spawnId & 0x3FFF;
  if ( spawnId != 0
    && idClientGame::IsPresentableIndexValid(this: clientGame, index: spawnId & 0x3FFF)
    && idClientGame::GetPresentableByIndex(this: clientGame, index: v5)->spawnId == p_instigator->spawnId )
  {
    v6 = idPresentablePtr<idPresentableProjectile>::operator->(this: p_instigator);
    v4 = v6->GetControllingPlayerIndex(this: v6);
  }
  idLib::Printf(fmt: "idClientGameMsg_QuickUse. Player: %d item: %s\n", v4, this->invDecl->name.str);
}


// ========================================================================
// ?Serialize@idClientGameMsg_VehicleCrosshairChangeTarget@@UAAXAAVidSerializer@@@Z
// EA  : 0x82B5B360
// RVA : 0x00B5B360
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_reliable.cpp
// ========================================================================

void __fastcall idClientGameMsg_VehicleCrosshairChangeTarget::Serialize(
        idClientGameMsg_VehicleCrosshairChangeTarget *this,
        idSerializer *ser)
{
  idPresentablePtr<idPresentable> *p_vehicle; // r31
  idBitMsg *msg; // r3
  int v5; // r29
  idPresentableVehicle *v6; // r3
  idThirdPersonCrosshair *Crosshair; // r3

  p_vehicle = (idPresentablePtr<idPresentable> *)&this->vehicle;
  msg = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: msg, value: p_vehicle->spawnId, numBits: 32);
  else
    p_vehicle->spawnId = idBitMsg::ReadBits(this: msg, numBits: 32);
  v5 = p_vehicle->spawnId & 0x3FFF;
  if ( p_vehicle->spawnId != 0
    && idClientGame::IsPresentableIndexValid(this: clientGame, index: p_vehicle->spawnId & 0x3FFF)
    && idClientGame::GetPresentableByIndex(this: clientGame, index: v5)->spawnId == p_vehicle->spawnId )
  {
    v6 = (idPresentableVehicle *)idPresentablePtr<idPresentableProjectile>::operator->(this: p_vehicle);
    Crosshair = idPresentableVehicle::GetCrosshair(this: v6);
    idThirdPersonCrosshair::SerializeTargetOverride(this: Crosshair, ser);
  }
}


// ========================================================================
// ?Execute@idClientGameMsg_VehicleCrosshairChangeTarget@@UAAXXZ
// EA  : 0x82B5B408
// RVA : 0x00B5B408
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_reliable.cpp
// ========================================================================

void __fastcall idClientGameMsg_VehicleCrosshairChangeTarget::Execute(
        idClientGameMsg_VehicleCrosshairChangeTarget *this)
{
  unsigned int spawnId; // r11
  idPresentablePtr<idPresentable> *p_vehicle; // r29
  int v3; // r31
  idPresentableVehicle *v4; // r3
  bfx::BinaryReplayLogOut *Crosshair; // r3

  spawnId = this->vehicle.spawnId;
  p_vehicle = (idPresentablePtr<idPresentable> *)&this->vehicle;
  v3 = spawnId & 0x3FFF;
  if ( spawnId != 0
    && idClientGame::IsPresentableIndexValid(this: clientGame, index: spawnId & 0x3FFF)
    && idClientGame::GetPresentableByIndex(this: clientGame, index: v3)->spawnId == p_vehicle->spawnId )
  {
    v4 = (idPresentableVehicle *)idPresentablePtr<idPresentableProjectile>::operator->(this: p_vehicle);
    Crosshair = (bfx::BinaryReplayLogOut *)idPresentableVehicle::GetCrosshair(this: v4);
    idPhysics_StaticMulti::UpdateTime(this: Crosshair);
  }
}


// ========================================================================
// ?Serialize@idClientGameMsg_VehicleWeaponChange@@UAAXAAVidSerializer@@@Z
// EA  : 0x82B5B478
// RVA : 0x00B5B478
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_reliable.cpp
// ========================================================================

void __fastcall idClientGameMsg_VehicleWeaponChange::Serialize(
        idClientGameMsg_VehicleWeaponChange *this,
        idSerializer *ser)
{
  idPresentablePtr<idPresentable> *p_vehicle; // r31
  idBitMsg *msg; // r3
  int v5; // r29
  idPresentableVehicle *v6; // r3

  p_vehicle = (idPresentablePtr<idPresentable> *)&this->vehicle;
  msg = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: msg, value: p_vehicle->spawnId, numBits: 32);
  else
    p_vehicle->spawnId = idBitMsg::ReadBits(this: msg, numBits: 32);
  v5 = p_vehicle->spawnId & 0x3FFF;
  if ( p_vehicle->spawnId != 0
    && idClientGame::IsPresentableIndexValid(this: clientGame, index: p_vehicle->spawnId & 0x3FFF)
    && idClientGame::GetPresentableByIndex(this: clientGame, index: v5)->spawnId == p_vehicle->spawnId )
  {
    v6 = (idPresentableVehicle *)idPresentablePtr<idPresentableProjectile>::operator->(this: p_vehicle);
    idPresentableVehicle::SerializeWeaponChange(this: v6, ser);
  }
}


// ========================================================================
// ?Execute@idClientGameMsg_VehicleWeaponChange@@UAAXXZ
// EA  : 0x82B5B518
// RVA : 0x00B5B518
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_reliable.cpp
// ========================================================================

void __fastcall idClientGameMsg_VehicleWeaponChange::Execute(idClientGameMsg_VehicleWeaponChange *this)
{
  unsigned int spawnId; // r11
  idPresentablePtr<idPresentable> *p_vehicle; // r29
  int v3; // r31
  bfx::BinaryReplayLogOut *v4; // r3

  spawnId = this->vehicle.spawnId;
  p_vehicle = (idPresentablePtr<idPresentable> *)&this->vehicle;
  v3 = spawnId & 0x3FFF;
  if ( spawnId != 0
    && idClientGame::IsPresentableIndexValid(this: clientGame, index: spawnId & 0x3FFF)
    && idClientGame::GetPresentableByIndex(this: clientGame, index: v3)->spawnId == p_vehicle->spawnId )
  {
    v4 = (bfx::BinaryReplayLogOut *)idPresentablePtr<idPresentableProjectile>::operator->(this: p_vehicle);
    idPhysics_StaticMulti::UpdateTime(this: v4);
  }
}


// ========================================================================
// ?Serialize@idClientGameMsg_UpdateStat@@UAAXAAVidSerializer@@@Z
// EA  : 0x82B5B588
// RVA : 0x00B5B588
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_reliable.cpp
// ========================================================================

void __fastcall idClientGameMsg_UpdateStat::Serialize(idClientGameMsg_UpdateStat *this, idSerializer *ser)
{
  idBitMsg *msg; // r3
  int statType; // r29
  idBitMsg *v6; // r3
  unsigned int v7; // r10
  idBitMsg *v8; // r3

  msg = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: msg, value: this->presentable.spawnId, numBits: 32);
  else
    this->presentable.spawnId = idBitMsg::ReadBits(this: msg, numBits: 32);
  statType = this->statType;
  v6 = ser->msg;
  v7 = _cntlzw(3u);
  if ( ser->writing )
    idBitMsg::WriteBits(this: v6, value: this->statType, numBits: 32 - v7);
  else
    statType = idBitMsg::ReadBits(this: v6, numBits: 32 - v7);
  this->statType = statType;
  v8 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v8, value: this->statParm, numBits: 32);
  else
    this->statParm = idBitMsg::ReadBits(this: v8, numBits: 32);
}


// ========================================================================
// ?Execute@idClientGameMsg_UpdateStat@@UAAXXZ
// EA  : 0x82B5B640
// RVA : 0x00B5B640
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_reliable.cpp
// ========================================================================

void __fastcall idClientGameMsg_UpdateStat::Execute(idClientGameMsg_UpdateStat *this)
{
  unsigned int spawnId; // r11
  idPresentablePtr<idPresentable> *p_presentable; // r29
  int v4; // r31
  int statType; // r11
  idPresentable *v6; // r3
  idPresentable *v7; // r3
  idPresentableVehicle *v8; // r3
  idPresentable *v9; // r3
  idPresentable *v10; // r3
  int statParm; // r31
  idPresentableVehicle *v12; // r3

  spawnId = this->presentable.spawnId;
  p_presentable = &this->presentable;
  v4 = spawnId & 0x3FFF;
  if ( spawnId != 0
    && idClientGame::IsPresentableIndexValid(this: clientGame, index: spawnId & 0x3FFF)
    && idClientGame::GetPresentableByIndex(this: clientGame, index: v4)->spawnId == p_presentable->spawnId )
  {
    statType = this->statType;
    if ( statType == 1 )
    {
      v9 = idPresentablePtr<idPresentableProjectile>::operator->(this: p_presentable);
      if ( v9->GetVehicleInterface(this: v9) != nullptr )
      {
        v10 = idPresentablePtr<idPresentableProjectile>::operator->(this: p_presentable);
        statParm = this->statParm;
        v12 = v10->GetVehicleInterface(this: v10);
        idPresentableVehicle::AddBoostUpSP(this: v12, statParm);
      }
    }
    else if ( statType == 2 )
    {
      v6 = idPresentablePtr<idPresentableProjectile>::operator->(this: p_presentable);
      if ( v6->GetVehicleInterface(this: v6) != nullptr )
      {
        v7 = idPresentablePtr<idPresentableProjectile>::operator->(this: p_presentable);
        v8 = v7->GetVehicleInterface(this: v7);
        idPresentableVehicle::AddJumpManSP(this: v8);
      }
    }
  }
}


// ========================================================================
// ?Serialize@idClientGameMsg_UseFocus@@UAAXAAVidSerializer@@@Z
// EA  : 0x82B5B740
// RVA : 0x00B5B740
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_reliable.cpp
// ========================================================================

void __fastcall idClientGameMsg_UseFocus::Serialize(idClientGameMsg_UseFocus *this, idSerializer *ser)
{
  idBitMsg *msg; // r3
  idBitMsg *v5; // r3
  usableState_t usableState; // r29
  idBitMsg *v7; // r3
  unsigned int v8; // r10

  msg = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: msg, value: this->instigator.spawnId, numBits: 32);
  else
    this->instigator.spawnId = idBitMsg::ReadBits(this: msg, numBits: 32);
  v5 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v5, value: this->usedPresentable.spawnId, numBits: 32);
  else
    this->usedPresentable.spawnId = idBitMsg::ReadBits(this: v5, numBits: 32);
  usableState = this->usableState;
  v7 = ser->msg;
  v8 = _cntlzw(0xEu);
  if ( ser->writing )
  {
    idBitMsg::WriteBits(this: v7, value: this->usableState, numBits: 32 - v8);
    this->usableState = usableState;
  }
  else
  {
    this->usableState = idBitMsg::ReadBits(this: v7, numBits: 32 - v8);
  }
}


// ========================================================================
// ?Execute@idClientGameMsg_UseFocus@@UAAXXZ
// EA  : 0x82B5B7F8
// RVA : 0x00B5B7F8
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_reliable.cpp
// ========================================================================

void __fastcall idClientGameMsg_UseFocus::Execute(idClientGameMsg_UseFocus *this)
{
  unsigned int spawnId; // r11
  idPresentablePtr<idPresentable> *p_usedPresentable; // r29
  int v4; // r31
  idEntity *entity; // r31
  idPresentable *v6; // r3

  spawnId = this->usedPresentable.spawnId;
  p_usedPresentable = &this->usedPresentable;
  v4 = spawnId & 0x3FFF;
  if ( spawnId != 0
    && idClientGame::IsPresentableIndexValid(this: clientGame, index: spawnId & 0x3FFF)
    && idClientGame::GetPresentableByIndex(this: clientGame, index: v4)->spawnId == p_usedPresentable->spawnId
    && idPresentablePtr<idPresentablePlayer>::operator idPresentablePlayer *(this: &this->instigator) != nullptr
    && common->IsServer(this: common) )
  {
    entity = idPresentablePtr<idPresentableProjectile>::operator->(this: p_usedPresentable)->entity;
    if ( entity != nullptr )
    {
      idPresentablePtr<idPresentableProjectile>::operator->(this: (idPresentablePtr<idPresentable> *)&this->instigator);
      v6 = idPresentablePtr<idPresentableProjectile>::operator->(this: (idPresentablePtr<idPresentable> *)&this->instigator);
      entity->Use(this: entity, a2: v6->entity, a3: this->usableState);
    }
  }
}


// ========================================================================
// ?PrintDebug@idClientGameMsg_UseFocus@@UAAXXZ
// EA  : 0x82B5B8D8
// RVA : 0x00B5B8D8
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_reliable.cpp
// ========================================================================

void __fastcall idClientGameMsg_UseFocus::PrintDebug(idClientGameMsg_UseFocus *this)
{
  unsigned int spawnId; // r11
  idPresentablePtr<idPresentable> *p_usedPresentable; // r31
  int v4; // r30
  int entityNumber; // r27
  unsigned int v6; // r11
  int v7; // r31
  int v8; // r4

  spawnId = this->usedPresentable.spawnId;
  p_usedPresentable = &this->usedPresentable;
  v4 = spawnId & 0x3FFF;
  if ( spawnId != 0
    && idClientGame::IsPresentableIndexValid(this: clientGame, index: spawnId & 0x3FFF)
    && idClientGame::GetPresentableByIndex(this: clientGame, index: v4)->spawnId == p_usedPresentable->spawnId )
  {
    entityNumber = idPresentablePtr<idPresentableProjectile>::operator->(this: p_usedPresentable)->entityNumber;
  }
  else
  {
    entityNumber = -1;
  }
  v6 = this->instigator.spawnId;
  v7 = v6 & 0x3FFF;
  if ( v6 != 0
    && idClientGame::IsPresentableIndexValid(this: clientGame, index: v6 & 0x3FFF)
    && idClientGame::GetPresentableByIndex(this: clientGame, index: v7)->spawnId == this->instigator.spawnId )
  {
    v8 = idPresentablePtr<idPresentableProjectile>::operator->(this: (idPresentablePtr<idPresentable> *)&this->instigator)->entityNumber;
  }
  else
  {
    v8 = -1;
  }
  idLib::Printf(fmt: "idClientGameMsg_UseFocus. instigator: %d used: %d\n", v8, entityNumber);
}


// ========================================================================
// ?Serialize@idClientGameMsg_MeleeHit@@UAAXAAVidSerializer@@@Z
// EA  : 0x82B5B9C0
// RVA : 0x00B5B9C0
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_reliable.cpp
// ========================================================================

void __fastcall idClientGameMsg_MeleeHit::Serialize(idClientGameMsg_MeleeHit *this, idSerializer *ser)
{
  idBitMsg *msg; // r3
  idBitMsg *v5; // r3
  int trmFeature; // r11
  unsigned __int16 Bits; // r29
  idBitMsg *v8; // r3
  idIndex<short,enum invalidJointIndex_t> *v9; // r11
  idBitMsg *v10; // r3
  unsigned __int16 v11; // [sp+50h] [-30h] BYREF

  msg = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: msg, value: this->instigator.spawnId, numBits: 32);
  else
    this->instigator.spawnId = idBitMsg::ReadBits(this: msg, numBits: 32);
  v5 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v5, value: this->hitEntityNum, numBits: 32);
  else
    this->hitEntityNum = idBitMsg::ReadBits(this: v5, numBits: 32);
  idSerializer::Serialize<idDeclDamage>(this: ser, decl: &this->damageDecl);
  trmFeature = this->trace.c.trmFeature;
  if ( trmFeature == NULL_JOINT_INDEX.value )
    LOWORD(trmFeature) = -1;
  Bits = trmFeature;
  v8 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v8, value: (unsigned __int16)trmFeature, numBits: 16);
  else
    Bits = idBitMsg::ReadBits(this: v8, numBits: 16);
  if ( Bits == 0xFFFF )
  {
    v9 = &NULL_JOINT_INDEX;
  }
  else
  {
    v11 = Bits;
    v9 = (idIndex<short,enum invalidJointIndex_t> *)&v11;
  }
  this->trace.c.trmFeature = v9->value;
  v10 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v10, value: this->trace.c.modelFeature, numBits: 32);
  else
    this->trace.c.modelFeature = idBitMsg::ReadBits(this: v10, numBits: 32);
}


// ========================================================================
// ?Execute@idClientGameMsg_MeleeHit@@UAAXXZ
// EA  : 0x82B5BAF0
// RVA : 0x00B5BAF0
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_reliable.cpp
// ========================================================================

void __fastcall idClientGameMsg_MeleeHit::Execute(idClientGameMsg_MeleeHit *this)
{
  idEntity *v2; // r3
  idEntity *v3; // r30
  idPhysics *Physics; // r3
  float *v5; // r28
  idPresentable *v6; // r3
  double v7; // fp10
  double v8; // fp8
  double v9; // fp6
  double v10; // fp13
  idPhysics *v13; // r3
  float *v14; // r3
  idPresentable *v15; // r3

  v2 = gameLocal->GetEntity(this: gameLocal, a2: this->hitEntityNum);
  v3 = v2;
  if ( v2 != nullptr )
  {
    Physics = idEntity::GetPhysics(this: v2);
    v5 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
    v6 = idPresentablePtr<idPresentableProjectile>::operator->(this: (idPresentablePtr<idPresentable> *)&this->instigator);
    v7 = (float)(v6->origin.y - v5[1]);
    v8 = (float)(v6->origin.x - *v5);
    v9 = (float)(v6->origin.z - v5[2]);
    v10 = idMath::FLT_SMALLEST_NON_DENORMAL;
    this->trace.c.type = CONTACT_SPHERE;
    _FP2 = (float)((float)((float)((float)v9 * (float)v9)
                         + (float)((float)((float)v8 * (float)v8) + (float)((float)v7 * (float)v7)))
                 - (float)v10);
    __asm { fsel      f13, f2, f3, f13 }
    v13 = idEntity::GetPhysics(this: v3);
    v14 = (float *)v13->GetOrigin(this: v13, a2: 0);
    this->trace.endpos.x = *v14;
    this->trace.endpos.y = v14[1];
    this->trace.endpos.z = v14[2];
    this->trace.fraction = 0.89999998;
    v15 = idPresentablePtr<idPresentableProjectile>::operator->(this: (idPresentablePtr<idPresentable> *)&this->instigator);
    ((void (__fastcall *)(idEntity *, _DWORD, idEntity *, const idDeclDamage *, double))v3->Damage)(
      a1: v3,
      a2: 0,
      a3: v15->entity,
      a4: this->damageDecl,
      a5: 1.0);
  }
}


// ========================================================================
// ?PrintDebug@idClientGameMsg_MeleeHit@@UAAXXZ
// EA  : 0x82B5BC80
// RVA : 0x00B5BC80
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_reliable.cpp
// ========================================================================

void __fastcall idClientGameMsg_MeleeHit::PrintDebug(idClientGameMsg_MeleeHit *this)
{
  unsigned int spawnId; // r11
  int v3; // r30
  idPresentable *PresentableByIndex; // r3

  spawnId = this->instigator.spawnId;
  v3 = spawnId & 0x3FFF;
  if ( spawnId == 0
    || !idClientGame::IsPresentableIndexValid(this: clientGame, index: spawnId & 0x3FFF)
    || (PresentableByIndex = idClientGame::GetPresentableByIndex(this: clientGame, index: v3))->spawnId != this->instigator.spawnId )
  {
    PresentableByIndex = nullptr;
  }
  idLib::Printf(fmt: "idClientGameMsg_MeleeHit player %d", PresentableByIndex->index);
}


// ========================================================================
// ?Serialize@idClientGameMsg_ActorModifier@@UAAXAAVidSerializer@@@Z
// EA  : 0x82B5BCF8
// RVA : 0x00B5BCF8
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_reliable.cpp
// ========================================================================

void __fastcall idClientGameMsg_ActorModifier::Serialize(idClientGameMsg_ActorModifier *this, idSerializer *ser)
{
  idBitMsg *msg; // r3
  idBitMsg *v5; // r3
  idBitMsg *v6; // r3

  msg = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: msg, value: this->instigator.spawnId, numBits: 32);
  else
    this->instigator.spawnId = idBitMsg::ReadBits(this: msg, numBits: 32);
  v5 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v5, value: this->uid, numBits: 32);
  else
    this->uid = idBitMsg::ReadBits(this: v5, numBits: 32);
  v6 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v6, value: this->index, numBits: 8);
  else
    this->index = idBitMsg::ReadBits(this: v6, numBits: 8);
}


// ========================================================================
// ?Execute@idClientGameMsg_ActorModifier@@UAAXXZ
// EA  : 0x82B5BDB0
// RVA : 0x00B5BDB0
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_reliable.cpp
// ========================================================================

void __fastcall idClientGameMsg_ActorModifier::Execute(idClientGameMsg_ActorModifier *this)
{
  idPresentablePtr<idPresentable> *p_instigator; // r30
  idPresentable *v3; // r3

  p_instigator = (idPresentablePtr<idPresentable> *)&this->instigator;
  if ( idPresentablePtr<idPresentable>::IsValid(this: &this->instigator) )
  {
    v3 = idPresentablePtr<idPresentableProjectile>::operator->(this: p_instigator);
    ((void (__fastcall *)(idPresentable *, unsigned int, _DWORD))v3->__vftable[1].ShouldInterpolate)(
      a1: v3,
      a2: this->uid,
      a3: this->index);
  }
  else
  {
    idLib::Warning(fmt: "idClientGameMsg_ActorModifier: instigator is not valid.");
  }
}


// ========================================================================
// ?QueueReliableClientGameMsg@idClientGame@@QAAXPAVidClientGameMsg@@AAVidBitMsg@@@Z
// EA  : 0x82B5C088
// RVA : 0x00B5C088
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_reliable.cpp
// ========================================================================

void __fastcall idClientGame::QueueReliableClientGameMsg(
        idClientGame *this,
        idClientGameMsg *gameMsg,
        idBitMsg *bitMsg,
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
        idClientGameMsg *a14)
{
  gameReliable_t v16; // r3
  _BYTE v17[4]; // [sp+50h] [-20h] BYREF
  idBitMsg *v18; // [sp+54h] [-1Ch]

  a14 = gameMsg;
  if ( gameMsg != nullptr )
  {
    v18 = bitMsg;
    v17[0] = 0;
    gameMsg->Serialize(this: gameMsg, a2: (idSerializer *)v17);
    if ( cg_reliable_debug.valueInteger != 0 )
    {
      v16 = gameMsg->GetMsgType(this: gameMsg);
      idLib::Printf(fmt: "^6Queued^7 reliable ClientGameMsg %d \n", v16);
    }
    idList<idAnimWebBlendTree *,5>::Append(
      this: (idList<enum encounterGroupRole_t,5> *)&this->queuedReliableMsgs,
      obj: (encounterGroupRole_t *)&a14);
  }
}


// ========================================================================
// ?Execute@idClientGameMsg_HandsEquip@@UAAXXZ
// EA  : 0x82B5C140
// RVA : 0x00B5C140
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_reliable.cpp
// ========================================================================

void __fastcall idClientGameMsg_HandsEquip::Execute(idClientGameMsg_HandsEquip *this)
{
  idPresentablePlayer *PlayerPresentableByIndex; // r30
  int v3; // r29
  idInventoryItem *JobByDecl; // r4
  idWeapon *v5; // r3
  const idDeclAmmo *ammoDecl; // r4
  idWeapon *v7; // r30
  idAmmoItem *ammoClip; // r11
  idPresentableWeapon *PresentableWeapon; // r3

  PlayerPresentableByIndex = idClientGame::FindPlayerPresentableByIndex(this: clientGame, playerNum: this->playerNumber);
  v3 = (int)PlayerPresentableByIndex->GetInventory(this: PlayerPresentableByIndex);
  JobByDecl = (idInventoryItem *)idJobManager::FindJobByDecl(
                                   this: (idJobManager *)v3,
                                   jobDecl: (const idDeclJob *)this->itemDecl);
  if ( JobByDecl != nullptr )
  {
    idPresentablePlayer::EquipItem(this: PlayerPresentableByIndex, item: JobByDecl);
    *(_BYTE *)(v3 + 796) = 0;
    v5 = PlayerPresentableByIndex->GetEquippedWeapon(this: PlayerPresentableByIndex);
    ammoDecl = this->ammoDecl;
    v7 = v5;
    if ( ammoDecl != nullptr )
    {
      ammoClip = v5->ammoClip;
      if ( ammoClip != nullptr && ammoClip->decl != ammoDecl )
      {
        idWeapon::BeginReloading(this: v5, ammoDecl, secondaryAmmo: false);
        PresentableWeapon = idWeapon::GetPresentableWeapon(this: v7);
        v7->Reload(
          this: v7,
          a2: (idInventoryCollection *)v3,
          a3: &PresentableWeapon->fxManager,
          a4: false,
          a5: false,
          a6: false);
      }
    }
    *(_BYTE *)(v3 + 796) = 1;
  }
  else
  {
    idLib::Warning(
      fmt: "idClientGameMsg_HandsEquip item %s not in player %d's inventory. ",
      this->itemDecl->name.str,
      this->playerNumber);
  }
}


// ========================================================================
// __unwind$494204
// EA  : 0x82B5C24C
// RVA : 0x00B5C24C
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_reliable.cpp
// ========================================================================

void _unwind_494204()
{
  int v0; // r12

  idInventorySerializeLock::~idInventorySerializeLock(this: (idInventorySerializeLock *)(v0 - 144 + 88));
}


// ========================================================================
// ?Execute@idClientGameMsg_HandsAmmoChange@@UAAXXZ
// EA  : 0x82B5C280
// RVA : 0x00B5C280
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_reliable.cpp
// ========================================================================

void __fastcall idClientGameMsg_HandsAmmoChange::Execute(idClientGameMsg_HandsAmmoChange *this)
{
  idPresentablePlayer *PlayerPresentableByIndex; // r30
  int v3; // r28
  int v4; // r3
  idWeapon *v5; // r30
  char v6; // r11
  const idDeclWeapon *weaponDecl; // r4
  idWeapon *JobByDecl; // r3
  const idDeclAmmo *ammoDecl; // r11
  idFXManager *p_fxManager; // r5

  PlayerPresentableByIndex = idClientGame::FindPlayerPresentableByIndex(this: clientGame, playerNum: this->playerNumber);
  v3 = (int)PlayerPresentableByIndex->GetInventory(this: PlayerPresentableByIndex);
  v4 = (int)PlayerPresentableByIndex->GetEquippedWeapon(this: PlayerPresentableByIndex);
  v5 = (idWeapon *)v4;
  if ( v4 == 0 || this->weaponDecl == nullptr || (v6 = 1, this->ammoDecl == nullptr) )
    v6 = 0;
  if ( v6 != 0 )
  {
    weaponDecl = this->weaponDecl;
    if ( *(const idDeclWeapon **)(v4 + 12) != weaponDecl )
    {
      JobByDecl = (idWeapon *)idJobManager::FindJobByDecl(
                                this: (idJobManager *)v3,
                                jobDecl: (const idDeclJob *)weaponDecl);
      v5 = idWeapon::CastTo(c: JobByDecl);
    }
    if ( v5 != nullptr )
    {
      ammoDecl = this->ammoDecl;
      if ( v5->ammoClip->decl == ammoDecl )
        idLib::Warning(
          fmt: "idClientGameMsg_HandsAmmoChange player %d change %s already loaded?",
          this->playerNumber,
          ammoDecl->name.str);
      *(_BYTE *)(v3 + 796) = 0;
      idWeapon::BeginReloading(this: v5, ammoDecl: this->ammoDecl, secondaryAmmo: false);
      if ( idWeapon::GetPresentableWeapon(this: v5) != nullptr )
        p_fxManager = &idWeapon::GetPresentableWeapon(this: v5)->fxManager;
      else
        p_fxManager = nullptr;
      v5->Reload(this: v5, a2: (idInventoryCollection *)v3, a3: p_fxManager, a4: false, a5: false, a6: false);
      *(_BYTE *)(v3 + 796) = 1;
    }
    else
    {
      idLib::Warning(
        fmt: "idClientGameMsg_HandsAmmoChange item %s not in player %d's inventory. ",
        this->weaponDecl->name.str,
        this->playerNumber);
    }
  }
  else
  {
    idLib::Warning(fmt: "idClientGameMsg_HandsAmmoChange player %d weapon is NULL.", this->playerNumber);
  }
}


// ========================================================================
// __unwind$494276
// EA  : 0x82B5C400
// RVA : 0x00B5C400
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_reliable.cpp
// ========================================================================

void _unwind_494276()
{
  int v0; // r12

  idInventorySerializeLock::~idInventorySerializeLock(this: (idInventorySerializeLock *)(v0 - 144 + 80));
}


// ========================================================================
// ?Execute@idClientGameMsg_HandsThrow@@UAAXXZ
// EA  : 0x82B5C428
// RVA : 0x00B5C428
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_reliable.cpp
// ========================================================================

void __fastcall idClientGameMsg_HandsThrow::Execute(idClientGameMsg_HandsThrow *this)
{
  idPresentablePlayer *PlayerPresentableByIndex; // r4
  int playerNumber; // r30
  gameReliable_t v4; // r3
  idClientGameMsg_HandsThrow::clientGameMsgHandsThrow_t throwType; // r11

  PlayerPresentableByIndex = idClientGame::FindPlayerPresentableByIndex(this: clientGame, playerNum: this->playerNumber);
  if ( PlayerPresentableByIndex != nullptr )
  {
    throwType = this->throwType;
    if ( (unsigned int)throwType > HANDS_THROW_DROPONDEATH )
    {
      idLib::Warning(fmt: "Unknown throwType: %d ", this->throwType);
      this->PrintDebug(this);
    }
    else if ( throwType == HANDS_THROW_RELEASE )
    {
      idClientGameMsg_HandsThrow::ThrowItem(this, player: PlayerPresentableByIndex);
    }
  }
  else
  {
    playerNumber = this->playerNumber;
    v4 = this->GetMsgType(this);
    idLib::Warning(fmt: "Invalid player for client game msg %d. playerNumber: %d ", v4, playerNumber);
    this->PrintDebug(this);
  }
}


// ========================================================================
// ?Serialize@idClientGameMsg_PostGameScoreRecap@@UAAXAAVidSerializer@@@Z
// EA  : 0x82B5C510
// RVA : 0x00B5C510
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_reliable.cpp
// ========================================================================

void __fastcall idClientGameMsg_PostGameScoreRecap::Serialize(
        idClientGameMsg_PostGameScoreRecap *this,
        idSerializer *ser)
{
  int num; // r31
  idBitMsg *msg; // r3
  idList<idClientGameMsg_PostGameScoreRecap::scoreItem_t,5> *p_items; // r29
  int size; // r11
  int v8; // r27
  int v9; // r31
  idBitMsg *v10; // r3
  bool isFloat; // r28
  idClientGameMsg_PostGameScoreRecap::scoreItem_t *v12; // r28
  idBitMsg *v13; // r3
  idClientGameMsg_PostGameScoreRecap::scoreItem_t *list; // r28
  idBitMsg *v15; // r3

  num = this->items.num;
  msg = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: msg, value: num, numBits: 32);
  else
    num = idBitMsg::ReadBits(this: msg, numBits: 32);
  p_items = &this->items;
  if ( num <= this->items.size
    || (unsigned __int8)idList<idClientGameMsg_PostGameScoreRecap::scoreItem_t,5>::Resize(
                          this: &this->items,
                          newsize: num) != 0 )
  {
    size = this->items.size;
    if ( num < size )
      size = num;
    this->items.num = size;
  }
  v8 = 0;
  if ( this->items.num > 0 )
  {
    v9 = 0;
    do
    {
      v10 = ser->msg;
      isFloat = p_items->list[v9].isFloat;
      if ( ser->writing )
        idBitMsg::WriteBits(this: v10, value: p_items->list[v9].isFloat, numBits: 1);
      else
        isFloat = (_cntlzw(idBitMsg::ReadBits(this: v10, numBits: 1) - 1) & 0x20) != 0;
      p_items->list[v9].isFloat = isFloat;
      v12 = &p_items->list[v9];
      v13 = ser->msg;
      if ( v12->isFloat )
      {
        if ( ser->writing )
          idBitMsg::WriteBits(this: v13, value: COERCE_INT(v12->floatValue), numBits: 32);
        else
          LODWORD(v12->floatValue) = idBitMsg::ReadBits(this: v13, numBits: 32);
      }
      else if ( ser->writing )
      {
        idBitMsg::WriteBits(this: v13, value: v12->intValue, numBits: 32);
      }
      else
      {
        v12->intValue = idBitMsg::ReadBits(this: v13, numBits: 32);
      }
      list = p_items->list;
      v15 = ser->msg;
      if ( ser->writing )
        idBitMsg::WriteBits(this: v15, value: list[v9].playerIndex, numBits: 32);
      else
        list[v9].playerIndex = idBitMsg::ReadBits(this: v15, numBits: 32);
      idSerializer::Serialize<idDeclMetric>(this: ser, decl: &p_items->list[v9].metric);
      ++v8;
      ++v9;
    }
    while ( v8 < this->items.num );
  }
}


// ========================================================================
// ?Execute@idClientGameMsg_PostGameScoreRecap@@UAAXXZ
// EA  : 0x82B5C6C8
// RVA : 0x00B5C6C8
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_reliable.cpp
// ========================================================================

void __fastcall idClientGameMsg_PostGameScoreRecap::Execute(idClientGameMsg_PostGameScoreRecap *this)
{
  int v2; // r31
  idClientGame *i; // r3
  idPresentablePlayer *VehiclePresentable; // r3
  idPresentablePlayer *v5; // r30
  idPresentablePlayer *LocalPresentablePlayer; // r3

  v2 = 0;
  for ( i = clientGame; v2 < clientGame->vehiclePresentables.num; ++v2 )
  {
    VehiclePresentable = (idPresentablePlayer *)idClientGame::GetVehiclePresentable(this: i, index: v2);
    v5 = VehiclePresentable;
    if ( VehiclePresentable != nullptr )
    {
      idPresentablePlayer::StopSound(this: VehiclePresentable, channel: SND_CHANNEL_ANY, peerMask: 0);
      HIBYTE(v5->view.screenEffects[2].genParms[4].w) = 1;
    }
    i = clientGame;
  }
  LocalPresentablePlayer = idClientGame::GetLocalPresentablePlayer(this: i);
  idList<idClientGameMsg_PostGameScoreRecap::scoreItem_t,5>::operator=(
    this: &LocalPresentablePlayer->postGameItems,
    other: &this->items);
  this->PrintDebug(this);
}


// ========================================================================
// ?NetReceiveReliable@idClientGame@@QAAXHAAVidBitMsg@@H@Z
// EA  : 0x82B5C860
// RVA : 0x00B5C860
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_reliable.cpp
// ========================================================================

void __fastcall idClientGame::NetReceiveReliable(idClientGame *this, int type, idBitMsg *msg, int peer)
{
  int v6; // r10
  void **v7; // r9
  void **p_weapon; // r8
  int v9; // r7
  int v10; // r6
  idClientGameMsg_HandsThrow *v11; // r3
  idClientGameMsg_HandsThrow *v12; // r4
  idBitMsg *v13; // r5
  idClientGame *v14; // r3
  idClientGameMsg_HandsThrow *v15; // r3
  idClientGameMsg_HandsThrow *v16; // r3
  idClientGameMsg_HitScanHit *v17; // r3
  idClientGameMsg_HandsThrow *v18; // r3
  idClientGameMsg_HandsThrow *v19; // r3
  idClientGameMsg_HandsThrow *v20; // r3
  idClientGameMsg_HandsThrow *v21; // r3
  idClientGameMsg_HandsThrow *v22; // r30
  idClientGameMsg_HandsThrow *v23; // r3
  idClientGameMsg_HandsThrow *v24; // r3
  idClientGameMsg_HandsThrow *v25; // r3
  idClientGameMsg_HandsThrow *v26; // r3
  idClientGameMsg_PostGameScoreRecap *v27; // r3
  int v28; // [sp+8h] [-78h]
  int v29; // [sp+Ch] [-74h]
  int v30; // [sp+10h] [-70h]
  int v31; // [sp+14h] [-6Ch]
  int v32; // [sp+18h] [-68h]
  idClientGameMsg *v33; // [sp+1Ch] [-64h]

  switch ( type )
  {
    case '&':
      v11 = (idClientGameMsg_HandsThrow *)idMem::AllocWithLocation(
                                            this: &mem,
                                            location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                            size: 0x14u,
                                            tag: TAG_NETWORKING,
                                            zeroBuffer: false,
                                            align: ALIGN_16,
                                            heap: HEAP_DEFAULTHEAP);
      if ( v11 == nullptr )
        goto LABEL_4;
      v6 = (int)&off_822B0000;
      v7 = (void **)255;
      p_weapon = &idClientGameMsg_HandsEquip::`vftable';
      v11->fp.attacker.spawnId = 0;
      v11->peerMask = -1;
      v12 = v11;
      v11->__vftable = (idClientGameMsg_HandsThrow_vtbl *)&idClientGameMsg_HandsEquip::`vftable';
      v13 = msg;
      v11->fp.weapon = nullptr;
      v14 = this;
      goto LABEL_34;
    case '\'':
      v15 = (idClientGameMsg_HandsThrow *)idMem::AllocWithLocation(
                                            this: &mem,
                                            location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                            size: 0x18u,
                                            tag: TAG_NETWORKING,
                                            zeroBuffer: false,
                                            align: ALIGN_16,
                                            heap: HEAP_DEFAULTHEAP);
      if ( v15 == nullptr )
        goto LABEL_4;
      v6 = (int)&off_822B0000;
      v7 = (void **)255;
      p_weapon = &idClientGameMsg_HandsAmmoChange::`vftable';
      v15->fp.attacker.spawnId = 0;
      v15->peerMask = -1;
      v12 = v15;
      v15->__vftable = (idClientGameMsg_HandsThrow_vtbl *)&idClientGameMsg_HandsAmmoChange::`vftable';
      v13 = msg;
      v15->fp.presentableWeapon.spawnId = 0;
      v15->fp.weapon = nullptr;
      v14 = this;
      goto LABEL_34;
    case '(':
      v16 = (idClientGameMsg_HandsThrow *)idMem::AllocWithLocation(
                                            this: &mem,
                                            location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                            size: 0xA30u,
                                            tag: TAG_NETWORKING,
                                            zeroBuffer: false,
                                            align: ALIGN_16,
                                            heap: HEAP_DEFAULTHEAP);
      if ( v16 != nullptr )
        v12 = idClientGameMsg_HandsThrow::idClientGameMsg_HandsThrow(this: v16);
      else
        v12 = nullptr;
      v13 = msg;
      v14 = this;
      goto LABEL_34;
    case ')':
      v17 = (idClientGameMsg_HitScanHit *)idMem::AllocWithLocation(
                                            this: &mem,
                                            location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                            size: 0x328u,
                                            tag: TAG_NETWORKING,
                                            zeroBuffer: false,
                                            align: ALIGN_16,
                                            heap: HEAP_DEFAULTHEAP);
      if ( v17 == nullptr )
        goto LABEL_4;
      v12 = (idClientGameMsg_HandsThrow *)idClientGameMsg_HitScanHit::idClientGameMsg_HitScanHit(this: v17);
      v13 = msg;
      v14 = this;
      goto LABEL_34;
    case '*':
      v18 = (idClientGameMsg_HandsThrow *)idMem::AllocWithLocation(
                                            this: &mem,
                                            location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                            size: 0x10u,
                                            tag: TAG_NETWORKING,
                                            zeroBuffer: false,
                                            align: ALIGN_16,
                                            heap: HEAP_DEFAULTHEAP);
      if ( v18 == nullptr )
        goto LABEL_4;
      v6 = 255;
      v7 = &idClientGameMsg_QuickUse::`vftable';
      v18->peerMask = -1;
      v18->__vftable = (idClientGameMsg_HandsThrow_vtbl *)&idClientGameMsg_QuickUse::`vftable';
      v12 = v18;
      v18->fp.attacker.spawnId = 0;
      v13 = msg;
      v18->fp.presentableWeapon.spawnId = 0;
      v14 = this;
      goto LABEL_34;
    case '+':
      v20 = (idClientGameMsg_HandsThrow *)idMem::AllocWithLocation(
                                            this: &mem,
                                            location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                            size: 0x14u,
                                            tag: TAG_NETWORKING,
                                            zeroBuffer: false,
                                            align: ALIGN_16,
                                            heap: HEAP_DEFAULTHEAP);
      if ( v20 == nullptr )
        goto LABEL_4;
      v6 = 255;
      v7 = &idClientGameMsg_UseFocus::`vftable';
      v20->peerMask = -1;
      v20->__vftable = (idClientGameMsg_HandsThrow_vtbl *)&idClientGameMsg_UseFocus::`vftable';
      v12 = v20;
      v20->fp.attacker.spawnId = 0;
      v13 = msg;
      v20->fp.presentableWeapon.spawnId = 0;
      v20->fp.weapon = nullptr;
      v14 = this;
      goto LABEL_34;
    case '-':
      v21 = (idClientGameMsg_HandsThrow *)idMem::AllocWithLocation(
                                            this: &mem,
                                            location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                            size: 0x94u,
                                            tag: TAG_NETWORKING,
                                            zeroBuffer: false,
                                            align: ALIGN_16,
                                            heap: HEAP_DEFAULTHEAP);
      v22 = v21;
      v12 = nullptr;
      if ( v21 != nullptr )
      {
        v21->peerMask = -1;
        v21->__vftable = (idClientGameMsg_HandsThrow_vtbl *)&idClientGameMsg_MeleeHit::`vftable';
        v21->fp.attacker.spawnId = 0;
        v21->fp.presentableWeapon.spawnId = 0x1FFF;
        v21->fp.weapon = nullptr;
        memset(Dst: &v21->fp.ignoreEntityNum, Val: 0, Size: 0x80u);
        v12 = v22;
      }
      v13 = msg;
      v14 = this;
      goto LABEL_34;
    case '.':
      v19 = (idClientGameMsg_HandsThrow *)idMem::AllocWithLocation(
                                            this: &mem,
                                            location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                            size: 0x34u,
                                            tag: TAG_NETWORKING,
                                            zeroBuffer: false,
                                            align: ALIGN_16,
                                            heap: HEAP_DEFAULTHEAP);
      if ( v19 == nullptr )
        goto LABEL_4;
      v6 = 255;
      v7 = &idClientGameMsg_DropItem::`vftable';
      v19->peerMask = -1;
      v19->__vftable = (idClientGameMsg_HandsThrow_vtbl *)&idClientGameMsg_DropItem::`vftable';
      p_weapon = (void **)&v19->fp.weapon;
      v19->fp.weapon = nullptr;
      v12 = v19;
      v19->fp.ignoreEntityNum = 0;
      v13 = msg;
      v19->fp.targetList.list = nullptr;
      v19->fp.targetList.num = 0;
      v19->fp.targetList.size = 0;
      *(_DWORD *)&v19->fp.targetList.granularity = 0;
      v19->fp.target.spawnId = 0;
      v19->fp.targetPos.x = 0.0;
      v19->fp.attacker.spawnId = 0;
      v19->fp.presentableWeapon.spawnId = 0;
      v14 = this;
      goto LABEL_34;
    case '/':
      v23 = (idClientGameMsg_HandsThrow *)idMem::AllocWithLocation(
                                            this: &mem,
                                            location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                            size: 0xCu,
                                            tag: TAG_NETWORKING,
                                            zeroBuffer: false,
                                            align: ALIGN_16,
                                            heap: HEAP_DEFAULTHEAP);
      if ( v23 == nullptr )
        goto LABEL_4;
      v6 = 255;
      v7 = &idClientGameMsg_VehicleCrosshairChangeTarget::`vftable';
      v23->peerMask = -1;
      v23->__vftable = (idClientGameMsg_HandsThrow_vtbl *)&idClientGameMsg_VehicleCrosshairChangeTarget::`vftable';
      v12 = v23;
      v23->fp.attacker.spawnId = 0;
      v13 = msg;
      v23->fp.attacker.spawnId = 0;
      v14 = this;
      goto LABEL_34;
    case '0':
      v24 = (idClientGameMsg_HandsThrow *)idMem::AllocWithLocation(
                                            this: &mem,
                                            location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                            size: 0xCu,
                                            tag: TAG_NETWORKING,
                                            zeroBuffer: false,
                                            align: ALIGN_16,
                                            heap: HEAP_DEFAULTHEAP);
      if ( v24 == nullptr )
        goto LABEL_4;
      v6 = 255;
      v7 = &idClientGameMsg_VehicleWeaponChange::`vftable';
      v24->peerMask = -1;
      v24->__vftable = (idClientGameMsg_HandsThrow_vtbl *)&idClientGameMsg_VehicleWeaponChange::`vftable';
      v12 = v24;
      v24->fp.attacker.spawnId = 0;
      v13 = msg;
      v24->fp.attacker.spawnId = 0;
      v14 = this;
      goto LABEL_34;
    case '1':
      v25 = (idClientGameMsg_HandsThrow *)idMem::AllocWithLocation(
                                            this: &mem,
                                            location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                            size: 0x14u,
                                            tag: TAG_NETWORKING,
                                            zeroBuffer: false,
                                            align: ALIGN_16,
                                            heap: HEAP_DEFAULTHEAP);
      if ( v25 == nullptr )
        goto LABEL_4;
      v6 = 255;
      v7 = &idClientGameMsg_UpdateStat::`vftable';
      v25->peerMask = -1;
      v25->__vftable = (idClientGameMsg_HandsThrow_vtbl *)&idClientGameMsg_UpdateStat::`vftable';
      v12 = v25;
      v25->fp.attacker.spawnId = 0;
      v13 = msg;
      v25->fp.attacker.spawnId = 0;
      v25->fp.presentableWeapon.spawnId = 0;
      v25->fp.weapon = nullptr;
      v14 = this;
      goto LABEL_34;
    case '2':
      v26 = (idClientGameMsg_HandsThrow *)idMem::AllocWithLocation(
                                            this: &mem,
                                            location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                            size: 0x14u,
                                            tag: TAG_NETWORKING,
                                            zeroBuffer: false,
                                            align: ALIGN_16,
                                            heap: HEAP_DEFAULTHEAP);
      if ( v26 != nullptr )
      {
        v6 = 255;
        v7 = &idClientGameMsg_ActorModifier::`vftable';
        v26->peerMask = -1;
        v26->__vftable = (idClientGameMsg_HandsThrow_vtbl *)&idClientGameMsg_ActorModifier::`vftable';
        v12 = v26;
        v26->fp.attacker.spawnId = 0;
        v13 = msg;
        v26->fp.presentableWeapon.spawnId = 0;
        HIBYTE(v26->fp.weapon) = 0;
        v14 = this;
      }
      else
      {
LABEL_4:
        v12 = nullptr;
        v13 = msg;
        v14 = this;
      }
      goto LABEL_34;
    case ':':
      v27 = (idClientGameMsg_PostGameScoreRecap *)idMem::AllocWithLocation(
                                                    this: &mem,
                                                    location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                                    size: 0x18u,
                                                    tag: TAG_NETWORKING,
                                                    zeroBuffer: false,
                                                    align: ALIGN_16,
                                                    heap: HEAP_DEFAULTHEAP);
      if ( v27 != nullptr )
        v12 = (idClientGameMsg_HandsThrow *)idClientGameMsg_PostGameScoreRecap::idClientGameMsg_PostGameScoreRecap(this: v27);
      else
        v12 = nullptr;
      v13 = msg;
      v14 = this;
LABEL_34:
      idClientGame::QueueReliableClientGameMsg(
        this: v14,
        gameMsg: v12,
        bitMsg: v13,
        a4: v10,
        a5: v9,
        a6: (int)p_weapon,
        a7: (int)v7,
        a8: v6,
        a9: v28,
        a10: v29,
        a11: v30,
        a12: v31,
        a13: v32,
        a14: v33);
      break;
    default:
      return;
  }
}


// ========================================================================
// __unwind$494634
// EA  : 0x82B5CE04
// RVA : 0x00B5CE04
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_reliable.cpp
// ========================================================================

void _unwind_494634()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_NETWORKING);
}


// ========================================================================
// __unwind$494644
// EA  : 0x82B5CE30
// RVA : 0x00B5CE30
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_reliable.cpp
// ========================================================================

void _unwind_494644()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_NETWORKING);
}


// ========================================================================
// ?AddInt@idClientGameMsg_PostGameScoreRecap@@QAAXPBVidDeclMetric@@HH@Z
// EA  : 0x82B5CE60
// RVA : 0x00B5CE60
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_reliable.cpp
// ========================================================================

void __fastcall idClientGameMsg_PostGameScoreRecap::AddInt(
        idClientGameMsg_PostGameScoreRecap *this,
        const idDeclMetric *metricDecl,
        int playerIndex,
        int val)
{
  idClientGameMsg_PostGameScoreRecap::scoreItem_t *v7; // r3

  if ( metricDecl != nullptr )
  {
    v7 = idList<idClientGameMsg_PostGameScoreRecap::scoreItem_t,5>::Alloc(this: &this->items);
    v7->intValue = val;
    v7->isFloat = false;
    v7->metric = metricDecl;
    v7->playerIndex = playerIndex;
  }
}


// ========================================================================
// `dynamic initializer for 'cg_reliable_debug''
// EA  : 0x8336D630
// RVA : 0x0136D630
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_reliable.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__cg_reliable_debug__()
{
  idCVar::idCVar(
    this: &cg_reliable_debug,
    name: "cg_reliable_debug",
    value: "0",
    flags: 1,
    description: "Debug reliable client game msgs",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__cg_reliable_debug__);
}


// ========================================================================
// `dynamic initializer for 'cg_projectile_ignoreGrenades''
// EA  : 0x8336D688
// RVA : 0x0136D688
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_reliable.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__cg_projectile_ignoreGrenades__()
{
  idCVar::idCVar(
    this: &cg_projectile_ignoreGrenades,
    name: "cg_projectile_ignoreGrenades",
    value: "0",
    flags: 1,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__cg_projectile_ignoreGrenades__);
}


// ========================================================================
// `dynamic initializer for 'cg_projectile_grenadeDeathDropVelocity''
// EA  : 0x8336D6E0
// RVA : 0x0136D6E0
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_reliable.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__cg_projectile_grenadeDeathDropVelocity__()
{
  idCVar::idCVar(
    this: &cg_projectile_grenadeDeathDropVelocity,
    name: "cg_projectile_grenadeDeathDropVelocity",
    value: "300.0",
    flags: 4,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__cg_projectile_grenadeDeathDropVelocity__);
}

