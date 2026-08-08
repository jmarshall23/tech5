
// ========================================================================
// ?InternalInitState@idBackStand_Default@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AC3688
// RVA : 0x00AC3688
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_backstand.cpp
// ========================================================================

void __fastcall idBackStand_Default::InternalInitState(idBackStand_Default *this, const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(this, fsm, transType: &BACKSTAND_ShouldReturn::Type, nextStateType: &idAIStateDone::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &BACKSTAND_ShouldMove::Type,
    nextStateType: &idBackStand_Moving::Type);
}


// ========================================================================
// ?InternalInitState@idBackStand_Moving@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AC36F0
// RVA : 0x00AC36F0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_backstand.cpp
// ========================================================================

void __fastcall idBackStand_Moving::InternalInitState(idBackStand_Moving *this, const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(this, fsm, transType: &BACKSTAND_ShouldReturn::Type, nextStateType: &idAIStateDone::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &BACKSTAND_ShouldOutOfReach::Type,
    nextStateType: &idBackStand_OutOfReach::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &BACKSTAND_ShouldRise::Type,
    nextStateType: &idBackStand_Rising::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &BACKSTAND_MoveDone::Type,
    nextStateType: &idBackStand_Default::Type);
}


// ========================================================================
// ?InternalInitState@idBackStand_OutOfReach@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AC3790
// RVA : 0x00AC3790
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_backstand.cpp
// ========================================================================

void __fastcall idBackStand_OutOfReach::InternalInitState(
        idBackStand_OutOfReach *this,
        const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(this, fsm, transType: &BACKSTAND_ShouldReturn::Type, nextStateType: &idAIStateDone::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &BACKSTAND_ShouldChangeHint::Type,
    nextStateType: &idBackStand_Moving::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &BACKSTAND_ShouldAttack::Type,
    nextStateType: &idBackStand_Rising::Type);
}


// ========================================================================
// ?InternalInitState@idBackStand_Rising@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AC3810
// RVA : 0x00AC3810
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_backstand.cpp
// ========================================================================

void __fastcall idBackStand_Rising::InternalInitState(idBackStand_Rising *this, const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(
    this,
    fsm,
    transType: &BACKSTAND_AnimDone::Type,
    nextStateType: &idBackStand_Standing::Type);
}


// ========================================================================
// ?InternalInitState@idBackStand_Standing@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AC3828
// RVA : 0x00AC3828
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_backstand.cpp
// ========================================================================

void __fastcall idBackStand_Standing::InternalInitState(idBackStand_Standing *this, const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(
    this,
    fsm,
    transType: &BACKSTAND_ShouldReturn::Type,
    nextStateType: &idBackStand_Lowering::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &BACKSTAND_ShouldAttack::Type,
    nextStateType: &idBackStand_Attacking::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &BACKSTAND_ShouldOutOfReachFromLedge::Type,
    nextStateType: &idBackStand_OutOfReach::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &BACKSTAND_ShouldLower::Type,
    nextStateType: &idBackStand_Lowering::Type);
}


// ========================================================================
// ?InternalInitState@idBackStand_Attacking@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AC38B0
// RVA : 0x00AC38B0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_backstand.cpp
// ========================================================================

void __fastcall idBackStand_Attacking::InternalInitState(idBackStand_Attacking *this, const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(this, fsm, transType: &BACKSTAND_ShouldReturn::Type, nextStateType: &idAIStateDone::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &BACKSTAND_AnimDone::Type,
    nextStateType: &idBackStand_Standing::Type);
}


// ========================================================================
// ?InternalInitState@idBackStand_Lowering@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AC3918
// RVA : 0x00AC3918
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_backstand.cpp
// ========================================================================

void __fastcall idBackStand_Lowering::InternalInitState(idBackStand_Lowering *this, const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(this, fsm, transType: &BACKSTAND_ShouldReturn::Type, nextStateType: &idAIStateDone::Type);
  idState::AddStateTransition(this, fsm, transType: &BACKSTAND_Done::Type, nextStateType: &idBackStand_Default::Type);
}


// ========================================================================
// ?Evaluate@BACKSTAND_Error@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AC3980
// RVA : 0x00AC3980
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_backstand.cpp
// ========================================================================

int __fastcall BACKSTAND_Error::Evaluate(
        BACKSTAND_Error *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  return 349;
}


// ========================================================================
// ?Evaluate@BACKSTAND_Done@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AC3988
// RVA : 0x00AC3988
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_backstand.cpp
// ========================================================================

int __fastcall BACKSTAND_Done::Evaluate(
        BACKSTAND_Done *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  return 456;
}


// ========================================================================
// ?InitStates@idBackStandFSM@@UAAXABVidFiniteStateMachineParams@@@Z
// EA  : 0x82AC3990
// RVA : 0x00AC3990
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_backstand.cpp
// ========================================================================

void __fastcall idBackStandFSM::InitStates(idBackStandFSM *this, const idFiniteStateMachineParams *params)
{
  idAIFSM::InitStates(this, params);
  this->AddState(this, a2: &this->stateDefault);
  this->AddState(this, a2: &this->stateMoving);
  this->AddState(this, a2: &this->stateOutOfReach);
  this->AddState(this, a2: &this->stateRising);
  this->AddState(this, a2: &this->stateStanding);
  this->AddState(this, a2: &this->stateAttacking);
  this->AddState(this, a2: &this->stateLowering);
}


// ========================================================================
// ?Evaluate@BACKSTAND_MoveDone@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AC3A68
// RVA : 0x00AC3A68
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_backstand.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall BACKSTAND_MoveDone::Evaluate(
        BACKSTAND_MoveDone *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        XGRAPHICS::IRInst *state,
        const int curTime)
{
  idAIStateTransition::aiTransCode_t result; // r3
  idFiniteStateMachine *FullPath; // r3
  int v8; // r3
  idAIStateDone *v9; // r10

  if ( ai->aiVolatile.physics.moveState.GetMoveStatus(this: &ai->aiVolatile.physics.moveState) == 0 )
    return TRANSCODE_MAX;
  FullPath = (idFiniteStateMachine *)idFile_SaveGamePipelined::GetFullPath(this: state);
  if ( FullPath != nullptr && (unsigned __int8)idFiniteStateMachine::HadError(this: FullPath) != 0 )
    return TRANSCODE_MAX;
  v8 = idFile_SaveGamePipelined::GetFullPath(this: state);
  if ( v8 == 0 )
    return 0;
  v9 = *(idAIStateDone **)(v8 + 40);
  result = TRANSCODE_MAX;
  if ( v9 != gameLocal->doneState )
    return 0;
  return result;
}


// ========================================================================
// EntityPlaneDistance
// EA  : 0x82AC3B20
// RVA : 0x00AC3B20
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_backstand.cpp
// ========================================================================

float __fastcall EntityPlaneDistance(idEntity *entA, idEntity *entB)
{
  idPhysics *Physics; // r3
  idPhysics *v4; // r3
  float *v5; // r3
  double v6; // fp1
  float v8[4]; // [sp+50h] [-20h]

  Physics = idEntity::GetPhysics(this: entA);
  *(_QWORD *)v8 = *(_QWORD *)&Physics->GetOrigin(this: Physics, a2: 0)->x;
  v4 = idEntity::GetPhysics(this: entB);
  v5 = (float *)v4->GetOrigin(this: v4, a2: 0);
  v6 = __fsqrts((float)((float)((float)(v8[0] - *v5) * (float)(v8[0] - *v5))
                      + (float)((float)(v8[1] - v5[1]) * (float)(v8[1] - v5[1]))));
  return *((float *)&v6 + 1);
}


// ========================================================================
// GetHintRisePosition
// EA  : 0x82AC3BB8
// RVA : 0x00AC3BB8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_backstand.cpp
// ========================================================================

idVec3 *__fastcall GetHintRisePosition(idVec3 *result, idAI2 *ai, const idEntity *ent)
{
  const idDeclAIBehavior *decl; // r11
  double v7; // fp31
  double v8; // fp30
  double v9; // fp29
  idPhysics *Physics; // r3
  float *v11; // r3
  double v13; // fp2
  double v15; // fp13
  double v16; // fp10
  double v17; // fp2
  double v18; // fp13
  double v19; // fp12
  double v20; // fp0
  float y; // r10
  float x; // r9
  const idDeclAIBehavior *v23; // r11
  double v25; // fp9
  double v26; // fp8
  float v27; // [sp+50h] [-60h]
  float v28; // [sp+54h] [-5Ch]
  float v29; // [sp+58h] [-58h]
  float z; // [sp+68h] [-48h]

  decl = ai->aiEditable.behaviors.decl;
  v7 = (float)(ent->spawnPosition.x + (float)(ent->spawnOrientation.mat[0].x * decl->backstandBehaviors.approachDistance));
  v8 = (float)(ent->spawnPosition.y + (float)(ent->spawnOrientation.mat[0].y * decl->backstandBehaviors.approachDistance));
  v9 = (float)(ent->spawnPosition.z + (float)(ent->spawnOrientation.mat[0].z * decl->backstandBehaviors.approachDistance));
  Physics = idEntity::GetPhysics(this: ai);
  v11 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
  v29 = v11[2];
  v28 = v11[1];
  v27 = *v11;
  _FP9 = (float)((float)((float)((float)((float)v7 - v27) * (float)((float)v7 - v27))
                       + (float)((float)((float)((float)v9 - v29) * (float)((float)v9 - v29))
                               + (float)((float)((float)v8 - v28) * (float)((float)v8 - v28))))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  v13 = (float)((float)((float)((float)((float)v7 - v27) * (float)((float)v7 - v27))
                      + (float)((float)((float)((float)v9 - v29) * (float)((float)v9 - v29))
                              + (float)((float)((float)v8 - v28) * (float)((float)v8 - v28))))
              * (float)0.5);
  __asm { fsel      f1, f9, f10, f13 }
  v15 = __frsqrte(_FP1);
  v16 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v15
                                                                                      * (float)((float)((float)((float)((float)v7 - v27) * (float)((float)v7 - v27)) + (float)((float)((float)((float)v9 - v29) * (float)((float)v9 - v29)) + (float)((float)((float)v8 - v28) * (float)((float)v8 - v28))))
                                                                                              * (float)0.5))
                                                                              * (float)v15)
                                                                      - (float)1.5)
                                                      * (float)v15)
                                              * (float)((float)((float)((float)((float)v7 - v27)
                                                                      * (float)((float)v7 - v27))
                                                              + (float)((float)((float)((float)v9 - v29)
                                                                              * (float)((float)v9 - v29))
                                                                      + (float)((float)((float)v8 - v28)
                                                                              * (float)((float)v8 - v28))))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v15
                                                                              * (float)((float)((float)((float)((float)v7 - v27) * (float)((float)v7 - v27))
                                                                                              + (float)((float)((float)((float)v9 - v29) * (float)((float)v9 - v29)) + (float)((float)((float)v8 - v28) * (float)((float)v8 - v28))))
                                                                                      * (float)0.5))
                                                                      * (float)v15)
                                                              - (float)1.5)
                                              * (float)v15))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v15
                                                      * (float)((float)((float)((float)((float)v7 - v27)
                                                                              * (float)((float)v7 - v27))
                                                                      + (float)((float)((float)((float)v9 - v29)
                                                                                      * (float)((float)v9 - v29))
                                                                              + (float)((float)((float)v8 - v28)
                                                                                      * (float)((float)v8 - v28))))
                                                              * (float)0.5))
                                              * (float)v15)
                                      - (float)1.5)
                      * (float)v15));
  v17 = (float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v15 * (float)((float)((float)((float)((float)v7 - v27) * (float)((float)v7 - v27)) + (float)((float)((float)((float)v9 - v29) * (float)((float)v9 - v29)) + (float)((float)((float)v8 - v28) * (float)((float)v8 - v28)))) * (float)0.5)) * (float)v15) - (float)1.5)
                                                                                      * (float)v15)
                                                                              * (float)((float)((float)((float)((float)v7 - v27) * (float)((float)v7 - v27))
                                                                                              + (float)((float)((float)((float)v9 - v29) * (float)((float)v9 - v29)) + (float)((float)((float)v8 - v28) * (float)((float)v8 - v28))))
                                                                                      * (float)0.5))
                                                                      * (float)((float)-(float)((float)((float)((float)v15 * (float)((float)((float)((float)((float)v7 - v27) * (float)((float)v7 - v27)) + (float)((float)((float)((float)v9 - v29) * (float)((float)v9 - v29)) + (float)((float)((float)v8 - v28) * (float)((float)v8 - v28)))) * (float)0.5)) * (float)v15)
                                                                                              - (float)1.5)
                                                                              * (float)v15))
                                                              - (float)1.5)
                                              * (float)((float)-(float)((float)((float)((float)v15
                                                                                      * (float)((float)((float)((float)((float)v7 - v27) * (float)((float)v7 - v27)) + (float)((float)((float)((float)v9 - v29) * (float)((float)v9 - v29)) + (float)((float)((float)v8 - v28) * (float)((float)v8 - v28))))
                                                                                              * (float)0.5))
                                                                              * (float)v15)
                                                                      - (float)1.5)
                                                      * (float)v15))
                                      * (float)v13)
                              * (float)v16)
                      - (float)1.5);
  v19 = (float)((float)((float)v9 - v29)
              * (float)((float)v17
                      * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v15 * (float)((float)((float)((float)((float)v7 - v27) * (float)((float)v7 - v27)) + (float)((float)((float)((float)v9 - v29) * (float)((float)v9 - v29)) + (float)((float)((float)v8 - v28) * (float)((float)v8 - v28)))) * (float)0.5))
                                                                                              * (float)v15)
                                                                                      - (float)1.5)
                                                                      * (float)v15)
                                                              * (float)((float)((float)((float)((float)v7 - v27)
                                                                                      * (float)((float)v7 - v27))
                                                                              + (float)((float)((float)((float)v9 - v29)
                                                                                              * (float)((float)v9 - v29))
                                                                                      + (float)((float)((float)v8 - v28)
                                                                                              * (float)((float)v8 - v28))))
                                                                      * (float)0.5))
                                                      * (float)((float)-(float)((float)((float)((float)v15
                                                                                              * (float)((float)((float)((float)((float)v7 - v27) * (float)((float)v7 - v27)) + (float)((float)((float)((float)v9 - v29) * (float)((float)v9 - v29)) + (float)((float)((float)v8 - v28) * (float)((float)v8 - v28)))) * (float)0.5))
                                                                                      * (float)v15)
                                                                              - (float)1.5)
                                                              * (float)v15))
                                              - (float)1.5)
                              * (float)((float)-(float)((float)((float)((float)v15
                                                                      * (float)((float)((float)((float)((float)v7 - v27)
                                                                                              * (float)((float)v7 - v27))
                                                                                      + (float)((float)((float)((float)v9 - v29) * (float)((float)v9 - v29))
                                                                                              + (float)((float)((float)v8 - v28) * (float)((float)v8 - v28))))
                                                                              * (float)0.5))
                                                              * (float)v15)
                                                      - (float)1.5)
                                      * (float)v15))));
  v20 = (float)((float)((float)v7 - v27)
              * (float)((float)v17
                      * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v15 * (float)((float)((float)((float)((float)v7 - v27) * (float)((float)v7 - v27)) + (float)((float)((float)((float)v9 - v29) * (float)((float)v9 - v29)) + (float)((float)((float)v8 - v28) * (float)((float)v8 - v28)))) * (float)0.5))
                                                                                              * (float)v15)
                                                                                      - (float)1.5)
                                                                      * (float)v15)
                                                              * (float)((float)((float)((float)((float)v7 - v27)
                                                                                      * (float)((float)v7 - v27))
                                                                              + (float)((float)((float)((float)v9 - v29)
                                                                                              * (float)((float)v9 - v29))
                                                                                      + (float)((float)((float)v8 - v28)
                                                                                              * (float)((float)v8 - v28))))
                                                                      * (float)0.5))
                                                      * (float)((float)-(float)((float)((float)((float)v15
                                                                                              * (float)((float)((float)((float)((float)v7 - v27) * (float)((float)v7 - v27)) + (float)((float)((float)((float)v9 - v29) * (float)((float)v9 - v29)) + (float)((float)((float)v8 - v28) * (float)((float)v8 - v28)))) * (float)0.5))
                                                                                      * (float)v15)
                                                                              - (float)1.5)
                                                              * (float)v15))
                                              - (float)1.5)
                              * (float)((float)-(float)((float)((float)((float)v15
                                                                      * (float)((float)((float)((float)((float)v7 - v27)
                                                                                              * (float)((float)v7 - v27))
                                                                                      + (float)((float)((float)((float)v9 - v29) * (float)((float)v9 - v29))
                                                                                              + (float)((float)((float)v8 - v28) * (float)((float)v8 - v28))))
                                                                              * (float)0.5))
                                                              * (float)v15)
                                                      - (float)1.5)
                                      * (float)v15))));
  v18 = (float)((float)((float)v8 - v28)
              * (float)((float)v17
                      * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v15 * (float)((float)((float)((float)((float)v7 - v27) * (float)((float)v7 - v27)) + (float)((float)((float)((float)v9 - v29) * (float)((float)v9 - v29)) + (float)((float)((float)v8 - v28) * (float)((float)v8 - v28)))) * (float)0.5))
                                                                                              * (float)v15)
                                                                                      - (float)1.5)
                                                                      * (float)v15)
                                                              * (float)((float)((float)((float)((float)v7 - v27)
                                                                                      * (float)((float)v7 - v27))
                                                                              + (float)((float)((float)((float)v9 - v29)
                                                                                              * (float)((float)v9 - v29))
                                                                                      + (float)((float)((float)v8 - v28)
                                                                                              * (float)((float)v8 - v28))))
                                                                      * (float)0.5))
                                                      * (float)((float)-(float)((float)((float)((float)v15
                                                                                              * (float)((float)((float)((float)((float)v7 - v27) * (float)((float)v7 - v27)) + (float)((float)((float)((float)v9 - v29) * (float)((float)v9 - v29)) + (float)((float)((float)v8 - v28) * (float)((float)v8 - v28)))) * (float)0.5))
                                                                                      * (float)v15)
                                                                              - (float)1.5)
                                                              * (float)v15))
                                              - (float)1.5)
                              * (float)((float)-(float)((float)((float)((float)v15
                                                                      * (float)((float)((float)((float)((float)v7 - v27)
                                                                                              * (float)((float)v7 - v27))
                                                                                      + (float)((float)((float)((float)v9 - v29) * (float)((float)v9 - v29))
                                                                                              + (float)((float)((float)v8 - v28) * (float)((float)v8 - v28))))
                                                                              * (float)0.5))
                                                              * (float)v15)
                                                      - (float)1.5)
                                      * (float)v15))));
  if ( (float)((float)((float)-ent->spawnOrientation.mat[0].x * (float)v20)
             + (float)((float)((float)-ent->spawnOrientation.mat[0].z * (float)v19)
                     + (float)((float)-ent->spawnOrientation.mat[0].y * (float)v18))) < 0.0 )
  {
    y = ent->spawnOrientation.mat[1].y;
    x = ent->spawnOrientation.mat[1].x;
    z = ent->spawnOrientation.mat[1].z;
    if ( (float)((float)(x * (float)v20) + (float)((float)(z * (float)v19) + (float)(y * (float)v18))) >= 0.0 )
    {
      v20 = x;
      v18 = y;
      v19 = z;
    }
    else
    {
      v20 = -x;
      v18 = -y;
      v19 = -z;
    }
  }
  v23 = ai->aiEditable.behaviors.decl;
  v25 = (float)((float)v18 * v23->backstandBehaviors.riseDistance);
  v26 = (float)((float)v19 * v23->backstandBehaviors.riseDistance);
  result->x = (float)v7 - (float)(v23->backstandBehaviors.riseDistance * (float)v20);
  result->y = (float)v8 - (float)v25;
  result->z = (float)v9 - (float)v26;
  return result;
}


// ========================================================================
// ?Evaluate@RoamScenePoint_Shared_Finished@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AC3DB0
// RVA : 0x00AC3DB0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_backstand.cpp
// ========================================================================

int __fastcall RoamScenePoint_Shared_Finished::Evaluate(
        BACKSTAND_AnimDone *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  return !idAI2::AnimEventReceived(this: ai, priority: PRIORITY_LOW) ? 0 : 0x1C8;
}


// ========================================================================
// ?AIState_ExitState@idBackStand_OutOfReach@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AC3DF0
// RVA : 0x00AC3DF0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_backstand.cpp
// ========================================================================

void __fastcall idBackStand_OutOfReach::AIState_ExitState(
        idBackStand_OutOfReach *this,
        idAI2 *ai,
        idAIFSM *fsm,
        const int curTime)
{
  idAIMoveState::SetMovementModeForReal(this: &ai->aiVolatile.physics.moveState, mode: AIMOVEMODE_GROUND);
}


// ========================================================================
// ?AIState_Work@idBackStand_Rising@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AC3E00
// RVA : 0x00AC3E00
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_backstand.cpp
// ========================================================================

void __fastcall idBackStand_Rising::AIState_Work(idBackStand_Rising *this, idAI2 *ai, idAIFSM *fsm, const int curTime)
{
  if ( (*((_BYTE *)ai->aiEditable.behaviors.decl + 429) & 0x80) != 0 )
    idAIMoveState::SetMovementModeForReal(this: &ai->aiVolatile.physics.moveState, mode: AIMOVEMODE_PERFECTORIGIN);
}


// ========================================================================
// ??0idBackStandFSM@@QAA@XZ
// EA  : 0x82AC3E30
// RVA : 0x00AC3E30
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_backstand.cpp
// ========================================================================

idBackStandFSM *__fastcall idBackStandFSM::idBackStandFSM(idBackStandFSM *this)
{
  idFiniteStateMachine::idFiniteStateMachine(this, name: "FSM_backstand");
  this->__vftable = (idBackStandFSM_vtbl *)&idBackStandFSM::`vftable';
  idState::idState(this: &this->stateDefault, stateType: &idBackStand_Default::Type, childFSMType: nullptr, flags: 0);
  this->stateDefault.__vftable = (idBackStand_Default_vtbl *)&idBackStand_Default::`vftable';
  idState::idState(this: &this->stateMoving, stateType: &idBackStand_Moving::Type, childFSMType: nullptr, flags: 0);
  this->stateMoving.__vftable = (idBackStand_Moving_vtbl *)&idBackStand_Moving::`vftable';
  idState::idState(
    this: &this->stateOutOfReach,
    stateType: &idBackStand_OutOfReach::Type,
    childFSMType: nullptr,
    flags: 0);
  this->stateOutOfReach.__vftable = (idBackStand_OutOfReach_vtbl *)&idBackStand_OutOfReach::`vftable';
  idState::idState(this: &this->stateRising, stateType: &idBackStand_Rising::Type, childFSMType: nullptr, flags: 0);
  this->stateRising.__vftable = (idBackStand_Rising_vtbl *)&idBackStand_Rising::`vftable';
  idState::idState(this: &this->stateStanding, stateType: &idBackStand_Standing::Type, childFSMType: nullptr, flags: 0);
  this->stateStanding.__vftable = (idBackStand_Standing_vtbl *)&idBackStand_Standing::`vftable';
  idState::idState(
    this: &this->stateAttacking,
    stateType: &idBackStand_Attacking::Type,
    childFSMType: nullptr,
    flags: 0);
  this->stateAttacking.__vftable = (idBackStand_Attacking_vtbl *)&idBackStand_Attacking::`vftable';
  idState::idState(this: &this->stateLowering, stateType: &idBackStand_Lowering::Type, childFSMType: nullptr, flags: 0);
  this->stateLowering.__vftable = (idBackStand_Lowering_vtbl *)&idBackStand_Lowering::`vftable';
  idFiniteStateMachine::SetDefaultState(this, state: &this->stateDefault);
  return this;
}


// ========================================================================
// __unwind$489023
// EA  : 0x82AC3F7C
// RVA : 0x00AC3F7C
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_backstand.cpp
// ========================================================================

void _unwind_489023()
{
  int v0; // r12

  idAIFSM::~idAIFSM(this: *(idAIFSM **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$489024
// EA  : 0x82AC3FA4
// RVA : 0x00AC3FA4
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_backstand.cpp
// ========================================================================

void _unwind_489024()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 108));
}


// ========================================================================
// __unwind$489025
// EA  : 0x82AC3FD0
// RVA : 0x00AC3FD0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_backstand.cpp
// ========================================================================

void _unwind_489025()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 136));
}


// ========================================================================
// __unwind$489026
// EA  : 0x82AC3FFC
// RVA : 0x00AC3FFC
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_backstand.cpp
// ========================================================================

void _unwind_489026()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 164));
}


// ========================================================================
// __unwind$489027
// EA  : 0x82AC4028
// RVA : 0x00AC4028
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_backstand.cpp
// ========================================================================

void _unwind_489027()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 192));
}


// ========================================================================
// __unwind$489028
// EA  : 0x82AC4054
// RVA : 0x00AC4054
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_backstand.cpp
// ========================================================================

void _unwind_489028()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 220));
}


// ========================================================================
// __unwind$489029
// EA  : 0x82AC4080
// RVA : 0x00AC4080
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_backstand.cpp
// ========================================================================

void _unwind_489029()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 248));
}


// ========================================================================
// __unwind$489030
// EA  : 0x82AC40AC
// RVA : 0x00AC40AC
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_backstand.cpp
// ========================================================================

void _unwind_489030()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 276));
}


// ========================================================================
// ?AIState_Work@idBackStand_OutOfReach@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AC40D8
// RVA : 0x00AC40D8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_backstand.cpp
// ========================================================================

void __fastcall idBackStand_OutOfReach::AIState_Work(
        idBackStand_OutOfReach *this,
        idAI2 *ai,
        idAIFSM *fsm,
        const int curTime)
{
  idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *p_animation; // r31
  idAnimator_AnimWeb *CurSubWebIndex; // r3
  __int16 v7; // [sp+50h] [-20h] BYREF
  char v8; // [sp+52h] [-1Eh] BYREF

  p_animation = (idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)&ai->aiVolatile.animation;
  if ( curTime - fsm->lastTransitionTime > 7000
    && (unsigned __int16)ai->aiVolatile.animation.animWebAnimator.ptr[0].pathIndex >= 0x8000u )
  {
    idDeclAnimWeb::GetSubWebIndexForName(
      this: (idDeclAnimWeb *)&v7,
      result: (idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)ai->aiVolatile.animation.animWebAnimator.ptr[0].decl,
      subWebName: "backstand");
    CurSubWebIndex = idAnimator_AnimWeb::GetCurSubWebIndex(this: (idAnimator_AnimWeb *)&v8, result: p_animation);
    if ( v7 == SHIWORD(CurSubWebIndex->__vftable) )
      idAI2::WaitForAnimToStart(
        this: ai,
        awt: AIANIMWEB_BODY,
        priority: PRIORITY_LOW,
        subWebName: "down",
        stateName: "idle",
        ev: ANIMWEB_EVENT_START_BLEND_IN);
  }
}


// ========================================================================
// PredictedEnemyPlanePosition
// EA  : 0x82AC4230
// RVA : 0x00AC4230
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_backstand.cpp
// ========================================================================

idVec2 *__fastcall PredictedEnemyPlanePosition(idVec2 *result, idAI2 *ai, double time)
{
  int value; // r8
  idEntity *v6; // r3
  idEntity *v7; // r31
  idPhysics *Physics; // r3
  float *v9; // r3
  double v10; // fp30
  double v11; // fp29
  idPhysics *v12; // r3
  double v14; // fp11
  float v15[4]; // [sp+50h] [-40h] BYREF

  value = ai->aiVolatile.memory.currentEnemy.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v6 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v7 = idEntity::CastTo(c: v6);
  }
  else
  {
    v7 = nullptr;
  }
  Physics = idEntity::GetPhysics(this: v7);
  v9 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
  v10 = *v9;
  v11 = v9[1];
  v12 = idEntity::GetPhysics(this: v7);
  v12->GetLinearVelocity(this: (idPhysics *)v15, result: (idVec3 *)v12, a3: 0);
  v14 = (float)(v15[1] * (float)time);
  result->x = (float)(v15[0] * (float)time) + (float)v10;
  result->y = (float)v14 + (float)v11;
  return result;
}


// ========================================================================
// FindBestHint
// EA  : 0x82AC4348
// RVA : 0x00AC4348
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_backstand.cpp
// ========================================================================

idEntity *__fastcall FindBestHint(idAI2 *ai)
{
  int value; // r8
  idEntity *v3; // r3
  idCombatStage *CurrentCombatStage; // r3
  idCombatStage *v6; // r22
  int v7; // r9
  idAIHintGroup *v8; // r3
  idAIHintGroup *v9; // r26
  const idEntity *BackStandHint; // r24
  idPhysics *Physics; // r3
  float *v12; // r27
  idEntity *Enemy; // r31
  idPhysics *v14; // r3
  float *v15; // r3
  double v16; // fp30
  double v17; // fp29
  idPhysics *v18; // r3
  const idDeclAIBehavior *decl; // r7
  idEntity *v20; // r23
  int v21; // r28
  double v22; // fp31
  double v23; // fp25
  double v24; // fp28
  double v25; // fp27
  double riseTime; // fp26
  int v27; // r29
  int v28; // r10
  idAIHintGroup *v29; // r3
  idAIHintGroup *v30; // r3
  int v31; // r9
  idEntity *v32; // r3
  idEntity *v33; // r31
  float x; // r10
  float y; // r9
  double v36; // fp0
  double v37; // fp4
  double v38; // fp3
  float v39[18]; // [sp+60h] [-A0h] BYREF

  value = ai->aiVolatile.memory.currentEnemy.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] != value >> 13 )
    return nullptr;
  v3 = gameLocal->entities.ptr[value & 0x1FFF];
  if ( v3 == nullptr )
    return nullptr;
  if ( idEntity::CastTo(c: v3) == nullptr )
    return nullptr;
  CurrentCombatStage = idAI2::GetCurrentCombatStage(this: ai);
  v6 = CurrentCombatStage;
  if ( CurrentCombatStage == nullptr )
    return nullptr;
  v7 = CurrentCombatStage->hintGroup.spawnId.value;
  if ( gameLocal->spawnIds.ptr[v7 & 0x1FFF] != v7 >> 13 )
    return nullptr;
  v8 = (idAIHintGroup *)gameLocal->entities.ptr[v7 & 0x1FFF];
  if ( v8 == nullptr )
    return nullptr;
  v9 = idAIHintGroup::CastTo(c: v8);
  if ( v9 == nullptr )
    return nullptr;
  BackStandHint = idAIMemory::GetBackStandHint(this: &ai->aiVolatile.memory);
  Physics = idEntity::GetPhysics(this: ai);
  v12 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
  Enemy = (idEntity *)idAIMemory::GetEnemy(this: &ai->aiVolatile.memory);
  v14 = idEntity::GetPhysics(this: Enemy);
  v15 = (float *)v14->GetOrigin(this: v14, a2: 0);
  v16 = *v15;
  v17 = v15[1];
  v18 = idEntity::GetPhysics(this: Enemy);
  v18->GetLinearVelocity(this: (idPhysics *)v39, result: (idVec3 *)v18, a3: 0);
  decl = ai->aiEditable.behaviors.decl;
  v20 = nullptr;
  v21 = 0;
  v22 = 9000000.0;
  v23 = (float)(decl->backstandBehaviors.commitDistance * (float)2.0);
  v24 = v39[0];
  v25 = v39[1];
  riseTime = decl->backstandBehaviors.riseTime;
  if ( v9->targets.num > 0 )
  {
    v27 = 0;
    do
    {
      v28 = v6->hintGroup.spawnId.value;
      if ( gameLocal->spawnIds.ptr[v28 & 0x1FFF] == v28 >> 13
        && (v29 = (idAIHintGroup *)gameLocal->entities.ptr[v28 & 0x1FFF]) != nullptr )
      {
        v30 = idAIHintGroup::CastTo(c: v29);
      }
      else
      {
        v30 = nullptr;
      }
      if ( v21 < v30->targets.num
        && (v31 = v30->targets.list[v27].spawnId.value, gameLocal->spawnIds.ptr[v31 & 0x1FFF] == v31 >> 13)
        && (v32 = gameLocal->entities.ptr[v31 & 0x1FFF]) != nullptr )
      {
        v33 = idEntity::CastTo(c: v32);
      }
      else
      {
        v33 = nullptr;
      }
      if ( v33 != nullptr && v33->IsVisible(this: v33) )
      {
        x = v33->spawnPosition.x;
        y = v33->spawnPosition.y;
        v36 = __fsqrts((float)((float)((float)(x - *v12) * (float)(x - *v12))
                             + (float)((float)((float)(v33->spawnPosition.z - v12[2])
                                             * (float)(v33->spawnPosition.z - v12[2]))
                                     + (float)((float)(y - v12[1]) * (float)(y - v12[1])))));
        if ( v33 == BackStandHint || v36 >= v23 )
        {
          v37 = (float)((float)((float)((float)v24
                                      * (float)((float)((float)v36 / ai->aiConstants.movement.moveSpeed.maxRange)
                                              + (float)riseTime))
                              + (float)v16)
                      - x);
          v38 = (float)((float)((float)((float)v25
                                      * (float)((float)((float)v36 / ai->aiConstants.movement.moveSpeed.maxRange)
                                              + (float)riseTime))
                              + (float)v17)
                      - y);
          if ( (float)((float)((float)v38 * (float)v38) + (float)((float)v37 * (float)v37)) < v22 )
          {
            v22 = (float)((float)((float)v38 * (float)v38) + (float)((float)v37 * (float)v37));
            v20 = v33;
          }
        }
      }
      ++v21;
      ++v27;
    }
    while ( v21 < v9->targets.num );
  }
  return v20;
}


// ========================================================================
// ?Evaluate@BACKSTAND_TargetLost@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AC4678
// RVA : 0x00AC4678
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_backstand.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall BACKSTAND_TargetLost::Evaluate(
        BACKSTAND_TargetLost *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  int value; // r8
  idEntity *v6; // r3
  idAIStateTransition::aiTransCode_t result; // r3
  bool v8; // zf

  value = ai->aiVolatile.memory.currentEnemy.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] != value >> 13 )
    return TRANSCODE_MAX;
  v6 = gameLocal->entities.ptr[value & 0x1FFF];
  if ( v6 == nullptr )
    return TRANSCODE_MAX;
  v8 = idEntity::CastTo(c: v6) != nullptr;
  result = 0;
  if ( !v8 )
    return TRANSCODE_MAX;
  return result;
}


// ========================================================================
// ?Evaluate@BACKSTAND_ShouldReturn@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AC46F0
// RVA : 0x00AC46F0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_backstand.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall BACKSTAND_ShouldReturn::Evaluate(
        BACKSTAND_ShouldReturn *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  int value; // r8
  idEntity *v7; // r3
  idEntity *v8; // r3
  idAIStateTransition::aiTransCode_t result; // r3
  idPhysics *Physics; // r30
  idPhysics *v11; // r29
  const idDeclAIBehavior *decl; // r31
  float *p_z; // r30
  double v14; // fp12

  value = ai->aiVolatile.memory.currentEnemy.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] != value >> 13 )
    return TRANSCODE_MAX;
  v7 = gameLocal->entities.ptr[value & 0x1FFF];
  if ( v7 == nullptr )
    return TRANSCODE_MAX;
  v8 = idEntity::CastTo(c: v7);
  if ( v8 == nullptr )
    return TRANSCODE_MAX;
  Physics = idEntity::GetPhysics(this: v8);
  v11 = idEntity::GetPhysics(this: ai);
  decl = ai->aiEditable.behaviors.decl;
  p_z = &Physics->GetOrigin(this: Physics, a2: 0)->z;
  v14 = (float)(*p_z - v11->GetOrigin(this: v11, a2: 0)->z);
  result = TRANSCODE_MAX;
  if ( v14 >= decl->backstandBehaviors.groundReach )
    return 0;
  return result;
}


// ========================================================================
// ?Evaluate@BACKSTAND_ShouldRise@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AC47D0
// RVA : 0x00AC47D0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_backstand.cpp
// ========================================================================

int __fastcall BACKSTAND_ShouldRise::Evaluate(
        BACKSTAND_ShouldRise *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  int value; // r8
  idEntity *v7; // r3
  idAI2::idAIVolatile::idAIAnimationInfo *p_animation; // r31
  char v10; // r11
  char v11; // [sp+50h] [-20h] BYREF

  value = ai->aiVolatile.memory.backstandHint.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] != value >> 13 )
    return 0;
  v7 = gameLocal->entities.ptr[value & 0x1FFF];
  if ( v7 == nullptr
    || idEntity::CastTo(c: v7) == nullptr
    || ai->aiVolatile.physics.moveState.movementMode != AIMOVEMODE_GROUND
    || ai->aiVolatile.physics.moveState.GetMoveStatus(this: &ai->aiVolatile.physics.moveState) != 0 )
  {
    return 0;
  }
  p_animation = &ai->aiVolatile.animation;
  idDeclAnimWeb::GetSubWebIndexForName(
    this: (idDeclAnimWeb *)&v11,
    result: (idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)p_animation->animWebAnimator.ptr[0].decl,
    subWebName: "backstand");
  if ( (unsigned __int16)p_animation->animWebAnimator.ptr[0].curEdgeNodeIndex.value >= 0x8000u
    || (v10 = 1, (unsigned __int16)p_animation->animWebAnimator.ptr[0].curEdgeIndex >= 0x8000u) )
  {
    v10 = 0;
  }
  return v10 != 0 ? 0 : 0x1C8;
}


// ========================================================================
// ?Evaluate@BACKSTAND_ShouldOutOfReach@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AC48D8
// RVA : 0x00AC48D8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_backstand.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall BACKSTAND_ShouldOutOfReach::Evaluate(
        BACKSTAND_ShouldOutOfReach *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        int curTime)
{
  idAIStateTransition::aiTransCode_t result; // r3
  int value; // r8
  idEntity *v8; // r3
  idEntity *v9; // r30
  idVec2 *v10; // r3
  double v11; // fp11
  double v12; // fp9
  idVec2 v13; // [sp+50h] [-20h] BYREF

  if ( ((int (__fastcall *)(idAIMoveState *, idAI2 *, idAIFSM *, idAIState *, int))ai->aiVolatile.physics.moveState.GetMoveStatus)(
         a1: &ai->aiVolatile.physics.moveState,
         a2: ai,
         a3: parentFSM,
         a4: state,
         a5: curTime) != 0 )
    return 0;
  value = ai->aiVolatile.memory.backstandHint.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] != value >> 13 )
    return 0;
  v8 = gameLocal->entities.ptr[value & 0x1FFF];
  if ( v8 == nullptr )
    return 0;
  v9 = idEntity::CastTo(c: v8);
  if ( v9 == nullptr || FindBestHint(ai) != v9 || idAIMemory::GetEnemy(this: &ai->aiVolatile.memory) == nullptr )
    return 0;
  v10 = PredictedEnemyPlanePosition(result: &v13, ai, time: 1.0);
  v11 = (float)(v9->spawnPosition.x - v10->x);
  v12 = (float)(v9->spawnPosition.y - v10->y);
  result = 0;
  if ( __fsqrts((float)((float)((float)v12 * (float)v12) + (float)((float)v11 * (float)v11))) >= ai->aiEditable.behaviors.decl->backstandBehaviors.standReach )
    return TRANSCODE_MAX;
  return result;
}


// ========================================================================
// ?Evaluate@BACKSTAND_ShouldOutOfReachFromLedge@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AC49F8
// RVA : 0x00AC49F8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_backstand.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall BACKSTAND_ShouldOutOfReachFromLedge::Evaluate(
        BACKSTAND_ShouldOutOfReachFromLedge *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  int value; // r8
  idEntity *v7; // r3
  idEntity *v8; // r29
  idAIStateTransition::aiTransCode_t result; // r3
  int v10; // r8
  idEntity *v11; // r3
  idEntity *v12; // r30
  const idDeclAIBehavior *decl; // r31
  idAIMemory *p_memory; // r3
  idEntity *BackStandHint; // r3
  double v16; // fp1

  value = ai->aiVolatile.memory.backstandHint.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] != value >> 13 )
    return 0;
  v7 = gameLocal->entities.ptr[value & 0x1FFF];
  if ( v7 == nullptr )
    return 0;
  v8 = idEntity::CastTo(c: v7);
  if ( v8 == nullptr )
    return 0;
  v10 = ai->aiVolatile.memory.currentEnemy.spawnId.value;
  if ( gameLocal->spawnIds.ptr[v10 & 0x1FFF] != v10 >> 13 )
    return 0;
  v11 = gameLocal->entities.ptr[v10 & 0x1FFF];
  if ( v11 == nullptr )
    return 0;
  v12 = idEntity::CastTo(c: v11);
  if ( v12 == nullptr || FindBestHint(ai) != v8 )
    return 0;
  p_memory = &ai->aiVolatile.memory;
  decl = ai->aiEditable.behaviors.decl;
  BackStandHint = (idEntity *)idAIMemory::GetBackStandHint(this: p_memory);
  v16 = EntityPlaneDistance(entA: BackStandHint, entB: v12);
  result = 0;
  if ( v16 >= decl->backstandBehaviors.standReach )
    return TRANSCODE_MAX;
  return result;
}


// ========================================================================
// ?Evaluate@BACKSTAND_ShouldMove@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AC4B00
// RVA : 0x00AC4B00
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_backstand.cpp
// ========================================================================

int __fastcall BACKSTAND_ShouldMove::Evaluate(
        BACKSTAND_ShouldMove *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  return FindBestHint(ai) == nullptr ? 0 : 0x1C8;
}


// ========================================================================
// ?AIState_EnterState@idBackStand_OutOfReach@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AC4B38
// RVA : 0x00AC4B38
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_backstand.cpp
// ========================================================================

void __fastcall idBackStand_OutOfReach::AIState_EnterState(
        idBackStand_OutOfReach *this,
        idAI2 *ai,
        idAIFSM *fsm,
        int curTime)
{
  int value; // r8
  idEntity *v9; // r3
  idEntity *v10; // r25
  idPresentable *presentable; // r11
  const char *v12; // r30
  const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *v13; // r30
  const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *v14; // r29
  const idQuat *v15; // r3
  unsigned __int16 v16; // [sp+50h] [-60h] BYREF
  char v17; // [sp+52h] [-5Eh] BYREF
  idMat3 v18[2]; // [sp+60h] [-50h] BYREF

  idAI2::SetEnableAutoFocus(this: ai, enable: false);
  value = ai->aiVolatile.memory.backstandHint.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v9 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v10 = idEntity::CastTo(c: v9);
  }
  else
  {
    v10 = nullptr;
  }
  idDeclAnimWeb::GetSubWebIndexForName(
    this: (idDeclAnimWeb *)&v16,
    result: (idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)ai->aiVolatile.animation.animWebAnimator.ptr[0].decl,
    subWebName: "backstand");
  idAIState::ClearQueuedActions(this, ai, parentFSM: fsm, curTime);
  presentable = ai->presentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this: ai);
    presentable = ai->presentable;
  }
  if ( (float)((float)(presentable->axis.mat[0].x * v10->spawnOrientation.mat[1].x)
             + (float)((float)(presentable->axis.mat[0].z * v10->spawnOrientation.mat[1].z)
                     + (float)(presentable->axis.mat[0].y * v10->spawnOrientation.mat[1].y))) <= 0.0 )
    v12 = "pasing_right";
  else
    v12 = "pasing_left";
  idAI2::WaitForAnimToStart(
    this: ai,
    awt: AIANIMWEB_BODY,
    priority: PRIORITY_LOW,
    subWebName: "backstand",
    stateName: v12,
    ev: ANIMWEB_EVENT_START_BLEND_IN);
  v13 = (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)HIWORD(idDeclAnimWeb::GetStateIndexForName(
                                                                                 this: (idDeclAnimWeb *)&v17,
                                                                                 result: (idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)ai->aiVolatile.animation.animWebAnimator.ptr[0].decl,
                                                                                 name: v12)->__vftable);
  v14 = (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)v16;
  v15 = idMat3::ToQuat(this: v18, result: (idQuat *)&ai->aiVolatile.memory.backstandAlignment);
  idAIMoveState::StartPerfectOrigin(
    this: &ai->aiVolatile.physics.moveState,
    idealAxis: v15,
    idealPos: &ai->aiVolatile.memory.backstandRisePosition,
    lerpTimeMs: 750,
    swi: v14,
    si: v13);
}


// ========================================================================
// GetEnemySide
// EA  : 0x82AC4CB8
// RVA : 0x00AC4CB8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_backstand.cpp
// ========================================================================

int __fastcall GetEnemySide(idAI2 *ai)
{
  int value; // r8
  idEntity *v3; // r3
  idEntity *v4; // r30
  idPhysics *Physics; // r3
  float *v6; // r29
  idPhysics *v7; // r3
  float *v8; // r3
  idPresentable *presentable; // r11
  double v10; // fp31
  double v11; // fp30
  double v12; // fp29
  int result; // r3

  value = ai->aiVolatile.memory.currentEnemy.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] != value >> 13 )
    return 1;
  v3 = gameLocal->entities.ptr[value & 0x1FFF];
  if ( v3 == nullptr )
    return 1;
  v4 = idEntity::CastTo(c: v3);
  if ( v4 == nullptr )
    return 1;
  Physics = idEntity::GetPhysics(this: ai);
  v6 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
  v7 = idEntity::GetPhysics(this: v4);
  v8 = (float *)v7->GetOrigin(this: v7, a2: 0);
  presentable = ai->presentable;
  v10 = (float)(*v8 - *v6);
  v11 = (float)(v8[1] - v6[1]);
  v12 = (float)(v8[2] - v6[2]);
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this: ai);
    presentable = ai->presentable;
  }
  result = -1;
  if ( (float)((float)(presentable->axis.mat[1].x * (float)v10)
             + (float)((float)(presentable->axis.mat[1].z * (float)v12)
                     + (float)(presentable->axis.mat[1].y * (float)v11))) <= 0.0 )
    return 1;
  return result;
}


// ========================================================================
// ?AIState_EnterState@idBackStand_Attacking@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AC4DE8
// RVA : 0x00AC4DE8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_backstand.cpp
// ========================================================================

void __fastcall idBackStand_Attacking::AIState_EnterState(
        idBackStand_Attacking *this,
        idAI2 *ai,
        idAIFSM *fsm,
        int curTime)
{
  int value; // r8
  idEntity *v9; // r3
  idEntity *v10; // r29
  int v11; // r8
  idEntity *v12; // r3
  idEntity *v13; // r11
  float y; // r9
  float z; // r8
  idPhysics *Physics; // r3
  float *v17; // r30
  idPhysics *v18; // r3
  float *v19; // r3
  double v20; // fp7
  double v21; // fp6
  const char *v22; // r9
  idVec3 v23; // [sp+50h] [-60h] BYREF
  float x; // [sp+60h] [-50h]
  float v25; // [sp+64h] [-4Ch]
  float v26; // [sp+68h] [-48h]

  if ( (*((_BYTE *)ai->aiEditable.behaviors.decl + 429) & 0x80) != 0 )
  {
    value = ai->aiVolatile.memory.currentEnemy.spawnId.value;
    if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
      && (v9 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr
      && (v10 = idEntity::CastTo(c: v9)) != nullptr )
    {
      v11 = ai->aiVolatile.memory.backstandHint.spawnId.value;
      if ( gameLocal->spawnIds.ptr[v11 & 0x1FFF] == v11 >> 13
        && (v12 = gameLocal->entities.ptr[v11 & 0x1FFF]) != nullptr )
      {
        v13 = idEntity::CastTo(c: v12);
      }
      else
      {
        v13 = nullptr;
      }
      y = v13->spawnOrientation.mat[1].y;
      z = v13->spawnOrientation.mat[1].z;
      x = v13->spawnOrientation.mat[1].x;
      v25 = y;
      v26 = z;
      Physics = idEntity::GetPhysics(this: v10);
      v17 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
      v18 = idEntity::GetPhysics(this: ai);
      v19 = (float *)v18->GetOrigin(this: v18, a2: 0);
      v20 = (float)(v19[1] - v17[1]);
      v21 = (float)(v19[2] - v17[2]);
      v23.x = *v19 - *v17;
      v23.y = v20;
      v23.z = v21;
      idVec3::NormalizeFast(this: &v23);
      ai->aiVolatile.animation.animWebAnimator.ptr[0].select01 = -(float)((float)((float)((float)((float)(v26 * v23.z)
                                                                                                + (float)((float)(v23.x * x) + (float)(v25 * v23.y)))
                                                                                        + (float)1.0)
                                                                                * (float)0.5)
                                                                        - (float)1.0);
    }
    else
    {
      ai->aiVolatile.animation.animWebAnimator.ptr[0].select01 = 0.5;
    }
    idAIState::ClearQueuedActions(this, ai, parentFSM: fsm, curTime);
    v22 = "attack";
  }
  else
  {
    idAIState::ClearQueuedActions(this, ai, parentFSM: fsm, curTime);
    if ( GetEnemySide(ai) >= 0 )
      v22 = "attack_right";
    else
      v22 = "attack_left";
  }
  idAI2::WaitForAnimToStartVia(
    this: ai,
    awt: AIANIMWEB_BODY,
    priority: PRIORITY_LOW,
    subWebName: "backstand",
    stateName: "idle",
    viaSubWebName: "backstand",
    viaStateName: v22,
    ev: ANIMWEB_EVENT_START_BLEND_IN);
}


// ========================================================================
// ?Evaluate@BACKSTAND_ShouldAttack@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AC5040
// RVA : 0x00AC5040
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_backstand.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall BACKSTAND_ShouldAttack::Evaluate(
        BACKSTAND_ShouldAttack *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  int value; // r8
  idEntity *v7; // r3
  idEntity *v8; // r29
  idAIStateTransition::aiTransCode_t result; // r3
  int v10; // r8
  idEntity *v11; // r3
  idEntity *v12; // r3
  const idDeclAIBehavior *decl; // r31
  double v14; // fp1

  value = ai->aiVolatile.memory.currentEnemy.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] != value >> 13 )
    return 0;
  v7 = gameLocal->entities.ptr[value & 0x1FFF];
  if ( v7 == nullptr )
    return 0;
  v8 = idEntity::CastTo(c: v7);
  if ( v8 == nullptr )
    return 0;
  v10 = ai->aiVolatile.memory.backstandHint.spawnId.value;
  if ( gameLocal->spawnIds.ptr[v10 & 0x1FFF] == v10 >> 13 && (v11 = gameLocal->entities.ptr[v10 & 0x1FFF]) != nullptr )
    v12 = idEntity::CastTo(c: v11);
  else
    v12 = nullptr;
  decl = ai->aiEditable.behaviors.decl;
  v14 = EntityPlaneDistance(entA: v12, entB: v8);
  result = 0;
  if ( v14 <= decl->backstandBehaviors.attackReach )
    return TRANSCODE_MAX;
  return result;
}


// ========================================================================
// ?Evaluate@BACKSTAND_ShouldLower@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AC5128
// RVA : 0x00AC5128
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_backstand.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall BACKSTAND_ShouldLower::Evaluate(
        BACKSTAND_ShouldLower *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  int value; // r8
  idEntity *v7; // r3
  idEntity *v8; // r29
  int v9; // r8
  idEntity *v10; // r3
  idEntity *v11; // r3
  const idDeclAIBehavior *decl; // r31
  double v13; // fp1
  idAIStateTransition::aiTransCode_t result; // r3

  value = ai->aiVolatile.memory.currentEnemy.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] != value >> 13 )
    return 0;
  v7 = gameLocal->entities.ptr[value & 0x1FFF];
  if ( v7 == nullptr )
    return 0;
  v8 = idEntity::CastTo(c: v7);
  if ( v8 == nullptr )
    return 0;
  v9 = ai->aiVolatile.memory.backstandHint.spawnId.value;
  if ( gameLocal->spawnIds.ptr[v9 & 0x1FFF] == v9 >> 13 && (v10 = gameLocal->entities.ptr[v9 & 0x1FFF]) != nullptr )
    v11 = idEntity::CastTo(c: v10);
  else
    v11 = nullptr;
  decl = ai->aiEditable.behaviors.decl;
  v13 = EntityPlaneDistance(entA: v11, entB: v8);
  result = TRANSCODE_MAX;
  if ( v13 <= decl->backstandBehaviors.standReach )
    return 0;
  return result;
}


// ========================================================================
// ?CanUse@idBackStandFSM@@UBA_NPAVidFiniteStateMachine@@H@Z
// EA  : 0x82AC5200
// RVA : 0x00AC5200
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_backstand.cpp
// ========================================================================

BOOL __fastcall idBackStandFSM::CanUse(idBackStandFSM *this, idFiniteStateMachine *fsm, const int curTime)
{
  idEntity *Owner; // r3
  idAI2 *v4; // r31
  int bindMaster; // r8
  idEntity *v6; // r3
  idEntity *v7; // r3
  idEntity *v8; // r30
  idEncounterGroup *EncounterGroup; // r3
  int curCombatStage; // r11
  idPhysics *Physics; // r30
  idPhysics *v12; // r29
  const idDeclAIBehavior *decl; // r28
  int p_z; // r30

  Owner = idFiniteStateMachine::GetOwner(this: fsm);
  v4 = (idAI2 *)Owner;
  if ( (*(_BYTE *)(*(_DWORD *)Owner[14].renderModelInfo.editorModel.baseBuffer + 86) & 2) == 0 )
    return false;
  bindMaster = (int)Owner[72].bindInfo.bindMaster;
  if ( gameLocal->spawnIds.ptr[bindMaster & 0x1FFF] != bindMaster >> 13 )
    return false;
  v6 = gameLocal->entities.ptr[bindMaster & 0x1FFF];
  if ( v6 == nullptr )
    return false;
  v7 = idEntity::CastTo(c: v6);
  v8 = v7;
  if ( v7 == nullptr )
    return false;
  if ( !v7->IsDead(this: v7)
    && idAI2::GetEncounterGroup(this: v4) != nullptr
    && (EncounterGroup = idAI2::GetEncounterGroup(this: v4), (curCombatStage = EncounterGroup->curCombatStage) >= 0)
    && curCombatStage < EncounterGroup->combatStages.num
    && &EncounterGroup->combatStages.list[curCombatStage] != nullptr
    && (Physics = idEntity::GetPhysics(this: v8),
        v12 = idEntity::GetPhysics(this: v4),
        decl = v4->aiEditable.behaviors.decl,
        (float)(*(float *)(p_z = (int)&Physics->GetOrigin(this: Physics, a2: 0)->z) - v12->GetOrigin(this: v12, a2: 0)->z) >= (double)decl->backstandBehaviors.groundReach) )
  {
    return FindBestHint(ai: v4) != nullptr;
  }
  else
  {
    return false;
  }
}


// ========================================================================
// ?Evaluate@BACKSTAND_ShouldChangeHint@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AC5370
// RVA : 0x00AC5370
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_backstand.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall BACKSTAND_ShouldChangeHint::Evaluate(
        BACKSTAND_ShouldChangeHint *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  idEntityPtr<idEntity const > *p_backstandHint; // r29
  int value; // r9
  idEntity *v8; // r3
  idEntity *v9; // r3
  idEntity *v10; // r31
  idAIStateTransition::aiTransCode_t result; // r3
  idEntity *BestHint; // r3
  double v13; // fp12
  double v14; // fp9

  p_backstandHint = &ai->aiVolatile.memory.backstandHint;
  value = ai->aiVolatile.memory.backstandHint.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] != value >> 13 )
    return 0;
  v8 = gameLocal->entities.ptr[value & 0x1FFF];
  if ( v8 == nullptr )
    return 0;
  v9 = idEntity::CastTo(c: v8);
  v10 = v9;
  if ( v9 == nullptr )
    return 0;
  if ( v9->IsVisible(this: v9) )
  {
    BestHint = FindBestHint(ai);
    if ( BestHint == nullptr || v10 == BestHint )
      return 0;
    v13 = (float)(v10->spawnPosition.y - BestHint->spawnPosition.y);
    v14 = (float)(v10->spawnPosition.x - BestHint->spawnPosition.x);
    result = 0;
    if ( (float)((float)((float)v14 * (float)v14) + (float)((float)v13 * (float)v13)) >= 40000.0 )
      return TRANSCODE_MAX;
  }
  else
  {
    p_backstandHint->spawnId.value = 0x1FFF;
    return TRANSCODE_MAX;
  }
  return result;
}


// ========================================================================
// ?AIState_EnterState@idBackStand_Moving@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AC5470
// RVA : 0x00AC5470
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_backstand.cpp
// ========================================================================

void __fastcall idBackStand_Moving::AIState_EnterState(idBackStand_Moving *this, idAI2 *ai, idAIFSM *fsm, int curTime)
{
  ai->aiVolatile.memory.backstandHint.spawnId.value = 0x1FFF;
  ((void (__fastcall *)(idAI2 *, int, idAIFSM *, int))ai->SetWalkState)(a1: ai, a2: 2, a3: fsm, a4: curTime);
}


// ========================================================================
// ?AIState_Work@idBackStand_Moving@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AC54A0
// RVA : 0x00AC54A0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_backstand.cpp
// ========================================================================

void __fastcall idBackStand_Moving::AIState_Work(idBackStand_Moving *this, idAI2 *ai, idAIFSM *fsm, int curTime)
{
  idEntityPtr<idEntity const > *p_backstandHint; // r28
  int value; // r9
  idEntity *v10; // r3
  idEntity *v11; // r3
  double commitDistance; // fp31
  float v13; // r9
  float v14; // r8
  idPhysics *Physics; // r3
  float *v16; // r3
  idEntity *BestHint; // r30
  const idDeclAIBehavior *decl; // r10
  double v19; // fp29
  double v20; // fp28
  double v21; // fp27
  double x; // fp31
  double y; // fp30
  double z; // fp29
  float v25; // r9
  float v26; // r8
  double v27; // fp0
  double v28; // fp13
  float v29; // r7
  double v30; // fp12
  idEventArg *v31; // r21
  idEntity *v32; // r30
  idGameLocal *v33; // r11
  int v34; // r9
  idEntity *v35; // r3
  idEntity *v36; // r3
  float v37; // r11
  float v38; // r10
  idPhysics *v39; // r3
  float *v40; // r29
  idPhysics *v41; // r3
  float *v42; // r3
  double v43; // fp30
  float *p_spawnOrientation; // r11
  double v45; // fp29
  idMat3 *p_backstandAlignment; // r10
  double v47; // fp31
  double v48; // fp4
  double v49; // fp3
  double v50; // fp9
  double v51; // fp10
  double v52; // fp7
  double v53; // fp8
  double v54; // fp6
  double v55; // fp5
  double v56; // fp0
  double v57; // fp11
  double v58; // fp9
  double v59; // fp7
  double v60; // fp8
  double v61; // fp6
  double v62; // fp5
  const idDeclAIBehavior *v63; // r10
  double v64; // fp13
  double v65; // fp12
  double v66; // fp28
  double v67; // fp27
  double v68; // fp26
  idEventArg *v69; // r26
  const idEventArg *v70; // [sp+8h] [-298h]
  const idEventArg *v71; // [sp+Ch] [-294h]
  _BYTE v72[20]; // [sp+70h] [-230h] BYREF
  _BYTE v73[20]; // [sp+90h] [-210h] BYREF
  _BYTE v74[20]; // [sp+B0h] [-1F0h] BYREF
  _BYTE v75[20]; // [sp+D0h] [-1D0h] BYREF
  _BYTE v76[20]; // [sp+F0h] [-1B0h] BYREF
  idVec3 v77[2]; // [sp+110h] [-190h] BYREF
  idVec3 v78[2]; // [sp+130h] [-170h] BYREF
  float v79[5]; // [sp+150h] [-150h] BYREF
  const idEventArg *v80[5]; // [sp+170h] [-130h] BYREF
  const idEventArg *v81[5]; // [sp+190h] [-110h] BYREF
  float v82[5]; // [sp+1B0h] [-F0h] BYREF
  idEventArg v83; // [sp+1D0h] [-D0h] BYREF
  idEventArg v84[4]; // [sp+1F0h] [-B0h] BYREF

  if ( (*((_BYTE *)ai->aiEditable.behaviors.decl + 429) & 0x80) != 0 )
  {
    p_backstandHint = &ai->aiVolatile.memory.backstandHint;
    value = ai->aiVolatile.memory.backstandHint.spawnId.value;
    if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
      && (v10 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
    {
      v11 = idEntity::CastTo(c: v10);
    }
    else
    {
      v11 = nullptr;
    }
    commitDistance = ai->aiEditable.behaviors.decl->backstandBehaviors.commitDistance;
    if ( v11 == nullptr
      || (v13 = ai->aiVolatile.memory.backstandRisePosition.y,
          v14 = ai->aiVolatile.memory.backstandRisePosition.z,
          v77[0].x = ai->aiVolatile.memory.backstandRisePosition.x,
          v77[0].y = v13,
          v77[0].z = v14,
          Physics = idEntity::GetPhysics(this: ai),
          v16 = (float *)Physics->GetOrigin(this: Physics, a2: 0),
          __fsqrts((float)((float)((float)(v77[0].y - v16[1]) * (float)(v77[0].y - v16[1]))
                         + (float)((float)((float)(v77[0].x - *v16) * (float)(v77[0].x - *v16))
                                 + (float)((float)(v77[0].z - v16[2]) * (float)(v77[0].z - v16[2]))))) >= commitDistance) )
    {
      BestHint = FindBestHint(ai);
      if ( BestHint != nullptr && BestHint != idAIMemory::GetBackStandHint(this: &ai->aiVolatile.memory) )
      {
        p_backstandHint->spawnId.value = (gameLocal->spawnIds.ptr[BestHint->entityNumber] << 13)
                                       | BestHint->entityNumber;
        decl = ai->aiEditable.behaviors.decl;
        v19 = (float)(BestHint->spawnPosition.x
                    + (float)(BestHint->spawnOrientation.mat[0].x * decl->backstandBehaviors.approachDistance));
        v20 = (float)(BestHint->spawnPosition.y
                    + (float)(BestHint->spawnOrientation.mat[0].y * decl->backstandBehaviors.approachDistance));
        v21 = (float)(BestHint->spawnPosition.z
                    + (float)(BestHint->spawnOrientation.mat[0].z * decl->backstandBehaviors.approachDistance));
        GetHintRisePosition(result: v78, ai, ent: BestHint);
        x = v78[0].x;
        y = v78[0].y;
        v77[0].x = (float)v19 - v78[0].x;
        z = v78[0].z;
        v77[0].y = (float)v20 - v78[0].y;
        v77[0].z = (float)v21 - v78[0].z;
        idVec3::NormalizeFast(this: v77);
        v25 = BestHint->spawnOrientation.mat[2].x;
        v26 = BestHint->spawnOrientation.mat[2].y;
        v27 = v77[0].x;
        v28 = v77[0].y;
        v29 = BestHint->spawnOrientation.mat[2].z;
        v30 = v77[0].z;
        ai->aiVolatile.memory.backstandRisePosition.x = x;
        v77[0].x = v25;
        v77[0].y = v26;
        v77[0].z = v29;
        ai->aiVolatile.memory.backstandRisePosition.y = y;
        ai->aiVolatile.memory.backstandRisePosition.z = z;
        ai->aiVolatile.memory.backstandAlignment.mat[0].x = v27;
        ai->aiVolatile.memory.backstandAlignment.mat[1].x = (float)(v26 * (float)v30) - (float)(v29 * (float)v28);
        ai->aiVolatile.memory.backstandAlignment.mat[0].y = v28;
        ai->aiVolatile.memory.backstandAlignment.mat[0].z = v30;
        ai->aiVolatile.memory.backstandAlignment.mat[1].y = (float)(v29 * (float)v27) - (float)((float)v30 * v25);
        ai->aiVolatile.memory.backstandAlignment.mat[1].z = (float)((float)v28 * v25) - (float)(v26 * (float)v27);
        ai->aiVolatile.memory.backstandAlignment.mat[2].x = v25;
        ai->aiVolatile.memory.backstandAlignment.mat[2].y = v26;
        ai->aiVolatile.memory.backstandAlignment.mat[2].z = v29;
        idAI2::ClearAimFocus(this: ai);
        idAI2::ClearLookFocus(this: ai);
        idAIFireControl::SetFireMode(this: ai->aiVolatile.fireControl, owner: ai, mode: FIREMODE_HOLDFIRE);
        idAIState::ClearQueuedActions(this, ai, parentFSM: fsm, curTime);
        v81[1] = nullptr;
        v80[1] = nullptr;
        v78[0].y = x;
        v78[0].z = y;
        v78[1].x = z;
        v79[1] = 5.0;
        HIBYTE(v81[0]) = 105;
        v77[0].z = vec3_origin.y;
        HIBYTE(v77[0].x) = 118;
        v77[1].x = vec3_origin.z;
        HIBYTE(v79[0]) = 102;
        HIBYTE(v82[0]) = 105;
        LODWORD(v82[1]) = 1;
        HIBYTE(v78[0].x) = 118;
        HIBYTE(v80[0]) = 105;
        v77[0].y = vec3_origin.x;
        v31 = idEventArg::idEventArg(this: &v83, data: ai);
        memcpy(Dst: v76, Src: v77, Size: sizeof(v76));
        memcpy(Dst: v75, Src: v81, Size: sizeof(v75));
        memcpy(Dst: v74, Src: v79, Size: sizeof(v74));
        memcpy(Dst: v73, Src: v82, Size: sizeof(v73));
        memcpy(Dst: v72, Src: v78, Size: sizeof(v72));
        idEventReceiver::ProcessEvent(
          this: (idEventReceiver *)v84,
          result: (idEventArg *)&ai->aiVolatile.fsms.actionManager.legsFSM.actionsQueue,
          ev: *(const idEventDef **)&v31->type,
          arg1: (const idEventArg *)LODWORD(v31->value.v[1]),
          arg2: (const idEventArg *)LODWORD(v31->value.v[2]),
          arg3: (const idEventArg *)__ROL4__(v80[0], 32),
          arg4: v80[2],
          arg5: v80[3],
          arg6: v70,
          arg7: v71);
LABEL_21:
        idAIState::StartQueuedActions(this, ai, parentFSM: fsm, curTime);
      }
    }
  }
  else
  {
    v32 = FindBestHint(ai);
    if ( v32 != nullptr )
    {
      v33 = gameLocal;
      v34 = ai->aiVolatile.memory.backstandHint.spawnId.value;
      if ( gameLocal->spawnIds.ptr[v34 & 0x1FFF] == v34 >> 13
        && (v35 = gameLocal->entities.ptr[v34 & 0x1FFF]) != nullptr )
      {
        v36 = idEntity::CastTo(c: v35);
        v33 = gameLocal;
      }
      else
      {
        v36 = nullptr;
      }
      if ( v32 != v36 )
      {
        ai->aiVolatile.memory.backstandHint.spawnId.value = (v33->spawnIds.ptr[v32->entityNumber] << 13)
                                                          | v32->entityNumber;
        v37 = v32->spawnOrientation.mat[1].z;
        v38 = v32->spawnOrientation.mat[1].x;
        v77[0].y = v32->spawnOrientation.mat[1].y;
        v77[0].x = v38;
        v77[0].z = v37;
        v39 = idEntity::GetPhysics(this: ai);
        v40 = (float *)v39->GetOrigin(this: v39, a2: 0);
        v41 = idEntity::GetPhysics(this: v32);
        v42 = (float *)v41->GetOrigin(this: v41, a2: 0);
        v43 = v77[0].y;
        p_spawnOrientation = (float *)&v32->spawnOrientation;
        v45 = v77[0].z;
        p_backstandAlignment = &ai->aiVolatile.memory.backstandAlignment;
        v47 = v77[0].x;
        v48 = v32->spawnOrientation.mat[2].y;
        v49 = v32->spawnOrientation.mat[2].z;
        if ( (float)((float)((float)(*v42 - *v40) * v77[0].x)
                   + (float)((float)(v77[0].z * (float)(v42[2] - v40[2])) + (float)(v77[0].y * (float)(v42[1] - v40[1])))) >= 0.0 )
        {
          v57 = -v32->spawnOrientation.mat[0].x;
          v58 = -v32->spawnOrientation.mat[0].y;
          v59 = -v32->spawnOrientation.mat[0].z;
          v60 = v32->spawnOrientation.mat[1].y;
          v61 = v32->spawnOrientation.mat[1].z;
          v62 = v32->spawnOrientation.mat[2].x;
          p_backstandAlignment->mat[0].x = v32->spawnOrientation.mat[1].x;
          ai->aiVolatile.memory.backstandAlignment.mat[1].x = v57;
          ai->aiVolatile.memory.backstandAlignment.mat[0].y = v60;
          ai->aiVolatile.memory.backstandAlignment.mat[0].z = v61;
          ai->aiVolatile.memory.backstandAlignment.mat[1].y = v58;
          ai->aiVolatile.memory.backstandAlignment.mat[1].z = v59;
          v56 = 182.39999;
          ai->aiVolatile.memory.backstandAlignment.mat[2].x = v62;
        }
        else
        {
          v50 = -v32->spawnOrientation.mat[1].y;
          v51 = v32->spawnOrientation.mat[0].x;
          v52 = -v32->spawnOrientation.mat[1].z;
          v53 = v32->spawnOrientation.mat[2].x;
          v47 = -v47;
          v54 = v32->spawnOrientation.mat[0].y;
          v43 = -v43;
          v55 = v32->spawnOrientation.mat[0].z;
          v45 = -v45;
          p_backstandAlignment->mat[0].x = -v32->spawnOrientation.mat[1].x;
          ai->aiVolatile.memory.backstandAlignment.mat[1].x = v51;
          ai->aiVolatile.memory.backstandAlignment.mat[0].y = v50;
          ai->aiVolatile.memory.backstandAlignment.mat[0].z = v52;
          ai->aiVolatile.memory.backstandAlignment.mat[1].y = v54;
          ai->aiVolatile.memory.backstandAlignment.mat[1].z = v55;
          v56 = 164.3;
          ai->aiVolatile.memory.backstandAlignment.mat[2].x = v53;
        }
        ai->aiVolatile.memory.backstandAlignment.mat[2].y = v48;
        ai->aiVolatile.memory.backstandAlignment.mat[2].z = v49;
        v63 = ai->aiEditable.behaviors.decl;
        v64 = (float)(v32->spawnPosition.y
                    + (float)(v63->backstandBehaviors.approachDistance * v32->spawnOrientation.mat[0].y));
        v65 = (float)(v32->spawnPosition.z
                    + (float)(v63->backstandBehaviors.approachDistance * v32->spawnOrientation.mat[0].z));
        v66 = (float)((float)((float)(*p_spawnOrientation * v63->backstandBehaviors.approachDistance)
                            + v32->spawnPosition.x)
                    - (float)((float)v47 * (float)v56));
        ai->aiVolatile.memory.backstandRisePosition.x = (float)((float)(*p_spawnOrientation
                                                                      * v63->backstandBehaviors.approachDistance)
                                                              + v32->spawnPosition.x)
                                                      - (float)((float)v47 * (float)v56);
        v67 = (float)((float)v64 - (float)((float)v43 * (float)v56));
        ai->aiVolatile.memory.backstandRisePosition.y = (float)v64 - (float)((float)v43 * (float)v56);
        v68 = (float)((float)v65 - (float)((float)v45 * (float)v56));
        ai->aiVolatile.memory.backstandRisePosition.z = (float)v65 - (float)((float)v45 * (float)v56);
        idAI2::ClearAimFocus(this: ai);
        idAI2::ClearLookFocus(this: ai);
        idAIFireControl::SetFireMode(this: ai->aiVolatile.fireControl, owner: ai, mode: FIREMODE_HOLDFIRE);
        idAIState::ClearQueuedActions(this, ai, parentFSM: fsm, curTime);
        v78[0].y = v47;
        v78[0].z = v43;
        v78[1].x = v45;
        v77[0].y = v66;
        v82[1] = 1.0;
        v77[0].z = v67;
        HIBYTE(v78[0].x) = 118;
        v77[1].x = v68;
        HIBYTE(v80[0]) = 105;
        v80[1] = (const idEventArg *)1;
        HIBYTE(v82[0]) = 102;
        HIBYTE(v79[0]) = 105;
        LODWORD(v79[1]) = 1;
        HIBYTE(v77[0].x) = 118;
        HIBYTE(v81[0]) = 105;
        v81[1] = nullptr;
        v69 = idEventArg::idEventArg(this: v84, data: ai);
        memcpy(Dst: v76, Src: v78, Size: sizeof(v76));
        memcpy(Dst: v75, Src: v80, Size: sizeof(v75));
        memcpy(Dst: v74, Src: v82, Size: sizeof(v74));
        memcpy(Dst: v73, Src: v79, Size: sizeof(v73));
        memcpy(Dst: v72, Src: v77, Size: sizeof(v72));
        idEventReceiver::ProcessEvent(
          this: (idEventReceiver *)&v83,
          result: (idEventArg *)&ai->aiVolatile.fsms.actionManager.legsFSM.actionsQueue,
          ev: *(const idEventDef **)&v69->type,
          arg1: (const idEventArg *)LODWORD(v69->value.v[1]),
          arg2: (const idEventArg *)LODWORD(v69->value.v[2]),
          arg3: (const idEventArg *)__ROL4__(LODWORD(v69->value.q[3]), 32),
          arg4: v81[2],
          arg5: v81[3],
          arg6: v70,
          arg7: v71);
        goto LABEL_21;
      }
    }
  }
}


// ========================================================================
// ?AIState_EnterState@idBackStand_Rising@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AC5C18
// RVA : 0x00AC5C18
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_backstand.cpp
// ========================================================================

void __fastcall idBackStand_Rising::AIState_EnterState(idBackStand_Rising *this, idAI2 *ai, idAIFSM *fsm, int curTime)
{
  int value; // r8
  idEntity *v9; // r3
  idEntity *v10; // r30
  idVec3 *v11; // r10
  idEntityPtr<idEntity const > *p_backstandHint; // r11
  int i; // ctr
  const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *v14; // r29
  const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *v15; // r28
  const idQuat *v16; // r3
  idEntity *BestHint; // r3
  float *v18; // r30
  idEntityPtr<idEntity const > *v19; // r9
  idPresentable *presentable; // r11
  unsigned __int16 v21; // [sp+50h] [-80h] BYREF
  unsigned __int16 v22; // [sp+52h] [-7Eh] BYREF
  unsigned __int16 v23; // [sp+54h] [-7Ch] BYREF
  idMat3 v24[3]; // [sp+60h] [-70h] BYREF

  if ( (*((_BYTE *)ai->aiEditable.behaviors.decl + 429) & 0x80) != 0 )
  {
    idAI2::SetEnableAutoFocus(this: ai, enable: false);
    value = ai->aiVolatile.memory.backstandHint.spawnId.value;
    if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
      && (v9 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
    {
      v10 = idEntity::CastTo(c: v9);
    }
    else
    {
      v10 = nullptr;
    }
    v10->ActivateTargets(this: v10, a2: ai);
    v11 = &v24[0].mat[1];
    p_backstandHint = &ai->aiVolatile.memory.backstandHint;
    for ( i = 9; i != 0; --i )
    {
      ++p_backstandHint;
      v11 = (idVec3 *)((char *)v11 + 4);
      LODWORD(v11->x) = (idEntityPtr<idEntity const >)p_backstandHint->spawnId.value;
    }
    ai->aiVolatile.animation.animWebAnimator.ptr[0].select01 = -(float)((float)((float)((float)((float)(v10->spawnOrientation.mat[1].x * v24[0].mat[1].y)
                                                                                              + (float)((float)(v10->spawnOrientation.mat[1].y * v24[0].mat[1].z) + (float)(v10->spawnOrientation.mat[1].z * v24[0].mat[2].x)))
                                                                                      + (float)1.0)
                                                                              * (float)0.5)
                                                                      - (float)1.0);
    idAIState::ClearQueuedActions(this, ai, parentFSM: fsm, curTime);
    idDeclAnimWeb::GetSubWebIndexForName(
      this: (idDeclAnimWeb *)&v22,
      result: (idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)ai->aiVolatile.animation.animWebAnimator.ptr[0].decl,
      subWebName: "backstand");
    idDeclAnimWeb::GetStateIndexForName(
      this: (idDeclAnimWeb *)&v21,
      result: (idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)ai->aiVolatile.animation.animWebAnimator.ptr[0].decl,
      name: "rise");
    idDeclAnimWeb::GetStateIndexForName(
      this: (idDeclAnimWeb *)&v23,
      result: (idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)ai->aiVolatile.animation.animWebAnimator.ptr[0].decl,
      name: "idle");
    idAI2::WaitForAnimToStartVia(
      this: ai,
      awt: AIANIMWEB_BODY,
      priority: PRIORITY_LOW,
      dswi: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)v22,
      dsi: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)v23,
      vswi: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)v22,
      vsi: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)v21,
      ev: ANIMWEB_EVENT_START_BLEND_IN);
    v14 = (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)v21;
    v15 = (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)v22;
    v16 = idMat3::ToQuat(this: v24, result: (idQuat *)&v24[0].mat[1].y);
    idAIMoveState::StartPerfectOrigin(
      this: &ai->aiVolatile.physics.moveState,
      idealAxis: v16,
      idealPos: &ai->aiVolatile.memory.backstandRisePosition,
      lerpTimeMs: 400,
      swi: v15,
      si: v14);
  }
  else
  {
    idAI2::SetEnableAutoFocus(this: ai, enable: false);
    BestHint = FindBestHint(ai);
    v18 = (float *)BestHint;
    v19 = &ai->aiVolatile.memory.backstandHint;
    if ( BestHint != nullptr )
      v19->spawnId.value = (gameLocal->spawnIds.ptr[BestHint->entityNumber] << 13) | BestHint->entityNumber;
    else
      v19->spawnId.value = 0x1FFF;
    BestHint->ActivateTargets(this: BestHint, a2: ai);
    idAI2::SetAxis(this: ai, axis: &ai->aiVolatile.memory.backstandAlignment);
    idEntity::SetOrigin(this: ai, org: &ai->aiVolatile.memory.backstandRisePosition);
    idAIMoveState::SetMovementModeForReal(this: &ai->aiVolatile.physics.moveState, mode: AIMOVEMODE_STATIC);
    idAIState::ClearQueuedActions(this, ai, parentFSM: fsm, curTime);
    presentable = ai->presentable;
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this: ai);
      presentable = ai->presentable;
    }
    if ( (float)((float)(presentable->axis.mat[0].x * v18[17])
               + (float)((float)(presentable->axis.mat[0].z * v18[19]) + (float)(presentable->axis.mat[0].y * v18[18]))) <= 0.0 )
      idAI2::WaitForAnimToStartVia(
        this: ai,
        awt: AIANIMWEB_BODY,
        priority: PRIORITY_LOW,
        subWebName: "backstand",
        stateName: "idle",
        viaSubWebName: "backstand",
        viaStateName: "rise_right",
        ev: ANIMWEB_EVENT_START_BLEND_IN);
    else
      idAI2::WaitForAnimToStartVia(
        this: ai,
        awt: AIANIMWEB_BODY,
        priority: PRIORITY_LOW,
        subWebName: "backstand",
        stateName: "idle",
        viaSubWebName: "backstand",
        viaStateName: "rise_left",
        ev: ANIMWEB_EVENT_START_BLEND_IN);
  }
}


// ========================================================================
// ?AIState_EnterState@idBackStand_Lowering@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AC5F28
// RVA : 0x00AC5F28
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_backstand.cpp
// ========================================================================

void __fastcall idBackStand_Lowering::AIState_EnterState(
        idBackStand_Lowering *this,
        idAI2 *ai,
        idAIFSM *fsm,
        int curTime)
{
  const char *v8; // r9

  idAIMoveState::SetMovementModeForReal(this: &ai->aiVolatile.physics.moveState, mode: AIMOVEMODE_STATIC);
  idAIState::ClearQueuedActions(this, ai, parentFSM: fsm, curTime);
  if ( GetEnemySide(ai) >= 0 )
    v8 = "down_right";
  else
    v8 = "down_left";
  idAI2::WaitForAnimToStartVia(
    this: ai,
    awt: AIANIMWEB_BODY,
    priority: PRIORITY_LOW,
    subWebName: "hands_combat",
    stateName: "idle",
    viaSubWebName: "backstand",
    viaStateName: v8,
    ev: ANIMWEB_EVENT_START_BLEND_IN);
  ai->aiVolatile.memory.backstandHint.spawnId.value = 0x1FFF;
}

