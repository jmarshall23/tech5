
// ========================================================================
// ?GetCurrentValue@?$idExtrapolate@VidAngles@@@@QBA?AVidAngles@@M@Z
// EA  : 0x82749BA0
// RVA : 0x00749BA0
// PDB : w:\tech5\shared\idlib\math\extrapolate.h
// ========================================================================

// local variable allocation has failed, the output may be wrong!
idExtrapolate<idAngles> *__fastcall idExtrapolate<idAngles>::GetCurrentValue(
        idExtrapolate<idAngles> *this,
        idAngles *result,
        double time)
{
  double yaw; // fp13
  float v6; // r11
  float v7; // r10
  float pitch; // r9
  double roll; // fp0
  unsigned int v10; // r11
  signed int v11; // r11
  double v12; // fp2
  double v13; // fp10
  double v14; // fp8
  double v15; // fp5
  double v16; // fp7
  double v17; // fp2
  double v18; // fp1
  double v19; // fp0
  double v20; // fp12
  double v21; // fp11
  double v22; // fp13
  double v23; // fp8
  double v24; // fp7
  double v25; // fp4
  double v26; // fp3
  double v27; // fp2
  double v28; // fp10
  double v29; // fp8
  double v30; // fp5
  double v31; // fp7
  double v32; // fp31
  long double v33; // fp2
  long double v34; // fp2
  double v35; // fp7
  double v36; // fp6
  double v37; // fp13
  double v38; // fp12
  double v39; // fp31
  long double v40; // fp2
  long double v41; // fp2
  double v42; // fp6
  double v43; // fp5
  double v44; // fp10
  double v45; // fp9

  if ( time == result[4].pitch )
    goto LABEL_28;
  yaw = result->yaw;
  result[4].pitch = time;
  if ( time >= yaw )
  {
    roll = result->roll;
    if ( roll != 0.0 || (v10 = LODWORD(result->pitch) & 0xFFFFFFBF) == 1 || v10 == 2 )
    {
      if ( (LODWORD(result->pitch) & 0x40) == 0 && time > (float)(result->roll + (float)yaw) )
        time = (float)(result->roll + (float)yaw);
      v11 = LODWORD(result->pitch) & 0xFFFFFFBF;
      if ( v11 > 8 )
      {
        if ( v11 == 16 )
        {
          if ( roll != 0.0 )
          {
            v39 = (float)((float)((float)time - (float)yaw) / result->roll);
            *(double *)&v40 = (float)(idMath::HALF_PI * (float)((float)((float)time - (float)yaw) / result->roll));
            v41 = cos(x: v40);
            v42 = (float)(result[1].yaw + (float)(result[2].yaw * (float)v39));
            v43 = (float)(result[1].roll + (float)(result[2].roll * (float)v39));
            v44 = (float)(result[3].yaw
                        * (float)((float)((float)((float)((float)1.0 - (float)*(double *)&v41) * result->roll)
                                        * (float)0.70710677)
                                * (float)0.001));
            v45 = (float)(result[3].roll
                        * (float)((float)((float)((float)((float)1.0 - (float)*(double *)&v41) * result->roll)
                                        * (float)0.70710677)
                                * (float)0.001));
            result[4].yaw = (float)(result[1].pitch + (float)(result[2].pitch * (float)v39))
                          + (float)(result[3].pitch
                                  * (float)((float)((float)((float)((float)1.0 - (float)*(double *)&v41) * result->roll)
                                                  * (float)0.70710677)
                                          * (float)0.001));
            result[4].roll = (float)v42 + (float)v44;
            result[5].pitch = (float)v43 + (float)v45;
            goto LABEL_28;
          }
        }
        else
        {
          if ( v11 != 32 )
            goto LABEL_28;
          if ( roll != 0.0 )
          {
            v32 = (float)((float)((float)time - (float)yaw) / result->roll);
            *(double *)&v33 = (float)(idMath::HALF_PI * (float)((float)((float)time - (float)yaw) / result->roll));
            v34 = sin(x: v33);
            v35 = (float)(result[1].yaw + (float)(result[2].yaw * (float)v32));
            v36 = (float)(result[1].roll + (float)(result[2].roll * (float)v32));
            v37 = (float)(result[3].yaw
                        * (float)((float)((float)((float)*(double *)&v34 * result->roll) * (float)0.70710677)
                                * (float)0.001));
            v38 = (float)(result[3].roll
                        * (float)((float)((float)((float)*(double *)&v34 * result->roll) * (float)0.70710677)
                                * (float)0.001));
            result[4].yaw = (float)(result[1].pitch + (float)(result[2].pitch * (float)v32))
                          + (float)(result[3].pitch
                                  * (float)((float)((float)((float)*(double *)&v34 * result->roll) * (float)0.70710677)
                                          * (float)0.001));
            result[4].roll = (float)v35 + (float)v37;
            result[5].pitch = (float)v36 + (float)v38;
            goto LABEL_28;
          }
        }
      }
      else
      {
        switch ( v11 )
        {
          case 8:
            if ( roll != 0.0 )
            {
              v27 = (float)((float)((float)time - (float)yaw) / result->roll);
              v28 = (float)(result[1].pitch
                          + (float)((float)(result[2].pitch * (float)((float)((float)time - (float)yaw) / result->roll))
                                  * (float)(result->roll * (float)0.001)));
              v30 = (float)(result[3].roll
                          * (float)((float)-(float)((float)((float)((float)v27 * (float)v27) * (float)0.5) - (float)v27)
                                  * (float)(result->roll * (float)0.001)));
              v31 = (float)(result[3].pitch
                          * (float)((float)-(float)((float)((float)((float)v27 * (float)v27) * (float)0.5) - (float)v27)
                                  * (float)(result->roll * (float)0.001)));
              v29 = (float)(result[1].roll
                          + (float)((float)(result[2].roll * (float)((float)((float)time - (float)yaw) / result->roll))
                                  * (float)(result->roll * (float)0.001)));
              result[4].roll = (float)(result[1].yaw
                                     + (float)((float)(result[2].yaw
                                                     * (float)((float)((float)time - (float)yaw) / result->roll))
                                             * (float)(result->roll * (float)0.001)))
                             + (float)(result[3].yaw
                                     * (float)((float)-(float)((float)((float)((float)v27 * (float)v27) * (float)0.5)
                                                             - (float)v27)
                                             * (float)(result->roll * (float)0.001)));
              result[5].pitch = (float)v29 + (float)v30;
              result[4].yaw = (float)v28 + (float)v31;
              goto LABEL_28;
            }
            break;
          case 1:
            v22 = (float)((float)time - (float)yaw);
            v23 = result[1].yaw;
            v24 = result[1].roll;
            v25 = (float)(result[2].yaw * (float)((float)v22 * (float)0.001));
            v26 = (float)(result[2].roll * (float)((float)v22 * (float)0.001));
            result[4].yaw = result[1].pitch + (float)(result[2].pitch * (float)((float)v22 * (float)0.001));
            result[4].roll = (float)v23 + (float)v25;
            result[5].pitch = (float)v24 + (float)v26;
            goto LABEL_28;
          case 2:
            v17 = result[1].yaw;
            v18 = (float)((float)((float)time - (float)yaw) * (float)0.001);
            v19 = result[1].roll;
            v20 = (float)((float)(result[2].yaw + result[3].yaw) * (float)v18);
            v21 = (float)((float)(result[2].roll + result[3].roll) * (float)v18);
            result[4].yaw = result[1].pitch + (float)((float)(result[3].pitch + result[2].pitch) * (float)v18);
            result[4].roll = (float)v17 + (float)v20;
            result[5].pitch = (float)v19 + (float)v21;
            goto LABEL_28;
          case 4:
            if ( roll != 0.0 )
            {
              v12 = (float)((float)((float)time - (float)yaw) / result->roll);
              v13 = (float)(result[1].pitch
                          + (float)((float)(result[2].pitch * (float)((float)((float)time - (float)yaw) / result->roll))
                                  * (float)(result->roll * (float)0.001)));
              v15 = (float)(result[3].roll
                          * (float)((float)((float)((float)v12 * (float)v12) * (float)0.5)
                                  * (float)(result->roll * (float)0.001)));
              v16 = (float)(result[3].pitch
                          * (float)((float)((float)((float)v12 * (float)v12) * (float)0.5)
                                  * (float)(result->roll * (float)0.001)));
              v14 = (float)(result[1].roll
                          + (float)((float)(result[2].roll * (float)((float)((float)time - (float)yaw) / result->roll))
                                  * (float)(result->roll * (float)0.001)));
              result[4].roll = (float)(result[1].yaw
                                     + (float)((float)(result[2].yaw
                                                     * (float)((float)((float)time - (float)yaw) / result->roll))
                                             * (float)(result->roll * (float)0.001)))
                             + (float)(result[3].yaw
                                     * (float)((float)((float)((float)v12 * (float)v12) * (float)0.5)
                                             * (float)(result->roll * (float)0.001)));
              result[5].pitch = (float)v14 + (float)v15;
              result[4].yaw = (float)v13 + (float)v16;
              goto LABEL_28;
            }
            break;
          default:
LABEL_28:
            pitch = result[5].pitch;
            v7 = result[4].roll;
            v6 = result[4].yaw;
            goto LABEL_29;
        }
      }
      *(idAngles *)((char *)result + 52) = result[1];
      goto LABEL_28;
    }
  }
  v6 = result[1].pitch;
  v7 = result[1].yaw;
  pitch = result[1].roll;
LABEL_29:
  this->duration = pitch;
  this->startTime = v7;
  *(float *)&this->extrapolationType = v6;
  return this;
}


// ========================================================================
// ?GetCurrentSpeed@?$idExtrapolate@VidVec3@@@@QBA?AVidVec3@@M@Z
// EA  : 0x8274A018
// RVA : 0x0074A018
// PDB : w:\tech5\shared\idlib\math\extrapolate.h
// ========================================================================

// local variable allocation has failed, the output may be wrong!
idExtrapolate<idAngles> *__fastcall idExtrapolate<idVec3>::GetCurrentSpeed(
        idExtrapolate<idAngles> *this,
        idAngles *result,
        double time)
{
  double v5; // fp0
  unsigned int v6; // r11
  signed int v7; // r11
  double yaw; // fp8
  double roll; // fp7
  double v10; // fp4
  double v11; // fp3
  double v12; // fp8
  double v13; // fp6
  float v14; // r10
  float v15; // r9
  double v16; // fp13
  double v17; // fp12
  long double v18; // fp2
  long double v19; // fp2
  long double v20; // fp2

  if ( time < result->yaw )
  {
    v5 = 0.0;
    this->startTime = 0.0;
    this->duration = 0.0;
LABEL_24:
    *(float *)&this->extrapolationType = v5;
    return this;
  }
  if ( (result->roll != 0.0 || (v6 = LODWORD(result->pitch) & 0xFFFFFFBF) == 1 || v6 == 2)
    && ((LODWORD(result->pitch) & 0x40) != 0 || time <= (float)(result->roll + result->yaw)) )
  {
    v7 = LODWORD(result->pitch) & 0xFFFFFFBF;
    if ( v7 > 8 )
    {
      if ( v7 == 16 )
      {
        *(double *)&v20 = (float)((float)((float)((float)time - result->yaw) / result->roll) * idMath::HALF_PI);
        v19 = sin(x: v20);
      }
      else
      {
        if ( v7 != 32 )
          goto LABEL_16;
        *(double *)&v18 = (float)((float)((float)((float)time - result->yaw) / result->roll) * idMath::HALF_PI);
        v19 = cos(x: v18);
      }
      v17 = (float)(result[2].roll + (float)(result[3].roll * (float)*(double *)&v19));
      v16 = (float)(result[2].yaw + (float)(result[3].yaw * (float)*(double *)&v19));
      v5 = (float)(result[2].pitch + (float)(result[3].pitch * (float)*(double *)&v19));
    }
    else
    {
      if ( v7 != 8 )
      {
        if ( v7 != 1 )
        {
          if ( v7 == 2 )
          {
            v12 = (float)(result[2].yaw + result[3].yaw);
            v13 = (float)(result[2].roll + result[3].roll);
            *(float *)&this->extrapolationType = result[2].pitch + result[3].pitch;
            this->startTime = v12;
            this->duration = v13;
            return this;
          }
          if ( v7 == 4 )
          {
            yaw = result[2].yaw;
            roll = result[2].roll;
            v10 = (float)(result[3].yaw * (float)((float)((float)time - result->yaw) / result->roll));
            v11 = (float)(result[3].roll * (float)((float)((float)time - result->yaw) / result->roll));
            *(float *)&this->extrapolationType = result[2].pitch
                                               + (float)(result[3].pitch
                                                       * (float)((float)((float)time - result->yaw) / result->roll));
            this->startTime = (float)yaw + (float)v10;
            this->duration = (float)roll + (float)v11;
            return this;
          }
        }
LABEL_16:
        v14 = result[2].yaw;
        v15 = result[2].roll;
        this->extrapolationType = LODWORD(result[2].pitch);
        this->startTime = v14;
        this->duration = v15;
        return this;
      }
      v5 = (float)(result[2].pitch
                 + (float)(result[3].pitch
                         * (float)((float)1.0 - (float)((float)((float)time - result->yaw) / result->roll))));
      v16 = (float)(result[2].yaw
                  + (float)(result[3].yaw
                          * (float)((float)1.0 - (float)((float)((float)time - result->yaw) / result->roll))));
      v17 = (float)(result[2].roll
                  + (float)(result[3].roll
                          * (float)((float)1.0 - (float)((float)((float)time - result->yaw) / result->roll))));
    }
    this->startTime = v16;
    this->duration = v17;
    goto LABEL_24;
  }
  *(float *)&this->extrapolationType = 0.0;
  this->startTime = 0.0;
  this->duration = 0.0;
  return this;
}


// ========================================================================
// ?GetCurrentValue@?$idExtrapolate@M@@QBAMM@Z
// EA  : 0x8274A260
// RVA : 0x0074A260
// PDB : w:\tech5\shared\idlib\math\extrapolate.h
// ========================================================================

// local variable allocation has failed, the output may be wrong!
float __fastcall idExtrapolate<float>::GetCurrentValue(idExtrapolate<float> *this, double time)
{
  double startTime; // fp13
  double currentValue; // fp1
  double duration; // fp0
  unsigned __int32 v6; // r11
  signed __int32 v7; // r11
  double startValue; // fp0
  double v9; // fp7
  double v10; // fp7
  double v11; // fp31
  long double v12; // fp2
  long double v13; // fp2
  double v14; // fp31
  long double v15; // fp2
  long double v16; // fp2

  if ( time == this->currentTime )
    goto LABEL_29;
  startTime = this->startTime;
  this->currentTime = time;
  if ( time >= startTime )
  {
    duration = this->duration;
    if ( duration != 0.0 || (v6 = this->extrapolationType & 0xFFFFFFBF) == 1 || v6 == 2 )
    {
      if ( (this->extrapolationType & 0x40) == 0 && time > (float)(this->duration + (float)startTime) )
        time = (float)(this->duration + (float)startTime);
      v7 = this->extrapolationType & 0xFFFFFFBF;
      if ( v7 > 8 )
      {
        if ( v7 == 16 )
        {
          if ( duration != 0.0 )
          {
            v14 = (float)((float)((float)time - (float)startTime) / this->duration);
            *(double *)&v15 = (float)(idMath::HALF_PI * (float)((float)((float)time - (float)startTime) / this->duration));
            v16 = cos(x: v15);
            startValue = (float)((float)((float)((float)((float)((float)((float)((float)1.0 - (float)*(double *)&v16)
                                                                       * this->duration)
                                                               * (float)0.70710677)
                                                       * (float)0.001)
                                               * this->speed)
                                       + (float)(this->baseSpeed * (float)v14))
                               + this->startValue);
            goto LABEL_28;
          }
          goto LABEL_16;
        }
        if ( v7 == 32 )
        {
          if ( duration == 0.0 )
            goto LABEL_16;
          v11 = (float)((float)((float)time - (float)startTime) / this->duration);
          *(double *)&v12 = (float)(idMath::HALF_PI * (float)((float)((float)time - (float)startTime) / this->duration));
          v13 = sin(x: v12);
          this->currentValue = (float)((float)((float)((float)((float)(this->duration * (float)0.70710677)
                                                             * (float)*(double *)&v13)
                                                     * (float)0.001)
                                             * this->speed)
                                     + (float)(this->baseSpeed * (float)v11))
                             + this->startValue;
        }
      }
      else
      {
        switch ( v7 )
        {
          case 8:
            if ( duration != 0.0 )
            {
              v10 = (float)((float)((float)time - (float)startTime) / this->duration);
              startValue = (float)((float)((float)((float)((float)-(float)((float)((float)((float)v10 * (float)v10)
                                                                                 * (float)0.5)
                                                                         - (float)v10)
                                                         * (float)(this->duration * (float)0.001))
                                                 * this->speed)
                                         + (float)((float)(this->baseSpeed * (float)(this->duration * (float)0.001))
                                                 * (float)((float)((float)time - (float)startTime) / this->duration)))
                                 + this->startValue);
              goto LABEL_28;
            }
            goto LABEL_16;
          case 1:
            this->currentValue = (float)((float)((float)((float)time - (float)startTime) * (float)0.001)
                                       * this->baseSpeed)
                               + this->startValue;
            break;
          case 2:
            this->currentValue = (float)((float)(this->speed + this->baseSpeed)
                                       * (float)((float)((float)time - (float)startTime) * (float)0.001))
                               + this->startValue;
            break;
          case 4:
            if ( duration != 0.0 )
            {
              v9 = (float)((float)((float)time - (float)startTime) / this->duration);
              startValue = (float)((float)((float)((float)((float)((float)((float)v9 * (float)v9) * (float)0.5)
                                                         * (float)(this->duration * (float)0.001))
                                                 * this->speed)
                                         + (float)((float)(this->baseSpeed * (float)(this->duration * (float)0.001))
                                                 * (float)((float)((float)time - (float)startTime) / this->duration)))
                                 + this->startValue);
              goto LABEL_28;
            }
LABEL_16:
            startValue = this->startValue;
LABEL_28:
            this->currentValue = startValue;
            break;
          default:
            break;
        }
      }
LABEL_29:
      currentValue = this->currentValue;
      return *((float *)&currentValue + 1);
    }
  }
  currentValue = this->startValue;
  return *((float *)&currentValue + 1);
}


// ========================================================================
// ?GetCurrentSpeed@?$idExtrapolate@M@@QBAMM@Z
// EA  : 0x8274A978
// RVA : 0x0074A978
// PDB : w:\tech5\shared\idlib\math\extrapolate.h
// ========================================================================

// local variable allocation has failed, the output may be wrong!
float __fastcall idExtrapolate<float>::GetCurrentSpeed(idExtrapolate<float> *this, double time)
{
  double baseSpeed; // fp1
  bool v5; // zf
  unsigned __int32 v6; // r11
  signed __int32 v7; // r11
  long double v8; // fp2
  long double v9; // fp2
  long double v10; // fp2

  v5 = time < this->startTime;
  baseSpeed = 0.0;
  if ( !v5
    && (this->duration != 0.0 || (v6 = this->extrapolationType & 0xFFFFFFBF) == 1 || v6 == 2)
    && ((this->extrapolationType & 0x40) != 0 || time <= (float)(this->duration + this->startTime)) )
  {
    v7 = this->extrapolationType & 0xFFFFFFBF;
    if ( v7 <= 8 )
    {
      if ( v7 == 8 )
      {
        baseSpeed = (float)((float)((float)((float)1.0 - (float)((float)((float)time - this->startTime) / this->duration))
                                  * this->speed)
                          + this->baseSpeed);
        return *((float *)&baseSpeed + 1);
      }
      if ( v7 != 1 )
      {
        if ( v7 == 2 )
        {
          baseSpeed = (float)(this->speed + this->baseSpeed);
          return *((float *)&baseSpeed + 1);
        }
        if ( v7 == 4 )
        {
          baseSpeed = (float)((float)((float)((float)((float)time - this->startTime) / this->duration) * this->speed)
                            + this->baseSpeed);
          return *((float *)&baseSpeed + 1);
        }
      }
LABEL_14:
      baseSpeed = this->baseSpeed;
      return *((float *)&baseSpeed + 1);
    }
    if ( v7 == 16 )
    {
      *(double *)&v10 = (float)((float)((float)((float)time - this->startTime) / this->duration) * idMath::HALF_PI);
      v9 = sin(x: v10);
    }
    else
    {
      if ( v7 != 32 )
        goto LABEL_14;
      *(double *)&v8 = (float)((float)((float)((float)time - this->startTime) / this->duration) * idMath::HALF_PI);
      v9 = cos(x: v8);
    }
    baseSpeed = (float)((float)(this->speed * (float)*(double *)&v9) + this->baseSpeed);
  }
  return *((float *)&baseSpeed + 1);
}


// ========================================================================
// ?Init@?$idExtrapolate@VidQuat@@@@QAAXMMABVidQuat@@00W4extrapolation_t@@@Z
// EA  : 0x8274AB08
// RVA : 0x0074AB08
// PDB : w:\tech5\shared\idlib\math\extrapolate.h
// ========================================================================

void __fastcall idExtrapolate<idQuat>::Init(
        idExtrapolate<idQuat> *this,
        double startTime,
        double duration,
        const idQuat *startValue,
        const idQuat *baseSpeed,
        const idQuat *speed,
        idQuat *extrapolationType,
        idQuat *a8,
        extrapolation_t a9)
{
  this->startTime = startTime;
  this->extrapolationType = a9;
  this->duration = duration;
  this->startValue = *speed;
  this->baseSpeed = *extrapolationType;
  this->speed = *a8;
  this->currentTime = -1.0;
  this->currentValue = *speed;
}


// ========================================================================
// ?GetCurrentValue@?$idExtrapolate@VidQuat@@@@QBA?AVidQuat@@M@Z
// EA  : 0x8274ABA8
// RVA : 0x0074ABA8
// PDB : w:\tech5\shared\idlib\math\extrapolate.h
// ========================================================================

// local variable allocation has failed, the output may be wrong!
idExtrapolate<idQuat> *__fastcall idExtrapolate<idQuat>::GetCurrentValue(
        idExtrapolate<idQuat> *this,
        idQuat *result,
        double time)
{
  double y; // fp13
  float v6; // r10
  float v7; // r9
  float v8; // r8
  float v9; // r7
  double z; // fp0
  unsigned int v11; // r11
  signed int v12; // r11
  double v13; // fp2
  double v14; // fp7
  double v15; // fp6
  double v16; // fp2
  double v17; // fp0
  double v18; // fp13
  double v19; // fp10
  double v20; // fp9
  double v21; // fp11
  double v22; // fp0
  double w; // fp13
  double v24; // fp11
  double v25; // fp10
  double v26; // fp9
  double v27; // fp7
  double v28; // fp6
  double x; // fp7
  double v30; // fp6
  double v31; // fp5
  double v32; // fp3
  double v33; // fp2
  double v34; // fp1
  double v35; // fp0
  double v36; // fp2
  double v37; // fp7
  double v38; // fp6
  double v39; // fp2
  double v40; // fp0
  double v41; // fp13
  double v42; // fp10
  double v43; // fp9
  double v44; // fp11
  double v45; // fp31
  long double v46; // fp2
  long double v47; // fp2
  double v48; // fp4
  double v49; // fp3
  double v50; // fp10
  double v51; // fp8
  double v52; // fp9
  double v53; // fp7
  double v54; // fp31
  long double v55; // fp2
  long double v56; // fp2
  double v57; // fp5
  double v58; // fp6
  double v59; // fp4
  double v60; // fp11
  double v61; // fp10
  double v62; // fp12

  if ( time == result[3].w )
    goto LABEL_28;
  y = result->y;
  result[3].w = time;
  if ( time >= y )
  {
    z = result->z;
    if ( z != 0.0 || (v11 = LODWORD(result->x) & 0xFFFFFFBF) == 1 || v11 == 2 )
    {
      if ( (LODWORD(result->x) & 0x40) == 0 && time > (float)(result->z + (float)y) )
        time = (float)(result->z + (float)y);
      v12 = LODWORD(result->x) & 0xFFFFFFBF;
      if ( v12 > 8 )
      {
        if ( v12 == 16 )
        {
          if ( z != 0.0 )
          {
            v54 = (float)((float)((float)time - (float)y) / result->z);
            *(double *)&v55 = (float)(idMath::HALF_PI * (float)((float)((float)time - (float)y) / result->z));
            v56 = cos(x: v55);
            v57 = (float)(result[1].x + (float)(result[2].x * (float)v54));
            v58 = (float)(result[1].y + (float)(result[2].y * (float)v54));
            v59 = (float)(result[1].z + (float)(result[2].z * (float)v54));
            v60 = (float)(result[3].y
                        * (float)((float)((float)((float)((float)1.0 - (float)*(double *)&v56) * result->z)
                                        * (float)0.70710677)
                                * (float)0.001));
            v61 = (float)(result[3].z
                        * (float)((float)((float)((float)((float)1.0 - (float)*(double *)&v56) * result->z)
                                        * (float)0.70710677)
                                * (float)0.001));
            v62 = (float)(result[3].x
                        * (float)((float)((float)((float)((float)1.0 - (float)*(double *)&v56) * result->z)
                                        * (float)0.70710677)
                                * (float)0.001));
            result[4].x = (float)(result->w + (float)(result[1].w * (float)v54))
                        + (float)(result[2].w
                                * (float)((float)((float)((float)((float)1.0 - (float)*(double *)&v56) * result->z)
                                                * (float)0.70710677)
                                        * (float)0.001));
            result[4].z = (float)v58 + (float)v60;
            result[4].w = (float)v59 + (float)v61;
            result[4].y = (float)v57 + (float)v62;
            goto LABEL_28;
          }
        }
        else
        {
          if ( v12 != 32 )
            goto LABEL_28;
          if ( z != 0.0 )
          {
            v45 = (float)((float)((float)time - (float)y) / result->z);
            *(double *)&v46 = (float)(idMath::HALF_PI * (float)((float)((float)time - (float)y) / result->z));
            v47 = sin(x: v46);
            v48 = (float)(result[1].x + (float)(result[2].x * (float)v45));
            v49 = (float)(result[1].y + (float)(result[2].y * (float)v45));
            v50 = (float)(result[3].x
                        * (float)((float)((float)((float)*(double *)&v47 * result->z) * (float)0.70710677) * (float)0.001));
            v51 = (float)(result[3].z
                        * (float)((float)((float)((float)*(double *)&v47 * result->z) * (float)0.70710677) * (float)0.001));
            v52 = (float)(result[3].y
                        * (float)((float)((float)((float)*(double *)&v47 * result->z) * (float)0.70710677) * (float)0.001));
            v53 = (float)((float)(result->w + (float)(result[1].w * (float)v45))
                        + (float)(result[2].w
                                * (float)((float)((float)((float)*(double *)&v47 * result->z) * (float)0.70710677)
                                        * (float)0.001)));
            *(double *)&v47 = (float)(result[1].z + (float)(result[2].z * (float)v45));
            result[4].x = v53;
            result[4].y = (float)v48 + (float)v50;
            result[4].w = (float)*(double *)&v47 + (float)v51;
            result[4].z = (float)v49 + (float)v52;
            goto LABEL_28;
          }
        }
      }
      else
      {
        switch ( v12 )
        {
          case 8:
            if ( z != 0.0 )
            {
              v36 = (float)((float)((float)time - (float)y) / result->z);
              v37 = (float)((float)-(float)((float)((float)((float)v36 * (float)v36) * (float)0.5) - (float)v36)
                          * (float)(result->z * (float)0.001));
              v38 = (float)(result->w
                          + (float)((float)(result[1].w * (float)((float)((float)time - (float)y) / result->z))
                                  * (float)(result->z * (float)0.001)));
              v39 = (float)(result[1].x
                          + (float)((float)(result[2].x * (float)((float)((float)time - (float)y) / result->z))
                                  * (float)(result->z * (float)0.001)));
              v40 = (float)(result[1].y
                          + (float)((float)(result[2].y * (float)((float)((float)time - (float)y) / result->z))
                                  * (float)(result->z * (float)0.001)));
              v41 = (float)(result[1].z
                          + (float)((float)(result[2].z * (float)((float)((float)time - (float)y) / result->z))
                                  * (float)(result->z * (float)0.001)));
              v42 = (float)(result[3].y * (float)v37);
              v43 = (float)(result[3].z * (float)v37);
              v44 = (float)(result[3].x * (float)v37);
              result[4].x = (float)v38 + (float)(result[2].w * (float)v37);
              result[4].z = (float)v40 + (float)v42;
              result[4].w = (float)v41 + (float)v43;
              result[4].y = (float)v39 + (float)v44;
              goto LABEL_28;
            }
            break;
          case 1:
            x = result[1].x;
            v30 = result[1].y;
            v31 = result[1].z;
            v32 = (float)(result[1].w * (float)((float)((float)time - (float)y) * (float)0.001));
            v33 = (float)(result[2].x * (float)((float)((float)time - (float)y) * (float)0.001));
            v35 = (float)(result[2].z * (float)((float)((float)time - (float)y) * (float)0.001));
            v34 = (float)(result[2].y * (float)((float)((float)time - (float)y) * (float)0.001));
            result[4].x = result->w + (float)v32;
            result[4].y = (float)x + (float)v33;
            result[4].z = (float)v30 + (float)v34;
            result[4].w = (float)v31 + (float)v35;
            goto LABEL_28;
          case 2:
            v22 = (float)((float)((float)time - (float)y) * (float)0.001);
            v24 = result[1].y;
            v25 = result[1].z;
            v26 = (float)((float)(result[1].w + result[2].w) * (float)((float)((float)time - (float)y) * (float)0.001));
            v27 = (float)((float)(result[2].y + result[3].y) * (float)((float)((float)time - (float)y) * (float)0.001));
            v28 = (float)((float)(result[2].z + result[3].z) * (float)((float)((float)time - (float)y) * (float)0.001));
            w = result->w;
            result[4].y = result[1].x + (float)((float)(result[2].x + result[3].x) * (float)v22);
            result[4].x = (float)w + (float)v26;
            result[4].z = (float)v24 + (float)v27;
            result[4].w = (float)v25 + (float)v28;
            goto LABEL_28;
          case 4:
            if ( z != 0.0 )
            {
              v13 = (float)((float)((float)time - (float)y) / result->z);
              v14 = (float)((float)((float)((float)v13 * (float)v13) * (float)0.5) * (float)(result->z * (float)0.001));
              v15 = (float)(result->w
                          + (float)((float)(result[1].w * (float)((float)((float)time - (float)y) / result->z))
                                  * (float)(result->z * (float)0.001)));
              v16 = (float)(result[1].x
                          + (float)((float)(result[2].x * (float)((float)((float)time - (float)y) / result->z))
                                  * (float)(result->z * (float)0.001)));
              v17 = (float)(result[1].y
                          + (float)((float)(result[2].y * (float)((float)((float)time - (float)y) / result->z))
                                  * (float)(result->z * (float)0.001)));
              v18 = (float)(result[1].z
                          + (float)((float)(result[2].z * (float)((float)((float)time - (float)y) / result->z))
                                  * (float)(result->z * (float)0.001)));
              v19 = (float)(result[3].y * (float)v14);
              v20 = (float)(result[3].z * (float)v14);
              v21 = (float)(result[3].x * (float)v14);
              result[4].x = (float)v15 + (float)(result[2].w * (float)v14);
              result[4].z = (float)v17 + (float)v19;
              result[4].w = (float)v18 + (float)v20;
              result[4].y = (float)v16 + (float)v21;
              goto LABEL_28;
            }
            break;
          default:
LABEL_28:
            v9 = result[4].w;
            v8 = result[4].z;
            v7 = result[4].y;
            v6 = result[4].x;
            goto LABEL_29;
        }
      }
      result[4] = *(idQuat *)&result->w;
      goto LABEL_28;
    }
  }
  v6 = result->w;
  v7 = result[1].x;
  v8 = result[1].y;
  v9 = result[1].z;
LABEL_29:
  this->startValue.x = v9;
  this->duration = v8;
  this->startTime = v7;
  *(float *)&this->extrapolationType = v6;
  return this;
}

