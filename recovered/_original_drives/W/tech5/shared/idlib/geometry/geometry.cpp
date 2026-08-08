
// ========================================================================
// ?PositionOnLineSegment@idGeometry@@SAMABVidVec3@@00@Z
// EA  : 0x82F1EE50
// RVA : 0x00F1EE50
// PDB : w:\tech5\shared\idlib\geometry\geometry.cpp
// ========================================================================

float __fastcall idGeometry::PositionOnLineSegment(const idVec3 *point, const idVec3 *start, const idVec3 *end)
{
  double v3; // fp0
  double v4; // fp13
  double v5; // fp1

  v3 = (float)(end->y - start->y);
  v4 = (float)(end->z - start->z);
  if ( (float)((float)((float)(end->x - start->x) * (float)(end->x - start->x))
             + (float)((float)((float)v4 * (float)v4) + (float)((float)v3 * (float)v3))) >= (double)idMath::FLT_SMALLEST_NON_DENORMAL )
    v5 = (float)((float)((float)((float)(point->x - start->x) * (float)(end->x - start->x))
                       + (float)((float)((float)(point->z - start->z) * (float)(end->z - start->z))
                               + (float)((float)(point->y - start->y) * (float)(end->y - start->y))))
               / (float)((float)((float)(end->x - start->x) * (float)(end->x - start->x))
                       + (float)((float)((float)v4 * (float)v4) + (float)((float)v3 * (float)v3))));
  else
    v5 = 0.0;
  return *((float *)&v5 + 1);
}


// ========================================================================
// ?ClosestPointOnLineSegment@idGeometry@@SA_NABVidVec3@@00AAV2@@Z
// EA  : 0x82F1EEC8
// RVA : 0x00F1EEC8
// PDB : w:\tech5\shared\idlib\geometry\geometry.cpp
// ========================================================================

int __fastcall idGeometry::ClosestPointOnLineSegment(
        const idVec3 *point,
        const idVec3 *start,
        const idVec3 *end,
        idVec3 *closest)
{
  double z; // fp8
  double x; // fp7
  double v6; // fp13
  double v7; // fp12
  double v8; // fp11
  double v10; // fp10
  double v11; // fp12

  closest->x = 0.0;
  closest->z = 0.0;
  closest->y = 0.0;
  z = start->z;
  x = start->x;
  v6 = (float)(end->y - start->y);
  v7 = (float)(end->z - start->z);
  v8 = (float)(end->x - start->x);
  if ( (float)((float)((float)(end->x - start->x) * (float)(end->x - start->x))
             + (float)((float)((float)v7 * (float)v7) + (float)((float)v6 * (float)v6))) >= (double)idMath::FLT_SMALLEST_NON_DENORMAL )
  {
    v10 = (float)((float)((float)((float)(point->x - start->x) * (float)(end->x - start->x))
                        + (float)((float)((float)(point->z - start->z) * (float)(end->z - start->z))
                                + (float)((float)(point->y - start->y) * (float)(end->y - start->y))))
                / (float)((float)((float)(end->x - start->x) * (float)(end->x - start->x))
                        + (float)((float)((float)v7 * (float)v7) + (float)((float)v6 * (float)v6))));
    if ( v10 >= 0.0 )
    {
      if ( v10 <= 1.0 )
      {
        v11 = (float)((float)(end->z - start->z)
                    * (float)((float)((float)((float)(point->x - start->x) * (float)(end->x - start->x))
                                    + (float)((float)((float)(point->z - start->z) * (float)(end->z - start->z))
                                            + (float)((float)(point->y - start->y) * (float)(end->y - start->y))))
                            / (float)((float)((float)(end->x - start->x) * (float)(end->x - start->x))
                                    + (float)((float)((float)v7 * (float)v7) + (float)((float)v6 * (float)v6)))));
        closest->y = start->y + (float)((float)(end->y - start->y) * (float)v10);
        closest->x = (float)x + (float)((float)v8 * (float)v10);
        closest->z = (float)z + (float)v11;
        return 1;
      }
      if ( v10 >= 0.0 )
      {
        *closest = *end;
        return 0;
      }
    }
  }
  *closest = *start;
  return 0;
}


// ========================================================================
// ?ClosestPointOnLine@idGeometry@@SAXABVidVec3@@00AAV2@@Z
// EA  : 0x82F1EFC8
// RVA : 0x00F1EFC8
// PDB : w:\tech5\shared\idlib\geometry\geometry.cpp
// ========================================================================

void __fastcall idGeometry::ClosestPointOnLine(
        const idVec3 *point,
        const idVec3 *start,
        const idVec3 *dir,
        idVec3 *closest)
{
  double z; // fp11
  double y; // fp8
  double v6; // fp10
  double v7; // fp6
  float back_chain; // [sp+4h] [-Ch]
  float v9; // [sp+8h] [-8h]

  z = start->z;
  y = start->y;
  back_chain = dir->y;
  v9 = dir->z;
  v6 = (float)((float)((float)(point->x - start->x) * dir->x)
             + (float)((float)((float)(point->y - start->y) * back_chain) + (float)((float)(point->z - start->z) * v9)));
  v7 = (float)(v9
             * (float)((float)((float)(point->x - start->x) * dir->x)
                     + (float)((float)((float)(point->y - start->y) * back_chain)
                             + (float)((float)(point->z - start->z) * v9))));
  closest->x = start->x
             + (float)(dir->x
                     * (float)((float)((float)(point->x - start->x) * dir->x)
                             + (float)((float)((float)(point->y - start->y) * back_chain)
                                     + (float)((float)(point->z - start->z) * v9))));
  closest->y = (float)y + (float)(back_chain * (float)v6);
  closest->z = (float)z + (float)v7;
}


// ========================================================================
// ?TriangleNormal@idGeometry@@SA?AVidVec3@@ABV2@00@Z
// EA  : 0x82F1F048
// RVA : 0x00F1F048
// PDB : w:\tech5\shared\idlib\geometry\geometry.cpp
// ========================================================================

idVec3 *__fastcall idGeometry::TriangleNormal(idVec3 *result, const idVec3 *a, const idVec3 *b, const idVec3 *c)
{
  double v4; // fp5
  double v5; // fp4
  double v6; // fp3
  double v9; // fp7
  double v10; // fp10
  double v11; // fp7

  v4 = (float)((float)((float)(c->z - a->z) * (float)(b->x - a->x))
             - (float)((float)(c->x - a->x) * (float)(b->z - a->z)));
  v5 = (float)((float)((float)(c->x - a->x) * (float)(b->y - a->y))
             - (float)((float)(c->y - a->y) * (float)(b->x - a->x)));
  v6 = (float)((float)((float)(c->y - a->y) * (float)(b->z - a->z))
             - (float)((float)(c->z - a->z) * (float)(b->y - a->y)));
  _FP10 = (float)((float)((float)((float)v6 * (float)v6)
                        + (float)((float)((float)v5 * (float)v5) + (float)((float)v4 * (float)v4)))
                - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f8, f10, f11, f13 }
  v9 = __frsqrte(_FP8);
  v10 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v9
                                                                                      * (float)((float)((float)((float)v6 * (float)v6) + (float)((float)((float)v5 * (float)v5) + (float)((float)v4 * (float)v4)))
                                                                                              * (float)0.5))
                                                                              * (float)v9)
                                                                      - (float)1.5)
                                                      * (float)v9)
                                              * (float)((float)((float)((float)v6 * (float)v6)
                                                              + (float)((float)((float)v5 * (float)v5)
                                                                      + (float)((float)v4 * (float)v4)))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v9
                                                                              * (float)((float)((float)((float)v6 * (float)v6)
                                                                                              + (float)((float)((float)v5 * (float)v5) + (float)((float)v4 * (float)v4)))
                                                                                      * (float)0.5))
                                                                      * (float)v9)
                                                              - (float)1.5)
                                              * (float)v9))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v9
                                                      * (float)((float)((float)((float)v6 * (float)v6)
                                                                      + (float)((float)((float)v5 * (float)v5)
                                                                              + (float)((float)v4 * (float)v4)))
                                                              * (float)0.5))
                                              * (float)v9)
                                      - (float)1.5)
                      * (float)v9));
  v11 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v9 * (float)((float)((float)((float)v6 * (float)v6) + (float)((float)((float)v5 * (float)v5) + (float)((float)v4 * (float)v4))) * (float)0.5)) * (float)v9) - (float)1.5)
                                                                                              * (float)v9)
                                                                                      * (float)((float)((float)((float)v6 * (float)v6) + (float)((float)((float)v5 * (float)v5) + (float)((float)v4 * (float)v4)))
                                                                                              * (float)0.5))
                                                                              * (float)((float)-(float)((float)((float)((float)v9 * (float)((float)((float)((float)v6 * (float)v6) + (float)((float)((float)v5 * (float)v5) + (float)((float)v4 * (float)v4))) * (float)0.5)) * (float)v9) - (float)1.5)
                                                                                      * (float)v9))
                                                                      - (float)1.5)
                                                      * (float)((float)-(float)((float)((float)((float)v9
                                                                                              * (float)((float)((float)((float)v6 * (float)v6) + (float)((float)((float)v5 * (float)v5) + (float)((float)v4 * (float)v4))) * (float)0.5))
                                                                                      * (float)v9)
                                                                              - (float)1.5)
                                                              * (float)v9))
                                              * (float)((float)((float)((float)v6 * (float)v6)
                                                              + (float)((float)((float)v5 * (float)v5)
                                                                      + (float)((float)v4 * (float)v4)))
                                                      * (float)0.5))
                                      * (float)v10)
                              - (float)1.5)
              * (float)v10);
  result->x = (float)((float)((float)(c->y - a->y) * (float)(b->z - a->z))
                    - (float)((float)(c->z - a->z) * (float)(b->y - a->y)))
            * (float)v11;
  result->y = (float)v4 * (float)v11;
  result->z = (float)v5 * (float)v11;
  return result;
}


// ========================================================================
// ?IntersectRayWithLineSegment2D@idGeometry@@SA_NABVidVec2@@000AAM@Z
// EA  : 0x82F1F118
// RVA : 0x00F1F118
// PDB : w:\tech5\shared\idlib\geometry\geometry.cpp
// ========================================================================

int __fastcall idGeometry::IntersectRayWithLineSegment2D(
        const idVec2 *rayStart,
        const idVec2 *rayDir,
        const idVec2 *segStart,
        const idVec2 *segEnd,
        float *dist)
{
  double v5; // fp13
  double v6; // fp12
  double v7; // fp0
  double v8; // fp11
  double v9; // fp11
  unsigned __int8 v10; // r11
  double v12; // fp6
  double v15; // fp5
  double v16; // fp3
  double v17; // fp0
  double v18; // fp13
  double v19; // fp7
  double v20; // fp12
  double v21; // fp11
  double v22; // fp10
  double v23; // fp0

  v5 = (float)(segEnd->x - segStart->x);
  v6 = (float)(segEnd->y - segStart->y);
  v7 = (float)((float)(rayDir->x * (float)(segEnd->y - segStart->y))
             - (float)(rayDir->y * (float)(segEnd->x - segStart->x)));
  if ( (float)((float)v7 * (float)v7) > 0.000099999997 )
  {
    v8 = (float)((float)((float)(rayDir->y * (float)(segStart->x - rayStart->x))
                       - (float)(rayDir->x * (float)(segStart->y - rayStart->y)))
               * (float)((float)1.0
                       / (float)((float)(rayDir->x * (float)(segEnd->y - segStart->y))
                               - (float)(rayDir->y * (float)(segEnd->x - segStart->x)))));
    if ( v8 >= 0.0 && v8 <= 1.0 )
    {
      v9 = (float)((float)((float)((float)(segStart->x - rayStart->x) * (float)(segEnd->y - segStart->y))
                         - (float)((float)(segStart->y - rayStart->y) * (float)(segEnd->x - segStart->x)))
                 * (float)((float)1.0
                         / (float)((float)(rayDir->x * (float)(segEnd->y - segStart->y))
                                 - (float)(rayDir->y * (float)(segEnd->x - segStart->x)))));
      *dist = (float)((float)((float)(segStart->x - rayStart->x) * (float)(segEnd->y - segStart->y))
                    - (float)((float)(segStart->y - rayStart->y) * (float)(segEnd->x - segStart->x)))
            * (float)((float)1.0
                    / (float)((float)(rayDir->x * (float)(segEnd->y - segStart->y))
                            - (float)(rayDir->y * (float)(segEnd->x - segStart->x))));
      return v9 >= 0.0;
    }
    return 0;
  }
  v12 = (float)((float)(rayDir->y * (float)(segStart->x - rayStart->x))
              - (float)(rayDir->x * (float)(segStart->y - rayStart->y)));
  if ( (float)((float)v12 * (float)v12) > 0.000099999997 )
    return 0;
  _FP2 = (float)((float)((float)((float)(segEnd->x - segStart->x) * (float)(segEnd->x - segStart->x))
                       + (float)((float)v6 * (float)v6))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f9, f2, f3, f9 }
  v15 = __frsqrte(_FP9);
  v16 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v15
                                                                                      * (float)((float)((float)((float)v5 * (float)v5) + (float)((float)v6 * (float)v6))
                                                                                              * (float)0.5))
                                                                              * (float)v15)
                                                                      - (float)1.5)
                                                      * (float)v15)
                                              * (float)((float)((float)((float)v5 * (float)v5)
                                                              + (float)((float)v6 * (float)v6))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v15
                                                                              * (float)((float)((float)((float)v5 * (float)v5)
                                                                                              + (float)((float)v6 * (float)v6))
                                                                                      * (float)0.5))
                                                                      * (float)v15)
                                                              - (float)1.5)
                                              * (float)v15))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v15
                                                      * (float)((float)((float)((float)v5 * (float)v5)
                                                                      + (float)((float)v6 * (float)v6))
                                                              * (float)0.5))
                                              * (float)v15)
                                      - (float)1.5)
                      * (float)v15));
  v17 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v15 * (float)((float)((float)((float)v5 * (float)v5) + (float)((float)v6 * (float)v6)) * (float)0.5)) * (float)v15) - (float)1.5) * (float)v15)
                                                                                              * (float)((float)((float)((float)v5 * (float)v5) + (float)((float)v6 * (float)v6)) * (float)0.5))
                                                                                      * (float)((float)-(float)((float)((float)((float)v15 * (float)((float)((float)((float)v5 * (float)v5) + (float)((float)v6 * (float)v6)) * (float)0.5)) * (float)v15) - (float)1.5)
                                                                                              * (float)v15))
                                                                              - (float)1.5)
                                                              * (float)((float)-(float)((float)((float)((float)v15 * (float)((float)((float)((float)v5 * (float)v5) + (float)((float)v6 * (float)v6)) * (float)0.5))
                                                                                              * (float)v15)
                                                                                      - (float)1.5)
                                                                      * (float)v15))
                                                      * (float)((float)((float)((float)v5 * (float)v5)
                                                                      + (float)((float)v6 * (float)v6))
                                                              * (float)0.5))
                                              * (float)v16)
                                      - (float)1.5)
                      * (float)v16)
              * (float)v6);
  v19 = (float)((float)(segStart->y - rayStart->y)
              * (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v15 * (float)((float)((float)((float)v5 * (float)v5) + (float)((float)v6 * (float)v6)) * (float)0.5)) * (float)v15) - (float)1.5) * (float)v15) * (float)((float)((float)((float)v5 * (float)v5) + (float)((float)v6 * (float)v6)) * (float)0.5))
                                                                                              * (float)((float)-(float)((float)((float)((float)v15 * (float)((float)((float)((float)v5 * (float)v5) + (float)((float)v6 * (float)v6)) * (float)0.5)) * (float)v15) - (float)1.5) * (float)v15))
                                                                                      - (float)1.5)
                                                                      * (float)((float)-(float)((float)((float)((float)v15 * (float)((float)((float)((float)v5 * (float)v5) + (float)((float)v6 * (float)v6)) * (float)0.5)) * (float)v15)
                                                                                              - (float)1.5)
                                                                              * (float)v15))
                                                              * (float)((float)((float)((float)v5 * (float)v5)
                                                                              + (float)((float)v6 * (float)v6))
                                                                      * (float)0.5))
                                                      * (float)v16)
                                              - (float)1.5)
                              * (float)v16)
                      * (float)v6));
  v18 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v15 * (float)((float)((float)((float)v5 * (float)v5) + (float)((float)v6 * (float)v6)) * (float)0.5)) * (float)v15) - (float)1.5) * (float)v15)
                                                                                              * (float)((float)((float)((float)v5 * (float)v5) + (float)((float)v6 * (float)v6)) * (float)0.5))
                                                                                      * (float)((float)-(float)((float)((float)((float)v15 * (float)((float)((float)((float)v5 * (float)v5) + (float)((float)v6 * (float)v6)) * (float)0.5)) * (float)v15) - (float)1.5)
                                                                                              * (float)v15))
                                                                              - (float)1.5)
                                                              * (float)((float)-(float)((float)((float)((float)v15 * (float)((float)((float)((float)v5 * (float)v5) + (float)((float)v6 * (float)v6)) * (float)0.5))
                                                                                              * (float)v15)
                                                                                      - (float)1.5)
                                                                      * (float)v15))
                                                      * (float)((float)((float)((float)v5 * (float)v5)
                                                                      + (float)((float)v6 * (float)v6))
                                                              * (float)0.5))
                                              * (float)v16)
                                      - (float)1.5)
                      * (float)v16)
              * (float)v5);
  v20 = (float)((float)((float)(segStart->x - rayStart->x) * (float)v18) + (float)v19);
  v21 = (float)((float)(rayDir->y * (float)v17) + (float)(rayDir->x * (float)v18));
  if ( v20 < 0.0 )
  {
    if ( v21 <= 0.0 )
      return 0;
LABEL_15:
    *dist = (float)((float)(segStart->x - rayStart->x) * (float)v18) + (float)v19;
    return 1;
  }
  v22 = (float)((float)v20 * (float)v20);
  v23 = (float)((float)((float)v18 * (float)v18) + (float)((float)v17 * (float)v17));
  if ( v21 <= 0.0 )
  {
    if ( v22 >= v23 )
    {
      *dist = __fsqrts(v23);
      return 1;
    }
    goto LABEL_15;
  }
  *dist = (float)((float)(segStart->x - rayStart->x) * (float)v18) + (float)v19;
  v10 = 1;
  if ( v22 <= v23 )
    return v10;
  return 0;
}


// ========================================================================
// ?SquarePointLineSegmentDistance@idGeometry@@SAMABVidVec3@@00@Z
// EA  : 0x82F1F2B8
// RVA : 0x00F1F2B8
// PDB : w:\tech5\shared\idlib\geometry\geometry.cpp
// ========================================================================

float __fastcall idGeometry::SquarePointLineSegmentDistance(
        const idVec3 *point,
        const idVec3 *start,
        const idVec3 *end)
{
  double v3; // fp13
  double v4; // fp11
  double v5; // fp12
  double v6; // fp8
  double v7; // fp1
  double v8; // fp9
  double v9; // fp8
  double v10; // fp0
  double v11; // fp13
  double v12; // fp11
  double v13; // fp4

  v3 = (float)(end->y - start->y);
  v4 = (float)(end->z - start->z);
  if ( (float)((float)((float)v4 * (float)v4)
             + (float)((float)((float)(end->x - start->x) * (float)(end->x - start->x)) + (float)((float)v3 * (float)v3))) >= 0.0099999998 )
  {
    v8 = (float)(point->z - start->z);
    v9 = (float)(point->y - start->y);
    v10 = (float)((float)((float)((float)(point->x - start->x) * (float)(end->x - start->x))
                        + (float)((float)((float)(point->y - start->y) * (float)(end->y - start->y))
                                + (float)((float)(point->z - start->z) * (float)(end->z - start->z))))
                / (float)((float)((float)v4 * (float)v4)
                        + (float)((float)((float)(end->x - start->x) * (float)(end->x - start->x))
                                + (float)((float)v3 * (float)v3))));
    if ( v10 >= 0.0 )
    {
      if ( v10 <= 1.0 )
      {
        v11 = (float)((float)(end->y - start->y)
                    * (float)((float)((float)((float)(point->x - start->x) * (float)(end->x - start->x))
                                    + (float)((float)((float)(point->y - start->y) * (float)(end->y - start->y))
                                            + (float)((float)(point->z - start->z) * (float)(end->z - start->z))))
                            / (float)((float)((float)v4 * (float)v4)
                                    + (float)((float)((float)(end->x - start->x) * (float)(end->x - start->x))
                                            + (float)((float)v3 * (float)v3)))));
        v12 = (float)((float)(end->z - start->z) * (float)v10);
        v13 = (float)((float)(point->x - start->x) - (float)((float)(end->x - start->x) * (float)v10));
        v7 = (float)((float)((float)v13 * (float)v13)
                   + (float)((float)((float)((float)v8 - (float)v12) * (float)((float)v8 - (float)v12))
                           + (float)((float)((float)v9 - (float)v11) * (float)((float)v9 - (float)v11))));
      }
      else
      {
        v7 = (float)((float)((float)(point->x - end->x) * (float)(point->x - end->x))
                   + (float)((float)((float)(point->z - end->z) * (float)(point->z - end->z))
                           + (float)((float)(point->y - end->y) * (float)(point->y - end->y))));
      }
    }
    else
    {
      v7 = (float)((float)((float)(point->x - start->x) * (float)(point->x - start->x))
                 + (float)((float)((float)v8 * (float)v8) + (float)((float)v9 * (float)v9)));
    }
  }
  else
  {
    v5 = (float)(point->z - start->z);
    v6 = (float)(point->y - start->y);
    v7 = (float)((float)((float)v6 * (float)v6)
               + (float)((float)((float)(point->x - start->x) * (float)(point->x - start->x))
                       + (float)((float)v5 * (float)v5)));
  }
  return *((float *)&v7 + 1);
}


// ========================================================================
// ?SegmentSegmentClosestPoints@idGeometry@@SAXABVidVec3@@000AAV2@1AAM2_N@Z
// EA  : 0x82F1F3D0
// RVA : 0x00F1F3D0
// PDB : w:\tech5\shared\idlib\geometry\geometry.cpp
// ========================================================================

void __fastcall idGeometry::SegmentSegmentClosestPoints(
        const idVec3 *start1,
        const idVec3 *end1,
        const idVec3 *start2,
        const idVec3 *end2,
        idVec3 *out1,
        idVec3 *out2,
        float *t1,
        float *t2,
        bool clampTValues,
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
        char a28)
{
  double v28; // fp4
  double v29; // fp3
  double v30; // fp0
  double v31; // fp13
  double v32; // fp5
  double v33; // fp9
  double v34; // fp12
  double v35; // fp10
  double v36; // fp31
  double v37; // fp2
  double v38; // fp1
  double v39; // fp11
  double v40; // fp11
  double v41; // fp8
  double x; // fp7
  double v43; // fp6
  double y; // fp2
  double v45; // fp11
  double z; // fp7
  double v47; // fp8
  double v48; // fp6

  v28 = (float)(end2->y - start2->y);
  v29 = (float)(end2->z - start2->z);
  v30 = (float)(end1->y - start1->y);
  v31 = (float)(end1->z - start1->z);
  v32 = (float)(end2->x - start2->x);
  v33 = idMath::FLT_SMALLEST_NON_DENORMAL;
  v34 = (float)(end1->x - start1->x);
  v35 = (float)((float)((float)(end2->x - start2->x) * (float)(end2->x - start2->x))
              + (float)((float)((float)v29 * (float)v29) + (float)((float)v28 * (float)v28)));
  v36 = (float)((float)((float)(end2->x - start2->x) * (float)(start1->x - start2->x))
              + (float)((float)((float)(end2->z - start2->z) * (float)(start1->z - start2->z))
                      + (float)((float)(end2->y - start2->y) * (float)(start1->y - start2->y))));
  v37 = (float)((float)((float)(end1->x - start1->x) * (float)(end2->x - start2->x))
              + (float)((float)((float)(end1->z - start1->z) * (float)(end2->z - start2->z))
                      + (float)((float)(end1->y - start1->y) * (float)(end2->y - start2->y))));
  if ( v35 < idMath::FLT_SMALLEST_NON_DENORMAL
    || (float)((float)((float)(end1->x - start1->x) * (float)(end1->x - start1->x))
             + (float)((float)((float)v31 * (float)v31) + (float)((float)v30 * (float)v30))) < v33
    || (v38 = (float)((float)((float)((float)((float)(end1->x - start1->x) * (float)(end1->x - start1->x))
                                    + (float)((float)((float)v31 * (float)v31) + (float)((float)v30 * (float)v30)))
                            * (float)((float)((float)(end2->x - start2->x) * (float)(end2->x - start2->x))
                                    + (float)((float)((float)v29 * (float)v29) + (float)((float)v28 * (float)v28))))
                    - (float)((float)v37 * (float)v37))) < v33 )
  {
    *out1 = *start1;
    *out2 = *start2;
    *t1 = 1.0;
    *t2 = 1.0;
  }
  else
  {
    v39 = (float)((float)((float)((float)((float)((float)(end1->x - start1->x) * (float)(end2->x - start2->x))
                                        + (float)((float)((float)(end1->z - start1->z) * (float)(end2->z - start2->z))
                                                + (float)((float)(end1->y - start1->y) * (float)(end2->y - start2->y))))
                                * (float)((float)((float)(end2->x - start2->x) * (float)(start1->x - start2->x))
                                        + (float)((float)((float)(end2->z - start2->z) * (float)(start1->z - start2->z))
                                                + (float)((float)(end2->y - start2->y) * (float)(start1->y - start2->y)))))
                        - (float)((float)((float)((float)(end1->x - start1->x) * (float)(start1->x - start2->x))
                                        + (float)((float)((float)(end1->z - start1->z) * (float)(start1->z - start2->z))
                                                + (float)((float)(end1->y - start1->y) * (float)(start1->y - start2->y))))
                                * (float)((float)((float)(end2->x - start2->x) * (float)(end2->x - start2->x))
                                        + (float)((float)((float)v29 * (float)v29) + (float)((float)v28 * (float)v28)))))
                / (float)v38);
    *t1 = (float)((float)((float)((float)((float)(end1->x - start1->x) * (float)(end2->x - start2->x))
                                + (float)((float)((float)(end1->z - start1->z) * (float)(end2->z - start2->z))
                                        + (float)((float)(end1->y - start1->y) * (float)(end2->y - start2->y))))
                        * (float)((float)((float)(end2->x - start2->x) * (float)(start1->x - start2->x))
                                + (float)((float)((float)(end2->z - start2->z) * (float)(start1->z - start2->z))
                                        + (float)((float)(end2->y - start2->y) * (float)(start1->y - start2->y)))))
                - (float)((float)((float)((float)(end1->x - start1->x) * (float)(start1->x - start2->x))
                                + (float)((float)((float)(end1->z - start1->z) * (float)(start1->z - start2->z))
                                        + (float)((float)(end1->y - start1->y) * (float)(start1->y - start2->y))))
                        * (float)((float)((float)(end2->x - start2->x) * (float)(end2->x - start2->x))
                                + (float)((float)((float)v29 * (float)v29) + (float)((float)v28 * (float)v28)))))
        / (float)v38;
    if ( a28 != 0 )
    {
      if ( v39 >= 0.0 )
      {
        if ( v39 > 1.0 )
          v39 = 1.0;
      }
      else
      {
        v39 = 0.0;
      }
      *t1 = v39;
    }
    v40 = (float)((float)((float)(*t1 * (float)v37) + (float)v36) / (float)v35);
    *t2 = (float)((float)(*t1 * (float)v37) + (float)v36) / (float)v35;
    if ( a28 != 0 )
    {
      if ( v40 >= 0.0 )
      {
        if ( v40 > 1.0 )
          v40 = 1.0;
      }
      else
      {
        v40 = 0.0;
      }
      *t2 = v40;
    }
    v41 = (float)(*t1 * (float)v34);
    x = start1->x;
    v43 = (float)((float)v30 * *t1);
    y = start1->y;
    out1->z = (float)((float)v31 * *t1) + start1->z;
    out1->x = (float)x + (float)v41;
    out1->y = (float)y + (float)v43;
    v45 = start2->y;
    z = start2->z;
    v47 = (float)((float)v28 * *t2);
    v48 = (float)((float)v29 * *t2);
    out2->x = start2->x + (float)(*t2 * (float)v32);
    out2->y = (float)v47 + (float)v45;
    out2->z = (float)z + (float)v48;
  }
}


// ========================================================================
// ?FindNearestPerpendicular@idGeometry@@SA?AVidVec3@@ABV2@00@Z
// EA  : 0x82F1F5D0
// RVA : 0x00F1F5D0
// PDB : w:\tech5\shared\idlib\geometry\geometry.cpp
// ========================================================================

idVec3 *__fastcall idGeometry::FindNearestPerpendicular(
        idVec3 *result,
        const idVec3 *input,
        const idVec3 *up,
        const idVec3 *hint)
{
  double x; // fp10
  double z; // fp11
  double y; // fp8
  double v7; // fp5
  double v8; // fp4
  double v9; // fp3
  double v10; // fp2
  double v11; // fp1
  double v12; // fp31
  double v13; // fp13
  double v14; // fp11
  double v15; // fp11
  double v16; // fp8
  double v19; // fp2
  double v20; // fp5
  double v21; // fp3
  double v22; // fp2

  x = input->x;
  z = up->z;
  y = input->y;
  v7 = (float)(up->x * input->y);
  v8 = up->y;
  v9 = hint->y;
  v10 = (float)(up->y * input->z);
  v11 = hint->z;
  v12 = hint->x;
  v13 = (float)((float)(up->x * input->z) - (float)(input->x * up->z));
  result->y = (float)(up->x * input->z) - (float)(input->x * up->z);
  result->z = (float)((float)x * (float)v8) - (float)v7;
  v14 = (float)((float)((float)z * (float)y) - (float)v10);
  result->x = v14;
  if ( (float)((float)((float)v14 * (float)v12)
             + (float)((float)((float)v11 * (float)((float)((float)x * (float)v8) - (float)v7))
                     + (float)((float)v9 * (float)v13))) < 0.0 )
  {
    result->x = (float)v14 * (float)-1.0;
    result->y = (float)v13 * (float)-1.0;
    result->z = (float)((float)((float)x * (float)v8) - (float)v7) * (float)-1.0;
  }
  v15 = result->y;
  v16 = result->z;
  _FP5 = (float)((float)((float)(result->z * result->z)
                       + (float)((float)(result->x * result->x) + (float)(result->y * result->y)))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f3, f5, f6, f13 }
  v19 = __frsqrte(_FP3);
  v20 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v19
                                                                                      * (float)((float)((float)(result->z * result->z) + (float)((float)(result->x * result->x) + (float)(result->y * result->y)))
                                                                                              * (float)0.5))
                                                                              * (float)v19)
                                                                      - (float)1.5)
                                                      * (float)v19)
                                              * (float)((float)((float)(result->z * result->z)
                                                              + (float)((float)(result->x * result->x)
                                                                      + (float)(result->y * result->y)))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v19
                                                                              * (float)((float)((float)(result->z * result->z)
                                                                                              + (float)((float)(result->x * result->x) + (float)(result->y * result->y)))
                                                                                      * (float)0.5))
                                                                      * (float)v19)
                                                              - (float)1.5)
                                              * (float)v19))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v19
                                                      * (float)((float)((float)(result->z * result->z)
                                                                      + (float)((float)(result->x * result->x)
                                                                              + (float)(result->y * result->y)))
                                                              * (float)0.5))
                                              * (float)v19)
                                      - (float)1.5)
                      * (float)v19));
  v21 = (float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v19 * (float)((float)((float)(result->z * result->z) + (float)((float)(result->x * result->x) + (float)(result->y * result->y))) * (float)0.5)) * (float)v19) - (float)1.5)
                                                                                      * (float)v19)
                                                                              * (float)((float)((float)(result->z * result->z)
                                                                                              + (float)((float)(result->x * result->x) + (float)(result->y * result->y)))
                                                                                      * (float)0.5))
                                                                      * (float)((float)-(float)((float)((float)((float)v19 * (float)((float)((float)(result->z * result->z) + (float)((float)(result->x * result->x) + (float)(result->y * result->y))) * (float)0.5)) * (float)v19)
                                                                                              - (float)1.5)
                                                                              * (float)v19))
                                                              - (float)1.5)
                                              * (float)((float)-(float)((float)((float)((float)v19
                                                                                      * (float)((float)((float)(result->z * result->z) + (float)((float)(result->x * result->x) + (float)(result->y * result->y)))
                                                                                              * (float)0.5))
                                                                              * (float)v19)
                                                                      - (float)1.5)
                                                      * (float)v19))
                                      * (float)((float)((float)(result->z * result->z)
                                                      + (float)((float)(result->x * result->x)
                                                              + (float)(result->y * result->y)))
                                              * (float)0.5))
                              * (float)v20)
                      - (float)1.5);
  v22 = (float)((float)v21
              * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v19
                                                                                              * (float)((float)((float)(result->z * result->z) + (float)((float)(result->x * result->x) + (float)(result->y * result->y))) * (float)0.5))
                                                                                      * (float)v19)
                                                                              - (float)1.5)
                                                              * (float)v19)
                                                      * (float)((float)((float)(result->z * result->z)
                                                                      + (float)((float)(result->x * result->x)
                                                                              + (float)(result->y * result->y)))
                                                              * (float)0.5))
                                              * (float)((float)-(float)((float)((float)((float)v19
                                                                                      * (float)((float)((float)(result->z * result->z) + (float)((float)(result->x * result->x) + (float)(result->y * result->y)))
                                                                                              * (float)0.5))
                                                                              * (float)v19)
                                                                      - (float)1.5)
                                                      * (float)v19))
                                      - (float)1.5)
                      * (float)((float)-(float)((float)((float)((float)v19
                                                              * (float)((float)((float)(result->z * result->z)
                                                                              + (float)((float)(result->x * result->x)
                                                                                      + (float)(result->y * result->y)))
                                                                      * (float)0.5))
                                                      * (float)v19)
                                              - (float)1.5)
                              * (float)v19)));
  result->x = result->x * (float)v22;
  result->y = (float)v15 * (float)v22;
  result->z = (float)v16 * (float)v22;
  return result;
}


// ========================================================================
// ?AreaOfTriangle@idGeometry@@SAMABVidVec3@@00@Z
// EA  : 0x82F1F6E0
// RVA : 0x00F1F6E0
// PDB : w:\tech5\shared\idlib\geometry\geometry.cpp
// ========================================================================

float __fastcall idGeometry::AreaOfTriangle(const idVec3 *a, const idVec3 *b, const idVec3 *c)
{
  double v3; // fp7
  double v4; // fp6
  double v5; // fp5
  double v6; // fp1

  v3 = (float)((float)((float)(b->x - a->x) * (float)(c->y - a->y))
             - (float)((float)(c->x - a->x) * (float)(b->y - a->y)));
  v4 = (float)((float)((float)(c->z - a->z) * (float)(b->y - a->y))
             - (float)((float)(c->y - a->y) * (float)(b->z - a->z)));
  v5 = (float)((float)((float)(c->x - a->x) * (float)(b->z - a->z))
             - (float)((float)(b->x - a->x) * (float)(c->z - a->z)));
  v6 = (float)((float)__fsqrts((float)((float)((float)v5 * (float)v5)
                                     + (float)((float)((float)v4 * (float)v4) + (float)((float)v3 * (float)v3))))
             * (float)0.5);
  return *((float *)&v6 + 1);
}

