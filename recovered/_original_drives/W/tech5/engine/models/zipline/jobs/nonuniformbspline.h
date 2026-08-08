
// ========================================================================
// ?ClampedTime@?$idNonUniformBSpline@VidVec3@@@@QBAMM@Z
// EA  : 0x828915D8
// RVA : 0x008915D8
// PDB : w:\tech5\engine\models\zipline\jobs\nonuniformbspline.h
// ========================================================================

// local variable allocation has failed, the output may be wrong!
float __fastcall idNonUniformBSpline<idVec3>::ClampedTime(idNonUniformBSpline<idVec3> *this, double t)
{
  idNonUniformBSpline<idVec3>::boundary_t boundaryType; // r11
  int numKnots; // r11
  double v5; // fp30
  long double v6; // fp2
  long double v7; // fp2
  double v8; // fp1

  boundaryType = this->boundaryType;
  if ( boundaryType != CLAMPED )
  {
    if ( boundaryType == CLOSED )
    {
      numKnots = this->numKnots;
      v5 = (float)(this->times[numKnots - 1] + this->closeTime);
      *(double *)&v6 = (float)((float)t / (float)(this->times[numKnots - 1] + this->closeTime));
      v7 = floor(x: v6);
      v8 = (float)-(float)((float)((float)*(double *)&v7 * (float)v5) - (float)t);
      return *((float *)&v8 + 1);
    }
LABEL_6:
    v8 = t;
    return *((float *)&v8 + 1);
  }
  v8 = this->times[0];
  if ( t >= v8 )
  {
    v8 = this->times[this->numKnots - 1];
    if ( t < v8 )
      goto LABEL_6;
  }
  return *((float *)&v8 + 1);
}


// ========================================================================
// ?IndexForTime@?$idNonUniformBSpline@VidVec3@@@@QBAHM@Z
// EA  : 0x82891670
// RVA : 0x00891670
// PDB : w:\tech5\engine\models\zipline\jobs\nonuniformbspline.h
// ========================================================================

int __fastcall idNonUniformBSpline<idVec3>::IndexForTime(idNonUniformBSpline<idVec3> *this, double time)
{
  int numKnots; // r11
  int v3; // r8
  int v4; // r9
  int v5; // r10
  int v6; // r9
  double v7; // fp0

  numKnots = this->numKnots;
  v3 = 0;
  v4 = 0;
  if ( numKnots <= 0 )
    return v4 + v3;
  while ( 1 )
  {
    v5 = numKnots >> 1;
    v6 = v3 + (numKnots >> 1);
    v7 = this->times[v6];
    if ( time == v7 )
      break;
    numKnots -= v5;
    if ( time <= v7 )
    {
      v4 = 0;
    }
    else
    {
      v3 = v6;
      v4 = 1;
    }
    if ( v5 <= 0 )
      return v4 + v3;
  }
  return v3 + (numKnots >> 1);
}


// ========================================================================
// ?ValueForIndex@?$idNonUniformBSpline@VidVec3@@@@QBA?AVidVec3@@H@Z
// EA  : 0x828916D0
// RVA : 0x008916D0
// PDB : w:\tech5\engine\models\zipline\jobs\nonuniformbspline.h
// ========================================================================

idNonUniformBSpline<idVec3> *__fastcall idNonUniformBSpline<idVec3>::ValueForIndex(
        idNonUniformBSpline<idVec3> *this,
        idVec3 *result,
        int index)
{
  __int64 v3; // r11
  float v4; // r11
  float v5; // r10
  float v6; // r9
  float v7; // r11
  int v8; // r10
  int v9; // r5
  idVec3 *v10; // r11
  double v11; // fp13
  double v12; // fp10
  double v13; // fp1
  double v14; // fp12
  float x; // r9
  int v16; // r11
  idVec3 *v17; // r11
  float v18; // r10
  float v19; // r9
  __int64 v20; // r8
  idVec3 *v21; // r11
  double v22; // fp10
  double y; // fp9
  double v24; // fp0
  double v25; // fp1
  idVec3 *v26; // r11
  float v27; // r9
  float z; // r10

  *(float *)&v3 = result[682].z;
  LODWORD(v3) = HIDWORD(v3) - 1;
  if ( index >= 0 )
  {
    if ( index <= (int)v3 )
    {
      v16 = index;
    }
    else
    {
      x = result[683].x;
      if ( x == 0.0 )
      {
        LODWORD(v20) = index - v3;
        HIDWORD(v20) = 3 * v3;
        v21 = &result[v3];
        v22 = v21[171].x;
        y = v21[171].y;
        v24 = (float)((float)(v21[171].y - v21[170].y) * (float)v20);
        v25 = (float)((float)(v21[171].x - v21[170].x) * (float)v20);
        this->times[0] = v21[170].z + (float)((float)(v21[170].z - v21[169].z) * (float)v20);
        this->times[2] = (float)y + (float)v24;
        this->times[1] = (float)v22 + (float)v25;
        return this;
      }
      if ( LODWORD(x) == 2 )
      {
        __twllei(HIDWORD(v3), 0);
        __twlgei(HIDWORD(v3) & ~(__ROL4__(index, 1) - 1), 0xFFFFFFFF);
        v17 = &result[index % SHIDWORD(v3)];
        v18 = v17[171].x;
        v19 = v17[171].y;
        this->times[0] = v17[170].z;
        this->times[1] = v18;
        this->times[2] = v19;
        return this;
      }
      v16 = v3;
    }
    v26 = &result[v16];
    v27 = v26[171].x;
    z = v26[170].z;
    this->times[2] = v26[171].y;
    this->times[1] = v27;
    this->times[0] = z;
    return this;
  }
  v4 = result[683].x;
  if ( v4 == 0.0 )
  {
    LODWORD(v3) = index;
    v11 = result[171].x;
    v12 = result[171].y;
    v13 = (float)((float)(result[172].x - result[171].x) * (float)v3);
    v14 = (float)((float)(result[172].y - result[171].y) * (float)v3);
    this->times[0] = result[170].z + (float)((float)(result[171].z - result[170].z) * (float)v3);
    this->times[1] = (float)v11 + (float)v13;
    this->times[2] = (float)v12 + (float)v14;
  }
  else
  {
    if ( LODWORD(v4) == 2 )
    {
      v7 = result[682].z;
      v8 = __ROL4__(index, 1);
      v9 = index % SLODWORD(v7) + LODWORD(v7);
      __twlgei(LODWORD(v7) & ~(v8 - 1), 0xFFFFFFFF);
      __twllei(LODWORD(v7), 0);
      __twllei(LODWORD(v7), 0);
      __twlgei(LODWORD(v7) & ~(__ROL4__(v9, 1) - 1), 0xFFFFFFFF);
      v10 = &result[v9 % SLODWORD(v7)];
      v5 = v10[171].x;
      v6 = v10[171].y;
      this->times[0] = v10[170].z;
    }
    else
    {
      v5 = result[171].x;
      v6 = result[171].y;
      this->times[0] = result[170].z;
    }
    this->times[1] = v5;
    this->times[2] = v6;
  }
  return this;
}


// ========================================================================
// ?TimeForIndex@?$idNonUniformBSpline@VidVec3@@@@QBAMH@Z
// EA  : 0x828918F8
// RVA : 0x008918F8
// PDB : w:\tech5\engine\models\zipline\jobs\nonuniformbspline.h
// ========================================================================

float __fastcall idNonUniformBSpline<idVec3>::TimeForIndex(
        idNonUniformBSpline<idVec3> *this,
        __int64 index,
        int a3,
        int a4,
        __int64 a5)
{
  __int64 v5; // r11
  int v6; // r11
  signed int v7; // r11
  double v8; // fp12
  __int64 v9; // r7
  double v10; // fp8
  double v11; // fp1
  signed int numKnots; // r9
  double v13; // fp12
  double v14; // fp11

  v6 = this->numKnots - 1;
  if ( index >= 0 )
  {
    if ( SHIDWORD(index) <= v6 )
    {
      v11 = this->times[HIDWORD(index)];
    }
    else if ( this->boundaryType == CLOSED )
    {
      numKnots = this->numKnots;
      LODWORD(index) = SHIDWORD(index) / numKnots;
      v13 = (float)(this->times[v6] + this->closeTime);
      v14 = this->times[SHIDWORD(index) % numKnots];
      __twllei(numKnots, 0);
      __twllei(numKnots, 0);
      __twlgei(numKnots & ~(__ROL4__(HIDWORD(index), 1) - 1), 0xFFFFFFFF);
      __twlgei(numKnots & ~(__ROL4__(HIDWORD(index), 1) - 1), 0xFFFFFFFF);
      v11 = (float)((float)((float)v13 * (float)index) + (float)v14);
    }
    else
    {
      LODWORD(a5) = HIDWORD(index) - v6;
      v11 = (float)((float)((float)(this->times[v6] - this->times[v6 - 1]) * (float)a5) + this->times[v6]);
    }
  }
  else if ( this->boundaryType == CLOSED )
  {
    v7 = this->numKnots;
    v8 = (float)(this->closeTime + this->times[0]);
    LODWORD(v9) = SHIDWORD(index) / v7;
    HIDWORD(v9) = SHIDWORD(index) / v7 * v7;
    LODWORD(index) = SHIDWORD(index) % v7 + v7;
    v10 = this->times[(int)index % v7];
    __twllei(v7, 0);
    __twllei(v7, 0);
    __twllei(v7, 0);
    __twlgei(v7 & ~(__ROL4__(HIDWORD(index), 1) - 1), 0xFFFFFFFF);
    __twlgei(v7 & ~(__ROL4__(HIDWORD(index), 1) - 1), 0xFFFFFFFF);
    __twlgei(v7 & ~(__ROL4__(index, 1) - 1), 0xFFFFFFFF);
    v11 = (float)((float)((float)v9 * (float)v8) - (float)((float)v8 - (float)v10));
  }
  else
  {
    LODWORD(v5) = HIDWORD(index);
    v11 = (float)((float)((float)(this->times[1] - this->times[0]) * (float)v5) + this->times[0]);
  }
  return *((float *)&v11 + 1);
}


// ========================================================================
// ?Basis@?$idNonUniformBSpline@VidVec3@@@@IBAXHHMPAM@Z
// EA  : 0x82891BB8
// RVA : 0x00891BB8
// PDB : w:\tech5\engine\models\zipline\jobs\nonuniformbspline.h
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idNonUniformBSpline<idVec3>::Basis(
        idNonUniformBSpline<idVec3> *this,
        const int index,
        __int64 bvals,
        double t,
        int a5,
        __int64 a6)
{
  int v8; // r27
  int v9; // r21
  __int64 v10; // r11 OVERLAPPED
  float *v11; // r22
  int v12; // r25
  float *v13; // r24
  int v14; // r20
  int v15; // r31
  float *v16; // r29
  float *v17; // r26
  int v18; // r28
  int v19; // r11
  double v20; // fp12
  __int64 v21; // r7
  int v22; // r5
  double v23; // fp10
  double v24; // fp8
  double v25; // fp31
  __int64 v26; // r5
  double v27; // fp12
  double v28; // fp11
  double v29; // fp27
  __int64 v30; // r10
  int v31; // r8
  int v32; // r7
  __int64 v33; // r6
  double v34; // fp1
  double v35; // fp8
  __int64 v36; // [sp+60h] [-A0h]

  LODWORD(a6) = 4 * HIDWORD(bvals) + a5;
  v8 = HIDWORD(bvals);
  v9 = 2;
  *(float *)(a6 - 4) = 1.0;
  if ( SHIDWORD(bvals) >= 2 )
  {
    HIDWORD(v10) = 4 * (HIDWORD(bvals) - 2);
    v11 = &this->times[index - 1];
    v12 = HIDWORD(bvals) - 1;
    v13 = (float *)(HIDWORD(v10) + a5);
    v14 = index - HIDWORD(bvals);
    do
    {
      *v13 = 0.0;
      v15 = v14 + v12;
      if ( v12 < v8 )
      {
        v16 = v13;
        v17 = v11;
        v18 = v8 - v12;
        do
        {
          ++v15;
          ++v17;
          v19 = this->numKnots - 1;
          if ( v15 >= 0 )
          {
            if ( v15 <= v19 )
            {
              v25 = *v17;
            }
            else if ( this->boundaryType == CLOSED )
            {
              LODWORD(a6) = this->numKnots;
              LODWORD(v26) = v15 / (int)a6;
              HIDWORD(v26) = v15 / (int)a6 * a6;
              v27 = (float)(this->times[v19] + this->closeTime);
              v36 = v26;
              HIDWORD(v10) = __ROL4__(v15, 1);
              HIDWORD(a6) = 4 * (v15 % (int)a6);
              a5 = HIDWORD(v10) - 1;
              LODWORD(bvals) = HIDWORD(v10) - 1;
              HIDWORD(bvals) = a6 & ~(HIDWORD(v10) - 1);
              v28 = *(float *)((char *)this->times + HIDWORD(a6));
              __twllei(a6, 0);
              __twllei(a6, 0);
              __twlgei(HIDWORD(bvals), 0xFFFFFFFF);
              __twlgei(HIDWORD(bvals), 0xFFFFFFFF);
              v25 = (float)((float)((float)v27 * (float)v36) + (float)v28);
            }
            else
            {
              HIDWORD(v10) = v15 - v19;
              LODWORD(a6) = v15 - v19;
              v25 = (float)((float)((float)(this->times[v19] - this->times[v19 - 1]) * (float)a6) + this->times[v19]);
            }
          }
          else if ( this->boundaryType == CLOSED )
          {
            LODWORD(v10) = this->numKnots;
            v20 = (float)(this->closeTime + this->times[0]);
            LODWORD(v21) = v15 / (int)v10;
            HIDWORD(v21) = v15 / (int)v10 * v10;
            v22 = v15 % (int)v10 + v10;
            HIDWORD(v10) = __ROL4__(v22, 1);
            v23 = (double)v21;
            a5 = v22 % (int)v10;
            LODWORD(bvals) = __ROL4__(v15, 1) - 1;
            HIDWORD(bvals) = 4 * (v22 % (int)v10);
            LODWORD(a6) = v10 & ~(_DWORD)bvals;
            HIDWORD(a6) = v10 & ~(HIDWORD(v10) - 1);
            HIDWORD(v10) = a6;
            v24 = *(float *)((char *)this->times + HIDWORD(bvals));
            __twllei(v10, 0);
            __twllei(v10, 0);
            __twllei(v10, 0);
            __twlgei(a6, 0xFFFFFFFF);
            __twlgei(a6, 0xFFFFFFFF);
            __twlgei(HIDWORD(a6), 0xFFFFFFFF);
            v25 = (float)((float)((float)v23 * (float)v20) - (float)((float)v20 - (float)v24));
          }
          else
          {
            LODWORD(v10) = v15;
            v25 = (float)((float)((float)(this->times[1] - this->times[0]) * (float)v10) + this->times[0]);
          }
          v29 = idNonUniformBSpline<idVec3>::TimeForIndex(
                  this,
                  index: bvals,
                  a3: a5,
                  a4: SHIDWORD(a6),
                  a5: *(__int64 *)((char *)&a6 - 4));
          v34 = idNonUniformBSpline<idVec3>::TimeForIndex(this, index: v33, a3: v32, a4: v31, a5: v30);
          --v18;
          v35 = (float)(v16[1] * (float)((float)((float)t - (float)v25) / (float)((float)v29 - (float)v34)));
          *v16 = (float)((float)((float)1.0 - (float)((float)((float)t - (float)v25) / (float)((float)v29 - (float)v34)))
                       * v16[1])
               + *v16;
          *++v16 = v35;
        }
        while ( v18 != 0 );
      }
      ++v9;
      --v13;
      --v11;
      --v12;
    }
    while ( v9 <= v8 );
  }
}


// ========================================================================
// ?GetCurrentValue@?$idNonUniformBSpline@VidVec3@@@@QBA?AVidVec3@@M@Z
// EA  : 0x82891E50
// RVA : 0x00891E50
// PDB : w:\tech5\engine\models\zipline\jobs\nonuniformbspline.h
// ========================================================================

idNonUniformBSpline<idVec3> *__fastcall idNonUniformBSpline<idVec3>::GetCurrentValue(
        idNonUniformBSpline<idVec3> *this,
        idNonUniformBSpline<idVec3> *result,
        double time)
{
  float x; // r11
  float y; // r10
  float z; // r9
  double v8; // fp31
  int v9; // r3
  float v10; // r29
  int v11; // r27
  __int64 v12; // r6
  __int64 v13; // r10
  int v14; // r31
  double v15; // fp31
  double v16; // fp30
  double v17; // fp29
  float *v18; // r28
  idNonUniformBSpline<idVec3> *v19; // r3
  float v21; // [sp+50h] [-A0h]
  float v22; // [sp+54h] [-9Ch]
  float v23; // [sp+58h] [-98h]
  char v24; // [sp+60h] [-90h] BYREF
  int v25; // [sp+6Ch] [-84h] BYREF
  _BYTE v26[40]; // [sp+70h] [-80h] BYREF

  if ( result->numKnots == 1 )
  {
    x = result->values[0].x;
    y = result->values[0].y;
    z = result->values[0].z;
  }
  else
  {
    v8 = idNonUniformBSpline<idVec3>::ClampedTime(this: result, t: time);
    v9 = idNonUniformBSpline<idVec3>::IndexForTime(this: result, time: v8);
    v10 = *(float *)&result->order;
    v11 = v9;
    *(float *)&v12 = v10;
    idNonUniformBSpline<idVec3>::Basis(this: result, index: v9 - 1, bvals: v12, t: v8, a5: (int)v26, a6: v13);
    v14 = 0;
    v15 = 0.0;
    v21 = 0.0;
    v16 = 0.0;
    v22 = 0.0;
    v17 = 0.0;
    v23 = 0.0;
    if ( SLODWORD(v10) > 0 )
    {
      v18 = (float *)&v25;
      do
      {
        v19 = idNonUniformBSpline<idVec3>::ValueForIndex(
                this: (idNonUniformBSpline<idVec3> *)&v24,
                (idVec3 *)result,
                index: v14 - (SLODWORD(v10) >> 1) + v11);
        ++v18;
        ++v14;
        v15 = (float)((float)(v19->times[0] * *v18) + (float)v15);
        v16 = (float)((float)(v19->times[1] * *v18) + (float)v16);
        v17 = (float)((float)(v19->times[2] * *v18) + (float)v17);
      }
      while ( v14 < SLODWORD(v10) );
      v23 = v17;
      v22 = v16;
      v21 = v15;
    }
    x = v21;
    y = v22;
    z = v23;
  }
  this->times[2] = z;
  this->times[1] = y;
  this->times[0] = x;
  return this;
}


// ========================================================================
// ?AddValue@?$idNonUniformBSpline@VidVec3@@@@QAAHMABVidVec3@@@Z
// EA  : 0x82892C60
// RVA : 0x00892C60
// PDB : w:\tech5\engine\models\zipline\jobs\nonuniformbspline.h
// ========================================================================

int __fastcall idNonUniformBSpline<idVec3>::AddValue(
        idNonUniformBSpline<idVec3> *this,
        double time,
        const idVec3 *value,
        float *a4)
{
  int numKnots; // r10
  int result; // r3
  float *v7; // r10

  numKnots = this->numKnots;
  if ( numKnots >= 512 )
    return -1;
  this->times[numKnots] = time;
  v7 = &this->times[3 * this->numKnots];
  v7[512] = *a4;
  v7[513] = a4[1];
  v7[514] = a4[2];
  result = this->numKnots;
  this->numKnots = result + 1;
  return result;
}

