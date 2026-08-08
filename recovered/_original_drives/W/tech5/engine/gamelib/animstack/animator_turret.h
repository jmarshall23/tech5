
// ========================================================================
// ??0?$idAnimator_TurretNxN@$02@@QAA@XZ
// EA  : 0x829F5A98
// RVA : 0x009F5A98
// PDB : w:\tech5\engine\gamelib\animstack\animator_turret.h
// ========================================================================

idAnimator_TurretNxN<3> *__fastcall idAnimator_TurretNxN<3>::idAnimator_TurretNxN<3>(idAnimator_TurretNxN<3> *this)
{
  idAnimator_Synced::idAnimator_Synced(this);
  this->__vftable = (idAnimator_TurretNxN<3>_vtbl *)&idAnimator_TurretNxN<3>::`vftable';
  this->lastBlendTriangle = 0;
  this->vertexAliasHandles[0].value = -1;
  this->vertexAliasHandles[1].value = -1;
  this->vertexAliasHandles[2].value = -1;
  this->vertexAliasHandles[3].value = -1;
  this->vertexAliasHandles[4].value = -1;
  this->vertexAliasHandles[5].value = -1;
  this->vertexAliasHandles[6].value = -1;
  this->vertexAliasHandles[7].value = -1;
  this->vertexAliasHandles[8].value = -1;
  return this;
}


// ========================================================================
// ?SetParameters@?$idAnimator_TurretNxN@$02@@QAAXPAVidGameTimeManager@@PAVidAnimStack@@QBV?$idHandle@GW4invalidAliasHandle_t@@$0PPPP@@@_N@Z
// EA  : 0x829FB870
// RVA : 0x009FB870
// PDB : w:\tech5\engine\gamelib\animstack\animator_turret.h
// ========================================================================

void __fastcall idAnimator_TurretNxN<3>::SetParameters(
        idAnimator_TurretNxN<3> *this,
        idGameTimeManager *gametimeManager,
        idAnimStack *animStack,
        const idHandle<unsigned short,enum invalidAliasHandle_t,65535> *_vertexAliasHandles,
        bool additive)
{
  idAnimatorParms_Base v9[2]; // [sp+50h] [-70h] BYREF

  v9[0].animStack = animStack;
  idStr::idStr(this: &v9[0].name, text: "ta");
  v9[0].originBlend = ORIGINBLEND_BRANCH;
  v9[0].alpha = 1.0;
  v9[0].weightGroup = MD6_WEIGHTGROUP_ALL;
  v9[0].filterGroup = MD6_WEIGHTGROUP_ALL;
  v9[0].blendOp = !additive ? BOP_LERP : BOP_ADD_RIGHT;
  idAnimator_Base::Init(this, gametimeManager, parms: v9);
  qmemcpy(this->vertexAliasHandles, _vertexAliasHandles, sizeof(this->vertexAliasHandles));
  idStr::FreeData(this: &v9[0].name);
}


// ========================================================================
// __unwind$527705
// EA  : 0x829FB940
// RVA : 0x009FB940
// PDB : w:\tech5\engine\gamelib\animstack\animator_turret.h
// ========================================================================

void _unwind_527705()
{
  int v0; // r12

  idAnimatorParms_EndAdditiveChannels::~idAnimatorParms_EndAdditiveChannels(this: (vaiAction_t::vehicleCam_t *)(v0 - 192 + 80));
}


// ========================================================================
// ?FindWeights@?$idAnimator_TurretNxN@$02@@ABAXHABVidVec3@@AAV2@@Z
// EA  : 0x82BED4C8
// RVA : 0x00BED4C8
// PDB : w:\tech5\engine\gamelib\animstack\animator_turret.h
// ========================================================================

void __fastcall idAnimator_TurretNxN<3>::FindWeights(
        idAnimator_TurretNxN<3> *this,
        const int blendTriangleIndex,
        const idVec3 *point,
        idVec3 *outWeights)
{
  int v6; // r8
  float *v7; // r10
  float *v8; // r9
  double v9; // fp13
  double v10; // fp12
  double v11; // fp11
  double v12; // fp10
  double v13; // fp9
  double v14; // fp8
  double v15; // fp7
  double v16; // fp6
  double y; // fp11
  double x; // fp6
  double v19; // fp1
  double v20; // fp0
  double v21; // fp3
  idMat3 v22; // [sp+50h] [-40h] BYREF

  v6 = 4
     * (idAnimator_TurretNxN<3>::grid.blendTriangles[blendTriangleIndex].vertex3
      + __ROL4__(idAnimator_TurretNxN<3>::grid.blendTriangles[blendTriangleIndex].vertex3, 1));
  v7 = (float *)((char *)&idAnimator_TurretNxN<3>::grid
               + 4 * idAnimator_TurretNxN<3>::grid.blendTriangles[blendTriangleIndex].vertex1
               + 4 * __ROL4__(idAnimator_TurretNxN<3>::grid.blendTriangles[blendTriangleIndex].vertex1, 1));
  v8 = (float *)((char *)&idAnimator_TurretNxN<3>::grid
               + 4 * idAnimator_TurretNxN<3>::grid.blendTriangles[blendTriangleIndex].vertex2
               + 4 * __ROL4__(idAnimator_TurretNxN<3>::grid.blendTriangles[blendTriangleIndex].vertex2, 1));
  v9 = v7[1];
  v10 = v7[2];
  v11 = *v8;
  v12 = v8[1];
  v13 = v8[2];
  v14 = *(float *)((char *)&idAnimator_TurretNxN<3>::grid.vertexLocations[0].x + v6);
  v15 = *(float *)((char *)&idAnimator_TurretNxN<3>::grid.vertexLocations[0].y + v6);
  v16 = *(float *)((char *)&idAnimator_TurretNxN<3>::grid.vertexLocations[0].z + v6);
  v22.mat[0].x = *v7;
  v22.mat[0].y = v9;
  v22.mat[0].z = v10;
  v22.mat[1].x = v11;
  v22.mat[1].y = v12;
  v22.mat[1].z = v13;
  v22.mat[2].x = v14;
  v22.mat[2].y = v15;
  v22.mat[2].z = v16;
  idMat3::InverseSelf(this: &v22);
  y = point->y;
  x = v22.mat[1].x;
  v19 = (float)((float)(point->z * v22.mat[2].x) + (float)(point->x * v22.mat[0].x));
  v20 = (float)((float)(point->z * v22.mat[2].y) + (float)(point->x * v22.mat[0].y));
  v21 = v22.mat[1].y;
  outWeights->z = (float)(point->x * v22.mat[0].z)
                + (float)((float)(point->y * v22.mat[1].z) + (float)(point->z * v22.mat[2].z));
  outWeights->x = (float)((float)y * (float)x) + (float)v19;
  outWeights->y = (float)((float)y * (float)v21) + (float)v20;
}


// ========================================================================
// ?IsInBlendTriangle@?$idAnimator_TurretNxN@$02@@ABA_NABVidVec3@@H@Z
// EA  : 0x82BED608
// RVA : 0x00BED608
// PDB : w:\tech5\engine\gamelib\animstack\animator_turret.h
// ========================================================================

BOOL __fastcall idAnimator_TurretNxN<3>::IsInBlendTriangle(
        idAnimator_TurretNxN<3> *this,
        const idVec3 *point,
        const int blendTriangleIndex)
{
  float *v3; // r10
  float *v4; // r9
  float *v5; // r11
  double v6; // fp5
  double v7; // fp4
  bool v8; // r9
  bool v9; // r11

  v3 = (float *)((char *)&idAnimator_TurretNxN<3>::grid
               + 4 * idAnimator_TurretNxN<3>::grid.blendTriangles[blendTriangleIndex].vertex1
               + 4 * __ROL4__(idAnimator_TurretNxN<3>::grid.blendTriangles[blendTriangleIndex].vertex1, 1));
  v4 = (float *)((char *)&idAnimator_TurretNxN<3>::grid
               + 4 * idAnimator_TurretNxN<3>::grid.blendTriangles[blendTriangleIndex].vertex2
               + 4 * __ROL4__(idAnimator_TurretNxN<3>::grid.blendTriangles[blendTriangleIndex].vertex2, 1));
  v5 = (float *)((char *)&idAnimator_TurretNxN<3>::grid
               + 4 * idAnimator_TurretNxN<3>::grid.blendTriangles[blendTriangleIndex].vertex3
               + 4 * __ROL4__(idAnimator_TurretNxN<3>::grid.blendTriangles[blendTriangleIndex].vertex3, 1));
  v6 = (float)(*v3 - *v5);
  v7 = (float)(v3[1] - v5[1]);
  LOBYTE(v3) = (float)((float)((float)(point->y - v3[1]) * (float)(*v4 - *v3))
                     - (float)((float)(point->x - *v3) * (float)(v4[1] - v3[1]))) >= 0.0;
  v8 = (float)((float)((float)(point->y - v4[1]) * (float)(*v5 - *v4))
             - (float)((float)(point->x - *v4) * (float)(v5[1] - v4[1]))) >= 0.0;
  v9 = (float)((float)((float)(point->y - v5[1]) * (float)v6) - (float)((float)v7 * (float)(point->x - *v5))) >= 0.0;
  if ( (_BYTE)v3 == 0 )
    return !v8 && !v9;
  return v8 && v9;
}


// ========================================================================
// ??0blendgrid_t@?$idAnimator_TurretNxN@$02@@QAA@XZ
// EA  : 0x82BED778
// RVA : 0x00BED778
// PDB : w:\tech5\engine\gamelib\animstack\animator_turret.h
// ========================================================================

idAnimator_TurretNxN<3>::blendgrid_t *__fastcall idAnimator_TurretNxN<3>::blendgrid_t::blendgrid_t(
        idAnimator_TurretNxN<3>::blendgrid_t *this)
{
  __int64 v1; // r7
  float *v2; // r10
  int v3; // ctr
  int v4; // r9
  double v5; // fp7

  HIDWORD(v1) = 0x82000000;
  v2 = (float *)((char *)this - 4);
  v3 = 3;
  this->blendTriangles[0].vertex1 = 0;
  v4 = 0;
  this->blendTriangles[0].vertex2 = 0;
  this->blendTriangles[0].vertex3 = 0;
  this->blendTriangles[1].vertex1 = 0;
  this->blendTriangles[1].vertex2 = 0;
  this->blendTriangles[1].vertex3 = 0;
  this->blendTriangles[2].vertex1 = 0;
  this->blendTriangles[2].vertex2 = 0;
  this->blendTriangles[2].vertex3 = 0;
  this->blendTriangles[3].vertex1 = 0;
  this->blendTriangles[3].vertex2 = 0;
  this->blendTriangles[3].vertex3 = 0;
  this->blendTriangles[4].vertex1 = 0;
  this->blendTriangles[4].vertex2 = 0;
  this->blendTriangles[4].vertex3 = 0;
  this->blendTriangles[5].vertex1 = 0;
  this->blendTriangles[5].vertex2 = 0;
  this->blendTriangles[5].vertex3 = 0;
  this->blendTriangles[6].vertex1 = 0;
  this->blendTriangles[6].vertex2 = 0;
  this->blendTriangles[6].vertex3 = 0;
  this->blendTriangles[7].vertex1 = 0;
  this->blendTriangles[7].vertex2 = 0;
  this->blendTriangles[7].vertex3 = 0;
  do
  {
    LODWORD(v1) = v4;
    v2[1] = -1.0;
    v2[4] = 0.0;
    ++v4;
    v2[3] = 1.0;
    v5 = -(float)((float)v1 - (float)1.0);
    v2[2] = v5;
    v2[5] = v5;
    v2[6] = 1.0;
    v2[7] = 1.0;
    v2[8] = v5;
    v2 += 9;
    *v2 = 1.0;
    --v3;
  }
  while ( v3 != 0 );
  this->blendTriangles[0].vertex1 = 0;
  this->blendTriangles[0].vertex3 = 3;
  this->blendTriangles[1].vertex2 = 3;
  this->blendTriangles[0].vertex2 = 1;
  this->blendTriangles[1].vertex1 = 1;
  this->blendTriangles[1].vertex3 = 4;
  this->blendTriangles[2].vertex1 = 1;
  this->blendTriangles[2].vertex2 = 2;
  this->blendTriangles[2].vertex3 = 4;
  this->blendTriangles[3].vertex1 = this->blendTriangles[2].vertex2;
  this->blendTriangles[3].vertex2 = this->blendTriangles[2].vertex3;
  this->blendTriangles[3].vertex3 = 5;
  this->blendTriangles[4].vertex1 = 3;
  this->blendTriangles[4].vertex2 = 4;
  this->blendTriangles[4].vertex3 = 6;
  this->blendTriangles[5].vertex1 = this->blendTriangles[4].vertex2;
  this->blendTriangles[5].vertex2 = this->blendTriangles[4].vertex3;
  this->blendTriangles[5].vertex3 = 7;
  this->blendTriangles[6].vertex1 = 4;
  this->blendTriangles[6].vertex2 = 5;
  this->blendTriangles[6].vertex3 = 7;
  this->blendTriangles[7].vertex1 = this->blendTriangles[6].vertex2;
  this->blendTriangles[7].vertex2 = this->blendTriangles[6].vertex3;
  this->blendTriangles[7].vertex3 = 8;
  return this;
}


// ========================================================================
// ?FindContainingBlendTriangle@?$idAnimator_TurretNxN@$02@@ABAHABVidVec3@@@Z
// EA  : 0x82BED930
// RVA : 0x00BED930
// PDB : w:\tech5\engine\gamelib\animstack\animator_turret.h
// ========================================================================

int __fastcall idAnimator_TurretNxN<3>::FindContainingBlendTriangle(idAnimator_TurretNxN<3> *this, const idVec3 *point)
{
  int lastBlendTriangle; // r30
  int result; // r3
  unsigned __int8 *p_vertex2; // r6
  float *v6; // r11
  float *v7; // r10
  double v8; // fp5
  double v9; // fp4
  double v10; // fp3
  double v11; // fp2
  double v12; // fp1
  double v13; // fp31
  float *v14; // r11
  bool v15; // r9
  bool v16; // r11
  char v17; // r11

  lastBlendTriangle = this->lastBlendTriangle;
  if ( idAnimator_TurretNxN<3>::IsInBlendTriangle(this, point, blendTriangleIndex: lastBlendTriangle) )
    return lastBlendTriangle;
  result = 0;
  p_vertex2 = &idAnimator_TurretNxN<3>::grid.blendTriangles[0].vertex2;
  do
  {
    v6 = (float *)((char *)&idAnimator_TurretNxN<3>::grid + 4 * *(p_vertex2 - 1) + 4 * __ROL4__(*(p_vertex2 - 1), 1));
    v7 = (float *)((char *)&idAnimator_TurretNxN<3>::grid + 4 * *p_vertex2 + 4 * __ROL4__(*p_vertex2, 1));
    v8 = *v6;
    v9 = v6[1];
    v10 = (float)(point->x - *v6);
    v11 = (float)(point->y - v6[1]);
    v12 = (float)(v7[1] - v6[1]);
    v13 = (float)(*v7 - *v6);
    v14 = (float *)((char *)&idAnimator_TurretNxN<3>::grid + 4 * p_vertex2[1] + 4 * __ROL4__(p_vertex2[1], 1));
    v15 = (float)((float)((float)(point->y - v7[1]) * (float)(*v14 - *v7))
                - (float)((float)(point->x - *v7) * (float)(v14[1] - v7[1]))) >= 0.0;
    v16 = (float)((float)((float)(point->y - v14[1]) * (float)((float)v8 - *v14))
                - (float)((float)(point->x - *v14) * (float)((float)v9 - v14[1]))) >= 0.0;
    if ( (float)((float)((float)v13 * (float)v11) - (float)((float)v10 * (float)v12)) < 0.0 )
    {
      if ( !v15 && !v16 )
      {
LABEL_10:
        v17 = 1;
        goto LABEL_12;
      }
    }
    else if ( v15 && v16 )
    {
      goto LABEL_10;
    }
    v17 = 0;
LABEL_12:
    if ( v17 != 0 )
      return result;
    p_vertex2 += 3;
    ++result;
  }
  while ( (int)p_vertex2 < (int)&algn_83801524[1] );
  return 0;
}


// ========================================================================
// ?Update@?$idAnimator_TurretNxN@$02@@QAAXABVidVec3@@HPAVidTreeAnimator@@@Z
// EA  : 0x82BEE488
// RVA : 0x00BEE488
// PDB : w:\tech5\engine\gamelib\animstack\animator_turret.h
// ========================================================================

void __fastcall idAnimator_TurretNxN<3>::Update(
        idAnimator_TurretNxN<3> *this,
        const idVec3 *point,
        int time,
        idTreeAnimator *animator)
{
  int ContainingBlendTriangle; // r31
  int vertex2; // r3
  int vertex3; // r11
  idHandle<unsigned short,enum invalidAliasHandle_t,65535> v11[4]; // [sp+50h] [-50h] BYREF
  idVec3 v12[6]; // [sp+58h] [-48h] BYREF

  ContainingBlendTriangle = idAnimator_TurretNxN<3>::FindContainingBlendTriangle(this, point);
  this->lastBlendTriangle = ContainingBlendTriangle;
  idAnimator_TurretNxN<3>::FindWeights(this, blendTriangleIndex: ContainingBlendTriangle, point, outWeights: v12);
  vertex2 = idAnimator_TurretNxN<3>::grid.blendTriangles[ContainingBlendTriangle].vertex2;
  vertex3 = idAnimator_TurretNxN<3>::grid.blendTriangles[ContainingBlendTriangle].vertex3;
  v11[0] = this->vertexAliasHandles[idAnimator_TurretNxN<3>::grid.blendTriangles[ContainingBlendTriangle].vertex1];
  v11[1] = this->vertexAliasHandles[vertex2];
  v11[2] = this->vertexAliasHandles[vertex3];
  idAnimator_Synced::SetAnimHandlesAndWeights(
    this,
    animator,
    curTime: time,
    handles: v11,
    numAnims: 3,
    weights: &v12[0].x,
    numWeights: 3);
}


// ========================================================================
// `dynamic initializer for 'idAnimator_TurretNxN<3>::grid''
// EA  : 0x833749C8
// RVA : 0x013749C8
// PDB : w:\tech5\engine\gamelib\animstack\animator_turret.h
// ========================================================================

idAnimator_TurretNxN<3>::blendgrid_t *_dynamic_initializer_for__idAnimator_TurretNxN<3>::grid__()
{
  return idAnimator_TurretNxN<3>::blendgrid_t::blendgrid_t(this: &idAnimator_TurretNxN<3>::grid);
}

