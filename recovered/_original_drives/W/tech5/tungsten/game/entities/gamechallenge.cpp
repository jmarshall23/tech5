
// ========================================================================
// ?Restart@idGameChallenge@@UAA_NXZ
// EA  : 0x82C502C8
// RVA : 0x00C502C8
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

int __fastcall idGameChallenge::Restart(idGameChallenge *this)
{
  idGameChallenge_vtbl *v1; // r10
  idEventArg *v3; // r3
  idEventArg v5; // [sp+50h] [-30h] BYREF

  v1 = this->__vftable;
  this->bGameFailed = false;
  v1->RestartPlayer(this, a2: nullptr);
  v3 = idEventArg::idEventArg(this: &v5, data: this);
  idEventReceiver::PostEventMS(
    this: &this->idEntity,
    ev: &EV_Activate,
    time: *(_DWORD *)&v3->type,
    arg1: (const idEventArg *)LODWORD(v3->value.v[1]));
  return 1;
}


// ========================================================================
// ?PlayerStateExpired@idGameChallenge@@UAA_NAAUplayerData_t@1@@Z
// EA  : 0x82C50348
// RVA : 0x00C50348
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

int __fastcall idGameChallenge::PlayerStateExpired(idGameChallenge *this, idGameChallenge::playerData_t *data)
{
  int v3; // r3
  unsigned __int8 v4; // r11

  if ( data->stateTime == 0 )
    return 0;
  v3 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
  v4 = 1;
  if ( v3 < data->stateTime )
    return 0;
  return v4;
}


// ========================================================================
// ?EnterState_PLAYER_STATE_SPECTATE_AFTER_DEATH@idGameChallenge@@UAAXAAUplayerData_t@1@@Z
// EA  : 0x82C503B0
// RVA : 0x00C503B0
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

void __fastcall idGameChallenge::EnterState_PLAYER_STATE_SPECTATE_AFTER_DEATH(
        idGameChallenge *this,
        idGameChallenge::playerData_t *data)
{
  this->SetSpectator(this, a2: data, a3: true);
}


// ========================================================================
// ?EnterState_PLAYER_STATE_RESPAWNING@idGameChallenge@@UAAXAAUplayerData_t@1@@Z
// EA  : 0x82C503C8
// RVA : 0x00C503C8
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

void __fastcall idGameChallenge::EnterState_PLAYER_STATE_RESPAWNING(
        idGameChallenge *this,
        idGameChallenge::playerData_t *data)
{
  this->RespawnPlayer(this, a2: data, a3: CT_SPAWN_PLAYER);
}


// ========================================================================
// ?StateExpired_PLAYER_STATE_VDM_GAME_MODE_INFO@idGameChallenge@@UAAXAAUplayerData_t@1@@Z
// EA  : 0x82C503E0
// RVA : 0x00C503E0
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

void __fastcall idGameChallenge::StateExpired_PLAYER_STATE_VDM_GAME_MODE_INFO(
        idGameChallenge *this,
        idGameChallenge::playerData_t *data)
{
  idGameChallenge_vtbl *v4; // r29
  int v5; // r3

  if ( gameLocal->challengeState < CHALLENGE_STATE_IN_PROGRESS_OVERTIME )
  {
    if ( this->requireLoadoutSelection )
    {
      v4 = this->__vftable;
      v5 = this->GetPreGameDuration(this);
      v4->SetPlayerState(this, a2: data, a3: PLAYER_STATE_VDM_SELECT_LOADOUT, a4: v5);
    }
    else
    {
      this->SetPlayerState(this, a2: data, a3: PLAYER_STATE_RESPAWNING, a4: 0);
    }
  }
}


// ========================================================================
// ?StateExpired_PLAYER_STATE_VDM_SELECT_LOADOUT@idGameChallenge@@UAAXAAUplayerData_t@1@@Z
// EA  : 0x82C50468
// RVA : 0x00C50468
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

void __fastcall idGameChallenge::StateExpired_PLAYER_STATE_VDM_SELECT_LOADOUT(
        idGameChallenge *this,
        idGameChallenge::playerData_t *data)
{
  this->SetPlayerState(this, a2: data, a3: PLAYER_STATE_VDM_FORCE_SELECT_LOADOUT, a4: 0);
}


// ========================================================================
// ?StateExpired_PLAYER_STATE_SPECTATE_AFTER_DEATH@idGameChallenge@@UAAXAAUplayerData_t@1@@Z
// EA  : 0x82C50480
// RVA : 0x00C50480
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

void __fastcall idGameChallenge::StateExpired_PLAYER_STATE_SPECTATE_AFTER_DEATH(
        idGameChallenge *this,
        idGameChallenge::playerData_t *data)
{
  this->SetPlayerState(this, a2: data, a3: PLAYER_STATE_RESPAWNING, a4: 0);
}


// ========================================================================
// ?HandleState_PLAYER_STATE_VDM_FORCE_SELECT_LOADOUT@idGameChallenge@@UAAXAAUplayerData_t@1@@Z
// EA  : 0x82C50498
// RVA : 0x00C50498
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

void __fastcall idGameChallenge::HandleState_PLAYER_STATE_VDM_FORCE_SELECT_LOADOUT(
        idGameChallenge *this,
        idGameChallenge::playerData_t *data)
{
  this->HandleState_PLAYER_STATE_VDM_SELECT_LOADOUT(this, a2: data);
}


// ========================================================================
// ?HandleState_PLAYER_STATE_SPECTATE_AFTER_DEATH@idGameChallenge@@UAAXAAUplayerData_t@1@@Z
// EA  : 0x82C504A8
// RVA : 0x00C504A8
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

void __fastcall idGameChallenge::HandleState_PLAYER_STATE_SPECTATE_AFTER_DEATH(
        idGameChallenge *this,
        idGameChallenge::playerData_t *data)
{
  this->HandleState_PLAYER_STATE_WAITING_TO_RESPAWN_FROM_DEATH(this, a2: data);
}


// ========================================================================
// ?SetPlayerState@idGameChallenge@@UAAXAAUplayerData_t@1@W4challengePlayerState_t@@H@Z
// EA  : 0x82C504B8
// RVA : 0x00C504B8
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

void __fastcall idGameChallenge::SetPlayerState(
        idGameChallenge *this,
        idGameChallenge::playerData_t *data,
        challengePlayerState_t newState,
        int timeInStateMS)
{
  if ( data->state != newState )
  {
    data->state = newState;
    if ( (unsigned int)(newState - 2) <= 5 )
    {
      switch ( newState )
      {
        case PLAYER_STATE_VDM_FORCE_SELECT_LOADOUT:
          this->EnterState_PLAYER_STATE_VDM_FORCE_SELECT_LOADOUT(this, a2: data);
          break;
        case PLAYER_STATE_IN_PROGRESS:
        case PLAYER_STATE_WAITING_TO_RESPAWN_FROM_DEATH:
LABEL_17:
          break;
        case PLAYER_STATE_SPECTATE_AFTER_DEATH:
          this->EnterState_PLAYER_STATE_SPECTATE_AFTER_DEATH(this, a2: data);
          break;
        case PLAYER_STATE_VDM_SELECT_LOADOUT:
          this->EnterState_PLAYER_STATE_VDM_SELECT_LOADOUT(this, a2: data);
          break;
        default:
          this->EnterState_PLAYER_STATE_RESPAWNING(this, a2: data);
          goto LABEL_17;
      }
    }
  }
  if ( timeInStateMS != 0 )
    data->stateTime = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) + timeInStateMS;
  else
    data->stateTime = 0;
}


// ========================================================================
// ?IsHostile@idGameChallenge@@QBA_NW4gameTeam_t@@0@Z
// EA  : 0x82C50598
// RVA : 0x00C50598
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

int __fastcall idGameChallenge::IsHostile(idGameChallenge *this, const gameTeam_t team1, const gameTeam_t team2)
{
  unsigned __int8 v3; // r11

  if ( team1 != team2 )
    return 1;
  if ( team1 == TEAM_NONE )
    return 1;
  v3 = 0;
  if ( team2 == TEAM_NONE )
    return 1;
  return v3;
}


// ========================================================================
// ?GetPlayerScore@idGameChallenge@@UBAHABUplayerData_t@1@@Z
// EA  : 0x82C505C0
// RVA : 0x00C505C0
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

int __fastcall idGameChallenge::GetPlayerScore(idGameChallenge *this, const idGameChallenge::playerData_t *data)
{
  return data->score;
}


// ========================================================================
// ?CanScore@idGameChallenge@@UBA_NXZ
// EA  : 0x82C505C8
// RVA : 0x00C505C8
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

int __fastcall idGameChallenge::CanScore(idGameChallenge *this)
{
  challengeState_t challengeState; // r11
  int result; // r3

  challengeState = gameLocal->challengeState;
  if ( challengeState == CHALLENGE_STATE_IN_PROGRESS )
    return 1;
  result = 0;
  if ( challengeState == CHALLENGE_STATE_IN_PROGRESS_OVERTIME )
    return 1;
  return result;
}


// ========================================================================
// ?ForceScoreboardAll@idGameChallenge@@UAAX_N@Z
// EA  : 0x82C505F8
// RVA : 0x00C505F8
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

void __fastcall idGameChallenge::ForceScoreboardAll(idGameChallenge *this, bool force)
{
  ((void (__fastcall *)(idSession *, bool))session->MatchFinished)(a1: session, a2: force);
}


// ========================================================================
// ?GetScoreLimit@idGameChallenge@@UAAHXZ
// EA  : 0x82C50610
// RVA : 0x00C50610
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

int __fastcall idGameChallenge::GetScoreLimit(idGameChallenge *this)
{
  return this->scoreLimit;
}


// ========================================================================
// ?StartPreGame@idGameChallenge@@UAAXXZ
// EA  : 0x82C50618
// RVA : 0x00C50618
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

void __fastcall idGameChallenge::StartPreGame(idGameChallenge *this)
{
  this->preGameTime = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
  gameLocal->challengeState = CHALLENGE_STATE_WAITING_TO_START;
}


// ========================================================================
// ?HasSpecialCollectible@idGameChallenge_Coop@@QBA_NXZ
// EA  : 0x82C50680
// RVA : 0x00C50680
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

BOOL __fastcall idGameChallenge_Coop::HasSpecialCollectible(idGameChallenge_Coop *this)
{
  return this->specialCollectible.found;
}


// ========================================================================
// ?MPTestSpawns_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82C50688
// RVA : 0x00C50688
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

void __fastcall MPTestSpawns_f(const idCmdArgs *args)
{
  idGameChallenge *ChallengeEntity; // r3

  ChallengeEntity = idGameLocal::GetChallengeEntity(this: gameLocal);
  ChallengeEntity->DebugAllSpawnPoints(this: ChallengeEntity);
}


// ========================================================================
// ?ForceEndGame_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82C506C0
// RVA : 0x00C506C0
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

void __fastcall ForceEndGame_f(const idCmdArgs *args)
{
  if ( idGameLocal::GetChallengeEntity(this: gameLocal) != nullptr )
    gameLocal->challengeState = CHALLENGE_STATE_GAME_OVER;
  else
    idLib::Warning(fmt: "No active Game Challenge");
}


// ========================================================================
// ?GetPreGameDuration@idGameChallenge@@UBAHXZ
// EA  : 0x82C50758
// RVA : 0x00C50758
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

int __fastcall idGameChallenge::GetPreGameDuration(idGameChallenge *this)
{
  return session->GetTitleStorageInt_2(this: session, a2: "gc_preGameDuration", a3: gc_preGameDuration.valueInteger);
}


// ========================================================================
// ?GetPreGameDuration@idGameChallenge_Coop@@UBAHXZ
// EA  : 0x82C50788
// RVA : 0x00C50788
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

int __fastcall idGameChallenge_Coop::GetPreGameDuration(idGameChallenge_Coop *this)
{
  return session->GetTitleStorageInt_2(
           this: session,
           a2: "gc_preGameDurationCoop",
           a3: gc_preGameDurationCoop.valueInteger);
}


// ========================================================================
// ?Notice_DoubleKill@idGameChallenge@@QAA?AVeventVoid@@PAVidEventReceiver@@HH@Z
// EA  : 0x82C507B8
// RVA : 0x00C507B8
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

idGameChallenge *__fastcall idGameChallenge::Notice_DoubleKill(
        idGameChallenge *this,
        eventVoid *result,
        idEventReceiver *caller,
        int playerEntityNumber,
        int xpGained)
{
  idGameLocal::BroadcastUIStatusMessage(
    this: gameLocal,
    type: 1,
    numParams: 2,
    param1: playerEntityNumber,
    param2: xpGained,
    param3: -1,
    param4: -1);
  return this;
}


// ========================================================================
// ?Notice_TripleKill@idGameChallenge@@QAA?AVeventVoid@@PAVidEventReceiver@@HH@Z
// EA  : 0x82C50800
// RVA : 0x00C50800
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

idGameChallenge *__fastcall idGameChallenge::Notice_TripleKill(
        idGameChallenge *this,
        eventVoid *result,
        idEventReceiver *caller,
        int playerEntityNumber,
        int xpGained)
{
  idGameLocal::BroadcastUIStatusMessage(
    this: gameLocal,
    type: 2,
    numParams: 2,
    param1: playerEntityNumber,
    param2: xpGained,
    param3: -1,
    param4: -1);
  return this;
}


// ========================================================================
// ?Notice_QuadKill@idGameChallenge@@QAA?AVeventVoid@@PAVidEventReceiver@@HH@Z
// EA  : 0x82C50848
// RVA : 0x00C50848
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

idGameChallenge *__fastcall idGameChallenge::Notice_QuadKill(
        idGameChallenge *this,
        eventVoid *result,
        idEventReceiver *caller,
        int playerEntityNumber,
        int xpGained)
{
  idGameLocal::BroadcastUIStatusMessage(
    this: gameLocal,
    type: 3,
    numParams: 2,
    param1: playerEntityNumber,
    param2: xpGained,
    param3: -1,
    param4: -1);
  return this;
}


// ========================================================================
// ?Notice_KillingSpree@idGameChallenge@@QAA?AVeventVoid@@PAVidEventReceiver@@HH@Z
// EA  : 0x82C50890
// RVA : 0x00C50890
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

idGameChallenge *__fastcall idGameChallenge::Notice_KillingSpree(
        idGameChallenge *this,
        eventVoid *result,
        idEventReceiver *caller,
        int playerEntityNumber,
        int xpGained)
{
  idGameLocal::BroadcastUIStatusMessage(
    this: gameLocal,
    type: 4,
    numParams: 2,
    param1: playerEntityNumber,
    param2: xpGained,
    param3: -1,
    param4: -1);
  return this;
}


// ========================================================================
// ?Notice_LeaderKill@idGameChallenge@@QAA?AVeventVoid@@PAVidEventReceiver@@HH@Z
// EA  : 0x82C508D8
// RVA : 0x00C508D8
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

idGameChallenge *__fastcall idGameChallenge::Notice_LeaderKill(
        idGameChallenge *this,
        eventVoid *result,
        idEventReceiver *caller,
        int playerEntityNumber,
        int xpGained)
{
  idGameLocal::BroadcastUIStatusMessage(
    this: gameLocal,
    type: 18,
    numParams: 2,
    param1: playerEntityNumber,
    param2: xpGained,
    param3: -1,
    param4: -1);
  return this;
}


// ========================================================================
// ?Notice_CaptureFlag@idGameChallenge@@QAA?AVeventVoid@@PAVidEventReceiver@@HH@Z
// EA  : 0x82C50920
// RVA : 0x00C50920
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

idGameChallenge *__fastcall idGameChallenge::Notice_CaptureFlag(
        idGameChallenge *this,
        eventVoid *result,
        idEventReceiver *caller,
        int playerEntityNumber,
        int xpGained)
{
  idGameLocal::BroadcastUIStatusMessage(
    this: gameLocal,
    type: 7,
    numParams: 2,
    param1: playerEntityNumber,
    param2: xpGained,
    param3: -1,
    param4: -1);
  return this;
}


// ========================================================================
// ?RestartPlayer@idGameChallenge@@UAAXPAVidPlayer@@@Z
// EA  : 0x82C50968
// RVA : 0x00C50968
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

void __fastcall idGameChallenge::RestartPlayer(idGameChallenge *this, idPlayer *player)
{
  idPhysics *Physics; // r3
  idPhysics *v4; // r3
  idPhysics *v5; // r3

  if ( player != nullptr )
  {
    idPlayer::Respawn(this: player, initial: false, spawnSpot: nullptr);
    Physics = idEntity::GetPhysics(this: player);
    Physics->SetOrigin(this: Physics, a2: &player->spawnPosition, a3: -1);
    v4 = idEntity::GetPhysics(this: player);
    v4->SetLinearVelocity(this: v4, a2: &vec3_origin, a3: 0);
    v5 = idEntity::GetPhysics(this: player);
    v5->SetAngularVelocity(this: v5, a2: &vec3_origin, a3: 0);
  }
}


// ========================================================================
// ?FriendlyFireEnabled@idGameChallenge@@UAA_NXZ
// EA  : 0x82C50A18
// RVA : 0x00C50A18
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

BOOL __fastcall idGameChallenge::FriendlyFireEnabled(idGameChallenge *this)
{
  return gc_friendlyFire.valueInteger != 0;
}


// ========================================================================
// ?GetFactionFromTeam@idGameChallenge@@QBAPBVidDeclFaction@@ABW4gameTeam_t@@@Z
// EA  : 0x82C50A30
// RVA : 0x00C50A30
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

const idDeclFaction *__fastcall idGameChallenge::GetFactionFromTeam(idGameChallenge *this, const gameTeam_t *team)
{
  int num; // r7
  int v3; // r10
  teamInfo_t *list; // r9
  int v5; // r11
  teamInfo_t *v6; // r8

  num = this->teamInfo.num;
  v3 = 0;
  if ( num <= 0 )
    return nullptr;
  list = this->teamInfo.list;
  v5 = 0;
  v6 = list;
  while ( v6->team != *team )
  {
    ++v3;
    v6 = &list[++v5];
    if ( v3 >= num )
      return nullptr;
  }
  return list[v3].faction;
}


// ========================================================================
// ?GetTeamScore@idGameChallenge@@UBAHW4gameTeam_t@@@Z
// EA  : 0x82C50A88
// RVA : 0x00C50A88
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

int __fastcall idGameChallenge::GetTeamScore(idGameChallenge *this, gameTeam_t team)
{
  int v2; // r11

  v2 = team - 1;
  if ( team - 1 < 0 || v2 >= this->teams.num )
    return 0;
  else
    return this->teams.list[v2].teamScore;
}


// ========================================================================
// ?ScoreLimitReached@idGameChallenge@@UAA_NXZ
// EA  : 0x82C50AC0
// RVA : 0x00C50AC0
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

int __fastcall idGameChallenge::ScoreLimitReached(idGameChallenge *this)
{
  int num; // r7
  int v2; // r10
  int v3; // r11
  idGameChallenge::playerData_t *list; // r9

  num = this->players.num;
  v2 = 0;
  if ( num <= 0 )
    return 0;
  v3 = 0;
  list = this->players.list;
  while ( list->score < this->scoreLimit )
  {
    ++v2;
    list = &this->players.list[++v3];
    if ( v2 >= num )
      return 0;
  }
  return 1;
}


// ========================================================================
// ?GetLeaderPlayerIndex@idGameChallenge@@UBAHXZ
// EA  : 0x82C50B10
// RVA : 0x00C50B10
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

int __fastcall idGameChallenge::GetLeaderPlayerIndex(idGameChallenge *this)
{
  int v2; // r27
  int v3; // r30
  int v4; // r26
  int v5; // r29
  int v6; // r28
  int v7; // r3
  int result; // r3

  v2 = 0;
  v3 = -2147483647;
  v4 = -1;
  v5 = 0;
  if ( this->players.num <= 0 )
    return v4;
  v6 = 0;
  do
  {
    v7 = this->GetPlayerScore(this, a2: &this->players.list[v6]);
    if ( v7 <= v3 )
    {
      if ( v7 == v3 )
        ++v2;
    }
    else
    {
      v3 = v7;
      v4 = v5;
      v2 = 1;
    }
    ++v5;
    ++v6;
  }
  while ( v5 < this->players.num );
  result = -1;
  if ( v2 <= 1 )
    return v4;
  return result;
}


// ========================================================================
// ?GetHighScore@idGameChallenge@@UBAHXZ
// EA  : 0x82C50BB0
// RVA : 0x00C50BB0
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

int __fastcall idGameChallenge::GetHighScore(idGameChallenge *this)
{
  int num; // r10
  int result; // r3
  int v4; // r26
  int v5; // r27
  int v6; // r29
  int v7; // r3
  gameTeam_t team; // r11
  idGameChallenge::playerData_t *v9; // r30
  int v10; // [sp+50h] [-40h] BYREF
  int v11; // [sp+54h] [-3Ch]

  num = this->players.num;
  if ( num == 0 )
    return 0;
  v4 = 0;
  v5 = -2147483647;
  v10 = -2147483647;
  v11 = -2147483647;
  if ( num > 0 )
  {
    v6 = 0;
    do
    {
      v7 = this->GetPlayerScore(this, a2: &this->players.list[v6]);
      team = this->players.list[v6].team;
      if ( team != TEAM_NONE )
      {
        if ( *(&v10 + team - 1) == -2147483647 )
        {
          v9 = &this->players.list[v6];
          *(&v10 + v9->team - 1) = this->GetTeamScore(this, a2: v9->team);
        }
      }
      else if ( v7 > v5 )
      {
        v5 = v7;
      }
      ++v4;
      ++v6;
    }
    while ( v4 < this->players.num );
    if ( v5 != -2147483647 )
      return v5;
  }
  if ( v10 > -2147483647 )
    v5 = v10;
  if ( v11 > v5 )
    v5 = v11;
  result = 0;
  if ( v5 != -2147483647 )
    return v5;
  return result;
}


// ========================================================================
// ?FinishGame@idGameChallenge@@UAAXXZ
// EA  : 0x82C50CE8
// RVA : 0x00C50CE8
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

void __fastcall idGameChallenge::FinishGame(idGameChallenge *this)
{
  idLobbyBase *v1; // r3
  int v2; // r3

  if ( this->bFinishGameExit )
  {
    session->EndMatch(this: session, a2: false);
  }
  else
  {
    if ( gameLocal != nullptr && gameLocal->mainMenu != nullptr )
    {
      v1 = session->GetActingGameStateLobbyBase(this: session);
      v2 = (int)v1->GetMatchParms(this: v1);
      idMainMenu::SetMatchMapIndex(this: gameLocal->mainMenu, index: *(_DWORD *)(v2 + 8));
    }
    cmdSystem->AppendCommandText(this: cmdSystem, a2: "restartmap\n");
  }
}


// ========================================================================
// ?IsVehicleUnlockValid@idGameChallenge@@IAA_NPBVidDeclVehicleUnlock@@AAUplayerData_t@1@H@Z
// EA  : 0x82C50DC0
// RVA : 0x00C50DC0
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

BOOL __fastcall idGameChallenge::IsVehicleUnlockValid(
        idGameChallenge *this,
        const idDeclVehicleUnlock *unlockDecl,
        idGameChallenge::playerData_t *data,
        unsigned int slot)
{
  return unlockDecl != nullptr
      && slot <= 5
      && (_cntlzw(idDeclVehicleUnlock::GetUnlockTypeForSlot(slot) - unlockDecl->unlockType) & 0x20) != 0;
}


// ========================================================================
// ?SetMatchParms@idGameChallenge@@IAAXABVidMatchParameters@@@Z
// EA  : 0x82C50E30
// RVA : 0x00C50E30
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

void __fastcall idGameChallenge::SetMatchParms(idGameChallenge *this, const idMatchParameters *parms)
{
  idLobbyBase *v4; // r3
  int scoreLimit; // r11
  int timeLimit; // r11

  v4 = session->GetActingGameStateLobbyBase(this: session);
  if ( v4->GetMatchParms(this: v4)->gameType == 2 )
  {
    this->scoreLimit = 200;
    this->timeLimit = 600;
  }
  scoreLimit = parms->scoreLimit;
  if ( scoreLimit > 0 )
    this->scoreLimit = scoreLimit;
  timeLimit = parms->timeLimit;
  if ( timeLimit > 0 )
    this->timeLimit = timeLimit;
}


// ========================================================================
// ?AllocPresentable@idGameChallenge@@UAAPAVidPresentable@@PAVidRenderModel@@@Z
// EA  : 0x82C50ED0
// RVA : 0x00C50ED0
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

idPresentable *__fastcall idGameChallenge::AllocPresentable(idGameChallenge *this, idTreeAnimator *renderModel_)
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
             e: &this->idEntity,
             renderModel_,
             entityNumber_: this->entityNumber,
             fxDecl_: this->fxDecl);
  else
    return nullptr;
}


// ========================================================================
// __unwind$495172
// EA  : 0x82C50F40
// RVA : 0x00C50F40
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

void _unwind_495172()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_PRESENTABLE);
}


// ========================================================================
// ?GameLoadingFinished@idGameChallenge_Coop@@UAAXH@Z
// EA  : 0x82C50F70
// RVA : 0x00C50F70
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

void __fastcall idGameChallenge_Coop::GameLoadingFinished(idGameChallenge_Coop *this, int fadeInTime)
{
  this->mapLoadFinished = true;
  this->fadeInFinishTime = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED)
                         + fadeInTime;
}


// ========================================================================
// ?GetNumCollectiblesFound@idGameChallenge_Coop@@QBAHXZ
// EA  : 0x82C50FD0
// RVA : 0x00C50FD0
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

int __fastcall idGameChallenge_Coop::GetNumCollectiblesFound(idGameChallenge_Coop *this)
{
  int num; // r10
  int result; // r3
  idGameChallenge_Coop::collectibleData_t *list; // r9
  int v5; // r11
  int i; // ctr

  num = this->collectibleList.num;
  result = 0;
  if ( num > 0 )
  {
    list = this->collectibleList.list;
    v5 = 0;
    for ( i = num; i != 0; --i )
    {
      if ( list[v5].found )
        ++result;
      ++v5;
    }
  }
  return result;
}


// ========================================================================
// ?MPTestLeaderboardUpload_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82C51010
// RVA : 0x00C51010
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

void __fastcall MPTestLeaderboardUpload_f(const idCmdArgs *args)
{
  idLobbyBase *v1; // r31
  idLobbyBase_vtbl *v2; // r9
  int v3; // r29
  int v4; // r28
  idSession_vtbl *v5; // r25
  idSession **v6; // r3
  __int64 v7; // r8
  idSession_vtbl *v8; // r25
  idSession **v9; // r3
  __int64 v10; // r8
  idSession_vtbl *v11; // r25
  idSession **v12; // r3
  idSession_vtbl *v13; // r25
  idSession **v14; // r3
  unsigned __int64 v15; // [sp+50h] [-B0h] BYREF
  char v16; // [sp+58h] [-A8h] BYREF
  char v17; // [sp+60h] [-A0h] BYREF
  char v18; // [sp+68h] [-98h] BYREF
  char v19; // [sp+70h] [-90h] BYREF
  _QWORD v20[2]; // [sp+80h] [-80h] BYREF
  _QWORD v21[14]; // [sp+90h] [-70h] BYREF

  if ( (currentTestFrame & 1) != 0 )
  {
    --currentTime;
    ++currentScore;
    ++currentTestValue;
  }
  v1 = session->GetGameLobbyBase(this: session);
  v2 = v1->__vftable;
  v3 = 0;
  ++currentTestFrame;
  if ( v2->GetNumLobbyUsers(this: v1) > 0 )
  {
    v4 = 0;
    do
    {
      v15 = __PAIR64__((unsigned int)session, currentTime);
      v5 = session->__vftable;
      v6 = (idSession **)v1->GetLobbyUserIdByOrdinal(this: (idLobbyBase *)&v16, result: (lobbyUserID_t *)v1, a3: v3);
      v5->LeaderboardUpload(
        this: *v6,
        a2: (lobbyUserID_t *)v6[1],
        a3: &rageTestLeaderboardTime,
        a4: (const column_t *)&v15,
        a5: nullptr);
      LODWORD(v7) = currentTestValue;
      v20[0] = __PAIR64__(currentTestValue, currentScore);
      v20[1] = v7;
      v8 = session->__vftable;
      v9 = (idSession **)v1->GetLobbyUserIdByOrdinal(this: (idLobbyBase *)&v17, result: (lobbyUserID_t *)v1, a3: v3);
      v8->LeaderboardUpload(
        this: *v9,
        a2: (lobbyUserID_t *)v9[1],
        a3: &rageTestLeaderboardScore1,
        a4: (const column_t *)v20,
        a5: nullptr);
      LODWORD(v10) = currentTestValue;
      v21[0] = __PAIR64__(currentTestValue, currentScore);
      v21[1] = v10;
      v11 = session->__vftable;
      v12 = (idSession **)v1->GetLobbyUserIdByOrdinal(this: (idLobbyBase *)&v18, result: (lobbyUserID_t *)v1, a3: v3);
      v11->LeaderboardUpload(
        this: *v12,
        a2: (lobbyUserID_t *)v12[1],
        a3: &rageTestLeaderboardScore2,
        a4: (const column_t *)v21,
        a5: nullptr);
      v13 = session->__vftable;
      v14 = (idSession **)v1->GetLobbyUserIdByOrdinal(this: (idLobbyBase *)&v19, result: (lobbyUserID_t *)v1, a3: v3);
      v13->SetLobbyUserRelativeScore(this: *v14, a2: (lobbyUserID_t *)v14[1], a3: v4, a4: v3++);
      v4 += 1000;
    }
    while ( v3 < v1->GetNumLobbyUsers(this: v1) );
  }
  session->LeaderboardFlush(this: session);
}


// ========================================================================
// ?MPTestLeaderboardUploadCoop_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82C51258
// RVA : 0x00C51258
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

void __fastcall MPTestLeaderboardUploadCoop_f(const idCmdArgs *args)
{
  int v1; // r27
  __int64 v2; // r29
  int v3; // r26
  idLobbyBase *v4; // r31
  idLobbyBase_vtbl *v5; // r25
  lobbyUserID_t *v6; // r3
  int v7; // r24
  int v8; // r27
  __int64 v9; // r29
  idSession_vtbl *v10; // r25
  idSession **v11; // r3
  idLobbyBase_vtbl *v12; // r25
  lobbyUserID_t *v13; // r3
  int v14; // r3
  __int64 v15; // r7
  idSession_vtbl *v16; // r29
  idSession **v17; // r3
  _BYTE v18[16]; // [sp+50h] [-90h] BYREF
  _QWORD v19[4]; // [sp+60h] [-80h] BYREF
  _QWORD v20[12]; // [sp+80h] [-60h] BYREF

  HIDWORD(v2) = args;
  v1 = 0;
  LODWORD(v2) = 100;
  v3 = 200;
  v4 = session->GetGameLobbyBase(this: session);
  v5 = v4->__vftable;
  v6 = v4->GetLobbyUserIdByOrdinal(this: (idLobbyBase *)v18, result: (lobbyUserID_t *)v4, a3: 0);
  v7 = v5->GetLobbyUserEmblemOrdinal(
         this: (idLobbyBase *)v6->localUserHandle.handle,
         a2: *(lobbyUserID_t **)&v6->lobbyType);
  if ( (int)*(_DWORD *)HIDWORD(v2) > 1 )
    v1 = atol(nptr: *(const char **)(HIDWORD(v2) + 8));
  if ( (int)*(_DWORD *)HIDWORD(v2) > 2 )
    LODWORD(v2) = atol(nptr: *(const char **)(HIDWORD(v2) + 12));
  if ( (int)*(_DWORD *)HIDWORD(v2) > 3 )
    v3 = atol(nptr: *(const char **)(HIDWORD(v2) + 16));
  idLib::Printf(fmt: "Submitting coop score: leaderboard: %d. p1: %d p2: %d\n", v1, (_DWORD)v2, v3);
  v19[0] = __PAIR64__(v7, v2);
  LODWORD(v2) = v3 + v2;
  v19[1] = v2;
  v19[2] = __PAIR64__((idCVar *)&pb_ss_UpdateAfterPhysics.name, v7);
  v8 = v1;
  HIDWORD(v9) = rageMPCoopLeaderboards;
  v10 = session->__vftable;
  v11 = (idSession **)v4->GetLobbyUserIdByOrdinal(this: (idLobbyBase *)v18, result: (lobbyUserID_t *)v4, a3: 0);
  v10->LeaderboardUpload(
    this: *v11,
    a2: (lobbyUserID_t *)v11[1],
    a3: rageMPCoopLeaderboards[v8],
    a4: (const column_t *)v19,
    a5: nullptr);
  if ( v4->GetNumLobbyUsers(this: v4) > 1 )
  {
    v12 = v4->__vftable;
    v13 = v4->GetLobbyUserIdByOrdinal(this: (idLobbyBase *)v18, result: (lobbyUserID_t *)v4, a3: 1);
    v14 = v12->GetLobbyUserEmblemOrdinal(
            this: (idLobbyBase *)v13->localUserHandle.handle,
            a2: *(lobbyUserID_t **)&v13->lobbyType);
    LODWORD(v15) = v3;
    v20[1] = v9;
    v20[2] = __PAIR64__(v3, v14);
    v20[0] = v15;
    v16 = session->__vftable;
    v17 = (idSession **)v4->GetLobbyUserIdByOrdinal(this: (idLobbyBase *)v18, result: (lobbyUserID_t *)v4, a3: 1);
    v16->LeaderboardUpload(
      this: *v17,
      a2: (lobbyUserID_t *)v17[1],
      a3: rageMPCoopLeaderboards[v8],
      a4: (const column_t *)v20,
      a5: nullptr);
  }
  session->LeaderboardFlush(this: session);
}


// ========================================================================
// ?MPTestLeaderboardUploadRoadRage_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82C51468
// RVA : 0x00C51468
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

void __fastcall MPTestLeaderboardUploadRoadRage_f(const idCmdArgs *args)
{
  unsigned int v2; // r23
  int v3; // r26
  int v4; // r27
  int v5; // r24
  int v6; // r25
  idLobbyBase *v7; // r31
  idLobbyBase_vtbl *v8; // r29
  lobbyUserID_t *v9; // r3
  int v10; // r22
  leaderboardDefinition_t *v11; // r30
  __int128 v12; // r9
  idSession_vtbl *v13; // r29
  idSession **v14; // r3
  idLobbyBase_vtbl *v15; // r29
  lobbyUserID_t *v16; // r3
  int v17; // r3
  __int128 v18; // r7
  idSession_vtbl *v19; // r31
  lobbyUserID_t *(__fastcall *GetLobbyUserIdByOrdinal)(idLobbyBase *, lobbyUserID_t *, int); // ctr
  idSession **v21; // r3
  _BYTE v22[16]; // [sp+50h] [-A0h] BYREF
  _QWORD v23[4]; // [sp+60h] [-90h] BYREF
  _QWORD v24[14]; // [sp+80h] [-70h] BYREF

  v2 = 0;
  v3 = 100;
  v4 = 5;
  v5 = 200;
  v6 = 10;
  v7 = session->GetGameLobbyBase(this: session);
  v8 = v7->__vftable;
  v9 = v7->GetLobbyUserIdByOrdinal(this: (idLobbyBase *)v22, result: (lobbyUserID_t *)v7, a3: 0);
  v10 = v8->GetLobbyUserEmblemOrdinal(
          this: (idLobbyBase *)v9->localUserHandle.handle,
          a2: *(lobbyUserID_t **)&v9->lobbyType);
  if ( args->argc > 1 )
    v2 = atol(nptr: args->argv[1]);
  if ( args->argc > 2 )
    v3 = atol(nptr: args->argv[2]);
  if ( args->argc > 3 )
    v4 = atol(nptr: args->argv[3]);
  if ( args->argc > 4 )
    v5 = atol(nptr: args->argv[4]);
  if ( args->argc > 5 )
    v6 = atol(nptr: args->argv[5]);
  if ( v2 > 3 )
  {
    idLib::Printf(fmt: "Submitting Triad ");
    v11 = &rageLeaderboardTriad;
  }
  else if ( v2 == 1 )
  {
    idLib::Printf(fmt: "Submitting VDM ");
    v11 = &rageLeaderboardVDM;
  }
  else if ( v2 == 2 )
  {
    idLib::Printf(fmt: "Submitting Bully ");
    v11 = &rageLeaderboardBully;
  }
  else if ( v2 != 0 )
  {
    idLib::Printf(fmt: "Submitting Meteor ");
    v11 = &rageLeaderboardMeteor;
  }
  else
  {
    idLib::Printf(fmt: "Submitting RallyScore ");
    v11 = &rageLeaderboardRally;
  }
  idLib::Printf(fmt: "score: p1: %d/%d p2: %d/%d\n", v3, v4, v5, v6);
  *((_QWORD *)&v12 + 1) = __PAIR64__(v10, v4);
  v23[0] = __PAIR64__(v4, v3);
  v23[1] = __PAIR64__(v10, v4);
  v23[2] = *(_QWORD *)((char *)&v12 + 4);
  v13 = session->__vftable;
  v14 = (idSession **)v7->GetLobbyUserIdByOrdinal(this: (idLobbyBase *)v22, result: (lobbyUserID_t *)v7, a3: 0);
  v13->LeaderboardUpload(this: *v14, a2: (lobbyUserID_t *)v14[1], a3: v11, a4: (const column_t *)v23, a5: nullptr);
  if ( v7->GetNumLobbyUsers(this: v7) > 1 )
  {
    v15 = v7->__vftable;
    v16 = v7->GetLobbyUserIdByOrdinal(this: (idLobbyBase *)v22, result: (lobbyUserID_t *)v7, a3: 1);
    v17 = v15->GetLobbyUserEmblemOrdinal(
            this: (idLobbyBase *)v16->localUserHandle.handle,
            a2: *(lobbyUserID_t **)&v16->lobbyType);
    *((_QWORD *)&v18 + 1) = __PAIR64__(v6, v5);
    v24[2] = __PAIR64__(v5, v17);
    v24[0] = __PAIR64__(v6, v5);
    HIDWORD(v18) = v7;
    v24[1] = *(_QWORD *)((char *)&v18 + 4);
    GetLobbyUserIdByOrdinal = v7->GetLobbyUserIdByOrdinal;
    v19 = session->__vftable;
    v21 = (idSession **)GetLobbyUserIdByOrdinal(this: (idLobbyBase *)v22, result: (lobbyUserID_t *)HIDWORD(v18), a3: 1);
    v19->LeaderboardUpload(this: *v21, a2: (lobbyUserID_t *)v21[1], a3: v11, a4: (const column_t *)v24, a5: nullptr);
  }
  session->LeaderboardFlush(this: session);
}


// ========================================================================
// ?Notice_PlayerKill@idGameChallenge_PVP@@IAA?AVeventVoid@@PAVidEventReceiver@@HHPBVidDeclDamage@@H@Z
// EA  : 0x82C51738
// RVA : 0x00C51738
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

idGameChallenge_PVP *__fastcall idGameChallenge_PVP::Notice_PlayerKill(
        idGameChallenge_PVP *this,
        eventVoid *result,
        idEventReceiver *caller,
        int attackingPlayerEntityNumber,
        int victimPlayerEntityNumber,
        const idDeclDamage *damageDef,
        int xpGained)
{
  (*(void (__fastcall **)(eventVoid *, int, int))(*(_DWORD *)result + 892))(
    a1: result,
    a2: attackingPlayerEntityNumber,
    a3: victimPlayerEntityNumber);
  (*(void (__fastcall **)(eventVoid *, int, int, const idDeclDamage *, _DWORD, int, _DWORD))(*(_DWORD *)result + 848))(
    a1: result,
    a2: attackingPlayerEntityNumber,
    a3: victimPlayerEntityNumber,
    a4: damageDef,
    a5: 0,
    a6: xpGained,
    a7: 0);
  return this;
}


// ========================================================================
// ?Notice_TeamKill@idGameChallenge_PVP@@IAA?AVeventVoid@@PAVidEventReceiver@@HHPBVidDeclDamage@@@Z
// EA  : 0x82C517B0
// RVA : 0x00C517B0
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

idGameChallenge_PVP *__fastcall idGameChallenge_PVP::Notice_TeamKill(
        idGameChallenge_PVP *this,
        eventVoid *result,
        idEventReceiver *caller,
        int attackingPlayerEntityNumber,
        int victimPlayerEntityNumber,
        const idDeclDamage *damageDef)
{
  (*(void (__fastcall **)(eventVoid *, int, int))(*(_DWORD *)result + 896))(
    a1: result,
    a2: attackingPlayerEntityNumber,
    a3: victimPlayerEntityNumber);
  (*(void (__fastcall **)(eventVoid *, int, int, const idDeclDamage *, int, _DWORD, _DWORD))(*(_DWORD *)result + 848))(
    a1: result,
    a2: attackingPlayerEntityNumber,
    a3: victimPlayerEntityNumber,
    a4: damageDef,
    a5: 1,
    a6: 0,
    a7: 0);
  return this;
}


// ========================================================================
// ?SerializeMigrationGameData@idGameChallenge@@UAAXAAVidSerializer@@@Z
// EA  : 0x82C51B40
// RVA : 0x00C51B40
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

void __fastcall idGameChallenge::SerializeMigrationGameData(idGameChallenge *this, idSerializer *ser)
{
  int (*GetGameMs)(void); // ctr
  int v5; // r7
  idBitMsg *msg; // r3

  GetGameMs = (int (*)(void))gameLocal->GetGameMs;
  if ( this->timeLimit <= 0 )
    v5 = GetGameMs() - this->startTime;
  else
    v5 = this->endTime - GetGameMs();
  this->migratedTime = v5;
  msg = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: msg, value: v5, numBits: 32);
  else
    this->migratedTime = idBitMsg::ReadBits(this: msg, numBits: 32);
  if ( gc_hostMigration_debug.valueInteger != 0 )
    idLib::Printf(fmt: "^2Serializing migrated time: %d\n", this->migratedTime);
}


// ========================================================================
// ?BeginGame@idGameChallenge@@UAAXXZ
// EA  : 0x82C51C08
// RVA : 0x00C51C08
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

void __fastcall idGameChallenge::BeginGame(idGameChallenge *this)
{
  int v2; // r3
  int timeLimit; // r11
  BOOL wasMigratedGame; // r10
  int v5; // r26
  int v6; // r28
  idGameChallenge::playerData_t *v7; // r30
  idPlayer *v8; // r3
  idPlayer *v9; // r3
  idPlayer *v10; // r29
  idGameChallenge_vtbl *v11; // r7

  v2 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
  timeLimit = this->timeLimit;
  this->startTime = v2;
  if ( timeLimit > 0 )
  {
    wasMigratedGame = this->wasMigratedGame;
    this->endTime = 1000 * timeLimit + v2;
    if ( wasMigratedGame )
      this->endTime = this->migratedTime + v2;
    this->originalEndTime = this->endTime;
  }
  v5 = 0;
  if ( this->players.num > 0 )
  {
    v6 = 0;
    do
    {
      v7 = &this->players.list[v6];
      if ( gameLocal->spawnIds.ptr[v7->player.spawnId.value & 0x1FFF] == v7->player.spawnId.value >> 13 )
      {
        v8 = (idPlayer *)gameLocal->entities.ptr[v7->player.spawnId.value & 0x1FFF];
        if ( v8 != nullptr )
        {
          v9 = idPlayer::CastTo(c: v8);
          v10 = v9;
          if ( v9 != nullptr )
          {
            idPlayer::SetForceInhibitControl(this: v9, inhibit: false);
            *(_BYTE *)&v10->flags = (2 * this->takeDamage) & 2 | *(_BYTE *)&v10->flags & 0xFD;
            if ( this->wasMigratedGame )
            {
              v7->lastScore = v7->score;
            }
            else
            {
              v7->score = 0;
              v7->lastScore = 0;
            }
          }
        }
      }
      ++v5;
      ++v6;
    }
    while ( v5 < this->players.num );
  }
  gameLocal->challengeState = CHALLENGE_STATE_IN_PROGRESS;
  v11 = this->__vftable;
  this->incapacitated = false;
  v11->ActivateTargets(this, a2: &this->idEntity);
}


// ========================================================================
// ?BeginGame@idGameChallenge_Coop@@UAAXXZ
// EA  : 0x82C51D60
// RVA : 0x00C51D60
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

// attributes: thunk
void __fastcall idGameChallenge_Coop::BeginGame(idGameChallenge_Coop *this)
{
  idGameChallenge::BeginGame(this);
}


// ========================================================================
// ?GetPlayerData@idGameChallenge@@QAAPAUplayerData_t@1@PBVidPlayer@@@Z
// EA  : 0x82C51D68
// RVA : 0x00C51D68
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

idGameChallenge::playerData_t *__fastcall idGameChallenge::GetPlayerData(idGameChallenge *this, const idPlayer *player)
{
  int v4; // r29
  int v5; // r31
  idGameLocal *v6; // r10
  int value; // r9
  idPlayer *v8; // r3
  idPlayer *v9; // r3

  if ( player == nullptr )
    return nullptr;
  v4 = 0;
  if ( this->players.num <= 0 )
    return nullptr;
  v5 = 0;
  v6 = gameLocal;
  while ( 1 )
  {
    value = this->players.list[v5].player.spawnId.value;
    if ( v6->spawnIds.ptr[value & 0x1FFF] == value >> 13
      && (v8 = (idPlayer *)v6->entities.ptr[value & 0x1FFF]) != nullptr )
    {
      v9 = idPlayer::CastTo(c: v8);
      v6 = gameLocal;
    }
    else
    {
      v9 = nullptr;
    }
    if ( v9 == player )
      break;
    ++v4;
    ++v5;
    if ( v4 >= this->players.num )
      return nullptr;
  }
  return &this->players.list[v4];
}


// ========================================================================
// ?SetPlayerLoadout@idGameChallenge@@QAAXPAVidPlayer@@ABV?$idList@PBVidDeclVehicleUnlock@@$04@@@Z
// EA  : 0x82C51E30
// RVA : 0x00C51E30
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

void __fastcall idGameChallenge::SetPlayerLoadout(
        idGameChallenge *this,
        idPlayer *player,
        const idList<idDeclVehicleUnlock const *,5> *items)
{
  idGameChallenge::playerData_t *PlayerData; // r3
  int num; // r11
  char v7; // r7
  int v8; // r10
  int v9; // r11
  const idDeclVehicleUnlock **loadoutSlot; // r8
  char *v11; // r3

  PlayerData = idGameChallenge::GetPlayerData(this, player);
  if ( PlayerData != nullptr )
  {
    num = items->num;
    if ( num <= 6 )
    {
      v7 = 1;
      v8 = 0;
      if ( num > 0 )
      {
        v9 = 0;
        loadoutSlot = PlayerData->loadoutSlot;
        do
        {
          ++v8;
          v11 = (char *)((char *)items->list[v9] - (char *)loadoutSlot[v9]);
          loadoutSlot[v9] = items->list[v9];
          ++v9;
          v7 = v11 != nullptr ? 0 : v7;
        }
        while ( v8 < items->num );
      }
      if ( v7 == 0 )
        player->loadoutChanged = true;
    }
    else
    {
      idLib::Warning(fmt: "Too many items sent to SetPlayerLoadout()!");
    }
  }
}


// ========================================================================
// ?RespawnPlayerFromDeath@idGameChallenge@@QAAXPAVidPlayer@@@Z
// EA  : 0x82C51EF0
// RVA : 0x00C51EF0
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

void __fastcall idGameChallenge::RespawnPlayerFromDeath(idGameChallenge *this, idPlayer *player)
{
  idGameChallenge::playerData_t *PlayerData; // r3
  challengePlayerState_t state; // r11

  PlayerData = idGameChallenge::GetPlayerData(this, player);
  if ( PlayerData != nullptr )
  {
    state = PlayerData->state;
    if ( state == PLAYER_STATE_WAITING_TO_RESPAWN_FROM_DEATH || state == PLAYER_STATE_SPECTATE_AFTER_DEATH )
      this->SetPlayerState(this, a2: PlayerData, a3: PLAYER_STATE_RESPAWNING, a4: 0);
  }
}


// ========================================================================
// ?GetLeaderEntityNumber@idGameChallenge@@UBAHXZ
// EA  : 0x82C51F58
// RVA : 0x00C51F58
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

int __fastcall idGameChallenge::GetLeaderEntityNumber(idGameChallenge *this)
{
  int result; // r3
  int value; // r7

  result = this->GetLeaderPlayerIndex(this);
  if ( result > -1 )
  {
    value = this->players.list[result].player.spawnId.value;
    if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
      return this->players.list[result].player.spawnId.value & 0x1FFF;
  }
  return result;
}


// ========================================================================
// ?GenerateRelativeScore@idGameChallenge@@IAAHHH@Z
// EA  : 0x82C51FE0
// RVA : 0x00C51FE0
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

int __fastcall idGameChallenge::GenerateRelativeScore(idGameChallenge *this, int myIndex, int myScore)
{
  int v6; // r25
  int v7; // r8
  int num; // ctr
  int v9; // r11
  int v11; // r29
  int v12; // r30

  v6 = 0;
  if ( !this->IsTeamGame(this) )
  {
    v11 = 0;
    if ( this->players.num > 0 )
    {
      v12 = 0;
      do
      {
        if ( v11 != myIndex
          && gameLocal->spawnIds.ptr[this->players.list[v12].player.spawnId.value & 0x1FFF] == this->players.list[v12].player.spawnId.value >> 13
          && ((int (__fastcall *)(idGameChallenge *))this->GetPlayerScore)(a1: this) <= myScore )
        {
          ++v6;
        }
        ++v11;
        ++v12;
      }
      while ( v11 < this->players.num );
    }
    return v6;
  }
  v7 = 0;
  if ( this->teams.num <= 0 )
    return v6;
  num = this->teams.num;
  v9 = 0;
  do
  {
    if ( v7 != this->players.list[myIndex].team && this->teams.list[v9].teamScore <= myScore )
      ++v6;
    ++v7;
    ++v9;
    --num;
  }
  while ( num != 0 );
  return v6;
}


// ========================================================================
// ?GetDefaultVehicleUnlock@idGameChallenge@@IAAPBVidDeclVehicleUnlock@@H@Z
// EA  : 0x82C52110
// RVA : 0x00C52110
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

const idDeclVehicleUnlock *__fastcall idGameChallenge::GetDefaultVehicleUnlock(
        idGameChallenge *this,
        unsigned int slot)
{
  const idDeclVehicleLoadout *v2; // r11

  v2 = *idDeclVehicleLoadout::defaultLoadouts.list;
  if ( slot > 5 )
    return nullptr;
  switch ( slot )
  {
    case 0u:
      return v2->vehicleClass;
    case 1u:
      return v2->vehicle;
    case 2u:
      return v2->weaponPrimary;
    case 3u:
      return v2->weaponSecondary;
    case 4u:
      return v2->quickUse1;
    default:
      break;
  }
  return v2->quickUse2;
}


// ========================================================================
// ?GetVehicleUnlockForSlot@idGameChallenge@@IAAPBVidDeclVehicleUnlock@@AAUplayerData_t@1@H@Z
// EA  : 0x82C52180
// RVA : 0x00C52180
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

const idDeclVehicleUnlock *__fastcall idGameChallenge::GetVehicleUnlockForSlot(
        idGameChallenge *this,
        idGameChallenge::playerData_t *data,
        unsigned int slot)
{
  const idDecl *v6; // r3
  int v7; // r8
  const idDecl *v8; // r11

  if ( slot > 5 )
    return nullptr;
  v6 = idDeclInfo::FindWithInheritance(
         this: &idDeclVehicleUnlock::resourceList,
         name: "vehicle/unlocks/online/empty",
         makeDefault: true);
  v7 = 4 * (slot + 14);
  v8 = *(const idDecl **)((char *)&data->player.spawnId.value + v7);
  if ( v8 == v6 )
    return nullptr;
  if ( v8 != nullptr )
    return *(const idDeclVehicleUnlock **)((char *)&data->player.spawnId.value + v7);
  return idGameChallenge::GetDefaultVehicleUnlock(this, slot);
}


// ========================================================================
// ?GetPrimaryScoreboardStat@idGameChallenge@@UAAHH@Z
// EA  : 0x82C52208
// RVA : 0x00C52208
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

int __fastcall idGameChallenge::GetPrimaryScoreboardStat(idGameChallenge *this, int playerNum)
{
  const idDeclGameMode *v2; // r11

  v2 = idDeclGameMode::challengeModeLookup.list[this->gameMode];
  if ( v2 != nullptr )
    return idRageMetrics::GetSessionStat(
             this: clientGame->rageMetrics,
             playerId: playerNum,
             stat: v2->primaryScoreboardInfo.stat);
  else
    return 0;
}


// ========================================================================
// ?GetSecondaryScoreboardStat@idGameChallenge@@UAAHH@Z
// EA  : 0x82C52248
// RVA : 0x00C52248
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

int __fastcall idGameChallenge::GetSecondaryScoreboardStat(idGameChallenge *this, int playerNum)
{
  const idDeclGameMode *v2; // r11

  v2 = idDeclGameMode::challengeModeLookup.list[this->gameMode];
  if ( v2 != nullptr )
    return idRageMetrics::GetSessionStat(
             this: clientGame->rageMetrics,
             playerId: playerNum,
             stat: v2->secondaryScoreboardInfo.stat);
  else
    return 0;
}


// ========================================================================
// ?GetSecondaryLeaderboardStat@idGameChallenge@@MAAHH@Z
// EA  : 0x82C52288
// RVA : 0x00C52288
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

int __fastcall idGameChallenge::GetSecondaryLeaderboardStat(idGameChallenge *this, int playerNum)
{
  const idDeclGameMode *v2; // r11

  v2 = idDeclGameMode::challengeModeLookup.list[this->gameMode];
  if ( v2 != nullptr )
    return idRageMetrics::GetSessionStat(
             this: clientGame->rageMetrics,
             playerId: playerNum,
             stat: v2->secondaryLeaderboardStat);
  else
    return 0;
}


// ========================================================================
// ?StopObjective@idGameChallenge_Coop@@QAAX_N@Z
// EA  : 0x82C522C8
// RVA : 0x00C522C8
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

void __fastcall idGameChallenge_Coop::StopObjective(idGameChallenge_Coop *this, bool skipResults)
{
  int v4; // r3
  unsigned __int64 v5; // r22
  int totalTime; // r10
  int v7; // r11
  int num; // r4
  int v9; // r30
  int v10; // r31
  int value; // r9
  idPlayer *v12; // r3
  idPlayer *v13; // r3
  int v14; // r11
  int v15; // r24
  int v16; // r30
  int v17; // r31
  int v18; // r9
  idPlayer *v19; // r3
  int v20; // r25
  int v21; // r28
  int i; // r27
  int v23; // r9
  idPlayer *v24; // r3
  idPlayer *v25; // r30
  int score; // r4
  int SessionStat; // r3
  int v28; // r20
  int v29; // r20
  int v30; // r20
  int v31; // r3
  int v32; // r3
  int v33; // r3
  int v34; // r3
  int v35; // r3
  int v36; // r4
  int v37; // r10
  int v38; // r11
  int numCollectiblesToComplete; // r4
  int v40; // r5
  int v41; // r30
  int v42; // r28
  int v43; // r9
  idGameChallenge_Coop::ratingTitle_t *list; // r7
  int v45; // r10
  int v46; // r8
  int points; // r11
  int v48; // r30
  int j; // r28
  int v50; // r9
  idPlayer *v51; // r3
  idPlayer *v52; // r4
  idLobbyBase *v53; // r3
  idBitMsg v54; // [sp+50h] [-120h] BYREF
  _BYTE v55[240]; // [sp+80h] [-F0h] BYREF

  HIDWORD(v5) = (_cntlzw(gameLocal->GetGameDifficulty(this: gameLocal) - 3) & 0x20) != 0;
  v4 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
  LODWORD(v5) = 0;
  totalTime = this->totalTime;
  v7 = v4 - this->objectiveStartTimeMS;
  num = this->players.num;
  v9 = 0;
  this->bObjectiveActive = false;
  this->totalTime = totalTime + v7;
  if ( num > 0 )
  {
    v10 = 0;
    do
    {
      value = this->players.list[v10].player.spawnId.value;
      if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
      {
        v12 = (idPlayer *)gameLocal->entities.ptr[value & 0x1FFF];
        if ( v12 != nullptr )
        {
          v13 = idPlayer::CastTo(c: v12);
          if ( v13 != nullptr && !skipResults )
            idPlayer::SetForceInhibitControl(this: v13, inhibit: true);
        }
      }
      ++v9;
      ++v10;
    }
    while ( v9 < this->players.num );
  }
  if ( !skipResults )
  {
    v14 = this->players.num;
    memset(&v54.curSize, 0, 18);
    v54.writeData = v55;
    v54.readData = v55;
    v15 = 0;
    v54.maxSize = 128;
    v16 = 0;
    v54.tempValue = v5;
    if ( v14 > 0 )
    {
      v17 = 0;
      do
      {
        v18 = this->players.list[v17].player.spawnId.value;
        if ( gameLocal->spawnIds.ptr[v18 & 0x1FFF] != v18 >> 13 )
          break;
        v19 = (idPlayer *)gameLocal->entities.ptr[v18 & 0x1FFF];
        if ( v19 == nullptr )
          break;
        if ( idPlayer::CastTo(c: v19) == nullptr )
          break;
        ++v16;
        ++v15;
        ++v17;
      }
      while ( v16 < this->players.num );
    }
    idBitMsg::WriteBits(this: &v54, value: v15, numBits: 8);
    v20 = 0;
    if ( v15 > 0 )
    {
      v21 = 0;
      for ( i = v15; i != 0; --i )
      {
        v23 = this->players.list[v21].player.spawnId.value;
        if ( gameLocal->spawnIds.ptr[v23 & 0x1FFF] == v23 >> 13
          && (v24 = (idPlayer *)gameLocal->entities.ptr[v23 & 0x1FFF]) != nullptr )
        {
          v25 = idPlayer::CastTo(c: v24);
        }
        else
        {
          v25 = nullptr;
        }
        score = this->players.list[v21].score;
        v20 += score;
        idBitMsg::WriteBits(this: &v54, value: score, numBits: 32);
        SessionStat = idRageMetrics::GetSessionStat(
                        this: clientGame->rageMetrics,
                        playerId: v25->entityNumber,
                        stat: RAGE_STAT_AI_KILLS);
        idBitMsg::WriteBits(this: &v54, value: SessionStat, numBits: 32);
        v28 = idRageMetrics::GetSessionStat(
                this: clientGame->rageMetrics,
                playerId: v25->entityNumber,
                stat: RAGE_STAT_VEHICLE_DOUBLEKILLS);
        v29 = idRageMetrics::GetSessionStat(
                this: clientGame->rageMetrics,
                playerId: v25->entityNumber,
                stat: RAGE_STAT_VEHICLE_TRIPLEKILLS)
            + v28;
        v30 = idRageMetrics::GetSessionStat(
                this: clientGame->rageMetrics,
                playerId: v25->entityNumber,
                stat: RAGE_STAT_VEHICLE_QUADKILLS)
            + v29;
        v31 = idRageMetrics::GetSessionStat(
                this: clientGame->rageMetrics,
                playerId: v25->entityNumber,
                stat: RAGE_STAT_VEHICLE_KILLINGSPREES);
        idBitMsg::WriteBits(this: &v54, value: v31 + v30, numBits: 32);
        v32 = idRageMetrics::GetSessionStat(
                this: clientGame->rageMetrics,
                playerId: v25->entityNumber,
                stat: RAGE_STAT_HEADSHOT_KILLS);
        idBitMsg::WriteBits(this: &v54, value: v32, numBits: 32);
        v33 = idRageMetrics::GetSessionStat(
                this: clientGame->rageMetrics,
                playerId: v25->entityNumber,
                stat: RAGE_STAT_AI_ASSISTS);
        idBitMsg::WriteBits(this: &v54, value: v33, numBits: 32);
        v34 = idRageMetrics::GetSessionStat(
                this: clientGame->rageMetrics,
                playerId: v25->entityNumber,
                stat: RAGE_STAT_DEFEND_KILLS);
        idBitMsg::WriteBits(this: &v54, value: v34, numBits: 32);
        v35 = idRageMetrics::GetSessionStat(
                this: clientGame->rageMetrics,
                playerId: v25->entityNumber,
                stat: RAGE_STAT_PARTNER_REVIVES);
        idBitMsg::WriteBits(this: &v54, value: v35, numBits: 32);
        ++v21;
      }
    }
    idBitMsg::WriteBits(this: &v54, value: this->totalTime, numBits: 32);
    v36 = 0;
    v37 = 0;
    if ( this->collectibleList.num > 0 )
    {
      v38 = 0;
      do
      {
        if ( this->collectibleList.list[v38].found )
          ++v36;
        ++v37;
        ++v38;
      }
      while ( v37 < this->collectibleList.num );
    }
    idBitMsg::WriteBits(this: &v54, value: v36, numBits: 32);
    numCollectiblesToComplete = this->numCollectiblesToComplete;
    if ( numCollectiblesToComplete == -1 )
      numCollectiblesToComplete = this->collectibleList.num;
    idBitMsg::WriteBits(this: &v54, value: numCollectiblesToComplete, numBits: 32);
    idBitMsg::WriteBits(this: &v54, value: v20, numBits: 32);
    v40 = this->scoreRating.num;
    v41 = 0;
    v42 = -1;
    v43 = 1;
    if ( v40 > 1 )
    {
      list = this->scoreRating.list;
      v45 = 1;
      v46 = 0;
      do
      {
        points = list[v45].points;
        if ( points <= v20 && points >= *(int *)((char *)&list->points + v46) )
        {
          v41 = v43;
          v46 = v45 * 8;
        }
        if ( points > v42 )
          v42 = list[v45].points;
        ++v43;
        ++v45;
      }
      while ( v43 < v40 );
    }
    if ( v41 < v40 )
    {
      idBitMsg::WriteBits(this: &v54, value: v41, numBits: 8);
      if ( v42 == this->scoreRating.list[v41].points && v15 > 0 )
      {
        v48 = 0;
        for ( j = v15; j != 0; --j )
        {
          v50 = this->players.list[v48].player.spawnId.value;
          if ( gameLocal->spawnIds.ptr[v50 & 0x1FFF] == v50 >> 13
            && (v51 = (idPlayer *)gameLocal->entities.ptr[v50 & 0x1FFF]) != nullptr )
          {
            v52 = idPlayer::CastTo(c: v51);
          }
          else
          {
            v52 = nullptr;
          }
          idRageMetrics::CoopChallengeHighestScoreRank(
            this: clientGame->rageMetrics,
            player: v52,
            nightmare: SBYTE3(v5));
          ++v48;
        }
      }
    }
    else
    {
      idLib::Warning(fmt: "Incomplete coop score rating in %s", this->name.data);
      idBitMsg::WriteBits(this: &v54, value: 0, numBits: 8);
    }
    v53 = session->GetActingGameStateLobbyBase(this: session);
    v53->SendReliable(this: v53, a2: 19, a3: &v54, a4: true, a5: 255u);
  }
  this->objectiveScore = 0;
}


// ========================================================================
// ?GetTeamScore@idGameChallenge_Coop@@UBAHH@Z
// EA  : 0x82C52838
// RVA : 0x00C52838
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

int __fastcall idGameChallenge_Coop::GetTeamScore(idGameChallenge_Coop *this, int teamNum)
{
  int num; // r10
  int result; // r3
  idGameChallenge::playerData_t *list; // r8
  int v6; // r9
  int i; // ctr

  num = this->players.num;
  result = 0;
  if ( num > 0 )
  {
    list = this->players.list;
    v6 = 0;
    for ( i = num; i != 0; --i )
    {
      if ( gameLocal->spawnIds.ptr[list[v6].player.spawnId.value & 0x1FFF] == list[v6].player.spawnId.value >> 13 )
        result += list[v6].score;
      ++v6;
    }
  }
  return result;
}


// ========================================================================
// ?HasAllCollectibles@idGameChallenge_Coop@@QBA_NXZ
// EA  : 0x82C52898
// RVA : 0x00C52898
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

int __fastcall idGameChallenge_Coop::HasAllCollectibles(idGameChallenge_Coop *this)
{
  int numCollectiblesToComplete; // r7
  int num; // r11
  int v3; // r8
  int v4; // r11
  int v5; // ctr
  int v6; // r11
  unsigned __int8 v7; // r11
  bool v8; // zf

  numCollectiblesToComplete = this->numCollectiblesToComplete;
  if ( numCollectiblesToComplete == -1 )
    num = this->collectibleList.num;
  else
    num = this->numCollectiblesToComplete;
  if ( num <= 0 )
    return 0;
  v3 = 0;
  if ( this->collectibleList.num > 0 )
  {
    v4 = 0;
    v5 = this->collectibleList.num;
    do
    {
      if ( this->collectibleList.list[v4].found )
        ++v3;
      ++v4;
      --v5;
    }
    while ( v5 != 0 );
  }
  v6 = this->collectibleList.num;
  if ( numCollectiblesToComplete != -1 )
    v6 = this->numCollectiblesToComplete;
  v8 = v3 >= v6;
  v7 = 1;
  if ( !v8 )
    return 0;
  return v7;
}


// ========================================================================
// ?MPCallout_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82C52918
// RVA : 0x00C52918
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

void __fastcall MPCallout_f(const idCmdArgs *args)
{
  idGameChallenge *ChallengeEntity; // r3
  const char *v3; // r4

  ChallengeEntity = idGameLocal::GetChallengeEntity(this: gameLocal);
  if ( _RTDynamicCast(
         inptr: (void *)ChallengeEntity,
         VfDelta: 0,
         SrcType: (void *)&idGameChallenge `RTTI Type Descriptor',
         TargetType: &idGameChallenge_Coop `RTTI Type Descriptor',
         isReference: 0) == nullptr )
  {
    idLib::Warning(fmt: "No active Game Challenge");
    return;
  }
  if ( args->argc <= 1 )
  {
    v3 = &byte_8200D768;
LABEL_5:
    if ( idDeclInfo::FindWithInheritance(this: &idDeclOnlineScoringCallout::resourceList, name: v3, makeDefault: false) != nullptr )
      return;
    goto LABEL_6;
  }
  v3 = args->argv[1];
  if ( v3 != nullptr )
    goto LABEL_5;
LABEL_6:
  idLib::Warning(fmt: "Invalid callout");
}


// ========================================================================
// ?SyncMigrationGameDataWithSession@idGameChallenge@@UAAX_N@Z
// EA  : 0x82C52A18
// RVA : 0x00C52A18
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idGameChallenge::SyncMigrationGameDataWithSession(idGameChallenge *this, BOOL reading)
{
  int v2; // r30 OVERLAPPED
  idLobbyBase *v5; // r3
  unsigned __int8 matchFlags; // r31
  idLobbyBase *v7; // r3
  int v8; // r31 OVERLAPPED
  idGameChallenge_vtbl *v9; // r11
  void (__fastcall *SerializeMigrationGameData)(idGameChallenge *, idSerializer *); // ctr
  int v11; // r23
  int v12; // r27
  int value; // r9
  idPlayer *v14; // r3
  idLobbyBase *v15; // r29
  int v16; // r9
  idPlayer *v17; // r3
  idPlayer *v18; // r3
  idPresentable *presentable; // r3
  lobbyUserID_t *v20; // r4
  idLobbyBase_vtbl *v21; // r30 OVERLAPPED
  idPresentablePlayer *LobbyUserID; // r3
  idGameChallenge::playerData_t *list; // r11
  int v24; // r9
  idPlayer *v25; // r3
  idPlayer *v26; // r3
  idPresentable *v27; // r3
  lobbyUserID_t *v28; // r4
  idSession_vtbl *v29; // r30
  idPresentablePlayer *v30; // r3
  idGameChallenge_vtbl *v31; // r9
  idGameChallenge::playerData_t *v32; // r11
  void (__fastcall *SerializeMigrationUserData)(idGameChallenge *, idSerializer *, idGameChallenge::playerData_t *); // ctr
  bool v34; // [sp+50h] [-D0h] BYREF
  _DWORD *v35; // [sp+54h] [-CCh]
  bool v36; // [sp+58h] [-C8h] BYREF
  _DWORD *v37; // [sp+5Ch] [-C4h]
  char v38; // [sp+60h] [-C0h] BYREF
  char v39; // [sp+68h] [-B8h] BYREF
  _DWORD v40[7]; // [sp+70h] [-B0h] BYREF
  char v41; // [sp+8Ch] [-94h]
  char v42; // [sp+8Dh] [-93h]
  __int64 v43; // [sp+90h] [-90h]
  _DWORD v44[7]; // [sp+A0h] [-80h] BYREF
  char v45; // [sp+BCh] [-64h]
  char v46; // [sp+BDh] [-63h]
  __int64 v47; // [sp+C0h] [-60h]

  if ( this->gameMode != CHALLENGE_MODE_COOP )
  {
    v5 = session->GetActingGameStateLobbyBase(this: session);
    matchFlags = v5->GetMatchParms(this: v5)->matchFlags;
    v7 = session->GetActingGameStateLobbyBase(this: session);
    if ( v7->GetNumLobbyUsers(this: v7) >= ((_cntlzw(matchFlags & 0x80) & 0x20) != 0) + 1 )
    {
      v8 = 0;
      memset(v40, 0, sizeof(v40));
      v41 = 0;
      v42 = 0;
      v43 = *(_QWORD *)(&v2 - 1);
      if ( session->GetMigrationGameData(this: session, a2: (idBitMsg *)v40, a3: reading) )
      {
        v9 = this->__vftable;
        v35 = v40;
        SerializeMigrationGameData = v9->SerializeMigrationGameData;
        v34 = (_cntlzw(reading) & 0x20) != 0;
        SerializeMigrationGameData(this, a2: (idSerializer *)&v34);
        if ( reading )
          this->wasMigratedGame = true;
      }
      v11 = 0;
      if ( this->players.num > 0 )
      {
        v12 = 0;
        do
        {
          value = this->players.list[v12].player.spawnId.value;
          if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
          {
            v14 = (idPlayer *)gameLocal->entities.ptr[value & 0x1FFF];
            if ( v14 != nullptr && idPlayer::CastTo(c: v14) != nullptr )
            {
              v15 = session->GetGameLobbyBase(this: session);
              v16 = this->players.list[v12].player.spawnId.value;
              if ( gameLocal->spawnIds.ptr[v16 & 0x1FFF] == v16 >> 13
                && (v17 = (idPlayer *)gameLocal->entities.ptr[v16 & 0x1FFF]) != nullptr )
              {
                v18 = idPlayer::CastTo(c: v17);
              }
              else
              {
                v18 = nullptr;
              }
              presentable = v18->presentable;
              v20 = presentable != nullptr
                  ? (lobbyUserID_t *)presentable->GetPlayerInterface_2(this: presentable)
                  : nullptr;
              v21 = v15->__vftable;
              LobbyUserID = idPresentablePlayer::GetLobbyUserID(this: (idPresentablePlayer *)&v38, result: v20);
              if ( v21->IsLobbyUserValid(
                     this: (idLobbyBase *)LobbyUserID->__vftable,
                     a2: *((lobbyUserID_t **)&LobbyUserID->__vftable + 1)) )
              {
                memset(v44, 0, sizeof(v44));
                v47 = *(_QWORD *)&v8;
                list = this->players.list;
                v46 = 0;
                v45 = 0;
                v24 = list[v12].player.spawnId.value;
                if ( gameLocal->spawnIds.ptr[v24 & 0x1FFF] == v24 >> 13
                  && (v25 = (idPlayer *)gameLocal->entities.ptr[v24 & 0x1FFF]) != nullptr )
                {
                  v26 = idPlayer::CastTo(c: v25);
                }
                else
                {
                  v26 = nullptr;
                }
                v27 = v26->presentable;
                if ( v27 != nullptr )
                  v28 = (lobbyUserID_t *)v27->GetPlayerInterface_2(this: v27);
                else
                  v28 = nullptr;
                v29 = session->__vftable;
                v30 = idPresentablePlayer::GetLobbyUserID(this: (idPresentablePlayer *)&v39, result: v28);
                if ( v29->GetMigrationGameDataUser(
                       this: (idSession *)v30->__vftable,
                       a2: *((lobbyUserID_t **)&v30->__vftable + 1),
                       a3: (idBitMsg *)v44,
                       a4: reading) )
                {
                  v31 = this->__vftable;
                  v32 = this->players.list;
                  v37 = v44;
                  SerializeMigrationUserData = v31->SerializeMigrationUserData;
                  v36 = (_cntlzw(reading) & 0x20) != 0;
                  SerializeMigrationUserData(this, a2: (idSerializer *)&v36, a3: &v32[v12]);
                }
              }
            }
          }
          ++v11;
          ++v12;
        }
        while ( v11 < this->players.num );
      }
      if ( !reading )
        idCVar::SetBool(this: &gc_hostMigration_debug, newValue: false, force: true);
    }
  }
}


// ========================================================================
// ?SerializeMigrationUserData@idGameChallenge@@UAAXAAVidSerializer@@AAUplayerData_t@1@@Z
// EA  : 0x82C52DA0
// RVA : 0x00C52DA0
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

void __fastcall idGameChallenge::SerializeMigrationUserData(
        idGameChallenge *this,
        idSerializer *ser,
        idGameChallenge::playerData_t *data)
{
  const idDeclGameMode *v5; // r19
  idPlayer *v6; // r3
  idPlayer *v7; // r3
  int v8; // r20
  int v9; // r23
  rageStat_t v10; // r29
  idPlayer *v11; // r3
  idPlayer *v12; // r3
  unsigned __int16 SessionStat; // r30
  idPlayer *v14; // r3
  idBitMsg *msg; // r3
  idPlayer *v16; // r3
  idPlayer *v17; // r11
  idPlayer *v18; // r3
  idPlayer *v19; // r4
  idBitMsg *v20; // r11
  int score; // [sp+50h] [-80h] BYREF

  v5 = idDeclGameMode::challengeModeLookup.list[this->gameMode];
  if ( v5 != nullptr && gameLocal->spawnIds.ptr[data->player.spawnId.value & 0x1FFF] == data->player.spawnId.value >> 13 )
  {
    v6 = (idPlayer *)gameLocal->entities.ptr[data->player.spawnId.value & 0x1FFF];
    if ( v6 != nullptr && idPlayer::CastTo(c: v6) != nullptr )
    {
      score = data->score;
      idSerializer::Serialize(this: ser, value: &score);
      data->score = score;
      if ( gc_hostMigration_debug.valueInteger != 0 )
      {
        v7 = idEntityPtr<idPlayer>::operator->(this: &data->player);
        idLib::Printf(fmt: "Serialized player %d score: %d\n", v7->entityNumber, data->score);
      }
      v8 = 0;
      if ( v5->migrationStats.num > 0 )
      {
        v9 = 0;
        do
        {
          v10 = v5->migrationStats.list[v9];
          if ( v10 != RAGE_STAT_INVALID )
          {
            if ( gameLocal->spawnIds.ptr[data->player.spawnId.value & 0x1FFF] == data->player.spawnId.value >> 13
              && (v11 = (idPlayer *)gameLocal->entities.ptr[data->player.spawnId.value & 0x1FFF]) != nullptr )
            {
              v12 = idPlayer::CastTo(c: v11);
            }
            else
            {
              v12 = nullptr;
            }
            SessionStat = idRageMetrics::GetSessionStat(
                            this: clientGame->rageMetrics,
                            playerId: v12->entityNumber,
                            stat: v10);
            if ( !ser->writing && SessionStat != 0 )
            {
              v14 = idEntityPtr<idPlayer>::operator->(this: &data->player);
              idLib::Warning(
                fmt: "Migrating game stats player %d and session value is already > 0! Stat: %d value: %d",
                v14->entityNumber,
                v10,
                SessionStat);
            }
            msg = ser->msg;
            if ( ser->writing )
              idBitMsg::WriteBits(this: msg, value: SessionStat, numBits: 16);
            else
              SessionStat = idBitMsg::ReadBits(this: msg, numBits: 16);
            if ( gc_hostMigration_debug.valueInteger != 0 )
            {
              if ( gameLocal->spawnIds.ptr[data->player.spawnId.value & 0x1FFF] == data->player.spawnId.value >> 13
                && (v16 = (idPlayer *)gameLocal->entities.ptr[data->player.spawnId.value & 0x1FFF]) != nullptr )
              {
                v17 = idPlayer::CastTo(c: v16);
              }
              else
              {
                v17 = nullptr;
              }
              idLib::Printf(fmt: "Serialized player %d stat %d value %d\n", v17->entityNumber, v10, SessionStat);
            }
            if ( !ser->writing )
            {
              if ( gameLocal->spawnIds.ptr[data->player.spawnId.value & 0x1FFF] == data->player.spawnId.value >> 13
                && (v18 = (idPlayer *)gameLocal->entities.ptr[data->player.spawnId.value & 0x1FFF]) != nullptr )
              {
                v19 = idPlayer::CastTo(c: v18);
              }
              else
              {
                v19 = nullptr;
              }
              idRageMetrics::StatAddInt(this: clientGame->rageMetrics, player: v19, stat: v10, value: SessionStat);
            }
          }
          ++v8;
          ++v9;
        }
        while ( v8 < v5->migrationStats.num );
      }
      if ( gc_hostMigration_debug.valueInteger != 0 )
      {
        v20 = ser->msg;
        idLib::Printf(
          fmt: "SerializeMigrationUserData size: %d left: %d\n",
          (v20->writeBit != 0) + v20->curSize,
          v20->maxSize - (v20->writeBit != 0) - v20->curSize);
      }
    }
  }
}


// ========================================================================
// ?RegisterNewPlayer@idGameChallenge@@UAA_NAAUplayerData_t@1@PAVidPlayer@@_N@Z
// EA  : 0x82C530A0
// RVA : 0x00C530A0
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

int __fastcall idGameChallenge::RegisterNewPlayer(
        idGameChallenge *this,
        idGameChallenge::playerData_t *data,
        idPlayer *player,
        bool initial)
{
  BOOL v8; // r27
  bool IsBot; // r3
  bool v10; // r11
  int *p_timeTillNewPlayerCanTake; // r10
  int i; // ctr
  idGameChallenge_vtbl *v13; // r11

  if ( player == nullptr )
    return 0;
  data->player.spawnId.value = (gameLocal->spawnIds.ptr[player->entityNumber] << 13) | player->entityNumber;
  data->lives = this->numLives;
  data->score = 0;
  data->lastScore = 0;
  v8 = initial;
  data->startTime = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
  data->stateTime = 0;
  data->respawnDelay = 0;
  data->timeTillNewPlayerCanTake = -1;
  data->lastKiller = -1;
  data->state = PLAYER_STATE_NONE;
  if ( v8 || (IsBot = idPlayer::IsBot(this: player), v10 = true, IsBot) )
    v10 = false;
  data->timeTillNewPlayerCanTake = -1;
  data->needToSendFullSnap = v10;
  common->ResetPlayerInput(this: common, a2: player->entityNumber);
  idRageMetrics::ResetStats(this: clientGame->rageMetrics, player);
  idRageMetrics::AddPlayer(this: clientGame->rageMetrics, player);
  p_timeTillNewPlayerCanTake = &data->timeTillNewPlayerCanTake;
  for ( i = 6; i != 0; --i )
    *++p_timeTillNewPlayerCanTake = 0;
  if ( !idPlayer::IsBot(this: player) )
  {
    v13 = this->__vftable;
    if ( v8 )
    {
      v13->SetSpectator(this, a2: data, a3: true);
      return 1;
    }
    v13->SetPlayerState(this, a2: data, a3: PLAYER_STATE_RESPAWNING, a4: 0);
  }
  return 1;
}


// ========================================================================
// ?EnterState_PLAYER_STATE_VDM_SELECT_LOADOUT@idGameChallenge@@UAAXAAUplayerData_t@1@@Z
// EA  : 0x82C53230
// RVA : 0x00C53230
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idGameChallenge::EnterState_PLAYER_STATE_VDM_SELECT_LOADOUT(
        idGameChallenge *this,
        idGameChallenge::playerData_t *data)
{
  idGameChallenge::playerData_t *v2; // r30 OVERLAPPED
  idPlayer *v3; // r3
  int v4; // r31
  idLobbyBase *v5; // r3
  int value; // r5
  idLobbyBase *v7; // r30
  int v8; // r8
  idPlayer *v9; // r3
  idPlayer *v10; // r3
  idPresentable *presentable; // r3
  lobbyUserID_t *v12; // r4
  idLobbyBase_vtbl *v13; // r31
  idPresentablePlayer *LobbyUserID; // r3
  _BYTE v15[8]; // [sp+50h] [-60h] BYREF
  char v16; // [sp+58h] [-58h] BYREF
  _DWORD v17[7]; // [sp+60h] [-50h] BYREF
  char v18; // [sp+7Ch] [-34h]
  char v19; // [sp+7Dh] [-33h]
  __int64 v20; // [sp+80h] [-30h]

  v2 = data;
  if ( gameLocal->spawnIds.ptr[data->player.spawnId.value & 0x1FFF] == data->player.spawnId.value >> 13 )
  {
    v3 = (idPlayer *)gameLocal->entities.ptr[data->player.spawnId.value & 0x1FFF];
    if ( v3 != nullptr && idPlayer::CastTo(c: v3) != nullptr )
    {
      v4 = 0;
      memset(&v17[3], 0, 16);
      v17[0] = v15;
      v17[1] = v15;
      v17[2] = 4;
      v18 = 0;
      v19 = 0;
      v20 = *(_QWORD *)(&v2 - 1);
      v5 = session->GetActingGameStateLobbyBase(this: session);
      value = v2->player.spawnId.value;
      v8 = gameLocal->spawnIds.ptr[v2->player.spawnId.value & 0x1FFF];
      v7 = v5;
      if ( v8 == value >> 13 && (v9 = (idPlayer *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
        v10 = idPlayer::CastTo(c: v9);
      else
        v10 = nullptr;
      presentable = v10->presentable;
      if ( presentable != nullptr )
        v12 = (lobbyUserID_t *)presentable->GetPlayerInterface_2(this: presentable);
      else
        v12 = nullptr;
      v13 = v7->__vftable;
      LobbyUserID = idPresentablePlayer::GetLobbyUserID(this: (idPresentablePlayer *)&v16, result: v12);
      v13->SendReliableToLobbyUser(
        this: (idLobbyBase *)LobbyUserID->__vftable,
        a2: *((lobbyUserID_t **)&LobbyUserID->__vftable + 1),
        a3: 20,
        a4: (idBitMsg *)v17);
    }
  }
}


// ========================================================================
// ?EnterState_PLAYER_STATE_VDM_FORCE_SELECT_LOADOUT@idGameChallenge@@UAAXAAUplayerData_t@1@@Z
// EA  : 0x82C53380
// RVA : 0x00C53380
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idGameChallenge::EnterState_PLAYER_STATE_VDM_FORCE_SELECT_LOADOUT(
        idGameChallenge *this,
        idGameChallenge::playerData_t *data)
{
  idGameChallenge::playerData_t *v2; // r30 OVERLAPPED
  idPlayer *v3; // r3
  int value; // r9
  int v5; // r31
  int v6; // r11
  idPlayer *v7; // r3
  idPlayer *v8; // r3
  idLobbyBase *v9; // r3
  idLobbyBase *v10; // r30
  int v11; // r11
  int v12; // r7
  idPlayer *v13; // r3
  idPlayer *v14; // r3
  idPresentable *presentable; // r3
  lobbyUserID_t *v16; // r4
  idLobbyBase_vtbl *v17; // r31
  idPresentablePlayer *LobbyUserID; // r3
  _BYTE v19[8]; // [sp+50h] [-60h] BYREF
  char v20; // [sp+58h] [-58h] BYREF
  idBitMsg v21[2]; // [sp+60h] [-50h] BYREF

  v2 = data;
  if ( gameLocal->spawnIds.ptr[data->player.spawnId.value & 0x1FFF] == data->player.spawnId.value >> 13 )
  {
    v3 = (idPlayer *)gameLocal->entities.ptr[data->player.spawnId.value & 0x1FFF];
    if ( v3 != nullptr && idPlayer::CastTo(c: v3) != nullptr )
    {
      value = v2->player.spawnId.value;
      v5 = 0;
      v6 = v2->player.spawnId.value & 0x1FFF;
      v21[0].curSize = 0;
      v21[0].writeData = v19;
      v21[0].writeBit = 0;
      v21[0].readData = v19;
      v21[0].readCount = 0;
      v21[0].maxSize = 4;
      v21[0].readBit = 0;
      v21[0].allowOverflow = false;
      v21[0].overflowed = false;
      v21[0].tempValue = *(_QWORD *)(&v2 - 1);
      if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
        && (v7 = (idPlayer *)gameLocal->entities.ptr[v6]) != nullptr )
      {
        v8 = idPlayer::CastTo(c: v7);
      }
      else
      {
        v8 = nullptr;
      }
      idBitMsg::WriteBits(this: v21, value: v8->entityNumber, numBits: 8);
      idBitMsg::WriteBits(this: v21, value: 0, numBits: 8);
      v9 = session->GetActingGameStateLobbyBase(this: session);
      v11 = v2->player.spawnId.value & 0x1FFF;
      v12 = v2->player.spawnId.value >> 13;
      v10 = v9;
      if ( gameLocal->spawnIds.ptr[v11] == v12 && (v13 = (idPlayer *)gameLocal->entities.ptr[v11]) != nullptr )
        v14 = idPlayer::CastTo(c: v13);
      else
        v14 = nullptr;
      presentable = v14->presentable;
      if ( presentable != nullptr )
        v16 = (lobbyUserID_t *)presentable->GetPlayerInterface_2(this: presentable);
      else
        v16 = nullptr;
      v17 = v10->__vftable;
      LobbyUserID = idPresentablePlayer::GetLobbyUserID(this: (idPresentablePlayer *)&v20, result: v16);
      v17->SendReliableToLobbyUser(
        this: (idLobbyBase *)LobbyUserID->__vftable,
        a2: *((lobbyUserID_t **)&LobbyUserID->__vftable + 1),
        a3: 7,
        a4: v21);
    }
  }
}


// ========================================================================
// ?HandleState_PLAYER_STATE_NONE@idGameChallenge@@UAAXAAUplayerData_t@1@@Z
// EA  : 0x82C53530
// RVA : 0x00C53530
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

void __fastcall idGameChallenge::HandleState_PLAYER_STATE_NONE(
        idGameChallenge *this,
        idGameChallenge::playerData_t *data)
{
  idPlayer *v4; // r3
  idPlayer *v5; // r3
  int v6; // r6
  challengePlayerState_t v7; // r5

  if ( gameLocal->spawnIds.ptr[data->player.spawnId.value & 0x1FFF] == data->player.spawnId.value >> 13
    && (v4 = (idPlayer *)gameLocal->entities.ptr[data->player.spawnId.value & 0x1FFF]) != nullptr )
  {
    v5 = idPlayer::CastTo(c: v4);
  }
  else
  {
    v5 = nullptr;
  }
  if ( idPlayer::IsBot(this: v5) )
  {
    v6 = 0;
    v7 = PLAYER_STATE_RESPAWNING;
  }
  else
  {
    v6 = session->GetTitleStorageInt_2(
           this: session,
           a2: "gc_preGameLoadoutDelay",
           a3: gc_preGameLoadoutDelay.valueInteger);
    v7 = PLAYER_STATE_VDM_GAME_MODE_INFO;
  }
  this->SetPlayerState(this, a2: data, a3: v7, a4: v6);
}


// ========================================================================
// ?HandleState_PLAYER_STATE_VDM_SELECT_LOADOUT@idGameChallenge@@UAAXAAUplayerData_t@1@@Z
// EA  : 0x82C53618
// RVA : 0x00C53618
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

void __fastcall idGameChallenge::HandleState_PLAYER_STATE_VDM_SELECT_LOADOUT(
        idGameChallenge *this,
        idGameChallenge::playerData_t *data)
{
  idPlayer *v4; // r3
  idPlayer *v5; // r3

  if ( gameLocal->spawnIds.ptr[data->player.spawnId.value & 0x1FFF] == data->player.spawnId.value >> 13
    && (v4 = (idPlayer *)gameLocal->entities.ptr[data->player.spawnId.value & 0x1FFF]) != nullptr )
  {
    v5 = idPlayer::CastTo(c: v4);
  }
  else
  {
    v5 = nullptr;
  }
  if ( v5->loadoutChanged )
    this->SetPlayerState(this, a2: data, a3: PLAYER_STATE_RESPAWNING, a4: 0);
}


// ========================================================================
// ?HandleState_PLAYER_STATE_RESPAWNING@idGameChallenge@@UAAXAAUplayerData_t@1@@Z
// EA  : 0x82C536C0
// RVA : 0x00C536C0
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

void __fastcall idGameChallenge::HandleState_PLAYER_STATE_RESPAWNING(
        idGameChallenge *this,
        idGameChallenge::playerData_t *data)
{
  idPlayer *v4; // r3
  unsigned int spawnHandle; // r4
  idEntityPtr<idEntity> *SpawnResult; // r3
  idEntityPtr<idEntity> *v7; // r30
  idPlayer *v8; // r3
  idPlayer *v9; // r28
  idPlayer *v10; // r3
  idPlayer *v11; // r3

  if ( gameLocal->spawnIds.ptr[data->player.spawnId.value & 0x1FFF] == data->player.spawnId.value >> 13 )
  {
    v4 = (idPlayer *)gameLocal->entities.ptr[data->player.spawnId.value & 0x1FFF];
    if ( v4 != nullptr && idPlayer::CastTo(c: v4) != nullptr )
    {
      spawnHandle = data->spawnHandle;
      if ( spawnHandle != 0 )
      {
        SpawnResult = (idEntityPtr<idEntity> *)idSpawnManager::GetSpawnResult(
                                                 this: this->spawnManager,
                                                 handle: spawnHandle);
        v7 = SpawnResult;
        if ( SpawnResult != nullptr && SpawnResult->spawnId.value >= 2 )
        {
          if ( SpawnResult->spawnId.value == 2 )
          {
            if ( SpawnResult[2].spawnId.value != 0 )
            {
              v8 = (idPlayer *)idEntityPtr<idEntity const>::operator->(this: SpawnResult + 1);
              v9 = idPlayer::CastTo(c: v8);
              if ( v9 != nullptr && v9 == idEntityPtr<idPlayer>::operator->(this: &data->player) )
                this->FinalizeRespawnPlayer(
                  this,
                  a2: data,
                  a3: (const idVec3 *)v7[2].spawnId.value,
                  a4: (const idAngles *)(v7[2].spawnId.value + 12));
              else
                idLib::Warning(fmt: "SPAWN: Player is NULL or doesn't match");
            }
            else
            {
              idLib::Warning(fmt: "SPAWN: Spawn result location is NULL");
            }
            idSpawnManager::ReleaseSpawnResult(this: this->spawnManager, handle: data->spawnHandle);
            data->spawnHandle = 0;
          }
          else if ( SpawnResult->spawnId.value == 3 )
          {
            idSpawnManager::ReleaseSpawnResult(this: this->spawnManager, handle: data->spawnHandle);
            data->spawnHandle = 0;
            v10 = (idPlayer *)idEntityPtr<idEntity const>::operator->(this: v7 + 1);
            v11 = idPlayer::CastTo(c: v10);
            if ( v11 != nullptr )
            {
              idLib::Warning(fmt: "SPAWN: Spawn result FAILED for player number %d. Staring over", v11->entityNumber);
              this->RespawnPlayer(this, a2: data, a3: CT_SPAWN_PLAYER);
            }
            else
            {
              idLib::Warning(fmt: "SPAWN: Spawn result FAILED - NULL player");
            }
          }
        }
      }
    }
  }
}


// ========================================================================
// ?ProcessPlayerStates@idGameChallenge@@UAAXXZ
// EA  : 0x82C53850
// RVA : 0x00C53850
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

void __fastcall idGameChallenge::ProcessPlayerStates(idGameChallenge *this)
{
  int v2; // r27
  int v3; // r29
  idGameChallenge::playerData_t *v4; // r30
  idPlayer *v5; // r3
  unsigned int state; // r11

  v2 = 0;
  if ( this->players.num > 0 )
  {
    v3 = 0;
    do
    {
      v4 = &this->players.list[v3];
      if ( gameLocal->spawnIds.ptr[v4->player.spawnId.value & 0x1FFF] == v4->player.spawnId.value >> 13 )
      {
        v5 = (idPlayer *)gameLocal->entities.ptr[v4->player.spawnId.value & 0x1FFF];
        if ( v5 != nullptr && idPlayer::CastTo(c: v5) != nullptr )
        {
          if ( this->PlayerStateExpired(this, a2: v4) && (unsigned int)(v4->state - 1) <= 5 )
          {
            switch ( v4->state )
            {
              case PLAYER_STATE_VDM_SELECT_LOADOUT:
                this->StateExpired_PLAYER_STATE_VDM_SELECT_LOADOUT(this, a2: v4);
                break;
              case PLAYER_STATE_VDM_FORCE_SELECT_LOADOUT:
              case PLAYER_STATE_IN_PROGRESS:
LABEL_34:
                break;
              case PLAYER_STATE_WAITING_TO_RESPAWN_FROM_DEATH:
                this->StateExpired_PLAYER_STATE_WAITING_TO_RESPAWN_FROM_DEATH(this, a2: v4);
                break;
              case PLAYER_STATE_VDM_GAME_MODE_INFO:
                this->StateExpired_PLAYER_STATE_VDM_GAME_MODE_INFO(this, a2: v4);
                break;
              default:
                this->StateExpired_PLAYER_STATE_SPECTATE_AFTER_DEATH(this, a2: v4);
                goto LABEL_34;
            }
          }
          state = v4->state;
          if ( state <= 7 && state != 1 )
          {
            switch ( state )
            {
              case 2u:
                this->HandleState_PLAYER_STATE_VDM_SELECT_LOADOUT(this, a2: v4);
                break;
              case 3u:
                this->HandleState_PLAYER_STATE_VDM_FORCE_SELECT_LOADOUT(this, a2: v4);
                break;
              case 4u:
LABEL_35:
                break;
              case 5u:
                this->HandleState_PLAYER_STATE_WAITING_TO_RESPAWN_FROM_DEATH(this, a2: v4);
                break;
              case 6u:
                this->HandleState_PLAYER_STATE_SPECTATE_AFTER_DEATH(this, a2: v4);
                break;
              default:
                if ( state != 0 )
                  this->HandleState_PLAYER_STATE_RESPAWNING(this, a2: v4);
                else
                  this->HandleState_PLAYER_STATE_NONE(this, a2: v4);
                goto LABEL_35;
            }
          }
        }
      }
      ++v2;
      ++v3;
    }
    while ( v2 < this->players.num );
  }
}


// ========================================================================
// ?IsLeaderTied@idGameChallenge@@UAA_NXZ
// EA  : 0x82C539F8
// RVA : 0x00C539F8
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

int __fastcall idGameChallenge::IsLeaderTied(idGameChallenge *this)
{
  int num; // r10
  int v4; // r24
  int v5; // r27
  int v6; // r25
  int v7; // r29
  int value; // r9
  idPlayer *v9; // r3
  int v10; // r3
  gameTeam_t team; // r11
  idGameChallenge::playerData_t *v12; // r30
  unsigned __int8 v13; // r11
  int v14; // [sp+50h] [-50h] BYREF
  int v15; // [sp+54h] [-4Ch]

  num = this->players.num;
  if ( num == 0 )
    return 0;
  v4 = 0;
  v5 = -2147483647;
  v14 = -2147483647;
  v6 = 0;
  v15 = -2147483647;
  if ( num <= 0 )
    goto LABEL_17;
  v7 = 0;
  do
  {
    value = this->players.list[v7].player.spawnId.value;
    if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
    {
      v9 = (idPlayer *)gameLocal->entities.ptr[value & 0x1FFF];
      if ( v9 != nullptr && idPlayer::CastTo(c: v9) != nullptr )
      {
        v10 = this->GetPlayerScore(this, a2: &this->players.list[v7]);
        team = this->players.list[v7].team;
        if ( team != TEAM_NONE )
        {
          if ( *(&v14 + team - 1) == -2147483647 )
          {
            v12 = &this->players.list[v7];
            *(&v14 + v12->team - 1) = this->GetTeamScore(this, a2: v12->team);
          }
        }
        else if ( v10 <= v5 )
        {
          if ( v10 == v5 )
            ++v4;
        }
        else
        {
          v5 = v10;
          v4 = 1;
        }
      }
    }
    ++v6;
    ++v7;
  }
  while ( v6 < this->players.num );
  if ( v5 == -2147483647 )
  {
LABEL_17:
    if ( v14 <= -2147483647 )
    {
      if ( v14 == -2147483647 )
        ++v4;
    }
    else
    {
      v5 = v14;
      v4 = 1;
    }
    if ( v15 > v5 )
      return 0;
    if ( v15 == v5 )
      ++v4;
  }
  v13 = 1;
  if ( v4 <= 1 )
    return 0;
  return v13;
}


// ========================================================================
// ?GetPlayerData@idGameChallenge@@QAAPAUplayerData_t@1@H@Z
// EA  : 0x82C53BA8
// RVA : 0x00C53BA8
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

idGameChallenge::playerData_t *__fastcall idGameChallenge::GetPlayerData(
        idGameChallenge *this,
        unsigned int playerEntityNumber)
{
  int v4; // r29
  int v5; // r31
  idGameLocal *v6; // r9
  idGameChallenge::playerData_t *v7; // r11
  idPlayer *v8; // r3
  idPlayer *v9; // r3

  if ( playerEntityNumber > 5 )
    return nullptr;
  v4 = 0;
  if ( this->players.num <= 0 )
    return nullptr;
  v5 = 0;
  v6 = gameLocal;
  while ( 1 )
  {
    v7 = &this->players.list[v5];
    if ( v6->spawnIds.ptr[v7->player.spawnId.value & 0x1FFF] == v7->player.spawnId.value >> 13 )
    {
      v8 = (idPlayer *)v6->entities.ptr[v7->player.spawnId.value & 0x1FFF];
      if ( v8 != nullptr )
      {
        v9 = idPlayer::CastTo(c: v8);
        v6 = gameLocal;
      }
      else
      {
        v9 = nullptr;
      }
      if ( v9->entityNumber == playerEntityNumber )
        break;
    }
    ++v4;
    ++v5;
    if ( v4 >= this->players.num )
      return nullptr;
  }
  return &this->players.list[v4];
}


// ========================================================================
// ?GetRunnerUpScore@idGameChallenge@@UAAHXZ
// EA  : 0x82C53CA8
// RVA : 0x00C53CA8
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

encounterGroupRole_t __fastcall idGameChallenge::GetRunnerUpScore(idGameChallenge *this)
{
  int v1; // r29
  unsigned __int64 v3; // r8
  int v4; // r6
  __int64 v5; // r10
  int v6; // r28
  int num; // r29
  encounterGroupRole_t *list; // r30
  encounterGroupRole_t v10; // r29
  idSort_Quick<int,idSort_QuickDefault<int> > v11; // [sp+50h] [-50h] BYREF
  int v12; // [sp+54h] [-4Ch] BYREF
  idList<enum encounterGroupRole_t,5> v13[4]; // [sp+60h] [-40h] BYREF

  v1 = 0;
  memset(v13, 0, 14);
  v13[0].listStatic = 0;
  v13[0].memTag = 5;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)v13);
  LODWORD(v5) = this->players.num;
  v6 = 0;
  if ( (int)v5 > 0 )
  {
    do
    {
      v12 = this->GetPlayerScore(this, a2: &this->players.list[v1]);
      idList<idAnimWebBlendTree *,5>::Append(this: v13, obj: (encounterGroupRole_t *)&v12);
      LODWORD(v3) = this->players.num;
      ++v6;
      ++v1;
    }
    while ( v6 < (int)v3 );
  }
  num = v13[0].num;
  if ( v13[0].num > 1 )
  {
    v11.__vftable = (idSort_Quick<int,idSort_QuickDefault<int> >_vtbl *)&idSort_QuickDefault<int>::`vftable';
    list = v13[0].list;
    if ( v13[0].list != nullptr )
      idSort_Quick<int,idSort_QuickDefault<int>>::Sort(
        this: &v11,
        base: (int *)v13[0].list,
        num: v13[0].num,
        a4: v4,
        a5: v3,
        a6: v5);
    v11.__vftable = (idSort_Quick<int,idSort_QuickDefault<int> >_vtbl *)&idSort<int>::`vftable';
    v10 = list[num - 2];
    if ( (v13[0].listStatic == 0 || v13[0].listStatic == 2) && list != nullptr )
      idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
    return v10;
  }
  else
  {
    if ( (v13[0].listStatic == 0 || v13[0].listStatic == 2) && v13[0].list != nullptr )
      idMem::Free(this: &mem, ptr: v13[0].list, align: ALIGN_16);
    return ROLE_NONE;
  }
}


// ========================================================================
// __unwind$499680
// EA  : 0x82C53DFC
// RVA : 0x00C53DFC
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

void _unwind_499680()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 160 + 96));
}


// ========================================================================
// __unwind$499681
// EA  : 0x82C53E24
// RVA : 0x00C53E24
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

void _unwind_499681()
{
  int v0; // r12

  idSort_EntryDepthAndTicks::~idSort_EntryDepthAndTicks(this: (idSort_AnimEventSort *)(v0 - 160 + 80));
}


// ========================================================================
// ?GetScoringData@idGameChallenge@@UAAXABUplayerData_t@1@AAH111@Z
// EA  : 0x82C53E50
// RVA : 0x00C53E50
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

void __fastcall idGameChallenge::GetScoringData(
        idGameChallenge *this,
        const idGameChallenge::playerData_t *data,
        int *playerScore,
        int *playerPosition,
        int *otherScore,
        int *otherIndex)
{
  idGameLocal *v11; // r10
  int v13; // r27
  int v14; // r30
  idGameChallenge::playerData_t *v15; // r11
  int v16; // r11
  int v17; // r8
  idPlayer *v18; // r3
  int v19; // r3

  *playerScore = data->score;
  *playerPosition = 1;
  *otherScore = 0x80000000;
  *otherIndex = -1;
  v11 = gameLocal;
  if ( gameLocal->spawnIds.ptr[data->player.spawnId.value & 0x1FFF] == data->player.spawnId.value >> 13 )
  {
    v13 = 0;
    if ( this->players.num > 0 )
    {
      v14 = 0;
      do
      {
        v15 = &this->players.list[v14];
        if ( v15 != data )
        {
          v17 = v15->player.spawnId.value >> 13;
          v16 = v15->player.spawnId.value & 0x1FFF;
          if ( v11->spawnIds.ptr[v16] == v17 )
          {
            v18 = (idPlayer *)v11->entities.ptr[v16];
            if ( v18 != nullptr )
            {
              if ( idPlayer::CastTo(c: v18) != nullptr )
              {
                v19 = this->GetPlayerScore(this, a2: &this->players.list[v14]);
                if ( v19 > *otherScore )
                {
                  *otherScore = v19;
                  *otherIndex = v13;
                }
                if ( v19 > *playerScore )
                  ++*playerPosition;
              }
              v11 = gameLocal;
            }
          }
        }
        ++v13;
        ++v14;
      }
      while ( v13 < this->players.num );
    }
  }
}


// ========================================================================
// ?PostStatsToLeaderboard@idGameChallenge@@MAAXXZ
// EA  : 0x82C53F88
// RVA : 0x00C53F88
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

void __fastcall idGameChallenge::PostStatsToLeaderboard(idGameChallenge *this)
{
  const leaderboardDefinition_t *v2; // r19
  int v3; // r21
  int v4; // r20
  idGameChallenge::playerData_t *v5; // r26
  idPlayer *v6; // r3
  idPlayer *v7; // r3
  idPlayer *v8; // r25
  int entityNumber; // r23
  BOOL v10; // r9
  idGameChallenge_vtbl *v11; // r11
  int v12; // r3
  int v13; // r27
  int v14; // r30
  idLobbyBase *v15; // r29
  idPlayer *v16; // r3
  idPlayer *v17; // r3
  idPresentable *presentable; // r3
  lobbyUserID_t *v19; // r4
  idLobbyBase_vtbl *v20; // r31
  idPresentablePlayer *LobbyUserID; // r3
  __int128 v22; // r5
  __int64 v23; // r7
  idPresentable *v24; // r3
  lobbyUserID_t *v25; // r4
  idSession_vtbl *v26; // r30
  idPresentablePlayer *v27; // r3
  int RelativeScore; // r30
  int team; // r29
  idPresentable *v30; // r3
  lobbyUserID_t *v31; // r4
  idSession_vtbl *v32; // r31
  idPresentablePlayer *v33; // r3
  char v34; // [sp+50h] [-B0h] BYREF
  char v35; // [sp+58h] [-A8h] BYREF
  char v36; // [sp+60h] [-A0h] BYREF
  _QWORD v37[18]; // [sp+70h] [-90h] BYREF

  if ( this->gameMode != CHALLENGE_MODE_COOP )
  {
    v2 = this->GetLeaderboard(this);
    if ( v2 != nullptr )
    {
      v3 = 0;
      if ( this->players.num > 0 )
      {
        v4 = 0;
        do
        {
          v5 = &this->players.list[v4];
          if ( gameLocal->spawnIds.ptr[v5->player.spawnId.value & 0x1FFF] == v5->player.spawnId.value >> 13 )
          {
            v6 = (idPlayer *)gameLocal->entities.ptr[v5->player.spawnId.value & 0x1FFF];
            if ( v6 != nullptr && idPlayer::CastTo(c: v6) != nullptr )
            {
              if ( gameLocal->spawnIds.ptr[v5->player.spawnId.value & 0x1FFF] == v5->player.spawnId.value >> 13
                && (v7 = (idPlayer *)gameLocal->entities.ptr[v5->player.spawnId.value & 0x1FFF]) != nullptr )
              {
                v8 = idPlayer::CastTo(c: v7);
              }
              else
              {
                v8 = nullptr;
              }
              entityNumber = v8->entityNumber;
              v10 = this->IsTeamGame(this);
              v11 = this->__vftable;
              if ( v10 )
                v12 = v11->GetTeamScore(this, a2: v5->team);
              else
                v12 = v11->GetPlayerScore(this, a2: v5);
              v13 = v12;
              v14 = this->GetSecondaryLeaderboardStat(this, a2: entityNumber);
              v15 = session->GetActivePlatformLobbyBase(this: session);
              if ( gameLocal->spawnIds.ptr[v5->player.spawnId.value & 0x1FFF] == v5->player.spawnId.value >> 13
                && (v16 = (idPlayer *)gameLocal->entities.ptr[v5->player.spawnId.value & 0x1FFF]) != nullptr )
              {
                v17 = idPlayer::CastTo(c: v16);
              }
              else
              {
                v17 = nullptr;
              }
              presentable = v17->presentable;
              if ( presentable != nullptr )
                v19 = (lobbyUserID_t *)presentable->GetPlayerInterface_2(this: presentable);
              else
                v19 = nullptr;
              v20 = v15->__vftable;
              LobbyUserID = idPresentablePlayer::GetLobbyUserID(this: (idPresentablePlayer *)&v34, result: v19);
              DWORD1(v22) = v20->GetLobbyUserEmblemOrdinal(
                              this: (idLobbyBase *)LobbyUserID->__vftable,
                              a2: *((lobbyUserID_t **)&LobbyUserID->__vftable + 1));
              LODWORD(v23) = DWORD1(v22);
              HIDWORD(v23) = __CFADD__(v14, 0x80000000) ? 0 : v14;
              LODWORD(v22) = __CFADD__(v13, 0x80000000) ? 0 : v13;
              v37[2] = v23;
              DWORD2(v22) = HIDWORD(v23);
              v37[0] = v22;
              v37[1] = *(_QWORD *)((char *)&v22 + 4);
              v24 = v8->presentable;
              if ( v24 != nullptr )
                v25 = (lobbyUserID_t *)v24->GetPlayerInterface_2(this: v24);
              else
                v25 = nullptr;
              v26 = session->__vftable;
              v27 = idPresentablePlayer::GetLobbyUserID(this: (idPresentablePlayer *)&v35, result: v25);
              v26->LeaderboardUpload(
                this: (idSession *)v27->__vftable,
                a2: *((lobbyUserID_t **)&v27->__vftable + 1),
                a3: v2,
                a4: (const column_t *)v37,
                a5: nullptr);
              RelativeScore = idGameChallenge::GenerateRelativeScore(
                                this,
                                myIndex: v3,
                                myScore: __CFADD__(v13, 0x80000000) ? 0 : v13);
              if ( this->IsTeamGame(this) )
                team = v5->team;
              else
                team = entityNumber;
              v30 = v8->presentable;
              if ( v30 != nullptr )
                v31 = (lobbyUserID_t *)v30->GetPlayerInterface_2(this: v30);
              else
                v31 = nullptr;
              v32 = session->__vftable;
              v33 = idPresentablePlayer::GetLobbyUserID(this: (idPresentablePlayer *)&v36, result: v31);
              v32->SetLobbyUserRelativeScore(
                this: (idSession *)v33->__vftable,
                a2: *((lobbyUserID_t **)&v33->__vftable + 1),
                a3: RelativeScore,
                a4: team);
            }
          }
          ++v3;
          ++v4;
        }
        while ( v3 < this->players.num );
      }
      session->LeaderboardFlush(this: session);
    }
    else
    {
      idLib::Warning(fmt: "No leaderboard for gameMode %s - not submitting scores. ", this->name.data);
    }
  }
}


// ========================================================================
// ?IsSpawnpointValid@idGameChallenge@@IBA_NPAUspawnPoint_t@1@ABVidBounds@@PBVidEntity@@PAVidClipModel@@@Z
// EA  : 0x82C54310
// RVA : 0x00C54310
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

int __fastcall idGameChallenge::IsSpawnpointValid(
        idGameChallenge *this,
        idGameChallenge::spawnPoint_t *sp,
        const idBounds *playerBounds,
        idGameChallenge *entityToSpawn,
        idClipModel *clipModel)
{
  idEntity *v10; // r3
  char *v11; // r10
  _DWORD *p_z; // r11
  int i; // ctr
  int v14; // r11
  int v15; // r7
  idEntity *v16; // r3
  idEntity *v17; // r3
  idPhysics *Physics; // r3
  int v19; // r3
  float v20; // r6
  float v21; // r5
  float v22; // r3
  int value; // r9
  int v24; // r11
  idEntity *v25; // r3
  idEntity *v26; // r3
  idPhysics *v27; // r3
  int v28; // r3
  char *v29; // r10
  _DWORD *v30; // r11
  int j; // ctr
  int EntitiesTouchingBounds; // r28
  int v33; // r29
  int *v34; // r30
  int v35; // r9
  idGameChallenge *v36; // r31
  idEntity *v37; // r3
  const char *v39; // [sp+8h] [-598h]
  int v40; // [sp+Ch] [-594h]
  int v41; // [sp+10h] [-590h]
  int v42; // [sp+14h] [-58Ch]
  int v43; // [sp+18h] [-588h]
  int v44; // [sp+1Ch] [-584h]
  int v45; // [sp+20h] [-580h]
  int v46; // [sp+24h] [-57Ch]
  int v47; // [sp+28h] [-578h]
  int v48; // [sp+2Ch] [-574h]
  int v49; // [sp+30h] [-570h]
  int v50; // [sp+34h] [-56Ch]
  int v51; // [sp+38h] [-568h]
  int v52; // [sp+3Ch] [-564h]
  int v53; // [sp+40h] [-560h]
  int v54; // [sp+44h] [-55Ch]
  int v55; // [sp+48h] [-558h]
  int v56; // [sp+4Ch] [-554h]
  int v57; // [sp+50h] [-550h]
  char v58; // [sp+5Ch] [-544h] BYREF
  idBounds v59; // [sp+60h] [-540h] BYREF
  idVec3 v60; // [sp+78h] [-528h] BYREF
  char v61; // [sp+88h] [-518h] BYREF
  char v62; // [sp+8Ch] [-514h] BYREF
  idMat3 v63; // [sp+90h] [-510h] BYREF
  trace_t v64; // [sp+C0h] [-4E0h] BYREF
  int v65[280]; // [sp+140h] [-460h] BYREF

  if ( sp == nullptr )
    return 0;
  if ( gameLocal->spawnIds.ptr[sp->entity.spawnId.value & 0x1FFF] != sp->entity.spawnId.value >> 13 )
    return 0;
  v10 = gameLocal->entities.ptr[sp->entity.spawnId.value & 0x1FFF];
  if ( v10 == nullptr || idEntity::CastTo(c: v10) == nullptr )
    return 0;
  v11 = &v58;
  p_z = (_DWORD *)&playerBounds[-1].b[1].z;
  for ( i = 6; i != 0; --i )
  {
    ++p_z;
    v11 += 4;
    *(_DWORD *)v11 = *p_z;
  }
  v14 = sp->entity.spawnId.value & 0x1FFF;
  v15 = sp->entity.spawnId.value >> 13;
  v59.b[0].x = v59.b[0].x - (float)1.0;
  v59.b[0].y = v59.b[0].y - (float)1.0;
  v59.b[0].z = v59.b[0].z - (float)1.0;
  v59.b[1].x = v59.b[1].x + (float)1.0;
  v59.b[1].y = v59.b[1].y + (float)1.0;
  v59.b[1].z = v59.b[1].z + (float)1.0;
  if ( gameLocal->spawnIds.ptr[v14] == v15 && (v16 = gameLocal->entities.ptr[v14]) != nullptr )
    v17 = idEntity::CastTo(c: v16);
  else
    v17 = nullptr;
  Physics = idEntity::GetPhysics(this: v17);
  v19 = (int)Physics->GetOrigin(this: Physics, a2: 0);
  v20 = *(float *)v19;
  v21 = *(float *)(v19 + 8);
  v22 = *(float *)(v19 + 4);
  value = sp->entity.spawnId.value;
  v24 = sp->entity.spawnId.value & 0x1FFF;
  v60.x = v20;
  v60.z = v21;
  v60.y = v22;
  if ( gameLocal->spawnIds.ptr[v24] == value >> 13 && (v25 = gameLocal->entities.ptr[v24]) != nullptr )
    v26 = idEntity::CastTo(c: v25);
  else
    v26 = nullptr;
  v27 = idEntity::GetPhysics(this: v26);
  v28 = (int)v27->GetAxis(this: v27, a2: 0);
  v29 = &v62;
  v30 = (_DWORD *)(v28 - 4);
  for ( j = 9; j != 0; --j )
  {
    ++v30;
    v29 += 4;
    *(_DWORD *)v29 = *v30;
  }
  v59.b[0].x = v60.x + v59.b[0].x;
  v59.b[0].y = v60.y + v59.b[0].y;
  v59.b[0].z = v60.z + v59.b[0].z;
  v59.b[1].x = v59.b[1].x + v60.x;
  v59.b[1].y = v59.b[1].y + v60.y;
  v59.b[1].z = v59.b[1].z + v60.z;
  EntitiesTouchingBounds = idClip::GetEntitiesTouchingBounds(
                             this: &clientGame->clip,
                             bounds: &v59,
                             clipMask: -1,
                             entityList: v65,
                             maxCount: 256);
  v33 = 0;
  if ( EntitiesTouchingBounds <= 0 )
  {
LABEL_27:
    if ( !this->checkWorldCollisionOnSpawn )
      return 1;
    if ( clipModel == nullptr )
      return 1;
    idClip::Contents(
      this: (idClip *)&v61,
      result: &clientGame->clip,
      a3: &v64,
      start: &v60,
      clipModel,
      startAxis: &v63,
      clipMask: 65537,
      passEntityNumber: 0x1FFF,
      userName: v39,
      a10: v40,
      a11: v41,
      a12: v42,
      a13: v43,
      a14: v44,
      a15: v45,
      a16: v46,
      a17: v47,
      a18: v48,
      a19: v49,
      a20: v50,
      a21: v51,
      a22: v52,
      a23: v53,
      a24: v54,
      a25: v55,
      a26: v56,
      a27: v57,
      a28: 0);
    if ( v64.c.contentFlags == 0 )
      return 1;
    v37 = idEntityPtr<idEntity const>::operator->(this: &sp->entity);
    idLib::Warning(fmt: "GameChallenge Spawnpoint: object %s hit world. flags: %d", v37->name.data, v64.c.contentFlags);
    return 0;
  }
  v34 = v65;
  while ( 1 )
  {
    v35 = *v34 + 21563;
    v36 = *((idGameChallenge **)&gameLocal->__vftable + v35);
    if ( v36 != this
      && (unsigned __int8)idStaticEntity::IsTypeOf(c: *((idClass **)&gameLocal->__vftable + v35)) == 0
      && (unsigned __int8)idTrigger::IsTypeOf(c: &v36->idEntity) == 0
      && (unsigned __int8)idVolume::IsTypeOf(c: &v36->idEntity) == 0
      && (unsigned __int8)idDynamicEntity::IsTypeOf(c: &v36->idEntity) == 0
      && (entityToSpawn == nullptr || entityToSpawn != v36) )
    {
      break;
    }
    ++v33;
    ++v34;
    if ( v33 >= EntitiesTouchingBounds )
      goto LABEL_27;
  }
  idLib::Warning(fmt: "GameChallenge Spawnpoint: object %s found in spawn location.", v36->name.data);
  return 0;
}


// ========================================================================
// ?DidPlayerWin@idGameChallenge@@UBA_NH@Z
// EA  : 0x82C54698
// RVA : 0x00C54698
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

int __fastcall idGameChallenge::DidPlayerWin(idGameChallenge *this, int playerEntityId)
{
  int v4; // r28
  int v5; // r29
  idGameLocal *v6; // r9
  idGameChallenge::playerData_t *v7; // r30
  idPlayer *v8; // r3
  idPlayer *v9; // r3
  int result; // r3
  BOOL v11; // r9
  idGameChallenge_vtbl *v12; // r11
  int v13; // r3
  bool v14; // zf

  v4 = 0;
  if ( this->players.num <= 0 )
    return 0;
  v5 = 0;
  v6 = gameLocal;
  while ( 1 )
  {
    v7 = &this->players.list[v5];
    if ( v6->spawnIds.ptr[v7->player.spawnId.value & 0x1FFF] == v7->player.spawnId.value >> 13 )
    {
      v8 = (idPlayer *)v6->entities.ptr[v7->player.spawnId.value & 0x1FFF];
      if ( v8 != nullptr )
      {
        v9 = idPlayer::CastTo(c: v8);
        v6 = gameLocal;
      }
      else
      {
        v9 = nullptr;
      }
      if ( playerEntityId == v9->entityNumber )
        break;
    }
    ++v4;
    ++v5;
    if ( v4 >= this->players.num )
      return 0;
  }
  v11 = this->IsTeamGame(this);
  v12 = this->__vftable;
  v13 = v11 ? v12->GetTeamScore(this, a2: v7->team) : v12->GetPlayerScore(this, a2: v7);
  v14 = v13 == this->GetHighScore(this);
  result = 1;
  if ( !v14 )
    return 0;
  return result;
}


// ========================================================================
// ?GivePVPUnlockItems@idGameChallenge@@IAA_NPBVidDeclVehicleUnlock@@AAUplayerData_t@1@@Z
// EA  : 0x82C547D0
// RVA : 0x00C547D0
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

int __fastcall idGameChallenge::GivePVPUnlockItems(
        idGameChallenge *this,
        const idDeclVehicleUnlock *unlockDecl,
        idGameChallenge::playerData_t *data)
{
  idPlayer *v5; // r3
  idGameLocal *v6; // r11
  idPlayer *v7; // r3
  idPlayer *v8; // r3
  idEntity *v9; // r31
  idPlayer *v10; // r3
  idPlayer *v11; // r3
  int v12; // r3
  idList<idDeclVehicleUnlock::inventoryUnlock_t,5> *p_items; // r26
  int v14; // r24
  int v15; // r27
  idDeclVehicleUnlock::inventoryUnlock_t *v16; // r28
  const idDeclJob *InventoryDecl; // r30
  idJobManager *v18; // r3
  idInventoryItem *JobByDecl; // r29
  idPresentable *v20; // r29
  int v21; // r28
  idInventoryCollection *v22; // r3
  idPresentable *presentable; // r30
  int count; // r28
  idInventoryCollection *v25; // r3

  if ( gameLocal->spawnIds.ptr[data->player.spawnId.value & 0x1FFF] != data->player.spawnId.value >> 13 )
    return 0;
  v5 = (idPlayer *)gameLocal->entities.ptr[data->player.spawnId.value & 0x1FFF];
  if ( v5 == nullptr || idPlayer::CastTo(c: v5) == nullptr )
    return 0;
  v6 = gameLocal;
  if ( gameLocal->spawnIds.ptr[data->player.spawnId.value & 0x1FFF] == data->player.spawnId.value >> 13
    && (v7 = (idPlayer *)gameLocal->entities.ptr[data->player.spawnId.value & 0x1FFF]) != nullptr )
  {
    v8 = idPlayer::CastTo(c: v7);
    v6 = gameLocal;
    v9 = v8;
  }
  else
  {
    v9 = nullptr;
  }
  if ( v6->spawnIds.ptr[data->player.spawnId.value & 0x1FFF] == data->player.spawnId.value >> 13
    && (v10 = (idPlayer *)v6->entities.ptr[data->player.spawnId.value & 0x1FFF]) != nullptr )
  {
    v11 = idPlayer::CastTo(c: v10);
  }
  else
  {
    v11 = nullptr;
  }
  v12 = (int)v11->GetInventory_2(this: v11);
  if ( unlockDecl == nullptr || v9 == nullptr || v12 == 0 )
    return 0;
  p_items = &unlockDecl->items;
  v14 = 0;
  if ( unlockDecl->items.num > 0 )
  {
    v15 = 0;
    do
    {
      v16 = &p_items->list[v15];
      if ( v16->itemType == UNLOCK_ITEM_TYPE_PVP )
      {
        InventoryDecl = (const idDeclJob *)idDeclVehicleUnlock::GetInventoryDecl(unlock: &p_items->list[v15]);
        idLib::Printf(fmt: "GivePVPUnlockItems: slot %s %s\n", unlockDecl->name.str, InventoryDecl->name.str);
        v18 = (idJobManager *)v9->GetInventory_2(this: v9);
        JobByDecl = (idInventoryItem *)idJobManager::FindJobByDecl(this: v18, jobDecl: InventoryDecl);
        if ( JobByDecl != nullptr )
        {
          presentable = v9->presentable;
          if ( presentable == nullptr )
          {
            idEntity::InitPresentableInternal(this: v9);
            presentable = v9->presentable;
          }
          count = v16->count;
          v25 = v9->GetInventory_2(this: v9);
          idInventoryCollection::SetItemCount(this: v25, owner: presentable, item: JobByDecl, count, forceCount: true);
        }
        else
        {
          v20 = v9->presentable;
          if ( v20 == nullptr )
          {
            idEntity::InitPresentableInternal(this: v9);
            v20 = v9->presentable;
          }
          v21 = v16->count;
          v22 = v9->GetInventory_2(this: v9);
          idInventoryCollection::GiveItem(
            this: v22,
            owner: v20,
            decl: (const idDeclInventory *)InventoryDecl,
            count: v21,
            forceCount: false,
            canIntro: false);
        }
      }
      ++v14;
      ++v15;
    }
    while ( v14 < unlockDecl->items.num );
  }
  return 1;
}


// ========================================================================
// ?GivePVPUnlockItemsForSlot@idGameChallenge@@QAAXAAUplayerData_t@1@H@Z
// EA  : 0x82C54A18
// RVA : 0x00C54A18
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

void __fastcall idGameChallenge::GivePVPUnlockItemsForSlot(
        idGameChallenge *this,
        idGameChallenge::playerData_t *data,
        unsigned int slot)
{
  idPlayer *v6; // r3
  const idDeclVehicleUnlock *VehicleUnlockForSlot; // r30
  idLobbyBase *v8; // r29
  const char *str; // r27
  idPresentable *presentable; // r3
  lobbyUserID_t *v11; // r4
  idLobbyBase_vtbl *v12; // r28
  idPresentablePlayer *LobbyUserID; // r3
  const char *v14; // r3
  int entityNumber; // r29
  char v16; // [sp+50h] [-50h] BYREF

  if ( gameLocal->spawnIds.ptr[data->player.spawnId.value & 0x1FFF] == data->player.spawnId.value >> 13 )
  {
    v6 = (idPlayer *)gameLocal->entities.ptr[data->player.spawnId.value & 0x1FFF];
    if ( v6 != nullptr && idPlayer::CastTo(c: v6) != nullptr && slot <= 5 )
    {
      VehicleUnlockForSlot = idGameChallenge::GetVehicleUnlockForSlot(this, data, slot);
      if ( VehicleUnlockForSlot != nullptr )
      {
        if ( g_onlineDebug.valueInteger != 0 )
        {
          v8 = session->GetActingGameStateLobbyBase(this: session);
          str = VehicleUnlockForSlot->name.str;
          presentable = idEntityPtr<idPlayer>::operator->(this: &data->player)->presentable;
          if ( presentable != nullptr )
            v11 = (lobbyUserID_t *)presentable->GetPlayerInterface_2(this: presentable);
          else
            v11 = nullptr;
          v12 = v8->__vftable;
          LobbyUserID = idPresentablePlayer::GetLobbyUserID(this: (idPresentablePlayer *)&v16, result: v11);
          v14 = v12->GetLobbyUserName(
                  this: (idLobbyBase *)LobbyUserID->__vftable,
                  a2: *((lobbyUserID_t **)&LobbyUserID->__vftable + 1));
          idLib::Printf(fmt: "-= Equipping [ %s ] with unlock [ %s ]\n", v14, str);
        }
        entityNumber = idEntityPtr<idPlayer>::operator->(this: &data->player)->entityNumber;
        if ( idGameChallenge::IsVehicleUnlockValid(this, unlockDecl: VehicleUnlockForSlot, data, slot) )
        {
          if ( (unsigned __int8)idGameChallenge::GivePVPUnlockItems(this, unlockDecl: VehicleUnlockForSlot, data) == 0 )
            idLib::Warning(
              fmt: "GivePVPUnlockItemsForSlot failed for player %d, slot %d, unlock %s",
              entityNumber,
              slot,
              data->loadoutSlot[slot]->name.str);
        }
        else
        {
          idLib::Warning(
            fmt: "GivePVPUnlockItemsForSlot : Unlock [ %s ] is not valid for player %d!",
            VehicleUnlockForSlot->name.str,
            entityNumber);
        }
      }
    }
  }
}


// ========================================================================
// ?LoadMultiplayerDecls@idGameChallenge@@MAAXXZ
// EA  : 0x82C54BD8
// RVA : 0x00C54BD8
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

void __fastcall idGameChallenge::LoadMultiplayerDecls(idGameChallenge *this)
{
  challengeGameMode_t gameMode; // r11
  int v2; // r26
  int v3; // r27
  const char *str; // r4
  const idDecl *v5; // r3
  idResource **p_nextOnHashChain; // r30
  int v7; // r29
  int v8; // r31

  gameMode = this->gameMode;
  if ( (unsigned int)gameMode >= CHALLENGE_MODE_DM
    && gameMode != CHALLENGE_MODE_MAX
    && (unsigned int)idLib::production <= PROD_BUILDING )
  {
    v2 = 0;
    if ( idDeclVehicleUnlock::resourceList.declSources.num > 0 )
    {
      v3 = 0;
      do
      {
        str = idDeclVehicleUnlock::resourceList.declSources.list[v3]->name.str;
        if ( str != nullptr )
          v5 = idDeclInfo::FindWithInheritance(this: &idDeclVehicleUnlock::resourceList, name: str, makeDefault: false);
        else
          v5 = nullptr;
        p_nextOnHashChain = &v5[2].nextOnHashChain;
        v7 = 0;
        if ( (int)v5[2].resourceListPtr > 0 )
        {
          v8 = 0;
          do
          {
            idDeclVehicleUnlock::GetEntityDef(unlock: (const idDeclVehicleUnlock::inventoryUnlock_t *)&(*p_nextOnHashChain)[v8]);
            idDeclVehicleUnlock::GetInventoryDecl(unlock: (const idDeclVehicleUnlock::inventoryUnlock_t *)&(*p_nextOnHashChain)[v8]);
            idDeclVehicleUnlock::GetSoundShader(unlock: (const idDeclVehicleUnlock::inventoryUnlock_t *)&(*p_nextOnHashChain)[v8]);
            ++v7;
            v8 += 3;
          }
          while ( v7 < (int)p_nextOnHashChain[1] );
        }
        ++v2;
        ++v3;
      }
      while ( v2 < idDeclVehicleUnlock::resourceList.declSources.num );
    }
  }
}


// ========================================================================
// ?LogStatKillDeath@idGameChallenge@@QAAXHH@Z
// EA  : 0x82C54CC8
// RVA : 0x00C54CC8
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

void __fastcall idGameChallenge::LogStatKillDeath(
        idGameChallenge *this,
        unsigned int attackingPlayerEntityNumber,
        unsigned int victimPlayerEntityNumber)
{
  idGameChallenge::playerData_t *PlayerData; // r3
  idGameChallenge::playerData_t *v7; // r28
  idGameChallenge::playerData_t *v8; // r3

  if ( this->CanScore(this) )
  {
    PlayerData = idGameChallenge::GetPlayerData(this, playerEntityNumber: victimPlayerEntityNumber);
    v7 = PlayerData;
    if ( PlayerData != nullptr )
      PlayerData->lastKiller = attackingPlayerEntityNumber;
    v8 = idGameChallenge::GetPlayerData(this, playerEntityNumber: attackingPlayerEntityNumber);
    if ( v8 != nullptr && v7 != nullptr )
    {
      if ( v8->lastKiller == victimPlayerEntityNumber )
      {
        v8->lastKiller = -1;
        idRageMetrics::Revenge(
          this: clientGame->rageMetrics,
          victimNum: victimPlayerEntityNumber,
          killerNum: attackingPlayerEntityNumber);
        idGameLocal::BroadcastUIStatusMessage(
          this: gameLocal,
          type: 24,
          numParams: 1,
          param1: attackingPlayerEntityNumber,
          param2: -1,
          param3: -1,
          param4: -1);
      }
      this->IsTeamGame(this);
    }
  }
}


// ========================================================================
// ?DebugAllSpawnPoints@idGameChallenge@@UAAXXZ
// EA  : 0x82C54DA8
// RVA : 0x00C54DA8
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

void __fastcall idGameChallenge::DebugAllSpawnPoints(idGameChallenge *this)
{
  idGameChallenge::playerData_t *list; // r31
  idPlayer *v3; // r3
  idPlayer *v4; // r3
  idPlayer *v5; // r3
  idPhysics *Physics; // r3
  float *v7; // r3
  idPlayer *v8; // r3
  idPlayer *v9; // r3
  idPhysics *v10; // r3
  idClipModel *v11; // r17
  int v12; // r25
  int v13; // r20
  idGameChallenge::spawnPoint_t *v14; // r30
  idEntity *v15; // r3
  char IsSpawnpointValid; // r3
  int v17; // r11
  int v18; // r8
  int v19; // r5
  idEntity *v20; // r3
  idEntity *v21; // r11
  idEntity *v22; // r3
  idEntity *v23; // r3
  idPhysics *v24; // r31
  idEntity *v25; // r3
  idEntity *v26; // r3
  idPhysics *v27; // r3
  int v28; // r16
  idPhysics *v29; // r3
  idRenderWorld *renderWorld; // r31
  const idMat3 *(__fastcall *GetAxis)(idPhysics *, int); // ctr
  idRenderWorld_vtbl *v32; // r15
  int v33; // r3
  double v34; // fp30
  double v35; // fp29
  double v36; // fp28
  idEntity *v37; // r3
  idEntity *v38; // r3
  idPhysics *v39; // r3
  float *v40; // r3
  double v41; // fp10
  double v42; // fp9
  idEntity *v43; // r3
  idEntity *v44; // r3
  idEntity *v45; // r3
  idEntity *v46; // r11
  idEntity *v47; // r3
  idEntity *v48; // r3
  idPhysics *v49; // r31
  idEntity *v50; // r3
  idEntity *v51; // r3
  idPhysics *v52; // r3
  int v53; // r16
  idPhysics *v54; // r3
  idRenderWorld *v55; // r31
  const idMat3 *(__fastcall *v56)(idPhysics *, int); // ctr
  idRenderWorld_vtbl *v57; // r15
  int v58; // r3
  double v59; // fp30
  double v60; // fp29
  double v61; // fp28
  idEntity *v62; // r3
  idEntity *v63; // r3
  idPhysics *v64; // r3
  float *v65; // r3
  double v66; // fp10
  double v67; // fp9
  idEntity *v68; // r3
  idEntity *v69; // r3
  float v70[4]; // [sp+60h] [-F0h] BYREF
  float v71[4]; // [sp+70h] [-E0h] BYREF
  idBounds v72[2]; // [sp+80h] [-D0h] BYREF

  list = this->players.list;
  if ( gameLocal->spawnIds.ptr[list->player.spawnId.value & 0x1FFF] == list->player.spawnId.value >> 13
    && (v3 = (idPlayer *)gameLocal->entities.ptr[list->player.spawnId.value & 0x1FFF]) != nullptr
    && idPlayer::CastTo(c: v3) != nullptr )
  {
    if ( gameLocal->spawnIds.ptr[list->player.spawnId.value & 0x1FFF] == list->player.spawnId.value >> 13
      && (v4 = (idPlayer *)gameLocal->entities.ptr[list->player.spawnId.value & 0x1FFF]) != nullptr )
    {
      v5 = idPlayer::CastTo(c: v4);
    }
    else
    {
      v5 = nullptr;
    }
    Physics = idEntity::GetPhysics(this: v5);
    v7 = (float *)Physics->GetBounds(this: Physics, a2: -1);
    v72[0].b[0].x = *v7;
    v72[0].b[0].y = v7[1];
    v72[0].b[0].z = v7[2];
    v72[0].b[1].x = v7[3];
    v72[0].b[1].y = v7[4];
    v72[0].b[1].z = v7[5];
    if ( gameLocal->spawnIds.ptr[list->player.spawnId.value & 0x1FFF] == list->player.spawnId.value >> 13
      && (v8 = (idPlayer *)gameLocal->entities.ptr[list->player.spawnId.value & 0x1FFF]) != nullptr )
    {
      v9 = idPlayer::CastTo(c: v8);
    }
    else
    {
      v9 = nullptr;
    }
    v10 = idEntity::GetPhysics(this: v9);
    v11 = v10->GetClipModel(this: v10, a2: 0);
    if ( this->spawnPoints.num > 0 )
    {
      v12 = 0;
      this->checkWorldCollisionOnSpawn = true;
      v13 = 0;
      do
      {
        v14 = &this->spawnPoints.list[v13];
        if ( gameLocal->spawnIds.ptr[v14->entity.spawnId.value & 0x1FFF] == v14->entity.spawnId.value >> 13
          && (v15 = gameLocal->entities.ptr[v14->entity.spawnId.value & 0x1FFF]) != nullptr
          && idEntity::CastTo(c: v15) != nullptr )
        {
          IsSpawnpointValid = idGameChallenge::IsSpawnpointValid(
                                this,
                                sp: v14,
                                playerBounds: v72,
                                entityToSpawn: nullptr,
                                clipModel: v11);
          v17 = v14->entity.spawnId.value & 0x1FFF;
          v18 = v14->entity.spawnId.value >> 13;
          v19 = gameLocal->spawnIds.ptr[v17];
          if ( IsSpawnpointValid != 0 )
          {
            if ( v19 == v18 && (v20 = gameLocal->entities.ptr[v17]) != nullptr )
              v21 = idEntity::CastTo(c: v20);
            else
              v21 = nullptr;
            idLib::Printf(fmt: "Spawn point[%d] %s - Passed \n", v12, v21->name.data);
            if ( gameLocal->spawnIds.ptr[v14->entity.spawnId.value & 0x1FFF] == v14->entity.spawnId.value >> 13
              && (v22 = gameLocal->entities.ptr[v14->entity.spawnId.value & 0x1FFF]) != nullptr )
            {
              v23 = idEntity::CastTo(c: v22);
            }
            else
            {
              v23 = nullptr;
            }
            v24 = idEntity::GetPhysics(this: v23);
            if ( gameLocal->spawnIds.ptr[v14->entity.spawnId.value & 0x1FFF] == v14->entity.spawnId.value >> 13
              && (v25 = gameLocal->entities.ptr[v14->entity.spawnId.value & 0x1FFF]) != nullptr )
            {
              v26 = idEntity::CastTo(c: v25);
            }
            else
            {
              v26 = nullptr;
            }
            v27 = idEntity::GetPhysics(this: v26);
            v28 = (int)v27->GetOrigin(this: v27, a2: 0);
            v29 = v24;
            GetAxis = v24->GetAxis;
            renderWorld = clientGame->renderWorld;
            v32 = renderWorld->__vftable;
            v33 = (int)GetAxis(this: v29, a2: 0);
            v32->DebugOrientedBounds(
              this: renderWorld,
              a2: (const idVec4 *)&idColor::colorGreen,
              a3: v72,
              a4: (const idVec3 *)v28,
              a5: (const idMat3 *)v33,
              a6: 30000,
              a7: false);
            v34 = (float)(vec3_up.x * (float)50.0);
            v35 = (float)(vec3_up.y * (float)50.0);
            v36 = (float)(vec3_up.z * (float)50.0);
            if ( gameLocal->spawnIds.ptr[v14->entity.spawnId.value & 0x1FFF] == v14->entity.spawnId.value >> 13
              && (v37 = gameLocal->entities.ptr[v14->entity.spawnId.value & 0x1FFF]) != nullptr )
            {
              v38 = idEntity::CastTo(c: v37);
            }
            else
            {
              v38 = nullptr;
            }
            v39 = idEntity::GetPhysics(this: v38);
            v40 = (float *)v39->GetOrigin(this: v39, a2: 0);
            v41 = (float)(v40[1] + (float)v35);
            v42 = (float)((float)v34 + *v40);
            v70[2] = v40[2] + (float)v36;
            v70[0] = v42;
            v70[1] = v41;
            if ( gameLocal->spawnIds.ptr[v14->entity.spawnId.value & 0x1FFF] == v14->entity.spawnId.value >> 13
              && (v43 = gameLocal->entities.ptr[v14->entity.spawnId.value & 0x1FFF]) != nullptr )
            {
              v44 = idEntity::CastTo(c: v43);
            }
            else
            {
              v44 = nullptr;
            }
            ((void (__fastcall *)(idRenderWorld *, char *, float *, void (__fastcall *)(idRenderWorld *, const char *, const idVec3 *, float, const idVec4 *, const int, const int, const bool, const bool), idColor *, int, int, _DWORD, double))clientGame->renderWorld->DebugText)(
              a1: clientGame->renderWorld,
              a2: v44->name.data,
              a3: v70,
              a4: clientGame->renderWorld->DebugText,
              a5: &idColor::colorGreen,
              a6: 1,
              a7: 30000,
              a8: 0,
              a9: 0.2);
          }
          else
          {
            if ( v19 == v18 && (v45 = gameLocal->entities.ptr[v17]) != nullptr )
              v46 = idEntity::CastTo(c: v45);
            else
              v46 = nullptr;
            idLib::Printf(fmt: "Spawn point[%d] %s - FAILED \n", v12, v46->name.data);
            if ( gameLocal->spawnIds.ptr[v14->entity.spawnId.value & 0x1FFF] == v14->entity.spawnId.value >> 13
              && (v47 = gameLocal->entities.ptr[v14->entity.spawnId.value & 0x1FFF]) != nullptr )
            {
              v48 = idEntity::CastTo(c: v47);
            }
            else
            {
              v48 = nullptr;
            }
            v49 = idEntity::GetPhysics(this: v48);
            if ( gameLocal->spawnIds.ptr[v14->entity.spawnId.value & 0x1FFF] == v14->entity.spawnId.value >> 13
              && (v50 = gameLocal->entities.ptr[v14->entity.spawnId.value & 0x1FFF]) != nullptr )
            {
              v51 = idEntity::CastTo(c: v50);
            }
            else
            {
              v51 = nullptr;
            }
            v52 = idEntity::GetPhysics(this: v51);
            v53 = (int)v52->GetOrigin(this: v52, a2: 0);
            v54 = v49;
            v56 = v49->GetAxis;
            v55 = clientGame->renderWorld;
            v57 = v55->__vftable;
            v58 = (int)v56(this: v54, a2: 0);
            v57->DebugOrientedBounds(
              this: v55,
              a2: (const idVec4 *)&idColor::colorRed,
              a3: v72,
              a4: (const idVec3 *)v53,
              a5: (const idMat3 *)v58,
              a6: 30000,
              a7: false);
            v59 = (float)(vec3_up.x * (float)50.0);
            v60 = (float)(vec3_up.y * (float)50.0);
            v61 = (float)(vec3_up.z * (float)50.0);
            if ( gameLocal->spawnIds.ptr[v14->entity.spawnId.value & 0x1FFF] == v14->entity.spawnId.value >> 13
              && (v62 = gameLocal->entities.ptr[v14->entity.spawnId.value & 0x1FFF]) != nullptr )
            {
              v63 = idEntity::CastTo(c: v62);
            }
            else
            {
              v63 = nullptr;
            }
            v64 = idEntity::GetPhysics(this: v63);
            v65 = (float *)v64->GetOrigin(this: v64, a2: 0);
            v66 = (float)(v65[2] + (float)v61);
            v67 = (float)((float)v59 + *v65);
            v71[1] = v65[1] + (float)v60;
            v71[2] = v66;
            v71[0] = v67;
            if ( gameLocal->spawnIds.ptr[v14->entity.spawnId.value & 0x1FFF] == v14->entity.spawnId.value >> 13
              && (v68 = gameLocal->entities.ptr[v14->entity.spawnId.value & 0x1FFF]) != nullptr )
            {
              v69 = idEntity::CastTo(c: v68);
            }
            else
            {
              v69 = nullptr;
            }
            ((void (__fastcall *)(idRenderWorld *, char *, float *, void (__fastcall *)(idRenderWorld *, const char *, const idVec3 *, float, const idVec4 *, const int, const int, const bool, const bool), idColor *, int, int, _DWORD, double))clientGame->renderWorld->DebugText)(
              a1: clientGame->renderWorld,
              a2: v69->name.data,
              a3: v71,
              a4: clientGame->renderWorld->DebugText,
              a5: &idColor::colorRed,
              a6: 1,
              a7: 30000,
              a8: 0,
              a9: 0.2);
          }
        }
        else
        {
          idLib::Warning(fmt: "Spawn point[%d] has no valid entity!", v12);
        }
        ++v12;
        ++v13;
      }
      while ( v12 < this->spawnPoints.num );
      this->checkWorldCollisionOnSpawn = false;
    }
    else
    {
      idLib::Printf(fmt: "No spawn points listed in game challenge!  \n");
    }
  }
  else
  {
    idLib::Printf(fmt: "No valid game challenge data to test spawning with! \n");
  }
}


// ========================================================================
// ?BroadcastKillMessage@idGameChallenge@@UAAXHHPBVidDeclDamage@@_NHH@Z
// EA  : 0x82C554F8
// RVA : 0x00C554F8
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idGameChallenge::BroadcastKillMessage(
        idGameChallenge *this,
        int attackingPlayerEntityNumber,
        int victimPlayerEntityNumber,
        const idDeclDamage *damageDef,
        bool isTeamKill,
        int xpGained,
        int points,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        const idDecl *a18)
{
  int v21; // r31 OVERLAPPED
  int v23; // r11
  idLobbyBase *v24; // r3
  idSerializer v25; // [sp+50h] [-170h] BYREF
  idBitMsg v26; // [sp+60h] [-160h] BYREF
  _BYTE v27[304]; // [sp+90h] [-130h] BYREF

  a18 = damageDef;
  v21 = 0;
  memset(&v26.curSize, 0, 18);
  v26.writeData = v27;
  v26.readData = v27;
  v26.maxSize = 256;
  v26.tempValue = *(_QWORD *)&v21;
  v25.writing = true;
  v25.msg = &v26;
  idBitMsg::WriteBits(this: &v26, value: attackingPlayerEntityNumber, numBits: 32);
  idBitMsg::WriteBits(this: &v26, value: victimPlayerEntityNumber, numBits: 32);
  idBitMsg::WriteBits(this: &v26, value: xpGained, numBits: 32);
  idBitMsg::WriteBits(this: &v26, value: points, numBits: 32);
  idSerializer::Serialize<idDeclDamage>(this: &v25, decl: &a18);
  if ( v25.writing )
    idBitMsg::WriteBits(this: v25.msg, value: isTeamKill, numBits: 1);
  else
    idBitMsg::ReadBits(this: v25.msg, numBits: 1);
  v26.tempValue = *(_QWORD *)&v21;
  v23 = v26.writeBit != 0;
  v26.writeBit = 0;
  v26.curSize += v23;
  v24 = session->GetActingGameStateLobbyBase(this: session);
  v24->SendReliable(this: v24, a2: 23, a3: &v26, a4: true, a5: 255u);
}


// ========================================================================
// ?AllClientsDisconnected@idGameChallenge@@IBA_NXZ
// EA  : 0x82C55678
// RVA : 0x00C55678
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

int __fastcall idGameChallenge::AllClientsDisconnected(idGameChallenge *this)
{
  int v2; // r27
  int v3; // r30
  idGameLocal *v4; // r11
  idGameChallenge::playerData_t *list; // r31
  idPlayer *v6; // r3
  idPlayer *v7; // r3
  idPresentable *presentable; // r3
  int v9; // r3
  int value; // r9
  idPlayer *v11; // r3

  v2 = 0;
  if ( this->players.num <= 0 )
    return 1;
  v3 = 0;
  v4 = gameLocal;
  while ( 1 )
  {
    list = this->players.list;
    if ( v4->spawnIds.ptr[list[v3].player.spawnId.value & 0x1FFF] == list[v3].player.spawnId.value >> 13 )
      break;
LABEL_15:
    ++v2;
    ++v3;
    if ( v2 >= this->players.num )
      return 1;
  }
  v6 = (idPlayer *)v4->entities.ptr[list[v3].player.spawnId.value & 0x1FFF];
  if ( v6 != nullptr )
    v7 = idPlayer::CastTo(c: v6);
  else
    v7 = nullptr;
  presentable = v7->presentable;
  if ( presentable != nullptr )
    v9 = (int)presentable->GetPlayerInterface_2(this: presentable);
  else
    v9 = 0;
  if ( (*(unsigned __int8 (__fastcall **)(int))(*(_DWORD *)v9 + 300))(a1: v9) == 0 )
  {
    value = list[v3].player.spawnId.value;
    v4 = gameLocal;
    if ( gameLocal->spawnIds.ptr[value & 0x1FFF] != value >> 13 )
      goto LABEL_15;
    v11 = (idPlayer *)gameLocal->entities.ptr[value & 0x1FFF];
    if ( v11 == nullptr )
      goto LABEL_15;
    if ( idPlayer::CastTo(c: v11) != nullptr )
      return 0;
  }
  v4 = gameLocal;
  goto LABEL_15;
}


// ========================================================================
// ?RegisterNewPlayer@idGameChallenge_Coop@@UAA_NAAUplayerData_t@idGameChallenge@@PAVidPlayer@@_N@Z
// EA  : 0x82C557B0
// RVA : 0x00C557B0
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

int __fastcall idGameChallenge_Coop::RegisterNewPlayer(
        idGameChallenge_Coop *this,
        idGameChallenge::playerData_t *data,
        idPlayer *player,
        bool initial)
{
  gameTeam_t v8; // r4
  const idDeclFaction *FactionFromTeam; // r31
  idPlayer *v10; // r3

  if ( (unsigned __int8)idGameChallenge::RegisterNewPlayer(this, data, player, initial) == 0 )
    return 0;
  v8 = this->GetTeamNumber(this, a2: data);
  data->team = v8;
  if ( player != nullptr )
    idEntity::SetTeam(this: player, team: v8);
  FactionFromTeam = idGameChallenge::GetFactionFromTeam(this, team: &data->team);
  if ( FactionFromTeam != nullptr
    && gameLocal->spawnIds.ptr[data->player.spawnId.value & 0x1FFF] == data->player.spawnId.value >> 13 )
  {
    v10 = idEntityPtr<idPlayer>::operator->(this: &data->player);
    idActor::SetFaction(this: v10, faction: FactionFromTeam);
  }
  return 1;
}


// ========================================================================
// ?GameOver@idGameChallenge_Coop@@UAAXXZ
// EA  : 0x82C55878
// RVA : 0x00C55878
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

void __fastcall idGameChallenge_Coop::GameOver(idGameChallenge_Coop *this)
{
  int v2; // r26
  int v3; // r30
  int value; // r9
  idPlayer *v5; // r3
  idPlayer *v6; // r3
  idPlayer *v7; // r31
  idPresentable *presentable; // r3
  float *v9; // r3
  idPresentable *v10; // r3
  int v11; // r3
  int v12; // r30
  idGameLocal *v13; // r11
  int v14; // r31
  int v15; // r9
  idPlayer *v16; // r3

  v2 = 0;
  if ( this->players.num > 0 )
  {
    v3 = 0;
    do
    {
      value = this->players.list[v3].player.spawnId.value;
      if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
      {
        v5 = (idPlayer *)gameLocal->entities.ptr[value & 0x1FFF];
        if ( v5 != nullptr )
        {
          v6 = idPlayer::CastTo(c: v5);
          v7 = v6;
          if ( v6 != nullptr )
          {
            idPlayer::SetForceInhibitControl(this: v6, inhibit: true);
            if ( this->bGameFailed )
            {
              presentable = v7->presentable;
              if ( presentable != nullptr )
                v9 = (float *)presentable->GetPlayerInterface_2(this: presentable);
              else
                v9 = nullptr;
              v9[4767] = 0.0;
              v9[4768] = 0.0;
              v9[4769] = 0.0;
              v9[4770] = 0.0;
              v10 = v7->presentable;
              if ( v10 != nullptr )
              {
                v11 = (int)v10->GetPlayerInterface_2(this: v10);
                idView::Fade(this: (idView *)(v11 + 16224), color: (const idVec4 *)&idColor::colorBlack, time: 10000);
              }
              else
              {
                idView::Fade(this: (idView *)0x3F60, color: (const idVec4 *)&idColor::colorBlack, time: 10000);
              }
            }
            else
            {
              gameLocal->forceSingleView = true;
            }
          }
        }
      }
      ++v2;
      ++v3;
    }
    while ( v2 < this->players.num );
  }
  idGameChallenge_Coop::StopObjective(this, skipResults: this->bGameFailed);
  v12 = 0;
  v13 = gameLocal;
  if ( this->players.num > 0 )
  {
    v14 = 0;
    do
    {
      v15 = this->players.list[v14].player.spawnId.value;
      if ( v13->spawnIds.ptr[v15 & 0x1FFF] == v15 >> 13 )
      {
        v16 = (idPlayer *)v13->entities.ptr[v15 & 0x1FFF];
        if ( v16 != nullptr )
        {
          idPlayer::CastTo(c: v16);
          v13 = gameLocal;
        }
      }
      ++v12;
      ++v14;
    }
    while ( v12 < this->players.num );
  }
  if ( this->bGameFailed )
  {
    idGameLocal::BroadcastUIStatusMessage(
      this: v13,
      type: 16,
      numParams: 0,
      param1: -1,
      param2: -1,
      param3: -1,
      param4: -1);
    v13 = gameLocal;
  }
  v13->challengeState = CHALLENGE_STATE_RESULTS;
  this->endTime = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
}


// ========================================================================
// ?PostStatsToLeaderboard@idGameChallenge_Coop@@MAAXXZ
// EA  : 0x82C55AA0
// RVA : 0x00C55AA0
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

void __fastcall idGameChallenge_Coop::PostStatsToLeaderboard(idGameChallenge_Coop *this)
{
  int v2; // r8
  int v3; // r21
  int v4; // r23
  int v5; // r27
  int value; // r9
  idPlayer *v7; // r3
  int v8; // r9
  idPlayer *v9; // r3
  idPlayer *v10; // r24
  int v11; // r30
  idLobbyBase *v12; // r29
  int v13; // r6
  idPlayer *v14; // r3
  idPlayer *v15; // r3
  idPresentable *presentable; // r3
  lobbyUserID_t *v17; // r4
  idLobbyBase_vtbl *v18; // r31
  idPresentablePlayer *LobbyUserID; // r3
  unsigned int v20; // r3
  __int64 v21; // r8
  __int64 v22; // r6
  idLobbyBase *v23; // r3
  int challengeLeaderboardId; // r31
  char v25; // r11
  idPresentable *v26; // r3
  lobbyUserID_t *v27; // r4
  idSession_vtbl *v28; // r30
  idPresentablePlayer *v29; // r3
  char v30; // [sp+50h] [-90h] BYREF
  char v31; // [sp+58h] [-88h] BYREF
  _QWORD v32[16]; // [sp+60h] [-80h] BYREF

  v2 = this->GetTeamScore_2(this, a2: 0);
  v3 = 0;
  v4 = __CFADD__(v2, 0x80000000) ? 0 : v2;
  if ( this->players.num > 0 )
  {
    v5 = 0;
    do
    {
      value = this->players.list[v5].player.spawnId.value;
      if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
      {
        v7 = (idPlayer *)gameLocal->entities.ptr[value & 0x1FFF];
        if ( v7 != nullptr && idPlayer::CastTo(c: v7) != nullptr )
        {
          v8 = this->players.list[v5].player.spawnId.value;
          if ( gameLocal->spawnIds.ptr[v8 & 0x1FFF] == v8 >> 13
            && (v9 = (idPlayer *)gameLocal->entities.ptr[v8 & 0x1FFF]) != nullptr )
          {
            v10 = idPlayer::CastTo(c: v9);
          }
          else
          {
            v10 = nullptr;
          }
          v11 = this->GetPlayerScore(this, a2: &this->players.list[v5]);
          v12 = session->GetActivePlatformLobbyBase(this: session);
          v13 = this->players.list[v5].player.spawnId.value;
          if ( gameLocal->spawnIds.ptr[v13 & 0x1FFF] == v13 >> 13
            && (v14 = (idPlayer *)gameLocal->entities.ptr[v13 & 0x1FFF]) != nullptr )
          {
            v15 = idPlayer::CastTo(c: v14);
          }
          else
          {
            v15 = nullptr;
          }
          presentable = v15->presentable;
          if ( presentable != nullptr )
            v17 = (lobbyUserID_t *)presentable->GetPlayerInterface_2(this: presentable);
          else
            v17 = nullptr;
          v18 = v12->__vftable;
          LobbyUserID = idPresentablePlayer::GetLobbyUserID(this: (idPresentablePlayer *)&v30, result: v17);
          v20 = (unsigned __int64)((__int64 (__fastcall *)(idPresentablePlayer_vtbl *, _DWORD))v18->GetLobbyUserEmblemOrdinal)(
                                    a1: LobbyUserID->__vftable,
                                    a2: *((_DWORD *)&LobbyUserID->__vftable + 1)) >> 32;
          HIDWORD(v21) = 0x80000000;
          v32[2] = __PAIR64__(v11, v20);
          LODWORD(v22) = v4;
          HIDWORD(v22) = v11 + 0x80000000;
          v32[1] = v22;
          LODWORD(v21) = __CFADD__(v11, 0x80000000) ? 0 : v11;
          v32[0] = v21;
          v23 = session->GetActingGameStateLobbyBase(this: session);
          challengeLeaderboardId = v23->GetMatchParms(this: v23)->challengeLeaderboardId;
          if ( challengeLeaderboardId < 0 )
          {
            idLib::Warning(fmt: "No valid leaderboardID for game challenge %s. Defaulting", this->name.data);
            challengeLeaderboardId = 0;
          }
          if ( gameLocal->GetGameDifficulty(this: gameLocal) == 3 )
            challengeLeaderboardId += 10;
          if ( challengeLeaderboardId < 0 || (v25 = 1, challengeLeaderboardId >= 20) )
            v25 = 0;
          if ( v25 != 0 )
          {
            v26 = v10->presentable;
            if ( v26 != nullptr )
              v27 = (lobbyUserID_t *)v26->GetPlayerInterface_2(this: v26);
            else
              v27 = nullptr;
            v28 = session->__vftable;
            v29 = idPresentablePlayer::GetLobbyUserID(this: (idPresentablePlayer *)&v31, result: v27);
            v28->LeaderboardUpload(
              this: (idSession *)v29->__vftable,
              a2: *((lobbyUserID_t **)&v29->__vftable + 1),
              a3: rageMPCoopLeaderboards[challengeLeaderboardId],
              a4: (const column_t *)v32,
              a5: nullptr);
          }
        }
      }
      ++v3;
      ++v5;
    }
    while ( v3 < this->players.num );
  }
  session->LeaderboardFlush(this: session);
}


// ========================================================================
// ?SetCollectibleFound@idGameChallenge_Coop@@QAAXPAVidProp_OnlineCollectible@@_N@Z
// EA  : 0x82C55DC0
// RVA : 0x00C55DC0
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

void __fastcall idGameChallenge_Coop::SetCollectibleFound(
        idGameChallenge_Coop *this,
        idProp_OnlineCollectible *ent,
        bool found_)
{
  int value; // r10
  unsigned __int64 v7; // r30
  idProp_OnlineCollectible *v8; // r3
  idProp_OnlineCollectible *v9; // r3
  int num; // r11
  int v11; // r22
  int v12; // r27
  int v13; // r9
  idPlayer *v14; // r3
  int v15; // r9
  idPlayer *v16; // r3
  idPlayer *v17; // r3
  int v18; // r11
  idLobbyBase *v19; // r3
  int v20; // r5
  idLobbyBase *v21; // r28
  idPlayer *v22; // r3
  idPlayer *v23; // r3
  idPresentable *v24; // r3
  lobbyUserID_t *v25; // r4
  idLobbyBase_vtbl *v26; // r29
  idPresentablePlayer *v27; // r3
  int v28; // r18
  int v29; // r22
  idEntityPtr<idProp_OnlineCollectible> *p_collectible; // r10
  idProp_OnlineCollectible *v31; // r3
  idProp_OnlineCollectible *v32; // r3
  idGameChallenge_Coop::collectibleData_t *list; // r11
  int v34; // r25
  int v35; // r27
  int v36; // r9
  idPlayer *v37; // r3
  int v38; // r9
  idPlayer *v39; // r3
  idPlayer *v40; // r3
  int entityNumber; // r4
  int NumCollectiblesFound; // r3
  int MaxNumCollectibles; // r3
  idLobbyBase *v44; // r3
  int v45; // r6
  idLobbyBase *v46; // r28
  idPlayer *v47; // r3
  idPlayer *v48; // r3
  idPresentable *presentable; // r3
  lobbyUserID_t *v50; // r4
  idLobbyBase_vtbl *v51; // r29
  idPresentablePlayer *LobbyUserID; // r3
  int v53[2]; // [sp+50h] [-310h] BYREF
  idSerializer v54; // [sp+58h] [-308h] BYREF
  idBitMsg v55; // [sp+60h] [-300h] BYREF
  idBitMsg v56; // [sp+90h] [-2D0h] BYREF
  _BYTE v57[8]; // [sp+B8h] [-2A8h] BYREF
  idStr v58; // [sp+C0h] [-2A0h] BYREF
  _BYTE v59[256]; // [sp+E0h] [-280h] BYREF
  _BYTE v60[384]; // [sp+1E0h] [-180h] BYREF

  if ( ent != nullptr )
  {
    value = this->specialCollectible.collectible.spawnId.value;
    v53[0] = (int)&this->specialCollectible.collectible;
    LODWORD(v7) = 0;
    if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
      && (v8 = (idProp_OnlineCollectible *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
    {
      v9 = idProp_OnlineCollectible::CastTo(c: v8);
    }
    else
    {
      v9 = nullptr;
    }
    if ( v9 != ent || this->specialCollectible.found == found_ )
    {
      v28 = 0;
      if ( this->collectibleList.num > 0 )
      {
        v29 = 0;
        do
        {
          p_collectible = &this->collectibleList.list[v29].collectible;
          if ( gameLocal->spawnIds.ptr[p_collectible->spawnId.value & 0x1FFF] == p_collectible->spawnId.value >> 13
            && (v31 = (idProp_OnlineCollectible *)gameLocal->entities.ptr[p_collectible->spawnId.value & 0x1FFF]) != nullptr )
          {
            v32 = idProp_OnlineCollectible::CastTo(c: v31);
          }
          else
          {
            v32 = nullptr;
          }
          if ( v32 == ent )
          {
            list = this->collectibleList.list;
            if ( list[v29].found != found_ )
            {
              list[v29].found = found_;
              v34 = 0;
              if ( this->players.num > 0 )
              {
                v35 = 0;
                do
                {
                  HIDWORD(v7) = this->players.list;
                  v36 = *(_DWORD *)(HIDWORD(v7) + v35);
                  if ( gameLocal->spawnIds.ptr[v36 & 0x1FFF] == v36 >> 13 )
                  {
                    v37 = (idPlayer *)gameLocal->entities.ptr[v36 & 0x1FFF];
                    if ( v37 != nullptr && idPlayer::CastTo(c: v37) != nullptr )
                    {
                      v38 = *(_DWORD *)(HIDWORD(v7) + v35);
                      if ( gameLocal->spawnIds.ptr[v38 & 0x1FFF] == v38 >> 13
                        && (v39 = (idPlayer *)gameLocal->entities.ptr[v38 & 0x1FFF]) != nullptr )
                      {
                        v40 = idPlayer::CastTo(c: v39);
                      }
                      else
                      {
                        v40 = nullptr;
                      }
                      entityNumber = v40->entityNumber;
                      v55.maxSize = 256;
                      v55.writeData = v60;
                      v55.readData = v60;
                      memset(&v55.curSize, 0, 18);
                      v55.tempValue = v7;
                      v54.writing = true;
                      v54.msg = &v55;
                      idBitMsg::WriteBits(this: &v55, value: entityNumber, numBits: 32);
                      idSerializer::SerializeString(this: &v54, s: &this->collectibleStatusMessage);
                      idBitMsg::WriteBits(this: &v55, value: 2, numBits: 32);
                      NumCollectiblesFound = idGameChallenge_Coop::GetNumCollectiblesFound(this);
                      idBitMsg::WriteBits(this: &v55, value: NumCollectiblesFound, numBits: 32);
                      MaxNumCollectibles = idGameChallenge_Coop::GetMaxNumCollectibles(this);
                      idBitMsg::WriteBits(this: &v55, value: MaxNumCollectibles, numBits: 32);
                      v44 = session->GetActingGameStateLobbyBase(this: session);
                      v45 = *(_DWORD *)(HIDWORD(v7) + v35);
                      v46 = v44;
                      if ( gameLocal->spawnIds.ptr[v45 & 0x1FFF] == v45 >> 13
                        && (v47 = (idPlayer *)gameLocal->entities.ptr[v45 & 0x1FFF]) != nullptr )
                      {
                        v48 = idPlayer::CastTo(c: v47);
                      }
                      else
                      {
                        v48 = nullptr;
                      }
                      presentable = v48->presentable;
                      if ( presentable != nullptr )
                        v50 = (lobbyUserID_t *)presentable->GetPlayerInterface_2(this: presentable);
                      else
                        v50 = nullptr;
                      v51 = v46->__vftable;
                      LobbyUserID = idPresentablePlayer::GetLobbyUserID(this: (idPresentablePlayer *)v57, result: v50);
                      v51->SendReliableToLobbyUser(
                        this: (idLobbyBase *)LobbyUserID->__vftable,
                        a2: *((lobbyUserID_t **)&LobbyUserID->__vftable + 1),
                        a3: 35,
                        a4: &v55);
                    }
                  }
                  ++v34;
                  v35 += 80;
                }
                while ( v34 < this->players.num );
              }
            }
          }
          ++v28;
          ++v29;
        }
        while ( v28 < this->collectibleList.num );
      }
    }
    else
    {
      num = this->players.num;
      v11 = 0;
      this->specialCollectible.found = found_;
      if ( num > 0 )
      {
        v12 = 0;
        do
        {
          HIDWORD(v7) = this->players.list;
          v13 = *(_DWORD *)(HIDWORD(v7) + v12);
          if ( gameLocal->spawnIds.ptr[v13 & 0x1FFF] == v13 >> 13 )
          {
            v14 = (idPlayer *)gameLocal->entities.ptr[v13 & 0x1FFF];
            if ( v14 != nullptr && idPlayer::CastTo(c: v14) != nullptr )
            {
              v15 = *(_DWORD *)(HIDWORD(v7) + v12);
              if ( gameLocal->spawnIds.ptr[v15 & 0x1FFF] == v15 >> 13
                && (v16 = (idPlayer *)gameLocal->entities.ptr[v15 & 0x1FFF]) != nullptr )
              {
                v17 = idPlayer::CastTo(c: v16);
              }
              else
              {
                v17 = nullptr;
              }
              v18 = v17->entityNumber;
              v56.maxSize = 256;
              v56.writeData = v59;
              v56.readData = v59;
              memset(&v56.curSize, 0, 18);
              v53[0] = v18;
              v56.tempValue = v7;
              v54.writing = true;
              v54.msg = &v56;
              idSerializer::Serialize(this: &v54, value: v53);
              idStr::idStr(this: &v58, text: "#str_online_collect_special_status");
              idBitMsg::WriteString(this: &v56, s: v58.data, maxLength: -1, make7Bit: true);
              v53[0] = 0;
              idSerializer::Serialize(this: &v54, value: v53);
              v53[0] = 0;
              idSerializer::Serialize(this: &v54, value: v53);
              v53[0] = 0;
              idSerializer::Serialize(this: &v54, value: v53);
              v19 = session->GetActingGameStateLobbyBase(this: session);
              v20 = *(_DWORD *)(HIDWORD(v7) + v12);
              v21 = v19;
              if ( gameLocal->spawnIds.ptr[v20 & 0x1FFF] == v20 >> 13
                && (v22 = (idPlayer *)gameLocal->entities.ptr[v20 & 0x1FFF]) != nullptr )
              {
                v23 = idPlayer::CastTo(c: v22);
              }
              else
              {
                v23 = nullptr;
              }
              v24 = v23->presentable;
              if ( v24 != nullptr )
                v25 = (lobbyUserID_t *)v24->GetPlayerInterface_2(this: v24);
              else
                v25 = nullptr;
              v26 = v21->__vftable;
              v27 = idPresentablePlayer::GetLobbyUserID(this: (idPresentablePlayer *)v57, result: v25);
              v26->SendReliableToLobbyUser(
                this: (idLobbyBase *)v27->__vftable,
                a2: *((lobbyUserID_t **)&v27->__vftable + 1),
                a3: 35,
                a4: &v56);
              idStr::FreeData(this: &v58);
            }
          }
          ++v11;
          v12 += 80;
        }
        while ( v11 < this->players.num );
      }
    }
  }
}


// ========================================================================
// __unwind$502394
// EA  : 0x82C56330
// RVA : 0x00C56330
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

void _unwind_502394()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 864 + 192));
}


// ========================================================================
// ?AIKill@idGameChallenge_Coop@@AAAXHHPBVidDeclDamage@@@Z
// EA  : 0x82C56358
// RVA : 0x00C56358
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

void __fastcall idGameChallenge_Coop::AIKill(
        idGameChallenge_Coop *this,
        unsigned int attackingPlayerEntityNumber,
        int victimPlayerEntityNumber,
        const idDeclDamage *damageDef)
{
  idGameLocal *v7; // r11
  int value; // r9
  idPlayer *v9; // r3
  char v10; // r10
  idAI2 *v11; // r3
  idAI2 *v12; // r3
  idAI2 *v13; // r31
  int valueInteger; // r8
  const idDeclEntityDef *entityDef; // r11
  const char *str; // r7
  int damageGroup; // r11
  int v18; // r11
  unsigned __int8 *v19; // r11
  const char *v20; // r10
  int v21; // r9
  int v22; // r9
  bool v23; // zf

  if ( attackingPlayerEntityNumber > 5 )
    goto LABEL_6;
  v7 = gameLocal;
  value = this->players.list[attackingPlayerEntityNumber].player.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] != value >> 13 )
    goto LABEL_7;
  v9 = (idPlayer *)gameLocal->entities.ptr[this->players.list[attackingPlayerEntityNumber].player.spawnId.value & 0x1FFF];
  if ( v9 == nullptr )
    goto LABEL_7;
  if ( idPlayer::CastTo(c: v9) == nullptr )
  {
LABEL_6:
    v7 = gameLocal;
LABEL_7:
    v10 = 0;
    goto LABEL_8;
  }
  v7 = gameLocal;
  v10 = 1;
LABEL_8:
  if ( v10 != 0 && damageDef != nullptr )
  {
    v11 = (idAI2 *)v7->GetEntity(this: v7, a2: victimPlayerEntityNumber);
    v12 = idAI2::CastTo(c: v11);
    v13 = v12;
    if ( v12 != nullptr )
    {
      valueInteger = gc_spawnDebug.valueInteger;
      if ( gc_spawnDebug.valueInteger != 0 )
      {
        entityDef = v12->entityDef;
        if ( entityDef != nullptr )
          str = entityDef->name.str;
        else
          str = "*unknown*";
        idLib::Printf(
          fmt: "Player %d killed AI %d - %s (def: %s) \n",
          attackingPlayerEntityNumber,
          victimPlayerEntityNumber,
          v12->name.data,
          str);
        valueInteger = gc_spawnDebug.valueInteger;
      }
      damageGroup = v13->damageGroup;
      if ( damageGroup >= 0 )
      {
        v18 = (int)&v13->actorEditable.damageGroups.list[damageGroup];
        if ( v18 != 0 )
        {
          v19 = *(unsigned __int8 **)(v18 + 4);
          v20 = "head";
          do
          {
            v21 = *v19;
            v23 = v21 == 0;
            v22 = v21 - *(unsigned __int8 *)v20;
            if ( v23 )
              break;
            ++v19;
            ++v20;
          }
          while ( v22 == 0 );
          if ( v22 == 0 && valueInteger != 0 )
            idLib::Printf(fmt: "   Headshot\n");
        }
      }
    }
  }
}


// ========================================================================
// ?GetTeamNumber@idGameChallenge_PVP@@UBA?AW4gameTeam_t@@ABUplayerData_t@idGameChallenge@@@Z
// EA  : 0x82C564E8
// RVA : 0x00C564E8
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

gameTeam_t __fastcall idGameChallenge_PVP::GetTeamNumber(
        idGameChallenge_PVP *this,
        const idGameChallenge::playerData_t *data)
{
  BOOL isTeamGame; // r11
  gameTeam_t result; // r3
  idPlayer *v4; // r3
  idPlayer *v5; // r3

  isTeamGame = this->isTeamGame;
  result = TEAM_NONE;
  if ( isTeamGame && gameLocal->spawnIds.ptr[data->player.spawnId.value & 0x1FFF] == data->player.spawnId.value >> 13 )
  {
    v4 = (idPlayer *)gameLocal->entities.ptr[data->player.spawnId.value & 0x1FFF];
    if ( v4 != nullptr )
      v5 = idPlayer::CastTo(c: v4);
    else
      v5 = nullptr;
    return ((_cntlzw(v5->entityNumber % 2) & 0x20) != 0) + 1;
  }
  return result;
}


// ========================================================================
// ?ScorePlayerKill@idGameChallenge_PVP@@UAAXHH@Z
// EA  : 0x82C56590
// RVA : 0x00C56590
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

void __fastcall idGameChallenge_PVP::ScorePlayerKill(
        idGameChallenge_PVP *this,
        unsigned int attackingPlayerEntityNumber,
        unsigned int victimPlayerEntityNumber)
{
  idGameChallenge::playerData_t *PlayerData; // r30
  idGameChallenge::playerData_t *v7; // r3
  idGameChallenge::playerData_t *v8; // r29
  gameTeam_t team; // r11
  gameTeam_t v10; // r10

  if ( this->CanScore(this) )
  {
    PlayerData = idGameChallenge::GetPlayerData(this, playerEntityNumber: attackingPlayerEntityNumber);
    v7 = idGameChallenge::GetPlayerData(this, playerEntityNumber: victimPlayerEntityNumber);
    v8 = v7;
    if ( PlayerData != nullptr && v7 != nullptr )
    {
      if ( this->IsTeamGame(this) )
      {
        team = PlayerData->team;
        if ( team != TEAM_NONE )
        {
          v10 = v8->team;
          if ( v10 != TEAM_NONE && team != v10 )
          {
            PlayerData->score += this->killScore;
            this->teams.list[team - 1].teamScore += this->killScore;
          }
        }
      }
      else
      {
        PlayerData->score += this->killScore;
      }
    }
  }
}


// ========================================================================
// ?ScoreTeamKill@idGameChallenge_PVP@@UAAXHH@Z
// EA  : 0x82C56690
// RVA : 0x00C56690
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

void __fastcall idGameChallenge_PVP::ScoreTeamKill(
        idGameChallenge_PVP *this,
        unsigned int attackingPlayerEntityNumber,
        unsigned int victimPlayerEntityNumber)
{
  idGameChallenge::playerData_t *PlayerData; // r30
  idGameChallenge::playerData_t *v7; // r3
  int team; // r11
  int *p_teamScore; // r10

  if ( this->CanScore(this) )
  {
    PlayerData = idGameChallenge::GetPlayerData(this, playerEntityNumber: attackingPlayerEntityNumber);
    v7 = idGameChallenge::GetPlayerData(this, playerEntityNumber: victimPlayerEntityNumber);
    if ( PlayerData != nullptr && v7 != nullptr )
    {
      team = PlayerData->team;
      PlayerData->score -= this->killScore;
      if ( team > 0 )
      {
        p_teamScore = &this->teams.list[team - 1].teamScore;
        *p_teamScore -= this->killScore;
      }
    }
  }
}


// ========================================================================
// ?CanPostStats@idGameChallenge@@QBA_NXZ
// EA  : 0x82C56890
// RVA : 0x00C56890
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

int __fastcall idGameChallenge::CanPostStats(idGameChallenge *this)
{
  idLobbyBase *v3; // r3
  char v4; // r27
  idLobbyBase *v5; // r3
  idLobbyBase *v6; // r3
  double v7; // fp31
  int v8; // r3
  int originalEndTime; // r29
  bool v10; // cr56
  __int64 (*GetGameMs)(void); // ctr
  int v12; // r3
  int v13; // r29
  __int128 v14; // r5
  __int64 v15; // r9
  __int64 v16; // r7
  int (*v17)(void); // ctr
  int v18; // r3
  int v19; // r3
  idLobbyBase *v20; // r3
  idLobbyBase *v21; // r3

  if ( cg_forceStats.valueInteger != 0 )
    return 1;
  if ( this->bGameFailed )
    return 0;
  if ( session->GetState(this: session) != INGAME )
    return 0;
  v3 = session->GetActingGameStateLobbyBase(this: session);
  if ( (v3->GetMatchParms(this: v3)->matchFlags & 1) == 0 )
    return 0;
  v4 = 0;
  v5 = session->GetActingGameStateLobbyBase(this: session);
  if ( (v5->GetMatchParms(this: v5)->matchFlags & 0x80) != 0 && this->timeLimit > 0 )
  {
    v6 = session->GetActingGameStateLobbyBase(this: session);
    if ( v6->GetMatchParms(this: v6)->gameType == 2 )
    {
      v7 = ((double (__fastcall *)(idSession *, const char *, double))session->GetTitleStorageFloat_2)(
             a1: session,
             a2: "minPercentTimeForStatsWhenAlone",
             a3: 0.5);
      v8 = session->GetTitleStorageInt_2(this: session, a2: "maxTimeLeftInSecondsForStatsWhenAlone", a3: 45);
      originalEndTime = this->originalEndTime;
      v10 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) < originalEndTime - 1000 * v8;
      GetGameMs = (__int64 (*)(void))gameLocal->GetGameMs;
      if ( v10 )
      {
        v13 = this->originalEndTime;
        *(_QWORD *)((char *)&v14 + 4) = GetGameMs();
        LODWORD(v15) = DWORD1(v14);
        HIDWORD(v15) = this->timeLimit;
        LODWORD(v16) = v13;
        LODWORD(v14) = 1000 * HIDWORD(v15);
        v17 = (int (*)(void))gameLocal->GetGameMs;
        if ( (float)v15 < (double)(float)-(float)((float)((float)(__int64)v14 * (float)v7) - (float)v16) )
        {
          v19 = v17();
          idLib::Printf(fmt: "Time NOT good enough for stats when alone %i - %i - %i\n", this->timeLimit, v19, v13);
        }
        else
        {
          v18 = v17();
          idLib::Printf(fmt: "Percent was good enough for stats %i - %i - %i\n", this->timeLimit, v18, v13);
          v4 = 1;
        }
      }
      else
      {
        v12 = GetGameMs();
        idLib::Printf(fmt: "Time was good enough for stats %i - %i - %i\n", this->timeLimit, v12, originalEndTime);
        v4 = 1;
      }
    }
  }
  if ( v4 != 0 )
    return 1;
  v20 = session->GetActingGameStateLobbyBase(this: session);
  if ( (v20->GetMatchParms(this: v20)->matchFlags & 2) != 0
    && ((v21 = session->GetActingGameStateLobbyBase(this: session), v21->GetNumConnectedPeersInGame(this: v21) == 0)
     || (unsigned __int8)idGameChallenge::AllClientsDisconnected(this) != 0) )
  {
    return 0;
  }
  else
  {
    return ((this->players.num >= 0) + (this->players.num <= 1u)) & 1;
  }
}


// ========================================================================
// ?Notice_TeamKill@idGameChallenge@@QAA?AVeventVoid@@PAVidEventReceiver@@HHPBVidDeclDamage@@@Z
// EA  : 0x82C56BB0
// RVA : 0x00C56BB0
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

idGameChallenge *__fastcall idGameChallenge::Notice_TeamKill(
        idGameChallenge *this,
        idGameChallenge *result,
        idEventReceiver *caller,
        int attackingPlayerEntityNumber,
        unsigned int victimPlayerEntityNumber,
        const idDeclDamage *damageDef)
{
  if ( result->gameMode != CHALLENGE_MODE_COOP )
  {
    idGameChallenge::LogStatKillDeath(this: result, attackingPlayerEntityNumber: 0xFFFFFFFF, victimPlayerEntityNumber);
    result->BroadcastKillMessage(
      this: result,
      a2: attackingPlayerEntityNumber,
      a3: victimPlayerEntityNumber,
      a4: damageDef,
      a5: true,
      a6: 0,
      a7: 0);
  }
  return this;
}


// ========================================================================
// ?Notice_Suicide@idGameChallenge@@QAA?AVeventVoid@@PAVidEventReceiver@@HPBVidDeclDamage@@@Z
// EA  : 0x82C56C28
// RVA : 0x00C56C28
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

idGameChallenge *__fastcall idGameChallenge::Notice_Suicide(
        idGameChallenge *this,
        idGameChallenge *result,
        idEventReceiver *caller,
        unsigned int victimPlayerEntityNumber,
        const idDeclDamage *damageDef)
{
  idGameChallenge::playerData_t *PlayerData; // r30
  idGameChallenge *v10; // r3
  bool v11; // zf
  int score; // r10

  idGameChallenge::LogStatKillDeath(this: result, attackingPlayerEntityNumber: 0xFFFFFFFF, victimPlayerEntityNumber);
  result->BroadcastKillMessage(
    this: result,
    a2: victimPlayerEntityNumber,
    a3: victimPlayerEntityNumber,
    a4: damageDef,
    a5: false,
    a6: 0,
    a7: 0);
  PlayerData = idGameChallenge::GetPlayerData(this: result, playerEntityNumber: victimPlayerEntityNumber);
  v11 = result->IsTeamGame(this: result);
  v10 = this;
  if ( !v11 && PlayerData != nullptr )
  {
    score = PlayerData->score;
    PlayerData->respawnDelay = result->suicideSpawnDelay;
    PlayerData->score = score - result->suicideScore;
  }
  return v10;
}


// ========================================================================
// ?Notice_Death@idGameChallenge@@QAA?AVeventVoid@@PAVidEventReceiver@@HHPBVidDeclDamage@@@Z
// EA  : 0x82C56CE0
// RVA : 0x00C56CE0
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

idGameChallenge *__fastcall idGameChallenge::Notice_Death(
        idGameChallenge *this,
        idGameChallenge *result,
        idEventReceiver *caller,
        unsigned int playerEntityNumber,
        unsigned int killerEntityNum,
        const idDeclDamage *damageDef)
{
  idGameChallenge::playerData_t *PlayerData; // r3
  idPlayer *v12; // r3
  idGameChallenge::playerData_t *v13; // r30
  int score; // r10

  PlayerData = idGameChallenge::GetPlayerData(this: result, playerEntityNumber: killerEntityNum);
  if ( PlayerData == nullptr
    || gameLocal->spawnIds.ptr[PlayerData->player.spawnId.value & 0x1FFF] != PlayerData->player.spawnId.value >> 13
    || (v12 = (idPlayer *)gameLocal->entities.ptr[PlayerData->player.spawnId.value & 0x1FFF]) == nullptr
    || idPlayer::CastTo(c: v12) == nullptr )
  {
    v13 = idGameChallenge::GetPlayerData(this: result, playerEntityNumber);
    if ( !result->IsTeamGame(this: result) && v13 != nullptr )
    {
      score = v13->score;
      v13->respawnDelay = result->suicideSpawnDelay;
      v13->score = score - result->suicideScore;
    }
    result->BroadcastKillMessage(
      this: result,
      a2: killerEntityNum,
      a3: playerEntityNumber,
      a4: damageDef,
      a5: false,
      a6: 0,
      a7: -result->suicideScore);
  }
  return this;
}


// ========================================================================
// ?Spawn@idGameChallenge@@QAAXXZ
// EA  : 0x82C56DF0
// RVA : 0x00C56DF0
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

void __fastcall idGameChallenge::Spawn(idGameChallenge *this)
{
  idEventArg *v2; // r3
  const idEventArg **v3; // r10
  _DWORD *v4; // r11
  int i; // ctr
  int v6; // r3
  idDoomSpawnManager *v7; // r3
  idDoomSpawnManager *v8; // r3
  int j; // r30
  idSpawnNode *v10; // r4
  const idEventArg *v11[9]; // [sp+5Ch] [-74h] BYREF
  idEventArg v12[4]; // [sp+80h] [-50h] BYREF

  if ( this->startActive && common->IsMultiplayer(this: common) )
  {
    v2 = idEventArg::idEventArg(this: v12, data: this);
    v3 = v11;
    v4 = (_DWORD *)&v2[-1].value.q[3];
    for ( i = 5; i != 0; --i )
      *++v3 = (const idEventArg *)*++v4;
    v6 = GameFramesToTicks(frameNum: 2, type: GAMETIME_SCALED);
    idEventReceiver::PostEventMS(this: &this->idEntity, ev: &EV_Activate, time: v6, arg1: v11[3]);
  }
  gameLocal->challengeEntity.spawnId.value = (gameLocal->spawnIds.ptr[this->entityNumber] << 13) | this->entityNumber;
  v7 = (idDoomSpawnManager *)idMem::AllocWithLocation(
                               this: &mem,
                               location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                               size: 0x8ACu,
                               tag: TAG_GAME,
                               zeroBuffer: false,
                               align: ALIGN_16,
                               heap: HEAP_DEFAULTHEAP);
  if ( v7 != nullptr )
    v8 = idDoomSpawnManager::idDoomSpawnManager(this: v7);
  else
    v8 = nullptr;
  this->spawnManager = v8;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->spawnNodeGroup);
  this->spawnNodeGroup.approximateLocationCount = 0;
  for ( j = 86252; j < 119020; j += 4 )
  {
    v10 = idSpawnNode::CastTo(c: *(idSpawnNode **)((char *)&gameLocal->__vftable + j));
    if ( v10 != nullptr )
      idSpawnNodeGroup::AddNode(this: &this->spawnNodeGroup, node: v10);
  }
  this->reviveThreshold = session->GetTitleStorageFloat_2(
                            this: session,
                            a2: "gc_reviveThreshold",
                            a3: gc_reviveThreshold.valueFloat);
}


// ========================================================================
// __unwind$503747
// EA  : 0x82C56F94
// RVA : 0x00C56F94
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

void _unwind_503747()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 208 + 80), tag: TAG_GAME);
}


// ========================================================================
// ?SetTeam@idGameChallenge@@QAAXAAUplayerData_t@1@W4gameTeam_t@@_N@Z
// EA  : 0x82C56FC0
// RVA : 0x00C56FC0
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

void __fastcall idGameChallenge::SetTeam(
        idGameChallenge *this,
        idGameChallenge::playerData_t *data,
        gameTeam_t team,
        bool resetScore,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        gameTeam_t a16)
{
  int v17; // r11
  int v18; // r9
  idPlayer *v22; // r3
  int value; // r9
  idPlayer *v24; // r3
  idPlayer *v25; // r4
  idPlayer *v26; // r3
  idPlayer *v27; // r3
  gameTeam_t v28; // r11
  idGameChallenge::teamData_t *list; // r9
  idPlayer *v30; // r3
  idPlayer *v31; // r3
  idGameChallenge::teamData_t *v32; // r10
  const idDeclFaction *FactionFromTeam; // r30
  idGameLocal *v34; // r11
  idPlayer *v35; // r3
  idPlayer *v36; // r3
  idPlayer *v37; // r3
  idPlayer *v38; // r3
  idPlayer *v39; // r3
  idEntityPtr<idAI2> v40[16]; // [sp+50h] [-40h] BYREF

  v17 = data->player.spawnId.value & 0x1FFF;
  v18 = data->player.spawnId.value >> 13;
  a16 = team;
  if ( gameLocal->spawnIds.ptr[v17] != v18 )
    return;
  v22 = (idPlayer *)gameLocal->entities.ptr[v17];
  if ( v22 == nullptr || idPlayer::CastTo(c: v22) == nullptr )
    return;
  if ( resetScore )
  {
    value = data->player.spawnId.value;
    data->score = 0;
    if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
      && (v24 = (idPlayer *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
    {
      v25 = idPlayer::CastTo(c: v24);
    }
    else
    {
      v25 = nullptr;
    }
    idRageMetrics::ResetStats(this: clientGame->rageMetrics, player: v25);
  }
  if ( data->team > TEAM_NONE )
  {
    if ( gameLocal->spawnIds.ptr[data->player.spawnId.value & 0x1FFF] == data->player.spawnId.value >> 13
      && (v26 = (idPlayer *)gameLocal->entities.ptr[data->player.spawnId.value & 0x1FFF]) != nullptr )
    {
      v27 = idPlayer::CastTo(c: v26);
    }
    else
    {
      v27 = nullptr;
    }
    v28 = data->team;
    list = this->teams.list;
    v40[0] = (idEntityPtr<idAI2>)v27->entityNumber;
    idList<idEntityPtr<idPlayer>,5>::Remove(this: (idList<idEntityPtr<idAI2>,5> *)&list[v28 - 1], obj: v40);
  }
  if ( team > TEAM_NONE )
  {
    if ( gameLocal->spawnIds.ptr[data->player.spawnId.value & 0x1FFF] == data->player.spawnId.value >> 13
      && (v30 = (idPlayer *)gameLocal->entities.ptr[data->player.spawnId.value & 0x1FFF]) != nullptr )
    {
      v31 = idPlayer::CastTo(c: v30);
    }
    else
    {
      v31 = nullptr;
    }
    v32 = this->teams.list;
    v40[0] = (idEntityPtr<idAI2>)v31->entityNumber;
    idList<int,46>::AddUnique(this: &v32[team - 1].playerIndexList, obj: (const encounterGroupRole_t *)v40);
  }
  data->team = team;
  FactionFromTeam = idGameChallenge::GetFactionFromTeam(this, team: &a16);
  if ( FactionFromTeam != nullptr )
  {
    v34 = gameLocal;
    if ( gameLocal->spawnIds.ptr[data->player.spawnId.value & 0x1FFF] != data->player.spawnId.value >> 13 )
      goto LABEL_27;
    if ( idEntityPtr<idPlayer>::operator->(this: &data->player) != nullptr )
    {
      v35 = idEntityPtr<idPlayer>::operator->(this: &data->player);
      idActor::SetFaction(this: v35, faction: FactionFromTeam);
      v36 = idEntityPtr<idPlayer>::operator->(this: &data->player);
      idEntity::SetTeam(this: v36, team);
    }
  }
  v34 = gameLocal;
LABEL_27:
  if ( v34->spawnIds.ptr[data->player.spawnId.value & 0x1FFF] == data->player.spawnId.value >> 13 )
  {
    v37 = (idPlayer *)v34->entities.ptr[data->player.spawnId.value & 0x1FFF];
    if ( v37 != nullptr && idPlayer::CastTo(c: v37) != nullptr )
    {
      if ( gameLocal->spawnIds.ptr[data->player.spawnId.value & 0x1FFF] == data->player.spawnId.value >> 13
        && (v38 = (idPlayer *)gameLocal->entities.ptr[data->player.spawnId.value & 0x1FFF]) != nullptr )
      {
        v39 = idPlayer::CastTo(c: v38);
      }
      else
      {
        v39 = nullptr;
      }
      idEntity::SetTeam(this: v39, team);
    }
  }
  this->SetTeamRenderModel(this, a2: data);
}


// ========================================================================
// ?EndGame@idGameChallenge@@UAAXXZ
// EA  : 0x82C572B0
// RVA : 0x00C572B0
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

void __fastcall idGameChallenge::EndGame(idGameChallenge *this)
{
  int v2; // r23
  int v3; // r26
  idGameChallenge::playerData_t *v4; // r28
  idGameChallenge_vtbl *v5; // r11
  int v6; // r30
  int v7; // r29
  idPlayer *v8; // r3
  idPlayer *v9; // r4
  bool v10; // r3
  idGameChallenge_vtbl *v11; // r10
  idGameChallenge::playerData_t *list; // r11
  int v13; // r3
  int v14; // r30
  idPlayer *v15; // r3
  idPlayer *v16; // r4
  idPlayer *v17; // r3
  idPlayer *v18; // r4
  const idSoundShader *failedGameOverSound; // r5
  idLobbyBase *v20; // r3
  int v21; // r28
  int v22; // r29
  idGameChallenge::playerData_t *v23; // r30
  int value; // r9
  idPlayer *v25; // r3
  int v26; // r9
  idPlayer *v27; // r3
  idPlayer *v28; // r3

  common->CloseSnapshotFiles(this: common);
  if ( (unsigned __int8)idGameChallenge::CanPostStats(this) != 0 )
  {
    v2 = 0;
    if ( this->players.num > 0 )
    {
      v3 = 0;
      do
      {
        v4 = &this->players.list[v3];
        if ( gameLocal->spawnIds.ptr[v4->player.spawnId.value & 0x1FFF] == v4->player.spawnId.value >> 13 )
        {
          v5 = this->__vftable;
          if ( this->gameMode == CHALLENGE_MODE_COOP )
          {
            v6 = v5->GetPlayerScore(this, a2: &this->players.list[v3]);
            v7 = this->GetTeamScore(this, a2: TEAM_NONE);
            if ( gameLocal->spawnIds.ptr[v4->player.spawnId.value & 0x1FFF] == v4->player.spawnId.value >> 13
              && (v8 = (idPlayer *)gameLocal->entities.ptr[v4->player.spawnId.value & 0x1FFF]) != nullptr )
            {
              v9 = idPlayer::CastTo(c: v8);
            }
            else
            {
              v9 = nullptr;
            }
            idRageMetrics::Score_COOP(this: clientGame->rageMetrics, player: v9, teamScore: v6, individualScore: v7);
          }
          else
          {
            v10 = v5->IsTeamGame(this);
            v11 = this->__vftable;
            list = this->players.list;
            if ( v10 )
              v13 = v11->GetTeamScore(this, a2: list[v3].team);
            else
              v13 = v11->GetPlayerScore(this, a2: &list[v3]);
            v14 = v13;
            if ( gameLocal->spawnIds.ptr[v4->player.spawnId.value & 0x1FFF] == v4->player.spawnId.value >> 13
              && (v15 = (idPlayer *)gameLocal->entities.ptr[v4->player.spawnId.value & 0x1FFF]) != nullptr )
            {
              v16 = idPlayer::CastTo(c: v15);
            }
            else
            {
              v16 = nullptr;
            }
            idRageMetrics::Score_VDM(this: clientGame->rageMetrics, player: v16, score: v14);
          }
          if ( gameLocal->spawnIds.ptr[v4->player.spawnId.value & 0x1FFF] == v4->player.spawnId.value >> 13
            && (v17 = (idPlayer *)gameLocal->entities.ptr[v4->player.spawnId.value & 0x1FFF]) != nullptr )
          {
            v18 = idPlayer::CastTo(c: v17);
          }
          else
          {
            v18 = nullptr;
          }
          idRageMetrics::SetTime(this: clientGame->rageMetrics, player: v18, time: this->endTime - this->startTime);
        }
        ++v2;
        ++v3;
      }
      while ( v2 < this->players.num );
    }
    idRageMetrics::EndGame(this: clientGame->rageMetrics, challenge: this, postStats: true);
    this->PostStatsToLeaderboard(this);
  }
  else
  {
    idRageMetrics::EndGame(this: clientGame->rageMetrics, challenge: this, postStats: false);
  }
  gameLocal->challengeState = CHALLENGE_STATE_RESULTS;
  if ( this->gameMusic != nullptr )
    idEntity::StopSound(this: &this->idEntity, channel: SND_CHANNEL_MUSIC1, peerMask: 0xFFu);
  if ( this->bGameFailed && (failedGameOverSound = this->failedGameOverSound) != nullptr
    || (failedGameOverSound = this->gameOverSound) != nullptr )
  {
    idEntity::StartSoundShader(
      this: &this->idEntity,
      channel: SND_CHANNEL_MUSIC2,
      shader: failedGameOverSound,
      soundShaderFlags: SSF_GLOBAL|SSF_OMNIDIRECTIONAL,
      peerMask: 0xFFu);
  }
  v20 = session->GetActingGameStateLobbyBase(this: session);
  if ( v20->GetMatchParms(this: v20)->gameType != 2 )
  {
    v21 = 0;
    if ( this->players.num > 0 )
    {
      v22 = 0;
      do
      {
        v23 = this->players.list;
        value = v23[v22].player.spawnId.value;
        if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
        {
          v25 = (idPlayer *)gameLocal->entities.ptr[value & 0x1FFF];
          if ( v25 != nullptr && idPlayer::CastTo(c: v25) != nullptr )
          {
            v26 = v23[v22].player.spawnId.value;
            if ( gameLocal->spawnIds.ptr[v26 & 0x1FFF] == v26 >> 13
              && (v27 = (idPlayer *)gameLocal->entities.ptr[v26 & 0x1FFF]) != nullptr )
            {
              v28 = idPlayer::CastTo(c: v27);
            }
            else
            {
              v28 = nullptr;
            }
            idPlayer::ResetControl(this: v28);
          }
        }
        ++v21;
        ++v22;
      }
      while ( v21 < this->players.num );
    }
  }
  this->bFinishGameExit = (_cntlzw(this->bGameFailed) & 0x20) != 0;
  this->endTimeoutDuration = 1000 * gc_failedRestartTime.valueInteger;
}


// ========================================================================
// ?GameOver@idGameChallenge@@UAAXXZ
// EA  : 0x82C576C0
// RVA : 0x00C576C0
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

void __fastcall idGameChallenge::GameOver(idGameChallenge *this)
{
  int v2; // r26
  int v3; // r28
  idGameChallenge::playerData_t *v4; // r30
  idPlayer *v5; // r3
  int v6; // [sp+50h] [-50h] BYREF
  int v7; // [sp+54h] [-4Ch] BYREF
  int v8; // [sp+58h] [-48h] BYREF
  int v9; // [sp+5Ch] [-44h] BYREF

  this->ForceScoreboardAll(this, a2: true);
  idGameLocal::BroadcastUIStatusMessage(
    this: gameLocal,
    type: 15,
    numParams: 0,
    param1: -1,
    param2: -1,
    param3: -1,
    param4: -1);
  gameLocal->challengeState = CHALLENGE_STATE_RESULTS;
  this->endTime = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
  if ( (unsigned __int8)idGameChallenge::CanPostStats(this) != 0 )
  {
    v2 = 0;
    if ( this->players.num > 0 )
    {
      v3 = 0;
      do
      {
        v4 = &this->players.list[v3];
        if ( gameLocal->spawnIds.ptr[v4->player.spawnId.value & 0x1FFF] == v4->player.spawnId.value >> 13 )
        {
          v5 = (idPlayer *)gameLocal->entities.ptr[v4->player.spawnId.value & 0x1FFF];
          if ( v5 != nullptr && idPlayer::CastTo(c: v5) != nullptr )
          {
            v9 = 0;
            v7 = 0;
            v6 = 0;
            v8 = 0;
            this->GetScoringData(this, a2: v4, a3: &v9, a4: &v7, a5: &v6, a6: &v8);
          }
        }
        ++v2;
        ++v3;
      }
      while ( v2 < this->players.num );
    }
  }
}


// ========================================================================
// ?GiveStartingItems@idGameChallenge@@QAAXAAUplayerData_t@1@@Z
// EA  : 0x82C57808
// RVA : 0x00C57808
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

void __fastcall idGameChallenge::GiveStartingItems(idGameChallenge *this, idGameChallenge::playerData_t *data)
{
  idPlayer *v4; // r3
  signed int i; // r31
  idCoopStartingInventory *CoopStartingInventory; // r31
  idPlayer *v7; // r3
  idPresentable *presentable; // r3
  idPresentablePlayer *v9; // r3

  if ( gameLocal->spawnIds.ptr[data->player.spawnId.value & 0x1FFF] == data->player.spawnId.value >> 13 )
  {
    v4 = (idPlayer *)gameLocal->entities.ptr[data->player.spawnId.value & 0x1FFF];
    if ( v4 != nullptr && idPlayer::CastTo(c: v4) != nullptr )
    {
      if ( gc_useLoadoutForPvp.valueInteger != 0 )
      {
        for ( i = 0; i < 6; ++i )
          idGameChallenge::GivePVPUnlockItemsForSlot(this, data, slot: i);
      }
      else
      {
        CoopStartingInventory = idGameLocal::GetCoopStartingInventory(this: gameLocal);
        if ( CoopStartingInventory != nullptr )
        {
          v7 = idEntityPtr<idPlayer>::operator->(this: &data->player);
          idCoopStartingInventory::GiveItems(this: CoopStartingInventory, player: v7);
          presentable = idEntityPtr<idPlayer>::operator->(this: &data->player)->presentable;
          if ( presentable != nullptr )
          {
            v9 = presentable->GetPlayerInterface_2(this: presentable);
            idPresentablePlayer::SelectBestWeapon(this: v9);
          }
          else
          {
            idPresentablePlayer::SelectBestWeapon(this: nullptr);
          }
        }
        else
        {
          idLib::Warning(fmt: "GiveStartingItems failed for player, no idCoopStartingInventory found.");
        }
      }
    }
  }
}


// ========================================================================
// ?SetupSpectatorCamera@idGameChallenge@@IAAXPAVidPlayer@@@Z
// EA  : 0x82C57920
// RVA : 0x00C57920
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

void __fastcall idGameChallenge::SetupSpectatorCamera(idGameChallenge *this, idPlayer *player)
{
  idSpectatorCamera *spectatorCamera; // r28
  idEntityPtr<idEntity> *p_initialSpectatorCamLookAt; // r31
  idGameLocal *v6; // r11
  idEntity *v7; // r3
  idEntity *v8; // r3
  int v9; // r5
  char *v10; // r10
  float *p_y; // r11
  int i; // ctr
  int value; // r9
  idEntity *v14; // r3
  idEntity *v15; // r3
  idPhysics *Physics; // r31
  float *v17; // r3
  float *v18; // r3
  double x; // fp11
  double y; // fp10
  double z; // fp9
  double v22; // fp8
  double v23; // fp7
  double v24; // fp6
  double v25; // fp5
  double v26; // fp4
  double v27; // fp3
  idSpectatorCamera_vtbl *v28; // r11
  void (__fastcall *Init)(idSpectatorCamera *, idVec3 *__struct_ptr, idMat3 *__struct_ptr, idEntity *); // r11
  float v30; // [sp+60h] [-70h]
  float v31; // [sp+64h] [-6Ch]
  char v32; // [sp+6Ch] [-64h] BYREF
  float v33; // [sp+70h] [-60h]
  float v34; // [sp+74h] [-5Ch]
  float v35; // [sp+78h] [-58h]
  float v36; // [sp+7Ch] [-54h]
  float v37; // [sp+80h] [-50h]
  float v38; // [sp+84h] [-4Ch]
  float v39; // [sp+88h] [-48h]
  float v40; // [sp+8Ch] [-44h]
  float v41; // [sp+90h] [-40h]

  spectatorCamera = player->spectatorCamera;
  if ( spectatorCamera == nullptr || !this->useSpectatorCamera )
    return;
  p_initialSpectatorCamLookAt = &this->initialSpectatorCamLookAt;
  v6 = gameLocal;
  if ( gameLocal->spawnIds.ptr[this->initialSpectatorCamLookAt.spawnId.value & 0x1FFF] != this->initialSpectatorCamLookAt.spawnId.value >> 13 )
    goto LABEL_10;
  v7 = gameLocal->entities.ptr[this->initialSpectatorCamLookAt.spawnId.value & 0x1FFF];
  if ( v7 == nullptr )
    goto LABEL_10;
  if ( idEntity::CastTo(c: v7) == nullptr )
  {
    v6 = gameLocal;
LABEL_10:
    v9 = (v6->spawnIds.ptr[player->entityNumber] << 13) | player->entityNumber;
    goto LABEL_11;
  }
  v8 = idEntityPtr<idEntity const>::operator->(this: p_initialSpectatorCamLookAt);
  if ( v8 == nullptr )
  {
    spectatorCamera->target.spawnId.value = 0x1FFF;
    goto LABEL_12;
  }
  v9 = (gameLocal->spawnIds.ptr[v8->entityNumber] << 13) | v8->entityNumber;
LABEL_11:
  spectatorCamera->target.spawnId.value = v9;
LABEL_12:
  v10 = &v32;
  p_y = &mat2_identity.mat[1].y;
  for ( i = 9; i != 0; --i )
  {
    ++p_y;
    v10 += 4;
    *(float *)v10 = *p_y;
  }
  value = this->initialSpectatorCamPos.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v14 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr
    && idEntity::CastTo(c: v14) != nullptr )
  {
    v15 = idEntityPtr<idEntity const>::operator->(this: &this->initialSpectatorCamPos);
    Physics = idEntity::GetPhysics(this: v15);
    v17 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
    v30 = *v17;
    v31 = v17[1];
    v18 = (float *)Physics->GetAxis(this: Physics, a2: 0);
    x = *v18;
    y = v18[1];
    z = v18[2];
    v22 = v18[3];
    v23 = v18[4];
    v24 = v18[5];
    v25 = v18[6];
    v26 = v18[7];
    v27 = v18[8];
  }
  else
  {
    x = player->spawnOrientation.mat[0].x;
    y = player->spawnOrientation.mat[0].y;
    z = player->spawnOrientation.mat[0].z;
    v22 = player->spawnOrientation.mat[1].x;
    v23 = player->spawnOrientation.mat[1].y;
    v24 = player->spawnOrientation.mat[1].z;
    v25 = player->spawnOrientation.mat[2].x;
    v26 = player->spawnOrientation.mat[2].y;
    v27 = player->spawnOrientation.mat[2].z;
    v30 = player->spawnPosition.x;
    v31 = player->spawnPosition.y;
  }
  v40 = v26;
  v39 = v25;
  v28 = spectatorCamera->__vftable;
  v38 = v24;
  v37 = v23;
  v36 = v22;
  v35 = z;
  v34 = y;
  Init = v28->Init;
  v33 = x;
  v41 = v27;
  ((void (__fastcall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))Init)(
    a1: LODWORD(v30),
    a2: LODWORD(v31),
    a3: LODWORD(v33),
    a4: LODWORD(v34),
    a5: LODWORD(v36),
    a6: LODWORD(v39),
    a7: LODWORD(v40),
    a8: __ROL4__(LODWORD(v41), 32));
  idCamera::Activate(this: spectatorCamera, activator_: player);
}


// ========================================================================
// `idGameChallenge::SyncPlayersWithLobbyUsers'::`2'::idSWFScriptFunction_LeaveGame::Call
// EA  : 0x82C57BB0
// RVA : 0x00C57BB0
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

idSWFScriptVar *__fastcall _idGameChallenge::SyncPlayersWithLobbyUsers_::_2_::idSWFScriptFunction_LeaveGame::Call(
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  common->ClearDialog(this: common, a2: (gameDialogMessages_t)thisObject->variables.size, a3: nullptr, a4: 0);
  result->type = SWF_VAR_UNDEF;
  return result;
}


// ========================================================================
// ?EndGame@idGameChallenge_Coop@@UAAXXZ
// EA  : 0x82C57C08
// RVA : 0x00C57C08
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

void __fastcall idGameChallenge_Coop::EndGame(idGameChallenge_Coop *this)
{
  int v2; // r24
  int v3; // r30
  idGameLocal *v4; // r3
  idGameChallenge::playerData_t *list; // r31
  bool v6; // r29
  int value; // r9
  idPlayer *v8; // r3
  idPlayer *v9; // r4
  int v10; // r9
  idPlayer *v11; // r3
  idPlayer *v12; // r4

  if ( !this->bGameFailed )
  {
    v2 = 0;
    if ( this->players.num > 0 )
    {
      v3 = 0;
      v4 = gameLocal;
      do
      {
        list = this->players.list;
        if ( v4->spawnIds.ptr[list[v3].player.spawnId.value & 0x1FFF] == list[v3].player.spawnId.value >> 13 )
        {
          v6 = (_cntlzw(v4->GetGameDifficulty(this: v4) - 3) & 0x20) != 0;
          if ( !this->incapacitated )
          {
            value = list[v3].player.spawnId.value;
            if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
              && (v8 = (idPlayer *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
            {
              v9 = idPlayer::CastTo(c: v8);
            }
            else
            {
              v9 = nullptr;
            }
            idRageMetrics::CoopChallengeWithoutDeath(this: clientGame->rageMetrics, player: v9, nightmare: v6);
          }
          v10 = list[v3].player.spawnId.value;
          if ( gameLocal->spawnIds.ptr[v10 & 0x1FFF] == v10 >> 13
            && (v11 = (idPlayer *)gameLocal->entities.ptr[v10 & 0x1FFF]) != nullptr )
          {
            v12 = idPlayer::CastTo(c: v11);
          }
          else
          {
            v12 = nullptr;
          }
          idRageMetrics::CoopChallengeWithoutDefib(this: clientGame->rageMetrics, player: v12, nightmare: v6);
          v4 = gameLocal;
        }
        ++v2;
        ++v3;
      }
      while ( v2 < this->players.num );
    }
  }
  idGameChallenge::EndGame(this);
}


// ========================================================================
// ?RegisterNewPlayer@idGameChallenge_PVP@@UAA_NAAUplayerData_t@idGameChallenge@@PAVidPlayer@@_N@Z
// EA  : 0x82C57D70
// RVA : 0x00C57D70
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

int __fastcall idGameChallenge_PVP::RegisterNewPlayer(
        idGameChallenge_PVP *this,
        idGameChallenge::playerData_t *data,
        idPlayer *player,
        bool initial)
{
  gameTeam_t v7; // r3
  int v8; // r10
  int v9; // r9
  int v10; // r8
  int v11; // r7
  int v12; // [sp+8h] [-68h]
  int v13; // [sp+Ch] [-64h]
  int v14; // [sp+10h] [-60h]
  int v15; // [sp+14h] [-5Ch]
  int v16; // [sp+18h] [-58h]
  int v17; // [sp+1Ch] [-54h]
  int v18; // [sp+20h] [-50h]
  gameTeam_t v19; // [sp+24h] [-4Ch]

  if ( (unsigned __int8)idGameChallenge::RegisterNewPlayer(this, data, player, initial) == 0 )
    return 0;
  v7 = this->GetTeamNumber(this, a2: data);
  idGameChallenge::SetTeam(
    this,
    data,
    team: v7,
    resetScore: false,
    a5: v11,
    a6: v10,
    a7: v9,
    a8: v8,
    a9: v12,
    a10: v13,
    a11: v14,
    a12: v15,
    a13: v16,
    a14: v17,
    a15: v18,
    a16: v19);
  return 1;
}


// ========================================================================
// ?RespawnPlayer@idGameChallenge@@UAAXAAUplayerData_t@1@W4commandType_t@idDoomSpawnManager@@@Z
// EA  : 0x82C57FB8
// RVA : 0x00C57FB8
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

void __fastcall idGameChallenge::RespawnPlayer(
        idGameChallenge *this,
        idGameChallenge::playerData_t *data,
        idDoomSpawnManager::commandType_t spawnCmd)
{
  idPlayer *v6; // r3
  idPlayer *v7; // r31
  idSpawnNode **list; // r11
  idSpawnNode *v9; // r31
  idAngles *p_spawnOrientation; // r4
  double v11; // fp11
  double y; // fp10
  idAngles *v13; // r3
  float yaw; // r28
  float roll; // r8
  int v16; // r27
  unsigned int NewResultHandle; // r28
  idSpawnResult *SpawnResult; // r31
  idPlayer *v19; // r3
  idSpawnLocation *v20; // r10
  idDoomSpawnManager *spawnManager; // r3
  gameTeam_t v22[2]; // [sp+50h] [-90h] BYREF
  idVec3 v23; // [sp+58h] [-88h]
  idMat3 v24; // [sp+68h] [-78h] BYREF
  float pitch; // [sp+8Ch] [-54h]
  float v26; // [sp+90h] [-50h]
  float v27; // [sp+94h] [-4Ch]
  float v28; // [sp+98h] [-48h]
  idSpawnNode *v29; // [sp+9Ch] [-44h]
  int v30; // [sp+A0h] [-40h]
  float v31; // [sp+A4h] [-3Ch]

  if ( data->state == PLAYER_STATE_RESPAWNING )
  {
    if ( gc_forceSpawnFail.valueInteger == 0
      && gameLocal->spawnIds.ptr[data->player.spawnId.value & 0x1FFF] == data->player.spawnId.value >> 13 )
    {
      v6 = (idPlayer *)gameLocal->entities.ptr[data->player.spawnId.value & 0x1FFF];
      if ( v6 != nullptr )
      {
        v7 = idPlayer::CastTo(c: v6);
        if ( v7 != nullptr )
        {
          if ( this->spawnNodeGroup.nodes.num == 1 )
          {
            list = this->spawnNodeGroup.nodes.list;
            v9 = *list;
            p_spawnOrientation = (idAngles *)&(*list)->spawnOrientation;
            v11 = (float)((*list)->spawnPosition.z + (float)5.0);
            y = (*list)->spawnPosition.y;
            v23.x = (*list)->spawnPosition.x;
            v23.z = v11;
            v23.y = y;
            v13 = idMat3::ToAngles(this: &v24, result: p_spawnOrientation);
            v29 = v9;
            yaw = v13->yaw;
            roll = v13->roll;
            pitch = v13->pitch;
            v28 = 1.0;
            v31 = 0.0;
            v24.mat[2] = v23;
            v30 = 0;
            v26 = yaw;
            v27 = roll;
            v16 = idList<idSpawnLocation,5>::Append(
                    this: &this->spawnManager->context.spawnLocations,
                    obj: (const idSpawnLocation *)&v24.mat[2]);
            NewResultHandle = idSpawnManager::GetNewResultHandle(this: this->spawnManager);
            SpawnResult = (idSpawnResult *)idSpawnManager::GetSpawnResult(
                                             this: this->spawnManager,
                                             handle: NewResultHandle);
            v19 = idEntityPtr<idPlayer>::operator->(this: &data->player);
            if ( v19 != nullptr )
              SpawnResult->entity.spawnId.value = (gameLocal->spawnIds.ptr[v19->entityNumber] << 13) | v19->entityNumber;
            else
              SpawnResult->entity.spawnId.value = 0x1FFF;
            v20 = this->spawnManager->context.spawnLocations.list;
            SpawnResult->status = S_COMPLETE;
            SpawnResult->location = &v20[v16];
            data->spawnHandle = NewResultHandle;
          }
          else
          {
            spawnManager = this->spawnManager;
            v22[0] = data->team;
            data->spawnHandle = idDoomSpawnManager::QueueSpawnPlayer(
                                  this: spawnManager,
                                  playerIndex: v7->entityNumber,
                                  allowedTeams: v22,
                                  loadoutIndex: 0,
                                  spawnNodeGroup: &this->spawnNodeGroup,
                                  useInitialNodes: (_cntlzw(spawnCmd - 1) & 0x20) != 0,
                                  returnHandle: true);
            v7->spawnPending = true;
          }
        }
      }
    }
  }
  else
  {
    idLib::Warning(fmt: "Don't call RespawnPlayer directly.  Call SetPlayerState( PLAYER_STATE_RESPAWNING ) instead");
  }
}


// ========================================================================
// ?FinalizeRespawnPlayer@idGameChallenge@@UAAXAAUplayerData_t@1@ABVidVec3@@ABVidAngles@@@Z
// EA  : 0x82C581C8
// RVA : 0x00C581C8
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

void __fastcall idGameChallenge::FinalizeRespawnPlayer(
        idGameChallenge *this,
        idGameChallenge::playerData_t *data,
        const idVec3 *spawnLocation,
        const idAngles *spawnAngles)
{
  idPlayer *v8; // r3
  idPlayer *v9; // r27
  int v10; // r28
  int v11; // r30
  int value; // r9
  idEntity *v13; // r3
  idEntity *v14; // r4

  if ( gameLocal->spawnIds.ptr[data->player.spawnId.value & 0x1FFF] == data->player.spawnId.value >> 13
    && (v8 = (idPlayer *)gameLocal->entities.ptr[data->player.spawnId.value & 0x1FFF]) != nullptr )
  {
    v9 = idPlayer::CastTo(c: v8);
  }
  else
  {
    v9 = nullptr;
  }
  data->spawnHandle = 0;
  v9->spawnPending = false;
  v10 = 0;
  if ( v9->droppableList.num > 0 )
  {
    v11 = 0;
    do
    {
      value = v9->droppableList.list[v11].spawnId.value;
      if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
      {
        v13 = gameLocal->entities.ptr[value & 0x1FFF];
        if ( v13 != nullptr )
        {
          v14 = idEntity::CastTo(c: v13);
          if ( v14 != nullptr )
            gameLocal->DeleteEntity(this: gameLocal, a2: v14);
        }
      }
      ++v10;
      ++v11;
    }
    while ( v10 < v9->droppableList.num );
  }
  idPlayer::Respawn(
    this: v9,
    initial: false,
    spawnPos: spawnLocation,
    spawnAngles,
    spawnVehicle: nullptr,
    initialSpawnPoint: false);
  if ( gameLocal->challengeState > CHALLENGE_STATE_NONE )
  {
    idGameChallenge::GiveStartingItems(this, data);
    this->SetSpectator(this, a2: data, a3: false);
    data->respawnDelay = 0;
  }
  v9->loadoutChanged = false;
  this->SetPlayerState(this, a2: data, a3: PLAYER_STATE_IN_PROGRESS, a4: 0);
}


// ========================================================================
// ?SetSpectator@idGameChallenge@@UAAXAAUplayerData_t@1@_N@Z
// EA  : 0x82C58360
// RVA : 0x00C58360
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

void __fastcall idGameChallenge::SetSpectator(
        idGameChallenge *this,
        idGameChallenge::playerData_t *data,
        bool shouldSpectate)
{
  idPlayer *v6; // r3
  idPlayer *v7; // r3
  idPlayer *v8; // r3
  bool v9; // r4
  idSpectatorCamera *spectatorCamera; // r3
  idPlayer *v11; // r3
  idPlayer *v12; // r3

  if ( gameLocal->spawnIds.ptr[data->player.spawnId.value & 0x1FFF] == data->player.spawnId.value >> 13 )
  {
    v6 = (idPlayer *)gameLocal->entities.ptr[data->player.spawnId.value & 0x1FFF];
    if ( v6 != nullptr && idPlayer::CastTo(c: v6) != nullptr )
    {
      if ( data->spectator != shouldSpectate )
      {
        if ( shouldSpectate )
        {
          v7 = idEntityPtr<idPlayer>::operator->(this: &data->player);
          idGameChallenge::SetupSpectatorCamera(this, player: v7);
          v8 = idEntityPtr<idPlayer>::operator->(this: &data->player);
          v9 = true;
        }
        else
        {
          spectatorCamera = idEntityPtr<idPlayer>::operator->(this: &data->player)->spectatorCamera;
          if ( spectatorCamera != nullptr )
            idCamera::Deactivate(this: spectatorCamera);
          v8 = idEntityPtr<idPlayer>::operator->(this: &data->player);
          v9 = false;
        }
        idPlayer::SetForceInhibitControl(this: v8, inhibit: v9);
      }
      if ( gameLocal->spawnIds.ptr[data->player.spawnId.value & 0x1FFF] == data->player.spawnId.value >> 13
        && (v11 = (idPlayer *)gameLocal->entities.ptr[data->player.spawnId.value & 0x1FFF]) != nullptr )
      {
        v12 = idPlayer::CastTo(c: v11);
        idPlayer::SetSpectating(this: v12, v: shouldSpectate);
        data->spectator = shouldSpectate;
      }
      else
      {
        idPlayer::SetSpectating(this: nullptr, v: shouldSpectate);
        data->spectator = shouldSpectate;
      }
    }
  }
}


// ========================================================================
// ?SyncPlayersWithLobbyUsers@idGameChallenge@@IAAX_N@Z
// EA  : 0x82C58490
// RVA : 0x00C58490
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

void __fastcall idGameChallenge::SyncPlayersWithLobbyUsers(idGameChallenge *this, BOOL initial)
{
  int v4; // r27
  idLobbyBase *v5; // r3
  idLobbyBase *v6; // r3
  char v7; // r11
  idLobbyBase *v8; // r3
  char v9; // r28
  int v10; // r29
  idGameLocal *v11; // r9
  int v12; // r30
  idPlayer *v13; // r3
  idPlayer *v14; // r3
  idPresentable *presentable; // r3
  lobbyUserID_t *v16; // r4
  char v17; // r11
  idLobbyBase *v18; // r3
  int v19; // r24
  int v20; // r26
  idGameChallenge::playerData_t *list; // r25
  int value; // r9
  idPlayer *v23; // r3
  int v24; // r27
  int v25; // r28
  idGameChallenge::playerData_t *v26; // r30
  int v27; // r9
  idPlayer *v28; // r3
  int v29; // r9
  idGameLocal *v30; // r11
  idPlayer *v31; // r3
  idPlayer *v32; // r3
  idPresentable *v33; // r3
  int v34; // r3
  lobbyUserID_t *v35; // r30
  int v36; // r9
  idPlayer *v37; // r3
  idPlayer *v38; // r3
  idPresentable *v39; // r3
  lobbyUserID_t *v40; // r29
  idPresentablePlayer *LobbyUserID; // r30
  idPresentablePlayer *v42; // r3
  char v43; // r11
  int v44; // r26
  int v45; // r28
  idGameChallenge::playerData_t *v46; // r30
  idPlayer *v47; // r3
  idPlayer *v48; // r3
  idPlayer *v49; // r3
  idPresentable *v50; // r3
  lobbyUserID_t *v51; // r4
  idLobbyBase *v52; // r3
  idPlayer *v53; // r3
  idPlayer *v54; // r4
  idPlayer *v55; // r3
  idPlayer *v56; // r3
  idPresentable *v57; // r3
  idPresentablePlayer *v58; // r3
  idPlayer *v59; // r3
  idPlayer *v60; // r3
  idPresentable *v61; // r3
  int v62; // r3
  idPlayer *v63; // r3
  idPlayer *v64; // r3
  idPlayer *v65; // r3
  idPlayer *v66; // r3
  idLobbyBase *v67; // r3
  idLobbyBase *v68; // r3
  int v69; // r10
  int v70; // r9
  int v71; // r8
  int v72; // r7
  int v73; // r6
  int v74; // r5
  int num; // r26
  idVehicleState **v76; // r23
  int v77; // r29
  int v78; // r28
  idGameChallenge::playerData_t *v79; // r30
  idPlayer *v80; // r3
  __int64 v81; // r28
  idVehicleState **v82; // r11
  int v83; // r10
  idPlayer *Player; // r30
  idLobbyBase *v85; // r3
  const idDeclBot *v86; // r4
  challengeState_t challengeState; // r11
  idLobbyBase *v88; // r3
  idLobbyBase *v89; // r3
  int v90; // r30
  signed int v91; // r30
  idLobbyBase *v92; // r3
  idGameChallenge::playerData_t *v93; // r4
  int v94; // r29
  int v95; // r30
  int *v96; // r4
  int v97; // r29
  int v98; // r30
  int *v99; // r4
  idGameChallenge::playerData_t *v100; // r4
  _DWORD *v101; // r30
  idGameChallenge_Coop *v102; // r3
  __int32 *v103; // r10
  encounterGroupRole_t v104; // r11
  encounterGroupRole_t v105[2]; // [sp+70h] [-250h] BYREF
  int v106; // [sp+78h] [-248h] BYREF
  int v107; // [sp+7Ch] [-244h]
  lobbyUserID_t v108[2]; // [sp+80h] [-240h] BYREF
  idList<idVehicleState *,5> v109; // [sp+90h] [-230h] BYREF
  idList<idStrId,5> v110; // [sp+A0h] [-220h] BYREF
  _BYTE v111[16]; // [sp+B0h] [-210h] BYREF
  idStrId v112[4]; // [sp+C0h] [-200h] BYREF
  idList<enum encounterGroupRole_t,5> v113; // [sp+D0h] [-1F0h] BYREF
  int v114; // [sp+E0h] [-1E0h] BYREF
  _DWORD v115[4]; // [sp+F0h] [-1D0h] BYREF
  idStr v116; // [sp+100h] [-1C0h] BYREF
  char v117; // [sp+120h] [-1A0h] BYREF

  memset(&v109, 0, 14);
  *(_WORD *)&v109.memTag = 1280;
  idList<idThread *,58>::Clear(this: &v109);
  v4 = 0;
  v5 = session->GetActingGameStateLobbyBase(this: session);
  if ( v5->GetNumLobbyUsers(this: v5) > 0 )
  {
    do
    {
      v6 = session->GetActingGameStateLobbyBase(this: session);
      v6->GetLobbyUserIdByOrdinal(this: (idLobbyBase *)v108, result: (lobbyUserID_t *)v6, a3: v4);
      if ( v108[0].localUserHandle.handle == 0 || (v7 = 1, v108[0].lobbyType == 255) )
        v7 = 0;
      if ( v7 != 0 )
      {
        if ( initial
          || (v8 = session->GetActingGameStateLobbyBase(this: session),
              ((unsigned __int8 (*)(void))v8->IsLobbyUserLoaded)() != 0) )
        {
          v9 = 0;
          v10 = 0;
          if ( this->players.num > 0 )
          {
            v11 = gameLocal;
            v12 = 0;
            do
            {
              if ( v11->spawnIds.ptr[this->players.list[v12].player.spawnId.value & 0x1FFF] == this->players.list[v12].player.spawnId.value >> 13 )
              {
                v13 = (idPlayer *)v11->entities.ptr[this->players.list[v12].player.spawnId.value & 0x1FFF];
                if ( v13 != nullptr )
                  v14 = idPlayer::CastTo(c: v13);
                else
                  v14 = nullptr;
                presentable = v14->presentable;
                if ( presentable != nullptr )
                  v16 = (lobbyUserID_t *)presentable->GetPlayerInterface_2(this: presentable);
                else
                  v16 = nullptr;
                idPresentablePlayer::GetLobbyUserID(this: (idPresentablePlayer *)v115, result: v16);
                if ( v108[0].localUserHandle.handle != v115[0] || (v17 = 1, v108[0].lobbyType != HIBYTE(v115[1])) )
                  v17 = 0;
                if ( v17 != 0 )
                {
                  v9 = 1;
                  break;
                }
                v11 = gameLocal;
              }
              ++v10;
              ++v12;
            }
            while ( v10 < this->players.num );
          }
          if ( v9 == 0 )
            idList<lobbyUserID_t,5>::Append(this: (idList<lobbyUserID_t,5> *)&v109, obj: v108);
        }
      }
      ++v4;
      v18 = session->GetActingGameStateLobbyBase(this: session);
    }
    while ( v4 < v18->GetNumLobbyUsers(this: v18) );
  }
  v19 = 0;
  if ( this->players.num > 0 )
  {
    v20 = 0;
    do
    {
      list = this->players.list;
      value = list[v20].player.spawnId.value;
      if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
      {
        v23 = (idPlayer *)gameLocal->entities.ptr[value & 0x1FFF];
        if ( v23 != nullptr && idPlayer::CastTo(c: v23) != nullptr )
        {
          v24 = 0;
          if ( this->players.num > 0 )
          {
            v25 = 0;
            do
            {
              if ( v19 != v24 )
              {
                v26 = this->players.list;
                v27 = v26[v25].player.spawnId.value;
                if ( gameLocal->spawnIds.ptr[v27 & 0x1FFF] == v27 >> 13 )
                {
                  v28 = (idPlayer *)gameLocal->entities.ptr[v27 & 0x1FFF];
                  if ( v28 != nullptr && idPlayer::CastTo(c: v28) != nullptr )
                  {
                    v29 = v26[v25].player.spawnId.value;
                    v30 = gameLocal;
                    if ( gameLocal->spawnIds.ptr[v29 & 0x1FFF] == v29 >> 13
                      && (v31 = (idPlayer *)gameLocal->entities.ptr[v29 & 0x1FFF]) != nullptr )
                    {
                      v32 = idPlayer::CastTo(c: v31);
                      v30 = gameLocal;
                    }
                    else
                    {
                      v32 = nullptr;
                    }
                    v33 = v32->presentable;
                    if ( v33 != nullptr )
                    {
                      v34 = (int)v33->GetPlayerInterface_2(this: v33);
                      v30 = gameLocal;
                      v35 = (lobbyUserID_t *)v34;
                    }
                    else
                    {
                      v35 = nullptr;
                    }
                    v36 = list[v20].player.spawnId.value;
                    if ( v30->spawnIds.ptr[v36 & 0x1FFF] == v36 >> 13
                      && (v37 = (idPlayer *)v30->entities.ptr[v36 & 0x1FFF]) != nullptr )
                    {
                      v38 = idPlayer::CastTo(c: v37);
                    }
                    else
                    {
                      v38 = nullptr;
                    }
                    v39 = v38->presentable;
                    if ( v39 != nullptr )
                      v40 = (lobbyUserID_t *)v39->GetPlayerInterface_2(this: v39);
                    else
                      v40 = nullptr;
                    LobbyUserID = idPresentablePlayer::GetLobbyUserID(this: (idPresentablePlayer *)&v106, result: v35);
                    v42 = idPresentablePlayer::GetLobbyUserID(this: (idPresentablePlayer *)v105, result: v40);
                    if ( v42->__vftable != LobbyUserID->__vftable
                      || (v43 = 1,
                          *((unsigned __int8 *)&v42->__vftable + 4) != *((unsigned __int8 *)&LobbyUserID->__vftable + 4)) )
                    {
                      v43 = 0;
                    }
                    if ( v43 != 0 )
                      idLib::Warning(fmt: "Duplicate lobby user ID");
                  }
                }
              }
              ++v24;
              ++v25;
            }
            while ( v24 < this->players.num );
          }
        }
      }
      ++v19;
      ++v20;
    }
    while ( v19 < this->players.num );
  }
  v44 = 0;
  if ( this->players.num > 0 )
  {
    v45 = 0;
    do
    {
      v46 = &this->players.list[v45];
      if ( gameLocal->spawnIds.ptr[v46->player.spawnId.value & 0x1FFF] == v46->player.spawnId.value >> 13 )
      {
        v47 = (idPlayer *)gameLocal->entities.ptr[v46->player.spawnId.value & 0x1FFF];
        if ( v47 != nullptr && idPlayer::CastTo(c: v47) != nullptr )
        {
          if ( gameLocal->spawnIds.ptr[v46->player.spawnId.value & 0x1FFF] == v46->player.spawnId.value >> 13
            && (v48 = (idPlayer *)gameLocal->entities.ptr[v46->player.spawnId.value & 0x1FFF]) != nullptr )
          {
            v49 = idPlayer::CastTo(c: v48);
          }
          else
          {
            v49 = nullptr;
          }
          v50 = v49->presentable;
          if ( v50 != nullptr )
            v51 = (lobbyUserID_t *)v50->GetPlayerInterface_2(this: v50);
          else
            v51 = nullptr;
          idPresentablePlayer::GetLobbyUserID(this: (idPresentablePlayer *)&v106, result: v51);
          v52 = session->GetActingGameStateLobbyBase(this: session);
          if ( ((unsigned __int8 (*)(void))v52->IsLobbyUserValid)() != 0 )
          {
            v67 = session->GetActingGameStateLobbyBase(this: session);
            ((void (*)(void))v67->EnableSnapshotsForLobbyUser)();
            if ( v46->needToSendFullSnap )
            {
              v68 = session->GetActingGameStateLobbyBase(this: session);
              v72 = ((unsigned __int8 (*)(void))v68->LobbyUserHasFirstFullSnap)();
              if ( v72 != 0 )
              {
                idClientGame::MarkAllPresentablesAsSerialized(
                  this: clientGame,
                  skyOnly: false,
                  a3: v74,
                  a4: v73,
                  a5: v72,
                  a6: v71,
                  a7: v70,
                  a8: v69);
                clientGame->renderWorld->MarkAllLightsAsSerialized(this: clientGame->renderWorld);
                v46->needToSendFullSnap = false;
              }
            }
          }
          else
          {
            if ( gameLocal->spawnIds.ptr[v46->player.spawnId.value & 0x1FFF] == v46->player.spawnId.value >> 13
              && (v53 = (idPlayer *)gameLocal->entities.ptr[v46->player.spawnId.value & 0x1FFF]) != nullptr )
            {
              v54 = idPlayer::CastTo(c: v53);
            }
            else
            {
              v54 = nullptr;
            }
            idRageMetrics::RemovePlayer(this: clientGame->rageMetrics, player: v54);
            if ( gameLocal->spawnIds.ptr[v46->player.spawnId.value & 0x1FFF] == v46->player.spawnId.value >> 13
              && (v55 = (idPlayer *)gameLocal->entities.ptr[v46->player.spawnId.value & 0x1FFF]) != nullptr )
            {
              v56 = idPlayer::CastTo(c: v55);
            }
            else
            {
              v56 = nullptr;
            }
            v57 = v56->presentable;
            if ( v57 != nullptr )
              v58 = v57->GetPlayerInterface_2(this: v57);
            else
              v58 = nullptr;
            idPresentablePlayer::ResetLocalViews(this: v58);
            if ( gameLocal->spawnIds.ptr[v46->player.spawnId.value & 0x1FFF] == v46->player.spawnId.value >> 13
              && (v59 = (idPlayer *)gameLocal->entities.ptr[v46->player.spawnId.value & 0x1FFF]) != nullptr )
            {
              v60 = idPlayer::CastTo(c: v59);
            }
            else
            {
              v60 = nullptr;
            }
            v61 = v60->presentable;
            if ( v61 != nullptr )
              v62 = (int)v61->GetPlayerInterface_2(this: v61);
            else
              v62 = 0;
            idPlayerHud::SetTempHudState(this: (idPlayerHud *)(v62 + 35096), state: HUDSTATE_NONE);
            v46->timeTillNewPlayerCanTake = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) + 3000;
            if ( this->gameMode != CHALLENGE_MODE_COOP )
            {
              if ( gameLocal->spawnIds.ptr[v46->player.spawnId.value & 0x1FFF] == v46->player.spawnId.value >> 13
                && (v63 = (idPlayer *)gameLocal->entities.ptr[v46->player.spawnId.value & 0x1FFF]) != nullptr )
              {
                v64 = idPlayer::CastTo(c: v63);
              }
              else
              {
                v64 = nullptr;
              }
              v105[0] = (encounterGroupRole_t)v64->entityNumber;
              idList<idAnimWebBlendTree *,5>::Append(
                this: (idList<enum encounterGroupRole_t,5> *)&this->eventDisconnectList,
                obj: v105);
            }
            this->SetPlayerState(this, a2: v46, a3: PLAYER_STATE_NONE, a4: 0);
            if ( gameLocal->spawnIds.ptr[v46->player.spawnId.value & 0x1FFF] == v46->player.spawnId.value >> 13
              && (v65 = (idPlayer *)gameLocal->entities.ptr[v46->player.spawnId.value & 0x1FFF]) != nullptr )
            {
              v66 = idPlayer::CastTo(c: v65);
            }
            else
            {
              v66 = nullptr;
            }
            v66->Remove(this: v66);
            v46->player.spawnId.value = 0x1FFF;
          }
        }
      }
      ++v44;
      ++v45;
    }
    while ( v44 < this->players.num );
  }
  num = v109.num;
  v76 = v109.list;
  while ( num > 0 )
  {
    v77 = 0;
    if ( this->players.num <= 0 )
      break;
    v78 = 0;
    while ( 1 )
    {
      v79 = &this->players.list[v78];
      if ( (gameLocal->spawnIds.ptr[v79->player.spawnId.value & 0x1FFF] != v79->player.spawnId.value >> 13
         || (v80 = (idPlayer *)gameLocal->entities.ptr[v79->player.spawnId.value & 0x1FFF]) == nullptr
         || idPlayer::CastTo(c: v80) == nullptr)
        && (v79->timeTillNewPlayerCanTake == -1
         || gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) >= v79->timeTillNewPlayerCanTake) )
      {
        break;
      }
      ++v77;
      ++v78;
      if ( v77 >= this->players.num )
        goto LABEL_128;
    }
    if ( v77 == -1 )
      break;
    v81 = *(_QWORD *)v76;
    HIDWORD(v81) = &this->players.list[v77];
    if ( num > 0 )
    {
      v109.num = --num;
      if ( num > 0 )
      {
        v82 = v76;
        v83 = num;
        do
        {
          --v83;
          *v82 = v82[2];
          v82[1] = v82[3];
          v82 += 2;
        }
        while ( v83 != 0 );
      }
    }
    idGameLocal::SetupPlayer(this: gameLocal, playerNum: v77, lobbyUserID: (lobbyUserID_t *)v81, allowRecycle: false);
    Player = idGameLocal::GetPlayer(this: gameLocal, i: v77);
    if ( Player != nullptr )
    {
      v85 = session->GetActingGameStateLobbyBase(this: session);
      v86 = (const idDeclBot *)v85->GetLobbyUserBotData(this: v85, a2: (lobbyUserID_t *)v81);
      if ( v86 != nullptr )
        idPlayer::SetupBotComponent(this: Player, botDef: v86);
      if ( this->RegisterNewPlayer(this, a2: (idGameChallenge::playerData_t *)HIDWORD(v81), a3: Player, a4: initial)
        && this->gameMode != CHALLENGE_MODE_COOP )
      {
        v105[0] = (encounterGroupRole_t)Player->entityNumber;
        idList<idAnimWebBlendTree *,5>::Append(
          this: (idList<enum encounterGroupRole_t,5> *)&this->eventConnectList,
          obj: v105);
      }
    }
  }
LABEL_128:
  idClientGame::GenerateInputToPlayerIndexRouting(this: clientGame);
  challengeState = gameLocal->challengeState;
  if ( challengeState >= CHALLENGE_STATE_IN_PROGRESS && challengeState < CHALLENGE_STATE_GAME_OVER )
  {
    v88 = session->GetActingGameStateLobbyBase(this: session);
    if ( v88->GetMatchParms(this: v88)->gameType == 2 )
    {
      v89 = session->GetActingGameStateLobbyBase(this: session);
      if ( (v89->GetMatchParms(this: v89)->matchFlags & 4) != 0 )
      {
        v90 = session->GetTitleStorageInt_2(this: session, a2: "CHECK_SOLO_PLAY_IN_SECONDS", a3: 5);
        if ( gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) >= 1000 * v90 + this->startTime )
        {
          v91 = Sys_Milliseconds();
          if ( (unsigned __int8)idGameChallenge::AllClientsDisconnected(this) != 0
            && idClientGame::GetLocalPresentablePlayer(this: clientGame) != nullptr
            && gameLocal->challengeState < CHALLENGE_STATE_GAME_OVER
            && this->forceQuitGameTime == -1 )
          {
            v107 = (int)session->GetTitleStorageFloat_2(
                          this: session,
                          a2: "rankedForceQuitInSecondsWhenAlone",
                          a3: 30.0);
            this->forceQuitGameTime = 1000 * v107 + v91;
          }
          if ( this->forceQuitGameTime != -1 )
          {
            v92 = session->GetActingGameStateLobbyBase(this: session);
            if ( (v92->GetMatchParms(this: v92)->matchFlags & 0x80) == 0 || v91 >= this->forceQuitGameTime )
            {
              this->forceQuitGameTime = -1;
              if ( (unsigned __int8)idGameChallenge::CanPostStats(this) != 0
                && gameLocal->challengeState >= CHALLENGE_STATE_IN_PROGRESS )
              {
                if ( gameLocal->challengeState < CHALLENGE_STATE_GAME_OVER )
                  gameLocal->challengeState = CHALLENGE_STATE_GAME_OVER;
              }
              else
              {
                if ( this->players.listStatic == 0 || this->players.listStatic == 2 )
                {
                  v93 = this->players.list;
                  if ( v93 != nullptr )
                  {
                    v105[0] = (encounterGroupRole_t)this->players.list;
                    idMem::Free(this: &mem, ptr: v93, align: ALIGN_16);
                  }
                  this->players.list = nullptr;
                  this->players.size = 0;
                }
                this->players.num = 0;
                session->QuitMatch(this: session);
                ((void (__fastcall *)(idCommon *, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))common->AddDialog)(
                  a1: common,
                  a2: 78,
                  a3: 0,
                  a4: 0,
                  a5: 0,
                  a6: 0,
                  a7: 0,
                  a8: 0);
              }
            }
          }
        }
      }
    }
  }
  if ( this->fadeInFinishTime < idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) )
  {
    v94 = 0;
    if ( this->eventConnectList.num > 0 )
    {
      v95 = 0;
      do
      {
        idGameLocal::BroadcastUIStatusMessage(
          this: gameLocal,
          type: 37,
          numParams: 1,
          param1: this->eventConnectList.list[v95],
          param2: -1,
          param3: -1,
          param4: -1);
        ++v94;
        ++v95;
      }
      while ( v94 < this->eventConnectList.num );
    }
    if ( this->eventConnectList.listStatic == 0 || this->eventConnectList.listStatic == 2 )
    {
      v96 = this->eventConnectList.list;
      if ( v96 != nullptr )
      {
        v105[0] = (encounterGroupRole_t)this->eventConnectList.list;
        idMem::Free(this: &mem, ptr: v96, align: ALIGN_16);
      }
      this->eventConnectList.list = nullptr;
      this->eventConnectList.size = 0;
    }
    this->eventConnectList.num = 0;
    v97 = 0;
    if ( this->eventDisconnectList.num > 0 )
    {
      v98 = 0;
      do
      {
        idGameLocal::BroadcastUIStatusMessage(
          this: gameLocal,
          type: 38,
          numParams: 1,
          param1: this->eventDisconnectList.list[v98],
          param2: -1,
          param3: -1,
          param4: -1);
        ++v97;
        ++v98;
      }
      while ( v97 < this->eventDisconnectList.num );
    }
    if ( this->eventDisconnectList.listStatic == 0 || this->eventDisconnectList.listStatic == 2 )
    {
      v99 = this->eventDisconnectList.list;
      if ( v99 != nullptr )
      {
        v105[0] = (encounterGroupRole_t)this->eventDisconnectList.list;
        idMem::Free(this: &mem, ptr: v99, align: ALIGN_16);
      }
      this->eventDisconnectList.list = nullptr;
      this->eventDisconnectList.size = 0;
    }
    this->eventDisconnectList.num = 0;
  }
  if ( gc_forcePartnerLeft.valueInteger != 0
    && this->gameMode == CHALLENGE_MODE_COOP
    && gameLocal->challengeState < CHALLENGE_STATE_GAME_OVER )
  {
    if ( this->players.listStatic == 0 || this->players.listStatic == 2 )
    {
      v100 = this->players.list;
      if ( v100 != nullptr )
      {
        v105[0] = (encounterGroupRole_t)this->players.list;
        idMem::Free(this: &mem, ptr: v100, align: ALIGN_16);
      }
      this->players.list = nullptr;
      this->players.size = 0;
    }
    this->players.num = 0;
    session->QuitMatch(this: session);
    idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
    v113.num = 0;
    v113.size = 4;
    v113.granularity = 1;
    v113.list = (encounterGroupRole_t *)&v114;
    v113.memTag = 5;
    v113.listStatic = 1;
    v101 = idMem::AllocWithLocation(
             this: &mem,
             location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
             size: 0x10u,
             tag: TAG_SWF,
             zeroBuffer: false,
             align: ALIGN_16,
             heap: HEAP_DEFAULTHEAP);
    v105[0] = (encounterGroupRole_t)v101;
    if ( v101 != nullptr )
    {
      v102 = idGameChallenge_Coop::CastTo(c: (idGameChallenge_Coop *)this);
      v103 = v101 + 2;
      v101[1] = 0;
      v105[0] = (encounterGroupRole_t)(v101 + 2);
      *v101 = &`idGameChallenge::SyncPlayersWithLobbyUsers'::`2'::idSWFScriptFunction_LeaveGame::`vftable';
      v101[2] = 0x1FFF;
      if ( v102 != nullptr )
      {
        v105[0] = (encounterGroupRole_t)v102->entityNumber;
        v104 = (encounterGroupRole_t)v101;
        *v103 = (gameLocal->spawnIds.ptr[v105[0]] << 13) | v105[0];
      }
      else
      {
        *v103 = 0x1FFF;
        v104 = (encounterGroupRole_t)v101;
      }
      v101[3] = 61;
    }
    else
    {
      v104 = ROLE_NONE;
    }
    v105[0] = v104;
    idList<idAnimWebBlendTree *,5>::Append(this: &v113, obj: v105);
    *(_QWORD *)&v110.num = 4;
    v110.list = (idStrId *)v111;
    *(_DWORD *)&v110.granularity = 66817;
    memset(v111, 255, sizeof(v111));
    idStrId::Set(this: v112, key: "#str_swf_btn_continue");
    idList<idHandle<int,enum invalidAIEvent_t,-1>,5>::Append(this: &v110, obj: v112);
    v116.baseBuffer[0] = 0;
    v105[0] = (encounterGroupRole_t)&v116;
    v117 = 0;
    v116.len = 0;
    v116.data = &v117;
    v116.allocedAndFlag = -2147483392;
    idStr::operator=(this: &v116, text: &byte_8200D768);
    ((void (__fastcall *)(idCommon *, int, idList<enum encounterGroupRole_t,5> *, idList<idStrId,5> *, _DWORD, idStr *, int, _DWORD))common->AddDynamicDialog)(
      a1: common,
      a2: 61,
      a3: &v113,
      a4: &v110,
      a5: 0,
      a6: &v116,
      a7: 1,
      a8: 0);
    idMem::PopHeap(this: &mem);
    idCVar::SetBool(this: &gc_forcePartnerLeft, newValue: false, force: true);
    if ( v110.listStatic == 0 || v110.listStatic == 2 )
    {
      if ( v110.list != nullptr )
        idMem::Free(this: &mem, ptr: v110.list, align: ALIGN_16);
      v110.list = nullptr;
      v110.size = 0;
    }
    v110.num = 0;
    if ( v113.listStatic == 0 || v113.listStatic == 2 )
    {
      if ( v113.list != nullptr )
        idMem::Free(this: &mem, ptr: v113.list, align: ALIGN_16);
      v113.list = nullptr;
      v113.size = 0;
    }
    v113.num = 0;
  }
  if ( (v109.listStatic == 0 || v109.listStatic == 2) && v76 != nullptr )
    idMem::Free(this: &mem, ptr: v76, align: ALIGN_16);
}


// ========================================================================
// __unwind$505723
// EA  : 0x82C5958C
// RVA : 0x00C5958C
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

void _unwind_505723()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 704 + 144));
}


// ========================================================================
// __unwind$505724
// EA  : 0x82C595B4
// RVA : 0x00C595B4
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

void _unwind_505724()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 704 + 208));
}


// ========================================================================
// __unwind$505725
// EA  : 0x82C595DC
// RVA : 0x00C595DC
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

void _unwind_505725()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 704 + 112), tag: TAG_SWF);
}


// ========================================================================
// __unwind$505726
// EA  : 0x82C59608
// RVA : 0x00C59608
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

void _unwind_505726()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 704 + 160));
}


// ========================================================================
// __unwind$506944
// EA  : 0x82C59630
// RVA : 0x00C59630
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

void _unwind_506944()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v0 - 704 + 112));
}


// ========================================================================
// ?Think@idGameChallenge@@UAAXXZ
// EA  : 0x82C597B0
// RVA : 0x00C597B0
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

void __fastcall idGameChallenge::Think(idGameChallenge *this)
{
  idGameLocal *v2; // r3
  int v3; // r29
  int v4; // r26
  int v5; // r27
  idGameChallenge::playerData_t *v6; // r29
  int v7; // r10
  idPlayer *v8; // r3
  int challengeState; // r11
  challengeState_t v10; // r11

  if ( (this->thinkFlags & 1) == 0 )
    return;
  if ( idGameLocal::GetChallengeEntity(this: gameLocal) != this || !common->IsMultiplayer(this: common) )
  {
    idEntity::BecomeInactive(this: &this->idEntity, flags: 1);
    return;
  }
  idSpawnManager::Update(this: this->spawnManager);
  if ( gameLocal->challengeState >= CHALLENGE_STATE_IN_PROGRESS )
    idGameChallenge::SyncPlayersWithLobbyUsers(this, initial: false);
  this->ProcessPlayerStates(this);
  v2 = gameLocal;
  if ( gameLocal->challengeState == CHALLENGE_STATE_WAITING_TO_START )
  {
    v3 = this->GetPreGameDuration(this) + this->preGameTime;
    if ( gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) < v3 )
      return;
    this->BeginGame(this);
    v2 = gameLocal;
  }
  v4 = 0;
  if ( this->players.num > 0 )
  {
    v5 = 0;
    do
    {
      v6 = &this->players.list[v5];
      if ( v6->state == PLAYER_STATE_IN_PROGRESS
        && v2->spawnIds.ptr[v6->player.spawnId.value & 0x1FFF] == v6->player.spawnId.value >> 13 )
      {
        v7 = 4 * ((v6->player.spawnId.value & 0x1FFF) + 21563);
        if ( *(idGameLocal_vtbl **)((char *)&v2->__vftable + v7) != nullptr )
        {
          v8 = idPlayer::CastTo(c: *(idPlayer **)((char *)&v2->__vftable + v7));
          if ( v8 != nullptr && v8->playerHealth.IsDead_Impl(this: &v8->playerHealth) )
            this->SetPlayerState(
              this,
              a2: v6,
              a3: PLAYER_STATE_WAITING_TO_RESPAWN_FROM_DEATH,
              a4: this->spawnTimer + v6->respawnDelay);
          v2 = gameLocal;
        }
      }
      ++v4;
      ++v5;
    }
    while ( v4 < this->players.num );
  }
  challengeState = v2->challengeState;
  if ( challengeState >= 2 && challengeState < 6 )
  {
    this->SyncMigrationGameDataWithSession(this, a2: false);
    v2 = gameLocal;
  }
  v10 = v2->challengeState;
  if ( v10 == CHALLENGE_STATE_IN_PROGRESS
    || v10 == CHALLENGE_STATE_IN_PROGRESS_OVERTIME
    || v10 == CHALLENGE_STATE_END_OF_ROUND )
  {
    if ( v10 == CHALLENGE_STATE_IN_PROGRESS_OVERTIME )
    {
      if ( this->IsLeaderTied(this) && (unsigned __int8)idGameChallenge::AllClientsDisconnected(this) == 0 )
        goto LABEL_30;
    }
    else
    {
      if ( this->timeLimit <= 0 )
        goto LABEL_31;
      if ( v2->GetGameMs(this: v2, a2: GAMETIME_SCALED) < this->endTime )
      {
LABEL_30:
        v2 = gameLocal;
LABEL_31:
        if ( this->scoreLimit > 0 )
        {
          if ( this->ScoreLimitReached(this) )
            gameLocal->challengeState = CHALLENGE_STATE_GAME_OVER;
          v2 = gameLocal;
        }
        if ( this->players.num > 0 )
        {
          this->lastReviveThresholdTick = v2->GetGameMs(this: v2, a2: GAMETIME_SCALED);
          v2 = gameLocal;
        }
        goto LABEL_37;
      }
      if ( this->IsLeaderTied(this) && (unsigned __int8)idGameChallenge::AllClientsDisconnected(this) == 0 )
      {
        gameLocal->challengeState = CHALLENGE_STATE_IN_PROGRESS_OVERTIME;
        goto LABEL_30;
      }
    }
    gameLocal->challengeState = CHALLENGE_STATE_GAME_OVER;
    goto LABEL_30;
  }
LABEL_37:
  if ( v2->challengeState == CHALLENGE_STATE_GAME_OVER )
  {
    this->GameOver(this);
    this->EndGame(this);
    v2 = gameLocal;
  }
  if ( v2->challengeState == CHALLENGE_STATE_END_OF_ROUND )
  {
    this->EndRound(this);
    gameLocal->challengeState = CHALLENGE_STATE_START_NEW_ROUND;
    v2 = gameLocal;
  }
  if ( v2->challengeState == CHALLENGE_STATE_RESULTS )
  {
    if ( v2->GetGameMs(this: v2, a2: GAMETIME_SCALED) >= this->endTimeoutDuration + this->endTime )
    {
      common->ClearDialog(this: common, a2: GDM_MULTI_SELF_DESTRUCT, a3: nullptr, a4: 0);
      gameLocal->forceSingleView = false;
      gameLocal->challengeState = CHALLENGE_STATE_FINISH_MENU;
      this->FinishGame(this);
    }
    v2 = gameLocal;
  }
  if ( v2->challengeState == CHALLENGE_STATE_START_NEW_ROUND
    && v2->GetGameMs(this: v2, a2: GAMETIME_SCALED) >= this->roundEndTime + this->endTimeoutDuration )
  {
    this->StartRound(this);
    gameLocal->challengeState = CHALLENGE_STATE_IN_PROGRESS;
  }
  if ( gc_testStats.valueInteger != 0 )
  {
    this->PostStatsToLeaderboard(this);
    idCVar::SetBool(this: &gc_testStats, newValue: false, force: true);
  }
}


// ========================================================================
// ?Think@idGameChallenge_Coop@@UAAXXZ
// EA  : 0x82C59C80
// RVA : 0x00C59C80
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

void __fastcall idGameChallenge_Coop::Think(idGameChallenge_Coop *this)
{
  idPresentable *presentable; // r3
  idGameLocal *v3; // r11
  challengeState_t challengeState; // r10
  int v5; // r28
  int v6; // r31
  int value; // r9
  idPlayer *v8; // r3
  idPlayer *v9; // r3

  idGameChallenge::Think(this);
  presentable = this->presentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    presentable = this->presentable;
  }
  presentable->UpdateFX_3(this: presentable, a2: 1.0, a3: 0.0);
  v3 = gameLocal;
  challengeState = gameLocal->challengeState;
  if ( challengeState != CHALLENGE_STATE_WAITING_TO_START
    && (this->thinkFlags & 1) != 0
    && challengeState == CHALLENGE_STATE_IN_PROGRESS )
  {
    v5 = 0;
    if ( gameLocal->forceSingleView )
    {
      gameLocal->forceSingleView = false;
      v3 = gameLocal;
    }
    if ( this->players.num > 0 )
    {
      v6 = 0;
      do
      {
        value = this->players.list[v6].player.spawnId.value;
        if ( v3->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
        {
          v8 = (idPlayer *)v3->entities.ptr[value & 0x1FFF];
          if ( v8 != nullptr )
          {
            v9 = idPlayer::CastTo(c: v8);
            if ( v9 != nullptr )
              v9->playerHealth.IsDead_Impl(this: &v9->playerHealth);
            v3 = gameLocal;
          }
        }
        ++v5;
        ++v6;
      }
      while ( v5 < this->players.num );
    }
  }
}


// ========================================================================
// ?Call@fakeLeaderboardCallback@@UAAXXZ
// EA  : 0x82C59DA8
// RVA : 0x00C59DA8
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

void __fastcall fakeLeaderboardCallback::Call(fakeLeaderboardCallback *this)
{
  int v2; // r26
  int v3; // r28
  int v4; // r29
  int i; // r31

  v2 = 0;
  if ( this->rows.num > 0 )
  {
    v3 = 0;
    v4 = 7;
    do
    {
      idLib::Printf(fmt: "  %d ^3%s  ", LODWORD(this->rows.list[v3].rank), this->rows.list[v3].name.data);
      for ( i = 0; i < this->def->numColumns; ++i )
        idLib::Printf(fmt: "^%d%d ", i + 4, *((_DWORD *)&this->rows.list->hasAttachment + 2 * v4 + 2 * i + 1));
      idLib::Printf(fmt: "\n");
      ++v2;
      ++v3;
      v4 += 24;
    }
    while ( v2 < this->rows.num );
  }
  idLib::Printf(fmt: "\n\n");
}


// ========================================================================
// ?MPTestLeaderboardDownloadCoop_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82C5A060
// RVA : 0x00C5A060
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

void __fastcall MPTestLeaderboardDownloadCoop_f(const idCmdArgs *args)
{
  int v2; // r27
  int v3; // r29
  idLeaderboardCallback *v4; // r3
  _BYTE v5[30]; // [sp+60h] [-90h] BYREF
  __int16 v6; // [sp+7Eh] [-72h]
  int v7; // [sp+80h] [-70h]
  int v8; // [sp+84h] [-6Ch]
  _BYTE v9[30]; // [sp+90h] [-60h] BYREF
  __int16 v10; // [sp+AEh] [-42h]
  int v11; // [sp+B0h] [-40h]
  int v12; // [sp+B4h] [-3Ch]

  v2 = 0;
  if ( args->argc > 1 )
    v2 = atol(nptr: args->argv[1]);
  v3 = 0;
  if ( args->argc > 2 )
    v3 = atol(nptr: args->argv[2]);
  if ( v2 >= 0 )
  {
    idLib::Printf(fmt: "Getting coop leaderboard %d\n", v2);
    *(_DWORD *)&v9[4] = 0;
    *(_DWORD *)&v9[8] = -1;
    *(_DWORD *)&v9[12] = -1;
    v10 = 1280;
    memset(&v9[16], 0, 14);
    v11 = -1;
    v12 = 0;
    *(_DWORD *)v9 = &fakeLeaderboardCallback::`vftable';
    session->LeaderboardDownload(
      this: session,
      a2: 0,
      a3: rageMPCoopLeaderboards[v2],
      a4: v3,
      a5: 10,
      a6: (const idLeaderboardCallback *)v9);
    v4 = (idLeaderboardCallback *)v9;
  }
  else
  {
    *(_DWORD *)&v5[4] = 0;
    *(_DWORD *)&v5[8] = -1;
    *(_DWORD *)&v5[12] = -1;
    v6 = 1280;
    memset(&v5[16], 0, 14);
    v7 = -1;
    v8 = 0;
    *(_DWORD *)v5 = &fakeLeaderboardCallback::`vftable';
    session->LeaderboardDownload(
      this: session,
      a2: 0,
      a3: &rageTestLeaderboardScore2,
      a4: v3,
      a5: 10,
      a6: (const idLeaderboardCallback *)v5);
    v4 = (idLeaderboardCallback *)v5;
  }
  idLeaderboardCallback::~idLeaderboardCallback(this: v4);
}


// ========================================================================
// __unwind$507954
// EA  : 0x82C5A1D8
// RVA : 0x00C5A1D8
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

void _unwind_507954()
{
  int v0; // r12

  idCallbackBindMem<idMainMenu>::~idCallbackBindMem<idMainMenu>(this: (idCallback *)(v0 - 240 + 96));
}


// ========================================================================
// __unwind$507927
// EA  : 0x82C5A200
// RVA : 0x00C5A200
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

void _unwind_507927()
{
  int v0; // r12

  fakeLeaderboardCallback::~fakeLeaderboardCallback(this: (fakeLeaderboardCallback *)(v0 - 240 + 96));
}


// ========================================================================
// __unwind$508005
// EA  : 0x82C5A228
// RVA : 0x00C5A228
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

void _unwind_508005()
{
  int v0; // r12

  idCallbackBindMem<idMainMenu>::~idCallbackBindMem<idMainMenu>(this: (idCallback *)(v0 - 240 + 144));
}


// ========================================================================
// __unwind$507928
// EA  : 0x82C5A250
// RVA : 0x00C5A250
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

void _unwind_507928()
{
  int v0; // r12

  fakeLeaderboardCallback::~fakeLeaderboardCallback(this: (fakeLeaderboardCallback *)(v0 - 240 + 144));
}


// ========================================================================
// ?MPTestLeaderboardDownloadRally_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82C5A280
// RVA : 0x00C5A280
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

void __fastcall MPTestLeaderboardDownloadRally_f(const idCmdArgs *args)
{
  unsigned int v2; // r27
  int v3; // r26
  const leaderboardDefinition_t *v4; // r5
  idLeaderboardCallback v5[2]; // [sp+60h] [-60h] BYREF

  v2 = 0;
  v3 = 0;
  if ( args->argc > 1 )
    v2 = atol(nptr: args->argv[1]);
  if ( args->argc > 2 )
    v3 = atol(nptr: args->argv[2]);
  if ( v2 > 3 )
  {
    idLib::Printf(fmt: "Downloading Triad ");
    v4 = &rageLeaderboardTriad;
  }
  else if ( v2 == 1 )
  {
    idLib::Printf(fmt: "Downloading VDM ");
    v4 = &rageLeaderboardVDM;
  }
  else if ( v2 == 2 )
  {
    idLib::Printf(fmt: "Downloading Bully ");
    v4 = &rageLeaderboardBully;
  }
  else if ( v2 != 0 )
  {
    idLib::Printf(fmt: "Downloading Meteor ");
    v4 = &rageLeaderboardMeteor;
  }
  else
  {
    idLib::Printf(fmt: "Downloading RallyScore ");
    v4 = &rageLeaderboardRally;
  }
  v5[0].def = nullptr;
  v5[0].rows.granularity = 0;
  v5[0].startIndex = -1;
  v5[0].localIndex = -1;
  v5[0].rows.memTag = 5;
  v5[0].rows.listStatic = 0;
  v5[0].rows.list = nullptr;
  v5[0].rows.size = 0;
  v5[0].rows.num = 0;
  v5[0].numRowsInLeaderboard = -1;
  v5[0].errorCode = LEADERBOARD_ERROR_NONE;
  v5[0].__vftable = (idLeaderboardCallback_vtbl *)&fakeLeaderboardCallback::`vftable';
  session->LeaderboardDownload(this: session, a2: 0, a3: v4, a4: v3, a5: 10, a6: v5);
  idLeaderboardCallback::~idLeaderboardCallback(this: v5);
}


// ========================================================================
// __unwind$508111
// EA  : 0x82C5A3E8
// RVA : 0x00C5A3E8
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

void _unwind_508111()
{
  int v0; // r12

  idCallbackBindMem<idMainMenu>::~idCallbackBindMem<idMainMenu>(this: (idCallback *)(v0 - 192 + 96));
}


// ========================================================================
// __unwind$508085
// EA  : 0x82C5A410
// RVA : 0x00C5A410
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

void _unwind_508085()
{
  int v0; // r12

  fakeLeaderboardCallback::~fakeLeaderboardCallback(this: (fakeLeaderboardCallback *)(v0 - 192 + 96));
}


// ========================================================================
// ?OnActivate@idGameChallenge@@UAAXPAVidEntity@@@Z
// EA  : 0x82C5A5C8
// RVA : 0x00C5A5C8
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

void __fastcall idGameChallenge::OnActivate(idGameChallenge *this, idEntity *_activator)
{
  int v3; // r31
  int v4; // ctr
  int *p_timeTillNewPlayerCanTake; // r11
  int v6; // r29
  idPlayer *Player; // r5
  idLobbyBase *v8; // r3
  const idMatchParameters *v9; // r3
  bool v10; // r3
  idGameChallenge_vtbl *v11; // r11
  const idSoundShader *gameMusic; // r5
  idGameChallenge::playerData_t v13; // [sp+50h] [-90h] BYREF

  if ( !this->gcInitialized )
  {
    v3 = 0;
    this->bGameFailed = false;
    this->forceQuitGameTime = -1;
    idRageMetrics::Reset(this: clientGame->rageMetrics);
    v4 = 6;
    p_timeTillNewPlayerCanTake = &v13.timeTillNewPlayerCanTake;
    memset(&v13.respawnDelay, 0, 25);
    memset(&v13.state, 0, 13);
    v13.player.spawnId.value = 0x1FFF;
    v13.lastKiller = -1;
    v13.timeTillNewPlayerCanTake = -1;
    do
    {
      *++p_timeTillNewPlayerCanTake = 0;
      --v4;
    }
    while ( v4 != 0 );
    idList<idGameChallenge::playerData_t,5>::SetNum(this: &this->players, newNum: 6, initValue: &v13);
    v6 = 0;
    do
    {
      Player = idGameLocal::GetPlayer(this: gameLocal, i: v6);
      if ( Player != nullptr )
        this->RegisterNewPlayer(this, a2: &this->players.list[v3], a3: Player, a4: true);
      ++v3;
      ++v6;
    }
    while ( v3 < 6 );
    if ( (unsigned int)idLib::production <= PROD_BUILDING )
      this->LoadMultiplayerDecls(this);
    v8 = session->GetActingGameStateLobbyBase(this: session);
    v9 = v8->GetMatchParms(this: v8);
    idGameChallenge::SetMatchParms(this, parms: v9);
    idRageMetrics::BeginGame(this: clientGame->rageMetrics, challenge: this);
    this->SyncMigrationGameDataWithSession(this, a2: true);
    idEntity::BecomeActive(this: &this->idEntity, flags: 1);
    v10 = this->HasPreGame(this);
    v11 = this->__vftable;
    if ( v10 )
      v11->StartPreGame(this);
    else
      v11->BeginGame(this);
    gameMusic = this->gameMusic;
    if ( gameMusic != nullptr )
      idEntity::StartSoundShader(
        this: &this->idEntity,
        channel: SND_CHANNEL_MUSIC1,
        shader: gameMusic,
        soundShaderFlags: SSF_GLOBAL|SSF_OMNIDIRECTIONAL,
        peerMask: 0xFFu);
    this->gcInitialized = true;
  }
}


// ========================================================================
// ?OnActivate@idGameChallenge_Coop@@UAAXPAVidEntity@@@Z
// EA  : 0x82C5A7C8
// RVA : 0x00C5A7C8
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

void __fastcall idGameChallenge_Coop::OnActivate(idGameChallenge_Coop *this, idEntity *_activator)
{
  if ( !this->gcInitialized )
  {
    idGameChallenge::OnActivate(this, _activator);
    this->objectiveStartTimeMS = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
  }
}


// ========================================================================
// ?OnActivate@idGameChallenge_PVP@@UAAXPAVidEntity@@@Z
// EA  : 0x82C5A820
// RVA : 0x00C5A820
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

void __fastcall idGameChallenge_PVP::OnActivate(idGameChallenge_PVP *this, idEntity *_activator)
{
  if ( !this->gcInitialized )
    idGameChallenge::OnActivate(this, _activator);
}


// ========================================================================
// ??1idGameChallenge@@UAA@XZ
// EA  : 0x82C5AA28
// RVA : 0x00C5AA28
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

void __fastcall idGameChallenge::~idGameChallenge(idGameChallenge *this)
{
  idDoomSpawnManager *spawnManager; // r3

  this->__vftable = (idGameChallenge_vtbl *)&idGameChallenge::`vftable';
  spawnManager = this->spawnManager;
  if ( spawnManager != nullptr )
    ((void (__fastcall *)(idDoomSpawnManager *, int))spawnManager->dtr_idSpawnManager)(a1: spawnManager, a2: 1);
  this->spawnManager = nullptr;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->eventDisconnectList);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->eventConnectList);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->spawnNodeGroup);
  idStaticList<idGameChallenge::teamData_t,5>::~idStaticList<idGameChallenge::teamData_t,5>(this: &this->teams);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->players);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->teamInfo);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->spawnPoints);
  idEntity::~idEntity(this: &this->idEntity);
}


// ========================================================================
// __unwind$508424
// EA  : 0x82C5AAD4
// RVA : 0x00C5AAD4
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

void _unwind_508424()
{
  int v0; // r12

  idEntity::~idEntity(this: *(idEntity **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$508425
// EA  : 0x82C5AAFC
// RVA : 0x00C5AAFC
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

void _unwind_508425()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 828));
}


// ========================================================================
// __unwind$508426
// EA  : 0x82C5AB28
// RVA : 0x00C5AB28
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

void _unwind_508426()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 900));
}


// ========================================================================
// __unwind$508427
// EA  : 0x82C5AB54
// RVA : 0x00C5AB54
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

void _unwind_508427()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 920));
}


// ========================================================================
// __unwind$508428_0
// EA  : 0x82C5AB80
// RVA : 0x00C5AB80
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

void _unwind_508428_0()
{
  int v0; // r12

  idStaticList<idGameChallenge::teamData_t,5>::~idStaticList<idGameChallenge::teamData_t,5>(this: (idStaticList<idGameChallenge::teamData_t,5> *)(*(_DWORD *)(v0 - 112 + 132) + 1472));
}


// ========================================================================
// __unwind$508429_0
// EA  : 0x82C5ABAC
// RVA : 0x00C5ABAC
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

void _unwind_508429_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 1676));
}


// ========================================================================
// __unwind$508430
// EA  : 0x82C5ABD8
// RVA : 0x00C5ABD8
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

void _unwind_508430()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 1704));
}


// ========================================================================
// __unwind$508431_0
// EA  : 0x82C5AC04
// RVA : 0x00C5AC04
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

void _unwind_508431_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 1744));
}


// ========================================================================
// ?Clone@fakeLeaderboardCallback@@UBAPAV1@XZ
// EA  : 0x82C5AC38
// RVA : 0x00C5AC38
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

fakeLeaderboardCallback *__fastcall fakeLeaderboardCallback::Clone(fakeLeaderboardCallback *this)
{
  idLeaderboardCallback *v2; // r3
  _DWORD *v3; // r30

  v2 = (idLeaderboardCallback *)idMem::AllocWithLocation(
                                  this: &mem,
                                  location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                  size: 0x28u,
                                  tag: TAG_NEW,
                                  zeroBuffer: false,
                                  align: ALIGN_16,
                                  heap: HEAP_DEFAULTHEAP);
  v3 = &v2->__vftable;
  if ( v2 == nullptr )
    return nullptr;
  idLeaderboardCallback::idLeaderboardCallback(this: v2, __that: this);
  *v3 = &fakeLeaderboardCallback::`vftable';
  return (fakeLeaderboardCallback *)v3;
}


// ========================================================================
// __unwind$508755
// EA  : 0x82C5ACAC
// RVA : 0x00C5ACAC
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

void __fastcall _unwind_508755(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ??0idGameChallenge@@QAA@XZ
// EA  : 0x82C5AD90
// RVA : 0x00C5AD90
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

idGameChallenge *__fastcall idGameChallenge::idGameChallenge(idGameChallenge *this)
{
  char **p_teams; // r24

  idEntity::idEntity(this: &this->idEntity);
  this->timeLimit = 0;
  this->respawnDelay = 3.0;
  this->startActive = true;
  this->__vftable = (idGameChallenge_vtbl *)&idGameChallenge::`vftable';
  this->scoreLimit = 0;
  this->numLives = 0;
  *(_WORD *)&this->countupTime = 1;
  this->baseTime = 0;
  this->spawnPoints.list = nullptr;
  this->spawnPoints.granularity = 0;
  this->spawnPoints.memTag = 5;
  this->spawnPoints.listStatic = 0;
  this->spawnPoints.size = 0;
  this->spawnPoints.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->spawnPoints);
  this->minimumPlayers = 1;
  this->leaderBoard = -1;
  this->useSpectatorCamera = true;
  this->requireLoadoutSelection = false;
  this->initialSpectatorCamPos.spawnId.value = 0x1FFF;
  this->initialSpectatorCamLookAt.spawnId.value = 0x1FFF;
  this->gameMusic = nullptr;
  this->gameOverSound = nullptr;
  this->failedGameOverSound = nullptr;
  this->fxDecl = nullptr;
  this->voCallout = nullptr;
  this->killScore = 1;
  this->suicideScore = 1;
  this->suicideSpawnDelay = 1500;
  this->spawnTimer = 10000;
  this->teamInfo.list = nullptr;
  this->teamInfo.granularity = 0;
  this->teamInfo.memTag = 5;
  this->teamInfo.listStatic = 0;
  this->teamInfo.size = 0;
  this->teamInfo.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->teamInfo);
  this->botGameManagerType = BOT_GAME_MANAGER_TYPE_MAX;
  idStaticList<idGameChallenge::playerData_t,6>::idStaticList<idGameChallenge::playerData_t,6>(this: &this->players);
  this->startTime = 0;
  this->endTime = 0;
  this->originalEndTime = 0;
  this->preGameTime = 0;
  this->roundEndTime = 0;
  this->gameMode = CHALLENGE_MODE_NORMAL;
  this->bGameFailed = false;
  this->gameFailedText.index = -1;
  this->failedReason = 0;
  this->bFinishGameExit = true;
  this->incapacitated = true;
  this->lastReviveThresholdTick = 0;
  this->mapLoadFinished = false;
  p_teams = (char **)&this->teams;
  this->forceQuitGameTime = -1;
  idStaticList<idGameChallenge::teamData_t,5>::idStaticList<idGameChallenge::teamData_t,5>(this: &this->teams);
  this->gcInitialized = false;
  this->checkWorldCollisionOnSpawn = false;
  this->spawnManager = nullptr;
  this->spawnNodeGroup.nodes.list = nullptr;
  this->spawnNodeGroup.nodes.granularity = 0;
  this->spawnNodeGroup.nodes.memTag = 5;
  this->spawnNodeGroup.nodes.listStatic = 0;
  this->spawnNodeGroup.nodes.size = 0;
  this->spawnNodeGroup.nodes.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->spawnNodeGroup);
  this->spawnNodeGroup.approximateLocationCount = 0;
  this->wasMigratedGame = false;
  this->migratedTime = 0;
  this->eventConnectList.size = 6;
  this->eventConnectList.num = 0;
  this->eventConnectList.granularity = 1;
  this->eventConnectList.list = this->eventConnectList.staticList;
  this->eventConnectList.memTag = 5;
  this->eventConnectList.listStatic = 1;
  this->eventDisconnectList.size = 6;
  this->eventDisconnectList.num = 0;
  this->eventDisconnectList.granularity = 1;
  this->eventDisconnectList.list = this->eventDisconnectList.staticList;
  this->eventDisconnectList.memTag = 5;
  this->eventDisconnectList.listStatic = 1;
  this->fadeInFinishTime = 0;
  this->reviveThreshold = 2.0;
  if ( this->teams.listStatic == 0 || this->teams.listStatic == 2 )
  {
    if ( *p_teams != nullptr )
      idListArrayDelete<idSpawnablePropManager::spawnables_t>(ptr: *p_teams, num: this->teams.size);
    *p_teams = nullptr;
    this->teams.size = 0;
  }
  this->teams.num = 0;
  this->endTimeoutDuration = gc_results_time.valueInteger;
  memset(Dst: this->eventConnectList.list, Val: 0, Size: 4 * this->eventConnectList.size);
  memset(Dst: this->eventDisconnectList.list, Val: 0, Size: 4 * this->eventDisconnectList.size);
  idEventReceiver::AddEventListener(this: clientGame->rageMetrics, listener: &this->idEntity);
  return this;
}


// ========================================================================
// __unwind$508822
// EA  : 0x82C5B010
// RVA : 0x00C5B010
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

void _unwind_508822()
{
  int v0; // r12

  idEntity::~idEntity(this: *(idEntity **)(v0 - 160 + 180));
}


// ========================================================================
// __unwind$508823
// EA  : 0x82C5B038
// RVA : 0x00C5B038
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

void _unwind_508823()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 828));
}


// ========================================================================
// __unwind$508824
// EA  : 0x82C5B064
// RVA : 0x00C5B064
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

void _unwind_508824()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 900));
}


// ========================================================================
// __unwind$508825
// EA  : 0x82C5B090
// RVA : 0x00C5B090
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

void _unwind_508825()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 920));
}


// ========================================================================
// __unwind$508826
// EA  : 0x82C5B0BC
// RVA : 0x00C5B0BC
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

void _unwind_508826()
{
  int v0; // r12

  idStaticList<idGameChallenge::teamData_t,5>::~idStaticList<idGameChallenge::teamData_t,5>(this: (idStaticList<idGameChallenge::teamData_t,5> *)(*(_DWORD *)(v0 - 160 + 180) + 1472));
}


// ========================================================================
// __unwind$508827
// EA  : 0x82C5B0E8
// RVA : 0x00C5B0E8
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

void _unwind_508827()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 1676));
}


// ========================================================================
// __unwind$508828
// EA  : 0x82C5B114
// RVA : 0x00C5B114
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

void _unwind_508828()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 1704));
}


// ========================================================================
// __unwind$508829
// EA  : 0x82C5B140
// RVA : 0x00C5B140
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

void _unwind_508829()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 1744));
}


// ========================================================================
// ??0idGameChallenge_Coop@@QAA@XZ
// EA  : 0x82C5B178
// RVA : 0x00C5B178
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

idGameChallenge_Coop *__fastcall idGameChallenge_Coop::idGameChallenge_Coop(idGameChallenge_Coop *this)
{
  idGameChallenge::idGameChallenge(this);
  this->__vftable = (idGameChallenge_Coop_vtbl *)&idGameChallenge_Coop::`vftable';
  this->collectibleList.list = nullptr;
  this->collectibleList.granularity = 0;
  this->collectibleList.memTag = 5;
  this->collectibleList.listStatic = 0;
  this->collectibleList.size = 0;
  this->collectibleList.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->collectibleList);
  this->numCollectiblesToComplete = -1;
  idStrId::Set(this: &this->collectibleStatusMessage, key: "#str_online_collect_status");
  this->specialCollectible.found = false;
  this->specialCollectible.collectible.spawnId.value = 0x1FFF;
  this->useUniqueSpawnpoints = false;
  this->bObjectiveActive = false;
  this->objectiveStartTimeMS = 0;
  this->totalTime = 0;
  this->objectiveScore = 0;
  this->objectiveParScore = 0;
  this->objectiveParTimeMS = 0;
  this->objectiveText.index = -1;
  this->scoreRating.list = nullptr;
  this->scoreRating.granularity = 0;
  this->scoreRating.memTag = 5;
  this->scoreRating.listStatic = 0;
  this->scoreRating.size = 0;
  this->scoreRating.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->scoreRating);
  this->coopModelDefPlayer1 = nullptr;
  this->coopModelDefPlayer2 = nullptr;
  this->gameMode = CHALLENGE_MODE_COOP;
  this->useSpectatorCamera = false;
  return this;
}


// ========================================================================
// __unwind$509039
// EA  : 0x82C5B260
// RVA : 0x00C5B260
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

void _unwind_509039()
{
  int v0; // r12

  idGameChallenge::~idGameChallenge(this: *(idGameChallenge **)(v0 - 144 + 164));
}


// ========================================================================
// __unwind$509040
// EA  : 0x82C5B288
// RVA : 0x00C5B288
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

void _unwind_509040()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 1792));
}


// ========================================================================
// ??0idGameChallenge_PVP@@QAA@XZ
// EA  : 0x82C5B3E0
// RVA : 0x00C5B3E0
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

idGameChallenge_PVP *__fastcall idGameChallenge_PVP::idGameChallenge_PVP(idGameChallenge_PVP *this)
{
  char *list; // r3

  idGameChallenge::idGameChallenge(this);
  this->teamNoneModelDef = nullptr;
  this->__vftable = (idGameChallenge_PVP_vtbl *)&idGameChallenge_PVP::`vftable';
  this->teamRedModelDef = nullptr;
  this->teamBlueModelDef = nullptr;
  this->teamGreenModelDef = nullptr;
  this->teamYellowModelDef = nullptr;
  this->gameMode = CHALLENGE_MODE_DM;
  this->useSpectatorCamera = false;
  this->isTeamGame = false;
  this->killScore = 1;
  if ( this->teams.listStatic == 0 || this->teams.listStatic == 2 )
  {
    list = (char *)this->teams.list;
    if ( list != nullptr )
      idListArrayDelete<idSpawnablePropManager::spawnables_t>(ptr: list, num: this->teams.size);
    this->teams.list = nullptr;
    this->teams.size = 0;
  }
  this->teams.num = 0;
  return this;
}


// ========================================================================
// __unwind$509164
// EA  : 0x82C5B478
// RVA : 0x00C5B478
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

void _unwind_509164()
{
  int v0; // r12

  idGameChallenge::~idGameChallenge(this: *(idGameChallenge **)(v0 - 112 + 132));
}


// ========================================================================
// ??0idGameChallenge_DM_FFA@@QAA@XZ
// EA  : 0x82C5B508
// RVA : 0x00C5B508
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

idGameChallenge_DM_FFA *__fastcall idGameChallenge_DM_FFA::idGameChallenge_DM_FFA(idGameChallenge_DM_FFA *this)
{
  char *list; // r3

  idGameChallenge_PVP::idGameChallenge_PVP(this);
  this->killScore = 1;
  this->isTeamGame = false;
  this->__vftable = (idGameChallenge_DM_FFA_vtbl *)&idGameChallenge_DM_FFA::`vftable';
  this->gameMode = CHALLENGE_MODE_DM;
  this->requireLoadoutSelection = true;
  this->useSpectatorCamera = true;
  if ( this->teams.listStatic == 0 || this->teams.listStatic == 2 )
  {
    list = (char *)this->teams.list;
    if ( list != nullptr )
      idListArrayDelete<idSpawnablePropManager::spawnables_t>(ptr: list, num: this->teams.size);
    this->teams.list = nullptr;
    this->teams.size = 0;
  }
  this->teams.num = 0;
  return this;
}


// ========================================================================
// __unwind$509234
// EA  : 0x82C5B590
// RVA : 0x00C5B590
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

void _unwind_509234()
{
  int v0; // r12

  idGameChallenge_DM::~idGameChallenge_DM(this: *(idGameChallenge_DM **)(v0 - 112 + 132));
}


// ========================================================================
// ??0idGameChallenge_DM_TDM@@QAA@XZ
// EA  : 0x82C5B5C0
// RVA : 0x00C5B5C0
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

idGameChallenge_DM_TDM *__fastcall idGameChallenge_DM_TDM::idGameChallenge_DM_TDM(idGameChallenge_DM_TDM *this)
{
  int size; // r11

  idGameChallenge_PVP::idGameChallenge_PVP(this);
  this->isTeamGame = true;
  this->__vftable = (idGameChallenge_DM_TDM_vtbl *)&idGameChallenge_DM_TDM::`vftable';
  this->useSpectatorCamera = false;
  this->gameMode = CHALLENGE_MODE_DM;
  this->killScore = 1;
  if ( this->teams.size >= 2
    || (unsigned __int8)idList<idGameChallenge::teamData_t,5>::Resize(this: &this->teams, newsize: 2) != 0 )
  {
    size = this->teams.size;
    if ( size > 2 )
      size = 2;
    this->teams.num = size;
  }
  return this;
}


// ========================================================================
// __unwind$509302
// EA  : 0x82C5B650
// RVA : 0x00C5B650
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

void _unwind_509302()
{
  int v0; // r12

  idGameChallenge_DM::~idGameChallenge_DM(this: *(idGameChallenge_DM **)(v0 - 112 + 132));
}


// ========================================================================
// `dynamic initializer for 'gc_friendlyFire''
// EA  : 0x83376D70
// RVA : 0x01376D70
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__gc_friendlyFire__()
{
  idCVar::idCVar(
    this: &gc_friendlyFire,
    name: "gc_friendlyFire",
    value: "0",
    flags: 1,
    description: "1 = Shooting teammates will hurt them.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__gc_friendlyFire__);
}


// ========================================================================
// `dynamic initializer for 'gc_spectatorCamDuration''
// EA  : 0x83376DC8
// RVA : 0x01376DC8
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__gc_spectatorCamDuration__()
{
  idCVar::idCVar(
    this: &gc_spectatorCamDuration,
    name: "gc_spectatorCamDuration",
    value: "30000",
    flags: 2,
    description: "Duration of spectator mode in MS.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__gc_spectatorCamDuration__);
}


// ========================================================================
// `dynamic initializer for 'gc_preGameDuration''
// EA  : 0x83376E20
// RVA : 0x01376E20
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__gc_preGameDuration__()
{
  idCVar::idCVar(
    this: &gc_preGameDuration,
    name: "gc_preGameDuration",
    value: "3000",
    flags: 2,
    description: "Duration of pre-game in MS.  Controls the Waiting for Players... duration",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__gc_preGameDuration__);
}


// ========================================================================
// `dynamic initializer for 'gc_preGameLoadoutDelay''
// EA  : 0x83376E78
// RVA : 0x01376E78
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__gc_preGameLoadoutDelay__()
{
  idCVar::idCVar(
    this: &gc_preGameLoadoutDelay,
    name: "gc_preGameLoadoutDelay",
    value: "10000",
    flags: 2,
    description: "Duration of pre-game loadout delay.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__gc_preGameLoadoutDelay__);
}


// ========================================================================
// `dynamic initializer for 'gc_preGameDurationCoop''
// EA  : 0x83376ED0
// RVA : 0x01376ED0
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__gc_preGameDurationCoop__()
{
  idCVar::idCVar(
    this: &gc_preGameDurationCoop,
    name: "gc_preGameDurationCoop",
    value: "5000",
    flags: 2,
    description: "Duration of pre-game for coop in MS.  Controls the Waiting for Players... duration",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__gc_preGameDurationCoop__);
}


// ========================================================================
// `dynamic initializer for 'gc_results_time''
// EA  : 0x83376F28
// RVA : 0x01376F28
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__gc_results_time__()
{
  idCVar::idCVar(
    this: &gc_results_time,
    name: "gc_results_time",
    value: "20000",
    flags: 2,
    description: "Time in MS for results screen",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__gc_results_time__);
}


// ========================================================================
// `dynamic initializer for 'gc_reviveThreshold''
// EA  : 0x83376F80
// RVA : 0x01376F80
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__gc_reviveThreshold__()
{
  idCVar::idCVar(
    this: &gc_reviveThreshold,
    name: "gc_reviveThreshold",
    value: "2.0",
    flags: 4,
    description: "Threshold of time to game over if both players are down (in seconds). Time of 0 means infinite",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__gc_reviveThreshold__);
}


// ========================================================================
// `dynamic initializer for 'gc_failedRestartTime''
// EA  : 0x83376FD8
// RVA : 0x01376FD8
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__gc_failedRestartTime__()
{
  idCVar::idCVar(
    this: &gc_failedRestartTime,
    name: "gc_failedRestartTime",
    value: "15",
    flags: 2,
    description: "In seconds, the time that the game will take before restarting when it has failed",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__gc_failedRestartTime__);
}


// ========================================================================
// `dynamic initializer for 'gc_testStats''
// EA  : 0x83377030
// RVA : 0x01377030
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__gc_testStats__()
{
  idCVar::idCVar(
    this: &gc_testStats,
    name: "gc_testStats",
    value: "0",
    flags: 1,
    description: "Test uploading leaderboard stats",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__gc_testStats__);
}


// ========================================================================
// `dynamic initializer for 'gc_forcePartnerLeft''
// EA  : 0x83377088
// RVA : 0x01377088
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__gc_forcePartnerLeft__()
{
  idCVar::idCVar(
    this: &gc_forcePartnerLeft,
    name: "gc_forcePartnerLeft",
    value: "0",
    flags: 1,
    description: "Force the partner left scenario",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__gc_forcePartnerLeft__);
}


// ========================================================================
// `dynamic initializer for 'cg_forceStats''
// EA  : 0x833770E0
// RVA : 0x013770E0
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__cg_forceStats__()
{
  idCVar::idCVar(
    this: &cg_forceStats,
    name: "cg_forceStats",
    value: "0",
    flags: 1,
    description: "If true, stats will be posted, xp will be awarded, even in games where it normally would not.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__cg_forceStats__);
}


// ========================================================================
// `dynamic initializer for 'gc_forceSpawnFail''
// EA  : 0x83377138
// RVA : 0x01377138
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__gc_forceSpawnFail__()
{
  idCVar::idCVar(
    this: &gc_forceSpawnFail,
    name: "gc_forceSpawnFail",
    value: "0",
    flags: 1,
    description: "Force spawns to be at this spawn index.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__gc_forceSpawnFail__);
}


// ========================================================================
// `dynamic initializer for 'gc_spawnDebug''
// EA  : 0x83377190
// RVA : 0x01377190
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__gc_spawnDebug__()
{
  idCVar::idCVar(
    this: &gc_spawnDebug,
    name: "gc_spawnDebug",
    value: "1",
    flags: 1,
    description: "Force spawns to fail.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__gc_spawnDebug__);
}


// ========================================================================
// `dynamic initializer for 'gc_hostMigration_debug''
// EA  : 0x833771E8
// RVA : 0x013771E8
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__gc_hostMigration_debug__()
{
  idCVar::idCVar(
    this: &gc_hostMigration_debug,
    name: "gc_hostMigration_debug",
    value: "1",
    flags: 1,
    description: "Debugs host migration game data on the game code side",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__gc_hostMigration_debug__);
}


// ========================================================================
// `dynamic initializer for 'gc_useLoadoutForPvp''
// EA  : 0x83377240
// RVA : 0x01377240
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__gc_useLoadoutForPvp__()
{
  idCVar::idCVar(
    this: &gc_useLoadoutForPvp,
    name: "gc_useLoadoutForPvp",
    value: "0",
    flags: 1,
    description: "If true, on foot pvp will use loadouts",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__gc_useLoadoutForPvp__);
}


// ========================================================================
// `dynamic initializer for 'MPTestSpawns_v''
// EA  : 0x83377298
// RVA : 0x01377298
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__MPTestSpawns_v__()
{
  return idCommandLink::idCommandLink(
           this: &MPTestSpawns_v,
           cmdName: "MPTestSpawns",
           function: MPTestSpawns_f,
           description: "Tests all multiplayer spawn points",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'MPCallout_v''
// EA  : 0x833772C0
// RVA : 0x013772C0
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__MPCallout_v__()
{
  return idCommandLink::idCommandLink(
           this: &MPCallout_v,
           cmdName: "MPCallout",
           function: MPCallout_f,
           description: "Add multiplier points in coop challenge mode",
           argCompletion: idDeclManager::ArgCompletion_Decl<idDeclOnlineScoringCallout>);
}


// ========================================================================
// `dynamic initializer for 'ForceEndGame_v''
// EA  : 0x833772F0
// RVA : 0x013772F0
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__ForceEndGame_v__()
{
  return idCommandLink::idCommandLink(
           this: &ForceEndGame_v,
           cmdName: "ForceEndGame",
           function: ForceEndGame_f,
           description: "Forefully end the game, useful for testing end game stats",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'MPTestLeaderboardUpload_v''
// EA  : 0x83377318
// RVA : 0x01377318
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__MPTestLeaderboardUpload_v__()
{
  return idCommandLink::idCommandLink(
           this: &MPTestLeaderboardUpload_v,
           cmdName: "MPTestLeaderboardUpload",
           function: MPTestLeaderboardUpload_f,
           description: "Tests uploading leaderboard entries",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'MPTestLeaderboardUploadCoop_v''
// EA  : 0x83377340
// RVA : 0x01377340
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__MPTestLeaderboardUploadCoop_v__()
{
  return idCommandLink::idCommandLink(
           this: &MPTestLeaderboardUploadCoop_v,
           cmdName: "MPTestLeaderboardUploadCoop",
           function: MPTestLeaderboardUploadCoop_f,
           description: "Tests uploading leaderboard entries",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'MPTestLeaderboardUploadRoadRage_v''
// EA  : 0x83377368
// RVA : 0x01377368
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__MPTestLeaderboardUploadRoadRage_v__()
{
  return idCommandLink::idCommandLink(
           this: &MPTestLeaderboardUploadRoadRage_v,
           cmdName: "MPTestLeaderboardUploadRoadRage",
           function: MPTestLeaderboardUploadRoadRage_f,
           description: "Tests uploading leaderboard entries",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'MPTestLeaderboardDownloadCoop_v''
// EA  : 0x83377390
// RVA : 0x01377390
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__MPTestLeaderboardDownloadCoop_v__()
{
  return idCommandLink::idCommandLink(
           this: &MPTestLeaderboardDownloadCoop_v,
           cmdName: "MPTestLeaderboardDownloadCoop",
           function: MPTestLeaderboardDownloadCoop_f,
           description: "Tests uploading leaderboard entries",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'MPTestLeaderboardDownloadRally_v''
// EA  : 0x833773B8
// RVA : 0x013773B8
// PDB : w:\tech5\tungsten\game\entities\gamechallenge.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__MPTestLeaderboardDownloadRally_v__()
{
  return idCommandLink::idCommandLink(
           this: &MPTestLeaderboardDownloadRally_v,
           cmdName: "MPTestLeaderboardDownloadRally",
           function: MPTestLeaderboardDownloadRally_f,
           description: "Tests uploading leaderboard entries",
           argCompletion: nullptr);
}

