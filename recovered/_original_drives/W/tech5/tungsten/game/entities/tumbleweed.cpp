
// ========================================================================
// ?SetupDeferredDropShadowTraceModel@@YAPAVidRecycledTraceModel@@MM@Z
// EA  : 0x82CF3A28
// RVA : 0x00CF3A28
// PDB : w:\tech5\tungsten\game\entities\tumbleweed.cpp
// ========================================================================

idRecycledTraceModel *__fastcall SetupDeferredDropShadowTraceModel(double size, double depth)
{
  double v3; // fp5
  double v4; // fp8
  double x; // fp0
  double v6; // fp11
  double y; // fp13
  double z; // fp12
  double v9; // fp3
  double v10; // fp4
  double v11; // fp6
  double v12; // fp9
  double v13; // fp7
  double v14; // fp10
  idTraceModel **TraceModel; // r3
  idTraceModel **v16; // r31
  idVec3 v18; // [sp+50h] [-60h] BYREF
  idVec3 v19; // [sp+60h] [-50h] BYREF
  float v20; // [sp+6Ch] [-44h]
  float v21; // [sp+70h] [-40h]
  float v22; // [sp+74h] [-3Ch]
  float v23; // [sp+78h] [-38h]
  float v24; // [sp+7Ch] [-34h]
  float v25; // [sp+80h] [-30h]
  float v26; // [sp+84h] [-2Ch]
  float v27; // [sp+88h] [-28h]
  float v28; // [sp+8Ch] [-24h]

  if ( (_S18_15 & 1) != 0 )
  {
    z = baseWinding[3].z;
    y = baseWinding[3].y;
    x = baseWinding[3].x;
    v6 = baseWinding[2].z;
    v14 = baseWinding[2].y;
    v12 = baseWinding[2].x;
    v4 = baseWinding[1].z;
    v13 = baseWinding[1].y;
    v11 = baseWinding[1].x;
    v3 = baseWinding[0].z;
    v10 = baseWinding[0].y;
    v9 = baseWinding[0].x;
  }
  else
  {
    baseWinding[0].z = 0.0;
    baseWinding[1].z = 0.0;
    baseWinding[2].z = 0.0;
    baseWinding[3].z = 0.0;
    v3 = 0.0;
    v4 = 0.0;
    _S18_15 |= 1u;
    x = -1.0;
    v6 = 0.0;
    y = 1.0;
    z = 0.0;
    baseWinding[0].x = -1.0;
    v9 = -1.0;
    baseWinding[0].y = -1.0;
    v10 = -1.0;
    baseWinding[1].x = 1.0;
    v11 = 1.0;
    baseWinding[1].y = -1.0;
    v12 = 1.0;
    baseWinding[2].x = 1.0;
    v13 = -1.0;
    baseWinding[2].y = 1.0;
    v14 = 1.0;
    baseWinding[3].x = -1.0;
    baseWinding[3].y = 1.0;
  }
  v24 = (float)((float)size * (float)0.5) * (float)v14;
  v23 = (float)((float)size * (float)0.5) * (float)v12;
  v19.x = (float)((float)size * (float)0.5) * (float)v9;
  v19.y = (float)((float)size * (float)0.5) * (float)v10;
  v20 = (float)((float)size * (float)0.5) * (float)v11;
  v21 = (float)((float)size * (float)0.5) * (float)v13;
  v26 = (float)((float)size * (float)0.5) * (float)x;
  v22 = (float)((float)((float)size * (float)0.5) * (float)v4) + (float)depth;
  v27 = (float)((float)size * (float)0.5) * (float)y;
  v19.z = (float)((float)((float)size * (float)0.5) * (float)v3) + (float)depth;
  v25 = (float)((float)((float)size * (float)0.5) * (float)v6) + (float)depth;
  v28 = (float)((float)((float)size * (float)0.5) * (float)z) + (float)depth;
  TraceModel = (idTraceModel **)idTraceModelRecycler::GetTraceModel(this: clientGame->clip.traceModelRecycler);
  v18.x = 0.0;
  v18.y = 0.0;
  v18.z = (float)depth * (float)-2.0;
  v16 = TraceModel;
  idTraceModel::SetupPolygonVolume(this: *TraceModel, v: &v19, count: 4, dir: &v18);
  return (idRecycledTraceModel *)v16;
}


// ========================================================================
// ??0idTumbleWeed@@QAA@XZ
// EA  : 0x82CF3BF8
// RVA : 0x00CF3BF8
// PDB : w:\tech5\tungsten\game\entities\tumbleweed.cpp
// ========================================================================

idTumbleWeed *__fastcall idTumbleWeed::idTumbleWeed(idTumbleWeed *this)
{
  unsigned __int64 v2; // r11
  int v3; // ctr
  float *p_z; // r9
  float *p_y; // r10

  idDynamicEntity::idDynamicEntity(this);
  LODWORD(v2) = 0;
  this->__vftable = (idTumbleWeed_vtbl *)&idTumbleWeed::`vftable';
  this->windOffset = 0.0;
  this->shadow = nullptr;
  this->scale = 1.0;
  this->radius = 1.0;
  this->center.x = 0.0;
  this->center.y = 0.0;
  HIDWORD(v2) = &this->deferredDropShadow;
  this->center.z = 0.0;
  this->velocity.x = 0.0;
  v3 = 9;
  this->velocity.y = 0.0;
  p_z = &this->deferredDropShadow.origin.z;
  this->velocity.z = 0.0;
  this->moveQuery.index = v2;
  this->deferredDropShadow.query.index = v2;
  p_y = &mat2_identity.mat[1].y;
  this->deferredDropShadow.origin = vec3_origin;
  do
  {
    *++p_z = *++p_y;
    --v3;
  }
  while ( v3 != 0 );
  this->dropShadowTrm = nullptr;
  this->modelAxis.mat[2].z = 1.0;
  this->modelAxis.mat[1].y = 1.0;
  this->modelAxis.mat[0].x = 1.0;
  this->modelAxis.mat[1].z = 0.0;
  this->modelAxis.mat[0].z = 0.0;
  this->modelAxis.mat[0].y = 0.0;
  this->modelAxis.mat[2].y = 0.0;
  this->modelAxis.mat[2].x = 0.0;
  this->modelAxis.mat[1].x = 0.0;
  return this;
}


// ========================================================================
// ??1idTumbleWeed@@UAA@XZ
// EA  : 0x82CF3CF0
// RVA : 0x00CF3CF0
// PDB : w:\tech5\tungsten\game\entities\tumbleweed.cpp
// ========================================================================

void __fastcall idTumbleWeed::~idTumbleWeed(idTumbleWeed *this, int a2, int a3, int a4, int a5, int a6)
{
  idRecycledTraceModel *dropShadowTrm; // r4
  int v8; // [sp+8h] [-68h]
  int v9; // [sp+Ch] [-64h]
  int v10; // [sp+10h] [-60h]
  int v11; // [sp+14h] [-5Ch]
  int v12; // [sp+18h] [-58h]
  idRecycledTraceModel *v13; // [sp+1Ch] [-54h]

  this->__vftable = (idTumbleWeed_vtbl *)&idTumbleWeed::`vftable';
  dropShadowTrm = this->dropShadowTrm;
  if ( dropShadowTrm != nullptr )
  {
    idTraceModelRecycler::RecycleTraceModel(
      this: clientGame->clip.traceModelRecycler,
      recycledTrm: dropShadowTrm,
      defer: true,
      a4,
      a5,
      a6,
      a7: 163960,
      a8: 0x20000,
      a9: v8,
      a10: v9,
      a11: v10,
      a12: v11,
      a13: v12,
      a14: v13);
    this->dropShadowTrm = nullptr;
  }
  this->__vftable = (idTumbleWeed_vtbl *)&idDynamicEntity::`vftable';
  idEntity::~idEntity(this);
}


// ========================================================================
// __unwind$489034
// EA  : 0x82CF3D80
// RVA : 0x00CF3D80
// PDB : w:\tech5\tungsten\game\entities\tumbleweed.cpp
// ========================================================================

void _unwind_489034()
{
  int v0; // r12

  idDynamicEntity::~idDynamicEntity(this: *(idDynamicEntity **)(v0 - 112 + 132));
}


// ========================================================================
// ?GetModelTransform@idTumbleWeed@@UBAXAAVidVec3@@AAVidMat3@@@Z
// EA  : 0x82CF3DA8
// RVA : 0x00CF3DA8
// PDB : w:\tech5\tungsten\game\entities\tumbleweed.cpp
// ========================================================================

void __fastcall idTumbleWeed::GetModelTransform(idTumbleWeed *this, idVec3 *modelOrigin, idMat3 *modelAxis)
{
  double scale; // fp0
  double v6; // fp7
  double v7; // fp9
  double v8; // fp5
  double v9; // fp3
  double v10; // fp1
  double v11; // fp12
  double y; // fp10
  double v13; // fp8
  float *p_modelAxis; // r31
  idPhysics *Physics; // r3
  idPresentable *presentable; // r11
  idPhysics *v17; // r28
  double v19; // fp4
  double v21; // fp9
  double v22; // fp13
  double v23; // fp9
  double v24; // fp31
  double v25; // fp30
  double v26; // fp29
  float *v27; // r3
  double v28; // fp3
  double v29; // fp2

  scale = this->scale;
  v6 = (float)(this->scale * this->modelAxis.mat[0].z);
  v7 = (float)(this->scale * this->modelAxis.mat[1].x);
  v8 = (float)(this->scale * this->modelAxis.mat[0].y);
  v9 = (float)(this->modelAxis.mat[2].z * this->scale);
  v10 = (float)(this->scale * this->modelAxis.mat[2].y);
  v11 = (float)(this->scale * this->modelAxis.mat[2].x);
  y = this->modelAxis.mat[1].y;
  v13 = (float)(this->scale * this->modelAxis.mat[1].z);
  modelAxis->mat[0].x = this->modelAxis.mat[0].x * this->scale;
  modelAxis->mat[1].x = v7;
  p_modelAxis = (float *)&this->modelAxis;
  modelAxis->mat[0].y = v8;
  modelAxis->mat[0].z = v6;
  modelAxis->mat[1].y = (float)scale * (float)y;
  modelAxis->mat[1].z = v13;
  modelAxis->mat[2].x = v11;
  modelAxis->mat[2].y = v10;
  modelAxis->mat[2].z = v9;
  Physics = idEntity::GetPhysics(this);
  presentable = this->presentable;
  v17 = Physics;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    presentable = this->presentable;
  }
  _FP7 = (float)((float)((float)(presentable->axis.mat[0].z * presentable->axis.mat[0].z)
                       + (float)((float)(presentable->axis.mat[0].x * presentable->axis.mat[0].x)
                               + (float)(presentable->axis.mat[0].y * presentable->axis.mat[0].y)))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  v19 = (float)((float)((float)(presentable->axis.mat[0].z * presentable->axis.mat[0].z)
                      + (float)((float)(presentable->axis.mat[0].x * presentable->axis.mat[0].x)
                              + (float)(presentable->axis.mat[0].y * presentable->axis.mat[0].y)))
              * (float)0.5);
  __asm { fsel      f11, f7, f2, f13 }
  v21 = __frsqrte(_FP11);
  v22 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v21
                                                                                      * (float)((float)((float)(presentable->axis.mat[0].z * presentable->axis.mat[0].z) + (float)((float)(presentable->axis.mat[0].x * presentable->axis.mat[0].x) + (float)(presentable->axis.mat[0].y * presentable->axis.mat[0].y)))
                                                                                              * (float)0.5))
                                                                              * (float)v21)
                                                                      - (float)1.5)
                                                      * (float)v21)
                                              * (float)((float)((float)(presentable->axis.mat[0].z
                                                                      * presentable->axis.mat[0].z)
                                                              + (float)((float)(presentable->axis.mat[0].x
                                                                              * presentable->axis.mat[0].x)
                                                                      + (float)(presentable->axis.mat[0].y
                                                                              * presentable->axis.mat[0].y)))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v21
                                                                              * (float)((float)((float)(presentable->axis.mat[0].z * presentable->axis.mat[0].z)
                                                                                              + (float)((float)(presentable->axis.mat[0].x * presentable->axis.mat[0].x) + (float)(presentable->axis.mat[0].y * presentable->axis.mat[0].y)))
                                                                                      * (float)0.5))
                                                                      * (float)v21)
                                                              - (float)1.5)
                                              * (float)v21))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v21
                                                      * (float)((float)((float)(presentable->axis.mat[0].z
                                                                              * presentable->axis.mat[0].z)
                                                                      + (float)((float)(presentable->axis.mat[0].x
                                                                                      * presentable->axis.mat[0].x)
                                                                              + (float)(presentable->axis.mat[0].y
                                                                                      * presentable->axis.mat[0].y)))
                                                              * (float)0.5))
                                              * (float)v21)
                                      - (float)1.5)
                      * (float)v21));
  v23 = (float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v21 * (float)((float)((float)(presentable->axis.mat[0].z * presentable->axis.mat[0].z) + (float)((float)(presentable->axis.mat[0].x * presentable->axis.mat[0].x) + (float)(presentable->axis.mat[0].y * presentable->axis.mat[0].y))) * (float)0.5)) * (float)v21) - (float)1.5)
                                                                                      * (float)v21)
                                                                              * (float)((float)((float)(presentable->axis.mat[0].z * presentable->axis.mat[0].z)
                                                                                              + (float)((float)(presentable->axis.mat[0].x * presentable->axis.mat[0].x) + (float)(presentable->axis.mat[0].y * presentable->axis.mat[0].y)))
                                                                                      * (float)0.5))
                                                                      * (float)((float)-(float)((float)((float)((float)v21 * (float)((float)((float)(presentable->axis.mat[0].z * presentable->axis.mat[0].z) + (float)((float)(presentable->axis.mat[0].x * presentable->axis.mat[0].x) + (float)(presentable->axis.mat[0].y * presentable->axis.mat[0].y))) * (float)0.5)) * (float)v21)
                                                                                              - (float)1.5)
                                                                              * (float)v21))
                                                              - (float)1.5)
                                              * (float)((float)-(float)((float)((float)((float)v21
                                                                                      * (float)((float)((float)(presentable->axis.mat[0].z * presentable->axis.mat[0].z) + (float)((float)(presentable->axis.mat[0].x * presentable->axis.mat[0].x) + (float)(presentable->axis.mat[0].y * presentable->axis.mat[0].y)))
                                                                                              * (float)0.5))
                                                                              * (float)v21)
                                                                      - (float)1.5)
                                                      * (float)v21))
                                      * (float)v19)
                              * (float)v22)
                      - (float)1.5);
  v24 = (float)((float)(this->center.x
                      - (float)((float)(this->center.x * *p_modelAxis)
                              + (float)((float)(this->center.y * p_modelAxis[3])
                                      + (float)(this->center.z * p_modelAxis[6]))))
              * (float)((float)v23 * (float)v22));
  v25 = (float)((float)(this->center.y
                      - (float)((float)(this->center.z * p_modelAxis[7])
                              + (float)((float)(this->center.x * p_modelAxis[1])
                                      + (float)(this->center.y * p_modelAxis[4]))))
              * (float)((float)v23 * (float)v22));
  v26 = (float)((float)(this->center.z
                      - (float)((float)(this->center.z * p_modelAxis[8])
                              + (float)((float)(this->center.x * p_modelAxis[2])
                                      + (float)(this->center.y * p_modelAxis[5]))))
              * (float)((float)v23 * (float)v22));
  v27 = (float *)v17->GetOrigin(this: v17, a2: 0);
  v28 = (float)(v27[1] + (float)v25);
  v29 = (float)(v27[2] + (float)v26);
  modelOrigin->x = *v27 + (float)v24;
  modelOrigin->y = v28;
  modelOrigin->z = v29;
}


// ========================================================================
// ?DeferredDropShadow@@YAXABVidVec3@@ABVidMat3@@MMPBVidTraceModel@@PBVidMaterial@@AAVidDeferredShadow@@@Z
// EA  : 0x82CF41F0
// RVA : 0x00CF41F0
// PDB : w:\tech5\tungsten\game\entities\tumbleweed.cpp
// ========================================================================

void __fastcall DeferredDropShadow(
        const idVec3 *origin,
        const idMat3 *axis,
        double size,
        double depth,
        const idTraceModel *trm,
        const idMaterial *material,
        idDeferredShadow *deferredShadow,
        const idMaterial *a8,
        idClipQuery *a9,
        int a10,
        int a11,
        int a12,
        int a13,
        const idVec3 *a14,
        int a15,
        const idMat3 *a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        idDeferredShadow *a22,
        int a23,
        const idMaterial *a24)
{
  unsigned __int64 v24; // r17
  const idVec3 *v26; // r25
  const idMat3 *v28; // r30
  const idTraceModel *v30; // r26
  idClientGame *v32; // r31
  idClipQuery v33; // r11
  double v37; // fp28
  double v39; // fp23
  double v40; // fp22
  double v42; // fp27
  double v43; // fp24
  double v44; // fp21
  double v45; // fp26
  double v46; // fp25
  double v47; // fp20
  double v48; // fp19
  double v49; // fp17
  double v50; // fp18
  __int16 *indices; // r30
  float *p_y; // r8
  int v63; // ctr
  idVec3 *v67; // r9
  double z; // fp12
  double x; // fp11
  double y; // fp10
  double v71; // fp8
  double v72; // fp7
  double v73; // fp4
  double v74; // fp10
  double v75; // fp2
  int v76; // r10
  const idMaterial *v77; // r15
  const idMaterial *v78; // r14
  idRenderModelEffects *MergeBranch; // r3
  const char *v81; // [sp+8h] [-5A8h]
  int v82; // [sp+Ch] [-5A4h]
  int v83; // [sp+10h] [-5A0h]
  int v84; // [sp+14h] [-59Ch]
  int v85; // [sp+18h] [-598h]
  int v86; // [sp+1Ch] [-594h]
  int v87; // [sp+20h] [-590h]
  int v88; // [sp+24h] [-58Ch]
  int v89; // [sp+28h] [-588h]
  int v90; // [sp+2Ch] [-584h]
  int v91; // [sp+30h] [-580h]
  int v92; // [sp+34h] [-57Ch]
  int v93; // [sp+38h] [-578h]
  int v94; // [sp+3Ch] [-574h]
  int v95; // [sp+40h] [-570h]
  int v96; // [sp+44h] [-56Ch]
  int v97; // [sp+48h] [-568h]
  int v98; // [sp+4Ch] [-564h]
  int v99; // [sp+50h] [-560h]
  int v100; // [sp+58h] [-558h]
  int v101; // [sp+70h] [-540h] BYREF
  int v102; // [sp+74h] [-53Ch]
  idDrawVert v103; // [sp+80h] [-530h] BYREF
  idDrawVert v104; // [sp+A0h] [-510h] BYREF
  idDrawVert v105; // [sp+C0h] [-4F0h] BYREF
  clipResult_t v106; // [sp+E0h] [-4D0h] BYREF

  _R12 = -304;
  __asm { stvx128   v127, r1, r12 }
  a14 = origin;
  v26 = origin;
  a16 = axis;
  v28 = axis;
  a22 = deferredShadow;
  v30 = (const idTraceModel *)deferredShadow;
  a24 = a8;
  v32 = clientGame;
  if ( (unsigned __int8)idClip::QueryIsValid(this: &clientGame->clip, clipQuery: a9) != 0 )
  {
    LODWORD(v24) = 0;
    v33.index = a9->index;
    a9->index = v24;
    idCollisionModelManager::GetClipResult(
      this: collisionModelManager,
      result: &v106,
      query: &v32->clip.collisionQueries[v33.index & 0xFFF].query,
      peek: false);
    if ( v106.numIndices <= 0 )
    {
      v32 = clientGame;
    }
    else
    {
      _R29 = (float *)&a9[5].index + 1;
      _R18 = (char *)&a9[2].index + 4;
      v37 = *(float *)&a9[5].index;
      _R28 = (float *)&a9[6].index + 1;
      v39 = *((float *)&a9[6].index + 1);
      v40 = *((float *)&a9[3].index + 1);
      _R27 = (float *)&a9[6];
      v42 = *(float *)&a9[4].index;
      v43 = *((float *)&a9[2].index + 1);
      v44 = *(float *)&a9[6].index;
      v45 = *((float *)&a9[4].index + 1);
      v46 = *((float *)&a9[5].index + 1);
      v47 = *(float *)&a9[3].index;
      v48 = (float)-(float)((float)(*(float *)&a9[1].index * *((float *)&a9[5].index + 1))
                          + (float)((float)(*(float *)&a9[6].index * *((float *)&a9[1].index + 1))
                                  + (float)(*((float *)&a9[6].index + 1) * *(float *)&a9[2].index)));
      v49 = (float)-(float)((float)(*((float *)&a9[4].index + 1) * (float)(v30->vertsY[0] + *((float *)&a9[1].index + 1)))
                          + (float)((float)(*(float *)&a9[4].index * (float)(*(float *)&a9[1].index + v30->vertsX[0]))
                                  + (float)(*(float *)&a9[5].index * (float)(v30->vertsZ[0] + *(float *)&a9[2].index))));
      v50 = (float)-(float)((float)(*(float *)&a9[3].index * (float)(v30->vertsY[0] + *((float *)&a9[1].index + 1)))
                          + (float)((float)(*((float *)&a9[2].index + 1)
                                          * (float)(*(float *)&a9[1].index + v30->vertsX[0]))
                                  + (float)(*((float *)&a9[3].index + 1)
                                          * (float)(v30->vertsZ[0] + *(float *)&a9[2].index))));
      __asm { vspltisw128 v127, 0 }
      _R7 = &`VertexFloatToByte'::`2'::SIMD_SP_255_over_2;
      _R6 = &`VertexFloatToByte'::`2'::SIMD_SP_half;
      _R9 = &_vmx_3f8000003f8000003f8000003f800000;
      indices = v106.indices;
      _R26 = 3;
      _R21 = 16;
      _R22 = -2;
      _R23 = -1;
      _R24 = 2;
      _R25 = 4;
      while ( 1 )
      {
        _R11 = a9 + 3;
        __asm
        {
          vmr128    v59, v127
          lvlx128   v58, r0, r18
        }
        __asm { lvx128    v63, r0, r9 }
        p_y = &v103.st.y;
        __asm { lvx128    v12, r0, r6 }
        v63 = 3;
        __asm
        {
          vrlimi128 v59, v58, 8, 0
          lvx128    v11, r0, r7
          lvlx128   v57, r0, r11
        }
        _R11 = (char *)&a9[3].index + 4;
        __asm
        {
          lvlx128   v62, r0, r28
          lvlx128   v61, r0, r27
          vrlimi128 v59, v57, 4, 3
          lvlx128   v60, r0, r29
          lvlx128   v56, r0, r11
        }
        _R11 = &v103.normal[2];
        __asm
        {
          vrlimi128 v59, v56, 2, 2
          vaddfp128 v0, v91, v63
          vmaddfp   v0, v0, v12, v11
          vcfpsxws128 v59, v0, 0
        }
        do
        {
          __asm { vmr128    v54, v127 }
          __asm { vmr128    v55, v127 }
          _R10 = _R11 - 22;
          __asm { vor128    v53, v91, v59 }
          __asm { vcmpequw128 v52, v86, v54 }
          __asm { vrlimi128 v55, v60, 8, 0 }
          __asm
          {
            stvx128   v54, r0, r10
            vpkswss128 v51, v85, v53
            vsldoi128 v50, v86, v52, 4
          }
          __asm { vrlimi128 v55, v61, 4, 3 }
          v67 = &v106.verts[*indices];
          __asm
          {
            vpkshus128 v0, v83, v51
            vrlimi128 v55, v62, 2, 2
            stvx128   v50, r10, r21
          }
          __asm { vaddfp128 v13, v87, v63 }
          z = v67->z;
          x = v67->x;
          y = v67->y;
          __asm { vmaddfp   v13, v13, v12, v11 }
          v71 = (float)(*_R28 * (float)0.1);
          v72 = (float)(*_R27 * (float)0.1);
          v73 = (float)(v67->z * (float)v39);
          *(float *)(_R11 - 22) = v67->x + (float)(*_R29 * (float)0.1);
          *(float *)(_R11 - 14) = (float)z + (float)v71;
          *(float *)(_R11 - 18) = (float)y + (float)v72;
          __asm { vcfpsxws128 v49, v13, 0 }
          __asm
          {
            vpkswss128 v48, v81, v49
            vpkshus128 v13, v80, v48
          }
          __asm
          {
            stvebx    v13, r11, r22
            stvebx    v13, r11, r23
            stvebx    v13, 0, r11
            stvebx    v0, r11, r24
            stvebx    v0, r11, r26
            stvebx    v0, r11, r25
          }
          _R11[5] = -1;
          v74 = __fabs((float)((float)((float)((float)((float)y * (float)v44)
                                             + (float)((float)((float)x * (float)v46) + (float)v73))
                                     + (float)v48)
                             * (float)((float)1.0 / (float)depth)));
          v75 = (float)((float)((float)((float)v43 * *(float *)(_R11 - 22))
                              + (float)((float)(*(float *)(_R11 - 14) * (float)v40)
                                      + (float)(*(float *)(_R11 - 18) * (float)v47)))
                      + (float)v50);
          v102 = (int)(float)-(float)((float)((float)v74 * (float)255.0) - (float)255.0);
          v76 = v102;
          *(p_y - 1) = (float)v75 * (float)((float)1.0 / (float)size);
          *p_y = (float)((float)((float)((float)v42 * *(float *)(_R11 - 22))
                               + (float)((float)(*(float *)(_R11 - 14) * (float)v37)
                                       + (float)(*(float *)(_R11 - 18) * (float)v45)))
                       + (float)v49)
               * (float)((float)1.0 / (float)size);
          _R11[8] = -1;
          _R11[7] = -1;
          _R11[6] = -1;
          if ( (int)(float)-(float)((float)((float)v74 * (float)255.0) - (float)255.0) >= 0 )
          {
            if ( v76 > 255 )
              LOBYTE(v76) = -1;
          }
          else
          {
            LOBYTE(v76) = 0;
          }
          _R11[9] = v76;
          ++indices;
          p_y += 8;
          _R11 += 32;
          --v63;
        }
        while ( v63 != 0 );
        HIDWORD(v24) = gameLocal->GetGameMsPerFrame(this: gameLocal, a2: GAMETIME_SCALED);
        v77 = (const idMaterial *)gameLocal->GetGameMsPerFrame(this: gameLocal, a2: GAMETIME_SCALED);
        v78 = (const idMaterial *)gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
        MergeBranch = (idRenderModelEffects *)idAnimator_BlendEq::InternalGetMergeBranch(this: (idAnimator_BlendEq *)clientGame);
        idRenderModelEffects::AddDecal(
          this: MergeBranch,
          mat: a24,
          v0: &v103,
          v1: &v104,
          v2: &v105,
          v3: &v105,
          startTime: v78,
          lifeTime: v77,
          fadeInEndTime: (const int)v81,
          fadeOutStartTime: v82,
          a11: v83,
          a12: v84,
          a13: v85,
          a14: v86,
          a15: v87,
          a16: v88,
          a17: v89,
          a18: v90,
          a19: v91,
          a20: v92,
          a21: v93,
          a22: v94,
          a23: v95,
          a24: v96,
          a25: v97,
          a26: v98,
          a27: v99,
          a28: nullptr,
          a29: v100,
          a30: (const idMaterial *)HIDWORD(v24));
        LODWORD(v24) = v24 + 3;
        if ( (int)v24 >= v106.numIndices )
          break;
        _R9 = &_vmx_3f8000003f8000003f8000003f800000;
        _R6 = &`VertexFloatToByte'::`2'::SIMD_SP_half;
        _R7 = &`VertexFloatToByte'::`2'::SIMD_SP_255_over_2;
      }
      v26 = a14;
      v28 = a16;
      v30 = (const idTraceModel *)a22;
      v32 = clientGame;
    }
  }
  a9->index = *(unsigned __int64 *)&idClip::Clip(
                                      this: (idClip *)&v101,
                                      result: &v32->clip,
                                      a3: nullptr,
                                      start: v26,
                                      trm: v30,
                                      startAxis: v28,
                                      clipMask: 1,
                                      passEntityNumber: 0x2000,
                                      userName: v81,
                                      a10: v82,
                                      a11: v83,
                                      a12: v84,
                                      a13: v85,
                                      a14: v86,
                                      a15: v87,
                                      a16: v88,
                                      a17: v89,
                                      a18: v90,
                                      a19: v91,
                                      a20: v92,
                                      a21: v93,
                                      a22: v94,
                                      a23: v95,
                                      a24: v96,
                                      a25: v97,
                                      a26: v98,
                                      a27: v99,
                                      a28: (int)"w:\\tech5\\tungsten\\game\\entities\\TumbleWeed.cpp(91) : Clip")->world;
  *(float *)&a9[1].index = v26->x;
  *((float *)&a9[1].index + 1) = v26->y;
  *(float *)&a9[2].index = v26->z;
  *((float *)&a9[2].index + 1) = v28->mat[0].x;
  *(float *)&a9[3].index = v28->mat[0].y;
  *((float *)&a9[3].index + 1) = v28->mat[0].z;
  *(float *)&a9[4].index = v28->mat[1].x;
  *((float *)&a9[4].index + 1) = v28->mat[1].y;
  *(float *)&a9[5].index = v28->mat[1].z;
  *((float *)&a9[5].index + 1) = v28->mat[2].x;
  *(float *)&a9[6].index = v28->mat[2].y;
  *((float *)&a9[6].index + 1) = v28->mat[2].z;
  _R0 = -304;
  __asm { lvx128    v127, r1, r0 }
}


// ========================================================================
// ?Spawn@idTumbleWeed@@QAAXXZ
// EA  : 0x82CF4750
// RVA : 0x00CF4750
// PDB : w:\tech5\tungsten\game\entities\tumbleweed.cpp
// ========================================================================

void __fastcall idTumbleWeed::Spawn(idTumbleWeed *this)
{
  __int128 v2; // r5
  unsigned int v3; // r6
  unsigned int v4; // r7
  idPresentable *presentable; // r11
  char v6; // r10
  int *v7; // r10
  idRenderModelCommitted **p_committed; // r11
  int i; // ctr
  double y; // fp6
  double scale; // fp3
  double v12; // fp5
  double v13; // fp12
  double v14; // fp10
  double v15; // fp9
  idClipModel *v16; // r3
  idClipModel *v17; // r29
  idPhysics *Physics; // r3
  idPhysics *v19; // r3
  idPhysics *v20; // r3
  idPhysics *v21; // r3
  int v22; // [sp+5Ch] [-654h] BYREF
  idBounds v23; // [sp+60h] [-650h] BYREF
  idTraceModel v24; // [sp+80h] [-630h] BYREF

  DWORD1(v2) = clientGame->random.seed;
  v3 = 1664525 * clientGame->random.seed + 1013904223;
  clientGame->random.seed = v3;
  DWORD2(v2) = (v3 >> 10) & 0x7FFF;
  this->windOffset = (float)((float)((float)*(__int64 *)((char *)&v2 + 4) * (float)0.000061037019) - (float)1.0)
                   * (float)0.2;
  v4 = 1664525 * clientGame->random.seed + 1013904223;
  clientGame->random.seed = v4;
  presentable = this->presentable;
  LODWORD(v2) = (v4 >> 10) & 0x7FFF;
  this->scale = (float)((float)(__int64)v2 * (float)0.000022888882) + (float)0.5;
  if ( presentable == nullptr || (v6 = 1, presentable->model == nullptr) )
    v6 = 0;
  if ( v6 != 0 )
  {
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      presentable = this->presentable;
    }
    v7 = &v22;
    p_committed = &presentable->model->committed;
    for ( i = 6; i != 0; --i )
      *++v7 = (int)*++p_committed;
    y = v23.b[1].y;
    scale = this->scale;
    v12 = (float)(v23.b[0].y - (float)-4.0);
    v13 = (float)((float)((float)(v23.b[0].x - (float)-4.0) * this->scale)
                + (float)((float)(v23.b[1].x - (float)4.0) * this->scale));
    v23.b[0].x = (float)(v23.b[0].x - (float)-4.0) * this->scale;
    v23.b[1].x = (float)(v23.b[1].x - (float)4.0) * (float)scale;
    v14 = (float)((float)((float)(v23.b[0].z - (float)-4.0) * (float)scale)
                + (float)((float)(v23.b[1].z - (float)4.0) * (float)scale));
    v15 = (float)((float)((float)(v23.b[1].z - (float)4.0) * (float)scale)
                - (float)((float)(v23.b[0].z - (float)-4.0) * (float)scale));
    v23.b[1].z = (float)(v23.b[1].z - (float)4.0) * (float)scale;
    v23.b[0].z = (float)(v23.b[0].z - (float)-4.0) * (float)scale;
    v23.b[1].y = (float)(v23.b[1].y - (float)4.0) * (float)scale;
    v23.b[0].y = (float)(v23.b[0].y - (float)-4.0) * (float)scale;
    this->center.x = (float)v13 * (float)0.5;
    this->center.y = (float)((float)((float)v12 * (float)scale) + (float)((float)((float)y - (float)4.0) * (float)scale))
                   * (float)0.5;
    this->center.z = (float)v14 * (float)0.5;
    this->radius = (float)v15 * (float)0.5;
    idTraceModel::InitBox(this: &v24);
    idTraceModel::SetupBox(this: &v24, boxBounds: &v23);
    v16 = (idClipModel *)idMem::AllocWithLocation(
                           this: &mem,
                           location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                           size: 0xD8u,
                           tag: TAG_CLIPMODEL,
                           zeroBuffer: false,
                           align: ALIGN_16,
                           heap: HEAP_DEFAULTHEAP);
    if ( v16 != nullptr )
      v17 = idClipModel::idClipModel(
              this: v16,
              clip: &clientGame->clip,
              trm: &v24,
              numTraceModels: 1,
              material: nullptr);
    else
      v17 = nullptr;
    Physics = idEntity::GetPhysics(this);
    ((void (__fastcall *)(idPhysics *, idClipModel *, double))Physics->SetClipModel)(
      a1: Physics,
      a2: v17,
      a3: 0.0040000002);
    v19 = idEntity::GetPhysics(this);
    v19->SetContents(this: v19, a2: 0, a3: -1);
    v20 = idEntity::GetPhysics(this);
    v20->SetAxis(this: v20, a2: &mat3_identity, a3: -1);
    v21 = idEntity::GetPhysics(this);
    v21->UnlinkClip(this: v21);
    idEntity::BecomeActive(this, flags: 1);
    if ( this->shadow != nullptr )
      this->dropShadowTrm = SetupDeferredDropShadowTraceModel(size: (float)(this->radius * (float)2.0), depth: 16.0);
  }
}


// ========================================================================
// __unwind$489692_0
// EA  : 0x82CF4A60
// RVA : 0x00CF4A60
// PDB : w:\tech5\tungsten\game\entities\tumbleweed.cpp
// ========================================================================

void _unwind_489692_0()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 1712 + 80), tag: TAG_CLIPMODEL);
}


// ========================================================================
// ?Think@idTumbleWeed@@UAAXXZ
// EA  : 0x82CF4A90
// RVA : 0x00CF4A90
// PDB : w:\tech5\tungsten\game\entities\tumbleweed.cpp
// ========================================================================

void __fastcall idTumbleWeed::Think(idTumbleWeed *this)
{
  long double v2; // fp2
  long double v3; // fp2
  double v4; // fp0
  double v5; // fp30
  long double v6; // fp2
  double v7; // fp31
  long double v8; // fp2
  double y; // fp3
  idVec3 *p_velocity; // r29
  idClipQuery *p_moveQuery; // r28
  double v12; // fp27
  idClientGame *v13; // r27
  unsigned __int64 v14; // r26
  unsigned __int64 index; // r11
  idPhysics *Physics; // r3
  float *v17; // r3
  double v18; // fp26
  double v19; // fp25
  double v20; // fp24
  double v21; // fp11
  double v22; // fp10
  double v23; // fp9
  double radius; // fp20
  double v27; // fp2
  double v28; // fp2
  const idMat3 *v29; // r3
  idPhysics *v30; // r3
  idPhysics *v31; // r3
  double v32; // fp9
  double v33; // fp13
  double v34; // fp7
  idPhysics *v35; // r3
  const idVec3 *v36; // r27
  idPhysics *v37; // r3
  double v38; // fp9
  double v39; // fp7
  idClipModel *v40; // r3
  const idClipModel *v41; // r9
  double v42; // fp11
  double z; // fp13
  double v44; // fp9
  idPhysics *v45; // r3
  double v46; // fp31
  float *v47; // r3
  double v48; // fp9
  idRecycledTraceModel *dropShadowTrm; // r5
  double v50; // fp5
  const idMaterial *shadow; // r8
  double v52; // fp1
  int v53; // r10
  int v54; // [sp+8h] [-258h]
  int v55; // [sp+Ch] [-254h]
  int v56; // [sp+10h] [-250h]
  const char *v57; // [sp+14h] [-24Ch]
  int v58; // [sp+18h] [-248h]
  const idMat3 *v59; // [sp+1Ch] [-244h]
  int v60; // [sp+20h] [-240h]
  int v61; // [sp+24h] [-23Ch]
  int v62; // [sp+28h] [-238h]
  int v63; // [sp+2Ch] [-234h]
  int v64; // [sp+30h] [-230h]
  idDeferredShadow *v65; // [sp+34h] [-22Ch]
  int v66; // [sp+38h] [-228h]
  const idMaterial *v67; // [sp+3Ch] [-224h]
  int v68; // [sp+40h] [-220h]
  int v69; // [sp+44h] [-21Ch]
  int v70; // [sp+48h] [-218h]
  int v71; // [sp+4Ch] [-214h]
  int v72; // [sp+50h] [-210h]
  int v73; // [sp+58h] [-208h]
  int v74; // [sp+60h] [-200h]
  int v75; // [sp+68h] [-1F8h]
  int v76; // [sp+70h] [-1F0h]
  int v77; // [sp+78h] [-1E8h]
  idVec3 v78; // [sp+80h] [-1E0h] BYREF
  __int64 v79; // [sp+90h] [-1D0h] BYREF
  idVec3 v80; // [sp+98h] [-1C8h] BYREF
  idVec3 v81; // [sp+A8h] [-1B8h] BYREF
  idRotation v82; // [sp+C0h] [-1A0h] BYREF
  trace_t v83; // [sp+110h] [-150h] BYREF
  idMat3 v84[4]; // [sp+190h] [-D0h] BYREF

  v79 = __PAIR64__(&unk_82390000, gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED));
  *(double *)&v2 = (float)((float)((float)((float)v79 * (float)0.001) * (float)3.1415927) * (float)0.047619049);
  v3 = sin(x: v2);
  v4 = (float)*(double *)&v3;
  v5 = 0.02;
  if ( v4 >= 0.02 )
  {
    if ( v4 <= 1.0 )
      v5 = (float)*(double *)&v3;
    else
      v5 = 1.0;
  }
  *(double *)&v3 = (float)((float)((float)(this->windOffset + (float)0.60000002) * 3.1415927)
                         + (float)((float)((float)((float)v79 * (float)0.001) * (float)3.1415927) * (float)0.2));
  v6 = sin(x: v3);
  v7 = (float)((float)*(double *)&v6 * (float)v5);
  *(double *)&v6 = (float)((float)((float)(this->windOffset + (float)0.2) * 3.1415927)
                         + (float)((float)((float)((float)v79 * (float)0.001) * (float)3.1415927) * (float)0.25));
  v8 = cos(x: v6);
  y = this->velocity.y;
  this->velocity.x = this->velocity.x + (float)v7;
  p_velocity = &this->velocity;
  this->velocity.z = 0.0;
  this->velocity.y = (float)y + (float)((float)*(double *)&v8 * (float)v5);
  idVec3::Truncate(this: &this->velocity, length: 80.0);
  v78.x = 0.0;
  HIDWORD(v14) = &ai_useTurnTransitions.valueString.baseBuffer[12];
  v78.y = 0.0;
  p_moveQuery = &this->moveQuery;
  v78.z = -1.0;
  v12 = 10.0;
  v13 = clientGame;
  LODWORD(v14) = 0;
  if ( (unsigned __int8)idClip::QueryIsValid(this: &clientGame->clip, clipQuery: &this->moveQuery) != 0 )
  {
    index = p_moveQuery->index;
    p_moveQuery->index = v14;
    idCollisionModelManager::GetContentsResult(
      this: collisionModelManager,
      result: &v83,
      query: &v13->clip.collisionQueries[index & 0xFFF].query,
      peek: false);
    Physics = idEntity::GetPhysics(this);
    v17 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
    v18 = (float)(v83.endpos.z - v17[2]);
    v19 = (float)(v83.endpos.x - *v17);
    v20 = (float)(v83.endpos.y - v17[1]);
    v82.origin.z = vec3_origin.z;
    v82.axisValid = false;
    v82.axis.mat[0].x = mat3_identity.mat[0].x;
    v82.axis.mat[0].z = mat3_identity.mat[0].z;
    v82.axis.mat[0].y = mat3_identity.mat[0].y;
    v82.axis.mat[1].x = mat3_identity.mat[1].x;
    v82.axis.mat[1].y = mat3_identity.mat[1].y;
    v21 = (float)((float)(v78.z * (float)v19) - (float)((float)v18 * v78.x));
    v82.axis.mat[1].z = mat3_identity.mat[1].z;
    v82.origin.x = vec3_origin.x;
    v22 = (float)((float)((float)v20 * v78.x) - (float)(v78.y * (float)v19));
    v23 = (float)((float)((float)v18 * v78.y) - (float)((float)v20 * v78.z));
    v82.axis.mat[2].x = mat3_identity.mat[2].x;
    v82.axis.mat[2].y = mat3_identity.mat[2].y;
    radius = this->radius;
    v82.origin.y = vec3_origin.y;
    v82.axis.mat[2].z = mat3_identity.mat[2].z;
    _FP5 = (float)((float)((float)((float)v23 * (float)v23)
                         + (float)((float)((float)v22 * (float)v22) + (float)((float)v21 * (float)v21)))
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm { fsel      f4, f5, f6, f13 }
    v27 = __frsqrte(_FP4);
    v28 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v27
                                                                                        * (float)((float)((float)((float)v23 * (float)v23) + (float)((float)((float)v22 * (float)v22) + (float)((float)v21 * (float)v21)))
                                                                                                * (float)0.5))
                                                                                * (float)v27)
                                                                        - (float)1.5)
                                                        * (float)v27)
                                                * (float)((float)((float)((float)v23 * (float)v23)
                                                                + (float)((float)((float)v22 * (float)v22)
                                                                        + (float)((float)v21 * (float)v21)))
                                                        * (float)0.5))
                                        * (float)((float)-(float)((float)((float)((float)v27
                                                                                * (float)((float)((float)((float)v23 * (float)v23)
                                                                                                + (float)((float)((float)v22 * (float)v22) + (float)((float)v21 * (float)v21)))
                                                                                        * (float)0.5))
                                                                        * (float)v27)
                                                                - (float)1.5)
                                                * (float)v27))
                                - (float)1.5)
                * (float)((float)-(float)((float)((float)((float)v27
                                                        * (float)((float)((float)((float)v23 * (float)v23)
                                                                        + (float)((float)((float)v22 * (float)v22)
                                                                                + (float)((float)v21 * (float)v21)))
                                                                * (float)0.5))
                                                * (float)v27)
                                        - (float)1.5)
                        * (float)v27));
    v82.vec.x = (float)v23
              * (float)((float)-(float)((float)((float)((float)v28
                                                      * (float)((float)((float)((float)v23 * (float)v23)
                                                                      + (float)((float)((float)v22 * (float)v22)
                                                                              + (float)((float)v21 * (float)v21)))
                                                              * (float)0.5))
                                              * (float)v28)
                                      - (float)1.5)
                      * (float)v28);
    v82.vec.y = (float)v21
              * (float)((float)-(float)((float)((float)((float)v28
                                                      * (float)((float)((float)((float)v23 * (float)v23)
                                                                      + (float)((float)((float)v22 * (float)v22)
                                                                              + (float)((float)v21 * (float)v21)))
                                                              * (float)0.5))
                                              * (float)v28)
                                      - (float)1.5)
                      * (float)v28);
    v82.vec.z = (float)v22
              * (float)((float)-(float)((float)((float)((float)v28
                                                      * (float)((float)((float)((float)v23 * (float)v23)
                                                                      + (float)((float)((float)v22 * (float)v22)
                                                                              + (float)((float)v21 * (float)v21)))
                                                              * (float)0.5))
                                              * (float)v28)
                                      - (float)1.5)
                      * (float)v28);
    v82.angle = (float)((float)((float)((float)-(float)((float)((float)((float)v28
                                                                      * (float)((float)((float)((float)v23 * (float)v23)
                                                                                      + (float)((float)((float)v22 * (float)v22)
                                                                                              + (float)((float)v21 * (float)v21)))
                                                                              * (float)0.5))
                                                              * (float)v28)
                                                      - (float)1.5)
                                      * (float)v28)
                              * (float)((float)((float)v23 * (float)v23)
                                      + (float)((float)((float)v22 * (float)v22) + (float)((float)v21 * (float)v21))))
                      / (float)radius)
              * idMath::M_RAD2DEG;
    v29 = idRotation::ToMat3(this: &v82);
    idMat3::operator*=(this: &this->modelAxis, a: v29);
    idMat3::OrthoNormalize(this: v84, result: &this->modelAxis);
    v30 = idEntity::GetPhysics(this);
    v30->SetOrigin(this: v30, a2: &v83.endpos, a3: -1);
    v31 = idEntity::GetPhysics(this);
    v31->SetAxis(this: v31, a2: &mat3_identity, a3: -1);
    if ( v83.fraction < 1.0 )
    {
      v32 = this->velocity.y;
      v33 = v83.c.normal.y;
      v34 = (float)((float)((float)(this->velocity.y * v83.c.normal.y) + (float)(p_velocity->x * v83.c.normal.x))
                  * (float)0.99000001);
      p_velocity->x = -(float)((float)(v83.c.normal.x
                                     * (float)((float)((float)(this->velocity.y * v83.c.normal.y)
                                                     + (float)(p_velocity->x * v83.c.normal.x))
                                             * (float)0.99000001))
                             - p_velocity->x);
      this->velocity.y = -(float)((float)((float)v33 * (float)v34) - (float)v32);
    }
    if ( (v83.c.flags & 4) == 0 )
      v12 = 1.0;
  }
  if ( (float)((float)(this->velocity.x * this->velocity.x) + (float)(this->velocity.y * this->velocity.y)) > 0.000099999997 )
  {
    v35 = idEntity::GetPhysics(this);
    v36 = v35->GetOrigin(this: v35, a2: 0);
    v37 = idEntity::GetPhysics(this);
    v38 = (float)(this->velocity.z + v36->z);
    v39 = (float)(v36->y + this->velocity.y);
    v81.x = p_velocity->x + v36->x;
    v81.z = v38;
    v81.y = v39;
    v40 = v37->GetClipModel(this: v37, a2: 0);
    p_moveQuery->index = *(unsigned __int64 *)&idClip::StepMove(
                                                 this: (idClip *)&v79,
                                                 result: &clientGame->clip,
                                                 a3: nullptr,
                                                 start: v36,
                                                 end: &v81,
                                                 downNormal: &v78,
                                                 stepUp: v12,
                                                 stepDown: 15.0,
                                                 clipModel: v41,
                                                 startAxis: (const idMat3 *)0x2000,
                                                 clipMask: v54,
                                                 passEntityNumber: v55,
                                                 moveClipModel: v56,
                                                 userName: v57,
                                                 a15: v58,
                                                 a16: (int)v59,
                                                 a17: v60,
                                                 a18: v61,
                                                 a19: v62,
                                                 a20: v63,
                                                 a21: v64,
                                                 a22: (int)v65,
                                                 a23: v66,
                                                 a24: (int)v67,
                                                 a25: v68,
                                                 a26: v69,
                                                 a27: v70,
                                                 a28: v71,
                                                 a29: v72,
                                                 a30: v40,
                                                 a31: v73,
                                                 a32: (int)&mat3_identity,
                                                 a33: v74,
                                                 a34: (const idBounds *)1,
                                                 a35: v75,
                                                 a36: (const idClipModel *)0x2000,
                                                 a37: v76,
                                                 clipModel_0_3: false,
                                                 a39: v77,
                                                 startAxis_0: (const idTraceModel **)"w:\\tech5\\tungsten\\game\\entities\\TumbleWeed."
                                                                        "cpp(238) : StepMove")->world;
  }
  v42 = this->velocity.y;
  z = this->velocity.z;
  v44 = (float)(p_velocity->x * (float)0.80000001);
  p_velocity->x = p_velocity->x * (float)0.80000001;
  this->velocity.y = (float)v42 * (float)0.80000001;
  this->velocity.z = (float)z * (float)0.80000001;
  if ( (float)((float)((float)((float)v42 * (float)0.80000001) * (float)((float)v42 * (float)0.80000001))
             + (float)((float)v44 * (float)v44)) < 0.000099999997 )
  {
    this->velocity.y = 0.0;
    p_velocity->x = 0.0;
  }
  if ( this->dropShadowTrm != nullptr )
  {
    v45 = idEntity::GetPhysics(this);
    v46 = this->radius;
    v47 = (float *)v45->GetOrigin(this: v45, a2: 0);
    v48 = (float)(this->center.z + v47[2]);
    dropShadowTrm = this->dropShadowTrm;
    v50 = (float)(this->center.y + v47[1]);
    v80.x = this->center.x + *v47;
    v80.y = v50;
    shadow = this->shadow;
    v52 = (float)(this->radius * (float)2.0);
    v80.z = (float)v48 - (float)v46;
    DeferredDropShadow(
      origin: &v80,
      axis: &mat3_identity,
      size: v52,
      depth: 16.0,
      trm: (const idTraceModel *)dropShadowTrm,
      material: (const idMaterial *)off_82010000,
      deferredShadow: (idDeferredShadow *)dropShadowTrm->trm,
      a8: shadow,
      a9: &this->deferredDropShadow.query,
      a10: v53,
      a11: v54,
      a12: v55,
      a13: v56,
      a14: (const idVec3 *)v57,
      a15: v58,
      a16: v59,
      a17: v60,
      a18: v61,
      a19: v62,
      a20: v63,
      a21: v64,
      a22: v65,
      a23: v66,
      a24: v67);
  }
  idEntity::UpdateVisuals(this);
}

