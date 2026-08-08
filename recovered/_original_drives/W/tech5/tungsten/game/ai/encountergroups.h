
// ========================================================================
// ??0idCombatStage@@QAA@XZ
// EA  : 0x8259F068
// RVA : 0x0059F068
// PDB : w:\tech5\tungsten\game\ai\encountergroups.h
// ========================================================================

idCombatStage *__fastcall idCombatStage::idCombatStage(idCombatStage *this)
{
  idList<enum encounterGroupRole_t,5> *p_rolePriorityList; // r27
  int p_hintGroup; // [sp+50h] [-40h] BYREF

  this->name.len = 0;
  this->name.allocedAndFlag = 20;
  this->name.data = this->name.baseBuffer;
  this->name.baseBuffer[0] = 0;
  this->stageType = COMBAT_STAGE_ADVANCE;
  this->hintGroup.spawnId.value = 0x1FFF;
  p_rolePriorityList = &this->rolePriorityList;
  this->rolePriorityList.list = nullptr;
  this->rolePriorityList.granularity = 0;
  this->rolePriorityList.memTag = 5;
  this->rolePriorityList.listStatic = 0;
  this->rolePriorityList.size = 0;
  this->rolePriorityList.num = 0;
  p_hintGroup = (int)&this->hintGroup;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->rolePriorityList);
  this->stageTriggers.list = nullptr;
  this->stageTriggers.granularity = 0;
  this->stageTriggers.memTag = 5;
  this->stageTriggers.listStatic = 0;
  this->stageTriggers.size = 0;
  this->stageTriggers.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->stageTriggers);
  this->assaultBreachRules.list = nullptr;
  this->assaultBreachRules.granularity = 0;
  this->assaultBreachRules.memTag = 5;
  this->assaultBreachRules.listStatic = 0;
  this->assaultBreachRules.size = 0;
  this->assaultBreachRules.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->assaultBreachRules);
  this->fakeEnemy.spawnId.value = 0x1FFF;
  *((_BYTE *)this + 92) = *((_BYTE *)this + 92) & 3 | 0xF4;
  this->defenseNodes.list = nullptr;
  this->defenseNodes.granularity = 0;
  this->defenseNodes.memTag = 5;
  this->defenseNodes.listStatic = 0;
  this->defenseNodes.size = 0;
  this->defenseNodes.num = 0;
  p_hintGroup = (int)&this->fakeEnemy;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->defenseNodes);
  this->assaultNodes.list = nullptr;
  this->assaultNodes.granularity = 0;
  this->assaultNodes.memTag = 5;
  this->assaultNodes.listStatic = 0;
  this->assaultNodes.size = 0;
  this->assaultNodes.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->assaultNodes);
  this->flankNodes.list = nullptr;
  this->flankNodes.granularity = 0;
  this->flankNodes.memTag = 5;
  this->flankNodes.listStatic = 0;
  this->flankNodes.size = 0;
  this->flankNodes.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->flankNodes);
  this->flankTargetNodes.list = nullptr;
  this->flankTargetNodes.granularity = 0;
  this->flankTargetNodes.memTag = 5;
  this->flankTargetNodes.listStatic = 0;
  this->flankTargetNodes.size = 0;
  this->flankTargetNodes.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->flankTargetNodes);
  this->flankPathNodes.list = nullptr;
  this->flankPathNodes.granularity = 0;
  this->flankPathNodes.memTag = 5;
  this->flankPathNodes.listStatic = 0;
  this->flankPathNodes.size = 0;
  this->flankPathNodes.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->flankPathNodes);
  this->grenadeNodes.list = nullptr;
  this->grenadeNodes.granularity = 0;
  this->grenadeNodes.memTag = 5;
  this->grenadeNodes.listStatic = 0;
  this->grenadeNodes.size = 0;
  this->grenadeNodes.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->grenadeNodes);
  this->rechargeNodes.list = nullptr;
  this->rechargeNodes.granularity = 0;
  this->rechargeNodes.memTag = 5;
  this->rechargeNodes.listStatic = 0;
  this->rechargeNodes.size = 0;
  this->rechargeNodes.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->rechargeNodes);
  this->suppressionFireNodes.list = nullptr;
  this->suppressionFireNodes.granularity = 0;
  this->suppressionFireNodes.memTag = 5;
  this->suppressionFireNodes.listStatic = 0;
  this->suppressionFireNodes.size = 0;
  this->suppressionFireNodes.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->suppressionFireNodes);
  p_hintGroup = 1;
  idList<idAnimWebBlendTree *,5>::Append(this: p_rolePriorityList, obj: (const encounterGroupRole_t *)&p_hintGroup);
  return this;
}


// ========================================================================
// __unwind$710878
// EA  : 0x8259F25C
// RVA : 0x0059F25C
// PDB : w:\tech5\tungsten\game\ai\encountergroups.h
// ========================================================================

void _unwind_710878()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v0 - 144 + 164));
}


// ========================================================================
// __unwind$710879
// EA  : 0x8259F284
// RVA : 0x0059F284
// PDB : w:\tech5\tungsten\game\ai\encountergroups.h
// ========================================================================

void _unwind_710879()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 40));
}


// ========================================================================
// __unwind$710880
// EA  : 0x8259F2B0
// RVA : 0x0059F2B0
// PDB : w:\tech5\tungsten\game\ai\encountergroups.h
// ========================================================================

void _unwind_710880()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 56));
}


// ========================================================================
// __unwind$710881
// EA  : 0x8259F2DC
// RVA : 0x0059F2DC
// PDB : w:\tech5\tungsten\game\ai\encountergroups.h
// ========================================================================

void _unwind_710881()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 72));
}


// ========================================================================
// __unwind$710882
// EA  : 0x8259F308
// RVA : 0x0059F308
// PDB : w:\tech5\tungsten\game\ai\encountergroups.h
// ========================================================================

void _unwind_710882()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 96));
}


// ========================================================================
// __unwind$710883
// EA  : 0x8259F334
// RVA : 0x0059F334
// PDB : w:\tech5\tungsten\game\ai\encountergroups.h
// ========================================================================

void _unwind_710883()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 112));
}


// ========================================================================
// __unwind$710884
// EA  : 0x8259F360
// RVA : 0x0059F360
// PDB : w:\tech5\tungsten\game\ai\encountergroups.h
// ========================================================================

void _unwind_710884()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 128));
}


// ========================================================================
// __unwind$710885
// EA  : 0x8259F38C
// RVA : 0x0059F38C
// PDB : w:\tech5\tungsten\game\ai\encountergroups.h
// ========================================================================

void _unwind_710885()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 144));
}


// ========================================================================
// __unwind$710886
// EA  : 0x8259F3B8
// RVA : 0x0059F3B8
// PDB : w:\tech5\tungsten\game\ai\encountergroups.h
// ========================================================================

void _unwind_710886()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 160));
}


// ========================================================================
// __unwind$710887
// EA  : 0x8259F3E4
// RVA : 0x0059F3E4
// PDB : w:\tech5\tungsten\game\ai\encountergroups.h
// ========================================================================

void _unwind_710887()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 176));
}


// ========================================================================
// __unwind$710888
// EA  : 0x8259F410
// RVA : 0x0059F410
// PDB : w:\tech5\tungsten\game\ai\encountergroups.h
// ========================================================================

void _unwind_710888()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 192));
}


// ========================================================================
// __unwind$710889
// EA  : 0x8259F43C
// RVA : 0x0059F43C
// PDB : w:\tech5\tungsten\game\ai\encountergroups.h
// ========================================================================

void _unwind_710889()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 208));
}


// ========================================================================
// ?GetCurrentCombatStage@idEncounterGroup@@QAAPAVidCombatStage@@XZ
// EA  : 0x829F5DD8
// RVA : 0x009F5DD8
// PDB : w:\tech5\tungsten\game\ai\encountergroups.h
// ========================================================================

idCombatStage *__fastcall idEncounterGroup::GetCurrentCombatStage(idEncounterGroup *this)
{
  int curCombatStage; // r11

  curCombatStage = this->curCombatStage;
  if ( curCombatStage < 0 || curCombatStage >= this->combatStages.num )
    return nullptr;
  else
    return &this->combatStages.list[curCombatStage];
}


// ========================================================================
// ?GetTarget@idEncounterGroup@@QAAPAVidEntity@@H@Z
// EA  : 0x82A02358
// RVA : 0x00A02358
// PDB : w:\tech5\tungsten\game\ai\encountergroups.h
// ========================================================================

idEntity *__fastcall idEncounterGroup::GetTarget(idEncounterGroup *this, const int index)
{
  int value; // r9
  idEntity *v3; // r3

  value = this->targetList.list[index].target.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v3 = gameLocal->entities.ptr[this->targetList.list[index].target.spawnId.value & 0x1FFF]) != nullptr )
  {
    return idEntity::CastTo(c: v3);
  }
  else
  {
    return nullptr;
  }
}


// ========================================================================
// ?Triggerable@idEncounterGroupExpr@@QBA_NXZ
// EA  : 0x82A941E8
// RVA : 0x00A941E8
// PDB : w:\tech5\tungsten\game\ai\encountergroups.h
// ========================================================================

int __fastcall idEncounterGroupExpr::Triggerable(idEncounterGroupExpr *this)
{
  int value; // r10
  idEntity *v3; // r3
  unsigned __int8 v4; // r11

  value = this->target.spawnId.value;
  v4 = false;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
  {
    v3 = gameLocal->entities.ptr[value & 0x1FFF];
    if ( v3 != nullptr && idEntity::CastTo(c: v3) != nullptr && (!this->triggered || !this->triggerOnce) )
      return true;
  }
  return v4;
}


// ========================================================================
// ?GetEnemy@idAIMemory@@QBAPBVidEntity@@XZ
// EA  : 0x82A94280
// RVA : 0x00A94280
// PDB : w:\tech5\tungsten\game\ai\encountergroups.h
// ========================================================================

const idEntity *__fastcall idAIMemory::GetEnemy(idAIMemory *this)
{
  int value; // r10
  idEntity *v2; // r3

  value = this->currentEnemy.spawnId.value;
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
// ?GetLeader@idEncounterGroup@@QBAPAVidAI2@@XZ
// EA  : 0x82A942C8
// RVA : 0x00A942C8
// PDB : w:\tech5\tungsten\game\ai\encountergroups.h
// ========================================================================

idAI2 *__fastcall idEncounterGroup::GetLeader(idEncounterGroup *this)
{
  int value; // r10
  idAI2 *v2; // r3

  value = this->leader.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v2 = (idAI2 *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    return idAI2::CastTo(c: v2);
  }
  else
  {
    return nullptr;
  }
}


// ========================================================================
// ?Eval@idEncounterGroupExpr@@QBA_NPBVidEncounterGroup@@@Z
// EA  : 0x82A9A2E8
// RVA : 0x00A9A2E8
// PDB : w:\tech5\tungsten\game\ai\encountergroups.h
// ========================================================================

int __fastcall idEncounterGroupExpr::Eval(idEncounterGroupExpr *this, idEncounterGroup *owner)
{
  idEncounterGroupExpr::triggerOp_t op; // r11
  unsigned __int8 v4; // r11
  double v6; // fp1
  double v7; // fp1
  double v8; // fp1
  double v9; // fp1

  op = this->op;
  if ( (unsigned int)op > TRIGGEROP_GREATER_THAN_EQUAL )
    return 0;
  switch ( op )
  {
    case TRIGGEROP_LESS_THAN_EQUAL:
      v6 = idEncounterGroupExpr::Value(this, group: owner);
      v4 = 1;
      if ( v6 > this->value )
        return 0;
      return v4;
    case TRIGGEROP_EQUAL:
      v7 = idEncounterGroupExpr::Value(this, group: owner);
      v4 = 1;
      if ( v7 == this->value )
        return v4;
      return 0;
    case TRIGGEROP_GREATER_THAN:
      v8 = idEncounterGroupExpr::Value(this, group: owner);
      v4 = 1;
      if ( v8 > this->value )
        return v4;
      return 0;
    case TRIGGEROP_LESS_THAN:
      return idEncounterGroupExpr::Value(this, group: owner) < (double)this->value;
    default:
      v9 = idEncounterGroupExpr::Value(this, group: owner);
      v4 = 1;
      if ( v9 >= this->value )
        return v4;
      return 0;
  }
}

