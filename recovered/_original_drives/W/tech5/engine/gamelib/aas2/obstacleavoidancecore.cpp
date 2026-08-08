
// ========================================================================
// ??0idObstacleAvoidanceCore@@QAA@XZ
// EA  : 0x826BD3F0
// RVA : 0x006BD3F0
// PDB : w:\tech5\engine\gamelib\aas2\obstacleavoidancecore.cpp
// ========================================================================

idObstacleAvoidanceCore *__fastcall idObstacleAvoidanceCore::idObstacleAvoidanceCore(idObstacleAvoidanceCore *this)
{
  this->bspNodes = nullptr;
  this->numBspNodes = 0;
  this->obstacleIndices = nullptr;
  this->expandedObstacles = nullptr;
  this->maxExpandedObstacles = 0;
  this->numExpandedObstacles = 0;
  this->windingPoints = nullptr;
  this->maxWindingPoints = 0;
  this->numWindingPoints = 0;
  this->tempMemory = nullptr;
  this->tempMemorySize = 0;
  this->tempMemoryStart = nullptr;
  this->tempMemoryEnd = nullptr;
  this->pathNodes = nullptr;
  this->maxPathNodes = 0;
  this->numPathNodes = 0;
  this->debugLines = nullptr;
  this->maxDebugLines = 0;
  this->numDebugLines = 0;
  this->debugText = nullptr;
  this->maxDebugText = 0;
  this->numDebugText = 0;
  this->inputTransformValid = false;
  this->inputTransform.mat[0] = 1.0;
  this->inputTransform.mat[1] = 0.0;
  this->inputTransform.mat[2] = 0.0;
  this->inputTransform.mat[3] = 0.0;
  this->inputTransform.mat[4] = 0.0;
  this->inputTransform.mat[5] = 1.0;
  this->inputTransform.mat[6] = 0.0;
  this->inputTransform.mat[7] = 0.0;
  this->inputTransform.mat[8] = 0.0;
  this->inputTransform.mat[9] = 0.0;
  this->inputTransform.mat[10] = 1.0;
  this->inputTransform.mat[11] = 0.0;
  return this;
}


// ========================================================================
// ??1idObstacleAvoidanceCore@@QAA@XZ
// EA  : 0x826BD498
// RVA : 0x006BD498
// PDB : w:\tech5\engine\gamelib\aas2\obstacleavoidancecore.cpp
// ========================================================================

void __fastcall idObstacleAvoidanceCore::~idObstacleAvoidanceCore(idObstacleAvoidanceCore *this)
{
  this->bspNodes = nullptr;
  this->debugLines = nullptr;
  this->debugText = nullptr;
  this->expandedObstacles = nullptr;
  this->obstacleIndices = nullptr;
  this->pathNodes = nullptr;
  this->tempMemory = nullptr;
  this->tempMemoryEnd = nullptr;
  this->tempMemoryStart = nullptr;
  this->windingPoints = nullptr;
}


// ========================================================================
// ?AddDebugLine@idObstacleAvoidanceCore@@AAAXW4avoidColor_t@1@ABVidVec2@@1@Z
// EA  : 0x826BD4C8
// RVA : 0x006BD4C8
// PDB : w:\tech5\engine\gamelib\aas2\obstacleavoidancecore.cpp
// ========================================================================

void __fastcall idObstacleAvoidanceCore::AddDebugLine(
        idObstacleAvoidanceCore *this,
        idObstacleAvoidanceCore::avoidColor_t color,
        const idVec2 *start,
        const idVec2 *end)
{
  int numDebugLines; // r10
  avoidDebugLine_t *debugLines; // r9
  avoidDebugLine_t *v6; // r11
  double y; // fp13
  double v8; // fp11

  numDebugLines = this->numDebugLines;
  if ( numDebugLines < this->maxDebugLines - 1 )
  {
    debugLines = this->debugLines;
    if ( debugLines != nullptr )
    {
      v6 = &debugLines[numDebugLines];
      this->numDebugLines = numDebugLines + 1;
      v6->color = color;
      y = start->y;
      v6->start.x = start->x;
      v6->start.y = y;
      v6->start.z = 0.0;
      v8 = end->y;
      v6->end.x = end->x;
      v6->end.y = v8;
      v6->end.z = 0.0;
      this->debugLines[this->numDebugLines].color = COLOR_INVALID;
    }
  }
}


// ========================================================================
// ?AddDebugInt@idObstacleAvoidanceCore@@AAAXW4avoidColor_t@1@ABVidVec2@@H@Z
// EA  : 0x826BD548
// RVA : 0x006BD548
// PDB : w:\tech5\engine\gamelib\aas2\obstacleavoidancecore.cpp
// ========================================================================

void __fastcall idObstacleAvoidanceCore::AddDebugInt(
        idObstacleAvoidanceCore *this,
        idObstacleAvoidanceCore::avoidColor_t color,
        const idVec2 *pos,
        int num)
{
  int numDebugText; // r11
  avoidDebugText_t *debugText; // r8
  avoidDebugText_t *v7; // r31
  double y; // fp13

  numDebugText = this->numDebugText;
  if ( numDebugText < this->maxDebugText - 1 )
  {
    debugText = this->debugText;
    if ( debugText != nullptr )
    {
      this->numDebugText = numDebugText + 1;
      v7 = &debugText[numDebugText];
      v7->color = color;
      y = pos->y;
      v7->pos.x = pos->x;
      v7->pos.y = y;
      v7->pos.z = 0.0;
      snprintf_0(string: v7->text, count: 0x20u, format: "%d", num);
      v7->text[31] = 0;
      this->debugText[this->numDebugText].color = COLOR_INVALID;
    }
  }
}


// ========================================================================
// ?BoxParallelProjectionSilhouetteVerts@idObstacleAvoidanceCore@@CAHABVidMat3@@ABVidVec3@@11QAV3@@Z
// EA  : 0x826BD610
// RVA : 0x006BD610
// PDB : w:\tech5\engine\gamelib\aas2\obstacleavoidancecore.cpp
// ========================================================================

int __fastcall idObstacleAvoidanceCore::BoxParallelProjectionSilhouetteVerts(
        const idMat3 *axis,
        const idVec3 *center,
        const idVec3 *extents,
        const idVec3 *projectionDir,
        idVec3 *silVerts)
{
  double z; // fp2
  double x; // fp5
  double v7; // fp11
  double y; // fp10
  double v9; // fp8
  double v10; // fp7
  double v11; // fp9
  double v12; // fp6
  double v13; // fp23
  double v14; // fp22
  double v15; // fp24
  double v16; // fp1
  double v17; // fp31
  double v18; // fp3
  double v19; // fp0
  double v20; // fp26
  double v21; // fp25
  double v22; // fp30
  double v23; // fp21
  double v24; // fp28
  double v25; // fp29
  double v26; // fp4
  double v27; // fp12
  double v28; // fp13
  double v29; // fp4
  double v30; // fp12
  int v31; // r11
  double v32; // fp9
  int v33; // r9
  int *v34; // r5
  int result; // r3
  float *p_z; // r11
  int *v37; // r8
  float *v38; // r10
  double v39; // fp13
  double v40; // fp12
  float v41[46]; // [sp+10h] [-C0h] BYREF

  z = axis->mat[0].z;
  x = axis->mat[0].x;
  v7 = axis->mat[1].x;
  y = axis->mat[1].y;
  v9 = axis->mat[2].x;
  v10 = axis->mat[2].y;
  v11 = axis->mat[1].z;
  v12 = axis->mat[2].z;
  v13 = (float)(center->y + (float)(axis->mat[0].y * extents->x));
  v14 = (float)(center->z + (float)(axis->mat[0].z * extents->x));
  v15 = (float)(center->x - (float)(axis->mat[0].x * extents->x));
  v16 = (float)(center->y - (float)(axis->mat[0].y * extents->x));
  v17 = (float)(center->z - (float)(axis->mat[0].z * extents->x));
  v18 = (float)(center->x + (float)(axis->mat[0].x * extents->x));
  v19 = projectionDir->y;
  v20 = (float)((float)(axis->mat[1].x * extents->y) - (float)(axis->mat[2].x * extents->z));
  v21 = (float)((float)(axis->mat[1].y * extents->y) - (float)(axis->mat[2].y * extents->z));
  v22 = (float)((float)(axis->mat[2].x * extents->z) + (float)(axis->mat[1].x * extents->y));
  v23 = (float)((float)(axis->mat[1].z * extents->y) - (float)(axis->mat[2].z * extents->z));
  v24 = (float)((float)(axis->mat[2].z * extents->z) + (float)(axis->mat[1].z * extents->y));
  v25 = (float)((float)(axis->mat[2].y * extents->z) + (float)(axis->mat[1].y * extents->y));
  v26 = (float)(projectionDir->y * axis->mat[0].y);
  v27 = (float)((float)((float)(axis->mat[1].y * extents->y) - (float)(axis->mat[2].y * extents->z))
              + (float)(center->y + (float)(axis->mat[0].y * extents->x)));
  v41[6] = (float)((float)(axis->mat[1].x * extents->y) - (float)(axis->mat[2].x * extents->z))
         + (float)(center->x + (float)(axis->mat[0].x * extents->x));
  v41[7] = v27;
  v41[0] = (float)v15 - (float)v22;
  v41[8] = (float)v23 + (float)v14;
  v41[2] = (float)v17 - (float)v24;
  v41[1] = (float)v16 - (float)v25;
  v41[3] = (float)v18 - (float)v22;
  v41[4] = (float)v13 - (float)v25;
  v41[5] = (float)v14 - (float)v24;
  v41[9] = (float)v20 + (float)v15;
  v41[10] = (float)v21 + (float)v16;
  v41[11] = (float)v23 + (float)v17;
  v41[12] = (float)v15 - (float)v20;
  v41[13] = (float)v16 - (float)v21;
  v41[15] = (float)v18 - (float)v20;
  v41[14] = (float)v17 - (float)v23;
  v41[16] = (float)v13 - (float)v21;
  v41[17] = (float)v14 - (float)v23;
  v41[18] = (float)v22 + (float)v18;
  v41[19] = (float)v25 + (float)v13;
  v41[20] = (float)v24 + (float)v14;
  v28 = projectionDir->z;
  v29 = (float)((float)(projectionDir->z * (float)z) + (float)v26);
  v30 = projectionDir->x;
  v41[21] = (float)v22 + (float)v15;
  v41[22] = (float)v25 + (float)v16;
  v31 = 0;
  v41[23] = (float)v24 + (float)v17;
  if ( COERCE_INT(fabs((float)((float)v30 * (float)x) + (float)v29)) != 0 )
    v31 = 1 << (COERCE_INT((float)((float)v30 * (float)x) + (float)v29) < 0);
  v32 = (float)((float)((float)v28 * (float)v11) + (float)((float)v19 * (float)y));
  if ( COERCE_INT(fabs((float)((float)v30 * (float)v7) + (float)v32)) != 0 )
    v31 |= 4 << (COERCE_UNSIGNED_INT((float)((float)v30 * (float)v7) + (float)v32) >> 31);
  if ( COERCE_INT(
         fabs(
           (float)((float)v30 * (float)v9)
         + (float)((float)((float)v28 * (float)v12) + (float)((float)v19 * (float)v10)))) != 0 )
    v31 |= 16 << (COERCE_INT(
                    (float)((float)v30 * (float)v9)
                  + (float)((float)((float)v28 * (float)v12) + (float)((float)v19 * (float)v10))) < 0);
  v33 = 0;
  v34 = boxPlaneBitsSilVerts[v31];
  result = *v34;
  if ( *v34 > 0 )
  {
    p_z = &silVerts[-1].z;
    v37 = v34;
    do
    {
      ++v37;
      ++v33;
      v38 = &v41[3 * *v37];
      v39 = v38[1];
      v40 = v38[2];
      p_z[1] = *v38;
      p_z[2] = v39;
      p_z += 3;
      *p_z = v40;
      result = *v34;
    }
    while ( v33 < *v34 );
  }
  return result;
}


// ========================================================================
// ?GetCirclePoints@idObstacleAvoidanceCore@@CAXABVidVec2@@MQAV2@@Z
// EA  : 0x826BD888
// RVA : 0x006BD888
// PDB : w:\tech5\engine\gamelib\aas2\obstacleavoidancecore.cpp
// ========================================================================

void __fastcall idObstacleAvoidanceCore::GetCirclePoints(
        const idVec2 *center,
        double radius,
        idVec2 *circlePoints,
        float *a4)
{
  double x; // fp12
  double v5; // fp9
  double v6; // fp5
  double v7; // fp6
  double v8; // fp4
  double v9; // fp3
  double v10; // fp2
  double y; // fp11
  double v12; // fp12
  double v13; // fp2
  double v14; // fp0
  double v15; // fp7
  double v16; // fp8
  double v17; // fp13
  double v18; // fp0
  double v19; // fp0
  double v20; // fp1
  double v21; // fp7
  double v22; // fp0
  double v23; // fp11
  double v24; // fp7
  double v25; // fp8
  double v26; // fp9
  double v27; // fp5
  double v28; // fp0
  double v29; // fp10

  x = center->x;
  v5 = (float)((float)radius * (float)0.0);
  v6 = (float)((float)radius * (float)0.38268343);
  a4[1] = center->y + (float)radius;
  v7 = (float)((float)radius * (float)0.9238795);
  v8 = (float)((float)radius * (float)-0.38268343);
  v9 = (float)((float)radius * (float)-0.9238795);
  *a4 = (float)x + (float)((float)radius * (float)0.0);
  v10 = (float)(center->x + (float)((float)radius * (float)0.38268343));
  a4[3] = (float)((float)radius * (float)0.9238795) + center->y;
  a4[2] = v10;
  y = center->y;
  v12 = (float)((float)0.70710677 * (float)radius);
  a4[4] = center->x + (float)((float)0.70710677 * (float)radius);
  a4[5] = (float)((float)0.70710677 * (float)radius) + (float)y;
  v13 = (float)((float)radius * (float)-1.0);
  v14 = center->y;
  a4[6] = center->x + (float)((float)radius * (float)0.9238795);
  a4[7] = (float)((float)radius * (float)0.38268343) + (float)v14;
  v15 = center->x;
  v16 = (float)((float)-0.70710677 * (float)radius);
  v17 = v16;
  a4[9] = (float)((float)radius * (float)0.0) + center->y;
  a4[8] = (float)v15 + (float)radius;
  v18 = (float)((float)((float)radius * (float)-0.38268343) + center->y);
  a4[10] = center->x + (float)((float)radius * (float)0.9238795);
  a4[11] = v18;
  v19 = (float)((float)((float)-0.70710677 * (float)radius) + center->y);
  a4[12] = center->x + (float)((float)0.70710677 * (float)radius);
  a4[13] = v19;
  v21 = (float)(center->x + (float)((float)radius * (float)0.38268343));
  v20 = (float)((float)((float)radius * (float)-0.9238795) + center->y);
  a4[14] = v21;
  a4[15] = v20;
  v22 = center->y;
  a4[16] = center->x + (float)v5;
  a4[17] = (float)v13 + (float)v22;
  v23 = (float)(center->x + (float)v8);
  a4[19] = (float)v9 + center->y;
  a4[18] = v23;
  v24 = center->x;
  a4[21] = (float)v16 + center->y;
  a4[20] = (float)v24 + (float)v16;
  v25 = (float)(center->x + (float)v9);
  a4[23] = (float)v8 + center->y;
  a4[22] = v25;
  v26 = (float)((float)v5 + center->y);
  a4[24] = center->x + (float)v13;
  a4[25] = v26;
  v27 = (float)((float)v6 + center->y);
  a4[26] = center->x + (float)v9;
  a4[27] = v27;
  v28 = (float)((float)v12 + center->y);
  a4[28] = center->x + (float)v17;
  a4[29] = v28;
  v29 = (float)((float)v7 + center->y);
  a4[30] = center->x + (float)v8;
  a4[31] = v29;
}


// ========================================================================
// ?Plane2DFromPoints@idObstacleAvoidanceCore@@CA?AVidVec3@@ABVidVec2@@0_N@Z
// EA  : 0x826BDA80
// RVA : 0x006BDA80
// PDB : w:\tech5\engine\gamelib\aas2\obstacleavoidancecore.cpp
// ========================================================================

idVec3 *__fastcall idObstacleAvoidanceCore::Plane2DFromPoints(
        idVec3 *result,
        const idVec2 *start,
        const idVec2 *end,
        const bool normalize)
{
  double y; // fp9
  double x; // fp8
  double v6; // fp0
  double v7; // fp13
  double v10; // fp2
  double v11; // fp3
  double v12; // fp2

  y = start->y;
  x = start->x;
  v6 = (float)(start->y - end->y);
  v7 = (float)(end->x - start->x);
  result->x = start->y - end->y;
  result->y = v7;
  if ( normalize )
  {
    _FP5 = (float)((float)((float)((float)v7 * (float)v7) + (float)((float)v6 * (float)v6))
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm { fsel      f3, f5, f6, f11 }
    v10 = __frsqrte(_FP3);
    v11 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v10
                                                                                        * (float)((float)((float)((float)v7 * (float)v7) + (float)((float)v6 * (float)v6))
                                                                                                * (float)0.5))
                                                                                * (float)v10)
                                                                        - (float)1.5)
                                                        * (float)v10)
                                                * (float)((float)((float)((float)v7 * (float)v7)
                                                                + (float)((float)v6 * (float)v6))
                                                        * (float)0.5))
                                        * (float)((float)-(float)((float)((float)((float)v10
                                                                                * (float)((float)((float)((float)v7 * (float)v7)
                                                                                                + (float)((float)v6 * (float)v6))
                                                                                        * (float)0.5))
                                                                        * (float)v10)
                                                                - (float)1.5)
                                                * (float)v10))
                                - (float)1.5)
                * (float)((float)-(float)((float)((float)((float)v10
                                                        * (float)((float)((float)((float)v7 * (float)v7)
                                                                        + (float)((float)v6 * (float)v6))
                                                                * (float)0.5))
                                                * (float)v10)
                                        - (float)1.5)
                        * (float)v10));
    v12 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v10
                                                                                                * (float)((float)((float)((float)v7 * (float)v7) + (float)((float)v6 * (float)v6)) * (float)0.5))
                                                                                        * (float)v10)
                                                                                - (float)1.5)
                                                                * (float)v10)
                                                        * (float)((float)((float)((float)v7 * (float)v7)
                                                                        + (float)((float)v6 * (float)v6))
                                                                * (float)0.5))
                                                * (float)((float)-(float)((float)((float)((float)v10
                                                                                        * (float)((float)((float)((float)v7 * (float)v7) + (float)((float)v6 * (float)v6))
                                                                                                * (float)0.5))
                                                                                * (float)v10)
                                                                        - (float)1.5)
                                                        * (float)v10))
                                        - (float)1.5)
                        * (float)((float)-(float)((float)((float)((float)v10
                                                                * (float)((float)((float)((float)v7 * (float)v7)
                                                                                + (float)((float)v6 * (float)v6))
                                                                        * (float)0.5))
                                                        * (float)v10)
                                                - (float)1.5)
                                * (float)v10))
                * (float)((float)((float)((float)v7 * (float)v7) + (float)((float)v6 * (float)v6)) * (float)0.5));
    result->x = (float)v6 * (float)((float)-(float)((float)((float)v12 * (float)v11) - (float)1.5) * (float)v11);
    result->y = (float)v7 * (float)((float)-(float)((float)((float)v12 * (float)v11) - (float)1.5) * (float)v11);
  }
  result->z = -(float)((float)(result->x * (float)x) + (float)(result->y * (float)y));
  return result;
}


// ========================================================================
// ?Plane2DFromVecs@idObstacleAvoidanceCore@@CA?AVidVec3@@ABVidVec2@@0_N@Z
// EA  : 0x826BDB30
// RVA : 0x006BDB30
// PDB : w:\tech5\engine\gamelib\aas2\obstacleavoidancecore.cpp
// ========================================================================

idVec3 *__fastcall idObstacleAvoidanceCore::Plane2DFromVecs(
        idVec3 *result,
        const idVec2 *start,
        const idVec2 *dir,
        const bool normalize)
{
  double x; // fp13
  double v5; // fp12
  double v8; // fp4
  double v9; // fp8

  x = dir->x;
  v5 = -dir->y;
  result->x = v5;
  result->y = x;
  if ( normalize )
  {
    _FP7 = (float)((float)((float)((float)x * (float)x) + (float)((float)v5 * (float)v5))
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm { fsel      f5, f7, f8, f11 }
    v8 = __frsqrte(_FP5);
    v9 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v8
                                                                                       * (float)((float)((float)((float)x * (float)x) + (float)((float)v5 * (float)v5))
                                                                                               * (float)0.5))
                                                                               * (float)v8)
                                                                       - (float)1.5)
                                                       * (float)v8)
                                               * (float)((float)((float)((float)x * (float)x)
                                                               + (float)((float)v5 * (float)v5))
                                                       * (float)0.5))
                                       * (float)((float)-(float)((float)((float)((float)v8
                                                                               * (float)((float)((float)((float)x * (float)x)
                                                                                               + (float)((float)v5 * (float)v5))
                                                                                       * (float)0.5))
                                                                       * (float)v8)
                                                               - (float)1.5)
                                               * (float)v8))
                               - (float)1.5)
               * (float)((float)-(float)((float)((float)((float)v8
                                                       * (float)((float)((float)((float)x * (float)x)
                                                                       + (float)((float)v5 * (float)v5))
                                                               * (float)0.5))
                                               * (float)v8)
                                       - (float)1.5)
                       * (float)v8));
    result->x = (float)v5
              * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v8 * (float)((float)((float)((float)x * (float)x) + (float)((float)v5 * (float)v5)) * (float)0.5)) * (float)v8) - (float)1.5) * (float)v8)
                                                                                              * (float)((float)((float)((float)x * (float)x) + (float)((float)v5 * (float)v5)) * (float)0.5))
                                                                                      * (float)((float)-(float)((float)((float)((float)v8 * (float)((float)((float)((float)x * (float)x) + (float)((float)v5 * (float)v5)) * (float)0.5)) * (float)v8) - (float)1.5)
                                                                                              * (float)v8))
                                                                              - (float)1.5)
                                                              * (float)((float)-(float)((float)((float)((float)v8 * (float)((float)((float)((float)x * (float)x) + (float)((float)v5 * (float)v5)) * (float)0.5))
                                                                                              * (float)v8)
                                                                                      - (float)1.5)
                                                                      * (float)v8))
                                                      * (float)((float)((float)((float)x * (float)x)
                                                                      + (float)((float)v5 * (float)v5))
                                                              * (float)0.5))
                                              * (float)v9)
                                      - (float)1.5)
                      * (float)v9);
    result->y = (float)x
              * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v8 * (float)((float)((float)((float)x * (float)x) + (float)((float)v5 * (float)v5)) * (float)0.5)) * (float)v8) - (float)1.5) * (float)v8)
                                                                                              * (float)((float)((float)((float)x * (float)x) + (float)((float)v5 * (float)v5)) * (float)0.5))
                                                                                      * (float)((float)-(float)((float)((float)((float)v8 * (float)((float)((float)((float)x * (float)x) + (float)((float)v5 * (float)v5)) * (float)0.5)) * (float)v8) - (float)1.5)
                                                                                              * (float)v8))
                                                                              - (float)1.5)
                                                              * (float)((float)-(float)((float)((float)((float)v8 * (float)((float)((float)((float)x * (float)x) + (float)((float)v5 * (float)v5)) * (float)0.5))
                                                                                              * (float)v8)
                                                                                      - (float)1.5)
                                                                      * (float)v8))
                                                      * (float)((float)((float)((float)x * (float)x)
                                                                      + (float)((float)v5 * (float)v5))
                                                              * (float)0.5))
                                              * (float)v9)
                                      - (float)1.5)
                      * (float)v9);
  }
  result->z = -(float)((float)(start->y * result->y) + (float)(result->x * start->x));
  return result;
}


// ========================================================================
// ?PointInsideWinding@idObstacleAvoidanceCore@@CA_NPBVidVec2@@HABV2@M@Z
// EA  : 0x826BDBD8
// RVA : 0x006BDBD8
// PDB : w:\tech5\engine\gamelib\aas2\obstacleavoidancecore.cpp
// ========================================================================

int __fastcall idObstacleAvoidanceCore::PointInsideWinding(
        const idVec2 *winding,
        int numPoints,
        const idVec2 *point,
        double epsilon)
{
  int v4; // r11
  const idVec2 *i; // r10
  double y; // fp9
  double x; // fp8
  const idVec2 *v8; // r9
  double v9; // fp6
  double v12; // fp2
  double v13; // fp7
  double v14; // fp2

  v4 = 0;
  if ( numPoints <= 0 )
    return 1;
  for ( i = winding; ; ++i )
  {
    ++v4;
    y = i->y;
    x = i->x;
    __twllei(numPoints, 0);
    v8 = &winding[v4 % numPoints];
    __twlgei(numPoints & ~(__ROL4__(v4, 1) - 1), 0xFFFFFFFF);
    v9 = (float)((float)y - v8->y);
    _FP7 = (float)((float)((float)((float)(v8->x - (float)x) * (float)(v8->x - (float)x))
                         + (float)((float)v9 * (float)v9))
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm { fsel      f3, f7, f2, f13 }
    v12 = __frsqrte(_FP3);
    v13 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v12
                                                                                        * (float)((float)((float)((float)(v8->x - (float)x) * (float)(v8->x - (float)x)) + (float)((float)v9 * (float)v9))
                                                                                                * (float)0.5))
                                                                                * (float)v12)
                                                                        - (float)1.5)
                                                        * (float)v12)
                                                * (float)((float)((float)((float)(v8->x - (float)x)
                                                                        * (float)(v8->x - (float)x))
                                                                + (float)((float)v9 * (float)v9))
                                                        * (float)0.5))
                                        * (float)((float)-(float)((float)((float)((float)v12
                                                                                * (float)((float)((float)((float)(v8->x - (float)x) * (float)(v8->x - (float)x))
                                                                                                + (float)((float)v9 * (float)v9))
                                                                                        * (float)0.5))
                                                                        * (float)v12)
                                                                - (float)1.5)
                                                * (float)v12))
                                - (float)1.5)
                * (float)((float)-(float)((float)((float)((float)v12
                                                        * (float)((float)((float)((float)(v8->x - (float)x)
                                                                                * (float)(v8->x - (float)x))
                                                                        + (float)((float)v9 * (float)v9))
                                                                * (float)0.5))
                                                * (float)v12)
                                        - (float)1.5)
                        * (float)v12));
    v14 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v12 * (float)((float)((float)((float)(v8->x - (float)x) * (float)(v8->x - (float)x)) + (float)((float)v9 * (float)v9)) * (float)0.5)) * (float)v12) - (float)1.5)
                                                                                                * (float)v12)
                                                                                        * (float)((float)((float)((float)(v8->x - (float)x) * (float)(v8->x - (float)x)) + (float)((float)v9 * (float)v9))
                                                                                                * (float)0.5))
                                                                                * (float)((float)-(float)((float)((float)((float)v12 * (float)((float)((float)((float)(v8->x - (float)x) * (float)(v8->x - (float)x)) + (float)((float)v9 * (float)v9)) * (float)0.5)) * (float)v12) - (float)1.5)
                                                                                        * (float)v12))
                                                                        - (float)1.5)
                                                        * (float)((float)-(float)((float)((float)((float)v12
                                                                                                * (float)((float)((float)((float)(v8->x - (float)x) * (float)(v8->x - (float)x)) + (float)((float)v9 * (float)v9)) * (float)0.5))
                                                                                        * (float)v12)
                                                                                - (float)1.5)
                                                                * (float)v12))
                                                * (float)((float)((float)((float)(v8->x - (float)x)
                                                                        * (float)(v8->x - (float)x))
                                                                + (float)((float)v9 * (float)v9))
                                                        * (float)0.5))
                                        * (float)v13)
                                - (float)1.5)
                * (float)v13);
    if ( (float)((float)((float)(point->x * (float)((float)v14 * (float)((float)y - v8->y)))
                       + (float)(point->y * (float)((float)v14 * (float)(v8->x - (float)x))))
               - (float)((float)((float)x * (float)((float)v14 * (float)((float)y - v8->y)))
                       + (float)((float)y * (float)((float)v14 * (float)(v8->x - (float)x))))) > epsilon )
      break;
    if ( v4 >= numPoints )
      return 1;
  }
  return 0;
}


// ========================================================================
// ?ExpandWinding@idObstacleAvoidanceCore@@CAXPBVidVec2@@HMPAV2@@Z
// EA  : 0x826BDCD0
// RVA : 0x006BDCD0
// PDB : w:\tech5\engine\gamelib\aas2\obstacleavoidancecore.cpp
// ========================================================================

void __fastcall idObstacleAvoidanceCore::ExpandWinding(
        const idVec2 *winding,
        int numPoints,
        double d,
        idVec2 *expanded,
        int a5)
{
  int v5; // r10
  int v6; // ctr
  int v7; // r8
  float *v8; // r11
  double v9; // fp13
  double v10; // fp11
  double v11; // fp10
  const idVec2 *v12; // r9
  double v13; // fp6
  double v14; // fp7
  double v15; // fp4
  double v18; // fp8
  double v19; // fp8
  double v20; // fp6
  int v21; // r10
  float *v22; // r8
  int v23; // r28
  int v24; // r27
  int v25; // r26
  float *p_y; // r9
  float *v27; // r11
  double v28; // fp10
  double v29; // fp9
  double v30; // fp0
  double v31; // fp8
  double v32; // fp7
  double v33; // fp6
  double v34; // fp5
  double v35; // fp4
  float *v36; // r7
  double v37; // fp2
  double v38; // fp9
  float *v39; // r7
  double v40; // fp3
  double v41; // fp11
  float *v42; // r7
  double v43; // fp9
  double v44; // fp6
  double v45; // fp0
  unsigned int v46; // r30
  float *v47; // r7
  double v48; // fp2
  float *v49; // r9
  int v50; // r31
  int v51; // ctr
  int v52; // r5
  float *v53; // r11
  int v54; // r3
  double v55; // fp10
  double v56; // fp9
  unsigned int v57; // r29
  float *v58; // r8
  double v59; // fp8
  _BYTE v60[4]; // [sp+0h] [-100h] BYREF
  _BYTE back_chain[4]; // [sp+4h] [-FCh] BYREF
  _BYTE v62[4]; // [sp+8h] [-F8h] BYREF
  _BYTE v63[4]; // [sp+Ch] [-F4h] BYREF
  char v64; // [sp+10h] [-F0h] BYREF

  v5 = 0;
  if ( numPoints > 0 )
  {
    v6 = numPoints;
    v7 = (char *)winding - back_chain;
    v8 = (float *)back_chain;
    v9 = idMath::FLT_SMALLEST_NON_DENORMAL;
    do
    {
      ++v5;
      v10 = *(float *)((char *)v8 + v7);
      v11 = *(float *)((char *)v8 + v7 + 4);
      v12 = &winding[v5 % numPoints];
      __twllei(numPoints, 0);
      __twlgei(numPoints & ~(__ROL4__(v5, 1) - 1), 0xFFFFFFFF);
      v13 = (float)(v12->x - (float)v10);
      v14 = (float)((float)v11 - v12->y);
      *(v8 - 1) = (float)v11 - v12->y;
      *v8 = v13;
      v15 = v13;
      _FP11 = (float)((float)((float)((float)v14 * (float)v14) + (float)((float)v13 * (float)v13)) - (float)v9);
      __asm { fsel      f9, f11, f2, f13 }
      v18 = __frsqrte(_FP9);
      v19 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v18
                                                                                          * (float)((float)((float)((float)v14 * (float)v14) + (float)((float)v13 * (float)v13))
                                                                                                  * (float)0.5))
                                                                                  * (float)v18)
                                                                          - (float)1.5)
                                                          * (float)v18)
                                                  * (float)((float)((float)((float)v14 * (float)v14)
                                                                  + (float)((float)v13 * (float)v13))
                                                          * (float)0.5))
                                          * (float)((float)-(float)((float)((float)((float)v18
                                                                                  * (float)((float)((float)((float)v14 * (float)v14)
                                                                                                  + (float)((float)v13 * (float)v13))
                                                                                          * (float)0.5))
                                                                          * (float)v18)
                                                                  - (float)1.5)
                                                  * (float)v18))
                                  - (float)1.5)
                  * (float)((float)-(float)((float)((float)((float)v18
                                                          * (float)((float)((float)((float)v14 * (float)v14)
                                                                          + (float)((float)v13 * (float)v13))
                                                                  * (float)0.5))
                                                  * (float)v18)
                                          - (float)1.5)
                          * (float)v18));
      v20 = (float)-(float)((float)((float)((float)v19
                                          * (float)((float)((float)((float)v14 * (float)v14)
                                                          + (float)((float)v13 * (float)v13))
                                                  * (float)0.5))
                                  * (float)v19)
                          - (float)1.5);
      *(v8 - 1) = (float)v14 * (float)((float)v20 * (float)v19);
      *v8 = (float)v15 * (float)((float)v20 * (float)v19);
      *(v8 - 1) = (float)((float)v14 * (float)((float)v20 * (float)v19)) * (float)d;
      *v8 = (float)((float)v15 * (float)((float)v20 * (float)v19)) * (float)d;
      v8 += 2;
      --v6;
    }
    while ( v6 != 0 );
  }
  v21 = 0;
  if ( numPoints >= 4 )
  {
    v22 = (float *)&v60[-24];
    v23 = numPoints - 1;
    v24 = numPoints + 1;
    v25 = numPoints + 2;
    p_y = &winding[-1].y;
    v27 = (float *)(a5 + 12);
    do
    {
      v28 = (float)(p_y[1] + v22[6]);
      v29 = (float)(p_y[2] + v22[7]);
      v22 += 8;
      v30 = *v22;
      v31 = *(float *)&v60[(_DWORD)v27 - a5];
      v32 = *(float *)&back_chain[(_DWORD)v27 - a5];
      v33 = *(float *)&v62[(_DWORD)v27 - a5];
      v34 = *(float *)&v63[(_DWORD)v27 - a5];
      v35 = *(float *)((char *)v27 + (_DWORD)(&v64 - a5));
      v36 = (float *)&v60[8 * ((v23 + v21) % numPoints)];
      v37 = v36[1];
      *(v27 - 3) = *v36 + (float)v28;
      *(v27 - 2) = (float)v37 + (float)v29;
      v38 = (float)((float)v31 + *(float *)((char *)v27 + (_DWORD)winding - a5));
      v39 = (float *)&v60[8 * ((v21 + numPoints) % numPoints)];
      v40 = v39[1];
      *(v27 - 1) = *v39 + (float)(p_y[3] + (float)v30);
      *v27 = (float)v40 + (float)v38;
      v41 = (float)((float)v33 + p_y[6]);
      v42 = (float *)&v60[8 * ((v24 + v21) % numPoints)];
      v43 = v42[1];
      v27[1] = *v42 + (float)((float)v32 + p_y[5]);
      v27[2] = (float)v43 + (float)v41;
      v44 = p_y[7];
      p_y += 8;
      v45 = *p_y;
      __twllei(numPoints, 0);
      __twllei(numPoints, 0);
      __twllei(numPoints, 0);
      v46 = numPoints & ~(__ROL4__(v25 + v21, 1) - 1);
      __twlgei(numPoints & ~(__ROL4__(v23 + v21, 1) - 1), 0xFFFFFFFF);
      __twlgei(numPoints & ~(__ROL4__(v21 + numPoints, 1) - 1), 0xFFFFFFFF);
      __twlgei(numPoints & ~(__ROL4__(v24 + v21, 1) - 1), 0xFFFFFFFF);
      v47 = (float *)&v60[8 * ((v25 + v21) % numPoints)];
      v21 += 4;
      __twllei(numPoints, 0);
      __twlgei(v46, 0xFFFFFFFF);
      v48 = v47[1];
      v27[3] = *v47 + (float)((float)v34 + (float)v44);
      v27[4] = (float)v48 + (float)((float)v35 + (float)v45);
      v27 += 8;
    }
    while ( v21 < numPoints - 3 );
  }
  if ( v21 < numPoints )
  {
    v49 = (float *)(8 * v21 + a5);
    v50 = v60 - (_BYTE *)winding;
    v51 = numPoints - v21;
    v52 = numPoints - 1;
    v53 = &winding[v21].y;
    v54 = a5 - (_DWORD)winding;
    do
    {
      v55 = (float)(*(float *)&v60[(_DWORD)v49 - a5] + *(v53 - 1));
      v56 = (float)(*(float *)((char *)v53 + v50) + *v53);
      v57 = numPoints & ~(__ROL4__(v52 + v21, 1) - 1);
      v58 = (float *)&v60[8 * ((v52 + v21) % numPoints)];
      __twllei(numPoints, 0);
      ++v21;
      v59 = *v58;
      __twlgei(v57, 0xFFFFFFFF);
      *v49 = (float)v59 + (float)v55;
      v49 += 2;
      *(float *)((char *)v53 + v54) = v58[1] + (float)v56;
      v53 += 2;
      --v51;
    }
    while ( v51 != 0 );
  }
}


// ========================================================================
// ?GetAxialBevel@idObstacleAvoidanceCore@@CA_NABVidVec3@@0ABVidVec2@@AAV2@@Z
// EA  : 0x826BE068
// RVA : 0x006BE068
// PDB : w:\tech5\engine\gamelib\aas2\obstacleavoidancecore.cpp
// ========================================================================

int __fastcall idObstacleAvoidanceCore::GetAxialBevel(
        const idVec3 *plane1,
        const idVec3 *plane2,
        const idVec2 *point,
        idVec3 *bevel)
{
  double v4; // fp0
  double v6; // fp0

  if ( (LODWORD(plane1->x) ^ LODWORD(plane2->x)) >= 0 || __fabs(plane1->x) <= 0.1 || __fabs(plane2->x) <= 0.1 )
  {
    if ( (LODWORD(plane2->y) ^ LODWORD(plane1->y)) >= 0 || __fabs(plane1->y) <= 0.1 || __fabs(plane2->y) <= 0.1 )
    {
      return 0;
    }
    else
    {
      bevel->y = 0.0;
      if ( plane1->x >= 0.0 )
        v6 = 1.0;
      else
        v6 = -1.0;
      bevel->x = v6;
      bevel->z = -(float)((float)(point->x * bevel->x) + (float)(point->y * (float)0.0));
      return 1;
    }
  }
  else
  {
    bevel->x = 0.0;
    if ( plane1->y >= 0.0 )
      v4 = 1.0;
    else
      v4 = -1.0;
    bevel->y = v4;
    bevel->z = -(float)((float)(point->y * bevel->y) + (float)(point->x * (float)0.0));
    return 1;
  }
}


// ========================================================================
// ?ExpandWindingForAxialBox@idObstacleAvoidanceCore@@CAHPAVidVec2@@HQBV2@@Z
// EA  : 0x826BE190
// RVA : 0x006BE190
// PDB : w:\tech5\engine\gamelib\aas2\obstacleavoidancecore.cpp
// ========================================================================

int __fastcall idObstacleAvoidanceCore::ExpandWindingForAxialBox(idVec2 *winding, int numPoints, const idVec2 *bounds)
{
  signed int v6; // r31
  int v7; // r11
  idVec3 *v8; // r26
  const idVec3 *p_y; // r25
  idVec2 *v10; // r28
  int v11; // r29
  double x; // fp0
  double y; // fp13
  idVec2 *v14; // r5
  double v15; // fp9
  double v16; // fp13
  double z; // fp12
  double v18; // fp13
  double v19; // fp12
  idVec3 *v20; // r29
  double v21; // fp13
  double v22; // fp12
  signed int v23; // r10
  float *v24; // r11
  double v25; // fp2
  double v26; // fp7
  double v27; // fp6
  double v28; // fp4
  double v29; // fp3
  double v30; // fp1
  float *p_z; // r11
  int v32; // ctr
  double v33; // fp7
  int result; // r3
  int v35; // r9
  int v36; // r5
  int v37; // r4
  int v38; // r30
  idVec2 *v39; // r6
  float *v40; // r11
  double v41; // fp0
  double v42; // fp13
  double v43; // fp9
  idVec3 *v44; // r10
  double v45; // fp12
  double v46; // fp10
  double v47; // fp7
  char v48; // r10
  double v49; // fp9
  double v50; // fp3
  double v51; // fp1
  double v52; // fp0
  double v53; // fp0
  double v54; // fp13
  double v55; // fp9
  idVec3 *v56; // r10
  double v57; // fp12
  double v58; // fp10
  double v59; // fp7
  char v60; // r10
  double v61; // fp9
  double v62; // fp3
  double v63; // fp1
  double v64; // fp0
  double v65; // fp0
  double v66; // fp13
  double v67; // fp9
  idVec3 *v68; // r10
  double v69; // fp12
  double v70; // fp10
  double v71; // fp7
  char v72; // r10
  double v73; // fp9
  double v74; // fp3
  double v75; // fp1
  double v76; // fp0
  double v77; // fp0
  double v78; // fp13
  double v79; // fp9
  idVec3 *v80; // r10
  double v81; // fp12
  double v82; // fp10
  double v83; // fp7
  char v84; // r10
  double v85; // fp9
  double v86; // fp3
  double v87; // fp1
  double v88; // fp0
  idVec2 *v89; // r6
  int v90; // r5
  int v91; // ctr
  float *v92; // r10
  double v93; // fp13
  double v94; // fp0
  double v95; // fp9
  idVec3 *v96; // r11
  double v97; // fp12
  double v98; // fp10
  double v99; // fp7
  char v100; // r11
  double v101; // fp9
  double v102; // fp3
  double v103; // fp1
  double v104; // fp0
  idVec3 v105; // [sp+50h] [-130h] BYREF
  idVec3 v106; // [sp+60h] [-120h] BYREF
  char v107; // [sp+6Ch] [-114h] BYREF
  idVec3 v108[16]; // [sp+70h] [-110h] BYREF

  v6 = 0;
  v7 = 0;
  if ( numPoints > 0 )
  {
    v8 = v108;
    p_y = (idVec3 *)&v106.y;
    v10 = winding;
    do
    {
      v11 = v7 + 1;
      x = v10->x;
      y = v10->y;
      __twllei(numPoints, 0);
      v14 = &winding[(v7 + 1) % numPoints];
      __twlgei(numPoints & ~(__ROL4__(v7 + 1, 1) - 1), 0xFFFFFFFF);
      v15 = (float)(v14->y - (float)y);
      if ( (float)((float)((float)v15 * (float)v15) + (float)((float)(v14->x - (float)x) * (float)(v14->x - (float)x))) >= 0.0099999998 )
      {
        idObstacleAvoidanceCore::Plane2DFromPoints(result: &v106, start: v10, end: v14, normalize: true);
        if ( v6 > 0
          && (unsigned __int8)idObstacleAvoidanceCore::GetAxialBevel(
                                plane1: p_y,
                                plane2: &v106,
                                point: v10,
                                bevel: &v105) != 0 )
        {
          v16 = v105.y;
          ++v6;
          z = v105.z;
          ++p_y;
          v8->x = v105.x;
          v8->y = v16;
          v8->z = z;
          ++v8;
        }
        v18 = v106.y;
        ++v6;
        v19 = v106.z;
        ++p_y;
        v8->x = v106.x;
        v8->y = v18;
        v8->z = v19;
        ++v8;
      }
      v7 = v11;
      ++v10;
    }
    while ( v11 < numPoints );
  }
  v20 = &v108[v6];
  if ( (unsigned __int8)idObstacleAvoidanceCore::GetAxialBevel(
                          plane1: v20 - 1,
                          plane2: v108,
                          point: winding,
                          bevel: &v105) != 0 )
  {
    ++v6;
    v21 = v105.y;
    v22 = v105.z;
    v20->x = v105.x;
    v20->y = v21;
    v20->z = v22;
  }
  v23 = 0;
  if ( v6 >= 4 )
  {
    v24 = (float *)&v107;
    do
    {
      v23 += 4;
      v25 = v24[9];
      v26 = (float)((float)(v24[5] * *(float *)((char *)&bounds->y + ((*((_DWORD *)v24 + 5) >> 28) & 8)))
                  + (float)(v24[4] * *(float *)((char *)&bounds->x + ((*((_DWORD *)v24 + 4) >> 28) & 8))));
      v27 = (float)((float)(v24[8] * *(float *)((char *)&bounds->y + ((*((_DWORD *)v24 + 8) >> 28) & 8)))
                  + (float)(v24[7] * *(float *)((char *)&bounds->x + ((*((_DWORD *)v24 + 7) >> 28) & 8))));
      v28 = (float)((float)(v24[11] * *(float *)((char *)&bounds->y + ((*((_DWORD *)v24 + 11) >> 28) & 8)))
                  + (float)(v24[10] * *(float *)((char *)&bounds->x + ((*((_DWORD *)v24 + 10) >> 28) & 8))));
      v29 = v24[6];
      v30 = v24[12];
      v24[3] = (float)((float)(v24[2] * *(float *)((char *)&bounds->y + ((*((_DWORD *)v24 + 2) >> 28) & 8)))
                     + (float)(v24[1] * *(float *)((char *)&bounds->x + ((*((_DWORD *)v24 + 1) >> 28) & 8))))
             + v24[3];
      v24[6] = (float)v26 + (float)v29;
      v24[9] = (float)v27 + (float)v25;
      v24 += 12;
      *v24 = (float)v28 + (float)v30;
    }
    while ( v23 < v6 - 3 );
  }
  if ( v23 < v6 )
  {
    p_z = &v108[v23 - 1].z;
    v32 = v6 - v23;
    do
    {
      v33 = (float)((float)((float)(p_z[2] * *(float *)((char *)&bounds->y + ((*((_DWORD *)p_z + 2) >> 28) & 8)))
                          + (float)(p_z[1] * *(float *)((char *)&bounds->x + ((*((_DWORD *)p_z + 1) >> 28) & 8))))
                  + p_z[3]);
      p_z += 3;
      *p_z = v33;
      --v32;
    }
    while ( v32 != 0 );
  }
  result = 0;
  v35 = 0;
  if ( v6 >= 4 )
  {
    v36 = v6 - 1;
    v37 = v6 + 1;
    v38 = v6 + 2;
    v39 = winding;
    v40 = &v108[0].y;
    do
    {
      v41 = *v40;
      v42 = *(v40 - 1);
      v43 = (float)((float)(*(v40 - 1) * *(v40 - 1)) + (float)(*v40 * *v40));
      __twllei(v6, 0);
      __twlgei(v6 & ~(__ROL4__(v36 + v35, 1) - 1), 0xFFFFFFFF);
      v44 = &v108[(v36 + v35) % v6];
      v45 = v44->y;
      v46 = (float)((float)((float)v42 * v44->x) + (float)((float)v41 * v44->y));
      v47 = (float)((float)((float)v43 * (float)((float)(v44->x * v44->x) + (float)(v44->y * v44->y)))
                  - (float)((float)v46 * (float)v46));
      if ( __fabs(v47) >= 0.000001 )
      {
        v49 = (float)(v44->z * (float)v43);
        v50 = (float)((float)((float)(v40[1] * (float)((float)((float)v42 * v44->x) + (float)((float)v41 * v44->y)))
                            - (float)v49)
                    * (float)((float)1.0 / (float)v47));
        v51 = (float)((float)v41
                    * (float)((float)((float)(v44->z
                                            * (float)((float)((float)v42 * v44->x) + (float)((float)v41 * v44->y)))
                                    - (float)(v40[1] * (float)((float)(v44->x * v44->x) + (float)(v44->y * v44->y))))
                            * (float)((float)1.0 / (float)v47)));
        v52 = (float)((float)(v44->x
                            * (float)((float)((float)(v40[1]
                                                    * (float)((float)((float)v42 * v44->x) + (float)((float)v41 * v44->y)))
                                            - (float)v49)
                                    * (float)((float)1.0 / (float)v47)))
                    + (float)((float)v42
                            * (float)((float)((float)(v44->z
                                                    * (float)((float)((float)v42 * v44->x) + (float)((float)v41 * v44->y)))
                                            - (float)(v40[1]
                                                    * (float)((float)(v44->x * v44->x) + (float)(v44->y * v44->y))))
                                    * (float)((float)1.0 / (float)v47))));
        v48 = 1;
        v39->x = v52;
        v39->y = (float)((float)v45 * (float)v50) + (float)v51;
      }
      else
      {
        v48 = 0;
      }
      if ( v48 != 0 )
      {
        ++result;
        ++v39;
      }
      v53 = v40[3];
      v54 = v40[2];
      v55 = (float)((float)(v40[2] * v40[2]) + (float)(v40[3] * v40[3]));
      __twllei(v6, 0);
      __twlgei(v6 & ~(__ROL4__(v35 + v6, 1) - 1), 0xFFFFFFFF);
      v56 = &v108[(v35 + v6) % v6];
      v57 = v56->y;
      v58 = (float)((float)((float)v54 * v56->x) + (float)((float)v53 * v56->y));
      v59 = (float)((float)((float)v55 * (float)((float)(v56->x * v56->x) + (float)(v56->y * v56->y)))
                  - (float)((float)v58 * (float)v58));
      if ( __fabs(v59) >= 0.000001 )
      {
        v61 = (float)(v56->z * (float)v55);
        v62 = (float)((float)((float)(v40[4] * (float)((float)((float)v54 * v56->x) + (float)((float)v53 * v56->y)))
                            - (float)v61)
                    * (float)((float)1.0 / (float)v59));
        v63 = (float)((float)v53
                    * (float)((float)((float)(v56->z
                                            * (float)((float)((float)v54 * v56->x) + (float)((float)v53 * v56->y)))
                                    - (float)(v40[4] * (float)((float)(v56->x * v56->x) + (float)(v56->y * v56->y))))
                            * (float)((float)1.0 / (float)v59)));
        v64 = (float)((float)(v56->x
                            * (float)((float)((float)(v40[4]
                                                    * (float)((float)((float)v54 * v56->x) + (float)((float)v53 * v56->y)))
                                            - (float)v61)
                                    * (float)((float)1.0 / (float)v59)))
                    + (float)((float)v54
                            * (float)((float)((float)(v56->z
                                                    * (float)((float)((float)v54 * v56->x) + (float)((float)v53 * v56->y)))
                                            - (float)(v40[4]
                                                    * (float)((float)(v56->x * v56->x) + (float)(v56->y * v56->y))))
                                    * (float)((float)1.0 / (float)v59))));
        v60 = 1;
        v39->x = v64;
        v39->y = (float)((float)v57 * (float)v62) + (float)v63;
      }
      else
      {
        v60 = 0;
      }
      if ( v60 != 0 )
      {
        ++result;
        ++v39;
      }
      v65 = v40[6];
      v66 = v40[5];
      v67 = (float)((float)(v40[5] * v40[5]) + (float)(v40[6] * v40[6]));
      __twllei(v6, 0);
      __twlgei(v6 & ~(__ROL4__(v37 + v35, 1) - 1), 0xFFFFFFFF);
      v68 = &v108[(v37 + v35) % v6];
      v69 = v68->y;
      v70 = (float)((float)((float)v66 * v68->x) + (float)((float)v65 * v68->y));
      v71 = (float)((float)((float)v67 * (float)((float)(v68->x * v68->x) + (float)(v68->y * v68->y)))
                  - (float)((float)v70 * (float)v70));
      if ( __fabs(v71) >= 0.000001 )
      {
        v73 = (float)(v68->z * (float)v67);
        v74 = (float)((float)((float)(v40[7] * (float)((float)((float)v66 * v68->x) + (float)((float)v65 * v68->y)))
                            - (float)v73)
                    * (float)((float)1.0 / (float)v71));
        v75 = (float)((float)v65
                    * (float)((float)((float)(v68->z
                                            * (float)((float)((float)v66 * v68->x) + (float)((float)v65 * v68->y)))
                                    - (float)(v40[7] * (float)((float)(v68->x * v68->x) + (float)(v68->y * v68->y))))
                            * (float)((float)1.0 / (float)v71)));
        v76 = (float)((float)(v68->x
                            * (float)((float)((float)(v40[7]
                                                    * (float)((float)((float)v66 * v68->x) + (float)((float)v65 * v68->y)))
                                            - (float)v73)
                                    * (float)((float)1.0 / (float)v71)))
                    + (float)((float)v66
                            * (float)((float)((float)(v68->z
                                                    * (float)((float)((float)v66 * v68->x) + (float)((float)v65 * v68->y)))
                                            - (float)(v40[7]
                                                    * (float)((float)(v68->x * v68->x) + (float)(v68->y * v68->y))))
                                    * (float)((float)1.0 / (float)v71))));
        v72 = 1;
        v39->x = v76;
        v39->y = (float)((float)v69 * (float)v74) + (float)v75;
      }
      else
      {
        v72 = 0;
      }
      if ( v72 != 0 )
      {
        ++result;
        ++v39;
      }
      v77 = v40[9];
      v78 = v40[8];
      v79 = (float)((float)(v40[8] * v40[8]) + (float)(v40[9] * v40[9]));
      __twllei(v6, 0);
      __twlgei(v6 & ~(__ROL4__(v38 + v35, 1) - 1), 0xFFFFFFFF);
      v80 = &v108[(v38 + v35) % v6];
      v81 = v80->y;
      v82 = (float)((float)((float)v78 * v80->x) + (float)((float)v77 * v80->y));
      v83 = (float)((float)((float)v79 * (float)((float)(v80->x * v80->x) + (float)(v80->y * v80->y)))
                  - (float)((float)v82 * (float)v82));
      if ( __fabs(v83) >= 0.000001 )
      {
        v85 = (float)(v80->z * (float)v79);
        v86 = (float)((float)((float)(v40[10] * (float)((float)((float)v78 * v80->x) + (float)((float)v77 * v80->y)))
                            - (float)v85)
                    * (float)((float)1.0 / (float)v83));
        v87 = (float)((float)v77
                    * (float)((float)((float)(v80->z
                                            * (float)((float)((float)v78 * v80->x) + (float)((float)v77 * v80->y)))
                                    - (float)(v40[10] * (float)((float)(v80->x * v80->x) + (float)(v80->y * v80->y))))
                            * (float)((float)1.0 / (float)v83)));
        v88 = (float)((float)(v80->x
                            * (float)((float)((float)(v40[10]
                                                    * (float)((float)((float)v78 * v80->x) + (float)((float)v77 * v80->y)))
                                            - (float)v85)
                                    * (float)((float)1.0 / (float)v83)))
                    + (float)((float)v78
                            * (float)((float)((float)(v80->z
                                                    * (float)((float)((float)v78 * v80->x) + (float)((float)v77 * v80->y)))
                                            - (float)(v40[10]
                                                    * (float)((float)(v80->x * v80->x) + (float)(v80->y * v80->y))))
                                    * (float)((float)1.0 / (float)v83))));
        v84 = 1;
        v39->x = v88;
        v39->y = (float)((float)v81 * (float)v86) + (float)v87;
      }
      else
      {
        v84 = 0;
      }
      if ( v84 != 0 )
      {
        ++result;
        ++v39;
      }
      v35 += 4;
      v40 += 12;
    }
    while ( v35 < v6 - 3 );
  }
  if ( v35 < v6 )
  {
    v89 = &winding[result];
    v90 = v6 - 1;
    v91 = v6 - v35;
    v92 = &v108[v35].y;
    do
    {
      v93 = *(v92 - 1);
      v94 = *v92;
      v95 = (float)((float)(*v92 * *v92) + (float)(*(v92 - 1) * *(v92 - 1)));
      __twllei(v6, 0);
      __twlgei(v6 & ~(__ROL4__(v90 + v35, 1) - 1), 0xFFFFFFFF);
      v96 = &v108[(v90 + v35) % v6];
      v97 = v96->y;
      v98 = (float)((float)(v96->x * (float)v93) + (float)(v96->y * (float)v94));
      v99 = (float)((float)((float)v95 * (float)((float)(v96->x * v96->x) + (float)(v96->y * v96->y)))
                  - (float)((float)v98 * (float)v98));
      if ( __fabs(v99) >= 0.000001 )
      {
        v101 = (float)(v96->z * (float)v95);
        v102 = (float)((float)((float)(v92[1] * (float)((float)(v96->x * (float)v93) + (float)(v96->y * (float)v94)))
                             - (float)v101)
                     * (float)((float)1.0 / (float)v99));
        v103 = (float)((float)v94
                     * (float)((float)((float)(v96->z
                                             * (float)((float)(v96->x * (float)v93) + (float)(v96->y * (float)v94)))
                                     - (float)(v92[1] * (float)((float)(v96->x * v96->x) + (float)(v96->y * v96->y))))
                             * (float)((float)1.0 / (float)v99)));
        v104 = (float)((float)(v96->x
                             * (float)((float)((float)(v92[1]
                                                     * (float)((float)(v96->x * (float)v93)
                                                             + (float)(v96->y * (float)v94)))
                                             - (float)v101)
                                     * (float)((float)1.0 / (float)v99)))
                     + (float)((float)v93
                             * (float)((float)((float)(v96->z
                                                     * (float)((float)(v96->x * (float)v93)
                                                             + (float)(v96->y * (float)v94)))
                                             - (float)(v92[1]
                                                     * (float)((float)(v96->x * v96->x) + (float)(v96->y * v96->y))))
                                     * (float)((float)1.0 / (float)v99))));
        v100 = 1;
        v89->x = v104;
        v89->y = (float)((float)v97 * (float)v102) + (float)v103;
      }
      else
      {
        v100 = 0;
      }
      if ( v100 != 0 )
      {
        ++result;
        ++v89;
      }
      ++v35;
      v92 += 3;
      --v91;
    }
    while ( v91 != 0 );
  }
  return result;
}


// ========================================================================
// ?GetWindingBounds@idObstacleAvoidanceCore@@CAXPBVidVec2@@HQAV2@@Z
// EA  : 0x826BE918
// RVA : 0x006BE918
// PDB : w:\tech5\engine\gamelib\aas2\obstacleavoidancecore.cpp
// ========================================================================

void __fastcall idObstacleAvoidanceCore::GetWindingBounds(const idVec2 *winding, int numPoints, idVec2 *bounds)
{
  double x; // fp0
  idVec2 *v4; // r9
  int v5; // r10
  const idVec2 *v6; // r11
  double v7; // fp0
  double y; // fp0
  double v9; // fp0
  double v10; // fp0
  double v11; // fp0
  double v12; // fp0
  double v13; // fp0
  double v14; // fp0
  const idVec2 *v15; // r11
  int v16; // ctr
  double v17; // fp0
  double v18; // fp0

  if ( numPoints != 0 )
  {
    x = winding->x;
    v4 = bounds + 1;
    bounds[1] = *winding;
    v5 = 1;
    bounds->x = x;
    bounds->y = bounds[1].y;
    if ( numPoints > 1 )
    {
      if ( numPoints - 1 >= 4 )
      {
        v6 = winding + 2;
        do
        {
          v7 = v6[-1].x;
          if ( v7 >= bounds->x )
          {
            if ( v7 > v4->x )
              v4->x = v6[-1].x;
          }
          else
          {
            bounds->x = v6[-1].x;
          }
          y = v6[-1].y;
          if ( y >= bounds->y )
          {
            if ( y > bounds[1].y )
              bounds[1].y = v6[-1].y;
          }
          else
          {
            bounds->y = v6[-1].y;
          }
          v9 = v6->x;
          if ( v9 >= bounds->x )
          {
            if ( v9 > v4->x )
              v4->x = v6->x;
          }
          else
          {
            bounds->x = v6->x;
          }
          v10 = v6->y;
          if ( v10 >= bounds->y )
          {
            if ( v10 > bounds[1].y )
              bounds[1].y = v6->y;
          }
          else
          {
            bounds->y = v6->y;
          }
          v11 = v6[1].x;
          if ( v11 >= bounds->x )
          {
            if ( v11 > v4->x )
              v4->x = v6[1].x;
          }
          else
          {
            bounds->x = v6[1].x;
          }
          v12 = v6[1].y;
          if ( v12 >= bounds->y )
          {
            if ( v12 > bounds[1].y )
              bounds[1].y = v6[1].y;
          }
          else
          {
            bounds->y = v6[1].y;
          }
          v13 = v6[2].x;
          if ( v13 >= bounds->x )
          {
            if ( v13 > v4->x )
              v4->x = v6[2].x;
          }
          else
          {
            bounds->x = v6[2].x;
          }
          v14 = v6[2].y;
          if ( v14 >= bounds->y )
          {
            if ( v14 > bounds[1].y )
              bounds[1].y = v6[2].y;
          }
          else
          {
            bounds->y = v6[2].y;
          }
          v5 += 4;
          v6 += 4;
        }
        while ( v5 < numPoints - 3 );
      }
      if ( v5 < numPoints )
      {
        v15 = &winding[v5];
        v16 = numPoints - v5;
        do
        {
          v17 = v15->x;
          if ( v17 >= bounds->x )
          {
            if ( v17 > v4->x )
              v4->x = v15->x;
          }
          else
          {
            bounds->x = v15->x;
          }
          v18 = v15->y;
          if ( v18 >= bounds->y )
          {
            if ( v18 > bounds[1].y )
              bounds[1].y = v15->y;
          }
          else
          {
            bounds->y = v15->y;
          }
          ++v15;
          --v16;
        }
        while ( v16 != 0 );
      }
    }
  }
  else
  {
    bounds->y = 1.0e30;
    bounds->x = 1.0e30;
    bounds[1].y = -1.0e30;
    bounds[1].x = -1.0e30;
  }
}


// ========================================================================
// ?LineIntersectsPath@idObstacleAvoidanceCore@@ABA_NABVidVec2@@0PBUpathNode_t@1@@Z
// EA  : 0x826BEB50
// RVA : 0x006BEB50
// PDB : w:\tech5\engine\gamelib\aas2\obstacleavoidancecore.cpp
// ========================================================================

int __fastcall idObstacleAvoidanceCore::LineIntersectsPath(
        idObstacleAvoidanceCore *this,
        const idVec2 *start,
        const idVec2 *end,
        const idObstacleAvoidanceCore::pathNode_t *node)
{
  idObstacleAvoidanceCore::pathNode_t *parent; // r11
  idObstacleAvoidanceCore::pathNode_t **p_parent; // r10
  unsigned int v9; // r9
  unsigned int v10; // r8
  idVec3 v12; // [sp+58h] [-38h] BYREF

  idObstacleAvoidanceCore::Plane2DFromPoints(result: &v12, start, end, normalize: false);
  parent = node->parent;
  p_parent = &node->parent;
  v9 = COERCE_UNSIGNED_INT((float)((float)(node->pos.y * v12.y) + (float)(v12.x * node->pos.x)) + v12.z) >> 31;
  if ( parent == nullptr )
    return 0;
  while ( 1 )
  {
    v10 = COERCE_UNSIGNED_INT((float)((float)((*p_parent)->pos.y * v12.y) + (float)((*p_parent)->pos.x * v12.x)) + v12.z) >> 31;
    if ( v10 != v9
      && ((COERCE_UNSIGNED_INT(
             (float)((float)(end->y * (float)(parent->pos.x - node->pos.x))
                   + (float)(end->x * (float)(node->pos.y - parent->pos.y)))
           - (float)((float)(node->pos.y * (float)(parent->pos.x - node->pos.x))
                   + (float)(node->pos.x * (float)(node->pos.y - parent->pos.y))))
         ^ COERCE_UNSIGNED_INT(
             (float)((float)(start->y * (float)(parent->pos.x - node->pos.x))
                   + (float)(start->x * (float)(node->pos.y - parent->pos.y)))
           - (float)((float)(node->pos.y * (float)(parent->pos.x - node->pos.x))
                   + (float)(node->pos.x * (float)(node->pos.y - parent->pos.y)))))
        & 0x80000000) != 0 )
    {
      break;
    }
    p_parent = &parent->parent;
    node = parent;
    parent = parent->parent;
    v9 = v10;
    if ( parent == nullptr )
      return 0;
  }
  return 1;
}


// ========================================================================
// ?PointInsideObstacle@idObstacleAvoidanceCore@@ABAHABVidVec2@@@Z
// EA  : 0x826BEC78
// RVA : 0x006BEC78
// PDB : w:\tech5\engine\gamelib\aas2\obstacleavoidancecore.cpp
// ========================================================================

int __fastcall idObstacleAvoidanceCore::PointInsideObstacle(idObstacleAvoidanceCore *this, const idVec2 *point)
{
  idObstacleAvoidanceCore::expandedObstacle_t *expandedObstacles; // r26
  int numExpandedObstacles; // r27
  int v6; // r28
  double x; // fp31
  int v8; // r31
  double v9; // fp1
  float *v10; // r11
  double y; // fp0

  expandedObstacles = this->expandedObstacles;
  if ( expandedObstacles == nullptr )
    return -1;
  numExpandedObstacles = this->numExpandedObstacles;
  v6 = 0;
  if ( numExpandedObstacles <= 0 )
    return -1;
  x = point->x;
  v8 = 0;
  v9 = 0.1;
  while ( 1 )
  {
    v10 = (float *)&expandedObstacles[v8];
    if ( x >= expandedObstacles[v8].bounds[0].x )
    {
      y = point->y;
      if ( y >= v10[1]
        && x <= v10[2]
        && y <= v10[3]
        && (unsigned __int8)idObstacleAvoidanceCore::PointInsideWinding(
                              winding: this->expandedObstacles[v8].winding,
                              numPoints: this->expandedObstacles[v8].numPoints,
                              point,
                              epsilon: v9) != 0 )
      {
        break;
      }
    }
    ++v6;
    ++v8;
    if ( v6 >= numExpandedObstacles )
      return -1;
  }
  return v6;
}


// ========================================================================
// ?PointInsideObstacleList@idObstacleAvoidanceCore@@ABAHPBHHABVidVec2@@@Z
// EA  : 0x826BED48
// RVA : 0x006BED48
// PDB : w:\tech5\engine\gamelib\aas2\obstacleavoidancecore.cpp
// ========================================================================

int __fastcall idObstacleAvoidanceCore::PointInsideObstacleList(
        idObstacleAvoidanceCore *this,
        int *obstacleList,
        int numObstacles,
        const idVec2 *point)
{
  idObstacleAvoidanceCore::expandedObstacle_t *expandedObstacles; // r28
  int v8; // r26
  double x; // fp31
  double v11; // fp1
  int v12; // r30
  int v13; // r10
  float *v14; // r11
  double y; // fp0

  expandedObstacles = this->expandedObstacles;
  if ( expandedObstacles == nullptr )
    return -1;
  v8 = 0;
  if ( numObstacles <= 0 )
    return -1;
  x = point->x;
  v11 = 0.1;
  while ( 1 )
  {
    v12 = *obstacleList;
    v13 = *obstacleList;
    v14 = (float *)&expandedObstacles[v13];
    if ( x >= expandedObstacles[v13].bounds[0].x )
    {
      y = point->y;
      if ( y >= v14[1]
        && x <= v14[2]
        && y <= v14[3]
        && (unsigned __int8)idObstacleAvoidanceCore::PointInsideWinding(
                              winding: this->expandedObstacles[v13].winding,
                              numPoints: this->expandedObstacles[v13].numPoints,
                              point,
                              epsilon: v11) != 0 )
      {
        break;
      }
    }
    ++v8;
    ++obstacleList;
    if ( v8 >= numObstacles )
      return -1;
  }
  return v12;
}


// ========================================================================
// ?GetBspNodesForLine_r@idObstacleAvoidanceCore@@ABAHABVidVec2@@0HHQAH@Z
// EA  : 0x826BEE20
// RVA : 0x006BEE20
// PDB : w:\tech5\engine\gamelib\aas2\obstacleavoidancecore.cpp
// ========================================================================

int __fastcall idObstacleAvoidanceCore::GetBspNodesForLine_r(
        idObstacleAvoidanceCore *this,
        const idVec2 *p1,
        const idVec2 *p2,
        int nodeNum,
        int numNodes,
        int *nodes)
{
  const idVec2 *v7; // r28
  int v11; // r7
  idObstacleAvoidanceCore::bspNode_t *v12; // r31
  int v13; // r11
  double v14; // fp0
  double v15; // fp13
  int v16; // r6
  int BspNodesForLine_r; // r3
  __int16 v18; // r10
  BOOL v19; // r26
  double v20; // fp3
  idVec2 v21[8]; // [sp+50h] [-40h] BYREF

  v7 = p1;
  if ( this->bspNodes == nullptr )
    return 0;
  nodes[numNodes] = nodeNum;
  v11 = numNodes + 1;
  v12 = &this->bspNodes[nodeNum];
  if ( v12->axis < 0 )
    return v11;
  v13 = 4 * v12->axis;
  v14 = (float)(*(float *)((char *)&p1->x + v13) - v12->dist);
  v15 = (float)(*(float *)((char *)&p2->x + v13) - v12->dist);
  if ( v14 < 0.1 || v15 < 0.1 )
  {
    if ( v14 >= -0.1 || v15 >= -0.1 )
    {
      if ( __fabs((float)((float)(*(float *)((char *)&p1->x + v13) - v12->dist)
                        - (float)(*(float *)((char *)&p2->x + v13) - v12->dist))) > idMath::FLT_SMALLEST_NON_DENORMAL )
      {
        v19 = v14 < v15;
        v20 = (float)(p1->y
                    + (float)((float)(p2->y - p1->y)
                            * (float)((float)v14
                                    / (float)((float)v14 - (float)(*(float *)((char *)&p2->x + v13) - v12->dist)))));
        v21[0].x = p1->x
                 + (float)((float)(p2->x - p1->x)
                         * (float)((float)v14
                                 / (float)((float)v14 - (float)(*(float *)((char *)&p2->x + v13) - v12->dist))));
        v21[0].y = v20;
        BspNodesForLine_r = idObstacleAvoidanceCore::GetBspNodesForLine_r(
                              this,
                              p1,
                              p2: v21,
                              nodeNum: v12->children[v19],
                              numNodes: v11,
                              nodes);
        p1 = v21;
        v18 = v12->children[!v19];
      }
      else
      {
        BspNodesForLine_r = idObstacleAvoidanceCore::GetBspNodesForLine_r(
                              this,
                              p1,
                              p2,
                              nodeNum: v12->children[0],
                              numNodes: v11,
                              nodes);
        v18 = v12->children[1];
        p1 = v7;
      }
      v16 = v18;
      v11 = BspNodesForLine_r;
    }
    else
    {
      v16 = v12->children[1];
    }
  }
  else
  {
    v16 = v12->children[0];
  }
  return idObstacleAvoidanceCore::GetBspNodesForLine_r(this, p1, p2, nodeNum: v16, numNodes: v11, nodes);
}


// ========================================================================
// ?SetupBspTree_r@idObstacleAvoidanceCore@@AAAFABVidVec2@@0HH@Z
// EA  : 0x826BEFC8
// RVA : 0x006BEFC8
// PDB : w:\tech5\engine\gamelib\aas2\obstacleavoidancecore.cpp
// ========================================================================

int __fastcall idObstacleAvoidanceCore::SetupBspTree_r(
        idObstacleAvoidanceCore *this,
        const idVec2 *center,
        const idVec2 *span,
        int axis,
        int depth)
{
  int numBspNodes; // r11
  idObstacleAvoidanceCore::bspNode_t *v8; // r31
  int v9; // r28
  int v10; // r27
  int v11; // r8
  int v12; // r29
  double x; // fp11
  double y; // fp10
  double v15; // fp9
  double v16; // fp8
  double v17; // fp13
  double v18; // fp0
  double v19; // fp6
  idVec2 v20; // [sp+50h] [-60h] BYREF
  idVec2 v21; // [sp+58h] [-58h] BYREF
  idVec2 v22[10]; // [sp+60h] [-50h] BYREF

  if ( this->bspNodes == nullptr )
    return 0;
  numBspNodes = this->numBspNodes;
  v8 = &this->bspNodes[numBspNodes];
  this->numBspNodes = numBspNodes + 1;
  v9 = (__int16)numBspNodes;
  v8->indexOffset = 0;
  v8->numIndices = 0;
  if ( depth < 4 )
  {
    v8->axis = axis;
    v10 = axis ^ 1;
    v11 = 4 * (axis ^ 1);
    v8->dist = *(&center->x + axis);
    v12 = depth + 1;
    x = center->x;
    y = center->y;
    v15 = *(float *)((char *)&center->x + v11);
    v16 = *(float *)((char *)&span->x + v11);
    v17 = (float)(span->y * (float)0.5);
    v18 = (float)(span->x * (float)0.5);
    v19 = (float)(center->y + (float)(span->y * (float)0.5));
    v20.x = span->x * (float)0.5;
    v20.y = v17;
    v21.y = v19;
    v22[0].y = (float)y - (float)v17;
    *(float *)((char *)&v20.x + v11) = v16;
    v21.x = (float)x + (float)v18;
    v22[0].x = (float)x - (float)v18;
    *(float *)((char *)&v21.x + v11) = v15;
    *(float *)((char *)&v22[0].x + v11) = v15;
    v8->children[0] = idObstacleAvoidanceCore::SetupBspTree_r(
                        this,
                        center: &v21,
                        span: &v20,
                        axis: axis ^ 1,
                        depth: depth + 1);
    v8->children[1] = idObstacleAvoidanceCore::SetupBspTree_r(this, center: v22, span: &v20, axis: v10, depth: v12);
    return v9;
  }
  else
  {
    v8->axis = -1;
    v8->children[1] = -1;
    v8->children[0] = -1;
    v8->dist = 0.0;
    return (__int16)numBspNodes;
  }
}


// ========================================================================
// ?FilterObstacleIntoBspTree@idObstacleAvoidanceCore@@AAAXFHPAF@Z
// EA  : 0x826BF110
// RVA : 0x006BF110
// PDB : w:\tech5\engine\gamelib\aas2\obstacleavoidancecore.cpp
// ========================================================================

void __fastcall idObstacleAvoidanceCore::FilterObstacleIntoBspTree(
        idObstacleAvoidanceCore *this,
        __int16 nodeNum,
        int obstacleNum,
        __int16 *obstacleNodes)
{
  idObstacleAvoidanceCore::bspNode_t *bspNodes; // r31
  idObstacleAvoidanceCore::expandedObstacle_t *expandedObstacles; // r7
  unsigned int v6; // r8
  idObstacleAvoidanceCore::bspNode_t *v7; // r11
  int axis; // r10
  double dist; // fp0
  int v10; // r10

  bspNodes = this->bspNodes;
  if ( this->bspNodes != nullptr )
  {
    expandedObstacles = this->expandedObstacles;
    while ( expandedObstacles != nullptr )
    {
      v6 = nodeNum;
      v7 = &bspNodes[v6];
      axis = bspNodes[v6].axis;
      if ( axis < 0 )
        goto LABEL_9;
      dist = v7->dist;
      v10 = 8 * obstacleNum + axis;
      if ( *(&expandedObstacles->bounds[0].x + v10) <= dist )
      {
        if ( *(&expandedObstacles->bounds[1].x + v10) >= dist )
        {
LABEL_9:
          obstacleNodes[obstacleNum] = nodeNum;
          ++this->bspNodes[v6].numIndices;
          return;
        }
        nodeNum = v7->children[1];
      }
      else
      {
        nodeNum = v7->children[0];
      }
    }
  }
}


// ========================================================================
// ?ExtrudeDir@@YA?AVidVec2@@ABV1@0@Z
// EA  : 0x826BF1A8
// RVA : 0x006BF1A8
// PDB : w:\tech5\engine\gamelib\aas2\obstacleavoidancecore.cpp
// ========================================================================

idVec2 *__fastcall ExtrudeDir(idVec2 *result, const idVec2 *normal1, const idVec2 *normal2)
{
  double y; // fp0
  double v4; // fp13
  double v5; // fp13
  double v6; // fp10

  y = normal1->y;
  v4 = normal2->y;
  if ( (float)((float)(normal2->x * normal1->x) + (float)(normal2->y * normal1->y)) <= -0.70710677 )
  {
    result->x = normal2->x + normal1->x;
    result->y = (float)v4 + (float)y;
  }
  else
  {
    v5 = (float)(normal2->y + normal1->y);
    v6 = (float)((float)1.0
               / (float)((float)((float)(normal2->x * normal1->x) + (float)(normal2->y * normal1->y)) + (float)1.0));
    result->x = (float)(normal2->x + normal1->x)
              * (float)((float)1.0
                      / (float)((float)((float)(normal2->x * normal1->x) + (float)(normal2->y * normal1->y)) + (float)1.0));
    result->y = (float)v5 * (float)v6;
  }
  return result;
}


// ========================================================================
// ?SetupWallOrLedgeWinding@idObstacleAvoidanceCore@@AAAXAAUexpandedObstacle_t@1@HHHPBUobstacleEdge_t@@PBUobstacleVertex_t@@@Z
// EA  : 0x826BF210
// RVA : 0x006BF210
// PDB : w:\tech5\engine\gamelib\aas2\obstacleavoidancecore.cpp
// ========================================================================

void __fastcall idObstacleAvoidanceCore::SetupWallOrLedgeWinding(
        idObstacleAvoidanceCore *this,
        idObstacleAvoidanceCore::expandedObstacle_t *obstacle,
        int lastEdgeIndex,
        int currentEdgeIndex,
        int nextEdgeIndex,
        const obstacleEdge_t *edges,
        const obstacleVertex_t *vertices)
{
  const obstacleEdge_t *v9; // r11
  double v13; // fp0
  const obstacleVertex_t *v14; // r11
  const obstacleVertex_t *v15; // r27
  unsigned int v16; // r8
  double v17; // fp10
  double v18; // fp8
  int v19; // r25
  int numWindingPoints; // r10
  idVec2 *v21; // r28
  double v24; // fp2
  double v25; // fp7
  double v26; // fp25
  double v27; // fp31
  double v28; // fp28
  const obstacleEdge_t *v29; // r11
  const obstacleVertex_t *v30; // r29
  const obstacleVertex_t *v31; // r11
  unsigned int v32; // r9
  double v33; // fp11
  double x; // fp29
  int v35; // r23
  double v38; // fp3
  double v39; // fp8
  double v40; // fp24
  double v41; // fp23
  idVec2 *v42; // r11
  double v43; // fp10
  double v44; // fp7
  double v45; // fp9
  double y; // fp13
  idVec2 *v47; // r11
  double v48; // fp7
  double v49; // fp13
  double v50; // fp0
  double v51; // fp10
  idVec2 *v52; // r11
  double v53; // fp5
  double v54; // fp10
  idVec2 *winding; // r10
  double v56; // fp5
  const obstacleEdge_t *v57; // r11
  const obstacleVertex_t *v58; // r11
  const obstacleVertex_t *v59; // r10
  unsigned int v60; // r9
  double v61; // fp11
  int v62; // r30
  double v65; // fp2
  double v66; // fp7
  double v67; // fp30
  double v68; // fp29
  float *v69; // r11
  double v70; // fp4
  double v71; // fp3
  idVec2 *v72; // r11
  double v73; // fp7
  double v74; // fp11
  double v75; // fp13
  double v76; // fp0
  double v77; // fp9
  double v78; // fp10
  idVec2 *v79; // r11
  double v80; // fp3
  float *p_x; // r11
  double v82; // fp11
  idVec2 *v83; // r11
  idVec2 v87; // [sp+50h] [-D0h] BYREF
  idVec2 v88; // [sp+58h] [-C8h] BYREF
  idVec2 v89[13]; // [sp+60h] [-C0h] BYREF

  v9 = &edges[currentEdgeIndex];
  _R31 = obstacle;
  v13 = idMath::FLT_SMALLEST_NON_DENORMAL;
  v15 = &vertices[v9->verts[1]];
  v16 = v9->flags & 2;
  v14 = &vertices[v9->verts[0]];
  v17 = (float)(v15->position.y - v14->position.y);
  v18 = (float)(v14->position.x - v15->position.x);
  obstacle->numPoints = 4;
  v19 = ((_cntlzw(v16) & 0x20) != 0) - 3;
  obstacle->id = v19;
  numWindingPoints = this->numWindingPoints;
  v21 = &this->windingPoints[numWindingPoints];
  this->numWindingPoints = numWindingPoints + 4;
  obstacle->winding = v21;
  _FP5 = (float)((float)((float)((float)v18 * (float)v18) + (float)((float)v17 * (float)v17)) - (float)v13);
  __asm { fsel      f3, f5, f6, f0 }
  v24 = __frsqrte(_FP3);
  v25 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v24
                                                                                      * (float)((float)((float)((float)v18 * (float)v18) + (float)((float)v17 * (float)v17))
                                                                                              * (float)0.5))
                                                                              * (float)v24)
                                                                      - (float)1.5)
                                                      * (float)v24)
                                              * (float)((float)((float)((float)v18 * (float)v18)
                                                              + (float)((float)v17 * (float)v17))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v24
                                                                              * (float)((float)((float)((float)v18 * (float)v18)
                                                                                              + (float)((float)v17 * (float)v17))
                                                                                      * (float)0.5))
                                                                      * (float)v24)
                                                              - (float)1.5)
                                              * (float)v24))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v24
                                                      * (float)((float)((float)((float)v18 * (float)v18)
                                                                      + (float)((float)v17 * (float)v17))
                                                              * (float)0.5))
                                              * (float)v24)
                                      - (float)1.5)
                      * (float)v24));
  v26 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v24 * (float)((float)((float)((float)v18 * (float)v18) + (float)((float)v17 * (float)v17)) * (float)0.5)) * (float)v24) - (float)1.5) * (float)v24)
                                                                                              * (float)((float)((float)((float)v18 * (float)v18) + (float)((float)v17 * (float)v17)) * (float)0.5))
                                                                                      * (float)((float)-(float)((float)((float)((float)v24 * (float)((float)((float)((float)v18 * (float)v18) + (float)((float)v17 * (float)v17)) * (float)0.5)) * (float)v24) - (float)1.5)
                                                                                              * (float)v24))
                                                                              - (float)1.5)
                                                              * (float)((float)-(float)((float)((float)((float)v24 * (float)((float)((float)((float)v18 * (float)v18) + (float)((float)v17 * (float)v17)) * (float)0.5))
                                                                                              * (float)v24)
                                                                                      - (float)1.5)
                                                                      * (float)v24))
                                                      * (float)((float)((float)((float)v18 * (float)v18)
                                                                      + (float)((float)v17 * (float)v17))
                                                              * (float)0.5))
                                              * (float)v25)
                                      - (float)1.5)
                      * (float)v25)
              * (float)v18);
  v88.y = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v24 * (float)((float)((float)((float)v18 * (float)v18) + (float)((float)v17 * (float)v17)) * (float)0.5)) * (float)v24) - (float)1.5)
                                                                                                * (float)v24)
                                                                                        * (float)((float)((float)((float)v18 * (float)v18) + (float)((float)v17 * (float)v17))
                                                                                                * (float)0.5))
                                                                                * (float)((float)-(float)((float)((float)((float)v24 * (float)((float)((float)((float)v18 * (float)v18) + (float)((float)v17 * (float)v17)) * (float)0.5)) * (float)v24) - (float)1.5)
                                                                                        * (float)v24))
                                                                        - (float)1.5)
                                                        * (float)((float)-(float)((float)((float)((float)v24
                                                                                                * (float)((float)((float)((float)v18 * (float)v18) + (float)((float)v17 * (float)v17)) * (float)0.5))
                                                                                        * (float)v24)
                                                                                - (float)1.5)
                                                                * (float)v24))
                                                * (float)((float)((float)((float)v18 * (float)v18)
                                                                + (float)((float)v17 * (float)v17))
                                                        * (float)0.5))
                                        * (float)v25)
                                - (float)1.5)
                * (float)v25)
        * (float)v18;
  v27 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v24 * (float)((float)((float)((float)v18 * (float)v18) + (float)((float)v17 * (float)v17)) * (float)0.5)) * (float)v24) - (float)1.5) * (float)v24)
                                                                                              * (float)((float)((float)((float)v18 * (float)v18) + (float)((float)v17 * (float)v17)) * (float)0.5))
                                                                                      * (float)((float)-(float)((float)((float)((float)v24 * (float)((float)((float)((float)v18 * (float)v18) + (float)((float)v17 * (float)v17)) * (float)0.5)) * (float)v24) - (float)1.5)
                                                                                              * (float)v24))
                                                                              - (float)1.5)
                                                              * (float)((float)-(float)((float)((float)((float)v24 * (float)((float)((float)((float)v18 * (float)v18) + (float)((float)v17 * (float)v17)) * (float)0.5))
                                                                                              * (float)v24)
                                                                                      - (float)1.5)
                                                                      * (float)v24))
                                                      * (float)((float)((float)((float)v18 * (float)v18)
                                                                      + (float)((float)v17 * (float)v17))
                                                              * (float)0.5))
                                              * (float)v25)
                                      - (float)1.5)
                      * (float)v25)
              * (float)v17);
  v88.x = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v24 * (float)((float)((float)((float)v18 * (float)v18) + (float)((float)v17 * (float)v17)) * (float)0.5)) * (float)v24) - (float)1.5)
                                                                                                * (float)v24)
                                                                                        * (float)((float)((float)((float)v18 * (float)v18) + (float)((float)v17 * (float)v17))
                                                                                                * (float)0.5))
                                                                                * (float)((float)-(float)((float)((float)((float)v24 * (float)((float)((float)((float)v18 * (float)v18) + (float)((float)v17 * (float)v17)) * (float)0.5)) * (float)v24) - (float)1.5)
                                                                                        * (float)v24))
                                                                        - (float)1.5)
                                                        * (float)((float)-(float)((float)((float)((float)v24
                                                                                                * (float)((float)((float)((float)v18 * (float)v18) + (float)((float)v17 * (float)v17)) * (float)0.5))
                                                                                        * (float)v24)
                                                                                - (float)1.5)
                                                                * (float)v24))
                                                * (float)((float)((float)((float)v18 * (float)v18)
                                                                + (float)((float)v17 * (float)v17))
                                                        * (float)0.5))
                                        * (float)v25)
                                - (float)1.5)
                * (float)v25)
        * (float)v17;
  v28 = -v26;
  if ( lastEdgeIndex == -1 )
  {
    v54 = (float)(v14->position.y
                + (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v24 * (float)((float)((float)((float)v18 * (float)v18) + (float)((float)v17 * (float)v17)) * (float)0.5)) * (float)v24) - (float)1.5) * (float)v24) * (float)((float)((float)((float)v18 * (float)v18) + (float)((float)v17 * (float)v17)) * (float)0.5))
                                                                                                * (float)((float)-(float)((float)((float)((float)v24 * (float)((float)((float)((float)v18 * (float)v18) + (float)((float)v17 * (float)v17)) * (float)0.5)) * (float)v24) - (float)1.5) * (float)v24))
                                                                                        - (float)1.5)
                                                                        * (float)((float)-(float)((float)((float)((float)v24 * (float)((float)((float)((float)v18 * (float)v18) + (float)((float)v17 * (float)v17)) * (float)0.5)) * (float)v24)
                                                                                                - (float)1.5)
                                                                                * (float)v24))
                                                                * (float)((float)((float)((float)v18 * (float)v18)
                                                                                + (float)((float)v17 * (float)v17))
                                                                        * (float)0.5))
                                                        * (float)v25)
                                                - (float)1.5)
                                * (float)v25)
                        * (float)v17));
    v21[1].x = v14->position.x + (float)v28;
    v21[1].y = v54;
    winding = obstacle->winding;
    v56 = (float)(v14->position.y - (float)v27);
    winding[2].x = (float)(v14->position.x - (float)v28) - (float)((float)v27 * (float)8.0);
    winding[2].y = (float)v56 - (float)((float)v26 * (float)8.0);
  }
  else
  {
    v29 = &edges[lastEdgeIndex];
    v30 = &vertices[v29->verts[1]];
    v32 = v29->flags & 2;
    v31 = &vertices[v29->verts[0]];
    v33 = (float)(v30->position.y - v31->position.y);
    x = v30->position.x;
    v35 = ((_cntlzw(v32) & 0x20) != 0) - 3;
    _FP6 = (float)((float)((float)((float)(v31->position.x - v30->position.x)
                                 * (float)(v31->position.x - v30->position.x))
                         + (float)((float)v33 * (float)v33))
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm { fsel      f4, f6, f7, f0 }
    v38 = __frsqrte(_FP4);
    v39 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v38
                                                                                        * (float)((float)((float)((float)(v31->position.x - v30->position.x) * (float)(v31->position.x - v30->position.x)) + (float)((float)v33 * (float)v33))
                                                                                                * (float)0.5))
                                                                                * (float)v38)
                                                                        - (float)1.5)
                                                        * (float)v38)
                                                * (float)((float)((float)((float)(v31->position.x - v30->position.x)
                                                                        * (float)(v31->position.x - v30->position.x))
                                                                + (float)((float)v33 * (float)v33))
                                                        * (float)0.5))
                                        * (float)((float)-(float)((float)((float)((float)v38
                                                                                * (float)((float)((float)((float)(v31->position.x - v30->position.x) * (float)(v31->position.x - v30->position.x))
                                                                                                + (float)((float)v33 * (float)v33))
                                                                                        * (float)0.5))
                                                                        * (float)v38)
                                                                - (float)1.5)
                                                * (float)v38))
                                - (float)1.5)
                * (float)((float)-(float)((float)((float)((float)v38
                                                        * (float)((float)((float)((float)(v31->position.x
                                                                                        - v30->position.x)
                                                                                * (float)(v31->position.x
                                                                                        - v30->position.x))
                                                                        + (float)((float)v33 * (float)v33))
                                                                * (float)0.5))
                                                * (float)v38)
                                        - (float)1.5)
                        * (float)v38));
    v40 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v38 * (float)((float)((float)((float)(v31->position.x - v30->position.x) * (float)(v31->position.x - v30->position.x)) + (float)((float)v33 * (float)v33)) * (float)0.5)) * (float)v38) - (float)1.5) * (float)v38)
                                                                                                * (float)((float)((float)((float)(v31->position.x - v30->position.x) * (float)(v31->position.x - v30->position.x)) + (float)((float)v33 * (float)v33)) * (float)0.5))
                                                                                        * (float)((float)-(float)((float)((float)((float)v38 * (float)((float)((float)((float)(v31->position.x - v30->position.x) * (float)(v31->position.x - v30->position.x)) + (float)((float)v33 * (float)v33)) * (float)0.5)) * (float)v38) - (float)1.5)
                                                                                                * (float)v38))
                                                                                - (float)1.5)
                                                                * (float)((float)-(float)((float)((float)((float)v38 * (float)((float)((float)((float)(v31->position.x - v30->position.x) * (float)(v31->position.x - v30->position.x)) + (float)((float)v33 * (float)v33)) * (float)0.5))
                                                                                                * (float)v38)
                                                                                        - (float)1.5)
                                                                        * (float)v38))
                                                        * (float)((float)((float)((float)(v31->position.x
                                                                                        - v30->position.x)
                                                                                * (float)(v31->position.x
                                                                                        - v30->position.x))
                                                                        + (float)((float)v33 * (float)v33))
                                                                * (float)0.5))
                                                * (float)v39)
                                        - (float)1.5)
                        * (float)v39)
                * (float)(v31->position.x - v30->position.x));
    v41 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v38 * (float)((float)((float)((float)(v31->position.x - v30->position.x) * (float)(v31->position.x - v30->position.x)) + (float)((float)v33 * (float)v33)) * (float)0.5)) * (float)v38) - (float)1.5) * (float)v38)
                                                                                                * (float)((float)((float)((float)(v31->position.x - v30->position.x) * (float)(v31->position.x - v30->position.x)) + (float)((float)v33 * (float)v33)) * (float)0.5))
                                                                                        * (float)((float)-(float)((float)((float)((float)v38 * (float)((float)((float)((float)(v31->position.x - v30->position.x) * (float)(v31->position.x - v30->position.x)) + (float)((float)v33 * (float)v33)) * (float)0.5)) * (float)v38) - (float)1.5)
                                                                                                * (float)v38))
                                                                                - (float)1.5)
                                                                * (float)((float)-(float)((float)((float)((float)v38 * (float)((float)((float)((float)(v31->position.x - v30->position.x) * (float)(v31->position.x - v30->position.x)) + (float)((float)v33 * (float)v33)) * (float)0.5))
                                                                                                * (float)v38)
                                                                                        - (float)1.5)
                                                                        * (float)v38))
                                                        * (float)((float)((float)((float)(v31->position.x
                                                                                        - v30->position.x)
                                                                                * (float)(v31->position.x
                                                                                        - v30->position.x))
                                                                        + (float)((float)v33 * (float)v33))
                                                                * (float)0.5))
                                                * (float)v39)
                                        - (float)1.5)
                        * (float)v39)
                * (float)v33);
    v89[0].y = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v38 * (float)((float)((float)((float)(v31->position.x - v30->position.x) * (float)(v31->position.x - v30->position.x)) + (float)((float)v33 * (float)v33)) * (float)0.5)) * (float)v38) - (float)1.5) * (float)v38)
                                                                                             * (float)((float)((float)((float)(v31->position.x - v30->position.x) * (float)(v31->position.x - v30->position.x)) + (float)((float)v33 * (float)v33)) * (float)0.5))
                                                                                     * (float)((float)-(float)((float)((float)((float)v38 * (float)((float)((float)((float)(v31->position.x - v30->position.x) * (float)(v31->position.x - v30->position.x)) + (float)((float)v33 * (float)v33)) * (float)0.5)) * (float)v38) - (float)1.5)
                                                                                             * (float)v38))
                                                                             - (float)1.5)
                                                             * (float)((float)-(float)((float)((float)((float)v38 * (float)((float)((float)((float)(v31->position.x - v30->position.x) * (float)(v31->position.x - v30->position.x)) + (float)((float)v33 * (float)v33)) * (float)0.5))
                                                                                             * (float)v38)
                                                                                     - (float)1.5)
                                                                     * (float)v38))
                                                     * (float)((float)((float)((float)(v31->position.x - v30->position.x)
                                                                             * (float)(v31->position.x - v30->position.x))
                                                                     + (float)((float)v33 * (float)v33))
                                                             * (float)0.5))
                                             * (float)v39)
                                     - (float)1.5)
                     * (float)v39)
             * (float)(v31->position.x - v30->position.x);
    v89[0].x = v41;
    ExtrudeDir(result: &v87, normal1: v89, normal2: &v88);
    if ( v19 == -2 )
    {
      v21[1].x = x;
      v21[1].y = v30->position.y;
      v42 = _R31->winding;
      if ( v35 == -2 )
      {
        v43 = (float)(v87.x * (float)8.0);
        v44 = (float)(v30->position.x - (float)v28);
        v42[2].y = (float)(v30->position.y - (float)v27) - (float)(v87.y * (float)8.0);
        v42[2].x = (float)v44 - (float)v43;
      }
      else
      {
        v45 = (float)(v30->position.y + (float)v27);
        v42[2].x = (float)(v30->position.x + (float)v28) - (float)((float)v27 * (float)8.0);
        v42[2].y = (float)v45 - (float)((float)v26 * (float)8.0);
      }
    }
    else if ( v35 == -2 )
    {
      y = v30->position.y;
      v21[1].x = (float)((float)v27 * (float)12.0) + (float)x;
      v21[1].y = (float)((float)v26 * (float)12.0) + (float)y;
      v47 = _R31->winding;
      v48 = (float)(v30->position.y - (float)v41);
      v47[2].x = (float)(v30->position.x - (float)-v40) - (float)v41;
      v47[2].y = (float)v48 - (float)v40;
    }
    else
    {
      v49 = v87.y;
      v50 = v87.x;
      v51 = (float)(v87.x * (float)12.0);
      v21[1].y = (float)(v87.y * (float)12.0) + v30->position.y;
      v21[1].x = (float)v51 + (float)x;
      v52 = _R31->winding;
      v53 = (float)(v30->position.y - (float)v27);
      v52[2].x = (float)(v30->position.x - (float)v28) + (float)v50;
      v52[2].y = (float)v53 + (float)v49;
    }
  }
  if ( nextEdgeIndex == -1 )
  {
    p_x = &_R31->winding->x;
    v82 = (float)(v15->position.y + (float)v27);
    *p_x = v15->position.x + (float)v28;
    p_x[1] = v82;
    v70 = (float)((float)(v15->position.x + (float)v28) - (float)((float)v27 * (float)8.0));
    v71 = (float)((float)(v15->position.y + (float)v27) - (float)((float)v26 * (float)8.0));
    goto LABEL_19;
  }
  v57 = &edges[nextEdgeIndex];
  v59 = &vertices[v57->verts[1]];
  v60 = v57->flags & 2;
  v58 = &vertices[v57->verts[0]];
  v61 = (float)(v59->position.y - v58->position.y);
  v62 = ((_cntlzw(v60) & 0x20) != 0) - 3;
  _FP5 = (float)((float)((float)((float)(v58->position.x - v59->position.x) * (float)(v58->position.x - v59->position.x))
                       + (float)((float)v61 * (float)v61))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f3, f5, f6, f0 }
  v65 = __frsqrte(_FP3);
  v66 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v65
                                                                                      * (float)((float)((float)((float)(v58->position.x - v59->position.x) * (float)(v58->position.x - v59->position.x)) + (float)((float)v61 * (float)v61))
                                                                                              * (float)0.5))
                                                                              * (float)v65)
                                                                      - (float)1.5)
                                                      * (float)v65)
                                              * (float)((float)((float)((float)(v58->position.x - v59->position.x)
                                                                      * (float)(v58->position.x - v59->position.x))
                                                              + (float)((float)v61 * (float)v61))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v65
                                                                              * (float)((float)((float)((float)(v58->position.x - v59->position.x) * (float)(v58->position.x - v59->position.x))
                                                                                              + (float)((float)v61 * (float)v61))
                                                                                      * (float)0.5))
                                                                      * (float)v65)
                                                              - (float)1.5)
                                              * (float)v65))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v65
                                                      * (float)((float)((float)((float)(v58->position.x - v59->position.x)
                                                                              * (float)(v58->position.x - v59->position.x))
                                                                      + (float)((float)v61 * (float)v61))
                                                              * (float)0.5))
                                              * (float)v65)
                                      - (float)1.5)
                      * (float)v65));
  v68 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v65 * (float)((float)((float)((float)(v58->position.x - v59->position.x) * (float)(v58->position.x - v59->position.x)) + (float)((float)v61 * (float)v61)) * (float)0.5)) * (float)v65) - (float)1.5) * (float)v65)
                                                                                              * (float)((float)((float)((float)(v58->position.x - v59->position.x) * (float)(v58->position.x - v59->position.x)) + (float)((float)v61 * (float)v61)) * (float)0.5))
                                                                                      * (float)((float)-(float)((float)((float)((float)v65 * (float)((float)((float)((float)(v58->position.x - v59->position.x) * (float)(v58->position.x - v59->position.x)) + (float)((float)v61 * (float)v61)) * (float)0.5)) * (float)v65) - (float)1.5)
                                                                                              * (float)v65))
                                                                              - (float)1.5)
                                                              * (float)((float)-(float)((float)((float)((float)v65 * (float)((float)((float)((float)(v58->position.x - v59->position.x) * (float)(v58->position.x - v59->position.x)) + (float)((float)v61 * (float)v61)) * (float)0.5))
                                                                                              * (float)v65)
                                                                                      - (float)1.5)
                                                                      * (float)v65))
                                                      * (float)((float)((float)((float)(v58->position.x - v59->position.x)
                                                                              * (float)(v58->position.x - v59->position.x))
                                                                      + (float)((float)v61 * (float)v61))
                                                              * (float)0.5))
                                              * (float)v66)
                                      - (float)1.5)
                      * (float)v66)
              * (float)(v59->position.y - v58->position.y));
  v67 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v65 * (float)((float)((float)((float)(v58->position.x - v59->position.x) * (float)(v58->position.x - v59->position.x)) + (float)((float)v61 * (float)v61)) * (float)0.5)) * (float)v65) - (float)1.5) * (float)v65)
                                                                                              * (float)((float)((float)((float)(v58->position.x - v59->position.x) * (float)(v58->position.x - v59->position.x)) + (float)((float)v61 * (float)v61)) * (float)0.5))
                                                                                      * (float)((float)-(float)((float)((float)((float)v65 * (float)((float)((float)((float)(v58->position.x - v59->position.x) * (float)(v58->position.x - v59->position.x)) + (float)((float)v61 * (float)v61)) * (float)0.5)) * (float)v65) - (float)1.5)
                                                                                              * (float)v65))
                                                                              - (float)1.5)
                                                              * (float)((float)-(float)((float)((float)((float)v65 * (float)((float)((float)((float)(v58->position.x - v59->position.x) * (float)(v58->position.x - v59->position.x)) + (float)((float)v61 * (float)v61)) * (float)0.5))
                                                                                              * (float)v65)
                                                                                      - (float)1.5)
                                                                      * (float)v65))
                                                      * (float)((float)((float)((float)(v58->position.x - v59->position.x)
                                                                              * (float)(v58->position.x - v59->position.x))
                                                                      + (float)((float)v61 * (float)v61))
                                                              * (float)0.5))
                                              * (float)v66)
                                      - (float)1.5)
                      * (float)v66)
              * (float)(v58->position.x - v59->position.x));
  v89[0].x = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v65 * (float)((float)((float)((float)(v58->position.x - v59->position.x) * (float)(v58->position.x - v59->position.x)) + (float)((float)v61 * (float)v61)) * (float)0.5)) * (float)v65) - (float)1.5) * (float)v65)
                                                                                           * (float)((float)((float)((float)(v58->position.x - v59->position.x) * (float)(v58->position.x - v59->position.x)) + (float)((float)v61 * (float)v61)) * (float)0.5))
                                                                                   * (float)((float)-(float)((float)((float)((float)v65 * (float)((float)((float)((float)(v58->position.x - v59->position.x) * (float)(v58->position.x - v59->position.x)) + (float)((float)v61 * (float)v61)) * (float)0.5)) * (float)v65) - (float)1.5)
                                                                                           * (float)v65))
                                                                           - (float)1.5)
                                                           * (float)((float)-(float)((float)((float)((float)v65 * (float)((float)((float)((float)(v58->position.x - v59->position.x) * (float)(v58->position.x - v59->position.x)) + (float)((float)v61 * (float)v61)) * (float)0.5))
                                                                                           * (float)v65)
                                                                                   - (float)1.5)
                                                                   * (float)v65))
                                                   * (float)((float)((float)((float)(v58->position.x - v59->position.x)
                                                                           * (float)(v58->position.x - v59->position.x))
                                                                   + (float)((float)v61 * (float)v61))
                                                           * (float)0.5))
                                           * (float)v66)
                                   - (float)1.5)
                   * (float)v66)
           * (float)(v59->position.y - v58->position.y);
  v89[0].y = v67;
  ExtrudeDir(result: &v87, normal1: &v88, normal2: v89);
  v69 = &_R31->winding->x;
  if ( v19 == -2 )
  {
    *v69 = v15->position.x;
    if ( v62 == -2 )
    {
      v69[1] = v15->position.y;
      v70 = (float)((float)(v15->position.x + (float)v28) - (float)(v87.x * (float)8.0));
      v71 = (float)((float)(v15->position.y + (float)v27) - (float)(v87.y * (float)8.0));
LABEL_19:
      v83 = _R31->winding;
      v83[3].y = v71;
      v83[3].x = v70;
      goto LABEL_20;
    }
    v69[1] = v15->position.y;
    v72 = _R31->winding;
    v73 = (float)(v15->position.y - (float)v27);
    v72[3].x = (float)(v15->position.x - (float)v28) - (float)((float)v27 * (float)8.0);
    v72[3].y = (float)v73 - (float)((float)v26 * (float)8.0);
  }
  else
  {
    v74 = v15->position.y;
    if ( v62 == -2 )
    {
      *v69 = v15->position.x + (float)((float)v27 * (float)12.0);
      v69[1] = (float)v74 + (float)((float)v26 * (float)12.0);
      v70 = (float)((float)(v15->position.x + (float)-v67) - (float)v68);
      v71 = (float)((float)(v15->position.y + (float)v68) - (float)v67);
      goto LABEL_19;
    }
    v75 = v87.y;
    v76 = v87.x;
    v77 = (float)(v87.x * (float)12.0);
    v78 = v15->position.x;
    v69[1] = v15->position.y + (float)(v87.y * (float)12.0);
    *v69 = (float)v78 + (float)v77;
    v79 = _R31->winding;
    v80 = (float)(v15->position.y + (float)v27);
    v79[3].x = (float)(v15->position.x + (float)v28) + (float)v76;
    v79[3].y = (float)v80 + (float)v75;
  }
LABEL_20:
  _R11 = _R31->winding;
  _R9 = 16;
  _R10 = _R11 + 2;
  __asm
  {
    lvrx128   v63, r9, r11
    lvlx128   v62, r0, r11
    lvrx128   v61, r9, r10
    vor128    v60, v94, v63
    lvlx128   v59, r0, r10
    vor128    v58, v91, v61
    vminfp128 v57, v92, v58
    vmaxfp128 v56, v92, v58
    vpermwi128 v55, v57, 0xB1
    vpermwi128 v54, v56, 0xB1
    vminfp128 v53, v89, v55
    vmaxfp128 v52, v88, v54
    vsldoi128 v51, v85, v52, 8
    stvlx128  v51, r0, r31
    stvrx128  v51, r31, r9
  }
}


// ========================================================================
// ?GetPathNodeDelta@idObstacleAvoidanceCore@@AAA_NPAUpathNode_t@1@ABVidVec2@@ABVidBounds@@_N@Z
// EA  : 0x826BF808
// RVA : 0x006BF808
// PDB : w:\tech5\engine\gamelib\aas2\obstacleavoidancecore.cpp
// ========================================================================

int __fastcall idObstacleAvoidanceCore::GetPathNodeDelta(
        idObstacleAvoidanceCore *this,
        idObstacleAvoidanceCore::pathNode_t *node,
        const idVec2 *seekPos,
        const idBounds *clipBounds,
        __int64 passedCorner)
{
  idObstacleAvoidanceCore::expandedObstacle_t *expandedObstacles; // r8
  double x; // fp13
  double y; // fp12
  idVec2 *p_pos; // r29
  int v11; // r4
  idObstacleAvoidanceCore::expandedObstacle_t *v12; // r10
  idVec2 *p_delta; // r30
  signed int numPoints; // r11
  idVec2 *winding; // r10
  float *p_x; // r10
  double v17; // fp9
  double v18; // fp8
  int dir; // r10
  int edgeNum; // r9
  int v21; // r9
  double v22; // fp13
  int obstacle; // r8
  double v24; // fp12
  unsigned int v25; // r6
  int v26; // r9
  int v27; // r10
  int v28; // r28
  idVec2 *v29; // r9
  int v30; // r10
  double v31; // fp8
  double v32; // fp5
  double v33; // fp9
  double v34; // fp31
  double v35; // fp8
  double v36; // fp30
  double v37; // fp3
  idVec2 v38; // r10
  double v39; // fp11
  double v40; // fp12
  double v41; // fp0
  double v43; // fp6
  double v45; // fp4
  double v46; // fp0
  int v47; // r9
  idObstacleAvoidanceCore::pathNode_t *parent; // r11
  __int64 v49; // [sp+50h] [-40h] BYREF

  expandedObstacles = this->expandedObstacles;
  if ( expandedObstacles == nullptr )
    return 0;
  x = node->pos.x;
  y = node->pos.y;
  p_pos = &node->pos;
  v11 = node->dir + node->edgeNum;
  v12 = &expandedObstacles[node->obstacle];
  p_delta = &node->delta;
  numPoints = v12->numPoints;
  winding = v12->winding;
  __twllei(numPoints, 0);
  __twlgei(numPoints & ~(__ROL4__(v11, 1) - 1), 0xFFFFFFFF);
  p_x = &winding[v11 % numPoints].x;
  v17 = (float)(*p_x - (float)x);
  v18 = (float)(p_x[1] - (float)y);
  node->delta.x = *p_x - (float)x;
  node->delta.y = v18;
  if ( (float)((float)((float)v18 * (float)v18) + (float)((float)v17 * (float)v17)) <= 0.0099999998 )
  {
    HIDWORD(passedCorner) = 1;
    do
    {
      dir = node->dir;
      __twllei(numPoints, 0);
      edgeNum = node->edgeNum;
      __twllei(numPoints, 0);
      v21 = 2 * dir + numPoints + edgeNum - 1;
      node->edgeNum = v21 % numPoints;
      v22 = p_pos->x;
      obstacle = node->obstacle;
      v24 = node->pos.y;
      v25 = numPoints & ~(__ROL4__(v21, 1) - 1);
      v27 = v21 % numPoints;
      v26 = node->dir;
      __twlgei(v25, 0xFFFFFFFF);
      v28 = (v26 + v27) % numPoints;
      v30 = __ROL4__(v26 + v27, 1);
      v29 = this->expandedObstacles[obstacle].winding;
      v31 = (float)(v29[v28].y - (float)v24);
      p_delta->x = v29[v28].x - (float)v22;
      node->delta.y = v31;
      v32 = (float)((float)((float)v31 * (float)v31) + (float)(p_delta->x * p_delta->x));
      __twlgei(numPoints & ~(v30 - 1), 0xFFFFFFFF);
    }
    while ( v32 <= 0.0099999998 );
  }
  if ( BYTE3(passedCorner) != 0 )
  {
    v33 = p_pos->x;
    v34 = (float)(seekPos->x - p_pos->x);
    v35 = node->pos.y;
    v36 = (float)(seekPos->y - node->pos.y);
    LODWORD(passedCorner) = 2 * node->dir - 1;
    v37 = (float)((float)((float)(p_delta->x * (float)(seekPos->y - node->pos.y))
                        - (float)(node->delta.y * (float)(seekPos->x - node->pos.x)))
                * (float)passedCorner);
    v49 = passedCorner;
    v38 = *p_delta;
    v38.x = -9.4039548e-38;
    v39 = node->delta.y;
    v40 = -9.4039548e-38;
    v41 = (float)((float)(node->delta.y * node->delta.y) + (float)(-9.4039548e-38 * -9.4039548e-38));
    v49 = (__int64)v38;
    if ( v41 > 1.0 )
    {
      _FP7 = (float)((float)v41 - idMath::FLT_SMALLEST_NON_DENORMAL);
      v43 = (float)((float)v41 * (float)0.5);
      __asm { fsel      f5, f7, f0, f10 }
      v45 = __frsqrte(_FP5);
      v46 = (float)((float)-(float)((float)((float)((float)v45 * (float)((float)v41 * (float)0.5)) * (float)v45)
                                  - (float)1.5)
                  * (float)v45);
      v40 = (float)(-9.4039548e-38
                  * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v46
                                                                                                  * (float)v43)
                                                                                          * (float)v46)
                                                                                  - (float)1.5)
                                                                  * (float)v46)
                                                          * (float)v43)
                                                  * (float)((float)-(float)((float)((float)((float)v46 * (float)v43)
                                                                                  * (float)v46)
                                                                          - (float)1.5)
                                                          * (float)v46))
                                          - (float)1.5)
                          * (float)((float)-(float)((float)((float)((float)v46 * (float)v43) * (float)v46) - (float)1.5)
                                  * (float)v46)));
      v39 = (float)((float)v39
                  * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v46
                                                                                                  * (float)v43)
                                                                                          * (float)v46)
                                                                                  - (float)1.5)
                                                                  * (float)v46)
                                                          * (float)v43)
                                                  * (float)((float)-(float)((float)((float)((float)v46 * (float)v43)
                                                                                  * (float)v46)
                                                                          - (float)1.5)
                                                          * (float)v46))
                                          - (float)1.5)
                          * (float)((float)-(float)((float)((float)((float)v46 * (float)v43) * (float)v46) - (float)1.5)
                                  * (float)v46)));
    }
    if ( v37 >= 0.0 )
    {
      *(float *)&v49 = (float)v33 + (float)v40;
      *((float *)&v49 + 1) = (float)v35 + (float)v39;
      if ( (unsigned __int8)idObstacleAvoidanceCore::LineIntersectsPath(
                              this,
                              start: (const idVec2 *)&v49,
                              end: seekPos,
                              node: node->parent) == 0 )
      {
        p_delta->x = v34;
        node->delta.y = v36;
        node->edgeNum = -1;
      }
    }
  }
  v47 = node->edgeNum;
  if ( v47 != -1 )
  {
    parent = node->parent;
    if ( parent != nullptr )
    {
      while ( node->obstacle != parent->obstacle
           || v47 != parent->edgeNum
           || (float)((float)(parent->pos.x * node->delta.x) + (float)(parent->pos.y * node->delta.y)) > (double)(float)((float)(node->delta.y * (float)(node->delta.y + node->pos.y)) + (float)(node->delta.x * (float)(node->delta.x + node->pos.x)))
           || (float)((float)(node->delta.x * node->pos.x) + (float)(node->pos.y * node->delta.y)) > (double)(float)((float)(node->delta.y * (float)(parent->delta.y + parent->pos.y)) + (float)(node->delta.x * (float)(parent->pos.x + parent->delta.x))) )
      {
        parent = parent->parent;
        if ( parent == nullptr )
          return 1;
      }
      return 0;
    }
  }
  return 1;
}


// ========================================================================
// ?PrunePathTree@idObstacleAvoidanceCore@@AAAXPAUpathNode_t@1@ABVidVec2@@@Z
// EA  : 0x826BFB80
// RVA : 0x006BFB80
// PDB : w:\tech5\engine\gamelib\aas2\obstacleavoidancecore.cpp
// ========================================================================

void __fastcall idObstacleAvoidanceCore::PrunePathTree(
        idObstacleAvoidanceCore *this,
        idObstacleAvoidanceCore::pathNode_t *root,
        const idVec2 *seekPos)
{
  idObstacleAvoidanceCore::pathNode_t *v3; // r11
  idObstacleAvoidanceCore::pathNode_t *v4; // r10
  double v5; // fp12
  double v6; // fp9
  double targetDistSqr; // fp13
  idObstacleAvoidanceCore::pathNode_t *v8; // r10
  idObstacleAvoidanceCore::pathNode_t *v9; // r9
  idObstacleAvoidanceCore::pathNode_t *parent; // r11
  idObstacleAvoidanceCore::pathNode_t *v11; // r10

  v3 = root;
  while ( v3 != nullptr )
  {
    v4 = v3->children[0];
    v5 = (float)(seekPos->y - v3->pos.y);
    v6 = (float)(seekPos->x - v3->pos.x);
    v3->targetDistSqr = (float)((float)v6 * (float)v6) + (float)((float)v5 * (float)v5);
    if ( v4 != nullptr )
    {
      v3 = v4;
    }
    else if ( v3->children[1] != nullptr )
    {
      v3 = v3->children[1];
    }
    else
    {
      targetDistSqr = 1.0e30;
      v8 = v3;
      do
      {
        if ( v3->children[0] != nullptr && v3->children[1] != nullptr )
          break;
        if ( v3->targetDistSqr < targetDistSqr )
        {
          targetDistSqr = v3->targetDistSqr;
          v8 = v3;
        }
        v3 = v3->parent;
      }
      while ( v3 != nullptr );
      v8->children[0] = nullptr;
      v8->children[1] = nullptr;
      v9 = v8;
      parent = v8->parent;
      if ( parent == nullptr )
        return;
      while ( 1 )
      {
        v11 = parent->children[1];
        if ( v11 != nullptr && v11 != v9 )
          break;
        v9 = parent;
        parent = parent->parent;
        if ( parent == nullptr )
          return;
      }
      v3 = parent->children[1];
    }
  }
}


// ========================================================================
// ?GetSeekPointsOnPath@idObstacleAvoidanceCore@@AAAXQBVidVec2@@HABV2@MMQAVidVec3@@AAH@Z
// EA  : 0x826BFC78
// RVA : 0x006BFC78
// PDB : w:\tech5\engine\gamelib\aas2\obstacleavoidancecore.cpp
// ========================================================================

void __fastcall idObstacleAvoidanceCore::GetSeekPointsOnPath(
        idObstacleAvoidanceCore *this,
        const idVec2 *pathPoints,
        int numPathPoints,
        const idVec2 *corner,
        double radius,
        double frameMoveDist,
        idVec3 *seekPos,
        int *outNumSeekPos,
        int a9,
        int *a10)
{
  double v10; // fp12
  int v11; // r11
  int v12; // r3
  float *p_y; // r7
  double v14; // fp8
  double v15; // fp9
  double v16; // fp10
  float *v17; // r8
  double v18; // fp0
  double v19; // fp13
  double v20; // fp31
  double v21; // fp13
  double v23; // fp26
  double v25; // fp0
  double v26; // fp0
  double v27; // fp0
  double v28; // fp0
  float *v29; // r8

  v10 = frameMoveDist;
  v11 = 0;
  v12 = 0;
  if ( numPathPoints - 1 > 0 )
  {
    p_y = &pathPoints->y;
    do
    {
      if ( v11 >= 2 )
      {
        if ( v11 < 30 )
        {
          v29 = (float *)(12 * v11++ + a9);
          *v29 = *(p_y - 1);
          v29[1] = *p_y;
        }
      }
      else
      {
        v14 = (float)(p_y[1] - *(p_y - 1));
        v15 = (float)(p_y[2] - *p_y);
        v16 = __fsqrts((float)((float)((float)v15 * (float)v15) + (float)((float)v14 * (float)v14)));
        v10 = (float)((float)v10 - (float)v16);
        if ( v10 < 0.0 )
        {
          v17 = (float *)(12 * v11 + a9);
          do
          {
            v18 = (float)((float)((float)((float)((float)v16 + (float)v10) * (float)((float)1.0 / (float)v16))
                                * (float)v14)
                        + *(p_y - 1));
            v19 = (float)(*p_y
                        + (float)((float)v15
                                * (float)((float)((float)v16 + (float)v10) * (float)((float)1.0 / (float)v16))));
            if ( v12 > 0 && v12 < numPathPoints - 2 && radius != 0.0 )
            {
              v20 = __fabs(radius);
              v21 = (float)((float)(*p_y
                                  + (float)((float)v15
                                          * (float)((float)((float)v16 + (float)v10) * (float)((float)1.0 / (float)v16))))
                          - corner->y);
              _FP27 = (float)((float)((float)((float)v21 * (float)v21)
                                    + (float)((float)((float)v18 - corner->x) * (float)((float)v18 - corner->x)))
                            - idMath::FLT_SMALLEST_NON_DENORMAL);
              v23 = (float)((float)((float)((float)v21 * (float)v21)
                                  + (float)((float)((float)v18 - corner->x) * (float)((float)v18 - corner->x)))
                          * (float)0.5);
              __asm { fsel      f0, f27, f28, f0 }
              v25 = __frsqrte(_FP0);
              v26 = (float)((float)-(float)((float)((float)((float)v25 * (float)v23) * (float)v25) - (float)1.5)
                          * (float)v25);
              v27 = (float)((float)-(float)((float)((float)((float)v26 * (float)v23) * (float)v26) - (float)1.5)
                          * (float)v26);
              v28 = (float)((float)-(float)((float)((float)((float)v27 * (float)v23) * (float)v27) - (float)1.5)
                          * (float)v27);
              v19 = (float)(corner->y
                          + (float)((float)((float)((float)(*p_y
                                                          + (float)((float)v15
                                                                  * (float)((float)((float)v16 + (float)v10)
                                                                          * (float)((float)1.0 / (float)v16))))
                                                  - corner->y)
                                          * (float)v28)
                                  * (float)v20));
              v18 = (float)(corner->x
                          + (float)((float)((float)((float)((float)((float)((float)((float)v16 + (float)v10)
                                                                          * (float)((float)1.0 / (float)v16))
                                                                  * (float)v14)
                                                          + *(p_y - 1))
                                                  - corner->x)
                                          * (float)v28)
                                  * (float)v20));
            }
            ++v11;
            *v17 = v18;
            v17[1] = v19;
            v17 += 3;
            if ( v11 >= 2 )
              break;
            v10 = (float)((float)v10 + (float)frameMoveDist);
          }
          while ( v10 < 0.0 );
        }
      }
      ++v12;
      p_y += 2;
    }
    while ( v12 < numPathPoints - 1 );
  }
  *a10 = v11;
}


// ========================================================================
// ?TransformInput@idObstacleAvoidanceCore@@AAAXABVidVec3@@PAUobstacleRoute_t@@AAV2@AAVidVec4@@PAUobstacleBox_t@@HPAUobstacleVertex_t@@HPAUobstacleCorner_t@@HPAUobstacleTrace_t@@H@Z
// EA  : 0x826BFE38
// RVA : 0x006BFE38
// PDB : w:\tech5\engine\gamelib\aas2\obstacleavoidancecore.cpp
// ========================================================================

void __fastcall idObstacleAvoidanceCore::TransformInput(
        idObstacleAvoidanceCore *this,
        const idVec3 *gravity,
        obstacleRoute_t *route,
        idVec3 *lastDir,
        idVec4 *lastCorner,
        obstacleBox_t *obstacles,
        int numObstacles,
        obstacleVertex_t *vertices,
        int numVertices,
        obstacleCorner_t *corners,
        int numCorners,
        obstacleTrace_t *traces,
        int numTraces,
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
        int numVerticesa)
{
  double v36; // fp13
  double v37; // fp11
  double v38; // fp8
  double v42; // fp0
  double v43; // fp0
  double v44; // fp5
  double v45; // fp0
  double v46; // fp13
  double v47; // fp11
  double v49; // fp4
  idMat3x4 *p_inputTransform; // r31
  int v51; // r10
  double v53; // fp10
  double v54; // fp1
  double v55; // fp12
  double v56; // fp2
  double v57; // fp0
  double x; // fp13
  double v59; // fp13
  float *p_z; // r11
  idVec3 *p_center; // r30
  int i; // r29
  char *v63; // r10
  int v64; // ctr
  _DWORD *v65; // r11
  double v66; // fp0
  int v67; // r10
  float *v68; // r11
  float v69; // r5
  float v70; // r7
  double v71; // fp12
  float v72; // r4
  int v73; // r9
  obstacleVertex_t *v74; // r11
  double v75; // fp0
  int v76; // r10
  float *v77; // r11
  float v78; // r4
  float v79; // r5
  double v80; // fp12
  float v81; // r3
  float v82; // r6
  int v83; // r10
  float *v84; // r11
  double v85; // fp0
  int v86; // r10
  float *v87; // r11
  double v88; // fp0
  double v89; // fp11
  double v90; // fp10
  double v91; // fp7
  double v92; // fp2
  double v93; // fp4
  double v94; // fp10
  double v95; // fp13
  double v96; // fp12
  double v97; // fp9
  double v98; // fp8
  double v99; // fp5
  double v100; // fp4
  double v101; // fp1
  double v102; // fp13
  double v103; // fp10
  float *v104; // r11
  int v105; // ctr
  double v106; // fp0
  double v107; // fp11
  double v108; // fp10
  double v109; // fp7
  idVec3 start; // [sp+50h] [-80h]
  float v111; // [sp+50h] [-80h]
  float v112; // [sp+50h] [-80h]
  float v113; // [sp+50h] [-80h]
  float v114; // [sp+50h] [-80h]
  float v115; // [sp+50h] [-80h]
  float v116; // [sp+50h] [-80h]
  float v117; // [sp+50h] [-80h]
  float v118; // [sp+50h] [-80h]
  float v119; // [sp+50h] [-80h]
  float y; // [sp+54h] [-7Ch]
  float v121; // [sp+54h] [-7Ch]
  float v122; // [sp+54h] [-7Ch]
  float v123; // [sp+54h] [-7Ch]
  float v124; // [sp+54h] [-7Ch]
  float v125; // [sp+54h] [-7Ch]
  float v126; // [sp+54h] [-7Ch]
  float v127; // [sp+54h] [-7Ch]
  float v128; // [sp+54h] [-7Ch]
  float z; // [sp+58h] [-78h]
  float v130; // [sp+58h] [-78h]
  float v131; // [sp+58h] [-78h]
  float v132; // [sp+58h] [-78h]
  float v133; // [sp+58h] [-78h]
  float v134; // [sp+58h] [-78h]
  float v135; // [sp+58h] [-78h]
  float v136; // [sp+58h] [-78h]
  float v137; // [sp+60h] [-70h]
  float v138; // [sp+64h] [-6Ch]
  float v139; // [sp+64h] [-6Ch]
  float v140; // [sp+68h] [-68h]
  float v141; // [sp+68h] [-68h]
  char v142; // [sp+6Ch] [-64h] BYREF
  idMat3 v143; // [sp+70h] [-60h] BYREF
  idVec3 endAlignDir; // 0:^60.12

  v36 = -gravity->y;
  v37 = -gravity->z;
  v38 = -gravity->x;
  start = route->areas[0].start;
  _FP3 = (float)((float)((float)((float)v38 * (float)v38)
                       + (float)((float)((float)v37 * (float)v37) + (float)((float)v36 * (float)v36)))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f1, f3, f4, f9 }
  v42 = __frsqrte(_FP1);
  v43 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v42
                                                                                      * (float)((float)((float)((float)v38 * (float)v38) + (float)((float)((float)v37 * (float)v37) + (float)((float)v36 * (float)v36)))
                                                                                              * (float)0.5))
                                                                              * (float)v42)
                                                                      - (float)1.5)
                                                      * (float)v42)
                                              * (float)((float)((float)((float)v38 * (float)v38)
                                                              + (float)((float)((float)v37 * (float)v37)
                                                                      + (float)((float)v36 * (float)v36)))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v42
                                                                              * (float)((float)((float)((float)v38 * (float)v38)
                                                                                              + (float)((float)((float)v37 * (float)v37) + (float)((float)v36 * (float)v36)))
                                                                                      * (float)0.5))
                                                                      * (float)v42)
                                                              - (float)1.5)
                                              * (float)v42))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v42
                                                      * (float)((float)((float)((float)v38 * (float)v38)
                                                                      + (float)((float)((float)v37 * (float)v37)
                                                                              + (float)((float)v36 * (float)v36)))
                                                              * (float)0.5))
                                              * (float)v42)
                                      - (float)1.5)
                      * (float)v42));
  v44 = (float)((float)-(float)((float)((float)((float)v43
                                              * (float)((float)((float)((float)v38 * (float)v38)
                                                              + (float)((float)((float)v37 * (float)v37)
                                                                      + (float)((float)v36 * (float)v36)))
                                                      * (float)0.5))
                                      * (float)v43)
                              - (float)1.5)
              * (float)v43);
  v45 = (float)((float)((float)-(float)((float)((float)((float)v43
                                                      * (float)((float)((float)((float)v38 * (float)v38)
                                                                      + (float)((float)((float)v37 * (float)v37)
                                                                              + (float)((float)v36 * (float)v36)))
                                                              * (float)0.5))
                                              * (float)v43)
                                      - (float)1.5)
                      * (float)v43)
              * (float)v38);
  v46 = (float)((float)v44 * (float)v36);
  v47 = (float)((float)v44 * (float)v37);
  if ( (float)((float)((float)v46 * (float)v46) + (float)((float)v45 * (float)v45)) == 0.0 )
  {
    this->inputTransformValid = false;
  }
  else
  {
    _FP5 = (float)((float)((float)((float)v46 * (float)v46) + (float)((float)v45 * (float)v45))
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    v49 = (float)((float)((float)((float)v46 * (float)v46) + (float)((float)v45 * (float)v45)) * (float)0.5);
    this->inputTransform.mat[8] = v45;
    this->inputTransform.mat[9] = v46;
    p_inputTransform = &this->inputTransform;
    this->inputTransform.mat[10] = v47;
    v51 = 0;
    this->inputTransform.mat[2] = 0.0;
    __asm { fsel      f2, f5, f10, f9 }
    v53 = __frsqrte(_FP2);
    this->inputTransform.mat[11] = -(float)((float)(start.x * (float)v45)
                                          + (float)((float)(start.z * (float)v47) + (float)(start.y * (float)v46)));
    v54 = (float)((float)v46
                * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v53 * (float)v49) * (float)v53) - (float)1.5) * (float)v53)
                                                                                                * (float)v49)
                                                                                        * (float)((float)-(float)((float)((float)((float)v53 * (float)v49) * (float)v53) - (float)1.5)
                                                                                                * (float)v53))
                                                                                - (float)1.5)
                                                                * (float)((float)-(float)((float)((float)((float)v53 * (float)v49)
                                                                                                * (float)v53)
                                                                                        - (float)1.5)
                                                                        * (float)v53))
                                                        * (float)v49)
                                                * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v53 * (float)v49) * (float)v53) - (float)1.5)
                                                                                                * (float)v53)
                                                                                        * (float)v49)
                                                                                * (float)((float)-(float)((float)((float)((float)v53 * (float)v49) * (float)v53) - (float)1.5)
                                                                                        * (float)v53))
                                                                        - (float)1.5)
                                                        * (float)((float)-(float)((float)((float)((float)v53 * (float)v49)
                                                                                        * (float)v53)
                                                                                - (float)1.5)
                                                                * (float)v53)))
                                        - (float)1.5)
                        * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v53 * (float)v49)
                                                                                                * (float)v53)
                                                                                        - (float)1.5)
                                                                        * (float)v53)
                                                                * (float)v49)
                                                        * (float)((float)-(float)((float)((float)((float)v53 * (float)v49)
                                                                                        * (float)v53)
                                                                                - (float)1.5)
                                                                * (float)v53))
                                                - (float)1.5)
                                * (float)((float)-(float)((float)((float)((float)v53 * (float)v49) * (float)v53)
                                                        - (float)1.5)
                                        * (float)v53))));
    v55 = (float)((float)v45
                * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v53 * (float)v49) * (float)v53) - (float)1.5) * (float)v53)
                                                                                                * (float)v49)
                                                                                        * (float)((float)-(float)((float)((float)((float)v53 * (float)v49) * (float)v53) - (float)1.5)
                                                                                                * (float)v53))
                                                                                - (float)1.5)
                                                                * (float)((float)-(float)((float)((float)((float)v53 * (float)v49)
                                                                                                * (float)v53)
                                                                                        - (float)1.5)
                                                                        * (float)v53))
                                                        * (float)v49)
                                                * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v53 * (float)v49) * (float)v53) - (float)1.5)
                                                                                                * (float)v53)
                                                                                        * (float)v49)
                                                                                * (float)((float)-(float)((float)((float)((float)v53 * (float)v49) * (float)v53) - (float)1.5)
                                                                                        * (float)v53))
                                                                        - (float)1.5)
                                                        * (float)((float)-(float)((float)((float)((float)v53 * (float)v49)
                                                                                        * (float)v53)
                                                                                - (float)1.5)
                                                                * (float)v53)))
                                        - (float)1.5)
                        * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v53 * (float)v49)
                                                                                                * (float)v53)
                                                                                        - (float)1.5)
                                                                        * (float)v53)
                                                                * (float)v49)
                                                        * (float)((float)-(float)((float)((float)((float)v53 * (float)v49)
                                                                                        * (float)v53)
                                                                                - (float)1.5)
                                                                * (float)v53))
                                                - (float)1.5)
                                * (float)((float)-(float)((float)((float)((float)v53 * (float)v49) * (float)v53)
                                                        - (float)1.5)
                                        * (float)v53))));
    this->inputTransform.mat[1] = (float)v45
                                * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v53 * (float)v49) * (float)v53) - (float)1.5) * (float)v53) * (float)v49) * (float)((float)-(float)((float)((float)((float)v53 * (float)v49) * (float)v53) - (float)1.5) * (float)v53))
                                                                                                - (float)1.5)
                                                                                * (float)((float)-(float)((float)((float)((float)v53 * (float)v49) * (float)v53) - (float)1.5)
                                                                                        * (float)v53))
                                                                        * (float)v49)
                                                                * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v53 * (float)v49) * (float)v53) - (float)1.5) * (float)v53) * (float)v49)
                                                                                                * (float)((float)-(float)((float)((float)((float)v53 * (float)v49) * (float)v53) - (float)1.5) * (float)v53))
                                                                                        - (float)1.5)
                                                                        * (float)((float)-(float)((float)((float)((float)v53 * (float)v49) * (float)v53)
                                                                                                - (float)1.5)
                                                                                * (float)v53)))
                                                        - (float)1.5)
                                        * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v53 * (float)v49) * (float)v53) - (float)1.5)
                                                                                        * (float)v53)
                                                                                * (float)v49)
                                                                        * (float)((float)-(float)((float)((float)((float)v53 * (float)v49) * (float)v53)
                                                                                                - (float)1.5)
                                                                                * (float)v53))
                                                                - (float)1.5)
                                                * (float)((float)-(float)((float)((float)((float)v53 * (float)v49)
                                                                                * (float)v53)
                                                                        - (float)1.5)
                                                        * (float)v53)));
    this->inputTransform.mat[0] = -v54;
    this->inputTransform.mat[5] = (float)v47 * (float)-v54;
    v56 = -(float)((float)v47
                 * (float)((float)v45
                         * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v53 * (float)v49) * (float)v53) - (float)1.5) * (float)v53) * (float)v49)
                                                                                                 * (float)((float)-(float)((float)((float)((float)v53 * (float)v49) * (float)v53) - (float)1.5) * (float)v53))
                                                                                         - (float)1.5)
                                                                         * (float)((float)-(float)((float)((float)((float)v53 * (float)v49) * (float)v53)
                                                                                                 - (float)1.5)
                                                                                 * (float)v53))
                                                                 * (float)v49)
                                                         * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v53 * (float)v49) * (float)v53) - (float)1.5) * (float)v53)
                                                                                                 * (float)v49)
                                                                                         * (float)((float)-(float)((float)((float)((float)v53 * (float)v49) * (float)v53) - (float)1.5)
                                                                                                 * (float)v53))
                                                                                 - (float)1.5)
                                                                 * (float)((float)-(float)((float)((float)((float)v53 * (float)v49)
                                                                                                 * (float)v53)
                                                                                         - (float)1.5)
                                                                         * (float)v53)))
                                                 - (float)1.5)
                                 * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v53 * (float)v49) * (float)v53)
                                                                                                 - (float)1.5)
                                                                                 * (float)v53)
                                                                         * (float)v49)
                                                                 * (float)((float)-(float)((float)((float)((float)v53 * (float)v49)
                                                                                                 * (float)v53)
                                                                                         - (float)1.5)
                                                                         * (float)v53))
                                                         - (float)1.5)
                                         * (float)((float)-(float)((float)((float)((float)v53 * (float)v49) * (float)v53)
                                                                 - (float)1.5)
                                                 * (float)v53)))));
    this->inputTransform.mat[4] = v56;
    v57 = (float)((float)((float)v55 * (float)v45) - (float)((float)-v54 * (float)v46));
    this->inputTransform.mat[6] = v57;
    this->inputTransform.mat[3] = -(float)((float)(start.z * (float)0.0)
                                         + (float)((float)(start.y * (float)v55) + (float)(start.x * (float)-v54)));
    this->inputTransform.mat[7] = -(float)((float)((float)v56 * start.x)
                                         + (float)((float)((float)v57 * start.z)
                                                 + (float)((float)((float)v47 * (float)-v54) * start.y)));
    this->inputTransformValid = true;
    y = lastDir->y;
    x = lastDir->x;
    z = lastDir->z;
    lastDir->x = (float)(this->inputTransform.mat[2] * z)
               + (float)((float)(this->inputTransform.mat[0] * lastDir->x) + (float)(this->inputTransform.mat[1] * y));
    lastDir->y = (float)((float)x * this->inputTransform.mat[4])
               + (float)((float)(this->inputTransform.mat[5] * y) + (float)(z * this->inputTransform.mat[6]));
    lastDir->z = (float)(this->inputTransform.mat[10] * z)
               + (float)((float)(y * this->inputTransform.mat[9]) + (float)(this->inputTransform.mat[8] * (float)x));
    v59 = lastCorner->x;
    v130 = lastCorner->z;
    v121 = lastCorner->y;
    lastCorner->x = (float)((float)(this->inputTransform.mat[2] * v130)
                          + (float)((float)(this->inputTransform.mat[0] * lastCorner->x)
                                  + (float)(this->inputTransform.mat[1] * v121)))
                  + this->inputTransform.mat[3];
    lastCorner->y = (float)((float)((float)v59 * this->inputTransform.mat[4])
                          + (float)((float)(this->inputTransform.mat[5] * v121)
                                  + (float)(v130 * this->inputTransform.mat[6])))
                  + this->inputTransform.mat[7];
    lastCorner->z = (float)((float)(this->inputTransform.mat[10] * v130)
                          + (float)((float)(v121 * this->inputTransform.mat[9])
                                  + (float)(this->inputTransform.mat[8] * (float)v59)))
                  + this->inputTransform.mat[11];
    if ( route->numAreas > 0 )
    {
      p_z = &route->areas[0].start.z;
      do
      {
        ++v51;
        v111 = *(p_z - 2);
        v122 = *(p_z - 1);
        v131 = *p_z;
        *(p_z - 2) = (float)((float)(this->inputTransform.mat[2] * *p_z)
                           + (float)((float)(this->inputTransform.mat[0] * v111)
                                   + (float)(this->inputTransform.mat[1] * v122)))
                   + this->inputTransform.mat[3];
        *(p_z - 1) = (float)((float)(v111 * this->inputTransform.mat[4])
                           + (float)((float)(this->inputTransform.mat[5] * v122)
                                   + (float)(v131 * this->inputTransform.mat[6])))
                   + this->inputTransform.mat[7];
        *p_z = (float)((float)(this->inputTransform.mat[10] * v131)
                     + (float)((float)(v122 * this->inputTransform.mat[9]) + (float)(this->inputTransform.mat[8] * v111)))
             + this->inputTransform.mat[11];
        v137 = p_z[1];
        v138 = p_z[2];
        v140 = p_z[3];
        p_z[1] = (float)((float)(this->inputTransform.mat[2] * v140)
                       + (float)((float)(this->inputTransform.mat[1] * v138)
                               + (float)(this->inputTransform.mat[0] * v137)))
               + this->inputTransform.mat[3];
        p_z[2] = (float)((float)(v137 * this->inputTransform.mat[4])
                       + (float)((float)(this->inputTransform.mat[5] * v138)
                               + (float)(v140 * this->inputTransform.mat[6])))
               + this->inputTransform.mat[7];
        p_z[3] = (float)((float)(this->inputTransform.mat[8] * v137)
                       + (float)((float)(v138 * this->inputTransform.mat[9])
                               + (float)(this->inputTransform.mat[10] * v140)))
               + this->inputTransform.mat[11];
        p_z += 7;
      }
      while ( v51 < route->numAreas );
    }
    endAlignDir = route->endAlignDir;
    route->endAlignDir.x = (float)(this->inputTransform.mat[2] * endAlignDir.z)
                         + (float)((float)(this->inputTransform.mat[1] * endAlignDir.y)
                                 + (float)(this->inputTransform.mat[0] * endAlignDir.x));
    route->endAlignDir.y = (float)(endAlignDir.x * this->inputTransform.mat[4])
                         + (float)((float)(this->inputTransform.mat[5] * endAlignDir.y)
                                 + (float)(endAlignDir.z * this->inputTransform.mat[6]));
    route->endAlignDir.z = (float)(this->inputTransform.mat[8] * endAlignDir.x)
                         + (float)((float)(endAlignDir.y * this->inputTransform.mat[9])
                                 + (float)(this->inputTransform.mat[10] * endAlignDir.z));
    if ( numObstacles > 0 )
    {
      p_center = &obstacles->center;
      for ( i = numObstacles; i != 0; --i )
      {
        v63 = &v142;
        v141 = p_center->z;
        v139 = p_center->y;
        v64 = 9;
        v66 = p_center->x;
        p_center->x = (float)((float)(p_inputTransform->mat[2] * v141)
                            + (float)((float)(p_inputTransform->mat[1] * v139)
                                    + (float)(p_inputTransform->mat[0] * p_center->x)))
                    + p_inputTransform->mat[3];
        p_center->y = (float)((float)((float)v66 * p_inputTransform->mat[4])
                            + (float)((float)(p_inputTransform->mat[5] * v139) + (float)(v141 * p_inputTransform->mat[6])))
                    + p_inputTransform->mat[7];
        v65 = (_DWORD *)&p_center[-4].z;
        p_center->z = (float)((float)(p_inputTransform->mat[8] * (float)v66)
                            + (float)((float)(v139 * p_inputTransform->mat[9])
                                    + (float)(p_inputTransform->mat[10] * v141)))
                    + p_inputTransform->mat[11];
        do
        {
          ++v65;
          v63 += 4;
          *(_DWORD *)v63 = *v65;
          --v64;
        }
        while ( v64 != 0 );
        idMat3x4::Rotate(this: p_inputTransform, result: (idMat3 *)&p_center[-3], m: &v143);
        p_center = (idVec3 *)((char *)p_center + 80);
      }
    }
    v67 = 0;
    if ( a28 >= 4 )
    {
      v68 = &vertices[1].position.z;
      do
      {
        v69 = *(v68 - 3);
        v70 = *(v68 - 4);
        v112 = *(v68 - 5);
        *(v68 - 5) = (float)((float)(p_inputTransform->mat[2] * v69)
                           + (float)((float)(p_inputTransform->mat[1] * v70) + (float)(p_inputTransform->mat[0] * v112)))
                   + p_inputTransform->mat[3];
        *(v68 - 4) = (float)((float)(v112 * p_inputTransform->mat[4])
                           + (float)((float)(p_inputTransform->mat[5] * v70) + (float)(v69 * p_inputTransform->mat[6])))
                   + p_inputTransform->mat[7];
        *(v68 - 3) = (float)((float)(p_inputTransform->mat[8] * v112)
                           + (float)((float)(v70 * p_inputTransform->mat[9]) + (float)(p_inputTransform->mat[10] * v69)))
                   + p_inputTransform->mat[11];
        v113 = *(v68 - 2);
        v123 = *(v68 - 1);
        v71 = *v68;
        *(v68 - 2) = (float)((float)(p_inputTransform->mat[2] * *v68)
                           + (float)((float)(p_inputTransform->mat[1] * v123) + (float)(p_inputTransform->mat[0] * v113)))
                   + p_inputTransform->mat[3];
        *(v68 - 1) = (float)((float)(v113 * p_inputTransform->mat[4])
                           + (float)((float)(p_inputTransform->mat[5] * v123)
                                   + (float)((float)v71 * p_inputTransform->mat[6])))
                   + p_inputTransform->mat[7];
        *v68 = (float)((float)(p_inputTransform->mat[8] * v113)
                     + (float)((float)(v123 * p_inputTransform->mat[9]) + (float)(p_inputTransform->mat[10] * (float)v71)))
             + p_inputTransform->mat[11];
        v72 = v68[2];
        v132 = v68[3];
        v114 = v68[1];
        v67 += 4;
        v68[1] = (float)((float)(p_inputTransform->mat[2] * v132)
                       + (float)((float)(p_inputTransform->mat[1] * v72) + (float)(p_inputTransform->mat[0] * v114)))
               + p_inputTransform->mat[3];
        v68[2] = (float)((float)(v114 * p_inputTransform->mat[4])
                       + (float)((float)(p_inputTransform->mat[5] * v72) + (float)(v132 * p_inputTransform->mat[6])))
               + p_inputTransform->mat[7];
        v68[3] = (float)((float)(p_inputTransform->mat[8] * v114)
                       + (float)((float)(v72 * p_inputTransform->mat[9]) + (float)(p_inputTransform->mat[10] * v132)))
               + p_inputTransform->mat[11];
        v115 = v68[4];
        v124 = v68[5];
        v133 = v68[6];
        v68[4] = (float)((float)(p_inputTransform->mat[2] * v133)
                       + (float)((float)(p_inputTransform->mat[1] * v124) + (float)(p_inputTransform->mat[0] * v115)))
               + p_inputTransform->mat[3];
        v68[5] = (float)((float)(v115 * p_inputTransform->mat[4])
                       + (float)((float)(p_inputTransform->mat[5] * v124) + (float)(v133 * p_inputTransform->mat[6])))
               + p_inputTransform->mat[7];
        v68[6] = (float)((float)(p_inputTransform->mat[8] * v115)
                       + (float)((float)(v124 * p_inputTransform->mat[9]) + (float)(p_inputTransform->mat[10] * v133)))
               + p_inputTransform->mat[11];
        v68 += 12;
      }
      while ( v67 < a28 - 3 );
    }
    if ( v67 < a28 )
    {
      v73 = a28 - v67;
      v74 = &vertices[v67];
      do
      {
        --v73;
        v134 = v74->position.z;
        v125 = v74->position.y;
        v75 = v74->position.x;
        v74->position.x = (float)((float)(p_inputTransform->mat[2] * v134)
                                + (float)((float)(p_inputTransform->mat[1] * v125)
                                        + (float)(p_inputTransform->mat[0] * v74->position.x)))
                        + p_inputTransform->mat[3];
        v74->position.y = (float)((float)((float)v75 * p_inputTransform->mat[4])
                                + (float)((float)(p_inputTransform->mat[5] * v125)
                                        + (float)(v134 * p_inputTransform->mat[6])))
                        + p_inputTransform->mat[7];
        v74->position.z = (float)((float)(p_inputTransform->mat[8] * (float)v75)
                                + (float)((float)(v125 * p_inputTransform->mat[9])
                                        + (float)(p_inputTransform->mat[10] * v134)))
                        + p_inputTransform->mat[11];
        ++v74;
      }
      while ( v73 != 0 );
    }
    v76 = 0;
    if ( a32 >= 4 )
    {
      v77 = (float *)(a30 + 24);
      do
      {
        v78 = *(v77 - 4);
        v79 = *(v77 - 5);
        v116 = *(v77 - 6);
        *(v77 - 6) = (float)((float)(p_inputTransform->mat[2] * v78)
                           + (float)((float)(p_inputTransform->mat[1] * v79) + (float)(p_inputTransform->mat[0] * v116)))
                   + p_inputTransform->mat[3];
        *(v77 - 5) = (float)((float)(v116 * p_inputTransform->mat[4])
                           + (float)((float)(p_inputTransform->mat[5] * v79) + (float)(v78 * p_inputTransform->mat[6])))
                   + p_inputTransform->mat[7];
        *(v77 - 4) = (float)((float)(p_inputTransform->mat[8] * v116)
                           + (float)((float)(v79 * p_inputTransform->mat[9]) + (float)(p_inputTransform->mat[10] * v78)))
                   + p_inputTransform->mat[11];
        v126 = *(v77 - 1);
        v117 = *(v77 - 2);
        v80 = *v77;
        *(v77 - 2) = (float)((float)(p_inputTransform->mat[2] * *v77)
                           + (float)((float)(p_inputTransform->mat[1] * v126) + (float)(p_inputTransform->mat[0] * v117)))
                   + p_inputTransform->mat[3];
        *(v77 - 1) = (float)((float)(v117 * p_inputTransform->mat[4])
                           + (float)((float)(p_inputTransform->mat[5] * v126)
                                   + (float)((float)v80 * p_inputTransform->mat[6])))
                   + p_inputTransform->mat[7];
        *v77 = (float)((float)(p_inputTransform->mat[8] * v117)
                     + (float)((float)(v126 * p_inputTransform->mat[9]) + (float)(p_inputTransform->mat[10] * (float)v80)))
             + p_inputTransform->mat[11];
        v81 = v77[3];
        v82 = v77[4];
        v118 = v77[2];
        v76 += 4;
        v77[2] = (float)((float)(p_inputTransform->mat[2] * v82)
                       + (float)((float)(p_inputTransform->mat[1] * v81) + (float)(p_inputTransform->mat[0] * v118)))
               + p_inputTransform->mat[3];
        v77[3] = (float)((float)(v118 * p_inputTransform->mat[4])
                       + (float)((float)(p_inputTransform->mat[5] * v81) + (float)(v82 * p_inputTransform->mat[6])))
               + p_inputTransform->mat[7];
        v77[4] = (float)((float)(p_inputTransform->mat[8] * v118)
                       + (float)((float)(v81 * p_inputTransform->mat[9]) + (float)(p_inputTransform->mat[10] * v82)))
               + p_inputTransform->mat[11];
        v119 = v77[6];
        v127 = v77[7];
        v135 = v77[8];
        v77[6] = (float)((float)(p_inputTransform->mat[2] * v135)
                       + (float)((float)(p_inputTransform->mat[1] * v127) + (float)(p_inputTransform->mat[0] * v119)))
               + p_inputTransform->mat[3];
        v77[7] = (float)((float)(v119 * p_inputTransform->mat[4])
                       + (float)((float)(p_inputTransform->mat[5] * v127) + (float)(v135 * p_inputTransform->mat[6])))
               + p_inputTransform->mat[7];
        v77[8] = (float)((float)(p_inputTransform->mat[8] * v119)
                       + (float)((float)(v127 * p_inputTransform->mat[9]) + (float)(p_inputTransform->mat[10] * v135)))
               + p_inputTransform->mat[11];
        v77 += 16;
      }
      while ( v76 < a32 - 3 );
    }
    if ( v76 < a32 )
    {
      v84 = (float *)(16 * v76 + a30);
      v83 = a32 - v76;
      do
      {
        --v83;
        v85 = *v84;
        v136 = v84[2];
        v128 = v84[1];
        *v84 = (float)((float)(p_inputTransform->mat[2] * v136)
                     + (float)((float)(p_inputTransform->mat[1] * v128) + (float)(p_inputTransform->mat[0] * *v84)))
             + p_inputTransform->mat[3];
        v84[1] = (float)((float)((float)v85 * p_inputTransform->mat[4])
                       + (float)((float)(p_inputTransform->mat[5] * v128) + (float)(v136 * p_inputTransform->mat[6])))
               + p_inputTransform->mat[7];
        v84[2] = (float)((float)(p_inputTransform->mat[8] * (float)v85)
                       + (float)((float)(v128 * p_inputTransform->mat[9]) + (float)(p_inputTransform->mat[10] * v136)))
               + p_inputTransform->mat[11];
        v84 += 4;
      }
      while ( v83 != 0 );
    }
    v86 = 0;
    if ( numVerticesa >= 4 )
    {
      v87 = (float *)(a34 - 4);
      do
      {
        v88 = v87[1];
        v89 = v87[2];
        v87[1] = (float)((float)(p_inputTransform->mat[2] * (float)0.0)
                       + (float)((float)(p_inputTransform->mat[1] * v87[2]) + (float)(p_inputTransform->mat[0] * v87[1])))
               + p_inputTransform->mat[3];
        v87[2] = (float)((float)(p_inputTransform->mat[6] * (float)0.0)
                       + (float)((float)(p_inputTransform->mat[5] * (float)v89)
                               + (float)((float)v88 * p_inputTransform->mat[4])))
               + p_inputTransform->mat[7];
        v90 = v87[3];
        v91 = v87[4];
        v87[3] = (float)((float)(p_inputTransform->mat[2] * (float)0.0)
                       + (float)((float)(p_inputTransform->mat[1] * v87[4]) + (float)(p_inputTransform->mat[0] * v87[3])))
               + p_inputTransform->mat[3];
        v87[4] = (float)((float)(p_inputTransform->mat[6] * (float)0.0)
                       + (float)((float)(p_inputTransform->mat[5] * (float)v91)
                               + (float)((float)v90 * p_inputTransform->mat[4])))
               + p_inputTransform->mat[7];
        v92 = v87[6];
        v93 = v87[5];
        v87[5] = (float)((float)(p_inputTransform->mat[2] * (float)0.0)
                       + (float)((float)(p_inputTransform->mat[1] * v87[6]) + (float)(p_inputTransform->mat[0] * v87[5])))
               + p_inputTransform->mat[3];
        v87[6] = (float)((float)(p_inputTransform->mat[6] * (float)0.0)
                       + (float)((float)(p_inputTransform->mat[5] * (float)v92)
                               + (float)((float)v93 * p_inputTransform->mat[4])))
               + p_inputTransform->mat[7];
        v94 = v87[8];
        v95 = v87[7];
        v87[7] = (float)((float)(p_inputTransform->mat[2] * (float)0.0)
                       + (float)((float)(p_inputTransform->mat[1] * v87[8]) + (float)(p_inputTransform->mat[0] * v87[7])))
               + p_inputTransform->mat[3];
        v87[8] = (float)((float)(p_inputTransform->mat[6] * (float)0.0)
                       + (float)((float)(p_inputTransform->mat[5] * (float)v94)
                               + (float)((float)v95 * p_inputTransform->mat[4])))
               + p_inputTransform->mat[7];
        v96 = v87[9];
        v86 += 4;
        v97 = v87[10];
        v87[9] = (float)((float)(p_inputTransform->mat[2] * (float)0.0)
                       + (float)((float)(p_inputTransform->mat[1] * v87[10]) + (float)(p_inputTransform->mat[0] * v87[9])))
               + p_inputTransform->mat[3];
        v87[10] = (float)((float)(p_inputTransform->mat[6] * (float)0.0)
                        + (float)((float)(p_inputTransform->mat[5] * (float)v97)
                                + (float)((float)v96 * p_inputTransform->mat[4])))
                + p_inputTransform->mat[7];
        v98 = v87[11];
        v99 = v87[12];
        v87[11] = (float)((float)(p_inputTransform->mat[2] * (float)0.0)
                        + (float)((float)(p_inputTransform->mat[1] * v87[12])
                                + (float)(p_inputTransform->mat[0] * v87[11])))
                + p_inputTransform->mat[3];
        v87[12] = (float)((float)(p_inputTransform->mat[6] * (float)0.0)
                        + (float)((float)(p_inputTransform->mat[5] * (float)v99)
                                + (float)((float)v98 * p_inputTransform->mat[4])))
                + p_inputTransform->mat[7];
        v100 = v87[13];
        v101 = v87[14];
        v87[13] = (float)((float)(p_inputTransform->mat[2] * (float)0.0)
                        + (float)((float)(p_inputTransform->mat[1] * v87[14])
                                + (float)(p_inputTransform->mat[0] * v87[13])))
                + p_inputTransform->mat[3];
        v87[14] = (float)((float)(p_inputTransform->mat[6] * (float)0.0)
                        + (float)((float)(p_inputTransform->mat[5] * (float)v101)
                                + (float)((float)v100 * p_inputTransform->mat[4])))
                + p_inputTransform->mat[7];
        v102 = v87[15];
        v103 = v87[16];
        v87[15] = (float)((float)(p_inputTransform->mat[2] * (float)0.0)
                        + (float)((float)(p_inputTransform->mat[1] * v87[16])
                                + (float)(p_inputTransform->mat[0] * v87[15])))
                + p_inputTransform->mat[3];
        v87 += 16;
        *v87 = (float)((float)(p_inputTransform->mat[6] * (float)0.0)
                     + (float)((float)(p_inputTransform->mat[5] * (float)v103)
                             + (float)((float)v102 * p_inputTransform->mat[4])))
             + p_inputTransform->mat[7];
      }
      while ( v86 < numVerticesa - 3 );
    }
    if ( v86 < numVerticesa )
    {
      v104 = (float *)(16 * v86 + a34 - 4);
      v105 = numVerticesa - v86;
      do
      {
        v106 = v104[1];
        v107 = v104[2];
        v104[1] = (float)((float)(p_inputTransform->mat[2] * (float)0.0)
                        + (float)((float)(p_inputTransform->mat[1] * v104[2])
                                + (float)(p_inputTransform->mat[0] * v104[1])))
                + p_inputTransform->mat[3];
        v104[2] = (float)((float)(p_inputTransform->mat[6] * (float)0.0)
                        + (float)((float)(p_inputTransform->mat[5] * (float)v107)
                                + (float)((float)v106 * p_inputTransform->mat[4])))
                + p_inputTransform->mat[7];
        v108 = v104[3];
        v109 = v104[4];
        v104[3] = (float)((float)(p_inputTransform->mat[2] * (float)0.0)
                        + (float)((float)(p_inputTransform->mat[1] * v104[4])
                                + (float)(p_inputTransform->mat[0] * v104[3])))
                + p_inputTransform->mat[3];
        v104 += 4;
        *v104 = (float)((float)(p_inputTransform->mat[6] * (float)0.0)
                      + (float)((float)(p_inputTransform->mat[5] * (float)v109)
                              + (float)((float)v108 * p_inputTransform->mat[4])))
              + p_inputTransform->mat[7];
        --v105;
      }
      while ( v105 != 0 );
    }
  }
}


// ========================================================================
// ?UnTransformOutput@idObstacleAvoidanceCore@@AAAXPAUobstaclePath_t@@@Z
// EA  : 0x826C0D28
// RVA : 0x006C0D28
// PDB : w:\tech5\engine\gamelib\aas2\obstacleavoidancecore.cpp
// ========================================================================

void __fastcall idObstacleAvoidanceCore::UnTransformOutput(idObstacleAvoidanceCore *this, obstaclePath_t *path)
{
  double v2; // fp0
  int v3; // r10
  int v4; // r11
  avoidDebugLine_t *debugLines; // r9
  int v6; // r9
  obstaclePath_t *v7; // r10
  double v8; // fp0
  float y; // r8
  float x; // r7
  double v11; // fp11
  double v12; // fp6
  double v13; // fp4
  idMat3x4 *p_inputTransform; // r11
  double v15; // fp6
  double v16; // fp11
  double v17; // fp9
  double v18; // fp5
  float v19; // r7
  float v20; // r6
  double v21; // fp13
  double v22; // fp9
  double v23; // fp0
  double v24; // fp6
  double v25; // fp10
  float v26; // r7
  double v27; // fp2
  double v28; // fp1
  float v29; // r5
  double v30; // fp6
  double v31; // fp13
  double v32; // fp1
  double v33; // fp5
  double v34; // fp0
  float v35; // r5
  double v36; // fp10
  double v37; // fp5
  float v38; // r8
  double v39; // fp12
  double v40; // fp7
  int v41; // r8
  double v42; // fp1
  double v43; // fp5
  double v44; // fp7
  double v45; // fp12
  double v46; // fp8
  double v47; // fp2
  float v48; // r7
  double v49; // fp7
  double v50; // fp1
  double v51; // fp13
  double v52; // fp7
  double v53; // fp1
  double v54; // fp12
  int v55; // r10
  avoidDebugLine_t *v56; // r9
  double v57; // fp0
  float z; // r6
  double v59; // fp13
  float v60; // r5
  double v61; // fp11
  avoidDebugLine_t *v62; // r9
  avoidDebugLine_t *v63; // r7
  double v64; // fp13
  double v65; // fp9
  double v66; // fp4
  double v67; // fp2
  float v68; // [sp+4h] [-1Ch]
  float v69; // [sp+4h] [-1Ch]
  float v70; // [sp+4h] [-1Ch]
  float back_chain; // [sp+8h] [-18h]
  float back_chaina; // [sp+8h] [-18h]
  float back_chainb; // [sp+8h] [-18h]
  float back_chainc; // [sp+8h] [-18h]
  float back_chaind; // [sp+8h] [-18h]
  float v76; // [sp+10h] [-10h]
  float v77; // [sp+14h] [-Ch]
  float v78; // [sp+18h] [-8h]
  idVec3 direction; // 0:^0.12
  idVec3 v80; // 0:^0.12
  idPlane seekPosPlane; // 0:^10.16

  if ( this->inputTransformValid )
  {
    v6 = 0;
    if ( path->numSeekPos > 0 )
    {
      v7 = path;
      do
      {
        v8 = this->inputTransform.mat[7];
        y = v7->seekPos[0].y;
        x = v7->seekPos[0].x;
        v11 = this->inputTransform.mat[3];
        ++v6;
        back_chain = v7->seekPos[0].z;
        v12 = (float)(back_chain - this->inputTransform.mat[11]);
        v13 = (float)(v7->seekPos[0].x - this->inputTransform.mat[3]);
        v7->seekPos[0].x = (float)((float)(v7->seekPos[0].x - this->inputTransform.mat[3]) * this->inputTransform.mat[0])
                         + (float)((float)(this->inputTransform.mat[8]
                                         * (float)(back_chain - this->inputTransform.mat[11]))
                                 + (float)((float)(y - this->inputTransform.mat[7]) * this->inputTransform.mat[4]));
        v7->seekPos[0].y = (float)((float)(x - (float)v11) * this->inputTransform.mat[1])
                         + (float)((float)(this->inputTransform.mat[5] * (float)(y - (float)v8))
                                 + (float)((float)v12 * this->inputTransform.mat[9]));
        v7->seekPos[0].z = (float)((float)(y - (float)v8) * this->inputTransform.mat[6])
                         + (float)((float)(this->inputTransform.mat[10] * (float)v12)
                                 + (float)(this->inputTransform.mat[2] * (float)v13));
        v7 = (obstaclePath_t *)((char *)v7 + 12);
      }
      while ( v6 < path->numSeekPos );
    }
    seekPosPlane = path->seekPosPlane;
    p_inputTransform = &this->inputTransform;
    path->seekPosPlane.a = (float)(seekPosPlane.a * this->inputTransform.mat[0])
                         + (float)((float)(this->inputTransform.mat[8] * seekPosPlane.c)
                                 + (float)(seekPosPlane.b * this->inputTransform.mat[4]));
    path->seekPosPlane.b = (float)(this->inputTransform.mat[5] * seekPosPlane.b)
                         + (float)((float)(seekPosPlane.c * this->inputTransform.mat[9])
                                 + (float)(seekPosPlane.a * this->inputTransform.mat[1]));
    path->seekPosPlane.c = (float)(seekPosPlane.b * this->inputTransform.mat[6])
                         + (float)((float)(this->inputTransform.mat[10] * seekPosPlane.c)
                                 + (float)(this->inputTransform.mat[2] * seekPosPlane.a));
    path->seekPosPlane.d = (float)((float)(this->inputTransform.mat[3] * seekPosPlane.a)
                                 + (float)((float)(this->inputTransform.mat[11] * seekPosPlane.c)
                                         + (float)(this->inputTransform.mat[7] * seekPosPlane.b)))
                         + seekPosPlane.d;
    v15 = this->inputTransform.mat[7];
    v68 = path->firstObstaclePosition.y;
    back_chaina = path->firstObstaclePosition.z;
    v16 = (float)(back_chaina - this->inputTransform.mat[11]);
    v17 = (float)(path->firstObstaclePosition.x - this->inputTransform.mat[3]);
    path->firstObstaclePosition.x = (float)((float)(path->firstObstaclePosition.x - this->inputTransform.mat[3])
                                          * this->inputTransform.mat[0])
                                  + (float)((float)(this->inputTransform.mat[8]
                                                  * (float)(back_chaina - this->inputTransform.mat[11]))
                                          + (float)((float)(v68 - this->inputTransform.mat[7])
                                                  * this->inputTransform.mat[4]));
    path->firstObstaclePosition.y = (float)(this->inputTransform.mat[5] * (float)(v68 - (float)v15))
                                  + (float)((float)((float)v16 * this->inputTransform.mat[9])
                                          + (float)((float)v17 * this->inputTransform.mat[1]));
    path->firstObstaclePosition.z = (float)((float)(v68 - (float)v15) * this->inputTransform.mat[6])
                                  + (float)((float)(this->inputTransform.mat[10] * (float)v16)
                                          + (float)(this->inputTransform.mat[2] * (float)v17));
    v18 = this->inputTransform.mat[7];
    v19 = path->startPosOutsideObstacles.y;
    v20 = path->startPosOutsideObstacles.x;
    v21 = this->inputTransform.mat[3];
    back_chainb = path->startPosOutsideObstacles.z;
    v22 = (float)(back_chainb - this->inputTransform.mat[11]);
    path->startPosOutsideObstacles.x = (float)((float)(v20 - this->inputTransform.mat[3]) * this->inputTransform.mat[0])
                                     + (float)((float)(this->inputTransform.mat[8]
                                                     * (float)(back_chainb - this->inputTransform.mat[11]))
                                             + (float)((float)(v19 - this->inputTransform.mat[7])
                                                     * this->inputTransform.mat[4]));
    path->startPosOutsideObstacles.y = (float)(this->inputTransform.mat[5] * (float)(v19 - (float)v18))
                                     + (float)((float)((float)v22 * this->inputTransform.mat[9])
                                             + (float)((float)(v20 - (float)v21) * this->inputTransform.mat[1]));
    path->startPosOutsideObstacles.z = (float)((float)(v19 - (float)v18) * this->inputTransform.mat[6])
                                     + (float)((float)(this->inputTransform.mat[10] * (float)v22)
                                             + (float)(this->inputTransform.mat[2] * (float)(v20 - (float)v21)));
    v23 = this->inputTransform.mat[7];
    v69 = path->seekPosOutsideObstacles.y;
    back_chainc = path->seekPosOutsideObstacles.z;
    v24 = (float)(back_chainc - this->inputTransform.mat[11]);
    v25 = (float)(path->seekPosOutsideObstacles.x - this->inputTransform.mat[3]);
    path->seekPosOutsideObstacles.x = (float)((float)(path->seekPosOutsideObstacles.x - this->inputTransform.mat[3])
                                            * this->inputTransform.mat[0])
                                    + (float)((float)(this->inputTransform.mat[8]
                                                    * (float)(back_chainc - this->inputTransform.mat[11]))
                                            + (float)((float)(v69 - this->inputTransform.mat[7])
                                                    * this->inputTransform.mat[4]));
    path->seekPosOutsideObstacles.y = (float)(this->inputTransform.mat[5] * (float)(v69 - (float)v23))
                                    + (float)((float)((float)v24 * this->inputTransform.mat[9])
                                            + (float)((float)v25 * this->inputTransform.mat[1]));
    path->seekPosOutsideObstacles.z = (float)((float)(v69 - (float)v23) * this->inputTransform.mat[6])
                                    + (float)((float)(this->inputTransform.mat[10] * (float)v24)
                                            + (float)(this->inputTransform.mat[2] * (float)v25));
    v26 = path->radar[0].direction.x;
    v27 = this->inputTransform.mat[3];
    v28 = this->inputTransform.mat[7];
    v29 = path->radar[0].direction.y;
    back_chaind = path->radar[0].direction.z;
    v30 = (float)(back_chaind - this->inputTransform.mat[11]);
    path->radar[0].direction.x = (float)((float)(v26 - this->inputTransform.mat[3]) * this->inputTransform.mat[0])
                               + (float)((float)(this->inputTransform.mat[8]
                                               * (float)(back_chaind - this->inputTransform.mat[11]))
                                       + (float)((float)(v29 - this->inputTransform.mat[7]) * this->inputTransform.mat[4]));
    path->radar[0].direction.y = (float)(this->inputTransform.mat[5] * (float)(v29 - (float)v28))
                               + (float)((float)((float)v30 * this->inputTransform.mat[9])
                                       + (float)((float)(v26 - (float)v27) * this->inputTransform.mat[1]));
    path->radar[0].direction.z = (float)((float)(v29 - (float)v28) * this->inputTransform.mat[6])
                               + (float)((float)(this->inputTransform.mat[10] * (float)v30)
                                       + (float)(this->inputTransform.mat[2] * (float)(v26 - (float)v27)));
    v31 = this->inputTransform.mat[7];
    direction = path->radar[1].direction;
    v32 = this->inputTransform.mat[3];
    v33 = (float)(direction.z - this->inputTransform.mat[11]);
    path->radar[1].direction.x = (float)((float)(direction.x - this->inputTransform.mat[3]) * this->inputTransform.mat[0])
                               + (float)((float)(this->inputTransform.mat[8]
                                               * (float)(direction.z - this->inputTransform.mat[11]))
                                       + (float)((float)(direction.y - this->inputTransform.mat[7])
                                               * this->inputTransform.mat[4]));
    path->radar[1].direction.y = (float)(this->inputTransform.mat[5] * (float)(direction.y - (float)v31))
                               + (float)((float)((float)v33 * this->inputTransform.mat[9])
                                       + (float)((float)(direction.x - (float)v32) * this->inputTransform.mat[1]));
    path->radar[1].direction.z = (float)((float)(direction.y - (float)v31) * this->inputTransform.mat[6])
                               + (float)((float)(this->inputTransform.mat[10] * (float)v33)
                                       + (float)(this->inputTransform.mat[2] * (float)(direction.x - (float)v32)));
    v34 = this->inputTransform.mat[7];
    v35 = path->radar[2].direction.x;
    direction.y = path->radar[2].direction.y;
    v36 = this->inputTransform.mat[3];
    direction.z = path->radar[2].direction.z;
    v37 = (float)(direction.z - this->inputTransform.mat[11]);
    path->radar[2].direction.x = (float)((float)(v35 - this->inputTransform.mat[3]) * this->inputTransform.mat[0])
                               + (float)((float)(this->inputTransform.mat[8]
                                               * (float)(direction.z - this->inputTransform.mat[11]))
                                       + (float)((float)(direction.y - this->inputTransform.mat[7])
                                               * this->inputTransform.mat[4]));
    path->radar[2].direction.y = (float)(this->inputTransform.mat[5] * (float)(direction.y - (float)v34))
                               + (float)((float)((float)v37 * this->inputTransform.mat[9])
                                       + (float)((float)(v35 - (float)v36) * this->inputTransform.mat[1]));
    path->radar[2].direction.z = (float)((float)(direction.y - (float)v34) * this->inputTransform.mat[6])
                               + (float)((float)(this->inputTransform.mat[10] * (float)v37)
                                       + (float)(this->inputTransform.mat[2] * (float)(v35 - (float)v36)));
    v38 = path->radar[3].direction.x;
    v39 = this->inputTransform.mat[7];
    direction.y = path->radar[3].direction.y;
    v40 = this->inputTransform.mat[3];
    direction.z = path->radar[3].direction.z;
    v42 = (float)(direction.z - this->inputTransform.mat[11]);
    v43 = (float)(v38 - this->inputTransform.mat[3]);
    path->radar[3].direction.x = (float)((float)(v38 - this->inputTransform.mat[3]) * this->inputTransform.mat[0])
                               + (float)((float)(this->inputTransform.mat[8]
                                               * (float)(direction.z - this->inputTransform.mat[11]))
                                       + (float)((float)(direction.y - this->inputTransform.mat[7])
                                               * this->inputTransform.mat[4]));
    v44 = (float)((float)((float)v42 * this->inputTransform.mat[9])
                + (float)((float)(v38 - (float)v40) * this->inputTransform.mat[1]));
    v41 = 0;
    path->radar[3].direction.y = (float)(this->inputTransform.mat[5] * (float)(direction.y - (float)v39)) + (float)v44;
    path->radar[3].direction.z = (float)((float)(direction.y - (float)v39) * this->inputTransform.mat[6])
                               + (float)((float)(this->inputTransform.mat[10] * (float)v42)
                                       + (float)(this->inputTransform.mat[2] * (float)v43));
    v45 = this->inputTransform.mat[7];
    v80 = path->radar[4].direction;
    v46 = this->inputTransform.mat[3];
    v47 = (float)(v80.z - this->inputTransform.mat[11]);
    path->radar[4].direction.x = (float)((float)(v80.x - this->inputTransform.mat[3]) * this->inputTransform.mat[0])
                               + (float)((float)(this->inputTransform.mat[8]
                                               * (float)(v80.z - this->inputTransform.mat[11]))
                                       + (float)((float)(v80.y - this->inputTransform.mat[7])
                                               * this->inputTransform.mat[4]));
    path->radar[4].direction.y = (float)(this->inputTransform.mat[5] * (float)(v80.y - (float)v45))
                               + (float)((float)((float)v47 * this->inputTransform.mat[9])
                                       + (float)((float)(v80.x - (float)v46) * this->inputTransform.mat[1]));
    path->radar[4].direction.z = (float)((float)(v80.y - (float)v45) * this->inputTransform.mat[6])
                               + (float)((float)(this->inputTransform.mat[10] * (float)v47)
                                       + (float)(this->inputTransform.mat[2] * (float)(v80.x - (float)v46)));
    v48 = path->radar[5].direction.x;
    v80.z = path->radar[5].direction.z;
    v49 = (float)(path->radar[5].direction.y - this->inputTransform.mat[7]);
    v50 = (float)(v80.z - this->inputTransform.mat[11]);
    v51 = (float)(v48 - this->inputTransform.mat[3]);
    path->radar[5].direction.x = (float)((float)(v48 - this->inputTransform.mat[3]) * this->inputTransform.mat[0])
                               + (float)((float)(this->inputTransform.mat[8]
                                               * (float)(v80.z - this->inputTransform.mat[11]))
                                       + (float)((float)(path->radar[5].direction.y - this->inputTransform.mat[7])
                                               * this->inputTransform.mat[4]));
    path->radar[5].direction.y = (float)(this->inputTransform.mat[5] * (float)v49)
                               + (float)((float)((float)v50 * this->inputTransform.mat[9])
                                       + (float)((float)v51 * this->inputTransform.mat[1]));
    path->radar[5].direction.z = (float)((float)v49 * this->inputTransform.mat[6])
                               + (float)((float)(this->inputTransform.mat[10] * (float)v50)
                                       + (float)(this->inputTransform.mat[2] * (float)v51));
    v80.x = path->radar[6].direction.x;
    v52 = (float)(path->radar[6].direction.y - this->inputTransform.mat[7]);
    v80.z = path->radar[6].direction.z;
    v53 = (float)(v80.z - this->inputTransform.mat[11]);
    v54 = (float)(v80.x - this->inputTransform.mat[3]);
    path->radar[6].direction.x = (float)((float)(v80.x - this->inputTransform.mat[3]) * this->inputTransform.mat[0])
                               + (float)((float)(this->inputTransform.mat[8]
                                               * (float)(v80.z - this->inputTransform.mat[11]))
                                       + (float)((float)(path->radar[6].direction.y - this->inputTransform.mat[7])
                                               * this->inputTransform.mat[4]));
    path->radar[6].direction.y = (float)(this->inputTransform.mat[5] * (float)v52)
                               + (float)((float)((float)v53 * this->inputTransform.mat[9])
                                       + (float)((float)v54 * this->inputTransform.mat[1]));
    path->radar[6].direction.z = (float)((float)v52 * this->inputTransform.mat[6])
                               + (float)((float)(this->inputTransform.mat[10] * (float)v53)
                                       + (float)(this->inputTransform.mat[2] * (float)v54));
    if ( this->maxDebugLines > 0 )
    {
      v55 = 0;
      do
      {
        v56 = &this->debugLines[v55];
        if ( v56->color == COLOR_INVALID )
          break;
        v57 = this->inputTransform.mat[7];
        z = v56->start.z;
        v59 = this->inputTransform.mat[11];
        v60 = v56->start.x;
        v61 = this->inputTransform.mat[3];
        ++v41;
        v70 = v56->start.y;
        v62 = &this->debugLines[v55];
        v62->start.x = (float)((float)(v60 - this->inputTransform.mat[3]) * p_inputTransform->mat[0])
                     + (float)((float)(this->inputTransform.mat[8] * (float)(z - this->inputTransform.mat[11]))
                             + (float)((float)(v70 - this->inputTransform.mat[7]) * this->inputTransform.mat[4]));
        v62->start.y = (float)(this->inputTransform.mat[5] * (float)(v70 - (float)v57))
                     + (float)((float)((float)(z - (float)v59) * this->inputTransform.mat[9])
                             + (float)((float)(v60 - (float)v61) * this->inputTransform.mat[1]));
        v62->start.z = (float)((float)(v70 - (float)v57) * this->inputTransform.mat[6])
                     + (float)((float)(this->inputTransform.mat[10] * (float)(z - (float)v59))
                             + (float)(this->inputTransform.mat[2] * (float)(v60 - (float)v61)));
        v63 = &this->debugLines[v55];
        v64 = this->inputTransform.mat[7];
        ++v55;
        v65 = this->inputTransform.mat[3];
        v77 = v63->end.y;
        v78 = v63->end.z;
        v66 = (float)(v78 - this->inputTransform.mat[11]);
        v76 = v63->end.x;
        v67 = (float)(v76 - this->inputTransform.mat[3]);
        v63->end.x = (float)((float)(v76 - this->inputTransform.mat[3]) * p_inputTransform->mat[0])
                   + (float)((float)(this->inputTransform.mat[8] * (float)(v78 - this->inputTransform.mat[11]))
                           + (float)((float)(v77 - this->inputTransform.mat[7]) * this->inputTransform.mat[4]));
        v63->end.y = (float)(this->inputTransform.mat[5] * (float)(v77 - (float)v64))
                   + (float)((float)((float)v66 * this->inputTransform.mat[9])
                           + (float)((float)(v76 - (float)v65) * this->inputTransform.mat[1]));
        v63->end.z = (float)((float)(v77 - (float)v64) * this->inputTransform.mat[6])
                   + (float)((float)(this->inputTransform.mat[10] * (float)v66)
                           + (float)(this->inputTransform.mat[2] * (float)v67));
      }
      while ( v41 < this->maxDebugLines );
    }
  }
  else
  {
    v2 = path->startPosOutsideObstacles.z;
    v3 = 0;
    if ( this->maxDebugLines > 0 )
    {
      v4 = 0;
      do
      {
        debugLines = this->debugLines;
        if ( debugLines[v4].color == COLOR_INVALID )
          break;
        ++v3;
        debugLines[v4].start.z = v2;
        this->debugLines[v4++].end.z = v2;
      }
      while ( v3 < this->maxDebugLines );
    }
  }
}


// ========================================================================
// ?WindingRayIntersection@idObstacleAvoidanceCore@@CA_NPBVidVec2@@HABV2@1AAM2PAH@Z
// EA  : 0x826C1638
// RVA : 0x006C1638
// PDB : w:\tech5\engine\gamelib\aas2\obstacleavoidancecore.cpp
// ========================================================================

int __fastcall idObstacleAvoidanceCore::WindingRayIntersection(
        const idVec2 *winding,
        int numPoints,
        const idVec2 *start,
        const idVec2 *dir,
        float *scale1,
        float *scale2,
        int *edgeNums)
{
  int v14; // r31
  double z; // fp12
  double y; // fp11
  char *v17; // r11
  double x; // fp10
  int v19; // ctr
  const idVec2 *v20; // r7
  double v21; // fp0
  bool v22; // cr58
  int v24; // r28
  const idVec2 *v25; // r27
  float *v26; // r29
  int *v27; // r26
  char *i; // r25
  idVec3 *v29; // r3
  double v30; // fp13
  double v31; // fp12
  double v32; // fp12
  double v33; // fp11
  double v34; // fp0
  double v35; // fp13
  int v36; // r11
  int v37; // r10
  int v38; // [sp+4Ch] [-104h] BYREF
  int v39; // [sp+50h] [-100h] BYREF
  int v40; // [sp+54h] [-FCh]
  int v41; // [sp+58h] [-F8h]
  idVec3 v42; // [sp+60h] [-F0h] BYREF
  float v43; // [sp+70h] [-E0h] BYREF
  float v44; // [sp+74h] [-DCh]
  float v45; // [sp+78h] [-D8h]
  float v46; // [sp+7Ch] [-D4h]
  float v47; // [sp+80h] [-D0h]
  float v48; // [sp+84h] [-CCh]
  char v49; // [sp+8Ch] [-C4h] BYREF
  int v50; // [sp+90h] [-C0h] BYREF
  char v51; // [sp+94h] [-BCh] BYREF

  *scale2 = 0.0;
  *scale1 = 0.0;
  idObstacleAvoidanceCore::Plane2DFromVecs(result: &v42, start, dir, normalize: false);
  v14 = 0;
  v39 = 0;
  v40 = 0;
  v41 = 0;
  if ( numPoints > 0 )
  {
    z = v42.z;
    y = v42.y;
    v17 = &v49;
    x = v42.x;
    v19 = numPoints;
    v20 = winding;
    do
    {
      v21 = (float)((float)((float)(v20->y * (float)y) + (float)(v20->x * (float)x)) + (float)z);
      if ( v21 <= 0.1 )
      {
        if ( v21 >= -0.1 )
          *((_DWORD *)v17 + 1) = 2;
        else
          *((_DWORD *)v17 + 1) = 1;
      }
      else
      {
        *((_DWORD *)v17 + 1) = 0;
      }
      v17 += 4;
      ++v20;
      ++*(&v39 + *(_DWORD *)v17);
      --v19;
    }
    while ( v19 != 0 );
  }
  v22 = v39 == 0;
  *(&v50 + numPoints) = v50;
  if ( v22 )
    return 0;
  if ( v40 == 0 )
    return 0;
  v24 = 0;
  if ( numPoints <= 0 )
    return 0;
  v25 = winding;
  v26 = &v43;
  v27 = &v38;
  for ( i = &v51; ; i += 4 )
  {
    if ( *((_DWORD *)i - 1) != *(_DWORD *)i && *(_DWORD *)i != 2 )
    {
      *++v27 = v14;
      __twllei(numPoints, 0);
      ++v24;
      __twlgei(numPoints & ~(__ROL4__(v14 + 1, 1) - 1), 0xFFFFFFFF);
      v29 = idObstacleAvoidanceCore::Plane2DFromPoints(
              result: &v42,
              start: v25,
              end: &winding[(v14 + 1) % numPoints],
              normalize: false);
      v30 = v29->y;
      v31 = v29->z;
      *v26 = v29->x;
      v26[1] = v30;
      v26[2] = v31;
      v26 += 3;
      if ( v24 >= 2 )
        break;
    }
    ++v14;
    ++v25;
    if ( v14 >= numPoints )
      return 0;
  }
  if ( __fabs((float)-(float)((float)(dir->x * v43) + (float)(dir->y * v44))) <= idMath::FLT_SMALLEST_NON_DENORMAL )
    return 0;
  v32 = v47;
  v33 = v46;
  *scale1 = (float)((float)((float)(start->x * v43) + (float)(v44 * start->y)) + v45)
          / (float)-(float)((float)(dir->x * v43) + (float)(dir->y * v44));
  if ( __fabs((float)-(float)((float)(dir->x * (float)v33) + (float)(dir->y * (float)v32))) <= idMath::FLT_SMALLEST_NON_DENORMAL )
    return 0;
  v34 = (float)((float)((float)((float)(start->x * (float)v33) + (float)((float)v32 * start->y)) + v48)
              / (float)-(float)((float)(dir->x * (float)v33) + (float)(dir->y * (float)v32)));
  *scale2 = (float)((float)((float)(start->x * (float)v33) + (float)((float)v32 * start->y)) + v48)
          / (float)-(float)((float)(dir->x * (float)v33) + (float)(dir->y * (float)v32));
  v35 = *scale1;
  if ( __fabs(v35) <= __fabs(v34) )
  {
    v36 = v40;
    v37 = v39;
  }
  else
  {
    *scale1 = v34;
    v36 = v39;
    v37 = v40;
    *scale2 = v35;
  }
  if ( edgeNums != nullptr )
  {
    *edgeNums = v37;
    edgeNums[1] = v36;
  }
  return 1;
}


// ========================================================================
// ?LineIntersectsEdgeSequence@idObstacleAvoidanceCore@@ABA_NABVidVec2@@0PBUobstacleVertex_t@@PBUobstacleEdge_t@@PBF3H@Z
// EA  : 0x826C18F8
// RVA : 0x006C18F8
// PDB : w:\tech5\engine\gamelib\aas2\obstacleavoidancecore.cpp
// ========================================================================

int __fastcall idObstacleAvoidanceCore::LineIntersectsEdgeSequence(
        idObstacleAvoidanceCore *this,
        const idVec2 *start,
        const idVec2 *end,
        const obstacleVertex_t *vertices,
        const obstacleEdge_t *edges,
        const __int16 *sequenceFirst,
        const __int16 *nextEdge,
        int numSequences)
{
  double x; // fp12
  double v10; // fp11
  bool v11; // r11
  int v15; // r24
  int v17; // r11
  int v18; // r26
  const obstacleVertex_t *v19; // r11
  double v20; // fp0
  double y; // fp13
  int v22; // r28
  int v23; // r11
  const obstacleEdge_t *v24; // r8
  int v25; // r8
  const obstacleVertex_t *v26; // r8
  double v27; // fp13
  unsigned int v33; // ctr
  int v44; // r29
  int v45; // r30
  const obstacleEdge_t *v46; // r11
  const obstacleVertex_t *v47; // r8
  const obstacleVertex_t *v48; // r11
  double v49; // fp0
  double v50; // fp13
  const idVec2 *v51; // r3
  double v52; // fp9
  float v54[4]; // [sp+20h] [-A00h] BYREF
  char v55; // [sp+30h] [-9F0h] BYREF
  char v56; // [sp+40h] [-9E0h] BYREF
  char v57; // [sp+50h] [-9D0h] BYREF
  float v58[4]; // [sp+A0h] [-980h] BYREF
  char v59; // [sp+B0h] [-970h] BYREF
  char v60; // [sp+C0h] [-960h] BYREF
  char v61; // [sp+D0h] [-950h] BYREF
  _BYTE v62[32]; // [sp+120h] [-900h] BYREF
  _BYTE v63[16]; // [sp+140h] [-8E0h] BYREF
  char v64; // [sp+150h] [-8D0h] BYREF
  char v65; // [sp+160h] [-8C0h] BYREF
  char v66; // [sp+170h] [-8B0h] BYREF
  _DWORD v67[536]; // [sp+1C0h] [-860h] BYREF

  x = start->x;
  v10 = end->x;
  v11 = false;
  if ( __fabs((float)(start->x - end->x)) <= 0.1 )
    v11 = __fabs((float)(start->y - end->y)) <= 0.1;
  if ( !v11 )
  {
    _R11 = 16;
    __asm
    {
      lvlx128   v63, r0, r4
      lvlx128   v62, r0, r5
    }
    _R3 = &_vmx_00000000000000000000000000000000;
    _R31 = &_vmx_bdcccccdbdcccccdbdcccccdbdcccccd;
    __asm { lvrx128   v61, r11, r4 }
    v15 = 0;
    __asm
    {
      lvrx128   v60, r11, r5
      vor128    v59, v95, v61
      vor128    v58, v94, v60
    }
    __asm
    {
      lvx128    v57, r0, r3
      lvx128    v63, r0, r31
      vspltw128 v56, v59, 1
      vsubfp128 v55, v91, v58
      vspltw128 v12, v59, 0
      vspltw128 v54, v55, 0
      vspltw128 v0, v55, 1
      vsubfp128 v13, v89, v54
      vmulfp128 v11, v88, v13
      vmaddfp   v12, v12, v11, v0
      vsubfp128 v12, v89, v12
    }
    if ( numSequences > 0 )
    {
      while ( 2 )
      {
        v17 = *sequenceFirst;
        v18 = v17;
        v67[0] = v17;
        v19 = &vertices[edges[v17].verts[0]];
        v20 = v19->position.x;
        y = v19->position.y;
        while ( 1 )
        {
          v58[0] = y;
          v22 = 1;
          v54[0] = v20;
          if ( v18 != -1 )
          {
            v23 = 0;
            do
            {
              if ( v23 >= 31 )
                break;
              v24 = &edges[v18];
              if ( (v24->flags & 0x200) == 0 )
              {
                ++v22;
                v25 = v24->verts[1];
                v67[v23] = v18;
                v26 = &vertices[v25];
                v27 = v26->position.y;
                v54[v23 + 1] = v26->position.x;
                v58[++v23] = v27;
              }
              v18 = nextEdge[v18];
            }
            while ( v18 != -1 );
          }
          _R8 = 0;
          if ( v22 > 0 )
          {
            _R11 = 0;
            _R3 = v54;
            _R31 = v58;
            _R30 = &v55;
            v33 = ((unsigned int)(v22 - 1) >> 4) + 1;
            do
            {
              _R29 = &v56;
              __asm { lvx128    v10, r11, r3 }
              _R27 = &v57;
              __asm
              {
                lvx128    v11, r11, r30
                vmaddfp   v4, v0, v12, v10
              }
              _R23 = &v59;
              __asm { vmaddfp   v5, v0, v12, v11 }
              _R22 = &v60;
              _R21 = &v61;
              __asm
              {
                lvx128    v8, r11, r31
                lvx128    v10, r11, r29
              }
              _R29 = v62;
              __asm
              {
                lvx128    v11, r11, r27
                vmaddfp   v6, v0, v12, v10
                vmaddfp   v7, v0, v12, v11
                lvx128    v9, r11, r23
                lvx128    v10, r11, r22
              }
              _R27 = v63;
              __asm { lvx128    v11, r11, r21 }
              _R23 = &v64;
              _R22 = &v65;
              _R21 = &v66;
              __asm
              {
                vmaddfp   v8, v13, v4, v8
                vmaddfp   v9, v13, v5, v9
                vmaddfp   v10, v13, v6, v10
                vmaddfp   v11, v13, v7, v11
                vcmpgtfp128 v53, v8, v63
                stvx128   v8, r11, r27
                vcmpgtfp128 v52, v9, v63
                stvx128   v9, r11, r23
                vcmpgtfp128 v51, v10, v63
                stvx128   v10, r11, r22
                vcmpgtfp128 v50, v11, v63
                stvx128   v11, r11, r21
              }
              _R11 += 64;
              __asm
              {
                vpkuwus128 v49, v85, v52
                vpkuwus128 v48, v83, v50
                vpkuhus128 v47, v81, v48
                stvx128   v47, r8, r29
              }
              _R8 += 16;
              --v33;
            }
            while ( v33 != 0 );
          }
          v44 = 0;
          if ( v22 - 1 > 0 )
          {
            v45 = 0;
            do
            {
              if ( v62[v44 + 1] != v62[v44] )
              {
                v46 = &edges[v67[v45]];
                v47 = &vertices[v46->verts[1]];
                v48 = &vertices[v46->verts[0]];
                v49 = (float)((float)((float)(start->y * (float)(v47->position.x - v48->position.x))
                                    + (float)((float)x * (float)(v48->position.y - v47->position.y)))
                            - (float)((float)(v48->position.x * (float)(v48->position.y - v47->position.y))
                                    + (float)(v48->position.y * (float)(v47->position.x - v48->position.x))));
                v50 = (float)((float)((float)(end->y * (float)(v47->position.x - v48->position.x))
                                    + (float)((float)v10 * (float)(v48->position.y - v47->position.y)))
                            - (float)((float)(v48->position.x * (float)(v48->position.y - v47->position.y))
                                    + (float)(v48->position.y * (float)(v47->position.x - v48->position.x))));
                if ( ((COERCE_UNSIGNED_INT(
                         (float)((float)(end->y * (float)(v47->position.x - v48->position.x))
                               + (float)((float)v10 * (float)(v48->position.y - v47->position.y)))
                       - (float)((float)(v48->position.x * (float)(v48->position.y - v47->position.y))
                               + (float)(v48->position.y * (float)(v47->position.x - v48->position.x))))
                     ^ COERCE_UNSIGNED_INT(
                         (float)((float)(start->y * (float)(v47->position.x - v48->position.x))
                               + (float)((float)x * (float)(v48->position.y - v47->position.y)))
                       - (float)((float)(v48->position.x * (float)(v48->position.y - v47->position.y))
                               + (float)(v48->position.y * (float)(v47->position.x - v48->position.x)))))
                    & 0x80000000) != 0 )
                {
                  if ( __fabs(*(float *)&v63[v45 * 4]) >= __fabs(*(float *)&v63[v45 * 4 + 4]) )
                    v48 = v47;
                  v51 = start;
                  if ( __fabs(v49) >= __fabs(v50) )
                    v51 = end;
                  v52 = (float)(v48->position.y - v51->y);
                  if ( (float)((float)((float)(v48->position.x - v51->x) * (float)(v48->position.x - v51->x))
                             + (float)((float)v52 * (float)v52)) > 0.010000001 )
                    return 1;
                }
              }
              ++v44;
              ++v45;
            }
            while ( v44 < v22 - 1 );
          }
          if ( v18 == -1 )
            break;
          v20 = v54[v22 - 1];
          y = v58[v22 - 1];
          v67[0] = v67[v22 - 1];
        }
        ++v15;
        ++sequenceFirst;
        if ( v15 < numSequences )
          continue;
        break;
      }
    }
  }
  return 0;
}


// ========================================================================
// ?LineIntersectsWall@idObstacleAvoidanceCore@@ABA_NABVidVec2@@0@Z
// EA  : 0x826C1CF8
// RVA : 0x006C1CF8
// PDB : w:\tech5\engine\gamelib\aas2\obstacleavoidancecore.cpp
// ========================================================================

int __fastcall idObstacleAvoidanceCore::LineIntersectsWall(
        idObstacleAvoidanceCore *this,
        const idVec2 *start,
        const idVec2 *end)
{
  double v5; // fp13
  double x; // fp12
  double y; // fp10
  unsigned int v8; // r30
  double v9; // fp5
  double v10; // fp29
  int BspNodesForLine_r; // r24
  int v12; // r25
  double v13; // fp28
  double v14; // fp27
  int *v15; // r26
  double v16; // fp26
  double v17; // fp25
  int v18; // r29
  idObstacleAvoidanceCore::bspNode_t *v19; // r28
  int v20; // r30
  idObstacleAvoidanceCore::expandedObstacle_t *v21; // r11
  int id; // r11
  float v24; // [sp+50h] [-120h] BYREF
  float v25; // [sp+54h] [-11Ch] BYREF
  float v26; // [sp+58h] [-118h]
  float v27; // [sp+5Ch] [-114h]
  idVec2 v28; // [sp+60h] [-110h] BYREF
  float v29; // [sp+68h] [-108h] BYREF
  float v30; // [sp+6Ch] [-104h] BYREF
  int v31[46]; // [sp+70h] [-100h] BYREF

  if ( this->bspNodes == nullptr )
    return 0;
  if ( this->obstacleIndices == nullptr )
    return 0;
  if ( this->expandedObstacles == nullptr )
    return 0;
  v5 = (float)(end->y - start->y);
  v28.y = end->y - start->y;
  x = start->x;
  v28.x = end->x - start->x;
  y = start->y;
  v8 = ((unsigned int)~LODWORD(v28.y) >> 28) & 8;
  v25 = start->y - (float)1.0;
  v24 = (float)x - (float)1.0;
  v26 = (float)x + (float)1.0;
  v27 = (float)y + (float)1.0;
  v9 = (float)(v28.x * v28.x);
  *(float *)((char *)&v24 + (((unsigned int)~LODWORD(v28.x) >> 28) & 8)) = *(float *)((char *)&v24
                                                                                    + (((unsigned int)~LODWORD(v28.x) >> 28)
                                                                                     & 8))
                                                                         + v28.x;
  v10 = __fsqrts((float)((float)((float)v5 * (float)v5) + (float)v9));
  *(float *)((char *)&v25 + v8) = *(float *)((char *)&v25 + v8) + (float)v5;
  BspNodesForLine_r = idObstacleAvoidanceCore::GetBspNodesForLine_r(
                        this,
                        p1: start,
                        p2: end,
                        nodeNum: 0,
                        numNodes: 0,
                        nodes: v31);
  v12 = 0;
  if ( BspNodesForLine_r <= 0 )
    return 0;
  v13 = v27;
  v14 = v26;
  v15 = v31;
  v16 = v25;
  v17 = v24;
  while ( 1 )
  {
    v18 = 0;
    v19 = &this->bspNodes[*v15];
    if ( v19->numIndices > 0 )
      break;
LABEL_21:
    ++v12;
    ++v15;
    if ( v12 >= BspNodesForLine_r )
      return 0;
  }
  while ( 1 )
  {
    v20 = this->obstacleIndices[v19->indexOffset + v18];
    v21 = &this->expandedObstacles[v20];
    if ( v17 <= v21->bounds[1].x && v16 <= v21->bounds[1].y && v14 >= v21->bounds[0].x && v13 >= v21->bounds[0].y )
    {
      id = v21->id;
      if ( (id == -2 || id == -3 || id == -4)
        && (unsigned __int8)idObstacleAvoidanceCore::WindingRayIntersection(
                              winding: this->expandedObstacles[v20].winding,
                              numPoints: this->expandedObstacles[v20].numPoints,
                              start,
                              dir: &v28,
                              scale1: &v29,
                              scale2: &v30,
                              edgeNums: (int *)&v24) != 0
        && (float)(v29 * (float)v10) > -0.0099999998
        && v29 < 1.0
        && (this->expandedObstacles[v20].id != -3 || LODWORD(v24) == 2 || LODWORD(v25) == 2) )
      {
        return 1;
      }
    }
    if ( ++v18 >= v19->numIndices )
      goto LABEL_21;
  }
}


// ========================================================================
// ?LineIntersectsObstacle@idObstacleAvoidanceCore@@ABA_NABVidVec2@@0HH@Z
// EA  : 0x826C1F68
// RVA : 0x006C1F68
// PDB : w:\tech5\engine\gamelib\aas2\obstacleavoidancecore.cpp
// ========================================================================

int __fastcall idObstacleAvoidanceCore::LineIntersectsObstacle(
        idObstacleAvoidanceCore *this,
        const idVec2 *start,
        const idVec2 *end,
        int endObstacle,
        int ignoreObstacle)
{
  double v9; // fp13
  double x; // fp12
  double y; // fp10
  unsigned int v12; // r30
  double v13; // fp5
  double v14; // fp31
  int BspNodesForLine_r; // r23
  int v16; // r24
  double v17; // fp27
  double v18; // fp26
  double v19; // fp25
  int *v20; // r26
  double v21; // fp24
  int v22; // r29
  idObstacleAvoidanceCore::bspNode_t *v23; // r28
  __int16 v24; // r7
  int v25; // r30
  float *v26; // r11
  float v28; // [sp+50h] [-140h] BYREF
  float v29; // [sp+54h] [-13Ch] BYREF
  float v30; // [sp+58h] [-138h]
  float v31; // [sp+5Ch] [-134h]
  idVec2 v32; // [sp+60h] [-130h] BYREF
  float v33; // [sp+68h] [-128h] BYREF
  float v34; // [sp+6Ch] [-124h] BYREF
  int v35[50]; // [sp+70h] [-120h] BYREF

  if ( this->bspNodes == nullptr )
    return 0;
  if ( this->expandedObstacles == nullptr )
    return 0;
  if ( this->obstacleIndices == nullptr )
    return 0;
  v9 = (float)(end->y - start->y);
  v32.y = end->y - start->y;
  x = start->x;
  v32.x = end->x - start->x;
  y = start->y;
  v12 = ((unsigned int)~LODWORD(v32.y) >> 28) & 8;
  v29 = start->y - (float)1.0;
  v28 = (float)x - (float)1.0;
  v30 = (float)x + (float)1.0;
  v31 = (float)y + (float)1.0;
  v13 = (float)(v32.x * v32.x);
  *(float *)((char *)&v28 + (((unsigned int)~LODWORD(v32.x) >> 28) & 8)) = *(float *)((char *)&v28
                                                                                    + (((unsigned int)~LODWORD(v32.x) >> 28)
                                                                                     & 8))
                                                                         + v32.x;
  v14 = __fsqrts((float)((float)((float)v9 * (float)v9) + (float)v13));
  *(float *)((char *)&v29 + v12) = *(float *)((char *)&v29 + v12) + (float)v9;
  BspNodesForLine_r = idObstacleAvoidanceCore::GetBspNodesForLine_r(
                        this,
                        p1: start,
                        p2: end,
                        nodeNum: 0,
                        numNodes: 0,
                        nodes: v35);
  v16 = 0;
  if ( BspNodesForLine_r <= 0 )
    return 0;
  v17 = v31;
  v18 = v30;
  v19 = v29;
  v20 = v35;
  v21 = v28;
  while ( 1 )
  {
    v22 = 0;
    v23 = &this->bspNodes[*v20];
    if ( v23->numIndices > 0 )
      break;
LABEL_18:
    ++v16;
    ++v20;
    if ( v16 >= BspNodesForLine_r )
      return 0;
  }
  while ( 1 )
  {
    v24 = this->obstacleIndices[v23->indexOffset + v22];
    v25 = v24;
    if ( v24 != ignoreObstacle )
    {
      v26 = (float *)&this->expandedObstacles[v24];
      if ( v21 <= v26[2]
        && v19 <= v26[3]
        && v18 >= *v26
        && v17 >= v26[1]
        && (unsigned __int8)idObstacleAvoidanceCore::WindingRayIntersection(
                              winding: this->expandedObstacles[v24].winding,
                              numPoints: this->expandedObstacles[v24].numPoints,
                              start,
                              dir: &v32,
                              scale1: &v33,
                              scale2: &v34,
                              edgeNums: (int *)&v28) != 0
        && v33 >= 0.0
        && v33 <= 1.0
        && (v25 != endObstacle || (float)(v33 * (float)v14) < (double)(float)((float)v14 - (float)0.5)) )
      {
        return 1;
      }
    }
    if ( ++v22 >= v23->numIndices )
      goto LABEL_18;
  }
}


// ========================================================================
// ?GetFirstBlockingObstacle@idObstacleAvoidanceCore@@AAA_NABVidVec2@@0HAAMAAH2@Z
// EA  : 0x826C21C0
// RVA : 0x006C21C0
// PDB : w:\tech5\engine\gamelib\aas2\obstacleavoidancecore.cpp
// ========================================================================

BOOL __fastcall idObstacleAvoidanceCore::GetFirstBlockingObstacle(
        idObstacleAvoidanceCore *this,
        const idVec2 *start,
        const idVec2 *delta,
        int skipObstacle,
        float *blockingScale,
        int *blockingObstacle,
        int *blockingEdgeNum)
{
  double x; // fp13
  double y; // fp12
  double v17; // fp11
  double v18; // fp10
  unsigned int v19; // r6
  unsigned int v20; // r5
  double v21; // fp7
  double v22; // fp8
  int v23; // r30
  double v24; // fp9
  double v25; // fp13
  double v26; // fp12
  double v27; // fp8
  double v28; // fp30
  int BspNodesForLine_r; // r3
  double v30; // fp28
  double v31; // fp27
  int *v32; // r24
  double v33; // fp26
  int v34; // r21
  double v35; // fp25
  int v36; // r29
  idObstacleAvoidanceCore::bspNode_t *v37; // r28
  idObstacleAvoidanceCore::expandedObstacle_t *expandedObstacles; // r9
  __int16 v39; // r6
  int v40; // r30
  int v41; // r10
  float *v42; // r11
  int v43; // r11
  float v44; // [sp+50h] [-140h] BYREF
  float v45; // [sp+54h] [-13Ch] BYREF
  float v46; // [sp+58h] [-138h]
  float v47; // [sp+5Ch] [-134h]
  float v48; // [sp+60h] [-130h] BYREF
  float v49; // [sp+64h] [-12Ch] BYREF
  idVec2 v50; // [sp+68h] [-128h] BYREF
  int v51[46]; // [sp+70h] [-120h] BYREF

  if ( this->bspNodes == nullptr || this->expandedObstacles == nullptr || this->obstacleIndices == nullptr )
    return false;
  x = start->x;
  y = start->y;
  v17 = delta->x;
  v18 = delta->y;
  v19 = ~LODWORD(delta->x);
  v20 = ~LODWORD(delta->y);
  *blockingScale = 1.0e30;
  v21 = delta->y;
  v22 = start->y;
  v23 = (v20 >> 28) & 8;
  v24 = start->x;
  v44 = (float)x - (float)1.0;
  v45 = (float)y - (float)1.0;
  v46 = (float)x + (float)1.0;
  v47 = (float)y + (float)1.0;
  *(float *)((char *)&v44 + ((v19 >> 28) & 8)) = *(float *)((char *)&v44 + ((v19 >> 28) & 8)) + (float)v17;
  v25 = (float)((float)v22 + (float)v21);
  v26 = *(float *)((char *)&v45 + v23);
  v27 = (float)(delta->x * delta->x);
  v50.x = (float)v24 + delta->x;
  v50.y = v25;
  *(float *)((char *)&v45 + v23) = (float)v26 + (float)v18;
  v28 = __fsqrts((float)((float)((float)v21 * (float)v21) + (float)v27));
  BspNodesForLine_r = idObstacleAvoidanceCore::GetBspNodesForLine_r(
                        this,
                        p1: start,
                        p2: &v50,
                        nodeNum: 0,
                        numNodes: 0,
                        nodes: v51);
  if ( BspNodesForLine_r > 0 )
  {
    v30 = v47;
    v31 = v46;
    v32 = v51;
    v33 = v45;
    v34 = BspNodesForLine_r;
    v35 = v44;
    do
    {
      v36 = 0;
      v37 = &this->bspNodes[*v32];
      if ( v37->numIndices > 0 )
      {
        do
        {
          expandedObstacles = this->expandedObstacles;
          v39 = this->obstacleIndices[v37->indexOffset + v36];
          v40 = v39;
          v41 = v39;
          v42 = (float *)&expandedObstacles[v41];
          if ( v35 <= expandedObstacles[v41].bounds[1].x
            && v33 <= v42[3]
            && v31 >= *v42
            && v30 >= v42[1]
            && v39 != skipObstacle
            && (unsigned __int8)idObstacleAvoidanceCore::WindingRayIntersection(
                                  winding: expandedObstacles[v41].winding,
                                  numPoints: expandedObstacles[v41].numPoints,
                                  start,
                                  dir: delta,
                                  scale1: &v49,
                                  scale2: &v48,
                                  edgeNums: (int *)&v44) != 0
            && v49 < (double)*blockingScale
            && (float)(v48 * (float)v28) > 0.0099999998 )
          {
            v43 = LODWORD(v44);
            *blockingScale = v49;
            *blockingObstacle = v40;
            *blockingEdgeNum = v43;
          }
          ++v36;
        }
        while ( v36 < v37->numIndices );
      }
      --v34;
      ++v32;
    }
    while ( v34 != 0 );
  }
  return *blockingScale < 1.0;
}


// ========================================================================
// ?GetPointOutsideObstacles@idObstacleAvoidanceCore@@AAA_NAAVidVec2@@PAH1ABV2@_N@Z
// EA  : 0x826C2448
// RVA : 0x006C2448
// PDB : w:\tech5\engine\gamelib\aas2\obstacleavoidancecore.cpp
// ========================================================================

int __fastcall idObstacleAvoidanceCore::GetPointOutsideObstacles(
        idObstacleAvoidanceCore *this,
        idVec2 *point,
        int *obstacle,
        int *edgeNum,
        const idVec2 *startPos,
        bool moveAroundSeekPosObstacles)
{
  idVec2 *v7; // r31
  int *v8; // r24
  int *v9; // r27
  int v10; // r17
  int v11; // r16
  unsigned __int8 *tempMemoryEnd; // r4
  unsigned int v13; // r10
  unsigned int v14; // r9
  int *v15; // r14
  int v16; // r21
  int v17; // r15
  double y; // fp22
  double x; // fp23
  int *v20; // r18
  idVec2 *v21; // r5
  int v22; // r3
  int v23; // r19
  idObstacleAvoidanceCore::expandedObstacle_t *v24; // r11
  int id; // r10
  unsigned __int8 v26; // r10
  bool v27; // zf
  signed int numPoints; // r30
  idVec2 *winding; // r26
  unsigned __int8 v30; // r25
  char v31; // r20
  int v32; // r29
  double v33; // fp28
  double v34; // fp27
  int v35; // r28
  double v36; // fp26
  const idVec2 *v37; // r27
  signed int v38; // r31
  double v39; // fp30
  double v40; // fp31
  double v41; // fp29
  char v42; // r3
  idObstacleAvoidanceCore::expandedObstacle_t *v43; // r11
  int v44; // r28
  idVec2 *v45; // r5
  int v46; // r23
  int *v47; // r21
  int i; // r18
  idObstacleAvoidanceCore::expandedObstacle_t *expandedObstacles; // r11
  float *v50; // r10
  idObstacleAvoidanceCore::expandedObstacle_t *v51; // r11
  int v52; // r10
  char v53; // r10
  int v54; // r25
  char v55; // r24
  int v56; // r30
  const idVec2 *v57; // r29
  int v58; // r31
  double v59; // fp27
  double v60; // fp26
  float *v61; // r11
  double v62; // fp25
  double v63; // fp24
  int v64; // r27
  double v65; // fp0
  double v66; // fp30
  double v67; // fp31
  double v68; // fp9
  double v69; // fp29
  unsigned __int8 *v70; // r11
  unsigned __int8 *tempMemory; // r11
  idVec2 v73; // [sp+50h] [-260h] BYREF
  idVec2 v74; // [sp+58h] [-258h] BYREF
  idVec2 v75; // [sp+60h] [-250h] BYREF
  idVec2 v76; // [sp+68h] [-248h] BYREF
  int *v77; // [sp+70h] [-240h]
  unsigned int v78; // [sp+74h] [-23Ch]
  float v79; // [sp+78h] [-238h] BYREF
  float v80; // [sp+7Ch] [-234h] BYREF
  idVec2 v81; // [sp+80h] [-230h] BYREF
  idVec3 v82; // [sp+88h] [-228h] BYREF
  int v83[2]; // [sp+98h] [-218h] BYREF
  _QWORD v84[16]; // [sp+A0h] [-210h] BYREF
  idVec2 v85[31]; // [sp+120h] [-190h] BYREF

  v7 = point;
  v8 = obstacle;
  v9 = edgeNum;
  if ( obstacle != nullptr )
    *obstacle = -1;
  if ( edgeNum != nullptr )
    *edgeNum = -1;
  if ( this->expandedObstacles == nullptr )
    return 1;
  v10 = -1;
  v11 = -1;
  tempMemoryEnd = this->tempMemoryEnd;
  v13 = (4 * this->numExpandedObstacles + 15) & 0xFFFFFFF0;
  v14 = (this->flags & 0x200) == 0 ? 0 : 0xFFFFFFF1;
  v74 = *v7;
  v73 = v74;
  v15 = (int *)&tempMemoryEnd[-v13];
  v16 = v14 + 16;
  this->tempMemoryEnd = &tempMemoryEnd[-v13];
  v17 = 0;
  v78 = v14 + 16;
  if ( (int)(v14 + 16) > 0 )
  {
    y = v74.y;
    x = v74.x;
    v20 = v15 - 1;
    v77 = v15 - 1;
    while ( 1 )
    {
      v22 = idObstacleAvoidanceCore::PointInsideObstacle(this, point: &v74);
      v23 = v22;
      if ( v22 == -1 )
        break;
      v24 = &this->expandedObstacles[v22];
      id = v24->id;
      if ( id == -2 || (v27 = id != -3, v26 = 0, !v27) )
        v26 = 1;
      numPoints = v24->numPoints;
      winding = v24->winding;
      v30 = v26;
      v31 = 0;
      v32 = 0;
      v33 = 1.0e30;
      if ( numPoints > 0 )
      {
        v34 = v73.y;
        v35 = v26;
        v36 = v73.x;
        v37 = v24->winding;
        while ( 1 )
        {
          v38 = v32 + 1;
          __twllei(numPoints, 0);
          __twlgei(numPoints & ~(__ROL4__(v32 + 1, 1) - 1), 0xFFFFFFFF);
          idObstacleAvoidanceCore::Plane2DFromPoints(
            result: &v82,
            start: &winding[(v32 + 1) % numPoints],
            end: v37,
            normalize: true);
          if ( v35 != 0
            || !moveAroundSeekPosObstacles
            || (float)((float)((float)(startPos->y * v82.y) + (float)(startPos->x * v82.x)) + v82.z) >= 0.0 )
          {
            if ( (float)((float)((float)((float)v34 * v82.y) + (float)((float)v36 * v82.x)) + v82.z) >= v33 )
              goto LABEL_26;
            v39 = (float)((float)v36
                        - (float)((float)((float)((float)((float)((float)v34 * v82.y) + (float)((float)v36 * v82.x))
                                                + v82.z)
                                        + (float)0.5)
                                * v82.x));
            v76.x = (float)v36
                  - (float)((float)((float)((float)((float)((float)v34 * v82.y) + (float)((float)v36 * v82.x)) + v82.z)
                                  + (float)0.5)
                          * v82.x);
            v40 = (float)((float)v34
                        - (float)((float)((float)((float)((float)((float)v34 * v82.y) + (float)((float)v36 * v82.x))
                                                + v82.z)
                                        + (float)0.5)
                                * v82.y));
            v76.y = (float)v34
                  - (float)((float)((float)((float)((float)((float)v34 * v82.y) + (float)((float)v36 * v82.x)) + v82.z)
                                  + (float)0.5)
                          * v82.y);
            v41 = (float)((float)((float)(v76.y - (float)v34) * (float)(v76.y - (float)v34))
                        + (float)((float)(v76.x - (float)v36) * (float)(v76.x - (float)v36)));
            if ( v41 < v33
              && idObstacleAvoidanceCore::PointInsideObstacleList(
                   this,
                   obstacleList: v15,
                   numObstacles: v17,
                   point: &v76) == -1 )
            {
              if ( v35 != 0 )
                goto LABEL_23;
              v42 = idObstacleAvoidanceCore::LineIntersectsWall(this, start: &v73, end: &v76);
              v34 = v73.y;
              v36 = v73.x;
              if ( v42 == 0 )
                break;
            }
          }
LABEL_27:
          ++v32;
          ++v37;
          if ( v38 >= numPoints )
          {
LABEL_28:
            v7 = point;
            v74.x = x;
            v9 = edgeNum;
            v74.y = y;
            goto LABEL_29;
          }
        }
        v40 = v76.y;
        v39 = v76.x;
LABEL_23:
        x = v39;
        v10 = v23;
        y = v40;
        v11 = v32;
        v33 = v41;
        if ( v35 != 0 )
        {
          v73.x = v39;
          v36 = v39;
          v73.y = v40;
          v34 = v40;
        }
        v31 = 1;
LABEL_26:
        if ( v35 != 0 )
          goto LABEL_28;
        goto LABEL_27;
      }
LABEL_29:
      v43 = &this->expandedObstacles[v23];
      v44 = v43->numPoints;
      idObstacleAvoidanceCore::ExpandWinding(winding: v43->winding, numPoints: v44, d: 0.5, expanded: v21, a5: (int)v84);
      v46 = v30;
      if ( v30 != 0 )
        v44 = 1;
      if ( v17 > 0 )
      {
        v47 = v15;
        for ( i = v17; i != 0; --i )
        {
          expandedObstacles = this->expandedObstacles;
          v50 = (float *)&expandedObstacles[v23];
          v51 = &expandedObstacles[*v47];
          if ( v51->bounds[0].x <= (double)(float)(v50[2] + (float)0.5)
            && v51->bounds[0].y <= (double)(float)(v50[3] + (float)0.5)
            && v51->bounds[1].x >= (double)(float)(*v50 - (float)0.5)
            && v51->bounds[1].y >= (double)(float)(v50[1] - (float)0.5) )
          {
            v52 = v51->id;
            if ( v52 == -2 || (v27 = v52 != -3, v53 = 0, !v27) )
              v53 = 1;
            v54 = v51->numPoints;
            v55 = v53;
            idObstacleAvoidanceCore::ExpandWinding(
              winding: v51->winding,
              numPoints: v54,
              d: 0.5,
              expanded: v45,
              a5: (int)v85);
            v56 = 0;
            if ( v44 > 0 )
            {
              v57 = (const idVec2 *)v84;
              while ( 1 )
              {
                v58 = v56 + 1;
                v59 = v57->x;
                v60 = v57->y;
                v61 = (float *)&v84[(v56 + 1) % v44];
                v62 = (float)(*v61 - v57->x);
                v63 = (float)(v61[1] - v57->y);
                v81.x = *v61 - v57->x;
                v81.y = v63;
                __twllei(v44, 0);
                __twlgei(v44 & ~(__ROL4__(v56 + 1, 1) - 1), 0xFFFFFFFF);
                v45 = (idVec2 *)(unsigned __int8)idObstacleAvoidanceCore::WindingRayIntersection(
                                                   winding: v85,
                                                   numPoints: v54,
                                                   start: v57,
                                                   dir: &v81,
                                                   scale1: &v79,
                                                   scale2: &v80,
                                                   edgeNums: v83);
                if ( v45 != nullptr )
                  break;
LABEL_57:
                ++v56;
                ++v57;
                if ( v58 >= v44 )
                  goto LABEL_58;
              }
              v64 = 0;
              while ( 2 )
              {
                if ( v55 == 0 || v83[v64] == 0 )
                {
                  v65 = *(float *)((char *)&v79 + v64 * 4);
                  if ( v65 >= -0.0099999998 && v65 <= 1.01 )
                  {
                    v66 = (float)((float)((float)v62 * *(float *)((char *)&v79 + v64 * 4)) + (float)v59);
                    v75.x = (float)((float)v62 * *(float *)((char *)&v79 + v64 * 4)) + (float)v59;
                    v67 = (float)((float)((float)v63 * (float)v65) + (float)v60);
                    v75.y = (float)((float)v63 * (float)v65) + (float)v60;
                    v68 = (float)((float)((float)((float)v62 * (float)v65) + (float)v59) - v73.x);
                    v69 = (float)((float)((float)(v75.y - v73.y) * (float)(v75.y - v73.y))
                                + (float)((float)v68 * (float)v68));
                    if ( v69 < v33
                      && idObstacleAvoidanceCore::PointInsideObstacleList(
                           this,
                           obstacleList: v15,
                           numObstacles: v17,
                           point: &v75) == -1 )
                    {
                      if ( v46 != 0 )
                        goto LABEL_53;
                      if ( (unsigned __int8)idObstacleAvoidanceCore::LineIntersectsWall(this, start: &v73, end: &v75) == 0 )
                      {
                        v67 = v75.y;
                        v66 = v75.x;
LABEL_53:
                        x = v66;
                        v11 = v56;
                        y = v67;
                        v10 = v23;
                        v33 = v69;
                        if ( v46 != 0 )
                        {
                          v73.x = v66;
                          v73.y = v67;
                        }
                        v31 = 1;
                      }
                    }
                  }
                }
                if ( ++v64 >= 2 )
                  goto LABEL_57;
                continue;
              }
            }
LABEL_58:
            v8 = obstacle;
          }
          ++v47;
        }
        v20 = v77;
        v74.y = y;
        v16 = v78;
        v74.x = x;
        v7 = point;
        v9 = edgeNum;
      }
      if ( v31 != 0 )
      {
        *++v20 = v23;
        ++v17;
        v77 = v20;
        if ( v17 < v16 )
          continue;
      }
      goto LABEL_63;
    }
    v7->x = x;
    v7->y = y;
    if ( v8 != nullptr )
      *v8 = v10;
    if ( v9 != nullptr )
      *v9 = v11;
    tempMemory = this->tempMemory;
    if ( tempMemory != nullptr )
      this->tempMemoryEnd = &tempMemory[this->tempMemorySize];
    return 1;
  }
LABEL_63:
  if ( v8 != nullptr )
    *v8 = v10;
  if ( v9 != nullptr )
    *v9 = v11;
  v70 = this->tempMemory;
  if ( v70 != nullptr )
    this->tempMemoryEnd = &v70[this->tempMemorySize];
  return 0;
}


// ========================================================================
// ?SetupExpandedObstacles@idObstacleAvoidanceCore@@AAA_NABVidBounds@@ABVidVec3@@11M_NPBUobstacleBox_t@@HPBUobstacleVertex_t@@HPBUobstacleEdge_t@@HPBUobstacleCorner_t@@H_N@Z
// EA  : 0x826C2A58
// RVA : 0x006C2A58
// PDB : w:\tech5\engine\gamelib\aas2\obstacleavoidancecore.cpp
// ========================================================================

int __fastcall idObstacleAvoidanceCore::SetupExpandedObstacles(
        idObstacleAvoidanceCore *this,
        int bounds,
        const idVec3 *gravity,
        const idVec2 *startPos,
        const idVec2 *seekPos,
        double obstacleRadius,
        const bool assumeValidAASPath,
        const obstacleBox_t *obstacles,
        int numObstacles,
        const obstacleVertex_t *vertices,
        int numVertices,
        const obstacleEdge_t *edges,
        int numEdges,
        const obstacleCorner_t *corners,
        int numCorners,
        bool hasTraces,
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
        const obstacleVertex_t *a31,
        int a32,
        int a33,
        int a34,
        const obstacleEdge_t *a35,
        int a36,
        int numObstacles_0,
        int a38,
        const obstacleVertex_t *verticesa,
        int a40,
        int numVerticesa,
        int a42,
        char edges_3)
{
  char v43; // r23
  double v45; // fp11
  double v46; // fp10
  double v49; // fp9
  double v50; // fp8
  const idVec2 *v51; // r21
  double v53; // fp26
  int v54; // r28
  int i; // r25
  idObstacleAvoidanceCore::expandedObstacle_t *v56; // r29
  int v57; // r3
  signed int v58; // r30
  int v59; // r9
  float *v60; // r10
  float *v61; // r11
  double v62; // fp11
  double v63; // fp10
  double v64; // fp9
  double v65; // fp8
  double v66; // fp0
  float *v67; // r10
  int v68; // ctr
  float *v69; // r11
  double v70; // fp13
  double v71; // fp0
  int v72; // r3
  double v73; // fp13
  double v74; // fp0
  int v75; // r10
  idVec2 *windingPoints; // r8
  int numWindingPoints; // r11
  int numPoints; // r5
  int v79; // r11
  float *p_x; // r8
  double v81; // fp13
  signed int v82; // r10
  int v83; // r8
  float *v84; // r7
  int numDebugLines; // r9
  int v86; // r5
  idVec3 *v87; // r11
  avoidDebugLine_t *debugLines; // r5
  double x; // fp0
  double y; // fp13
  double v91; // fp12
  double v92; // fp11
  avoidDebugLine_t *v93; // r11
  int v94; // r9
  int v95; // r5
  idVec3 *v96; // r11
  avoidDebugLine_t *v97; // r5
  double v98; // fp0
  double v99; // fp13
  double v100; // fp12
  double v101; // fp11
  avoidDebugLine_t *v102; // r11
  int v103; // r9
  int v104; // r5
  idVec3 *v105; // r11
  avoidDebugLine_t *v106; // r5
  double v107; // fp0
  double v108; // fp13
  double v109; // fp12
  double v110; // fp11
  avoidDebugLine_t *v111; // r11
  int v112; // r9
  int v113; // r5
  idVec3 *v114; // r11
  avoidDebugLine_t *v115; // r5
  double v116; // fp0
  double v117; // fp13
  double v118; // fp12
  double v119; // fp11
  avoidDebugLine_t *v120; // r11
  idVec3 *v121; // r5
  int v122; // ctr
  int v123; // r9
  int v124; // r8
  idVec3 *v125; // r11
  avoidDebugLine_t *v126; // r7
  double v127; // fp0
  double v128; // fp13
  double v129; // fp12
  double v130; // fp11
  avoidDebugLine_t *v131; // r11
  int v132; // r6
  double v133; // fp7
  double v134; // fp8
  double v135; // fp6
  unsigned __int8 **p_tempMemoryEnd; // r17
  int v137; // r9
  unsigned int v138; // r7
  unsigned __int8 *v139; // r11
  unsigned __int8 *v140; // r10
  const __int16 *v141; // r15
  unsigned __int8 *v142; // r11
  const idBounds *v143; // r20
  unsigned __int8 *v144; // r14
  unsigned __int8 *v145; // r11
  int v146; // ctr
  int v147; // r10
  int v148; // r7
  int v149; // r19
  int v150; // r10
  int v151; // r28
  int v152; // r11
  int v153; // r5
  int v154; // r30
  int v155; // r11
  unsigned __int8 *v156; // r3
  int v157; // r7
  __int16 *v158; // r10
  __int16 v159; // r8
  int v160; // r9
  unsigned __int8 *v162; // r9
  _WORD *v163; // r10
  const idBounds *v164; // r23
  int v165; // r22
  int j; // r21
  int x_high; // r24
  int v168; // r11
  __int16 v169; // r10
  int v170; // r25
  int v171; // r11
  int numExpandedObstacles; // r11
  idObstacleAvoidanceCore::expandedObstacle_t *expandedObstacles; // r10
  idObstacleAvoidanceCore::expandedObstacle_t *v174; // r30
  const idVec2 *v175; // r5
  double v176; // fp7
  int v177; // r11
  int v178; // r5
  int v179; // r26
  int k; // r29
  int v183; // r11
  idObstacleAvoidanceCore::expandedObstacle_t *v184; // r10
  idObstacleAvoidanceCore::expandedObstacle_t *v185; // r30
  int v186; // r6
  double v187; // fp7
  int v188; // r11
  idObstacleAvoidanceCore::expandedObstacle_t *v189; // r10
  idObstacleAvoidanceCore::expandedObstacle_t *v190; // r30
  int v191; // r7
  int v192; // r6
  double v193; // fp7
  int v194; // r11
  idObstacleAvoidanceCore::expandedObstacle_t *v195; // r10
  idObstacleAvoidanceCore::expandedObstacle_t *v196; // r30
  int v197; // r5
  double v198; // fp7
  int v200; // r24
  int v201; // r18
  unsigned int v202; // r11
  unsigned int v203; // r17
  double v204; // fp28
  double v205; // fp27
  double v206; // fp30
  double v207; // fp29
  int v208; // r30
  int v209; // r5
  int m; // r6
  int v211; // r11
  __int16 v212; // r7
  int v213; // r11
  __int16 v214; // r8
  float *v215; // r10
  double v216; // fp11
  float *v217; // r11
  double v218; // fp12
  double v219; // fp13
  double v220; // fp0
  double v221; // fp0
  int v222; // r11
  double v223; // fp0
  int v224; // r25
  _DWORD *v225; // r26
  char *v226; // r11
  __int16 v227; // r8
  int v228; // r9
  unsigned __int16 *v229; // r10
  int v230; // r7
  int v231; // r5
  __int16 v232; // r4
  int v233; // r11
  int v234; // r10
  const obstacleEdge_t *v235; // r30
  const obstacleEdge_t *v236; // r29
  float *v237; // r5
  double v239; // fp4
  double v240; // fp7
  float *v241; // r11
  float *v242; // r9
  double v243; // fp1
  double v244; // fp8
  double v245; // fp6
  int v246; // r11
  double v248; // fp5
  double v254; // fp9
  double v255; // fp3
  double v256; // fp2
  double v257; // fp12
  double v258; // fp0
  double v259; // fp12
  double v260; // fp0
  double v261; // fp12
  double v262; // fp11
  double v263; // fp10
  double v264; // fp1
  double v265; // fp0
  int v266; // r7
  int v268; // r9
  int v269; // r6
  idVec2 *v270; // r9
  idVec2 *winding; // r9
  idVec2 *v272; // r9
  double v273; // fp4
  double v274; // fp13
  double v275; // fp6
  idVec2 *v276; // r9
  double v277; // fp6
  int v280; // r26
  float *v281; // r27
  float *v282; // r3
  int v283; // ctr
  unsigned int v284; // r9
  int v285; // r11
  idObstacleAvoidanceCore::expandedObstacle_t *v286; // r10
  idVec2 *v287; // r8
  int v288; // r11
  float *v289; // r8
  _BYTE *v290; // r7
  double v291; // fp13
  double v292; // fp11
  double v293; // fp10
  double v294; // fp9
  double v295; // fp8
  double v296; // fp7
  double v297; // fp6
  double v298; // fp5
  double v299; // fp4
  double v300; // fp3
  double v301; // fp2
  double v302; // fp1
  double v303; // fp0
  double v304; // fp13
  idVec2 *v305; // r8
  float *v306; // r8
  float *v307; // r8
  float *v308; // r8
  float *v309; // r8
  float *v310; // r11
  float *v311; // r11
  double v312; // fp10
  double v313; // fp5
  unsigned __int8 *tempMemory; // r11
  unsigned __int8 **v315; // r10
  int v316; // r9
  int v317; // r5
  __int16 *v318; // r6
  int v319; // r5
  __int16 v320; // r10
  int v321; // r9
  int v322; // r11
  __int16 v323; // r7
  idObstacleAvoidanceCore::bspNode_t *v324; // r10
  __int16 numIndices; // r5
  int v326; // r10
  __int16 *v327; // r9
  idObstacleAvoidanceCore::bspNode_t *v328; // r11
  int v329; // r28
  int v330; // r30
  idObstacleAvoidanceCore::expandedObstacle_t *v331; // r5
  int id; // r11
  int v333; // r9
  float *v334; // r10
  avoidDebugLine_t *v335; // r8
  avoidDebugLine_t *v336; // r11
  double v337; // fp0
  double v338; // fp13
  double v339; // fp12
  signed int v340; // r11
  int v341; // r10
  int v342; // r4
  int maxDebugLines; // r7
  idVec2 *v344; // r8
  int v345; // r9
  int v346; // r23
  float *v347; // r7
  float *v348; // r8
  avoidDebugLine_t *v349; // r6
  avoidDebugLine_t *v350; // r11
  double v351; // fp0
  double v352; // fp12
  int v353; // r9
  float *v354; // r10
  avoidDebugLine_t *v355; // r8
  avoidDebugLine_t *v356; // r11
  double v357; // fp13
  double v358; // fp12
  signed int v359; // r11
  int v360; // r10
  int v361; // r4
  int v362; // r7
  idVec2 *v363; // r8
  int v364; // r9
  int v365; // r23
  float *v366; // r7
  float *v367; // r8
  avoidDebugLine_t *v368; // r6
  avoidDebugLine_t *v369; // r11
  double v370; // fp0
  double v371; // fp12
  int v372; // r9
  float *v373; // r10
  avoidDebugLine_t *v374; // r8
  avoidDebugLine_t *v375; // r11
  double v376; // fp0
  double v377; // fp12
  signed int v378; // r11
  signed int v379; // r10
  int v380; // r4
  int v381; // r7
  idVec2 *v382; // r8
  int v383; // r9
  int v384; // r23
  float *v385; // r7
  float *v386; // r8
  avoidDebugLine_t *v387; // r6
  avoidDebugLine_t *v388; // r11
  double v389; // fp0
  double v390; // fp12
  unsigned __int8 *v391; // r11
  unsigned __int8 v392; // [sp+50h] [-270h]
  int v393; // [sp+54h] [-26Ch] BYREF
  unsigned __int8 **v394; // [sp+58h] [-268h] BYREF
  idVec2 v395; // [sp+60h] [-260h] BYREF
  float v396; // [sp+68h] [-258h]
  float v397; // [sp+6Ch] [-254h]
  idVec2 v398; // [sp+70h] [-250h] BYREF
  idVec2 v399; // [sp+78h] [-248h] BYREF
  idVec2 v400; // [sp+80h] [-240h] BYREF
  int v401; // [sp+8Ch] [-234h] BYREF
  idVec2 v402; // [sp+90h] [-230h] BYREF
  _BYTE v403[108]; // [sp+9Ch] [-224h] BYREF
  int v404; // [sp+108h] [-1B8h] BYREF
  idVec3 v405; // [sp+110h] [-1B0h] BYREF
  char v406; // [sp+120h] [-1A0h] BYREF

  v43 = (char)obstacles;
  v45 = *(float *)(bounds + 4);
  v46 = *(float *)(bounds + 16);
  v49 = (float)(*(float *)bounds - (float)1.0);
  v50 = (float)(*(float *)(bounds + 12) + (float)1.0);
  v395.x = *(float *)bounds - (float)1.0;
  v395.y = (float)v45 - (float)1.0;
  v396 = v50;
  v51 = startPos;
  v397 = (float)v46 + (float)1.0;
  v53 = (float)((float)((float)((float)v50 - (float)v49) * (float)0.5) + (float)1.0);
  if ( a29 > 0 )
  {
    v54 = numObstacles + 48;
    for ( i = a29; i != 0; --i )
    {
      v56 = &this->expandedObstacles[this->numExpandedObstacles];
      v56->id = *(_DWORD *)(v54 + 12);
      v57 = idObstacleAvoidanceCore::BoxParallelProjectionSilhouetteVerts(
              axis: (const idMat3 *)(v54 - 48),
              center: (const idVec3 *)(v54 - 12),
              extents: (const idVec3 *)v54,
              projectionDir: gravity,
              silVerts: &v405);
      v58 = v57;
      v59 = 0;
      if ( v57 >= 4 )
      {
        v60 = (float *)&v401;
        v61 = (float *)&v404;
        do
        {
          v59 += 4;
          v60[1] = v61[2];
          v60[2] = v61[3];
          v62 = v61[6];
          v60[3] = v61[5];
          v63 = v61[8];
          v60[4] = v62;
          v64 = v61[9];
          v60[5] = v63;
          v65 = v61[11];
          v60[6] = v64;
          v61 += 12;
          v66 = *v61;
          v60[7] = v65;
          v60 += 8;
          *v60 = v66;
        }
        while ( v59 < v57 - 3 );
      }
      if ( v59 < v57 )
      {
        v67 = (float *)&v402 + 2 * v59 - 1;
        v68 = v57 - v59;
        v69 = (float *)((char *)&v405 + 12 * v59 - 8);
        do
        {
          v70 = v69[2];
          v69 += 3;
          v71 = *v69;
          v67[1] = v70;
          v67 += 2;
          *v67 = v71;
          --v68;
        }
        while ( v68 != 0 );
      }
      v72 = idObstacleAvoidanceCore::ExpandWindingForAxialBox(winding: &v402, numPoints: v57, bounds: &v395);
      v56->numPoints = v72;
      idObstacleAvoidanceCore::GetWindingBounds(winding: &v402, numPoints: v72, bounds: v56->bounds);
      if ( *(_BYTE *)(v54 + 16) == 0
        || ((v73 = seekPos->x) < v56->bounds[0].x
         || (v74 = seekPos->y) < v56->bounds[0].y
         || v73 > v56->bounds[1].x
         || v74 > v56->bounds[1].y)
        && (unsigned __int8)idObstacleAvoidanceCore::PointInsideWinding(
                              winding: &v402,
                              numPoints: v56->numPoints,
                              point: seekPos,
                              epsilon: 0.1) == 0 )
      {
        v75 = 0;
        windingPoints = this->windingPoints;
        numWindingPoints = this->numWindingPoints;
        ++this->numExpandedObstacles;
        this->numWindingPoints = numWindingPoints + v56->numPoints;
        numPoints = v56->numPoints;
        v56->winding = &windingPoints[numWindingPoints];
        if ( numPoints > 0 )
        {
          v79 = 0;
          do
          {
            ++v75;
            p_x = &v56->winding[v79].x;
            v81 = *(float *)((char *)&v402.y + v79 * 8);
            *p_x = *(float *)((char *)&v402.x + v79 * 8);
            ++v79;
            p_x[1] = v81;
          }
          while ( v75 < v56->numPoints );
        }
        if ( this->debugLines != nullptr )
        {
          v82 = 0;
          if ( v58 >= 4 )
          {
            v83 = 2;
            v84 = (float *)&v406;
            do
            {
              numDebugLines = this->numDebugLines;
              v86 = this->maxDebugLines - 1;
              __twllei(v58, 0);
              __twlgei(v58 & ~(__ROL4__(v83 - 1, 1) - 1), 0xFFFFFFFF);
              v87 = &v405 + (v83 - 1) % v58;
              if ( numDebugLines < v86 )
              {
                debugLines = this->debugLines;
                if ( debugLines != nullptr )
                {
                  x = v87->x;
                  y = v87->y;
                  v91 = *(v84 - 4);
                  v92 = *(v84 - 3);
                  v93 = &debugLines[numDebugLines];
                  this->numDebugLines = numDebugLines + 1;
                  v93->color = COLOR_ORANGE;
                  v93->start.x = v91;
                  v93->start.y = v92;
                  v93->start.z = 0.0;
                  v93->end.x = x;
                  v93->end.y = y;
                  v93->end.z = 0.0;
                  this->debugLines[this->numDebugLines].color = COLOR_INVALID;
                }
              }
              v94 = this->numDebugLines;
              v95 = this->maxDebugLines - 1;
              __twllei(v58, 0);
              __twlgei(v58 & ~(__ROL4__(v83, 1) - 1), 0xFFFFFFFF);
              v96 = &v405 + v83 % v58;
              if ( v94 < v95 )
              {
                v97 = this->debugLines;
                if ( v97 != nullptr )
                {
                  v98 = v96->x;
                  v99 = v96->y;
                  v100 = *(v84 - 1);
                  v101 = *v84;
                  v102 = &v97[v94];
                  this->numDebugLines = v94 + 1;
                  v102->color = COLOR_ORANGE;
                  v102->start.x = v100;
                  v102->start.y = v101;
                  v102->start.z = 0.0;
                  v102->end.x = v98;
                  v102->end.y = v99;
                  v102->end.z = 0.0;
                  this->debugLines[this->numDebugLines].color = COLOR_INVALID;
                }
              }
              v103 = this->numDebugLines;
              v104 = this->maxDebugLines - 1;
              __twllei(v58, 0);
              __twlgei(v58 & ~(__ROL4__(v83 + 1, 1) - 1), 0xFFFFFFFF);
              v105 = &v405 + (v83 + 1) % v58;
              if ( v103 < v104 )
              {
                v106 = this->debugLines;
                if ( v106 != nullptr )
                {
                  v107 = v105->x;
                  v108 = v105->y;
                  v109 = v84[2];
                  v110 = v84[3];
                  v111 = &v106[v103];
                  this->numDebugLines = v103 + 1;
                  v111->color = COLOR_ORANGE;
                  v111->start.x = v109;
                  v111->start.y = v110;
                  v111->start.z = 0.0;
                  v111->end.x = v107;
                  v111->end.y = v108;
                  v111->end.z = 0.0;
                  this->debugLines[this->numDebugLines].color = COLOR_INVALID;
                }
              }
              v112 = this->numDebugLines;
              v113 = this->maxDebugLines - 1;
              __twllei(v58, 0);
              __twlgei(v58 & ~(__ROL4__(v83 + 2, 1) - 1), 0xFFFFFFFF);
              v114 = &v405 + (v83 + 2) % v58;
              if ( v112 < v113 )
              {
                v115 = this->debugLines;
                if ( v115 != nullptr )
                {
                  v116 = v114->x;
                  v117 = v114->y;
                  v118 = v84[5];
                  v119 = v84[6];
                  v120 = &v115[v112];
                  this->numDebugLines = v112 + 1;
                  v120->color = COLOR_ORANGE;
                  v120->start.x = v118;
                  v120->start.y = v119;
                  v120->start.z = 0.0;
                  v120->end.x = v116;
                  v120->end.y = v117;
                  v120->end.z = 0.0;
                  this->debugLines[this->numDebugLines].color = COLOR_INVALID;
                }
              }
              v82 += 4;
              v83 += 4;
              v84 += 12;
            }
            while ( v82 < v58 - 3 );
          }
          if ( v82 < v58 )
          {
            v121 = &v405 + v82;
            v122 = v58 - v82;
            do
            {
              ++v82;
              v123 = this->numDebugLines;
              v124 = this->maxDebugLines - 1;
              __twllei(v58, 0);
              __twlgei(v58 & ~(__ROL4__(v82, 1) - 1), 0xFFFFFFFF);
              v125 = &v405 + v82 % v58;
              if ( v123 < v124 )
              {
                v126 = this->debugLines;
                if ( v126 != nullptr )
                {
                  v127 = v125->x;
                  v128 = v125->y;
                  v129 = v121->x;
                  v130 = v121->y;
                  v131 = &v126[v123];
                  this->numDebugLines = v123 + 1;
                  v131->color = COLOR_ORANGE;
                  v131->start.x = v129;
                  v131->start.y = v130;
                  v131->start.z = 0.0;
                  v131->end.x = v127;
                  v131->end.y = v128;
                  v131->end.z = 0.0;
                  this->debugLines[this->numDebugLines].color = COLOR_INVALID;
                }
              }
              ++v121;
              --v122;
            }
            while ( v122 != 0 );
          }
        }
        v132 = this->numExpandedObstacles - 1;
        v133 = (float)((float)(v56->bounds[1].y + v56->bounds[0].y) * (float)0.5);
        v398.x = (float)(v56->bounds[1].x + v56->bounds[0].x) * (float)0.5;
        v398.y = v133;
        idObstacleAvoidanceCore::AddDebugInt(this, color: COLOR_WHITE, pos: &v398, num: v132);
      }
      v54 += 80;
    }
  }
  v392 = 1;
  if ( v43 != 0 && idObstacleAvoidanceCore::PointInsideObstacle(this, point: v51) == -1 )
  {
    v134 = (float)(seekPos->y - v51->y);
    v135 = (float)(seekPos[1].x - v51[1].x);
    v395.x = seekPos->x - v51->x;
    v395.y = v134;
    v396 = v135;
    if ( !idObstacleAvoidanceCore::GetFirstBlockingObstacle(
            this,
            start: v51,
            delta: &v395,
            skipObstacle: -1,
            blockingScale: &v398.x,
            blockingObstacle: &v393,
            blockingEdgeNum: (int *)&v394) )
    {
      if ( edges_3 == 0 )
        return 0;
      v392 = 0;
    }
  }
  p_tempMemoryEnd = &this->tempMemoryEnd;
  v394 = &this->tempMemoryEnd;
  v137 = 0;
  v138 = (2 * numObstacles_0 + 15) & 0xFFFFFFF0;
  v139 = &this->tempMemoryEnd[-v138];
  v140 = &v139[-v138];
  v141 = (const __int16 *)v139;
  v143 = (const idBounds *)&v139[-v138];
  v142 = &v139[-v138 - v138];
  this->tempMemoryEnd = v142;
  v144 = v142;
  if ( numObstacles_0 > 0 )
  {
    v145 = v140;
    v146 = numObstacles_0;
    v148 = v144 - v140;
    v147 = (char *)v141 - (char *)v140;
    do
    {
      *(_WORD *)&v145[v147] = -1;
      *(_WORD *)v145 = v137;
      *(_WORD *)&v145[v148] = v137++;
      v145 += 2;
      --v146;
    }
    while ( v146 != 0 );
  }
  v149 = numObstacles_0;
  v150 = 0;
  v393 = numObstacles_0;
  do
  {
    v151 = v150 + 1;
    v152 = v150 * v149 / 4;
    v153 = (v150 + 1) * v149 / 4;
    if ( v150 == 4 )
    {
      v152 = 0;
      v153 = v149;
    }
    v154 = v152;
    if ( v152 < v153 )
    {
      v155 = 2 * v152;
      v156 = &v144[2 * v149];
      bounds = (int)&v143->b[0].x + v155 + 2;
      do
      {
        v157 = v154 + 1;
        if ( v154 + 1 < v153 )
        {
          v158 = (__int16 *)bounds;
          while ( 1 )
          {
            v159 = *(_WORD *)((char *)&v143->b[0].x + v155);
            if ( a35[v159].vertNums[0] == a35[*(__int16 *)((char *)v158 + v144 - (unsigned __int8 *)v143)].vertNums[1] )
            {
              v162 = &v144[2 * v157];
              v163 = (_WORD *)((char *)v143 + 2 * v157);
              v141[*(__int16 *)v162] = v159;
              *(_WORD *)((char *)&v143->b[0].x + v155) = *v163;
              goto LABEL_64;
            }
            v160 = *(__int16 *)&v144[v155];
            if ( a35[v160].vertNums[1] == a35[*v158].vertNums[0] )
              break;
            ++v157;
            ++v158;
            if ( v157 >= v153 )
              goto LABEL_66;
          }
          v163 = (_WORD *)((char *)v143 + 2 * v157);
          v141[v160] = *v163;
          v162 = &v144[2 * v157];
          *(_WORD *)&v144[v155] = *(_WORD *)v162;
LABEL_64:
          if ( v157 < v153 )
          {
            v156 -= 2;
            --v153;
            --v149;
            --v154;
            bounds -= 2;
            v155 -= 2;
            *v163 = *(_WORD *)&v156[(char *)v143 - (char *)v144];
            *(_WORD *)v162 = *(_WORD *)v156;
          }
        }
LABEL_66:
        ++v154;
        bounds += 2;
        v155 += 2;
      }
      while ( v154 < v153 );
    }
    v150 = v151;
  }
  while ( v151 <= 4 );
  v393 = v149;
  if ( v149 > 0 )
  {
    v164 = v143;
    v165 = v144 - (unsigned __int8 *)v143;
    for ( j = v149; j != 0; --j )
    {
      x_high = SHIWORD(v164->b[0].x);
      if ( x_high != -1 )
      {
        v168 = SHIWORD(v164->b[0].x);
        while ( (a35[v168].flags & 0x200) != 0 )
        {
          x_high = v141[x_high];
          v168 = x_high;
          if ( x_high == -1 )
            goto LABEL_94;
        }
        v169 = v141[x_high];
        v170 = v169;
        if ( v169 == -1 )
          goto LABEL_81;
        v171 = v169;
        while ( (a35[v171].flags & 0x200) != 0 )
        {
          v170 = v141[v170];
          v171 = v170;
          if ( v170 == -1 )
            goto LABEL_81;
        }
        if ( v170 == -1 )
        {
LABEL_81:
          numExpandedObstacles = this->numExpandedObstacles;
          expandedObstacles = this->expandedObstacles;
          this->numExpandedObstacles = numExpandedObstacles + 1;
          v174 = &expandedObstacles[numExpandedObstacles];
          idObstacleAvoidanceCore::SetupWallOrLedgeWinding(
            this,
            obstacle: v174,
            lastEdgeIndex: -1,
            currentEdgeIndex: x_high,
            nextEdgeIndex: -1,
            edges: a35,
            vertices: a31);
          v175 = &v398;
          v176 = (float)((float)(v174->bounds[1].y + v174->bounds[0].y) * (float)0.5);
          v398.x = (float)(v174->bounds[0].x + v174->bounds[1].x) * (float)0.5;
          v398.y = v176;
        }
        else
        {
          v177 = v170;
          v178 = x_high;
          v179 = v170;
LABEL_83:
          for ( k = v141[v177]; k != -1; k = v141[k] )
          {
            if ( (a35[k].flags & 0x200) != 0 )
            {
              v177 = k;
              goto LABEL_83;
            }
            _R11 = &this->windingPoints[this->numWindingPoints];
            __asm { dcbt      0, r11 }
            _R9 = 128;
            __asm { dcbt      r9, r11 }
            v183 = this->numExpandedObstacles;
            v184 = this->expandedObstacles;
            this->numExpandedObstacles = v183 + 1;
            v185 = &v184[v183];
            idObstacleAvoidanceCore::SetupWallOrLedgeWinding(
              this,
              obstacle: v185,
              lastEdgeIndex: v178,
              currentEdgeIndex: v179,
              nextEdgeIndex: k,
              edges: a35,
              vertices: a31);
            v186 = this->numExpandedObstacles - 1;
            v187 = (float)((float)(v185->bounds[1].y + v185->bounds[0].y) * (float)0.5);
            v399.x = (float)(v185->bounds[0].x + v185->bounds[1].x) * (float)0.5;
            v399.y = v187;
            idObstacleAvoidanceCore::AddDebugInt(this, color: COLOR_WHITE, pos: &v399, num: v186);
            v178 = v179;
            v179 = k;
          }
          v188 = this->numExpandedObstacles;
          v189 = this->expandedObstacles;
          this->numExpandedObstacles = v188 + 1;
          v190 = &v189[v188];
          v191 = x_high;
          if ( a35[*(__int16 *)((char *)&v164->b[0].x + v165)].vertNums[1] != a35[SHIWORD(v164->b[0].x)].vertNums[0] )
            v191 = -1;
          idObstacleAvoidanceCore::SetupWallOrLedgeWinding(
            this,
            obstacle: v190,
            lastEdgeIndex: v178,
            currentEdgeIndex: v179,
            nextEdgeIndex: v191,
            edges: a35,
            vertices: a31);
          v192 = this->numExpandedObstacles - 1;
          v193 = (float)((float)(v190->bounds[1].y + v190->bounds[0].y) * (float)0.5);
          v400.x = (float)(v190->bounds[1].x + v190->bounds[0].x) * (float)0.5;
          v400.y = v193;
          idObstacleAvoidanceCore::AddDebugInt(this, color: COLOR_WHITE, pos: &v400, num: v192);
          v194 = this->numExpandedObstacles;
          v195 = this->expandedObstacles;
          this->numExpandedObstacles = v194 + 1;
          v196 = &v195[v194];
          v197 = v179;
          if ( a35[*(__int16 *)((char *)&v164->b[0].x + v165)].vertNums[1] != a35[SHIWORD(v164->b[0].x)].vertNums[0] )
            v197 = -1;
          idObstacleAvoidanceCore::SetupWallOrLedgeWinding(
            this,
            obstacle: v196,
            lastEdgeIndex: v197,
            currentEdgeIndex: x_high,
            nextEdgeIndex: v170,
            edges: a35,
            vertices: a31);
          v175 = &v395;
          v198 = (float)((float)(v196->bounds[1].y + v196->bounds[0].y) * (float)0.5);
          v395.x = (float)(v196->bounds[0].x + v196->bounds[1].x) * (float)0.5;
          v395.y = v198;
        }
        idObstacleAvoidanceCore::AddDebugInt(this, color: COLOR_WHITE, pos: v175, num: this->numExpandedObstacles - 1);
      }
LABEL_94:
      v164 = (const idBounds *)((char *)v164 + 2);
    }
    v51 = startPos;
  }
  _R23 = 16;
  v200 = 0;
  v201 = 0;
  v202 = (unsigned int)&(*p_tempMemoryEnd)[-((16 * v149 + 15) & 0xFFFFFFF0)];
  *p_tempMemoryEnd = (unsigned __int8 *)v202;
  v203 = v202;
  v204 = (float)(v51->x - (float)obstacleRadius);
  v205 = (float)(v51->x + (float)obstacleRadius);
  v206 = (float)(v51->y - (float)obstacleRadius);
  v207 = (float)(v51->y + (float)obstacleRadius);
  if ( v149 <= 0 )
    goto LABEL_134;
  v208 = v393;
  do
  {
    bounds = a35[*(__int16 *)&v144[2 * v201]].vertNums[1];
    if ( bounds == a35[*((__int16 *)&v143->b[0].x + v201)].vertNums[0] )
      goto LABEL_133;
    v209 = 0;
    v396 = 1.0e30;
    v395.x = 1.0e30;
    v395.y = NAN;
    bounds = (int)v143;
    v397 = NAN;
    do
    {
      if ( a35[*(__int16 *)(v144 - (unsigned __int8 *)v143 + bounds)].vertNums[1] != a35[*(__int16 *)bounds].vertNums[0] )
      {
        for ( m = 0; m < 2; ++m )
        {
          v211 = v209;
          if ( m == 0 )
            v211 = v201;
          v212 = *(_WORD *)&v144[2 * v211];
          v213 = v201;
          if ( m == 0 )
            v213 = v209;
          v214 = *((_WORD *)&v143->b[0].x + v213);
          v215 = &a31[a35[v212].verts[1]].position.x;
          v216 = *v215;
          v217 = &a31[a35[v214].verts[0]].position.x;
          if ( v216 >= v204 && v216 <= v205 )
          {
            v218 = v215[1];
            if ( v218 >= v206 && v218 <= v207 )
            {
              v219 = *v217;
              if ( v219 >= v204 && v219 <= v205 )
              {
                v220 = v217[1];
                if ( v220 >= v206 && v220 <= v207 )
                {
                  v221 = (float)(v217[1] - v215[1]);
                  v222 = 8 * m;
                  v223 = (float)((float)((float)((float)v219 - *v215) * (float)((float)v219 - *v215))
                               + (float)((float)v221 * (float)v221));
                  if ( v223 < *(&v395.x + 2 * m) )
                  {
                    *(float *)((char *)&v395.x + v222) = v223;
                    *(_WORD *)((char *)&v395.y + v222) = v212;
                    *(_WORD *)((char *)&v395.y + v222 + 2) = v214;
                  }
                }
              }
            }
          }
        }
      }
      ++v209;
      bounds += 2;
    }
    while ( v209 < v208 );
    v224 = 0;
    v225 = (_DWORD *)(8 * v200 + v203 - 8);
    while ( 1 )
    {
      v226 = (char *)&v395.y + v224;
      v227 = *(_WORD *)((char *)&v395.y + v224);
      if ( v227 == -1 )
        goto LABEL_129;
      v228 = 0;
      if ( v200 > 0 )
      {
        v229 = (unsigned __int16 *)(v203 + 6);
        while ( 1 )
        {
          if ( v227 == (__int16)*(v229 - 1) )
          {
            bounds = *v229;
            if ( *(unsigned __int16 *)((char *)&v395.y + v224 + 2) == bounds )
              break;
          }
          ++v228;
          v229 += 4;
          if ( v228 >= v200 )
            goto LABEL_127;
        }
        if ( v228 < v200 )
          goto LABEL_129;
      }
LABEL_127:
      v230 = *((_DWORD *)v226 - 1);
      v231 = *(_DWORD *)v226;
      v232 = *((_WORD *)v226 + 1);
      v233 = v227;
      v234 = v393;
      v225 += 2;
      *v225 = v230;
      v235 = &a35[v233];
      v236 = &a35[v232];
      v225[1] = v231;
      ++v200;
      if ( (unsigned __int8)idObstacleAvoidanceCore::LineIntersectsEdgeSequence(
                              this,
                              start: (const idVec2 *)&a31[a35[v233].verts[1]],
                              end: (const idVec2 *)&a31[v236->verts[0]],
                              vertices: a31,
                              edges: a35,
                              sequenceFirst: (const __int16 *)v143,
                              nextEdge: v141,
                              numSequences: v234) == 0 )
      {
        v239 = (float)(*(float *)bounds - *v237);
        v240 = (float)(v237[1] - *(float *)(bounds + 4));
        v241 = &a31[v235->verts[0]].position.x;
        v242 = &a31[v236->verts[1]].position.x;
        v243 = (float)(*v241 - *(float *)bounds);
        v244 = (float)(*(float *)(bounds + 4) - v241[1]);
        v245 = (float)(v242[1] - v237[1]);
        _FP9 = (float)((float)((float)((float)(*(float *)bounds - *v237) * (float)(*(float *)bounds - *v237))
                             + (float)((float)v240 * (float)v240))
                     - idMath::FLT_SMALLEST_NON_DENORMAL);
        v248 = (float)((float)((float)((float)(*(float *)bounds - *v237) * (float)(*(float *)bounds - *v237))
                             + (float)((float)v240 * (float)v240))
                     * (float)0.5);
        _FP3 = (float)((float)((float)((float)v244 * (float)v244)
                             + (float)((float)(*v241 - *(float *)bounds) * (float)(*v241 - *(float *)bounds)))
                     - idMath::FLT_SMALLEST_NON_DENORMAL);
        _FP2 = (float)((float)((float)((float)v245 * (float)v245)
                             + (float)((float)(*v237 - *v242) * (float)(*v237 - *v242)))
                     - idMath::FLT_SMALLEST_NON_DENORMAL);
        __asm
        {
          fsel      f12, f9, f12, f0
          fsel      f11, f3, f11, f0
          fsel      f10, f2, f10, f0
        }
        v254 = __frsqrte(_FP12);
        v255 = __frsqrte(_FP11);
        v256 = __frsqrte(_FP10);
        v257 = (float)((float)-(float)((float)((float)((float)v256
                                                     * (float)((float)((float)((float)v245 * (float)v245)
                                                                     + (float)((float)(*v237 - *v242)
                                                                             * (float)(*v237 - *v242)))
                                                             * (float)0.5))
                                             * (float)v256)
                                     - (float)1.5)
                     * (float)v256);
        v258 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v255
                                                                                             * (float)((float)((float)((float)v244 * (float)v244) + (float)((float)v243 * (float)v243)) * (float)0.5))
                                                                                     * (float)v255)
                                                                             - (float)1.5)
                                                             * (float)v255)
                                                     * (float)((float)((float)((float)v244 * (float)v244)
                                                                     + (float)((float)v243 * (float)v243))
                                                             * (float)0.5))
                                             * (float)((float)-(float)((float)((float)((float)v255
                                                                                     * (float)((float)((float)((float)v244 * (float)v244) + (float)((float)v243 * (float)v243))
                                                                                             * (float)0.5))
                                                                             * (float)v255)
                                                                     - (float)1.5)
                                                     * (float)v255))
                                     - (float)1.5)
                     * (float)((float)-(float)((float)((float)((float)v255
                                                             * (float)((float)((float)((float)v244 * (float)v244)
                                                                             + (float)((float)v243 * (float)v243))
                                                                     * (float)0.5))
                                                     * (float)v255)
                                             - (float)1.5)
                             * (float)v255));
        v259 = (float)((float)-(float)((float)((float)((float)v257
                                                     * (float)((float)((float)((float)v245 * (float)v245)
                                                                     + (float)((float)(*v237 - *v242)
                                                                             * (float)(*v237 - *v242)))
                                                             * (float)0.5))
                                             * (float)v257)
                                     - (float)1.5)
                     * (float)v257);
        v260 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v255 * (float)((float)((float)((float)v244 * (float)v244) + (float)((float)v243 * (float)v243)) * (float)0.5)) * (float)v255) - (float)1.5) * (float)v255)
                                                                                             * (float)((float)((float)((float)v244 * (float)v244) + (float)((float)v243 * (float)v243)) * (float)0.5))
                                                                                     * (float)((float)-(float)((float)((float)((float)v255 * (float)((float)((float)((float)v244 * (float)v244) + (float)((float)v243 * (float)v243)) * (float)0.5)) * (float)v255) - (float)1.5)
                                                                                             * (float)v255))
                                                                             - (float)1.5)
                                                             * (float)((float)-(float)((float)((float)((float)v255 * (float)((float)((float)((float)v244 * (float)v244) + (float)((float)v243 * (float)v243)) * (float)0.5))
                                                                                             * (float)v255)
                                                                                     - (float)1.5)
                                                                     * (float)v255))
                                                     * (float)((float)((float)((float)v244 * (float)v244)
                                                                     + (float)((float)v243 * (float)v243))
                                                             * (float)0.5))
                                             * (float)v258)
                                     - (float)1.5)
                     * (float)v258);
        v261 = (float)((float)-(float)((float)((float)((float)v259
                                                     * (float)((float)((float)((float)v245 * (float)v245)
                                                                     + (float)((float)(*v237 - *v242)
                                                                             * (float)(*v237 - *v242)))
                                                             * (float)0.5))
                                             * (float)v259)
                                     - (float)1.5)
                     * (float)v259);
        v262 = (float)((float)v260 * (float)(*(float *)(bounds + 4) - v241[1]));
        v263 = (float)((float)v260 * (float)(*v241 - *(float *)bounds));
        v246 = this->numExpandedObstacles;
        v264 = (float)((float)((float)v261 * (float)(v242[1] - v237[1])) * (float)v53);
        v265 = (float)((float)((float)v261 * (float)(*v237 - *v242)) * (float)v53);
        v266 = v246 + 1;
        _R11 = &this->expandedObstacles[v246];
        this->numExpandedObstacles = v266;
        _R11->id = -4;
        _R11->numPoints = 4;
        v268 = this->numWindingPoints;
        v269 = v268 + 4;
        v270 = &this->windingPoints[v268];
        this->numWindingPoints = v269;
        _R11->winding = v270;
        v270->x = *v237;
        v270->y = v237[1];
        winding = _R11->winding;
        winding[1].x = *(float *)bounds;
        winding[1].y = *(float *)(bounds + 4);
        v272 = _R11->winding;
        v273 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v254 * (float)v248) * (float)v254) - (float)1.5) * (float)v254) * (float)v248)
                                                                                             * (float)((float)-(float)((float)((float)((float)v254 * (float)v248) * (float)v254) - (float)1.5) * (float)v254))
                                                                                     - (float)1.5)
                                                                     * (float)((float)-(float)((float)((float)((float)v254 * (float)v248) * (float)v254)
                                                                                             - (float)1.5)
                                                                             * (float)v254))
                                                             * (float)v248)
                                                     * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v254 * (float)v248) * (float)v254) - (float)1.5) * (float)v254)
                                                                                             * (float)v248)
                                                                                     * (float)((float)-(float)((float)((float)((float)v254 * (float)v248) * (float)v254) - (float)1.5)
                                                                                             * (float)v254))
                                                                             - (float)1.5)
                                                             * (float)((float)-(float)((float)((float)((float)v254 * (float)v248)
                                                                                             * (float)v254)
                                                                                     - (float)1.5)
                                                                     * (float)v254)))
                                             - (float)1.5)
                             * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v254 * (float)v248) * (float)v254)
                                                                                             - (float)1.5)
                                                                             * (float)v254)
                                                                     * (float)v248)
                                                             * (float)((float)-(float)((float)((float)((float)v254 * (float)v248)
                                                                                             * (float)v254)
                                                                                     - (float)1.5)
                                                                     * (float)v254))
                                                     - (float)1.5)
                                     * (float)((float)-(float)((float)((float)((float)v254 * (float)v248) * (float)v254)
                                                             - (float)1.5)
                                             * (float)v254)))
                     * (float)v239);
        v274 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v254 * (float)v248) * (float)v254) - (float)1.5) * (float)v254) * (float)v248)
                                                                                             * (float)((float)-(float)((float)((float)((float)v254 * (float)v248) * (float)v254) - (float)1.5) * (float)v254))
                                                                                     - (float)1.5)
                                                                     * (float)((float)-(float)((float)((float)((float)v254 * (float)v248) * (float)v254)
                                                                                             - (float)1.5)
                                                                             * (float)v254))
                                                             * (float)v248)
                                                     * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v254 * (float)v248) * (float)v254) - (float)1.5) * (float)v254)
                                                                                             * (float)v248)
                                                                                     * (float)((float)-(float)((float)((float)((float)v254 * (float)v248) * (float)v254) - (float)1.5)
                                                                                             * (float)v254))
                                                                             - (float)1.5)
                                                             * (float)((float)-(float)((float)((float)((float)v254 * (float)v248)
                                                                                             * (float)v254)
                                                                                     - (float)1.5)
                                                                     * (float)v254)))
                                             - (float)1.5)
                             * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v254 * (float)v248) * (float)v254)
                                                                                             - (float)1.5)
                                                                             * (float)v254)
                                                                     * (float)v248)
                                                             * (float)((float)-(float)((float)((float)((float)v254 * (float)v248)
                                                                                             * (float)v254)
                                                                                     - (float)1.5)
                                                                     * (float)v254))
                                                     - (float)1.5)
                                     * (float)((float)-(float)((float)((float)((float)v254 * (float)v248) * (float)v254)
                                                             - (float)1.5)
                                             * (float)v254)))
                     * (float)v240);
        v275 = (float)((float)(*(float *)(bounds + 4) - (float)v274) - (float)((float)v273 * (float)v53));
        v272[2].x = (float)((float)(*(float *)bounds - (float)-v273) - (float)((float)v274 * (float)v53))
                  - (float)((float)v262 * (float)v53);
        v272[2].y = (float)v275 - (float)((float)v263 * (float)v53);
        v276 = _R11->winding;
        v277 = (float)((float)(v237[1] + (float)v274) - (float)((float)v273 * (float)v53));
        v276[3].x = (float)((float)((float)-v273 + *v237) - (float)((float)v274 * (float)v53)) - (float)v264;
        v276[3].y = (float)v277 - (float)v265;
        _R9 = _R11->winding;
        __asm
        {
          lvrx128   v61, r23, r9
          lvlx128   v60, r0, r9
        }
        _R8 = _R9 + 2;
        __asm
        {
          lvlx128   v63, r0, r8
          vor128    v59, v92, v61
          lvrx128   v62, r23, r8
          vor128    v58, v95, v62
          vminfp128 v57, v91, v58
          vmaxfp128 v56, v91, v58
          vpermwi128 v55, v57, 0xB1
          vpermwi128 v54, v56, 0xB1
          vminfp128 v53, v89, v55
          vmaxfp128 v52, v88, v54
          vsldoi128 v51, v85, v52, 8
          stvlx128  v51, r0, r11
          stvrx128  v51, r11, r23
        }
        bounds = this->numExpandedObstacles;
        if ( bounds >= this->maxExpandedObstacles )
          break;
      }
LABEL_129:
      v224 += 8;
      if ( v224 >= 16 )
        goto LABEL_132;
    }
    v201 = v393;
LABEL_132:
    v208 = v393;
LABEL_133:
    ++v201;
  }
  while ( v201 < v208 );
LABEL_134:
  v280 = 0;
  if ( numVerticesa > 0 )
  {
    v281 = &verticesa[1].position.x;
    do
    {
      if ( this->numExpandedObstacles >= this->maxExpandedObstacles )
        break;
      idObstacleAvoidanceCore::GetCirclePoints(
        center: (const idVec2 *)(v281 - 3),
        radius: *v281,
        circlePoints: (idVec2 *)bounds,
        a4: &v402.x);
      v283 = 2;
      bounds = 32 - (_DWORD)v403;
      v284 = 0;
      v285 = this->numExpandedObstacles;
      v286 = &this->expandedObstacles[v285];
      this->numExpandedObstacles = v285 + 1;
      v286->numPoints = 16;
      v287 = this->windingPoints;
      v288 = this->numWindingPoints;
      this->numWindingPoints = v288 + 16;
      v286->winding = &v287[v288];
      do
      {
        v289 = &v286->winding[v284 / 8].x;
        v290 = &v403[v284 + 56 - (_DWORD)v403];
        v291 = *(float *)&v403[v284 - 8];
        *v289 = *(float *)&v403[v284 - 12];
        v289[1] = v291;
        v292 = *(float *)&v403[v284];
        v293 = *(float *)&v403[v284 + 4];
        v294 = *(float *)&v403[v284 + 8];
        v295 = *(float *)&v403[v284 + 12];
        v296 = *(float *)&v403[v284 + 16];
        v297 = *(float *)&v403[v284 + 20];
        v298 = *(float *)&v403[v284 + 24];
        v299 = *(float *)&v403[v284 + 28];
        v300 = *(float *)&v403[v284 + 32];
        v301 = *(float *)&v403[v284 + 36];
        v302 = *(float *)&v403[v284 + 40];
        v303 = *(float *)&v403[v284 + 44];
        v304 = *(float *)&v403[v284 + 48];
        v305 = &v286->winding[v284 / 8];
        v305[1].x = *(float *)&v403[v284 - 4];
        v305[1].y = v292;
        v306 = (float *)&v403[v284 + (unsigned int)v286->winding + 16 - (_DWORD)v403];
        *v306 = v293;
        v306[1] = v294;
        v307 = (float *)&v403[v284 + (unsigned int)v286->winding + 24 - (_DWORD)v403];
        *v307 = v295;
        v307[1] = v296;
        v308 = (float *)&v403[v284 + (unsigned int)v286->winding + bounds];
        *v308 = v297;
        v308[1] = v298;
        v309 = (float *)&v403[v284 + (unsigned int)v286->winding + 40 - (_DWORD)v403];
        *v309 = v299;
        v309[1] = v300;
        v310 = (float *)&v403[v284 + (unsigned int)v286->winding + 48 - (_DWORD)v403];
        v284 += 64;
        *v310 = v301;
        v310[1] = v302;
        v311 = (float *)&v290[(unsigned int)v286->winding];
        *v311 = v303;
        v311[1] = v304;
        --v283;
      }
      while ( v283 != 0 );
      ++v280;
      v312 = (float)(*v282 - *v281);
      v286->bounds[0].y = v282[1] - *v281;
      v286->bounds[0].x = v312;
      v313 = (float)(*v281 + v282[1]);
      v286->bounds[1].x = *v281 + *v282;
      v286->bounds[1].y = v313;
      v281 += 4;
      v286->id = -5;
    }
    while ( v280 < numVerticesa );
  }
  v395.x = obstacleRadius;
  v395.y = obstacleRadius;
  idObstacleAvoidanceCore::SetupBspTree_r(this, center: startPos, span: &v395, axis: 0, depth: 0);
  tempMemory = this->tempMemory;
  v315 = v394;
  if ( tempMemory != nullptr )
    *v394 = &tempMemory[this->tempMemorySize];
  v316 = this->numExpandedObstacles;
  v317 = 0;
  v318 = (__int16 *)&(*v315)[-((2 * v316 + 15) & 0xFFFFFFF0)];
  *v315 = (unsigned __int8 *)v318;
  if ( v316 > 0 )
  {
    do
    {
      idObstacleAvoidanceCore::FilterObstacleIntoBspTree(this, nodeNum: 0, obstacleNum: v317, obstacleNodes: v318);
      v317 = v319 + 1;
    }
    while ( v317 < this->numExpandedObstacles );
  }
  v320 = 0;
  v321 = 0;
  if ( this->numBspNodes > 0 )
  {
    v322 = 0;
    do
    {
      v323 = v320;
      ++v321;
      this->bspNodes[v322].indexOffset = v320;
      v324 = &this->bspNodes[v322++];
      numIndices = v324->numIndices;
      v324->numIndices = 0;
      v320 = v323 + numIndices;
    }
    while ( v321 < this->numBspNodes );
  }
  v326 = 0;
  if ( this->numExpandedObstacles > 0 )
  {
    v327 = v318 - 1;
    do
    {
      v328 = &this->bspNodes[*++v327];
      this->obstacleIndices[v328->indexOffset + v328->numIndices++] = v326++;
    }
    while ( v326 < this->numExpandedObstacles );
  }
  if ( this->debugLines != nullptr )
  {
    v329 = 0;
    if ( this->numExpandedObstacles > 0 )
    {
      v330 = 0;
      do
      {
        v331 = &this->expandedObstacles[v330];
        id = v331->id;
        switch ( id )
        {
          case -2:
            v333 = this->numDebugLines;
            v334 = &v331->winding->x;
            if ( v333 < this->maxDebugLines - 1 )
            {
              v335 = this->debugLines;
              if ( v335 != nullptr )
              {
                v336 = &v335[v333];
                this->numDebugLines = v333 + 1;
                v336->color = COLOR_WHITE;
                v337 = *v334;
                v338 = v334[1];
                v336->start.z = 0.0;
                v336->start.y = v338;
                v336->start.x = v337;
                v339 = v334[2];
                v336->end.y = v334[3];
                v336->end.x = v339;
                v336->end.z = 0.0;
                this->debugLines[this->numDebugLines].color = COLOR_INVALID;
              }
            }
            v340 = v331->numPoints;
            v341 = 1;
            if ( v340 > 1 )
            {
              v342 = 1;
              do
              {
                ++v341;
                maxDebugLines = this->maxDebugLines;
                __twllei(v340, 0);
                v344 = v331->winding;
                v345 = this->numDebugLines;
                v346 = maxDebugLines - 1;
                v347 = &v344[v341 % v340].x;
                __twlgei(v340 & ~(__ROL4__(v341, 1) - 1), 0xFFFFFFFF);
                v348 = &v344[v342].x;
                if ( v345 < v346 )
                {
                  v349 = this->debugLines;
                  if ( v349 != nullptr )
                  {
                    v350 = &v349[v345];
                    this->numDebugLines = v345 + 1;
                    v350->color = COLOR_GRAY;
                    v351 = v348[1];
                    v350->start.x = *v348;
                    v350->start.y = v351;
                    v350->start.z = 0.0;
                    v352 = v347[1];
                    v350->end.x = *v347;
                    v350->end.y = v352;
                    v350->end.z = 0.0;
                    this->debugLines[this->numDebugLines].color = COLOR_INVALID;
                  }
                }
                v340 = v331->numPoints;
                ++v342;
              }
              while ( v341 < v340 );
            }
            break;
          case -3:
            v353 = this->numDebugLines;
            v354 = &v331->winding->x;
            if ( v353 < this->maxDebugLines - 1 )
            {
              v355 = this->debugLines;
              if ( v355 != nullptr )
              {
                v356 = &v355[v353];
                this->numDebugLines = v353 + 1;
                v356->color = COLOR_ORANGE;
                v357 = v354[1];
                v356->start.x = *v354;
                v356->start.y = v357;
                v356->start.z = 0.0;
                v358 = v354[3];
                v356->end.x = v354[2];
                v356->end.y = v358;
                v356->end.z = 0.0;
                this->debugLines[this->numDebugLines].color = COLOR_INVALID;
              }
            }
            v359 = v331->numPoints;
            v360 = 1;
            if ( v359 > 1 )
            {
              v361 = 1;
              do
              {
                ++v360;
                v362 = this->maxDebugLines;
                __twllei(v359, 0);
                v363 = v331->winding;
                v364 = this->numDebugLines;
                v365 = v362 - 1;
                v366 = &v363[v360 % v359].x;
                __twlgei(v359 & ~(__ROL4__(v360, 1) - 1), 0xFFFFFFFF);
                v367 = &v363[v361].x;
                if ( v364 < v365 )
                {
                  v368 = this->debugLines;
                  if ( v368 != nullptr )
                  {
                    v369 = &v368[v364];
                    this->numDebugLines = v364 + 1;
                    v369->color = COLOR_ORANGE;
                    v370 = v367[1];
                    v369->start.x = *v367;
                    v369->start.y = v370;
                    v369->start.z = 0.0;
                    v371 = v366[1];
                    v369->end.x = *v366;
                    v369->end.y = v371;
                    v369->end.z = 0.0;
                    this->debugLines[this->numDebugLines].color = COLOR_INVALID;
                  }
                }
                v359 = v331->numPoints;
                ++v361;
              }
              while ( v360 < v359 );
            }
            break;
          case -4:
            v372 = this->numDebugLines;
            v373 = &v331->winding->x;
            if ( v372 < this->maxDebugLines - 1 )
            {
              v374 = this->debugLines;
              if ( v374 != nullptr )
              {
                v375 = &v374[v372];
                this->numDebugLines = v372 + 1;
                v375->color = COLOR_RED;
                v376 = v373[1];
                v375->start.x = *v373;
                v375->start.y = v376;
                v375->start.z = 0.0;
                v377 = v373[3];
                v375->end.x = v373[2];
                v375->end.y = v377;
                v375->end.z = 0.0;
                this->debugLines[this->numDebugLines].color = COLOR_INVALID;
              }
            }
            break;
          default:
            v378 = v331->numPoints;
            v379 = 0;
            if ( v378 > 0 )
            {
              v380 = 0;
              do
              {
                ++v379;
                v381 = this->maxDebugLines;
                __twllei(v378, 0);
                v382 = v331->winding;
                v383 = this->numDebugLines;
                v384 = v381 - 1;
                v385 = &v382[v379 % v378].x;
                __twlgei(v378 & ~(__ROL4__(v379, 1) - 1), 0xFFFFFFFF);
                v386 = &v382[v380].x;
                if ( v383 < v384 )
                {
                  v387 = this->debugLines;
                  if ( v387 != nullptr )
                  {
                    v388 = &v387[v383];
                    this->numDebugLines = v383 + 1;
                    v388->color = COLOR_GREEN;
                    v389 = v386[1];
                    v388->start.x = *v386;
                    v388->start.y = v389;
                    v388->start.z = 0.0;
                    v390 = v385[1];
                    v388->end.x = *v385;
                    v388->end.y = v390;
                    v388->end.z = 0.0;
                    this->debugLines[this->numDebugLines].color = COLOR_INVALID;
                  }
                }
                v378 = v331->numPoints;
                ++v380;
              }
              while ( v379 < v378 );
            }
            break;
        }
        ++v329;
        ++v330;
      }
      while ( v329 < this->numExpandedObstacles );
    }
  }
  v391 = this->tempMemory;
  if ( v391 != nullptr )
    *v394 = &v391[this->tempMemorySize];
  return v392;
}


// ========================================================================
// ?OptimizePath@idObstacleAvoidanceCore@@ABAMPBUpathNode_t@1@0ABVidVec2@@1QAVidVec3@@AAH@Z
// EA  : 0x826C4400
// RVA : 0x006C4400
// PDB : w:\tech5\engine\gamelib\aas2\obstacleavoidancecore.cpp
// ========================================================================

float __fastcall idObstacleAvoidanceCore::OptimizePath(
        idObstacleAvoidanceCore *this,
        const idObstacleAvoidanceCore::pathNode_t *root,
        const idObstacleAvoidanceCore::pathNode_t *leafNode,
        const idVec2 *originalSeekPos,
        const idVec2 *lastDir,
        idVec3 *seekPos,
        int *outNumSeekPos)
{
  double v14; // fp7
  double v15; // fp1
  int v16; // r26
  const idObstacleAvoidanceCore::pathNode_t *v17; // r30
  idVec3 *v18; // r23
  double v19; // fp31
  const idObstacleAvoidanceCore::pathNode_t *i; // r31
  int obstacle; // r6
  double v22; // fp12
  double v23; // fp9
  bool v24; // cr56

  if ( leafNode == root )
  {
    seekPos->x = root->pos.x;
    seekPos->y = root->pos.y;
    v14 = (float)(root->delta.y + root->pos.y);
    seekPos[1].x = root->delta.x + root->pos.x;
    seekPos[1].y = v14;
    v15 = __fsqrts((float)((float)(root->delta.y * root->delta.y) + (float)(root->delta.x * root->delta.x)));
  }
  else
  {
    seekPos->x = originalSeekPos->x;
    v16 = 0;
    v17 = root;
    v18 = seekPos;
    v19 = 0.0;
    seekPos->y = originalSeekPos->y;
    seekPos[1].x = originalSeekPos->x;
    seekPos[1].y = originalSeekPos->y;
    do
    {
      for ( i = leafNode; i->parent != v17; i = i->parent )
      {
        obstacle = i->obstacle;
        if ( obstacle != v17->obstacle
          && (unsigned __int8)idObstacleAvoidanceCore::LineIntersectsObstacle(
                                this,
                                start: &v17->pos,
                                end: &i->pos,
                                endObstacle: obstacle,
                                ignoreObstacle: -1) == 0 )
        {
          break;
        }
      }
      v22 = (float)(i->pos.x - v17->pos.x);
      v23 = (float)(i->pos.y - v17->pos.y);
      v19 = (float)((float)__fsqrts((float)((float)((float)v23 * (float)v23) + (float)((float)v22 * (float)v22)))
                  + (float)v19);
      if ( v16 < 31 )
      {
        ++v16;
        v18->x = i->pos.x;
        v18->y = i->pos.y;
        ++v18;
      }
      v17 = i;
    }
    while ( i != leafNode );
    *outNumSeekPos = v16;
    if ( ((LODWORD(lastDir->x) | LODWORD(lastDir->y)) & 0x7FFFFFFF) != 0 )
      v24 = (float)((float)(lastDir->x * (float)(seekPos->x - root->pos.x))
                  + (float)((float)(seekPos->y - root->pos.y) * lastDir->y)) < 0.0;
    else
      v24 = (float)((float)((float)(seekPos->y - root->pos.y) * (float)(originalSeekPos->y - root->pos.y))
                  + (float)((float)(seekPos->x - root->pos.x) * (float)(originalSeekPos->x - root->pos.x))) < 0.0;
    if ( v24 )
      v19 = (float)((float)v19 + (float)100.0);
    v15 = v19;
  }
  return *((float *)&v15 + 1);
}


// ========================================================================
// ?FindOptimalPath@idObstacleAvoidanceCore@@AAAXPBUpathNode_t@1@ABVidVec2@@1QAVidVec3@@AAHAAM4@Z
// EA  : 0x826C4600
// RVA : 0x006C4600
// PDB : w:\tech5\engine\gamelib\aas2\obstacleavoidancecore.cpp
// ========================================================================

void __fastcall idObstacleAvoidanceCore::FindOptimalPath(
        idObstacleAvoidanceCore *this,
        const idObstacleAvoidanceCore::pathNode_t *root,
        const idVec2 *originalSeekPos,
        const idVec2 *lastDir,
        idVec3 *seekPos,
        int *outNumSeekPos,
        float *targetDist,
        float *pathLength)
{
  const idObstacleAvoidanceCore::pathNode_t *v16; // r25
  const idObstacleAvoidanceCore::pathNode_t *v17; // r11
  const idObstacleAvoidanceCore::pathNode_t *v18; // r9
  idObstacleAvoidanceCore::pathNode_t *parent; // r11
  const idObstacleAvoidanceCore::pathNode_t *v20; // r10
  double targetDistSqr; // fp29
  double v22; // fp1
  int v23; // r26
  double v24; // fp31
  const idObstacleAvoidanceCore::pathNode_t *v25; // r30
  double v26; // fp1
  idObstacleAvoidanceCore::pathNode_t *v27; // r11
  const idObstacleAvoidanceCore::pathNode_t *v28; // r9
  const idObstacleAvoidanceCore::pathNode_t *v29; // r10
  avoidDebugLine_t *debugLines; // r9
  int numDebugLines; // r10
  avoidDebugLine_t *v32; // r11
  double y; // fp0
  double v34; // fp12
  int v35; // r10
  idVec3 *v36; // r8
  avoidDebugLine_t *v37; // r9
  avoidDebugLine_t *v38; // r11
  double v39; // fp0
  double v40; // fp12
  int v41; // r10
  double v42; // fp13
  double v43; // fp12
  double v44; // fp11
  avoidDebugLine_t *v45; // r9
  avoidDebugLine_t *v46; // r11
  int v47; // r10
  double v48; // fp12
  double x; // fp13
  double v50; // fp11
  avoidDebugLine_t *v51; // r9
  avoidDebugLine_t *v52; // r11
  int v53; // r10
  double v54; // fp12
  double v55; // fp13
  double v56; // fp11
  avoidDebugLine_t *v57; // r9
  avoidDebugLine_t *v58; // r11
  int v59; // r10
  double v60; // fp12
  double v61; // fp13
  double v62; // fp0
  avoidDebugLine_t *v63; // r9
  avoidDebugLine_t *v64; // r11
  int v65[4]; // [sp+50h] [-210h] BYREF
  idVec3 v66[34]; // [sp+60h] [-200h] BYREF

  v16 = root;
  v17 = root;
  if ( root == nullptr )
    goto LABEL_17;
  do
  {
    if ( v17->targetDistSqr < (double)v16->targetDistSqr )
      v16 = v17;
    if ( v17->children[0] != nullptr )
    {
      v17 = v17->children[0];
    }
    else if ( v17->children[1] != nullptr )
    {
      v17 = v17->children[1];
    }
    else
    {
      v18 = v17;
      parent = v17->parent;
      if ( parent == nullptr )
        break;
      while ( 1 )
      {
        v20 = parent->children[1];
        if ( v20 != nullptr && v20 != v18 )
          break;
        v18 = parent;
        parent = parent->parent;
        if ( parent == nullptr )
          goto LABEL_15;
      }
      v17 = parent->children[1];
    }
  }
  while ( v17 != nullptr );
LABEL_15:
  if ( v16 == root )
LABEL_17:
    targetDistSqr = 0.0;
  else
    targetDistSqr = v16->targetDistSqr;
  v65[0] = 2;
  v22 = idObstacleAvoidanceCore::OptimizePath(
          this,
          root,
          leafNode: v16,
          originalSeekPos,
          lastDir,
          seekPos,
          outNumSeekPos: v65);
  v23 = v65[0];
  v24 = v22;
  v25 = root;
  while ( v25 != nullptr )
  {
    if ( v25->targetDistSqr < (double)(float)((float)targetDistSqr + (float)1.0) && v25 != v16 )
    {
      memcpy(Dst: v66, Src: seekPos, Size: 0x174u);
      v65[0] = 0;
      v26 = idObstacleAvoidanceCore::OptimizePath(
              this,
              root,
              leafNode: v25,
              originalSeekPos,
              lastDir,
              seekPos: v66,
              outNumSeekPos: v65);
      if ( v26 < v24 )
      {
        v24 = v26;
        v16 = v25;
        memcpy(Dst: seekPos, Src: v66, Size: 0x174u);
        v23 = v65[0];
      }
    }
    if ( v25->children[0] != nullptr )
    {
      v25 = v25->children[0];
    }
    else if ( v25->children[1] != nullptr )
    {
      v25 = v25->children[1];
    }
    else
    {
      v27 = v25->parent;
      v28 = v25;
      if ( v27 == nullptr )
        break;
      while ( 1 )
      {
        v29 = v27->children[1];
        if ( v29 != nullptr && v29 != v28 )
          break;
        v28 = v27;
        v27 = v27->parent;
        if ( v27 == nullptr )
          goto LABEL_34;
      }
      v25 = v27->children[1];
    }
  }
LABEL_34:
  *targetDist = __fsqrts(targetDistSqr);
  *pathLength = v24;
  *outNumSeekPos = v23;
  debugLines = this->debugLines;
  if ( debugLines != nullptr )
  {
    if ( root != nullptr )
    {
      numDebugLines = this->numDebugLines;
      if ( numDebugLines < this->maxDebugLines - 1 )
      {
        v32 = &debugLines[numDebugLines];
        this->numDebugLines = numDebugLines + 1;
        v32->color = COLOR_GREEN;
        y = root->pos.y;
        v32->start.x = root->pos.x;
        v32->start.y = y;
        v32->start.z = 0.0;
        v34 = seekPos->y;
        v32->end.x = seekPos->x;
        v32->end.y = v34;
        v32->end.z = 0.0;
        this->debugLines[this->numDebugLines].color = COLOR_INVALID;
      }
    }
    v35 = this->numDebugLines;
    v36 = seekPos + 1;
    if ( v35 < this->maxDebugLines - 1 )
    {
      v37 = this->debugLines;
      if ( v37 != nullptr )
      {
        v38 = &v37[v35];
        this->numDebugLines = v35 + 1;
        v38->color = COLOR_YELLOW;
        v39 = seekPos->y;
        v38->start.x = seekPos->x;
        v38->start.y = v39;
        v38->start.z = 0.0;
        v40 = seekPos[1].y;
        v38->end.x = v36->x;
        v38->end.y = v40;
        v38->end.z = 0.0;
        this->debugLines[this->numDebugLines].color = COLOR_INVALID;
      }
    }
    v41 = this->numDebugLines;
    v42 = seekPos->y;
    v43 = (float)(seekPos->x + (float)16.0);
    v44 = (float)(seekPos->x - (float)16.0);
    if ( v41 < this->maxDebugLines - 1 )
    {
      v45 = this->debugLines;
      if ( v45 != nullptr )
      {
        v46 = &v45[v41];
        this->numDebugLines = v41 + 1;
        v46->color = COLOR_GREEN;
        v46->start.x = v44;
        v46->start.y = v42;
        v46->start.z = 0.0;
        v46->end.z = 0.0;
        v46->end.x = v43;
        v46->end.y = v42;
        this->debugLines[this->numDebugLines].color = COLOR_INVALID;
      }
    }
    v47 = this->numDebugLines;
    v48 = (float)(seekPos->y + (float)16.0);
    x = seekPos->x;
    v50 = (float)(seekPos->y - (float)16.0);
    if ( v47 < this->maxDebugLines - 1 )
    {
      v51 = this->debugLines;
      if ( v51 != nullptr )
      {
        v52 = &v51[v47];
        this->numDebugLines = v47 + 1;
        v52->color = COLOR_GREEN;
        v52->start.x = x;
        v52->start.y = v50;
        v52->start.z = 0.0;
        v52->end.x = x;
        v52->end.y = v48;
        v52->end.z = 0.0;
        this->debugLines[this->numDebugLines].color = COLOR_INVALID;
      }
    }
    v53 = this->numDebugLines;
    v54 = (float)(v36->x + (float)16.0);
    v55 = seekPos[1].y;
    v56 = (float)(v36->x - (float)16.0);
    if ( v53 < this->maxDebugLines - 1 )
    {
      v57 = this->debugLines;
      if ( v57 != nullptr )
      {
        v58 = &v57[v53];
        this->numDebugLines = v53 + 1;
        v58->color = COLOR_YELLOW;
        v58->start.x = v56;
        v58->start.y = v55;
        v58->start.z = 0.0;
        v58->end.x = v54;
        v58->end.y = v55;
        v58->end.z = 0.0;
        this->debugLines[this->numDebugLines].color = COLOR_INVALID;
      }
    }
    v59 = this->numDebugLines;
    v60 = (float)(seekPos[1].y + (float)16.0);
    v61 = v36->x;
    v62 = (float)(seekPos[1].y - (float)16.0);
    if ( v59 < this->maxDebugLines - 1 )
    {
      v63 = this->debugLines;
      if ( v63 != nullptr )
      {
        v64 = &v63[v59];
        this->numDebugLines = v59 + 1;
        v64->color = COLOR_YELLOW;
        v64->start.x = v61;
        v64->start.y = v62;
        v64->start.z = 0.0;
        v64->end.x = v61;
        v64->end.y = v60;
        v64->end.z = 0.0;
        this->debugLines[this->numDebugLines].color = COLOR_INVALID;
      }
    }
  }
}


// ========================================================================
// ?SubSamplePath@idObstacleAvoidanceCore@@AAAXABVidVec3@@00AAV2@@Z
// EA  : 0x826C4AC8
// RVA : 0x006C4AC8
// PDB : w:\tech5\engine\gamelib\aas2\obstacleavoidancecore.cpp
// ========================================================================

void __fastcall idObstacleAvoidanceCore::SubSamplePath(
        idObstacleAvoidanceCore *this,
        const idVec2 *startPos,
        const idVec3 *pathStart,
        const idVec3 *pathEnd,
        idVec3 *result)
{
  double v6; // fp28
  double v7; // fp29
  double v8; // fp27
  float y; // r8
  float z; // r7
  double v11; // fp30
  double v13; // fp31
  double x; // fp26
  double v15; // fp25
  double v16; // fp24
  int i; // r28
  double v20; // fp9
  double v21; // fp7
  idVec2 v22; // [sp+50h] [-A0h] BYREF
  float v23; // [sp+58h] [-98h]

  v6 = (float)(pathEnd->y - pathStart->y);
  v7 = (float)(pathEnd->x - pathStart->x);
  v8 = (float)(pathEnd->z - pathStart->z);
  y = pathStart->y;
  z = pathStart->z;
  v11 = 0.25;
  v13 = 0.5;
  v22.x = pathStart->x;
  x = v22.x;
  v22.y = y;
  v15 = y;
  v23 = z;
  v16 = z;
  for ( i = 0; i < 8; ++i )
  {
    if ( (float)((float)v11
               * (float)((float)((float)v8 * (float)v8)
                       + (float)((float)((float)v7 * (float)v7) + (float)((float)v6 * (float)v6)))) <= 16.0 )
      break;
    v20 = pathStart->z;
    v21 = (float)(pathStart->y + (float)((float)v6 * (float)v13));
    v22.x = pathStart->x + (float)((float)v7 * (float)v13);
    v22.y = v21;
    v23 = (float)((float)v8 * (float)v13) + (float)v20;
    if ( (unsigned __int8)idObstacleAvoidanceCore::LineIntersectsWall(this, start: startPos, end: &v22) != 0 )
    {
      v13 = (float)((float)v13 - (float)v11);
    }
    else
    {
      x = v22.x;
      v13 = (float)((float)v13 + (float)v11);
      v15 = v22.y;
      v16 = v23;
    }
    v11 = (float)((float)v11 * (float)0.5);
  }
  result->x = x;
  result->y = v15;
  result->z = v16;
}


// ========================================================================
// ?FindSeekPosForRoute@idObstacleAvoidanceCore@@AAA_NPBUobstacleRoute_t@@MABVidVec3@@AAV3@QAV3@AAH@Z
// EA  : 0x826C4C00
// RVA : 0x006C4C00
// PDB : w:\tech5\engine\gamelib\aas2\obstacleavoidancecore.cpp
// ========================================================================

int __fastcall idObstacleAvoidanceCore::FindSeekPosForRoute(
        idObstacleAvoidanceCore *this,
        const obstacleRoute_t *route,
        double obstacleRadius,
        const idVec3 *startPos,
        const idVec2 *seekPos,
        idVec3 *wallCorners,
        float *outNextRouteIndex,
        int *a8)
{
  double z; // fp30
  float *v16; // r30
  int v17; // r28
  int id; // r11
  float v20; // r8
  int v21; // r26
  float y; // r6
  int v23; // r28
  idVec3 *p_start; // r30
  double x; // fp9
  double v26; // fp12
  double v27; // fp13
  int v28; // r28
  double v29; // fp0
  idVec3 *v30; // r30
  double v33; // fp8
  double v34; // fp3
  double v35; // fp3
  avoidDebugLine_t *debugLines; // r9
  int numDebugLines; // r10
  avoidDebugLine_t *v38; // r11
  int v39; // r10
  avoidDebugLine_t *v40; // r9
  avoidDebugLine_t *v41; // r11
  int v42; // r10
  avoidDebugLine_t *v43; // r9
  avoidDebugLine_t *v44; // r11
  int v45; // r10
  avoidDebugLine_t *v46; // r9
  avoidDebugLine_t *v47; // r11
  double v48; // fp7
  double v49; // fp2
  double v50; // fp4
  double v51; // fp1
  double v52; // fp5
  double v53; // fp7
  double v54; // fp4
  double v55; // fp7
  double v56; // fp5
  double v57; // fp4
  double v58; // fp2
  double v59; // fp1
  double v60; // fp8
  double v61; // fp6
  avoidDebugLine_t *v62; // r9
  int v63; // r10
  double v64; // fp8
  double v65; // fp10
  double v66; // fp7
  avoidDebugLine_t *v67; // r11
  int v68; // r10
  double v69; // fp8
  double v70; // fp10
  double v71; // fp7
  avoidDebugLine_t *v72; // r9
  avoidDebugLine_t *v73; // r11
  double v74; // fp11
  double v75; // fp10
  idVec3 v76; // [sp+50h] [-A0h] BYREF
  idVec3 v77; // [sp+5Ch] [-94h] BYREF

  if ( this->expandedObstacles != nullptr )
  {
    z = wallCorners->z;
    v16 = &route->endAlignDir.y + 7 * route->numAreas;
    v17 = idObstacleAvoidanceCore::PointInsideObstacle(this, point: (const idVec2 *)v16);
    if ( (unsigned __int8)idObstacleAvoidanceCore::LineIntersectsObstacle(
                            this,
                            start: seekPos,
                            end: (const idVec2 *)v16,
                            endObstacle: v17,
                            ignoreObstacle: v17) != 0 )
    {
      v20 = route->areas[0].end.z;
      v21 = 1;
      y = route->areas[0].end.y;
      v23 = route->numAreas - 1;
      v76.x = route->areas[0].end.x;
      v76.y = y;
      v76.z = v20;
      v77.x = v76.x;
      v77.y = y;
      v77.z = v20;
      if ( v23 >= 1 )
      {
        p_start = &route->areas[v23].start;
        while ( (unsigned __int8)idObstacleAvoidanceCore::LineIntersectsWall(
                                   this,
                                   start: seekPos,
                                   end: (const idVec2 *)p_start) != 0 )
        {
          --v23;
          p_start = (idVec3 *)((char *)p_start - 28);
          if ( v23 < 1 )
            goto LABEL_13;
        }
        idObstacleAvoidanceCore::SubSamplePath(
          this,
          startPos: seekPos,
          pathStart: p_start,
          pathEnd: p_start + 1,
          result: &v76);
        v21 = v23;
      }
LABEL_13:
      x = v76.x;
      v26 = v76.y;
      v27 = v76.x;
      v28 = route->numAreas - 1;
      v77.x = v76.x;
      v29 = v76.y;
      v77.y = v76.y;
      v77.z = v76.z;
      if ( v28 >= v21 )
      {
        v30 = &route->areas[v28].start;
        while ( (unsigned __int8)idObstacleAvoidanceCore::LineIntersectsWall(
                                   this,
                                   start: (const idVec2 *)&v76,
                                   end: (const idVec2 *)v30) != 0 )
        {
          --v28;
          v30 = (idVec3 *)((char *)v30 - 28);
          if ( v28 < v21 )
          {
            v29 = v77.y;
            v27 = v77.x;
            v26 = v76.y;
            x = v76.x;
            goto LABEL_21;
          }
        }
        idObstacleAvoidanceCore::SubSamplePath(
          this,
          startPos: (const idVec2 *)&v76,
          pathStart: v30,
          pathEnd: v30 + 1,
          result: &v77);
        v27 = v77.x;
        x = v76.x;
        v29 = v77.y;
        v26 = v76.y;
        _FP3 = (float)((float)((float)((float)(v77.y - v76.y) * (float)(v77.y - v76.y))
                             + (float)((float)((float)(v77.x - v76.x) * (float)(v77.x - v76.x))
                                     + (float)((float)(v77.z - v76.z) * (float)(v77.z - v76.z))))
                     - idMath::FLT_SMALLEST_NON_DENORMAL);
        __asm { fsel      f3, f3, f1, f8 }
        v33 = __frsqrte(_FP3);
        v34 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v33
                                                                                            * (float)((float)((float)((float)(v77.y - v76.y) * (float)(v77.y - v76.y)) + (float)((float)((float)(v77.x - v76.x) * (float)(v77.x - v76.x)) + (float)((float)(v77.z - v76.z) * (float)(v77.z - v76.z)))) * (float)0.5))
                                                                                    * (float)v33)
                                                                            - (float)1.5)
                                                            * (float)v33)
                                                    * (float)((float)((float)((float)(v77.y - v76.y)
                                                                            * (float)(v77.y - v76.y))
                                                                    + (float)((float)((float)(v77.x - v76.x)
                                                                                    * (float)(v77.x - v76.x))
                                                                            + (float)((float)(v77.z - v76.z)
                                                                                    * (float)(v77.z - v76.z))))
                                                            * (float)0.5))
                                            * (float)((float)-(float)((float)((float)((float)v33
                                                                                    * (float)((float)((float)((float)(v77.y - v76.y) * (float)(v77.y - v76.y)) + (float)((float)((float)(v77.x - v76.x) * (float)(v77.x - v76.x)) + (float)((float)(v77.z - v76.z) * (float)(v77.z - v76.z))))
                                                                                            * (float)0.5))
                                                                            * (float)v33)
                                                                    - (float)1.5)
                                                    * (float)v33))
                                    - (float)1.5)
                    * (float)((float)-(float)((float)((float)((float)v33
                                                            * (float)((float)((float)((float)(v77.y - v76.y)
                                                                                    * (float)(v77.y - v76.y))
                                                                            + (float)((float)((float)(v77.x - v76.x)
                                                                                            * (float)(v77.x - v76.x))
                                                                                    + (float)((float)(v77.z - v76.z)
                                                                                            * (float)(v77.z - v76.z))))
                                                                    * (float)0.5))
                                                    * (float)v33)
                                            - (float)1.5)
                            * (float)v33));
        v35 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v33 * (float)((float)((float)((float)(v77.y - v76.y) * (float)(v77.y - v76.y)) + (float)((float)((float)(v77.x - v76.x) * (float)(v77.x - v76.x)) + (float)((float)(v77.z - v76.z) * (float)(v77.z - v76.z)))) * (float)0.5)) * (float)v33) - (float)1.5) * (float)v33)
                                                                                            * (float)((float)((float)((float)(v77.y - v76.y) * (float)(v77.y - v76.y)) + (float)((float)((float)(v77.x - v76.x) * (float)(v77.x - v76.x)) + (float)((float)(v77.z - v76.z) * (float)(v77.z - v76.z)))) * (float)0.5))
                                                                                    * (float)((float)-(float)((float)((float)((float)v33 * (float)((float)((float)((float)(v77.y - v76.y) * (float)(v77.y - v76.y)) + (float)((float)((float)(v77.x - v76.x) * (float)(v77.x - v76.x)) + (float)((float)(v77.z - v76.z) * (float)(v77.z - v76.z)))) * (float)0.5)) * (float)v33) - (float)1.5)
                                                                                            * (float)v33))
                                                                            - (float)1.5)
                                                            * (float)((float)-(float)((float)((float)((float)v33 * (float)((float)((float)((float)(v77.y - v76.y) * (float)(v77.y - v76.y)) + (float)((float)((float)(v77.x - v76.x) * (float)(v77.x - v76.x)) + (float)((float)(v77.z - v76.z) * (float)(v77.z - v76.z)))) * (float)0.5))
                                                                                            * (float)v33)
                                                                                    - (float)1.5)
                                                                    * (float)v33))
                                                    * (float)((float)((float)((float)(v77.y - v76.y)
                                                                            * (float)(v77.y - v76.y))
                                                                    + (float)((float)((float)(v77.x - v76.x)
                                                                                    * (float)(v77.x - v76.x))
                                                                            + (float)((float)(v77.z - v76.z)
                                                                                    * (float)(v77.z - v76.z))))
                                                            * (float)0.5))
                                            * (float)v34)
                                    - (float)1.5)
                    * (float)v34);
        if ( (float)((float)v35
                   * (float)((float)((float)(v77.y - v76.y) * (float)(v77.y - v76.y))
                           + (float)((float)((float)(v77.x - v76.x) * (float)(v77.x - v76.x))
                                   + (float)((float)(v77.z - v76.z) * (float)(v77.z - v76.z))))) > 0.2 )
        {
          v27 = (float)(v77.x - (float)((float)((float)(v77.x - v76.x) * (float)v35) * (float)0.2));
          v77.x = v77.x - (float)((float)((float)(v77.x - v76.x) * (float)v35) * (float)0.2);
          v29 = (float)(v77.y - (float)((float)((float)(v77.y - v76.y) * (float)v35) * (float)0.2));
          v77.y = v77.y - (float)((float)((float)(v77.y - v76.y) * (float)v35) * (float)0.2);
          v77.z = v77.z - (float)((float)((float)(v77.z - v76.z) * (float)v35) * (float)0.2);
        }
        *a8 = v28;
      }
LABEL_21:
      debugLines = this->debugLines;
      if ( debugLines != nullptr )
      {
        numDebugLines = this->numDebugLines;
        if ( numDebugLines < this->maxDebugLines - 1 )
        {
          v38 = &debugLines[numDebugLines];
          this->numDebugLines = numDebugLines + 1;
          v38->color = COLOR_WHITE;
          v38->start.x = (float)x - (float)16.0;
          v38->start.y = v26;
          v38->start.z = 0.0;
          v38->end.z = 0.0;
          v38->end.x = (float)x + (float)16.0;
          v38->end.y = v26;
          this->debugLines[this->numDebugLines].color = COLOR_INVALID;
          v29 = v77.y;
          v27 = v77.x;
          x = v76.x;
          v26 = v76.y;
        }
        v39 = this->numDebugLines;
        if ( v39 < this->maxDebugLines - 1 )
        {
          v40 = this->debugLines;
          if ( v40 != nullptr )
          {
            v41 = &v40[v39];
            this->numDebugLines = v39 + 1;
            v41->color = COLOR_WHITE;
            v41->start.x = x;
            v41->start.y = (float)v26 - (float)16.0;
            v41->start.z = 0.0;
            v41->end.x = x;
            v41->end.y = (float)v26 + (float)16.0;
            v41->end.z = 0.0;
            this->debugLines[this->numDebugLines].color = COLOR_INVALID;
            v29 = v77.y;
            v27 = v77.x;
            v26 = v76.y;
            x = v76.x;
          }
        }
        v42 = this->numDebugLines;
        if ( v42 < this->maxDebugLines - 1 )
        {
          v43 = this->debugLines;
          if ( v43 != nullptr )
          {
            v44 = &v43[v42];
            this->numDebugLines = v42 + 1;
            v44->color = COLOR_WHITE;
            v44->start.x = (float)v27 - (float)16.0;
            v44->start.y = v29;
            v44->start.z = 0.0;
            v44->end.x = (float)v27 + (float)16.0;
            v44->end.y = v29;
            v44->end.z = 0.0;
            this->debugLines[this->numDebugLines].color = COLOR_INVALID;
            v29 = v77.y;
            v27 = v77.x;
            v26 = v76.y;
            x = v76.x;
          }
        }
        v45 = this->numDebugLines;
        if ( v45 < this->maxDebugLines - 1 )
        {
          v46 = this->debugLines;
          if ( v46 != nullptr )
          {
            v47 = &v46[v45];
            this->numDebugLines = v45 + 1;
            v47->color = COLOR_WHITE;
            v47->start.x = v27;
            v47->start.y = (float)v29 - (float)16.0;
            v47->start.z = 0.0;
            v47->end.x = v27;
            v47->end.y = (float)v29 + (float)16.0;
            v47->end.z = 0.0;
            this->debugLines[this->numDebugLines].color = COLOR_INVALID;
            v29 = v77.y;
            v27 = v77.x;
            v26 = v76.y;
            x = v76.x;
          }
        }
      }
      v48 = (float)((float)v26 - seekPos->y);
      v49 = v76.z;
      v50 = (float)((float)v29 - seekPos->y);
      v51 = v77.z;
      v52 = (float)((float)((float)obstacleRadius - (float)20.0) * (float)((float)obstacleRadius - (float)20.0));
      v53 = (float)((float)((float)((float)x - seekPos->x) * (float)((float)x - seekPos->x))
                  + (float)((float)((float)(v76.z - seekPos[1].x) * (float)(v76.z - seekPos[1].x))
                          + (float)((float)v48 * (float)v48)));
      v54 = (float)((float)((float)((float)v27 - seekPos->x) * (float)((float)v27 - seekPos->x))
                  + (float)((float)((float)(v77.z - seekPos[1].x) * (float)(v77.z - seekPos[1].x))
                          + (float)((float)v50 * (float)v50)));
      if ( v53 <= v52 )
      {
        if ( v54 <= v52 )
        {
          wallCorners->x = v27;
          wallCorners->z = v51;
          wallCorners->y = v29;
        }
        else
        {
          v60 = __fsqrts(v53);
          v61 = __fsqrts(v54);
          wallCorners->x = (float)((float)((float)v27 - (float)x)
                                 * (float)((float)((float)((float)obstacleRadius - (float)20.0) - (float)v60)
                                         / (float)v61))
                         + (float)x;
          wallCorners->y = (float)((float)((float)v29 - (float)v26)
                                 * (float)((float)((float)((float)obstacleRadius - (float)20.0) - (float)v60)
                                         / (float)v61))
                         + (float)v26;
          wallCorners->z = (float)((float)((float)v51 - (float)v49)
                                 * (float)((float)((float)((float)obstacleRadius - (float)20.0) - (float)v60)
                                         / (float)v61))
                         + (float)v49;
        }
      }
      else
      {
        v55 = __fsqrts(v53);
        v56 = seekPos->y;
        v57 = seekPos[1].x;
        v58 = (float)((float)((float)v26 - seekPos->y)
                    * (float)((float)((float)obstacleRadius - (float)20.0) / (float)v55));
        v59 = (float)((float)(v76.z - seekPos[1].x) * (float)((float)((float)obstacleRadius - (float)20.0) / (float)v55));
        wallCorners->x = (float)((float)((float)x - seekPos->x)
                               * (float)((float)((float)obstacleRadius - (float)20.0) / (float)v55))
                       + seekPos->x;
        wallCorners->y = (float)v58 + (float)v56;
        wallCorners->z = (float)v59 + (float)v57;
      }
      wallCorners->z = z;
      v62 = this->debugLines;
      if ( v62 != nullptr )
      {
        v63 = this->numDebugLines;
        v64 = (float)(wallCorners->x + (float)16.0);
        v65 = wallCorners->y;
        v66 = (float)(wallCorners->x - (float)16.0);
        if ( v63 < this->maxDebugLines - 1 )
        {
          v67 = &v62[v63];
          this->numDebugLines = v63 + 1;
          v67->color = COLOR_MAGENTA;
          v67->start.x = v66;
          v67->start.y = v65;
          v67->start.z = 0.0;
          v67->end.x = v64;
          v67->end.y = v65;
          v67->end.z = 0.0;
          this->debugLines[this->numDebugLines].color = COLOR_INVALID;
          v29 = v77.y;
          v27 = v77.x;
          v26 = v76.y;
          x = v76.x;
        }
        v68 = this->numDebugLines;
        v69 = (float)(wallCorners->y + (float)16.0);
        v70 = wallCorners->x;
        v71 = (float)(wallCorners->y - (float)16.0);
        if ( v68 < this->maxDebugLines - 1 )
        {
          v72 = this->debugLines;
          if ( v72 != nullptr )
          {
            v73 = &v72[v68];
            this->numDebugLines = v68 + 1;
            v73->color = COLOR_MAGENTA;
            v73->start.x = v70;
            v73->start.y = v71;
            v73->start.z = 0.0;
            v73->end.x = v70;
            v73->end.y = v69;
            v73->end.z = 0.0;
            this->debugLines[this->numDebugLines].color = COLOR_INVALID;
            v29 = v77.y;
            v27 = v77.x;
            v26 = v76.y;
            x = v76.x;
          }
        }
      }
      v74 = v76.z;
      v75 = v77.z;
      *outNextRouteIndex = x;
      outNextRouteIndex[1] = v26;
      outNextRouteIndex[2] = v74;
      outNextRouteIndex[3] = v27;
      outNextRouteIndex[4] = v29;
      outNextRouteIndex[5] = v75;
    }
    else
    {
      wallCorners->x = *v16;
      wallCorners->y = v16[1];
      wallCorners->z = z;
      *outNextRouteIndex = *v16;
      outNextRouteIndex[1] = v16[1];
      outNextRouteIndex[2] = v16[2];
      outNextRouteIndex[3] = *v16;
      outNextRouteIndex[4] = v16[1];
      outNextRouteIndex[5] = v16[2];
      if ( v17 == -1 )
        return 1;
      id = this->expandedObstacles[v17].id;
      if ( id == -1 || id == -3 )
        return 1;
    }
  }
  return 0;
}


// ========================================================================
// ?PathAroundCircle@idObstacleAvoidanceCore@@AAA_NABVidVec2@@00QBV2@_NQAV2@AAH@Z
// EA  : 0x826C5328
// RVA : 0x006C5328
// PDB : w:\tech5\engine\gamelib\aas2\obstacleavoidancecore.cpp
// ========================================================================

int __fastcall idObstacleAvoidanceCore::PathAroundCircle(
        idObstacleAvoidanceCore *this,
        const idVec2 *startPos,
        const idVec2 *corner,
        const idVec2 *endPos,
        const idVec2 *circlePoints,
        bool clockWise,
        idVec2 *pathPoints,
        int *numPathPoints)
{
  double x; // fp9
  double y; // fp7
  double v13; // fp8
  int v14; // r3
  int v15; // ctr
  double v16; // fp6
  int v17; // r31
  float *p_y; // r11
  int v19; // r30
  float *v20; // r6
  double v21; // fp12
  double v22; // fp11
  double v23; // fp13
  double v24; // fp5
  bool v25; // r5
  double v26; // fp13
  double v27; // fp12
  double v28; // fp5
  double v29; // fp4
  float *v30; // r6
  double v31; // fp11
  double v32; // fp10
  bool v33; // r5
  double v34; // fp13
  double v35; // fp12
  double v36; // fp5
  float *v37; // r6
  double v38; // fp4
  double v39; // fp11
  double v40; // fp10
  bool v41; // r5
  double v42; // fp13
  double v43; // fp12
  double v44; // fp5
  double v45; // fp4
  float *v46; // r6
  double v47; // fp11
  double v48; // fp10
  int v49; // r11
  int v50; // r6
  unsigned __int8 *v51; // r8
  int v52; // r8
  idVec2 *v53; // r5
  int v54; // r30
  const idVec2 *v55; // r4
  int v56; // r31
  float *p_x; // r5
  int v58; // r29
  float *v59; // r5
  const idVec2 *v60; // r4
  int v61; // r31
  int v62; // r29
  float *v63; // r5
  const idVec2 *v64; // r4
  int v65; // r31
  int v66; // r29
  float *v67; // r5
  const idVec2 *v68; // r4
  int v69; // r30
  int v70; // r29
  float *v71; // r5
  const idVec2 *v72; // r4
  int v73; // r30
  int v74; // r29
  float *v75; // r5
  const idVec2 *v76; // r4
  int v77; // r30
  int v78; // r29
  float *v79; // r5
  const idVec2 *v80; // r4
  int v81; // r30
  int v82; // r29
  const idVec2 *v83; // r4
  int v84; // r30
  int v85; // r8
  int v86; // r6
  int v87; // r31
  idVec2 *v88; // r6
  int v89; // r8
  idVec2 *v90; // r29
  float *v91; // r3
  int v92; // r5
  float *v93; // r4
  int v94; // r6
  const idVec2 *v95; // r6
  float *v96; // r4
  int v97; // r3
  const idVec2 *v98; // r6
  int v99; // r5
  float *v100; // r4
  int v101; // r3
  const idVec2 *v102; // r6
  int v103; // r5
  float *v104; // r4
  int v105; // r30
  const idVec2 *v106; // r6
  int v107; // r5
  float *v108; // r4
  int v109; // r30
  const idVec2 *v110; // r6
  int v111; // r5
  float *v112; // r4
  int v113; // r30
  const idVec2 *v114; // r6
  int v115; // r5
  float *v116; // r4
  int v117; // r30
  const idVec2 *v118; // r5
  float *v119; // r3
  int v120; // r4
  int v121; // r28
  int v122; // r27
  int v123; // r29
  idVec2 *i; // r31
  double v125; // fp31
  double v126; // fp30
  double v127; // fp11
  double v128; // fp10
  double v129; // fp13
  double v130; // fp7
  double v131; // fp6
  double v132; // fp13
  float v134; // [sp+50h] [-A0h] BYREF
  int v135; // [sp+54h] [-9Ch] BYREF
  int v136[2]; // [sp+58h] [-98h] BYREF
  idVec2 v137[2]; // [sp+60h] [-90h] BYREF
  _BYTE v138[56]; // [sp+70h] [-80h] BYREF

  x = startPos->x;
  y = startPos->y;
  v13 = endPos->x;
  v14 = 0;
  v15 = 4;
  v16 = endPos->y;
  v17 = 3;
  p_y = &circlePoints[2].y;
  v19 = 1 - (_DWORD)v138;
  do
  {
    v20 = (float *)((char *)&circlePoints->x + ((8 * (_DWORD)&v138[v14 + v19]) & 0x78));
    v21 = (float)(*(p_y - 4) - v20[1]);
    v22 = (float)(*v20 - *(p_y - 5));
    v23 = (float)(*(p_y - 5) - (float)v13);
    v24 = (float)(*(p_y - 4) - (float)v16);
    v138[v14] = (float)((float)((float)(*v20 - *(p_y - 5)) * (float)(*(p_y - 4) - (float)y))
                      + (float)((float)(*(p_y - 5) - (float)x) * (float)(*(p_y - 4) - v20[1]))) < 0.0;
    v25 = (float)((float)((float)v24 * (float)v22) + (float)((float)v23 * (float)v21)) < 0.0;
    v26 = *(p_y - 2);
    v27 = *(p_y - 3);
    v28 = (float)(*(p_y - 2) - (float)y);
    v29 = (float)(*(p_y - 3) - (float)x);
    v30 = (float *)((char *)&circlePoints->x + ((8 * (v17 - 1)) & 0x78));
    *((_BYTE *)&v137[0].x + v14) = v25;
    v31 = (float)((float)v26 - v30[1]);
    v32 = (float)(*v30 - (float)v27);
    v138[v14 + 1] = (float)((float)((float)(*v30 - (float)v27) * (float)v28)
                          + (float)((float)v29 * (float)((float)v26 - v30[1]))) < 0.0;
    v33 = (float)((float)((float)((float)v26 - (float)v16) * (float)v32)
                + (float)((float)((float)v27 - (float)v13) * (float)v31)) < 0.0;
    v34 = *p_y;
    v35 = *(p_y - 1);
    v36 = (float)(*p_y - (float)y);
    v37 = (float *)((char *)&circlePoints->x + ((8 * v17) & 0x78));
    v38 = (float)(*(p_y - 1) - (float)x);
    v39 = (float)(*p_y - v37[1]);
    v40 = (float)(*v37 - *(p_y - 1));
    *((_BYTE *)&v137[0].x + v14 + 1) = v33;
    v138[v14 + 2] = (float)((float)((float)v40 * (float)v36) + (float)((float)v38 * (float)v39)) < 0.0;
    v41 = (float)((float)((float)((float)v34 - (float)v16) * (float)v40)
                + (float)((float)((float)v35 - (float)v13) * (float)v39)) < 0.0;
    v42 = p_y[2];
    v43 = p_y[1];
    v44 = (float)(p_y[2] - (float)y);
    v45 = (float)(p_y[1] - (float)x);
    v46 = (float *)((char *)&circlePoints->x + ((8 * (v17 + 1)) & 0x78));
    *((_BYTE *)&v137[0].x + v14 + 2) = v41;
    v47 = (float)((float)v42 - v46[1]);
    v48 = (float)(*v46 - (float)v43);
    v138[v17] = (float)((float)((float)(*v46 - (float)v43) * (float)v44)
                      + (float)((float)v45 * (float)((float)v42 - v46[1]))) < 0.0;
    p_y += 8;
    v17 += 4;
    *((_BYTE *)&v137[0].x + v14 + 3) = (float)((float)((float)((float)v42 - (float)v16) * (float)v48)
                                             + (float)((float)((float)v43 - (float)v13) * (float)v47)) < 0.0;
    v14 += 4;
    --v15;
  }
  while ( v15 != 0 );
  pathPoints->x = x;
  v49 = 1;
  pathPoints->y = startPos->y;
  if ( clockWise )
  {
    v50 = 0;
    v51 = v138;
    while ( (((unsigned __int8)v138[((_BYTE)v51 + (_BYTE)v19) & 0xF] ^ 1) & *v51) == 0 )
    {
      ++v50;
      ++v51;
      if ( v50 >= 16 )
        goto LABEL_35;
    }
    if ( v50 != -1 )
    {
      v52 = 0;
      v53 = pathPoints + 1;
      do
      {
        v54 = ((_BYTE)v50 + 1 + (_BYTE)v52) & 0xF;
        ++v49;
        v55 = &circlePoints[v54];
        v56 = *((unsigned __int8 *)&v137[0].x + v54);
        v53->x = v55->x;
        v53->y = v55->y;
        p_x = &v53[1].x;
        if ( v56 != 0 )
          break;
        v58 = ((_BYTE)v52 + (_BYTE)v50 + 2) & 0xF;
        ++v49;
        v60 = &circlePoints[v58];
        v61 = *((unsigned __int8 *)&v137[0].x + v58);
        *p_x = v60->x;
        p_x[1] = v60->y;
        v59 = p_x + 2;
        if ( v61 != 0 )
          break;
        v62 = ((_BYTE)v52 + (_BYTE)v50 + 3) & 0xF;
        ++v49;
        v64 = &circlePoints[v62];
        v65 = *((unsigned __int8 *)&v137[0].x + v62);
        *v59 = v64->x;
        v59[1] = v64->y;
        v63 = v59 + 2;
        if ( v65 != 0 )
          break;
        v66 = ((_BYTE)v52 + (_BYTE)v50 + 4) & 0xF;
        ++v49;
        v68 = &circlePoints[v66];
        v69 = *((unsigned __int8 *)&v137[0].x + v66);
        *v63 = v68->x;
        v63[1] = v68->y;
        v67 = v63 + 2;
        if ( v69 != 0 )
          break;
        v70 = ((_BYTE)v52 + (_BYTE)v50 + 5) & 0xF;
        ++v49;
        v72 = &circlePoints[v70];
        v73 = *((unsigned __int8 *)&v137[0].x + v70);
        *v67 = v72->x;
        v67[1] = v72->y;
        v71 = v67 + 2;
        if ( v73 != 0 )
          break;
        v74 = ((_BYTE)v52 + (_BYTE)v50 + 6) & 0xF;
        ++v49;
        v76 = &circlePoints[v74];
        v77 = *((unsigned __int8 *)&v137[0].x + v74);
        *v71 = v76->x;
        v71[1] = v76->y;
        v75 = v71 + 2;
        if ( v77 != 0 )
          break;
        v78 = ((_BYTE)v52 + (_BYTE)v50 + 7) & 0xF;
        ++v49;
        v80 = &circlePoints[v78];
        v81 = *((unsigned __int8 *)&v137[0].x + v78);
        *v75 = v80->x;
        v75[1] = v80->y;
        v79 = v75 + 2;
        if ( v81 != 0 )
          break;
        v82 = ((_BYTE)v52 + (_BYTE)v50 - 8) & 0xF;
        ++v49;
        v83 = &circlePoints[v82];
        v84 = *((unsigned __int8 *)&v137[0].x + v82);
        *v79 = v83->x;
        v79[1] = v83->y;
        v53 = (idVec2 *)(v79 + 2);
        if ( v84 != 0 )
          break;
        v52 += 8;
      }
      while ( v52 < 16 );
    }
  }
  else
  {
    v85 = 15;
    while ( 1 )
    {
      v86 = v85 - 1;
      if ( (((unsigned __int8)v138[(v85 - 1) & 0xF] ^ 1) & (unsigned __int8)v138[v85]) != 0 )
        break;
      --v85;
      if ( v86 < 0 )
        goto LABEL_35;
    }
    if ( v85 != -1 )
    {
      v87 = 0;
      v88 = pathPoints + 1;
      v89 = v85 - 2;
      do
      {
        v90 = v88;
        v91 = (float *)((char *)&circlePoints->x + ((8 * (v89 + 2)) & 0x78));
        v92 = ((_BYTE)v89 + 1) & 0xF;
        v93 = &v88[1].x;
        ++v49;
        v88->x = *v91;
        v94 = *((unsigned __int8 *)&v137[0].x + v92);
        v90->y = v91[1];
        if ( v94 != 0 )
          break;
        v95 = &circlePoints[v92];
        ++v49;
        v97 = *((unsigned __int8 *)&v137[0].x + (v89 & 0xF));
        *v93 = v95->x;
        v93[1] = v95->y;
        v96 = v93 + 2;
        if ( v97 != 0 )
          break;
        v98 = &circlePoints[v89 & 0xF];
        v99 = ((_BYTE)v89 - 1) & 0xF;
        ++v49;
        v101 = *((unsigned __int8 *)&v137[0].x + v99);
        *v96 = v98->x;
        v96[1] = v98->y;
        v100 = v96 + 2;
        if ( v101 != 0 )
          break;
        v102 = &circlePoints[v99];
        v103 = ((_BYTE)v89 - 2) & 0xF;
        ++v49;
        *v100 = v102->x;
        v105 = *((unsigned __int8 *)&v137[0].x + v103);
        v100[1] = v102->y;
        v104 = v100 + 2;
        if ( v105 != 0 )
          break;
        v106 = &circlePoints[v103];
        v107 = ((_BYTE)v89 - 3) & 0xF;
        ++v49;
        *v104 = v106->x;
        v109 = *((unsigned __int8 *)&v137[0].x + v107);
        v104[1] = v106->y;
        v108 = v104 + 2;
        if ( v109 != 0 )
          break;
        v110 = &circlePoints[v107];
        v111 = ((_BYTE)v89 - 4) & 0xF;
        ++v49;
        *v108 = v110->x;
        v113 = *((unsigned __int8 *)&v137[0].x + v111);
        v108[1] = v110->y;
        v112 = v108 + 2;
        if ( v113 != 0 )
          break;
        v114 = &circlePoints[v111];
        v115 = ((_BYTE)v89 - 5) & 0xF;
        ++v49;
        *v112 = v114->x;
        v117 = *((unsigned __int8 *)&v137[0].x + v115);
        v112[1] = v114->y;
        v116 = v112 + 2;
        if ( v117 != 0 )
          break;
        v118 = &circlePoints[v115];
        v119 = v116;
        *v116 = v118->x;
        v88 = (idVec2 *)(v116 + 2);
        ++v49;
        v120 = *((unsigned __int8 *)&v137[0].x + (((_BYTE)v89 - 6) & 0xF));
        v119[1] = v118->y;
        if ( v120 != 0 )
          break;
        v87 += 8;
        v89 -= 8;
      }
      while ( v87 < 16 );
    }
  }
LABEL_35:
  v121 = v49 + 1;
  v122 = v49;
  v123 = 0;
  pathPoints[v49] = *endPos;
  *numPathPoints = v49 + 1;
  if ( v49 <= 0 )
    return 1;
  for ( i = pathPoints + 1; ; ++i )
  {
    v125 = (float)(i->y - i[-1].y);
    v126 = (float)(i->x - i[-1].x);
    v137[0].y = i->y - i[-1].y;
    v137[0].x = v126;
    if ( idObstacleAvoidanceCore::GetFirstBlockingObstacle(
           this,
           start: i - 1,
           delta: v137,
           skipObstacle: -1,
           blockingScale: &v134,
           blockingObstacle: v136,
           blockingEdgeNum: &v135) )
    {
      if ( v123 < v121 - 2 )
        break;
      v127 = (float)((float)v126 - (float)((float)v126 * v134));
      v128 = (float)((float)v125 - (float)((float)v125 * v134));
      if ( (float)((float)((float)v128 * (float)v128) + (float)((float)v127 * (float)v127)) < 1.0 )
        return 1;
      v129 = corner->y;
      v130 = (float)((float)(endPos->y - corner->y) * (float)0.5);
      v131 = (float)(corner->x + (float)((float)(endPos->x - corner->x) * (float)0.5));
      i->x = corner->x + (float)((float)(endPos->x - corner->x) * (float)0.5);
      i->y = (float)v129 + (float)v130;
      v132 = (float)((float)((float)v129 + (float)v130) - i[-1].y);
      v137[0].x = (float)v131 - i[-1].x;
      v137[0].y = v132;
      if ( idObstacleAvoidanceCore::GetFirstBlockingObstacle(
             this,
             start: i - 1,
             delta: v137,
             skipObstacle: -1,
             blockingScale: &v134,
             blockingObstacle: v136,
             blockingEdgeNum: &v135) )
      {
        break;
      }
    }
    if ( ++v123 >= v122 )
      return 1;
  }
  return 0;
}


// ========================================================================
// ?CircleCorners@idObstacleAvoidanceCore@@AAAXPAUobstaclePath_t@@ABVidVec4@@ABVidBounds@@MM@Z
// EA  : 0x826C5B90
// RVA : 0x006C5B90
// PDB : w:\tech5\engine\gamelib\aas2\obstacleavoidancecore.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idObstacleAvoidanceCore::CircleCorners(
        idObstacleAvoidanceCore *this,
        obstaclePath_t *path,
        const idVec2 *lastCorner,
        const idBounds *bbox,
        double frameMoveDist,
        double cornerCircleRadius)
{
  idVec2 *p_nextCorner; // r30
  idVec3 *v10; // r22
  __int64 v12; // r5
  idVec2 v13; // r4 OVERLAPPED
  double x; // fp30
  double y; // fp29
  double v16; // fp24
  idVec2 v17; // r11
  double v18; // fp19
  double v19; // fp21
  double v20; // fp23
  double v21; // fp18
  double v22; // fp20
  int v23; // r23
  double v28; // fp13
  double v29; // fp11
  double v30; // fp4
  double v31; // fp4
  double v32; // fp13
  double v33; // fp11
  double v34; // fp28
  double v35; // fp27
  double v36; // fp26
  double v37; // fp25
  int *v42; // r8
  idVec3 *v43; // r7
  double z; // fp0
  __int64 v45; // r11
  double w; // fp1
  avoidDebugLine_t *debugLines; // r11
  int v50; // r29
  idVec2 *v51; // r5
  idVec2 *v52; // r28
  double v53; // fp11
  int v54; // r25
  double v55; // fp0
  bool v56; // r11
  double v57; // fp12
  double v58; // fp1
  int *v61; // r8
  idVec3 *v62; // r7
  __int64 v63; // r11
  double v64; // fp11
  double v65; // fp1
  int v68; // r30
  idVec2 *v69; // r5
  idVec2 *v70; // r29
  int v71; // r10
  unsigned int v72; // ctr
  float *v73; // r11
  idVec2 *v74; // r9
  int v75; // r7
  int v76; // r5
  int v77; // r3
  float *v78; // r9
  int v79; // ctr
  float *v80; // r11
  idVec2 *v81; // r9
  int v82; // r30
  int v83; // r10
  int v84; // r11
  double v85; // fp11
  double v86; // fp10
  double v87; // fp9
  double v88; // fp8
  double v89; // fp7
  int v90; // r11
  int v91; // ctr
  double v92; // fp13
  int v93; // r11
  int i; // ctr
  double v95; // fp13
  int v96; // r5
  int v97; // r6
  float *v98; // r11
  int numDebugLines; // r9
  avoidDebugLine_t *v100; // r8
  avoidDebugLine_t *v101; // r10
  double v102; // fp13
  double v103; // fp12
  int v104; // r9
  avoidDebugLine_t *v105; // r8
  avoidDebugLine_t *v106; // r10
  double v107; // fp0
  double v108; // fp12
  int v109; // r9
  avoidDebugLine_t *v110; // r8
  avoidDebugLine_t *v111; // r10
  double v112; // fp0
  double v113; // fp12
  int v114; // r9
  avoidDebugLine_t *v115; // r8
  avoidDebugLine_t *v116; // r10
  double v117; // fp0
  double v118; // fp12
  float *v119; // r10
  int v120; // ctr
  int v121; // r9
  avoidDebugLine_t *v122; // r8
  avoidDebugLine_t *v123; // r11
  double v124; // fp0
  double v125; // fp12
  double v126; // fp11
  int v127; // r10
  double v128; // fp13
  double v129; // fp12
  double v130; // fp11
  avoidDebugLine_t *v131; // r9
  avoidDebugLine_t *v132; // r11
  int v133; // r10
  double v134; // fp12
  double v135; // fp13
  double v136; // fp11
  avoidDebugLine_t *v137; // r9
  avoidDebugLine_t *v138; // r11
  int v139; // r10
  double v140; // fp12
  double v141; // fp13
  double v142; // fp11
  avoidDebugLine_t *v143; // r9
  avoidDebugLine_t *v144; // r11
  int v145; // r10
  double v146; // fp12
  double v147; // fp13
  double v148; // fp0
  avoidDebugLine_t *v149; // r9
  avoidDebugLine_t *v150; // r11
  int v151[2]; // [sp+50h] [-3D0h] BYREF
  idVec2 v152; // [sp+58h] [-3C8h] BYREF
  idVec2 v153; // [sp+60h] [-3C0h] BYREF
  __int64 v154; // [sp+68h] [-3B8h] BYREF
  idVec2 v155; // [sp+70h] [-3B0h] BYREF
  idVec2 v156; // [sp+78h] [-3A8h] BYREF
  idVec2 v157[20]; // [sp+80h] [-3A0h] BYREF
  idVec2 v158; // [sp+120h] [-300h] BYREF
  _QWORD v159[47]; // [sp+128h] [-2F8h] BYREF
  idVec2 v160[33]; // [sp+2A0h] [-180h] BYREF

  p_nextCorner = (idVec2 *)&path->nextCorner;
  v10 = &path->seekPos[1];
  path->nextCorner.x = 0.0;
  path->nextCorner.w = 0.0;
  path->nextCorner.z = 0.0;
  path->nextCorner.y = 0.0;
  v12 = *(_QWORD *)&path->startPosOutsideObstacles.x;
  path->nextCornerAngle = 0.0;
  v13 = *(idVec2 *)HIDWORD(v12);
  v153 = v13;
  x = v13.x;
  v152 = *(idVec2 *)&path->seekPos[1].x;
  v155 = *(idVec2 *)((char *)&v13 - 4);
  y = v13.y;
  v16 = v152.x;
  v17 = *(idVec2 *)&path->startPosOutsideObstacles.x;
  v18 = *((float *)&v12 + 1);
  v19 = (float)(v13.y - *((float *)&v12 + 1));
  v20 = v152.y;
  v21 = v13.y;
  v22 = (float)(v13.x - v13.y);
  v23 = 2;
  v159[0] = *(_QWORD *)&path->seekPos[0].x;
  v17.x = *((float *)v159 + 1);
  v151[0] = 2;
  v158 = v17;
  _FP11 = (float)((float)((float)((float)(v13.y - v152.y) * (float)(v13.y - v152.y))
                        + (float)((float)(v13.x - v152.x) * (float)(v13.x - v152.x)))
                - idMath::FLT_SMALLEST_NON_DENORMAL);
  _FP4 = (float)((float)((float)((float)(v13.x - v13.y) * (float)(v13.x - v13.y))
                       + (float)((float)(v13.y - *((float *)&v12 + 1)) * (float)(v13.y - *((float *)&v12 + 1))))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm
  {
    fsel      f11, f11, f3, f13
    fsel      f4, f4, f1, f13
  }
  v28 = __frsqrte(_FP11);
  v29 = __frsqrte(_FP4);
  v30 = (float)((float)-(float)((float)((float)((float)v28
                                              * (float)((float)((float)((float)(v13.y - v152.y) * (float)(v13.y - v152.y))
                                                              + (float)((float)(v13.x - v152.x) * (float)(v13.x - v152.x)))
                                                      * (float)0.5))
                                      * (float)v28)
                              - (float)1.5)
              * (float)v28);
  v31 = (float)((float)-(float)((float)((float)((float)v30
                                              * (float)((float)((float)((float)(v13.y - v152.y) * (float)(v13.y - v152.y))
                                                              + (float)((float)(v13.x - v152.x) * (float)(v13.x - v152.x)))
                                                      * (float)0.5))
                                      * (float)v30)
                              - (float)1.5)
              * (float)v30);
  v32 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v29
                                                                                      * (float)((float)((float)((float)(v13.x - v13.y) * (float)(v13.x - v13.y)) + (float)((float)(v13.y - *((float *)&v12 + 1)) * (float)(v13.y - *((float *)&v12 + 1))))
                                                                                              * (float)0.5))
                                                                              * (float)v29)
                                                                      - (float)1.5)
                                                      * (float)v29)
                                              * (float)((float)((float)((float)(v13.x - v13.y) * (float)(v13.x - v13.y))
                                                              + (float)((float)(v13.y - *((float *)&v12 + 1))
                                                                      * (float)(v13.y - *((float *)&v12 + 1))))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v29
                                                                              * (float)((float)((float)((float)(v13.x - v13.y) * (float)(v13.x - v13.y))
                                                                                              + (float)((float)(v13.y - *((float *)&v12 + 1)) * (float)(v13.y - *((float *)&v12 + 1))))
                                                                                      * (float)0.5))
                                                                      * (float)v29)
                                                              - (float)1.5)
                                              * (float)v29))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v29
                                                      * (float)((float)((float)((float)(v13.x - v13.y)
                                                                              * (float)(v13.x - v13.y))
                                                                      + (float)((float)(v13.y - *((float *)&v12 + 1))
                                                                              * (float)(v13.y - *((float *)&v12 + 1))))
                                                              * (float)0.5))
                                              * (float)v29)
                                      - (float)1.5)
                      * (float)v29));
  v33 = (float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v29 * (float)((float)((float)((float)(v13.x - v13.y) * (float)(v13.x - v13.y)) + (float)((float)(v13.y - *((float *)&v12 + 1)) * (float)(v13.y - *((float *)&v12 + 1)))) * (float)0.5)) * (float)v29) - (float)1.5)
                                                                                      * (float)v29)
                                                                              * (float)((float)((float)((float)(v13.x - v13.y) * (float)(v13.x - v13.y))
                                                                                              + (float)((float)(v13.y - *((float *)&v12 + 1)) * (float)(v13.y - *((float *)&v12 + 1))))
                                                                                      * (float)0.5))
                                                                      * (float)((float)-(float)((float)((float)((float)v29 * (float)((float)((float)((float)(v13.x - v13.y) * (float)(v13.x - v13.y)) + (float)((float)(v13.y - *((float *)&v12 + 1)) * (float)(v13.y - *((float *)&v12 + 1)))) * (float)0.5)) * (float)v29)
                                                                                              - (float)1.5)
                                                                              * (float)v29))
                                                              - (float)1.5)
                                              * (float)((float)-(float)((float)((float)((float)v29
                                                                                      * (float)((float)((float)((float)(v13.x - v13.y) * (float)(v13.x - v13.y)) + (float)((float)(v13.y - *((float *)&v12 + 1)) * (float)(v13.y - *((float *)&v12 + 1))))
                                                                                              * (float)0.5))
                                                                              * (float)v29)
                                                                      - (float)1.5)
                                                      * (float)v29))
                                      * (float)((float)((float)((float)(v13.x - v13.y) * (float)(v13.x - v13.y))
                                                      + (float)((float)(v13.y - *((float *)&v12 + 1))
                                                              * (float)(v13.y - *((float *)&v12 + 1))))
                                              * (float)0.5))
                              * (float)v32)
                      - (float)1.5);
  v34 = (float)((float)((float)-(float)((float)((float)((float)v31
                                                      * (float)((float)((float)((float)(v13.y - v152.y)
                                                                              * (float)(v13.y - v152.y))
                                                                      + (float)((float)(v13.x - v152.x)
                                                                              * (float)(v13.x - v152.x)))
                                                              * (float)0.5))
                                              * (float)v31)
                                      - (float)1.5)
                      * (float)v31)
              * (float)(v13.x - v152.x));
  v35 = (float)((float)((float)-(float)((float)((float)((float)v31
                                                      * (float)((float)((float)((float)(v13.y - v152.y)
                                                                              * (float)(v13.y - v152.y))
                                                                      + (float)((float)(v13.x - v152.x)
                                                                              * (float)(v13.x - v152.x)))
                                                              * (float)0.5))
                                              * (float)v31)
                                      - (float)1.5)
                      * (float)v31)
              * (float)(v13.y - v152.y));
  v36 = (float)((float)((float)v33 * (float)v32) * (float)(v13.x - v13.y));
  v37 = (float)((float)((float)v33 * (float)v32) * (float)(v13.y - *((float *)&v12 + 1)));
  _FP13 = (float)((float)((float)((float)v33 * (float)v32)
                        * (float)((float)((float)(v13.x - v13.y) * (float)(v13.x - v13.y))
                                + (float)((float)(v13.y - *((float *)&v12 + 1)) * (float)(v13.y - *((float *)&v12 + 1)))))
                - (float)((float)((float)-(float)((float)((float)((float)v31
                                                                * (float)((float)((float)((float)(v13.y - v152.y)
                                                                                        * (float)(v13.y - v152.y))
                                                                                + (float)((float)(v13.x - v152.x)
                                                                                        * (float)(v13.x - v152.x)))
                                                                        * (float)0.5))
                                                        * (float)v31)
                                                - (float)1.5)
                                * (float)v31)
                        * (float)((float)((float)(v13.y - v152.y) * (float)(v13.y - v152.y))
                                + (float)((float)(v13.x - v152.x) * (float)(v13.x - v152.x)))));
  __asm { fsel      f12, f13, f3, f1 }
  if ( (float)((float)_FP12 * (float)0.89999998) > (double)(float)((float)cornerCircleRadius * (float)0.25) )
  {
    _FP13 = (float)((float)cornerCircleRadius - (float)((float)_FP12 * (float)0.89999998));
    __asm { fsel      f22, f13, f0, f2 }
    idObstacleAvoidanceCore::GetCirclePoints(
      center: &v153,
      radius: _FP22,
      circlePoints: (idVec2 *)LODWORD(v13.y),
      a4: &v160[0].x);
    v156.x = v152.x + (float)v34;
    v156.y = v152.y + (float)v35;
    if ( (unsigned __int8)idObstacleAvoidanceCore::PathAroundCircle(
                            this,
                            startPos: &v155,
                            corner: &v153,
                            endPos: &v156,
                            circlePoints: v160,
                            clockWise: (float)((float)((float)v34 * (float)v37) - (float)((float)v35 * (float)v36)) < 0.0,
                            pathPoints: &v158,
                            numPathPoints: v151) != 0 )
    {
      if ( (float)((float)((float)v34 * (float)v37) - (float)((float)v35 * (float)v36)) >= 0.0 )
        _FP22 = -_FP22;
      v23 = v151[0];
      z = path->seekPos[0].z;
      p_nextCorner->x = x;
      HIDWORD(v45) = &path->numSeekPos;
      LODWORD(v45) = v23;
      p_nextCorner->y = y;
      p_nextCorner[1].x = z;
      v154 = v45;
      p_nextCorner[1].y = _FP22;
      w = path->nextCorner.w;
      _FP9 = (float)((float)((float)v154 - (float)3.0) * (float)22.5);
      __asm { fsel      f8, f9, f9, f31 }
      path->nextCornerAngle = _FP8;
      idObstacleAvoidanceCore::GetSeekPointsOnPath(
        this,
        pathPoints: &v158,
        numPathPoints: v23,
        corner: p_nextCorner,
        radius: w,
        frameMoveDist,
        seekPos: v43,
        outNumSeekPos: v42,
        a9: (int)path,
        a10: &path->numSeekPos);
      v16 = *(float *)v159;
      v20 = *((float *)v159 + 1);
      v152.x = *(float *)v159;
      v152.y = *((float *)v159 + 1);
    }
    else
    {
      debugLines = this->debugLines;
      v152.x = x;
      v152.y = y;
      v16 = x;
      v20 = y;
      if ( debugLines != nullptr )
      {
        v50 = v151[0] - 1;
        if ( v151[0] - 1 > 0 )
        {
          v51 = &v158;
          do
          {
            v52 = v51 + 1;
            idObstacleAvoidanceCore::AddDebugLine(this, color: COLOR_PURPLE, start: v51, end: v51 + 1);
            --v50;
            v51 = v52;
          }
          while ( v50 != 0 );
        }
      }
      v23 = 0;
    }
  }
  v53 = lastCorner[1].y;
  v54 = 0;
  v151[0] = 0;
  if ( v53 != 0.0 )
  {
    v56 = false;
    if ( __fabs((float)(lastCorner->x - (float)x)) <= 0.1 )
      v56 = __fabs((float)(lastCorner->y - (float)y)) <= 0.1;
    if ( !v56
      && (float)((float)((float)(lastCorner->y - (float)y) * (float)v19)
               + (float)((float)(lastCorner->x - (float)x) * (float)v22)) < 0.0 )
    {
      v58 = __fabs(v53);
      v57 = lastCorner->y;
      v55 = lastCorner->x;
      _FP2 = (float)((float)((float)((float)((float)v18 - (float)v57) * (float)((float)v18 - (float)v57))
                           + (float)((float)((float)v21 - (float)v55) * (float)((float)v21 - (float)v55)))
                   - (float)((float)((float)((float)v20 - (float)v57) * (float)((float)v20 - (float)v57))
                           + (float)((float)((float)v16 - (float)v55) * (float)((float)v16 - (float)v55))));
      __asm { fsel      f0, f2, f3, f4 }
      if ( _FP0 < (float)((float)v58 * (float)v58) )
        v58 = __fsqrts(_FP0);
      idObstacleAvoidanceCore::GetCirclePoints(
        center: lastCorner,
        radius: v58,
        circlePoints: (idVec2 *)LODWORD(v13.y),
        a4: &v160[0].x);
      *(float *)&v154 = (float)v16 - (float)v21;
      *((float *)&v154 + 1) = (float)v20 - (float)v18;
      if ( (unsigned __int8)idObstacleAvoidanceCore::WindingRayIntersection(
                              winding: v160,
                              numPoints: 16,
                              start: &v155,
                              dir: (const idVec2 *)&v154,
                              scale1: &v156.x,
                              scale2: &v153.x,
                              edgeNums: nullptr) != 0
        && (v156.x > 0.0 || v153.x > 0.0) )
      {
        if ( (unsigned __int8)idObstacleAvoidanceCore::PathAroundCircle(
                                this,
                                startPos: &v155,
                                corner: lastCorner,
                                endPos: &v152,
                                circlePoints: v160,
                                clockWise: lastCorner[1].y > 0.0,
                                pathPoints: v157,
                                numPathPoints: v151) != 0 )
        {
          v54 = v151[0];
          p_nextCorner->x = lastCorner->x;
          HIDWORD(v63) = &path->numSeekPos;
          LODWORD(v63) = v54;
          p_nextCorner->y = lastCorner->y;
          v154 = v63;
          p_nextCorner[1].x = lastCorner[1].x;
          v64 = (double)v154;
          p_nextCorner[1].y = lastCorner[1].y;
          v65 = path->nextCorner.w;
          _FP7 = (float)((float)((float)v64 - (float)3.0) * (float)22.5);
          __asm { fsel      f5, f7, f7, f31 }
          path->nextCornerAngle = _FP5;
          idObstacleAvoidanceCore::GetSeekPointsOnPath(
            this,
            pathPoints: v157,
            numPathPoints: v54,
            corner: p_nextCorner,
            radius: v65,
            frameMoveDist,
            seekPos: v62,
            outNumSeekPos: v61,
            a9: (int)path,
            a10: &path->numSeekPos);
        }
        else
        {
          if ( this->debugLines != nullptr )
          {
            v68 = v151[0] - 1;
            if ( v151[0] - 1 > 0 )
            {
              v69 = v157;
              do
              {
                v70 = v69 + 1;
                idObstacleAvoidanceCore::AddDebugLine(this, color: COLOR_PURPLE, start: v69, end: v69 + 1);
                --v68;
                v69 = v70;
              }
              while ( v68 != 0 );
            }
          }
          v54 = 0;
        }
      }
    }
  }
  if ( this->debugLines != nullptr )
  {
    if ( v23 != 0 )
    {
      if ( v54 != 0 )
      {
        v71 = v23 - 1;
        if ( v23 - 1 >= 4 )
        {
          v72 = ((unsigned int)(v23 - 5) >> 2) + 1;
          v73 = (float *)&v158 + 2 * v71 + 3;
          do
          {
            v74 = &v158 + v54 + v71 - 2;
            v75 = 8 * (v54 - 3 + v71);
            v74->x = *(v73 - 3);
            v76 = 8 * (v54 - 4 + v71);
            v74->y = *(v73 - 2);
            *(float *)((char *)&v158.x + v75) = *(v73 - 5);
            v77 = 8 * (v54 - 5 + v71);
            v71 -= 4;
            *(float *)((char *)&v158.y + v75) = *(v73 - 4);
            *(float *)((char *)&v158.x + v76) = *(v73 - 7);
            *(float *)((char *)&v158.y + v76) = *(v73 - 6);
            v78 = (float *)((char *)&v158.x + v77);
            *v78 = *(v73 - 9);
            v73 -= 8;
            v78[1] = *v73;
            --v72;
          }
          while ( v72 != 0 );
        }
        if ( v71 > 0 )
        {
          v79 = v71;
          v80 = (float *)&v158 + 2 * v71 + 3;
          do
          {
            v81 = &v158 + v54 + v71-- - 2;
            v81->x = *(v80 - 3);
            v80 -= 2;
            v81->y = *v80;
            --v79;
          }
          while ( v79 != 0 );
        }
        v82 = v54 - 1;
        v83 = 1;
        if ( v54 - 1 > 1 )
        {
          if ( v54 - 2 >= 4 )
          {
            v84 = 0;
            do
            {
              *(float *)&v159[v84] = v157[v84 + 1].x;
              *((float *)&v159[v84] + 1) = v157[v84 + 1].y;
              v85 = v157[v84 + 2].y;
              v86 = v157[v84 + 3].x;
              *(float *)&v159[v84 + 1] = v157[v84 + 2].x;
              *((float *)&v159[v84 + 1] + 1) = v85;
              v87 = v157[v84 + 3].y;
              *(float *)&v159[v84 + 2] = v86;
              v83 += 4;
              v88 = v157[v84 + 4].x;
              *((float *)&v159[v84 + 2] + 1) = v87;
              v89 = v157[v84 + 4].y;
              *(float *)&v159[v84 + 3] = v88;
              *((float *)&v159[v84 + 3] + 1) = v89;
              v84 += 4;
            }
            while ( v83 < v54 - 4 );
          }
          if ( v83 < v82 )
          {
            v90 = v83;
            v91 = v82 - v83;
            do
            {
              v92 = v157[v90].y;
              *(float *)((char *)&v158.x + v90 * 8) = v157[v90].x;
              *(float *)((char *)&v158.y + v90 * 8) = v92;
              ++v90;
              --v91;
            }
            while ( v91 != 0 );
          }
        }
        v23 = v54 + v23 - 2;
      }
    }
    else if ( v54 != 0 )
    {
      if ( v54 > 0 )
      {
        v93 = 0;
        for ( i = v54; i != 0; --i )
        {
          v95 = v157[v93].y;
          *(float *)((char *)&v158.x + v93 * 8) = v157[v93].x;
          *(float *)((char *)&v158.y + v93 * 8) = v95;
          ++v93;
        }
      }
      v23 = v54;
    }
    v96 = v23 - 1;
    v97 = 0;
    if ( v23 - 1 >= 4 )
    {
      v98 = (float *)v159 + 1;
      do
      {
        numDebugLines = this->numDebugLines;
        if ( numDebugLines < this->maxDebugLines - 1 )
        {
          v100 = this->debugLines;
          if ( v100 != nullptr )
          {
            v101 = &v100[numDebugLines];
            this->numDebugLines = numDebugLines + 1;
            v101->color = COLOR_CYAN;
            v102 = *(v98 - 2);
            v101->start.x = *(v98 - 3);
            v101->start.y = v102;
            v101->start.z = 0.0;
            v103 = *v98;
            v101->end.x = *(v98 - 1);
            v101->end.y = v103;
            v101->end.z = 0.0;
            this->debugLines[this->numDebugLines].color = COLOR_INVALID;
          }
        }
        v104 = this->numDebugLines;
        if ( v104 < this->maxDebugLines - 1 )
        {
          v105 = this->debugLines;
          if ( v105 != nullptr )
          {
            v106 = &v105[v104];
            this->numDebugLines = v104 + 1;
            v106->color = COLOR_CYAN;
            v107 = *v98;
            v106->start.x = *(v98 - 1);
            v106->start.y = v107;
            v106->start.z = 0.0;
            v108 = v98[2];
            v106->end.x = v98[1];
            v106->end.y = v108;
            v106->end.z = 0.0;
            this->debugLines[this->numDebugLines].color = COLOR_INVALID;
          }
        }
        v109 = this->numDebugLines;
        if ( v109 < this->maxDebugLines - 1 )
        {
          v110 = this->debugLines;
          if ( v110 != nullptr )
          {
            v111 = &v110[v109];
            this->numDebugLines = v109 + 1;
            v111->color = COLOR_CYAN;
            v112 = v98[2];
            v111->start.x = v98[1];
            v111->start.y = v112;
            v111->start.z = 0.0;
            v113 = v98[4];
            v111->end.x = v98[3];
            v111->end.y = v113;
            v111->end.z = 0.0;
            this->debugLines[this->numDebugLines].color = COLOR_INVALID;
          }
        }
        v114 = this->numDebugLines;
        if ( v114 < this->maxDebugLines - 1 )
        {
          v115 = this->debugLines;
          if ( v115 != nullptr )
          {
            v116 = &v115[v114];
            this->numDebugLines = v114 + 1;
            v116->color = COLOR_CYAN;
            v117 = v98[4];
            v116->start.x = v98[3];
            v116->start.y = v117;
            v116->start.z = 0.0;
            v118 = v98[6];
            v116->end.x = v98[5];
            v116->end.y = v118;
            v116->end.z = 0.0;
            this->debugLines[this->numDebugLines].color = COLOR_INVALID;
          }
        }
        v97 += 4;
        v98 += 8;
      }
      while ( v97 < v23 - 4 );
    }
    if ( v97 < v96 )
    {
      v119 = (float *)&v159[v97] + 1;
      v120 = v96 - v97;
      do
      {
        v121 = this->numDebugLines;
        if ( v121 < this->maxDebugLines - 1 )
        {
          v122 = this->debugLines;
          if ( v122 != nullptr )
          {
            v123 = &v122[v121];
            this->numDebugLines = v121 + 1;
            v123->color = COLOR_CYAN;
            v124 = *(v119 - 2);
            v123->start.x = *(v119 - 3);
            v123->start.y = v124;
            v123->start.z = 0.0;
            v125 = *v119;
            v126 = *(v119 - 1);
            v123->end.z = 0.0;
            v123->end.x = v126;
            v123->end.y = v125;
            this->debugLines[this->numDebugLines].color = COLOR_INVALID;
          }
        }
        v119 += 2;
        --v120;
      }
      while ( v120 != 0 );
    }
    if ( v23 != 0 || v54 != 0 )
    {
      v127 = this->numDebugLines;
      v128 = path->seekPos[0].y;
      v129 = (float)(path->seekPos[0].x + (float)16.0);
      v130 = (float)(path->seekPos[0].x - (float)16.0);
      if ( v127 < this->maxDebugLines - 1 )
      {
        v131 = this->debugLines;
        if ( v131 != nullptr )
        {
          v132 = &v131[v127];
          this->numDebugLines = v127 + 1;
          v132->color = COLOR_CYAN;
          v132->start.x = v130;
          v132->start.y = v128;
          v132->start.z = 0.0;
          v132->end.x = v129;
          v132->end.y = v128;
          v132->end.z = 0.0;
          this->debugLines[this->numDebugLines].color = COLOR_INVALID;
        }
      }
      v133 = this->numDebugLines;
      v134 = (float)(path->seekPos[0].y + (float)16.0);
      v135 = path->seekPos[0].x;
      v136 = (float)(path->seekPos[0].y - (float)16.0);
      if ( v133 < this->maxDebugLines - 1 )
      {
        v137 = this->debugLines;
        if ( v137 != nullptr )
        {
          v138 = &v137[v133];
          this->numDebugLines = v133 + 1;
          v138->color = COLOR_CYAN;
          v138->start.x = v135;
          v138->start.y = v136;
          v138->start.z = 0.0;
          v138->end.x = v135;
          v138->end.y = v134;
          v138->end.z = 0.0;
          this->debugLines[this->numDebugLines].color = COLOR_INVALID;
        }
      }
      v139 = this->numDebugLines;
      v140 = (float)(v10->x + (float)16.0);
      v141 = v10->y;
      v142 = (float)(v10->x - (float)16.0);
      if ( v139 < this->maxDebugLines - 1 )
      {
        v143 = this->debugLines;
        if ( v143 != nullptr )
        {
          v144 = &v143[v139];
          this->numDebugLines = v139 + 1;
          v144->color = COLOR_CYAN;
          v144->start.x = v142;
          v144->start.y = v141;
          v144->start.z = 0.0;
          v144->end.x = v140;
          v144->end.y = v141;
          v144->end.z = 0.0;
          this->debugLines[this->numDebugLines].color = COLOR_INVALID;
        }
      }
      v145 = this->numDebugLines;
      v146 = (float)(v10->y + (float)16.0);
      v147 = v10->x;
      v148 = (float)(v10->y - (float)16.0);
      if ( v145 < this->maxDebugLines - 1 )
      {
        v149 = this->debugLines;
        if ( v149 != nullptr )
        {
          v150 = &v149[v145];
          this->numDebugLines = v145 + 1;
          v150->color = COLOR_CYAN;
          v150->start.x = v147;
          v150->start.y = v148;
          v150->start.z = 0.0;
          v150->end.x = v147;
          v150->end.y = v146;
          v150->end.z = 0.0;
          this->debugLines[this->numDebugLines].color = COLOR_INVALID;
        }
      }
    }
  }
}


// ========================================================================
// ?CircleApproachDestination@idObstacleAvoidanceCore@@AAAXPAUobstaclePath_t@@PBUobstacleRoute_t@@M@Z
// EA  : 0x826C6718
// RVA : 0x006C6718
// PDB : w:\tech5\engine\gamelib\aas2\obstacleavoidancecore.cpp
// ========================================================================

void __fastcall idObstacleAvoidanceCore::CircleApproachDestination(
        idObstacleAvoidanceCore *this,
        idVec2 *path,
        const obstacleRoute_t *route,
        double frameMoveDist)
{
  double v4; // fp13
  int v5; // r11
  double x; // fp12
  __int64 v11; // r27
  double endTurnRadius; // fp1
  bool v13; // r28
  double v14; // fp10
  double v15; // fp0
  double v16; // fp3
  double v17; // fp2
  double v18; // fp8
  double v21; // fp9
  double v22; // fp9
  double v23; // fp0
  double v24; // fp13
  double v25; // fp9
  int *v26; // r8
  idVec3 *v27; // r7
  int v28; // r5
  int v29; // r5
  int v30; // r6
  float *v31; // r11
  int numDebugLines; // r9
  avoidDebugLine_t *debugLines; // r8
  avoidDebugLine_t *v34; // r10
  double v35; // fp0
  double v36; // fp12
  int v37; // r9
  avoidDebugLine_t *v38; // r8
  avoidDebugLine_t *v39; // r10
  double v40; // fp13
  double v41; // fp12
  int v42; // r9
  avoidDebugLine_t *v43; // r8
  avoidDebugLine_t *v44; // r10
  double v45; // fp0
  double v46; // fp12
  int v47; // r9
  avoidDebugLine_t *v48; // r8
  avoidDebugLine_t *v49; // r10
  double v50; // fp0
  double v51; // fp12
  float *v52; // r10
  int v53; // ctr
  int v54; // r9
  avoidDebugLine_t *v55; // r8
  avoidDebugLine_t *v56; // r11
  double v57; // fp13
  double v58; // fp11
  idVec2 v59; // [sp+50h] [-270h] BYREF
  int v60[2]; // [sp+58h] [-268h] BYREF
  idVec2 v61; // [sp+60h] [-260h] BYREF
  unsigned __int64 v62; // [sp+68h] [-258h] BYREF
  idVec2 v63[16]; // [sp+70h] [-250h] BYREF
  unsigned __int64 v64; // [sp+F0h] [-1D0h] BYREF
  _QWORD v65[48]; // [sp+F8h] [-1C8h] BYREF

  v4 = -route->endAlignDir.y;
  v5 = 28 * route->numAreas;
  x = route->endAlignDir.x;
  v59 = path[51];
  v11 = *(_QWORD *)((char *)&route->endAlignDir.y + v5);
  HIDWORD(v11) = 0;
  v62 = (unsigned int)v11;
  endTurnRadius = route->endTurnRadius;
  v13 = (float)((float)((float)(*((float *)&v11 + 1) - v59.y) * (float)x)
              + (float)((float)((float)0.0 - v59.x) * (float)v4)) > 0.0;
  v14 = (float)(route->endTurnRadius + (float)1.0);
  if ( (float)((float)((float)(*((float *)&v11 + 1) - v59.y) * (float)x)
             + (float)((float)((float)0.0 - v59.x) * (float)v4)) <= 0.0 )
    v15 = (float)(route->endTurnRadius + (float)1.0);
  else
    v15 = -v14;
  v16 = (float)((float)(route->endTurnRadius + (float)1.0) * (float)0.75);
  v61.x = (float)((float)v4 * (float)v15) + (float)0.0;
  v61.y = (float)((float)x * (float)v15) + *((float *)&v11 + 1);
  v17 = (float)(v59.x - v61.x);
  v18 = (float)(v59.y - v61.y);
  _FP5 = (float)((float)((float)((float)(v59.y - v61.y) * (float)(v59.y - v61.y))
                       + (float)((float)(v59.x - v61.x) * (float)(v59.x - v61.x)))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f13, f5, f6, f13 }
  v21 = __frsqrte(_FP13);
  v22 = (float)((float)-(float)((float)((float)((float)v21
                                              * (float)((float)((float)((float)(v59.y - v61.y) * (float)(v59.y - v61.y))
                                                              + (float)((float)(v59.x - v61.x) * (float)(v59.x - v61.x)))
                                                      * (float)0.5))
                                      * (float)v21)
                              - (float)1.5)
              * (float)v21);
  v23 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v22
                                                                                              * (float)((float)((float)((float)v18 * (float)v18) + (float)((float)v17 * (float)v17)) * (float)0.5))
                                                                                      * (float)v22)
                                                                              - (float)1.5)
                                                              * (float)v22)
                                                      * (float)((float)((float)((float)v18 * (float)v18)
                                                                      + (float)((float)v17 * (float)v17))
                                                              * (float)0.5))
                                              * (float)((float)-(float)((float)((float)((float)v22
                                                                                      * (float)((float)((float)((float)v18 * (float)v18) + (float)((float)v17 * (float)v17))
                                                                                              * (float)0.5))
                                                                              * (float)v22)
                                                                      - (float)1.5)
                                                      * (float)v22))
                                      - (float)1.5)
                      * (float)((float)-(float)((float)((float)((float)v22
                                                              * (float)((float)((float)((float)v18 * (float)v18)
                                                                              + (float)((float)v17 * (float)v17))
                                                                      * (float)0.5))
                                                      * (float)v22)
                                              - (float)1.5)
                              * (float)v22))
              * (float)((float)((float)v18 * (float)v18) + (float)((float)v17 * (float)v17)));
  v24 = (float)((float)v17
              * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v22
                                                                                              * (float)((float)((float)((float)v18 * (float)v18) + (float)((float)v17 * (float)v17)) * (float)0.5))
                                                                                      * (float)v22)
                                                                              - (float)1.5)
                                                              * (float)v22)
                                                      * (float)((float)((float)((float)v18 * (float)v18)
                                                                      + (float)((float)v17 * (float)v17))
                                                              * (float)0.5))
                                              * (float)((float)-(float)((float)((float)((float)v22
                                                                                      * (float)((float)((float)((float)v18 * (float)v18) + (float)((float)v17 * (float)v17))
                                                                                              * (float)0.5))
                                                                              * (float)v22)
                                                                      - (float)1.5)
                                                      * (float)v22))
                                      - (float)1.5)
                      * (float)((float)-(float)((float)((float)((float)v22
                                                              * (float)((float)((float)((float)v18 * (float)v18)
                                                                              + (float)((float)v17 * (float)v17))
                                                                      * (float)0.5))
                                                      * (float)v22)
                                              - (float)1.5)
                              * (float)v22)));
  v25 = (float)((float)v18
              * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v22
                                                                                              * (float)((float)((float)((float)v18 * (float)v18) + (float)((float)v17 * (float)v17)) * (float)0.5))
                                                                                      * (float)v22)
                                                                              - (float)1.5)
                                                              * (float)v22)
                                                      * (float)((float)((float)((float)v18 * (float)v18)
                                                                      + (float)((float)v17 * (float)v17))
                                                              * (float)0.5))
                                              * (float)((float)-(float)((float)((float)((float)v22
                                                                                      * (float)((float)((float)((float)v18 * (float)v18) + (float)((float)v17 * (float)v17))
                                                                                              * (float)0.5))
                                                                              * (float)v22)
                                                                      - (float)1.5)
                                                      * (float)v22))
                                      - (float)1.5)
                      * (float)((float)-(float)((float)((float)((float)v22
                                                              * (float)((float)((float)((float)v18 * (float)v18)
                                                                              + (float)((float)v17 * (float)v17))
                                                                      * (float)0.5))
                                                      * (float)v22)
                                              - (float)1.5)
                              * (float)v22)));
  if ( v23 > v16 && v23 < v14 )
  {
    v59.x = (float)((float)v24 * (float)v14) + v61.x;
    v59.y = (float)((float)v25 * (float)v14) + v61.y;
  }
  idObstacleAvoidanceCore::GetCirclePoints(center: &v61, radius: endTurnRadius, circlePoints: path, a4: &v63[0].x);
  v65[0] = v11;
  v60[0] = 2;
  v64 = __PAIR64__(v60, LODWORD(v59.y));
  v27 = (idVec3 *)(unsigned __int8)idObstacleAvoidanceCore::PathAroundCircle(
                                     this,
                                     startPos: &v59,
                                     corner: &v61,
                                     endPos: (const idVec2 *)&v62,
                                     circlePoints: v63,
                                     clockWise: v13,
                                     pathPoints: (idVec2 *)&v64,
                                     numPathPoints: v60);
  if ( v27 != nullptr )
  {
    idObstacleAvoidanceCore::GetSeekPointsOnPath(
      this,
      pathPoints: (const idVec2 *)&v64,
      numPathPoints: v60[0],
      corner: &v61,
      radius: route->endTurnRadius,
      frameMoveDist,
      seekPos: v27,
      outNumSeekPos: v26,
      a9: (int)path,
      a10: (int *)&path[46].y);
    if ( this->debugLines != nullptr )
    {
      v29 = v28 - 1;
      v30 = 0;
      if ( v29 >= 4 )
      {
        v31 = (float *)v65 + 1;
        do
        {
          numDebugLines = this->numDebugLines;
          if ( numDebugLines < this->maxDebugLines - 1 )
          {
            debugLines = this->debugLines;
            if ( debugLines != nullptr )
            {
              v34 = &debugLines[numDebugLines];
              this->numDebugLines = numDebugLines + 1;
              v34->color = COLOR_CYAN;
              v35 = *(v31 - 2);
              v34->start.x = *(v31 - 3);
              v34->start.y = v35;
              v34->start.z = 0.0;
              v36 = *v31;
              v34->end.x = *(v31 - 1);
              v34->end.y = v36;
              v34->end.z = 0.0;
              this->debugLines[this->numDebugLines].color = COLOR_INVALID;
            }
          }
          v37 = this->numDebugLines;
          if ( v37 < this->maxDebugLines - 1 )
          {
            v38 = this->debugLines;
            if ( v38 != nullptr )
            {
              v39 = &v38[v37];
              this->numDebugLines = v37 + 1;
              v39->color = COLOR_CYAN;
              v40 = *v31;
              v39->start.x = *(v31 - 1);
              v39->start.y = v40;
              v39->start.z = 0.0;
              v41 = v31[2];
              v39->end.x = v31[1];
              v39->end.y = v41;
              v39->end.z = 0.0;
              this->debugLines[this->numDebugLines].color = COLOR_INVALID;
            }
          }
          v42 = this->numDebugLines;
          if ( v42 < this->maxDebugLines - 1 )
          {
            v43 = this->debugLines;
            if ( v43 != nullptr )
            {
              v44 = &v43[v42];
              this->numDebugLines = v42 + 1;
              v44->color = COLOR_CYAN;
              v45 = v31[2];
              v44->start.x = v31[1];
              v44->start.y = v45;
              v44->start.z = 0.0;
              v46 = v31[4];
              v44->end.x = v31[3];
              v44->end.y = v46;
              v44->end.z = 0.0;
              this->debugLines[this->numDebugLines].color = COLOR_INVALID;
            }
          }
          v47 = this->numDebugLines;
          if ( v47 < this->maxDebugLines - 1 )
          {
            v48 = this->debugLines;
            if ( v48 != nullptr )
            {
              v49 = &v48[v47];
              this->numDebugLines = v47 + 1;
              v49->color = COLOR_CYAN;
              v50 = v31[4];
              v49->start.x = v31[3];
              v49->start.y = v50;
              v49->start.z = 0.0;
              v51 = v31[6];
              v49->end.x = v31[5];
              v49->end.y = v51;
              v49->end.z = 0.0;
              this->debugLines[this->numDebugLines].color = COLOR_INVALID;
            }
          }
          v30 += 4;
          v31 += 8;
        }
        while ( v30 < v29 - 3 );
      }
      if ( v30 < v29 )
      {
        v52 = (float *)&v65[v30] + 1;
        v53 = v29 - v30;
        do
        {
          v54 = this->numDebugLines;
          if ( v54 < this->maxDebugLines - 1 )
          {
            v55 = this->debugLines;
            if ( v55 != nullptr )
            {
              v56 = &v55[v54];
              this->numDebugLines = v54 + 1;
              v56->color = COLOR_CYAN;
              v57 = *(v52 - 3);
              v56->start.y = *(v52 - 2);
              v56->start.z = 0.0;
              v56->start.x = v57;
              v58 = *(v52 - 1);
              v56->end.y = *v52;
              v56->end.x = v58;
              v56->end.z = 0.0;
              this->debugLines[this->numDebugLines].color = COLOR_INVALID;
            }
          }
          v52 += 2;
          --v53;
        }
        while ( v53 != 0 );
      }
    }
  }
}


// ========================================================================
// ?UpdateRadar@idObstacleAvoidanceCore@@AAAXPAUobstaclePath_t@@M@Z
// EA  : 0x826C6B80
// RVA : 0x006C6B80
// PDB : w:\tech5\engine\gamelib\aas2\obstacleavoidancecore.cpp
// ========================================================================

void __fastcall idObstacleAvoidanceCore::UpdateRadar(
        idObstacleAvoidanceCore *this,
        obstaclePath_t *path,
        double frameMoveDist)
{
  idVec2 *p_radarForward; // r11
  double v7; // fp9
  double y; // fp29
  double v9; // fp28
  double x; // fp30
  double v13; // fp4
  double v14; // fp7
  double v15; // fp4
  obstaclePath_t::radar_t *radar; // r28
  obstaclePath_t::radar_t *v17; // r27
  obstaclePath_t::radar_t *v18; // r24
  obstaclePath_t::radar_t *v19; // r23
  obstaclePath_t::radar_t *v20; // r22
  obstaclePath_t::radar_t *v21; // r20
  obstaclePath_t::radar_t *v22; // r19
  obstaclePath_t::radar_t *v23; // r30
  int v24; // r26
  double v25; // fp10
  double v26; // fp9
  double v27; // fp12
  double v28; // fp0
  int v29; // r10
  obstaclePath_t::radar_t *v31; // r30
  int v32; // r26
  double v34; // fp11
  double v35; // fp0
  int v36; // r10
  double v37; // fp13
  int numDebugLines; // r10
  double v39; // fp0
  int v40; // r11
  double v41; // fp12
  double v42; // fp11
  double v43; // fp12
  double v44; // fp11
  avoidDebugLine_t *debugLines; // r9
  avoidDebugLine_t *v46; // r11
  double v47; // fp0
  int v48; // r10
  double v49; // fp12
  double v50; // fp11
  avoidDebugLine_t *v51; // r9
  avoidDebugLine_t *v52; // r11
  double v53; // fp0
  int v54; // r10
  double v55; // fp12
  double v56; // fp11
  avoidDebugLine_t *v57; // r9
  avoidDebugLine_t *v58; // r11
  double v59; // fp0
  int v60; // r10
  double v61; // fp12
  double v62; // fp11
  avoidDebugLine_t *v63; // r9
  avoidDebugLine_t *v64; // r11
  double v65; // fp0
  int v66; // r10
  double v67; // fp12
  double v68; // fp11
  avoidDebugLine_t *v69; // r9
  avoidDebugLine_t *v70; // r11
  double v71; // fp0
  int v72; // r10
  double v73; // fp12
  double v74; // fp11
  avoidDebugLine_t *v75; // r9
  avoidDebugLine_t *v76; // r11
  double v77; // fp0
  int v78; // r10
  double v79; // fp13
  double v80; // fp0
  avoidDebugLine_t *v81; // r9
  avoidDebugLine_t *v82; // r11
  double v83; // fp12
  int v84; // [sp+50h] [-B0h] BYREF
  float v85; // [sp+54h] [-ACh] BYREF
  int v86[2]; // [sp+58h] [-A8h] BYREF
  idVec2 v87; // [sp+60h] [-A0h] BYREF

  if ( path->useRadarForward )
  {
    p_radarForward = (idVec2 *)&path->radarForward;
  }
  else
  {
    p_radarForward = &v87;
    v7 = (float)(path->seekPos[0].y - path->startPosOutsideObstacles.y);
    v87.x = path->seekPos[0].x - path->startPosOutsideObstacles.x;
    v87.y = v7;
  }
  v87 = *p_radarForward;
  if ( LODWORD(v87.x) != 0 )
  {
    y = v87.y;
    v9 = frameMoveDist;
    x = v87.x;
  }
  else
  {
    _FP7 = (float)((float)((float)(0.0 * 0.0) + (float)(v87.y * v87.y)) - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm { fsel      f5, f7, f8, f12 }
    v13 = __frsqrte(_FP5);
    v14 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v13
                                                                                        * (float)((float)((float)(0.0 * 0.0) + (float)(v87.y * v87.y))
                                                                                                * (float)0.5))
                                                                                * (float)v13)
                                                                        - (float)1.5)
                                                        * (float)v13)
                                                * (float)((float)((float)(0.0 * 0.0) + (float)(v87.y * v87.y))
                                                        * (float)0.5))
                                        * (float)((float)-(float)((float)((float)((float)v13
                                                                                * (float)((float)((float)(0.0 * 0.0)
                                                                                                + (float)(v87.y * v87.y))
                                                                                        * (float)0.5))
                                                                        * (float)v13)
                                                                - (float)1.5)
                                                * (float)v13))
                                - (float)1.5)
                * (float)((float)-(float)((float)((float)((float)v13
                                                        * (float)((float)((float)(0.0 * 0.0) + (float)(v87.y * v87.y))
                                                                * (float)0.5))
                                                * (float)v13)
                                        - (float)1.5)
                        * (float)v13));
    v15 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v13 * (float)((float)((float)(0.0 * 0.0) + (float)(v87.y * v87.y)) * (float)0.5)) * (float)v13) - (float)1.5)
                                                                                                * (float)v13)
                                                                                        * (float)((float)((float)(0.0 * 0.0) + (float)(v87.y * v87.y))
                                                                                                * (float)0.5))
                                                                                * (float)((float)-(float)((float)((float)((float)v13 * (float)((float)((float)(0.0 * 0.0) + (float)(v87.y * v87.y)) * (float)0.5)) * (float)v13) - (float)1.5)
                                                                                        * (float)v13))
                                                                        - (float)1.5)
                                                        * (float)((float)-(float)((float)((float)((float)v13
                                                                                                * (float)((float)((float)(0.0 * 0.0) + (float)(v87.y * v87.y)) * (float)0.5))
                                                                                        * (float)v13)
                                                                                - (float)1.5)
                                                                * (float)v13))
                                                * (float)((float)((float)(0.0 * 0.0) + (float)(v87.y * v87.y))
                                                        * (float)0.5))
                                        * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v13 * (float)((float)((float)(0.0 * 0.0) + (float)(v87.y * v87.y)) * (float)0.5)) * (float)v13) - (float)1.5)
                                                                                        * (float)v13)
                                                                                * (float)((float)((float)(0.0 * 0.0)
                                                                                                + (float)(v87.y * v87.y))
                                                                                        * (float)0.5))
                                                                        * (float)((float)-(float)((float)((float)((float)v13 * (float)((float)((float)(0.0 * 0.0) + (float)(v87.y * v87.y)) * (float)0.5)) * (float)v13)
                                                                                                - (float)1.5)
                                                                                * (float)v13))
                                                                - (float)1.5)
                                                * (float)((float)-(float)((float)((float)((float)v13
                                                                                        * (float)((float)((float)(0.0 * 0.0) + (float)(v87.y * v87.y))
                                                                                                * (float)0.5))
                                                                                * (float)v13)
                                                                        - (float)1.5)
                                                        * (float)v13)))
                                - (float)1.5)
                * (float)v14);
    x = (float)((float)v15 * 0.0);
    y = (float)((float)v15 * v87.y);
    v9 = (float)((float)v15 * (float)((float)(0.0 * 0.0) + (float)(v87.y * v87.y)));
  }
  if ( v9 <= 0.0 )
  {
    x = 0.0;
    y = 1.0;
  }
  radar = path->radar;
  v17 = &path->radar[1];
  v18 = &path->radar[2];
  path->radar[0].direction.z = -0.0;
  v19 = &path->radar[3];
  v20 = &path->radar[4];
  v21 = &path->radar[5];
  v22 = &path->radar[6];
  v23 = path->radar;
  v24 = 7;
  v25 = -(float)((float)y * (float)256.0);
  path->radar[0].direction.y = v25;
  v26 = -(float)((float)x * (float)256.0);
  path->radar[0].direction.x = v26;
  path->radar[1].direction.y = (float)x * (float)256.0;
  path->radar[1].direction.z = 0.0;
  path->radar[1].direction.x = v25;
  path->radar[2].direction.y = v26;
  path->radar[2].direction.z = -0.0;
  path->radar[2].direction.x = -v25;
  path->radar[3].direction.x = (float)v25 + (float)((float)x * (float)256.0);
  path->radar[3].direction.y = (float)((float)y * (float)256.0) + (float)((float)x * (float)256.0);
  path->radar[3].direction.z = 0.0;
  path->radar[4].direction.x = (float)((float)x * (float)256.0) - (float)v25;
  path->radar[4].direction.y = (float)((float)y * (float)256.0) - (float)((float)x * (float)256.0);
  path->radar[4].direction.z = 0.0;
  path->radar[5].direction.x = (float)v26 + (float)v25;
  path->radar[5].direction.y = (float)v25 + (float)((float)x * (float)256.0);
  path->radar[5].direction.z = 0.0;
  path->radar[6].direction.x = (float)v26 - (float)v25;
  path->radar[6].direction.y = (float)v25 - (float)((float)x * (float)256.0);
  path->radar[6].direction.z = -0.0;
  v87 = *(idVec2 *)&path->startPosOutsideObstacles.x;
  do
  {
    v84 = -1;
    if ( idObstacleAvoidanceCore::GetFirstBlockingObstacle(
           this,
           start: &v87,
           delta: (const idVec2 *)v23,
           skipObstacle: -1,
           blockingScale: &v85,
           blockingObstacle: &v84,
           blockingEdgeNum: v86) )
    {
      v27 = v23->direction.y;
      v28 = v85;
      v29 = v84;
      v23->direction.x = v23->direction.x * v85;
      v23->direction.y = (float)v27 * (float)v28;
      v23->obstacle = this->expandedObstacles[v29].id;
    }
    else
    {
      v23->obstacle = -1;
    }
    --v24;
    ++v23;
  }
  while ( v24 != 0 );
  _FP0 = (float)((float)v9 - (float)frameMoveDist);
  v31 = &path->radar[1];
  v32 = 2;
  __asm { fsel      f11, f0, f27, f28 }
  v87.x = (float)((float)_FP11 * (float)x) + v87.x;
  v87.y = v87.y + (float)((float)_FP11 * (float)y);
  do
  {
    v84 = -1;
    if ( idObstacleAvoidanceCore::GetFirstBlockingObstacle(
           this,
           start: &v87,
           delta: (const idVec2 *)v31,
           skipObstacle: -1,
           blockingScale: &v85,
           blockingObstacle: &v84,
           blockingEdgeNum: v86) )
    {
      v34 = v31->direction.x;
      v35 = v85;
      v36 = v84;
      v31->direction.y = v31->direction.y * v85;
      v31->direction.x = (float)v34 * (float)v35;
      v31->obstacle = this->expandedObstacles[v36].id;
    }
    else
    {
      v31->obstacle = -1;
    }
    --v32;
    ++v31;
  }
  while ( v32 != 0 );
  if ( this->debugLines != nullptr )
  {
    v37 = path->startPosOutsideObstacles.x;
    numDebugLines = this->numDebugLines;
    v39 = path->startPosOutsideObstacles.y;
    v40 = this->maxDebugLines - 1;
    v41 = radar->direction.x;
    v42 = path->radar[0].direction.y;
    v87.y = path->startPosOutsideObstacles.y;
    v87.x = v37;
    v43 = (float)((float)v41 + (float)v37);
    v44 = (float)((float)v42 + (float)v39);
    if ( numDebugLines < v40 )
    {
      debugLines = this->debugLines;
      if ( debugLines != nullptr )
      {
        v46 = &debugLines[numDebugLines];
        this->numDebugLines = numDebugLines + 1;
        v46->color = COLOR_ORANGE;
        v47 = v87.y;
        v46->start.x = v87.x;
        v46->start.y = v47;
        v46->start.z = 0.0;
        v46->end.x = v43;
        v46->end.y = v44;
        v46->end.z = 0.0;
        this->debugLines[this->numDebugLines].color = COLOR_INVALID;
        v39 = v87.y;
        v37 = v87.x;
      }
    }
    v48 = this->numDebugLines;
    v49 = (float)(v17->direction.x + (float)v37);
    v50 = (float)(path->radar[1].direction.y + (float)v39);
    if ( v48 < this->maxDebugLines - 1 )
    {
      v51 = this->debugLines;
      if ( v51 != nullptr )
      {
        v52 = &v51[v48];
        this->numDebugLines = v48 + 1;
        v52->color = COLOR_ORANGE;
        v53 = v87.y;
        v52->start.x = v87.x;
        v52->start.y = v53;
        v52->start.z = 0.0;
        v52->end.x = v49;
        v52->end.y = v50;
        v52->end.z = 0.0;
        this->debugLines[this->numDebugLines].color = COLOR_INVALID;
        v39 = v87.y;
        v37 = v87.x;
      }
    }
    v54 = this->numDebugLines;
    v55 = (float)(v18->direction.x + (float)v37);
    v56 = (float)(path->radar[2].direction.y + (float)v39);
    if ( v54 < this->maxDebugLines - 1 )
    {
      v57 = this->debugLines;
      if ( v57 != nullptr )
      {
        v58 = &v57[v54];
        this->numDebugLines = v54 + 1;
        v58->color = COLOR_ORANGE;
        v59 = v87.y;
        v58->start.x = v87.x;
        v58->start.y = v59;
        v58->start.z = 0.0;
        v58->end.x = v55;
        v58->end.y = v56;
        v58->end.z = 0.0;
        this->debugLines[this->numDebugLines].color = COLOR_INVALID;
        v37 = v87.x;
        v39 = v87.y;
      }
    }
    v60 = this->numDebugLines;
    v61 = (float)(v19->direction.x + (float)v37);
    v62 = (float)(path->radar[3].direction.y + (float)v39);
    if ( v60 < this->maxDebugLines - 1 )
    {
      v63 = this->debugLines;
      if ( v63 != nullptr )
      {
        v64 = &v63[v60];
        this->numDebugLines = v60 + 1;
        v64->color = COLOR_ORANGE;
        v65 = v87.y;
        v64->start.x = v87.x;
        v64->start.y = v65;
        v64->start.z = 0.0;
        v64->end.x = v61;
        v64->end.y = v62;
        v64->end.z = 0.0;
        this->debugLines[this->numDebugLines].color = COLOR_INVALID;
        v39 = v87.y;
        v37 = v87.x;
      }
    }
    v66 = this->numDebugLines;
    v67 = (float)(v20->direction.x + (float)v37);
    v68 = (float)(path->radar[4].direction.y + (float)v39);
    if ( v66 < this->maxDebugLines - 1 )
    {
      v69 = this->debugLines;
      if ( v69 != nullptr )
      {
        v70 = &v69[v66];
        this->numDebugLines = v66 + 1;
        v70->color = COLOR_ORANGE;
        v71 = v87.y;
        v70->start.x = v87.x;
        v70->start.y = v71;
        v70->start.z = 0.0;
        v70->end.x = v67;
        v70->end.y = v68;
        v70->end.z = 0.0;
        this->debugLines[this->numDebugLines].color = COLOR_INVALID;
        v39 = v87.y;
        v37 = v87.x;
      }
    }
    v72 = this->numDebugLines;
    v73 = (float)(v21->direction.x + (float)v37);
    v74 = (float)(path->radar[5].direction.y + (float)v39);
    if ( v72 < this->maxDebugLines - 1 )
    {
      v75 = this->debugLines;
      if ( v75 != nullptr )
      {
        v76 = &v75[v72];
        this->numDebugLines = v72 + 1;
        v76->color = COLOR_ORANGE;
        v77 = v87.y;
        v76->start.x = v87.x;
        v76->start.y = v77;
        v76->start.z = 0.0;
        v76->end.x = v73;
        v76->end.y = v74;
        v76->end.z = 0.0;
        this->debugLines[this->numDebugLines].color = COLOR_INVALID;
        v39 = v87.y;
        v37 = v87.x;
      }
    }
    v78 = this->numDebugLines;
    v79 = (float)(v22->direction.x + (float)v37);
    v80 = (float)(path->radar[6].direction.y + (float)v39);
    if ( v78 < this->maxDebugLines - 1 )
    {
      v81 = this->debugLines;
      if ( v81 != nullptr )
      {
        v82 = &v81[v78];
        this->numDebugLines = v78 + 1;
        v82->color = COLOR_ORANGE;
        v83 = v87.y;
        v82->start.x = v87.x;
        v82->start.y = v83;
        v82->start.z = 0.0;
        v82->end.x = v79;
        v82->end.y = v80;
        v82->end.z = 0.0;
        this->debugLines[this->numDebugLines].color = COLOR_INVALID;
      }
    }
  }
}


// ========================================================================
// ?BuildPathTree@idObstacleAvoidanceCore@@AAAPAUpathNode_t@1@ABVidVec3@@0MPAUobstaclePath_t@@@Z
// EA  : 0x826C7200
// RVA : 0x006C7200
// PDB : w:\tech5\engine\gamelib\aas2\obstacleavoidancecore.cpp
// ========================================================================

idObstacleAvoidanceCore::pathNode_t *__fastcall idObstacleAvoidanceCore::BuildPathTree(
        idObstacleAvoidanceCore *this,
        const idVec3 *startPos,
        const idVec2 *seekPos,
        double obstacleRadius,
        obstaclePath_t *path,
        int a6)
{
  int numPathNodes; // r11
  idObstacleAvoidanceCore::pathNode_t *pathNodes; // r10
  double x; // fp0
  double y; // fp13
  double v11; // fp29
  double v12; // fp28
  double v13; // fp10
  double v14; // fp27
  double v15; // fp26
  idObstacleAvoidanceCore::pathNode_t *v16; // r25
  idObstacleAvoidanceCore::pathNode_t *v19; // r18
  double v20; // fp9
  int numNodes; // r19
  double v22; // fp8
  idObstacleAvoidanceCore::pathNode_t *v23; // r22
  idObstacleAvoidanceCore::pathNode_t *v24; // r31
  double v25; // fp2
  idObstacleAvoidanceCore::pathNode_t *next; // r21
  float *p_x; // r27
  float *v28; // r26
  int v29; // r9
  int id; // r11
  __int64 v31; // r8
  double v32; // fp10
  int v33; // r10
  idObstacleAvoidanceCore::pathNode_t *v34; // r11
  idObstacleAvoidanceCore::pathNode_t *v35; // r11
  idObstacleAvoidanceCore::pathNode_t *v36; // r11
  double v37; // fp9
  idObstacleAvoidanceCore::pathNode_t *v38; // r10
  double v39; // fp8
  int v40; // r11
  int v41; // r11
  __int64 v42; // r8
  unsigned int v43; // r8
  idObstacleAvoidanceCore::pathNode_t *v44; // r11
  idObstacleAvoidanceCore::pathNode_t *v45; // r11
  int v46; // r4
  idObstacleAvoidanceCore::pathNode_t *v47; // r29
  int dir; // r10
  double v49; // fp9
  int v50; // r6
  double v51; // fp9
  __int64 v52; // r8
  int v53; // r10
  signed int numPoints; // r11
  int v55; // r9
  idQueueNode<idObstacleAvoidanceCore::pathNode_t> *p_queueNode; // r11
  int v57; // r7
  int v59; // [sp+50h] [-E0h] BYREF
  int v60; // [sp+54h] [-DCh] BYREF
  float v61[2]; // [sp+58h] [-D8h] BYREF
  idBounds v62[3]; // [sp+60h] [-D0h] BYREF

  numPathNodes = this->numPathNodes;
  pathNodes = this->pathNodes;
  x = startPos->x;
  y = startPos->y;
  v11 = (float)(startPos->x - (float)obstacleRadius);
  v12 = (float)(startPos->y - (float)obstacleRadius);
  v13 = (float)(startPos->z + (float)obstacleRadius);
  v62[0].b[0].z = startPos->z - (float)obstacleRadius;
  v62[0].b[1].z = v13;
  v14 = (float)((float)x + (float)obstacleRadius);
  v15 = (float)((float)y + (float)obstacleRadius);
  v16 = &pathNodes[numPathNodes];
  this->numPathNodes = numPathNodes + 1;
  v16->dir = 0;
  v16->pos.y = 0.0;
  v16->pos.x = 0.0;
  v16->delta.y = 0.0;
  v16->delta.x = 0.0;
  v16->numNodes = 0;
  v16->obstacle = -1;
  v16->edgeNum = -1;
  v16->children[1] = nullptr;
  v16->children[0] = nullptr;
  v19 = nullptr;
  v16->parent = nullptr;
  v20 = startPos->x;
  v16->pos.x = startPos->x;
  numNodes = 64;
  v22 = startPos->y;
  v23 = nullptr;
  v16->pos.y = startPos->y;
  v24 = v16;
  v25 = (float)(seekPos->y - (float)v22);
  v16->delta.x = seekPos->x - (float)v20;
  v16->delta.y = v25;
  v16->numNodes = 1;
  v16->queueNode.next = nullptr;
  next = nullptr;
  v16->queueNode.next = nullptr;
  while ( this->numPathNodes < this->maxPathNodes - 1 )
  {
    v24->queueNode.next = nullptr;
    if ( v19 != nullptr )
      v19->queueNode.next = v24;
    v19 = v24;
    if ( v24->numNodes >= 4 * numNodes )
      goto LABEL_39;
    p_x = &v24->delta.x;
    v28 = &v24->pos.x;
    if ( (float)((float)(v24->delta.x + v24->pos.x) - (float)10.0) < v11
      || (float)((float)(v24->delta.x + v24->pos.x) + (float)10.0) > v14
      || (float)((float)(v24->pos.y + v24->delta.y) - (float)10.0) < v12
      || (float)((float)(v24->pos.y + v24->delta.y) + (float)10.0) > v15 )
    {
      goto LABEL_39;
    }
    if ( idObstacleAvoidanceCore::GetFirstBlockingObstacle(
           this,
           start: &v24->pos,
           delta: &v24->delta,
           skipObstacle: v24->obstacle,
           blockingScale: v61,
           blockingObstacle: &v60,
           blockingEdgeNum: &v59) )
    {
      v29 = v60;
      id = this->expandedObstacles[v60].id;
      if ( id != -4 )
      {
        if ( *(_DWORD *)(a6 + 404) == -1 && id != -2 && id != -3 && id != -5 )
          *(_DWORD *)(a6 + 404) = id;
        HIDWORD(v31) = 0;
        v32 = (float)(v61[0] * v24->delta.y);
        *p_x = *p_x * v61[0];
        v24->delta.y = v32;
        v33 = this->numPathNodes;
        if ( v24->edgeNum == -1 )
        {
          v24->children[0] = &this->pathNodes[v33];
          ++this->numPathNodes;
          v34 = v24->children[0];
          v34->dir = 0;
          v34->pos.y = 0.0;
          v34->pos.x = 0.0;
          v34->delta.y = 0.0;
          v34->delta.x = 0.0;
          v34->obstacle = -1;
          v34->edgeNum = -1;
          v34->numNodes = 0;
          v34->children[1] = nullptr;
          v34->children[0] = nullptr;
          v34->parent = nullptr;
          v24->children[1] = &this->pathNodes[this->numPathNodes++];
          v35 = v24->children[1];
          v35->dir = 0;
          v35->pos.y = 0.0;
          v35->pos.x = 0.0;
          v35->delta.y = 0.0;
          v35->delta.x = 0.0;
          v35->obstacle = -1;
          v35->edgeNum = -1;
          v35->numNodes = 0;
          v35->children[1] = nullptr;
          v35->children[0] = nullptr;
          v35->parent = nullptr;
          v24->children[0]->dir = 0;
          v24->children[1]->dir = 1;
          v24->children[1]->parent = v24;
          v24->children[0]->parent = v24;
          v36 = v24->children[1];
          v37 = (float)(*p_x + *v28);
          v36->pos.y = v24->pos.y + v24->delta.y;
          v36->pos.x = v37;
          v38 = v24->children[0];
          v38->pos.x = v37;
          v39 = v36->pos.y;
          v40 = v59;
          v38->pos.y = v39;
          v24->children[1]->obstacle = v29;
          v24->children[0]->obstacle = v29;
          v24->children[1]->edgeNum = v40;
          v24->children[0]->edgeNum = v40;
          v41 = v24->numNodes + 1;
          v24->children[1]->numNodes = v41;
          v42 = (unsigned int)v24->children[0];
          *(_DWORD *)(v42 + 32) = v41;
          if ( (unsigned __int8)idObstacleAvoidanceCore::GetPathNodeDelta(
                                  this,
                                  node: v24->children[0],
                                  seekPos,
                                  clipBounds: v62,
                                  passedCorner: v42) != 0 )
          {
            v44 = v24->children[0];
            v44->queueNode.next = nullptr;
            if ( v23 != nullptr )
              v23->queueNode.next = v44;
            else
              next = v44;
            v23 = v44;
          }
          if ( (unsigned __int8)idObstacleAvoidanceCore::GetPathNodeDelta(
                                  this,
                                  node: v24->children[1],
                                  seekPos,
                                  clipBounds: v62,
                                  passedCorner: v43) != 0 )
          {
            v45 = v24->children[1];
            v45->queueNode.next = nullptr;
            if ( v23 != nullptr )
              v23->queueNode.next = v45;
            else
              next = v45;
            v23 = v45;
          }
          goto LABEL_39;
        }
        v46 = v59;
        LODWORD(v31) = 4 * (v24->dir + 10);
        v47 = &this->pathNodes[v33];
        *(int *)((char *)&v24->dir + v31) = (int)v47;
        ++this->numPathNodes;
        v47->dir = 0;
        v47->pos.y = 0.0;
        v47->pos.x = 0.0;
        v47->delta.y = 0.0;
        v47->delta.x = 0.0;
        v47->obstacle = -1;
        v47->edgeNum = -1;
        v47->numNodes = 0;
        v47->parent = nullptr;
        v47->children[1] = nullptr;
        v47->children[0] = nullptr;
        dir = v24->dir;
        v47->parent = v24;
        v47->dir = dir;
        v49 = (float)(v24->pos.y + v24->delta.y);
        v47->pos.x = *p_x + *v28;
        v47->pos.y = v49;
        v47->obstacle = v29;
        v47->edgeNum = v46;
        v47->numNodes = v24->numNodes + 1;
        if ( (unsigned __int8)idObstacleAvoidanceCore::GetPathNodeDelta(
                                this,
                                node: v47,
                                seekPos,
                                clipBounds: v62,
                                passedCorner: v31) != 0 )
        {
          v47->queueNode.next = nullptr;
          if ( v23 != nullptr )
          {
            v23->queueNode.next = v47;
LABEL_38:
            v23 = v47;
            goto LABEL_39;
          }
          goto LABEL_37;
        }
      }
    }
    else
    {
      v47 = &this->pathNodes[this->numPathNodes];
      v24->children[v24->dir] = v47;
      ++this->numPathNodes;
      v47->dir = 0;
      v47->pos.y = 0.0;
      v47->pos.x = 0.0;
      v47->delta.y = 0.0;
      v47->delta.x = 0.0;
      v47->children[0] = nullptr;
      v47->numNodes = 0;
      v47->parent = nullptr;
      v47->obstacle = -1;
      v47->edgeNum = -1;
      v47->children[1] = nullptr;
      v50 = v24->dir;
      v47->parent = v24;
      v47->dir = v50;
      v51 = (float)(*p_x + *v28);
      v47->pos.y = v24->pos.y + v24->delta.y;
      v47->pos.x = v51;
      v47->numNodes = v24->numNodes + 1;
      if ( v24->edgeNum == -1 )
      {
        if ( v24->numNodes < numNodes )
          numNodes = v24->numNodes;
        goto LABEL_39;
      }
      HIDWORD(v52) = 1;
      v47->obstacle = v24->obstacle;
      v53 = 2 * v24->dir + v24->edgeNum;
      numPoints = this->expandedObstacles[v24->obstacle].numPoints;
      __twllei(numPoints, 0);
      v55 = v53 + numPoints - 1;
      LODWORD(v52) = __ROL4__(v55, 1) - 1;
      v47->edgeNum = v55 % numPoints;
      __twlgei(numPoints & ~(_DWORD)v52, 0xFFFFFFFF);
      if ( (unsigned __int8)idObstacleAvoidanceCore::GetPathNodeDelta(
                              this,
                              node: v47,
                              seekPos,
                              clipBounds: v62,
                              passedCorner: v52) != 0 )
      {
        v47->queueNode.next = nullptr;
        if ( v23 != nullptr )
        {
          v23->queueNode.next = v47;
          goto LABEL_38;
        }
LABEL_37:
        next = v47;
        goto LABEL_38;
      }
    }
LABEL_39:
    v24 = next;
    if ( next != nullptr )
    {
      p_queueNode = &next->queueNode;
      v57 = (next == v23) - 1;
      next = next->queueNode.next;
      v23 = (idObstacleAvoidanceCore::pathNode_t *)(v57 & (unsigned int)v23);
      p_queueNode->next = nullptr;
    }
    if ( v24 == nullptr )
      return v16;
  }
  return v16;
}


// ========================================================================
// ?FindPathAroundObstacles@idObstacleAvoidanceCore@@QAAXPAUobstaclePath_t@@PAUavoidDebugLine_t@@HPAUavoidDebugText_t@@HPAXHABVidBounds@@ABVidVec3@@5ABVidVec4@@MMMHPBUobstacleRoute_t@@PBUobstacleBox_t@@HPBUobstacleVertex_t@@HPBUobstacleEdge_t@@HPBUobstacleCorner_t@@HPBUobstacleTrace_t@@HPAM@Z
// EA  : 0x826C7838
// RVA : 0x006C7838
// PDB : w:\tech5\engine\gamelib\aas2\obstacleavoidancecore.cpp
// ========================================================================

void __fastcall idObstacleAvoidanceCore::FindPathAroundObstacles(
        idObstacleAvoidanceCore *this,
        obstaclePath_t *path,
        avoidDebugLine_t *debugLines,
        int maxDebugLines,
        avoidDebugText_t *debugText,
        int maxDebugText,
        char *temp,
        int tempSize,
        double obstacleRadius,
        double frameMoveDist,
        double cornerCircleRadius,
        const idBounds *bbox,
        const idVec3 *gravity,
        const idVec3 *lastDir,
        const idVec4 *lastCorner,
        const int flags,
        const obstacleRoute_t *route,
        const obstacleBox_t *obstacles,
        int numObstacles,
        const obstacleVertex_t *vertices,
        int numVertices,
        const obstacleEdge_t *edges,
        int numEdges,
        const obstacleCorner_t *corners,
        int numCorners,
        const obstacleTrace_t *traces,
        int numTraces,
        float *traceFractions,
        int a29,
        int a30,
        const idBounds *a31,
        int a32,
        const idVec3 *a33,
        int a34,
        float *a35,
        int a36,
        float *a37,
        int a38,
        const idBounds *bboxa,
        int a40,
        const idVec3 *gravitya,
        int a42,
        const idVec3 *lastDira,
        int a44,
        int lastCornera,
        int a46,
        obstacleRoute_t *a47,
        int a48,
        obstacleBox_t *a49,
        int a50,
        int a51,
        int a52,
        obstacleVertex_t *flagsa,
        int a54,
        const obstacleRoute_t *routea,
        int a56,
        const obstacleEdge_t *obstaclesa,
        int a58,
        int numObstaclesa,
        int a60,
        const obstacleVertex_t *verticesa,
        int a62,
        int numVerticesa,
        int a64)
{
  const obstacleEdge_t *edgesa; // [sp+2BCh] [+DCh]
  int numEdgesa; // [sp+2C4h] [+E4h]
  const obstacleCorner_t *cornersa; // [sp+2CCh] [+ECh] MAPDST
  unsigned __int8 *v73; // r10
  int v74; // ctr
  int v75; // r11
  int v76; // r11
  int v77; // r10
  BOOL v78; // r27
  int v79; // r9
  const obstacleEdge_t *v80; // r5
  int v81; // r3
  int v82; // r11
  unsigned __int8 *tempMemoryStart; // r9
  int v84; // r4
  int v85; // r11
  int v86; // r10
  int v87; // r5
  idObstacleAvoidanceCore::expandedObstacle_t *v88; // r11
  int v89; // r4
  idVec2 *v90; // r10
  int v91; // r26
  float v92; // r8
  float v93; // r27
  float v94; // r16
  float v95; // r15
  float v96; // r11
  float x; // r5
  float v98; // r6
  float y; // r3
  double v100; // fp26
  double v101; // fp0
  float z; // r7
  double v103; // fp27
  double v104; // fp13
  double v105; // fp29
  double v106; // fp12
  double v107; // fp6
  double v110; // fp1
  double v111; // fp4
  double v112; // fp1
  double v113; // fp4
  double v114; // fp3
  double v115; // fp10
  double v116; // fp9
  idVec3 *p_startPosOutsideObstacles; // r27
  idVec3 *p_seekPosOutsideObstacles; // r29
  char v119; // r23
  const idVec2 *v121; // r28
  const idVec3 *v122; // r5
  char PointOutsideObstacles; // r3
  int v124; // r28
  char SeekPosForRoute; // r3
  double v126; // fp0
  double v127; // fp25
  double v128; // fp12
  double v129; // fp10
  double v130; // fp13
  double v131; // fp24
  idVec3 *v132; // r26
  int *p_numSeekPos; // r24
  char v134; // r3
  int v135; // r9
  double v136; // fp9
  int startPosObstacle; // r11
  bool v138; // cr58
  unsigned __int8 *tempMemory; // r11
  int v140; // r28
  idObstacleAvoidanceCore::pathNode_t *v141; // r11
  unsigned int v142; // r7
  unsigned int v143; // r6
  idObstacleAvoidanceCore::pathNode_t *v144; // r26
  const idObstacleAvoidanceCore::pathNode_t *v145; // r4
  idObstacleAvoidanceCore *v146; // r3
  BOOL v147; // r11
  idObstacleAvoidanceCore::pathNode_t *next; // r8
  signed int v149; // r11
  idObstacleAvoidanceCore::pathNode_t **children; // r10
  int v151; // r6
  int numDebugLines; // r10
  idObstacleAvoidanceCore::pathNode_t *v153; // r9
  avoidDebugLine_t *v154; // r7
  avoidDebugLine_t *v155; // r11
  double v156; // fp0
  double v157; // fp12
  idObstacleAvoidanceCore::pathNode_t *v158; // r11
  double v159; // fp0
  double v160; // fp13
  idObstacleAvoidanceCore::pathNode_t *v161; // r11
  int *v162; // r7
  int v163; // r9
  float *v164; // r11
  int v165; // r10
  float *p_x; // r10
  double v167; // fp12
  double v168; // fp11
  double v169; // fp8
  double v170; // fp7
  double v171; // fp4
  double v172; // fp3
  double v173; // fp0
  double v174; // fp9
  double v179; // fp13
  double v180; // fp10
  double v181; // fp13
  double v182; // fp10
  double v183; // fp1
  double v184; // fp0
  double v185; // fp10
  double v186; // fp9
  int v187; // [sp+8h] [-1D8h]
  const obstacleVertex_t *v188; // [sp+8h] [-1D8h]
  obstacleCorner_t *v189; // [sp+Ch] [-1D4h]
  int v190; // [sp+Ch] [-1D4h]
  int v191; // [sp+10h] [-1D0h]
  const obstacleEdge_t *v192; // [sp+10h] [-1D0h]
  obstacleTrace_t *v193; // [sp+14h] [-1CCh]
  int v194; // [sp+14h] [-1CCh]
  int v195; // [sp+18h] [-1C8h]
  double v196; // [sp+18h] [-1C8h]
  int v197; // [sp+1Ch] [-1C4h]
  int v198; // [sp+20h] [-1C0h]
  double v199; // [sp+20h] [-1C0h]
  int v200; // [sp+24h] [-1BCh]
  int v201; // [sp+28h] [-1B8h]
  double v202; // [sp+28h] [-1B8h]
  int v203; // [sp+2Ch] [-1B4h]
  int v204; // [sp+30h] [-1B0h]
  double v205; // [sp+30h] [-1B0h]
  int v206; // [sp+34h] [-1ACh]
  int v207; // [sp+38h] [-1A8h]
  double v208; // [sp+38h] [-1A8h]
  int v209; // [sp+3Ch] [-1A4h]
  int v210; // [sp+40h] [-1A0h]
  double v211; // [sp+40h] [-1A0h]
  int v212; // [sp+44h] [-19Ch]
  int v213; // [sp+48h] [-198h]
  int v214; // [sp+48h] [-198h]
  int v215; // [sp+4Ch] [-194h]
  int v216; // [sp+4Ch] [-194h]
  int v217; // [sp+50h] [-190h]
  int v218; // [sp+50h] [-190h]
  int v219; // [sp+58h] [-188h]
  int v220; // [sp+58h] [-188h]
  int v221; // [sp+60h] [-180h]
  int v222; // [sp+60h] [-180h]
  int v223; // [sp+68h] [-178h]
  int v224; // [sp+68h] [-178h]
  int v225; // [sp+70h] [-170h]
  int v226; // [sp+70h] [-170h]
  int v227; // [sp+78h] [-168h]
  int v228; // [sp+80h] [-160h]
  int v229; // [sp+88h] [-158h]
  int v230; // [sp+90h] [-150h] BYREF
  int v231; // [sp+94h] [-14Ch] BYREF
  idVec3 v232; // [sp+98h] [-148h] BYREF
  float v233; // [sp+A8h] [-138h]
  float v234; // [sp+ACh] [-134h]
  float v235; // [sp+B0h] [-130h]
  idVec3 v236[2]; // [sp+B8h] [-128h] BYREF
  idVec4 v237; // [sp+D0h] [-110h] BYREF

  this->flags = lastCornera;
  this->tempMemorySize = tempSize - 32;
  v73 = (unsigned __int8 *)&temp[tempSize - 16];
  this->tempMemory = (unsigned __int8 *)(temp + 16);
  v74 = 16;
  this->tempMemoryStart = (unsigned __int8 *)(temp + 16);
  v75 = 0;
  this->tempMemoryEnd = v73;
  do
  {
    temp[v75] = v75;
    v73[v75] = v75;
    ++v75;
    --v74;
  }
  while ( v74 != 0 );
  v76 = 0;
  v77 = 0;
  v78 = false;
  v79 = 0;
  if ( numObstaclesa >= 2 )
  {
    v80 = obstaclesa - 1;
    do
    {
      v81 = v80[1].flags;
      v79 += 2;
      v80 += 2;
      v76 += (~(_WORD)v81 & 0x200) != 0;
      v77 += (~v80->flags & 0x200) != 0;
    }
    while ( v79 < numObstaclesa - 1 );
  }
  if ( v79 < numObstaclesa )
    v78 = (~obstaclesa[v79].flags & 0x200) != 0;
  v82 = v76 + v77 + v78;
  this->maxDebugText = maxDebugText;
  tempMemoryStart = this->tempMemoryStart;
  this->maxDebugLines = maxDebugLines;
  this->debugText = debugText;
  this->numExpandedObstacles = 0;
  this->numWindingPoints = 0;
  v84 = 4 * (numVerticesa + 4) + v82;
  this->bspNodes = (idObstacleAvoidanceCore::bspNode_t *)tempMemoryStart;
  v85 = v82 + a51 + numVerticesa + 16;
  this->pathNodes = nullptr;
  this->maxPathNodes = 0;
  this->maxExpandedObstacles = v85;
  this->numPathNodes = 0;
  this->debugLines = debugLines;
  this->numDebugLines = 0;
  v86 = 4 * v84 + 10 * a51;
  this->numDebugText = 0;
  this->maxWindingPoints = v86;
  v87 = 32 * v85 + 15;
  this->obstacleIndices = (__int16 *)(tempMemoryStart + 496);
  v88 = (idObstacleAvoidanceCore::expandedObstacle_t *)&tempMemoryStart[((2 * v85 + 15) & 0xFFFFFFF0) + 496];
  v89 = 8 * v86 + 15;
  this->expandedObstacles = v88;
  v90 = (idVec2 *)((char *)v88->bounds + (v87 & 0xFFFFFFF0));
  this->windingPoints = v90;
  this->tempMemoryStart = (unsigned __int8 *)v90 + (v89 & 0xFFFFFFF0);
  if ( debugLines != nullptr )
    debugLines->color = COLOR_INVALID;
  if ( debugText != nullptr )
    debugText->color = COLOR_INVALID;
  v91 = numEdgesa;
  v92 = a37[1];
  v237.x = *a37;
  v237.y = v92;
  v93 = *a35;
  v94 = a35[1];
  v95 = a35[2];
  v96 = a37[3];
  v237.z = a37[2];
  v236[0].x = v93;
  v236[0].y = v94;
  v236[0].z = v95;
  v237.w = v96;
  idObstacleAvoidanceCore::TransformInput(
    this,
    gravity: a33,
    route: a47,
    lastDir: v236,
    lastCorner: &v237,
    obstacles: a49,
    numObstacles: a51,
    vertices: flagsa,
    numVertices: v187,
    corners: v189,
    numCorners: v191,
    traces: v193,
    numTraces: v195,
    a14: v197,
    a15: v198,
    a16: v200,
    a17: v201,
    a18: v203,
    a19: v204,
    a20: v206,
    a21: v207,
    a22: v209,
    a23: v210,
    a24: v212,
    a25: v213,
    a26: v215,
    a27: v217,
    a28: (int)routea,
    a29: v219,
    a30: (int)verticesa,
    a31: v221,
    a32: numVerticesa,
    a33: v223,
    a34: (int)edgesa,
    a35: v225,
    numVerticesa: numEdgesa);
  x = a47->areas[0].end.x;
  v98 = a47->areas[0].start.x;
  y = a47->areas[0].end.y;
  v234 = a47->areas[0].start.y;
  v232.y = y;
  v233 = v98;
  v100 = v98;
  v232.x = x;
  v101 = x;
  z = a47->areas[0].end.z;
  v235 = a47->areas[0].start.z;
  v232.z = z;
  v103 = v234;
  v104 = y;
  v233 = x;
  v105 = v235;
  v106 = z;
  v107 = (float)((float)((float)(z - v235) * (float)(z - v235)) + (float)((float)(y - v234) * (float)(y - v234)));
  _FP4 = (float)((float)((float)((float)(x - v98) * (float)(x - v98))
                       + (float)((float)((float)(z - v235) * (float)(z - v235))
                               + (float)((float)(y - v234) * (float)(y - v234))))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f2, f4, f5, f11 }
  v110 = __frsqrte(_FP2);
  v111 = (float)((float)-(float)((float)((float)((float)v110
                                               * (float)((float)((float)((float)(x - v98) * (float)(x - v98))
                                                               + (float)((float)((float)(z - v235) * (float)(z - v235))
                                                                       + (float)((float)(y - v234) * (float)(y - v234))))
                                                       * (float)0.5))
                                       * (float)v110)
                               - (float)1.5)
               * (float)v110);
  v112 = (float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v110
                                                                               * (float)((float)((float)((float)(x - v98) * (float)(x - v98))
                                                                                               + (float)v107)
                                                                                       * (float)0.5))
                                                                       * (float)v110)
                                                               - (float)1.5)
                                               * (float)v110)
                                       * (float)((float)((float)((float)(x - v98) * (float)(x - v98)) + (float)v107)
                                               * (float)0.5))
                               * (float)((float)-(float)((float)((float)((float)v110
                                                                       * (float)((float)((float)((float)(x - v98)
                                                                                               * (float)(x - v98))
                                                                                       + (float)v107)
                                                                               * (float)0.5))
                                                               * (float)v110)
                                                       - (float)1.5)
                                       * (float)v110))
                       - (float)1.5);
  v113 = (float)((float)-(float)((float)((float)((float)((float)v112 * (float)v111)
                                               * (float)((float)((float)((float)(x - v98) * (float)(x - v98))
                                                               + (float)((float)((float)(z - v235) * (float)(z - v235))
                                                                       + (float)((float)(y - v234) * (float)(y - v234))))
                                                       * (float)0.5))
                                       * (float)((float)v112 * (float)v111))
                               - (float)1.5)
               * (float)((float)v112 * (float)v111));
  v114 = (float)((float)v113
               * (float)((float)((float)(x - v98) * (float)(x - v98))
                       + (float)((float)((float)(z - v235) * (float)(z - v235))
                               + (float)((float)(y - v234) * (float)(y - v234)))));
  v115 = (float)((float)(y - v234) * (float)v113);
  v234 = y;
  v116 = (float)((float)(z - v235) * (float)v113);
  v235 = z;
  if ( v114 > obstacleRadius )
  {
    v101 = (float)((float)((float)((float)((float)(x - v98) * (float)v113) * (float)obstacleRadius) * (float)0.89999998)
                 + v98);
    v232.x = (float)((float)((float)((float)(x - v98) * (float)v113) * (float)obstacleRadius) * (float)0.89999998) + v98;
    v104 = (float)((float)((float)((float)v115 * (float)obstacleRadius) * (float)0.89999998) + (float)v103);
    v232.y = (float)((float)((float)v115 * (float)obstacleRadius) * (float)0.89999998) + (float)v103;
    v106 = (float)((float)((float)((float)v116 * (float)obstacleRadius) * (float)0.89999998) + (float)v105);
    v232.z = (float)((float)((float)v116 * (float)obstacleRadius) * (float)0.89999998) + (float)v105;
  }
  path->seekPos[0].x = v101;
  path->seekPos[0].y = v104;
  path->seekPos[0].z = v106;
  path->seekPos[1].x = v101;
  path->seekPos[1].y = v104;
  path->seekPos[1].z = v106;
  path->numSeekPos = 1;
  path->seekPosPlane.d = 0.0;
  path->seekPosPlane.c = 0.0;
  path->seekPosPlane.b = 0.0;
  path->seekPosPlane.a = 0.0;
  path->firstObstaclePosition.z = 0.0;
  p_startPosOutsideObstacles = &path->startPosOutsideObstacles;
  path->firstObstaclePosition.y = 0.0;
  p_seekPosOutsideObstacles = &path->seekPosOutsideObstacles;
  path->firstObstaclePosition.x = 0.0;
  path->firstObstacle = -1;
  path->startPosOutsideObstacles.x = v98;
  path->startPosOutsideObstacles.y = v103;
  path->startPosOutsideObstacles.z = v105;
  path->startPosObstacle = -1;
  path->seekPosOutsideObstacles.x = v101;
  path->seekPosOutsideObstacles.y = v104;
  path->seekPosOutsideObstacles.z = v106;
  path->seekPosObstacle = -1;
  path->targetDist = 1.0e30;
  path->pathLength = 1.0e30;
  path->nextCorner.w = 0.0;
  path->nextCorner.z = 0.0;
  path->nextCorner.y = 0.0;
  path->nextCorner.x = 0.0;
  path->nextCornerAngle = 0.0;
  path->wallCorners[0].x = v101;
  path->wallCorners[0].y = v104;
  path->wallCorners[0].z = v106;
  path->wallCorners[1].x = v101;
  path->wallCorners[1].y = v104;
  path->wallCorners[1].z = v106;
  path->hasValidPath = true;
  path->startPosValid = true;
  path->seekPosValid = true;
  path->radar[0].direction.x = 0.0;
  path->radar[0].direction.z = 0.0;
  path->radar[0].direction.y = 0.0;
  path->radar[0].obstacle = -1;
  path->radar[1].direction.z = 0.0;
  path->radar[1].direction.y = 0.0;
  path->radar[1].direction.x = 0.0;
  path->radar[1].obstacle = -1;
  path->radar[2].direction.z = 0.0;
  path->radar[2].direction.y = 0.0;
  path->radar[2].direction.x = 0.0;
  path->radar[2].obstacle = -1;
  path->radar[3].direction.z = 0.0;
  path->radar[3].direction.y = 0.0;
  path->radar[3].direction.x = 0.0;
  path->radar[3].obstacle = -1;
  path->radar[4].direction.z = 0.0;
  path->radar[4].direction.y = 0.0;
  path->radar[4].direction.x = 0.0;
  path->radar[4].obstacle = -1;
  path->radar[5].direction.z = 0.0;
  path->radar[5].direction.y = 0.0;
  path->radar[5].direction.x = 0.0;
  path->radar[5].obstacle = -1;
  path->radar[6].direction.z = 0.0;
  path->radar[6].direction.y = 0.0;
  path->radar[6].direction.x = 0.0;
  path->radar[6].obstacle = -1;
  if ( (lastCornera & 0x40) != 0 )
  {
    v211 = v235;
    v208 = v234;
    v205 = v233;
    v202 = v105;
    v199 = v103;
    v196 = v98;
    printf(
      format: (const char *)HIDWORD(v100),
      LODWORD(v100),
      LODWORD(v103),
      LODWORD(v105),
      (unsigned int)COERCE_UNSIGNED_INT64(v233),
      (unsigned int)COERCE_UNSIGNED_INT64(v234),
      (unsigned int)COERCE_UNSIGNED_INT64(v235),
      &path->wallCorners[1],
      v100,
      v103,
      v105);
  }
  v119 = idObstacleAvoidanceCore::SetupExpandedObstacles(
           this,
           bounds: (int)a31,
           gravity: a33,
           startPos: (const idVec2 *)&path->startPosOutsideObstacles,
           seekPos: (const idVec2 *)&path->seekPosOutsideObstacles,
           obstacleRadius,
           assumeValidAASPath: (const bool)obstaclesa,
           obstacles: (const obstacleBox_t *)(lastCornera & 1),
           numObstacles: (int)a49,
           vertices: v188,
           numVertices: v190,
           edges: v192,
           numEdges: v194,
           corners: (const obstacleCorner_t *)HIDWORD(v196),
           numCorners: SLODWORD(v196),
           hasTraces: SBYTE3(v199),
           a17: SLODWORD(v199),
           a18: SHIDWORD(v202),
           a19: SLODWORD(v202),
           a20: SHIDWORD(v205),
           a21: SLODWORD(v205),
           a22: SHIDWORD(v208),
           a23: SLODWORD(v208),
           a24: SHIDWORD(v211),
           a25: SLODWORD(v211),
           a26: v214,
           a27: v216,
           a28: v218,
           a29: a51,
           a30: v220,
           a31: flagsa,
           a32: v222,
           a33: (int)routea,
           a34: v224,
           a35: obstaclesa,
           a36: v226,
           numObstacles_0: numObstaclesa,
           a38: v227,
           verticesa,
           a40: v228,
           numVerticesa,
           a42: v229,
           edges_3: (-numEdgesa & ~numEdgesa) < 0);
  if ( numEdgesa > 0 )
  {
    v121 = (const idVec2 *)edgesa;
    do
    {
      if ( (unsigned __int8)idObstacleAvoidanceCore::LineIntersectsObstacle(
                              this,
                              start: v121,
                              end: v121 + 1,
                              endObstacle: 0,
                              ignoreObstacle: 0) != 0 )
        cornersa->corner.x = 0.0;
      else
        cornersa->corner.x = 1.0;
      --v91;
      v121 += 2;
      cornersa = (const obstacleCorner_t *)((char *)cornersa + 4);
    }
    while ( v91 != 0 );
  }
  if ( v119 != 0 )
  {
    PointOutsideObstacles = idObstacleAvoidanceCore::GetPointOutsideObstacles(
                              this,
                              point: (idVec2 *)&path->startPosOutsideObstacles,
                              obstacle: &v230,
                              edgeNum: nullptr,
                              startPos: (const idVec2 *)&path->startPosOutsideObstacles,
                              moveAroundSeekPosObstacles: false);
    v124 = v230;
    path->startPosValid = PointOutsideObstacles;
    if ( v124 != -1 )
      path->startPosObstacle = this->expandedObstacles[v124].id;
    v230 = a47->numAreas - 1;
    SeekPosForRoute = idObstacleAvoidanceCore::FindSeekPosForRoute(
                        this,
                        route: a47,
                        obstacleRadius,
                        startPos: v122,
                        seekPos: (const idVec2 *)&path->startPosOutsideObstacles,
                        wallCorners: &v232,
                        outNextRouteIndex: &path->wallCorners[0].x,
                        a8: &v230);
    v126 = v232.y;
    v127 = (float)(v232.y - (float)v103);
    v128 = v232.z;
    v129 = (float)(v232.z - (float)v105);
    v130 = v232.x;
    v131 = (float)(v232.x - (float)v100);
    path->seekPos[0].x = v232.x;
    v132 = &path->seekPos[1];
    path->seekPos[0].y = v126;
    p_numSeekPos = &path->numSeekPos;
    path->seekPos[0].z = v128;
    path->seekPos[1].x = v130;
    path->seekPos[1].y = v126;
    path->seekPos[1].z = v128;
    path->numSeekPos = 1;
    p_seekPosOutsideObstacles->x = v130;
    path->seekPosOutsideObstacles.y = v126;
    path->seekPosOutsideObstacles.z = v128;
    if ( (float)((float)((float)v131 * (float)v131)
               + (float)((float)((float)v129 * (float)v129) + (float)((float)v127 * (float)v127))) >= 0.010000001
      && SeekPosForRoute == 0 )
    {
      v134 = idObstacleAvoidanceCore::GetPointOutsideObstacles(
               this,
               point: (idVec2 *)&path->seekPosOutsideObstacles,
               obstacle: &v231,
               edgeNum: nullptr,
               startPos: (const idVec2 *)&path->startPosOutsideObstacles,
               moveAroundSeekPosObstacles: (lastCornera & 2) != 0);
      v135 = v231;
      path->seekPosValid = v134;
      if ( v135 != -1 )
        path->seekPosObstacle = this->expandedObstacles[v135].id;
      v132->x = p_seekPosOutsideObstacles->x;
      path->seekPos[1].y = path->seekPosOutsideObstacles.y;
      path->seekPos[1].z = path->seekPosOutsideObstacles.z;
      *p_numSeekPos = 2;
      if ( v124 != -1 || v135 != -1 )
      {
        v136 = (float)(path->seekPosOutsideObstacles.y - path->startPosOutsideObstacles.y);
        if ( (float)((float)((float)v136 * (float)v136)
                   + (float)((float)(p_seekPosOutsideObstacles->x - p_startPosOutsideObstacles->x)
                           * (float)(p_seekPosOutsideObstacles->x - p_startPosOutsideObstacles->x))) < 1.0 )
        {
          if ( v124 != -1 )
            path->startPosObstacle = this->expandedObstacles[v124].id;
          if ( v135 != -1 )
            path->seekPosObstacle = this->expandedObstacles[v135].id;
          startPosObstacle = path->startPosObstacle;
          if ( startPosObstacle == -1 )
            startPosObstacle = path->seekPosObstacle;
          path->firstObstacle = startPosObstacle;
          if ( (float)((float)((float)v127 * (float)v127) + (float)((float)v131 * (float)v131)) > 4.0 )
          {
            path->seekPos[0].x = p_startPosOutsideObstacles->x;
            path->seekPos[0].y = path->startPosOutsideObstacles.y;
            path->seekPos[0].z = path->startPosOutsideObstacles.z;
            v132->x = p_startPosOutsideObstacles->x;
            path->seekPos[1].y = path->startPosOutsideObstacles.y;
            path->seekPos[1].z = path->startPosOutsideObstacles.z;
            path->hasValidPath = false;
            return;
          }
          path->seekPos[0].x = p_seekPosOutsideObstacles->x;
          v138 = (lastCornera & 8) == 0;
          path->seekPos[0].y = path->seekPosOutsideObstacles.y;
          path->seekPos[0].z = path->seekPosOutsideObstacles.z;
          v132->x = p_seekPosOutsideObstacles->x;
          path->seekPos[1].y = path->seekPosOutsideObstacles.y;
          path->seekPos[1].z = path->seekPosOutsideObstacles.z;
          *p_numSeekPos = 1;
          goto LABEL_81;
        }
      }
      tempMemory = this->tempMemory;
      if ( tempMemory != nullptr )
        this->tempMemoryEnd = &tempMemory[this->tempMemorySize];
      v140 = 0;
      v141 = (idObstacleAvoidanceCore::pathNode_t *)&this->windingPoints[this->numWindingPoints];
      v142 = this->tempMemoryEnd - (unsigned __int8 *)v141;
      this->pathNodes = v141;
      v143 = v142 / 0x34;
      this->maxPathNodes = v142 / 0x34;
      do
      {
        this->numPathNodes = 0;
        v144 = idObstacleAvoidanceCore::BuildPathTree(
                 this,
                 startPos: &path->startPosOutsideObstacles,
                 seekPos: (const idVec2 *)&path->seekPosOutsideObstacles,
                 obstacleRadius,
                 path: (obstaclePath_t *)v143,
                 a6: (int)path);
        idObstacleAvoidanceCore::PrunePathTree(
          this,
          root: v144,
          seekPos: (const idVec2 *)&path->seekPosOutsideObstacles);
        idObstacleAvoidanceCore::FindOptimalPath(
          this: v146,
          root: v145,
          originalSeekPos: (const idVec2 *)&v232,
          lastDir: (const idVec2 *)v236,
          seekPos: path->seekPos,
          outNumSeekPos: &path->numSeekPos,
          targetDist: &path->targetDist,
          pathLength: &path->pathLength);
        v147 = path->targetDist < 1.0;
        path->hasValidPath = v147;
        if ( v147 )
          break;
        if ( numVerticesa <= 0 )
          break;
        ++v140;
        this->numExpandedObstacles -= numVerticesa;
      }
      while ( v140 < 2 );
      path->wallCorners[0].x = path->seekPos[0].x;
      path->wallCorners[0].y = path->seekPos[0].y;
      path->wallCorners[0].z = path->seekPos[0].z;
      path->wallCorners[1].x = path->seekPos[1].x;
      path->wallCorners[1].y = path->seekPos[1].y;
      path->wallCorners[1].z = path->seekPos[1].z;
      if ( (lastCornera & 0x20) != 0 && debugLines != nullptr )
      {
        next = v144;
        if ( v144 == nullptr )
        {
LABEL_68:
          if ( (lastCornera & 4) != 0 )
            idObstacleAvoidanceCore::CircleCorners(
              this,
              path,
              lastCorner: (const idVec2 *)&v237,
              bbox: a31,
              frameMoveDist,
              cornerCircleRadius);
          if ( a47->endTurnRadius > 0.0 )
            idObstacleAvoidanceCore::CircleApproachDestination(this, (idVec2 *)path, route: a47, frameMoveDist);
          v162 = &path->numSeekPos;
          if ( path->numSeekPos < 30 )
          {
            v163 = v230;
            if ( v230 < a47->numAreas )
            {
              v164 = &a47->endTurnRadius + 7 * v230;
              do
              {
                v165 = *v162;
                if ( *v162 >= 30 )
                  break;
                *v162 = v165 + 1;
                ++v163;
                p_x = &path->seekPos[v165].x;
                *p_x = v164[5];
                p_x[1] = v164[6];
                v164 += 7;
                p_x[2] = *v164;
              }
              while ( v163 < a47->numAreas );
            }
          }
          if ( (lastCornera & 8) != 0 )
            idObstacleAvoidanceCore::UpdateRadar(this, path, frameMoveDist);
          v167 = (float)(path->seekPos[0].y - (float)v103);
          v168 = (float)(path->seekPos[1].y - path->seekPos[0].y);
          v169 = (float)(path->seekPos[0].x - (float)v100);
          v170 = (float)(path->seekPos[1].x - path->seekPos[0].x);
          v171 = (float)(path->seekPos[0].z - (float)v105);
          v172 = (float)(path->seekPos[1].z - path->seekPos[0].z);
          v173 = idMath::FLT_SMALLEST_NON_DENORMAL;
          path->seekPosPlane.c = 0.0;
          v174 = (float)((float)((float)v171 * (float)v171)
                       + (float)((float)((float)v169 * (float)v169) + (float)((float)v167 * (float)v167)));
          _FP5 = (float)((float)((float)((float)v171 * (float)v171)
                               + (float)((float)((float)v169 * (float)v169) + (float)((float)v167 * (float)v167)))
                       - (float)v173);
          _FP4 = (float)((float)((float)((float)v172 * (float)v172)
                               + (float)((float)((float)v170 * (float)v170) + (float)((float)v168 * (float)v168)))
                       - (float)v173);
          __asm
          {
            fsel      f1, f5, f9, f0
            fsel      f0, f4, f6, f0
          }
          v179 = __frsqrte(_FP1);
          v180 = __frsqrte(_FP0);
          v181 = (float)((float)-(float)((float)((float)((float)v179 * (float)((float)v174 * (float)0.5)) * (float)v179)
                                       - (float)1.5)
                       * (float)v179);
          v182 = (float)((float)-(float)((float)((float)((float)v180
                                                       * (float)((float)((float)((float)v172 * (float)v172)
                                                                       + (float)((float)((float)v170 * (float)v170)
                                                                               + (float)((float)v168 * (float)v168)))
                                                               * (float)0.5))
                                               * (float)v180)
                                       - (float)1.5)
                       * (float)v180);
          v183 = (float)((float)-(float)((float)((float)((float)v181 * (float)((float)v174 * (float)0.5)) * (float)v181)
                                       - (float)1.5)
                       * (float)v181);
          v184 = (float)((float)-(float)((float)((float)((float)v182
                                                       * (float)((float)((float)((float)v172 * (float)v172)
                                                                       + (float)((float)((float)v170 * (float)v170)
                                                                               + (float)((float)v168 * (float)v168)))
                                                               * (float)0.5))
                                               * (float)v182)
                                       - (float)1.5)
                       * (float)v182);
          v185 = (float)((float)((float)-(float)((float)((float)((float)v182
                                                               * (float)((float)((float)((float)v172 * (float)v172)
                                                                               + (float)((float)((float)v170
                                                                                               * (float)v170)
                                                                                       + (float)((float)v168
                                                                                               * (float)v168)))
                                                                       * (float)0.5))
                                                       * (float)v182)
                                               - (float)1.5)
                               * (float)v182)
                       * (float)((float)((float)((float)v172 * (float)v172)
                                       + (float)((float)((float)v170 * (float)v170) + (float)((float)v168 * (float)v168)))
                               * (float)0.5));
          v186 = (float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v181
                                                                                       * (float)((float)v174 * (float)0.5))
                                                                               * (float)v181)
                                                                       - (float)1.5)
                                                       * (float)v181)
                                               * (float)((float)v174 * (float)0.5))
                                       * (float)((float)-(float)((float)((float)((float)v181
                                                                               * (float)((float)v174 * (float)0.5))
                                                                       * (float)v181)
                                                               - (float)1.5)
                                               * (float)v181))
                               - (float)1.5);
          path->seekPosPlane.a = (float)((float)((float)-(float)((float)((float)v185 * (float)v184) - (float)1.5)
                                               * (float)v184)
                                       * (float)v170)
                               + (float)((float)((float)v186 * (float)v183) * (float)v169);
          path->seekPosPlane.b = (float)((float)((float)-(float)((float)((float)v185 * (float)v184) - (float)1.5)
                                               * (float)v184)
                                       * (float)v168)
                               + (float)((float)((float)v186 * (float)v183) * (float)v167);
          idPlane::Normalize(this: &path->seekPosPlane, fixDegenerate: true);
          path->seekPosPlane.d = -(float)((float)(path->seekPos[0].x * path->seekPosPlane.a)
                                        + (float)((float)(path->seekPos[0].z * path->seekPosPlane.c)
                                                + (float)(path->seekPosPlane.b * path->seekPos[0].y)));
          goto LABEL_83;
        }
        do
        {
          v149 = 0;
          children = next->children;
          while ( *children == nullptr )
          {
            ++v149;
            ++children;
            if ( v149 >= 2 )
              goto LABEL_60;
          }
          if ( next->edgeNum == -1 )
            v151 = 6;
          else
            v151 = ((_cntlzw(v149) & 0x20) == 0) + 3;
          numDebugLines = this->numDebugLines;
          v153 = next->children[v149];
          if ( numDebugLines < this->maxDebugLines - 1 )
          {
            v154 = this->debugLines;
            if ( v154 != nullptr )
            {
              v155 = &v154[numDebugLines];
              this->numDebugLines = numDebugLines + 1;
              v155->color = v151;
              v156 = next->pos.y;
              v155->start.x = next->pos.x;
              v155->start.y = v156;
              v155->start.z = 0.0;
              v157 = v153->pos.y;
              v155->end.x = v153->pos.x;
              v155->end.z = 0.0;
              v155->end.y = v157;
              this->debugLines[this->numDebugLines].color = COLOR_INVALID;
            }
          }
LABEL_60:
          next = next->queueNode.next;
        }
        while ( next != nullptr );
      }
      if ( v144 != nullptr )
      {
        v158 = v144->children[0];
        if ( v158 != nullptr )
        {
          v159 = v158->pos.x;
          v160 = v158->pos.y;
        }
        else
        {
          v161 = v144->children[1];
          if ( v161 != nullptr )
          {
            v159 = v161->pos.x;
            v160 = v161->pos.y;
          }
          else
          {
            v159 = v144->pos.x;
            v160 = v144->pos.y;
          }
        }
        path->firstObstaclePosition.y = v160;
        path->firstObstaclePosition.x = v159;
        path->firstObstaclePosition.z = v105;
      }
      goto LABEL_68;
    }
  }
  v138 = (lastCornera & 8) == 0;
LABEL_81:
  path->hasValidPath = true;
  if ( !v138 )
    idObstacleAvoidanceCore::UpdateRadar(this, path, frameMoveDist);
LABEL_83:
  idObstacleAvoidanceCore::UnTransformOutput(this, path);
}

