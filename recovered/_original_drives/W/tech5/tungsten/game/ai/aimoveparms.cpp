
// ========================================================================
// ?GetRelevantGoalOrigin@idAIMoveParms@@QBAABVidVec3@@PBVidAI2@@@Z
// EA  : 0x82A54D98
// RVA : 0x00A54D98
// PDB : w:\tech5\tungsten\game\ai\aimoveparms.cpp
// ========================================================================

const aiPhysicalState_t *__fastcall idAIMoveParms::GetRelevantGoalOrigin(idAIMoveParms *this, const idAI2 *ai)
{
  int value; // r10
  idEntity *v5; // r3
  idEntity *v6; // r3
  idEntity *v7; // r31
  idAIEntityState *v9; // r3
  aiSenseState_t *v10; // r3
  idPhysics *Physics; // r3

  value = this->goalEntity.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] != value >> 13 )
    return (const aiPhysicalState_t *)&this->goalOrigin;
  v5 = gameLocal->entities.ptr[value & 0x1FFF];
  if ( v5 == nullptr )
    return (const aiPhysicalState_t *)&this->goalOrigin;
  v6 = idEntity::CastTo(c: v5);
  v7 = v6;
  if ( v6 == nullptr )
    return (const aiPhysicalState_t *)&this->goalOrigin;
  v9 = idAIWorldState::StateForEntity(this: &ai->aiVolatile.world.worldState, ent: v6);
  if ( v9 != nullptr )
  {
    v10 = v9->senses.ptr[v9->lastSense];
    if ( v10->lastUnconfirmedStimTime >= 0 )
      return aiSenseState_t::GetConfirmedPhysicalSafe(this: v10);
  }
  Physics = idEntity::GetPhysics(this: v7);
  return (const aiPhysicalState_t *)Physics->GetOrigin(this: Physics, a2: 0);
}


// ========================================================================
// ??0idAIMoveParms@@QAA@XZ
// EA  : 0x82A54E68
// RVA : 0x00A54E68
// PDB : w:\tech5\tungsten\game\ai\aimoveparms.cpp
// ========================================================================

idAIMoveParms *__fastcall idAIMoveParms::idAIMoveParms(idAIMoveParms *this)
{
  this->moveReason = AIMOVEREASON_UNKNOWN;
  this->startOrigin.x = 0.0;
  this->startOrigin.y = 0.0;
  this->startOrigin.z = 0.0;
  this->goalOrigin.x = 0.0;
  this->goalOrigin.y = 0.0;
  this->goalOrigin.z = 0.0;
  this->goalEntity.spawnId.value = 0x1FFF;
  this->goalOrientation = quat_identity;
  this->goalScenePoint.spawnId.value = 0x1FFF;
  this->goalTolerance = 0.1;
  this->intermediateTolerance = 0.1;
  this->arrivalPosture = POSTURE_STANDING;
  this->arrivalAction = AIARRIVAL_UNKNOWN;
  this->flags = 0;
  this->sourceSubWeb.value = -1;
  this->sourceState.value = -1;
  this->destSubWeb.value = -1;
  this->destState.value = -1;
  return this;
}


// ========================================================================
// ?Init@idAIMoveParms@@QAAXW4aiMoveReason_t@@ABVidVec3@@1PBVidEntity@@ABVidQuat@@PBVidScenePoint@@MMW4aiArrivalAction_t@@W4posture_t@@HABV?$idIndex@FW4invalidSubWebIndex_t@idDeclAnimWeb@@@@ABV?$idIndex@FW4invalidStateIndex_t@idDeclAnimWeb@@@@78@Z
// EA  : 0x82A54F00
// RVA : 0x00A54F00
// PDB : w:\tech5\tungsten\game\ai\aimoveparms.cpp
// ========================================================================

void __fastcall idAIMoveParms::Init(
        idAIMoveParms *this,
        aiMoveReason_t moveReason_,
        const idVec3 *startOrigin_,
        const idVec3 *goalOrigin_,
        const idEntity *goalEntity_,
        const idQuat *goalOrientation_,
        const idScenePoint *goalScenePoint_,
        double goalTolerance_,
        double intermediateTolerance_,
        const aiArrivalAction_t arrivalAction_,
        const posture_t arrivalPosture_,
        const int flags_,
        const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *sourceSubWeb_,
        const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *sourceState_,
        const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *destSubWeb_,
        const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *destState_,
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
        aiArrivalAction_t a32,
        int a33,
        posture_t a34,
        int a35,
        int a36,
        int a37,
        __int16 *a38,
        int a39,
        __int16 *arrivalAction__0,
        int a41,
        __int16 *arrivalPosture_a,
        int a43,
        __int16 *flags_a)
{
  this->moveReason = moveReason_;
  this->startOrigin = *startOrigin_;
  this->goalOrigin = *goalOrigin_;
  if ( goalEntity_ != nullptr )
    this->goalEntity.spawnId.value = (gameLocal->spawnIds.ptr[goalEntity_->entityNumber] << 13)
                                   | goalEntity_->entityNumber;
  else
    this->goalEntity.spawnId.value = 0x1FFF;
  this->goalOrientation = *goalOrientation_;
  if ( goalScenePoint_ != nullptr )
    this->goalScenePoint.spawnId.value = (gameLocal->spawnIds.ptr[goalScenePoint_->entityNumber] << 13)
                                       | goalScenePoint_->entityNumber;
  else
    this->goalScenePoint.spawnId.value = 0x1FFF;
  this->goalTolerance = goalTolerance_;
  this->intermediateTolerance = intermediateTolerance_;
  this->arrivalPosture = a34;
  this->arrivalAction = a32;
  this->flags = a36;
  this->sourceSubWeb.value = *a38;
  this->sourceState.value = *arrivalAction__0;
  this->destSubWeb.value = *arrivalPosture_a;
  this->destState.value = *flags_a;
}

