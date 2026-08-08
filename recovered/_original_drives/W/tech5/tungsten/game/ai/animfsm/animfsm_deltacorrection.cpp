
// ========================================================================
// ?SameSignRelaxed@@YA_NMMM@Z
// EA  : 0x82A798E0
// RVA : 0x00A798E0
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm_deltacorrection.cpp
// ========================================================================

int __fastcall SameSignRelaxed(double x, double y, double t)
{
  unsigned __int8 v3; // r11

  if ( x >= -t == y >= -t )
    return 1;
  v3 = 0;
  if ( x < t == y < t )
    return 1;
  return v3;
}


// ========================================================================
// ?AnimEvent_AnimDeltaCorrectionSetFlags@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@W4aiAnimDCFlags_t@@@Z
// EA  : 0x82A799D8
// RVA : 0x00A799D8
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm_deltacorrection.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __usercall idAI2::AnimEvent_AnimDeltaCorrectionSetFlags@<r4>(
        idAI2 *this@<r3>,
        int result@<r4>,
        const idMD6Anim *anim@<r5>,
        aiAnimDCFlags_t flags@<r6>)
{
  if ( (flags & 1) != 0 )
    *(_BYTE *)(result + 35392) = (4 * ((unsigned int)~*(unsigned __int8 *)(result + 35392) >> 2)) & 4
                               | *(_BYTE *)(result + 35392) & 0xFB;
  if ( (flags & 4) != 0 )
    *(_BYTE *)(result + 35392) = ((unsigned __int8)((unsigned int)~*(unsigned __int8 *)(result + 35392) >> 6) << 6)
                               & 0x40
                               | *(_BYTE *)(result + 35392) & 0xBF;
  if ( (flags & 8) != 0 )
    *(_BYTE *)(result + 35392) = (32 * ((unsigned int)~*(unsigned __int8 *)(result + 35392) >> 5)) & 0x20
                               | *(_BYTE *)(result + 35392) & 0xDF;
  if ( (flags & 0x10) != 0 )
    *(_BYTE *)(result + 35392) = (16 * ((unsigned int)~*(unsigned __int8 *)(result + 35392) >> 4)) & 0x10
                               | *(_BYTE *)(result + 35392) & 0xEF;
  if ( (flags & 2) != 0 )
    *(_BYTE *)(result + 35392) = (8 * ((unsigned int)~*(unsigned __int8 *)(result + 35392) >> 3)) & 8
                               | *(_BYTE *)(result + 35392) & 0xF7;
  if ( (flags & 1) != 0 )
    *(_BYTE *)(result + 35392) = (4 * _cntlzw(*(_BYTE *)(result + 35392) & 0x80)) & 0x80
                               | *(_BYTE *)(result + 35392) & 0x7F;
  if ( (flags & 0x40) != 0 )
    *(_BYTE *)(result + 35392) = (2 * ((unsigned int)~*(unsigned __int8 *)(result + 35392) >> 1)) & 2
                               | *(_BYTE *)(result + 35392) & 0xFD;
  if ( (flags & 0x80) != 0 )
    *(_BYTE *)(result + 35392) = *(_BYTE *)(result + 35392) & 0xFE | ((*(_BYTE *)(result + 35392) & 1) == 0);
  if ( (flags & 0x100) != 0 )
    *(_BYTE *)(result + 35393) = (4 * _cntlzw(*(_BYTE *)(result + 35393) & 0x80)) & 0x80
                               | *(_BYTE *)(result + 35393) & 0x7F;
  if ( (flags & 0x200) != 0 )
    *(_BYTE *)(result + 35393) = (8 * ((unsigned int)~*(unsigned __int8 *)(result + 35393) >> 3)) & 8
                               | *(_BYTE *)(result + 35393) & 0xF7;
  if ( (flags & 0x400) != 0 )
    *(_BYTE *)(result + 35393) = (4 * ((unsigned int)~*(unsigned __int8 *)(result + 35393) >> 2)) & 4
                               | *(_BYTE *)(result + 35393) & 0xFB;
  return result;
}


// ========================================================================
// ?AnimEvent_AnimDeltaCorrectionRotationRate@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@MMM@Z
// EA  : 0x82A79B70
// RVA : 0x00A79B70
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm_deltacorrection.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
float *__usercall idAI2::AnimEvent_AnimDeltaCorrectionRotationRate@<r4>(
        idAI2 *this@<r3>,
        float *result@<r4>,
        const idMD6Anim *anim@<r5>,
        double rotationRateMax@<f1>,
        double rotationMinScale@<f2>,
        double rotationMaxScale@<f3>)
{
  result[8847] = rotationRateMax;
  result[8845] = rotationMaxScale;
  result[8846] = rotationMinScale;
  return result;
}


// ========================================================================
// ?GetRemainingFramesToTime@idAnimBaseFSM@@IAAMH@Z
// EA  : 0x82A79B98
// RVA : 0x00A79B98
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm_deltacorrection.cpp
// ========================================================================

float __fastcall idAnimBaseFSM::GetRemainingFramesToTime(idAnimBaseFSM *this, int time)
{
  const idMD6Anim *anim; // r4
  double v4; // fp1
  idMD6LeafPlay *LeafForMD6; // r31
  int v6; // r3
  __int64 v7; // r10
  int v8; // r8
  int v9; // r7
  int v10; // r6
  int v11; // r5
  int v12; // r30
  __int64 v13; // r7
  double v14; // fp31
  __int128 v15; // r5

  anim = this->animDeltaCorrection.anim;
  if ( anim != nullptr
    && (LeafForMD6 = (idMD6LeafPlay *)idAnimWebAI::GetLeafForMD6(
                                        this: this->ai->aiVolatile.animation.animWebAnimator.ptr,
                                        _anim: anim)) != nullptr )
  {
    v6 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
    v12 = time - idMD6LeafPlay::GetFrameTime(this: LeafForMD6, gameTime: v6, a3: v11, a4: v10, a5: v9, a6: v8, a7: v7);
    LODWORD(v13) = idMD6Leaf::GetFrameRate(this: LeafForMD6) * v12;
    HIDWORD(v13) = gameLocal->GetGameMsPerRealSec;
    v14 = (float)v13;
    *(_QWORD *)((char *)&v15 + 4) = ((__int64 (__fastcall *)(idGameLocal *))HIDWORD(v13))(a1: gameLocal);
    LODWORD(v15) = DWORD1(v15);
    v4 = (float)((float)v14 / (float)(__int64)v15);
  }
  else
  {
    v4 = 0.0;
  }
  return *((float *)&v4 + 1);
}


// ========================================================================
// ?ResetAnimDeltaCorrection@idAnimBaseFSM@@QAAXXZ
// EA  : 0x82A79C70
// RVA : 0x00A79C70
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm_deltacorrection.cpp
// ========================================================================

void __fastcall idAnimBaseFSM::ResetAnimDeltaCorrection(idAnimBaseFSM *this)
{
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  char v3; // r10
  char v4; // r9
  char v5; // r7
  idTreeAnimator *v6; // r30
  float *p_deferredAxis; // r11
  float *p_x; // r11
  animDeltaCorrection_t::input_t v9; // [sp+50h] [-50h] BYREF

  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: this->ai);
  v3 = *((_BYTE *)&this->animDeltaCorrection + 72);
  v4 = *((_BYTE *)&this->animDeltaCorrection + 372);
  v5 = *((_BYTE *)&v9 + 41);
  this->animDeltaCorrection.rotationEndTime = 0;
  this->animDeltaCorrection.translationEndTime = 0;
  this->animDeltaCorrection.idealPoint = IDEALPOINT_NONE;
  *((_BYTE *)&this->animDeltaCorrection + 72) = v3 & 0x3F;
  *((_BYTE *)&this->animDeltaCorrection + 372) = v4 & 0xF;
  this->animDeltaCorrection.idealDir = IDEALDIR_NONE;
  v9.translationCorrectionMaxScale = 0.0;
  v9.rotationMaxScale = 0.0;
  v9.rotationMinScale = 0.0;
  v9.rotationRateMax = 0.0;
  v6 = TreeAnimatorFromPresentable;
  *((_BYTE *)&v9 + 40) = 0;
  *((_BYTE *)&v9 + 41) = v5 & 3 | 0x40;
  v9.translationCorrectionPerFrameMax = vec3_origin;
  v9.translationPerFrameMax = vec3_origin;
  animDeltaCorrection_t::input_t::operator=(this: &this->animDeltaCorrection.in, __that: &v9);
  p_deferredAxis = (float *)&v6->deferredAxis;
  if ( !v6->useDeferredPosition )
    p_deferredAxis = (float *)&v6->g.axis;
  this->animDeltaCorrection.uncorrectedAxis.mat[0].x = *p_deferredAxis;
  this->animDeltaCorrection.uncorrectedAxis.mat[0].y = p_deferredAxis[1];
  this->animDeltaCorrection.uncorrectedAxis.mat[0].z = p_deferredAxis[2];
  this->animDeltaCorrection.uncorrectedAxis.mat[1].x = p_deferredAxis[3];
  this->animDeltaCorrection.uncorrectedAxis.mat[1].y = p_deferredAxis[4];
  this->animDeltaCorrection.uncorrectedAxis.mat[1].z = p_deferredAxis[5];
  this->animDeltaCorrection.uncorrectedAxis.mat[2].x = p_deferredAxis[6];
  this->animDeltaCorrection.uncorrectedAxis.mat[2].y = p_deferredAxis[7];
  this->animDeltaCorrection.uncorrectedAxis.mat[2].z = p_deferredAxis[8];
  p_x = &v6->deferredOrigin.x;
  if ( !v6->useDeferredPosition )
    p_x = &v6->g.origin.x;
  this->animDeltaCorrection.startOrigin.x = *p_x;
  this->animDeltaCorrection.startOrigin.y = p_x[1];
  this->animDeltaCorrection.startOrigin.z = p_x[2];
  this->animDeltaCorrection.animSpacePreTranslationCorrection = mat3_identity;
  this->animDeltaCorrection.skipFirstFrame = false;
}


// ========================================================================
// ?BeginAnimDeltaCorrectionRotation@idAnimBaseFSM@@QAAXPBVidMD6Anim@@PBVidDeclAnimWebNode@@W4aiAnimDCIdealDir_t@@HHHPBVidCachedJoint@@3@Z
// EA  : 0x82A79E18
// RVA : 0x00A79E18
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm_deltacorrection.cpp
// ========================================================================

void __fastcall idAnimBaseFSM::BeginAnimDeltaCorrectionRotation(
        idAnimBaseFSM *this,
        const idMD6Anim *anim,
        const idDeclAnimWebNode *node,
        aiAnimDCIdealDir_t idealDir,
        int startFrame,
        int endFrame,
        int goalFrame,
        const idCachedJoint *endJoint,
        const idCachedJoint *goalJoint,
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
        int a28)
{
  idAIStateLite *currentState; // r3
  aiAnimDCIdealDir_t idealDirOverride; // r11
  char v38; // r10
  idAI2 *ai; // r3
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  float *p_x; // r11
  idPhysics *v42; // r3
  float *v43; // r3
  double v44; // fp7
  double v45; // fp6
  idPhysics *Physics; // r3
  float *v47; // r3
  double v48; // fp7
  double v49; // fp6
  double z; // fp12
  idMD6AnimData *animData; // r11
  float *endDelta; // r29
  idMat3 *v53; // r3
  double v54; // fp3
  aiAnimDCIdealDir_t v55; // r11
  idMat3 *v56; // r3
  double v57; // fp3
  idMD6AnimData *v58; // r11
  bool v59; // zf
  float *startDelta; // r30
  idMD6LeafPlay *LeafForMD6; // r30
  int v62; // r28
  signed int FrameRate; // r3
  int v64; // r29
  signed int v65; // r3
  idMat3 v66; // [sp+50h] [-B0h] BYREF
  idMat3 v67[3]; // [sp+80h] [-80h] BYREF

  if ( anim == nullptr )
    return;
  currentState = this->currentState;
  if ( currentState != nullptr && (currentState->GetStateFlags(this: currentState) & 2) != 0 )
    return;
  idealDirOverride = this->animDeltaCorrection.idealDirOverride;
  this->animDeltaCorrection.idealDir = idealDirOverride != IDEALDIR_NONE ? idealDirOverride : idealDir;
  if ( this->animDeltaCorrection.idealDir == IDEALDIR_NOOP )
    return;
  v38 = *((_BYTE *)&this->animDeltaCorrection + 372);
  ai = this->ai;
  *((_BYTE *)&this->animDeltaCorrection + 72) |= 0x80u;
  *((_BYTE *)&this->animDeltaCorrection + 372) = v38 | 0x30;
  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: ai);
  p_x = &TreeAnimatorFromPresentable->deferredOrigin.x;
  if ( !TreeAnimatorFromPresentable->useDeferredPosition )
    p_x = &TreeAnimatorFromPresentable->g.origin.x;
  this->animDeltaCorrection.startOrigin.x = *p_x;
  this->animDeltaCorrection.startOrigin.y = p_x[1];
  this->animDeltaCorrection.startOrigin.z = p_x[2];
  if ( (unsigned int)(this->animDeltaCorrection.idealDir - 1) > 7
    || this->animDeltaCorrection.idealDir == IDEALDIR_BODYORIENTATION )
  {
LABEL_25:
    this->animDeltaCorrection.endDir.x = this->orientBody.idealDir.x;
    this->animDeltaCorrection.endDir.y = this->orientBody.idealDir.y;
    z = this->orientBody.idealDir.z;
    goto LABEL_26;
  }
  if ( this->animDeltaCorrection.idealDir == IDEALDIR_MOVEORIENTATION )
  {
    this->animDeltaCorrection.endDir.x = this->orientMove.idealDir.x;
    this->animDeltaCorrection.endDir.y = this->orientMove.idealDir.y;
    z = this->orientMove.idealDir.z;
LABEL_26:
    this->animDeltaCorrection.endDir.z = z;
    goto LABEL_27;
  }
  if ( this->animDeltaCorrection.idealDir == IDEALDIR_GOALORIENTATION )
  {
    this->animDeltaCorrection.endDir.x = this->nextArrivalAxis.mat[0].x;
    this->animDeltaCorrection.endDir.y = this->nextArrivalAxis.mat[0].y;
    z = this->nextArrivalAxis.mat[0].z;
    goto LABEL_26;
  }
  if ( this->animDeltaCorrection.idealDir != IDEALDIR_TONEXTPOINT )
  {
    if ( this->animDeltaCorrection.idealDir == IDEALDIR_TOGOALPOINT )
    {
      Physics = idEntity::GetPhysics(this: this->ai);
      v47 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
      v48 = (float)(this->navNextPos.y - v47[1]);
      v49 = (float)(this->navNextPos.z - v47[2]);
      this->animDeltaCorrection.endDir.x = this->navNextPos.x - *v47;
      this->animDeltaCorrection.endDir.y = v48;
      this->animDeltaCorrection.endDir.z = v49;
      goto LABEL_27;
    }
    if ( this->animDeltaCorrection.idealDir != IDEALDIR_TOENEMY )
    {
      if ( this->animDeltaCorrection.idealDir == IDEALDIR_CURRENT_ANIMNODE )
      {
        this->animDeltaCorrection.endDir.x = this->animDeltaCorrection.currentAnimnodeAxis.mat[0].x;
        this->animDeltaCorrection.endDir.y = this->animDeltaCorrection.currentAnimnodeAxis.mat[0].y;
        z = this->animDeltaCorrection.currentAnimnodeAxis.mat[0].z;
      }
      else
      {
        this->animDeltaCorrection.endDir.x = this->animDeltaCorrection.currentRefAxis.mat[0].x;
        this->animDeltaCorrection.endDir.y = this->animDeltaCorrection.currentRefAxis.mat[0].y;
        z = this->animDeltaCorrection.currentRefAxis.mat[0].z;
      }
      goto LABEL_26;
    }
    goto LABEL_25;
  }
  v42 = idEntity::GetPhysics(this: this->ai);
  v43 = (float *)v42->GetOrigin(this: v42, a2: 0);
  v44 = (float)(this->navNextPos.y - v43[1]);
  v45 = (float)(this->navNextPos.z - v43[2]);
  this->animDeltaCorrection.endDir.x = this->navNextPos.x - *v43;
  this->animDeltaCorrection.endDir.y = v44;
  this->animDeltaCorrection.endDir.z = v45;
  if ( ((LODWORD(this->animDeltaCorrection.endDir.z)
       | LODWORD(this->animDeltaCorrection.endDir.y)
       | LODWORD(this->animDeltaCorrection.endDir.x))
      & 0x7FFFFFFF) == 0 )
  {
    this->animDeltaCorrection.endDir.x = this->orientBody.axis.mat[0].x;
    this->animDeltaCorrection.endDir.y = this->orientBody.axis.mat[0].y;
    this->animDeltaCorrection.endDir.z = this->orientBody.axis.mat[0].z;
  }
LABEL_27:
  animData = anim->animData;
  endDelta = nullptr;
  if ( animData != nullptr )
    endDelta = animData->endDelta;
  if ( endFrame > -1 && endJoint != nullptr )
  {
    v53 = idQuat::ToMat3(this: (idQuat *)&v66, result: (idMat3 *)&endJoint->rot);
    this->animDeltaCorrection.animSpaceEndRotation = *idMat3::Inverse(this: v67, result: v53);
    this->animDeltaCorrection.animSpaceEndRotation_Translation.x = endJoint->trans.x;
    this->animDeltaCorrection.animSpaceEndRotation_Translation.y = endJoint->trans.y;
    v54 = endJoint->trans.z;
  }
  else
  {
    endFrame = 0;
    if ( animData != nullptr )
      endFrame = animData->numFrames;
    this->animDeltaCorrection.animSpaceEndRotation = *idQuat::ToMat3(this: (idQuat *)v67, result: (idMat3 *)endDelta);
    this->animDeltaCorrection.animSpaceEndRotation_Translation.x = endDelta[8];
    this->animDeltaCorrection.animSpaceEndRotation_Translation.y = endDelta[9];
    v54 = endDelta[10];
  }
  this->animDeltaCorrection.animSpaceEndRotation_Translation.z = v54;
  v55 = this->animDeltaCorrection.idealDir;
  if ( v55 == IDEALDIR_DEPARTURE_PATH_DIRECTION )
  {
    this->animDeltaCorrection.animSpaceGoalRotation = *idQuat::ToMat3(this: (idQuat *)v67, result: (idMat3 *)endDelta);
    if ( goalFrame > -1 && a28 != 0 )
    {
      this->animDeltaCorrection.animSpaceGoalRotation_Translation.x = *(float *)(a28 + 4);
      this->animDeltaCorrection.animSpaceGoalRotation_Translation.y = *(float *)(a28 + 8);
      this->animDeltaCorrection.animSpaceGoalRotation_Translation.z = *(float *)(a28 + 12);
    }
    else
    {
      goalFrame = endFrame;
      this->animDeltaCorrection.animSpaceGoalRotation_Translation.x = this->animDeltaCorrection.animSpaceEndRotation_Translation.x;
      this->animDeltaCorrection.animSpaceGoalRotation_Translation.y = this->animDeltaCorrection.animSpaceEndRotation_Translation.y;
      this->animDeltaCorrection.animSpaceGoalRotation_Translation.z = this->animDeltaCorrection.animSpaceEndRotation_Translation.z;
    }
  }
  else
  {
    if ( goalFrame > -1 && a28 != 0 )
    {
      v56 = idQuat::ToMat3(this: (idQuat *)v67, result: (idMat3 *)(a28 + 16));
      this->animDeltaCorrection.animSpaceGoalRotation = *idMat3::Inverse(this: &v66, result: v56);
      this->animDeltaCorrection.animSpaceGoalRotation_Translation.x = *(float *)(a28 + 4);
      this->animDeltaCorrection.animSpaceGoalRotation_Translation.y = *(float *)(a28 + 8);
      v57 = *(float *)(a28 + 12);
    }
    else
    {
      goalFrame = 0;
      v59 = v55 != IDEALDIR_CURRENT_ANIMNODE;
      v58 = anim->animData;
      if ( !v59 )
      {
        startDelta = nullptr;
        if ( v58 != nullptr )
          startDelta = v58->startDelta;
        this->animDeltaCorrection.animSpaceGoalRotation = *idQuat::ToMat3(
                                                             this: (idQuat *)v67,
                                                             result: (idMat3 *)startDelta);
        this->animDeltaCorrection.animSpaceGoalRotation_Translation.x = startDelta[8];
        this->animDeltaCorrection.animSpaceGoalRotation_Translation.y = startDelta[9];
        this->animDeltaCorrection.animSpaceGoalRotation_Translation.z = startDelta[10];
        goto LABEL_51;
      }
      if ( v58 != nullptr )
        goalFrame = v58->numFrames;
      this->animDeltaCorrection.animSpaceGoalRotation = *idQuat::ToMat3(this: (idQuat *)v67, result: (idMat3 *)endDelta);
      this->animDeltaCorrection.animSpaceGoalRotation_Translation.x = endDelta[8];
      this->animDeltaCorrection.animSpaceGoalRotation_Translation.y = endDelta[9];
      v57 = endDelta[10];
    }
    this->animDeltaCorrection.animSpaceGoalRotation_Translation.z = v57;
  }
LABEL_51:
  if ( goalFrame < endFrame )
    *((_BYTE *)&this->animDeltaCorrection + 372) |= 0x40u;
  this->animDeltaCorrection.anim = anim;
  this->animDeltaCorrection.node = node;
  LeafForMD6 = (idMD6LeafPlay *)idAnimWebAI::GetLeafForMD6(
                                  this: this->ai->aiVolatile.animation.animWebAnimator.ptr,
                                  _anim: anim);
  if ( LeafForMD6 != nullptr )
  {
    v62 = gameLocal->GetGameMsPerRealSec(this: gameLocal) * endFrame;
    FrameRate = idMD6Leaf::GetFrameRate(this: LeafForMD6);
    this->animDeltaCorrection.rotationEndTime = v62 / FrameRate;
    __twllei(FrameRate, 0);
    __twlgei(FrameRate & ~(__ROL4__(v62, 1) - 1), 0xFFFFFFFF);
    v64 = gameLocal->GetGameMsPerRealSec(this: gameLocal) * goalFrame;
    v65 = idMD6Leaf::GetFrameRate(this: LeafForMD6);
    __twllei(v65, 0);
    this->animDeltaCorrection.rotationGoalTime = v64 / v65;
    __twlgei(v65 & ~(__ROL4__(v64, 1) - 1), 0xFFFFFFFF);
  }
  else
  {
    this->animDeltaCorrection.rotationEndTime = 0;
    this->animDeltaCorrection.rotationGoalTime = 0;
  }
  this->animDeltaCorrection.previousRemainingRotationFrames = idAnimBaseFSM::GetRemainingFramesToTime(
                                                                this,
                                                                time: this->animDeltaCorrection.rotationEndTime);
  this->animDeltaCorrection.previousRemainingRotationFramesToGoal = idAnimBaseFSM::GetRemainingFramesToTime(
                                                                      this,
                                                                      time: this->animDeltaCorrection.rotationGoalTime);
  if ( startFrame == 0 )
    this->animDeltaCorrection.skipFirstFrame = true;
}


// ========================================================================
// ?GetDeltaCorrectionGoalOrigin@idAnimBaseFSM@@IBA?AVidVec3@@XZ
// EA  : 0x82A7A4E8
// RVA : 0x00A7A4E8
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm_deltacorrection.cpp
// ========================================================================

idAnimBaseFSM *__fastcall idAnimBaseFSM::GetDeltaCorrectionGoalOrigin(idAnimBaseFSM *this, idVec3 *result)
{
  float z; // r11
  idAnimBaseFSM *v3; // r31
  double x; // fp0
  double y; // fp13
  double v7; // fp12
  int v8; // r6
  idEntity *v9; // r3
  float v10; // r3
  idPhysics *Physics; // r3
  float *v12; // r3

  z = result[13].z;
  v3 = this;
  if ( LODWORD(z) == 4 )
    goto LABEL_10;
  if ( LODWORD(z) != 5 )
  {
    if ( LODWORD(z) != 7 )
    {
      x = result[3].x;
      y = result[3].y;
      v7 = result[3].z;
      goto LABEL_11;
    }
LABEL_10:
    v7 = result[30].z;
    y = result[30].y;
    x = result[30].x;
    goto LABEL_11;
  }
  v8 = *(_DWORD *)(LODWORD(result[1].x) + 58000);
  if ( gameLocal->spawnIds.ptr[v8 & 0x1FFF] != v8 >> 13
    || (v9 = gameLocal->entities.ptr[v8 & 0x1FFF]) == nullptr
    || (v10 = COERCE_FLOAT(idEntity::CastTo(c: v9))) == 0.0 )
  {
    v10 = result[1].x;
  }
  Physics = idEntity::GetPhysics(this: (idEntity *)LODWORD(v10));
  v12 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
  x = *v12;
  y = v12[1];
  v7 = v12[2];
  this = v3;
LABEL_11:
  *(float *)&v3->idAIFSMLite::idEventReceiver::idClass::__vftable = x;
  *(float *)&v3->listenerList = y;
  *(float *)&v3->listeningToList = v7;
  return this;
}


// ========================================================================
// ?GetDeltaCorrectionGoalRotation@idAnimBaseFSM@@IBA?AVidMat3@@PBUdeltaCorrectionGoalRotationParms_t@1@@Z
// EA  : 0x82A7A5F0
// RVA : 0x00A7A5F0
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm_deltacorrection.cpp
// ========================================================================

idAnimBaseFSM *__fastcall idAnimBaseFSM::GetDeltaCorrectionGoalRotation(
        idAnimBaseFSM *this,
        idAnimBaseFSM *result,
        const idAnimBaseFSM::deltaCorrectionGoalRotationParms_t *parms)
{
  idAnimBaseFSM *p_z; // r11
  idAnimBaseFSM *v7; // r10
  int i; // ctr
  idPhysics *Physics; // r3
  idMat3 *p_orientBody; // r4
  idVec3 *v11; // r3
  idPhysics *v12; // r3
  float *v13; // r3
  double v14; // fp7
  double v15; // fp6
  double y; // fp13
  double z; // fp12
  float v18; // r3
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  double v20; // fp31
  __int64 v21; // r4
  __int64 v22; // r10
  idEntity *Enemy; // r3
  idPhysics *v25; // r3
  idPhysics *v26; // r3
  int v27; // r3
  float *v28; // r10
  _DWORD *v29; // r11
  int j; // ctr
  double v31; // fp12
  double v32; // fp11
  double v33; // fp10
  double v34; // fp9
  double v35; // fp8
  double v36; // fp7
  double v37; // fp6
  idVec3 *p_worldSpaceAnimGoalOrigin; // r29
  double DistanceToPath; // fp1
  int v40; // r3
  idRenderWorld *v41; // r3
  double x; // fp10
  double v43; // fp9
  idRenderWorld *v44; // r3
  idMat3 v45; // [sp+50h] [-210h] BYREF
  float v46; // [sp+74h] [-1ECh]
  float v47; // [sp+78h] [-1E8h]
  float v48[4]; // [sp+80h] [-1E0h] BYREF
  float v49[3]; // [sp+90h] [-1D0h] BYREF
  float v50[11]; // [sp+9Ch] [-1C4h] BYREF
  __int64 v51; // [sp+C8h] [-198h]
  idVec3 v52; // [sp+D0h] [-190h] BYREF
  idVec3 v53[4]; // [sp+E0h] [-180h] BYREF
  char v54; // [sp+110h] [-150h] BYREF
  char v55; // [sp+140h] [-120h] BYREF
  char v56; // [sp+170h] [-F0h] BYREF
  char v57; // [sp+1A0h] [-C0h] BYREF
  char v58; // [sp+1D0h] [-90h] BYREF
  char v59; // [sp+200h] [-60h] BYREF

  p_z = (idAnimBaseFSM *)&result->orientBody.idealDir.z;
  v7 = (idAnimBaseFSM *)((char *)this - 4);
  for ( i = 9; i != 0; --i )
  {
    p_z = (idAnimBaseFSM *)((char *)p_z + 4);
    v7 = (idAnimBaseFSM *)((char *)v7 + 4);
    v7->idAIFSMLite::idEventReceiver::idClass::__vftable = p_z->idAIFSMLite::idEventReceiver::idClass::__vftable;
  }
  if ( (*((_BYTE *)&result->animDeltaCorrection.in + 41) & 8) == 0 )
  {
    Physics = idEntity::GetPhysics(this: result->ai);
    Physics->GetOrigin(this: Physics, a2: 0);
  }
  switch ( result->animDeltaCorrection.idealDir )
  {
    case IDEALDIR_BODYORIENTATION:
      p_orientBody = (idMat3 *)&result->orientBody;
      v11 = (idVec3 *)&v56;
      goto LABEL_25;
    case IDEALDIR_MOVEORIENTATION:
      p_orientBody = (idMat3 *)&result->orientMove;
      v11 = (idVec3 *)&v58;
      goto LABEL_25;
    case IDEALDIR_TONEXTPOINT:
      if ( result->cachedCorners.num <= 0 )
      {
        y = result->orientMove.idealDir.y;
        z = result->orientMove.idealDir.z;
        v45.mat[0].x = result->orientMove.idealDir.x;
        v45.mat[0].y = y;
        v45.mat[0].z = z;
      }
      else
      {
        v12 = idEntity::GetPhysics(this: result->ai);
        v13 = (float *)v12->GetOrigin(this: v12, a2: 0);
        v14 = (float)(result->navNextPos.y - v13[1]);
        v15 = (float)(result->navNextPos.z - v13[2]);
        v45.mat[0].x = result->navNextPos.x - *v13;
        v45.mat[0].y = v14;
        v45.mat[0].z = v15;
        idVec3::NormalizeFast(this: v45.mat);
      }
      v18 = *(float *)&result->ai;
      *(idVec3 *)&v45.mat[1].y = vec3_origin;
      TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: (idAnimatedEntity *)LODWORD(v18));
      idTreeAnimator::GetLastOriginDeltas(this: TreeAnimatorFromPresentable, trans: (idVec3 *)&v45.mat[1].y);
      v20 = (float)((float)(v45.mat[1].y * v45.mat[1].y)
                  + (float)((float)(v45.mat[1].z * v45.mat[1].z) + (float)(v45.mat[2].x * v45.mat[2].x)));
      v21 = ((__int64 (__fastcall *)(idGameLocal *, int))gameLocal->GetGameHz)(a1: gameLocal, a2: 1);
      LODWORD(v22) = HIDWORD(v21);
      HIDWORD(v22) = result->idAIFSMLite::idEventReceiver::idClass::__vftable;
      v51 = v22;
      (*(void (__fastcall **)(idAnimBaseFSM *, _DWORD, idMat3 *, double))(HIDWORD(v22) + 148))(
        a1: result,
        a2: v21,
        a3: &v45,
        a4: (float)((float)v22 * (float)__fsqrts(v20)));
      *(idMat3 *)&this->idAIFSMLite::idEventReceiver::idClass::__vftable = *idVec3::ToMat3(this: v53, result: &v45);
      return this;
    case IDEALDIR_TOENEMY:
      Enemy = (idEntity *)idAIMemory::GetEnemy(this: &result->ai->aiVolatile.memory);
      if ( Enemy != nullptr )
      {
        v25 = idEntity::GetPhysics(this: Enemy);
        v25->GetOrigin(this: v25, a2: 0);
        v26 = idEntity::GetPhysics(this: result->ai);
        v27 = (int)v26->GetAxis(this: v26, a2: 0);
        v28 = v50;
        v29 = (_DWORD *)(v27 - 4);
        for ( j = 9; j != 0; --j )
          *++v28 = *(float *)++v29;
        *(float *)&this->idAIFSMLite::idEventReceiver::idClass::__vftable = v50[1];
        v31 = v50[2];
        v32 = v50[3];
        *(float *)&this->ai = v50[4];
        v33 = v50[5];
        *(float *)&this->listenerList = v31;
        *(float *)&this->listeningToList = v32;
        v34 = v50[6];
        *(float *)&this->defaultState = v33;
        v35 = v50[7];
        *(float *)&this->currentState = v34;
        v36 = v50[8];
        *(float *)&this->stateStartTime = v35;
        v37 = v50[9];
        *(float *)&this->currentlyUpdating = v36;
        *(float *)&this->idAIMoveInterface::__vftable = v37;
        return this;
      }
      else
      {
        v11 = (idVec3 *)&v54;
LABEL_24:
        p_orientBody = (idMat3 *)&result->animDeltaCorrection.endDir;
LABEL_25:
        *(idMat3 *)&this->idAIFSMLite::idEventReceiver::idClass::__vftable = *idVec3::ToMat3(
                                                                                this: v11,
                                                                                result: p_orientBody);
        return this;
      }
    case IDEALDIR_CURRENT_REF_AXIS:
      *(float *)&this->idAIFSMLite::idEventReceiver::idClass::__vftable = result->animDeltaCorrection.currentRefAxis.mat[0].x;
      *(float *)&this->listenerList = result->animDeltaCorrection.currentRefAxis.mat[0].y;
      *(float *)&this->listeningToList = result->animDeltaCorrection.currentRefAxis.mat[0].z;
      *(float *)&this->ai = result->animDeltaCorrection.currentRefAxis.mat[1].x;
      *(float *)&this->defaultState = result->animDeltaCorrection.currentRefAxis.mat[1].y;
      *(float *)&this->currentState = result->animDeltaCorrection.currentRefAxis.mat[1].z;
      *(float *)&this->stateStartTime = result->animDeltaCorrection.currentRefAxis.mat[2].x;
      *(float *)&this->currentlyUpdating = result->animDeltaCorrection.currentRefAxis.mat[2].y;
      *(float *)&this->idAIMoveInterface::__vftable = result->animDeltaCorrection.currentRefAxis.mat[2].z;
      return this;
    case IDEALDIR_DEPARTURE_PATH_DIRECTION:
      if ( parms != nullptr )
      {
        p_worldSpaceAnimGoalOrigin = &parms->worldSpaceAnimGoalOrigin;
        DistanceToPath = idAnimBaseFSM::GetDistanceToPath(
                           this: result,
                           startOrigin: &parms->sourcePosition,
                           testPoint: &parms->worldSpaceAnimGoalOrigin,
                           outPositionOnPath: (idVec3 *)&v45.mat[2].z,
                           outDirectionOnPath: &v52);
        if ( parms->debug )
        {
          v40 = ((int (__fastcall *)(idGameLocal *, double))gameLocal->GetRenderWorld)(
                  a1: gameLocal,
                  a2: DistanceToPath);
          v49[0] = v45.mat[2].z;
          v49[1] = v46;
          v49[2] = v47;
          v50[0] = 3.0;
          (*(void (__fastcall **)(int, idColor *, float *, int, int, _DWORD))(*(_DWORD *)v40 + 216))(
            a1: v40,
            a2: &idColor::colorGreen,
            a3: v49,
            a4: 12,
            a5: 1,
            a6: 0);
          v41 = gameLocal->GetRenderWorld(this: gameLocal);
          x = p_worldSpaceAnimGoalOrigin->x;
          v43 = parms->worldSpaceAnimGoalOrigin.y;
          v48[2] = parms->worldSpaceAnimGoalOrigin.z;
          v48[0] = x;
          v48[1] = v43;
          v48[3] = 3.0;
          v41->DebugSphere(
            this: v41,
            a2: (const idVec4 *)&idColor::colorBlue,
            a3: (const idSphere *)v48,
            a4: 12,
            a5: 1,
            a6: false);
          v44 = gameLocal->GetRenderWorld(this: gameLocal);
          v44->DebugLine(
            this: v44,
            a2: (const idVec4 *)&idColor::colorGreen,
            a3: p_worldSpaceAnimGoalOrigin,
            a4: (const idVec3 *)&v45.mat[2].z,
            a5: 1,
            a6: false);
        }
        p_orientBody = (idMat3 *)&v52;
        v11 = (idVec3 *)&v55;
      }
      else
      {
        p_orientBody = (idMat3 *)&result->orientMove;
        v11 = (idVec3 *)&v57;
      }
      goto LABEL_25;
    default:
      v11 = (idVec3 *)&v59;
      goto LABEL_24;
  }
}


// ========================================================================
// ?CheckResetAnimDeltaCorrection@idAnimBaseFSM@@QAAXPBVidDeclAnimWebNode@@@Z
// EA  : 0x82A7AB00
// RVA : 0x00A7AB00
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm_deltacorrection.cpp
// ========================================================================

void __fastcall idAnimBaseFSM::CheckResetAnimDeltaCorrection(idAnimBaseFSM *this, const idDeclAnimWebNode *node)
{
  if ( (*((_BYTE *)&this->animDeltaCorrection + 72) & 0x80) == 0
    && (*((_BYTE *)&this->animDeltaCorrection + 72) & 0x40) == 0
    || this->animDeltaCorrection.node == node )
  {
    idAnimBaseFSM::ResetAnimDeltaCorrection(this);
  }
}


// ========================================================================
// ?BeginAnimDeltaCorrectionTranslation@idAnimBaseFSM@@QAAXPBVidMD6Anim@@PBVidDeclAnimWebNode@@W4aiAnimDCIdealPoint_t@@HHHPBVidCachedJoint@@3_N@Z
// EA  : 0x82A7AB30
// RVA : 0x00A7AB30
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm_deltacorrection.cpp
// ========================================================================

void __fastcall idAnimBaseFSM::BeginAnimDeltaCorrectionTranslation(
        idAnimBaseFSM *this,
        const idMD6Anim *anim,
        const idDeclAnimWebNode *node,
        aiAnimDCIdealPoint_t idealPoint,
        int startFrame,
        int endFrame,
        int goalFrame,
        const idCachedJoint *endJoint,
        const idCachedJoint *goalJoint,
        bool correctGravity,
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
        float *a28)
{
  idAIStateLite *currentState; // r3
  aiAnimDCIdealPoint_t idealPointOverride; // r11
  char v38; // r10
  idAI2 *ai; // r3
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idMD6AnimData *animData; // r11
  idTreeAnimator *v42; // r24
  float *endDelta; // r10
  double z; // fp12
  double v45; // fp12
  idMD6AnimData *v46; // r11
  float *startDelta; // r11
  idMD6LeafPlay *LeafForMD6; // r30
  int v49; // r29
  signed int FrameRate; // r3
  idPhysics *Physics; // r3
  float *v52; // r3
  double v53; // fp7
  double v54; // fp6
  idTreeAnimator *v55; // r3
  float *p_deferredAxis; // r11
  double x; // fp12
  float v58; // r9
  float v59; // r10
  double v60; // fp5
  char v61; // r10
  float *p_axis; // r11
  double v63; // fp12
  double v64; // fp9
  idContents *p_clipMask; // r3
  double v66; // fp13
  int v67; // r30
  idPhysics *v68; // r3
  idMat3 *v69; // r3
  double fraction; // fp13
  double y; // fp11
  double v72; // fp10
  double v73; // fp13
  double v74; // fp12
  idAI2 *Enemy; // r3
  idPhysics *v76; // r3
  idVec3 *v77; // r3
  idAI2 *v78; // r3
  idPhysics *v79; // r3
  float *v80; // r3
  double v81; // fp31
  double v82; // fp30
  double v83; // fp29
  idPhysics *v84; // r3
  float *v85; // r3
  double v86; // fp5
  double v87; // fp4
  idNpCornerInfo *list; // r10
  int v89; // [sp+8h] [-1A8h]
  bool v90; // [sp+Fh] [-1A1h]
  const char *v91; // [sp+10h] [-1A0h]
  int v92; // [sp+14h] [-19Ch]
  int v93; // [sp+18h] [-198h]
  int v94; // [sp+1Ch] [-194h]
  int v95; // [sp+20h] [-190h]
  int v96; // [sp+24h] [-18Ch]
  int v97; // [sp+28h] [-188h]
  int v98; // [sp+2Ch] [-184h]
  int v99; // [sp+30h] [-180h]
  int v100; // [sp+34h] [-17Ch]
  int v101; // [sp+38h] [-178h]
  int v102; // [sp+3Ch] [-174h]
  int v103; // [sp+40h] [-170h]
  int v104; // [sp+44h] [-16Ch]
  int v105; // [sp+48h] [-168h]
  int v106; // [sp+4Ch] [-164h]
  int v107; // [sp+50h] [-160h]
  int v108; // [sp+58h] [-158h]
  int v109; // [sp+60h] [-150h]
  idVec3 v110; // [sp+70h] [-140h] BYREF
  idVec3 v111; // [sp+80h] [-130h] BYREF
  idVec3 v112; // [sp+90h] [-120h] BYREF
  float v113[4]; // [sp+A0h] [-110h] BYREF
  idVec3 v114; // [sp+B0h] [-100h] BYREF
  trace_t v115; // [sp+C0h] [-F0h] BYREF

  if ( anim == nullptr )
    return;
  currentState = this->currentState;
  if ( currentState != nullptr && (currentState->GetStateFlags(this: currentState) & 2) != 0 )
    return;
  idealPointOverride = this->animDeltaCorrection.idealPointOverride;
  this->animDeltaCorrection.idealPoint = idealPointOverride != IDEALPOINT_NONE ? idealPointOverride : idealPoint;
  if ( this->animDeltaCorrection.idealPoint == IDEALPOINT_NOOP )
    return;
  v38 = *((_BYTE *)&this->animDeltaCorrection + 372);
  ai = this->ai;
  *((_BYTE *)&this->animDeltaCorrection + 72) |= 0x40u;
  *((_BYTE *)&this->animDeltaCorrection + 372) = v38 | 0x30;
  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: ai);
  animData = anim->animData;
  v42 = TreeAnimatorFromPresentable;
  endDelta = nullptr;
  if ( animData != nullptr )
    endDelta = animData->endDelta;
  if ( endFrame > -1 && endJoint != nullptr )
  {
    this->animDeltaCorrection.animSpaceEndTranslation.x = endJoint->trans.x;
    this->animDeltaCorrection.animSpaceEndTranslation.y = endJoint->trans.y;
    z = endJoint->trans.z;
  }
  else
  {
    endFrame = 0;
    if ( animData != nullptr )
      endFrame = animData->numFrames;
    this->animDeltaCorrection.animSpaceEndTranslation.x = endDelta[8];
    this->animDeltaCorrection.animSpaceEndTranslation.y = endDelta[9];
    z = endDelta[10];
  }
  this->animDeltaCorrection.animSpaceEndTranslation.z = z;
  if ( goalFrame > -1 && a28 != nullptr )
  {
    this->animDeltaCorrection.animSpaceGoalTranslation.x = a28[1];
    this->animDeltaCorrection.animSpaceGoalTranslation.y = a28[2];
    v45 = a28[3];
LABEL_27:
    this->animDeltaCorrection.animSpaceGoalTranslation.z = v45;
    goto LABEL_28;
  }
  goalFrame = 0;
  v46 = anim->animData;
  if ( this->animDeltaCorrection.idealPoint != IDEALPOINT_CURRENT_ANIMNODE )
  {
    if ( v46 != nullptr )
      goalFrame = v46->numFrames;
    this->animDeltaCorrection.animSpaceGoalTranslation.x = endDelta[8];
    this->animDeltaCorrection.animSpaceGoalTranslation.y = endDelta[9];
    v45 = endDelta[10];
    goto LABEL_27;
  }
  if ( v46 != nullptr )
    startDelta = v46->startDelta;
  else
    startDelta = nullptr;
  this->animDeltaCorrection.animSpaceGoalTranslation.x = startDelta[8];
  this->animDeltaCorrection.animSpaceGoalTranslation.y = startDelta[9];
  this->animDeltaCorrection.animSpaceGoalTranslation.z = startDelta[10];
LABEL_28:
  if ( goalFrame < endFrame )
    *((_BYTE *)&this->animDeltaCorrection + 372) |= 0x80u;
  this->animDeltaCorrection.anim = anim;
  this->animDeltaCorrection.node = node;
  LeafForMD6 = (idMD6LeafPlay *)idAnimWebAI::GetLeafForMD6(
                                  this: this->ai->aiVolatile.animation.animWebAnimator.ptr,
                                  _anim: anim);
  if ( LeafForMD6 != nullptr )
  {
    v49 = gameLocal->GetGameMsPerRealSec(this: gameLocal) * endFrame;
    FrameRate = idMD6Leaf::GetFrameRate(this: LeafForMD6);
    __twllei(FrameRate, 0);
    this->animDeltaCorrection.translationEndTime = v49 / FrameRate;
    __twlgei(FrameRate & ~(__ROL4__(v49, 1) - 1), 0xFFFFFFFF);
  }
  else
  {
    this->animDeltaCorrection.translationEndTime = 0;
  }
  this->animDeltaCorrection.previousRemainingTranslationFrames = idAnimBaseFSM::GetRemainingFramesToTime(
                                                                   this,
                                                                   time: this->animDeltaCorrection.translationEndTime);
  if ( startFrame == 0 )
    this->animDeltaCorrection.skipFirstFrame = true;
  idAnimBaseFSM::GetDeltaCorrectionGoalOrigin(this: (idAnimBaseFSM *)v113, result: (idVec3 *)this);
  Physics = idEntity::GetPhysics(this: this->ai);
  v52 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
  v53 = (float)(v113[1] - v52[1]);
  v54 = (float)(v113[2] - v52[2]);
  v110.x = v113[0] - *v52;
  v110.y = v53;
  v110.z = v54;
  idVec3::NormalizeFast(this: &v110);
  v55 = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: this->ai);
  p_deferredAxis = (float *)&v55->deferredAxis;
  if ( !v55->useDeferredPosition )
    p_deferredAxis = (float *)&v55->g.axis;
  x = v110.x;
  v58 = p_deferredAxis[1];
  v59 = p_deferredAxis[2];
  v110.x = *p_deferredAxis;
  v60 = (float)((float)(v58 * v110.y) + (float)((float)(v110.x * (float)x) + (float)(v59 * v110.z)));
  v110.y = v58;
  v110.z = v59;
  if ( v60 <= 0.94999999 )
    v61 = *((_BYTE *)&this->animDeltaCorrection + 112) & 0x7F;
  else
    v61 = *((_BYTE *)&this->animDeltaCorrection + 112) | 0x80;
  *((_BYTE *)&this->animDeltaCorrection + 112) = v61;
  p_axis = (float *)&v42->deferredAxis;
  if ( !v42->useDeferredPosition )
    p_axis = (float *)&v42->g.axis;
  this->animDeltaCorrection.uncorrectedAxis.mat[0].x = *p_axis;
  this->animDeltaCorrection.uncorrectedAxis.mat[0].y = p_axis[1];
  this->animDeltaCorrection.uncorrectedAxis.mat[0].z = p_axis[2];
  this->animDeltaCorrection.uncorrectedAxis.mat[1].x = p_axis[3];
  this->animDeltaCorrection.uncorrectedAxis.mat[1].y = p_axis[4];
  this->animDeltaCorrection.uncorrectedAxis.mat[1].z = p_axis[5];
  this->animDeltaCorrection.uncorrectedAxis.mat[2].x = p_axis[6];
  this->animDeltaCorrection.uncorrectedAxis.mat[2].y = p_axis[7];
  this->animDeltaCorrection.uncorrectedAxis.mat[2].z = p_axis[8];
  if ( (unsigned int)(this->animDeltaCorrection.idealPoint - 1) > 8 )
  {
LABEL_61:
    Enemy = this->ai;
LABEL_62:
    v76 = idEntity::GetPhysics(this: Enemy);
    v77 = (idVec3 *)v76->GetOrigin(this: v76, a2: 0);
    goto LABEL_63;
  }
  switch ( this->animDeltaCorrection.idealPoint )
  {
    case IDEALPOINT_NEXTPOINT:
      this->animDeltaCorrection.endPoint.x = this->navNextPos.x;
      this->animDeltaCorrection.endPoint.y = this->navNextPos.y;
      v63 = this->navNextPos.z;
LABEL_64:
      this->animDeltaCorrection.endPoint.z = v63;
      return;
    case IDEALPOINT_CURRENT_ANIMNODE:
      this->animDeltaCorrection.endPoint.x = this->animDeltaCorrection.currentAnimnodeOrigin.x;
      this->animDeltaCorrection.endPoint.y = this->animDeltaCorrection.currentAnimnodeOrigin.y;
      v63 = this->animDeltaCorrection.currentAnimnodeOrigin.z;
      goto LABEL_64;
    case IDEALPOINT_CURRENT_REF_PT:
      this->animDeltaCorrection.endPoint.x = this->animDeltaCorrection.currentRefOrigin.x;
      this->animDeltaCorrection.endPoint.y = this->animDeltaCorrection.currentRefOrigin.y;
      v63 = this->animDeltaCorrection.currentRefOrigin.z;
      goto LABEL_64;
    case IDEALPOINT_ENEMYORIGIN:
      Enemy = (idAI2 *)idAIMemory::GetEnemy(this: &this->ai->aiVolatile.memory);
      if ( Enemy != nullptr )
        goto LABEL_62;
      goto LABEL_61;
    case IDEALPOINT_NEXTGROUNDPOINT:
      v64 = this->intermediateMove.destPos.z;
      p_clipMask = &this->ai->aiConstants.physics.clipMask;
      v66 = (float)(this->intermediateMove.destPos.y + (float)(vec3_up.y * (float)32.0));
      v114.x = this->intermediateMove.destPos.x + (float)(vec3_up.x * (float)32.0);
      v114.y = v66;
      v114.z = (float)v64 + (float)(vec3_up.z * (float)32.0);
      v112.x = (float)(vec3_down.x * (float)1024.0) + v114.x;
      v112.y = (float)(vec3_down.y * (float)1024.0) + (float)v66;
      v112.z = (float)(vec3_down.z * (float)1024.0) + v114.z;
      v67 = idContents::ToFlags(this: p_clipMask);
      v68 = idEntity::GetPhysics(this: this->ai);
      v69 = (idMat3 *)v68->GetAxis(this: v68, a2: 0);
      idClip::Translation(
        this: (idClip *)&v110,
        result: &clientGame->clip,
        a3: &v115,
        start: &v114,
        end: &v112,
        clipModel: nullptr,
        startAxis: v69,
        clipMask: v67,
        passEntityNumber: v89,
        moveClipModel: v90,
        userName: v91,
        a12: v92,
        a13: v93,
        a14: v94,
        a15: v95,
        a16: v96,
        a17: v97,
        a18: v98,
        a19: v99,
        a20: v100,
        a21: v101,
        a22: v102,
        a23: v103,
        a24: v104,
        a25: v105,
        a26: v106,
        a27: v107,
        a28: 0x1FFF,
        a29: v108,
        a30: false,
        a31: v109,
        a32: (int)"w:\\tech5\\tungsten\\game\\ai\\animfsm\\AnimFSM_DeltaCorrection.cpp(406) : deltaCorrectGround");
      fraction = v115.fraction;
      y = v112.y;
      v72 = v112.z;
      this->animDeltaCorrection.endPoint.x = v112.x;
      this->animDeltaCorrection.endPoint.y = y;
      this->animDeltaCorrection.endPoint.z = v72;
      if ( fraction < 1.0 )
      {
        v73 = v115.endpos.y;
        v74 = v115.endpos.z;
        this->animDeltaCorrection.endPoint.x = v115.endpos.x;
        this->animDeltaCorrection.endPoint.y = v73;
        this->animDeltaCorrection.endPoint.z = v74;
      }
      return;
    default:
      break;
  }
  if ( this->animDeltaCorrection.idealPoint != IDEALPOINT_FLIGHT_ANIM )
  {
    if ( this->animDeltaCorrection.idealPoint != IDEALPOINT_PATH_POINT )
    {
      if ( this->animDeltaCorrection.idealPoint == IDEALPOINT_GOALPOINT )
      {
        this->animDeltaCorrection.endPoint.x = this->nextArrivalPos.x;
        this->animDeltaCorrection.endPoint.y = this->nextArrivalPos.y;
        v63 = this->nextArrivalPos.z;
        goto LABEL_64;
      }
      v77 = this->GetTraversalEndpoint(this: v113, result: this);
LABEL_63:
      this->animDeltaCorrection.endPoint.x = v77->x;
      this->animDeltaCorrection.endPoint.y = v77->y;
      v63 = v77->z;
      goto LABEL_64;
    }
    goto LABEL_61;
  }
  v111 = vec3_origin;
  idMD6Util::GetAnimDelta(md6anim: anim, deltaOrigin: &v111, deltaAxis: nullptr);
  v78 = this->ai;
  this->animDeltaCorrection.in.translationCorrectionMaxScale = 1.5;
  v79 = idEntity::GetPhysics(this: v78);
  v80 = (float *)v79->GetAxis(this: v79, a2: 0);
  v81 = (float)((float)(*v80 * v111.x) + (float)((float)(v80[3] * v111.y) + (float)(v80[6] * v111.z)));
  v82 = (float)((float)(v80[1] * v111.x) + (float)((float)(v80[4] * v111.y) + (float)(v80[7] * v111.z)));
  v83 = (float)((float)(v80[2] * v111.x) + (float)((float)(v80[5] * v111.y) + (float)(v80[8] * v111.z)));
  v84 = idEntity::GetPhysics(this: this->ai);
  v85 = (float *)v84->GetOrigin(this: v84, a2: 0);
  v86 = (float)(v85[1] + (float)v82);
  v87 = (float)(v85[2] + (float)v83);
  this->animDeltaCorrection.currentRefOrigin.x = *v85 + (float)v81;
  this->animDeltaCorrection.currentRefOrigin.y = v86;
  this->animDeltaCorrection.currentRefOrigin.z = v87;
  if ( this->cachedCorners.num > 0 )
  {
    list = this->cachedCorners.list;
    this->animDeltaCorrection.currentRefOrigin.x = list->position.x;
    this->animDeltaCorrection.currentRefOrigin.y = list->position.y;
    this->animDeltaCorrection.currentRefOrigin.z = list->position.z;
  }
}


// ========================================================================
// ?CheckDeltaCorrectionAbortConditions@idAnimBaseFSM@@QBA_NXZ
// EA  : 0x82A7B268
// RVA : 0x00A7B268
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm_deltacorrection.cpp
// ========================================================================

BOOL __fastcall idAnimBaseFSM::CheckDeltaCorrectionAbortConditions(idAnimBaseFSM *this)
{
  aiAnimDCIdealPoint_t idealPoint; // r11
  idVec3 v4; // [sp+50h] [-20h] BYREF

  idealPoint = this->animDeltaCorrection.idealPoint;
  if ( idealPoint <= IDEALPOINT_NONE
    || idealPoint > IDEALPOINT_CURRENT_ANIMNODE && idealPoint != IDEALPOINT_NEXTGROUNDPOINT )
  {
    return false;
  }
  idAnimBaseFSM::GetDeltaCorrectionGoalOrigin(this: (idAnimBaseFSM *)&v4, result: (idVec3 *)this);
  return idAnimBaseFSM::HasGoalChangedSignificantly(this, newGoal: &v4, cutoff: 20.0);
}


// ========================================================================
// ?HandleAnimDeltaCorrection@idAI2@@QAAXPBVidMD6Anim@@W4aiAnimDCIdealPoint_t@@W4aiAnimDCIdealDir_t@@W4animEventBool_t@@H@Z
// EA  : 0x82A7B2F0
// RVA : 0x00A7B2F0
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm_deltacorrection.cpp
// ========================================================================

void __fastcall idAI2::HandleAnimDeltaCorrection(
        idAI2 *this,
        const idMD6Anim *anim,
        unsigned __int32 idealPoint,
        unsigned __int32 idealDir,
        animEventBool_t correctGravity,
        int thisEventNumber)
{
  idDeclMD6 *decl; // r27
  idMD6AnimData *animData; // r11
  int numFrames; // r6
  idMD6AnimData *v14; // r11
  int v15; // r6
  idAnimWebCmdCtx *v16; // r3
  idAnimWebCmdCtx *(__fastcall *GetAnimWebCmdCtx)(struct idAI2 *); // r4
  const idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *value; // r19
  idAnimator_AnimWeb *animWeb; // r17
  int v20; // r3
  int curFrame; // r28
  const idDeclAnimWeb *v22; // r10
  const idDeclAnimWebNode *v23; // r19
  idMD6AnimData *v24; // r11
  int v25; // r6
  idVehicleState **list; // r4
  double v27; // fp31
  double v28; // fp29
  const idCachedJoint *NumLocalUsers; // r26
  float *v30; // r27
  double v31; // fp30
  int v32; // r10
  idVehicleState **v33; // r11
  idVehicleState *v34; // r29
  __int64 v35; // r9
  int v36; // r10
  D3DXShader::CTErrors **v37; // r11
  D3DXShader::CTErrors *v38; // r29
  __int64 v39; // r9
  double v40; // fp30
  const idCachedJoint *v41; // r26
  int v42; // r27
  int v43; // r10
  idVehicleState **v44; // r11
  idVehicleState *v45; // r29
  __int64 v46; // r9
  int v47; // r10
  D3DXShader::CTErrors **v48; // r11
  D3DXShader::CTErrors *v49; // r29
  __int64 v50; // r9
  const idCachedJoint *v51; // [sp+8h] [-208h]
  int v52; // [sp+Ch] [-204h]
  int v53; // [sp+10h] [-200h]
  int v54; // [sp+14h] [-1FCh]
  int v55; // [sp+18h] [-1F8h]
  int v56; // [sp+1Ch] [-1F4h]
  int v57; // [sp+20h] [-1F0h]
  int v58; // [sp+24h] [-1ECh]
  int v59; // [sp+28h] [-1E8h]
  int v60; // [sp+2Ch] [-1E4h]
  int v61; // [sp+30h] [-1E0h]
  int v62; // [sp+34h] [-1DCh]
  int v63; // [sp+38h] [-1D8h]
  int v64; // [sp+3Ch] [-1D4h]
  int v65; // [sp+40h] [-1D0h]
  int v66; // [sp+44h] [-1CCh]
  int v67; // [sp+48h] [-1C8h]
  int v68; // [sp+4Ch] [-1C4h]
  int v69; // [sp+50h] [-1C0h]
  idAnimator_AnimWeb::animInfo_t v70; // [sp+70h] [-1A0h] BYREF
  idList<idVehicleState *,5> v71; // [sp+80h] [-190h] BYREF
  int v72; // [sp+90h] [-180h] BYREF
  idList<idVehicleState *,5> v73; // [sp+D0h] [-140h] BYREF
  int v74; // [sp+E0h] [-130h] BYREF
  idList<idVehicleState *,5> v75; // [sp+120h] [-F0h] BYREF
  int v76; // [sp+130h] [-E0h] BYREF

  if ( common->IsServer(this: common) )
  {
    decl = idAnimatedEntity::GetTreeAnimatorFromPresentable(this)->decl;
    v75.granularity = 1;
    v75.size = 16;
    v75.num = 0;
    v75.memTag = 5;
    v75.list = (idVehicleState **)&v76;
    v75.listStatic = 1;
    v71.size = 16;
    v71.num = 0;
    v71.granularity = 1;
    v71.list = (idVehicleState **)&v72;
    v71.memTag = 5;
    v71.listStatic = 1;
    animData = anim->animData;
    numFrames = 0;
    if ( animData != nullptr )
      numFrames = animData->numFrames;
    idDeclMD6::FindAnimEvents(
      this: decl,
      anim,
      startFrame: 0,
      endFrame: numFrames,
      eventNum: AE_AnimDeltaCorrectionEnd.eventnum,
      events: &v75);
    v14 = anim->animData;
    v15 = 0;
    if ( v14 != nullptr )
      v15 = v14->numFrames;
    idDeclMD6::FindAnimEvents(
      this: decl,
      anim,
      startFrame: 0,
      endFrame: v15,
      eventNum: AE_AnimDeltaCorrectionGoal.eventnum,
      events: &v71);
    v16 = this->GetAnimWebCmdCtx(this);
    GetAnimWebCmdCtx = this->GetAnimWebCmdCtx;
    value = (const idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> *)(unsigned __int16)v16->animWeb->curNodeIndex.value;
    memset(&v70, 0, sizeof(v70));
    animWeb = GetAnimWebCmdCtx(this)->animWeb;
    v20 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
    idAnimator_AnimWeb::GetNodeAnimLength(
      this: animWeb,
      curTime: v20,
      modelIndex: nullptr,
      nodeIndex: value,
      animInfo: &v70);
    curFrame = v70.curFrame;
    v22 = this->GetAnimWebCmdCtx(this)->animWeb->decl;
    if ( (__int16)value == -1 )
      v23 = nullptr;
    else
      v23 = v22->nodes.list[(__int16)value];
    v73.size = 16;
    v73.num = 0;
    v73.granularity = 1;
    v73.list = (idVehicleState **)&v74;
    v73.memTag = 5;
    v73.listStatic = 1;
    v24 = anim->animData;
    v25 = 0;
    if ( v24 != nullptr )
      v25 = v24->numFrames;
    idDeclMD6::FindAnimEvents(
      this: decl,
      anim,
      startFrame: curFrame - 2,
      endFrame: v25,
      eventNum: thisEventNumber,
      events: &v73);
    list = v73.list;
    if ( v73.num > 0 )
      curFrame = SLOWORD((*v73.list)->debugName.len);
    v27 = -1.0;
    v28 = -1.0;
    NumLocalUsers = nullptr;
    v30 = nullptr;
    v31 = -1.0;
    if ( (_cntlzw(idealPoint) & 0x20) == 0 )
    {
      v32 = 0;
      if ( v75.num > 0 )
      {
        v33 = v75.list;
        while ( 1 )
        {
          v34 = *v33;
          if ( HIWORD((*v33)->__vftable) != 0
            && BYTE2(v34->stateData) == 3
            && *(_DWORD *)(LOWORD(v34->listenerList) + *(_DWORD *)&v34->enterFailed) != 0 )
          {
            break;
          }
          ++v32;
          ++v33;
          if ( v32 >= v75.num )
            goto LABEL_24;
        }
        if ( SLOWORD(v34->debugName.len) > curFrame + 2 )
        {
          NumLocalUsers = (const idCachedJoint *)idSignInManagerXbox::GetNumLocalUsers(this: (D3DXShader::CTErrors *)v34);
          LODWORD(v35) = SLOWORD(v34->debugName.len);
          v28 = (float)v35;
        }
        else
        {
          idLib::Warning(
            fmt: "%s, delta correction end event within 2 frames of start event, DISCARDING END EVENT",
            anim->name.str);
        }
      }
LABEL_24:
      v36 = 0;
      if ( v71.num > 0 )
      {
        v37 = (D3DXShader::CTErrors **)v71.list;
        while ( 1 )
        {
          v38 = *v37;
          if ( HIWORD((*v37)->m_uPragmaCount) != 0
            && BYTE2(v38->m_pErrorContext) == 3
            && *(_DWORD *)(LOWORD(v38->m_pErrorNums) + v38->m_cbErrors) != 0 )
          {
            break;
          }
          ++v36;
          ++v37;
          if ( v36 >= v71.num )
            goto LABEL_32;
        }
        v30 = (float *)idSignInManagerXbox::GetNumLocalUsers(this: *v37);
        LODWORD(v39) = SLOWORD(v38->m_uWarningCount);
        v31 = (float)v39;
      }
LABEL_32:
      idAnimBaseFSM::BeginAnimDeltaCorrectionTranslation(
        this: &this->aiVolatile.animation.animFSM,
        anim,
        node: v23,
        (aiAnimDCIdealPoint_t)idealPoint,
        startFrame: curFrame,
        endFrame: (int)v28,
        goalFrame: (int)v31,
        endJoint: NumLocalUsers,
        goalJoint: v51,
        correctGravity: v52,
        a11: v53,
        a12: v54,
        a13: v55,
        a14: v56,
        a15: v57,
        a16: v58,
        a17: v59,
        a18: v60,
        a19: v61,
        a20: v62,
        a21: v63,
        a22: v64,
        a23: v65,
        a24: v66,
        a25: v67,
        a26: v68,
        a27: v69,
        a28: v30);
      list = v73.list;
    }
    v40 = -1.0;
    v41 = nullptr;
    v42 = 0;
    if ( (_cntlzw(idealDir) & 0x20) == 0 )
    {
      v43 = 0;
      if ( v75.num > 0 )
      {
        v44 = v75.list;
        while ( 1 )
        {
          v45 = *v44;
          if ( HIWORD((*v44)->__vftable) > 1u
            && LOBYTE(v45->stateData) == 3
            && *(_DWORD *)(HIWORD(v45->listeningToList) + *(_DWORD *)&v45->enterFailed) != 0 )
          {
            break;
          }
          ++v43;
          ++v44;
          if ( v43 >= v75.num )
            goto LABEL_44;
        }
        if ( SLOWORD(v45->debugName.len) > curFrame + 2 )
        {
          v41 = (const idCachedJoint *)idSignInManagerXbox::GetNumLocalUsers(this: (D3DXShader::CTErrors *)v45);
          LODWORD(v46) = SLOWORD(v45->debugName.len);
          v40 = (float)v46;
        }
        else
        {
          idLib::Warning(
            fmt: "%s, delta correction end event within 2 frames of start event, DISCARDING END EVENT",
            anim->name.str);
        }
      }
LABEL_44:
      v47 = 0;
      if ( v71.num > 0 )
      {
        v48 = (D3DXShader::CTErrors **)v71.list;
        while ( 1 )
        {
          v49 = *v48;
          if ( HIWORD((*v48)->m_uPragmaCount) > 1u
            && LOBYTE(v49->m_pErrorContext) == 3
            && *(_DWORD *)(HIWORD(v49->m_pSpecifiers) + v49->m_cbErrors) != 0 )
          {
            break;
          }
          ++v47;
          ++v48;
          if ( v47 >= v71.num )
            goto LABEL_52;
        }
        v42 = idSignInManagerXbox::GetNumLocalUsers(this: *v48);
        LODWORD(v50) = SLOWORD(v49->m_uWarningCount);
        v27 = (float)v50;
      }
LABEL_52:
      idAnimBaseFSM::BeginAnimDeltaCorrectionRotation(
        this: &this->aiVolatile.animation.animFSM,
        anim,
        node: v23,
        (aiAnimDCIdealDir_t)idealDir,
        startFrame: curFrame,
        endFrame: (int)v40,
        goalFrame: (int)v27,
        endJoint: v41,
        goalJoint: v51,
        a10: v52,
        a11: v53,
        a12: v54,
        a13: v55,
        a14: v56,
        a15: v57,
        a16: v58,
        a17: v59,
        a18: v60,
        a19: v61,
        a20: v62,
        a21: v63,
        a22: v64,
        a23: v65,
        a24: v66,
        a25: v67,
        a26: v68,
        a27: v69,
        a28: v42);
      list = v73.list;
    }
    if ( v73.listStatic == 0 || v73.listStatic == 2 )
    {
      if ( list != nullptr )
        idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
      v73.list = nullptr;
      v73.size = 0;
    }
    v73.num = 0;
    if ( v71.listStatic == 0 || v71.listStatic == 2 )
    {
      if ( v71.list != nullptr )
        idMem::Free(this: &mem, ptr: v71.list, align: ALIGN_16);
      v71.list = nullptr;
      v71.size = 0;
    }
    v71.num = 0;
    if ( (v75.listStatic == 0 || v75.listStatic == 2) && v75.list != nullptr )
      idMem::Free(this: &mem, ptr: v75.list, align: ALIGN_16);
  }
}


// ========================================================================
// __unwind$491434
// EA  : 0x82A7B920
// RVA : 0x00A7B920
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm_deltacorrection.cpp
// ========================================================================

void _unwind_491434()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 528 + 288));
}


// ========================================================================
// __unwind$491435
// EA  : 0x82A7B948
// RVA : 0x00A7B948
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm_deltacorrection.cpp
// ========================================================================

void _unwind_491435()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 528 + 128));
}


// ========================================================================
// __unwind$491436
// EA  : 0x82A7B970
// RVA : 0x00A7B970
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm_deltacorrection.cpp
// ========================================================================

void _unwind_491436()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 528 + 208));
}


// ========================================================================
// ?AnimEvent_AnimDeltaCorrection@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@W4aiAnimDCIdealPoint_t@@W4aiAnimDCIdealDir_t@@W4animEventBool_t@@@Z
// EA  : 0x82A7B998
// RVA : 0x00A7B998
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm_deltacorrection.cpp
// ========================================================================

idAI2 *__fastcall idAI2::AnimEvent_AnimDeltaCorrection(
        idAI2 *this,
        idAI2 *result,
        const idMD6Anim *anim,
        unsigned __int32 idealPoint,
        unsigned __int32 idealDir,
        animEventBool_t correctGravity)
{
  if ( ai_enableDeltaCorrection.valueInteger != 0 )
    idAI2::HandleAnimDeltaCorrection(
      this: result,
      anim,
      idealPoint,
      idealDir,
      correctGravity,
      thisEventNumber: AE_AnimDeltaCorrection.eventnum);
  return this;
}


// ========================================================================
// ?AnimEvent_AnimDeltaCorrection_Turn@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA  : 0x82A7BA00
// RVA : 0x00A7BA00
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm_deltacorrection.cpp
// ========================================================================

idAI2 *__fastcall idAI2::AnimEvent_AnimDeltaCorrection_Turn(idAI2 *this, idAI2 *result, const idMD6Anim *anim)
{
  if ( ai_enableDeltaCorrection.valueInteger != 0 )
    idAI2::HandleAnimDeltaCorrection(
      this: result,
      anim,
      idealPoint: 0,
      idealDir: 2u,
      correctGravity: B_FALSE,
      thisEventNumber: AE_AnimDeltaCorrection_Turn.eventnum);
  return this;
}


// ========================================================================
// ?AnimEvent_AnimDeltaCorrection_Land@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA  : 0x82A7BA70
// RVA : 0x00A7BA70
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm_deltacorrection.cpp
// ========================================================================

idAI2 *__fastcall idAI2::AnimEvent_AnimDeltaCorrection_Land(idAI2 *this, idAI2 *result, const idMD6Anim *anim)
{
  int numFrames; // r30
  idMD6AnimData *animData; // r11
  int eventnum; // r27
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  int len_low; // r30
  idTreeAnimator *v11; // r3
  float *p_z; // r10
  float *p_y; // r11
  int v14; // ctr
  float *BodyOrientation; // r3
  double v16; // fp30
  double v17; // fp29
  double v18; // fp31
  idPhysics *Physics; // r3
  float *v20; // r3
  double x; // fp31
  double v22; // fp9
  double z; // fp29
  double y; // fp30
  idVec3 v26; // [sp+50h] [-3190h] BYREF
  idVec3 v27; // [sp+60h] [-3180h] BYREF
  float *v28; // [sp+6Ch] [-3174h]
  idMD6Util::animDelta_t v29; // [sp+70h] [-3170h] BYREF
  idList<idVehicleState *,5> v30; // [sp+A0h] [-3140h] BYREF
  int v31; // [sp+B0h] [-3130h] BYREF
  trace_t v32; // [sp+F0h] [-30F0h] BYREF
  idMD6Util::idJointCache v33; // [sp+170h] [-3070h] BYREF

  if ( ai_enableDeltaCorrection.valueInteger != 0 )
  {
    numFrames = 0;
    v30.granularity = 1;
    v30.num = 0;
    v30.size = 16;
    v30.list = (idVehicleState **)&v31;
    v30.memTag = 5;
    v30.listStatic = 1;
    animData = anim->animData;
    eventnum = AE_AnimDeltaCorrectionEnd.eventnum;
    if ( animData != nullptr )
      numFrames = animData->numFrames;
    TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: result);
    idDeclMD6::FindAnimEvents(
      this: TreeAnimatorFromPresentable->decl,
      anim,
      startFrame: 0,
      endFrame: numFrames,
      eventNum: eventnum,
      events: &v30);
    len_low = -1;
    if ( v30.num > 0 )
      len_low = SLOWORD((*v30.list)->debugName.len);
    v11 = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: result);
    idMD6Util::idJointCache::idJointCache(this: &v33, decl: v11->decl, anim, frameNum: len_low);
    p_z = &v29.deltaTranslation.z;
    p_y = &mat2_identity.mat[1].y;
    v14 = 9;
    v29.deltaTranslation = vec3_origin;
    do
    {
      *++p_z = *++p_y;
      --v14;
    }
    while ( v14 != 0 );
    if ( (unsigned __int8)idMD6Util::idJointCache::GetDelta(
                            this: &v33,
                            delta: &v29,
                            jointName: "origin",
                            refJointName: "origin") != 0 )
    {
      BodyOrientation = (float *)idAI2::GetBodyOrientation(this: result);
      v28 = BodyOrientation + 3;
      v16 = (float)((float)(BodyOrientation[5] * v29.deltaTranslation.x)
                  + (float)((float)(BodyOrientation[8] * v29.deltaTranslation.y)
                          + (float)(BodyOrientation[11] * v29.deltaTranslation.z)));
      v17 = (float)((float)(BodyOrientation[4] * v29.deltaTranslation.x)
                  + (float)((float)(BodyOrientation[7] * v29.deltaTranslation.y)
                          + (float)(BodyOrientation[10] * v29.deltaTranslation.z)));
      v18 = (float)((float)(BodyOrientation[3] * v29.deltaTranslation.x)
                  + (float)((float)(BodyOrientation[6] * v29.deltaTranslation.y)
                          + (float)(BodyOrientation[9] * v29.deltaTranslation.z)));
      Physics = idEntity::GetPhysics(this: result);
      v20 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
      x = (float)(*v20 + (float)v18);
      v22 = (float)(v20[1] + (float)v17);
      z = (float)(v20[2] + (float)v16);
      y = v22;
      v26.x = (float)(vec3_up.x * (float)128.0) + (float)x;
      v26.z = (float)(vec3_up.z * (float)128.0) + (float)z;
      v26.y = (float)(vec3_up.y * (float)128.0) + (float)v22;
      v27.x = v26.x - (float)(vec3_up.x * (float)256.0);
      v27.z = v26.z - (float)(vec3_up.z * (float)256.0);
      v27.y = v26.y - (float)(vec3_up.y * (float)256.0);
      idClip::TracePoint(
        this: &clientGame->clip,
        result: &v32,
        start: &v26,
        end: &v27,
        clipMask: 106513,
        passEntityNumber: 0x1FFF);
      if ( v32.fraction < 1.0 )
      {
        x = v32.endpos.x;
        y = v32.endpos.y;
        z = v32.endpos.z;
      }
      result->aiVolatile.animation.animFSM.animDeltaCorrection.currentRefOrigin.x = x;
      result->aiVolatile.animation.animFSM.animDeltaCorrection.currentRefOrigin.y = y;
      result->aiVolatile.animation.animFSM.animDeltaCorrection.currentRefOrigin.z = z;
    }
    idAI2::HandleAnimDeltaCorrection(
      this: result,
      anim,
      idealPoint: 4u,
      idealDir: 0,
      correctGravity: B_FALSE,
      thisEventNumber: AE_AnimDeltaCorrection_Land.eventnum);
    idList<idThread *,58>::Clear(this: &v30);
  }
  return this;
}


// ========================================================================
// __unwind$491938
// EA  : 0x82A7BD7C
// RVA : 0x00A7BD7C
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm_deltacorrection.cpp
// ========================================================================

void _unwind_491938()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 12768 + 160));
}


// ========================================================================
// ?MoveAIDeltaCorrection@idAnimBaseFSM@@IAAXXZ
// EA  : 0x82A7BDB0
// RVA : 0x00A7BDB0
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm_deltacorrection.cpp
// ========================================================================

void __fastcall idAnimBaseFSM::MoveAIDeltaCorrection(idAnimBaseFSM *this)
{
  unsigned __int64 v2; // r6
  const char *v3; // r7
  idTreeAnimator *v4; // r28
  BOOL useDeferredPosition; // r8
  idMat3 *p_deferredAxis; // r11
  int *v7; // r10
  _DWORD *p_z; // r11
  int i; // ctr
  idRenderModelParms *p_deferredOrigin; // r11
  float x; // r10
  float y; // r9
  float z; // r8
  float *v14; // r10
  int *v15; // r11
  int j; // ctr
  double v17; // fp9
  double v18; // fp7
  double v19; // fp6
  double v20; // fp5
  double v21; // fp4
  double v22; // fp9
  double v23; // fp0
  double v24; // fp8
  double v25; // fp7
  idMat3 *LastOriginRotation; // r3
  double previousRemainingTranslationFrames; // fp20
  double previousRemainingRotationFrames; // fp31
  int rotationEndTime; // r4
  const idVec3 *LastOriginTranslation; // r3
  float v31; // r10
  float v32; // r9
  idAI2 *ai; // r8
  double v34; // fp14
  char v35; // r11
  unsigned __int8 v36; // r27
  idAnimWebAI *ptr; // r28
  char *v38; // r4
  double v39; // fp17
  idVec3 *p_animSpaceGoalTranslation; // r26
  double v41; // fp11
  double v42; // fp16
  double v43; // fp6
  idMat3 *v44; // r3
  idAngles *v45; // r3
  double yaw; // fp0
  char v47; // r10
  char v48; // r11
  int v49; // r9
  double v50; // fp31
  double v51; // fp30
  double v52; // fp25
  double v53; // fp29
  double v54; // fp28
  double v55; // fp24
  double v56; // fp27
  double v57; // fp26
  double v58; // fp23
  float *DeltaCorrectionGoalRotation; // r3
  idVec3 *v60; // r10
  char v61; // r9
  double v62; // fp1
  char v63; // r4
  idVec3 *p_animSpaceEndTranslation; // r28
  double v65; // fp10
  double v66; // fp9
  double v67; // fp31
  double v68; // fp30
  double v69; // fp19
  idAI2 *v70; // r9
  double v71; // fp29
  double v72; // fp28
  double v73; // fp27
  double v74; // fp26
  double v75; // fp25
  double v76; // fp24
  double v77; // fp23
  double v78; // fp22
  double v79; // fp21
  double v80; // fp5
  double v81; // fp4
  double v82; // fp6
  idRenderWorld *v83; // r3
  idRenderWorld_vtbl *v84; // r9
  idRenderWorld *v85; // r3
  double v86; // fp9
  float v87; // r9
  float v88; // r8
  double v89; // fp13
  double v90; // fp8
  double v91; // fp7
  double v92; // fp0
  double v93; // fp20
  double v94; // fp14
  double v95; // fp1
  double v96; // fp2
  double v97; // fp10
  double v98; // fp10
  double v99; // fp12
  double v100; // fp11
  double v101; // fp31
  double v102; // fp30
  idAI2 *v103; // r11
  double v104; // fp0
  double v105; // fp10
  double v106; // fp9
  double v107; // fp11
  idRenderWorld *v108; // r3
  idRenderWorld_vtbl *v109; // r11
  idRenderWorld *v110; // r3
  double v111; // fp21
  double v112; // fp19
  double v113; // fp18
  int v114; // r8
  double v115; // fp17
  double v116; // fp16
  double v117; // fp0
  double v118; // fp13
  double v119; // fp15
  double v120; // fp12
  double v121; // fp1
  int v122; // r10
  double v123; // fp5
  double v124; // fp10
  double v125; // fp11
  double v126; // fp9
  double v127; // fp29
  double v128; // fp30
  double v129; // fp31
  double v130; // fp28
  double v131; // fp27
  double v132; // fp26
  double v133; // fp29
  double v134; // fp13
  double v135; // fp4
  double v136; // fp1
  double v137; // fp13
  double v138; // fp7
  double v139; // fp8
  double v140; // fp5
  double v141; // fp24
  double v142; // fp23
  double v143; // fp22
  double translationCorrectionMaxScale; // fp25
  double v145; // fp1
  double v146; // fp12
  double v147; // fp0
  double v148; // fp0
  bool v149; // r27
  BOOL v150; // r29
  bool v151; // r28
  float *v152; // r3
  double v153; // fp0
  double v154; // fp13
  double v155; // fp12
  double v156; // fp11
  double v157; // fp11
  double v158; // fp11
  double v159; // fp8
  bool v160; // r10
  bool v161; // r11
  float *v162; // r3
  double v163; // fp0
  double v164; // fp10
  double v165; // fp9
  double v166; // fp12
  double v167; // fp13
  double v168; // fp11
  double v169; // fp8
  double v170; // fp0
  double v171; // fp0
  double v172; // r5
  idRenderWorld *v173; // r3
  idRenderWorld *v174; // r3
  idRenderWorld *v175; // r3
  idRenderWorld_vtbl *v176; // r11
  idRenderWorld *v177; // r3
  idTreeAnimator *v178; // r10
  idAI2 *v179; // r8
  double v180; // fp0
  double v181; // fp12
  double v182; // fp11
  double v183; // fp0
  double v184; // fp13
  double v185; // fp12
  idRenderWorld *v186; // r3
  idRenderWorld *v187; // r3
  idRenderWorld *v188; // r3
  idMD6AnimData *animData; // r11
  double v190; // fp31
  double v191; // fp30
  double v192; // fp29
  double v193; // fp28
  double v194; // fp18
  double v195; // fp21
  const idMat3 *v196; // r3
  idMat3 *v197; // r3
  idMat3 *v198; // r3
  double v199; // fp0
  double v200; // fp9
  idAI2 *v201; // r9
  double v202; // fp4
  idMat3 *v203; // r3
  const idMat3 *v204; // r29
  const idMat3 *v205; // r3
  idMat3 *v206; // r3
  idMat3 *v207; // r3
  idMat3 *v208; // r3
  idRenderWorld *v209; // r3
  double v210; // fp19
  idRenderWorld *v211; // r3
  double v212; // fp22
  double v213; // fp24
  const idMat3 *v214; // r3
  idMat3 *v215; // r3
  idMat3 *v216; // r3
  double v217; // fp20
  idMat3 *v218; // r3
  const idMat3 *v219; // r29
  idMat3 *v220; // r3
  idMat3 *v221; // r3
  idMat3 *v222; // r3
  idMat3 *v223; // r3
  const idMat3 *v224; // r29
  const idMat3 *v225; // r3
  idMat3 *v226; // r3
  idMat3 *v227; // r3
  const idMat3 *v228; // r29
  idMat3 *v229; // r3
  idMat3 *v230; // r3
  idMat3 *v231; // r3
  double v232; // fp25
  double rotationRateMax; // fp31
  int (*GetGameMsPerFrame)(void); // ctr
  _BYTE v235[12]; // r7
  double v236; // fp27
  double v237; // fp23
  double v238; // fp28
  double v239; // fp31
  char v240; // r11
  double v241; // fp30
  char v242; // r29
  int v243; // r10
  double v244; // fp0
  double v245; // fp31
  idAI2 *v246; // r10
  double v247; // fp0
  char v248; // r9
  char v249; // r11
  double v250; // fp0
  double v251; // fp0
  char v252; // r11
  double v253; // fp0
  double v254; // fp0
  idMat3 *v255; // r3
  idAI2 *v256; // r10
  idRenderWorld *v257; // r29
  idMat3 *v258; // r3
  const idMat3 *v259; // r3
  idMat3 *v260; // r3
  idMat3 *v261; // r3
  double v262; // fp6
  double v263; // fp9
  idMat3 *v264; // r3
  float *v265; // r3
  double v266; // fp0
  int v267; // r9
  double v268; // fp13
  double v269; // fp12
  double v270; // fp11
  double v271; // fp10
  double v272; // fp9
  double v273; // fp8
  double v274; // fp7
  double v275; // fp6
  double v276; // fp1
  double v277; // fp5
  double v278; // fp9
  double v279; // fp4
  idColor *v280; // r29
  idRenderWorld *v281; // r3
  idAI2 *v282; // r3
  navVolumeFlags_t useVolumes; // r9
  float v284; // r7
  float v285; // r10
  int v286; // r28
  int v287; // r27
  float v288; // r8
  int v289; // r11
  int lastBlendTime; // r29
  int v291; // r28
  unsigned __int8 UserChannelUseGravity; // r3
  idPhysics_AI *v293; // r27
  unsigned int v294; // r3
  double previousRemainingRotationFramesToGoal; // fp31
  char v296; // r11
  idAIStateLite *currentState; // r3
  const char *name; // r29
  const char *Classname; // r3
  double v300; // fp31
  idAngles *v301; // r3
  const char *v302; // r3
  unsigned __int8 v303; // r29
  idAI2 *v304; // r3
  double v305; // fp31
  turnDirection_t v306; // r5
  double v307; // [sp+18h] [-7E8h]
  idVec3 v308; // [sp+50h] [-7B0h] BYREF
  idVec3 *v309; // [sp+5Ch] [-7A4h]
  idVec3 v310; // [sp+60h] [-7A0h] BYREF
  __int64 v311; // [sp+70h] [-790h]
  idMat3 v312; // [sp+78h] [-788h] BYREF
  idMat3 v313; // [sp+A0h] [-760h] BYREF
  float v314; // [sp+C4h] [-73Ch]
  float v315; // [sp+C8h] [-738h]
  float v316; // [sp+CCh] [-734h]
  float v317; // [sp+D0h] [-730h]
  idMat3 v318; // [sp+E0h] [-720h] BYREF
  float v319; // [sp+104h] [-6FCh]
  float v320; // [sp+108h] [-6F8h] BYREF
  float v321; // [sp+10Ch] [-6F4h]
  float v322; // [sp+110h] [-6F0h]
  float v323; // [sp+118h] [-6E8h] BYREF
  float v324; // [sp+11Ch] [-6E4h]
  float v325; // [sp+120h] [-6E0h]
  idMat3 v326; // [sp+130h] [-6D0h] BYREF
  int v327; // [sp+15Ch] [-6A4h] BYREF
  idMat3 v328; // [sp+160h] [-6A0h] BYREF
  idTreeAnimator *TreeAnimatorFromPresentable; // [sp+184h] [-67Ch]
  idMat3 v330; // [sp+188h] [-678h] BYREF
  float v331; // [sp+1ACh] [-654h]
  float v332; // [sp+1B0h] [-650h]
  float v333; // [sp+1B4h] [-64Ch]
  float v334; // [sp+1B8h] [-648h]
  float v335; // [sp+1BCh] [-644h]
  idMat3 v336; // [sp+1C0h] [-640h] BYREF
  idNpMover3D::idProbeInput3D v337; // [sp+1E4h] [-61Ch] BYREF
  idMat3 v338; // [sp+1F0h] [-610h] BYREF
  float v339; // [sp+218h] [-5E8h] BYREF
  float v340; // [sp+21Ch] [-5E4h]
  float v341; // [sp+220h] [-5E0h]
  idMat3 v342; // [sp+230h] [-5D0h] BYREF
  int v343; // [sp+254h] [-5ACh]
  float v344; // [sp+258h] [-5A8h]
  float v345; // [sp+25Ch] [-5A4h] BYREF
  idMat3 v346; // [sp+260h] [-5A0h] BYREF
  idMat3 v347; // [sp+288h] [-578h] BYREF
  int v348; // [sp+2ACh] [-554h]
  int v349; // [sp+2B0h] [-550h]
  int v350; // [sp+2B4h] [-54Ch]
  char v351; // [sp+2B8h] [-548h]
  float v352; // [sp+2BCh] [-544h]
  float v353; // [sp+2C0h] [-540h]
  float v354; // [sp+2C4h] [-53Ch]
  idStr v355; // [sp+2D0h] [-530h] BYREF
  float v356[4]; // [sp+2F0h] [-510h] BYREF
  float v357[4]; // [sp+300h] [-500h] BYREF
  float v358[4]; // [sp+310h] [-4F0h] BYREF
  float v359[4]; // [sp+320h] [-4E0h] BYREF
  float v360[4]; // [sp+330h] [-4D0h] BYREF
  idMat3 v361; // [sp+340h] [-4C0h] BYREF
  float v362; // [sp+364h] [-49Ch]
  float v363; // [sp+368h] [-498h]
  float v364[4]; // [sp+370h] [-490h] BYREF
  idVec3 v365; // [sp+380h] [-480h] BYREF
  idMat3 v366; // [sp+390h] [-470h] BYREF
  float v367; // [sp+3B4h] [-44Ch]
  float v368; // [sp+3B8h] [-448h]
  float v369[4]; // [sp+3C0h] [-440h] BYREF
  float v370[4]; // [sp+3D0h] [-430h] BYREF
  float v371[4]; // [sp+3E0h] [-420h] BYREF
  float v372[4]; // [sp+3F0h] [-410h] BYREF
  float v373[4]; // [sp+400h] [-400h] BYREF
  idMat3 v374; // [sp+410h] [-3F0h] BYREF
  idMat3 v375; // [sp+440h] [-3C0h] BYREF
  idAnimBaseFSM::deltaCorrectionGoalRotationParms_t v376; // [sp+470h] [-390h] BYREF
  idMat3 v377; // [sp+4E0h] [-320h] BYREF
  idMat3 v378; // [sp+510h] [-2F0h] BYREF
  idMat3 v379; // [sp+540h] [-2C0h] BYREF
  idMat3 v380; // [sp+570h] [-290h] BYREF
  idMat3 v381; // [sp+5A0h] [-260h] BYREF
  idMat3 v382; // [sp+5D0h] [-230h] BYREF
  idMat3 v383; // [sp+600h] [-200h] BYREF
  idMat3 v384; // [sp+628h] [-1D8h] BYREF
  idMat3 v385; // [sp+658h] [-1A8h] BYREF
  idMat3 v386; // [sp+688h] [-178h] BYREF
  idMat3 v387[5]; // [sp+6B0h] [-150h] BYREF

  RD_EventBegin(name: "idAnimFSM_AAS::MoveAIDeltaCorrection");
  LODWORD(v2) = "idAnimFSM_AAS::MoveAIDeltaCorrection";
  HIDWORD(v2) = 6;
  idPLogScope::idPLogScope(this: (idPLogScope *)&v347.mat[1].y, pl: &pLog, gMask: v2, label: v3);
  if ( idEntity::GetPhysics(this: this->ai)->type != PHYSICS_AI )
  {
    idAnimBaseFSM::SetDestination(this, cmd: &idAIMoveCmd::s_null);
    idPLogScope::~idPLogScope(this: (idPLogScope *)&v347.mat[1].y);
    goto LABEL_274;
  }
  LODWORD(v330.mat[1].x) = this->ai;
  v343 = LODWORD(v330.mat[1].x) + 11520;
  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: (idAnimatedEntity *)LODWORD(v330.mat[1].x));
  v4 = TreeAnimatorFromPresentable;
  idTreeAnimator::SetRemoveOriginRotation(this: TreeAnimatorFromPresentable, removeRotation: true);
  idTreeAnimator::SetRemoveOriginRotation(this: TreeAnimatorFromPresentable, removeRotation: true);
  useDeferredPosition = TreeAnimatorFromPresentable->useDeferredPosition;
  p_deferredAxis = &TreeAnimatorFromPresentable->deferredAxis;
  if ( !TreeAnimatorFromPresentable->useDeferredPosition )
    p_deferredAxis = &TreeAnimatorFromPresentable->g.axis;
  v7 = &v327;
  p_z = (_DWORD *)&p_deferredAxis[-1].mat[2].z;
  for ( i = 9; i != 0; --i )
    *++v7 = *++p_z;
  p_deferredOrigin = (idRenderModelParms *)&v4->deferredOrigin;
  if ( !useDeferredPosition )
    p_deferredOrigin = &v4->g;
  x = p_deferredOrigin->origin.x;
  y = p_deferredOrigin->origin.y;
  z = p_deferredOrigin->origin.z;
  v310.x = p_deferredOrigin->origin.x;
  v310.y = y;
  v310.z = z;
  if ( (_S18_4 & 1) == 0 )
  {
    prevOrigin.x = x;
    prevOrigin.y = y;
    _S18_4 |= 1u;
    prevOrigin.z = z;
  }
  v14 = &v345;
  v15 = &v327;
  for ( j = 9; j != 0; --j )
    *(_DWORD *)++v14 = *++v15;
  idMat3::ToAngles(this: &v386, result: (idAngles *)&v346);
  LODWORD(v336.mat[2].z) = &vec3_origin;
  *(idVec3 *)&v312.mat[1].y = vec3_origin;
  idTreeAnimator::GetLastOriginDeltas(this: v4, rot: &v326, trans: &v308);
  v17 = (float)(this->animDeltaCorrection.animSpacePreTranslationCorrection.mat[1].z * v308.y);
  v18 = (float)(this->animDeltaCorrection.animSpacePreTranslationCorrection.mat[1].y * v308.y);
  v19 = (float)(this->animDeltaCorrection.animSpacePreTranslationCorrection.mat[1].x * v308.y);
  v20 = this->animDeltaCorrection.animSpacePreTranslationCorrection.mat[2].z;
  v21 = this->animDeltaCorrection.animSpacePreTranslationCorrection.mat[2].y;
  LODWORD(v330.mat[1].x) = &this->animDeltaCorrection.animSpacePreTranslationCorrection;
  v23 = this->animDeltaCorrection.animSpacePreTranslationCorrection.mat[0].x;
  v24 = (float)((float)(this->animDeltaCorrection.animSpacePreTranslationCorrection.mat[0].z * v308.x)
              + (float)((float)((float)v20 * v308.z) + (float)v17));
  v22 = (float)((float)(this->animDeltaCorrection.animSpacePreTranslationCorrection.mat[2].x * v308.z) + (float)v19);
  v25 = (float)((float)(this->animDeltaCorrection.animSpacePreTranslationCorrection.mat[0].y * v308.x)
              + (float)((float)((float)v21 * v308.z) + (float)v18));
  v308.z = v24;
  v308.y = v25;
  v308.x = (float)(v308.x * (float)v23) + (float)v22;
  idMat3::ToAngles(this: &v312, result: (idAngles *)&v326);
  LastOriginRotation = (idMat3 *)idTreeAnimator::GetLastOriginRotation(this: v4);
  idQuat::ToMat3(this: (idQuat *)&v338, result: LastOriginRotation);
  idMat3::ToAngles(this: &v384, result: (idAngles *)&v338);
  idMat3::ToAngles(this: (idMat3 *)&v385.mat[2].z, result: (idAngles *)&v326);
  previousRemainingTranslationFrames = this->animDeltaCorrection.previousRemainingTranslationFrames;
  this->animDeltaCorrection.previousRemainingTranslationFrames = idAnimBaseFSM::GetRemainingFramesToTime(
                                                                   this,
                                                                   time: this->animDeltaCorrection.translationEndTime);
  previousRemainingRotationFrames = this->animDeltaCorrection.previousRemainingRotationFrames;
  rotationEndTime = this->animDeltaCorrection.rotationEndTime;
  v336.mat[2].y = this->animDeltaCorrection.previousRemainingRotationFrames;
  this->animDeltaCorrection.previousRemainingRotationFrames = idAnimBaseFSM::GetRemainingFramesToTime(
                                                                this,
                                                                time: rotationEndTime);
  LastOriginTranslation = idTreeAnimator::GetLastOriginTranslation(this: v4);
  v31 = LastOriginTranslation->y;
  v32 = LastOriginTranslation->z;
  v336.mat[0].x = LastOriginTranslation->x;
  v336.mat[0].y = v31;
  v336.mat[0].z = v32;
  idStr::idStr(this: &v355, text: "dc");
  ai = this->ai;
  v34 = v336.mat[0].x;
  v35 = *((_BYTE *)&this->animDeltaCorrection + 72);
  v36 = 1;
  ptr = ai->aiVolatile.animation.animWebAnimator.ptr;
  LODWORD(v330.mat[1].x) = &ai->aiVolatile.animation;
  if ( (v35 < 0 || (v35 & 0x40) != 0) && ai->aiVolatile.animation.animWebAnimator.ptr[0].modelAnimStates.list->blending )
  {
    if ( previousRemainingTranslationFrames > 4.0 || previousRemainingRotationFrames > 4.0 )
    {
      if ( idAnimWebAI::GetWebOriginBlendOp(this: ai->aiVolatile.animation.animWebAnimator.ptr) != ORIGINBLEND_RIGHT )
      {
        idAnimWebAI::ForceWebOriginBlendOp(this: ptr, newOp: ORIGINBLEND_RIGHT);
        v36 = 0;
        idStr::Append(this: &v355, text: " w_b");
      }
      if ( v34 > 20.0 )
      {
        v36 = 0;
        v38 = " w_lt";
        goto LABEL_25;
      }
    }
    else if ( this->animDeltaCorrection.idealDir == IDEALDIR_DEPARTURE_PATH_DIRECTION
           && idAnimWebAI::GetWebOriginBlendOp(this: ai->aiVolatile.animation.animWebAnimator.ptr) != ORIGINBLEND_LEFT )
    {
      v36 = 0;
      idLib::Warning(
        fmt: "%s, delta correction end time is within blend window, aborting delta correction.",
        this->animDeltaCorrection.anim->name.str);
      v38 = " aborted";
LABEL_25:
      idStr::Append(this: &v355, text: v38);
    }
  }
  v39 = v336.mat[0].y;
  p_animSpaceGoalTranslation = &this->animDeltaCorrection.animSpaceGoalTranslation;
  v41 = (float)(this->animDeltaCorrection.animSpaceGoalTranslation.x - (float)v34);
  v42 = v336.mat[0].z;
  v43 = (float)((float)((float)(this->animDeltaCorrection.animSpaceGoalTranslation.z - v336.mat[0].z)
                      * (float)(this->animDeltaCorrection.animSpaceGoalTranslation.z - v336.mat[0].z))
              + (float)((float)((float)v41 * (float)v41)
                      + (float)((float)(this->animDeltaCorrection.animSpaceGoalTranslation.y - v336.mat[0].y)
                              * (float)(this->animDeltaCorrection.animSpaceGoalTranslation.y - v336.mat[0].y))));
  v309 = &this->animDeltaCorrection.animSpaceGoalTranslation;
  *((_BYTE *)&this->animDeltaCorrection + 372) = (16 * (__fsqrts(v43) > 0.1)) & 0x10
                                               | *((_BYTE *)&this->animDeltaCorrection + 372) & 0xEF;
  v44 = idMat3::Inverse(this: &v380, result: &v338);
  v45 = (idAngles *)idMat3::operator*(this: &v383, result: v44, a: &this->animDeltaCorrection.animSpaceGoalRotation);
  yaw = idMat3::ToAngles(this: &v361, result: v45)->yaw;
  v335 = 1.0;
  v333 = -1.0;
  if ( yaw > 1.0 || (v47 = 0, yaw < -1.0) )
    v47 = 1;
  v48 = *((_BYTE *)&this->animDeltaCorrection + 372);
  BYTE1(v312.mat[2].z) = v47;
  if ( (v48 & 0x10) == 0 )
    *((_BYTE *)&this->animDeltaCorrection + 372) = (16 * v47) & 0x10 | v48 & 0xEF;
  v49 = *((_BYTE *)&this->animDeltaCorrection + 72) & 0x80;
  v334 = 0.0;
  if ( v49 == 0 )
    goto LABEL_32;
  if ( (*((_BYTE *)&this->animDeltaCorrection + 372) & 0x80) != 0 )
  {
    DeltaCorrectionGoalRotation = (float *)idAnimBaseFSM::GetDeltaCorrectionGoalRotation(
                                             this: (idAnimBaseFSM *)&v380,
                                             result: this,
                                             parms: nullptr);
    goto LABEL_39;
  }
  if ( (*((_BYTE *)&this->animDeltaCorrection + 112) & 0x80) == 0 )
  {
    idAnimBaseFSM::GetDeltaCorrectionGoalRotation(this: (idAnimBaseFSM *)&v313.mat[1].y, result: this, parms: nullptr);
    idMat3::operator*(
      this: &v318,
      result: &this->animDeltaCorrection.uncorrectedAxis,
      a: &this->animDeltaCorrection.animSpaceGoalRotation);
    if ( (float)((float)(v313.mat[2].x * v318.mat[0].z)
               + (float)((float)(v318.mat[0].x * v313.mat[1].y) + (float)(v313.mat[1].z * v318.mat[0].y))) < 0.0 )
    {
      v50 = this->animDeltaCorrection.uncorrectedAxis.mat[0].x;
      v51 = this->animDeltaCorrection.uncorrectedAxis.mat[0].y;
      v60 = &this->animDeltaCorrection.uncorrectedAxis.mat[1];
      v61 = *((_BYTE *)&this->animDeltaCorrection + 112) | 0x80;
      v52 = this->animDeltaCorrection.uncorrectedAxis.mat[0].z;
      v53 = this->animDeltaCorrection.uncorrectedAxis.mat[1].x;
      LODWORD(v312.mat[2].y) = &this->animDeltaCorrection.uncorrectedAxis;
      v54 = this->animDeltaCorrection.uncorrectedAxis.mat[1].y;
      v55 = this->animDeltaCorrection.uncorrectedAxis.mat[1].z;
      v56 = this->animDeltaCorrection.uncorrectedAxis.mat[2].x;
      v57 = this->animDeltaCorrection.uncorrectedAxis.mat[2].y;
      v58 = this->animDeltaCorrection.uncorrectedAxis.mat[2].z;
      *((_BYTE *)&this->animDeltaCorrection + 112) = v61;
LABEL_40:
      LODWORD(v312.mat[2].y) = v60;
      goto LABEL_41;
    }
    DeltaCorrectionGoalRotation = (float *)idMat3::operator*(
                                             this: &v380,
                                             result: (idMat3 *)&v313.mat[1].y,
                                             a: &this->animDeltaCorrection.animSpaceGoalRotation);
LABEL_39:
    v58 = DeltaCorrectionGoalRotation[8];
    v57 = DeltaCorrectionGoalRotation[7];
    v60 = (idVec3 *)(DeltaCorrectionGoalRotation + 6);
    v56 = DeltaCorrectionGoalRotation[6];
    LODWORD(v312.mat[2].y) = DeltaCorrectionGoalRotation + 3;
    v55 = DeltaCorrectionGoalRotation[5];
    v54 = DeltaCorrectionGoalRotation[4];
    v53 = DeltaCorrectionGoalRotation[3];
    v52 = DeltaCorrectionGoalRotation[2];
    v51 = DeltaCorrectionGoalRotation[1];
    v50 = *DeltaCorrectionGoalRotation;
    goto LABEL_40;
  }
LABEL_32:
  v50 = this->animDeltaCorrection.uncorrectedAxis.mat[0].x;
  v51 = this->animDeltaCorrection.uncorrectedAxis.mat[0].y;
  LODWORD(v312.mat[1].x) = &this->animDeltaCorrection.uncorrectedAxis.mat[1];
  v52 = this->animDeltaCorrection.uncorrectedAxis.mat[0].z;
  v53 = this->animDeltaCorrection.uncorrectedAxis.mat[1].x;
  LODWORD(v312.mat[1].x) = &this->animDeltaCorrection.uncorrectedAxis.mat[2];
  v54 = this->animDeltaCorrection.uncorrectedAxis.mat[1].y;
  v55 = this->animDeltaCorrection.uncorrectedAxis.mat[1].z;
  v56 = this->animDeltaCorrection.uncorrectedAxis.mat[2].x;
  v57 = this->animDeltaCorrection.uncorrectedAxis.mat[2].y;
  v58 = this->animDeltaCorrection.uncorrectedAxis.mat[2].z;
LABEL_41:
  v318.mat[0].x = v50;
  v318.mat[0].y = v51;
  v318.mat[0].z = v52;
  v318.mat[1].x = v53;
  v318.mat[1].y = v54;
  v318.mat[1].z = v55;
  v318.mat[2].x = v56;
  v318.mat[2].y = v57;
  v318.mat[2].z = v58;
  v62 = idMat3::ToYaw(this: &this->animDeltaCorrection.animSpaceEndRotation);
  if ( v62 > 1.0 || (v63 = 0, v62 < -1.0) )
    v63 = 1;
  HIBYTE(v312.mat[2].z) = v63;
  LODWORD(v312.mat[2].y) = v36;
  v312.mat[1].x = 250.0;
  v319 = 200.0;
  if ( v36 != 0
    && (*((_BYTE *)&this->animDeltaCorrection + 72) & 0x40) != 0
    && previousRemainingTranslationFrames >= 0.0 )
  {
    idStr::Append(this: &v355, text: " c_trans");
    idAnimBaseFSM::GetDeltaCorrectionGoalOrigin(this: (idAnimBaseFSM *)&v330.mat[2].z, result: (idVec3 *)this);
    p_animSpaceEndTranslation = &this->animDeltaCorrection.animSpaceEndTranslation;
    v65 = p_animSpaceGoalTranslation->x;
    v66 = this->animDeltaCorrection.animSpaceEndTranslation.x;
    v67 = (float)(this->animDeltaCorrection.animSpaceGoalTranslation.z
                - this->animDeltaCorrection.animSpaceEndTranslation.z);
    v68 = (float)(this->animDeltaCorrection.animSpaceGoalTranslation.y
                - this->animDeltaCorrection.animSpaceEndTranslation.y);
    v69 = (float)(p_animSpaceGoalTranslation->x - this->animDeltaCorrection.animSpaceEndTranslation.x);
    v345 = this->animDeltaCorrection.animSpaceGoalTranslation.z - this->animDeltaCorrection.animSpaceEndTranslation.z;
    v344 = v68;
    v309 = &this->animDeltaCorrection.animSpaceEndTranslation;
    v361.mat[0].x = (float)v65 - (float)v66;
    idMat3::operator*(
      this: (idMat3 *)&v313.mat[1].y,
      result: &v318,
      a: &this->animDeltaCorrection.animSpacePreTranslationCorrection);
    v70 = this->ai;
    *(float *)&v309 = 10.0;
    v71 = v314;
    v72 = v313.mat[2].z;
    v73 = v315;
    v74 = v313.mat[2].x;
    v75 = v313.mat[1].z;
    v76 = v313.mat[2].y;
    v77 = v317;
    v78 = v316;
    v79 = v313.mat[1].y;
    v80 = (float)(v332
                - (float)((float)((float)v67 * v317)
                        + (float)((float)((float)v69 * v313.mat[2].x) + (float)((float)v68 * v314))));
    v325 = v332
         - (float)((float)((float)v67 * v317) + (float)((float)((float)v69 * v313.mat[2].x) + (float)((float)v68 * v314)));
    v81 = (float)(v331
                - (float)((float)((float)v67 * v316)
                        + (float)((float)((float)v69 * v313.mat[1].z) + (float)((float)v68 * v313.mat[2].z))));
    v324 = v331
         - (float)((float)((float)v67 * v316)
                 + (float)((float)((float)v69 * v313.mat[1].z) + (float)((float)v68 * v313.mat[2].z)));
    v82 = (float)(v330.mat[2].z
                - (float)((float)(v313.mat[1].y * (float)v69)
                        + (float)((float)((float)v68 * v313.mat[2].y) + (float)((float)v67 * v315))));
    v323 = v330.mat[2].z
         - (float)((float)(v313.mat[1].y * (float)v69)
                 + (float)((float)((float)v68 * v313.mat[2].y) + (float)((float)v67 * v315)));
    if ( ai_debugAnimDeltaCorrection.valueInteger == v70->entityNumber
      && ai_debugAnimDeltaCorrectionType.valueInteger == 1 )
    {
      v83 = gameLocal->GetRenderWorld(this: gameLocal);
      v361.mat[1].y = v323;
      v361.mat[1].z = v324;
      v361.mat[2].x = v325 + v319;
      v84 = v83->__vftable;
      v336.mat[1].x = v324;
      v84->DebugLine(
        this: v83,
        a2: (const idVec4 *)&idColor::colorGreen,
        a3: (const idVec3 *)&v323,
        a4: (const idVec3 *)&v361.mat[1].y,
        a5: 2000,
        a6: false);
      v85 = gameLocal->GetRenderWorld(this: gameLocal);
      v370[0] = v323;
      v370[1] = v324;
      v370[2] = v325;
      v370[3] = 10.0;
      v85->DebugSphere(
        this: v85,
        a2: (const idVec4 *)&idColor::colorGreen,
        a3: (const idSphere *)v370,
        a4: 10,
        a5: 1,
        a6: false);
      v80 = v325;
      v81 = v324;
      v82 = v323;
    }
    if ( (*((_BYTE *)&this->animDeltaCorrection.in + 40) & 0x80) != 0 )
      v86 = 1.0;
    else
      v86 = previousRemainingTranslationFrames;
    v336.mat[1].x = v86;
    HIDWORD(v311) = &this->animDeltaCorrection.animSpaceEndTranslation;
    v87 = *(float *)(LODWORD(v336.mat[2].z) + 4);
    v88 = *(float *)(LODWORD(v336.mat[2].z) + 8);
    v313.mat[0].x = *(float *)LODWORD(v336.mat[2].z);
    v313.mat[0].y = v87;
    v313.mat[0].z = v88;
    if ( v86 < 1.0 )
    {
      v89 = (float)(v308.z * (float)v86);
      v91 = (float)(v308.x * (float)v86);
      v90 = (float)(v308.y * (float)v86);
      v95 = (float)((float)(this->animDeltaCorrection.animSpaceEndTranslation.y - (float)v39)
                  + (float)((float)((float)1.0 - (float)v86) * v308.y));
      v96 = (float)((float)(this->animDeltaCorrection.animSpaceEndTranslation.z - (float)v42)
                  + (float)((float)((float)1.0 - (float)v86) * v308.z));
      v94 = -(float)((float)(p_animSpaceEndTranslation->x - (float)v34)
                   + (float)((float)((float)1.0 - (float)v86) * v308.x));
      v313.mat[0].x = (float)((float)((float)((float)1.0 - (float)v86) * v308.x) * (float)v79)
                    + (float)((float)((float)((float)((float)1.0 - (float)v86) * v308.y) * (float)v76)
                            + (float)((float)((float)((float)1.0 - (float)v86) * v308.z) * (float)v73));
      v313.mat[0].z = (float)((float)((float)((float)1.0 - (float)v86) * v308.z) * (float)v77)
                    + (float)((float)((float)((float)((float)1.0 - (float)v86) * v308.x) * (float)v74)
                            + (float)((float)((float)((float)1.0 - (float)v86) * v308.y) * (float)v71));
      v97 = (float)((float)((float)((float)((float)1.0 - (float)v86) * v308.z) * (float)v78)
                  + (float)((float)((float)((float)((float)1.0 - (float)v86) * v308.x) * (float)v75)
                          + (float)((float)((float)((float)1.0 - (float)v86) * v308.y) * (float)v72)));
      v308.z = v308.z * (float)v86;
      v308.y = v308.y * (float)v86;
      v308.x = v308.x * (float)v86;
      v92 = -v96;
      v313.mat[0].y = v97;
      v93 = -v95;
    }
    else
    {
      v89 = v308.z;
      v90 = v308.y;
      v91 = v308.x;
      v92 = (float)((float)(this->animDeltaCorrection.animSpaceEndTranslation.z - (float)v42) + v308.z);
      v93 = (float)((float)(this->animDeltaCorrection.animSpaceEndTranslation.y - (float)v39) + v308.y);
      v94 = (float)((float)(p_animSpaceEndTranslation->x - (float)v34) + v308.x);
    }
    v98 = __fabs(v92);
    v99 = __fsqrts((float)((float)((float)v94 * (float)v94) + (float)((float)v93 * (float)v93)));
    v100 = __fsqrts((float)((float)((float)v90 * (float)v90) + (float)((float)v91 * (float)v91)));
    if ( v86 < 1.0 )
    {
      v101 = 1.0;
    }
    else
    {
      if ( v99 <= 1.0 )
        v101 = (float)((float)1.0 / (float)v86);
      else
        v101 = (float)((float)v100 / (float)v99);
      if ( v98 <= v334 )
        v102 = (float)((float)1.0 / (float)v86);
      else
        v102 = (float)((float)__fabs(v89) / (float)v98);
      if ( v101 > 1.0 )
        v101 = 1.0;
      if ( v102 <= 1.0 )
        goto LABEL_69;
    }
    v102 = 1.0;
LABEL_69:
    v103 = this->ai;
    v105 = (float)((float)((float)((float)v92 * (float)v77)
                         + (float)((float)((float)v94 * (float)v74) + (float)((float)v93 * (float)v71)))
                 + v310.z);
    v330.mat[2].x = (float)((float)((float)v92 * (float)v77)
                          + (float)((float)((float)v94 * (float)v74) + (float)((float)v93 * (float)v71)))
                  + v310.z;
    v106 = (float)((float)((float)((float)v92 * (float)v78)
                         + (float)((float)((float)v94 * (float)v75) + (float)((float)v93 * (float)v72)))
                 + v310.y);
    v330.mat[1].z = (float)((float)((float)v92 * (float)v78)
                          + (float)((float)((float)v94 * (float)v75) + (float)((float)v93 * (float)v72)))
                  + v310.y;
    v104 = (float)((float)((float)v94 * (float)v79)
                 + (float)((float)((float)v93 * (float)v76) + (float)((float)v92 * (float)v73)));
    v107 = (float)((float)v104 + v310.x);
    v330.mat[1].y = (float)v104 + v310.x;
    if ( ai_debugAnimDeltaCorrection.valueInteger == v103->entityNumber
      && ai_debugAnimDeltaCorrectionType.valueInteger == 1 )
    {
      v108 = gameLocal->GetRenderWorld(this: gameLocal);
      v366.mat[2].z = v330.mat[1].y;
      v367 = v330.mat[1].z;
      v368 = v330.mat[2].x + v319;
      v109 = v108->__vftable;
      *(float *)&v311 = v330.mat[1].z;
      v109->DebugLine(
        this: v108,
        a2: (const idVec4 *)&idColor::colorBlue,
        a3: (const idVec3 *)&v330.mat[1].y,
        a4: (const idVec3 *)&v366.mat[2].z,
        a5: 2000,
        a6: false);
      v110 = gameLocal->GetRenderWorld(this: gameLocal);
      v371[1] = v330.mat[1].z;
      v371[0] = v330.mat[1].y;
      v371[2] = v330.mat[2].x;
      v371[3] = 10.0;
      v110->DebugSphere(
        this: v110,
        a2: (const idVec4 *)&idColor::colorBlue,
        a3: (const idSphere *)v371,
        a4: 12,
        a5: 1,
        a6: false);
      v89 = v308.z;
      v90 = v308.y;
      v91 = v308.x;
      v80 = v325;
      v81 = v324;
      v82 = v323;
      v105 = v330.mat[2].x;
      v106 = v330.mat[1].z;
      v107 = v330.mat[1].y;
    }
    v111 = v318.mat[2].y;
    v112 = v318.mat[2].x;
    v113 = v318.mat[1].y;
    v114 = *((_BYTE *)&this->animDeltaCorrection + 372) & 0x80;
    v115 = v318.mat[1].x;
    v116 = v318.mat[0].y;
    HIDWORD(v311) = &TreeAnimatorFromPresentable->g.scale;
    v117 = (float)(TreeAnimatorFromPresentable->g.scale.z * (float)v89);
    v118 = (float)(TreeAnimatorFromPresentable->g.scale.y * (float)v90);
    v119 = v318.mat[0].x;
    v120 = (float)(TreeAnimatorFromPresentable->g.scale.x * (float)v91);
    if ( v114 != 0 || (*((_BYTE *)&this->animDeltaCorrection + 112) & 0x80) != 0 )
    {
      v136 = (float)((float)v80 - (float)v105);
      v124 = (float)((float)v81 - (float)v106);
      v313.mat[2].x = v318.mat[0].z;
      v314 = v318.mat[1].z;
      v313.mat[1].y = v318.mat[0].x;
      v125 = (float)((float)v82 - (float)v107);
      v313.mat[1].z = v318.mat[0].y;
      v313.mat[2].y = v318.mat[1].x;
      v313.mat[2].z = v318.mat[1].y;
      v315 = v318.mat[2].x;
      v316 = v318.mat[2].y;
      v127 = (float)((float)((float)v81 - (float)v106) * (float)v101);
      v317 = v318.mat[2].z;
      v138 = (float)((float)((float)v120 * v318.mat[0].z) + (float)((float)v118 * v318.mat[1].z));
      v139 = (float)((float)((float)v120 * v318.mat[0].y) + (float)((float)v118 * v318.mat[1].y));
      v140 = (float)((float)(v318.mat[0].x * (float)v120) + (float)((float)v118 * v318.mat[1].x));
      v137 = (float)((float)v136 * (float)v102);
      v128 = (float)((float)v125 * (float)v101);
      v129 = v137;
      v130 = (float)((float)((float)v117 * v318.mat[2].z) + (float)v138);
      v131 = (float)((float)((float)v117 * v318.mat[2].y) + (float)v139);
      v132 = (float)((float)((float)v117 * v318.mat[2].x) + (float)v140);
    }
    else
    {
      v121 = (float)((float)(TreeAnimatorFromPresentable->g.scale.y * (float)v90) * v328.mat[1].z);
      v122 = *((_BYTE *)&this->animDeltaCorrection.in + 41) & 4;
      v314 = v328.mat[1].z;
      v313.mat[1].z = v328.mat[0].y;
      v313.mat[2].x = v328.mat[0].z;
      if ( v122 != 0 )
      {
        v123 = (float)((float)v80 - (float)v105);
        v124 = (float)((float)v81 - (float)v106);
        v315 = v328.mat[2].x;
        v313.mat[2].z = v328.mat[1].y;
        v125 = (float)((float)v82 - (float)v107);
        v313.mat[2].y = v328.mat[1].x;
        v316 = v328.mat[2].y;
        v317 = v328.mat[2].z;
        v313.mat[1].y = v328.mat[0].x;
        v127 = (float)((float)((float)v81 - (float)v106) * (float)v101);
        v126 = (float)((float)v123 * (float)v102);
        v128 = (float)((float)v125 * (float)v101);
        v129 = v126;
        v130 = (float)((float)((float)v117 * v328.mat[2].z)
                     + (float)((float)((float)v120 * v328.mat[0].z) + (float)((float)v118 * v328.mat[1].z)));
        v131 = (float)((float)((float)v117 * v328.mat[2].y)
                     + (float)((float)((float)v120 * v328.mat[0].y) + (float)((float)v118 * v328.mat[1].y)));
        v132 = (float)((float)(v328.mat[0].x * (float)v120)
                     + (float)((float)((float)v118 * v328.mat[1].x) + (float)((float)v117 * v328.mat[2].x)));
      }
      else
      {
        v133 = (float)((float)v118 * v328.mat[1].y);
        v124 = (float)((float)v81 - v310.y);
        v313.mat[2].z = v328.mat[1].y;
        v125 = (float)((float)v82 - v310.x);
        v315 = v328.mat[2].x;
        v313.mat[1].y = v328.mat[0].x;
        v134 = (float)((float)((float)v118 * v328.mat[1].x) + (float)((float)v117 * v328.mat[2].x));
        v313.mat[2].y = v328.mat[1].x;
        v316 = v328.mat[2].y;
        v317 = v328.mat[2].z;
        v130 = (float)((float)((float)v117 * v328.mat[2].z) + (float)((float)((float)v120 * v328.mat[0].z) + (float)v121));
        v132 = (float)((float)(v328.mat[0].x * (float)v120) + (float)v134);
        v131 = (float)((float)((float)v117 * v328.mat[2].y) + (float)((float)((float)v120 * v328.mat[0].y) + (float)v133));
        v127 = (float)((float)((float)((float)v81 - v310.y) * (float)v101)
                     - (float)((float)((float)v117 * v328.mat[2].y)
                             + (float)((float)((float)v120 * v328.mat[0].y) + (float)v133)));
        v135 = (float)((float)((float)v82 - v310.x) * (float)v101);
        v129 = (float)((float)((float)((float)v80 - v310.z) * (float)v102)
                     - (float)((float)((float)v117 * v328.mat[2].z)
                             + (float)((float)((float)v120 * v328.mat[0].z) + (float)v121)));
        v128 = (float)((float)v135 - (float)((float)(v328.mat[0].x * (float)v120) + (float)v134));
      }
    }
    v308.z = v130;
    v308.x = v132;
    v308.y = v131;
    v141 = idMath::FLT_SMALLEST_NON_DENORMAL;
    v312.mat[2].x = v129;
    v312.mat[1].y = v128;
    v142 = v124;
    v312.mat[1].z = v127;
    v143 = v125;
    if ( ((LODWORD(v308.x) | LODWORD(v308.y) | LODWORD(v308.z)) & 0x7FFFFFFF) != 0 )
    {
      translationCorrectionMaxScale = this->animDeltaCorrection.in.translationCorrectionMaxScale;
      *(float *)&v311 = this->animDeltaCorrection.in.translationCorrectionMaxScale;
      if ( __fabs(translationCorrectionMaxScale) >= v141 )
      {
        v145 = idVec3::NormalizeFast(this: (idVec3 *)&v312.mat[1].y);
        v146 = __fsqrts((float)((float)((float)v132 * (float)v132)
                              + (float)((float)((float)v130 * (float)v130) + (float)((float)v131 * (float)v131))));
        v147 = (float)((float)v145 / (float)v146);
        if ( v147 >= -translationCorrectionMaxScale )
        {
          if ( v147 > translationCorrectionMaxScale )
            v147 = translationCorrectionMaxScale;
        }
        else
        {
          v147 = -translationCorrectionMaxScale;
        }
        v148 = (float)((float)v147 * (float)v146);
        v128 = (float)((float)v148 * v312.mat[1].y);
        v312.mat[1].y = (float)v148 * v312.mat[1].y;
        v127 = (float)((float)v148 * v312.mat[1].z);
        v312.mat[1].z = (float)v148 * v312.mat[1].z;
        v129 = (float)((float)v148 * v312.mat[2].x);
        v312.mat[2].x = (float)v148 * v312.mat[2].x;
      }
    }
    v149 = (_cntlzw(__fabs(this->animDeltaCorrection.in.translationCorrectionPerFrameMax.y) < v141) & 0x20) != 0;
    v150 = (_cntlzw(__fabs(this->animDeltaCorrection.in.translationCorrectionPerFrameMax.x) < v141) & 0x20) != 0;
    v151 = (_cntlzw(__fabs(this->animDeltaCorrection.in.translationCorrectionPerFrameMax.z) < v141) & 0x20) != 0;
    if ( v150 || v149 || v151 )
    {
      v152 = (float *)idMat3::Inverse(this: &v380, result: (idMat3 *)&v313.mat[1].y);
      v153 = (float)((float)(*v152 * (float)v128)
                   + (float)((float)(v152[6] * (float)v129) + (float)(v152[3] * (float)v127)));
      v154 = (float)((float)(v152[2] * (float)v128)
                   + (float)((float)(v152[8] * (float)v129) + (float)(v152[5] * (float)v127)));
      v155 = (float)((float)(v152[1] * (float)v128)
                   + (float)((float)(v152[7] * (float)v129) + (float)(v152[4] * (float)v127)));
      if ( v150 )
      {
        v156 = this->animDeltaCorrection.in.translationCorrectionPerFrameMax.x;
        if ( v153 >= -v156 )
        {
          if ( v153 > v156 )
            v153 = this->animDeltaCorrection.in.translationCorrectionPerFrameMax.x;
        }
        else
        {
          v153 = -v156;
        }
      }
      if ( v151 )
      {
        v157 = this->animDeltaCorrection.in.translationCorrectionPerFrameMax.y;
        if ( v155 >= -v157 )
        {
          if ( v155 > v157 )
            v155 = this->animDeltaCorrection.in.translationCorrectionPerFrameMax.y;
        }
        else
        {
          v155 = -v157;
        }
      }
      if ( v149 )
      {
        v158 = this->animDeltaCorrection.in.translationCorrectionPerFrameMax.z;
        if ( v154 >= -v158 )
        {
          if ( v154 > v158 )
            v154 = this->animDeltaCorrection.in.translationCorrectionPerFrameMax.z;
        }
        else
        {
          v154 = -v158;
        }
      }
      v130 = v308.z;
      v131 = v308.y;
      v132 = v308.x;
      v141 = idMath::FLT_SMALLEST_NON_DENORMAL;
      v129 = (float)((float)((float)v154 * v317)
                   + (float)((float)((float)v153 * v313.mat[2].x) + (float)((float)v155 * v314)));
      v312.mat[2].x = (float)((float)v154 * v317)
                    + (float)((float)((float)v153 * v313.mat[2].x) + (float)((float)v155 * v314));
      v127 = (float)((float)((float)v154 * v316)
                   + (float)((float)((float)v153 * v313.mat[1].z) + (float)((float)v155 * v313.mat[2].z)));
      v312.mat[1].z = (float)((float)v154 * v316)
                    + (float)((float)((float)v153 * v313.mat[1].z) + (float)((float)v155 * v313.mat[2].z));
      v128 = (float)((float)(v313.mat[1].y * (float)v153)
                   + (float)((float)((float)v155 * v313.mat[2].y) + (float)((float)v154 * v315)));
      v312.mat[1].y = (float)(v313.mat[1].y * (float)v153)
                    + (float)((float)((float)v155 * v313.mat[2].y) + (float)((float)v154 * v315));
    }
    if ( (*((_BYTE *)&this->animDeltaCorrection + 372) & 0x10) == 0 )
    {
      *((_BYTE *)&this->animDeltaCorrection + 372) = (16
                                                    * (((LODWORD(v312.mat[1].y)
                                                       | LODWORD(v312.mat[1].z)
                                                       | LODWORD(v312.mat[2].x))
                                                      & 0x7FFFFFFF) != 0))
                                                   & 0x10
                                                   | *((_BYTE *)&this->animDeltaCorrection + 372) & 0xEF;
      v141 = idMath::FLT_SMALLEST_NON_DENORMAL;
    }
    v159 = __fabs(this->animDeltaCorrection.in.translationPerFrameMax.x);
    v308.x = v313.mat[0].x + (float)((float)v132 + (float)v128);
    v308.y = (float)((float)v131 + (float)v127) + v313.mat[0].y;
    v308.z = (float)((float)v129 + (float)v130) + v313.mat[0].z;
    v160 = (_cntlzw(__fabs(this->animDeltaCorrection.in.translationPerFrameMax.y) < v141) & 0x20) != 0;
    v161 = (_cntlzw(__fabs(this->animDeltaCorrection.in.translationPerFrameMax.z) < v141) & 0x20) != 0;
    if ( (_cntlzw(v159 < v141) & 0x20) != 0 || v160 || v161 )
    {
      v162 = (float *)idMat3::Inverse(this: &v380, result: (idMat3 *)&v313.mat[1].y);
      v163 = this->animDeltaCorrection.in.translationPerFrameMax.x;
      v164 = idMath::FLT_SMALLEST_NON_DENORMAL;
      v165 = (float)((float)(v162[8] * v308.z) + (float)((float)(v162[5] * v308.y) + (float)(v162[2] * v308.x)));
      v166 = (float)((float)(*v162 * v308.x) + (float)((float)(v162[3] * v308.y) + (float)(v162[6] * v308.z)));
      v167 = (float)((float)(v162[7] * v308.z) + (float)((float)(v162[4] * v308.y) + (float)(v162[1] * v308.x)));
      v168 = v166;
      v169 = v167;
      *(float *)&v311 = this->animDeltaCorrection.in.translationPerFrameMax.x;
      if ( __fabs(v163) >= idMath::FLT_SMALLEST_NON_DENORMAL )
      {
        if ( v166 >= -v163 )
        {
          if ( v166 <= v163 )
            v163 = v166;
        }
        else
        {
          v163 = -v163;
        }
        v168 = v163;
      }
      v170 = this->animDeltaCorrection.in.translationPerFrameMax.y;
      *(float *)&v311 = this->animDeltaCorrection.in.translationPerFrameMax.y;
      if ( __fabs(v170) >= v164 )
      {
        if ( v167 >= -v170 )
        {
          if ( v167 <= v170 )
            v170 = v167;
        }
        else
        {
          v170 = -v170;
        }
        v169 = v170;
      }
      v171 = this->animDeltaCorrection.in.translationPerFrameMax.z;
      *(float *)&v311 = this->animDeltaCorrection.in.translationPerFrameMax.z;
      if ( __fabs(v171) >= v164 )
      {
        if ( v165 >= -v171 )
        {
          if ( v165 <= v171 )
            v171 = v165;
        }
        else
        {
          v171 = -v171;
        }
        v165 = v171;
      }
      v308.z = (float)((float)v165 * v317) + (float)((float)((float)v168 * v313.mat[2].x) + (float)((float)v169 * v314));
      v308.y = (float)((float)v165 * v316)
             + (float)((float)((float)v168 * v313.mat[1].z) + (float)((float)v169 * v313.mat[2].z));
      v308.x = (float)(v313.mat[1].y * (float)v168)
             + (float)((float)((float)v169 * v313.mat[2].y) + (float)((float)v165 * v315));
    }
    if ( ai_debugAnimDeltaCorrection.valueInteger == this->ai->entityNumber
      && ai_debugAnimDeltaCorrectionType.valueInteger == 1 )
    {
      idLib::Printf(
        fmt: (const char *)(const char *)HIDWORD(COERCE_UNSIGNED_INT64(v336.mat[0].x)),
        (unsigned int)COERCE_UNSIGNED_INT64(v336.mat[0].x),
        (unsigned int)COERCE_UNSIGNED_INT64(v336.mat[0].y));
      idLib::Printf(fmt: (const char *)HIDWORD(v94), LODWORD(v94), LODWORD(v93), v94, v93);
      idLib::Printf(fmt: "translation errors :                              %f      %f  \n", v143, v142);
      idLib::Printf(fmt: "translation correction :\t\t\t %f      %f  \n", v128, v127);
      idLib::Printf(
        fmt: (const char *)(const char *)HIDWORD(COERCE_UNSIGNED_INT64((float)(v330.mat[2].z - v310.x))),
        (unsigned int)COERCE_UNSIGNED_INT64((float)(v330.mat[2].z - v310.x)),
        (unsigned int)COERCE_UNSIGNED_INT64((float)(v331 - v310.y)));
      v172 = (float)((float)((float)(v345 * (float)v111)
                           + (float)((float)(v361.mat[0].x * (float)v116) + (float)(v344 * (float)v113)))
                   + v308.y);
      idLib::Printf(
        fmt: (const char *)(const char *)HIDWORD(COERCE_UNSIGNED_INT64((float)((float)((float)((float)v119 * v361.mat[0].x)
                                                                                + (float)((float)(v344 * (float)v115)
                                                                                        + (float)(v345 * (float)v112)))
                                                                        + v308.x))),
        HIDWORD(v172),
        LODWORD(v172));
      v307 = v308.x;
      idLib::Printf(
        fmt: (const char *)(HIDWORD(v307) - 9532),
        (unsigned int)COERCE_UNSIGNED_INT64(v308.x),
        (unsigned int)COERCE_UNSIGNED_INT64(v308.y));
      idLib::Printf(
        fmt: (const char *)(const char *)HIDWORD(COERCE_UNSIGNED_INT64(v336.mat[1].x)),
        (unsigned int)COERCE_UNSIGNED_INT64(v336.mat[1].x));
      v173 = gameLocal->GetRenderWorld(this: gameLocal);
      v357[1] = v331;
      *(float *)&v311 = v331;
      v357[0] = v330.mat[2].z;
      v357[2] = v332 + (float)300.0;
      v173->DebugLine(
        this: v173,
        a2: (const idVec4 *)&idColor::colorRed,
        a3: (const idVec3 *)&v330.mat[2].z,
        a4: (const idVec3 *)v357,
        a5: 2000,
        a6: false);
      v174 = gameLocal->GetRenderWorld(this: gameLocal);
      v373[2] = v332;
      v373[0] = v330.mat[2].z;
      v373[3] = *(float *)&v309;
      v373[1] = v331;
      v174->DebugSphere(
        this: v174,
        a2: (const idVec4 *)&idColor::colorRed,
        a3: (const idSphere *)v373,
        a4: 12,
        a5: 1,
        a6: false);
      v320 = v310.x + v308.x;
      v321 = v308.y + v310.y;
      v322 = v308.z + v310.z;
      v175 = gameLocal->GetRenderWorld(this: gameLocal);
      v358[0] = v320;
      v358[1] = v321;
      v358[2] = v322 + v312.mat[1].x;
      v176 = v175->__vftable;
      *(float *)&v311 = v321;
      v176->DebugLine(
        this: v175,
        a2: (const idVec4 *)&idColor::colorOrange,
        a3: (const idVec3 *)&v320,
        a4: (const idVec3 *)v358,
        a5: 2000,
        a6: false);
      if ( ((LODWORD(v313.mat[0].x) | LODWORD(v313.mat[0].y) | LODWORD(v313.mat[0].z)) & 0x7FFFFFFF) != 0 )
      {
        v321 = v321 - v313.mat[0].y;
        v320 = v320 - v313.mat[0].x;
        v322 = v322 - v313.mat[0].z;
        v177 = gameLocal->GetRenderWorld(this: gameLocal);
        v360[2] = v322 + v312.mat[1].x;
        v360[0] = v320;
        v360[1] = v321;
        *(float *)&v311 = v321;
        v177->DebugLine(
          this: v177,
          a2: (const idVec4 *)&idColor::colorWhite,
          a3: (const idVec3 *)&v320,
          a4: (const idVec3 *)v360,
          a5: 2000,
          a6: false);
      }
    }
    goto LABEL_139;
  }
  if ( (*((_BYTE *)&this->animDeltaCorrection + 72) & 0x40) != 0 )
  {
    idStr::Append(this: &v355, text: " a_trans");
    v178 = TreeAnimatorFromPresentable;
    v179 = this->ai;
    v180 = TreeAnimatorFromPresentable->g.scale.z;
    v181 = (float)(TreeAnimatorFromPresentable->g.scale.z * v308.z);
    HIDWORD(v311) = &TreeAnimatorFromPresentable->g.scale;
    v182 = (float)((float)((float)(v308.x * v178->g.scale.x) * (float)v51)
                 + (float)((float)(v178->g.scale.y * v308.y) * (float)v54));
    v183 = (float)((float)((float)(v308.x * v178->g.scale.x) * (float)v50)
                 + (float)((float)((float)(v178->g.scale.y * v308.y) * (float)v53)
                         + (float)((float)((float)v180 * v308.z) * (float)v56)));
    v184 = (float)((float)((float)v181 * (float)v58)
                 + (float)((float)((float)(v308.x * v178->g.scale.x) * (float)v52)
                         + (float)((float)(v178->g.scale.y * v308.y) * (float)v55)));
    v308.z = (float)((float)v181 * (float)v58)
           + (float)((float)((float)(v308.x * v178->g.scale.x) * (float)v52)
                   + (float)((float)(v178->g.scale.y * v308.y) * (float)v55));
    v308.x = v183;
    v185 = (float)((float)((float)v181 * (float)v57) + (float)v182);
    v308.y = v185;
    if ( ai_debugAnimDeltaCorrection.valueInteger == v179->entityNumber
      && ai_debugAnimDeltaCorrectionType.valueInteger == 1 )
    {
      v340 = (float)v185 + v310.y;
      v339 = (float)v183 + v310.x;
      v341 = (float)v184 + v310.z;
      v186 = gameLocal->GetRenderWorld(this: gameLocal);
      v356[2] = v341 + (float)250.0;
      v356[1] = v340;
      v356[0] = v339;
      *(float *)&v311 = v340;
      v186->DebugLine(
        this: v186,
        a2: (const idVec4 *)&idColor::colorRed,
        a3: (const idVec3 *)&v339,
        a4: (const idVec3 *)v356,
        a5: 2000,
        a6: false);
      idAnimBaseFSM::GetDeltaCorrectionGoalOrigin(this: (idAnimBaseFSM *)&v336.mat[1].y, result: (idVec3 *)this);
      v187 = gameLocal->GetRenderWorld(this: gameLocal);
      v366.mat[1].y = v336.mat[1].y;
      v366.mat[1].z = v336.mat[1].z;
      *(float *)&v311 = v336.mat[1].z;
      v366.mat[2].x = v336.mat[2].x + (float)300.0;
      v187->DebugLine(
        this: v187,
        a2: (const idVec4 *)&idColor::colorWhite,
        a3: (const idVec3 *)&v336.mat[1].y,
        a4: (const idVec3 *)&v366.mat[1].y,
        a5: 2000,
        a6: false);
      v188 = gameLocal->GetRenderWorld(this: gameLocal);
      v372[2] = v336.mat[2].x;
      v372[0] = v336.mat[1].y;
      v372[1] = v336.mat[1].z;
      v372[3] = 10.0;
      v188->DebugSphere(
        this: v188,
        a2: (const idVec4 *)&idColor::colorWhite,
        a3: (const idSphere *)v372,
        a4: 12,
        a5: 2000,
        a6: false);
      animData = this->animDeltaCorrection.anim->animData;
      if ( animData != nullptr )
        animData = (idMD6AnimData *)((char *)animData + 80);
      v190 = (float)((float)((float)((float)(animData->startDelta[0] - (float)v34) * (float)v50)
                           + (float)((float)((float)(animData->startDelta[1] - (float)v39) * (float)v53)
                                   + (float)((float)(animData->startDelta[2] - (float)v42) * (float)v56)))
                   + v308.x);
      v191 = (float)((float)((float)((float)(animData->startDelta[2] - (float)v42) * (float)v57)
                           + (float)((float)((float)(animData->startDelta[0] - (float)v34) * (float)v51)
                                   + (float)((float)(animData->startDelta[1] - (float)v39) * (float)v54)))
                   + v308.y);
      HIDWORD(v311) = animData->startDelta;
      idLib::Printf(fmt: (const char *)HIDWORD(v190), HIDWORD(v191), LODWORD(v191), v190, v191);
      v192 = (float)(v336.mat[1].y - v310.x);
      v193 = (float)(v336.mat[1].z - v310.y);
      idLib::Printf(fmt: (const char *)HIDWORD(v192), HIDWORD(v193), LODWORD(v193), v192, v193);
      idLib::Printf(
        fmt: "accumulated error :\t%f      %f  \n",
        (float)((float)v192 - (float)v190),
        (float)((float)v193 - (float)v191));
      idLib::Printf(fmt: "delta this frame : %f      %f  \n", v308.x, v308.y);
      idLib::Printf(
        fmt: (const char *)(const char *)HIDWORD(COERCE_UNSIGNED_INT64((float)(v310.x - prevOrigin.x))),
        (unsigned int)COERCE_UNSIGNED_INT64((float)(v310.x - prevOrigin.x)),
        (unsigned int)COERCE_UNSIGNED_INT64((float)(v310.y - prevOrigin.y)));
      prevOrigin.x = v310.x;
      prevOrigin.y = v310.y;
      prevOrigin.z = v310.z;
    }
  }
  else
  {
    idStr::Append(this: &v355, text: " n_trans");
  }
LABEL_139:
  if ( LODWORD(v312.mat[2].y) == 0 || (*((_BYTE *)&this->animDeltaCorrection + 72) & 0x80) == 0 )
  {
    v194 = v336.mat[2].y;
    v195 = v334;
    goto LABEL_232;
  }
  v194 = v336.mat[2].y;
  v195 = v334;
  if ( v336.mat[2].y < (double)v334 )
  {
LABEL_232:
    idStr::Append(this: &v355, text: " n_rot");
    v264 = idMat3::Inverse(this: &v377, result: &v326);
    v326.mat[0].x = v264->mat[0].x;
    v217 = v333;
    v212 = v335;
    v210 = v319;
    v309 = &v264->mat[2];
    v326.mat[0].y = v264->mat[0].y;
    v326.mat[0].z = v264->mat[0].z;
    v326.mat[1] = v264->mat[1];
    v326.mat[2] = v264->mat[2];
    goto LABEL_233;
  }
  idStr::Append(this: &v355, text: " c_rot");
  idAnimBaseFSM::deltaCorrectionGoalRotationParms_t::deltaCorrectionGoalRotationParms_t(this: &v376);
  v376.sourcePosition.x = v310.x;
  v376.sourcePosition.y = v310.y;
  v376.sourcePosition.z = v310.z;
  v376.sourceAxis.mat[0].x = v328.mat[0].x;
  v376.sourceAxis.mat[0].y = v328.mat[0].y;
  v376.sourceAxis.mat[0].z = v328.mat[0].z;
  v376.sourceAxis.mat[1].x = v328.mat[1].x;
  v376.sourceAxis.mat[1].y = v328.mat[1].y;
  v376.sourceAxis.mat[1].z = v328.mat[1].z;
  v376.sourceAxis.mat[2].x = v328.mat[2].x;
  v376.sourceAxis.mat[2].y = v328.mat[2].y;
  v376.sourceAxis.mat[2].z = v328.mat[2].z;
  v196 = idMat3::Inverse(this: &v378, result: &v338);
  v197 = idMat3::operator*(this: &v381, result: &v328, a: v196);
  v198 = idMat3::operator*(this: &v375, result: v197, a: &this->animDeltaCorrection.animSpaceGoalRotation);
  v199 = (float)(this->animDeltaCorrection.animSpaceGoalRotation_Translation.y - v336.mat[0].y);
  v200 = (float)(this->animDeltaCorrection.animSpaceGoalRotation_Translation.x - v336.mat[0].x);
  v376.worldSpaceAnimGoalAxis.mat[0].x = v198->mat[0].x;
  v309 = &v198->mat[1];
  v201 = this->ai;
  v202 = (float)(this->animDeltaCorrection.animSpaceGoalRotation_Translation.z - v336.mat[0].z);
  v309 = &v198->mat[2];
  v376.worldSpaceAnimGoalAxis.mat[0].y = v198->mat[0].y;
  v376.worldSpaceAnimGoalAxis.mat[0].z = v198->mat[0].z;
  HIDWORD(v311) = &this->animDeltaCorrection.animSpaceGoalRotation_Translation;
  v376.worldSpaceAnimGoalAxis.mat[1] = v198->mat[1];
  v376.worldSpaceAnimGoalAxis.mat[2] = v198->mat[2];
  v376.worldSpaceAnimGoalOrigin.z = (float)((float)((float)((float)((float)v202 * v338.mat[2].z)
                                                          + (float)((float)((float)v200 * v338.mat[0].z)
                                                                  + (float)((float)v199 * v338.mat[1].z)))
                                                  * v328.mat[2].z)
                                          + (float)((float)((float)((float)((float)v202 * v338.mat[2].x)
                                                                  + (float)((float)(v338.mat[0].x * (float)v200)
                                                                          + (float)((float)v199 * v338.mat[1].x)))
                                                          * v328.mat[0].z)
                                                  + (float)((float)((float)((float)v202 * v338.mat[2].y)
                                                                  + (float)((float)((float)v200 * v338.mat[0].y)
                                                                          + (float)((float)v199 * v338.mat[1].y)))
                                                          * v328.mat[1].z)))
                                  + v310.z;
  v376.worldSpaceAnimGoalOrigin.y = (float)((float)((float)((float)((float)v202 * v338.mat[2].z)
                                                          + (float)((float)((float)v200 * v338.mat[0].z)
                                                                  + (float)((float)v199 * v338.mat[1].z)))
                                                  * v328.mat[2].y)
                                          + (float)((float)((float)((float)((float)v202 * v338.mat[2].x)
                                                                  + (float)((float)(v338.mat[0].x * (float)v200)
                                                                          + (float)((float)v199 * v338.mat[1].x)))
                                                          * v328.mat[0].y)
                                                  + (float)((float)((float)((float)v202 * v338.mat[2].y)
                                                                  + (float)((float)((float)v200 * v338.mat[0].y)
                                                                          + (float)((float)v199 * v338.mat[1].y)))
                                                          * v328.mat[1].y)))
                                  + v310.y;
  v376.worldSpaceAnimGoalOrigin.x = (float)((float)((float)((float)((float)v202 * v338.mat[2].z)
                                                          + (float)((float)((float)v200 * v338.mat[0].z)
                                                                  + (float)((float)v199 * v338.mat[1].z)))
                                                  * v328.mat[2].x)
                                          + (float)((float)((float)((float)((float)v202 * v338.mat[2].x)
                                                                  + (float)((float)(v338.mat[0].x * (float)v200)
                                                                          + (float)((float)v199 * v338.mat[1].x)))
                                                          * v328.mat[0].x)
                                                  + (float)((float)((float)((float)v202 * v338.mat[2].y)
                                                                  + (float)((float)((float)v200 * v338.mat[0].y)
                                                                          + (float)((float)v199 * v338.mat[1].y)))
                                                          * v328.mat[1].x)))
                                  + v310.x;
  v376.debug = (_cntlzw(v201->entityNumber - ai_debugAnimDeltaCorrection.valueInteger) & 0x20) != 0;
  idAnimBaseFSM::GetDeltaCorrectionGoalRotation(this: (idAnimBaseFSM *)&v379, result: this, parms: &v376);
  idMat3::ToAngles(this: &v361, result: (idAngles *)&v379);
  idMat3::ToAngles(this: (idMat3 *)&v384.mat[2].z, result: (idAngles *)&this->animDeltaCorrection.animSpaceEndRotation);
  idMat3::ToAngles(this: (idMat3 *)&v385.mat[1].y, result: (idAngles *)&this->animDeltaCorrection.animSpaceGoalRotation);
  v203 = idMat3::Inverse(this: &v375, result: &this->animDeltaCorrection.animSpaceEndRotation);
  idMat3::operator*(this: v387, result: v203, a: &this->animDeltaCorrection.animSpaceGoalRotation);
  idMat3::ToAngles(this: &v385, result: (idAngles *)v387);
  v204 = idMat3::Inverse(this: &v375, result: &v328);
  v205 = idMat3::Inverse(this: &v381, result: v387);
  v206 = idMat3::operator*(this: &v378, result: &v328, a: v205);
  idMat3::operator*(this: (idMat3 *)&v313.mat[1].y, result: v206, a: v204);
  idMat3::ToAngles(this: (idMat3 *)&v386.mat[1].y, result: (idAngles *)&v313.mat[1].y);
  v207 = idMat3::Inverse(this: &v375, result: (idMat3 *)&v313.mat[1].y);
  idMat3::operator*(this: &v383, result: v207, a: &v379);
  idMat3::ToAngles(this: (idMat3 *)&v384.mat[1].y, result: (idAngles *)&v383);
  if ( ai_debugAnimDeltaCorrection.valueInteger == this->ai->entityNumber
    && ai_debugAnimDeltaCorrectionType.valueInteger == 2 )
  {
    v208 = idMat3::Inverse(this: &v375, result: (idMat3 *)&v313.mat[1].y);
    idMat3::operator*(this: &v378, result: v208, a: &v379);
    v209 = gameLocal->GetRenderWorld(this: gameLocal);
    v210 = v319;
    v369[1] = (float)(v378.mat[0].y * v319) + v310.y;
    v369[2] = (float)(v378.mat[0].z * v319) + v310.z;
    v369[0] = (float)(v378.mat[0].x * v319) + v310.x;
    ((void (__fastcall *)(idRenderWorld *, idColor *, idVec3 *, float *, double))v209->DebugArrow)(
      a1: v209,
      a2: &idColor::colorCyan,
      a3: &v310,
      a4: v369,
      a5: 2.0);
    v211 = gameLocal->GetRenderWorld(this: gameLocal);
    v361.mat[2].z = v310.x + (float)(v379.mat[0].x * v312.mat[1].x);
    v363 = (float)(v379.mat[0].z * v312.mat[1].x) + v310.z;
    v362 = (float)(v379.mat[0].y * v312.mat[1].x) + v310.y;
    ((void (__fastcall *)(idRenderWorld *, idColor *, idVec3 *, float *, double))v211->DebugArrow)(
      a1: v211,
      a2: &idColor::colorGreen,
      a3: &v310,
      a4: &v361.mat[2].z,
      a5: 2.0);
  }
  else
  {
    v210 = v319;
  }
  v212 = v335;
  if ( (*((_BYTE *)&this->animDeltaCorrection.in + 40) & 4) != 0 )
    v213 = v335;
  else
    v213 = v194;
  idMat3::ToAngles(this: &v330, result: (idAngles *)&mat3_identity);
  if ( v213 < v212 )
  {
    v366.mat[0].z = v312.mat[0].z * (float)v213;
    v366.mat[0].y = v312.mat[0].y * (float)v213;
    v366.mat[0].x = v312.mat[0].x * (float)v213;
    v330.mat[0].z = v312.mat[0].z * (float)((float)v212 - (float)v213);
    v330.mat[0].y = v312.mat[0].y * (float)((float)v212 - (float)v213);
    v330.mat[0].x = v312.mat[0].x * (float)((float)v212 - (float)v213);
    v218 = idAngles::ToMat3(this: (idAngles *)&v375, result: &v366);
    v309 = &v218->mat[2];
    v326 = *v218;
    v219 = idMat3::Inverse(this: &v381, result: &this->animDeltaCorrection.animSpaceEndRotation);
    v220 = idAngles::ToMat3(this: (idAngles *)&v375, result: &v330);
    v221 = idMat3::Inverse(this: &v378, result: v220);
    v222 = idMat3::operator*(this: &v382, result: v221, a: v219);
    v223 = idMat3::operator*(this: &v377, result: v222, a: &v338);
    v342.mat[0].x = v223->mat[0].x;
    v342.mat[0].y = v223->mat[0].y;
    v309 = &v223->mat[1];
    v342.mat[0].z = v223->mat[0].z;
    v309 = &v223->mat[2];
    v342.mat[1] = v223->mat[1];
    v342.mat[2] = v223->mat[2];
    v217 = v333;
    v330.mat[0].x = v330.mat[0].x * v333;
    v330.mat[0].y = v330.mat[0].y * v333;
    v330.mat[0].z = v330.mat[0].z * v333;
  }
  else
  {
    v214 = idMat3::Inverse(this: &v375, result: &v338);
    v215 = idMat3::operator*(this: &v381, result: &v326, a: v214);
    v216 = idMat3::operator*(this: &v378, result: v215, a: &this->animDeltaCorrection.animSpaceEndRotation);
    v342.mat[0].x = v216->mat[0].x;
    v217 = v333;
    v309 = &v216->mat[2];
    v342.mat[0].y = v216->mat[0].y;
    v342.mat[0].z = v216->mat[0].z;
    v342.mat[1] = v216->mat[1];
    v342.mat[2] = v216->mat[2];
  }
  idMat3::ToAngles(this: &v318, result: (idAngles *)&v342);
  v224 = idMat3::Inverse(this: &v377, result: &v328);
  v225 = idMat3::Inverse(this: &v382, result: &v342);
  v226 = idMat3::operator*(this: &v375, result: &v328, a: v225);
  v227 = idMat3::operator*(this: &v381, result: v226, a: v224);
  v309 = &v227->mat[2];
  v374 = *v227;
  idMat3::ToAngles(this: (idMat3 *)&v312.mat[1].y, result: (idAngles *)&v374);
  v228 = idMat3::Inverse(this: &v377, result: &v328);
  v229 = idMat3::Inverse(this: &v382, result: &v374);
  v230 = idMat3::operator*(this: &v375, result: v229, a: v228);
  idMat3::operator*(this: &v380, result: v230, a: &v383);
  idMat3::ToAngles(this: &v313, result: (idAngles *)&v380);
  v231 = idMat3::Inverse(this: &v377, result: &v326);
  v309 = &v231->mat[2];
  v326 = *v231;
  v312.mat[0] = (idVec3)*idMat3::ToAngles(this: &v336, result: (idAngles *)&v326);
  if ( v213 < v212 )
    v232 = v212;
  else
    v232 = v213;
  rotationRateMax = this->animDeltaCorrection.in.rotationRateMax;
  GetGameMsPerFrame = (int (*)(void))gameLocal->GetGameMsPerFrame;
  if ( __fabs(rotationRateMax) < idMath::FLT_SMALLEST_NON_DENORMAL )
  {
    v311 = __PAIR64__(&unk_82390000, GetGameMsPerFrame());
    v236 = (float)((float)((float)v311 * (float)0.001) * (float)360.0);
  }
  else
  {
    v311 = __PAIR64__(&unk_82390000, GetGameMsPerFrame());
    v236 = (float)((float)((float)v311 * (float)rotationRateMax) * (float)0.001);
  }
  v237 = v312.mat[0].y;
  v238 = idMath::FLT_SMALLEST_NON_DENORMAL;
  if ( (*((_BYTE *)&this->animDeltaCorrection.in + 41) & 0x40) == 0 )
    goto LABEL_189;
  v239 = v312.mat[1].z;
  *(_DWORD *)&v235[8] = abs32((int)v312.mat[1].z);
  v311 = *(_QWORD *)&v235[4];
  if ( (float)*(__int64 *)&v235[4] >= 0.5 || (v240 = 1, __fabs(v237) >= v238) )
    v240 = 0;
  v241 = v313.mat[0].y;
  v242 = v240;
  v243 = (unsigned __int8)SameSignRelaxed(x: v313.mat[0].y, y: v312.mat[1].z, t: 5.0);
  if ( v243 == 0 && (*((_BYTE *)&this->animDeltaCorrection.in + 40) & 8) != 0 )
    goto LABEL_189;
  if ( __fabs(v239) >= v238 && v242 == 0 && (*((_BYTE *)&this->animDeltaCorrection.in + 40) & 4) == 0 )
  {
    if ( (*((_BYTE *)&this->animDeltaCorrection.in + 40) & 0x40) != 0 && v243 == 0 )
    {
      if ( v241 >= v195 )
        v241 = (float)((float)v241 - (float)360.0);
      else
        v241 = (float)((float)v241 + (float)360.0);
      v313.mat[0].y = v241;
    }
    if ( v213 >= v212 )
    {
      v244 = (float)((float)v237 / (float)v239);
      if ( v244 < v195 )
      {
        v244 = v195;
LABEL_178:
        v245 = (float)((float)v244 * (float)v241);
        v246 = this->ai;
        v237 = (float)((float)((float)v244 * (float)v241) + (float)v237);
        v312.mat[0].y = v237;
        if ( ai_debugAnimDeltaCorrection.valueInteger == v246->entityNumber
          && ai_debugAnimDeltaCorrectionType.valueInteger == 2 )
        {
          idLib::Printf(fmt: "rotation yaw error :                               %f      \n", v241);
          idLib::Printf(fmt: "rotation yaw correction :\t\t\t%f      \n", v245);
          idLib::Printf(fmt: "rotation yaw delta : %f        \n", v312.mat[0].y);
LABEL_188:
          v238 = idMath::FLT_SMALLEST_NON_DENORMAL;
          v237 = v312.mat[0].y;
          goto LABEL_189;
        }
        goto LABEL_189;
      }
      if ( v244 <= v212 )
        goto LABEL_178;
    }
    v244 = v212;
    goto LABEL_178;
  }
  v247 = (float)((float)v241 / (float)v232);
  if ( v247 >= -v236 )
  {
    if ( v247 > v236 )
      v247 = v236;
  }
  else
  {
    v247 = -v236;
  }
  v237 = (float)((float)v247 + (float)v237);
  v312.mat[0].y = v237;
  if ( ai_debugAnimDeltaCorrection.valueInteger == this->ai->entityNumber
    && ai_debugAnimDeltaCorrectionType.valueInteger == 2 )
  {
    idLib::Printf(fmt: (const char *)HIDWORD(v241), LODWORD(v241), v241);
    idLib::Printf(fmt: "LERP -- NO SCALE :\t\t\t\t\t    \n");
    idLib::Printf(
      fmt: (const char *)(const char *)HIDWORD(COERCE_UNSIGNED_INT64(v312.mat[0].y)),
      (unsigned int)COERCE_UNSIGNED_INT64(v312.mat[0].y));
    goto LABEL_188;
  }
LABEL_189:
  v248 = *((_BYTE *)&this->animDeltaCorrection.in + 41);
  if ( (v248 & 0x20) == 0 )
    goto LABEL_207;
  *(_DWORD *)&v235[4] = abs32((int)v312.mat[1].y);
  v311 = *(_QWORD *)v235;
  if ( (float)*(__int64 *)v235 >= 0.5 || (v249 = 1, __fabs(v312.mat[0].x) >= v238) )
    v249 = 0;
  if ( __fabs(v312.mat[1].y) < v238 || v249 != 0 || (*((_BYTE *)&this->animDeltaCorrection.in + 40) & 4) != 0 )
  {
    v251 = (float)(v313.mat[0].x / (float)v232);
    if ( v251 >= -v236 )
    {
      if ( v251 > v236 )
        v251 = v236;
    }
    else
    {
      v251 = -v236;
    }
    v312.mat[0].x = (float)v251 + v312.mat[0].x;
  }
  else
  {
    if ( v213 < v212 )
      goto LABEL_200;
    v250 = (float)(v312.mat[0].x / v312.mat[1].y);
    if ( v250 < v195 )
    {
      v312.mat[0].x = (float)(v313.mat[0].x * (float)v195) + v312.mat[0].x;
      goto LABEL_207;
    }
    if ( v250 > v212 )
LABEL_200:
      v250 = v212;
    v312.mat[0].x = (float)(v313.mat[0].x * (float)v250) + v312.mat[0].x;
  }
LABEL_207:
  if ( (v248 & 0x10) != 0 )
  {
    if ( v312.mat[2].x >= 0.5 || (v252 = 1, __fabs(v312.mat[0].z) >= v238) )
      v252 = 0;
    if ( __fabs(v312.mat[2].x) < v238 || v252 != 0 || (*((_BYTE *)&this->animDeltaCorrection.in + 40) & 4) != 0 )
    {
      v254 = (float)(v313.mat[0].z / (float)v232);
      if ( v254 >= -v236 )
      {
        if ( v254 > v236 )
          v254 = v236;
      }
      else
      {
        v254 = -v236;
      }
      v312.mat[0].z = v312.mat[0].z + (float)v254;
      goto LABEL_225;
    }
    if ( v213 < v212 )
      goto LABEL_218;
    v253 = (float)(v312.mat[0].z / v312.mat[2].x);
    if ( v253 < v195 )
    {
      v312.mat[0].z = (float)((float)v195 * v313.mat[0].z) + v312.mat[0].z;
      goto LABEL_225;
    }
    if ( v253 > v212 )
LABEL_218:
      v253 = v212;
    v312.mat[0].z = (float)((float)v253 * v313.mat[0].z) + v312.mat[0].z;
  }
LABEL_225:
  if ( (*((_BYTE *)&this->animDeltaCorrection + 372) & 0x10) == 0 )
    *((_BYTE *)&this->animDeltaCorrection + 372) = (16
                                                  * (((LODWORD(v312.mat[0].y)
                                                     | LODWORD(v312.mat[0].z)
                                                     | LODWORD(v312.mat[0].x))
                                                    & 0x7FFFFFFF) != 0))
                                                 & 0x10
                                                 | *((_BYTE *)&this->animDeltaCorrection + 372) & 0xEF;
  v312.mat[0].x = v312.mat[0].x + v330.mat[0].x;
  v312.mat[0].y = (float)v237 + v330.mat[0].y;
  v312.mat[0].z = v312.mat[0].z + v330.mat[0].z;
  v255 = idAngles::ToMat3(this: (idAngles *)&v377, result: &v312);
  v326.mat[0].x = v255->mat[0].x;
  v256 = this->ai;
  v309 = &v255->mat[2];
  v326.mat[0].y = v255->mat[0].y;
  v326.mat[0].z = v255->mat[0].z;
  v326.mat[1] = v255->mat[1];
  v326.mat[2] = v255->mat[2];
  if ( ai_debugAnimDeltaCorrection.valueInteger == v256->entityNumber
    && ai_debugAnimDeltaCorrectionType.valueInteger == 2 )
  {
    idLib::Printf(fmt: (const char *)HIDWORD(v213), LODWORD(v213), v213);
    if ( v213 < v212 )
    {
      v257 = gameLocal->GetRenderWorld(this: gameLocal);
      v258 = idAngles::ToMat3(this: (idAngles *)&v377, result: &v330);
      v259 = idMat3::Inverse(this: &v382, result: v258);
      v260 = idMat3::operator*(this: &v375, result: &v326, a: v259);
      v261 = idMat3::operator*(this: &v381, result: v260, a: &v328);
      v262 = (float)(v261->mat[0].x * (float)v210);
      v263 = (float)(v261->mat[0].z * (float)v210);
      v364[1] = v310.y + (float)(v261->mat[0].y * (float)v210);
      v364[0] = v310.x + (float)v262;
      v364[2] = v310.z + (float)v263;
      v257->DebugLine(
        this: v257,
        a2: (const idVec4 *)&idColor::colorWhite,
        a3: &v310,
        a4: (const idVec3 *)v364,
        a5: 1,
        a6: false);
    }
  }
LABEL_233:
  v265 = (float *)idMat3::operator*(this: &v377, result: &v326, a: &v328);
  v266 = *v265;
  v346.mat[0].x = *v265;
  v267 = *((_BYTE *)&this->animDeltaCorrection + 72) & 0x40;
  v309 = (idVec3 *)(v265 + 6);
  v268 = v265[1];
  v346.mat[0].y = v265[1];
  v269 = v265[2];
  v346.mat[0].z = v265[2];
  v270 = v265[3];
  v346.mat[1].x = v265[3];
  v271 = v265[4];
  v346.mat[1].y = v265[4];
  v272 = v265[5];
  v346.mat[1].z = v265[5];
  v273 = v265[6];
  v346.mat[2].x = v265[6];
  v274 = v265[7];
  v346.mat[2].y = v265[7];
  v275 = v265[8];
  v346.mat[2].z = v265[8];
  if ( v267 == 0 )
  {
    HIDWORD(v311) = &TreeAnimatorFromPresentable->g.scale;
    v276 = (float)((float)(v338.mat[2].z * (float)(TreeAnimatorFromPresentable->g.scale.z * v308.z))
                 + (float)((float)(v338.mat[0].z * (float)(v308.x * TreeAnimatorFromPresentable->g.scale.x))
                         + (float)(v338.mat[1].z * (float)(TreeAnimatorFromPresentable->g.scale.y * v308.y))));
    v277 = (float)((float)(v338.mat[0].x * (float)(v308.x * TreeAnimatorFromPresentable->g.scale.x))
                 + (float)((float)(v338.mat[1].x * (float)(TreeAnimatorFromPresentable->g.scale.y * v308.y))
                         + (float)(v338.mat[2].x * (float)(TreeAnimatorFromPresentable->g.scale.z * v308.z))));
    v278 = (float)((float)((float)v269
                         * (float)((float)(v338.mat[0].x * (float)(v308.x * TreeAnimatorFromPresentable->g.scale.x))
                                 + (float)((float)(v338.mat[1].x
                                                 * (float)(TreeAnimatorFromPresentable->g.scale.y * v308.y))
                                         + (float)(v338.mat[2].x
                                                 * (float)(TreeAnimatorFromPresentable->g.scale.z * v308.z)))))
                 + (float)((float)v272
                         * (float)((float)(v338.mat[2].y * (float)(TreeAnimatorFromPresentable->g.scale.z * v308.z))
                                 + (float)((float)(v338.mat[0].y
                                                 * (float)(v308.x * TreeAnimatorFromPresentable->g.scale.x))
                                         + (float)(v338.mat[1].y
                                                 * (float)(TreeAnimatorFromPresentable->g.scale.y * v308.y))))));
    v279 = (float)((float)((float)v270
                         * (float)((float)(v338.mat[2].y * (float)(TreeAnimatorFromPresentable->g.scale.z * v308.z))
                                 + (float)((float)(v338.mat[0].y
                                                 * (float)(v308.x * TreeAnimatorFromPresentable->g.scale.x))
                                         + (float)(v338.mat[1].y
                                                 * (float)(TreeAnimatorFromPresentable->g.scale.y * v308.y)))))
                 + (float)((float)v273
                         * (float)((float)(v338.mat[2].z * (float)(TreeAnimatorFromPresentable->g.scale.z * v308.z))
                                 + (float)((float)(v338.mat[0].z
                                                 * (float)(v308.x * TreeAnimatorFromPresentable->g.scale.x))
                                         + (float)(v338.mat[1].z
                                                 * (float)(TreeAnimatorFromPresentable->g.scale.y * v308.y))))));
    v308.y = (float)((float)v274
                   * (float)((float)(v338.mat[2].z * (float)(TreeAnimatorFromPresentable->g.scale.z * v308.z))
                           + (float)((float)(v338.mat[0].z * (float)(v308.x * TreeAnimatorFromPresentable->g.scale.x))
                                   + (float)(v338.mat[1].z * (float)(TreeAnimatorFromPresentable->g.scale.y * v308.y)))))
           + (float)((float)((float)v268
                           * (float)((float)(v338.mat[0].x * (float)(v308.x * TreeAnimatorFromPresentable->g.scale.x))
                                   + (float)((float)(v338.mat[1].x
                                                   * (float)(TreeAnimatorFromPresentable->g.scale.y * v308.y))
                                           + (float)(v338.mat[2].x
                                                   * (float)(TreeAnimatorFromPresentable->g.scale.z * v308.z)))))
                   + (float)((float)v271
                           * (float)((float)(v338.mat[2].y * (float)(TreeAnimatorFromPresentable->g.scale.z * v308.z))
                                   + (float)((float)(v338.mat[0].y
                                                   * (float)(v308.x * TreeAnimatorFromPresentable->g.scale.x))
                                           + (float)(v338.mat[1].y
                                                   * (float)(TreeAnimatorFromPresentable->g.scale.y * v308.y))))));
    v308.z = (float)((float)v275 * (float)v276) + (float)v278;
    v308.x = (float)((float)v277 * (float)v266) + (float)v279;
  }
  idAnimBaseFSM::GetDeltaCorrectionGoalRotation(this: (idAnimBaseFSM *)&v377, result: this, parms: nullptr);
  if ( ai_debugAnimDeltaCorrection.valueInteger == this->ai->entityNumber
    && ai_debugAnimDeltaCorrectionType.valueInteger == 2 )
  {
    v280 = &idColor::colorOrange;
    if ( v194 < v217 )
      v280 = &idColor::colorRed;
    v281 = gameLocal->GetRenderWorld(this: gameLocal);
    v359[1] = v310.y + (float)(v346.mat[0].y * (float)v210);
    v359[0] = v310.x + (float)(v346.mat[0].x * (float)v210);
    v359[2] = v310.z + (float)(v346.mat[0].z * (float)v210);
    ((void (__fastcall *)(idRenderWorld *, idColor *, idVec3 *, float *, double))v281->DebugArrow)(
      a1: v281,
      a2: v280,
      a3: &v310,
      a4: v359,
      a5: 2.0);
  }
  if ( (_S18_4 & 2) == 0 )
    _S18_4 |= 2u;
  idMat3::ToAngles(this: &v347, result: (idAngles *)&v326);
  lastDeltaAngles.pitch = v347.mat[0].x;
  lastDeltaAngles.yaw = v347.mat[0].y;
  lastDeltaAngles.roll = v347.mat[0].z;
  if ( (this->currentState->GetStateFlags(this: this->currentState) & 8) != 0 )
  {
    v282 = this->ai;
    v337.useVolumes = NavVolumeNone;
    useVolumes = v282->GetNavParms3d(this: v282)->mover.useVolumes;
    v284 = *(float *)LODWORD(v336.mat[2].z);
    v285 = *(float *)(LODWORD(v336.mat[2].z) + 4);
    v286 = *(_DWORD *)LODWORD(v336.mat[2].z);
    v352 = v195;
    v287 = *(_DWORD *)(LODWORD(v336.mat[2].z) + 4);
    v353 = v195;
    v288 = *(float *)(LODWORD(v336.mat[2].z) + 8);
    v354 = v195;
    v289 = *(_DWORD *)(LODWORD(v336.mat[2].z) + 8);
    v365.x = v310.x + v308.x;
    v365.z = v308.z + v310.z;
    v351 = 0;
    v365.y = v308.y + v310.y;
    v337.useVolumes = useVolumes;
    v347.mat[2].x = v284;
    v347.mat[2].y = v285;
    v347.mat[2].z = v288;
    v348 = v286;
    v349 = v287;
    v350 = v289;
    idNpMover3D::NavProbe3D(
      input: &v337,
      start: &v310,
      end: &v365,
      results: (idNpMover3D::idProbeResults3D *)&v347.mat[2]);
    v308.x = v347.mat[2].x - v310.x;
    v308.z = v347.mat[2].z - v310.z;
    v308.y = v347.mat[2].y - v310.y;
  }
  lastBlendTime = TreeAnimatorFromPresentable->lastBlendTime;
  v291 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) - lastBlendTime;
  UserChannelUseGravity = idAnimBaseFSM::GetUserChannelUseGravity(this);
  v293 = (idPhysics_AI *)v343;
  *(_DWORD *)(v343 + 648) = (_cntlzw(UserChannelUseGravity) & 0x20) != 0;
  v294 = gameLocal->GetGameMsPerFrame(this: gameLocal, a2: GAMETIME_SCALED);
  idPhysics_AI::SetDelta(this: v293, d: &v308, ticksPerFrame: v294);
  if ( (*((_BYTE *)&this->animDeltaCorrection + 72) & 0x40) != 0
    || this->animDeltaCorrection.idealPoint == IDEALPOINT_NOOP
    || (*((_BYTE *)&this->animDeltaCorrection + 72) & 0x80) == 0
    || LODWORD(v312.mat[2].y) == 0
    || *(_BYTE *)(*(_DWORD *)(LODWORD(v330.mat[1].x) + 64) + 68) != 0 )
  {
    goto LABEL_263;
  }
  previousRemainingRotationFramesToGoal = this->animDeltaCorrection.previousRemainingRotationFramesToGoal;
  this->animDeltaCorrection.previousRemainingRotationFramesToGoal = idAnimBaseFSM::GetRemainingFramesToTime(
                                                                      this,
                                                                      time: this->animDeltaCorrection.rotationGoalTime);
  v296 = 0;
  if ( previousRemainingRotationFramesToGoal != v194 )
  {
    if ( previousRemainingRotationFramesToGoal > v195 )
      goto LABEL_256;
    goto LABEL_255;
  }
  if ( v194 <= v195 || BYTE1(v312.mat[2].z) == 0 && HIBYTE(v312.mat[2].z) != 0 )
LABEL_255:
    v296 = 1;
LABEL_256:
  if ( v296 != 0 )
  {
    if ( this->RespondsTo(this, a2: &FSM_DepartureReturnToMove) )
    {
      idEventReceiver::ProcessEvent(
        this: (idEventReceiver *)&v318,
        result: (idEventArg *)this,
        ev: &FSM_DepartureReturnToMove);
    }
    else
    {
      currentState = this->currentState;
      name = FSM_DepartureReturnToMove.name;
      if ( currentState != nullptr )
      {
        Classname = idClass::GetClassname(this: currentState);
        idLib::Warning(fmt: "State '%s' didn't handle event '%s'", Classname, name);
      }
      else
      {
        idLib::Warning(fmt: "State '%s' didn't handle event '%s'", &byte_8200D768, FSM_DepartureReturnToMove.name);
      }
    }
    idAnimBaseFSM::ResetAnimDeltaCorrection(this);
  }
LABEL_263:
  if ( ai_printDeltas.valueInteger == this->ai->entityNumber )
  {
    v300 = __fsqrts((float)((float)(v308.x * v308.x) + (float)((float)(v308.z * v308.z) + (float)(v308.y * v308.y))));
    idVec3::ToString(this: (idAngles *)&v308, precision: 2);
    v301 = (idAngles *)v293->GetOrigin(this: v293, a2: 0);
    v302 = idVec3::ToString(this: v301, precision: 2);
    idLib::Printf(
      fmt: "last origin : ( %s ) :  d( %s ), s( %f )   ( %s )\n",
      v302,
      (const char *)HIDWORD(v300),
      v300,
      (const char *)LODWORD(v300));
  }
  v303 = 0;
  if ( v347.mat[0].y <= v212 )
  {
    if ( v347.mat[0].y < v217 )
      v303 = 2;
  }
  else
  {
    v303 = 1;
  }
  v304 = this->ai;
  v311 = __PAIR64__(&unk_82150000, v291);
  v305 = (float)((float)((float)1000.0 / (float)__SPAIR64__(&unk_82150000, v291)) * v347.mat[0].y);
  if ( idEntity::GetBindMaster(this: v304) == nullptr )
    idAIOrientation::UpdateFromAnim(
      this: &this->orientBody,
      axis: &v346,
      turnRate: v305,
      turnDir: v306,
      updateIdeal: v303,
      a6: (_cntlzw(this->animDeltaMode - 3) & 0x20) != 0);
  if ( ((LODWORD(v308.x) | LODWORD(v308.y) | LODWORD(v308.z)) & 0x7FFFFFFF) != 0 )
  {
    idVec3::NormalizeFast(this: &v308);
    idAIOrientation::SetIdealDir(this: &this->orientMove, ai: this->ai, dir: &v308);
    this->moveOrientationOnPath = true;
  }
  idStr::FreeData(this: &v355);
  idPLogScope::~idPLogScope(this: (idPLogScope *)&v347.mat[1].y);
LABEL_274:
  RD_EventEnd();
}


// ========================================================================
// __unwind$492267
// EA  : 0x82A7EC90
// RVA : 0x00A7EC90
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm_deltacorrection.cpp
// ========================================================================

void _unwind_492267()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 2048 + 1748));
}


// ========================================================================
// __unwind$492268
// EA  : 0x82A7ECB8
// RVA : 0x00A7ECB8
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm_deltacorrection.cpp
// ========================================================================

void _unwind_492268()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 2048 + 664));
}


// ========================================================================
// __unwind$492270
// EA  : 0x82A7ECE0
// RVA : 0x00A7ECE0
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm_deltacorrection.cpp
// ========================================================================

void _unwind_492270()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 2048 + 720));
}


// ========================================================================
// `dynamic initializer for 'ai_printDeltas''
// EA  : 0x83368700
// RVA : 0x01368700
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm_deltacorrection.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_printDeltas__()
{
  idCVar::idCVar(
    this: &ai_printDeltas,
    name: "ai_printDeltas",
    value: "0",
    flags: 2,
    description: "set to entity number to display ai's deltas from animation",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_printDeltas__);
}


// ========================================================================
// `dynamic initializer for 'ai_debugAnimDeltaCorrectionType''
// EA  : 0x83368758
// RVA : 0x01368758
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm_deltacorrection.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_debugAnimDeltaCorrectionType__()
{
  idCVar::idCVar(
    this: &ai_debugAnimDeltaCorrectionType,
    name: "ai_debugAnimDeltaCorrectionType",
    value: "1",
    flags: 2,
    description: "enable/disable debugging anim delta correction, 1 = translation 2 = rotation.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_debugAnimDeltaCorrectionType__);
}


// ========================================================================
// `dynamic initializer for 'ai_debugAnimDeltaCorrection''
// EA  : 0x833687B0
// RVA : 0x013687B0
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm_deltacorrection.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_debugAnimDeltaCorrection__()
{
  idCVar::idCVar(
    this: &ai_debugAnimDeltaCorrection,
    name: "ai_debugAnimDeltaCorrection",
    value: "0",
    flags: 2,
    description: "entity number to display delta correction info on",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_debugAnimDeltaCorrection__);
}


// ========================================================================
// `dynamic initializer for 'ai_enableDeltaCorrection''
// EA  : 0x83368808
// RVA : 0x01368808
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm_deltacorrection.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_enableDeltaCorrection__()
{
  idCVar::idCVar(
    this: &ai_enableDeltaCorrection,
    name: "ai_enableDeltaCorrection",
    value: "1",
    flags: 1,
    description: "1 = enable delta correction anim events.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_enableDeltaCorrection__);
}

