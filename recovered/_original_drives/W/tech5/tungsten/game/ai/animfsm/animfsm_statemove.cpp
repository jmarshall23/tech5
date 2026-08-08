
// ========================================================================
// ?Enter@idAnimStateMoveGround@@UAAXPAVidAI2@@PAVidAnimBaseFSM@@@Z
// EA  : 0x82A7FAE0
// RVA : 0x00A7FAE0
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm_statemove.cpp
// ========================================================================

void __fastcall idAnimStateMoveGround::Enter(idAnimStateMoveGround *this, idAI2 *ai, idAnimBaseFSM *fsm)
{
  this->playedDeparture = false;
  idAnimBaseFSM::ReleaseAllNavTraces(this: fsm);
  idAIStateLite::SetSubState(this, newSubState: 0);
}


// ========================================================================
// ?InternalEnter@idAnimStateDead@@MAAXPAVidAI2@@PAVidAIFSMLite@@@Z
// EA  : 0x82A7FB30
// RVA : 0x00A7FB30
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm_statemove.cpp
// ========================================================================

void __fastcall idAnimStateDead::InternalEnter(idAnimStateDead *this, idAI2 *ai, idAnimBaseFSM *fsm)
{
  this->Enter(this, a2: ai, a3: fsm);
}


// ========================================================================
// ?InternalReEnter@idAnimStateIdleGround@@MAAXPAVidAI2@@PAVidAIFSMLite@@@Z
// EA  : 0x82A7FB40
// RVA : 0x00A7FB40
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm_statemove.cpp
// ========================================================================

void __fastcall idAnimStateIdleGround::InternalReEnter(idAnimStateDead *this, idAI2 *ai, idAnimBaseFSM *fsm)
{
  this->ReEnter(this, a2: ai, a3: fsm);
}


// ========================================================================
// ?InternalExit@idAnimStateIdleGround@@MAAXPAVidAI2@@PAVidAIFSMLite@@@Z
// EA  : 0x82A7FB50
// RVA : 0x00A7FB50
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm_statemove.cpp
// ========================================================================

void __fastcall idAnimStateIdleGround::InternalExit(idAnimStateDead *this, idAI2 *ai, idAnimBaseFSM *fsm)
{
  this->Exit(this, a2: ai, a3: fsm);
}


// ========================================================================
// ?InternalWork@idAnimStateMoveGround@@MAAHPAVidAI2@@PAVidAIFSMLite@@@Z
// EA  : 0x82A7FB60
// RVA : 0x00A7FB60
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm_statemove.cpp
// ========================================================================

int __fastcall idAnimStateMoveGround::InternalWork(idAnimStateDead *this, idAI2 *ai, idAnimBaseFSM *fsm)
{
  return this->Work(this, a2: ai, a3: fsm);
}


// ========================================================================
// ?GetStateFlags@idAnimStateMoveGround@@UBAHXZ
// EA  : 0x82A7FBE8
// RVA : 0x00A7FBE8
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm_statemove.cpp
// ========================================================================

int __fastcall idAnimStateMoveGround::GetStateFlags(idAnimStateMoveGround *this)
{
  int subState; // r11
  int result; // r3

  subState = this->subState;
  result = subState == 9;
  if ( subState == 6 )
    result |= 2u;
  if ( subState == 7 )
    return result | 4;
  return result;
}


// ========================================================================
// ?Exit@idAnimStateMoveGround@@UAAXPAVidAI2@@PAVidAnimBaseFSM@@@Z
// EA  : 0x82A7FC18
// RVA : 0x00A7FC18
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm_statemove.cpp
// ========================================================================

void __fastcall idAnimStateMoveGround::Exit(idAnimStateMoveGround *this, idAI2 *ai, idAnimBaseFSM *fsm)
{
  ai->aiVolatile.memory.temporaryHoldFire = false;
  idAnimBaseFSM::ReleaseAllNavTraces(this: fsm);
  idAnimWebTransitions::transitionCache_t::Clear(this: &fsm->arrivalTransitionCache);
  idAnimWebTransitions::transitionCache_t::Clear(this: &fsm->turnTransitionCache);
  idAnimWebTransitions::transitionCache_t::Clear(this: &fsm->departureTransitionCache);
  fsm->emergencyLerp = false;
}


// ========================================================================
// ?UpdateStopping@idAnimStateMoveGround@@IAAHPAVidAI2@@PAVidAnimBaseFSM@@@Z
// EA  : 0x82A7FC80
// RVA : 0x00A7FC80
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm_statemove.cpp
// ========================================================================

int __fastcall idAnimStateMoveGround::UpdateStopping(idAnimStateMoveGround *this, idAI2 *ai, idAnimBaseFSM *fsm)
{
  const idVec3 *v6; // r3
  int overrideMoveFlags; // r3
  double v8; // fp6
  double v11; // fp2
  double v12; // fp3
  double v13; // fp2
  double v14; // fp30
  int result; // r3
  void (__fastcall *SetLinearVelocity)(struct idPhysics_AI *, const idVec3 *, int); // ctr
  __int64 v19; // [sp+50h] [-C0h] BYREF
  idVec3 v20; // [sp+60h] [-B0h] BYREF
  float v21[4]; // [sp+70h] [-A0h] BYREF
  idAnimWebTransitions::transitionQueryResult_t v22; // [sp+80h] [-90h] BYREF

  if ( (unsigned __int8)idAnimBaseFSM::GetUserChannelIsDeltaDriven(this: fsm) != 0 )
    return 1;
  ai->aiVolatile.physics.object.GetLinearVelocity(
    this: (struct idPhysics_AI *)&v20,
    result: (idVec3 *)&ai->aiVolatile,
    a3: 0);
  v6 = fsm->GetNavUpAxis(this: &v19, result: fsm);
  idVec3::ProjectOntoPlane(this: &v20, normal: v6, overBounce: 1.0);
  overrideMoveFlags = fsm->overrideMoveFlags;
  v8 = (float)((float)(v20.z * v20.z) + (float)((float)(v20.y * v20.y) + (float)(v20.x * v20.x)));
  _FP5 = (float)((float)((float)(v20.z * v20.z) + (float)((float)(v20.y * v20.y) + (float)(v20.x * v20.x)))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f3, f5, f6, f13 }
  v11 = __frsqrte(_FP3);
  v12 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v11
                                                                                      * (float)((float)((float)(v20.z * v20.z) + (float)((float)(v20.y * v20.y) + (float)(v20.x * v20.x)))
                                                                                              * (float)0.5))
                                                                              * (float)v11)
                                                                      - (float)1.5)
                                                      * (float)v11)
                                              * (float)((float)((float)(v20.z * v20.z)
                                                              + (float)((float)(v20.y * v20.y) + (float)(v20.x * v20.x)))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v11
                                                                              * (float)((float)((float)(v20.z * v20.z)
                                                                                              + (float)((float)(v20.y * v20.y) + (float)(v20.x * v20.x)))
                                                                                      * (float)0.5))
                                                                      * (float)v11)
                                                              - (float)1.5)
                                              * (float)v11))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v11
                                                      * (float)((float)((float)(v20.z * v20.z)
                                                                      + (float)((float)(v20.y * v20.y)
                                                                              + (float)(v20.x * v20.x)))
                                                              * (float)0.5))
                                              * (float)v11)
                                      - (float)1.5)
                      * (float)v11));
  v13 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v11
                                                                                              * (float)((float)((float)(v20.z * v20.z) + (float)((float)(v20.y * v20.y) + (float)(v20.x * v20.x))) * (float)0.5))
                                                                                      * (float)v11)
                                                                              - (float)1.5)
                                                              * (float)v11)
                                                      * (float)((float)((float)(v20.z * v20.z)
                                                                      + (float)((float)(v20.y * v20.y)
                                                                              + (float)(v20.x * v20.x)))
                                                              * (float)0.5))
                                              * (float)((float)-(float)((float)((float)((float)v11
                                                                                      * (float)((float)((float)(v20.z * v20.z) + (float)((float)(v20.y * v20.y) + (float)(v20.x * v20.x)))
                                                                                              * (float)0.5))
                                                                              * (float)v11)
                                                                      - (float)1.5)
                                                      * (float)v11))
                                      - (float)1.5)
                      * (float)((float)-(float)((float)((float)((float)v11
                                                              * (float)((float)((float)(v20.z * v20.z)
                                                                              + (float)((float)(v20.y * v20.y)
                                                                                      + (float)(v20.x * v20.x)))
                                                                      * (float)0.5))
                                                      * (float)v11)
                                              - (float)1.5)
                              * (float)v11))
              * (float)((float)((float)(v20.z * v20.z) + (float)((float)(v20.y * v20.y) + (float)(v20.x * v20.x)))
                      * (float)0.5));
  v20.x = v20.x * (float)((float)-(float)((float)((float)v13 * (float)v12) - (float)1.5) * (float)v12);
  v20.y = v20.y * (float)((float)-(float)((float)((float)v13 * (float)v12) - (float)1.5) * (float)v12);
  v20.z = (float)((float)-(float)((float)((float)v13 * (float)v12) - (float)1.5) * (float)v12) * v20.z;
  v14 = (float)((float)((float)-(float)((float)((float)v13 * (float)v12) - (float)1.5) * (float)v12) * (float)v8);
  if ( (overrideMoveFlags & 0x1000) == 0 )
  {
    idAnimWebTransitions::transitionQueryResult_t::transitionQueryResult_t(this: &v22);
    if ( idAnimBaseFSM::UpdateTransitionToDestination(this: fsm, transInfo: &v22, transType: 6) != 0
      && (unsigned __int8)idAnimBaseFSM::StartArrivalAnimation(
                            this: fsm,
                            transInfo: &v22,
                            destinationOrigin: &v22.destOrigin,
                            force: true,
                            transType: TRANSITION_SOFTSTOP) != 0 )
    {
      idAnimWebTransitions::CleanupNavTraces(ai, cache: &fsm->arrivalTransitionCache);
      idAIStateLite::SetSubState(this, newSubState: 6);
      return 1;
    }
  }
  v19 = __PAIR64__(&unk_82390000, gameLocal->GetGameMsPerFrame(this: gameLocal, a2: GAMETIME_SCALED));
  SetLinearVelocity = ai->aiVolatile.physics.object.SetLinearVelocity;
  _FP5 = (float)-(float)((float)((float)((float)v19 * (float)0.001) * (float)1200.0) - (float)v14);
  __asm { fsel      f30, f5, f5, f31 }
  v21[0] = v20.x * (float)_FP30;
  v21[1] = v20.y * (float)_FP30;
  v21[2] = v20.z * (float)_FP30;
  SetLinearVelocity(this: &ai->aiVolatile.physics.object, a2: (const idVec3 *)v21, a3: 0);
  result = 4;
  if ( _FP30 != 0.0 )
    return 1;
  return result;
}


// ========================================================================
// ?FSMEvent_StartArrival@idAnimStateMoveGround@@IAA?AVeventVoid@@XZ
// EA  : 0x82A7FEB8
// RVA : 0x00A7FEB8
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm_statemove.cpp
// ========================================================================

idAnimStateMoveGround *__fastcall idAnimStateMoveGround::FSMEvent_StartArrival(
        idAnimStateMoveGround *this,
        idAIStateLite *result)
{
  idAIStateLite::SetSubState(this: result, newSubState: 5);
  return this;
}


// ========================================================================
// ?FSMEvent_StartDeparture@idAnimStateMoveGround@@IAA?AVeventVoid@@XZ
// EA  : 0x82A7FEF0
// RVA : 0x00A7FEF0
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm_statemove.cpp
// ========================================================================

idAnimStateMoveGround *__fastcall idAnimStateMoveGround::FSMEvent_StartDeparture(
        idAnimStateMoveGround *this,
        idAIStateLite *result)
{
  idAIStateLite::SetSubState(this: result, newSubState: 4);
  return this;
}


// ========================================================================
// ?FSMEvent_StartStepTransition@idAnimStateMoveGround@@IAA?AVeventVoid@@XZ
// EA  : 0x82A7FF28
// RVA : 0x00A7FF28
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm_statemove.cpp
// ========================================================================

idAnimStateMoveGround *__fastcall idAnimStateMoveGround::FSMEvent_StartStepTransition(
        idAnimStateMoveGround *this,
        idAIStateLite *result)
{
  idAIStateLite::SetSubState(this: result, newSubState: 1);
  return this;
}


// ========================================================================
// ?FSMEvent_DepartureReturnToMove@idAnimStateMoveGround@@IAA?AVeventVoid@@XZ
// EA  : 0x82A7FF60
// RVA : 0x00A7FF60
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm_statemove.cpp
// ========================================================================

idAnimStateMoveGround *__fastcall idAnimStateMoveGround::FSMEvent_DepartureReturnToMove(
        idAnimStateMoveGround *this,
        idAIStateLite *result)
{
  HIBYTE(result[11].listenerList) = 1;
  idAIStateLite::SetSubState(this: result, newSubState: 0);
  return this;
}


// ========================================================================
// ?FSMEvent_AnimEventLunge@idAnimStateMoveGround@@IAA?AVeventVoid@@XZ
// EA  : 0x82A7FFA8
// RVA : 0x00A7FFA8
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm_statemove.cpp
// ========================================================================

idAnimStateMoveGround *__fastcall idAnimStateMoveGround::FSMEvent_AnimEventLunge(
        idAnimStateMoveGround *this,
        idAIStateLite *result)
{
  if ( result->subState == 15 )
    idAIStateLite::SetSubState(this: result, newSubState: 16);
  return this;
}


// ========================================================================
// ??0idAnimStateMoveGround@@QAA@XZ
// EA  : 0x82A80000
// RVA : 0x00A80000
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm_statemove.cpp
// ========================================================================

idAnimStateMoveGround *__fastcall idAnimStateMoveGround::idAnimStateMoveGround(idAnimStateMoveGround *this)
{
  float z; // r8

  idAIStateLite::idAIStateLite(this);
  this->__vftable = (idAnimStateMoveGround_vtbl *)&idAnimStateMoveGround::`vftable';
  this->leapAnimSet.animInto.len = 0;
  this->leapAnimSet.animInto.allocedAndFlag = 20;
  this->leapAnimSet.animInto.data = this->leapAnimSet.animInto.baseBuffer;
  this->leapAnimSet.animInto.baseBuffer[0] = 0;
  this->leapAnimSet.animFlight.data = this->leapAnimSet.animFlight.baseBuffer;
  this->leapAnimSet.animFlight.allocedAndFlag = 20;
  this->leapAnimSet.animFlight.len = 0;
  this->leapAnimSet.animFlight.baseBuffer[0] = 0;
  this->leapAnimSet.animLand.allocedAndFlag = 20;
  this->leapAnimSet.animLand.data = this->leapAnimSet.animLand.baseBuffer;
  this->leapAnimSet.animLand.len = 0;
  this->leapAnimSet.animLand.baseBuffer[0] = 0;
  this->leapAnimSet.animLandPost.allocedAndFlag = 20;
  this->leapAnimSet.animLandPost.data = this->leapAnimSet.animLandPost.baseBuffer;
  this->leapAnimSet.animLandPost.len = 0;
  this->leapAnimSet.animLandPost.baseBuffer[0] = 0;
  this->fallEndHeight = 0.0;
  this->turnInfo.upcomingTurnPoint = vec3_origin;
  this->turnInfo.upcomingTurnPointWithBackoff.x = vec3_origin.x;
  this->turnInfo.upcomingTurnPointWithBackoff.y = vec3_origin.y;
  z = vec3_origin.z;
  this->turnInfo.distanceToTurnPointSqr = 0.0;
  this->turnInfo.hasUpcomingTurnPoint = false;
  this->turnInfo.canExecuteUpcomingTurn = false;
  this->turnInfo.upcomingTurnPointWithBackoff.z = z;
  this->playedDeparture = false;
  idAIStateLite::SetSubState(this, newSubState: 0);
  return this;
}


// ========================================================================
// __unwind$490080
// EA  : 0x82A80120
// RVA : 0x00A80120
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm_statemove.cpp
// ========================================================================

void _unwind_490080()
{
  int v0; // r12

  idAnimStateDead::~idAnimStateDead(this: *(idAIStateLite **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$490081
// EA  : 0x82A80148
// RVA : 0x00A80148
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm_statemove.cpp
// ========================================================================

void _unwind_490081()
{
  int v0; // r12

  leapAnimSet_t::~leapAnimSet_t(this: (leapAnimSet_t *)(*(_DWORD *)(v0 - 112 + 132) + 16));
}


// ========================================================================
// ?InternalShouldStartLink@idAnimStateMoveGround@@MAA_NPAVidAI2@@PAVidAnimBaseFSM@@AAUidNpCornerInfo@@2@Z
// EA  : 0x82A801D8
// RVA : 0x00A801D8
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm_statemove.cpp
// ========================================================================

int __fastcall idAnimStateMoveGround::InternalShouldStartLink(
        idAnimStateMoveGround *this,
        idAI2 *ai,
        idAnimBaseFSM *fsm,
        idNpCornerInfo *linkStart,
        idNpCornerInfo *linkEnd)
{
  idAnimWebCmdCtx *v9; // r3
  idNpCornerInfo *list; // r31
  idPhysics *Physics; // r3
  float *v12; // r3

  if ( fsm->nextLinkCorner != 0 )
    return 0;
  v9 = ai->GetAnimWebCmdCtx(this: ai);
  if ( !idAnimWebCmdCtx::IsGroupAllowed(this: v9, _groupBits: 0x20000u) )
    return 0;
  list = fsm->cachedCorners.list;
  if ( list->cornerType != CORNER_LINKSTART )
    return 0;
  if ( list[1].cornerType != CORNER_LINKEND )
    return 0;
  Physics = idEntity::GetPhysics(this: ai);
  v12 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
  if ( (float)((float)((float)(*v12 - list->position.x) * (float)(*v12 - list->position.x))
             + (float)((float)((float)(v12[2] - list->position.z) * (float)(v12[2] - list->position.z))
                     + (float)((float)(v12[1] - list->position.y) * (float)(v12[1] - list->position.y)))) >= (double)(float)(list->mayUseDist * list->mayUseDist) )
    return 0;
  idNpCornerInfo::operator=(this: linkStart, __that: list);
  idNpCornerInfo::operator=(this: linkEnd, __that: list + 1);
  return 1;
}


// ========================================================================
// ?UpdateFallTraversal@idAnimStateMoveGround@@IAAHPAVidAI2@@PAVidAnimBaseFSM@@@Z
// EA  : 0x82A802F8
// RVA : 0x00A802F8
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm_statemove.cpp
// ========================================================================

int __fastcall idAnimStateMoveGround::UpdateFallTraversal(idAnimStateMoveGround *this, idAI2 *ai, idAnimBaseFSM *fsm)
{
  idIndex<short,enum invalidJointIndex_t> *TreeAnimatorFromPresentable; // r3
  idTreeAnimator *v7; // r28
  unsigned int v8; // r3
  idPhysics *Physics; // r3
  idPhysics *v10; // r29
  __int64 v11; // r6
  double v12; // fp31
  float *v13; // r3
  double v14; // fp4
  double v15; // fp3
  idPhysics *v16; // r3
  idPhysics *v17; // r3
  int v18; // r3
  double fallEndHeight; // fp13
  int v20; // r11
  int v21; // r10
  double v22; // fp31
  idPhysics *v23; // r3
  idPhysics *v24; // r3
  idPhysics *v25; // r3
  double v26; // fp0
  idAnimWebCmdCtx *v27; // r3
  idAIAnimWebState_Movement *v28; // r3
  const idAnimWebState *v29; // r4
  idAnimWebCmd *v30; // r3
  idAnimWebCmd *v31; // r3
  int flags; // r11
  idIndex<short,enum invalidJointIndex_t> v34[4]; // [sp+50h] [-180h] BYREF
  float v35; // [sp+58h] [-178h] BYREF
  float v36; // [sp+5Ch] [-174h]
  float v37; // [sp+60h] [-170h]
  _DWORD v38[2]; // [sp+68h] [-168h] BYREF
  float v39; // [sp+70h] [-160h]
  __int64 v40; // [sp+78h] [-158h]
  idVec3 v41; // [sp+80h] [-150h] BYREF
  idAIAnimWebState_Movement v42; // [sp+90h] [-140h] BYREF
  idMat3 v43; // [sp+B0h] [-120h] BYREF
  idAnimWebCmd v44; // [sp+E0h] [-F0h] BYREF

  TreeAnimatorFromPresentable = (idIndex<short,enum invalidJointIndex_t> *)idAnimatedEntity::GetTreeAnimatorFromPresentable(this: ai);
  v7 = (idTreeAnimator *)TreeAnimatorFromPresentable;
  if ( this->subState != 9 )
  {
    idTreeAnimator::GetJointIndex(this: (idTreeAnimator *)v34, result: TreeAnimatorFromPresentable, jointName: "hips");
    idTreeAnimator::GetWorldSpaceJointFrameDeltas(
      this: v7,
      indices: v34,
      numIndices: 1,
      transDeltas: &v41,
      rotDeltas: &v43);
    if ( fsm->animWaitHandle.status == AWCMD_STATUS_WAITING )
      return 1;
    v8 = gameLocal->GetGameMsPerFrame(this: gameLocal, a2: GAMETIME_SCALED);
    idPhysics_AI::SetDelta(this: &ai->aiVolatile.physics.object, d: &v41, ticksPerFrame: v8);
    idAIStateLite::SetSubState(this, newSubState: 9);
  }
  Physics = idEntity::GetPhysics(this: ai);
  Physics->GetLinearVelocity(this: (idPhysics *)&v35, result: (idVec3 *)Physics, a3: 0);
  v10 = idEntity::GetPhysics(this: ai);
  LODWORD(v11) = gameLocal->GetGameMsPerFrame(this: gameLocal, a2: GAMETIME_SCALED);
  HIDWORD(v11) = v10->__vftable;
  v40 = v11;
  v12 = (float)((float)v11 * (float)0.001);
  v13 = (float *)(*(int (__fastcall **)(idPhysics *))(HIDWORD(v11) + 100))(a1: v10);
  v14 = (float)(v13[2] * (float)v12);
  v15 = (float)(v13[1] * (float)v12);
  v35 = (float)(*v13 * (float)v12) + v35;
  v37 = (float)v14 + v37;
  v36 = v36 + (float)v15;
  v16 = idEntity::GetPhysics(this: ai);
  v16->SetLinearVelocity(this: v16, a2: (const idVec3 *)&v35, a3: 0);
  v17 = idEntity::GetPhysics(this: ai);
  v18 = (int)v17->GetOrigin(this: v17, a2: 0);
  fallEndHeight = this->fallEndHeight;
  v20 = *(_DWORD *)v18;
  v21 = *(_DWORD *)(v18 + 4);
  v39 = *(float *)(v18 + 8);
  v38[0] = v20;
  v22 = (float)(v39 - (float)fallEndHeight);
  v38[1] = v21;
  v23 = idEntity::GetPhysics(this: ai);
  if ( v23->GetClipMask(this: v23, a2: -1) != 0 || v22 >= 48.0 )
  {
    v25 = idEntity::GetPhysics(this: ai);
    if ( v25->GetClipMask(this: v25, a2: -1) != 0 )
      idAI2::SetWorldCollision(this: ai, collideWithWorld: false);
  }
  else
  {
    idAI2::SetWorldCollision(this: ai, collideWithWorld: true);
    if ( v22 < 0.25 )
    {
      v39 = this->fallEndHeight + (float)0.25;
      v24 = idEntity::GetPhysics(this: ai);
      v24->SetOrigin(this: v24, a2: (const idVec3 *)v38, a3: -1);
    }
  }
  if ( __fabs(v22) < 8.0 )
  {
    idAnimator_WalkIK::EnableAll(this: &ai->walkIK);
    if ( v37 > 150.0 )
      v26 = 0.0;
    else
      v26 = 1.0;
    fsm->animBlendVars.animFallHeightIndex.value = v26;
    v27 = ai->GetAnimWebCmdCtx(this: ai);
    idAnimWebCmd::idAnimWebCmd(
      this: &v44,
      _owner: v27,
      userName: "w:\\tech5\\tungsten\\game\\ai\\animfsm\\AnimFSM_StateMove.cpp(1056) : fallLand");
    v28 = idAIAnimWebState_Movement::idAIAnimWebState_Movement(
            this: &v42,
            ai,
            postfix: nullptr,
            subweb: AISUBWEB_MAX,
            posture: POSTURE_MAX);
    v29 = &v28->idAnimWebState;
    if ( v28 == nullptr )
      v29 = nullptr;
    v44.flags |= 0x600u;
    v30 = idAnimWebCmd::ChangeState(this: &v44, _dst: v29);
    v30->intrBlend = INTR_BLEND_YES;
    v30->intrPath = INTR_PATH_IMMEDIATE;
    v31 = idAnimWebCmd::Force(this: v30, blendFrames: 3, originBlend: ORIGINBLEND_BRANCH);
    flags = v31->flags;
    v31->groups = 1;
    v31->forceFallbackPathSize = -1;
    v31->groupFilter = -1;
    v31->flags = flags | 0x40;
    idAnimWebCmd::Commit(
      this: v31,
      handle: &fsm->animWaitHandle,
      priority: AWCMD_PRIORITY_HIGH,
      ev: AWCMD_EVENT_DEST_BLEND_START);
    v42.__vftable = (idAIAnimWebState_Movement_vtbl *)&idAIAnimWebState::`vftable';
    idAIStateLite::SetSubState(this, newSubState: 0);
    fsm->CallbackFinishLinkTraversal(this: fsm);
  }
  return 1;
}


// ========================================================================
// __unwind$490374
// EA  : 0x82A806C0
// RVA : 0x00A806C0
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm_statemove.cpp
// ========================================================================

void _unwind_490374()
{
  int v0; // r12

  idAIAnimWebState_Current::~idAIAnimWebState_Current(this: (idAIAnimWebState_Current *)(v0 - 464 + 144));
}


// ========================================================================
// ?GetMoveCyclePostfix@idAnimStateMoveGround@@IAA?AVidStr@@PAVidAI2@@PAVidAnimBaseFSM@@@Z
// EA  : 0x82A806F0
// RVA : 0x00A806F0
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm_statemove.cpp
// ========================================================================

idStr *__fastcall idAnimStateMoveGround::GetMoveCyclePostfix(
        idAnimStateMoveGround *this,
        idStr *result,
        idAI2 *ai,
        idAnimBaseFSM *fsm)
{
  idStr *v7; // r3

  idStr::idStr((idStr *)this, text: &byte_8200D768);
  if ( idAnimBaseFSM::CanRotateBodyIndepentlyOfMove(this: fsm)
    || !fsm->useFullyBodyAiming
    || __fabs(fsm->animBlendVars.bodyMoveAngle.value) >= 5.0 )
  {
    return (idStr *)this;
  }
  if ( (unsigned __int8)idFocusInfo::HasFocus(this: ai->aiVolatile.focus.foci.ptr) != 0 )
  {
    v7 = (idStr *)this;
LABEL_8:
    idStr::operator=(this: v7, text: "_aim");
    return (idStr *)this;
  }
  if ( (unsigned __int8)idFocusInfo::HasFocus(this: &ai->aiVolatile.focus.foci.ptr[1]) != 0 )
  {
    v7 = (idStr *)this;
    if ( !ai->aiVolatile.focus.foci.ptr[1].keepFocusInView )
      return v7;
    goto LABEL_8;
  }
  return (idStr *)this;
}


// ========================================================================
// __unwind$490583
// EA  : 0x82A807BC
// RVA : 0x00A807BC
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm_statemove.cpp
// ========================================================================

void _unwind_490583()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 128;
  if ( (*(_DWORD *)(v0 - 128 + 80) & 1) != 0 )
  {
    *(_DWORD *)(v1 + 80) &= ~1u;
    idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v1 + 148));
  }
}


// ========================================================================
// ?CheckForStepTransition@idAnimStateMoveGround@@IAA?AW4idTransitionCode@@PAVidAI2@@PAVidAnimBaseFSM@@@Z
// EA  : 0x82A80808
// RVA : 0x00A80808
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm_statemove.cpp
// ========================================================================

int __fastcall idAnimStateMoveGround::CheckForStepTransition(
        idAnimStateMoveGround *this,
        idAI2 *ai,
        idAnimBaseFSM *fsm)
{
  unsigned __int64 v6; // r6
  const char *v7; // r7
  int updated; // r3
  idPLogScope v10[2]; // [sp+50h] [-90h] BYREF
  idAnimWebTransitions::transitionQueryResult_t v11; // [sp+60h] [-80h] BYREF

  RD_EventBegin(name: "idAnimStateMoveGround::CheckForStepTransition");
  LODWORD(v6) = "idAnimStateMoveGround::CheckForStepTransition";
  HIDWORD(v6) = 6;
  idPLogScope::idPLogScope(this: v10, pl: &pLog, gMask: v6, label: v7);
  if ( this->subState != 1
    && fsm->puppetModeMask == 0
    && idAnimBaseFSM::CanStepTransition(this: fsm)
    && ai_useStepTransitionAnims.valueInteger != 0 )
  {
    idAnimWebTransitions::transitionQueryResult_t::transitionQueryResult_t(this: &v11);
    updated = idAnimBaseFSM::UpdateTransitionToDestination(this: fsm, transInfo: &v11, transType: 3);
    if ( updated == 2 )
    {
      if ( (unsigned __int8)idAnimBaseFSM::StartArrivalAnimation(
                              this: fsm,
                              transInfo: &v11,
                              destinationOrigin: &v11.destOrigin,
                              force: false,
                              transType: TRANSITION_STEP) != 0 )
      {
        idAnimWebTransitions::CleanupNavTraces(ai, cache: &fsm->arrivalTransitionCache);
        idAIStateLite::SetSubState(this, newSubState: 1);
        idPLogScope::~idPLogScope(this: v10);
        RD_EventEnd();
        return 1;
      }
    }
    else if ( updated == 1 )
    {
      idPLogScope::~idPLogScope(this: v10);
      RD_EventEnd();
      return 3;
    }
  }
  idPLogScope::~idPLogScope(this: v10);
  RD_EventEnd();
  return 0;
}


// ========================================================================
// __unwind$490763
// EA  : 0x82A80948
// RVA : 0x00A80948
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm_statemove.cpp
// ========================================================================

void _unwind_490763()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 224 + 172));
}


// ========================================================================
// __unwind$490764
// EA  : 0x82A80970
// RVA : 0x00A80970
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm_statemove.cpp
// ========================================================================

void _unwind_490764()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 224 + 80));
}


// ========================================================================
// ?CheckForArrival@idAnimStateMoveGround@@IAA?AW4idTransitionCode@@PAVidAI2@@PAVidAnimBaseFSM@@@Z
// EA  : 0x82A809A0
// RVA : 0x00A809A0
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm_statemove.cpp
// ========================================================================

int __fastcall idAnimStateMoveGround::CheckForArrival(idAnimStateMoveGround *this, idAI2 *ai, idAnimBaseFSM *fsm)
{
  unsigned __int64 v6; // r6
  const char *v7; // r7
  int updated; // r3
  idPLogScope v10[2]; // [sp+50h] [-90h] BYREF
  idAnimWebTransitions::transitionQueryResult_t v11; // [sp+60h] [-80h] BYREF

  RD_EventBegin(name: "idAnimStateMoveGround::CheckForArrival");
  LODWORD(v6) = "idAnimStateMoveGround::CheckForArrival";
  HIDWORD(v6) = 6;
  idPLogScope::idPLogScope(this: v10, pl: &pLog, gMask: v6, label: v7);
  if ( this->subState != 5 && fsm->puppetModeMask == 0 && idAnimBaseFSM::CanArrivalTransition(this: fsm) )
  {
    idAnimWebTransitions::transitionQueryResult_t::transitionQueryResult_t(this: &v11);
    updated = idAnimBaseFSM::UpdateTransitionToDestination(this: fsm, transInfo: &v11, transType: 1);
    if ( updated == 2 )
    {
      if ( (unsigned __int8)idAnimBaseFSM::StartArrivalAnimation(
                              this: fsm,
                              transInfo: &v11,
                              destinationOrigin: &v11.destOrigin,
                              force: true,
                              transType: TRANSITION_NORMAL) != 0 )
      {
        idAnimWebTransitions::CleanupNavTraces(ai, cache: &fsm->arrivalTransitionCache);
        idAIStateLite::SetSubState(this, newSubState: 5);
        idPLogScope::~idPLogScope(this: v10);
        RD_EventEnd();
        return 1;
      }
    }
    else if ( updated == 1 )
    {
      idPLogScope::~idPLogScope(this: v10);
      RD_EventEnd();
      return 3;
    }
  }
  idPLogScope::~idPLogScope(this: v10);
  RD_EventEnd();
  return 0;
}


// ========================================================================
// __unwind$490835
// EA  : 0x82A80ACC
// RVA : 0x00A80ACC
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm_statemove.cpp
// ========================================================================

void _unwind_490835()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 224 + 172));
}


// ========================================================================
// __unwind$490836
// EA  : 0x82A80AF4
// RVA : 0x00A80AF4
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm_statemove.cpp
// ========================================================================

void _unwind_490836()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 224 + 80));
}


// ========================================================================
// ?CheckForLinkStart@idAnimStateMoveGround@@IAA?AW4idTransitionCode@@PAVidAI2@@PAVidAnimBaseFSM@@@Z
// EA  : 0x82A80B28
// RVA : 0x00A80B28
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm_statemove.cpp
// ========================================================================

int __fastcall idAnimStateMoveGround::CheckForLinkStart(idAnimStateMoveGround *this, idAI2 *ai, idAnimBaseFSM *fsm)
{
  unsigned __int64 v6; // r6
  const char *v7; // r7
  idEntity *v8; // r3
  idInfoLinkSegment *v9; // r3
  idInfoLinkSegment *v10; // r3
  idAnimWebPath *v11; // r27
  __int64 v12; // r10
  __int64 v13; // r6
  __int64 v14; // r8
  va *v15; // r3
  int *v17; // r10
  idAIAnimWebState_Movement *v18; // r9
  int i; // ctr
  int *v20; // r10
  idAIAnimWebState *v21; // r11
  int j; // ctr
  idAIMoveInfo *cachedMoveInfoIntermediate; // r11
  double v24; // fp12
  double x; // fp11
  int *v26; // r10
  idAIAnimWebState_Idle *v27; // r11
  int k; // ctr
  int v29; // r28
  idAIAnimWebState *v30; // r3
  idAnimWebState *v31; // r11
  int *v32; // r10
  idAtomicString *p_debugState; // r11
  int m; // ctr
  idAnimWebCmdCtx *v35; // r3
  idAnimWebCmd *v36; // r3
  idAnimWebCmd *v37; // r3
  idAnimWebCmd *v38; // r3
  idAnimWebCmd *v39; // r3
  double z; // fp9
  double v41; // fp5
  idPhysics *Physics; // r3
  idPhysics *v43; // r3
  idAI2_vtbl *v44; // r11
  int v45; // r3
  __int64 v46; // r6
  __int64 v47; // r10
  __int64 v48; // r8
  va *v49; // r3
  int *v50; // r10
  idAIAnimWebState *v51; // r9
  int n; // ctr
  idAIMoveInfo *cachedMoveInfoDest; // r11
  double v54; // fp12
  double v55; // fp11
  int *v56; // r10
  idAIAnimWebState *v57; // r11
  int jj; // ctr
  int *v59; // r10
  idAIAnimWebState *v60; // r11
  int ii; // ctr
  idAnimWebCmdCtx *v62; // r3
  idAnimWebCmd *v63; // r3
  idAnimWebCmd *v64; // r3
  idAnimWebCmd *v65; // r3
  idAnimWebCmd *v66; // r3
  double v67; // fp12
  double v68; // fp0
  double v69; // fp13
  double y; // fp12
  double v71; // fp11
  double v72; // fp10
  double v73; // fp9
  double v74; // fp8
  double v75; // fp7
  double v76; // fp6
  idPhysics *v77; // r3
  idPhysics *v78; // r3
  double v79; // fp9
  double v80; // fp8
  double v81; // fp5
  double v82; // fp4
  double v83; // fp3
  idLegsFSM *ActionFSM; // r3
  idAIAction *v85; // r3
  __int16 flags; // r11
  const idDeclMD6 *decl; // r29
  const idMD6Anim *AnimByIndex; // r3
  idMD6AnimData *animData; // r11
  const idMD6Anim *v90; // r27
  int numFrames; // r6
  char v92; // r25
  idVarArgs<4> **list; // r29
  int kk; // r28
  int v95; // [sp+8h] [-15E8h]
  int v96; // [sp+Ch] [-15E4h]
  int v97; // [sp+10h] [-15E0h]
  int v98; // [sp+14h] [-15DCh]
  int v99; // [sp+18h] [-15D8h]
  int v100; // [sp+1Ch] [-15D4h]
  idVec3 *p_destPosition; // [sp+50h] [-15A0h] BYREF
  idPLogScope v102; // [sp+58h] [-1598h] BYREF
  const char *v103; // [sp+60h] [-1590h] BYREF
  idMat3 v104; // [sp+70h] [-1580h] BYREF
  int v105; // [sp+9Ch] [-1554h] BYREF
  idAnimWebState v106; // [sp+A0h] [-1550h] BYREF
  idStr v107; // [sp+C0h] [-1530h] BYREF
  idStr v108; // [sp+E0h] [-1510h] BYREF
  float v109[4]; // [sp+100h] [-14F0h] BYREF
  blendParms_t v110; // [sp+110h] [-14E0h] BYREF
  idStr v111; // [sp+130h] [-14C0h] BYREF
  idStr v112; // [sp+150h] [-14A0h] BYREF
  idAIAnimWebState v113; // [sp+170h] [-1480h] BYREF
  float v114[6]; // [sp+188h] [-1468h] BYREF
  idStr v115; // [sp+1A0h] [-1450h] BYREF
  idStr v116; // [sp+1C0h] [-1430h] BYREF
  idAIAnimWebState v117; // [sp+1E0h] [-1410h] BYREF
  idNpCornerInfo v118; // [sp+200h] [-13F0h] BYREF
  idAIAnimWebState v119; // [sp+240h] [-13B0h] BYREF
  idAIAnimWebState v120; // [sp+260h] [-1390h] BYREF
  idNpCornerInfo v121; // [sp+280h] [-1370h] BYREF
  idAIAnimWebState_Current v122; // [sp+2C0h] [-1330h] BYREF
  idAIAnimWebState_Idle v123; // [sp+2E0h] [-1310h] BYREF
  idAIAnimWebState_Movement v124; // [sp+300h] [-12F0h] BYREF
  idAIAnimWebState v125; // [sp+320h] [-12D0h] BYREF
  idAIAnimWebState_Current v126; // [sp+340h] [-12B0h] BYREF
  idList<idVehicleState *,5> v127; // [sp+360h] [-1290h] BYREF
  int v128; // [sp+370h] [-1280h] BYREF
  aas2Traversal_t v129; // [sp+3B0h] [-1240h] BYREF
  idAIAnimWebState v130; // [sp+3F0h] [-1200h] BYREF
  idAnimWebState v131; // [sp+410h] [-11E0h] BYREF
  idAnimWebCmd v132; // [sp+430h] [-11C0h] BYREF
  idAnimWebCmd v133; // [sp+4E0h] [-1110h] BYREF
  va v134; // [sp+590h] [-1060h] BYREF

  RD_EventBegin(name: "idAnimStateMoveGround::CheckForLinkStart");
  LODWORD(v6) = "idAnimStateMoveGround::CheckForLinkStart";
  HIDWORD(v6) = 6;
  idPLogScope::idPLogScope(this: &v102, pl: &pLog, gMask: v6, label: v7);
  idNpCornerInfo::idNpCornerInfo(this: &v121);
  idNpCornerInfo::idNpCornerInfo(this: &v118);
  if ( np_enable.valueInteger != 0 )
  {
    if ( this->InternalShouldStartLink(this, a2: ai, a3: fsm, a4: &v121, a5: &v118) )
    {
      if ( gameLocal->spawnIds.ptr[v121.linkEntityStart.spawnId.value & 0x1FFF] == v121.linkEntityStart.spawnId.value >> 13
        && (v8 = gameLocal->entities.ptr[v121.linkEntityStart.spawnId.value & 0x1FFF]) != nullptr )
      {
        v9 = (idInfoLinkSegment *)idEntity::CastTo(c: v8);
      }
      else
      {
        v9 = nullptr;
      }
      v10 = idInfoLinkSegment::CastTo(c: v9);
      v11 = (idAnimWebPath *)v10;
      if ( v10 != nullptr && fsm->CallbackCanUseLink(this: fsm, a2: v10) && v11[25].len != 0 )
      {
        v107.len = 0;
        v107.baseBuffer[0] = 0;
        v107.allocedAndFlag = 20;
        v107.data = v107.baseBuffer;
        v108.allocedAndFlag = 20;
        v108.data = v108.baseBuffer;
        v108.len = 0;
        v108.baseBuffer[0] = 0;
        idAnimWebPath::GetWebPathNames(this: v11 + 25, subWebName: &v107, stateName: &v108);
        idAIAnimWebState::idAIAnimWebState(this: &v117, ai, subwebName: v107.data, stateName: v108.data);
        HIDWORD(v12) = "1 - formation cover, such as behind regime shield units";
        HIDWORD(v13) = ai->name.data;
        v15 = va::va(
                this: &v134,
                fmt: "Bad Traversal Anim for %s",
                a3: v13,
                a4: v14,
                a5: v12,
                a6: v95,
                a7: v96,
                a8: v97,
                a9: v98,
                a10: v99,
                a11: v100);
        if ( !idAnimWebState::Verify(this: &v117.idAnimWebState, errorMsg: v15->buffer) )
        {
          idAnimBaseFSM::SetDestination(this: fsm, cmd: &idAIMoveCmd::s_null);
          v117.__vftable = (idAIAnimWebState_vtbl *)&idAIAnimWebState::`vftable';
          idStr::FreeData(this: &v108);
          idStr::FreeData(this: &v107);
          idNpLink::~idNpLink(this: &v118.link);
          idNpLink::~idNpLink(this: &v121.link);
          idPLogScope::~idPLogScope(this: &v102);
          RD_EventEnd();
          return 1;
        }
        fsm->SetOnLink(this: fsm, a2: true);
        this->fallEndHeight = v118.position.z;
        idAIAnimWebState_Current::idAIAnimWebState_Current(this: &v126, ai);
        idAIAnimWebState_Idle::idAIAnimWebState_Idle(
          this: &v123,
          ai,
          subweb: AISUBWEB_MAX,
          posture: POSTURE_MAX,
          useWeaponSlot: EQUIP_MAX);
        idAIAnimWebState_Movement::idAIAnimWebState_Movement(
          this: &v124,
          ai,
          postfix: nullptr,
          subweb: AISUBWEB_MAX,
          posture: POSTURE_MAX);
        idAnimWebPath::GetWebPathNames(this: v11 + 26, subWebName: &v107, stateName: &v108);
        idAIAnimWebState::idAIAnimWebState(this: &v119, ai, subwebName: v107.data, stateName: v108.data);
        v17 = &v105;
        v18 = &v124;
        for ( i = 5; i != 0; --i )
        {
          v18 = (idAIAnimWebState_Movement *)((char *)v18 + 4);
          *++v17 = (int)v18->__vftable;
        }
        if ( idAnimWebState::Verify(this: &v119.idAnimWebState, errorMsg: nullptr) )
        {
          v20 = &v105;
          v21 = &v119;
          for ( j = 5; j != 0; --j )
          {
            v21 = (idAIAnimWebState *)((char *)v21 + 4);
            *++v20 = (int)v21->__vftable;
          }
        }
        else if ( fsm->currentMove.arrivalAction >= AIARRIVAL_STOP )
        {
          cachedMoveInfoIntermediate = fsm->cachedMoveInfoIntermediate;
          if ( cachedMoveInfoIntermediate != nullptr
            || (cachedMoveInfoIntermediate = fsm->cachedMoveInfoDest) != nullptr )
          {
            v24 = (float)(cachedMoveInfoIntermediate->destPosition.y - v118.position.y);
            x = cachedMoveInfoIntermediate->destPosition.x;
            p_destPosition = &cachedMoveInfoIntermediate->destPosition;
            if ( (float)((float)((float)(cachedMoveInfoIntermediate->destPosition.z - v118.position.z)
                               * (float)(cachedMoveInfoIntermediate->destPosition.z - v118.position.z))
                       + (float)((float)((float)((float)x - v118.position.x) * (float)((float)x - v118.position.x))
                               + (float)((float)v24 * (float)v24))) <= (double)(float)(fsm->currentMove.arrivalRadius
                                                                                     * fsm->currentMove.arrivalRadius) )
            {
              v26 = &v105;
              v27 = &v123;
              for ( k = 5; k != 0; --k )
              {
                v27 = (idAIAnimWebState_Idle *)((char *)v27 + 4);
                *++v26 = (int)v27->__vftable;
              }
            }
          }
        }
        v29 = 7;
        idAnimWebState::idAnimWebState(this: &v131);
        if ( v11[27].len != 0 )
        {
          idAnimWebPath::GetWebPathNames(this: v11 + 27, subWebName: &v107, stateName: &v108);
          v30 = idAIAnimWebState::idAIAnimWebState(this: &v130, ai, subwebName: v107.data, stateName: v108.data);
          v31 = &v30->idAnimWebState;
          if ( v30 == nullptr )
            v31 = nullptr;
          v32 = &v105;
          p_debugState = &v31[-1].debugState;
          for ( m = 5; m != 0; --m )
          {
            ++p_debugState;
            *++v32 = (int)p_debugState->str;
          }
          v29 = 8;
          v130.__vftable = (idAIAnimWebState_vtbl *)&idAIAnimWebState::`vftable';
        }
        blendParms_t::blendParms_t(this: &v110);
        blendParms_t::SetDuration(this: &v110, frame: 3);
        idAnimWebState::GetBlendParmsToDestination(this: &v126.idAnimWebState, dest: &v117.idAnimWebState, parms: &v110);
        v35 = ai->GetAnimWebCmdCtx(this: ai);
        idAnimWebCmd::idAnimWebCmd(
          this: &v133,
          _owner: v35,
          userName: "w:\\tech5\\tungsten\\game\\ai\\animfsm\\AnimFSM_StateMove.cpp(573) : startAnimLink");
        v133.intrPath = INTR_PATH_IMMEDIATE;
        v133.groups = 0x20000;
        v133.intrBlend = INTR_BLEND_MULTI;
        v133.groupFilter = 1;
        v133.flags |= 0x600u;
        v36 = idAnimWebCmd::Force(this: &v133, bp: &v110);
        v37 = idAnimWebCmd::ChangeState(this: v36, _dst: &v106);
        v38 = idAnimWebCmd::Via(this: v37, _via: &v117.idAnimWebState, optional: false);
        v39 = idAnimWebCmd::ViaSubweb(this: v38, subweb: "transitions");
        if ( idAnimWebCmd::Commit(
               this: v39,
               handle: &fsm->animWaitHandle,
               priority: AWCMD_PRIORITY_HIGH,
               ev: AWCMD_EVENT_VIA_BLEND_OUT_START) == AWCMD_STATUS_OK )
        {
          idAIStateLite::SetSubState(this, newSubState: v29);
          fsm->animDeltaMode = ANIMDELTAMODE_DRIVEN;
          fsm->animDeltaCorrection.currentAnimnodeOrigin.x = fsm->nextLinkPos.x;
          fsm->animDeltaCorrection.currentAnimnodeOrigin.y = fsm->nextLinkPos.y;
          fsm->animDeltaCorrection.currentAnimnodeOrigin.z = fsm->nextLinkPos.z;
          p_destPosition = &fsm->nextLinkAxis.mat[1];
          fsm->animDeltaCorrection.currentAnimnodeAxis.mat[0].x = fsm->nextLinkAxis.mat[0].x;
          p_destPosition = &fsm->animDeltaCorrection.currentAnimnodeAxis.mat[1];
          fsm->animDeltaCorrection.currentAnimnodeAxis.mat[0].y = fsm->nextLinkAxis.mat[0].y;
          p_destPosition = &fsm->nextLinkAxis.mat[1];
          z = fsm->nextLinkAxis.mat[0].z;
          p_destPosition = &fsm->desiredMoveAxis.mat[1];
          fsm->animDeltaCorrection.currentAnimnodeAxis.mat[0].z = z;
          fsm->animDeltaCorrection.currentAnimnodeAxis.mat[1].x = fsm->nextLinkAxis.mat[1].x;
          p_destPosition = &fsm->animDeltaCorrection.currentAnimnodeAxis.mat[2];
          fsm->animDeltaCorrection.currentAnimnodeAxis.mat[1].y = fsm->nextLinkAxis.mat[1].y;
          p_destPosition = &fsm->nextLinkAxis.mat[2];
          fsm->animDeltaCorrection.currentAnimnodeAxis.mat[1].z = fsm->nextLinkAxis.mat[1].z;
          v41 = fsm->nextLinkAxis.mat[2].x;
          p_destPosition = &fsm->desiredMoveAxis.mat[2];
          fsm->animDeltaCorrection.currentAnimnodeAxis.mat[2].x = v41;
          fsm->animDeltaCorrection.currentAnimnodeAxis.mat[2].y = fsm->nextLinkAxis.mat[2].y;
          fsm->animDeltaCorrection.currentAnimnodeAxis.mat[2].z = fsm->nextLinkAxis.mat[2].z;
          fsm->desiredMoveAxis.mat[0].x = fsm->nextLinkAxis.mat[0].x;
          fsm->desiredMoveAxis.mat[0].y = fsm->nextLinkAxis.mat[0].y;
          fsm->desiredMoveAxis.mat[0].z = fsm->nextLinkAxis.mat[0].z;
          fsm->desiredMoveAxis.mat[1].x = fsm->nextLinkAxis.mat[1].x;
          fsm->desiredMoveAxis.mat[1].y = fsm->nextLinkAxis.mat[1].y;
          fsm->desiredMoveAxis.mat[1].z = fsm->nextLinkAxis.mat[1].z;
          fsm->desiredMoveAxis.mat[2].x = fsm->nextLinkAxis.mat[2].x;
          fsm->desiredMoveAxis.mat[2].y = fsm->nextLinkAxis.mat[2].y;
          fsm->desiredMoveAxis.mat[2].z = fsm->nextLinkAxis.mat[2].z;
          Physics = idEntity::GetPhysics(this: ai);
          Physics->SetLinearVelocity(this: Physics, a2: &vec3_origin, a3: 0);
          v43 = idEntity::GetPhysics(this: ai);
          v43->SetOrigin(this: v43, a2: &fsm->nextLinkPos, a3: -1);
          idAIOrientation::SetAxis(this: &fsm->orientMove, axis: &fsm->nextLinkAxis);
          idAIOrientation::SetIdealDir(this: &fsm->orientMove, ai, dir: fsm->nextLinkAxis.mat);
          idAIOrientation::SetAxis(this: &fsm->orientBody, axis: &fsm->nextLinkAxis);
          idAIOrientation::SetIdealDir(this: &fsm->orientBody, ai, dir: fsm->nextLinkAxis.mat);
          ai->actorVolatile.modelInfo.modelAxis.mat[0].x = fsm->nextLinkAxis.mat[0].x;
          p_destPosition = &ai->actorVolatile.modelInfo.modelAxis.mat[2];
          ai->actorVolatile.modelInfo.modelAxis.mat[0].y = fsm->nextLinkAxis.mat[0].y;
          ai->actorVolatile.modelInfo.modelAxis.mat[0].z = fsm->nextLinkAxis.mat[0].z;
          ai->actorVolatile.modelInfo.modelAxis.mat[1].x = fsm->nextLinkAxis.mat[1].x;
          ai->actorVolatile.modelInfo.modelAxis.mat[1].y = fsm->nextLinkAxis.mat[1].y;
          ai->actorVolatile.modelInfo.modelAxis.mat[1].z = fsm->nextLinkAxis.mat[1].z;
          ai->actorVolatile.modelInfo.modelAxis.mat[2].x = fsm->nextLinkAxis.mat[2].x;
          ai->actorVolatile.modelInfo.modelAxis.mat[2].y = fsm->nextLinkAxis.mat[2].y;
          ai->actorVolatile.modelInfo.modelAxis.mat[2].z = fsm->nextLinkAxis.mat[2].z;
          ai->UpdateModelTransform(this: ai);
          v119.__vftable = (idAIAnimWebState_vtbl *)&idAIAnimWebState::`vftable';
          v124.__vftable = (idAIAnimWebState_Movement_vtbl *)&idAIAnimWebState::`vftable';
          v123.__vftable = (idAIAnimWebState_Idle_vtbl *)&idAIAnimWebState::`vftable';
          v126.__vftable = (idAIAnimWebState_Current_vtbl *)&idAIAnimWebState::`vftable';
          v117.__vftable = (idAIAnimWebState_vtbl *)&idAIAnimWebState::`vftable';
          idStr::FreeData(this: &v108);
          idStr::FreeData(this: &v107);
          idNpLink::~idNpLink(this: &v118.link);
          idNpLink::~idNpLink(this: &v121.link);
          idPLogScope::~idPLogScope(this: &v102);
          RD_EventEnd();
          return 1;
        }
        idAnimBaseFSM::SetDestination(this: fsm, cmd: &idAIMoveCmd::s_null);
        v119.__vftable = (idAIAnimWebState_vtbl *)&idAIAnimWebState::`vftable';
        v124.__vftable = (idAIAnimWebState_Movement_vtbl *)&idAIAnimWebState::`vftable';
        v123.__vftable = (idAIAnimWebState_Idle_vtbl *)&idAIAnimWebState::`vftable';
        v126.__vftable = (idAIAnimWebState_Current_vtbl *)&idAIAnimWebState::`vftable';
        v117.__vftable = (idAIAnimWebState_vtbl *)&idAIAnimWebState::`vftable';
        idStr::FreeData(this: &v108);
        idStr::FreeData(this: &v107);
        idNpLink::~idNpLink(this: &v118.link);
        idNpLink::~idNpLink(this: &v121.link);
        idPLogScope::~idPLogScope(this: &v102);
        goto LABEL_66;
      }
    }
    goto LABEL_65;
  }
  aas2Traversal_t::aas2Traversal_t(this: &v129);
  if ( !fsm->ShouldStartAASTraversal(this: fsm, a2: (idVec3 *)v109, a3: (idVec3 *)v114, a4: &v104, a5: &v129) )
  {
LABEL_65:
    idNpLink::~idNpLink(this: &v118.link);
    idNpLink::~idNpLink(this: &v121.link);
    idPLogScope::~idPLogScope(this: &v102);
    goto LABEL_66;
  }
  v44 = ai->__vftable;
  v103 = nullptr;
  v45 = (int)v44->GetAAS(this: ai);
  (*(void (__fastcall **)(int, _DWORD, const char **))(*(_DWORD *)v45 + 188))(
    a1: v45,
    a2: (unsigned __int16)v129.animIndex.value,
    a3: &v103);
  v116.len = 0;
  v116.baseBuffer[0] = 0;
  v116.allocedAndFlag = 20;
  v116.data = v116.baseBuffer;
  v115.allocedAndFlag = 20;
  v115.data = v115.baseBuffer;
  v115.len = 0;
  v115.baseBuffer[0] = 0;
  idAI2::GetSubWebAndStateFromAnimWebPath(this: ai, animWebPath: v103, subWebName: &v116, stateName: &v115);
  idAIAnimWebState::idAIAnimWebState(this: &v113, ai, subwebName: v116.data, stateName: v115.data);
  HIDWORD(v46) = ai->name.data;
  v49 = va::va(
          this: &v134,
          fmt: "Bad Traversal Anim for %s",
          a3: v46,
          a4: v48,
          a5: v47,
          a6: v95,
          a7: v96,
          a8: v97,
          a9: v98,
          a10: v99,
          a11: v100);
  if ( !idAnimWebState::Verify(this: &v113.idAnimWebState, errorMsg: v49->buffer) )
  {
    idAnimBaseFSM::SetDestination(this: fsm, cmd: &idAIMoveCmd::s_null);
    v113.__vftable = (idAIAnimWebState_vtbl *)&idAIAnimWebState::`vftable';
    idStr::FreeData(this: &v115);
    idStr::FreeData(this: &v116);
    idNpLink::~idNpLink(this: &v118.link);
    idNpLink::~idNpLink(this: &v121.link);
    idPLogScope::~idPLogScope(this: &v102);
    RD_EventEnd();
    return 1;
  }
  fsm->SetOnLink(this: fsm, a2: true);
  this->fallEndHeight = v118.position.z;
  v111.allocedAndFlag = 20;
  v111.len = 0;
  v111.data = v111.baseBuffer;
  v111.baseBuffer[0] = 0;
  v112.allocedAndFlag = 20;
  v112.data = v112.baseBuffer;
  v112.len = 0;
  v112.baseBuffer[0] = 0;
  idAI2::GetSubWebAndStateFromAnimWebPath(this: ai, animWebPath: "$subweb:run", subWebName: &v111, stateName: &v112);
  idAIAnimWebState::idAIAnimWebState(this: &v125, ai, subwebName: v111.data, stateName: v112.data);
  idAI2::GetSubWebAndStateFromAnimWebPath(this: ai, animWebPath: "$subweb:idle", subWebName: &v111, stateName: &v112);
  idAIAnimWebState::idAIAnimWebState(this: &v120, ai, subwebName: v111.data, stateName: v112.data);
  idAIAnimWebState_Current::idAIAnimWebState_Current(this: &v122, ai);
  v50 = &v105;
  v51 = &v125;
  for ( n = 5; n != 0; --n )
  {
    v51 = (idAIAnimWebState *)((char *)v51 + 4);
    *++v50 = (int)v51->__vftable;
  }
  if ( fsm->currentMove.arrivalAction < AIARRIVAL_STOP )
  {
    if ( (v129.flags & 8) == 0 )
    {
      v59 = &v105;
      v60 = &v120;
      for ( ii = 5; ii != 0; --ii )
      {
        v60 = (idAIAnimWebState *)((char *)v60 + 4);
        *++v59 = (int)v60->__vftable;
      }
    }
  }
  else
  {
    cachedMoveInfoDest = fsm->cachedMoveInfoIntermediate;
    if ( cachedMoveInfoDest != nullptr || (cachedMoveInfoDest = fsm->cachedMoveInfoDest) != nullptr )
    {
      v54 = (float)(cachedMoveInfoDest->destPosition.y - v114[1]);
      v55 = cachedMoveInfoDest->destPosition.x;
      p_destPosition = &cachedMoveInfoDest->destPosition;
      if ( (float)((float)((float)(cachedMoveInfoDest->destPosition.z - v114[2])
                         * (float)(cachedMoveInfoDest->destPosition.z - v114[2]))
                 + (float)((float)((float)((float)v55 - v114[0]) * (float)((float)v55 - v114[0]))
                         + (float)((float)v54 * (float)v54))) <= (double)(float)(fsm->currentMove.arrivalRadius
                                                                               * fsm->currentMove.arrivalRadius) )
      {
        v56 = &v105;
        v57 = &v120;
        for ( jj = 5; jj != 0; --jj )
        {
          v57 = (idAIAnimWebState *)((char *)v57 + 4);
          *++v56 = (int)v57->__vftable;
        }
      }
    }
  }
  blendParms_t::blendParms_t(this: &v110);
  blendParms_t::SetDuration(this: &v110, frame: 3);
  idAnimWebState::GetBlendParmsToDestination(this: &v122.idAnimWebState, dest: &v113.idAnimWebState, parms: &v110);
  v62 = ai->GetAnimWebCmdCtx(this: ai);
  idAnimWebCmd::idAnimWebCmd(
    this: &v132,
    _owner: v62,
    userName: "w:\\tech5\\tungsten\\game\\ai\\animfsm\\AnimFSM_StateMove.cpp(704) : startAnimLink");
  v132.intrPath = INTR_PATH_IMMEDIATE;
  v132.groups = 0x20000;
  v132.intrBlend = INTR_BLEND_MULTI;
  v132.groupFilter = 1;
  v132.flags |= 0x600u;
  v63 = idAnimWebCmd::Force(this: &v132, bp: &v110);
  v64 = idAnimWebCmd::ChangeState(this: v63, _dst: &v106);
  v65 = idAnimWebCmd::Via(this: v64, _via: &v113.idAnimWebState, optional: false);
  v66 = idAnimWebCmd::ViaSubweb(this: v65, subweb: "transitions");
  if ( idAnimWebCmd::Commit(
         this: v66,
         handle: &fsm->animWaitHandle,
         priority: AWCMD_PRIORITY_HIGH,
         ev: AWCMD_EVENT_VIA_BLEND_OUT_START) != AWCMD_STATUS_OK )
  {
    idAnimBaseFSM::SetDestination(this: fsm, cmd: &idAIMoveCmd::s_null);
    v122.__vftable = (idAIAnimWebState_Current_vtbl *)&idAIAnimWebState::`vftable';
    v120.__vftable = (idAIAnimWebState_vtbl *)&idAIAnimWebState::`vftable';
    v125.__vftable = (idAIAnimWebState_vtbl *)&idAIAnimWebState::`vftable';
    idStr::FreeData(this: &v112);
    idStr::FreeData(this: &v111);
    v113.__vftable = (idAIAnimWebState_vtbl *)&idAIAnimWebState::`vftable';
    idStr::FreeData(this: &v115);
    idStr::FreeData(this: &v116);
    idNpLink::~idNpLink(this: &v118.link);
    idNpLink::~idNpLink(this: &v121.link);
    idPLogScope::~idPLogScope(this: &v102);
LABEL_66:
    RD_EventEnd();
    return 0;
  }
  fsm->animDeltaMode = ANIMDELTAMODE_DRIVEN;
  fsm->animDeltaCorrection.currentAnimnodeOrigin.x = v109[0];
  v67 = v109[2];
  fsm->animDeltaCorrection.currentAnimnodeOrigin.y = v109[1];
  fsm->animDeltaCorrection.currentAnimnodeOrigin.z = v67;
  v68 = v104.mat[0].x;
  fsm->animDeltaCorrection.currentAnimnodeAxis.mat[0].x = v104.mat[0].x;
  v69 = v104.mat[1].x;
  y = v104.mat[0].y;
  v71 = v104.mat[0].z;
  fsm->animDeltaCorrection.currentAnimnodeAxis.mat[1].x = v104.mat[1].x;
  p_destPosition = &fsm->desiredMoveAxis.mat[2];
  fsm->animDeltaCorrection.currentAnimnodeAxis.mat[0].y = y;
  fsm->animDeltaCorrection.currentAnimnodeAxis.mat[0].z = v71;
  v72 = v104.mat[1].y;
  fsm->animDeltaCorrection.currentAnimnodeAxis.mat[1].y = v104.mat[1].y;
  v73 = v104.mat[1].z;
  fsm->animDeltaCorrection.currentAnimnodeAxis.mat[1].z = v104.mat[1].z;
  v74 = v104.mat[2].x;
  fsm->animDeltaCorrection.currentAnimnodeAxis.mat[2].x = v104.mat[2].x;
  v75 = v104.mat[2].y;
  fsm->animDeltaCorrection.currentAnimnodeAxis.mat[2].y = v104.mat[2].y;
  v76 = v104.mat[2].z;
  fsm->animDeltaCorrection.currentAnimnodeAxis.mat[2].z = v104.mat[2].z;
  fsm->desiredMoveAxis.mat[0].x = v68;
  fsm->desiredMoveAxis.mat[1].x = v69;
  fsm->desiredMoveAxis.mat[0].y = y;
  fsm->desiredMoveAxis.mat[0].z = v71;
  fsm->desiredMoveAxis.mat[1].y = v72;
  fsm->desiredMoveAxis.mat[1].z = v73;
  fsm->desiredMoveAxis.mat[2].x = v74;
  fsm->desiredMoveAxis.mat[2].y = v75;
  fsm->desiredMoveAxis.mat[2].z = v76;
  v77 = idEntity::GetPhysics(this: ai);
  v77->SetLinearVelocity(this: v77, a2: &vec3_origin, a3: 0);
  v78 = idEntity::GetPhysics(this: ai);
  v78->SetOrigin(this: v78, a2: (const idVec3 *)v109, a3: -1);
  idAIOrientation::SetAxis(this: &fsm->orientMove, axis: &v104);
  idAIOrientation::SetIdealDir(this: &fsm->orientMove, ai, dir: v104.mat);
  idAIOrientation::SetAxis(this: &fsm->orientBody, axis: &v104);
  idAIOrientation::SetIdealDir(this: &fsm->orientBody, ai, dir: v104.mat);
  ai->actorVolatile.modelInfo.modelAxis.mat[0].x = v104.mat[0].x;
  v79 = v104.mat[0].y;
  v80 = v104.mat[0].z;
  ai->actorVolatile.modelInfo.modelAxis.mat[1].x = v104.mat[1].x;
  p_destPosition = &ai->actorVolatile.modelInfo.modelAxis.mat[2];
  ai->actorVolatile.modelInfo.modelAxis.mat[0].y = v79;
  ai->actorVolatile.modelInfo.modelAxis.mat[0].z = v80;
  ai->actorVolatile.modelInfo.modelAxis.mat[1].y = v104.mat[1].y;
  v81 = v104.mat[2].x;
  ai->actorVolatile.modelInfo.modelAxis.mat[1].z = v104.mat[1].z;
  v82 = v104.mat[2].y;
  ai->actorVolatile.modelInfo.modelAxis.mat[2].x = v81;
  v83 = v104.mat[2].z;
  ai->actorVolatile.modelInfo.modelAxis.mat[2].y = v82;
  ai->actorVolatile.modelInfo.modelAxis.mat[2].z = v83;
  ai->UpdateModelTransform(this: ai);
  ActionFSM = idAI2::GetActionFSM(this: ai);
  v85 = idAIAction::CastTo(c: (idAIAction *)ActionFSM->curState);
  if ( v85 != nullptr )
    v85->tempUninterruptible = true;
  flags = v129.flags;
  fsm->pendingAnims.traversalDeltaCorrectionAnim = nullptr;
  if ( (flags & 0x800) != 0 )
  {
    v127.num = 0;
    v127.granularity = 1;
    v127.size = 16;
    v127.list = (idVehicleState **)&v128;
    v127.memTag = 5;
    v127.listStatic = 1;
    decl = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: ai)->decl;
    AnimByIndex = idAnimWebState::GetAnimByIndex(this: &v113.idAnimWebState, md6: decl, animIndex: 0, modelIndex: 0);
    animData = AnimByIndex->animData;
    v90 = AnimByIndex;
    numFrames = 0;
    if ( animData != nullptr )
      numFrames = animData->numFrames;
    idDeclMD6::FindAnimEvents(
      this: decl,
      anim: AnimByIndex,
      startFrame: 0,
      endFrame: numFrames,
      eventNum: AE_AnimDeltaCorrection.eventnum,
      events: &v127);
    v92 = 0;
    if ( v127.num > 0 )
    {
      list = (idVarArgs<4> **)v127.list;
      for ( kk = v127.num; kk != 0; --kk )
      {
        p_destPosition = nullptr;
        idVarArgs<4>::GetArg(this: *list, index: 0, val: (int *)&p_destPosition);
        if ( p_destPosition == (idVec3 *)9 )
          v92 = 1;
        ++list;
      }
    }
    if ( v92 == 0 )
      fsm->pendingAnims.traversalDeltaCorrectionAnim = v90;
    idList<idThread *,58>::Clear(this: &v127);
  }
  idAIStateLite::SetSubState(this, newSubState: 7);
  v122.__vftable = (idAIAnimWebState_Current_vtbl *)&idAIAnimWebState::`vftable';
  v120.__vftable = (idAIAnimWebState_vtbl *)&idAIAnimWebState::`vftable';
  v125.__vftable = (idAIAnimWebState_vtbl *)&idAIAnimWebState::`vftable';
  idStr::FreeData(this: &v112);
  idStr::FreeData(this: &v111);
  v113.__vftable = (idAIAnimWebState_vtbl *)&idAIAnimWebState::`vftable';
  idStr::FreeData(this: &v115);
  idStr::FreeData(this: &v116);
  idNpLink::~idNpLink(this: &v118.link);
  idNpLink::~idNpLink(this: &v121.link);
  idPLogScope::~idPLogScope(this: &v102);
  RD_EventEnd();
  return 1;
}


// ========================================================================
// __unwind$490935
// EA  : 0x82A81974
// RVA : 0x00A81974
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm_statemove.cpp
// ========================================================================

void _unwind_490935()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 5616 + 5520));
}


// ========================================================================
// __unwind$490936
// EA  : 0x82A8199C
// RVA : 0x00A8199C
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm_statemove.cpp
// ========================================================================

void _unwind_490936()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 5616 + 88));
}


// ========================================================================
// __unwind$490937
// EA  : 0x82A819C4
// RVA : 0x00A819C4
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm_statemove.cpp
// ========================================================================

void _unwind_490937()
{
  int v0; // r12

  idNpCornerInfo::~idNpCornerInfo(this: (idNpCornerInfo *)(v0 - 5616 + 640));
}


// ========================================================================
// __unwind$490938
// EA  : 0x82A819EC
// RVA : 0x00A819EC
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm_statemove.cpp
// ========================================================================

void _unwind_490938()
{
  int v0; // r12

  idNpCornerInfo::~idNpCornerInfo(this: (idNpCornerInfo *)(v0 - 5616 + 512));
}


// ========================================================================
// __unwind$490939
// EA  : 0x82A81A14
// RVA : 0x00A81A14
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm_statemove.cpp
// ========================================================================

void _unwind_490939()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 5616 + 192));
}


// ========================================================================
// __unwind$490940
// EA  : 0x82A81A3C
// RVA : 0x00A81A3C
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm_statemove.cpp
// ========================================================================

void _unwind_490940()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 5616 + 224));
}


// ========================================================================
// __unwind$490941
// EA  : 0x82A81A64
// RVA : 0x00A81A64
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm_statemove.cpp
// ========================================================================

void _unwind_490941()
{
  int v0; // r12

  idAIAnimWebState_Current::~idAIAnimWebState_Current(this: (idAIAnimWebState_Current *)(v0 - 5616 + 480));
}


// ========================================================================
// __unwind$490942
// EA  : 0x82A81A8C
// RVA : 0x00A81A8C
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm_statemove.cpp
// ========================================================================

void _unwind_490942()
{
  int v0; // r12

  idAIAnimWebState_Current::~idAIAnimWebState_Current(this: (idAIAnimWebState_Current *)(v0 - 5616 + 832));
}


// ========================================================================
// __unwind$490943
// EA  : 0x82A81AB4
// RVA : 0x00A81AB4
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm_statemove.cpp
// ========================================================================

void _unwind_490943()
{
  int v0; // r12

  idAIAnimWebState_Current::~idAIAnimWebState_Current(this: (idAIAnimWebState_Current *)(v0 - 5616 + 736));
}


// ========================================================================
// __unwind$490944
// EA  : 0x82A81ADC
// RVA : 0x00A81ADC
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm_statemove.cpp
// ========================================================================

void _unwind_490944()
{
  int v0; // r12

  idAIAnimWebState_Current::~idAIAnimWebState_Current(this: (idAIAnimWebState_Current *)(v0 - 5616 + 768));
}


// ========================================================================
// __unwind$490945
// EA  : 0x82A81B04
// RVA : 0x00A81B04
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm_statemove.cpp
// ========================================================================

void _unwind_490945()
{
  int v0; // r12

  idAIAnimWebState_Current::~idAIAnimWebState_Current(this: (idAIAnimWebState_Current *)(v0 - 5616 + 576));
}


// ========================================================================
// __unwind$490947
// EA  : 0x82A81B2C
// RVA : 0x00A81B2C
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm_statemove.cpp
// ========================================================================

void _unwind_490947()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 5616 + 448));
}


// ========================================================================
// __unwind$490948
// EA  : 0x82A81B54
// RVA : 0x00A81B54
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm_statemove.cpp
// ========================================================================

void _unwind_490948()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 5616 + 416));
}


// ========================================================================
// __unwind$490949
// EA  : 0x82A81B7C
// RVA : 0x00A81B7C
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm_statemove.cpp
// ========================================================================

void _unwind_490949()
{
  int v0; // r12

  idAIAnimWebState_Current::~idAIAnimWebState_Current(this: (idAIAnimWebState_Current *)(v0 - 5616 + 368));
}


// ========================================================================
// __unwind$490950
// EA  : 0x82A81BA4
// RVA : 0x00A81BA4
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm_statemove.cpp
// ========================================================================

void _unwind_490950()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 5616 + 304));
}


// ========================================================================
// __unwind$490951
// EA  : 0x82A81BCC
// RVA : 0x00A81BCC
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm_statemove.cpp
// ========================================================================

void _unwind_490951()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 5616 + 336));
}


// ========================================================================
// __unwind$490952
// EA  : 0x82A81BF4
// RVA : 0x00A81BF4
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm_statemove.cpp
// ========================================================================

void _unwind_490952()
{
  int v0; // r12

  idAIAnimWebState_Current::~idAIAnimWebState_Current(this: (idAIAnimWebState_Current *)(v0 - 5616 + 800));
}


// ========================================================================
// __unwind$490953
// EA  : 0x82A81C1C
// RVA : 0x00A81C1C
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm_statemove.cpp
// ========================================================================

void _unwind_490953()
{
  int v0; // r12

  idAIAnimWebState_Current::~idAIAnimWebState_Current(this: (idAIAnimWebState_Current *)(v0 - 5616 + 608));
}


// ========================================================================
// __unwind$490954
// EA  : 0x82A81C44
// RVA : 0x00A81C44
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm_statemove.cpp
// ========================================================================

void _unwind_490954()
{
  int v0; // r12

  idAIAnimWebState_Current::~idAIAnimWebState_Current(this: (idAIAnimWebState_Current *)(v0 - 5616 + 704));
}


// ========================================================================
// __unwind$490955
// EA  : 0x82A81C6C
// RVA : 0x00A81C6C
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm_statemove.cpp
// ========================================================================

void _unwind_490955()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 5616 + 864));
}


// ========================================================================
// ?CheckForTurnTransition@idAnimStateMoveGround@@IAA?AW4idTransitionCode@@PAVidAI2@@PAVidAnimBaseFSM@@@Z
// EA  : 0x82A81CA0
// RVA : 0x00A81CA0
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm_statemove.cpp
// ========================================================================

int __fastcall idAnimStateMoveGround::CheckForTurnTransition(
        idAnimStateMoveGround *this,
        idAI2 *ai,
        idAnimBaseFSM *fsm)
{
  unsigned __int64 v6; // r6
  const char *v7; // r7
  idPhysics *Physics; // r3
  float *v9; // r3
  float *v10; // r26
  double v11; // fp12
  double x; // fp11
  double v13; // fp10
  double v14; // fp6
  idAnimBaseFSM_vtbl *v15; // r10
  int v16; // r25
  char v17; // r9
  BOOL v18; // r21
  idRenderWorld *v19; // r3
  idRenderWorld *v20; // r3
  double v21; // fp0
  double v22; // fp12
  double v23; // fp11
  double v24; // fp8
  double v26; // fp31
  double v27; // fp30
  double v28; // fp29
  double y; // fp13
  double z; // fp12
  idNpCornerInfo *v31; // r11
  double v32; // fp31
  double v33; // fp30
  double v34; // fp10
  double v35; // fp29
  double v36; // fp9
  const idAINavPowerMoverParms *(__fastcall *GetNavParms)(idAI2 *); // ctr
  int v38; // r3
  const idAINavPowerMoverParms *(__fastcall *v39)(idAI2 *); // r9
  int v40; // r3
  idAI2_vtbl *v41; // r6
  double v42; // fp0
  double v43; // fp13
  double v44; // fp4
  idRenderWorld *v45; // r3
  char v46; // r11
  bool v47; // r11
  bool v48; // zf
  double v49; // fp0
  double v50; // fp12
  double v51; // fp10
  double v52; // fp8
  double v53; // fp7
  double v54; // fp6
  double v55; // fp5
  double v56; // fp4
  double v57; // fp3
  double v58; // fp2
  idRenderWorld *v59; // r3
  idVec3 v61; // [sp+50h] [-450h] BYREF
  idVec3 *p_nextArrivalPos; // [sp+5Ch] [-444h]
  float v63[4]; // [sp+60h] [-440h] BYREF
  idVec3 v64; // [sp+70h] [-430h] BYREF
  float v65[4]; // [sp+80h] [-420h] BYREF
  idVec3 v66; // [sp+90h] [-410h] BYREF
  idVec3 v67; // [sp+A0h] [-400h] BYREF
  float maximumPathDistance; // [sp+B0h] [-3F0h] BYREF
  __int16 v69; // [sp+B4h] [-3ECh]
  int v70; // [sp+B8h] [-3E8h]
  char v71; // [sp+BCh] [-3E4h]
  idNpMover::idProbeInput v72; // [sp+C0h] [-3E0h] BYREF
  idPLogScope v73; // [sp+D0h] [-3D0h] BYREF
  idVec3 v74; // [sp+D8h] [-3C8h] BYREF
  float v75[4]; // [sp+E8h] [-3B8h] BYREF
  float v76[6]; // [sp+F8h] [-3A8h] BYREF
  float v77[4]; // [sp+110h] [-390h] BYREF
  float v78[4]; // [sp+120h] [-380h] BYREF
  float v79[4]; // [sp+130h] [-370h] BYREF
  float v80[4]; // [sp+140h] [-360h] BYREF
  idAnimWebTransitions::transitionQueryValidation_t v81; // [sp+150h] [-350h] BYREF
  idNpMover::idProbeResults v82; // [sp+190h] [-310h] BYREF
  idAnimWebTransitions::transitionQueryResult_t v83; // [sp+1C0h] [-2E0h] BYREF
  idAnimWebTransitions::transitionQueryParms_t v84; // [sp+210h] [-290h] BYREF

  RD_EventBegin(name: "idAnimStateMoveGround::CheckForTurnTransition");
  LODWORD(v6) = "idAnimStateMoveGround::CheckForTurnTransition";
  HIDWORD(v6) = 6;
  idPLogScope::idPLogScope(this: &v73, pl: &pLog, gMask: v6, label: v7);
  if ( ai_useBrakingTurns.valueInteger == 0 )
    goto LABEL_39;
  Physics = idEntity::GetPhysics(this: ai);
  v9 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
  v10 = v9;
  if ( fsm->nextArrivalCorner < 0 )
    goto LABEL_39;
  v11 = (float)(fsm->nextArrivalPos.y - v9[1]);
  x = fsm->nextArrivalPos.x;
  v13 = *v9;
  p_nextArrivalPos = &fsm->nextArrivalPos;
  v14 = (float)(fsm->nextArrivalPos.z - v9[2]);
  if ( (float)((float)((float)v14 * (float)v14)
             + (float)((float)((float)((float)x - (float)v13) * (float)((float)x - (float)v13))
                     + (float)((float)v11 * (float)v11))) <= (double)fsm->arrivalTransitionCache.maximumDeltaOriginDistanceSqr )
    goto LABEL_39;
  idAnimBaseFSM::UpdateTurnTransitionCache(this: fsm);
  v70 = 0;
  v15 = fsm->idAIFSMLite::idEventReceiver::idClass::__vftable;
  v69 = 257;
  v71 = 1;
  maximumPathDistance = 0.0;
  v15->GetPathPositionAndDirection(
    this: fsm,
    a2: (const idAnimBaseFSM::pathPositionAndDirectionParms_t *)&maximumPathDistance,
    a3: (idVec3 *)v65,
    a4: (idVec3 *)v76);
  maximumPathDistance = fsm->turnTransitionCache.maximumPathDistance;
  v16 = fsm->GetPathPositionAndDirection(
          this: fsm,
          a2: (const idAnimBaseFSM::pathPositionAndDirectionParms_t *)&maximumPathDistance,
          a3: (idVec3 *)v63,
          a4: (idVec3 *)v75);
  v17 = _cntlzw(ai->entityNumber - ai_debugAnimWebTransitions.valueInteger);
  v18 = (v17 & 0x20) != 0;
  if ( (v17 & 0x20) != 0 )
  {
    v19 = gameLocal->GetRenderWorld(this: gameLocal);
    v78[0] = v65[0];
    v78[1] = v65[1];
    v78[2] = v65[2];
    v78[3] = 5.0;
    v19->DebugSphere(
      this: v19,
      a2: (const idVec4 *)&idColor::colorBlue,
      a3: (const idSphere *)v78,
      a4: 12,
      a5: 1,
      a6: false);
    v20 = gameLocal->GetRenderWorld(this: gameLocal);
    v80[0] = v63[0];
    v80[1] = v63[1];
    v80[2] = v63[2];
    v80[3] = 5.0;
    v20->DebugSphere(
      this: v20,
      a2: (const idVec4 *)&idColor::colorPurple,
      a3: (const idSphere *)v80,
      a4: 12,
      a5: 1,
      a6: false);
  }
  v21 = 0.3826834;
  v22 = (float)((float)(fsm->orientBody.axis.mat[0].x * v76[0])
              + (float)((float)(fsm->orientBody.axis.mat[0].y * v76[1]) + (float)(fsm->orientBody.axis.mat[0].z * v76[2])));
  if ( this->turnInfo.hasUpcomingTurnPoint )
    goto LABEL_10;
  if ( (float)((float)(v76[2] * v75[2]) + (float)((float)(v75[0] * v76[0]) + (float)(v76[1] * v75[1]))) > 0.3826834
    && v22 > 0.3826834 )
  {
    goto LABEL_39;
  }
  if ( this->turnInfo.hasUpcomingTurnPoint )
  {
LABEL_10:
    v23 = (float)(this->turnInfo.upcomingTurnPoint.y - v10[1]);
    v24 = (float)(this->turnInfo.upcomingTurnPoint.x - *v10);
    if ( (float)((float)((float)v24 * (float)v24) + (float)((float)v23 * (float)v23)) > (double)this->turnInfo.distanceToTurnPointSqr )
    {
      this->turnInfo.distanceToTurnPointSqr = 0.0;
      this->turnInfo.hasUpcomingTurnPoint = false;
      this->turnInfo.upcomingTurnPoint.y = 0.0;
      this->turnInfo.upcomingTurnPoint.x = 0.0;
      this->turnInfo.upcomingTurnPoint.z = 0.0;
      this->turnInfo.upcomingTurnPointWithBackoff.z = 0.0;
      this->turnInfo.upcomingTurnPointWithBackoff.y = 0.0;
      this->turnInfo.upcomingTurnPointWithBackoff.x = 0.0;
    }
    else
    {
      this->turnInfo.distanceToTurnPointSqr = (float)((float)v24 * (float)v24) + (float)((float)v23 * (float)v23);
    }
    v21 = 0.3826834;
  }
  if ( !this->turnInfo.hasUpcomingTurnPoint && (v16 == -1 || v22 <= v21) )
  {
    v61 = *(idVec3 *)v10;
    v26 = *v10;
    v27 = v10[1];
    v28 = v10[2];
  }
  else if ( this->turnInfo.hasUpcomingTurnPoint )
  {
    y = this->turnInfo.upcomingTurnPoint.y;
    z = this->turnInfo.upcomingTurnPoint.z;
    v26 = this->turnInfo.upcomingTurnPointWithBackoff.x;
    v27 = this->turnInfo.upcomingTurnPointWithBackoff.y;
    v28 = this->turnInfo.upcomingTurnPointWithBackoff.z;
    v61.x = this->turnInfo.upcomingTurnPoint.x;
    v61.y = y;
    v61.z = z;
  }
  else
  {
    v31 = &fsm->cachedCorners.list[v16];
    v32 = v31->position.x;
    v61.x = v31->position.x;
    v33 = v31->position.y;
    v34 = (float)(v31->position.y - v65[1]);
    v61.y = v31->position.y;
    v35 = v31->position.z;
    v36 = (float)(v31->position.z - v65[2]);
    v67.x = (float)v32 - v65[0];
    v67.y = v34;
    v67.z = v36;
    v61.z = v35;
    idVec3::NormalizeFast(this: &v67);
    v64.x = v63[0] - (float)v32;
    v64.z = v63[2] - (float)v35;
    v64.y = v63[1] - (float)v33;
    idVec3::NormalizeFast(this: &v64);
    v66.x = v67.x - v64.x;
    v66.z = v67.z - v64.z;
    v66.y = v67.y - v64.y;
    idVec3::NormalizeFast(this: &v66);
    v72.debugDrawTime = 0;
    v72.layer = NAVLAYER_NONE;
    v72.obstacleMask = Obstacle_All;
    v72.surfacesUsable = NavCustomAll;
    GetNavParms = ai->GetNavParms;
    v74.x = (float)((float)(v66.x * (float)50.0) * (float)2.0) + (float)v32;
    v74.z = (float)v35 + (float)((float)(v66.z * (float)50.0) * (float)2.0);
    v74.y = (float)v33 + (float)((float)(v66.y * (float)50.0) * (float)2.0);
    v38 = (int)GetNavParms(this: ai);
    v39 = ai->GetNavParms;
    v72.layer = *(_DWORD *)(*(_DWORD *)v38 + 72);
    v40 = (int)v39(this: ai);
    v41 = ai->__vftable;
    v72.obstacleMask = *(_DWORD *)(v40 + 140);
    v72.surfacesUsable = v41->GetNavParms(this: ai)->surface.surfacesUsable;
    idNpMover::idProbeResults::idProbeResults(this: &v82);
    idNpMover::NavProbe(input: &v72, start: &v61, end: &v74, results: &v82, genPath: nullptr);
    this->turnInfo.hasUpcomingTurnPoint = true;
    v42 = v61.y;
    v43 = v61.x;
    v44 = v61.z;
    v26 = v82.endPos.x;
    v27 = v82.endPos.y;
    v28 = v82.endPos.z;
    this->turnInfo.distanceToTurnPointSqr = (float)((float)(v61.x - *v10) * (float)(v61.x - *v10))
                                          + (float)((float)(v61.y - v10[1]) * (float)(v61.y - v10[1]));
    this->turnInfo.upcomingTurnPoint.x = v43;
    this->turnInfo.upcomingTurnPoint.y = v42;
    this->turnInfo.upcomingTurnPoint.z = v44;
    this->turnInfo.upcomingTurnPointWithBackoff.x = v26;
    this->turnInfo.upcomingTurnPointWithBackoff.y = v27;
    this->turnInfo.upcomingTurnPointWithBackoff.z = v28;
    idNpAreaHandle::~idNpAreaHandle(this: &v82.endArea);
  }
  if ( v18 )
  {
    v45 = gameLocal->GetRenderWorld(this: gameLocal);
    v77[1] = v27;
    v77[3] = 5.0;
    v77[2] = v28;
    v77[0] = v26;
    v45->DebugSphere(
      this: v45,
      a2: (const idVec4 *)&idColor::colorYellow,
      a3: (const idSphere *)v77,
      a4: 12,
      a5: 1,
      a6: false);
  }
  idAnimWebTransitions::transitionQueryValidation_t::transitionQueryValidation_t(this: &v81);
  if ( ai_enableScrambles.valueInteger == 0
    || (v46 = 1, ai->aiVolatile.animation.animWebAnimator.ptr[0].runIndexType != ANIMWEBAI_RUNINDEXTYPE_SCRAMBLE) )
  {
    v46 = 0;
  }
  v48 = v46 == 0;
  v47 = (ai->aiVolatile.groupStatus.condition & 8) != 0;
  if ( !v48 )
  {
    v81.suggestedFlags |= 0x4000u;
    v81.allowedFlags |= 0x4000u;
  }
  if ( v47 )
  {
    v81.allowedFlags |= 0x2000u;
    v81.requiredFlags |= 0x2000u;
  }
  idAnimWebTransitions::transitionQueryParms_t::transitionQueryParms_t(this: &v84);
  v84.sourceOrigin1.x = *v10;
  v84.sourceOrigin1.y = v10[1];
  v49 = v10[2];
  p_nextArrivalPos = &fsm->orientBody.axis.mat[2];
  v50 = fsm->orientBody.axis.mat[0].x;
  v51 = fsm->orientBody.axis.mat[0].y;
  v52 = fsm->orientBody.axis.mat[0].z;
  v53 = fsm->orientBody.axis.mat[1].x;
  v54 = fsm->orientBody.axis.mat[1].y;
  v55 = fsm->orientBody.axis.mat[1].z;
  v56 = fsm->orientBody.axis.mat[2].x;
  v57 = fsm->orientBody.axis.mat[2].y;
  v58 = fsm->orientBody.axis.mat[2].z;
  v84.sourceOrigin1.z = v49;
  v84.turnPoint.x = v61.x;
  v84.sourceAxis.mat[0].x = v50;
  v84.turnPoint.y = v61.y;
  v84.sourceAxis.mat[0].y = v51;
  v84.turnPoint.z = v61.z;
  v84.sourceAxis.mat[0].z = v52;
  v84.sourceAxis.mat[1].x = v53;
  v84.sourceAxis.mat[1].y = v54;
  v84.sourceAxis.mat[1].z = v55;
  v84.sourceAxis.mat[2].x = v56;
  v84.sourceAxis.mat[2].y = v57;
  v84.sourceAxis.mat[2].z = v58;
  idAnimWebTransitions::transitionQueryResult_t::transitionQueryResult_t(this: &v83);
  if ( (unsigned __int8)idAnimWebTransitions::FindTurnTransition(
                          ai,
                          validation: &v81,
                          cache: &fsm->turnTransitionCache,
                          parms: &v84,
                          out: &v83) == 0
    || (unsigned __int8)idAnimBaseFSM::StartTurnAnimation(
                          this: fsm,
                          transInfo: &v83,
                          destinationOrigin: &v83.destOrigin) == 0 )
  {
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v84.cachedCorners);
LABEL_39:
    this->turnInfo.hasUpcomingTurnPoint = false;
    idPLogScope::~idPLogScope(this: &v73);
    RD_EventEnd();
    return 0;
  }
  if ( v18 )
  {
    v59 = gameLocal->GetRenderWorld(this: gameLocal);
    v79[0] = v26;
    v79[2] = v28;
    v79[1] = v27;
    v79[3] = 5.0;
    v59->DebugSphere(
      this: v59,
      a2: (const idVec4 *)&idColor::colorGreen,
      a3: (const idSphere *)v79,
      a4: 12,
      a5: 5000,
      a6: false);
  }
  idAIStateLite::SetSubState(this, newSubState: 2);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v84.cachedCorners);
  idPLogScope::~idPLogScope(this: &v73);
  RD_EventEnd();
  return 1;
}


// ========================================================================
// __unwind$492194
// EA  : 0x82A82478
// RVA : 0x00A82478
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm_statemove.cpp
// ========================================================================

void _unwind_492194()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 1184 + 1048));
}


// ========================================================================
// __unwind$492195
// EA  : 0x82A824A0
// RVA : 0x00A824A0
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm_statemove.cpp
// ========================================================================

void _unwind_492195()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 1184 + 208));
}


// ========================================================================
// __unwind$492196
// EA  : 0x82A824C8
// RVA : 0x00A824C8
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm_statemove.cpp
// ========================================================================

void _unwind_492196()
{
  int v0; // r12

  idNpMover::idProbeResults::~idProbeResults(this: (idNpMover::idProbeResults *)(v0 - 1184 + 400));
}


// ========================================================================
// __unwind$492197
// EA  : 0x82A824F0
// RVA : 0x00A824F0
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm_statemove.cpp
// ========================================================================

void _unwind_492197()
{
  int v0; // r12

  idAnimWebTransitions::transitionQueryParms_t::~transitionQueryParms_t(this: (idAnimWebTransitions::transitionQueryParms_t *)(v0 - 1184 + 528));
}


// ========================================================================
// ?Work@idAnimStateMoveGround@@UAAHPAVidAI2@@PAVidAnimBaseFSM@@@Z
// EA  : 0x82A82520
// RVA : 0x00A82520
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm_statemove.cpp
// ========================================================================

int __fastcall idAnimStateMoveGround::Work(idAnimStateMoveGround *this, idAI2 *ai, idAnimBaseFSM *fsm)
{
  unsigned __int64 v6; // r6
  const char *v7; // r7
  double x; // fp11
  idAnimBaseFSM_vtbl *v9; // r9
  int updated; // r30
  idAnimStateMoveGround *v12; // r3
  idAnimWebCmdCtx *v13; // r3
  int v14; // r27
  unsigned __int64 v15; // r6
  const char *v16; // r7
  int v17; // r27
  idStr *MoveCyclePostfix; // r3
  idAIAnimWebState_Movement *v19; // r3
  idAnimWebState *v20; // r11
  idAIAnimWebState_Movement *v21; // r10
  idAIAnimWebState_Movement_vtbl **p_debugState; // r11
  int i; // ctr
  int v24; // r9
  idAnimWebCmdCtx *v25; // r3
  idAnimWebCmd *v26; // r3
  idAnimWebCmd *v27; // r3
  int flags; // r9
  int v29; // r27
  int v30; // r30
  walkState_t v31; // r3
  int IsMoving; // r27
  idAnimWebCmdCtx *v33; // r3
  int v34; // r4
  idAnimStateMoveGround *v35; // r3
  idAnimWebCmdCtx *v36; // r3
  bool v37; // zf
  idAnimBaseFSM_vtbl *v38; // r10
  idAnimWebCmdCtx *v39; // r3
  walkState_t v40; // r3
  int v41; // r30
  const idVec3 *v42; // r3
  idPLogScope v43; // [sp+50h] [-250h] BYREF
  idPLogScope v44; // [sp+58h] [-248h] BYREF
  bool v45; // [sp+60h] [-240h]
  idAIAnimWebState_Movement v46; // [sp+70h] [-230h] BYREF
  idAIAnimWebState_Current v47; // [sp+90h] [-210h] BYREF
  idAIAnimWebState_Idle v48; // [sp+B0h] [-1F0h] BYREF
  idAIAnimWebState_Target v49; // [sp+D0h] [-1D0h] BYREF
  idAIAnimWebState_Target v50; // [sp+F0h] [-1B0h] BYREF
  idAIAnimWebState_Current v51; // [sp+110h] [-190h] BYREF
  idAIAnimWebState_Target v52; // [sp+130h] [-170h] BYREF
  idAIAnimWebState_Current v53; // [sp+150h] [-150h] BYREF
  idAIAnimWebState_Movement v54; // [sp+170h] [-130h] BYREF
  idAnimStateMoveGround v55; // [sp+190h] [-110h] BYREF

  RD_EventBegin(name: "idAnimStateMoveGround::Work");
  LODWORD(v6) = "idAnimStateMoveGround::Work";
  HIDWORD(v6) = 6;
  idPLogScope::idPLogScope(this: &v43, pl: &pLog, gMask: v6, label: v7);
  fsm->desiredMoveAxis.mat[0] = fsm->orientMove.axis.mat[0];
  x = fsm->orientMove.axis.mat[1].x;
  v44.logIndex = (int)&fsm->orientMove.axis;
  fsm->desiredMoveAxis.mat[1].x = x;
  fsm->desiredMoveAxis.mat[1].y = fsm->orientMove.axis.mat[1].y;
  v44.logIndex = (int)&fsm->desiredMoveAxis.mat[1];
  fsm->desiredMoveAxis.mat[1].z = fsm->orientMove.axis.mat[1].z;
  v44.logIndex = (int)&fsm->desiredMoveAxis.mat[2];
  fsm->desiredMoveAxis.mat[2] = fsm->orientMove.axis.mat[2];
  switch ( this->subState )
  {
    case 0:
    case 2:
    case 3:
      ai->aiVolatile.memory.temporaryHoldFire = false;
      v9 = fsm->idAIFSMLite::idEventReceiver::idClass::__vftable;
      fsm->emergencyLerp = false;
      if ( v9->IsMoveDone(this: fsm) )
      {
        idAIStateLite::SetSubState(this, newSubState: 3);
        updated = idAnimStateMoveGround::UpdateStopping(this, ai, fsm);
        idPLogScope::~idPLogScope(this: &v43);
        RD_EventEnd();
        return updated;
      }
      v44.logIndex = this->subState;
      if ( v44.logIndex == 3 )
      {
        v12 = this;
LABEL_9:
        idAIStateLite::SetSubState(this: v12, newSubState: 0);
        goto LABEL_10;
      }
      if ( v44.logIndex == 2 )
      {
        v13 = ai->GetAnimWebCmdCtx(this: ai);
        if ( !idAnimWebCmdCtx::HasActiveWaitHandle(this: v13) )
        {
          v12 = this;
          goto LABEL_9;
        }
      }
LABEL_10:
      v14 = idAnimStateMoveGround::CheckForLinkStart(this, ai, fsm);
      if ( v14 != 0 )
        goto LABEL_11;
      RD_EventBegin(name: "idAnimStateMoveGround::Work -- animWebState stuff");
      LODWORD(v15) = "idAnimStateMoveGround::Work -- animWebState stuff";
      HIDWORD(v15) = 6;
      idPLogScope::idPLogScope(this: &v44, pl: &pLog, gMask: v15, label: v16);
      idAIAnimWebState_Current::idAIAnimWebState_Current(this: &v47, ai);
      idAIAnimWebState_Idle::idAIAnimWebState_Idle(
        this: &v48,
        ai,
        subweb: AISUBWEB_MAX,
        posture: POSTURE_MAX,
        useWeaponSlot: EQUIP_MAX);
      if ( idAnimWebState::operator==(this: &v47.idAnimWebState, other: &v48.idAnimWebState) )
      {
        v17 = idAnimStateMoveGround::CheckForStepTransition(this, ai, fsm);
        if ( v17 != 0 )
        {
          v48.__vftable = (idAIAnimWebState_Idle_vtbl *)&idAIAnimWebState::`vftable';
          v47.__vftable = (idAIAnimWebState_Current_vtbl *)&idAIAnimWebState::`vftable';
          idPLogScope::~idPLogScope(this: &v44);
          RD_EventEnd();
          idPLogScope::~idPLogScope(this: &v43);
          RD_EventEnd();
          return v17;
        }
      }
      MoveCyclePostfix = idAnimStateMoveGround::GetMoveCyclePostfix(this: &v55, result: (idStr *)this, ai, fsm);
      idAIAnimWebState_Movement::idAIAnimWebState_Movement(
        this: &v46,
        ai,
        postfix: MoveCyclePostfix->data,
        subweb: AISUBWEB_MAX,
        posture: POSTURE_MAX);
      idStr::FreeData(this: (idStr *)&v55);
      if ( !idAnimWebState::Verify(this: &v46.idAnimWebState, errorMsg: nullptr) )
      {
        v19 = idAIAnimWebState_Movement::idAIAnimWebState_Movement(
                this: &v54,
                ai,
                postfix: nullptr,
                subweb: AISUBWEB_MAX,
                posture: POSTURE_MAX);
        v20 = &v19->idAnimWebState;
        if ( v19 == nullptr )
          v20 = nullptr;
        v21 = &v46;
        p_debugState = (idAIAnimWebState_Movement_vtbl **)&v20[-1].debugState;
        for ( i = 5; i != 0; --i )
        {
          ++p_debugState;
          v21 = (idAIAnimWebState_Movement *)((char *)v21 + 4);
          v21->__vftable = *p_debugState;
        }
        v54.__vftable = (idAIAnimWebState_Movement_vtbl *)&idAIAnimWebState::`vftable';
      }
      idAIAnimWebState_Target::idAIAnimWebState_Target(this: &v49, ai);
      v24 = -fsm->cachedCorners.num & ~fsm->cachedCorners.num;
      v45 = v24 < 0;
      if ( v24 < 0 && idAnimWebState::operator!=(this: &v46.idAnimWebState, other: &v49.idAnimWebState) )
      {
        v25 = ai->GetAnimWebCmdCtx(this: ai);
        idAnimWebCmd::idAnimWebCmd(
          this: (idAnimWebCmd *)&v55.leapAnimSet.animInto.baseBuffer[4],
          _owner: v25,
          userName: "w:\\tech5\\tungsten\\game\\ai\\animfsm\\AnimFSM_StateMove.cpp(179) : toLocomotion");
        *(_DWORD *)&v55.playedDeparture |= 0x200u;
        v26 = idAnimWebCmd::ChangeState(
                this: (idAnimWebCmd *)&v55.leapAnimSet.animInto.baseBuffer[4],
                _dst: &v46.idAnimWebState);
        v26->groups = 1;
        v26->groupFilter = -1;
        v26->intrBlend = INTR_BLEND_MULTI;
        v27 = idAnimWebCmd::ViaSubweb(this: v26, subweb: "transitions");
        flags = v27->flags;
        v27->forceFallbackPathSize = -1;
        v27->flags = flags | 0x40;
        *(_DWORD *)&v55.leapAnimSet.animLand.baseBuffer[16] = 2;
        idAnimWebCmd::Commit(
          this: (idAnimWebCmd *)&v55.leapAnimSet.animInto.baseBuffer[4],
          handle: &fsm->animWaitHandle,
          priority: AWCMD_PRIORITY_HIGH,
          ev: AWCMD_EVENT_DEST_BLEND_START);
      }
      if ( !this->playedDeparture && !idAnimWebState::operator==(this: &v47.idAnimWebState, other: &v49.idAnimWebState) )
        goto LABEL_31;
      v29 = idAnimStateMoveGround::CheckForArrival(this, ai, fsm);
      if ( v29 != 0 )
      {
        v49.__vftable = (idAIAnimWebState_Target_vtbl *)&idAIAnimWebState::`vftable';
        v46.__vftable = (idAIAnimWebState_Movement_vtbl *)&idAIAnimWebState::`vftable';
        v48.__vftable = (idAIAnimWebState_Idle_vtbl *)&idAIAnimWebState::`vftable';
        v47.__vftable = (idAIAnimWebState_Current_vtbl *)&idAIAnimWebState::`vftable';
        idPLogScope::~idPLogScope(this: &v44);
        RD_EventEnd();
        idPLogScope::~idPLogScope(this: &v43);
        RD_EventEnd();
        return v29;
      }
      else
      {
        if ( this->subState == 2 || (v30 = idAnimStateMoveGround::CheckForTurnTransition(this, ai, fsm)) == 0 )
        {
LABEL_31:
          v49.__vftable = (idAIAnimWebState_Target_vtbl *)&idAIAnimWebState::`vftable';
          v46.__vftable = (idAIAnimWebState_Movement_vtbl *)&idAIAnimWebState::`vftable';
          v48.__vftable = (idAIAnimWebState_Idle_vtbl *)&idAIAnimWebState::`vftable';
          v47.__vftable = (idAIAnimWebState_Current_vtbl *)&idAIAnimWebState::`vftable';
          idPLogScope::~idPLogScope(this: &v44);
          RD_EventEnd();
          goto LABEL_65;
        }
        v49.__vftable = (idAIAnimWebState_Target_vtbl *)&idAIAnimWebState::`vftable';
        v46.__vftable = (idAIAnimWebState_Movement_vtbl *)&idAIAnimWebState::`vftable';
        v48.__vftable = (idAIAnimWebState_Idle_vtbl *)&idAIAnimWebState::`vftable';
        v47.__vftable = (idAIAnimWebState_Current_vtbl *)&idAIAnimWebState::`vftable';
        idPLogScope::~idPLogScope(this: &v44);
        RD_EventEnd();
        idPLogScope::~idPLogScope(this: &v43);
        RD_EventEnd();
        return v30;
      }
    case 1:
      v38 = fsm->idAIFSMLite::idEventReceiver::idClass::__vftable;
      fsm->useFullyBodyAiming = false;
      if ( v38->IsMoveDone(this: fsm) )
        goto LABEL_59;
      v39 = ai->GetAnimWebCmdCtx(this: ai);
      if ( idAnimWebCmdCtx::HasActiveWaitHandle(this: v39) )
        goto LABEL_65;
      idAnimBaseFSM::ReleaseAllNavTraces(this: fsm);
      goto LABEL_62;
    case 4:
      ai->aiVolatile.memory.temporaryHoldFire = true;
      v14 = idAnimStateMoveGround::CheckForLinkStart(this, ai, fsm);
      if ( v14 != 0 )
      {
LABEL_11:
        idPLogScope::~idPLogScope(this: &v43);
        RD_EventEnd();
        return v14;
      }
      v31 = ai->GetWalkState(this: ai);
      IsMoving = (unsigned __int8)idAnimBaseFSM::GetUserChannelIsMoving(this: fsm, threshold: v31);
      v33 = ai->GetAnimWebCmdCtx(this: ai);
      if ( !idAnimWebCmdCtx::HasActiveWaitHandle(this: v33) || (_BYTE)IsMoving != 0 )
      {
        v34 = 0;
        fsm->animWaitHandle.status = AWCMD_STATUS_DONE;
        v35 = this;
        this->playedDeparture = true;
        goto LABEL_64;
      }
      idAIAnimWebState_Current::idAIAnimWebState_Current(this: &v53, ai);
      idAIAnimWebState_Target::idAIAnimWebState_Target(this: &v52, ai);
      if ( ai->aiVolatile.animation.animWebAnimator.ptr[0].modelAnimStates.list->blending
        || !idAnimWebState::operator==(this: &v53.idAnimWebState, other: &v52.idAnimWebState) )
      {
        v52.__vftable = (idAIAnimWebState_Target_vtbl *)&idAIAnimWebState::`vftable';
        v53.__vftable = (idAIAnimWebState_Current_vtbl *)&idAIAnimWebState::`vftable';
      }
      else
      {
        fsm->animWaitHandle.status = AWCMD_STATUS_DONE;
        idAIStateLite::SetSubState(this, newSubState: 0);
        v52.__vftable = (idAIAnimWebState_Target_vtbl *)&idAIAnimWebState::`vftable';
        v53.__vftable = (idAIAnimWebState_Current_vtbl *)&idAIAnimWebState::`vftable';
      }
      goto LABEL_65;
    case 5:
    case 6:
      if ( idAnimBaseFSM::CheckDeltaCorrectionAbortConditions(this: fsm) )
      {
        idAnimBaseFSM::ResetAnimDeltaCorrection(this: fsm);
        idAnimBaseFSM::ReleaseAllNavTraces(this: fsm);
LABEL_62:
        v35 = this;
        goto LABEL_63;
      }
      ai->aiVolatile.memory.temporaryHoldFire = true;
      if ( fsm->IsMoveDone(this: fsm) )
      {
LABEL_59:
        idAnimBaseFSM::SetMoveStatus(this: fsm, _status: AIMOVESTATUS_DONE);
        idPLogScope::~idPLogScope(this: &v43);
        RD_EventEnd();
        return 4;
      }
      v36 = ai->GetAnimWebCmdCtx(this: ai);
      if ( !idAnimWebCmdCtx::HasActiveWaitHandle(this: v36) )
      {
        idAnimBaseFSM::ReleaseAllNavTraces(this: fsm);
        v37 = (unsigned __int8)idAnimBaseFSM::CheckForEndDeltaCorrectionEmergencyLerp(this: fsm) == 0;
        v35 = this;
        if ( !v37 )
        {
          v34 = 19;
LABEL_64:
          idAIStateLite::SetSubState(this: v35, newSubState: v34);
          goto LABEL_65;
        }
LABEL_63:
        v34 = 0;
        goto LABEL_64;
      }
      idAIAnimWebState_Current::idAIAnimWebState_Current(this: &v51, ai);
      idAIAnimWebState_Target::idAIAnimWebState_Target(this: &v50, ai);
      if ( ai->aiVolatile.animation.animWebAnimator.ptr[0].modelAnimStates.list->blending
        || !idAnimWebState::operator==(this: &v51.idAnimWebState, other: &v50.idAnimWebState) )
      {
        v50.__vftable = (idAIAnimWebState_Target_vtbl *)&idAIAnimWebState::`vftable';
        v51.__vftable = (idAIAnimWebState_Current_vtbl *)&idAIAnimWebState::`vftable';
      }
      else
      {
        fsm->animWaitHandle.status = AWCMD_STATUS_DONE;
        idAIStateLite::SetSubState(this, newSubState: 0);
        v50.__vftable = (idAIAnimWebState_Target_vtbl *)&idAIAnimWebState::`vftable';
        v51.__vftable = (idAIAnimWebState_Current_vtbl *)&idAIAnimWebState::`vftable';
      }
LABEL_65:
      idPLogScope::~idPLogScope(this: &v43);
LABEL_66:
      RD_EventEnd();
      return 1;
    case 7:
      v40 = ai->GetWalkState(this: ai);
      idAnimBaseFSM::GetUserChannelIsMoving(this: fsm, threshold: v40);
      if ( fsm->animWaitHandle.status == AWCMD_STATUS_WAITING )
        goto LABEL_65;
      fsm->CallbackFinishLinkTraversal(this: fsm);
      idAIStateLite::SetSubState(this, newSubState: 0);
      idPLogScope::~idPLogScope(this: &v43);
      goto LABEL_66;
    case 8:
    case 9:
      v41 = idAnimStateMoveGround::UpdateFallTraversal(this, ai, fsm);
      idPLogScope::~idPLogScope(this: &v43);
      RD_EventEnd();
      return v41;
    case 0x11:
      v34 = 18;
      v35 = this;
      goto LABEL_64;
    case 0x13:
      if ( fsm->IsMoveDone(this: fsm) )
        goto LABEL_59;
      if ( fsm->cachedCorners.num > 0 )
      {
        v42 = fsm->GetFinalPoint(this: &fsm->idAIMoveInterface);
        if ( idAnimBaseFSM::HasGoalChangedSignificantly(this: fsm, newGoal: v42, cutoff: 20.0) )
          goto LABEL_62;
      }
      goto LABEL_65;
    default:
      goto LABEL_65;
  }
}


// ========================================================================
// __unwind$492692
// EA  : 0x82A82E78
// RVA : 0x00A82E78
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm_statemove.cpp
// ========================================================================

void _unwind_492692()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 672 + 604));
}


// ========================================================================
// __unwind$492693
// EA  : 0x82A82EA0
// RVA : 0x00A82EA0
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm_statemove.cpp
// ========================================================================

void _unwind_492693()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 672 + 80));
}


// ========================================================================
// __unwind$492694
// EA  : 0x82A82EC8
// RVA : 0x00A82EC8
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm_statemove.cpp
// ========================================================================

void _unwind_492694()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 672 + 605));
}


// ========================================================================
// __unwind$492695
// EA  : 0x82A82EF0
// RVA : 0x00A82EF0
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm_statemove.cpp
// ========================================================================

void _unwind_492695()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 672 + 88));
}


// ========================================================================
// __unwind$492696
// EA  : 0x82A82F18
// RVA : 0x00A82F18
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm_statemove.cpp
// ========================================================================

void _unwind_492696()
{
  int v0; // r12

  idAIAnimWebState_Current::~idAIAnimWebState_Current(this: (idAIAnimWebState_Current *)(v0 - 672 + 144));
}


// ========================================================================
// __unwind$492697
// EA  : 0x82A82F40
// RVA : 0x00A82F40
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm_statemove.cpp
// ========================================================================

void _unwind_492697()
{
  int v0; // r12

  idAIAnimWebState_Current::~idAIAnimWebState_Current(this: (idAIAnimWebState_Current *)(v0 - 672 + 176));
}


// ========================================================================
// __unwind$492698
// EA  : 0x82A82F68
// RVA : 0x00A82F68
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm_statemove.cpp
// ========================================================================

void _unwind_492698()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 672 + 400));
}


// ========================================================================
// __unwind$492699
// EA  : 0x82A82F90
// RVA : 0x00A82F90
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm_statemove.cpp
// ========================================================================

void _unwind_492699()
{
  int v0; // r12

  idAIAnimWebState_Current::~idAIAnimWebState_Current(this: (idAIAnimWebState_Current *)(v0 - 672 + 112));
}


// ========================================================================
// __unwind$492701
// EA  : 0x82A82FB8
// RVA : 0x00A82FB8
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm_statemove.cpp
// ========================================================================

void _unwind_492701()
{
  int v0; // r12

  idAIAnimWebState_Current::~idAIAnimWebState_Current(this: (idAIAnimWebState_Current *)(v0 - 672 + 208));
}


// ========================================================================
// __unwind$492702
// EA  : 0x82A82FE0
// RVA : 0x00A82FE0
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm_statemove.cpp
// ========================================================================

void _unwind_492702()
{
  int v0; // r12

  idAIAnimWebState_Current::~idAIAnimWebState_Current(this: (idAIAnimWebState_Current *)(v0 - 672 + 336));
}


// ========================================================================
// __unwind$492703
// EA  : 0x82A83008
// RVA : 0x00A83008
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm_statemove.cpp
// ========================================================================

void _unwind_492703()
{
  int v0; // r12

  idAIAnimWebState_Current::~idAIAnimWebState_Current(this: (idAIAnimWebState_Current *)(v0 - 672 + 304));
}


// ========================================================================
// __unwind$492704
// EA  : 0x82A83030
// RVA : 0x00A83030
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm_statemove.cpp
// ========================================================================

void _unwind_492704()
{
  int v0; // r12

  idAIAnimWebState_Current::~idAIAnimWebState_Current(this: (idAIAnimWebState_Current *)(v0 - 672 + 272));
}


// ========================================================================
// __unwind$492705
// EA  : 0x82A83058
// RVA : 0x00A83058
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm_statemove.cpp
// ========================================================================

void _unwind_492705()
{
  int v0; // r12

  idAIAnimWebState_Current::~idAIAnimWebState_Current(this: (idAIAnimWebState_Current *)(v0 - 672 + 240));
}


// ========================================================================
// `dynamic initializer for 'ai_useStepTransitionAnims''
// EA  : 0x83368860
// RVA : 0x01368860
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm_statemove.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_useStepTransitionAnims__()
{
  idCVar::idCVar(
    this: &ai_useStepTransitionAnims,
    name: "ai_useStepTransitionAnims",
    value: "1",
    flags: 1,
    description: "enable/disable using step transition animations to get into desired animation states at move destinations.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_useStepTransitionAnims__);
}


// ========================================================================
// `dynamic initializer for 'ai_debugClimb''
// EA  : 0x833688B8
// RVA : 0x013688B8
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm_statemove.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_debugClimb__()
{
  idCVar::idCVar(
    this: &ai_debugClimb,
    name: "ai_debugClimb",
    value: "0",
    flags: 1,
    description: "set to 1 to show debug information on climbing.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_debugClimb__);
}


// ========================================================================
// `dynamic initializer for 'ai_useBrakingTurns''
// EA  : 0x83368910
// RVA : 0x01368910
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm_statemove.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_useBrakingTurns__()
{
  idCVar::idCVar(
    this: &ai_useBrakingTurns,
    name: "ai_useBrakingTurns",
    value: "1",
    flags: 1,
    description: "enable/disable braking turns.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_useBrakingTurns__);
}

