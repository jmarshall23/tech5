
// ========================================================================
// ??0idAILogic@@QAA@ABVidSpawnId@@0PAVidEncounterGroup@@PAVidFaction@@MM_N3@Z
// EA  : 0x82AF8170
// RVA : 0x00AF8170
// PDB : w:\tech5\tungsten\game\ai\gamestate\aientitystate.cpp
// ========================================================================

idAILogic *__fastcall idAILogic::idAILogic(
        idAILogic *this,
        const idSpawnId *spawnId_,
        const idSpawnId *curEnemyId_,
        idEncounterGroup *encounterGroup_,
        idFaction *faction_,
        double combatTimeoutInterval_,
        double searchTimeoutInterval_,
        const bool isRelaxed_,
        const bool isSearching_,
        bool a10,
        int a11,
        int a12,
        int a13,
        int a14,
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
        bool a30)
{
  int value; // r5

  this->spawnId = (idSpawnId)spawnId_->value;
  value = curEnemyId_->value;
  this->combatTimeoutInterval = combatTimeoutInterval_;
  this->searchTimeoutInterval = searchTimeoutInterval_;
  this->curEnemyId.value = value;
  this->isRelaxed = a10;
  this->isSearching = a30;
  this->slowIdleSpot = false;
  this->pausePerception = false;
  this->encounterGroup = encounterGroup_;
  this->faction = faction_;
  return this;
}


// ========================================================================
// ?TraceVisible@@YA_NPBUaiLatchedState_t@@AAUtrace_t@@@Z
// EA  : 0x82AF81B0
// RVA : 0x00AF81B0
// PDB : w:\tech5\tungsten\game\ai\gamestate\aientitystate.cpp
// ========================================================================

int __fastcall TraceVisible(const aiLatchedState_t *dls, trace_t *tr)
{
  int EntityNumber; // r29
  int v5; // r3
  int entityNum; // r11
  int result; // r3
  bool v8; // zf

  if ( tr->fraction >= 1.0 )
    return 1;
  EntityNumber = idSpawnId::GetEntityNumber(this: &dls->spawnId);
  v5 = idSpawnId::GetEntityNumber(this: &dls->masterId);
  entityNum = tr->c.entityNum;
  if ( entityNum == EntityNumber )
    return 1;
  v8 = entityNum != v5;
  result = 0;
  if ( !v8 )
    return 1;
  return result;
}


// ========================================================================
// ?GetEntity@idAIEntityState@@QBAPAVidEntity@@XZ
// EA  : 0x82AF8210
// RVA : 0x00AF8210
// PDB : w:\tech5\tungsten\game\ai\gamestate\aientitystate.cpp
// ========================================================================

idEntity *__fastcall idAIEntityState::GetEntity(idAIEntityState *this)
{
  return gameLocal->GetEntityForSpawnId(this: gameLocal, a2: (const idSpawnId *)this->spawnId.value);
}


// ========================================================================
// ??0aiPhysicalState_t@@QAA@XZ
// EA  : 0x82AF82E8
// RVA : 0x00AF82E8
// PDB : w:\tech5\tungsten\game\ai\gamestate\aientitystate.cpp
// ========================================================================

aiPhysicalState_t *__fastcall aiPhysicalState_t::aiPhysicalState_t(aiPhysicalState_t *this)
{
  this->origin.x = 0.0;
  this->origin.y = 0.0;
  this->origin.z = 0.0;
  this->velocity.x = 0.0;
  this->velocity.y = 0.0;
  this->velocity.z = 0.0;
  this->rotation = quat_identity;
  this->viewfwd.x = 1.0;
  this->viewfwd.y = 0.0;
  this->viewfwd.z = 0.0;
  this->eyePos.x = 0.0;
  this->eyePos.y = 0.0;
  this->eyePos.z = 0.0;
  this->crouchChangeDelta = 0;
  this->entFlags = 0;
  this->stimScale = 0;
  this->bounds.b[0][2] = 0x7FFF;
  this->bounds.b[0][1] = 0x7FFF;
  this->bounds.b[0][0] = 0x7FFF;
  this->bounds.b[1][2] = 0x8000;
  this->bounds.b[1][1] = 0x8000;
  this->bounds.b[1][0] = 0x8000;
  return this;
}


// ========================================================================
// ?GetState@idAILogic@@QBAPBUaiLatchedState_t@@XZ
// EA  : 0x82AF8388
// RVA : 0x00AF8388
// PDB : w:\tech5\tungsten\game\ai\gamestate\aientitystate.cpp
// ========================================================================

const aiLatchedState_t *__fastcall idAILogic::GetState(idAILogic *this)
{
  return idAIGameState::GetState(this: &gameLocal->aiGameState, spawnId: &this->spawnId);
}


// ========================================================================
// ??0aiSenseState_t@@QAA@XZ
// EA  : 0x82AF83A0
// RVA : 0x00AF83A0
// PDB : w:\tech5\tungsten\game\ai\gamestate\aientitystate.cpp
// ========================================================================

aiSenseState_t *__fastcall aiSenseState_t::aiSenseState_t(aiSenseState_t *this)
{
  char v1; // r4

  this->__vftable = (aiSenseState_t_vtbl *)&aiSenseState_t::`vftable';
  this->unConfirmedPhysical.origin.x = 0.0;
  this->unConfirmedPhysical.origin.y = 0.0;
  this->unConfirmedPhysical.origin.z = 0.0;
  this->unConfirmedPhysical.velocity.x = 0.0;
  this->unConfirmedPhysical.velocity.y = 0.0;
  this->unConfirmedPhysical.velocity.z = 0.0;
  this->unConfirmedPhysical.rotation = quat_identity;
  this->unConfirmedPhysical.viewfwd.x = 1.0;
  this->unConfirmedPhysical.viewfwd.y = 0.0;
  this->unConfirmedPhysical.viewfwd.z = 0.0;
  this->unConfirmedPhysical.eyePos.x = 0.0;
  this->unConfirmedPhysical.eyePos.y = 0.0;
  this->unConfirmedPhysical.eyePos.z = 0.0;
  this->unConfirmedPhysical.crouchChangeDelta = 0;
  this->unConfirmedPhysical.entFlags = 0;
  this->unConfirmedPhysical.stimScale = 0;
  this->unConfirmedPhysical.bounds.b[1][2] = 0x8000;
  this->unConfirmedPhysical.bounds.b[1][1] = 0x8000;
  this->unConfirmedPhysical.bounds.b[1][0] = 0x8000;
  this->unConfirmedPhysical.bounds.b[0][2] = 0x7FFF;
  this->unConfirmedPhysical.bounds.b[0][1] = 0x7FFF;
  this->unConfirmedPhysical.bounds.b[0][0] = 0x7FFF;
  this->lastUnconfirmedStimTime = -1;
  this->confirmedPhysical.origin.x = 0.0;
  this->confirmedPhysical.origin.y = 0.0;
  this->confirmedPhysical.origin.z = 0.0;
  this->confirmedPhysical.velocity.x = 0.0;
  this->confirmedPhysical.velocity.y = 0.0;
  this->confirmedPhysical.velocity.z = 0.0;
  this->confirmedPhysical.rotation = quat_identity;
  this->confirmedPhysical.viewfwd.x = 1.0;
  this->confirmedPhysical.viewfwd.y = 0.0;
  this->confirmedPhysical.viewfwd.z = 0.0;
  this->confirmedPhysical.eyePos.x = 0.0;
  this->confirmedPhysical.eyePos.y = 0.0;
  this->confirmedPhysical.eyePos.z = 0.0;
  this->confirmedPhysical.crouchChangeDelta = 0;
  this->confirmedPhysical.entFlags = 0;
  this->confirmedPhysical.stimScale = 0;
  this->confirmedPhysical.bounds.b[1][2] = 0x8000;
  this->confirmedPhysical.bounds.b[1][1] = 0x8000;
  this->confirmedPhysical.bounds.b[1][0] = 0x8000;
  this->confirmedPhysical.bounds.b[0][2] = 0x7FFF;
  this->confirmedPhysical.bounds.b[0][1] = 0x7FFF;
  this->confirmedPhysical.bounds.b[0][0] = 0x7FFF;
  this->lastConfirmedStimTime = -1;
  this->integrator.value = 0.0;
  v1 = *((_BYTE *)&this->integrator + 12);
  this->integrator.decayRate = 0.0;
  this->integrator.lastUpdateMS = -1;
  *((_BYTE *)&this->integrator + 12) = v1 & 0x7F;
  this->aiOrigin.x = 0.0;
  this->aiOrigin.y = 0.0;
  this->aiOrigin.z = 0.0;
  this->senseType = 0;
  this->senseFlags = 0;
  this->stimulusType = 0;
  return this;
}


// ========================================================================
// ?GetConfirmedPhysicalSafe@aiSenseState_t@@QBAABUaiPhysicalState_t@@XZ
// EA  : 0x82AF8528
// RVA : 0x00AF8528
// PDB : w:\tech5\tungsten\game\ai\gamestate\aientitystate.cpp
// ========================================================================

const aiPhysicalState_t *__fastcall aiSenseState_t::GetConfirmedPhysicalSafe(aiSenseState_t *this)
{
  if ( this->lastConfirmedStimTime >= 0 )
    return &this->confirmedPhysical;
  if ( ai_debugEnemy.valueInteger > 0 && ai_debugLevel.valueInteger >= 2 )
    idLib::Warning(fmt: "Attempting to get unconfirmed physical sense");
  return &this->unConfirmedPhysical;
}


// ========================================================================
// ?GetConfirmedStimTimeSafe@aiSenseState_t@@QBAHXZ
// EA  : 0x82AF85B0
// RVA : 0x00AF85B0
// PDB : w:\tech5\tungsten\game\ai\gamestate\aientitystate.cpp
// ========================================================================

int __fastcall aiSenseState_t::GetConfirmedStimTimeSafe(aiSenseState_t *this)
{
  int result; // r3

  result = this->lastConfirmedStimTime;
  if ( result < 0 )
    return this->lastUnconfirmedStimTime;
  return result;
}


// ========================================================================
// ?ExtrapolatePosition@aiSenseState_t@@QBAXMAAVidVec3@@@Z
// EA  : 0x82AF85C8
// RVA : 0x00AF85C8
// PDB : w:\tech5\tungsten\game\ai\gamestate\aientitystate.cpp
// ========================================================================

void __fastcall aiSenseState_t::ExtrapolatePosition(aiSenseState_t *this, double seconds, idVec3 *futurePos, float *a4)
{
  const aiPhysicalState_t *ConfirmedPhysicalSafe; // r29
  const idSpring<idVec3> *v8; // r3
  double z; // fp12
  double v10; // fp6
  double v11; // fp10
  double v12; // fp9
  double v13; // fp7

  ConfirmedPhysicalSafe = aiSenseState_t::GetConfirmedPhysicalSafe(this);
  if ( this->lastConfirmedStimTime >= 0 && this->HasSpring(this) )
  {
    v8 = this->GetSpring(this);
    *a4 = v8->p1.x;
    a4[1] = v8->p1.y;
    z = v8->p1.z;
  }
  else
  {
    *a4 = ConfirmedPhysicalSafe->origin.x;
    a4[1] = ConfirmedPhysicalSafe->origin.y;
    z = ConfirmedPhysicalSafe->origin.z;
  }
  a4[2] = z;
  v10 = a4[2];
  v11 = (float)(ConfirmedPhysicalSafe->velocity.y * (float)seconds);
  v12 = (float)(ConfirmedPhysicalSafe->velocity.z * (float)seconds);
  v13 = a4[1];
  *a4 = *a4 + (float)((float)seconds * ConfirmedPhysicalSafe->velocity.x);
  a4[1] = (float)v13 + (float)v11;
  a4[2] = (float)v12 + (float)v10;
}


// ========================================================================
// ?InitSpring@idAISenseState_Sight@@UAAXPBUaiLatchedState_t@@@Z
// EA  : 0x82AF86A8
// RVA : 0x00AF86A8
// PDB : w:\tech5\tungsten\game\ai\gamestate\aientitystate.cpp
// ========================================================================

void __fastcall idAISenseState_Sight::InitSpring(idAISenseState_Sight *this, const aiLatchedState_t *ls)
{
  this->confirmedOriginSpring.restLength = 0.0;
  this->confirmedOriginSpring.k = 1.0;
  this->confirmedOriginSpring.m = 1.0;
  this->confirmedOriginSpring.c = 2.0;
  this->confirmedOriginSpring.p0.z = 0.0;
  this->confirmedOriginSpring.p0.y = 0.0;
  this->confirmedOriginSpring.p0.x = 0.0;
  this->confirmedOriginSpring.p1.z = 0.0;
  this->confirmedOriginSpring.p1.y = 0.0;
  this->confirmedOriginSpring.p1.x = 0.0;
  this->confirmedOriginSpring.vel.z = 0.0;
  this->confirmedOriginSpring.vel.y = 0.0;
  this->confirmedOriginSpring.vel.x = 0.0;
  this->confirmedOriginSpring.maxSpeed = 0.0;
  this->confirmedOriginSpring.pMin.z = 0.0;
  this->confirmedOriginSpring.pMin.y = 0.0;
  this->confirmedOriginSpring.pMin.x = 0.0;
  this->confirmedOriginSpring.hasPMin = false;
  this->confirmedOriginSpring.pMax.z = 0.0;
  this->confirmedOriginSpring.pMax.y = 0.0;
  this->confirmedOriginSpring.pMax.x = 0.0;
  this->confirmedOriginSpring.hasPMax = false;
  if ( ls != nullptr )
  {
    this->confirmedOriginSpring.p0 = ls->physical.origin;
    this->confirmedOriginSpring.p1 = ls->physical.origin;
  }
}


// ========================================================================
// ?Update@idAISenseState_Sight@@UAAXPBUaiLatchedState_t@@@Z
// EA  : 0x82AF8760
// RVA : 0x00AF8760
// PDB : w:\tech5\tungsten\game\ai\gamestate\aientitystate.cpp
// ========================================================================

void __fastcall idAISenseState_Sight::Update(idAISenseState_Sight *this, const aiLatchedState_t *ls)
{
  double y; // fp9
  double z; // fp8
  double v4; // fp6
  double v5; // fp5

  y = ls->physical.origin.y;
  z = ls->physical.origin.z;
  v4 = (float)(ls->physical.velocity.y * ai_originSpringExtrapolate.valueFloat);
  v5 = (float)(ls->physical.velocity.z * ai_originSpringExtrapolate.valueFloat);
  this->confirmedOriginSpring.p0.x = ls->physical.origin.x
                                   + (float)(ls->physical.velocity.x * ai_originSpringExtrapolate.valueFloat);
  this->confirmedOriginSpring.p0.y = (float)y + (float)v4;
  this->confirmedOriginSpring.p0.z = (float)z + (float)v5;
}


// ========================================================================
// ??1idAIEntityState@@UAA@XZ
// EA  : 0x82AF87B0
// RVA : 0x00AF87B0
// PDB : w:\tech5\tungsten\game\ai\gamestate\aientitystate.cpp
// ========================================================================

void __fastcall idAIEntityState::~idAIEntityState(idAIEntityState *this)
{
  this->sightSense.__vftable = (idAISenseState_Sight_vtbl *)&idClass::`vftable';
  this->hearingSense.__vftable = (idAISenseState_Hearing_vtbl *)&idClass::`vftable';
  this->__vftable = (idAIEntityState_vtbl *)&idClass::`vftable';
}


// ========================================================================
// ?Init@idAIEntityState@@QAAXPBVidAIGameState@@ABVidAILogic@@ABVidSpawnId@@PBUaiLatchedState_t@@@Z
// EA  : 0x82AF87C8
// RVA : 0x00AF87C8
// PDB : w:\tech5\tungsten\game\ai\gamestate\aientitystate.cpp
// ========================================================================

void __fastcall idAIEntityState::Init(
        idAIEntityState *this,
        idAIGameState *gameState,
        const idAILogic *owner,
        const idSpawnId *entId,
        const aiLatchedState_t *ls)
{
  int *p_gameTime; // r27
  int v7; // r30
  const aiLatchedState_t *State; // r28
  char v10; // r11
  idEntity *v11; // r3
  const char *data; // r4
  float *p_restLength; // r31
  int v14; // r11
  int v15; // r9
  char v16; // r8

  p_gameTime = &gameState->gameTime;
  v7 = 2;
  State = ls;
  v10 = *((_BYTE *)this + 541) & 0x3F | 0x80;
  this->initTime = gameState->gameTime;
  this->spawnId = (idSpawnId)entId->value;
  *((_BYTE *)this + 541) = v10;
  this->lastSense = 2;
  if ( ls == nullptr )
  {
    State = idAIGameState::GetState(this: gameState, spawnId: entId);
    if ( State == nullptr )
    {
      v11 = gameLocal->GetEntityForSpawnId_2(this: gameLocal, a2: entId->value);
      if ( v11 != nullptr )
        data = v11->name.data;
      else
        data = "<NULL>";
      idLib::Error(fmt: "idAIEntityState::Init - missing latched state for entity '%s'", data);
    }
  }
  p_restLength = &this->sightSense.confirmedOriginSpring.restLength;
  this->entityType = State->entityType;
  do
  {
    v14 = *((_DWORD *)p_restLength + 1);
    v15 = *p_gameTime;
    v16 = *(_BYTE *)(v14 + 192);
    *(float *)(v14 + 180) = 0.0;
    *(float *)(v14 + 184) = -0.0;
    *(_DWORD *)(v14 + 188) = v15;
    *(_BYTE *)(v14 + 192) = v16 & 0x7F;
    ++p_restLength;
    (*(void (__fastcall **)(_DWORD, const aiLatchedState_t *))(**(_DWORD **)p_restLength + 20))(
      a1: *(_DWORD *)p_restLength,
      a2: State);
    --v7;
  }
  while ( v7 != 0 );
}


// ========================================================================
// ?UpdateSprings@idAIEntityState@@QAAXABUtrackingParms_t@@@Z
// EA  : 0x82AF88E0
// RVA : 0x00AF88E0
// PDB : w:\tech5\tungsten\game\ai\gamestate\aientitystate.cpp
// ========================================================================

void __fastcall idAIEntityState::UpdateSprings(idAIEntityState *this, const trackingParms_t *trackingParms)
{
  float *p_restLength; // r30
  int i; // r31

  p_restLength = &this->sightSense.confirmedOriginSpring.restLength;
  for ( i = 2; i != 0; --i )
  {
    ++p_restLength;
    (*(void (__fastcall **)(_DWORD, const trackingParms_t *))(**(_DWORD **)p_restLength + 28))(
      a1: *(_DWORD *)p_restLength,
      a2: trackingParms);
  }
}


// ========================================================================
// ?IsDead@idAIEntityState@@QBA_NXZ
// EA  : 0x82AF8920
// RVA : 0x00AF8920
// PDB : w:\tech5\tungsten\game\ai\gamestate\aientitystate.cpp
// ========================================================================

BOOL __fastcall idAIEntityState::IsDead(idAIEntityState *this)
{
  idEntity *v1; // r3

  v1 = gameLocal->GetEntityForSpawnId(this: gameLocal, a2: this->spawnId.value);
  return v1 == nullptr || v1->IsDead(this: v1);
}


// ========================================================================
// ?IsDying@idAIEntityState@@QBA_NXZ
// EA  : 0x82AF8988
// RVA : 0x00AF8988
// PDB : w:\tech5\tungsten\game\ai\gamestate\aientitystate.cpp
// ========================================================================

BOOL __fastcall idAIEntityState::IsDying(idAIEntityState *this)
{
  idEntity *v1; // r3

  v1 = gameLocal->GetEntityForSpawnId(this: gameLocal, a2: this->spawnId.value);
  return v1 != nullptr && v1->IsDying(this: v1);
}


// ========================================================================
// ?DecreaseAwareness@idAIEntityState@@AAAXABVidAILogic@@W4aiAwareness_t@@@Z
// EA  : 0x82AF89F0
// RVA : 0x00AF89F0
// PDB : w:\tech5\tungsten\game\ai\gamestate\aientitystate.cpp
// ========================================================================

void __fastcall idAIEntityState::DecreaseAwareness(
        idAIEntityState *this,
        const idAILogic *owner,
        aiAwareness_t newAwareness)
{
  idEntity *v5; // r3
  aiAwareness_t curAwareness; // r11
  idEventArg *v7; // r28
  int value; // r4
  idGameLocal_vtbl *v9; // r10
  const idEntity *v10; // r3
  idEventArg *v11; // r26
  _BYTE v12[20]; // [sp+70h] [-D0h] BYREF
  _DWORD v13[5]; // [sp+90h] [-B0h] BYREF
  int v14; // [sp+B0h] [-90h]
  aiAwareness_t v15; // [sp+B4h] [-8Ch]
  idEventArg v16; // [sp+D0h] [-70h] BYREF
  idEventReceiver v17[6]; // [sp+F0h] [-50h] BYREF

  v5 = gameLocal->GetEntityForSpawnId(this: gameLocal, a2: owner->spawnId.value);
  curAwareness = this->curAwareness;
  v7 = (idEventArg *)v5;
  if ( newAwareness < curAwareness )
  {
    value = this->spawnId.value;
    HIBYTE(v13[0]) = 105;
    HIBYTE(v14) = 105;
    v13[1] = newAwareness;
    v9 = gameLocal->__vftable;
    v15 = curAwareness;
    v10 = v9->GetEntityForSpawnId(this: gameLocal, a2: (const idSpawnId *)value);
    v11 = idEventArg::idEventArg(this: &v16, data: v10);
    memcpy(Dst: v12, Src: v13, Size: sizeof(v12));
    idEventReceiver::ProcessEvent(
      this: v17,
      result: v7,
      ev: *(const idEventDef **)&v11->type,
      arg1: (const idEventArg *)LODWORD(v11->value.v[1]),
      arg2: (const idEventArg *)LODWORD(v11->value.v[2]),
      arg3: (const idEventArg *)__ROL4__(v14, 32));
    this->curAwareness = newAwareness;
  }
}


// ========================================================================
// ??0aiLatchedState_t@@QAA@XZ
// EA  : 0x82AF8AC8
// RVA : 0x00AF8AC8
// PDB : w:\tech5\tungsten\game\ai\gamestate\aientitystate.cpp
// ========================================================================

aiLatchedState_t *__fastcall aiLatchedState_t::aiLatchedState_t(aiLatchedState_t *this)
{
  this->physical.origin.x = 0.0;
  this->physical.origin.y = 0.0;
  this->physical.origin.z = 0.0;
  this->physical.velocity.x = 0.0;
  this->physical.velocity.y = 0.0;
  this->physical.velocity.z = 0.0;
  this->physical.rotation = quat_identity;
  this->physical.viewfwd.x = 1.0;
  this->physical.viewfwd.y = 0.0;
  this->physical.viewfwd.z = 0.0;
  this->physical.eyePos.x = 0.0;
  this->physical.eyePos.y = 0.0;
  this->physical.eyePos.z = 0.0;
  this->physical.crouchChangeDelta = 0;
  this->physical.entFlags = 0;
  this->physical.stimScale = 0;
  this->physical.bounds.b[0][2] = 0x7FFF;
  this->physical.bounds.b[0][1] = 0x7FFF;
  this->physical.bounds.b[0][0] = 0x7FFF;
  this->physical.bounds.b[1][2] = 0x8000;
  this->physical.bounds.b[1][1] = 0x8000;
  this->physical.bounds.b[1][0] = 0x8000;
  this->faction = nullptr;
  this->spawnId.value = 0x1FFF;
  this->masterId.value = 0x1FFF;
  this->frameNum = -1;
  this->groupHandle.value = -1;
  this->horzFOV = 0;
  *(_WORD *)&this->vertFOV = 6;
  return this;
}


// ========================================================================
// ??0aiLatchedEvent_t@@QAA@XZ
// EA  : 0x82AF8B98
// RVA : 0x00AF8B98
// PDB : w:\tech5\tungsten\game\ai\gamestate\aientitystate.cpp
// ========================================================================

aiLatchedEvent_t *__fastcall aiLatchedEvent_t::aiLatchedEvent_t(aiLatchedEvent_t *this)
{
  this->eventTime = -1;
  this->eventHandle.value = -1;
  this->origin.x = 0.0;
  this->origin.y = 0.0;
  this->origin.z = 0.0;
  this->creatorId.value = 0x1FFF;
  this->relevantId.value = 0x1FFF;
  this->priority = 0;
  this->flags = 0;
  this->eventClass = AIEVENT_NONE;
  return this;
}


// ========================================================================
// ??0idAILogic@@QAA@ABVidSpawnId@@@Z
// EA  : 0x82AF8BD8
// RVA : 0x00AF8BD8
// PDB : w:\tech5\tungsten\game\ai\gamestate\aientitystate.cpp
// ========================================================================

idAILogic *__fastcall idAILogic::idAILogic(idAILogic *this, const idSpawnId *_spawnId)
{
  idAI2 *v3; // r3
  idAI2 *v4; // r3
  idAI2 *v5; // r30

  this->spawnId = (idSpawnId)_spawnId->value;
  this->curEnemyId.value = 0x1FFF;
  this->combatTimeoutInterval = -1.0;
  this->isSearching = false;
  this->searchTimeoutInterval = -1.0;
  this->encounterGroup = nullptr;
  this->faction = nullptr;
  this->isRelaxed = true;
  v3 = (idAI2 *)gameLocal->GetEntityForSpawnId(this: gameLocal, a2: _spawnId->value);
  v4 = idAI2::CastTo(c: v3);
  v5 = v4;
  if ( v4 != nullptr )
  {
    this->isRelaxed = (_cntlzw(idAI2::GetAlertCycle(this: v4) - 1) & 0x20) != 0;
    this->isSearching = (_cntlzw(idAI2::GetAlertCycle(this: v5) - 2) & 0x20) != 0;
    this->slowIdleSpot = v5->aiEditable.perception.slowIdleSpot;
    this->combatTimeoutInterval = v5->aiEditable.perception.combatTimeoutInterval;
    this->searchTimeoutInterval = v5->aiEditable.perception.searchTimeoutInterval;
    this->senseUpdatesOnNonEnemies = v5->aiEditable.perception.senseUpdatesOnNonEnemies;
  }
  return this;
}


// ========================================================================
// ?UpdateSpring@idAISenseState_Sight@@UAAXABUtrackingParms_t@@@Z
// EA  : 0x82AF8CC0
// RVA : 0x00AF8CC0
// PDB : w:\tech5\tungsten\game\ai\gamestate\aientitystate.cpp
// ========================================================================

void __fastcall idAISenseState_Sight::UpdateSpring(idAISenseState_Sight *this, const trackingParms_t *trackingParms)
{
  const aiPhysicalState_t *v4; // r3
  idSpring<idVec3> *p_confirmedOriginSpring; // r31
  idVec3 *p_p1; // r30
  double v7; // fp29
  double v8; // fp28
  double v9; // fp30
  double v10; // fp31
  const aiPhysicalState_t *ConfirmedPhysicalSafe; // r3
  float z; // r8
  double v13; // fp0
  double v15; // fp6
  double v16; // fp5
  double v18; // fp1
  double v19; // fp11
  double v20; // fp10
  double v22; // fp10
  double v23; // fp9
  double v25; // fp5
  double v26; // fp8
  double v27; // fp7
  double v28; // fp1
  idRenderWorld *v29; // r3
  idRenderWorld *v30; // r3
  float x; // [sp+50h] [-60h]
  float y; // [sp+54h] [-5Ch]

  if ( ai_useOriginSprings.valueInteger != 0 )
  {
    p_confirmedOriginSpring = &this->confirmedOriginSpring;
    this->confirmedOriginSpring.m = trackingParms->springMass;
    idSpring<idVec3>::SetConstants(
      this: &this->confirmedOriginSpring,
      _k: trackingParms->springTightness,
      _c: trackingParms->springDampen);
    p_p1 = &this->confirmedOriginSpring.p1;
    v7 = (float)(this->confirmedOriginSpring.p1.y - this->confirmedOriginSpring.p0.y);
    v8 = (float)(this->confirmedOriginSpring.p1.z - this->confirmedOriginSpring.p0.z);
    v9 = (float)(this->confirmedOriginSpring.p1.x - this->confirmedOriginSpring.p0.x);
    v10 = (float)((float)((float)v9 * (float)v9)
                + (float)((float)((float)v8 * (float)v8) + (float)((float)v7 * (float)v7)));
    if ( v10 > (float)(trackingParms->springMaxLength * trackingParms->springMaxLength) )
    {
      ConfirmedPhysicalSafe = aiSenseState_t::GetConfirmedPhysicalSafe(this);
      z = ConfirmedPhysicalSafe->velocity.z;
      y = ConfirmedPhysicalSafe->velocity.y;
      x = ConfirmedPhysicalSafe->velocity.x;
      v13 = (float)((float)(x * x) + (float)((float)(y * y) + (float)(z * z)));
      if ( v13 <= 0.0 )
      {
        _FP8 = (float)((float)((float)((float)v9 * (float)v9)
                             + (float)((float)((float)v8 * (float)v8) + (float)((float)v7 * (float)v7)))
                     - idMath::FLT_SMALLEST_NON_DENORMAL);
        v22 = this->confirmedOriginSpring.p0.y;
        v23 = this->confirmedOriginSpring.p0.z;
        __asm { fsel      f6, f8, f31, f13 }
        v25 = __frsqrte(_FP6);
        v26 = (float)((float)((float)v7
                            * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v25 * (float)((float)v10 * 0.5)) * (float)v25) - 1.5) * (float)v25) * (float)((float)v10 * 0.5)) * (float)((float)-(float)((float)((float)((float)v25 * (float)((float)v10 * 0.5)) * (float)v25) - 1.5) * (float)v25))
                                                                                            - 1.5)
                                                                            * (float)((float)-(float)((float)((float)((float)v25 * (float)((float)v10 * 0.5)) * (float)v25) - 1.5)
                                                                                    * (float)v25))
                                                                    * (float)((float)v10 * 0.5))
                                                            * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v25 * (float)((float)v10 * 0.5)) * (float)v25) - 1.5) * (float)v25) * (float)((float)v10 * 0.5))
                                                                                            * (float)((float)-(float)((float)((float)((float)v25 * (float)((float)v10 * 0.5)) * (float)v25) - 1.5) * (float)v25))
                                                                                    - 1.5)
                                                                    * (float)((float)-(float)((float)((float)((float)v25 * (float)((float)v10 * 0.5)) * (float)v25)
                                                                                            - 1.5)
                                                                            * (float)v25)))
                                                    - 1.5)
                                    * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v25 * (float)((float)v10 * 0.5)) * (float)v25) - 1.5)
                                                                                    * (float)v25)
                                                                            * (float)((float)v10 * 0.5))
                                                                    * (float)((float)-(float)((float)((float)((float)v25 * (float)((float)v10 * 0.5)) * (float)v25)
                                                                                            - 1.5)
                                                                            * (float)v25))
                                                            - 1.5)
                                            * (float)((float)-(float)((float)((float)((float)v25
                                                                                    * (float)((float)v10 * 0.5))
                                                                            * (float)v25)
                                                                    - 1.5)
                                                    * (float)v25))))
                    * trackingParms->springMaxLength);
        v27 = (float)((float)((float)v8
                            * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v25 * (float)((float)v10 * 0.5)) * (float)v25) - 1.5) * (float)v25) * (float)((float)v10 * 0.5)) * (float)((float)-(float)((float)((float)((float)v25 * (float)((float)v10 * 0.5)) * (float)v25) - 1.5) * (float)v25))
                                                                                            - 1.5)
                                                                            * (float)((float)-(float)((float)((float)((float)v25 * (float)((float)v10 * 0.5)) * (float)v25) - 1.5)
                                                                                    * (float)v25))
                                                                    * (float)((float)v10 * 0.5))
                                                            * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v25 * (float)((float)v10 * 0.5)) * (float)v25) - 1.5) * (float)v25) * (float)((float)v10 * 0.5))
                                                                                            * (float)((float)-(float)((float)((float)((float)v25 * (float)((float)v10 * 0.5)) * (float)v25) - 1.5) * (float)v25))
                                                                                    - 1.5)
                                                                    * (float)((float)-(float)((float)((float)((float)v25 * (float)((float)v10 * 0.5)) * (float)v25)
                                                                                            - 1.5)
                                                                            * (float)v25)))
                                                    - 1.5)
                                    * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v25 * (float)((float)v10 * 0.5)) * (float)v25) - 1.5)
                                                                                    * (float)v25)
                                                                            * (float)((float)v10 * 0.5))
                                                                    * (float)((float)-(float)((float)((float)((float)v25 * (float)((float)v10 * 0.5)) * (float)v25)
                                                                                            - 1.5)
                                                                            * (float)v25))
                                                            - 1.5)
                                            * (float)((float)-(float)((float)((float)((float)v25
                                                                                    * (float)((float)v10 * 0.5))
                                                                            * (float)v25)
                                                                    - 1.5)
                                                    * (float)v25))))
                    * trackingParms->springMaxLength);
        p_p1->x = p_confirmedOriginSpring->p0.x
                + (float)(trackingParms->springMaxLength
                        * (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v25 * (float)((float)v10 * 0.5)) * (float)v25) - 1.5) * (float)v25) * (float)((float)v10 * 0.5)) * (float)((float)-(float)((float)((float)((float)v25 * (float)((float)v10 * 0.5)) * (float)v25) - 1.5) * (float)v25))
                                                                                                - 1.5)
                                                                                * (float)((float)-(float)((float)((float)((float)v25 * (float)((float)v10 * 0.5)) * (float)v25) - 1.5)
                                                                                        * (float)v25))
                                                                        * (float)((float)v10 * 0.5))
                                                                * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v25 * (float)((float)v10 * 0.5)) * (float)v25) - 1.5) * (float)v25) * (float)((float)v10 * 0.5))
                                                                                                * (float)((float)-(float)((float)((float)((float)v25 * (float)((float)v10 * 0.5)) * (float)v25) - 1.5) * (float)v25))
                                                                                        - 1.5)
                                                                        * (float)((float)-(float)((float)((float)((float)v25 * (float)((float)v10 * 0.5)) * (float)v25)
                                                                                                - 1.5)
                                                                                * (float)v25)))
                                                        - 1.5)
                                        * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v25 * (float)((float)v10 * 0.5)) * (float)v25) - 1.5)
                                                                                        * (float)v25)
                                                                                * (float)((float)v10 * 0.5))
                                                                        * (float)((float)-(float)((float)((float)((float)v25 * (float)((float)v10 * 0.5)) * (float)v25)
                                                                                                - 1.5)
                                                                                * (float)v25))
                                                                - 1.5)
                                                * (float)((float)-(float)((float)((float)((float)v25
                                                                                        * (float)((float)v10 * 0.5))
                                                                                * (float)v25)
                                                                        - 1.5)
                                                        * (float)v25)))
                                * (float)v9));
        this->confirmedOriginSpring.p1.y = (float)v26 + (float)v22;
        this->confirmedOriginSpring.p1.z = (float)v27 + (float)v23;
      }
      else
      {
        _FP4 = (float)((float)((float)(x * x) + (float)((float)(y * y) + (float)(z * z)))
                     - idMath::FLT_SMALLEST_NON_DENORMAL);
        v15 = this->confirmedOriginSpring.p0.y;
        v16 = this->confirmedOriginSpring.p0.z;
        __asm { fsel      f2, f4, f0, f12 }
        v18 = __frsqrte(_FP2);
        v19 = (float)((float)(y
                            * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v18 * (float)((float)v13 * 0.5)) * (float)v18) - 1.5) * (float)v18) * (float)((float)v13 * 0.5)) * (float)((float)-(float)((float)((float)((float)v18 * (float)((float)v13 * 0.5)) * (float)v18) - 1.5) * (float)v18))
                                                                                            - 1.5)
                                                                            * (float)((float)-(float)((float)((float)((float)v18 * (float)((float)v13 * 0.5)) * (float)v18) - 1.5)
                                                                                    * (float)v18))
                                                                    * (float)((float)v13 * 0.5))
                                                            * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v18 * (float)((float)v13 * 0.5)) * (float)v18) - 1.5) * (float)v18) * (float)((float)v13 * 0.5))
                                                                                            * (float)((float)-(float)((float)((float)((float)v18 * (float)((float)v13 * 0.5)) * (float)v18) - 1.5) * (float)v18))
                                                                                    - 1.5)
                                                                    * (float)((float)-(float)((float)((float)((float)v18 * (float)((float)v13 * 0.5)) * (float)v18)
                                                                                            - 1.5)
                                                                            * (float)v18)))
                                                    - 1.5)
                                    * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v18 * (float)((float)v13 * 0.5)) * (float)v18) - 1.5)
                                                                                    * (float)v18)
                                                                            * (float)((float)v13 * 0.5))
                                                                    * (float)((float)-(float)((float)((float)((float)v18 * (float)((float)v13 * 0.5)) * (float)v18)
                                                                                            - 1.5)
                                                                            * (float)v18))
                                                            - 1.5)
                                            * (float)((float)-(float)((float)((float)((float)v18
                                                                                    * (float)((float)v13 * 0.5))
                                                                            * (float)v18)
                                                                    - 1.5)
                                                    * (float)v18))))
                    * trackingParms->springMaxLength);
        v20 = (float)((float)(z
                            * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v18 * (float)((float)v13 * 0.5)) * (float)v18) - 1.5) * (float)v18) * (float)((float)v13 * 0.5)) * (float)((float)-(float)((float)((float)((float)v18 * (float)((float)v13 * 0.5)) * (float)v18) - 1.5) * (float)v18))
                                                                                            - 1.5)
                                                                            * (float)((float)-(float)((float)((float)((float)v18 * (float)((float)v13 * 0.5)) * (float)v18) - 1.5)
                                                                                    * (float)v18))
                                                                    * (float)((float)v13 * 0.5))
                                                            * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v18 * (float)((float)v13 * 0.5)) * (float)v18) - 1.5) * (float)v18) * (float)((float)v13 * 0.5))
                                                                                            * (float)((float)-(float)((float)((float)((float)v18 * (float)((float)v13 * 0.5)) * (float)v18) - 1.5) * (float)v18))
                                                                                    - 1.5)
                                                                    * (float)((float)-(float)((float)((float)((float)v18 * (float)((float)v13 * 0.5)) * (float)v18)
                                                                                            - 1.5)
                                                                            * (float)v18)))
                                                    - 1.5)
                                    * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v18 * (float)((float)v13 * 0.5)) * (float)v18) - 1.5)
                                                                                    * (float)v18)
                                                                            * (float)((float)v13 * 0.5))
                                                                    * (float)((float)-(float)((float)((float)((float)v18 * (float)((float)v13 * 0.5)) * (float)v18)
                                                                                            - 1.5)
                                                                            * (float)v18))
                                                            - 1.5)
                                            * (float)((float)-(float)((float)((float)((float)v18
                                                                                    * (float)((float)v13 * 0.5))
                                                                            * (float)v18)
                                                                    - 1.5)
                                                    * (float)v18))))
                    * trackingParms->springMaxLength);
        p_p1->x = p_confirmedOriginSpring->p0.x
                - (float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v18 * (float)((float)v13 * 0.5)) * (float)v18) - 1.5) * (float)v18) * (float)((float)v13 * 0.5)) * (float)((float)-(float)((float)((float)((float)v18 * (float)((float)v13 * 0.5)) * (float)v18) - 1.5) * (float)v18))
                                                                                                - 1.5)
                                                                                * (float)((float)-(float)((float)((float)((float)v18 * (float)((float)v13 * 0.5)) * (float)v18) - 1.5)
                                                                                        * (float)v18))
                                                                        * (float)((float)v13 * 0.5))
                                                                * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v18 * (float)((float)v13 * 0.5)) * (float)v18) - 1.5) * (float)v18) * (float)((float)v13 * 0.5))
                                                                                                * (float)((float)-(float)((float)((float)((float)v18 * (float)((float)v13 * 0.5)) * (float)v18) - 1.5) * (float)v18))
                                                                                        - 1.5)
                                                                        * (float)((float)-(float)((float)((float)((float)v18 * (float)((float)v13 * 0.5)) * (float)v18)
                                                                                                - 1.5)
                                                                                * (float)v18)))
                                                        - 1.5)
                                        * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v18 * (float)((float)v13 * 0.5)) * (float)v18) - 1.5)
                                                                                        * (float)v18)
                                                                                * (float)((float)v13 * 0.5))
                                                                        * (float)((float)-(float)((float)((float)((float)v18 * (float)((float)v13 * 0.5)) * (float)v18)
                                                                                                - 1.5)
                                                                                * (float)v18))
                                                                - 1.5)
                                                * (float)((float)-(float)((float)((float)((float)v18
                                                                                        * (float)((float)v13 * 0.5))
                                                                                * (float)v18)
                                                                        - 1.5)
                                                        * (float)v18)))
                                * x)
                        * trackingParms->springMaxLength);
        this->confirmedOriginSpring.p1.y = (float)v15 - (float)v19;
        this->confirmedOriginSpring.p1.z = (float)v16 - (float)v20;
      }
    }
    this->confirmedOriginSpring.maxSpeed = trackingParms->springMaxSpeed;
    v28 = ((double (__fastcall *)(idGameLocal *, int))gameLocal->GetRealSecPerFrame)(a1: gameLocal, a2: 1);
    idSpring<idVec3>::Update(this: &this->confirmedOriginSpring, dt: v28);
    if ( ai_debugLevel.valueInteger > 0 && ai_debugOriginSprings.valueInteger != 0 )
    {
      v29 = gameLocal->GetRenderWorld(this: gameLocal);
      v29->DebugPoint(
        this: v29,
        a2: (const idVec4 *)&idColor::colorGreen,
        a3: &this->confirmedOriginSpring.p0,
        a4: 0,
        a5: true);
      v30 = gameLocal->GetRenderWorld(this: gameLocal);
      v30->DebugPoint(
        this: v30,
        a2: (const idVec4 *)&idColor::colorRed,
        a3: &this->confirmedOriginSpring.p1,
        a4: 0,
        a5: true);
    }
  }
  else
  {
    v4 = aiSenseState_t::GetConfirmedPhysicalSafe(this);
    this->confirmedOriginSpring.p0 = v4->origin;
    this->confirmedOriginSpring.p1 = v4->origin;
    this->confirmedOriginSpring.vel.z = 0.0;
    this->confirmedOriginSpring.vel.y = 0.0;
    this->confirmedOriginSpring.vel.x = 0.0;
  }
}


// ========================================================================
// ?GetAimPoint@idAIEntityState@@QBAXW4aiSense_t@@W4aimPoint_t@@AAVidVec3@@@Z
// EA  : 0x82AF8FE0
// RVA : 0x00AF8FE0
// PDB : w:\tech5\tungsten\game\ai\gamestate\aientitystate.cpp
// ========================================================================

void __fastcall idAIEntityState::GetAimPoint(
        idAIEntityState *this,
        const aiSense_t sense,
        aimPoint_t aimPoint,
        idVec3 *point)
{
  aimPoint_t v5; // r28
  aiSenseState_t *v6; // r29
  const aiPhysicalState_t *ConfirmedPhysicalSafe; // r31
  float *v8; // r3
  double x; // fp31
  double y; // fp30
  double z; // fp29
  double v12; // fp7
  double v13; // fp6
  double v14; // fp28
  double v15; // fp27
  double v16; // fp26
  float *v17; // r3
  double v18; // fp6
  double v19; // fp4
  double v20; // fp2
  double v21; // fp1
  float *v22; // r3
  double v23; // fp4
  double v24; // fp3
  const aiPhysicalState_t *v25; // r3
  idBounds *v26; // r3
  double v27; // fp12
  const aiPhysicalState_t *v28; // r3
  idBounds *v29; // r3
  double v30; // fp31
  double v31; // fp30
  const aiPhysicalState_t *v32; // r3
  double v33; // fp31
  double v34; // fp30
  float v35; // r10
  float v36; // r9
  double v37; // fp4
  double v38; // fp12
  double v39; // fp11
  idVec3 v40[2]; // [sp+50h] [-D0h] BYREF
  idBoundsShort v41[2]; // [sp+70h] [-B0h] BYREF
  idBoundsShort v42[2]; // [sp+90h] [-90h] BYREF
  idBoundsShort v43[6]; // [sp+B0h] [-70h] BYREF

  v5 = aimPoint;
  if ( aimPoint == AIMPOINT_BEST )
    v5 = ((_cntlzw(this->lastVisible - 3) & 0x20) == 0) + 1;
  v6 = this->senses.ptr[(unsigned __int8)sense];
  ConfirmedPhysicalSafe = aiSenseState_t::GetConfirmedPhysicalSafe(this: v6);
  if ( v6->HasSpring(this: v6) && v6->lastConfirmedStimTime >= 0 )
  {
    v8 = (float *)v6->GetSpring(this: v6);
    x = v8[3];
    y = v8[4];
    z = v8[5];
  }
  else
  {
    x = ConfirmedPhysicalSafe->origin.x;
    y = ConfirmedPhysicalSafe->origin.y;
    z = ConfirmedPhysicalSafe->origin.z;
  }
  if ( (unsigned int)(v5 - 1) <= 7 )
  {
    switch ( v5 )
    {
      case AIMPOINT_TORSO:
        v14 = (float)(ConfirmedPhysicalSafe->eyePos.x - ConfirmedPhysicalSafe->origin.x);
        v15 = (float)(ConfirmedPhysicalSafe->eyePos.y - ConfirmedPhysicalSafe->origin.y);
        v16 = (float)(ConfirmedPhysicalSafe->eyePos.z - ConfirmedPhysicalSafe->origin.z);
        v17 = (float *)idBoundsShort::ToBounds(
                         this: (idBoundsShort *)v40,
                         result: (idBounds *)&ConfirmedPhysicalSafe->bounds);
        v18 = (float)((float)((float)(v17[4] + v17[1]) * (float)0.5) + (float)y);
        v19 = (float)((float)((float)(v17[5] + v17[2]) * (float)0.5) + (float)z);
        v20 = (float)((float)((float)v15 - (float)((float)(v17[4] + v17[1]) * (float)0.5)) * (float)0.5);
        v21 = (float)((float)((float)v16 - (float)((float)(v17[5] + v17[2]) * (float)0.5)) * (float)0.5);
        point->x = (float)((float)((float)(v17[3] + *v17) * (float)0.5) + (float)x)
                 + (float)((float)((float)v14 - (float)((float)(v17[3] + *v17) * (float)0.5)) * (float)0.5);
        point->y = (float)v18 + (float)v20;
        point->z = (float)v19 + (float)v21;
        break;
      case AIMPOINT_CENTER:
        v22 = (float *)idBoundsShort::ToBounds(this: v41, result: (idBounds *)&ConfirmedPhysicalSafe->bounds);
        v23 = (float)((float)(v22[4] + v22[1]) * (float)0.5);
        v24 = (float)((float)(v22[5] + v22[2]) * (float)0.5);
        point->x = (float)((float)(v22[3] + *v22) * (float)0.5) + (float)x;
        point->y = (float)v23 + (float)y;
        point->z = (float)v24 + (float)z;
        break;
      case AIMPOINT_LEGS:
        v25 = aiSenseState_t::GetConfirmedPhysicalSafe(this: v6);
        v26 = idBoundsShort::ToBounds(this: v42, result: (idBounds *)&v25->bounds);
        v27 = (float)(v26->b[1].z - v26->b[0].z);
        point->x = x;
        point->y = y;
        point->z = (float)((float)v27 * (float)0.25) + (float)z;
        break;
      case AIMPOINT_FEET:
        v28 = aiSenseState_t::GetConfirmedPhysicalSafe(this: v6);
        v29 = idBoundsShort::ToBounds(this: v43, result: (idBounds *)&v28->bounds);
        v30 = v29->b[1].z;
        v31 = v29->b[0].z;
        v32 = aiSenseState_t::GetConfirmedPhysicalSafe(this: v6);
        point->x = v32->origin.x;
        point->y = v32->origin.y;
        point->z = (float)((float)((float)v30 - (float)v31) * (float)0.1) + v32->origin.z;
        break;
      case AIMPOINT_BEST:
      case AIMPOINT_EYELEVEL:
LABEL_23:
        break;
      default:
        v12 = (float)(ConfirmedPhysicalSafe->eyePos.y - ConfirmedPhysicalSafe->origin.y);
        v13 = (float)(ConfirmedPhysicalSafe->eyePos.z - ConfirmedPhysicalSafe->origin.z);
        if ( v5 == AIMPOINT_HEAD )
        {
          point->x = (float)(ConfirmedPhysicalSafe->eyePos.x - ConfirmedPhysicalSafe->origin.x) + (float)x;
          point->y = (float)v12 + (float)y;
          point->z = (float)v13 + (float)z;
        }
        else
        {
          v33 = (float)((float)(ConfirmedPhysicalSafe->eyePos.x - ConfirmedPhysicalSafe->origin.x) + (float)x);
          point->x = v33;
          v34 = (float)((float)v12 + (float)y);
          point->y = v34;
          point->z = (float)v13 + (float)z;
          v35 = ConfirmedPhysicalSafe->velocity.x;
          v36 = ConfirmedPhysicalSafe->velocity.y;
          v40[0].z = ConfirmedPhysicalSafe->velocity.z;
          v40[0].y = v36;
          v40[0].x = v35;
          idVec3::NormalizeFast(this: v40);
          v37 = point->z;
          v38 = (float)(v40[0].y * (float)64.0);
          v39 = (float)(v40[0].z * (float)64.0);
          point->x = (float)(v40[0].x * (float)64.0) + (float)v33;
          point->y = (float)v38 + (float)v34;
          point->z = (float)v39 + (float)v37;
        }
        goto LABEL_23;
    }
  }
}


// ========================================================================
// ?AICanSee_Resolve@idAIEntityState@@SA?AW4visibleType_t@@ABVidAILogic@@AAUaiDefVisInfo_t@1@PBUaiLatchedState_t@@@Z
// EA  : 0x82AF9388
// RVA : 0x00AF9388
// PDB : w:\tech5\tungsten\game\ai\gamestate\aientitystate.cpp
// ========================================================================

int __fastcall idAIEntityState::AICanSee_Resolve(
        const idAILogic *owner,
        idAIEntityState::aiDefVisInfo_t *defVisInfo,
        const aiLatchedState_t *tols)
{
  unsigned __int64 v6; // r27
  const aiLatchedState_t *State; // r24
  idClientGame *v8; // r28
  unsigned __int64 index; // r11
  idClientGame *v11; // r29
  idClipQuery *p_boundsQuery; // r31
  idClipQuery v13; // r11
  trace_t v14; // [sp+50h] [-150h] BYREF
  trace_t v15; // [sp+D0h] [-D0h] BYREF

  HIDWORD(v6) = &ai_useTurnTransitions.valueString.baseBuffer[12];
  State = idAIGameState::GetState(this: &gameLocal->aiGameState, spawnId: &owner->spawnId);
  v14.fraction = 1.0;
  v8 = clientGame;
  if ( (unsigned __int8)idClip::QueryIsValid(this: &clientGame->clip, clipQuery: &defVisInfo->eyeQuery) == 0 )
    return 5;
  LODWORD(v6) = 0;
  index = defVisInfo->eyeQuery.index;
  defVisInfo->eyeQuery.index = v6;
  idCollisionModelManager::GetContentsResult(
    this: collisionModelManager,
    result: &v14,
    query: &v8->clip.collisionQueries[index & 0xFFF].query,
    peek: false);
  if ( owner->pausePerception )
    return 5;
  if ( (unsigned __int8)TraceVisible(dls: tols, tr: &v14) == 0 )
  {
    if ( ai_showVisTrace.valueInteger > 0 && ai_debugLevel.valueInteger > 0 )
      clientGame->renderWorld->DebugLine(
        this: clientGame->renderWorld,
        a2: (const idVec4 *)&idColor::colorYellow,
        a3: &State->physical.eyePos,
        a4: &v14.endpos,
        a5: 1000,
        a6: true);
    if ( defVisInfo->fovWeight > 0.0 )
      return 2;
    else
      return 0;
  }
  if ( defVisInfo->fovWeight <= 0.0 )
    return 1;
  v11 = clientGame;
  p_boundsQuery = &defVisInfo->boundsQuery;
  if ( (unsigned __int8)idClip::QueryIsValid(this: &clientGame->clip, clipQuery: p_boundsQuery) != 0 )
  {
    v13.index = p_boundsQuery->index;
    p_boundsQuery->index = v6;
    idCollisionModelManager::GetContentsResult(
      this: collisionModelManager,
      result: &v15,
      query: &v11->clip.collisionQueries[v13.index & 0xFFF].query,
      peek: false);
    if ( (unsigned __int8)TraceVisible(dls: tols, tr: &v15) == 0 )
    {
      if ( ai_showVisTrace.valueInteger > 0 && ai_debugLevel.valueInteger > 0 )
      {
        clientGame->renderWorld->DebugLine(
          this: clientGame->renderWorld,
          a2: (const idVec4 *)&idColor::colorRed,
          a3: &State->physical.eyePos,
          a4: &v14.endpos,
          a5: 1000,
          a6: true);
        clientGame->renderWorld->DebugLine(
          this: clientGame->renderWorld,
          a2: (const idVec4 *)&idColor::colorYellow,
          a3: &State->physical.eyePos,
          a4: &v15.endpos,
          a5: 1000,
          a6: true);
      }
      return 3;
    }
    v11 = clientGame;
  }
  if ( ai_showVisTrace.valueInteger > 0 && ai_debugLevel.valueInteger > 0 )
    v11->renderWorld->DebugLine(
      this: v11->renderWorld,
      a2: (const idVec4 *)&idColor::colorRed,
      a3: &State->physical.eyePos,
      a4: &v14.endpos,
      a5: 1000,
      a6: true);
  return 4;
}


// ========================================================================
// ?IsVisible@idAIEntityState@@QBA_NXZ
// EA  : 0x82AF9658
// RVA : 0x00AF9658
// PDB : w:\tech5\tungsten\game\ai\gamestate\aientitystate.cpp
// ========================================================================

int __fastcall idAIEntityState::IsVisible(idAIEntityState *this)
{
  int GameMs; // r3
  unsigned __int8 v3; // r11

  if ( this->lastVisible <= 2u )
    return 0;
  if ( this->senses.ptr[1]->lastUnconfirmedStimTime < 0 )
    return 0;
  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  v3 = 1;
  if ( GameMs - this->senses.ptr[1]->lastConfirmedStimTime >= 1000 )
    return 0;
  return v3;
}


// ========================================================================
// ?TestSurprise@idAIEntityState@@AAAXPBVidAIGameState@@ABVidAILogic@@PBUaiLatchedState_t@@@Z
// EA  : 0x82AF96D8
// RVA : 0x00AF96D8
// PDB : w:\tech5\tungsten\game\ai\gamestate\aientitystate.cpp
// ========================================================================

void __fastcall idAIEntityState::TestSurprise(
        idAIEntityState *this,
        const idAIGameState *gameState,
        const idAILogic *owner,
        const aiLatchedState_t *ls)
{
  idEntity *v7; // r31
  aiSenseState_t *v8; // r3
  const aiPhysicalState_t *ConfirmedPhysicalSafe; // r3
  double x; // fp31
  double v11; // fp30
  double v12; // fp25
  idPhysics *Physics; // r3
  float *v14; // r3
  double v15; // fp12
  double v16; // fp10
  double v17; // fp31
  idPhysics *v18; // r3
  float *v19; // r3
  double v20; // fp6
  double v21; // fp4
  float y; // [sp+54h] [-BCh]
  float z; // [sp+58h] [-B8h]
  float v24; // [sp+60h] [-B0h]
  float v25; // [sp+64h] [-ACh]
  float v26; // [sp+68h] [-A8h]
  idVec3 v27; // [sp+78h] [-98h] BYREF
  idVec3 v28; // [sp+88h] [-88h] BYREF

  v7 = gameLocal->GetEntityForSpawnId(this: gameLocal, a2: owner->spawnId.value);
  if ( v7 != nullptr )
  {
    v8 = this->senses.ptr[this->lastSense];
    if ( gameState->gameTime - v8->lastConfirmedStimTime > 3000 )
    {
      ConfirmedPhysicalSafe = aiSenseState_t::GetConfirmedPhysicalSafe(this: v8);
      z = ls->physical.origin.z;
      x = ls->physical.origin.x;
      v26 = ConfirmedPhysicalSafe->origin.z;
      v24 = ConfirmedPhysicalSafe->origin.x;
      v11 = ConfirmedPhysicalSafe->origin.x;
      y = ls->physical.origin.y;
      v25 = ConfirmedPhysicalSafe->origin.y;
      v12 = (float)(ls->physical.origin.x - ConfirmedPhysicalSafe->origin.x);
      Physics = idEntity::GetPhysics(this: v7);
      v14 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
      v15 = (float)(z - v14[2]);
      v16 = (float)(y - v14[1]);
      v27.x = (float)x - *v14;
      v27.z = v15;
      v27.y = v16;
      v17 = idVec3::ToYaw(this: &v27);
      v18 = idEntity::GetPhysics(this: v7);
      v19 = (float *)v18->GetOrigin(this: v18, a2: 0);
      v20 = (float)(v26 - v19[2]);
      v21 = (float)(v25 - v19[1]);
      v28.x = (float)v11 - *v19;
      v28.z = v20;
      v28.y = v21;
      if ( (float)((float)((float)__fabs((float)((float)v17 - idVec3::ToYaw(this: &v28))) * (float)0.0055555557)
                 + (float)((float)__fsqrts((float)((float)((float)v12 * (float)v12)
                                                 + (float)((float)((float)(z - v26) * (float)(z - v26))
                                                         + (float)((float)(y - v25) * (float)(y - v25)))))
                         * (float)0.001953125)) > 1.0 )
      {
        HIBYTE(v24) = 105;
        idEventReceiver::PostEventMS(
          this: v7,
          ev: &EV_Surprised,
          time: SLODWORD(v24),
          arg1: (const idEventArg *)LODWORD(v26));
      }
    }
  }
}


// ========================================================================
// ?SetSenseState@idAIEntityState@@QAAXPBVidAIGameState@@ABVidAILogic@@W4aiSense_t@@ABUaiPhysicalState_t@@W4aiStimulus_t@@ABVidSpawnId@@@Z
// EA  : 0x82AF98D0
// RVA : 0x00AF98D0
// PDB : w:\tech5\tungsten\game\ai\gamestate\aientitystate.cpp
// ========================================================================

void __fastcall idAIEntityState::SetSenseState(
        idAIEntityState *this,
        idAIGameState *gameState,
        const idAILogic *aiOwner,
        const aiSense_t sense,
        const aiPhysicalState_t *physical,
        const aiStimulus_t stimType,
        const idSpawnId *sourceId)
{
  unsigned __int8 v7; // r24
  unsigned __int8 v12; // r23
  aiSenseState_t *v13; // r31
  int *p_gameTime; // r22
  unsigned __int8 senseFlags; // r11
  const aiLatchedState_t *State; // r3

  v7 = sense;
  v12 = stimType;
  v13 = this->senses.ptr[(unsigned __int8)sense];
  p_gameTime = &gameState->gameTime;
  aiPhysicalState_t::operator=(this: &v13->unConfirmedPhysical, __that: physical);
  v13->lastUnconfirmedStimTime = gameState->gameTime;
  aiPhysicalState_t::operator=(this: &v13->confirmedPhysical, __that: physical);
  v13->lastConfirmedStimTime = *p_gameTime;
  v13->aiOrigin = idAIGameState::GetState(this: &gameLocal->aiGameState, spawnId: &aiOwner->spawnId)->physical.origin;
  if ( sourceId->value == aiOwner->spawnId.value )
  {
    senseFlags = v13->senseFlags;
    v13->stimulusType = v12;
    v13->senseFlags = senseFlags | 1;
    this->lastSense = v7;
  }
  else
  {
    State = idAIGameState::GetState(this: gameState, spawnId: sourceId);
    if ( State != nullptr
      && State->spawnId.value == sourceId->value
      && State->groupHandle.value == idAIGameState::GetState(this: &gameLocal->aiGameState, spawnId: &aiOwner->spawnId)->groupHandle.value )
    {
      v13->senseFlags |= 2u;
    }
    v13->stimulusType = v12;
    this->lastSense = v7;
  }
}


// ========================================================================
// ??0idAILogic@@QAA@PBVidAI2@@@Z
// EA  : 0x82AF99F8
// RVA : 0x00AF99F8
// PDB : w:\tech5\tungsten\game\ai\gamestate\aientitystate.cpp
// ========================================================================

idAILogic *__fastcall idAILogic::idAILogic(idAILogic *this, idAI2 *ai)
{
  idSpawnId *v4; // r4
  int value; // r8
  idEntity *v6; // r3
  idEntity *v7; // r3
  const idEntity *v8; // r5
  _BYTE v10[64]; // [sp+50h] [-40h] BYREF

  this->spawnId.value = 0x1FFF;
  this->curEnemyId.value = 0x1FFF;
  this->combatTimeoutInterval = -1.0;
  this->searchTimeoutInterval = -1.0;
  this->isRelaxed = true;
  this->isSearching = false;
  this->slowIdleSpot = false;
  this->pausePerception = false;
  this->encounterGroup = nullptr;
  this->faction = nullptr;
  if ( ai != nullptr )
  {
    this->spawnId = (idSpawnId)idGameLocal::GetSpawnId(
                                 this: (idGameLocal *)v10,
                                 result: (idSpawnId *)gameLocal,
                                 ent: ai)->value;
    v4 = (idSpawnId *)gameLocal;
    value = ai->aiVolatile.memory.currentEnemy.spawnId.value;
    if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
      && (v6 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
    {
      v7 = idEntity::CastTo(c: v6);
      v4 = (idSpawnId *)gameLocal;
      v8 = v7;
    }
    else
    {
      v8 = nullptr;
    }
    this->curEnemyId = (idSpawnId)idGameLocal::GetSpawnId(this: (idGameLocal *)v10, result: v4, ent: v8)->value;
    this->isRelaxed = (_cntlzw(idAI2::GetAlertCycle(this: ai) - 1) & 0x20) != 0;
    this->isSearching = (_cntlzw(idAI2::GetAlertCycle(this: ai) - 2) & 0x20) != 0;
    this->slowIdleSpot = ai->aiEditable.perception.slowIdleSpot;
    this->combatTimeoutInterval = ai->aiEditable.perception.combatTimeoutInterval;
    this->searchTimeoutInterval = ai->aiEditable.perception.searchTimeoutInterval;
    if ( idAI2::PerceptionFlagIsSet(this: ai, flags: 1) )
      this->pausePerception = true;
    this->encounterGroup = idAI2::GetEncounterGroup(this: ai);
    this->faction = ai->GetFaction(this: ai);
    this->senseUpdatesOnNonEnemies = ai->aiEditable.perception.senseUpdatesOnNonEnemies;
  }
  return this;
}


// ========================================================================
// ??0idAIEntityState@@QAA@XZ
// EA  : 0x82AF9B70
// RVA : 0x00AF9B70
// PDB : w:\tech5\tungsten\game\ai\gamestate\aientitystate.cpp
// ========================================================================

idAIEntityState *__fastcall idAIEntityState::idAIEntityState(idAIEntityState *this)
{
  idAISenseState_Hearing *p_hearingSense; // r30
  idAISenseState_Sight *p_sightSense; // r29
  char v4; // r4

  p_hearingSense = &this->hearingSense;
  this->__vftable = (idAIEntityState_vtbl *)&idAIEntityState::`vftable';
  p_sightSense = &this->sightSense;
  aiSenseState_t::aiSenseState_t(this: &this->hearingSense);
  this->hearingSense.__vftable = (idAISenseState_Hearing_vtbl *)&idAISenseState_Hearing::`vftable';
  idAISenseState_Sight::idAISenseState_Sight(this: &this->sightSense);
  this->spawnId.value = 0x1FFF;
  v4 = *((_BYTE *)this + 541);
  this->highestAwareness = 0;
  this->lastSense = 2;
  this->lastVisible = 2;
  this->lastVisualStimulus = 0.0;
  *((_BYTE *)this + 541) = v4 & 0x3F;
  this->initTime = -1;
  this->visChangeTime = -1;
  this->curAwareness = 0;
  this->entityType = 6;
  this->aasPosition.valid = false;
  this->aasPosition.areaNum = 0;
  this->aasPosition.origin.x = 0.0;
  this->aasPosition.origin.y = 0.0;
  this->aasPosition.origin.z = 0.0;
  this->aasPosition.validOrigin.x = 0.0;
  this->aasPosition.validOrigin.y = 0.0;
  this->aasPosition.validOrigin.z = 0.0;
  this->aasPosition.aas = nullptr;
  this->senses.ptr[0] = p_hearingSense;
  this->senses.ptr[1] = p_sightSense;
  return this;
}


// ========================================================================
// ?IncreaseAwareness@idAIEntityState@@AAAXABVidAILogic@@W4aiAwareness_t@@@Z
// EA  : 0x82AF9C98
// RVA : 0x00AF9C98
// PDB : w:\tech5\tungsten\game\ai\gamestate\aientitystate.cpp
// ========================================================================

void __fastcall idAIEntityState::IncreaseAwareness(idAIEntityState *this, const idAILogic *owner, int newAwareness)
{
  idAI2 *v6; // r27
  idPlayer *v7; // r28
  idAI2 *v8; // r3
  idAI2 *v9; // r24
  char v10; // r10
  float v11; // r9
  idEventArg *v12; // r26
  float v13; // r10
  idEventArg *v14; // r26
  idEncounterGroup *EncounterGroup; // r3
  idGameTimeManager *p_gameTimeManager; // r3
  bool v17; // zf
  float v18; // r10
  idEventArg *v19; // r23
  idPhysics *Physics; // r3
  float *v21; // r26
  const aiPhysicalState_t *ConfirmedPhysicalSafe; // r3
  double v23; // fp10
  double v24; // fp6
  idPhysics *v25; // r3
  float *v26; // r26
  const aiPhysicalState_t *v27; // r3
  double v28; // fp10
  double v29; // fp6
  float v30; // r10
  idEventArg *v31; // r23
  idPhysics *v32; // r26
  idPhysics *v33; // r23
  float *v34; // r26
  float *v35; // r3
  double v36; // fp0
  double v37; // fp6
  float *presentable; // r11
  const idEventDef *v39; // r5
  idPlayer *v40; // r3
  idProp_WeaponStatic *Control; // r3
  int v42; // r9
  idGameTimeManager *v43; // r3
  idPhysics *v44; // r3
  int v45; // r3
  aiSenseState_t *v46; // r9
  float *v47; // r31
  const aiPhysicalState_t *v48; // r3
  double v49; // fp10
  double v50; // fp8
  _BYTE v51[20]; // [sp+70h] [-F0h] BYREF
  idVec3 v52; // [sp+90h] [-D0h] BYREF
  idVec3 v53[2]; // [sp+B0h] [-B0h] BYREF
  idEventArg v54; // [sp+D0h] [-90h] BYREF
  idEventArg v55; // [sp+F0h] [-70h] BYREF

  v6 = (idAI2 *)gameLocal->GetEntityForSpawnId(this: gameLocal, a2: owner->spawnId.value);
  v7 = (idPlayer *)gameLocal->GetEntityForSpawnId(this: gameLocal, a2: this->spawnId.value);
  v8 = idAI2::CastTo(c: v6);
  v9 = v8;
  if ( v8 != nullptr && v8->IsDead(this: v8) )
    return;
  if ( newAwareness > this->highestAwareness )
  {
    v10 = *((_BYTE *)this + 541);
    LODWORD(v11) = this->curAwareness;
    LODWORD(v53[0].y) = newAwareness;
    HIBYTE(v53[0].x) = 105;
    *((_BYTE *)this + 541) = v10 | 0x40;
    HIBYTE(v52.x) = 105;
    v52.y = v11;
    v12 = idEventArg::idEventArg(this: &v54, data: v7);
    memcpy(Dst: v51, Src: v53, Size: sizeof(v51));
    idEventReceiver::ProcessEvent(
      this: (idEventReceiver *)&v55,
      result: (idEventArg *)v6,
      ev: *(const idEventDef **)&v12->type,
      arg1: (const idEventArg *)LODWORD(v12->value.v[1]),
      arg2: (const idEventArg *)LODWORD(v12->value.v[2]),
      arg3: (const idEventArg *)__ROL4__(LODWORD(v52.x), 32));
    this->highestAwareness = newAwareness;
    this->curAwareness = newAwareness;
    return;
  }
  LODWORD(v13) = this->curAwareness;
  if ( newAwareness > SLODWORD(v13) )
  {
    LODWORD(v53[0].y) = newAwareness;
    v52.y = v13;
    HIBYTE(v53[0].x) = 105;
    HIBYTE(v52.x) = 105;
    v14 = idEventArg::idEventArg(this: &v55, data: v7);
    memcpy(Dst: v51, Src: v53, Size: sizeof(v51));
    idEventReceiver::ProcessEvent(
      this: (idEventReceiver *)&v54,
      result: (idEventArg *)v6,
      ev: *(const idEventDef **)&v14->type,
      arg1: (const idEventArg *)LODWORD(v14->value.v[1]),
      arg2: (const idEventArg *)LODWORD(v14->value.v[2]),
      arg3: (const idEventArg *)__ROL4__(LODWORD(v52.x), 32));
    this->curAwareness = newAwareness;
    return;
  }
  if ( newAwareness != LODWORD(v13)
    || newAwareness != 3
    || v9 == nullptr
    || idAI2::GetEncounterGroup(this: v9) == nullptr
    || v7 != idAIMemory::GetEnemy(this: &v9->aiVolatile.memory) )
  {
    return;
  }
  EncounterGroup = idAI2::GetEncounterGroup(this: v9);
  v17 = idEncounterGroup::LastLivingMemberSeenEnemytime(this: EncounterGroup) != -1;
  p_gameTimeManager = &clientGame->gameTimeManager;
  if ( !v17 )
  {
    if ( idGameTimeManager::GetGameMs(this: p_gameTimeManager, type: GAMETIME_SCALED)
       - this->senses.ptr[1]->lastConfirmedStimTime < 1000
      || idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED)
       - this->senses.ptr[0]->lastConfirmedStimTime < 1000
      && (Physics = idEntity::GetPhysics(this: v9),
          v21 = (float *)Physics->GetOrigin(this: Physics, a2: 0),
          ConfirmedPhysicalSafe = aiSenseState_t::GetConfirmedPhysicalSafe(this: this->senses.ptr[0]),
          v23 = (float)(ConfirmedPhysicalSafe->origin.y - v21[1]),
          (float)((float)((float)(v24 = (float)(ConfirmedPhysicalSafe->origin.z - v21[2])) * (float)v24)
                + (float)((float)((float)(ConfirmedPhysicalSafe->origin.x - *v21)
                                * (float)(ConfirmedPhysicalSafe->origin.x - *v21))
                        + (float)((float)v23 * (float)v23))) < 262144.0) )
    {
      LODWORD(v18) = this->curAwareness;
      HIBYTE(v53[0].x) = 105;
      LODWORD(v53[0].y) = 3;
      HIBYTE(v52.x) = 105;
      v52.y = v18;
      v19 = idEventArg::idEventArg(this: &v55, data: v7);
      memcpy(Dst: v51, Src: v53, Size: sizeof(v51));
      idEventReceiver::ProcessEvent(
        this: (idEventReceiver *)&v54,
        result: (idEventArg *)v6,
        ev: *(const idEventDef **)&v19->type,
        arg1: (const idEventArg *)LODWORD(v19->value.v[1]),
        arg2: (const idEventArg *)LODWORD(v19->value.v[2]),
        arg3: (const idEventArg *)__ROL4__(LODWORD(v52.x), 32));
      v9->aiVolatile.memory.lastActuallySeenEnemyTime = idGameTimeManager::GetGameMs(
                                                          this: &clientGame->gameTimeManager,
                                                          type: GAMETIME_SCALED);
    }
    goto LABEL_34;
  }
  if ( idGameTimeManager::GetGameMs(this: p_gameTimeManager, type: GAMETIME_SCALED)
     - this->senses.ptr[this->lastSense]->lastConfirmedStimTime > 5000 )
  {
    if ( v7 != nullptr )
    {
      v25 = idEntity::GetPhysics(this: v7);
      v26 = (float *)v25->GetOrigin(this: v25, a2: 0);
      v27 = aiSenseState_t::GetConfirmedPhysicalSafe(this: this->senses.ptr[this->lastSense]);
      v28 = (float)(v27->origin.z - v26[2]);
      v29 = (float)(v27->origin.y - v26[1]);
      if ( (float)((float)((float)v29 * (float)v29)
                 + (float)((float)((float)(v27->origin.x - *v26) * (float)(v27->origin.x - *v26))
                         + (float)((float)v28 * (float)v28))) > 65536.0 )
      {
        LODWORD(v30) = this->curAwareness;
        HIBYTE(v53[0].x) = 105;
        LODWORD(v53[0].y) = 3;
        HIBYTE(v52.x) = 105;
        v52.y = v30;
        v31 = idEventArg::idEventArg(this: &v55, data: v7);
        memcpy(Dst: v51, Src: v53, Size: sizeof(v51));
        idEventReceiver::ProcessEvent(
          this: (idEventReceiver *)&v54,
          result: (idEventArg *)v6,
          ev: *(const idEventDef **)&v31->type,
          arg1: (const idEventArg *)LODWORD(v31->value.v[1]),
          arg2: (const idEventArg *)LODWORD(v31->value.v[2]),
          arg3: (const idEventArg *)__ROL4__(LODWORD(v31->value.q[3]), 32));
      }
    }
    goto LABEL_34;
  }
  if ( owner->curEnemyId.value == this->spawnId.value )
  {
    if ( idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED)
       - this->senses.ptr[this->lastSense]->lastConfirmedStimTime <= 5000 )
    {
      if ( idPlayer::CastTo(c: v7) == nullptr )
        goto LABEL_34;
      v40 = idPlayer::CastTo(c: v7);
      Control = (idProp_WeaponStatic *)idPlayer::GetControl(this: v40);
      if ( idProp_WeaponStatic::CastTo(c: Control) == nullptr )
        goto LABEL_34;
      v39 = &EV_EnemyOnTurret;
    }
    else
    {
      if ( this->senses.ptr[1]->lastUnconfirmedStimTime < 0
        || idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED)
         - this->senses.ptr[1]->lastConfirmedStimTime >= 1000 )
      {
        goto LABEL_34;
      }
      v32 = idEntity::GetPhysics(this: v6);
      v33 = idEntity::GetPhysics(this: v7);
      v34 = (float *)v32->GetOrigin(this: v32, a2: 0);
      v35 = (float *)v33->GetOrigin(this: v33, a2: 0);
      v36 = *v34;
      v37 = (float)(v35[1] - v34[1]);
      v53[0].z = v35[2] - v34[2];
      v53[0].y = v37;
      v53[0].x = *v35 - (float)v36;
      v52 = v53[0];
      idVec3::NormalizeFast(this: &v52);
      presentable = (float *)v7->presentable;
      if ( presentable == nullptr )
      {
        idEntity::InitPresentableInternal(this: v7);
        presentable = (float *)v7->presentable;
      }
      if ( (float)((float)(v52.x * presentable[33])
                 + (float)((float)(presentable[34] * v52.y) + (float)(presentable[35] * v52.z))) <= 0.49999997 )
        goto LABEL_34;
      v39 = &EV_BehindEnemy;
    }
    idEventReceiver::ProcessEvent(this: (idEventReceiver *)&v55, result: (idEventArg *)v6, ev: v39);
  }
LABEL_34:
  v42 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED)
      - this->senses.ptr[1]->lastConfirmedStimTime;
  v43 = &clientGame->gameTimeManager;
  if ( v42 < 1000 )
  {
LABEL_38:
    v9->aiVolatile.memory.lastActuallySeenEnemyTime = idGameTimeManager::GetGameMs(this: v43, type: GAMETIME_SCALED);
    return;
  }
  if ( idGameTimeManager::GetGameMs(this: v43, type: GAMETIME_SCALED) - this->senses.ptr[0]->lastConfirmedStimTime < 1000 )
  {
    v44 = idEntity::GetPhysics(this: v9);
    v45 = (int)v44->GetOrigin(this: v44, a2: 0);
    v46 = this->senses.ptr[0];
    v47 = (float *)v45;
    v48 = aiSenseState_t::GetConfirmedPhysicalSafe(this: v46);
    v49 = (float)(v48->origin.y - v47[1]);
    v50 = (float)(v48->origin.z - v47[2]);
    if ( (float)((float)((float)(v48->origin.x - *v47) * (float)(v48->origin.x - *v47))
               + (float)((float)((float)v50 * (float)v50) + (float)((float)v49 * (float)v49))) < 262144.0 )
    {
      v43 = &clientGame->gameTimeManager;
      goto LABEL_38;
    }
  }
}


// ========================================================================
// ?WithinFOV@idAIEntityState@@SA_NABVidAILogic@@PBUaiLatchedState_t@@AAM@Z
// EA  : 0x82AFA500
// RVA : 0x00AFA500
// PDB : w:\tech5\tungsten\game\ai\gamestate\aientitystate.cpp
// ========================================================================

int __fastcall idAIEntityState::WithinFOV(const idAILogic *owner, const aiLatchedState_t *tols, float *fovWeight)
{
  unsigned __int64 v6; // r6
  const char *v7; // r7
  const aiLatchedState_t *State; // r30
  idRenderWorld *v9; // r3
  double y; // fp9
  double x; // fp7
  double v12; // fp6
  double v13; // fp5
  double z; // fp9
  double v15; // fp8
  double v16; // fp13
  double v17; // fp10
  double v18; // fp12
  double v19; // fp0
  double v23; // fp5
  double v24; // fp1
  double v25; // fp0
  double v26; // fp1
  double v27; // fp31
  double v28; // fp1
  double v29; // fp1
  idPLogScope v30; // [sp+58h] [-68h] BYREF
  idVec3 v31; // [sp+60h] [-60h] BYREF
  float v32[6]; // [sp+70h] [-50h] BYREF

  RD_EventBegin(name: "idAIEntityState::WithinFOV");
  LODWORD(v6) = "idAIEntityState::WithinFOV";
  HIDWORD(v6) = 6;
  idPLogScope::idPLogScope(this: &v30, pl: &pLog, gMask: v6, label: v7);
  State = idAIGameState::GetState(this: &gameLocal->aiGameState, spawnId: &owner->spawnId);
  if ( State != nullptr && tols != nullptr )
  {
    if ( ai_debugFOV.valueInteger != 0 )
    {
      v9 = common->RW(this: common);
      y = State->physical.eyePos.y;
      x = State->physical.eyePos.x;
      v12 = (float)(State->physical.viewfwd.y * (float)500.0);
      v13 = (float)(State->physical.viewfwd.x * (float)500.0);
      v32[2] = State->physical.eyePos.z + (float)(State->physical.viewfwd.z * (float)500.0);
      v32[1] = (float)y + (float)v12;
      v32[0] = (float)x + (float)v13;
      v9->DebugLine(
        this: v9,
        a2: (const idVec4 *)&idColor::colorRed,
        a3: &State->physical.eyePos,
        a4: (const idVec3 *)v32,
        a5: 100,
        a6: false);
    }
    *fovWeight = 1.0;
    z = State->physical.eyePos.z;
    v15 = tols->physical.eyePos.z;
    v16 = (float)(tols->physical.eyePos.y - State->physical.eyePos.y);
    v17 = (float)(tols->physical.eyePos.x - State->physical.eyePos.x);
    v18 = (float)(tols->physical.eyePos.z - State->physical.eyePos.z);
    v31.x = tols->physical.eyePos.x - State->physical.eyePos.x;
    v31.y = v16;
    v31.z = (float)v15 - (float)z;
    v19 = (float)((float)(v31.z * v31.z) + (float)((float)((float)v17 * (float)v17) + (float)((float)v16 * (float)v16)));
    if ( v19 < 0.1 )
      goto LABEL_6;
    _FP8 = (float)((float)((float)((float)((float)v15 - (float)z) * (float)((float)v15 - (float)z))
                         + (float)((float)((float)v17 * (float)v17) + (float)((float)v16 * (float)v16)))
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm { fsel      f6, f8, f0, f9 }
    v23 = __frsqrte(_FP6);
    v24 = (float)((float)-(float)((float)((float)((float)v23
                                                * (float)((float)((float)(v31.z * v31.z)
                                                                + (float)((float)((float)v17 * (float)v17)
                                                                        + (float)((float)v16 * (float)v16)))
                                                        * (float)0.5))
                                        * (float)v23)
                                - (float)1.5)
                * (float)v23);
    v25 = (float)((float)((float)-(float)((float)((float)((float)v23 * (float)((float)v19 * (float)0.5)) * (float)v23)
                                        - (float)1.5)
                        * (float)v23)
                * (float)((float)v19 * (float)0.5));
    v31.x = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)v25 * (float)v24) - (float)1.5)
                                                          * (float)v24)
                                                  * (float)((float)((float)(v31.z * v31.z)
                                                                  + (float)((float)((float)v17 * (float)v17)
                                                                          + (float)((float)v16 * (float)v16)))
                                                          * (float)0.5))
                                          * (float)((float)-(float)((float)((float)v25 * (float)v24) - (float)1.5)
                                                  * (float)v24))
                                  - (float)1.5)
                  * (float)((float)-(float)((float)((float)v25 * (float)v24) - (float)1.5) * (float)v24))
          * (float)v17;
    v31.y = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)v25 * (float)v24) - (float)1.5)
                                                          * (float)v24)
                                                  * (float)((float)((float)(v31.z * v31.z)
                                                                  + (float)((float)((float)v17 * (float)v17)
                                                                          + (float)((float)v16 * (float)v16)))
                                                          * (float)0.5))
                                          * (float)((float)-(float)((float)((float)v25 * (float)v24) - (float)1.5)
                                                  * (float)v24))
                                  - (float)1.5)
                  * (float)((float)-(float)((float)((float)v25 * (float)v24) - (float)1.5) * (float)v24))
          * (float)v16;
    v31.z = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)v25 * (float)v24) - (float)1.5)
                                                          * (float)v24)
                                                  * (float)((float)((float)(v31.z * v31.z)
                                                                  + (float)((float)((float)v17 * (float)v17)
                                                                          + (float)((float)v16 * (float)v16)))
                                                          * (float)0.5))
                                          * (float)((float)-(float)((float)((float)v25 * (float)v24) - (float)1.5)
                                                  * (float)v24))
                                  - (float)1.5)
                  * (float)((float)-(float)((float)((float)v25 * (float)v24) - (float)1.5) * (float)v24))
          * (float)v18;
    if ( State->horzFOV == 0 )
      goto LABEL_6;
    v26 = idAIVisibility::ByteToFOVDot(fov: State->horzFOV);
    v27 = v26;
    if ( State->vertFOV != 0 )
    {
      v29 = idAIVisibility::ByteToFOVDot(fov: State->vertFOV);
      v28 = idAIVisibility::CheckFOV(dir: &v31, eyeFwd: &State->physical.viewfwd, cosHorzFOV: v27, cosVertFOV: v29);
    }
    else
    {
      v28 = idAIVisibility::CheckFOV(dir: &v31, eyeFwd: &State->physical.viewfwd, cosFOV: v26);
    }
    *fovWeight = v28;
    if ( v28 > 0.0 )
    {
LABEL_6:
      idPLogScope::~idPLogScope(this: &v30);
      RD_EventEnd();
      return 1;
    }
    idPLogScope::~idPLogScope(this: &v30);
  }
  else
  {
    *fovWeight = 0.0;
    idPLogScope::~idPLogScope(this: &v30);
  }
  RD_EventEnd();
  return 0;
}


// ========================================================================
// __unwind$492503
// EA  : 0x82AFA790
// RVA : 0x00AFA790
// PDB : w:\tech5\tungsten\game\ai\gamestate\aientitystate.cpp
// ========================================================================

void _unwind_492503()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 192 + 124));
}


// ========================================================================
// __unwind$492504
// EA  : 0x82AFA7B8
// RVA : 0x00AFA7B8
// PDB : w:\tech5\tungsten\game\ai\gamestate\aientitystate.cpp
// ========================================================================

void _unwind_492504()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 192 + 88));
}


// ========================================================================
// ?AICanSee_Submit@idAIEntityState@@SAXABVidAILogic@@PBUaiLatchedState_t@@_NAAUaiDefVisInfo_t@1@@Z
// EA  : 0x82AFA7E8
// RVA : 0x00AFA7E8
// PDB : w:\tech5\tungsten\game\ai\gamestate\aientitystate.cpp
// ========================================================================

void __fastcall idAIEntityState::AICanSee_Submit(
        const idAILogic *owner,
        const aiLatchedState_t *tols,
        const bool seeThroughBreakables,
        idAIEntityState::aiDefVisInfo_t *defVisInfo)
{
  unsigned __int64 v8; // r6
  const char *v9; // r7
  const aiLatchedState_t *State; // r3
  int v11; // r25
  idSpawnId *p_spawnId; // r29
  const idVec3 *p_eyePos; // r28
  int EntityNumber; // r3
  double v15; // fp10
  double v16; // fp9
  int v17; // r3
  int v18; // [sp+8h] [-F8h]
  int v19; // [sp+8h] [-F8h]
  bool v20; // [sp+Fh] [-F1h]
  bool v21; // [sp+Fh] [-F1h]
  const char *v22; // [sp+10h] [-F0h]
  const char *v23; // [sp+10h] [-F0h]
  int v24; // [sp+14h] [-ECh]
  int v25; // [sp+14h] [-ECh]
  int v26; // [sp+18h] [-E8h]
  int v27; // [sp+18h] [-E8h]
  int v28; // [sp+1Ch] [-E4h]
  int v29; // [sp+1Ch] [-E4h]
  int v30; // [sp+20h] [-E0h]
  int v31; // [sp+20h] [-E0h]
  int v32; // [sp+24h] [-DCh]
  int v33; // [sp+24h] [-DCh]
  int v34; // [sp+28h] [-D8h]
  int v35; // [sp+28h] [-D8h]
  int v36; // [sp+2Ch] [-D4h]
  int v37; // [sp+2Ch] [-D4h]
  int v38; // [sp+30h] [-D0h]
  int v39; // [sp+30h] [-D0h]
  int v40; // [sp+34h] [-CCh]
  int v41; // [sp+34h] [-CCh]
  int v42; // [sp+38h] [-C8h]
  int v43; // [sp+38h] [-C8h]
  int v44; // [sp+3Ch] [-C4h]
  int v45; // [sp+3Ch] [-C4h]
  int v46; // [sp+40h] [-C0h]
  int v47; // [sp+40h] [-C0h]
  int v48; // [sp+44h] [-BCh]
  int v49; // [sp+44h] [-BCh]
  int v50; // [sp+48h] [-B8h]
  int v51; // [sp+48h] [-B8h]
  int v52; // [sp+4Ch] [-B4h]
  int v53; // [sp+4Ch] [-B4h]
  int v54; // [sp+50h] [-B0h]
  int v55; // [sp+50h] [-B0h]
  int v56; // [sp+58h] [-A8h]
  int v57; // [sp+58h] [-A8h]
  int v58; // [sp+60h] [-A0h]
  int v59; // [sp+60h] [-A0h]
  idPLogScope v60; // [sp+70h] [-90h] BYREF
  _BYTE v61[8]; // [sp+78h] [-88h] BYREF
  idVec3 v62; // [sp+80h] [-80h] BYREF
  idBoundsShort v63; // [sp+90h] [-70h] BYREF
  float v64; // [sp+9Ch] [-64h]
  float v65; // [sp+A0h] [-60h]
  float v66; // [sp+A4h] [-5Ch]

  RD_EventBegin(name: "idAIEntityState::AICanSee_Submit");
  LODWORD(v8) = "idAIEntityState::AICanSee_Submit";
  HIDWORD(v8) = 6;
  idPLogScope::idPLogScope(this: &v60, pl: &pLog, gMask: v8, label: v9);
  State = idAIGameState::GetState(this: &gameLocal->aiGameState, spawnId: &owner->spawnId);
  v11 = 3;
  if ( !seeThroughBreakables )
    v11 = 8195;
  p_spawnId = &State->spawnId;
  p_eyePos = &State->physical.eyePos;
  EntityNumber = idSpawnId::GetEntityNumber(this: &State->spawnId);
  defVisInfo->eyeQuery.index = *(_QWORD *)&idClip::Translation(
                                             this: (idClip *)v61,
                                             result: &clientGame->clip,
                                             a3: nullptr,
                                             start: p_eyePos,
                                             end: &tols->physical.eyePos,
                                             clipModel: nullptr,
                                             startAxis: &mat3_identity,
                                             clipMask: v11,
                                             passEntityNumber: v18,
                                             moveClipModel: v20,
                                             userName: v22,
                                             a12: v24,
                                             a13: v26,
                                             a14: v28,
                                             a15: v30,
                                             a16: v32,
                                             a17: v34,
                                             a18: v36,
                                             a19: v38,
                                             a20: v40,
                                             a21: v42,
                                             a22: v44,
                                             a23: v46,
                                             a24: v48,
                                             a25: v50,
                                             a26: v52,
                                             a27: v54,
                                             a28: EntityNumber,
                                             a29: v56,
                                             a30: false,
                                             a31: v58,
                                             a32: (int)"w:\\tech5\\tungsten\\game\\ai\\gamestate\\AIEntityState.cpp(924) : Translation")->world;
  if ( tols->entityType == 1 )
  {
    idBoundsShort::ToBounds(this: &v63, result: (idBounds *)&tols->physical.bounds);
    v15 = (float)((float)(tols->physical.origin.y + v65) + (float)(tols->physical.origin.y + *(float *)&v63.b[0][2]));
    v16 = (float)((float)(tols->physical.origin.z + v66) + (float)(tols->physical.origin.z + *(float *)&v63.b[1][1]));
    v62.x = (float)((float)(tols->physical.origin.x + v64) + (float)(tols->physical.origin.x + *(float *)&v63.b[0][0]))
          * (float)0.5;
    v62.y = (float)v15 * (float)0.5;
    v62.z = (float)v16 * (float)0.5;
    v17 = idSpawnId::GetEntityNumber(this: p_spawnId);
    defVisInfo->boundsQuery.index = *(_QWORD *)&idClip::Translation(
                                                  this: (idClip *)v61,
                                                  result: &clientGame->clip,
                                                  a3: nullptr,
                                                  start: p_eyePos,
                                                  end: &v62,
                                                  clipModel: nullptr,
                                                  startAxis: &mat3_identity,
                                                  clipMask: v11,
                                                  passEntityNumber: v19,
                                                  moveClipModel: v21,
                                                  userName: v23,
                                                  a12: v25,
                                                  a13: v27,
                                                  a14: v29,
                                                  a15: v31,
                                                  a16: v33,
                                                  a17: v35,
                                                  a18: v37,
                                                  a19: v39,
                                                  a20: v41,
                                                  a21: v43,
                                                  a22: v45,
                                                  a23: v47,
                                                  a24: v49,
                                                  a25: v51,
                                                  a26: v53,
                                                  a27: v55,
                                                  a28: v17,
                                                  a29: v57,
                                                  a30: false,
                                                  a31: v59,
                                                  a32: (int)"w:\\tech5\\tungsten\\game\\ai\\gamestate\\AIEntityState.cpp(933) : Translation")->world;
  }
  idPLogScope::~idPLogScope(this: &v60);
  RD_EventEnd();
}


// ========================================================================
// __unwind$492621
// EA  : 0x82AFA9A0
// RVA : 0x00AFA9A0
// PDB : w:\tech5\tungsten\game\ai\gamestate\aientitystate.cpp
// ========================================================================

void _unwind_492621()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 256 + 168));
}


// ========================================================================
// __unwind$492622
// EA  : 0x82AFA9C8
// RVA : 0x00AFA9C8
// PDB : w:\tech5\tungsten\game\ai\gamestate\aientitystate.cpp
// ========================================================================

void _unwind_492622()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 256 + 112));
}


// ========================================================================
// ?UpdateSense@idAIEntityState@@AAA_NPBVidAIGameState@@ABVidAILogic@@ABVidSpawnId@@2ABV?$idHandle@HW4invalidAIEvent_t@@$0?0@@AAVaiSenseState_t@@PBUaiLatchedState_t@@@Z
// EA  : 0x82AFA9F8
// RVA : 0x00AFA9F8
// PDB : w:\tech5\tungsten\game\ai\gamestate\aientitystate.cpp
// ========================================================================

int __fastcall idAIEntityState::UpdateSense(
        idAIEntityState *this,
        idAIGameState *gameState,
        const idAILogic *owner,
        const idSpawnId *entId,
        const idSpawnId *sourceEntId,
        const idHandle<int,enum invalidAIEvent_t,-1> *sourceEventId,
        aiSenseState_t *sense,
        const aiLatchedState_t *ls)
{
  unsigned __int64 v15; // r6
  const char *v16; // r7
  int v17; // r20
  const aiLatchedState_t *State; // r24
  aiSenseState_t_vtbl *v20; // r10
  const aiLatchedEvent_t *Event; // r3
  const aiLatchedState_t *v22; // r4
  unsigned __int8 v23; // r8
  const aiLatchedState_t *v24; // r3
  unsigned __int8 v25; // r10
  idPLogScope v26[15]; // [sp+58h] [-78h] BYREF

  RD_EventBegin(name: "idAIEntityState::UpdateSense");
  LODWORD(v15) = "idAIEntityState::UpdateSense";
  HIDWORD(v15) = 2;
  idPLogScope::idPLogScope(this: v26, pl: &pLog, gMask: v15, label: v16);
  v17 = 0;
  State = idAIGameState::GetState(this: &gameLocal->aiGameState, spawnId: &owner->spawnId);
  if ( ls == nullptr )
  {
    *((_BYTE *)this + 541) &= ~0x80u;
    idPLogScope::~idPLogScope(this: v26);
    RD_EventEnd();
    return 0;
  }
  aiPhysicalState_t::operator=(this: &sense->unConfirmedPhysical, __that: &ls->physical);
  if ( sense->integrator.value == 1.0 )
  {
    if ( sense->lastConfirmedStimTime >= 0
      && ls->spawnId.value == owner->curEnemyId.value
      && (sense->senseFlags & 1) != 0 )
    {
      idAIEntityState::TestSurprise(this, gameState, owner, ls);
    }
    aiPhysicalState_t::operator=(this: &sense->confirmedPhysical, __that: &ls->physical);
    v20 = sense->__vftable;
    v17 = 1;
    sense->lastConfirmedStimTime = gameState->gameTime;
    v20->Update(this: sense, a2: ls);
  }
  Event = idAIGameState::GetEvent(this: gameState, handle: sourceEventId);
  if ( Event != nullptr )
  {
    if ( (Event->flags & 1) != 0 )
    {
      v22 = idAIGameState::GetState(this: gameState, spawnId: &Event->relevantId);
      if ( v22 != nullptr )
        aiPhysicalState_t::operator=(this: &sense->unConfirmedPhysical, __that: &v22->physical);
    }
    else
    {
      sense->unConfirmedPhysical.origin.x = Event->origin.x;
      sense->unConfirmedPhysical.origin.y = Event->origin.y;
      sense->unConfirmedPhysical.origin.z = Event->origin.z;
    }
  }
  sense->aiOrigin.x = State->physical.origin.x;
  sense->aiOrigin.y = State->physical.origin.y;
  sense->aiOrigin.z = State->physical.origin.z;
  v23 = sense->senseFlags & 0xFB;
  sense->lastUnconfirmedStimTime = gameState->gameTime;
  sense->senseFlags = v23;
  v24 = idAIGameState::GetState(this: gameState, spawnId: sourceEntId);
  if ( v24 != nullptr )
  {
    if ( sourceEntId->value == owner->spawnId.value )
    {
      v25 = sense->senseFlags | 1;
LABEL_19:
      sense->senseFlags = v25;
      goto LABEL_20;
    }
    if ( v24->groupHandle.value == State->groupHandle.value )
    {
      v25 = sense->senseFlags | 2;
      goto LABEL_19;
    }
  }
LABEL_20:
  idPLogScope::~idPLogScope(this: v26);
  RD_EventEnd();
  return v17;
}


// ========================================================================
// __unwind$492946
// EA  : 0x82AFAC34
// RVA : 0x00AFAC34
// PDB : w:\tech5\tungsten\game\ai\gamestate\aientitystate.cpp
// ========================================================================

void _unwind_492946()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 208 + 96));
}


// ========================================================================
// __unwind$492947
// EA  : 0x82AFAC5C
// RVA : 0x00AFAC5C
// PDB : w:\tech5\tungsten\game\ai\gamestate\aientitystate.cpp
// ========================================================================

void _unwind_492947()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 208 + 88));
}


// ========================================================================
// ?UpdateSeen@idAIEntityState@@QAAXPBVidAIGameState@@ABVidAILogic@@@Z
// EA  : 0x82AFAC88
// RVA : 0x00AFAC88
// PDB : w:\tech5\tungsten\game\ai\gamestate\aientitystate.cpp
// ========================================================================

void __fastcall idAIEntityState::UpdateSeen(idAIEntityState *this, idAIGameState *gameState, const idAILogic *owner)
{
  aiSenseState_t *v3; // r27
  idSpawnId *p_spawnId; // r30
  float y; // r10
  float z; // r9
  float x; // r8
  float v11; // r7
  float v12; // r6
  int lastUnconfirmedStimTime; // r26
  const aiLatchedState_t *State; // r25
  const aiLatchedState_t *v15; // r3
  double v16; // fp13
  double v17; // fp12
  double v18; // fp11
  double v19; // fp10
  double v20; // fp9
  idHandle<int,enum invalidAIEvent_t,-1> v21; // [sp+50h] [-70h] BYREF
  float v22; // [sp+58h] [-68h]
  float v23; // [sp+5Ch] [-64h]
  float v24; // [sp+60h] [-60h]
  float v25; // [sp+68h] [-58h]
  float v26; // [sp+6Ch] [-54h]
  float v27; // [sp+70h] [-50h]

  v3 = this->senses.ptr[1];
  p_spawnId = &this->spawnId;
  y = v3->unConfirmedPhysical.origin.y;
  z = v3->unConfirmedPhysical.origin.z;
  x = v3->aiOrigin.x;
  v11 = v3->aiOrigin.y;
  v12 = v3->aiOrigin.z;
  lastUnconfirmedStimTime = v3->lastUnconfirmedStimTime;
  v22 = v3->unConfirmedPhysical.origin.x;
  v23 = y;
  v24 = z;
  v25 = x;
  v26 = v11;
  v27 = v12;
  v21.value = -1;
  State = idAIGameState::GetState(this: gameState, spawnId: &this->spawnId);
  v15 = idAIGameState::GetState(this: &gameLocal->aiGameState, spawnId: &owner->spawnId);
  idAIEntityState::UpdateSense(
    this,
    gameState,
    owner,
    entId: p_spawnId,
    sourceEntId: &v15->spawnId,
    sourceEventId: &v21,
    sense: v3,
    ls: State);
  v3->lastUnconfirmedStimTime = lastUnconfirmedStimTime;
  v16 = v23;
  v17 = v24;
  v18 = v25;
  v19 = v26;
  v20 = v27;
  v3->unConfirmedPhysical.origin.x = v22;
  v3->unConfirmedPhysical.origin.y = v16;
  v3->unConfirmedPhysical.origin.z = v17;
  v3->aiOrigin.x = v18;
  v3->aiOrigin.y = v19;
  v3->aiOrigin.z = v20;
}


// ========================================================================
// ?Refresh_Submit@idAIEntityState@@QAAXPBVidAIGameState@@PBVidAIWorldState@@ABVidAILogic@@AAUaiDefVisInfo_t@1@@Z
// EA  : 0x82AFAD70
// RVA : 0x00AFAD70
// PDB : w:\tech5\tungsten\game\ai\gamestate\aientitystate.cpp
// ========================================================================

void __fastcall idAIEntityState::Refresh_Submit(
        idAIEntityState *this,
        idAIGameState *gameState,
        const idAIWorldState *worldState,
        const idAILogic *owner,
        idAIEntityState::aiDefVisInfo_t *defVisInfo)
{
  idSpawnId *p_spawnId; // r30
  const aiLatchedState_t *State; // r3
  const aiLatchedState_t *v10; // r29
  aiSenseState_t *v11; // r26
  int v12; // r3
  aiSenseState_t *v13; // r31
  int v14; // r29
  int stimulusType; // r11
  const aiLatchedState_t *v16; // r30
  int EntityNumber; // r28
  const aiPhysicalState_t *ConfirmedPhysicalSafe; // r3
  int v19; // [sp+8h] [-A8h]
  bool v20; // [sp+Fh] [-A1h]
  const char *v21; // [sp+10h] [-A0h]
  int v22; // [sp+14h] [-9Ch]
  int v23; // [sp+18h] [-98h]
  int v24; // [sp+1Ch] [-94h]
  int v25; // [sp+20h] [-90h]
  int v26; // [sp+24h] [-8Ch]
  int v27; // [sp+28h] [-88h]
  int v28; // [sp+2Ch] [-84h]
  int v29; // [sp+30h] [-80h]
  int v30; // [sp+34h] [-7Ch]
  int v31; // [sp+38h] [-78h]
  int v32; // [sp+3Ch] [-74h]
  int v33; // [sp+40h] [-70h]
  int v34; // [sp+44h] [-6Ch]
  int v35; // [sp+48h] [-68h]
  int v36; // [sp+4Ch] [-64h]
  int v37; // [sp+50h] [-60h]
  int v38; // [sp+58h] [-58h]
  int v39; // [sp+60h] [-50h]
  char v40; // [sp+70h] [-40h] BYREF

  p_spawnId = &this->spawnId;
  State = idAIGameState::GetState(this: gameState, spawnId: &this->spawnId);
  v10 = State;
  if ( State != nullptr && State->spawnId.value == p_spawnId->value )
  {
    v11 = this->senses.ptr[1];
    v12 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
    idAIEntityState::AICanSee_Submit(
      owner,
      tols: v10,
      seeThroughBreakables: ((v12 - v11->lastConfirmedStimTime >= 0) + ((unsigned int)(v12 - v11->lastConfirmedStimTime) >= 0x3E8)) & 1,
      defVisInfo);
    v13 = this->senses.ptr[1];
    if ( v13->lastConfirmedStimTime >= 0 )
    {
      v14 = 3;
      if ( gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) - v13->lastConfirmedStimTime < 1000 )
        v14 = 8195;
      stimulusType = v13->stimulusType;
      if ( stimulusType == 8 || stimulusType == 9 )
      {
        v16 = idAIGameState::GetState(this: &gameLocal->aiGameState, spawnId: &owner->spawnId);
        EntityNumber = idSpawnId::GetEntityNumber(this: &owner->spawnId);
        ConfirmedPhysicalSafe = aiSenseState_t::GetConfirmedPhysicalSafe(this: v13);
        defVisInfo->lastSeenPosQuery.index = *(_QWORD *)&idClip::Translation(
                                                           this: (idClip *)&v40,
                                                           result: &clientGame->clip,
                                                           a3: nullptr,
                                                           start: &v16->physical.eyePos,
                                                           end: &ConfirmedPhysicalSafe->eyePos,
                                                           clipModel: nullptr,
                                                           startAxis: &mat3_identity,
                                                           clipMask: v14,
                                                           passEntityNumber: v19,
                                                           moveClipModel: v20,
                                                           userName: v21,
                                                           a12: v22,
                                                           a13: v23,
                                                           a14: v24,
                                                           a15: v25,
                                                           a16: v26,
                                                           a17: v27,
                                                           a18: v28,
                                                           a19: v29,
                                                           a20: v30,
                                                           a21: v31,
                                                           a22: v32,
                                                           a23: v33,
                                                           a24: v34,
                                                           a25: v35,
                                                           a26: v36,
                                                           a27: v37,
                                                           a28: EntityNumber,
                                                           a29: v38,
                                                           a30: false,
                                                           a31: v39,
                                                           a32: (int)"w:\\tech5\\tungsten\\game\\ai\\gamestate\\AIEntityState."
                                                                "cpp(508) : Translation")->world;
      }
    }
  }
  else
  {
    *((_BYTE *)this + 541) &= ~0x80u;
  }
}


// ========================================================================
// ?AddStimulus@idAIEntityState@@QAAXPBVidAIGameState@@ABVidAILogic@@W4aiStimulus_t@@MABVidSpawnId@@ABV?$idHandle@HW4invalidAIEvent_t@@$0?0@@PBUaiLatchedState_t@@@Z
// EA  : 0x82AFAEF8
// RVA : 0x00AFAEF8
// PDB : w:\tech5\tungsten\game\ai\gamestate\aientitystate.cpp
// ========================================================================

void __fastcall idAIEntityState::AddStimulus(
        idAIEntityState *this,
        idAIGameState *gameState,
        const idAILogic *owner,
        const aiStimulus_t stimulusType,
        double stimulusAmount,
        const idSpawnId *entSourceId,
        const idSpawnId *eventSourceId,
        const idHandle<int,enum invalidAIEvent_t,-1> *ls,
        const aiLatchedState_t *State)
{
  unsigned __int64 v17; // r6
  const char *v18; // r7
  __int64 v19; // r8
  const idAIEntityState::stimulusToSense_t *v20; // r29
  char v21; // r25
  int v22; // r6
  int v23; // r28
  int trigger; // r5
  char v25; // r11
  int v26; // r23
  double v27; // fp1
  idEntity *v28; // r3
  double y; // fp13
  double z; // fp12
  idFaction *faction; // [sp+50h] [-B0h]
  idPLogScope v32; // [sp+58h] [-A8h] BYREF
  char v33; // [sp+60h] [-A0h]
  float x; // [sp+64h] [-9Ch]
  float v35; // [sp+68h] [-98h]
  float v36; // [sp+6Ch] [-94h]

  RD_EventBegin(name: "idAIEntityState::AddStimulus");
  LODWORD(v17) = "idAIEntityState::AddStimulus";
  HIDWORD(v17) = 6;
  idPLogScope::idPLogScope(this: &v32, pl: &pLog, gMask: v17, label: v18);
  LODWORD(v19) = *((_BYTE *)this + 541) & 0x80;
  if ( (*((_BYTE *)this + 541) & 0x80) == 0 )
    goto LABEL_30;
  if ( State == nullptr )
  {
    State = idAIGameState::GetState(this: gameState, spawnId: &this->spawnId);
    if ( State == nullptr )
      goto LABEL_30;
  }
  if ( State->spawnId.value != this->spawnId.value )
    goto LABEL_30;
  v20 = &idAIEntityState::SENSE_FOR_STIMULUS[stimulusType];
  v21 = 0;
  HIDWORD(v19) = v20->sense + 128;
  v22 = 4 * HIDWORD(v19);
  v23 = *((_DWORD *)&this->__vftable + HIDWORD(v19));
  *(_BYTE *)(v23 + 210) = stimulusType;
  trigger = v20->trigger;
  if ( v20->trigger )
  {
    v25 = *(_BYTE *)(v23 + 192);
    v26 = v23 + 180;
    *(float *)(v23 + 180) = 1.0;
    if ( (v25 & 0x80) == 0 )
      *(_BYTE *)(v23 + 192) = v25 & 0x7F | 0x80;
    idAIEntityState::IncreaseAwareness(this, owner, newAwareness: v20->awareness);
    v21 = 1;
LABEL_21:
    if ( v20->sense == AISENSE_SIGHT )
      this->lastVisualStimulus = stimulusAmount;
    goto LABEL_23;
  }
  v27 = 1.0;
  if ( v20->sense == AISENSE_HEARING && stimulusAmount != 1.0 && ai_enableSenseVolumes.valueInteger != 0 )
    v27 = idPerceptionVolume::ByteToScale(b: State->physical.stimScale);
  v26 = v23 + 180;
  if ( !idLeakyIntegrator<0,1>::AddStimulus(
          this: (idLeakyIntegrator<0,1> *)(v23 + 180),
          curTimeMS: gameState->gameTime,
          stimulus: (float)((float)v27 * (float)stimulusAmount),
          a4: trigger,
          a5: v22,
          a6: v19) )
    goto LABEL_21;
  idAIEntityState::IncreaseAwareness(this, owner, newAwareness: v20->awareness);
  v21 = 1;
  if ( v20->sense == AISENSE_SIGHT )
  {
    if ( owner->encounterGroup != nullptr )
    {
      faction = owner->faction;
      if ( faction != nullptr
        && idFaction::GetAttitudeTowards(this: faction, id: (const idSpawnId *)this->spawnId.value) < ATTITUDE_NEUTRAL )
      {
        v28 = gameLocal->GetEntityForSpawnId(this: gameLocal, a2: owner->spawnId.value);
        if ( v28 != nullptr )
        {
          y = State->physical.origin.y;
          z = State->physical.origin.z;
          x = State->physical.origin.x;
          v33 = 118;
          v35 = y;
          v36 = z;
          idEventReceiver::PostEventMS(
            this: v28,
            ev: &EV_UpdateGroupAmbush,
            time: 0,
            arg1: (const idEventArg *)LODWORD(v35));
        }
      }
    }
    goto LABEL_21;
  }
LABEL_23:
  if ( stimulusType == AISTIMULUS_GROUP_SUSPECTED )
    *(_BYTE *)(v23 + 209) = *(_BYTE *)(v23 + 209) & 0xFC | 2;
  if ( (unsigned __int8)idAIEntityState::UpdateSense(
                          this,
                          gameState,
                          owner,
                          entId: &this->spawnId,
                          sourceEntId: eventSourceId,
                          sourceEventId: ls,
                          sense: (aiSenseState_t *)v23,
                          ls: State) != 0
    || this->lastSense == 2 )
  {
    this->lastSense = v20->sense;
  }
  if ( v21 != 0 )
    *(_BYTE *)(v26 + 12) &= ~0x80u;
LABEL_30:
  idPLogScope::~idPLogScope(this: &v32);
  RD_EventEnd();
}


// ========================================================================
// __unwind$493171
// EA  : 0x82AFB1EC
// RVA : 0x00AFB1EC
// PDB : w:\tech5\tungsten\game\ai\gamestate\aientitystate.cpp
// ========================================================================

void _unwind_493171()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 256 + 116));
}


// ========================================================================
// __unwind$493172
// EA  : 0x82AFB214
// RVA : 0x00AFB214
// PDB : w:\tech5\tungsten\game\ai\gamestate\aientitystate.cpp
// ========================================================================

void _unwind_493172()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 256 + 88));
}


// ========================================================================
// ?Refresh_Resolve@idAIEntityState@@QAAXPBVidAIGameState@@PBVidAIWorldState@@ABVidAILogic@@AAUaiDefVisInfo_t@1@@Z
// EA  : 0x82AFB248
// RVA : 0x00AFB248
// PDB : w:\tech5\tungsten\game\ai\gamestate\aientitystate.cpp
// ========================================================================

void __fastcall idAIEntityState::Refresh_Resolve(
        idAIEntityState *this,
        idAIGameState *gameState,
        idTypesafeNumber<int,enum gameTimeUnique_t> *worldState,
        const idAILogic *owner,
        idAIEntityState::aiDefVisInfo_t *defVisInfo)
{
  unsigned __int64 v10; // r6
  const char *v11; // r7
  const aiLatchedState_t *State; // r30
  const aiLatchedState_t *v13; // r25
  visibleType_t v14; // r23
  int v15; // r3
  unsigned __int8 v16; // r11
  double v18; // fp4
  double v20; // fp2
  double v21; // fp10
  double v22; // fp5
  double v23; // fp13
  int v24; // r20
  const idTypesafeNumber<int,enum gameTimeUnique_t> *CurrentRefreshInterval; // r3
  double StimulusForVisibility; // fp1
  const aiStimulus_t *v27; // r6
  const aiLatchedState_t *v28; // r5
  double v29; // fp25
  double v30; // fp4
  double v31; // fp28
  aiSenseState_t *v32; // r3
  double v33; // fp27
  double v34; // fp26
  aiStimulus_t v35; // r28
  int lastConfirmedStimTime; // r4
  const aiPhysicalState_t *ConfirmedPhysicalSafe; // r3
  double v38; // fp10
  double v39; // fp6
  double v42; // fp7
  double v43; // fp10
  double v44; // fp1
  const idSpawnId *v45; // r7
  __int64 v46; // r8
  idClientGame *v47; // r11
  float *v48; // r5
  float *v49; // r4
  aiSenseState_t *v50; // r27
  idClipQuery *p_lastSeenPosQuery; // r29
  idClip *p_clip; // r28
  __int128 v53; // r11
  int v54; // r10
  unsigned int lastVisible; // r10
  unsigned int lastSense; // r10
  aiSenseState_t *v59; // r11
  int lastUnconfirmedStimTime; // r10
  int curAwareness; // r11
  double v62; // fp13
  double combatTimeoutInterval; // fp0
  aiAwareness_t v64; // r5
  double searchTimeoutInterval; // fp0
  double v66; // fp11
  double v67; // fp0
  double v68; // fp11
  double value; // [sp+18h] [-328h]
  __int64 v70; // [sp+60h] [-2E0h] BYREF
  char v71; // [sp+68h] [-2D8h]
  idHandle<int,enum invalidAIEvent_t,-1> v72; // [sp+6Ch] [-2D4h] BYREF
  idPLogScope v73[2]; // [sp+70h] [-2D0h] BYREF
  float v74[4]; // [sp+80h] [-2C0h] BYREF
  float v75[4]; // [sp+90h] [-2B0h] BYREF
  float v76[4]; // [sp+A0h] [-2A0h] BYREF
  float v77[4]; // [sp+B0h] [-290h] BYREF
  float v78[4]; // [sp+C0h] [-280h] BYREF
  float v79[16]; // [sp+D0h] [-270h] BYREF
  float v80[16]; // [sp+110h] [-230h] BYREF
  float v81[16]; // [sp+150h] [-1F0h] BYREF
  float v82[16]; // [sp+190h] [-1B0h] BYREF
  float v83[16]; // [sp+1D0h] [-170h] BYREF
  trace_t v84; // [sp+210h] [-130h] BYREF

  RD_EventBegin(name: "idAIEntityState::Refresh_Resolve");
  LODWORD(v10) = "idAIEntityState::Refresh_Resolve";
  HIDWORD(v10) = 6;
  idPLogScope::idPLogScope(this: v73, pl: &pLog, gMask: v10, label: v11);
  State = idAIGameState::GetState(this: gameState, spawnId: &this->spawnId);
  v13 = idAIGameState::GetState(this: &gameLocal->aiGameState, spawnId: &owner->spawnId);
  if ( State == nullptr || State->spawnId.value != this->spawnId.value )
  {
    *((_BYTE *)this + 541) &= ~0x80u;
    idPLogScope::~idPLogScope(this: v73);
    goto LABEL_59;
  }
  if ( defVisInfo->fovWeight <= 0.0 && !defVisInfo->closeEnough && ai_visTraceOutsideFOV.valueInteger == 0 )
  {
    v14 = VISIBLE_OUTSIDE_FOV;
    goto LABEL_12;
  }
  v15 = idAIEntityState::AICanSee_Resolve(owner, defVisInfo, tols: State);
  v14 = v15;
  if ( v15 == 5 )
  {
    if ( debugDeferredWorldRefresh.valueInteger != 0 )
    {
      v79[0] = v13->physical.eyePos.x;
      v79[1] = v13->physical.eyePos.y;
      v79[2] = v13->physical.eyePos.z;
      v79[3] = 3.0;
      v79[4] = 3.0;
      v79[5] = 3.0;
      v79[6] = mat3_identity.mat[0].x;
      v79[7] = mat3_identity.mat[0].y;
      v79[8] = mat3_identity.mat[0].z;
      v79[9] = mat3_identity.mat[1].x;
      v79[10] = mat3_identity.mat[1].y;
      v79[11] = mat3_identity.mat[1].z;
      v79[12] = mat3_identity.mat[2].x;
      v79[13] = mat3_identity.mat[2].y;
      v79[14] = mat3_identity.mat[2].z;
      v76[0] = 0.0;
      v76[1] = 0.0;
      v76[2] = 0.0;
      v76[3] = 0.0;
      clientGame->renderWorld->DebugBox(
        this: clientGame->renderWorld,
        a2: (const idVec4 *)v76,
        a3: (const idBox *)v79,
        a4: 1500,
        a5: false);
    }
    goto LABEL_10;
  }
  if ( v15 == 1 )
  {
LABEL_12:
    if ( defVisInfo->closeEnough )
    {
      v14 = VISIBLE_VISIBLE;
      v16 = 1;
      _FP5 = (float)((float)((float)(defVisInfo->delta.z * defVisInfo->delta.z)
                           + (float)((float)(defVisInfo->delta.x * defVisInfo->delta.x)
                                   + (float)(defVisInfo->delta.y * defVisInfo->delta.y)))
                   - idMath::FLT_SMALLEST_NON_DENORMAL);
      v18 = (float)((float)((float)(defVisInfo->delta.z * defVisInfo->delta.z)
                          + (float)((float)(defVisInfo->delta.x * defVisInfo->delta.x)
                                  + (float)(defVisInfo->delta.y * defVisInfo->delta.y)))
                  * (float)0.5);
      __asm { fsel      f3, f5, f6, f0 }
      v20 = __frsqrte(_FP3);
      v21 = (float)-(float)((float)((float)((float)((float)((float)(defVisInfo->delta.z * defVisInfo->delta.z)
                                                          + (float)((float)(defVisInfo->delta.x * defVisInfo->delta.x)
                                                                  + (float)(defVisInfo->delta.y * defVisInfo->delta.y)))
                                                  * (float)0.5)
                                          * (float)v20)
                                  * (float)v20)
                          - (float)1.5);
      v22 = (float)((float)-(float)((float)((float)((float)((float)((float)(defVisInfo->delta.z * defVisInfo->delta.z)
                                                                  + (float)((float)(defVisInfo->delta.x
                                                                                  * defVisInfo->delta.x)
                                                                          + (float)(defVisInfo->delta.y
                                                                                  * defVisInfo->delta.y)))
                                                          * (float)0.5)
                                                  * (float)((float)v21 * (float)v20))
                                          * (float)((float)v21 * (float)v20))
                                  - (float)1.5)
                  * (float)((float)v21 * (float)v20));
      v23 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v18
                                                                                                  * (float)((float)-(float)((float)((float)((float)v18 * (float)((float)v21 * (float)v20)) * (float)((float)v21 * (float)v20)) - (float)1.5) * (float)((float)v21 * (float)v20)))
                                                                                          * (float)v22)
                                                                                  - (float)1.5)
                                                                  * (float)v22)
                                                          * (float)((float)(defVisInfo->delta.z * defVisInfo->delta.z)
                                                                  + (float)((float)(defVisInfo->delta.x
                                                                                  * defVisInfo->delta.x)
                                                                          + (float)(defVisInfo->delta.y
                                                                                  * defVisInfo->delta.y))))
                                                  * idAIWorldState::AI_CLOSE_ENOUGH_FOR_VIS_SCALE)
                                          - (float)1.0)
                          * (float)0.69999999)
                  + (float)-0.30000001);
      HIDWORD(v70) = &defVisInfo->delta;
      defVisInfo->fovWeight = v23;
      goto LABEL_17;
    }
    goto LABEL_16;
  }
  if ( v15 > 2 )
  {
    v16 = 1;
    goto LABEL_17;
  }
LABEL_16:
  v16 = 0;
LABEL_17:
  v24 = v16;
  if ( v16 != 0 )
  {
    CurrentRefreshInterval = idAIWorldState::GetCurrentRefreshInterval(this: (idAIWorldState *)&v70, result: worldState);
    StimulusForVisibility = idAIWorldState::GetStimulusForVisibility(
                              this: (idAIWorldState *)worldState,
                              vis: v14,
                              interval: CurrentRefreshInterval);
    v27 = idAIWorldState::STIMULUS_TYPE_FOR_VIS;
    v28 = (const aiLatchedState_t *)(4 * v14);
    v29 = StimulusForVisibility;
    v30 = 100000.0;
    v31 = (float)(State->physical.origin.x - v13->physical.origin.x);
    v32 = this->senses.ptr[this->lastSense];
    v33 = (float)(State->physical.origin.z - v13->physical.origin.z);
    v34 = (float)(State->physical.origin.y - v13->physical.origin.y);
    v35 = idAIWorldState::STIMULUS_TYPE_FOR_VIS[v14];
    lastConfirmedStimTime = v32->lastConfirmedStimTime;
    HIDWORD(v70) = v32;
    if ( lastConfirmedStimTime >= 0 )
    {
      HIDWORD(v70) = v32;
      ConfirmedPhysicalSafe = aiSenseState_t::GetConfirmedPhysicalSafe(this: v32);
      v38 = (float)(ConfirmedPhysicalSafe->origin.y - State->physical.origin.y);
      v39 = (float)(ConfirmedPhysicalSafe->origin.z - State->physical.origin.z);
      v30 = __fsqrts((float)((float)((float)v39 * (float)v39)
                           + (float)((float)((float)(ConfirmedPhysicalSafe->origin.x - State->physical.origin.x)
                                           * (float)(ConfirmedPhysicalSafe->origin.x - State->physical.origin.x))
                                   + (float)((float)v38 * (float)v38))));
    }
    _FP10 = (float)((float)((float)((float)v33 * (float)v33)
                          + (float)((float)((float)v31 * (float)v31) + (float)((float)v34 * (float)v34)))
                  - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm { fsel      f8, f10, f11, f0 }
    v42 = __frsqrte(_FP8);
    v43 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v42
                                                                                        * (float)((float)((float)((float)v33 * (float)v33) + (float)((float)((float)v31 * (float)v31) + (float)((float)v34 * (float)v34)))
                                                                                                * (float)0.5))
                                                                                * (float)v42)
                                                                        - (float)1.5)
                                                        * (float)v42)
                                                * (float)((float)((float)((float)v33 * (float)v33)
                                                                + (float)((float)((float)v31 * (float)v31)
                                                                        + (float)((float)v34 * (float)v34)))
                                                        * (float)0.5))
                                        * (float)((float)-(float)((float)((float)((float)v42
                                                                                * (float)((float)((float)((float)v33 * (float)v33)
                                                                                                + (float)((float)((float)v31 * (float)v31) + (float)((float)v34 * (float)v34)))
                                                                                        * (float)0.5))
                                                                        * (float)v42)
                                                                - (float)1.5)
                                                * (float)v42))
                                - (float)1.5)
                * (float)((float)-(float)((float)((float)((float)v42
                                                        * (float)((float)((float)((float)v33 * (float)v33)
                                                                        + (float)((float)((float)v31 * (float)v31)
                                                                                + (float)((float)v34 * (float)v34)))
                                                                * (float)0.5))
                                                * (float)v42)
                                        - (float)1.5)
                        * (float)v42));
    v44 = idAIWorldState::VisibilityEffects(
            this: (idAIWorldState *)worldState,
            owner,
            input: v29,
            fovWeight: defVisInfo->fovWeight,
            ls: v28,
            vis: (const visibleType_t)v27,
            distance: (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v42 * (float)((float)((float)((float)v33 * (float)v33) + (float)((float)((float)v31 * (float)v31) + (float)((float)v34 * (float)v34))) * (float)0.5)) * (float)v42) - (float)1.5) * (float)v42)
                                                                                                  * (float)((float)((float)((float)v33 * (float)v33) + (float)((float)((float)v31 * (float)v31) + (float)((float)v34 * (float)v34))) * (float)0.5))
                                                                                          * (float)((float)-(float)((float)((float)((float)v42 * (float)((float)((float)((float)v33 * (float)v33) + (float)((float)((float)v31 * (float)v31) + (float)((float)v34 * (float)v34))) * (float)0.5)) * (float)v42) - (float)1.5)
                                                                                                  * (float)v42))
                                                                                  - (float)1.5)
                                                                  * (float)((float)-(float)((float)((float)((float)v42 * (float)((float)((float)((float)v33 * (float)v33) + (float)((float)((float)v31 * (float)v31) + (float)((float)v34 * (float)v34))) * (float)0.5))
                                                                                                  * (float)v42)
                                                                                          - (float)1.5)
                                                                          * (float)v42))
                                                          * (float)((float)((float)((float)v33 * (float)v33)
                                                                          + (float)((float)((float)v31 * (float)v31)
                                                                                  + (float)((float)v34 * (float)v34)))
                                                                  * (float)0.5))
                                                  * (float)v43)
                                          - (float)1.5)
                          * (float)v43)
                  * (float)((float)((float)v33 * (float)v33)
                          + (float)((float)((float)v31 * (float)v31) + (float)((float)v34 * (float)v34)))),
            displacement: v30,
            isRelaxed: (const bool)State);
    v72.value = -1;
    idAIEntityState::AddStimulus(
      this,
      gameState,
      owner,
      stimulusType: v35,
      stimulusAmount: v44,
      entSourceId: v45,
      eventSourceId: &owner->spawnId,
      ls: &v72,
      State);
    HIDWORD(v46) = &debugDeferredWorldRefresh;
    if ( debugDeferredWorldRefresh.valueInteger != 0 )
    {
      v81[0] = v13->physical.eyePos.x;
      v81[1] = v13->physical.eyePos.y;
      v47 = clientGame;
      v48 = v81;
      v49 = v77;
      v81[2] = v13->physical.eyePos.z;
      v81[3] = 3.0;
      v81[4] = 3.0;
      v81[5] = 3.0;
      v81[6] = mat3_identity.mat[0].x;
      v81[7] = mat3_identity.mat[0].y;
      v81[8] = mat3_identity.mat[0].z;
      v81[9] = mat3_identity.mat[1].x;
      v81[10] = mat3_identity.mat[1].y;
      v81[11] = mat3_identity.mat[1].z;
      v81[12] = mat3_identity.mat[2].x;
      v81[13] = mat3_identity.mat[2].y;
      v81[14] = mat3_identity.mat[2].z;
      v77[1] = 1.0;
      v77[2] = 0.0;
      v77[0] = 0.0;
      v77[3] = 0.0;
LABEL_34:
      v47->renderWorld->DebugBox(
        this: v47->renderWorld,
        a2: (const idVec4 *)v49,
        a3: (const idBox *)v48,
        a4: 1500,
        a5: false);
    }
  }
  else
  {
    v50 = this->senses.ptr[1];
    p_lastSeenPosQuery = &defVisInfo->lastSeenPosQuery;
    v50->senseFlags &= ~4u;
    p_clip = &clientGame->clip;
    if ( (unsigned __int8)idClip::QueryIsValid(this: &clientGame->clip, clipQuery: p_lastSeenPosQuery) != 0 )
    {
      LODWORD(v53) = 0;
      *(idClipQuery *)((char *)&v53 + 4) = (idClipQuery)p_lastSeenPosQuery->index;
      HIDWORD(v70) = p_clip;
      p_lastSeenPosQuery->index = v53;
      idCollisionModelManager::GetContentsResult(
        this: collisionModelManager,
        result: &v84,
        query: &p_clip->collisionQueries[WORD5(v53) & 0xFFF].query,
        peek: false);
      if ( (unsigned __int8)TraceVisible(dls: State, tr: &v84) != 0 )
        v50->senseFlags |= 4u;
    }
    v54 = v50->lastConfirmedStimTime;
    LODWORD(v70) = (int)(float)((float)1000.0 * (float)5.0);
    if ( v54 < (int)v70 )
    {
      _FP13 = (float)((float)0.5 - v50->integrator.value);
      __asm { fsel      f12, f13, f0, f24 }
      v50->integrator.value = _FP12;
    }
    else
    {
      v50->integrator.value = 0.0;
    }
    if ( debugDeferredWorldRefresh.valueInteger != 0 )
    {
      v47 = clientGame;
      if ( (v50->senseFlags & 4) != 0 )
      {
        v83[0] = v13->physical.eyePos.x;
        v48 = v83;
        v49 = v75;
        v83[1] = v13->physical.eyePos.y;
        v83[2] = v13->physical.eyePos.z;
        v83[3] = 3.0;
        v83[4] = 3.0;
        v83[5] = 3.0;
        v83[6] = mat3_identity.mat[0].x;
        v83[7] = mat3_identity.mat[0].y;
        v83[8] = mat3_identity.mat[0].z;
        v83[9] = mat3_identity.mat[1].x;
        v83[10] = mat3_identity.mat[1].y;
        v83[11] = mat3_identity.mat[1].z;
        v83[12] = mat3_identity.mat[2].x;
        v83[13] = mat3_identity.mat[2].y;
        v83[14] = mat3_identity.mat[2].z;
        v75[0] = 0.0;
        v75[1] = 1.0;
        v75[2] = 1.0;
        v75[3] = 0.0;
      }
      else if ( v14 == VISIBLE_OUTSIDE_FOV )
      {
        v80[0] = v13->physical.eyePos.x;
        v48 = v80;
        v49 = v74;
        v80[1] = v13->physical.eyePos.y;
        v80[2] = v13->physical.eyePos.z;
        v80[3] = 3.0;
        v80[4] = 3.0;
        v80[5] = 3.0;
        v80[6] = mat3_identity.mat[0].x;
        v80[7] = mat3_identity.mat[0].y;
        v80[8] = mat3_identity.mat[0].z;
        v80[9] = mat3_identity.mat[1].x;
        v80[10] = mat3_identity.mat[1].y;
        v80[11] = mat3_identity.mat[1].z;
        v80[12] = mat3_identity.mat[2].x;
        v80[13] = mat3_identity.mat[2].y;
        v80[14] = mat3_identity.mat[2].z;
        v74[0] = 0.0;
        v74[1] = 0.0;
        v74[2] = 1.0;
        v74[3] = 0.0;
      }
      else
      {
        v82[0] = v13->physical.eyePos.x;
        v48 = v82;
        v49 = v78;
        v82[1] = v13->physical.eyePos.y;
        v82[2] = v13->physical.eyePos.z;
        v82[3] = 3.0;
        v82[4] = 3.0;
        v82[5] = 3.0;
        v82[6] = mat3_identity.mat[0].x;
        v82[7] = mat3_identity.mat[0].y;
        v82[8] = mat3_identity.mat[0].z;
        v82[9] = mat3_identity.mat[1].x;
        v82[10] = mat3_identity.mat[1].y;
        v82[11] = mat3_identity.mat[1].z;
        v82[12] = mat3_identity.mat[2].x;
        v82[13] = mat3_identity.mat[2].y;
        v82[14] = mat3_identity.mat[2].z;
        v78[0] = 1.0;
        v78[1] = 0.0;
        v78[2] = 0.0;
        v78[3] = 0.0;
      }
      goto LABEL_34;
    }
  }
  if ( ai_debugLevel.valueInteger >= 1 && ai_debugPerception.valueInteger >= 5 )
  {
    value = this->senses.ptr[1]->integrator.value;
    idLib::Printf(fmt: (const char *)HIDWORD(value), LODWORD(value));
  }
  lastVisible = this->lastVisible;
  if ( v14 != lastVisible )
  {
    this->lastVisible = v14;
    HIDWORD(v46) = (lastVisible <= 2) - 1;
    v71 = BYTE3(v46) & 1;
    if ( v24 != (BYTE3(v46) & 1) )
      this->visChangeTime = gameState->gameTime;
  }
  lastSense = this->lastSense;
  if ( lastSense >= 2 )
    goto LABEL_10;
  v59 = this->senses.ptr[lastSense];
  lastUnconfirmedStimTime = v59->lastConfirmedStimTime;
  if ( lastUnconfirmedStimTime < 0 )
    lastUnconfirmedStimTime = v59->lastUnconfirmedStimTime;
  curAwareness = this->curAwareness;
  LODWORD(v46) = gameState->gameTime - lastUnconfirmedStimTime;
  v70 = v46;
  v62 = (float)((float)v46 * (float)0.001);
  switch ( curAwareness )
  {
    case 3:
      combatTimeoutInterval = owner->combatTimeoutInterval;
      *(float *)&v70 = owner->combatTimeoutInterval;
      if ( combatTimeoutInterval < 0.0 )
        goto LABEL_10;
      *(float *)&v70 = combatTimeoutInterval;
      if ( v62 < combatTimeoutInterval )
        goto LABEL_10;
      v64 = AIAWARE_SUSPECTED;
      break;
    case 2:
      searchTimeoutInterval = owner->searchTimeoutInterval;
      *(float *)&v70 = owner->searchTimeoutInterval;
      if ( searchTimeoutInterval < 0.0 )
        goto LABEL_10;
      v66 = (float)((float)searchTimeoutInterval + owner->combatTimeoutInterval);
      *(float *)&v70 = searchTimeoutInterval;
      if ( v62 < v66 )
        goto LABEL_10;
      v64 = AIAWARE_LOST;
      break;
    case 1:
      v67 = owner->searchTimeoutInterval;
      *(float *)&v70 = owner->searchTimeoutInterval;
      if ( v67 < 0.0 )
        goto LABEL_10;
      v68 = (float)((float)v67 + owner->combatTimeoutInterval);
      *(float *)&v70 = v67;
      if ( v62 < v68 )
        goto LABEL_10;
      v64 = AIAWARE_UNAWARE;
      break;
    default:
      goto LABEL_10;
  }
  idAIEntityState::DecreaseAwareness(this, owner, newAwareness: v64);
LABEL_10:
  idPLogScope::~idPLogScope(this: v73);
LABEL_59:
  RD_EventEnd();
}


// ========================================================================
// __unwind$493312
// EA  : 0x82AFBBC8
// RVA : 0x00AFBBC8
// PDB : w:\tech5\tungsten\game\ai\gamestate\aientitystate.cpp
// ========================================================================

void _unwind_493312()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 832 + 656));
}


// ========================================================================
// __unwind$493313
// EA  : 0x82AFBBF0
// RVA : 0x00AFBBF0
// PDB : w:\tech5\tungsten\game\ai\gamestate\aientitystate.cpp
// ========================================================================

void _unwind_493313()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 832 + 112));
}


// ========================================================================
// `dynamic initializer for 'ai_useOriginSprings''
// EA  : 0x83369838
// RVA : 0x01369838
// PDB : w:\tech5\tungsten\game\ai\gamestate\aientitystate.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_useOriginSprings__()
{
  idCVar::idCVar(
    this: &ai_useOriginSprings,
    name: "ai_useOriginSprings",
    value: "1",
    flags: 1,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_useOriginSprings__);
}


// ========================================================================
// `dynamic initializer for 'ai_originSpringExtrapolate''
// EA  : 0x83369890
// RVA : 0x01369890
// PDB : w:\tech5\tungsten\game\ai\gamestate\aientitystate.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_originSpringExtrapolate__()
{
  idCVar::idCVar(
    this: &ai_originSpringExtrapolate,
    name: "ai_originSpringExtrapolate",
    value: "0.1",
    flags: 4,
    description: "amount to extrapolate velocity in origin springs (0.1 seems to work)",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_originSpringExtrapolate__);
}


// ========================================================================
// `dynamic initializer for 'ai_debugOriginSprings''
// EA  : 0x833698E8
// RVA : 0x013698E8
// PDB : w:\tech5\tungsten\game\ai\gamestate\aientitystate.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_debugOriginSprings__()
{
  idCVar::idCVar(
    this: &ai_debugOriginSprings,
    name: "ai_debugOriginSprings",
    value: "0",
    flags: 1,
    description: "1 = show origin springs",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_debugOriginSprings__);
}


// ========================================================================
// `dynamic initializer for 'ai_debugFOV''
// EA  : 0x83369940
// RVA : 0x01369940
// PDB : w:\tech5\tungsten\game\ai\gamestate\aientitystate.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_debugFOV__()
{
  idCVar::idCVar(
    this: &ai_debugFOV,
    name: "ai_debugFOV",
    value: "0",
    flags: 1,
    description: "1 = show entity FOV checks.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_debugFOV__);
}


// ========================================================================
// `dynamic initializer for 'debugDeferredWorldRefresh''
// EA  : 0x83369998
// RVA : 0x01369998
// PDB : w:\tech5\tungsten\game\ai\gamestate\aientitystate.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__debugDeferredWorldRefresh__()
{
  idCVar::idCVar(
    this: &debugDeferredWorldRefresh,
    name: "debugDeferredWorldRefresh",
    value: "0",
    flags: 1,
    description: "Toggle a box around the AI's head which indicates the results of his refresh update.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__debugDeferredWorldRefresh__);
}

