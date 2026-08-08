
// ========================================================================
// ?Reset@idRageMetrics@@QAAXXZ
// EA  : 0x82DDE9F0
// RVA : 0x00DDE9F0
// PDB : w:\tech5\tungsten\game\metrics\ragemetrics.cpp
// ========================================================================

void __fastcall idRageMetrics::Reset(idRageMetrics *this)
{
  this->players[0].inGame = false;
  this->players[1].inGame = false;
  this->players[2].inGame = false;
  this->players[3].inGame = false;
  this->players[4].inGame = false;
  this->players[5].inGame = false;
}


// ========================================================================
// ?BeginGame@idRageMetrics@@QAAXABVidGameChallenge@@@Z
// EA  : 0x82DDEA10
// RVA : 0x00DDEA10
// PDB : w:\tech5\tungsten\game\metrics\ragemetrics.cpp
// ========================================================================

void __fastcall idRageMetrics::BeginGame(idRageMetrics *this, const idGameChallenge *challenge)
{
  idRagePlayerMetrics *players; // r30
  int i; // r31

  this->gameChallenge = challenge;
  players = this->players;
  for ( i = 6; i != 0; --i )
    idRagePlayerMetrics::BeginGame(this: players++, challenge);
}


// ========================================================================
// ?HandlePlayerMetricsMsg@idRageMetrics@@QAAXAAVidBitMsg@@H@Z
// EA  : 0x82DDEA50
// RVA : 0x00DDEA50
// PDB : w:\tech5\tungsten\game\metrics\ragemetrics.cpp
// ========================================================================

void __fastcall idRageMetrics::HandlePlayerMetricsMsg(idRageMetrics *this, idBitMsg *msg, int playerId)
{
  idRagePlayerMetrics *v3; // r31

  v3 = &this->players[playerId];
  idRagePlayerMetrics::ReadSessionData(this: v3, msg);
  idRagePlayerMetrics::UpdateLevel(this: v3);
  idRagePlayerMetrics::AggregateStats(this: v3);
}


// ========================================================================
// ?HandlePlayerUnlockMetricsMsg@idRageMetrics@@QAAXAAVidBitMsg@@H@Z
// EA  : 0x82DDEA98
// RVA : 0x00DDEA98
// PDB : w:\tech5\tungsten\game\metrics\ragemetrics.cpp
// ========================================================================

void __fastcall idRageMetrics::HandlePlayerUnlockMetricsMsg(idRageMetrics *this, idBitMsg *msg, int playerId)
{
  idRagePlayerMetrics *v3; // r31

  v3 = &this->players[playerId];
  idRagePlayerMetrics::ReadSessionUnlockData(this: v3, msg);
  idRagePlayerMetrics::AggregateUnlockStats(this: v3);
}


// ========================================================================
// ?GetDriver@idRageMetrics@@AAAPAVidEntity@@PBVidVehicle@@@Z
// EA  : 0x82DDEAD8
// RVA : 0x00DDEAD8
// PDB : w:\tech5\tungsten\game\metrics\ragemetrics.cpp
// ========================================================================

idEntity *__fastcall idRageMetrics::GetDriver(idRageMetrics *this, idVehicle_Car *vehicle)
{
  idEntity *Driver; // r30
  idVehicle_Car *v4; // r3

  Driver = idVehicle::GetDriver(this: vehicle);
  if ( Driver != nullptr )
    return Driver;
  v4 = idVehicle_Car::CastTo(c: vehicle);
  if ( v4 == nullptr )
    return Driver;
  else
    return idVehicle::GetCachedPlayerDriver(this: v4);
}


// ========================================================================
// ?GetStatInt@idRageMetrics@@QAAHPAVidLocalUser@@W4rageStat_t@@@Z
// EA  : 0x82DDEB38
// RVA : 0x00DDEB38
// PDB : w:\tech5\tungsten\game\metrics\ragemetrics.cpp
// ========================================================================

idLocalUser *__fastcall idRageMetrics::GetStatInt(idRageMetrics *this, idLocalUser *user, int stat)
{
  idLocalUser *result; // r3

  result = user;
  if ( user != nullptr )
    return (idLocalUser *)user->GetStatInt(this: user, a2: stat);
  return result;
}


// ========================================================================
// ?ResetStats@idRageMetrics@@QAAXPBVidPlayer@@@Z
// EA  : 0x82DDEB60
// RVA : 0x00DDEB60
// PDB : w:\tech5\tungsten\game\metrics\ragemetrics.cpp
// ========================================================================

void __fastcall idRageMetrics::ResetStats(idRageMetrics *this, const idPlayer *player)
{
  if ( player != nullptr )
    idRagePlayerMetrics::ResetStats(this: &this->players[player->entityNumber]);
  else
    idLib::Warning(fmt: "[%s] Invalid player", "idRageMetrics::ResetStats");
}


// ========================================================================
// ?AddPlayer@idRageMetrics@@QAAXAAVidPlayer@@@Z
// EA  : 0x82DDEB90
// RVA : 0x00DDEB90
// PDB : w:\tech5\tungsten\game\metrics\ragemetrics.cpp
// ========================================================================

void __fastcall idRageMetrics::AddPlayer(idRageMetrics *this, idPlayer *player)
{
  this->players[player->entityNumber].inGame = true;
}


// ========================================================================
// ?RemovePlayer@idRageMetrics@@QAAXAAVidPlayer@@@Z
// EA  : 0x82DDEBA8
// RVA : 0x00DDEBA8
// PDB : w:\tech5\tungsten\game\metrics\ragemetrics.cpp
// ========================================================================

void __fastcall idRageMetrics::RemovePlayer(idRageMetrics *this, idPlayer *player)
{
  idRagePlayerMetrics::ResetStats(this: &this->players[player->entityNumber]);
  this->players[player->entityNumber].inGame = false;
}


// ========================================================================
// ?GainXP@idRageMetrics@@QAAXHH@Z
// EA  : 0x82DDEC08
// RVA : 0x00DDEC08
// PDB : w:\tech5\tungsten\game\metrics\ragemetrics.cpp
// ========================================================================

void __fastcall idRageMetrics::GainXP(idRageMetrics *this, int playerId, int xp)
{
  char *v3; // r11

  v3 = (char *)this + 5000 * playerId;
  if ( v3 != (char *)-12 )
    idRagePlayerMetrics::GainXP(this: (idRagePlayerMetrics *)(v3 + 12), xp, xpSource: nullptr);
}


// ========================================================================
// ?UpdateLevel@idRageMetrics@@QAAXH@Z
// EA  : 0x82DDEC30
// RVA : 0x00DDEC30
// PDB : w:\tech5\tungsten\game\metrics\ragemetrics.cpp
// ========================================================================

void __fastcall idRageMetrics::UpdateLevel(idRageMetrics *this, int playerId)
{
  char *v2; // r11

  v2 = (char *)this + 5000 * playerId;
  if ( v2 != (char *)-12 )
    idRagePlayerMetrics::UpdateLevel(this: (idRagePlayerMetrics *)(v2 + 12));
}


// ========================================================================
// ?Revenge@idRageMetrics@@QAAXHH@Z
// EA  : 0x82DDEC48
// RVA : 0x00DDEC48
// PDB : w:\tech5\tungsten\game\metrics\ragemetrics.cpp
// ========================================================================

void __fastcall idRageMetrics::Revenge(idRageMetrics *this, int victimNum, int killerNum)
{
  char *v3; // r11

  v3 = (char *)this + 5000 * killerNum;
  if ( v3 != (char *)-12 )
    idRagePlayerMetrics::Revenge(this: (idRagePlayerMetrics *)(v3 + 12), victimEntityNum: victimNum);
}


// ========================================================================
// ?GetPlayerMetrics@idRageMetrics@@QAAPAVidRagePlayerMetrics@@PBVidEntity@@@Z
// EA  : 0x82DDEC60
// RVA : 0x00DDEC60
// PDB : w:\tech5\tungsten\game\metrics\ragemetrics.cpp
// ========================================================================

idRagePlayerMetrics *__fastcall idRageMetrics::GetPlayerMetrics(idRageMetrics *this, idVehicle *entity)
{
  idVehicle *PlayerFromEntity; // r3

  PlayerFromEntity = idGameLocal::GetPlayerFromEntity(this: gameLocal, activator: entity);
  if ( PlayerFromEntity != nullptr )
    return &this->players[PlayerFromEntity->entityNumber];
  else
    return nullptr;
}


// ========================================================================
// ?GetPlayerMetrics@idRageMetrics@@QAAPAVidRagePlayerMetrics@@ABVidVehicle@@@Z
// EA  : 0x82DDECC0
// RVA : 0x00DDECC0
// PDB : w:\tech5\tungsten\game\metrics\ragemetrics.cpp
// ========================================================================

idRagePlayerMetrics *__fastcall idRageMetrics::GetPlayerMetrics(idRageMetrics *this, idVehicle_Car *vehicle)
{
  idVehicle *Driver; // r31
  idVehicle_Car *v5; // r3
  idVehicle *PlayerFromEntity; // r3

  Driver = (idVehicle *)idVehicle::GetDriver(this: vehicle);
  if ( Driver == nullptr )
  {
    v5 = idVehicle_Car::CastTo(c: vehicle);
    if ( v5 != nullptr )
      Driver = (idVehicle *)idVehicle::GetCachedPlayerDriver(this: v5);
  }
  PlayerFromEntity = idGameLocal::GetPlayerFromEntity(this: gameLocal, activator: Driver);
  if ( PlayerFromEntity != nullptr )
    return &this->players[PlayerFromEntity->entityNumber];
  else
    return nullptr;
}


// ========================================================================
// ?GetSessionStat@idRageMetrics@@QBAHHW4rageStat_t@@@Z
// EA  : 0x82DDED40
// RVA : 0x00DDED40
// PDB : w:\tech5\tungsten\game\metrics\ragemetrics.cpp
// ========================================================================

int __fastcall idRageMetrics::GetSessionStat(idRageMetrics *this, int playerId, rageStat_t stat)
{
  idRageStat *v3; // r31

  v3 = &this->players[playerId].stats.list[stat];
  if ( RageStatTypeIsInt(stat) )
    return v3->sessionValue.i;
  else
    return (int)v3->sessionValue.f;
}


// ========================================================================
// ?GetSessionStatFloat@idRageMetrics@@QBAMHW4rageStat_t@@@Z
// EA  : 0x82DDEDC0
// RVA : 0x00DDEDC0
// PDB : w:\tech5\tungsten\game\metrics\ragemetrics.cpp
// ========================================================================

float __fastcall idRageMetrics::GetSessionStatFloat(idRageMetrics *this, int playerId, rageStat_t stat)
{
  idRageStat *v3; // r31
  __int64 v4; // r10
  double f; // fp1

  v3 = &this->players[playerId].stats.list[stat];
  HIDWORD(v4) = RageStatTypeIsInt(stat);
  if ( HIDWORD(v4) != 0 )
  {
    LODWORD(v4) = v3->sessionValue.i;
    f = (float)v4;
  }
  else
  {
    f = v3->sessionValue.f;
  }
  return *((float *)&f + 1);
}


// ========================================================================
// ?GetStatInt@idRageMetrics@@QAAHPBVidPlayer@@W4rageStat_t@@@Z
// EA  : 0x82DDEE48
// RVA : 0x00DDEE48
// PDB : w:\tech5\tungsten\game\metrics\ragemetrics.cpp
// ========================================================================

int __fastcall idRageMetrics::GetStatInt(idRageMetrics *this, idPlayer *player, int stat)
{
  idLocalUser *LocalUser; // r3

  if ( player != nullptr && (LocalUser = idPlayer::GetLocalUser(this: player)) != nullptr )
    return LocalUser->GetStatInt(this: LocalUser, a2: stat);
  else
    return 0;
}


// ========================================================================
// ?GetStatFloat@idRageMetrics@@QAAMPBVidPlayer@@W4rageStat_t@@@Z
// EA  : 0x82DDEEB8
// RVA : 0x00DDEEB8
// PDB : w:\tech5\tungsten\game\metrics\ragemetrics.cpp
// ========================================================================

float __fastcall idRageMetrics::GetStatFloat(idRageMetrics *this, idPlayer *player, int stat)
{
  double v4; // fp1
  idLocalUser *LocalUser; // r3

  if ( player != nullptr && (LocalUser = idPlayer::GetLocalUser(this: player)) != nullptr )
    v4 = LocalUser->GetStatFloat(this: LocalUser, a2: stat);
  else
    v4 = 0.0;
  return *((float *)&v4 + 1);
}


// ========================================================================
// ?StatAddInt@idRageMetrics@@QAAXPBVidPlayer@@W4rageStat_t@@H@Z
// EA  : 0x82DDEF28
// RVA : 0x00DDEF28
// PDB : w:\tech5\tungsten\game\metrics\ragemetrics.cpp
// ========================================================================

void __fastcall idRageMetrics::StatAddInt(idRageMetrics *this, const idPlayer *player, rageStat_t stat, int value)
{
  char *v4; // r10

  if ( player != nullptr )
  {
    v4 = (char *)this + 5000 * player->entityNumber;
    if ( v4 != (char *)-12 )
      idRagePlayerMetrics::StatAddInt(this: (idRagePlayerMetrics *)(v4 + 12), stat, value);
  }
}


// ========================================================================
// ?StatAddFloat@idRageMetrics@@QAAXPBVidPlayer@@W4rageStat_t@@M@Z
// EA  : 0x82DDEF58
// RVA : 0x00DDEF58
// PDB : w:\tech5\tungsten\game\metrics\ragemetrics.cpp
// ========================================================================

void __fastcall idRageMetrics::StatAddFloat(idRageMetrics *this, const idPlayer *player, rageStat_t stat, double value)
{
  char *v4; // r10

  if ( player != nullptr )
  {
    v4 = (char *)this + 5000 * player->entityNumber;
    if ( v4 != (char *)-12 )
      idRagePlayerMetrics::StatAddFloat(this: (idRagePlayerMetrics *)(v4 + 12), stat, value);
  }
}


// ========================================================================
// ?AreTeammates@idRageMetrics@@ABA_NPBVidRagePlayerMetrics@@0@Z
// EA  : 0x82DDEF88
// RVA : 0x00DDEF88
// PDB : w:\tech5\tungsten\game\metrics\ragemetrics.cpp
// ========================================================================

int __fastcall idRageMetrics::AreTeammates(
        idRageMetrics *this,
        const idRagePlayerMetrics *player1,
        const idRagePlayerMetrics *player2)
{
  idPlayer *Player; // r31
  idPlayer *v5; // r3
  idEntity *v6; // r30
  gameTeam_t Team; // r31
  unsigned __int8 v8; // r11

  if ( player1 == nullptr )
    return 0;
  if ( player2 == nullptr )
    return 0;
  Player = idGameLocal::GetPlayer(this: gameLocal, i: player1->entityNumber);
  v5 = idGameLocal::GetPlayer(this: gameLocal, i: player2->entityNumber);
  v6 = v5;
  if ( Player == nullptr || v5 == nullptr )
    return 0;
  Team = idEntity::GetTeam(this: Player);
  if ( Team != idEntity::GetTeam(this: v6) )
    return 0;
  v8 = 1;
  if ( Team == TEAM_NONE )
    return 0;
  return v8;
}


// ========================================================================
// ?IsLeader@idRageMetrics@@ABA_NPBVidRagePlayerMetrics@@@Z
// EA  : 0x82DDF038
// RVA : 0x00DDF038
// PDB : w:\tech5\tungsten\game\metrics\ragemetrics.cpp
// ========================================================================

BOOL __fastcall idRageMetrics::IsLeader(idRageMetrics *this, const idRagePlayerMetrics *playerMetrics)
{
  const idGameChallenge *gameChallenge; // r11

  return playerMetrics != nullptr
      && (gameChallenge = this->gameChallenge) != nullptr
      && (_cntlzw(((int (*)(void))gameChallenge->GetLeaderEntityNumber)() - playerMetrics->entityNumber) & 0x20) != 0;
}


// ========================================================================
// ?GetLevelStats@idRageMetrics@@QAAABVidLevelStats@@ABVidPlayer@@@Z
// EA  : 0x82DDF0B0
// RVA : 0x00DDF0B0
// PDB : w:\tech5\tungsten\game\metrics\ragemetrics.cpp
// ========================================================================

void __fastcall idRageMetrics::GetLevelStats(idRageMetrics *this, const idPlayer *player)
{
  if ( (idRageMetrics *)((char *)this + 5000 * player->entityNumber) == (idRageMetrics *)-12 )
    idLib::Error(fmt: "Invalid playerMetrics for player");
}


// ========================================================================
// ?ClearLevelStats@idRageMetrics@@QAAXABVidPlayer@@@Z
// EA  : 0x82DDF0D8
// RVA : 0x00DDF0D8
// PDB : w:\tech5\tungsten\game\metrics\ragemetrics.cpp
// ========================================================================

void __fastcall idRageMetrics::ClearLevelStats(idRageMetrics *this, const idPlayer *player)
{
  char *v2; // r10

  v2 = (char *)this + 5000 * player->entityNumber;
  if ( v2 == (char *)-12 )
    idLib::Error(fmt: "Invalid playerMetrics for player");
  else
    idLevelStats::Clear(this: (idLevelStats *)(v2 + 3300));
}


// ========================================================================
// ?AwardMost@idRageMetrics@@AAAXW4rageStat_t@@0PAVidClientGameMsg_PostGameScoreRecap@@@Z
// EA  : 0x82DDF100
// RVA : 0x00DDF100
// PDB : w:\tech5\tungsten\game\metrics\ragemetrics.cpp
// ========================================================================

void __fastcall idRageMetrics::AwardMost(
        idRageMetrics *this,
        rageStat_t criteria,
        rageStat_t award,
        idClientGameMsg_PostGameScoreRecap *msg)
{
  idStaticList<idRageStat,256> *p_stats; // r30
  int v8; // r26
  int v9; // r28
  idStaticList<idRageStat,256> *v10; // r29
  idClientGame *LobbyUserIdFromPlayerIndex; // r3
  char v12; // r11
  __int32 v13; // r31
  int v14; // r11
  int i; // r29
  idClientGame *v16; // r3
  char v17; // r11
  __int32 v18; // r31
  int v19; // r11
  _BYTE v20[88]; // [sp+58h] [-58h] BYREF

  p_stats = &this->players[0].stats;
  v8 = 0;
  v9 = 0;
  v10 = &this->players[0].stats;
  do
  {
    LobbyUserIdFromPlayerIndex = idClientGame::GetLobbyUserIdFromPlayerIndex(
                                   this: (idClientGame *)v20,
                                   result: (lobbyUserID_t *)clientGame,
                                   playerIndex: v9);
    if ( LobbyUserIdFromPlayerIndex->random.seed == 0
      || (v12 = 1, HIBYTE(LobbyUserIdFromPlayerIndex->renderWorld) == 255) )
    {
      v12 = 0;
    }
    if ( v12 != 0 )
    {
      v13 = (__int32)&v10->list[criteria];
      v14 = RageStatTypeIsInt(stat: criteria) ? *(_DWORD *)(v13 + 4) : (int)*(float *)(v13 + 4);
      if ( v14 > v8 )
        v8 = v14;
    }
    ++v9;
    v10 = (idStaticList<idRageStat,256> *)((char *)v10 + 5000);
  }
  while ( v9 < 6 );
  if ( v8 != 0 )
  {
    for ( i = 0; i < 6; ++i )
    {
      v16 = idClientGame::GetLobbyUserIdFromPlayerIndex(
              this: (idClientGame *)v20,
              result: (lobbyUserID_t *)clientGame,
              playerIndex: i);
      if ( v16->random.seed == 0 || (v17 = 1, HIBYTE(v16->renderWorld) == 255) )
        v17 = 0;
      if ( v17 != 0 )
      {
        v18 = (__int32)&p_stats->list[criteria];
        if ( RageStatTypeIsInt(stat: criteria) )
          v19 = *(_DWORD *)(v18 + 4);
        else
          v19 = (int)*(float *)(v18 + 4);
        if ( v19 == v8 )
        {
          idRagePlayerMetrics::Award(this: (idRagePlayerMetrics *)&p_stats[-1].staticList[255], award);
          if ( msg != nullptr )
            idClientGameMsg_PostGameScoreRecap::AddInt(
              this: msg,
              metricDecl: p_stats->list[award].decl,
              playerIndex: i,
              val: v8);
        }
      }
      p_stats = (idStaticList<idRageStat,256> *)((char *)p_stats + 5000);
    }
  }
}


// ========================================================================
// ?AwardLeast@idRageMetrics@@AAAXW4rageStat_t@@0PAVidClientGameMsg_PostGameScoreRecap@@@Z
// EA  : 0x82DDF2A8
// RVA : 0x00DDF2A8
// PDB : w:\tech5\tungsten\game\metrics\ragemetrics.cpp
// ========================================================================

void __fastcall idRageMetrics::AwardLeast(
        idRageMetrics *this,
        rageStat_t criteria,
        rageStat_t award,
        idClientGameMsg_PostGameScoreRecap *msg)
{
  idStaticList<idRageStat,256> *p_stats; // r30
  int v8; // r28
  idStaticList<idRageStat,256> *v9; // r29
  int v10; // r25
  idClientGame *LobbyUserIdFromPlayerIndex; // r3
  char v12; // r11
  __int32 v13; // r31
  int v14; // r11
  int i; // r29
  idClientGame *v16; // r3
  char v17; // r11
  __int32 v18; // r31
  int v19; // r11
  _BYTE v20[104]; // [sp+58h] [-68h] BYREF

  p_stats = &this->players[0].stats;
  v8 = 0;
  v9 = &this->players[0].stats;
  v10 = 0x7FFFFFFF;
  do
  {
    if ( HIBYTE(v9[1].staticList[1].sessionValue.f) != 0 )
    {
      LobbyUserIdFromPlayerIndex = idClientGame::GetLobbyUserIdFromPlayerIndex(
                                     this: (idClientGame *)v20,
                                     result: (lobbyUserID_t *)clientGame,
                                     playerIndex: v8);
      if ( LobbyUserIdFromPlayerIndex->random.seed == 0
        || (v12 = 1, HIBYTE(LobbyUserIdFromPlayerIndex->renderWorld) == 255) )
      {
        v12 = 0;
      }
      if ( v12 != 0 )
      {
        v13 = (__int32)&v9->list[criteria];
        v14 = RageStatTypeIsInt(stat: criteria) ? *(_DWORD *)(v13 + 4) : (int)*(float *)(v13 + 4);
        if ( v14 < v10 )
          v10 = v14;
      }
    }
    ++v8;
    v9 = (idStaticList<idRageStat,256> *)((char *)v9 + 5000);
  }
  while ( v8 < 6 );
  if ( v10 != 0x7FFFFFFF )
  {
    for ( i = 0; i < 6; ++i )
    {
      if ( HIBYTE(p_stats[1].staticList[1].sessionValue.f) != 0 )
      {
        v16 = idClientGame::GetLobbyUserIdFromPlayerIndex(
                this: (idClientGame *)v20,
                result: (lobbyUserID_t *)clientGame,
                playerIndex: i);
        if ( v16->random.seed == 0 || (v17 = 1, HIBYTE(v16->renderWorld) == 255) )
          v17 = 0;
        if ( v17 != 0 )
        {
          v18 = (__int32)&p_stats->list[criteria];
          if ( RageStatTypeIsInt(stat: criteria) )
            v19 = *(_DWORD *)(v18 + 4);
          else
            v19 = (int)*(float *)(v18 + 4);
          if ( v19 == v10 )
          {
            idRagePlayerMetrics::Award(this: (idRagePlayerMetrics *)&p_stats[-1].staticList[255], award);
            if ( msg != nullptr )
              idClientGameMsg_PostGameScoreRecap::AddInt(
                this: msg,
                metricDecl: p_stats->list[award].decl,
                playerIndex: i,
                val: v10);
          }
        }
      }
      p_stats = (idStaticList<idRageStat,256> *)((char *)p_stats + 5000);
    }
  }
}


// ========================================================================
// ?Drive@idRageMetrics@@QAAXABVidVehicle_Car@@H@Z
// EA  : 0x82DDF470
// RVA : 0x00DDF470
// PDB : w:\tech5\tungsten\game\metrics\ragemetrics.cpp
// ========================================================================

void __fastcall idRageMetrics::Drive(idRageMetrics *this, idVehicle_Car *car, int deltaTime)
{
  idRagePlayerMetrics *PlayerMetrics; // r31
  idPhysics *Physics; // r3
  float *v7; // r28
  double v8; // fp31
  double v9; // fp30
  double v10; // fp29
  int v11; // r4

  if ( !this->gameEnded )
  {
    PlayerMetrics = idRageMetrics::GetPlayerMetrics(this, vehicle: car);
    if ( PlayerMetrics != nullptr )
    {
      Physics = idEntity::GetPhysics(this: car);
      v7 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
      v8 = (float)(PlayerMetrics->origin.x - *v7);
      v9 = (float)(PlayerMetrics->origin.y - v7[1]);
      v10 = (float)(PlayerMetrics->origin.z - v7[2]);
      idVehicle_Car::GetNumWheelsOnGround(this: car);
      idRagePlayerMetrics::Travel(
        this: PlayerMetrics,
        distance: __fsqrts((float)((float)((float)v10 * (float)v10)
                       + (float)((float)((float)v8 * (float)v8) + (float)((float)v9 * (float)v9)))),
        timeMs: v11,
        wheelsOnGround: deltaTime);
      PlayerMetrics->origin.x = *v7;
      PlayerMetrics->origin.y = v7[1];
      PlayerMetrics->origin.z = v7[2];
    }
  }
}


// ========================================================================
// ?EnterVehicle@idRageMetrics@@QAAXABVidVehicle_Car@@ABVidPlayer@@@Z
// EA  : 0x82DDF548
// RVA : 0x00DDF548
// PDB : w:\tech5\tungsten\game\metrics\ragemetrics.cpp
// ========================================================================

void __fastcall idRageMetrics::EnterVehicle(idRageMetrics *this, const idVehicle_Car *car, const idPlayer *player)
{
  char *v3; // r9
  char *v4; // r31
  idPhysics *Physics; // r3
  float *v6; // r3
  idGameLocal *v7; // r3
  double v8; // fp12
  idGameLocal_vtbl *v9; // r7

  if ( !this->gameEnded )
  {
    v3 = (char *)this + 5000 * player->entityNumber;
    v4 = v3 + 12;
    if ( v3 != (char *)-12 )
    {
      Physics = idEntity::GetPhysics(this: &car->idVehicle);
      v6 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
      *((float *)v4 + 787) = *v6;
      *((float *)v4 + 788) = v6[1];
      v8 = v6[2];
      v7 = gameLocal;
      v9 = gameLocal->__vftable;
      *((float *)v4 + 789) = v8;
      *((_DWORD *)v4 + 784) = v9->GetGameMs(this: v7, a2: GAMETIME_SCALED);
    }
  }
}


// ========================================================================
// ?WeaponFired@idRageMetrics@@QAA?AUweaponStatsTag_t@@PAVidPlayer@@PBVidDecl@@@Z
// EA  : 0x82DDF5E8
// RVA : 0x00DDF5E8
// PDB : w:\tech5\tungsten\game\metrics\ragemetrics.cpp
// ========================================================================

idRageMetrics *__fastcall idRageMetrics::WeaponFired(
        idRageMetrics *this,
        weaponStatsTag_t *result,
        idVehicle *player,
        const idDecl *decl)
{
  idVehicle *PlayerFromEntity; // r3
  weaponStatsTag_t *v8; // r10

  PlayerFromEntity = idGameLocal::GetPlayerFromEntity(this: gameLocal, activator: player);
  if ( PlayerFromEntity != nullptr
    && (v8 = &result[1250 * PlayerFromEntity->entityNumber]) != (weaponStatsTag_t *)-12
    && decl != nullptr )
  {
    idRagePlayerMetrics::WeaponFired((idRagePlayerMetrics *)this, result: v8 + 3, decl);
    return this;
  }
  else
  {
    this->__vftable = nullptr;
    return this;
  }
}


// ========================================================================
// ?WeaponFiredResult@idRageMetrics@@QAAXPAVidPlayer@@UweaponStatsTag_t@@PAVidEntity@@M@Z
// EA  : 0x82DDF660
// RVA : 0x00DDF660
// PDB : w:\tech5\tungsten\game\metrics\ragemetrics.cpp
// ========================================================================

void __fastcall idRageMetrics::WeaponFiredResult(
        idRageMetrics *this,
        idVehicle *player,
        weaponStatsTag_t *tag,
        idEntity *target,
        double damage)
{
  idVehicle *PlayerFromEntity; // r3
  char *v10; // r10

  PlayerFromEntity = idGameLocal::GetPlayerFromEntity(this: gameLocal, activator: player);
  if ( PlayerFromEntity != nullptr )
  {
    v10 = (char *)this + 5000 * PlayerFromEntity->entityNumber;
    if ( v10 != (char *)-12 )
      idRagePlayerMetrics::WeaponFiredResult(this: (idRagePlayerMetrics *)(v10 + 12), tag, target, damage);
  }
}


// ========================================================================
// ?WeaponFiredDone@idRageMetrics@@QAAXPAVidPlayer@@UweaponStatsTag_t@@H@Z
// EA  : 0x82DDF6C8
// RVA : 0x00DDF6C8
// PDB : w:\tech5\tungsten\game\metrics\ragemetrics.cpp
// ========================================================================

void __fastcall idRageMetrics::WeaponFiredDone(
        idRageMetrics *this,
        idVehicle *player,
        weaponStatsTag_t *tag,
        int carryoverCount)
{
  idVehicle *PlayerFromEntity; // r3
  char *v8; // r10

  PlayerFromEntity = idGameLocal::GetPlayerFromEntity(this: gameLocal, activator: player);
  if ( PlayerFromEntity != nullptr )
  {
    v8 = (char *)this + 5000 * PlayerFromEntity->entityNumber;
    if ( v8 != (char *)-12 )
      idRagePlayerMetrics::WeaponFiredDone(this: (idRagePlayerMetrics *)(v8 + 12), tag, carryoverCount);
  }
}


// ========================================================================
// ?WeaponFiredResult_DirectHit@idRageMetrics@@QAAXPAVidPlayer@@PBVidDecl@@@Z
// EA  : 0x82DDF720
// RVA : 0x00DDF720
// PDB : w:\tech5\tungsten\game\metrics\ragemetrics.cpp
// ========================================================================

void __fastcall idRageMetrics::WeaponFiredResult_DirectHit(idRageMetrics *this, idVehicle *player, const idDecl *decl)
{
  idVehicle *PlayerFromEntity; // r3
  char *v6; // r10

  PlayerFromEntity = idGameLocal::GetPlayerFromEntity(this: gameLocal, activator: player);
  if ( PlayerFromEntity != nullptr )
  {
    v6 = (char *)this + 5000 * PlayerFromEntity->entityNumber;
    if ( v6 != (char *)-12 )
      idRagePlayerMetrics::WeaponFiredResult_DirectHit(this: (idRagePlayerMetrics *)(v6 + 12), decl);
  }
}


// ========================================================================
// ?ItemsTaken@idRageMetrics@@QAAXPBVidPlayer@@H@Z
// EA  : 0x82DDF788
// RVA : 0x00DDF788
// PDB : w:\tech5\tungsten\game\metrics\ragemetrics.cpp
// ========================================================================

void __fastcall idRageMetrics::ItemsTaken(idRageMetrics *this, idVehicle *player, int items)
{
  idVehicle *PlayerFromEntity; // r3
  char *v6; // r10

  PlayerFromEntity = idGameLocal::GetPlayerFromEntity(this: gameLocal, activator: player);
  if ( PlayerFromEntity != nullptr )
  {
    v6 = (char *)this + 5000 * PlayerFromEntity->entityNumber;
    if ( v6 != (char *)-12 )
      idRagePlayerMetrics::ItemsTaken(this: (idRagePlayerMetrics *)(v6 + 12), items);
  }
}


// ========================================================================
// ?ClientDamage@idRageMetrics@@QAAXPBVidPlayer@@MPBVidDeclDamage@@@Z
// EA  : 0x82DDF7F0
// RVA : 0x00DDF7F0
// PDB : w:\tech5\tungsten\game\metrics\ragemetrics.cpp
// ========================================================================

void __fastcall idRageMetrics::ClientDamage(
        idRageMetrics *this,
        idVehicle *player,
        double damage,
        const idDeclDamage *damageDef,
        const idDeclDamage *a5)
{
  idVehicle *PlayerFromEntity; // r3
  char *v9; // r10

  PlayerFromEntity = idGameLocal::GetPlayerFromEntity(this: gameLocal, activator: player);
  if ( PlayerFromEntity != nullptr )
  {
    v9 = (char *)this + 5000 * PlayerFromEntity->entityNumber;
    if ( v9 != (char *)-12 )
      idRagePlayerMetrics::ClientDamage(this: (idRagePlayerMetrics *)(v9 + 12), (int)damage, damageDef: a5);
  }
}


// ========================================================================
// ?Score_VDM@idRageMetrics@@QAAXPBVidEntity@@H@Z
// EA  : 0x82DDF870
// RVA : 0x00DDF870
// PDB : w:\tech5\tungsten\game\metrics\ragemetrics.cpp
// ========================================================================

void __fastcall idRageMetrics::Score_VDM(idRageMetrics *this, idVehicle *player, int score)
{
  idVehicle *PlayerFromEntity; // r3
  char *v6; // r10

  PlayerFromEntity = idGameLocal::GetPlayerFromEntity(this: gameLocal, activator: player);
  if ( PlayerFromEntity != nullptr )
  {
    v6 = (char *)this + 5000 * PlayerFromEntity->entityNumber;
    if ( v6 != (char *)-12 )
      idRagePlayerMetrics::Score_VDM(this: (idRagePlayerMetrics *)(v6 + 12), score);
  }
}


// ========================================================================
// ?Score_COOP@idRageMetrics@@QAAXPBVidEntity@@HH@Z
// EA  : 0x82DDF8D8
// RVA : 0x00DDF8D8
// PDB : w:\tech5\tungsten\game\metrics\ragemetrics.cpp
// ========================================================================

void __fastcall idRageMetrics::Score_COOP(idRageMetrics *this, idVehicle *player, int teamScore, int individualScore)
{
  idVehicle *PlayerFromEntity; // r3
  char *v8; // r10

  PlayerFromEntity = idGameLocal::GetPlayerFromEntity(this: gameLocal, activator: player);
  if ( PlayerFromEntity != nullptr )
  {
    v8 = (char *)this + 5000 * PlayerFromEntity->entityNumber;
    if ( v8 != (char *)-12 )
      idRagePlayerMetrics::Score_COOP(this: (idRagePlayerMetrics *)(v8 + 12), teamScore, individualScore);
  }
}


// ========================================================================
// ?SetTime@idRageMetrics@@QAAXPBVidEntity@@H@Z
// EA  : 0x82DDF930
// RVA : 0x00DDF930
// PDB : w:\tech5\tungsten\game\metrics\ragemetrics.cpp
// ========================================================================

void __fastcall idRageMetrics::SetTime(idRageMetrics *this, idVehicle *player, int time)
{
  idVehicle *PlayerFromEntity; // r3
  char *v6; // r10

  PlayerFromEntity = idGameLocal::GetPlayerFromEntity(this: gameLocal, activator: player);
  if ( PlayerFromEntity != nullptr )
  {
    v6 = (char *)this + 5000 * PlayerFromEntity->entityNumber;
    if ( v6 != (char *)-12 )
      idRagePlayerMetrics::SetTime(this: (idRagePlayerMetrics *)(v6 + 12), time);
  }
}


// ========================================================================
// ?UpdateTime@idRageMetrics@@QAAXPBVidPlayer@@H@Z
// EA  : 0x82DDF998
// RVA : 0x00DDF998
// PDB : w:\tech5\tungsten\game\metrics\ragemetrics.cpp
// ========================================================================

void __fastcall idRageMetrics::UpdateTime(idRageMetrics *this, idVehicle *player, int ms)
{
  idVehicle *PlayerFromEntity; // r3
  char *v6; // r10

  PlayerFromEntity = idGameLocal::GetPlayerFromEntity(this: gameLocal, activator: player);
  if ( PlayerFromEntity != nullptr )
  {
    v6 = (char *)this + 5000 * PlayerFromEntity->entityNumber;
    if ( v6 != (char *)-12 )
      idRagePlayerMetrics::UpdateTime(this: (idRagePlayerMetrics *)(v6 + 12), ms);
  }
}


// ========================================================================
// ?CoopChallengeWithoutDeath@idRageMetrics@@QAAXPBVidPlayer@@_N@Z
// EA  : 0x82DDFA00
// RVA : 0x00DDFA00
// PDB : w:\tech5\tungsten\game\metrics\ragemetrics.cpp
// ========================================================================

void __fastcall idRageMetrics::CoopChallengeWithoutDeath(idRageMetrics *this, idVehicle *player, bool nightmare)
{
  idVehicle *PlayerFromEntity; // r3
  char *v6; // r10

  PlayerFromEntity = idGameLocal::GetPlayerFromEntity(this: gameLocal, activator: player);
  if ( PlayerFromEntity != nullptr )
  {
    v6 = (char *)this + 5000 * PlayerFromEntity->entityNumber;
    if ( v6 != (char *)-12 )
      idRagePlayerMetrics::CoopChallengeWithoutDeath(this: (idRagePlayerMetrics *)(v6 + 12), nightmare);
  }
}


// ========================================================================
// ?CoopChallengeWithoutDefib@idRageMetrics@@QAAXPBVidPlayer@@_N@Z
// EA  : 0x82DDFA68
// RVA : 0x00DDFA68
// PDB : w:\tech5\tungsten\game\metrics\ragemetrics.cpp
// ========================================================================

void __fastcall idRageMetrics::CoopChallengeWithoutDefib(idRageMetrics *this, idVehicle *player, bool nightmare)
{
  idVehicle *PlayerFromEntity; // r3
  char *v6; // r10

  PlayerFromEntity = idGameLocal::GetPlayerFromEntity(this: gameLocal, activator: player);
  if ( PlayerFromEntity != nullptr )
  {
    v6 = (char *)this + 5000 * PlayerFromEntity->entityNumber;
    if ( v6 != (char *)-12 )
      idRagePlayerMetrics::CoopChallengeWithoutDefib(this: (idRagePlayerMetrics *)(v6 + 12), nightmare);
  }
}


// ========================================================================
// ?CoopChallengeHighestScoreRank@idRageMetrics@@QAAXPBVidPlayer@@_N@Z
// EA  : 0x82DDFAD0
// RVA : 0x00DDFAD0
// PDB : w:\tech5\tungsten\game\metrics\ragemetrics.cpp
// ========================================================================

void __fastcall idRageMetrics::CoopChallengeHighestScoreRank(idRageMetrics *this, idVehicle *player, bool nightmare)
{
  idVehicle *PlayerFromEntity; // r3
  char *v6; // r10

  PlayerFromEntity = idGameLocal::GetPlayerFromEntity(this: gameLocal, activator: player);
  if ( PlayerFromEntity != nullptr )
  {
    v6 = (char *)this + 5000 * PlayerFromEntity->entityNumber;
    if ( v6 != (char *)-12 )
      idRagePlayerMetrics::CoopChallengeHighestScoreRank(this: (idRagePlayerMetrics *)(v6 + 12), nightmare);
  }
}


// ========================================================================
// ?SkillJump@idRageMetrics@@QAAXPBVidPlayer@@@Z
// EA  : 0x82DDFB38
// RVA : 0x00DDFB38
// PDB : w:\tech5\tungsten\game\metrics\ragemetrics.cpp
// ========================================================================

void __fastcall idRageMetrics::SkillJump(idRageMetrics *this, idVehicle *player)
{
  idVehicle *PlayerFromEntity; // r3
  char *v4; // r10

  PlayerFromEntity = idGameLocal::GetPlayerFromEntity(this: gameLocal, activator: player);
  if ( PlayerFromEntity != nullptr )
  {
    v4 = (char *)this + 5000 * PlayerFromEntity->entityNumber;
    if ( v4 != (char *)-12 )
      idRagePlayerMetrics::SkillJump(this: (idRagePlayerMetrics *)(v4 + 12));
  }
}


// ========================================================================
// ?CompleteGame@idRageMetrics@@QAAXPBVidPlayer@@H@Z
// EA  : 0x82DDFB90
// RVA : 0x00DDFB90
// PDB : w:\tech5\tungsten\game\metrics\ragemetrics.cpp
// ========================================================================

void __fastcall idRageMetrics::CompleteGame(idRageMetrics *this, idVehicle *player, int difficulty)
{
  idVehicle *PlayerFromEntity; // r3
  char *v6; // r10
  idRagePlayerMetrics *v7; // r30
  int i; // r31

  PlayerFromEntity = idGameLocal::GetPlayerFromEntity(this: gameLocal, activator: player);
  if ( PlayerFromEntity != nullptr )
  {
    v6 = (char *)this + 5000 * PlayerFromEntity->entityNumber;
    v7 = (idRagePlayerMetrics *)(v6 + 12);
    if ( v6 != (char *)-12 )
    {
      for ( i = 0; i <= difficulty; ++i )
        idRagePlayerMetrics::CompleteGame(this: v7, difficulty: i);
    }
  }
}


// ========================================================================
// ?EngineeredItem@idRageMetrics@@QAAXPBVidPlayer@@@Z
// EA  : 0x82DDFBF8
// RVA : 0x00DDFBF8
// PDB : w:\tech5\tungsten\game\metrics\ragemetrics.cpp
// ========================================================================

void __fastcall idRageMetrics::EngineeredItem(idRageMetrics *this, idVehicle *player)
{
  idVehicle *PlayerFromEntity; // r3
  char *v4; // r10

  PlayerFromEntity = idGameLocal::GetPlayerFromEntity(this: gameLocal, activator: player);
  if ( PlayerFromEntity != nullptr )
  {
    v4 = (char *)this + 5000 * PlayerFromEntity->entityNumber;
    if ( v4 != (char *)-12 )
      idRagePlayerMetrics::EngineeredItem(this: (idRagePlayerMetrics *)(v4 + 12));
  }
}


// ========================================================================
// ?StealthCrossbowKill@idRageMetrics@@QAAXPBVidPlayer@@@Z
// EA  : 0x82DDFC50
// RVA : 0x00DDFC50
// PDB : w:\tech5\tungsten\game\metrics\ragemetrics.cpp
// ========================================================================

void __fastcall idRageMetrics::StealthCrossbowKill(idRageMetrics *this, idVehicle *player)
{
  idVehicle *PlayerFromEntity; // r3
  char *v4; // r10

  PlayerFromEntity = idGameLocal::GetPlayerFromEntity(this: gameLocal, activator: player);
  if ( PlayerFromEntity != nullptr )
  {
    v4 = (char *)this + 5000 * PlayerFromEntity->entityNumber;
    if ( v4 != (char *)-12 )
      idRagePlayerMetrics::StealthCrossbowKill(this: (idRagePlayerMetrics *)(v4 + 12));
  }
}


// ========================================================================
// ?StealthKill@idRageMetrics@@QAAXPBVidPlayer@@PBVidAI2@@@Z
// EA  : 0x82DDFCA8
// RVA : 0x00DDFCA8
// PDB : w:\tech5\tungsten\game\metrics\ragemetrics.cpp
// ========================================================================

void __fastcall idRageMetrics::StealthKill(idRageMetrics *this, idVehicle *player, const idAI2 *victim)
{
  idVehicle *PlayerFromEntity; // r3
  char *v6; // r10

  PlayerFromEntity = idGameLocal::GetPlayerFromEntity(this: gameLocal, activator: player);
  if ( PlayerFromEntity != nullptr )
  {
    v6 = (char *)this + 5000 * PlayerFromEntity->entityNumber;
    if ( v6 != (char *)-12 && victim != nullptr )
      idRagePlayerMetrics::StealthKill(this: (idRagePlayerMetrics *)(v6 + 12), victimEntityNumber: victim->entityNumber);
  }
}


// ========================================================================
// ?ComboKill@idRageMetrics@@QAAXPBVidPlayer@@PBVidAI2@@@Z
// EA  : 0x82DDFD18
// RVA : 0x00DDFD18
// PDB : w:\tech5\tungsten\game\metrics\ragemetrics.cpp
// ========================================================================

void __fastcall idRageMetrics::ComboKill(idRageMetrics *this, idVehicle *player, const idAI2 *victim)
{
  idVehicle *PlayerFromEntity; // r3
  char *v6; // r10

  PlayerFromEntity = idGameLocal::GetPlayerFromEntity(this: gameLocal, activator: player);
  if ( PlayerFromEntity != nullptr )
  {
    v6 = (char *)this + 5000 * PlayerFromEntity->entityNumber;
    if ( v6 != (char *)-12 && victim != nullptr )
      idRagePlayerMetrics::ComboKill(this: (idRagePlayerMetrics *)(v6 + 12), victimEntityNumber: victim->entityNumber);
  }
}


// ========================================================================
// ?PlayerIncapacitated@idRageMetrics@@QAAXPBVidPlayer@@@Z
// EA  : 0x82DDFD88
// RVA : 0x00DDFD88
// PDB : w:\tech5\tungsten\game\metrics\ragemetrics.cpp
// ========================================================================

void __fastcall idRageMetrics::PlayerIncapacitated(idRageMetrics *this, idVehicle *player)
{
  idVehicle *PlayerFromEntity; // r3
  char *v4; // r10

  PlayerFromEntity = idGameLocal::GetPlayerFromEntity(this: gameLocal, activator: player);
  if ( PlayerFromEntity != nullptr )
  {
    v4 = (char *)this + 5000 * PlayerFromEntity->entityNumber;
    if ( v4 != (char *)-12 )
      idRagePlayerMetrics::Incapacitated(this: (idRagePlayerMetrics *)(v4 + 12));
  }
}


// ========================================================================
// ?PlayerRevived@idRageMetrics@@QAAXPBVidPlayer@@0@Z
// EA  : 0x82DDFDE0
// RVA : 0x00DDFDE0
// PDB : w:\tech5\tungsten\game\metrics\ragemetrics.cpp
// ========================================================================

void __fastcall idRageMetrics::PlayerRevived(idRageMetrics *this, idVehicle *revivedPlayer, idVehicle *reviver)
{
  idVehicle *PlayerFromEntity; // r3
  char *v7; // r10
  idVehicle *v8; // r3
  char *v9; // r10

  PlayerFromEntity = idGameLocal::GetPlayerFromEntity(this: gameLocal, activator: revivedPlayer);
  if ( PlayerFromEntity != nullptr )
  {
    v7 = (char *)this + 5000 * PlayerFromEntity->entityNumber;
    if ( v7 != (char *)-12 )
      idRagePlayerMetrics::Revived(this: (idRagePlayerMetrics *)(v7 + 12));
  }
  v8 = idGameLocal::GetPlayerFromEntity(this: gameLocal, activator: reviver);
  if ( v8 != nullptr )
  {
    v9 = (char *)this + 5000 * v8->entityNumber;
    if ( v9 != (char *)-12 )
      idRagePlayerMetrics::RevivedPartner(
        this: (idRagePlayerMetrics *)(v9 + 12),
        revivedPlayerEntityNumber: revivedPlayer->entityNumber);
  }
}


// ========================================================================
// ?ShotAuthorityJetpackerInAir@idRageMetrics@@QAAXPBVidPlayer@@@Z
// EA  : 0x82DDFE60
// RVA : 0x00DDFE60
// PDB : w:\tech5\tungsten\game\metrics\ragemetrics.cpp
// ========================================================================

void __fastcall idRageMetrics::ShotAuthorityJetpackerInAir(idRageMetrics *this, idVehicle *player)
{
  idVehicle *PlayerFromEntity; // r3
  char *v4; // r10

  PlayerFromEntity = idGameLocal::GetPlayerFromEntity(this: gameLocal, activator: player);
  if ( PlayerFromEntity != nullptr )
  {
    v4 = (char *)this + 5000 * PlayerFromEntity->entityNumber;
    if ( v4 != (char *)-12 )
      idRagePlayerMetrics::ShotAuthorityJetpackerInAir(this: (idRagePlayerMetrics *)(v4 + 12));
  }
}


// ========================================================================
// ?AddBoostUpSP@idRageMetrics@@QAAXABVidVehicle_Car@@H@Z
// EA  : 0x82DDFEB8
// RVA : 0x00DDFEB8
// PDB : w:\tech5\tungsten\game\metrics\ragemetrics.cpp
// ========================================================================

void __fastcall idRageMetrics::AddBoostUpSP(idRageMetrics *this, idVehicle_Car *car, int deltaTime)
{
  idRagePlayerMetrics *PlayerMetrics; // r3

  if ( !this->gameEnded )
  {
    PlayerMetrics = idRageMetrics::GetPlayerMetrics(this, vehicle: car);
    if ( PlayerMetrics != nullptr )
      idRagePlayerMetrics::AddBoostUpSP(this: PlayerMetrics, time: deltaTime);
  }
}


// ========================================================================
// ?AddJumpManSP@idRageMetrics@@QAAXABVidVehicle_Car@@@Z
// EA  : 0x82DDFF00
// RVA : 0x00DDFF00
// PDB : w:\tech5\tungsten\game\metrics\ragemetrics.cpp
// ========================================================================

void __fastcall idRageMetrics::AddJumpManSP(idRageMetrics *this, idVehicle_Car *car)
{
  idRagePlayerMetrics *PlayerMetrics; // r3

  if ( !this->gameEnded )
  {
    PlayerMetrics = idRageMetrics::GetPlayerMetrics(this, vehicle: car);
    if ( PlayerMetrics != nullptr )
      idRagePlayerMetrics::AddJumpUpSP(this: PlayerMetrics);
  }
}


// ========================================================================
// ?AddDuraBumpSP@idRageMetrics@@QAAXABVidVehicle_Car@@M@Z
// EA  : 0x82DDFF38
// RVA : 0x00DDFF38
// PDB : w:\tech5\tungsten\game\metrics\ragemetrics.cpp
// ========================================================================

void __fastcall idRageMetrics::AddDuraBumpSP(idRageMetrics *this, idVehicle_Car *car, double damage)
{
  idRagePlayerMetrics *PlayerMetrics; // r3

  if ( !this->gameEnded )
  {
    PlayerMetrics = idRageMetrics::GetPlayerMetrics(this, vehicle: car);
    if ( PlayerMetrics != nullptr )
      idRagePlayerMetrics::AddDuraBumpSP(this: PlayerMetrics, damage);
  }
}


// ========================================================================
// ?AddOverAmmoSP@idRageMetrics@@QAAXABVidVehicle_Car@@@Z
// EA  : 0x82DDFF80
// RVA : 0x00DDFF80
// PDB : w:\tech5\tungsten\game\metrics\ragemetrics.cpp
// ========================================================================

void __fastcall idRageMetrics::AddOverAmmoSP(idRageMetrics *this, idVehicle_Car *car)
{
  idRagePlayerMetrics *PlayerMetrics; // r3

  if ( !this->gameEnded )
  {
    PlayerMetrics = idRageMetrics::GetPlayerMetrics(this, vehicle: car);
    if ( PlayerMetrics != nullptr )
      idRagePlayerMetrics::AddOverAmmoSP(this: PlayerMetrics);
  }
}


// ========================================================================
// ?AddFasterFasterSP@idRageMetrics@@QAAXABVidVehicle_Car@@@Z
// EA  : 0x82DDFFB8
// RVA : 0x00DDFFB8
// PDB : w:\tech5\tungsten\game\metrics\ragemetrics.cpp
// ========================================================================

void __fastcall idRageMetrics::AddFasterFasterSP(idRageMetrics *this, idVehicle_Car *car)
{
  idRagePlayerMetrics *PlayerMetrics; // r3

  if ( !this->gameEnded )
  {
    PlayerMetrics = idRageMetrics::GetPlayerMetrics(this, vehicle: car);
    if ( PlayerMetrics != nullptr )
      idRagePlayerMetrics::AddFasterFasterSP(this: PlayerMetrics);
  }
}


// ========================================================================
// ?AddOverLoadSP@idRageMetrics@@QAAXABVidVehicle_Car@@@Z
// EA  : 0x82DDFFF0
// RVA : 0x00DDFFF0
// PDB : w:\tech5\tungsten\game\metrics\ragemetrics.cpp
// ========================================================================

void __fastcall idRageMetrics::AddOverLoadSP(idRageMetrics *this, idVehicle_Car *car)
{
  idRagePlayerMetrics *PlayerMetrics; // r3

  if ( !this->gameEnded )
  {
    PlayerMetrics = idRageMetrics::GetPlayerMetrics(this, vehicle: car);
    if ( PlayerMetrics != nullptr )
      idRagePlayerMetrics::AddOverLoadSP(this: PlayerMetrics);
  }
}


// ========================================================================
// ?EvaluateEndOfGameStats@idRageMetrics@@AAAXABVidGameChallenge@@@Z
// EA  : 0x82DE0030
// RVA : 0x00DE0030
// PDB : w:\tech5\tungsten\game\metrics\ragemetrics.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idRageMetrics::EvaluateEndOfGameStats(idRageMetrics *this, const idGameChallenge *challenge)
{
  idLobbyBase *v4; // r3
  int v5; // r29
  idStaticList<idRageStat,256> *p_stats; // r28
  idRageStat *list; // r27
  idRageStat *v8; // r27
  idRageStat *v9; // r27
  idRageStat *v10; // r27
  idRageStat *v11; // r27
  double f; // fp31
  int v13; // r29
  idStaticList<idRageStat,256> *v14; // r27
  idClientGame *LobbyUserIdFromPlayerIndex; // r3
  char v16; // r11
  int SessionStat; // r28
  int v18; // r3
  __int64 v19; // r11 OVERLAPPED
  int v20; // r28
  __int64 v21; // r10
  int v22; // r3
  idRageStat *v23; // r28
  idRageStat *v24; // r28
  int v25; // r29
  bool *p_inGame; // r30
  idClientGame *v27; // r3
  char v28; // r11
  _BYTE v29[16]; // [sp+70h] [-A0h] BYREF
  idClientGameMsg_PostGameScoreRecap v30; // [sp+80h] [-90h] BYREF
  idClientGameMsg_PostGameScoreRecap v31; // [sp+A0h] [-70h] BYREF

  if ( common->IsMultiplayer(this: common)
    && (v4 = session->GetActingGameStateLobbyBase(this: session), v4->GetMatchParms(this: v4)->gameType == 2) )
  {
    idClientGameMsg_PostGameScoreRecap::idClientGameMsg_PostGameScoreRecap(this: &v30);
    idRageMetrics::AwardMost(this, criteria: RAGE_STAT_PLAYER_KILLS, award: RAGE_STAT_MOST_KILLS, msg: &v30);
    idRageMetrics::AwardLeast(this, criteria: RAGE_STAT_PERSONAL_DEATHS, award: RAGE_STAT_LEAST_DEATHS, msg: &v30);
    idRageMetrics::AwardMost(this, criteria: RAGE_STAT_SHOTS, award: RAGE_STAT_LONGEST_BULLY, msg: &v30);
    idRageMetrics::AwardMost(this, criteria: RAGE_STAT_PERSONAL_DEATHS, award: RAGE_STAT_MOST_DEATHS, msg: &v30);
    idRageMetrics::AwardLeast(this, criteria: RAGE_STAT_PLAYER_KILLS, award: RAGE_STAT_LEAST_KILLS, msg: &v30);
    idClientGame::HandleReliableGameMsg(this: clientGame, gameMsg: &v30);
    idClientGameMsg_PostGameScoreRecap::~idClientGameMsg_PostGameScoreRecap(this: &v30);
  }
  else if ( challenge->gameMode == CHALLENGE_MODE_COOP )
  {
    v5 = 0;
    p_stats = &this->players[0].stats;
    do
    {
      if ( HIBYTE(p_stats[1].staticList[1].sessionValue.f) != 0 )
      {
        list = p_stats->list;
        list[217].sessionValue.i = idRageMetrics::GetSessionStat(this, playerId: v5, stat: RAGE_STAT_AI_KILLS);
        v8 = p_stats->list;
        v8[221].sessionValue.i = idRageMetrics::GetSessionStat(this, playerId: v5, stat: RAGE_STAT_SHOTS);
        v9 = p_stats->list;
        v9[222].sessionValue.i = idRageMetrics::GetSessionStat(
                                   this,
                                   playerId: v5,
                                   stat: RAGE_STAT_WEAPON_HEADSHOT_ENEMY);
        v10 = p_stats->list;
        v10[223].sessionValue.i = idRageMetrics::GetSessionStat(this, playerId: v5, stat: RAGE_STAT_HEADSHOT_KILLS);
        v11 = p_stats->list;
        v11[220].sessionValue.i = idRageMetrics::GetSessionStat(this, playerId: v5, stat: RAGE_STAT_SCORE_COOP);
      }
      ++v5;
      p_stats = (idStaticList<idRageStat,256> *)((char *)p_stats + 5000);
    }
    while ( v5 < 6 );
  }
  else
  {
    f = 0.0;
    idClientGameMsg_PostGameScoreRecap::idClientGameMsg_PostGameScoreRecap(this: &v31);
    v13 = 0;
    v14 = &this->players[0].stats;
    do
    {
      if ( HIBYTE(v14[1].staticList[1].sessionValue.f) != 0 )
      {
        LobbyUserIdFromPlayerIndex = idClientGame::GetLobbyUserIdFromPlayerIndex(
                                       this: (idClientGame *)v29,
                                       result: (lobbyUserID_t *)clientGame,
                                       playerIndex: v13);
        if ( LobbyUserIdFromPlayerIndex->random.seed == 0
          || (v16 = 1, HIBYTE(LobbyUserIdFromPlayerIndex->renderWorld) == 255) )
        {
          v16 = 0;
        }
        if ( v16 != 0 )
        {
          if ( challenge->DidPlayerWin(this: challenge, a2: v13) )
            idRagePlayerMetrics::Award(this: (idRagePlayerMetrics *)&v14[-1].staticList[255], award: RAGE_STAT_WINS);
          if ( idRageMetrics::GetSessionStat(this, playerId: v13, stat: RAGE_STAT_VEHICLE_DEATHS) == 0 )
            idRagePlayerMetrics::Award(
              this: (idRagePlayerMetrics *)&v14[-1].staticList[255],
              award: RAGE_STAT_NO_VEHICLE_DEATHS);
          if ( idRageMetrics::GetSessionStat(this, playerId: v13, stat: RAGE_STAT_WINNING_SCORE) != 0
            || idRageMetrics::GetSessionStat(this, playerId: v13, stat: RAGE_STAT_WINNING_KILL) != 0
            || idRageMetrics::GetSessionStat(this, playerId: v13, stat: RAGE_STAT_WINNING_FLAG_CAPTURE) != 0 )
          {
            idRagePlayerMetrics::Award(
              this: (idRagePlayerMetrics *)&v14[-1].staticList[255],
              award: RAGE_STAT_MATCH_WINNER);
          }
          SessionStat = idRageMetrics::GetSessionStat(this, playerId: v13, stat: RAGE_STAT_VEHICLE_KILLS);
          v18 = idRageMetrics::GetSessionStat(this, playerId: v13, stat: RAGE_STAT_VEHICLE_DEATHS);
          LODWORD(v19) = v18;
          if ( SessionStat > 0 )
          {
            if ( v18 <= 0 )
              LODWORD(v19) = 1;
            HIDWORD(v19) = SessionStat;
            v14[1].staticList[0].aggregatedValue.f = (float)*(__int64 *)((char *)&v19 + 4) / (float)v19;
          }
          if ( v14[1].staticList[0].aggregatedValue.f > f )
            f = v14[1].staticList[0].aggregatedValue.f;
          v20 = idRageMetrics::GetSessionStat(this, playerId: v13, stat: RAGE_STAT_VEHICLE_HITS);
          v22 = idRageMetrics::GetSessionStat(this, playerId: v13, stat: RAGE_STAT_VEHICLE_SHOTS);
          if ( v22 > 0 )
          {
            LODWORD(v21) = v20;
            if ( (float)((float)v21 / (float)__SPAIR64__(v20, v22)) > 0.5 )
              idRagePlayerMetrics::Award(
                this: (idRagePlayerMetrics *)&v14[-1].staticList[255],
                award: RAGE_STAT_ACCURACY);
          }
          idRagePlayerMetrics::UpdateLongestLife(this: (idRagePlayerMetrics *)&v14[-1].staticList[255]);
          if ( idRageMetrics::GetSessionStat(this, playerId: v13, stat: RAGE_STAT_VEHICLE_QUAD_PICKUPS) >= 2 )
            v14->list[142].sessionValue.i = 1;
          v23 = v14->list;
          v23[228].sessionValue.i = idRageMetrics::GetSessionStat(this, playerId: v13, stat: RAGE_STAT_VEHICLE_KILLS);
          v24 = v14->list;
          v24[230].sessionValue.f = idRageMetrics::GetSessionStatFloat(
                                      this,
                                      playerId: v13,
                                      stat: RAGE_STAT_VEHICLE_ODOMETER_ON_GROUND);
        }
      }
      ++v13;
      v14 = (idStaticList<idRageStat,256> *)((char *)v14 + 5000);
    }
    while ( v13 < 6 );
    idRageMetrics::AwardLeast(this, criteria: RAGE_STAT_VEHICLE_DEATHS, award: RAGE_STAT_LEAST_DEATHS, msg: nullptr);
    idRageMetrics::AwardMost(this, criteria: RAGE_STAT_VEHICLE_POWERUPS, award: RAGE_STAT_MOST_POWERUPS, msg: nullptr);
    idRageMetrics::AwardMost(
      this,
      criteria: RAGE_STAT_VEHICLE_LEADERKILLS,
      award: RAGE_STAT_MOST_LEADER_KILLS,
      msg: nullptr);
    idRageMetrics::AwardMost(this, criteria: RAGE_STAT_VEHICLE_KILLS, award: RAGE_STAT_MOST_KILLS, msg: nullptr);
    idRageMetrics::AwardMost(
      this,
      criteria: RAGE_STAT_VDM_SPECIAL_KILLS,
      award: RAGE_STAT_MOST_SPECIAL_KILLS,
      msg: nullptr);
    v25 = 0;
    p_inGame = &this->players[0].inGame;
    do
    {
      if ( *p_inGame )
      {
        v27 = idClientGame::GetLobbyUserIdFromPlayerIndex(
                this: (idClientGame *)v29,
                result: (lobbyUserID_t *)clientGame,
                playerIndex: v25);
        if ( v27->random.seed == 0 || (v28 = 1, HIBYTE(v27->renderWorld) == 255) )
          v28 = 0;
        if ( v28 != 0 )
          *(_DWORD *)(*((_DWORD *)p_inGame - 780) + 2752) = idClientGameMsg_PostGameScoreRecap::GetNumAwards(
                                                              this: &v31,
                                                              playerNum: v25);
      }
      ++v25;
      p_inGame += 5000;
    }
    while ( v25 < 6 );
    idClientGame::HandleReliableGameMsg(this: clientGame, gameMsg: &v31);
    if ( (v31.items.listStatic == 0 || v31.items.listStatic == 2) && v31.items.list != nullptr )
      idMem::Free(this: &mem, ptr: v31.items.list, align: ALIGN_16);
  }
}


// ========================================================================
// __unwind$490969_0
// EA  : 0x82DE0598
// RVA : 0x00DE0598
// PDB : w:\tech5\tungsten\game\metrics\ragemetrics.cpp
// ========================================================================

void _unwind_490969_0()
{
  int v0; // r12

  idClientGameMsg_PostGameScoreRecap::~idClientGameMsg_PostGameScoreRecap(this: (idClientGameMsg_PostGameScoreRecap *)(v0 - 272 + 128));
}


// ========================================================================
// __unwind$490970_0
// EA  : 0x82DE05C0
// RVA : 0x00DE05C0
// PDB : w:\tech5\tungsten\game\metrics\ragemetrics.cpp
// ========================================================================

void _unwind_490970_0()
{
  int v0; // r12

  idClientGameMsg_PostGameScoreRecap::~idClientGameMsg_PostGameScoreRecap(this: (idClientGameMsg_PostGameScoreRecap *)(v0 - 272 + 160));
}


// ========================================================================
// __unwind$491085
// EA  : 0x82DE05E8
// RVA : 0x00DE05E8
// PDB : w:\tech5\tungsten\game\metrics\ragemetrics.cpp
// ========================================================================

void _unwind_491085()
{
  int v0; // r12

  idClientGameMsg_MeleeHit::~idClientGameMsg_MeleeHit(this: (idClientGameMsg_VehicleWeaponChange *)(v0 - 272 + 160));
}


// ========================================================================
// ?GetKillStreakTimeLimit@idRageMetrics@@ABAHXZ
// EA  : 0x82DE0610
// RVA : 0x00DE0610
// PDB : w:\tech5\tungsten\game\metrics\ragemetrics.cpp
// ========================================================================

int __fastcall idRageMetrics::GetKillStreakTimeLimit(idRageMetrics *this)
{
  challengeGameMode_t ChallengeMode; // r3
  double (__fastcall *GetTitleStorageFloat_2)(double); // ctr

  ChallengeMode = idGameLocal::GetChallengeMode(this: gameLocal);
  GetTitleStorageFloat_2 = (double (__fastcall *)(double))session->GetTitleStorageFloat_2;
  if ( ChallengeMode == CHALLENGE_MODE_COOP )
    return (int)(float)((float)1000.0 * (float)GetTitleStorageFloat_2(a1: gc_coop_killStreakTimeLimit.valueFloat));
  else
    return (int)(float)((float)1000.0 * (float)GetTitleStorageFloat_2(a1: gc_killStreakTimeLimit.valueFloat));
}


// ========================================================================
// ??1idRageMetrics@@UAA@XZ
// EA  : 0x82DE07B8
// RVA : 0x00DE07B8
// PDB : w:\tech5\tungsten\game\metrics\ragemetrics.cpp
// ========================================================================

void __fastcall idRageMetrics::~idRageMetrics(idRageMetrics *this)
{
  this->__vftable = (idRageMetrics_vtbl *)&idRageMetrics::`vftable';
  `eh vector destructor iterator'(
    ptr: this->players,
    size: 0x1388u,
    count: 6,
    pDtor: (void (__fastcall *)(void *))idRagePlayerMetrics::~idRagePlayerMetrics);
  idEventReceiver::~idEventReceiver(this);
}


// ========================================================================
// __unwind$491288
// EA  : 0x82DE081C
// RVA : 0x00DE081C
// PDB : w:\tech5\tungsten\game\metrics\ragemetrics.cpp
// ========================================================================

void _unwind_491288()
{
  int v0; // r12

  idEventReceiver::~idEventReceiver(this: *(idEventReceiver **)(v0 - 112 + 132));
}


// ========================================================================
// ?EndGame@idRageMetrics@@QAAXABVidGameChallenge@@_N@Z
// EA  : 0x82DE0848
// RVA : 0x00DE0848
// PDB : w:\tech5\tungsten\game\metrics\ragemetrics.cpp
// ========================================================================

void __fastcall idRageMetrics::EndGame(idRageMetrics *this, const idGameChallenge *challenge, bool postStats)
{
  idRagePlayerMetrics *players; // r30
  int i; // r31

  players = this->players;
  idRageMetrics::EvaluateEndOfGameStats(this, challenge);
  for ( i = 6; i != 0; --i )
    idRagePlayerMetrics::EndGame(this: players++, challenge, postStats);
  this->gameChallenge = nullptr;
  this->gameEnded = true;
}


// ========================================================================
// ?Kill@idRageMetrics@@QAAXPBVidEntity@@00PBVidDeclDamage@@@Z
// EA  : 0x82DE08A0
// RVA : 0x00DE08A0
// PDB : w:\tech5\tungsten\game\metrics\ragemetrics.cpp
// ========================================================================

void __fastcall idRageMetrics::Kill(
        idRageMetrics *this,
        idTurret *killer,
        idVehicle *victim,
        const idEntity *inflictor,
        const idDeclDamage *damageDef)
{
  const idDeclDamage *v8; // r14
  int v9; // r24
  idVehicle *Driver; // r15
  idVehicle *v11; // r25
  idAI2 *v12; // r16
  idPlayer *v13; // r20
  idAFEntity_Dummy *v14; // r21
  idTurret *v15; // r31
  idPlayer *turretOwner; // r29
  idAI2 *v17; // r28
  idPlayer *v18; // r26
  idVehicle *v19; // r3
  const idDeclEntityDef *entityDef; // r11
  idVehicle_Car *v21; // r23
  const char *str; // r3
  char v23; // r27
  int v24; // r9
  idRagePlayerMetrics *PlayerMetrics; // r17
  idRagePlayerMetrics *v26; // r19
  int entityNumber; // r4
  int v28; // r4
  int KillStreakTimeLimit; // r3
  vehicleClass_t vehicleClass; // r11
  idVehicle_Car *v31; // r3
  idVehicle_Car *v32; // r3
  idVehicleKey *playerKey; // r11
  idRagePlayerMetrics *players; // r21
  int v35; // r20
  idArray<int,6> *p_playerMeleeTime; // r28
  double v37; // fp31
  double v38; // fp31
  int v39; // r31
  int GameMs; // r14
  bool v41; // [sp+50h] [-B0h]
  idPlayer *v42; // [sp+54h] [-ACh]
  BOOL v43; // [sp+58h] [-A8h]

  v8 = damageDef;
  if ( this->gameEnded || killer == nullptr )
    return;
  v9 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
  Driver = victim;
  v11 = idVehicle::CastTo(c: victim);
  v12 = idAI2::CastTo(c: (idAI2 *)victim);
  v13 = idPlayer::CastTo(c: (idPlayer *)victim);
  v42 = v13;
  v14 = idAFEntity_Dummy::CastTo(c: (idAFEntity_Dummy *)victim);
  v15 = idTurret::CastTo(c: killer);
  turretOwner = (idPlayer *)killer;
  v17 = idAI2::CastTo(c: (idAI2 *)killer);
  v18 = idPlayer::CastTo(c: (idPlayer *)killer);
  v19 = idVehicle::CastTo(c: (idVehicle *)killer);
  entityDef = killer->entityDef;
  v21 = (idVehicle_Car *)v19;
  v41 = v15 != nullptr;
  if ( entityDef != nullptr )
    str = entityDef->name.str;
  else
    str = "*unknown*";
  v23 = 0;
  v24 = idStr::Find(searchIn: str, searchFor: "sentrybot", casesensitive: false, start: 0, end: -1);
  v43 = v24 != -1;
  if ( v24 == -1 )
  {
    if ( v15 == nullptr )
      goto LABEL_11;
    turretOwner = (idPlayer *)v15->turretOwner;
  }
  else
  {
    turretOwner = (idPlayer *)idAIEvent::GetInstigator(this: (idAIEvent *)&v17->aiVolatile.memory);
  }
  v18 = idPlayer::CastTo(c: turretOwner);
LABEL_11:
  if ( v11 != nullptr )
  {
    Driver = (idVehicle *)idRageMetrics::GetDriver(this, vehicle: (idVehicle_Car *)v11);
  }
  else if ( v13 != nullptr )
  {
    v11 = (idVehicle *)v13->GetVehicle(this: v13);
  }
  if ( v21 != nullptr )
  {
    turretOwner = (idPlayer *)idRageMetrics::GetDriver(this, vehicle: v21);
    v18 = idPlayer::CastTo(c: turretOwner);
  }
  else if ( v18 != nullptr )
  {
    v21 = (idVehicle_Car *)v18->GetVehicle(this: v18);
  }
  PlayerMetrics = idRageMetrics::GetPlayerMetrics(this, entity: Driver);
  v26 = idRageMetrics::GetPlayerMetrics(this, entity: (idVehicle *)v18);
  if ( PlayerMetrics == nullptr )
    goto LABEL_32;
  if ( v11 != nullptr )
  {
    if ( turretOwner != nullptr )
      entityNumber = turretOwner->entityNumber;
    else
      entityNumber = 0x1FFF;
    idRagePlayerMetrics::VehicleDeath(this: PlayerMetrics, killerEntityNum: entityNumber, damageDef: v8);
    if ( v26 != PlayerMetrics )
      goto LABEL_32;
    idRagePlayerMetrics::VehicleSuicide(this: PlayerMetrics, damageDef: v8);
  }
  else
  {
    if ( turretOwner != nullptr )
      v28 = turretOwner->entityNumber;
    else
      v28 = 0x1FFF;
    idRagePlayerMetrics::Death(this: PlayerMetrics, killerEntityNum: v28, damageDef: v8);
    if ( v26 != PlayerMetrics )
      goto LABEL_32;
    idRagePlayerMetrics::Suicide(this: PlayerMetrics, damageDef: v8);
  }
  v23 = 1;
LABEL_32:
  if ( v21 != nullptr && killer == (idTurret *)victim )
    v23 = 1;
  if ( v26 != nullptr && v23 == 0 )
  {
    if ( (unsigned __int8)idRageMetrics::AreTeammates(this, player1: v26, player2: PlayerMetrics) != 0 )
    {
      if ( PlayerMetrics != nullptr )
        idRagePlayerMetrics::TeamKill(this: v26, victim: PlayerMetrics, damageDef: v8);
    }
    else
    {
      idRagePlayerMetrics::ResetSpecialKill(this: v26);
      if ( idRageMetrics::IsLeader(this, playerMetrics: PlayerMetrics) )
        idRagePlayerMetrics::LeaderKill(this: v26);
      if ( v21 != nullptr && ((double (__fastcall *)(idVehicle_Car *))v21->GetHealth)(a1: v21) <= 0.0 )
        idRagePlayerMetrics::AfterlifeKill(this: v26);
      KillStreakTimeLimit = idRageMetrics::GetKillStreakTimeLimit(this);
      idRagePlayerMetrics::UpdateKillStreak(this: v26, currentTime: v9, killStreakTimeLimit: KillStreakTimeLimit);
      if ( v11 != nullptr )
      {
        idRagePlayerMetrics::VehicleKill(this: v26, victim: PlayerMetrics, damageDef: v8);
        vehicleClass = v11->vehicleClass;
        switch ( vehicleClass )
        {
          case VEHICLE_CLASS1:
            idRagePlayerMetrics::VehicleKillByClass1(this: v26);
            break;
          case VEHICLE_CLASS2:
            idRagePlayerMetrics::VehicleKillByClass2(this: v26);
            break;
          case VEHICLE_CLASS3:
            idRagePlayerMetrics::VehicleKillByClass3(this: v26);
            break;
          case VEHICLE_CLASS4:
            idRagePlayerMetrics::VehicleKillByClass4(this: v26);
            break;
          default:
            break;
        }
        if ( common->IsMultiplayer(this: common) )
        {
          v31 = idVehicle_Car::CastTo(c: (idVehicle_Car *)v11);
          if ( v31 != nullptr && idVehicle_Car::GetNumWheelsOnGround(this: v31) == 0 )
            idRagePlayerMetrics::AirKill(this: v26);
          v32 = idVehicle_Car::CastTo(c: v21);
          if ( v32 != nullptr && idVehicle_Car::GetNumWheelsOnGround(this: v32) == 0 )
            idRagePlayerMetrics::AerialKill(this: v26);
        }
        else if ( v18 != nullptr && v21 != nullptr )
        {
          playerKey = v21->playerKey;
          if ( playerKey != nullptr )
            ++playerKey->numVehicleKills;
        }
      }
      if ( v14 != nullptr && v14->isEnemyOfPlayer )
        idRagePlayerMetrics::BanditKill(this: v26);
      if ( v12 != nullptr )
      {
        idRagePlayerMetrics::AIKill(this: v26, victimEntityNum: Driver->entityNumber, damageDef: v8);
        if ( common->IsMultiplayer(this: common) )
        {
          players = this->players;
          v35 = 0;
          p_playerMeleeTime = &v12->aiVolatile.playerMeleeTime;
          do
          {
            if ( killer->entityNumber != v35 )
            {
              v37 = *(float *)p_playerMeleeTime[-1].ptr;
              v38 = (float)((float)v37 / v12->aiHealth.GetMaxBaseHealth_Impl(this: &v12->aiHealth));
              if ( v38 >= ((double (__fastcall *)(idSession *, const char *, double))session->GetTitleStorageFloat_2)(
                            a1: session,
                            a2: "gc_coop_assistPct",
                            a3: gc_coop_assistPct.valueFloat)
                && players != nullptr )
              {
                idRagePlayerMetrics::AIAssist(
                  this: players,
                  victimEntityNum: v12->entityNumber,
                  killerEntityNum: killer->entityNumber);
              }
              v39 = p_playerMeleeTime->ptr[0];
              if ( p_playerMeleeTime->ptr[0] > 0 )
              {
                GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
                if ( GameMs - v39 <= session->GetTitleStorageInt_2(
                                       this: session,
                                       a2: "gc_coop_defendTime",
                                       a3: gc_coop_defendTime.valueInteger) )
                  idRagePlayerMetrics::DefendKill(this: v26, victimEntityNumber: Driver->entityNumber);
                v8 = damageDef;
              }
            }
            ++v35;
            p_playerMeleeTime = (idArray<int,6> *)((char *)p_playerMeleeTime + 4);
            ++players;
          }
          while ( v35 < 2 );
          v13 = v42;
        }
      }
      if ( v13 != nullptr )
        idRagePlayerMetrics::PlayerKill(this: v26, victim: PlayerMetrics, damageDef: v8);
      if ( v41 )
      {
        idRagePlayerMetrics::TurretKill(this: v26, totalKillsPerItem: killer->entitiesKilled);
      }
      else if ( v43 )
      {
        idRagePlayerMetrics::SentryBotKill(this: v26, totalKillsPerItem: killer->entitiesKilled);
      }
    }
  }
}


// ========================================================================
// ??0idRageMetrics@@QAA@XZ
// EA  : 0x82DE0ED0
// RVA : 0x00DE0ED0
// PDB : w:\tech5\tungsten\game\metrics\ragemetrics.cpp
// ========================================================================

idRageMetrics *__fastcall idRageMetrics::idRageMetrics(idRageMetrics *this)
{
  idRagePlayerMetrics *players; // r28
  int v3; // r29

  idEventReceiver::idEventReceiver(this);
  this->__vftable = (idRageMetrics_vtbl *)&idRageMetrics::`vftable';
  players = this->players;
  `eh vector constructor iterator'(
    ptr: this->players,
    size: 0x1388u,
    count: 6,
    pCtor: (void (__fastcall *)(void *))idRagePlayerMetrics::idRagePlayerMetrics,
    pDtor: (void (__fastcall *)(void *))idRagePlayerMetrics::~idRagePlayerMetrics);
  v3 = 0;
  this->gameChallenge = nullptr;
  this->gameEnded = false;
  idDeclMetric::LoadAllDecls();
  do
    idRagePlayerMetrics::Init(this: players++, listener: this, entityNumber: v3++);
  while ( v3 < 6 );
  return this;
}


// ========================================================================
// __unwind$491476
// EA  : 0x82DE0F58
// RVA : 0x00DE0F58
// PDB : w:\tech5\tungsten\game\metrics\ragemetrics.cpp
// ========================================================================

void _unwind_491476()
{
  int v0; // r12

  idEventReceiver::~idEventReceiver(this: *(idEventReceiver **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$491477
// EA  : 0x82DE0F80
// RVA : 0x00DE0F80
// PDB : w:\tech5\tungsten\game\metrics\ragemetrics.cpp
// ========================================================================

void _unwind_491477()
{
  int v0; // r12

  `eh vector destructor iterator'(
    ptr: (void *)(*(_DWORD *)(v0 - 128 + 148) + 12),
    size: 0x1388u,
    count: 6,
    pDtor: (void (__fastcall *)(void *))idRagePlayerMetrics::~idRagePlayerMetrics);
}


// ========================================================================
// `dynamic initializer for 'gc_coop_killStreakTimeLimit''
// EA  : 0x83385860
// RVA : 0x01385860
// PDB : w:\tech5\tungsten\game\metrics\ragemetrics.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__gc_coop_killStreakTimeLimit__()
{
  idCVar::idCVar(
    this: &gc_coop_killStreakTimeLimit,
    name: "gc_coop_killStreakTimeLimit",
    value: "2.0",
    flags: 4,
    description: "Time allowed for consecutive kills to be counted as a streak (in seconds).",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__gc_coop_killStreakTimeLimit__);
}


// ========================================================================
// `dynamic initializer for 'gc_killStreakTimeLimit''
// EA  : 0x833858B8
// RVA : 0x013858B8
// PDB : w:\tech5\tungsten\game\metrics\ragemetrics.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__gc_killStreakTimeLimit__()
{
  idCVar::idCVar(
    this: &gc_killStreakTimeLimit,
    name: "gc_killStreakTimeLimit",
    value: "10.0",
    flags: 4,
    description: "Time allowed for consecutive kills to be counted as a streak (in seconds).",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__gc_killStreakTimeLimit__);
}


// ========================================================================
// `dynamic initializer for 'gc_coop_assistPct''
// EA  : 0x83385910
// RVA : 0x01385910
// PDB : w:\tech5\tungsten\game\metrics\ragemetrics.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__gc_coop_assistPct__()
{
  idCVar::idCVar(
    this: &gc_coop_assistPct,
    name: "gc_coop_assistPct",
    value: "0.3",
    flags: 4,
    description: "Percentage of damage a player must do to get an assist (while not getting killing blow)",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__gc_coop_assistPct__);
}


// ========================================================================
// `dynamic initializer for 'gc_coop_defendTime''
// EA  : 0x83385968
// RVA : 0x01385968
// PDB : w:\tech5\tungsten\game\metrics\ragemetrics.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__gc_coop_defendTime__()
{
  idCVar::idCVar(
    this: &gc_coop_defendTime,
    name: "gc_coop_defendTime",
    value: "2000",
    flags: 2,
    description: "Time in MS after an AI melees a player where the other player can register a defend kill",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__gc_coop_defendTime__);
}

