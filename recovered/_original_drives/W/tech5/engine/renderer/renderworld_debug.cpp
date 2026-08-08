
// ========================================================================
// ?DebugArrow3@idRenderWorldLocal@@UAAXABVidVec4@@ABVidVec3@@1MH_N@Z
// EA  : 0x8295E7B8
// RVA : 0x0095E7B8
// PDB : w:\tech5\engine\renderer\renderworld_debug.cpp
// ========================================================================

void __fastcall idRenderWorldLocal::DebugArrow3(
        idRenderWorldLocal *this,
        const idVec4 *color,
        const idVec3 *start,
        const idVec3 *end,
        double size,
        const int lifetime,
        int depthTest,
        BOOL a8)
{
  double v9; // fp11
  double v11; // fp5
  double v19; // fp9
  double v20; // fp13
  double v21; // fp10
  double v22; // fp9
  double y; // fp11
  double z; // fp10
  void (__fastcall *DebugPyramid)(idRenderWorld *, const idVec4 *, const idVec3 *, const idVec3 *, const idVec3 *, float, float, const int, const bool); // ctr
  idVec3 v26; // [sp+60h] [-70h] BYREF
  idVec3 v27; // [sp+70h] [-60h] BYREF
  idVec3 v28; // [sp+80h] [-50h] BYREF

  v9 = (float)(end->z - start->z);
  v11 = (float)(end->y - start->y);
  _FP1 = (float)((float)((float)((float)v11 * (float)v11)
                       + (float)((float)((float)(end->x - start->x) * (float)(end->x - start->x))
                               + (float)((float)v9 * (float)v9)))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f10, f1, f2, f13 }
  v19 = __frsqrte(_FP10);
  v20 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v19
                                                                                      * (float)((float)((float)((float)v11 * (float)v11) + (float)((float)((float)(end->x - start->x) * (float)(end->x - start->x)) + (float)((float)v9 * (float)v9)))
                                                                                              * (float)0.5))
                                                                              * (float)v19)
                                                                      - (float)1.5)
                                                      * (float)v19)
                                              * (float)((float)((float)((float)v11 * (float)v11)
                                                              + (float)((float)((float)(end->x - start->x)
                                                                              * (float)(end->x - start->x))
                                                                      + (float)((float)v9 * (float)v9)))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v19
                                                                              * (float)((float)((float)((float)v11 * (float)v11)
                                                                                              + (float)((float)((float)(end->x - start->x) * (float)(end->x - start->x)) + (float)((float)v9 * (float)v9)))
                                                                                      * (float)0.5))
                                                                      * (float)v19)
                                                              - (float)1.5)
                                              * (float)v19))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v19
                                                      * (float)((float)((float)((float)v11 * (float)v11)
                                                                      + (float)((float)((float)(end->x - start->x)
                                                                                      * (float)(end->x - start->x))
                                                                              + (float)((float)v9 * (float)v9)))
                                                              * (float)0.5))
                                              * (float)v19)
                                      - (float)1.5)
                      * (float)v19));
  v21 = (float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v19 * (float)((float)((float)((float)v11 * (float)v11) + (float)((float)((float)(end->x - start->x) * (float)(end->x - start->x)) + (float)((float)v9 * (float)v9))) * (float)0.5)) * (float)v19) - (float)1.5)
                                                                                      * (float)v19)
                                                                              * (float)((float)((float)((float)v11 * (float)v11)
                                                                                              + (float)((float)((float)(end->x - start->x) * (float)(end->x - start->x)) + (float)((float)v9 * (float)v9)))
                                                                                      * (float)0.5))
                                                                      * (float)((float)-(float)((float)((float)((float)v19 * (float)((float)((float)((float)v11 * (float)v11) + (float)((float)((float)(end->x - start->x) * (float)(end->x - start->x)) + (float)((float)v9 * (float)v9))) * (float)0.5)) * (float)v19)
                                                                                              - (float)1.5)
                                                                              * (float)v19))
                                                              - (float)1.5)
                                              * (float)((float)-(float)((float)((float)((float)v19
                                                                                      * (float)((float)((float)((float)v11 * (float)v11) + (float)((float)((float)(end->x - start->x) * (float)(end->x - start->x)) + (float)((float)v9 * (float)v9)))
                                                                                              * (float)0.5))
                                                                              * (float)v19)
                                                                      - (float)1.5)
                                                      * (float)v19))
                                      * (float)((float)((float)((float)v11 * (float)v11)
                                                      + (float)((float)((float)(end->x - start->x)
                                                                      * (float)(end->x - start->x))
                                                              + (float)((float)v9 * (float)v9)))
                                              * (float)0.5))
                              * (float)v20)
                      - (float)1.5);
  v22 = (float)((float)v21
              * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v19
                                                                                              * (float)((float)((float)((float)v11 * (float)v11) + (float)((float)((float)(end->x - start->x) * (float)(end->x - start->x)) + (float)((float)v9 * (float)v9))) * (float)0.5))
                                                                                      * (float)v19)
                                                                              - (float)1.5)
                                                              * (float)v19)
                                                      * (float)((float)((float)((float)v11 * (float)v11)
                                                                      + (float)((float)((float)(end->x - start->x)
                                                                                      * (float)(end->x - start->x))
                                                                              + (float)((float)v9 * (float)v9)))
                                                              * (float)0.5))
                                              * (float)((float)-(float)((float)((float)((float)v19
                                                                                      * (float)((float)((float)((float)v11 * (float)v11) + (float)((float)((float)(end->x - start->x) * (float)(end->x - start->x)) + (float)((float)v9 * (float)v9)))
                                                                                              * (float)0.5))
                                                                              * (float)v19)
                                                                      - (float)1.5)
                                                      * (float)v19))
                                      - (float)1.5)
                      * (float)((float)-(float)((float)((float)((float)v19
                                                              * (float)((float)((float)((float)v11 * (float)v11)
                                                                              + (float)((float)((float)(end->x - start->x)
                                                                                              * (float)(end->x - start->x))
                                                                                      + (float)((float)v9 * (float)v9)))
                                                                      * (float)0.5))
                                                      * (float)v19)
                                              - (float)1.5)
                              * (float)v19)));
  v26.x = (float)(end->x - start->x) * (float)v22;
  v26.y = (float)v22 * (float)v11;
  v26.z = (float)v9 * (float)v22;
  idVec3::NormalVectors(this: &v26, left: &v28, down: &v27);
  this->DebugLine(this, a2: color, a3: start, a4: end, a5: depthTest, a6: a8);
  y = end->y;
  z = end->z;
  DebugPyramid = this->DebugPyramid;
  v27.x = end->x - (float)(v26.x * (float)size);
  v27.y = (float)y - (float)(v26.y * (float)size);
  v27.z = (float)z - (float)(v26.z * (float)size);
  ((void (__fastcall *)(idRenderWorldLocal *, const idVec4 *, idVec3 *, idVec3 *, idVec3 *, double, double))DebugPyramid)(
    a1: this,
    a2: color,
    a3: &v27,
    a4: &v26,
    a5: &v28,
    a6: size,
    a7: size);
}


// ========================================================================
// ?DebugPyramid@idRenderWorldLocal@@UAAXABVidVec4@@ABVidVec3@@11MMH_N@Z
// EA  : 0x8295E938
// RVA : 0x0095E938
// PDB : w:\tech5\engine\renderer\renderworld_debug.cpp
// ========================================================================

void __fastcall idRenderWorldLocal::DebugPyramid(
        idRenderWorldLocal *this,
        const idVec4 *color,
        const idVec3 *base,
        const idVec3 *up,
        const idVec3 *forward,
        double height,
        double width,
        const int lifetime,
        const bool depthTest,
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
        bool a30)
{
  double x; // fp13
  double y; // fp8
  double z; // fp10
  double v33; // fp6
  double v34; // fp7
  double v35; // fp3
  double v36; // fp1
  double v37; // fp28
  double v38; // fp31
  double v39; // fp26
  double v40; // fp29
  double v41; // fp27
  double v42; // fp30
  idRenderWorldLocal_vtbl *v44; // r10
  double v45; // fp11
  double v46; // fp5
  double v47; // fp9
  void (__fastcall *DebugLine)(idRenderWorld *, const idVec4 *, const idVec3 *, const idVec3 *, const int, const bool); // ctr
  float v51[4]; // [sp+50h] [-B0h] BYREF
  float v52; // [sp+60h] [-A0h] BYREF
  float v53; // [sp+64h] [-9Ch]
  float v54; // [sp+68h] [-98h]
  float v55; // [sp+70h] [-90h] BYREF
  float v56; // [sp+74h] [-8Ch]
  float v57; // [sp+78h] [-88h]
  float v58; // [sp+80h] [-80h] BYREF
  float v59; // [sp+84h] [-7Ch]
  float v60; // [sp+88h] [-78h]
  float v61[18]; // [sp+90h] [-70h] BYREF

  x = up->x;
  y = forward->y;
  z = up->z;
  v33 = forward->z;
  v34 = (float)(up->z * (float)height);
  v35 = (float)(forward->z * up->y);
  v37 = base->y;
  v38 = (float)(forward->x * (float)width);
  v39 = base->z;
  v40 = (float)(forward->y * (float)width);
  v41 = (float)(forward->z * (float)width);
  v42 = base->x;
  v44 = this->__vftable;
  v45 = (float)(base->x + (float)(up->x * (float)height));
  v46 = (float)((float)(forward->x * up->y) - (float)(forward->y * up->x));
  v47 = (float)(base->y + (float)(up->y * (float)height));
  v36 = (float)(forward->x * up->z);
  v51[0] = v45;
  v51[1] = v47;
  v51[2] = (float)v39 + (float)v34;
  DebugLine = v44->DebugLine;
  v54 = (float)((float)v39 + (float)((float)((float)v46 * (float)width) * (float)0.5))
      + (float)((float)v41 * (float)0.5);
  v52 = (float)((float)v42
              + (float)((float)((float)((float)((float)y * (float)z) - (float)v35) * (float)width) * (float)0.5))
      + (float)((float)v38 * (float)0.5);
  v53 = (float)((float)v37
              + (float)((float)((float)((float)((float)v33 * (float)x) - (float)v36) * (float)width) * (float)0.5))
      + (float)((float)v40 * (float)0.5);
  v57 = v54 - (float)v41;
  v55 = v52 - (float)v38;
  v56 = v53 - (float)v40;
  v60 = v57 - (float)((float)v46 * (float)width);
  v58 = v55 - (float)((float)((float)((float)y * (float)z) - (float)v35) * (float)width);
  v59 = v56 - (float)((float)((float)((float)v33 * (float)x) - (float)v36) * (float)width);
  v61[2] = (float)v41 + v60;
  v61[0] = (float)v38 + v58;
  v61[1] = (float)v40 + v59;
  DebugLine(this, a2: color, a3: (const idVec3 *)&v52, a4: (const idVec3 *)&v55, a5: a10, a6: a30);
  this->DebugLine(this, a2: color, a3: (const idVec3 *)&v55, a4: (const idVec3 *)&v58, a5: a10, a6: a30);
  this->DebugLine(this, a2: color, a3: (const idVec3 *)&v58, a4: (const idVec3 *)v61, a5: a10, a6: a30);
  this->DebugLine(this, a2: color, a3: (const idVec3 *)v61, a4: (const idVec3 *)&v52, a5: a10, a6: a30);
  this->DebugLine(this, a2: color, a3: (const idVec3 *)&v52, a4: (const idVec3 *)v51, a5: a10, a6: a30);
  this->DebugLine(this, a2: color, a3: (const idVec3 *)&v55, a4: (const idVec3 *)v51, a5: a10, a6: a30);
  this->DebugLine(this, a2: color, a3: (const idVec3 *)&v58, a4: (const idVec3 *)v51, a5: a10, a6: a30);
  this->DebugLine(this, a2: color, a3: (const idVec3 *)v61, a4: (const idVec3 *)v51, a5: a10, a6: a30);
}


// ========================================================================
// ?DebugWinding@idRenderWorldLocal@@UAAXABVidVec4@@ABVidWinding@@ABVidVec3@@ABVidMat3@@H_N@Z
// EA  : 0x8295EBA8
// RVA : 0x0095EBA8
// PDB : w:\tech5\engine\renderer\renderworld_debug.cpp
// ========================================================================

void __fastcall idRenderWorldLocal::DebugWinding(
        idRenderWorldLocal *this,
        const idVec4 *color,
        const idWinding *w,
        const idVec3 *origin,
        const idMat3 *axis,
        int lifetime,
        BOOL depthTest)
{
  int numPoints; // r10
  int v15; // r29
  idVec5 *v16; // r11
  double x; // fp5
  double z; // fp31
  double v19; // fp13
  double v20; // fp0
  int v21; // r27
  idVec5 *v22; // r11
  void (__fastcall *DebugLine)(idRenderWorld *, const idVec4 *, const idVec3 *, const idVec3 *, const int, const bool); // ctr
  double v24; // fp31
  double v25; // fp2
  double v26; // fp0
  int v27; // r8
  float v28; // [sp+50h] [-80h] BYREF
  float v29; // [sp+54h] [-7Ch]
  float v30; // [sp+58h] [-78h]
  float v31; // [sp+60h] [-70h] BYREF
  float v32; // [sp+64h] [-6Ch]
  float v33; // [sp+68h] [-68h]

  numPoints = w->numPoints;
  if ( numPoints >= 2 )
  {
    v15 = 0;
    v16 = &w->p[numPoints];
    x = origin->x;
    z = origin->z;
    v19 = (float)((float)(axis->mat[0].z * v16[-1].x)
                + (float)((float)(v16[-1].y * axis->mat[1].z) + (float)(v16[-1].z * axis->mat[2].z)));
    v20 = (float)((float)(axis->mat[1].x * v16[-1].y)
                + (float)((float)(axis->mat[2].x * v16[-1].z) + (float)(axis->mat[0].x * v16[-1].x)));
    v32 = origin->y
        + (float)((float)(v16[-1].x * axis->mat[0].y)
                + (float)((float)(axis->mat[1].y * v16[-1].y) + (float)(axis->mat[2].y * v16[-1].z)));
    v33 = (float)z + (float)v19;
    v31 = (float)x + (float)v20;
    v21 = 0;
    do
    {
      v22 = &w->p[v21];
      DebugLine = this->DebugLine;
      v24 = origin->z;
      v25 = (float)((float)(axis->mat[0].z * v22->x)
                  + (float)((float)(v22->y * axis->mat[1].z) + (float)(v22->z * axis->mat[2].z)));
      v26 = (float)(origin->x
                  + (float)((float)(axis->mat[1].x * v22->y)
                          + (float)((float)(axis->mat[2].x * v22->z) + (float)(axis->mat[0].x * v22->x))));
      v29 = origin->y
          + (float)((float)(v22->x * axis->mat[0].y)
                  + (float)((float)(axis->mat[1].y * v22->y) + (float)(axis->mat[2].y * v22->z)));
      v28 = v26;
      v30 = (float)v24 + (float)v25;
      DebugLine(this, a2: color, a3: (const idVec3 *)&v31, a4: (const idVec3 *)&v28, a5: lifetime, a6: depthTest);
      v27 = w->numPoints;
      ++v15;
      ++v21;
      v31 = v28;
      v32 = v29;
      v33 = v30;
    }
    while ( v15 < v27 );
  }
}


// ========================================================================
// ?DebugCircle@idRenderWorldLocal@@UAAXABVidVec4@@ABVidVec3@@1MHH_N@Z
// EA  : 0x8295ED60
// RVA : 0x0095ED60
// PDB : w:\tech5\engine\renderer\renderworld_debug.cpp
// ========================================================================

void __fastcall idRenderWorldLocal::DebugCircle(
        idRenderWorldLocal *this,
        const idVec4 *color,
        const idVec3 *origin,
        idVec3 *dir,
        double radius,
        const int numSteps,
        int lifetime,
        int depthTest,
        BOOL a9)
{
  __int64 v16; // r11
  long double v17; // fp2
  int v18; // r30
  double v19; // fp31
  double v20; // fp30
  double v21; // fp29
  double y; // fp13
  double z; // fp12
  double v24; // fp28
  double v25; // fp27
  double v26; // fp26
  double v27; // fp25
  double v28; // fp24
  long double v29; // fp2
  double v30; // fp9
  double v31; // fp24
  double v32; // fp23
  double v33; // fp22
  long double v34; // fp2
  void (__fastcall *DebugLine)(idRenderWorld *, const idVec4 *, const idVec3 *, const idVec3 *, const int, const bool); // ctr
  double v36; // fp0
  double v37; // fp13
  idVec3 v38; // [sp+58h] [-B8h] BYREF
  idVec3 v39[8]; // [sp+68h] [-A8h] BYREF

  idVec3::NormalVectors(this: dir, left: v39, down: &v38);
  v18 = 1;
  v19 = (float)(v39[0].x * (float)radius);
  v20 = (float)(v39[0].y * (float)radius);
  v21 = (float)(v39[0].z * (float)radius);
  y = origin->y;
  z = origin->z;
  v24 = (float)(v38.x * (float)radius);
  v25 = (float)(v38.y * (float)radius);
  v39[0].x = origin->x + (float)(v39[0].x * (float)radius);
  v39[0].y = (float)y + (float)(v39[0].y * (float)radius);
  v39[0].z = (float)z + (float)(v39[0].z * (float)radius);
  v26 = (float)(v38.z * (float)radius);
  if ( lifetime >= 1 )
  {
    LODWORD(v16) = lifetime;
    v27 = (float)v16;
    do
    {
      LODWORD(v16) = v18;
      v28 = (float)((float)((float)v16 * idMath::TWO_PI) / (float)v27);
      *(double *)&v17 = v28;
      v29 = cos(x: v17);
      v30 = (float)*(double *)&v29;
      *(double *)&v29 = v28;
      v31 = (float)((float)v19 * (float)v30);
      v32 = (float)((float)v20 * (float)v30);
      v33 = (float)((float)v21 * (float)v30);
      v34 = sin(x: v29);
      DebugLine = this->DebugLine;
      v36 = (float)(origin->y + (float)((float)v25 * (float)*(double *)&v34));
      v37 = (float)(origin->z + (float)((float)v26 * (float)*(double *)&v34));
      v38.x = (float)(origin->x + (float)((float)v24 * (float)*(double *)&v34)) + (float)v31;
      v38.y = (float)v36 + (float)v32;
      v38.z = (float)v37 + (float)v33;
      DebugLine(this, a2: color, a3: v39, a4: &v38, a5: depthTest, a6: a9);
      ++v18;
      v39[0].x = v38.x;
      v39[0].y = v38.y;
      v39[0].z = v38.z;
    }
    while ( v18 <= lifetime );
  }
}


// ========================================================================
// ?DebugCylinder@idRenderWorldLocal@@UAAXABVidVec4@@ABVidCylinder@@ABVidVec3@@HH_N@Z
// EA  : 0x8295EEF8
// RVA : 0x0095EEF8
// PDB : w:\tech5\engine\renderer\renderworld_debug.cpp
// ========================================================================

void __fastcall idRenderWorldLocal::DebugCylinder(
        idRenderWorldLocal *this,
        const idVec4 *color,
        const idCylinder *cyl,
        idVec3 *dir,
        int numSteps,
        int lifetime,
        BOOL depthTest)
{
  __int64 v14; // r11
  long double v15; // fp2
  int v16; // r28
  double v17; // fp25
  double v18; // fp24
  double v19; // fp23
  double v20; // fp22
  double v21; // fp21
  double v22; // fp20
  double v23; // fp28
  double v24; // fp27
  double v25; // fp26
  double v26; // fp19
  double v27; // fp31
  long double v28; // fp2
  double v29; // fp9
  double v30; // fp31
  double v31; // fp30
  double v32; // fp29
  long double v33; // fp2
  double x; // fp7
  double y; // fp6
  double v36; // fp13
  double z; // fp5
  void (__fastcall *DebugLine)(idRenderWorld *, const idVec4 *, const idVec3 *, const idVec3 *, const int, const bool); // r9
  double v39; // fp0
  double v40; // fp9
  double v41; // fp3
  double v42; // fp10
  double v43; // fp31
  double v44; // fp30
  double v45; // fp29
  idRenderWorldLocal_vtbl *v46; // r3
  double v47; // fp8
  double v48; // fp7
  double v49; // fp5
  double v50; // fp4
  double v51; // fp3
  void (__fastcall *v52)(idRenderWorld *, const idVec4 *, const idVec3 *, const idVec3 *, const int, const bool); // r11
  double halfHeight; // fp0
  double v54; // fp10
  double v55; // fp9
  double v56; // fp5
  void (__fastcall *v57)(idRenderWorld *, const idVec4 *, const idVec3 *, const idVec3 *, const int, const bool); // ctr
  double v58; // fp1
  idVec3 v59; // [sp+50h] [-130h] BYREF
  idVec3 v60; // [sp+60h] [-120h] BYREF
  float v61[4]; // [sp+70h] [-110h] BYREF
  float v62[4]; // [sp+80h] [-100h] BYREF
  float v63[4]; // [sp+90h] [-F0h] BYREF
  float v64[4]; // [sp+A0h] [-E0h] BYREF
  float v65[32]; // [sp+B0h] [-D0h] BYREF

  idVec3::NormalVectors(this: dir, left: &v59, down: &v60);
  v16 = 1;
  v17 = (float)(v59.x * cyl->radius);
  v18 = (float)(v59.y * cyl->radius);
  v19 = (float)(v59.z * cyl->radius);
  v20 = (float)(v60.x * cyl->radius);
  v21 = (float)(v60.y * cyl->radius);
  v22 = (float)(v60.z * cyl->radius);
  v23 = (float)(cyl->origin.x + (float)(v59.x * cyl->radius));
  v24 = (float)((float)(v59.y * cyl->radius) + cyl->origin.y);
  v25 = (float)((float)(v59.z * cyl->radius) + cyl->origin.z);
  if ( numSteps >= 1 )
  {
    LODWORD(v14) = numSteps;
    *(_QWORD *)&v59.x = v14;
    v26 = (float)v14;
    do
    {
      LODWORD(v14) = v16;
      v27 = (float)((float)((float)v14 * idMath::TWO_PI) / (float)v26);
      *(double *)&v15 = v27;
      *(_QWORD *)&v59.x = v14;
      v28 = cos(x: v15);
      v29 = (float)*(double *)&v28;
      *(double *)&v28 = v27;
      v30 = (float)((float)v17 * (float)v29);
      v31 = (float)((float)v18 * (float)v29);
      v32 = (float)((float)v19 * (float)v29);
      v33 = sin(x: v28);
      x = cyl->origin.x;
      y = cyl->origin.y;
      v36 = (float)(dir->y * cyl->halfHeight);
      z = cyl->origin.z;
      DebugLine = this->DebugLine;
      v39 = (float)(dir->z * cyl->halfHeight);
      v40 = (float)((float)v20 * (float)*(double *)&v33);
      v41 = (float)((float)v21 * (float)*(double *)&v33);
      *((double *)&v33 + 1) = (float)((float)v22 * (float)*(double *)&v33);
      *(double *)&v33 = (float)(dir->x * cyl->halfHeight);
      v42 = (float)((float)(dir->y * cyl->halfHeight) + (float)v24);
      v60.x = (float)(dir->x * cyl->halfHeight) + (float)v23;
      v60.y = v42;
      v60.z = (float)v39 + (float)v25;
      v43 = (float)((float)((float)x + (float)v40) + (float)v30);
      v44 = (float)((float)((float)v41 + (float)y) + (float)v31);
      v45 = (float)((float)((float)*((double *)&v33 + 1) + (float)z) + (float)v32);
      v61[0] = (float)*(double *)&v33 + (float)v43;
      v61[1] = (float)v36 + (float)v44;
      v61[2] = (float)v39 + (float)v45;
      DebugLine(this, a2: color, a3: &v60, a4: (const idVec3 *)v61, a5: lifetime, a6: depthTest);
      v46 = this->__vftable;
      v47 = (float)(dir->y * cyl->halfHeight);
      v48 = (float)(dir->z * cyl->halfHeight);
      v49 = (float)((float)v44 - (float)(dir->y * cyl->halfHeight));
      v50 = (float)((float)v45 - (float)(dir->z * cyl->halfHeight));
      v51 = (float)((float)v23 - (float)(dir->x * cyl->halfHeight));
      v62[0] = (float)v43 - (float)(dir->x * cyl->halfHeight);
      v62[1] = v49;
      v62[2] = v50;
      v63[0] = v51;
      v63[1] = (float)v24 - (float)v47;
      v52 = v46->DebugLine;
      v63[2] = (float)v25 - (float)v48;
      v52(this, a2: color, a3: (const idVec3 *)v63, a4: (const idVec3 *)v62, a5: lifetime, a6: depthTest);
      halfHeight = cyl->halfHeight;
      v54 = dir->z;
      v55 = (float)(dir->y * cyl->halfHeight);
      v56 = (float)(dir->z * cyl->halfHeight);
      v57 = this->DebugLine;
      v58 = (float)((float)(dir->x * cyl->halfHeight) + (float)v43);
      v64[0] = (float)v43 - (float)(dir->x * cyl->halfHeight);
      v65[0] = v58;
      v64[1] = (float)v44 - (float)v55;
      v64[2] = (float)v45 - (float)((float)v54 * (float)halfHeight);
      v65[2] = (float)v56 + (float)v45;
      v65[1] = (float)v55 + (float)v44;
      v57(this, a2: color, a3: (const idVec3 *)v65, a4: (const idVec3 *)v64, a5: lifetime, a6: depthTest);
      ++v16;
      v23 = v43;
      v24 = v44;
      v25 = v45;
    }
    while ( v16 <= numSteps );
  }
}


// ========================================================================
// ?DebugArc@idRenderWorldLocal@@UAAXABVidVec4@@ABVidVec3@@1MMMMH_N2@Z
// EA  : 0x8295F1C8
// RVA : 0x0095F1C8
// PDB : w:\tech5\engine\renderer\renderworld_debug.cpp
// ========================================================================

void __fastcall idRenderWorldLocal::DebugArc(
        idRenderWorldLocal *this,
        const idVec4 *color,
        const idVec3 *origin,
        idVec3 *dir,
        double radius,
        double startAngle,
        double endAngle,
        double anglesPerSegment,
        const int lifetime,
        const bool depthTest,
        const bool drawSectorEdges,
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
        int a30,
        int a31,
        int a32,
        int a33,
        bool a34,
        int a35,
        char a36)
{
  double v43; // fp13
  double v44; // fp29
  double v45; // fp30
  double v46; // fp31
  double v47; // fp25
  double v48; // fp22
  int v49; // r25
  __int64 v50; // r9
  double v51; // fp28
  double v52; // fp27
  double v53; // fp26
  double v54; // fp24
  long double v55; // fp2
  long double v56; // fp2
  double v57; // fp23
  double v58; // fp21
  double v59; // fp20
  __int64 v60; // r11
  double v61; // fp4
  long double v62; // fp2
  int v63; // r30
  double v64; // fp23
  double v65; // fp21
  long double v66; // fp2
  double v67; // fp9
  double v68; // fp21
  double v69; // fp20
  double v70; // fp19
  long double v71; // fp2
  void (__fastcall *DebugLine)(idRenderWorld *, const idVec4 *, const idVec3 *, const idVec3 *, const int, const bool); // ctr
  double v73; // fp0
  double v74; // fp13
  long double v75; // fp2
  double v76; // fp28
  double v77; // fp27
  double v78; // fp26
  long double v79; // fp2
  void (__fastcall *v80)(idRenderWorld *, const idVec4 *, const idVec3 *, const idVec3 *, const int, const bool); // ctr
  double v81; // fp4
  idVec3 v82; // [sp+58h] [-D8h] BYREF
  idVec3 v83[10]; // [sp+68h] [-C8h] BYREF

  idVec3::NormalVectors(this: dir, left: v83, down: &v82);
  v43 = (float)((float)endAngle - (float)startAngle);
  v44 = (float)(v83[0].z * (float)radius);
  v45 = (float)(v83[0].y * (float)radius);
  v46 = (float)(v83[0].x * (float)radius);
  v47 = (float)(idMath::M_DEG2RAD * (float)startAngle);
  v48 = (float)(idMath::M_DEG2RAD * (float)endAngle);
  v49 = (int)__fabs((float)((float)((float)endAngle - (float)startAngle) / (float)anglesPerSegment));
  LODWORD(v50) = v49;
  v51 = (float)((float)((float)((float)(v82.z * v83[0].y) - (float)(v83[0].z * v82.y)) * (float)-1.0) * (float)radius);
  v52 = (float)((float)((float)((float)(v83[0].z * v82.x) - (float)(v82.z * v83[0].x)) * (float)-1.0) * (float)radius);
  v53 = (float)((float)((float)((float)(v82.y * v83[0].x) - (float)(v83[0].y * v82.x)) * (float)-1.0) * (float)radius);
  if ( (float)((float)v50 * (float)anglesPerSegment) < v43 )
    ++v49;
  v54 = (float)(idMath::M_DEG2RAD * (float)v43);
  *(double *)&v55 = v47;
  *((double *)&v55 + 1) = (float)v50;
  v56 = cos(x: v55);
  v57 = (float)((float)*(double *)&v56 * (float)v51);
  v58 = (float)((float)v52 * (float)*(double *)&v56);
  v59 = (float)((float)v53 * (float)*(double *)&v56);
  *(double *)&v56 = v47;
  v62 = sin(x: v56);
  v61 = (float)(origin->z - (float)((float)v44 * (float)*(double *)&v62));
  *((double *)&v62 + 1) = (float)((float)(origin->y - (float)((float)v45 * (float)*(double *)&v62)) + (float)v58);
  v83[0].x = (float)(origin->x - (float)((float)v46 * (float)*(double *)&v62)) + (float)v57;
  v83[0].y = *((double *)&v62 + 1);
  v83[0].z = (float)v61 + (float)v59;
  if ( a36 != 0 )
    this->DebugLine(this, a2: color, a3: origin, a4: v83, a5: a32, a6: a34);
  v63 = 1;
  if ( v49 > 1 )
  {
    LODWORD(v60) = v49;
    v64 = (float)v60;
    do
    {
      LODWORD(v60) = v63;
      v65 = (float)((float)((float)((float)v60 * (float)v54) / (float)v64) + (float)v47);
      *(double *)&v62 = v65;
      v66 = cos(x: v62);
      v67 = (float)*(double *)&v66;
      *(double *)&v66 = v65;
      v68 = (float)((float)v67 * (float)v51);
      v69 = (float)((float)v52 * (float)v67);
      v70 = (float)((float)v53 * (float)v67);
      v71 = sin(x: v66);
      DebugLine = this->DebugLine;
      v73 = (float)(origin->y - (float)((float)v45 * (float)*(double *)&v71));
      v74 = (float)(origin->z - (float)((float)v44 * (float)*(double *)&v71));
      v82.x = (float)(origin->x - (float)((float)*(double *)&v71 * (float)v46)) + (float)v68;
      v82.y = (float)v73 + (float)v69;
      v82.z = (float)v74 + (float)v70;
      DebugLine(this, a2: color, a3: v83, a4: &v82, a5: a32, a6: a34);
      ++v63;
      v83[0].x = v82.x;
      v83[0].y = v82.y;
      v83[0].z = v82.z;
    }
    while ( v63 < v49 );
  }
  *(double *)&v62 = v48;
  v75 = cos(x: v62);
  v76 = (float)((float)*(double *)&v75 * (float)v51);
  v77 = (float)((float)v52 * (float)*(double *)&v75);
  v78 = (float)((float)v53 * (float)*(double *)&v75);
  *(double *)&v75 = v48;
  v79 = sin(x: v75);
  v80 = this->DebugLine;
  v81 = (float)(origin->z - (float)((float)v44 * (float)*(double *)&v79));
  *((double *)&v79 + 1) = (float)((float)(origin->y - (float)((float)v45 * (float)*(double *)&v79)) + (float)v77);
  v82.x = (float)(origin->x - (float)((float)*(double *)&v79 * (float)v46)) + (float)v76;
  v82.y = *((double *)&v79 + 1);
  v82.z = (float)v81 + (float)v78;
  v80(this, a2: color, a3: v83, a4: &v82, a5: a32, a6: a34);
  if ( a36 != 0 )
    this->DebugLine(this, a2: color, a3: origin, a4: &v82, a5: a32, a6: a34);
}


// ========================================================================
// ?DebugBounds@idRenderWorldLocal@@UAAXABVidVec4@@ABVidBounds@@ABVidVec3@@H_N@Z
// EA  : 0x8295F508
// RVA : 0x0095F508
// PDB : w:\tech5\engine\renderer\renderworld_debug.cpp
// ========================================================================

void __fastcall idRenderWorldLocal::DebugBounds(
        idRenderWorldLocal *this,
        const idVec4 *color,
        const idBounds *bounds,
        const idVec3 *org,
        int lifetime,
        BOOL depthTest)
{
  double x; // fp0
  double v8; // fp13
  double v12; // fp12
  int v13; // r29
  double y; // fp11
  double z; // fp9
  double v16; // fp5
  double v17; // fp6
  double v18; // fp7
  double v19; // fp3
  double v20; // fp31
  double v21; // fp1
  const idVec3 *v22; // r30
  int v23; // r28
  float v24; // [sp+50h] [-C0h] BYREF
  float v25; // [sp+54h] [-BCh]
  float v26; // [sp+58h] [-B8h]
  float v27; // [sp+5Ch] [-B4h]
  float v28; // [sp+60h] [-B0h]
  float v29; // [sp+64h] [-ACh]
  float v30; // [sp+68h] [-A8h]
  float v31; // [sp+6Ch] [-A4h]
  float v32; // [sp+70h] [-A0h]
  float v33; // [sp+74h] [-9Ch]
  float v34; // [sp+78h] [-98h]
  float v35; // [sp+7Ch] [-94h]
  float v36[2]; // [sp+80h] [-90h] BYREF
  float v37; // [sp+88h] [-88h]
  float v38; // [sp+8Ch] [-84h]
  float v39; // [sp+90h] [-80h]
  float v40; // [sp+94h] [-7Ch]
  float v41; // [sp+98h] [-78h]
  float v42; // [sp+9Ch] [-74h]
  float v43; // [sp+A0h] [-70h]
  float v44; // [sp+A4h] [-6Ch]
  float v45; // [sp+A8h] [-68h]
  float v46; // [sp+ACh] [-64h]

  x = bounds->b[0].x;
  v8 = bounds->b[1].x;
  if ( x <= v8 )
  {
    v12 = org->x;
    v13 = 1;
    y = org->y;
    z = org->z;
    v16 = bounds->b[0].z;
    v17 = (float)(org->x + bounds->b[1].x);
    v18 = bounds->b[0].y;
    v19 = bounds->b[1].y;
    v20 = (float)(org->y + bounds->b[0].y);
    v24 = org->x + bounds->b[0].x;
    v21 = bounds->b[1].z;
    v27 = (float)v12 + (float)v8;
    v25 = (float)y + (float)v18;
    v26 = (float)z + (float)v16;
    v30 = v17;
    v31 = (float)y + (float)v19;
    v28 = v20;
    v32 = v26;
    v34 = v31;
    v35 = v26;
    v33 = (float)v12 + (float)x;
    v37 = (float)z + (float)v21;
    v29 = v26;
    v36[0] = v33;
    v36[1] = v25;
    v38 = v27;
    v39 = v25;
    v40 = v37;
    v41 = v27;
    v22 = (const idVec3 *)&v24;
    v42 = v31;
    v23 = 4;
    v43 = v37;
    v44 = v33;
    v45 = v31;
    v46 = v37;
    do
    {
      this->DebugLine(
        this,
        a2: color,
        a3: v22,
        a4: (const idVec3 *)(&v24 + (v13 & 3) + ((2 * v13) & 6)),
        a5: lifetime,
        a6: depthTest);
      this->DebugLine(
        this,
        a2: color,
        a3: &v22[4],
        a4: (const idVec3 *)&v36[(v13 & 3) + ((2 * v13) & 6)],
        a5: lifetime,
        a6: depthTest);
      this->DebugLine(this, a2: color, a3: v22, a4: &v22[4], a5: lifetime, a6: depthTest);
      --v23;
      ++v13;
      ++v22;
    }
    while ( v23 != 0 );
  }
}


// ========================================================================
// ?DebugOrientedBounds@idRenderWorldLocal@@UAAXABVidVec4@@ABVidBounds@@ABVidVec3@@ABVidMat3@@H_N@Z
// EA  : 0x8295F6F0
// RVA : 0x0095F6F0
// PDB : w:\tech5\engine\renderer\renderworld_debug.cpp
// ========================================================================

void __fastcall idRenderWorldLocal::DebugOrientedBounds(
        idRenderWorldLocal *this,
        const idVec4 *color,
        const idBounds *bounds,
        const idVec3 *org,
        const idMat3 *axis,
        int lifetime,
        BOOL depthTest)
{
  double x; // fp13
  double z; // fp4
  double v13; // fp7
  double y; // fp6
  double v15; // fp5
  double v16; // fp20
  double v17; // fp30
  double v18; // fp2
  double v19; // fp18
  double v20; // fp1
  double v21; // fp31
  double v22; // fp16
  double v23; // fp24
  double v24; // fp0
  double v25; // fp28
  double v26; // fp25
  double v27; // fp23
  double v28; // fp17
  double v29; // fp19
  double v30; // fp21
  double v31; // fp11
  double v32; // fp3
  double v33; // fp11
  double v34; // fp0
  double v35; // fp8
  double v36; // fp12
  double v37; // fp10
  double v38; // fp29
  double v39; // fp31
  double v40; // fp24
  double v41; // fp9
  double v42; // fp27
  int v43; // r29
  double v44; // fp6
  double v45; // fp30
  const idVec3 *v46; // r30
  int i; // r28
  float v48; // [sp+50h] [-160h]
  float v49; // [sp+54h] [-15Ch]
  float v50; // [sp+54h] [-15Ch]
  float v51; // [sp+58h] [-158h]
  float v52; // [sp+58h] [-158h]
  float v53; // [sp+5Ch] [-154h]
  float v54; // [sp+60h] [-150h]
  float v55; // [sp+60h] [-150h]
  float v56; // [sp+64h] [-14Ch]
  float v57; // [sp+64h] [-14Ch]
  float v58; // [sp+68h] [-148h]
  float v59[12]; // [sp+70h] [-140h] BYREF
  float v60[48]; // [sp+A0h] [-110h] BYREF

  x = bounds->b[1].x;
  v49 = bounds->b[0].x;
  v53 = bounds->b[1].x;
  if ( v49 <= x )
  {
    z = axis->mat[0].z;
    v13 = axis->mat[1].x;
    y = bounds->b[0].y;
    v15 = axis->mat[0].y;
    v16 = (float)(axis->mat[1].x * bounds->b[0].y);
    v17 = axis->mat[1].z;
    v18 = axis->mat[0].x;
    v19 = (float)(axis->mat[0].z * bounds->b[1].x);
    v20 = axis->mat[1].y;
    v21 = bounds->b[1].y;
    v22 = (float)(axis->mat[0].y * bounds->b[1].x);
    v51 = bounds->b[0].y;
    v48 = bounds->b[0].x;
    v23 = (float)(axis->mat[0].z * v48);
    v25 = (float)(axis->mat[0].y * v48);
    v26 = axis->mat[2].x;
    v27 = axis->mat[2].y;
    v54 = v21;
    v28 = org->z;
    v29 = org->x;
    v30 = org->y;
    v31 = (float)(org->x
                + (float)((float)(axis->mat[2].x * bounds->b[0].z)
                        + (float)((float)(axis->mat[0].x * v48) + (float)(axis->mat[1].x * v51))));
    v24 = bounds->b[0].z;
    v56 = axis->mat[2].z;
    v59[4] = org->y
           + (float)((float)(axis->mat[2].y * bounds->b[0].z)
                   + (float)((float)(axis->mat[1].y * v51) + (float)(axis->mat[0].y * bounds->b[1].x)));
    v59[0] = v31;
    v32 = (float)((float)(v56 * (float)v24) + (float)((float)((float)v17 * (float)v21) + (float)((float)z * (float)x)));
    v59[2] = (float)v28 + (float)((float)(v56 * (float)v24) + (float)((float)((float)v17 * (float)y) + (float)v23));
    v59[3] = (float)v29
           + (float)((float)((float)v26 * (float)v24) + (float)((float)((float)v18 * (float)x) + (float)v16));
    v59[5] = (float)v28 + (float)((float)(v56 * (float)v24) + (float)((float)((float)v17 * (float)y) + (float)v19));
    v59[7] = (float)v30
           + (float)((float)((float)v27 * (float)v24) + (float)((float)((float)v20 * (float)v21) + (float)v22));
    v59[1] = (float)v30
           + (float)((float)((float)v27 * (float)v24) + (float)((float)((float)v20 * (float)y) + (float)v25));
    v33 = v24;
    v35 = (float)((float)((float)v18 * v48) + (float)((float)v13 * (float)v21));
    v36 = (float)((float)((float)v17 * (float)v21) + (float)((float)z * v48));
    v37 = v51;
    v59[6] = (float)v29
           + (float)((float)((float)v26 * (float)v24)
                   + (float)((float)((float)v18 * (float)x) + (float)((float)v13 * (float)v21)));
    v38 = v54;
    v55 = v29;
    v40 = v56;
    v41 = (float)((float)((float)v27 * (float)v24)
                + (float)((float)((float)v20 * (float)v21) + (float)((float)v15 * v48)));
    v34 = v49;
    v39 = v49;
    v58 = v32;
    v42 = bounds->b[1].z;
    v43 = 1;
    v44 = (float)((float)((float)v27 * bounds->b[1].z) + (float)((float)((float)v20 * v51) + (float)((float)v15 * v49)));
    v52 = v17;
    v45 = (float)((float)(v56 * bounds->b[1].z) + (float)((float)(v52 * (float)v37) + (float)((float)z * v49)));
    v50 = v30;
    v57 = v41;
    v59[9] = v55 + (float)((float)((float)v26 * (float)v33) + (float)v35);
    v60[1] = v50 + (float)v44;
    v59[8] = (float)v28 + v58;
    v59[10] = v50 + v57;
    v59[11] = (float)v28 + (float)((float)((float)v40 * (float)v33) + (float)v36);
    v60[2] = (float)v28 + (float)v45;
    v60[0] = v55
           + (float)((float)((float)v26 * (float)v42)
                   + (float)((float)((float)v18 * (float)v39) + (float)((float)v13 * (float)v37)));
    v60[4] = v50
           + (float)((float)((float)v27 * (float)v42)
                   + (float)((float)((float)v20 * (float)v37) + (float)((float)v15 * v53)));
    v60[3] = v55
           + (float)((float)((float)v26 * (float)v42)
                   + (float)((float)((float)v18 * v53) + (float)((float)v13 * (float)v37)));
    v60[5] = (float)v28
           + (float)((float)((float)v40 * (float)v42) + (float)((float)(v52 * (float)v37) + (float)((float)z * v53)));
    v60[7] = v50
           + (float)((float)((float)v27 * (float)v42)
                   + (float)((float)((float)v20 * (float)v38) + (float)((float)v15 * v53)));
    v60[6] = v55
           + (float)((float)((float)v26 * (float)v42)
                   + (float)((float)((float)v18 * v53) + (float)((float)v13 * (float)v38)));
    v60[8] = (float)v28
           + (float)((float)((float)v40 * (float)v42) + (float)((float)(v52 * (float)v38) + (float)((float)z * v53)));
    v60[10] = v50
            + (float)((float)((float)v27 * (float)v42)
                    + (float)((float)((float)v20 * (float)v38) + (float)((float)v15 * (float)v34)));
    v60[9] = v55
           + (float)((float)((float)v26 * (float)v42)
                   + (float)((float)((float)v18 * (float)v34) + (float)((float)v13 * (float)v38)));
    v60[11] = (float)v28
            + (float)((float)((float)v40 * (float)v42)
                    + (float)((float)(v52 * (float)v38) + (float)((float)z * (float)v34)));
    v46 = (const idVec3 *)v59;
    for ( i = 4; i != 0; --i )
    {
      this->DebugLine(
        this,
        a2: color,
        a3: v46,
        a4: (const idVec3 *)&v59[(v43 & 3) + ((2 * v43) & 6)],
        a5: lifetime,
        a6: depthTest);
      this->DebugLine(
        this,
        a2: color,
        a3: &v46[4],
        a4: (const idVec3 *)&v60[(v43 & 3) + ((2 * v43) & 6)],
        a5: lifetime,
        a6: depthTest);
      this->DebugLine(this, a2: color, a3: v46, a4: &v46[4], a5: lifetime, a6: depthTest);
      ++v43;
      ++v46;
    }
  }
}


// ========================================================================
// ?DebugBox@idRenderWorldLocal@@UAAXABVidVec4@@ABVidBox@@H_N@Z
// EA  : 0x8295FAC8
// RVA : 0x0095FAC8
// PDB : w:\tech5\engine\renderer\renderworld_debug.cpp
// ========================================================================

void __fastcall idRenderWorldLocal::DebugBox(
        idRenderWorldLocal *this,
        const idVec4 *color,
        idBox *box,
        int lifetime,
        BOOL depthTest)
{
  int v9; // r29
  idVec3 *v10; // r30
  int i; // r28
  idVec3 v12[14]; // [sp+50h] [-B0h] BYREF

  idBox::ToPoints(this: box, points: v12);
  v9 = 1;
  v10 = v12;
  for ( i = 4; i != 0; --i )
  {
    this->DebugLine(
      this,
      a2: color,
      a3: v10,
      a4: (idVec3 *)((char *)v12 + 4 * (v9 & 3) + 4 * ((2 * v9) & 6)),
      a5: lifetime,
      a6: depthTest);
    this->DebugLine(
      this,
      a2: color,
      a3: &v10[4],
      a4: (idVec3 *)((char *)&v12[4] + 4 * (v9 & 3) + 4 * ((2 * v9) & 6)),
      a5: lifetime,
      a6: depthTest);
    this->DebugLine(this, a2: color, a3: v10, a4: &v10[4], a5: lifetime, a6: depthTest);
    ++v9;
    ++v10;
  }
}


// ========================================================================
// ?DebugFrustum@idRenderWorldLocal@@UAAXABVidVec4@@ABVidFrustum@@_NH@Z
// EA  : 0x8295FBA8
// RVA : 0x0095FBA8
// PDB : w:\tech5\engine\renderer\renderworld_debug.cpp
// ========================================================================

void __fastcall idRenderWorldLocal::DebugFrustum(
        idRenderWorldLocal *this,
        const idVec4 *color,
        idFrustum *frustum,
        const bool showFromOrigin,
        int lifetime)
{
  int v10; // r11
  const idVec3 *v11; // r29
  int v12; // r30
  const idVec3 *v13; // r29
  int i; // r30
  int v15; // r11
  const idVec3 *v16; // r30
  int v17; // r29
  idVec3 v18[4]; // [sp+50h] [-A0h] BYREF
  _DWORD v19[28]; // [sp+80h] [-70h] BYREF

  idFrustum::ToPoints(this: frustum, points: v18);
  if ( frustum->dNear > 0.0 )
  {
    v10 = 0;
    v11 = v18;
    do
    {
      v12 = v10 + 1;
      this->DebugLine(
        this,
        a2: color,
        a3: v11,
        a4: (idVec3 *)((char *)v18 + 4 * ((v10 + 1) & 3) + 4 * ((2 * (v10 + 1)) & 6)),
        a5: lifetime,
        a6: false);
      v10 = v12;
      ++v11;
    }
    while ( v12 < 4 );
    if ( showFromOrigin )
    {
      v13 = v18;
      for ( i = 4; i != 0; --i )
        this->DebugLine(this, a2: color, a3: (const idVec3 *)frustum, a4: v13++, a5: lifetime, a6: false);
    }
  }
  v15 = 0;
  v16 = (const idVec3 *)v19;
  do
  {
    v17 = v15 + 1;
    this->DebugLine(
      this,
      a2: color,
      a3: v16,
      a4: (const idVec3 *)&v19[((v15 + 1) & 3) + ((2 * (v15 + 1)) & 6)],
      a5: lifetime,
      a6: false);
    this->DebugLine(this, a2: color, a3: &v16[-4], a4: v16, a5: lifetime, a6: false);
    v15 = v17;
    ++v16;
  }
  while ( v17 < 4 );
}


// ========================================================================
// ?DebugCone@idRenderWorldLocal@@UAAXABVidVec4@@ABVidVec3@@1MMH_N@Z
// EA  : 0x8295FD10
// RVA : 0x0095FD10
// PDB : w:\tech5\engine\renderer\renderworld_debug.cpp
// ========================================================================

void __fastcall idRenderWorldLocal::DebugCone(
        idRenderWorldLocal *this,
        const idVec4 *color,
        const idVec3 *apex,
        const idVec3 *dir,
        double radius1,
        double radius2,
        const int lifetime,
        const bool depthTest,
        int a9,
        BOOL a10)
{
  double y; // fp29
  double z; // fp28
  double x; // fp27
  double v22; // fp2
  double v23; // fp5
  double v24; // fp3
  double v25; // fp2
  double v26; // fp0
  __int64 v27; // r11
  double v28; // fp0
  int v29; // r26
  double v30; // fp13
  double v31; // fp26
  double v32; // fp12
  double v33; // fp25
  double v34; // fp24
  double v35; // fp28
  double v36; // fp27
  double v37; // fp29
  double v38; // fp30
  double v39; // fp23
  double v40; // fp22
  double v41; // fp21
  double v42; // fp11
  double v43; // fp1
  double v44; // fp21
  double v45; // fp20
  double v46; // fp19
  double v47; // fp1
  void (__fastcall *DebugLine)(idRenderWorld *, const idVec4 *, const idVec3 *, const idVec3 *, const int, const bool); // ctr
  double v49; // fp23
  double v50; // fp22
  double v51; // fp21
  double v52; // fp20
  double v53; // fp11
  double v54; // fp1
  double v55; // fp20
  double v56; // fp19
  double v57; // fp18
  double v58; // fp1
  double v59; // fp8
  void (__fastcall *v60)(idRenderWorld *, const idVec4 *, const idVec3 *, const idVec3 *, const int, const bool); // ctr
  double v61; // fp5
  float v62; // [sp+58h] [-138h] BYREF
  float v63; // [sp+5Ch] [-134h]
  float v64; // [sp+60h] [-130h]
  float v65; // [sp+68h] [-128h] BYREF
  float v66; // [sp+6Ch] [-124h]
  float v67; // [sp+70h] [-120h]
  float v68; // [sp+78h] [-118h] BYREF
  float v69; // [sp+7Ch] [-114h]
  float v70; // [sp+80h] [-110h]
  float v71; // [sp+88h] [-108h] BYREF
  float v72; // [sp+8Ch] [-104h]
  float v73; // [sp+90h] [-100h]
  float v74; // [sp+98h] [-F8h] BYREF
  float v75; // [sp+9Ch] [-F4h]
  float v76; // [sp+A0h] [-F0h]
  idVec3 v77; // [sp+B0h] [-E0h] BYREF
  idVec3 v78; // [sp+BCh] [-D4h] BYREF
  idVec3 v79; // [sp+C8h] [-C8h] BYREF

  y = dir->y;
  z = dir->z;
  x = dir->x;
  _FP5 = (float)((float)((float)(dir->x * dir->x) + (float)((float)(dir->z * dir->z) + (float)(dir->y * dir->y)))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f3, f5, f6, f13 }
  v22 = __frsqrte(_FP3);
  v23 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v22
                                                                                      * (float)((float)((float)(dir->x * dir->x) + (float)((float)(dir->z * dir->z) + (float)(dir->y * dir->y)))
                                                                                              * (float)0.5))
                                                                              * (float)v22)
                                                                      - (float)1.5)
                                                      * (float)v22)
                                              * (float)((float)((float)(dir->x * dir->x)
                                                              + (float)((float)(dir->z * dir->z)
                                                                      + (float)(dir->y * dir->y)))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v22
                                                                              * (float)((float)((float)(dir->x * dir->x)
                                                                                              + (float)((float)(dir->z * dir->z) + (float)(dir->y * dir->y)))
                                                                                      * (float)0.5))
                                                                      * (float)v22)
                                                              - (float)1.5)
                                              * (float)v22))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v22
                                                      * (float)((float)((float)(dir->x * dir->x)
                                                                      + (float)((float)(dir->z * dir->z)
                                                                              + (float)(dir->y * dir->y)))
                                                              * (float)0.5))
                                              * (float)v22)
                                      - (float)1.5)
                      * (float)v22));
  v24 = (float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v22 * (float)((float)((float)(dir->x * dir->x) + (float)((float)(dir->z * dir->z) + (float)(dir->y * dir->y))) * (float)0.5)) * (float)v22) - (float)1.5)
                                                                                      * (float)v22)
                                                                              * (float)((float)((float)(dir->x * dir->x)
                                                                                              + (float)((float)(dir->z * dir->z) + (float)(dir->y * dir->y)))
                                                                                      * (float)0.5))
                                                                      * (float)((float)-(float)((float)((float)((float)v22 * (float)((float)((float)(dir->x * dir->x) + (float)((float)(dir->z * dir->z) + (float)(dir->y * dir->y))) * (float)0.5)) * (float)v22)
                                                                                              - (float)1.5)
                                                                              * (float)v22))
                                                              - (float)1.5)
                                              * (float)((float)-(float)((float)((float)((float)v22
                                                                                      * (float)((float)((float)(dir->x * dir->x) + (float)((float)(dir->z * dir->z) + (float)(dir->y * dir->y)))
                                                                                              * (float)0.5))
                                                                              * (float)v22)
                                                                      - (float)1.5)
                                                      * (float)v22))
                                      * (float)((float)((float)(dir->x * dir->x)
                                                      + (float)((float)(dir->z * dir->z) + (float)(dir->y * dir->y)))
                                              * (float)0.5))
                              * (float)v23)
                      - (float)1.5);
  v25 = (float)((float)v24
              * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v22
                                                                                              * (float)((float)((float)(dir->x * dir->x) + (float)((float)(dir->z * dir->z) + (float)(dir->y * dir->y))) * (float)0.5))
                                                                                      * (float)v22)
                                                                              - (float)1.5)
                                                              * (float)v22)
                                                      * (float)((float)((float)(dir->x * dir->x)
                                                                      + (float)((float)(dir->z * dir->z)
                                                                              + (float)(dir->y * dir->y)))
                                                              * (float)0.5))
                                              * (float)((float)-(float)((float)((float)((float)v22
                                                                                      * (float)((float)((float)(dir->x * dir->x) + (float)((float)(dir->z * dir->z) + (float)(dir->y * dir->y)))
                                                                                              * (float)0.5))
                                                                              * (float)v22)
                                                                      - (float)1.5)
                                                      * (float)v22))
                                      - (float)1.5)
                      * (float)((float)-(float)((float)((float)((float)v22
                                                              * (float)((float)((float)(dir->x * dir->x)
                                                                              + (float)((float)(dir->z * dir->z)
                                                                                      + (float)(dir->y * dir->y)))
                                                                      * (float)0.5))
                                                      * (float)v22)
                                              - (float)1.5)
                              * (float)v22)));
  v26 = (float)(dir->y * (float)v25);
  v79.x = dir->x * (float)v25;
  v79.y = v26;
  v79.z = (float)z * (float)v25;
  idVec3::NormalVectors(this: &v79, left: &v77, down: &v78);
  v28 = apex->x;
  v29 = 20;
  v30 = apex->y;
  v31 = (float)(apex->x + (float)x);
  v32 = apex->z;
  v33 = (float)(apex->y + (float)y);
  v34 = (float)(apex->z + (float)z);
  v35 = -v78.y;
  v36 = -v78.z;
  v63 = (float)((float)v35 * (float)radius2) + (float)(apex->y + (float)y);
  v37 = -v78.x;
  v64 = (float)((float)v36 * (float)radius2) + (float)v34;
  v62 = (float)((float)v37 * (float)radius2) + (float)v31;
  if ( radius1 == 0.0 )
  {
    v38 = v77.z;
    v39 = v77.y;
    v40 = v77.x;
    do
    {
      LODWORD(v27) = v29;
      v41 = (float)v27;
      v42 = idMath::Cos16(a: (float)((float)v27 * idMath::M_DEG2RAD));
      v43 = (float)((float)v41 * idMath::M_DEG2RAD);
      v44 = (float)((float)v42 * (float)v37);
      v45 = (float)((float)v35 * (float)v42);
      v46 = (float)((float)v36 * (float)v42);
      v47 = idMath::Sin16(a: v43);
      DebugLine = this->DebugLine;
      v65 = (float)((float)((float)((float)v40 * (float)v47) + (float)v44) * (float)radius2) + (float)v31;
      v66 = (float)((float)((float)((float)v39 * (float)v47) + (float)v45) * (float)radius2) + (float)v33;
      v67 = (float)((float)((float)((float)v38 * (float)v47) + (float)v46) * (float)radius2) + (float)v34;
      DebugLine(this, a2: color, a3: (const idVec3 *)&v62, a4: (const idVec3 *)&v65, a5: a9, a6: a10);
      this->DebugLine(this, a2: color, a3: (const idVec3 *)&v65, a4: apex, a5: a9, a6: a10);
      v29 += 20;
      v62 = v65;
      v63 = v66;
      v64 = v67;
    }
    while ( v29 <= 360 );
  }
  else
  {
    v49 = v77.z;
    v50 = v77.y;
    v51 = v77.x;
    v74 = (float)v28 + (float)((float)v37 * (float)radius1);
    v75 = (float)v30 + (float)((float)v35 * (float)radius1);
    v76 = (float)v32 + (float)((float)v36 * (float)radius1);
    do
    {
      LODWORD(v27) = v29;
      v52 = (float)v27;
      v53 = idMath::Cos16(a: (float)((float)v27 * idMath::M_DEG2RAD));
      v54 = (float)((float)v52 * idMath::M_DEG2RAD);
      v55 = (float)((float)v53 * (float)v37);
      v56 = (float)((float)v35 * (float)v53);
      v57 = (float)((float)v36 * (float)v53);
      v58 = idMath::Sin16(a: v54);
      v59 = apex->z;
      v60 = this->DebugLine;
      v61 = (float)(apex->y + (float)((float)((float)((float)v50 * (float)v58) + (float)v56) * (float)radius1));
      v68 = apex->x + (float)((float)((float)((float)v51 * (float)v58) + (float)v55) * (float)radius1);
      v69 = v61;
      v70 = (float)v59 + (float)((float)((float)((float)v49 * (float)v58) + (float)v57) * (float)radius1);
      v71 = (float)((float)((float)((float)v51 * (float)v58) + (float)v55) * (float)radius2) + (float)v31;
      v72 = (float)((float)((float)((float)v50 * (float)v58) + (float)v56) * (float)radius2) + (float)v33;
      v73 = (float)((float)((float)((float)v49 * (float)v58) + (float)v57) * (float)radius2) + (float)v34;
      v60(this, a2: color, a3: (const idVec3 *)&v74, a4: (const idVec3 *)&v68, a5: a9, a6: a10);
      this->DebugLine(this, a2: color, a3: (const idVec3 *)&v62, a4: (const idVec3 *)&v71, a5: a9, a6: a10);
      this->DebugLine(this, a2: color, a3: (const idVec3 *)&v68, a4: (const idVec3 *)&v71, a5: a9, a6: a10);
      v29 += 20;
      v74 = v68;
      v75 = v69;
      v76 = v70;
      v62 = v71;
      v63 = v72;
      v64 = v73;
    }
    while ( v29 <= 360 );
  }
}


// ========================================================================
// ?DebugCone@idRenderWorldLocal@@UAAXABVidVec4@@ABVidVec3@@1MH_N@Z
// EA  : 0x829600F0
// RVA : 0x009600F0
// PDB : w:\tech5\engine\renderer\renderworld_debug.cpp
// ========================================================================

void __fastcall idRenderWorldLocal::DebugCone(
        idRenderWorldLocal *this,
        const idVec4 *color,
        const idVec3 *apex,
        const idVec3 *dir,
        double angle,
        const int lifetime,
        int depthTest,
        BOOL a8)
{
  double z; // fp10
  double v18; // fp3
  double v19; // fp6
  double v20; // fp4
  double v21; // fp3
  double v22; // fp1
  double v23; // fp31
  double v24; // fp30
  double v25; // fp29
  double v26; // fp28
  long double v27; // fp2
  long double v28; // fp2
  double v29; // fp24
  __int64 v30; // r11
  long double v31; // fp2
  int v32; // r31
  double v33; // fp25
  double v34; // fp27
  double v35; // fp26
  double v36; // fp9
  double v37; // fp31
  double v38; // fp24
  double y; // fp23
  double x; // fp22
  double v41; // fp21
  double v42; // fp11
  double v43; // fp1
  double v44; // fp21
  double v45; // fp20
  double v46; // fp19
  double v47; // fp1
  void (__fastcall *DebugLine)(idRenderWorld *, const idVec4 *, const idVec3 *, const idVec3 *, const int, const bool); // ctr
  float v49; // [sp+58h] [-F8h] BYREF
  float v50; // [sp+5Ch] [-F4h]
  float v51; // [sp+60h] [-F0h]
  float v52; // [sp+68h] [-E8h] BYREF
  float v53; // [sp+6Ch] [-E4h]
  float v54; // [sp+70h] [-E0h]
  idVec3 v55; // [sp+80h] [-D0h] BYREF
  idVec3 v56; // [sp+8Ch] [-C4h] BYREF
  idVec3 v57; // [sp+98h] [-B8h] BYREF

  z = dir->z;
  _FP6 = (float)((float)((float)(dir->x * dir->x) + (float)((float)(dir->z * dir->z) + (float)(dir->y * dir->y)))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f4, f6, f7, f13 }
  v18 = __frsqrte(_FP4);
  v19 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v18
                                                                                      * (float)((float)((float)(dir->x * dir->x) + (float)((float)(dir->z * dir->z) + (float)(dir->y * dir->y)))
                                                                                              * (float)0.5))
                                                                              * (float)v18)
                                                                      - (float)1.5)
                                                      * (float)v18)
                                              * (float)((float)((float)(dir->x * dir->x)
                                                              + (float)((float)(dir->z * dir->z)
                                                                      + (float)(dir->y * dir->y)))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v18
                                                                              * (float)((float)((float)(dir->x * dir->x)
                                                                                              + (float)((float)(dir->z * dir->z) + (float)(dir->y * dir->y)))
                                                                                      * (float)0.5))
                                                                      * (float)v18)
                                                              - (float)1.5)
                                              * (float)v18))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v18
                                                      * (float)((float)((float)(dir->x * dir->x)
                                                                      + (float)((float)(dir->z * dir->z)
                                                                              + (float)(dir->y * dir->y)))
                                                              * (float)0.5))
                                              * (float)v18)
                                      - (float)1.5)
                      * (float)v18));
  v20 = (float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v18 * (float)((float)((float)(dir->x * dir->x) + (float)((float)(dir->z * dir->z) + (float)(dir->y * dir->y))) * (float)0.5)) * (float)v18) - (float)1.5)
                                                                                      * (float)v18)
                                                                              * (float)((float)((float)(dir->x * dir->x)
                                                                                              + (float)((float)(dir->z * dir->z) + (float)(dir->y * dir->y)))
                                                                                      * (float)0.5))
                                                                      * (float)((float)-(float)((float)((float)((float)v18 * (float)((float)((float)(dir->x * dir->x) + (float)((float)(dir->z * dir->z) + (float)(dir->y * dir->y))) * (float)0.5)) * (float)v18)
                                                                                              - (float)1.5)
                                                                              * (float)v18))
                                                              - (float)1.5)
                                              * (float)((float)-(float)((float)((float)((float)v18
                                                                                      * (float)((float)((float)(dir->x * dir->x) + (float)((float)(dir->z * dir->z) + (float)(dir->y * dir->y)))
                                                                                              * (float)0.5))
                                                                              * (float)v18)
                                                                      - (float)1.5)
                                                      * (float)v18))
                                      * (float)((float)((float)(dir->x * dir->x)
                                                      + (float)((float)(dir->z * dir->z) + (float)(dir->y * dir->y)))
                                              * (float)0.5))
                              * (float)v19)
                      - (float)1.5);
  v21 = (float)((float)v20
              * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v18
                                                                                              * (float)((float)((float)(dir->x * dir->x) + (float)((float)(dir->z * dir->z) + (float)(dir->y * dir->y))) * (float)0.5))
                                                                                      * (float)v18)
                                                                              - (float)1.5)
                                                              * (float)v18)
                                                      * (float)((float)((float)(dir->x * dir->x)
                                                                      + (float)((float)(dir->z * dir->z)
                                                                              + (float)(dir->y * dir->y)))
                                                              * (float)0.5))
                                              * (float)((float)-(float)((float)((float)((float)v18
                                                                                      * (float)((float)((float)(dir->x * dir->x) + (float)((float)(dir->z * dir->z) + (float)(dir->y * dir->y)))
                                                                                              * (float)0.5))
                                                                              * (float)v18)
                                                                      - (float)1.5)
                                                      * (float)v18))
                                      - (float)1.5)
                      * (float)((float)-(float)((float)((float)((float)v18
                                                              * (float)((float)((float)(dir->x * dir->x)
                                                                              + (float)((float)(dir->z * dir->z)
                                                                                      + (float)(dir->y * dir->y)))
                                                                      * (float)0.5))
                                                      * (float)v18)
                                              - (float)1.5)
                              * (float)v18)));
  v22 = (float)(dir->y * (float)v21);
  v57.x = dir->x * (float)v21;
  v57.y = v22;
  v57.z = (float)z * (float)v21;
  idVec3::NormalVectors(this: &v57, left: &v55, down: &v56);
  v23 = (float)((float)angle * (float)0.5);
  v25 = -v56.y;
  v26 = -v56.z;
  *(double *)&v27 = v23;
  v24 = -v56.x;
  v28 = sin(x: v27);
  v29 = (float)*(double *)&v28;
  *(double *)&v28 = v23;
  v31 = cos(x: v28);
  v32 = 20;
  v33 = (float)(apex->z + (float)((float)*(double *)&v31 * dir->z));
  v34 = (float)(apex->x + (float)(dir->x * (float)*(double *)&v31));
  v35 = (float)(apex->y + (float)(dir->y * (float)*(double *)&v31));
  v36 = __fsqrts((float)((float)(dir->x * dir->x) + (float)((float)(dir->y * dir->y) + (float)(dir->z * dir->z))));
  v37 = (float)((float)v36 * (float)v29);
  v52 = (float)((float)v24 * (float)((float)v36 * (float)v29))
      + (float)(apex->x + (float)(dir->x * (float)*(double *)&v31));
  y = v55.y;
  x = v55.x;
  v53 = (float)((float)v25 * (float)((float)v36 * (float)v29)) + (float)v35;
  v54 = (float)((float)v26 * (float)((float)v36 * (float)v29)) + (float)v33;
  v38 = v55.z;
  do
  {
    LODWORD(v30) = v32;
    v41 = (float)v30;
    v42 = idMath::Cos16(a: (float)((float)v30 * idMath::M_DEG2RAD));
    v43 = (float)((float)v41 * idMath::M_DEG2RAD);
    v44 = (float)((float)v42 * (float)v24);
    v45 = (float)((float)v25 * (float)v42);
    v46 = (float)((float)v26 * (float)v42);
    v47 = idMath::Sin16(a: v43);
    DebugLine = this->DebugLine;
    v49 = (float)((float)((float)((float)x * (float)v47) + (float)v44) * (float)v37) + (float)v34;
    v50 = (float)((float)((float)((float)y * (float)v47) + (float)v45) * (float)v37) + (float)v35;
    v51 = (float)((float)((float)((float)v38 * (float)v47) + (float)v46) * (float)v37) + (float)v33;
    DebugLine(this, a2: color, a3: (const idVec3 *)&v52, a4: (const idVec3 *)&v49, a5: depthTest, a6: a8);
    this->DebugLine(this, a2: color, a3: (const idVec3 *)&v49, a4: apex, a5: depthTest, a6: a8);
    v32 += 20;
    v52 = v49;
    v53 = v50;
    v54 = v51;
  }
  while ( v32 <= 360 );
}


// ========================================================================
// ?DebugAxis@idRenderWorldLocal@@UAAXABVidVec3@@ABVidMat3@@H_N@Z
// EA  : 0x82960368
// RVA : 0x00960368
// PDB : w:\tech5\engine\renderer\renderworld_debug.cpp
// ========================================================================

void __fastcall idRenderWorldLocal::DebugAxis(
        idRenderWorldLocal *this,
        const idVec3 *origin,
        const idMat3 *axis,
        int lifeTime,
        int depthTest)
{
  float z; // r11
  double x; // fp0
  double y; // fp13
  float v8; // r9
  double v9; // fp12
  idRenderWorldLocal_vtbl *v11; // r7
  void (__fastcall *DebugArrow)(idRenderWorld *, const idVec4 *, const idVec3 *, const idVec3 *, float, const int, const bool); // ctr
  double v15; // fp10
  void (__fastcall *v16)(idRenderWorld *, const idVec4 *, const idVec3 *, const idVec3 *, float, const int, const bool); // r7
  double v17; // fp5
  void (__fastcall *v18)(idRenderWorld *, const idVec4 *, const idVec3 *, const idVec3 *, float, const int, const bool); // r10
  double v19; // fp6
  double v20; // fp5
  float v21; // [sp+50h] [-60h] BYREF
  float v22; // [sp+54h] [-5Ch]
  float v23; // [sp+58h] [-58h]
  float v24; // [sp+60h] [-50h] BYREF
  float v25; // [sp+64h] [-4Ch]
  float v26; // [sp+68h] [-48h]

  z = origin->z;
  x = axis->mat[0].x;
  y = axis->mat[0].y;
  v8 = origin->x;
  v9 = axis->mat[0].z;
  v11 = this->__vftable;
  v22 = origin->y;
  v23 = z;
  v21 = v8;
  DebugArrow = v11->DebugArrow;
  v24 = v8 + (float)((float)x * (float)16.0);
  v25 = v22 + (float)((float)y * (float)16.0);
  v26 = z + (float)((float)v9 * (float)16.0);
  ((void (__fastcall *)(idRenderWorldLocal *, idColor *, float *, float *, idRenderWorldLocal_vtbl *, int, int, double))DebugArrow)(
    a1: this,
    a2: &idColor::colorRed,
    a3: &v21,
    a4: &v24,
    a5: v11,
    a6: lifeTime,
    a7: depthTest,
    a8: 2.0);
  v15 = (float)(axis->mat[1].z * (float)16.0);
  v16 = this->DebugArrow;
  v17 = (float)((float)(axis->mat[1].y * (float)16.0) + v22);
  v24 = (float)(axis->mat[1].x * (float)16.0) + v21;
  v25 = v17;
  v26 = (float)v15 + v23;
  ((void (__fastcall *)(idRenderWorldLocal *, idColor *, float *, float *, double))v16)(
    a1: this,
    a2: &idColor::colorGreen,
    a3: &v21,
    a4: &v24,
    a5: 2.0);
  v18 = this->DebugArrow;
  v19 = (float)((float)(axis->mat[2].y * (float)16.0) + v22);
  v20 = (float)((float)(axis->mat[2].z * (float)16.0) + v23);
  v24 = (float)(axis->mat[2].x * (float)16.0) + v21;
  v25 = v19;
  v26 = v20;
  ((void (__fastcall *)(idRenderWorldLocal *, idColor *, float *, float *, double))v18)(
    a1: this,
    a2: &idColor::colorBlue,
    a3: &v21,
    a4: &v24,
    a5: 2.0);
}


// ========================================================================
// ?DebugAxis@idRenderWorldLocal@@UAAXABVidVec4@@ABVidVec3@@ABVidMat3@@H_N@Z
// EA  : 0x82960508
// RVA : 0x00960508
// PDB : w:\tech5\engine\renderer\renderworld_debug.cpp
// ========================================================================

void __fastcall idRenderWorldLocal::DebugAxis(
        idRenderWorldLocal *this,
        const idVec4 *color,
        const idVec3 *origin,
        const idMat3 *axis,
        int lifeTime,
        bool depthTest)
{
  float z; // r11
  double x; // fp0
  float v8; // r9
  double y; // fp13
  double v11; // fp12
  idRenderWorldLocal_vtbl *v12; // r7
  void (__fastcall *DebugArrow)(idRenderWorld *, const idVec4 *, const idVec3 *, const idVec3 *, float, const int, const bool); // ctr
  double v17; // fp10
  void (__fastcall *v18)(idRenderWorld *, const idVec4 *, const idVec3 *, const idVec3 *, float, const int, const bool); // r10
  double v19; // fp5
  idRenderWorldLocal_vtbl *v20; // r7
  double v21; // fp6
  double v22; // fp5
  float v23; // [sp+50h] [-60h] BYREF
  float v24; // [sp+54h] [-5Ch]
  float v25; // [sp+58h] [-58h]
  float v26; // [sp+60h] [-50h] BYREF
  float v27; // [sp+64h] [-4Ch]
  float v28; // [sp+68h] [-48h]

  z = origin->z;
  x = axis->mat[0].x;
  v8 = origin->x;
  y = axis->mat[0].y;
  v11 = axis->mat[0].z;
  v12 = this->__vftable;
  v24 = origin->y;
  v25 = z;
  v23 = v8;
  DebugArrow = v12->DebugArrow;
  v26 = v8 + (float)((float)x * (float)16.0);
  v27 = v24 + (float)((float)y * (float)16.0);
  v28 = z + (float)((float)v11 * (float)16.0);
  ((void (__fastcall *)(idRenderWorldLocal *, const idVec4 *, float *, float *, idRenderWorldLocal_vtbl *, int, bool, double))DebugArrow)(
    a1: this,
    a2: color,
    a3: &v23,
    a4: &v26,
    a5: v12,
    a6: lifeTime,
    a7: depthTest,
    a8: 2.0);
  v17 = (float)(axis->mat[1].z * (float)16.0);
  v18 = this->DebugArrow;
  v19 = (float)((float)(axis->mat[1].y * (float)16.0) + v24);
  v26 = (float)(axis->mat[1].x * (float)16.0) + v23;
  v27 = v19;
  v28 = (float)v17 + v25;
  ((void (__fastcall *)(idRenderWorldLocal *, const idVec4 *, float *, float *, double))v18)(
    a1: this,
    a2: color,
    a3: &v23,
    a4: &v26,
    a5: 2.0);
  v20 = this->__vftable;
  v21 = (float)((float)(axis->mat[2].y * (float)16.0) + v24);
  v22 = (float)((float)(axis->mat[2].z * (float)16.0) + v25);
  v26 = (float)(axis->mat[2].x * (float)16.0) + v23;
  v27 = v21;
  v28 = v22;
  ((void (__fastcall *)(idRenderWorldLocal *, const idVec4 *, float *, float *, double))v20->DebugArrow)(
    a1: this,
    a2: color,
    a3: &v23,
    a4: &v26,
    a5: 2.0);
}


// ========================================================================
// ?DebugAxisScaled@idRenderWorldLocal@@UAAXABVidVec3@@ABVidMat3@@MH_N@Z
// EA  : 0x82960698
// RVA : 0x00960698
// PDB : w:\tech5\engine\renderer\renderworld_debug.cpp
// ========================================================================

void __fastcall idRenderWorldLocal::DebugAxisScaled(
        idRenderWorldLocal *this,
        const idVec3 *origin,
        const idMat3 *axis,
        double scale,
        const int time,
        int depthTest,
        BOOL a7)
{
  double v7; // fp10
  double v8; // fp9
  double y; // fp7
  double z; // fp6
  void (__fastcall *DebugLine)(idRenderWorld *, const idVec4 *, const idVec3 *, const idVec3 *, const int, const bool); // r10
  double x; // fp5
  double v13; // fp4
  double v15; // fp3
  double v16; // fp2
  double v17; // fp0
  double v20; // fp31
  double v22; // fp30
  double v23; // fp29
  double v24; // fp28
  double v25; // fp27
  double v26; // fp26
  double v27; // fp5
  double v28; // fp4
  idRenderWorldLocal_vtbl *v29; // r11
  double v30; // fp13
  double v31; // fp12
  idRenderWorldLocal_vtbl *v32; // r3
  float v33[4]; // [sp+50h] [-90h] BYREF
  float v34[4]; // [sp+60h] [-80h] BYREF
  float v35[18]; // [sp+70h] [-70h] BYREF

  v7 = (float)(axis->mat[0].y * (float)scale);
  v8 = (float)(axis->mat[0].z * (float)scale);
  y = origin->y;
  z = origin->z;
  DebugLine = this->DebugLine;
  x = axis->mat[1].x;
  v13 = axis->mat[1].y;
  v15 = axis->mat[1].z;
  v16 = axis->mat[2].x;
  v17 = axis->mat[2].y;
  v33[0] = origin->x + (float)(axis->mat[0].x * (float)scale);
  v33[1] = (float)y + (float)v7;
  v33[2] = (float)z + (float)v8;
  v20 = (float)((float)x * (float)scale);
  v22 = (float)((float)v13 * (float)scale);
  v23 = (float)((float)v15 * (float)scale);
  v24 = (float)((float)scale * (float)v16);
  v25 = (float)((float)v17 * (float)scale);
  v26 = (float)(axis->mat[2].z * (float)scale);
  ((void (__fastcall *)(idRenderWorldLocal *, idColor *, const idVec3 *, float *))DebugLine)(
    a1: this,
    a2: &idColor::colorRed,
    a3: origin,
    a4: v33);
  v27 = (float)(origin->y + (float)v22);
  v28 = (float)(origin->z + (float)v23);
  v34[0] = origin->x + (float)v20;
  v34[1] = v27;
  v29 = this->__vftable;
  v34[2] = v28;
  v29->DebugLine(
    this,
    a2: (const idVec4 *)&idColor::colorGreen,
    a3: origin,
    a4: (const idVec3 *)v34,
    a5: depthTest,
    a6: a7);
  v30 = (float)(origin->y + (float)v25);
  v31 = (float)(origin->z + (float)v26);
  v35[0] = origin->x + (float)v24;
  v35[1] = v30;
  v32 = this->__vftable;
  v35[2] = v31;
  v32->DebugLine(
    this,
    a2: (const idVec4 *)&idColor::colorBlue,
    a3: origin,
    a4: (const idVec3 *)v35,
    a5: depthTest,
    a6: a7);
}


// ========================================================================
// ?DebugPoint@idRenderWorldLocal@@UAAXABVidVec4@@ABVidVec3@@H_N@Z
// EA  : 0x82960800
// RVA : 0x00960800
// PDB : w:\tech5\engine\renderer\renderworld_debug.cpp
// ========================================================================

void __fastcall idRenderWorldLocal::DebugPoint(
        idRenderWorldLocal *this,
        const idVec4 *color,
        const idVec3 *origin,
        int lifeTime,
        BOOL depthTest)
{
  double x; // fp0
  double y; // fp13
  idRenderWorldLocal_vtbl *v7; // r10
  double z; // fp12
  void (__fastcall *DebugLine)(idRenderWorld *, const idVec4 *, const idVec3 *, const idVec3 *, const int, const bool); // ctr
  double v15; // fp7
  double v16; // fp6
  double v17; // fp5
  idRenderWorldLocal_vtbl *v18; // r11
  double v19; // fp2
  double v20; // fp1
  double v21; // fp0
  idRenderWorldLocal_vtbl *v22; // r9
  float v23[4]; // [sp+50h] [-A0h] BYREF
  float v24[4]; // [sp+60h] [-90h] BYREF
  float v25[4]; // [sp+70h] [-80h] BYREF
  float v26[4]; // [sp+80h] [-70h] BYREF
  float v27[4]; // [sp+90h] [-60h] BYREF
  float v28[6]; // [sp+A0h] [-50h] BYREF

  x = origin->x;
  y = origin->y;
  v7 = this->__vftable;
  z = origin->z;
  v23[2] = origin->z;
  v23[1] = y;
  v23[0] = (float)x + (float)8.0;
  v24[0] = (float)x - (float)8.0;
  v24[1] = y;
  DebugLine = v7->DebugLine;
  v24[2] = z;
  DebugLine(this, a2: color, a3: (const idVec3 *)v24, a4: (const idVec3 *)v23, a5: lifeTime, a6: depthTest);
  v15 = (float)(origin->y + (float)8.0);
  v16 = origin->z;
  v17 = (float)(origin->y - (float)8.0);
  v25[0] = origin->x;
  v18 = this->__vftable;
  v25[1] = v15;
  v25[2] = v16;
  v26[0] = v25[0];
  v26[1] = v17;
  v26[2] = v16;
  v18->DebugLine(this, a2: color, a3: (const idVec3 *)v26, a4: (const idVec3 *)v25, a5: lifeTime, a6: depthTest);
  v19 = (float)(origin->z + (float)8.0);
  v20 = origin->y;
  v21 = (float)(origin->z - (float)8.0);
  v27[0] = origin->x;
  v22 = this->__vftable;
  v27[1] = v20;
  v27[2] = v19;
  v28[0] = v27[0];
  v28[1] = v20;
  v28[2] = v21;
  v22->DebugLine(this, a2: color, a3: (const idVec3 *)v28, a4: (const idVec3 *)v27, a5: lifeTime, a6: depthTest);
}


// ========================================================================
// ?DrawTextLength@idRenderWorldLocal@@QBAMPBDMH@Z
// EA  : 0x82960930
// RVA : 0x00960930
// PDB : w:\tech5\engine\renderer\renderworld_debug.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
float __fastcall idRenderWorldLocal::DrawTextLength(
        idRenderWorldLocal *this,
        const char *text,
        double scale,
        int len,
        int a5)
{
  int v5; // r2 OVERLAPPED
  double v7; // fp1
  int v8; // r11
  int i; // r5
  unsigned int v10; // r10
  int v11; // r7
  int v12; // r11
  int v13; // r3 OVERLAPPED
  unsigned int v14; // r9
  int v15; // r10

  v7 = 0.0;
  if ( text != nullptr && *text != 0 )
  {
    if ( a5 == 0 )
    {
      v8 = 0;
      do
        ++v8;
      while ( text[v8] != 0 );
      a5 = v8;
    }
    for ( i = 0; i < a5; ++i )
    {
      v10 = text[i] - 32;
      if ( v10 < 0x60 )
      {
        v11 = 2 * simplex[v10][0];
        v12 = 2;
        v13 = simplex[v10][1];
        if ( v11 > 0 )
        {
          v14 = v10;
          v15 = 0;
          do
          {
            if ( simplex[v14][v12] >= 0 )
            {
              v12 += 2;
              v15 += 2;
              if ( simplex[v14][v12] >= 0 )
                continue;
            }
            ++v15;
            ++v12;
          }
          while ( v15 < v11 );
        }
        v7 = (float)((float)((float)*(__int64 *)(&v5 - 1) * (float)scale) + (float)v7);
      }
    }
  }
  return *((float *)&v7 + 1);
}


// ========================================================================
// ?DebugArrow@idRenderWorldLocal@@UAAXABVidVec4@@ABVidVec3@@1MH_N@Z
// EA  : 0x82961020
// RVA : 0x00961020
// PDB : w:\tech5\engine\renderer\renderworld_debug.cpp
// ========================================================================

void __fastcall idRenderWorldLocal::DebugArrow(
        idRenderWorldLocal *this,
        const idVec4 *color,
        const idVec3 *start,
        const idVec3 *end,
        double size,
        const int lifetime,
        int depthTest,
        BOOL a8)
{
  double y; // fp25
  double v16; // fp12
  double x; // fp24
  double z; // fp23
  double v19; // fp8
  double v22; // fp1
  double v23; // fp4
  double v24; // fp2
  double v25; // fp1
  double v26; // fp29
  double v27; // fp28
  double v28; // fp27
  double v29; // fp22
  double v30; // fp21
  double v31; // fp30
  double v32; // fp28
  double v33; // fp27
  double v34; // fp31
  double v35; // fp26
  double v36; // fp12
  double v37; // fp11
  idVec3 v38; // [sp+58h] [-E8h] BYREF
  idVec3 v39; // [sp+68h] [-D8h] BYREF
  idVec3 v40[2]; // [sp+78h] [-C8h] BYREF
  idWinding v41[7]; // [sp+90h] [-B0h] BYREF

  ((void (__fastcall *)(idRenderWorldLocal *))this->DebugLine)(a1: this);
  if ( r_debugArrowStep.valueInteger > 10 )
  {
    y = end->y;
    v16 = (float)(end->y - start->y);
    x = end->x;
    z = end->z;
    v19 = (float)(end->z - start->z);
    _FP4 = (float)((float)((float)((float)v19 * (float)v19)
                         + (float)((float)((float)(end->x - start->x) * (float)(end->x - start->x))
                                 + (float)((float)v16 * (float)v16)))
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm { fsel      f2, f4, f5, f13 }
    v22 = __frsqrte(_FP2);
    v23 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v22
                                                                                        * (float)((float)((float)((float)v19 * (float)v19) + (float)((float)((float)(end->x - start->x) * (float)(end->x - start->x)) + (float)((float)v16 * (float)v16)))
                                                                                                * (float)0.5))
                                                                                * (float)v22)
                                                                        - (float)1.5)
                                                        * (float)v22)
                                                * (float)((float)((float)((float)v19 * (float)v19)
                                                                + (float)((float)((float)(end->x - start->x)
                                                                                * (float)(end->x - start->x))
                                                                        + (float)((float)v16 * (float)v16)))
                                                        * (float)0.5))
                                        * (float)((float)-(float)((float)((float)((float)v22
                                                                                * (float)((float)((float)((float)v19 * (float)v19)
                                                                                                + (float)((float)((float)(end->x - start->x) * (float)(end->x - start->x)) + (float)((float)v16 * (float)v16)))
                                                                                        * (float)0.5))
                                                                        * (float)v22)
                                                                - (float)1.5)
                                                * (float)v22))
                                - (float)1.5)
                * (float)((float)-(float)((float)((float)((float)v22
                                                        * (float)((float)((float)((float)v19 * (float)v19)
                                                                        + (float)((float)((float)(end->x - start->x)
                                                                                        * (float)(end->x - start->x))
                                                                                + (float)((float)v16 * (float)v16)))
                                                                * (float)0.5))
                                                * (float)v22)
                                        - (float)1.5)
                        * (float)v22));
    v24 = (float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v22 * (float)((float)((float)((float)v19 * (float)v19) + (float)((float)((float)(end->x - start->x) * (float)(end->x - start->x)) + (float)((float)v16 * (float)v16))) * (float)0.5)) * (float)v22) - (float)1.5)
                                                                                        * (float)v22)
                                                                                * (float)((float)((float)((float)v19 * (float)v19)
                                                                                                + (float)((float)((float)(end->x - start->x) * (float)(end->x - start->x)) + (float)((float)v16 * (float)v16)))
                                                                                        * (float)0.5))
                                                                        * (float)((float)-(float)((float)((float)((float)v22 * (float)((float)((float)((float)v19 * (float)v19) + (float)((float)((float)(end->x - start->x) * (float)(end->x - start->x)) + (float)((float)v16 * (float)v16))) * (float)0.5)) * (float)v22)
                                                                                                - (float)1.5)
                                                                                * (float)v22))
                                                                - (float)1.5)
                                                * (float)((float)-(float)((float)((float)((float)v22
                                                                                        * (float)((float)((float)((float)v19 * (float)v19) + (float)((float)((float)(end->x - start->x) * (float)(end->x - start->x)) + (float)((float)v16 * (float)v16)))
                                                                                                * (float)0.5))
                                                                                * (float)v22)
                                                                        - (float)1.5)
                                                        * (float)v22))
                                        * (float)((float)((float)((float)v19 * (float)v19)
                                                        + (float)((float)((float)(end->x - start->x)
                                                                        * (float)(end->x - start->x))
                                                                + (float)((float)v16 * (float)v16)))
                                                * (float)0.5))
                                * (float)v23)
                        - (float)1.5);
    v25 = (float)((float)v24
                * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v22
                                                                                                * (float)((float)((float)((float)v19 * (float)v19) + (float)((float)((float)(end->x - start->x) * (float)(end->x - start->x)) + (float)((float)v16 * (float)v16))) * (float)0.5))
                                                                                        * (float)v22)
                                                                                - (float)1.5)
                                                                * (float)v22)
                                                        * (float)((float)((float)((float)v19 * (float)v19)
                                                                        + (float)((float)((float)(end->x - start->x)
                                                                                        * (float)(end->x - start->x))
                                                                                + (float)((float)v16 * (float)v16)))
                                                                * (float)0.5))
                                                * (float)((float)-(float)((float)((float)((float)v22
                                                                                        * (float)((float)((float)((float)v19 * (float)v19) + (float)((float)((float)(end->x - start->x) * (float)(end->x - start->x)) + (float)((float)v16 * (float)v16)))
                                                                                                * (float)0.5))
                                                                                * (float)v22)
                                                                        - (float)1.5)
                                                        * (float)v22))
                                        - (float)1.5)
                        * (float)((float)-(float)((float)((float)((float)v22
                                                                * (float)((float)((float)((float)v19 * (float)v19)
                                                                                + (float)((float)((float)(end->x - start->x)
                                                                                                * (float)(end->x - start->x))
                                                                                        + (float)((float)v16 * (float)v16)))
                                                                        * (float)0.5))
                                                        * (float)v22)
                                                - (float)1.5)
                                * (float)v22)));
    v26 = (float)((float)(end->x - start->x) * (float)v25);
    v27 = (float)((float)(end->y - start->y) * (float)v25);
    v38.x = (float)(end->x - start->x) * (float)v25;
    v38.y = (float)v16 * (float)v25;
    v28 = (float)((float)v19 * (float)v25);
    v38.z = (float)v19 * (float)v25;
    idVec3::NormalVectors(this: &v38, left: &v39, down: v40);
    v41[0].allocedSize = 0;
    v41[0].__vftable = (idWinding_vtbl *)&idWinding::`vftable';
    v41[0].numPoints = 0;
    v41[0].p = nullptr;
    v29 = (float)((float)size * (float)0.5);
    v30 = (float)((float)v28 * (float)size);
    v31 = v39.z;
    v32 = (float)((float)v27 * (float)size);
    v35 = v39.x;
    v39.z = (float)((float)z - (float)((float)v28 * (float)size)) + (float)((float)((float)size * (float)0.5) * v39.z);
    v33 = v39.y;
    v39.y = (float)((float)y - (float)v32) + (float)((float)((float)size * (float)0.5) * v39.y);
    v34 = (float)((float)v26 * (float)size);
    v39.x = (float)((float)x - (float)v34) + (float)((float)v29 * v39.x);
    idWinding::AddPoint(this: v41, v: &v39);
    idWinding::AddPoint(this: v41, v: end);
    v36 = (float)(end->y - (float)v32);
    v37 = (float)(end->x - (float)v34);
    v39.z = (float)(end->z - (float)v30) - (float)((float)v29 * (float)v31);
    v39.y = (float)v36 - (float)((float)v29 * (float)v33);
    v39.x = (float)v37 - (float)((float)v29 * (float)v35);
    idWinding::AddPoint(this: v41, v: &v39);
    this->DebugFilledPolygon(this, a2: color, a3: v41, a4: depthTest, a5: a8);
    v41[0].__vftable = (idWinding_vtbl *)&idWinding::`vftable';
    idMem::Free(this: &mem, ptr: v41[0].p, align: ALIGN_16);
  }
}


// ========================================================================
// __unwind$235473
// EA  : 0x8296124C
// RVA : 0x0096124C
// PDB : w:\tech5\engine\renderer\renderworld_debug.cpp
// ========================================================================

void _unwind_235473()
{
  int v0; // r12

  idWinding::~idWinding(this: (idWinding *)(v0 - 320 + 144));
}


// ========================================================================
// ?DebugArrow2@idRenderWorldLocal@@UAAXABVidVec4@@ABVidVec3@@1MH_N1@Z
// EA  : 0x82961280
// RVA : 0x00961280
// PDB : w:\tech5\engine\renderer\renderworld_debug.cpp
// ========================================================================

void __fastcall idRenderWorldLocal::DebugArrow2(
        idRenderWorldLocal *this,
        const idVec4 *color,
        const idVec3 *start,
        const idVec3 *end,
        double size,
        const int lifetime,
        int depthTest,
        const idVec3 *camPos,
        float *a9)
{
  double y; // fp11
  double v18; // fp9
  double x; // fp8
  double v20; // fp1
  double v21; // fp6
  double z; // fp5
  double v23; // fp3
  double v24; // fp7
  double v25; // fp10
  double v28; // fp4
  double v29; // fp2
  double v30; // fp2
  double v31; // fp4
  double v32; // fp3
  double v33; // fp2
  double v34; // fp9
  double v35; // fp7
  double v36; // fp6
  double v39; // fp13
  double v40; // fp10
  double v41; // fp13
  double v42; // fp30
  double v43; // fp29
  double v44; // fp28
  double v45; // fp27
  double v46; // fp26
  double v47; // fp25
  double v48; // fp31
  double v49; // fp9
  double v50; // fp8
  double v51; // fp7
  idVec3 v52; // [sp+50h] [-A0h] BYREF
  idWinding v53[4]; // [sp+60h] [-90h] BYREF

  ((void (__fastcall *)(idRenderWorldLocal *))this->DebugLine)(a1: this);
  if ( r_debugArrowStep.valueInteger > 10 )
  {
    y = end->y;
    v18 = (float)(end->y - start->y);
    x = end->x;
    v20 = (float)(end->x - *a9);
    v21 = (float)(end->x - start->x);
    z = end->z;
    v23 = (float)(end->z - start->z);
    v24 = (float)(end->z - a9[2]);
    v25 = (float)(end->y - a9[1]);
    v53[0].allocedSize = 0;
    v53[0].__vftable = (idWinding_vtbl *)&idWinding::`vftable';
    v53[0].numPoints = 0;
    v53[0].p = nullptr;
    _FP4 = (float)((float)((float)((float)v23 * (float)v23)
                         + (float)((float)((float)v21 * (float)v21) + (float)((float)v18 * (float)v18)))
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm { fsel      f2, f4, f2, f13 }
    v28 = __frsqrte(_FP2);
    v29 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v28
                                                                                        * (float)((float)((float)((float)v23 * (float)v23) + (float)((float)((float)v21 * (float)v21) + (float)((float)v18 * (float)v18)))
                                                                                                * (float)0.5))
                                                                                * (float)v28)
                                                                        - (float)1.5)
                                                        * (float)v28)
                                                * (float)((float)((float)((float)v23 * (float)v23)
                                                                + (float)((float)((float)v21 * (float)v21)
                                                                        + (float)((float)v18 * (float)v18)))
                                                        * (float)0.5))
                                        * (float)((float)-(float)((float)((float)((float)v28
                                                                                * (float)((float)((float)((float)v23 * (float)v23)
                                                                                                + (float)((float)((float)v21 * (float)v21) + (float)((float)v18 * (float)v18)))
                                                                                        * (float)0.5))
                                                                        * (float)v28)
                                                                - (float)1.5)
                                                * (float)v28))
                                - (float)1.5)
                * (float)((float)-(float)((float)((float)((float)v28
                                                        * (float)((float)((float)((float)v23 * (float)v23)
                                                                        + (float)((float)((float)v21 * (float)v21)
                                                                                + (float)((float)v18 * (float)v18)))
                                                                * (float)0.5))
                                                * (float)v28)
                                        - (float)1.5)
                        * (float)v28));
    v30 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v28 * (float)((float)((float)((float)v23 * (float)v23) + (float)((float)((float)v21 * (float)v21) + (float)((float)v18 * (float)v18))) * (float)0.5)) * (float)v28) - (float)1.5)
                                                                                                * (float)v28)
                                                                                        * (float)((float)((float)((float)v23 * (float)v23) + (float)((float)((float)v21 * (float)v21) + (float)((float)v18 * (float)v18)))
                                                                                                * (float)0.5))
                                                                                * (float)((float)-(float)((float)((float)((float)v28 * (float)((float)((float)((float)v23 * (float)v23) + (float)((float)((float)v21 * (float)v21) + (float)((float)v18 * (float)v18))) * (float)0.5)) * (float)v28) - (float)1.5)
                                                                                        * (float)v28))
                                                                        - (float)1.5)
                                                        * (float)((float)-(float)((float)((float)((float)v28
                                                                                                * (float)((float)((float)((float)v23 * (float)v23) + (float)((float)((float)v21 * (float)v21) + (float)((float)v18 * (float)v18))) * (float)0.5))
                                                                                        * (float)v28)
                                                                                - (float)1.5)
                                                                * (float)v28))
                                                * (float)((float)((float)((float)v23 * (float)v23)
                                                                + (float)((float)((float)v21 * (float)v21)
                                                                        + (float)((float)v18 * (float)v18)))
                                                        * (float)0.5))
                                        * (float)v29)
                                - (float)1.5)
                * (float)v29);
    v31 = (float)((float)v23 * (float)v30);
    v32 = (float)((float)v18 * (float)v30);
    v33 = (float)((float)v21 * (float)v30);
    v34 = (float)((float)((float)v24 * (float)v33) - (float)((float)v31 * (float)v20));
    v35 = (float)((float)((float)v31 * (float)v25) - (float)((float)v32 * (float)v24));
    v36 = (float)((float)((float)v32 * (float)v20) - (float)((float)v25 * (float)v33));
    _FP10 = (float)((float)((float)((float)v36 * (float)v36)
                          + (float)((float)((float)v35 * (float)v35) + (float)((float)v34 * (float)v34)))
                  - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm { fsel      f1, f10, f1, f13 }
    v39 = __frsqrte(_FP1);
    v40 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v39
                                                                                        * (float)((float)((float)((float)v36 * (float)v36) + (float)((float)((float)v35 * (float)v35) + (float)((float)v34 * (float)v34)))
                                                                                                * (float)0.5))
                                                                                * (float)v39)
                                                                        - (float)1.5)
                                                        * (float)v39)
                                                * (float)((float)((float)((float)v36 * (float)v36)
                                                                + (float)((float)((float)v35 * (float)v35)
                                                                        + (float)((float)v34 * (float)v34)))
                                                        * (float)0.5))
                                        * (float)((float)-(float)((float)((float)((float)v39
                                                                                * (float)((float)((float)((float)v36 * (float)v36)
                                                                                                + (float)((float)((float)v35 * (float)v35) + (float)((float)v34 * (float)v34)))
                                                                                        * (float)0.5))
                                                                        * (float)v39)
                                                                - (float)1.5)
                                                * (float)v39))
                                - (float)1.5)
                * (float)((float)-(float)((float)((float)((float)v39
                                                        * (float)((float)((float)((float)v36 * (float)v36)
                                                                        + (float)((float)((float)v35 * (float)v35)
                                                                                + (float)((float)v34 * (float)v34)))
                                                                * (float)0.5))
                                                * (float)v39)
                                        - (float)1.5)
                        * (float)v39));
    v41 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v39 * (float)((float)((float)((float)v36 * (float)v36) + (float)((float)((float)v35 * (float)v35) + (float)((float)v34 * (float)v34))) * (float)0.5)) * (float)v39) - (float)1.5)
                                                                                                * (float)v39)
                                                                                        * (float)((float)((float)((float)v36 * (float)v36) + (float)((float)((float)v35 * (float)v35) + (float)((float)v34 * (float)v34)))
                                                                                                * (float)0.5))
                                                                                * (float)((float)-(float)((float)((float)((float)v39 * (float)((float)((float)((float)v36 * (float)v36) + (float)((float)((float)v35 * (float)v35) + (float)((float)v34 * (float)v34))) * (float)0.5)) * (float)v39) - (float)1.5)
                                                                                        * (float)v39))
                                                                        - (float)1.5)
                                                        * (float)((float)-(float)((float)((float)((float)v39
                                                                                                * (float)((float)((float)((float)v36 * (float)v36) + (float)((float)((float)v35 * (float)v35) + (float)((float)v34 * (float)v34))) * (float)0.5))
                                                                                        * (float)v39)
                                                                                - (float)1.5)
                                                                * (float)v39))
                                                * (float)((float)((float)((float)v36 * (float)v36)
                                                                + (float)((float)((float)v35 * (float)v35)
                                                                        + (float)((float)v34 * (float)v34)))
                                                        * (float)0.5))
                                        * (float)v40)
                                - (float)1.5)
                * (float)v40);
    v42 = (float)((float)v35 * (float)v41);
    v43 = (float)((float)v34 * (float)v41);
    v44 = (float)((float)v36 * (float)v41);
    v45 = (float)((float)size * (float)0.5);
    v46 = (float)((float)v31 * (float)size);
    v47 = (float)((float)v32 * (float)size);
    v52.z = (float)((float)z - (float)((float)v31 * (float)size))
          + (float)((float)((float)size * (float)0.5) * (float)((float)v36 * (float)v41));
    v52.y = (float)((float)y - (float)((float)v32 * (float)size))
          + (float)((float)((float)size * (float)0.5) * (float)((float)v34 * (float)v41));
    v49 = (float)((float)((float)size * (float)0.5) * (float)((float)v35 * (float)v41));
    v48 = (float)((float)v33 * (float)size);
    v52.x = (float)((float)x - (float)v48) + (float)v49;
    idWinding::AddPoint(this: v53, v: &v52);
    v50 = (float)(end->y - (float)v47);
    v51 = (float)(end->x - (float)v48);
    v52.z = (float)(end->z - (float)v46) - (float)((float)v45 * (float)v44);
    v52.y = (float)v50 - (float)((float)v45 * (float)v43);
    v52.x = (float)v51 - (float)((float)v45 * (float)v42);
    idWinding::AddPoint(this: v53, v: &v52);
    idWinding::AddPoint(this: v53, v: end);
    this->DebugFilledPolygon(this, a2: color, a3: v53, a4: depthTest, a5: (const bool)camPos);
    v53[0].__vftable = (idWinding_vtbl *)&idWinding::`vftable';
    idMem::Free(this: &mem, ptr: v53[0].p, align: ALIGN_16);
  }
}


// ========================================================================
// __unwind$235639
// EA  : 0x829614F8
// RVA : 0x009614F8
// PDB : w:\tech5\engine\renderer\renderworld_debug.cpp
// ========================================================================

void _unwind_235639()
{
  int v0; // r12

  idWinding::~idWinding(this: (idWinding *)(v0 - 240 + 96));
}


// ========================================================================
// ?DebugShadedArc@idRenderWorldLocal@@UAAXABVidVec4@@ABVidVec3@@11MMMMH_N@Z
// EA  : 0x82961528
// RVA : 0x00961528
// PDB : w:\tech5\engine\renderer\renderworld_debug.cpp
// ========================================================================

void __fastcall idRenderWorldLocal::DebugShadedArc(
        idRenderWorldLocal *this,
        const idVec4 *color,
        const idVec3 *origin,
        const idVec3 *dir,
        const idVec3 *up,
        double radius,
        double startAngle,
        double endAngle,
        double anglesPerSegment,
        const int lifetime,
        const bool depthTest,
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
        int a30,
        int a31,
        int a32,
        int a33,
        int a34,
        int a35,
        bool a36)
{
  float y; // r9
  float z; // r8
  double v46; // fp13
  double v47; // fp25
  double v48; // fp22
  int v50; // r28
  __int64 v51; // r3
  double v53; // fp7
  double v54; // fp2
  bool v55; // mr_fpscr48
  double v56; // fp11
  double v57; // fp31
  double v58; // fp30
  double v59; // fp29
  double v60; // fp26
  double v61; // fp28
  double v62; // fp27
  double v63; // fp24
  long double v64; // fp2
  long double v65; // fp2
  double v66; // fp23
  double v67; // fp21
  double v68; // fp20
  long double v69; // fp2
  double x; // fp12
  double v71; // fp11
  double v72; // fp10
  __int64 v73; // r11
  long double v74; // fp2
  int v75; // r29
  double v76; // fp23
  double v77; // fp21
  long double v78; // fp2
  double v79; // fp9
  double v80; // fp21
  double v81; // fp20
  double v82; // fp19
  long double v83; // fp2
  double v84; // fp0
  double v85; // fp13
  long double v86; // fp2
  double v87; // fp29
  double v88; // fp30
  double v89; // fp31
  long double v90; // fp2
  double v91; // fp5
  double v92; // fp4
  idVec3 v93[2]; // [sp+58h] [-D8h] BYREF
  idWinding v94[8]; // [sp+70h] [-C0h] BYREF

  y = dir->y;
  z = dir->z;
  v93[0].x = dir->x;
  v93[0].y = y;
  v93[0].z = z;
  idVec3::ProjectOntoPlane(this: v93, normal: up, overBounce: 1.0);
  v46 = (float)((float)endAngle - (float)startAngle);
  v47 = (float)(idMath::M_DEG2RAD * (float)startAngle);
  v48 = (float)(idMath::M_DEG2RAD * (float)endAngle);
  _FP1 = (float)((float)((float)(v93[0].x * v93[0].x)
                       + (float)((float)(v93[0].z * v93[0].z) + (float)(v93[0].y * v93[0].y)))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  v50 = (int)__fabs((float)((float)((float)endAngle - (float)startAngle) / (float)anglesPerSegment));
  LODWORD(v51) = v50;
  __asm { fsel      f1, f1, f6, f11 }
  v53 = (float)((float)((float)(v93[0].x * v93[0].x)
                      + (float)((float)(v93[0].z * v93[0].z) + (float)(v93[0].y * v93[0].y)))
              * (float)0.5);
  v54 = __frsqrte(_FP1);
  v55 = (float)((float)v51 * (float)anglesPerSegment) < v46;
  v56 = (float)((float)-(float)((float)((float)((float)v54
                                              * (float)((float)((float)(v93[0].x * v93[0].x)
                                                              + (float)((float)(v93[0].z * v93[0].z)
                                                                      + (float)(v93[0].y * v93[0].y)))
                                                      * (float)0.5))
                                      * (float)v54)
                              - (float)1.5)
              * (float)v54);
  v57 = (float)((float)(v93[0].x
                      * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v56 * (float)v53)
                                                                                              * (float)v56)
                                                                                      - (float)1.5)
                                                                      * (float)v56)
                                                              * (float)v53)
                                                      * (float)((float)-(float)((float)((float)((float)v56 * (float)v53)
                                                                                      * (float)v56)
                                                                              - (float)1.5)
                                                              * (float)v56))
                                              - (float)1.5)
                              * (float)((float)-(float)((float)((float)((float)v56 * (float)v53) * (float)v56)
                                                      - (float)1.5)
                                      * (float)v56)))
              * (float)radius);
  v58 = (float)((float)(v93[0].y
                      * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v56 * (float)v53)
                                                                                              * (float)v56)
                                                                                      - (float)1.5)
                                                                      * (float)v56)
                                                              * (float)v53)
                                                      * (float)((float)-(float)((float)((float)((float)v56 * (float)v53)
                                                                                      * (float)v56)
                                                                              - (float)1.5)
                                                              * (float)v56))
                                              - (float)1.5)
                              * (float)((float)-(float)((float)((float)((float)v56 * (float)v53) * (float)v56)
                                                      - (float)1.5)
                                      * (float)v56)))
              * (float)radius);
  v59 = (float)((float)(v93[0].z
                      * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v56 * (float)v53)
                                                                                              * (float)v56)
                                                                                      - (float)1.5)
                                                                      * (float)v56)
                                                              * (float)v53)
                                                      * (float)((float)-(float)((float)((float)((float)v56 * (float)v53)
                                                                                      * (float)v56)
                                                                              - (float)1.5)
                                                              * (float)v56))
                                              - (float)1.5)
                              * (float)((float)-(float)((float)((float)((float)v56 * (float)v53) * (float)v56)
                                                      - (float)1.5)
                                      * (float)v56)))
              * (float)radius);
  v60 = (float)((float)-(float)((float)(up->z
                                      * (float)(v93[0].y
                                              * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v56 * (float)v53) * (float)v56) - (float)1.5)
                                                                                              * (float)v56)
                                                                                      * (float)v53)
                                                                              * (float)((float)-(float)((float)((float)((float)v56 * (float)v53) * (float)v56) - (float)1.5)
                                                                                      * (float)v56))
                                                                      - (float)1.5)
                                                      * (float)((float)-(float)((float)((float)((float)v56 * (float)v53)
                                                                                      * (float)v56)
                                                                              - (float)1.5)
                                                              * (float)v56))))
                              - (float)(up->y
                                      * (float)(v93[0].z
                                              * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v56 * (float)v53) * (float)v56) - (float)1.5)
                                                                                              * (float)v56)
                                                                                      * (float)v53)
                                                                              * (float)((float)-(float)((float)((float)((float)v56 * (float)v53) * (float)v56) - (float)1.5)
                                                                                      * (float)v56))
                                                                      - (float)1.5)
                                                      * (float)((float)-(float)((float)((float)((float)v56 * (float)v53)
                                                                                      * (float)v56)
                                                                              - (float)1.5)
                                                              * (float)v56)))))
              * (float)radius);
  v61 = (float)((float)-(float)((float)(up->y
                                      * (float)(v93[0].x
                                              * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v56 * (float)v53) * (float)v56) - (float)1.5)
                                                                                              * (float)v56)
                                                                                      * (float)v53)
                                                                              * (float)((float)-(float)((float)((float)((float)v56 * (float)v53) * (float)v56) - (float)1.5)
                                                                                      * (float)v56))
                                                                      - (float)1.5)
                                                      * (float)((float)-(float)((float)((float)((float)v56 * (float)v53)
                                                                                      * (float)v56)
                                                                              - (float)1.5)
                                                              * (float)v56))))
                              - (float)(up->x
                                      * (float)(v93[0].y
                                              * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v56 * (float)v53) * (float)v56) - (float)1.5)
                                                                                              * (float)v56)
                                                                                      * (float)v53)
                                                                              * (float)((float)-(float)((float)((float)((float)v56 * (float)v53) * (float)v56) - (float)1.5)
                                                                                      * (float)v56))
                                                                      - (float)1.5)
                                                      * (float)((float)-(float)((float)((float)((float)v56 * (float)v53)
                                                                                      * (float)v56)
                                                                              - (float)1.5)
                                                              * (float)v56)))))
              * (float)radius);
  v62 = (float)((float)-(float)((float)(up->x
                                      * (float)(v93[0].z
                                              * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v56 * (float)v53) * (float)v56) - (float)1.5)
                                                                                              * (float)v56)
                                                                                      * (float)v53)
                                                                              * (float)((float)-(float)((float)((float)((float)v56 * (float)v53) * (float)v56) - (float)1.5)
                                                                                      * (float)v56))
                                                                      - (float)1.5)
                                                      * (float)((float)-(float)((float)((float)((float)v56 * (float)v53)
                                                                                      * (float)v56)
                                                                              - (float)1.5)
                                                              * (float)v56))))
                              - (float)(up->z
                                      * (float)(v93[0].x
                                              * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v56 * (float)v53) * (float)v56) - (float)1.5)
                                                                                              * (float)v56)
                                                                                      * (float)v53)
                                                                              * (float)((float)-(float)((float)((float)((float)v56 * (float)v53) * (float)v56) - (float)1.5)
                                                                                      * (float)v56))
                                                                      - (float)1.5)
                                                      * (float)((float)-(float)((float)((float)((float)v56 * (float)v53)
                                                                                      * (float)v56)
                                                                              - (float)1.5)
                                                              * (float)v56)))))
              * (float)radius);
  if ( v55 )
    ++v50;
  v63 = (float)(idMath::M_DEG2RAD * (float)v46);
  *(double *)&v64 = v47;
  *((double *)&v64 + 1) = (float)(v93[0].z
                                * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v56 * (float)v53) * (float)v56)
                                                                                                - (float)1.5)
                                                                                * (float)v56)
                                                                        * (float)v53)
                                                                * (float)((float)-(float)((float)((float)((float)v56 * (float)v53)
                                                                                                * (float)v56)
                                                                                        - (float)1.5)
                                                                        * (float)v56))
                                                        - (float)1.5)
                                        * (float)((float)-(float)((float)((float)((float)v56 * (float)v53) * (float)v56)
                                                                - (float)1.5)
                                                * (float)v56)));
  v65 = cos(x: v64);
  v66 = (float)((float)v59 * (float)*(double *)&v65);
  v67 = (float)((float)v58 * (float)*(double *)&v65);
  v68 = (float)((float)*(double *)&v65 * (float)v57);
  *(double *)&v65 = v47;
  v69 = sin(x: v65);
  x = origin->x;
  v71 = origin->z;
  v72 = origin->y;
  v94[0].allocedSize = 0;
  v94[0].__vftable = (idWinding_vtbl *)&idWinding::`vftable';
  v94[0].numPoints = 0;
  v94[0].p = nullptr;
  v93[0].x = (float)((float)x - (float)((float)v60 * (float)*(double *)&v69)) + (float)v68;
  v93[0].z = (float)((float)v71 - (float)((float)v61 * (float)*(double *)&v69)) + (float)v66;
  v93[0].y = (float)((float)v72 - (float)((float)v62 * (float)*(double *)&v69)) + (float)v67;
  idWinding::AddPoint(this: v94, v: origin);
  idWinding::AddPoint(this: v94, v: v93);
  v75 = 1;
  if ( v50 > 1 )
  {
    LODWORD(v73) = v50;
    v76 = (float)v73;
    do
    {
      LODWORD(v73) = v75;
      v77 = (float)((float)((float)((float)v73 * (float)v63) / (float)v76) + (float)v47);
      *(double *)&v74 = v77;
      v78 = cos(x: v74);
      v79 = (float)*(double *)&v78;
      *(double *)&v78 = v77;
      v80 = (float)((float)v59 * (float)v79);
      v81 = (float)((float)v58 * (float)v79);
      v82 = (float)((float)v79 * (float)v57);
      v83 = sin(x: v78);
      v84 = (float)(origin->z - (float)((float)v61 * (float)*(double *)&v83));
      v85 = (float)(origin->y - (float)((float)v62 * (float)*(double *)&v83));
      v93[0].x = (float)(origin->x - (float)((float)*(double *)&v83 * (float)v60)) + (float)v82;
      v93[0].z = (float)v84 + (float)v80;
      v93[0].y = (float)v85 + (float)v81;
      idWinding::AddPoint(this: v94, v: v93);
      ++v75;
    }
    while ( v75 < v50 );
  }
  *(double *)&v74 = v48;
  v86 = cos(x: v74);
  v87 = (float)((float)v59 * (float)*(double *)&v86);
  v88 = (float)((float)v58 * (float)*(double *)&v86);
  v89 = (float)((float)*(double *)&v86 * (float)v57);
  *(double *)&v86 = v48;
  v90 = sin(x: v86);
  v91 = (float)(origin->z - (float)((float)v61 * (float)*(double *)&v90));
  v92 = (float)(origin->y - (float)((float)v62 * (float)*(double *)&v90));
  v93[0].x = (float)(origin->x - (float)((float)*(double *)&v90 * (float)v60)) + (float)v89;
  v93[0].z = (float)v91 + (float)v87;
  v93[0].y = (float)v92 + (float)v88;
  idWinding::AddPoint(this: v94, v: v93);
  idWinding::AddPoint(this: v94, v: origin);
  this->DebugFilledPolygon(this, a2: color, a3: v94, a4: a34, a5: a36);
  if ( drawReversed )
  {
    idWinding::ReverseSelf(this: v94);
    this->DebugFilledPolygon(this, a2: color, a3: v94, a4: a34, a5: a36);
  }
  v94[0].__vftable = (idWinding_vtbl *)&idWinding::`vftable';
  idMem::Free(this: &mem, ptr: v94[0].p, align: ALIGN_16);
}


// ========================================================================
// __unwind$235848
// EA  : 0x829618F0
// RVA : 0x009618F0
// PDB : w:\tech5\engine\renderer\renderworld_debug.cpp
// ========================================================================

void _unwind_235848()
{
  int v0; // r12

  idWinding::~idWinding(this: (idWinding *)(v0 - 304 + 112));
}


// ========================================================================
// ?DebugSphere@idRenderWorldLocal@@UAAXABVidVec4@@ABVidSphere@@HH_N@Z
// EA  : 0x82961920
// RVA : 0x00961920
// PDB : w:\tech5\engine\renderer\renderworld_debug.cpp
// ========================================================================

void __fastcall idRenderWorldLocal::DebugSphere(
        idRenderWorldLocal *this,
        const idVec4 *color,
        const idSphere *sphere,
        signed int sectors,
        int lifetime,
        BOOL depthTest)
{
  int v6; // r24
  int v7; // r29
  float *v13; // r3
  idVec3 *v14; // r27
  __int64 v15; // r11
  double v16; // fp11
  double y; // fp10
  int v18; // ctr
  float *v19; // r11
  int i; // r20
  double v21; // fp30
  double v22; // fp31
  double v23; // fp1
  int v24; // r28
  idVec3 *v25; // r29
  double x; // fp7
  double v27; // fp6
  double v28; // fp30
  double radius; // fp29
  double v30; // fp28
  double v31; // fp11
  double v32; // fp1
  double v33; // fp29
  double v34; // fp28
  double v35; // fp1
  idRenderWorldLocal_vtbl *v36; // r10
  void (__fastcall *DebugLine)(idRenderWorld *, const idVec4 *, const idVec3 *, const idVec3 *, const int, const bool); // r9
  float v38; // [sp+70h] [-B0h] BYREF
  float v39; // [sp+74h] [-ACh]
  float v40; // [sp+78h] [-A8h]
  float v41; // [sp+80h] [-A0h] BYREF
  float v42; // [sp+84h] [-9Ch]
  float v43; // [sp+88h] [-98h]

  v6 = 360 / sectors;
  v7 = 360 / (360 / sectors);
  __twllei(sectors, 0);
  __twllei(360 / sectors, 0);
  v13 = (float *)idMem::AllocWithLocation(
                   this: &mem,
                   location: "w:\\tech5\\shared\\idlib\\Heap.h(149) : TAG_TEMP",
                   size: 12 * v7,
                   tag: TAG_TEMP,
                   zeroBuffer: false,
                   align: ALIGN_16,
                   heap: HEAP_DEFAULTHEAP);
  v14 = (idVec3 *)v13;
  HIDWORD(v15) = 1;
  v16 = (float)(sphere->origin.z + sphere->radius);
  y = sphere->origin.y;
  *v13 = sphere->origin.x;
  v13[1] = y;
  v13[2] = v16;
  if ( v7 > 1 )
  {
    if ( v7 - 1 >= 4 )
    {
      LODWORD(v15) = v13 + 2;
      do
      {
        HIDWORD(v15) += 4;
        *(float *)(v15 + 4) = *v13;
        *(float *)(v15 + 8) = v13[1];
        *(float *)(v15 + 12) = v13[2];
        *(float *)(v15 + 16) = *v13;
        *(float *)(v15 + 20) = v13[1];
        *(float *)(v15 + 24) = v13[2];
        *(float *)(v15 + 28) = *v13;
        *(float *)(v15 + 32) = v13[1];
        *(float *)(v15 + 36) = v13[2];
        *(float *)(v15 + 40) = *v13;
        *(float *)(v15 + 44) = v13[1];
        LODWORD(v15) = v15 + 48;
        *(float *)v15 = v13[2];
      }
      while ( SHIDWORD(v15) < v7 - 3 );
    }
    if ( SHIDWORD(v15) < v7 )
    {
      v18 = v7 - HIDWORD(v15);
      v19 = &v13[3 * HIDWORD(v15) - 1];
      do
      {
        v19[1] = *v13;
        v19[2] = v13[1];
        v19 += 3;
        *v19 = v13[2];
        --v18;
      }
      while ( v18 != 0 );
    }
  }
  for ( i = v6; i <= 360; i += v6 )
  {
    LODWORD(v15) = i;
    v21 = (float)v15;
    v22 = idMath::Sin16(a: (float)((float)v15 * idMath::M_DEG2RAD));
    v23 = idMath::Cos16(a: (float)((float)v21 * idMath::M_DEG2RAD));
    v24 = v6;
    v25 = v14;
    x = sphere->origin.x;
    v27 = (float)((float)(sphere->radius * (float)v23) + sphere->origin.z);
    v39 = (float)(sphere->radius * (float)v22) + sphere->origin.y;
    v38 = x;
    v40 = v27;
    do
    {
      LODWORD(v15) = v24;
      v28 = sphere->origin.x;
      radius = sphere->radius;
      v30 = (float)v15;
      v31 = (float)(idMath::Sin16(a: (float)((float)v15 * idMath::M_DEG2RAD)) * (float)radius);
      v32 = (float)((float)v30 * idMath::M_DEG2RAD);
      v33 = sphere->origin.y;
      v34 = sphere->radius;
      v41 = (float)((float)v31 * (float)v22) + (float)v28;
      v35 = idMath::Cos16(a: v32);
      v36 = this->__vftable;
      v43 = v40;
      DebugLine = v36->DebugLine;
      v42 = (float)((float)((float)v35 * (float)v34) * (float)v22) + (float)v33;
      DebugLine(this, a2: color, a3: (const idVec3 *)&v38, a4: (const idVec3 *)&v41, a5: lifetime, a6: depthTest);
      this->DebugLine(this, a2: color, a3: (const idVec3 *)&v38, a4: v25, a5: lifetime, a6: depthTest);
      v24 += v6;
      v25->x = v38;
      v25->y = v39;
      v25->z = v40;
      ++v25;
      v40 = v43;
      v39 = v42;
      v38 = v41;
    }
    while ( v24 <= 360 );
  }
  idMem::Free(this: &mem, ptr: v14, align: ALIGN_16);
}


// ========================================================================
// __unwind$236157
// EA  : 0x82961C18
// RVA : 0x00961C18
// PDB : w:\tech5\engine\renderer\renderworld_debug.cpp
// ========================================================================

void _unwind_236157()
{
  int v0; // r12

  idTempArray<idPlane>::~idTempArray<idPlane>(this: (idTempArray<int> *)(v0 - 288 + 88));
}


// ========================================================================
// ?DebugLine@idRenderWorldLocal@@UAAXABVidVec4@@ABVidVec3@@1H_N@Z
// EA  : 0x82962820
// RVA : 0x00962820
// PDB : w:\tech5\engine\renderer\renderworld_debug.cpp
// ========================================================================

void __fastcall idRenderWorldLocal::DebugLine(
        idRenderWorldLocal *this,
        const idVec4 *color,
        const idVec3 *start,
        const idVec3 *end,
        int lifetime,
        bool depthTest)
{
  double x; // fp0
  double y; // fp13
  double z; // fp12
  double w; // fp11
  double v10; // fp10
  double v11; // fp9
  double v12; // fp8
  double v13; // fp7
  double v14; // fp6
  double v15; // fp5
  debugLine_t v16; // [sp+50h] [-40h] BYREF

  x = color->x;
  y = color->y;
  v16.depthTest = depthTest;
  z = color->z;
  w = color->w;
  v10 = start->x;
  v11 = start->y;
  v12 = start->z;
  v13 = end->x;
  v14 = end->y;
  v15 = end->z;
  v16.rgb.x = x;
  v16.rgb.y = y;
  v16.rgb.z = z;
  v16.rgb.w = w;
  v16.start.x = v10;
  v16.start.y = v11;
  v16.start.z = v12;
  v16.end.x = v13;
  v16.end.y = v14;
  v16.end.z = v15;
  if ( g_stopTime.valueInteger != 0 && g_runFrames.valueInteger <= 0 )
    v16.lifeTime = -1;
  else
    v16.lifeTime = lifetime;
  idList<debugLine_t,3>::Append(this: &this->rb_debugLines, obj: &v16);
}


// ========================================================================
// ?DebugLine_renderThread@idRenderWorldLocal@@QBAXABVidVec4@@ABVidVec3@@1H_N@Z
// EA  : 0x829628D8
// RVA : 0x009628D8
// PDB : w:\tech5\engine\renderer\renderworld_debug.cpp
// ========================================================================

void __fastcall idRenderWorldLocal::DebugLine_renderThread(
        idRenderWorldLocal *this,
        const idVec4 *color,
        const idVec3 *start,
        const idVec3 *end,
        int lifetime,
        bool depthTest)
{
  double x; // fp0
  double y; // fp13
  double z; // fp12
  double w; // fp11
  double v10; // fp10
  double v11; // fp9
  double v12; // fp8
  double v13; // fp7
  double v14; // fp6
  double v15; // fp5
  debugLine_t v16; // [sp+50h] [-40h] BYREF

  x = color->x;
  y = color->y;
  v16.depthTest = depthTest;
  z = color->z;
  w = color->w;
  v10 = start->x;
  v11 = start->y;
  v12 = start->z;
  v13 = end->x;
  v14 = end->y;
  v15 = end->z;
  v16.rgb.x = x;
  v16.rgb.y = y;
  v16.rgb.z = z;
  v16.rgb.w = w;
  v16.start.x = v10;
  v16.start.y = v11;
  v16.start.z = v12;
  v16.end.x = v13;
  v16.end.y = v14;
  v16.end.z = v15;
  if ( g_stopTime.valueInteger != 0 && g_runFrames.valueInteger <= 0 )
    v16.lifeTime = -1;
  else
    v16.lifeTime = lifetime;
  idList<debugLine_t,3>::Append(this: &this->latchedDebugLines, obj: &v16);
}


// ========================================================================
// ?DebugSphere_renderThread@idRenderWorldLocal@@QBAXABVidVec4@@ABVidSphere@@HH_N@Z
// EA  : 0x82962998
// RVA : 0x00962998
// PDB : w:\tech5\engine\renderer\renderworld_debug.cpp
// ========================================================================

void __fastcall idRenderWorldLocal::DebugSphere_renderThread(
        idRenderWorldLocal *this,
        const idVec4 *color,
        const idSphere *sphere,
        signed int sectors,
        int lifetime,
        bool depthTest)
{
  int v6; // r25
  int v7; // r29
  float *v13; // r3
  idVec3 *v14; // r27
  __int64 v15; // r11
  double v16; // fp11
  double y; // fp10
  int v18; // ctr
  float *v19; // r11
  int i; // r20
  double v21; // fp30
  double v22; // fp31
  int v23; // r28
  idVec3 *v24; // r29
  double v25; // fp26
  double x; // fp30
  double v27; // fp29
  double v28; // fp28
  double radius; // fp27
  double v30; // fp25
  double v31; // fp11
  double v32; // fp1
  double v33; // fp27
  double v34; // fp25
  double v35; // fp28
  double v36; // fp27
  idVec3 v37; // [sp+70h] [-D0h] BYREF
  idVec3 v38; // [sp+80h] [-C0h] BYREF

  v6 = 360 / sectors;
  v7 = 360 / (360 / sectors);
  __twllei(sectors, 0);
  __twllei(360 / sectors, 0);
  v13 = (float *)idMem::AllocWithLocation(
                   this: &mem,
                   location: "w:\\tech5\\shared\\idlib\\Heap.h(149) : TAG_TEMP",
                   size: 12 * v7,
                   tag: TAG_TEMP,
                   zeroBuffer: false,
                   align: ALIGN_16,
                   heap: HEAP_DEFAULTHEAP);
  v14 = (idVec3 *)v13;
  HIDWORD(v15) = 1;
  v16 = (float)(sphere->origin.z + sphere->radius);
  y = sphere->origin.y;
  *v13 = sphere->origin.x;
  v13[1] = y;
  v13[2] = v16;
  if ( v7 > 1 )
  {
    if ( v7 - 1 >= 4 )
    {
      LODWORD(v15) = v13 + 2;
      do
      {
        HIDWORD(v15) += 4;
        *(float *)(v15 + 4) = *v13;
        *(float *)(v15 + 8) = v13[1];
        *(float *)(v15 + 12) = v13[2];
        *(float *)(v15 + 16) = *v13;
        *(float *)(v15 + 20) = v13[1];
        *(float *)(v15 + 24) = v13[2];
        *(float *)(v15 + 28) = *v13;
        *(float *)(v15 + 32) = v13[1];
        *(float *)(v15 + 36) = v13[2];
        *(float *)(v15 + 40) = *v13;
        *(float *)(v15 + 44) = v13[1];
        LODWORD(v15) = v15 + 48;
        *(float *)v15 = v13[2];
      }
      while ( SHIDWORD(v15) < v7 - 3 );
    }
    if ( SHIDWORD(v15) < v7 )
    {
      v18 = v7 - HIDWORD(v15);
      v19 = &v13[3 * HIDWORD(v15) - 1];
      do
      {
        v19[1] = *v13;
        v19[2] = v13[1];
        v19 += 3;
        *v19 = v13[2];
        --v18;
      }
      while ( v18 != 0 );
    }
  }
  for ( i = v6; i <= 360; i += v6 )
  {
    LODWORD(v15) = i;
    v21 = (float)v15;
    v22 = idMath::Sin16(a: (float)((float)v15 * idMath::M_DEG2RAD));
    v23 = v6;
    v24 = v14;
    v25 = (float)((float)(sphere->radius * idMath::Cos16(a: (float)((float)v21 * idMath::M_DEG2RAD))) + sphere->origin.z);
    x = sphere->origin.x;
    v27 = (float)((float)(sphere->radius * (float)v22) + sphere->origin.y);
    v37.x = sphere->origin.x;
    v37.z = v25;
    v37.y = v27;
    v38.z = v25;
    do
    {
      LODWORD(v15) = v23;
      v28 = sphere->origin.x;
      radius = sphere->radius;
      v30 = (float)v15;
      v31 = (float)(idMath::Sin16(a: (float)((float)v15 * idMath::M_DEG2RAD)) * (float)radius);
      v32 = (float)((float)v30 * idMath::M_DEG2RAD);
      v33 = sphere->origin.y;
      v34 = sphere->radius;
      v35 = (float)((float)((float)v31 * (float)v22) + (float)v28);
      v38.x = v35;
      v36 = (float)((float)((float)(idMath::Cos16(a: v32) * (float)v34) * (float)v22) + (float)v33);
      v38.y = v36;
      idRenderWorldLocal::DebugLine_renderThread(this, color, start: &v37, end: &v38, lifetime, depthTest);
      idRenderWorldLocal::DebugLine_renderThread(this, color, start: &v37, end: v24, lifetime, depthTest);
      v23 += v6;
      v24->x = x;
      x = v35;
      v24->y = v27;
      v27 = v36;
      v24->z = v25;
      ++v24;
      v37.x = v35;
      v37.y = v36;
    }
    while ( v23 <= 360 );
  }
  idMem::Free(this: &mem, ptr: v14, align: ALIGN_16);
}


// ========================================================================
// __unwind$237055
// EA  : 0x82962C60
// RVA : 0x00962C60
// PDB : w:\tech5\engine\renderer\renderworld_debug.cpp
// ========================================================================

void _unwind_237055()
{
  int v0; // r12

  idTempArray<idPlane>::~idTempArray<idPlane>(this: (idTempArray<int> *)(v0 - 320 + 88));
}


// ========================================================================
// ?DebugPoint_renderThread@idRenderWorldLocal@@QBAXABVidVec4@@ABVidVec3@@H_N@Z
// EA  : 0x82962C88
// RVA : 0x00962C88
// PDB : w:\tech5\engine\renderer\renderworld_debug.cpp
// ========================================================================

void __fastcall idRenderWorldLocal::DebugPoint_renderThread(
        idRenderWorldLocal *this,
        const idVec4 *color,
        const idVec3 *origin,
        int lifeTime,
        bool depthTest)
{
  double x; // fp0
  double y; // fp13
  double z; // fp12
  double v13; // fp8
  double v14; // fp6
  double v15; // fp5
  double v16; // fp3
  double v17; // fp2
  double v18; // fp1
  double v19; // fp0
  idVec3 v20; // [sp+50h] [-60h] BYREF
  idVec3 v21[2]; // [sp+60h] [-50h] BYREF

  x = origin->x;
  y = origin->y;
  z = origin->z;
  v20.z = origin->z;
  v20.y = y;
  v20.x = (float)x + (float)8.0;
  v21[0].x = (float)x - (float)8.0;
  v21[0].y = y;
  v21[0].z = z;
  idRenderWorldLocal::DebugLine_renderThread(this, color, start: v21, end: &v20, lifetime: lifeTime, depthTest);
  v13 = origin->x;
  v14 = origin->z;
  v15 = (float)(origin->y - (float)8.0);
  v21[0].y = origin->y + (float)8.0;
  v21[0].x = v13;
  v21[0].z = v14;
  v20.x = v13;
  v20.y = v15;
  v20.z = v14;
  idRenderWorldLocal::DebugLine_renderThread(this, color, start: &v20, end: v21, lifetime: lifeTime, depthTest);
  v16 = origin->x;
  v17 = (float)(origin->z + (float)8.0);
  v18 = origin->y;
  v19 = (float)(origin->z - (float)8.0);
  v21[0].y = origin->y;
  v21[0].x = v16;
  v21[0].z = v17;
  v20.x = v16;
  v20.y = v18;
  v20.z = v19;
  idRenderWorldLocal::DebugLine_renderThread(this, color, start: &v20, end: v21, lifetime: lifeTime, depthTest);
}


// ========================================================================
// ?DebugFilledBounds@idRenderWorldLocal@@UAAXABVidVec4@@ABVidBounds@@ABVidVec3@@H_N@Z
// EA  : 0x82962D90
// RVA : 0x00962D90
// PDB : w:\tech5\engine\renderer\renderworld_debug.cpp
// ========================================================================

void __fastcall idRenderWorldLocal::DebugFilledBounds(
        idRenderWorldLocal *this,
        const idVec4 *color,
        const idBounds *bounds,
        const idVec3 *org,
        int lifetime,
        bool depthTest)
{
  double x; // fp5
  double y; // fp4
  double z; // fp3
  double w; // fp2
  double v10; // fp1
  double v11; // fp31
  double v12; // fp30
  double v13; // fp29
  double v14; // fp28
  double v15; // fp27
  double v16; // fp26
  double v17; // fp25
  double v18; // fp24
  debugBounds_t v19; // [sp+50h] [-B0h] BYREF

  x = color->x;
  y = color->y;
  z = color->z;
  w = color->w;
  v10 = bounds->b[0].x;
  v19.depthTest = depthTest;
  v11 = bounds->b[0].y;
  v12 = bounds->b[0].z;
  v13 = bounds->b[1].x;
  v14 = bounds->b[1].y;
  v15 = bounds->b[1].z;
  v16 = org->x;
  v17 = org->y;
  v18 = org->z;
  v19.rgb.x = x;
  v19.rgb.y = y;
  v19.axis.mat[0].x = mat3_identity.mat[0].x;
  v19.rgb.z = z;
  v19.axis.mat[0].y = mat3_identity.mat[0].y;
  v19.rgb.w = w;
  v19.axis.mat[0].z = mat3_identity.mat[0].z;
  v19.bounds.b[0].x = v10;
  v19.axis.mat[1].x = mat3_identity.mat[1].x;
  v19.bounds.b[0].y = v11;
  v19.axis.mat[1].y = mat3_identity.mat[1].y;
  v19.bounds.b[0].z = v12;
  v19.axis.mat[1].z = mat3_identity.mat[1].z;
  v19.bounds.b[1].x = v13;
  v19.axis.mat[2].x = mat3_identity.mat[2].x;
  v19.bounds.b[1].y = v14;
  v19.axis.mat[2].y = mat3_identity.mat[2].y;
  v19.bounds.b[1].z = v15;
  v19.axis.mat[2].z = mat3_identity.mat[2].z;
  v19.origin.x = v16;
  v19.origin.y = v17;
  v19.origin.z = v18;
  if ( g_stopTime.valueInteger != 0 && g_runFrames.valueInteger <= 0 )
    v19.lifeTime = -1;
  else
    v19.lifeTime = lifetime;
  idList<debugBounds_t,3>::Append(this: &this->rb_debugBounds, obj: &v19);
}


// ========================================================================
// ?DebugText@idRenderWorldLocal@@UAAXPBDABVidVec3@@MABVidVec4@@ABVidMat3@@HH_N4@Z
// EA  : 0x82962EC8
// RVA : 0x00962EC8
// PDB : w:\tech5\engine\renderer\renderworld_debug.cpp
// ========================================================================

void __fastcall idRenderWorldLocal::DebugText(
        idRenderWorldLocal *this,
        const char *text,
        const idVec3 *origin,
        double scale,
        const idVec4 *color,
        const idMat3 *viewAxis,
        float *align,
        unsigned __int8 lifetime,
        int depthTest,
        const bool bold,
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
        bool a29,
        int a30,
        char a31)
{
  double x; // fp0
  double y; // fp13
  double z; // fp12
  double v41; // fp11
  double v42; // fp10
  double v43; // fp9
  double v44; // fp8
  double v45; // fp7
  double v46; // fp6
  double v47; // fp5
  double v48; // fp4
  double v49; // fp3
  double v50; // fp2
  double v51; // fp1
  double v52; // fp31
  double v53; // fp30
  debugText_t v54; // [sp+50h] [-120h] BYREF

  strncpy(dest: v54.text, source: text, count: 0x7Fu);
  v54.scale = scale;
  v54.align = lifetime;
  x = origin->x;
  y = origin->y;
  z = origin->z;
  v41 = viewAxis->mat[0].x;
  v42 = viewAxis->mat[0].y;
  v43 = viewAxis->mat[0].z;
  v54.text[127] = 0;
  v44 = viewAxis->mat[1].x;
  v45 = *align;
  v54.orientToRenderViewAxis = false;
  v46 = align[1];
  v54.lineWidth = a31 == 0 ? 1 : 4;
  v47 = align[2];
  v48 = align[3];
  v49 = align[4];
  v50 = align[5];
  v51 = align[6];
  v54.origin.x = x;
  v54.origin.y = y;
  v54.origin.z = z;
  v52 = align[7];
  v53 = align[8];
  v54.color.x = v41;
  v54.color.y = v42;
  v54.color.z = v43;
  v54.color.w = v44;
  v54.viewAxis.mat[0].x = v45;
  v54.viewAxis.mat[0].y = v46;
  v54.viewAxis.mat[0].z = v47;
  v54.viewAxis.mat[1].x = v48;
  v54.viewAxis.mat[1].y = v49;
  v54.viewAxis.mat[1].z = v50;
  v54.viewAxis.mat[2].x = v51;
  v54.viewAxis.mat[2].y = v52;
  v54.viewAxis.mat[2].z = v53;
  if ( g_stopTime.valueInteger != 0 && g_runFrames.valueInteger <= 0 )
    v54.lifeTime = -1;
  else
    v54.lifeTime = depthTest;
  v54.depthTest = a29;
  idList<debugText_t,3>::Append(this: &this->rb_debugText, obj: &v54);
}


// ========================================================================
// ?DebugText@idRenderWorldLocal@@UAAXPBDABVidVec3@@MABVidVec4@@HH_N3@Z
// EA  : 0x82963010
// RVA : 0x00963010
// PDB : w:\tech5\engine\renderer\renderworld_debug.cpp
// ========================================================================

void __fastcall idRenderWorldLocal::DebugText(
        idRenderWorldLocal *this,
        const char *text,
        const idVec3 *origin,
        double scale,
        const idVec4 *color,
        float *align,
        unsigned __int8 lifetime,
        int depthTest,
        bool bold,
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
        char a29)
{
  double y; // fp5
  double z; // fp4
  double v38; // fp3
  double v39; // fp2
  double v40; // fp1
  double v41; // fp31
  debugText_t v42; // [sp+50h] [-110h] BYREF

  strncpy(dest: v42.text, source: text, count: 0x7Fu);
  v42.scale = scale;
  y = origin->y;
  z = origin->z;
  v38 = *align;
  v39 = align[1];
  v42.viewAxis.mat[0].x = mat3_identity.mat[0].x;
  v40 = align[2];
  v42.origin.y = y;
  v42.lineWidth = a29 == 0 ? 1 : 4;
  v42.text[127] = 0;
  v42.align = lifetime;
  v42.orientToRenderViewAxis = true;
  v42.viewAxis.mat[0].y = mat3_identity.mat[0].y;
  v41 = align[3];
  v42.origin.x = origin->x;
  v42.origin.z = z;
  v42.viewAxis.mat[0].z = mat3_identity.mat[0].z;
  v42.color.x = v38;
  v42.viewAxis.mat[1].x = mat3_identity.mat[1].x;
  v42.color.y = v39;
  v42.viewAxis.mat[1].y = mat3_identity.mat[1].y;
  v42.color.z = v40;
  v42.viewAxis.mat[1].z = mat3_identity.mat[1].z;
  v42.color.w = v41;
  v42.viewAxis.mat[2].x = mat3_identity.mat[2].x;
  v42.viewAxis.mat[2].y = mat3_identity.mat[2].y;
  v42.viewAxis.mat[2].z = mat3_identity.mat[2].z;
  if ( g_stopTime.valueInteger != 0 && g_runFrames.valueInteger <= 0 )
    v42.lifeTime = -1;
  else
    v42.lifeTime = depthTest;
  v42.depthTest = bold;
  idList<debugText_t,3>::Append(this: &this->rb_debugText, obj: &v42);
}


// ========================================================================
// ?DebugSpline@idRenderWorldLocal@@UAAXABVidVec4@@PAV?$idCurve_Spline@VidVec3@@@@M_NH_N@Z
// EA  : 0x82963158
// RVA : 0x00963158
// PDB : w:\tech5\engine\renderer\renderworld_debug.cpp
// ========================================================================

void __fastcall idRenderWorldLocal::DebugSpline(
        idRenderWorldLocal *this,
        const idVec4 *color,
        idVec3 *spline,
        double step,
        bool drawKnots,
        int lifeTime,
        int depthTest,
        BOOL a8)
{
  double v14; // fp30
  double v15; // fp31
  double TimeForLength; // fp1
  int v17; // r29
  int v18; // r30
  idVec3 *v19; // r9
  float x; // r8
  float y; // r10
  float z; // r9
  void (__fastcall *DebugPoint)(idRenderWorld *, const idVec4 *, const idVec3 *, const int, const bool); // ctr
  float v24[4]; // [sp+50h] [-90h] BYREF
  float v25[4]; // [sp+60h] [-80h] BYREF
  _DWORD v26[12]; // [sp+70h] [-70h] BYREF

  if ( spline != nullptr )
  {
    v14 = ((double (__fastcall *)(idVec3 *, double))*(_DWORD *)(LODWORD(spline->x) + 36))(
            a1: spline,
            a2: *(float *)(4 * LODWORD(spline[2].x) + LODWORD(spline->y) - 4));
    v15 = 0.0;
    (*(void (__fastcall **)(float *, idVec3 *, double))(LODWORD(spline->x) + 20))(a1: v25, a2: spline, a3: 0.0);
    if ( v14 >= 0.0 )
    {
      do
      {
        TimeForLength = idCurve<idVec3>::GetTimeForLength(this: (idCurve<idVec3> *)spline, length: v15, epsilon: 0.1);
        (*(void (__fastcall **)(float *, idVec3 *, double))(LODWORD(spline->x) + 20))(
          a1: v24,
          a2: spline,
          a3: TimeForLength);
        this->DebugLine(this, a2: color, a3: (const idVec3 *)v25, a4: (const idVec3 *)v24, a5: depthTest, a6: a8);
        v15 = (float)((float)v15 + (float)step);
        v25[0] = v24[0];
        v25[1] = v24[1];
        v25[2] = v24[2];
      }
      while ( v15 <= v14 );
    }
    v17 = 0;
    if ( SLODWORD(spline[2].x) > 0 )
    {
      v18 = 0;
      do
      {
        v19 = (idVec3 *)(LODWORD(spline[1].z) + v18);
        x = v19->x;
        y = v19->y;
        z = v19->z;
        DebugPoint = this->DebugPoint;
        *(float *)v26 = x;
        *(float *)&v26[1] = y;
        *(float *)&v26[2] = z;
        DebugPoint(this, a2: (const idVec4 *)&idColor::colorCyan, a3: (const idVec3 *)v26, a4: depthTest, a5: a8);
        ++v17;
        v18 += 12;
      }
      while ( v17 < SLODWORD(spline[2].x) );
    }
  }
}


// ========================================================================
// ?DebugCommit@idRenderWorldLocal@@QAAXXZ
// EA  : 0x82963570
// RVA : 0x00963570
// PDB : w:\tech5\engine\renderer\renderworld_debug.cpp
// ========================================================================

void __fastcall idRenderWorldLocal::DebugCommit(idRenderWorldLocal *this)
{
  if ( this->latchedDebugLines.num != 0 || this->rb_debugLines.num != 0 )
    idList<debugLine_t,3>::operator=(this: &this->latchedDebugLines, other: &this->rb_debugLines);
  if ( this->latchedDebugText.num != 0 || this->rb_debugText.num != 0 )
    idList<debugText_t,3>::operator=(this: &this->latchedDebugText, other: &this->rb_debugText);
  if ( this->latchedDebugPolygons.num != 0 || this->rb_debugPolygons.num != 0 )
    idList<debugPolygon_t,3>::operator=(this: &this->latchedDebugPolygons, other: &this->rb_debugPolygons);
  if ( this->latchedDebugBounds.num != 0 || this->rb_debugBounds.num != 0 )
    idList<debugBounds_t,3>::operator=(this: &this->latchedDebugBounds, other: &this->rb_debugBounds);
}


// ========================================================================
// ?DebugClear@idRenderWorldLocal@@UAAXH@Z
// EA  : 0x82963688
// RVA : 0x00963688
// PDB : w:\tech5\engine\renderer\renderworld_debug.cpp
// ========================================================================

void __fastcall idRenderWorldLocal::DebugClear(idRenderWorldLocal *this, int deltaTime)
{
  int num; // r11
  int v5; // r30
  idList<debugLine_t,3> *p_rb_debugLines; // r31
  int v7; // r8
  debugLine_t *list; // r9
  int v9; // r7
  float *p_z; // r10
  int v11; // r11
  debugLine_t *v12; // r11
  int size; // r11
  int v14; // r11
  int v15; // r27
  int v16; // r29
  debugPolygon_t *v17; // r31
  int v18; // r26
  int lifeTime; // r11
  debugPolygon_t *v20; // r30
  int v21; // r11
  int v22; // r11
  int v23; // r29
  int v24; // r30
  debugBounds_t *v25; // r31
  int v26; // r27
  int v27; // r11
  int v28; // r11
  int v29; // r11
  int v30; // r29
  int v31; // r30
  debugText_t *v32; // r31
  int v33; // r27
  int v34; // r11
  int v35; // r11

  num = this->rb_debugLines.num;
  if ( num != 0 )
  {
    v5 = 0;
    p_rb_debugLines = &this->rb_debugLines;
    v7 = 0;
    list = this->rb_debugLines.list;
    if ( num > 0 )
    {
      v9 = 0;
      p_z = &list->start.z;
      do
      {
        v11 = *((_DWORD *)p_z + 5);
        *((_DWORD *)p_z + 5) = v11 - deltaTime;
        if ( v11 - deltaTime >= 0 )
        {
          if ( v5 != v7 )
          {
            v12 = &p_rb_debugLines->list[v9];
            v12->rgb.x = list->rgb.x;
            v12->rgb.y = *(p_z - 5);
            v12->rgb.z = *(p_z - 4);
            v12->rgb.w = *(p_z - 3);
            v12->start.x = *(p_z - 2);
            v12->start.y = *(p_z - 1);
            v12->start.z = *p_z;
            v12->end.x = p_z[1];
            v12->end.y = p_z[2];
            v12->end.z = p_z[3];
            v12->depthTest = *((_BYTE *)p_z + 16);
            v12->lifeTime = (int)p_z[5];
          }
          ++v5;
          ++v9;
        }
        ++v7;
        ++list;
        p_z += 12;
      }
      while ( v7 < this->rb_debugLines.num );
    }
    if ( v5 <= this->rb_debugLines.size
      || (unsigned __int8)idList<debugLine_t,3>::Resize(this: &this->rb_debugLines, newsize: v5) != 0 )
    {
      size = p_rb_debugLines->size;
      if ( v5 < size )
        size = v5;
      p_rb_debugLines->num = size;
    }
  }
  v14 = this->rb_debugPolygons.num;
  if ( v14 != 0 )
  {
    v15 = 0;
    v16 = 0;
    v17 = this->rb_debugPolygons.list;
    if ( v14 > 0 )
    {
      v18 = 0;
      do
      {
        lifeTime = v17->lifeTime;
        v17->lifeTime = lifeTime - deltaTime;
        if ( lifeTime - deltaTime >= 0 )
        {
          if ( v15 != v16 )
          {
            v20 = &this->rb_debugPolygons.list[v18];
            v20->rgb.x = v17->rgb.x;
            v20->rgb.y = v17->rgb.y;
            v20->rgb.z = v17->rgb.z;
            v20->rgb.w = v17->rgb.w;
            idWinding::operator=(this: &v20->winding, winding: &v17->winding);
            v20->depthTest = v17->depthTest;
            v20->lifeTime = v17->lifeTime;
          }
          ++v15;
          ++v18;
        }
        ++v16;
        ++v17;
      }
      while ( v16 < this->rb_debugPolygons.num );
    }
    if ( v15 <= this->rb_debugPolygons.size
      || (unsigned __int8)idList<debugPolygon_t,3>::Resize(this: &this->rb_debugPolygons, newsize: v15) != 0 )
    {
      v21 = this->rb_debugPolygons.size;
      if ( v15 < v21 )
        v21 = v15;
      this->rb_debugPolygons.num = v21;
    }
  }
  v22 = this->rb_debugBounds.num;
  if ( v22 != 0 )
  {
    v23 = 0;
    v24 = 0;
    v25 = this->rb_debugBounds.list;
    if ( v22 > 0 )
    {
      v26 = 0;
      do
      {
        v27 = v25->lifeTime;
        v25->lifeTime = v27 - deltaTime;
        if ( v27 - deltaTime >= 0 )
        {
          if ( v23 != v24 )
            debugBounds_t::operator=(this: &this->rb_debugBounds.list[v26], __that: v25);
          ++v23;
          ++v26;
        }
        ++v24;
        ++v25;
      }
      while ( v24 < this->rb_debugBounds.num );
    }
    if ( v23 <= this->rb_debugBounds.size
      || (unsigned __int8)idList<debugBounds_t,3>::Resize(this: &this->rb_debugBounds, newsize: v23) != 0 )
    {
      v28 = this->rb_debugBounds.size;
      if ( v23 < v28 )
        v28 = v23;
      this->rb_debugBounds.num = v28;
    }
  }
  v29 = this->rb_debugText.num;
  if ( v29 != 0 )
  {
    v30 = 0;
    v31 = 0;
    v32 = this->rb_debugText.list;
    if ( v29 > 0 )
    {
      v33 = 0;
      do
      {
        v34 = v32->lifeTime;
        v32->lifeTime = v34 - deltaTime;
        if ( v34 - deltaTime >= 0 )
        {
          if ( v30 != v31 )
            debugText_t::operator=(this: &this->rb_debugText.list[v33], __that: v32);
          ++v30;
          ++v33;
        }
        ++v31;
        ++v32;
      }
      while ( v31 < this->rb_debugText.num );
    }
    if ( v30 <= this->rb_debugText.size
      || (unsigned __int8)idList<debugText_t,3>::Resize(this: &this->rb_debugText, newsize: v30) != 0 )
    {
      v35 = this->rb_debugText.size;
      if ( v30 < v35 )
        v35 = v30;
      this->rb_debugText.num = v35;
    }
  }
}


// ========================================================================
// ?DebugFilledPolygon@idRenderWorldLocal@@UAAXABVidVec4@@ABVidWinding@@H_N@Z
// EA  : 0x82963A00
// RVA : 0x00963A00
// PDB : w:\tech5\engine\renderer\renderworld_debug.cpp
// ========================================================================

void __fastcall idRenderWorldLocal::DebugFilledPolygon(
        idRenderWorldLocal *this,
        const idVec4 *color,
        const idWinding *winding,
        int lifetime,
        bool depthTest)
{
  double y; // fp13
  double z; // fp12
  double w; // fp11
  debugPolygon_t v11[2]; // [sp+50h] [-60h] BYREF

  v11[0].winding.allocedSize = 0;
  v11[0].winding.__vftable = (idWinding_vtbl *)&idWinding::`vftable';
  v11[0].winding.numPoints = 0;
  v11[0].winding.p = nullptr;
  y = color->y;
  z = color->z;
  w = color->w;
  v11[0].rgb.x = color->x;
  v11[0].rgb.y = y;
  v11[0].rgb.z = z;
  v11[0].rgb.w = w;
  idWinding::operator=(this: &v11[0].winding, winding);
  v11[0].depthTest = depthTest;
  if ( g_stopTime.valueInteger != 0 && g_runFrames.valueInteger <= 0 )
    v11[0].lifeTime = -1;
  else
    v11[0].lifeTime = lifetime;
  idList<debugPolygon_t,3>::Append(this: &this->rb_debugPolygons, obj: v11);
  v11[0].winding.__vftable = (idWinding_vtbl *)&idWinding::`vftable';
  idMem::Free(this: &mem, ptr: v11[0].winding.p, align: ALIGN_16);
}


// ========================================================================
// __unwind$238460
// EA  : 0x82963AD4
// RVA : 0x00963AD4
// PDB : w:\tech5\engine\renderer\renderworld_debug.cpp
// ========================================================================

void _unwind_238460()
{
  int v0; // r12

  debugPolygon_t::~debugPolygon_t(this: (debugPolygon_t *)(v0 - 176 + 80));
}

