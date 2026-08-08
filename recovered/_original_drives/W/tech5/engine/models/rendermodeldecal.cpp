
// ========================================================================
// ?Shutdown@idRenderModelDecal@@SAXXZ
// EA  : 0x827FBC98
// RVA : 0x007FBC98
// PDB : w:\tech5\engine\models\rendermodeldecal.cpp
// ========================================================================

static void __fastcall idRenderModelDecal::Shutdown()
{
  idVertexBuffer *v0; // r31

  v0 = idRenderModelDecal::preAllocatedVertexBuffer;
  do
    idVertexBuffer::FreeBufferObject(this: v0++);
  while ( (int)v0 < (int)&idRenderModelDecal::preAllocatedIndexBufferBoxes );
  idIndexBuffer::FreeBufferObject(this: &idRenderModelDecal::preAllocatedIndexBufferBoxes);
  idIndexBuffer::FreeBufferObject(this: &idRenderModelDecal::preAllocatedIndexBufferQuads);
  idRenderModelDecal::preAllocatedBufferInUse = false;
}


// ========================================================================
// ?Update@idRenderModelDecal@@QAAXH@Z
// EA  : 0x827FBD10
// RVA : 0x007FBD10
// PDB : w:\tech5\engine\models\rendermodeldecal.cpp
// ========================================================================

void __fastcall idRenderModelDecal::Update(idRenderModelDecal *this, int currTime)
{
  int v2; // r8
  int v3; // r11
  idRenderModelDecal::decalInfo_t *decals; // r9
  int v5; // r10
  int v6; // r8
  idRenderModelDecal::tireDecalInfo_t *tireDecals; // r9
  int v8; // r10

  v2 = this->decalRange[1];
  v3 = this->decalRange[0];
  this->gameTime = currTime;
  if ( v3 < v2 )
  {
    decals = this->decals;
    do
    {
      v5 = this->decalRange[0];
      if ( currTime - decals[v5 & 0x7FF].startTime <= decals[v5 & 0x7FF].lifeTime )
        break;
      this->decalRange[0] = v5 + 1;
    }
    while ( v5 + 1 < this->decalRange[1] );
  }
  if ( this->decalRange[0] < v2 - 2048 )
    this->decalRange[0] = v2 - 2048;
  v6 = this->tireDecalRange[1];
  if ( this->tireDecalRange[0] < v6 )
  {
    tireDecals = this->tireDecals;
    do
    {
      v8 = this->tireDecalRange[0];
      if ( currTime - tireDecals[v8 & 0x1FF].startTime <= tireDecals[v8 & 0x1FF].lifeTime )
        break;
      this->tireDecalRange[0] = v8 + 1;
    }
    while ( v8 + 1 < this->tireDecalRange[1] );
  }
  if ( this->tireDecalRange[0] < v6 - 512 )
    this->tireDecalRange[0] = v6 - 512;
  idRenderModel::CommitThisFrame(this);
}


// ========================================================================
// ?CommitSubclass@idRenderModelDecal@@EAA_NXZ
// EA  : 0x827FBDE0
// RVA : 0x007FBDE0
// PDB : w:\tech5\engine\models\rendermodeldecal.cpp
// ========================================================================

int __fastcall idRenderModelDecal::CommitSubclass(idRenderModelDecal *this)
{
  int v2; // r9
  int v3; // r8
  int v4; // r7

  v2 = this->tireDecalRange[0];
  v3 = this->decalRange[1];
  v4 = this->tireDecalRange[1];
  this->latchedDecalRange[0] = this->decalRange[0];
  this->latchedTireDecalRange[0] = v2;
  this->latchedDecalRange[1] = v3;
  this->latchedTireDecalRange[1] = v4;
  this->latchedTime = this->gameTime;
  return 0;
}


// ========================================================================
// ?SetupInverseVPMatrix@idRenderModelDecal@@AAAXAAVidRenderMatrix@@PBVidRenderView@@MM@Z
// EA  : 0x827FBE98
// RVA : 0x007FBE98
// PDB : w:\tech5\engine\models\rendermodeldecal.cpp
// ========================================================================

void __fastcall idRenderModelDecal::SetupInverseVPMatrix(int a1, idRenderMatrix *a2, int a3, long double zFar)
{
  double v6; // fp31
  double v7; // fp29
  const idRenderMatrix *v9; // r3
  long double v10; // fp2
  double v11; // fp28
  long double v12; // fp2
  idRenderMatrix *v13; // r3
  double v14; // fp0
  idRenderMatrix v15; // [sp+50h] [-D0h] BYREF
  char v16; // [sp+90h] [-90h] BYREF

  v6 = *(double *)&zFar;
  v7 = *((double *)&zFar + 1);
  if ( (*(_BYTE *)(a1 + 221) & 1) != 0 || a3 == 0 )
  {
    a2->m[0] = 1.0;
    a2->m[5] = 1.0;
    a2->m[10] = 1.0;
    a2->m[15] = 1.0;
    a2->m[1] = 0.0;
    a2->m[2] = 0.0;
    a2->m[3] = 0.0;
    a2->m[4] = 0.0;
    a2->m[6] = 0.0;
    a2->m[7] = 0.0;
    a2->m[8] = 0.0;
    a2->m[9] = 0.0;
    a2->m[11] = 0.0;
    a2->m[12] = 0.0;
    a2->m[13] = 0.0;
    a2->m[14] = 0.0;
  }
  else
  {
    if ( *(float *)(a1 + 208) == 1.0 )
    {
      v9 = (const idRenderMatrix *)(a3 + 3808);
    }
    else
    {
      if ( *(_BYTE *)(a3 + 1960) != 0 )
        v6 = (float)((float)*(double *)&zFar * (float)0.25);
      *(double *)&zFar = (float)((float)((float)(*(float *)(a3 + 1956) * *(float *)(a1 + 208)) * idMath::M_DEG2RAD)
                               * (float)0.5);
      v10 = tan(x: zFar);
      v11 = (float)((float)*(double *)&v10 * (float)v6);
      *(double *)&v10 = (float)((float)((float)(*(float *)(a3 + 1952) * *(float *)(a1 + 208)) * idMath::M_DEG2RAD)
                              * (float)0.5);
      v12 = tan(x: v10);
      idRenderMatrix::BuildProjection(
        xMin: -(float)((float)*(double *)&v12 * (float)v6),
        xMax: (float)((float)*(double *)&v12 * (float)v6),
        yMin: -v11,
        yMax: v11,
        zNear: v6,
        zFar: v7,
        out: v13);
      v9 = (const idRenderMatrix *)&v16;
    }
    idRenderMatrix::Multiply(a: v9, b: (const idRenderMatrix *)(a3 + 3936), out: &v15);
    v14 = *(float *)(a1 + 212);
    if ( v14 > 0.0 )
    {
      v15.m[8] = v15.m[8] * *(float *)(a1 + 212);
      v15.m[9] = v15.m[9] * (float)v14;
      v15.m[10] = v15.m[10] * (float)v14;
      v15.m[11] = v15.m[11] * (float)v14;
    }
    idRenderMatrix::Inverse(src: &v15, out: a2);
  }
}


// ========================================================================
// ??1idRenderModelDecal@@UAA@XZ
// EA  : 0x827FC050
// RVA : 0x007FC050
// PDB : w:\tech5\engine\models\rendermodeldecal.cpp
// ========================================================================

void __fastcall idRenderModelDecal::~idRenderModelDecal(idRenderModelDecal *this)
{
  int v2; // r29
  idVertexBuffer *vertexBuffer; // r28
  idTriangles *triangles; // r3
  bufferUsageType_t *p_usage; // r27

  this->__vftable = (idRenderModelDecal_vtbl *)&idRenderModelDecal::`vftable';
  idMem::Free(this: &mem, ptr: this->decals, align: ALIGN_16);
  idMem::Free(this: &mem, ptr: this->tireDecals, align: ALIGN_16);
  if ( this->usesPreAllocatedBuffer )
    idRenderModelDecal::preAllocatedBufferInUse = false;
  v2 = 2;
  vertexBuffer = this->vertexBuffer;
  do
  {
    idVertexBuffer::FreeBufferObject(this: vertexBuffer);
    --v2;
    ++vertexBuffer;
  }
  while ( v2 != 0 );
  idIndexBuffer::FreeBufferObject(this: &this->indexBufferBoxes);
  idIndexBuffer::FreeBufferObject(this: &this->indexBufferQuads);
  triangles = this->triangles;
  if ( triangles != nullptr )
  {
    p_usage = &triangles[-1].indexBuffer.usage;
    `eh vector destructor iterator'(
      ptr: triangles,
      size: 0x84u,
      count: triangles[-1].indexBuffer.usage,
      pDtor: (void (__fastcall *)(void *))idTriangles::~idTriangles);
    idMem::Free(this: &mem, ptr: p_usage, align: ALIGN_16);
  }
  idIndexBuffer::~idIndexBuffer(this: &this->indexBufferQuads);
  idIndexBuffer::~idIndexBuffer(this: &this->indexBufferBoxes);
  `eh vector destructor iterator'(
    ptr: this->vertexBuffer,
    size: 0x10u,
    count: 2,
    pDtor: (void (__fastcall *)(void *))idVertexBuffer::~idVertexBuffer);
  idRenderModel::~idRenderModel(this);
}


// ========================================================================
// __unwind$231118
// EA  : 0x827FC158
// RVA : 0x007FC158
// PDB : w:\tech5\engine\models\rendermodeldecal.cpp
// ========================================================================

void _unwind_231118()
{
  int v0; // r12

  idRenderModel::~idRenderModel(this: *(idRenderModel **)(v0 - 144 + 164));
}


// ========================================================================
// __unwind$231119
// EA  : 0x827FC180
// RVA : 0x007FC180
// PDB : w:\tech5\engine\models\rendermodeldecal.cpp
// ========================================================================

void _unwind_231119()
{
  int v0; // r12

  `eh vector destructor iterator'(
    ptr: (void *)(*(_DWORD *)(v0 - 144 + 164) + 2084),
    size: 0x10u,
    count: 2,
    pDtor: (void (__fastcall *)(void *))idVertexBuffer::~idVertexBuffer);
}


// ========================================================================
// __unwind$231120
// EA  : 0x827FC1BC
// RVA : 0x007FC1BC
// PDB : w:\tech5\engine\models\rendermodeldecal.cpp
// ========================================================================

void _unwind_231120()
{
  int v0; // r12

  idIndexBuffer::~idIndexBuffer(this: (idIndexBuffer *)(*(_DWORD *)(v0 - 144 + 164) + 2116));
}


// ========================================================================
// __unwind$231121
// EA  : 0x827FC1E8
// RVA : 0x007FC1E8
// PDB : w:\tech5\engine\models\rendermodeldecal.cpp
// ========================================================================

void _unwind_231121()
{
  int v0; // r12

  idIndexBuffer::~idIndexBuffer(this: (idIndexBuffer *)(*(_DWORD *)(v0 - 144 + 164) + 2132));
}


// ========================================================================
// ?AddDecalFromPoint@idRenderModelDecal@@UAA?AV?$idHandle@HW4invalidDecalHandle_t@@$0?0@@PBUdecalParams_t@@HABVidVec3@@1V?$idIndex@FW4invalidJointIndex_t@@@@@Z
// EA  : 0x827FC218
// RVA : 0x007FC218
// PDB : w:\tech5\engine\models\rendermodeldecal.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
idHandle<int,enum invalidDecalHandle_t,-1> *__fastcall idRenderModelDecal::AddDecalFromPoint(
        idRenderModelDecal *this,
        idHandle<int,enum invalidDecalHandle_t,-1> *result,
        const decalParams_t *parms,
        const int startTime,
        const idVec3 *pos,
        const idVec3 *dir,
        idIndex<short,enum invalidJointIndex_t> *jointId)
{
  int v7; // r2 OVERLAPPED
  __int64 v14; // r4
  const idMaterial *decalMat; // r11
  int v16; // r11
  int v17; // r11
  int value; // r7
  int i; // r10
  _DWORD *v20; // r9
  int v21; // r31
  float *fadeInTime; // r3 OVERLAPPED
  double v23; // fp8
  double angle; // fp1
  unsigned int v25; // r5
  double x; // fp13
  double v27; // fp5
  double v28; // fp11
  float *v29; // r11
  double v30; // fp10
  double y; // fp12
  double z; // fp8
  double v33; // fp2
  double v34; // fp3
  double v37; // fp8
  double v38; // fp6
  double v39; // fp2
  double v40; // fp12
  double v41; // fp13
  double v42; // fp13
  double v43; // fp11
  double v46; // fp5
  double v47; // fp1
  double v48; // fp13
  double v49; // fp3
  double v50; // fp29
  double v51; // fp27
  double v52; // fp2
  double v53; // fp28
  double v54; // fp1
  double v55; // fp26
  double v56; // fp11
  double v57; // fp8
  double v58; // fp6
  double v59; // fp5
  double v60; // fp3
  double v61; // fp12
  double v62; // fp11
  double v63; // fp2
  double v64; // fp1
  double v67; // fp5
  double v68; // fp6
  double v69; // fp4
  double v70; // fp13
  double v71; // fp7
  double v72; // fp8
  double v75; // fp12
  __int64 v76; // r10
  double v77; // fp12
  double v78; // fp5
  idImageAtlas *transSortImageAtlas; // r7
  double v86; // fp1
  double v87; // fp4
  double v88; // fp8
  float v90; // [sp+50h] [-90h] BYREF
  int v91; // [sp+54h] [-8Ch]
  __int64 v92; // [sp+58h] [-88h] BYREF

  if ( r_skipDecals.valueInteger != 0 )
    goto LABEL_2;
  decalMat = parms->decalMat;
  if ( parms->decalMat == nullptr )
    goto LABEL_2;
  if ( (*((_BYTE *)decalMat + 72) & 4) == 0 )
    idLib::Warning(fmt: "Invalid decal material: %s, decal material must use the image atlas", decalMat->name.str);
  if ( parms->lifeTime < 0 )
  {
    value = result[508].value;
    v17 = 2048;
    for ( i = 204800; i < 217600; i += 400 )
    {
      v20 = (_DWORD *)(value + i);
      if ( *(_DWORD *)(value + i + 4) == 0 )
        break;
      if ( v20[26] == 0 )
      {
        ++v17;
        break;
      }
      if ( v20[51] == 0 )
      {
        v17 += 2;
        break;
      }
      if ( v20[76] == 0 )
      {
        v17 += 3;
        break;
      }
      v17 += 4;
    }
    if ( v17 != 2176 )
      goto LABEL_20;
LABEL_2:
    this->__vftable = (idRenderModelDecal_vtbl *)-1;
    HIDWORD(v14) = this;
    return (idHandle<int,enum invalidDecalHandle_t,-1> *)HIDWORD(v14);
  }
  v16 = result[510].value;
  if ( v16 - result[517].value >= 2048 )
    goto LABEL_2;
  result[510].value = v16 + 1;
  v17 = v16 & 0x7FF;
LABEL_20:
  v21 = result[508].value + 100 * v17;
  *(_DWORD *)(v21 + 96) = v17;
  *(_DWORD *)(v21 + 8) = parms->decalMat;
  *(_DWORD *)v21 = startTime;
  *(_DWORD *)(v21 + 4) = parms->lifeTime;
  *(_DWORD *)(v21 + 12) = parms->fadeOutTime;
  fadeInTime = (float *)parms->fadeInTime;
  *(_DWORD *)(v21 + 16) = fadeInTime;
  *(float *)(v21 + 32) = pos->x;
  *(float *)(v21 + 36) = pos->y;
  *(float *)(v21 + 40) = pos->z;
  v23 = (float)(parms->size.y * (float)0.5);
  *(float *)(v21 + 80) = parms->size.x * (float)0.5;
  *(float *)(v21 + 84) = v23;
  *(float *)(v21 + 28) = parms->depth * (float)0.5;
  *(_BYTE *)(v21 + 92) = parms->quad;
  angle = parms->angle;
  if ( angle == 0.0 )
  {
    v25 = 1664525 * result[515].value + 1013904223;
    result[515].value = v25;
    fadeInTime = (float *)((v25 >> 10) & 0x7FFF);
    v92 = *(_QWORD *)(&v7 - 1);
    angle = (float)((float)((float)*(__int64 *)(&v7 - 1) * idMath::TWO_PI) * (float)0.000030518509);
  }
  idMath::SinCos16(a: angle, s: fadeInTime, c: (float *)&v92, a4: &v90);
  x = dir->x;
  *(float *)(v21 + 68) = dir->x;
  v27 = x;
  v28 = 0.0;
  v29 = (float *)(v21 + 44);
  v30 = 1.0;
  y = dir->y;
  *(float *)(v21 + 72) = dir->y;
  z = dir->z;
  v33 = (float)((float)(dir->z * dir->z) + (float)((float)((float)x * (float)x) + (float)((float)y * (float)y)));
  *(float *)(v21 + 76) = dir->z;
  v34 = z;
  _FP1 = (float)((float)v33 - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f13, f1, f2, f13 }
  v37 = __frsqrte(_FP13);
  v38 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v37
                                                                                      * (float)((float)v33 * (float)0.5))
                                                                              * (float)v37)
                                                                      - (float)1.5)
                                                      * (float)v37)
                                              * (float)((float)v33 * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v37
                                                                              * (float)((float)v33 * (float)0.5))
                                                                      * (float)v37)
                                                              - (float)1.5)
                                              * (float)v37))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v37 * (float)((float)v33 * (float)0.5)) * (float)v37)
                                      - (float)1.5)
                      * (float)v37));
  v39 = (float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v37 * (float)((float)v33 * (float)0.5)) * (float)v37) - (float)1.5)
                                                                                      * (float)v37)
                                                                              * (float)((float)v33 * (float)0.5))
                                                                      * (float)((float)-(float)((float)((float)((float)v37 * (float)((float)v33 * (float)0.5)) * (float)v37)
                                                                                              - (float)1.5)
                                                                              * (float)v37))
                                                              - (float)1.5)
                                              * (float)((float)-(float)((float)((float)((float)v37
                                                                                      * (float)((float)v33 * (float)0.5))
                                                                              * (float)v37)
                                                                      - (float)1.5)
                                                      * (float)v37))
                                      * (float)((float)v33 * (float)0.5))
                              * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v37 * (float)((float)v33 * (float)0.5)) * (float)v37)
                                                                                              - (float)1.5)
                                                                              * (float)v37)
                                                                      * (float)((float)v33 * (float)0.5))
                                                              * (float)((float)-(float)((float)((float)((float)v37 * (float)((float)v33 * (float)0.5))
                                                                                              * (float)v37)
                                                                                      - (float)1.5)
                                                                      * (float)v37))
                                                      - (float)1.5)
                                      * (float)((float)-(float)((float)((float)((float)v37
                                                                              * (float)((float)v33 * (float)0.5))
                                                                      * (float)v37)
                                                              - (float)1.5)
                                              * (float)v37)))
                      - (float)1.5);
  v40 = (float)((float)y * (float)((float)v39 * (float)v38));
  *(float *)(v21 + 72) = v40;
  v41 = (float)((float)v27 * (float)((float)v39 * (float)v38));
  *(float *)(v21 + 68) = (float)v27 * (float)((float)v39 * (float)v38);
  *(float *)(v21 + 76) = (float)v34 * (float)((float)v39 * (float)v38);
  v42 = (float)((float)((float)v41 * (float)v41) + (float)((float)v40 * (float)v40));
  if ( v42 != 0.0 )
  {
    v43 = (float)((float)v42 * (float)0.5);
    _FP10 = (float)((float)v42 - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm { fsel      f6, f10, f13, f12 }
    v46 = __frsqrte(_FP6);
    v47 = (float)((float)-(float)((float)((float)((float)((float)v42 * (float)0.5) * (float)v46) * (float)v46)
                                - (float)1.5)
                * (float)v46);
    v48 = (float)((float)((float)v42 * (float)0.5)
                * (float)((float)-(float)((float)((float)((float)((float)v42 * (float)0.5) * (float)v46) * (float)v46)
                                        - (float)1.5)
                        * (float)v46));
    v49 = (float)(*(float *)(v21 + 72)
                * (float)((float)-(float)((float)((float)((float)v43
                                                        * (float)((float)-(float)((float)((float)v48 * (float)v47)
                                                                                - (float)1.5)
                                                                * (float)v47))
                                                * (float)((float)-(float)((float)((float)v48 * (float)v47) - (float)1.5)
                                                        * (float)v47))
                                        - (float)1.5)
                        * (float)((float)-(float)((float)((float)v48 * (float)v47) - (float)1.5) * (float)v47)));
    v28 = (float)(*(float *)(v21 + 68)
                * (float)((float)-(float)((float)((float)((float)v43
                                                        * (float)((float)-(float)((float)((float)v48 * (float)v47)
                                                                                - (float)1.5)
                                                                * (float)v47))
                                                * (float)((float)-(float)((float)((float)v48 * (float)v47) - (float)1.5)
                                                        * (float)v47))
                                        - (float)1.5)
                        * (float)((float)-(float)((float)((float)v48 * (float)v47) - (float)1.5) * (float)v47)));
    v30 = -v49;
  }
  HIDWORD(v14) = this;
  v50 = (float)((float)v28 * v90);
  v51 = (float)((float)v28 * *(float *)&v92);
  v52 = (float)((float)v30 * v90);
  v53 = (float)((float)v30 * *(float *)&v92);
  v54 = (float)(v90 * (float)0.0);
  v55 = (float)(*(float *)&v92 * (float)0.0);
  v57 = (float)((float)(*(float *)(v21 + 72) * (float)0.0) - (float)(*(float *)(v21 + 76) * (float)v28));
  v56 = (float)((float)(*(float *)(v21 + 68) * (float)v28) - (float)(*(float *)(v21 + 72) * (float)v30));
  v58 = (float)((float)v56 * *(float *)&v92);
  v59 = (float)((float)v57 * *(float *)&v92);
  v60 = (float)((float)v57 * v90);
  v61 = (float)((float)((float)(*(float *)(v21 + 76) * (float)v30) - (float)(*(float *)(v21 + 68) * (float)0.0)) * v90);
  v62 = (float)((float)v56 * v90);
  *(float *)(v21 + 48) = (float)v50
                       - (float)((float)((float)(*(float *)(v21 + 76) * (float)v30)
                                       - (float)(*(float *)(v21 + 68) * (float)0.0))
                               * *(float *)&v92);
  *(float *)(v21 + 52) = (float)v54 - (float)v58;
  *v29 = (float)v52 - (float)v59;
  *(float *)(v21 + 56) = (float)v53 + (float)v60;
  *(float *)(v21 + 60) = (float)v51 + (float)v61;
  *(float *)(v21 + 64) = (float)v55 + (float)v62;
  v63 = *(float *)(v21 + 52);
  v64 = *(float *)(v21 + 48);
  _FP8 = (float)((float)((float)(v29[2] * v29[2]) + (float)((float)(*v29 * *v29) + (float)(v29[1] * v29[1])))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f6, f8, f10, f13 }
  v67 = __frsqrte(_FP6);
  v68 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v67
                                                                                      * (float)((float)((float)(v29[2] * v29[2]) + (float)((float)(*v29 * *v29) + (float)(v29[1] * v29[1])))
                                                                                              * (float)0.5))
                                                                              * (float)v67)
                                                                      - (float)1.5)
                                                      * (float)v67)
                                              * (float)((float)((float)(v29[2] * v29[2])
                                                              + (float)((float)(*v29 * *v29) + (float)(v29[1] * v29[1])))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v67
                                                                              * (float)((float)((float)(v29[2] * v29[2])
                                                                                              + (float)((float)(*v29 * *v29) + (float)(v29[1] * v29[1])))
                                                                                      * (float)0.5))
                                                                      * (float)v67)
                                                              - (float)1.5)
                                              * (float)v67))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v67
                                                      * (float)((float)((float)(v29[2] * v29[2])
                                                                      + (float)((float)(*v29 * *v29)
                                                                              + (float)(v29[1] * v29[1])))
                                                              * (float)0.5))
                                              * (float)v67)
                                      - (float)1.5)
                      * (float)v67));
  v69 = (float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v67 * (float)((float)((float)(v29[2] * v29[2]) + (float)((float)(*v29 * *v29) + (float)(v29[1] * v29[1]))) * (float)0.5)) * (float)v67) - (float)1.5)
                                                                                      * (float)v67)
                                                                              * (float)((float)((float)(v29[2] * v29[2])
                                                                                              + (float)((float)(*v29 * *v29) + (float)(v29[1] * v29[1])))
                                                                                      * (float)0.5))
                                                                      * (float)((float)-(float)((float)((float)((float)v67 * (float)((float)((float)(v29[2] * v29[2]) + (float)((float)(*v29 * *v29) + (float)(v29[1] * v29[1]))) * (float)0.5)) * (float)v67)
                                                                                              - (float)1.5)
                                                                              * (float)v67))
                                                              - (float)1.5)
                                              * (float)((float)-(float)((float)((float)((float)v67
                                                                                      * (float)((float)((float)(v29[2] * v29[2]) + (float)((float)(*v29 * *v29) + (float)(v29[1] * v29[1])))
                                                                                              * (float)0.5))
                                                                              * (float)v67)
                                                                      - (float)1.5)
                                                      * (float)v67))
                                      * (float)((float)((float)(v29[2] * v29[2])
                                                      + (float)((float)(*v29 * *v29) + (float)(v29[1] * v29[1])))
                                              * (float)0.5))
                              * (float)v68)
                      - (float)1.5);
  v70 = (float)((float)v69
              * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v67
                                                                                              * (float)((float)((float)(v29[2] * v29[2]) + (float)((float)(*v29 * *v29) + (float)(v29[1] * v29[1]))) * (float)0.5))
                                                                                      * (float)v67)
                                                                              - (float)1.5)
                                                              * (float)v67)
                                                      * (float)((float)((float)(v29[2] * v29[2])
                                                                      + (float)((float)(*v29 * *v29)
                                                                              + (float)(v29[1] * v29[1])))
                                                              * (float)0.5))
                                              * (float)((float)-(float)((float)((float)((float)v67
                                                                                      * (float)((float)((float)(v29[2] * v29[2]) + (float)((float)(*v29 * *v29) + (float)(v29[1] * v29[1])))
                                                                                              * (float)0.5))
                                                                              * (float)v67)
                                                                      - (float)1.5)
                                                      * (float)v67))
                                      - (float)1.5)
                      * (float)((float)-(float)((float)((float)((float)v67
                                                              * (float)((float)((float)(v29[2] * v29[2])
                                                                              + (float)((float)(*v29 * *v29)
                                                                                      + (float)(v29[1] * v29[1])))
                                                                      * (float)0.5))
                                                      * (float)v67)
                                              - (float)1.5)
                              * (float)v67)));
  *v29 = *v29
       * (float)((float)v69
               * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v67
                                                                                               * (float)((float)((float)(v29[2] * v29[2]) + (float)((float)(*v29 * *v29) + (float)(v29[1] * v29[1]))) * (float)0.5))
                                                                                       * (float)v67)
                                                                               - (float)1.5)
                                                               * (float)v67)
                                                       * (float)((float)((float)(v29[2] * v29[2])
                                                                       + (float)((float)(*v29 * *v29)
                                                                               + (float)(v29[1] * v29[1])))
                                                               * (float)0.5))
                                               * (float)((float)-(float)((float)((float)((float)v67
                                                                                       * (float)((float)((float)(v29[2] * v29[2]) + (float)((float)(*v29 * *v29) + (float)(v29[1] * v29[1])))
                                                                                               * (float)0.5))
                                                                               * (float)v67)
                                                                       - (float)1.5)
                                                       * (float)v67))
                                       - (float)1.5)
                       * (float)((float)-(float)((float)((float)((float)v67
                                                               * (float)((float)((float)(v29[2] * v29[2])
                                                                               + (float)((float)(*v29 * *v29)
                                                                                       + (float)(v29[1] * v29[1])))
                                                                       * (float)0.5))
                                                       * (float)v67)
                                               - (float)1.5)
                               * (float)v67)));
  *(float *)(v21 + 52) = (float)v63 * (float)v70;
  *(float *)(v21 + 48) = (float)v64 * (float)v70;
  v71 = *(float *)(v21 + 56);
  v72 = *(float *)(v21 + 64);
  _FP2 = (float)((float)((float)(v29[5] * v29[5]) + (float)((float)(v29[3] * v29[3]) + (float)(v29[4] * v29[4])))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f13, f2, f3, f13 }
  v75 = __frsqrte(_FP13);
  HIDWORD(v76) = &joystick.joyAxis[0][2];
  v77 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v75
                                                                                      * (float)((float)((float)(v29[5] * v29[5]) + (float)((float)(v29[3] * v29[3]) + (float)(v29[4] * v29[4])))
                                                                                              * (float)0.5))
                                                                              * (float)v75)
                                                                      - (float)1.5)
                                                      * (float)v75)
                                              * (float)((float)((float)(v29[5] * v29[5])
                                                              + (float)((float)(v29[3] * v29[3])
                                                                      + (float)(v29[4] * v29[4])))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v75
                                                                              * (float)((float)((float)(v29[5] * v29[5])
                                                                                              + (float)((float)(v29[3] * v29[3]) + (float)(v29[4] * v29[4])))
                                                                                      * (float)0.5))
                                                                      * (float)v75)
                                                              - (float)1.5)
                                              * (float)v75))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v75
                                                      * (float)((float)((float)(v29[5] * v29[5])
                                                                      + (float)((float)(v29[3] * v29[3])
                                                                              + (float)(v29[4] * v29[4])))
                                                              * (float)0.5))
                                              * (float)v75)
                                      - (float)1.5)
                      * (float)v75));
  v78 = (float)((float)-(float)((float)((float)((float)v77
                                              * (float)((float)((float)(v29[5] * v29[5])
                                                              + (float)((float)(v29[3] * v29[3])
                                                                      + (float)(v29[4] * v29[4])))
                                                      * (float)0.5))
                                      * (float)v77)
                              - (float)1.5)
              * (float)v77);
  v29[4] = v29[4]
         * (float)((float)-(float)((float)((float)((float)v77
                                                 * (float)((float)((float)(v29[5] * v29[5])
                                                                 + (float)((float)(v29[3] * v29[3])
                                                                         + (float)(v29[4] * v29[4])))
                                                         * (float)0.5))
                                         * (float)v77)
                                 - (float)1.5)
                 * (float)v77);
  *(float *)(v21 + 64) = (float)v72 * (float)v78;
  *(float *)(v21 + 56) = (float)v71 * (float)v78;
  _FP11 = (float)(*(float *)(v21 + 80) - (float)255.0);
  _FP12 = (float)(*(float *)(v21 + 84) - (float)255.0);
  __asm { fsel      f8, f11, f13, f1 }
  *(float *)(v21 + 80) = _FP8;
  __asm { fsel      f10, f12, f13, f0 }
  *(float *)(v21 + 84) = _FP10;
  _FP6 = (float)(*(float *)(v21 + 28) - (float)255.0);
  __asm { fsel      f5, f6, f13, f7 }
  *(float *)(v21 + 88) = 1.0;
  *(float *)(v21 + 28) = _FP5;
  this->__vftable = *(idRenderModelDecal_vtbl **)(v21 + 96);
  transSortImageAtlas = globalImages->transSortImageAtlas;
  v86 = parms->decalMat->atlasScaleBias.x;
  LODWORD(v14) = transSortImageAtlas->ATLAS_WIDTH;
  LODWORD(v76) = transSortImageAtlas->ATLAS_HEIGHT;
  v87 = (float)(parms->decalMat->atlasScaleBias.y * (float)v76);
  v88 = (float)(parms->decalMat->atlasScaleBias.z * (float)v14);
  v91 = (int)(float)(parms->decalMat->atlasScaleBias.w * (float)v76);
  HIDWORD(v76) = ((int)v88 << 12) | (int)(float)((float)v86 * (float)v14);
  LODWORD(v76) = (v91 << 12) | (int)v87;
  *(float *)(v21 + 20) = (float)__SPAIR64__(v91, HIDWORD(v76));
  *(float *)(v21 + 24) = (float)v76;
  return (idHandle<int,enum invalidDecalHandle_t,-1> *)HIDWORD(v14);
}


// ========================================================================
// ?AddDecalFromTireMark@idRenderModelDecal@@QAAXPBUtireDecalParams_t@@HABVidVec3@@1@Z
// EA  : 0x827FC7D8
// RVA : 0x007FC7D8
// PDB : w:\tech5\engine\models\rendermodeldecal.cpp
// ========================================================================

void __fastcall idRenderModelDecal::AddDecalFromTireMark(
        idRenderModelDecal *this,
        const tireDecalParams_t *parms,
        int startTime,
        const idVec3 *pos,
        const idVec3 *dir)
{
  const idMaterial *decalMat; // r11
  int v11; // r11
  idRenderModelDecal::tireDecalInfo_t *tireDecals; // r10
  const idMaterial *v13; // r7
  idRenderModelDecal::tireDecalInfo_t *v14; // r11
  __int128 v15; // r6
  __int64 v16; // r10

  if ( r_skipDecals.valueInteger == 0 )
  {
    decalMat = parms->decalMat;
    if ( parms->decalMat != nullptr )
    {
      if ( (*((_BYTE *)decalMat + 72) & 4) == 0 )
        idLib::Warning(fmt: "Invalid decal material: %s, decal material must use the image atlas", decalMat->name.str);
      v11 = this->tireDecalRange[1];
      if ( v11 - this->latchedTireDecalRange[0] < 512 )
      {
        tireDecals = this->tireDecals;
        this->tireDecalRange[1] = v11 + 1;
        v13 = parms->decalMat;
        v14 = &tireDecals[v11 & 0x1FF];
        v14->startTime = startTime;
        v14->decalMtr = v13;
        v14->lifeTime = parms->lifeTime;
        v14->fadeTime = parms->fadeTime;
        v14->pos.x = pos->x;
        v14->pos.y = pos->y;
        v14->pos.z = pos->z;
        v14->dir.x = dir->x;
        v14->dir.y = dir->y;
        v14->dir.z = dir->z;
        v14->depth = parms->depth;
        v14->corners[0].x = parms->corners[0].x;
        v14->corners[0].y = parms->corners[0].y;
        v14->corners[0].z = parms->corners[0].z;
        v14->corners[1].x = parms->corners[1].x;
        v14->corners[1].y = parms->corners[1].y;
        v14->corners[1].z = parms->corners[1].z;
        v14->corners[2].x = parms->corners[2].x;
        v14->corners[2].y = parms->corners[2].y;
        v14->corners[2].z = parms->corners[2].z;
        v14->corners[3].x = parms->corners[3].x;
        v14->corners[3].y = parms->corners[3].y;
        v14->corners[3].z = parms->corners[3].z;
        v14->left.x = parms->left.x;
        v14->left.y = parms->left.y;
        v14->left.z = parms->left.z;
        v14->halfWidth = parms->halfWidth;
        v14->halfHeight = parms->halfHeight;
        v14->markStart = parms->markStart;
        v14->markEnd = parms->markEnd;
        DWORD1(v15) = parms->decalMat;
        *((_QWORD *)&v15 + 1) = *(_QWORD *)&globalImages->transSortImageAtlas->ATLAS_WIDTH;
        HIDWORD(v15) = (int)(float)(parms->decalMat->atlasScaleBias.x * (float)*(__int64 *)((char *)&v15 + 4));
        HIDWORD(v16) = (int)(float)(parms->decalMat->atlasScaleBias.z * (float)*(__int64 *)((char *)&v15 + 4));
        DWORD1(v15) = (HIDWORD(v16) << 12) | HIDWORD(v15);
        LODWORD(v16) = ((int)(float)(parms->decalMat->atlasScaleBias.w * (float)(__int64)v15) << 12)
                     | (int)(float)(parms->decalMat->atlasScaleBias.y * (float)(__int64)v15);
        v14->scaleBiasX = (float)*(__int64 *)&v15;
        v14->scaleBiasY = (float)v16;
      }
    }
  }
}


// ========================================================================
// ?GenDecalVerts@idRenderModelDecal@@AAAXPBUdecalInfo_t@1@PAVidDrawVert@@@Z
// EA  : 0x827FCA28
// RVA : 0x007FCA28
// PDB : w:\tech5\engine\models\rendermodeldecal.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idRenderModelDecal::GenDecalVerts(
        idRenderModelDecal *this,
        const idRenderModelDecal::decalInfo_t *decal,
        __int64 verts)
{
  int v3; // r2 OVERLAPPED
  int v6; // r3
  double v8; // fp29
  int v9; // r3
  int v10; // r3
  double v11; // fp9
  double v12; // fp10
  double v13; // fp9
  double v14; // fp13
  double y; // fp11
  double z; // fp1
  double v17; // fp9
  double v18; // fp7
  double v19; // fp1
  double v20; // fp13
  double v21; // fp2
  double v22; // fp5
  double v23; // fp4
  double x; // fp12
  double v25; // fp11
  double v26; // fp10
  double v27; // fp7
  double v28; // fp4
  double v29; // fp4
  double v30; // fp13
  double v31; // fp12
  double v32; // fp7
  double v33; // fp6
  double v34; // fp12
  double v35; // fp5
  double v36; // fp2
  double v37; // fp6
  double v38; // fp4
  double v39; // fp8
  double v44; // fp7
  double v46; // fp11
  double v48; // fp4
  double v49; // fp3
  double v50; // fp5
  double v51; // fp4
  double v52; // fp11
  double v53; // fp2
  double v54; // fp6
  double v55; // fp13
  int v61; // r24
  double v65; // fp13
  double v66; // fp12
  __int64 v67; // r26 OVERLAPPED
  float *p_z; // r3
  float *p_y; // r28
  float *v70; // r27
  double v73; // fp11
  double v74; // fp7
  double v75; // fp4
  double v76; // fp9
  double v77; // fp6
  double v78; // fp8
  double v80; // fp5
  double v81; // fp3
  double v82; // fp9
  double v83; // fp7
  double v84; // fp1
  double v85; // fp4
  double v86; // fp4
  double v87; // fp8
  double v88; // fp7
  double v89; // fp2
  double v90; // fp3
  double v91; // fp11
  double v92; // fp6
  double v93; // fp6
  double v94; // fp8
  double v95; // fp30
  double v96; // fp4
  double v97; // fp2
  double v98; // fp7
  double v99; // fp11
  double v104; // fp2
  double v105; // fp4
  double v106; // fp3
  double v107; // fp4
  int v123; // r3
  char v124; // r24 OVERLAPPED
  double v125; // fp11
  double v126; // fp1
  double v127; // fp9
  double v128; // fp6
  double v129; // fp3
  double v130; // fp31
  double v131; // fp4
  double v132; // fp7
  double v133; // fp2
  double v134; // fp8
  double v135; // fp30
  double v136; // fp5
  int v154; // r27
  float *p_scaleBiasX; // r17
  float *p_scaleBiasY; // r16
  int v157; // ctr
  idVec2 *p_size; // r25
  float *p_sizeScale; // r6
  float *v160; // r24
  float *p_depth; // r23
  float *v162; // r22
  float *v163; // r21
  float *v164; // r20
  float *v165; // r19
  float *v168; // r3
  float *v169; // r28
  double v172; // fp13
  double v176; // fp11
  double v177; // fp10
  double v178; // fp5
  double v179; // fp12
  double v180; // fp10
  double v181; // fp2
  double v182; // fp8
  double v183; // fp4
  double v184; // fp1
  double v185; // fp11
  double v188; // fp13
  double v189; // fp12
  double v190; // fp11
  float *v195; // [sp+8h] [-178h]
  float *v196; // [sp+14h] [-16Ch]
  float *v197; // [sp+18h] [-168h]
  float *v198; // [sp+20h] [-160h]
  __int64 v199; // [sp+20h] [-160h]
  __int64 v200; // [sp+20h] [-160h]
  int v201; // [sp+28h] [-158h]
  float v202; // [sp+30h] [-150h] BYREF
  float v203; // [sp+34h] [-14Ch]
  float v204; // [sp+38h] [-148h]
  float v205; // [sp+3Ch] [-144h]
  float v206; // [sp+40h] [-140h] BYREF
  float v207; // [sp+44h] [-13Ch]
  float v208; // [sp+48h] [-138h]
  float v209; // [sp+4Ch] [-134h]
  float v210; // [sp+50h] [-130h] BYREF
  float v211; // [sp+54h] [-12Ch]
  float v212; // [sp+58h] [-128h]
  float v213; // [sp+5Ch] [-124h]
  float v214; // [sp+60h] [-120h] BYREF
  float v215; // [sp+64h] [-11Ch]
  float v216; // [sp+68h] [-118h]
  float v217; // [sp+6Ch] [-114h]
  __int64 v218; // [sp+70h] [-110h] BYREF
  float v219; // [sp+78h] [-108h]
  float v220; // [sp+7Ch] [-104h]
  __int64 v221; // [sp+80h] [-100h]
  __int64 v222; // [sp+88h] [-F8h]
  __int64 v223; // [sp+90h] [-F0h]
  __int64 v224; // [sp+98h] [-E8h]
  __int64 v225; // [sp+A0h] [-E0h]
  __int64 v226; // [sp+A8h] [-D8h]

  LODWORD(_R11) = decal->startTime;
  HIDWORD(_R11) = &decal->axis;
  *(_DWORD *)&_R9[8] = *(_DWORD *)(v6 + 2064);
  *(_DWORD *)&_R9[4] = decal->fadeInTime + decal->startTime;
  *(_DWORD *)_R9 = &decal->pos;
  LODWORD(verts) = decal->fadeOutTime + decal->startTime;
  v8 = 0.0;
  if ( *(int *)&_R9[8] >= *(int *)&_R9[4] )
  {
    if ( *(int *)&_R9[8] > (int)verts )
    {
      v9 = decal->fadeOutTime + decal->startTime;
      LODWORD(verts) = *(_DWORD *)&_R9[8] - verts;
      v11 = (double)*(__int64 *)(&v3 - 1);
      v10 = decal->lifeTime + _R11;
      v8 = (float)((float)verts / (float)((float)*(__int64 *)(&v3 - 1) - (float)v11));
    }
  }
  else
  {
    LODWORD(verts) = _R11;
    LODWORD(_R11) = *(_DWORD *)&_R9[8] - _R11;
    *(_DWORD *)&_R9[8] = decal->fadeInTime + decal->startTime;
    v8 = (float)((float)1.0 - (float)((float)_R11 / (float)((float)*(__int64 *)&_R9[4] - (float)verts)));
  }
  if ( decal->quad )
  {
    v12 = (float)(decal->size.x * decal->sizeScale);
    v13 = (float)(decal->size.y * decal->sizeScale);
    *(idVec3 *)HIDWORD(verts) = simpleQuad[0];
    *(idVec3 *)(HIDWORD(verts) + 32) = simpleQuad[1];
    *(idVec3 *)(HIDWORD(verts) + 64) = simpleQuad[2];
    *(idVec3 *)(HIDWORD(verts) + 96) = simpleQuad[3];
    *(float *)HIDWORD(verts) = *(float *)HIDWORD(verts) * (float)v12;
    *(float *)(HIDWORD(verts) + 32) = (float)v12 * *(float *)(HIDWORD(verts) + 32);
    *(float *)(HIDWORD(verts) + 64) = (float)v12 * *(float *)(HIDWORD(verts) + 64);
    *(float *)(HIDWORD(verts) + 96) = (float)v12 * *(float *)(HIDWORD(verts) + 96);
    *(float *)(HIDWORD(verts) + 4) = *(float *)(HIDWORD(verts) + 4) * (float)v13;
    *(float *)(HIDWORD(verts) + 36) = *(float *)(HIDWORD(verts) + 36) * (float)v13;
    *(float *)(HIDWORD(verts) + 68) = *(float *)(HIDWORD(verts) + 68) * (float)v13;
    *(float *)(HIDWORD(verts) + 100) = *(float *)(HIDWORD(verts) + 100) * (float)v13;
    v14 = *(float *)HIDWORD(verts);
    y = decal->axis.mat[0].y;
    z = decal->axis.mat[0].z;
    v17 = (float)((float)(*(float *)(HIDWORD(verts) + 4) * decal->axis.mat[1].y)
                + (float)(*(float *)(HIDWORD(verts) + 8) * decal->axis.mat[2].y));
    v18 = (float)((float)(*(float *)(HIDWORD(verts) + 4) * decal->axis.mat[1].z)
                + (float)(*(float *)(HIDWORD(verts) + 8) * decal->axis.mat[2].z));
    *(float *)HIDWORD(verts) = (float)(*(float *)(HIDWORD(verts) + 4) * decal->axis.mat[1].x)
                             + (float)((float)(*(float *)HIDWORD(verts) * decal->axis.mat[0].x)
                                     + (float)(*(float *)(HIDWORD(verts) + 8) * decal->axis.mat[2].x));
    *(float *)(HIDWORD(verts) + 4) = (float)((float)v14 * (float)y) + (float)v17;
    *(float *)(HIDWORD(verts) + 8) = (float)((float)v14 * (float)z) + (float)v18;
    v19 = decal->axis.mat[1].z;
    v20 = *(float *)(HIDWORD(verts) + 36);
    v21 = *(float *)(HIDWORD(verts) + 32);
    v22 = *(float *)HIDWORD(_R11);
    v23 = decal->axis.mat[1].y;
    x = decal->axis.mat[1].x;
    v25 = decal->axis.mat[0].y;
    v26 = *(float *)(HIDWORD(verts) + 40);
    v204 = 0.0;
    v27 = (float)((float)v26 * decal->axis.mat[2].x);
    v28 = (float)((float)((float)v20 * (float)v23) + (float)((float)v26 * decal->axis.mat[2].y));
    *(float *)(HIDWORD(verts) + 40) = (float)((float)v21 * decal->axis.mat[0].z)
                                    + (float)((float)((float)v20 * (float)v19)
                                            + (float)((float)v26 * decal->axis.mat[2].z));
    *(float *)(HIDWORD(verts) + 36) = (float)((float)v21 * (float)v25) + (float)v28;
    *(float *)(HIDWORD(verts) + 32) = (float)((float)v20 * (float)x)
                                    + (float)((float)((float)v21 * (float)v22) + (float)v27);
    v29 = *(float *)(HIDWORD(verts) + 64);
    v30 = decal->axis.mat[0].y;
    v31 = decal->axis.mat[0].z;
    v32 = (float)((float)(*(float *)(HIDWORD(verts) + 68) * decal->axis.mat[1].y)
                + (float)(*(float *)(HIDWORD(verts) + 72) * decal->axis.mat[2].y));
    v33 = (float)((float)(*(float *)(HIDWORD(verts) + 68) * decal->axis.mat[1].z)
                + (float)(*(float *)(HIDWORD(verts) + 72) * decal->axis.mat[2].z));
    *(float *)(HIDWORD(verts) + 64) = (float)(*(float *)(HIDWORD(verts) + 68) * decal->axis.mat[1].x)
                                    + (float)((float)(*(float *)(HIDWORD(verts) + 64) * decal->axis.mat[0].x)
                                            + (float)(*(float *)(HIDWORD(verts) + 72) * decal->axis.mat[2].x));
    *(float *)(HIDWORD(verts) + 68) = (float)((float)v29 * (float)v30) + (float)v32;
    *(float *)(HIDWORD(verts) + 72) = (float)((float)v29 * (float)v31) + (float)v33;
    v34 = *(float *)(HIDWORD(verts) + 100);
    v35 = decal->axis.mat[1].y;
    v36 = *(float *)(HIDWORD(verts) + 96);
    v37 = *(float *)HIDWORD(_R11);
    v38 = (float)((float)(*(float *)(HIDWORD(verts) + 104) * decal->axis.mat[2].x)
                + (float)(decal->axis.mat[1].x * *(float *)(HIDWORD(verts) + 100)));
    v39 = (float)((float)(*(float *)(HIDWORD(verts) + 104) * decal->axis.mat[2].y)
                + (float)(decal->axis.mat[0].y * *(float *)(HIDWORD(verts) + 96)));
    *(float *)(HIDWORD(verts) + 104) = (float)(decal->axis.mat[1].z * *(float *)(HIDWORD(verts) + 100))
                                     + (float)((float)(*(float *)(HIDWORD(verts) + 104) * decal->axis.mat[2].z)
                                             + (float)(decal->axis.mat[0].z * *(float *)(HIDWORD(verts) + 96)));
    *(float *)(HIDWORD(verts) + 96) = (float)((float)v36 * (float)v37) + (float)v38;
    *(float *)(HIDWORD(verts) + 100) = (float)((float)v35 * (float)v34) + (float)v39;
    *(float *)HIDWORD(verts) = *(float *)HIDWORD(verts) + **(float **)_R9;
    _R30 = &v210;
    _R31 = &v202;
    *(float *)(HIDWORD(verts) + 4) = decal->pos.y + *(float *)(HIDWORD(verts) + 4);
    _R29 = &v214;
    *(float *)(HIDWORD(verts) + 8) = *(float *)(HIDWORD(verts) + 8) + decal->pos.z;
    _R11 = HIDWORD(verts) + 124;
    v44 = *(float *)(HIDWORD(verts) + 36);
    _R26 = 2;
    v46 = *(float *)(HIDWORD(verts) + 40);
    _R27 = 3;
    v208 = 0.0;
    v212 = 0.0;
    v216 = 0.0;
    *(float *)(HIDWORD(verts) + 32) = **(float **)_R9 + *(float *)(HIDWORD(verts) + 32);
    v205 = (float)((float)1.0 - (float)v8) * (float)255.0;
    v48 = v205;
    v49 = v205;
    v50 = (float)((float)v44 + decal->pos.y);
    v209 = v205;
    *(float *)(HIDWORD(verts) + 36) = v50;
    v213 = v48;
    v51 = decal->pos.z;
    v217 = v49;
    *(float *)(HIDWORD(verts) + 40) = (float)v46 + (float)v51;
    v52 = *(float *)(HIDWORD(verts) + 68);
    *(float *)(HIDWORD(verts) + 64) = **(float **)_R9 + *(float *)(HIDWORD(verts) + 64);
    v53 = *(float *)(HIDWORD(verts) + 72);
    *(float *)(HIDWORD(verts) + 68) = decal->pos.y + (float)v52;
    *(float *)(HIDWORD(verts) + 72) = (float)v53 + decal->pos.z;
    v54 = *(float *)(HIDWORD(verts) + 100);
    v55 = *(float *)(HIDWORD(verts) + 104);
    *(float *)(HIDWORD(verts) + 96) = **(float **)_R9 + *(float *)(HIDWORD(verts) + 96);
    *(float *)(HIDWORD(verts) + 100) = (float)v54 + decal->pos.y;
    *(float *)(HIDWORD(verts) + 104) = (float)v55 + decal->pos.z;
    _R7 = 1;
    *(float *)(HIDWORD(verts) + 12) = decal->scaleBiasX;
    *(float *)(HIDWORD(verts) + 44) = decal->scaleBiasX;
    *(float *)(HIDWORD(verts) + 76) = decal->scaleBiasX;
    *(float *)(HIDWORD(verts) + 108) = decal->scaleBiasX;
    *(float *)(HIDWORD(verts) + 16) = decal->scaleBiasY;
    *(float *)(HIDWORD(verts) + 48) = decal->scaleBiasY;
    *(float *)(HIDWORD(verts) + 80) = decal->scaleBiasY;
    *(float *)(HIDWORD(verts) + 112) = decal->scaleBiasY;
    _R4 = &v206;
    _R10 = HIDWORD(verts) + 28;
    v206 = simpleQuadST[1].x * (float)255.0;
    v210 = simpleQuadST[2].x * (float)255.0;
    _R8 = HIDWORD(verts) + 60;
    v207 = simpleQuadST[1].y * (float)255.0;
    _R9 = HIDWORD(verts) + 92;
    v211 = simpleQuadST[2].y * (float)255.0;
    v215 = simpleQuadST[3].y * (float)255.0;
    v214 = simpleQuadST[3].x * (float)255.0;
    v202 = simpleQuadST[0].x * (float)255.0;
    v203 = simpleQuadST[0].y * (float)255.0;
    __asm
    {
      lvx128    v62, r0, r29
      vcfpsxws128 v55, v62, 0
      lvx128    v63, r0, r4
      vpkswss128 v52, v87, v55
      lvx128    v59, r0, r30
      lvx128    v61, r0, r31
      vcfpsxws128 v60, v61, 0
      vcfpsxws128 v58, v63, 0
      vpkswss128 v56, v92, v60
      vcfpsxws128 v57, v59, 0
      vpkshus128 v11, v84, v52
      vpkshus128 v0, v88, v56
      stvebx    v0, 0, r10
      vpkswss128 v54, v90, v58
      vpkswss128 v53, v89, v57
      vpkshus128 v13, v86, v54
      vpkshus128 v12, v85, v53
      stvebx    v13, 0, r8
      stvebx    v12, 0, r9
      stvebx    v11, 0, r11
      stvebx    v0, r10, r7
      stvebx    v13, r8, r7
      stvebx    v12, r9, r7
      stvebx    v11, r11, r7
      stvebx    v0, r10, r26
      stvebx    v13, r8, r26
      stvebx    v12, r9, r26
      stvebx    v11, r11, r26
      stvebx    v0, r10, r27
      stvebx    v13, r8, r27
      stvebx    v12, r9, r27
      stvebx    v11, r11, r27
    }
  }
  else
  {
    v61 = 0;
    v201 = 0;
    _R31 = &`VertexFloatToByte'::`2'::SIMD_SP_255_over_2;
    _R30 = &`VertexFloatToByte'::`2'::SIMD_SP_half;
    _R29 = &_vmx_3f8000003f8000003f8000003f800000;
    if ( r_oldDecalGen.valueInteger != 0 )
      goto LABEL_13;
    *(_DWORD *)&_R9[4] = &decal->axis.mat[2];
    v65 = (float)(decal->size.x * decal->sizeScale);
    v66 = (float)(decal->size.y * decal->sizeScale);
    LODWORD(v67) = &decal->depth;
    HIDWORD(v67) = &decal->axis.mat[1];
    __asm { vspltisw128 v63, 0 }
    LODWORD(verts) = &decal->axis.mat[0].y;
    p_z = &decal->axis.mat[0].z;
    p_y = &decal->pos.y;
    v70 = &decal->pos.z;
    _R20 = &decal->axis.mat[2].z;
    LODWORD(_R11) = HIDWORD(verts) + 72;
    *(_DWORD *)&_R9[8] = &simpleCube[1].z;
    do
    {
      *(float *)(_R11 - 72) = *(float *)(*(_DWORD *)&_R9[8] - 20);
      LODWORD(_R23) = HIDWORD(_R11) + 16;
      DWORD2(_R23) = HIDWORD(_R11) + 32;
      DWORD1(_R23) = HIDWORD(_R11) + 20;
      *(float *)(_R11 - 68) = *(float *)(*(_DWORD *)&_R9[8] - 16);
      *(float *)(_R11 - 64) = *(float *)(*(_DWORD *)&_R9[8] - 12);
      *(float *)(_R11 - 40) = *(float *)(*(_DWORD *)&_R9[8] - 8);
      *(float *)(_R11 - 36) = *(float *)(*(_DWORD *)&_R9[8] - 4);
      *(float *)(_R11 - 32) = **(float **)&_R9[8];
      *(float *)(_R11 - 8) = *(float *)(*(_DWORD *)&_R9[8] + 4);
      *(float *)(_R11 - 4) = *(float *)(*(_DWORD *)&_R9[8] + 8);
      *(float *)_R11 = *(float *)(*(_DWORD *)&_R9[8] + 12);
      *(float *)(_R11 + 24) = *(float *)(*(_DWORD *)&_R9[8] + 16);
      *(float *)(_R11 + 28) = *(float *)(*(_DWORD *)&_R9[8] + 20);
      *(float *)(_R11 + 32) = *(float *)(*(_DWORD *)&_R9[8] + 24);
      *(float *)(_R11 - 72) = *(float *)(_R11 - 72) * (float)v65;
      *(float *)(_R11 - 40) = *(float *)(_R11 - 40) * (float)v65;
      *(float *)(_R11 - 8) = *(float *)(_R11 - 8) * (float)v65;
      *(float *)(_R11 + 24) = *(float *)(_R11 + 24) * (float)v65;
      *(float *)(_R11 - 68) = *(float *)(_R11 - 68) * (float)v66;
      *(float *)(_R11 - 36) = *(float *)(_R11 - 36) * (float)v66;
      *(float *)(_R11 - 4) = *(float *)(_R11 - 4) * (float)v66;
      *(float *)(_R11 + 28) = *(float *)(_R11 + 28) * (float)v66;
      *(float *)(_R11 - 64) = *(float *)(_R11 - 64) * *(float *)v67;
      *(float *)(_R11 - 32) = *(float *)(_R11 - 32) * *(float *)v67;
      *(float *)_R11 = *(float *)v67 * *(float *)_R11;
      *(float *)(_R11 + 32) = *(float *)(_R11 + 32) * *(float *)v67;
      v73 = *(float *)(_R11 - 64);
      v74 = *(float *)(_R11 - 68);
      v75 = *(float *)(_R11 - 72);
      v76 = *(float *)HIDWORD(v67);
      v77 = *(float *)(HIDWORD(_R11) + 32);
      v78 = (float)(*(float *)(_R11 - 68) * *(float *)(HIDWORD(_R11) + 20));
      v80 = *_R3;
      v81 = (float)((float)(*(float *)(_R11 - 72) * *(float *)HIDWORD(_R11))
                  + (float)(*(float *)(_R11 - 64) * **(float **)&_R9[4]));
      *(float *)(_R11 - 68) = (float)(*(float *)(_R11 - 72) * *(float *)verts)
                            + (float)((float)(*(float *)(_R11 - 64) * *(float *)(HIDWORD(_R11) + 28))
                                    + (float)(*(float *)(_R11 - 68) * *(float *)(HIDWORD(_R11) + 16)));
      *(float *)(_R11 - 72) = (float)((float)v74 * (float)v76) + (float)v81;
      *(float *)(_R11 - 64) = (float)((float)v80 * (float)v75) + (float)((float)((float)v73 * (float)v77) + (float)v78);
      v82 = *(float *)verts;
      v83 = *(float *)(_R11 - 40);
      v84 = (float)((float)(*(float *)(_R11 - 36) * *(float *)(HIDWORD(_R11) + 16))
                  + (float)(*(float *)(_R11 - 32) * *(float *)(HIDWORD(_R11) + 28)));
      v85 = (float)((float)(**(float **)&_R9[4] * *(float *)(_R11 - 32))
                  + (float)((float)(*(float *)(_R11 - 36) * *(float *)HIDWORD(v67))
                          + (float)(*(float *)(_R11 - 40) * *(float *)HIDWORD(_R11))));
      *(float *)(_R11 - 32) = (float)(*(float *)(HIDWORD(_R11) + 32) * *(float *)(_R11 - 32))
                            + (float)((float)(*_R3 * *(float *)(_R11 - 40))
                                    + (float)(*(float *)(HIDWORD(_R11) + 20) * *(float *)(_R11 - 36)));
      *(float *)(_R11 - 40) = v85;
      *(float *)(_R11 - 36) = (float)((float)v83 * (float)v82) + (float)v84;
      v86 = *(float *)_R11;
      v87 = *(float *)(_R11 - 8);
      v88 = *(float *)verts;
      v89 = *_R3;
      v90 = (float)((float)(*(float *)(_R11 - 4) * *(float *)(HIDWORD(_R11) + 16))
                  + (float)(*(float *)_R11 * *(float *)(HIDWORD(_R11) + 28)));
      v91 = (float)(*(float *)(HIDWORD(_R11) + 20) * *(float *)(_R11 - 4));
      v92 = *(float *)(HIDWORD(_R11) + 32);
      *(float *)(_R11 - 8) = (float)(*(float *)(_R11 - 8) * *(float *)HIDWORD(_R11))
                           + (float)((float)(**(float **)&_R9[4] * *(float *)_R11)
                                   + (float)(*(float *)(_R11 - 4) * *(float *)HIDWORD(v67)));
      *(float *)(_R11 - 4) = (float)((float)v87 * (float)v88) + (float)v90;
      *(float *)_R11 = (float)((float)v89 * (float)v87) + (float)((float)((float)v92 * (float)v86) + (float)v91);
      v93 = *(float *)(_R11 + 32);
      v94 = *(float *)(HIDWORD(_R11) + 32);
      v95 = *_R3;
      v96 = *(float *)(_R11 + 24);
      v97 = (float)(*(float *)(HIDWORD(_R11) + 20) * *(float *)(_R11 + 28));
      v98 = **(float **)&_R9[4];
      v99 = (float)((float)(*(float *)(_R11 + 28) * *(float *)HIDWORD(v67))
                  + (float)(*(float *)(_R11 + 24) * *(float *)HIDWORD(_R11)));
      *(float *)(_R11 + 28) = (float)(*(float *)(_R11 + 24) * *(float *)verts)
                            + (float)((float)(*(float *)(_R11 + 32) * *(float *)(HIDWORD(_R11) + 28))
                                    + (float)(*(float *)(_R11 + 28) * *(float *)(HIDWORD(_R11) + 16)));
      *(float *)(_R11 + 24) = (float)((float)v98 * (float)v93) + (float)v99;
      *(float *)(_R11 + 32) = (float)((float)v95 * (float)v96) + (float)((float)((float)v94 * (float)v93) + (float)v97);
      __asm { vor128    v51, v95, v63 }
      _R24 = *(_DWORD *)&_R9[4] + 4;
      _R19 = -51;
      _R18 = -50;
      _R17 = -52;
      *(float *)(_R11 - 72) = *(float *)(_R11 - 72) + **(float **)_R9;
      *(float *)(_R11 - 68) = *(float *)(_R11 - 68) + *p_y;
      *(float *)(_R11 - 64) = *(float *)(_R11 - 64) + *v70;
      v104 = *(float *)(_R11 - 32);
      *(float *)(_R11 - 40) = *(float *)(_R11 - 40) + **(float **)_R9;
      *(float *)(_R11 - 36) = *(float *)(_R11 - 36) + *p_y;
      *(float *)(_R11 - 32) = (float)v104 + *v70;
      v105 = *(float *)(_R11 - 4);
      *(float *)(_R11 - 8) = *(float *)(_R11 - 8) + **(float **)_R9;
      v106 = *(float *)_R11;
      *(float *)(_R11 - 4) = (float)v105 + *p_y;
      *(float *)_R11 = *v70 + (float)v106;
      v107 = *(float *)(_R11 + 32);
      *(float *)(_R11 + 24) = *(float *)(_R11 + 24) + **(float **)_R9;
      *(float *)(_R11 + 28) = *(float *)(_R11 + 28) + *p_y;
      *(float *)(_R11 + 32) = (float)v107 + *v70;
      *(float *)(_R11 - 60) = decal->scaleBiasX;
      *(float *)(_R11 - 28) = decal->scaleBiasX;
      *(float *)(_R11 + 4) = decal->scaleBiasX;
      *(float *)(_R11 + 36) = decal->scaleBiasX;
      *(float *)(_R11 - 56) = decal->scaleBiasY;
      *(float *)(_R11 - 24) = decal->scaleBiasY;
      *(float *)(_R11 + 8) = decal->scaleBiasY;
      *(float *)(_R11 + 40) = decal->scaleBiasY;
      __asm
      {
        lvlx128   v50, r0, r24
        lvlx128   v49, r0, r8
        vrlimi128 v51, v49, 8, 0
        lvlx128   v48, r0, r20
        vrlimi128 v51, v50, 4, 3
        lvx128    v62, r0, r29
        lvx128    v0, r0, r30
        lvx128    v13, r0, r31
        vrlimi128 v51, v48, 2, 2
      }
      v218 = *(_QWORD *)((char *)&_R23 + 4);
      __asm { vor128    v47, v95, v63 }
      _R16 = -20;
      _R15 = -19;
      __asm { vor128    v46, v95, v63 }
      _R14 = -18;
      v224 = *(_QWORD *)&_R9[4];
      __asm { vaddfp128 v12, v83, v62 }
      *(_DWORD *)&_R9[8] = 12;
      v223 = *(__int64 *)((char *)&verts + 4);
      HIDWORD(verts) = 13;
      v226 = *(_QWORD *)&decal;
      _R4 = 14;
      __asm { vor128    v45, v95, v63 }
      v225 = v67;
      v221 = *(__int64 *)((char *)&v67 + 4);
      __asm { vor128    v44, v95, v63 }
      v222 = _R23;
      _R26 = 44;
      v198 = _R20;
      _R25 = 45;
      v196 = v70;
      *((_QWORD *)&_R23 + 1) = 0xFFFFFFD00000002EuLL;
      DWORD1(_R23) = -47;
      _R27 = -46;
      __asm
      {
        vmaddfp   v0, v12, v0, v13
        vcfpsxws128 v43, v0, 0
        vpkswss128 v42, v75, v43
        vpkshus128 v0, v74, v42
        stvebx    v0, r11, r17
        stvebx    v0, r11, r19
        stvebx    v0, r11, r18
        lvlx128   v41, r0, r8
        vrlimi128 v47, v41, 8, 0
        lvlx128   v40, r0, r24
        lvlx128   v39, r0, r20
      }
      HIDWORD(_R23) = *(_DWORD *)&_R9[4] + 8;
      __asm { lvx128    v62, r0, r29 }
      _R24 = *(_DWORD *)&_R9[4] + 4;
      __asm
      {
        lvx128    v13, r0, r31
        vrlimi128 v47, v40, 4, 3
        lvx128    v0, r0, r30
        vrlimi128 v47, v39, 2, 2
        vaddfp128 v12, v79, v62
        vmaddfp   v0, v12, v0, v13
        vcfpsxws128 v38, v0, 0
        vpkswss128 v37, v70, v38
        vpkshus128 v0, v69, v37
        stvebx    v0, r11, r16
        stvebx    v0, r11, r15
        stvebx    v0, r11, r14
        lvx128    v13, r0, r31
        lvx128    v62, r0, r29
        lvlx128   v34, r0, r20
        lvx128    v0, r0, r30
        lvlx128   v36, r0, r8
        vrlimi128 v46, v36, 8, 0
        lvlx128   v35, r0, r24
        vrlimi128 v46, v35, 4, 3
        vrlimi128 v46, v34, 2, 2
        vaddfp128 v12, v78, v62
        vmaddfp   v0, v12, v0, v13
        vcfpsxws128 v33, v0, 0
        vpkswss128 v32, v65, v33
        vpkshus128 v0, v64, v32
        stvebx    v0, r11, r9
        stvebx    v0, r11, r5
        stvebx    v0, r11, r4
        lvlx128   v62, r0, r8
        vrlimi128 v45, v62, 8, 0
        lvx128    v62, r0, r29
        lvlx128   v61, r0, r24
        lvlx128   v60, r0, r20
        lvx128    v0, r0, r30
        vrlimi128 v45, v61, 4, 3
        lvx128    v13, r0, r31
        vrlimi128 v45, v60, 2, 2
        vaddfp128 v12, v77, v62
        vmaddfp   v0, v12, v0, v13
        vcfpsxws128 v59, v0, 0
        vor128    v57, v95, v63
      }
      _R24 = -16;
      __asm { vor128    v56, v95, v63 }
      _R19 = -15;
      __asm { vor128    v55, v95, v63 }
      _R18 = -14;
      _R17 = 16;
      _R16 = 17;
      _R15 = 18;
      _R14 = 48;
      *(_DWORD *)&_R9[8] = 49;
      HIDWORD(verts) = 50;
      __asm
      {
        vpkswss128 v58, v91, v59
        vpkshus128 v0, v90, v58
        stvebx    v0, r11, r26
        stvebx    v0, r11, r25
        stvebx    v0, r11, r23
        lvlx128   v54, r0, r10
        vrlimi128 v44, v54, 8, 0
        lvlx128   v53, r0, r6
        vrlimi128 v44, v53, 4, 3
        lvlx128   v52, r0, r3
        lvx128    v62, r0, r29
        lvx128    v13, r0, r31
        lvx128    v0, r0, r30
        vrlimi128 v44, v52, 2, 2
        vaddfp128 v12, v76, v62
        vmaddfp   v0, v12, v0, v13
        vcfpsxws128 v51, v0, 0
        vpkswss128 v50, v83, v51
        vpkshus128 v0, v82, v50
        stvebx    v0, r11, r22
        stvebx    v0, r11, r21
        stvebx    v0, r11, r27
        lvx128    v62, r0, r29
        lvx128    v13, r0, r31
        lvlx128   v49, r0, r10
        vrlimi128 v57, v49, 8, 0
        lvlx128   v48, r0, r6
        vrlimi128 v57, v48, 4, 3
        lvlx128   v47, r0, r3
        lvx128    v0, r0, r30
        vrlimi128 v57, v47, 2, 2
        vaddfp128 v12, v89, v62
        vmaddfp   v0, v12, v0, v13
        vcfpsxws128 v46, v0, 0
        vpkswss128 v45, v78, v46
        vpkshus128 v0, v77, v45
        stvebx    v0, r11, r24
        stvebx    v0, r11, r19
        stvebx    v0, r11, r18
        lvx128    v62, r0, r29
        lvx128    v0, r0, r30
        lvlx128   v44, r0, r10
        vrlimi128 v56, v44, 8, 0
        lvlx128   v43, r0, r6
        lvlx128   v42, r0, r3
        lvx128    v13, r0, r31
        vrlimi128 v56, v43, 4, 3
        vrlimi128 v56, v42, 2, 2
        vaddfp128 v12, v88, v62
        vmaddfp   v0, v12, v0, v13
        vcfpsxws128 v41, v0, 0
        vpkswss128 v40, v73, v41
        vpkshus128 v0, v72, v40
        stvebx    v0, r11, r17
        stvebx    v0, r11, r16
        stvebx    v0, r11, r15
        lvlx128   v39, r0, r3
        lvlx128   v37, r0, r6
        lvx128    v0, r0, r30
        lvlx128   v38, r0, r10
        vrlimi128 v55, v38, 8, 0
        vrlimi128 v55, v37, 4, 3
        lvx128    v62, r0, r29
        lvx128    v13, r0, r31
        vrlimi128 v55, v39, 2, 2
        vaddfp128 v12, v87, v62
        vmaddfp   v0, v12, v0, v13
        vcfpsxws128 v36, v0, 0
        vpkswss128 v35, v68, v36
      }
      v70 = v196;
      v123 = HIDWORD(v226);
      LODWORD(v67) = v225;
      *(__int64 *)((char *)&v67 + 4) = v221;
      __asm { vpkshus128 v0, v67, v35 }
      _R20 = v198;
      __asm
      {
        stvebx    v0, r11, r14
        stvebx    v0, r11, r9
      }
      *(_QWORD *)&_R9[4] = v224;
      __asm { stvebx    v0, r11, r5 }
      *(__int64 *)((char *)&verts + 4) = v223;
      v125 = (float)(*(float *)(_R11 - 72) - **(float **)_R9);
      v126 = (float)(*(float *)(_R11 + 24) - **(float **)_R9);
      v127 = (float)(*(float *)(_R11 - 68) - *p_y);
      v128 = (float)(*(float *)(_R11 - 36) - *p_y);
      v129 = (float)(*(float *)(_R11 - 4) - *p_y);
      v130 = (float)(*(float *)(_R11 + 28) - *p_y);
      v131 = (float)(*(float *)(_R11 - 8) - **(float **)_R9);
      v132 = (float)(*(float *)(_R11 - 40) - **(float **)_R9);
      v133 = (float)(*(float *)_R11 - *v196);
      v134 = (float)(*(float *)(_R11 - 64) - *v196);
      v135 = (float)(*(float *)(_R11 + 32) - *v196);
      v136 = (float)(*(float *)(_R11 - 32) - *v196);
      if ( v125 <= 0.0 )
        v124 = 0;
      v203 = __fabs(v127);
      v202 = __fabs(v125);
      v204 = __fabs(v134);
      v205 = (float)((float)1.0 - (float)v8) * (float)255.0;
      v206 = __fabs(v132);
      v207 = __fabs(v128);
      v208 = __fabs(v136);
      v209 = v205;
      v210 = __fabs(v131);
      v211 = __fabs(v129);
      v212 = __fabs(v133);
      v213 = v205;
      v214 = __fabs(v126);
      v216 = __fabs(v135);
      v217 = v205;
      _R14 = &v210;
      v215 = __fabs(v130);
      _R18 = &v214;
      v199 = *(__int64 *)((char *)&_R11 + 4);
      v218 = *(_QWORD *)_R9;
      _R15 = &v206;
      *(_BYTE *)(_R11 - 49) = (2 * ((2 * (v134 > 0.0)) | (v127 > 0.0))) | v124;
      _R17 = &v202;
      *(_BYTE *)(_R11 - 17) = (2 * ((2 * (v136 > 0.0)) | (v128 > 0.0))) | (v132 > 0.0);
      __asm { lvx128    v32, r0, r14 }
      __asm { lvx128    v61, r0, r18 }
      __asm { lvx128    v33, r0, r15 }
      *(_BYTE *)(_R11 + 15) = (2 * ((2 * (v133 > 0.0)) | (v129 > 0.0))) | (v131 > 0.0);
      __asm
      {
        lvx128    v34, r0, r17
        vcfpsxws128 v62, v34, 0
        vcfpsxws128 v60, v33, 0
      }
      __asm { vcfpsxws128 v59, v32, 0 }
      _R24 = -12;
      __asm { vcfpsxws128 v58, v61, 0 }
      *(_BYTE *)(_R11 + 47) = (2 * ((2 * (v135 > 0.0)) | (v130 > 0.0))) | (v126 > 0.0);
      _R23 = 20;
      __asm { vpkswss128 v57, v94, v62 }
      _R22 = -44;
      __asm
      {
        vpkswss128 v56, v92, v60
        vpkswss128 v55, v91, v59
        vpkshus128 v0, v89, v57
      }
      _R21 = 52;
      __asm { vpkshus128 v13, v88, v56 }
      _R19 = -43;
      __asm { vpkswss128 v54, v90, v58 }
      _R17 = -11;
      __asm { vpkshus128 v12, v87, v55 }
      _R16 = 21;
      _R15 = 53;
      v222 = *(__int64 *)((char *)&verts - 4);
      _R14 = -42;
      v221 = verts;
      __asm { vpkshus128 v11, v86, v54 }
      HIDWORD(_R11) = -10;
      __asm { stvebx    v0, r11, r22 }
      *(_DWORD *)&_R9[4] = 22;
      __asm { stvebx    v13, r11, r24 }
      *(_DWORD *)_R9 = 54;
      __asm { stvebx    v12, r11, r23 }
      _R22 = -41;
      _R23 = -9;
      __asm { stvebx    v11, r11, r21 }
      __asm { stvebx    v0, r11, r19 }
      v61 = v201 + 4;
      __asm { stvebx    v13, r11, r17 }
      __asm { stvebx    v12, r11, r16 }
      __asm { stvebx    v11, r11, r15 }
      __asm
      {
        stvebx    v0, r11, r14
        stvebx    v13, r11, r10
      }
      *(__int64 *)((char *)&_R11 + 4) = v199;
      __asm
      {
        stvebx    v12, r11, r8
        stvebx    v11, r11, r7
        stvebx    v0, r11, r22
        stvebx    v13, r11, r23
      }
      _R6 = HIDWORD(v222);
      _R23 = 23;
      __asm
      {
        stvebx    v12, r11, r23
        stvebx    v11, r11, r6
      }
      verts = v221;
      LODWORD(_R11) = _R11 + 128;
      *(_QWORD *)_R9 = v218;
      v201 += 4;
    }
    while ( v201 < 5 );
    if ( v61 < 8 )
    {
LABEL_13:
      __asm { vspltisw128 v62, 0 }
      v154 = 32 * v61 + HIDWORD(verts);
      p_scaleBiasX = &decal->scaleBiasX;
      p_scaleBiasY = &decal->scaleBiasY;
      v157 = 8 - v61;
      p_size = &decal->size;
      v197 = &decal->scaleBiasX;
      p_sizeScale = &decal->sizeScale;
      v220 = (float)((float)1.0 - (float)v8) * (float)255.0;
      p_depth = &decal->depth;
      v195 = &decal->scaleBiasY;
      *(_DWORD *)&_R9[8] = &simpleCube[v61].z;
      v160 = &decal->size.y;
      LODWORD(_R11) = v154 + 22;
      *(_DWORD *)&_R9[4] = HIDWORD(_R11) + 24;
      v162 = (float *)(HIDWORD(_R11) + 12);
      v163 = (float *)(HIDWORD(_R11) + 28);
      v164 = (float *)(HIDWORD(_R11) + 16);
      v165 = (float *)(HIDWORD(_R11) + 32);
      _R5 = (float *)(HIDWORD(_R11) + 8);
      _R4 = (float *)(HIDWORD(_R11) + 4);
      v168 = (float *)(*(_DWORD *)_R9 + 4);
      v169 = (float *)(*(_DWORD *)_R9 + 8);
      _R26 = 2;
      _R27 = 3;
      while ( 1 )
      {
        v172 = *(float *)(*(_DWORD *)&_R9[8] - 8);
        *(float *)(_R11 - 22) = *(float *)(*(_DWORD *)&_R9[8] - 8);
        _R18 = *(_DWORD *)&_R9[4] + 4;
        __asm { vor128    v53, v94, v62 }
        _R14 = -2;
        __asm { vor128    v47, v94, v62 }
        _R15 = -1;
        v176 = *(float *)(*(_DWORD *)&_R9[8] - 4);
        *(float *)(_R11 - 18) = *(float *)(*(_DWORD *)&_R9[8] - 4);
        v177 = **(float **)&_R9[8];
        *(float *)(_R11 - 14) = **(float **)&_R9[8];
        v178 = (float)((float)((float)v172 * *p_sizeScale) * p_size->x);
        *(float *)(_R11 - 22) = (float)((float)v172 * *p_sizeScale) * p_size->x;
        v179 = (float)((float)((float)v176 * *p_sizeScale) * *v160);
        *(float *)(_R11 - 18) = (float)((float)v176 * *p_sizeScale) * *v160;
        v180 = (float)((float)v177 * *p_depth);
        *(float *)(_R11 - 14) = v180;
        v181 = *(float *)HIDWORD(_R11);
        v182 = *_R5;
        v183 = (float)((float)(**(float **)&_R9[4] * (float)v180) + (float)(*v162 * (float)v179));
        v184 = (float)((float)(*(float *)(HIDWORD(_R11) + 20) * (float)v179) + (float)(*v165 * (float)v180));
        v185 = (float)((float)((float)v180 * *v163) + (float)((float)((float)v178 * *_R4) + (float)((float)v179 * *v164)));
        *(float *)(_R11 - 18) = (float)((float)v180 * *v163)
                              + (float)((float)((float)v178 * *_R4) + (float)((float)v179 * *v164));
        *(float *)(_R11 - 22) = (float)((float)v178 * (float)v181) + (float)v183;
        *(float *)(_R11 - 14) = (float)((float)v182 * (float)v178) + (float)v184;
        *(float *)(_R11 - 22) = (float)((float)((float)v178 * (float)v181) + (float)v183) + **(float **)_R9;
        *(float *)(_R11 - 18) = *v168 + (float)v185;
        *(float *)(_R11 - 14) = (float)((float)((float)v182 * (float)v178) + (float)v184) + *v169;
        *(float *)(_R11 - 10) = *p_scaleBiasX;
        *(float *)(_R11 - 6) = *p_scaleBiasY;
        __asm
        {
          lvx128    v63, r0, r29
          lvx128    v0, r0, r30
          lvlx128   v52, r0, r8
          vrlimi128 v53, v52, 8, 0
          lvlx128   v51, r0, r18
        }
        _R18 = *(_DWORD *)&_R9[4] + 8;
        __asm
        {
          lvx128    v13, r0, r31
          vrlimi128 v53, v51, 4, 3
          lvlx128   v50, r0, r18
          vrlimi128 v53, v50, 2, 2
          vaddfp128 v12, v85, v63
          vmaddfp   v0, v12, v0, v13
          vcfpsxws128 v49, v0, 0
          vpkswss128 v48, v81, v49
          vpkshus128 v0, v80, v48
          stvebx    v0, r11, r14
          stvebx    v0, r11, r15
        }
        _R18 = 4;
        __asm
        {
          stvebx    v0, 0, r11
          lvlx128   v46, r0, r10
          vrlimi128 v47, v46, 8, 0
          lvlx128   v45, r0, r4
          lvlx128   v44, r0, r5
          lvx128    v63, r0, r29
          lvx128    v0, r0, r30
          vrlimi128 v47, v45, 4, 3
          lvx128    v13, r0, r31
          vrlimi128 v47, v44, 2, 2
          vaddfp128 v12, v79, v63
          vmaddfp   v0, v12, v0, v13
          vcfpsxws128 v43, v0, 0
          vpkswss128 v42, v75, v43
          vpkshus128 v0, v74, v42
          stvebx    v0, r11, r26
          stvebx    v0, r11, r27
          stvebx    v0, r11, r18
        }
        v188 = (float)(*(float *)(_R11 - 22) - **(float **)_R9);
        v189 = (float)(*(float *)(_R11 - 18) - *v168);
        v190 = (float)(*(float *)(_R11 - 14) - *v169);
        *(float *)&v218 = __fabs(v188);
        *((float *)&v218 + 1) = __fabs(v189);
        v219 = __fabs(v190);
        _R15 = &v218;
        v200 = *(__int64 *)((char *)&_R11 + 4);
        _R17 = 6;
        _R14 = 7;
        _R16 = 8;
        HIDWORD(_R11) = 9;
        *(_BYTE *)(_R11 + 1) = (2 * ((2 * (v190 > 0.0)) | (v189 > 0.0))) | (v188 > 0.0);
        __asm
        {
          lvx128    v41, r0, r15
          vcfpsxws128 v40, v41, 0
          vpkswss128 v39, v72, v40
          vpkshus128 v0, v71, v39
          stvebx    v0, r11, r17
          stvebx    v0, r11, r14
          stvebx    v0, r11, r16
          stvebx    v0, r11, r10
        }
        *(__int64 *)((char *)&_R11 + 4) = v200;
        LODWORD(_R11) = _R11 + 32;
        if ( --v157 == 0 )
          break;
        p_scaleBiasY = v195;
        p_scaleBiasX = v197;
      }
    }
  }
}


// ========================================================================
// PackFloat
// EA  : 0x827FDD80
// RVA : 0x007FDD80
// PDB : w:\tech5\engine\models\rendermodeldecal.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall PackFloat(unsigned __int8 *val1, double number)
{
  double v3; // fp31
  long double v4; // fp2
  long double v5; // fp2
  int v6; // r11
  long double v7; // fp2
  int v8; // r11
  long double v9; // fp2
  int v10; // r11
  double v11; // fp31
  long double v12; // fp2
  int v13; // r11

  v3 = (float)((float)number * (float)0.001);
  *(double *)&v4 = v3;
  v5 = floor(x: v4);
  v6 = (int)(float)((float)((float)v3 - (float)*(double *)&v5) * (float)255.0);
  if ( v6 >= 0 )
  {
    if ( v6 > 255 )
      LOBYTE(v6) = -1;
  }
  else
  {
    LOBYTE(v6) = 0;
  }
  *val1 = v6;
  *(double *)&v5 = (float)((float)v3 * (float)256.0);
  v7 = floor(x: v5);
  v8 = (int)(float)((float)((float)((float)v3 * (float)256.0) - (float)*(double *)&v7) * (float)255.0);
  if ( v8 >= 0 )
  {
    if ( v8 > 255 )
      LOBYTE(v8) = -1;
  }
  else
  {
    LOBYTE(v8) = 0;
  }
  val1[1] = v8;
  *(double *)&v7 = (float)((float)v3 * (float)65536.0);
  v9 = floor(x: v7);
  v10 = (int)(float)((float)((float)((float)v3 * (float)65536.0) - (float)*(double *)&v9) * (float)255.0);
  if ( v10 >= 0 )
  {
    if ( v10 > 255 )
      LOBYTE(v10) = -1;
  }
  else
  {
    LOBYTE(v10) = 0;
  }
  val1[2] = v10;
  v11 = (float)((float)v3 * (float)16777216.0);
  *(double *)&v9 = v11;
  v12 = floor(x: v9);
  v13 = (int)(float)((float)((float)v11 - (float)*(double *)&v12) * (float)255.0);
  if ( v13 >= 0 )
  {
    if ( v13 > 255 )
      LOBYTE(v13) = -1;
  }
  else
  {
    LOBYTE(v13) = 0;
  }
  val1[3] = v13;
}


// ========================================================================
// ?GetDecalFromHandle@idRenderModelDecal@@AAAPAUdecalInfo_t@1@V?$idHandle@HW4invalidDecalHandle_t@@$0?0@@@Z
// EA  : 0x827FDF10
// RVA : 0x007FDF10
// PDB : w:\tech5\engine\models\rendermodeldecal.cpp
// ========================================================================

idRenderModelDecal::decalInfo_t *__fastcall idRenderModelDecal::GetDecalFromHandle(
        idRenderModelDecal *this,
        int decalHandle)
{
  idRenderModelDecal::decalInfo_t *result; // r3
  int v4; // r11
  int v5; // r10
  int v6; // r11

  result = nullptr;
  if ( decalHandle != -1 )
  {
    if ( decalHandle < 2048 )
    {
      v4 = this->decalRange[0] & 0x7FF;
      v5 = (this->decalRange[1] - 1) & 0x7FF;
      if ( v5 >= v4 )
      {
        v6 = (decalHandle >> 31) + (decalHandle >= (this->decalRange[0] & 0x7FFu));
      }
      else if ( decalHandle >= v4 || (LOBYTE(v6) = 0, decalHandle <= v5) )
      {
        LOBYTE(v6) = 1;
      }
      if ( (_BYTE)v6 != 0 )
        return __CFADD__(
                 this->decals[decalHandle].lifeTime - (this->gameTime - this->decals[decalHandle].startTime),
                 (this->gameTime - this->decals[decalHandle].startTime) ^ 0x80000000)
             ? nullptr
             : &this->decals[decalHandle];
    }
    else
    {
      return &this->decals[decalHandle];
    }
  }
  return result;
}


// ========================================================================
// ?DebugDrawDecals@idRenderModelDecal@@AAAXABVidVec3@@ABVidMat3@@PAVidDrawVert@@H@Z
// EA  : 0x827FDFC8
// RVA : 0x007FDFC8
// PDB : w:\tech5\engine\models\rendermodeldecal.cpp
// ========================================================================

void __fastcall idRenderModelDecal::DebugDrawDecals(
        idRenderModelDecal *this,
        const idVec3 *pos,
        const idMat3 *axis,
        idDrawVert *verts,
        int numVerts)
{
  idRenderWorld *v9; // r3
  idRenderWorld *v10; // r3
  idBox v11; // [sp+50h] [-70h] BYREF

  v9 = common->RW(this: common);
  v9->DebugAxis_2(this: v9, a2: pos, a3: axis, a4: 0, a5: false);
  if ( r_debugDecals.valueInteger > 1 && verts != nullptr && numVerts > 0 )
  {
    v11.center.z = 0.0;
    v11.center.y = 0.0;
    v11.center.x = 0.0;
    v11.axis.mat[2].z = 1.0;
    v11.axis.mat[1].y = 1.0;
    v11.axis.mat[0].x = 1.0;
    v11.axis.mat[1].z = 0.0;
    v11.axis.mat[0].z = 0.0;
    v11.axis.mat[0].y = 0.0;
    v11.extents.z = -1.0e30;
    v11.extents.y = v11.extents.z;
    v11.extents.x = v11.extents.z;
    v11.axis.mat[2].y = 0.0;
    v11.axis.mat[2].x = 0.0;
    v11.axis.mat[1].x = 0.0;
    do
    {
      idBox::AddPoint(this: &v11, v: &verts->xyz);
      --numVerts;
      ++verts;
    }
    while ( numVerts != 0 );
    v10 = common->RW(this: common);
    v10->DebugBox(this: v10, a2: (const idVec4 *)&idColor::colorWhite, a3: &v11, a4: 0, a5: false);
  }
}


// ========================================================================
// BuildIndexBufferBoxes
// EA  : 0x827FE100
// RVA : 0x007FE100
// PDB : w:\tech5\engine\models\rendermodeldecal.cpp
// ========================================================================

void __fastcall BuildIndexBufferBoxes(idIndexBuffer *indexBuffer)
{
  char *v2; // r30
  int v3; // r10
  char *v4; // r11
  int i; // ctr

  v2 = (char *)idMem::AllocWithLocation(
                 this: &mem,
                 location: "w:\\tech5\\shared\\idlib\\Heap.h(149) : TAG_TEMP",
                 size: 0x2F400u,
                 tag: TAG_TEMP,
                 zeroBuffer: false,
                 align: ALIGN_16,
                 heap: HEAP_DEFAULTHEAP);
  v3 = 2;
  v4 = v2 - 2;
  for ( i = 2688; i != 0; --i )
  {
    *((_WORD *)v4 + 1) = v3;
    *((_WORD *)v4 + 2) = v3 + 1;
    *((_WORD *)v4 + 3) = v3 - 2;
    *((_WORD *)v4 + 4) = v3 - 1;
    *((_WORD *)v4 + 5) = v3;
    *((_WORD *)v4 + 6) = v3 - 2;
    *((_WORD *)v4 + 7) = v3 + 3;
    *((_WORD *)v4 + 8) = v3 - 1;
    *((_WORD *)v4 + 9) = v3 - 2;
    *((_WORD *)v4 + 10) = v3 + 2;
    *((_WORD *)v4 + 11) = v3 + 3;
    *((_WORD *)v4 + 12) = v3 - 2;
    *((_WORD *)v4 + 13) = v3 + 5;
    *((_WORD *)v4 + 14) = v3 + 2;
    *((_WORD *)v4 + 15) = v3 - 2;
    *((_WORD *)v4 + 16) = v3 + 1;
    *((_WORD *)v4 + 17) = v3 + 5;
    *((_WORD *)v4 + 18) = v3 - 2;
    *((_WORD *)v4 + 19) = v3 - 1;
    *((_WORD *)v4 + 20) = v3 + 3;
    *((_WORD *)v4 + 21) = v3 + 4;
    *((_WORD *)v4 + 22) = v3;
    *((_WORD *)v4 + 23) = v3 - 1;
    *((_WORD *)v4 + 24) = v3 + 4;
    *((_WORD *)v4 + 25) = v3 + 1;
    *((_WORD *)v4 + 26) = v3;
    *((_WORD *)v4 + 27) = v3 + 4;
    *((_WORD *)v4 + 28) = v3 + 5;
    *((_WORD *)v4 + 29) = v3 + 1;
    *((_WORD *)v4 + 30) = v3 + 4;
    *((_WORD *)v4 + 31) = v3 + 2;
    *((_WORD *)v4 + 32) = v3 + 5;
    *((_WORD *)v4 + 33) = v3 + 4;
    *((_WORD *)v4 + 34) = v3 + 3;
    *((_WORD *)v4 + 35) = v3 + 2;
    v4 += 72;
    *(_WORD *)v4 = v3 + 4;
    v3 += 8;
  }
  idIndexBuffer::AllocBufferObject(this: indexBuffer, data: v2, allocSize: 193536, allocUsage: BU_DYNAMIC);
  if ( v2 != nullptr )
    idMem::Free(this: &mem, ptr: v2, align: ALIGN_16);
}


// ========================================================================
// __unwind$233546
// EA  : 0x827FE284
// RVA : 0x007FE284
// PDB : w:\tech5\engine\models\rendermodeldecal.cpp
// ========================================================================

void _unwind_233546()
{
  int v0; // r12

  idTempArray<idPlane>::~idTempArray<idPlane>(this: (idTempArray<int> *)(v0 - 160 + 80));
}


// ========================================================================
// BuildIndexBufferQuads
// EA  : 0x827FE2B8
// RVA : 0x007FE2B8
// PDB : w:\tech5\engine\models\rendermodeldecal.cpp
// ========================================================================

void __fastcall BuildIndexBufferQuads(idIndexBuffer *indexBuffer)
{
  char *v2; // r30
  int v3; // r10
  char *v4; // r11
  int i; // ctr

  v2 = (char *)idMem::AllocWithLocation(
                 this: &mem,
                 location: "w:\\tech5\\shared\\idlib\\Heap.h(149) : TAG_TEMP",
                 size: 0xFC00u,
                 tag: TAG_TEMP,
                 zeroBuffer: false,
                 align: ALIGN_16,
                 heap: HEAP_DEFAULTHEAP);
  v3 = 2;
  v4 = v2 - 2;
  for ( i = 5376; i != 0; --i )
  {
    *((_WORD *)v4 + 1) = v3;
    *((_WORD *)v4 + 2) = v3 - 1 + 2;
    *((_WORD *)v4 + 3) = v3 - 2;
    *((_WORD *)v4 + 4) = v3 - 1;
    *((_WORD *)v4 + 5) = v3;
    v4 += 12;
    *(_WORD *)v4 = v3 - 2;
    v3 += 4;
  }
  idIndexBuffer::AllocBufferObject(this: indexBuffer, data: v2, allocSize: 64512, allocUsage: BU_DYNAMIC);
  if ( v2 != nullptr )
    idMem::Free(this: &mem, ptr: v2, align: ALIGN_16);
}


// ========================================================================
// __unwind$233691
// EA  : 0x827FE398
// RVA : 0x007FE398
// PDB : w:\tech5\engine\models\rendermodeldecal.cpp
// ========================================================================

void _unwind_233691()
{
  int v0; // r12

  idTempArray<idPlane>::~idTempArray<idPlane>(this: (idTempArray<int> *)(v0 - 128 + 80));
}


// ========================================================================
// ?Init@idRenderModelDecal@@SAXXZ
// EA  : 0x827FE3C0
// RVA : 0x007FE3C0
// PDB : w:\tech5\engine\models\rendermodeldecal.cpp
// ========================================================================

static void __fastcall idRenderModelDecal::Init()
{
  idVertexBuffer *v0; // r31

  v0 = idRenderModelDecal::preAllocatedVertexBuffer;
  do
    idVertexBuffer::AllocBufferObject(
      this: v0++,
      data: nullptr,
      allocSize: 688128,
      vertexMask: 31,
      allocUsage: BU_DYNAMIC);
  while ( (int)v0 < (int)&idRenderModelDecal::preAllocatedIndexBufferBoxes );
  BuildIndexBufferBoxes(indexBuffer: &idRenderModelDecal::preAllocatedIndexBufferBoxes);
  BuildIndexBufferQuads(indexBuffer: &idRenderModelDecal::preAllocatedIndexBufferQuads);
  idRenderModelDecal::preAllocatedBufferInUse = false;
}


// ========================================================================
// ??0idRenderModelDecal@@QAA@XZ
// EA  : 0x827FE450
// RVA : 0x007FE450
// PDB : w:\tech5\engine\models\rendermodeldecal.cpp
// ========================================================================

idRenderModelDecal *__fastcall idRenderModelDecal::idRenderModelDecal(idRenderModelDecal *this)
{
  idTriangles *v2; // r29
  idVertexBuffer *vertexBuffer; // r28
  idVertexBuffer *v4; // r27
  const idVertexBuffer *v5; // r28
  int i; // r27
  _DWORD *v7; // r3
  int v8; // r11
  int j; // ctr
  float *v10; // r10
  float *v11; // r10
  idTriangles *v12; // r10
  float *v13; // r10
  float *v14; // r10
  float *v15; // r10
  float *v16; // r10
  float *v17; // r10

  idRenderModel::idRenderModel(this);
  v2 = nullptr;
  this->__vftable = (idRenderModelDecal_vtbl *)&idRenderModelDecal::`vftable';
  this->random.seed = 0;
  vertexBuffer = this->vertexBuffer;
  `eh vector constructor iterator'(
    ptr: this->vertexBuffer,
    size: 0x10u,
    count: 2,
    pCtor: (void (__fastcall *)(void *))idIndexBuffer::idIndexBuffer,
    pDtor: (void (__fastcall *)(void *))idVertexBuffer::~idVertexBuffer);
  idIndexBuffer::idIndexBuffer(this: &this->indexBufferBoxes);
  idIndexBuffer::idIndexBuffer(this: &this->indexBufferQuads);
  idRenderModel::SetAxis(this, a: &mat3_identity);
  idRenderModel::FreeSurfaces(this);
  *((_BYTE *)&this->g + 105) |= 0x84u;
  this->parmPositionToLocalBoxSpace[0] = (const idDeclRenderParm *)idDeclInfo::FindWithInheritance(
                                                                     this: &idDeclRenderParm::resourceList,
                                                                     name: "decalPosToLocalBoxSpaceX",
                                                                     makeDefault: true);
  this->parmPositionToLocalBoxSpace[1] = (const idDeclRenderParm *)idDeclInfo::FindWithInheritance(
                                                                     this: &idDeclRenderParm::resourceList,
                                                                     name: "decalPosToLocalBoxSpaceY",
                                                                     makeDefault: true);
  this->parmPositionToLocalBoxSpace[2] = (const idDeclRenderParm *)idDeclInfo::FindWithInheritance(
                                                                     this: &idDeclRenderParm::resourceList,
                                                                     name: "decalPosToLocalBoxSpaceZ",
                                                                     makeDefault: true);
  this->parmPositionToLocalBoxSpace[3] = (const idDeclRenderParm *)idDeclInfo::FindWithInheritance(
                                                                     this: &idDeclRenderParm::resourceList,
                                                                     name: "decalPosToLocalBoxSpaceW",
                                                                     makeDefault: true);
  this->gameTime = 0;
  this->latchedTime = 0;
  this->decalRange[1] = 0;
  this->decalRange[0] = 0;
  this->tireDecalRange[1] = 0;
  this->tireDecalRange[0] = 0;
  this->latchedDecalRange[1] = 0;
  this->latchedDecalRange[0] = 0;
  this->latchedTireDecalRange[1] = 0;
  this->latchedTireDecalRange[0] = 0;
  if ( idRenderModelDecal::preAllocatedBufferInUse )
  {
    BuildIndexBufferBoxes(indexBuffer: &this->indexBufferBoxes);
    BuildIndexBufferQuads(indexBuffer: &this->indexBufferQuads);
    for ( i = 2; i != 0; --i )
      idVertexBuffer::AllocBufferObject(
        this: vertexBuffer++,
        data: nullptr,
        allocSize: 688128,
        vertexMask: 31,
        allocUsage: BU_DYNAMIC);
    this->usesPreAllocatedBuffer = false;
  }
  else
  {
    v4 = this->vertexBuffer;
    v5 = idRenderModelDecal::preAllocatedVertexBuffer;
    do
      idVertexBuffer::Reference(this: v4++, other: v5++);
    while ( (int)v5 < (int)&idRenderModelDecal::preAllocatedIndexBufferBoxes );
    idIndexBuffer::Reference(this: &this->indexBufferBoxes, other: &idRenderModelDecal::preAllocatedIndexBufferBoxes);
    idIndexBuffer::Reference(this: &this->indexBufferQuads, other: &idRenderModelDecal::preAllocatedIndexBufferQuads);
    idRenderModelDecal::preAllocatedBufferInUse = true;
    this->usesPreAllocatedBuffer = true;
  }
  v7 = idMem::AllocWithLocation(
         this: &mem,
         location: "w:\\tech5\\shared\\idlib\\Heap.h(82) : tag",
         size: 0x1084u,
         tag: TAG_TRIANGLES,
         zeroBuffer: false,
         align: ALIGN_16,
         heap: HEAP_DEFAULTHEAP);
  if ( v7 != nullptr )
  {
    v2 = (idTriangles *)(v7 + 1);
    *v7 = 32;
    `eh vector constructor iterator'(
      ptr: v7 + 1,
      size: 0x84u,
      count: 32,
      pCtor: (void (__fastcall *)(void *))idTriangles::idTriangles,
      pDtor: (void (__fastcall *)(void *))idTriangles::~idTriangles);
  }
  this->triangles = v2;
  v8 = 3;
  for ( j = 4; j != 0; --j )
  {
    v10 = (float *)&this->triangles[v8 - 3];
    *v10 = -99999.0;
    v10[3] = 99999.0;
    v10[2] = -99999.0;
    v10[1] = -99999.0;
    v10[5] = 99999.0;
    v10[4] = 99999.0;
    v11 = (float *)&this->triangles[v8 - 3];
    v11[35] = -99999.0;
    v11[34] = -99999.0;
    v11[33] = -99999.0;
    v11[38] = 99999.0;
    v11[37] = 99999.0;
    v11[36] = 99999.0;
    v12 = &this->triangles[v8];
    v12[-1].bounds.b[0].z = -99999.0;
    v12[-1].bounds.b[0].y = -99999.0;
    v12[-1].bounds.b[0].x = -99999.0;
    v12[-1].bounds.b[1].z = 99999.0;
    v12[-1].bounds.b[1].y = 99999.0;
    v12[-1].bounds.b[1].x = 99999.0;
    v13 = (float *)&this->triangles[v8];
    v13[2] = -99999.0;
    v13[1] = -99999.0;
    *v13 = -99999.0;
    v13[5] = 99999.0;
    v13[4] = 99999.0;
    v13[3] = 99999.0;
    v14 = (float *)&this->triangles[v8];
    v14[35] = -99999.0;
    v14[34] = -99999.0;
    v14[33] = -99999.0;
    v14[38] = 99999.0;
    v14[37] = 99999.0;
    v14[36] = 99999.0;
    v15 = (float *)&this->triangles[v8];
    v15[68] = -99999.0;
    v15[67] = -99999.0;
    v15[66] = -99999.0;
    v15[71] = 99999.0;
    v15[70] = 99999.0;
    v15[69] = 99999.0;
    v16 = (float *)&this->triangles[v8];
    v16[101] = -99999.0;
    v16[100] = -99999.0;
    v16[99] = -99999.0;
    v16[104] = 99999.0;
    v16[103] = 99999.0;
    v16[102] = 99999.0;
    v17 = (float *)&this->triangles[v8];
    v17[134] = -99999.0;
    v8 += 8;
    v17[133] = -99999.0;
    v17[132] = -99999.0;
    v17[137] = 99999.0;
    v17[136] = 99999.0;
    v17[135] = 99999.0;
  }
  this->decals = (idRenderModelDecal::decalInfo_t *)idMem::AllocWithLocation(
                                                      this: &mem,
                                                      location: "w:\\tech5\\engine\\models\\RenderModelDecal.cpp(349) : TAG_EFFECT_PARTICLE",
                                                      size: 0x35200u,
                                                      tag: TAG_EFFECT_PARTICLE,
                                                      zeroBuffer: true,
                                                      align: ALIGN_16,
                                                      heap: HEAP_DEFAULTHEAP);
  this->tireDecals = (idRenderModelDecal::tireDecalInfo_t *)idMem::AllocWithLocation(
                                                              this: &mem,
                                                              location: "w:\\tech5\\engine\\models\\RenderModelDecal.cpp(350) : TAG"
                                                              "_EFFECT_PARTICLE",
                                                              size: 0xF800u,
                                                              tag: TAG_EFFECT_PARTICLE,
                                                              zeroBuffer: true,
                                                              align: ALIGN_16,
                                                              heap: HEAP_DEFAULTHEAP);
  return this;
}


// ========================================================================
// __unwind$233761
// EA  : 0x827FE81C
// RVA : 0x007FE81C
// PDB : w:\tech5\engine\models\rendermodeldecal.cpp
// ========================================================================

void _unwind_233761()
{
  int v0; // r12

  idRenderModel::~idRenderModel(this: *(idRenderModel **)(v0 - 176 + 196));
}


// ========================================================================
// __unwind$233762
// EA  : 0x827FE844
// RVA : 0x007FE844
// PDB : w:\tech5\engine\models\rendermodeldecal.cpp
// ========================================================================

void _unwind_233762()
{
  int v0; // r12

  `eh vector destructor iterator'(
    ptr: (void *)(*(_DWORD *)(v0 - 176 + 196) + 2084),
    size: 0x10u,
    count: 2,
    pDtor: (void (__fastcall *)(void *))idVertexBuffer::~idVertexBuffer);
}


// ========================================================================
// __unwind$233763
// EA  : 0x827FE880
// RVA : 0x007FE880
// PDB : w:\tech5\engine\models\rendermodeldecal.cpp
// ========================================================================

void _unwind_233763()
{
  int v0; // r12

  idIndexBuffer::~idIndexBuffer(this: (idIndexBuffer *)(*(_DWORD *)(v0 - 176 + 196) + 2116));
}


// ========================================================================
// __unwind$233764
// EA  : 0x827FE8AC
// RVA : 0x007FE8AC
// PDB : w:\tech5\engine\models\rendermodeldecal.cpp
// ========================================================================

void _unwind_233764()
{
  int v0; // r12

  idIndexBuffer::~idIndexBuffer(this: (idIndexBuffer *)(*(_DWORD *)(v0 - 176 + 196) + 2132));
}


// ========================================================================
// __unwind$233765
// EA  : 0x827FE8D8
// RVA : 0x007FE8D8
// PDB : w:\tech5\engine\models\rendermodeldecal.cpp
// ========================================================================

void _unwind_233765()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 176 + 80), tag: TAG_TRIANGLES);
}


// ========================================================================
// ?GenSphericalDecalVerts@idRenderModelDecal@@AAAXPBUdecalInfo_t@1@PAVidDrawVert@@@Z
// EA  : 0x827FE968
// RVA : 0x007FE968
// PDB : w:\tech5\engine\models\rendermodeldecal.cpp
// ========================================================================

void __fastcall idRenderModelDecal::GenSphericalDecalVerts(
        idRenderModelDecal *this,
        const idRenderModelDecal::decalInfo_t *decal,
        idDrawVert *verts)
{
  char *v4; // r10
  float *p_z; // r11
  int i; // ctr
  float z; // r6
  double v14; // fp27
  double v15; // fp26
  double v16; // fp25
  idVec2 *p_size; // r29
  double v18; // fp24
  double y; // fp23
  float *p_scaleBiasX; // r20
  double x; // fp22
  float *p_scaleBiasY; // r19
  double v23; // fp21
  double v25; // fp20
  float *v26; // r30
  double v27; // fp19
  double v30; // fp16
  double v32; // fp17
  double v34; // fp18
  double v39; // fp0
  double v40; // fp13
  double v41; // fp12
  double v42; // fp9
  double v43; // fp6
  double v44; // fp1
  double v45; // fp0
  double v47; // fp7
  double v48; // fp8
  double v49; // fp6
  BOOL v50; // r9
  float v51; // [sp+58h] [-198h]
  float v52; // [sp+5Ch] [-194h]
  float v53; // [sp+60h] [-190h]
  char v54; // [sp+6Ch] [-184h] BYREF
  float v55; // [sp+70h] [-180h] BYREF
  float v56; // [sp+74h] [-17Ch] BYREF
  float v57; // [sp+78h] [-178h] BYREF
  idVec3 v58; // [sp+7Ch] [-174h] BYREF
  float v59; // [sp+88h] [-168h] BYREF
  float v60; // [sp+8Ch] [-164h] BYREF
  float v61; // [sp+90h] [-160h] BYREF

  v4 = &v54;
  p_z = &decal->pos.z;
  for ( i = 9; i != 0; --i )
  {
    ++p_z;
    v4 += 4;
    *(float *)v4 = *p_z;
  }
  __asm { vspltisw128 v126, 0 }
  _R11 = &v55;
  _R10 = &v56;
  *(float *)&_R8 = decal->pos.y;
  LODWORD(_R8) = &v57;
  z = decal->pos.z;
  _R31 = &v60;
  __asm { vmr128    v63, v126 }
  __asm { lvlx128   v62, r0, r11 }
  __asm
  {
    lvlx128   v61, r0, r10
    lvlx128   v60, r0, r8
  }
  _R30 = &v59;
  __asm { vrlimi128 v63, v62, 8, 0 }
  _R3 = &v61;
  __asm { lvlx128   v124, r0, r31 }
  v14 = v61;
  v15 = v60;
  __asm { vor128    v127, v95, v63 }
  __asm { lvlx128   v123, r0, r30 }
  __asm { lvlx128   v125, r0, r3 }
  v16 = v59;
  p_size = &decal->size;
  __asm { vrlimi128 v127, v61, 4, 3 }
  v18 = v58.z;
  y = v58.y;
  p_scaleBiasX = &decal->scaleBiasX;
  x = v58.x;
  p_scaleBiasY = &decal->scaleBiasY;
  v23 = v57;
  _R31 = &verts->xyz.y;
  v25 = v56;
  v26 = &simpleCube[0].z;
  v27 = v55;
  __asm { vrlimi128 v127, v60, 2, 2 }
  _R28 = &`VertexFloatToByte'::`2'::SIMD_SP_255_over_2;
  _R21 = 16;
  v30 = decal->pos.x;
  _R27 = &`VertexFloatToByte'::`2'::SIMD_SP_half;
  v32 = *(float *)&_R8;
  _R22 = -1;
  v34 = z;
  _R23 = 20;
  _R26 = &_vmx_3f8000003f8000003f8000003f800000;
  _R24 = 3;
  _R25 = 4;
  do
  {
    v39 = *(v26 - 2);
    __asm { vmr128    v59, v126 }
    *(_R31 - 1) = *(v26 - 2);
    v40 = *(v26 - 1);
    *_R31 = *(v26 - 1);
    __asm { vrlimi128 v59, v123, 8, 0 }
    v41 = *v26;
    _R31[1] = *v26;
    __asm { vrlimi128 v59, v124, 4, 3 }
    v42 = (float)((float)v39 * p_size->x);
    *(_R31 - 1) = (float)v39 * p_size->x;
    v43 = (float)(p_size->x * (float)v40);
    *_R31 = p_size->x * (float)v40;
    v44 = (float)((float)v41 * p_size->x);
    v45 = (float)((float)((float)v41 * p_size->x) * (float)v15);
    _R31[1] = (float)v41 * p_size->x;
    *((float *)&_R8 + 1) = _R31[1];
    __asm { vrlimi128 v59, v125, 2, 2 }
    _R11 = (char *)_R31 + 18;
    v53 = *((float *)&_R8 + 1);
    v51 = *(_R31 - 1);
    v47 = (float)((float)((float)v44 * (float)v16)
                + (float)((float)((float)v42 * (float)v27) + (float)((float)v43 * (float)x)));
    v52 = *_R31;
    v48 = (float)((float)((float)v43 * (float)y) + (float)((float)((float)v42 * (float)v25) + (float)v45));
    v49 = (float)((float)((float)v43 * (float)v18)
                + (float)((float)((float)v42 * (float)v23) + (float)((float)v44 * (float)v14)));
    _R31[1] = v49;
    *(_R31 - 1) = (float)v30 + (float)v47;
    *_R31 = (float)v32 + (float)v48;
    _R31[1] = (float)v49 + (float)v34;
    _R31[2] = *p_scaleBiasX;
    _R31[3] = *p_scaleBiasY;
    __asm
    {
      lvx128    v13, r0, r28
      lvx128    v0, r0, r27
      lvx128    v63, r0, r26
      vaddfp128 v12, v91, v63
      vmaddfp   v0, v12, v0, v13
      vcfpsxws128 v58, v0, 0
      vpkswss128 v57, v90, v58
      vpkshus128 v0, v89, v57
      stvebx    v0, r31, r21
      stvebx    v0, r11, r22
      stvebx    v0, 0, r11
      lvx128    v0, r0, r27
      lvx128    v13, r0, r28
      lvx128    v63, r0, r26
      vaddfp128 v12, v127, v63
      vmaddfp   v0, v12, v0, v13
      vcfpsxws128 v56, v0, 0
      vpkswss128 v55, v88, v56
      vpkshus128 v0, v87, v55
      stvebx    v0, r31, r23
      stvebx    v0, r11, r24
      stvebx    v0, r11, r25
    }
    idDrawVert::SetBiTangent(this: (idDrawVert *)(_R31 - 1), t: &v58, a3: (int)verts, a4: SLODWORD(z), a5: _R8);
    PackFloat(
      val1: (unsigned __int8 *)_R31 + 24,
      number: __fsqrts((float)((float)(v51 * v51) + (float)((float)(v53 * v53) + (float)(v52 * v52)))));
    v50 = v51 > 0.0;
    v26 += 3;
    HIDWORD(_R8) = 2 * ((2 * (v53 > 0.0)) | (v52 > 0.0));
    z = COERCE_FLOAT((idVec3 *)&simpleQuad[0].z);
    verts = (idDrawVert *)(HIDWORD(_R8) | v50);
    *((_BYTE *)_R31 + 19) = (2 * ((2 * (v53 > 0.0)) | (v52 > 0.0))) | v50;
    _R31 += 8;
  }
  while ( (int)v26 < (int)&simpleQuad[0].z );
}


// ========================================================================
// ?SetDecalPosition@idRenderModelDecal@@QAA_NV?$idHandle@HW4invalidDecalHandle_t@@$0?0@@ABVidVec3@@ABVidMat3@@@Z
// EA  : 0x827FEC60
// RVA : 0x007FEC60
// PDB : w:\tech5\engine\models\rendermodeldecal.cpp
// ========================================================================

idRenderModelDecal::decalInfo_t *__fastcall idRenderModelDecal::SetDecalPosition(
        idRenderModelDecal *this,
        const idHandle<int,enum invalidDecalHandle_t,-1> *decalHandle,
        const idVec3 *decalWorldPosition,
        const idMat3 *decalWorldAxis)
{
  idRenderModelDecal::decalInfo_t *result; // r3
  float *p_startTime; // r11

  result = idRenderModelDecal::GetDecalFromHandle(this, (int)decalHandle);
  p_startTime = (float *)&result->startTime;
  if ( result != nullptr )
  {
    result->axis.mat[0].x = decalWorldAxis->mat[0].x;
    p_startTime[12] = decalWorldAxis->mat[0].y;
    p_startTime[13] = decalWorldAxis->mat[0].z;
    p_startTime[14] = decalWorldAxis->mat[1].x;
    p_startTime[15] = decalWorldAxis->mat[1].y;
    p_startTime[16] = decalWorldAxis->mat[1].z;
    p_startTime[17] = decalWorldAxis->mat[2].x;
    p_startTime[18] = decalWorldAxis->mat[2].y;
    p_startTime[19] = decalWorldAxis->mat[2].z;
    p_startTime[8] = decalWorldPosition->x;
    p_startTime[9] = decalWorldPosition->y;
    p_startTime[10] = decalWorldPosition->z;
    return (idRenderModelDecal::decalInfo_t *)1;
  }
  return result;
}


// ========================================================================
// ?SetDecalAttributes@idRenderModelDecal@@QAA_NV?$idHandle@HW4invalidDecalHandle_t@@$0?0@@ABVidVec3@@ABVidMat3@@M@Z
// EA  : 0x827FED10
// RVA : 0x007FED10
// PDB : w:\tech5\engine\models\rendermodeldecal.cpp
// ========================================================================

idRenderModelDecal::decalInfo_t *__fastcall idRenderModelDecal::SetDecalAttributes(
        idRenderModelDecal *this,
        const idHandle<int,enum invalidDecalHandle_t,-1> *decalHandle,
        const idVec3 *decalWorldPosition,
        const idMat3 *decalWorldAxis,
        double sizeScale)
{
  idRenderModelDecal::decalInfo_t *result; // r3
  double v8; // fp1

  result = idRenderModelDecal::GetDecalFromHandle(this, (int)decalHandle);
  if ( result != nullptr )
  {
    result->axis.mat[0].x = decalWorldAxis->mat[0].x;
    result->axis.mat[0].y = decalWorldAxis->mat[0].y;
    result->axis.mat[0].z = decalWorldAxis->mat[0].z;
    result->axis.mat[1].x = decalWorldAxis->mat[1].x;
    result->axis.mat[1].y = decalWorldAxis->mat[1].y;
    result->axis.mat[1].z = decalWorldAxis->mat[1].z;
    result->axis.mat[2].x = decalWorldAxis->mat[2].x;
    result->axis.mat[2].y = decalWorldAxis->mat[2].y;
    result->axis.mat[2].z = decalWorldAxis->mat[2].z;
    result->pos.x = decalWorldPosition->x;
    result->pos.y = decalWorldPosition->y;
    result->pos.z = decalWorldPosition->z;
    result->sizeScale = v8;
    return (idRenderModelDecal::decalInfo_t *)1;
  }
  return result;
}


// ========================================================================
// ?GetDecalAxis@idRenderModelDecal@@QAA_NV?$idHandle@HW4invalidDecalHandle_t@@$0?0@@AAVidMat3@@@Z
// EA  : 0x827FEDC0
// RVA : 0x007FEDC0
// PDB : w:\tech5\engine\models\rendermodeldecal.cpp
// ========================================================================

idRenderModelDecal::decalInfo_t *__fastcall idRenderModelDecal::GetDecalAxis(
        idRenderModelDecal *this,
        const idHandle<int,enum invalidDecalHandle_t,-1> *decalHandle,
        idMat3 *decalAxis)
{
  idRenderModelDecal::decalInfo_t *result; // r3

  result = idRenderModelDecal::GetDecalFromHandle(this, (int)decalHandle);
  if ( result != nullptr )
  {
    decalAxis->mat[0].x = result->axis.mat[0].x;
    decalAxis->mat[0].y = result->axis.mat[0].y;
    decalAxis->mat[0].z = result->axis.mat[0].z;
    decalAxis->mat[1].x = result->axis.mat[1].x;
    decalAxis->mat[1].y = result->axis.mat[1].y;
    decalAxis->mat[1].z = result->axis.mat[1].z;
    decalAxis->mat[2].x = result->axis.mat[2].x;
    decalAxis->mat[2].y = result->axis.mat[2].y;
    decalAxis->mat[2].z = result->axis.mat[2].z;
    return (idRenderModelDecal::decalInfo_t *)1;
  }
  else
  {
    decalAxis->mat[2].z = 1.0;
    decalAxis->mat[1].y = 1.0;
    decalAxis->mat[0].x = 1.0;
    decalAxis->mat[1].z = 0.0;
    decalAxis->mat[0].z = 0.0;
    decalAxis->mat[0].y = 0.0;
    decalAxis->mat[2].y = 0.0;
    decalAxis->mat[2].x = 0.0;
    decalAxis->mat[1].x = 0.0;
  }
  return result;
}


// ========================================================================
// ?RemoveDecal@idRenderModelDecal@@UAA_NV?$idHandle@HW4invalidDecalHandle_t@@$0?0@@@Z
// EA  : 0x827FEE90
// RVA : 0x007FEE90
// PDB : w:\tech5\engine\models\rendermodeldecal.cpp
// ========================================================================

idRenderModelDecal::decalInfo_t *__fastcall idRenderModelDecal::RemoveDecal(
        idRenderModelDecal *this,
        const idHandle<int,enum invalidDecalHandle_t,-1> *decalHandle)
{
  idRenderModelDecal::decalInfo_t *result; // r3
  idRenderModelDecal::decalInfo_t *v3; // r11

  result = idRenderModelDecal::GetDecalFromHandle(this, (int)decalHandle);
  v3 = result;
  if ( result != nullptr )
  {
    v3->lifeTime = 0;
    return (idRenderModelDecal::decalInfo_t *)1;
  }
  return result;
}


// ========================================================================
// ?UpdateInView@idRenderModelDecal@@EAA_NPBVidRenderView@@0PAVidRenderModelUpdateTools@@@Z
// EA  : 0x827FEEE0
// RVA : 0x007FEEE0
// PDB : w:\tech5\engine\models\rendermodeldecal.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __fastcall idRenderModelDecal::UpdateInView(
        idRenderModelDecal *this,
        const idRenderView *currentView,
        const idRenderView *nextView,
        idRenderModelUpdateTools *updateTools,
        const char *a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        idRenderModelDecal *a12)
{
  idRenderModelDecal *v13; // r21
  unsigned __int64 v15; // r6
  idRenderModelSurface *list; // r11
  idTriangles *geometry; // r10
  long double v18; // fp2
  const idDeclRenderParm **p_triangles; // r28
  idColor *v20; // r30
  int i; // r29
  double a; // fp30
  double b; // fp29
  const idDeclRenderParm *v24; // r27
  double g; // fp28
  double r; // fp31
  idStaticParmBlock<32> *RenderParmBlock; // r3
  int v28; // r6
  idTriangles *triangles; // r11
  unsigned __int64 v30; // r30
  unsigned int vertexMask; // r7
  int size; // r11
  int v33; // r5
  _BYTE *v34; // r3
  int v36; // r15
  int v37; // r5
  idRenderModelDecal::decalInfo_t **p_decals; // r14
  int v39; // r7
  int v40; // r11
  int v41; // r24
  int v42; // r8
  int v43; // r10
  const idMaterial *material; // r9
  idTriangles *v45; // r10
  int v46; // r8
  int v47; // r25
  int v48; // r23
  int v49; // r20
  idTriangles *v50; // r26
  __int64 v51; // r6
  bool v52; // r19
  const idIndexBuffer *p_indexBufferQuads; // r16
  int v54; // r22
  int v55; // r21
  int v56; // r9
  int v59; // r11
  int v60; // r11
  int j; // ctr
  int k; // ctr
  idRenderModelDecal *v73; // r14
  __int64 v74; // r6
  int v75; // r21
  idRenderModelDecal::decalInfo_t **v76; // r19
  int v77; // r18
  int v78; // r20
  idRenderModelDecal::decalInfo_t *v80; // r11
  int lifeTime; // r10
  const idMaterial *decalMtr; // r23
  int v83; // r8
  int v84; // r10
  const idMaterial *v85; // r9
  decalProjType_t materialDecalProjType; // r10
  idTriangles *v87; // r9
  int v88; // r24
  idTriangles *v89; // r26
  int v90; // r25
  bool v91; // r22
  int v92; // r28
  int v93; // r27
  char *v95; // r29
  int v96; // r11
  int v97; // r11
  const idRenderModelDecal::decalInfo_t *v98; // r4
  int m; // ctr
  int v105; // r6
  int v106; // r30
  int v110; // r9
  const idMaterial *v111; // r20
  int v112; // r10
  idTriangles *v113; // r10
  int v114; // r19
  idTriangles *v115; // r21
  int v116; // r22
  char *v117; // r24
  int v119; // r28
  int *v120; // r10
  float *p_y; // r11
  int n; // ctr
  idRenderWorldLocal *World; // r3
  float v124; // r11
  float v125; // r9
  double v126; // fp11
  int v127; // r29
  double v128; // fp26
  double v129; // fp28
  double v131; // fp27
  float v132; // r9
  float v133; // r8
  double v134; // fp12
  double v135; // fp0
  int valueInteger; // r10
  double v137; // fp5
  double v138; // fp3
  double v139; // fp0
  idRenderWorldLocal *v140; // r14
  idColor *v141; // r3
  double v146; // fp13
  __int64 v153; // r9 OVERLAPPED
  __int64 v154; // r11
  double v155; // fp4
  double v156; // fp0
  double v157; // fp13
  double v160; // fp6
  char v161; // r11
  double v162; // fp9
  double v163; // fp3
  double v164; // fp5
  double v165; // fp6
  double v168; // fp5
  double v169; // fp2
  double v170; // fp10
  double v171; // fp8
  double v172; // fp13
  double v173; // fp2
  double v174; // fp4
  double v175; // fp3
  double v176; // fp2
  double v177; // fp6
  double v178; // fp5
  double v179; // fp4
  double v180; // fp0
  double v181; // fp0
  double v182; // fp12
  double v183; // fp13
  char v184; // r11
  char v185; // r11
  char v186; // r11
  int ii; // ctr
  idPLog *pLog; // r29
  idPLog::logEntry_t *v193; // r30
  int v194; // r3
  __int64 totalTicks; // r11
  __int64 v196; // r9
  int num; // [sp+50h] [-590h]
  int v200; // [sp+50h] [-590h]
  int v201; // [sp+50h] [-590h]
  int v202; // [sp+50h] [-590h]
  int v203; // [sp+54h] [-58Ch]
  int v204; // [sp+54h] [-58Ch]
  int v205; // [sp+58h] [-588h]
  unsigned int v206; // [sp+5Ch] [-584h]
  idVertexBuffer *v207; // [sp+60h] [-580h]
  _BYTE *v208; // [sp+64h] [-57Ch]
  int v209; // [sp+6Ch] [-574h]
  float v210; // [sp+78h] [-568h] BYREF
  float v211; // [sp+7Ch] [-564h]
  float v212; // [sp+80h] [-560h]
  idRenderModelSurface v213; // [sp+90h] [-550h] BYREF
  int v215; // [sp+CCh] [-514h] BYREF
  float v216; // [sp+D0h] [-510h] BYREF
  float v217; // [sp+D4h] [-50Ch] BYREF
  float v218[4]; // [sp+D8h] [-508h] BYREF
  float v219; // [sp+E8h] [-4F8h] BYREF
  float v220; // [sp+ECh] [-4F4h] BYREF
  float v221; // [sp+F0h] [-4F0h] BYREF
  int v222; // [sp+F4h] [-4ECh]
  idPLogScope v223; // [sp+F8h] [-4E8h] BYREF
  float v224; // [sp+100h] [-4E0h]
  float v225; // [sp+104h] [-4DCh]
  float v226; // [sp+108h] [-4D8h]
  parmValue_t v227; // [sp+110h] [-4D0h] BYREF
  __int64 v228; // [sp+120h] [-4C0h]
  __int64 v229; // [sp+128h] [-4B8h]
  __int64 v230; // [sp+130h] [-4B0h]
  __int64 v231; // [sp+138h] [-4A8h]
  __int64 v232; // [sp+140h] [-4A0h]
  __int64 v233; // [sp+148h] [-498h]
  idColor v234; // [sp+150h] [-490h] BYREF
  idRenderMatrix v235; // [sp+160h] [-480h] BYREF
  int v236; // [sp+1A0h] [-440h] BYREF
  _BYTE v237[6]; // [sp+1B0h] [-430h] BYREF
  __int16 v238; // [sp+1B6h] [-42Ah] BYREF
  idDrawVert v239[8]; // [sp+2A0h] [-340h] BYREF
  idRenderMatrix v240; // [sp+3A0h] [-240h] BYREF
  idDrawVert v241[11]; // [sp+3E0h] [-200h] BYREF

  _R12 = -256;
  __asm { stvx128   v127, r1, r12 }
  a12 = this;
  v13 = this;
  LODWORD(v15) = "idRenderModelDecal::UpdateInView";
  HIDWORD(v15) = 1;
  idPLogScope::idPLogScope(this: &v223, pl: &::pLog, gMask: v15, label: a5);
  if ( r_skipDecals.valueInteger != 0 )
  {
    list = v13->surfaces.list;
    if ( list != nullptr )
    {
      geometry = list->geometry;
      if ( geometry != nullptr )
      {
        geometry->numVerts = 0;
        list->geometry->numIndexes = 0;
        list->material = nullptr;
      }
    }
    idPLogScope::~idPLogScope(this: &v223);
  }
  else
  {
    *((double *)&v18 + 1) = r_zfar.valueFloat;
    *(double *)&v18 = r_znear.valueFloat;
    idRenderModelDecal::SetupInverseVPMatrix(a1: (int)v13, a2: &v240, a3: (int)currentView, zFar: v18);
    idRenderMatrix::Multiply(
      a: &currentView->worldSpaceInverseMVPMatrix,
      b: &renderMatrix_windowSpaceToClipSpace,
      out: &v235);
    p_triangles = (const idDeclRenderParm **)&v13->triangles;
    v20 = &v234;
    for ( i = 4; i != 0; --i )
    {
      a = v20[1].a;
      b = v20[1].b;
      v24 = *++p_triangles;
      g = v20[1].g;
      ++v20;
      r = v20->r;
      RenderParmBlock = idRenderModel::GetRenderParmBlock(this: v13);
      v227.value[0] = r;
      v227.value[1] = g;
      v227.value[2] = b;
      v227.value[3] = a;
      idParmBlock::SetParm(this: RenderParmBlock, parm: v24, parmValue: &v227);
    }
    triangles = v13->triangles;
    LODWORD(v30) = 0;
    v206 = 0;
    if ( triangles != nullptr )
    {
      vertexMask = triangles->vertexMask;
      v28 = ((vertexMask & 1) == 0) - 1;
      v206 = ((vertexMask & 0x1000) == 0 ? 0 : 0xC)
           + ((vertexMask >> 9) & 4)
           + ((vertexMask & 0x40) == 0 ? 0 : 0xFFFFFFFC)
           + ((vertexMask & 0x20) == 0 ? 0 : 0xFFFFFFFC)
           + ((vertexMask >> 2) & 4)
           + ((vertexMask >> 1) & 4)
           + (vertexMask & 4)
           + ((4 * vertexMask) & 8)
           + (v28 & 0xC);
    }
    HIDWORD(v30) = &v13->surfaces;
    if ( v13->surfaces.size < 0 )
      idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v13->surfaces);
    size = v13->surfaces.size;
    v33 = __CFADD__(-size, size ^ 0x80000000) - 1;
    v13->surfaces.num = v33 & size;
    v207 = (idVertexBuffer *)((char *)v13->vertexBuffer
                            + ((16
                              * ((int (__fastcall *)(idRenderSystem *, int, int, int, unsigned int))renderSystem->FrameNumber)(
                                  a1: renderSystem,
                                  a2: v33 & size,
                                  a3: v33,
                                  a4: v28,
                                  a5: (size ^ 0x80000000) - size))
                             & 0x10));
    v34 = idVertexBuffer::MapBuffer(this: v207, mapType: BM_WRITE_NOSYNC);
    v36 = v13->latchedDecalRange[0];
    v37 = v13->latchedDecalRange[1];
    v208 = v34;
    v203 = 0;
    v205 = 0;
    if ( v36 < v37 )
    {
      p_decals = &v13->decals;
      do
      {
        v39 = (int)&(*p_decals)[v36 & 0x7FF];
        v40 = *(_DWORD *)(v39 + 4);
        if ( v40 < 0 || v13->latchedTime - *(_DWORD *)v39 <= v40 )
        {
          v41 = *(_DWORD *)(v39 + 8);
          if ( v41 != 0 )
          {
            v42 = 0;
            num = v13->surfaces.num;
            if ( num > 0 )
            {
              v43 = 0;
              do
              {
                material = v13->surfaces.list[v43].material;
                if ( material != nullptr && material->progs[6] == *(const idDeclRenderProg **)(v41 + 200) )
                  break;
                ++v42;
                ++v43;
              }
              while ( v42 < num );
            }
            if ( v42 == num )
            {
              if ( num >= 32 )
                break;
              v45 = v13->triangles;
              v46 = *(_DWORD *)(v41 + 80);
              v213.skinOffsets.x = 0.0;
              v47 = *(unsigned __int8 *)(v39 + 92);
              v213.skinOffsets.y = 0.0;
              v48 = v203;
              v213.skinOffsets.z = 0.0;
              v49 = v205;
              v213.skinOffsets.w = 0.0;
              v213.material = (const idMaterial *)v41;
              v213.materialNum = 0;
              v213.extraGLState = v30;
              v50 = &v45[num];
              v213.referenceMask = 0;
              memset(&v213.binaryModelId, 0, 16);
              v213.geometry = v50;
              v213.geometryIsReference = true;
              LODWORD(v51) = v50->vertexMask;
              v52 = (_cntlzw(v46 - 1) & 0x20) != 0;
              p_indexBufferQuads = &v13->indexBufferQuads;
              v54 = ((v51 & 0x1000) == 0 ? 0 : 0xC)
                  + (((unsigned int)v51 >> 9) & 4)
                  + ((v51 & 0x40) == 0 ? 0 : 0xFFFFFFFC)
                  + ((v51 & 0x20) == 0 ? 0 : 0xFFFFFFFC)
                  + (((unsigned int)v51 >> 2) & 4)
                  + (((unsigned int)v51 >> 1) & 4)
                  + (v51 & 4)
                  + ((4 * v51) & 8)
                  + ((v51 & 1) == 0 ? 0 : 0xC);
              if ( v47 == 0 )
                p_indexBufferQuads = &v13->indexBufferBoxes;
              v55 = v36;
              if ( v36 < v37 )
              {
                HIDWORD(v30) = &v208[32 * v203];
                v56 = -32 * v203 - (_DWORD)v208;
                _R27 = (char *)&v239[0].st.y + v56;
                _R28 = &v237[v56];
                do
                {
                  LODWORD(v30) = &(*p_decals)[v55 & 0x7FF];
                  v59 = *(_DWORD *)(v30 + 8);
                  if ( v59 != 0 && *(_DWORD *)(v59 + 200) == *(_DWORD *)(v41 + 200) )
                  {
                    v60 = *(_DWORD *)(v30 + 4);
                    if ( (v60 < 0 || a12->latchedTime - *(_DWORD *)v30 <= v60) && *(unsigned __int8 *)(v30 + 92) == v47 )
                    {
                      if ( v47 != 0 )
                      {
                        HIDWORD(v51) = &v236;
                        idRenderModelDecal::GenDecalVerts(
                          this: a12,
                          decal: (const idRenderModelDecal::decalInfo_t *)v30,
                          verts: v51);
                        _R11 = HIDWORD(v30);
                        _R9 = -16;
                        _R8 = 16;
                        for ( j = 4; j != 0; --j )
                        {
                          _R10 = &_R28[_R11];
                          __asm
                          {
                            lvx128    v63, r28, r11
                            lvx128    v62, r10, r9
                            stvx128   v62, r0, r11
                            stvx128   v63, r11, r8
                          }
                          _R11 += 32;
                        }
                        _R28 -= 128;
                        _R27 -= 128;
                        v203 += 4;
                        HIDWORD(v30) += 128;
                        v205 += 6;
                        if ( v203 > 21500 )
                          break;
                      }
                      else
                      {
                        HIDWORD(v51) = v239;
                        if ( v52 )
                          idRenderModelDecal::GenSphericalDecalVerts(
                            this: a12,
                            decal: (const idRenderModelDecal::decalInfo_t *)v30,
                            verts: v239);
                        else
                          idRenderModelDecal::GenDecalVerts(
                            this: a12,
                            decal: (const idRenderModelDecal::decalInfo_t *)v30,
                            verts: v51);
                        _R11 = HIDWORD(v30);
                        _R9 = -16;
                        _R8 = 16;
                        for ( k = 8; k != 0; --k )
                        {
                          _R10 = &_R27[_R11];
                          __asm
                          {
                            lvx128    v61, r27, r11
                            lvx128    v60, r10, r9
                            stvx128   v60, r0, r11
                            stvx128   v61, r11, r8
                          }
                          _R11 += 32;
                        }
                        _R28 -= 256;
                        _R27 -= 256;
                        v203 += 8;
                        HIDWORD(v30) += 256;
                        v205 += 36;
                        if ( v203 > 21496 )
                          break;
                        if ( r_debugDecals.valueInteger > 0 )
                          idRenderModelDecal::DebugDrawDecals(
                            this: a12,
                            pos: (const idVec3 *)(v30 + 32),
                            axis: (const idMat3 *)(v30 + 44),
                            verts: v239,
                            numVerts: 8);
                      }
                    }
                  }
                  ++v55;
                }
                while ( v55 < a12->latchedDecalRange[1] );
              }
              v50->numVerts = v203 - v48;
              v50->numIndexes = v205 - v49;
              idVertexBuffer::Reference(
                this: &v50->vertexBuffer,
                other: v207,
                refOffset: v48 * v54,
                refSize: (v203 - v48) * v54);
              idIndexBuffer::Reference(
                this: &v50->indexBuffer,
                other: p_indexBufferQuads,
                refOffset: 0,
                refSize: 2 * (v205 - v49));
              idList<idRenderModelSurface,62>::Append(this: &a12->surfaces, obj: &v213);
              v13 = a12;
              LODWORD(v30) = 0;
            }
          }
        }
        v37 = v13->latchedDecalRange[1];
        ++v36;
      }
      while ( v36 < v37 );
    }
    v73 = a12;
    LODWORD(v74) = v208;
    v75 = 2048;
    HIDWORD(_R16) = v203;
    v76 = &a12->decals;
    v77 = a12->surfaces.num;
    v78 = 2048;
    LODWORD(_R16) = 0;
    do
    {
      v80 = &(*v76)[v78];
      lifeTime = v80->lifeTime;
      if ( lifeTime < 0 || v73->latchedTime - v80->startTime <= lifeTime )
      {
        decalMtr = v80->decalMtr;
        if ( decalMtr != nullptr )
        {
          v83 = v77;
          v200 = v73->surfaces.num;
          if ( v77 < v200 )
          {
            v84 = v77;
            do
            {
              v85 = v73->surfaces.list[v84].material;
              if ( v85 != nullptr && v85->progs[6] == decalMtr->progs[6] )
                break;
              ++v83;
              ++v84;
            }
            while ( v83 < v200 );
          }
          if ( v83 == v200 )
          {
            if ( v200 >= 32 )
              break;
            materialDecalProjType = decalMtr->materialDecalProjType;
            v87 = v73->triangles;
            v213.skinOffsets.x = 0.0;
            v88 = v205;
            v213.skinOffsets.y = 0.0;
            v213.skinOffsets.z = 0.0;
            v213.material = decalMtr;
            v213.skinOffsets.w = 0.0;
            v213.materialNum = 0;
            v213.extraGLState = _R16;
            v213.referenceMask = 0;
            memset(&v213.binaryModelId, 0, 16);
            v89 = &v87[v200];
            v213.geometry = v89;
            v90 = HIDWORD(_R16);
            v213.geometryIsReference = true;
            v91 = (_cntlzw(materialDecalProjType - 1) & 0x20) != 0;
            if ( v75 < 2176 )
            {
              v92 = 32 * HIDWORD(_R16) + v74;
              v93 = v78 * 100;
              _R30 = (char *)&v241[0].st.y - v74 + -32 * HIDWORD(_R16);
              do
              {
                v95 = (char *)*v76 + v93;
                v96 = *((_DWORD *)v95 + 2);
                if ( v96 != 0 && *(const idDeclRenderProg **)(v96 + 200) == decalMtr->progs[6] )
                {
                  v97 = *((_DWORD *)v95 + 1);
                  if ( v97 < 0 || v73->latchedTime - *(_DWORD *)v95 <= v97 )
                  {
                    HIDWORD(v74) = v241;
                    v98 = (idRenderModelDecal::decalInfo_t *)((char *)*v76 + v93);
                    if ( v91 )
                      idRenderModelDecal::GenSphericalDecalVerts(this: v73, decal: v98, verts: v241);
                    else
                      idRenderModelDecal::GenDecalVerts(this: v73, decal: v98, verts: v74);
                    _R11 = v92;
                    _R9 = -16;
                    _R8 = 16;
                    for ( m = 8; m != 0; --m )
                    {
                      _R10 = &_R30[_R11];
                      __asm
                      {
                        lvx128    v59, r30, r11
                        lvx128    v58, r10, r9
                        stvx128   v58, r0, r11
                        stvx128   v59, r11, r8
                      }
                      _R11 += 32;
                    }
                    HIDWORD(_R16) += 8;
                    _R30 -= 256;
                    v92 = _R11;
                    v205 += 36;
                    if ( SHIDWORD(_R16) > 21496 )
                      break;
                    if ( r_debugDecals.valueInteger > 0 )
                      idRenderModelDecal::DebugDrawDecals(
                        this: v73,
                        pos: (const idVec3 *)(v95 + 32),
                        axis: (const idMat3 *)(v95 + 44),
                        verts: v241,
                        numVerts: 8);
                  }
                }
                v93 += 100;
              }
              while ( v93 < 217600 );
            }
            v89->numVerts = HIDWORD(_R16) - v90;
            v89->numIndexes = v205 - v88;
            idVertexBuffer::Reference(
              this: &v89->vertexBuffer,
              other: v207,
              refOffset: v90 * v206,
              refSize: (HIDWORD(_R16) - v90) * v206);
            idIndexBuffer::Reference(
              this: &v89->indexBuffer,
              other: &v73->indexBufferBoxes,
              refOffset: 0,
              refSize: 2 * (v205 - v88));
            idList<idRenderModelSurface,62>::Append(this: &v73->surfaces, obj: &v213);
            LODWORD(v74) = v208;
          }
        }
      }
      ++v78;
      ++v75;
    }
    while ( v78 < 2176 );
    v105 = v73->latchedTireDecalRange[1];
    v209 = v73->latchedTireDecalRange[0];
    v204 = HIDWORD(_R16);
    v222 = v73->surfaces.num;
    if ( v209 < v105 )
    {
      v106 = v209;
      HIDWORD(_R4) = &mat3_identity;
      _R17 = &`VertexFloatToByte'::`2'::SIMD_SP_255_over_2;
      HIDWORD(_R16) = &`VertexFloatToByte'::`2'::SIMD_SP_half;
      _R23 = &_vmx_3f8000003f8000003f8000003f800000;
      do
      {
        v110 = v222;
        v201 = v73->surfaces.num;
        v111 = v73->tireDecals[v106 & 0x1FF].decalMtr;
        if ( v222 < v201 )
        {
          v112 = v222;
          do
          {
            if ( v73->surfaces.list[v112].material == v111 )
              break;
            ++v110;
            ++v112;
          }
          while ( v110 < v201 );
        }
        if ( v110 == v201 )
        {
          v113 = v73->triangles;
          v213.skinOffsets.x = 0.0;
          v114 = v204;
          v213.skinOffsets.y = 0.0;
          v213.skinOffsets.z = 0.0;
          v213.material = v111;
          v213.skinOffsets.w = 0.0;
          v213.materialNum = 0;
          v213.extraGLState = _R16;
          v213.referenceMask = 0;
          memset(&v213.binaryModelId, 0, 16);
          v115 = &v113[v201];
          v213.geometry = v115;
          v116 = v106;
          v213.geometryIsReference = true;
          v202 = v205;
          if ( v106 < v105 )
          {
            v117 = &v208[32 * v204];
            _R25 = (_BYTE *)(&v237[-32 * v204] - v208);
            do
            {
              v119 = (int)&v73->tireDecals[v116 & 0x1FF];
              if ( *(const idMaterial **)(v119 + 8) == v111 )
              {
                v120 = &v215;
                p_y = &mat2_identity.mat[1].y;
                for ( n = 9; n != 0; --n )
                  *++v120 = *(_DWORD *)++p_y;
                if ( r_debugDecals.valueInteger > 0 )
                {
                  HIDWORD(_R4) = idRenderModel::GetWorld(this: v73);
                  if ( HIDWORD(_R4) != 0 )
                  {
                    World = idRenderModel::GetWorld(this: v73);
                    HIDWORD(_R4) = ((int (__fastcall *)(idRenderWorldLocal *, int, float *, _DWORD, _DWORD))World->DebugAxis_2)(
                                     a1: World,
                                     a2: v119 + 24,
                                     a3: &v216,
                                     a4: 0,
                                     a5: 0);
                  }
                }
                __asm { lvx128    v13, r0, r15 }
                v124 = *(float *)(v119 + 24);
                __asm { lvx128    v12, r0, r17 }
                v125 = *(float *)(v119 + 32);
                v126 = idMath::FLT_SMALLEST_NON_DENORMAL;
                __asm { vspltisw128 v127, 0 }
                v127 = 0;
                v225 = *(float *)(v119 + 28);
                v224 = v124;
                v128 = v124;
                v226 = v125;
                v129 = v125;
                _R30 = (unsigned __int8 *)&v238;
                v131 = v225;
                do
                {
                  v132 = *(float *)(4 * ((v127 & 3) + ((2 * v127) & 6)) + v119 + 56);
                  v133 = *(float *)(4 * ((v127 & 3) + ((2 * v127) & 6)) + v119 + 60);
                  v227.swizzle[0] = *(_DWORD *)(4 * ((v127 & 3) + ((2 * v127) & 6)) + v119 + 52);
                  v210 = v227.value[0];
                  v211 = v132;
                  v212 = v133;
                  if ( v127 >= 4 )
                  {
                    v135 = v212;
                    v134 = v210;
                  }
                  else
                  {
                    v134 = v227.value[0];
                    v135 = (float)(v212 - (float)(*(float *)(v119 + 48) * (float)2.0));
                  }
                  valueInteger = r_debugDecals.valueInteger;
                  v137 = (float)((float)(v218[0] * (float)v134)
                               + (float)((float)(v221 * (float)v135) + (float)(v218[3] * v132)));
                  v138 = (float)((float)(v217 * (float)v134)
                               + (float)((float)(v220 * (float)v135) + (float)(v218[2] * v132)));
                  v139 = (float)((float)v128
                               + (float)((float)(v218[1] * v132)
                                       + (float)((float)(v216 * (float)v134) + (float)(v219 * (float)v135))));
                  v210 = v139;
                  v212 = (float)v129 + (float)v137;
                  v211 = (float)v131 + (float)v138;
                  *(float *)(_R30 - 14) = v212;
                  *(float *)(_R30 - 22) = v139;
                  *(float *)(_R30 - 18) = (float)v131 + (float)v138;
                  if ( valueInteger > 0 )
                  {
                    HIDWORD(_R4) = idRenderModel::GetWorld(this: v73);
                    if ( HIDWORD(_R4) != 0 )
                    {
                      v140 = idRenderModel::GetWorld(this: v73);
                      v141 = BrightColorForNumber(result: &v234, number: v127);
                      HIDWORD(_R4) = ((int (__fastcall *)(idRenderWorldLocal *, idColor *, float *, _DWORD, _DWORD))v140->DebugPoint)(
                                       a1: v140,
                                       a2: v141,
                                       a3: &v210,
                                       a4: 0,
                                       a5: 0);
                      v73 = a12;
                    }
                    v126 = idMath::FLT_SMALLEST_NON_DENORMAL;
                    __asm
                    {
                      lvx128    v12, r0, r17
                      lvx128    v13, r0, r15
                    }
                  }
                  _R9 = &v219;
                  __asm { vmr128    v57, v127 }
                  _R8 = &v220;
                  __asm { lvx128    v56, r0, r23 }
                  _R7 = &v221;
                  _R11 = _R30 - 2;
                  v146 = *(float *)(v119 + 20);
                  _R10 = _R30 - 1;
                  *(float *)(_R30 - 10) = *(float *)(v119 + 16);
                  __asm { lvlx128   v55, r0, r9 }
                  HIDWORD(_R7) = &v217;
                  __asm
                  {
                    vrlimi128 v57, v55, 8, 0
                    lvlx128   v54, r0, r8
                    lvlx128   v53, r0, r7
                  }
                  _R5 = v218;
                  *(float *)(_R30 - 6) = v146;
                  LODWORD(_R4) = &v216;
                  __asm { vmr128    v52, v127 }
                  _R9 = _R30 + 2;
                  __asm { vrlimi128 v57, v54, 4, 3 }
                  _R8 = _R30 + 3;
                  _R7 = _R30 + 4;
                  __asm
                  {
                    vrlimi128 v57, v53, 2, 2
                    vaddfp128 v0, v89, v56
                    vmaddfp   v0, v0, v13, v12
                    vcfpsxws128 v51, v0, 0
                    vpkswss128 v50, v83, v51
                    vpkshus128 v0, v82, v50
                    stvebx    v0, 0, r11
                    stvebx    v0, 0, r10
                    stvebx    v0, 0, r30
                    lvlx128   v49, r0, r6
                    lvlx128   v48, r0, r5
                    lvx128    v47, r0, r23
                    lvlx128   v46, r0, r4
                    vrlimi128 v52, v46, 8, 0
                    vrlimi128 v52, v49, 4, 3
                    vrlimi128 v52, v48, 2, 2
                    vaddfp128 v0, v84, v47
                    vmaddfp   v0, v0, v13, v12
                    vcfpsxws128 v45, v0, 0
                    vpkswss128 v44, v77, v45
                    vpkshus128 v0, v76, v44
                    stvebx    v0, 0, r9
                    stvebx    v0, 0, r8
                    stvebx    v0, 0, r7
                  }
                  LODWORD(_R7) = _R30[4];
                  HIDWORD(v153) = _R30[2];
                  LODWORD(v153) = _R30[3];
                  v230 = v153;
                  v228 = _R7;
                  v229 = *(__int64 *)((char *)&_R7 - 4);
                  LODWORD(_R4) = *(_R30 - 2);
                  LODWORD(v154) = *_R30;
                  HIDWORD(v154) = *(_R30 - 1);
                  v232 = _R4;
                  v155 = (float)((float)((float)v153 * (float)0.0078431377) - (float)1.0);
                  v156 = (float)((float)((float)*(__int64 *)((char *)&_R7 - 4) * (float)0.0078431377) - (float)1.0);
                  v157 = (float)((float)((float)_R7 * (float)0.0078431377) - (float)1.0);
                  _FP9 = (float)((float)((float)((float)v157 * (float)v157)
                                       + (float)((float)((float)v156 * (float)v156) + (float)((float)v155 * (float)v155)))
                               - (float)v126);
                  __asm { fsel      f7, f9, f10, f11 }
                  v160 = __frsqrte(_FP7);
                  v233 = *(__int64 *)((char *)&v153 - 4);
                  v231 = v154;
                  v162 = (float)((float)((float)*(__int64 *)((char *)&v153 - 4) * (float)0.0078431377) - (float)1.0);
                  v163 = (float)((float)((float)_R4 * (float)0.0078431377) - (float)1.0);
                  v164 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v160 * (float)((float)((float)((float)v157 * (float)v157) + (float)((float)((float)v156 * (float)v156) + (float)((float)v155 * (float)v155))) * (float)0.5))
                                                                                               * (float)v160)
                                                                                       - (float)1.5)
                                                                       * (float)v160)
                                                               * (float)((float)((float)((float)v157 * (float)v157)
                                                                               + (float)((float)((float)v156
                                                                                               * (float)v156)
                                                                                       + (float)((float)v155
                                                                                               * (float)v155)))
                                                                       * (float)0.5))
                                                       * (float)((float)-(float)((float)((float)((float)v160
                                                                                               * (float)((float)((float)((float)v157 * (float)v157) + (float)((float)((float)v156 * (float)v156) + (float)((float)v155 * (float)v155))) * (float)0.5))
                                                                                       * (float)v160)
                                                                               - (float)1.5)
                                                               * (float)v160))
                                               - (float)1.5)
                               * (float)((float)-(float)((float)((float)((float)v160
                                                                       * (float)((float)((float)((float)v157
                                                                                               * (float)v157)
                                                                                       + (float)((float)((float)v156 * (float)v156)
                                                                                               + (float)((float)v155 * (float)v155)))
                                                                               * (float)0.5))
                                                               * (float)v160)
                                                       - (float)1.5)
                                       * (float)v160));
                  v165 = (float)((float)((float)v154 * (float)0.0078431377) - (float)1.0);
                  _FP8 = (float)((float)((float)((float)v165 * (float)v165)
                                       + (float)((float)((float)v163 * (float)v163) + (float)((float)v162 * (float)v162)))
                               - (float)v126);
                  __asm { fsel      f8, f8, f2, f11 }
                  v168 = (float)((float)-(float)((float)((float)((float)v164
                                                               * (float)((float)((float)((float)v157 * (float)v157)
                                                                               + (float)((float)((float)v156
                                                                                               * (float)v156)
                                                                                       + (float)((float)v155
                                                                                               * (float)v155)))
                                                                       * (float)0.5))
                                                       * (float)v164)
                                               - (float)1.5)
                               * (float)v164);
                  v169 = __frsqrte(_FP8);
                  v170 = (float)((float)v168
                               * (float)((float)((float)*(__int64 *)((char *)&_R7 - 4) * (float)0.0078431377)
                                       - (float)1.0));
                  v171 = (float)((float)v168 * (float)((float)((float)v153 * (float)0.0078431377) - (float)1.0));
                  v172 = (float)((float)v168 * (float)((float)((float)_R7 * (float)0.0078431377) - (float)1.0));
                  v173 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v169 * (float)((float)((float)((float)v165 * (float)v165) + (float)((float)((float)v163 * (float)v163) + (float)((float)v162 * (float)v162))) * (float)0.5))
                                                                                               * (float)v169)
                                                                                       - (float)1.5)
                                                                       * (float)v169)
                                                               * (float)((float)((float)((float)v165 * (float)v165)
                                                                               + (float)((float)((float)v163
                                                                                               * (float)v163)
                                                                                       + (float)((float)v162
                                                                                               * (float)v162)))
                                                                       * (float)0.5))
                                                       * (float)((float)-(float)((float)((float)((float)v169
                                                                                               * (float)((float)((float)((float)v165 * (float)v165) + (float)((float)((float)v163 * (float)v163) + (float)((float)v162 * (float)v162))) * (float)0.5))
                                                                                       * (float)v169)
                                                                               - (float)1.5)
                                                               * (float)v169))
                                               - (float)1.5)
                               * (float)((float)-(float)((float)((float)((float)v169
                                                                       * (float)((float)((float)((float)v165
                                                                                               * (float)v165)
                                                                                       + (float)((float)((float)v163 * (float)v163)
                                                                                               + (float)((float)v162 * (float)v162)))
                                                                               * (float)0.5))
                                                               * (float)v169)
                                                       - (float)1.5)
                                       * (float)v169));
                  v174 = (float)((float)-(float)((float)((float)((float)v173
                                                               * (float)((float)((float)((float)v165 * (float)v165)
                                                                               + (float)((float)((float)v163
                                                                                               * (float)v163)
                                                                                       + (float)((float)v162
                                                                                               * (float)v162)))
                                                                       * (float)0.5))
                                                       * (float)v173)
                                               - (float)1.5)
                               * (float)v173);
                  v175 = (float)((float)((float)-(float)((float)((float)((float)v173
                                                                       * (float)((float)((float)((float)v165
                                                                                               * (float)v165)
                                                                                       + (float)((float)((float)v163 * (float)v163)
                                                                                               + (float)((float)v162 * (float)v162)))
                                                                               * (float)0.5))
                                                               * (float)v173)
                                                       - (float)1.5)
                                       * (float)v173)
                               * (float)v163);
                  v176 = (float)((float)v174
                               * (float)((float)((float)*(__int64 *)((char *)&v153 - 4) * (float)0.0078431377)
                                       - (float)1.0));
                  v177 = (float)((float)((float)v174
                                       * (float)((float)((float)*(__int64 *)((char *)&v153 - 4) * (float)0.0078431377)
                                               - (float)1.0))
                               * (float)((float)v168
                                       * (float)((float)((float)*(__int64 *)((char *)&_R7 - 4) * (float)0.0078431377)
                                               - (float)1.0)));
                  v178 = (float)((float)((float)v174 * (float)((float)((float)v154 * (float)0.0078431377) - (float)1.0))
                               * (float)((float)v168 * (float)((float)((float)v153 * (float)0.0078431377) - (float)1.0)));
                  v179 = (float)((float)((float)((float)v174
                                               * (float)((float)((float)v154 * (float)0.0078431377) - (float)1.0))
                                       * (float)v170)
                               - (float)((float)v172 * (float)v175));
                  v161 = 0;
                  if ( (float)((float)(v218[1] * (float)((float)((float)v176 * (float)v172) - (float)v178))
                             + (float)((float)((float)((float)((float)v171 * (float)v175) - (float)v177) * v218[3])
                                     + (float)((float)v179 * v218[2]))) >= 0.0 )
                    v161 = -1;
                  v180 = *(float *)(_R30 - 22);
                  _R30[5] = v161;
                  v181 = (float)((float)v180 - (float)v128);
                  v182 = (float)(*(float *)(_R30 - 14) - (float)v129);
                  v183 = (float)(*(float *)(_R30 - 18) - (float)v131);
                  v215 = (int)(float)((float)((float)1.0 / (float)__fabs(v181)) * (float)255.0);
                  v184 = v215;
                  if ( v215 >= 0 )
                  {
                    if ( v215 > 255 )
                      v184 = -1;
                  }
                  else
                  {
                    v184 = 0;
                  }
                  _R30[6] = v184;
                  v215 = (int)(float)((float)((float)1.0 / (float)__fabs(v183)) * (float)255.0);
                  v185 = v215;
                  if ( v215 >= 0 )
                  {
                    if ( v215 > 255 )
                      v185 = -1;
                  }
                  else
                  {
                    v185 = 0;
                  }
                  _R30[7] = v185;
                  v215 = (int)(float)((float)((float)1.0 / (float)__fabs(v182)) * (float)255.0);
                  v186 = v215;
                  if ( v215 >= 0 )
                  {
                    if ( v215 > 255 )
                      v186 = -1;
                  }
                  else
                  {
                    v186 = 0;
                  }
                  _R30[8] = v186;
                  _R30[9] = -1;
                  HIDWORD(_R4) = v182 > 0.0;
                  ++v127;
                  _R30[1] = (2 * ((2 * (v182 > 0.0)) | (v183 > 0.0))) | (v181 > 0.0);
                  _R30 += 32;
                }
                while ( v127 < 8 );
                _R11 = v117;
                _R9 = -16;
                _R8 = 16;
                for ( ii = 8; ii != 0; --ii )
                {
                  _R10 = &_R11[(_DWORD)_R25];
                  __asm
                  {
                    lvx128    v43, r25, r11
                    lvx128    v42, r10, r9
                    stvx128   v42, r0, r11
                    stvx128   v43, r11, r8
                  }
                  _R11 += 32;
                }
                _R25 -= 256;
                v117 = _R11;
                v106 = v209;
                v204 += 8;
                v205 += 36;
                if ( v204 > 21496 )
                  break;
              }
              ++v116;
            }
            while ( v116 < v73->latchedTireDecalRange[1] );
          }
          v115->numVerts = v204 - v114;
          v115->numIndexes = v205 - v202;
          idVertexBuffer::Reference(
            this: &v115->vertexBuffer,
            other: v207,
            refOffset: v114 * v206,
            refSize: (v204 - v114) * v206);
          idIndexBuffer::Reference(
            this: &v115->indexBuffer,
            other: &v73->indexBufferBoxes,
            refOffset: 0,
            refSize: 2 * (v205 - v202));
          HIDWORD(_R4) = idList<idRenderModelSurface,62>::Append(this: &v73->surfaces, obj: &v213);
        }
        v105 = v73->latchedTireDecalRange[1];
        v209 = ++v106;
      }
      while ( v106 < v105 );
    }
    idVertexBuffer::UnmapBuffer(this: (idPixelUnpackBuffer *)v207);
    idRenderModel::CommitSurfaces(this: v73);
    if ( v223.logIndex >= 0 )
    {
      pLog = v223.pLog;
      v193 = &v223.pLog->logEntries.list[v223.logIndex];
      v194 = (unsigned __int64)Sys_GetClockTicks() >> 32;
      totalTicks = v193->totalTicks;
      HIDWORD(totalTicks) = v193->parent;
      LODWORD(v196) = v194 - totalTicks;
      v193->totalTicks = v196;
      pLog->lastEntry = HIDWORD(totalTicks);
    }
  }
  _R0 = -256;
  __asm { lvx128    v127, r1, r0 }
  return 0;
}


// ========================================================================
// __unwind$234439
// EA  : 0x827FFFC8
// RVA : 0x007FFFC8
// PDB : w:\tech5\engine\models\rendermodeldecal.cpp
// ========================================================================

void _unwind_234439()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 1504 + 248));
}


// ========================================================================
// `dynamic initializer for 'r_skipDecals''
// EA  : 0x833438B8
// RVA : 0x013438B8
// PDB : w:\tech5\engine\models\rendermodeldecal.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_skipDecals__()
{
  idCVar::idCVar(
    this: &r_skipDecals,
    name: "r_skipDecals",
    value: "0",
    flags: 1,
    description: "skip rendermodel decals",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_skipDecals__);
}


// ========================================================================
// `dynamic initializer for 'r_debugDecals''
// EA  : 0x83343910
// RVA : 0x01343910
// PDB : w:\tech5\engine\models\rendermodeldecal.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_debugDecals__()
{
  idCVar::idCVar(
    this: &r_debugDecals,
    name: "r_debugDecals",
    value: "0",
    flags: 2,
    description: "1 - To display the decal axis.  2 - To see the axis and obb.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_debugDecals__);
}


// ========================================================================
// `dynamic initializer for 'r_oldDecalGen''
// EA  : 0x83343968
// RVA : 0x01343968
// PDB : w:\tech5\engine\models\rendermodeldecal.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_oldDecalGen__()
{
  idCVar::idCVar(
    this: &r_oldDecalGen,
    name: "r_oldDecalGen",
    value: "0",
    flags: 1,
    description: "1 - Fall back to old GenDecalVerts serially instead of 4 at a time",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_oldDecalGen__);
}


// ========================================================================
// `dynamic initializer for 'idRenderModelDecal::preAllocatedVertexBuffer''
// EA  : 0x833439C0
// RVA : 0x013439C0
// PDB : w:\tech5\engine\models\rendermodeldecal.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__idRenderModelDecal::preAllocatedVertexBuffer__()
{
  `eh vector constructor iterator'(
    ptr: (char *)idRenderModelDecal::preAllocatedVertexBuffer,
    size: 0x10u,
    count: 2,
    pCtor: (void (__fastcall *)(void *))idIndexBuffer::idIndexBuffer,
    pDtor: (void (__fastcall *)(void *))idVertexBuffer::~idVertexBuffer);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__idRenderModelDecal::preAllocatedVertexBuffer__);
}


// ========================================================================
// `dynamic initializer for 'idRenderModelDecal::preAllocatedIndexBufferBoxes''
// EA  : 0x83343A10
// RVA : 0x01343A10
// PDB : w:\tech5\engine\models\rendermodeldecal.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__idRenderModelDecal::preAllocatedIndexBufferBoxes__()
{
  idIndexBuffer::idIndexBuffer(this: &idRenderModelDecal::preAllocatedIndexBufferBoxes);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__idRenderModelDecal::preAllocatedIndexBufferBoxes__);
}


// ========================================================================
// `dynamic initializer for 'idRenderModelDecal::preAllocatedIndexBufferQuads''
// EA  : 0x83343A48
// RVA : 0x01343A48
// PDB : w:\tech5\engine\models\rendermodeldecal.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__idRenderModelDecal::preAllocatedIndexBufferQuads__()
{
  idIndexBuffer::idIndexBuffer(this: &idRenderModelDecal::preAllocatedIndexBufferQuads);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__idRenderModelDecal::preAllocatedIndexBufferQuads__);
}

