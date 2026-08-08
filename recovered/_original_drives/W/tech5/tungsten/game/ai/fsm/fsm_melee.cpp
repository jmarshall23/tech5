
// ========================================================================
// ?InternalInitState@idMelee_Default@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82ADA130
// RVA : 0x00ADA130
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_melee.cpp
// ========================================================================

void __fastcall idMelee_Default::InternalInitState(idMelee_Default *this, const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(this, fsm, transType: &MELEE_NoTarget::Type, nextStateType: &idAIStateDone::Type);
  idState::AddStateTransition(this, fsm, transType: &MELEE_TargetOutOfRange::Type, nextStateType: &idAIStateDone::Type);
  idState::AddStateTransition(this, fsm, transType: &MELEE_Reposition::Type, nextStateType: &idMelee_Reposition::Type);
  idState::AddStateTransition(this, fsm, transType: &MELEE_Attack::Type, nextStateType: &idMelee_Attack::Type);
}


// ========================================================================
// ?AIState_EnterState@idMelee_Default@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82ADA1B8
// RVA : 0x00ADA1B8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_melee.cpp
// ========================================================================

void __fastcall idMelee_Default::AIState_EnterState(
        idAdvance_Default *this,
        idAI2 *ai,
        idAIFSM *fsm,
        const int curTime)
{
  idAI2::SetEnableHeadTracking(this: ai, enable: true);
}


// ========================================================================
// ?InternalInitState@idMelee_Attack@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82ADA1C8
// RVA : 0x00ADA1C8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_melee.cpp
// ========================================================================

void __fastcall idMelee_Attack::InternalInitState(idMelee_Attack *this, const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(this, fsm, transType: &MELEE_AttackDone::Type, nextStateType: &idMelee_Default::Type);
}


// ========================================================================
// ?Evaluate@MELEE_RepositionFailed@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82ADA1E0
// RVA : 0x00ADA1E0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_melee.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall MELEE_RepositionFailed::Evaluate(
        MELEE_RepositionFailed *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        XGRAPHICS::IRInst *state,
        const int curTime)
{
  idAIMoveState *MoveInterface; // r3
  idAIStateTransition::aiTransCode_t result; // r3
  bool v8; // zf

  if ( idFile_SaveGamePipelined::GetFullPath(this: state) == 0 )
    return TRANSCODE_MELEE_REPOSITION_FAILED;
  MoveInterface = idAI2::GetMoveInterface(this: ai);
  v8 = MoveInterface->GetMoveStatus(this: MoveInterface) < 2;
  result = 0;
  if ( !v8 )
    return TRANSCODE_MELEE_REPOSITION_FAILED;
  return result;
}


// ========================================================================
// ?InternalInitState@idMelee_Reposition@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82ADA248
// RVA : 0x00ADA248
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_melee.cpp
// ========================================================================

void __fastcall idMelee_Reposition::InternalInitState(idMelee_Reposition *this, const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(this, fsm, transType: &MELEE_NoTarget::Type, nextStateType: &idAIStateDone::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &MELEE_RepositionFailed::Type,
    nextStateType: &idMelee_Default::Type);
  idState::AddStateTransition(this, fsm, transType: &MELEE_RepositionDone::Type, nextStateType: &idMelee_Default::Type);
}


// ========================================================================
// ?InitStates@idMeleeFSM@@UAAXABVidFiniteStateMachineParams@@@Z
// EA  : 0x82ADA2B0
// RVA : 0x00ADA2B0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_melee.cpp
// ========================================================================

void __fastcall idMeleeFSM::InitStates(idMeleeFSM *this, const idFiniteStateMachineParams *params)
{
  idAIFSM::InitStates(this, params);
  this->AddState(this, a2: &this->stateDefault);
  this->AddState(this, a2: &this->stateReposition);
  this->AddState(this, a2: &this->stateAttack);
}


// ========================================================================
// ?Evaluate@MELEE_Reposition@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82ADA328
// RVA : 0x00ADA328
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_melee.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall MELEE_Reposition::Evaluate(
        MELEE_Reposition *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        int curTime)
{
  idAIStateTransition::aiTransCode_t result; // r3
  const idDeclAIBehavior *decl; // r10
  unsigned int v8; // r8
  bool v9; // zf

  if ( ai->aiVolatile.memory.nextDodgeTime > curTime )
    return 0;
  decl = ai->aiEditable.behaviors.decl;
  v8 = 1664525 * clientGame->random.seed + 1013904223;
  clientGame->random.seed = v8;
  if ( (signed int)(((v8 >> 10) & 0x7FFF) % 0x64) > decl->meleeDodgeChance )
    return 0;
  if ( (unsigned __int8)idAI2::HasAngryRage(this: ai) == 0 )
    return TRANSCODE_MELEE_REPOSITION;
  v9 = (unsigned __int8)idAI2::WantsToAngryRage(this: ai) != 0;
  result = 0;
  if ( !v9 )
    return TRANSCODE_MELEE_REPOSITION;
  return result;
}


// ========================================================================
// ?Evaluate@COMBAT_MeleeDone@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82ADA408
// RVA : 0x00ADA408
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_melee.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall COMBAT_MeleeDone::Evaluate(
        COMBAT_MeleeDone *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        XGRAPHICS::IRInst *state,
        const int curTime)
{
  idFiniteStateMachine *FullPath; // r3
  idAIStateTransition::aiTransCode_t result; // r3
  bool v7; // zf

  FullPath = (idFiniteStateMachine *)idFile_SaveGamePipelined::GetFullPath(this: state);
  if ( FullPath == nullptr )
    return TRANSCODE_MELEE_DONE;
  v7 = idFiniteStateMachine::GetStatus(this: FullPath) != 0;
  result = 0;
  if ( !v7 )
    return TRANSCODE_MELEE_DONE;
  return result;
}


// ========================================================================
// ?Evaluate@MELEE_RepositionDone@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82ADA450
// RVA : 0x00ADA450
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_melee.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall MELEE_RepositionDone::Evaluate(
        MELEE_RepositionDone *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        XGRAPHICS::IRInst *state,
        const int curTime)
{
  idFiniteStateMachine *FullPath; // r3
  idAIStateTransition::aiTransCode_t result; // r3
  bool v7; // zf

  FullPath = (idFiniteStateMachine *)idFile_SaveGamePipelined::GetFullPath(this: state);
  if ( FullPath == nullptr )
    return TRANSCODE_MELEE_REPOSITION_DONE;
  v7 = idFiniteStateMachine::GetStatus(this: FullPath) != 0;
  result = 0;
  if ( !v7 )
    return TRANSCODE_MELEE_REPOSITION_DONE;
  return result;
}


// ========================================================================
// ??0idMeleeFSM@@QAA@XZ
// EA  : 0x82ADA4A0
// RVA : 0x00ADA4A0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_melee.cpp
// ========================================================================

idMeleeFSM *__fastcall idMeleeFSM::idMeleeFSM(idMeleeFSM *this)
{
  idFiniteStateMachine::idFiniteStateMachine(this, name: "FSM_melee");
  this->__vftable = (idMeleeFSM_vtbl *)&idMeleeFSM::`vftable';
  idState::idState(this: &this->stateDefault, stateType: &idMelee_Default::Type, childFSMType: nullptr, flags: 0);
  this->stateDefault.__vftable = (idMelee_Default_vtbl *)&idMelee_Default::`vftable';
  idState::idState(this: &this->stateAttack, stateType: &idMelee_Attack::Type, childFSMType: nullptr, flags: 0);
  this->stateAttack.__vftable = (idMelee_Attack_vtbl *)&idMelee_Attack::`vftable';
  idState::idState(this: &this->stateReposition, stateType: &idMelee_Reposition::Type, childFSMType: nullptr, flags: 0);
  this->stateReposition.__vftable = (idMelee_Reposition_vtbl *)&idMelee_Reposition::`vftable';
  idFiniteStateMachine::SetDefaultState(this, state: &this->stateDefault);
  return this;
}


// ========================================================================
// __unwind$487768
// EA  : 0x82ADA55C
// RVA : 0x00ADA55C
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_melee.cpp
// ========================================================================

void _unwind_487768()
{
  int v0; // r12

  idAIFSM::~idAIFSM(this: *(idAIFSM **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$487769
// EA  : 0x82ADA584
// RVA : 0x00ADA584
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_melee.cpp
// ========================================================================

void _unwind_487769()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 108));
}


// ========================================================================
// __unwind$487770
// EA  : 0x82ADA5B0
// RVA : 0x00ADA5B0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_melee.cpp
// ========================================================================

void _unwind_487770()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 136));
}


// ========================================================================
// __unwind$487771
// EA  : 0x82ADA5DC
// RVA : 0x00ADA5DC
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_melee.cpp
// ========================================================================

void _unwind_487771()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 164));
}


// ========================================================================
// ??1idMeleeFSM@@UAA@XZ
// EA  : 0x82ADA610
// RVA : 0x00ADA610
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_melee.cpp
// ========================================================================

void __fastcall idMeleeFSM::~idMeleeFSM(idMeleeFSM *this)
{
  this->__vftable = (idMeleeFSM_vtbl *)&idMeleeFSM::`vftable';
  idState::~idState(this: &this->stateReposition);
  idState::~idState(this: &this->stateAttack);
  idState::~idState(this: &this->stateDefault);
  idFiniteStateMachine::~idFiniteStateMachine(this);
}


// ========================================================================
// __unwind$487841
// EA  : 0x82ADA674
// RVA : 0x00ADA674
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_melee.cpp
// ========================================================================

void _unwind_487841()
{
  int v0; // r12

  idAIFSM::~idAIFSM(this: *(idAIFSM **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$487842
// EA  : 0x82ADA69C
// RVA : 0x00ADA69C
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_melee.cpp
// ========================================================================

void _unwind_487842()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 108));
}


// ========================================================================
// __unwind$487843
// EA  : 0x82ADA6C8
// RVA : 0x00ADA6C8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_melee.cpp
// ========================================================================

void _unwind_487843()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 136));
}


// ========================================================================
// ?Evaluate@MELEE_NoTarget@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82ADA758
// RVA : 0x00ADA758
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_melee.cpp
// ========================================================================

int __fastcall MELEE_NoTarget::Evaluate(
        MELEE_NoTarget *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  int value; // r8
  idEntity *v7; // r3
  idEntity *v8; // r3
  idEntity *v9; // r31

  value = ai->aiVolatile.memory.currentEnemy.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v7 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr
    && (v8 = idEntity::CastTo(c: v7), v9 = v8, v8 != nullptr)
    && idAIWorldState::StateForEntity(this: &ai->aiVolatile.world.worldState, ent: v8) != nullptr )
  {
    return !v9->IsDead(this: v9) ? 0 : 0x164;
  }
  else
  {
    return 356;
  }
}


// ========================================================================
// ?Evaluate@MELEE_TargetOutOfRange@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82ADA820
// RVA : 0x00ADA820
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_melee.cpp
// ========================================================================

int __fastcall MELEE_TargetOutOfRange::Evaluate(
        MELEE_TargetOutOfRange *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  int value; // r8
  idEntity *v7; // r3
  idEntity *v8; // r3
  idTurret *v9; // r30
  idAIEntityState *v11; // r3
  idTurret *v12; // r4
  aiSenseState_t *v13; // r30
  int v14; // r29
  idVec3 *p_velocity; // r28
  const aiPhysicalState_t *ConfirmedPhysicalSafe; // r3
  aiMelee_t MeleeTypeForTarget; // r29
  const aiPhysicalState_t *v18; // r3

  value = ai->aiVolatile.memory.currentEnemy.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] != value >> 13 )
    return 0;
  v7 = gameLocal->entities.ptr[value & 0x1FFF];
  if ( v7 == nullptr )
    return 0;
  v8 = idEntity::CastTo(c: v7);
  v9 = (idTurret *)v8;
  if ( v8 == nullptr )
    return 0;
  v11 = idAIWorldState::StateForEntity(this: &ai->aiVolatile.world.worldState, ent: v8);
  if ( v11 == nullptr )
    return 0;
  v12 = v9;
  v13 = v11->senses.ptr[v11->lastSense];
  v14 = idAI2::MeleePreference(this: ai, target: v12);
  p_velocity = &aiSenseState_t::GetConfirmedPhysicalSafe(this: v13)->velocity;
  ConfirmedPhysicalSafe = aiSenseState_t::GetConfirmedPhysicalSafe(this: v13);
  MeleeTypeForTarget = idAI2::GetMeleeTypeForTarget(
                         this: ai,
                         targetPos: &ConfirmedPhysicalSafe->origin,
                         targetVel: p_velocity,
                         meleeMask: -1,
                         preferredMask: v14);
  v18 = aiSenseState_t::GetConfirmedPhysicalSafe(this: v13);
  return (unsigned __int8)idAI2::IsTargetInMeleeRange(this: ai, targetPos: &v18->origin, meleeType: MeleeTypeForTarget) != 0
       ? 0
       : 0x161;
}


// ========================================================================
// ?Evaluate@MELEE_Attack@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82ADA930
// RVA : 0x00ADA930
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_melee.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall MELEE_Attack::Evaluate(
        MELEE_Attack *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  int value; // r8
  idEntity *v7; // r3
  idEntity *v8; // r4
  idAIEntityState *v9; // r3
  const aiPhysicalState_t *ConfirmedPhysicalSafe; // r3
  idAIStateTransition::aiTransCode_t result; // r3
  bool v12; // zf

  if ( idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) < ai->aiVolatile.memory.nextCloseMeleeTime )
    return 0;
  value = ai->aiVolatile.memory.currentEnemy.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] != value >> 13 )
    return 0;
  v7 = gameLocal->entities.ptr[value & 0x1FFF];
  if ( v7 == nullptr )
    return 0;
  v8 = idEntity::CastTo(c: v7);
  if ( v8 == nullptr )
    return 0;
  v9 = idAIWorldState::StateForEntity(this: &ai->aiVolatile.world.worldState, ent: v8);
  if ( v9 == nullptr )
    return 0;
  ConfirmedPhysicalSafe = aiSenseState_t::GetConfirmedPhysicalSafe(this: v9->senses.ptr[v9->lastSense]);
  v12 = (unsigned __int8)idAI2::IsTargetInMeleeRange(
                           this: ai,
                           targetPos: &ConfirmedPhysicalSafe->origin,
                           meleeType: AIMELEE_ALL) != 0;
  result = TRANSCODE_MELEE_ATTACK;
  if ( !v12 )
    return 0;
  return result;
}


// ========================================================================
// ?AIState_EnterState@idMelee_Attack@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82ADAA20
// RVA : 0x00ADAA20
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_melee.cpp
// ========================================================================

void __fastcall idMelee_Attack::AIState_EnterState(idMelee_Attack *this, idAI2 *ai, idEventArg *fsm, const int curTime)
{
  const idDeclAIBehavior *decl; // r28
  int minCloseMeleeInterval; // r9
  int maxCloseMeleeInterval; // r8
  signed int v10; // r11
  int v11; // r11
  unsigned int seed; // r8
  unsigned int v13; // r4
  int v14; // r3
  unsigned int v15; // r4
  int value; // r3
  idEntity *v17; // r3
  idEntity *v18; // r3
  idTurret *v19; // r30
  idAIEntityState *v20; // r11
  idTurret *v21; // r4
  aiSenseState_t *v22; // r30
  int v23; // r29
  idVec3 *p_velocity; // r21
  const aiPhysicalState_t *ConfirmedPhysicalSafe; // r3
  aiMelee_t MeleeTypeForTarget; // r29
  const aiPhysicalState_t *v27; // r3
  overrideAnim_t v28; // r30
  idEventArg *v29; // r22
  unsigned int v30; // r4
  int GameMs; // r3
  _BYTE v32[20]; // [sp+70h] [-140h] BYREF
  _BYTE v33[20]; // [sp+90h] [-120h] BYREF
  float v34[5]; // [sp+B0h] [-100h] BYREF
  _DWORD v35[5]; // [sp+D0h] [-E0h] BYREF
  int v36; // [sp+F0h] [-C0h]
  overrideAnim_t v37; // [sp+F4h] [-BCh]
  const idEventArg *v38; // [sp+F8h] [-B8h]
  idEventArg v39; // [sp+110h] [-A0h] BYREF
  idEventReceiver v40[10]; // [sp+130h] [-80h] BYREF

  decl = ai->aiEditable.behaviors.decl;
  minCloseMeleeInterval = decl->minCloseMeleeInterval;
  maxCloseMeleeInterval = decl->maxCloseMeleeInterval;
  v10 = maxCloseMeleeInterval - minCloseMeleeInterval;
  if ( maxCloseMeleeInterval == minCloseMeleeInterval )
  {
    v11 = 0;
  }
  else
  {
    seed = clientGame->random.seed;
    __twllei(v10, 0);
    v13 = 1664525 * seed + 1013904223;
    clientGame->random.seed = v13;
    v14 = (v13 >> 10) & 0x7FFF;
    v15 = v10 & ~(__ROL4__(v14, 1) - 1);
    v11 = v14 % v10;
    __twlgei(v15, 0xFFFFFFFF);
  }
  ai->aiVolatile.memory.nextCloseMeleeTime = v11 + minCloseMeleeInterval + curTime;
  idAIFireControl::SetFireMode(this: ai->aiVolatile.fireControl, owner: ai, mode: FIREMODE_HOLDFIRE);
  ai->aiVolatile.fireControl->allowReloads = false;
  value = ai->aiVolatile.memory.currentEnemy.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] != value >> 13 )
    goto LABEL_8;
  v17 = gameLocal->entities.ptr[value & 0x1FFF];
  if ( v17 == nullptr )
    goto LABEL_8;
  v18 = idEntity::CastTo(c: v17);
  v19 = (idTurret *)v18;
  if ( v18 == nullptr )
    goto LABEL_8;
  v20 = idAIWorldState::StateForEntity(this: &ai->aiVolatile.world.worldState, ent: v18);
  if ( v20 == nullptr )
    goto LABEL_8;
  v21 = v19;
  v22 = v20->senses.ptr[v20->lastSense];
  v23 = idAI2::MeleePreference(this: ai, target: v21);
  p_velocity = &aiSenseState_t::GetConfirmedPhysicalSafe(this: v22)->velocity;
  ConfirmedPhysicalSafe = aiSenseState_t::GetConfirmedPhysicalSafe(this: v22);
  MeleeTypeForTarget = idAI2::GetMeleeTypeForTarget(
                         this: ai,
                         targetPos: &ConfirmedPhysicalSafe->origin,
                         targetVel: p_velocity,
                         meleeMask: -1,
                         preferredMask: v23);
  if ( MeleeTypeForTarget != AIMELEE_NONE
    && (v27 = aiSenseState_t::GetConfirmedPhysicalSafe(this: v22),
        (unsigned __int8)idAI2::IsTargetInMeleeRange(this: ai, targetPos: &v27->origin, meleeType: MeleeTypeForTarget) != 0)
    && (!idActor::IsCrouching(this: ai) || (MeleeTypeForTarget & 0x1E00) != 0) )
  {
    v28 = AIMeleeTypeToOverrideAnim(meleeType: MeleeTypeForTarget);
    if ( v28 != ANIMOVERRIDE_NONE )
    {
      idAI2::EndActionScript(this: ai);
      LODWORD(fsm[1].value.v[2]) = this;
      v37 = v28;
      v35[1] = 0;
      HIBYTE(v35[0]) = 105;
      v34[1] = vec3_origin.x;
      HIBYTE(v34[0]) = 118;
      HIBYTE(v36) = 105;
      v34[3] = vec3_origin.z;
      v34[2] = vec3_origin.y;
      v29 = idEventArg::idEventArg(this: &v39, data: ai);
      memcpy(Dst: v33, Src: v34, Size: sizeof(v33));
      memcpy(Dst: v32, Src: v35, Size: sizeof(v32));
      idEventReceiver::ProcessEvent(
        this: v40,
        result: fsm,
        ev: *(const idEventDef **)&v29->type,
        arg1: (const idEventArg *)LODWORD(v29->value.v[1]),
        arg2: (const idEventArg *)LODWORD(v29->value.v[2]),
        arg3: (const idEventArg *)__ROL4__(v36, 32),
        arg4: v38);
    }
    v30 = 1664525 * clientGame->random.seed + 1013904223;
    clientGame->random.seed = v30;
    if ( (signed int)(((v30 >> 10) & 0x7FFF) % 0x64) < decl->rageBehaviors.angryRageAfterMissingChance )
    {
      GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      idAIMemory::SetWantAngryRageTime(this: &ai->aiVolatile.memory, t: GameMs, debugReason: "miss enemy");
    }
  }
  else
  {
LABEL_8:
    idState::SetEnterFailed(this, failed: true);
  }
}


// ========================================================================
// ?AIState_EnterState@idMelee_Reposition@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82ADAD40
// RVA : 0x00ADAD40
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_melee.cpp
// ========================================================================

void __fastcall idMelee_Reposition::AIState_EnterState(
        idMelee_Reposition *this,
        idAI2 *ai,
        idEventArg *fsm,
        const int curTime)
{
  int value; // r8
  idEntity *v9; // r3
  idEntity *v10; // r4
  idAIEntityState *v11; // r3
  const idDeclAIBehavior *decl; // r10
  int minMeleeDodgeInterval; // r7
  int maxMeleeDodgeInterval; // r11
  aiSenseState_t *v15; // r30
  __int64 v16; // r11
  unsigned int seed; // r5
  signed int v18; // r5
  unsigned int v19; // r4
  unsigned int v20; // r7
  double v21; // fp31
  const aiPhysicalState_t *ConfirmedPhysicalSafe; // r3
  aiDirection_t DirectionTo; // r28
  int v24; // r29
  idPhysics *Physics; // r25
  idVec3 *p_velocity; // r24
  float *v27; // r3
  double v28; // fp30
  double v29; // fp29
  double v30; // fp28
  idPhysics *v31; // r25
  const aiPhysicalState_t *v32; // r24
  float *v33; // r3
  const aiPhysicalState_t *v34; // r3
  char v35; // r11
  idEventArg *v36; // r3
  __int64 v37; // [sp+70h] [-C0h] BYREF
  idEventArg v38; // [sp+90h] [-A0h] BYREF
  idEventReceiver v39[4]; // [sp+B0h] [-80h] BYREF

  value = ai->aiVolatile.memory.currentEnemy.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] != value >> 13
    || (v9 = gameLocal->entities.ptr[value & 0x1FFF]) == nullptr
    || (v10 = idEntity::CastTo(c: v9)) == nullptr
    || (v11 = idAIWorldState::StateForEntity(this: &ai->aiVolatile.world.worldState, ent: v10)) == nullptr )
  {
    idState::SetEnterFailed(this, failed: true);
    return;
  }
  decl = ai->aiEditable.behaviors.decl;
  minMeleeDodgeInterval = decl->minMeleeDodgeInterval;
  maxMeleeDodgeInterval = decl->maxMeleeDodgeInterval;
  HIDWORD(v16) = 1013904223;
  v15 = v11->senses.ptr[v11->lastSense];
  LODWORD(v16) = maxMeleeDodgeInterval - minMeleeDodgeInterval;
  if ( (_DWORD)v16 != 0 )
  {
    seed = clientGame->random.seed;
    __twllei(v16, 0);
    clientGame->random.seed = 1664525 * seed + 1013904223;
    v18 = ((1664525 * seed + 1013904223) >> 10) & 0x7FFF;
    v19 = v16 & ~(__ROL4__(v18, 1) - 1);
    LODWORD(v16) = v18 % (int)v16;
    __twlgei(v19, 0xFFFFFFFF);
  }
  else
  {
    LODWORD(v16) = 0;
  }
  ai->aiVolatile.memory.nextDodgeTime = v16 + minMeleeDodgeInterval + curTime;
  v20 = 1664525 * clientGame->random.seed;
  clientGame->random.seed = v20 + 1013904223;
  LODWORD(v16) = ((v20 + 1013904223) >> 10) & 0x7FFF;
  v37 = v16;
  v21 = (float)((float)v16 * (float)0.000030518509);
  ConfirmedPhysicalSafe = aiSenseState_t::GetConfirmedPhysicalSafe(this: v15);
  DirectionTo = idAI2::GetDirectionTo(this: ai, pos: &ConfirmedPhysicalSafe->origin);
  v24 = 1;
  Physics = idEntity::GetPhysics(this: ai);
  p_velocity = &aiSenseState_t::GetConfirmedPhysicalSafe(this: v15)->velocity;
  v27 = (float *)Physics->GetLinearVelocity(this: (idPhysics *)&v37, result: (idVec3 *)Physics, a3: 0);
  v28 = (float)(*v27 - p_velocity->x);
  v29 = (float)(v27[1] - p_velocity->y);
  v30 = (float)(v27[2] - p_velocity->z);
  v31 = idEntity::GetPhysics(this: ai);
  v32 = aiSenseState_t::GetConfirmedPhysicalSafe(this: v15);
  v33 = (float *)v31->GetOrigin(this: v31, a2: 0);
  if ( (float)((float)((float)(*v33 - v32->origin.x) * (float)v28)
             + (float)((float)((float)(v33[2] - v32->origin.z) * (float)v30)
                     + (float)((float)(v33[1] - v32->origin.y) * (float)v29))) > 0.0
    || (v34 = aiSenseState_t::GetConfirmedPhysicalSafe(this: v15),
        v35 = 1,
        ((LODWORD(v34->velocity.z) | LODWORD(v34->velocity.y) | LODWORD(v34->velocity.x)) & 0x7FFFFFFF) == 0) )
  {
    v35 = 0;
  }
  if ( DirectionTo == AIDIR_FRONT )
  {
    if ( v21 > 0.5 )
      goto LABEL_14;
LABEL_22:
    v24 = 2;
    goto LABEL_23;
  }
  if ( DirectionTo != AIDIR_FRONT_LEFT )
  {
    if ( DirectionTo != AIDIR_FRONT_RIGHT )
      goto LABEL_23;
    if ( v35 != 0 )
    {
      v24 = 4;
      if ( v21 < 1.0 )
        goto LABEL_23;
    }
    goto LABEL_22;
  }
  if ( v35 != 0 && v21 < 1.0 )
  {
    v24 = 4;
    goto LABEL_23;
  }
LABEL_14:
  v24 = 3;
LABEL_23:
  idAI2::EndActionScript(this: ai);
  LODWORD(fsm[1].value.v[2]) = this;
  LODWORD(v37) = v24;
  HIBYTE(v37) = 105;
  v36 = idEventArg::idEventArg(this: &v38, data: ai);
  idEventReceiver::ProcessEvent(
    this: v39,
    result: fsm,
    ev: *(const idEventDef **)&v36->type,
    arg1: (const idEventArg *)LODWORD(v36->value.v[1]),
    arg2: (const idEventArg *)LODWORD(v36->value.v[2]));
}


// ========================================================================
// ?CanUse@idMeleeFSM@@UBA_NPAVidFiniteStateMachine@@H@Z
// EA  : 0x82ADB0B8
// RVA : 0x00ADB0B8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_melee.cpp
// ========================================================================

BOOL __fastcall idMeleeFSM::CanUse(idMeleeFSM *this, idFiniteStateMachine *fsm, const int curTime)
{
  idAI2 *Owner; // r3
  idAI2 *v4; // r3
  idAI2 *v5; // r30
  int value; // r8
  idEntity *v7; // r3
  idEntity *v8; // r3
  idTurret *v9; // r31
  idAIEntityState *v10; // r3
  idTurret *v11; // r4
  aiSenseState_t *v12; // r31
  int v13; // r29
  idVec3 *p_velocity; // r28
  const aiPhysicalState_t *ConfirmedPhysicalSafe; // r3
  aiMelee_t MeleeTypeForTarget; // r29
  const aiPhysicalState_t *v17; // r3

  Owner = (idAI2 *)idFiniteStateMachine::GetOwner(this: fsm);
  v4 = idAI2::CastTo(c: Owner);
  v5 = v4;
  if ( (*((_BYTE *)v4->aiEditable.behaviors.decl + 196) & 4) == 0 )
    return false;
  if ( idAI2::GetValidMeleeTypes(this: v4, mask: 2) == 0 )
    return false;
  value = v5->aiVolatile.memory.currentEnemy.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] != value >> 13 )
    return false;
  v7 = gameLocal->entities.ptr[value & 0x1FFF];
  if ( v7 == nullptr )
    return false;
  v8 = idEntity::CastTo(c: v7);
  v9 = (idTurret *)v8;
  if ( v8 == nullptr )
    return false;
  v10 = idAIWorldState::StateForEntity(this: &v5->aiVolatile.world.worldState, ent: v8);
  if ( v10 == nullptr )
    return false;
  v11 = v9;
  v12 = v10->senses.ptr[v10->lastSense];
  v13 = idAI2::MeleePreference(this: v5, target: v11);
  p_velocity = &aiSenseState_t::GetConfirmedPhysicalSafe(this: v12)->velocity;
  ConfirmedPhysicalSafe = aiSenseState_t::GetConfirmedPhysicalSafe(this: v12);
  MeleeTypeForTarget = idAI2::GetMeleeTypeForTarget(
                         this: v5,
                         targetPos: &ConfirmedPhysicalSafe->origin,
                         targetVel: p_velocity,
                         meleeMask: -1,
                         preferredMask: v13);
  if ( MeleeTypeForTarget == AIMELEE_NONE )
    return false;
  v17 = aiSenseState_t::GetConfirmedPhysicalSafe(this: v12);
  return (unsigned __int8)idAI2::IsTargetInMeleeRange(this: v5, targetPos: &v17->origin, meleeType: MeleeTypeForTarget) != 0;
}

