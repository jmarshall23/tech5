
// ========================================================================
// ?SubmitCollisionQueries@idEffectPhysicsCuttable@@QAAXXZ
// EA  : 0x82702F98
// RVA : 0x00702F98
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicscuttable.cpp
// ========================================================================

void __fastcall idEffectPhysicsCuttable::SubmitCollisionQueries(idEffectPhysicsCuttable *this)
{
  idEffectPhysicsBroadPhase::SubmitQueries(this: &this->broadPhase, worldCollisionModelOnly: false);
}


// ========================================================================
// ?UpdateModel@idEffectPhysicsCuttable@@QAAXABVidVec3@@H@Z
// EA  : 0x82703100
// RVA : 0x00703100
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicscuttable.cpp
// ========================================================================

void __fastcall idEffectPhysicsCuttable::UpdateModel(
        idEffectPhysicsCuttable *this,
        const idVec3 *scale,
        int currentTime,
        int a4,
        __int64 a5)
{
  int v7; // r27
  double v8; // fp27
  int v9; // r28
  idEffectPhysicsCuttable::piece_t *v10; // r31
  int renderModelIndex; // r11
  idRenderModelCuttableDynamic **list; // r10
  idRenderModel *v13; // r30
  idEffectPhysicsRigidBody *rigidBody; // r11
  char *v15; // r9
  idEffectPhysicsRigidBody *p_z; // r10
  int v17; // ctr
  double v18; // fp31
  double v19; // fp30
  double v20; // fp29
  __int64 v21; // r8
  int firstCollisionTime; // r11
  int v23; // r11
  char v26; // [sp+5Ch] [-94h] BYREF
  idMat3 v27[2]; // [sp+60h] [-90h] BYREF

  LODWORD(a5) = this->pieceFadeTime;
  v7 = 0;
  v8 = (float)((float)1.0 / (float)a5);
  if ( this->pieces.num > 0 )
  {
    v9 = 0;
    do
    {
      v10 = &this->pieces.list[v9];
      renderModelIndex = v10->renderModelIndex;
      if ( renderModelIndex >= 0 )
      {
        list = this->models.list;
        v13 = list[renderModelIndex];
        if ( v13 != nullptr && idRenderModelCuttableDynamic::IsValid(this: list[renderModelIndex]) )
        {
          rigidBody = v10->rigidBody;
          if ( v10->timeStamp != 0 && rigidBody->active )
          {
            v15 = &v26;
            p_z = (idEffectPhysicsRigidBody *)&rigidBody->currentState.position.z;
            v17 = 9;
            v18 = (float)(rigidBody->currentState.position.x
                        + (float)((float)(rigidBody->currentState.orientation.mat[0].x * v10->position.x)
                                + (float)((float)(rigidBody->currentState.orientation.mat[1].x * v10->position.y)
                                        + (float)(rigidBody->currentState.orientation.mat[2].x * v10->position.z))));
            v19 = (float)(rigidBody->currentState.position.y
                        + (float)((float)(rigidBody->currentState.orientation.mat[2].y * v10->position.z)
                                + (float)((float)(rigidBody->currentState.orientation.mat[0].y * v10->position.x)
                                        + (float)(rigidBody->currentState.orientation.mat[1].y * v10->position.y))));
            v20 = (float)(rigidBody->currentState.position.z
                        + (float)((float)(rigidBody->currentState.orientation.mat[2].z * v10->position.z)
                                + (float)((float)(rigidBody->currentState.orientation.mat[0].z * v10->position.x)
                                        + (float)(rigidBody->currentState.orientation.mat[1].z * v10->position.y))));
            do
            {
              p_z = (idEffectPhysicsRigidBody *)((char *)p_z + 4);
              v15 += 4;
              *(_DWORD *)v15 = p_z->properties;
              --v17;
            }
            while ( v17 != 0 );
            idRenderModel::SetAxis(this: v13, a: v27);
            if ( !v13->deferredPositionInitialized || !v13->useDeferredPosition )
            {
              v13->g.origin.x = v18;
              v13->g.origin.y = v19;
              v13->g.origin.z = v20;
            }
            v13->deferredOrigin.x = v18;
            v13->deferredOrigin.y = v19;
            v13->deferredOrigin.z = v20;
            firstCollisionTime = v10->firstCollisionTime;
            if ( firstCollisionTime != 0 )
            {
              v23 = currentTime - this->pieceLifeTime - firstCollisionTime;
              if ( v23 > 0 )
              {
                LODWORD(v21) = this->pieceFadeTime - v23;
                _FP10 = -(float)((float)v21 * (float)v8);
                __asm { fsel      f1, f10, f28, f11# v }
                idRenderModel::SetModelFade(this: v13, v: _FP1);
              }
            }
            idRenderModel::CommitThisFrame(this: v13);
          }
        }
      }
      ++v7;
      ++v9;
    }
    while ( v7 < this->pieces.num );
  }
}


// ========================================================================
// ?DrawCollisionModels@idEffectPhysicsCuttable@@QAAXH@Z
// EA  : 0x827032F0
// RVA : 0x007032F0
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicscuttable.cpp
// ========================================================================

void __fastcall idEffectPhysicsCuttable::DrawCollisionModels(idEffectPhysicsCuttable *this, int single)
{
  int v4; // r26
  int v5; // r30
  idEffectPhysicsCuttable::piece_t *v6; // r11
  int timeStamp; // r10
  idEffectPhysicsRigidBody *rigidBody; // r11
  float y; // r5
  idEffectPhysicsRigidBody *p_z; // r10
  float z; // r4
  int *v12; // r11
  int traceModelIndex; // r8
  int v14; // ctr
  int v15; // [sp+8h] [-E8h]
  int v16; // [sp+Ch] [-E4h]
  int v17; // [sp+10h] [-E0h]
  int v18; // [sp+14h] [-DCh]
  int v19; // [sp+18h] [-D8h]
  int v20; // [sp+1Ch] [-D4h]
  int v21; // [sp+20h] [-D0h]
  int v22; // [sp+24h] [-CCh]
  int v23; // [sp+28h] [-C8h]
  int v24; // [sp+2Ch] [-C4h]
  int v25; // [sp+30h] [-C0h]
  int v26; // [sp+34h] [-BCh]
  int v27; // [sp+38h] [-B8h]
  int v28; // [sp+3Ch] [-B4h]
  int v29; // [sp+40h] [-B0h]
  int v30; // [sp+44h] [-ACh]
  int v31; // [sp+48h] [-A8h]
  int v32; // [sp+4Ch] [-A4h]
  int v33; // [sp+50h] [-A0h]
  idVec3 v34; // [sp+60h] [-90h] BYREF
  int v35; // [sp+6Ch] [-84h] BYREF
  idMat3 v36; // [sp+70h] [-80h] BYREF

  v4 = 0;
  if ( this->pieces.num > 0 )
  {
    v5 = 0;
    do
    {
      if ( single < 0 || v4 == single )
      {
        v6 = &this->pieces.list[v5];
        timeStamp = v6->timeStamp;
        rigidBody = v6->rigidBody;
        if ( timeStamp != 0 && rigidBody->active )
        {
          y = rigidBody->currentState.position.y;
          p_z = (idEffectPhysicsRigidBody *)&rigidBody->currentState.position.z;
          z = rigidBody->currentState.position.z;
          traceModelIndex = rigidBody->properties->traceModelIndex;
          v14 = 9;
          v34.x = rigidBody->currentState.position.x;
          v12 = &v35;
          v34.y = y;
          v34.z = z;
          do
          {
            p_z = (idEffectPhysicsRigidBody *)((char *)p_z + 4);
            *++v12 = (int)p_z->properties;
            --v14;
          }
          while ( v14 != 0 );
          idCollisionModelManager::DrawCollisionModel(
            this: collisionModelManager,
            model: this->broadPhase.traceModelCache->cache.list[traceModelIndex]->collisionModel,
            modelJoints: nullptr,
            modelOrigin: &v34,
            modelAxis: &v36,
            viewOrigin: &vec3_origin,
            viewAxis: &mat3_identity,
            radius: 0.0,
            lifeTime: 4 * traceModelIndex,
            a10: v15,
            a11: v16,
            a12: v17,
            a13: v18,
            a14: v19,
            a15: v20,
            a16: v21,
            a17: v22,
            a18: v23,
            a19: v24,
            a20: v25,
            a21: v26,
            a22: v27,
            a23: v28,
            a24: v29,
            a25: v30,
            a26: v31,
            a27: v32,
            a28: v33,
            a29: 0);
        }
      }
      ++v4;
      ++v5;
    }
    while ( v4 < this->pieces.num );
  }
}


// ========================================================================
// ??1idEffectPhysicsCuttable@@QAA@XZ
// EA  : 0x82703410
// RVA : 0x00703410
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicscuttable.cpp
// ========================================================================

void __fastcall idEffectPhysicsCuttable::~idEffectPhysicsCuttable(idEffectPhysicsCuttable *this)
{
  int v2; // r25
  int v3; // r26
  idEffectPhysicsCuttable::piece_t *list; // r11
  idEffectPhysicsCuttable::piece_t *v5; // r29
  idEffectPhysicsRigidBody *rigidBody; // r28
  idStreamFileLog *properties; // r28
  idEffectPhysicsCuttable::piece_t *v8; // r4
  idEffectPhysicsCuttable::piece_t *v9; // r4
  idRenderModelCuttableDynamic **v10; // r4

  idList<idThread *,58>::Clear((idList<idVehicleState *,5> *)this);
  v2 = 0;
  if ( this->pieces.num > 0 )
  {
    v3 = 0;
    do
    {
      list = this->pieces.list;
      v5 = &list[v3];
      rigidBody = list[v3].rigidBody;
      if ( rigidBody != nullptr )
      {
        idEffectPhysicsRigidBody::~idEffectPhysicsRigidBody(this: list[v3].rigidBody);
        idMem::Free(this: &mem, ptr: rigidBody, align: ALIGN_16);
        v5->rigidBody = nullptr;
      }
      properties = (idStreamFileLog *)v5->properties;
      if ( v5->properties != nullptr )
      {
        idMD6PhaseTrack::idMD6PhaseTrack(this: (idStreamFileLog *)v5->properties);
        idMem::Free(this: &mem, ptr: properties, align: ALIGN_16);
        v5->properties = nullptr;
      }
      ++v2;
      v5->soundTable = nullptr;
      ++v3;
    }
    while ( v2 < this->pieces.num );
  }
  if ( this->pieces.listStatic == 0 || this->pieces.listStatic == 2 )
  {
    v8 = this->pieces.list;
    if ( v8 != nullptr )
      idMem::Free(this: &mem, ptr: v8, align: ALIGN_16);
    this->pieces.list = nullptr;
    this->pieces.size = 0;
  }
  this->pieces.num = 0;
  idEffectPhysicsBroadPhase::~idEffectPhysicsBroadPhase(this: &this->broadPhase);
  if ( this->pieces.listStatic == 0 || this->pieces.listStatic == 2 )
  {
    v9 = this->pieces.list;
    if ( v9 != nullptr )
      idMem::Free(this: &mem, ptr: v9, align: ALIGN_16);
    this->pieces.list = nullptr;
    this->pieces.size = 0;
  }
  this->pieces.num = 0;
  if ( this->models.listStatic == 0 || this->models.listStatic == 2 )
  {
    v10 = this->models.list;
    if ( v10 != nullptr )
      idMem::Free(this: &mem, ptr: v10, align: ALIGN_16);
    this->models.list = nullptr;
    this->models.size = 0;
  }
  this->models.num = 0;
  if ( this->freeModels.listStatic == 0 || this->freeModels.listStatic == 2 )
  {
    if ( this->freeModels.list != nullptr )
      idMem::Free(this: &mem, ptr: this->freeModels.list, align: ALIGN_16);
    this->freeModels.list = nullptr;
    this->freeModels.size = 0;
  }
  this->freeModels.num = 0;
}


// ========================================================================
// __unwind$247434_0
// EA  : 0x827035C4
// RVA : 0x007035C4
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicscuttable.cpp
// ========================================================================

void _unwind_247434_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: *(idStaticList<idVehicleState *,4> **)(v0 - 160 + 180));
}


// ========================================================================
// __unwind$247435
// EA  : 0x827035EC
// RVA : 0x007035EC
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicscuttable.cpp
// ========================================================================

void _unwind_247435()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 96));
}


// ========================================================================
// __unwind$247436
// EA  : 0x82703618
// RVA : 0x00703618
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicscuttable.cpp
// ========================================================================

void _unwind_247436()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 152));
}


// ========================================================================
// __unwind$247437
// EA  : 0x82703644
// RVA : 0x00703644
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicscuttable.cpp
// ========================================================================

void _unwind_247437()
{
  int v0; // r12

  idEffectPhysicsBroadPhase::~idEffectPhysicsBroadPhase(this: (idEffectPhysicsBroadPhase *)(*(_DWORD *)(v0 - 160 + 180)
                                                                                          + 1032));
}


// ========================================================================
// ??0idEffectPhysicsCuttable@@QAA@XZ
// EA  : 0x82703958
// RVA : 0x00703958
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicscuttable.cpp
// ========================================================================

idEffectPhysicsCuttable *__fastcall idEffectPhysicsCuttable::idEffectPhysicsCuttable(idEffectPhysicsCuttable *this)
{
  this->freeModels.granularity = 1;
  this->freeModels.list = this->freeModels.staticList;
  this->freeModels.size = 10;
  this->freeModels.num = 0;
  this->freeModels.memTag = 5;
  this->freeModels.listStatic = 1;
  this->models.size = 10;
  this->models.num = 0;
  this->models.granularity = 1;
  this->models.list = this->models.staticList;
  this->models.memTag = 5;
  this->models.listStatic = 1;
  idStaticList<idEffectPhysicsCuttable::piece_t,8>::idStaticList<idEffectPhysicsCuttable::piece_t,8>(this: &this->pieces);
  idEffectPhysicsBroadPhase::idEffectPhysicsBroadPhase(this: &this->broadPhase);
  this->pieceMaxLifeTime = 30000;
  this->pieceLifeTime = 5000;
  this->pieceFadeTime = 2000;
  this->pieceCollisionAgeDecay = 0.0;
  this->pieceMass = 8;
  this->pieceFriction = 0.0;
  return this;
}


// ========================================================================
// __unwind$247773
// EA  : 0x82703A20
// RVA : 0x00703A20
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicscuttable.cpp
// ========================================================================

void _unwind_247773()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: *(idStaticList<idVehicleState *,4> **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$247774
// EA  : 0x82703A48
// RVA : 0x00703A48
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicscuttable.cpp
// ========================================================================

void _unwind_247774()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 96));
}


// ========================================================================
// __unwind$247775
// EA  : 0x82703A74
// RVA : 0x00703A74
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicscuttable.cpp
// ========================================================================

void _unwind_247775()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 152));
}


// ========================================================================
// ?Emit@idEffectPhysicsCuttable@@QAAHABUcuttablePhysicsEmitInfo_t@@ABV?$idList@VidDrawVert@@$04@@ABV?$idList@VidVec2@@$04@@ABV?$idList@G$04@@@Z
// EA  : 0x82703AA8
// RVA : 0x00703AA8
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicscuttable.cpp
// ========================================================================

int __fastcall idEffectPhysicsCuttable::Emit(
        idEffectPhysicsCuttable *this,
        const cuttablePhysicsEmitInfo_t *emitInfo,
        const idList<idDrawVert,5> *vertices,
        const idList<idVec2,5> *st,
        const idList<unsigned short,5> *indices)
{
  int num; // r11
  int v8; // r10
  idEffectPhysicsCuttable::piece_t *list; // r9
  int v10; // r8
  int v11; // r5
  int v12; // r11
  idEffectPhysicsCuttable::piece_t *v13; // r6
  idEffectPhysicsCuttable::piece_t *v14; // r7
  const idMaterial *v15; // r3
  int v16; // r4
  int v17; // r10
  idEffectPhysicsCuttable::model_t *v18; // r9
  int v19; // r8
  int v20; // r11
  idEffectPhysicsCuttable::model_t *v21; // r6
  idEffectPhysicsCuttable::model_t *v22; // r7
  idEffectPhysicsCuttable::model_t *v23; // r9
  idEffectPhysicsCuttable::model_t *v24; // r10
  int index; // r14
  idEffectPhysicsCuttable::model_t *v26; // r8
  double x; // fp0
  idMat3 *p_orientation; // r27
  idEffectPhysicsCuttable::piece_t *v29; // r29
  idVec3 *p_position; // r23
  double v31; // fp11
  const idMaterial *renderModelIndex; // r11
  const idMaterial *rigidBody; // r30
  const idMaterial *properties; // r30
  double v35; // fp30
  double v36; // fp29
  double v37; // fp28
  int v38; // r21
  __int64 v39; // r10
  const idMaterial *v40; // r3
  idEffectPhysicsProperties *v41; // r28
  const idMaterial *v42; // r3
  idEffectPhysicsRigidBody *v43; // r30
  int entityNum; // r11
  double v45; // fp10
  double v46; // fp9
  double y; // fp7
  const idEffectPhysicsProperties *v48; // r9
  double v49; // fp13
  float v50; // r6
  double mass; // fp12
  float z; // r5
  float v53; // r4
  double v54; // fp10
  double v55; // fp13
  double v56; // fp12
  double v57; // fp3
  double v58; // fp2
  double v59; // fp10
  double v60; // fp5
  double v61; // fp0
  double v62; // fp9
  double v63; // fp8
  double v64; // fp7
  idRenderModelCuttableDynamic **v65; // r10
  idRenderModel *v66; // r30
  __int64 v68; // [sp+50h] [-710h] BYREF
  float v69; // [sp+58h] [-708h]
  int v70; // [sp+5Ch] [-704h]
  float v71; // [sp+60h] [-700h]
  float v72; // [sp+64h] [-6FCh]
  float v73; // [sp+68h] [-6F8h]
  idVec3 v74; // [sp+70h] [-6F0h] BYREF
  idVec3 v75; // [sp+80h] [-6E0h] BYREF
  idTraceModel v76; // [sp+90h] [-6D0h] BYREF

  num = this->pieces.num;
  v8 = 0;
  v70 = 0;
  if ( num > 0 )
  {
    list = this->pieces.list;
    v10 = 0;
    v11 = this->pieces.num;
    v12 = 0;
    v13 = list;
    v14 = list;
    do
    {
      if ( v14->timeStamp < v13->timeStamp )
      {
        v70 = v8;
        v10 = v12 * 108;
      }
      ++v8;
      v14 = &list[++v12];
      v13 = (idEffectPhysicsCuttable::piece_t *)((char *)list + v10);
    }
    while ( v8 < v11 );
  }
  v15 = (const idMaterial *)this->freeModels.num;
  v16 = 0;
  v17 = 0;
  HIDWORD(v68) = v15;
  if ( (int)v15 > 0 )
  {
    v18 = this->freeModels.list;
    v19 = 0;
    v20 = 0;
    v21 = this->freeModels.list;
    v22 = this->freeModels.list;
    do
    {
      if ( v22->timeStamp < v21->timeStamp )
      {
        v16 = v17;
        v19 = v20 * 8;
      }
      ++v17;
      v22 = &v18[++v20];
      v21 = (idEffectPhysicsCuttable::model_t *)((char *)v18 + v19);
    }
    while ( v17 < (int)v15 );
  }
  v23 = this->freeModels.list;
  v24 = &this->freeModels.list[v16];
  index = v24->index;
  if ( v16 >= 0 && v16 < (int)v15 )
  {
    this->freeModels.num = (int)&v15[-1].coverage + 3;
    if ( (const idMaterial *)v16 != (const idMaterial *)((char *)&v15[-1].coverage + 3) )
    {
      v26 = &v23[(int)v15 - 1];
      v24->index = v26->index;
      v24->timeStamp = v26->timeStamp;
    }
  }
  x = emitInfo->position.x;
  p_orientation = &emitInfo->orientation;
  v29 = &this->pieces.list[v70];
  HIDWORD(v68) = &emitInfo->orientation.mat[1];
  v29->position.x = x;
  v29->position.y = emitInfo->position.y;
  HIDWORD(v68) = &emitInfo->orientation.mat[2];
  p_position = &emitInfo->position;
  v29->position.z = emitInfo->position.z;
  v31 = emitInfo->orientation.mat[0].x;
  HIDWORD(v68) = &v29->orientation.mat[2];
  v29->orientation.mat[0].x = v31;
  v29->orientation.mat[0].y = emitInfo->orientation.mat[0].y;
  v29->orientation.mat[0].z = emitInfo->orientation.mat[0].z;
  v29->orientation.mat[1].x = emitInfo->orientation.mat[1].x;
  v29->orientation.mat[1].y = emitInfo->orientation.mat[1].y;
  v29->orientation.mat[1].z = emitInfo->orientation.mat[1].z;
  v29->orientation.mat[2].x = emitInfo->orientation.mat[2].x;
  v29->orientation.mat[2].y = emitInfo->orientation.mat[2].y;
  v29->orientation.mat[2].z = emitInfo->orientation.mat[2].z;
  v29->timeStamp = emitInfo->emitTime;
  v29->firstCollisionTime = 0;
  v29->soundTable = emitInfo->soundTable;
  renderModelIndex = (const idMaterial *)v29->renderModelIndex;
  v29->minBounceVelocitySqr = emitInfo->minBounceVelocitySqr;
  v29->nextSoundTime = emitInfo->emitTime;
  if ( (int)renderModelIndex >= 0 )
  {
    LODWORD(v68) = emitInfo->emitTime;
    HIDWORD(v68) = renderModelIndex;
    idList<cachedPageFile_t,5>::Append((idList<idSkinMapping,46> *)this, obj: (const idSkinMapping *)&v68);
  }
  v29->renderModelIndex = index;
  HIDWORD(v68) = &v29->collision;
  v29->collision.collisionNormalVelocity = vec3_origin;
  v29->collision.collisionPoint = vec3_origin;
  rigidBody = (const idMaterial *)v29->rigidBody;
  v29->collision.collisionSurfaceType = 0;
  if ( rigidBody != nullptr )
  {
    HIDWORD(v68) = rigidBody;
    idEffectPhysicsRigidBody::~idEffectPhysicsRigidBody(this: (idEffectPhysicsRigidBody *)rigidBody);
    idMem::Free(this: &mem, ptr: (void *)rigidBody, align: ALIGN_16);
    v29->rigidBody = nullptr;
  }
  properties = (const idMaterial *)v29->properties;
  if ( v29->properties != nullptr )
  {
    HIDWORD(v68) = v29->properties;
    idMD6PhaseTrack::idMD6PhaseTrack(this: (idStreamFileLog *)HIDWORD(v68));
    idMem::Free(this: &mem, ptr: (void *)properties, align: ALIGN_16);
    v29->properties = nullptr;
  }
  v76 = *emitInfo->traceModel;
  v35 = (float)((float)(v76.bounds.b[0].x + v76.bounds.b[1].x) * (float)0.5);
  v36 = (float)((float)(v76.bounds.b[0].y + v76.bounds.b[1].y) * (float)0.5);
  v37 = (float)((float)(v76.bounds.b[0].z + v76.bounds.b[1].z) * (float)0.5);
  v75.x = -v35;
  v75.y = -v36;
  v75.z = -v37;
  *(float *)&v68 = v75.z;
  idTraceModel::Translate(this: &v76, translation: &v75);
  v38 = idTraceModelCache::AllocTraceModel(
          this: this->broadPhase.traceModelCache,
          trm: &v76,
          material: emitInfo->renderMaterial);
  v40 = (const idMaterial *)idMem::AllocWithLocation(
                              this: &mem,
                              location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                              size: 0xA0u,
                              tag: TAG_FXPHYSICS,
                              zeroBuffer: false,
                              align: ALIGN_16,
                              heap: HEAP_DEFAULTHEAP);
  HIDWORD(v68) = v40;
  if ( v40 != nullptr )
    v41 = idEffectPhysicsProperties::idEffectPhysicsProperties(this: (idEffectPhysicsProperties *)v40);
  else
    v41 = nullptr;
  LODWORD(v39) = pieceMass;
  v68 = v39;
  idEffectPhysicsProperties::Setup(this: v41, broadPhase: &this->broadPhase, traceModelIndex: v38, mass: (float)v39);
  v41->contactFriction = 0.5;
  v41->linearFriction = 0.60000002;
  v41->angularFriction = 0.60000002;
  v41->bouncyness = 0.60000002;
  v41->angularFrictionWater = 1.0;
  v41->linearFrictionWater = 1.0;
  v41->gravityVector.z = -250.0;
  v41->gravityVector.x = 0.0;
  v41->gravityVector.y = 0.0;
  v41->worldCollisionOnly = true;
  v41->simplePointCollision = false;
  v41->crazyBounceChance = 0.0;
  HIDWORD(v68) = &v41->gravityVector;
  v41->maxLinearVelocity = 5000.0;
  v41->stopSpeed = 30.0;
  v41->maxAngularVelocity = (float)3.1415927 * (float)4.0;
  v41->clipMask = 1;
  v42 = (const idMaterial *)idMem::AllocWithLocation(
                              this: &mem,
                              location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                              size: 0x110u,
                              tag: TAG_FXPHYSICS,
                              zeroBuffer: false,
                              align: ALIGN_16,
                              heap: HEAP_DEFAULTHEAP);
  HIDWORD(v68) = v42;
  if ( v42 != nullptr )
    v43 = idEffectPhysicsRigidBody::idEffectPhysicsRigidBody(this: (idEffectPhysicsRigidBody *)v42);
  else
    v43 = nullptr;
  idEffectPhysicsRigidBody::Setup(this: v43, props: v41);
  entityNum = emitInfo->entityNum;
  HIDWORD(v68) = &v43->currentState;
  v43->SPObject.entityNum = entityNum;
  v45 = (float)((float)v37 + emitInfo->position.z);
  v46 = (float)(p_position->x + (float)v35);
  v43->currentState.position.y = emitInfo->position.y + (float)v36;
  v43->currentState.position.z = v45;
  v43->currentState.position.x = v46;
  idEffectPhysicsBroadPhase::SetObjectPosition(
    this: v43->properties->broadPhase,
    object: &v43->SPObject,
    origin: &v43->currentState.position,
    axis: &v43->currentState.orientation,
    bounds: nullptr);
  v43->currentState.orientation.mat[0].x = p_orientation->mat[0].x;
  y = emitInfo->orientation.mat[0].y;
  HIDWORD(v68) = &v43->currentState.orientation;
  v43->currentState.orientation.mat[0].y = y;
  v43->currentState.orientation.mat[0].z = emitInfo->orientation.mat[0].z;
  HIDWORD(v68) = &v43->currentState.orientation.mat[1];
  v43->currentState.orientation.mat[1].x = emitInfo->orientation.mat[1].x;
  v43->currentState.orientation.mat[1].y = emitInfo->orientation.mat[1].y;
  v43->currentState.orientation.mat[1].z = emitInfo->orientation.mat[1].z;
  HIDWORD(v68) = &emitInfo->orientation.mat[2];
  v43->currentState.orientation.mat[2].x = emitInfo->orientation.mat[2].x;
  v43->currentState.orientation.mat[2].y = emitInfo->orientation.mat[2].y;
  v43->currentState.orientation.mat[2].z = emitInfo->orientation.mat[2].z;
  idEffectPhysicsBroadPhase::SetObjectPosition(
    this: v43->properties->broadPhase,
    object: &v43->SPObject,
    origin: &v43->currentState.position,
    axis: &v43->currentState.orientation,
    bounds: nullptr);
  v48 = v43->properties;
  *(float *)&v68 = vec3_origin.x;
  v49 = vec3_origin.x;
  v50 = emitInfo->orientation.mat[0].y;
  mass = v48->mass;
  z = emitInfo->orientation.mat[0].z;
  v53 = p_orientation->mat[0].x;
  LODWORD(v68) = LODWORD(vec3_origin.y);
  v69 = vec3_origin.z;
  v54 = vec3_origin.z;
  v72 = v50;
  v43->currentState.linearMomentum.y = vec3_origin.y * (float)mass;
  v73 = z;
  v71 = v53;
  v43->currentState.linearMomentum.x = (float)v49 * (float)mass;
  v43->currentState.linearMomentum.z = (float)v54 * (float)mass;
  HIDWORD(v68) = &v43->currentState.angularMomentum;
  v55 = v72;
  v56 = v71;
  v57 = v43->properties->inertiaTensor.mat[1].y;
  v58 = v43->properties->inertiaTensor.mat[0].y;
  v59 = v43->properties->inertiaTensor.mat[0].z;
  v60 = (float)(v43->properties->inertiaTensor.mat[2].y * v73);
  v61 = (float)((float)(v43->properties->inertiaTensor.mat[1].z * v72)
              + (float)(v43->properties->inertiaTensor.mat[2].z * v73));
  v43->currentState.angularMomentum.x = (float)(v43->properties->inertiaTensor.mat[0].x * v71)
                                      + (float)((float)(v43->properties->inertiaTensor.mat[1].x * v72)
                                              + (float)(v43->properties->inertiaTensor.mat[2].x * v73));
  v43->currentState.angularMomentum.z = (float)((float)v59 * (float)v56) + (float)v61;
  v43->currentState.angularMomentum.y = (float)((float)v58 * (float)v56)
                                      + (float)((float)((float)v57 * (float)v55) + (float)v60);
  if ( (float)((float)(emitInfo->impulse.z * emitInfo->impulse.z)
             + (float)((float)(emitInfo->impulse.x * emitInfo->impulse.x)
                     + (float)(emitInfo->impulse.y * emitInfo->impulse.y))) > 0.25 )
  {
    v62 = emitInfo->impulsePoint.z;
    v63 = (float)(emitInfo->impulsePoint.y + emitInfo->position.y);
    v64 = emitInfo->position.z;
    v74.x = p_position->x + emitInfo->impulsePoint.x;
    HIDWORD(v68) = &emitInfo->impulsePoint;
    v74.y = v63;
    v74.z = (float)v62 + (float)v64;
    idEffectPhysicsRigidBody::ApplyImpulse(this: v43, point: &v74, impulse: &emitInfo->impulse);
  }
  v43->active = true;
  v43->SPObject.motion.ignore = false;
  v29->properties = v41;
  v29->rigidBody = v43;
  v29->position.z = -v37;
  v29->position.y = -v36;
  v29->position.x = -v35;
  v65 = this->models.list;
  v66 = v65[index];
  if ( v66 != nullptr )
  {
    idRenderModelCuttableDynamic::Upload(
      this: v65[index],
      renderMaterial: emitInfo->renderMaterial,
      depthMaterial: emitInfo->depthMaterial,
      vertices,
      st,
      indices);
    idRenderModel::SetModelFade(this: v66, v: 1.0);
    idRenderModel::CommitThisFrame(this: v66);
  }
  return v70;
}


// ========================================================================
// __unwind$247838
// EA  : 0x827041D8
// RVA : 0x007041D8
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicscuttable.cpp
// ========================================================================

void _unwind_247838()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 1888 + 80), tag: TAG_FXPHYSICS);
}


// ========================================================================
// __unwind$247839
// EA  : 0x82704204
// RVA : 0x00704204
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicscuttable.cpp
// ========================================================================

void _unwind_247839()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 1888 + 80), tag: TAG_FXPHYSICS);
}


// ========================================================================
// ?UpdateSimulation@idEffectPhysicsCuttable@@QAAXABVidVec3@@ABVidMat3@@HH@Z
// EA  : 0x82704230
// RVA : 0x00704230
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicscuttable.cpp
// ========================================================================

void __fastcall idEffectPhysicsCuttable::UpdateSimulation(
        idEffectPhysicsCuttable *this,
        idEffectPhysicsCollision *origin,
        const idMat3 *axis,
        int currentTime,
        unsigned int gameMsPerFrame)
{
  int num; // r9
  int v8; // r24
  double v9; // fp31
  int v10; // r26
  idEffectPhysicsCuttable::piece_t *v11; // r31
  int timeStamp; // r11
  idEffectPhysicsRigidBody *rigidBody; // r27
  int firstCollisionTime; // r9
  unsigned int v15; // r11
  int renderModelIndex; // r11
  idRenderModelCuttableDynamic *v17; // r29
  double v18; // fp0
  double v19; // fp13
  double v20; // fp12
  idDeclImpactSound *soundTable; // r3
  idSkinMapping v22; // [sp+50h] [-80h] BYREF

  num = this->pieces.num;
  v22 = (idSkinMapping)__PAIR64__(&unk_82390000, gameMsPerFrame);
  v8 = 0;
  v9 = (float)((float)__SPAIR64__(&unk_82390000, gameMsPerFrame) * (float)0.001);
  if ( num > 0 )
  {
    v10 = 0;
    do
    {
      v11 = &this->pieces.list[v10];
      timeStamp = v11->timeStamp;
      rigidBody = v11->rigidBody;
      if ( timeStamp != 0 && rigidBody->active )
      {
        firstCollisionTime = v11->firstCollisionTime;
        if ( firstCollisionTime != 0 )
          v15 = this->pieceFadeTime + this->pieceLifeTime + firstCollisionTime;
        else
          v15 = this->pieceMaxLifeTime + timeStamp;
        if ( (((((currentTime ^ v15) & 0x80000000) == 0) + (v15 >= currentTime)) & 1) != 0 )
        {
          rigidBody->active = false;
          renderModelIndex = v11->renderModelIndex;
          v11->timeStamp = 0;
          if ( renderModelIndex >= 0 )
          {
            v17 = this->models.list[renderModelIndex];
            if ( v17 != nullptr && !v17->unlinked )
            {
              idRenderModel::CommitThisFrame(this: v17);
              v17->unlinked = true;
            }
            v22.from = (const idMaterial *)v11->renderModelIndex;
            v22.to = (const idMaterial *)currentTime;
            idList<cachedPageFile_t,5>::Append((idList<idSkinMapping,46> *)this, obj: &v22);
            v11->renderModelIndex = -1;
          }
        }
        else
        {
          idEffectPhysicsRigidBody::Update(
            this: v11->rigidBody,
            deltaTime: v9,
            extraMomentumDecay: 0.0,
            collision: origin);
          if ( rigidBody->settled )
          {
            if ( v11->firstCollisionTime == 0 )
              v11->firstCollisionTime = currentTime;
          }
          else if ( ((LODWORD(v11->collision.collisionNormalVelocity.z)
                    | LODWORD(v11->collision.collisionNormalVelocity.y)
                    | LODWORD(v11->collision.collisionNormalVelocity.x))
                   & 0x7FFFFFFF) != 0 )
          {
            if ( v11->firstCollisionTime == 0 )
              v11->firstCollisionTime = currentTime;
            if ( this->soundWorld != nullptr )
            {
              soundTable = v11->soundTable;
              if ( soundTable != nullptr && currentTime >= v11->nextSoundTime )
              {
                v18 = (float)((float)(rigidBody->currentState.linearMomentum.x * rigidBody->properties->inverseMass)
                            - (float)(rigidBody->properties->gravityVector.x * (float)v9));
                v19 = (float)((float)(rigidBody->currentState.linearMomentum.y * rigidBody->properties->inverseMass)
                            - (float)(rigidBody->properties->gravityVector.y * (float)v9));
                v20 = (float)((float)(rigidBody->currentState.linearMomentum.z * rigidBody->properties->inverseMass)
                            - (float)(rigidBody->properties->gravityVector.z * (float)v9));
                if ( (float)((float)((float)v19 * (float)v19)
                           + (float)((float)((float)v20 * (float)v20) + (float)((float)v18 * (float)v18))) > (double)v11->minBounceVelocitySqr )
                {
                  origin = (idEffectPhysicsCollision *)idDeclImpactSound::GetImpactSoundForMaterial(
                                                         this: soundTable,
                                                         materialID: v11->collision.collisionSurfaceType);
                  if ( origin != nullptr )
                  {
                    this->soundWorld->PlayPositionedShaderDirectly(
                      this: this->soundWorld,
                      a2: (const idSoundShader *)origin,
                      a3: (const idVec3 *)&v11->rigidBody->currentState,
                      a4: &mat3_identity,
                      a5: 0.0);
                    v11->nextSoundTime = v11->soundTable->soundInterval + currentTime;
                  }
                }
              }
            }
          }
        }
      }
      ++v8;
      ++v10;
    }
    while ( v8 < this->pieces.num );
  }
}


// ========================================================================
// ?Init@idEffectPhysicsCuttable@@QAAXPAVidRenderWorld@@PAVidSoundWorld@@PAVidClip@@PAVidTraceModelCache@@@Z
// EA  : 0x82704638
// RVA : 0x00704638
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicscuttable.cpp
// ========================================================================

void __fastcall idEffectPhysicsCuttable::Init(
        idEffectPhysicsCuttable *this,
        idRenderWorld *renderWorld,
        idSoundWorld *soundWorld_,
        idClip *clip,
        idTraceModelCache *traceModelCache)
{
  int v8; // r27
  int i; // r31
  idRenderModel *v10; // r3
  void *v11; // [sp+50h] [-E0h] BYREF
  idSkinMapping v12; // [sp+58h] [-D8h] BYREF
  idEffectPhysicsCuttable::piece_t v13; // [sp+60h] [-D0h] BYREF

  idEffectPhysicsBroadPhase::Init(this: &this->broadPhase, clip, tmc: traceModelCache);
  this->pieceCollisionAgeDecay = 0.0;
  this->pieceMaxLifeTime = (int)(float)((float)1000.0 * (float)30.0);
  this->pieceLifeTime = (int)(float)((float)1000.0 * (float)5.0);
  this->pieceFriction = 0.0;
  v8 = 8;
  this->pieceFadeTime = (int)(float)((float)1000.0 * (float)2.0);
  do
  {
    v13.collision.collisionSurfaceType = 0;
    v13.timeStamp = 0;
    v13.firstCollisionTime = 0;
    v13.collision.collisionPoint = vec3_origin;
    v13.collision.collisionNormalVelocity = vec3_origin;
    memset(&v13, 0, 12);
    v13.position.x = vec3_origin.x;
    v13.position.y = vec3_origin.y;
    v13.position.z = vec3_origin.z;
    v13.renderModelIndex = -1;
    v13.orientation.mat[0].x = mat3_identity.mat[0].x;
    v13.orientation.mat[0].y = mat3_identity.mat[0].y;
    v13.nextSoundTime = 0;
    v13.orientation.mat[0].z = mat3_identity.mat[0].z;
    v13.orientation.mat[1].x = mat3_identity.mat[1].x;
    v13.orientation.mat[1].y = mat3_identity.mat[1].y;
    v13.orientation.mat[1].z = mat3_identity.mat[1].z;
    v13.orientation.mat[2].x = mat3_identity.mat[2].x;
    v13.orientation.mat[2].y = mat3_identity.mat[2].y;
    v13.orientation.mat[2].z = mat3_identity.mat[2].z;
    v13.minBounceVelocitySqr = 1.0;
    idList<idEffectPhysicsCuttable::piece_t,5>::Append(this: &this->pieces, obj: &v13);
    --v8;
  }
  while ( v8 != 0 );
  v12.to = nullptr;
  for ( i = 0; i < 10; ++i )
  {
    v10 = renderWorld->AllocRenderModel(this: renderWorld, a2: "_cuttabledynamic", a3: 1, a4: -1);
    v11 = _RTDynamicCast(
            inptr: v10,
            VfDelta: 0,
            SrcType: &idRenderModel `RTTI Type Descriptor',
            TargetType: &idRenderModelCuttableDynamic `RTTI Type Descriptor',
            isReference: 0);
    idList<idAnimWebBlendTree *,5>::Append(
      this: (idList<enum encounterGroupRole_t,5> *)&this->models,
      obj: (const encounterGroupRole_t *)&v11);
    v12.from = (const idMaterial *)i;
    idList<cachedPageFile_t,5>::Append((idList<idSkinMapping,46> *)this, obj: &v12);
  }
  this->soundWorld = soundWorld_;
}

