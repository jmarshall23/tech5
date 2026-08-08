
// ========================================================================
// ??0idAICoverManager@@QAA@XZ
// EA  : 0x82A8A450
// RVA : 0x00A8A450
// PDB : w:\tech5\tungsten\game\ai\cover\aicovermanager.cpp
// ========================================================================

idAICoverManager *__fastcall idAICoverManager::idAICoverManager(idAICoverManager *this)
{
  this->knownCover.granularity = 0;
  this->knownCover.memTag = 5;
  this->knownCover.listStatic = 0;
  this->knownCover.list = nullptr;
  this->knownCover.size = 0;
  this->knownCover.num = 0;
  this->lastUpdateTime = 0;
  this->lastTravelFlags = 0;
  this->lastUpdatePos.x = 0.0;
  this->lastUpdatePos.y = 0.0;
  this->lastUpdatePos.z = 0.0;
  this->forceUpdate = false;
  return this;
}


// ========================================================================
// ?UpdateCover@idAICoverManager@@QAAXPAVidAI2@@ABVidVec3@@H_N2@Z
// EA  : 0x82A8A508
// RVA : 0x00A8A508
// PDB : w:\tech5\tungsten\game\ai\cover\aicovermanager.cpp
// ========================================================================

void __fastcall idAICoverManager::UpdateCover(
        idAICoverManager *this,
        idAI2 *ai,
        const idVec3 *referencePoint,
        int curTime,
        const bool force,
        const bool useStageFilter)
{
  unsigned __int64 v12; // r6
  const char *v13; // r7
  bool v14; // r11
  const idDeclAIBehavior *decl; // r22
  double v16; // fp12
  double v17; // fp9
  double v18; // fp6
  const idAAS2 *v19; // r23
  double v20; // fp12
  double v21; // fp9
  double v22; // fp6
  int travelFlags; // r30
  double coverRadius; // fp31
  idAAS2 v25; // r29
  int AreaNum; // r3
  int v27; // r6
  idEncounterGroup *EncounterGroup; // r3
  int curCombatStage; // r11
  idEncounterGroup *v30; // r3
  int v31; // r11
  idCombatStage *v32; // r11
  idEncounterGroup *v33; // r3
  idPhysics *Physics; // r3
  double v35; // fp31
  float *v36; // r25
  int v37; // r27
  idLinkList<idVehicle> *next; // r11
  idVehicle *owner; // r30
  idPhysics *v40; // r3
  float *v41; // r3
  double v42; // fp10
  double v43; // fp6
  idDynamicCoverMgr *v44; // r3
  idLinkList<idVehicle> *v45; // r11
  idEncounterGroup *v46; // r3
  int v47; // r11
  idEncounterGroup *v48; // r3
  int v49; // r11
  int v50; // r11
  idLinkList<idActor> *v51; // r11
  idAI2 *v52; // r30
  idAI2 *v53; // r3
  idPhysics *v54; // r3
  float *v55; // r3
  double v56; // fp10
  double v57; // fp6
  idDynamicCoverMgr *v58; // r3
  idLinkList<idActor> *v59; // r11
  idPLog *pLog; // r29
  idPLog::logEntry_t *v61; // r30
  int v62; // r3
  __int64 totalTicks; // r11
  __int64 v64; // r9
  double v65; // [sp+30h] [-1C0h]
  idPLogScope v66; // [sp+68h] [-188h] BYREF
  idList<int,5> v67; // [sp+70h] [-180h] BYREF
  int v68; // [sp+80h] [-170h] BYREF

  RD_EventBegin(name: "idAICoverManager::UpdateCover");
  LODWORD(v12) = "idAICoverManager::UpdateCover";
  HIDWORD(v12) = 6;
  idPLogScope::idPLogScope(this: &v66, pl: &::pLog, gMask: v12, label: v13);
  v14 = force || this->forceUpdate;
  this->forceUpdate = false;
  if ( !v14 )
    v14 = ai->aiVolatile.aas.travelFlags != this->lastTravelFlags;
  if ( !v14 )
  {
    if ( this->knownCover.num != 0 || (v14 = true, curTime - this->lastUpdateTime < 5000) )
      v14 = false;
  }
  decl = ai->aiEditable.behaviors.decl;
  if ( !v14 )
  {
    if ( (*(_BYTE *)&decl->dynamicCoverCaps & 0x40) == 0 && (*(_BYTE *)&decl->dynamicCoverCaps & 0x80) == 0
      || (v14 = true, curTime - this->lastUpdateTime < 5000) )
    {
      v14 = false;
    }
  }
  if ( !v14 )
  {
    v16 = (float)(referencePoint->y - this->lastUpdatePos.y);
    v17 = (float)(referencePoint->x - this->lastUpdatePos.x);
    v18 = (float)(referencePoint->z - this->lastUpdatePos.z);
    v14 = (float)((float)((float)v18 * (float)v18)
                + (float)((float)((float)v17 * (float)v17) + (float)((float)v16 * (float)v16))) >= 16384.0;
  }
  if ( v14 && (v19 = ai->GetAAS(this: ai)) != nullptr )
  {
    if ( ai_debugCover.valueInteger > 0 && ai_debugLevel.valueInteger != 0 )
    {
      v20 = (float)(referencePoint->y - this->lastUpdatePos.y);
      v21 = (float)(referencePoint->x - this->lastUpdatePos.x);
      v22 = (float)(referencePoint->z - this->lastUpdatePos.z);
      v65 = __fsqrts((float)((float)((float)v22 * (float)v22)
                           + (float)((float)((float)v21 * (float)v21) + (float)((float)v20 * (float)v20))));
      idLib::Printf(
        fmt: "[%d] %s updating cover - time interval %d, dist = %.2f, travel flags change = %d\n",
        curTime,
        ai->name.data,
        HIDWORD(v65),
        v65,
        LODWORD(v65));
    }
    this->lastUpdatePos.x = referencePoint->x;
    this->lastUpdatePos.y = referencePoint->y;
    this->lastUpdatePos.z = referencePoint->z;
    this->lastUpdateTime = curTime;
    travelFlags = ai->aiVolatile.aas.travelFlags;
    this->lastTravelFlags = travelFlags;
    coverRadius = ai->aiEditable.cover.coverRadius;
    if ( ai_coverRadiusOverride.valueFloat != -1.0 )
      coverRadius = ai_coverRadiusOverride.valueFloat;
    v25.__vftable = v19->__vftable;
    AreaNum = idActor::GetAreaNum(this: ai, aas: v19);
    ((void (__fastcall *)(const idAAS2 *, int, const idVec3 *, int, _DWORD, _DWORD, int, int *, double))v25.FindCoverPoints)(
      a1: v19,
      a2: AreaNum,
      a3: referencePoint,
      a4: v27,
      a5: 0,
      a6: 0,
      a7: travelFlags,
      a8: &v68,
      a9: coverRadius);
    if ( useStageFilter && ai_useStageCoverFilter.valueInteger != 0 && idAI2::GetEncounterGroup(this: ai) != nullptr )
    {
      EncounterGroup = idAI2::GetEncounterGroup(this: ai);
      curCombatStage = EncounterGroup->curCombatStage;
      if ( curCombatStage >= 0
        && curCombatStage < EncounterGroup->combatStages.num
        && &EncounterGroup->combatStages.list[curCombatStage] != nullptr )
      {
        v30 = idAI2::GetEncounterGroup(this: ai);
        v31 = v30->curCombatStage;
        if ( v31 < 0 || v31 >= v30->combatStages.num )
          v32 = nullptr;
        else
          v32 = &v30->combatStages.list[v31];
        if ( v32->defenseNodes.num != 0 || v32->assaultNodes.num != 0 || v32->flankNodes.num != 0 )
        {
          idList<idVehicleKey *,5>::idList<idVehicleKey *,5>(this: (idList<idDeclVehicleUpgrade const *,5> *)&v67);
          v33 = idAI2::GetEncounterGroup(this: ai);
          idEncounterGroup::GetCurrentCombatStageCoverIndices(this: v33, coverIndices: &v67);
          idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v67);
        }
      }
    }
    if ( this->knownCover.size < 0 )
      idList<idAICover,5>::Resize(this: &this->knownCover, newsize: 0);
    idList<idAICover,5>::SetNum(this: &this->knownCover, newNum: 0);
    Physics = idEntity::GetPhysics(this: ai);
    v35 = (float)((float)coverRadius * (float)coverRadius);
    v36 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
    v37 = 0;
    if ( (*(_BYTE *)&decl->dynamicCoverCaps & 0x80) != 0 && ai_useVehicleCover.valueInteger != 0 )
    {
      next = gameLocal->vehicleEntities.next;
      if ( next != nullptr && next != gameLocal->vehicleEntities.head )
      {
        owner = next->owner;
        while ( owner != nullptr )
        {
          if ( owner->provideDynamicCover || ai_forceVehicleCoverFlag.valueInteger != 0 )
          {
            v40 = idEntity::GetPhysics(this: owner);
            v41 = (float *)v40->GetOrigin(this: v40, a2: 0);
            v42 = (float)(v41[1] - v36[1]);
            v43 = (float)(v41[2] - v36[2]);
            if ( (float)((float)((float)v43 * (float)v43)
                       + (float)((float)((float)(*v41 - *v36) * (float)(*v41 - *v36)) + (float)((float)v42 * (float)v42))) <= v35 )
            {
              v44 = owner->GetDynamicCoverMgr(this: owner);
              if ( v44 != nullptr )
                v37 += idDynamicCoverMgr::AppendUsableCover(this: v44, owner, aas: v19, coverList: &this->knownCover);
            }
          }
          v45 = owner->controlNode.next;
          if ( v45 == nullptr || v45 == owner->controlNode.head )
            owner = nullptr;
          else
            owner = v45->owner;
        }
      }
    }
    if ( idAI2::GetEncounterGroup(this: ai) != nullptr
      && (*(_BYTE *)&decl->dynamicCoverCaps & 0x40) != 0
      && ai_useFormationCover.valueInteger != 0 )
    {
      if ( (v46 = idAI2::GetEncounterGroup(this: ai), (v47 = v46->curCombatStage) < 0)
        || v47 >= v46->combatStages.num
        || &v46->combatStages.list[v47] == nullptr
        || ((v48 = idAI2::GetEncounterGroup(this: ai), (v49 = v48->curCombatStage) < 0) || v49 >= v48->combatStages.num
          ? (v50 = 0)
          : (v50 = (int)&v48->combatStages.list[v49]),
            (*(_BYTE *)(v50 + 92) & 4) != 0) )
      {
        v51 = gameLocal->actorEntities.next;
        if ( v51 != nullptr && v51 != gameLocal->actorEntities.head )
        {
          v52 = (idAI2 *)v51->owner;
          while ( v52 != nullptr )
          {
            v53 = idAI2::CastTo(c: v52);
            if ( v53 != nullptr && idAI2::ProvidesFormationCover(this: v53) )
            {
              v54 = idEntity::GetPhysics(this: v52);
              v55 = (float *)v54->GetOrigin(this: v54, a2: 0);
              v56 = (float)(v55[1] - v36[1]);
              v57 = (float)(v55[2] - v36[2]);
              if ( (float)((float)((float)v57 * (float)v57)
                         + (float)((float)((float)(*v55 - *v36) * (float)(*v55 - *v36))
                                 + (float)((float)v56 * (float)v56))) <= v35 )
              {
                v58 = v52->GetDynamicCoverMgr(this: v52);
                if ( v58 != nullptr )
                  v37 += idDynamicCoverMgr::AppendUsableCover(
                           this: v58,
                           owner: v52,
                           aas: v19,
                           coverList: &this->knownCover);
              }
            }
            v59 = v52->actorNode.next;
            if ( v59 == nullptr || v59 == v52->actorNode.head )
              v52 = nullptr;
            else
              v52 = (idAI2 *)v59->owner;
          }
        }
      }
    }
    if ( v37 > 0 )
      idLib::Printf(fmt: "Added %d dynamic cover points.\n", v37);
    if ( v66.logIndex >= 0 )
    {
      pLog = v66.pLog;
      v61 = &v66.pLog->logEntries.list[v66.logIndex];
      v62 = (unsigned __int64)Sys_GetClockTicks() >> 32;
      totalTicks = v61->totalTicks;
      HIDWORD(totalTicks) = v61->parent;
      LODWORD(v64) = v62 - totalTicks;
      v61->totalTicks = v64;
      pLog->lastEntry = HIDWORD(totalTicks);
    }
  }
  else
  {
    idPLogScope::~idPLogScope(this: &v66);
  }
  RD_EventEnd();
}


// ========================================================================
// __unwind$488075
// EA  : 0x82A8ACC4
// RVA : 0x00A8ACC4
// PDB : w:\tech5\tungsten\game\ai\cover\aicovermanager.cpp
// ========================================================================

void _unwind_488075()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 496 + 384));
}


// ========================================================================
// __unwind$488076
// EA  : 0x82A8ACEC
// RVA : 0x00A8ACEC
// PDB : w:\tech5\tungsten\game\ai\cover\aicovermanager.cpp
// ========================================================================

void _unwind_488076()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 496 + 104));
}


// ========================================================================
// __unwind$488077
// EA  : 0x82A8AD14
// RVA : 0x00A8AD14
// PDB : w:\tech5\tungsten\game\ai\cover\aicovermanager.cpp
// ========================================================================

void _unwind_488077()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 496 + 112));
}


// ========================================================================
// ?HasCover@idAICoverManager@@QAA_NPAVidAI2@@ABVidVec3@@H_N@Z
// EA  : 0x82A8AD40
// RVA : 0x00A8AD40
// PDB : w:\tech5\tungsten\game\ai\cover\aicovermanager.cpp
// ========================================================================

unsigned int __fastcall idAICoverManager::HasCover(
        idAICoverManager *this,
        idAI2 *ai,
        const idVec3 *referencePoint,
        int curTime,
        const bool inAvoid)
{
  idAICoverManager::UpdateCover(
    this,
    ai,
    referencePoint,
    curTime,
    force: inAvoid,
    useStageFilter: (_cntlzw(inAvoid) & 0x20) != 0);
  return (-this->knownCover.num & (unsigned int)~this->knownCover.num) >> 31;
}


// ========================================================================
// `dynamic initializer for 'ai_coverRadiusOverride''
// EA  : 0x83368E90
// RVA : 0x01368E90
// PDB : w:\tech5\tungsten\game\ai\cover\aicovermanager.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_coverRadiusOverride__()
{
  idCVar::idCVar(
    this: &ai_coverRadiusOverride,
    name: "ai_coverRadiusOverride",
    value: "-1",
    flags: 4,
    description: "if not -1 this overrides all AI's cover radius",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_coverRadiusOverride__);
}


// ========================================================================
// `dynamic initializer for 'ai_useFormationCover''
// EA  : 0x83368EE8
// RVA : 0x01368EE8
// PDB : w:\tech5\tungsten\game\ai\cover\aicovermanager.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_useFormationCover__()
{
  idCVar::idCVar(
    this: &ai_useFormationCover,
    name: "ai_useFormationCover",
    value: "1",
    flags: 4,
    description: "1 - formation cover, such as behind regime shield units",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_useFormationCover__);
}


// ========================================================================
// `dynamic initializer for 'ai_useVehicleCover''
// EA  : 0x83368F40
// RVA : 0x01368F40
// PDB : w:\tech5\tungsten\game\ai\cover\aicovermanager.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_useVehicleCover__()
{
  idCVar::idCVar(
    this: &ai_useVehicleCover,
    name: "ai_useVehicleCover",
    value: "1",
    flags: 4,
    description: "1 - formation cover, such as behind regime shield units",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_useVehicleCover__);
}


// ========================================================================
// `dynamic initializer for 'ai_forceVehicleCoverFlag''
// EA  : 0x83368F98
// RVA : 0x01368F98
// PDB : w:\tech5\tungsten\game\ai\cover\aicovermanager.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_forceVehicleCoverFlag__()
{
  idCVar::idCVar(
    this: &ai_forceVehicleCoverFlag,
    name: "ai_forceVehicleCoverFlag",
    value: "0",
    flags: 1,
    description: "force all vehicles to provide cover.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_forceVehicleCoverFlag__);
}

