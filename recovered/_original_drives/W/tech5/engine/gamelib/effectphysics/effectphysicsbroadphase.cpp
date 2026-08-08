
// ========================================================================
// ?Init@idEffectPhysicsBroadPhase@@QAAXPAVidClip@@PAVidTraceModelCache@@@Z
// EA  : 0x827012C8
// RVA : 0x007012C8
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicsbroadphase.cpp
// ========================================================================

void __fastcall idEffectPhysicsBroadPhase::Init(idEffectPhysicsBroadPhase *this, idClip *clip, idTraceModelCache *tmc)
{
  this->clip = clip;
  this->traceModelCache = tmc;
}


// ========================================================================
// ?GetMotionResult@idEffectPhysicsBroadPhase@@QAA_NPAUtrace_t@@PAVidSPObject@@@Z
// EA  : 0x82701378
// RVA : 0x00701378
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicsbroadphase.cpp
// ========================================================================

BOOL __fastcall idEffectPhysicsBroadPhase::GetMotionResult(
        idEffectPhysicsBroadPhase *this,
        trace_t *result,
        idSPObject *object)
{
  BOOL ContentsResult; // r3
  BOOL v6; // r29

  ContentsResult = idCollisionModelManager::GetContentsResult(
                     this: collisionModelManager,
                     result,
                     query: &object->query,
                     peek: false);
  object->origin = result->endpos;
  v6 = ContentsResult;
  object->axis = result->endAxis;
  idMat3::OrthoNormalizeSelf(this: &object->axis);
  return v6;
}


// ========================================================================
// ?GetPositionedModels@idEffectPhysicsBroadPhase@@ABAHPBVidSPObject@@PAVidPositionedCollisionModel@@H@Z
// EA  : 0x82701528
// RVA : 0x00701528
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicsbroadphase.cpp
// ========================================================================

int __fastcall idEffectPhysicsBroadPhase::GetPositionedModels(
        idEffectPhysicsBroadPhase *this,
        const idSPObject *object,
        idPositionedCollisionModel *models,
        int maxModels)
{
  int v5; // r8
  int v6; // r30
  idCollisionQuery *p_modelQuery; // r11
  unsigned __int64 v8; // r10
  int v9; // r7

  if ( this->traceModelCache == nullptr )
    return 0;
  v5 = 0;
  v6 = 0;
  if ( object->overlap.num > 0 )
  {
    p_modelQuery = &models[-1].modelQuery;
    HIDWORD(v8) = 0;
    do
    {
      LODWORD(v8) = this->objects.list[*(__int16 *)((char *)object->overlap.list + HIDWORD(v8))];
      v9 = *(_DWORD *)(v8 + 4);
      if ( v9 != -1 && *(_BYTE *)(v8 + 78) == 0 )
      {
        ++v5;
        HIDWORD(p_modelQuery[1].offset) = this->traceModelCache->cache.list[v9]->collisionModel;
        *(float *)&p_modelQuery[2].offset = *(float *)(v8 + 16);
        *((float *)&p_modelQuery[2].offset + 1) = *(float *)(v8 + 20);
        *(float *)&p_modelQuery[3].offset = *(float *)(v8 + 24);
        *((float *)&p_modelQuery[3].offset + 1) = *(float *)(v8 + 28);
        *(float *)&p_modelQuery[4].offset = *(float *)(v8 + 32);
        *((float *)&p_modelQuery[4].offset + 1) = *(float *)(v8 + 36);
        *(float *)&p_modelQuery[5].offset = *(float *)(v8 + 40);
        *((float *)&p_modelQuery[5].offset + 1) = *(float *)(v8 + 44);
        *(float *)&p_modelQuery[6].offset = *(float *)(v8 + 48);
        *((float *)&p_modelQuery[6].offset + 1) = *(float *)(v8 + 52);
        *(float *)&p_modelQuery[7].offset = *(float *)(v8 + 56);
        *((float *)&p_modelQuery[7].offset + 1) = *(float *)(v8 + 60);
        HIDWORD(p_modelQuery[8].offset) = 0x1FFF;
        HIDWORD(p_modelQuery[9].offset) = *(__int16 *)((char *)object->overlap.list + HIDWORD(v8));
        LODWORD(p_modelQuery[9].offset) = 0;
        v8 = *(_QWORD *)(v8 + 112);
        p_modelQuery += 10;
        p_modelQuery->offset = v8;
        if ( v5 >= maxModels )
          break;
      }
      ++v6;
      HIDWORD(v8) += 2;
    }
    while ( v6 < object->overlap.num );
  }
  return v5;
}


// ========================================================================
// ?SubmitQueries@idEffectPhysicsBroadPhase@@QAAX_N@Z
// EA  : 0x82701658
// RVA : 0x00701658
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicsbroadphase.cpp
// ========================================================================

void __fastcall idEffectPhysicsBroadPhase::SubmitQueries(idEffectPhysicsBroadPhase *this, bool worldCollisionModelOnly)
{
  __int64 v2; // r22
  idClip *clip; // r9
  idCollisionModelManager *v4; // r11
  int i; // ctr
  BOOL v6; // r20
  int PositionedModelsInternal; // r29
  idClipModel *world; // r30
  float *p_z; // r31
  int v10; // r24
  idCollisionModel *collisionModel; // r3
  int v12; // r23
  int v13; // r24
  int v14; // r31
  const idVec3 *v15; // r28
  double v16; // fp6
  double v17; // fp0
  double v18; // fp9
  double v19; // fp5
  __int64 v20; // r9
  int v21; // [sp+8h] [-2978h]
  idPositionedCollisionModel *v22; // [sp+Ch] [-2974h]
  int v23; // [sp+10h] [-2970h]
  const idPositionedCollisionModel *v24; // [sp+14h] [-296Ch]
  int v25; // [sp+18h] [-2968h]
  const char *v26; // [sp+1Ch] [-2964h]
  int v27; // [sp+20h] [-2960h]
  int v28; // [sp+24h] [-295Ch]
  int v29; // [sp+28h] [-2958h]
  int v30; // [sp+2Ch] [-2954h]
  int v31; // [sp+30h] [-2950h]
  int v32; // [sp+34h] [-294Ch]
  int v33; // [sp+38h] [-2948h]
  int v34; // [sp+3Ch] [-2944h]
  int v35; // [sp+40h] [-2940h]
  int v36; // [sp+44h] [-293Ch]
  int v37; // [sp+48h] [-2938h]
  int v38; // [sp+4Ch] [-2934h]
  int v39; // [sp+50h] [-2930h]
  int v40; // [sp+58h] [-2928h]
  int v41; // [sp+60h] [-2920h]
  int v42; // [sp+68h] [-2918h]
  int v43; // [sp+70h] [-2910h]
  const idTraceModel *v44; // [sp+80h] [-2900h] BYREF
  idVec3 v45; // [sp+88h] [-28F8h] BYREF
  idRotation v46; // [sp+A0h] [-28E0h] BYREF
  idBounds v47; // [sp+F0h] [-2890h] BYREF
  idCollisionModelManager v48[8]; // [sp+108h] [-2878h] BYREF
  _QWORD v49[4]; // [sp+110h] [-2870h] BYREF

  HIDWORD(v2) = this;
  if ( this->traceModelCache != nullptr )
  {
    clip = this->clip;
    if ( this->clip != nullptr )
    {
      v4 = v48;
      LODWORD(v2) = 0;
      for ( i = 128; i != 0; --i )
      {
        v4 += 80;
        *(_QWORD *)v4 = v2;
      }
      v6 = worldCollisionModelOnly;
      PositionedModelsInternal = 0;
      if ( worldCollisionModelOnly )
      {
        world = clip->world;
        if ( idClipModel::GetNumCollisionModels(this: clip->world) > 0 )
        {
          p_z = &v47.b[1].z;
          v10 = 0;
          do
          {
            collisionModel = world->collisionModel;
            if ( collisionModel == nullptr )
            {
              if ( PositionedModelsInternal >= world->traceModels.num )
                collisionModel = idClipModel::NoTraceModelWarning(this: world);
              else
                collisionModel = world->clip->traceModelCache->cache.list[world->traceModels.list[v10]]->collisionModel;
            }
            *((_DWORD *)p_z + 3) = collisionModel;
            p_z[5] = world->origin.x;
            ++PositionedModelsInternal;
            p_z[6] = world->origin.y;
            ++v10;
            p_z[7] = world->origin.z;
            p_z[8] = world->axis.mat[0].x;
            p_z[9] = world->axis.mat[0].y;
            p_z[10] = world->axis.mat[0].z;
            p_z[11] = world->axis.mat[1].x;
            p_z[12] = world->axis.mat[1].y;
            p_z[13] = world->axis.mat[1].z;
            p_z[14] = world->axis.mat[2].x;
            p_z[15] = world->axis.mat[2].y;
            p_z[16] = world->axis.mat[2].z;
            p_z[17] = *(float *)&world->entityNumber;
            p_z[18] = *(float *)&world->physicsId;
            p_z[19] = *(float *)&world->bodyId;
            p_z += 20;
            *p_z = *(float *)&world->contents;
          }
          while ( PositionedModelsInternal < idClipModel::GetNumCollisionModels(this: world) );
        }
      }
      v12 = 0;
      if ( *(int *)(HIDWORD(v2) + 12) > 0 )
      {
        v13 = 0;
        do
        {
          v14 = *(_DWORD *)(v13 + *(_DWORD *)(HIDWORD(v2) + 8));
          if ( v14 != 0 && *(_BYTE *)(v14 + 76) != 0 )
          {
            v15 = *(const idVec3 **)(v14 + 12);
            v44 = **(const idTraceModel ***)(4 * *(_DWORD *)(v14 + 4) + *(_DWORD *)(*(_DWORD *)(HIDWORD(v2) + 4) + 52));
            idBoundsShort::ToBounds(this: (idBoundsShort *)&v47, result: (idBounds *)(v14 + 64));
            if ( !v6 )
              PositionedModelsInternal = idClip::GetPositionedModelsInternal(
                                           this: *(idClip **)HIDWORD(v2),
                                           v1: v47.b,
                                           v2: &v47.b[1],
                                           isLine: false,
                                           clipMask: (int)v15,
                                           passEntityNumber: *(_DWORD *)(v14 + 8),
                                           passOwnerNumber: 0x1FFF,
                                           physicsId: -1,
                                           bodyMask: v21,
                                           models: v22,
                                           maxModels: v23);
            if ( *(_BYTE *)(v14 + 77) == 0 )
              PositionedModelsInternal += idEffectPhysicsBroadPhase::GetPositionedModels(
                                            this: (idEffectPhysicsBroadPhase *)HIDWORD(v2),
                                            object: (const idSPObject *)v14,
                                            models: (idPositionedCollisionModel *)&v49[10 * PositionedModelsInternal],
                                            maxModels: 128 - PositionedModelsInternal);
            v16 = *(float *)(v14 + 104);
            v46.origin.x = *(float *)(v14 + 16);
            v46.origin.y = *(float *)(v14 + 20);
            v46.origin.z = *(float *)(v14 + 24);
            v46.vec.x = *(float *)(v14 + 92);
            v46.vec.y = *(float *)(v14 + 96);
            v17 = *(float *)(v14 + 100);
            v46.axisValid = false;
            v46.axis.mat[2].y = mat3_identity.mat[2].y;
            v46.vec.z = v17;
            v46.axis.mat[1].y = mat3_identity.mat[1].y;
            v46.axis.mat[2].z = mat3_identity.mat[2].z;
            v46.axis.mat[1].z = mat3_identity.mat[1].z;
            v46.angle = v16;
            v46.axis.mat[0].x = mat3_identity.mat[0].x;
            v46.axis.mat[0].y = mat3_identity.mat[0].y;
            v46.axis.mat[0].z = mat3_identity.mat[0].z;
            v46.axis.mat[1].x = mat3_identity.mat[1].x;
            v46.axis.mat[2].x = mat3_identity.mat[2].x;
            v18 = (float)(*(float *)(v14 + 80) + *(float *)(v14 + 16));
            v19 = (float)(*(float *)(v14 + 84) + *(float *)(v14 + 20));
            v45.z = *(float *)(v14 + 88) + *(float *)(v14 + 24);
            v45.x = v18;
            v45.y = v19;
            v20 = *(_QWORD *)idCollisionModelManager::Motion(
                               this: v48,
                               result: (idCollisionQuery *)collisionModelManager,
                               a3: nullptr,
                               start: (const idMat3 *)(v14 + 16),
                               end: &v45,
                               rotation: &v46,
                               globalBounds: &v47,
                               trms: &v44,
                               numTrms: v21,
                               trmAxis: (const idMat3 *)v22,
                               contentMask: v23,
                               models: v24,
                               numModels: v25,
                               userName: v26,
                               a15: v27,
                               a16: v28,
                               a17: v29,
                               a18: v30,
                               a19: v31,
                               a20: v32,
                               a21: v33,
                               a22: v34,
                               a23: v35,
                               a24: v36,
                               a25: v37,
                               a26: v38,
                               a27: v39,
                               a28: 1,
                               a29: v40,
                               a30: v14 + 28,
                               a31: v41,
                               a32: v15,
                               a33: v42,
                               a34: (int)v49,
                               a35: v43,
                               numTrmsa: PositionedModelsInternal);
            *(_BYTE *)(v14 + 76) = 0;
            *(_QWORD *)(v14 + 112) = v20;
          }
          ++v12;
          v13 += 4;
        }
        while ( v12 < *(_DWORD *)(HIDWORD(v2) + 12) );
      }
    }
  }
}


// ========================================================================
// ??0idEffectPhysicsBroadPhase@@QAA@XZ
// EA  : 0x82701BB0
// RVA : 0x00701BB0
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicsbroadphase.cpp
// ========================================================================

idEffectPhysicsBroadPhase *__fastcall idEffectPhysicsBroadPhase::idEffectPhysicsBroadPhase(
        idEffectPhysicsBroadPhase *this)
{
  this->objects.list = nullptr;
  this->objects.granularity = 0;
  this->objects.memTag = 59;
  this->objects.listStatic = 0;
  this->objects.size = 0;
  this->objects.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->objects);
  `eh vector constructor iterator'(
    ptr: this->markers,
    size: 0x10u,
    count: 3,
    pCtor: (void (__fastcall *)(void *))idList<breakableIsland_t,59>::idList<breakableIsland_t,59>,
    pDtor: (void (__fastcall *)(void *))idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>);
  this->clip = nullptr;
  this->traceModelCache = nullptr;
  return this;
}


// ========================================================================
// __unwind$247570_0
// EA  : 0x82701C24
// RVA : 0x00701C24
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicsbroadphase.cpp
// ========================================================================

void _unwind_247570_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 8));
}


// ========================================================================
// ??1idEffectPhysicsBroadPhase@@QAA@XZ
// EA  : 0x82701C58
// RVA : 0x00701C58
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicsbroadphase.cpp
// ========================================================================

void __fastcall idEffectPhysicsBroadPhase::~idEffectPhysicsBroadPhase(idEffectPhysicsBroadPhase *this)
{
  this->clip = nullptr;
  this->traceModelCache = nullptr;
  `eh vector destructor iterator'(
    ptr: this->markers,
    size: 0x10u,
    count: 3,
    pDtor: (void (__fastcall *)(void *))idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->objects);
}


// ========================================================================
// __unwind$247592
// EA  : 0x82701CBC
// RVA : 0x00701CBC
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicsbroadphase.cpp
// ========================================================================

void _unwind_247592()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 8));
}


// ========================================================================
// ?RemoveObject@idEffectPhysicsBroadPhase@@QAAXPAVidSPObject@@@Z
// EA  : 0x82701DB8
// RVA : 0x00701DB8
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicsbroadphase.cpp
// ========================================================================

void __fastcall idEffectPhysicsBroadPhase::RemoveObject(idEffectPhysicsBroadPhase *this, idSPObject *object)
{
  unsigned __int64 v2; // r25
  unsigned int offset; // r11
  char v6; // r11
  bool v7; // zf
  _DWORD *v8; // r22
  int *p_num; // r31
  int v10; // r26
  int v11; // r29
  int v12; // r30
  unsigned int v13; // r6
  int v14; // r9
  _WORD *v15; // r11
  idList<short,59> *v16; // r27
  int v17; // r11
  int v18; // r30
  unsigned int v19; // r5
  int v20; // r9
  int v21; // r11
  idList<short,59> *v22; // r29
  int v23; // r30
  int v24; // r11
  __int16 v25[56]; // [sp+50h] [-70h] BYREF

  LODWORD(v2) = 0;
  this->objects.list[object->id] = nullptr;
  offset = object->query.offset;
  if ( offset < (unsigned int)idCollisionQuery::finalResultsFirstSubmittedOffset
    || (v7 = offset < (unsigned int)idCollisionQuery::finalResultsLastSubmittedOffset, v6 = 1, !v7) )
  {
    v6 = 0;
  }
  if ( v6 != 0 )
    object->query.offset = v2;
  if ( !object->motion.worldCollisionOnly )
  {
    v8 = (_DWORD *)&object->query.offset + 1;
    p_num = &this->markers[0].num;
    do
    {
      v10 = v8[4];
      v11 = v8[1];
      if ( v11 < v10 - 1 )
      {
        v12 = 4 * v11;
        do
        {
          v13 = *(unsigned __int16 *)(*(p_num - 1) + v12 + 6);
          v14 = (4 * v13) & 0x1FFFC;
          (*(idSPObject **)((char *)this->objects.list + v14))->index[v13 >> 15][v2] = v11;
          v15 = (_WORD *)(*(p_num - 1) + v12);
          *v15 = v15[2];
          v15[1] = v15[3];
          if ( v13 >> 15 != 0 )
          {
            v16 = *(idList<short,59> **)((char *)this->objects.list + v14);
            v25[0] = (__int16)v16->list;
            idList<short,59>::RemoveFast(this: &object->overlap, obj: v25);
            v25[0] = object->id;
            idList<short,59>::RemoveFast(this: v16 + 9, obj: v25);
          }
          ++v11;
          v12 += 4;
        }
        while ( v11 < v10 - 1 );
      }
      v17 = *p_num;
      if ( v10 < *p_num - 1 )
      {
        v18 = 4 * v10;
        do
        {
          v19 = *(unsigned __int16 *)(*(p_num - 1) + v18 + 6);
          v20 = (4 * v19) & 0x1FFFC;
          (*(idSPObject **)((char *)this->objects.list + v20))->index[v19 >> 15][v2] = v10 - 1;
          v21 = *(p_num - 1) + v18;
          *(_WORD *)(v21 - 4) = *(_WORD *)(v21 + 4);
          *(_WORD *)(v21 - 2) = *(_WORD *)(v21 + 6);
          if ( v19 >> 15 != 0 )
          {
            v22 = *(idList<short,59> **)((char *)this->objects.list + v20);
            v25[0] = (__int16)v22->list;
            idList<short,59>::RemoveFast(this: &object->overlap, obj: v25);
            v25[0] = object->id;
            idList<short,59>::RemoveFast(this: v22 + 9, obj: v25);
          }
          v17 = *p_num;
          ++v10;
          v18 += 4;
        }
        while ( v10 < *p_num - 1 );
      }
      v23 = v17 - 2;
      if ( v17 - 2 <= p_num[1]
        || (unsigned __int8)idList<idEffectPhysicsBroadPhase::idSPMarker,59>::Resize(
                              this: (idList<cm_edge_t,5> *)(p_num - 1),
                              newsize: v17 - 2) != 0 )
      {
        v24 = p_num[1];
        if ( v23 < v24 )
          v24 = v23;
        *p_num = v24;
      }
      LODWORD(v2) = v2 + 1;
      *++v8 = -1;
      p_num += 4;
    }
    while ( (int)v2 < 3 );
  }
}


// ========================================================================
// ?AddObject@idEffectPhysicsBroadPhase@@QAAXPAVidSPObject@@ABVidVec3@@ABVidMat3@@PBVidBounds@@@Z
// EA  : 0x82702070
// RVA : 0x00702070
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicsbroadphase.cpp
// ========================================================================

void __fastcall idEffectPhysicsBroadPhase::AddObject(
        idEffectPhysicsBroadPhase *this,
        idSPObject *object,
        const idVec3 *origin,
        const idMat3 *axis,
        const idBounds *bounds,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        idSPObject *a14)
{
  idTraceModelCache *traceModelCache; // r11
  idTraceModel *trm; // r6
  int num; // r9
  idList<idSPObject *,59> *p_objects; // r24
  int v22; // r11
  int v23; // r10
  int v24; // r25
  idList<idEffectPhysicsBroadPhase::idSPMarker,59> *markers; // r29
  int *v26; // r21
  __int16 *v27; // r22
  int v28; // r23
  __int16 v29; // r20
  __int16 v30; // r19
  int v31; // r30
  unsigned int v32; // r5
  int v33; // r9
  idEffectPhysicsBroadPhase::idSPMarker *v34; // r10
  idEffectPhysicsBroadPhase::idSPMarker *v35; // r7
  int v36; // r31
  idList<unsigned short,5> *p_overlap; // r3
  int v38; // r9
  int v39; // r10
  signed __int16 v40; // r11
  int v41; // r7
  int v42; // r11
  idList<unsigned short,5> *v43; // r3
  int v44; // r9
  int v45; // r10
  signed __int16 id; // r11
  int v47; // r7
  int v48; // r11
  int v49; // r28
  int v50; // r30
  unsigned int data; // r6
  int v52; // r9
  idEffectPhysicsBroadPhase::idSPMarker *v53; // r11
  int v54; // r31
  idList<unsigned short,5> *v55; // r3
  int v56; // r9
  int v57; // r10
  signed __int16 v58; // r11
  int v59; // r7
  int v60; // r11
  idList<unsigned short,5> *v61; // r3
  int v62; // r9
  int v63; // r10
  signed __int16 v64; // r11
  int v65; // r7
  int v66; // r11
  int v67; // r3
  unsigned __int16 v68[8]; // [sp+50h] [-A0h] BYREF
  idBounds v69[6]; // [sp+60h] [-90h] BYREF

  a14 = object;
  if ( bounds != nullptr
    || (traceModelCache = this->traceModelCache) != nullptr
    && (trm = traceModelCache->cache.list[object->traceModelIndex]->trm,
        bounds = &trm->bounds,
        trm != (idTraceModel *)-1504) )
  {
    idBounds::FromTransformedBounds(this: v69, bounds, origin, axis);
    object->origin.x = origin->x;
    object->origin.y = origin->y;
    object->origin.z = origin->z;
    object->axis.mat[0].x = axis->mat[0].x;
    object->axis.mat[0].y = axis->mat[0].y;
    object->axis.mat[0].z = axis->mat[0].z;
    object->axis.mat[1].x = axis->mat[1].x;
    object->axis.mat[1].y = axis->mat[1].y;
    object->axis.mat[1].z = axis->mat[1].z;
    object->axis.mat[2].x = axis->mat[2].x;
    object->axis.mat[2].y = axis->mat[2].y;
    object->axis.mat[2].z = axis->mat[2].z;
    idBoundsShort::SetBounds(this: &object->absBounds, bounds: v69);
    num = this->objects.num;
    p_objects = &this->objects;
    v22 = 0;
    if ( num <= 0 )
    {
LABEL_8:
      v22 = -1;
    }
    else
    {
      v23 = 0;
      while ( p_objects->list[v23] != nullptr )
      {
        ++v22;
        ++v23;
        if ( v22 >= num )
          goto LABEL_8;
      }
    }
    object->id = v22;
    if ( v22 == -1 )
      object->id = idList<idAnimWebBlendTree *,5>::Append(
                     this: (idList<enum encounterGroupRole_t,5> *)&this->objects,
                     obj: (const encounterGroupRole_t *)&a14);
    else
      p_objects->list[v22] = object;
    if ( !object->motion.worldCollisionOnly )
    {
      v24 = 0;
      markers = this->markers;
      v26 = &object->index[0][2];
      v27 = object->absBounds.b[1];
      do
      {
        idList<idEffectPhysicsBroadPhase::idSPMarker,59>::Alloc(this: markers);
        idList<idEffectPhysicsBroadPhase::idSPMarker,59>::Alloc(this: markers);
        v28 = markers->num - 1;
        v29 = *(v27 - 3);
        v30 = *v27;
        if ( v28 > 1 )
        {
          v31 = v28;
          do
          {
            if ( v30 >= markers->list[v31 - 2].value )
              break;
            v32 = *((unsigned __int16 *)&markers->list[v31 - 1] - 1);
            v33 = (4 * v32) & 0x1FFFC;
            (*(idSPObject **)((char *)p_objects->list + v33))->index[v32 >> 15][v24] = v28;
            v34 = &markers->list[v31 - 2];
            v35 = &markers->list[v31];
            v35->value = v34->value;
            v35->data = v34->data;
            v36 = *(int *)((char *)p_objects->list + v33);
            if ( v32 >> 15 != 0 )
            {
              if ( (unsigned __int8)idBoundsShort::IntersectsBounds(
                                      this: &object->absBounds,
                                      a: (const idBoundsShort *)(v36 + 64)) != 0 )
              {
                p_overlap = (idList<unsigned short,5> *)&object->overlap;
                v38 = object->overlap.num;
                v39 = 0;
                v40 = *(_DWORD *)v36;
                v68[0] = v40;
                if ( v38 <= 0 )
                  goto LABEL_25;
                v41 = v40;
                v42 = 0;
                while ( (__int16)p_overlap->list[v42] != v41 )
                {
                  ++v39;
                  ++v42;
                  if ( v39 >= v38 )
                    goto LABEL_25;
                }
                if ( v39 < 0 )
LABEL_25:
                  idList<unsigned short,72>::Append(this: p_overlap, obj: v68);
                v43 = (idList<unsigned short,5> *)(v36 + 144);
                v44 = *(_DWORD *)(v36 + 148);
                v45 = 0;
                id = object->id;
                v68[0] = id;
                if ( v44 <= 0 )
                  goto LABEL_30;
                v47 = id;
                v48 = 0;
                while ( (__int16)v43->list[v48] != v47 )
                {
                  ++v45;
                  ++v48;
                  if ( v45 >= v44 )
                    goto LABEL_30;
                }
                if ( v45 < 0 )
LABEL_30:
                  idList<unsigned short,72>::Append(this: v43, obj: v68);
              }
            }
            else
            {
              v68[0] = *(_DWORD *)v36;
              idList<short,59>::RemoveFast(this: &object->overlap, obj: (const __int16 *)v68);
              v68[0] = object->id;
              idList<short,59>::RemoveFast(this: (idList<short,59> *)(v36 + 144), obj: (const __int16 *)v68);
            }
            --v28;
            --v31;
          }
          while ( v28 > 1 );
        }
        v49 = v28 - 1;
        if ( v28 - 1 > 0 )
        {
          v50 = v49;
          do
          {
            if ( v29 >= markers->list[v50 - 1].value )
              break;
            data = markers->list[v50 - 1].data;
            v52 = (4 * data) & 0x1FFFC;
            (*(idSPObject **)((char *)p_objects->list + v52))->index[data >> 15][v24] = v49;
            v53 = &markers->list[v50];
            v53->value = v53[-1].value;
            v53->data = v53[-1].data;
            if ( data >> 15 != 0 )
            {
              v54 = *(int *)((char *)p_objects->list + v52);
              if ( (unsigned __int8)idBoundsShort::IntersectsBounds(
                                      this: &object->absBounds,
                                      a: (const idBoundsShort *)(v54 + 64)) != 0 )
              {
                v55 = (idList<unsigned short,5> *)&object->overlap;
                v56 = object->overlap.num;
                v57 = 0;
                v58 = *(_DWORD *)v54;
                v68[0] = v58;
                if ( v56 <= 0 )
                  goto LABEL_46;
                v59 = v58;
                v60 = 0;
                while ( (__int16)v55->list[v60] != v59 )
                {
                  ++v57;
                  ++v60;
                  if ( v57 >= v56 )
                    goto LABEL_46;
                }
                if ( v57 < 0 )
LABEL_46:
                  idList<unsigned short,72>::Append(this: v55, obj: v68);
                v61 = (idList<unsigned short,5> *)(v54 + 144);
                v62 = *(_DWORD *)(v54 + 148);
                v63 = 0;
                v64 = object->id;
                v68[0] = v64;
                if ( v62 <= 0 )
                  goto LABEL_53;
                v65 = v64;
                v66 = 0;
                while ( (__int16)v61->list[v66] != v65 )
                {
                  ++v63;
                  ++v66;
                  if ( v63 >= v62 )
                    goto LABEL_53;
                }
                if ( v63 < 0 )
LABEL_53:
                  idList<unsigned short,72>::Append(this: v61, obj: v68);
              }
            }
            --v49;
            --v50;
          }
          while ( v49 > 0 );
        }
        *(v26 - 2) = v49;
        *++v26 = v28;
        ++v24;
        markers->list[v49].value = v29;
        ++v27;
        markers->list[v49].data = object->id;
        markers->list[v28].value = v30;
        v67 = (int)&markers->list[v28];
        ++markers;
        *(_WORD *)(v67 + 2) = object->id | 0x8000;
      }
      while ( v24 < 3 );
    }
  }
}


// ========================================================================
// ?MoveObject@idEffectPhysicsBroadPhase@@AAAXPAVidSPObject@@@Z
// EA  : 0x82702568
// RVA : 0x00702568
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicsbroadphase.cpp
// ========================================================================

void __fastcall idEffectPhysicsBroadPhase::MoveObject(idEffectPhysicsBroadPhase *this, idSPObject *object)
{
  int v4; // r24
  int *v5; // r19
  idList<idEffectPhysicsBroadPhase::idSPMarker,59> *markers; // r28
  __int16 *v7; // r18
  int v8; // r22
  int v9; // r23
  __int16 v10; // r21
  int v11; // r30
  __int16 v12; // r20
  int v13; // r29
  unsigned int data; // r6
  int v15; // r9
  idEffectPhysicsBroadPhase::idSPMarker *v16; // r11
  idEffectPhysicsBroadPhase::idSPMarker v17; // r7
  int v18; // r31
  char v19; // r11
  idList<unsigned short,5> *p_overlap; // r3
  int num; // r9
  int v22; // r10
  signed __int16 v23; // r11
  int v24; // r7
  int v25; // r11
  idList<unsigned short,5> *v26; // r3
  int v27; // r9
  int v28; // r10
  signed __int16 id; // r11
  int v30; // r7
  int v31; // r11
  unsigned int v32; // r6
  int v33; // r9
  idEffectPhysicsBroadPhase::idSPMarker *v34; // r11
  idEffectPhysicsBroadPhase::idSPMarker v35; // r5
  int v36; // r31
  char v37; // r11
  idList<unsigned short,5> *v38; // r3
  int v39; // r9
  int v40; // r10
  signed __int16 v41; // r11
  int v42; // r7
  int v43; // r11
  idList<unsigned short,5> *v44; // r3
  int v45; // r9
  int v46; // r10
  signed __int16 v47; // r11
  int v48; // r7
  int v49; // r11
  idEffectPhysicsBroadPhase::idSPMarker *list; // r11
  int i; // r10
  unsigned int v52; // r5
  int v53; // r8
  idEffectPhysicsBroadPhase::idSPMarker *v54; // r11
  idEffectPhysicsBroadPhase::idSPMarker v55; // r6
  idList<short,59> *v56; // r31
  int v57; // r10
  unsigned int v58; // r5
  int v59; // r8
  idEffectPhysicsBroadPhase::idSPMarker *v60; // r11
  idEffectPhysicsBroadPhase::idSPMarker v61; // r3
  idList<short,59> *v62; // r31
  unsigned __int16 v63[64]; // [sp+50h] [-80h] BYREF

  v4 = 0;
  v5 = &object->index[0][2];
  markers = this->markers;
  v7 = object->absBounds.b[1];
  do
  {
    v8 = *(v5 - 2);
    v9 = v5[1];
    v10 = *(v7 - 3);
    v11 = v9;
    v12 = *v7;
    markers->list[v8].value = v10;
    markers->list[v9].value = v12;
    if ( v8 > 0 )
    {
      v13 = v8;
      do
      {
        if ( v10 >= markers->list[v13 - 1].value )
          break;
        data = markers->list[v13 - 1].data;
        v15 = (4 * data) & 0x1FFFC;
        (*(idSPObject **)((char *)this->objects.list + v15))->index[data >> 15][v4] = v8;
        v16 = &markers->list[v13];
        v17 = *v16;
        v16->value = v16[-1].value;
        v16->data = v16[-1].data;
        v16[-1] = v17;
        if ( data >> 15 != 0 )
        {
          v18 = *(int *)((char *)this->objects.list + v15);
          if ( object->absBounds.b[0][0] > *(__int16 *)(v18 + 70)
            || object->absBounds.b[0][1] > *(__int16 *)(v18 + 72)
            || object->absBounds.b[0][2] > *(__int16 *)(v18 + 74)
            || *(__int16 *)(v18 + 64) > object->absBounds.b[1][0]
            || *(__int16 *)(v18 + 66) > object->absBounds.b[1][1]
            || (v19 = 1, *(__int16 *)(v18 + 68) > object->absBounds.b[1][2]) )
          {
            v19 = 0;
          }
          if ( v19 != 0 )
          {
            p_overlap = (idList<unsigned short,5> *)&object->overlap;
            num = object->overlap.num;
            v22 = 0;
            v23 = *(_DWORD *)v18;
            v63[0] = v23;
            if ( num <= 0 )
              goto LABEL_20;
            v24 = v23;
            v25 = 0;
            while ( (__int16)p_overlap->list[v25] != v24 )
            {
              ++v22;
              ++v25;
              if ( v22 >= num )
                goto LABEL_20;
            }
            if ( v22 < 0 )
LABEL_20:
              idList<unsigned short,72>::Append(this: p_overlap, obj: v63);
            v26 = (idList<unsigned short,5> *)(v18 + 144);
            v27 = *(_DWORD *)(v18 + 148);
            v28 = 0;
            id = object->id;
            v63[0] = id;
            if ( v27 <= 0 )
              goto LABEL_27;
            v30 = id;
            v31 = 0;
            while ( (__int16)v26->list[v31] != v30 )
            {
              ++v28;
              ++v31;
              if ( v28 >= v27 )
                goto LABEL_27;
            }
            if ( v28 < 0 )
LABEL_27:
              idList<unsigned short,72>::Append(this: v26, obj: v63);
          }
        }
        --v8;
        --v13;
      }
      while ( v8 > 0 );
    }
    for ( ; v9 < markers->num - 1; ++v11 )
    {
      if ( v12 <= markers->list[v11 + 1].value )
        break;
      v32 = markers->list[v11 + 1].data;
      v33 = (4 * v32) & 0x1FFFC;
      (*(idSPObject **)((char *)this->objects.list + v33))->index[v32 >> 15][v4] = v9;
      v34 = &markers->list[v11];
      v35 = *v34;
      v34->value = v34[1].value;
      v34->data = v34[1].data;
      v34[1] = v35;
      if ( (~(_WORD)v32 & 0x8000) != 0 )
      {
        v36 = *(int *)((char *)this->objects.list + v33);
        if ( object->absBounds.b[0][0] > *(__int16 *)(v36 + 70)
          || object->absBounds.b[0][1] > *(__int16 *)(v36 + 72)
          || object->absBounds.b[0][2] > *(__int16 *)(v36 + 74)
          || *(__int16 *)(v36 + 64) > object->absBounds.b[1][0]
          || *(__int16 *)(v36 + 66) > object->absBounds.b[1][1]
          || (v37 = 1, *(__int16 *)(v36 + 68) > object->absBounds.b[1][2]) )
        {
          v37 = 0;
        }
        if ( v37 != 0 )
        {
          v38 = (idList<unsigned short,5> *)&object->overlap;
          v39 = object->overlap.num;
          v40 = 0;
          v41 = *(_DWORD *)v36;
          v63[0] = v41;
          if ( v39 <= 0 )
            goto LABEL_46;
          v42 = v41;
          v43 = 0;
          while ( (__int16)v38->list[v43] != v42 )
          {
            ++v40;
            ++v43;
            if ( v40 >= v39 )
              goto LABEL_46;
          }
          if ( v40 < 0 )
LABEL_46:
            idList<unsigned short,72>::Append(this: v38, obj: v63);
          v44 = (idList<unsigned short,5> *)(v36 + 144);
          v45 = *(_DWORD *)(v36 + 148);
          v46 = 0;
          v47 = object->id;
          v63[0] = v47;
          if ( v45 <= 0 )
            goto LABEL_53;
          v48 = v47;
          v49 = 0;
          while ( (__int16)v44->list[v49] != v48 )
          {
            ++v46;
            ++v49;
            if ( v46 >= v45 )
              goto LABEL_53;
          }
          if ( v46 < 0 )
LABEL_53:
            idList<unsigned short,72>::Append(this: v44, obj: v63);
        }
      }
      ++v9;
    }
    list = markers->list;
    for ( i = v8; v10 > markers->list[v8 + 1].value; i = v8 )
    {
      v52 = markers->list[i + 1].data;
      v53 = (4 * v52) & 0x1FFFC;
      (*(idSPObject **)((char *)this->objects.list + v53))->index[v52 >> 15][v4] = v8;
      v54 = &markers->list[i];
      v55 = *v54;
      v54->value = v54[1].value;
      v54->data = v54[1].data;
      v54[1] = v55;
      if ( v52 >> 15 != 0 )
      {
        v56 = *(idList<short,59> **)((char *)this->objects.list + v53);
        v63[0] = (unsigned __int16)v56->list;
        idList<short,59>::RemoveFast(this: &object->overlap, obj: (const __int16 *)v63);
        v63[0] = object->id;
        idList<short,59>::RemoveFast(this: v56 + 9, obj: (const __int16 *)v63);
      }
      ++v8;
      list = markers->list;
    }
    v57 = v9;
    if ( v12 < list[v9 - 1].value )
    {
      do
      {
        v58 = markers->list[v57 - 1].data;
        v59 = (4 * v58) & 0x1FFFC;
        (*(idSPObject **)((char *)this->objects.list + v59))->index[v58 >> 15][v4] = v9;
        v60 = &markers->list[v57];
        v61 = *v60;
        v60->value = v60[-1].value;
        v60->data = v60[-1].data;
        v60[-1] = v61;
        if ( (~(_WORD)v58 & 0x8000) != 0 )
        {
          v62 = *(idList<short,59> **)((char *)this->objects.list + v59);
          v63[0] = (unsigned __int16)v62->list;
          idList<short,59>::RemoveFast(this: &object->overlap, obj: (const __int16 *)v63);
          v63[0] = object->id;
          idList<short,59>::RemoveFast(this: v62 + 9, obj: (const __int16 *)v63);
        }
        v57 = --v9;
      }
      while ( v12 < markers->list[v9 - 1].value );
    }
    ++v4;
    *(v5 - 2) = v8;
    *++v5 = v9;
    ++v7;
    ++markers;
  }
  while ( v4 < 3 );
}


// ========================================================================
// ?SetObjectPosition@idEffectPhysicsBroadPhase@@QAAXPAVidSPObject@@ABVidVec3@@ABVidMat3@@PBVidBounds@@@Z
// EA  : 0x82702B98
// RVA : 0x00702B98
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicsbroadphase.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idEffectPhysicsBroadPhase::SetObjectPosition(
        idEffectPhysicsBroadPhase *this,
        idSPObject *object,
        const idVec3 *origin,
        const idMat3 *axis,
        const idBounds *bounds)
{
  idTraceModelCache *traceModelCache; // r11
  idTraceModel *trm; // r6
  unsigned int offset; // r11
  unsigned __int64 v12; // r9 OVERLAPPED
  char v13; // r11
  bool v14; // zf
  idBounds v15[2]; // [sp+50h] [-40h] BYREF

  if ( bounds != nullptr
    || (traceModelCache = this->traceModelCache) != nullptr
    && (trm = traceModelCache->cache.list[object->traceModelIndex]->trm,
        bounds = &trm->bounds,
        trm != (idTraceModel *)-1504) )
  {
    idBounds::FromTransformedBounds(this: v15, bounds, origin, axis);
    idBoundsShort::SetBounds(this: &object->absBounds, bounds: v15);
    object->origin.x = origin->x;
    object->origin.y = origin->y;
    object->origin.z = origin->z;
    object->axis.mat[0].x = axis->mat[0].x;
    object->axis.mat[0].y = axis->mat[0].y;
    object->axis.mat[0].z = axis->mat[0].z;
    object->axis.mat[1].x = axis->mat[1].x;
    object->axis.mat[1].y = axis->mat[1].y;
    object->axis.mat[1].z = axis->mat[1].z;
    object->axis.mat[2].x = axis->mat[2].x;
    object->axis.mat[2].y = axis->mat[2].y;
    object->axis.mat[2].z = axis->mat[2].z;
    if ( !object->motion.worldCollisionOnly )
      idEffectPhysicsBroadPhase::MoveObject(this, object);
    object->motion.valid = false;
    *(unsigned __int64 *)((char *)&v12 + 4) = object->query.offset;
    offset = object->query.offset;
    LODWORD(v12) = HIDWORD(idCollisionQuery::finalResultsFirstSubmittedOffset);
    if ( offset < (unsigned int)idCollisionQuery::finalResultsFirstSubmittedOffset
      || (LODWORD(v12) = HIDWORD(idCollisionQuery::finalResultsLastSubmittedOffset),
          v14 = offset < (unsigned int)idCollisionQuery::finalResultsLastSubmittedOffset,
          v13 = 1,
          !v14) )
    {
      v13 = v12;
    }
    if ( v13 != 0 )
      object->query.offset = v12;
  }
}


// ========================================================================
// ?ApplyMotion@idEffectPhysicsBroadPhase@@QAAXPAVidSPObject@@ABVidVec3@@ABVidRotation@@@Z
// EA  : 0x82702CD8
// RVA : 0x00702CD8
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicsbroadphase.cpp
// ========================================================================

void __fastcall idEffectPhysicsBroadPhase::ApplyMotion(
        idEffectPhysicsBroadPhase *this,
        idSPObject *object,
        const idVec3 *translation,
        const idRotation *rotation,
        const char *a5)
{
  unsigned __int64 v9; // r6
  idTraceModelCache *traceModelCache; // r11
  double v12; // fp12
  double x; // fp11
  double y; // fp0
  double v15; // fp11
  double v16; // fp12
  double z; // fp0
  double v18; // fp11
  double v19; // fp12
  idPLog *pLog; // r29
  idPLog::logEntry_t *v33; // r30
  int v34; // r3
  __int64 totalTicks; // r11
  __int64 v36; // r9
  idPLogScope v37; // [sp+58h] [-68h] BYREF
  idBounds v38[4]; // [sp+60h] [-60h] BYREF

  LODWORD(v9) = "idEffectPhysicsBroadPhase::Motion";
  HIDWORD(v9) = 1;
  idPLogScope::idPLogScope(this: &v37, pl: &::pLog, gMask: v9, label: a5);
  traceModelCache = this->traceModelCache;
  if ( traceModelCache != nullptr )
  {
    idBounds::FromBoundsRotation(
      this: v38,
      bounds: &traceModelCache->cache.list[object->traceModelIndex]->trm->bounds,
      boundsOrigin: &object->origin,
      boundsAxis: &object->axis,
      rotation);
    if ( translation->x >= 0.0 )
    {
      x = v38[0].b[0].x;
      v12 = (float)(v38[0].b[1].x + translation->x);
    }
    else
    {
      v12 = v38[0].b[1].x;
      x = (float)(v38[0].b[0].x + translation->x);
    }
    y = translation->y;
    v38[0].b[0].x = (float)x - (float)1.0;
    v15 = v38[0].b[0].y;
    v38[0].b[1].x = (float)v12 + (float)1.0;
    v16 = v38[0].b[1].y;
    if ( y >= 0.0 )
      v16 = (float)(v38[0].b[1].y + (float)y);
    else
      v15 = (float)(v38[0].b[0].y + (float)y);
    z = translation->z;
    v38[0].b[0].y = (float)v15 - (float)1.0;
    v18 = v38[0].b[0].z;
    v38[0].b[1].y = (float)v16 + (float)1.0;
    v19 = v38[0].b[1].z;
    if ( z >= 0.0 )
      v19 = (float)(v38[0].b[1].z + (float)z);
    else
      v18 = (float)(v38[0].b[0].z + (float)z);
    _R11 = v38;
    _R9 = 16;
    _R8 = v38;
    v38[0].b[0].z = (float)v18 - (float)1.0;
    v38[0].b[1].z = (float)v19 + (float)1.0;
    _R10 = 8;
    _R7 = v38;
    __asm { vspltisw128 v62, 0 }
    _R6 = 24;
    __asm { lvrx128   v61, r9, r11 }
    _R5 = v38;
    __asm { lvlx128   v60, r0, r8 }
    _R11 = &idBoundsShort::vector_float_max_ushort;
    __asm { lvrx128   v59, r6, r7 }
    _R9 = idBoundsShort::vector_int_max_ushort;
    __asm
    {
      lvlx128   v58, r10, r5
      vor128    v57, v90, v59
      vor128    v56, v92, v61
      vsldoi128 v55, v89, v62, 4
      lvx128    v63, r0, r11
    }
    __asm { lvx128    v0, r0, r9 }
    _R11 = &object->absBounds;
    _R7 = idBoundsShort::vector_int_zero;
    __asm
    {
      vsubfp128 v54, v87, v63
      vrlimi128 v56, v62, 1, 0
    }
    _R6 = 4;
    __asm
    {
      vaddfp128 v53, v88, v63
      lvx128    v63, r0, r7
      vcfpsxws128 v13, v54, 0
      vcfpsxws128 v12, v53, 0
      vaddsws   v11, v13, v0
      vsubsws   v10, v12, v0
      vpkswss128 v52, v11, v63
      vpkswss128 v51, v10, v63
      vsldoi128 v50, v94, v52, 0xA
      vor128    v49, v83, v50
      vspltw128 v48, v49, 0
      vspltw128 v47, v49, 1
      vspltw128 v46, v49, 2
      stvewx128 v48, r0, r11
      stvewx128 v47, r11, r6
      stvewx128 v46, r11, r10
    }
    if ( !object->motion.worldCollisionOnly )
      idEffectPhysicsBroadPhase::MoveObject(this, object);
    object->motion.valid = true;
    object->motion.translation.x = translation->x;
    object->motion.translation.y = translation->y;
    object->motion.translation.z = translation->z;
    object->motion.rotationVec.x = rotation->vec.x;
    object->motion.rotationVec.y = rotation->vec.y;
    object->motion.rotationVec.z = rotation->vec.z;
    object->motion.rotationAngle = rotation->angle;
    if ( v37.logIndex >= 0 )
    {
      pLog = v37.pLog;
      v33 = &v37.pLog->logEntries.list[v37.logIndex];
      v34 = (unsigned __int64)Sys_GetClockTicks() >> 32;
      totalTicks = v33->totalTicks;
      HIDWORD(totalTicks) = v33->parent;
      LODWORD(v36) = v34 - totalTicks;
      v33->totalTicks = v36;
      pLog->lastEntry = HIDWORD(totalTicks);
    }
  }
  else
  {
    idPLogScope::~idPLogScope(this: &v37);
  }
}


// ========================================================================
// __unwind$248620
// EA  : 0x82702F70
// RVA : 0x00702F70
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicsbroadphase.cpp
// ========================================================================

void _unwind_248620()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 192 + 88));
}

