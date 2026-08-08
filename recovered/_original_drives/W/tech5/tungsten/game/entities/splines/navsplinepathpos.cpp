
// ========================================================================
// ?GetSplineWorldPos@idNavSplinePosition@@QBA?AVidVec3@@XZ
// EA  : 0x82CC3D40
// RVA : 0x00CC3D40
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathpos.cpp
// ========================================================================

idNavSplinePosition *__fastcall idNavSplinePosition::GetSplineWorldPos(idNavSplinePosition *this, idVec3 *result)
{
  float z; // r4
  idNavSplinePosition *v4; // r31

  z = result->z;
  v4 = this;
  if ( z == 0.0 )
  {
    *this = (idNavSplinePosition)vec3_origin;
  }
  else
  {
    idNavSpline::GetWorldPos((idNavSpline *)this, result: (idVec3 *)LODWORD(z), distance: result->x);
    return v4;
  }
  return this;
}


// ========================================================================
// ?GetSplineWidth@idNavSplinePosition@@QBAMM@Z
// EA  : 0x82CC3DB8
// RVA : 0x00CC3DB8
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathpos.cpp
// ========================================================================

double __fastcall idNavSplinePosition::GetSplineWidth(idNavSplinePosition *this, double dist)
{
  idNavSpline *navSpline; // r3

  if ( dist < 0.0 )
    dist = this->distance;
  navSpline = this->navSpline;
  if ( navSpline != nullptr )
    return idNavSpline::GetWidth(this: navSpline, distance: dist);
  else
    return 0.0;
}


// ========================================================================
// ?Validate@idNavSplinePosition@@QAAXPAVidNavSpline@@0@Z
// EA  : 0x82CC3DE8
// RVA : 0x00CC3DE8
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathpos.cpp
// ========================================================================

void __fastcall idNavSplinePosition::Validate(
        idNavSplinePosition *this,
        idNavSpline *nextSpline,
        idNavSpline *prevSpline)
{
  idNavSpline *navSpline; // r11
  double distance; // fp0
  double length; // fp13
  double v6; // fp0
  double v7; // fp13

  navSpline = this->navSpline;
  if ( navSpline != nullptr )
  {
    if ( nextSpline == nullptr && navSpline->bestNext != nullptr )
      nextSpline = navSpline->bestNext;
    if ( prevSpline == nullptr && navSpline->bestPrev != nullptr )
      prevSpline = navSpline->bestPrev;
    while ( 1 )
    {
      while ( 1 )
      {
        distance = this->distance;
        if ( distance >= 0.0 )
        {
          if ( distance <= navSpline->length )
            return;
          if ( distance >= 0.0 )
            break;
        }
        if ( prevSpline == nullptr )
        {
          this->distance = 0.0;
          return;
        }
        if ( prevSpline->startNode == navSpline->startNode )
        {
          navSpline = prevSpline;
          this->distance = -distance;
          this->navSpline = prevSpline;
        }
        else
        {
          length = prevSpline->length;
          this->navSpline = prevSpline;
          navSpline = prevSpline;
          this->distance = (float)length + (float)distance;
        }
        nextSpline = prevSpline->bestNext;
        prevSpline = prevSpline->bestPrev;
      }
      if ( nextSpline == nullptr )
        break;
      v6 = (float)(this->distance - navSpline->length);
      if ( nextSpline->endNode == navSpline->endNode )
      {
        v7 = nextSpline->length;
        this->navSpline = nextSpline;
        this->distance = (float)v7 - (float)v6;
        navSpline = nextSpline;
      }
      else
      {
        this->distance = this->distance - navSpline->length;
        navSpline = nextSpline;
        this->navSpline = nextSpline;
      }
      prevSpline = nextSpline->bestPrev;
      nextSpline = nextSpline->bestNext;
    }
    this->distance = navSpline->length;
  }
}


// ========================================================================
// ?GetWorldPositionAndForward@idNavSplinePosition@@QBAXAAVidVec3@@0@Z
// EA  : 0x82CC3F08
// RVA : 0x00CC3F08
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathpos.cpp
// ========================================================================

void __fastcall idNavSplinePosition::GetWorldPositionAndForward(
        idNavSplinePosition *this,
        idVec3 *pos,
        idVec3 *forward)
{
  idVec3 *navSpline; // r4
  double distance; // fp31
  float *WorldPos; // r3
  float *v9; // r3
  double v10; // fp7
  double v11; // fp5
  double v12; // fp3
  double v15; // fp6
  double v16; // fp10
  double v17; // fp6
  char v18; // [sp+50h] [-50h] BYREF
  char v19; // [sp+60h] [-40h] BYREF

  navSpline = (idVec3 *)this->navSpline;
  distance = (float)(navSpline[1].x - (float)1.0);
  if ( this->distance <= distance )
    distance = this->distance;
  WorldPos = (float *)idNavSpline::GetWorldPos(this: (idNavSpline *)&v18, result: navSpline, distance);
  pos->x = *WorldPos;
  pos->y = WorldPos[1];
  pos->z = WorldPos[2];
  v9 = (float *)idNavSpline::GetWorldPos(
                  this: (idNavSpline *)&v19,
                  result: (idVec3 *)this->navSpline,
                  distance: (float)((float)distance + (float)1.0));
  v10 = (float)(*v9 - pos->x);
  v11 = (float)(v9[2] - pos->z);
  v12 = (float)(v9[1] - pos->y);
  forward->y = v9[1] - pos->y;
  forward->x = v10;
  forward->z = v11;
  _FP10 = (float)((float)((float)((float)v12 * (float)v12)
                        + (float)((float)((float)v11 * (float)v11) + (float)((float)v10 * (float)v10)))
                - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f9, f10, f11, f13 }
  v15 = __frsqrte(_FP9);
  v16 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v15
                                                                                      * (float)((float)((float)((float)v12 * (float)v12) + (float)((float)((float)v11 * (float)v11) + (float)((float)v10 * (float)v10)))
                                                                                              * (float)0.5))
                                                                              * (float)v15)
                                                                      - (float)1.5)
                                                      * (float)v15)
                                              * (float)((float)((float)((float)v12 * (float)v12)
                                                              + (float)((float)((float)v11 * (float)v11)
                                                                      + (float)((float)v10 * (float)v10)))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v15
                                                                              * (float)((float)((float)((float)v12 * (float)v12)
                                                                                              + (float)((float)((float)v11 * (float)v11) + (float)((float)v10 * (float)v10)))
                                                                                      * (float)0.5))
                                                                      * (float)v15)
                                                              - (float)1.5)
                                              * (float)v15))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v15
                                                      * (float)((float)((float)((float)v12 * (float)v12)
                                                                      + (float)((float)((float)v11 * (float)v11)
                                                                              + (float)((float)v10 * (float)v10)))
                                                              * (float)0.5))
                                              * (float)v15)
                                      - (float)1.5)
                      * (float)v15));
  v17 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v15 * (float)((float)((float)((float)v12 * (float)v12) + (float)((float)((float)v11 * (float)v11) + (float)((float)v10 * (float)v10))) * (float)0.5)) * (float)v15) - (float)1.5)
                                                                                              * (float)v15)
                                                                                      * (float)((float)((float)((float)v12 * (float)v12) + (float)((float)((float)v11 * (float)v11) + (float)((float)v10 * (float)v10)))
                                                                                              * (float)0.5))
                                                                              * (float)((float)-(float)((float)((float)((float)v15 * (float)((float)((float)((float)v12 * (float)v12) + (float)((float)((float)v11 * (float)v11) + (float)((float)v10 * (float)v10))) * (float)0.5)) * (float)v15) - (float)1.5)
                                                                                      * (float)v15))
                                                                      - (float)1.5)
                                                      * (float)((float)-(float)((float)((float)((float)v15
                                                                                              * (float)((float)((float)((float)v12 * (float)v12) + (float)((float)((float)v11 * (float)v11) + (float)((float)v10 * (float)v10))) * (float)0.5))
                                                                                      * (float)v15)
                                                                              - (float)1.5)
                                                              * (float)v15))
                                              * (float)((float)((float)((float)v12 * (float)v12)
                                                              + (float)((float)((float)v11 * (float)v11)
                                                                      + (float)((float)v10 * (float)v10)))
                                                      * (float)0.5))
                                      * (float)v16)
                              - (float)1.5)
              * (float)v16);
  forward->x = (float)v10 * (float)v17;
  forward->y = (float)v17 * (float)v12;
  forward->z = (float)v11 * (float)v17;
}


// ========================================================================
// ?GetForward@idNavSplinePosition@@QBA?AVidVec3@@XZ
// EA  : 0x82CC4038
// RVA : 0x00CC4038
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathpos.cpp
// ========================================================================

idNavSplinePosition *__fastcall idNavSplinePosition::GetForward(idNavSplinePosition *this, idVec3 *result)
{
  float z; // r4
  double x; // fp31
  float *WorldPos; // r29
  float *v7; // r3
  double v9; // fp10
  double v10; // fp8
  double v11; // fp6
  double v14; // fp12
  double v15; // fp2
  double v16; // fp0
  double v17; // fp13
  char v18; // [sp+50h] [-50h] BYREF
  char v19; // [sp+60h] [-40h] BYREF

  z = result->z;
  x = (float)(*(float *)(LODWORD(z) + 12) - (float)1.0);
  if ( result->x <= x )
    x = result->x;
  WorldPos = (float *)idNavSpline::GetWorldPos(this: (idNavSpline *)&v18, result: (idVec3 *)LODWORD(z), distance: x);
  v7 = (float *)idNavSpline::GetWorldPos(
                  this: (idNavSpline *)&v19,
                  result: (idVec3 *)LODWORD(result->z),
                  distance: (float)((float)x + (float)1.0));
  v9 = (float)(v7[1] - WorldPos[1]);
  v10 = (float)(v7[2] - WorldPos[2]);
  v11 = (float)(*v7 - *WorldPos);
  _FP2 = (float)((float)((float)((float)(*v7 - *WorldPos) * (float)(*v7 - *WorldPos))
                       + (float)((float)((float)v10 * (float)v10) + (float)((float)v9 * (float)v9)))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f13, f2, f3, f13 }
  v14 = __frsqrte(_FP13);
  v15 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v14
                                                                                      * (float)((float)((float)((float)(*v7 - *WorldPos) * (float)(*v7 - *WorldPos)) + (float)((float)((float)v10 * (float)v10) + (float)((float)v9 * (float)v9)))
                                                                                              * (float)0.5))
                                                                              * (float)v14)
                                                                      - (float)1.5)
                                                      * (float)v14)
                                              * (float)((float)((float)((float)(*v7 - *WorldPos)
                                                                      * (float)(*v7 - *WorldPos))
                                                              + (float)((float)((float)v10 * (float)v10)
                                                                      + (float)((float)v9 * (float)v9)))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v14
                                                                              * (float)((float)((float)((float)(*v7 - *WorldPos) * (float)(*v7 - *WorldPos))
                                                                                              + (float)((float)((float)v10 * (float)v10) + (float)((float)v9 * (float)v9)))
                                                                                      * (float)0.5))
                                                                      * (float)v14)
                                                              - (float)1.5)
                                              * (float)v14))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v14
                                                      * (float)((float)((float)((float)(*v7 - *WorldPos)
                                                                              * (float)(*v7 - *WorldPos))
                                                                      + (float)((float)((float)v10 * (float)v10)
                                                                              + (float)((float)v9 * (float)v9)))
                                                              * (float)0.5))
                                              * (float)v14)
                                      - (float)1.5)
                      * (float)v14));
  v16 = (float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v14 * (float)((float)((float)((float)(*v7 - *WorldPos) * (float)(*v7 - *WorldPos)) + (float)((float)((float)v10 * (float)v10) + (float)((float)v9 * (float)v9))) * (float)0.5)) * (float)v14) - (float)1.5)
                                                                                      * (float)v14)
                                                                              * (float)((float)((float)((float)(*v7 - *WorldPos) * (float)(*v7 - *WorldPos))
                                                                                              + (float)((float)((float)v10 * (float)v10) + (float)((float)v9 * (float)v9)))
                                                                                      * (float)0.5))
                                                                      * (float)((float)-(float)((float)((float)((float)v14 * (float)((float)((float)((float)(*v7 - *WorldPos) * (float)(*v7 - *WorldPos)) + (float)((float)((float)v10 * (float)v10) + (float)((float)v9 * (float)v9))) * (float)0.5)) * (float)v14)
                                                                                              - (float)1.5)
                                                                              * (float)v14))
                                                              - (float)1.5)
                                              * (float)((float)-(float)((float)((float)((float)v14
                                                                                      * (float)((float)((float)((float)(*v7 - *WorldPos) * (float)(*v7 - *WorldPos)) + (float)((float)((float)v10 * (float)v10) + (float)((float)v9 * (float)v9)))
                                                                                              * (float)0.5))
                                                                              * (float)v14)
                                                                      - (float)1.5)
                                                      * (float)v14))
                                      * (float)((float)((float)((float)(*v7 - *WorldPos) * (float)(*v7 - *WorldPos))
                                                      + (float)((float)((float)v10 * (float)v10)
                                                              + (float)((float)v9 * (float)v9)))
                                              * (float)0.5))
                              * (float)v15)
                      - (float)1.5);
  v17 = (float)((float)v16
              * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v14
                                                                                              * (float)((float)((float)((float)(*v7 - *WorldPos) * (float)(*v7 - *WorldPos)) + (float)((float)((float)v10 * (float)v10) + (float)((float)v9 * (float)v9))) * (float)0.5))
                                                                                      * (float)v14)
                                                                              - (float)1.5)
                                                              * (float)v14)
                                                      * (float)((float)((float)((float)(*v7 - *WorldPos)
                                                                              * (float)(*v7 - *WorldPos))
                                                                      + (float)((float)((float)v10 * (float)v10)
                                                                              + (float)((float)v9 * (float)v9)))
                                                              * (float)0.5))
                                              * (float)((float)-(float)((float)((float)((float)v14
                                                                                      * (float)((float)((float)((float)(*v7 - *WorldPos) * (float)(*v7 - *WorldPos)) + (float)((float)((float)v10 * (float)v10) + (float)((float)v9 * (float)v9)))
                                                                                              * (float)0.5))
                                                                              * (float)v14)
                                                                      - (float)1.5)
                                                      * (float)v14))
                                      - (float)1.5)
                      * (float)((float)-(float)((float)((float)((float)v14
                                                              * (float)((float)((float)((float)(*v7 - *WorldPos)
                                                                                      * (float)(*v7 - *WorldPos))
                                                                              + (float)((float)((float)v10 * (float)v10)
                                                                                      + (float)((float)v9 * (float)v9)))
                                                                      * (float)0.5))
                                                      * (float)v14)
                                              - (float)1.5)
                              * (float)v14)));
  this->rightDistance = (float)v9
                      * (float)((float)v16
                              * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v14 * (float)((float)((float)((float)(*v7 - *WorldPos) * (float)(*v7 - *WorldPos)) + (float)((float)((float)v10 * (float)v10) + (float)((float)v9 * (float)v9))) * (float)0.5)) * (float)v14)
                                                                                              - (float)1.5)
                                                                              * (float)v14)
                                                                      * (float)((float)((float)((float)(*v7 - *WorldPos)
                                                                                              * (float)(*v7 - *WorldPos))
                                                                                      + (float)((float)((float)v10 * (float)v10)
                                                                                              + (float)((float)v9 * (float)v9)))
                                                                              * (float)0.5))
                                                              * (float)((float)-(float)((float)((float)((float)v14 * (float)((float)((float)((float)(*v7 - *WorldPos) * (float)(*v7 - *WorldPos)) + (float)((float)((float)v10 * (float)v10) + (float)((float)v9 * (float)v9))) * (float)0.5))
                                                                                              * (float)v14)
                                                                                      - (float)1.5)
                                                                      * (float)v14))
                                                      - (float)1.5)
                                      * (float)((float)-(float)((float)((float)((float)v14
                                                                              * (float)((float)((float)((float)(*v7 - *WorldPos) * (float)(*v7 - *WorldPos))
                                                                                              + (float)((float)((float)v10 * (float)v10) + (float)((float)v9 * (float)v9)))
                                                                                      * (float)0.5))
                                                                      * (float)v14)
                                                              - (float)1.5)
                                              * (float)v14)));
  this->distance = (float)v11 * (float)v17;
  *(float *)&this->navSpline = (float)v10 * (float)v17;
  return this;
}


// ========================================================================
// ?GetRight@idNavSplinePosition@@QBA?AVidVec3@@XZ
// EA  : 0x82CC4148
// RVA : 0x00CC4148
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathpos.cpp
// ========================================================================

idNavSplinePosition *__fastcall idNavSplinePosition::GetRight(idNavSplinePosition *this, idVec3 *result)
{
  double distance; // fp12
  double v5; // fp8
  double v6; // fp11
  idNavSplinePosition v7; // [sp+50h] [-20h] BYREF

  idNavSplinePosition::GetForward(this: &v7, result);
  distance = v7.distance;
  v5 = (float)(*(float *)&v7.navSpline * (float)0.0);
  v6 = (float)(v7.rightDistance * (float)0.0);
  this->distance = v7.rightDistance - (float)(*(float *)&v7.navSpline * (float)0.0);
  *(float *)&this->navSpline = (float)((float)distance * (float)0.0) - (float)v6;
  this->rightDistance = (float)v5 - (float)distance;
  return this;
}


// ========================================================================
// ?GetVectors@idNavSplinePosition@@QBAXAAVidVec3@@0@Z
// EA  : 0x82CC41B0
// RVA : 0x00CC41B0
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathpos.cpp
// ========================================================================

void __fastcall idNavSplinePosition::GetVectors(idNavSplinePosition *this, idVec3 *forward, idVec3 *right)
{
  float *v5; // r3
  double v6; // fp0
  double v7; // fp12
  double v8; // fp9
  idNavSplinePosition v9[2]; // [sp+50h] [-30h] BYREF

  v5 = (float *)idNavSplinePosition::GetForward(this: v9, result: (idVec3 *)this);
  v6 = *v5;
  forward->x = *v5;
  v7 = v5[1];
  forward->y = v5[1];
  v8 = (float)(v5[2] * (float)0.0);
  forward->z = v5[2];
  right->x = (float)v7 - (float)v8;
  right->y = (float)v8 - (float)v6;
  right->z = (float)((float)v6 * (float)0.0) - (float)((float)v7 * (float)0.0);
}


// ========================================================================
// ?GetWorldPos@idNavSplinePosition@@QBA?AVidVec3@@XZ
// EA  : 0x82CC4238
// RVA : 0x00CC4238
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathpos.cpp
// ========================================================================

idNavSplinePosition *__fastcall idNavSplinePosition::GetWorldPos(idNavSplinePosition *this, idVec3 *result)
{
  float z; // r4
  float x; // r9
  float y; // r8
  double v7; // fp31
  float *Right; // r3
  double v9; // fp6
  double v10; // fp4
  float v12; // [sp+50h] [-40h] BYREF
  float v13; // [sp+54h] [-3Ch]
  float v14; // [sp+58h] [-38h]
  idNavSplinePosition v15; // [sp+60h] [-30h] BYREF

  z = result->z;
  if ( z == 0.0 )
  {
    x = vec3_origin.x;
    y = vec3_origin.y;
    this->navSpline = (idNavSpline *)LODWORD(vec3_origin.z);
  }
  else
  {
    idNavSpline::GetWorldPos(this: (idNavSpline *)&v12, result: (idVec3 *)LODWORD(z), distance: result->x);
    v7 = result->y;
    Right = (float *)idNavSplinePosition::GetRight(this: &v15, result);
    v9 = (float)(Right[1] * (float)v7);
    v10 = (float)(v12 + (float)(*Right * (float)v7));
    v14 = v14 + (float)(Right[2] * (float)v7);
    v12 = v10;
    v13 = v13 + (float)v9;
    x = v12;
    y = v13;
    *(float *)&this->navSpline = v14;
  }
  this->distance = x;
  this->rightDistance = y;
  return this;
}


// ========================================================================
// ?Validate@idNavSplinePosition@@QAAXPAUnavSplinePath_t@@@Z
// EA  : 0x82CC4318
// RVA : 0x00CC4318
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathpos.cpp
// ========================================================================

void __fastcall idNavSplinePosition::Validate(idNavSplinePosition *this, navSplinePath_t *path)
{
  idNavSpline *navSpline; // r11
  double distance; // fp0
  double v4; // fp13
  double length; // fp12
  int v6; // r11
  int v7; // r10
  navSplinePath_t::path_t *list; // r9
  idNavSpline *v9; // r8
  double v10; // fp0
  idNavSpline *v11; // r8
  navSplinePath_t::path_t *v12; // r10
  double dir; // fp12

  navSpline = this->navSpline;
  if ( navSpline != nullptr && path != nullptr )
  {
    distance = this->distance;
    if ( distance < 0.0 || distance > navSpline->length )
    {
      v4 = 0.0;
      if ( distance >= 0.0 )
      {
        length = navSpline->length;
        if ( distance > length )
        {
          this->distance = navSpline->length;
          v4 = (float)((float)distance - (float)length);
        }
      }
      else
      {
        this->distance = 0.0;
        v4 = -distance;
      }
      v6 = 1;
      if ( path->path.num > 1 )
      {
        v7 = 1;
        while ( 1 )
        {
          list = path->path.list;
          if ( v4 < list[v7].navSpline->length )
            break;
          v9 = list[v7].navSpline;
          ++v6;
          ++v7;
          v10 = v9->length;
          this->navSpline = v9;
          v4 = (float)((float)v4 - (float)v10);
          if ( v6 >= path->path.num )
            goto LABEL_20;
        }
        v11 = list[v6].navSpline;
        this->navSpline = v11;
        v12 = &path->path.list[v6];
        if ( v6 >= path->path.num - 1 )
          dir = -v12->dir;
        else
          dir = v12->dir;
        if ( dir != 1.0 )
          v4 = (float)(v11->length - (float)v4);
        this->distance = v4;
      }
LABEL_20:
      if ( v6 == path->path.num )
      {
        if ( path->path.list[v6 - 1].dir >= 0.0 )
          this->distance = 0.0;
        else
          this->distance = this->navSpline->length;
      }
    }
  }
}


// ========================================================================
// ?Validate@idNavSplinePosition@@QAAXVidVec3@@@Z
// EA  : 0x82CC4460
// RVA : 0x00CC4460
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathpos.cpp
// ========================================================================

void __fastcall idNavSplinePosition::Validate(idNavSplinePosition *this, idVec3 *velocity)
{
  idNavSpline *navSpline; // r8
  double v5; // fp2
  double v6; // fp5
  double v7; // fp2
  double distance; // fp8
  double v9; // fp13
  idNavSpline *v10; // r6
  double v11; // fp12
  int v12; // r9
  int v13; // r10
  navSplineConnection_t *v14; // r11
  double v15; // fp0
  double v16; // fp0
  idNavSpline *v17; // r6
  int v18; // r9
  int v19; // r10
  navSplineConnection_t *v20; // r11
  double v21; // fp0
  double v22; // fp0
  double length; // fp13

  navSpline = this->navSpline;
  _FP5 = (float)((float)((float)(*(float *)&this * *(float *)&this)
                       + (float)((float)(*(float *)&velocity * *(float *)&velocity)
                               + (float)(*(float *)&velocity * *(float *)&velocity)))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f3, f5, f6, f12 }
  v5 = __frsqrte(_FP3);
  v6 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v5
                                                                                     * (float)((float)((float)(*(float *)&this * *(float *)&this) + (float)((float)(*(float *)&velocity * *(float *)&velocity) + (float)(*(float *)&velocity * *(float *)&velocity)))
                                                                                             * (float)0.5))
                                                                             * (float)v5)
                                                                     - (float)1.5)
                                                     * (float)v5)
                                             * (float)((float)((float)(*(float *)&this * *(float *)&this)
                                                             + (float)((float)(*(float *)&velocity * *(float *)&velocity)
                                                                     + (float)(*(float *)&velocity * *(float *)&velocity)))
                                                     * (float)0.5))
                                     * (float)((float)-(float)((float)((float)((float)v5
                                                                             * (float)((float)((float)(*(float *)&this * *(float *)&this)
                                                                                             + (float)((float)(*(float *)&velocity * *(float *)&velocity) + (float)(*(float *)&velocity * *(float *)&velocity)))
                                                                                     * (float)0.5))
                                                                     * (float)v5)
                                                             - (float)1.5)
                                             * (float)v5))
                             - (float)1.5)
             * (float)((float)-(float)((float)((float)((float)v5
                                                     * (float)((float)((float)(*(float *)&this * *(float *)&this)
                                                                     + (float)((float)(*(float *)&velocity
                                                                                     * *(float *)&velocity)
                                                                             + (float)(*(float *)&velocity
                                                                                     * *(float *)&velocity)))
                                                             * (float)0.5))
                                             * (float)v5)
                                     - (float)1.5)
                     * (float)v5));
  v7 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v5 * (float)((float)((float)(*(float *)&this * *(float *)&this) + (float)((float)(*(float *)&velocity * *(float *)&velocity) + (float)(*(float *)&velocity * *(float *)&velocity))) * (float)0.5)) * (float)v5) - (float)1.5)
                                                                                             * (float)v5)
                                                                                     * (float)((float)((float)(*(float *)&this * *(float *)&this) + (float)((float)(*(float *)&velocity * *(float *)&velocity) + (float)(*(float *)&velocity * *(float *)&velocity)))
                                                                                             * (float)0.5))
                                                                             * (float)((float)-(float)((float)((float)((float)v5 * (float)((float)((float)(*(float *)&this * *(float *)&this) + (float)((float)(*(float *)&velocity * *(float *)&velocity) + (float)(*(float *)&velocity * *(float *)&velocity))) * (float)0.5)) * (float)v5) - (float)1.5)
                                                                                     * (float)v5))
                                                                     - (float)1.5)
                                                     * (float)((float)-(float)((float)((float)((float)v5
                                                                                             * (float)((float)((float)(*(float *)&this * *(float *)&this) + (float)((float)(*(float *)&velocity * *(float *)&velocity) + (float)(*(float *)&velocity * *(float *)&velocity))) * (float)0.5))
                                                                                     * (float)v5)
                                                                             - (float)1.5)
                                                             * (float)v5))
                                             * (float)((float)((float)(*(float *)&this * *(float *)&this)
                                                             + (float)((float)(*(float *)&velocity * *(float *)&velocity)
                                                                     + (float)(*(float *)&velocity * *(float *)&velocity)))
                                                     * (float)0.5))
                                     * (float)v6)
                             - (float)1.5)
             * (float)v6);
  if ( navSpline != nullptr )
  {
    distance = this->distance;
    v9 = 0.0;
    if ( distance >= 0.0 )
    {
      if ( distance > navSpline->length )
      {
        v17 = nullptr;
        v18 = 0;
        if ( navSpline->next.num <= 0 )
          goto LABEL_23;
        v19 = 0;
        do
        {
          v20 = &navSpline->next.list[v19];
          v21 = __fabs((float)((float)(v20->forward.x * (float)(*(float *)&this * (float)v7))
                             + (float)((float)(v20->forward.y * (float)(*(float *)&velocity * (float)v7))
                                     + (float)(v20->forward.z * (float)(*(float *)&velocity * (float)v7)))));
          if ( v21 > v9 )
          {
            v17 = v20->navSpline;
            v9 = v21;
          }
          ++v18;
          ++v19;
        }
        while ( v18 < this->navSpline->next.num );
        if ( v17 != nullptr )
        {
          v22 = (float)(this->distance - navSpline->length);
          if ( v17->endNode == navSpline->endNode )
          {
            length = v17->length;
            this->navSpline = v17;
            this->distance = (float)length - (float)v22;
          }
          else
          {
            this->distance = this->distance - navSpline->length;
            this->navSpline = v17;
          }
        }
        else
        {
LABEL_23:
          this->distance = navSpline->length;
        }
      }
    }
    else
    {
      v10 = nullptr;
      v11 = 0.0;
      v12 = 0;
      if ( navSpline->prev.num <= 0 )
        goto LABEL_12;
      v13 = 0;
      do
      {
        v14 = &navSpline->prev.list[v13];
        v15 = __fabs((float)((float)(v14->forward.x * (float)(*(float *)&this * (float)v7))
                           + (float)((float)(v14->forward.y * (float)(*(float *)&velocity * (float)v7))
                                   + (float)(v14->forward.z * (float)(*(float *)&velocity * (float)v7)))));
        if ( v15 > v11 )
        {
          v10 = v14->navSpline;
          v11 = v15;
        }
        ++v12;
        ++v13;
      }
      while ( v12 < navSpline->prev.num );
      if ( v10 != nullptr )
      {
        if ( v10->startNode == navSpline->startNode )
        {
          this->distance = -distance;
          this->navSpline = v10;
        }
        else
        {
          v16 = v10->length;
          this->navSpline = v10;
          this->distance = (float)v16 + (float)distance;
        }
      }
      else
      {
LABEL_12:
        this->distance = 0.0;
      }
    }
    idNavSplinePosition::Validate(this, nextSpline: nullptr, prevSpline: nullptr);
  }
}


// ========================================================================
// ?MoveDelta@idNavSplinePosition@@QAAXMVidVec3@@@Z
// EA  : 0x82CC4680
// RVA : 0x00CC4680
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathpos.cpp
// ========================================================================

void __fastcall idNavSplinePosition::MoveDelta(idNavSplinePosition *this, double delta, idVec3 *velocity, idVec3 *a4)
{
  char v4; // r11

  this->distance = this->distance + (float)delta;
  if ( *(float *)&velocity != vec3_origin.x
    || *(float *)&a4 != vec3_origin.y
    || (v4 = 1, *(float *)&a4 != vec3_origin.z) )
  {
    v4 = 0;
  }
  if ( v4 != 0 )
    idNavSplinePosition::Validate(this, nextSpline: nullptr, prevSpline: nullptr);
  else
    idNavSplinePosition::Validate(this, velocity: a4);
}


// ========================================================================
// ?MoveDeltaRelativeToEntity@idNavSplinePosition@@QAAXMPAVidEntity@@@Z
// EA  : 0x82CC4728
// RVA : 0x00CC4728
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathpos.cpp
// ========================================================================

void __fastcall idNavSplinePosition::MoveDeltaRelativeToEntity(
        idNavSplinePosition *this,
        double delta,
        idEntity *ent,
        idEntity *a4)
{
  idPhysics *Physics; // r3
  float *v8; // r29
  float *Forward; // r3
  double v10; // fp13
  idPhysics *v11; // r3
  int v12; // r3
  idNavSplinePosition v13[2]; // [sp+50h] [-40h] BYREF

  if ( a4 != nullptr )
  {
    Physics = idEntity::GetPhysics(this: a4);
    v8 = (float *)Physics->GetAxis(this: Physics, a2: 0);
    Forward = (float *)idNavSplinePosition::GetForward(this: v13, result: (idVec3 *)this);
    if ( (float)((float)(*v8 * *Forward) + (float)((float)(v8[2] * Forward[2]) + (float)(v8[1] * Forward[1]))) <= 0.0 )
      v10 = (float)(this->distance - (float)delta);
    else
      v10 = (float)(this->distance + (float)delta);
    this->distance = v10;
    v11 = idEntity::GetPhysics(this: a4);
    v12 = (int)v11->GetLinearVelocity(this: (idPhysics *)v13, result: (idVec3 *)v11, a3: 0);
    idNavSplinePosition::Validate(this: *(idNavSplinePosition **)v12, velocity: *(idVec3 **)(v12 + 4));
  }
}


// ========================================================================
// ?IsOnDeadendPath@idNavSplinePosition@@QBA_NXZ
// EA  : 0x82CC4810
// RVA : 0x00CC4810
// PDB : w:\tech5\tungsten\game\entities\splines\navsplinepathpos.cpp
// ========================================================================

int __fastcall idNavSplinePosition::IsOnDeadendPath(idNavSplinePosition *this)
{
  idNavSpline *navSpline; // r11
  unsigned __int8 v3; // r11
  bool v4; // zf

  navSpline = this->navSpline;
  if ( navSpline->isTempSpline )
    return 0;
  if ( navSpline->next.num == 0 )
    return 1;
  v4 = navSpline->prev.num != 0;
  v3 = 0;
  if ( !v4 )
    return 1;
  return v3;
}

