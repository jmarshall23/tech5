
// ========================================================================
// ?SetPlayerOccupant@idAnimator_VehicleCar@@QAAX_N@Z
// EA  : 0x826EDDD0
// RVA : 0x006EDDD0
// PDB : w:\tech5\engine\gamelib\animstack\animator_vehiclecar.cpp
// ========================================================================

void __fastcall idAnimator_VehicleCar::SetPlayerOccupant(idAnimator_VehicleCar *this, bool playerOccupant_)
{
  this->playerOccupant = playerOccupant_;
}


// ========================================================================
// ?SetTireWobble@idAnimator_VehicleCar@@QAAXHM@Z
// EA  : 0x826EDF08
// RVA : 0x006EDF08
// PDB : w:\tech5\engine\gamelib\animstack\animator_vehiclecar.cpp
// ========================================================================

void __fastcall idAnimator_VehicleCar::SetTireWobble(idAnimator_VehicleCar *this, int wheelIndex, double wobbleFrac_)
{
  if ( wheelIndex >= 0 && wheelIndex < this->animWheels.num )
    this->animWheels.list[wheelIndex].wobbleFrac = wobbleFrac_;
}


// ========================================================================
// ?InternalGetDialMeterJointIndex@idAnimator_VehicleCar@@ABA?AV?$idIndex@FW4invalidJointIndex_t@@@@H@Z
// EA  : 0x826EDF38
// RVA : 0x006EDF38
// PDB : w:\tech5\engine\gamelib\animstack\animator_vehiclecar.cpp
// ========================================================================

idAnimator_VehicleCar *__fastcall idAnimator_VehicleCar::InternalGetDialMeterJointIndex(
        idAnimator_VehicleCar *this,
        idIndex<short,enum invalidJointIndex_t> *result,
        int dialIndex)
{
  HIWORD(this->__vftable) = -1;
  if ( dialIndex >= 0 || dialIndex < *(_DWORD *)&result[40].value )
    HIWORD(this->__vftable) = *(_WORD *)(*(_DWORD *)&result[38].value + 48 * dialIndex);
  return this;
}


// ========================================================================
// ?SetSpeedometer@idAnimator_VehicleCar@@QAAXM@Z
// EA  : 0x826EE070
// RVA : 0x006EE070
// PDB : w:\tech5\engine\gamelib\animstack\animator_vehiclecar.cpp
// ========================================================================

void __fastcall idAnimator_VehicleCar::SetSpeedometer(idAnimator_VehicleCar *this, double value)
{
  int speedometer; // r11

  speedometer = this->speedometer;
  if ( speedometer >= 0 && speedometer < this->dialMeters.num )
    this->dialMeters.list[speedometer].value = value;
}


// ========================================================================
// ?SetTachometer@idAnimator_VehicleCar@@QAAXM@Z
// EA  : 0x826EE0A8
// RVA : 0x006EE0A8
// PDB : w:\tech5\engine\gamelib\animstack\animator_vehiclecar.cpp
// ========================================================================

void __fastcall idAnimator_VehicleCar::SetTachometer(idAnimator_VehicleCar *this, double value)
{
  int tachometer; // r11

  tachometer = this->tachometer;
  if ( tachometer >= 0 && tachometer < this->dialMeters.num )
    this->dialMeters.list[tachometer].value = value;
}


// ========================================================================
// ?Evaluate@idAnimator_VehicleCar@@QAAXXZ
// EA  : 0x826EE3A8
// RVA : 0x006EE3A8
// PDB : w:\tech5\engine\gamelib\animstack\animator_vehiclecar.cpp
// ========================================================================

void __fastcall idAnimator_VehicleCar::Evaluate(idAnimator_VehicleCar *this)
{
  idTreeAnimator *animator; // r21
  idRenderModel *renderModel; // r11
  idMat3 *p_deferredAxis; // r30
  long double v7; // fp2
  int num; // r11
  unsigned __int64 v9; // r20
  double v10; // fp21
  int v11; // r24
  int v12; // r25
  idAnimWheel *v13; // r31
  idRenderModel *v14; // r11
  bool v15; // r28
  idWheelDef *list; // r10
  idWheelDef *v17; // r26
  double v18; // fp27
  double v19; // fp31
  float *p_x; // r11
  double v21; // fp30
  double v22; // fp29
  double v23; // fp28
  double v24; // fp2
  double v25; // fp3
  double v26; // fp7
  double v27; // fp5
  double v28; // fp1
  double v29; // fp0
  double v30; // fp13
  double v31; // fp12
  double v32; // fp11
  double v33; // fp10
  double v34; // fp9
  double v35; // fp8
  unsigned __int64 *p_index; // r29
  idClip *clip; // r9
  int v38; // r11
  double fraction; // fp13
  double v40; // fp11
  BOOL isOnElevator; // r9
  double v42; // fp8
  double v43; // fp13
  double v44; // fp12
  double v45; // fp0
  double y; // fp27
  double v47; // fp31
  double v48; // fp12
  double z; // fp26
  double x; // fp25
  double v51; // fp30
  double v52; // fp29
  long double v53; // fp2
  double v57; // fp0
  long double v58; // fp2
  double v59; // fp12
  double v60; // fp11
  double v61; // fp13
  double v62; // fp0
  int v69; // r25
  int v71; // r23
  int v72; // r24
  int v78; // r21
  int v79; // r22
  idTreeAnimator *v199; // r3
  int v215; // r11
  int v216; // r29
  int v217; // r30
  idAnimDialMeter *v218; // r31
  double v219; // fp10
  double v220; // fp1
  double v221; // fp11
  double v222; // fp9
  float v223; // r10
  float v224; // r5
  idTreeAnimator *v225; // r3
  int v227; // [sp+8h] [-3C8h]
  bool v228; // [sp+Fh] [-3C1h]
  const char *v229; // [sp+10h] [-3C0h]
  idTreeAnimator *v230; // [sp+74h] [-35Ch]
  idVec3 v231; // [sp+80h] [-350h] BYREF
  idQuat v232; // [sp+90h] [-340h] BYREF
  idTypesafeNumber<float,enum RadiansUnique_t> v233[2]; // [sp+A0h] [-330h] BYREF
  idVec3 *v234; // [sp+A8h] [-328h]
  __vector4 *v235; // [sp+ACh] [-324h]
  idVec3 v236; // [sp+B0h] [-320h] BYREF
  __vector4 *v237; // [sp+C0h] [-310h]
  idVec3 v238; // [sp+C8h] [-308h] BYREF
  idVec3 v239; // [sp+D8h] [-2F8h] BYREF
  idVec3 v240; // [sp+E8h] [-2E8h] BYREF
  idMat3 v241; // [sp+100h] [-2D0h] BYREF
  idMat3 v242; // [sp+130h] [-2A0h] BYREF
  idVec3 v243; // [sp+158h] [-278h] BYREF
  idVec3 v244[2]; // [sp+168h] [-268h] BYREF
  idMat3x4 v245; // [sp+180h] [-250h] BYREF
  idMat3x4 v246; // [sp+1B0h] [-220h] BYREF
  idMat3x4 v247; // [sp+1E0h] [-1F0h] BYREF
  trace_t v248; // [sp+210h] [-1C0h] BYREF

  _R12 = -320;
  __asm { stvx128   v127, r1, r12 }
  animator = this->animator;
  _R27 = this;
  v230 = animator;
  if ( animator != nullptr && this->clip != nullptr )
  {
    renderModel = this->renderModel;
    if ( renderModel != nullptr
      && this->vehicleProps != nullptr
      && (this->animWheels.list->clipModel->contents & 0x1000) == 0 )
    {
      p_deferredAxis = &renderModel->deferredAxis;
      if ( !renderModel->useDeferredPosition )
        p_deferredAxis = &renderModel->g.axis;
      *(double *)&v7 = idGameTimeManager::GetRealMsPerFrame(
                         this: this->gametimeManager.gameTimeManager,
                         type: GAMETIME_SCALED);
      num = _R27->animWheels.num;
      v9 = 0;
      v10 = (float)((float)1.0 / (float)((float)*(double *)&v7 * (float)0.001));
      if ( num > 0 )
      {
        v11 = 0;
        v12 = 0;
        do
        {
          v13 = &_R27->animWheels.list[v12];
          v14 = _R27->renderModel;
          v15 = false;
          list = _R27->vehicleProps->wheels.list;
          v17 = &list[v11];
          v18 = (float)(list[v11].suspensionDown + list[v11].suspensionUp);
          v19 = (float)((float)(list[v11].suspensionDown + list[v11].suspensionUp) * (float)0.25);
          if ( v14->useDeferredPosition )
            p_x = &v14->deferredOrigin.x;
          else
            p_x = &v14->g.origin.x;
          v21 = (float)(*p_x
                      + (float)((float)(v13->localJointOrigin.x * p_deferredAxis->mat[0].x)
                              + (float)((float)(p_deferredAxis->mat[1].x * v13->localJointOrigin.y)
                                      + (float)(p_deferredAxis->mat[2].x * v13->localJointOrigin.z))));
          v22 = (float)(p_x[1]
                      + (float)((float)(p_deferredAxis->mat[0].y * v13->localJointOrigin.x)
                              + (float)((float)(p_deferredAxis->mat[2].y * v13->localJointOrigin.z)
                                      + (float)(p_deferredAxis->mat[1].y * v13->localJointOrigin.y))));
          v23 = (float)(p_x[2]
                      + (float)((float)(v13->localJointOrigin.y * p_deferredAxis->mat[1].z)
                              + (float)((float)(p_deferredAxis->mat[0].z * v13->localJointOrigin.x)
                                      + (float)(p_deferredAxis->mat[2].z * v13->localJointOrigin.z))));
          v24 = (float)(p_deferredAxis->mat[2].z
                      * (float)(list[v11].suspensionUp
                              + (float)((float)(list[v11].suspensionDown + list[v11].suspensionUp) * (float)0.25)));
          v25 = (float)(p_deferredAxis->mat[2].y
                      * (float)(list[v11].suspensionUp
                              + (float)((float)(list[v11].suspensionDown + list[v11].suspensionUp) * (float)0.25)));
          v238.x = (float)(p_deferredAxis->mat[2].x
                         * (float)(list[v11].suspensionUp
                                 + (float)((float)(list[v11].suspensionDown + list[v11].suspensionUp) * (float)0.25)))
                 + (float)(*p_x
                         + (float)((float)(v13->localJointOrigin.x * p_deferredAxis->mat[0].x)
                                 + (float)((float)(p_deferredAxis->mat[1].x * v13->localJointOrigin.y)
                                         + (float)(p_deferredAxis->mat[2].x * v13->localJointOrigin.z))));
          v238.z = (float)v24 + (float)v23;
          v238.y = (float)v25 + (float)v22;
          v26 = (float)(v17->suspensionDown * p_deferredAxis->mat[2].x);
          v27 = (float)((float)v22 - (float)(p_deferredAxis->mat[2].y * v17->suspensionDown));
          v240.z = (float)v23 - (float)(p_deferredAxis->mat[2].z * v17->suspensionDown);
          v240.y = v27;
          v240.x = (float)v21 - (float)v26;
          v28 = v13->wheelSteeringAxis.mat[9];
          v29 = v13->wheelSteeringAxis.mat[5];
          v30 = v13->wheelSteeringAxis.mat[1];
          v31 = v13->wheelSteeringAxis.mat[8];
          v32 = v13->wheelSteeringAxis.mat[4];
          v33 = v13->wheelSteeringAxis.mat[0];
          v34 = v13->wheelSteeringAxis.mat[10];
          v35 = v13->wheelSteeringAxis.mat[6];
          v241.mat[2].x = v13->wheelSteeringAxis.mat[2];
          v241.mat[2].y = v35;
          v241.mat[2].z = v34;
          v241.mat[1].z = v28;
          v241.mat[1].y = v29;
          v241.mat[1].x = v30;
          v241.mat[0].z = v31;
          v241.mat[0].x = v33;
          v241.mat[0].y = v32;
          idMat3::operator*(this: &v242, result: p_deferredAxis, a: &v241);
          p_index = &v13->collisionQuery.index;
          if ( (unsigned __int8)idClip::QueryIsValid(this: _R27->clip, clipQuery: &v13->collisionQuery) != 0 )
          {
            v13->prevTraceFraction = v13->traceFraction;
            clip = _R27->clip;
            v38 = v13->collisionQuery.index & 0xFFF;
            *p_index = v9;
            idCollisionModelManager::GetContentsResult(
              this: collisionModelManager,
              result: &v248,
              query: &clip->collisionQueries[v38].query,
              peek: false);
            fraction = v248.fraction;
            v13->traceFraction = v248.fraction;
            v13->traceSurfaceType = v248.c.surfaceType;
            v13->traceSurfaceColor[0] = v248.c.surfaceColor[0];
            v13->traceSurfaceColor[1] = v248.c.surfaceColor[1];
            v13->traceSurfaceColor[2] = v248.c.surfaceColor[2];
            v15 = fraction < 1.0;
            if ( fraction < 1.0
              && __fabs((float)((float)(v242.mat[2].x * v248.c.normal.x)
                              + (float)((float)(v242.mat[2].y * v248.c.normal.y)
                                      + (float)(v242.mat[2].z * v248.c.normal.z)))) < (float)0.2 )
            {
              v13->traceFraction = (float)((float)(v17->suspensionUp - v13->wheelHeight) + (float)v19)
                                 / (float)((float)v19 + (float)v18);
            }
            v13->wheelHeight = v17->suspensionUp
                             - (float)((float)(v13->traceFraction * (float)((float)v19 + (float)v18)) - (float)v19);
          }
          *p_index = idClip::Translation(
                       this: (idClip *)v233,
                       result: (idClipQuery *)_R27->clip,
                       result: nullptr,
                       start: &v238,
                       end: &v240,
                       clipModel: v13->clipModel,
                       startAxis: p_deferredAxis,
                       clipMask: _R27->clipMask,
                       passEntityNumber: v227,
                       moveClipModel: v228,
                       userName: v229)->index;
          if ( v15 )
            v40 = 1.0;
          else
            v40 = 0.0;
          if ( v15 && v17->steering < 1.0 && -v13->wheelHeight > (float)(v17->suspensionDown * (float)0.5) )
            v40 = (float)((float)-(float)((float)((float)((float)-1.0 / v17->suspensionDown) * v13->wheelHeight)
                                        - (float)1.0)
                        * (float)2.0);
          isOnElevator = _R27->isOnElevator;
          v42 = (float)((float)v23 - v13->lastWorldOrigin.z);
          v43 = (float)((float)((float)v21 - v13->lastWorldOrigin.x) * (float)v10);
          v44 = (float)((float)((float)v22 - v13->lastWorldOrigin.y) * (float)v10);
          v236.x = (float)((float)v21 - v13->lastWorldOrigin.x) * (float)v10;
          v236.y = v44;
          v45 = (float)((float)v42 * (float)v10);
          v236.z = (float)v42 * (float)v10;
          if ( isOnElevator )
          {
            v236.z = 0.0;
            v45 = 0.0;
          }
          y = v242.mat[0].y;
          v47 = 0.0;
          v48 = (float)(v242.mat[0].y * (float)v44);
          z = v242.mat[0].z;
          x = v242.mat[0].x;
          v13->lastWorldOrigin.x = v21;
          v51 = 0.0;
          v13->lastWorldOrigin.y = v22;
          v13->lastWorldOrigin.z = v23;
          v52 = (float)((float)((float)x * (float)v43) + (float)((float)((float)z * (float)v45) + (float)v48));
          if ( v15 || _R27->accelerating || _R27->isReversing || _R27->handBraking )
          {
            if ( _R27->handBraking && v17->hasHandbrake )
              v47 = 0.0;
            else
              v47 = (float)((float)((float)((float)x * (float)v43) + (float)((float)((float)z * (float)v45) + (float)v48))
                          * (float)v40);
            if ( _R27->accelerating )
            {
              v47 = (float)((float)((float)((float)1.0 - (float)v40) * (float)1200.0) + (float)v47);
            }
            else if ( _R27->isReversing )
            {
              v47 = (float)-(float)((float)((float)((float)1.0 - (float)v40) * (float)600.0) - (float)v47);
            }
            v51 = (float)1000.0;
          }
          v13->wheelVelocity = v13->wheelVelocity * (float)0.99000001;
          *(double *)&v53 = idGameTimeManager::GetRealMsPerFrame(
                              this: _R27->gametimeManager.gameTimeManager,
                              type: GAMETIME_SCALED);
          if ( v47 <= v13->wheelVelocity )
          {
            _FP13 = (float)((float)v47
                          - (float)(v13->wheelVelocity
                                  - (float)((float)((float)*(double *)&v53 * (float)v51) * (float)0.001)));
            __asm { fsel      f12, f13, f31, f0 }
          }
          else
          {
            _FP13 = (float)((float)v47
                          - (float)(v13->wheelVelocity
                                  + (float)((float)((float)*(double *)&v53 * (float)v51) * (float)0.001)));
            __asm { fsel      f12, f13, f0, f31 }
          }
          v13->wheelVelocity = _FP12;
          if ( _R27->updateWheelAngle )
          {
            v57 = (float)((float)((float)_FP12 / (float)(v17->wheelRadius * (float)v10)) + v13->wheelAngle);
            v13->wheelAngle = (float)((float)_FP12 / (float)(v17->wheelRadius * (float)v10)) + v13->wheelAngle;
            if ( v57 >= idMath::TWO_PI || v57 < 0.0 )
            {
              *(double *)&v53 = (float)((float)((float)1.0 / idMath::TWO_PI) * (float)v57);
              v58 = floor(x: v53);
              v13->wheelAngle = -(float)((float)((float)*(double *)&v58 * idMath::TWO_PI) - v13->wheelAngle);
            }
          }
          v231 = v236;
          *(double *)&v7 = idVec3::NormalizeFast(this: &v231);
          v59 = v231.y;
          v60 = v231.z;
          v61 = v231.x;
          if ( (float)((float)(v231.x * p_deferredAxis->mat[0].x)
                     + (float)((float)(v231.z * p_deferredAxis->mat[0].z) + (float)(p_deferredAxis->mat[0].y * v231.y))) < 0.0 )
          {
            v61 = -v61;
            v59 = -v59;
            v60 = -v60;
          }
          v62 = 0.0;
          if ( __fabs(v52) >= 1.0 )
          {
            *(double *)&v7 = idMath::ACos16(a: (float)((float)((float)x * (float)v61)
                                                     + (float)((float)((float)y * (float)v59)
                                                             + (float)((float)z * (float)v60))));
            v62 = (float)((float)*(double *)&v7 * (float)((float)2.0 / 3.1415927));
            if ( v62 > 1.0 )
              v62 = 1.0;
          }
          ++HIDWORD(v9);
          ++v12;
          ++v11;
          v13->wheelSlip = __fsqrts((float)((float)v62 * (float)v62));
          num = _R27->animWheels.num;
        }
        while ( SHIDWORD(v9) < num );
      }
      _R16 = &vector_float_halfPI;
      _R15 = &vector_float_PI;
      _R14 = &vector_float_twoPI;
      v237 = &vector_float_halfPI;
      _R28 = &vector_float_oneOverTwoPI;
      _R22 = COERCE_FLOAT(&vector_float_degrees_to_radians);
      _R29 = 16;
      v235 = &vector_float_oneOverTwoPI;
      v69 = 0;
      LODWORD(v233[0].value) = &vector_float_degrees_to_radians;
      _R31 = &vector_float_cosine_c4;
      if ( num > 0 )
      {
        __asm { vspltisw128 v127, 0 }
        v71 = 0;
        v72 = 0;
        _R19 = &`GetWheelRotation'::`2'::vectori_perm_wheel_steering;
        _R18 = &`GetWheelRotation'::`2'::vectori_perm_wheel_spin;
        _R17 = &`GetWheelRotation'::`2'::vectori_perm_wheel_wobble;
        do
        {
          _R30 = &_R27->animWheels.list[v72];
          _R26 = &_R27->vehicleProps->wheels.list[v71];
          if ( _R30->suspensionLever.num > 0 )
          {
            v78 = 0;
            v79 = 0;
            do
            {
              _R28 = (unsigned __int16 *)&_R30->suspensionLever.list[v79];
              if ( *_R28 != 0xFFFF )
              {
                if ( _R26->suspensionLever.list[v78].direction == DIR_ALIGN_TO )
                {
                  idTreeAnimator::GetModelSpaceJointTransform(
                    this: v230,
                    pose: DRIVER_MODEL,
                    jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)_R28[1],
                    origin: &v243,
                    axis: &v242);
                  idTreeAnimator::GetModelSpaceJointTransform(
                    this: v230,
                    pose: DRIVER_MODEL,
                    jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)*_R28,
                    origin: v244,
                    axis: &v241);
                  _R8 = v244;
                  _R7 = v244;
                  _R6 = &v243;
                  _R5 = &v243;
                  _R4 = 80;
                  __asm { lvrx128   v60, r29, r8 }
                  _R11 = _R28 + 4;
                  __asm { lvlx128   v59, r0, r7 }
                  _R3 = 96;
                  __asm
                  {
                    lvrx128   v58, r29, r6
                    vor128    v57, v91, v60
                    lvlx128   v56, r0, r5
                  }
                  _R16 = -176;
                  __asm
                  {
                    vor128    v55, v88, v58
                    lvx128    v63, r31, r4
                    lvrx128   v54, r29, r11
                  }
                  _R4 = 112;
                  __asm
                  {
                    vand128   v52, v89, v63
                    lvlx128   v53, r0, r11
                    vor128    v50, v85, v54
                    lvx128    v62, r31, r3
                    vand128   v48, v87, v63
                    lvx128    v13, r31, r16
                  }
                  _R15 = 128;
                  __asm
                  {
                    vmr       v7, v13
                    lvx128    v5, r31, r4
                  }
                  _R10 = _R28 + 10;
                  __asm { vand128   v44, v82, v63 }
                  _R9 = _R28 + 16;
                  __asm { vsubfp128 v6, v80, v52 }
                  _R3 = -192;
                  _R4 = 48;
                  __asm { lvx128    v61, r31, r15 }
                  _R11 = &v231;
                  __asm
                  {
                    vor128    v10, v76, v44
                    lvrx128   v51, r29, r10
                    lvlx128   v49, r0, r10
                  }
                  _R16 = 64;
                  __asm
                  {
                    vor128    v46, v81, v51
                    lvrx128   v47, r29, r9
                    lvlx128   v45, r0, r9
                    vor128    v0, v77, v47
                    lvx128    v60, r31, r4
                    vand128   v12, v78, v63
                    lvx128    v63, r31, r3
                  }
                  _R3 = 272;
                  __asm
                  {
                    vpermwi128 v43, v0, 0xFC
                    vmsum4fp128 v11, v6, v44
                    vpermwi128 v30, v0, 0x85
                    vpermwi128 v4, v12, 0x60 # '`'
                    vpermwi128 v8, v12, 0x85
                    vnmsubfp  v6, v11, v6, v10
                    vmsum4fp128 v11, v6, v6
                    vcmpgtfp128 v10, v11, v62
                    vsel      v10, v13, v11, v10
                    vrsqrtefp128 v42, v10
                    vmulfp128 v11, v74, v42
                    vmulfp128 v41, v74, v61
                    vmaddfp   v11, v11, v5, v10
                    vmulfp128 v40, v73, v11
                    vmulfp128 v11, v6, v40
                    vmaddfp   v13, v12, v13, v11
                    vpermwi128 v39, v11, 0x61 # 'a'
                    vpermwi128 v6, v11, 0x84
                    vpermwi128 v12, v0, 0x62 # 'b'
                    vspltw128 v38, v13, 2
                    vxor128   v13, v71, v60
                    vsldoi128 v11, v95, v38, 4
                    vmaddfp   v11, v4, v11, v6
                  }
                  _R9 = 144;
                  __asm { lvx128    v59, r31, r16 }
                  _R8 = 160;
                  _R10 = &v231;
                  __asm
                  {
                    lvx128    v37, r31, r3
                    stvx128   v37, r0, r11
                  }
                  v234 = &v236;
                  _R7 = 224;
                  __asm { lvx128    v10, r31, r9 }
                  _R6 = 240;
                  __asm { lvx128    v9, r31, r8 }
                  _R5 = 176;
                  __asm { lvx128    v6, r0, r10 }
                  _R4 = 192;
                  __asm { stvx128   v6, r0, r11 }
                  _R3 = 208;
                  __asm
                  {
                    vnmsubfp  v11, v8, v11, v13
                    lvx128    v6, r31, r7
                    lvx128    v4, r31, r6
                  }
                  _R11 = 256;
                  __asm { lvx128    v3, r31, r5 }
                  _R10 = 288;
                  __asm { lvx128    v2, r31, r4 }
                  _R9 = &v245;
                  __asm { lvx128    v31, r31, r3 }
                  _R8 = &v245.mat[4];
                  _R7 = &v245.mat[8];
                  _R14 = &vector_float_twoPI;
                  __asm { lvx128    v1, r31, r11 }
                  _R11 = &v236;
                  _R15 = &vector_float_PI;
                  _R16 = v237;
                  __asm
                  {
                    vmr128    v36, v11
                    vmsum4fp128 v13, v68, v36
                    vcmpgtfp128 v11, v13, v62
                    vsel      v11, v7, v13, v11
                    vrsqrtefp128 v35, v11
                    vmulfp128 v13, v67, v35
                    vmulfp128 v34, v67, v61
                    vmaddfp   v13, v13, v5, v11
                    vmulfp128 v33, v66, v13
                    vmulfp128 v32, v68, v33
                    vpermwi128 v62, v32, 0x18
                    vpermwi128 v11, v32, 0x61 # 'a'
                    vpermwi128 v7, v32, 0xFF
                    vpermwi128 v13, v32, 0x86
                    vmulfp128 v8, v94, v43
                    vmaddfp   v11, v11, v8, v30
                    vxor128   v11, v11, v60
                    vmaddfp   v0, v7, v11, v0
                    vnmsubfp  v0, v13, v0, v12
                    vaddfp128 v61, v0, v0
                    vpermwi128 v60, v0, 0x41 # 'A'
                    vmr       v12, v0
                    vpermwi128 v8, v0, 0xBF
                    vxor128   v0, v92, v59
                    vpermwi128 v13, v61, 0x5A # 'Z'
                    vor128    v11, v93, v61
                    vpermwi128 v7, v61, 0xA4
                    vmaddfp   v0, v0, v10, v13
                    vnmsubfp  v10, v12, v10, v11
                    vmaddfp   v13, v8, v9, v7
                    lvx128    v7, r0, r11
                    vperm     v12, v0, v10, v6
                    vmaddfp   v11, v13, v0, v3
                    vperm     v10, v0, v13, v4
                    vmaddfp   v0, v13, v12, v2
                    vmaddfp   v13, v10, v12, v31
                    vperm128  v59, v11, v63, v1
                    vperm128  v58, v0, v63, v7
                    lvx128    v0, r31, r10
                    vperm128  v57, v13, v63, v0
                    stvx128   v59, r0, r9
                    stvx128   v58, r0, r8
                    stvx128   v57, r0, r7
                  }
                }
                else
                {
                  _R11 = 4;
                  _R10 = 364;
                  _R8 = -176;
                  _R9 = -192;
                  _R7 = 16;
                  __asm { lvlx128   v56, r28, r11 }
                  _R6 = 96;
                  __asm { lvlx128   v55, r30, r10 }
                  _R5 = 128;
                  __asm
                  {
                    vspltw128 v54, v56, 0
                    lvx128    v0, r31, r8
                    vspltw128 v53, v55, 0
                    lvx128    v63, r31, r9
                    lvx128    v59, r31, r7
                  }
                  _R4 = 112;
                  __asm { lvx128    v62, r31, r6 }
                  _R11 = _R28 + 4;
                  __asm { lvx128    v61, r31, r5 }
                  _R3 = 80;
                  __asm { vmulfp128 v12, v85, v54 }
                  _R10 = _R28 + 16;
                  _R9 = 48;
                  __asm { lvx128    v8, r31, r4 }
                  _R8 = 64;
                  __asm { lvlx128   v52, r0, r11 }
                  _R7 = 144;
                  __asm { lvrx128   v51, r29, r11 }
                  _R6 = 160;
                  __asm
                  {
                    vor128    v50, v84, v51
                    lvx128    v60, r31, r3
                    lvlx128   v49, r0, r10
                  }
                  _R5 = 224;
                  __asm
                  {
                    lvrx128   v48, r29, r10
                    vor128    v13, v81, v48
                    vand128   v47, v82, v60
                    lvx128    v60, r31, r9
                    vnmsubfp  v7, v12, v0, v12
                    vsldoi128 v46, v12, v63, 4
                    vpermwi128 v45, v13, 0xFC
                    vpermwi128 v6, v13, 0x85
                    vpermwi128 v9, v13, 0x62 # 'b'
                    vmulfp128 v44, v78, v47
                    vand128   v12, v7, v59
                    vcmpgefp128 v7, v12, v62
                    vsel      v7, v0, v12, v7
                    vrsqrtefp128 v43, v7
                    vmulfp128 v11, v75, v43
                    vmulfp128 v42, v75, v61
                    vmaddfp   v11, v11, v8, v12
                    vmulfp128 v11, v74, v11
                    vmaddfp   v12, v11, v0, v12
                    vsldoi128 v41, v95, v12, 4
                    vor128    v40, v76, v41
                    vmsum4fp128 v12, v72, v40
                    vcmpgtfp128 v11, v12, v62
                    lvx128    v62, r31, r8
                    vsel      v11, v0, v12, v11
                    vrsqrtefp128 v39, v11
                    vmulfp128 v0, v71, v39
                    vmulfp128 v38, v71, v61
                    vmaddfp   v0, v0, v8, v11
                    vmulfp128 v37, v70, v0
                    vmulfp128 v36, v72, v37
                    vpermwi128 v35, v36, 0x18
                    vpermwi128 v12, v36, 0x61 # 'a'
                    vpermwi128 v10, v36, 0xFF
                    vpermwi128 v0, v36, 0x86
                    vmulfp128 v11, v67, v45
                    vmaddfp   v12, v12, v11, v6
                    lvx128    v11, r31, r7
                    vxor128   v12, v12, v60
                    vmaddfp   v13, v10, v12, v13
                    lvx128    v10, r31, r6
                    vnmsubfp  v13, v0, v13, v9
                    vaddfp    v0, v13, v13
                    vpermwi128 v34, v13, 0x41 # 'A'
                    vmr       v12, v13
                    vpermwi128 v31, v13, 0xBF
                    vxor128   v13, v66, v62
                    vpermwi128 v3, v0, 0x5A # 'Z'
                    vpermwi128 v1, v0, 0xA4
                    vmaddfp   v13, v13, v11, v3
                  }
                  _R4 = 240;
                  __asm { vnmsubfp  v11, v12, v11, v0 }
                  _R3 = 176;
                  __asm
                  {
                    vmaddfp   v0, v31, v10, v1
                    lvx128    v7, r31, r5
                  }
                  _R11 = 192;
                  _R10 = 208;
                  __asm { lvx128    v6, r31, r4 }
                  _R9 = 256;
                  __asm { lvx128    v9, r31, r3 }
                  _R8 = 272;
                  _R7 = 288;
                  __asm { lvx128    v8, r31, r11 }
                  _R6 = &v245;
                  __asm { lvx128    v5, r31, r10 }
                  _R5 = &v245.mat[4];
                  __asm { lvx128    v4, r31, r9 }
                  _R4 = &v245.mat[8];
                  __asm
                  {
                    lvx128    v3, r31, r8
                    lvx128    v2, r31, r7
                    vperm     v12, v13, v11, v7
                    vperm     v11, v13, v0, v6
                    vmaddfp   v10, v0, v13, v9
                    vmaddfp   v13, v0, v12, v8
                    vmaddfp   v0, v11, v12, v5
                    vperm128  v33, v10, v63, v4
                    vperm128  v32, v13, v63, v3
                    vperm128  v63, v0, v63, v2
                    stvx128   v33, r0, r6
                    stvx128   v32, r0, r5
                    stvx128   v63, r0, r4
                  }
                }
                idTreeAnimator::SetJointMat3x4(
                  this: v230,
                  pose: (animationPose_t)0,
                  jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)*_R28,
                  type: JOINTMOD_MODEL_OVERRIDE,
                  mat: &v245,
                  setPos: false);
              }
              LODWORD(v9) = v9 + 1;
              ++v79;
              ++v78;
            }
            while ( (int)v9 < _R30->suspensionLever.num );
            animator = v230;
            LODWORD(v9) = 0;
            _R28 = v235;
            _R22 = v233[0].value;
          }
          _R10 = 268;
          __asm { lvx128    v61, r0, r22 }
          _R11 = &_R27->steerAngle;
          __asm { lvx128    v58, r0, r28 }
          _R9 = 56;
          __asm { lvx128    v57, r0, r14 }
          _R8 = 52;
          __asm { lvx128    v60, r0, r15 }
          _R7 = 32;
          __asm
          {
            lvx128    v56, r0, r16
            lvlx128   v62, r30, r10
          }
          _R6 = 356;
          __asm { lvlx128   v59, r0, r11 }
          _R5 = -160;
          __asm
          {
            vspltw128 v55, v62, 0
            lvlx128   v54, r26, r9
            vspltw128 v53, v59, 0
            lvlx128   v52, r26, r8
            vspltw128 v51, v54, 0
            lvx128    v62, r31, r7
            vspltw128 v50, v52, 0
            lvlx128   v49, r30, r6
            vmulfp128 v48, v87, v55
            lvx128    v59, r31, r5
            vxor128   v47, v85, v62
            vspltw128 v46, v49, 0
          }
          _R4 = -176;
          _R3 = -128;
          _R9 = -144;
          __asm { vmulfp128 v45, v79, v50 }
          _R11 = &_R30->localJointQuat;
          _R8 = -112;
          __asm { lvx128    v13, r31, r4 }
          _R10 = &_R30->localJointOrigin;
          __asm { lvx128    v9, r31, r3 }
          _R7 = -48;
          __asm { lvx128    v8, r31, r9 }
          _R6 = -64;
          __asm { lvlx128   v44, r0, r11 }
          _R5 = -32;
          __asm { lvrx128   v43, r29, r11 }
          _R11 = &_R30->wheelSteeringAxis;
          __asm
          {
            vmulfp128 v42, v80, v51
            vor128    v12, v76, v43
            lvx128    v5, r31, r8
          }
          _R4 = -96;
          __asm
          {
            lvlx128   v41, r0, r10
            lvrx128   v40, r29, r10
            lvx128    v7, r31, r7
            vpermwi128 v39, v12, 0xFC
            vmulfp128 v38, v77, v61
            lvx128    v6, r31, r6
            vpermwi128 v1, v12, 0x85
            vor128    v63, v73, v40
            vmulfp128 v37, v74, v61
            vsldoi128 v36, v69, v46, 4
            vsldoi128 v35, v68, v38, 4
            vsldoi128 v34, v67, v127, 4
            vmulfp128 v33, v66, v59
            vmulfp128 v32, v65, v58
            vcmpgefp128 v61, v127, v33
            vrfiz128  v59, v32
            vand128   v58, v93, v13
            vsubfp128 v55, v91, v58
            vmulfp128 v54, v87, v57
            vsubfp128 v53, v86, v33
            vaddfp128 v52, v85, v60
            vand128   v51, v84, v62
            vor128    v0, v84, v52
            vxor128   v50, v84, v51
            vxor128   v49, v83, v60
            vcmpgefp128 v10, v88, v50
            vsubfp128 v11, v81, v52
            vand128   v48, v10, v62
            vsel      v10, v11, v0, v10
            vmr128    v47, v10
            vmulfp128 v0, v79, v47
            vmaddfp   v11, v0, v9, v8
            vmaddfp   v9, v0, v7, v6
            vmaddfp   v10, v11, v5, v0
            lvx128    v11, r31, r5
            vmaddfp   v6, v9, v11, v0
            lvx128    v11, r31, r4
            vmaddfp   v30, v10, v11, v0
          }
          _R3 = -16;
          _R10 = -80;
          __asm
          {
            lvx128    v5, r0, r31
            lvx128    v4, r0, r17
          }
          _R9 = 96;
          __asm { lvx128    v2, r0, r19 }
          _R8 = 48;
          __asm
          {
            vmr       v7, v13
            vpermwi128 v8, v12, 0x62 # 'b'
            lvx128    v10, r31, r3
            vmr       v11, v13
            lvx128    v9, r31, r10
          }
          _R6 = 112;
          __asm { lvx128    v59, r31, r9 }
          _R7 = 128;
          __asm { lvx128    v60, r31, r8 }
          _R5 = 64;
          __asm { lvx128    v3, r0, r18 }
          _R4 = 144;
          _R3 = 160;
          __asm
          {
            vmaddfp   v31, v6, v10, v0
            lvx128    v6, r31, r6
            vmaddfp   v10, v30, v9, v0
            lvx128    v58, r31, r7
          }
          _R10 = 224;
          __asm
          {
            vmaddfp   v9, v31, v5, v0
            vmaddfp   v10, v10, v13, v0
            vmaddfp   v0, v9, v13, v0
            vmulfp128 v62, v10, v47
            vxor128   v61, v0, v48
            vperm128  v46, v94, v61, v4
            vperm128  v45, v94, v61, v2
            vperm128  v44, v94, v61, v3
            lvx128    v62, r31, r5
            vpermwi128 v43, v46, 0x18
            vmsum4fp128 v42, v77, v45
            vpermwi128 v5, v46, 0x61 # 'a'
            vpermwi128 v31, v46, 0xFF
            vpermwi128 v13, v46, 0x86
            vmulfp128 v0, v75, v39
            vpermwi128 v41, v44, 0x18
            vpermwi128 v2, v44, 0x61 # 'a'
            vpermwi128 v4, v44, 0xFF
            vpermwi128 v9, v44, 0x86
            vpermwi128 v40, v45, 0x18
            vpermwi128 v3, v45, 0x61 # 'a'
            vpermwi128 v29, v45, 0xFF
            vpermwi128 v10, v45, 0x86
            vmaddfp   v1, v5, v0, v1
            vcmpgtfp128 v5, v74, v59
            vor128    v0, v74, v42
            vxor128   v1, v1, v60
            vsel      v5, v7, v0, v5
            vmaddfp   v0, v31, v1, v12
            vrsqrtefp128 v39, v5
            vnmsubfp  v0, v13, v0, v8
            vmulfp128 v12, v71, v39
            vmulfp128 v38, v71, v58
            vpermwi128 v37, v0, 0xFC
            vpermwi128 v13, v0, 0x85
            vmaddfp   v7, v12, v6, v5
            vpermwi128 v12, v0, 0x62 # 'b'
            vmulfp128 v8, v73, v37
            vmulfp128 v36, v70, v7
            vmaddfp   v13, v2, v8, v13
            vmulfp128 v35, v77, v36
            vxor128   v13, v13, v60
            vmaddfp   v0, v4, v13, v0
            vpermwi128 v33, v35, 0x41 # 'A'
            vaddfp128 v34, v67, v35
            vor128    v8, v67, v35
            vxor128   v26, v65, v62
            vnmsubfp  v13, v9, v0, v12
            vpermwi128 v32, v13, 0xFC
            vpermwi128 v9, v13, 0x85
            vpermwi128 v12, v13, 0x62 # 'b'
            vmulfp128 v7, v72, v32
            vmaddfp   v25, v3, v7, v9
            vpermwi128 v7, v34, 0x5A # 'Z'
            vor128    v9, v66, v34
            lvx128    v0, r31, r4
          }
          _R9 = 272;
          __asm { lvx128    v5, r31, r3 }
          _R8 = &v231;
          __asm { vpermwi128 v27, v35, 0xBF }
          _R7 = 176;
          __asm
          {
            vmaddfp   v7, v26, v0, v7
            vpermwi128 v28, v34, 0xA4
            vnmsubfp  v26, v8, v0, v9
            vxor128   v8, v25, v60
            lvx128    v61, r31, r9
          }
          _R6 = 240;
          __asm { stvx128   v61, r0, r8 }
          _R5 = 192;
          __asm
          {
            lvx128    v4, r31, r10
            vmaddfp   v9, v27, v5, v28
            vmaddfp   v13, v29, v8, v13
            lvx128    v2, r31, r7
          }
          _R4 = 208;
          __asm { lvx128    v3, r31, r6 }
          _R3 = 256;
          __asm { lvx128    v31, r31, r5 }
          _R10 = &v231;
          _R9 = 288;
          _R8 = &v247;
          __asm { lvx128    v30, r31, r4 }
          _R5 = &v247.mat[4];
          __asm { lvx128    v1, r31, r3 }
          _R26 = &v247.mat[8];
          __asm { vperm     v8, v7, v26, v4 }
          __asm
          {
            vnmsubfp  v13, v10, v13, v12
            vmr128    v60, v13
            vmsum4fp128 v13, v92, v60
            vcmpgtfp128 v12, v13, v59
            vsel      v12, v11, v13, v12
            vrsqrtefp128 v59, v12
            vmulfp128 v13, v91, v59
            vmulfp128 v58, v91, v58
            vmaddfp   v13, v13, v6, v12
            vmulfp128 v57, v90, v13
            vmulfp128 v56, v92, v57
            vaddfp128 v55, v88, v56
            vpermwi128 v54, v56, 0x41 # 'A'
            vor128    v12, v88, v56
            vpermwi128 v6, v56, 0xBF
            vxor128   v29, v86, v62
            vpermwi128 v11, v55, 0x5A # 'Z'
            vor128    v13, v87, v55
            vpermwi128 v10, v55, 0xA4
            vmaddfp   v11, v29, v0, v11
            vnmsubfp  v29, v12, v0, v13
            vmaddfp   v0, v6, v5, v10
            vperm     v13, v11, v29, v4
            vmaddfp   v6, v0, v11, v2
            vperm     v12, v11, v0, v3
            vmaddfp   v11, v9, v7, v2
            vmaddfp   v0, v0, v13, v31
            vmaddfp   v10, v12, v13, v30
            vperm     v13, v7, v9, v3
            vmaddfp   v12, v9, v8, v31
            vmaddfp   v13, v13, v8, v30
            vperm128  v53, v6, v63, v1
            lvx128    v6, r0, r10
            vperm128  v52, v11, v63, v1
          }
          _R10 = 32;
          __asm
          {
            vperm128  v51, v0, v63, v6
            lvx128    v0, r31, r9
            vperm128  v50, v10, v63, v0
            vperm128  v49, v12, v63, v6
            stvx128   v53, r0, r8
            vperm128  v48, v13, v63, v0
            stvx128   v51, r0, r5
            stvx128   v50, r0, r26
            stvx128   v49, r11, r29
            stvx128   v52, r0, r11
            stvx128   v48, r11, r10
          }
          idTreeAnimator::SetJointMat3x4(
            this: animator,
            pose: (animationPose_t)0,
            jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)_R30->wheelJointIndex.value,
            type: JOINTMOD_MODEL_OVERRIDE,
            mat: &v247,
            setPos: (_cntlzw(_R30->suspensionLever.num) & 0x20) != 0);
          ++v69;
          ++v72;
          ++v71;
        }
        while ( v69 < _R27->animWheels.num );
      }
      if ( _R27->rotateSteeringWheel && (unsigned __int16)_R27->steeringWheelJoint.value < 0x8000u )
      {
        _R11 = 140;
        __asm
        {
          lvx128    v61, r0, r22
          lvx128    v60, r0, r28
          vspltisw128 v47, 0
        }
        _R10 = -176;
        __asm { lvx128    v59, r0, r14 }
        _R6 = -48;
        __asm { lvx128    v63, r0, r15 }
        _R9 = 32;
        __asm
        {
          lvx128    v58, r0, r16
          lvlx128   v46, r27, r11
        }
        _R11 = &_R27->steeringWheelAxis;
        _R8 = -128;
        __asm
        {
          lvx128    v30, r0, r31
          vspltw128 v45, v46, 0
          lvx128    v13, r31, r10
          lvx128    v6, r31, r6
        }
        _R6 = 80;
        __asm { lvx128    v62, r31, r9 }
        _R7 = -144;
        __asm { lvlx128   v43, r0, r11 }
        _R5 = -64;
        __asm
        {
          vmulfp128 v44, v77, v61
          lvrx128   v40, r29, r11
          vor128    v37, v75, v40
          lvx128    v8, r31, r8
          lvx128    v61, r31, r6
        }
        _R4 = -112;
        __asm { lvx128    v7, r31, r7 }
        _R3 = -32;
        __asm { lvx128    v5, r31, r5 }
        _R9 = -96;
        __asm { vand128   v35, v69, v61 }
        _R8 = -16;
        _R7 = -80;
        __asm { lvx128    v4, r31, r4 }
        _R10 = &_R27->steeringWheelJointQuat;
        __asm { lvx128    v3, r31, r3 }
        _R5 = -192;
        __asm { lvx128    v2, r31, r9 }
        _R4 = 96;
        __asm
        {
          lvx128    v1, r31, r8
          lvx128    v31, r31, r7
          vmulfp128 v41, v76, v60
          lvlx128   v42, r0, r10
          vcmpgefp128 v39, v79, v44
          lvrx128   v38, r29, r10
          vor128    v12, v74, v38
          vpermwi128 v36, v12, 0xFC
          vpermwi128 v29, v12, 0x85
          vpermwi128 v11, v12, 0x62 # 'b'
          vrfiz128  v34, v41
          vand128   v33, v71, v13
          vsubfp128 v32, v66, v33
          vmulfp128 v61, v64, v59
          vsubfp128 v60, v93, v44
          vaddfp128 v59, v92, v63
          vand128   v57, v91, v62
          vor128    v0, v91, v59
          vxor128   v56, v91, v57
          vxor128   v55, v89, v63
          lvx128    v63, r31, r5
          vcmpgefp128 v9, v90, v56
          vsubfp128 v10, v87, v59
          vand128   v54, v9, v62
          vsel      v9, v10, v0, v9
          vmr128    v53, v9
          vmulfp128 v0, v85, v53
          vmaddfp   v10, v0, v8, v7
          vmaddfp   v9, v0, v6, v5
          vmaddfp   v10, v10, v4, v0
          vmaddfp   v9, v9, v3, v0
          vmaddfp   v10, v10, v2, v0
          vmaddfp   v9, v9, v1, v0
          vmaddfp   v10, v10, v31, v0
          vmaddfp   v9, v9, v30, v0
          vmaddfp   v10, v10, v13, v0
          vmaddfp   v0, v9, v13, v0
          vmulfp128 v52, v10, v53
          vxor128   v51, v0, v54
          vaddfp128 v50, v83, v13
          vsldoi128 v49, v84, v63, 4
          lvx128    v62, r31, r4
          vsldoi128 v47, v95, v50, 4
        }
        _R11 = 128;
        _R10 = 112;
        v199 = _R27->animator;
        _R9 = 48;
        __asm { vmulfp128 v48, v81, v35 }
        _R8 = 64;
        _R7 = 144;
        __asm { lvx128    v61, r31, r11 }
        _R6 = 160;
        __asm { lvx128    v8, r31, r10 }
        _R5 = 224;
        __asm { lvx128    v60, r31, r9 }
        _R4 = 240;
        __asm { lvx128    v59, r31, r8 }
        _R11 = 176;
        __asm { lvx128    v10, r31, r7 }
        _R10 = 192;
        __asm { lvx128    v7, r31, r6 }
        _R9 = 208;
        __asm { lvx128    v6, r31, r5 }
        _R8 = 256;
        __asm { lvx128    v4, r31, r4 }
        _R7 = 272;
        __asm { lvx128    v5, r31, r11 }
        _R6 = 288;
        __asm { lvx128    v3, r31, r10 }
        _R5 = &v246;
        __asm
        {
          vor128    v46, v80, v47
          lvx128    v2, r31, r9
          lvx128    v1, r31, r8
        }
        _R4 = &v246.mat[4];
        _R11 = &v246.mat[8];
        __asm
        {
          vmsum4fp128 v0, v78, v46
          vcmpgtfp128 v9, v0, v62
          vsel      v9, v13, v0, v9
          vrsqrtefp128 v45, v9
          vmulfp128 v0, v77, v45
          vmulfp128 v44, v77, v61
          vmaddfp   v0, v0, v8, v9
          vmulfp128 v43, v76, v0
          vmulfp128 v42, v78, v43
          vpermwi128 v41, v42, 0x18
          vpermwi128 v8, v42, 0x61 # 'a'
          vpermwi128 v9, v42, 0xFF
          vpermwi128 v0, v42, 0x86
          vmulfp128 v13, v73, v36
          vmaddfp   v13, v8, v13, v29
          vxor128   v13, v13, v60
          vmaddfp   v13, v9, v13, v12
          vnmsubfp  v13, v0, v13, v11
          vaddfp128 v40, v13, v13
          vpermwi128 v39, v13, 0x41 # 'A'
          vpermwi128 v9, v13, 0xBF
          vxor128   v8, v71, v59
          vpermwi128 v11, v40, 0x5A # 'Z'
          vor128    v0, v72, v40
          vpermwi128 v12, v40, 0xA4
          vmaddfp   v11, v8, v10, v11
          vnmsubfp  v10, v13, v10, v0
          vmaddfp   v12, v9, v7, v12
          lvx128    v7, r31, r6
          vperm     v0, v11, v10, v6
          vperm     v13, v11, v12, v4
          vmaddfp   v10, v12, v11, v5
          vmaddfp   v12, v12, v0, v3
          vmaddfp   v13, v13, v0, v2
          lvx128    v0, r31, r7
          vperm128  v38, v10, v63, v1
          vperm128  v37, v12, v63, v0
          vperm128  v36, v13, v63, v7
          stvx128   v38, r0, r5
          stvx128   v37, r0, r4
          stvx128   v36, r0, r11
        }
        if ( v199 != nullptr )
          idTreeAnimator::SetJointMat3x4(
            this: v199,
            pose: DRIVER_MODEL,
            jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)_R27->steeringWheelJoint.value,
            type: JOINTMOD_MODEL_OVERRIDE,
            mat: &v246,
            setPos: false);
      }
      if ( _R27->animator != nullptr )
      {
        v215 = _R27->dialMeters.num;
        v239.x = 1.0;
        v239.y = 1.0;
        v216 = 0;
        v239.z = 1.0;
        if ( v215 > 0 )
        {
          v217 = 0;
          do
          {
            v218 = &_R27->dialMeters.list[v217];
            v233[0] = LODWORD(v218->value);
            idQuat::idQuat(this: &v232, axis: &v218->axis, angle: v233, a4: v7);
            v219 = v218->rot.z;
            v220 = (float)-(float)((float)(v218->rot.y * v232.y)
                                 - (float)((float)(v218->rot.w * v232.w) - (float)(v218->rot.x * v232.x)));
            v221 = (float)-(float)((float)(v218->rot.z * v232.x)
                                 - (float)((float)(v218->rot.w * v232.y)
                                         + (float)((float)(v218->rot.y * v232.w) + (float)(v218->rot.x * v232.z))));
            v222 = (float)-(float)((float)(v218->rot.x * v232.y)
                                 - (float)((float)(v218->rot.y * v232.x)
                                         + (float)((float)(v218->rot.w * v232.z) + (float)(v218->rot.z * v232.w))));
            v232.x = -(float)((float)(v218->rot.y * v232.z)
                            - (float)((float)(v218->rot.w * v232.x)
                                    + (float)((float)(v218->rot.x * v232.w) + (float)(v218->rot.z * v232.y))));
            v232.y = v221;
            v232.w = -(float)((float)((float)v219 * v232.z) - (float)v220);
            v232.z = v222;
            idQuat::ToMat3(this: (idQuat *)&v242, result: (idMat3 *)&v232);
            v223 = v218->pos.y;
            v224 = v218->pos.z;
            v225 = _R27->animator;
            v231.x = v218->pos.x;
            v231.y = v223;
            v231.z = v224;
            idTreeAnimator::SetJointPosAxisScale(
              this: v225,
              pose: DRIVER_MODEL,
              jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)v218->joint.value,
              type: JOINTMOD_MODEL_OVERRIDE,
              pos: &v231,
              axis: &v242,
              scale: &v239);
            ++v216;
            ++v217;
          }
          while ( v216 < _R27->dialMeters.num );
        }
      }
    }
  }
  _R0 = -320;
  __asm { lvx128    v127, r1, r0 }
}


// ========================================================================
// ?DeleteAnimWheels@idAnimator_VehicleCar@@AAAXXZ
// EA  : 0x826EFE18
// RVA : 0x006EFE18
// PDB : w:\tech5\engine\gamelib\animstack\animator_vehiclecar.cpp
// ========================================================================

void __fastcall idAnimator_VehicleCar::DeleteAnimWheels(idAnimator_VehicleCar *this)
{
  int v2; // r29
  int v3; // r30
  idClipModel *clipModel; // r3
  char *list; // r3

  v2 = 0;
  if ( this->animWheels.num > 0 )
  {
    v3 = 0;
    do
    {
      clipModel = this->animWheels.list[v3].clipModel;
      if ( clipModel != nullptr )
        idClipModel::Delete(this: clipModel);
      ++v2;
      ++v3;
    }
    while ( v2 < this->animWheels.num );
  }
  if ( this->animWheels.listStatic == 0 || this->animWheels.listStatic == 2 )
  {
    list = (char *)this->animWheels.list;
    if ( list != nullptr )
      idListArrayDelete<idAnimWheel>(ptr: list, num: this->animWheels.size);
    this->animWheels.list = nullptr;
    this->animWheels.size = 0;
  }
  this->animWheels.num = 0;
}


// ========================================================================
// ?InternalInitDialMeter@idAnimator_VehicleCar@@AAAHABUdialMeter_t@@@Z
// EA  : 0x826EFEA8
// RVA : 0x006EFEA8
// PDB : w:\tech5\engine\gamelib\animstack\animator_vehiclecar.cpp
// ========================================================================

int __fastcall idAnimator_VehicleCar::InternalInitDialMeter(idAnimator_VehicleCar *this, const dialMeter_t *props)
{
  dialDirection_t direction; // r11
  double v6; // fp31
  dialAxis_t axis; // r11
  int v8; // r31
  float *p_x; // r11
  double v10; // fp10
  double v11; // fp8
  idQuat *v12; // r3
  double y; // fp4
  double z; // fp3
  double w; // fp2
  __int16 v16; // [sp+50h] [-C0h] BYREF
  idVec3 v17; // [sp+58h] [-B8h] BYREF
  idMat3 v18; // [sp+70h] [-A0h] BYREF
  idAnimDialMeter v19; // [sp+B0h] [-60h] BYREF

  idTreeAnimator::GetJointIndex(
    this: (idTreeAnimator *)&v16,
    result: (idIndex<short,enum invalidJointIndex_t> *)this->animator,
    jointName: props->jointName.data);
  if ( v16 < 0 )
    return -1;
  direction = props->direction;
  v6 = 0.0;
  if ( (unsigned int)direction <= DIAL_MOVE_NEGATIVE )
  {
    if ( direction == DIAL_ROTATE_RIGHT || direction == DIAL_MOVE_POSITIVE )
      v6 = 1.0;
    else
      v6 = -1.0;
  }
  axis = props->axis;
  v8 = 0;
  if ( axis != DIAL_AXIS_X )
  {
    if ( axis == DIAL_AXIS_Y )
    {
      v8 = 1;
    }
    else if ( (unsigned int)axis < (DIAL_AXIS_Z|DIAL_AXIS_Y) )
    {
      v8 = 2;
    }
  }
  else
  {
    v8 = 0;
  }
  idTreeAnimator::GetModelSpaceJointTransform(
    this: this->animator,
    pose: DRIVER_MODEL,
    jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)v16,
    origin: &v17,
    axis: (idMat3 *)&v18.mat[1].y);
  v19.pos.x = v17.x;
  p_x = &mat3_identity.mat[v8].x;
  v19.pos.y = v17.y;
  v19.pos.z = v17.z;
  v19.joint.value = v16;
  v10 = (float)(p_x[1] * (float)v6);
  v11 = (float)(p_x[2] * (float)v6);
  v19.axis.x = *p_x * (float)v6;
  v19.axis.y = v10;
  v19.axis.z = v11;
  v12 = idMat3::ToQuat(this: &v18, result: (idQuat *)&v18.mat[1].y);
  v19.value = 0.0;
  y = v12->y;
  z = v12->z;
  w = v12->w;
  v19.rot.x = v12->x;
  v19.rot.y = y;
  v19.rot.z = z;
  v19.rot.w = w;
  return idList<idAnimDialMeter,5>::Append(this: &this->dialMeters, obj: &v19);
}


// ========================================================================
// ?InternalPreBlendTree@idAnimator_VehicleCar@@MAAXPBVidAnimStack@@HH@Z
// EA  : 0x826F0040
// RVA : 0x006F0040
// PDB : w:\tech5\engine\gamelib\animstack\animator_vehiclecar.cpp
// ========================================================================

void __fastcall idAnimator_VehicleCar::InternalPreBlendTree(
        idAnimator_VehicleCar *this,
        const idAnimStack *stack,
        const int curTime,
        const int ticksPerSec)
{
  unsigned __int64 v5; // r6
  const char *v6; // r7
  idPLogScope v7[6]; // [sp+50h] [-30h] BYREF

  RD_EventBegin(name: "idAnimator_VehicleCar::InternalPreBlendTree");
  LODWORD(v5) = "idAnimator_VehicleCar::InternalPreBlendTree";
  HIDWORD(v5) = 2;
  idPLogScope::idPLogScope(this: v7, pl: &pLog, gMask: v5, label: v6);
  idAnimator_VehicleCar::Evaluate(this);
  idPLogScope::~idPLogScope(this: v7);
  RD_EventEnd();
}


// ========================================================================
// __unwind$252515
// EA  : 0x826F0098
// RVA : 0x006F0098
// PDB : w:\tech5\engine\gamelib\animstack\animator_vehiclecar.cpp
// ========================================================================

void _unwind_252515()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 128 + 88));
}


// ========================================================================
// __unwind$252516
// EA  : 0x826F00C0
// RVA : 0x006F00C0
// PDB : w:\tech5\engine\gamelib\animstack\animator_vehiclecar.cpp
// ========================================================================

void _unwind_252516()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 128 + 80));
}


// ========================================================================
// ??0idAnimator_VehicleCar@@QAA@XZ
// EA  : 0x826F01B0
// RVA : 0x006F01B0
// PDB : w:\tech5\engine\gamelib\animstack\animator_vehiclecar.cpp
// ========================================================================

idAnimator_VehicleCar *__fastcall idAnimator_VehicleCar::idAnimator_VehicleCar(idAnimator_VehicleCar *this)
{
  float w; // r4

  idAnimator_Base::idAnimator_Base(this);
  this->animator = nullptr;
  this->__vftable = (idAnimator_VehicleCar_vtbl *)&idAnimator_VehicleCar::`vftable';
  this->vehicleProps = nullptr;
  this->animWheels.granularity = 0;
  this->animWheels.memTag = 5;
  this->animWheels.listStatic = 0;
  this->animWheels.list = nullptr;
  this->animWheels.size = 0;
  this->animWheels.num = 0;
  this->clip = nullptr;
  this->entityNum = 0x1FFF;
  this->renderModel = nullptr;
  this->dialMeters.list = nullptr;
  this->dialMeters.granularity = 0;
  this->dialMeters.memTag = 5;
  this->dialMeters.listStatic = 0;
  this->dialMeters.size = 0;
  this->dialMeters.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->dialMeters);
  this->accelerating = false;
  this->handBraking = false;
  this->isReversing = false;
  this->playerOccupant = false;
  this->speedometer = -1;
  this->tachometer = -1;
  this->rotateSteeringWheel = true;
  this->clipMask = 107553;
  this->steeringWheelJoint.value = -1;
  this->steeringWheelAxis.x = 1.0;
  this->steeringWheelAxis.y = 0.0;
  this->steeringWheelAxis.z = 0.0;
  this->steeringWheelJointQuat.x = quat_identity.x;
  this->steeringWheelJointQuat.y = quat_identity.y;
  this->steeringWheelJointQuat.z = quat_identity.z;
  w = quat_identity.w;
  this->steerAngle = 0.0;
  this->lastSteerAngle = 0.0;
  this->updateWheelAngle = true;
  this->newSteerAngle = 0.0;
  this->isOnElevator = false;
  this->steeringWheelJointQuat.w = w;
  return this;
}


// ========================================================================
// __unwind$252574
// EA  : 0x826F02E0
// RVA : 0x006F02E0
// PDB : w:\tech5\engine\gamelib\animstack\animator_vehiclecar.cpp
// ========================================================================

void _unwind_252574()
{
  int v0; // r12

  idAnimator_Base::~idAnimator_Base(this: *(idAnimator_Base **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$252575
// EA  : 0x826F0308
// RVA : 0x006F0308
// PDB : w:\tech5\engine\gamelib\animstack\animator_vehiclecar.cpp
// ========================================================================

void _unwind_252575()
{
  int v0; // r12

  idList<idAnimWheel,5>::~idList<idAnimWheel,5>(this: (idList<idAnimWheel,5> *)(*(_DWORD *)(v0 - 128 + 148) + 48));
}


// ========================================================================
// ??1idAnimator_VehicleCar@@UAA@XZ
// EA  : 0x826F0340
// RVA : 0x006F0340
// PDB : w:\tech5\engine\gamelib\animstack\animator_vehiclecar.cpp
// ========================================================================

void __fastcall idAnimator_VehicleCar::~idAnimator_VehicleCar(idAnimator_VehicleCar *this)
{
  char *list; // r3

  this->__vftable = (idAnimator_VehicleCar_vtbl *)&idAnimator_VehicleCar::`vftable';
  idAnimator_VehicleCar::DeleteAnimWheels(this);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->dialMeters);
  this->animator = nullptr;
  this->clip = nullptr;
  this->renderModel = nullptr;
  this->vehicleProps = nullptr;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->dialMeters);
  if ( this->animWheels.listStatic == 0 || this->animWheels.listStatic == 2 )
  {
    list = (char *)this->animWheels.list;
    if ( list != nullptr )
      idListArrayDelete<idAnimWheel>(ptr: list, num: this->animWheels.size);
    this->animWheels.list = nullptr;
    this->animWheels.size = 0;
  }
  this->animWheels.num = 0;
  idAnimator_Base::~idAnimator_Base(this);
}


// ========================================================================
// __unwind$252657
// EA  : 0x826F03D4
// RVA : 0x006F03D4
// PDB : w:\tech5\engine\gamelib\animstack\animator_vehiclecar.cpp
// ========================================================================

void _unwind_252657()
{
  int v0; // r12

  idAnimator_Base::~idAnimator_Base(this: *(idAnimator_Base **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$252658
// EA  : 0x826F03FC
// RVA : 0x006F03FC
// PDB : w:\tech5\engine\gamelib\animstack\animator_vehiclecar.cpp
// ========================================================================

void _unwind_252658()
{
  int v0; // r12

  idList<idAnimWheel,5>::~idList<idAnimWheel,5>(this: (idList<idAnimWheel,5> *)(*(_DWORD *)(v0 - 128 + 148) + 48));
}


// ========================================================================
// __unwind$252659
// EA  : 0x826F0428
// RVA : 0x006F0428
// PDB : w:\tech5\engine\gamelib\animstack\animator_vehiclecar.cpp
// ========================================================================

void _unwind_252659()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 76));
}


// ========================================================================
// ?InitVehicleAnimator@idAnimator_VehicleCar@@QAAXPAVidGameTimeManager@@PBVidDeclVehicleProps@@PAVidAnimStack@@PAVidRenderModel@@HPAVidClip@@@Z
// EA  : 0x826F0558
// RVA : 0x006F0558
// PDB : w:\tech5\engine\gamelib\animstack\animator_vehiclecar.cpp
// ========================================================================

void __fastcall idAnimator_VehicleCar::InitVehicleAnimator(
        idAnimator_VehicleCar *this,
        idGameTimeManager *game,
        const idDeclVehicleProps *vehicleProps_,
        idAnimStack *animStack_,
        idRenderModel *renderModel_,
        int entityNum_,
        idClip *clip_,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16)
{
  idClip *v22; // r24
  idTreeAnimator *treeAnimator; // r21
  char *data; // r5
  const idMD6Model *model; // r11
  idIndex<short,enum invalidJointIndex_t> *JointIndex; // r3
  __int16 value; // r11
  const idDeclVehicleProps *vehicleProps; // r11
  double v29; // fp0
  int rotationAxis; // r11
  float *v31; // r11
  double v32; // fp2
  double v33; // fp13
  double v34; // fp12
  idQuat *v35; // r3
  int num; // r10
  int v37; // r17
  idMem *x_low; // r30
  int v39; // r18
  int v40; // r19
  idAnimWheel *v41; // r29
  idWheelDef *v42; // r26
  __int16 v43; // r9
  idQuat *v44; // r3
  float y; // r10
  double z; // fp3
  int v47; // r5
  int v48; // r4
  int v49; // r7
  int v50; // r6
  int listStatic; // r11
  int v52; // r4
  int v53; // r22
  int v54; // r24
  int v55; // r25
  const char **p_str; // r28
  idAnimSuspensionLever *v57; // r30
  char *v58; // r5
  char v59; // r11
  idIndex<short,enum invalidJointIndex_t> *v60; // r3
  __int16 v61; // r11
  unsigned int v62; // r11
  double v63; // fp0
  double x; // fp13
  idIndex<short,enum invalidJointIndex_t> *v65; // r3
  unsigned int v66; // r10
  double v67; // fp12
  double v68; // fp6
  double v69; // fp4
  double v70; // fp5
  float *v71; // r10
  int v72; // r11
  _DWORD *v73; // r11
  int v74; // ctr
  const idMat3 *v75; // r3
  idClipModel *v76; // r3
  idClipModel *v77; // r3
  int v78; // r10
  int v79; // r9
  int v80; // r8
  int v81; // r7
  int v82; // r6
  int v83; // r5
  int v84; // r4
  int v85; // r3
  idTreeAnimator v86; // [sp+54h] [-A7Ch] BYREF
  int v87; // [sp+9D0h] [-100h]
  int v88; // [sp+9D4h] [-FCh]
  int v89; // [sp+9D8h] [-F8h]
  int v90; // [sp+9DCh] [-F4h]
  int v91; // [sp+9E0h] [-F0h]
  float v92; // [sp+9E4h] [-ECh]
  float v93; // [sp+9E8h] [-E8h]
  float v94[8]; // [sp+9ECh] [-E4h] BYREF
  __int16 v95; // [sp+A0Ch] [-C4h]
  __int16 v96; // [sp+A0Eh] [-C2h]

  v22 = clip_;
  if ( vehicleProps_ == nullptr )
  {
    idLib::Warning(fmt: "idAnimator_VehicleCar: vehicleProps == NULL for '%s'", "<unknown>");
    return;
  }
  *(_DWORD *)&v86.gameParmBlock.staticOps[10].parmIndexA = animStack_;
  idStr::idStr(this: (idStr *)&v86.gameParmBlock.staticOps[11], text: "vehicleAnimator");
  memset(&v86.gameParmBlock.staticOps[15].parmIndexA, 0, 12);
  *(_DWORD *)&v86.gameParmBlock.staticOps[15].type = 1;
  *(float *)&v86.gameParmBlock.staticOps[17].type = 1.0;
  idAnimator_Base::Init(
    this,
    gametimeManager: game,
    parms: (const idAnimatorParms_Base *)&v86.gameParmBlock.staticOps[10].parmIndexA);
  this->vehicleProps = vehicleProps_;
  treeAnimator = animStack_->treeAnimator;
  this->animator = treeAnimator;
  this->clip = v22;
  this->entityNum = entityNum_;
  this->renderModel = renderModel_;
  data = vehicleProps_->steeringWheel.jointName.data;
  model = treeAnimator->decl->model;
  if ( model != nullptr && (*((_DWORD *)&v86.__vftable + 1) = model->skeleton, *((_DWORD *)&v86.__vftable + 1) != 0) )
  {
    JointIndex = idMD6Skel::GetJointIndex(
                   this: (idMD6Skel *)&v86,
                   result: *((idIndex<short,enum invalidJointIndex_t> **)&v86.__vftable + 1),
                   name: data);
  }
  else
  {
    JointIndex = (idIndex<short,enum invalidJointIndex_t> *)&v86;
    HIWORD(v86.__vftable) = -1;
  }
  value = JointIndex->value;
  this->steeringWheelJoint = (idIndex<short,enum invalidJointIndex_t>)JointIndex->value;
  if ( value >= 0 )
  {
    idTreeAnimator::GetModelSpaceJointTransform(
      this: this->animator,
      pose: DRIVER_MODEL,
      jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)value,
      origin: (idVec3 *)&v86.gameParmBlock.staticOps[20].parmIndexA,
      axis: (idMat3 *)&v86.g.origin.z);
    vehicleProps = this->vehicleProps;
    if ( vehicleProps->steeringWheel.rotationDirection != ROTATE_LEFT )
      v29 = 1.0;
    else
      v29 = -1.0;
    rotationAxis = vehicleProps->steeringWheel.rotationAxis;
    v86.g.scale.z = v86.g.origin.z;
    *(float *)&v86.g.customMaterial = v86.g.axis.mat[0].z;
    *((_DWORD *)&v86.__vftable + 1) = &this->steeringWheelAxis;
    v31 = &v86.g.origin.z + 3 * rotationAxis;
    *(float *)&v86.g.customSkin = v86.g.axis.mat[1].z;
    v32 = (float)(*v31 * (float)v29);
    v33 = (float)(v31[2] * (float)v29);
    v34 = (float)(v31[1] * (float)v29);
    *(float *)&v86.g.groupMasterIndex = v86.g.axis.mat[0].x;
    *(float *)&v86.g.allowSurfaceOnlyInViewID = v86.g.axis.mat[1].x;
    *(float *)&v86.g.suppressSurfaceInViewID = v86.g.axis.mat[2].x;
    *(float *)&v86.g.suppressShadowInViewID = v86.g.axis.mat[0].y;
    *(float *)&v86.g.suppressShadowInLightIndex = v86.g.axis.mat[1].y;
    *(float *)&v86.g.firstVisibleFrameCount = v86.g.axis.mat[2].y;
    this->steeringWheelAxis.y = v34;
    this->steeringWheelAxis.z = v33;
    this->steeringWheelAxis.x = v32;
    v35 = idMat3::ToQuat(this: (idMat3 *)&v86.gameParmBlock.staticOps[18].parmIndexA, result: (idQuat *)&v86.g.scale.z);
    this->steeringWheelJointQuat.x = v35->x;
    this->steeringWheelJointQuat.y = v35->y;
    *((_DWORD *)&v86.__vftable + 1) = &this->steeringWheelJointQuat;
    this->steeringWheelJointQuat.z = v35->z;
    this->steeringWheelJointQuat.w = v35->w;
  }
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->dialMeters);
  this->speedometer = idAnimator_VehicleCar::InternalInitDialMeter(this, props: &this->vehicleProps->speedometer);
  this->tachometer = idAnimator_VehicleCar::InternalInitDialMeter(this, props: &this->vehicleProps->tachometer);
  idAnimWheel::idAnimWheel(this: (idAnimWheel *)&v86.gameParmBlock.staticOps[30].parmIndexA);
  idAnimator_VehicleCar::DeleteAnimWheels(this);
  idList<idAnimWheel,5>::SetNum(
    this: &this->animWheels,
    newNum: this->vehicleProps->wheels.num,
    initValue: (const idAnimWheel *)&v86.gameParmBlock.staticOps[30].parmIndexA);
  num = this->animWheels.num;
  v37 = 0;
  x_low = &mem;
  LODWORD(v86.deferredOrigin.x) = &mem;
  if ( num <= 0 )
  {
LABEL_49:
    if ( (LOBYTE(v86.gameParmBlock.staticOps[32].parmIndexDest) == 0
       || LOBYTE(v86.gameParmBlock.staticOps[32].parmIndexDest) == 2)
      && *(_DWORD *)&v86.gameParmBlock.staticOps[30].parmIndexA != 0 )
    {
      idMem::Free(this: x_low, ptr: *(void **)&v86.gameParmBlock.staticOps[30].parmIndexA, align: ALIGN_16);
    }
  }
  else
  {
    v39 = 0;
    *((_DWORD *)&v86.__vftable + 1) = &bounds_zero;
    v40 = 0;
    LODWORD(v86.deferredOrigin.y) = &quat_identity;
    while ( 1 )
    {
      v41 = &this->animWheels.list[v39];
      v42 = &this->vehicleProps->wheels.list[v40];
      v43 = idTreeAnimator::GetJointIndex(
              this: &v86,
              result: (idIndex<short,enum invalidJointIndex_t> *)treeAnimator,
              jointName: v42->wheelJoint.str)->value;
      v41->wheelJointIndex.value = v43;
      if ( v43 < 0 )
        break;
      idTreeAnimator::GetModelSpaceJointTransform(
        this: treeAnimator,
        pose: DRIVER_MODEL,
        jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)v43,
        origin: (idVec3 *)&v86.__vftable + 1,
        axis: (idMat3 *)&v86.g.viewport);
      *((float *)&v86.g + 26) = *(float *)&v86.g.viewport.x1;
      *((float *)&v86.g + 27) = *(float *)&v86.g.viewport.y2;
      v86.g.radiosityScale = *(float *)&v86.gameParmBlock.ops.num;
      *((float *)&v86.g + 29) = *(float *)&v86.g.viewport.y1;
      v86.g.staticReflectionStrength = *((float *)&v86.g + 42);
      v86.g.highlightColor = (highlightColor_t)v86.gameParmBlock.ops.size;
      v86.g.dimShadowClipZ = *(float *)&v86.g.viewport.x2;
      v86.g.maxTexelDensity = *(float *)&v86.gameParmBlock.ops.list;
      v86.g.modelFade = *(float *)&v86.gameParmBlock.ops.granularity;
      v44 = idMat3::ToQuat(
              this: (idMat3 *)&v86.gameParmBlock.staticOps[18].parmIndexA,
              result: (idQuat *)((char *)&v86.g + 104));
      v41->localJointQuat.x = v44->x;
      y = v86.deferredOrigin.y;
      v41->localJointQuat.y = v44->y;
      z = v44->z;
      v86.gameParmBlock.staticOps[4].parmIndexA = -1;
      v41->localJointQuat.z = z;
      v86.gameParmBlock.staticOps[4].parmIndexB = -1;
      v41->localJointQuat.w = v44->w;
      v47 = *(_DWORD *)(LODWORD(y) + 4);
      *(float *)&v86.gameParmBlock.staticOps[5].type = 1.0;
      v48 = *(_DWORD *)(LODWORD(y) + 8);
      *(float *)&v86.gameParmBlock.staticOps[5].parmIndexA = 0.0;
      v49 = *(_DWORD *)(LODWORD(y) + 12);
      *(float *)&v86.gameParmBlock.staticOps[6].type = 0.0;
      v50 = *(_DWORD *)LODWORD(y);
      *(float *)&v86.gameParmBlock.staticOps[6].parmIndexA = 0.0;
      listStatic = v41->suspensionLever.listStatic;
      *(float *)&v86.gameParmBlock.staticOps[7].type = 0.0;
      *(float *)&v86.gameParmBlock.staticOps[7].parmIndexA = 0.0;
      *(float *)&v86.gameParmBlock.staticOps[8].type = 0.0;
      *(_DWORD *)&v86.gameParmBlock.staticOps[9].parmIndexA = v48;
      *(_DWORD *)&v86.gameParmBlock.staticOps[9].type = v47;
      *(_DWORD *)&v86.gameParmBlock.staticOps[8].parmIndexA = v50;
      *(_DWORD *)&v86.gameParmBlock.staticOps[10].type = v49;
      if ( listStatic == 0 || listStatic == 2 )
      {
        if ( v41->suspensionLever.list != nullptr )
          idMem::Free(this: x_low, ptr: v41->suspensionLever.list, align: ALIGN_16);
        v41->suspensionLever.list = nullptr;
        v41->suspensionLever.size = 0;
      }
      v41->suspensionLever.num = 0;
      idList<idAnimSuspensionLever,5>::SetNum(
        this: &v41->suspensionLever,
        newNum: v42->suspensionLever.num,
        initValue: (const idAnimSuspensionLever *)&v86.gameParmBlock.staticOps[4].parmIndexA);
      v53 = 0;
      if ( v42->suspensionLever.num > 0 )
      {
        v54 = 0;
        v55 = 0;
        while ( 1 )
        {
          p_str = &v42->suspensionLever.list[v55].joint.str;
          v57 = &v41->suspensionLever.list[v54];
          v58 = (char *)*p_str;
          if ( *p_str == &byte_8200D768 || (v59 = 0, *v58 == 0) )
            v59 = 1;
          if ( v59 != 0 )
            goto _LN428;
          v60 = idTreeAnimator::GetJointIndex(
                  this: (idTreeAnimator *)((char *)&v86.deferredOrigin.z + 2),
                  result: (idIndex<short,enum invalidJointIndex_t> *)treeAnimator,
                  jointName: v58);
          v61 = v60->value;
          v57->jointIndex = (idIndex<short,enum invalidJointIndex_t>)v60->value;
          if ( v61 < 0 )
          {
            idLib::Error(fmt: "idAnimator_VehicleCar '%s' can't find first lever joint '%s'", "<unknown>", *p_str);
_LN429:
            idLib::Error(fmt: "idAnimator_VehicleCar '%s' can't find alignTo joint '%s'", "<unknown>", *p_str);
            _LN430(
              a1: v85,
              a2: v84,
              a3: v83,
              a4: v82,
              a5: v81,
              a6: v80,
              a7: v79,
              a8: v78,
              a9,
              a10,
              a11,
              a12,
              a13,
              a14,
              a15,
              a16);
            return;
          }
          idTreeAnimator::GetModelSpaceJointTransform(
            this: treeAnimator,
            pose: DRIVER_MODEL,
            jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)v61,
            origin: (idVec3 *)&v86.needCommitFrameNum,
            axis: (idMat3 *)&v86.deferredAxis.mat[0].z);
          v62 = (unsigned int)p_str[2];
          if ( v62 > 4 || v62 == 0 )
            break;
          switch ( v62 )
          {
            case 1u:
              v63 = -1.0;
LABEL_39:
              x = 0.0;
              goto LABEL_40;
            case 2u:
              v63 = 0.0;
              x = 1.0;
LABEL_40:
              v67 = 0.0;
              goto LABEL_41;
            case 3u:
              v63 = 0.0;
              x = -1.0;
              goto LABEL_40;
            default:
              break;
          }
          v65 = idTreeAnimator::GetJointIndex(
                  this: (idTreeAnimator *)&v86.deferredOrigin.z,
                  result: (idIndex<short,enum invalidJointIndex_t> *)treeAnimator,
                  jointName: p_str[1]);
          v66 = (unsigned __int16)v57->jointIndex.value;
          v57->alignToJointIndex = (idIndex<short,enum invalidJointIndex_t>)v65->value;
          if ( v66 >= 0x8000 )
            goto _LN429;
          v63 = v86.deferredAxis.mat[1].z;
          x = v86.deferredAxis.mat[2].x;
          v67 = v86.deferredAxis.mat[2].y;
LABEL_41:
          v69 = (float)((float)(*((float *)&v86.__vftable + 3) - *(float *)&v86.needCommitFrameNum)
                      - (float)((float)((float)((float)(*((float *)&v86.__vftable + 3)
                                                      - *(float *)&v86.needCommitFrameNum)
                                              * (float)v63)
                                      + (float)((float)((float)x
                                                      * (float)(*(float *)&v86.name.str - *(float *)&v86.committed))
                                              + (float)((float)v67
                                                      * (float)(*(float *)&v86.debugName - v86.referenceBounds.b[0].x))))
                              * (float)v63));
          v70 = (float)((float)(*(float *)&v86.debugName - v86.referenceBounds.b[0].x)
                      - (float)((float)v67
                              * (float)((float)((float)(*((float *)&v86.__vftable + 3)
                                                      - *(float *)&v86.needCommitFrameNum)
                                              * (float)v63)
                                      + (float)((float)((float)x
                                                      * (float)(*(float *)&v86.name.str - *(float *)&v86.committed))
                                              + (float)((float)v67
                                                      * (float)(*(float *)&v86.debugName - v86.referenceBounds.b[0].x))))));
          v68 = (float)((float)(*(float *)&v86.name.str - *(float *)&v86.committed)
                      - (float)((float)x
                              * (float)((float)((float)(*((float *)&v86.__vftable + 3)
                                                      - *(float *)&v86.needCommitFrameNum)
                                              * (float)v63)
                                      + (float)((float)((float)x
                                                      * (float)(*(float *)&v86.name.str - *(float *)&v86.committed))
                                              + (float)((float)v67
                                                      * (float)(*(float *)&v86.debugName - v86.referenceBounds.b[0].x))))));
          v57->invLength = (float)-1.0
                         / (float)__fsqrts((float)((float)((float)v69 * (float)v69)
                                                 + (float)((float)((float)v70 * (float)v70)
                                                         + (float)((float)v68 * (float)v68))));
          v57->rotationAxis.x = v63;
          v57->rotationAxis.y = x;
          v57->rotationAxis.z = v67;
          v57->alignAxis.x = v86.deferredAxis.mat[2].z;
          v57->alignAxis.y = *(float *)&v86.useDeferredPosition;
          v57->alignAxis.z = *(float *)&v86.needWriteToSnapshot;
          *(float *)&v86.gameParmBlock.usingTempOps = v86.deferredAxis.mat[2].z;
          *(float *)&v86.gameParmBlock.thread = v86.deferredAxis.mat[1].z;
          *(float *)&v86.gameParmBlock.constants.granularity = v86.deferredAxis.mat[0].z;
          *(float *)&v86.gameParmBlock.staticOps[0].type = v86.deferredAxis.mat[1].x;
          *(float *)&v86.gameParmBlock.staticOps[0].parmIndexA = v86.deferredAxis.mat[2].x;
          *(float *)&v86.gameParmBlock.staticOps[1].type = *(float *)&v86.useDeferredPosition;
          *(float *)&v86.gameParmBlock.staticOps[1].parmIndexA = v86.deferredAxis.mat[1].y;
          *(float *)&v86.gameParmBlock.staticOps[2].type = v86.deferredAxis.mat[2].y;
          *(float *)&v86.gameParmBlock.staticOps[2].parmIndexA = *(float *)&v86.needWriteToSnapshot;
          v57->localJointQuat = *idMat3::ToQuat(
                                   this: (idMat3 *)&v86.gameParmBlock.staticOps[22].parmIndexA,
                                   result: (idQuat *)&v86.gameParmBlock.constants.granularity);
          ++v53;
          ++v55;
          ++v54;
          if ( v53 >= v42->suspensionLever.num )
          {
            v22 = clip_;
            x_low = (idMem *)LODWORD(v86.deferredOrigin.x);
            goto LABEL_43;
          }
        }
        v63 = 1.0;
        goto LABEL_39;
      }
LABEL_43:
      v71 = v94;
      *(float *)&v86.name.str = v42->wheelOffset + *(float *)&v86.name.str;
      v72 = *((_DWORD *)&v86.__vftable + 1);
      v41->localJointOrigin.x = *((float *)&v86.__vftable + 3);
      v73 = (_DWORD *)(v72 - 4);
      v41->localJointOrigin.y = *(float *)&v86.name.str;
      v74 = 6;
      v41->localJointOrigin.z = *(float *)&v86.debugName;
      v87 = 0;
      v92 = 0.0;
      v88 = 0;
      v93 = 0.0;
      v89 = 0;
      v94[0] = 0.0;
      v90 = 0;
      v91 = 0;
      do
      {
        *++v71 = *(float *)++v73;
        --v74;
      }
      while ( v74 != 0 );
      v95 = 0;
      v94[7] = 0.0;
      v96 = 0;
      idTraceModel::SetupCylinder(
        this: (idTraceModel *)&v86.gameParmBlock.staticConstants[22].swizzle[3],
        height: 5.0,
        width: (float)(v42->wheelRadius * (float)2.0),
        numSides: v52);
      v86.referenceBounds.b[1].z = 0.0;
      v86.g.origin.x = 0.0;
      v86.referenceBounds.b[1].y = 0.70710677;
      v86.g.origin.y = 0.70710677;
      v75 = idQuat::ToMat3(
              this: (idQuat *)&v86.gameParmBlock.staticOps[24].parmIndexA,
              result: (idMat3 *)&v86.referenceBounds.b[1].y);
      idTraceModel::Rotate(this: (idTraceModel *)&v86.gameParmBlock.staticConstants[22].swizzle[3], rotation: v75);
      idTraceModel::Scale(
        this: (idTraceModel *)&v86.gameParmBlock.staticConstants[22].swizzle[3],
        scale: &this->renderModel->g.scale);
      v76 = (idClipModel *)idMem::AllocWithLocation(
                             this: x_low,
                             location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                             size: 0xD8u,
                             tag: TAG_CLIPMODEL,
                             zeroBuffer: false,
                             align: ALIGN_16,
                             heap: HEAP_DEFAULTHEAP);
      if ( v76 != nullptr )
        v77 = idClipModel::idClipModel(
                this: v76,
                clip: v22,
                trm: (const idTraceModel *)&v86.gameParmBlock.staticConstants[22].swizzle[3],
                numTraceModels: 1,
                material: nullptr);
      else
        v77 = nullptr;
      v41->clipModel = v77;
      idClipModel::SetContents(this: v77, newContents: 197120);
      v41->dustTime = 0;
      v41->lastDustPrtDropPos.x = *((float *)&v86.__vftable + 3);
      ++v37;
      v41->lastDustPrtDropPos.y = *(float *)&v86.name.str;
      ++v40;
      v41->lastDustPrtDropPos.z = *(float *)&v86.debugName;
      ++v39;
      v41->lastDustPrtDropPos2.x = *((float *)&v86.__vftable + 3);
      v41->lastDustPrtDropPos2.y = *(float *)&v86.name.str;
      v41->lastDustPrtDropPos2.z = *(float *)&v86.debugName;
      if ( v37 >= this->animWheels.num )
        goto LABEL_49;
    }
    idLib::Error(fmt: "idAnimator_VehicleCar '%s' can't find wheel joint '%s'", "<unknown>", v42->wheelJoint.str);
_LN428:
    if ( (LOBYTE(v86.gameParmBlock.staticOps[32].parmIndexDest) == 0
       || LOBYTE(v86.gameParmBlock.staticOps[32].parmIndexDest) == 2)
      && *(_DWORD *)&v86.gameParmBlock.staticOps[30].parmIndexA != 0 )
    {
      idMem::Free(
        this: (idMem *)LODWORD(v86.deferredOrigin.x),
        ptr: *(void **)&v86.gameParmBlock.staticOps[30].parmIndexA,
        align: ALIGN_16);
    }
  }
  idStr::FreeData(this: (idStr *)&v86.gameParmBlock.staticOps[11]);
}


// ========================================================================
// $LN430
// EA  : 0x826F0E18
// RVA : 0x006F0E18
// PDB : w:\tech5\engine\gamelib\animstack\animator_vehiclecar.cpp
// ========================================================================

void _LN430()
{
  int v0; // r12

  idAnimatorParms_EndAdditiveChannels::~idAnimatorParms_EndAdditiveChannels(this: (vaiAction_t::vehicleCam_t *)(v0 - 2768 + 496));
}


// ========================================================================
// __unwind$252755
// EA  : 0x826F0E40
// RVA : 0x006F0E40
// PDB : w:\tech5\engine\gamelib\animstack\animator_vehiclecar.cpp
// ========================================================================

void _unwind_252755()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 2768 + 656));
}


// ========================================================================
// __unwind$252756
// EA  : 0x826F0E68
// RVA : 0x006F0E68
// PDB : w:\tech5\engine\gamelib\animstack\animator_vehiclecar.cpp
// ========================================================================

void _unwind_252756()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 2768 + 80), tag: TAG_CLIPMODEL);
}


// ========================================================================
// ?SerializeSnapshot@idAnimator_VehicleCar@@UAAXAAVidSerializer@@@Z
// EA  : 0x826F0E98
// RVA : 0x006F0E98
// PDB : w:\tech5\engine\gamelib\animstack\animator_vehiclecar.cpp
// ========================================================================

void __fastcall idAnimator_VehicleCar::SerializeSnapshot(idAnimator_VehicleCar *this, idSerializer *ser)
{
  const idDeclVehicleProps *vehicleProps; // r30
  int v5; // r10
  const idDeclVehicleProps *v6; // r5
  double steerAngle; // fp0
  int num; // r11
  double v9; // fp0
  int v10; // r29
  int v11; // r30
  idAnimWheel *v12; // r11
  int v13; // [sp+8h] [-88h]
  int v14; // [sp+Ch] [-84h]
  int v15; // [sp+10h] [-80h]
  int v16; // [sp+14h] [-7Ch]
  int v17; // [sp+18h] [-78h]
  int v18; // [sp+1Ch] [-74h]
  int v19; // [sp+20h] [-70h]
  int v20; // [sp+24h] [-6Ch]
  float v21[4]; // [sp+50h] [-40h] BYREF

  vehicleProps = this->vehicleProps;
  idSerializer::Serialize<idDeclVehicleProps>(this: ser, decl: &this->vehicleProps);
  v6 = this->vehicleProps;
  if ( vehicleProps != v6 )
    idAnimator_VehicleCar::InitVehicleAnimator(
      this,
      game: this->gametimeManager.gameTimeManager,
      vehicleProps_: v6,
      animStack_: this->serializeProps.animStack,
      renderModel_: this->serializeProps.animStack->treeAnimator,
      entityNum_: -1,
      clip_: this->serializeProps.clip,
      a8: v5,
      a9: v13,
      a10: v14,
      a11: v15,
      a12: v16,
      a13: v17,
      a14: v18,
      a15: v19,
      a16: v20);
  steerAngle = this->steerAngle;
  this->lastSteerAngle = this->steerAngle;
  v21[0] = steerAngle;
  idSerializer::SerializeQ<90,8>(this: ser, value: v21);
  num = this->animWheels.num;
  v9 = v21[0];
  v10 = 0;
  this->steerAngle = v21[0];
  this->newSteerAngle = v9;
  if ( num > 0 )
  {
    v11 = 0;
    do
    {
      v12 = &this->animWheels.list[v11];
      if ( v12->wobbleFrac > 1.0 )
        v12->wobbleFrac = 1.0;
      idSerializer::SerializeUQ<1,4>(this: ser, value: &this->animWheels.list[v11].wobbleFrac);
      ++v10;
      ++v11;
    }
    while ( v10 < this->animWheels.num );
  }
}

