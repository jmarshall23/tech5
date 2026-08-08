
// ========================================================================
// ?GetCurrentValue@?$idInterpolate@M@@QBAMM@Z
// EA  : 0x82678288
// RVA : 0x00678288
// PDB : w:\tech5\shared\idlib\math\interpolate.h
// ========================================================================

float __fastcall idInterpolate<float>::GetCurrentValue(idInterpolate<float> *this, double time)
{
  double v2; // fp0
  double duration; // fp13
  double startValue; // fp0
  double currentValue; // fp1
  double endValue; // fp0

  v2 = (float)((float)time - this->startTime);
  if ( time == this->currentTime )
    goto LABEL_10;
  duration = this->duration;
  this->currentTime = time;
  if ( duration < 0.0 )
  {
    if ( v2 >= 0.0 )
      goto LABEL_4;
    if ( v2 <= duration )
    {
LABEL_6:
      endValue = this->endValue;
      this->currentValue = this->endValue;
      currentValue = endValue;
      return *((float *)&currentValue + 1);
    }
    goto LABEL_9;
  }
  if ( v2 > 0.0 )
  {
    if ( v2 >= duration )
      goto LABEL_6;
LABEL_9:
    this->currentValue = (float)((float)((float)(this->endValue - this->startValue) / (float)duration) * (float)v2)
                       + this->startValue;
LABEL_10:
    currentValue = this->currentValue;
    return *((float *)&currentValue + 1);
  }
LABEL_4:
  startValue = this->startValue;
  this->currentValue = this->startValue;
  currentValue = startValue;
  return *((float *)&currentValue + 1);
}


// ========================================================================
// ?Init@?$idInterpolateAccelDecelLinear@M@@QAAXMMMMABM0@Z
// EA  : 0x82748AD8
// RVA : 0x00748AD8
// PDB : w:\tech5\shared\idlib\math\interpolate.h
// ========================================================================

void __fastcall idInterpolateAccelDecelLinear<float>::Init(
        idInterpolateAccelDecelLinear<float> *this,
        double startTime,
        double accelTime,
        double decelTime,
        double duration,
        const float *startValue,
        const float *endValue,
        int a8,
        int a9,
        float *a10,
        float *a11)
{
  double v11; // fp0
  double v12; // fp12
  double v13; // fp8
  double v14; // fp13
  double v15; // fp10
  extrapolation_t v16; // r11

  this->startTime = startTime;
  this->accelTime = accelTime;
  v11 = accelTime;
  this->decelTime = decelTime;
  this->startValue = *a10;
  this->endValue = *a11;
  if ( duration > 0.0 )
  {
    if ( (float)((float)accelTime + (float)decelTime) > duration )
    {
      v11 = (float)((float)((float)accelTime * (float)duration) / (float)((float)accelTime + (float)decelTime));
      this->accelTime = (float)((float)accelTime * (float)duration) / (float)((float)accelTime + (float)decelTime);
      this->decelTime = (float)duration
                      - (float)((float)((float)accelTime * (float)duration)
                              / (float)((float)accelTime + (float)decelTime));
    }
    v12 = this->decelTime;
    v13 = (float)((float)v11 + this->decelTime);
    v14 = (float)((float)((float)duration - (float)v11) - this->decelTime);
    this->linearTime = (float)((float)duration - (float)v11) - this->decelTime;
    v15 = (float)((float)((float)1000.0 / (float)((float)((float)v13 * (float)0.5) + (float)v14)) * (float)(*a11 - *a10));
    if ( v11 == 0.0 )
    {
      if ( v14 == 0.0 )
      {
        this->extrapolate.duration = v12;
        v16 = EXTRAPOLATION_DECELLINEAR;
      }
      else
      {
        this->extrapolate.duration = v14;
        v16 = EXTRAPOLATION_LINEAR;
      }
    }
    else
    {
      this->extrapolate.duration = v11;
      v16 = EXTRAPOLATION_ACCELLINEAR;
    }
    this->extrapolate.startTime = startTime;
    this->extrapolate.extrapolationType = v16;
    this->extrapolate.startValue = *a10;
    this->extrapolate.baseSpeed = 0.0;
    this->extrapolate.speed = v15;
    this->extrapolate.currentTime = -1.0;
    this->extrapolate.currentValue = *a10;
  }
  else
  {
    this->linearTime = 0.0;
  }
}


// ========================================================================
// ?SetPhase@?$idInterpolateAccelDecelLinear@M@@ABAXM@Z
// EA  : 0x82748BD0
// RVA : 0x00748BD0
// PDB : w:\tech5\shared\idlib\math\interpolate.h
// ========================================================================

void __fastcall idInterpolateAccelDecelLinear<float>::SetPhase(idInterpolateAccelDecelLinear<float> *this, double time)
{
  double startTime; // fp13
  extrapolation_t extrapolationType; // r11
  double v4; // fp11
  double accelTime; // fp12
  double linearTime; // fp0
  double v7; // fp12
  double v8; // fp12
  double v9; // fp11
  double startValue; // fp10
  double decelTime; // fp11
  double endValue; // fp10
  double speed; // fp8

  startTime = this->startTime;
  extrapolationType = this->extrapolate.extrapolationType;
  v4 = (float)((float)time - this->startTime);
  accelTime = this->accelTime;
  if ( v4 >= accelTime )
  {
    linearTime = this->linearTime;
    v7 = (float)(this->linearTime + this->accelTime);
    if ( v4 >= v7 )
    {
      if ( extrapolationType != EXTRAPOLATION_DECELLINEAR )
      {
        decelTime = this->decelTime;
        endValue = this->endValue;
        speed = this->extrapolate.speed;
        this->extrapolate.extrapolationType = EXTRAPOLATION_DECELLINEAR;
        this->extrapolate.startTime = (float)v7 + (float)startTime;
        this->extrapolate.duration = decelTime;
        this->extrapolate.startValue = -(float)((float)((float)((float)decelTime * (float)0.00050000002) * (float)speed)
                                              - (float)endValue);
        this->extrapolate.baseSpeed = this->extrapolate.baseSpeed;
        this->extrapolate.speed = this->extrapolate.speed;
        this->extrapolate.currentValue = -(float)((float)((float)((float)decelTime * (float)0.00050000002) * (float)speed)
                                                - (float)endValue);
        this->extrapolate.currentTime = -1.0;
      }
    }
    else if ( extrapolationType != EXTRAPOLATION_LINEAR )
    {
      v8 = this->accelTime;
      v9 = this->extrapolate.speed;
      startValue = this->startValue;
      this->extrapolate.extrapolationType = EXTRAPOLATION_LINEAR;
      this->extrapolate.duration = linearTime;
      this->extrapolate.startTime = (float)v8 + (float)startTime;
      this->extrapolate.startValue = (float)((float)((float)v8 * (float)0.00050000002) * (float)v9) + (float)startValue;
      this->extrapolate.baseSpeed = this->extrapolate.baseSpeed;
      this->extrapolate.speed = this->extrapolate.speed;
      this->extrapolate.currentValue = (float)((float)((float)v8 * (float)0.00050000002) * (float)v9)
                                     + (float)startValue;
      this->extrapolate.currentTime = -1.0;
    }
  }
  else if ( extrapolationType != EXTRAPOLATION_ACCELLINEAR )
  {
    this->extrapolate.startTime = this->startTime;
    this->extrapolate.duration = accelTime;
    this->extrapolate.extrapolationType = EXTRAPOLATION_ACCELLINEAR;
    this->extrapolate.startValue = this->startValue;
    this->extrapolate.baseSpeed = this->extrapolate.baseSpeed;
    this->extrapolate.speed = this->extrapolate.speed;
    this->extrapolate.currentTime = -1.0;
    this->extrapolate.currentValue = this->startValue;
  }
}


// ========================================================================
// ?Init@?$idInterpolateAccelDecelLinear@VidAngles@@@@QAAXMMMMABVidAngles@@0@Z
// EA  : 0x8274A508
// RVA : 0x0074A508
// PDB : w:\tech5\shared\idlib\math\interpolate.h
// ========================================================================

void __fastcall idInterpolateAccelDecelLinear<idAngles>::Init(
        idInterpolateAccelDecelLinear<idAngles> *this,
        double startTime,
        double accelTime,
        double decelTime,
        double duration,
        const idAngles *startValue,
        const idAngles *endValue,
        int a8,
        int a9,
        idAngles *a10,
        idAngles *a11)
{
  double v11; // fp12
  double v12; // fp13
  double v13; // fp11
  double v14; // fp8
  double v15; // fp7
  double v16; // fp5
  double v17; // fp10
  double roll; // fp2
  double v19; // fp8
  double v20; // fp4
  double v21; // fp10
  double v22; // fp9
  double v23; // fp8
  extrapolation_t v24; // r11

  this->startTime = startTime;
  this->accelTime = accelTime;
  this->decelTime = decelTime;
  this->startValue = *a10;
  this->endValue = *a11;
  if ( duration > 0.0 )
  {
    if ( (float)(this->decelTime + this->accelTime) > duration )
    {
      v11 = (float)((float)(this->accelTime * (float)duration) / (float)(this->decelTime + this->accelTime));
      this->accelTime = (float)(this->accelTime * (float)duration) / (float)(this->decelTime + this->accelTime);
      this->decelTime = (float)duration - (float)v11;
    }
    v12 = this->decelTime;
    v13 = this->accelTime;
    v14 = (float)(this->decelTime + this->accelTime);
    v15 = (float)((float)((float)duration - this->accelTime) - this->decelTime);
    this->linearTime = (float)((float)duration - this->accelTime) - this->decelTime;
    v16 = (float)(a11->yaw - a10->yaw);
    v17 = (float)((float)((float)v14 * (float)0.5) + (float)v15);
    roll = a10->roll;
    v19 = a11->roll;
    v20 = (float)(a11->pitch - a10->pitch);
    this->extrapolate.startTime = startTime;
    v22 = (float)((float)v20 * (float)((float)1000.0 / (float)v17));
    v23 = (float)((float)((float)v19 - (float)roll) * (float)((float)1000.0 / (float)v17));
    v21 = (float)((float)v16 * (float)((float)1000.0 / (float)v17));
    if ( v13 == 0.0 )
    {
      if ( v15 == 0.0 )
      {
        this->extrapolate.duration = v12;
        v24 = EXTRAPOLATION_DECELLINEAR;
      }
      else
      {
        this->extrapolate.duration = v15;
        v24 = EXTRAPOLATION_LINEAR;
      }
      this->extrapolate.extrapolationType = v24;
      this->extrapolate.startValue = *a10;
      this->extrapolate.baseSpeed.pitch = 0.0;
      this->extrapolate.baseSpeed.yaw = 0.0;
      this->extrapolate.baseSpeed.roll = 0.0;
      this->extrapolate.speed.pitch = v22;
      this->extrapolate.speed.yaw = v21;
      this->extrapolate.speed.roll = v23;
      this->extrapolate.currentTime = -1082130432;
      this->extrapolate.currentValue = *a10;
    }
    else
    {
      this->extrapolate.duration = v13;
      this->extrapolate.extrapolationType = EXTRAPOLATION_ACCELLINEAR;
      this->extrapolate.startValue = *a10;
      this->extrapolate.baseSpeed.pitch = 0.0;
      this->extrapolate.baseSpeed.yaw = 0.0;
      this->extrapolate.baseSpeed.roll = 0.0;
      this->extrapolate.speed.pitch = v22;
      this->extrapolate.speed.yaw = v21;
      this->extrapolate.speed.roll = v23;
      this->extrapolate.currentTime = -1082130432;
      this->extrapolate.currentValue = *a10;
    }
  }
  else
  {
    this->linearTime = 0.0;
  }
}


// ========================================================================
// ?GetCurrentValue@?$idInterpolate@VidVec3@@@@QBA?AVidVec3@@M@Z
// EA  : 0x8274A6D8
// RVA : 0x0074A6D8
// PDB : w:\tech5\shared\idlib\math\interpolate.h
// ========================================================================

idInterpolate<idVec3> *__fastcall idInterpolate<idVec3>::GetCurrentValue(
        idInterpolate<idVec3> *this,
        idVec3 *result,
        double time)
{
  double v3; // fp0
  double y; // fp13
  double v5; // fp11
  double v6; // fp12
  double v7; // fp5
  double v8; // fp4
  float x; // r11
  float v10; // r10
  float z; // r9
  float v13; // [sp+4h] [-1Ch]
  float v14; // [sp+8h] [-18h]
  float v15; // [sp+8h] [-18h]
  float back_chain; // [sp+14h] [-Ch]
  float v17; // [sp+18h] [-8h]

  v3 = (float)((float)time - result->x);
  if ( time != result[2].z )
  {
    y = result->y;
    result[2].z = time;
    if ( y < 0.0 )
    {
      if ( v3 < 0.0 )
      {
        if ( v3 > y )
        {
          v5 = (float)((float)v3 / (float)y);
          x = result[2].x;
          back_chain = result[1].x;
          v15 = result[2].y;
          v17 = result[1].y;
          result[3].x = (float)((float)(result[1].z - result->z) * (float)((float)v3 / (float)y)) + result->z;
          v6 = v17;
          result[3].y = (float)((float)(x - back_chain) * (float)((float)v3 / (float)y)) + back_chain;
          v7 = (float)(v15 - v17);
          goto LABEL_11;
        }
        goto LABEL_9;
      }
    }
    else if ( v3 > 0.0 )
    {
      if ( v3 < y )
      {
        v5 = (float)((float)v3 / (float)y);
        v13 = result[1].x;
        v14 = result[1].y;
        v6 = v14;
        v7 = (float)(result[2].y - v14);
        v8 = (float)((float)(result[2].x - v13) * (float)((float)v3 / (float)y));
        result[3].x = (float)((float)(result[1].z - result->z) * (float)((float)v3 / (float)y)) + result->z;
        result[3].y = (float)v8 + v13;
LABEL_11:
        result[3].z = (float)((float)v7 * (float)v5) + (float)v6;
        goto LABEL_12;
      }
LABEL_9:
      result[3] = *(idVec3 *)((char *)result + 20);
      goto LABEL_12;
    }
    result[3] = *(idVec3 *)&result->z;
  }
LABEL_12:
  v10 = result[3].y;
  z = result[3].z;
  this->startTime = result[3].x;
  this->duration = v10;
  this->startValue.x = z;
  return this;
}


// ========================================================================
// ?InitDuration@?$idInterpolateAccelLinearEx@M@@QAAXMMMABM0@Z
// EA  : 0x8274A868
// RVA : 0x0074A868
// PDB : w:\tech5\shared\idlib\math\interpolate.h
// ========================================================================

void __fastcall idInterpolateAccelLinearEx<float>::InitDuration(
        idInterpolateAccelLinearEx<float> *this,
        double startTime,
        double startSpeed,
        double duration,
        const float *startValue,
        const float *endValue,
        int a7,
        float *a8,
        float *a9)
{
  double endSpeed; // fp0

  this->startTime = startTime;
  this->startSpeed = startSpeed;
  this->startValue = *a8;
  this->endValue = *a9;
  this->duration = duration;
  if ( duration > 0.0 )
    this->endSpeed = (float)((float)((float)((float)((float)((float)0.001 * (float)duration) * (float)startSpeed)
                                           + (float)(*a8 - *a9))
                                   / (float)((float)0.001 * (float)duration))
                           * (float)-2.0)
                   + (float)startSpeed;
  else
    this->endSpeed = startSpeed;
  endSpeed = this->endSpeed;
  this->extrapolate.startTime = startTime;
  this->extrapolate.duration = duration;
  this->extrapolate.extrapolationType = EXTRAPOLATION_ACCELLINEAR;
  this->extrapolate.startValue = this->startValue;
  this->extrapolate.baseSpeed = this->startSpeed;
  this->extrapolate.speed = (float)endSpeed - (float)startSpeed;
  this->extrapolate.currentTime = -1.0;
  this->extrapolate.currentValue = this->startValue;
}


// ========================================================================
// ?GetCurrentValue@?$idInterpolateAccelLinearEx@M@@QBAMM@Z
// EA  : 0x8274A910
// RVA : 0x0074A910
// PDB : w:\tech5\shared\idlib\math\interpolate.h
// ========================================================================

double __fastcall idInterpolateAccelLinearEx<float>::GetCurrentValue(
        idInterpolateAccelLinearEx<float> *this,
        double time)
{
  if ( time < (float)(this->duration + this->startTime) )
    return idExtrapolate<float>::GetCurrentValue(this: &this->extrapolate, time);
  if ( this->startSpeed == this->endSpeed )
    return this->endValue;
  return (float)((float)((float)((float)((float)time - (float)(this->duration + this->startTime)) * this->endSpeed)
                       * (float)0.001)
               + this->endValue);
}


// ========================================================================
// ?SetPhase@?$idInterpolateAccelDecelLinear@VidVec3@@@@ABAXM@Z
// EA  : 0x8274B0F8
// RVA : 0x0074B0F8
// PDB : w:\tech5\shared\idlib\math\interpolate.h
// ========================================================================

void __fastcall idInterpolateAccelDecelLinear<idVec3>::SetPhase(
        idInterpolateAccelDecelLinear<idAngles> *this,
        double time)
{
  double startTime; // fp13
  double v3; // fp11
  double accelTime; // fp12
  double linearTime; // fp0
  extrapolation_t extrapolationType; // r10
  double v7; // fp12
  idExtrapolate<idAngles> *p_extrapolate; // r11
  double v9; // fp11
  double v10; // fp10
  double v11; // fp9
  double v12; // fp8
  double v13; // fp7
  double v14; // fp6
  double v15; // fp5
  double v16; // fp4
  double decelTime; // fp11
  double pitch; // fp10
  double v19; // fp9
  double yaw; // fp7
  double roll; // fp6
  double v22; // fp5
  double v23; // fp4
  double v24; // fp3

  startTime = this->startTime;
  v3 = (float)((float)time - this->startTime);
  accelTime = this->accelTime;
  if ( v3 >= accelTime )
  {
    linearTime = this->linearTime;
    extrapolationType = this->extrapolate.extrapolationType;
    v7 = (float)(this->linearTime + this->accelTime);
    p_extrapolate = &this->extrapolate;
    if ( v3 >= v7 )
    {
      if ( extrapolationType != EXTRAPOLATION_DECELLINEAR )
      {
        decelTime = this->decelTime;
        pitch = this->extrapolate.speed.pitch;
        v19 = this->endValue.pitch;
        yaw = this->endValue.yaw;
        roll = this->endValue.roll;
        v22 = (float)(this->decelTime * (float)0.00050000002);
        v23 = this->extrapolate.speed.yaw;
        v24 = this->extrapolate.speed.roll;
        p_extrapolate->extrapolationType = EXTRAPOLATION_DECELLINEAR;
        this->extrapolate.duration = decelTime;
        this->extrapolate.startTime = (float)v7 + (float)startTime;
        this->extrapolate.startValue.pitch = (float)v19 - (float)((float)pitch * (float)v22);
        this->extrapolate.startValue.yaw = (float)yaw - (float)((float)v22 * (float)v23);
        this->extrapolate.startValue.roll = (float)roll - (float)((float)v24 * (float)v22);
        this->extrapolate.baseSpeed = this->extrapolate.baseSpeed;
        this->extrapolate.speed = this->extrapolate.speed;
        this->extrapolate.currentTime = -1.0;
        this->extrapolate.currentValue.pitch = (float)v19 - (float)((float)pitch * (float)v22);
        this->extrapolate.currentValue.yaw = (float)yaw - (float)((float)v22 * (float)v23);
        this->extrapolate.currentValue.roll = (float)roll - (float)((float)v24 * (float)v22);
      }
    }
    else if ( extrapolationType != EXTRAPOLATION_LINEAR )
    {
      v9 = (float)(this->accelTime + this->startTime);
      v10 = this->extrapolate.speed.pitch;
      v11 = this->extrapolate.speed.yaw;
      v12 = this->extrapolate.speed.roll;
      v13 = this->startValue.pitch;
      v14 = (float)(this->accelTime * (float)0.00050000002);
      v15 = this->startValue.yaw;
      v16 = this->startValue.roll;
      p_extrapolate->extrapolationType = EXTRAPOLATION_LINEAR;
      this->extrapolate.startTime = v9;
      this->extrapolate.duration = linearTime;
      this->extrapolate.startValue.pitch = (float)v13 + (float)((float)v10 * (float)v14);
      this->extrapolate.startValue.yaw = (float)v15 + (float)((float)v14 * (float)v11);
      this->extrapolate.startValue.roll = (float)v16 + (float)((float)v12 * (float)v14);
      this->extrapolate.baseSpeed = this->extrapolate.baseSpeed;
      this->extrapolate.speed = this->extrapolate.speed;
      this->extrapolate.currentTime = -1.0;
      this->extrapolate.currentValue.pitch = (float)v13 + (float)((float)v10 * (float)v14);
      this->extrapolate.currentValue.yaw = (float)v15 + (float)((float)v14 * (float)v11);
      this->extrapolate.currentValue.roll = (float)v16 + (float)((float)v12 * (float)v14);
    }
  }
  else if ( this->extrapolate.extrapolationType != EXTRAPOLATION_ACCELLINEAR )
  {
    this->extrapolate.startTime = this->startTime;
    this->extrapolate.duration = accelTime;
    this->extrapolate.extrapolationType = EXTRAPOLATION_ACCELLINEAR;
    this->extrapolate.startValue = this->startValue;
    this->extrapolate.baseSpeed = this->extrapolate.baseSpeed;
    this->extrapolate.speed = this->extrapolate.speed;
    this->extrapolate.currentTime = -1.0;
    this->extrapolate.currentValue = this->startValue;
  }
}


// ========================================================================
// ??0?$idInterpolateAccelDecelLinear@VidQuat@@@@QAA@XZ
// EA  : 0x8274B320
// RVA : 0x0074B320
// PDB : w:\tech5\shared\idlib\math\interpolate.h
// ========================================================================

idInterpolateAccelDecelLinear<idQuat> *__fastcall idInterpolateAccelDecelLinear<idQuat>::idInterpolateAccelDecelLinear<idQuat>(
        idInterpolateAccelDecelLinear<idQuat> *this)
{
  this->extrapolate.extrapolationType = EXTRAPOLATION_NONE;
  this->extrapolate.duration = 0.0;
  this->extrapolate.startTime = 0.0;
  this->extrapolate.startValue.x = 0.0;
  this->extrapolate.startValue.y = 0.0;
  this->extrapolate.startValue.z = 0.0;
  this->extrapolate.startValue.w = 0.0;
  this->extrapolate.baseSpeed.x = 0.0;
  this->extrapolate.baseSpeed.y = 0.0;
  this->extrapolate.baseSpeed.z = 0.0;
  this->extrapolate.baseSpeed.w = 0.0;
  this->extrapolate.speed.x = 0.0;
  this->extrapolate.speed.y = 0.0;
  this->extrapolate.speed.z = 0.0;
  this->extrapolate.speed.w = 0.0;
  this->extrapolate.currentTime = -1.0;
  this->extrapolate.currentValue = this->extrapolate.startValue;
  this->decelTime = 0.0;
  this->linearTime = 0.0;
  this->accelTime = 0.0;
  this->startTime = 0.0;
  this->startValue.x = 0.0;
  this->startValue.y = 0.0;
  this->startValue.z = 0.0;
  this->startValue.w = 0.0;
  this->endValue = this->startValue;
  return this;
}


// ========================================================================
// ?SetStartValue@?$idInterpolateAccelDecelLinear@VidVec3@@@@QAAXABVidVec3@@@Z
// EA  : 0x8274D380
// RVA : 0x0074D380
// PDB : w:\tech5\shared\idlib\math\interpolate.h
// ========================================================================

void __fastcall idInterpolateAccelDecelLinear<idVec3>::SetStartValue(
        idInterpolateAccelDecelLinear<idAngles> *this,
        const idAngles *startValue)
{
  this->startValue = *startValue;
  this->extrapolate.extrapolationType = EXTRAPOLATION_NONE;
  this->extrapolate.startTime = 0.0;
  this->extrapolate.duration = 0.0;
  this->extrapolate.startValue = this->extrapolate.startValue;
  this->extrapolate.baseSpeed = this->extrapolate.baseSpeed;
  this->extrapolate.speed = this->extrapolate.speed;
  this->extrapolate.currentTime = -1.0;
  this->extrapolate.currentValue = this->extrapolate.startValue;
}


// ========================================================================
// ?GetCurrentValue@?$idInterpolateAccelDecelLinear@VidVec3@@@@QBA?AVidVec3@@M@Z
// EA  : 0x8274D428
// RVA : 0x0074D428
// PDB : w:\tech5\shared\idlib\math\interpolate.h
// ========================================================================

idInterpolateAccelDecelLinear<idVec3> *__fastcall idInterpolateAccelDecelLinear<idVec3>::GetCurrentValue(
        idInterpolateAccelDecelLinear<idVec3> *this,
        idInterpolateAccelDecelLinear<idAngles> *result,
        double time)
{
  idInterpolateAccelDecelLinear<idVec3>::SetPhase(this: result, time);
  idExtrapolate<idAngles>::GetCurrentValue(
    (idExtrapolate<idAngles> *)this,
    result: (idAngles *)&result->extrapolate,
    time);
  return this;
}


// ========================================================================
// ?GetCurrentSpeed@?$idInterpolateAccelDecelLinear@VidVec3@@@@QBA?AVidVec3@@M@Z
// EA  : 0x8274D488
// RVA : 0x0074D488
// PDB : w:\tech5\shared\idlib\math\interpolate.h
// ========================================================================

idInterpolateAccelDecelLinear<idVec3> *__fastcall idInterpolateAccelDecelLinear<idVec3>::GetCurrentSpeed(
        idInterpolateAccelDecelLinear<idVec3> *this,
        idInterpolateAccelDecelLinear<idAngles> *result,
        double time)
{
  idInterpolateAccelDecelLinear<idVec3>::SetPhase(this: result, time);
  idExtrapolate<idVec3>::GetCurrentSpeed(
    (idExtrapolate<idAngles> *)this,
    result: (idAngles *)&result->extrapolate,
    time);
  return this;
}


// ========================================================================
// ?Init@?$idInterpolateAccelDecelLinear@VidQuat@@@@QAAXMMMMABVidQuat@@0@Z
// EA  : 0x8274D4E8
// RVA : 0x0074D4E8
// PDB : w:\tech5\shared\idlib\math\interpolate.h
// ========================================================================

void __fastcall idInterpolateAccelDecelLinear<idQuat>::Init(
        idInterpolateAccelDecelLinear<idQuat> *this,
        double startTime,
        double accelTime,
        double decelTime,
        double duration,
        const idQuat *startValue,
        const idQuat *endValue,
        int a8,
        int a9,
        const idQuat *a10,
        idQuat *a11)
{
  double v11; // fp12
  double v12; // fp13
  double v13; // fp9
  double v14; // fp2
  double linearTime; // fp12
  double v16; // fp11
  double v17; // fp3
  double v18; // fp10
  double v19; // fp8
  extrapolation_t v20; // r9
  idQuat v21; // [sp+50h] [-30h] BYREF
  idQuat v22; // [sp+60h] [-20h] BYREF

  this->startTime = startTime;
  this->accelTime = accelTime;
  this->decelTime = decelTime;
  this->startValue = *a10;
  this->endValue = *a11;
  if ( duration > 0.0 )
  {
    if ( (float)(this->decelTime + this->accelTime) > duration )
    {
      v11 = (float)((float)(this->accelTime * (float)duration) / (float)(this->decelTime + this->accelTime));
      this->accelTime = (float)(this->accelTime * (float)duration) / (float)(this->decelTime + this->accelTime);
      this->decelTime = (float)duration - (float)v11;
    }
    v12 = this->decelTime;
    v13 = (float)(this->decelTime + this->accelTime);
    v14 = this->accelTime;
    this->linearTime = (float)((float)duration - this->accelTime) - this->decelTime;
    linearTime = this->linearTime;
    v16 = (float)((float)1000.0 / (float)((float)((float)v13 * (float)0.5) + this->linearTime));
    v17 = (float)(a11->x - a10->x);
    v18 = (float)(a11->z - a10->z);
    v19 = (float)((float)(a11->y - a10->y)
                * (float)((float)1000.0 / (float)((float)((float)v13 * (float)0.5) + this->linearTime)));
    v21.w = (float)(a11->w - a10->w)
          * (float)((float)1000.0 / (float)((float)((float)v13 * (float)0.5) + this->linearTime));
    v21.y = v19;
    v21.x = (float)v17 * (float)v16;
    v21.z = (float)v18 * (float)v16;
    if ( v14 == 0.0 )
    {
      if ( linearTime == 0.0 )
      {
        v20 = EXTRAPOLATION_DECELLINEAR;
        v14 = v12;
      }
      else
      {
        v20 = EXTRAPOLATION_LINEAR;
        v14 = linearTime;
      }
    }
    else
    {
      v20 = EXTRAPOLATION_ACCELLINEAR;
    }
    v22.x = 0.0;
    v22.y = 0.0;
    v22.z = 0.0;
    v22.w = 0.0;
    idExtrapolate<idQuat>::Init(
      this: &this->extrapolate,
      startTime,
      duration: v14,
      startValue,
      baseSpeed: endValue,
      speed: a10,
      extrapolationType: &v22,
      a8: &v21,
      a9: v20);
  }
  else
  {
    this->linearTime = 0.0;
  }
}


// ========================================================================
// ?Invalidate@?$idInterpolateAccelDecelLinear@VidQuat@@@@AAAXXZ
// EA  : 0x8274D678
// RVA : 0x0074D678
// PDB : w:\tech5\shared\idlib\math\interpolate.h
// ========================================================================

void __fastcall idInterpolateAccelDecelLinear<idQuat>::Invalidate(idInterpolateAccelDecelLinear<idQuat> *this)
{
  this->extrapolate.extrapolationType = EXTRAPOLATION_NONE;
  this->extrapolate.startTime = 0.0;
  this->extrapolate.duration = 0.0;
  this->extrapolate.startValue = this->extrapolate.startValue;
  this->extrapolate.baseSpeed = this->extrapolate.baseSpeed;
  this->extrapolate.speed = this->extrapolate.speed;
  this->extrapolate.currentTime = -1.0;
  this->extrapolate.currentValue = this->extrapolate.startValue;
}


// ========================================================================
// ?GetCurrentValue@?$idInterpolate@VidQuat@@@@QBA?AVidQuat@@M@Z
// EA  : 0x8274D818
// RVA : 0x0074D818
// PDB : w:\tech5\shared\idlib\math\interpolate.h
// ========================================================================

idInterpolate<idQuat> *__fastcall idInterpolate<idQuat>::GetCurrentValue(
        idInterpolate<idQuat> *this,
        idQuat *result,
        double time)
{
  double v3; // fp0
  double y; // fp13
  double v5; // fp10
  double v6; // fp11
  double v7; // fp2
  float w; // r5
  float v9; // r9
  float v10; // r8
  float v11; // r7
  float back_chain; // [sp+0h] [-40h]
  float back_chaina; // [sp+0h] [-40h]
  float x; // [sp+8h] [-38h]
  float v16; // [sp+Ch] [-34h]
  float v17; // [sp+10h] [-30h]
  float z; // [sp+10h] [-30h]
  float v19; // [sp+14h] [-2Ch]
  float v20; // [sp+18h] [-28h]
  float v21; // [sp+1Ch] [-24h]

  v3 = (float)((float)time - result->x);
  if ( time != result[2].z )
  {
    y = result->y;
    result[2].z = time;
    if ( y < 0.0 )
    {
      if ( v3 < 0.0 )
      {
        if ( v3 > y )
        {
          w = result->w;
          v5 = (float)((float)v3 / (float)y);
          back_chaina = result->z;
          z = result[1].z;
          v19 = result[1].w;
          v16 = result[1].y;
          v6 = v16;
          v7 = (float)(result[2].y - v16);
          result[3].y = (float)((float)(result[2].x - result[1].x) * (float)((float)v3 / (float)y)) + result[1].x;
          result[3].x = (float)((float)(v19 - w) * (float)((float)v3 / (float)y)) + w;
          result[2].w = (float)((float)(z - back_chaina) * (float)((float)v3 / (float)y)) + back_chaina;
          goto LABEL_11;
        }
        goto LABEL_9;
      }
    }
    else if ( v3 > 0.0 )
    {
      if ( v3 < y )
      {
        v5 = (float)((float)v3 / (float)y);
        back_chain = result[1].z;
        x = result[2].x;
        v17 = result->z;
        v20 = result[1].x;
        v21 = result[1].y;
        v6 = v21;
        v7 = (float)(result[2].y - v21);
        result[3].x = (float)((float)(result[1].w - result->w) * (float)((float)v3 / (float)y)) + result->w;
        result[2].w = (float)((float)(back_chain - v17) * (float)((float)v3 / (float)y)) + v17;
        result[3].y = (float)((float)(x - v20) * (float)((float)v3 / (float)y)) + v20;
LABEL_11:
        result[3].z = (float)((float)v7 * (float)v5) + (float)v6;
        goto LABEL_12;
      }
LABEL_9:
      result[2].w = result[1].z;
      result[3].x = result[1].w;
      result[3].y = result[2].x;
      result[3].z = result[2].y;
      goto LABEL_12;
    }
    result[2].w = result->z;
    result[3].x = result->w;
    result[3].y = result[1].x;
    result[3].z = result[1].y;
  }
LABEL_12:
  v9 = result[3].x;
  v10 = result[3].y;
  v11 = result[3].z;
  this->startTime = result[2].w;
  this->duration = v9;
  this->startValue.x = v10;
  this->startValue.y = v11;
  return this;
}


// ========================================================================
// ?SetPhase@?$idInterpolateAccelDecelLinear@VidQuat@@@@ABAXM@Z
// EA  : 0x8274DA38
// RVA : 0x0074DA38
// PDB : w:\tech5\shared\idlib\math\interpolate.h
// ========================================================================

void __fastcall idInterpolateAccelDecelLinear<idQuat>::SetPhase(
        idInterpolateAccelDecelLinear<idQuat> *this,
        double time,
        const idQuat *a3,
        const idQuat *a4)
{
  double startTime; // fp13
  extrapolation_t extrapolationType; // r10
  double v6; // fp12
  double accelTime; // fp0
  idExtrapolate<idQuat> *p_extrapolate; // r3
  double linearTime; // fp2
  idQuat *p_startValue; // r6
  double v12; // fp1
  extrapolation_t v13; // r9
  double v14; // fp0
  double v15; // fp10
  double v16; // fp9
  double v17; // fp8
  double v18; // fp7
  float v19[6]; // [sp+50h] [-20h] BYREF

  startTime = this->startTime;
  extrapolationType = this->extrapolate.extrapolationType;
  v6 = (float)((float)time - this->startTime);
  accelTime = this->accelTime;
  p_extrapolate = &this->extrapolate;
  if ( v6 >= accelTime )
  {
    linearTime = this->linearTime;
    v14 = (float)(this->linearTime + (float)accelTime);
    if ( v6 >= v14 )
    {
      if ( extrapolationType == EXTRAPOLATION_DECELLINEAR )
        return;
      linearTime = this->decelTime;
      v12 = (float)((float)v14 + (float)startTime);
      v13 = EXTRAPOLATION_DECELLINEAR;
      v15 = (float)(this->endValue.x
                  - (float)(this->extrapolate.speed.x * (float)(this->decelTime * (float)0.00050000002)));
      v16 = (float)(this->endValue.y
                  - (float)(this->extrapolate.speed.y * (float)(this->decelTime * (float)0.00050000002)));
      v17 = (float)(this->endValue.z
                  - (float)(this->extrapolate.speed.z * (float)(this->decelTime * (float)0.00050000002)));
      v18 = (float)(this->endValue.w
                  - (float)(this->extrapolate.speed.w * (float)(this->decelTime * (float)0.00050000002)));
    }
    else
    {
      if ( extrapolationType == EXTRAPOLATION_LINEAR )
        return;
      v12 = (float)(this->accelTime + (float)startTime);
      v13 = EXTRAPOLATION_LINEAR;
      v15 = (float)(this->startValue.x
                  + (float)(this->extrapolate.speed.x * (float)(this->accelTime * (float)0.00050000002)));
      v16 = (float)(this->startValue.y
                  + (float)(this->extrapolate.speed.y * (float)(this->accelTime * (float)0.00050000002)));
      v17 = (float)(this->startValue.z
                  + (float)(this->extrapolate.speed.z * (float)(this->accelTime * (float)0.00050000002)));
      v18 = (float)(this->startValue.w
                  + (float)(this->extrapolate.speed.w * (float)(this->accelTime * (float)0.00050000002)));
    }
    v19[3] = v18;
    p_startValue = (idQuat *)v19;
    v19[2] = v17;
    v19[1] = v16;
    v19[0] = v15;
  }
  else
  {
    if ( extrapolationType == EXTRAPOLATION_ACCELLINEAR )
      return;
    linearTime = accelTime;
    p_startValue = &this->startValue;
    v12 = startTime;
    v13 = EXTRAPOLATION_ACCELLINEAR;
  }
  idExtrapolate<idQuat>::Init(
    this: p_extrapolate,
    startTime: v12,
    duration: linearTime,
    startValue: a3,
    baseSpeed: a4,
    speed: p_startValue,
    extrapolationType: &this->extrapolate.baseSpeed,
    a8: &this->extrapolate.speed,
    a9: v13);
}


// ========================================================================
// ?GetCurrentValue@?$idInterpolateAccelDecelLinear@VidQuat@@@@QBA?AVidQuat@@M@Z
// EA  : 0x82750360
// RVA : 0x00750360
// PDB : w:\tech5\shared\idlib\math\interpolate.h
// ========================================================================

idInterpolateAccelDecelLinear<idQuat> *__fastcall idInterpolateAccelDecelLinear<idQuat>::GetCurrentValue(
        idInterpolateAccelDecelLinear<idQuat> *this,
        idQuat *result,
        double time,
        const idQuat *a4)
{
  idInterpolateAccelDecelLinear<idQuat>::SetPhase(
    this: (idInterpolateAccelDecelLinear<idQuat> *)result,
    time,
    a3: result,
    a4);
  idExtrapolate<idQuat>::GetCurrentValue((idExtrapolate<idQuat> *)this, result: result + 3, time);
  return this;
}


// ========================================================================
// ?InitEndSpeed@?$idInterpolateAccelLinearEx@M@@QAAMMMMABM0@Z
// EA  : 0x827503C0
// RVA : 0x007503C0
// PDB : w:\tech5\shared\idlib\math\interpolate.h
// ========================================================================

float __fastcall idInterpolateAccelLinearEx<float>::InitEndSpeed(
        idInterpolateAccelLinearEx<float> *this,
        double startTime,
        double startSpeed,
        double endSpeed,
        const float *startValue,
        const float *endValue,
        int a7,
        float *a8,
        __int64 a9)
{
  double v9; // fp0
  double duration; // fp1

  this->startTime = startTime;
  this->startSpeed = startSpeed;
  this->startValue = *a8;
  v9 = 0.0;
  this->endSpeed = endSpeed;
  this->endValue = *(float *)HIDWORD(a9);
  if ( (float)((float)((float)startSpeed * (float)2.0) + (float)((float)endSpeed - (float)startSpeed)) != 0.0 )
  {
    LODWORD(a9) = (int)(float)((float)((float)((float)(*(float *)HIDWORD(a9) - this->startValue)
                                             / (float)((float)((float)startSpeed * (float)2.0)
                                                     + (float)((float)endSpeed - (float)startSpeed)))
                                     * (float)1000.0)
                             * (float)2.0);
    v9 = (float)a9;
  }
  this->duration = v9;
  this->extrapolate.duration = v9;
  this->extrapolate.startTime = startTime;
  this->extrapolate.extrapolationType = EXTRAPOLATION_ACCELLINEAR;
  this->extrapolate.startValue = this->startValue;
  this->extrapolate.baseSpeed = this->startSpeed;
  this->extrapolate.speed = (float)endSpeed - (float)startSpeed;
  this->extrapolate.currentTime = -1.0;
  this->extrapolate.currentValue = this->startValue;
  duration = this->duration;
  return *((float *)&duration + 1);
}


// ========================================================================
// ?GetCurrentValueEaseOut@?$idInterpolate@M@@QBAMM@Z
// EA  : 0x82B770A8
// RVA : 0x00B770A8
// PDB : w:\tech5\shared\idlib\math\interpolate.h
// ========================================================================

// local variable allocation has failed, the output may be wrong!
float __fastcall idInterpolate<float>::GetCurrentValueEaseOut(idInterpolate<float> *this, double time)
{
  double v3; // fp0
  double duration; // fp13
  long double v5; // fp2
  long double v6; // fp2
  double v7; // fp8
  double currentValue; // fp1

  v3 = (float)((float)time - this->startTime);
  if ( time != this->currentTime )
  {
    duration = this->duration;
    this->currentTime = time;
    if ( duration < 0.0 )
    {
      if ( v3 >= 0.0 )
        goto LABEL_4;
      if ( v3 <= duration )
        goto LABEL_6;
      v7 = (float)((float)((float)((float)(this->endValue - this->startValue) / (float)duration) * (float)v3)
                 + this->startValue);
    }
    else
    {
      if ( v3 <= 0.0 )
      {
LABEL_4:
        this->currentValue = this->startValue;
        goto LABEL_12;
      }
      if ( v3 >= duration )
      {
LABEL_6:
        this->currentValue = this->endValue;
        goto LABEL_12;
      }
      *(double *)&v5 = (float)((float)((float)v3 / (float)duration) * idMath::HALF_PI);
      v6 = sin(x: v5);
      v7 = (float)((float)((float)(this->endValue - this->startValue) * (float)*(double *)&v6) + this->startValue);
    }
    this->currentValue = v7;
  }
LABEL_12:
  currentValue = this->currentValue;
  return *((float *)&currentValue + 1);
}


// ========================================================================
// ?Init@?$idInterpolateAccelDecelSine@M@@QAAXMMMMABM0@Z
// EA  : 0x82C70E18
// RVA : 0x00C70E18
// PDB : w:\tech5\shared\idlib\math\interpolate.h
// ========================================================================

void __fastcall idInterpolateAccelDecelSine<float>::Init(
        idInterpolateAccelDecelSine<float> *this,
        double startTime,
        double accelTime,
        double decelTime,
        double duration,
        const float *startValue,
        const float *endValue,
        int a8,
        int a9,
        float *a10,
        float *a11)
{
  double v11; // fp0
  double v12; // fp12
  double v13; // fp8
  double v14; // fp13
  double v15; // fp10
  extrapolation_t v16; // r11

  this->startTime = startTime;
  this->accelTime = accelTime;
  v11 = accelTime;
  this->decelTime = decelTime;
  this->startValue = *a10;
  this->endValue = *a11;
  if ( duration > 0.0 )
  {
    if ( (float)((float)accelTime + (float)decelTime) > duration )
    {
      v11 = (float)((float)((float)accelTime * (float)duration) / (float)((float)accelTime + (float)decelTime));
      this->accelTime = (float)((float)accelTime * (float)duration) / (float)((float)accelTime + (float)decelTime);
      this->decelTime = (float)duration
                      - (float)((float)((float)accelTime * (float)duration)
                              / (float)((float)accelTime + (float)decelTime));
    }
    v12 = this->decelTime;
    v13 = (float)((float)v11 + this->decelTime);
    v14 = (float)((float)((float)duration - (float)v11) - this->decelTime);
    this->linearTime = (float)((float)duration - (float)v11) - this->decelTime;
    v15 = (float)((float)((float)1000.0 / (float)((float)((float)v13 * (float)0.70710677) + (float)v14))
                * (float)(*a11 - *a10));
    if ( v11 == 0.0 )
    {
      if ( v14 == 0.0 )
      {
        this->extrapolate.duration = v12;
        v16 = EXTRAPOLATION_DECELSINE;
      }
      else
      {
        this->extrapolate.duration = v14;
        v16 = EXTRAPOLATION_LINEAR;
      }
    }
    else
    {
      this->extrapolate.duration = v11;
      v16 = EXTRAPOLATION_ACCELSINE;
    }
    this->extrapolate.startTime = startTime;
    this->extrapolate.extrapolationType = v16;
    this->extrapolate.startValue = *a10;
    this->extrapolate.baseSpeed = 0.0;
    this->extrapolate.speed = v15;
    this->extrapolate.currentTime = -1.0;
    this->extrapolate.currentValue = *a10;
  }
  else
  {
    this->linearTime = 0.0;
  }
}


// ========================================================================
// ?SetPhase@?$idInterpolateAccelDecelSine@M@@ABAXM@Z
// EA  : 0x82C70F10
// RVA : 0x00C70F10
// PDB : w:\tech5\shared\idlib\math\interpolate.h
// ========================================================================

void __fastcall idInterpolateAccelDecelSine<float>::SetPhase(idInterpolateAccelDecelSine<float> *this, double time)
{
  double startTime; // fp13
  extrapolation_t extrapolationType; // r11
  double v4; // fp11
  double accelTime; // fp12
  double linearTime; // fp0
  double v7; // fp12
  double v8; // fp12
  double v9; // fp11
  double v10; // fp10
  double startValue; // fp9
  double decelTime; // fp11
  double endValue; // fp10
  double speed; // fp9

  startTime = this->startTime;
  extrapolationType = this->extrapolate.extrapolationType;
  v4 = (float)((float)time - this->startTime);
  accelTime = this->accelTime;
  if ( v4 >= accelTime )
  {
    linearTime = this->linearTime;
    v7 = (float)(this->linearTime + this->accelTime);
    if ( v4 >= v7 )
    {
      if ( extrapolationType != EXTRAPOLATION_DECELSINE )
      {
        decelTime = this->decelTime;
        endValue = this->endValue;
        speed = this->extrapolate.speed;
        this->extrapolate.extrapolationType = EXTRAPOLATION_DECELSINE;
        this->extrapolate.startTime = (float)v7 + (float)startTime;
        this->extrapolate.duration = decelTime;
        this->extrapolate.startValue = -(float)((float)((float)((float)((float)decelTime * (float)0.70710677)
                                                              * (float)0.001)
                                                      * (float)speed)
                                              - (float)endValue);
        this->extrapolate.baseSpeed = this->extrapolate.baseSpeed;
        this->extrapolate.speed = this->extrapolate.speed;
        this->extrapolate.currentTime = -1.0;
        this->extrapolate.currentValue = -(float)((float)((float)((float)((float)decelTime * (float)0.70710677)
                                                                * (float)0.001)
                                                        * (float)speed)
                                                - (float)endValue);
      }
    }
    else if ( extrapolationType != EXTRAPOLATION_LINEAR )
    {
      v8 = this->accelTime;
      v9 = (float)(this->accelTime + this->startTime);
      v10 = this->extrapolate.speed;
      startValue = this->startValue;
      this->extrapolate.extrapolationType = EXTRAPOLATION_LINEAR;
      this->extrapolate.duration = linearTime;
      this->extrapolate.startTime = v9;
      this->extrapolate.startValue = (float)((float)((float)((float)v8 * (float)0.70710677) * (float)0.001) * (float)v10)
                                   + (float)startValue;
      this->extrapolate.baseSpeed = this->extrapolate.baseSpeed;
      this->extrapolate.speed = this->extrapolate.speed;
      this->extrapolate.currentTime = -1.0;
      this->extrapolate.currentValue = (float)((float)((float)((float)v8 * (float)0.70710677) * (float)0.001)
                                             * (float)v10)
                                     + (float)startValue;
    }
  }
  else if ( extrapolationType != EXTRAPOLATION_ACCELSINE )
  {
    this->extrapolate.startTime = this->startTime;
    this->extrapolate.duration = accelTime;
    this->extrapolate.extrapolationType = EXTRAPOLATION_ACCELSINE;
    this->extrapolate.startValue = this->startValue;
    this->extrapolate.baseSpeed = this->extrapolate.baseSpeed;
    this->extrapolate.speed = this->extrapolate.speed;
    this->extrapolate.currentTime = -1.0;
    this->extrapolate.currentValue = this->startValue;
  }
}


// ========================================================================
// ??0?$idInterpolateAccelDecelSine@VidVec3@@@@QAA@XZ
// EA  : 0x82D05F88
// RVA : 0x00D05F88
// PDB : w:\tech5\shared\idlib\math\interpolate.h
// ========================================================================

idInterpolateAccelDecelLinear<idAngles> *__fastcall idInterpolateAccelDecelSine<idVec3>::idInterpolateAccelDecelSine<idVec3>(
        idInterpolateAccelDecelLinear<idAngles> *this)
{
  this->extrapolate.extrapolationType = EXTRAPOLATION_NONE;
  this->extrapolate.duration = 0.0;
  this->extrapolate.startTime = 0.0;
  this->extrapolate.startValue.pitch = 0.0;
  this->extrapolate.startValue.yaw = 0.0;
  this->extrapolate.startValue.roll = 0.0;
  this->extrapolate.baseSpeed.pitch = 0.0;
  this->extrapolate.baseSpeed.yaw = 0.0;
  this->extrapolate.baseSpeed.roll = 0.0;
  this->extrapolate.speed.pitch = 0.0;
  this->extrapolate.speed.yaw = 0.0;
  this->extrapolate.speed.roll = 0.0;
  this->extrapolate.currentTime = -1.0;
  this->extrapolate.currentValue = this->extrapolate.startValue;
  this->decelTime = 0.0;
  this->linearTime = 0.0;
  this->accelTime = 0.0;
  this->startTime = 0.0;
  this->startValue.pitch = 0.0;
  this->startValue.yaw = 0.0;
  this->startValue.roll = 0.0;
  this->endValue = this->startValue;
  return this;
}


// ========================================================================
// ?Init@?$idInterpolateAccelDecelSine@VidVec3@@@@QAAXMMMMABVidVec3@@0@Z
// EA  : 0x82D084B0
// RVA : 0x00D084B0
// PDB : w:\tech5\shared\idlib\math\interpolate.h
// ========================================================================

void __fastcall idInterpolateAccelDecelSine<idVec3>::Init(
        idInterpolateAccelDecelSine<idVec3> *this,
        double startTime,
        double accelTime,
        double decelTime,
        double duration,
        const idVec3 *startValue,
        const idVec3 *endValue,
        int a8,
        int a9,
        idVec3 *a10,
        idVec3 *a11)
{
  double v11; // fp12
  double v12; // fp13
  double v13; // fp11
  double v14; // fp8
  double v15; // fp7
  double z; // fp6
  double v17; // fp5
  double v18; // fp4
  double v19; // fp12
  double v20; // fp2
  double v21; // fp7
  extrapolation_t v22; // r11

  this->startTime = startTime;
  this->accelTime = accelTime;
  this->decelTime = decelTime;
  this->startValue = *a10;
  this->endValue = *a11;
  if ( duration > 0.0 )
  {
    if ( (float)(this->decelTime + this->accelTime) > duration )
    {
      v11 = (float)((float)(this->accelTime * (float)duration) / (float)(this->decelTime + this->accelTime));
      this->accelTime = (float)(this->accelTime * (float)duration) / (float)(this->decelTime + this->accelTime);
      this->decelTime = (float)duration - (float)v11;
    }
    v12 = this->decelTime;
    v13 = this->accelTime;
    v14 = (float)(this->decelTime + this->accelTime);
    v15 = (float)((float)((float)duration - this->accelTime) - this->decelTime);
    this->linearTime = (float)((float)duration - this->accelTime) - this->decelTime;
    z = a11->z;
    v17 = a10->z;
    v18 = (float)(a11->x - a10->x);
    v19 = v15;
    v20 = (float)(a11->y - a10->y);
    this->extrapolate.startTime = startTime;
    v21 = (float)((float)1000.0 / (float)((float)((float)v14 * (float)0.70710677) + (float)v15));
    if ( v13 == 0.0 )
    {
      if ( v19 == 0.0 )
      {
        this->extrapolate.duration = v12;
        v22 = EXTRAPOLATION_DECELSINE;
      }
      else
      {
        this->extrapolate.duration = v19;
        v22 = EXTRAPOLATION_LINEAR;
      }
      this->extrapolate.extrapolationType = v22;
      this->extrapolate.startValue = *a10;
      this->extrapolate.baseSpeed.x = 0.0;
      this->extrapolate.baseSpeed.y = 0.0;
      this->extrapolate.baseSpeed.z = 0.0;
      this->extrapolate.speed.x = (float)v18 * (float)v21;
      this->extrapolate.speed.y = (float)v20 * (float)v21;
      this->extrapolate.speed.z = (float)((float)z - (float)v17) * (float)v21;
      this->extrapolate.currentTime = -1082130432;
      this->extrapolate.currentValue = *a10;
    }
    else
    {
      this->extrapolate.duration = v13;
      this->extrapolate.extrapolationType = EXTRAPOLATION_ACCELSINE;
      this->extrapolate.startValue = *a10;
      this->extrapolate.baseSpeed.x = 0.0;
      this->extrapolate.baseSpeed.y = 0.0;
      this->extrapolate.baseSpeed.z = 0.0;
      this->extrapolate.speed.x = (float)v18 * (float)v21;
      this->extrapolate.speed.y = (float)v20 * (float)v21;
      this->extrapolate.speed.z = (float)((float)z - (float)v17) * (float)v21;
      this->extrapolate.currentTime = -1082130432;
      this->extrapolate.currentValue = *a10;
    }
  }
  else
  {
    this->linearTime = 0.0;
  }
}


// ========================================================================
// ?SetPhase@?$idInterpolateAccelDecelSine@VidVec3@@@@ABAXM@Z
// EA  : 0x82D08680
// RVA : 0x00D08680
// PDB : w:\tech5\shared\idlib\math\interpolate.h
// ========================================================================

void __fastcall idInterpolateAccelDecelSine<idVec3>::SetPhase(idInterpolateAccelDecelSine<idVec3> *this, double time)
{
  double startTime; // fp13
  double v3; // fp11
  double accelTime; // fp12
  double linearTime; // fp0
  extrapolation_t extrapolationType; // r10
  double v7; // fp12
  idExtrapolate<idVec3> *p_extrapolate; // r11
  double v9; // fp11
  double v10; // fp10
  double v11; // fp6
  double v12; // fp9
  double v13; // fp7
  double v14; // fp8
  double v15; // fp5
  double v16; // fp4
  double decelTime; // fp11
  double x; // fp10
  double y; // fp9
  double z; // fp8
  double v21; // fp6
  double v22; // fp5
  double v23; // fp4
  double v24; // fp3

  startTime = this->startTime;
  v3 = (float)((float)time - this->startTime);
  accelTime = this->accelTime;
  if ( v3 >= accelTime )
  {
    linearTime = this->linearTime;
    extrapolationType = this->extrapolate.extrapolationType;
    v7 = (float)(this->linearTime + this->accelTime);
    p_extrapolate = &this->extrapolate;
    if ( v3 >= v7 )
    {
      if ( extrapolationType != EXTRAPOLATION_DECELSINE )
      {
        decelTime = this->decelTime;
        x = this->endValue.x;
        y = this->endValue.y;
        z = this->endValue.z;
        v21 = this->extrapolate.speed.x;
        v22 = (float)(this->decelTime * (float)0.70710677);
        v23 = this->extrapolate.speed.y;
        v24 = this->extrapolate.speed.z;
        p_extrapolate->extrapolationType = EXTRAPOLATION_DECELSINE;
        this->extrapolate.duration = decelTime;
        this->extrapolate.startTime = (float)v7 + (float)startTime;
        this->extrapolate.startValue.x = (float)x - (float)((float)v21 * (float)((float)v22 * (float)0.001));
        this->extrapolate.startValue.y = (float)y - (float)((float)v23 * (float)((float)v22 * (float)0.001));
        this->extrapolate.startValue.z = (float)z - (float)((float)((float)v22 * (float)0.001) * (float)v24);
        this->extrapolate.baseSpeed = this->extrapolate.baseSpeed;
        this->extrapolate.speed = this->extrapolate.speed;
        this->extrapolate.currentTime = -1.0;
        this->extrapolate.currentValue.x = (float)x - (float)((float)v21 * (float)((float)v22 * (float)0.001));
        this->extrapolate.currentValue.y = (float)y - (float)((float)v23 * (float)((float)v22 * (float)0.001));
        this->extrapolate.currentValue.z = (float)z - (float)((float)((float)v22 * (float)0.001) * (float)v24);
      }
    }
    else if ( extrapolationType != EXTRAPOLATION_LINEAR )
    {
      v9 = (float)(this->accelTime + this->startTime);
      v10 = this->extrapolate.speed.x;
      v11 = this->startValue.x;
      v12 = this->extrapolate.speed.y;
      v13 = (float)(this->accelTime * (float)0.70710677);
      v14 = this->extrapolate.speed.z;
      v15 = this->startValue.y;
      v16 = this->startValue.z;
      p_extrapolate->extrapolationType = EXTRAPOLATION_LINEAR;
      this->extrapolate.duration = linearTime;
      this->extrapolate.startTime = v9;
      this->extrapolate.startValue.x = (float)v11 + (float)((float)v10 * (float)((float)v13 * (float)0.001));
      this->extrapolate.startValue.y = (float)v15 + (float)((float)v12 * (float)((float)v13 * (float)0.001));
      this->extrapolate.startValue.z = (float)v16 + (float)((float)((float)v13 * (float)0.001) * (float)v14);
      this->extrapolate.baseSpeed = this->extrapolate.baseSpeed;
      this->extrapolate.speed = this->extrapolate.speed;
      this->extrapolate.currentTime = -1.0;
      this->extrapolate.currentValue.x = (float)v11 + (float)((float)v10 * (float)((float)v13 * (float)0.001));
      this->extrapolate.currentValue.y = (float)v15 + (float)((float)v12 * (float)((float)v13 * (float)0.001));
      this->extrapolate.currentValue.z = (float)v16 + (float)((float)((float)v13 * (float)0.001) * (float)v14);
    }
  }
  else if ( this->extrapolate.extrapolationType != EXTRAPOLATION_ACCELSINE )
  {
    this->extrapolate.startTime = this->startTime;
    this->extrapolate.duration = accelTime;
    this->extrapolate.extrapolationType = EXTRAPOLATION_ACCELSINE;
    this->extrapolate.startValue = this->startValue;
    this->extrapolate.baseSpeed = this->extrapolate.baseSpeed;
    this->extrapolate.speed = this->extrapolate.speed;
    this->extrapolate.currentTime = -1.0;
    this->extrapolate.currentValue = this->startValue;
  }
}

