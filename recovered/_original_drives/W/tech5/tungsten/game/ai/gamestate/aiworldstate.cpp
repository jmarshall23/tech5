
// ========================================================================
// ?Init@idAIWorldState@@QAAXMHH@Z
// EA  : 0x82AFD2E8
// RVA : 0x00AFD2E8
// PDB : w:\tech5\tungsten\game\ai\gamestate\aiworldstate.cpp
// ========================================================================

void __fastcall idAIWorldState::Init(
        idAIWorldState *this,
        double visibleSightTime_,
        const int friendlyVisibilityEffectsMask_,
        int enemyVisibilityEffectsMask_,
        int a5)
{
  int v5; // r11
  int i; // ctr

  this->visibleSightTime = visibleSightTime_;
  v5 = 0;
  this->friendlyVisibilityEffectsMask = enemyVisibilityEffectsMask_;
  this->numFreeEnts = 8;
  this->enemyVisibilityEffectsMask = a5;
  this->numEnts = 0;
  for ( i = 8; i != 0; --i )
  {
    this->ents[v5].value = -1;
    this->freeEnts[v5].value = v5;
    ++v5;
  }
}


// ========================================================================
// ?StateForSpawnId@idAIWorldState@@QBAPBVidAIEntityState@@ABVidSpawnId@@@Z
// EA  : 0x82AFD330
// RVA : 0x00AFD330
// PDB : w:\tech5\tungsten\game\ai\gamestate\aiworldstate.cpp
// ========================================================================

idAIEntityState *__fastcall idAIWorldState::StateForSpawnId(idAIWorldState *this, const idSpawnId *entId)
{
  int v2; // r10
  int numEnts; // r6

  v2 = 0;
  numEnts = this->numEnts;
  if ( numEnts <= 0 )
    return nullptr;
  while ( this->entityStates[this->ents[v2].value].spawnId.value != entId->value )
  {
    if ( ++v2 >= numEnts )
      return nullptr;
  }
  return &this->entityStates[this->ents[v2].value];
}


// ========================================================================
// ?StateForEntity@idAIWorldState@@QAAPAVidAIEntityState@@PBVidEntity@@@Z
// EA  : 0x82AFD3A8
// RVA : 0x00AFD3A8
// PDB : w:\tech5\tungsten\game\ai\gamestate\aiworldstate.cpp
// ========================================================================

idAIEntityState *__fastcall idAIWorldState::StateForEntity(idAIWorldState *this, const idEntity *ent)
{
  idSpawnId v4[4]; // [sp+50h] [-20h] BYREF

  idGameLocal::GetSpawnId(this: (idGameLocal *)v4, result: (idSpawnId *)gameLocal, ent);
  return idAIWorldState::StateForSpawnId(this, entId: v4);
}


// ========================================================================
// ?Clear@idAIWorldState@@QAAXXZ
// EA  : 0x82AFD538
// RVA : 0x00AFD538
// PDB : w:\tech5\tungsten\game\ai\gamestate\aiworldstate.cpp
// ========================================================================

void __fastcall idAIWorldState::Clear(idAIWorldState *this)
{
  int v1; // r11
  int i; // ctr

  v1 = 0;
  this->numFreeEnts = 8;
  this->numEnts = 0;
  for ( i = 8; i != 0; --i )
  {
    this->ents[v1].value = -1;
    this->freeEnts[v1].value = v1;
    ++v1;
  }
}


// ========================================================================
// ?GetCurrentRefreshInterval@idAIWorldState@@QBA?AV?$idTypesafeNumber@HW4gameTimeUnique_t@@@@XZ
// EA  : 0x82AFD570
// RVA : 0x00AFD570
// PDB : w:\tech5\tungsten\game\ai\gamestate\aiworldstate.cpp
// ========================================================================

idAIWorldState *__fastcall idAIWorldState::GetCurrentRefreshInterval(
        idAIWorldState *this,
        idTypesafeNumber<int,enum gameTimeUnique_t> *result)
{
  int num; // r30
  idGameTimeManager *p_gameTimeManager; // r3
  int v5; // r10

  num = gameLocal->aiWorldStateUsers.num;
  p_gameTimeManager = &clientGame->gameTimeManager;
  if ( num > 2 )
    v5 = idGameTimeManager::GetGameMsPerFrame(this: p_gameTimeManager, type: GAMETIME_SCALED) * num;
  else
    v5 = 3 * idGameTimeManager::GetGameMsPerFrame(this: p_gameTimeManager, type: GAMETIME_SCALED);
  this->__vftable = (idAIWorldState_vtbl *)v5;
  return this;
}


// ========================================================================
// ?AllocEntityState@idAIWorldState@@AAAPAVidAIEntityState@@XZ
// EA  : 0x82AFD600
// RVA : 0x00AFD600
// PDB : w:\tech5\tungsten\game\ai\gamestate\aiworldstate.cpp
// ========================================================================

idAIEntityState *__fastcall idAIWorldState::AllocEntityState(idAIWorldState *this)
{
  int numFreeEnts; // r10
  char *v4; // r5
  char value; // r4
  int v6; // r10
  idAIEntityState *v7; // r3

  numFreeEnts = this->numFreeEnts;
  if ( numFreeEnts <= 0 )
    return nullptr;
  v4 = (char *)this + this->numEnts;
  value = this->ents[numFreeEnts + 7].value;
  this->numFreeEnts = numFreeEnts - 1;
  v4[4] = value;
  v6 = value;
  ++this->numEnts;
  v7 = &this->entityStates[v6];
  if ( (idAIWorldState *)((char *)this + v6 * 576) == (idAIWorldState *)-24 )
    return nullptr;
  else
    return idAIEntityState::idAIEntityState(this: v7);
}


// ========================================================================
// __unwind$489192
// EA  : 0x82AFD6A0
// RVA : 0x00AFD6A0
// PDB : w:\tech5\tungsten\game\ai\gamestate\aiworldstate.cpp
// ========================================================================

void _unwind_489192()
{
  int v0; // r12

  idPhysics_StaticMulti::UpdateTime(this: *(bfx::BinaryReplayLogOut **)(v0 - 112 + 84));
}


// ========================================================================
// ?RemoveLeastRelevant@idAIWorldState@@AAAXPBVidAIGameState@@ABVidAILogic@@@Z
// EA  : 0x82AFD6D0
// RVA : 0x00AFD6D0
// PDB : w:\tech5\tungsten\game\ai\gamestate\aiworldstate.cpp
// ========================================================================

void __fastcall idAIWorldState::RemoveLeastRelevant(
        idAIWorldState *this,
        idAIGameState *gameState,
        const idAILogic *owner)
{
  int lastUnconfirmedStimTime; // r26
  int v7; // r27
  int v8; // r25
  int v9; // r28
  idIndex<signed char,enum invalidEntityStateIndex_t> *ents; // r24
  char *v11; // r11
  char *v12; // r30
  int v13; // r11
  const aiLatchedState_t *State; // r3
  int v15; // r29
  char *v16; // r30
  __int16 numEnts; // r7
  char v18; // r10
  idSpawnId v19; // [sp+50h] [-150h] BYREF
  idSpawnId v20; // [sp+54h] [-14Ch] BYREF
  aiSenseState_t v21; // [sp+60h] [-140h] BYREF

  lastUnconfirmedStimTime = 0x7FFFFFFF;
  v7 = -1;
  v8 = 2147483646;
  v9 = 0;
  if ( this->numEnts > 0 )
  {
    ents = this->ents;
    while ( 1 )
    {
      v11 = (char *)this + 576 * ents[v9].value;
      v12 = v11 + 24;
      if ( (v11[565] & 0x80) == 0 )
        break;
      v13 = *((_DWORD *)v11 + 136);
      if ( v13 != owner->curEnemyId.value )
      {
        v20.value = v13;
        State = idAIGameState::GetState(this: gameState, spawnId: &v20);
        if ( State == nullptr )
          break;
        v15 = *(const int *)((char *)typePriority + __ROL4__(State->entityType, 2));
        if ( v15 <= v8 )
        {
          aiSenseState_t::aiSenseState_t(
            this: &v21,
            __that: *(const aiSenseState_t **)&v12[4 * (unsigned __int8)v12[538] + 512]);
          if ( v21.lastUnconfirmedStimTime < lastUnconfirmedStimTime )
          {
            lastUnconfirmedStimTime = v21.lastUnconfirmedStimTime;
            v7 = v9;
            v8 = v15;
          }
        }
      }
      if ( ++v9 >= this->numEnts )
        goto LABEL_12;
    }
    v7 = v9;
LABEL_12:
    if ( v7 >= 0 )
    {
      v16 = (char *)this + v7;
      v19.value = this->entityStates[this->ents[v7].value].spawnId.value;
      idTargetCache::RemoveBySpawnId(this: &this->targetCache, spawnId: &v19);
      numEnts = this->numEnts;
      if ( v7 < numEnts )
      {
        v18 = v16[4];
        this->numEnts = numEnts - 1;
        if ( v7 != (__int16)(numEnts - 1) )
          v16[4] = this->ents[(__int16)(numEnts - 1)].value;
        this->freeEnts[this->numFreeEnts++].value = v18;
      }
    }
  }
}


// ========================================================================
// ?GetStimulusForVisibility@idAIWorldState@@QBAMW4visibleType_t@@V?$idTypesafeNumber@HW4gameTimeUnique_t@@@@@Z
// EA  : 0x82AFD868
// RVA : 0x00AFD868
// PDB : w:\tech5\tungsten\game\ai\gamestate\aiworldstate.cpp
// ========================================================================

float __fastcall idAIWorldState::GetStimulusForVisibility(idAIWorldState *this, int vis, __int64 interval, __int64 a4)
{
  double v4; // fp0
  double v5; // fp1

  v4 = 0.0;
  if ( vis > 2 )
    v4 = (float)((float)1.0 / this->visibleSightTime);
  LODWORD(a4) = *(_DWORD *)HIDWORD(interval);
  LODWORD(interval) = timeManager.gameTimePerFrame.value * timeManager.gameHz;
  v5 = (float)((float)((float)((float)1.0 / (float)interval) * (float)a4) * (float)v4);
  return *((float *)&v5 + 1);
}


// ========================================================================
// ??1idAIWorldState@@UAA@XZ
// EA  : 0x82AFD8E0
// RVA : 0x00AFD8E0
// PDB : w:\tech5\tungsten\game\ai\gamestate\aiworldstate.cpp
// ========================================================================

void __fastcall idAIWorldState::~idAIWorldState(idAIWorldState *this)
{
  int v2; // r11
  int i; // ctr

  this->__vftable = (idAIWorldState_vtbl *)&idAIWorldState::`vftable';
  v2 = 0;
  this->numFreeEnts = 8;
  this->numEnts = 0;
  for ( i = 8; i != 0; --i )
  {
    this->ents[v2].value = -1;
    this->freeEnts[v2].value = v2;
    ++v2;
  }
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->targetCache);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->aiDeferredRefreshInfo);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->aiDeferredVisInfo);
  `eh vector destructor iterator'(
    ptr: this->entityStates,
    size: 0x240u,
    count: 8,
    pDtor: (void (__fastcall *)(void *))idAIEntityState::~idAIEntityState);
  this->__vftable = (idAIWorldState_vtbl *)&idClass::`vftable';
}


// ========================================================================
// __unwind$489815
// EA  : 0x82AFD994
// RVA : 0x00AFD994
// PDB : w:\tech5\tungsten\game\ai\gamestate\aiworldstate.cpp
// ========================================================================

void _unwind_489815()
{
  int v0; // r12

  idAIEvent::~idAIEvent(this: *(idAimAssist **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$489816
// EA  : 0x82AFD9BC
// RVA : 0x00AFD9BC
// PDB : w:\tech5\tungsten\game\ai\gamestate\aiworldstate.cpp
// ========================================================================

void _unwind_489816()
{
  int v0; // r12

  `eh vector destructor iterator'(
    ptr: (void *)(*(_DWORD *)(v0 - 112 + 132) + 24),
    size: 0x240u,
    count: 8,
    pDtor: (void (__fastcall *)(void *))idAIEntityState::~idAIEntityState);
}


// ========================================================================
// __unwind$489817
// EA  : 0x82AFD9F8
// RVA : 0x00AFD9F8
// PDB : w:\tech5\tungsten\game\ai\gamestate\aiworldstate.cpp
// ========================================================================

void _unwind_489817()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 4632));
}


// ========================================================================
// __unwind$489818
// EA  : 0x82AFDA24
// RVA : 0x00AFDA24
// PDB : w:\tech5\tungsten\game\ai\gamestate\aiworldstate.cpp
// ========================================================================

void _unwind_489818()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 4648));
}


// ========================================================================
// ??0idAIWorldState@@QAA@XZ
// EA  : 0x82AFDB18
// RVA : 0x00AFDB18
// PDB : w:\tech5\tungsten\game\ai\gamestate\aiworldstate.cpp
// ========================================================================

idAIWorldState *__fastcall idAIWorldState::idAIWorldState(idAIWorldState *this)
{
  unsigned __int64 v2; // r28
  idIndex<signed char,enum invalidEntityStateIndex_t> *freeEnts; // r26
  int v4; // ctr
  int v5; // r11

  LODWORD(v2) = 0;
  this->__vftable = (idAIWorldState_vtbl *)&idAIWorldState::`vftable';
  this->ents[0].value = -1;
  this->ents[1].value = -1;
  HIDWORD(v2) = this->ents;
  this->ents[2].value = -1;
  freeEnts = this->freeEnts;
  this->ents[3].value = -1;
  this->ents[4].value = -1;
  this->ents[5].value = -1;
  this->ents[6].value = -1;
  this->ents[7].value = -1;
  this->freeEnts[0].value = -1;
  this->freeEnts[1].value = -1;
  this->freeEnts[2].value = -1;
  this->freeEnts[3].value = -1;
  this->freeEnts[4].value = -1;
  this->freeEnts[5].value = -1;
  this->freeEnts[6].value = -1;
  this->freeEnts[7].value = -1;
  this->numEnts = 0;
  this->numFreeEnts = 0;
  `eh vector constructor iterator'(
    ptr: this->entityStates,
    size: 0x240u,
    count: 8,
    pCtor: (void (__fastcall *)(void *))idAIEntityState::idAIEntityState,
    pDtor: (void (__fastcall *)(void *))idAIEntityState::~idAIEntityState);
  this->aiDeferredVisInfo.list = nullptr;
  this->aiDeferredVisInfo.granularity = 0;
  this->aiDeferredVisInfo.memTag = 5;
  this->aiDeferredVisInfo.listStatic = 0;
  this->aiDeferredVisInfo.size = 0;
  this->aiDeferredVisInfo.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->aiDeferredVisInfo);
  this->aiDeferredRefreshInfo.list = nullptr;
  this->aiDeferredRefreshInfo.granularity = 0;
  this->aiDeferredRefreshInfo.memTag = 5;
  this->aiDeferredRefreshInfo.listStatic = 0;
  this->aiDeferredRefreshInfo.size = 0;
  this->aiDeferredRefreshInfo.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->aiDeferredRefreshInfo);
  this->gatherQuery.index = v2;
  idTargetCache::idTargetCache(this: &this->targetCache);
  this->lastUpdateFrameNum = -1;
  this->lastUpdatePos.x = -65535.0;
  this->lastUpdatePos.y = -65535.0;
  this->lastUpdatePos.z = -65535.0;
  v4 = 8;
  this->numFreeEnts = 8;
  this->radius = 2048.0;
  this->friendlyVisibilityEffectsMask = -1;
  this->visibleSightTime = 0.30000001;
  v5 = 0;
  this->enemyVisibilityEffectsMask = -1;
  this->initialUpdateCount = 2;
  this->updateFriendly = true;
  this->refreshFriendly = true;
  this->bOwnerAiInCover = false;
  this->numEnts = 0;
  do
  {
    *(_BYTE *)(HIDWORD(v2) + v5) = -1;
    freeEnts[v5].value = v5;
    ++v5;
    --v4;
  }
  while ( v4 != 0 );
  return this;
}


// ========================================================================
// __unwind$489914
// EA  : 0x82AFDCA4
// RVA : 0x00AFDCA4
// PDB : w:\tech5\tungsten\game\ai\gamestate\aiworldstate.cpp
// ========================================================================

void _unwind_489914()
{
  int v0; // r12

  idAIEvent::~idAIEvent(this: *(idAimAssist **)(v0 - 160 + 180));
}


// ========================================================================
// __unwind$489915
// EA  : 0x82AFDCCC
// RVA : 0x00AFDCCC
// PDB : w:\tech5\tungsten\game\ai\gamestate\aiworldstate.cpp
// ========================================================================

void _unwind_489915()
{
  int v0; // r12

  `eh vector destructor iterator'(
    ptr: (void *)(*(_DWORD *)(v0 - 160 + 180) + 24),
    size: 0x240u,
    count: 8,
    pDtor: (void (__fastcall *)(void *))idAIEntityState::~idAIEntityState);
}


// ========================================================================
// __unwind$489916
// EA  : 0x82AFDD08
// RVA : 0x00AFDD08
// PDB : w:\tech5\tungsten\game\ai\gamestate\aiworldstate.cpp
// ========================================================================

void _unwind_489916()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 4632));
}


// ========================================================================
// __unwind$489917
// EA  : 0x82AFDD34
// RVA : 0x00AFDD34
// PDB : w:\tech5\tungsten\game\ai\gamestate\aiworldstate.cpp
// ========================================================================

void _unwind_489917()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 4648));
}


// ========================================================================
// ?VisibilityEffects@idAIWorldState@@QBAMABVidAILogic@@MMPBUaiLatchedState_t@@W4visibleType_t@@MM_N@Z
// EA  : 0x82AFDF08
// RVA : 0x00AFDF08
// PDB : w:\tech5\tungsten\game\ai\gamestate\aiworldstate.cpp
// ========================================================================

float __fastcall idAIWorldState::VisibilityEffects(
        idAIWorldState *this,
        const idAILogic *owner,
        double input,
        double fovWeight,
        const aiLatchedState_t *ls,
        const visibleType_t vis,
        double distance,
        double displacement,
        int isRelaxed,
        int a10,
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
        int a30,
        int a31,
        char a32)
{
  unsigned __int64 v39; // r6
  const char *v40; // r7
  idPlayer *v41; // r28
  idPlayer *v42; // r3
  int enemyVisibilityEffectsMask; // r27
  idPlayer *v44; // r23
  double v45; // fp29
  double StimulusDistanceScale; // fp30
  double v47; // fp31
  float v50; // r9
  float v51; // r7
  double v52; // fp12
  double v55; // fp7
  double v56; // fp13
  idPhysics *Physics; // r3
  float *v58; // r3
  double v59; // fp30
  double v60; // fp28
  double v61; // fp29
  idEntity *v62; // r3
  idPhysics *v63; // r3
  float *v64; // r3
  double v67; // fp1
  idFaction *faction; // [sp+50h] [-A0h]
  idPLogScope v70; // [sp+58h] [-98h] BYREF
  float v71; // [sp+60h] [-90h]
  float v72; // [sp+64h] [-8Ch]
  float v73; // [sp+68h] [-88h]

  RD_EventBegin(name: "idAIWorldState::VisibilityEffects");
  LODWORD(v39) = "idAIWorldState::VisibilityEffects";
  HIDWORD(v39) = 2;
  idPLogScope::idPLogScope(this: &v70, pl: &pLog, gMask: v39, label: v40);
  v41 = (idPlayer *)gameLocal->GetEntityForSpawnId(this: gameLocal, a2: *(_DWORD *)(isRelaxed + 88));
  v42 = idPlayer::CastTo(c: v41);
  enemyVisibilityEffectsMask = this->enemyVisibilityEffectsMask;
  v44 = v42;
  v45 = 1.0;
  faction = owner->faction;
  if ( faction != nullptr && idFaction::GetAttitudeTowards(this: faction, otherEnt: v41) >= ATTITUDE_LIKE )
    enemyVisibilityEffectsMask = this->friendlyVisibilityEffectsMask;
  StimulusDistanceScale = 1.0;
  v47 = (float)(ai_visibilitySenseScale.valueFloat * (float)input);
  if ( v41 != nullptr && !v41->IsDead(this: v41) )
    StimulusDistanceScale = idEntity::GetStimulusDistanceScale(this: v41);
  _FP11 = (float)((float)1.0 - (float)((float)500.0 / (float)((float)StimulusDistanceScale * (float)distance)));
  __asm { fsel      f10, f11, f12, f29 }
  if ( (enemyVisibilityEffectsMask & 1) != 0 )
    v47 = (float)((float)v47 * (float)((float)1.0 - (float)((float)1.0 - (float)_FP10)));
  if ( (enemyVisibilityEffectsMask & 2) != 0 && fovWeight <= 0.40000001 )
    v47 = (float)((float)v47 * (float)0.25);
  if ( (enemyVisibilityEffectsMask & 4) != 0 && (*(_WORD *)(isRelaxed + 78) & 2) != 0 )
    v47 = (float)((float)v47 * (float)0.5);
  if ( (enemyVisibilityEffectsMask & 8) != 0 && a10 == 3 )
    v47 = (float)((float)v47 * (float)0.5);
  if ( (enemyVisibilityEffectsMask & 0x20) != 0 )
  {
    v50 = *(float *)(isRelaxed + 16);
    v51 = *(float *)(isRelaxed + 20);
    v71 = *(float *)(isRelaxed + 12);
    v72 = v50;
    v73 = v51;
    v52 = (float)((float)(v71 * v71) + (float)((float)(v73 * v73) + (float)(v72 * v72)));
    _FP11 = (float)((float)((float)(v71 * v71) + (float)((float)(v73 * v73) + (float)(v72 * v72)))
                  - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm { fsel      f8, f11, f12, f13 }
    v55 = __frsqrte(_FP8);
    v56 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v55
                                                                                        * (float)((float)v52 * (float)0.5))
                                                                                * (float)v55)
                                                                        - (float)1.5)
                                                        * (float)v55)
                                                * (float)((float)v52 * (float)0.5))
                                        * (float)((float)-(float)((float)((float)((float)v55
                                                                                * (float)((float)v52 * (float)0.5))
                                                                        * (float)v55)
                                                                - (float)1.5)
                                                * (float)v55))
                                - (float)1.5)
                * (float)((float)-(float)((float)((float)((float)v55 * (float)((float)v52 * (float)0.5)) * (float)v55)
                                        - (float)1.5)
                        * (float)v55));
    if ( (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v55 * (float)((float)v52 * (float)0.5)) * (float)v55) - (float)1.5) * (float)v55)
                                                                                               * (float)((float)v52 * (float)0.5))
                                                                                       * (float)((float)-(float)((float)((float)((float)v55 * (float)((float)v52 * (float)0.5)) * (float)v55) - (float)1.5)
                                                                                               * (float)v55))
                                                                               - (float)1.5)
                                                               * (float)((float)-(float)((float)((float)((float)v55 * (float)((float)v52 * (float)0.5))
                                                                                               * (float)v55)
                                                                                       - (float)1.5)
                                                                       * (float)v55))
                                                       * (float)((float)v52 * (float)0.5))
                                               * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v55 * (float)((float)v52 * (float)0.5)) * (float)v55) - (float)1.5)
                                                                                               * (float)v55)
                                                                                       * (float)((float)v52 * (float)0.5))
                                                                               * (float)((float)-(float)((float)((float)((float)v55 * (float)((float)v52 * (float)0.5)) * (float)v55) - (float)1.5)
                                                                                       * (float)v55))
                                                                       - (float)1.5)
                                                       * (float)((float)-(float)((float)((float)((float)v55
                                                                                               * (float)((float)v52 * (float)0.5))
                                                                                       * (float)v55)
                                                                               - (float)1.5)
                                                               * (float)v55)))
                                       - (float)1.5)
                       * (float)v56)
               * (float)v52) >= 100.0
      || *(__int16 *)(isRelaxed + 76) <= 500 )
    {
      v47 = (float)((float)v47 * (float)2.0);
      if ( v47 >= 0.0 )
      {
        if ( v47 > 1.0 )
          v47 = 1.0;
      }
      else
      {
        v47 = 0.0;
      }
    }
  }
  if ( (enemyVisibilityEffectsMask & 0x40) != 0 )
  {
    if ( ai_enableSenseVolumes.valueInteger != 0 )
      v45 = idPerceptionVolume::ByteToScale(b: *(_BYTE *)(isRelaxed + 80));
    v47 = (float)((float)v47 * (float)v45);
  }
  if ( (enemyVisibilityEffectsMask & 0x80) != 0 )
    v47 = (float)((float)v47 * gameLocal->world->aiSenseScale);
  if ( (enemyVisibilityEffectsMask & 0x200) != 0 && a32 != 0 && owner->slowIdleSpot )
    v47 = (float)((float)v47 * (float)0.25);
  if ( (enemyVisibilityEffectsMask & 0x400) != 0 && v41 != nullptr && !v41->IsDead(this: v41) )
  {
    Physics = idEntity::GetPhysics(this: v41);
    v58 = (float *)Physics->GetBounds(this: Physics, a2: -1);
    v59 = (float)(v58[5] - v58[2]);
    v60 = (float)(v58[4] - v58[1]);
    v61 = (float)(v58[3] - *v58);
    if ( v44 != nullptr && v44->IsDrivingVehicle(this: v44) )
    {
      v62 = (idEntity *)v44->GetVehicle(this: v44);
      v63 = idEntity::GetPhysics(this: v62);
      v64 = (float *)v63->GetBounds(this: v63, a2: -1);
      v59 = (float)(v64[5] - v64[2]);
      v60 = (float)(v64[4] - v64[1]);
      v61 = (float)(v64[3] - *v64);
    }
    if ( idProjectile_Grenade::CastTo(c: (idProjectile_Grenade *)v41) != nullptr )
    {
      v59 = 90.0;
      v61 = 32.0;
      v60 = 32.0;
    }
    _FP12 = (float)((float)v59 - (float)90.0);
    __asm { fsel      f10, f12, f30, f0 }
    v47 = (float)((float)v47
                * (float)((float)((float)((float)_FP10 * (float)((float)v60 + (float)v61)) * (float)0.5)
                        * (float)0.00034722223));
  }
  idPLogScope::~idPLogScope(this: &v70);
  RD_EventEnd();
  v67 = v47;
  return *((float *)&v67 + 1);
}


// ========================================================================
// __unwind$490097
// EA  : 0x82AFE350
// RVA : 0x00AFE350
// PDB : w:\tech5\tungsten\game\ai\gamestate\aiworldstate.cpp
// ========================================================================

void _unwind_490097()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 240 + 108));
}


// ========================================================================
// __unwind$490098
// EA  : 0x82AFE378
// RVA : 0x00AFE378
// PDB : w:\tech5\tungsten\game\ai\gamestate\aiworldstate.cpp
// ========================================================================

void _unwind_490098()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 240 + 88));
}


// ========================================================================
// ?UpdateSeen@idAIWorldState@@AAAXPBVidAIGameState@@ABVidAILogic@@ABUtrackingParms_t@@PBUaiLatchedState_t@@@Z
// EA  : 0x82AFE3A8
// RVA : 0x00AFE3A8
// PDB : w:\tech5\tungsten\game\ai\gamestate\aiworldstate.cpp
// ========================================================================

void __fastcall idAIWorldState::UpdateSeen(
        idAIWorldState *this,
        idAIGameState *gameState,
        const idAILogic *aiOwner,
        const trackingParms_t *trackingParms,
        const aiLatchedState_t *os)
{
  unsigned __int64 v8; // r6
  const char *v9; // r7
  int v10; // r28
  idIndex<signed char,enum invalidEntityStateIndex_t> *ents; // r27
  int value; // r11
  idAIEntityState *v13; // r29
  __int16 numEnts; // r11
  char v15; // r10
  int v16; // r8
  idPLog *pLog; // r29
  idPLog::logEntry_t *v18; // r30
  int v19; // r3
  __int64 totalTicks; // r11
  __int64 v21; // r9
  idSpawnId v22; // [sp+50h] [-60h] BYREF
  idPLogScope v23; // [sp+58h] [-58h] BYREF

  RD_EventBegin(name: "idAIWorldState::UpdateSeen");
  LODWORD(v8) = "idAIWorldState::UpdateSeen";
  HIDWORD(v8) = 6;
  idPLogScope::idPLogScope(this: &v23, pl: &::pLog, gMask: v8, label: v9);
  v10 = this->numEnts - 1;
  if ( v10 >= 0 )
  {
    ents = this->ents;
    do
    {
      value = ents[v10].value;
      v13 = &this->entityStates[value];
      if ( (idAIWorldState *)((char *)this + value * 576) == (idAIWorldState *)-24 )
        goto LABEL_9;
      v22.value = this->entityStates[value].spawnId.value;
      if ( idAIGameState::GetState(this: gameState, spawnId: &v22) == nullptr )
        goto LABEL_9;
      if ( (*((_BYTE *)v13 + 541) & 0x80) != 0 && v13->lastVisible > 2u )
        idAIEntityState::UpdateSeen(this: v13, gameState, owner: aiOwner);
      if ( (*((_BYTE *)v13 + 541) & 0x80) == 0 )
      {
LABEL_9:
        numEnts = this->numEnts;
        if ( v10 < numEnts )
        {
          v15 = ents[v10].value;
          v16 = (__int16)(numEnts - 1);
          this->numEnts = v16;
          if ( v10 != v16 )
            ents[v10] = this->ents[v16];
          this->freeEnts[this->numFreeEnts++].value = v15;
        }
      }
      --v10;
    }
    while ( v10 >= 0 );
  }
  if ( v23.logIndex >= 0 )
  {
    pLog = v23.pLog;
    v18 = &v23.pLog->logEntries.list[v23.logIndex];
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
// __unwind$490411
// EA  : 0x82AFE520
// RVA : 0x00AFE520
// PDB : w:\tech5\tungsten\game\ai\gamestate\aiworldstate.cpp
// ========================================================================

void _unwind_490411()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 176 + 96));
}


// ========================================================================
// __unwind$490412
// EA  : 0x82AFE548
// RVA : 0x00AFE548
// PDB : w:\tech5\tungsten\game\ai\gamestate\aiworldstate.cpp
// ========================================================================

void _unwind_490412()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 176 + 88));
}


// ========================================================================
// ?InternalAddEntityState@idAIWorldState@@AAAPAVidAIEntityState@@PBVidAIGameState@@ABVidAILogic@@ABVidSpawnId@@W4aiStimulus_t@@M2V?$idHandle@HW4invalidAIEvent_t@@$0?0@@PBUaiLatchedState_t@@@Z
// EA  : 0x82AFE578
// RVA : 0x00AFE578
// PDB : w:\tech5\tungsten\game\ai\gamestate\aiworldstate.cpp
// ========================================================================

idAIEntityState *__fastcall idAIWorldState::InternalAddEntityState(
        idAIWorldState *this,
        idAIGameState *gameState,
        const idEntityPtr<idAI2> *owner,
        const idEntityPtr<idAI2> *entId,
        aiStimulus_t stimulusType,
        double stimulusAmount,
        const idSpawnId *sourceId,
        const idEntityPtr<idAI2> *sourceEventHandle,
        const aiLatchedState_t *ls,
        int a10,
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
        idHandle<int,enum invalidAIEvent_t,-1> a27,
        int a28,
        const aiLatchedState_t *a29)
{
  unsigned __int64 v36; // r6
  const char *v37; // r7
  const aiLatchedState_t *State; // r26
  int v39; // r11
  int numEnts; // r6
  char *v41; // r30
  idAIEntityState *v42; // r30
  idAIEntityState *v44; // r3
  idAIEntityState *v45; // r30
  const idSpawnId *v46; // r7
  idPLogScope v47[3]; // [sp+50h] [-70h] BYREF

  a27.value = (int)ls;
  RD_EventBegin(name: "idAIWorldState::InternalAddEntityState");
  LODWORD(v36) = "idAIWorldState::InternalAddEntityState";
  HIDWORD(v36) = 2;
  idPLogScope::idPLogScope(this: v47, pl: &pLog, gMask: v36, label: v37);
  if ( entId->spawnId.value == owner->spawnId.value || entId->spawnId.value == 0x1FFF )
  {
    idPLogScope::~idPLogScope(this: v47);
    RD_EventEnd();
    return nullptr;
  }
  else
  {
    idAIGameState::ForceLatch(this: gameState, spawnId: owner);
    idAIGameState::ForceLatch(this: gameState, spawnId: entId);
    idAIGameState::ForceLatch(this: gameState, spawnId: sourceEventHandle);
    idAIGameState::UpdateForcedLatches(this: gameState, game: gameLocal);
    State = a29;
    if ( a29 == nullptr )
      State = idAIGameState::GetState(this: gameState, spawnId: &entId->spawnId);
    v39 = 0;
    numEnts = this->numEnts;
    if ( numEnts > 0 )
    {
      do
      {
        if ( this->entityStates[this->ents[v39].value].spawnId.value == entId->spawnId.value )
          break;
        ++v39;
      }
      while ( v39 < numEnts );
    }
    if ( v39 >= numEnts )
    {
      if ( numEnts >= 8 )
        idAIWorldState::RemoveLeastRelevant(this, gameState, (const idAILogic *)owner);
      v44 = idAIWorldState::AllocEntityState(this);
      v45 = v44;
      if ( v44 != nullptr )
      {
        idAIEntityState::Init(this: v44, gameState, (const idAILogic *)owner, entId: &entId->spawnId, ls: State);
        idAIEntityState::AddStimulus(
          this: v45,
          gameState,
          (const idAILogic *)owner,
          stimulusType,
          stimulusAmount,
          entSourceId: v46,
          eventSourceId: &sourceEventHandle->spawnId,
          ls: &a27,
          State);
      }
      idPLogScope::~idPLogScope(this: v47);
      RD_EventEnd();
      return v45;
    }
    else
    {
      v41 = (char *)this + v39;
      idAIEntityState::AddStimulus(
        this: &this->entityStates[this->ents[v39].value],
        gameState,
        (const idAILogic *)owner,
        stimulusType,
        stimulusAmount,
        entSourceId: (const idSpawnId *)(9 * this->ents[v39].value),
        eventSourceId: &sourceEventHandle->spawnId,
        ls: &a27,
        State);
      v42 = &this->entityStates[v41[4]];
      idPLogScope::~idPLogScope(this: v47);
      RD_EventEnd();
      return v42;
    }
  }
}


// ========================================================================
// __unwind$490480
// EA  : 0x82AFE798
// RVA : 0x00AFE798
// PDB : w:\tech5\tungsten\game\ai\gamestate\aiworldstate.cpp
// ========================================================================

void _unwind_490480()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 192 + 88));
}


// ========================================================================
// __unwind$490481
// EA  : 0x82AFE7C0
// RVA : 0x00AFE7C0
// PDB : w:\tech5\tungsten\game\ai\gamestate\aiworldstate.cpp
// ========================================================================

void _unwind_490481()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 192 + 80));
}


// ========================================================================
// ?AddEntityStateFromEvent@idAIWorldState@@QAAPBVidAIEntityState@@PBVidAIGameState@@ABVidAILogic@@PBVidAIEvent@@W4aiStimulus_t@@MABVidSpawnId@@@Z
// EA  : 0x82AFE7F0
// RVA : 0x00AFE7F0
// PDB : w:\tech5\tungsten\game\ai\gamestate\aiworldstate.cpp
// ========================================================================

const idAIEntityState *__fastcall idAIWorldState::AddEntityStateFromEvent(
        idAIWorldState *this,
        idAIGameState *gameState,
        idEntityPtr<idAI2> *owner,
        const idAIEvent *event,
        aiStimulus_t stimType,
        double stimAmount,
        const idSpawnId *sourceId,
        const idEntityPtr<idAI2> *a8)
{
  unsigned __int64 v15; // r6
  const char *v16; // r7
  int value; // r9
  idEntity *v18; // r3
  idEntity *v19; // r4
  const aiLatchedState_t *State; // r3
  const idSpawnId *v22; // r8
  idAIEntityState *v23; // r30
  const aiLatchedState_t *v24; // r3
  int v25; // [sp+8h] [-C8h]
  int v26; // [sp+Ch] [-C4h]
  int v27; // [sp+10h] [-C0h]
  int v28; // [sp+14h] [-BCh]
  int v29; // [sp+18h] [-B8h]
  int v30; // [sp+1Ch] [-B4h]
  int v31; // [sp+20h] [-B0h]
  int v32; // [sp+24h] [-ACh]
  int v33; // [sp+28h] [-A8h]
  int v34; // [sp+2Ch] [-A4h]
  int v35; // [sp+30h] [-A0h]
  int v36; // [sp+34h] [-9Ch]
  int v37; // [sp+38h] [-98h]
  int v38; // [sp+3Ch] [-94h]
  int v39; // [sp+40h] [-90h]
  int v40; // [sp+44h] [-8Ch]
  int v41; // [sp+48h] [-88h]
  idHandle<int,enum invalidAIEvent_t,-1> *v42; // [sp+4Ch] [-84h]
  int v43; // [sp+50h] [-80h]
  idSpawnId v44[2]; // [sp+60h] [-70h] BYREF
  idPLogScope v45[3]; // [sp+68h] [-68h] BYREF

  if ( event == nullptr )
    return nullptr;
  RD_EventBegin(name: "idAIWorldState::AddEntityStateFromEvent");
  LODWORD(v15) = "idAIWorldState::AddEntityStateFromEvent";
  HIDWORD(v15) = 2;
  idPLogScope::idPLogScope(this: v45, pl: &pLog, gMask: v15, label: v16);
  value = event->instigator.spawnId.value;
  v44[1].value = (int)&event->instigator;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] != value >> 13
    || (v18 = gameLocal->entities.ptr[value & 0x1FFF]) == nullptr
    || (v19 = idEntity::CastTo(c: v18)) == nullptr )
  {
    idPLogScope::~idPLogScope(this: v45);
    RD_EventEnd();
    return nullptr;
  }
  idSpawnId::idSpawnId(this: v44, ent: v19);
  State = idAIGameState::GetState(this: gameState, spawnId: v44);
  v23 = idAIWorldState::InternalAddEntityState(
          this,
          gameState,
          owner,
          entId: (const idEntityPtr<idAI2> *)v44,
          stimulusType: stimType,
          stimulusAmount: stimAmount,
          sourceId: v22,
          sourceEventHandle: a8,
          ls: (const aiLatchedState_t *)event->handle.value,
          a10: v25,
          a11: v26,
          a12: v27,
          a13: v28,
          a14: v29,
          a15: v30,
          a16: v31,
          a17: v32,
          a18: v33,
          a19: v34,
          a20: v35,
          a21: v36,
          a22: v37,
          a23: v38,
          a24: v39,
          a25: v40,
          a26: v41,
          a27: v42,
          a28: v43,
          a29: State);
  if ( v23 != nullptr )
  {
    v24 = idAILogic::GetState(this: (idAILogic *)owner);
    idTargetCache::Update(this: &this->targetCache, ownerState: v24, worldState: this, targetSpawnId: v44);
  }
  idPLogScope::~idPLogScope(this: v45);
  RD_EventEnd();
  return v23;
}


// ========================================================================
// __unwind$490556
// EA  : 0x82AFE938
// RVA : 0x00AFE938
// PDB : w:\tech5\tungsten\game\ai\gamestate\aiworldstate.cpp
// ========================================================================

void _unwind_490556()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 208 + 112));
}


// ========================================================================
// __unwind$490557
// EA  : 0x82AFE960
// RVA : 0x00AFE960
// PDB : w:\tech5\tungsten\game\ai\gamestate\aiworldstate.cpp
// ========================================================================

void _unwind_490557()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 208 + 104));
}


// ========================================================================
// ?UpdateSprings@idAIWorldState@@AAAXABUtrackingParms_t@@@Z
// EA  : 0x82AFE990
// RVA : 0x00AFE990
// PDB : w:\tech5\tungsten\game\ai\gamestate\aiworldstate.cpp
// ========================================================================

void __fastcall idAIWorldState::UpdateSprings(idAIWorldState *this, const trackingParms_t *trackingParms)
{
  unsigned __int64 v4; // r6
  const char *v5; // r7
  int i; // r30
  idPLog *pLog; // r29
  idPLog::logEntry_t *v8; // r30
  int v9; // r3
  __int64 totalTicks; // r11
  __int64 v11; // r9
  idPLogScope v12; // [sp+50h] [-40h] BYREF

  RD_EventBegin(name: "idAIWorldState::UpdateSprings");
  LODWORD(v4) = "idAIWorldState::UpdateSprings";
  HIDWORD(v4) = 6;
  idPLogScope::idPLogScope(this: &v12, pl: &::pLog, gMask: v4, label: v5);
  for ( i = 0; i < this->numEnts; ++i )
    idAIEntityState::UpdateSprings(this: &this->entityStates[this->ents[i].value], trackingParms);
  if ( v12.logIndex >= 0 )
  {
    pLog = v12.pLog;
    v8 = &v12.pLog->logEntries.list[v12.logIndex];
    v9 = (unsigned __int64)Sys_GetClockTicks() >> 32;
    totalTicks = v8->totalTicks;
    HIDWORD(totalTicks) = v8->parent;
    LODWORD(v11) = v9 - totalTicks;
    v8->totalTicks = v11;
    pLog->lastEntry = HIDWORD(totalTicks);
  }
  RD_EventEnd();
}


// ========================================================================
// __unwind$490648
// EA  : 0x82AFEA60
// RVA : 0x00AFEA60
// PDB : w:\tech5\tungsten\game\ai\gamestate\aiworldstate.cpp
// ========================================================================

void _unwind_490648()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 144 + 88));
}


// ========================================================================
// __unwind$490649
// EA  : 0x82AFEA88
// RVA : 0x00AFEA88
// PDB : w:\tech5\tungsten\game\ai\gamestate\aiworldstate.cpp
// ========================================================================

void _unwind_490649()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 144 + 80));
}


// ========================================================================
// ?ResolveDeferredQueries@idAIWorldState@@QAAXPBVidAIGameState@@ABVidAILogic@@@Z
// EA  : 0x82AFEB48
// RVA : 0x00AFEB48
// PDB : w:\tech5\tungsten\game\ai\gamestate\aiworldstate.cpp
// ========================================================================

void __fastcall idAIWorldState::ResolveDeferredQueries(
        idAIWorldState *this,
        idAIGameState *gameState,
        idAILogic *aiOwner)
{
  unsigned __int64 v6; // r6
  const char *v7; // r7
  int v8; // r27
  int v9; // r30
  const aiLatchedState_t *StateForEntityNum; // r3
  idAIEntityState *v11; // r3
  unsigned __int64 v12; // r6
  const char *v13; // r7
  int v14; // r17
  int v15; // r20
  idAIEntityState::aiDefVisInfo_t *v16; // r30
  const aiLatchedState_t *v17; // r3
  int v18; // r26
  int v19; // r3
  int v20; // r27
  double v21; // fp7
  double v23; // fp5
  double v25; // fp3
  double v26; // fp8
  double v27; // fp5
  __int64 v28; // r6
  __int64 v29; // r8
  const idSpawnId **v30; // r25
  double StimulusForVisibility; // fp30
  idAIWorldState *v32; // r3
  int v33; // r10
  int lastConfirmedStimTime; // r9
  visibleType_t v35; // r6
  const aiLatchedState_t *v36; // r5
  idAIEntityState *v37; // r3
  double v38; // fp4
  aiSenseState_t *v39; // r3
  const aiPhysicalState_t *ConfirmedPhysicalSafe; // r3
  double v41; // fp10
  double v42; // fp6
  double v44; // fp7
  double v46; // fp5
  double v47; // fp13
  double v48; // fp8
  double v49; // fp1
  int v50; // r27
  double v51; // fp30
  const idSpawnId *v52; // r8
  idVehicle *v53; // r3
  idVehicle *v54; // r3
  idVehicle *v55; // r30
  idPlayer *Driver; // r3
  idEntity *v57; // r3
  const aiLatchedState_t *v58; // r26
  aiStimulus_t v59; // r15
  const idEntity *v60; // r3
  const idEntityPtr<idAI2> *SpawnId; // r3
  const idSpawnId *v62; // r8
  idRobot *v63; // r3
  idRobot *v64; // r3
  idRobot *v65; // r30
  idEntity *v66; // r3
  const aiLatchedState_t *v67; // r26
  aiStimulus_t v68; // r27
  const idEntity *v69; // r3
  const idEntityPtr<idAI2> *v70; // r3
  const idSpawnId *v71; // r8
  idPLog *pLog; // r29
  idPLog::logEntry_t *v73; // r30
  int v74; // r3
  __int64 totalTicks; // r11
  __int64 v76; // r9
  int v77; // [sp+8h] [-148h]
  int v78; // [sp+8h] [-148h]
  int v79; // [sp+Ch] [-144h]
  int v80; // [sp+Ch] [-144h]
  int v81; // [sp+10h] [-140h]
  int v82; // [sp+10h] [-140h]
  int v83; // [sp+14h] [-13Ch]
  int v84; // [sp+14h] [-13Ch]
  int v85; // [sp+18h] [-138h]
  int v86; // [sp+18h] [-138h]
  int v87; // [sp+1Ch] [-134h]
  int v88; // [sp+1Ch] [-134h]
  int v89; // [sp+20h] [-130h]
  int v90; // [sp+20h] [-130h]
  int v91; // [sp+24h] [-12Ch]
  int v92; // [sp+24h] [-12Ch]
  int v93; // [sp+28h] [-128h]
  int v94; // [sp+28h] [-128h]
  int v95; // [sp+2Ch] [-124h]
  int v96; // [sp+2Ch] [-124h]
  int v97; // [sp+30h] [-120h]
  int v98; // [sp+30h] [-120h]
  int v99; // [sp+34h] [-11Ch]
  int v100; // [sp+34h] [-11Ch]
  int v101; // [sp+38h] [-118h]
  int v102; // [sp+38h] [-118h]
  int v103; // [sp+3Ch] [-114h]
  int v104; // [sp+3Ch] [-114h]
  int v105; // [sp+40h] [-110h]
  int v106; // [sp+40h] [-110h]
  int v107; // [sp+44h] [-10Ch]
  int v108; // [sp+44h] [-10Ch]
  int v109; // [sp+48h] [-108h]
  int v110; // [sp+48h] [-108h]
  idHandle<int,enum invalidAIEvent_t,-1> *v111; // [sp+4Ch] [-104h]
  idHandle<int,enum invalidAIEvent_t,-1> *v112; // [sp+4Ch] [-104h]
  int v113; // [sp+50h] [-100h]
  int v114; // [sp+50h] [-100h]
  _DWORD v115[2]; // [sp+60h] [-F0h] BYREF
  int v116; // [sp+68h] [-E8h] BYREF
  int v117; // [sp+6Ch] [-E4h] BYREF
  idPLogScope v118[10]; // [sp+70h] [-E0h] BYREF

  if ( idAILogic::GetState(this: aiOwner) != nullptr
    && this->lastUpdateFrameNum == gameLocal->GetGameFrame(this: gameLocal) - 1 )
  {
    if ( this->aiDeferredRefreshInfo.num != 0 )
    {
      RD_EventBegin(name: "idAIWorldState::Update - Resolving refreshed Queries");
      LODWORD(v6) = "idAIWorldState::Update - Resolving refreshed Queries";
      HIDWORD(v6) = 6;
      idPLogScope::idPLogScope(this: v118, pl: &::pLog, gMask: v6, label: v7);
      v8 = 0;
      if ( this->aiDeferredRefreshInfo.num > 0 )
      {
        v9 = 0;
        do
        {
          StateForEntityNum = idAIGameState::GetStateForEntityNum(
                                this: gameState,
                                num: this->aiDeferredRefreshInfo.list[v9].entityNum);
          if ( StateForEntityNum != nullptr )
          {
            v11 = idAIWorldState::StateForSpawnId(this, entId: &StateForEntityNum->spawnId);
            if ( v11 != nullptr )
              idAIEntityState::Refresh_Resolve(
                this: v11,
                gameState,
                worldState: (idTypesafeNumber<int,enum gameTimeUnique_t> *)this,
                owner: aiOwner,
                defVisInfo: &this->aiDeferredRefreshInfo.list[v9]);
          }
          ++v8;
          ++v9;
        }
        while ( v8 < this->aiDeferredRefreshInfo.num );
      }
      idList<idAIEntityState::aiDefVisInfo_t,5>::SetNum(this: &this->aiDeferredRefreshInfo, newNum: 0);
      idPLogScope::~idPLogScope(this: v118);
      RD_EventEnd();
    }
    if ( this->aiDeferredVisInfo.num != 0 )
    {
      RD_EventBegin(name: "idAIWorldState::Update - Resolve Deferred Queries");
      LODWORD(v12) = "idAIWorldState::Update - Resolve Deferred Queries";
      HIDWORD(v12) = 6;
      idPLogScope::idPLogScope(this: v118, pl: &::pLog, gMask: v12, label: v13);
      idAIWorldState::GetCurrentRefreshInterval(
        this: (idAIWorldState *)v115,
        result: (idTypesafeNumber<int,enum gameTimeUnique_t> *)this);
      v14 = 0;
      if ( this->aiDeferredVisInfo.num > 0 )
      {
        v15 = 0;
        do
        {
          v16 = &this->aiDeferredVisInfo.list[v15];
          v17 = idAIGameState::GetStateForEntityNum(this: gameState, num: v16->entityNum);
          v18 = (int)v17;
          if ( v17 != nullptr )
          {
            if ( v16->fovWeight <= 0.0 && !v16->closeEnough && ai_visTraceOutsideFOV.valueInteger == 0 )
              goto LABEL_20;
            v19 = idAIEntityState::AICanSee_Resolve(owner: aiOwner, defVisInfo: v16, tols: v17);
            v20 = v19;
            if ( v19 == 5 )
              goto LABEL_33;
            if ( v19 != 1 )
            {
              if ( v19 > 2 )
                goto LABEL_23;
            }
            else
            {
LABEL_20:
              if ( v16->closeEnough )
              {
                v20 = 4;
                v21 = (float)((float)(v16->delta.z * v16->delta.z)
                            + (float)((float)(v16->delta.x * v16->delta.x) + (float)(v16->delta.y * v16->delta.y)));
                _FP6 = (float)((float)((float)(v16->delta.z * v16->delta.z)
                                     + (float)((float)(v16->delta.x * v16->delta.x)
                                             + (float)(v16->delta.y * v16->delta.y)))
                             - idMath::FLT_SMALLEST_NON_DENORMAL);
                v23 = (float)((float)((float)(v16->delta.z * v16->delta.z)
                                    + (float)((float)(v16->delta.x * v16->delta.x) + (float)(v16->delta.y * v16->delta.y)))
                            * (float)0.5);
                __asm { fsel      f4, f6, f7, f0 }
                v25 = __frsqrte(_FP4);
                v26 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v25 * (float)((float)((float)(v16->delta.z * v16->delta.z) + (float)((float)(v16->delta.x * v16->delta.x) + (float)(v16->delta.y * v16->delta.y))) * (float)0.5))
                                                                                            * (float)v25)
                                                                                    - (float)1.5)
                                                                    * (float)v25)
                                                            * (float)((float)((float)(v16->delta.z * v16->delta.z)
                                                                            + (float)((float)(v16->delta.x * v16->delta.x)
                                                                                    + (float)(v16->delta.y * v16->delta.y)))
                                                                    * (float)0.5))
                                                    * (float)((float)-(float)((float)((float)((float)v25
                                                                                            * (float)((float)((float)(v16->delta.z * v16->delta.z) + (float)((float)(v16->delta.x * v16->delta.x) + (float)(v16->delta.y * v16->delta.y))) * (float)0.5))
                                                                                    * (float)v25)
                                                                            - (float)1.5)
                                                            * (float)v25))
                                            - (float)1.5)
                            * (float)((float)-(float)((float)((float)((float)v25
                                                                    * (float)((float)((float)(v16->delta.z * v16->delta.z)
                                                                                    + (float)((float)(v16->delta.x * v16->delta.x)
                                                                                            + (float)(v16->delta.y * v16->delta.y)))
                                                                            * (float)0.5))
                                                            * (float)v25)
                                                    - (float)1.5)
                                    * (float)v25));
                v27 = (float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v25 * (float)((float)((float)(v16->delta.z * v16->delta.z) + (float)((float)(v16->delta.x * v16->delta.x) + (float)(v16->delta.y * v16->delta.y))) * (float)0.5)) * (float)v25) - (float)1.5) * (float)v25)
                                                                                            * (float)((float)((float)(v16->delta.z * v16->delta.z) + (float)((float)(v16->delta.x * v16->delta.x) + (float)(v16->delta.y * v16->delta.y))) * (float)0.5))
                                                                                    * (float)((float)-(float)((float)((float)((float)v25 * (float)((float)((float)(v16->delta.z * v16->delta.z) + (float)((float)(v16->delta.x * v16->delta.x) + (float)(v16->delta.y * v16->delta.y))) * (float)0.5)) * (float)v25) - (float)1.5)
                                                                                            * (float)v25))
                                                                            - (float)1.5)
                                                            * (float)((float)-(float)((float)((float)((float)v25 * (float)((float)((float)(v16->delta.z * v16->delta.z) + (float)((float)(v16->delta.x * v16->delta.x) + (float)(v16->delta.y * v16->delta.y))) * (float)0.5))
                                                                                            * (float)v25)
                                                                                    - (float)1.5)
                                                                    * (float)v25))
                                                    * (float)v23)
                                            * (float)v26)
                                    - (float)1.5);
                v16->fovWeight = (float)((float)-(float)((float)((float)((float)((float)v27
                                                                               * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v25 * (float)((float)((float)(v16->delta.z * v16->delta.z) + (float)((float)(v16->delta.x * v16->delta.x) + (float)(v16->delta.y * v16->delta.y))) * (float)0.5)) * (float)v25) - (float)1.5) * (float)v25) * (float)((float)((float)(v16->delta.z * v16->delta.z) + (float)((float)(v16->delta.x * v16->delta.x) + (float)(v16->delta.y * v16->delta.y))) * (float)0.5)) * (float)((float)-(float)((float)((float)((float)v25 * (float)((float)((float)(v16->delta.z * v16->delta.z) + (float)((float)(v16->delta.x * v16->delta.x) + (float)(v16->delta.y * v16->delta.y))) * (float)0.5)) * (float)v25) - (float)1.5) * (float)v25)) - (float)1.5)
                                                                                       * (float)((float)-(float)((float)((float)((float)v25 * (float)((float)((float)(v16->delta.z * v16->delta.z) + (float)((float)(v16->delta.x * v16->delta.x) + (float)(v16->delta.y * v16->delta.y))) * (float)0.5)) * (float)v25) - (float)1.5)
                                                                                               * (float)v25)))
                                                                       * (float)v21)
                                                               * idAIWorldState::AI_CLOSE_ENOUGH_FOR_VIS_SCALE)
                                                       - (float)1.0)
                                       * 0.69999999)
                               - (float)0.30000001;
LABEL_23:
                HIDWORD(v28) = idAIWorldState::GetCurrentRefreshInterval(
                                 this: (idAIWorldState *)v115,
                                 result: (idTypesafeNumber<int,enum gameTimeUnique_t> *)this);
                v30 = (const idSpawnId **)(v18 + 88);
                StimulusForVisibility = idAIWorldState::GetStimulusForVisibility(this, vis: v20, interval: v28, a4: v29);
                v37 = idAIWorldState::StateForSpawnId(this: v32, entId: (const idSpawnId *)(v18 + 88));
                if ( v37 != nullptr )
                {
                  v33 = *((_BYTE *)v37 + 541) & 0x80;
                  if ( (*((_BYTE *)v37 + 541) & 0x80) != 0 )
                  {
                    v33 = 4 * (v37->lastSense + 128);
                    v39 = *(aiSenseState_t **)((char *)&v37->__vftable + v33);
                    lastConfirmedStimTime = v39->lastConfirmedStimTime;
                    v115[1] = v39;
                    if ( lastConfirmedStimTime >= 0 )
                    {
                      v115[1] = v39;
                      ConfirmedPhysicalSafe = aiSenseState_t::GetConfirmedPhysicalSafe(this: v39);
                      v41 = (float)(ConfirmedPhysicalSafe->origin.y - *(float *)(v18 + 4));
                      v42 = (float)(ConfirmedPhysicalSafe->origin.z - *(float *)(v18 + 8));
                      v38 = __fsqrts((float)((float)((float)v42 * (float)v42)
                                           + (float)((float)((float)(ConfirmedPhysicalSafe->origin.x - *(float *)v18)
                                                           * (float)(ConfirmedPhysicalSafe->origin.x - *(float *)v18))
                                                   + (float)((float)v41 * (float)v41))));
                    }
                  }
                }
                _FP8 = (float)((float)((float)(v16->delta.x * v16->delta.x)
                                     + (float)((float)(v16->delta.y * v16->delta.y)
                                             + (float)(v16->delta.z * v16->delta.z)))
                             - idMath::FLT_SMALLEST_NON_DENORMAL);
                v44 = (float)((float)((float)(v16->delta.x * v16->delta.x)
                                    + (float)((float)(v16->delta.y * v16->delta.y) + (float)(v16->delta.z * v16->delta.z)))
                            * (float)0.5);
                __asm { fsel      f6, f8, f9, f0 }
                v46 = __frsqrte(_FP6);
                v47 = (float)-(float)((float)((float)((float)v46
                                                    * (float)((float)((float)(v16->delta.x * v16->delta.x)
                                                                    + (float)((float)(v16->delta.y * v16->delta.y)
                                                                            + (float)(v16->delta.z * v16->delta.z)))
                                                            * (float)0.5))
                                            * (float)v46)
                                    - (float)1.5);
                v48 = (float)((float)-(float)((float)((float)((float)((float)v47 * (float)v46)
                                                            * (float)((float)((float)(v16->delta.x * v16->delta.x)
                                                                            + (float)((float)(v16->delta.y * v16->delta.y)
                                                                                    + (float)(v16->delta.z * v16->delta.z)))
                                                                    * (float)0.5))
                                                    * (float)((float)v47 * (float)v46))
                                            - (float)1.5)
                            * (float)((float)v47 * (float)v46));
                v49 = idAIWorldState::VisibilityEffects(
                        this,
                        owner: aiOwner,
                        input: StimulusForVisibility,
                        fovWeight: v16->fovWeight,
                        ls: v36,
                        vis: v35,
                        distance: (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)v47 * (float)v46) * (float)v44) * (float)((float)v47 * (float)v46))
                                                                                              - (float)1.5)
                                                                              * (float)((float)v47 * (float)v46))
                                                                      * (float)v44)
                                                              * (float)v48)
                                                      - (float)1.5)
                                      * (float)v48)
                              * (float)((float)(v16->delta.x * v16->delta.x)
                                      + (float)((float)(v16->delta.y * v16->delta.y)
                                              + (float)(v16->delta.z * v16->delta.z)))),
                        displacement: v38,
                        isRelaxed: v18,
                        a10: v20,
                        a11: lastConfirmedStimTime,
                        a12: v33,
                        a13: v77,
                        a14: v79,
                        a15: v81,
                        a16: v83,
                        a17: v85,
                        a18: v87,
                        a19: v89,
                        a20: v91,
                        a21: v93,
                        a22: v95,
                        a23: v97,
                        a24: v99,
                        a25: v101,
                        a26: v103,
                        a27: v105,
                        a28: v107,
                        a29: v109,
                        a30: (int)v111,
                        a31: v113,
                        a32: aiOwner->isRelaxed);
                v50 = v20;
                v51 = v49;
                idAIWorldState::InternalAddEntityState(
                  this,
                  gameState,
                  owner: (const idEntityPtr<idAI2> *)aiOwner,
                  entId: (const idEntityPtr<idAI2> *)(v18 + 88),
                  stimulusType: idAIWorldState::STIMULUS_TYPE_FOR_VIS[v50],
                  stimulusAmount: v49,
                  sourceId: v52,
                  sourceEventHandle: (const idEntityPtr<idAI2> *)aiOwner,
                  ls: (const aiLatchedState_t *)0xFFFFFFFF,
                  a10: v78,
                  a11: v80,
                  a12: v82,
                  a13: v84,
                  a14: v86,
                  a15: v88,
                  a16: v90,
                  a17: v92,
                  a18: v94,
                  a19: v96,
                  a20: v98,
                  a21: v100,
                  a22: v102,
                  a23: v104,
                  a24: v106,
                  a25: v108,
                  a26: v110,
                  a27: v112,
                  a28: v114,
                  a29: (const aiLatchedState_t *)v18);
                v53 = (idVehicle *)gameLocal->GetEntityForSpawnId(this: gameLocal, a2: *v30);
                v54 = idVehicle::CastTo(c: v53);
                v55 = v54;
                if ( v54 != nullptr )
                {
                  Driver = (idPlayer *)idVehicle::GetDriver(this: v54);
                  if ( idPlayer::CastTo(c: Driver) != nullptr )
                  {
                    v57 = idVehicle::GetDriver(this: v55);
                    v58 = idAIGameState::GetStateForEntityNum(this: gameState, num: v57->entityNumber);
                    v59 = idAIWorldState::STIMULUS_TYPE_FOR_VIS[v50];
                    v60 = idVehicle::GetDriver(this: v55);
                    SpawnId = (const idEntityPtr<idAI2> *)idGameLocal::GetSpawnId(
                                                            this: (idGameLocal *)&v116,
                                                            result: (idSpawnId *)gameLocal,
                                                            ent: v60);
                    idAIWorldState::InternalAddEntityState(
                      this,
                      gameState,
                      owner: (const idEntityPtr<idAI2> *)aiOwner,
                      entId: SpawnId,
                      stimulusType: v59,
                      stimulusAmount: v51,
                      sourceId: v62,
                      sourceEventHandle: (const idEntityPtr<idAI2> *)aiOwner,
                      ls: (const aiLatchedState_t *)0xFFFFFFFF,
                      a10: v77,
                      a11: v79,
                      a12: v81,
                      a13: v83,
                      a14: v85,
                      a15: v87,
                      a16: v89,
                      a17: v91,
                      a18: v93,
                      a19: v95,
                      a20: v97,
                      a21: v99,
                      a22: v101,
                      a23: v103,
                      a24: v105,
                      a25: v107,
                      a26: v109,
                      a27: v111,
                      a28: v113,
                      a29: v58);
                  }
                }
                v63 = (idRobot *)gameLocal->GetEntityForSpawnId(this: gameLocal, a2: *v30);
                v64 = idRobot::CastTo(c: v63);
                v65 = v64;
                if ( v64 != nullptr && idRobot::HasSeatTypeOccupant(this: v64, type: COCKPITSEAT_PILOT) )
                {
                  v66 = idRobot::GetDriver(this: v65);
                  v67 = idAIGameState::GetStateForEntityNum(this: gameState, num: v66->entityNumber);
                  v68 = idAIWorldState::STIMULUS_TYPE_FOR_VIS[v50];
                  v69 = idRobot::GetDriver(this: v65);
                  v70 = (const idEntityPtr<idAI2> *)idGameLocal::GetSpawnId(
                                                      this: (idGameLocal *)&v117,
                                                      result: (idSpawnId *)gameLocal,
                                                      ent: v69);
                  idAIWorldState::InternalAddEntityState(
                    this,
                    gameState,
                    owner: (const idEntityPtr<idAI2> *)aiOwner,
                    entId: v70,
                    stimulusType: v68,
                    stimulusAmount: v51,
                    sourceId: v71,
                    sourceEventHandle: (const idEntityPtr<idAI2> *)aiOwner,
                    ls: (const aiLatchedState_t *)0xFFFFFFFF,
                    a10: v77,
                    a11: v79,
                    a12: v81,
                    a13: v83,
                    a14: v85,
                    a15: v87,
                    a16: v89,
                    a17: v91,
                    a18: v93,
                    a19: v95,
                    a20: v97,
                    a21: v99,
                    a22: v101,
                    a23: v103,
                    a24: v105,
                    a25: v107,
                    a26: v109,
                    a27: v111,
                    a28: v113,
                    a29: v67);
                }
              }
            }
          }
LABEL_33:
          ++v14;
          ++v15;
        }
        while ( v14 < this->aiDeferredVisInfo.num );
      }
      if ( this->aiDeferredVisInfo.size < 0 )
        idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->aiDeferredVisInfo);
      this->aiDeferredVisInfo.num = __CFADD__(-this->aiDeferredVisInfo.size, this->aiDeferredVisInfo.size ^ 0x80000000)
                                  ? 0
                                  : this->aiDeferredVisInfo.size;
      if ( v118[0].logIndex >= 0 )
      {
        pLog = v118[0].pLog;
        v73 = &v118[0].pLog->logEntries.list[v118[0].logIndex];
        v74 = (unsigned __int64)Sys_GetClockTicks() >> 32;
        totalTicks = v73->totalTicks;
        HIDWORD(totalTicks) = v73->parent;
        LODWORD(v76) = v74 - totalTicks;
        v73->totalTicks = v76;
        pLog->lastEntry = HIDWORD(totalTicks);
      }
      RD_EventEnd();
    }
  }
  else
  {
    idList<idAIEntityState::aiDefVisInfo_t,5>::SetNum(this: &this->aiDeferredRefreshInfo, newNum: 0);
    idList<idAIEntityState::aiDefVisInfo_t,5>::SetNum(this: &this->aiDeferredVisInfo, newNum: 0);
  }
}


// ========================================================================
// __unwind$490709
// EA  : 0x82AFF128
// RVA : 0x00AFF128
// PDB : w:\tech5\tungsten\game\ai\gamestate\aiworldstate.cpp
// ========================================================================

void _unwind_490709()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 336 + 120));
}


// ========================================================================
// __unwind$490710
// EA  : 0x82AFF150
// RVA : 0x00AFF150
// PDB : w:\tech5\tungsten\game\ai\gamestate\aiworldstate.cpp
// ========================================================================

void _unwind_490710()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 336 + 112));
}


// ========================================================================
// __unwind$490711
// EA  : 0x82AFF178
// RVA : 0x00AFF178
// PDB : w:\tech5\tungsten\game\ai\gamestate\aiworldstate.cpp
// ========================================================================

void _unwind_490711()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 336 + 121));
}


// ========================================================================
// __unwind$490712
// EA  : 0x82AFF1A0
// RVA : 0x00AFF1A0
// PDB : w:\tech5\tungsten\game\ai\gamestate\aiworldstate.cpp
// ========================================================================

void _unwind_490712()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 336 + 112));
}


// ========================================================================
// ?AllocQuery@@YAAAUaiDefVisInfo_t@idAIEntityState@@AAV?$idList@UaiDefVisInfo_t@idAIEntityState@@$04@@@Z
// EA  : 0x82AFF1C8
// RVA : 0x00AFF1C8
// PDB : w:\tech5\tungsten\game\ai\gamestate\aiworldstate.cpp
// ========================================================================

idAIEntityState::aiDefVisInfo_t *__fastcall AllocQuery(idList<idAIEntityState::aiDefVisInfo_t,5> *queryList)
{
  idAIEntityState::aiDefVisInfo_t *result; // r3
  unsigned __int64 v2; // r11

  result = idList<idAIEntityState::aiDefVisInfo_t,5>::Alloc(this: queryList);
  HIDWORD(v2) = 0x82000000;
  LODWORD(v2) = 0;
  result->eyeQuery.index = v2;
  result->boundsQuery.index = v2;
  result->lastSeenPosQuery.index = v2;
  result->delta.x = 0.0;
  result->delta.y = 0.0;
  result->delta.z = 0.0;
  result->entityNum = -1;
  result->fovWeight = 0.0;
  result->closeEnough = false;
  return result;
}


// ========================================================================
// ?UpdateInternal@idAIWorldState@@AAAXPBVidAIGameState@@ABVidAILogic@@ABUtrackingParms_t@@PBUaiLatchedState_t@@@Z
// EA  : 0x82AFF228
// RVA : 0x00AFF228
// PDB : w:\tech5\tungsten\game\ai\gamestate\aiworldstate.cpp
// ========================================================================

void __fastcall idAIWorldState::UpdateInternal(
        idAIWorldState *this,
        idAIGameState *gameState,
        idAILogic *aiOwner,
        const trackingParms_t *trackingParms,
        const aiLatchedState_t *os)
{
  idAIGameState *v6; // r17
  const aiLatchedState_t *v8; // r19
  unsigned __int64 v9; // r6
  idPLog *v10; // r25
  const char *v11; // r7
  unsigned __int64 v12; // r6
  const char *v13; // r7
  int v14; // r3
  int initialUpdateCount; // r11
  bool v16; // r26
  bool v17; // r14
  bool v18; // r15
  unsigned __int64 v19; // r6
  const char *v20; // r7
  int v21; // r30
  double radius; // fp0
  double x; // fp12
  double y; // fp11
  double z; // fp9
  double v26; // fp8
  double v27; // fp7
  unsigned __int64 v28; // r6
  const char *v29; // r7
  __int16 EntityNumber; // r3
  unsigned __int64 v31; // r6
  const char *v32; // r7
  signed int num; // r30
  unsigned int v34; // r11
  unsigned int v35; // r10
  unsigned int v36; // r9
  char v37; // r8
  char v38; // r7
  char v39; // r6
  int v40; // r3
  int value; // r7
  idEntityPtr<idEntity> *list; // r8
  int v43; // r9
  int v44; // r11
  idGameTimeManager *p_gameTimeManager; // r3
  unsigned int v46; // r10
  int v47; // r9
  int v48; // r3
  int v49; // r3
  unsigned __int64 v50; // r6
  const char *v51; // r7
  double v52; // fp24
  unsigned __int64 index; // r10
  int GatheredEntities; // r29
  char v55; // r11
  unsigned __int64 v56; // r6
  const char *v57; // r7
  bool v58; // r11
  idDeclFaction *v59; // r17
  const int *v60; // r23
  const aiLatchedState_t *StateForEntityNum; // r3
  const aiLatchedState_t *v62; // r26
  const idSpawnId *p_spawnId; // r30
  double v64; // fp30
  double v65; // fp29
  double v66; // fp28
  double v67; // fp25
  bool v68; // r27
  unsigned __int8 v69; // r3
  int v70; // r25
  double v71; // fp4
  double v72; // fp3
  idAIEntityState *v73; // r3
  aiSenseState_t *v74; // r30
  int v75; // r3
  char v76; // r11
  bool v77; // r30
  idAIEntityState::aiDefVisInfo_t *v78; // r3
  int v79; // r10
  unsigned __int64 v80; // r6
  const char *v81; // r7
  bool v82; // r11
  idDeclFaction *faction; // r21
  int v84; // r24
  idIndex<signed char,enum invalidEntityStateIndex_t> *ents; // r23
  int v86; // r11
  idAIEntityState *v87; // r25
  const aiLatchedState_t *State; // r3
  const aiLatchedState_t *v89; // r29
  bool v90; // r27
  char v91; // r26
  double v92; // fp31
  double v93; // fp30
  double v94; // fp29
  idAIEntityState::aiDefVisInfo_t *v95; // r30
  __int16 numEnts; // r11
  char v97; // r10
  int v98; // r9
  float v99[2]; // [sp+50h] [-590h] BYREF
  idPLogScope v100; // [sp+58h] [-588h] BYREF
  idPLogScope v101; // [sp+60h] [-580h] BYREF
  idPLog *v102; // [sp+68h] [-578h]
  idPLogScope v103; // [sp+70h] [-570h] BYREF
  idPLogScope v104; // [sp+78h] [-568h] BYREF
  idSpawnId v105; // [sp+80h] [-560h] BYREF
  float v106[4]; // [sp+90h] [-550h] BYREF
  idBounds v107; // [sp+A0h] [-540h] BYREF
  float v108[16]; // [sp+C0h] [-520h] BYREF
  int v109[274]; // [sp+100h] [-4E0h] BYREF

  v6 = gameState;
  v8 = os;
  RD_EventBegin(name: "idAIWorldState::UpdateInternal");
  LODWORD(v9) = "idAIWorldState::UpdateInternal";
  v10 = &pLog;
  HIDWORD(v9) = 6;
  v102 = &pLog;
  idPLogScope::idPLogScope(this: &v104, pl: &pLog, gMask: v9, label: v11);
  RD_EventBegin(name: "idAIWorldState::UpdateInternal -- resolve queries");
  LODWORD(v12) = "idAIWorldState::UpdateInternal -- resolve queries";
  HIDWORD(v12) = 6;
  idPLogScope::idPLogScope(this: &v100, pl: &pLog, gMask: v12, label: v13);
  idAIWorldState::ResolveDeferredQueries(this, gameState: v6, aiOwner);
  idPLogScope::~idPLogScope(this: &v100);
  RD_EventEnd();
  v14 = gameLocal->GetGameFrame(this: gameLocal);
  initialUpdateCount = this->initialUpdateCount;
  this->lastUpdateFrameNum = v14;
  if ( initialUpdateCount > 0 )
  {
    v16 = (_cntlzw(initialUpdateCount - 2) & 0x20) != 0;
    v17 = (_cntlzw(initialUpdateCount - 1) & 0x20) != 0;
    this->initialUpdateCount = initialUpdateCount - 1;
LABEL_3:
    v18 = false;
    goto LABEL_4;
  }
  num = gameLocal->aiWorldStateUsers.num;
  if ( num <= 0 )
  {
    idPLogScope::~idPLogScope(this: &v104);
    goto LABEL_15;
  }
  if ( num > 2 )
  {
    v40 = idAccolade::Count(this: &clientGame->gameTimeManager);
    value = aiOwner->spawnId.value;
    list = gameLocal->aiWorldStateUsers.list;
    v43 = __ROL4__(v40, 1);
    v44 = v40 % num;
    p_gameTimeManager = &clientGame->gameTimeManager;
    v46 = num & ~(v43 - 1);
    __twllei(num, 0);
    v47 = list[v44].spawnId.value;
    __twlgei(v46, 0xFFFFFFFF);
    v16 = (_cntlzw(value - v47) & 0x20) != 0;
    v48 = idAccolade::Count(this: p_gameTimeManager);
    __twllei(num, 0);
    __twlgei(num & ~(__ROL4__(v48 - 1, 1) - 1), 0xFFFFFFFF);
    v17 = (v48 - 1) % num >= 0
       && (_cntlzw(aiOwner->spawnId.value - gameLocal->aiWorldStateUsers.list[(v48 - 1) % num].spawnId.value) & 0x20) != 0;
    v49 = idAccolade::Count(this: &clientGame->gameTimeManager);
    __twllei(num, 0);
    __twlgei(num & ~(__ROL4__(v49 - 2, 1) - 1), 0xFFFFFFFF);
    if ( (v49 - 2) % num < 0 )
      goto LABEL_3;
    v18 = (_cntlzw(aiOwner->spawnId.value - gameLocal->aiWorldStateUsers.list[(v49 - 2) % num].spawnId.value) & 0x20) != 0;
  }
  else
  {
    v34 = idAccolade::Count(this: &clientGame->gameTimeManager) % 3;
    v35 = v34 - 1;
    v36 = v34 - 2;
    if ( gameLocal->aiWorldStateUsers.list->spawnId.value == aiOwner->spawnId.value )
    {
      v37 = _cntlzw(v34);
      v38 = _cntlzw(v35);
      v39 = _cntlzw(v36);
    }
    else
    {
      v37 = _cntlzw(v35);
      v38 = _cntlzw(v36);
      v39 = _cntlzw(v34);
    }
    v16 = (v37 & 0x20) != 0;
    v17 = (v38 & 0x20) != 0;
    v18 = (v39 & 0x20) != 0;
  }
LABEL_4:
  if ( v16 )
  {
    RD_EventBegin(name: "idAIWorldState::Update - gather");
    LODWORD(v19) = "idAIWorldState::Update - gather";
    HIDWORD(v19) = 6;
    idPLogScope::idPLogScope(this: &v101, pl: &pLog, gMask: v19, label: v20);
    this->lastUpdatePos.x = v8->physical.origin.x;
    this->lastUpdatePos.y = v8->physical.origin.y;
    LODWORD(v99[0]) = &this->lastUpdatePos;
    v21 = 99840;
    this->lastUpdatePos.z = v8->physical.origin.z;
    if ( aiOwner->isRelaxed || aiOwner->isSearching )
      v21 = 103936;
    radius = this->radius;
    if ( ai_perceptionRadiusOverride.valueFloat > 0.0 )
      radius = ai_perceptionRadiusOverride.valueFloat;
    x = v8->physical.origin.x;
    y = v8->physical.origin.y;
    z = v8->physical.origin.z;
    v26 = (float)(v8->physical.origin.y + (float)radius);
    v27 = (float)(v8->physical.origin.z + (float)radius);
    v107.b[1].x = v8->physical.origin.x + (float)radius;
    v107.b[1].y = v26;
    v107.b[1].z = v27;
    v107.b[0].x = (float)-radius + (float)x;
    v107.b[0].y = (float)y + (float)-radius;
    v107.b[0].z = (float)z + (float)-radius;
    RD_EventBegin(name: "idAIWorldState::Update - issue gather");
    LODWORD(v28) = "idAIWorldState::Update - issue gather";
    HIDWORD(v28) = 6;
    idPLogScope::idPLogScope(this: &v100, pl: &pLog, gMask: v28, label: v29);
    EntityNumber = idSpawnId::GetEntityNumber(this: &aiOwner->spawnId);
    this->gatherQuery.index = *(_QWORD *)&idClip::GatherTouchingBounds(
                                            this: (idClip *)&v103,
                                            result: (idGatherQuery *)&clientGame->clip,
                                            bounds: &v107,
                                            clipMask: v21,
                                            passEntityNumber: EntityNumber,
                                            userName: "w:\\tech5\\tungsten\\game\\ai\\gamestate\\AIWorldState.cpp(623) : GatherTouchingBounds")->world;
    idPLogScope::~idPLogScope(this: &v100);
    RD_EventEnd();
    idPLogScope::~idPLogScope(this: &v101);
    RD_EventEnd();
  }
  else if ( !v17 || com_production.valueInteger != 0 )
  {
    if ( v18 )
    {
      RD_EventBegin(name: "idAIWorldState::Update - refresh");
      LODWORD(v80) = "idAIWorldState::Update - refresh";
      HIDWORD(v80) = 6;
      idPLogScope::idPLogScope(this: &v103, pl: &pLog, gMask: v80, label: v81);
      v82 = aiOwner->senseUpdatesOnNonEnemies && (_cntlzw(this->refreshFriendly) & 0x20) != 0;
      this->refreshFriendly = v82;
      faction = idAILogic::GetState(this: aiOwner)->faction;
      v84 = this->numEnts - 1;
      if ( v84 >= 0 )
      {
        ents = this->ents;
        do
        {
          v86 = ents[v84].value;
          v87 = &this->entityStates[v86];
          if ( (idAIWorldState *)((char *)this + v86 * 576) == (idAIWorldState *)-24 )
            goto LABEL_86;
          v105.value = this->entityStates[v86].spawnId.value;
          State = idAIGameState::GetState(this: v6, spawnId: &v105);
          v89 = State;
          if ( State == nullptr )
            goto LABEL_86;
          idDeclFaction::GetAttitudeTowards(
            this: faction,
            otherFaction: State->faction,
            attitude: (idRelationship::attitude_t *)&v101);
          if ( (this->refreshFriendly || v101.logIndex <= 3) && (v89->physical.entFlags & 0x20) == 0 )
          {
            v90 = false;
            v91 = idAIEntityState::WithinFOV(owner: aiOwner, tols: v89, fovWeight: v99);
            v92 = (float)(v89->physical.origin.z - v8->physical.origin.z);
            v93 = (float)(v89->physical.origin.y - v8->physical.origin.y);
            v94 = (float)(v89->physical.origin.x - v8->physical.origin.x);
            if ( this->bOwnerAiInCover && v101.logIndex < 2 )
              v90 = (float)((float)((float)v92 * (float)v92)
                          + (float)((float)((float)(v89->physical.origin.x - v8->physical.origin.x)
                                          * (float)(v89->physical.origin.x - v8->physical.origin.x))
                                  + (float)((float)v93 * (float)v93))) <= (double)idAIWorldState::AI_CLOSE_ENOUGH_FOR_VIS_SQR;
            v95 = AllocQuery(queryList: &this->aiDeferredRefreshInfo);
            v100.logIndex = (int)&v95->delta;
            v95->fovWeight = v99[0];
            v95->delta.x = v94;
            v95->delta.y = v93;
            v95->delta.z = v92;
            v95->entityNum = idSpawnId::GetEntityNumber(this: &v89->spawnId);
            v95->closeEnough = v90;
            if ( v91 != 0 || v90 || ai_visTraceOutsideFOV.valueInteger != 0 )
              idAIEntityState::Refresh_Submit(
                this: v87,
                gameState: v6,
                worldState: this,
                owner: aiOwner,
                defVisInfo: v95);
          }
          if ( (*((_BYTE *)v87 + 541) & 0x80) == 0 )
          {
LABEL_86:
            numEnts = this->numEnts;
            if ( v84 < numEnts )
            {
              v97 = ents[v84].value;
              v98 = (__int16)(numEnts - 1);
              this->numEnts = v98;
              if ( v84 != v98 )
                ents[v84] = this->ents[v98];
              this->freeEnts[this->numFreeEnts++].value = v97;
            }
          }
          --v84;
        }
        while ( v84 >= 0 );
      }
      goto LABEL_14;
    }
  }
  else
  {
    RD_EventBegin(name: "idAIWorldState::Update - update entities");
    LODWORD(v50) = "idAIWorldState::Update - update entities";
    HIDWORD(v50) = 6;
    idPLogScope::idPLogScope(this: &v103, pl: &pLog, gMask: v50, label: v51);
    v52 = (float)(this->radius * this->radius);
    if ( ai_perceptionRadiusOverride.valueFloat > 0.0 )
      v52 = (float)(ai_perceptionRadiusOverride.valueFloat * ai_perceptionRadiusOverride.valueFloat);
    index = this->gatherQuery.index;
    GatheredEntities = 0;
    if ( (idClipModel *)index < *(idClipModel **)((char *)&clientGame->clip.temporaryClipModel + (HIDWORD(index) | 0x5A0))
      || (v55 = 1, (unsigned int)index > LODWORD(clientGame->clip.gatherQueryLastSubmittedIndex)) )
    {
      v55 = 0;
    }
    if ( v55 != 0 )
    {
      RD_EventBegin(name: "idAIWorldState::Update - resolve gather");
      LODWORD(v56) = "idAIWorldState::Update - resolve gather";
      HIDWORD(v56) = 6;
      idPLogScope::idPLogScope(this: &v100, pl: &pLog, gMask: v56, label: v57);
      GatheredEntities = idClip::GetGatheredEntities(
                           this: &clientGame->clip,
                           query: &this->gatherQuery,
                           entityList: v109,
                           maxCount: 256);
      idPLogScope::~idPLogScope(this: &v100);
      RD_EventEnd();
    }
    v58 = aiOwner->senseUpdatesOnNonEnemies && (_cntlzw(this->updateFriendly) & 0x20) != 0;
    this->updateFriendly = v58;
    v59 = idAILogic::GetState(this: aiOwner)->faction;
    if ( GatheredEntities > 0 )
    {
      v60 = v109;
      do
      {
        StateForEntityNum = idAIGameState::GetStateForEntityNum(this: gameState, num: *v60);
        v62 = StateForEntityNum;
        if ( StateForEntityNum != nullptr )
        {
          p_spawnId = &StateForEntityNum->spawnId;
          if ( StateForEntityNum->spawnId.value != aiOwner->spawnId.value
            && (StateForEntityNum->physical.entFlags & 0x20) == 0 )
          {
            idDeclFaction::GetAttitudeTowards(
              this: v59,
              otherFaction: StateForEntityNum->faction,
              attitude: (idRelationship::attitude_t *)&v101);
            if ( this->updateFriendly || v101.logIndex <= 3 )
            {
              v64 = (float)(v62->physical.origin.y - os->physical.origin.y);
              v65 = (float)(v62->physical.origin.x - os->physical.origin.x);
              v66 = (float)(v62->physical.origin.z - os->physical.origin.z);
              v67 = (float)((float)((float)v66 * (float)v66)
                          + (float)((float)((float)(v62->physical.origin.x - os->physical.origin.x)
                                          * (float)(v62->physical.origin.x - os->physical.origin.x))
                                  + (float)((float)v64 * (float)v64)));
              if ( v67 <= v52 )
              {
                v68 = false;
                v69 = idAIEntityState::WithinFOV(owner: aiOwner, tols: v62, fovWeight: v99);
                if ( this->bOwnerAiInCover && v101.logIndex < 2 )
                  v68 = v67 <= idAIWorldState::AI_CLOSE_ENOUGH_FOR_VIS_SQR;
                v70 = v69;
                if ( v69 != 0 || v68 )
                {
                  v73 = idAIWorldState::StateForSpawnId(this, entId: p_spawnId);
                  if ( v73 == nullptr
                    || (v74 = v73->senses.ptr[1])->lastUnconfirmedStimTime < 0
                    || (v100.logIndex = (int)v73->senses.ptr[1],
                        v75 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED),
                        v76 = 1,
                        v75 - v74->lastConfirmedStimTime >= 1000) )
                  {
                    v76 = 0;
                  }
                  v77 = v76;
                  v78 = AllocQuery(queryList: &this->aiDeferredVisInfo);
                  v78->delta.y = v64;
                  v78->delta.x = v65;
                  v78->delta.z = v66;
                  v100.logIndex = (int)&v78->delta;
                  v78->fovWeight = v99[0];
                  v79 = *v60;
                  v78->closeEnough = v68;
                  v78->entityNum = v79;
                  if ( v70 != 0 || v68 || ai_visTraceOutsideFOV.valueInteger != 0 )
                    idAIEntityState::AICanSee_Submit(
                      owner: aiOwner,
                      tols: v62,
                      seeThroughBreakables: v77,
                      defVisInfo: v78);
                }
                else if ( debugDeferredWorldState.valueInteger != 0 )
                {
                  v71 = os->physical.eyePos.y;
                  v72 = os->physical.eyePos.z;
                  v108[0] = os->physical.eyePos.x;
                  v100.logIndex = (int)&os->physical.eyePos;
                  v108[1] = v71;
                  v108[3] = 3.0;
                  v108[2] = v72;
                  v108[4] = 3.0;
                  v108[5] = 3.0;
                  v108[6] = mat3_identity.mat[0].x;
                  v108[7] = mat3_identity.mat[0].y;
                  v108[8] = mat3_identity.mat[0].z;
                  v108[9] = mat3_identity.mat[1].x;
                  v108[10] = mat3_identity.mat[1].y;
                  v108[11] = mat3_identity.mat[1].z;
                  v108[12] = mat3_identity.mat[2].x;
                  v108[13] = mat3_identity.mat[2].y;
                  v108[14] = mat3_identity.mat[2].z;
                  v106[0] = 0.0;
                  v106[1] = 0.0;
                  v106[2] = 1.0;
                  v106[3] = 1.0;
                  clientGame->renderWorld->DebugBox(
                    this: clientGame->renderWorld,
                    a2: (const idVec4 *)v106,
                    a3: (const idBox *)v108,
                    a4: 1500,
                    a5: false);
                }
                v10 = v102;
              }
            }
          }
        }
        --GatheredEntities;
        ++v60;
      }
      while ( GatheredEntities != 0 );
      v8 = os;
    }
    idPLogScope::~idPLogScope(this: &v103);
    RD_EventEnd();
    v6 = gameState;
  }
  RD_EventBegin(name: "idAIWorldState::UpdateInternal - UpdateSeen");
  LODWORD(v31) = "idAIWorldState::UpdateInternal - UpdateSeen";
  HIDWORD(v31) = 6;
  idPLogScope::idPLogScope(this: &v103, pl: v10, gMask: v31, label: v32);
  if ( !v17 && !v18 )
    idAIWorldState::UpdateSeen(this, gameState: v6, aiOwner, trackingParms, os: v8);
LABEL_14:
  idPLogScope::~idPLogScope(this: &v103);
  RD_EventEnd();
  idPLogScope::~idPLogScope(this: &v104);
LABEL_15:
  RD_EventEnd();
}


// ========================================================================
// $M491585
// EA  : 0x82AFFD2C
// RVA : 0x00AFFD2C
// PDB : w:\tech5\tungsten\game\ai\gamestate\aiworldstate.cpp
// ========================================================================

void _M491585()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 1504 + 1280));
}


// ========================================================================
// __unwind$491114_0
// EA  : 0x82AFFD54
// RVA : 0x00AFFD54
// PDB : w:\tech5\tungsten\game\ai\gamestate\aiworldstate.cpp
// ========================================================================

void _unwind_491114_0()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 1504 + 120));
}


// ========================================================================
// __unwind$491115_0
// EA  : 0x82AFFD7C
// RVA : 0x00AFFD7C
// PDB : w:\tech5\tungsten\game\ai\gamestate\aiworldstate.cpp
// ========================================================================

void _unwind_491115_0()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 1504 + 1281));
}


// ========================================================================
// __unwind$491116_0
// EA  : 0x82AFFDA4
// RVA : 0x00AFFDA4
// PDB : w:\tech5\tungsten\game\ai\gamestate\aiworldstate.cpp
// ========================================================================

void _unwind_491116_0()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 1504 + 88));
}


// ========================================================================
// __unwind$491117_0
// EA  : 0x82AFFDCC
// RVA : 0x00AFFDCC
// PDB : w:\tech5\tungsten\game\ai\gamestate\aiworldstate.cpp
// ========================================================================

void _unwind_491117_0()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 1504 + 1282));
}


// ========================================================================
// __unwind$491118_0
// EA  : 0x82AFFDF4
// RVA : 0x00AFFDF4
// PDB : w:\tech5\tungsten\game\ai\gamestate\aiworldstate.cpp
// ========================================================================

void _unwind_491118_0()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 1504 + 96));
}


// ========================================================================
// __unwind$491119_0
// EA  : 0x82AFFE1C
// RVA : 0x00AFFE1C
// PDB : w:\tech5\tungsten\game\ai\gamestate\aiworldstate.cpp
// ========================================================================

void _unwind_491119_0()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 1504 + 1283));
}


// ========================================================================
// __unwind$491120_0
// EA  : 0x82AFFE44
// RVA : 0x00AFFE44
// PDB : w:\tech5\tungsten\game\ai\gamestate\aiworldstate.cpp
// ========================================================================

void _unwind_491120_0()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 1504 + 88));
}


// ========================================================================
// __unwind$491127_0
// EA  : 0x82AFFE6C
// RVA : 0x00AFFE6C
// PDB : w:\tech5\tungsten\game\ai\gamestate\aiworldstate.cpp
// ========================================================================

void _unwind_491127_0()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 1504 + 1287));
}


// ========================================================================
// __unwind$491128_0
// EA  : 0x82AFFE94
// RVA : 0x00AFFE94
// PDB : w:\tech5\tungsten\game\ai\gamestate\aiworldstate.cpp
// ========================================================================

void _unwind_491128_0()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 1504 + 112));
}


// ========================================================================
// __unwind$491121_0
// EA  : 0x82AFFEBC
// RVA : 0x00AFFEBC
// PDB : w:\tech5\tungsten\game\ai\gamestate\aiworldstate.cpp
// ========================================================================

void _unwind_491121_0()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 1504 + 1284));
}


// ========================================================================
// __unwind$491122
// EA  : 0x82AFFEE4
// RVA : 0x00AFFEE4
// PDB : w:\tech5\tungsten\game\ai\gamestate\aiworldstate.cpp
// ========================================================================

void _unwind_491122()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 1504 + 112));
}


// ========================================================================
// __unwind$491123
// EA  : 0x82AFFF0C
// RVA : 0x00AFFF0C
// PDB : w:\tech5\tungsten\game\ai\gamestate\aiworldstate.cpp
// ========================================================================

void _unwind_491123()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 1504 + 1285));
}


// ========================================================================
// __unwind$491124
// EA  : 0x82AFFF34
// RVA : 0x00AFFF34
// PDB : w:\tech5\tungsten\game\ai\gamestate\aiworldstate.cpp
// ========================================================================

void _unwind_491124()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 1504 + 88));
}


// ========================================================================
// __unwind$491125
// EA  : 0x82AFFF5C
// RVA : 0x00AFFF5C
// PDB : w:\tech5\tungsten\game\ai\gamestate\aiworldstate.cpp
// ========================================================================

void _unwind_491125()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 1504 + 1286));
}


// ========================================================================
// __unwind$491126
// EA  : 0x82AFFF84
// RVA : 0x00AFFF84
// PDB : w:\tech5\tungsten\game\ai\gamestate\aiworldstate.cpp
// ========================================================================

void _unwind_491126()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 1504 + 112));
}


// ========================================================================
// ?AddEntityState@idAIWorldState@@QAAPBVidAIEntityState@@PBVidAIGameState@@ABVidAILogic@@ABVidSpawnId@@W4aiStimulus_t@@M2@Z
// EA  : 0x82AFFFB8
// RVA : 0x00AFFFB8
// PDB : w:\tech5\tungsten\game\ai\gamestate\aiworldstate.cpp
// ========================================================================

const idAIEntityState *__fastcall idAIWorldState::AddEntityState(
        idAIWorldState *this,
        idAIGameState *gameState,
        idEntityPtr<idAI2> *owner,
        const idEntityPtr<idAI2> *entId,
        aiStimulus_t stimulusType,
        double stimulusAmount,
        const idSpawnId *sourceId,
        const idEntityPtr<idAI2> *a8)
{
  unsigned __int64 v15; // r6
  const char *v16; // r7
  const aiLatchedState_t *State; // r3
  const idSpawnId *v18; // r8
  idAIEntityState *v19; // r27
  const aiLatchedState_t *v20; // r3
  int v22; // [sp+8h] [-B8h]
  int v23; // [sp+Ch] [-B4h]
  int v24; // [sp+10h] [-B0h]
  int v25; // [sp+14h] [-ACh]
  int v26; // [sp+18h] [-A8h]
  int v27; // [sp+1Ch] [-A4h]
  int v28; // [sp+20h] [-A0h]
  int v29; // [sp+24h] [-9Ch]
  int v30; // [sp+28h] [-98h]
  int v31; // [sp+2Ch] [-94h]
  int v32; // [sp+30h] [-90h]
  int v33; // [sp+34h] [-8Ch]
  int v34; // [sp+38h] [-88h]
  int v35; // [sp+3Ch] [-84h]
  int v36; // [sp+40h] [-80h]
  int v37; // [sp+44h] [-7Ch]
  int v38; // [sp+48h] [-78h]
  idHandle<int,enum invalidAIEvent_t,-1> *v39; // [sp+4Ch] [-74h]
  int v40; // [sp+50h] [-70h]
  idPLogScope v41[2]; // [sp+60h] [-60h] BYREF

  RD_EventBegin(name: "idAIWorldState::AddEntityState");
  LODWORD(v15) = "idAIWorldState::AddEntityState";
  HIDWORD(v15) = 2;
  idPLogScope::idPLogScope(this: v41, pl: &pLog, gMask: v15, label: v16);
  State = idAIGameState::GetState(this: gameState, spawnId: &entId->spawnId);
  v19 = idAIWorldState::InternalAddEntityState(
          this,
          gameState,
          owner,
          entId,
          stimulusType,
          stimulusAmount,
          sourceId: v18,
          sourceEventHandle: a8,
          ls: (const aiLatchedState_t *)0xFFFFFFFF,
          a10: v22,
          a11: v23,
          a12: v24,
          a13: v25,
          a14: v26,
          a15: v27,
          a16: v28,
          a17: v29,
          a18: v30,
          a19: v31,
          a20: v32,
          a21: v33,
          a22: v34,
          a23: v35,
          a24: v36,
          a25: v37,
          a26: v38,
          a27: v39,
          a28: v40,
          a29: State);
  if ( v19 != nullptr )
  {
    v20 = idAILogic::GetState(this: (idAILogic *)owner);
    idTargetCache::Update(this: &this->targetCache, ownerState: v20, worldState: this, targetSpawnId: &entId->spawnId);
  }
  idPLogScope::~idPLogScope(this: v41);
  RD_EventEnd();
  return v19;
}


// ========================================================================
// __unwind$491661
// EA  : 0x82B00088
// RVA : 0x00B00088
// PDB : w:\tech5\tungsten\game\ai\gamestate\aiworldstate.cpp
// ========================================================================

void _unwind_491661()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 192 + 104));
}


// ========================================================================
// __unwind$491662
// EA  : 0x82B000B0
// RVA : 0x00B000B0
// PDB : w:\tech5\tungsten\game\ai\gamestate\aiworldstate.cpp
// ========================================================================

void _unwind_491662()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 192 + 96));
}


// ========================================================================
// ?AddEntityStateFakePosition@idAIWorldState@@QAAPBVidAIEntityState@@PBVidAIGameState@@ABVidAILogic@@ABVidSpawnId@@W4aiStimulus_t@@M2ABVidVec3@@@Z
// EA  : 0x82B000D8
// RVA : 0x00B000D8
// PDB : w:\tech5\tungsten\game\ai\gamestate\aiworldstate.cpp
// ========================================================================

const aiLatchedState_t *__fastcall idAIWorldState::AddEntityStateFakePosition(
        idAIWorldState *this,
        idAIGameState *gameState,
        idEntityPtr<idAI2> *owner,
        const idEntityPtr<idAI2> *entId,
        aiStimulus_t stimulusType,
        double stimulusAmount,
        const idSpawnId *sourceId,
        const idEntityPtr<idAI2> *fakePosition,
        float *a9)
{
  const aiLatchedState_t *result; // r3
  const idSpawnId *v18; // r8
  double v19; // fp0
  double v20; // fp13
  double v21; // fp12
  idAIEntityState *v22; // r31
  const aiLatchedState_t *State; // r3
  int v24; // [sp+8h] [-118h]
  int v25; // [sp+Ch] [-114h]
  int v26; // [sp+10h] [-110h]
  int v27; // [sp+14h] [-10Ch]
  int v28; // [sp+18h] [-108h]
  int v29; // [sp+1Ch] [-104h]
  int v30; // [sp+20h] [-100h]
  int v31; // [sp+24h] [-FCh]
  int v32; // [sp+28h] [-F8h]
  int v33; // [sp+2Ch] [-F4h]
  int v34; // [sp+30h] [-F0h]
  int v35; // [sp+34h] [-ECh]
  int v36; // [sp+38h] [-E8h]
  int v37; // [sp+3Ch] [-E4h]
  int v38; // [sp+40h] [-E0h]
  int v39; // [sp+44h] [-DCh]
  int v40; // [sp+48h] [-D8h]
  idHandle<int,enum invalidAIEvent_t,-1> *v41; // [sp+4Ch] [-D4h]
  int v42; // [sp+50h] [-D0h]
  aiLatchedState_t v43; // [sp+60h] [-C0h] BYREF

  result = idAIGameState::GetState(this: gameState, spawnId: &entId->spawnId);
  if ( result != nullptr )
  {
    v43 = *result;
    v19 = a9[2];
    v20 = *a9;
    v21 = a9[1];
    v43.physical.origin.y = a9[1];
    v43.physical.origin.x = v20;
    v43.physical.eyePos.x = v20;
    v43.physical.eyePos.y = v21;
    v43.physical.eyePos.z = (float)v19 + (float)(v43.physical.eyePos.z - v43.physical.origin.z);
    v43.physical.origin.z = v19;
    v22 = idAIWorldState::InternalAddEntityState(
            this,
            gameState,
            owner,
            entId,
            stimulusType,
            stimulusAmount,
            sourceId: v18,
            sourceEventHandle: fakePosition,
            ls: (const aiLatchedState_t *)0xFFFFFFFF,
            a10: v24,
            a11: v25,
            a12: v26,
            a13: v27,
            a14: v28,
            a15: v29,
            a16: v30,
            a17: v31,
            a18: v32,
            a19: v33,
            a20: v34,
            a21: v35,
            a22: v36,
            a23: v37,
            a24: v38,
            a25: v39,
            a26: v40,
            a27: v41,
            a28: v42,
            a29: &v43);
    if ( v22 != nullptr )
    {
      State = idAILogic::GetState(this: (idAILogic *)owner);
      idTargetCache::Update(
        this: &this->targetCache,
        ownerState: State,
        worldState: this,
        targetSpawnId: &entId->spawnId);
    }
    return (const aiLatchedState_t *)v22;
  }
  return result;
}


// ========================================================================
// ?AddEntityState@idAIWorldState@@QAAPBVidAIEntityState@@PBVidAIGameState@@ABVidAILogic@@ABVidSpawnId@@W4aiStimulus_t@@M2ABVaiSenseState_t@@@Z
// EA  : 0x82B001D8
// RVA : 0x00B001D8
// PDB : w:\tech5\tungsten\game\ai\gamestate\aiworldstate.cpp
// ========================================================================

const idAIEntityState *__fastcall idAIWorldState::AddEntityState(
        idAIWorldState *this,
        idAIGameState *gameState,
        idEntityPtr<idAI2> *owner,
        const idEntityPtr<idAI2> *entId,
        aiStimulus_t stimulusType,
        double stimulusAmount,
        const idSpawnId *sourceId,
        const idEntityPtr<idAI2> *sourceSense,
        aiSenseState_t *a9)
{
  unsigned __int64 v17; // r6
  const char *v18; // r7
  const aiLatchedState_t *State; // r4
  idAI2 *v20; // r29
  const aiPhysicalState_t *v22; // r3
  const idSpawnId *v23; // r8
  const aiPhysicalState_t *ConfirmedPhysicalSafe; // r3
  idAIEntityState *v25; // r29
  const aiLatchedState_t *v26; // r3
  __int32 v27; // r9
  int v28; // [sp+8h] [-138h]
  int v29; // [sp+Ch] [-134h]
  int v30; // [sp+10h] [-130h]
  int v31; // [sp+14h] [-12Ch]
  int v32; // [sp+18h] [-128h]
  int v33; // [sp+1Ch] [-124h]
  int v34; // [sp+20h] [-120h]
  int v35; // [sp+24h] [-11Ch]
  int v36; // [sp+28h] [-118h]
  int v37; // [sp+2Ch] [-114h]
  int v38; // [sp+30h] [-110h]
  int v39; // [sp+34h] [-10Ch]
  int v40; // [sp+38h] [-108h]
  int v41; // [sp+3Ch] [-104h]
  int v42; // [sp+40h] [-100h]
  int v43; // [sp+44h] [-FCh]
  int v44; // [sp+48h] [-F8h]
  idHandle<int,enum invalidAIEvent_t,-1> *v45; // [sp+4Ch] [-F4h]
  int v46; // [sp+50h] [-F0h]
  idPLogScope v47[2]; // [sp+60h] [-E0h] BYREF
  aiLatchedState_t v48; // [sp+70h] [-D0h] BYREF

  RD_EventBegin(name: "idAIWorldState::AddEntityState");
  LODWORD(v17) = "idAIWorldState::AddEntityState";
  HIDWORD(v17) = 2;
  idPLogScope::idPLogScope(this: v47, pl: &pLog, gMask: v17, label: v18);
  aiLatchedState_t::aiLatchedState_t(this: &v48);
  State = idAIGameState::GetState(this: gameState, spawnId: &entId->spawnId);
  if ( State != nullptr )
  {
    aiLatchedState_t::operator=(this: &v48, __that: State);
    ConfirmedPhysicalSafe = aiSenseState_t::GetConfirmedPhysicalSafe(this: a9);
    aiPhysicalState_t::operator=(this: &v48.physical, __that: ConfirmedPhysicalSafe);
  }
  else
  {
    v20 = (idAI2 *)gameLocal->GetEntityForSpawnId_2(this: gameLocal, a2: entId->spawnId.value);
    if ( v20 == nullptr )
    {
      idPLogScope::~idPLogScope(this: v47);
      RD_EventEnd();
      return nullptr;
    }
    v48.spawnId.value = entId->spawnId.value;
    v48.frameNum = gameLocal->GetGameFrame(this: gameLocal);
    v48.entityType = idAIGameState::GetEntityType(ent: v20);
    v22 = aiSenseState_t::GetConfirmedPhysicalSafe(this: a9);
    aiPhysicalState_t::operator=(this: &v48.physical, __that: v22);
    v48.horzFOV = idAIVisibility::FOVDotToByte(fov: -0.000000050005699);
    v48.vertFOV = idAIVisibility::FOVDotToByte(fov: -0.000000050005699);
  }
  v25 = idAIWorldState::InternalAddEntityState(
          this,
          gameState,
          owner,
          entId,
          stimulusType,
          stimulusAmount,
          sourceId: v23,
          sourceEventHandle: sourceSense,
          ls: (const aiLatchedState_t *)0xFFFFFFFF,
          a10: v28,
          a11: v29,
          a12: v30,
          a13: v31,
          a14: v32,
          a15: v33,
          a16: v34,
          a17: v35,
          a18: v36,
          a19: v37,
          a20: v38,
          a21: v39,
          a22: v40,
          a23: v41,
          a24: v42,
          a25: v43,
          a26: v44,
          a27: v45,
          a28: v46,
          a29: &v48);
  if ( v25 != nullptr )
  {
    v26 = idAILogic::GetState(this: (idAILogic *)owner);
    idTargetCache::Update(this: &this->targetCache, ownerState: v26, worldState: this, targetSpawnId: &entId->spawnId);
    v27 = 4 * (idAIEntityState::SENSE_FOR_STIMULUS[stimulusType].sense + 128);
    (*(idAIEntityState_vtbl **)((char *)&v25->__vftable + v27))[11].GetType = (idTypeInfo *(__fastcall *)(struct idAIEntityState *))a9->lastUnconfirmedStimTime;
    if ( a9->lastConfirmedStimTime >= 0 )
    {
      BYTE1((*(idAIEntityState_vtbl **)((char *)&v25->__vftable + v27))[26].GetType) = a9->senseFlags & 0xF6 | 8;
      v25->senses.ptr[idAIEntityState::SENSE_FOR_STIMULUS[stimulusType].sense]->lastConfirmedStimTime = a9->lastConfirmedStimTime;
    }
  }
  idPLogScope::~idPLogScope(this: v47);
  RD_EventEnd();
  return v25;
}


// ========================================================================
// __unwind$491714
// EA  : 0x82B003E8
// RVA : 0x00B003E8
// PDB : w:\tech5\tungsten\game\ai\gamestate\aiworldstate.cpp
// ========================================================================

void _unwind_491714()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 320 + 220));
}


// ========================================================================
// __unwind$491715
// EA  : 0x82B00410
// RVA : 0x00B00410
// PDB : w:\tech5\tungsten\game\ai\gamestate\aiworldstate.cpp
// ========================================================================

void _unwind_491715()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 320 + 96));
}


// ========================================================================
// ?ForceAwarenessByDistance@idAIWorldState@@QAAXPAVidAI2@@M_N1@Z
// EA  : 0x82B00440
// RVA : 0x00B00440
// PDB : w:\tech5\tungsten\game\ai\gamestate\aiworldstate.cpp
// ========================================================================

void __fastcall idAIWorldState::ForceAwarenessByDistance(
        idAIWorldState *this,
        idAI2 *owner,
        double forceRadius,
        bool playerFlag,
        bool aiFlag,
        char a6)
{
  unsigned __int64 v11; // r6
  const char *v12; // r7
  idPhysics *Physics; // r3
  float *v14; // r3
  double v15; // fp31
  int EntitiesTouchingBounds; // r3
  int *v17; // r26
  int i; // r24
  int v19; // r9
  idAI2 *v20; // r30
  idPhysics *v21; // r3
  float *v22; // r3
  idAIGameState *p_aiGameState; // r21
  const idEntityPtr<idAI2> *v24; // r20
  const idEntityPtr<idAI2> *v25; // r30
  idEntityPtr<idAI2> *v26; // r3
  const idSpawnId *v27; // r8
  idPLog *pLog; // r29
  idPLog::logEntry_t *v29; // r30
  int v30; // r3
  __int64 totalTicks; // r11
  __int64 v32; // r9
  float v33; // [sp+50h] [-500h]
  float v34; // [sp+54h] [-4FCh]
  float v35; // [sp+58h] [-4F8h]
  idPLogScope v36; // [sp+60h] [-4F0h] BYREF
  idBounds v37; // [sp+70h] [-4E0h] BYREF
  idSpawnId v38; // [sp+88h] [-4C8h] BYREF
  idSpawnId v39; // [sp+8Ch] [-4C4h] BYREF
  idAILogic v40; // [sp+90h] [-4C0h] BYREF
  int v41[270]; // [sp+B0h] [-4A0h] BYREF

  RD_EventBegin(name: "idAIWorldState::ForceAwarenessByDistance");
  LODWORD(v11) = "idAIWorldState::ForceAwarenessByDistance";
  HIDWORD(v11) = 6;
  idPLogScope::idPLogScope(this: &v36, pl: &::pLog, gMask: v11, label: v12);
  Physics = idEntity::GetPhysics(this: owner);
  v14 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
  v35 = v14[2];
  v33 = *v14;
  v15 = *v14;
  v34 = v14[1];
  v37.b[0].x = (float)-forceRadius + *v14;
  v37.b[1].y = v34 + (float)forceRadius;
  v37.b[0].y = (float)-forceRadius + v34;
  v37.b[0].z = (float)-forceRadius + v35;
  v37.b[1].x = v33 + (float)forceRadius;
  v37.b[1].z = v35 + (float)forceRadius;
  EntitiesTouchingBounds = idClip::GetEntitiesTouchingBounds(
                             this: &clientGame->clip,
                             bounds: &v37,
                             clipMask: 99840,
                             entityList: v41,
                             maxCount: 256);
  if ( EntitiesTouchingBounds > 0 )
  {
    v17 = v41;
    for ( i = EntitiesTouchingBounds; i != 0; --i )
    {
      v19 = *v17 + 21563;
      v20 = *((idAI2 **)&gameLocal->__vftable + v19);
      if ( v20 != nullptr
        && v20 != owner
        && (a6 != 0 && (unsigned __int8)idAI2::IsTypeOf(c: *((idClass **)&gameLocal->__vftable + v19)) != 0
         || aiFlag && (unsigned __int8)idPlayer::IsTypeOf(c: v20) != 0) )
      {
        v21 = idEntity::GetPhysics(this: v20);
        v22 = (float *)v21->GetOrigin(this: v21, a2: 0);
        if ( (float)((float)((float)(v22[2] - v35) * (float)(v22[2] - v35))
                   + (float)((float)((float)(*v22 - (float)v15) * (float)(*v22 - (float)v15))
                           + (float)((float)(v22[1] - v34) * (float)(v22[1] - v34)))) <= (double)(float)((float)forceRadius * (float)forceRadius) )
        {
          p_aiGameState = &gameLocal->aiGameState;
          v24 = (const idEntityPtr<idAI2> *)idSpawnId::idSpawnId(this: &v38, ent: owner);
          v25 = (const idEntityPtr<idAI2> *)idSpawnId::idSpawnId(this: &v39, ent: v20);
          v26 = (idEntityPtr<idAI2> *)idAILogic::idAILogic(this: &v40, ai: owner);
          idAIWorldState::AddEntityState(
            this,
            gameState: p_aiGameState,
            owner: v26,
            entId: v25,
            stimulusType: AISTIMULUS_TRIGGER,
            stimulusAmount: 1.0,
            sourceId: v27,
            a8: v24);
        }
      }
      ++v17;
    }
  }
  if ( v36.logIndex >= 0 )
  {
    pLog = v36.pLog;
    v29 = &v36.pLog->logEntries.list[v36.logIndex];
    v30 = (unsigned __int64)Sys_GetClockTicks() >> 32;
    totalTicks = v29->totalTicks;
    HIDWORD(totalTicks) = v29->parent;
    LODWORD(v32) = v30 - totalTicks;
    v29->totalTicks = v32;
    pLog->lastEntry = HIDWORD(totalTicks);
  }
  RD_EventEnd();
}


// ========================================================================
// __unwind$491814
// EA  : 0x82B006A8
// RVA : 0x00B006A8
// PDB : w:\tech5\tungsten\game\ai\gamestate\aiworldstate.cpp
// ========================================================================

void _unwind_491814()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 1360 + 1200));
}


// ========================================================================
// __unwind$491815
// EA  : 0x82B006D0
// RVA : 0x00B006D0
// PDB : w:\tech5\tungsten\game\ai\gamestate\aiworldstate.cpp
// ========================================================================

void _unwind_491815()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 1360 + 96));
}


// ========================================================================
// ?Update@idAIWorldState@@QAAXPBVidAIGameState@@ABVidAILogic@@ABUtrackingParms_t@@@Z
// EA  : 0x82B006F8
// RVA : 0x00B006F8
// PDB : w:\tech5\tungsten\game\ai\gamestate\aiworldstate.cpp
// ========================================================================

void __fastcall idAIWorldState::Update(
        idAIWorldState *this,
        idAIGameState *gameState,
        idAILogic *aiOwner,
        const trackingParms_t *trackingParms)
{
  const aiLatchedState_t *State; // r3
  const aiLatchedState_t *v9; // r30

  State = idAILogic::GetState(this: aiOwner);
  v9 = State;
  if ( State != nullptr )
  {
    idAIWorldState::UpdateInternal(this, gameState, aiOwner, trackingParms, os: State);
    idAIWorldState::UpdateSprings(this, trackingParms);
    idTargetCache::Init(this: &this->targetCache, ownerState: v9, worldState: this);
  }
}


// ========================================================================
// `dynamic initializer for 'ai_visTraceOutsideFOV''
// EA  : 0x83369A48
// RVA : 0x01369A48
// PDB : w:\tech5\tungsten\game\ai\gamestate\aiworldstate.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_visTraceOutsideFOV__()
{
  idCVar::idCVar(
    this: &ai_visTraceOutsideFOV,
    name: "ai_visTraceOutsideFOV",
    value: "0",
    flags: 1,
    description: "1: vis trace to entities that are outside FOV",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_visTraceOutsideFOV__);
}


// ========================================================================
// `dynamic initializer for 'ai_perceptionRadiusOverride''
// EA  : 0x83369AA0
// RVA : 0x01369AA0
// PDB : w:\tech5\tungsten\game\ai\gamestate\aiworldstate.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_perceptionRadiusOverride__()
{
  idCVar::idCVar(
    this: &ai_perceptionRadiusOverride,
    name: "ai_perceptionRadiusOverride",
    value: "-1",
    flags: 4,
    description: "> 0: overrides AI actor perception radius",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_perceptionRadiusOverride__);
}


// ========================================================================
// `dynamic initializer for 'debugDeferredWorldState''
// EA  : 0x83369AF8
// RVA : 0x01369AF8
// PDB : w:\tech5\tungsten\game\ai\gamestate\aiworldstate.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__debugDeferredWorldState__()
{
  idCVar::idCVar(
    this: &debugDeferredWorldState,
    name: "debugDeferredWorldState",
    value: "0",
    flags: 1,
    description: "Toggle a box around the AI's head which indicates the results of his sense update.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__debugDeferredWorldState__);
}

