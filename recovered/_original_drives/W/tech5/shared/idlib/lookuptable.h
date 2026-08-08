
// ========================================================================
// ?Sort@?$idCatmullRomSpline@M@@QAAXXZ
// EA  : 0x82F2F020
// RVA : 0x00F2F020
// PDB : w:\tech5\shared\idlib\lookuptable.h
// ========================================================================

void __fastcall idCatmullRomSpline<float>::Sort(idCatmullRomSpline<float> *this)
{
  int v1; // r31
  float *v2; // r29
  int v3; // r8
  int v4; // r9
  char *v5; // r10
  int v6; // r7
  float *v7; // r11
  int v8; // r10
  int v9; // r11
  int v10; // ctr
  int v11; // r10
  double v12; // fp13
  double v13; // fp12
  double v14; // fp11

  v1 = this->numKnots - 1;
  if ( v1 > 0 )
  {
    v2 = &this->values[v1 + 1];
    do
    {
      v3 = 0;
      v4 = 1;
      if ( v1 >= 4 )
      {
        v5 = nullptr;
        v6 = 12;
        v7 = &this->times[3];
        do
        {
          if ( *(v7 - 2) > (double)*(float *)((char *)this->times + (_DWORD)v5) )
          {
            v3 = v4;
            v5 = (char *)v7 - 8 - (_DWORD)this;
          }
          if ( *(v7 - 1) > (double)*(float *)((char *)this->times + (_DWORD)v5) )
          {
            v3 = v4 + 1;
            v5 = (char *)v7 - 4 - (_DWORD)this;
          }
          if ( *v7 > (double)*(float *)((char *)this->times + (_DWORD)v5) )
          {
            v3 = v4 + 2;
            v5 = (char *)v6;
          }
          if ( v7[1] > (double)*(float *)((char *)this->times + (_DWORD)v5) )
          {
            v3 = v4 + 3;
            v5 = (char *)v7 + 4 - (_DWORD)this;
          }
          v4 += 4;
          v6 += 16;
          v7 += 4;
        }
        while ( v4 <= v1 - 3 );
      }
      if ( v4 <= v1 )
      {
        v8 = 4 * v3;
        v9 = v4;
        v10 = v1 - v4 + 1;
        do
        {
          if ( this->times[v9] > (double)*(float *)((char *)this->times + v8) )
          {
            v3 = v4;
            v8 = v9 * 4;
          }
          ++v4;
          ++v9;
          --v10;
        }
        while ( v10 != 0 );
      }
      v11 = v3 + 64;
      --v1;
      v12 = this->times[v3];
      v13 = this->times[v11];
      this->times[v3] = *(v2 - 65);
      v14 = *(v2 - 1);
      *(v2 - 65) = v12;
      this->times[v11] = v14;
      *--v2 = v13;
    }
    while ( v1 > 0 );
  }
  this->changed = true;
}


// ========================================================================
// ?Normalize@?$idCatmullRomSpline@M@@QAAXM@Z
// EA  : 0x82F2F160
// RVA : 0x00F2F160
// PDB : w:\tech5\shared\idlib\lookuptable.h
// ========================================================================

void __fastcall idCatmullRomSpline<float>::Normalize(idCatmullRomSpline<float> *this, double totalTime)
{
  int numKnots; // r11
  double v3; // fp0
  int v4; // r10
  float *v5; // r11
  double v6; // fp12

  numKnots = this->numKnots;
  if ( numKnots >= 1 && this->times[numKnots - 1] != 0.0 )
  {
    v3 = (float)((float)totalTime / this->times[numKnots - 1]);
    v4 = 0;
    v5 = (float *)((char *)this - 4);
    do
    {
      ++v4;
      v6 = (float)(v5[1] * (float)v3);
      *++v5 = v6;
    }
    while ( v4 < this->numKnots );
    this->changed = true;
  }
}


// ========================================================================
// ?ClampedTime@?$idCatmullRomSpline@M@@QBAMM@Z
// EA  : 0x82F2F1C8
// RVA : 0x00F2F1C8
// PDB : w:\tech5\shared\idlib\lookuptable.h
// ========================================================================

// local variable allocation has failed, the output may be wrong!
float __fastcall idCatmullRomSpline<float>::ClampedTime(idCatmullRomSpline<float> *this, double t)
{
  idCatmullRomSpline<float>::boundary_t boundaryType; // r11
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
// ?IndexForTime@?$idCatmullRomSpline@M@@QBAHM_N@Z
// EA  : 0x82F2F260
// RVA : 0x00F2F260
// PDB : w:\tech5\shared\idlib\lookuptable.h
// ========================================================================

int __fastcall idCatmullRomSpline<float>::IndexForTime(
        idCatmullRomSpline<float> *this,
        double time,
        const bool fastSearch,
        char a4)
{
  int result; // r3
  int numKnots; // r10
  float *v7; // r11
  double v8; // fp0
  int v9; // r11
  int v10; // r8
  int v11; // r9
  int v12; // r10
  int v13; // r9
  double v14; // fp0

  if ( a4 != 0 )
  {
    result = this->currentIndex;
    if ( result >= 0 )
    {
      numKnots = this->numKnots;
      if ( result <= numKnots )
      {
        if ( result != 0 )
        {
          v7 = &this->times[result];
          v8 = *(v7 - 1);
          if ( result == numKnots )
          {
            if ( time > v8 )
              return result;
          }
          else
          {
            if ( time > v8 && time <= *v7 )
              return result;
            if ( time > *v7 && (++result == numKnots || time <= v7[1]) )
            {
LABEL_22:
              this->currentIndex = result;
              return result;
            }
          }
        }
        else if ( time <= this->times[0] )
        {
          return result;
        }
      }
    }
  }
  v9 = this->numKnots;
  v10 = 0;
  v11 = 0;
  if ( v9 <= 0 )
  {
LABEL_21:
    result = v11 + v10;
    if ( a4 == 0 )
      return result;
    goto LABEL_22;
  }
  while ( 1 )
  {
    v12 = v9 >> 1;
    v13 = v10 + (v9 >> 1);
    v14 = this->times[v13];
    if ( time == v14 )
      return v10 + (v9 >> 1);
    v9 -= v12;
    if ( time <= v14 )
    {
      v11 = 0;
    }
    else
    {
      v10 = v13;
      v11 = 1;
    }
    if ( v12 <= 0 )
      goto LABEL_21;
  }
}


// ========================================================================
// ?TimeForIndex@?$idCatmullRomSpline@M@@QBAMH@Z
// EA  : 0x82F2F368
// RVA : 0x00F2F368
// PDB : w:\tech5\shared\idlib\lookuptable.h
// ========================================================================

float __fastcall idCatmullRomSpline<float>::TimeForIndex(
        idCatmullRomSpline<float> *this,
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
// ?ValueForIndex@?$idCatmullRomSpline@M@@QBAMH@Z
// EA  : 0x82F2F508
// RVA : 0x00F2F508
// PDB : w:\tech5\shared\idlib\lookuptable.h
// ========================================================================

float __fastcall idCatmullRomSpline<float>::ValueForIndex(idCatmullRomSpline<float> *this, int index)
{
  __int64 v2; // r11
  idCatmullRomSpline<float>::boundary_t v3; // r11
  double v4; // fp1
  signed int numKnots; // r11
  int v6; // r5
  idCatmullRomSpline<float>::boundary_t boundaryType; // r9
  __int64 v8; // r8

  LODWORD(v2) = this->numKnots;
  HIDWORD(v2) = v2 - 1;
  if ( index >= 0 )
  {
    if ( index <= SHIDWORD(v2) )
    {
      v4 = this->values[index];
    }
    else
    {
      boundaryType = this->boundaryType;
      if ( boundaryType != 0 )
      {
        if ( boundaryType == CLOSED )
        {
          __twllei(v2, 0);
          __twlgei(v2 & ~(__ROL4__(index, 1) - 1), 0xFFFFFFFF);
          v4 = this->values[index % (int)v2];
        }
        else
        {
          v4 = this->values[HIDWORD(v2)];
        }
      }
      else
      {
        LODWORD(v8) = index - HIDWORD(v2);
        HIDWORD(v8) = HIDWORD(v2) + 63;
        v4 = (float)((float)((float)(this->values[HIDWORD(v2)] - this->times[HIDWORD(v2) + 63]) * (float)v8)
                   + this->values[HIDWORD(v2)]);
      }
    }
  }
  else
  {
    v3 = this->boundaryType;
    if ( v3 != 0 )
    {
      if ( v3 == CLOSED )
      {
        numKnots = this->numKnots;
        v6 = index % numKnots + numKnots;
        __twlgei(numKnots & ~(__ROL4__(index, 1) - 1), 0xFFFFFFFF);
        __twllei(numKnots, 0);
        __twllei(numKnots, 0);
        __twlgei(numKnots & ~(__ROL4__(v6, 1) - 1), 0xFFFFFFFF);
        v4 = this->values[v6 % numKnots];
      }
      else
      {
        v4 = this->values[0];
      }
    }
    else
    {
      LODWORD(v2) = index;
      v4 = (float)((float)((float)(this->values[1] - this->values[0]) * (float)v2) + this->values[0]);
    }
  }
  return *((float *)&v4 + 1);
}


// ========================================================================
// ?Basis@?$idCatmullRomSpline@M@@IBAXHMPAM@Z
// EA  : 0x82F2F660
// RVA : 0x00F2F660
// PDB : w:\tech5\shared\idlib\lookuptable.h
// ========================================================================

void __fastcall idCatmullRomSpline<float>::Basis(
        idCatmullRomSpline<float> *this,
        const int index,
        double t,
        __int64 bvals,
        int a5,
        int a6,
        __int64 a7)
{
  float *v8; // r29
  double v9; // fp31
  __int64 v10; // r10
  int v11; // r8
  int v12; // r7
  __int64 v13; // r6
  double v14; // fp30
  __int64 v15; // r10
  int v16; // r8
  int v17; // r7
  __int64 v18; // r6
  double v19; // fp1

  v8 = (float *)bvals;
  v9 = (float)((float)t - idCatmullRomSpline<float>::TimeForIndex(this, index: bvals, a3: a5, a4: a6, a5: a7));
  v14 = idCatmullRomSpline<float>::TimeForIndex(this, index: v13, a3: v12, a4: v11, a5: v10);
  v19 = idCatmullRomSpline<float>::TimeForIndex(this, index: v18, a3: v17, a4: v16, a5: v15);
  *v8 = (float)((float)((float)((float)((float)2.0 - (float)((float)v9 / (float)((float)v14 - (float)v19)))
                              * (float)((float)v9 / (float)((float)v14 - (float)v19)))
                      - (float)1.0)
              * (float)((float)v9 / (float)((float)v14 - (float)v19)))
      * (float)0.5;
  v8[3] = (float)((float)((float)((float)((float)v9 / (float)((float)v14 - (float)v19)) - (float)1.0)
                        * (float)((float)v9 / (float)((float)v14 - (float)v19)))
                * (float)((float)v9 / (float)((float)v14 - (float)v19)))
        * (float)0.5;
  v8[1] = (float)((float)((float)((float)((float)((float)((float)v9 / (float)((float)v14 - (float)v19)) * (float)3.0)
                                        - (float)5.0)
                                * (float)((float)v9 / (float)((float)v14 - (float)v19)))
                        * (float)((float)v9 / (float)((float)v14 - (float)v19)))
                + (float)2.0)
        * (float)0.5;
  v8[2] = (float)((float)((float)((float)((float)4.0
                                        - (float)((float)((float)v9 / (float)((float)v14 - (float)v19)) * (float)3.0))
                                * (float)((float)v9 / (float)((float)v14 - (float)v19)))
                        + (float)1.0)
                * (float)((float)v9 / (float)((float)v14 - (float)v19)))
        * (float)0.5;
}


// ========================================================================
// ?GetCurrentValue@?$idCatmullRomSpline@M@@QBAMM_N@Z
// EA  : 0x82F2F8E0
// RVA : 0x00F2F8E0
// PDB : w:\tech5\shared\idlib\lookuptable.h
// ========================================================================

float __fastcall idCatmullRomSpline<float>::GetCurrentValue(
        idCatmullRomSpline<float> *this,
        double time,
        const bool fastSearch,
        char a4)
{
  double v6; // fp1
  double v7; // fp31
  bool v8; // r4
  int v9; // r29
  __int64 v10; // r6
  __int64 v11; // r10
  int v12; // r8
  int v13; // r7
  int v14; // r28
  int v15; // r31
  float *v16; // r29
  double v17; // fp31
  double v18; // fp30
  double v19; // fp1
  int v21; // [sp+4Ch] [-54h] BYREF
  char v22; // [sp+50h] [-50h] BYREF

  if ( this->numKnots == 1 )
  {
    v6 = this->values[0];
  }
  else
  {
    v7 = idCatmullRomSpline<float>::ClampedTime(this, t: time);
    v9 = idCatmullRomSpline<float>::IndexForTime(this, time: v7, fastSearch: v8, a4);
    LODWORD(v10) = &v22;
    idCatmullRomSpline<float>::Basis(this, index: v9 - 1, t: v7, bvals: v10, a5: v13, a6: v12, a7: v11);
    v14 = v9 - 2;
    v15 = 0;
    v16 = (float *)&v21;
    v17 = 0.0;
    do
    {
      v18 = *++v16;
      v19 = idCatmullRomSpline<float>::ValueForIndex(this, index: v14 + v15++);
      v17 = (float)((float)((float)v19 * (float)v18) + (float)v17);
    }
    while ( v15 < 4 );
    v6 = v17;
  }
  return *((float *)&v6 + 1);
}

