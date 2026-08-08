
// ========================================================================
// ?SetLandTime@idBobCycle@@QAAXHH@Z
// EA  : 0x82DF6290
// RVA : 0x00DF6290
// PDB : w:\tech5\tungsten\game\player\bobcycle.cpp
// ========================================================================

void __fastcall idBobCycle::SetLandTime(idBobCycle *this, int _landTime, int _landChange)
{
  this->landTime = _landTime;
  this->landChange = _landChange;
}


// ========================================================================
// ??0idBobCycle@@QAA@XZ
// EA  : 0x82DF62A0
// RVA : 0x00DF62A0
// PDB : w:\tech5\tungsten\game\player\bobcycle.cpp
// ========================================================================

idBobCycle *__fastcall idBobCycle::idBobCycle(idBobCycle *this)
{
  idParametricDecay *offset_decay; // r28
  int v3; // r26
  idParametricDecay *v4; // r25
  float z; // r5
  double currentValue; // fp13
  double v7; // fp3
  int v8; // r29

  this->stepUpTime = 0;
  this->landChange = 0;
  this->stepUpDelta = 0.0;
  this->landTime = 0;
  this->lastUpdateTime = 0;
  this->viewBobAngles = ang_zero;
  offset_decay = this->offset_decay;
  v3 = 1;
  v4 = this->offset_decay;
  this->viewBob = vec3_origin;
  this->surfaceTiltTargetAngles = ang_zero;
  this->handsAngles = ang_zero;
  this->handsOffset.x = vec3_origin.x;
  this->handsOffset.y = vec3_origin.y;
  z = vec3_origin.z;
  this->cycle = 0.0;
  this->handsOffset.z = z;
  this->currentStep = 0;
  do
  {
    idParametricDecay::idParametricDecay(this: v4);
    --v3;
    ++v4;
  }
  while ( v3 >= 0 );
  this->moving = false;
  this->idleBlend.duration = 0;
  this->idleBlend.startTime = 0.0;
  this->idleBlend.currentTime = 0.0;
  this->idleBlend.currentValue = 0.0;
  currentValue = this->idleBlend.currentValue;
  this->idleBlend.endValue = this->idleBlend.currentValue;
  this->idleBlend.startValue = currentValue;
  this->sideMove = 0;
  this->lagretain = 0.0;
  this->bobFoot = 0;
  this->bobFrac = 0.0;
  this->bobCycle = 128;
  this->bobfracsin = 0.0;
  this->swayOffset = vec3_origin;
  this->crouching = false;
  this->instantCrouchChange = false;
  this->decay_active = false;
  idParametricDecay::idParametricDecay(this: &this->crouch_decay);
  v7 = 0.0;
  this->scaleStartTime = 0;
  this->scaleEndTime = 0;
  this->accelRotValue = 0.0;
  this->footStep = FOOTSTEP_NONE;
  this->strafeRotValue = 0.0;
  this->scaleRate = 0.0;
  v8 = 2;
  this->currentScale = 1.0;
  this->baseScale = 1.0;
  this->targetScale = 1.0;
  this->coverIndicationBlender = 0.0;
  this->zoomBlendOut = 1.0;
  this->currentLeanScale.x = 0.0;
  this->currentLeanScale.y = 0.0;
  this->tzero[0] = 0;
  this->tzero[1] = 0;
  this->decay[0] = 0.0;
  this->decay[1] = 0.0;
  this->offset_base[0] = 0.0;
  this->offset_base[1] = 0.0;
  while ( 1 )
  {
    idParametricDecay::Init(this: offset_decay, delta: v7, linear: v7, t0: v7, tdelta: 130.0, lambda: 0.40000001);
    --v8;
    ++offset_decay;
    if ( v8 == 0 )
      break;
    v7 = 0.0;
  }
  return this;
}


// ========================================================================
// ?TestSteppedUp@idBobCycle@@QAAXABVidPhysics_Player@@@Z
// EA  : 0x82DF64A0
// RVA : 0x00DF64A0
// PDB : w:\tech5\tungsten\game\player\bobcycle.cpp
// ========================================================================

void __fastcall idBobCycle::TestSteppedUp(idBobCycle *this, idPhysics_Player *physicsObj)
{
  int v4; // r29
  int valueInteger; // r30
  double StepUp; // fp1
  __int128 v7; // r10

  if ( idPhysics_Player::HasSteppedUp(this: physicsObj) )
  {
    v4 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) - this->stepUpTime;
    valueInteger = g_stepup_time.valueInteger;
    if ( v4 >= g_stepup_time.valueInteger )
    {
      this->stepUpDelta = idPhysics_Player::GetStepUp(this: physicsObj);
    }
    else
    {
      StepUp = idPhysics_Player::GetStepUp(this: physicsObj);
      LODWORD(v7) = valueInteger;
      DWORD2(v7) = valueInteger - v4;
      this->stepUpDelta = (float)StepUp
                        + (float)((float)((float)*(__int64 *)((char *)&v7 + 4) * this->stepUpDelta) / (float)(__int64)v7);
    }
    if ( this->stepUpDelta > (double)(float)(pm_stepsize.valueFloat * (float)2.0) )
      this->stepUpDelta = pm_stepsize.valueFloat * (float)2.0;
    this->stepUpTime = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  }
}


// ========================================================================
// ?DoLadderViewCorrection@idBobCycle@@AAAXPBVidPresentablePlayer@@@Z
// EA  : 0x82DF65A0
// RVA : 0x00DF65A0
// PDB : w:\tech5\tungsten\game\player\bobcycle.cpp
// ========================================================================

void __fastcall idBobCycle::DoLadderViewCorrection(idBobCycle *this, const idPresentablePlayer *player)
{
  idAngles *p_viewAngles; // r24
  unsigned int v5; // r11
  const idMat3 *v6; // r3
  long double v7; // fp2
  double v8; // fp1
  double v9; // fp11
  double x; // fp0
  double v11; // fp13
  double v12; // fp12
  double v13; // fp0
  double v14; // fp8
  double v15; // fp11
  double y; // fp10
  double z; // fp9
  double v18; // fp1
  double v19; // fp13
  double v20; // fp12
  double v21; // fp0
  double v22; // fp13
  double v23; // fp9
  double v24; // fp10
  double v25; // fp8
  idVec3 v26; // [sp+60h] [-A0h] BYREF
  idMat3 v27; // [sp+70h] [-90h] BYREF

  p_viewAngles = &player->ucmdTracker1.viewAngles;
  idView::GetViewPos(this: &player->view, origin: &v26, axis: &v27);
  v5 = _S18_19;
  if ( (_S18_19 & 1) == 0 )
  {
    v5 = _S18_19 | 1;
    viewOffstetUp.x = 0.0;
    viewOffstetUp.y = 0.0;
    viewOffstetUp.z = 0.0;
    _S18_19 |= 1u;
  }
  if ( (v5 & 2) == 0 )
  {
    viewOffstetDown.y = 0.0;
    v5 |= 2u;
    _S18_19 = v5;
    viewOffstetDown.x = -1.0;
    viewOffstetDown.z = 10.0;
  }
  if ( (v5 & 4) == 0 )
  {
    viewOffstetLeft.x = 3.0;
    v5 |= 4u;
    viewOffstetLeft.z = 3.0;
    _S18_19 = v5;
    viewOffstetLeft.y = -5.0;
  }
  if ( (v5 & 8) == 0 )
  {
    viewOffstetRight.x = 3.0;
    v5 |= 8u;
    viewOffstetRight.z = 3.0;
    _S18_19 = v5;
    viewOffstetRight.y = 5.0;
  }
  if ( (v5 & 0x10) == 0 )
  {
    minAngles.roll = 0.0;
    v5 |= 0x10u;
    _S18_19 = v5;
    minAngles.pitch = -89.0;
    minAngles.yaw = -90.0;
  }
  if ( (v5 & 0x20) == 0 )
  {
    maxAngles.yaw = 90.0;
    maxAngles.roll = 0.0;
    _S18_19 = v5 | 0x20;
    maxAngles.pitch = 45.0;
  }
  v6 = player->physicsObj.GetAxis(this: &player->physicsObj, a2: 0);
  *(double *)&v7 = (float)((float)(v27.mat[1].x * v6->mat[0].x)
                         + (float)((float)(v27.mat[1].z * v6->mat[0].z) + (float)(v27.mat[1].y * v6->mat[0].y)));
  v8 = idMath::ACos(a: v7);
  if ( p_viewAngles->pitch <= 0.0 )
  {
    v9 = (float)(p_viewAngles->pitch / minAngles.pitch);
    v11 = (float)((float)(viewOffstetUp.y * (float)(p_viewAngles->pitch / minAngles.pitch)) + vec3_origin.y);
    v12 = (float)((float)(viewOffstetUp.z * (float)(p_viewAngles->pitch / minAngles.pitch)) + vec3_origin.z);
    x = viewOffstetUp.x;
  }
  else
  {
    v9 = (float)(p_viewAngles->pitch / maxAngles.pitch);
    v11 = (float)(vec3_origin.y + (float)(viewOffstetDown.y * (float)(p_viewAngles->pitch / maxAngles.pitch)));
    v12 = (float)(vec3_origin.z + (float)(viewOffstetDown.z * (float)(p_viewAngles->pitch / maxAngles.pitch)));
    x = viewOffstetDown.x;
  }
  v13 = (float)((float)((float)x * (float)v9) + vec3_origin.x);
  if ( (float)((float)((float)v8 * idMath::M_RAD2DEG) - (float)90.0) <= 0.0 )
  {
    v14 = (float)((float)((float)((float)v8 * idMath::M_RAD2DEG) - (float)90.0) / minAngles.yaw);
    v15 = viewOffstetRight.x;
    y = viewOffstetRight.y;
    z = viewOffstetRight.z;
  }
  else
  {
    v14 = (float)((float)((float)((float)v8 * idMath::M_RAD2DEG) - (float)90.0) / maxAngles.yaw);
    v15 = viewOffstetLeft.x;
    y = viewOffstetLeft.y;
    z = viewOffstetLeft.z;
  }
  v18 = v27.mat[0].y;
  v19 = (float)((float)((float)y * (float)v14) + (float)v11);
  v20 = (float)((float)((float)z * (float)v14) + (float)v12);
  v21 = (float)((float)((float)v15 * (float)v14) + (float)v13);
  v23 = (float)((float)(v27.mat[2].z * (float)v20) + (float)(v27.mat[1].z * (float)v19));
  v24 = (float)((float)(v27.mat[2].y * (float)v20) + (float)(v27.mat[1].y * (float)v19));
  v25 = (float)((float)(v27.mat[0].x * (float)v21)
              + (float)((float)(v27.mat[2].x * (float)v20) + (float)(v27.mat[1].x * (float)v19)));
  v22 = v27.mat[0].z;
  this->viewBob.x = v25;
  this->viewBob.z = (float)((float)v22 * (float)v21) + (float)v23;
  this->viewBob.y = (float)((float)v18 * (float)v21) + (float)v24;
}


// ========================================================================
// ?DoBob@idBobCycle@@AAAXPBVidPresentablePlayer@@@Z
// EA  : 0x82DF68C0
// RVA : 0x00DF68C0
// PDB : w:\tech5\tungsten\game\player\bobcycle.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idBobCycle::DoBob(idBobCycle *this, const idPresentablePlayer *player)
{
  idPhysics_Player *p_physicsObj; // r31
  idVec3 *v5; // r28
  float *v6; // r3
  double v7; // fp11
  double v8; // fp9
  double v11; // fp3
  double v12; // fp12
  double v13; // fp11
  double v14; // fp31
  __int64 v15; // r4 OVERLAPPED
  long double v16; // fp4
  int v17; // r26
  double v18; // fp30
  __int64 v19; // r11
  double v20; // fp27
  int GameMs; // r3
  __int64 v22; // r11
  double duration; // fp0
  __int64 v24; // r11
  double CurrentValue; // fp27
  double v26; // fp0
  double v27; // fp10
  double cycle; // fp10
  double v29; // fp0
  long double v30; // fp2
  long double v31; // fp2
  int currentStep; // r11
  float *offset_base; // r27
  __int64 v34; // r6
  idParametricDecay *offset_decay; // r30
  int v36; // r3
  double v37; // fp30
  __int64 v38; // r10
  double v39; // fp1
  double v40; // fp31
  __int64 v41; // r11
  double v42; // fp30
  __int64 v43; // r10
  idInterpolate<float> *p_idleBlend; // r30
  double v45; // fp13
  double v46; // fp12
  int sideMove; // r10
  double v48; // fp31
  __int64 v49; // r11
  __int64 v50; // r8
  double v51; // fp0
  double v52; // fp13
  double v53; // fp3
  __int64 v54; // r7
  double startTime; // fp2
  double v56; // fp13
  double v57; // fp12
  float v58[2]; // [sp+50h] [-B0h] BYREF
  __int64 v59; // [sp+58h] [-A8h] BYREF
  __int64 v60; // [sp+60h] [-A0h] BYREF
  __int64 v61[8]; // [sp+70h] [-90h] BYREF

  p_physicsObj = &player->physicsObj;
  v5 = player->physicsObj.GetPushedLinearVelocity(this: v61, result: &player->physicsObj, a3: 0);
  v6 = (float *)p_physicsObj->GetLinearVelocity(
                  this: (struct idPhysics_Player *)&v60,
                  result: (idVec3 *)p_physicsObj,
                  a3: 0);
  v7 = (float)(*v6 - v5->x);
  v8 = (float)(v6[1] - v5->y);
  _FP6 = (float)((float)((float)((float)v8 * (float)v8) + (float)((float)(*v6 - v5->x) * (float)(*v6 - v5->x)))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f4, f6, f7, f13 }
  v11 = __frsqrte(_FP4);
  v12 = (float)((float)-(float)((float)((float)((float)v11
                                              * (float)((float)((float)((float)v8 * (float)v8)
                                                              + (float)((float)(*v6 - v5->x) * (float)(*v6 - v5->x)))
                                                      * (float)0.5))
                                      * (float)v11)
                              - (float)1.5)
              * (float)v11);
  v13 = (float)((float)((float)-(float)((float)((float)((float)v11
                                                      * (float)((float)((float)((float)v8 * (float)v8)
                                                                      + (float)((float)v7 * (float)v7))
                                                              * (float)0.5))
                                              * (float)v11)
                                      - (float)1.5)
                      * (float)v11)
              * (float)((float)((float)((float)v8 * (float)v8) + (float)((float)v7 * (float)v7)) * (float)0.5));
  v14 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)v13 * (float)v12)
                                                                              - (float)1.5)
                                                              * (float)v12)
                                                      * (float)((float)((float)((float)v8 * (float)v8)
                                                                      + (float)((float)(*v6 - v5->x)
                                                                              * (float)(*v6 - v5->x)))
                                                              * (float)0.5))
                                              * (float)((float)-(float)((float)((float)v13 * (float)v12) - (float)1.5)
                                                      * (float)v12))
                                      - (float)1.5)
                      * (float)((float)-(float)((float)((float)v13 * (float)v12) - (float)1.5) * (float)v12))
              * (float)((float)((float)v8 * (float)v8) + (float)((float)(*v6 - v5->x) * (float)(*v6 - v5->x))));
  v59 = (unsigned int)idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED)
      | 0x100000000LL;
  HIDWORD(v15) = idGameTimeManager::GetPreviousGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  LODWORD(v15) = HIDWORD(v15);
  *((_QWORD *)&v16 + 1) = v59;
  *(_QWORD *)&v16 = v15;
  v17 = 0;
  v18 = (float)((float)v59 - (float)v15);
  v59 = v15;
  if ( player->ucmdTracker1.usercmd.forwardmove != 0 || player->ucmdTracker1.usercmd.rightmove != 0 )
  {
    if ( !this->moving )
    {
      this->moving = true;
      LODWORD(v24) = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      CurrentValue = idInterpolate<float>::GetCurrentValue(this: &this->idleBlend, time: (float)v24);
      HIDWORD(v15) = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      v59 = __PAIR64__(&unk_82340000, HIDWORD(v15));
      this->idleBlend.startValue = CurrentValue;
      this->idleBlend.endValue = 1.0;
      this->idleBlend.currentValue = CurrentValue;
      this->idleBlend.duration = (float)((float)1.0 - (float)CurrentValue) * (float)100.0;
      this->idleBlend.startTime = (float)__SPAIR64__(&unk_82340000, HIDWORD(v15));
      this->idleBlend.currentTime = (float)__SPAIR64__(&unk_82340000, HIDWORD(v15)) - (float)1.0;
    }
  }
  else
  {
    if ( this->moving )
    {
      this->moving = false;
      LODWORD(v19) = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      v20 = idInterpolate<float>::GetCurrentValue(this: &this->idleBlend, time: (float)v19);
      GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      this->idleBlend.startValue = v20;
      v59 = __PAIR64__(&unk_82340000, GameMs);
      this->idleBlend.endValue = 0.0;
      this->idleBlend.duration = (float)v20 * (float)100.0;
      this->idleBlend.startTime = (float)__SPAIR64__(&unk_82340000, GameMs);
      this->idleBlend.currentValue = v20;
      this->idleBlend.currentTime = (float)__SPAIR64__(&unk_82340000, GameMs) - (float)1.0;
    }
    LODWORD(v22) = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    duration = this->idleBlend.duration;
    v59 = v22;
    if ( (float)v22 >= (double)(float)((float)duration + this->idleBlend.startTime) && v14 == 0.0 )
    {
      this->cycle = 0.0;
      this->currentStep = 0;
      this->sideMove = 0;
    }
  }
  if ( player->ucmdTracker1.usercmd.rightmove != 0 && this->sideMove == 0 )
  {
    if ( player->ucmdTracker1.usercmd.rightmove <= 0 )
      this->sideMove = -1;
    else
      this->sideMove = 1;
  }
  if ( v14 > 0.0 )
  {
    if ( v14 > pm_walkspeed.valueFloat )
    {
      v27 = (float)(pm_runspeed.valueFloat - pm_walkspeed.valueFloat);
      if ( v27 == 0.0 )
        v27 = 0.0099999998;
      *((double *)&v16 + 1) = (float)((float)(pm_runspeed.valueFloat
                                            * (float)((float)((float)v14 - pm_walkspeed.valueFloat) / (float)v27))
                                    * (float)0.43478262);
      v26 = (float)((float)((float)((float)((float)1.0
                                          - (float)((float)((float)v14 - pm_walkspeed.valueFloat) / (float)v27))
                                  * pm_walkspeed.valueFloat)
                          * (float)0.58823526)
                  + (float)((float)(pm_runspeed.valueFloat
                                  * (float)((float)((float)v14 - pm_walkspeed.valueFloat) / (float)v27))
                          * (float)0.43478262));
    }
    else
    {
      v26 = (float)(pm_walkspeed.valueFloat * (float)0.58823526);
    }
    cycle = this->cycle;
    v29 = (float)((float)((float)((float)v18 * (float)v14) / (float)((float)v26 * (float)1000.0)) + this->cycle);
    this->cycle = v29;
    if ( cycle < 0.5 && v29 >= 0.5 )
    {
      if ( this->currentStep != 0 )
        this->footStep = FOOTSTEP_LEFT;
      else
        this->footStep = FOOTSTEP_RIGHT;
    }
    *(double *)&v30 = this->cycle;
    if ( *(double *)&v30 > 1.0 )
    {
      *((_QWORD *)&v30 + 1) = 0x3FF0000000000000LL;
      v31 = fmod(dX: v30, dY: v16);
      currentStep = this->currentStep;
      this->cycle = *(double *)&v31;
      this->currentStep = (currentStep + 1) % 2;
    }
  }
  offset_base = this->offset_base;
  LODWORD(v34) = player->ucmdTracker1.usercmd.rightmove;
  HIDWORD(v34) = player->ucmdTracker1.usercmd.forwardmove;
  offset_decay = this->offset_decay;
  v59 = *(__int64 *)((char *)&v15 - 4);
  v58[1] = (float)v34 * (float)0.0078740157;
  v58[0] = (float)*(__int64 *)((char *)&v15 - 4) * (float)0.0078740157;
  do
  {
    v36 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    v37 = *offset_base;
    LODWORD(v38) = v36;
    v60 = v38;
    v39 = idParametricDecay::Evaluate(this: offset_decay, t: (float)v38);
    v40 = v58[v17];
    *(float *)((char *)&v59 + v17 * 4) = (float)v39 + (float)v37;
    if ( v37 != v40 )
    {
      idParametricDecay::SetDelta(this: offset_decay, delta: (float)((float)((float)v39 + (float)v37) - (float)v40));
      LODWORD(v41) = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      v61[0] = v41;
      idParametricDecay::SetTZero(this: offset_decay, t0: (float)v41);
      *offset_base = v40;
    }
    ++v17;
    ++offset_decay;
    ++offset_base;
  }
  while ( v17 < 2 );
  v42 = idMath::Sin16(a: (float)(this->cycle * (float)3.1415927));
  LODWORD(v43) = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  p_idleBlend = &this->idleBlend;
  v45 = (float)((float)v43 - this->idleBlend.startTime);
  v61[0] = v43;
  if ( (float)v43 != this->idleBlend.currentTime )
  {
    v46 = this->idleBlend.duration;
    this->idleBlend.currentTime = (float)v43;
    if ( v46 < 0.0 )
    {
      if ( v45 >= 0.0 )
      {
        this->idleBlend.currentValue = this->idleBlend.startValue;
        goto LABEL_38;
      }
      if ( v45 > v46 )
      {
LABEL_37:
        this->idleBlend.currentValue = (float)((float)((float)(this->idleBlend.endValue - this->idleBlend.startValue)
                                                     / (float)v46)
                                             * (float)v45)
                                     + this->idleBlend.startValue;
        goto LABEL_38;
      }
    }
    else
    {
      if ( v45 <= 0.0 )
      {
        this->idleBlend.currentValue = this->idleBlend.startValue;
        goto LABEL_38;
      }
      if ( v45 < v46 )
        goto LABEL_37;
    }
    this->idleBlend.currentValue = this->idleBlend.endValue;
  }
LABEL_38:
  sideMove = this->sideMove;
  v48 = 1.0;
  this->viewBob.z = (float)(this->idleBlend.currentValue * (float)v42) * (float)1.4;
  if ( sideMove == 1 )
    v48 = -1.0;
  LODWORD(v49) = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  v51 = (float)((float)v49 - p_idleBlend->startTime);
  v61[0] = v49;
  if ( (float)v49 != this->idleBlend.currentTime )
  {
    v52 = this->idleBlend.duration;
    this->idleBlend.currentTime = (float)v49;
    if ( v52 < 0.0 )
    {
      if ( v51 >= 0.0 )
      {
        this->idleBlend.currentValue = this->idleBlend.startValue;
        goto LABEL_50;
      }
      if ( v51 > v52 )
      {
LABEL_49:
        this->idleBlend.currentValue = (float)((float)((float)(this->idleBlend.endValue - this->idleBlend.startValue)
                                                     / (float)v52)
                                             * (float)v51)
                                     + this->idleBlend.startValue;
        goto LABEL_50;
      }
    }
    else
    {
      if ( v51 <= 0.0 )
      {
        this->idleBlend.currentValue = this->idleBlend.startValue;
        goto LABEL_50;
      }
      if ( v51 < v52 )
        goto LABEL_49;
    }
    this->idleBlend.currentValue = this->idleBlend.endValue;
  }
LABEL_50:
  LODWORD(v50) = this->currentStep;
  v53 = (float)((float)((float)((float)((float)((float)((float)((float)v50 * (float)2.0) - (float)1.0) * (float)v48)
                                      * (float)v42)
                              * (float)0.60000002)
                      + (float)(*((float *)&v59 + 1) * 1.5))
              * this->idleBlend.currentValue);
  v61[0] = v50;
  this->viewBobAngles.roll = v53;
  LODWORD(v54) = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  startTime = p_idleBlend->startTime;
  v56 = (float)((float)v54 - p_idleBlend->startTime);
  v61[0] = v54;
  if ( (float)v54 != this->idleBlend.currentTime )
  {
    v57 = this->idleBlend.duration;
    this->idleBlend.currentTime = (float)v54;
    if ( v57 < 0.0 )
    {
      if ( v56 < 0.0 )
      {
        if ( v56 > v57 )
          goto LABEL_54;
        goto LABEL_63;
      }
    }
    else if ( v56 > 0.0 )
    {
      if ( v56 < v57 )
      {
LABEL_54:
        this->idleBlend.currentValue = (float)((float)((float)(this->idleBlend.endValue - this->idleBlend.startValue)
                                                     / (float)v57)
                                             * (float)((float)v54 - (float)startTime))
                                     + this->idleBlend.startValue;
        goto LABEL_55;
      }
LABEL_63:
      this->idleBlend.currentValue = this->idleBlend.endValue;
      goto LABEL_55;
    }
    this->idleBlend.currentValue = this->idleBlend.startValue;
  }
LABEL_55:
  this->viewBobAngles.pitch = (float)((float)((float)v42 * (float)0.44999999) + (float)(*(float *)&v59 * 0.5))
                            * this->idleBlend.currentValue;
}


// ========================================================================
// ?EvaluateScale@idBobCycle@@AAAXXZ
// EA  : 0x82DF71F8
// RVA : 0x00DF71F8
// PDB : w:\tech5\tungsten\game\player\bobcycle.cpp
// ========================================================================

void __fastcall idBobCycle::EvaluateScale(idBobCycle *this)
{
  int GameMs; // r3
  int scaleEndTime; // r11
  int v4; // r3
  int v5; // r11
  __int128 v6; // r7

  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  scaleEndTime = this->scaleEndTime;
  if ( GameMs > scaleEndTime || scaleEndTime == this->scaleStartTime )
  {
    this->currentScale = this->targetScale;
  }
  else
  {
    v4 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    v5 = this->scaleEndTime;
    LODWORD(v6) = v5 - v4;
    DWORD2(v6) = v5 - this->scaleStartTime;
    this->currentScale = (float)((float)((float)(this->baseScale - this->targetScale) * (float)(__int64)v6)
                               / (float)*(__int64 *)((char *)&v6 + 4))
                       + this->targetScale;
  }
}


// ========================================================================
// ?GetCrouchDecay@idBobCycle@@QBAMXZ
// EA  : 0x82DF72B8
// RVA : 0x00DF72B8
// PDB : w:\tech5\tungsten\game\player\bobcycle.cpp
// ========================================================================

float __fastcall idBobCycle::GetCrouchDecay(idBobCycle *this)
{
  __int64 v2; // r9
  double v3; // fp1

  if ( this->decay_active )
  {
    LODWORD(v2) = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    v3 = idParametricDecay::Evaluate(this: &this->crouch_decay, t: (float)v2);
  }
  else
  {
    v3 = 0.0;
  }
  return *((float *)&v3 + 1);
}


// ========================================================================
// ?SetBobSwayScale@idBobCycle@@QAAXMH@Z
// EA  : 0x82DF7340
// RVA : 0x00DF7340
// PDB : w:\tech5\tungsten\game\player\bobcycle.cpp
// ========================================================================

void __fastcall idBobCycle::SetBobSwayScale(idBobCycle *this, double newScale, int transitionTime, unsigned int a4)
{
  int GameMs; // r3
  double v8; // fp13
  double scaleRate; // fp12

  idBobCycle::EvaluateScale(this);
  if ( a4 != -1 )
    this->scaleRate = (float)((float)1.0 - (float)newScale) / (float)__SPAIR64__(0x82000000, a4);
  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  v8 = (float)(this->currentScale - (float)newScale);
  scaleRate = this->scaleRate;
  this->baseScale = this->currentScale;
  this->targetScale = newScale;
  this->scaleEndTime = (int)(float)((float)((float)__fabs(v8) / (float)scaleRate) + (float)(GameMs | 0x11000000000uLL));
  this->scaleStartTime = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
}


// ========================================================================
// ?Update@idBobCycle@@QAAXPBVidPresentablePlayer@@@Z
// EA  : 0x82DF7418
// RVA : 0x00DF7418
// PDB : w:\tech5\tungsten\game\player\bobcycle.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idBobCycle::Update(idBobCycle *this, idPresentablePlayer *player)
{
  idPresentablePlayer *v3; // r16
  unsigned __int64 v4; // r6
  const char *v5; // r7
  int v6; // r22
  idVec3 *p_handsOffset; // r29
  __int64 v8; // r8
  __int64 v9; // r11
  double stepUpDelta; // fp0
  double z; // fp13
  int GameMs; // r3
  __int64 v13; // r9
  __int64 v14; // r7
  double v15; // fp0
  double v16; // fp12
  double v17; // fp0
  double v18; // fp3
  double v19; // fp12
  double valueFloat; // fp25
  double v21; // fp27
  double v22; // fp24
  double v23; // fp23
  double v24; // fp20
  double v25; // fp19
  double strafeRotChangeSpeed; // fp14
  idHands *p_hands; // r25
  const idWeapon *CurrentWeapon; // r3
  idWeapon *v29; // r19
  const idDeclInventory *decl; // r28
  char garageIcon_high; // r10
  double v32; // fp0
  double v33; // fp13
  double v34; // fp12
  double v35; // fp11
  double v36; // fp10
  double v37; // fp9
  double v38; // fp1
  double v39; // fp26
  double v40; // fp1
  double v41; // fp28
  __int64 v42; // r9
  int v43; // r3
  long double v44; // fp2
  int v45; // r28
  long double v46; // fp2
  double yaw; // fp0
  double v48; // fp12
  double pitch; // fp0
  double v50; // fp12
  double v51; // fp22
  double v52; // fp30
  double v53; // fp21
  double v54; // fp0
  double v55; // fp18
  double v56; // fp13
  double v57; // fp10
  idAngles *p_handsAngles; // r17
  double v61; // fp0
  double v62; // fp12
  double v63; // fp13
  idPhysics_Player *p_physicsObj; // r15
  float *v65; // r28
  __int64 v66; // r6 OVERLAPPED
  float *v67; // r3
  double v68; // fp0
  double v69; // fp12
  double v70; // fp11
  char v71; // r11
  double v72; // fp10
  double v73; // fp13
  double y; // fp30
  int rightmove; // r7
  double x; // fp29
  double v77; // fp28
  double v78; // fp1
  idVec3 *p_swayOffset; // r18
  double v80; // fp24
  double v81; // fp23
  double v82; // fp22
  double v83; // fp11
  double v84; // fp10
  double v85; // fp8
  double v86; // fp7
  double v87; // fp4
  double lagretain; // fp5
  float v89; // r11
  float v90; // r10
  double v91; // fp0
  double v92; // fp9
  double v93; // fp9
  double v94; // fp0
  double v95; // fp12
  double v96; // fp10
  double v97; // fp13
  double v98; // fp9
  double v99; // fp5
  double v100; // fp8
  double v101; // fp1
  double v102; // fp11
  double v103; // fp10
  double v104; // fp6
  double v105; // fp8
  double v106; // fp7
  double v107; // fp9
  double v108; // fp5
  double v109; // fp10
  double v110; // fp6
  double v111; // fp4
  double v112; // fp4
  double v113; // fp3
  double v114; // fp2
  double v115; // fp8
  double v116; // fp1
  double v117; // fp0
  double v118; // fp13
  double v119; // fp12
  double v120; // fp8
  bool IsZoomedIn; // r3
  double zoomBlendOut; // fp13
  double v123; // fp10
  double v124; // fp0
  double v125; // fp13
  float *v126; // r11
  double v127; // fp26
  double v128; // fp0
  double v129; // fp11
  double v130; // fp6
  double v131; // fp2
  double v132; // fp10
  double v133; // fp9
  double v134; // fp11
  double v135; // fp1
  double v136; // fp0
  double Offset; // fp1
  double v138; // fp2
  double v139; // fp3
  double v140; // fp7
  double v141; // fp6
  double v142; // fp5
  double v143; // fp1
  double v144; // fp9
  double v145; // fp8
  double v146; // fp6
  double v147; // fp5
  double v148; // fp0
  double coverIndicationBlender; // fp0
  double v160; // fp0
  double v161; // fp30
  double v162; // fp0
  idVec2 *p_currentLeanScale; // r11
  double v167; // fp13
  double v171; // fp13
  double v172; // fp0
  double v173; // fp11
  double v174; // fp13
  double v175; // fp0
  double v176; // fp13
  double v177; // fp12
  double v178; // fp11
  double v179; // fp9
  double v180; // fp5
  double v181; // fp4
  double v182; // fp7
  double v183; // fp10
  double v184; // fp11
  double v185; // fp13
  double v186; // fp6
  double v187; // fp8
  double v188; // fp0
  double v189; // fp4
  double v190; // fp2
  double v191; // fp9
  double v192; // fp12
  double v193; // fp11
  double v194; // fp0
  double v195; // fp10
  double v196; // fp13
  double v197; // fp6
  double v198; // fp8
  double v199; // fp7
  double v200; // fp3
  double v201; // fp1
  double v202; // fp13
  double v203; // fp0
  double v204; // fp12
  double v205; // fp0
  double v206; // fp1
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  long double v208; // fp2
  double v209; // fp13
  double accelRotValue; // fp0
  long double v218; // fp2
  __int64 v219; // r9
  BOOL decay_active; // r7
  double v221; // fp30
  double CrouchDecay; // fp1
  __int64 v223; // r10
  double v224; // fp9
  long double v225; // fp2
  long double v226; // fp2
  double v227; // fp12
  double v228; // fp11
  double v229; // fp10
  double v230; // fp30
  double v231; // fp29
  double v232; // fp28
  double strafeRotValue; // fp0
  double strafeLeftTiltAngle; // fp13
  double v242; // fp9
  double roll; // fp8
  double v244; // fp7
  double v245; // fp30
  double v246; // fp12
  double v247; // fp11
  double v248; // fp10
  double currentScale; // fp0
  double v250; // fp13
  double v251; // fp7
  double v252; // fp5
  double v253; // fp4
  double v254; // fp13
  double v255; // fp0
  double v256; // fp10
  const idVec3 *IronSightsOffset; // r3
  double v258; // fp8
  double v259; // fp7
  double v260; // fp0
  double v261; // fp6
  double v262; // fp13
  double v263; // fp12
  double v264; // fp6
  double v265; // fp30
  double v266; // fp3
  double v267; // fp2
  double v268; // fp1
  int time; // r28
  double linear; // fp28
  double lambda; // fp27
  int v272; // r27
  double v273; // fp26
  double v274; // fp25
  const idColor *v275; // r5
  char IsCrouching; // r3
  BOOL instantCrouchChange; // r11
  __int64 v278; // r11
  __int64 v279; // r7
  double v280; // fp29
  __int64 v281; // r10
  idGameTimeManager *v282; // r3
  double v283; // fp30
  __int64 v284; // r9
  double v285; // fp2
  double v286; // fp1
  double v287; // fp5
  double v288; // fp4
  int v289; // r3
  double t0; // fp0
  double v291; // fp30
  double v292; // fp0
  idGameTimeManager *p_gameTimeManager; // r3
  unsigned __int64 v294; // r9 OVERLAPPED
  __int64 v295; // r6 OVERLAPPED
  double v296; // fp5
  double v297; // fp2
  __int64 v298; // fp12
  double v299; // fp4
  double v300; // fp7
  __int64 v301; // r8
  __int64 v302; // r6
  __int64 v303; // r10
  __int64 v304; // r10
  double v305; // fp30
  idDebugGraph *v306; // r3
  double v307; // fp0
  float v308; // r27
  float v309; // r9
  float v310; // r8
  bool v311; // cr58
  int v312; // r3
  idDynamicWaterEntity *v313; // r3
  double v314; // fp30
  double v315; // fp1
  double v316; // fp10
  double v321; // fp0
  int *v322; // r10
  int *v323; // r11
  int i; // ctr
  int *v325; // r10
  int *v326; // r11
  int j; // ctr
  double v328; // fp12
  double v329; // fp0
  double v330; // fp13
  double v338; // fp0
  int valueInteger; // r11
  idDebugGraph *v347; // r3
  double v348; // fp9
  double v349; // fp2
  const idColor *v350; // r5
  int v351; // r11
  idDebugGraph *v352; // r3
  idColor *v353; // r6
  double v354; // fp12
  double v355; // fp0
  idVec3 v356; // [sp+50h] [-3E0h] BYREF
  unsigned __int64 v357; // [sp+60h] [-3D0h] BYREF
  idMat3 v358; // [sp+68h] [-3C8h] BYREF
  int v359; // [sp+8Ch] [-3A4h] BYREF
  idMat3 v360; // [sp+90h] [-3A0h] BYREF
  idVec3 v361; // [sp+B8h] [-378h] BYREF
  idVec3 v362; // [sp+C8h] [-368h] BYREF
  float v363; // [sp+E0h] [-350h]
  float v364; // [sp+E4h] [-34Ch]
  float v365; // [sp+E8h] [-348h]
  float v366; // [sp+ECh] [-344h]
  float v367[3]; // [sp+F0h] [-340h] BYREF
  float v368[9]; // [sp+FCh] [-334h] BYREF
  idDeclWeapon::handRotation_t v369; // [sp+120h] [-310h] BYREF
  idPLogScope v370; // [sp+160h] [-2D0h] BYREF
  idAngles *v371; // [sp+168h] [-2C8h]
  idVec2 v372; // [sp+170h] [-2C0h] BYREF
  idVec3 v373; // [sp+178h] [-2B8h] BYREF
  idVec3 v374; // [sp+188h] [-2A8h] BYREF
  idMat3 v375; // [sp+198h] [-298h] BYREF
  idDeclWeapon::handCoverMovRot_t v376; // [sp+1C0h] [-270h] BYREF
  idDeclWeapon::handRotation_t v377; // [sp+240h] [-1F0h] BYREF
  int v378; // [sp+27Ch] [-1B4h] BYREF
  idMat3 v379; // [sp+280h] [-1B0h] BYREF
  int v380; // [sp+2ACh] [-184h] BYREF
  idMat3 v381; // [sp+2B0h] [-180h] BYREF
  idMat3 v382[5]; // [sp+2E0h] [-150h] BYREF

  v3 = player;
  RD_EventBegin(name: "idBobCycle::Update");
  LODWORD(v4) = "idBobCycle::Update";
  HIDWORD(v4) = 2;
  idPLogScope::idPLogScope(this: &v370, pl: &pLog, gMask: v4, label: v5);
  v6 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) - this->lastUpdateTime;
  this->lastUpdateTime = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  if ( pm_noBob.valueInteger != 0 || (*((_BYTE *)v3 + 47032) & 0x20) != 0 || g_freeCam.valueInteger != 0 )
  {
    this->viewBob.x = vec3_origin.x;
    LODWORD(v356.x) = &this->handsAngles;
    this->viewBob.y = vec3_origin.y;
    this->viewBob.z = vec3_origin.z;
    this->viewBobAngles = ang_zero;
    this->handsOffset = vec3_origin;
    this->handsAngles = ang_zero;
    idPLogScope::~idPLogScope(this: &v370);
    goto LABEL_234;
  }
  v371 = &ang_zero;
  p_handsOffset = &this->handsOffset;
  this->viewBob.y = 0.0;
  LODWORD(v358.mat[1].x) = &this->handsOffset;
  this->viewBob.z = 0.0;
  this->viewBob.x = 0.0;
  this->handsOffset.z = 0.0;
  this->handsOffset.y = 0.0;
  this->handsOffset.x = 0.0;
  this->viewBobAngles = ang_zero;
  if ( idPlayer::IsOnLadder(this: (idPlayer *)v3->entity) )
  {
    idBobCycle::DoLadderViewCorrection(this, player: v3);
    idPLogScope::~idPLogScope(this: &v370);
    goto LABEL_234;
  }
  LODWORD(v358.mat[1].x) = &v3->physicsObj.currentSwimDepthState;
  if ( v3->physicsObj.currentSwimDepthState == SWIMDEPTH_STATE_NONE )
    idBobCycle::DoBob(this, player: v3);
  HIDWORD(v9) = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED)
              - this->stepUpTime;
  LODWORD(v9) = g_stepup_time.valueInteger;
  if ( SHIDWORD(v9) < g_stepup_time.valueInteger )
  {
    HIDWORD(v9) = g_stepup_time.valueInteger - HIDWORD(v9);
    stepUpDelta = this->stepUpDelta;
    LODWORD(v8) = HIDWORD(v9);
    z = this->viewBob.z;
    *(_QWORD *)&v356.x = v8;
    this->viewBob.z = (float)z - (float)((float)((float)v8 * (float)stepUpDelta) / (float)v9);
    this->handsOffset.z = this->handsOffset.z - (float)((float)((float)v8 * (float)stepUpDelta) / (float)v9);
  }
  *(float *)&v357 = 0.0;
  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  HIDWORD(v13) = 0x82000000;
  LODWORD(v14) = GameMs - this->landTime;
  *(_QWORD *)&v356.x = v14;
  v15 = (float)v14;
  if ( v15 < 150.0 )
  {
    v16 = this->viewBob.z;
    LODWORD(v13) = this->landChange;
    v17 = (float)((float)*(__int64 *)&v356.x * (float)0.0066666668);
    *(_QWORD *)&v356.x = v13;
    this->viewBob.z = (float)((float)v13 * (float)v17) + (float)v16;
    LODWORD(v14) = this->landChange;
    *(_QWORD *)&v356.x = v14;
    v18 = (float)((float)((float)v14 * (float)v17) + this->handsOffset.z);
LABEL_14:
    this->handsOffset.z = v18;
    *(float *)&v357 = v17;
    goto LABEL_15;
  }
  if ( v15 < 450.0 )
  {
    v19 = this->viewBob.z;
    LODWORD(v13) = this->landChange;
    *(_QWORD *)&v356.x = v13;
    this->viewBob.z = (float)((float)v13
                            * (float)-(float)((float)((float)((float)v14 - (float)150.0) * (float)0.0033333334)
                                            - (float)1.0))
                    + (float)v19;
    LODWORD(v14) = this->landChange;
    *(_QWORD *)&v356.x = v14;
    v18 = (float)((float)((float)v14
                        * (float)-(float)((float)((float)((float)v15 - (float)150.0) * (float)0.0033333334) - (float)1.0))
                + this->handsOffset.z);
    v17 = (float)-(float)((float)((float)((float)v15 - (float)150.0) * (float)0.0033333334) - (float)1.0);
    goto LABEL_14;
  }
LABEL_15:
  v363 = 0.0;
  v364 = 0.0;
  v365 = 0.0;
  v368[3] = 0.0;
  valueFloat = 0.0;
  v367[0] = 0.0;
  v21 = 0.0;
  v22 = 0.015;
  v23 = 0.0;
  v368[4] = 0.0;
  v24 = 0.0;
  v367[1] = 0.0;
  v25 = 0.0;
  v369.minAngles.pitch = 0.0;
  strafeRotChangeSpeed = 0.0;
  v366 = 0.015;
  HIBYTE(v368[5]) = 0;
  v367[2] = 0.0;
  v369.minAngles.yaw = 0.0;
  v368[0] = 0.0;
  v369.maxAngles.pitch = 0.0;
  v368[1] = 0.0;
  v369.maxAngles.yaw = 0.0;
  v368[2] = 0.0;
  v369.scale = 0.0;
  v369.minAngles.roll = 0.0;
  v369.retain = 0.0;
  v369.maxAngles.roll = 0.0;
  v369.extraYawMultiplier = 1.0;
  v369.extraPitchMultiplier = 1.0;
  v369.accelMaxDipAngle = 0.0;
  v369.accelRotChangeSpeed = 0.0;
  v369.strafeRotChangeSpeed = 0.0;
  v369.strafeRightTiltAngle = 0.0;
  v369.strafeLeftTiltAngle = 0.0;
  idDeclWeapon::handCoverMovRot_t::handCoverMovRot_t(this: &v376);
  p_hands = &v3->hands;
  CurrentWeapon = idHands::GetCurrentWeapon(this: &v3->hands, slot: EQUIP_RIGHT_HAND);
  v29 = (idWeapon *)CurrentWeapon;
  if ( hands_usecvars.valueFloat != 0.0 || v3->hands.testModel != nullptr )
  {
    v377.accelMaxDipAngle = 0.0;
    v377.accelRotChangeSpeed = 0.0;
    v377.strafeRightTiltAngle = 0.0;
    v377.strafeLeftTiltAngle = 0.0;
    valueFloat = hands_lagClamp.valueFloat;
    v363 = hands_lagClamp.valueFloat;
    v21 = hands_lagScale.valueFloat;
    v23 = hands_lagRetain.valueFloat;
    v22 = hands_lagRecenter.valueFloat;
    v364 = hands_lagScale.valueFloat;
    v365 = hands_lagRetain.valueFloat;
    v366 = hands_lagRecenter.valueFloat;
    v377.scale = hands_rotScale.valueFloat;
    v377.minAngles.pitch = hands_rotMinAnglesX.valueFloat;
    v377.minAngles.yaw = hands_rotMinAnglesX.valueFloat;
    v377.minAngles.roll = hands_rotMinAnglesZ.valueFloat;
    v377.maxAngles.pitch = hands_rotMaxAnglesX.valueFloat;
    v377.maxAngles.yaw = hands_rotMaxAnglesX.valueFloat;
    HIBYTE(v368[5]) = 0;
    v377.retain = hands_rotRetain.valueFloat;
    v377.extraYawMultiplier = hands_extraYawMul.valueFloat;
    v377.extraPitchMultiplier = hands_extraPitchMul.valueFloat;
    v377.maxAngles.roll = hands_rotMaxAnglesZ.valueFloat;
    v367[0] = hands_offsetAtMaxPitchX.valueFloat;
    v367[1] = hands_offsetAtMaxPitchY.valueFloat;
    v367[2] = hands_offsetAtMaxPitchZ.valueFloat;
    v368[0] = hands_offsetAtMinPitchX.valueFloat;
    v368[1] = hands_offsetAtMinPitchY.valueFloat;
    v368[2] = hands_offsetAtMinPitchZ.valueFloat;
    v24 = hands_offsetByYaw.valueFloat;
    v25 = hands_offsetByPitch.valueFloat;
    v368[3] = hands_offsetByYaw.valueFloat;
    v368[4] = hands_offsetByPitch.valueFloat;
    idDeclWeapon::handRotation_t::operator=(this: &v369, __that: &v377);
    v3 = player;
    goto LABEL_21;
  }
  if ( CurrentWeapon != nullptr )
  {
    decl = CurrentWeapon->decl;
    if ( decl != nullptr )
    {
      garageIcon_high = HIBYTE(decl[1].garageIcon);
      valueFloat = *(float *)&decl[1].internalName.data;
      v21 = *(float *)&decl[1].internalName.allocedAndFlag;
      v23 = *(float *)decl[1].internalName.baseBuffer;
      v22 = *(float *)&decl[1].internalName.baseBuffer[4];
      v32 = *(float *)&decl[1].internalName.baseBuffer[8];
      LODWORD(v356.x) = &decl[1].internalName.baseBuffer[8];
      v33 = *(float *)&decl[1].internalName.baseBuffer[12];
      HIBYTE(v368[5]) = garageIcon_high;
      v34 = *(float *)&decl[1].internalName.baseBuffer[16];
      LODWORD(v356.x) = &decl[1].description;
      v35 = *(float *)&decl[1].description.index;
      v36 = *(float *)&decl[1].boostDescription.index;
      v37 = *(float *)&decl[1].requiredName.index;
      v24 = *(float *)&decl[1].icon;
      v25 = *(float *)&decl[1].quickIcon;
      v363 = valueFloat;
      v364 = v21;
      v365 = v23;
      v366 = v22;
      v368[3] = v24;
      v368[4] = v25;
      v367[0] = v32;
      v367[1] = v33;
      v367[2] = v34;
      v368[0] = v35;
      v368[1] = v36;
      v368[2] = v37;
      idDeclWeapon::handRotation_t::operator=(
        this: &v369,
        __that: (const idDeclWeapon::handRotation_t *)&decl[1].engineeringIcon);
      idDeclWeapon::handCoverMovRot_t::operator=(
        this: &v376,
        __that: (const idDeclWeapon::handCoverMovRot_t *)&decl[1].vehicleJointName);
LABEL_21:
      strafeRotChangeSpeed = v369.strafeRotChangeSpeed;
    }
  }
  v38 = idMath::AngleNormalize360(angle: (float)(v3->ucmdTracker1.viewAngles.pitch
                                               - v3->ucmdTracker1.prevViewAngles.pitch));
  v39 = v38;
  if ( v38 > 180.0 )
    v39 = (float)((float)v38 - (float)360.0);
  v40 = idMath::AngleNormalize360(angle: (float)(v3->ucmdTracker1.viewAngles.yaw - v3->ucmdTracker1.prevViewAngles.yaw));
  v41 = v40;
  if ( v40 > 180.0 )
    v41 = (float)((float)v40 - (float)360.0);
  v43 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  v45 = v43;
  if ( this->decay[0] != 0.0 )
  {
    LODWORD(v42) = v43 - this->tzero[0];
    *(_QWORD *)&v356.x = v42;
    *(double *)&v44 = (float)((float)v42 * v369.retain);
    if ( *(double *)&v44 < -700.0 || *(double *)&v44 > 700.0 )
    {
      this->handsAngles.yaw = 0.0;
      this->decay[0] = 0.0;
    }
    else
    {
      v44 = exp(x: v44);
      this->handsAngles.yaw = this->decay[0] * (float)*(double *)&v44;
    }
  }
  if ( this->decay[1] != 0.0 )
  {
    LODWORD(v42) = v45 - this->tzero[1];
    *(_QWORD *)&v356.x = v42;
    *(double *)&v44 = (float)((float)v42 * v369.retain);
    if ( *(double *)&v44 < -700.0 || *(double *)&v44 > 700.0 )
    {
      this->handsAngles.pitch = 0.0;
      this->decay[1] = 0.0;
    }
    else
    {
      v46 = exp(x: v44);
      this->handsAngles.pitch = (float)*(double *)&v46 * this->decay[1];
    }
  }
  if ( v41 != 0.0 )
  {
    yaw = this->handsAngles.yaw;
    this->tzero[0] = v45;
    v48 = (float)-(float)((float)(v369.scale * (float)v41) - (float)yaw);
    this->handsAngles.yaw = -(float)((float)(v369.scale * (float)v41) - (float)yaw);
    this->decay[0] = v48;
  }
  if ( v39 != 0.0 )
  {
    pitch = this->handsAngles.pitch;
    this->tzero[1] = v45;
    v50 = (float)-(float)((float)(v369.scale * (float)v39) - (float)pitch);
    this->handsAngles.pitch = -(float)((float)(v369.scale * (float)v39) - (float)pitch);
    this->decay[1] = v50;
  }
  idView::GetViewPos(this: &v3->view, origin: (idVec3 *)&v375.mat[1].y, axis: &v360);
  v51 = (float)((float)(v360.mat[1].x * vec3_up.y) - (float)(v360.mat[1].y * vec3_up.x));
  v52 = (float)((float)(v360.mat[1].z * vec3_up.x) - (float)(v360.mat[1].x * vec3_up.z));
  v53 = (float)((float)(v360.mat[1].y * vec3_up.z) - (float)(v360.mat[1].z * vec3_up.y));
  v54 = __fabs((float)((float)(v360.mat[0].x
                             * (float)((float)(v360.mat[1].y * vec3_up.z) - (float)(v360.mat[1].z * vec3_up.y)))
                     + (float)((float)(v360.mat[0].y
                                     * (float)((float)(v360.mat[1].z * vec3_up.x) - (float)(v360.mat[1].x * vec3_up.z)))
                             + (float)(v360.mat[0].z
                                     * (float)((float)(v360.mat[1].x * vec3_up.y) - (float)(v360.mat[1].y * vec3_up.x))))));
  if ( v54 >= 0.0 )
  {
    if ( v54 <= 1.0 )
      v55 = v54;
    else
      v55 = 1.0;
  }
  else
  {
    v55 = 0.0;
  }
  v56 = -v369.minAngles.yaw;
  v57 = this->handsAngles.pitch;
  p_handsAngles = &this->handsAngles;
  _FP6 = (float)((float)((float)((float)-(float)((float)((float)v55 * (float)2.0) - (float)3.0) * (float)v55)
                       * (float)v55)
               - (float)0.25);
  __asm { fsel      f26, f6, f7, f0 }
  v61 = (float)(this->handsAngles.yaw * (float)_FP26);
  this->handsAngles.yaw = this->handsAngles.yaw * (float)_FP26;
  v62 = (float)((float)_FP26 * (float)v57);
  this->handsAngles.pitch = (float)_FP26 * (float)v57;
  if ( v61 < v56 || (v56 = v369.maxAngles.yaw, v61 > v369.maxAngles.yaw) )
    v61 = v56;
  v63 = v369.minAngles.pitch;
  this->handsAngles.yaw = v61;
  if ( v62 >= -v63 )
  {
    if ( v62 > v369.maxAngles.pitch )
      v62 = v369.maxAngles.pitch;
  }
  else
  {
    v62 = -v63;
  }
  p_handsAngles->pitch = v62;
  if ( v61 < 0.0000099999997 && v61 > -0.0000099999997 )
    this->handsAngles.yaw = 0.0;
  if ( v62 < 0.0000099999997 && v62 > -0.0000099999997 )
    p_handsAngles->pitch = 0.0;
  p_physicsObj = &v3->physicsObj;
  v65 = (float *)v3->physicsObj.GetPushedLinearVelocity(
                   this: (struct idPhysics_Player *)&v375,
                   result: (idVec3 *)&v3->physicsObj,
                   a3: 0);
  v67 = (float *)v3->physicsObj.GetLinearVelocity(
                   this: (struct idPhysics_Player *)&v358,
                   result: (idVec3 *)&v3->physicsObj,
                   a3: 0);
  v68 = (float)(v67[2] - v65[2]);
  v69 = (float)(v67[1] - v65[1]);
  v70 = (float)(*v67 - *v65);
  if ( ((unsigned __int8)(v3->ucmdTracker1.usercmd.upmove | v3->ucmdTracker1.usercmd.forwardmove)
      | v3->ucmdTracker1.usercmd.rightmove) != 0
    || (v71 = 1, v68 <= -10.0) )
  {
    v71 = 0;
  }
  if ( v71 != 0 )
  {
    v72 = (float)(this->lagretain - (float)v22);
    this->lagretain = this->lagretain - (float)v22;
    if ( v72 < 0.0 )
      this->lagretain = 0.0;
  }
  else
  {
    this->lagretain = v23;
  }
  v73 = -v52;
  y = v360.mat[1].y;
  rightmove = v3->ucmdTracker1.usercmd.rightmove;
  LODWORD(v66) = v3->ucmdTracker1.usercmd.forwardmove;
  *(_QWORD *)&v356.x = v66;
  x = v360.mat[1].x;
  v77 = v360.mat[1].z;
  v78 = this->swayOffset.x;
  p_swayOffset = &this->swayOffset;
  LODWORD(v356.x) = &this->swayOffset;
  v80 = (float)((float)v66 * (float)0.0078740157);
  v81 = __fabs(v80);
  this->swayOffset.x = (float)((float)((float)((float)((float)-v51 * (float)v68)
                                             + (float)((float)((float)-v53 * (float)v70)
                                                     + (float)((float)v73 * (float)v69)))
                                     * (float)v21)
                             * (float)v81)
                     + (float)v78;
  v82 = (float)((float)*(__int64 *)((char *)&v66 - 4) * (float)0.0078740157);
  this->swayOffset.y = (float)((float)((float)((float)((float)-v77 * (float)v68)
                                             + (float)((float)((float)-x * (float)v70) + (float)((float)-y * (float)v69)))
                                     * (float)v21)
                             * (float)__fabs(v82))
                     + this->swayOffset.y;
  v83 = (float)((float)((float)-vec3_up.x * (float)v70) + (float)((float)-vec3_up.y * (float)v69));
  v84 = -vec3_up.z;
  v85 = (float)((float)((float)((float)((float)v84 * (float)v68) + (float)v83) * (float)v21) + this->swayOffset.z);
  this->swayOffset.z = (float)((float)((float)((float)v84 * (float)v68) + (float)v83) * (float)v21) + this->swayOffset.z;
  v86 = this->swayOffset.x;
  v87 = this->swayOffset.y;
  lagretain = this->lagretain;
  this->swayOffset.z = (float)v85 * this->lagretain;
  this->swayOffset.y = (float)v87 * (float)lagretain;
  this->swayOffset.x = (float)v86 * (float)lagretain;
  v89 = this->swayOffset.x;
  v90 = this->swayOffset.y;
  v358.mat[0].z = this->swayOffset.z;
  v358.mat[0].y = v90;
  v358.mat[0].x = v89;
  if ( idVec3::NormalizeFast(this: v358.mat) > valueFloat )
  {
    v91 = v358.mat[0].x;
    LODWORD(v356.x) = &this->swayOffset;
    v92 = (float)(v358.mat[0].y * (float)valueFloat);
    this->swayOffset.z = v358.mat[0].z * (float)valueFloat;
    this->swayOffset.y = v92;
    p_swayOffset->x = (float)valueFloat * (float)v91;
  }
  v93 = (float)((float)(this->swayOffset.z * this->swayOffset.z)
              + (float)((float)(p_swayOffset->x * p_swayOffset->x) + (float)(this->swayOffset.y * this->swayOffset.y)));
  LODWORD(v356.x) = &this->swayOffset;
  if ( v93 < 0.00000011920929 )
  {
    this->swayOffset.z = 0.0;
    LODWORD(v356.x) = &this->swayOffset;
    this->swayOffset.y = 0.0;
    p_swayOffset->x = 0.0;
  }
  v94 = v360.mat[2].x;
  v95 = v360.mat[2].y;
  v96 = (float)(v360.mat[2].x * this->swayOffset.z);
  v97 = v360.mat[2].z;
  v98 = (float)(v360.mat[2].y * this->swayOffset.z);
  v99 = (float)(v360.mat[2].z * this->swayOffset.z);
  LODWORD(v356.x) = &this->swayOffset;
  v100 = p_swayOffset->x;
  LODWORD(v356.x) = &this->handsOffset;
  v101 = this->handsOffset.y;
  v102 = this->handsOffset.z;
  v103 = (float)((float)((float)v100 * v360.mat[0].x) + (float)v96);
  v104 = (float)((float)(v360.mat[0].y * (float)v100) + (float)v98);
  v105 = (float)((float)(v360.mat[0].z * (float)v100) + (float)v99);
  v106 = (float)(v369.extraYawMultiplier * (float)_FP26);
  v107 = (float)(v369.extraPitchMultiplier * (float)_FP26);
  v108 = (float)((float)((float)x * this->swayOffset.y) + (float)v103);
  v110 = (float)((float)((float)((float)y * this->swayOffset.y) + (float)v104) * (float)_FP26);
  v111 = (float)(p_handsOffset->x + (float)((float)((float)((float)x * this->swayOffset.y) + (float)v103) * (float)_FP26));
  v109 = (float)((float)((float)v77 * this->swayOffset.y) + (float)v105);
  p_handsOffset->x = p_handsOffset->x + (float)((float)v108 * (float)_FP26);
  this->handsOffset.y = (float)v101 + (float)v110;
  this->handsOffset.z = (float)v102 + (float)((float)v109 * (float)_FP26);
  v113 = (float)((float)y * (float)(this->handsAngles.yaw * (float)v24));
  v114 = (float)((float)v111 + (float)((float)x * (float)(this->handsAngles.yaw * (float)v24)));
  v112 = (float)((float)v77 * (float)(this->handsAngles.yaw * (float)v24));
  p_handsOffset->x = v114;
  this->handsOffset.y = (float)((float)v101 + (float)v110) + (float)v113;
  this->handsOffset.z = (float)((float)v102 + (float)((float)v109 * (float)_FP26)) + (float)v112;
  v115 = p_handsAngles->pitch;
  this->handsAngles.yaw = (float)v106 * this->handsAngles.yaw;
  v116 = (float)((float)v94 * (float)((float)v25 * (float)v115));
  v117 = (float)((float)v97 * (float)((float)v25 * (float)v115));
  v118 = (float)((float)v95 * (float)((float)v25 * (float)v115));
  v119 = this->handsOffset.y;
  v120 = (float)((float)v117 + this->handsOffset.z);
  p_handsOffset->x = (float)v116 + p_handsOffset->x;
  this->handsOffset.y = (float)v118 + (float)v119;
  this->handsOffset.z = v120;
  p_handsAngles->pitch = (float)v107 * p_handsAngles->pitch;
  IsZoomedIn = idPresentablePlayer::IsZoomedIn(ptr: v3);
  zoomBlendOut = this->zoomBlendOut;
  *(_QWORD *)&v356.x = __PAIR64__(&unk_82340000, v6);
  if ( IsZoomedIn )
    v123 = (float)((float)zoomBlendOut - (float)((float)__SPAIR64__(&unk_82340000, v6) * (float)0.0049999999));
  else
    v123 = (float)((float)((float)__SPAIR64__(&unk_82340000, v6) * (float)0.0049999999) + (float)zoomBlendOut);
  this->zoomBlendOut = v123;
  v124 = v123;
  if ( v123 >= 0.0 )
  {
    if ( v123 > 1.0 )
      v124 = 1.0;
  }
  else
  {
    v124 = 0.0;
  }
  v125 = v360.mat[0].z;
  this->zoomBlendOut = v124;
  v126 = v367;
  v127 = (float)((float)((float)-(float)((float)((float)v124 * (float)2.0) - (float)3.0) * (float)v124) * (float)v124);
  v128 = (float)((float)((float)1.0 - (float)v55)
               * (float)((float)((float)-(float)((float)((float)v124 * (float)2.0) - (float)3.0) * (float)v124)
                       * (float)v124));
  if ( v125 <= 0.0 )
    v126 = v368;
  v129 = (float)(v126[1] * (float)v128);
  v130 = (float)((float)v128 * *v126);
  v131 = (float)(v126[2] * (float)v128);
  v132 = (float)(v360.mat[1].x * (float)(v126[1] * (float)v128));
  LODWORD(v356.x) = &this->handsOffset;
  v133 = this->handsOffset.y;
  v135 = (float)((float)(v360.mat[2].z * (float)v131)
               + (float)((float)((float)v125 * (float)v130) + (float)(v360.mat[1].z * (float)v129)));
  v136 = (float)((float)(v360.mat[2].y * (float)v131)
               + (float)((float)(v360.mat[0].y * (float)v130) + (float)(v360.mat[1].y * (float)v129)));
  v134 = this->handsOffset.z;
  p_handsOffset->x = (float)((float)(v360.mat[2].x * (float)v131)
                           + (float)((float)((float)v130 * v360.mat[0].x) + (float)v132))
                   + p_handsOffset->x;
  this->handsOffset.z = (float)v135 + (float)v134;
  this->handsOffset.y = (float)v136 + (float)v133;
  Offset = idWeaponKick::GetOffset(this: &v3->weaponKick[3]);
  v138 = (float)(v360.mat[0].y * (float)Offset);
  v139 = (float)(v360.mat[0].z * (float)Offset);
  v140 = p_handsOffset->x;
  v141 = this->handsOffset.y;
  LODWORD(v356.x) = &this->handsOffset;
  v142 = this->handsOffset.z;
  p_handsOffset->x = (float)((float)Offset * v360.mat[0].x) + (float)v140;
  this->handsOffset.y = (float)v138 + (float)v141;
  this->handsOffset.z = (float)v139 + (float)v142;
  if ( p_hands->currentDualWieldState != SET_DUALWIELD_ON )
  {
    v143 = idWeaponKick::GetOffset(this: &v3->weaponKick[4]);
    LODWORD(v356.x) = &this->handsOffset;
    v144 = this->handsOffset.y;
    v145 = this->handsOffset.z;
    v146 = (float)(v360.mat[1].z * (float)-v143);
    v147 = (float)(v360.mat[1].y * (float)-v143);
    p_handsOffset->x = (float)(v360.mat[1].x * (float)-v143) + p_handsOffset->x;
    this->handsOffset.z = (float)v146 + (float)v145;
    this->handsOffset.y = (float)v147 + (float)v144;
  }
  v148 = (float)((float)((float)__fabs(v360.mat[0].z) - (float)0.5) * (float)2.0);
  if ( v148 >= 0.0 )
  {
    if ( v148 > 1.0 )
      v148 = 1.0;
  }
  else
  {
    v148 = 0.0;
  }
  _FP13 = (float)((float)((float)1.0 - (float)v148)
                - (float)((float)1.0
                        - idEnvironmentAnalyzer::GetCoverModifiedScale(
                            this: &v3->environmentAnalyzer,
                            viewDir: v360.mat,
                            getMovementScale: false)));
  __asm { fsel      f30, f13, f0, f30 }
  if ( v29 != nullptr
    && idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) < v29->nextFireTime + 750
    || idPresentablePlayer::PlayerBehavior_ContextualShimmy_IsInShimmy(this: v3)
    || idPresentablePlayer::PlayerBehavior_WallClimb_IsInWallClimb(this: v3) )
  {
    this->coverIndicationBlender = 0.0;
  }
  else if ( v29 == nullptr
         || v29->CrosshairShouldPulsate(this: v29)
         || !v3->environmentAnalyzer.forwardCollision
         || v3->environmentAnalyzer.forceLeanMode != 0
         || (unsigned __int8)idHands::IsInRestState(this: p_hands) != 0 )
  {
    this->coverIndicationBlender = -(float)((float)((float)(this->coverIndicationBlender
                                                          * (float)__SPAIR64__(&unk_82340000, v6))
                                                  * COVERINDICATIONBLENDSPEED)
                                          - this->coverIndicationBlender);
  }
  else
  {
    coverIndicationBlender = this->coverIndicationBlender;
    if ( coverIndicationBlender <= _FP30 )
    {
      if ( coverIndicationBlender < _FP30 )
      {
        _FP11 = (float)((float)((float)_FP30 - this->coverIndicationBlender) - (float)0.1);
        __asm { fsel      f10, f11, f12, f21 }
        _FP7 = (float)((float)((float)((float)((float)_FP10 * (float)__SPAIR64__(&unk_82340000, v6))
                                     * COVERINDICATIONBLENDSPEED)
                             + this->coverIndicationBlender)
                     - (float)_FP30);
        __asm { fsel      f6, f7, f30, f8 }
        this->coverIndicationBlender = _FP6;
      }
    }
    else
    {
      _FP11 = (float)((float)(this->coverIndicationBlender - (float)_FP30) - (float)0.1);
      __asm { fsel      f10, f11, f12, f21 }
      _FP7 = (float)((float)-(float)((float)((float)((float)_FP10 * (float)__SPAIR64__(&unk_82340000, v6))
                                           * COVERINDICATIONBLENDSPEED)
                                   - this->coverIndicationBlender)
                   - (float)_FP30);
      __asm { fsel      f6, f7, f8, f30 }
      this->coverIndicationBlender = _FP6;
    }
  }
  v160 = this->coverIndicationBlender;
  if ( v160 >= 0.0 )
  {
    if ( v160 > 1.0 )
      v160 = 1.0;
  }
  else
  {
    v160 = 0.0;
  }
  this->coverIndicationBlender = v160;
  if ( v160 < 0.000099999997 )
    this->coverIndicationBlender = 0.0;
  v161 = (float)((float)((float)-(float)((float)((float)(this->coverIndicationBlender * (float)v127) * (float)2.0)
                                       - (float)3.0)
                       * (float)(this->coverIndicationBlender * (float)v127))
               * (float)(this->coverIndicationBlender * (float)v127));
  idPresentablePlayer::PlayerBehavior_Lean_GetHandsOffsetScale(this: v3, scale: &v372);
  v162 = this->currentLeanScale.y;
  if ( v162 >= v372.y )
  {
    if ( v162 <= v372.y )
      goto LABEL_110;
    _FP12 = (float)((float)(this->currentLeanScale.y
                          - (float)((float)__SPAIR64__(&unk_82340000, v6) * (float)0.0049999999))
                  - v372.y);
    __asm { fsel      f11, f12, f0, f13 }
  }
  else
  {
    _FP12 = (float)((float)(this->currentLeanScale.y
                          + (float)((float)__SPAIR64__(&unk_82340000, v6) * (float)0.0049999999))
                  - v372.y);
    __asm { fsel      f11, f12, f13, f0 }
  }
  this->currentLeanScale.y = _FP11;
LABEL_110:
  p_currentLeanScale = &this->currentLeanScale;
  v167 = this->currentLeanScale.x;
  if ( v167 >= v372.x )
  {
    if ( v167 <= v372.x )
      goto LABEL_115;
    _FP12 = (float)((float)(this->currentLeanScale.x
                          - (float)((float)__SPAIR64__(&unk_82340000, v6) * (float)0.0049999999))
                  - v372.x);
    __asm { fsel      f11, f12, f13, f0 }
  }
  else
  {
    _FP12 = (float)((float)(this->currentLeanScale.x
                          + (float)((float)__SPAIR64__(&unk_82340000, v6) * (float)0.0049999999))
                  - v372.x);
    __asm { fsel      f11, f12, f0, f13 }
  }
  p_currentLeanScale->x = _FP11;
LABEL_115:
  v171 = this->currentLeanScale.y;
  if ( v171 >= -1.0 )
  {
    if ( v171 > 1.0 )
      v171 = 1.0;
  }
  else
  {
    v171 = -1.0;
  }
  v172 = p_currentLeanScale->x;
  this->currentLeanScale.y = v171;
  if ( v172 >= -1.0 )
  {
    if ( v172 > 1.0 )
      v172 = 1.0;
  }
  else
  {
    v172 = -1.0;
  }
  p_currentLeanScale->x = v172;
  LODWORD(v356.x) = &this->currentLeanScale;
  v173 = (float)(p_currentLeanScale->x * (float)v127);
  v174 = (float)((float)v127 * this->currentLeanScale.y);
  p_currentLeanScale->x = p_currentLeanScale->x * (float)v127;
  this->currentLeanScale.y = v174;
  v175 = v173;
  if ( v173 >= 0.0 )
  {
    v176 = v376.offsetRight.z;
    v177 = v376.offsetRight.y;
    v178 = v376.rotRight.z;
    v179 = v376.rotRight.y;
    v180 = v376.offsetRight.x;
    v181 = v376.rotRight.x;
  }
  else
  {
    v176 = v376.offsetLeft.z;
    v175 = -v173;
    v177 = v376.offsetLeft.y;
    v178 = v376.rotLeft.z;
    v179 = v376.rotLeft.y;
    v180 = v376.offsetLeft.x;
    v181 = v376.rotLeft.x;
  }
  v182 = (float)((float)v178 * (float)v175);
  v183 = (float)((float)v176 * (float)v175);
  v356.x = v175;
  v184 = (float)((float)v181 * (float)v175);
  v185 = (float)((float)v180 * (float)v175);
  v186 = (float)((float)v179 * (float)v175);
  v187 = (float)((float)v177 * (float)v175);
  v188 = this->currentLeanScale.y;
  if ( v188 >= 0.0 )
  {
    v189 = (float)(v376.offsetUp.y * this->currentLeanScale.y);
    v190 = (float)(v376.rotUp.y * this->currentLeanScale.y);
    v192 = (float)((float)(v376.offsetUp.x * this->currentLeanScale.y) + (float)v185);
    v191 = (float)((float)(v376.rotUp.x * this->currentLeanScale.y) + (float)v184);
    v194 = (float)((float)v183 + (float)(v376.offsetUp.z * this->currentLeanScale.y));
    v193 = (float)((float)v182 + (float)(v376.rotUp.z * this->currentLeanScale.y));
    v356.x = this->currentLeanScale.y;
  }
  else
  {
    v356.x = -v188;
    v189 = (float)(v376.offsetDown.y * v356.x);
    v190 = (float)(v376.rotDown.y * v356.x);
    v191 = (float)((float)(v376.rotDown.x * v356.x) + (float)v184);
    v192 = (float)((float)(v376.offsetDown.x * v356.x) + (float)v185);
    v193 = (float)((float)v182 + (float)(v376.rotDown.z * v356.x));
    v194 = (float)((float)v183 + (float)(v376.offsetDown.z * v356.x));
  }
  v195 = (float)((float)v186 + (float)v190);
  v196 = (float)((float)v187 + (float)v189);
  if ( v161 > 0.0 )
  {
    v194 = (float)((float)v194 + (float)((float)(v376.offsetIndication.z - (float)v194) * (float)v161));
    v196 = (float)((float)((float)v187 + (float)v189)
                 + (float)((float)(v376.offsetIndication.y - (float)((float)v187 + (float)v189)) * (float)v161));
    v193 = (float)((float)v193 + (float)((float)(v376.rotIndication.z - (float)v193) * (float)v161));
    v195 = (float)((float)((float)v186 + (float)v190)
                 + (float)((float)(v376.rotIndication.y - (float)((float)v186 + (float)v190)) * (float)v161));
    v192 = (float)((float)((float)(v376.offsetIndication.x - (float)v192) * (float)v161) + (float)v192);
    v191 = (float)((float)((float)(v376.rotIndication.x - (float)v191) * (float)v161) + (float)v191);
  }
  v197 = p_handsOffset->x;
  v198 = this->handsOffset.y;
  v199 = this->handsOffset.z;
  LODWORD(v356.x) = &v3->firstPersonViewAxis;
  v200 = (float)((float)(v3->firstPersonViewAxis.mat[2].z * (float)v194)
               + (float)(v3->firstPersonViewAxis.mat[1].z * (float)v196));
  v201 = (float)((float)(v3->firstPersonViewAxis.mat[2].x * (float)v194)
               + (float)(v3->firstPersonViewAxis.mat[1].x * (float)v196));
  v202 = (float)((float)(v3->firstPersonViewAxis.mat[0].y * (float)v192)
               + (float)((float)(v3->firstPersonViewAxis.mat[2].y * (float)v194)
                       + (float)(v3->firstPersonViewAxis.mat[1].y * (float)v196)));
  v203 = (float)((float)(v3->firstPersonViewAxis.mat[0].z * (float)v192) + (float)v200);
  v204 = (float)((float)((float)v192 * v3->firstPersonViewAxis.mat[0].x) + (float)v201);
  this->handsOffset.y = (float)v202 + (float)v198;
  this->handsOffset.z = (float)v203 + (float)v199;
  p_handsOffset->x = (float)v197 + (float)v204;
  v205 = (float)((float)v195 + p_handsAngles->pitch);
  v206 = (float)((float)v193 + this->handsAngles.yaw);
  this->handsAngles.roll = v191;
  p_handsAngles->pitch = v205;
  this->handsAngles.yaw = v206;
  TreeAnimatorFromPresentable = idHands::GetTreeAnimatorFromPresentable(this: p_hands);
  if ( (unsigned __int8)idTreeAnimator::GetModelSpaceJointTransform(
                          this: TreeAnimatorFromPresentable,
                          pose: DRIVER_MODEL,
                          jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)0x20,
                          origin: &v361,
                          axis: v382) != 0 )
  {
    v209 = (float)((float)((float)((float)(v369.accelRotChangeSpeed * (float)v81) * (float)0.30000001) + (float)1.0)
                 * v369.accelRotChangeSpeed);
    if ( v80 <= 0.00000011920929 )
    {
      accelRotValue = this->accelRotValue;
      if ( v80 >= -0.00000011920929 )
      {
        if ( accelRotValue >= 0.0 )
        {
          _FP13 = (float)-(float)((float)((float)((float)((float)((float)(v369.accelRotChangeSpeed * (float)v81)
                                                                * (float)0.30000001)
                                                        + (float)1.0)
                                                * v369.accelRotChangeSpeed)
                                        * (float)__SPAIR64__(&unk_82340000, v6))
                                - this->accelRotValue);
          __asm { fsel      f12, f13, f13, f31 }
        }
        else
        {
          _FP13 = (float)((float)((float)((float)((float)((float)(v369.accelRotChangeSpeed * (float)v81)
                                                        * (float)0.30000001)
                                                + (float)1.0)
                                        * v369.accelRotChangeSpeed)
                                * (float)__SPAIR64__(&unk_82340000, v6))
                        + this->accelRotValue);
          __asm { fsel      f12, f13, f31, f13 }
        }
        this->accelRotValue = _FP12;
      }
      else
      {
        if ( accelRotValue > 0.0 )
          this->accelRotValue = this->accelRotValue - (float)1.0;
        _FP12 = (float)((float)-(float)((float)((float)v209 * (float)__SPAIR64__(&unk_82340000, v6))
                                      - this->accelRotValue)
                      - (float)-1.0);
        __asm { fsel      f11, f12, f13, f27 }
        this->accelRotValue = _FP11;
      }
    }
    else
    {
      if ( this->accelRotValue < 0.0 )
        this->accelRotValue = this->accelRotValue + (float)1.0;
      _FP12 = (float)((float)((float)((float)v209 * (float)__SPAIR64__(&unk_82340000, v6)) + this->accelRotValue)
                    - (float)1.0);
      __asm { fsel      f11, f12, f15, f13 }
      this->accelRotValue = _FP11;
    }
    *(double *)&v208 = (float)((float)__fabs(this->accelRotValue) * (float)3.1415927);
    v218 = sin(x: v208);
    LODWORD(v219) = this->landChange;
    HIDWORD(v219) = &unk_821C0000;
    decay_active = this->decay_active;
    *(_QWORD *)&v356.x = v219;
    v221 = (float)((float)((float)((float)((float)-(float)((float)((float)*(double *)&v218 * (float)2.0) - (float)3.0)
                                         * v369.accelMaxDipAngle)
                                 * (float)*(double *)&v218)
                         * (float)*(double *)&v218)
                 - (float)((float)((float)((float)v219 * (float)0.03125) * *(float *)&v357) * (float)15.0));
    if ( decay_active )
    {
      CrouchDecay = idBobCycle::GetCrouchDecay(this);
      LODWORD(v223) = pm_normalviewheight.valueInteger - pm_crouchviewheight.valueInteger;
      *(_QWORD *)&v356.x = v223;
      v224 = __fabs((float)((float)CrouchDecay / (float)v223));
      *(double *)&v225 = (float)((float)((float)((float)-(float)((float)((float)v224 * (float)2.0) - (float)3.0)
                                               * (float)v224)
                                       * (float)v224)
                               * (float)3.1415927);
      v226 = sin(x: v225);
      v221 = (float)((float)((float)*(double *)&v226 * (float)2.25) + (float)v221);
    }
    p_handsAngles->pitch = (float)v221 + p_handsAngles->pitch;
    v373.x = 0.0;
    v373.y = -1.0;
    v373.z = 0.0;
    *(idVec3 *)&v358.mat[1].y = v361;
    *(float *)&v357 = (float)-v221 * idMath::M_DEG2RAD;
    idVec3::RotateSelf(
      this: (idVec3 *)&v358.mat[1].y,
      axis: &v373,
      angle: (idTypesafeNumber<float,enum RadiansUnique_t> *)&v357);
    v227 = v361.z;
    v228 = v361.y;
    v229 = v361.x;
    v230 = (float)(v361.z - v358.mat[2].x);
    v231 = (float)(v361.y - v358.mat[1].z);
    v232 = (float)(v361.x - v358.mat[1].y);
    if ( v82 <= 0.00000011920929 )
    {
      if ( v82 >= -0.00000011920929 )
      {
        if ( this->strafeRotValue >= 0.0 )
        {
          _FP13 = (float)-(float)((float)((float)strafeRotChangeSpeed * (float)__SPAIR64__(&unk_82340000, v6))
                                - this->strafeRotValue);
          __asm { fsel      f9, f13, f13, f31 }
        }
        else
        {
          _FP13 = (float)((float)((float)strafeRotChangeSpeed * (float)__SPAIR64__(&unk_82340000, v6))
                        + this->strafeRotValue);
          __asm { fsel      f9, f13, f31, f13 }
        }
        this->strafeRotValue = _FP9;
      }
      else
      {
        _FP9 = (float)((float)-(float)((float)((float)strafeRotChangeSpeed * (float)__SPAIR64__(&unk_82340000, v6))
                                     - this->strafeRotValue)
                     - (float)-1.0);
        __asm { fsel      f8, f9, f13, f27 }
        this->strafeRotValue = _FP8;
      }
    }
    else
    {
      _FP9 = (float)((float)((float)((float)strafeRotChangeSpeed * (float)__SPAIR64__(&unk_82340000, v6))
                           + this->strafeRotValue)
                   - (float)1.0);
      __asm { fsel      f8, f9, f15, f13 }
      this->strafeRotValue = _FP8;
    }
    strafeRotValue = this->strafeRotValue;
    if ( strafeRotValue <= 0.0 )
      strafeLeftTiltAngle = v369.strafeLeftTiltAngle;
    else
      strafeLeftTiltAngle = v369.strafeRightTiltAngle;
    v242 = __fabs(strafeRotValue);
    roll = this->handsAngles.roll;
    v358.mat[1].y = v229;
    v358.mat[1].z = v228;
    v358.mat[2].x = v227;
    v374.x = -1.0;
    v374.y = 0.0;
    v374.z = 0.0;
    this->handsAngles.roll = (float)((float)((float)((float)-(float)((float)((float)v242 * (float)2.0) - (float)3.0)
                                                   * (float)strafeLeftTiltAngle)
                                           * (float)v242)
                                   * (float)v242)
                           + (float)roll;
    *(float *)&v357 = (float)-(float)((float)((float)((float)((float)-(float)((float)((float)v242 * (float)2.0)
                                                                            - (float)3.0)
                                                            * (float)strafeLeftTiltAngle)
                                                    * (float)v242)
                                            * (float)v242)
                                    + (float)roll)
                    * idMath::M_DEG2RAD;
    idVec3::RotateSelf(
      this: (idVec3 *)&v358.mat[1].y,
      axis: &v374,
      angle: (idTypesafeNumber<float,enum RadiansUnique_t> *)&v357);
    LODWORD(v356.x) = &this->handsOffset;
    v244 = this->handsOffset.y;
    v246 = (float)((float)(v3->firstPersonViewAxis.mat[1].z * (float)((float)(v361.y - v358.mat[1].z) + (float)v231))
                 + (float)((float)(v3->firstPersonViewAxis.mat[0].z
                                 * (float)((float)(v361.x - v358.mat[1].y) + (float)v232))
                         + (float)(v3->firstPersonViewAxis.mat[2].z
                                 * (float)((float)(v361.z - v358.mat[2].x) + (float)v230))));
    v248 = (float)((float)((float)((float)((float)(v361.x - v358.mat[1].y) + (float)v232)
                                 * v3->firstPersonViewAxis.mat[0].x)
                         + (float)((float)(v3->firstPersonViewAxis.mat[2].x
                                         * (float)((float)(v361.z - v358.mat[2].x) + (float)v230))
                                 + (float)(v3->firstPersonViewAxis.mat[1].x
                                         * (float)((float)(v361.y - v358.mat[1].z) + (float)v231))))
                 + p_handsOffset->x);
    v247 = (float)((float)(v3->firstPersonViewAxis.mat[1].y * (float)((float)(v361.y - v358.mat[1].z) + (float)v231))
                 + (float)((float)(v3->firstPersonViewAxis.mat[0].y
                                 * (float)((float)(v361.x - v358.mat[1].y) + (float)v232))
                         + (float)(v3->firstPersonViewAxis.mat[2].y
                                 * (float)((float)(v361.z - v358.mat[2].x) + (float)v230))));
    v245 = this->handsOffset.z;
    p_handsOffset->x = v248;
    this->handsOffset.z = (float)v246 + (float)v245;
    this->handsOffset.y = (float)v247 + (float)v244;
  }
  idBobCycle::EvaluateScale(this);
  currentScale = this->currentScale;
  v250 = this->viewBob.z;
  LODWORD(v356.x) = &this->viewBob;
  this->viewBob.y = (float)currentScale * this->viewBob.y;
  this->viewBob.z = (float)currentScale * (float)v250;
  LODWORD(v356.x) = &this->handsOffset;
  this->viewBob.x = (float)currentScale * this->viewBob.x;
  LODWORD(v356.x) = &this->handsAngles;
  v251 = this->handsOffset.z;
  v252 = this->currentScale;
  v253 = p_handsOffset->x;
  this->handsOffset.y = this->currentScale * this->handsOffset.y;
  this->handsOffset.z = (float)v252 * (float)v251;
  p_handsOffset->x = (float)v253 * (float)v252;
  v254 = this->handsAngles.roll;
  v255 = this->currentScale;
  v256 = (float)(this->currentScale * this->handsAngles.yaw);
  p_handsAngles->pitch = this->currentScale * p_handsAngles->pitch;
  this->handsAngles.yaw = v256;
  this->handsAngles.roll = (float)v255 * (float)v254;
  if ( v29 != nullptr )
  {
    IronSightsOffset = idWeapon::GetIronSightsOffset(this: v29);
    v258 = (float)(IronSightsOffset->z * (float)((float)1.0 - (float)v127));
    v259 = (float)(IronSightsOffset->y * (float)((float)1.0 - (float)v127));
    v260 = v3->firstPersonViewAxis.mat[2].x;
    v261 = IronSightsOffset->x;
    LODWORD(v356.x) = &v3->firstPersonViewAxis;
    v262 = v3->firstPersonViewAxis.mat[1].z;
    v263 = (float)(v3->firstPersonViewAxis.mat[1].y * (float)v259);
    LODWORD(v356.x) = &this->handsOffset;
    v265 = this->handsOffset.z;
    v266 = (float)((float)((float)((float)((float)1.0 - (float)v127) * (float)v261) * v3->firstPersonViewAxis.mat[0].x)
                 + (float)((float)(v3->firstPersonViewAxis.mat[1].x * (float)v259) + (float)((float)v260 * (float)v258)));
    v267 = (float)((float)(v3->firstPersonViewAxis.mat[2].z * (float)v258)
                 + (float)((float)(v3->firstPersonViewAxis.mat[0].z
                                 * (float)((float)((float)1.0 - (float)v127) * (float)v261))
                         + (float)((float)v262 * (float)v259)));
    v268 = (float)((float)(v3->firstPersonViewAxis.mat[2].y * (float)v258)
                 + (float)((float)(v3->firstPersonViewAxis.mat[0].y
                                 * (float)((float)((float)1.0 - (float)v127) * (float)v261))
                         + (float)v263));
    v264 = this->handsOffset.y;
    p_handsOffset->x = (float)v266 + p_handsOffset->x;
    this->handsOffset.z = (float)v267 + (float)v265;
    this->handsOffset.y = (float)v268 + (float)v264;
  }
  time = idPresentablePlayer::GetDecayParams(this: v3, crouch: true)->time;
  linear = idPresentablePlayer::GetDecayParams(this: v3, crouch: true)->linear;
  lambda = idPresentablePlayer::GetDecayParams(this: v3, crouch: true)->lambda;
  v272 = idPresentablePlayer::GetDecayParams(this: v3, crouch: false)->time;
  v273 = idPresentablePlayer::GetDecayParams(this: v3, crouch: false)->linear;
  v274 = idPresentablePlayer::GetDecayParams(this: v3, crouch: false)->lambda;
  if ( !idPresentablePlayer::PlayerBehavior_SprintSlide_IsSliding(this: v3)
    && this->crouching != (unsigned __int8)idPhysics_Player::IsCrouching(this: &v3->physicsObj) )
  {
    IsCrouching = idPhysics_Player::IsCrouching(this: &v3->physicsObj);
    instantCrouchChange = this->instantCrouchChange;
    this->crouching = IsCrouching;
    if ( !instantCrouchChange )
    {
      LODWORD(v278) = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      *(_QWORD *)&v356.x = v278;
      v280 = idParametricDecay::Evaluate(this: &this->crouch_decay, t: (float)v278);
      if ( v280 == 0.0 )
        this->decay_active = false;
      if ( this->decay_active )
      {
        v289 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        t0 = this->crouch_decay.t0;
        *(_QWORD *)&v356.x = __PAIR64__(&unk_82340000, v289);
        v291 = 0.016659999;
        v292 = (float)((float)((float)__SPAIR64__(&unk_82340000, v289) - (float)t0) / this->crouch_decay.tdelta);
        if ( v292 >= 0.016659999 )
        {
          if ( v292 <= 1.0 )
            v291 = v292;
          else
            v291 = 1.0;
        }
        p_gameTimeManager = &clientGame->gameTimeManager;
        if ( this->crouching )
        {
          LODWORD(v301) = idGameTimeManager::GetGameMs(this: p_gameTimeManager, type: GAMETIME_SCALED);
          *(_QWORD *)&v356.x = __PAIR64__(v301, time);
          v296 = lambda;
          v297 = linear;
          v357 = v301;
          v298 = v301;
          LODWORD(v302) = pm_normalviewheight.valueInteger - pm_crouchviewheight.valueInteger;
          *(_QWORD *)&v358.mat[0].x = v302;
          v300 = (float)v302;
          v299 = (float)((float)__SPAIR64__(v301, time) * (float)v291);
        }
        else
        {
          v294 = __PAIR64__(v272, idGameTimeManager::GetGameMs(this: p_gameTimeManager, type: GAMETIME_SCALED));
          v357 = v294;
          LODWORD(v295) = pm_crouchviewheight.valueInteger - pm_normalviewheight.valueInteger;
          v296 = v274;
          v297 = v273;
          *(_QWORD *)&v356.x = v295;
          v298 = v294;
          v299 = (float)((float)*(__int64 *)((char *)&v294 + 4) * (float)v291);
          v300 = (float)v295;
        }
        idParametricDecay::Init(
          this: &this->crouch_decay,
          delta: (float)((float)v300 + (float)v280),
          linear: v297,
          t0: (float)v298,
          tdelta: v299,
          lambda: v296);
      }
      else
      {
        HIDWORD(v281) = this->crouching;
        LODWORD(v279) = pm_normalviewheight.valueInteger - pm_crouchviewheight.valueInteger;
        v282 = &clientGame->gameTimeManager;
        *(_QWORD *)&v356.x = v279;
        v283 = (float)v279;
        if ( HIDWORD(v281) != 0 )
        {
          LODWORD(v281) = time;
          *(_QWORD *)&v356.x = v281;
          LODWORD(v284) = idGameTimeManager::GetGameMs(this: v282, type: GAMETIME_SCALED);
          v285 = linear;
          v286 = v283;
          v287 = lambda;
        }
        else
        {
          *(_QWORD *)&v356.x = (unsigned int)v272;
          LODWORD(v284) = idGameTimeManager::GetGameMs(this: v282, type: GAMETIME_SCALED);
          v285 = v273;
          v286 = -v283;
          v287 = v274;
        }
        v288 = (float)*(__int64 *)&v356.x;
        *(_QWORD *)&v356.x = v284;
        idParametricDecay::Init(
          this: &this->crouch_decay,
          delta: v286,
          linear: v285,
          t0: (float)v284,
          tdelta: v288,
          lambda: v287);
        this->decay_active = true;
      }
    }
    this->instantCrouchChange = false;
  }
  if ( this->decay_active )
  {
    LODWORD(v303) = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    *(_QWORD *)&v358.mat[0].x = v303;
    v305 = idParametricDecay::Evaluate(this: &this->crouch_decay, t: (float)v303);
    if ( g_drawCrouch.valueInteger != 0 )
    {
      v306 = idBobCycle::graphDecay;
      if ( idBobCycle::graphDecay == nullptr )
      {
        v306 = console->CreateGraph(this: console, a2: 100);
        idBobCycle::graphDecay = v306;
      }
      v307 = v305;
      if ( !this->crouching )
      {
        LODWORD(v304) = pm_normalviewheight.valueInteger - pm_crouchviewheight.valueInteger;
        *(_QWORD *)&v358.mat[0].x = v304;
        v307 = (float)((float)v304 + (float)v305);
      }
      idDebugGraph::SetValue(
        this: v306,
        b: -1,
        value: (float)((float)v307 * (float)0.016666668),
        color: v275,
        a5: &idColor::colorGreen.r);
    }
    if ( v305 == 0.0 )
    {
      this->decay_active = false;
    }
    else
    {
      this->viewBob.z = (float)v305 + this->viewBob.z;
      this->handsOffset.z = (float)v305 + this->handsOffset.z;
    }
  }
  v308 = v358.mat[1].x;
  v309 = v371->yaw;
  v310 = v371->roll;
  v311 = *(_DWORD *)LODWORD(v358.mat[1].x) == 0;
  v358.mat[0].x = v371->pitch;
  v358.mat[0].y = v309;
  v358.mat[0].z = v310;
  if ( !v311
    && p_physicsObj->GetWaterEntNum(this: &v3->physicsObj) > 0
    && (v312 = p_physicsObj->GetWaterEntNum(this: &v3->physicsObj),
        (v313 = idDynamicWaterEntity::CastTo(c: (idDynamicWaterEntity *)gameLocal->entities.ptr[v312])) != nullptr)
    && (*(float *)&v357 = 0.0,
        v356 = *(idVec3 *)&v375.mat[1].y,
        (unsigned __int8)idDynamicWaterEntity::SetPositionOnSurface(
                           this: v313,
                           pos: &v356,
                           waveHeight: (float *)&v357,
                           normal: &v362) != 0) )
  {
    if ( v362.z < 0.0 )
    {
      v362.z = -v362.z;
      v362.x = -v362.x;
      v362.y = -v362.y;
    }
    v314 = v3->origin.z;
    v315 = ((double (__fastcall *)(idPhysics_Player *))p_physicsObj->GetWaterSurfaceWrldHeight)(a1: &v3->physicsObj);
    v316 = this->viewBob.z;
    _FP7 = (float)((float)1.0 - (float)((float)((float)((float)v315 - (float)v314) - fullWaveAtDepth) / noWaveAtDepth));
    __asm { fsel      f6, f7, f7, f31 }
    _FP5 = (float)((float)_FP6 - (float)1.0);
    __asm { fsel      f31, f5, f15, f6 }
    v321 = (float)((float)_FP31 * *(float *)&v357);
    *(float *)&v357 = (float)_FP31 * *(float *)&v357;
    this->viewBob.z = (float)v321 + (float)v316;
    if ( *(_DWORD *)LODWORD(v308) != 2 )
    {
      v321 = (float)((float)v321 - (float)3.0);
      *(float *)&v357 = v321;
    }
    this->handsOffset.z = (float)v321 + this->handsOffset.z;
    v322 = &v380;
    v323 = &v359;
    for ( i = 9; i != 0; --i )
      *++v322 = *++v323;
    v381.mat[2].x = v362.x;
    v381.mat[2].y = v362.y;
    v381.mat[2].z = v362.z;
    idMat3::OrthoNormalizeSelf(this: &v381, prio1: 2, prio2: 0);
    v325 = &v378;
    v326 = &v359;
    for ( j = 9; j != 0; --j )
      *++v325 = *++v326;
    v379.mat[2].x = vec3_up.x;
    v379.mat[2].y = vec3_up.y;
    v379.mat[2].z = vec3_up.z;
    idMat3::OrthoNormalizeSelf(this: &v379, prio1: 2, prio2: 0);
    idMat3::ToAngles(this: &v358, result: (idAngles *)&v379);
    idMat3::ToAngles(this: &v375, result: (idAngles *)&v381);
    v328 = (float)((float)_FP31 * (float)(v375.mat[0].x - v358.mat[0].x));
    v329 = (float)((float)_FP31 * (float)(v375.mat[0].z - v358.mat[0].z));
  }
  else
  {
    v329 = v358.mat[0].z;
    v328 = v358.mat[0].x;
  }
  v330 = this->surfaceTiltTargetAngles.roll;
  if ( v330 >= v329 )
  {
    if ( v330 <= v329 )
      goto LABEL_208;
    _FP9 = (float)((float)(this->surfaceTiltTargetAngles.roll - (float)v329) - (float)0.1);
    __asm { fsel      f8, f9, f10, f21 }
    _FP5 = (float)((float)-(float)((float)((float)((float)_FP8 * (float)__SPAIR64__(&unk_82340000, v6))
                                         * (float)0.0024999999)
                                 - this->surfaceTiltTargetAngles.roll)
                 - (float)v329);
    __asm { fsel      f4, f5, f6, f0 }
  }
  else
  {
    _FP9 = (float)((float)((float)v329 - this->surfaceTiltTargetAngles.roll) - (float)0.1);
    __asm { fsel      f8, f9, f10, f21 }
    _FP5 = (float)((float)((float)((float)((float)_FP8 * (float)__SPAIR64__(&unk_82340000, v6)) * (float)0.0024999999)
                         + this->surfaceTiltTargetAngles.roll)
                 - (float)v329);
    __asm { fsel      f4, f5, f0, f6 }
  }
  this->surfaceTiltTargetAngles.roll = _FP4;
LABEL_208:
  v338 = this->surfaceTiltTargetAngles.pitch;
  if ( v338 < v328 )
  {
    _FP10 = (float)((float)((float)v328 - this->surfaceTiltTargetAngles.pitch) - (float)0.1);
    __asm { fsel      f9, f10, f13, f21 }
    _FP6 = (float)((float)((float)((float)((float)_FP9 * (float)__SPAIR64__(&unk_82340000, v6)) * (float)0.0024999999)
                         + this->surfaceTiltTargetAngles.pitch)
                 - (float)v328);
    __asm { fsel      f5, f6, f12, f7 }
LABEL_212:
    this->surfaceTiltTargetAngles.pitch = _FP5;
    goto LABEL_213;
  }
  if ( v338 > v328 )
  {
    _FP10 = (float)((float)(this->surfaceTiltTargetAngles.pitch - (float)v328) - (float)0.1);
    __asm { fsel      f9, f10, f13, f21 }
    _FP6 = (float)((float)-(float)((float)((float)((float)_FP9 * (float)__SPAIR64__(&unk_82340000, v6))
                                         * (float)0.0024999999)
                                 - this->surfaceTiltTargetAngles.pitch)
                 - (float)v328);
    __asm { fsel      f5, f6, f7, f12 }
    goto LABEL_212;
  }
LABEL_213:
  this->viewBobAngles.pitch = this->surfaceTiltTargetAngles.pitch + this->viewBobAngles.pitch;
  this->viewBobAngles.roll = this->viewBobAngles.roll + this->surfaceTiltTargetAngles.roll;
  if ( idBobCycle::graphDecay != nullptr )
    idBobCycle::graphDecay->enable = g_drawCrouch.valueInteger != 0;
  valueInteger = g_drawSway.valueInteger;
  if ( g_drawSway.valueInteger != 0 )
  {
    v347 = idBobCycle::graphSwayOffset;
    if ( idBobCycle::graphSwayOffset == nullptr )
    {
      idBobCycle::graphSwayOffset = console->CreateGraph(this: console, a2: 100);
      idBobCycle::graphSwayAngles = console->CreateGraph(this: console, a2: 100);
      idBobCycle::graphSwayAngles->mode = GRAPH_FILL_REVERSE;
      v347 = idBobCycle::graphSwayOffset;
    }
    v348 = (float)((float)(p_swayOffset->x * p_swayOffset->x)
                 + (float)((float)(this->swayOffset.y * this->swayOffset.y)
                         + (float)(this->swayOffset.z * this->swayOffset.z)));
    LODWORD(v356.x) = &this->swayOffset;
    idDebugGraph::SetValue(
      this: v347,
      b: -1,
      value: (float)((float)__fsqrts(v348) * (float)0.1),
      color: v275,
      a5: &idColor::colorGreen.r);
    v349 = (float)((float)(this->handsAngles.roll * this->handsAngles.roll)
                 + (float)((float)(p_handsAngles->pitch * p_handsAngles->pitch)
                         + (float)(this->handsAngles.yaw * this->handsAngles.yaw)));
    LODWORD(v356.x) = &this->handsAngles;
    idDebugGraph::SetValue(
      this: idBobCycle::graphSwayAngles,
      b: -1,
      value: (float)((float)__fsqrts(v349) * (float)0.050000001),
      color: v350,
      a5: &idColor::colorBlue.r);
    valueInteger = g_drawSway.valueInteger;
  }
  if ( idBobCycle::graphSwayOffset != nullptr )
  {
    idBobCycle::graphSwayOffset->enable = valueInteger != 0;
    idBobCycle::graphSwayAngles->enable = g_drawSway.valueInteger != 0;
  }
  v351 = g_drawBob.valueInteger;
  if ( g_drawBob.valueInteger != 0 )
  {
    v352 = idBobCycle::graphBob;
    if ( idBobCycle::graphBob == nullptr )
    {
      v352 = console->CreateGraph(this: console, a2: 100);
      v351 = g_drawBob.valueInteger;
      idBobCycle::graphBob = v352;
    }
    if ( v351 == 1 )
    {
      v353 = &idColor::colorRed;
      v354 = (float)(this->viewBob.z - (float)0.2);
      v355 = 0.3125;
    }
    else if ( v351 == 2 )
    {
      v353 = &idColor::colorGreen;
      v354 = (float)(this->viewBobAngles.roll - (float)2.2);
      v355 = 0.22727272;
    }
    else
    {
      v353 = &idColor::colorBlue;
      v354 = (float)(this->viewBobAngles.pitch - (float)1.5);
      v355 = 0.33333334;
    }
    idDebugGraph::SetValue(this: v352, b: -1, value: (float)((float)v354 * (float)v355), color: v275, a5: &v353->r);
    v351 = g_drawBob.valueInteger;
  }
  if ( idBobCycle::graphBob != nullptr )
    idBobCycle::graphBob->enable = v351 != 0;
  idPLogScope::~idPLogScope(this: &v370);
LABEL_234:
  RD_EventEnd();
}


// ========================================================================
// __unwind$489498_0
// EA  : 0x82DF95A8
// RVA : 0x00DF95A8
// PDB : w:\tech5\tungsten\game\player\bobcycle.cpp
// ========================================================================

void _unwind_489498_0()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 1072 + 772));
}


// ========================================================================
// __unwind$489499_0
// EA  : 0x82DF95D0
// RVA : 0x00DF95D0
// PDB : w:\tech5\tungsten\game\player\bobcycle.cpp
// ========================================================================

void _unwind_489499_0()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 1072 + 352));
}


// ========================================================================
// `dynamic initializer for 'g_stepup_time''
// EA  : 0x83386FB0
// RVA : 0x01386FB0
// PDB : w:\tech5\tungsten\game\player\bobcycle.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_stepup_time__()
{
  idCVar::idCVar(
    this: &g_stepup_time,
    name: "g_stepup_time",
    value: "100",
    flags: 2,
    description: "time it takes to move up a single step",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_stepup_time__);
}

