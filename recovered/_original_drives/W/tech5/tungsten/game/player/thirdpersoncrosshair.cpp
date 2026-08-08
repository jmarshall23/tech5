
// ========================================================================
// ?CenterPitch@idThirdPersonCrosshair@@QAAXXZ
// EA  : 0x82E815E8
// RVA : 0x00E815E8
// PDB : w:\tech5\tungsten\game\player\thirdpersoncrosshair.cpp
// ========================================================================

void __fastcall idThirdPersonCrosshair::CenterPitch(idThirdPersonCrosshair *this)
{
  this->goalAngles.pitch = 0.0;
}


// ========================================================================
// ?AngleTowardsGoal@idThirdPersonCrosshair@@AAAXVidAngles@@M@Z
// EA  : 0x82E815F8
// RVA : 0x00E815F8
// PDB : w:\tech5\tungsten\game\player\thirdpersoncrosshair.cpp
// ========================================================================

void __fastcall idThirdPersonCrosshair::AngleTowardsGoal(
        idThirdPersonCrosshair *this,
        idAngles *goal,
        double moveScale)
{
  double v3; // fp13
  double v4; // fp0
  double v5; // fp8
  char v6; // r11
  double v7; // fp11
  double v8; // fp9
  double v9; // fp12
  double v10; // fp11
  double v11; // fp9
  double v12; // fp12
  double v13; // fp12

  v3 = (float)(*(float *)&this - this->angles.pitch);
  v4 = (float)(*(float *)&goal - this->angles.yaw);
  v5 = (float)(*(float *)&goal - this->angles.roll);
  if ( ang_zero.pitch != v3 || ang_zero.yaw != v4 || (v6 = 1, ang_zero.roll != v5) )
    v6 = 0;
  if ( v6 == 0 )
  {
    if ( __fabs(v4) <= __fabs(v3) )
      v7 = (float)((float)(*(float *)&this - this->angles.pitch) / (float)(this->angleSpeed.pitch * (float)moveScale));
    else
      v7 = (float)((float)(*(float *)&goal - this->angles.yaw) / (float)(this->angleSpeed.yaw * (float)moveScale));
    v8 = (float)((float)((float)1.0 / (float)v7) * (float)(*(float *)&goal - this->angles.roll));
    v9 = __fabs((float)((float)((float)1.0 / (float)v7) * (float)(*(float *)&goal - this->angles.yaw)));
    v10 = __fabs((float)((float)((float)1.0 / (float)v7) * (float)(*(float *)&this - this->angles.pitch)));
    v11 = __fabs(v8);
    if ( v9 <= __fabs(v4) )
    {
      if ( v4 <= 0.0 )
        v12 = (float)(this->angles.yaw - (float)v9);
      else
        v12 = (float)(this->angles.yaw + (float)v9);
      this->angles.yaw = v12;
    }
    else
    {
      this->angles.yaw = *(float *)&goal;
    }
    if ( v10 <= __fabs(v3) )
    {
      if ( v3 <= 0.0 )
        v13 = (float)(this->angles.pitch - (float)v10);
      else
        v13 = (float)((float)v10 + this->angles.pitch);
      this->angles.pitch = v13;
    }
    else
    {
      this->angles.pitch = *(float *)&this;
    }
    if ( (float)((float)v11 * (float)moveScale) <= __fabs(v3) )
    {
      if ( v5 <= 0.0 )
        this->angles.roll = this->angles.roll - (float)v11;
      else
        this->angles.roll = this->angles.roll + (float)v11;
    }
    else
    {
      this->angles.roll = *(float *)&goal;
    }
  }
}


// ========================================================================
// ?HideModel@idThirdPersonCrosshair@@QAAXXZ
// EA  : 0x82E81758
// RVA : 0x00E81758
// PDB : w:\tech5\tungsten\game\player\thirdpersoncrosshair.cpp
// ========================================================================

void __fastcall idThirdPersonCrosshair::HideModel(idThirdPersonCrosshair *this)
{
  idRenderModelStatic *crosshairModel; // r3
  idVec4 v3; // [sp+50h] [-20h] BYREF

  crosshairModel = this->crosshairModel;
  if ( crosshairModel != nullptr )
  {
    this->crosshairEnabled = false;
    v3.x = 0.0;
    v3.y = 0.0;
    v3.z = 0.0;
    v3.w = 0.0;
    idRenderModel::SetParm(this: crosshairModel, parm: rp->Color, v4: &v3);
    idRenderModel::CommitThisFrame(this: this->crosshairModel);
  }
}


// ========================================================================
// ?UpdateCrosshairOriginAxis@idThirdPersonCrosshair@@AAAXABVidVec3@@0M@Z
// EA  : 0x82E817C8
// RVA : 0x00E817C8
// PDB : w:\tech5\tungsten\game\player\thirdpersoncrosshair.cpp
// ========================================================================

void __fastcall idThirdPersonCrosshair::UpdateCrosshairOriginAxis(
        idThirdPersonCrosshair *this,
        const idVec3 *targetOrigin,
        const idVec3 *viewOrigin,
        double radius)
{
  signed int valueInteger; // r27
  double v8; // fp2
  double v10; // fp11
  double v11; // fp11
  double v12; // fp26
  double v13; // fp29
  double v14; // fp28
  int v15; // r3
  __int64 v16; // r6
  double v17; // fp0
  int v18; // r11
  __int64 v19; // r3
  long double v20; // fp2
  long double v21; // fp2
  idRenderModelStatic *crosshairModel; // r11
  double v23; // fp1
  double v24; // fp10
  double v25; // fp9
  double v28; // fp1
  double v29; // fp8
  double v30; // fp5
  double v31; // fp3
  double v32; // fp2
  double v33; // fp1
  double v34; // fp7
  double v35; // fp6
  double v36; // fp5
  double v39; // fp11
  double v40; // fp1
  const idMat3 *v41; // r3
  idMat3 v42[3]; // [sp+60h] [-A0h] BYREF
  const idVec3 v43; // 0:^50.12

  if ( this->crosshairModel != nullptr )
  {
    v43 = *targetOrigin;
    valueInteger = ch_animateTime.valueInteger;
    _FP3 = (float)((float)((float)((float)(v43.x - viewOrigin->x) * (float)(v43.x - viewOrigin->x))
                         + (float)((float)((float)(v43.z - viewOrigin->z) * (float)(v43.z - viewOrigin->z))
                                 + (float)((float)(v43.y - viewOrigin->y) * (float)(v43.y - viewOrigin->y))))
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    v8 = (float)((float)((float)((float)(v43.x - viewOrigin->x) * (float)(v43.x - viewOrigin->x))
                       + (float)((float)((float)(v43.z - viewOrigin->z) * (float)(v43.z - viewOrigin->z))
                               + (float)((float)(v43.y - viewOrigin->y) * (float)(v43.y - viewOrigin->y))))
               * (float)0.5);
    __asm { fsel      f0, f3, f4, f0 }
    v10 = __frsqrte(_FP0);
    v11 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v10 * (float)v8)
                                                                                * (float)v10)
                                                                        - (float)1.5)
                                                        * (float)v10)
                                                * (float)v8)
                                        * (float)((float)-(float)((float)((float)((float)v10 * (float)v8) * (float)v10)
                                                                - (float)1.5)
                                                * (float)v10))
                                - (float)1.5)
                * (float)((float)-(float)((float)((float)((float)v10 * (float)v8) * (float)v10) - (float)1.5)
                        * (float)v10));
    v12 = (float)((float)((float)(v43.z - viewOrigin->z)
                        * (float)((float)-(float)((float)((float)((float)v11
                                                                * (float)((float)((float)((float)(v43.x - viewOrigin->x)
                                                                                        * (float)(v43.x - viewOrigin->x))
                                                                                + (float)((float)((float)(v43.z - viewOrigin->z)
                                                                                                * (float)(v43.z - viewOrigin->z))
                                                                                        + (float)((float)(v43.y - viewOrigin->y)
                                                                                                * (float)(v43.y - viewOrigin->y))))
                                                                        * (float)0.5))
                                                        * (float)v11)
                                                - (float)1.5)
                                * (float)v11))
                * (float)radius);
    v13 = (float)(targetOrigin->x
                - (float)((float)((float)(v43.x - viewOrigin->x)
                                * (float)((float)-(float)((float)((float)((float)v11
                                                                        * (float)((float)((float)((float)(v43.x - viewOrigin->x)
                                                                                                * (float)(v43.x - viewOrigin->x))
                                                                                        + (float)((float)((float)(v43.z - viewOrigin->z) * (float)(v43.z - viewOrigin->z))
                                                                                                + (float)((float)(v43.y - viewOrigin->y) * (float)(v43.y - viewOrigin->y))))
                                                                                * (float)0.5))
                                                                * (float)v11)
                                                        - (float)1.5)
                                        * (float)v11))
                        * (float)radius));
    v14 = (float)(v43.y
                - (float)((float)((float)(v43.y - viewOrigin->y)
                                * (float)((float)-(float)((float)((float)((float)v11
                                                                        * (float)((float)((float)((float)(v43.x - viewOrigin->x)
                                                                                                * (float)(v43.x - viewOrigin->x))
                                                                                        + (float)((float)((float)(v43.z - viewOrigin->z) * (float)(v43.z - viewOrigin->z))
                                                                                                + (float)((float)(v43.y - viewOrigin->y) * (float)(v43.y - viewOrigin->y))))
                                                                                * (float)0.5))
                                                                * (float)v11)
                                                        - (float)1.5)
                                        * (float)v11))
                        * (float)radius));
    v15 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
    HIDWORD(v16) = v15 / valueInteger * valueInteger;
    v17 = idMath::TWO_PI;
    LODWORD(v16) = ch_animateTime.valueInteger;
    v18 = __ROL4__(v15, 1);
    LODWORD(v19) = v15 % valueInteger;
    __twllei(valueInteger, 0);
    __twlgei(valueInteger & ~(v18 - 1), 0xFFFFFFFF);
    *(double *)&v20 = (float)((float)((float)v19 / (float)v16) * (float)v17);
    v21 = cos(x: v20);
    crosshairModel = this->crosshairModel;
    v23 = (float)((float)((float)*(double *)&v21 * (float)8.0) + (float)102.0);
    if ( !crosshairModel->deferredPositionInitialized || !crosshairModel->useDeferredPosition )
    {
      crosshairModel->g.origin.x = v13;
      crosshairModel->g.origin.y = v14;
      crosshairModel->g.origin.z = (float)v23 + (float)(v43.z - (float)v12);
    }
    crosshairModel->deferredOrigin.x = v13;
    crosshairModel->deferredOrigin.z = (float)v23 + (float)(v43.z - (float)v12);
    crosshairModel->deferredOrigin.y = v14;
    v24 = (float)((float)v14 - viewOrigin->y);
    v25 = (float)((float)((float)v23 + (float)(v43.z - (float)v12)) - viewOrigin->z);
    _FP4 = (float)((float)((float)((float)((float)v13 - viewOrigin->x) * (float)((float)v13 - viewOrigin->x))
                         + (float)((float)((float)v25 * (float)v25) + (float)((float)v24 * (float)v24)))
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm { fsel      f3, f4, f5, f0 }
    v28 = __frsqrte(_FP3);
    v29 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v28
                                                                                        * (float)((float)((float)((float)((float)v13 - viewOrigin->x) * (float)((float)v13 - viewOrigin->x)) + (float)((float)((float)v25 * (float)v25) + (float)((float)v24 * (float)v24)))
                                                                                                * (float)0.5))
                                                                                * (float)v28)
                                                                        - (float)1.5)
                                                        * (float)v28)
                                                * (float)((float)((float)((float)((float)v13 - viewOrigin->x)
                                                                        * (float)((float)v13 - viewOrigin->x))
                                                                + (float)((float)((float)v25 * (float)v25)
                                                                        + (float)((float)v24 * (float)v24)))
                                                        * (float)0.5))
                                        * (float)((float)-(float)((float)((float)((float)v28
                                                                                * (float)((float)((float)((float)((float)v13 - viewOrigin->x) * (float)((float)v13 - viewOrigin->x))
                                                                                                + (float)((float)((float)v25 * (float)v25) + (float)((float)v24 * (float)v24)))
                                                                                        * (float)0.5))
                                                                        * (float)v28)
                                                                - (float)1.5)
                                                * (float)v28))
                                - (float)1.5)
                * (float)((float)-(float)((float)((float)((float)v28
                                                        * (float)((float)((float)((float)((float)v13 - viewOrigin->x)
                                                                                * (float)((float)v13 - viewOrigin->x))
                                                                        + (float)((float)((float)v25 * (float)v25)
                                                                                + (float)((float)v24 * (float)v24)))
                                                                * (float)0.5))
                                                * (float)v28)
                                        - (float)1.5)
                        * (float)v28));
    v30 = (float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v28 * (float)((float)((float)((float)((float)v13 - viewOrigin->x) * (float)((float)v13 - viewOrigin->x)) + (float)((float)((float)v25 * (float)v25) + (float)((float)v24 * (float)v24))) * (float)0.5)) * (float)v28) - (float)1.5)
                                                                                        * (float)v28)
                                                                                * (float)((float)((float)((float)((float)v13 - viewOrigin->x) * (float)((float)v13 - viewOrigin->x))
                                                                                                + (float)((float)((float)v25 * (float)v25) + (float)((float)v24 * (float)v24)))
                                                                                        * (float)0.5))
                                                                        * (float)((float)-(float)((float)((float)((float)v28 * (float)((float)((float)((float)((float)v13 - viewOrigin->x) * (float)((float)v13 - viewOrigin->x)) + (float)((float)((float)v25 * (float)v25) + (float)((float)v24 * (float)v24))) * (float)0.5)) * (float)v28)
                                                                                                - (float)1.5)
                                                                                * (float)v28))
                                                                - (float)1.5)
                                                * (float)((float)-(float)((float)((float)((float)v28
                                                                                        * (float)((float)((float)((float)((float)v13 - viewOrigin->x) * (float)((float)v13 - viewOrigin->x)) + (float)((float)((float)v25 * (float)v25) + (float)((float)v24 * (float)v24)))
                                                                                                * (float)0.5))
                                                                                * (float)v28)
                                                                        - (float)1.5)
                                                        * (float)v28))
                                        * (float)((float)((float)((float)((float)v13 - viewOrigin->x)
                                                                * (float)((float)v13 - viewOrigin->x))
                                                        + (float)((float)((float)v25 * (float)v25)
                                                                + (float)((float)v24 * (float)v24)))
                                                * (float)0.5))
                                * (float)v29)
                        - (float)1.5);
    v31 = (float)((float)((float)v13 - viewOrigin->x)
                * (float)((float)v30
                        * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v28 * (float)((float)((float)((float)((float)v13 - viewOrigin->x) * (float)((float)v13 - viewOrigin->x)) + (float)((float)((float)v25 * (float)v25) + (float)((float)v24 * (float)v24))) * (float)0.5))
                                                                                                * (float)v28)
                                                                                        - (float)1.5)
                                                                        * (float)v28)
                                                                * (float)((float)((float)((float)((float)v13
                                                                                                - viewOrigin->x)
                                                                                        * (float)((float)v13
                                                                                                - viewOrigin->x))
                                                                                + (float)((float)((float)v25 * (float)v25)
                                                                                        + (float)((float)v24 * (float)v24)))
                                                                        * (float)0.5))
                                                        * (float)((float)-(float)((float)((float)((float)v28
                                                                                                * (float)((float)((float)((float)((float)v13 - viewOrigin->x) * (float)((float)v13 - viewOrigin->x)) + (float)((float)((float)v25 * (float)v25) + (float)((float)v24 * (float)v24))) * (float)0.5))
                                                                                        * (float)v28)
                                                                                - (float)1.5)
                                                                * (float)v28))
                                                - (float)1.5)
                                * (float)((float)-(float)((float)((float)((float)v28
                                                                        * (float)((float)((float)((float)((float)v13 - viewOrigin->x)
                                                                                                * (float)((float)v13 - viewOrigin->x))
                                                                                        + (float)((float)((float)v25 * (float)v25)
                                                                                                + (float)((float)v24 * (float)v24)))
                                                                                * (float)0.5))
                                                                * (float)v28)
                                                        - (float)1.5)
                                        * (float)v28))));
    v32 = (float)((float)v24
                * (float)((float)v30
                        * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v28 * (float)((float)((float)((float)((float)v13 - viewOrigin->x) * (float)((float)v13 - viewOrigin->x)) + (float)((float)((float)v25 * (float)v25) + (float)((float)v24 * (float)v24))) * (float)0.5))
                                                                                                * (float)v28)
                                                                                        - (float)1.5)
                                                                        * (float)v28)
                                                                * (float)((float)((float)((float)((float)v13
                                                                                                - viewOrigin->x)
                                                                                        * (float)((float)v13
                                                                                                - viewOrigin->x))
                                                                                + (float)((float)((float)v25 * (float)v25)
                                                                                        + (float)((float)v24 * (float)v24)))
                                                                        * (float)0.5))
                                                        * (float)((float)-(float)((float)((float)((float)v28
                                                                                                * (float)((float)((float)((float)((float)v13 - viewOrigin->x) * (float)((float)v13 - viewOrigin->x)) + (float)((float)((float)v25 * (float)v25) + (float)((float)v24 * (float)v24))) * (float)0.5))
                                                                                        * (float)v28)
                                                                                - (float)1.5)
                                                                * (float)v28))
                                                - (float)1.5)
                                * (float)((float)-(float)((float)((float)((float)v28
                                                                        * (float)((float)((float)((float)((float)v13 - viewOrigin->x)
                                                                                                * (float)((float)v13 - viewOrigin->x))
                                                                                        + (float)((float)((float)v25 * (float)v25)
                                                                                                + (float)((float)v24 * (float)v24)))
                                                                                * (float)0.5))
                                                                * (float)v28)
                                                        - (float)1.5)
                                        * (float)v28))));
    v33 = (float)((float)v25
                * (float)((float)v30
                        * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v28 * (float)((float)((float)((float)((float)v13 - viewOrigin->x) * (float)((float)v13 - viewOrigin->x)) + (float)((float)((float)v25 * (float)v25) + (float)((float)v24 * (float)v24))) * (float)0.5))
                                                                                                * (float)v28)
                                                                                        - (float)1.5)
                                                                        * (float)v28)
                                                                * (float)((float)((float)((float)((float)v13
                                                                                                - viewOrigin->x)
                                                                                        * (float)((float)v13
                                                                                                - viewOrigin->x))
                                                                                + (float)((float)((float)v25 * (float)v25)
                                                                                        + (float)((float)v24 * (float)v24)))
                                                                        * (float)0.5))
                                                        * (float)((float)-(float)((float)((float)((float)v28
                                                                                                * (float)((float)((float)((float)((float)v13 - viewOrigin->x) * (float)((float)v13 - viewOrigin->x)) + (float)((float)((float)v25 * (float)v25) + (float)((float)v24 * (float)v24))) * (float)0.5))
                                                                                        * (float)v28)
                                                                                - (float)1.5)
                                                                * (float)v28))
                                                - (float)1.5)
                                * (float)((float)-(float)((float)((float)((float)v28
                                                                        * (float)((float)((float)((float)((float)v13 - viewOrigin->x)
                                                                                                * (float)((float)v13 - viewOrigin->x))
                                                                                        + (float)((float)((float)v25 * (float)v25)
                                                                                                + (float)((float)v24 * (float)v24)))
                                                                                * (float)0.5))
                                                                * (float)v28)
                                                        - (float)1.5)
                                        * (float)v28))));
    v34 = (float)((float)((float)v33 * vec3_up.x) - (float)((float)v31 * vec3_up.z));
    v35 = (float)((float)((float)v31 * vec3_up.y) - (float)((float)v32 * vec3_up.x));
    v36 = (float)((float)((float)v32 * vec3_up.z) - (float)((float)v33 * vec3_up.y));
    _FP1 = (float)((float)((float)((float)v36 * (float)v36)
                         + (float)((float)((float)v35 * (float)v35) + (float)((float)v34 * (float)v34)))
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm { fsel      f12, f1, f2, f0 }
    v39 = __frsqrte(_FP12);
    v40 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v39
                                                                                        * (float)((float)((float)((float)v36 * (float)v36) + (float)((float)((float)v35 * (float)v35) + (float)((float)v34 * (float)v34)))
                                                                                                * (float)0.5))
                                                                                * (float)v39)
                                                                        - (float)1.5)
                                                        * (float)v39)
                                                * (float)((float)((float)((float)v36 * (float)v36)
                                                                + (float)((float)((float)v35 * (float)v35)
                                                                        + (float)((float)v34 * (float)v34)))
                                                        * (float)0.5))
                                        * (float)((float)-(float)((float)((float)((float)v39
                                                                                * (float)((float)((float)((float)v36 * (float)v36)
                                                                                                + (float)((float)((float)v35 * (float)v35) + (float)((float)v34 * (float)v34)))
                                                                                        * (float)0.5))
                                                                        * (float)v39)
                                                                - (float)1.5)
                                                * (float)v39))
                                - (float)1.5)
                * (float)((float)-(float)((float)((float)((float)v39
                                                        * (float)((float)((float)((float)v36 * (float)v36)
                                                                        + (float)((float)((float)v35 * (float)v35)
                                                                                + (float)((float)v34 * (float)v34)))
                                                                * (float)0.5))
                                                * (float)v39)
                                        - (float)1.5)
                        * (float)v39));
    v42[0].mat[0].x = (float)v36
                    * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v39 * (float)((float)((float)((float)v36 * (float)v36) + (float)((float)((float)v35 * (float)v35) + (float)((float)v34 * (float)v34))) * (float)0.5)) * (float)v39) - (float)1.5) * (float)v39) * (float)((float)((float)((float)v36 * (float)v36) + (float)((float)((float)v35 * (float)v35) + (float)((float)v34 * (float)v34))) * (float)0.5))
                                                                                            * (float)((float)-(float)((float)((float)((float)v39 * (float)((float)((float)((float)v36 * (float)v36) + (float)((float)((float)v35 * (float)v35) + (float)((float)v34 * (float)v34))) * (float)0.5)) * (float)v39) - (float)1.5) * (float)v39))
                                                                                    - (float)1.5)
                                                                    * (float)((float)-(float)((float)((float)((float)v39 * (float)((float)((float)((float)v36 * (float)v36) + (float)((float)((float)v35 * (float)v35) + (float)((float)v34 * (float)v34))) * (float)0.5)) * (float)v39)
                                                                                            - (float)1.5)
                                                                            * (float)v39))
                                                            * (float)((float)((float)((float)v36 * (float)v36)
                                                                            + (float)((float)((float)v35 * (float)v35)
                                                                                    + (float)((float)v34 * (float)v34)))
                                                                    * (float)0.5))
                                                    * (float)v40)
                                            - (float)1.5)
                            * (float)v40);
    v42[0].mat[0].y = (float)v34
                    * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v39 * (float)((float)((float)((float)v36 * (float)v36) + (float)((float)((float)v35 * (float)v35) + (float)((float)v34 * (float)v34))) * (float)0.5)) * (float)v39) - (float)1.5) * (float)v39) * (float)((float)((float)((float)v36 * (float)v36) + (float)((float)((float)v35 * (float)v35) + (float)((float)v34 * (float)v34))) * (float)0.5))
                                                                                            * (float)((float)-(float)((float)((float)((float)v39 * (float)((float)((float)((float)v36 * (float)v36) + (float)((float)((float)v35 * (float)v35) + (float)((float)v34 * (float)v34))) * (float)0.5)) * (float)v39) - (float)1.5) * (float)v39))
                                                                                    - (float)1.5)
                                                                    * (float)((float)-(float)((float)((float)((float)v39 * (float)((float)((float)((float)v36 * (float)v36) + (float)((float)((float)v35 * (float)v35) + (float)((float)v34 * (float)v34))) * (float)0.5)) * (float)v39)
                                                                                            - (float)1.5)
                                                                            * (float)v39))
                                                            * (float)((float)((float)((float)v36 * (float)v36)
                                                                            + (float)((float)((float)v35 * (float)v35)
                                                                                    + (float)((float)v34 * (float)v34)))
                                                                    * (float)0.5))
                                                    * (float)v40)
                                            - (float)1.5)
                            * (float)v40);
    v42[0].mat[0].z = (float)v35
                    * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v39 * (float)((float)((float)((float)v36 * (float)v36) + (float)((float)((float)v35 * (float)v35) + (float)((float)v34 * (float)v34))) * (float)0.5)) * (float)v39) - (float)1.5) * (float)v39) * (float)((float)((float)((float)v36 * (float)v36) + (float)((float)((float)v35 * (float)v35) + (float)((float)v34 * (float)v34))) * (float)0.5))
                                                                                            * (float)((float)-(float)((float)((float)((float)v39 * (float)((float)((float)((float)v36 * (float)v36) + (float)((float)((float)v35 * (float)v35) + (float)((float)v34 * (float)v34))) * (float)0.5)) * (float)v39) - (float)1.5) * (float)v39))
                                                                                    - (float)1.5)
                                                                    * (float)((float)-(float)((float)((float)((float)v39 * (float)((float)((float)((float)v36 * (float)v36) + (float)((float)((float)v35 * (float)v35) + (float)((float)v34 * (float)v34))) * (float)0.5)) * (float)v39)
                                                                                            - (float)1.5)
                                                                            * (float)v39))
                                                            * (float)((float)((float)((float)v36 * (float)v36)
                                                                            + (float)((float)((float)v35 * (float)v35)
                                                                                    + (float)((float)v34 * (float)v34)))
                                                                    * (float)0.5))
                                                    * (float)v40)
                                            - (float)1.5)
                            * (float)v40);
    v41 = idVec3::ToMat3(this: (idVec3 *)&v42[0].mat[1].y, result: v42);
    idRenderModel::SetAxis(this: this->crosshairModel, a: v41);
  }
}


// ========================================================================
// ?Set@idThirdPersonCrosshair@@QAAXPAVidPresentableAnimatedEntity@@PBVidDeclWeapon@@PBVidDeclAmmo@@PAVidTreeAnimator@@UtagData_t@@HVidAngles@@5M_N6@Z
// EA  : 0x82E81AA0
// RVA : 0x00E81AA0
// PDB : w:\tech5\tungsten\game\player\thirdpersoncrosshair.cpp
// ========================================================================

void __fastcall idThirdPersonCrosshair::Set(
        idThirdPersonCrosshair *this,
        idPresentableAnimatedEntity *presentable,
        const idDeclWeapon *declWeapon,
        const idDeclAmmo *declAmmo,
        idTreeAnimator *treeAnimator,
        tagData_t *tagData,
        int flags,
        idAngles *minAngles,
        double rotateSpeed,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14,
        double a15,
        double a16,
        idAngles *maxAngles,
        bool resetAngles,
        bool skipHighlight,
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
        int a32,
        int a33,
        int a34,
        int a35,
        int a36,
        float a37,
        int a38,
        int a39,
        int a40,
        int a41,
        int a42,
        float a43,
        float a44,
        float a45,
        int flags_0,
        float minAnglesa,
        float minAngles_4,
        float minAngles_8,
        int a50,
        int maxAnglesa,
        int maxAngles_4,
        int maxAngles_8,
        char a54,
        int a55,
        bool a56)
{
  idRenderModelStatic *crosshairModel; // r3

  if ( presentable != nullptr )
    this->presentable.spawnId = presentable->spawnId;
  else
    this->presentable.spawnId = 0;
  this->treeAnimator = treeAnimator;
  this->tagData.trans.x = *(float *)&treeAnimator;
  this->tagData.trans.y = *(float *)&tagData;
  this->tagData.trans.z = *(float *)&tagData;
  this->tagData.rot.x = *(float *)&flags;
  this->tagData.rot.y = *(float *)&flags;
  this->tagData.rot.z = *(float *)&minAngles;
  this->tagData.rot.w = a37;
  this->tagData.parentJoint.value = HIWORD(a38);
  this->minAngles.pitch = a43;
  this->minAngles.yaw = a44;
  this->minAngles.roll = a45;
  this->maxAngles.pitch = minAnglesa;
  this->maxAngles.yaw = minAngles_4;
  this->maxAngles.roll = minAngles_8;
  crosshairModel = this->crosshairModel;
  this->goalSpeed = rotateSpeed;
  this->flags = a40;
  this->declWeapon = declWeapon;
  this->declAmmo = declAmmo;
  if ( crosshairModel != nullptr )
  {
    crosshairModel->unlinked = true;
    crosshairModel->deleteOnSync = true;
    idRenderModel::CommitThisFrame(this: crosshairModel);
    this->crosshairModel = nullptr;
  }
  this->firing = false;
  this->skipTargetHighlight = a56;
  if ( a54 != 0 )
  {
    this->goalAngles.pitch = 0.0;
    this->goalAngles.yaw = 0.0;
    this->goalAngles.roll = 0.0;
  }
  this->angleSpeed.pitch = 5.0;
  this->angleSpeed.yaw = 5.0;
  this->angleSpeed.roll = 5.0;
  this->axis = mat3_identity;
}


// ========================================================================
// ?DetachOwner@idThirdPersonCrosshair@@QAAXXZ
// EA  : 0x82E81C38
// RVA : 0x00E81C38
// PDB : w:\tech5\tungsten\game\player\thirdpersoncrosshair.cpp
// ========================================================================

void __fastcall idThirdPersonCrosshair::DetachOwner(idThirdPersonCrosshair *this)
{
  this->presentable.spawnId = 0;
}


// ========================================================================
// ??1idThirdPersonCrosshair@@UAA@XZ
// EA  : 0x82E81C50
// RVA : 0x00E81C50
// PDB : w:\tech5\tungsten\game\player\thirdpersoncrosshair.cpp
// ========================================================================

void __fastcall idThirdPersonCrosshair::~idThirdPersonCrosshair(idThirdPersonCrosshair *this)
{
  idRenderModelStatic *crosshairModel; // r3

  this->__vftable = (idThirdPersonCrosshair_vtbl *)&idThirdPersonCrosshair::`vftable';
  crosshairModel = this->crosshairModel;
  if ( crosshairModel != nullptr )
  {
    crosshairModel->unlinked = true;
    crosshairModel->deleteOnSync = true;
    idRenderModel::CommitThisFrame(this: crosshairModel);
    this->crosshairModel = nullptr;
  }
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->validTargets);
}


// ========================================================================
// __unwind$490652
// EA  : 0x82E81CC4
// RVA : 0x00E81CC4
// PDB : w:\tech5\tungsten\game\player\thirdpersoncrosshair.cpp
// ========================================================================

void _unwind_490652()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 624));
}


// ========================================================================
// ?GetTargetPosition@idThirdPersonCrosshair@@QBA_NAAVidVec3@@@Z
// EA  : 0x82E81CF0
// RVA : 0x00E81CF0
// PDB : w:\tech5\tungsten\game\player\thirdpersoncrosshair.cpp
// ========================================================================

int __fastcall idThirdPersonCrosshair::GetTargetPosition(idThirdPersonCrosshair *this, idVec3 *pos)
{
  idPresentablePtr<idPresentable> *p_target; // r30
  idPresentable *v5; // r11
  idEntity *entity; // r3
  idPhysics *Physics; // r3
  float *v8; // r3
  double v10; // fp8
  double v11; // fp6
  idPhysics *v12; // r3
  float *v13; // r3
  double v14; // fp8
  double v15; // fp6

  p_target = &this->target;
  if ( idPresentablePtr<idPresentable>::IsValid(this: (idPresentablePtr<idPresentableActor> *)&this->target) )
  {
    v5 = idPresentablePtr<idPresentableProjectile>::operator->(this: p_target);
    entity = v5->entity;
    if ( entity == nullptr )
    {
      pos->x = v5->origin.x;
      pos->y = v5->origin.y;
      pos->z = v5->origin.z;
      return 1;
    }
    if ( this->targetId == -1 )
    {
      Physics = idEntity::GetPhysics(this: entity);
      v8 = (float *)Physics->GetAbsBounds(this: Physics, a2: -1);
      v10 = (float)(v8[4] + v8[1]);
      v11 = (float)(v8[5] + v8[2]);
      pos->x = (float)(v8[3] + *v8) * (float)0.5;
      pos->y = (float)v10 * (float)0.5;
      pos->z = (float)v11 * (float)0.5;
      return 1;
    }
    v12 = idEntity::GetPhysics(this: entity);
    v13 = (float *)v12->GetClipModel(this: v12, a2: this->targetId);
    if ( v13 != nullptr )
    {
      v14 = (float)(v13[30] + v13[27]);
      v15 = (float)(v13[31] + v13[28]);
      pos->x = (float)(v13[29] + v13[26]) * (float)0.5;
      pos->y = (float)v14 * (float)0.5;
      pos->z = (float)v15 * (float)0.5;
      return 1;
    }
  }
  return 0;
}


// ========================================================================
// ?DetermineOriginForward@idThirdPersonCrosshair@@AAAXXZ
// EA  : 0x82E81E50
// RVA : 0x00E81E50
// PDB : w:\tech5\tungsten\game\player\thirdpersoncrosshair.cpp
// ========================================================================

void __fastcall idThirdPersonCrosshair::DetermineOriginForward(idThirdPersonCrosshair *this)
{
  unsigned int spawnId; // r11
  idPresentablePtr<idPresentableActor> *p_presentable; // r28
  int v4; // r30
  idPresentable *PresentableByIndex; // r3
  float *v6; // r3
  double v7; // fp8
  idTreeAnimator *treeAnimator; // r3
  idMat3 *p_axis; // r30
  idVec3 *p_angles; // r4
  idAngles *p_y; // r3
  idAngles *v12; // r3
  double v13; // fp9
  double v14; // fp7
  idVec3 *p_forward; // r11
  float v16[4]; // [sp+50h] [-70h] BYREF
  char v17; // [sp+60h] [-60h] BYREF
  idMat3 v18[2]; // [sp+70h] [-50h] BYREF

  spawnId = this->presentable.spawnId;
  p_presentable = (idPresentablePtr<idPresentableActor> *)&this->presentable;
  v4 = spawnId & 0x3FFF;
  if ( spawnId != 0 && idClientGame::IsPresentableIndexValid(this: clientGame, index: spawnId & 0x3FFF) )
  {
    PresentableByIndex = idClientGame::GetPresentableByIndex(this: clientGame, index: v4);
    if ( PresentableByIndex->spawnId == p_presentable->spawnId )
    {
      v6 = (float *)PresentableByIndex->GetPlayerInterface_2(this: PresentableByIndex);
      if ( v6 != nullptr )
      {
        this->origin.x = v6[11633];
        this->origin.y = v6[11634];
        this->origin.z = v6[11635];
        v7 = v6[11636];
        this->forward.x = v6[11636];
        this->forward.y = v6[11637];
        this->forward.z = v6[11638];
        this->baseForward.x = v7;
        this->baseForward.y = this->forward.y;
        this->baseForward.z = this->forward.z;
        return;
      }
    }
  }
  treeAnimator = this->treeAnimator;
  if ( treeAnimator == nullptr
    || (p_axis = &this->axis,
        (unsigned __int8)idTreeAnimator::GetWorldSpaceTagTransform(
                           this: treeAnimator,
                           tagData: &this->tagData,
                           origin: &this->origin,
                           axis: &this->axis) == 0) )
  {
    if ( !idPresentablePtr<idPresentable>::IsValid(this: p_presentable) )
    {
      this->trace.endpos = vec3_origin;
      return;
    }
    this->origin = idPresentablePtr<idPresentableProjectile>::operator->(this: (idPresentablePtr<idPresentable> *)p_presentable)->origin;
    this->axis = idPresentablePtr<idPresentableProjectile>::operator->(this: (idPresentablePtr<idPresentable> *)p_presentable)->axis;
    p_axis = &this->axis;
  }
  if ( (this->flags & 0x20) != 0 )
  {
    p_angles = (idVec3 *)&this->angles;
    p_y = (idAngles *)&v17;
  }
  else
  {
    v12 = idMat3::ToAngles(this: v18, result: (idAngles *)p_axis);
    p_angles = (idVec3 *)v16;
    v13 = (float)(this->angles.roll + v12->roll);
    v14 = (float)(this->angles.yaw + v12->yaw);
    v16[0] = v12->pitch + this->angles.pitch;
    p_y = (idAngles *)&v18[0].mat[1].y;
    v16[2] = v13;
    v16[1] = v14;
  }
  this->forward = *idAngles::ToForward(this: p_y, result: p_angles);
  p_forward = &this->forward;
  if ( (this->flags & 0x80) != 0 )
    p_forward = (idVec3 *)p_axis;
  this->baseForward.x = p_forward->x;
  this->baseForward.y = p_forward->y;
  this->baseForward.z = p_forward->z;
}


// ========================================================================
// ?ClearTarget@idThirdPersonCrosshair@@QAAXXZ
// EA  : 0x82E820C0
// RVA : 0x00E820C0
// PDB : w:\tech5\tungsten\game\player\thirdpersoncrosshair.cpp
// ========================================================================

void __fastcall idThirdPersonCrosshair::ClearTarget(idThirdPersonCrosshair *this)
{
  idPresentablePtr<idPresentable> *p_presentable; // r30
  idPresentable *v3; // r3

  p_presentable = &this->presentable;
  if ( idPresentablePtr<idPresentable>::IsValid(this: (idPresentablePtr<idPresentableActor> *)&this->presentable) )
  {
    v3 = idPresentablePtr<idPresentableProjectile>::operator->(this: p_presentable);
    idPresentable::StopSound(this: v3, channel: SND_CHANNEL_WEAPON, peerMask: 0);
  }
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->validTargets);
  this->target.spawnId = 0;
  this->targetLocked = false;
  this->acquiringTarget.spawnId = 0;
  this->targetAcquiringTime = 0;
  this->lastAcquireSoundTime = 0;
  this->playedLockSound = false;
  this->firing = false;
  this->targetId = -1;
}


// ========================================================================
// ?IsValidTarget@idThirdPersonCrosshair@@AAA_NPAVidPresentable@@@Z
// EA  : 0x82E82150
// RVA : 0x00E82150
// PDB : w:\tech5\tungsten\game\player\thirdpersoncrosshair.cpp
// ========================================================================

int __fastcall idThirdPersonCrosshair::IsValidTarget(idThirdPersonCrosshair *this, idPresentable *pres)
{
  int v4; // r26
  int i; // r31
  idPresentablePtr<idPresentable> *list; // r29
  unsigned int spawnId; // r11
  int v8; // r30
  idPresentablePtr<idPresentable> *v9; // r29
  unsigned int v10; // r11
  int v11; // r30
  idPresentable *PresentableByIndex; // r3

  v4 = 0;
  if ( this->validTargets.num <= 0 )
    return 0;
  for ( i = 0; ; ++i )
  {
    list = this->validTargets.list;
    spawnId = list[i].spawnId;
    v8 = spawnId & 0x3FFF;
    if ( spawnId != 0
      && idClientGame::IsPresentableIndexValid(this: clientGame, index: spawnId & 0x3FFF)
      && idClientGame::GetPresentableByIndex(this: clientGame, index: v8)->spawnId == list[i].spawnId )
    {
      v9 = this->validTargets.list;
      v10 = v9[i].spawnId;
      v11 = v10 & 0x3FFF;
      if ( v10 == 0
        || !idClientGame::IsPresentableIndexValid(this: clientGame, index: v10 & 0x3FFF)
        || (PresentableByIndex = idClientGame::GetPresentableByIndex(this: clientGame, index: v11))->spawnId != v9[i].spawnId )
      {
        PresentableByIndex = nullptr;
      }
      if ( PresentableByIndex == pres )
        break;
    }
    if ( ++v4 >= this->validTargets.num )
      return 0;
  }
  return 1;
}


// ========================================================================
// ?WeaponCanFire@idThirdPersonCrosshair@@QAAXPBVidDeclWeapon@@_N@Z
// EA  : 0x82E82248
// RVA : 0x00E82248
// PDB : w:\tech5\tungsten\game\player\thirdpersoncrosshair.cpp
// ========================================================================

void __fastcall idThirdPersonCrosshair::WeaponCanFire(
        idThirdPersonCrosshair *this,
        const idDeclWeapon *weapon,
        bool bl)
{
  bool v5; // r11
  BOOL playedLockSound; // r11
  idPresentable *v7; // r3
  const idSoundShader *lockedSound; // r30
  idPresentable *v9; // r3

  if ( weapon == nullptr || (v5 = true, !weapon->autoLock) )
    v5 = false;
  this->autoAcquire = v5;
  if ( v5 )
  {
    playedLockSound = this->playedLockSound;
    this->weaponCanFire = bl;
    if ( playedLockSound && !bl )
    {
      v7 = idPresentablePtr<idPresentableProjectile>::operator->(this: &this->presentable);
      idPresentable::StopSound(this: v7, channel: SND_CHANNEL_WEAPON, peerMask: 0);
      this->playedLockSound = false;
    }
    if ( !this->playedLockSound
      && this->weaponCanFire
      && idPresentablePtr<idPresentable>::IsValid(this: (idPresentablePtr<idPresentableActor> *)&this->acquiringTarget)
      && idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED)
       - this->targetAcquiringTime > (int)(float)(weapon->lockTime * (float)1000.0) )
    {
      if ( weapon->lockedSound != nullptr && !this->playedLockSound && this->weaponCanFire )
      {
        this->playedLockSound = true;
        lockedSound = weapon->lockedSound;
        v9 = idPresentablePtr<idPresentableProjectile>::operator->(this: &this->presentable);
        idPresentable::StartSoundShader(
          this: v9,
          channel: SND_CHANNEL_WEAPON,
          shader: lockedSound,
          soundShaderFlags: (soundShaderFlags_t)0,
          peerMask: 0);
      }
      this->target.spawnId = this->acquiringTarget.spawnId;
      if ( (this->flags & 2) != 0 )
        this->targetLocked = true;
    }
  }
}


// ========================================================================
// ?DrawVisual@idThirdPersonCrosshair@@AAAXABVidView@@@Z
// EA  : 0x82E823A8
// RVA : 0x00E823A8
// PDB : w:\tech5\tungsten\game\player\thirdpersoncrosshair.cpp
// ========================================================================

void __fastcall idThirdPersonCrosshair::DrawVisual(idThirdPersonCrosshair *this, idView *view)
{
  idLobbyBase *v4; // r3
  idColor *v5; // r11
  float g; // r8
  float b; // r7
  float a; // r6
  int visualType; // r11
  float *v10; // r5
  double y; // fp9
  double v12; // fp6
  double z; // fp7
  double v14; // fp5
  idClientGame *v15; // r11
  double visRadius; // fp1
  idPresentable *v17; // r3
  idBounds *v18; // r3
  idPresentable *v19; // r3
  idRenderModelStatic *crosshairModel; // r3
  double visRadiusDir; // fp13
  double v22; // fp0
  double v23; // fp12
  double v24; // fp9
  double v25; // fp6
  double v26; // fp7
  double v27; // fp5
  idMat3 *p_normal; // r11
  float v29; // r8
  double v30; // fp8
  float v31; // r7
  double x; // fp11
  double v33; // fp6
  double v34; // fp10
  double v35; // fp9
  double v36; // fp7
  double v37; // fp10
  double v38; // fp7
  double v39; // fp5
  double v40; // fp6
  double v41; // fp5
  double v42; // fp12
  double v43; // fp9
  double v44; // fp7
  idColor v45; // [sp+50h] [-100h] BYREF
  idVec3 v46[2]; // [sp+60h] [-F0h] BYREF
  float v47[4]; // [sp+78h] [-D8h] BYREF
  float v48[4]; // [sp+88h] [-C8h] BYREF
  float v49[4]; // [sp+98h] [-B8h] BYREF
  float v50[4]; // [sp+A8h] [-A8h] BYREF
  float v51[4]; // [sp+B8h] [-98h] BYREF
  float v52[6]; // [sp+C8h] [-88h] BYREF
  idVec4 v53; // [sp+E0h] [-70h] BYREF
  idMat3 v54; // [sp+F0h] [-60h] BYREF
  idVec3 v55[2]; // [sp+118h] [-38h] BYREF

  v45.a = -1.0;
  v45.b = -1.0;
  v45.g = -1.0;
  v45.r = -1.0;
  if ( ch_drawVisuals.valueInteger != 0 )
  {
    if ( !common->IsMultiplayer(this: common)
      || (v4 = session->GetActingGameStateLobbyBase(this: session), v4->GetMatchParms(this: v4)->gameType != 2) )
    {
      idView::GetViewPos(this: view, origin: v55, axis: &v54);
      if ( this->flashTime < gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) )
      {
        if ( idPresentablePtr<idPresentable>::IsValid(this: (idPresentablePtr<idPresentableActor> *)&this->acquiringTarget) )
          v5 = &idColor::colorYellow;
        else
          v5 = &idColor::colorGreen;
        g = v5->g;
        b = v5->b;
        a = v5->a;
        v45.r = v5->r;
        v45.g = g;
        v45.b = b;
        v45.a = a;
      }
      else
      {
        v45 = idColor::colorRed;
      }
      visualType = this->visualType;
      if ( visualType == 1 )
      {
        v10 = v51;
        y = this->trace.endpos.y;
        v12 = (float)(this->forward.y * (float)4.0);
        z = this->trace.endpos.z;
        v14 = (float)(this->forward.z * (float)4.0);
        v15 = clientGame;
        visRadius = 10.0;
        v51[0] = this->trace.endpos.x - (float)(this->forward.x * (float)4.0);
        v46[0] = v54.mat[0];
        v51[1] = (float)y - (float)v12;
        v51[2] = (float)z - (float)v14;
LABEL_27:
        ((void (__fastcall *)(idRenderWorld *, idColor *, float *, idVec3 *, double))v15->renderWorld->DebugCircle)(
          a1: v15->renderWorld,
          a2: &v45,
          a3: v10,
          a4: v46,
          a5: visRadius);
        return;
      }
      if ( visualType != 2 )
      {
        if ( visualType != 3 )
          return;
        p_normal = (idMat3 *)&this->trace.c.normal;
        if ( this->trace.fraction >= 1.0 )
          p_normal = &v54;
        v29 = p_normal->mat[0].y;
        v30 = this->trace.endpos.z;
        v31 = p_normal->mat[0].z;
        x = this->trace.endpos.x;
        v33 = (float)(this->forward.z * (float)4.0);
        v34 = this->trace.endpos.y;
        v35 = (float)(this->forward.x * (float)4.0);
        v36 = (float)(this->forward.y * (float)4.0);
        v46[0].x = p_normal->mat[0].x;
        v46[0].y = v29;
        v46[0].z = v31;
        v49[2] = (float)v30 - (float)v33;
        v49[0] = (float)x - (float)v35;
        v49[1] = (float)v34 - (float)v36;
        ((void (__fastcall *)(idRenderWorld *, idColor *, float *, idVec3 *, double))clientGame->renderWorld->DebugCircle)(
          a1: clientGame->renderWorld,
          a2: &v45,
          a3: v49,
          a4: v46,
          a5: 12.0);
        v37 = (float)(this->forward.z * (float)4.0);
        v38 = this->trace.endpos.z;
        v39 = (float)(this->trace.endpos.y - (float)(this->forward.y * (float)4.0));
        v50[0] = this->trace.endpos.x - (float)(this->forward.x * (float)4.0);
        v50[1] = v39;
        v50[2] = (float)v38 - (float)v37;
        ((void (__fastcall *)(idRenderWorld *, idColor *, float *, idVec3 *, double))clientGame->renderWorld->DebugCircle)(
          a1: clientGame->renderWorld,
          a2: &v45,
          a3: v50,
          a4: v46,
          a5: 16.0);
        v40 = (float)(this->trace.endpos.y - (float)(this->forward.y * (float)4.0));
        v41 = (float)(this->trace.endpos.z - (float)(this->forward.z * (float)4.0));
        v47[0] = this->trace.endpos.x - (float)(this->forward.x * (float)4.0);
        v47[1] = v40;
        v47[2] = v41;
        ((void (__fastcall *)(idRenderWorld *, idColor *, float *, idVec3 *, double))clientGame->renderWorld->DebugCircle)(
          a1: clientGame->renderWorld,
          a2: &v45,
          a3: v47,
          a4: v46,
          a5: 22.0);
        v42 = (float)(this->forward.z * (float)4.0);
        v15 = clientGame;
        v43 = this->trace.endpos.z;
        visRadius = 38.0;
        v10 = v48;
        v44 = (float)(this->trace.endpos.y - (float)(this->forward.y * (float)4.0));
        v48[0] = this->trace.endpos.x - (float)(this->forward.x * (float)4.0);
        v48[1] = v44;
        v48[2] = (float)v43 - (float)v42;
        goto LABEL_27;
      }
      if ( this->crosshairModel == nullptr )
      {
        if ( ch_drawDebugVisuals.valueInteger == 0 )
          return;
        visRadiusDir = this->visRadiusDir;
        v22 = (float)(this->visRadiusDir + this->visRadius);
        this->visRadius = this->visRadiusDir + this->visRadius;
        v23 = 8.0;
        if ( v22 < 8.0 || (v23 = 16.0, v22 > 16.0) )
        {
          this->visRadiusDir = -visRadiusDir;
          this->visRadius = v23;
        }
        v10 = v52;
        v24 = this->trace.endpos.y;
        v25 = (float)(this->forward.y * (float)4.0);
        v26 = this->trace.endpos.z;
        v27 = (float)(this->forward.z * (float)4.0);
        v15 = clientGame;
        visRadius = this->visRadius;
        v52[0] = this->trace.endpos.x - (float)(this->forward.x * (float)4.0);
        v46[0] = v54.mat[0];
        v52[1] = (float)v24 - (float)v25;
        v52[2] = (float)v26 - (float)v27;
        goto LABEL_27;
      }
      if ( idPresentablePtr<idPresentable>::IsValid(this: (idPresentablePtr<idPresentableActor> *)&this->target)
        || ch_drawCrosshairAlways.valueInteger != 0 )
      {
        v17 = idPresentablePtr<idPresentableProjectile>::operator->(this: &this->target);
        v18 = v17->GetBounds(this: (idPresentable *)v46, result: (idBounds *)v17, a3: -1);
        this->crosshairPredictionRadius = idBounds::GetRadius(this: v18);
        v19 = idPresentablePtr<idPresentableProjectile>::operator->(this: &this->target);
        idThirdPersonCrosshair::UpdateCrosshairOriginAxis(
          this,
          targetOrigin: &v19->origin,
          viewOrigin: v55,
          radius: this->crosshairPredictionRadius);
        crosshairModel = this->crosshairModel;
        this->crosshairEnabled = true;
        v53.x = 1.0;
        v53.y = 1.0;
        v53.z = 1.0;
        v53.w = 1.0;
        idRenderModel::SetParm(this: crosshairModel, parm: rp->Color, v4: &v53);
        idRenderModel::CommitThisFrame(this: this->crosshairModel);
      }
      else
      {
        idThirdPersonCrosshair::HideModel(this);
      }
    }
  }
}


// ========================================================================
// ?SerializeTargetOverride@idThirdPersonCrosshair@@QAAXAAVidSerializer@@@Z
// EA  : 0x82E82950
// RVA : 0x00E82950
// PDB : w:\tech5\tungsten\game\player\thirdpersoncrosshair.cpp
// ========================================================================

void __fastcall idThirdPersonCrosshair::SerializeTargetOverride(idThirdPersonCrosshair *this, idSerializer *ser)
{
  idBitMsg *msg; // r3
  bool targetLocked; // r29
  idBitMsg *v6; // r3

  msg = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: msg, value: this->target.spawnId, numBits: 32);
  else
    this->target.spawnId = idBitMsg::ReadBits(this: msg, numBits: 32);
  targetLocked = this->targetLocked;
  v6 = ser->msg;
  if ( ser->writing )
  {
    idBitMsg::WriteBits(this: v6, value: this->targetLocked, numBits: 1);
    this->targetLocked = targetLocked;
  }
  else
  {
    this->targetLocked = (_cntlzw(idBitMsg::ReadBits(this: v6, numBits: 1) - 1) & 0x20) != 0;
  }
}


// ========================================================================
// ??0idThirdPersonCrosshair@@QAA@XZ
// EA  : 0x82E829E0
// RVA : 0x00E829E0
// PDB : w:\tech5\tungsten\game\player\thirdpersoncrosshair.cpp
// ========================================================================

idThirdPersonCrosshair *__fastcall idThirdPersonCrosshair::idThirdPersonCrosshair(idThirdPersonCrosshair *this)
{
  unsigned __int64 v1; // r11
  int v3; // ctr
  float *p_z; // r6
  float *p_y; // r7
  int v6; // ctr
  __int16 *p_granularity; // r8
  float roll; // r6
  float a; // r4

  LODWORD(v1) = 0;
  this->__vftable = (idThirdPersonCrosshair_vtbl *)&idThirdPersonCrosshair::`vftable';
  this->deferredTargetTrace[0].trace.index = v1;
  HIDWORD(v1) = allocationCurrent[242];
  this->deferredTargetTrace[0].presentable.spawnId = 0;
  this->deferredTargetTrace[0].dot = 0.0;
  this->deferredTargetTrace[1].trace.index = v1;
  this->deferredTargetTrace[1].presentable.spawnId = 0;
  this->deferredTargetTrace[1].dot = 0.0;
  this->deferredTargetTrace[2].trace.index = v1;
  this->deferredTargetTrace[2].presentable.spawnId = 0;
  this->deferredTargetTrace[2].dot = 0.0;
  this->deferredTargetTrace[3].trace.index = v1;
  this->deferredTargetTrace[3].presentable.spawnId = 0;
  this->deferredTargetTrace[3].dot = 0.0;
  this->deferredTargetTrace[4].trace.index = v1;
  this->deferredTargetTrace[4].presentable.spawnId = 0;
  this->deferredTargetTrace[4].dot = 0.0;
  this->deferredTargetTrace[5].trace.index = v1;
  v3 = 9;
  this->deferredTargetTrace[5].presentable.spawnId = 0;
  this->deferredTargetTrace[5].dot = 0.0;
  this->deferredTargetTrace[6].trace.index = v1;
  HIDWORD(v1) = &this->tagData;
  this->deferredTargetTrace[6].presentable.spawnId = 0;
  this->deferredTargetTrace[6].dot = 0.0;
  this->deferredTargetTrace[7].trace.index = v1;
  HIDWORD(v1) = allocationCurrent[242];
  this->deferredTargetTrace[7].presentable.spawnId = 0;
  this->deferredTargetTrace[7].dot = 0.0;
  this->deferredTargetTrace[8].trace.index = v1;
  HIDWORD(v1) = &ang_zero;
  this->deferredTargetTrace[8].presentable.spawnId = 0;
  this->deferredTargetTrace[8].dot = 0.0;
  this->deferredTargetTrace[9].trace.index = v1;
  this->deferredTargetTrace[9].presentable.spawnId = 0;
  this->deferredTargetTrace[9].dot = 0.0;
  this->deferredLosingTargetTrace.index = v1;
  this->presentable.spawnId = 0;
  this->baseForward = vec3_origin;
  p_z = &this->origin.z;
  p_y = &mat2_identity.mat[1].y;
  this->treeAnimator = nullptr;
  this->tagData.trans.x = 0.0;
  this->tagData.trans.y = 0.0;
  this->tagData.trans.z = 0.0;
  this->tagData.rot.x = 0.0;
  this->tagData.rot.y = 0.0;
  this->tagData.rot.z = 0.0;
  this->tagData.rot.w = 0.0;
  this->tagData.parentJoint.value = -1;
  this->minAngles = ang_zero;
  this->maxAngles = ang_zero;
  this->angleSpeed = ang_zero;
  this->origin = vec3_origin;
  do
  {
    *++p_z = *++p_y;
    --v3;
  }
  while ( v3 != 0 );
  this->forward = vec3_origin;
  v6 = 16;
  p_granularity = &this->validTargets.granularity;
  this->angles = ang_zero;
  this->absAngles = ang_zero;
  this->deltaAngles = ang_zero;
  this->goalAngles.pitch = ang_zero.pitch;
  this->goalAngles.yaw = ang_zero.yaw;
  roll = ang_zero.roll;
  this->goalSpeed = 0.0;
  this->goalAngles.roll = roll;
  this->lastGoalAngles = ang_zero;
  HIDWORD(v1) = this->validTargets.staticList;
  this->skipTargetHighlight = false;
  this->target.spawnId = 0;
  this->prevTarget.spawnId = 0;
  this->joy_extent = 0.0;
  this->flags = 0;
  this->autoAcquire = false;
  this->timeToRetainLostTarget = 0;
  this->lostTargetTime = 0;
  this->flashTime = 0;
  this->firing = false;
  this->targetLocked = false;
  this->targetCanLock = false;
  this->targetAcquiringTime = 0;
  this->visualType = 2;
  this->targetId = -1;
  this->acquiringTarget.spawnId = 0;
  this->visColor.r = idColor::colorWhite.r;
  this->visColor.g = idColor::colorWhite.g;
  this->visColor.b = idColor::colorWhite.b;
  a = idColor::colorWhite.a;
  this->visRadius = 0.0;
  this->visRadiusDir = 0.0;
  this->weaponCanFire = true;
  this->declWeapon = nullptr;
  this->declAmmo = nullptr;
  this->playedLockSound = false;
  this->visColor.a = a;
  this->lastAcquireSoundTime = 0;
  this->crosshairModel = nullptr;
  this->validTargets.size = 16;
  this->validTargets.num = 0;
  this->validTargets.granularity = 1;
  this->validTargets.list = this->validTargets.staticList;
  this->validTargets.memTag = 5;
  this->validTargets.listStatic = 1;
  do
  {
    p_granularity += 2;
    *(_DWORD *)p_granularity = 0;
    --v6;
  }
  while ( v6 != 0 );
  this->crosshairPredictionRadius = 0.0;
  this->crosshairEnabled = true;
  this->deferredTrace1.index = v1;
  this->deferredTrace2.index = v1;
  this->lockableBoundsQuery.index = v1;
  memset(Dst: &this->trace, Val: 0, Size: sizeof(this->trace));
  return this;
}


// ========================================================================
// ?Draw@idThirdPersonCrosshair@@QAAXABVidView@@@Z
// EA  : 0x82E82D80
// RVA : 0x00E82D80
// PDB : w:\tech5\tungsten\game\player\thirdpersoncrosshair.cpp
// ========================================================================

void __fastcall idThirdPersonCrosshair::Draw(idThirdPersonCrosshair *this, idView *view)
{
  double valueFloat; // fp30
  const idDeclWeapon *declWeapon; // r11
  double lockAngle; // fp26
  const idDeclWeapon *v7; // r11
  double unlockYaw; // fp27
  const idDeclWeapon *v9; // r11
  idColor *v10; // r11
  float g; // r5
  float b; // r4
  float a; // r3
  double y; // fp13
  double v15; // fp12
  double z; // fp11
  double v17; // fp10
  double x; // fp8
  double v19; // fp7
  double v20; // fp6
  double v21; // fp5
  double v22; // fp3
  double v23; // fp2
  double v24; // fp1
  double v25; // fp0
  double v26; // fp9
  double v27; // fp8
  idAngles *v28; // r3
  double v29; // fp0
  double v30; // fp13
  idVec3 *v31; // r3
  double v32; // fp4
  double v33; // fp10
  double v34; // fp2
  idVec3 *v35; // r3
  double v36; // fp7
  double v37; // fp13
  double v38; // fp5
  idVec3 *v39; // r3
  double v40; // fp7
  double v41; // fp13
  double v42; // fp5
  idVec3 *v43; // r3
  double v44; // fp5
  double v45; // fp11
  double v46; // fp3
  idVec3 *v47; // r3
  double v48; // fp5
  double v49; // fp11
  double v50; // fp3
  double v51; // fp13
  idVec3 v52; // [sp+50h] [-230h] BYREF
  float v53; // [sp+60h] [-220h] BYREF
  float v54; // [sp+64h] [-21Ch]
  float v55; // [sp+68h] [-218h]
  idVec3 v56; // [sp+70h] [-210h] BYREF
  idVec3 v57; // [sp+80h] [-200h] BYREF
  idAngles v58; // [sp+90h] [-1F0h] BYREF
  float v59[4]; // [sp+A0h] [-1E0h] BYREF
  float v60[4]; // [sp+B0h] [-1D0h] BYREF
  float v61[4]; // [sp+C0h] [-1C0h] BYREF
  float v62[4]; // [sp+D0h] [-1B0h] BYREF
  float v63[4]; // [sp+E0h] [-1A0h] BYREF
  float v64[4]; // [sp+F0h] [-190h] BYREF
  float v65[4]; // [sp+100h] [-180h] BYREF
  float v66[4]; // [sp+110h] [-170h] BYREF
  float v67[4]; // [sp+120h] [-160h] BYREF
  float v68[4]; // [sp+130h] [-150h] BYREF
  float v69[4]; // [sp+140h] [-140h] BYREF
  float v70[4]; // [sp+150h] [-130h] BYREF
  float v71[4]; // [sp+160h] [-120h] BYREF
  float v72[4]; // [sp+170h] [-110h] BYREF
  float v73[4]; // [sp+180h] [-100h] BYREF
  float v74[4]; // [sp+190h] [-F0h] BYREF
  float v75[4]; // [sp+1A0h] [-E0h] BYREF
  float v76[4]; // [sp+1B0h] [-D0h] BYREF
  float v77[4]; // [sp+1C0h] [-C0h] BYREF
  float v78[4]; // [sp+1D0h] [-B0h] BYREF
  float v79[4]; // [sp+1E0h] [-A0h] BYREF
  float v80[4]; // [sp+1F0h] [-90h] BYREF
  float v81[4]; // [sp+200h] [-80h] BYREF
  float v82[16]; // [sp+210h] [-70h] BYREF

  if ( ch_debug.valueInteger != 0 )
  {
    valueFloat = ch_lockdist.valueFloat;
    if ( ch_lockdist.valueFloat <= 0.0 )
    {
      declWeapon = this->declWeapon;
      if ( declWeapon != nullptr )
        valueFloat = declWeapon->lockOnRange;
    }
    lockAngle = ch_lockangle.valueFloat;
    if ( ch_lockangle.valueFloat <= 0.0 )
    {
      v7 = this->declWeapon;
      if ( v7 != nullptr )
        lockAngle = v7->lockAngle;
    }
    unlockYaw = ch_unlockyaw.valueFloat;
    if ( ch_unlockyaw.valueFloat <= 0.0 )
    {
      v9 = this->declWeapon;
      if ( v9 != nullptr )
        unlockYaw = v9->unlockYaw;
    }
    if ( idPresentablePtr<idPresentable>::IsValid(this: (idPresentablePtr<idPresentableActor> *)&this->target) )
      v10 = &idColor::colorGreen;
    else
      v10 = &idColor::colorWhite;
    g = v10->g;
    b = v10->b;
    a = v10->a;
    v82[0] = v10->r;
    v82[1] = g;
    v82[2] = b;
    v82[3] = a;
    clientGame->renderWorld->DebugLine(
      this: clientGame->renderWorld,
      a2: (const idVec4 *)v82,
      a3: &this->origin,
      a4: &this->trace.endpos,
      a5: 0,
      a6: false);
    y = this->trace.endpos.y;
    v15 = (float)(this->trace.endpos.x + (float)10.0);
    z = this->trace.endpos.z;
    v17 = (float)(this->trace.endpos.x - (float)10.0);
    v75[1] = 0.0;
    v75[2] = 0.0;
    v75[0] = 1.0;
    v75[3] = 1.0;
    v69[0] = v15;
    v69[1] = y;
    v69[2] = z;
    v66[0] = v17;
    v66[1] = y;
    v66[2] = z;
    clientGame->renderWorld->DebugLine(
      this: clientGame->renderWorld,
      a2: (const idVec4 *)v75,
      a3: (const idVec3 *)v66,
      a4: (const idVec3 *)v69,
      a5: 0,
      a6: false);
    x = this->trace.endpos.x;
    v19 = (float)(this->trace.endpos.y + (float)10.0);
    v20 = this->trace.endpos.z;
    v21 = (float)(this->trace.endpos.y - (float)10.0);
    v77[0] = 1.0;
    v77[1] = 0.0;
    v77[2] = 0.0;
    v77[3] = 1.0;
    v61[0] = x;
    v61[1] = v19;
    v61[2] = v20;
    v68[0] = x;
    v68[1] = v21;
    v68[2] = v20;
    clientGame->renderWorld->DebugLine(
      this: clientGame->renderWorld,
      a2: (const idVec4 *)v77,
      a3: (const idVec3 *)v68,
      a4: (const idVec3 *)v61,
      a5: 0,
      a6: false);
    v81[1] = 0.0;
    v81[2] = 0.0;
    v22 = this->trace.endpos.x;
    v23 = (float)(this->trace.endpos.z - (float)10.0);
    v24 = this->trace.endpos.y;
    v25 = (float)(this->trace.endpos.z + (float)10.0);
    v81[3] = 1.0;
    v81[0] = 1.0;
    v63[0] = v22;
    v70[2] = v23;
    v70[1] = v24;
    v63[1] = v24;
    v63[2] = v25;
    v70[0] = v22;
    clientGame->renderWorld->DebugLine(
      this: clientGame->renderWorld,
      a2: (const idVec4 *)v81,
      a3: (const idVec3 *)v70,
      a4: (const idVec3 *)v63,
      a5: 0,
      a6: false);
    v26 = -this->absAngles.yaw;
    v27 = -this->absAngles.roll;
    v52.x = -this->absAngles.pitch;
    v52.y = v26;
    v52.z = v27;
    v28 = idVec3::ToAngles(this: (idVec3 *)&v58, result: (idAngles *)&this->baseForward);
    v29 = (float)(v28->yaw - v52.y);
    v30 = (float)(v28->roll - v52.z);
    v52.x = v28->pitch - v52.x;
    v52.y = v29;
    v52.z = v30;
    idAngles::Normalize180(this: (idAngles *)&v52);
    v31 = idAngles::ToForward(this: &v58, result: &v52);
    v32 = (float)(v31->z * (float)valueFloat);
    v33 = this->origin.z;
    v34 = (float)((float)(v31->y * (float)valueFloat) + this->origin.y);
    v53 = (float)(v31->x * (float)valueFloat) + this->origin.x;
    v54 = v34;
    v55 = (float)v32 + (float)v33;
    clientGame->renderWorld->DebugLine(
      this: clientGame->renderWorld,
      a2: (const idVec4 *)&idColor::colorPurple,
      a3: &this->origin,
      a4: (const idVec3 *)&v53,
      a5: 0,
      a6: false);
    v79[0] = 1.0;
    v79[1] = 1.0;
    v79[2] = 0.0;
    v79[3] = 1.0;
    v72[0] = v53 + (float)12.0;
    v72[1] = v54;
    v65[1] = v54;
    v65[0] = v53 - (float)12.0;
    v72[2] = v55;
    v65[2] = v55;
    clientGame->renderWorld->DebugLine(
      this: clientGame->renderWorld,
      a2: (const idVec4 *)v79,
      a3: (const idVec3 *)v65,
      a4: (const idVec3 *)v72,
      a5: 0,
      a6: true);
    v76[2] = 0.0;
    v76[3] = 1.0;
    v74[2] = v55;
    v67[0] = v53;
    v67[1] = v54 + (float)12.0;
    v67[2] = v55;
    v74[0] = v53;
    v74[1] = v54 - (float)12.0;
    v76[0] = 1.0;
    v76[1] = 1.0;
    clientGame->renderWorld->DebugLine(
      this: clientGame->renderWorld,
      a2: (const idVec4 *)v76,
      a3: (const idVec3 *)v74,
      a4: (const idVec3 *)v67,
      a5: 0,
      a6: true);
    v78[0] = 1.0;
    v78[1] = 1.0;
    v78[2] = 0.0;
    v78[3] = 1.0;
    v59[0] = v53;
    v59[1] = v54;
    v59[2] = v55 + (float)12.0;
    v73[0] = v53;
    v73[1] = v54;
    v73[2] = v55 - (float)12.0;
    clientGame->renderWorld->DebugLine(
      this: clientGame->renderWorld,
      a2: (const idVec4 *)v78,
      a3: (const idVec3 *)v73,
      a4: (const idVec3 *)v59,
      a5: 0,
      a6: true);
    v56.x = v52.x;
    v56.z = v52.z;
    v56.y = v52.y + (float)lockAngle;
    v35 = idAngles::ToForward(this: &v58, result: &v56);
    v36 = (float)(v35->z * (float)valueFloat);
    v37 = this->origin.z;
    v38 = (float)((float)(v35->y * (float)valueFloat) + this->origin.y);
    v71[0] = (float)(v35->x * (float)valueFloat) + this->origin.x;
    v71[1] = v38;
    v71[2] = (float)v36 + (float)v37;
    clientGame->renderWorld->DebugLine(
      this: clientGame->renderWorld,
      a2: (const idVec4 *)&idColor::colorCyan,
      a3: &this->origin,
      a4: (const idVec3 *)v71,
      a5: 0,
      a6: false);
    v56.y = -(float)((float)((float)lockAngle * (float)2.0) - v56.y);
    v39 = idAngles::ToForward(this: &v58, result: &v56);
    v40 = (float)(v39->z * (float)valueFloat);
    v41 = this->origin.z;
    v42 = (float)((float)(v39->y * (float)valueFloat) + this->origin.y);
    v60[0] = (float)(v39->x * (float)valueFloat) + this->origin.x;
    v60[1] = v42;
    v60[2] = (float)v40 + (float)v41;
    clientGame->renderWorld->DebugLine(
      this: clientGame->renderWorld,
      a2: (const idVec4 *)&idColor::colorCyan,
      a3: &this->origin,
      a4: (const idVec3 *)v60,
      a5: 0,
      a6: false);
    v57.x = v52.x;
    v57.z = v52.z;
    v57.y = v52.y + (float)unlockYaw;
    v43 = idAngles::ToForward(this: &v58, result: &v57);
    v44 = (float)(v43->z * (float)valueFloat);
    v45 = this->origin.z;
    v46 = (float)((float)(v43->y * (float)valueFloat) + this->origin.y);
    v62[0] = (float)(v43->x * (float)valueFloat) + this->origin.x;
    v62[1] = v46;
    v62[2] = (float)v44 + (float)v45;
    clientGame->renderWorld->DebugLine(
      this: clientGame->renderWorld,
      a2: (const idVec4 *)&idColor::colorBlack,
      a3: &this->origin,
      a4: (const idVec3 *)v62,
      a5: 0,
      a6: false);
    v57.y = -(float)((float)((float)unlockYaw * (float)2.0) - v57.y);
    v47 = idAngles::ToForward(this: &v58, result: &v57);
    v48 = (float)((float)valueFloat * v47->x);
    v49 = this->origin.x;
    v50 = (float)((float)(v47->z * (float)valueFloat) + this->origin.z);
    v64[1] = (float)(v47->y * (float)valueFloat) + this->origin.y;
    v64[2] = v50;
    v64[0] = (float)v48 + (float)v49;
    clientGame->renderWorld->DebugLine(
      this: clientGame->renderWorld,
      a2: (const idVec4 *)&idColor::colorBlack,
      a3: &this->origin,
      a4: (const idVec3 *)v64,
      a5: 0,
      a6: false);
    v51 = this->trace.endpos.z;
    v80[0] = this->trace.endpos.x;
    v80[2] = v51;
    v80[3] = 50.0;
    v80[1] = this->trace.endpos.y;
    clientGame->renderWorld->DebugSphere(
      this: clientGame->renderWorld,
      a2: (const idVec4 *)&idColor::colorRed,
      a3: (const idSphere *)v80,
      a4: 12,
      a5: 0,
      a6: false);
  }
  idThirdPersonCrosshair::DrawVisual(this, view);
}


// ========================================================================
// ?CheckLosingTarget@idThirdPersonCrosshair@@AAA_NPAVidPresentable@@_N@Z
// EA  : 0x82E834B8
// RVA : 0x00E834B8
// PDB : w:\tech5\tungsten\game\player\thirdpersoncrosshair.cpp
// ========================================================================

int __fastcall idThirdPersonCrosshair::CheckLosingTarget(
        idThirdPersonCrosshair *this,
        idPresentable *tPresentable,
        bool zoomed)
{
  unsigned __int64 v3; // r24
  idPresentableVehicle *v7; // r3
  double x; // fp29
  double y; // fp30
  double z; // fp31
  unsigned int spawnId; // r11
  int v12; // r30
  idPresentable *PresentableByIndex; // r3
  double v14; // fp11
  double v15; // fp13
  double v16; // fp12
  double v17; // fp9
  double v18; // fp0
  double v19; // fp10
  double v20; // fp0
  double v23; // fp5
  double v24; // fp1
  double v25; // fp0
  const idDeclAmmo *declAmmo; // r11
  char v27; // r29
  int v28; // r30
  idAngles *v29; // r30
  idAngles *v30; // r3
  double v31; // fp9
  double v32; // fp7
  double v33; // fp29
  double v34; // fp31
  double v35; // fp30
  char v36; // r11
  double v37; // fp11
  double v38; // fp12
  const idDeclAmmo *v39; // r11
  double unlockZoomedYaw; // fp13
  double unlockZoomedPitch; // fp0
  double unlockYaw; // fp13
  double valueFloat; // fp0
  idClientGame *v45; // r28
  idClipQuery *p_deferredLosingTargetTrace; // r30
  unsigned __int64 index; // r11
  idPresentable *TracePresentable; // r3
  idPresentable *v49; // r3
  int entityNumber; // r29
  float v51; // r9
  float v52; // r8
  idPresentable *v53; // r3
  int v54; // r30
  float v55; // r9
  float v56; // r8
  idPresentable *v57; // r3
  idPresentable *v58; // r3
  int v59; // [sp+8h] [-198h]
  bool v60; // [sp+Fh] [-191h]
  const char *v61; // [sp+10h] [-190h]
  int v62; // [sp+14h] [-18Ch]
  int v63; // [sp+18h] [-188h]
  int v64; // [sp+1Ch] [-184h]
  int v65; // [sp+20h] [-180h]
  int v66; // [sp+24h] [-17Ch]
  int v67; // [sp+28h] [-178h]
  int v68; // [sp+2Ch] [-174h]
  int v69; // [sp+30h] [-170h]
  int v70; // [sp+34h] [-16Ch]
  int v71; // [sp+38h] [-168h]
  int v72; // [sp+3Ch] [-164h]
  int v73; // [sp+40h] [-160h]
  int v74; // [sp+44h] [-15Ch]
  int v75; // [sp+48h] [-158h]
  int v76; // [sp+4Ch] [-154h]
  int v77; // [sp+50h] [-150h]
  int v78; // [sp+58h] [-148h]
  int v79; // [sp+60h] [-140h]
  idVec3 v80; // [sp+70h] [-130h] BYREF
  idVec3 v81; // [sp+80h] [-120h] BYREF
  idVec3 v82; // [sp+90h] [-110h] BYREF
  idAngles v83; // [sp+A0h] [-100h] BYREF
  trace_t v84; // [sp+B0h] [-F0h] BYREF

  v7 = tPresentable->GetVehicleInterface(this: tPresentable);
  if ( v7 != nullptr && v7->isScramblingLocks )
    return 1;
  if ( (unsigned __int8)idThirdPersonCrosshair::GetTargetPosition(this, pos: &v80) != 0 )
  {
    z = v80.z;
    y = v80.y;
    x = v80.x;
  }
  else
  {
    x = tPresentable->origin.x;
    y = tPresentable->origin.y;
    z = tPresentable->origin.z;
  }
  spawnId = this->presentable.spawnId;
  LODWORD(v3) = 0;
  v12 = spawnId & 0x3FFF;
  if ( spawnId == 0
    || !idClientGame::IsPresentableIndexValid(this: clientGame, index: spawnId & 0x3FFF)
    || (PresentableByIndex = idClientGame::GetPresentableByIndex(this: clientGame, index: v12))->spawnId != this->presentable.spawnId )
  {
    PresentableByIndex = nullptr;
  }
  v14 = PresentableByIndex->origin.x;
  v15 = (float)((float)z - PresentableByIndex->origin.z);
  v16 = (float)((float)y - PresentableByIndex->origin.y);
  v83.roll = (float)z - PresentableByIndex->origin.z;
  v83.yaw = v16;
  v83.pitch = (float)x - (float)v14;
  v18 = ch_lockdist.valueFloat <= 0.0 ? this->declWeapon->unlockRange : (float)(ch_lockdist.valueFloat * (float)1.2);
  v19 = (float)((float)v18 * (float)v18);
  v20 = (float)((float)((float)v15 * (float)v15)
              + (float)((float)((float)((float)x - (float)v14) * (float)((float)x - (float)v14))
                      + (float)((float)v16 * (float)v16)));
  if ( v20 > v19 )
    return 1;
  _FP8 = (float)((float)((float)((float)v15 * (float)v15)
                       + (float)((float)((float)((float)x - (float)v14) * (float)((float)x - (float)v14))
                               + (float)((float)v16 * (float)v16)))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f6, f8, f0, f10 }
  v23 = __frsqrte(_FP6);
  v24 = (float)((float)-(float)((float)((float)((float)v23
                                              * (float)((float)((float)((float)v15 * (float)v15)
                                                              + (float)((float)((float)((float)x - (float)v14)
                                                                              * (float)((float)x - (float)v14))
                                                                      + (float)((float)v16 * (float)v16)))
                                                      * (float)0.5))
                                      * (float)v23)
                              - (float)1.5)
              * (float)v23);
  v25 = (float)((float)((float)-(float)((float)((float)((float)v23 * (float)((float)v20 * (float)0.5)) * (float)v23)
                                      - (float)1.5)
                      * (float)v23)
              * (float)((float)v20 * (float)0.5));
  v17 = (float)((float)x - (float)v14);
  v83.pitch = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)v25 * (float)v24)
                                                                            - (float)1.5)
                                                            * (float)v24)
                                                    * (float)((float)((float)((float)v15 * (float)v15)
                                                                    + (float)((float)((float)v17 * (float)v17)
                                                                            + (float)((float)v16 * (float)v16)))
                                                            * (float)0.5))
                                            * (float)((float)-(float)((float)((float)v25 * (float)v24) - (float)1.5)
                                                    * (float)v24))
                                    - (float)1.5)
                    * (float)((float)-(float)((float)((float)v25 * (float)v24) - (float)1.5) * (float)v24))
            * (float)v17;
  v83.yaw = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)v25 * (float)v24) - (float)1.5)
                                                          * (float)v24)
                                                  * (float)((float)((float)((float)v15 * (float)v15)
                                                                  + (float)((float)((float)((float)x - (float)v14)
                                                                                  * (float)((float)x - (float)v14))
                                                                          + (float)((float)v16 * (float)v16)))
                                                          * (float)0.5))
                                          * (float)((float)-(float)((float)((float)v25 * (float)v24) - (float)1.5)
                                                  * (float)v24))
                                  - (float)1.5)
                  * (float)((float)-(float)((float)((float)v25 * (float)v24) - (float)1.5) * (float)v24))
          * (float)v16;
  v83.roll = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)v25 * (float)v24)
                                                                           - (float)1.5)
                                                           * (float)v24)
                                                   * (float)((float)((float)((float)v15 * (float)v15)
                                                                   + (float)((float)((float)((float)x - (float)v14)
                                                                                   * (float)((float)x - (float)v14))
                                                                           + (float)((float)v16 * (float)v16)))
                                                           * (float)0.5))
                                           * (float)((float)-(float)((float)((float)v25 * (float)v24) - (float)1.5)
                                                   * (float)v24))
                                   - (float)1.5)
                   * (float)((float)-(float)((float)((float)v25 * (float)v24) - (float)1.5) * (float)v24))
           * (float)v15;
  if ( ch_locktodead.valueInteger == 0 )
  {
    declAmmo = this->declAmmo;
    if ( declAmmo != nullptr )
    {
      v27 = 0;
      v28 = 0;
      if ( declAmmo->lockableTypes.num > 0 )
      {
        do
        {
          HIDWORD(v3) = tPresentable->entityTypeFlags;
          if ( (idDeclAmmo::GetLockableTypeFlags(this: this->declAmmo, index: v28) & HIDWORD(v3)) != 0 )
            v27 = 1;
          ++v28;
        }
        while ( v28 < this->declAmmo->lockableTypes.num );
      }
      if ( v27 == 0 )
        return 1;
    }
    if ( !tPresentable->IsTargetLockable(this: tPresentable, a2: this->declAmmo) )
      return 1;
  }
  v29 = idVec3::ToAngles(this: &v82, result: (idAngles *)&this->baseForward);
  v30 = idVec3::ToAngles(this: &v80, result: &v83);
  v31 = (float)(v30->roll - v29->roll);
  v32 = (float)(v30->yaw - v29->yaw);
  v81.x = v30->pitch - v29->pitch;
  v81.z = v31;
  v81.y = v32;
  idAngles::Normalize180(this: (idAngles *)&v81);
  v33 = v81.z;
  v34 = v81.y;
  v35 = v81.x;
  if ( (this->flags & 0x80) != 0 )
  {
    this->goalAngles.pitch = v81.x;
    this->goalAngles.yaw = v34;
    this->goalAngles.roll = v33;
  }
  v80 = v81;
  idAngles::Clamp(this: (idAngles *)&v80, min: &this->minAngles, max: &this->maxAngles);
  if ( v80.x != v35 || v80.y != v34 || (v36 = 1, v80.z != v33) )
    v36 = 0;
  if ( v36 == 0 )
    return 1;
  v37 = (float)((float)v35 - this->absAngles.pitch);
  v38 = (float)((float)v34 - this->absAngles.yaw);
  if ( zoomed )
  {
    v39 = this->declAmmo;
    if ( v39 != nullptr )
      unlockZoomedYaw = v39->unlockZoomedYaw;
    else
      unlockZoomedYaw = ch_unlockzoomedyaw.valueFloat;
    if ( v39 != nullptr )
      unlockZoomedPitch = v39->unlockZoomedPitch;
    else
      unlockZoomedPitch = ch_unlockzoomedpitch.valueFloat;
    if ( __fabs(v38) >= unlockZoomedYaw || __fabs(v37) >= unlockZoomedPitch )
      return 1;
  }
  else
  {
    if ( ch_unlockyaw.valueFloat <= 0.0 )
      unlockYaw = this->declWeapon->unlockYaw;
    else
      unlockYaw = ch_unlockyaw.valueFloat;
    valueFloat = ch_unlockpitch.valueFloat;
    if ( ch_unlockpitch.valueFloat <= 0.0 )
      valueFloat = this->declWeapon->unlockPitch;
    if ( __fabs(v38) >= unlockYaw || __fabs(v37) >= valueFloat )
      return 1;
  }
  if ( crosshair_UseDeferredTrace.valueInteger != 0 )
  {
    if ( !idPresentablePtr<idPresentable>::IsValid(this: (idPresentablePtr<idPresentableActor> *)&this->target) )
      goto LABEL_52;
    v45 = clientGame;
    p_deferredLosingTargetTrace = &this->deferredLosingTargetTrace;
    if ( (unsigned __int8)idClip::QueryIsValid(this: &clientGame->clip, clipQuery: &this->deferredLosingTargetTrace) == 0
      || (index = p_deferredLosingTargetTrace->index,
          p_deferredLosingTargetTrace->index = v3,
          idCollisionModelManager::GetContentsResult(
            this: collisionModelManager,
            result: &this->trace,
            query: &v45->clip.collisionQueries[index & 0xFFF].query,
            peek: false),
          this->trace.c.entityNum == idPresentablePtr<idPresentableProjectile>::operator->(this: &this->target)->entityNumber)
      || this->trace.fraction >= 1.0 )
    {
      v49 = idPresentablePtr<idPresentableProjectile>::operator->(this: &this->target);
      entityNumber = 0x1FFF;
      v51 = v49->origin.y;
      v52 = v49->origin.z;
      v82.x = v49->origin.x;
      v82.y = v51;
      v82.z = v52;
      if ( idPresentablePtr<idPresentable>::IsValid(this: (idPresentablePtr<idPresentableActor> *)&this->presentable) )
        entityNumber = idPresentablePtr<idPresentableProjectile>::operator->(this: &this->presentable)->entityNumber;
      p_deferredLosingTargetTrace->index = *(unsigned __int64 *)&idClip::Translation(
                                                                   this: (idClip *)&v80,
                                                                   result: &clientGame->clip,
                                                                   a3: nullptr,
                                                                   start: &this->origin,
                                                                   end: &v82,
                                                                   clipModel: nullptr,
                                                                   startAxis: &mat3_identity,
                                                                   clipMask: 238593,
                                                                   passEntityNumber: v59,
                                                                   moveClipModel: v60,
                                                                   userName: v61,
                                                                   a12: v62,
                                                                   a13: v63,
                                                                   a14: v64,
                                                                   a15: v65,
                                                                   a16: v66,
                                                                   a17: v67,
                                                                   a18: v68,
                                                                   a19: v69,
                                                                   a20: v70,
                                                                   a21: v71,
                                                                   a22: v72,
                                                                   a23: v73,
                                                                   a24: v74,
                                                                   a25: v75,
                                                                   a26: v76,
                                                                   a27: v77,
                                                                   a28: entityNumber,
                                                                   a29: v78,
                                                                   a30: false,
                                                                   a31: v79,
                                                                   a32: (int)"w:\\tech5\\tungsten\\game\\player\\ThirdPersonCr"
                                                                        "osshair.cpp(599) : Translation")->world;
      goto LABEL_52;
    }
    TracePresentable = idClientGame::GetTracePresentable(this: clientGame, trace: &this->trace);
    if ( (unsigned __int8)idThirdPersonCrosshair::IsValidTarget(this, pres: TracePresentable) != 0 )
    {
LABEL_52:
      this->lostTargetTime = 0;
      return 0;
    }
    if ( this->timeToRetainLostTarget <= 0 )
      return 1;
    if ( this->lostTargetTime == 0 )
      this->lostTargetTime = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED)
                           + this->timeToRetainLostTarget;
    if ( this->lostTargetTime == 0 )
      return 1;
    if ( this->lostTargetTime > idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) )
      return 0;
    goto LABEL_59;
  }
  if ( !idPresentablePtr<idPresentable>::IsValid(this: (idPresentablePtr<idPresentableActor> *)&this->target) )
    goto LABEL_52;
  v53 = idPresentablePtr<idPresentableProjectile>::operator->(this: &this->target);
  v54 = 0x1FFF;
  v55 = v53->origin.y;
  v56 = v53->origin.z;
  v82.x = v53->origin.x;
  v82.y = v55;
  v82.z = v56;
  if ( idPresentablePtr<idPresentable>::IsValid(this: (idPresentablePtr<idPresentableActor> *)&this->presentable) )
    v54 = idPresentablePtr<idPresentableProjectile>::operator->(this: &this->presentable)->entityNumber;
  idClip::TracePoint(
    this: &clientGame->clip,
    result: &v84,
    start: &this->origin,
    end: &v82,
    clipMask: 238593,
    passEntityNumber: v54);
  v57 = idPresentablePtr<idPresentableProjectile>::operator->(this: &this->target);
  if ( v84.c.entityNum == v57->entityNumber )
    goto LABEL_52;
  if ( v84.fraction >= 1.0 )
    goto LABEL_52;
  v58 = idClientGame::GetTracePresentable(this: clientGame, trace: &v84);
  if ( (unsigned __int8)idThirdPersonCrosshair::IsValidTarget(this, pres: v58) != 0 )
    goto LABEL_52;
  if ( this->timeToRetainLostTarget <= 0 )
    return 1;
  if ( this->lostTargetTime == 0 )
    this->lostTargetTime = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED)
                         + this->timeToRetainLostTarget;
  if ( this->lostTargetTime == 0 )
    return 1;
  if ( this->lostTargetTime <= idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) )
  {
LABEL_59:
    this->lostTargetTime = 0;
    return 1;
  }
  return 0;
}


// ========================================================================
// ?IsLocallyControlled@idThirdPersonCrosshair@@QBA_NXZ
// EA  : 0x82E83C18
// RVA : 0x00E83C18
// PDB : w:\tech5\tungsten\game\player\thirdpersoncrosshair.cpp
// ========================================================================

BOOL __fastcall idThirdPersonCrosshair::IsLocallyControlled(idThirdPersonCrosshair *this)
{
  idPresentablePtr<idPresentable> *p_presentable; // r31
  idPresentable *v2; // r3
  idPresentable *v3; // r3
  idPresentable *v4; // r31
  idPresentablePlayer *Controller; // r3

  p_presentable = &this->presentable;
  if ( !idPresentablePtr<idPresentable>::IsValid(this: (idPresentablePtr<idPresentableActor> *)&this->presentable) )
    return false;
  v2 = idPresentablePtr<idPresentableProjectile>::operator->(this: p_presentable);
  v3 = (idPresentable *)v2->GetVehicleInterface(this: v2);
  v4 = v3;
  if ( v3 == nullptr || idPresentable::GetController(this: v3) == nullptr )
    return false;
  Controller = idPresentable::GetController(this: v4);
  return Controller->IsLocallyControlled(this: Controller);
}


// ========================================================================
// __unwind$493000_0
// EA  : 0x82E84FE8
// RVA : 0x00E84FE8
// PDB : w:\tech5\tungsten\game\player\thirdpersoncrosshair.cpp
// ========================================================================

void _unwind_493000_0()
{
  idRDScopedEvent *v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: v0 + 65312);
}


// ========================================================================
// __unwind$493001
// EA  : 0x82E85018
// RVA : 0x00E85018
// PDB : w:\tech5\tungsten\game\player\thirdpersoncrosshair.cpp
// ========================================================================

void _unwind_493001()
{
  idPLogScope *v0; // r12

  idPLogScope::~idPLogScope(this: v0 + 4019);
}


// ========================================================================
// ?TargetLock@idThirdPersonCrosshair@@AAAXPBVidDeclWeapon@@_N1@Z
// EA  : 0x82E85040
// RVA : 0x00E85040
// PDB : w:\tech5\tungsten\game\player\thirdpersoncrosshair.cpp
// ========================================================================

void __fastcall idThirdPersonCrosshair::TargetLock(
        idThirdPersonCrosshair *this,
        const idDeclWeapon *weapon,
        bool zoomed,
        bool handWeapon)
{
  idLobbyBase *v8; // r3
  bool v9; // r11
  idPresentable *v10; // r27
  idPresentable *updated; // r28
  int v12; // r9
  const idSoundShader *lockedSound; // r30
  idPresentable *v14; // r3
  idPresentable *v15; // r27
  int v16; // [sp+50h] [-50h] BYREF
  int v17; // [sp+54h] [-4Ch]

  v8 = session->GetActingGameStateLobbyBase(this: session);
  if ( v8->GetMatchParms(this: v8)->gameType == 2 && !idThirdPersonCrosshair::IsLocallyControlled(this)
    || this->declWeapon == nullptr )
  {
    return;
  }
  if ( weapon == nullptr || (v9 = true, !weapon->autoLock) )
    v9 = false;
  this->autoAcquire = v9;
  if ( ch_shoottolock.valueInteger == 0 )
    this->firing = true;
  if ( !v9 && ((this->flags & 2) == 0 || !this->firing) )
    idThirdPersonCrosshair::ClearTarget(this);
  if ( (this->autoAcquire
     && (v10 = idPresentablePtr<idPresentableProjectile>::operator->(this: &this->acquiringTarget)) != nullptr
     || (v10 = idPresentablePtr<idPresentableProjectile>::operator->(this: &this->target)) != nullptr)
    && (((double (__fastcall *)(idPresentable *))v10->GetTotalCurHealth)(a1: v10) <= 0.0
     || (unsigned __int8)idThirdPersonCrosshair::CheckLosingTarget(this, tPresentable: v10, zoomed) != 0) )
  {
    idThirdPersonCrosshair::ClearTarget(this);
  }
  updated = nullptr;
  v16 = -1;
  if ( !handWeapon || zoomed || !handWeapon )
    updated = idThirdPersonCrosshair::UpdateLockableTargets(this, id: &v16, zoomed);
  this->targetCanLock = false;
  if ( v10 == nullptr )
  {
    if ( this->firing || this->autoAcquire )
    {
      if ( updated != nullptr )
      {
        idThirdPersonCrosshair::ClearTarget(this);
        if ( this->autoAcquire )
        {
          this->acquiringTarget.spawnId = updated->spawnId;
        }
        else if ( (this->flags & 2) != 0 )
        {
          this->target.spawnId = updated->spawnId;
          this->targetLocked = true;
          this->targetId = -1;
        }
        this->targetAcquiringTime = idGameTimeManager::GetGameMs(
                                      this: &clientGame->gameTimeManager,
                                      type: GAMETIME_SCALED);
      }
    }
    else if ( (this->flags & 2) != 0 )
    {
      this->targetCanLock = updated != nullptr;
    }
  }
  if ( this->autoAcquire
    && idPresentablePtr<idPresentable>::IsValid(this: (idPresentablePtr<idPresentableActor> *)&this->acquiringTarget) )
  {
    v12 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED)
        - this->targetAcquiringTime;
    v17 = (int)(float)(weapon->lockTime * (float)1000.0);
    if ( v12 > v17 )
    {
      if ( weapon->lockedSound != nullptr && !this->playedLockSound && this->weaponCanFire )
      {
        this->playedLockSound = true;
        lockedSound = weapon->lockedSound;
        v14 = idPresentablePtr<idPresentableProjectile>::operator->(this: &this->presentable);
        idPresentable::StartSoundShader(
          this: v14,
          channel: SND_CHANNEL_WEAPON,
          shader: lockedSound,
          soundShaderFlags: (soundShaderFlags_t)0,
          peerMask: 0);
      }
      this->target.spawnId = this->acquiringTarget.spawnId;
      if ( (this->flags & 2) != 0 )
        this->targetLocked = true;
      return;
    }
  }
  else
  {
    v15 = idPresentablePtr<idPresentableProjectile>::operator->(this: &this->prevTarget);
    if ( idPresentablePtr<idPresentableProjectile>::operator->(this: &this->target) == v15
      || idPresentablePtr<idPresentableProjectile>::operator->(this: &this->target) == nullptr
      || weapon == nullptr )
    {
      return;
    }
  }
  if ( idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED)
     - this->lastAcquireSoundTime > weapon->acquireLoop )
    this->lastAcquireSoundTime = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
}


// ========================================================================
// ?Update@idThirdPersonCrosshair@@QAAXABVidAngles@@PBVidDeclWeapon@@PBVidDeclAmmo@@_N3@Z
// EA  : 0x82E853D8
// RVA : 0x00E853D8
// PDB : w:\tech5\tungsten\game\player\thirdpersoncrosshair.cpp
// ========================================================================

void __fastcall idThirdPersonCrosshair::Update(
        idThirdPersonCrosshair *this,
        const idAngles *_deltaAngles,
        const idDeclWeapon *weapon,
        const idDeclAmmo *declAmmo,
        bool zoomed,
        bool handWeapon)
{
  unsigned __int64 v11; // r6
  const char *v12; // r7
  idVec3 *v13; // r11
  double v14; // fp9
  double v15; // fp7
  idAngles *p_absAngles; // r29
  idAngles *p_goalAngles; // r21
  double valueFloat; // fp31
  double v19; // fp9
  double v20; // fp7
  idAngles *v21; // r29
  idAngles *v22; // r3
  double v23; // fp0
  double v24; // fp12
  double v25; // fp9
  double v26; // fp7
  idAngles *p_angles; // r29
  unsigned __int64 v28; // r20
  idPresentablePtr<idPresentable> *p_presentable; // r3
  double lockOnRange; // fp0
  const idDeclWeapon *declWeapon; // r11
  double v32; // fp9
  double v33; // fp8
  double y; // fp6
  idClip *p_clip; // r29
  double x; // fp5
  idClipQuery *p_deferredTrace2; // r24
  unsigned __int64 index; // r11
  idClipQuery *p_deferredTrace1; // r28
  idClip *v40; // r29
  unsigned __int64 v41; // r11
  idPresentable *TracePresentable; // r3
  idPresentable *v43; // r28
  double v44; // fp0
  const idDeclWeapon *v45; // r11
  double v46; // fp9
  double v47; // fp8
  double v48; // fp6
  double v49; // fp5
  idPresentable *v50; // r3
  float v51; // r9
  float z; // r27
  int entityNumber; // r8
  idPresentable *v54; // r27
  idPresentable *v55; // r3
  idRenderModel *model; // r11
  idLobbyBase *v57; // r3
  idPresentable *v58; // r3
  int v59; // r3
  idPresentable *v60; // r3
  idRenderModel *v61; // r10
  int v62; // [sp+8h] [-1F8h]
  bool v63; // [sp+Fh] [-1F1h]
  const char *v64; // [sp+10h] [-1F0h]
  int v65; // [sp+14h] [-1ECh]
  int v66; // [sp+18h] [-1E8h]
  int v67; // [sp+1Ch] [-1E4h]
  int v68; // [sp+20h] [-1E0h]
  int v69; // [sp+24h] [-1DCh]
  int v70; // [sp+28h] [-1D8h]
  int v71; // [sp+2Ch] [-1D4h]
  int v72; // [sp+30h] [-1D0h]
  int v73; // [sp+34h] [-1CCh]
  int v74; // [sp+38h] [-1C8h]
  int v75; // [sp+3Ch] [-1C4h]
  int v76; // [sp+40h] [-1C0h]
  int v77; // [sp+44h] [-1BCh]
  int v78; // [sp+48h] [-1B8h]
  int v79; // [sp+4Ch] [-1B4h]
  int v80; // [sp+50h] [-1B0h]
  int v81; // [sp+54h] [-1ACh]
  int v82; // [sp+58h] [-1A8h]
  int v83; // [sp+60h] [-1A0h]
  idVec3 v84; // [sp+70h] [-190h] BYREF
  idVec3 endpos; // [sp+80h] [-180h] BYREF
  idClientGameMsg v86; // [sp+90h] [-170h] BYREF
  int v87; // [sp+98h] [-168h]
  idVec3 v88; // [sp+A0h] [-160h] BYREF
  idVec3 v89; // [sp+B0h] [-150h] BYREF
  idVec3 v90; // [sp+C0h] [-140h] BYREF
  idPLogScope v91[2]; // [sp+D0h] [-130h] BYREF
  trace_t v92; // [sp+E0h] [-120h] BYREF

  RD_EventBegin(name: "idThirdPersonCrosshair::Update");
  LODWORD(v11) = "idThirdPersonCrosshair::Update";
  HIDWORD(v11) = 2;
  idPLogScope::idPLogScope(this: v91, pl: &pLog, gMask: v11, label: v12);
  if ( idPresentablePtr<idPresentable>::IsValid(this: (idPresentablePtr<idPresentableActor> *)&this->presentable) )
  {
    if ( (this->flags & 0x20) != 0 )
    {
      v13 = &v84;
      v14 = (float)(this->absAngles.roll + _deltaAngles->roll);
      v15 = (float)(this->absAngles.yaw + _deltaAngles->yaw);
      v84.x = _deltaAngles->pitch + this->absAngles.pitch;
      v84.z = v14;
      v84.y = v15;
    }
    else
    {
      v13 = (idVec3 *)&ang_zero;
    }
    this->absAngles.pitch = v13->x;
    p_absAngles = &this->absAngles;
    this->absAngles.yaw = v13->y;
    this->absAngles.roll = v13->z;
    if ( (this->flags & 0x40) != 0 )
      p_absAngles->pitch = 0.0;
    if ( ch_usemouse.valueInteger != 0 )
    {
      p_goalAngles = &this->goalAngles;
      this->goalAngles.pitch = p_absAngles->pitch;
      this->goalAngles.yaw = this->absAngles.yaw;
      this->goalAngles.roll = this->absAngles.roll;
      idAngles::Clamp(this: &this->goalAngles, min: &this->minAngles, max: &this->maxAngles);
      this->angles.pitch = this->goalAngles.pitch;
      this->angles.yaw = this->goalAngles.yaw;
      this->angles.roll = this->goalAngles.roll;
      idThirdPersonCrosshair::DetermineOriginForward(this);
    }
    else
    {
      valueFloat = 1.0;
      if ( idPresentablePtr<idPresentable>::IsValid(this: (idPresentablePtr<idPresentableActor> *)&this->target)
        && (this->flags & 0x80) != 0 )
      {
        if ( (unsigned __int8)idThirdPersonCrosshair::GetTargetPosition(this, pos: &v84) != 0 )
        {
          v19 = (float)(v84.z - this->origin.z);
          v20 = (float)(v84.y - this->origin.y);
          v88.x = v84.x - this->origin.x;
          v88.z = v19;
          v88.y = v20;
          idVec3::NormalizeFast(this: &v88);
          v21 = idVec3::ToAngles(this: &endpos, result: (idAngles *)&this->baseForward);
          v22 = idVec3::ToAngles(this: &v84, result: (idAngles *)&v88);
          v23 = (float)(v22->pitch - v21->pitch);
          v24 = (float)(v22->roll - v21->roll);
          this->goalAngles.yaw = v22->yaw - v21->yaw;
          this->goalAngles.roll = v24;
          this->goalAngles.pitch = v23;
          idAngles::Normalize180(this: &this->goalAngles);
          valueFloat = ch_targetspeed.valueFloat;
        }
      }
      else
      {
        if ( (this->flags & 0x10) != 0 )
        {
          v25 = (float)(_deltaAngles->pitch + this->angles.pitch);
          v26 = (float)(this->angles.roll + _deltaAngles->roll);
          this->goalAngles.yaw = this->angles.yaw + _deltaAngles->yaw;
          this->goalAngles.roll = v26;
          this->goalAngles.pitch = v25;
        }
        else
        {
          this->goalAngles.pitch = p_absAngles->pitch;
          this->goalAngles.yaw = this->absAngles.yaw;
          this->goalAngles.roll = this->absAngles.roll;
        }
        valueFloat = ch_movespeed.valueFloat;
      }
      p_goalAngles = &this->goalAngles;
      idAngles::Clamp(this: &this->goalAngles, min: &this->minAngles, max: &this->maxAngles);
      if ( (this->flags & 8) != 0 )
      {
        idThirdPersonCrosshair::AngleTowardsGoal(
          this: (idThirdPersonCrosshair *)LODWORD(this->goalAngles.pitch),
          goal: (idAngles *)LODWORD(this->goalAngles.yaw),
          moveScale: valueFloat);
        p_angles = &this->angles;
        idAngles::Clamp(this: &this->angles, min: &this->minAngles, max: &this->maxAngles);
      }
      else
      {
        p_angles = &this->angles;
        this->angles.pitch = p_goalAngles->pitch;
        this->angles.yaw = this->goalAngles.yaw;
        this->angles.roll = this->goalAngles.roll;
      }
      idAngles::Normalize180(this: &this->goalAngles);
      idAngles::Normalize180(this: p_angles);
      idThirdPersonCrosshair::DetermineOriginForward(this);
      idThirdPersonCrosshair::TargetLock(this, weapon, zoomed, handWeapon);
    }
    LODWORD(v28) = 0;
    if ( idPresentablePtr<idPresentable>::IsValid(this: (idPresentablePtr<idPresentableActor> *)&this->presentable) )
    {
      p_presentable = &this->presentable;
      if ( crosshair_UseDeferredTrace.valueInteger != 0 )
      {
        HIDWORD(v28) = idPresentablePtr<idPresentableProjectile>::operator->(this: p_presentable);
        lockOnRange = ch_lockdist.valueFloat;
        if ( ch_lockdist.valueFloat <= 0.0 )
        {
          declWeapon = this->declWeapon;
          if ( declWeapon != nullptr )
            lockOnRange = declWeapon->lockOnRange;
        }
        v32 = (float)(this->forward.y * (float)lockOnRange);
        v33 = (float)(this->forward.x * (float)lockOnRange);
        y = this->origin.y;
        p_clip = &clientGame->clip;
        x = this->origin.x;
        p_deferredTrace2 = &this->deferredTrace2;
        v90.z = this->origin.z + (float)(this->forward.z * (float)lockOnRange);
        v84.x = lockOnRange;
        v90.y = (float)y + (float)v32;
        v90.x = (float)x + (float)v33;
        if ( (unsigned __int8)idClip::QueryIsValid(this: &clientGame->clip, clipQuery: &this->deferredTrace2) != 0 )
        {
          index = p_deferredTrace2->index;
          p_deferredTrace2->index = v28;
          LODWORD(v84.x) = p_clip;
          idCollisionModelManager::GetContentsResult(
            this: collisionModelManager,
            result: &this->trace,
            query: &p_clip->collisionQueries[index & 0xFFF].query,
            peek: false);
        }
        p_deferredTrace1 = &this->deferredTrace1;
        v40 = &clientGame->clip;
        if ( (unsigned __int8)idClip::QueryIsValid(this: &clientGame->clip, clipQuery: &this->deferredTrace1) != 0 )
        {
          v41 = p_deferredTrace1->index;
          p_deferredTrace1->index = v28;
          LODWORD(v84.x) = v40;
          idCollisionModelManager::GetContentsResult(
            this: collisionModelManager,
            result: &v92,
            query: &v40->collisionQueries[v41 & 0xFFF].query,
            peek: false);
          TracePresentable = idClientGame::GetTracePresentable(this: clientGame, trace: &v92);
          if ( v92.fraction < 1.0 && TracePresentable == (idPresentable *)HIDWORD(v28) )
          {
            v81 = *(_DWORD *)(HIDWORD(v28) + 180);
            endpos = v92.endpos;
            p_deferredTrace2->index = *(unsigned __int64 *)&idClip::Translation(
                                                              this: (idClip *)&v84,
                                                              result: &clientGame->clip,
                                                              a3: nullptr,
                                                              start: &endpos,
                                                              end: &v90,
                                                              clipModel: nullptr,
                                                              startAxis: &mat3_identity,
                                                              clipMask: 238593,
                                                              passEntityNumber: v62,
                                                              moveClipModel: v63,
                                                              userName: v64,
                                                              a12: v65,
                                                              a13: v66,
                                                              a14: v67,
                                                              a15: v68,
                                                              a16: v69,
                                                              a17: v70,
                                                              a18: v71,
                                                              a19: v72,
                                                              a20: v73,
                                                              a21: v74,
                                                              a22: v75,
                                                              a23: v76,
                                                              a24: v77,
                                                              a25: v78,
                                                              a26: v79,
                                                              a27: v80,
                                                              a28: v81,
                                                              a29: v82,
                                                              a30: false,
                                                              a31: v83,
                                                              a32: (int)"w:\\tech5\\tungsten\\game\\player\\ThirdPersonCrossha"
                                                                   "ir.cpp(300) : Translation")->world;
          }
          else
          {
            trace_t::operator=(this: &this->trace, __that: &v92);
          }
        }
        p_deferredTrace1->index = *(unsigned __int64 *)&idClip::Translation(
                                                          this: (idClip *)&v84,
                                                          result: &clientGame->clip,
                                                          a3: nullptr,
                                                          start: &this->origin,
                                                          end: &v90,
                                                          clipModel: nullptr,
                                                          startAxis: &mat3_identity,
                                                          clipMask: 238593,
                                                          passEntityNumber: v62,
                                                          moveClipModel: v63,
                                                          userName: v64,
                                                          a12: v65,
                                                          a13: v66,
                                                          a14: v67,
                                                          a15: v68,
                                                          a16: v69,
                                                          a17: v70,
                                                          a18: v71,
                                                          a19: v72,
                                                          a20: v73,
                                                          a21: v74,
                                                          a22: v75,
                                                          a23: v76,
                                                          a24: v77,
                                                          a25: v78,
                                                          a26: v79,
                                                          a27: v80,
                                                          a28: *(_DWORD *)(HIDWORD(v28) + 180),
                                                          a29: v82,
                                                          a30: false,
                                                          a31: v83,
                                                          a32: (int)"w:\\tech5\\tungsten\\game\\player\\ThirdPersonCrosshair.c"
                                                               "pp(307) : Translation")->world;
      }
      else
      {
        v43 = idPresentablePtr<idPresentableProjectile>::operator->(this: p_presentable);
        v44 = ch_lockdist.valueFloat;
        if ( ch_lockdist.valueFloat <= 0.0 )
        {
          v45 = this->declWeapon;
          if ( v45 != nullptr )
            v44 = v45->lockOnRange;
        }
        v46 = (float)(this->forward.y * (float)v44);
        v47 = (float)(this->forward.x * (float)v44);
        v48 = this->origin.y;
        v49 = this->origin.x;
        v89.z = this->origin.z + (float)(this->forward.z * (float)v44);
        v84.x = v44;
        v89.y = (float)v48 + (float)v46;
        v89.x = (float)v49 + (float)v47;
        idClip::TracePoint(
          this: &clientGame->clip,
          result: &this->trace,
          start: &this->origin,
          end: &v89,
          clipMask: 238593,
          passEntityNumber: v43->entityNumber);
        v50 = idClientGame::GetTracePresentable(this: clientGame, trace: &this->trace);
        if ( this->trace.fraction < 1.0 && v50 == v43 )
        {
          v51 = this->trace.endpos.y;
          z = this->trace.endpos.z;
          entityNumber = v43->entityNumber;
          endpos.x = this->trace.endpos.x;
          endpos.y = v51;
          endpos.z = z;
          idClip::TracePoint(
            this: &clientGame->clip,
            result: &this->trace,
            start: &endpos,
            end: &v89,
            clipMask: 238593,
            passEntityNumber: entityNumber);
        }
      }
    }
    this->lastGoalAngles.pitch = p_goalAngles->pitch;
    this->lastGoalAngles.yaw = p_goalAngles->yaw;
    LODWORD(v84.x) = &this->lastGoalAngles;
    this->lastGoalAngles.roll = p_goalAngles->roll;
    v54 = idPresentablePtr<idPresentableProjectile>::operator->(this: &this->target);
    if ( v54 != idPresentablePtr<idPresentableProjectile>::operator->(this: &this->prevTarget) )
    {
      if ( !this->skipTargetHighlight
        && idPresentablePtr<idPresentable>::IsValid(this: (idPresentablePtr<idPresentableActor> *)&this->prevTarget) )
      {
        v55 = idPresentablePtr<idPresentableProjectile>::operator->(this: &this->prevTarget);
        model = v55->model;
        v55->highlightColor = HIGHLIGHT_COLOR_NONE;
        model->g.highlightColor = HIGHLIGHT_COLOR_NONE;
      }
      if ( common->IsClient(this: common) )
      {
        v57 = session->GetActingGameStateLobbyBase(this: session);
        if ( v57->GetMatchParms(this: v57)->gameType == 2 && idThirdPersonCrosshair::IsLocallyControlled(this) )
        {
          if ( idPresentablePtr<idPresentable>::IsValid(this: (idPresentablePtr<idPresentableActor> *)&this->presentable) )
          {
            v58 = idPresentablePtr<idPresentableProjectile>::operator->(this: &this->presentable);
            v59 = (int)v58->GetVehicleInterface(this: v58);
          }
          else
          {
            v59 = 0;
          }
          v87 = 0;
          v86.peerMask = -1;
          v86.__vftable = (idClientGameMsg_vtbl *)&idClientGameMsg_VehicleCrosshairChangeTarget::`vftable';
          if ( v59 != 0 )
            v87 = *(_DWORD *)(v59 + 1100);
          else
            v87 = 0;
          idClientGame::HandleReliableGameMsg(this: clientGame, gameMsg: &v86);
          v86.__vftable = (idClientGameMsg_vtbl *)&idClientGameMsg::`vftable';
        }
      }
      this->prevTarget.spawnId = this->target.spawnId;
      if ( !this->skipTargetHighlight
        && idPresentablePtr<idPresentable>::IsValid(this: (idPresentablePtr<idPresentableActor> *)&this->target) )
      {
        v60 = idPresentablePtr<idPresentableProjectile>::operator->(this: &this->target);
        v61 = v60->model;
        v60->highlightColor = HIGHLIGHT_COLOR_EXPLODE;
        v61->g.highlightColor = HIGHLIGHT_COLOR_EXPLODE;
      }
    }
  }
  idPLogScope::~idPLogScope(this: v91);
  RD_EventEnd();
}


// ========================================================================
// __unwind$494282
// EA  : 0x82E85C30
// RVA : 0x00E85C30
// PDB : w:\tech5\tungsten\game\player\thirdpersoncrosshair.cpp
// ========================================================================

void _unwind_494282()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 512 + 352));
}


// ========================================================================
// __unwind$494283
// EA  : 0x82E85C58
// RVA : 0x00E85C58
// PDB : w:\tech5\tungsten\game\player\thirdpersoncrosshair.cpp
// ========================================================================

void _unwind_494283()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 512 + 208));
}


// ========================================================================
// __unwind$494284
// EA  : 0x82E85C80
// RVA : 0x00E85C80
// PDB : w:\tech5\tungsten\game\player\thirdpersoncrosshair.cpp
// ========================================================================

void _unwind_494284()
{
  int v0; // r12

  idClientGameMsg_MeleeHit::~idClientGameMsg_MeleeHit(this: (idClientGameMsg_VehicleWeaponChange *)(v0 - 512 + 144));
}


// ========================================================================
// `dynamic initializer for 'ch_usemouse''
// EA  : 0x83390428
// RVA : 0x01390428
// PDB : w:\tech5\tungsten\game\player\thirdpersoncrosshair.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ch_usemouse__()
{
  idCVar::idCVar(
    this: &ch_usemouse,
    name: "ch_usemouse",
    value: "0",
    flags: 1,
    description: "Makes using crosshair easier with mouse",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ch_usemouse__);
}


// ========================================================================
// `dynamic initializer for 'ch_shoottolock''
// EA  : 0x83390480
// RVA : 0x01390480
// PDB : w:\tech5\tungsten\game\player\thirdpersoncrosshair.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ch_shoottolock__()
{
  idCVar::idCVar(
    this: &ch_shoottolock,
    name: "ch_shoottolock",
    value: "0",
    flags: 1,
    description: "Shooting activates target lock",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ch_shoottolock__);
}


// ========================================================================
// `dynamic initializer for 'ch_lockangle''
// EA  : 0x833904D8
// RVA : 0x013904D8
// PDB : w:\tech5\tungsten\game\player\thirdpersoncrosshair.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ch_lockangle__()
{
  idCVar::idCVar(
    this: &ch_lockangle,
    name: "ch_lockangle",
    value: "0",
    flags: 4,
    description: "Max angle for target locking",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ch_lockangle__);
}


// ========================================================================
// `dynamic initializer for 'ch_unlockyaw''
// EA  : 0x83390530
// RVA : 0x01390530
// PDB : w:\tech5\tungsten\game\player\thirdpersoncrosshair.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ch_unlockyaw__()
{
  idCVar::idCVar(
    this: &ch_unlockyaw,
    name: "ch_unlockyaw",
    value: "0",
    flags: 4,
    description: "Max yaw before unlocking from target",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ch_unlockyaw__);
}


// ========================================================================
// `dynamic initializer for 'ch_unlockpitch''
// EA  : 0x83390588
// RVA : 0x01390588
// PDB : w:\tech5\tungsten\game\player\thirdpersoncrosshair.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ch_unlockpitch__()
{
  idCVar::idCVar(
    this: &ch_unlockpitch,
    name: "ch_unlockpitch",
    value: "0",
    flags: 4,
    description: "Max pitch before unlocking from target",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ch_unlockpitch__);
}


// ========================================================================
// `dynamic initializer for 'ch_lockdist''
// EA  : 0x833905E0
// RVA : 0x013905E0
// PDB : w:\tech5\tungsten\game\player\thirdpersoncrosshair.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ch_lockdist__()
{
  idCVar::idCVar(
    this: &ch_lockdist,
    name: "ch_lockdist",
    value: "0",
    flags: 4,
    description: "Max distance for target locking (0 = use decl value .. 4500 default decl value)",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ch_lockdist__);
}


// ========================================================================
// `dynamic initializer for 'ch_unlockzoomedyaw''
// EA  : 0x83390638
// RVA : 0x01390638
// PDB : w:\tech5\tungsten\game\player\thirdpersoncrosshair.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ch_unlockzoomedyaw__()
{
  idCVar::idCVar(
    this: &ch_unlockzoomedyaw,
    name: "ch_unlockzoomedyaw",
    value: "16.5",
    flags: 4,
    description: "Max yaw before unlocking from target when zoomed",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ch_unlockzoomedyaw__);
}


// ========================================================================
// `dynamic initializer for 'ch_unlockzoomedpitch''
// EA  : 0x83390690
// RVA : 0x01390690
// PDB : w:\tech5\tungsten\game\player\thirdpersoncrosshair.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ch_unlockzoomedpitch__()
{
  idCVar::idCVar(
    this: &ch_unlockzoomedpitch,
    name: "ch_unlockzoomedpitch",
    value: "9",
    flags: 4,
    description: "Max pitch before unlocking from target when zoomed",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ch_unlockzoomedpitch__);
}


// ========================================================================
// `dynamic initializer for 'ch_locktodead''
// EA  : 0x833906E8
// RVA : 0x013906E8
// PDB : w:\tech5\tungsten\game\player\thirdpersoncrosshair.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ch_locktodead__()
{
  idCVar::idCVar(
    this: &ch_locktodead,
    name: "ch_locktodead",
    value: "0",
    flags: 1,
    description: "Lock to 'non lockable' objects (ie: dead things / empty vehicles / ammo pickups...)  [ for debugging ]",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ch_locktodead__);
}


// ========================================================================
// `dynamic initializer for 'ch_debug''
// EA  : 0x83390740
// RVA : 0x01390740
// PDB : w:\tech5\tungsten\game\player\thirdpersoncrosshair.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ch_debug__()
{
  idCVar::idCVar(
    this: &ch_debug,
    name: "ch_debug",
    value: "0",
    flags: 1,
    description: "Display debug info",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ch_debug__);
}


// ========================================================================
// `dynamic initializer for 'ch_targetspeed''
// EA  : 0x83390798
// RVA : 0x01390798
// PDB : w:\tech5\tungsten\game\player\thirdpersoncrosshair.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ch_targetspeed__()
{
  idCVar::idCVar(
    this: &ch_targetspeed,
    name: "ch_targetspeed",
    value: ".5",
    flags: 4,
    description: "Move speed when target is locked",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ch_targetspeed__);
}


// ========================================================================
// `dynamic initializer for 'ch_movespeed''
// EA  : 0x833907F0
// RVA : 0x013907F0
// PDB : w:\tech5\tungsten\game\player\thirdpersoncrosshair.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ch_movespeed__()
{
  idCVar::idCVar(
    this: &ch_movespeed,
    name: "ch_movespeed",
    value: "1.0",
    flags: 4,
    description: "Move speed when user is controlling",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ch_movespeed__);
}


// ========================================================================
// `dynamic initializer for 'ch_drawVisuals''
// EA  : 0x83390848
// RVA : 0x01390848
// PDB : w:\tech5\tungsten\game\player\thirdpersoncrosshair.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ch_drawVisuals__()
{
  idCVar::idCVar(
    this: &ch_drawVisuals,
    name: "ch_drawVisuals",
    value: "1",
    flags: 1,
    description: "Draw the 3rd person crosshair",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ch_drawVisuals__);
}


// ========================================================================
// `dynamic initializer for 'ch_drawCrosshairAlways''
// EA  : 0x833908A0
// RVA : 0x013908A0
// PDB : w:\tech5\tungsten\game\player\thirdpersoncrosshair.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ch_drawCrosshairAlways__()
{
  idCVar::idCVar(
    this: &ch_drawCrosshairAlways,
    name: "ch_drawCrosshairAlways",
    value: "0",
    flags: 1,
    description: "If false we only draw the crosshair when there is a valid target",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ch_drawCrosshairAlways__);
}


// ========================================================================
// `dynamic initializer for 'ch_ignoreFaction''
// EA  : 0x833908F8
// RVA : 0x013908F8
// PDB : w:\tech5\tungsten\game\player\thirdpersoncrosshair.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ch_ignoreFaction__()
{
  idCVar::idCVar(
    this: &ch_ignoreFaction,
    name: "ch_ignoreFaction",
    value: "0",
    flags: 1,
    description: "Ignores factions .. targets everyone.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ch_ignoreFaction__);
}


// ========================================================================
// `dynamic initializer for 'ch_animateTime''
// EA  : 0x83390950
// RVA : 0x01390950
// PDB : w:\tech5\tungsten\game\player\thirdpersoncrosshair.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ch_animateTime__()
{
  idCVar::idCVar(
    this: &ch_animateTime,
    name: "ch_animateTime",
    value: "900",
    flags: 2,
    description: "time for ch to animate from top to bottom",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ch_animateTime__);
}


// ========================================================================
// `dynamic initializer for 'ch_drawDebugVisuals''
// EA  : 0x833909A8
// RVA : 0x013909A8
// PDB : w:\tech5\tungsten\game\player\thirdpersoncrosshair.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ch_drawDebugVisuals__()
{
  idCVar::idCVar(
    this: &ch_drawDebugVisuals,
    name: "ch_drawDebugVisuals",
    value: "0",
    flags: 1,
    description: "Draw debug 3rd person crosshair",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ch_drawDebugVisuals__);
}


// ========================================================================
// `dynamic initializer for 'crosshair_UseDeferredTrace''
// EA  : 0x83390A00
// RVA : 0x01390A00
// PDB : w:\tech5\tungsten\game\player\thirdpersoncrosshair.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__crosshair_UseDeferredTrace__()
{
  idCVar::idCVar(
    this: &crosshair_UseDeferredTrace,
    name: "crosshair_UseDeferredTrace",
    value: "1",
    flags: 1,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__crosshair_UseDeferredTrace__);
}

