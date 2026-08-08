
// ========================================================================
// ?LerpToWithScale@@YAMMMM@Z
// EA  : 0x826F8C50
// RVA : 0x006F8C50
// PDB : w:\tech5\engine\gamelib\animstack\animweb\animwebutils.cpp
// ========================================================================

float __fastcall LerpToWithScale(double cur, double dest, double scale)
{
  double v3; // fp0
  double v4; // fp1

  v3 = (float)((float)dest - (float)cur);
  if ( v3 <= -0.000001 || v3 >= 0.000001 )
    v4 = (float)((float)((float)((float)dest - (float)cur) * (float)scale) + (float)cur);
  else
    v4 = dest;
  return *((float *)&v4 + 1);
}


// ========================================================================
// ?LerpToWithRate@@YAMMMM@Z
// EA  : 0x826F8D70
// RVA : 0x006F8D70
// PDB : w:\tech5\engine\gamelib\animstack\animweb\animwebutils.cpp
// ========================================================================

float __fastcall LerpToWithRate(double cur, double dest, double absRate)
{
  double v4; // fp1

  if ( cur >= dest )
  {
    if ( cur > dest )
    {
      v4 = (float)((float)cur - (float)absRate);
      if ( v4 < dest )
        goto LABEL_4;
      if ( v4 <= cur )
        return *((float *)&v4 + 1);
    }
LABEL_8:
    v4 = cur;
    return *((float *)&v4 + 1);
  }
  v4 = (float)((float)cur + (float)absRate);
  if ( v4 < cur )
    goto LABEL_8;
  if ( v4 > dest )
LABEL_4:
    v4 = dest;
  return *((float *)&v4 + 1);
}


// ========================================================================
// ?UpdateWalkBlend@@YA_NABVidVec3@@ABVidMat3@@MAAM22222@Z
// EA  : 0x826F8DC0
// RVA : 0x006F8DC0
// PDB : w:\tech5\engine\gamelib\animstack\animweb\animwebutils.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __fastcall UpdateWalkBlend(
        const idVec3 *velocity,
        const idMat3 *axis,
        double lerpScale,
        float *blendBack,
        float *blendRight,
        float *blendAngle,
        float *sync8index1,
        float *sync8index2,
        float *sync8blendAngle,
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
        float *a29)
{
  double v35; // fp13
  double v37; // fp31
  double v38; // fp30
  long double v39; // fp2
  __int64 v40; // r6 OVERLAPPED
  long double v41; // fp2
  double v42; // fp7
  double v43; // fp12
  double v44; // fp11
  double v45; // fp10
  double v46; // fp0
  double v47; // fp0
  double v48; // fp0
  double v49; // fp0
  double v50; // fp0
  double v51; // fp0
  __int64 v52; // r9
  int v53; // r11
  double v54; // fp7
  int v55; // r7

  v35 = __fsqrts((float)((float)(velocity->z * velocity->z)
                       + (float)((float)(velocity->x * velocity->x) + (float)(velocity->y * velocity->y))));
  if ( v35 <= 0.1 )
    return 0;
  v37 = (float)((float)((float)(velocity->x * axis->mat[0].x)
                      + (float)((float)(axis->mat[0].y * velocity->y) + (float)(axis->mat[0].z * velocity->z)))
              * (float)((float)1.0 / (float)v35));
  v38 = (float)((float)((float)(velocity->x * axis->mat[1].x)
                      + (float)((float)(axis->mat[1].y * velocity->y) + (float)(axis->mat[1].z * velocity->z)))
              * (float)((float)1.0 / (float)v35));
  if ( v37 >= -1.0 )
  {
    if ( v37 > 1.0 )
      v37 = 1.0;
  }
  else
  {
    v37 = -1.0;
  }
  if ( v38 >= -1.0 )
  {
    if ( v38 > 1.0 )
      v38 = 1.0;
  }
  else
  {
    v38 = -1.0;
  }
  *(double *)&v39 = v37;
  *((double *)&v39 + 1) = axis->mat[1].x;
  v41 = acos(x: v39);
  v42 = (float)(idMath::M_RAD2DEG * (float)*(double *)&v41);
  if ( v37 < 0.0 )
    v43 = (float)((float)((float)(idMath::M_RAD2DEG * (float)*(double *)&v41) - (float)90.0) * (float)0.011111111);
  else
    v43 = (float)-(float)((float)((float)(idMath::M_RAD2DEG * (float)*(double *)&v41) * (float)0.011111111) - (float)1.0);
  if ( v37 >= 0.0 )
    v44 = 0.0;
  else
    v44 = 1.0;
  if ( v38 >= 0.0 )
    v45 = 0.0;
  else
    v45 = 1.0;
  v46 = (float)((float)v44 - *blendRight);
  if ( v46 <= -0.000001 || v46 >= 0.000001 )
    v47 = (float)((float)((float)((float)v44 - *blendRight) * (float)lerpScale) + *blendRight);
  else
    v47 = v44;
  *blendRight = v47;
  v48 = (float)((float)v45 - *blendAngle);
  if ( v48 <= -0.000001 || v48 >= 0.000001 )
    v49 = (float)((float)((float)((float)v45 - *blendAngle) * (float)lerpScale) + *blendAngle);
  else
    v49 = v45;
  *blendAngle = v49;
  v50 = (float)((float)((float)1.0 - (float)v43) - *sync8index1);
  if ( v50 <= -0.000001 || v50 >= 0.000001 )
    v51 = (float)((float)((float)((float)((float)1.0 - (float)v43) - *sync8index1) * (float)lerpScale) + *sync8index1);
  else
    v51 = (float)((float)1.0 - (float)v43);
  *sync8index1 = v51;
  HIDWORD(v52) = &off_82030000;
  LODWORD(v40) = (int)(float)((float)v42 * (float)0.022222223);
  v54 = (float)-(float)((float)((float)v40 * (float)45.0) - (float)v42);
  *a29 = (float)v54 * (float)0.022222223;
  v53 = 7 - v40;
  if ( v38 < 0.0 )
    v53 = v40;
  else
    *a29 = (float)1.0 - (float)((float)v54 * (float)0.022222223);
  LODWORD(v52) = v53;
  v55 = (v53 + 1) & 7;
  *sync8index2 = (float)v52;
  *sync8blendAngle = (float)*(__int64 *)((char *)&v40 - 4);
  return 1;
}


// ========================================================================
// ?UpdateWalkBlendFromAngle@@YA_NMMAAM00000@Z
// EA  : 0x826F9098
// RVA : 0x006F9098
// PDB : w:\tech5\engine\gamelib\animstack\animweb\animwebutils.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __fastcall UpdateWalkBlendFromAngle(
        double angle,
        double lerpScale,
        float *blendBack,
        float *blendRight,
        float *blendAngle,
        float *sync8index1,
        float *sync8index2,
        float *sync8blendAngle,
        float *a9,
        float *a10)
{
  int v10; // r2 OVERLAPPED
  char v11; // r11
  double v12; // fp10
  unsigned __int8 v13; // r4
  double v14; // fp6
  double v15; // fp12
  double v16; // fp11
  int v17; // r11
  double v18; // fp0
  double v19; // fp0
  double v20; // fp0
  double v21; // fp0
  double v22; // fp0
  double v23; // fp0
  __int64 v24; // r7
  __int64 v25; // r5
  int v26; // r3
  int v27; // r11
  double v28; // fp6
  bool v29; // zf

  if ( angle <= -90.0 || (v11 = 1, angle >= 90.0) )
    v11 = 0;
  v12 = 0.0;
  if ( angle <= 0.0 || (v13 = 1, angle >= 180.0) )
    v13 = 0;
  v14 = __fabs(angle);
  if ( v11 != 0 )
    v15 = (float)-(float)((float)((float)v14 * (float)0.011111111) - (float)1.0);
  else
    v15 = (float)((float)((float)v14 - (float)90.0) * (float)0.011111111);
  if ( v11 != 0 )
    v16 = 0.0;
  else
    v16 = 1.0;
  v17 = v13;
  if ( v13 == 0 )
    v12 = 1.0;
  v18 = (float)((float)v16 - *blendAngle);
  if ( v18 <= -0.000001 || v18 >= 0.000001 )
    v19 = (float)((float)((float)((float)v16 - *blendAngle) * (float)lerpScale) + *blendAngle);
  else
    v19 = v16;
  *blendAngle = v19;
  v20 = (float)((float)v12 - *sync8index1);
  if ( v20 <= -0.000001 || v20 >= 0.000001 )
    v21 = (float)((float)((float)((float)v12 - *sync8index1) * (float)lerpScale) + *sync8index1);
  else
    v21 = v12;
  *sync8index1 = v21;
  v22 = (float)((float)((float)1.0 - (float)v15) - *sync8index2);
  if ( v22 <= -0.000001 || v22 >= 0.000001 )
    v23 = (float)((float)((float)((float)((float)1.0 - (float)v15) - *sync8index2) * (float)lerpScale) + *sync8index2);
  else
    v23 = (float)((float)1.0 - (float)v15);
  HIDWORD(v24) = "_AI_OBSTACLE";
  *sync8index2 = v23;
  HIDWORD(v25) = (int)(float)((float)v14 * (float)0.022222223);
  v26 = HIDWORD(v25);
  v28 = (float)-(float)((float)((float)*(__int64 *)(&v10 - 1) * (float)45.0) - (float)v14);
  *a10 = (float)v28 * (float)0.022222223;
  v29 = v17 == 0;
  v27 = 7 - HIDWORD(v25);
  if ( v29 )
    v27 = HIDWORD(v25);
  else
    *a10 = (float)1.0 - (float)((float)v28 * (float)0.022222223);
  LODWORD(v24) = v27;
  LODWORD(v25) = (v27 + 1) & 7;
  *sync8blendAngle = (float)v24;
  *a9 = (float)v25;
  return 1;
}

