
// ========================================================================
// ?Add@idRageStat@@QAAHAAVidRagePlayerMetrics@@H@Z
// EA  : 0x82DE60F8
// RVA : 0x00DE60F8
// PDB : w:\tech5\tungsten\game\metrics\ragestat.cpp
// ========================================================================

int __fastcall idRageStat::Add(idRageStat *this, idRagePlayerMetrics *owner, int value)
{
  int v7; // r29
  bool v8; // cr58
  idGameChallenge *ChallengeEntity; // r3
  int XPValue; // r3
  int v11; // r30

  if ( gameLocal == nullptr )
    return 0;
  v7 = 0;
  v8 = this->decl == nullptr;
  this->sessionValue.i += value;
  if ( !v8 )
  {
    ChallengeEntity = idGameLocal::GetChallengeEntity(this: gameLocal);
    if ( (unsigned __int8)idGameChallenge::CanPostStats(this: ChallengeEntity) != 0 )
    {
      XPValue = idDeclMetric::GetXPValue(this: this->decl, delta: value);
      v7 = XPValue + idDeclMetric::GetXPBonus(this: this->decl, delta: value);
      if ( v7 != 0 )
      {
        v11 = 1;
        if ( common->IsMultiplayer(this: common) )
          v11 = (int)session->GetTitleStorageFloat_2(this: session, a2: "xp_multiplier", a3: 1.0);
        idRagePlayerMetrics::GainXP(this: owner, xp: v11 * v7, xpSource: this->decl);
      }
    }
  }
  return v7;
}


// ========================================================================
// ?Add@idRageStat@@QAAXM@Z
// EA  : 0x82DE6200
// RVA : 0x00DE6200
// PDB : w:\tech5\tungsten\game\metrics\ragestat.cpp
// ========================================================================

void __fastcall idRageStat::Add(idTungstenHealth *this, double h)
{
  this->components[0].cur = (float)h + this->components[0].cur;
}


// ========================================================================
// ?Increment@idRageStat@@QAAHAAVidRagePlayerMetrics@@@Z
// EA  : 0x82DE6210
// RVA : 0x00DE6210
// PDB : w:\tech5\tungsten\game\metrics\ragestat.cpp
// ========================================================================

int __fastcall idRageStat::Increment(idRageStat *this, idRagePlayerMetrics *owner)
{
  return idRageStat::Add(this, owner, value: 1);
}


// ========================================================================
// ?Init@idRageStat@@QAAXABVidRagePlayerMetrics@@@Z
// EA  : 0x82DE6218
// RVA : 0x00DE6218
// PDB : w:\tech5\tungsten\game\metrics\ragestat.cpp
// ========================================================================

void __fastcall idRageStat::Init(idRageStat *this, const idRagePlayerMetrics *owner)
{
  this->decl = idDeclMetric::Find(stat: (rageStat_t)(this - owner->stats.list));
}


// ========================================================================
// ?Aggregate@idRageStat@@QAA?ATstatValue_t@1@AAVidRagePlayerMetrics@@@Z
// EA  : 0x82DE6258
// RVA : 0x00DE6258
// PDB : w:\tech5\tungsten\game\metrics\ragestat.cpp
// ========================================================================

idRageStat::statValue_t *__fastcall idRageStat::Aggregate(
        idRageStat::statValue_t *__return_ptr retstr,
        idRageStat *this,
        idRagePlayerMetrics *owner)
{
  idRageStat::statValue_t v3; // r29
  idPlayer *Player; // r26
  idLocalUser *LocalUserFromPlayerIndex; // r3
  BOOL isAchievementReady; // r10
  idLocalUser *v10; // r25
  const idDeclMetric *decl; // r11
  unsigned int method; // r27
  rageStat_t v13; // r3
  rageStat_t stat; // r28
  bool IsInt; // r3
  idLocalUser_vtbl *v16; // r11
  int v17; // r24
  int v18; // r3
  idRageStat::statValue_t v19; // r31
  idRageStat::statValue_t v20; // r11
  idRageStat::statValue_t v21; // r11
  int v22; // r11
  double v24; // fp1
  double v25; // fp31
  double f; // fp0
  double v27; // fp11

  v3.i = 0;
  Player = nullptr;
  LocalUserFromPlayerIndex = idClientGame::GetLocalUserFromPlayerIndex(this: clientGame, index: owner->entityNumber);
  isAchievementReady = owner->isAchievementReady;
  retstr->i = 0;
  v10 = LocalUserFromPlayerIndex;
  if ( isAchievementReady && common->IsServer(this: common) )
    Player = idGameLocal::GetPlayer(this: gameLocal, i: owner->entityNumber);
  if ( v10 == nullptr )
    return retstr;
  decl = this->decl;
  method = 2;
  v13 = this - owner->stats.list;
  stat = v13;
  if ( this->decl != nullptr )
  {
    if ( decl->aggregate.stat != RAGE_STAT_INVALID )
      stat = decl->aggregate.stat;
    method = decl->aggregate.method;
  }
  IsInt = RageStatTypeIsInt(stat: v13);
  v16 = v10->__vftable;
  if ( !IsInt )
  {
    v24 = ((double (__fastcall *)(idLocalUser *, rageStat_t))v16->GetStatFloat)(a1: v10, a2: stat);
    v25 = v24;
    if ( Player != nullptr )
      f = Player->stats[stat].f;
    else
      f = 0.0;
    if ( method <= 3 )
    {
      if ( method == 1 )
      {
        if ( this->sessionValue.f > v24 )
        {
          v25 = this->sessionValue.f;
          f = v25;
        }
      }
      else if ( method == 2 )
      {
        v27 = (float)(this->sessionValue.f - this->aggregatedValue.f);
        this->aggregatedValue.f = this->aggregatedValue.f + (float)(this->sessionValue.f - this->aggregatedValue.f);
        v25 = (float)((float)v27 + (float)v24);
        f = (float)((float)v27 + (float)f);
      }
      else if ( method != 0 )
      {
        v25 = this->sessionValue.f;
        this->aggregatedValue.f = this->sessionValue.f;
        f = v25;
      }
      else if ( this->sessionValue.f < v24 )
      {
        v25 = this->sessionValue.f;
        f = v25;
      }
    }
    if ( Player != nullptr )
      Player->stats[stat].f = f;
    v10->SetStatFloat(this: v10, a2: stat, a3: v25);
    retstr->f = v25;
    return retstr;
  }
  v17 = v16->GetStatInt(this: v10, a2: stat);
  v18 = v10->GetStatInt(this: v10, a2: stat);
  v19.i = v18;
  if ( Player != nullptr )
    v3.i = Player->stats[stat].i;
  if ( method <= 3 )
  {
    if ( method == 1 )
    {
      v21.i = (int)this->sessionValue;
      if ( v21.i > v18 )
        v19.i = (int)this->sessionValue;
      if ( v21.i > v3.i )
        v3.i = (int)this->sessionValue;
    }
    else if ( method == 2 )
    {
      v22 = this->sessionValue.i - this->aggregatedValue.i;
      v19.i = v22 + v18;
      v3.i += v22;
      this->aggregatedValue.i = this->sessionValue.i;
    }
    else if ( method != 0 )
    {
      v19.i = (int)this->sessionValue;
      v3.i = v19.i;
      this->aggregatedValue = v19;
    }
    else
    {
      v20.i = (int)this->sessionValue;
      if ( v20.i < v18 )
        v19.i = (int)this->sessionValue;
      if ( v20.i < v3.i )
        v3.i = (int)this->sessionValue;
    }
  }
  if ( Player != nullptr )
  {
    idAchievementManager::EventCompletesAchievement(
      this: &Player->achievementManager,
      eventId: stat,
      count: v19.i - v17);
    Player->stats[stat].i = v3.i;
  }
  v10->SetStatInt(this: v10, a2: stat, a3: v19.i);
  retstr->i = v19.i;
  return retstr;
}

