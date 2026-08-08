
// ========================================================================
// ?DebugGetEnemyTrailPos@idAIMemory@@QBAABVidAIPos@@H@Z
// EA  : 0x82A52788
// RVA : 0x00A52788
// PDB : w:\tech5\tungsten\game\ai\aimemory.cpp
// ========================================================================

const idAIPos *__fastcall idAIMemory::DebugGetEnemyTrailPos(idAIMemory *this, const int _i)
{
  return &this->lEnemyTrailPos[(this->iEnemyTrailFinger + _i) % 5];
}


// ========================================================================
// ?SetInvalidCover@idAIMemory@@QAAXABVidAICover@@H@Z
// EA  : 0x82A527C8
// RVA : 0x00A527C8
// PDB : w:\tech5\tungsten\game\ai\aimemory.cpp
// ========================================================================

void __fastcall idAIMemory::SetInvalidCover(idAIMemory *this, idAICover *cover, int unusableTime)
{
  idAICover::MakeUnusable(this: cover, duration: unusableTime);
  idAICover::operator=(this: &this->invalidCover, other: cover);
}


// ========================================================================
// ?SetReachedCoverTime@idAIMemory@@QAAXH@Z
// EA  : 0x82A52818
// RVA : 0x00A52818
// PDB : w:\tech5\tungsten\game\ai\aimemory.cpp
// ========================================================================

void __fastcall idAIMemory::SetReachedCoverTime(idAIMemory *this, int curTime)
{
  if ( this->newCoverSet )
  {
    this->reachedCoverTime = curTime;
    this->newCoverSet = false;
  }
}


// ========================================================================
// ?SetCurrentCover@idAIMemory@@QAAXABVidAICover@@@Z
// EA  : 0x82A52838
// RVA : 0x00A52838
// PDB : w:\tech5\tungsten\game\ai\aimemory.cpp
// ========================================================================

void __fastcall idAIMemory::SetCurrentCover(idAIMemory *this, const idAICover *cover)
{
  idAICover *p_currentCover; // r29

  p_currentCover = &this->currentCover;
  if ( !idAICover::operator==(this: &this->currentCover, other: cover) )
    this->newCoverSet = true;
  idAICover::operator=(this: p_currentCover, other: cover);
}


// ========================================================================
// ?SetLastCover@idAIMemory@@QAAXABVidAICover@@@Z
// EA  : 0x82A52880
// RVA : 0x00A52880
// PDB : w:\tech5\tungsten\game\ai\aimemory.cpp
// ========================================================================

void __fastcall idAIMemory::SetLastCover(idAIMemory *this, const idAICover *cover)
{
  idAICover *p_lastCover; // r27
  int v5; // r30
  int *p_nextCoverActionTime; // r31

  p_lastCover = &this->lastCover;
  if ( !idAICover::operator==(this: &this->lastCover, other: cover) )
  {
    v5 = 4;
    p_nextCoverActionTime = &this->nextCoverActionTime;
    do
    {
      p_nextCoverActionTime -= 3;
      --v5;
      idAICover::operator=(
        this: (idAICover *)p_nextCoverActionTime,
        other: (const idAICover *)p_nextCoverActionTime - 1);
    }
    while ( v5 != 0 );
    idAICover::operator=(this: this->lCoverHistory, other: cover);
  }
  idAICover::operator=(this: p_lastCover, other: cover);
}


// ========================================================================
// ?GetHistoryScore@idAIMemory@@QBAMABVidAICover@@@Z
// EA  : 0x82A528F0
// RVA : 0x00A528F0
// PDB : w:\tech5\tungsten\game\ai\aimemory.cpp
// ========================================================================

float __fastcall idAIMemory::GetHistoryScore(idAIMemory *this, idAICover *_Cover)
{
  int v3; // r30
  idAICover *lCoverHistory; // r31
  double v5; // fp31
  double v6; // fp1

  v3 = 0;
  lCoverHistory = this->lCoverHistory;
  v5 = 0.16666667;
  while ( !idAICover::operator==(this: _Cover, other: lCoverHistory) )
  {
    ++v3;
    v5 = (float)((float)v5 + (float)0.16666667);
    ++lCoverHistory;
    if ( v3 >= 4 )
    {
      v6 = 1.0;
      return *((float *)&v6 + 1);
    }
  }
  v6 = v5;
  return *((float *)&v6 + 1);
}


// ========================================================================
// ?SetAIVarExpression@idAIMemory@@QAAXPBDW4aiVarOp_t@@0@Z
// EA  : 0x82A52978
// RVA : 0x00A52978
// PDB : w:\tech5\tungsten\game\ai\aimemory.cpp
// ========================================================================

void __fastcall idAIMemory::SetAIVarExpression(idAIMemory *this, const char *name, aiVarOp_t op, const char *value)
{
  idStr::operator=(this: &this->varName, text: name);
  this->varOp = op;
  idStr::operator=(this: &this->varValue, text: value);
}


// ========================================================================
// ?GetScriptedAggro@idAIMemory@@QBAMH@Z
// EA  : 0x82A529B0
// RVA : 0x00A529B0
// PDB : w:\tech5\tungsten\game\ai\aimemory.cpp
// ========================================================================

float __fastcall idAIMemory::GetScriptedAggro(idAIMemory *this, int curTime)
{
  int scriptedAggroEndTime; // r11
  double scriptedAggro; // fp1

  scriptedAggroEndTime = this->scriptedAggroEndTime;
  if ( scriptedAggroEndTime < 0 || curTime <= scriptedAggroEndTime )
    scriptedAggro = this->scriptedAggro;
  else
    scriptedAggro = 0.0;
  return *((float *)&scriptedAggro + 1);
}


// ========================================================================
// ?ClearScenePointHistory@idAIMemory@@QAAXXZ
// EA  : 0x82A529D8
// RVA : 0x00A529D8
// PDB : w:\tech5\tungsten\game\ai\aimemory.cpp
// ========================================================================

void __fastcall idAIMemory::ClearScenePointHistory(idAIMemory *this)
{
  this->scenePointHistory[0] = nullptr;
  this->scenePointHistory[1] = nullptr;
  this->scenePointHistory[2] = nullptr;
  this->scenePointHistory[3] = nullptr;
  this->scenePointHistory[4] = nullptr;
}


// ========================================================================
// ?GetLastHeldScenePoint@idAIMemory@@QBAPAVidScenePoint@@XZ
// EA  : 0x82A529F8
// RVA : 0x00A529F8
// PDB : w:\tech5\tungsten\game\ai\aimemory.cpp
// ========================================================================

idScenePoint *__fastcall idAIMemory::GetLastHeldScenePoint(idAIMemory *this)
{
  return this->scenePointHistory[0];
}


// ========================================================================
// ?SetTakeScenePointTimeStamp@idAIMemory@@QBAXH@Z
// EA  : 0x82A52A00
// RVA : 0x00A52A00
// PDB : w:\tech5\tungsten\game\ai\aimemory.cpp
// ========================================================================

void __fastcall idAIMemory::SetTakeScenePointTimeStamp(idAIMemory *this, int curTime)
{
  if ( this->curScenePointTakeTime < 0 )
    this->curScenePointTakeTime = curTime;
}


// ========================================================================
// ?SetActivateScenePointTimeStamp@idAIMemory@@QBAXH@Z
// EA  : 0x82A52A18
// RVA : 0x00A52A18
// PDB : w:\tech5\tungsten\game\ai\aimemory.cpp
// ========================================================================

void __fastcall idAIMemory::SetActivateScenePointTimeStamp(idAIMemory *this, int curTime)
{
  if ( this->curScenePointActivateTime < 0 )
    this->curScenePointActivateTime = curTime;
}


// ========================================================================
// ?ClearScenePointTimeStamps@idAIMemory@@QBAXXZ
// EA  : 0x82A52A30
// RVA : 0x00A52A30
// PDB : w:\tech5\tungsten\game\ai\aimemory.cpp
// ========================================================================

void __fastcall idAIMemory::ClearScenePointTimeStamps(idAIMemory *this)
{
  this->curScenePointTakeTime = -1;
  this->curScenePointActivateTime = -1;
}


// ========================================================================
// ?FirstThink@idAIMemory@@QAAXPBVidDeclAIBehavior@@@Z
// EA  : 0x82A52A40
// RVA : 0x00A52A40
// PDB : w:\tech5\tungsten\game\ai\aimemory.cpp
// ========================================================================

void __fastcall idAIMemory::FirstThink(idAIMemory *this, const idDeclAIBehavior *bdef)
{
  int v4; // r28
  int v5; // r3
  int v6; // r28
  int v7; // r3
  int v8; // r28
  int v9; // r3
  int v10; // r29
  int v11; // r3
  idAICover *lCoverHistory; // r30
  int i; // r31

  this->spawnTime = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  v4 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED)
     + (bdef->dodging.maxAimDodgeInterval + bdef->dodging.minAimDodgeInterval) / 2;
  v5 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
  this->nextDodgeTime = GetRandomInterval(_min: v5, _max: v4);
  v6 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED)
     + (bdef->maxThrowInterval + bdef->minThrowInterval) / 2;
  v7 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
  this->nextThrowTime = GetRandomInterval(_min: v7, _max: v6);
  v8 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED)
     + (bdef->rageBehaviors.maxRageInterval + bdef->rageBehaviors.minRageInterval) / 2;
  v9 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
  this->soonestAngryRageTime = GetRandomInterval(_min: v9, _max: v8);
  v10 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED)
      + (bdef->rageBehaviors.maxRageInterval + bdef->rageBehaviors.minRageInterval) / 2;
  v11 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
  this->soonestTauntRageTime = GetRandomInterval(_min: v11, _max: v10);
  this->nextThrowTime = GetRandomInterval(_min: bdef->minThrowInterval, _max: bdef->maxThrowInterval);
  lCoverHistory = this->lCoverHistory;
  this->currentEnemySuspectedPos.bValid = false;
  this->lEnemyTrailPos[0].bValid = false;
  this->lEnemyTrailPos[1].bValid = false;
  this->lEnemyTrailPos[2].bValid = false;
  this->lEnemyTrailPos[3].bValid = false;
  this->lEnemyTrailPos[4].bValid = false;
  for ( i = 5; i != 0; --i )
    idAICover::idAICover(this: lCoverHistory++);
}


// ========================================================================
// ?ClearCurrentTrailPos@idAIMemory@@QAAXXZ
// EA  : 0x82A52C28
// RVA : 0x00A52C28
// PDB : w:\tech5\tungsten\game\ai\aimemory.cpp
// ========================================================================

void __fastcall idAIMemory::ClearCurrentTrailPos(idAIMemory *this)
{
  this->lEnemyTrailPos[this->iEnemyTrailFinger].bValid = false;
}


// ========================================================================
// ?TouchEnemyTrail@idAIMemory@@QAAXH@Z
// EA  : 0x82A52C40
// RVA : 0x00A52C40
// PDB : w:\tech5\tungsten\game\ai\aimemory.cpp
// ========================================================================

void __fastcall idAIMemory::TouchEnemyTrail(idAIMemory *this, const int _curTime)
{
  int v2; // r10

  this->lEnemyTrailPos[0].bValid = false;
  this->lEnemyTrailPos[1].bValid = false;
  this->lEnemyTrailPos[2].bValid = false;
  this->lEnemyTrailPos[3].bValid = false;
  this->lEnemyTrailPos[4].bValid = false;
  v2 = this->enemyTrailUpdatePeriod + _curTime;
  this->iEnemyTrailFinger = 0;
  this->nextEnemyTrailTime = v2;
}


// ========================================================================
// ?SetWantAngryRageTime@idAIMemory@@QAAXHPBD@Z
// EA  : 0x82A52C70
// RVA : 0x00A52C70
// PDB : w:\tech5\tungsten\game\ai\aimemory.cpp
// ========================================================================

void __fastcall idAIMemory::SetWantAngryRageTime(idAIMemory *this, int t, const char *debugReason)
{
  this->wantAngryRageTime = t;
  if ( t >= 0 && ai_debugRage.valueInteger != 0 && ai_debugLevel.valueInteger > 0 )
    idLib::Printf(fmt: "Rage Angry reason %s\n", debugReason);
}


// ========================================================================
// ?SetWantTauntRageTime@idAIMemory@@QAAXHPBD@Z
// EA  : 0x82A52CB8
// RVA : 0x00A52CB8
// PDB : w:\tech5\tungsten\game\ai\aimemory.cpp
// ========================================================================

void __fastcall idAIMemory::SetWantTauntRageTime(idAIMemory *this, int t, const char *debugReason)
{
  this->wantTauntRageTime = t;
  if ( ai_debugRage.valueInteger != 0 && ai_debugLevel.valueInteger > 0 )
    idLib::Printf(fmt: "Rage Taunt reason %s\n", debugReason);
}


// ========================================================================
// ?TriggerPulled@idAIMemory@@QAAXXZ
// EA  : 0x82A52CF8
// RVA : 0x00A52CF8
// PDB : w:\tech5\tungsten\game\ai\aimemory.cpp
// ========================================================================

void __fastcall idAIMemory::TriggerPulled(idAIMemory *this)
{
  this->numShotsThisPull = 0;
  this->numShotsThisPullBlocked = 0;
  this->numShotsThisPullBlockedConsecutive = 0;
}


// ========================================================================
// ?WeaponFired@idAIMemory@@QAAX_N@Z
// EA  : 0x82A52D10
// RVA : 0x00A52D10
// PDB : w:\tech5\tungsten\game\ai\aimemory.cpp
// ========================================================================

void __fastcall idAIMemory::WeaponFired(idAIMemory *this, bool shotWasClear)
{
  __int16 numShotsThisPullBlockedConsecutive; // r11

  ++this->numShotsThisPull;
  if ( shotWasClear )
  {
    this->numShotsThisPullBlockedConsecutive = 0;
  }
  else
  {
    numShotsThisPullBlockedConsecutive = this->numShotsThisPullBlockedConsecutive;
    ++this->numShotsThisPullBlocked;
    this->numShotsThisPullBlockedConsecutive = numShotsThisPullBlockedConsecutive + 1;
  }
}


// ========================================================================
// ?HasOverrideScriptScenePointOfType@idAIMemory@@QBA_NW4scenePointType_t@@@Z
// EA  : 0x82A52D50
// RVA : 0x00A52D50
// PDB : w:\tech5\tungsten\game\ai\aimemory.cpp
// ========================================================================

int __fastcall idAIMemory::HasOverrideScriptScenePointOfType(idAIMemory *this, scenePointType_t spType)
{
  idScenePoint *overrideScenePoint; // r11
  int result; // r3

  overrideScenePoint = this->overrideScenePoint;
  if ( overrideScenePoint == nullptr )
    return 0;
  if ( (*(_BYTE *)&overrideScenePoint->flags & 8) == 0 )
    return 0;
  if ( overrideScenePoint->type != spType )
    return 0;
  result = 1;
  if ( (overrideScenePoint->scriptFlags & 1) == 0 )
    return 0;
  return result;
}


// ========================================================================
// ?HasOverrideScriptScenePointNotOfType@idAIMemory@@QBA_NW4scenePointType_t@@@Z
// EA  : 0x82A52D98
// RVA : 0x00A52D98
// PDB : w:\tech5\tungsten\game\ai\aimemory.cpp
// ========================================================================

int __fastcall idAIMemory::HasOverrideScriptScenePointNotOfType(idAIMemory *this, scenePointType_t spType)
{
  idScenePoint *overrideScenePoint; // r11
  int result; // r3

  overrideScenePoint = this->overrideScenePoint;
  if ( overrideScenePoint == nullptr )
    return 0;
  if ( (*(_BYTE *)&overrideScenePoint->flags & 8) == 0 )
    return 0;
  if ( overrideScenePoint->type == spType )
    return 0;
  result = 1;
  if ( (overrideScenePoint->scriptFlags & 1) == 0 )
    return 0;
  return result;
}


// ========================================================================
// ?UpdateScenePointHistory@idAIMemory@@QAAXPAVidScenePoint@@@Z
// EA  : 0x82A52DE0
// RVA : 0x00A52DE0
// PDB : w:\tech5\tungsten\game\ai\aimemory.cpp
// ========================================================================

void __fastcall idAIMemory::UpdateScenePointHistory(idAIMemory *this, idScenePoint *scenePoint)
{
  idScenePoint *v2; // r10
  idScenePoint *v3; // r9
  idScenePoint *v4; // r8

  if ( scenePoint != nullptr && scenePoint->type != LOOK && this->scenePointHistory[0] != scenePoint )
  {
    v2 = this->scenePointHistory[2];
    v3 = this->scenePointHistory[1];
    v4 = this->scenePointHistory[0];
    this->scenePointHistory[4] = this->scenePointHistory[3];
    this->scenePointHistory[3] = v2;
    this->scenePointHistory[2] = v3;
    this->scenePointHistory[1] = v4;
    this->scenePointHistory[0] = scenePoint;
  }
}


// ========================================================================
// ?GetScenePointHistoryScore@idAIMemory@@QBAMPAVidScenePoint@@@Z
// EA  : 0x82A52E28
// RVA : 0x00A52E28
// PDB : w:\tech5\tungsten\game\ai\aimemory.cpp
// ========================================================================

float __fastcall idAIMemory::GetScenePointHistoryScore(idAIMemory *this, idScenePoint *scenePoint)
{
  int v2; // r10
  idScenePoint **scenePointHistory; // r11
  double v4; // fp1

  if ( scenePoint == nullptr || scenePoint->type == LOOK )
  {
    v4 = 0.0;
  }
  else
  {
    v2 = 0;
    scenePointHistory = this->scenePointHistory;
    v4 = 0.0;
    while ( *scenePointHistory != scenePoint )
    {
      ++v2;
      v4 = (float)((float)v4 + (float)0.2);
      ++scenePointHistory;
      if ( v2 >= 4 )
      {
        v4 = 1.0;
        break;
      }
    }
  }
  return *((float *)&v4 + 1);
}


// ========================================================================
// ?UpdateLookScenePointHistory@idAIMemory@@QAAXPAVidScenePoint@@@Z
// EA  : 0x82A52E90
// RVA : 0x00A52E90
// PDB : w:\tech5\tungsten\game\ai\aimemory.cpp
// ========================================================================

void __fastcall idAIMemory::UpdateLookScenePointHistory(idAIMemory *this, idScenePoint *scenePoint)
{
  idScenePoint *v2; // r10
  idScenePoint *v3; // r9
  idScenePoint *v4; // r8

  if ( scenePoint != nullptr && scenePoint->type == LOOK && this->lookScenePointHistory[0] != scenePoint )
  {
    v2 = this->lookScenePointHistory[2];
    v3 = this->lookScenePointHistory[1];
    v4 = this->lookScenePointHistory[0];
    this->lookScenePointHistory[4] = this->lookScenePointHistory[3];
    this->lookScenePointHistory[3] = v2;
    this->lookScenePointHistory[2] = v3;
    this->lookScenePointHistory[1] = v4;
    this->lookScenePointHistory[0] = scenePoint;
  }
}


// ========================================================================
// ?GetLookScenePointHistoryScore@idAIMemory@@QBAMPAVidScenePoint@@@Z
// EA  : 0x82A52ED8
// RVA : 0x00A52ED8
// PDB : w:\tech5\tungsten\game\ai\aimemory.cpp
// ========================================================================

float __fastcall idAIMemory::GetLookScenePointHistoryScore(idAIMemory *this, idScenePoint *scenePoint)
{
  int v2; // r10
  idScenePoint **lookScenePointHistory; // r11
  double v4; // fp1

  if ( scenePoint != nullptr && scenePoint->type == LOOK )
  {
    v2 = 0;
    lookScenePointHistory = this->lookScenePointHistory;
    v4 = 0.0;
    while ( *lookScenePointHistory != scenePoint )
    {
      ++v2;
      v4 = (float)((float)v4 + (float)0.2);
      ++lookScenePointHistory;
      if ( v2 >= 4 )
      {
        v4 = 1.0;
        break;
      }
    }
  }
  else
  {
    v4 = 0.0;
  }
  return *((float *)&v4 + 1);
}


// ========================================================================
// ?SetOverrideScenePoint@idAIMemory@@QAAXPAVidScenePoint@@@Z
// EA  : 0x82A52F40
// RVA : 0x00A52F40
// PDB : w:\tech5\tungsten\game\ai\aimemory.cpp
// ========================================================================

void __fastcall idAIMemory::SetOverrideScenePoint(idAIMemory *this, idScenePoint *scenePoint)
{
  idScenePoint *overrideScenePoint; // r11
  scenePointScriptFlags_t scriptFlags; // r10

  overrideScenePoint = this->overrideScenePoint;
  if ( overrideScenePoint == nullptr || overrideScenePoint == scenePoint )
  {
    this->overrideScenePoint = scenePoint;
  }
  else
  {
    scriptFlags = overrideScenePoint->scriptFlags;
    this->overrideScenePoint = scenePoint;
    if ( (scriptFlags & 0x400) != 0 )
      this->keptOverrideScenePoint = overrideScenePoint;
  }
}


// ========================================================================
// ?UpdateEnemyTrailPos@idAIMemory@@QAAXHABVidVec3@@@Z
// EA  : 0x82A52F78
// RVA : 0x00A52F78
// PDB : w:\tech5\tungsten\game\ai\aimemory.cpp
// ========================================================================

void __fastcall idAIMemory::UpdateEnemyTrailPos(idAIMemory *this, const int _curTime, const idVec3 *_EnemyPos)
{
  int iEnemyTrailFinger; // r29
  int v7; // r11
  idAIPos *v8; // r11
  double z; // fp12
  int v10; // r11

  if ( this->enemyTrailUpdatePeriod > 0 && _curTime >= this->nextEnemyTrailTime )
  {
    iEnemyTrailFinger = this->iEnemyTrailFinger;
    v7 = (iEnemyTrailFinger + 4) % 5;
    if ( !this->lEnemyTrailPos[iEnemyTrailFinger].bValid
      || !this->lEnemyTrailPos[v7].bValid
      || idVec3::DistanceFast(this: &this->lEnemyTrailPos[v7].pos, v: _EnemyPos) > 48.0 )
    {
      v8 = &this->lEnemyTrailPos[iEnemyTrailFinger];
      v8->pos.x = _EnemyPos->x;
      v8->pos.y = _EnemyPos->y;
      z = _EnemyPos->z;
      v8->bValid = true;
      v8->pos.z = z;
      v10 = this->iEnemyTrailFinger + 1;
      this->nextEnemyTrailTime = _curTime + this->enemyTrailUpdatePeriod;
      this->iEnemyTrailFinger = v10 % 5;
    }
  }
}


// ========================================================================
// ?GetEnemyTrailPos@idAIMemory@@QAA_NAAVidAIPos@@@Z
// EA  : 0x82A53088
// RVA : 0x00A53088
// PDB : w:\tech5\tungsten\game\ai\aimemory.cpp
// ========================================================================

int __fastcall idAIMemory::GetEnemyTrailPos(idAIMemory *this, idAIPos *_Trail)
{
  int v2; // r7
  int v3; // r11

  v2 = 0;
  while ( 1 )
  {
    v3 = (this->iEnemyTrailFinger + v2) % 5;
    if ( this->lEnemyTrailPos[v3].bValid )
      break;
    if ( ++v2 >= 5 )
      return 0;
  }
  *_Trail = this->lEnemyTrailPos[v3];
  this->iEnemyTrailFinger = (this->iEnemyTrailFinger + v2) % 5;
  return 1;
}


// ========================================================================
// ??1idAIMemory@@QAA@XZ
// EA  : 0x82A53268
// RVA : 0x00A53268
// PDB : w:\tech5\tungsten\game\ai\aimemory.cpp
// ========================================================================

void __fastcall idAIMemory::~idAIMemory(idAIMemory *this)
{
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->lookScenePoints);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->roamScenePoints);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->searchScenePoints);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->combatScenePoints);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->scenePointVolumes);
  idStr::FreeData(this: &this->varValue);
  idStr::FreeData(this: &this->varName);
  idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&this->cachedCover);
  `eh vector destructor iterator'(
    ptr: this->lCoverHistory,
    size: 0xCu,
    count: 5,
    pDtor: (void (__fastcall *)(void *))idPhysics_StaticMulti::UpdateTime);
  idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&this->lastCover);
  idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&this->currentCover);
  idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&this->invalidCover);
}


// ========================================================================
// __unwind$490005_0
// EA  : 0x82A53310
// RVA : 0x00A53310
// PDB : w:\tech5\tungsten\game\ai\aimemory.cpp
// ========================================================================

void _unwind_490005_0()
{
  int v0; // r12

  idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)(*(_DWORD *)(v0 - 112 + 132) + 188));
}


// ========================================================================
// __unwind$490006_0
// EA  : 0x82A5333C
// RVA : 0x00A5333C
// PDB : w:\tech5\tungsten\game\ai\aimemory.cpp
// ========================================================================

void _unwind_490006_0()
{
  int v0; // r12

  idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)(*(_DWORD *)(v0 - 112 + 132) + 200));
}


// ========================================================================
// __unwind$490007
// EA  : 0x82A53368
// RVA : 0x00A53368
// PDB : w:\tech5\tungsten\game\ai\aimemory.cpp
// ========================================================================

void _unwind_490007()
{
  int v0; // r12

  idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)(*(_DWORD *)(v0 - 112 + 132) + 212));
}


// ========================================================================
// __unwind$490008
// EA  : 0x82A53394
// RVA : 0x00A53394
// PDB : w:\tech5\tungsten\game\ai\aimemory.cpp
// ========================================================================

void _unwind_490008()
{
  int v0; // r12

  `eh vector destructor iterator'(
    ptr: (void *)(*(_DWORD *)(v0 - 112 + 132) + 224),
    size: 0xCu,
    count: 5,
    pDtor: (void (__fastcall *)(void *))idPhysics_StaticMulti::UpdateTime);
}


// ========================================================================
// __unwind$490009
// EA  : 0x82A533D0
// RVA : 0x00A533D0
// PDB : w:\tech5\tungsten\game\ai\aimemory.cpp
// ========================================================================

void _unwind_490009()
{
  int v0; // r12

  idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)(*(_DWORD *)(v0 - 112 + 132) + 432));
}


// ========================================================================
// __unwind$490010
// EA  : 0x82A533FC
// RVA : 0x00A533FC
// PDB : w:\tech5\tungsten\game\ai\aimemory.cpp
// ========================================================================

void _unwind_490010()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 896));
}


// ========================================================================
// __unwind$490011
// EA  : 0x82A53428
// RVA : 0x00A53428
// PDB : w:\tech5\tungsten\game\ai\aimemory.cpp
// ========================================================================

void _unwind_490011()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 932));
}


// ========================================================================
// __unwind$490012
// EA  : 0x82A53454
// RVA : 0x00A53454
// PDB : w:\tech5\tungsten\game\ai\aimemory.cpp
// ========================================================================

void _unwind_490012()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 964));
}


// ========================================================================
// __unwind$490013
// EA  : 0x82A53480
// RVA : 0x00A53480
// PDB : w:\tech5\tungsten\game\ai\aimemory.cpp
// ========================================================================

void _unwind_490013()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 980));
}


// ========================================================================
// __unwind$490014
// EA  : 0x82A534AC
// RVA : 0x00A534AC
// PDB : w:\tech5\tungsten\game\ai\aimemory.cpp
// ========================================================================

void _unwind_490014()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 1000));
}


// ========================================================================
// __unwind$490015
// EA  : 0x82A534D8
// RVA : 0x00A534D8
// PDB : w:\tech5\tungsten\game\ai\aimemory.cpp
// ========================================================================

void _unwind_490015()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 1020));
}


// ========================================================================
// ?SetLastDamage@idAIMemory@@QAAXPAVidEntity@@0@Z
// EA  : 0x82A53508
// RVA : 0x00A53508
// PDB : w:\tech5\tungsten\game\ai\aimemory.cpp
// ========================================================================

void __fastcall idAIMemory::SetLastDamage(idAIMemory *this, idEntity *attacker, idEntity *inflictor)
{
  this->lastDamageTime = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  if ( attacker != nullptr )
    this->lastAttacker.spawnId.value = (gameLocal->spawnIds.ptr[attacker->entityNumber] << 13) | attacker->entityNumber;
  else
    this->lastAttacker.spawnId.value = 0x1FFF;
  if ( inflictor != nullptr )
    this->lastInflictor.spawnId.value = (gameLocal->spawnIds.ptr[inflictor->entityNumber] << 13)
                                      | inflictor->entityNumber;
  else
    this->lastInflictor.spawnId.value = 0x1FFF;
}


// ========================================================================
// ?SetCurrentPath@idAIMemory@@QAAXPBVidInfoPath@@@Z
// EA  : 0x82A535B0
// RVA : 0x00A535B0
// PDB : w:\tech5\tungsten\game\ai\aimemory.cpp
// ========================================================================

void __fastcall idAIMemory::SetCurrentPath(idAIMemory *this, const idInfoPath *path)
{
  int value; // r9
  idInfoPath *v4; // r3
  int v5; // r9
  idInfoPath *v6; // r3
  idInfoPath *v7; // r3
  const idInfoPath *NextPathPoint; // r3

  if ( path != nullptr )
    this->currentPath.spawnId.value = (gameLocal->spawnIds.ptr[path->entityNumber] << 13) | path->entityNumber;
  else
    this->currentPath.spawnId.value = 0x1FFF;
  value = this->currentPath.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v4 = (idInfoPath *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr
    && idInfoPath::CastTo(c: v4) != nullptr
    && ((v5 = this->currentPath.spawnId.value, gameLocal->spawnIds.ptr[v5 & 0x1FFF] != v5 >> 13)
     || (v6 = (idInfoPath *)gameLocal->entities.ptr[v5 & 0x1FFF]) == nullptr
      ? (v7 = nullptr)
      : (v7 = idInfoPath::CastTo(c: v6)),
        (NextPathPoint = idInfoPath::GetNextPathPoint(this: v7)) != nullptr) )
  {
    this->nextPath.spawnId.value = (gameLocal->spawnIds.ptr[NextPathPoint->entityNumber] << 13)
                                 | NextPathPoint->entityNumber;
  }
  else
  {
    this->nextPath.spawnId.value = 0x1FFF;
  }
}


// ========================================================================
// ?ClearScenePointLists@idAIMemory@@AAAXXZ
// EA  : 0x82A536C0
// RVA : 0x00A536C0
// PDB : w:\tech5\tungsten\game\ai\aimemory.cpp
// ========================================================================

void __fastcall idAIMemory::ClearScenePointLists(idAIMemory *this)
{
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->combatScenePoints);
  this->combatScenePoints.hasSearchedForScenePoints = false;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->searchScenePoints);
  this->searchScenePoints.hasSearchedForScenePoints = false;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->roamScenePoints);
  this->roamScenePoints.hasSearchedForScenePoints = false;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->lookScenePoints);
  this->lookScenePoints.hasSearchedForScenePoints = false;
}


// ========================================================================
// ?SetRestrictionVolume@idAIMemory@@QAAXV?$idEntityPtr@VidVolume_Restriction@@@@@Z
// EA  : 0x82A53728
// RVA : 0x00A53728
// PDB : w:\tech5\tungsten\game\ai\aimemory.cpp
// ========================================================================

void __fastcall idAIMemory::SetRestrictionVolume(idAIMemory *this, int volume)
{
  idGameLocal *v3; // r11
  idEntityPtr<idVolume_Restriction> *p_restrictionVolume; // r26
  idVolume_Restriction *v6; // r3
  idVolume_Restriction *v7; // r3
  idVolume_Restriction *v8; // r27
  int v9; // r31
  idVolume_Restriction *v10; // r3
  idVolume_Restriction *v11; // r3
  idVolume_Restriction *v12; // r3
  idVolume_Restriction *v13; // r3
  idVolume_Restriction *v14; // r3
  char flags; // r11

  p_restrictionVolume = &this->restrictionVolume;
  v3 = gameLocal;
  if ( gameLocal->spawnIds.ptr[this->restrictionVolume.spawnId.value & 0x1FFF] == this->restrictionVolume.spawnId.value >> 13
    && (v6 = (idVolume_Restriction *)gameLocal->entities.ptr[this->restrictionVolume.spawnId.value & 0x1FFF]) != nullptr )
  {
    v7 = idVolume_Restriction::CastTo(c: v6);
    v3 = gameLocal;
    v8 = v7;
  }
  else
  {
    v8 = nullptr;
  }
  v9 = volume & 0x1FFF;
  if ( v3->spawnIds.ptr[v9] == volume >> 13 && (v10 = (idVolume_Restriction *)v3->entities.ptr[v9]) != nullptr )
    v11 = idVolume_Restriction::CastTo(c: v10);
  else
    v11 = nullptr;
  if ( v8 != v11 )
  {
    p_restrictionVolume->spawnId.value = volume;
    if ( gameLocal->spawnIds.ptr[v9] == volume >> 13
      && (v12 = (idVolume_Restriction *)gameLocal->entities.ptr[v9]) != nullptr
      && idVolume_Restriction::CastTo(c: v12) != nullptr )
    {
      if ( this->restrictionVolumeActive
        || (*(_BYTE *)&idEntityPtr<idVolume_Restriction>::operator idVolume_Restriction *(this: p_restrictionVolume)->flags
          & 8) != 0 )
      {
        idAIMemory::ClearScenePointLists(this);
      }
      if ( gameLocal->spawnIds.ptr[p_restrictionVolume->spawnId.value & 0x1FFF] == p_restrictionVolume->spawnId.value >> 13
        && (v13 = (idVolume_Restriction *)gameLocal->entities.ptr[p_restrictionVolume->spawnId.value & 0x1FFF]) != nullptr )
      {
        v14 = idVolume_Restriction::CastTo(c: v13);
      }
      else
      {
        v14 = nullptr;
      }
      flags = (char)v14->flags;
      this->restrictionPos.bValid = false;
      this->restrictionVolumeActive = (flags & 8) != 0;
    }
    else
    {
      this->restrictionVolumeActive = false;
      idAIMemory::ClearScenePointLists(this);
      this->restrictionPos.bValid = false;
    }
  }
}


// ========================================================================
// ?HasRestrictionVolume@idAIMemory@@QAA_NXZ
// EA  : 0x82A538B8
// RVA : 0x00A538B8
// PDB : w:\tech5\tungsten\game\ai\aimemory.cpp
// ========================================================================

BOOL __fastcall idAIMemory::HasRestrictionVolume(idAIMemory *this)
{
  int value; // r10
  idVolume_Restriction *v3; // r3
  int v5; // r9
  idVolume_Restriction *v6; // r3
  idVolume_Restriction *v7; // r3
  int v8; // r9
  idVolume_Restriction *v9; // r3
  idVolume_Restriction *v10; // r3

  value = this->restrictionVolume.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] != value >> 13 )
    return false;
  v3 = (idVolume_Restriction *)gameLocal->entities.ptr[value & 0x1FFF];
  if ( v3 == nullptr || idVolume_Restriction::CastTo(c: v3) == nullptr )
    return false;
  v5 = this->restrictionVolume.spawnId.value;
  if ( gameLocal->spawnIds.ptr[v5 & 0x1FFF] == v5 >> 13
    && (v6 = (idVolume_Restriction *)gameLocal->entities.ptr[v5 & 0x1FFF]) != nullptr )
  {
    v7 = idVolume_Restriction::CastTo(c: v6);
  }
  else
  {
    v7 = nullptr;
  }
  if ( ((*(_BYTE *)&v7->flags & 8) != 0) != this->restrictionVolumeActive )
  {
    idAIMemory::ClearScenePointLists(this);
    v8 = this->restrictionVolume.spawnId.value;
    if ( gameLocal->spawnIds.ptr[v8 & 0x1FFF] == v8 >> 13
      && (v9 = (idVolume_Restriction *)gameLocal->entities.ptr[v8 & 0x1FFF]) != nullptr )
    {
      v10 = idVolume_Restriction::CastTo(c: v9);
    }
    else
    {
      v10 = nullptr;
    }
    this->restrictionVolumeActive = (*(_BYTE *)&v10->flags & 8) != 0;
  }
  return this->restrictionVolumeActive;
}


// ========================================================================
// ?SetRestrictionPos@idAIMemory@@QAAXABVidVec3@@@Z
// EA  : 0x82A539F0
// RVA : 0x00A539F0
// PDB : w:\tech5\tungsten\game\ai\aimemory.cpp
// ========================================================================

void __fastcall idAIMemory::SetRestrictionPos(idAIMemory *this, const idVec3 *pos)
{
  bool v4; // r11

  if ( idAIMemory::HasRestrictionVolume(this) )
  {
    v4 = true;
    this->restrictionPos.pos.x = pos->x;
    this->restrictionPos.pos.y = pos->y;
    this->restrictionPos.pos.z = pos->z;
  }
  else
  {
    v4 = false;
  }
  this->restrictionPos.bValid = v4;
}


// ========================================================================
// ??0idAIMemory@@QAA@XZ
// EA  : 0x82A53B48
// RVA : 0x00A53B48
// PDB : w:\tech5\tungsten\game\ai\aimemory.cpp
// ========================================================================

idAIMemory *__fastcall idAIMemory::idAIMemory(idAIMemory *this)
{
  idAICover *lCoverHistory; // r20
  idList<idVolume_ScenePoints *,5> *p_scenePointVolumes; // r26
  idAIMemory::idScenePointList *p_combatScenePoints; // r25
  idAIMemory::idScenePointList *p_searchScenePoints; // r24
  idAIMemory::idScenePointList *p_roamScenePoints; // r23
  idAIMemory::idScenePointList *p_lookScenePoints; // r22
  int v8; // r28
  idScenePoint **v9; // r11
  int i; // ctr

  this->transCode = 0;
  this->currentEnemy.spawnId.value = 0x1FFF;
  this->ambushTarget.spawnId.value = 0x1FFF;
  this->currentAggroTarget.spawnId.value = 0x1FFF;
  this->currentFriendly.spawnId.value = 0x1FFF;
  this->currentNeutral.spawnId.value = 0x1FFF;
  this->currentFriendlyBlocker.spawnId.value = 0x1FFF;
  this->currentFriendlyBlockerTime = -1;
  this->currentEnemySuspectedPos.bValid = false;
  this->lEnemyTrailPos[0].bValid = false;
  this->lEnemyTrailPos[1].bValid = false;
  this->lEnemyTrailPos[2].bValid = false;
  this->lEnemyTrailPos[3].bValid = false;
  this->lEnemyTrailPos[4].bValid = false;
  this->nextEnemyTrailTime = -10000;
  this->iEnemyTrailFinger = 0;
  this->actionEntity.spawnId.value = 0x1FFF;
  this->transitionEntity.spawnId.value = 0x1FFF;
  this->spottedEnemyTrigger.spawnId.value = 0x1FFF;
  this->detectedEnemyTrigger.spawnId.value = 0x1FFF;
  this->usedProp.spawnId.value = 0x1FFF;
  this->nearbyPossessed.spawnId.value = 0x1FFF;
  this->endOpenCombatTime = -1;
  this->openCombatCoverCheckTime = -1;
  this->spawnPosition.x = -3.4028235e38;
  this->spawnPosition.y = -3.4028235e38;
  this->spawnPosition.z = -3.4028235e38;
  this->spawnTime = -1;
  idAICover::idAICover(this: &this->invalidCover);
  idAICover::idAICover(this: &this->currentCover);
  idAICover::idAICover(this: &this->lastCover);
  lCoverHistory = this->lCoverHistory;
  `eh vector constructor iterator'(
    ptr: this->lCoverHistory,
    size: 0xCu,
    count: 5,
    pCtor: (void (__fastcall *)(void *))idAICover::idAICover,
    pDtor: (void (__fastcall *)(void *))idPhysics_StaticMulti::UpdateTime);
  this->nextCoverActionTime = -1;
  this->endCoverActionTime = -1;
  this->endBurstTime = -1;
  this->nextBurstTime = -1;
  this->exitCoverTime = -1;
  this->reachedCoverTime = -1;
  this->coverExposedTime = -1;
  this->newCoverSet = false;
  this->forceCharge = false;
  this->currentPath.spawnId.value = 0x1FFF;
  this->nextPath.spawnId.value = 0x1FFF;
  this->lastDamageTime = -1;
  this->lastStunTime = -1;
  this->lastFiredAtTime = -10000;
  this->lastAimedAtTime = -10000;
  this->lastHeavyAimedAtTime = -10000;
  this->endHeavyAimedAtTime = -10000;
  this->lastHeavyFiredAtTime = -10000;
  this->justAimedAtTime = -10000;
  this->lastSurprisedTime = -10000;
  this->lastFireTime = -10000;
  this->lastIntimidationTime = -10000;
  this->startIntimidationTime = -10000;
  this->armorPopOffAccumulation = 0;
  this->lastAttacker.spawnId.value = 0x1FFF;
  this->lastInflictor.spawnId.value = 0x1FFF;
  this->lastToucher.spawnId.value = 0x1FFF;
  this->justTouched = false;
  this->entityToPush.spawnId.value = 0x1FFF;
  this->searchAction = ANIMOVERRIDE_NONE;
  this->highestAlertCycle = ALERTCYCLE_RELAXED;
  this->enemyPathBlocked = false;
  this->allowCombat = true;
  this->allowSearch = true;
  this->searchToStimulusMode = AISEARCH_TO_STIMULUS_NONE;
  this->enemyTravelTime = 0;
  this->enemyApproachPoint.x = 0.0;
  this->enemyApproachPoint.y = 0.0;
  this->enemyApproachPoint.z = 0.0;
  this->animAfterOverride = AIMEMORY_ANIMAFTER_OVERRIDE_DEFAULT;
  idAICover::idAICover(this: &this->cachedCover);
  this->cachedDestination.x = -3.4028235e38;
  this->cachedDestination.y = -3.4028235e38;
  this->cachedDestination.z = -3.4028235e38;
  this->currentSearchHintIndex = 0;
  this->flags = 0;
  this->nextCloseMeleeTime = -1;
  this->nextMoveTime = -1;
  this->lastMoveFailedTime = -1073741824;
  this->nextDodgeTime = -1;
  this->movementStartTime = -1;
  this->movementMaxDuration = -1;
  this->movementFailedTime = -1;
  this->lastChargeTime = -1;
  this->nextChargeTime = -1;
  this->retryCombatTime = -1;
  this->ignoredProjectile.spawnId.value = 0x1FFF;
  this->avoidEntity.spawnId.value = 0x1FFF;
  this->avoidancePoint.x = -3.4028235e38;
  this->avoidancePoint.y = -3.4028235e38;
  this->avoidancePoint.z = -3.4028235e38;
  this->avoidanceDir.x = 0.0;
  this->avoidanceDir.y = 0.0;
  this->avoidanceDir.z = 0.0;
  this->lastAvoidTime = -1;
  this->lastDiveTime = -1;
  this->miscVec3.x = 0.0;
  this->miscVec3.y = 0.0;
  this->miscVec3.z = 0.0;
  this->nextLeapAttackTime = -1;
  this->leapTarget.x = 0.0;
  this->leapTarget.y = 0.0;
  this->leapTarget.z = 0.0;
  this->projectileInfo.coverAction = COVERACTION_MAX;
  this->projectileInfo.itemDecl = nullptr;
  this->projectileInfo.actualTargetPos.x = 0.0;
  this->projectileInfo.actualTargetPos.y = 0.0;
  this->projectileInfo.actualTargetPos.z = 0.0;
  this->projectileInfo.actualTargetVel.x = 0.0;
  this->projectileInfo.actualTargetVel.y = 0.0;
  this->projectileInfo.actualTargetVel.z = 0.0;
  this->projectileInfo.predictedTargetPos.x = 0.0;
  this->projectileInfo.predictedTargetPos.y = 0.0;
  this->projectileInfo.predictedTargetPos.z = 0.0;
  this->projectileInfo.nodeIndex.value = -1;
  this->projectileInfo.overrideAnim = ANIMOVERRIDE_NONE;
  this->projectileInfo.jointIndex.value = -1;
  this->projectileInfo.useMuzzleForLaunch = false;
  this->projectileInfo.target.spawnId.value = 0x1FFF;
  this->projectileInfo.linearParms.time = 0.0;
  this->projectileInfo.linearParms.speed = 0.0;
  this->projectileInfo.linearParms.gravity = 0.0;
  this->projectileInfo.parabolicParms.time = 0.0;
  this->projectileInfo.parabolicParms.speed = 0.0;
  this->projectileInfo.parabolicParms.gravity = 0.0;
  this->projectileInfo.parabolicParms.angle = 0.0;
  this->projectileInfo.parabolicParms.maxHeight = 0.0;
  this->projectileInfo.parabolicParms.horizSpeed = 0.0;
  this->projectileInfo.parabolicParms.vertSpeed = 0.0;
  this->nextThrowTime = -1;
  this->loopAnimExitAtEnd.waitTimeMS = 0;
  this->loopAnimExitAtEnd.endFramesFromEnd = 0;
  this->loopAnimExitAtEnd.numFrames = 0;
  this->loopAnimExitAtEnd.frameRate = 0;
  this->loopAnimExitAtEnd.startAnimTime = 0;
  this->loopAnimExitAtEnd.startingAnimFrameOn = 0;
  this->waitExpireTime = -1;
  this->confidenceLevel = AICONFIDENCE_FEARLESS;
  this->fireBlocker.spawnId.value = 0x1FFF;
  this->numShotsThisPullBlockedConsecutive = 0;
  this->numShotsThisPullBlocked = 0;
  this->numShotsThisPull = 0;
  this->muzzleInSolid = false;
  this->temporaryHoldFire = false;
  this->shouldCrouch = false;
  this->wantAngryRageTime = -1;
  this->wantTauntRageTime = -1;
  this->soonestAngryRageTime = -1;
  this->soonestTauntRageTime = -1;
  this->coveringFireTime = -1;
  this->pathBlockedCounter = 0;
  this->reloadSlot = EQUIP_NONE;
  this->lastActuallySeenEnemyTime = -1;
  this->painFailed = false;
  this->killedHeavily = false;
  this->backstandHint.spawnId.value = 0x1FFF;
  this->backstandRisePosition.x = -3.4028235e38;
  this->backstandRisePosition.y = -3.4028235e38;
  this->backstandRisePosition.z = -3.4028235e38;
  this->currentActionNode.spawnId.value = 0x1FFF;
  this->actionNodeNum = -1;
  this->actionNodeAnimIndex = -1;
  this->reachedActionNode = false;
  this->greetingParms.voiceMsgType = AIVOICE_MAX;
  this->greetingParms.declVoiceOver = nullptr;
  this->greetingParms.priority = AIVOICEPRIORITY_NONE;
  this->greetingParms.focusTarget = nullptr;
  this->currentPlayerInteraction = -1;
  this->interactionEntity.spawnId.value = 0x1FFF;
  this->interactionCamera.spawnId.value = 0x1FFF;
  this->interactionPoint.spawnId.value = 0x1FFF;
  this->completeJobDecl = nullptr;
  this->acceptJobDecl = nullptr;
  this->triggeredInteraction.spawnId.value = 0x1FFF;
  this->interactionIsUsable = false;
  this->actionNodeBlockedTime = 0;
  this->controllingPlayer.spawnId.value = 0x1FFF;
  this->currentInteraction.spawnId.value = 0x1FFF;
  this->scriptedAggro = 0.0;
  this->scriptedAggroEndTime = 0;
  this->varName.allocedAndFlag = 20;
  this->varName.data = this->varName.baseBuffer;
  this->varName.len = 0;
  this->varName.baseBuffer[0] = 0;
  this->varOp = AIVAROP_EQUAL;
  this->varValue.allocedAndFlag = 20;
  this->varValue.data = this->varValue.baseBuffer;
  this->varValue.len = 0;
  this->varValue.baseBuffer[0] = 0;
  this->scenePointVolumes.list = nullptr;
  p_scenePointVolumes = &this->scenePointVolumes;
  this->scenePointVolumes.granularity = 0;
  this->scenePointVolumes.memTag = 5;
  this->scenePointVolumes.listStatic = 0;
  this->scenePointVolumes.size = 0;
  this->scenePointVolumes.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->scenePointVolumes);
  this->combatScenePoints.scenePointList.list = nullptr;
  this->combatScenePoints.scenePointList.granularity = 0;
  p_combatScenePoints = &this->combatScenePoints;
  this->combatScenePoints.scenePointList.memTag = 5;
  this->combatScenePoints.scenePointList.listStatic = 0;
  this->combatScenePoints.scenePointList.size = 0;
  this->combatScenePoints.scenePointList.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->combatScenePoints);
  this->searchScenePoints.scenePointList.list = nullptr;
  this->searchScenePoints.scenePointList.granularity = 0;
  p_searchScenePoints = &this->searchScenePoints;
  this->searchScenePoints.scenePointList.memTag = 5;
  this->searchScenePoints.scenePointList.listStatic = 0;
  this->searchScenePoints.scenePointList.size = 0;
  this->searchScenePoints.scenePointList.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->searchScenePoints);
  this->roamScenePoints.scenePointList.list = nullptr;
  this->roamScenePoints.scenePointList.granularity = 0;
  p_roamScenePoints = &this->roamScenePoints;
  this->roamScenePoints.scenePointList.memTag = 5;
  this->roamScenePoints.scenePointList.listStatic = 0;
  this->roamScenePoints.scenePointList.size = 0;
  this->roamScenePoints.scenePointList.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->roamScenePoints);
  this->lookScenePoints.scenePointList.list = nullptr;
  this->lookScenePoints.scenePointList.granularity = 0;
  p_lookScenePoints = &this->lookScenePoints;
  this->lookScenePoints.scenePointList.memTag = 5;
  this->lookScenePoints.scenePointList.listStatic = 0;
  this->lookScenePoints.scenePointList.size = 0;
  this->lookScenePoints.scenePointList.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->lookScenePoints);
  this->curScenePoint = nullptr;
  this->curLookScenePoint = nullptr;
  this->overrideScenePoint = nullptr;
  this->keptOverrideScenePoint = nullptr;
  this->lastScenePointSearchTime = 0;
  this->lastLookScenePointSearchTime = 0;
  this->curScenePointDirty = false;
  this->curScenePointTakeTime = -1;
  this->curScenePointActivateTime = -1;
  this->curLookScenePointDirty = false;
  this->scenePointUserGroup.spawnId.value = 0x1FFF;
  v8 = 5;
  this->restrictionVolume.spawnId.value = 0x1FFF;
  this->restrictionPos.bValid = false;
  this->restrictionVolumeActive = false;
  this->restrictionStopOnEnter = false;
  this->restrictionPos.bValid = false;
  this->currentEnemySuspectedPos.bValid = false;
  this->lEnemyTrailPos[0].bValid = false;
  this->lEnemyTrailPos[1].bValid = false;
  this->lEnemyTrailPos[2].bValid = false;
  this->lEnemyTrailPos[3].bValid = false;
  this->lEnemyTrailPos[4].bValid = false;
  do
  {
    idAICover::idAICover(this: lCoverHistory);
    --v8;
    ++lCoverHistory;
  }
  while ( v8 != 0 );
  if ( this->scenePointVolumes.listStatic == 0 || this->scenePointVolumes.listStatic == 2 )
  {
    if ( p_scenePointVolumes->list != nullptr )
      idMem::Free(this: &mem, ptr: p_scenePointVolumes->list, align: ALIGN_16);
    p_scenePointVolumes->list = nullptr;
    this->scenePointVolumes.size = 0;
  }
  this->scenePointVolumes.num = 0;
  v9 = &this->scenePointHistory[4];
  for ( i = 5; i != 0; --i )
  {
    *(v9 - 4) = nullptr;
    *++v9 = nullptr;
  }
  if ( this->combatScenePoints.scenePointList.listStatic == 0 || this->combatScenePoints.scenePointList.listStatic == 2 )
  {
    if ( p_combatScenePoints->scenePointList.list != nullptr )
      idMem::Free(this: &mem, ptr: p_combatScenePoints->scenePointList.list, align: ALIGN_16);
    p_combatScenePoints->scenePointList.list = nullptr;
    this->combatScenePoints.scenePointList.size = 0;
  }
  this->combatScenePoints.scenePointList.num = 0;
  this->combatScenePoints.hasSearchedForScenePoints = false;
  if ( this->searchScenePoints.scenePointList.listStatic == 0 || this->searchScenePoints.scenePointList.listStatic == 2 )
  {
    if ( p_searchScenePoints->scenePointList.list != nullptr )
      idMem::Free(this: &mem, ptr: p_searchScenePoints->scenePointList.list, align: ALIGN_16);
    p_searchScenePoints->scenePointList.list = nullptr;
    this->searchScenePoints.scenePointList.size = 0;
  }
  this->searchScenePoints.scenePointList.num = 0;
  this->searchScenePoints.hasSearchedForScenePoints = false;
  if ( this->roamScenePoints.scenePointList.listStatic == 0 || this->roamScenePoints.scenePointList.listStatic == 2 )
  {
    if ( p_roamScenePoints->scenePointList.list != nullptr )
      idMem::Free(this: &mem, ptr: p_roamScenePoints->scenePointList.list, align: ALIGN_16);
    p_roamScenePoints->scenePointList.list = nullptr;
    this->roamScenePoints.scenePointList.size = 0;
  }
  this->roamScenePoints.hasSearchedForScenePoints = false;
  this->roamScenePoints.scenePointList.num = 0;
  if ( this->lookScenePoints.scenePointList.listStatic == 0 || this->lookScenePoints.scenePointList.listStatic == 2 )
  {
    if ( p_lookScenePoints->scenePointList.list != nullptr )
      idMem::Free(this: &mem, ptr: p_lookScenePoints->scenePointList.list, align: ALIGN_16);
    p_lookScenePoints->scenePointList.list = nullptr;
    this->lookScenePoints.scenePointList.size = 0;
  }
  this->lookScenePoints.scenePointList.num = 0;
  this->lookScenePoints.hasSearchedForScenePoints = false;
  return this;
}


// ========================================================================
// __unwind$491159
// EA  : 0x82A5432C
// RVA : 0x00A5432C
// PDB : w:\tech5\tungsten\game\ai\aimemory.cpp
// ========================================================================

void _unwind_491159()
{
  int v0; // r12

  idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)(*(_DWORD *)(v0 - 256 + 276) + 188));
}


// ========================================================================
// __unwind$491160
// EA  : 0x82A54358
// RVA : 0x00A54358
// PDB : w:\tech5\tungsten\game\ai\aimemory.cpp
// ========================================================================

void _unwind_491160()
{
  int v0; // r12

  idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)(*(_DWORD *)(v0 - 256 + 276) + 200));
}


// ========================================================================
// __unwind$491161
// EA  : 0x82A54384
// RVA : 0x00A54384
// PDB : w:\tech5\tungsten\game\ai\aimemory.cpp
// ========================================================================

void _unwind_491161()
{
  int v0; // r12

  idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)(*(_DWORD *)(v0 - 256 + 276) + 212));
}


// ========================================================================
// __unwind$491162
// EA  : 0x82A543B0
// RVA : 0x00A543B0
// PDB : w:\tech5\tungsten\game\ai\aimemory.cpp
// ========================================================================

void _unwind_491162()
{
  int v0; // r12

  `eh vector destructor iterator'(
    ptr: (void *)(*(_DWORD *)(v0 - 256 + 276) + 224),
    size: 0xCu,
    count: 5,
    pDtor: (void (__fastcall *)(void *))idPhysics_StaticMulti::UpdateTime);
}


// ========================================================================
// __unwind$491163
// EA  : 0x82A543EC
// RVA : 0x00A543EC
// PDB : w:\tech5\tungsten\game\ai\aimemory.cpp
// ========================================================================

void _unwind_491163()
{
  int v0; // r12

  idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)(*(_DWORD *)(v0 - 256 + 276) + 432));
}


// ========================================================================
// __unwind$491164
// EA  : 0x82A54418
// RVA : 0x00A54418
// PDB : w:\tech5\tungsten\game\ai\aimemory.cpp
// ========================================================================

void _unwind_491164()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 256 + 276) + 896));
}


// ========================================================================
// __unwind$491165
// EA  : 0x82A54444
// RVA : 0x00A54444
// PDB : w:\tech5\tungsten\game\ai\aimemory.cpp
// ========================================================================

void _unwind_491165()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 256 + 276) + 932));
}


// ========================================================================
// __unwind$491166
// EA  : 0x82A54470
// RVA : 0x00A54470
// PDB : w:\tech5\tungsten\game\ai\aimemory.cpp
// ========================================================================

void _unwind_491166()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 256 + 276) + 964));
}


// ========================================================================
// __unwind$491167
// EA  : 0x82A5449C
// RVA : 0x00A5449C
// PDB : w:\tech5\tungsten\game\ai\aimemory.cpp
// ========================================================================

void _unwind_491167()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 256 + 276) + 980));
}


// ========================================================================
// __unwind$491168
// EA  : 0x82A544C8
// RVA : 0x00A544C8
// PDB : w:\tech5\tungsten\game\ai\aimemory.cpp
// ========================================================================

void _unwind_491168()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 256 + 276) + 1000));
}


// ========================================================================
// __unwind$491169
// EA  : 0x82A544F4
// RVA : 0x00A544F4
// PDB : w:\tech5\tungsten\game\ai\aimemory.cpp
// ========================================================================

void _unwind_491169()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 256 + 276) + 1020));
}


// ========================================================================
// __unwind$491170
// EA  : 0x82A54520
// RVA : 0x00A54520
// PDB : w:\tech5\tungsten\game\ai\aimemory.cpp
// ========================================================================

void _unwind_491170()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 256 + 276) + 1040));
}


// ========================================================================
// ?RemoveScenePointVolume@idAIMemory@@QAAXPAVidVolume_ScenePoints@@@Z
// EA  : 0x82A54550
// RVA : 0x00A54550
// PDB : w:\tech5\tungsten\game\ai\aimemory.cpp
// ========================================================================

void __fastcall idAIMemory::RemoveScenePointVolume(idAIMemory *this, idVolume_ScenePoints *spVolume)
{
  idList<idEntityPtr<idEntity>,58> *p_scenePointVolumes; // r3
  int v4; // r10
  int num; // r9
  int v6; // r11

  v4 = 0;
  num = this->scenePointVolumes.num;
  p_scenePointVolumes = (idList<idEntityPtr<idEntity>,58> *)&this->scenePointVolumes;
  if ( num > 0 )
  {
    v6 = 0;
    while ( (idVolume_ScenePoints *)p_scenePointVolumes->list[v6].spawnId.value != spVolume )
    {
      ++v4;
      ++v6;
      if ( v4 >= num )
        goto LABEL_8;
    }
    if ( v4 >= 0 )
      idList<idHandle<int,enum invalidAIEvent_t,-1>,5>::RemoveIndex(this: p_scenePointVolumes, index: v4);
  }
LABEL_8:
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->combatScenePoints);
  this->combatScenePoints.hasSearchedForScenePoints = false;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->searchScenePoints);
  this->searchScenePoints.hasSearchedForScenePoints = false;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->roamScenePoints);
  this->roamScenePoints.hasSearchedForScenePoints = false;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->lookScenePoints);
  this->lookScenePoints.hasSearchedForScenePoints = false;
}


// ========================================================================
// ?CheckIfDirtyScenePoint@idAIMemory@@QAA_NPAVidScenePoint@@@Z
// EA  : 0x82A54608
// RVA : 0x00A54608
// PDB : w:\tech5\tungsten\game\ai\aimemory.cpp
// ========================================================================

int __fastcall idAIMemory::CheckIfDirtyScenePoint(idAIMemory *this, idScenePoint *dirtyScenePoint)
{
  idVolume_Restriction *v4; // r29
  idScenePoint *ScenePointPos; // r3
  idAIMemory::idScenePointList *p_combatScenePoints; // r26
  idAIMemory::idScenePointList *p_searchScenePoints; // r25
  idAIMemory::idScenePointList *p_roamScenePoints; // r27
  int v9; // r29
  int v10; // r28
  int v11; // r29
  int num; // r27
  int v13; // r30
  idGameLocal *v14; // r10
  int value; // r9
  idScenePoint *v16; // r3
  idScenePoint *v17; // r3
  int v19; // r29
  int v20; // r27
  int v21; // r30
  idGameLocal *v22; // r10
  int v23; // r9
  idScenePoint *v24; // r3
  idScenePoint *v25; // r3
  int v26; // r29
  int v27; // r28
  int v28; // r30
  idEntityPtr<idVolume_Restriction> v29; // [sp+50h] [-80h] BYREF
  int v30; // [sp+58h] [-78h] BYREF
  idList<idDeclVehicleUpgrade const *,5> v31[6]; // [sp+70h] [-60h] BYREF

  if ( !this->curScenePointDirty )
    return 0;
  this->curScenePointDirty = false;
  if ( dirtyScenePoint == nullptr )
    return 1;
  if ( dirtyScenePoint->type == LOOK )
    return 1;
  if ( dirtyScenePoint != this->curScenePoint )
    return 1;
  if ( idAIMemory::HasRestrictionVolume(this) )
  {
    v29.spawnId.value = this->restrictionVolume.spawnId.value;
    v4 = idEntityPtr<idVolume_Restriction>::operator idVolume_Restriction *(this: &v29);
    ScenePointPos = idScenePoint::GetScenePointPos(this: (idScenePoint *)&v30, result: dirtyScenePoint);
    if ( !idVolume_ItemGroup::Contains(this: v4, pos: (const idVec3 *)ScenePointPos) )
      return 1;
  }
  p_combatScenePoints = &this->combatScenePoints;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->combatScenePoints);
  this->combatScenePoints.hasSearchedForScenePoints = false;
  p_searchScenePoints = &this->searchScenePoints;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->searchScenePoints);
  this->searchScenePoints.hasSearchedForScenePoints = false;
  p_roamScenePoints = &this->roamScenePoints;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->roamScenePoints);
  this->roamScenePoints.hasSearchedForScenePoints = false;
  idList<idVehicleKey *,5>::idList<idVehicleKey *,5>(this: v31);
  v9 = 0;
  if ( this->scenePointVolumes.num > 0 )
  {
    v10 = 0;
    do
    {
      this->scenePointVolumes.list[v10]->GetScenePoints(
        this: this->scenePointVolumes.list[v10],
        a2: (idList<idEntityPtr<idScenePoint>,5> *)v31,
        a3: dirtyScenePoint->type,
        a4: (idEntityPtr<idVolume_Restriction> *)this->restrictionVolume.spawnId.value,
        a5: (idEntityPtr<idScenePoint_UserGroup> *)this->scenePointUserGroup.spawnId.value);
      ++v9;
      ++v10;
    }
    while ( v9 < this->scenePointVolumes.num );
  }
  v29.spawnId.value = dirtyScenePoint->type;
  switch ( v29.spawnId.value )
  {
    case 4:
      idList<idEntityPtr<idAISearchHintGroup>,5>::operator=(
        this: (idList<idEntityPtr<idAISearchHintGroup>,5> *)&this->combatScenePoints,
        other: (const idList<idEntityPtr<idAISearchHintGroup>,5> *)v31);
      v11 = 0;
      num = this->combatScenePoints.scenePointList.num;
      if ( num > 0 )
      {
        v13 = 0;
        v14 = gameLocal;
        while ( 1 )
        {
          value = p_combatScenePoints->scenePointList.list[v13].spawnId.value;
          if ( v14->spawnIds.ptr[value & 0x1FFF] == value >> 13
            && (v16 = (idScenePoint *)v14->entities.ptr[value & 0x1FFF]) != nullptr )
          {
            v17 = idScenePoint::CastTo(c: v16);
            v14 = gameLocal;
          }
          else
          {
            v17 = nullptr;
          }
          if ( v17 == dirtyScenePoint )
            break;
          ++v11;
          ++v13;
          if ( v11 >= num )
            goto LABEL_40;
        }
        idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)v31);
        return 0;
      }
      break;
    case 3:
      idList<idEntityPtr<idAISearchHintGroup>,5>::operator=(
        this: (idList<idEntityPtr<idAISearchHintGroup>,5> *)&this->searchScenePoints,
        other: (const idList<idEntityPtr<idAISearchHintGroup>,5> *)v31);
      v19 = 0;
      v20 = this->searchScenePoints.scenePointList.num;
      if ( v20 > 0 )
      {
        v21 = 0;
        v22 = gameLocal;
        while ( 1 )
        {
          v23 = p_searchScenePoints->scenePointList.list[v21].spawnId.value;
          if ( v22->spawnIds.ptr[v23 & 0x1FFF] == v23 >> 13
            && (v24 = (idScenePoint *)v22->entities.ptr[v23 & 0x1FFF]) != nullptr )
          {
            v25 = idScenePoint::CastTo(c: v24);
            v22 = gameLocal;
          }
          else
          {
            v25 = nullptr;
          }
          if ( v25 == dirtyScenePoint )
            break;
          ++v19;
          ++v21;
          if ( v19 >= v20 )
            goto LABEL_40;
        }
LABEL_32:
        idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)v31);
        return 0;
      }
      break;
    case 1:
      idList<idEntityPtr<idAISearchHintGroup>,5>::operator=(
        this: (idList<idEntityPtr<idAISearchHintGroup>,5> *)&this->roamScenePoints,
        other: (const idList<idEntityPtr<idAISearchHintGroup>,5> *)v31);
      v26 = 0;
      v27 = this->roamScenePoints.scenePointList.num;
      if ( v27 > 0 )
      {
        v28 = 0;
        while ( idEntityPtr<idScenePoint>::operator idScenePoint *(this: &p_roamScenePoints->scenePointList.list[v28]) != dirtyScenePoint )
        {
          ++v26;
          ++v28;
          if ( v26 >= v27 )
            goto LABEL_40;
        }
        goto LABEL_32;
      }
      break;
    default:
      break;
  }
LABEL_40:
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)v31);
  return 1;
}


// ========================================================================
// __unwind$492968
// EA  : 0x82A548F0
// RVA : 0x00A548F0
// PDB : w:\tech5\tungsten\game\ai\aimemory.cpp
// ========================================================================

void _unwind_492968()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 208 + 112));
}


// ========================================================================
// ?CheckIfDirtyLookScenePoint@idAIMemory@@QAA_NPAVidScenePoint@@@Z
// EA  : 0x82A54920
// RVA : 0x00A54920
// PDB : w:\tech5\tungsten\game\ai\aimemory.cpp
// ========================================================================

int __fastcall idAIMemory::CheckIfDirtyLookScenePoint(idAIMemory *this, idScenePoint *dirtyLookScenePoint)
{
  idScenePoint *curLookScenePoint; // r11
  idList<idEntityPtr<idAISearchHintGroup>,5> *p_lookScenePoints; // r26
  int v6; // r28
  int v7; // r29
  int v8; // r29
  int num; // r27
  int v10; // r30
  idGameLocal *v11; // r10
  int value; // r9
  idScenePoint *v13; // r3
  idScenePoint *v14; // r3
  idList<idDeclVehicleUpgrade const *,5> v16[6]; // [sp+50h] [-60h] BYREF

  curLookScenePoint = this->curLookScenePoint;
  if ( curLookScenePoint != nullptr && this->curLookScenePointDirty )
  {
    this->curLookScenePointDirty = false;
    if ( dirtyLookScenePoint != nullptr && dirtyLookScenePoint->type == LOOK && dirtyLookScenePoint == curLookScenePoint )
    {
      p_lookScenePoints = (idList<idEntityPtr<idAISearchHintGroup>,5> *)&this->lookScenePoints;
      idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->lookScenePoints);
      this->lookScenePoints.hasSearchedForScenePoints = false;
      idList<idVehicleKey *,5>::idList<idVehicleKey *,5>(this: v16);
      v6 = 0;
      if ( this->scenePointVolumes.num > 0 )
      {
        v7 = 0;
        do
        {
          this->scenePointVolumes.list[v7]->GetScenePoints(
            this: this->scenePointVolumes.list[v7],
            a2: (idList<idEntityPtr<idScenePoint>,5> *)v16,
            a3: LOOK,
            a4: (idEntityPtr<idVolume_Restriction> *)0x1FFF,
            a5: (idEntityPtr<idScenePoint_UserGroup> *)this->scenePointUserGroup.spawnId.value);
          ++v6;
          ++v7;
        }
        while ( v6 < this->scenePointVolumes.num );
      }
      idList<idEntityPtr<idAISearchHintGroup>,5>::operator=(
        this: p_lookScenePoints,
        other: (const idList<idEntityPtr<idAISearchHintGroup>,5> *)v16);
      v8 = 0;
      num = this->lookScenePoints.scenePointList.num;
      if ( num <= 0 )
      {
LABEL_17:
        idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)v16);
        return 1;
      }
      v10 = 0;
      v11 = gameLocal;
      while ( 1 )
      {
        value = p_lookScenePoints->list[v10].spawnId.value;
        if ( v11->spawnIds.ptr[value & 0x1FFF] == value >> 13
          && (v13 = (idScenePoint *)v11->entities.ptr[value & 0x1FFF]) != nullptr )
        {
          v14 = idScenePoint::CastTo(c: v13);
          v11 = gameLocal;
        }
        else
        {
          v14 = nullptr;
        }
        if ( v14 == dirtyLookScenePoint )
          break;
        ++v8;
        ++v10;
        if ( v8 >= num )
          goto LABEL_17;
      }
      idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)v16);
    }
  }
  return 0;
}


// ========================================================================
// __unwind$493216
// EA  : 0x82A54A8C
// RVA : 0x00A54A8C
// PDB : w:\tech5\tungsten\game\ai\aimemory.cpp
// ========================================================================

void _unwind_493216()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 176 + 80));
}


// ========================================================================
// ?GetScenePoints@idAIMemory@@QAAXAAV?$idList@V?$idEntityPtr@VidScenePoint@@@@$04@@W4scenePointType_t@@@Z
// EA  : 0x82A54AB8
// RVA : 0x00A54AB8
// PDB : w:\tech5\tungsten\game\ai\aimemory.cpp
// ========================================================================

void __fastcall idAIMemory::GetScenePoints(
        idAIMemory *this,
        idList<idEntityPtr<idAISearchHintGroup>,5> *spList,
        scenePointType_t spType)
{
  int num; // r30
  int v7; // r29

  switch ( spType )
  {
    case 4:
      if ( this->combatScenePoints.scenePointList.num > 0 || this->combatScenePoints.hasSearchedForScenePoints )
      {
        idList<idEntityPtr<idAISearchHintGroup>,5>::operator=(
          this: spList,
          other: (const idList<idEntityPtr<idAISearchHintGroup>,5> *)&this->combatScenePoints);
        return;
      }
      break;
    case 3:
      if ( this->searchScenePoints.scenePointList.num > 0 || this->searchScenePoints.hasSearchedForScenePoints )
      {
        idList<idEntityPtr<idAISearchHintGroup>,5>::operator=(
          this: spList,
          other: (const idList<idEntityPtr<idAISearchHintGroup>,5> *)&this->searchScenePoints);
        return;
      }
      break;
    case 1:
      if ( this->roamScenePoints.scenePointList.num > 0 || this->roamScenePoints.hasSearchedForScenePoints )
      {
        idList<idEntityPtr<idAISearchHintGroup>,5>::operator=(
          this: spList,
          other: (const idList<idEntityPtr<idAISearchHintGroup>,5> *)&this->roamScenePoints);
        return;
      }
      break;
    default:
      if ( spType == LOOK
        && (this->lookScenePoints.scenePointList.num > 0 || this->lookScenePoints.hasSearchedForScenePoints) )
      {
        idList<idEntityPtr<idAISearchHintGroup>,5>::operator=(
          this: spList,
          other: (const idList<idEntityPtr<idAISearchHintGroup>,5> *)&this->lookScenePoints);
        return;
      }
      break;
  }
  num = this->scenePointVolumes.num;
  if ( num > 0 )
  {
    v7 = 0;
    do
    {
      this->scenePointVolumes.list[v7]->GetScenePoints(
        this: this->scenePointVolumes.list[v7],
        a2: (idList<idEntityPtr<idScenePoint>,5> *)spList,
        a3: spType,
        a4: (idEntityPtr<idVolume_Restriction> *)this->restrictionVolume.spawnId.value,
        a5: (idEntityPtr<idScenePoint_UserGroup> *)this->scenePointUserGroup.spawnId.value);
      --num;
      ++v7;
    }
    while ( num != 0 );
    switch ( spType )
    {
      case 4:
        idList<idEntityPtr<idAISearchHintGroup>,5>::operator=(
          this: (idList<idEntityPtr<idAISearchHintGroup>,5> *)&this->combatScenePoints,
          other: spList);
        this->combatScenePoints.hasSearchedForScenePoints = true;
        break;
      case 3:
        idList<idEntityPtr<idAISearchHintGroup>,5>::operator=(
          this: (idList<idEntityPtr<idAISearchHintGroup>,5> *)&this->searchScenePoints,
          other: spList);
        this->searchScenePoints.hasSearchedForScenePoints = true;
        break;
      case 1:
        idList<idEntityPtr<idAISearchHintGroup>,5>::operator=(
          this: (idList<idEntityPtr<idAISearchHintGroup>,5> *)&this->roamScenePoints,
          other: spList);
        this->roamScenePoints.hasSearchedForScenePoints = true;
        break;
      case 2:
        idList<idEntityPtr<idAISearchHintGroup>,5>::operator=(
          this: (idList<idEntityPtr<idAISearchHintGroup>,5> *)&this->lookScenePoints,
          other: spList);
        this->lookScenePoints.hasSearchedForScenePoints = true;
        break;
      default:
        break;
    }
  }
}


// ========================================================================
// ?SetScenePointUserGroup@idAIMemory@@QAAXV?$idEntityPtr@VidScenePoint_UserGroup@@@@@Z
// EA  : 0x82A54C78
// RVA : 0x00A54C78
// PDB : w:\tech5\tungsten\game\ai\aimemory.cpp
// ========================================================================

void __fastcall idAIMemory::SetScenePointUserGroup(idAIMemory *this, idEntityPtr<idScenePoint_UserGroup> *group)
{
  this->scenePointUserGroup.spawnId.value = (int)group;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->combatScenePoints);
  this->combatScenePoints.hasSearchedForScenePoints = false;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->searchScenePoints);
  this->searchScenePoints.hasSearchedForScenePoints = false;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->roamScenePoints);
  this->roamScenePoints.hasSearchedForScenePoints = false;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->lookScenePoints);
  this->lookScenePoints.hasSearchedForScenePoints = false;
}


// ========================================================================
// ?AddScenePointVolume@idAIMemory@@QAAXPAVidVolume_ScenePoints@@@Z
// EA  : 0x82A54CE0
// RVA : 0x00A54CE0
// PDB : w:\tech5\tungsten\game\ai\aimemory.cpp
// ========================================================================

void __fastcall idAIMemory::AddScenePointVolume(
        idAIMemory *this,
        idVolume_ScenePoints *spVolume,
        int a3,
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
        idVolume_ScenePoints *a14)
{
  idList<enum encounterGroupRole_t,5> *p_scenePointVolumes; // r3
  int v16; // r10
  int num; // r9
  int v18; // r11

  a14 = spVolume;
  v16 = 0;
  num = this->scenePointVolumes.num;
  p_scenePointVolumes = (idList<enum encounterGroupRole_t,5> *)&this->scenePointVolumes;
  if ( num <= 0 )
    goto LABEL_7;
  v18 = 0;
  while ( (idVolume_ScenePoints *)p_scenePointVolumes->list[v18] != spVolume )
  {
    ++v16;
    ++v18;
    if ( v16 >= num )
      goto LABEL_7;
  }
  if ( v16 < 0 )
LABEL_7:
    idList<idAnimWebBlendTree *,5>::Append(this: p_scenePointVolumes, obj: (const encounterGroupRole_t *)&a14);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->combatScenePoints);
  this->combatScenePoints.hasSearchedForScenePoints = false;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->searchScenePoints);
  this->searchScenePoints.hasSearchedForScenePoints = false;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->roamScenePoints);
  this->roamScenePoints.hasSearchedForScenePoints = false;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->lookScenePoints);
  this->lookScenePoints.hasSearchedForScenePoints = false;
}

