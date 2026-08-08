
// ========================================================================
// ?GetWorldPos@idNavSpline@@QAA?AVidVec3@@M@Z
// EA  : 0x82CBA3D0
// RVA : 0x00CBA3D0
// PDB : w:\tech5\tungsten\game\entities\splines\navspline.cpp
// ========================================================================

idNavSpline *__fastcall idNavSpline::GetWorldPos(idNavSpline *this, idVec3 *result, double distance)
{
  idNavSpline *v3; // r31

  v3 = this;
  if ( LODWORD(result->y) != 0 )
  {
    (*(void (__fastcall **)(double))(*(_DWORD *)LODWORD(result->y) + 20))(a1: distance);
    return v3;
  }
  else
  {
    this->splinePath = (idNavSplinePath *)LODWORD(vec3_origin.x);
    this->curve = (idCurve_Spline<idVec3> *)LODWORD(vec3_origin.y);
    this->width = vec3_origin.z;
  }
  return this;
}


// ========================================================================
// ?GetClosestSection@idNavSpline@@QAAXVidVec3@@AAM1PAM@Z
// EA  : 0x82CBA450
// RVA : 0x00CBA450
// PDB : w:\tech5\tungsten\game\entities\splines\navspline.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idNavSpline::GetClosestSection(
        idNavSpline *this,
        idVec3 *worldPos,
        float *minDist,
        float *maxDist,
        float *distanceToWorldPos)
{
  int v5; // r3
  int v6; // r27
  __int64 v9; // r11
  int v10; // r28
  int v11; // r30
  int v12; // r29
  int v13; // r31
  double v14; // fp31
  __int64 v15; // r7
  double v16; // fp3
  __int64 v17; // r11
  float v18; // [sp+58h] [-B8h] BYREF
  float v19; // [sp+5Ch] [-B4h]
  float v20; // [sp+60h] [-B0h]
  float v21[24]; // [sp+70h] [-A0h] BYREF
  __int64 v22; // [sp+130h] [+20h]

  v22 = *(_QWORD *)&worldPos;
  v6 = v5;
  v21[0] = 0.0;
  memset(Dst: &v21[1], Val: 0, Size: 0x3Cu);
  HIDWORD(v9) = &unk_821C0000;
  v10 = 0;
  v11 = 0;
  v12 = 0;
  v13 = 0;
  v14 = (float)(*(float *)(v6 + 12) * (float)0.06666667);
  do
  {
    LODWORD(v9) = v11;
    (*(void (__fastcall **)(float *, double))(**(_DWORD **)(v6 + 4) + 20))(
      a1: &v18,
      a2: (float)((float)v9 * (float)v14));
    v16 = (float)((float)((float)(v18 - *(float *)&v22) * (float)(v18 - *(float *)&v22))
                + (float)((float)((float)(v20 - *(float *)&worldPos) * (float)(v20 - *(float *)&worldPos))
                        + (float)((float)(v19 - *((float *)&v22 + 1)) * (float)(v19 - *((float *)&v22 + 1)))));
    v21[v13] = (float)((float)(v18 - *(float *)&v22) * (float)(v18 - *(float *)&v22))
             + (float)((float)((float)(v20 - *(float *)&worldPos) * (float)(v20 - *(float *)&worldPos))
                     + (float)((float)(v19 - *((float *)&v22 + 1)) * (float)(v19 - *((float *)&v22 + 1))));
    if ( v16 < *(float *)((char *)v21 + v12) )
    {
      v10 = v11;
      v12 = v13 * 4;
    }
    ++v13;
    ++v11;
  }
  while ( v13 < 16 );
  HIDWORD(v17) = v10 + 2;
  LODWORD(v15) = (((unsigned int)(v10 - 2) >> 31) - 1) & (v10 - 2);
  *maxDist = (float)v15 * (float)v14;
  if ( v10 + 2 > 15 )
    HIDWORD(v17) = 15;
  LODWORD(v17) = HIDWORD(v17);
  *distanceToWorldPos = (float)v17 * (float)v14;
}


// ========================================================================
// ?GetClosestPositionFromSection@idNavSpline@@QAA?AVidNavSplinePosition@@VidVec3@@MMHMPAM@Z
// EA  : 0x82CBA5B0
// RVA : 0x00CBA5B0
// PDB : w:\tech5\tungsten\game\entities\splines\navspline.cpp
// ========================================================================

idNavSpline *__fastcall idNavSpline::GetClosestPositionFromSection(
        idNavSpline *this,
        __int64 worldPos,
        double minDist,
        double maxDist,
        int iterations,
        double epsilon,
        float *distSqrToWorldPos,
        int a8,
        int a9,
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
        int a28,
        int a29,
        float *a30)
{
  float v30; // r26
  idNavSplinePathMgr *NavSplinePathMgr; // r30
  __int64 v37; // r3
  double v38; // fp24
  double v39; // fp20
  float *v40; // r3
  double v41; // fp30
  float *v42; // r3
  double v43; // fp0
  idVec3 *SplineWorldPos; // r3
  double v45; // fp31
  double v46; // fp30
  double v47; // fp29
  idVec3 *Right; // r3
  idNavSplinePosition v50; // [sp+50h] [-C0h] BYREF
  idNavSplinePosition v51[10]; // [sp+60h] [-B0h] BYREF
  float v53; // [sp+138h] [+28h]

  v30 = *(float *)&worldPos;
  v53 = *((float *)&worldPos + 1);
  NavSplinePathMgr = idGameLocal::GetNavSplinePathMgr(this: gameLocal, splineType: NAV_SPLINE_TYPE_VEHICLE_AI);
  NavSplinePathMgr->navSplineClosestPosSectionTimer.state = TS_STARTED;
  LODWORD(v37) = (unsigned __int64)Sys_GetClockTicks() >> 32;
  NavSplinePathMgr->navSplineClosestPosSectionTimer.start = v37;
  ++NavSplinePathMgr->navSplineClosestPosSectionCount;
  *(float *)&this->splinePath = 0.0;
  this->width = 0.0;
  *(float *)&this->curve = 0.0;
  v38 = (float)((float)epsilon * (float)epsilon);
  v39 = 1.0e30;
  while ( a9 != 0 )
  {
    --a9;
    v40 = (float *)(*(int (__fastcall **)(idNavSplinePosition *, double))(**(_DWORD **)(LODWORD(v30) + 4) + 20))(
                     a1: &v50,
                     a2: (float)((float)((float)((float)((float)minDist + (float)maxDist) * (float)0.5) + (float)minDist)
                           * (float)0.5));
    v41 = (float)((float)((float)(*v40 - *(float *)&worldPos) * (float)(*v40 - *(float *)&worldPos))
                + (float)((float)((float)(v40[2] - v53) * (float)(v40[2] - v53))
                        + (float)((float)(v40[1] - *((float *)&worldPos + 1))
                                * (float)(v40[1] - *((float *)&worldPos + 1)))));
    v42 = (float *)(*(int (__fastcall **)(idNavSplinePosition *, double))(**(_DWORD **)(LODWORD(v30) + 4) + 20))(
                     a1: v51,
                     a2: (float)((float)((float)((float)((float)minDist + (float)maxDist) * (float)0.5) + (float)maxDist)
                           * (float)0.5));
    v43 = (float)((float)((float)(*v42 - *(float *)&worldPos) * (float)(*v42 - *(float *)&worldPos))
                + (float)((float)((float)(v42[2] - v53) * (float)(v42[2] - v53))
                        + (float)((float)(v42[1] - *((float *)&worldPos + 1))
                                * (float)(v42[1] - *((float *)&worldPos + 1)))));
    if ( v41 >= v43 )
    {
      *(float *)&this->splinePath = (float)((float)((float)((float)minDist + (float)maxDist) * (float)0.5)
                                          + (float)maxDist)
                                  * (float)0.5;
      minDist = (float)((float)((float)minDist + (float)maxDist) * (float)0.5);
      if ( v43 <= v38 || __fabs((float)((float)v39 - (float)v43)) <= v38 )
      {
        v39 = v43;
        break;
      }
      v39 = v43;
    }
    else
    {
      *(float *)&this->splinePath = (float)((float)((float)((float)minDist + (float)maxDist) * (float)0.5)
                                          + (float)minDist)
                                  * (float)0.5;
      maxDist = (float)((float)((float)minDist + (float)maxDist) * (float)0.5);
      if ( v41 <= v38 || __fabs((float)((float)v39 - (float)v41)) <= v38 )
      {
        v39 = v41;
        break;
      }
      v39 = v41;
    }
  }
  if ( a30 != nullptr )
    *a30 = v39;
  this->width = v30;
  SplineWorldPos = idNavSplinePosition::GetSplineWorldPos(this: v51, result: (idVec3 *)this);
  v45 = (float)(*(float *)&worldPos - SplineWorldPos->x);
  v46 = (float)(*((float *)&worldPos + 1) - SplineWorldPos->y);
  v47 = (float)(v53 - SplineWorldPos->z);
  Right = idNavSplinePosition::GetRight(this: &v50, result: (idVec3 *)this);
  *(float *)&this->curve = (float)(Right->x * (float)v45)
                         + (float)((float)(Right->z * (float)v47) + (float)(Right->y * (float)v46));
  idTimer::Stop(this: &NavSplinePathMgr->navSplineClosestPosSectionTimer);
  return this;
}


// ========================================================================
// ?GetForward@idNavSpline@@QAA?AVidVec3@@M@Z
// EA  : 0x82CBA7E8
// RVA : 0x00CBA7E8
// PDB : w:\tech5\tungsten\game\entities\splines\navspline.cpp
// ========================================================================

idNavSpline *__fastcall idNavSpline::GetForward(idNavSpline *this, idVec3 *result, double distance)
{
  idNavSpline *v3; // r31
  double v5; // fp31
  int v6; // r3
  float y; // r4
  float *v8; // r30
  float *v9; // r3
  double v10; // fp8
  double v11; // fp6
  double v14; // fp12
  double v15; // fp2
  double v16; // fp0
  double v17; // fp13
  float v18; // r10
  float v20; // [sp+50h] [-50h] BYREF
  _BYTE v21[24]; // [sp+60h] [-40h] BYREF

  v3 = this;
  v5 = distance;
  if ( LODWORD(result->y) != 0 )
  {
    if ( distance > (float)(result[1].x - 1.0) )
      v5 = (float)(result[1].x - 1.0);
    v6 = (*(int (__fastcall **)(float *, double))(*(_DWORD *)LODWORD(result->y) + 20))(a1: &v20, a2: v5);
    y = result->y;
    v8 = (float *)v6;
    v9 = (float *)(*(int (__fastcall **)(_BYTE *, double))(*(_DWORD *)LODWORD(y) + 20))(
                    a1: v21,
                    a2: (float)((float)v5 + (float)1.0));
    v10 = (float)(v9[2] - v8[2]);
    v11 = (float)(v9[1] - v8[1]);
    _FP2 = (float)((float)((float)((float)v11 * (float)v11)
                         + (float)((float)((float)v10 * (float)v10) + (float)((float)(*v9 - *v8) * (float)(*v9 - *v8))))
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm { fsel      f13, f2, f3, f13 }
    v14 = __frsqrte(_FP13);
    v15 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v14
                                                                                        * (float)((float)((float)((float)v11 * (float)v11) + (float)((float)((float)v10 * (float)v10) + (float)((float)(*v9 - *v8) * (float)(*v9 - *v8))))
                                                                                                * (float)0.5))
                                                                                * (float)v14)
                                                                        - (float)1.5)
                                                        * (float)v14)
                                                * (float)((float)((float)((float)v11 * (float)v11)
                                                                + (float)((float)((float)v10 * (float)v10)
                                                                        + (float)((float)(*v9 - *v8) * (float)(*v9 - *v8))))
                                                        * (float)0.5))
                                        * (float)((float)-(float)((float)((float)((float)v14
                                                                                * (float)((float)((float)((float)v11 * (float)v11)
                                                                                                + (float)((float)((float)v10 * (float)v10) + (float)((float)(*v9 - *v8) * (float)(*v9 - *v8))))
                                                                                        * (float)0.5))
                                                                        * (float)v14)
                                                                - (float)1.5)
                                                * (float)v14))
                                - (float)1.5)
                * (float)((float)-(float)((float)((float)((float)v14
                                                        * (float)((float)((float)((float)v11 * (float)v11)
                                                                        + (float)((float)((float)v10 * (float)v10)
                                                                                + (float)((float)(*v9 - *v8)
                                                                                        * (float)(*v9 - *v8))))
                                                                * (float)0.5))
                                                * (float)v14)
                                        - (float)1.5)
                        * (float)v14));
    v16 = (float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v14 * (float)((float)((float)((float)v11 * (float)v11) + (float)((float)((float)v10 * (float)v10) + (float)((float)(*v9 - *v8) * (float)(*v9 - *v8)))) * (float)0.5)) * (float)v14) - (float)1.5)
                                                                                        * (float)v14)
                                                                                * (float)((float)((float)((float)v11 * (float)v11)
                                                                                                + (float)((float)((float)v10 * (float)v10) + (float)((float)(*v9 - *v8) * (float)(*v9 - *v8))))
                                                                                        * (float)0.5))
                                                                        * (float)((float)-(float)((float)((float)((float)v14 * (float)((float)((float)((float)v11 * (float)v11) + (float)((float)((float)v10 * (float)v10) + (float)((float)(*v9 - *v8) * (float)(*v9 - *v8)))) * (float)0.5)) * (float)v14)
                                                                                                - (float)1.5)
                                                                                * (float)v14))
                                                                - (float)1.5)
                                                * (float)((float)-(float)((float)((float)((float)v14
                                                                                        * (float)((float)((float)((float)v11 * (float)v11) + (float)((float)((float)v10 * (float)v10) + (float)((float)(*v9 - *v8) * (float)(*v9 - *v8))))
                                                                                                * (float)0.5))
                                                                                * (float)v14)
                                                                        - (float)1.5)
                                                        * (float)v14))
                                        * (float)((float)((float)((float)v11 * (float)v11)
                                                        + (float)((float)((float)v10 * (float)v10)
                                                                + (float)((float)(*v9 - *v8) * (float)(*v9 - *v8))))
                                                * (float)0.5))
                                * (float)v15)
                        - (float)1.5);
    v17 = (float)((float)v16
                * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v14
                                                                                                * (float)((float)((float)((float)v11 * (float)v11) + (float)((float)((float)v10 * (float)v10) + (float)((float)(*v9 - *v8) * (float)(*v9 - *v8)))) * (float)0.5))
                                                                                        * (float)v14)
                                                                                - (float)1.5)
                                                                * (float)v14)
                                                        * (float)((float)((float)((float)v11 * (float)v11)
                                                                        + (float)((float)((float)v10 * (float)v10)
                                                                                + (float)((float)(*v9 - *v8)
                                                                                        * (float)(*v9 - *v8))))
                                                                * (float)0.5))
                                                * (float)((float)-(float)((float)((float)((float)v14
                                                                                        * (float)((float)((float)((float)v11 * (float)v11) + (float)((float)((float)v10 * (float)v10) + (float)((float)(*v9 - *v8) * (float)(*v9 - *v8))))
                                                                                                * (float)0.5))
                                                                                * (float)v14)
                                                                        - (float)1.5)
                                                        * (float)v14))
                                        - (float)1.5)
                        * (float)((float)-(float)((float)((float)((float)v14
                                                                * (float)((float)((float)((float)v11 * (float)v11)
                                                                                + (float)((float)((float)v10 * (float)v10)
                                                                                        + (float)((float)(*v9 - *v8)
                                                                                                * (float)(*v9 - *v8))))
                                                                        * (float)0.5))
                                                        * (float)v14)
                                                - (float)1.5)
                                * (float)v14)));
    v20 = (float)((float)v16
                * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v14
                                                                                                * (float)((float)((float)((float)v11 * (float)v11) + (float)((float)((float)v10 * (float)v10) + (float)((float)(*v9 - *v8) * (float)(*v9 - *v8)))) * (float)0.5))
                                                                                        * (float)v14)
                                                                                - (float)1.5)
                                                                * (float)v14)
                                                        * (float)((float)((float)((float)v11 * (float)v11)
                                                                        + (float)((float)((float)v10 * (float)v10)
                                                                                + (float)((float)(*v9 - *v8)
                                                                                        * (float)(*v9 - *v8))))
                                                                * (float)0.5))
                                                * (float)((float)-(float)((float)((float)((float)v14
                                                                                        * (float)((float)((float)((float)v11 * (float)v11) + (float)((float)((float)v10 * (float)v10) + (float)((float)(*v9 - *v8) * (float)(*v9 - *v8))))
                                                                                                * (float)0.5))
                                                                                * (float)v14)
                                                                        - (float)1.5)
                                                        * (float)v14))
                                        - (float)1.5)
                        * (float)((float)-(float)((float)((float)((float)v14
                                                                * (float)((float)((float)((float)v11 * (float)v11)
                                                                                + (float)((float)((float)v10 * (float)v10)
                                                                                        + (float)((float)(*v9 - *v8)
                                                                                                * (float)(*v9 - *v8))))
                                                                        * (float)0.5))
                                                        * (float)v14)
                                                - (float)1.5)
                                * (float)v14)))
        * (float)(*v9 - *v8);
    v18 = v20;
    v3->width = (float)v10 * (float)v17;
    *(float *)&v3->curve = (float)v17 * (float)v11;
    *(float *)&v3->splinePath = v18;
    return v3;
  }
  else
  {
    this->splinePath = (idNavSplinePath *)1065353216;
    *(float *)&this->curve = 0.0;
    this->width = 0.0;
  }
  return this;
}


// ========================================================================
// ?GetNextSplines@idNavSpline@@QAAPAV1@H@Z
// EA  : 0x82CBA968
// RVA : 0x00CBA968
// PDB : w:\tech5\tungsten\game\entities\splines\navspline.cpp
// ========================================================================

idNavSpline *__fastcall idNavSpline::GetNextSplines(idNavSpline *this, int num)
{
  if ( num >= this->next.num )
    return nullptr;
  else
    return this->next.list[num].navSpline;
}


// ========================================================================
// ?GetPrevSplines@idNavSpline@@QAAPAV1@H@Z
// EA  : 0x82CBA990
// RVA : 0x00CBA990
// PDB : w:\tech5\tungsten\game\entities\splines\navspline.cpp
// ========================================================================

idNavSpline *__fastcall idNavSpline::GetPrevSplines(idNavSpline *this, int num)
{
  if ( num >= this->prev.num )
    return nullptr;
  else
    return this->prev.list[num].navSpline;
}


// ========================================================================
// ?GetDirFromLinkedSpline@idNavSpline@@QAAHPAV1@@Z
// EA  : 0x82CBA9B8
// RVA : 0x00CBA9B8
// PDB : w:\tech5\tungsten\game\entities\splines\navspline.cpp
// ========================================================================

int __fastcall idNavSpline::GetDirFromLinkedSpline(idNavSpline *this, idNavSpline *spline)
{
  navSplinePathNode_t *startNode; // r6
  int num; // r7
  int v4; // r10
  int v5; // r11
  navSplineLink_t *v6; // r9
  int v7; // r10
  int v8; // r7
  int v9; // r11
  navSplineLink_t *list; // r9

  if ( spline == nullptr )
    return 0;
  startNode = this->startNode;
  if ( startNode == nullptr )
    return 0;
  num = startNode->links.num;
  v4 = 0;
  if ( num <= 0 )
  {
LABEL_7:
    v7 = 0;
    v8 = this->endNode->links.num;
    if ( v8 > 0 )
    {
      v9 = 0;
      list = startNode->links.list;
      while ( list->navSpline != spline )
      {
        ++v7;
        list = &startNode->links.list[++v9];
        if ( v7 >= v8 )
          return 0;
      }
      return -1;
    }
    return 0;
  }
  v5 = 0;
  v6 = startNode->links.list;
  while ( v6->navSpline != spline )
  {
    ++v4;
    v6 = &startNode->links.list[++v5];
    if ( v4 >= num )
      goto LABEL_7;
  }
  return 1;
}


// ========================================================================
// ?CalcBounds@idNavSpline@@QAAXXZ
// EA  : 0x82CBAA60
// RVA : 0x00CBAA60
// PDB : w:\tech5\tungsten\game\entities\splines\navspline.cpp
// ========================================================================

void __fastcall idNavSpline::CalcBounds(idNavSpline *this)
{
  float *p_bounds; // r31
  double v3; // fp31
  idVec3 v28; // [sp+50h] [-60h] BYREF
  idVec3 v29; // [sp+60h] [-50h] BYREF

  p_bounds = (float *)&this->bounds;
  this->bounds.b[0].z = 1.0e30;
  this->bounds.b[0].y = 1.0e30;
  this->bounds.b[0].x = 1.0e30;
  v3 = 0.0;
  this->bounds.b[1].z = -1.0e30;
  this->bounds.b[1].y = -1.0e30;
  this->bounds.b[1].x = -1.0e30;
  if ( this->length > 0.0 )
  {
    do
    {
      if ( this->curve != nullptr )
        ((void (__fastcall *)(idVec3 *, double))this->curve->GetCurrentValue)(a1: &v28, a2: v3);
      else
        v28 = vec3_origin;
      v3 = (float)((float)v3 + (float)50.0);
      _FP9 = (float)(v28.x - p_bounds[3]);
      _FP5 = (float)(v28.z - p_bounds[5]);
      _FP3 = (float)(*p_bounds - v28.x);
      _FP7 = (float)(v28.y - p_bounds[4]);
      _FP1 = (float)(p_bounds[1] - v28.y);
      _FP29 = (float)(p_bounds[2] - v28.z);
      __asm { fsel      f11, f9, f0, f11 }
      p_bounds[3] = _FP11;
      __asm { fsel      f9, f5, f12, f8 }
      p_bounds[5] = _FP9;
      __asm { fsel      f8, f3, f0, f6 }
      *p_bounds = _FP8;
      __asm { fsel      f10, f7, f13, f10 }
      p_bounds[4] = _FP10;
      __asm { fsel      f7, f1, f13, f4 }
      p_bounds[1] = _FP7;
      __asm { fsel      f6, f29, f12, f2 }
      p_bounds[2] = _FP6;
    }
    while ( v3 < this->length );
  }
  if ( this->curve != nullptr )
    ((void (__fastcall *)(idVec3 *))this->curve->GetCurrentValue)(a1: &v29);
  else
    v29 = vec3_origin;
  _FP9 = (float)(*p_bounds - v29.x);
  _FP5 = (float)(p_bounds[2] - v29.z);
  _FP3 = (float)(v29.x - p_bounds[3]);
  _FP7 = (float)(p_bounds[1] - v29.y);
  _FP1 = (float)(v29.y - p_bounds[4]);
  _FP31 = (float)(v29.z - p_bounds[5]);
  __asm { fsel      f11, f9, f0, f11 }
  *p_bounds = _FP11;
  __asm { fsel      f9, f5, f12, f8 }
  p_bounds[2] = _FP9;
  __asm { fsel      f8, f3, f0, f6 }
  p_bounds[3] = _FP8;
  __asm { fsel      f10, f7, f13, f10 }
  p_bounds[1] = _FP10;
  __asm { fsel      f7, f1, f13, f4 }
  p_bounds[4] = _FP7;
  __asm { fsel      f6, f31, f12, f2 }
  p_bounds[5] = _FP6;
}


// ========================================================================
// ?IsDeadEnd@idNavSpline@@QAA_NXZ
// EA  : 0x82CBAC58
// RVA : 0x00CBAC58
// PDB : w:\tech5\tungsten\game\entities\splines\navspline.cpp
// ========================================================================

int __fastcall idNavSpline::IsDeadEnd(idNavSpline *this)
{
  unsigned __int8 v2; // r11

  if ( this->isTempSpline )
    return 0;
  if ( this->startNode->links.num == 1 )
    return 1;
  v2 = 0;
  if ( this->endNode->links.num == 1 )
    return 1;
  return v2;
}


// ========================================================================
// ?GetStartPathPos@navSplinePath_t@@QAA?AVidNavSplinePosition@@XZ
// EA  : 0x82CBACA0
// RVA : 0x00CBACA0
// PDB : w:\tech5\tungsten\game\entities\splines\navspline.cpp
// ========================================================================

navSplinePath_t *__fastcall navSplinePath_t::GetStartPathPos(navSplinePath_t *this, idNavSplinePosition *result)
{
  float rightDistance; // r11
  float v3; // r9

  if ( (int)result[1].navSpline <= 0 )
  {
    this->distance = 0.0;
    this->startDistance = 0.0;
    this->endDistance = 0.0;
  }
  else
  {
    rightDistance = result[1].rightDistance;
    this->startDistance = result->distance;
    v3 = *(float *)LODWORD(rightDistance);
    this->endDistance = 0.0;
    this->distance = v3;
  }
  return this;
}


// ========================================================================
// ?IsSingleSpline@navSplinePath_t@@QAA_NXZ
// EA  : 0x82CBACF0
// RVA : 0x00CBACF0
// PDB : w:\tech5\tungsten\game\entities\splines\navspline.cpp
// ========================================================================

int __fastcall navSplinePath_t::IsSingleSpline(navSplinePath_t *this)
{
  int num; // r8
  int v2; // r10
  int i; // r11

  num = this->path.num;
  if ( num < 2 )
    return 1;
  v2 = 1;
  for ( i = 1; this->path.list[i].navSpline == this->path.list->navSpline; ++i )
  {
    if ( ++v2 >= num )
      return 1;
  }
  return 0;
}


// ========================================================================
// ?GetDrawColor@idQuestNavSplinePath@@QBA?AVidColor@@XZ
// EA  : 0x82CBAD40
// RVA : 0x00CBAD40
// PDB : w:\tech5\tungsten\game\entities\splines\navspline.cpp
// ========================================================================

idQuestNavSplinePath *__fastcall idQuestNavSplinePath::GetDrawColor(idQuestNavSplinePath *this, idColor *result)
{
  double v2; // fp13
  float b; // r11

  v2 = 0.0;
  if ( HIBYTE(result[57].a) != 0 )
    v2 = 1.0;
  b = result[57].b;
  if ( b == 0.0 )
  {
    *(float *)&this->__vftable = 0.0;
    *(float *)&this->listenerList = 1.0;
    *(float *)&this->name.len = 1.0;
    *(float *)&this->listeningToList = v2;
  }
  else
  {
    switch ( LODWORD(b) )
    {
      case 1:
        *(float *)&this->name.len = 1.0;
        *(float *)&this->__vftable = 0.0;
        *(float *)&this->listeningToList = v2;
        *(float *)&this->listenerList = 0.69999999;
        break;
      case 2:
        *(float *)&this->name.len = 1.0;
        *(float *)&this->__vftable = 0.0;
        *(float *)&this->listeningToList = v2;
        *(float *)&this->listenerList = 0.40000001;
        break;
      case 3:
        *(float *)&this->listenerList = 1.0;
        *(float *)&this->name.len = 1.0;
        *(float *)&this->listeningToList = v2;
        *(float *)&this->__vftable = 0.5;
        break;
      default:
        *(float *)&this->listenerList = 0.0;
        *(float *)&this->name.len = 0.0;
        *(float *)&this->__vftable = 1.0;
        *(float *)&this->listeningToList = v2;
        break;
    }
  }
  return this;
}


// ========================================================================
// ?DetermineBestLinks@idNavSpline@@QAAXXZ
// EA  : 0x82CBAE70
// RVA : 0x00CBAE70
// PDB : w:\tech5\tungsten\game\entities\splines\navspline.cpp
// ========================================================================

void __fastcall idNavSpline::DetermineBestLinks(idNavSpline *this)
{
  idNavSpline *v2; // r27
  double v3; // fp30
  double v4; // fp29
  idNavSpline *navSpline; // r31
  int v6; // r29
  double width; // fp28
  int v8; // r30
  double v9; // fp27
  double v10; // fp26
  navSplinePathNode_t *startNode; // r10
  char v12; // r11
  float *Forward; // r3
  double v14; // fp0
  double v15; // fp13
  double v16; // fp12
  float *v17; // r3
  double v18; // fp0
  float *v19; // r3
  idNavSpline *v20; // r27
  double v21; // fp29
  double v22; // fp28
  double v23; // fp27
  idNavSpline *v24; // r31
  int v25; // r29
  int v26; // r30
  navSplinePathNode_t *v27; // r10
  char v28; // r11
  float *v29; // r3
  double v30; // fp0
  double v31; // fp13
  double v32; // fp12
  float *v33; // r3
  double v34; // fp0
  idNavSpline v35; // [sp+50h] [-80h] BYREF

  idNavSpline::GetForward(this: &v35, result: (idVec3 *)this, distance: (float)(this->length - (float)100.0));
  v2 = nullptr;
  v3 = -1.0;
  v4 = -1.0;
  if ( this->next.num <= 0 )
    navSpline = nullptr;
  else
    navSpline = this->next.list->navSpline;
  v6 = 1;
  if ( navSpline != nullptr )
  {
    width = v35.width;
    v8 = 1;
    v9 = *(float *)&v35.curve;
    v10 = *(float *)&v35.splinePath;
    do
    {
      startNode = navSpline->startNode;
      if ( startNode == nullptr || (v12 = 1, navSpline->endNode == nullptr) )
        v12 = 0;
      if ( v12 == 0 )
        goto LABEL_17;
      if ( startNode == this->endNode )
      {
        if ( (*(_BYTE *)&navSpline->splinePath->splineFlags & 0x40) != 0 )
        {
          Forward = (float *)idNavSpline::GetForward(this: &v35, result: (idVec3 *)navSpline, distance: 100.0);
          v14 = *Forward;
          v15 = Forward[1];
          v16 = Forward[2];
          goto LABEL_15;
        }
      }
      else if ( (*(_BYTE *)&navSpline->splinePath->splineFlags & 0x20) != 0 )
      {
        v17 = (float *)idNavSpline::GetForward(
                         this: (idNavSpline *)&v35.traversed,
                         result: (idVec3 *)navSpline,
                         distance: (float)(navSpline->length - (float)100.0));
        v14 = -*v17;
        v15 = -v17[1];
        v16 = -v17[2];
LABEL_15:
        v18 = (float)((float)((float)v10 * (float)v14)
                    + (float)((float)((float)width * (float)v16) + (float)((float)v9 * (float)v15)));
        if ( v18 > v4 )
        {
          v4 = v18;
          v2 = navSpline;
        }
      }
LABEL_17:
      if ( v6 >= this->next.num )
        navSpline = nullptr;
      else
        navSpline = this->next.list[v8].navSpline;
      ++v6;
      ++v8;
    }
    while ( navSpline != nullptr );
  }
  this->bestNext = v2;
  v19 = (float *)idNavSpline::GetForward(this: (idNavSpline *)&v35.traversed, result: (idVec3 *)this, distance: 100.0);
  v20 = nullptr;
  v21 = -*v19;
  v22 = -v19[1];
  v23 = -v19[2];
  if ( this->prev.num <= 0 )
    v24 = nullptr;
  else
    v24 = this->prev.list->navSpline;
  v25 = 1;
  if ( v24 != nullptr )
  {
    v26 = 1;
    do
    {
      v27 = v24->startNode;
      if ( v27 == nullptr || (v28 = 1, v24->endNode == nullptr) )
        v28 = 0;
      if ( v28 != 0 )
      {
        if ( v27 == this->startNode )
        {
          v29 = (float *)idNavSpline::GetForward(
                           this: (idNavSpline *)&v35.traversed,
                           result: (idVec3 *)v24,
                           distance: 100.0);
          v30 = *v29;
          v31 = v29[1];
          v32 = v29[2];
        }
        else
        {
          v33 = (float *)idNavSpline::GetForward(
                           this: &v35,
                           result: (idVec3 *)v24,
                           distance: (float)(v24->length - (float)100.0));
          v30 = -*v33;
          v31 = -v33[1];
          v32 = -v33[2];
        }
        v34 = (float)((float)((float)v30 * (float)v21)
                    + (float)((float)((float)v32 * (float)v23) + (float)((float)v31 * (float)v22)));
        if ( v34 > v3 )
        {
          v3 = v34;
          v20 = v24;
        }
      }
      if ( v25 >= this->prev.num )
        v24 = nullptr;
      else
        v24 = this->prev.list[v26].navSpline;
      ++v25;
      ++v26;
    }
    while ( v24 != nullptr );
  }
  this->bestPrev = v20;
}


// ========================================================================
// ?GetWidth@idNavSpline@@QAAMM@Z
// EA  : 0x82CBB118
// RVA : 0x00CBB118
// PDB : w:\tech5\tungsten\game\entities\splines\navspline.cpp
// ========================================================================

float __fastcall idNavSpline::GetWidth(idNavSpline *this, double distance)
{
  idCurve_Spline<idVec3> *curve; // r6
  double v3; // fp0
  int num; // r7
  int v5; // r11
  float *list; // r8
  int v7; // r10
  bool v8; // cr58
  int v9; // r10
  int v10; // r11
  double v11; // fp1

  curve = this->curve;
  v3 = 0.0;
  if ( curve == nullptr || this->splinePath == nullptr || distance < 0.0 || distance > this->length )
  {
    v11 = 0.0;
    return *((float *)&v11 + 1);
  }
  num = curve->values.num;
  v5 = 0;
  if ( num >= 4 )
  {
    list = curve->times.list;
    v7 = 0;
    do
    {
      v3 = list[v7];
      if ( v3 > distance )
        goto LABEL_20;
      v3 = list[v7 + 1];
      if ( v3 > distance )
      {
        ++v5;
        goto LABEL_20;
      }
      v3 = list[v7 + 2];
      if ( v3 > distance )
      {
        v5 += 2;
        goto LABEL_20;
      }
      v3 = list[v7 + 3];
      if ( v3 > distance )
      {
        v5 += 3;
        goto LABEL_20;
      }
      v5 += 4;
      v7 += 4;
    }
    while ( v5 < num - 3 );
  }
  v8 = v5 == num;
  if ( v5 < num )
  {
    v9 = v5;
    do
    {
      v3 = curve->times.list[v9];
      if ( v3 > distance )
        break;
      ++v5;
      ++v9;
    }
    while ( v5 < num );
LABEL_20:
    v8 = v5 == num;
  }
  if ( v8 )
    --v5;
  v10 = v5;
  v11 = (float)((float)((float)((float)((float)distance - curve->times.list[v10 - 1])
                              / (float)((float)v3 - curve->times.list[v10 - 1]))
                      * (float)(this->splinePath->pathWidth.list[v10] - this->splinePath->pathWidth.list[v10 - 1]))
              + this->splinePath->pathWidth.list[v10 - 1]);
  return *((float *)&v11 + 1);
}


// ========================================================================
// ?CleanupEntityList@idNavSpline@@QAAXXZ
// EA  : 0x82CBB248
// RVA : 0x00CBB248
// PDB : w:\tech5\tungsten\game\entities\splines\navspline.cpp
// ========================================================================

void __fastcall idNavSpline::CleanupEntityList(idNavSpline *this)
{
  int v1; // r10
  idList<idEntityPtr<idEntity>,5> *p_entityList; // r8
  int v3; // r9
  int num; // r11
  int v5; // r11

  v1 = 0;
  if ( this->entityList.num > 0 )
  {
    p_entityList = &this->entityList;
    v3 = 0;
    do
    {
      if ( gameLocal->spawnIds.ptr[p_entityList->list[v3].spawnId.value & 0x1FFF] != p_entityList->list[v3].spawnId.value >> 13 )
      {
        if ( v1 >= 0 )
        {
          num = this->entityList.num;
          if ( v1 < num )
          {
            v5 = num - 1;
            this->entityList.num = v5;
            if ( v1 != v5 )
              p_entityList->list[v3].spawnId.value = p_entityList->list[v5].spawnId.value;
          }
        }
        --v1;
        --v3;
      }
      ++v1;
      ++v3;
    }
    while ( v1 < this->entityList.num );
  }
}


// ========================================================================
// ?Draw@idNavSpline@@QAAXVidColor@@MMM_N@Z
// EA  : 0x82CBB2E0
// RVA : 0x00CBB2E0
// PDB : w:\tech5\tungsten\game\entities\splines\navspline.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idNavSpline::Draw(
        idNavSpline *this,
        __int64 showRight,
        double startDist,
        double endDist,
        double stepSize,
        int a6,
        int a7,
        int a8,
        char a9,
        int a10,
        __int64 a11,
        __int64 a12,
        __int64 a13,
        __int64 a14,
        __int64 a15)
{
  idCurve_Spline<idVec3> *curve; // r4
  idCurve_Spline<idVec3> *v21; // r4
  float *Forward; // r3
  double v23; // fp24
  double v24; // fp23
  double v25; // fp22
  double Width; // fp1
  idNavSpline *v27; // r3
  double v28; // fp1
  double v29; // fp1
  idNavSpline *v30; // r3
  double v31; // fp1
  idVec3 *v32; // r6
  idVec3 *v33; // r5
  idCurve_Spline<idVec3> *v34; // r4
  idVec3 v35; // [sp+50h] [-110h] BYREF
  idVec3 v36; // [sp+60h] [-100h] BYREF
  idVec3 v37; // [sp+70h] [-F0h] BYREF
  float v38[4]; // [sp+80h] [-E0h] BYREF
  float v39[4]; // [sp+90h] [-D0h] BYREF
  float v40[4]; // [sp+A0h] [-C0h] BYREF
  float v41[4]; // [sp+B0h] [-B0h] BYREF
  float v42[4]; // [sp+C0h] [-A0h] BYREF
  idNavSpline v43; // [sp+D0h] [-90h] BYREF

  a14 = *(__int64 *)((char *)&showRight + 4);
  a15 = showRight;
  if ( gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) != this->drawtime )
  {
    for ( ; startDist <= endDist; startDist = (float)((float)startDist + (float)stepSize) )
    {
      if ( (float)((float)endDist - (float)startDist) < stepSize )
        stepSize = (float)((float)((float)endDist - (float)startDist) + (float)1.0);
      curve = this->curve;
      if ( curve != nullptr )
        ((void (__fastcall *)(idVec3 *, double))curve->GetCurrentValue)(a1: &v35, a2: startDist);
      else
        v35 = vec3_origin;
      v21 = this->curve;
      if ( v21 != nullptr )
        ((void (__fastcall *)(idVec3 *, double))v21->GetCurrentValue)(
          a1: &v36,
          a2: (float)((float)startDist + (float)stepSize));
      else
        v36 = vec3_origin;
      if ( a9 != 0 )
      {
        Forward = (float *)idNavSpline::GetForward(this: &v43, result: (idVec3 *)this, distance: startDist);
        v23 = (float)((float)(*Forward * (float)0.0) - (float)(Forward[1] * (float)0.0));
        v24 = (float)(Forward[1] - (float)(Forward[2] * (float)0.0));
        v25 = (float)((float)(Forward[2] * (float)0.0) - *Forward);
        Width = idNavSpline::GetWidth(this, distance: (float)((float)startDist + (float)stepSize));
        v38[0] = v36.x + (float)((float)v24 * (float)Width);
        v38[1] = v36.y + (float)((float)v25 * (float)Width);
        v38[2] = v36.z + (float)((float)v23 * (float)Width);
        v28 = idNavSpline::GetWidth(this: v27, distance: startDist);
        v39[0] = v35.x + (float)((float)v24 * (float)v28);
        v39[1] = v35.y + (float)((float)v25 * (float)v28);
        v39[2] = v35.z + (float)((float)v23 * (float)v28);
        clientGame->renderWorld->DebugLine(
          this: clientGame->renderWorld,
          a2: (const idVec4 *)&a14,
          a3: (const idVec3 *)v39,
          a4: (const idVec3 *)v38,
          a5: 0,
          a6: false);
        v29 = idNavSpline::GetWidth(this, distance: (float)((float)startDist + (float)stepSize));
        v40[0] = v36.x - (float)((float)v24 * (float)v29);
        v40[1] = v36.y - (float)((float)v25 * (float)v29);
        v40[2] = v36.z - (float)((float)v23 * (float)v29);
        v31 = idNavSpline::GetWidth(this: v30, distance: startDist);
        v41[0] = v35.x - (float)((float)v31 * (float)v24);
        v41[1] = v35.y - (float)((float)v25 * (float)v31);
        v41[2] = v35.z - (float)((float)v23 * (float)v31);
        clientGame->renderWorld->DebugLine(
          this: clientGame->renderWorld,
          a2: (const idVec4 *)&a14,
          a3: (const idVec3 *)v41,
          a4: (const idVec3 *)v40,
          a5: 0,
          a6: false);
      }
      else
      {
        if ( (*(_BYTE *)&this->splinePath->splineFlags & 0x40) != 0 )
        {
          if ( (*(_BYTE *)&this->splinePath->splineFlags & 0x20) != 0 )
          {
            clientGame->renderWorld->DebugLine(
              this: clientGame->renderWorld,
              a2: (const idVec4 *)&a14,
              a3: &v35,
              a4: &v36,
              a5: 0,
              a6: false);
            continue;
          }
          if ( (*(_BYTE *)&this->splinePath->splineFlags & 0x40) != 0 )
          {
            v32 = &v36;
            v33 = &v35;
LABEL_20:
            ((void (__fastcall *)(idRenderWorld *, __int64 *, idVec3 *, idVec3 *, double))clientGame->renderWorld->DebugArrow)(
              a1: clientGame->renderWorld,
              a2: &a14,
              a3: v33,
              a4: v32,
              a5: 15.0);
            continue;
          }
        }
        if ( (*(_BYTE *)&this->splinePath->splineFlags & 0x20) != 0 )
        {
          v32 = &v35;
          v33 = &v36;
          goto LABEL_20;
        }
      }
    }
    v34 = this->curve;
    if ( v34 != nullptr )
      ((void (__fastcall *)(idVec3 *, double))v34->GetCurrentValue)(a1: &v37, a2: 0.0);
    else
      v37 = vec3_origin;
    v42[0] = v37.x;
    v42[1] = v37.y;
    v42[2] = v37.z + (float)100.0;
    clientGame->renderWorld->DebugLine(
      this: clientGame->renderWorld,
      a2: (const idVec4 *)&idColor::colorGreen,
      a3: &v37,
      a4: (const idVec3 *)v42,
      a5: 0,
      a6: false);
    this->drawtime = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
  }
}


// ========================================================================
// ?Step@navSplinePath_t@@QAAXM@Z
// EA  : 0x82CBB6F8
// RVA : 0x00CBB6F8
// PDB : w:\tech5\tungsten\game\entities\splines\navspline.cpp
// ========================================================================

void __fastcall navSplinePath_t::Step(navSplinePath_t *this, double stepdist)
{
  int num; // r11
  int v3; // r11
  int v4; // r11
  int v5; // r10
  int v6; // r9
  navSplinePath_t::path_t *v7; // r11
  navSplinePath_t::path_t *v8; // r11
  navSplinePath_t::path_t *list; // r11
  idList<navSplinePath_t::path_t,5> *p_path; // r8
  double v11; // fp11
  double startDistance; // fp0
  double v13; // fp9
  idNavSpline *navSpline; // r7
  int v15; // r11
  int v16; // r11
  int v17; // r10
  int v18; // r9
  navSplinePath_t::path_t *v19; // r11
  double v20; // fp0

  num = this->path.num;
  if ( (float)(this->distance - (float)stepdist) >= 0.001 )
  {
    if ( num != 0 )
    {
      list = this->path.list;
      p_path = &this->path;
      v11 = (float)((float)(list->dir * (float)stepdist) + this->startDistance);
      this->distance = this->distance - (float)stepdist;
LABEL_11:
      this->startDistance = v11;
      while ( 1 )
      {
        startDistance = this->startDistance;
        if ( startDistance >= 0.0 && startDistance <= list->navSpline->length )
          break;
        if ( stepdist >= 0.0 )
        {
          navSpline = list->navSpline;
          if ( this->path.num <= 2 )
          {
            list->navSpline = list[1].navSpline;
            p_path->list->dir = -p_path->list[1].dir;
          }
          else
          {
            v15 = this->path.num;
            if ( v15 > 0 )
            {
              v16 = v15 - 1;
              v17 = 0;
              this->path.num = v16;
              if ( v16 > 0 )
              {
                v18 = 0;
                do
                {
                  ++v17;
                  v19 = &p_path->list[v18++];
                  v19->navSpline = v19[1].navSpline;
                  v19->dir = v19[1].dir;
                }
                while ( v17 < this->path.num );
              }
            }
          }
          v20 = this->startDistance;
          if ( v20 >= 0.0 )
            this->startDistance = this->startDistance - navSpline->length;
          else
            this->startDistance = -v20;
          list = p_path->list;
          if ( p_path->list->dir < 0.0 )
          {
            v11 = (float)(list->navSpline->length - this->startDistance);
            goto LABEL_11;
          }
        }
        else
        {
          v13 = (float)((float)stepdist + this->distance);
          this->startDistance = -(float)((float)(list->dir * (float)stepdist) - this->startDistance);
          this->distance = v13;
        }
      }
    }
  }
  else
  {
    if ( num > 2 )
    {
      do
      {
        v3 = this->path.num;
        if ( v3 > 0 )
        {
          v4 = v3 - 1;
          v5 = 0;
          this->path.num = v4;
          if ( v4 > 0 )
          {
            v6 = 0;
            do
            {
              ++v5;
              v7 = &this->path.list[v6++];
              v7->navSpline = v7[1].navSpline;
              v7->dir = v7[1].dir;
            }
            while ( v5 < this->path.num );
          }
        }
      }
      while ( this->path.num > 2 );
    }
    v8 = this->path.list;
    this->startDistance = this->endDistance;
    v8->navSpline = v8[1].navSpline;
    this->distance = 0.0;
  }
}


// ========================================================================
// ?Draw@navSplinePath_t@@QAAXVidColor@@M@Z
// EA  : 0x82CBB8C8
// RVA : 0x00CBB8C8
// PDB : w:\tech5\tungsten\game\entities\splines\navspline.cpp
// ========================================================================

void __fastcall navSplinePath_t::Draw(navSplinePath_t *this, idColor *color, double stepSize, int a4)
{
  int v7; // r10
  int v8; // r8
  int v9; // r7
  __int64 v10; // r6
  char IsSingleSpline; // r3
  navSplinePath_t::path_t *list; // r11
  idNavSpline *navSpline; // r3
  unsigned int v18; // r10
  double startDistance; // fp1
  double length; // fp2
  int v21; // r8
  int v22; // r7
  int num; // r11
  int v24; // r30
  char v25; // r10
  int v26; // r29
  navSplinePath_t::path_t *v27; // r10
  int v28; // r11
  char *v29; // r11
  int v30; // [sp+8h] [-98h]
  __int64 v31; // [sp+10h] [-90h]
  __int64 v32; // [sp+18h] [-88h]
  __int64 v33; // [sp+20h] [-80h]
  __int64 v34; // [sp+28h] [-78h]
  __int64 v35; // [sp+30h] [-70h]

  if ( this->path.num >= 2 )
  {
    IsSingleSpline = navSplinePath_t::IsSingleSpline(this);
    list = this->path.list;
    if ( IsSingleSpline != 0 )
    {
      navSpline = list->navSpline;
      _FP12 = (float)(this->startDistance - this->endDistance);
      _FP11 = _FP12;
      __asm
      {
        fsel      f2, f12, f13, f0
        fsel      f1, f11, f0, f13
      }
    }
    else
    {
      v18 = 0x82000000;
      if ( list->dir == 1.0 )
      {
        v18 = (unsigned int)list->navSpline;
        startDistance = this->startDistance;
        length = list->navSpline->length;
      }
      else
      {
        length = this->startDistance;
        startDistance = 0.0;
      }
      HIDWORD(v10) = a4;
      idNavSpline::Draw(
        this: list->navSpline,
        showRight: v10,
        startDist: startDistance,
        endDist: length,
        stepSize,
        a6: v9,
        a7: v8,
        a8: 0,
        a9: v18,
        a10: v30,
        a11: v31,
        a12: v32,
        a13: v33,
        a14: v34,
        a15: v35);
      num = this->path.num;
      v24 = 1;
      v25 = num - 1;
      if ( num - 1 > 1 )
      {
        v26 = 1;
        do
        {
          HIDWORD(v10) = a4;
          idNavSpline::Draw(
            this: this->path.list[v26].navSpline,
            showRight: v10,
            startDist: 0.0,
            endDist: this->path.list[v26].navSpline->length,
            stepSize,
            a6: v22,
            a7: v21,
            a8: 0,
            a9: v25,
            a10: v30,
            a11: v31,
            a12: v32,
            a13: v33,
            a14: v34,
            a15: v35);
          num = this->path.num;
          ++v24;
          ++v26;
          v25 = num - 1;
        }
        while ( v24 < num - 1 );
      }
      v27 = this->path.list;
      v28 = num;
      v8 = (int)v27->navSpline;
      v9 = (int)v27[v28 - 1].navSpline;
      if ( v27->navSpline == (idNavSpline *)v9 )
      {
        v8 = (int)&v27[v28];
        v9 = (int)v27[v28 - 1].navSpline;
        *(_DWORD *)(v9 + 108) = 0;
      }
      v7 = 8 * this->path.num;
      v29 = (char *)this->path.list + v7;
      if ( *((float *)v29 - 1) == 1.0 )
      {
        v7 = *((_DWORD *)v29 - 2);
        _FP1 = this->endDistance;
        _FP2 = *(float *)(v7 + 12);
      }
      else
      {
        _FP2 = this->endDistance;
        _FP1 = 0.0;
      }
      navSpline = *((idNavSpline **)v29 - 2);
    }
    HIDWORD(v10) = a4;
    idNavSpline::Draw(
      this: navSpline,
      showRight: v10,
      startDist: _FP1,
      endDist: _FP2,
      stepSize,
      a6: v9,
      a7: v8,
      a8: 0,
      a9: v7,
      a10: v30,
      a11: v31,
      a12: v32,
      a13: v33,
      a14: v34,
      a15: v35);
  }
}


// ========================================================================
// ??0idNavSpline@@QAA@XZ
// EA  : 0x82CBBB28
// RVA : 0x00CBBB28
// PDB : w:\tech5\tungsten\game\entities\splines\navspline.cpp
// ========================================================================

idNavSpline *__fastcall idNavSpline::idNavSpline(idNavSpline *this)
{
  this->next.list = nullptr;
  this->next.granularity = 0;
  this->next.memTag = 5;
  this->next.listStatic = 0;
  this->next.size = 0;
  this->next.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->next);
  this->prev.list = nullptr;
  this->prev.granularity = 0;
  this->prev.memTag = 5;
  this->prev.listStatic = 0;
  this->prev.size = 0;
  this->prev.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->prev);
  this->entityList.list = nullptr;
  this->entityList.granularity = 0;
  this->entityList.memTag = 5;
  this->entityList.listStatic = 0;
  this->entityList.size = 0;
  this->entityList.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->entityList);
  this->splinePath = nullptr;
  this->curve = nullptr;
  this->traversed = false;
  this->isTempSpline = false;
  this->drawtime = 0;
  this->width = 0.0;
  this->bestNext = nullptr;
  this->length = 0.0;
  this->bestPrev = nullptr;
  this->startNode = nullptr;
  this->endNode = nullptr;
  return this;
}


// ========================================================================
// __unwind$490158
// EA  : 0x82CBBBE8
// RVA : 0x00CBBBE8
// PDB : w:\tech5\tungsten\game\entities\splines\navspline.cpp
// ========================================================================

void _unwind_490158()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 20));
}


// ========================================================================
// __unwind$490159
// EA  : 0x82CBBC14
// RVA : 0x00CBBC14
// PDB : w:\tech5\tungsten\game\entities\splines\navspline.cpp
// ========================================================================

void _unwind_490159()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 36));
}


// ========================================================================
// ??1idNavSpline@@QAA@XZ
// EA  : 0x82CBBC48
// RVA : 0x00CBBC48
// PDB : w:\tech5\tungsten\game\entities\splines\navspline.cpp
// ========================================================================

void __fastcall idNavSpline::~idNavSpline(idNavSpline *this)
{
  idCurve_Spline<idVec3> *curve; // r3

  curve = this->curve;
  if ( curve != nullptr )
  {
    ((void (__fastcall *)(idCurve_Spline<idVec3> *, int))curve->dtr_idCurve<idVec3>)(a1: curve, a2: 1);
    this->curve = nullptr;
  }
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->entityList);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->prev);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->next);
}


// ========================================================================
// __unwind$490199_0
// EA  : 0x82CBBCC4
// RVA : 0x00CBBCC4
// PDB : w:\tech5\tungsten\game\entities\splines\navspline.cpp
// ========================================================================

void _unwind_490199_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 20));
}


// ========================================================================
// __unwind$490200
// EA  : 0x82CBBCF0
// RVA : 0x00CBBCF0
// PDB : w:\tech5\tungsten\game\entities\splines\navspline.cpp
// ========================================================================

void _unwind_490200()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 36));
}


// ========================================================================
// __unwind$490201
// EA  : 0x82CBBD1C
// RVA : 0x00CBBD1C
// PDB : w:\tech5\tungsten\game\entities\splines\navspline.cpp
// ========================================================================

void _unwind_490201()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 52));
}


// ========================================================================
// ?Init@idNavSpline@@QAAXXZ
// EA  : 0x82CBBD48
// RVA : 0x00CBBD48
// PDB : w:\tech5\tungsten\game\entities\splines\navspline.cpp
// ========================================================================

void __fastcall idNavSpline::Init(idNavSpline *this)
{
  if ( !common->IsToolActive(this: common) )
    idNavSpline::DetermineBestLinks(this);
}


// ========================================================================
// ??YnavSplinePath_t@@QAAXABU0@@Z
// EA  : 0x82CBBF80
// RVA : 0x00CBBF80
// PDB : w:\tech5\tungsten\game\entities\splines\navspline.cpp
// ========================================================================

void __fastcall navSplinePath_t::operator+=(navSplinePath_t *this, const navSplinePath_t *that)
{
  int num; // r30
  int v4; // r31
  idList<navSplinePath_t::path_t,5> *p_path; // r29
  navSplinePath_t::path_t *list; // r11
  int v7; // r30

  num = this->path.num;
  v4 = that->path.num;
  if ( num < 2 || v4 < 2 )
  {
    if ( num == 0 && v4 > 0 )
      navSplinePath_t::operator=(this, __that: that);
  }
  else
  {
    this->distance = that->distance + this->distance;
    this->endDistance = that->endDistance;
    if ( num == 2 && (p_path = &this->path, this->path.list->navSpline == this->path.list[1].navSpline) )
    {
      idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->path);
      num = 0;
    }
    else
    {
      p_path = &this->path;
      idList<navSplinePath_t::path_t,5>::RemoveIndex(this: &this->path, index: num - 1);
    }
    if ( v4 == 2 && num > 0 && (list = that->path.list)->navSpline == list[1].navSpline )
    {
      idList<navSplinePath_t::path_t,5>::Append(this: p_path, obj: list + 1);
    }
    else
    {
      v7 = 0;
      do
      {
        idList<navSplinePath_t::path_t,5>::Append(this: p_path, obj: &that->path.list[v7]);
        --v4;
        ++v7;
      }
      while ( v4 != 0 );
    }
  }
}


// ========================================================================
// `dynamic initializer for 'spl_qn_pathVectorStep_Short''
// EA  : 0x83378700
// RVA : 0x01378700
// PDB : w:\tech5\tungsten\game\entities\splines\navspline.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__spl_qn_pathVectorStep_Short__()
{
  idCVar::idCVar(
    this: &spl_qn_pathVectorStep_Short,
    name: "spl_qn_pathVectorStep_Short",
    value: "200",
    flags: 4,
    description: "Short Dist from start to get forward vector",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__spl_qn_pathVectorStep_Short__);
}


// ========================================================================
// `dynamic initializer for 'spl_qn_pathVectorStep_Short_Max''
// EA  : 0x83378758
// RVA : 0x01378758
// PDB : w:\tech5\tungsten\game\entities\splines\navspline.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__spl_qn_pathVectorStep_Short_Max__()
{
  idCVar::idCVar(
    this: &spl_qn_pathVectorStep_Short_Max,
    name: "spl_qn_pathVectorStep_Short_Max",
    value: "300",
    flags: 4,
    description: "Short Dist from start to get forward vector",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__spl_qn_pathVectorStep_Short_Max__);
}


// ========================================================================
// `dynamic initializer for 'spl_qn_pathVectorStep_Medium''
// EA  : 0x833787B0
// RVA : 0x013787B0
// PDB : w:\tech5\tungsten\game\entities\splines\navspline.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__spl_qn_pathVectorStep_Medium__()
{
  idCVar::idCVar(
    this: &spl_qn_pathVectorStep_Medium,
    name: "spl_qn_pathVectorStep_Medium",
    value: "500",
    flags: 4,
    description: "Medium Dist from start to get forward vector",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__spl_qn_pathVectorStep_Medium__);
}


// ========================================================================
// `dynamic initializer for 'spl_qn_pathVectorStep_Medium_Max''
// EA  : 0x83378808
// RVA : 0x01378808
// PDB : w:\tech5\tungsten\game\entities\splines\navspline.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__spl_qn_pathVectorStep_Medium_Max__()
{
  idCVar::idCVar(
    this: &spl_qn_pathVectorStep_Medium_Max,
    name: "spl_qn_pathVectorStep_Medium_Max",
    value: "750",
    flags: 4,
    description: "Medium Dist from start to get forward vector",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__spl_qn_pathVectorStep_Medium_Max__);
}


// ========================================================================
// `dynamic initializer for 'spl_qn_pathVectorStep_Long''
// EA  : 0x83378860
// RVA : 0x01378860
// PDB : w:\tech5\tungsten\game\entities\splines\navspline.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__spl_qn_pathVectorStep_Long__()
{
  idCVar::idCVar(
    this: &spl_qn_pathVectorStep_Long,
    name: "spl_qn_pathVectorStep_Long",
    value: "1500",
    flags: 4,
    description: "Long Dist from start to get forward vector",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__spl_qn_pathVectorStep_Long__);
}


// ========================================================================
// `dynamic initializer for 'spl_qn_pathVectorStep_Long_Max''
// EA  : 0x833788B8
// RVA : 0x013788B8
// PDB : w:\tech5\tungsten\game\entities\splines\navspline.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__spl_qn_pathVectorStep_Long_Max__()
{
  idCVar::idCVar(
    this: &spl_qn_pathVectorStep_Long_Max,
    name: "spl_qn_pathVectorStep_Long_Max",
    value: "3500",
    flags: 4,
    description: "Long Dist from start to get forward vector",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__spl_qn_pathVectorStep_Long_Max__);
}


// ========================================================================
// `dynamic initializer for 'spl_qn_pathVectorStep_VeryLong''
// EA  : 0x83378910
// RVA : 0x01378910
// PDB : w:\tech5\tungsten\game\entities\splines\navspline.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__spl_qn_pathVectorStep_VeryLong__()
{
  idCVar::idCVar(
    this: &spl_qn_pathVectorStep_VeryLong,
    name: "spl_qn_pathVectorStep_VeryLong",
    value: "5000",
    flags: 4,
    description: "Long Dist from start to get forward vector",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__spl_qn_pathVectorStep_VeryLong__);
}


// ========================================================================
// `dynamic initializer for 'spl_qn_pathVectorStep_VeryLong_Max''
// EA  : 0x83378968
// RVA : 0x01378968
// PDB : w:\tech5\tungsten\game\entities\splines\navspline.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__spl_qn_pathVectorStep_VeryLong_Max__()
{
  idCVar::idCVar(
    this: &spl_qn_pathVectorStep_VeryLong_Max,
    name: "spl_qn_pathVectorStep_VeryLong_Max",
    value: "7500",
    flags: 4,
    description: "Long Dist from start to get forward vector",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__spl_qn_pathVectorStep_VeryLong_Max__);
}


// ========================================================================
// `dynamic initializer for 'spl_qn_pathVectorStep_Override''
// EA  : 0x833789C0
// RVA : 0x013789C0
// PDB : w:\tech5\tungsten\game\entities\splines\navspline.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__spl_qn_pathVectorStep_Override__()
{
  idCVar::idCVar(
    this: &spl_qn_pathVectorStep_Override,
    name: "spl_qn_pathVectorStep_Override",
    value: "1500",
    flags: 4,
    description: "Over ride Dist from start to get forward vector",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__spl_qn_pathVectorStep_Override__);
}


// ========================================================================
// `dynamic initializer for 'spl_qn_pathVectorStep_Should_Override''
// EA  : 0x83378A18
// RVA : 0x01378A18
// PDB : w:\tech5\tungsten\game\entities\splines\navspline.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__spl_qn_pathVectorStep_Should_Override__()
{
  idCVar::idCVar(
    this: &spl_qn_pathVectorStep_Should_Override,
    name: "spl_qn_pathVectorStep_Should_Override",
    value: "0",
    flags: 2,
    description: "<= 0 no override, 1 short override, 2 medium override, 3 long override, >= 4 cvar override",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__spl_qn_pathVectorStep_Should_Override__);
}


// ========================================================================
// `dynamic initializer for 'spl_qn_searchMult''
// EA  : 0x83378A70
// RVA : 0x01378A70
// PDB : w:\tech5\tungsten\game\entities\splines\navspline.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__spl_qn_searchMult__()
{
  idCVar::idCVar(
    this: &spl_qn_searchMult,
    name: "spl_qn_searchMult",
    value: "2",
    flags: 4,
    description: "scales spline width by this value -- used as search distance",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__spl_qn_searchMult__);
}

