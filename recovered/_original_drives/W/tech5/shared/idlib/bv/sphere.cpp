
// ========================================================================
// ?LineIntersection@idSphere@@QBA_NABVidVec3@@0@Z
// EA  : 0x82EFA658
// RVA : 0x00EFA658
// PDB : w:\tech5\shared\idlib\bv\sphere.cpp
// ========================================================================

BOOL __fastcall idSphere::LineIntersection(idSphere *this, const idVec3 *start, const idVec3 *end)
{
  double v3; // fp0
  double v4; // fp7
  double v5; // fp13
  double v6; // fp6
  double v7; // fp12
  double v8; // fp11
  double v9; // fp10
  double v10; // fp9
  double v11; // fp8
  double v13; // fp2
  double v14; // fp1
  double v15; // fp0

  v3 = (float)(start->y - this->origin.y);
  v5 = (float)(start->z - this->origin.z);
  v7 = (float)(start->x - this->origin.x);
  v8 = (float)((float)(end->y - this->origin.y) - (float)(start->y - this->origin.y));
  v9 = (float)((float)(end->z - this->origin.z) - (float)(start->z - this->origin.z));
  v10 = (float)((float)(end->x - this->origin.x) - (float)(start->x - this->origin.x));
  v11 = (float)((float)((float)-v7 * (float)((float)(end->x - this->origin.x) - (float)(start->x - this->origin.x)))
              + (float)((float)((float)-v5
                              * (float)((float)(end->z - this->origin.z) - (float)(start->z - this->origin.z)))
                      + (float)((float)-v3
                              * (float)((float)(end->y - this->origin.y) - (float)(start->y - this->origin.y)))));
  if ( v11 > 0.0 )
  {
    if ( v11 < (float)((float)((float)v10 * (float)v10)
                     + (float)((float)((float)v9 * (float)v9) + (float)((float)v8 * (float)v8))) )
    {
      v13 = (float)((float)((float)((float)(end->y - this->origin.y) - (float)(start->y - this->origin.y))
                          * (float)((float)((float)((float)-v7
                                                  * (float)((float)(end->x - this->origin.x)
                                                          - (float)(start->x - this->origin.x)))
                                          + (float)((float)((float)-v5
                                                          * (float)((float)(end->z - this->origin.z)
                                                                  - (float)(start->z - this->origin.z)))
                                                  + (float)((float)-v3
                                                          * (float)((float)(end->y - this->origin.y)
                                                                  - (float)(start->y - this->origin.y)))))
                                  / (float)((float)((float)v10 * (float)v10)
                                          + (float)((float)((float)v9 * (float)v9) + (float)((float)v8 * (float)v8)))))
                  + (float)(start->y - this->origin.y));
      v14 = (float)((float)((float)((float)(end->z - this->origin.z) - (float)(start->z - this->origin.z))
                          * (float)((float)((float)((float)-v7
                                                  * (float)((float)(end->x - this->origin.x)
                                                          - (float)(start->x - this->origin.x)))
                                          + (float)((float)((float)-v5
                                                          * (float)((float)(end->z - this->origin.z)
                                                                  - (float)(start->z - this->origin.z)))
                                                  + (float)((float)-v3
                                                          * (float)((float)(end->y - this->origin.y)
                                                                  - (float)(start->y - this->origin.y)))))
                                  / (float)((float)((float)v10 * (float)v10)
                                          + (float)((float)((float)v9 * (float)v9) + (float)((float)v8 * (float)v8)))))
                  + (float)(start->z - this->origin.z));
      v15 = (float)((float)((float)((float)(end->x - this->origin.x) - (float)(start->x - this->origin.x))
                          * (float)((float)((float)((float)-v7
                                                  * (float)((float)(end->x - this->origin.x)
                                                          - (float)(start->x - this->origin.x)))
                                          + (float)((float)((float)-v5
                                                          * (float)((float)(end->z - this->origin.z)
                                                                  - (float)(start->z - this->origin.z)))
                                                  + (float)((float)-v3
                                                          * (float)((float)(end->y - this->origin.y)
                                                                  - (float)(start->y - this->origin.y)))))
                                  / (float)((float)((float)v10 * (float)v10)
                                          + (float)((float)((float)v9 * (float)v9) + (float)((float)v8 * (float)v8)))))
                  + (float)(start->x - this->origin.x));
      return (float)((float)((float)v15 * (float)v15)
                   + (float)((float)((float)v14 * (float)v14) + (float)((float)v13 * (float)v13))) < (double)(float)(this->radius * this->radius);
    }
    else
    {
      v4 = (float)(end->y - this->origin.y);
      v6 = (float)(end->z - this->origin.z);
      return (float)((float)((float)(end->x - this->origin.x) * (float)(end->x - this->origin.x))
                   + (float)((float)((float)v6 * (float)v6) + (float)((float)v4 * (float)v4))) < (double)(float)(this->radius * this->radius);
    }
  }
  else
  {
    return (float)((float)((float)v5 * (float)v5)
                 + (float)((float)((float)v3 * (float)v3)
                         + (float)((float)(start->x - this->origin.x) * (float)(start->x - this->origin.x)))) < (double)(float)(this->radius * this->radius);
  }
}

