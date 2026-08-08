
// ========================================================================
// ?PlaneIntersection@idPlane@@QBA_NABV1@AAVidVec3@@1@Z
// EA  : 0x82F38C88
// RVA : 0x00F38C88
// PDB : w:\tech5\shared\idlib\math\plane.cpp
// ========================================================================

int __fastcall idPlane::PlaneIntersection(idPlane *this, const idPlane *plane, idVec3 *start, idVec3 *dir)
{
  double a; // fp13
  double v5; // fp11
  double v6; // fp12
  double v7; // fp10
  double v8; // fp9
  double b; // fp7
  double c; // fp8
  double v12; // fp3
  double v13; // fp6
  double d; // fp31
  double v15; // fp2
  double v16; // fp1
  double v17; // fp9
  double v18; // fp2
  double v19; // fp4
  double v20; // fp13
  double v21; // fp1
  double v22; // fp2
  double v23; // fp10
  double v24; // fp9

  a = plane->a;
  v5 = (float)((float)(this->c * this->c) + (float)((float)(this->a * this->a) + (float)(this->b * this->b)));
  v6 = (float)((float)(plane->c * this->c) + (float)((float)(plane->a * this->a) + (float)(plane->b * this->b)));
  v7 = (float)((float)(plane->c * plane->c) + (float)((float)(plane->a * plane->a) + (float)(plane->b * plane->b)));
  v8 = v7 * v5 - v6 * v6;
  if ( __fabs((float)v8) < 0.000001 )
    return 0;
  b = this->b;
  c = plane->c;
  v12 = this->c;
  v13 = (float)(plane->c * this->a);
  d = this->d;
  v15 = (float)(this->c * plane->b);
  v16 = plane->d;
  v17 = 1.0 / v8;
  dir->z = (float)(plane->b * this->a) - (float)(this->b * plane->a);
  dir->y = (float)((float)v12 * (float)a) - (float)v13;
  dir->x = (float)((float)b * (float)c) - (float)v15;
  v18 = d * v6 - v16 * v5;
  v19 = (float)((v16 * v6 - d * v7) * v17);
  v20 = (float)(plane->a * (float)(v18 * v17));
  v21 = (float)(plane->b * (float)(v18 * v17));
  v22 = (float)(plane->c * (float)(v18 * v17));
  v23 = (float)((float)v19 * this->b);
  v24 = (float)((float)v19 * this->c);
  start->x = (float)(this->a * (float)v19) + (float)v20;
  start->y = (float)v23 + (float)v21;
  start->z = (float)v24 + (float)v22;
  return 1;
}


// ========================================================================
// ?ConvexPolytopeBounds@idPlane@@SA?AVidBounds@@PBV1@H@Z
// EA  : 0x82F38DC0
// RVA : 0x00F38DC0
// PDB : w:\tech5\shared\idlib\math\plane.cpp
// ========================================================================

idBounds *__fastcall idPlane::ConvexPolytopeBounds(idBounds *result, idPlane *planes, int numPlanes)
{
  int v6; // r30
  double v7; // fp30
  double v8; // fp29
  idPlane *v9; // r26
  int v10; // r27
  const idPlane *v11; // r4
  int v12; // r7
  const idPlane *v13; // r4
  double v14; // fp3
  double v15; // fp2
  int v16; // r9
  int v17; // r8
  float *v18; // r11
  double v19; // fp11
  char v20; // r10
  double v21; // fp11
  char v22; // r10
  double v23; // fp11
  char v24; // r10
  double v25; // fp11
  char v26; // r10
  double v27; // fp7
  double v28; // fp5
  double v29; // fp4
  float *p_b; // r11
  char v56; // r10
  float v57; // [sp+50h] [-B0h]
  idVec3 v58; // [sp+58h] [-A8h] BYREF
  idVec3 v59; // [sp+68h] [-98h] BYREF

  v6 = 0;
  result->b[0].z = 1.0e30;
  result->b[0].y = 1.0e30;
  result->b[0].x = 1.0e30;
  result->b[1].z = -1.0e30;
  result->b[1].y = -1.0e30;
  result->b[1].x = -1.0e30;
  if ( numPlanes > 0 )
  {
    v7 = v57;
    v8 = 1.0e30;
    v9 = planes;
    do
    {
      v10 = v6 + 1;
      if ( v6 + 1 >= numPlanes )
        goto LABEL_59;
      v11 = v9 + 1;
      do
      {
        if ( (unsigned __int8)idPlane::PlaneIntersection(this: v9, plane: v11, start: &v58, dir: &v59) == 0 )
          goto LABEL_58;
        v14 = -v8;
        v15 = v8;
        v16 = 0;
        if ( numPlanes < 4 )
        {
LABEL_67:
          if ( v16 < numPlanes )
          {
            p_b = &planes[v16].b;
            do
            {
              if ( v16 != v6 && v16 != v12 )
              {
                if ( (float)((float)((float)(p_b[1] * v59.z) + (float)(*p_b * v59.y)) + (float)(*(p_b - 1) * v59.x)) == 0.0 )
                {
                  v56 = 0;
                }
                else
                {
                  v56 = 1;
                  v7 = -(float)((float)((float)((float)(*p_b * v58.y)
                                              + (float)((float)(*(p_b - 1) * v58.x) + (float)(p_b[1] * v58.z)))
                                      + p_b[2])
                              / (float)((float)((float)(p_b[1] * v59.z) + (float)(*p_b * v59.y))
                                      + (float)(*(p_b - 1) * v59.x)));
                }
                if ( v56 != 0 )
                {
                  if ( (float)((float)((float)(*p_b * v59.y) + (float)(p_b[1] * v59.z)) + (float)(*(p_b - 1) * v59.x)) <= 0.0 )
                  {
                    if ( v7 > v14 )
                      v14 = v7;
                  }
                  else if ( v7 < v15 )
                  {
                    v15 = v7;
                  }
                }
                else if ( (float)((float)((float)(*(p_b - 1) * v58.x)
                                        + (float)((float)(*p_b * v58.y) + (float)(p_b[1] * v58.z)))
                                + p_b[2]) > 0.0 )
                {
                  goto LABEL_55;
                }
              }
              ++v16;
              p_b += 4;
            }
            while ( v16 < numPlanes );
          }
          goto LABEL_56;
        }
        v17 = 2;
        v18 = &planes[1].b;
        while ( 1 )
        {
          if ( v16 != v6 && v16 != v12 )
          {
            v19 = (float)((float)(*(v18 - 4) * v59.y)
                        + (float)((float)(*(v18 - 5) * v59.x) + (float)(*(v18 - 3) * v59.z)));
            if ( v19 == 0.0 )
            {
              v20 = 0;
            }
            else
            {
              v20 = 1;
              v7 = -(float)((float)((float)((float)(*(v18 - 3) * v58.z)
                                          + (float)((float)(*(v18 - 5) * v58.x) + (float)(*(v18 - 4) * v58.y)))
                                  + *(v18 - 2))
                          / (float)((float)(*(v18 - 4) * v59.y)
                                  + (float)((float)(*(v18 - 5) * v59.x) + (float)(*(v18 - 3) * v59.z))));
            }
            if ( v20 != 0 )
            {
              if ( v19 <= 0.0 )
              {
                if ( v7 > v14 )
                  v14 = v7;
              }
              else if ( v7 < v15 )
              {
                v15 = v7;
              }
            }
            else if ( (float)((float)((float)(*(v18 - 3) * v58.z)
                                    + (float)((float)(*(v18 - 5) * v58.x) + (float)(*(v18 - 4) * v58.y)))
                            + *(v18 - 2)) > 0.0 )
            {
              goto LABEL_55;
            }
          }
          if ( v17 - 1 != v6 && v17 - 1 != v12 )
          {
            v21 = (float)((float)(*v18 * v59.y) + (float)((float)(*(v18 - 1) * v59.x) + (float)(v18[1] * v59.z)));
            if ( v21 == 0.0 )
            {
              v22 = 0;
            }
            else
            {
              v22 = 1;
              v7 = -(float)((float)((float)((float)(*v18 * v58.y)
                                          + (float)((float)(*(v18 - 1) * v58.x) + (float)(v18[1] * v58.z)))
                                  + v18[2])
                          / (float)((float)(*v18 * v59.y)
                                  + (float)((float)(*(v18 - 1) * v59.x) + (float)(v18[1] * v59.z))));
            }
            if ( v22 != 0 )
            {
              if ( v21 <= 0.0 )
              {
                if ( v7 > v14 )
                  v14 = v7;
              }
              else if ( v7 < v15 )
              {
                v15 = v7;
              }
            }
            else if ( (float)((float)((float)(*v18 * v58.y)
                                    + (float)((float)(*(v18 - 1) * v58.x) + (float)(v18[1] * v58.z)))
                            + v18[2]) > 0.0 )
            {
              ++v16;
              goto LABEL_55;
            }
          }
          if ( v17 != v6 && v17 != v12 )
          {
            v23 = (float)((float)(v18[4] * v59.y) + (float)((float)(v18[3] * v59.x) + (float)(v18[5] * v59.z)));
            if ( v23 == 0.0 )
            {
              v24 = 0;
            }
            else
            {
              v24 = 1;
              v7 = -(float)((float)((float)((float)(v18[5] * v58.z)
                                          + (float)((float)(v18[3] * v58.x) + (float)(v18[4] * v58.y)))
                                  + v18[6])
                          / (float)((float)(v18[4] * v59.y) + (float)((float)(v18[3] * v59.x) + (float)(v18[5] * v59.z))));
            }
            if ( v24 != 0 )
            {
              if ( v23 <= 0.0 )
              {
                if ( v7 > v14 )
                  v14 = v7;
              }
              else if ( v7 < v15 )
              {
                v15 = v7;
              }
            }
            else if ( (float)((float)((float)(v18[5] * v58.z)
                                    + (float)((float)(v18[3] * v58.x) + (float)(v18[4] * v58.y)))
                            + v18[6]) > 0.0 )
            {
              v16 += 2;
              goto LABEL_55;
            }
          }
          if ( v17 + 1 != v6 && v17 + 1 != v12 )
          {
            v25 = (float)((float)(v18[8] * v59.y) + (float)((float)(v18[7] * v59.x) + (float)(v18[9] * v59.z)));
            if ( v25 == 0.0 )
            {
              v26 = 0;
            }
            else
            {
              v26 = 1;
              v7 = -(float)((float)((float)((float)(v18[9] * v58.z)
                                          + (float)((float)(v18[7] * v58.x) + (float)(v18[8] * v58.y)))
                                  + v18[10])
                          / (float)((float)(v18[8] * v59.y) + (float)((float)(v18[7] * v59.x) + (float)(v18[9] * v59.z))));
            }
            if ( v26 != 0 )
            {
              if ( v25 <= 0.0 )
              {
                if ( v7 > v14 )
                  v14 = v7;
              }
              else if ( v7 < v15 )
              {
                v15 = v7;
              }
              goto LABEL_66;
            }
            if ( (float)((float)((float)(v18[9] * v58.z) + (float)((float)(v18[7] * v58.x) + (float)(v18[8] * v58.y)))
                       + v18[10]) > 0.0 )
              break;
          }
LABEL_66:
          v16 += 4;
          v18 += 16;
          v17 += 4;
          if ( v16 >= numPlanes - 3 )
            goto LABEL_67;
        }
        v16 += 3;
LABEL_55:
        if ( v16 >= numPlanes )
        {
LABEL_56:
          if ( v14 < v15 )
          {
            v27 = (float)((float)(v59.x * (float)v15) + v58.x);
            v28 = (float)((float)(v59.y * (float)v15) + v58.y);
            v29 = (float)((float)(v59.z * (float)v15) + v58.z);
            _FP2 = (float)(result->b[0].x - (float)((float)(v59.x * (float)v14) + v58.x));
            _FP13 = (float)(result->b[0].y - (float)((float)(v59.y * (float)v14) + v58.y));
            _FP11 = (float)(result->b[0].z - (float)((float)(v59.z * (float)v14) + v58.z));
            _FP8 = (float)((float)((float)(v59.y * (float)v14) + v58.y) - result->b[1].y);
            _FP9 = (float)((float)((float)(v59.x * (float)v14) + v58.x) - result->b[1].x);
            _FP3 = (float)((float)((float)(v59.z * (float)v14) + v58.z) - result->b[1].z);
            __asm
            {
              fsel      f2, f2, f0, f6
              fsel      f1, f13, f12, f27
              fsel      f13, f11, f10, f26
              fsel      f11, f9, f0, f25
              fsel      f9, f8, f12, f29
              fsel      f8, f3, f10, f28
            }
            _FP6 = (float)((float)_FP2 - (float)v27);
            _FP3 = (float)((float)_FP1 - (float)v28);
            _FP0 = (float)((float)_FP13 - (float)v29);
            _FP12 = (float)((float)v27 - (float)_FP11);
            _FP10 = (float)((float)v28 - (float)_FP9);
            _FP29 = (float)((float)v29 - (float)_FP8);
            __asm { fsel      f6, f6, f7, f2 }
            result->b[0].x = _FP6;
            __asm { fsel      f3, f3, f5, f1 }
            result->b[0].y = _FP3;
            __asm { fsel      f2, f0, f4, f13 }
            result->b[0].z = _FP2;
            __asm { fsel      f1, f12, f7, f11 }
            result->b[1].x = _FP1;
            __asm { fsel      f0, f10, f5, f9 }
            result->b[1].y = _FP0;
            __asm { fsel      f13, f29, f4, f8 }
            result->b[1].z = _FP13;
            v8 = 1.0e30;
          }
        }
LABEL_58:
        v11 = v13 + 1;
      }
      while ( v12 + 1 < numPlanes );
LABEL_59:
      ++v6;
      ++v9;
    }
    while ( v10 < numPlanes );
  }
  return result;
}

