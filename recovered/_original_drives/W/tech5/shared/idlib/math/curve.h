
// ========================================================================
// ?ValueForIndex@?$idCurve_Spline@VidVec1@@@@IBA?AVidVec1@@H@Z
// EA  : 0x826308E8
// RVA : 0x006308E8
// PDB : w:\tech5\shared\idlib\math\curve.h
// ========================================================================

idCurve_Spline<idVec1> *__fastcall idCurve_Spline<idVec1>::ValueForIndex(
        idCurve_Spline<idVec1> *this,
        idVec1 *result,
        const int index,
        int a4,
        __int64 a5)
{
  float x; // r10
  int v6; // r11
  float v7; // r11
  float v8; // r9
  float v9; // r11
  float v10; // r7
  int v11; // r8
  idCurve_Spline<idVec1>_vtbl *v12; // r7
  __int64 v13; // r11
  float v14; // r9
  float v15; // r8

  x = result[6].x;
  v6 = LODWORD(x) - 1;
  if ( index >= 0 )
  {
    if ( index > v6 )
    {
      v14 = result[11].x;
      if ( v14 == 0.0 )
      {
        LODWORD(a5) = index - v6;
        *(float *)&this->__vftable = (float)((float)(*(float *)(4 * v6 + LODWORD(result[5].x))
                                                   - *(float *)(4 * v6 + LODWORD(result[5].x) - 4))
                                           * (float)a5)
                                   + *(float *)(4 * v6 + LODWORD(result[5].x));
        return this;
      }
      if ( LODWORD(v14) == 1 )
      {
        this->__vftable = *(idCurve_Spline<idVec1>_vtbl **)(4 * v6 + LODWORD(result[5].x));
        return this;
      }
      if ( LODWORD(v14) < 3 )
      {
        v15 = result[5].x;
        __twllei(LODWORD(x), 0);
        __twlgei(LODWORD(x) & ~(__ROL4__(index, 1) - 1), 0xFFFFFFFF);
        this->__vftable = *(idCurve_Spline<idVec1>_vtbl **)(4 * (index % SLODWORD(x)) + LODWORD(v15));
        return this;
      }
    }
    goto LABEL_15;
  }
  v7 = result[11].x;
  if ( v7 == 0.0 )
  {
    LODWORD(v13) = index;
    HIDWORD(v13) = result[5];
    *(float *)&this->__vftable = (float)((float)(*(float *)(HIDWORD(v13) + 4) - *(float *)HIDWORD(v13)) * (float)v13)
                               + *(float *)HIDWORD(v13);
    return this;
  }
  if ( LODWORD(v7) == 1 )
  {
    this->__vftable = *(idCurve_Spline<idVec1>_vtbl **)LODWORD(result[5].x);
    return this;
  }
  if ( LODWORD(v7) >= 3 )
  {
LABEL_15:
    this->__vftable = *(idCurve_Spline<idVec1>_vtbl **)(4 * index + LODWORD(result[5].x));
    return this;
  }
  v8 = result[2].x;
  v9 = result[6].x;
  v10 = result[5].x;
  __twllei(LODWORD(v8), 0);
  v11 = index % SLODWORD(v8) + LODWORD(v9);
  __twlgei(LODWORD(v8) & ~(__ROL4__(index, 1) - 1), 0xFFFFFFFF);
  __twllei(LODWORD(v9), 0);
  v12 = *(idCurve_Spline<idVec1>_vtbl **)(4 * (v11 % SLODWORD(v9)) + LODWORD(v10));
  __twlgei(LODWORD(v9) & ~(__ROL4__(v11, 1) - 1), 0xFFFFFFFF);
  this->__vftable = v12;
  return this;
}


// ========================================================================
// ?Basis@?$idCurve_CatmullRomSpline@VidVec3@@@@IBAXHMPAM@Z
// EA  : 0x82630A68
// RVA : 0x00630A68
// PDB : w:\tech5\shared\idlib\math\curve.h
// ========================================================================

void __fastcall idCurve_CatmullRomSpline<idVec3>::Basis(
        idCurve_CatmullRomSpline<idVec1> *this,
        int index,
        double t,
        float *bvals,
        float *a5)
{
  double v8; // fp31
  double v9; // fp30
  double v10; // fp1

  v8 = (float)((float)t - idCurve_Spline<idAngles>::TimeForIndex(this, index));
  v9 = idCurve_Spline<idAngles>::TimeForIndex(this, index: index + 1);
  v10 = idCurve_Spline<idAngles>::TimeForIndex(this, index);
  *a5 = (float)((float)((float)((float)((float)2.0 - (float)((float)v8 / (float)((float)v9 - (float)v10)))
                              * (float)((float)v8 / (float)((float)v9 - (float)v10)))
                      - (float)1.0)
              * (float)((float)v8 / (float)((float)v9 - (float)v10)))
      * (float)0.5;
  a5[3] = (float)((float)((float)((float)((float)v8 / (float)((float)v9 - (float)v10)) - (float)1.0)
                        * (float)((float)v8 / (float)((float)v9 - (float)v10)))
                * (float)((float)v8 / (float)((float)v9 - (float)v10)))
        * (float)0.5;
  a5[1] = (float)((float)((float)((float)((float)((float)((float)v8 / (float)((float)v9 - (float)v10)) * (float)3.0)
                                        - (float)5.0)
                                * (float)((float)v8 / (float)((float)v9 - (float)v10)))
                        * (float)((float)v8 / (float)((float)v9 - (float)v10)))
                + (float)2.0)
        * (float)0.5;
  a5[2] = (float)((float)((float)((float)((float)4.0
                                        - (float)((float)((float)v8 / (float)((float)v9 - (float)v10)) * (float)3.0))
                                * (float)((float)v8 / (float)((float)v9 - (float)v10)))
                        + (float)1.0)
                * (float)((float)v8 / (float)((float)v9 - (float)v10)))
        * (float)0.5;
}


// ========================================================================
// ??1?$idCurve@VidVec1@@@@UAA@XZ
// EA  : 0x82630CA8
// RVA : 0x00630CA8
// PDB : w:\tech5\shared\idlib\math\curve.h
// ========================================================================

void __fastcall idCurve<idVec1>::~idCurve<idVec1>(idCurve<idVec1> *this)
{
  this->__vftable = (idCurve<idVec1>_vtbl *)&idCurve<idVec1>::`vftable';
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->values);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->times);
}


// ========================================================================
// __unwind$224117
// EA  : 0x82630CFC
// RVA : 0x00630CFC
// PDB : w:\tech5\shared\idlib\math\curve.h
// ========================================================================

void _unwind_224117()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 4));
}


// ========================================================================
// ?RemoveIndex@?$idCurve@VidVec1@@@@UAAXH@Z
// EA  : 0x82630D28
// RVA : 0x00630D28
// PDB : w:\tech5\shared\idlib\math\curve.h
// ========================================================================

void __fastcall idCurve<idVec1>::RemoveIndex(idCurve<idVec1> *this, int index)
{
  idList<idHandle<int,enum invalidAIEvent_t,-1>,5>::RemoveIndex(
    this: (idList<idEntityPtr<idEntity>,58> *)&this->values,
    index);
  idList<float,5>::RemoveIndex(this: &this->times, index);
  this->changed = true;
}


// ========================================================================
// ?GetCurrentSecondDerivative@?$idCurve@VidVec1@@@@UBA?AVidVec1@@M@Z
// EA  : 0x82630D78
// RVA : 0x00630D78
// PDB : w:\tech5\shared\idlib\math\curve.h
// ========================================================================

idCurve<idVec1> *__fastcall idCurve<idVec1>::GetCurrentSecondDerivative(
        idCurve<idVec1> *this,
        idVec1 *result,
        double time)
{
  *(float *)&this->__vftable = 0.0;
  return this;
}


// ========================================================================
// ?IsDone@?$idCurve@VidAngles@@@@UBA_NM@Z
// EA  : 0x82630D88
// RVA : 0x00630D88
// PDB : w:\tech5\shared\idlib\math\curve.h
// ========================================================================

BOOL __fastcall idCurve<idAngles>::IsDone(idCurve<idVec1> *this, double time)
{
  return time >= this->times.list[this->times.num - 1];
}


// ========================================================================
// ?EstimateLengthForTime@?$idCurve@VidVec1@@@@UBAMM@Z
// EA  : 0x82630DB8
// RVA : 0x00630DB8
// PDB : w:\tech5\shared\idlib\math\curve.h
// ========================================================================

float __fastcall idCurve<idVec1>::EstimateLengthForTime(idCurve<idVec1> *this, double time)
{
  int num; // r7
  int v4; // r9
  double v5; // fp1
  float *list; // r8
  idVec1 *v7; // r10
  float *v8; // r11
  int v9; // r8
  double v10; // fp11
  double v11; // fp0

  num = this->times.num;
  v4 = 1;
  v5 = 0.0;
  if ( num > 1 )
  {
    list = this->times.list;
    v7 = this->values.list;
    v8 = list + 1;
    v9 = (char *)v7 - (char *)list;
    while ( 1 )
    {
      v10 = (float)(*(float *)((char *)v8 + v9) - v7->x);
      v11 = __fsqrts((float)((float)v10 * (float)v10));
      if ( time < *v8 )
        break;
      ++v4;
      v5 = (float)((float)v11 + (float)v5);
      ++v7;
      ++v8;
      if ( v4 >= num )
        return *((float *)&v5 + 1);
    }
    v5 = (float)((float)((float)((float)((float)time - this->times.list[v4 - 1]) * (float)v11)
                       / (float)(this->times.list[v4] - this->times.list[v4 - 1]))
               + (float)v5);
  }
  return *((float *)&v5 + 1);
}


// ========================================================================
// ?GetCurrentValue@?$idCurve@VidVec1@@@@UBA?AVidVec1@@M@Z
// EA  : 0x82630E50
// RVA : 0x00630E50
// PDB : w:\tech5\shared\idlib\math\curve.h
// ========================================================================

idCurve<idVec1> *__fastcall idCurve<idVec1>::GetCurrentValue(
        idCurve<idVec1> *this,
        idCurve<idVec1> *result,
        double time)
{
  int v5; // r3
  float v6; // r11

  v5 = idCurve<idVec3>::IndexForTime(this: result, time);
  v6 = *(float *)&result->values.num;
  if ( v5 < SLODWORD(v6) )
    this->__vftable = (idCurve<idVec1>_vtbl *)LODWORD(result->values.list[v5].x);
  else
    this->__vftable = (idCurve<idVec1>_vtbl *)LODWORD(result->values.list[LODWORD(v6) - 1].x);
  return this;
}


// ========================================================================
// ?GetCurrentValue@?$idCurve_CatmullRomSpline@VidVec1@@@@UBA?AVidVec1@@M@Z
// EA  : 0x82630EC8
// RVA : 0x00630EC8
// PDB : w:\tech5\shared\idlib\math\curve.h
// ========================================================================

idCurve_CatmullRomSpline<idVec1> *__fastcall idCurve_CatmullRomSpline<idVec1>::GetCurrentValue(
        idCurve_CatmullRomSpline<idVec1> *this,
        idCurve_CatmullRomSpline<idVec1> *result,
        double time)
{
  idCurve_CatmullRomSpline<idVec1> *v3; // r27
  double v5; // fp31
  int v6; // r29
  float *v7; // r5
  __int64 v8; // r8
  int v9; // r6
  int v10; // r28
  int v11; // r31
  int *p_size; // r29
  double v13; // fp31
  idCurve_Spline<idVec1> *v14; // r3
  idCurve_Spline<idVec1> v16; // [sp+50h] [-60h] BYREF

  v3 = this;
  if ( result->times.num == 1 )
  {
    this->__vftable = (idCurve_CatmullRomSpline<idVec1>_vtbl *)LODWORD(result->values.list->x);
  }
  else
  {
    v5 = idCurve_Spline<idVec1>::ClampedTime(this: result, t: time);
    v6 = idCurve<idVec3>::IndexForTime(this: result, time: v5);
    idCurve_CatmullRomSpline<idVec3>::Basis(
      this: result,
      index: v6 - 1,
      t: v5,
      bvals: v7,
      a5: (float *)&v16.times.granularity);
    v10 = v6 - 2;
    v11 = 0;
    p_size = &v16.times.size;
    v13 = 0.0;
    do
    {
      v14 = idCurve_Spline<idVec1>::ValueForIndex(this: &v16, (idVec1 *)result, index: v10 + v11++, a4: v9, a5: v8);
      v13 = (float)((float)(*(float *)&v14->__vftable * *(float *)++p_size) + (float)v13);
    }
    while ( v11 < 4 );
    *(float *)&v16.__vftable = v13;
    v3->__vftable = (idCurve_CatmullRomSpline<idVec1>_vtbl *)v16.__vftable;
    return v3;
  }
  return this;
}


// ========================================================================
// ??0?$idCurve@VidVec1@@@@QAA@XZ
// EA  : 0x82630FF8
// RVA : 0x00630FF8
// PDB : w:\tech5\shared\idlib\math\curve.h
// ========================================================================

idCurve<idVec1> *__fastcall idCurve<idVec1>::idCurve<idVec1>(idCurve<idVec1> *this)
{
  this->__vftable = (idCurve<idVec1>_vtbl *)&idCurve<idVec1>::`vftable';
  this->times.list = nullptr;
  this->times.granularity = 0;
  this->times.memTag = 116;
  this->times.listStatic = 0;
  this->times.size = 0;
  this->times.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->times);
  this->values.list = nullptr;
  this->values.granularity = 0;
  this->values.memTag = 116;
  this->values.listStatic = 0;
  this->values.size = 0;
  this->values.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->values);
  this->changed = false;
  this->currentIndex = -1;
  return this;
}


// ========================================================================
// __unwind$224432
// EA  : 0x8263107C
// RVA : 0x0063107C
// PDB : w:\tech5\shared\idlib\math\curve.h
// ========================================================================

void _unwind_224432()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 4));
}


// ========================================================================
// ?RombergIntegral@?$idCurve@VidVec1@@@@IBAMMMH@Z
// EA  : 0x826310A8
// RVA : 0x006310A8
// PDB : w:\tech5\shared\idlib\math\curve.h
// ========================================================================

float __fastcall idCurve<idVec1>::RombergIntegral(
        idCurve<idVec1> *this,
        double t0,
        double t1,
        const int order,
        int a5,
        int a6)
{
  double v8; // fp30
  idVec1 *(__fastcall *GetCurrentFirstDerivative)(idCurve<idVec1> *, idVec1 *, const float); // r11
  double v12; // fp31
  int v13; // r30
  int v14; // r28
  double v15; // fp27
  double v16; // fp31
  int i; // r31
  int v18; // r10
  int v19; // r11
  double v20; // fp13
  double v21; // fp10
  double v22; // fp9
  double v23; // fp8
  double v24; // fp7
  double v25; // fp6
  double v26; // fp5
  double v27; // fp4
  double v28; // fp3
  double v29; // fp2
  double v30; // fp1
  double v31; // fp13
  int v32; // r11
  int v33; // ctr
  int v34; // r10
  float *v35; // r11
  double v36; // fp13
  double v37; // fp12
  double v38; // fp11
  double v39; // fp1
  float v41; // [sp+50h] [-150h] BYREF
  float v42; // [sp+54h] [-14Ch] BYREF
  float v43[2]; // [sp+58h] [-148h] BYREF
  float v44; // [sp+60h] [-140h] BYREF
  float v45; // [sp+64h] [-13Ch] BYREF
  float v46; // [sp+68h] [-138h] BYREF
  float v47; // [sp+6Ch] [-134h] BYREF
  float v48[8]; // [sp+70h] [-130h] BYREF
  float v49; // [sp+90h] [-110h] BYREF
  float v50; // [sp+94h] [-10Ch] BYREF
  float v51; // [sp+98h] [-108h] BYREF
  float v52; // [sp+9Ch] [-104h] BYREF
  float v53[7]; // [sp+A0h] [-100h] BYREF
  char v54; // [sp+BCh] [-E4h] BYREF
  float v55[10]; // [sp+C0h] [-E0h] BYREF
  float v56[34]; // [sp+E8h] [-B8h] BYREF

  v8 = (float)((float)t1 - (float)t0);
  GetCurrentFirstDerivative = (idVec1 *(__fastcall *)(idCurve<idVec1> *, idVec1 *, const float))this->GetCurrentFirstDerivative;
  v44 = 1.0;
  v45 = 4.0;
  v46 = 16.0;
  v47 = 64.0;
  v48[0] = 256.0;
  v48[1] = 1024.0;
  v48[2] = 4096.0;
  v48[3] = 16384.0;
  v48[4] = 65536.0;
  v48[5] = 262144.0;
  v48[6] = 1048576.0;
  v49 = 1.0;
  v50 = 0.33333334;
  v51 = 0.06666667;
  v52 = 0.015873017;
  v53[0] = 0.0039215689;
  v53[1] = 0.00097751711;
  v53[2] = 0.00024420026;
  v53[3] = 0.000061038882;
  v53[4] = 0.000015259022;
  v53[5] = 0.0000038147118;
  v53[6] = 0.00000095367523;
  ((void (__fastcall *)(float *, idCurve<idVec1> *))GetCurrentFirstDerivative)(a1: v43, a2: this);
  v12 = __fsqrts((float)(v43[0] * v43[0]));
  this->GetCurrentFirstDerivative(this: (idCurve<idVec1> *)&v42, result: (idVec1 *)this, a3: t1);
  v13 = 2;
  v14 = 1;
  for ( v55[0] = (float)((float)((float)__fsqrts((float)(v42 * v42)) + (float)v12) * (float)v8) * (float)0.5;
        v13 <= a6;
        v14 *= 2 )
  {
    v15 = 0.0;
    v16 = 0.5;
    if ( v14 >= 1 )
    {
      for ( i = v14; i != 0; --i )
      {
        this->GetCurrentFirstDerivative(
          this: (idCurve<idVec1> *)&v41,
          result: (idVec1 *)this,
          a3: (float)((float)((float)v16 * (float)v8) + (float)t0));
        v16 = (float)((float)v16 + (float)1.0);
        v15 = (float)((float)__fsqrts((float)(v41 * v41)) + (float)v15);
      }
    }
    v18 = 1;
    v56[0] = (float)((float)((float)v15 * (float)v8) + v55[0]) * (float)0.5;
    if ( v13 > 1 )
    {
      if ( v13 - 3 + 2 >= 4 )
      {
        v19 = 0;
        do
        {
          v20 = *(float *)((char *)&v50 + v19 * 4);
          v21 = (float)((float)(*(float *)((char *)&v45 + v19 * 4) * v56[v19]) - v56[v19 - 10]);
          v22 = *(float *)((char *)&v46 + v19 * 4);
          v23 = v55[v19 + 1];
          v24 = *(float *)((char *)&v51 + v19 * 4);
          v25 = v48[v19 - 1];
          v26 = v55[v19 + 2];
          v27 = v53[v19 - 1];
          v28 = v48[v19];
          v29 = v55[v19 + 3];
          v30 = v53[v19];
          v18 += 4;
          v56[v19 + 1] = (float)((float)(*(float *)((char *)&v45 + v19 * 4) * v56[v19]) - v56[v19 - 10])
                       * *(float *)((char *)&v50 + v19 * 4);
          v31 = (float)((float)((float)v22 * (float)((float)v21 * (float)v20)) - (float)v23);
          v56[v19 + 2] = (float)v31 * (float)v24;
          v56[v19 + 3] = (float)((float)((float)v25 * (float)((float)v31 * (float)v24)) - (float)v26) * (float)v27;
          v56[v19 + 4] = (float)((float)((float)v28
                                       * (float)((float)((float)((float)v25 * (float)((float)v31 * (float)v24))
                                                       - (float)v26)
                                               * (float)v27))
                               - (float)v29)
                       * (float)v30;
          v19 += 4;
        }
        while ( v18 < v13 - 3 );
      }
      if ( v18 < v13 )
      {
        v32 = v18;
        v33 = v13 - v18;
        do
        {
          v56[v32] = (float)((float)(*(float *)((char *)&v44 + v32 * 4) * v55[v32 + 9]) - v55[v32 - 1])
                   * *(float *)((char *)&v49 + v32 * 4);
          ++v32;
          --v33;
        }
        while ( v33 != 0 );
      }
    }
    v34 = 0;
    if ( v13 >= 4 )
    {
      v35 = (float *)&v54;
      do
      {
        v34 += 4;
        v36 = v35[12];
        v37 = v35[13];
        v38 = v35[14];
        v35[1] = v35[11];
        v35[2] = v36;
        v35[3] = v37;
        v35 += 4;
        *v35 = v38;
      }
      while ( v34 < v13 - 3 );
    }
    if ( v34 < v13 )
      blkmov(a1: &v55[v34], a2: &v56[v34], a3: 4 * (v13 - v34));
    ++v13;
    v8 = (float)((float)v8 * (float)0.5);
  }
  v39 = v55[a6 - 1];
  return *((float *)&v39 + 1);
}


// ========================================================================
// ?GetLengthForTime@?$idCurve@VidVec1@@@@UBAMM@Z
// EA  : 0x82631F68
// RVA : 0x00631F68
// PDB : w:\tech5\shared\idlib\math\curve.h
// ========================================================================

float __fastcall idCurve<idVec1>::GetLengthForTime(idCurve<idVec1> *this, double time)
{
  double v4; // fp31
  int v5; // r5
  int v6; // r4
  int v7; // r3
  int v8; // r28
  int v9; // r30
  int i; // r31
  double v11; // fp1

  v4 = 0.0;
  v7 = idCurve<idVec3>::IndexForTime(this, time);
  v8 = v7;
  if ( v7 > 0 )
  {
    v9 = 0;
    for ( i = v7; i != 0; --i )
    {
      v4 = (float)(idCurve<idVec1>::RombergIntegral(
                     this,
                     t0: this->times.list[v9],
                     t1: this->times.list[v9 + 1],
                     order: v6,
                     a5: v5,
                     a6: 5)
                 + (float)v4);
      ++v9;
    }
  }
  v11 = (float)(idCurve<idVec1>::RombergIntegral(this, t0: this->times.list[v8], t1: time, order: v6, a5: v5, a6: 5)
              + (float)v4);
  return *((float *)&v11 + 1);
}


// ========================================================================
// ?GetCloseTime@?$idCurve_Spline@VidAngles@@@@UAAMXZ
// EA  : 0x82632000
// RVA : 0x00632000
// PDB : w:\tech5\shared\idlib\math\curve.h
// ========================================================================

float __fastcall idCurve_Spline<idAngles>::GetCloseTime(idCurve_Spline<idVec1> *this)
{
  double closeTime; // fp1

  if ( this->boundaryType == CLOSED )
    closeTime = this->closeTime;
  else
    closeTime = 0.0;
  return *((float *)&closeTime + 1);
}


// ========================================================================
// ??0?$idCurve_CatmullRomSpline@VidVec1@@@@QAA@XZ
// EA  : 0x82632020
// RVA : 0x00632020
// PDB : w:\tech5\shared\idlib\math\curve.h
// ========================================================================

idCurve_CatmullRomSpline<idVec1> *__fastcall idCurve_CatmullRomSpline<idVec1>::idCurve_CatmullRomSpline<idVec1>(
        idCurve_CatmullRomSpline<idVec1> *this)
{
  idCurve<idVec1>::idCurve<idVec1>(this);
  this->boundaryType = 0;
  this->__vftable = (idCurve_CatmullRomSpline<idVec1>_vtbl *)&idCurve_CatmullRomSpline<idVec1>::`vftable';
  this->closeTime = 0.0;
  return this;
}


// ========================================================================
// ?GetCurrentFirstDerivative@?$idCurve_CatmullRomSpline@VidVec1@@@@UBA?AVidVec1@@M@Z
// EA  : 0x82632070
// RVA : 0x00632070
// PDB : w:\tech5\shared\idlib\math\curve.h
// ========================================================================

idCurve_CatmullRomSpline<idVec1> *__fastcall idCurve_CatmullRomSpline<idVec1>::GetCurrentFirstDerivative(
        idCurve_CatmullRomSpline<idVec1> *this,
        idCurve_CatmullRomSpline<idVec1> *result,
        double time)
{
  idCurve_CatmullRomSpline<idVec1> *v3; // r25
  double v5; // fp31
  int v6; // r3
  int v7; // r26
  int v8; // r28
  float *v9; // r5
  __int64 v10; // r8
  int v11; // r6
  int v12; // r30
  int v13; // r27
  int *p_size; // r29
  double v15; // fp31
  idCurve_Spline<idVec1> *v16; // r3
  double v17; // fp30
  double v18; // fp1
  idCurve_Spline<idVec1> v20[2]; // [sp+50h] [-70h] BYREF

  v3 = this;
  if ( result->times.num == 1 )
  {
    *(float *)&this->__vftable = 0.0;
  }
  else
  {
    v5 = idCurve_Spline<idVec1>::ClampedTime(this: result, t: time);
    v6 = idCurve<idVec3>::IndexForTime(this: result, time: v5);
    v7 = v6 - 1;
    v8 = v6;
    v12 = 0;
    v13 = v6 - 2;
    idCurve_CatmullRomSpline<idAngles>::BasisFirstDerivative(this: result, index: v6 - 1, t: v5, bvals: v9);
    p_size = &v20[0].times.size;
    v15 = 0.0;
    do
    {
      v16 = idCurve_Spline<idVec1>::ValueForIndex(this: v20, (idVec1 *)result, index: v13 + v12++, a4: v11, a5: v10);
      v15 = (float)((float)(*(float *)++p_size * *(float *)&v16->__vftable) + (float)v15);
    }
    while ( v12 < 4 );
    v17 = idCurve_Spline<idAngles>::TimeForIndex(this: result, index: v8);
    v18 = idCurve_Spline<idAngles>::TimeForIndex(this: result, index: v7);
    *(float *)&v3->__vftable = (float)v15 / (float)((float)v17 - (float)v18);
    return v3;
  }
  return this;
}


// ========================================================================
// ?GetCurrentSecondDerivative@?$idCurve_CatmullRomSpline@VidVec1@@@@UBA?AVidVec1@@M@Z
// EA  : 0x82632160
// RVA : 0x00632160
// PDB : w:\tech5\shared\idlib\math\curve.h
// ========================================================================

idCurve_CatmullRomSpline<idVec1> *__fastcall idCurve_CatmullRomSpline<idVec1>::GetCurrentSecondDerivative(
        idCurve_CatmullRomSpline<idVec1> *this,
        idCurve_CatmullRomSpline<idVec1> *result,
        double time)
{
  idCurve_CatmullRomSpline<idVec1> *v3; // r25
  double v5; // fp31
  int v6; // r3
  int v7; // r26
  int v8; // r28
  float *v9; // r5
  __int64 v10; // r8
  int v11; // r6
  int v12; // r30
  int v13; // r27
  int *p_size; // r29
  double v15; // fp31
  idCurve_Spline<idVec1> *v16; // r3
  double v17; // fp30
  double v18; // fp1
  idCurve_Spline<idVec1> v20[2]; // [sp+50h] [-70h] BYREF

  v3 = this;
  if ( result->times.num == 1 )
  {
    *(float *)&this->__vftable = 0.0;
  }
  else
  {
    v5 = idCurve_Spline<idVec1>::ClampedTime(this: result, t: time);
    v6 = idCurve<idVec3>::IndexForTime(this: result, time: v5);
    v7 = v6 - 1;
    v8 = v6;
    v12 = 0;
    v13 = v6 - 2;
    idCurve_CatmullRomSpline<idAngles>::BasisSecondDerivative(this: result, index: v6 - 1, t: v5, bvals: v9);
    p_size = &v20[0].times.size;
    v15 = 0.0;
    do
    {
      v16 = idCurve_Spline<idVec1>::ValueForIndex(this: v20, (idVec1 *)result, index: v13 + v12++, a4: v11, a5: v10);
      v15 = (float)((float)(*(float *)++p_size * *(float *)&v16->__vftable) + (float)v15);
    }
    while ( v12 < 4 );
    v17 = idCurve_Spline<idAngles>::TimeForIndex(this: result, index: v8);
    v18 = idCurve_Spline<idAngles>::TimeForIndex(this: result, index: v7);
    *(float *)&v3->__vftable = (float)v15 / (float)((float)((float)v17 - (float)v18) * (float)((float)v17 - (float)v18));
    return v3;
  }
  return this;
}


// ========================================================================
// ?CreateNewCurve@?$idCurve_CatmullRomSpline@VidVec1@@@@MBAPAV?$idCurve@VidVec1@@@@XZ
// EA  : 0x82632F08
// RVA : 0x00632F08
// PDB : w:\tech5\shared\idlib\math\curve.h
// ========================================================================

idCurve<idVec1> *__fastcall idCurve_CatmullRomSpline<idVec1>::CreateNewCurve(idCurve_CatmullRomSpline<idVec1> *this)
{
  idCurve<idVec1> *v1; // r3
  idCurve<idVec1> *v2; // r30

  v1 = (idCurve<idVec1> *)idMem::AllocWithLocation(
                            this: &mem,
                            location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                            size: 0x34u,
                            tag: TAG_TABLE,
                            zeroBuffer: false,
                            align: ALIGN_16,
                            heap: HEAP_DEFAULTHEAP);
  v2 = v1;
  if ( v1 == nullptr )
    return nullptr;
  idCurve<idVec1>::idCurve<idVec1>(this: v1);
  v2[1].__vftable = nullptr;
  v2->__vftable = (idCurve<idVec1>_vtbl *)&idCurve_CatmullRomSpline<idVec1>::`vftable';
  *(float *)&v2[1].times.list = 0.0;
  return v2;
}


// ========================================================================
// __unwind$226328
// EA  : 0x82632FA0
// RVA : 0x00632FA0
// PDB : w:\tech5\shared\idlib\math\curve.h
// ========================================================================

void _unwind_226328()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_TABLE);
}


// ========================================================================
// ?SetNumValues@?$idCurve@VidVec1@@@@UAAXH@Z
// EA  : 0x82634D60
// RVA : 0x00634D60
// PDB : w:\tech5\shared\idlib\math\curve.h
// ========================================================================

void __fastcall idCurve<idVec1>::SetNumValues(idCurve<idVec1> *this, int num)
{
  idList<idVec1,116> *p_values; // r30
  int size; // r11
  int v6; // r11

  p_values = &this->values;
  if ( num <= this->values.size
    || idList<idNavSpline *,5>::Resize(this: (idList<idSpawnArea::GeneratedPosition *,5> *)&this->values, newsize: num) )
  {
    size = p_values->size;
    if ( num < size )
      size = num;
    p_values->num = size;
  }
  if ( num <= this->times.size
    || (unsigned __int8)idList<float,116>::Resize(this: (idList<float,13> *)&this->times, newsize: num) != 0 )
  {
    v6 = this->times.size;
    if ( num < v6 )
      v6 = num;
    this->times.num = v6;
  }
}


// ========================================================================
// ?AddValue@?$idCurve@VidVec1@@@@UAAHMABVidVec1@@@Z
// EA  : 0x82634DF0
// RVA : 0x00634DF0
// PDB : w:\tech5\shared\idlib\math\curve.h
// ========================================================================

int __fastcall idCurve<idVec1>::AddValue(
        idCurve<idVec1> *this,
        double time,
        const idVec1 *value,
        const idVec1 *a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        float a12,
        float a13,
        float a14,
        float a15,
        float a16,
        float a17)
{
  int v20; // r3
  int v21; // r31

  a17 = time;
  v20 = idCurve<idVec3>::IndexForTime(this, time);
  v21 = v20;
  if ( v20 < this->times.num && this->times.list[v20] < time )
    v21 = v20 + 1;
  idList<float,116>::Insert(this: &this->times, obj: &a17, index: v21);
  idList<idVec1,116>::Insert(this: &this->values, obj: a4, index: v21);
  this->changed = true;
  return v21;
}


// ========================================================================
// ?GetLengthBetweenKnots@?$idCurve@VidVec3@@@@QBAMHH@Z
// EA  : 0x8274DB88
// RVA : 0x0074DB88
// PDB : w:\tech5\shared\idlib\math\curve.h
// ========================================================================

float __fastcall idCurve<idVec3>::GetLengthBetweenKnots(idCurve<idVec3> *this, int i0, int i1)
{
  double v4; // fp31
  int v5; // r30
  int v6; // r31
  double v7; // fp1

  v4 = 0.0;
  if ( i0 < i1 )
  {
    v5 = i0;
    v6 = i1 - i0;
    do
    {
      --v6;
      v4 = (float)(idCurve<idVec3>::RombergIntegral(
                     this,
                     t0: this->times.list[v5],
                     t1: this->times.list[v5 + 1],
                     order: i0)
                 + (float)v4);
      ++v5;
    }
    while ( v6 != 0 );
  }
  v7 = v4;
  return *((float *)&v7 + 1);
}


// ========================================================================
// ?GetTimeForLength@?$idCurve@VidVec3@@@@QBAMMM@Z
// EA  : 0x82750480
// RVA : 0x00750480
// PDB : w:\tech5\shared\idlib\math\curve.h
// ========================================================================

float __fastcall idCurve<idVec3>::GetTimeForLength(idCurve<idVec3> *this, double length, double epsilon)
{
  double v6; // fp31
  double v7; // fp1
  int v8; // r10
  int v9; // r29
  int v10; // r12
  char *v11; // r4
  float *v12; // r27
  int v13; // r28
  double v14; // fp0
  double v15; // fp29
  float *v16; // r11
  int v17; // r29
  int v18; // r28
  double v19; // fp31
  double v20; // fp30
  _DWORD back_chain[20]; // [sp+0h] [-C0h]
  float v23[3]; // [sp+50h] [-70h] BYREF
  char v24; // [sp+5Fh] [-61h] BYREF

  v6 = 0.0;
  if ( length > 0.0 )
  {
    ((void (*)(void))RtlCheckStack12)();
    v9 = 0;
    *(_DWORD *)((char *)back_chain + v10) = back_chain[0];
    v11 = &v24;
    if ( v8 - 1 > 0 )
    {
      v12 = v23;
      do
      {
        v13 = v9 + 1;
        v6 = (float)(idCurve<idVec3>::GetLengthBetweenKnots(this, i0: v9, i1: v9 + 1) + (float)v6);
        *v12 = v6;
        if ( length < v6 )
          break;
        ++v9;
        ++v12;
      }
      while ( v13 < this->values.num - 1 );
    }
    if ( v9 < this->values.num - 1 )
    {
      if ( v9 != 0 )
      {
        v16 = &v23[v9];
        v15 = (float)((float)length - *(v16 - 1));
        v14 = (float)(*v16 - *(v16 - 1));
      }
      else
      {
        v14 = v23[0];
        v15 = length;
      }
      v17 = v9;
      v18 = 0;
      v19 = (float)((float)((float)(this->times.list[v17 + 1] - this->times.list[v17]) / (float)v14) * (float)v15);
      do
      {
        v20 = (float)(idCurve<idVec3>::RombergIntegral(
                        this,
                        t0: this->times.list[v17],
                        t1: (float)((float)v19 + this->times.list[v17]),
                        order: (const int)v11)
                    - (float)v15);
        if ( __fabs(v20) <= epsilon )
          break;
        this->GetCurrentFirstDerivative(
          this: (idCurve<idVec3> *)v23,
          result: (idVec3 *)this,
          a3: (float)(this->times.list[v17] + (float)v19));
        ++v18;
        v19 = (float)((float)v19
                    - (float)((float)v20
                            / (float)__fsqrts((float)((float)(v23[2] * v23[2])
                                                    + (float)((float)(v23[0] * v23[0]) + (float)(v23[1] * v23[1]))))));
      }
      while ( v18 < 32 );
      v7 = (float)(this->times.list[v17] + (float)v19);
    }
    else
    {
      v7 = this->times.list[this->times.num - 1];
    }
  }
  else
  {
    v7 = *this->times.list;
  }
  return *((float *)&v7 + 1);
}


// ========================================================================
// ?GetBatchValues@?$idCurve@VidVec3@@@@QBAXQBMQAVidVec3@@1H@Z
// EA  : 0x82750670
// RVA : 0x00750670
// PDB : w:\tech5\shared\idlib\math\curve.h
// ========================================================================

void __fastcall idCurve<idVec3>::GetBatchValues(
        idCurve<idVec3> *this,
        const float *lengths,
        idVec3 *origins,
        idVec3 *derivatives,
        int num)
{
  int v10; // r10
  int v11; // r4
  int v12; // r12
  double v13; // fp31
  float *v14; // r28
  int v15; // r29
  int v16; // r29
  float *p_y; // r22
  float *p_z; // r26
  int v19; // r23
  int v20; // r24
  int v21; // r10
  double v22; // fp0
  float *v23; // r11
  float *v24; // r11
  double v25; // fp30
  double v26; // fp29
  double v27; // fp0
  float *v28; // r11
  int v29; // r27
  double v30; // fp31
  double v31; // fp30
  idVec3 *v32; // r3
  idVec3 *v33; // r3
  _DWORD back_chain[20]; // [sp+0h] [-110h]
  float v35[4]; // [sp+50h] [-C0h] BYREF
  int v36; // [sp+60h] [-B0h] BYREF
  int v37; // [sp+70h] [-A0h] BYREF

  ((void (*)(void))RtlCheckStack12)();
  v11 = 0;
  *(_DWORD *)((char *)back_chain + v12) = back_chain[0];
  v13 = 0.0;
  if ( v10 - 1 > 0 )
  {
    v14 = v35;
    do
    {
      v15 = v11 + 1;
      v13 = (float)(idCurve<idVec3>::GetLengthBetweenKnots(this, i0: v11, i1: v11 + 1) + (float)v13);
      *v14 = v13;
      if ( lengths[num - 1] < v13 )
        break;
      v11 = v15;
      ++v14;
    }
    while ( v15 < this->values.num - 1 );
  }
  v16 = 0;
  if ( num > 0 )
  {
    p_y = &derivatives[-1].y;
    p_z = &origins->z;
    v19 = (char *)derivatives - (char *)origins;
    v20 = num;
    do
    {
      v21 = this->values.num - 1;
      if ( v16 < v21 )
      {
        if ( v21 - v16 < 4 )
        {
LABEL_15:
          if ( v16 >= v21 )
            goto LABEL_24;
          v24 = &v35[v16];
          do
          {
            if ( *lengths < (double)*v24 )
              break;
            ++v16;
            ++v24;
          }
          while ( v16 < v21 );
        }
        else
        {
          v22 = *lengths;
          v23 = &v35[v16 + 2];
          while ( v22 >= *(v23 - 2) )
          {
            if ( v22 < *(v23 - 1) )
            {
              ++v16;
              break;
            }
            if ( v22 < *v23 )
            {
              v16 += 2;
              break;
            }
            if ( v22 < v23[1] )
            {
              v16 += 3;
              break;
            }
            v16 += 4;
            v23 += 4;
            if ( v16 >= this->values.num - 4 )
              goto LABEL_15;
          }
        }
        if ( v16 < v21 )
        {
          if ( v16 != 0 )
          {
            v28 = &v35[v16];
            v26 = (float)(*lengths - *(v28 - 1));
            v27 = (float)(*v28 - *(v28 - 1));
          }
          else
          {
            v26 = *lengths;
            v27 = v35[0];
          }
          v29 = 0;
          v30 = (float)((float)((float)(this->times.list[v16 + 1] - this->times.list[v16]) / (float)v27) * (float)v26);
          while ( 1 )
          {
            v31 = (float)(idCurve<idVec3>::RombergIntegral(
                            this,
                            t0: this->times.list[v16],
                            t1: (float)(this->times.list[v16] + (float)v30),
                            order: v11)
                        - (float)v26);
            if ( __fabs(v31) <= 0.1 )
              break;
            this->GetCurrentFirstDerivative(
              this: (idCurve<idVec3> *)v35,
              result: (idVec3 *)this,
              a3: (float)(this->times.list[v16] + (float)v30));
            ++v29;
            v30 = (float)((float)v30
                        - (float)((float)v31
                                / (float)__fsqrts((float)((float)(v35[2] * v35[2])
                                                        + (float)((float)(v35[0] * v35[0]) + (float)(v35[1] * v35[1]))))));
            if ( v29 >= 32 )
              goto LABEL_33;
          }
          v25 = (float)(this->times.list[v16] + (float)v30);
          if ( v25 >= 0.0 )
            goto LABEL_34;
LABEL_33:
          v25 = (float)(this->times.list[v16] + (float)v30);
          goto LABEL_34;
        }
      }
LABEL_24:
      v25 = this->times.list[this->times.num - 1];
LABEL_34:
      v32 = this->GetCurrentValue(this: &v36, result: this, a3: v25);
      *(p_z - 2) = v32->x;
      *(p_z - 1) = v32->y;
      *p_z = v32->z;
      v33 = this->GetCurrentFirstDerivative(this: &v37, result: this, a3: v25);
      --v20;
      p_y[2] = v33->x;
      ++lengths;
      p_y += 3;
      *p_y = v33->y;
      *(float *)((char *)p_z + v19) = v33->z;
      p_z += 3;
    }
    while ( v20 != 0 );
  }
}


// ========================================================================
// ?IndexForTime@?$idCurve@VidVec3@@@@IBAHM@Z
// EA  : 0x827F8538
// RVA : 0x007F8538
// PDB : w:\tech5\shared\idlib\math\curve.h
// ========================================================================

int __fastcall idCurve<idVec3>::IndexForTime(idCurve<idVec1> *this, double time)
{
  int result; // r3
  int num; // r9
  float *v5; // r11
  double v6; // fp0
  int v7; // r11
  int v8; // r8
  int v9; // r9
  int v10; // r10
  int v11; // r9
  double v12; // fp0

  result = this->currentIndex;
  if ( result >= 0 )
  {
    num = this->times.num;
    if ( result <= num )
    {
      if ( result != 0 )
      {
        v5 = &this->times.list[result];
        v6 = *(v5 - 1);
        if ( result == num )
        {
          if ( time > v6 )
            return result;
        }
        else
        {
          if ( time > v6 && time <= *v5 )
            return result;
          if ( time > *v5 && (++result == num || time <= v5[1]) )
          {
LABEL_21:
            this->currentIndex = result;
            return result;
          }
        }
      }
      else if ( time <= *this->times.list )
      {
        return result;
      }
    }
  }
  v7 = this->times.num;
  v8 = 0;
  v9 = 0;
  if ( v7 <= 0 )
  {
LABEL_20:
    result = v9 + v8;
    goto LABEL_21;
  }
  while ( 1 )
  {
    v10 = v7 >> 1;
    v11 = v8 + (v7 >> 1);
    v12 = this->times.list[v11];
    if ( time == v12 )
      return v8 + (v7 >> 1);
    v7 -= v10;
    if ( time <= v12 )
    {
      v9 = 0;
    }
    else
    {
      v8 = v11;
      v9 = 1;
    }
    if ( v10 <= 0 )
      goto LABEL_20;
  }
}


// ========================================================================
// ??1?$idCurve@VidVec3@@@@UAA@XZ
// EA  : 0x827F8F38
// RVA : 0x007F8F38
// PDB : w:\tech5\shared\idlib\math\curve.h
// ========================================================================

void __fastcall idCurve<idVec3>::~idCurve<idVec3>(idCurve<idVec3> *this)
{
  this->__vftable = (idCurve<idVec3>_vtbl *)&idCurve<idVec3>::`vftable';
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->values);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->times);
}


// ========================================================================
// __unwind$227056
// EA  : 0x827F8F8C
// RVA : 0x007F8F8C
// PDB : w:\tech5\shared\idlib\math\curve.h
// ========================================================================

void _unwind_227056()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 4));
}


// ========================================================================
// ?RemoveIndex@?$idCurve@VidVec3@@@@UAAXH@Z
// EA  : 0x827F8FB8
// RVA : 0x007F8FB8
// PDB : w:\tech5\shared\idlib\math\curve.h
// ========================================================================

void __fastcall idCurve<idVec3>::RemoveIndex(idCurve<idVec3> *this, int index)
{
  idList<idAngles,5>::RemoveIndex(this: &this->values, index);
  idList<float,5>::RemoveIndex(this: &this->times, index);
  this->changed = true;
}


// ========================================================================
// ??0?$idCurve@VidVec3@@@@QAA@XZ
// EA  : 0x827F9010
// RVA : 0x007F9010
// PDB : w:\tech5\shared\idlib\math\curve.h
// ========================================================================

idCurve<idVec3> *__fastcall idCurve<idVec3>::idCurve<idVec3>(idCurve<idVec3> *this)
{
  this->__vftable = (idCurve<idVec3>_vtbl *)&idCurve<idVec3>::`vftable';
  this->times.list = nullptr;
  this->times.granularity = 0;
  this->times.memTag = 116;
  this->times.listStatic = 0;
  this->times.size = 0;
  this->times.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->times);
  this->values.list = nullptr;
  this->values.granularity = 0;
  this->values.memTag = 116;
  this->values.listStatic = 0;
  this->values.size = 0;
  this->values.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->values);
  this->changed = false;
  this->currentIndex = -1;
  return this;
}


// ========================================================================
// __unwind$227301
// EA  : 0x827F9094
// RVA : 0x007F9094
// PDB : w:\tech5\shared\idlib\math\curve.h
// ========================================================================

void _unwind_227301()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 4));
}


// ========================================================================
// ?TimeForIndex@?$idCurve_Spline@VidAngles@@@@IBAMH@Z
// EA  : 0x827F94F8
// RVA : 0x007F94F8
// PDB : w:\tech5\shared\idlib\math\curve.h
// ========================================================================

// local variable allocation has failed, the output may be wrong!
float __fastcall idCurve_Spline<idAngles>::TimeForIndex(
        idCurve_Spline<idVec1> *this,
        const int index,
        int a3,
        __int64 a4)
{
  int v4; // r2 OVERLAPPED
  int v5; // r10
  signed int v6; // r11
  float *v7; // r7
  int v8; // r3
  double v9; // fp12
  int v10; // r6
  double v11; // fp7
  double v12; // fp1
  __int64 v13; // r11
  signed int num; // r9
  float *list; // r7
  int v16; // r3
  double v17; // fp12
  double v18; // fp11

  v5 = this->times.num - 1;
  if ( index >= 0 )
  {
    if ( index <= v5 )
    {
      v12 = this->times.list[index];
    }
    else if ( this->boundaryType == CLOSED )
    {
      num = this->times.num;
      list = this->times.list;
      v17 = (float)(list[v5] + this->closeTime);
      v16 = index / num;
      v18 = list[index % num];
      __twllei(num, 0);
      __twllei(num, 0);
      __twlgei(num & ~(__ROL4__(index, 1) - 1), 0xFFFFFFFF);
      __twlgei(num & ~(__ROL4__(index, 1) - 1), 0xFFFFFFFF);
      v12 = (float)((float)((float)v17 * (float)*(__int64 *)(&v4 - 1)) + (float)v18);
    }
    else
    {
      LODWORD(a4) = index - v5;
      v12 = (float)((float)((float)(this->times.list[v5] - this->times.list[v5 - 1]) * (float)a4) + this->times.list[v5]);
    }
  }
  else if ( this->boundaryType == CLOSED )
  {
    v6 = this->times.num;
    v7 = this->times.list;
    v9 = (float)(v7[v5] + this->closeTime);
    v10 = index % v6 + v6;
    v11 = (float)((float)(v7[v5] + this->closeTime) - v7[v10 % v6]);
    v8 = index / v6;
    __twllei(v6, 0);
    __twllei(v6, 0);
    __twllei(v6, 0);
    __twlgei(v6 & ~(__ROL4__(index, 1) - 1), 0xFFFFFFFF);
    __twlgei(v6 & ~(__ROL4__(index, 1) - 1), 0xFFFFFFFF);
    __twlgei(v6 & ~(__ROL4__(v10, 1) - 1), 0xFFFFFFFF);
    v12 = (float)((float)((float)*(__int64 *)(&v4 - 1) * (float)v9) - (float)v11);
  }
  else
  {
    LODWORD(v13) = index;
    HIDWORD(v13) = this->times.list;
    v12 = (float)((float)((float)(*(float *)(HIDWORD(v13) + 4) - *(float *)HIDWORD(v13)) * (float)v13)
                + *(float *)HIDWORD(v13));
  }
  return *((float *)&v12 + 1);
}


// ========================================================================
// ??0?$idCurve_NonUniformBSpline@VidVec3@@@@QAA@XZ
// EA  : 0x827F97E0
// RVA : 0x007F97E0
// PDB : w:\tech5\shared\idlib\math\curve.h
// ========================================================================

idCurve_NonUniformBSpline<idVec3> *__fastcall idCurve_NonUniformBSpline<idVec3>::idCurve_NonUniformBSpline<idVec3>(
        idCurve_NonUniformBSpline<idVec3> *this)
{
  idCurve<idVec3>::idCurve<idVec3>(this);
  this->boundaryType = 0;
  this->__vftable = (idCurve_NonUniformBSpline<idVec3>_vtbl *)&idCurve_NonUniformBSpline<idVec3>::`vftable';
  this->closeTime = 0.0;
  this->order = 4;
  return this;
}


// ========================================================================
// ?BasisSecondDerivative@?$idCurve_NonUniformBSpline@VidVec3@@@@IBAXHHMPAM@Z
// EA  : 0x827F9838
// RVA : 0x007F9838
// PDB : w:\tech5\shared\idlib\math\curve.h
// ========================================================================

void __fastcall idCurve_NonUniformBSpline<idVec3>::BasisSecondDerivative(
        idCurve_NonUniformBSpline<idVec3> *this,
        int index,
        const int order,
        double t,
        float *bvals,
        float *a6)
{
  int v6; // r29
  __int64 v11; // r10
  __int64 v12; // r8
  int v13; // r5
  int v14; // r31
  double v15; // fp31
  float *v16; // r30
  double v17; // fp30
  double v18; // fp29
  __int64 v19; // r8
  int v20; // r5
  double v21; // fp1
  double v22; // fp31
  __int64 v23; // r8
  int v24; // r5
  __int64 v25; // [sp+50h] [-70h]

  v6 = order - 1;
  idCurve_NonUniformBSpline<idAngles>::BasisFirstDerivative(this, index, order: order - 1, t, bvals);
  v14 = 0;
  *a6 = 0.0;
  if ( v6 > 0 )
  {
    LODWORD(v11) = v6;
    v15 = (float)v11;
    v16 = a6 - 1;
    do
    {
      v17 = (float)(v16[1] - v16[2]);
      v16[1] = v16[1] - v16[2];
      v18 = idCurve_Spline<idAngles>::TimeForIndex(
              (idCurve_Spline<idVec1> *)this,
              index: index + order - 3 + v14,
              a3: v13,
              a4: v12);
      v21 = idCurve_Spline<idAngles>::TimeForIndex(
              (idCurve_Spline<idVec1> *)this,
              index: index - 2 + v14++,
              a3: v20,
              a4: v19);
      *++v16 = (float)((float)v15 / (float)((float)v18 - (float)v21)) * (float)v17;
    }
    while ( v14 < v6 );
  }
  LODWORD(v11) = v6;
  v25 = v11;
  v22 = idCurve_Spline<idAngles>::TimeForIndex(
          (idCurve_Spline<idVec1> *)this,
          index: v14 + index + order - 3,
          a3: v13,
          a4: v12);
  a6[v14] = (float)((float)v25
                  / (float)((float)v22
                          - idCurve_Spline<idAngles>::TimeForIndex(
                              (idCurve_Spline<idVec1> *)this,
                              index: v14 + index - 2,
                              a3: v24,
                              a4: v23)))
          * a6[v14];
}


// ========================================================================
// ?GetCurrentSecondDerivative@?$idCurve_NonUniformBSpline@VidAngles@@@@UBA?AVidAngles@@M@Z
// EA  : 0x827F9958
// RVA : 0x007F9958
// PDB : w:\tech5\shared\idlib\math\curve.h
// ========================================================================

idCurve_NonUniformBSpline<idVec3> *__fastcall idCurve_NonUniformBSpline<idAngles>::GetCurrentSecondDerivative(
        idCurve_NonUniformBSpline<idVec3> *this,
        idCurve_Spline<idVec1> *result,
        double time)
{
  idVec1 *list; // r11
  double v6; // fp8
  double v7; // fp6
  double v8; // fp31
  int v9; // r3
  int v10; // r28
  int v11; // r26
  float *v12; // r6
  idVec1 *v13; // r11
  int v14; // r31
  double v15; // fp31
  double v16; // fp30
  double v17; // fp29
  int *p_size; // r29
  idVec3 *v19; // r3
  float v21; // [sp+50h] [-A0h]
  float v22; // [sp+54h] [-9Ch]
  int v23; // [sp+58h] [-98h]
  idCurve_Spline<idVec3> v24; // [sp+60h] [-90h] BYREF

  if ( result->times.num == 1 )
  {
    list = result->values.list;
    v6 = (float)(list[1].x - list[1].x);
    v7 = (float)(list[2].x - list[2].x);
    *(float *)&this->__vftable = list->x - list->x;
    *(float *)&this->times.list = v6;
    *(float *)&this->times.num = v7;
  }
  else
  {
    v8 = idCurve_Spline<idVec1>::ClampedTime(this: result, t: time);
    v9 = idCurve<idVec3>::IndexForTime(this: result, time: v8);
    v10 = (int)result[1].__vftable;
    v11 = v9;
    idCurve_NonUniformBSpline<idVec3>::BasisSecondDerivative(
      this: (idCurve_NonUniformBSpline<idVec3> *)result,
      index: v9 - 1,
      order: v10,
      t: v8,
      bvals: v12,
      a6: (float *)&v24.times.granularity);
    v13 = result->values.list;
    v14 = 0;
    v15 = (float)(v13->x - v13->x);
    v16 = (float)(v13[1].x - v13[1].x);
    v17 = (float)(v13[2].x - v13[2].x);
    v21 = v13->x - v13->x;
    v22 = v13[1].x - v13[1].x;
    *(float *)&v23 = v13[2].x - v13[2].x;
    if ( v10 > 0 )
    {
      p_size = &v24.times.size;
      do
      {
        v19 = idCurve_Spline<idVec3>::ValueForIndex(this: &v24, (idVec3 *)result, index: v14 - (v10 >> 1) + v11);
        ++p_size;
        ++v14;
        v15 = (float)((float)(v19->x * *(float *)p_size) + (float)v15);
        v16 = (float)((float)(v19->y * *(float *)p_size) + (float)v16);
        v17 = (float)((float)(v19->z * *(float *)p_size) + (float)v17);
      }
      while ( v14 < v10 );
      *(float *)&v23 = v17;
      v22 = v16;
      v21 = v15;
    }
    *(float *)&this->__vftable = v21;
    *(float *)&this->times.list = v22;
    this->times.num = v23;
  }
  return this;
}


// ========================================================================
// ?AddValue@?$idCurve_NURBS@VidVec3@@@@UAAHMABVidVec3@@@Z
// EA  : 0x827F9AC0
// RVA : 0x007F9AC0
// PDB : w:\tech5\shared\idlib\math\curve.h
// ========================================================================

int __fastcall idCurve_NURBS<idVec3>::AddValue(
        idCurve_NURBS<idVec3> *this,
        double time,
        const idVec3 *value,
        const idVec3 *a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        float a12,
        float a13,
        float a14,
        float a15,
        float a16,
        float a17)
{
  int v19; // r29
  float v21[12]; // [sp+50h] [-30h] BYREF

  a17 = time;
  v19 = idCurve<idVec3>::IndexForTime((idCurve<idVec1> *)this, time);
  idList<float,116>::Insert(this: &this->times, obj: &a17, index: v19);
  idList<idVec3,116>::Insert(this: &this->values, obj: a4, index: v19);
  v21[0] = 1.0;
  idList<float,116>::Insert(this: &this->weights, obj: v21, index: v19);
  return v19;
}


// ========================================================================
// ?CreateNewCurve@?$idCurve_NonUniformBSpline@VidVec3@@@@MBAPAV?$idCurve@VidVec3@@@@XZ
// EA  : 0x827FAE78
// RVA : 0x007FAE78
// PDB : w:\tech5\shared\idlib\math\curve.h
// ========================================================================

idCurve<idVec3> *__fastcall idCurve_NonUniformBSpline<idVec3>::CreateNewCurve(idCurve_NonUniformBSpline<idVec3> *this)
{
  idCurve<idVec3> *v1; // r3
  idCurve<idVec3> *v2; // r30

  v1 = (idCurve<idVec3> *)idMem::AllocWithLocation(
                            this: &mem,
                            location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                            size: 0x38u,
                            tag: TAG_TABLE,
                            zeroBuffer: false,
                            align: ALIGN_16,
                            heap: HEAP_DEFAULTHEAP);
  v2 = v1;
  if ( v1 == nullptr )
    return nullptr;
  idCurve<idVec3>::idCurve<idVec3>(this: v1);
  v2[1].__vftable = nullptr;
  v2->__vftable = (idCurve<idVec3>_vtbl *)&idCurve_NonUniformBSpline<idVec3>::`vftable';
  *(float *)&v2[1].times.list = 0.0;
  v2[1].times.num = 4;
  return v2;
}


// ========================================================================
// __unwind$230341
// EA  : 0x827FAF18
// RVA : 0x007FAF18
// PDB : w:\tech5\shared\idlib\math\curve.h
// ========================================================================

void _unwind_230341()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_TABLE);
}


// ========================================================================
// ??0?$idCurve_NURBS@VidVec3@@@@QAA@XZ
// EA  : 0x827FAF50
// RVA : 0x007FAF50
// PDB : w:\tech5\shared\idlib\math\curve.h
// ========================================================================

idCurve_NURBS<idVec3> *__fastcall idCurve_NURBS<idVec3>::idCurve_NURBS<idVec3>(idCurve_NURBS<idVec3> *this)
{
  idCurve<idVec3>::idCurve<idVec3>(this);
  this->boundaryType = 0;
  this->order = 4;
  this->closeTime = 0.0;
  this->__vftable = (idCurve_NURBS<idVec3>_vtbl *)&idCurve_NURBS<idVec3>::`vftable';
  this->weights.list = nullptr;
  this->weights.granularity = 0;
  this->weights.memTag = 116;
  this->weights.listStatic = 0;
  this->weights.size = 0;
  this->weights.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->weights);
  return this;
}


// ========================================================================
// __unwind$230384_0
// EA  : 0x827FAFDC
// RVA : 0x007FAFDC
// PDB : w:\tech5\shared\idlib\math\curve.h
// ========================================================================

void _unwind_230384_0()
{
  int v0; // r12

  idCurve_NonUniformBSpline<idVec3>::~idCurve_NonUniformBSpline<idVec3>(this: *(idCurve_NonUniformBSpline<idVec3> **)(v0 - 112 + 132));
}


// ========================================================================
// ?Clear@?$idCurve_NURBS@VidAngles@@@@UAAXXZ
// EA  : 0x827FB008
// RVA : 0x007FB008
// PDB : w:\tech5\shared\idlib\math\curve.h
// ========================================================================

void __fastcall idCurve_NURBS<idAngles>::Clear(idCurve_NURBS<idVec3> *this)
{
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->values);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->times);
  this->currentIndex = -1;
  this->changed = true;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->weights);
}


// ========================================================================
// ?GetCurrentValue@?$idCurve_NURBS@VidAngles@@@@UBA?AVidAngles@@M@Z
// EA  : 0x827FB058
// RVA : 0x007FB058
// PDB : w:\tech5\shared\idlib\math\curve.h
// ========================================================================

idCurve_NURBS<idVec3> *__fastcall idCurve_NURBS<idAngles>::GetCurrentValue(
        idCurve_NURBS<idVec3> *this,
        idCurve_Spline<idVec1> *result,
        double time)
{
  float *v3; // r24
  float v5; // r11
  float *v6; // r9
  int v7; // r8
  double v8; // fp31
  int v9; // r3
  int v10; // r27
  int v11; // r25
  float *v12; // r6
  idVec1 *list; // r11
  int v14; // r31
  double v15; // fp30
  double v16; // fp31
  double v17; // fp29
  double v18; // fp28
  int v19; // r26
  int *p_size; // r28
  double v21; // fp27
  double v22; // fp27
  idVec3 *v23; // r3
  idCurve_Spline<idVec3> v25[2]; // [sp+50h] [-B0h] BYREF

  v3 = (float *)this;
  if ( result->times.num == 1 )
  {
    v5 = *(float *)&result->values.list;
    v6 = *(float **)(LODWORD(v5) + 4);
    v7 = *(_DWORD *)(LODWORD(v5) + 8);
    this->__vftable = *(idCurve_NURBS<idVec3>_vtbl **)LODWORD(v5);
    this->times.list = v6;
    this->times.num = v7;
  }
  else
  {
    v8 = idCurve_Spline<idVec1>::ClampedTime(this: result, t: time);
    v9 = idCurve<idVec3>::IndexForTime(this: result, time: v8);
    v10 = (int)result[1].__vftable;
    v11 = v9;
    idCurve_NonUniformBSpline<idAngles>::Basis(
      this: (idCurve_NonUniformBSpline<idVec3> *)result,
      index: v9 - 1,
      order: v10,
      t: v8,
      bvals: v12);
    list = result->values.list;
    v14 = 0;
    v15 = (float)(list->x - list->x);
    v16 = 0.0;
    v17 = (float)(list[1].x - list[1].x);
    v18 = (float)(list[2].x - list[2].x);
    if ( v10 > 0 )
    {
      v19 = v10 >> 1;
      p_size = &v25[0].times.size;
      do
      {
        v21 = *(float *)++p_size;
        v22 = (float)(idCurve_NURBS<idAngles>::WeightForIndex(
                        this: (idCurve_NURBS<idVec3> *)result,
                        index: v14 - v19 + v11)
                    * (float)v21);
        v16 = (float)((float)v22 + (float)v16);
        v23 = idCurve_Spline<idVec3>::ValueForIndex(this: v25, (idVec3 *)result, index: v14 - v19 + v11);
        ++v14;
        v15 = (float)((float)(v23->x * (float)v22) + (float)v15);
        v17 = (float)((float)(v23->y * (float)v22) + (float)v17);
        v18 = (float)((float)(v23->z * (float)v22) + (float)v18);
      }
      while ( v14 < v10 );
    }
    *v3 = (float)((float)1.0 / (float)v16) * (float)v15;
    v3[1] = (float)((float)1.0 / (float)v16) * (float)v17;
    v3[2] = (float)((float)1.0 / (float)v16) * (float)v18;
    return (idCurve_NURBS<idVec3> *)v3;
  }
  return this;
}


// ========================================================================
// ?GetCurrentSecondDerivative@?$idCurve_NURBS@VidAngles@@@@UBA?AVidAngles@@M@Z
// EA  : 0x827FB1C0
// RVA : 0x007FB1C0
// PDB : w:\tech5\shared\idlib\math\curve.h
// ========================================================================

idCurve_NURBS<idVec3> *__fastcall idCurve_NURBS<idAngles>::GetCurrentSecondDerivative(
        idCurve_NURBS<idVec3> *this,
        idCurve_Spline<idVec1> *result,
        double time)
{
  float *v3; // r24
  float v5; // r11
  float *v6; // r9
  int v7; // r8
  double v8; // fp31
  int v9; // r3
  int v10; // r28
  int v11; // r30
  int v12; // r26
  float *v13; // r6
  float *v14; // r6
  float *v15; // r6
  idVec1 *list; // r10
  int v17; // r29
  double x; // fp12
  double v19; // fp28
  double v20; // fp10
  double v21; // fp27
  double v22; // fp26
  double v23; // fp31
  double v24; // fp24
  double v25; // fp23
  double v26; // fp20
  double v27; // fp25
  double v28; // fp22
  double v29; // fp21
  double v30; // fp30
  double v31; // fp29
  int v32; // r25
  unsigned int v33; // r30
  double v34; // fp1
  double v35; // fp19
  double v36; // fp18
  double v37; // fp17
  idCurve_Spline<idVec3> v39[2]; // [sp+50h] [-180h] BYREF
  float v40[42]; // [sp+E0h] [-F0h] BYREF

  v3 = (float *)this;
  if ( result->times.num == 1 )
  {
    v5 = *(float *)&result->values.list;
    v6 = *(float **)(LODWORD(v5) + 4);
    v7 = *(_DWORD *)(LODWORD(v5) + 8);
    this->__vftable = *(idCurve_NURBS<idVec3>_vtbl **)LODWORD(v5);
    this->times.list = v6;
    this->times.num = v7;
  }
  else
  {
    v8 = idCurve_Spline<idVec1>::ClampedTime(this: result, t: time);
    v9 = idCurve<idVec3>::IndexForTime(this: result, time: v8);
    v10 = (int)result[1].__vftable;
    v11 = v9 - 1;
    v12 = v9;
    idCurve_NonUniformBSpline<idAngles>::Basis(
      this: (idCurve_NonUniformBSpline<idVec3> *)result,
      index: v9 - 1,
      order: v10,
      t: v8,
      bvals: v13);
    idCurve_NonUniformBSpline<idAngles>::BasisFirstDerivative(
      this: (idCurve_NonUniformBSpline<idVec3> *)result,
      index: v11,
      order: v10,
      t: v8,
      bvals: v14);
    idCurve_NonUniformBSpline<idVec3>::BasisSecondDerivative(
      this: (idCurve_NonUniformBSpline<idVec3> *)result,
      index: v11,
      order: v10,
      t: v8,
      bvals: v15,
      a6: v40);
    list = result->values.list;
    v17 = 0;
    x = list[1].x;
    v19 = (float)(list->x - list->x);
    *(float *)&v39[0].__vftable = list->x - list->x;
    v20 = list[2].x;
    v21 = (float)((float)x - (float)x);
    *(_DWORD *)&v39[0].values.granularity = v39[0].__vftable;
    *(float *)&v39[0].times.list = (float)x - (float)x;
    *(_DWORD *)&v39[0].times.granularity = v39[0].__vftable;
    v22 = (float)((float)v20 - (float)v20);
    *(float *)&v39[0].times.num = (float)v20 - (float)v20;
    v39[0].currentIndex = (int)v39[0].times.list;
    v23 = 0.0;
    v39[0].values.list = (idVec3 *)v39[0].times.list;
    v24 = *(float *)&v39[0].times.list;
    v25 = *(float *)&v39[0].__vftable;
    *(float *)&v39[0].changed = *(float *)&v39[0].times.num;
    v26 = *(float *)&v39[0].__vftable;
    v39[0].values.num = v39[0].times.num;
    v27 = *(float *)&v39[0].times.num;
    v28 = *(float *)&v39[0].times.num;
    v29 = *(float *)&v39[0].times.list;
    v30 = 0.0;
    v31 = 0.0;
    if ( v10 > 0 )
    {
      v32 = v10 >> 1;
      v33 = 0;
      do
      {
        v34 = idCurve_NURBS<idAngles>::WeightForIndex(this: (idCurve_NURBS<idVec3> *)result, index: v17 - v32 + v12);
        v35 = (float)(*(float *)((char *)&v39[0].closeTime + v33) * (float)v34);
        v36 = (float)(*(float *)((char *)&v39[1].boundaryType + v33) * (float)v34);
        v37 = (float)(v40[v33 / 4] * (float)v34);
        v23 = (float)((float)(*(float *)((char *)&v39[0].closeTime + v33) * (float)v34) + (float)v23);
        v30 = (float)((float)(*(float *)((char *)&v39[1].boundaryType + v33) * (float)v34) + (float)v30);
        v31 = (float)((float)(v40[v33 / 4] * (float)v34) + (float)v31);
        idCurve_Spline<idVec3>::ValueForIndex(this: v39, (idVec3 *)result, index: v17 - v32 + v12);
        ++v17;
        v33 += 4;
        v19 = (float)((float)(*(float *)&v39[0].__vftable * (float)v35) + (float)v19);
        v21 = (float)((float)(*(float *)&v39[0].times.list * (float)v35) + (float)v21);
        v22 = (float)((float)(*(float *)&v39[0].times.num * (float)v35) + (float)v22);
        v25 = (float)((float)(*(float *)&v39[0].__vftable * (float)v36) + (float)v25);
        v24 = (float)((float)v24 + (float)(*(float *)&v39[0].times.list * (float)v36));
        v27 = (float)((float)v27 + (float)(*(float *)&v39[0].times.num * (float)v36));
        v26 = (float)((float)(*(float *)&v39[0].__vftable * (float)v37) + (float)v26);
        v29 = (float)((float)v29 + (float)(*(float *)&v39[0].times.list * (float)v37));
        v28 = (float)((float)v28 + (float)(*(float *)&v39[0].times.num * (float)v37));
      }
      while ( v17 < v10 );
    }
    *v3 = (float)((float)((float)((float)((float)v26 * (float)v23) - (float)((float)v19 * (float)v31))
                        * (float)((float)v23 * (float)v23))
                - (float)((float)((float)((float)((float)((float)v25 * (float)v23) - (float)((float)v19 * (float)v30))
                                        * (float)2.0)
                                * (float)v23)
                        * (float)v30))
        * (float)((float)1.0 / (float)((float)((float)((float)v23 * (float)v23) * (float)v23) * (float)v23));
    v3[1] = (float)((float)((float)((float)((float)v29 * (float)v23) - (float)((float)v21 * (float)v31))
                          * (float)((float)v23 * (float)v23))
                  - (float)((float)((float)((float)((float)((float)v24 * (float)v23) - (float)((float)v21 * (float)v30))
                                          * (float)2.0)
                                  * (float)v23)
                          * (float)v30))
          * (float)((float)1.0 / (float)((float)((float)((float)v23 * (float)v23) * (float)v23) * (float)v23));
    v3[2] = (float)((float)((float)((float)((float)v28 * (float)v23) - (float)((float)v22 * (float)v31))
                          * (float)((float)v23 * (float)v23))
                  - (float)((float)((float)((float)((float)((float)v27 * (float)v23) - (float)((float)v22 * (float)v30))
                                          * (float)2.0)
                                  * (float)v23)
                          * (float)v30))
          * (float)((float)1.0 / (float)((float)((float)((float)v23 * (float)v23) * (float)v23) * (float)v23));
    return (idCurve_NURBS<idVec3> *)v3;
  }
  return this;
}


// ========================================================================
// ?CreateNewCurve@?$idCurve_NURBS@VidVec3@@@@MBAPAV?$idCurve@VidVec3@@@@XZ
// EA  : 0x827FB518
// RVA : 0x007FB518
// PDB : w:\tech5\shared\idlib\math\curve.h
// ========================================================================

idCurve_NURBS<idVec3> *__fastcall idCurve_NURBS<idVec3>::CreateNewCurve(idCurve_NURBS<idVec3> *this)
{
  idCurve_NURBS<idVec3> *v1; // r3

  v1 = (idCurve_NURBS<idVec3> *)idMem::AllocWithLocation(
                                  this: &mem,
                                  location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                  size: 0x48u,
                                  tag: TAG_TABLE,
                                  zeroBuffer: false,
                                  align: ALIGN_16,
                                  heap: HEAP_DEFAULTHEAP);
  if ( v1 != nullptr )
    return idCurve_NURBS<idVec3>::idCurve_NURBS<idVec3>(this: v1);
  else
    return nullptr;
}


// ========================================================================
// __unwind$231059_0
// EA  : 0x827FB580
// RVA : 0x007FB580
// PDB : w:\tech5\shared\idlib\math\curve.h
// ========================================================================

void _unwind_231059_0()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_TABLE);
}


// ========================================================================
// ?MakeUniformMoveSpeed@?$idCurve@VidVec3@@@@QAAMM@Z
// EA  : 0x82C37478
// RVA : 0x00C37478
// PDB : w:\tech5\shared\idlib\math\curve.h
// ========================================================================

float __fastcall idCurve<idVec3>::MakeUniformMoveSpeed(idCurve<idVec3> *this, double moveSpeed)
{
  int v4; // r10
  int v5; // r4
  int v6; // r12
  double v7; // fp31
  float *v8; // r28
  int v9; // r29
  double LengthBetweenKnots; // fp1
  double v11; // fp0
  int v12; // r10
  double v13; // fp1
  int v14; // r11
  _DWORD back_chain[19]; // [sp+0h] [-A0h]
  _BYTE v17[12]; // [sp+4Ch] [-54h] BYREF

  ((void (*)(void))RtlCheckStack12)();
  v5 = 0;
  *(_DWORD *)((char *)back_chain + v6) = back_chain[0];
  v7 = 0.0;
  if ( v4 - 1 > 0 )
  {
    v8 = (float *)v17;
    do
    {
      v9 = v5 + 1;
      LengthBetweenKnots = idCurve<idVec3>::GetLengthBetweenKnots(this, i0: v5, i1: v5 + 1);
      *++v8 = LengthBetweenKnots;
      v5 = v9;
      v7 = (float)((float)LengthBetweenKnots + (float)v7);
    }
    while ( v9 < this->values.num - 1 );
  }
  v11 = 0.0;
  v12 = 0;
  v13 = (float)((float)((float)1.0 / (float)moveSpeed) * (float)v7);
  if ( this->times.num - 1 > 0 )
  {
    v14 = 0;
    do
    {
      ++v12;
      this->times.list[v14] = v11;
      v11 = (float)((float)(*(float *)&v17[v14 * 4 + 4] * (float)((float)1.0 / (float)moveSpeed)) + (float)v11);
      ++v14;
    }
    while ( v12 < this->times.num - 1 );
  }
  this->times.list[this->times.num - 1] = (float)((float)1.0 / (float)moveSpeed) * (float)v7;
  this->changed = true;
  return *((float *)&v13 + 1);
}


// ========================================================================
// ?MakeUniform@?$idCurve@VidAngles@@@@QAAXM@Z
// EA  : 0x82C70CA0
// RVA : 0x00C70CA0
// PDB : w:\tech5\shared\idlib\math\curve.h
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idCurve<idAngles>::MakeUniform(
        idCurve<idVec3> *this,
        double totalTime,
        int a3,
        int a4,
        int a5,
        int a6,
        __int64 a7)
{
  __int64 v7; // r30 OVERLAPPED
  __int64 v8; // r10
  int v9; // r5
  int v10; // r11
  int v11; // r10
  double v12; // fp0
  float *list; // r7
  int v14; // r31
  int v15; // r10
  int v16; // ctr
  double v17; // fp0
  __int64 v18; // r9
  __int64 v19; // [sp+0h] [-30h]

  HIDWORD(v8) = this->times.list;
  v9 = this->times.num - 1;
  v10 = 1;
  *(float *)HIDWORD(v8) = 0.0;
  if ( v9 >= 4 )
  {
    LODWORD(v8) = v9;
    v12 = (float)v8;
    v11 = 3;
    LODWORD(a7) = 4;
    do
    {
      HIDWORD(a7) = v11 - 1;
      list = this->times.list;
      LODWORD(v7) = v11;
      v19 = *(__int64 *)((char *)&a7 + 4);
      HIDWORD(a7) = v11 + 1;
      v14 = v10;
      v10 += 4;
      v11 += 4;
      *(float *)((char *)list + a7) = (float)((float)*(__int64 *)((char *)&v7 - 4) * (float)totalTime) / (float)v12;
      *(float *)((char *)this->times.list + a7 + 4) = (float)((float)v19 * (float)totalTime) / (float)v12;
      *(float *)((char *)this->times.list + a7 + 8) = (float)((float)v7 * (float)totalTime) / (float)v12;
      *(float *)((char *)this->times.list + a7 + 12) = (float)((float)*(__int64 *)((char *)&a7 + 4) * (float)totalTime)
                                                     / (float)v12;
      HIDWORD(a7) = a7 + 12;
      LODWORD(a7) = a7 + 16;
    }
    while ( v10 <= v9 - 3 );
  }
  if ( v10 <= v9 )
  {
    LODWORD(a7) = v9;
    v15 = 4 * v10;
    v16 = v9 - v10 + 1;
    v17 = (float)a7;
    do
    {
      LODWORD(v18) = v10;
      HIDWORD(v18) = this->times.list;
      ++v10;
      *(float *)(v15 + HIDWORD(v18)) = (float)((float)v18 * (float)totalTime) / (float)v17;
      v15 += 4;
      --v16;
    }
    while ( v16 != 0 );
  }
  this->changed = true;
}


// ========================================================================
// ??1?$idCurve@VidAngles@@@@UAA@XZ
// EA  : 0x82C87828
// RVA : 0x00C87828
// PDB : w:\tech5\shared\idlib\math\curve.h
// ========================================================================

void __fastcall idCurve<idAngles>::~idCurve<idAngles>(idCurve<idAngles> *this)
{
  this->__vftable = (idCurve<idAngles>_vtbl *)&idCurve<idAngles>::`vftable';
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->values);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->times);
}


// ========================================================================
// __unwind$508359
// EA  : 0x82C8787C
// RVA : 0x00C8787C
// PDB : w:\tech5\shared\idlib\math\curve.h
// ========================================================================

void _unwind_508359()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 4));
}


// ========================================================================
// ?GetCurrentFirstDerivative@?$idCurve@VidAngles@@@@UBA?AVidAngles@@M@Z
// EA  : 0x82C878A8
// RVA : 0x00C878A8
// PDB : w:\tech5\shared\idlib\math\curve.h
// ========================================================================

idCurve<idVec3> *__fastcall idCurve<idAngles>::GetCurrentFirstDerivative(
        idCurve<idVec3> *this,
        idVec3 *result,
        double time)
{
  float z; // r11
  double v4; // fp8
  double v5; // fp6

  z = result[1].z;
  v4 = (float)(*(float *)(LODWORD(z) + 4) - *(float *)(LODWORD(z) + 4));
  v5 = (float)(*(float *)(LODWORD(z) + 8) - *(float *)(LODWORD(z) + 8));
  *(float *)&this->__vftable = *(float *)LODWORD(z) - *(float *)LODWORD(z);
  *(float *)&this->times.list = v4;
  *(float *)&this->times.num = v5;
  return this;
}


// ========================================================================
// ?EstimateLengthForTime@?$idCurve@VidVec3@@@@UBAMM@Z
// EA  : 0x82C878E0
// RVA : 0x00C878E0
// PDB : w:\tech5\shared\idlib\math\curve.h
// ========================================================================

float __fastcall idCurve<idVec3>::EstimateLengthForTime(idCurve<idVec3> *this, double time)
{
  int num; // r5
  int v4; // r8
  double v5; // fp1
  idVec3 *list; // r7
  int v7; // r9
  int i; // r10
  double v9; // fp9
  double v10; // fp7
  double v11; // fp4
  double v12; // fp0

  num = this->times.num;
  v4 = 1;
  v5 = 0.0;
  if ( num > 1 )
  {
    list = this->values.list;
    v7 = 1;
    for ( i = 1; ; ++i )
    {
      v9 = (float)(list[i].y - list[i - 1].y);
      v10 = (float)(list[i].x - list[i - 1].x);
      v11 = (float)(list[i].z - list[i - 1].z);
      v12 = __fsqrts((float)((float)((float)v11 * (float)v11)
                           + (float)((float)((float)v10 * (float)v10) + (float)((float)v9 * (float)v9))));
      if ( time < this->times.list[v7] )
        break;
      ++v4;
      v5 = (float)((float)v12 + (float)v5);
      ++v7;
      if ( v4 >= num )
        return *((float *)&v5 + 1);
    }
    v5 = (float)((float)((float)((float)((float)time - this->times.list[v4 - 1]) * (float)v12)
                       / (float)(this->times.list[v4] - this->times.list[v4 - 1]))
               + (float)v5);
  }
  return *((float *)&v5 + 1);
}


// ========================================================================
// ?Clear@?$idCurve@VidAngles@@@@UAAXXZ
// EA  : 0x82C87A10
// RVA : 0x00C87A10
// PDB : w:\tech5\shared\idlib\math\curve.h
// ========================================================================

void __fastcall idCurve<idAngles>::Clear(idCurve<idVec1> *this)
{
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->values);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->times);
  this->currentIndex = -1;
  this->changed = true;
}


// ========================================================================
// ?GetCurrentValue@?$idCurve@VidVec3@@@@UBA?AVidVec3@@M@Z
// EA  : 0x82C87A58
// RVA : 0x00C87A58
// PDB : w:\tech5\shared\idlib\math\curve.h
// ========================================================================

idCurve<idVec3> *__fastcall idCurve<idVec3>::GetCurrentValue(
        idCurve<idVec3> *this,
        idCurve<idVec1> *result,
        double time)
{
  int v5; // r3
  float v6; // r11
  int v7; // r10
  idCurve<idVec3> *v8; // r3
  bool v9; // zf
  int v10; // r11
  float *v11; // r9
  int v12; // r8
  int v13; // r10
  float *v14; // r8
  int v15; // r7

  v5 = idCurve<idVec3>::IndexForTime(this: result, time);
  v6 = *(float *)&result->values.num;
  v7 = v5;
  v9 = v5 < SLODWORD(v6);
  v8 = this;
  if ( v9 )
  {
    v13 = (int)&result->values.list[3 * v7];
    v14 = *(float **)(v13 + 4);
    v15 = *(_DWORD *)(v13 + 8);
    this->__vftable = *(idCurve<idVec3>_vtbl **)v13;
    this->times.list = v14;
    this->times.num = v15;
  }
  else
  {
    v10 = (int)&result->values.list[3 * LODWORD(v6)];
    v11 = *(float **)(v10 - 8);
    v12 = *(_DWORD *)(v10 - 4);
    this->__vftable = *(idCurve<idVec3>_vtbl **)(v10 - 12);
    this->times.list = v11;
    this->times.num = v12;
  }
  return v8;
}


// ========================================================================
// ??0?$idCurve@VidAngles@@@@QAA@XZ
// EA  : 0x82C87B78
// RVA : 0x00C87B78
// PDB : w:\tech5\shared\idlib\math\curve.h
// ========================================================================

idCurve<idAngles> *__fastcall idCurve<idAngles>::idCurve<idAngles>(idCurve<idAngles> *this)
{
  this->__vftable = (idCurve<idAngles>_vtbl *)&idCurve<idAngles>::`vftable';
  this->times.list = nullptr;
  this->times.granularity = 0;
  this->times.memTag = 116;
  this->times.listStatic = 0;
  this->times.size = 0;
  this->times.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->times);
  this->values.list = nullptr;
  this->values.granularity = 0;
  this->values.memTag = 116;
  this->values.listStatic = 0;
  this->values.size = 0;
  this->values.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->values);
  this->changed = false;
  this->currentIndex = -1;
  return this;
}


// ========================================================================
// __unwind$508792
// EA  : 0x82C87BFC
// RVA : 0x00C87BFC
// PDB : w:\tech5\shared\idlib\math\curve.h
// ========================================================================

void _unwind_508792()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 4));
}


// ========================================================================
// ?RombergIntegral@?$idCurve@VidVec3@@@@IBAMMMH@Z
// EA  : 0x82C87C28
// RVA : 0x00C87C28
// PDB : w:\tech5\shared\idlib\math\curve.h
// ========================================================================

float __fastcall idCurve<idVec3>::RombergIntegral(
        idCurve<idVec3> *this,
        double t0,
        double t1,
        const int order,
        int a5,
        int a6)
{
  double v8; // fp28
  idVec3 *(__fastcall *GetCurrentFirstDerivative)(idCurve<idVec3> *, idVec3 *, double); // r11
  double v12; // fp31
  int v13; // r30
  int v14; // r28
  double v15; // fp27
  double v16; // fp31
  int i; // r31
  int v18; // r10
  int v19; // r11
  double v20; // fp13
  double v21; // fp10
  double v22; // fp9
  double v23; // fp8
  double v24; // fp7
  double v25; // fp6
  double v26; // fp5
  double v27; // fp4
  double v28; // fp3
  double v29; // fp2
  double v30; // fp1
  double v31; // fp13
  int v32; // r11
  int v33; // ctr
  int v34; // r10
  float *v35; // r11
  double v36; // fp13
  double v37; // fp12
  double v38; // fp11
  double v39; // fp1
  float v41; // [sp+50h] [-170h] BYREF
  float v42; // [sp+54h] [-16Ch] BYREF
  float v43; // [sp+58h] [-168h] BYREF
  float v44; // [sp+5Ch] [-164h] BYREF
  float v45[8]; // [sp+60h] [-160h] BYREF
  float v46; // [sp+80h] [-140h] BYREF
  float v47; // [sp+84h] [-13Ch] BYREF
  float v48; // [sp+88h] [-138h] BYREF
  float v49; // [sp+8Ch] [-134h] BYREF
  float v50[8]; // [sp+90h] [-130h] BYREF
  float v51; // [sp+B0h] [-110h] BYREF
  float v52; // [sp+B4h] [-10Ch]
  float v53; // [sp+B8h] [-108h]
  float v54; // [sp+C0h] [-100h] BYREF
  float v55; // [sp+C4h] [-FCh]
  float v56; // [sp+C8h] [-F8h]
  float v57; // [sp+D0h] [-F0h] BYREF
  float v58; // [sp+D4h] [-ECh]
  float v59; // [sp+D8h] [-E8h]
  char v60; // [sp+DCh] [-E4h] BYREF
  float v61[10]; // [sp+E0h] [-E0h] BYREF
  float v62[34]; // [sp+108h] [-B8h] BYREF

  v8 = (float)((float)t1 - (float)t0);
  GetCurrentFirstDerivative = this->GetCurrentFirstDerivative;
  v46 = 1.0;
  v47 = 4.0;
  v48 = 16.0;
  v49 = 64.0;
  v50[0] = 256.0;
  v50[1] = 1024.0;
  v50[2] = 4096.0;
  v50[3] = 16384.0;
  v50[4] = 65536.0;
  v50[5] = 262144.0;
  v50[6] = 1048576.0;
  v41 = 1.0;
  v42 = 0.33333334;
  v43 = 0.06666667;
  v44 = 0.015873017;
  v45[0] = 0.0039215689;
  v45[1] = 0.00097751711;
  v45[2] = 0.00024420026;
  v45[3] = 0.000061038882;
  v45[4] = 0.000015259022;
  v45[5] = 0.0000038147118;
  v45[6] = 0.00000095367523;
  ((void (__fastcall *)(float *, idCurve<idVec3> *))GetCurrentFirstDerivative)(a1: &v54, a2: this);
  v12 = __fsqrts((float)((float)(v56 * v56) + (float)((float)(v54 * v54) + (float)(v55 * v55))));
  this->GetCurrentFirstDerivative(this: (idCurve<idVec3> *)&v57, result: (idVec3 *)this, a3: t1);
  v13 = 2;
  v14 = 1;
  for ( v61[0] = (float)((float)((float)__fsqrts((float)((float)(v59 * v59)
                                                       + (float)((float)(v57 * v57) + (float)(v58 * v58))))
                               + (float)v12)
                       * (float)v8)
               * (float)0.5; v13 <= a6; v14 *= 2 )
  {
    v15 = 0.0;
    v16 = 0.5;
    if ( v14 >= 1 )
    {
      for ( i = v14; i != 0; --i )
      {
        this->GetCurrentFirstDerivative(
          this: (idCurve<idVec3> *)&v51,
          result: (idVec3 *)this,
          a3: (float)((float)((float)v16 * (float)v8) + (float)t0));
        v16 = (float)((float)v16 + (float)1.0);
        v15 = (float)((float)__fsqrts((float)((float)(v53 * v53) + (float)((float)(v51 * v51) + (float)(v52 * v52))))
                    + (float)v15);
      }
    }
    v18 = 1;
    v62[0] = (float)((float)((float)v15 * (float)v8) + v61[0]) * (float)0.5;
    if ( v13 > 1 )
    {
      if ( v13 - 3 + 2 >= 4 )
      {
        v19 = 0;
        do
        {
          v20 = *(float *)((char *)&v42 + v19 * 4);
          v21 = (float)((float)(*(float *)((char *)&v47 + v19 * 4) * v62[v19]) - v62[v19 - 10]);
          v22 = *(float *)((char *)&v48 + v19 * 4);
          v23 = v61[v19 + 1];
          v24 = *(float *)((char *)&v43 + v19 * 4);
          v25 = v50[v19 - 1];
          v26 = v61[v19 + 2];
          v27 = v45[v19 - 1];
          v28 = v50[v19];
          v29 = v61[v19 + 3];
          v30 = v45[v19];
          v18 += 4;
          v62[v19 + 1] = (float)((float)(*(float *)((char *)&v47 + v19 * 4) * v62[v19]) - v62[v19 - 10])
                       * *(float *)((char *)&v42 + v19 * 4);
          v31 = (float)((float)((float)v22 * (float)((float)v21 * (float)v20)) - (float)v23);
          v62[v19 + 2] = (float)v31 * (float)v24;
          v62[v19 + 3] = (float)((float)((float)v25 * (float)((float)v31 * (float)v24)) - (float)v26) * (float)v27;
          v62[v19 + 4] = (float)((float)((float)v28
                                       * (float)((float)((float)((float)v25 * (float)((float)v31 * (float)v24))
                                                       - (float)v26)
                                               * (float)v27))
                               - (float)v29)
                       * (float)v30;
          v19 += 4;
        }
        while ( v18 < v13 - 3 );
      }
      if ( v18 < v13 )
      {
        v32 = v18;
        v33 = v13 - v18;
        do
        {
          v62[v32] = (float)((float)(*(float *)((char *)&v46 + v32 * 4) * v61[v32 + 9]) - v61[v32 - 1])
                   * *(float *)((char *)&v41 + v32 * 4);
          ++v32;
          --v33;
        }
        while ( v33 != 0 );
      }
    }
    v34 = 0;
    if ( v13 >= 4 )
    {
      v35 = (float *)&v60;
      do
      {
        v34 += 4;
        v36 = v35[12];
        v37 = v35[13];
        v38 = v35[14];
        v35[1] = v35[11];
        v35[2] = v36;
        v35[3] = v37;
        v35 += 4;
        *v35 = v38;
      }
      while ( v34 < v13 - 3 );
    }
    if ( v34 < v13 )
      blkmov(a1: &v61[v34], a2: &v62[v34], a3: 4 * (v13 - v34));
    ++v13;
    v8 = (float)((float)v8 * (float)0.5);
  }
  v39 = v61[a6 - 1];
  return *((float *)&v39 + 1);
}


// ========================================================================
// ?GetLengthForTime@?$idCurve@VidVec3@@@@UBAMM@Z
// EA  : 0x82C8C558
// RVA : 0x00C8C558
// PDB : w:\tech5\shared\idlib\math\curve.h
// ========================================================================

float __fastcall idCurve<idVec3>::GetLengthForTime(idCurve<idVec3> *this, double time)
{
  double v4; // fp31
  int v5; // r5
  int v6; // r4
  int v7; // r3
  int v8; // r28
  int v9; // r30
  int i; // r31
  double v11; // fp1

  v4 = 0.0;
  v7 = idCurve<idVec3>::IndexForTime((idCurve<idVec1> *)this, time);
  v8 = v7;
  if ( v7 > 0 )
  {
    v9 = 0;
    for ( i = v7; i != 0; --i )
    {
      v4 = (float)(idCurve<idVec3>::RombergIntegral(
                     this,
                     t0: this->times.list[v9],
                     t1: this->times.list[v9 + 1],
                     order: v6,
                     a5: v5,
                     a6: 5)
                 + (float)v4);
      ++v9;
    }
  }
  v11 = (float)(idCurve<idVec3>::RombergIntegral(this, t0: this->times.list[v8], t1: time, order: v6, a5: v5, a6: 5)
              + (float)v4);
  return *((float *)&v11 + 1);
}


// ========================================================================
// ?SetBoundaryType@?$idCurve_Spline@VidVec1@@@@UAAXW4eType@boundary_t@@@Z
// EA  : 0x82C8C5F0
// RVA : 0x00C8C5F0
// PDB : w:\tech5\shared\idlib\math\curve.h
// ========================================================================

void __fastcall idCurve_Spline<idVec1>::SetBoundaryType(idCurve_Spline<idVec1> *this, boundary_t::eType bt)
{
  this->boundaryType = bt;
  this->changed = true;
}


// ========================================================================
// ?SetCloseTime@?$idCurve_Spline@VidAngles@@@@UAAXM@Z
// EA  : 0x82C8C600
// RVA : 0x00C8C600
// PDB : w:\tech5\shared\idlib\math\curve.h
// ========================================================================

void __fastcall idCurve_Spline<idAngles>::SetCloseTime(idCurve_Spline<idVec1> *this, double t)
{
  this->closeTime = t;
  this->changed = true;
}


// ========================================================================
// ?IsDone@?$idCurve_Spline@VidAngles@@@@UBA_NM@Z
// EA  : 0x82C8C610
// RVA : 0x00C8C610
// PDB : w:\tech5\shared\idlib\math\curve.h
// ========================================================================

int __fastcall idCurve_Spline<idAngles>::IsDone(idCurve_Spline<idVec1> *this, double time)
{
  unsigned __int8 v2; // r11

  if ( this->boundaryType == CLOSED )
    return 0;
  v2 = 1;
  if ( time < this->times.list[this->times.num - 1] )
    return 0;
  return v2;
}


// ========================================================================
// ??0?$idCurve_CatmullRomSpline@VidAngles@@@@QAA@XZ
// EA  : 0x82C8C648
// RVA : 0x00C8C648
// PDB : w:\tech5\shared\idlib\math\curve.h
// ========================================================================

idCurve_CatmullRomSpline<idAngles> *__fastcall idCurve_CatmullRomSpline<idAngles>::idCurve_CatmullRomSpline<idAngles>(
        idCurve_CatmullRomSpline<idAngles> *this)
{
  idCurve<idAngles>::idCurve<idAngles>(this);
  this->boundaryType = 0;
  this->__vftable = (idCurve_CatmullRomSpline<idAngles>_vtbl *)&idCurve_CatmullRomSpline<idAngles>::`vftable';
  this->closeTime = 0.0;
  return this;
}


// ========================================================================
// ?ValueForIndex@?$idCurve_Spline@VidVec3@@@@IBA?AVidVec3@@H@Z
// EA  : 0x82C8C698
// RVA : 0x00C8C698
// PDB : w:\tech5\shared\idlib\math\curve.h
// ========================================================================

idCurve_Spline<idVec3> *__fastcall idCurve_Spline<idVec3>::ValueForIndex(
        idCurve_Spline<idVec3> *this,
        idVec3 *result,
        int index)
{
  float x; // r10
  int v4; // r11
  float v5; // r11
  float v6; // r9
  float v7; // r11
  float v8; // r8
  int v9; // r7
  int v10; // r9
  idCurve_Spline<idVec3>_vtbl *v11; // r8
  float v12; // r11
  float *v13; // r9
  int v14; // r8
  __int64 v15; // r11
  double v16; // fp1
  double v17; // fp0
  double v18; // fp12
  double v19; // fp11
  float z; // r9
  float v21; // r8
  int v22; // r10
  float *v23; // r8
  int v24; // r7
  int v25; // r10
  float *v26; // r8
  int v27; // r7
  __int64 v28; // r7
  float *v29; // r11
  double v30; // fp1
  double v31; // fp0
  double v32; // fp11
  double v33; // fp10
  int v34; // r6
  float *v35; // r7

  x = result[2].x;
  v4 = LODWORD(x) - 1;
  if ( index >= 0 )
  {
    if ( index <= v4 )
      goto LABEL_15;
    z = result[3].z;
    if ( z == 0.0 )
    {
      LODWORD(v28) = index - v4;
      HIDWORD(v28) = 3 * v4;
      v29 = (float *)(12 * v4 + LODWORD(result[1].z));
      v30 = v29[1];
      v31 = v29[2];
      v32 = (float)((float)(v29[1] - *(v29 - 2)) * (float)v28);
      v33 = (float)((float)(v29[2] - *(v29 - 1)) * (float)v28);
      *(float *)&this->__vftable = (float)((float)(*v29 - *(v29 - 3)) * (float)v28) + *v29;
      *(float *)&this->times.list = (float)v30 + (float)v32;
      *(float *)&this->times.num = (float)v31 + (float)v33;
    }
    else if ( LODWORD(z) == 1 )
    {
      v25 = 12 * v4 + LODWORD(result[1].z);
      v26 = *(float **)(v25 + 4);
      v27 = *(_DWORD *)(v25 + 8);
      this->__vftable = *(idCurve_Spline<idVec3>_vtbl **)v25;
      this->times.list = v26;
      this->times.num = v27;
    }
    else
    {
      if ( LODWORD(z) >= 3 )
        goto LABEL_15;
      v21 = result[1].z;
      __twllei(LODWORD(x), 0);
      __twlgei(LODWORD(x) & ~(__ROL4__(index, 1) - 1), 0xFFFFFFFF);
      v22 = 12 * (index % SLODWORD(x)) + LODWORD(v21);
      v24 = *(_DWORD *)(v22 + 8);
      v23 = *(float **)(v22 + 4);
      this->__vftable = *(idCurve_Spline<idVec3>_vtbl **)v22;
      this->times.list = v23;
      this->times.num = v24;
    }
  }
  else
  {
    v5 = result[3].z;
    if ( v5 == 0.0 )
    {
      LODWORD(v15) = index;
      *(float *)&v15 = result[1].z;
      v16 = *(float *)(HIDWORD(v15) + 4);
      v17 = *(float *)(HIDWORD(v15) + 8);
      v18 = (float)((float)(*(float *)(HIDWORD(v15) + 16) - *(float *)(HIDWORD(v15) + 4)) * (float)v15);
      v19 = (float)((float)(*(float *)(HIDWORD(v15) + 20) - *(float *)(HIDWORD(v15) + 8)) * (float)v15);
      *(float *)&this->__vftable = *(float *)HIDWORD(v15)
                                 + (float)((float)(*(float *)(HIDWORD(v15) + 12) - *(float *)HIDWORD(v15)) * (float)v15);
      *(float *)&this->times.list = (float)v16 + (float)v18;
      *(float *)&this->times.num = (float)v17 + (float)v19;
    }
    else
    {
      if ( LODWORD(v5) != 1 )
      {
        if ( LODWORD(v5) < 3 )
        {
          v6 = result->z;
          v7 = result[2].x;
          v8 = result[1].z;
          __twllei(LODWORD(v6), 0);
          v9 = index % SLODWORD(v6) + LODWORD(v7);
          __twlgei(LODWORD(v6) & ~(__ROL4__(index, 1) - 1), 0xFFFFFFFF);
          __twllei(LODWORD(v7), 0);
          __twlgei(LODWORD(v7) & ~(__ROL4__(v9, 1) - 1), 0xFFFFFFFF);
          v10 = 12 * (v9 % SLODWORD(v7)) + LODWORD(v8);
          v11 = *(idCurve_Spline<idVec3>_vtbl **)v10;
LABEL_16:
          v34 = *(_DWORD *)(v10 + 8);
          v35 = *(float **)(v10 + 4);
          this->__vftable = v11;
          this->times.num = v34;
          this->times.list = v35;
          return this;
        }
LABEL_15:
        v10 = 12 * index + LODWORD(result[1].z);
        v11 = *(idCurve_Spline<idVec3>_vtbl **)v10;
        goto LABEL_16;
      }
      v12 = result[1].z;
      v13 = *(float **)(LODWORD(v12) + 4);
      v14 = *(_DWORD *)(LODWORD(v12) + 8);
      this->__vftable = *(idCurve_Spline<idVec3>_vtbl **)LODWORD(v12);
      this->times.list = v13;
      this->times.num = v14;
    }
  }
  return this;
}


// ========================================================================
// ?ClampedTime@?$idCurve_Spline@VidVec1@@@@IBAMM@Z
// EA  : 0x82C8C910
// RVA : 0x00C8C910
// PDB : w:\tech5\shared\idlib\math\curve.h
// ========================================================================

// local variable allocation has failed, the output may be wrong!
float __fastcall idCurve_Spline<idVec1>::ClampedTime(idCurve_Spline<idVec1> *this, double t)
{
  boundary_t::eType boundaryType; // r11
  float *v4; // r10
  double v5; // fp30
  long double v6; // fp2
  long double v7; // fp2
  double v8; // fp1
  float *list; // r11

  boundaryType = this->boundaryType;
  if ( boundaryType != CLAMPED )
  {
    if ( boundaryType == CLOSED )
    {
      v4 = &this->times.list[this->times.num];
      v5 = (float)(*(v4 - 1) + this->closeTime);
      *(double *)&v6 = (float)((float)t / (float)(*(v4 - 1) + this->closeTime));
      v7 = floor(x: v6);
      v8 = (float)-(float)((float)((float)*(double *)&v7 * (float)v5) - (float)t);
      return *((float *)&v8 + 1);
    }
LABEL_6:
    v8 = t;
    return *((float *)&v8 + 1);
  }
  list = this->times.list;
  v8 = *list;
  if ( t >= v8 )
  {
    v8 = list[this->times.num - 1];
    if ( t < v8 )
      goto LABEL_6;
  }
  return *((float *)&v8 + 1);
}


// ========================================================================
// ?GetCurrentValue@?$idCurve_CatmullRomSpline@VidAngles@@@@UBA?AVidAngles@@M@Z
// EA  : 0x82C8C9B0
// RVA : 0x00C8C9B0
// PDB : w:\tech5\shared\idlib\math\curve.h
// ========================================================================

idCurve_CatmullRomSpline<idVec3> *__fastcall idCurve_CatmullRomSpline<idAngles>::GetCurrentValue(
        idCurve_CatmullRomSpline<idVec3> *this,
        idCurve_CatmullRomSpline<idVec1> *result,
        double time)
{
  float v5; // r11
  float *v6; // r9
  int v7; // r8
  double v8; // fp31
  int v9; // r29
  float *v10; // r5
  idVec1 *list; // r10
  int v12; // r28
  int v13; // r31
  int *p_size; // r29
  double v15; // fp31
  double v16; // fp30
  double v17; // fp29
  float *v18; // r3
  float *v19; // r10
  idCurve_Spline<idVec3>_vtbl *v20; // r11
  idCurve_Spline<idVec3> v22; // [sp+50h] [-70h] BYREF

  if ( result->times.num == 1 )
  {
    v5 = *(float *)&result->values.list;
    v6 = *(float **)(LODWORD(v5) + 4);
    v7 = *(_DWORD *)(LODWORD(v5) + 8);
    this->__vftable = *(idCurve_CatmullRomSpline<idVec3>_vtbl **)LODWORD(v5);
    this->times.list = v6;
    this->times.num = v7;
  }
  else
  {
    v8 = idCurve_Spline<idVec1>::ClampedTime(this: result, t: time);
    v9 = idCurve<idVec3>::IndexForTime(this: result, time: v8);
    idCurve_CatmullRomSpline<idVec3>::Basis(
      this: result,
      index: v9 - 1,
      t: v8,
      bvals: v10,
      a5: (float *)&v22.times.granularity);
    list = result->values.list;
    v12 = v9 - 2;
    v13 = 0;
    p_size = &v22.times.size;
    v15 = (float)(list->x - list->x);
    v16 = (float)(list[1].x - list[1].x);
    v17 = (float)(list[2].x - list[2].x);
    do
    {
      v18 = (float *)idCurve_Spline<idVec3>::ValueForIndex(this: &v22, (idVec3 *)result, index: v12 + v13);
      ++p_size;
      ++v13;
      v15 = (float)((float)(*v18 * *(float *)p_size) + (float)v15);
      v16 = (float)((float)(v18[1] * *(float *)p_size) + (float)v16);
      v17 = (float)((float)(v18[2] * *(float *)p_size) + (float)v17);
    }
    while ( v13 < 4 );
    *(float *)&v22.times.list = v16;
    v19 = v22.times.list;
    *(float *)&v22.__vftable = v15;
    v20 = v22.__vftable;
    *(float *)&v22.times.num = v17;
    this->times.num = v22.times.num;
    this->__vftable = (idCurve_CatmullRomSpline<idVec3>_vtbl *)v20;
    this->times.list = v19;
  }
  return this;
}


// ========================================================================
// ??0?$idCurve_KochanekBartelsSpline@VidAngles@@@@QAA@XZ
// EA  : 0x82C8CAE8
// RVA : 0x00C8CAE8
// PDB : w:\tech5\shared\idlib\math\curve.h
// ========================================================================

idCurve_KochanekBartelsSpline<idAngles> *__fastcall idCurve_KochanekBartelsSpline<idAngles>::idCurve_KochanekBartelsSpline<idAngles>(
        idCurve_KochanekBartelsSpline<idAngles> *this)
{
  idCurve<idAngles>::idCurve<idAngles>(this);
  this->boundaryType = 0;
  this->closeTime = 0.0;
  this->__vftable = (idCurve_KochanekBartelsSpline<idAngles>_vtbl *)&idCurve_KochanekBartelsSpline<idAngles>::`vftable';
  this->tension.list = nullptr;
  this->tension.granularity = 0;
  this->tension.memTag = 116;
  this->tension.listStatic = 0;
  this->tension.size = 0;
  this->tension.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->tension);
  this->continuity.list = nullptr;
  this->continuity.granularity = 0;
  this->continuity.memTag = 116;
  this->continuity.listStatic = 0;
  this->continuity.size = 0;
  this->continuity.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->continuity);
  this->bias.list = nullptr;
  this->bias.granularity = 0;
  this->bias.memTag = 116;
  this->bias.listStatic = 0;
  this->bias.size = 0;
  this->bias.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->bias);
  return this;
}


// ========================================================================
// __unwind$514561
// EA  : 0x82C8CB94
// RVA : 0x00C8CB94
// PDB : w:\tech5\shared\idlib\math\curve.h
// ========================================================================

void _unwind_514561()
{
  int v0; // r12

  idCurve_Spline<idAngles>::~idCurve_Spline<idAngles>(this: *(idCurve_NonUniformBSpline<idAngles> **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$514562
// EA  : 0x82C8CBBC
// RVA : 0x00C8CBBC
// PDB : w:\tech5\shared\idlib\math\curve.h
// ========================================================================

void _unwind_514562()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 52));
}


// ========================================================================
// __unwind$514563
// EA  : 0x82C8CBE8
// RVA : 0x00C8CBE8
// PDB : w:\tech5\shared\idlib\math\curve.h
// ========================================================================

void _unwind_514563()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 68));
}


// ========================================================================
// ?BasisFirstDerivative@?$idCurve_KochanekBartelsSpline@VidAngles@@@@IBAXHMPAM@Z
// EA  : 0x82C8CC18
// RVA : 0x00C8CC18
// PDB : w:\tech5\shared\idlib\math\curve.h
// ========================================================================

void __fastcall idCurve_KochanekBartelsSpline<idAngles>::BasisFirstDerivative(
        idCurve_KochanekBartelsSpline<idVec3> *this,
        int index,
        double t,
        float *bvals,
        float *a5,
        __int64 a6)
{
  double v9; // fp31
  __int64 v10; // r8
  int v11; // r5
  double v12; // fp30
  __int64 v13; // r8
  int v14; // r5
  double v15; // fp1

  v9 = (float)((float)t
             - idCurve_Spline<idAngles>::TimeForIndex((idCurve_Spline<idVec1> *)this, index, a3: (int)bvals, a4: a6));
  v12 = idCurve_Spline<idAngles>::TimeForIndex((idCurve_Spline<idVec1> *)this, index: index + 1, a3: v11, a4: v10);
  v15 = idCurve_Spline<idAngles>::TimeForIndex((idCurve_Spline<idVec1> *)this, index, a3: v14, a4: v13);
  *a5 = (float)((float)((float)((float)v9 / (float)((float)v12 - (float)v15)) * (float)6.0) - (float)6.0)
      * (float)((float)v9 / (float)((float)v12 - (float)v15));
  a5[1] = (float)((float)6.0 - (float)((float)((float)v9 / (float)((float)v12 - (float)v15)) * (float)6.0))
        * (float)((float)v9 / (float)((float)v12 - (float)v15));
  a5[2] = (float)((float)((float)((float)((float)v9 / (float)((float)v12 - (float)v15)) * (float)3.0) - (float)4.0)
                * (float)((float)v9 / (float)((float)v12 - (float)v15)))
        + (float)1.0;
  a5[3] = (float)((float)((float)((float)v9 / (float)((float)v12 - (float)v15)) * (float)3.0) - (float)2.0)
        * (float)((float)v9 / (float)((float)v12 - (float)v15));
}


// ========================================================================
// ?Clear@?$idCurve_KochanekBartelsSpline@VidAngles@@@@UAAXXZ
// EA  : 0x82C8CCD8
// RVA : 0x00C8CCD8
// PDB : w:\tech5\shared\idlib\math\curve.h
// ========================================================================

void __fastcall idCurve_KochanekBartelsSpline<idAngles>::Clear(idCurve_KochanekBartelsSpline<idVec3> *this)
{
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->values);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->times);
  this->currentIndex = -1;
  this->changed = true;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->tension);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->continuity);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->bias);
}


// ========================================================================
// ?GetCurrentFirstDerivative@?$idCurve_KochanekBartelsSpline@VidVec3@@@@UBA?AVidVec3@@M@Z
// EA  : 0x82C8CD38
// RVA : 0x00C8CD38
// PDB : w:\tech5\shared\idlib\math\curve.h
// ========================================================================

idCurve_KochanekBartelsSpline<idVec3> *__fastcall idCurve_KochanekBartelsSpline<idVec3>::GetCurrentFirstDerivative(
        idCurve_KochanekBartelsSpline<idVec3> *this,
        idCurve_Spline<idVec1> *result,
        double time)
{
  idVec1 *list; // r11
  double x; // fp9
  double v7; // fp8
  double v8; // fp6
  double v9; // fp31
  int v10; // r3
  int v11; // r29
  int v12; // r28
  __int64 v13; // r8
  float *v14; // r5
  float *v15; // r3
  double v16; // fp31
  double v17; // fp30
  double v18; // fp29
  float *v19; // r3
  double v20; // fp31
  double v21; // fp30
  double v22; // fp29
  __int64 v23; // r8
  int v24; // r5
  double v25; // fp28
  __int64 v26; // r8
  int v27; // r5
  double v28; // fp1
  idVec3 v30; // [sp+50h] [-A0h] BYREF
  idVec3 v31; // [sp+60h] [-90h] BYREF
  idCurve_Spline<idVec3> v32; // [sp+70h] [-80h] BYREF

  if ( result->times.num == 1 )
  {
    list = result->values.list;
    x = list[2].x;
    v7 = (float)(list[1].x - list[1].x);
    *(float *)&this->__vftable = list->x - list->x;
    *(float *)&this->times.list = v7;
    v8 = (float)((float)x - (float)x);
  }
  else
  {
    v9 = idCurve_Spline<idVec1>::ClampedTime(this: result, t: time);
    v10 = idCurve<idVec3>::IndexForTime(this: result, time: v9);
    v11 = v10 - 1;
    v12 = v10;
    idCurve_KochanekBartelsSpline<idVec3>::TangentsForIndex(
      this: (idCurve_KochanekBartelsSpline<idVec3> *)result,
      index: v10 - 1,
      t0: &v30,
      t1: &v31);
    idCurve_KochanekBartelsSpline<idAngles>::BasisFirstDerivative(
      this: (idCurve_KochanekBartelsSpline<idVec3> *)result,
      index: v11,
      t: v9,
      bvals: v14,
      a5: (float *)&v32.values.granularity,
      a6: v13);
    v15 = (float *)idCurve_Spline<idVec3>::ValueForIndex(this: &v32, (idVec3 *)result, index: v11);
    v16 = (float)(*v15 * *(float *)&v32.values.granularity);
    v17 = (float)(v15[1] * *(float *)&v32.values.granularity);
    v18 = (float)(v15[2] * *(float *)&v32.values.granularity);
    v19 = (float *)idCurve_Spline<idVec3>::ValueForIndex(
                     this: (idCurve_Spline<idVec3> *)&v32.times.granularity,
                     (idVec3 *)result,
                     index: v12);
    v20 = (float)((float)(v31.x * *(float *)&v32.boundaryType)
                + (float)((float)(v30.x * *(float *)&v32.changed)
                        + (float)((float)(*v19 * *(float *)&v32.currentIndex) + (float)v16)));
    v21 = (float)((float)(v31.y * *(float *)&v32.boundaryType)
                + (float)((float)(v30.y * *(float *)&v32.changed)
                        + (float)((float)(v19[1] * *(float *)&v32.currentIndex) + (float)v17)));
    v22 = (float)((float)(v31.z * *(float *)&v32.boundaryType)
                + (float)((float)(v30.z * *(float *)&v32.changed)
                        + (float)((float)(v19[2] * *(float *)&v32.currentIndex) + (float)v18)));
    v25 = idCurve_Spline<idAngles>::TimeForIndex(this: result, index: v12, a3: v24, a4: v23);
    v28 = idCurve_Spline<idAngles>::TimeForIndex(this: result, index: v11, a3: v27, a4: v26);
    *(float *)&this->__vftable = (float)((float)1.0 / (float)((float)v25 - (float)v28)) * (float)v20;
    *(float *)&this->times.list = (float)((float)1.0 / (float)((float)v25 - (float)v28)) * (float)v21;
    v8 = (float)((float)((float)1.0 / (float)((float)v25 - (float)v28)) * (float)v22);
  }
  *(float *)&this->times.num = v8;
  return this;
}


// ========================================================================
// ??0?$idCurve_NonUniformBSpline@VidAngles@@@@QAA@XZ
// EA  : 0x82C8CFD0
// RVA : 0x00C8CFD0
// PDB : w:\tech5\shared\idlib\math\curve.h
// ========================================================================

idCurve_NonUniformBSpline<idAngles> *__fastcall idCurve_NonUniformBSpline<idAngles>::idCurve_NonUniformBSpline<idAngles>(
        idCurve_NonUniformBSpline<idAngles> *this)
{
  idCurve<idAngles>::idCurve<idAngles>(this);
  this->boundaryType = 0;
  this->__vftable = (idCurve_NonUniformBSpline<idAngles>_vtbl *)&idCurve_NonUniformBSpline<idAngles>::`vftable';
  this->closeTime = 0.0;
  this->order = 4;
  return this;
}


// ========================================================================
// ?Basis@?$idCurve_NonUniformBSpline@VidAngles@@@@IBAXHHMPAM@Z
// EA  : 0x82C8D028
// RVA : 0x00C8D028
// PDB : w:\tech5\shared\idlib\math\curve.h
// ========================================================================

void __fastcall idCurve_NonUniformBSpline<idAngles>::Basis(
        idCurve_NonUniformBSpline<idVec3> *this,
        const int index,
        int order,
        double t,
        float *bvals,
        __int64 a6)
{
  int v8; // r26
  int v9; // r21
  int v10; // r22
  int v11; // r25
  float *v12; // r23
  int v13; // r20
  int v14; // r31
  int v15; // r27
  float *v16; // r29
  int v17; // r28
  int v18; // r10
  signed int v19; // r11
  __int64 v20; // r4
  double v21; // fp12
  int v22; // r6
  double v23; // fp7
  double v24; // fp31
  __int64 v25; // r11
  signed int num; // r9
  __int64 v27; // r4
  double v28; // fp12
  double v29; // fp11
  double v30; // fp27
  __int64 v31; // r8
  int v32; // r5
  double v33; // fp1
  double v34; // fp8

  v8 = order;
  v9 = 2;
  *(float *)(4 * order + HIDWORD(a6) - 4) = 1.0;
  if ( order >= 2 )
  {
    v10 = 4 * index - 4;
    v11 = order - 1;
    v12 = (float *)(4 * (order - 2) + HIDWORD(a6));
    v13 = index - order;
    do
    {
      *v12 = 0.0;
      v14 = v13 + v11;
      if ( v11 < v8 )
      {
        v15 = v10;
        v16 = v12;
        v17 = v8 - v11;
        do
        {
          ++v14;
          v15 += 4;
          v18 = this->times.num - 1;
          if ( v14 >= 0 )
          {
            if ( v14 <= v18 )
            {
              v24 = *(float *)((char *)this->times.list + v15);
            }
            else if ( this->boundaryType == CLOSED )
            {
              num = this->times.num;
              HIDWORD(a6) = this->times.list;
              LODWORD(v27) = v14 / num;
              HIDWORD(v27) = v14 / num * num;
              v28 = (float)(*(float *)(4 * v18 + HIDWORD(a6)) + this->closeTime);
              LODWORD(a6) = v14 % num;
              order = __ROL4__(v14, 1) - 1;
              v29 = *(float *)(4 * (v14 % num) + HIDWORD(a6));
              __twllei(num, 0);
              __twllei(num, 0);
              __twlgei(num & ~order, 0xFFFFFFFF);
              __twlgei(num & ~order, 0xFFFFFFFF);
              v24 = (float)((float)((float)v28 * (float)v27) + (float)v29);
            }
            else
            {
              LODWORD(a6) = v14 - v18;
              v24 = (float)((float)((float)(this->times.list[v18] - this->times.list[v18 - 1]) * (float)a6)
                          + this->times.list[v18]);
            }
          }
          else if ( this->boundaryType == CLOSED )
          {
            v19 = this->times.num;
            HIDWORD(a6) = this->times.list;
            LODWORD(v20) = v14 / v19;
            HIDWORD(v20) = v14 / v19 * v19;
            v21 = (float)(*(float *)(4 * v18 + HIDWORD(a6)) + this->closeTime);
            v22 = v14 % v19 + v19;
            LODWORD(a6) = __ROL4__(v22, 1);
            order = __ROL4__(v14, 1) - 1;
            v23 = (float)((float)(*(float *)(4 * v18 + HIDWORD(a6)) + this->closeTime)
                        - *(float *)(4 * (v22 % v19) + HIDWORD(a6)));
            __twllei(v19, 0);
            __twllei(v19, 0);
            __twllei(v19, 0);
            __twlgei(v19 & ~order, 0xFFFFFFFF);
            __twlgei(v19 & ~order, 0xFFFFFFFF);
            __twlgei(v19 & ~(a6 - 1), 0xFFFFFFFF);
            v24 = (float)((float)((float)v20 * (float)v21) - (float)v23);
          }
          else
          {
            LODWORD(v25) = v14;
            HIDWORD(v25) = this->times.list;
            v24 = (float)((float)((float)(*(float *)(HIDWORD(v25) + 4) - *(float *)HIDWORD(v25)) * (float)v25)
                        + *(float *)HIDWORD(v25));
          }
          v30 = idCurve_Spline<idAngles>::TimeForIndex(
                  (idCurve_Spline<idVec1> *)this,
                  index: v9 - 1 + v14,
                  a3: order,
                  a4: a6);
          v33 = idCurve_Spline<idAngles>::TimeForIndex((idCurve_Spline<idVec1> *)this, index: v14, a3: v32, a4: v31);
          --v17;
          v34 = (float)(v16[1] * (float)((float)((float)t - (float)v24) / (float)((float)v30 - (float)v33)));
          *v16 = (float)((float)((float)1.0 - (float)((float)((float)t - (float)v24) / (float)((float)v30 - (float)v33)))
                       * v16[1])
               + *v16;
          *++v16 = v34;
        }
        while ( v17 != 0 );
      }
      ++v9;
      --v12;
      v10 -= 4;
      --v11;
    }
    while ( v9 <= v8 );
  }
}


// ========================================================================
// ?BasisFirstDerivative@?$idCurve_NonUniformBSpline@VidAngles@@@@IBAXHHMPAM@Z
// EA  : 0x82C8D2D0
// RVA : 0x00C8D2D0
// PDB : w:\tech5\shared\idlib\math\curve.h
// ========================================================================

void __fastcall idCurve_NonUniformBSpline<idAngles>::BasisFirstDerivative(
        idCurve_NonUniformBSpline<idVec3> *this,
        int index,
        const int order,
        double t,
        float *bvals,
        __int64 a6)
{
  int v6; // r29
  float *v8; // r27
  __int64 v11; // r10
  __int64 v12; // r8
  int v13; // r5
  int v14; // r31
  double v15; // fp31
  float *v16; // r30
  double v17; // fp30
  double v18; // fp29
  __int64 v19; // r8
  int v20; // r5
  double v21; // fp1
  double v22; // fp31
  __int64 v23; // r8
  int v24; // r5
  __int64 v25; // [sp+50h] [-70h]

  v6 = order - 1;
  v8 = (float *)HIDWORD(a6);
  HIDWORD(a6) += 4;
  idCurve_NonUniformBSpline<idAngles>::Basis(this, index, order: order - 1, t, bvals, a6);
  v14 = 0;
  *v8 = 0.0;
  if ( v6 > 0 )
  {
    LODWORD(v11) = v6;
    v15 = (float)v11;
    v16 = v8 - 1;
    do
    {
      v17 = (float)(v16[1] - v16[2]);
      v16[1] = v16[1] - v16[2];
      v18 = idCurve_Spline<idAngles>::TimeForIndex(
              (idCurve_Spline<idVec1> *)this,
              index: index + order - 3 + v14,
              a3: v13,
              a4: v12);
      v21 = idCurve_Spline<idAngles>::TimeForIndex(
              (idCurve_Spline<idVec1> *)this,
              index: index - 2 + v14++,
              a3: v20,
              a4: v19);
      *++v16 = (float)((float)v15 / (float)((float)v18 - (float)v21)) * (float)v17;
    }
    while ( v14 < v6 );
  }
  LODWORD(v11) = v6;
  v25 = v11;
  v22 = idCurve_Spline<idAngles>::TimeForIndex(
          (idCurve_Spline<idVec1> *)this,
          index: v14 + index + order - 3,
          a3: v13,
          a4: v12);
  v8[v14] = (float)((float)v25
                  / (float)((float)v22
                          - idCurve_Spline<idAngles>::TimeForIndex(
                              (idCurve_Spline<idVec1> *)this,
                              index: v14 + index - 2,
                              a3: v24,
                              a4: v23)))
          * v8[v14];
}


// ========================================================================
// ?GetCurrentValue@?$idCurve_NonUniformBSpline@VidAngles@@@@UBA?AVidAngles@@M@Z
// EA  : 0x82C8D3F0
// RVA : 0x00C8D3F0
// PDB : w:\tech5\shared\idlib\math\curve.h
// ========================================================================

idCurve_NonUniformBSpline<idVec3> *__fastcall idCurve_NonUniformBSpline<idAngles>::GetCurrentValue(
        idCurve_NonUniformBSpline<idVec3> *this,
        idCurve_Spline<idVec1> *result,
        double time)
{
  float v5; // r11
  float *v6; // r9
  int v7; // r8
  double v8; // fp31
  int v9; // r3
  int v10; // r28
  int v11; // r26
  __int64 v12; // r8
  float *v13; // r6
  idVec1 *list; // r11
  int v15; // r31
  double v16; // fp31
  double v17; // fp30
  double v18; // fp29
  int *p_size; // r29
  float *v20; // r3
  float v22; // [sp+50h] [-A0h]
  float v23; // [sp+54h] [-9Ch]
  int v24; // [sp+58h] [-98h]
  idCurve_Spline<idVec3> v25; // [sp+60h] [-90h] BYREF

  if ( result->times.num == 1 )
  {
    v5 = *(float *)&result->values.list;
    v6 = *(float **)(LODWORD(v5) + 4);
    v7 = *(_DWORD *)(LODWORD(v5) + 8);
    this->__vftable = *(idCurve_NonUniformBSpline<idVec3>_vtbl **)LODWORD(v5);
    this->times.list = v6;
    this->times.num = v7;
  }
  else
  {
    v8 = idCurve_Spline<idVec1>::ClampedTime(this: result, t: time);
    v9 = idCurve<idVec3>::IndexForTime(this: result, time: v8);
    v10 = (int)result[1].__vftable;
    v11 = v9;
    HIDWORD(v12) = &v25.times.granularity;
    idCurve_NonUniformBSpline<idAngles>::Basis(
      this: (idCurve_NonUniformBSpline<idVec3> *)result,
      index: v9 - 1,
      order: v10,
      t: v8,
      bvals: v13,
      a6: v12);
    list = result->values.list;
    v15 = 0;
    v16 = (float)(list->x - list->x);
    v17 = (float)(list[1].x - list[1].x);
    v18 = (float)(list[2].x - list[2].x);
    v22 = list->x - list->x;
    v23 = list[1].x - list[1].x;
    *(float *)&v24 = list[2].x - list[2].x;
    if ( v10 > 0 )
    {
      p_size = &v25.times.size;
      do
      {
        v20 = (float *)idCurve_Spline<idVec3>::ValueForIndex(
                         this: &v25,
                         (idVec3 *)result,
                         index: v15 - (v10 >> 1) + v11);
        ++p_size;
        ++v15;
        v16 = (float)((float)(*v20 * *(float *)p_size) + (float)v16);
        v17 = (float)((float)(v20[1] * *(float *)p_size) + (float)v17);
        v18 = (float)((float)(v20[2] * *(float *)p_size) + (float)v18);
      }
      while ( v15 < v10 );
      *(float *)&v24 = v18;
      v23 = v17;
      v22 = v16;
    }
    *(float *)&this->__vftable = v22;
    *(float *)&this->times.list = v23;
    this->times.num = v24;
  }
  return this;
}


// ========================================================================
// ?GetCurrentFirstDerivative@?$idCurve_NonUniformBSpline@VidAngles@@@@UBA?AVidAngles@@M@Z
// EA  : 0x82C8D540
// RVA : 0x00C8D540
// PDB : w:\tech5\shared\idlib\math\curve.h
// ========================================================================

idCurve_NonUniformBSpline<idVec3> *__fastcall idCurve_NonUniformBSpline<idAngles>::GetCurrentFirstDerivative(
        idCurve_NonUniformBSpline<idVec3> *this,
        idCurve_Spline<idVec1> *result,
        double time)
{
  idVec1 *list; // r11
  double v6; // fp8
  double v7; // fp6
  double v8; // fp31
  int v9; // r3
  int v10; // r28
  int v11; // r26
  __int64 v12; // r8
  float *v13; // r6
  idVec1 *v14; // r11
  int v15; // r31
  double v16; // fp31
  double v17; // fp30
  double v18; // fp29
  int *p_size; // r29
  float *v20; // r3
  float v22; // [sp+50h] [-A0h]
  float v23; // [sp+54h] [-9Ch]
  int v24; // [sp+58h] [-98h]
  idCurve_Spline<idVec3> v25; // [sp+60h] [-90h] BYREF

  if ( result->times.num == 1 )
  {
    list = result->values.list;
    v6 = (float)(list[1].x - list[1].x);
    v7 = (float)(list[2].x - list[2].x);
    *(float *)&this->__vftable = list->x - list->x;
    *(float *)&this->times.list = v6;
    *(float *)&this->times.num = v7;
  }
  else
  {
    v8 = idCurve_Spline<idVec1>::ClampedTime(this: result, t: time);
    v9 = idCurve<idVec3>::IndexForTime(this: result, time: v8);
    v10 = (int)result[1].__vftable;
    v11 = v9;
    HIDWORD(v12) = &v25.times.granularity;
    idCurve_NonUniformBSpline<idAngles>::BasisFirstDerivative(
      this: (idCurve_NonUniformBSpline<idVec3> *)result,
      index: v9 - 1,
      order: v10,
      t: v8,
      bvals: v13,
      a6: v12);
    v14 = result->values.list;
    v15 = 0;
    v16 = (float)(v14->x - v14->x);
    v17 = (float)(v14[1].x - v14[1].x);
    v18 = (float)(v14[2].x - v14[2].x);
    v22 = v14->x - v14->x;
    v23 = v14[1].x - v14[1].x;
    *(float *)&v24 = v14[2].x - v14[2].x;
    if ( v10 > 0 )
    {
      p_size = &v25.times.size;
      do
      {
        v20 = (float *)idCurve_Spline<idVec3>::ValueForIndex(
                         this: &v25,
                         (idVec3 *)result,
                         index: v15 - (v10 >> 1) + v11);
        ++p_size;
        ++v15;
        v16 = (float)((float)(*v20 * *(float *)p_size) + (float)v16);
        v17 = (float)((float)(v20[1] * *(float *)p_size) + (float)v17);
        v18 = (float)((float)(v20[2] * *(float *)p_size) + (float)v18);
      }
      while ( v15 < v10 );
      *(float *)&v24 = v18;
      v23 = v17;
      v22 = v16;
    }
    *(float *)&this->__vftable = v22;
    *(float *)&this->times.list = v23;
    this->times.num = v24;
  }
  return this;
}


// ========================================================================
// ??0?$idCurve_NURBS@VidAngles@@@@QAA@XZ
// EA  : 0x82C8D6B0
// RVA : 0x00C8D6B0
// PDB : w:\tech5\shared\idlib\math\curve.h
// ========================================================================

idCurve_NURBS<idAngles> *__fastcall idCurve_NURBS<idAngles>::idCurve_NURBS<idAngles>(idCurve_NURBS<idAngles> *this)
{
  idCurve<idAngles>::idCurve<idAngles>(this);
  this->boundaryType = 0;
  this->order = 4;
  this->closeTime = 0.0;
  this->__vftable = (idCurve_NURBS<idAngles>_vtbl *)&idCurve_NURBS<idAngles>::`vftable';
  this->weights.list = nullptr;
  this->weights.granularity = 0;
  this->weights.memTag = 116;
  this->weights.listStatic = 0;
  this->weights.size = 0;
  this->weights.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->weights);
  return this;
}


// ========================================================================
// __unwind$515742
// EA  : 0x82C8D73C
// RVA : 0x00C8D73C
// PDB : w:\tech5\shared\idlib\math\curve.h
// ========================================================================

void _unwind_515742()
{
  int v0; // r12

  idCurve_Spline<idAngles>::~idCurve_Spline<idAngles>(this: *(idCurve_NonUniformBSpline<idAngles> **)(v0 - 112 + 132));
}


// ========================================================================
// ?RemoveIndex@?$idCurve_NURBS@VidVec3@@@@UAAXH@Z
// EA  : 0x82C8D768
// RVA : 0x00C8D768
// PDB : w:\tech5\shared\idlib\math\curve.h
// ========================================================================

void __fastcall idCurve_NURBS<idVec3>::RemoveIndex(idCurve_NURBS<idVec3> *this, int index)
{
  idList<idAngles,5>::RemoveIndex(this: &this->values, index);
  idList<float,5>::RemoveIndex(this: &this->times, index);
  idList<float,5>::RemoveIndex(this: &this->weights, index);
}


// ========================================================================
// ?WeightForIndex@?$idCurve_NURBS@VidAngles@@@@IBAMH@Z
// EA  : 0x82C8D7C0
// RVA : 0x00C8D7C0
// PDB : w:\tech5\shared\idlib\math\curve.h
// ========================================================================

float __fastcall idCurve_NURBS<idAngles>::WeightForIndex(
        idCurve_NURBS<idVec3> *this,
        const int index,
        int a3,
        int a4,
        __int64 a5)
{
  signed int num; // r10
  int v6; // r11
  boundary_t::eType v7; // r11
  signed int v8; // r11
  float *v9; // r9
  int v10; // r10
  int v11; // r8
  int v12; // r4
  double v13; // fp1
  __int64 v14; // r11
  boundary_t::eType boundaryType; // r9
  float *list; // r8

  num = this->weights.num;
  v6 = num - 1;
  if ( index >= 0 )
  {
    if ( index > v6 )
    {
      boundaryType = this->boundaryType;
      if ( boundaryType == 0 )
      {
        LODWORD(a5) = index - v6;
        v13 = (float)((float)((float)(this->weights.list[v6] - this->weights.list[v6 - 1]) * (float)a5)
                    + this->weights.list[v6]);
        return *((float *)&v13 + 1);
      }
      if ( boundaryType == CLAMPED )
      {
        v13 = this->weights.list[v6];
        return *((float *)&v13 + 1);
      }
      if ( (unsigned int)boundaryType < (CLAMPED|CLOSED) )
      {
        list = this->weights.list;
        __twllei(num, 0);
        __twlgei(num & ~(__ROL4__(index, 1) - 1), 0xFFFFFFFF);
        v13 = list[index % num];
        return *((float *)&v13 + 1);
      }
    }
    goto LABEL_15;
  }
  v7 = this->boundaryType;
  if ( v7 == 0 )
  {
    LODWORD(v14) = index;
    HIDWORD(v14) = this->weights.list;
    v13 = (float)((float)((float)(*(float *)(HIDWORD(v14) + 4) - *(float *)HIDWORD(v14)) * (float)v14)
                + *(float *)HIDWORD(v14));
    return *((float *)&v13 + 1);
  }
  if ( v7 == CLAMPED )
  {
    v13 = *this->weights.list;
    return *((float *)&v13 + 1);
  }
  if ( (unsigned int)v7 >= (CLAMPED|CLOSED) )
  {
LABEL_15:
    v13 = this->weights.list[index];
    return *((float *)&v13 + 1);
  }
  v8 = this->weights.num;
  v9 = this->weights.list;
  v11 = index / num;
  v10 = __ROL4__(index, 1);
  v12 = index - v11 * v8 + v8;
  __twlgei(v8 & ~(v10 - 1), 0xFFFFFFFF);
  __twllei(v8, 0);
  __twllei(v8, 0);
  __twlgei(v8 & ~(__ROL4__(v12, 1) - 1), 0xFFFFFFFF);
  v13 = v9[v12 % v8];
  return *((float *)&v13 + 1);
}


// ========================================================================
// ?GetCurrentFirstDerivative@?$idCurve_NURBS@VidAngles@@@@UBA?AVidAngles@@M@Z
// EA  : 0x82C8D920
// RVA : 0x00C8D920
// PDB : w:\tech5\shared\idlib\math\curve.h
// ========================================================================

idCurve_NURBS<idVec3> *__fastcall idCurve_NURBS<idAngles>::GetCurrentFirstDerivative(
        idCurve_NURBS<idVec3> *this,
        idCurve_Spline<idVec1> *result,
        double time)
{
  float *v3; // r24
  float v5; // r11
  float *v6; // r9
  int v7; // r8
  double v8; // fp31
  int v9; // r3
  int v10; // r27
  int v11; // r30
  int v12; // r26
  __int64 v13; // r8
  float *v14; // r6
  __int64 v15; // r8
  float *v16; // r6
  int v17; // r6
  int v18; // r5
  idVec1 *list; // r11
  int v20; // r29
  double v21; // fp25
  double v22; // fp24
  double v23; // fp26
  __int64 v24; // r8
  double v25; // fp31
  double v26; // fp28
  double v27; // fp29
  double v28; // fp27
  double v29; // fp30
  int v30; // r25
  int v31; // r30
  double v32; // fp1
  double v33; // fp23
  double v34; // fp22
  idCurve_Spline<idVec3> v36; // [sp+50h] [-100h] BYREF
  _BYTE v37[120]; // [sp+90h] [-C0h] BYREF

  v3 = (float *)this;
  if ( result->times.num == 1 )
  {
    v5 = *(float *)&result->values.list;
    v6 = *(float **)(LODWORD(v5) + 4);
    v7 = *(_DWORD *)(LODWORD(v5) + 8);
    this->__vftable = *(idCurve_NURBS<idVec3>_vtbl **)LODWORD(v5);
    this->times.list = v6;
    this->times.num = v7;
  }
  else
  {
    v8 = idCurve_Spline<idVec1>::ClampedTime(this: result, t: time);
    v9 = idCurve<idVec3>::IndexForTime(this: result, time: v8);
    v10 = (int)result[1].__vftable;
    v11 = v9 - 1;
    v12 = v9;
    HIDWORD(v13) = &v36.times.granularity;
    idCurve_NonUniformBSpline<idAngles>::Basis(
      this: (idCurve_NonUniformBSpline<idVec3> *)result,
      index: v9 - 1,
      order: v10,
      t: v8,
      bvals: v14,
      a6: v13);
    HIDWORD(v15) = v37;
    idCurve_NonUniformBSpline<idAngles>::BasisFirstDerivative(
      this: (idCurve_NonUniformBSpline<idVec3> *)result,
      index: v11,
      order: v10,
      t: v8,
      bvals: v16,
      a6: v15);
    list = result->values.list;
    v20 = 0;
    v21 = (float)(list[1].x - list[1].x);
    v22 = (float)(list[2].x - list[2].x);
    *(float *)&v36.times.list = list[1].x - list[1].x;
    *(float *)&v36.times.num = v22;
    LODWORD(v24) = v36.times.num;
    v23 = (float)(list->x - list->x);
    *(float *)&v36.__vftable = list->x - list->x;
    HIDWORD(v24) = v36.__vftable;
    v25 = 0.0;
    v26 = *(float *)&v36.times.list;
    v27 = *(float *)&v36.times.num;
    v28 = *(float *)&v36.__vftable;
    v29 = 0.0;
    if ( v10 > 0 )
    {
      v30 = v10 >> 1;
      v31 = 0;
      do
      {
        v32 = idCurve_NURBS<idAngles>::WeightForIndex(
                this: (idCurve_NURBS<idVec3> *)result,
                index: v20 - v30 + v12,
                a3: v18,
                a4: v17,
                a5: v24);
        v33 = (float)(*(float *)((char *)&v36.times.granularity + v31) * (float)v32);
        v34 = (float)(*(float *)&v37[v31] * (float)v32);
        v25 = (float)((float)(*(float *)((char *)&v36.times.granularity + v31) * (float)v32) + (float)v25);
        v29 = (float)((float)(*(float *)&v37[v31] * (float)v32) + (float)v29);
        idCurve_Spline<idVec3>::ValueForIndex(this: &v36, (idVec3 *)result, index: v20 - v30 + v12);
        ++v20;
        v31 += 4;
        v23 = (float)((float)(*(float *)&v36.__vftable * (float)v33) + (float)v23);
        v21 = (float)((float)(*(float *)&v36.times.list * (float)v33) + (float)v21);
        v22 = (float)((float)(*(float *)&v36.times.num * (float)v33) + (float)v22);
        v28 = (float)((float)(*(float *)&v36.__vftable * (float)v34) + (float)v28);
        v26 = (float)((float)v26 + (float)(*(float *)&v36.times.list * (float)v34));
        v27 = (float)((float)v27 + (float)(*(float *)&v36.times.num * (float)v34));
      }
      while ( v20 < v10 );
    }
    *v3 = (float)((float)((float)v28 * (float)v25) - (float)((float)v23 * (float)v29))
        * (float)((float)1.0 / (float)((float)v25 * (float)v25));
    v3[1] = (float)((float)((float)v26 * (float)v25) - (float)((float)v21 * (float)v29))
          * (float)((float)1.0 / (float)((float)v25 * (float)v25));
    v3[2] = (float)((float)((float)v27 * (float)v25) - (float)((float)v22 * (float)v29))
          * (float)((float)1.0 / (float)((float)v25 * (float)v25));
    return (idCurve_NURBS<idVec3> *)v3;
  }
  return this;
}


// ========================================================================
// ??0?$idCurve_CubicBezierSpline@VidAngles@@@@QAA@XZ
// EA  : 0x82C8DBA8
// RVA : 0x00C8DBA8
// PDB : w:\tech5\shared\idlib\math\curve.h
// ========================================================================

idCurve_CubicBezierSpline<idAngles> *__fastcall idCurve_CubicBezierSpline<idAngles>::idCurve_CubicBezierSpline<idAngles>(
        idCurve_CubicBezierSpline<idAngles> *this)
{
  idCurve<idAngles>::idCurve<idAngles>(this);
  this->boundaryType = 0;
  this->__vftable = (idCurve_CubicBezierSpline<idAngles>_vtbl *)&idCurve_CubicBezierSpline<idAngles>::`vftable';
  this->closeTime = 0.0;
  this->order = 4;
  return this;
}


// ========================================================================
// ?GetCurrentSecondDerivative@?$idCurve_CubicBezierSpline@VidVec3@@@@UBA?AVidVec3@@M@Z
// EA  : 0x82C8DC00
// RVA : 0x00C8DC00
// PDB : w:\tech5\shared\idlib\math\curve.h
// ========================================================================

idCurve_CubicBezierSpline<idVec3> *__fastcall idCurve_CubicBezierSpline<idVec3>::GetCurrentSecondDerivative(
        idCurve_CubicBezierSpline<idVec3> *this,
        idCurve_Spline<idVec1> *result,
        double time,
        int a4,
        int a5,
        __int64 a6)
{
  float v6; // r10
  int v10; // r31
  int v11; // r11
  double v12; // fp30
  double v13; // fp31
  __int64 v14; // r8
  int v15; // r5
  double v16; // fp1
  float v17; // r9
  float *v18; // r11
  float *v19; // r10
  double v20; // fp1
  double v21; // fp10
  double v22; // fp3
  double v23; // fp0
  double v24; // fp10
  double v25; // fp8
  double v26; // fp7
  double v27; // fp4
  double v28; // fp2
  double v29; // fp1

  v6 = *(float *)&result->times.list;
  v10 = 0;
  if ( *(float *)(LODWORD(v6) + 12) < time )
  {
    v11 = 12;
    do
    {
      v11 += 12;
      v10 += 3;
    }
    while ( *(float *)(v11 + LODWORD(v6)) < time );
  }
  v12 = idCurve_Spline<idAngles>::TimeForIndex(this: result, index: v10, a3: a4, a4: a6);
  v13 = (float)((float)time - (float)v12);
  v16 = idCurve_Spline<idAngles>::TimeForIndex(this: result, index: v10 + 3, a3: v15, a4: v14);
  v17 = *(float *)&result->values.list;
  v18 = (float *)(12 * v10 + LODWORD(v17));
  v19 = (float *)(12 * (v10 + 2) + LODWORD(v17));
  v21 = (float)(result->times.list[v10 + 3] - result->times.list[v10]);
  v23 = (float)((float)v21 * (float)v21);
  v24 = (float)(v18[3]
              * (float)((float)((float)((float)v13 / (float)((float)v16 - (float)v12)) * (float)18.0) - (float)12.0));
  v25 = (float)(v18[4]
              * (float)((float)((float)((float)v13 / (float)((float)v16 - (float)v12)) * (float)18.0) - (float)12.0));
  v26 = (float)(v18[5]
              * (float)((float)((float)((float)v13 / (float)((float)v16 - (float)v12)) * (float)18.0) - (float)12.0));
  v22 = (float)((float)6.0 - (float)((float)((float)v13 / (float)((float)v16 - (float)v12)) * (float)18.0));
  v20 = (float)((float)((float)v13 / (float)((float)v16 - (float)v12)) * (float)6.0);
  v27 = (float)((float)((float)((float)(*v18 * (float)((float)6.0 - (float)v20)) + (float)v24)
                      + (float)(*v19 * (float)v22))
              + (float)(*(float *)(12 * (v10 + 3) + LODWORD(v17)) * (float)v20));
  v28 = (float)((float)((float)((float)(v18[1] * (float)((float)6.0 - (float)v20)) + (float)v25)
                      + (float)(v19[1] * (float)v22))
              + (float)(*(float *)(12 * (v10 + 3) + LODWORD(v17) + 4) * (float)v20));
  v29 = (float)((float)((float)((float)(v18[2] * (float)((float)6.0 - (float)v20)) + (float)v26)
                      + (float)(v19[2] * (float)v22))
              + (float)(*(float *)(12 * (v10 + 3) + LODWORD(v17) + 8) * (float)v20));
  *(float *)&this->__vftable = (float)v27 * (float)((float)1.0 / (float)v23);
  *(float *)&this->times.list = (float)v28 * (float)((float)1.0 / (float)v23);
  *(float *)&this->times.num = (float)v29 * (float)((float)1.0 / (float)v23);
  return this;
}


// ========================================================================
// ?GetLengthForTime@?$idCurve_CubicBezierSpline@VidAngles@@@@MBAMM@Z
// EA  : 0x82C8DDB8
// RVA : 0x00C8DDB8
// PDB : w:\tech5\shared\idlib\math\curve.h
// ========================================================================

float __fastcall idCurve_CubicBezierSpline<idAngles>::GetLengthForTime(
        idCurve_CubicBezierSpline<idVec3> *this,
        double time,
        int a3,
        int a4)
{
  float *list; // r10
  int v7; // r28
  double v8; // fp31
  int v9; // r11
  int v10; // r11
  unsigned int v11; // r30
  int v12; // r31
  double v13; // fp1

  list = this->times.list;
  v7 = 0;
  v8 = 0.0;
  if ( list[3] < time )
  {
    v9 = 3;
    do
    {
      v9 += 3;
      v7 += 3;
    }
    while ( list[v9] < time );
  }
  if ( v7 > 0 )
  {
    v10 = 0;
    v11 = (v7 - 1) / 3u + 1;
    do
    {
      v12 = v10 + 12;
      --v11;
      v8 = (float)(idCurve<idVec3>::RombergIntegral(
                     this,
                     t0: *(float *)((char *)this->times.list + v10),
                     t1: *(float *)((char *)this->times.list + v10 + 12),
                     order: a3,
                     a5: a4,
                     a6: 5)
                 + (float)v8);
      v10 = v12;
    }
    while ( v11 != 0 );
  }
  v13 = (float)(idCurve<idVec3>::RombergIntegral(this, t0: this->times.list[v7], t1: time, order: a3, a5: a4, a6: 5)
              + (float)v8);
  return *((float *)&v13 + 1);
}


// ========================================================================
// ??0?$idCurve_CatmullRomSpline@VidVec3@@@@QAA@XZ
// EA  : 0x82C8F028
// RVA : 0x00C8F028
// PDB : w:\tech5\shared\idlib\math\curve.h
// ========================================================================

idCurve_CatmullRomSpline<idVec3> *__fastcall idCurve_CatmullRomSpline<idVec3>::idCurve_CatmullRomSpline<idVec3>(
        idCurve_CatmullRomSpline<idVec3> *this)
{
  idCurve<idVec3>::idCurve<idVec3>(this);
  this->boundaryType = 0;
  this->__vftable = (idCurve_CatmullRomSpline<idVec3>_vtbl *)&idCurve_CatmullRomSpline<idVec3>::`vftable';
  this->closeTime = 0.0;
  return this;
}


// ========================================================================
// ?BasisFirstDerivative@?$idCurve_CatmullRomSpline@VidAngles@@@@IBAXHMPAM@Z
// EA  : 0x82C8F078
// RVA : 0x00C8F078
// PDB : w:\tech5\shared\idlib\math\curve.h
// ========================================================================

void __fastcall idCurve_CatmullRomSpline<idAngles>::BasisFirstDerivative(
        idCurve_CatmullRomSpline<idVec1> *this,
        int index,
        double t,
        float *bvals,
        float *a5,
        __int64 a6)
{
  double v9; // fp31
  __int64 v10; // r8
  int v11; // r5
  double v12; // fp30
  __int64 v13; // r8
  int v14; // r5
  double v15; // fp1
  double v16; // fp8

  v9 = (float)((float)t - idCurve_Spline<idAngles>::TimeForIndex(this, index, a3: (int)bvals, a4: a6));
  v12 = idCurve_Spline<idAngles>::TimeForIndex(this, index: index + 1, a3: v11, a4: v10);
  v15 = idCurve_Spline<idAngles>::TimeForIndex(this, index, a3: v14, a4: v13);
  v16 = (float)((float)v9 / (float)((float)v12 - (float)v15));
  *a5 = (float)((float)-(float)((float)((float)((float)v9 / (float)((float)v12 - (float)v15)) * (float)1.5) - (float)2.0)
              * (float)((float)v9 / (float)((float)v12 - (float)v15)))
      - (float)0.5;
  a5[3] = (float)((float)((float)v16 * (float)v16) * (float)1.5) - (float)v16;
  a5[1] = (float)((float)((float)((float)v9 / (float)((float)v12 - (float)v15)) * (float)4.5) - (float)5.0)
        * (float)((float)v9 / (float)((float)v12 - (float)v15));
  a5[2] = (float)((float)((float)4.0 - (float)((float)((float)v9 / (float)((float)v12 - (float)v15)) * (float)4.5))
                * (float)((float)v9 / (float)((float)v12 - (float)v15)))
        + (float)0.5;
}


// ========================================================================
// ?BasisSecondDerivative@?$idCurve_CatmullRomSpline@VidAngles@@@@IBAXHMPAM@Z
// EA  : 0x82C8F140
// RVA : 0x00C8F140
// PDB : w:\tech5\shared\idlib\math\curve.h
// ========================================================================

void __fastcall idCurve_CatmullRomSpline<idAngles>::BasisSecondDerivative(
        idCurve_CatmullRomSpline<idVec1> *this,
        int index,
        double t,
        float *bvals,
        float *a5,
        __int64 a6)
{
  double v9; // fp31
  __int64 v10; // r8
  int v11; // r5
  double v12; // fp30
  __int64 v13; // r8
  int v14; // r5
  double v15; // fp1

  v9 = (float)((float)t - idCurve_Spline<idAngles>::TimeForIndex(this, index, a3: (int)bvals, a4: a6));
  v12 = idCurve_Spline<idAngles>::TimeForIndex(this, index: index + 1, a3: v11, a4: v10);
  v15 = idCurve_Spline<idAngles>::TimeForIndex(this, index, a3: v14, a4: v13);
  *a5 = (float)2.0 - (float)((float)((float)v9 / (float)((float)v12 - (float)v15)) * (float)3.0);
  a5[1] = (float)((float)((float)v9 / (float)((float)v12 - (float)v15)) * (float)9.0) - (float)5.0;
  a5[2] = (float)4.0 - (float)((float)((float)v9 / (float)((float)v12 - (float)v15)) * (float)9.0);
  a5[3] = (float)((float)((float)v9 / (float)((float)v12 - (float)v15)) * (float)3.0) - (float)1.0;
}


// ========================================================================
// ?GetCurrentFirstDerivative@?$idCurve_CatmullRomSpline@VidVec3@@@@UBA?AVidVec3@@M@Z
// EA  : 0x82C8F1F8
// RVA : 0x00C8F1F8
// PDB : w:\tech5\shared\idlib\math\curve.h
// ========================================================================

idCurve_CatmullRomSpline<idVec3> *__fastcall idCurve_CatmullRomSpline<idVec3>::GetCurrentFirstDerivative(
        idCurve_CatmullRomSpline<idVec3> *this,
        idCurve_CatmullRomSpline<idVec1> *result,
        double time)
{
  idVec1 *list; // r11
  double x; // fp0
  double v7; // fp6
  double v8; // fp11
  double v9; // fp31
  int v10; // r3
  int v11; // r25
  int v12; // r28
  __int64 v13; // r8
  float *v14; // r5
  idVec1 *v15; // r10
  int v16; // r30
  int *p_size; // r29
  double v18; // fp31
  double v19; // fp30
  double v20; // fp29
  __int64 v21; // r8
  int v22; // r5
  float *v23; // r3
  double v24; // fp28
  __int64 v25; // r8
  int v26; // r5
  double v27; // fp1
  idCurve_Spline<idVec3> v29; // [sp+50h] [-80h] BYREF

  if ( result->times.num == 1 )
  {
    list = result->values.list;
    x = list->x;
    v7 = (float)(list[2].x - list[2].x);
    *(float *)&this->times.list = list[1].x - list[1].x;
    *(float *)&this->times.num = v7;
    v8 = (float)((float)x - (float)x);
  }
  else
  {
    v9 = idCurve_Spline<idVec1>::ClampedTime(this: result, t: time);
    v10 = idCurve<idVec3>::IndexForTime(this: result, time: v9);
    v11 = v10 - 1;
    v12 = v10;
    idCurve_CatmullRomSpline<idAngles>::BasisFirstDerivative(
      this: result,
      index: v10 - 1,
      t: v9,
      bvals: v14,
      a5: (float *)&v29.times.granularity,
      a6: v13);
    v15 = result->values.list;
    v16 = 0;
    p_size = &v29.times.size;
    v18 = (float)(v15->x - v15->x);
    v19 = (float)(v15[1].x - v15[1].x);
    v20 = (float)(v15[2].x - v15[2].x);
    do
    {
      v23 = (float *)idCurve_Spline<idVec3>::ValueForIndex(this: &v29, (idVec3 *)result, index: v12 - 2 + v16);
      ++p_size;
      ++v16;
      v18 = (float)((float)(*v23 * *(float *)p_size) + (float)v18);
      v19 = (float)((float)(v23[1] * *(float *)p_size) + (float)v19);
      v20 = (float)((float)(v23[2] * *(float *)p_size) + (float)v20);
    }
    while ( v16 < 4 );
    v24 = idCurve_Spline<idAngles>::TimeForIndex(this: result, index: v12, a3: v22, a4: v21);
    v27 = idCurve_Spline<idAngles>::TimeForIndex(this: result, index: v11, a3: v26, a4: v25);
    *(float *)&this->times.list = (float)((float)1.0 / (float)((float)v24 - (float)v27)) * (float)v19;
    *(float *)&this->times.num = (float)((float)1.0 / (float)((float)v24 - (float)v27)) * (float)v20;
    v8 = (float)((float)((float)1.0 / (float)((float)v24 - (float)v27)) * (float)v18);
  }
  *(float *)&this->__vftable = v8;
  return this;
}


// ========================================================================
// ?GetCurrentSecondDerivative@?$idCurve_CatmullRomSpline@VidAngles@@@@UBA?AVidAngles@@M@Z
// EA  : 0x82C8F358
// RVA : 0x00C8F358
// PDB : w:\tech5\shared\idlib\math\curve.h
// ========================================================================

idCurve_CatmullRomSpline<idVec3> *__fastcall idCurve_CatmullRomSpline<idAngles>::GetCurrentSecondDerivative(
        idCurve_CatmullRomSpline<idVec3> *this,
        idCurve_CatmullRomSpline<idVec1> *result,
        double time)
{
  float *v3; // r26
  idVec1 *list; // r11
  double v6; // fp8
  double v7; // fp6
  double v8; // fp31
  int v9; // r3
  int v10; // r25
  int v11; // r28
  __int64 v12; // r8
  float *v13; // r5
  idVec1 *v14; // r10
  int v15; // r30
  int *p_size; // r29
  double v17; // fp31
  double v18; // fp30
  double v19; // fp29
  __int64 v20; // r8
  int v21; // r5
  float *v22; // r3
  double v23; // fp28
  __int64 v24; // r8
  int v25; // r5
  double v26; // fp1
  idCurve_Spline<idVec3> v28; // [sp+50h] [-80h] BYREF

  v3 = (float *)this;
  if ( result->times.num == 1 )
  {
    list = result->values.list;
    v6 = (float)(list[1].x - list[1].x);
    v7 = (float)(list[2].x - list[2].x);
    *(float *)&this->__vftable = list->x - list->x;
    *(float *)&this->times.list = v6;
    *(float *)&this->times.num = v7;
  }
  else
  {
    v8 = idCurve_Spline<idVec1>::ClampedTime(this: result, t: time);
    v9 = idCurve<idVec3>::IndexForTime(this: result, time: v8);
    v10 = v9 - 1;
    v11 = v9;
    idCurve_CatmullRomSpline<idAngles>::BasisSecondDerivative(
      this: result,
      index: v9 - 1,
      t: v8,
      bvals: v13,
      a5: (float *)&v28.times.granularity,
      a6: v12);
    v14 = result->values.list;
    v15 = 0;
    p_size = &v28.times.size;
    v17 = (float)(v14->x - v14->x);
    v18 = (float)(v14[1].x - v14[1].x);
    v19 = (float)(v14[2].x - v14[2].x);
    do
    {
      v22 = (float *)idCurve_Spline<idVec3>::ValueForIndex(this: &v28, (idVec3 *)result, index: v11 - 2 + v15);
      ++p_size;
      ++v15;
      v17 = (float)((float)(*v22 * *(float *)p_size) + (float)v17);
      v18 = (float)((float)(v22[1] * *(float *)p_size) + (float)v18);
      v19 = (float)((float)(v22[2] * *(float *)p_size) + (float)v19);
    }
    while ( v15 < 4 );
    v23 = idCurve_Spline<idAngles>::TimeForIndex(this: result, index: v11, a3: v21, a4: v20);
    v26 = idCurve_Spline<idAngles>::TimeForIndex(this: result, index: v10, a3: v25, a4: v24);
    *v3 = (float)((float)1.0 / (float)((float)((float)v23 - (float)v26) * (float)((float)v23 - (float)v26)))
        * (float)v17;
    v3[1] = (float)((float)1.0 / (float)((float)((float)v23 - (float)v26) * (float)((float)v23 - (float)v26)))
          * (float)v18;
    v3[2] = (float)((float)1.0 / (float)((float)((float)v23 - (float)v26) * (float)((float)v23 - (float)v26)))
          * (float)v19;
    return (idCurve_CatmullRomSpline<idVec3> *)v3;
  }
  return this;
}


// ========================================================================
// ??0?$idCurve_KochanekBartelsSpline@VidVec3@@@@QAA@XZ
// EA  : 0x82C8F4D8
// RVA : 0x00C8F4D8
// PDB : w:\tech5\shared\idlib\math\curve.h
// ========================================================================

idCurve_KochanekBartelsSpline<idVec3> *__fastcall idCurve_KochanekBartelsSpline<idVec3>::idCurve_KochanekBartelsSpline<idVec3>(
        idCurve_KochanekBartelsSpline<idVec3> *this)
{
  idCurve<idVec3>::idCurve<idVec3>(this);
  this->boundaryType = 0;
  this->closeTime = 0.0;
  this->__vftable = (idCurve_KochanekBartelsSpline<idVec3>_vtbl *)&idCurve_KochanekBartelsSpline<idVec3>::`vftable';
  this->tension.list = nullptr;
  this->tension.granularity = 0;
  this->tension.memTag = 116;
  this->tension.listStatic = 0;
  this->tension.size = 0;
  this->tension.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->tension);
  this->continuity.list = nullptr;
  this->continuity.granularity = 0;
  this->continuity.memTag = 116;
  this->continuity.listStatic = 0;
  this->continuity.size = 0;
  this->continuity.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->continuity);
  this->bias.list = nullptr;
  this->bias.granularity = 0;
  this->bias.memTag = 116;
  this->bias.listStatic = 0;
  this->bias.size = 0;
  this->bias.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->bias);
  return this;
}


// ========================================================================
// __unwind$519692
// EA  : 0x82C8F584
// RVA : 0x00C8F584
// PDB : w:\tech5\shared\idlib\math\curve.h
// ========================================================================

void _unwind_519692()
{
  int v0; // r12

  idCurve_NonUniformBSpline<idVec3>::~idCurve_NonUniformBSpline<idVec3>(this: *(idCurve_NonUniformBSpline<idVec3> **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$519693
// EA  : 0x82C8F5AC
// RVA : 0x00C8F5AC
// PDB : w:\tech5\shared\idlib\math\curve.h
// ========================================================================

void _unwind_519693()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 52));
}


// ========================================================================
// __unwind$519694
// EA  : 0x82C8F5D8
// RVA : 0x00C8F5D8
// PDB : w:\tech5\shared\idlib\math\curve.h
// ========================================================================

void _unwind_519694()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 68));
}


// ========================================================================
// ?RemoveIndex@?$idCurve_KochanekBartelsSpline@VidAngles@@@@UAAXH@Z
// EA  : 0x82C8F608
// RVA : 0x00C8F608
// PDB : w:\tech5\shared\idlib\math\curve.h
// ========================================================================

void __fastcall idCurve_KochanekBartelsSpline<idAngles>::RemoveIndex(
        idCurve_KochanekBartelsSpline<idVec3> *this,
        int index)
{
  idList<idAngles,5>::RemoveIndex(this: &this->values, index);
  idList<float,5>::RemoveIndex(this: &this->times, index);
  idList<float,5>::RemoveIndex(this: &this->tension, index);
  idList<float,5>::RemoveIndex(this: &this->continuity, index);
  idList<float,5>::RemoveIndex(this: &this->bias, index);
}


// ========================================================================
// ?TangentsForIndex@?$idCurve_KochanekBartelsSpline@VidVec3@@@@IBAXHAAVidVec3@@0@Z
// EA  : 0x82C8F678
// RVA : 0x00C8F678
// PDB : w:\tech5\shared\idlib\math\curve.h
// ========================================================================

void __fastcall idCurve_KochanekBartelsSpline<idVec3>::TangentsForIndex(
        idCurve_KochanekBartelsSpline<idVec3> *this,
        int index,
        idVec3 *t0,
        idVec3 *t1)
{
  float *v8; // r30
  float *v9; // r3
  double v10; // fp29
  double v11; // fp28
  double v12; // fp27
  __int64 v13; // r8
  int v14; // r5
  double v15; // fp31
  __int64 v16; // r8
  int v17; // r5
  double v18; // fp1
  __int64 v19; // r8
  int v20; // r30
  double v21; // fp26
  double v22; // fp25
  int v23; // r5
  double v24; // fp30
  __int64 v25; // r8
  int v26; // r5
  double v27; // fp1
  float *list; // r7
  float *v29; // r6
  double v30; // fp26
  double v31; // fp24
  float *v32; // r28
  float *v33; // r3
  double v34; // fp13
  double v35; // fp12
  int v36; // r28
  double v37; // fp26
  __int64 v38; // r8
  int v39; // r5
  double v40; // fp24
  __int64 v41; // r8
  int v42; // r5
  double v43; // fp1
  float *v44; // r11
  float *v45; // r10
  double v46; // fp1
  double v47; // fp31
  double v48; // fp30
  double v49; // fp29
  double v50; // fp28
  float *v51; // r31
  float *v52; // r3
  double v53; // fp4
  double v54; // fp3
  idCurve_Spline<idVec3> v55[2]; // [sp+50h] [-C0h] BYREF

  v8 = (float *)idCurve_Spline<idVec3>::ValueForIndex(this: v55, result: (idVec3 *)this, index);
  v9 = (float *)idCurve_Spline<idVec3>::ValueForIndex(
                  this: (idCurve_Spline<idVec3> *)&v55[0].times.granularity,
                  result: (idVec3 *)this,
                  index: index + 1);
  v10 = (float)(*v9 - *v8);
  v11 = (float)(v9[1] - v8[1]);
  v12 = (float)(v9[2] - v8[2]);
  v15 = idCurve_Spline<idAngles>::TimeForIndex((idCurve_Spline<idVec1> *)this, index: index + 1, a3: v14, a4: v13);
  v18 = idCurve_Spline<idAngles>::TimeForIndex((idCurve_Spline<idVec1> *)this, index, a3: v17, a4: v16);
  LODWORD(v19) = off_82010000;
  v20 = index;
  v21 = (float)((float)1.0 - this->tension.list[index]);
  v22 = (float)((float)((float)v15 - (float)v18) * (float)2.0);
  v24 = idCurve_Spline<idAngles>::TimeForIndex((idCurve_Spline<idVec1> *)this, index: index + 1, a3: v23, a4: v19);
  v27 = idCurve_Spline<idAngles>::TimeForIndex((idCurve_Spline<idVec1> *)this, index: index - 1, a3: v26, a4: v25);
  list = this->bias.list;
  v29 = this->continuity.list;
  v31 = (float)((float)((float)((float)((float)((float)1.0 - v29[v20]) * (float)((float)1.0 - list[v20]))
                              * (float)((float)v22 / (float)((float)v24 - (float)v27)))
                      * (float)v21)
              * (float)0.5);
  v30 = (float)((float)((float)((float)((float)(v29[v20] + (float)1.0) * (float)(list[v20] + (float)1.0))
                              * (float)((float)v22 / (float)((float)v24 - (float)v27)))
                      * (float)v21)
              * (float)0.5);
  v32 = (float *)idCurve_Spline<idVec3>::ValueForIndex(
                   this: (idCurve_Spline<idVec3> *)&v55[0].times.granularity,
                   result: (idVec3 *)this,
                   index: index - 1);
  v33 = (float *)idCurve_Spline<idVec3>::ValueForIndex(
                   this: (idCurve_Spline<idVec3> *)&v55[0].values.granularity,
                   result: (idVec3 *)this,
                   index);
  v34 = (float)(v33[1] - v32[1]);
  v35 = (float)(v33[2] - v32[2]);
  t0->x = (float)((float)v10 * (float)v31) + (float)((float)(*v33 - *v32) * (float)v30);
  v36 = index + 2;
  t0->y = (float)((float)v11 * (float)v31) + (float)((float)v34 * (float)v30);
  t0->z = (float)((float)v12 * (float)v31) + (float)((float)v35 * (float)v30);
  v37 = (float)((float)1.0 - this->tension.list[index + 1]);
  v40 = idCurve_Spline<idAngles>::TimeForIndex((idCurve_Spline<idVec1> *)this, index: index + 2, a3: v39, a4: v38);
  v43 = idCurve_Spline<idAngles>::TimeForIndex((idCurve_Spline<idVec1> *)this, index, a3: v42, a4: v41);
  v44 = this->continuity.list;
  v45 = this->bias.list;
  v47 = (float)((float)((float)((float)((float)(v44[v20 + 1] + (float)1.0) * (float)((float)1.0 - v45[v20 + 1]))
                              * (float)((float)v22 / (float)((float)v40 - (float)v43)))
                      * (float)v37)
              * (float)0.5);
  v46 = (float)((float)((float)((float)((float)(v45[v20 + 1] + (float)1.0) * (float)((float)1.0 - v44[v20 + 1]))
                              * (float)((float)v22 / (float)((float)v40 - (float)v43)))
                      * (float)v37)
              * (float)0.5);
  v48 = (float)((float)v10 * (float)v46);
  v49 = (float)((float)v11 * (float)v46);
  v50 = (float)((float)v12 * (float)v46);
  v51 = (float *)idCurve_Spline<idVec3>::ValueForIndex(
                   this: (idCurve_Spline<idVec3> *)&v55[0].values.granularity,
                   result: (idVec3 *)this,
                   index: index + 1);
  v52 = (float *)idCurve_Spline<idVec3>::ValueForIndex(
                   this: (idCurve_Spline<idVec3> *)&v55[0].closeTime,
                   result: (idVec3 *)this,
                   index: v36);
  v53 = (float)((float)(v52[1] - v51[1]) * (float)v47);
  v54 = (float)((float)(v52[2] - v51[2]) * (float)v47);
  t1->x = (float)((float)(*v52 - *v51) * (float)v47) + (float)v48;
  t1->y = (float)v53 + (float)v49;
  t1->z = (float)v54 + (float)v50;
}


// ========================================================================
// ?Basis@?$idCurve_KochanekBartelsSpline@VidAngles@@@@IBAXHMPAM@Z
// EA  : 0x82C8F920
// RVA : 0x00C8F920
// PDB : w:\tech5\shared\idlib\math\curve.h
// ========================================================================

void __fastcall idCurve_KochanekBartelsSpline<idAngles>::Basis(
        idCurve_KochanekBartelsSpline<idVec3> *this,
        int index,
        double t,
        float *bvals,
        float *a5,
        __int64 a6)
{
  double v9; // fp31
  __int64 v10; // r8
  int v11; // r5
  double v12; // fp30
  __int64 v13; // r8
  int v14; // r5
  double v15; // fp1

  v9 = (float)((float)t
             - idCurve_Spline<idAngles>::TimeForIndex((idCurve_Spline<idVec1> *)this, index, a3: (int)bvals, a4: a6));
  v12 = idCurve_Spline<idAngles>::TimeForIndex((idCurve_Spline<idVec1> *)this, index: index + 1, a3: v11, a4: v10);
  v15 = idCurve_Spline<idAngles>::TimeForIndex((idCurve_Spline<idVec1> *)this, index, a3: v14, a4: v13);
  a5[2] = (float)((float)((float)((float)((float)v9 / (float)((float)v12 - (float)v15)) - (float)2.0)
                        * (float)((float)v9 / (float)((float)v12 - (float)v15)))
                + (float)1.0)
        * (float)((float)v9 / (float)((float)v12 - (float)v15));
  a5[3] = (float)((float)((float)((float)v9 / (float)((float)v12 - (float)v15)) - (float)1.0)
                * (float)((float)v9 / (float)((float)v12 - (float)v15)))
        * (float)((float)v9 / (float)((float)v12 - (float)v15));
  *a5 = (float)((float)((float)((float)((float)((float)v9 / (float)((float)v12 - (float)v15)) * (float)2.0) - (float)3.0)
                      * (float)((float)v9 / (float)((float)v12 - (float)v15)))
              * (float)((float)v9 / (float)((float)v12 - (float)v15)))
      + (float)1.0;
  a5[1] = (float)((float)((float)3.0 - (float)((float)((float)v9 / (float)((float)v12 - (float)v15)) * (float)2.0))
                * (float)((float)v9 / (float)((float)v12 - (float)v15)))
        * (float)((float)v9 / (float)((float)v12 - (float)v15));
}


// ========================================================================
// ?BasisSecondDerivative@?$idCurve_KochanekBartelsSpline@VidVec3@@@@IBAXHMPAM@Z
// EA  : 0x82C8F9E0
// RVA : 0x00C8F9E0
// PDB : w:\tech5\shared\idlib\math\curve.h
// ========================================================================

void __fastcall idCurve_KochanekBartelsSpline<idVec3>::BasisSecondDerivative(
        idCurve_KochanekBartelsSpline<idVec3> *this,
        int index,
        double t,
        float *bvals,
        float *a5,
        __int64 a6)
{
  double v9; // fp31
  __int64 v10; // r8
  int v11; // r5
  double v12; // fp30
  __int64 v13; // r8
  int v14; // r5
  double v15; // fp1

  v9 = (float)((float)t
             - idCurve_Spline<idAngles>::TimeForIndex((idCurve_Spline<idVec1> *)this, index, a3: (int)bvals, a4: a6));
  v12 = idCurve_Spline<idAngles>::TimeForIndex((idCurve_Spline<idVec1> *)this, index: index + 1, a3: v11, a4: v10);
  v15 = idCurve_Spline<idAngles>::TimeForIndex((idCurve_Spline<idVec1> *)this, index, a3: v14, a4: v13);
  *a5 = (float)((float)((float)v9 / (float)((float)v12 - (float)v15)) * (float)12.0) - (float)6.0;
  a5[1] = (float)6.0 - (float)((float)((float)v9 / (float)((float)v12 - (float)v15)) * (float)12.0);
  a5[2] = (float)((float)((float)v9 / (float)((float)v12 - (float)v15)) * (float)6.0) - (float)4.0;
  a5[3] = (float)((float)((float)v9 / (float)((float)v12 - (float)v15)) * (float)6.0) - (float)2.0;
}


// ========================================================================
// ?GetCurrentValue@?$idCurve_KochanekBartelsSpline@VidVec3@@@@UBA?AVidVec3@@M@Z
// EA  : 0x82C8FA88
// RVA : 0x00C8FA88
// PDB : w:\tech5\shared\idlib\math\curve.h
// ========================================================================

idCurve_KochanekBartelsSpline<idVec3> *__fastcall idCurve_KochanekBartelsSpline<idVec3>::GetCurrentValue(
        idCurve_KochanekBartelsSpline<idVec3> *this,
        idCurve_Spline<idVec1> *result,
        double time)
{
  float *v3; // r30
  float v5; // r11
  float *v6; // r9
  int v7; // r8
  double v8; // fp31
  int v9; // r3
  int v10; // r29
  int v11; // r28
  __int64 v12; // r8
  float *v13; // r5
  float *v14; // r3
  double v15; // fp31
  double v16; // fp30
  double v17; // fp29
  float *v18; // r3
  double v19; // fp7
  double v20; // fp6
  float x; // r8
  float y; // r7
  idVec3 v24; // [sp+50h] [-90h] BYREF
  idVec3 v25; // [sp+60h] [-80h] BYREF
  idCurve_Spline<idVec3> v26; // [sp+70h] [-70h] BYREF

  v3 = (float *)this;
  if ( result->times.num == 1 )
  {
    v5 = *(float *)&result->values.list;
    v6 = *(float **)(LODWORD(v5) + 4);
    v7 = *(_DWORD *)(LODWORD(v5) + 8);
    this->__vftable = *(idCurve_KochanekBartelsSpline<idVec3>_vtbl **)LODWORD(v5);
    this->times.list = v6;
    this->times.num = v7;
  }
  else
  {
    v8 = idCurve_Spline<idVec1>::ClampedTime(this: result, t: time);
    v9 = idCurve<idVec3>::IndexForTime(this: result, time: v8);
    v10 = v9 - 1;
    v11 = v9;
    idCurve_KochanekBartelsSpline<idVec3>::TangentsForIndex(
      this: (idCurve_KochanekBartelsSpline<idVec3> *)result,
      index: v9 - 1,
      t0: &v24,
      t1: &v25);
    idCurve_KochanekBartelsSpline<idAngles>::Basis(
      this: (idCurve_KochanekBartelsSpline<idVec3> *)result,
      index: v10,
      t: v8,
      bvals: v13,
      a5: (float *)&v26.values.granularity,
      a6: v12);
    v14 = (float *)idCurve_Spline<idVec3>::ValueForIndex(this: &v26, (idVec3 *)result, index: v10);
    v15 = (float)(*v14 * *(float *)&v26.values.granularity);
    v16 = (float)(v14[1] * *(float *)&v26.values.granularity);
    v17 = (float)(v14[2] * *(float *)&v26.values.granularity);
    v18 = (float *)idCurve_Spline<idVec3>::ValueForIndex(
                     this: (idCurve_Spline<idVec3> *)&v26.times.granularity,
                     (idVec3 *)result,
                     index: v11);
    v19 = (float)((float)(v24.x * *(float *)&v26.changed)
                + (float)((float)(*v18 * *(float *)&v26.currentIndex) + (float)v15));
    v20 = (float)((float)(v24.y * *(float *)&v26.changed)
                + (float)((float)(v18[1] * *(float *)&v26.currentIndex) + (float)v16));
    v24.z = (float)(v25.z * *(float *)&v26.boundaryType)
          + (float)((float)(v24.z * *(float *)&v26.changed)
                  + (float)((float)(v18[2] * *(float *)&v26.currentIndex) + (float)v17));
    v24.x = (float)(v25.x * *(float *)&v26.boundaryType) + (float)v19;
    v24.y = (float)(v25.y * *(float *)&v26.boundaryType) + (float)v20;
    x = v24.x;
    y = v24.y;
    v3[2] = v24.z;
    v3[1] = y;
    *v3 = x;
    return (idCurve_KochanekBartelsSpline<idVec3> *)v3;
  }
  return this;
}


// ========================================================================
// ?GetCurrentSecondDerivative@?$idCurve_KochanekBartelsSpline@VidAngles@@@@UBA?AVidAngles@@M@Z
// EA  : 0x82C8FC20
// RVA : 0x00C8FC20
// PDB : w:\tech5\shared\idlib\math\curve.h
// ========================================================================

idCurve_KochanekBartelsSpline<idVec3> *__fastcall idCurve_KochanekBartelsSpline<idAngles>::GetCurrentSecondDerivative(
        idCurve_KochanekBartelsSpline<idVec3> *this,
        idCurve_Spline<idVec1> *result,
        double time)
{
  float *v3; // r30
  idVec1 *list; // r11
  double v6; // fp8
  double v7; // fp6
  double v8; // fp31
  int v9; // r3
  int v10; // r29
  int v11; // r28
  __int64 v12; // r8
  float *v13; // r5
  float *v14; // r3
  double v15; // fp31
  double v16; // fp30
  double v17; // fp29
  float *v18; // r3
  double v19; // fp31
  double v20; // fp30
  double v21; // fp29
  __int64 v22; // r8
  int v23; // r5
  double v24; // fp28
  __int64 v25; // r8
  int v26; // r5
  double v27; // fp1
  idVec3 v29; // [sp+50h] [-A0h] BYREF
  idVec3 v30; // [sp+60h] [-90h] BYREF
  idCurve_Spline<idVec3> v31; // [sp+70h] [-80h] BYREF

  v3 = (float *)this;
  if ( result->times.num == 1 )
  {
    list = result->values.list;
    v6 = (float)(list[1].x - list[1].x);
    v7 = (float)(list[2].x - list[2].x);
    *(float *)&this->__vftable = list->x - list->x;
    *(float *)&this->times.list = v6;
    *(float *)&this->times.num = v7;
  }
  else
  {
    v8 = idCurve_Spline<idVec1>::ClampedTime(this: result, t: time);
    v9 = idCurve<idVec3>::IndexForTime(this: result, time: v8);
    v10 = v9 - 1;
    v11 = v9;
    idCurve_KochanekBartelsSpline<idVec3>::TangentsForIndex(
      this: (idCurve_KochanekBartelsSpline<idVec3> *)result,
      index: v9 - 1,
      t0: &v29,
      t1: &v30);
    idCurve_KochanekBartelsSpline<idVec3>::BasisSecondDerivative(
      this: (idCurve_KochanekBartelsSpline<idVec3> *)result,
      index: v10,
      t: v8,
      bvals: v13,
      a5: (float *)&v31.values.granularity,
      a6: v12);
    v14 = (float *)idCurve_Spline<idVec3>::ValueForIndex(this: &v31, (idVec3 *)result, index: v10);
    v15 = (float)(*v14 * *(float *)&v31.values.granularity);
    v16 = (float)(v14[1] * *(float *)&v31.values.granularity);
    v17 = (float)(v14[2] * *(float *)&v31.values.granularity);
    v18 = (float *)idCurve_Spline<idVec3>::ValueForIndex(
                     this: (idCurve_Spline<idVec3> *)&v31.times.granularity,
                     (idVec3 *)result,
                     index: v11);
    v19 = (float)((float)(v30.x * *(float *)&v31.boundaryType)
                + (float)((float)(v29.x * *(float *)&v31.changed)
                        + (float)((float)(*v18 * *(float *)&v31.currentIndex) + (float)v15)));
    v20 = (float)((float)(v30.y * *(float *)&v31.boundaryType)
                + (float)((float)(v29.y * *(float *)&v31.changed)
                        + (float)((float)(v18[1] * *(float *)&v31.currentIndex) + (float)v16)));
    v21 = (float)((float)(v30.z * *(float *)&v31.boundaryType)
                + (float)((float)(v29.z * *(float *)&v31.changed)
                        + (float)((float)(v18[2] * *(float *)&v31.currentIndex) + (float)v17)));
    v24 = idCurve_Spline<idAngles>::TimeForIndex(this: result, index: v11, a3: v23, a4: v22);
    v27 = idCurve_Spline<idAngles>::TimeForIndex(this: result, index: v10, a3: v26, a4: v25);
    *v3 = (float)((float)1.0 / (float)((float)((float)v24 - (float)v27) * (float)((float)v24 - (float)v27)))
        * (float)v19;
    v3[1] = (float)((float)1.0 / (float)((float)((float)v24 - (float)v27) * (float)((float)v24 - (float)v27)))
          * (float)v20;
    v3[2] = (float)((float)1.0 / (float)((float)((float)v24 - (float)v27) * (float)((float)v24 - (float)v27)))
          * (float)v21;
    return (idCurve_KochanekBartelsSpline<idVec3> *)v3;
  }
  return this;
}


// ========================================================================
// ?SetNumValues@?$idCurve_KochanekBartelsSpline@VidVec3@@@@UAAXH@Z
// EA  : 0x82C8FEC8
// RVA : 0x00C8FEC8
// PDB : w:\tech5\shared\idlib\math\curve.h
// ========================================================================

void __fastcall idCurve_KochanekBartelsSpline<idVec3>::SetNumValues(
        idCurve_KochanekBartelsSpline<idAngles> *this,
        int num)
{
  idList<idAngles,116> *p_values; // r30
  int size; // r11
  int v6; // r11
  float v7[2]; // [sp+50h] [-30h] BYREF

  p_values = &this->values;
  if ( num <= this->values.size
    || (unsigned __int8)idList<idVec3,59>::Resize(this: (idList<idVec3,5> *)&this->values, newsize: num) != 0 )
  {
    size = p_values->size;
    if ( num < size )
      size = num;
    p_values->num = size;
  }
  if ( num <= this->times.size
    || (unsigned __int8)idList<float,116>::Resize(this: (idList<float,13> *)&this->times, newsize: num) != 0 )
  {
    v6 = this->times.size;
    if ( num < v6 )
      v6 = num;
    this->times.num = v6;
  }
  v7[0] = 0.0;
  idList<float,17>::SetNum(this: (idList<float,32> *)&this->tension, newNum: num, initValue: v7);
  v7[0] = 0.0;
  idList<float,17>::SetNum(this: (idList<float,32> *)&this->continuity, newNum: num, initValue: v7);
  v7[0] = 0.0;
  idList<float,17>::SetNum(this: (idList<float,32> *)&this->bias, newNum: num, initValue: v7);
}


// ========================================================================
// ?AddValue@?$idCurve_KochanekBartelsSpline@VidAngles@@@@UAAHMABVidAngles@@MMM@Z
// EA  : 0x82C8FFA8
// RVA : 0x00C8FFA8
// PDB : w:\tech5\shared\idlib\math\curve.h
// ========================================================================

int __fastcall idCurve_KochanekBartelsSpline<idAngles>::AddValue(
        idCurve_KochanekBartelsSpline<idAngles> *this,
        double time,
        const idAngles *value,
        double tension,
        double continuity,
        double bias,
        const idVec3 *a7,
        double a8,
        double a9,
        double a10,
        double a11,
        float a12,
        float a13,
        float a14,
        float a15,
        float a16,
        float a17,
        float a18,
        float a19,
        float a20,
        float a21,
        float a22,
        float a23,
        float a24,
        float a25)
{
  int v27; // r29

  a17 = time;
  a21 = tension;
  a23 = continuity;
  a25 = bias;
  v27 = idCurve<idVec3>::IndexForTime((idCurve<idVec1> *)this, time);
  idList<float,116>::Insert(this: &this->times, obj: &a17, index: v27);
  idList<idVec3,116>::Insert(this: (idList<idVec3,116> *)&this->values, obj: a7, index: v27);
  idList<float,116>::Insert(this: &this->tension, obj: &a21, index: v27);
  idList<float,116>::Insert(this: &this->continuity, obj: &a23, index: v27);
  idList<float,116>::Insert(this: &this->bias, obj: &a25, index: v27);
  return v27;
}


// ========================================================================
// ??0?$idCurve_CubicBezierSpline@VidVec3@@@@QAA@XZ
// EA  : 0x82C90030
// RVA : 0x00C90030
// PDB : w:\tech5\shared\idlib\math\curve.h
// ========================================================================

idCurve_CubicBezierSpline<idVec3> *__fastcall idCurve_CubicBezierSpline<idVec3>::idCurve_CubicBezierSpline<idVec3>(
        idCurve_CubicBezierSpline<idVec3> *this)
{
  idCurve<idVec3>::idCurve<idVec3>(this);
  this->boundaryType = 0;
  this->__vftable = (idCurve_CubicBezierSpline<idVec3>_vtbl *)&idCurve_CubicBezierSpline<idVec3>::`vftable';
  this->closeTime = 0.0;
  this->order = 4;
  return this;
}


// ========================================================================
// ?Basis@?$idCurve_CubicBezierSpline@VidVec3@@@@IBAXHMPAM@Z
// EA  : 0x82C90088
// RVA : 0x00C90088
// PDB : w:\tech5\shared\idlib\math\curve.h
// ========================================================================

void __fastcall idCurve_CubicBezierSpline<idVec3>::Basis(
        idCurve_CubicBezierSpline<idVec3> *this,
        int index,
        double t,
        float *bvals,
        float *a5,
        __int64 a6)
{
  double v9; // fp31
  __int64 v10; // r8
  int v11; // r5
  double v12; // fp30
  __int64 v13; // r8
  int v14; // r5
  double v15; // fp1
  double v16; // fp10

  v9 = (float)((float)t
             - idCurve_Spline<idAngles>::TimeForIndex((idCurve_Spline<idVec1> *)this, index, a3: (int)bvals, a4: a6));
  v12 = idCurve_Spline<idAngles>::TimeForIndex((idCurve_Spline<idVec1> *)this, index: index + 3, a3: v11, a4: v10);
  v15 = idCurve_Spline<idAngles>::TimeForIndex((idCurve_Spline<idVec1> *)this, index, a3: v14, a4: v13);
  v16 = (float)((float)v9 / (float)((float)v12 - (float)v15));
  a5[3] = (float)((float)v16 * (float)v16) * (float)v16;
  a5[2] = (float)((float)((float)v16 * (float)v16) * (float)3.0)
        - (float)((float)((float)((float)v16 * (float)v16) * (float)v16) * (float)3.0);
  a5[1] = (float)((float)((float)v9 / (float)((float)v12 - (float)v15)) * (float)3.0)
        - (float)((float)((float)((float)v16 * (float)v16) * (float)6.0)
                - (float)((float)((float)((float)v16 * (float)v16) * (float)v16) * (float)3.0));
  *a5 = (float)((float)((float)((float)((float)v16 * (float)v16) * (float)3.0)
                      - (float)((float)((float)v16 * (float)v16) * (float)v16))
              - (float)((float)((float)v9 / (float)((float)v12 - (float)v15)) * (float)3.0))
      + (float)1.0;
}


// ========================================================================
// ?BasisFirstDerivative@?$idCurve_CubicBezierSpline@VidAngles@@@@IBAXHMPAM@Z
// EA  : 0x82C90140
// RVA : 0x00C90140
// PDB : w:\tech5\shared\idlib\math\curve.h
// ========================================================================

void __fastcall idCurve_CubicBezierSpline<idAngles>::BasisFirstDerivative(
        idCurve_CubicBezierSpline<idVec3> *this,
        int index,
        double t,
        float *bvals,
        float *a5,
        __int64 a6)
{
  double v9; // fp31
  __int64 v10; // r8
  int v11; // r5
  double v12; // fp30
  __int64 v13; // r8
  int v14; // r5
  double v15; // fp1
  double v16; // fp9

  v9 = (float)((float)t
             - idCurve_Spline<idAngles>::TimeForIndex((idCurve_Spline<idVec1> *)this, index, a3: (int)bvals, a4: a6));
  v12 = idCurve_Spline<idAngles>::TimeForIndex((idCurve_Spline<idVec1> *)this, index: index + 3, a3: v11, a4: v10);
  v15 = idCurve_Spline<idAngles>::TimeForIndex((idCurve_Spline<idVec1> *)this, index, a3: v14, a4: v13);
  v16 = (float)((float)v9 / (float)((float)v12 - (float)v15));
  a5[3] = (float)((float)v16 * (float)v16) * (float)3.0;
  a5[2] = (float)((float)((float)v9 / (float)((float)v12 - (float)v15)) * (float)6.0)
        - (float)((float)((float)v16 * (float)v16) * (float)9.0);
  *a5 = (float)((float)((float)((float)v9 / (float)((float)v12 - (float)v15)) * (float)6.0)
              - (float)((float)((float)v16 * (float)v16) * (float)3.0))
      - (float)3.0;
  a5[1] = (float)3.0
        - (float)((float)((float)v16 * (float)12.0) - (float)((float)((float)v16 * (float)v16) * (float)9.0));
}


// ========================================================================
// ?GetCurrentValue@?$idCurve_CubicBezierSpline@VidAngles@@@@UBA?AVidAngles@@M@Z
// EA  : 0x82C901F8
// RVA : 0x00C901F8
// PDB : w:\tech5\shared\idlib\math\curve.h
// ========================================================================

idCurve_CubicBezierSpline<idVec3> *__fastcall idCurve_CubicBezierSpline<idAngles>::GetCurrentValue(
        idCurve_CubicBezierSpline<idVec3> *this,
        idCurve_CubicBezierSpline<idVec3> *result,
        double time,
        float *a4)
{
  float *v4; // r30
  int v5; // r11
  __int64 v7; // r8
  float v8; // r11
  float *v9; // r9
  int v10; // r8
  float v11; // r10
  int v12; // r31
  int v13; // r11
  float v14; // r9
  float *v15; // r11
  float *v16; // r10
  int v17; // r8
  double v18; // fp2
  double v19; // fp0
  double v20; // fp12
  double v21; // fp11
  float v23; // [sp+50h] [-30h] BYREF
  float v24; // [sp+54h] [-2Ch]
  float v25; // [sp+58h] [-28h]
  float v26; // [sp+5Ch] [-24h]

  v4 = (float *)this;
  v5 = result->times.num - 1;
  LODWORD(v7) = 3 * (v5 / 3);
  HIDWORD(v7) = v5 % 3;
  if ( v5 == (_DWORD)v7 )
  {
    v11 = *(float *)&result->times.list;
    v12 = 0;
    if ( *(float *)(LODWORD(v11) + 12) < time )
    {
      v13 = 12;
      do
      {
        v13 += 12;
        v12 += 3;
      }
      while ( *(float *)(v13 + LODWORD(v11)) < time );
    }
    idCurve_CubicBezierSpline<idVec3>::Basis(this: result, index: v12, t: time, bvals: a4, a5: &v23, a6: v7);
    v14 = *(float *)&result->values.list;
    v15 = (float *)(12 * v12 + LODWORD(v14));
    v16 = (float *)(12 * (v12 + 2) + LODWORD(v14));
    v17 = 12 * (v12 + 3);
    v18 = (float)(*(float *)(v17 + LODWORD(v14) + 4) * v26);
    v19 = (float)(*(float *)(v17 + LODWORD(v14) + 8) * v26);
    v20 = (float)((float)((float)(v15[1] * v23) + (float)(v15[4] * v24)) + (float)(v16[1] * v25));
    v21 = (float)((float)((float)(v15[2] * v23) + (float)(v15[5] * v24)) + (float)(v16[2] * v25));
    *v4 = (float)((float)((float)(v23 * *v15) + (float)(v15[3] * v24)) + (float)(*v16 * v25))
        + (float)(*(float *)(v17 + LODWORD(v14)) * v26);
    v4[1] = (float)v20 + (float)v18;
    v4[2] = (float)v21 + (float)v19;
    return (idCurve_CubicBezierSpline<idVec3> *)v4;
  }
  else
  {
    v8 = *(float *)&result->values.list;
    v9 = *(float **)(LODWORD(v8) + 4);
    v10 = *(_DWORD *)(LODWORD(v8) + 8);
    this->__vftable = *(idCurve_CubicBezierSpline<idVec3>_vtbl **)LODWORD(v8);
    this->times.list = v9;
    this->times.num = v10;
  }
  return this;
}


// ========================================================================
// ?GetCurrentFirstDerivative@?$idCurve_CubicBezierSpline@VidAngles@@@@UBA?AVidAngles@@M@Z
// EA  : 0x82C90380
// RVA : 0x00C90380
// PDB : w:\tech5\shared\idlib\math\curve.h
// ========================================================================

idCurve_CubicBezierSpline<idVec3> *__fastcall idCurve_CubicBezierSpline<idAngles>::GetCurrentFirstDerivative(
        idCurve_CubicBezierSpline<idVec3> *this,
        idCurve_CubicBezierSpline<idVec3> *result,
        double time,
        float *a4,
        int a5,
        __int64 a6)
{
  float v6; // r10
  int v9; // r31
  int v10; // r11
  float v11; // r8
  float v12; // r6
  float *v13; // r11
  float *v14; // r9
  int v15; // r5
  int v16; // r10
  double v18; // fp10
  double v19; // fp4
  double v20; // fp3
  float v21; // [sp+50h] [-30h] BYREF
  float v22; // [sp+54h] [-2Ch]
  float v23; // [sp+58h] [-28h]
  float v24; // [sp+5Ch] [-24h]

  v6 = *(float *)&result->times.list;
  v9 = 0;
  if ( *(float *)(LODWORD(v6) + 12) < time )
  {
    v10 = 12;
    do
    {
      v10 += 12;
      v9 += 3;
    }
    while ( *(float *)(v10 + LODWORD(v6)) < time );
  }
  idCurve_CubicBezierSpline<idAngles>::BasisFirstDerivative(this: result, index: v9, t: time, bvals: a4, a5: &v21, a6);
  v11 = *(float *)&result->values.list;
  v12 = *(float *)&result->times.list;
  v13 = (float *)(12 * v9 + LODWORD(v11));
  v14 = (float *)(12 * (v9 + 2) + LODWORD(v11));
  v15 = 4 * (v9 + 3);
  v16 = 12 * (v9 + 3);
  v18 = (float)((float)1.0 / (float)(*(float *)(v15 + LODWORD(v12)) - *(float *)(4 * v9 + LODWORD(v12))));
  v19 = (float)((float)((float)((float)(v13[1] * v21) + (float)(v13[4] * v22)) + (float)(v14[1] * v23))
              + (float)(*(float *)(v16 + LODWORD(v11) + 4) * v24));
  v20 = (float)((float)((float)((float)(v13[2] * v21) + (float)(v13[5] * v22)) + (float)(v14[2] * v23))
              + (float)(*(float *)(v16 + LODWORD(v11) + 8) * v24));
  *(float *)&this->__vftable = (float)((float)((float)((float)(*v13 * v21) + (float)(v13[3] * v22)) + (float)(*v14 * v23))
                                     + (float)(*(float *)(v16 + LODWORD(v11)) * v24))
                             * (float)((float)1.0
                                     / (float)(*(float *)(v15 + LODWORD(v12)) - *(float *)(4 * v9 + LODWORD(v12))));
  *(float *)&this->times.list = (float)v19 * (float)v18;
  *(float *)&this->times.num = (float)v20 * (float)v18;
  return this;
}


// ========================================================================
// ?CreateNewCurve@?$idCurve_CatmullRomSpline@VidAngles@@@@MBAPAV?$idCurve@VidAngles@@@@XZ
// EA  : 0x82C905B0
// RVA : 0x00C905B0
// PDB : w:\tech5\shared\idlib\math\curve.h
// ========================================================================

idCurve<idAngles> *__fastcall idCurve_CatmullRomSpline<idAngles>::CreateNewCurve(
        idCurve_CatmullRomSpline<idAngles> *this)
{
  idCurve<idAngles> *v1; // r3
  idCurve<idAngles> *v2; // r30

  v1 = (idCurve<idAngles> *)idMem::AllocWithLocation(
                              this: &mem,
                              location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                              size: 0x34u,
                              tag: TAG_TABLE,
                              zeroBuffer: false,
                              align: ALIGN_16,
                              heap: HEAP_DEFAULTHEAP);
  v2 = v1;
  if ( v1 == nullptr )
    return nullptr;
  idCurve<idAngles>::idCurve<idAngles>(this: v1);
  v2[1].__vftable = nullptr;
  v2->__vftable = (idCurve<idAngles>_vtbl *)&idCurve_CatmullRomSpline<idAngles>::`vftable';
  *(float *)&v2[1].times.list = 0.0;
  return v2;
}


// ========================================================================
// __unwind$522110
// EA  : 0x82C90648
// RVA : 0x00C90648
// PDB : w:\tech5\shared\idlib\math\curve.h
// ========================================================================

void _unwind_522110()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_TABLE);
}


// ========================================================================
// ?CreateNewCurve@?$idCurve_KochanekBartelsSpline@VidAngles@@@@MBAPAV?$idCurve@VidAngles@@@@XZ
// EA  : 0x82C90680
// RVA : 0x00C90680
// PDB : w:\tech5\shared\idlib\math\curve.h
// ========================================================================

idCurve_KochanekBartelsSpline<idAngles> *__fastcall idCurve_KochanekBartelsSpline<idAngles>::CreateNewCurve(
        idCurve_KochanekBartelsSpline<idAngles> *this)
{
  idCurve_KochanekBartelsSpline<idAngles> *v1; // r3

  v1 = (idCurve_KochanekBartelsSpline<idAngles> *)idMem::AllocWithLocation(
                                                    this: &mem,
                                                    location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                                    size: 0x64u,
                                                    tag: TAG_TABLE,
                                                    zeroBuffer: false,
                                                    align: ALIGN_16,
                                                    heap: HEAP_DEFAULTHEAP);
  if ( v1 != nullptr )
    return idCurve_KochanekBartelsSpline<idAngles>::idCurve_KochanekBartelsSpline<idAngles>(this: v1);
  else
    return nullptr;
}


// ========================================================================
// __unwind$522188
// EA  : 0x82C906E8
// RVA : 0x00C906E8
// PDB : w:\tech5\shared\idlib\math\curve.h
// ========================================================================

void _unwind_522188()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_TABLE);
}


// ========================================================================
// ?CreateNewCurve@?$idCurve_NonUniformBSpline@VidAngles@@@@MBAPAV?$idCurve@VidAngles@@@@XZ
// EA  : 0x82C90720
// RVA : 0x00C90720
// PDB : w:\tech5\shared\idlib\math\curve.h
// ========================================================================

idCurve<idAngles> *__fastcall idCurve_NonUniformBSpline<idAngles>::CreateNewCurve(
        idCurve_NonUniformBSpline<idAngles> *this)
{
  idCurve<idAngles> *v1; // r3
  idCurve<idAngles> *v2; // r30

  v1 = (idCurve<idAngles> *)idMem::AllocWithLocation(
                              this: &mem,
                              location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                              size: 0x38u,
                              tag: TAG_TABLE,
                              zeroBuffer: false,
                              align: ALIGN_16,
                              heap: HEAP_DEFAULTHEAP);
  v2 = v1;
  if ( v1 == nullptr )
    return nullptr;
  idCurve<idAngles>::idCurve<idAngles>(this: v1);
  v2[1].__vftable = nullptr;
  v2->__vftable = (idCurve<idAngles>_vtbl *)&idCurve_NonUniformBSpline<idAngles>::`vftable';
  *(float *)&v2[1].times.list = 0.0;
  v2[1].times.num = 4;
  return v2;
}


// ========================================================================
// __unwind$522211
// EA  : 0x82C907C0
// RVA : 0x00C907C0
// PDB : w:\tech5\shared\idlib\math\curve.h
// ========================================================================

void _unwind_522211()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_TABLE);
}


// ========================================================================
// ?SetNumValues@?$idCurve_NURBS@VidAngles@@@@UAAXH@Z
// EA  : 0x82C907F0
// RVA : 0x00C907F0
// PDB : w:\tech5\shared\idlib\math\curve.h
// ========================================================================

void __fastcall idCurve_NURBS<idAngles>::SetNumValues(idCurve_NURBS<idVec3> *this, int num)
{
  idList<idVec3,116> *p_values; // r30
  int size; // r11
  int v6; // r11
  float v7; // [sp+50h] [-30h] BYREF

  p_values = &this->values;
  if ( num <= this->values.size
    || (unsigned __int8)idList<idVec3,59>::Resize(this: (idList<idVec3,5> *)&this->values, newsize: num) != 0 )
  {
    size = p_values->size;
    if ( num < size )
      size = num;
    p_values->num = size;
  }
  if ( num <= this->times.size
    || (unsigned __int8)idList<float,116>::Resize(this: (idList<float,13> *)&this->times, newsize: num) != 0 )
  {
    v6 = this->times.size;
    if ( num < v6 )
      v6 = num;
    this->times.num = v6;
  }
  v7 = 0.0;
  idList<float,17>::SetNum(this: (idList<float,32> *)&this->weights, newNum: num, initValue: &v7);
}


// ========================================================================
// ?CreateNewCurve@?$idCurve_NURBS@VidAngles@@@@MBAPAV?$idCurve@VidAngles@@@@XZ
// EA  : 0x82C908A8
// RVA : 0x00C908A8
// PDB : w:\tech5\shared\idlib\math\curve.h
// ========================================================================

idCurve_NURBS<idAngles> *__fastcall idCurve_NURBS<idAngles>::CreateNewCurve(idCurve_NURBS<idAngles> *this)
{
  idCurve_NURBS<idAngles> *v1; // r3

  v1 = (idCurve_NURBS<idAngles> *)idMem::AllocWithLocation(
                                    this: &mem,
                                    location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                    size: 0x48u,
                                    tag: TAG_TABLE,
                                    zeroBuffer: false,
                                    align: ALIGN_16,
                                    heap: HEAP_DEFAULTHEAP);
  if ( v1 != nullptr )
    return idCurve_NURBS<idAngles>::idCurve_NURBS<idAngles>(this: v1);
  else
    return nullptr;
}


// ========================================================================
// __unwind$522328
// EA  : 0x82C90910
// RVA : 0x00C90910
// PDB : w:\tech5\shared\idlib\math\curve.h
// ========================================================================

void _unwind_522328()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_TABLE);
}


// ========================================================================
// ?CreateNewCurve@?$idCurve_CubicBezierSpline@VidAngles@@@@MBAPAV?$idCurve@VidAngles@@@@XZ
// EA  : 0x82C90948
// RVA : 0x00C90948
// PDB : w:\tech5\shared\idlib\math\curve.h
// ========================================================================

idCurve<idAngles> *__fastcall idCurve_CubicBezierSpline<idAngles>::CreateNewCurve(
        idCurve_CubicBezierSpline<idAngles> *this)
{
  idCurve<idAngles> *v1; // r3
  idCurve<idAngles> *v2; // r30

  v1 = (idCurve<idAngles> *)idMem::AllocWithLocation(
                              this: &mem,
                              location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                              size: 0x38u,
                              tag: TAG_TABLE,
                              zeroBuffer: false,
                              align: ALIGN_16,
                              heap: HEAP_DEFAULTHEAP);
  v2 = v1;
  if ( v1 == nullptr )
    return nullptr;
  idCurve<idAngles>::idCurve<idAngles>(this: v1);
  v2[1].__vftable = nullptr;
  v2->__vftable = (idCurve<idAngles>_vtbl *)&idCurve_CubicBezierSpline<idAngles>::`vftable';
  *(float *)&v2[1].times.list = 0.0;
  v2[1].times.num = 4;
  return v2;
}


// ========================================================================
// __unwind$522351
// EA  : 0x82C909E8
// RVA : 0x00C909E8
// PDB : w:\tech5\shared\idlib\math\curve.h
// ========================================================================

void _unwind_522351()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_TABLE);
}


// ========================================================================
// ?AddValue@?$idCurve_KochanekBartelsSpline@VidVec3@@@@UAAHMABVidVec3@@@Z
// EA  : 0x82C90CB8
// RVA : 0x00C90CB8
// PDB : w:\tech5\shared\idlib\math\curve.h
// ========================================================================

int __fastcall idCurve_KochanekBartelsSpline<idVec3>::AddValue(
        idCurve_KochanekBartelsSpline<idAngles> *this,
        double time,
        const idAngles *value,
        const idVec3 *a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        float a12,
        float a13,
        float a14,
        float a15,
        float a16,
        float a17)
{
  int v19; // r29
  float v21[2]; // [sp+50h] [-30h] BYREF

  a17 = time;
  v19 = idCurve<idVec3>::IndexForTime((idCurve<idVec1> *)this, time);
  idList<float,116>::Insert(this: &this->times, obj: &a17, index: v19);
  idList<idVec3,116>::Insert(this: (idList<idVec3,116> *)&this->values, obj: a4, index: v19);
  v21[0] = 0.0;
  idList<float,116>::Insert(this: &this->tension, obj: v21, index: v19);
  v21[0] = 0.0;
  idList<float,116>::Insert(this: &this->continuity, obj: v21, index: v19);
  v21[0] = 0.0;
  idList<float,116>::Insert(this: &this->bias, obj: v21, index: v19);
  return v19;
}


// ========================================================================
// ?AddValue@?$idCurve_NURBS@VidAngles@@@@UAAHMABVidAngles@@M@Z
// EA  : 0x82C90D50
// RVA : 0x00C90D50
// PDB : w:\tech5\shared\idlib\math\curve.h
// ========================================================================

int __fastcall idCurve_NURBS<idAngles>::AddValue(
        idCurve_NURBS<idVec3> *this,
        double time,
        const idVec3 *value,
        double weight,
        const idVec3 *a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        float a12,
        float a13,
        float a14,
        float a15,
        float a16,
        float a17,
        float a18,
        float a19,
        float a20,
        float a21)
{
  int v23; // r29

  a17 = time;
  a21 = weight;
  v23 = idCurve<idVec3>::IndexForTime((idCurve<idVec1> *)this, time);
  idList<float,116>::Insert(this: &this->times, obj: &a17, index: v23);
  idList<idVec3,116>::Insert(this: &this->values, obj: a5, index: v23);
  idList<float,116>::Insert(this: &this->weights, obj: &a21, index: v23);
  return v23;
}


// ========================================================================
// ?SetNumValues@?$idCurve@VidAngles@@@@UAAXH@Z
// EA  : 0x82C914E8
// RVA : 0x00C914E8
// PDB : w:\tech5\shared\idlib\math\curve.h
// ========================================================================

void __fastcall idCurve<idAngles>::SetNumValues(idCurve<idVec3> *this, int num)
{
  idList<idVec3,116> *p_values; // r30
  int size; // r11
  int v6; // r11

  p_values = &this->values;
  if ( num <= this->values.size
    || (unsigned __int8)idList<idVec3,59>::Resize(this: (idList<idVec3,5> *)&this->values, newsize: num) != 0 )
  {
    size = p_values->size;
    if ( num < size )
      size = num;
    p_values->num = size;
  }
  if ( num <= this->times.size
    || (unsigned __int8)idList<float,116>::Resize(this: (idList<float,13> *)&this->times, newsize: num) != 0 )
  {
    v6 = this->times.size;
    if ( num < v6 )
      v6 = num;
    this->times.num = v6;
  }
}


// ========================================================================
// ?CreateNewCurve@?$idCurve_CatmullRomSpline@VidVec3@@@@MBAPAV?$idCurve@VidVec3@@@@XZ
// EA  : 0x82C91580
// RVA : 0x00C91580
// PDB : w:\tech5\shared\idlib\math\curve.h
// ========================================================================

idCurve<idVec3> *__fastcall idCurve_CatmullRomSpline<idVec3>::CreateNewCurve(idCurve_CatmullRomSpline<idVec3> *this)
{
  idCurve<idVec3> *v1; // r3
  idCurve<idVec3> *v2; // r30

  v1 = (idCurve<idVec3> *)idMem::AllocWithLocation(
                            this: &mem,
                            location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                            size: 0x34u,
                            tag: TAG_TABLE,
                            zeroBuffer: false,
                            align: ALIGN_16,
                            heap: HEAP_DEFAULTHEAP);
  v2 = v1;
  if ( v1 == nullptr )
    return nullptr;
  idCurve<idVec3>::idCurve<idVec3>(this: v1);
  v2[1].__vftable = nullptr;
  v2->__vftable = (idCurve<idVec3>_vtbl *)&idCurve_CatmullRomSpline<idVec3>::`vftable';
  *(float *)&v2[1].times.list = 0.0;
  return v2;
}


// ========================================================================
// __unwind$523441
// EA  : 0x82C91618
// RVA : 0x00C91618
// PDB : w:\tech5\shared\idlib\math\curve.h
// ========================================================================

void _unwind_523441()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_TABLE);
}


// ========================================================================
// ?CreateNewCurve@?$idCurve_KochanekBartelsSpline@VidVec3@@@@MBAPAV?$idCurve@VidVec3@@@@XZ
// EA  : 0x82C91650
// RVA : 0x00C91650
// PDB : w:\tech5\shared\idlib\math\curve.h
// ========================================================================

idCurve_KochanekBartelsSpline<idVec3> *__fastcall idCurve_KochanekBartelsSpline<idVec3>::CreateNewCurve(
        idCurve_KochanekBartelsSpline<idVec3> *this)
{
  idCurve_KochanekBartelsSpline<idVec3> *v1; // r3

  v1 = (idCurve_KochanekBartelsSpline<idVec3> *)idMem::AllocWithLocation(
                                                  this: &mem,
                                                  location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                                  size: 0x64u,
                                                  tag: TAG_TABLE,
                                                  zeroBuffer: false,
                                                  align: ALIGN_16,
                                                  heap: HEAP_DEFAULTHEAP);
  if ( v1 != nullptr )
    return idCurve_KochanekBartelsSpline<idVec3>::idCurve_KochanekBartelsSpline<idVec3>(this: v1);
  else
    return nullptr;
}


// ========================================================================
// __unwind$523474
// EA  : 0x82C916B8
// RVA : 0x00C916B8
// PDB : w:\tech5\shared\idlib\math\curve.h
// ========================================================================

void _unwind_523474()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_TABLE);
}


// ========================================================================
// ?CreateNewCurve@?$idCurve_CubicBezierSpline@VidVec3@@@@MBAPAV?$idCurve@VidVec3@@@@XZ
// EA  : 0x82C916F0
// RVA : 0x00C916F0
// PDB : w:\tech5\shared\idlib\math\curve.h
// ========================================================================

idCurve<idVec3> *__fastcall idCurve_CubicBezierSpline<idVec3>::CreateNewCurve(idCurve_CubicBezierSpline<idVec3> *this)
{
  idCurve<idVec3> *v1; // r3
  idCurve<idVec3> *v2; // r30

  v1 = (idCurve<idVec3> *)idMem::AllocWithLocation(
                            this: &mem,
                            location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                            size: 0x38u,
                            tag: TAG_TABLE,
                            zeroBuffer: false,
                            align: ALIGN_16,
                            heap: HEAP_DEFAULTHEAP);
  v2 = v1;
  if ( v1 == nullptr )
    return nullptr;
  idCurve<idVec3>::idCurve<idVec3>(this: v1);
  v2[1].__vftable = nullptr;
  v2->__vftable = (idCurve<idVec3>_vtbl *)&idCurve_CubicBezierSpline<idVec3>::`vftable';
  *(float *)&v2[1].times.list = 0.0;
  v2[1].times.num = 4;
  return v2;
}


// ========================================================================
// __unwind$523594
// EA  : 0x82C91790
// RVA : 0x00C91790
// PDB : w:\tech5\shared\idlib\math\curve.h
// ========================================================================

void _unwind_523594()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_TABLE);
}


// ========================================================================
// ?AddValue@?$idCurve@VidAngles@@@@UAAHMABVidAngles@@@Z
// EA  : 0x82C917C0
// RVA : 0x00C917C0
// PDB : w:\tech5\shared\idlib\math\curve.h
// ========================================================================

int __fastcall idCurve<idAngles>::AddValue(
        idCurve<idVec3> *this,
        double time,
        const idVec3 *value,
        const idVec3 *a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        float a12,
        float a13,
        float a14,
        float a15,
        float a16,
        float a17)
{
  int v20; // r3
  int v21; // r31

  a17 = time;
  v20 = idCurve<idVec3>::IndexForTime((idCurve<idVec1> *)this, time);
  v21 = v20;
  if ( v20 < this->times.num && this->times.list[v20] < time )
    v21 = v20 + 1;
  idList<float,116>::Insert(this: &this->times, obj: &a17, index: v21);
  idList<idVec3,116>::Insert(this: &this->values, obj: a4, index: v21);
  this->changed = true;
  return v21;
}


// ========================================================================
// ?SetConstantSpeed@?$idCurve@VidVec3@@@@QAAXM@Z
// EA  : 0x82CBF7F0
// RVA : 0x00CBF7F0
// PDB : w:\tech5\shared\idlib\math\curve.h
// ========================================================================

void __fastcall idCurve<idVec3>::SetConstantSpeed(idCurve<idVec3> *this, double totalTime)
{
  int v4; // r10
  int v5; // r4
  int v6; // r12
  double v7; // fp31
  float *v8; // r28
  int v9; // r29
  double LengthBetweenKnots; // fp1
  double v11; // fp0
  int v12; // r10
  int v13; // r11
  _DWORD back_chain[19]; // [sp+0h] [-A0h]
  _BYTE v15[12]; // [sp+4Ch] [-54h] BYREF

  ((void (*)(void))RtlCheckStack12)();
  v5 = 0;
  *(_DWORD *)((char *)back_chain + v6) = back_chain[0];
  v7 = 0.0;
  if ( v4 - 1 > 0 )
  {
    v8 = (float *)v15;
    do
    {
      v9 = v5 + 1;
      LengthBetweenKnots = idCurve<idVec3>::GetLengthBetweenKnots(this, i0: v5, i1: v5 + 1);
      *++v8 = LengthBetweenKnots;
      v5 = v9;
      v7 = (float)((float)LengthBetweenKnots + (float)v7);
    }
    while ( v9 < this->values.num - 1 );
  }
  v11 = 0.0;
  v12 = 0;
  if ( this->times.num - 1 > 0 )
  {
    v13 = 0;
    do
    {
      ++v12;
      this->times.list[v13] = v11;
      v11 = (float)((float)(*(float *)&v15[v13 * 4 + 4] * (float)((float)totalTime / (float)v7)) + (float)v11);
      ++v13;
    }
    while ( v12 < this->times.num - 1 );
  }
  this->times.list[this->times.num - 1] = totalTime;
  this->changed = true;
}


// ========================================================================
// ?EstimateTimeForLength@?$idCurve@VidVec3@@@@QBAMMM@Z
// EA  : 0x82D58F48
// RVA : 0x00D58F48
// PDB : w:\tech5\shared\idlib\math\curve.h
// ========================================================================

float __fastcall idCurve<idVec3>::EstimateTimeForLength(idCurve<idVec3> *this, double length, double epsilon)
{
  double v3; // fp0
  double v4; // fp1
  float *list; // r6
  int v6; // r9
  int num; // r7
  idVec3 *v8; // r5
  int v9; // r8
  int i; // r10
  double v11; // fp10
  double v12; // fp8
  double v13; // fp5
  double v14; // fp13

  v3 = length;
  if ( length > 0.0 )
  {
    list = this->times.list;
    v6 = 1;
    num = this->times.num;
    v4 = *list;
    if ( num > 1 )
    {
      v8 = this->values.list;
      v9 = 1;
      for ( i = 1; ; ++i )
      {
        v11 = (float)(v8[i].y - v8[i - 1].y);
        v12 = (float)(v8[i].x - v8[i - 1].x);
        v13 = (float)(v8[i].z - v8[i - 1].z);
        v14 = __fsqrts((float)((float)((float)v13 * (float)v13)
                             + (float)((float)((float)v12 * (float)v12) + (float)((float)v11 * (float)v11))));
        if ( v3 < v14 )
          break;
        ++v6;
        v4 = list[v9];
        v3 = (float)((float)v3 - (float)v14);
        ++v9;
        if ( v6 >= num )
          return *((float *)&v4 + 1);
      }
      v4 = (float)((float)((float)(this->times.list[v6] - this->times.list[v6 - 1]) * (float)((float)v3 / (float)v14))
                 + this->times.list[v6 - 1]);
    }
  }
  else
  {
    v4 = *this->times.list;
  }
  return *((float *)&v4 + 1);
}

