
// ========================================================================
// ?SubmitCollisionQueries@idEffectPhysicsPieceEmitter@@QAAX_N@Z
// EA  : 0x827052B0
// RVA : 0x007052B0
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicspieceemitter.cpp
// ========================================================================

void __fastcall idEffectPhysicsPieceEmitter::SubmitCollisionQueries(
        idEffectPhysicsPieceEmitter *this,
        bool worldCollisionModelOnly)
{
  idEffectPhysicsBroadPhase::SubmitQueries(this: &this->broadPhase, worldCollisionModelOnly);
}


// ========================================================================
// ?Show@idEffectPhysicsPieceEmitter@@QAAXXZ
// EA  : 0x827052B8
// RVA : 0x007052B8
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicspieceemitter.cpp
// ========================================================================

void __fastcall idEffectPhysicsPieceEmitter::Show(idEffectPhysicsPieceEmitter *this)
{
  this->hidden = false;
}


// ========================================================================
// ?EmitPiece@idEffectPhysicsPieceEmitter@@QAAXHABVidVec3@@ABVidMat3@@00@Z
// EA  : 0x827052C8
// RVA : 0x007052C8
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicspieceemitter.cpp
// ========================================================================

void __fastcall idEffectPhysicsPieceEmitter::EmitPiece(
        idEffectPhysicsPieceEmitter *this,
        int emitTime,
        const idVec3 *pos,
        const idMat3 *axes,
        const idVec3 *impulsePoint,
        const idVec3 *impulse)
{
  idEffectPhysicsPieceEmitter::idBreakablePiece *v11; // r11
  idEffectPhysicsRigidBody *rigidBody; // r11
  idEffectPhysicsBroadPhase **p_broadPhase; // r4
  idEffectPhysicsBroadPhase *v14; // r3
  idEffectPhysicsRigidBody *v15; // r11
  idEffectPhysicsBroadPhase **v16; // r9
  idEffectPhysicsBroadPhase *v17; // r3
  idEffectPhysicsRigidBody *v18; // r3
  double mass; // fp2
  double v20; // fp1
  double z; // fp0
  double x; // fp12
  idEffectPhysicsRigidBody *v23; // r10
  double v24; // fp4
  double y; // fp7
  double v26; // fp11
  double v27; // fp9
  idEffectPhysicsPieceEmitter::idBreakablePiece *list; // r9
  int pieceIndex; // r11
  double v30; // fp11
  double v31; // fp10
  idEffectPhysicsRigidBody *v32; // r11
  int v33; // r11
  idVec3 v34; // [sp+50h] [-50h] BYREF

  v11 = &this->pieces.list[this->pieceIndex];
  if ( !v11->rigidBody->active )
    ++this->numPiecesInUse;
  this->hiddenOverride = false;
  v11->emitTime = emitTime;
  this->pieces.list[this->pieceIndex].firstCollisionTime = 0;
  rigidBody = this->pieces.list[this->pieceIndex].rigidBody;
  rigidBody->currentState.position.x = pos->x;
  p_broadPhase = &rigidBody->properties->broadPhase;
  rigidBody->currentState.position.y = pos->y;
  v14 = *p_broadPhase;
  rigidBody->currentState.position.z = pos->z;
  idEffectPhysicsBroadPhase::SetObjectPosition(
    this: v14,
    object: &rigidBody->SPObject,
    origin: &rigidBody->currentState.position,
    axis: &rigidBody->currentState.orientation,
    bounds: nullptr);
  v15 = this->pieces.list[this->pieceIndex].rigidBody;
  v15->currentState.orientation.mat[0].x = axes->mat[0].x;
  v16 = &v15->properties->broadPhase;
  v15->currentState.orientation.mat[0].y = axes->mat[0].y;
  v17 = *v16;
  v15->currentState.orientation.mat[0].z = axes->mat[0].z;
  v15->currentState.orientation.mat[1].x = axes->mat[1].x;
  v15->currentState.orientation.mat[1].y = axes->mat[1].y;
  v15->currentState.orientation.mat[1].z = axes->mat[1].z;
  v15->currentState.orientation.mat[2].x = axes->mat[2].x;
  v15->currentState.orientation.mat[2].y = axes->mat[2].y;
  v15->currentState.orientation.mat[2].z = axes->mat[2].z;
  idEffectPhysicsBroadPhase::SetObjectPosition(
    this: v17,
    object: &v15->SPObject,
    origin: &v15->currentState.position,
    axis: &v15->currentState.orientation,
    bounds: nullptr);
  v18 = this->pieces.list[this->pieceIndex].rigidBody;
  mass = v18->properties->mass;
  v20 = (float)(vec3_origin.x * v18->properties->mass);
  z = vec3_origin.z;
  v18->currentState.linearMomentum.y = vec3_origin.y * v18->properties->mass;
  v18->currentState.linearMomentum.z = (float)z * (float)mass;
  v18->currentState.linearMomentum.x = v20;
  x = vec3_origin.x;
  v23 = this->pieces.list[this->pieceIndex].rigidBody;
  v24 = v23->properties->inertiaTensor.mat[0].z;
  y = v23->properties->inertiaTensor.mat[0].y;
  v26 = (float)((float)(v23->properties->inertiaTensor.mat[1].z * vec3_origin.y)
              + (float)(v23->properties->inertiaTensor.mat[2].z * vec3_origin.z));
  v27 = (float)((float)(v23->properties->inertiaTensor.mat[1].y * vec3_origin.y)
              + (float)(v23->properties->inertiaTensor.mat[2].y * vec3_origin.z));
  v23->currentState.angularMomentum.x = (float)(v23->properties->inertiaTensor.mat[0].x * vec3_origin.x)
                                      + (float)((float)(v23->properties->inertiaTensor.mat[1].x * vec3_origin.y)
                                              + (float)(v23->properties->inertiaTensor.mat[2].x * vec3_origin.z));
  v23->currentState.angularMomentum.z = (float)((float)v24 * (float)x) + (float)v26;
  v23->currentState.angularMomentum.y = (float)((float)y * (float)x) + (float)v27;
  list = this->pieces.list;
  pieceIndex = this->pieceIndex;
  v30 = (float)(impulsePoint->z + pos->z);
  v31 = (float)(impulsePoint->y + pos->y);
  v34.x = pos->x + impulsePoint->x;
  v34.z = v30;
  v34.y = v31;
  idEffectPhysicsRigidBody::ApplyImpulse(this: list[pieceIndex].rigidBody, point: &v34, impulse);
  v32 = this->pieces.list[this->pieceIndex].rigidBody;
  v32->active = true;
  v32->SPObject.motion.ignore = false;
  v33 = this->pieceIndex;
  if ( v33 >= this->pieces.num - 1 )
    this->pieceIndex = 0;
  else
    this->pieceIndex = v33 + 1;
}


// ========================================================================
// ?UpdateModel@idEffectPhysicsPieceEmitter@@QAAXABVidVec3@@@Z
// EA  : 0x82705580
// RVA : 0x00705580
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicspieceemitter.cpp
// ========================================================================

void __fastcall idEffectPhysicsPieceEmitter::UpdateModel(
        idEffectPhysicsPieceEmitter *this,
        const idVec3 *activeDrawScale3D)
{
  int num; // r10
  double x; // fp12
  int v5; // r30
  int v6; // r29
  idEffectPhysicsPieceEmitter::idBreakablePiece *list; // r11
  idEffectPhysicsRigidBody *rigidBody; // r11
  const idVec3 *p_position; // r28
  const idMat3 *v10; // r3
  idRenderModelDiscreteAnimation *model; // r3
  idMat3 v12; // [sp+50h] [-80h] BYREF
  idMat3 v13[2]; // [sp+80h] [-50h] BYREF

  num = this->pieces.num;
  v12.mat[2].z = activeDrawScale3D->z;
  x = activeDrawScale3D->x;
  v5 = 0;
  v12.mat[1].y = activeDrawScale3D->y;
  v12.mat[0].x = x;
  v12.mat[0].y = 0.0;
  v12.mat[0].z = 0.0;
  v12.mat[1].x = 0.0;
  v12.mat[1].z = 0.0;
  v12.mat[2].x = 0.0;
  v12.mat[2].y = 0.0;
  if ( num > 0 )
  {
    v6 = 0;
    do
    {
      list = this->pieces.list;
      if ( list[v6].rigidBody->active )
      {
        rigidBody = list[v6].rigidBody;
        p_position = &rigidBody->currentState.position;
        v10 = idMat3::operator*(this: v13, result: &rigidBody->currentState.orientation, a: &v12);
        idRenderModelDiscreteAnimation::SetPiecePosition(
          this: this->model,
          index: v5,
          position: p_position,
          orientation: v10);
      }
      else
      {
        idRenderModelDiscreteAnimation::CollapsePiece(this: this->model, index: v5);
      }
      ++v5;
      ++v6;
    }
    while ( v5 < this->pieces.num );
  }
  model = this->model;
  if ( model != nullptr && !this->hidden && !this->hiddenOverride )
    idRenderModelDiscreteAnimation::Update(this: model);
}


// ========================================================================
// ?Hide@idEffectPhysicsPieceEmitter@@QAAXXZ
// EA  : 0x82705678
// RVA : 0x00705678
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicspieceemitter.cpp
// ========================================================================

void __fastcall idEffectPhysicsPieceEmitter::Hide(idEffectPhysicsPieceEmitter *this)
{
  idRenderModelDiscreteAnimation *model; // r31

  model = this->model;
  this->hidden = true;
  if ( model != nullptr && !model->unlinked )
  {
    idRenderModel::CommitThisFrame(this: model);
    model->unlinked = true;
  }
}


// ========================================================================
// ?Reset@idEffectPhysicsPieceEmitter@@QAAXXZ
// EA  : 0x827056D0
// RVA : 0x007056D0
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicspieceemitter.cpp
// ========================================================================

void __fastcall idEffectPhysicsPieceEmitter::Reset(idEffectPhysicsPieceEmitter *this)
{
  idRenderModelDiscreteAnimation *model; // r3
  int num; // r11
  int v4; // r27
  int v5; // r28
  int v6; // r30
  idEffectPhysicsRigidBody *rigidBody; // r11
  idEffectPhysicsBroadPhase **p_broadPhase; // r4
  idEffectPhysicsBroadPhase *v9; // r3
  idEffectPhysicsRigidBody *v10; // r11
  idEffectPhysicsBroadPhase **v11; // r10
  idEffectPhysicsBroadPhase *v12; // r3
  double y; // fp13
  double z; // fp12
  idEffectPhysicsRigidBody *v15; // r8
  double mass; // fp2
  idEffectPhysicsRigidBody *v17; // r5
  double v18; // fp10
  double v19; // fp11
  double x; // fp13
  double v21; // fp2
  double v22; // fp12
  int i; // r10
  idEffectPhysicsProperties *v24; // r8
  const idDeclBreakable *decl; // r11
  idRenderModelDiscreteAnimation *v26; // r30
  idVec3 v27; // [sp+50h] [-70h] BYREF
  idMat3 v28; // [sp+60h] [-60h] BYREF

  model = this->model;
  if ( model != nullptr )
  {
    idRenderModelDiscreteAnimation::Reset(this: model);
    num = this->pieces.num;
    v4 = 0;
    this->random.seed = 0;
    v5 = 0;
    this->pieceIndex = 0;
    this->numPiecesInUse = 0;
    if ( num > 0 )
    {
      v6 = 0;
      do
      {
        this->pieces.list[v6].emitTime = 0;
        this->pieces.list[v6].firstCollisionTime = 0;
        idRenderModelDiscreteAnimation::GetPiecePosition(
          this: this->model,
          index: v5,
          position: &v27,
          orientation: &v28);
        this->pieces.list[v6].rigidBody->active = false;
        rigidBody = this->pieces.list[v6].rigidBody;
        rigidBody->currentState.position.x = v27.x;
        p_broadPhase = &rigidBody->properties->broadPhase;
        rigidBody->currentState.position.y = v27.y;
        v9 = *p_broadPhase;
        rigidBody->currentState.position.z = v27.z;
        idEffectPhysicsBroadPhase::SetObjectPosition(
          this: v9,
          object: &rigidBody->SPObject,
          origin: &rigidBody->currentState.position,
          axis: &rigidBody->currentState.orientation,
          bounds: nullptr);
        v10 = this->pieces.list[v6].rigidBody;
        v10->currentState.orientation.mat[0].x = v28.mat[0].x;
        v11 = &v10->properties->broadPhase;
        v10->currentState.orientation.mat[0].y = v28.mat[0].y;
        v12 = *v11;
        v10->currentState.orientation.mat[0].z = v28.mat[0].z;
        v10->currentState.orientation.mat[1] = v28.mat[1];
        v10->currentState.orientation.mat[2] = v28.mat[2];
        idEffectPhysicsBroadPhase::SetObjectPosition(
          this: v12,
          object: &v10->SPObject,
          origin: &v10->currentState.position,
          axis: &v10->currentState.orientation,
          bounds: nullptr);
        ++v5;
        y = vec3_origin.y;
        z = vec3_origin.z;
        v15 = this->pieces.list[v6].rigidBody;
        mass = v15->properties->mass;
        v15->currentState.linearMomentum.x = vec3_origin.x * v15->properties->mass;
        v15->currentState.linearMomentum.y = (float)y * (float)mass;
        v15->currentState.linearMomentum.z = (float)z * (float)mass;
        v17 = this->pieces.list[v6++].rigidBody;
        v18 = (float)((float)(v17->properties->inertiaTensor.mat[1].x * vec3_origin.y)
                    + (float)(v17->properties->inertiaTensor.mat[2].x * vec3_origin.z));
        v19 = (float)((float)(v17->properties->inertiaTensor.mat[1].z * vec3_origin.y)
                    + (float)(v17->properties->inertiaTensor.mat[2].z * vec3_origin.z));
        x = vec3_origin.x;
        v21 = v17->properties->inertiaTensor.mat[0].x;
        v22 = v17->properties->inertiaTensor.mat[0].z;
        v17->currentState.angularMomentum.y = (float)(v17->properties->inertiaTensor.mat[0].y * vec3_origin.x)
                                            + (float)((float)(v17->properties->inertiaTensor.mat[1].y * vec3_origin.y)
                                                    + (float)(v17->properties->inertiaTensor.mat[2].y * vec3_origin.z));
        v17->currentState.angularMomentum.x = (float)((float)v21 * (float)x) + (float)v18;
        v17->currentState.angularMomentum.z = (float)((float)v22 * (float)x) + (float)v19;
      }
      while ( v5 < this->pieces.num );
    }
    for ( i = 0; i < this->properties.num; v24->clipMask = this->decl->settings.clipMask )
    {
      ++i;
      v24 = this->properties.list[v4++];
      v24->linearFriction = this->decl->settings.linearFriction;
      v24->angularFriction = this->decl->settings.angularFriction;
      v24->contactFriction = this->decl->settings.contactFriction;
      v24->linearFrictionWater = this->decl->settings.linearFrictionWater;
      v24->angularFrictionWater = this->decl->settings.angularFrictionWater;
      v24->bouncyness = this->decl->settings.bouncyness;
      decl = this->decl;
      v24->gravityVector.x = decl->settings.gravityVector.x;
      v24->gravityVector.y = decl->settings.gravityVector.y;
      v24->gravityVector.z = decl->settings.gravityVector.z;
      v24->worldCollisionOnly = this->decl->settings.worldCollisionOnly;
      v24->simplePointCollision = this->decl->settings.simplePointCollision;
      v24->crazyBounceChance = this->decl->settings.crazyBounceChance;
      v24->stopSpeed = this->decl->settings.stopSpeed;
      v24->maxLinearVelocity = this->decl->settings.maxLinearVelocity;
      v24->maxAngularVelocity = this->decl->settings.maxAngularVelocity;
    }
    v26 = this->model;
    this->hiddenOverride = true;
    if ( v26 != nullptr && !v26->unlinked )
    {
      idRenderModel::CommitThisFrame(this: v26);
      v26->unlinked = true;
    }
  }
}


// ========================================================================
// ?DrawCollisionModels@idEffectPhysicsPieceEmitter@@QAAXHABVidVec3@@ABVidMat3@@@Z
// EA  : 0x827059C8
// RVA : 0x007059C8
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicspieceemitter.cpp
// ========================================================================

void __fastcall idEffectPhysicsPieceEmitter::DrawCollisionModels(
        idEffectPhysicsPieceEmitter *this,
        int single,
        const idVec3 *offset,
        const idMat3 *axis)
{
  int v8; // r27
  int v9; // r29
  char *v10; // r10
  idEffectPhysicsPieceEmitter::idBreakablePiece *list; // r9
  idEffectPhysicsRigidBody *rigidBody; // r7
  int v13; // ctr
  float y; // r4
  float z; // r3
  int traceModelIndex; // r30
  idEffectPhysicsRigidBody *p_z; // r11
  double v18; // fp10
  double v19; // fp5
  double v20; // fp3
  idRenderWorld *v21; // r30
  __int64 v22; // r6
  __int64 v23; // r10
  __int64 v24; // r8
  va *v25; // r3
  int v26; // [sp+8h] [-1128h]
  int v27; // [sp+Ch] [-1124h]
  int v28; // [sp+10h] [-1120h]
  int v29; // [sp+14h] [-111Ch]
  int v30; // [sp+18h] [-1118h]
  int v31; // [sp+1Ch] [-1114h]
  int v32; // [sp+20h] [-1110h]
  int v33; // [sp+24h] [-110Ch]
  int v34; // [sp+28h] [-1108h]
  int v35; // [sp+2Ch] [-1104h]
  int v36; // [sp+30h] [-1100h]
  int v37; // [sp+34h] [-10FCh]
  int v38; // [sp+38h] [-10F8h]
  int v39; // [sp+3Ch] [-10F4h]
  int v40; // [sp+40h] [-10F0h]
  int v41; // [sp+44h] [-10ECh]
  int v42; // [sp+48h] [-10E8h]
  int v43; // [sp+4Ch] [-10E4h]
  int v44; // [sp+50h] [-10E0h]
  idVec3 v45; // [sp+60h] [-10D0h] BYREF
  char v46; // [sp+6Ch] [-10C4h] BYREF
  idMat3 v47; // [sp+70h] [-10C0h] BYREF
  va v48; // [sp+A0h] [-1090h] BYREF

  v8 = 0;
  if ( this->pieces.num > 0 )
  {
    v9 = 0;
    do
    {
      if ( single < 0 || v8 == single )
      {
        v10 = &v46;
        list = this->pieces.list;
        rigidBody = list[v9].rigidBody;
        v13 = 9;
        y = rigidBody->currentState.position.y;
        z = rigidBody->currentState.position.z;
        traceModelIndex = rigidBody->properties->traceModelIndex;
        v45.x = rigidBody->currentState.position.x;
        v45.y = y;
        v45.z = z;
        p_z = (idEffectPhysicsRigidBody *)&list[v9].rigidBody->currentState.position.z;
        do
        {
          p_z = (idEffectPhysicsRigidBody *)((char *)p_z + 4);
          v10 += 4;
          *(_DWORD *)v10 = p_z->properties;
          --v13;
        }
        while ( v13 != 0 );
        if ( !list[v9].rigidBody->active )
        {
          v18 = offset->y;
          v19 = (float)((float)(axis->mat[0].y * v45.x)
                      + (float)((float)(axis->mat[1].y * v45.y) + (float)(axis->mat[2].y * v45.z)));
          v20 = (float)(offset->x
                      + (float)((float)(axis->mat[0].x * v45.x)
                              + (float)((float)(axis->mat[1].x * v45.y) + (float)(axis->mat[2].x * v45.z))));
          v45.z = offset->z
                + (float)((float)(axis->mat[0].z * v45.x)
                        + (float)((float)(axis->mat[1].z * v45.y) + (float)(axis->mat[2].z * v45.z)));
          v45.x = v20;
          v45.y = (float)v18 + (float)v19;
          idMat3::operator*=(this: &v47, a: axis);
        }
        idCollisionModelManager::DrawCollisionModel(
          this: collisionModelManager,
          model: this->broadPhase.traceModelCache->cache.list[traceModelIndex]->collisionModel,
          modelJoints: nullptr,
          modelOrigin: &v45,
          modelAxis: &v47,
          viewOrigin: &vec3_origin,
          viewAxis: &mat3_identity,
          radius: 0.0,
          lifeTime: 4 * traceModelIndex,
          a10: v26,
          a11: v27,
          a12: v28,
          a13: v29,
          a14: v30,
          a15: v31,
          a16: v32,
          a17: v33,
          a18: v34,
          a19: v35,
          a20: v36,
          a21: v37,
          a22: v38,
          a23: v39,
          a24: v40,
          a25: v41,
          a26: v42,
          a27: v43,
          a28: v44,
          a29: 0);
        if ( common->RW(this: common) != nullptr )
        {
          v21 = common->RW(this: common);
          HIDWORD(v22) = v8 + 1;
          v25 = va::va(
                  this: &v48,
                  fmt: "%d",
                  a3: v22,
                  a4: v24,
                  a5: v23,
                  a6: v26,
                  a7: v27,
                  a8: v28,
                  a9: v29,
                  a10: v30,
                  a11: v31);
          ((void (__fastcall *)(idRenderWorld *, va *, idVec3 *, void (__fastcall *)(idRenderWorld *, const char *, const idVec3 *, float, const idVec4 *, const int, const int, const bool, const bool), idColor *, int, _DWORD, _DWORD, double))v21->DebugText)(
            a1: v21,
            a2: v25,
            a3: &v45,
            a4: v21->DebugText,
            a5: &idColor::colorWhite,
            a6: 1,
            a7: 0,
            a8: 0,
            a9: 0.1);
        }
      }
      ++v8;
      ++v9;
    }
    while ( v8 < this->pieces.num );
  }
}


// ========================================================================
// ?GetPropertiesForTraceModel@idEffectPhysicsPieceEmitter@@AAAPAVidEffectPhysicsProperties@@ABVidTraceModel@@@Z
// EA  : 0x82705CD0
// RVA : 0x00705CD0
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicspieceemitter.cpp
// ========================================================================

idEffectPhysicsProperties *__fastcall idEffectPhysicsPieceEmitter::GetPropertiesForTraceModel(
        idEffectPhysicsPieceEmitter *this,
        const idTraceModel *trm)
{
  int v3; // r3
  int v4; // r28
  encounterGroupRole_t v5; // r10
  idEffectPhysicsProperties **list; // r8
  int v7; // r11
  idEffectPhysicsProperties *v8; // r3
  idEffectPhysicsProperties *v9; // r30
  double pieceMass; // fp1
  const idDeclBreakable *decl; // r10
  const idDeclBreakable *v13; // r11
  encounterGroupRole_t v14[12]; // [sp+50h] [-30h] BYREF

  v3 = idTraceModelCache::AllocTraceModel(
         this: this->broadPhase.traceModelCache,
         trm,
         material: this->model->surfaces.list->material);
  v4 = v3;
  v5 = ROLE_NONE;
  v14[0] = (encounterGroupRole_t)this->properties.num;
  if ( v14[0] <= ROLE_NONE )
  {
LABEL_5:
    v8 = (idEffectPhysicsProperties *)idMem::AllocWithLocation(
                                        this: &mem,
                                        location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                        size: 0xA0u,
                                        tag: TAG_FXPHYSICS,
                                        zeroBuffer: false,
                                        align: ALIGN_16,
                                        heap: HEAP_DEFAULTHEAP);
    v14[0] = (encounterGroupRole_t)v8;
    if ( v8 != nullptr )
      v9 = idEffectPhysicsProperties::idEffectPhysicsProperties(this: v8);
    else
      v9 = nullptr;
    pieceMass = this->pieceMass;
    v14[0] = (encounterGroupRole_t)v9;
    idEffectPhysicsProperties::Setup(this: v9, broadPhase: &this->broadPhase, traceModelIndex: v4, mass: pieceMass);
    decl = this->decl;
    v14[1] = (encounterGroupRole_t)&v9->gravityVector;
    v9->linearFriction = decl->settings.linearFriction;
    v9->angularFriction = this->decl->settings.angularFriction;
    v9->contactFriction = this->decl->settings.contactFriction;
    v9->linearFrictionWater = this->decl->settings.linearFrictionWater;
    v9->angularFrictionWater = this->decl->settings.angularFrictionWater;
    v9->bouncyness = this->decl->settings.bouncyness;
    v13 = this->decl;
    v9->gravityVector.x = v13->settings.gravityVector.x;
    v9->gravityVector.y = v13->settings.gravityVector.y;
    v9->gravityVector.z = v13->settings.gravityVector.z;
    v9->worldCollisionOnly = this->decl->settings.worldCollisionOnly;
    v9->simplePointCollision = this->decl->settings.simplePointCollision;
    v9->crazyBounceChance = this->decl->settings.crazyBounceChance;
    v9->stopSpeed = this->decl->settings.stopSpeed;
    v9->maxLinearVelocity = this->decl->settings.maxLinearVelocity;
    v9->maxAngularVelocity = this->decl->settings.maxAngularVelocity;
    v9->clipMask = this->decl->settings.clipMask;
    idList<idAnimWebBlendTree *,5>::Append((idList<enum encounterGroupRole_t,5> *)this, obj: v14);
    return v9;
  }
  else
  {
    list = this->properties.list;
    v7 = 0;
    while ( list[v7]->traceModelIndex != v3 )
    {
      ++v5;
      ++v7;
      if ( v5 >= v14[0] )
        goto LABEL_5;
    }
    return list[v5];
  }
}


// ========================================================================
// __unwind$248034
// EA  : 0x82705E78
// RVA : 0x00705E78
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicspieceemitter.cpp
// ========================================================================

void _unwind_248034()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_FXPHYSICS);
}


// ========================================================================
// ??0idEffectPhysicsPieceEmitter@@QAA@XZ
// EA  : 0x82705F18
// RVA : 0x00705F18
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicspieceemitter.cpp
// ========================================================================

idEffectPhysicsPieceEmitter *__fastcall idEffectPhysicsPieceEmitter::idEffectPhysicsPieceEmitter(
        idEffectPhysicsPieceEmitter *this)
{
  this->properties.list = nullptr;
  this->properties.granularity = 0;
  this->properties.memTag = 59;
  this->properties.listStatic = 0;
  this->properties.size = 0;
  this->properties.num = 0;
  idList<idThread *,58>::Clear((idList<idVehicleState *,5> *)this);
  this->pieces.granularity = 0;
  this->pieces.memTag = 59;
  this->pieces.listStatic = 0;
  this->pieces.list = nullptr;
  this->pieces.size = 0;
  this->pieces.num = 0;
  idEffectPhysicsBroadPhase::idEffectPhysicsBroadPhase(this: &this->broadPhase);
  this->random.seed = 0;
  this->model = nullptr;
  this->decl = nullptr;
  this->modelEffects = nullptr;
  this->pieceMass = 10.0;
  this->pieceCollisionAgeDecay = 0.0;
  this->pieceCollisionVolumeDecay = 0.0;
  this->soundInfo.soundWorld = nullptr;
  this->soundInfo.minBounceVelSqr = 0.0;
  this->soundInfo.impactTable = nullptr;
  this->soundInfo.nextSoundTime = 0;
  this->pieceFriction = 0.0;
  this->pieceLifeTime = 0;
  this->pieceIndex = 0;
  this->numPiecesInUse = 0;
  this->hidden = false;
  this->hiddenOverride = false;
  return this;
}


// ========================================================================
// __unwind$248301
// EA  : 0x82705FEC
// RVA : 0x00705FEC
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicspieceemitter.cpp
// ========================================================================

void _unwind_248301()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: *(idStaticList<idVehicleState *,4> **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$248302
// EA  : 0x82706014
// RVA : 0x00706014
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicspieceemitter.cpp
// ========================================================================

void _unwind_248302()
{
  int v0; // r12

  idList<idEffectPhysicsPieceEmitter::idBreakablePiece,59>::~idList<idEffectPhysicsPieceEmitter::idBreakablePiece,59>(this: (idList<idEffectPhysicsPieceEmitter::idBreakablePiece,59> *)(*(_DWORD *)(v0 - 128 + 148) + 16));
}


// ========================================================================
// ??1idEffectPhysicsPieceEmitter@@QAA@XZ
// EA  : 0x82706048
// RVA : 0x00706048
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicspieceemitter.cpp
// ========================================================================

void __fastcall idEffectPhysicsPieceEmitter::~idEffectPhysicsPieceEmitter(idEffectPhysicsPieceEmitter *this)
{
  int v2; // r28
  int v3; // r29
  idRenderModelDiscreteAnimation *model; // r3
  idEffectPhysicsPieceEmitter::idBreakablePiece *list; // r3
  idEffectPhysicsPieceEmitter::idBreakablePiece *v6; // r3

  if ( this->model != nullptr )
  {
    v2 = 0;
    if ( this->properties.num > 0 )
    {
      v3 = 0;
      do
      {
        idTraceModelCache::FreeTraceModel(
          this: this->broadPhase.traceModelCache,
          traceModelIndex: this->properties.list[v3]->traceModelIndex);
        ++v2;
        ++v3;
      }
      while ( v2 < this->properties.num );
    }
    model = this->model;
    model->unlinked = true;
    model->deleteOnSync = true;
    idRenderModel::CommitThisFrame(this: model);
  }
  if ( this->pieces.listStatic == 0 || this->pieces.listStatic == 2 )
  {
    list = this->pieces.list;
    if ( list != nullptr )
      idListArrayDelete<idEffectPhysicsPieceEmitter::idBreakablePiece>(ptr: &list->rigidBody, num: this->pieces.size);
    this->pieces.list = nullptr;
    this->pieces.size = 0;
  }
  this->pieces.num = 0;
  idList<idEffectPhysicsProperties *,59>::DeleteContents(this: &this->properties);
  idEffectPhysicsBroadPhase::~idEffectPhysicsBroadPhase(this: &this->broadPhase);
  if ( this->pieces.listStatic == 0 || this->pieces.listStatic == 2 )
  {
    v6 = this->pieces.list;
    if ( v6 != nullptr )
      idListArrayDelete<idEffectPhysicsPieceEmitter::idBreakablePiece>(ptr: &v6->rigidBody, num: this->pieces.size);
    this->pieces.list = nullptr;
    this->pieces.size = 0;
  }
  this->pieces.num = 0;
  if ( this->properties.listStatic == 0 || this->properties.listStatic == 2 )
  {
    if ( this->properties.list != nullptr )
      idMem::Free(this: &mem, ptr: this->properties.list, align: ALIGN_16);
    this->properties.list = nullptr;
    this->properties.size = 0;
  }
  this->properties.num = 0;
}


// ========================================================================
// __unwind$248352
// EA  : 0x82706180
// RVA : 0x00706180
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicspieceemitter.cpp
// ========================================================================

void _unwind_248352()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: *(idStaticList<idVehicleState *,4> **)(v0 - 144 + 164));
}


// ========================================================================
// __unwind$248353
// EA  : 0x827061A8
// RVA : 0x007061A8
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicspieceemitter.cpp
// ========================================================================

void _unwind_248353()
{
  int v0; // r12

  idList<idEffectPhysicsPieceEmitter::idBreakablePiece,59>::~idList<idEffectPhysicsPieceEmitter::idBreakablePiece,59>(this: (idList<idEffectPhysicsPieceEmitter::idBreakablePiece,59> *)(*(_DWORD *)(v0 - 144 + 164) + 16));
}


// ========================================================================
// __unwind$248354
// EA  : 0x827061D4
// RVA : 0x007061D4
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicspieceemitter.cpp
// ========================================================================

void _unwind_248354()
{
  int v0; // r12

  idEffectPhysicsBroadPhase::~idEffectPhysicsBroadPhase(this: (idEffectPhysicsBroadPhase *)(*(_DWORD *)(v0 - 144 + 164)
                                                                                          + 32));
}


// ========================================================================
// ?Init@idEffectPhysicsPieceEmitter@@QAAXPAVidClip@@PAVidTraceModelCache@@PAVidRenderModelDiscreteAnimation@@PAVidRenderModelEffects@@PAUpieceEmitterSound_t@1@H@Z
// EA  : 0x82706208
// RVA : 0x00706208
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicspieceemitter.cpp
// ========================================================================

void __fastcall idEffectPhysicsPieceEmitter::Init(
        idEffectPhysicsPieceEmitter *this,
        idClip *clip,
        idTraceModelCache *tmc,
        idRenderModelDiscreteAnimation *model,
        idRenderModelEffects *modelEffects,
        idEffectPhysicsPieceEmitter::pieceEmitterSound_t *soundInfo,
        int entNum)
{
  const idDeclBreakable *declBreakable; // r11
  idList<idEffectPhysicsPieceEmitter::idBreakablePiece,59> *p_pieces; // r22
  int num; // r30
  int size; // r11
  int v16; // r23
  int v17; // r25
  float *p_z; // r10
  int v19; // ctr
  idSysMutex *p_viewNoteMutex; // r11
  const idEffectPhysicsProperties *PropertiesForTraceModel; // r29
  idEffectPhysicsRigidBody *v22; // r3
  idEffectPhysicsRigidBody *v23; // r30
  double y; // fp13
  double z; // fp12
  double mass; // fp2
  double x; // fp3
  double v28; // fp1
  double v29; // fp0
  double v30; // fp12
  double v31; // fp10
  idVec3 v32[2]; // [sp+58h] [-6E8h] BYREF
  idMat3 v33; // [sp+70h] [-6D0h] BYREF
  idTraceModel v34; // [sp+A0h] [-6A0h] BYREF

  idEffectPhysicsBroadPhase::Init(this: &this->broadPhase, clip, tmc);
  this->model = model;
  declBreakable = model->declBreakable;
  this->modelEffects = modelEffects;
  this->decl = declBreakable;
  if ( soundInfo != nullptr )
  {
    this->soundInfo.soundWorld = soundInfo->soundWorld;
    this->soundInfo.impactTable = soundInfo->impactTable;
    this->soundInfo.nextSoundTime = soundInfo->nextSoundTime;
    this->soundInfo.minBounceVelSqr = soundInfo->minBounceVelSqr;
  }
  this->pieceIndex = 0;
  this->numPiecesInUse = 0;
  idList<idEffectPhysicsProperties *,59>::DeleteContents(this: &this->properties);
  p_pieces = &this->pieces;
  num = model->transforms.num;
  if ( num <= this->pieces.size
    || (unsigned __int8)idList<idEffectPhysicsPieceEmitter::idBreakablePiece,59>::Resize(
                          this: &this->pieces,
                          newsize: model->transforms.num) != 0 )
  {
    size = this->pieces.size;
    if ( num < size )
      size = num;
    this->pieces.num = size;
  }
  v16 = 0;
  if ( model->transforms.num > 0 )
  {
    v17 = 0;
    do
    {
      v34.offset.x = 0.0;
      p_z = &v34.offset.z;
      v34.offset.y = 0.0;
      v34.offset.z = 0.0;
      memset(&v34.type, 0, 20);
      v19 = 6;
      p_viewNoteMutex = &analysisClient.viewNoteMutex;
      do
      {
        ++p_viewNoteMutex;
        *++p_z = *(float *)&p_viewNoteMutex->handle;
        --v19;
      }
      while ( v19 != 0 );
      v34.radius = 0.0;
      v34.isConvex = false;
      v34.pad[2] = 0;
      v34.pad[1] = 0;
      v34.pad[0] = 0;
      idRenderModelDiscreteAnimation::GetPiecePosition(this: model, index: v16, position: v32, orientation: &v33);
      idRenderModelDiscreteAnimation::GetPieceTraceModel(this: model, index: v16, traceModel: &v34);
      idTraceModel::Shrink(this: &v34, m: 0.1875);
      PropertiesForTraceModel = idEffectPhysicsPieceEmitter::GetPropertiesForTraceModel(this, trm: &v34);
      v22 = (idEffectPhysicsRigidBody *)idMem::AllocWithLocation(
                                          this: &mem,
                                          location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                          size: 0x110u,
                                          tag: TAG_FXPHYSICS,
                                          zeroBuffer: false,
                                          align: ALIGN_16,
                                          heap: HEAP_DEFAULTHEAP);
      if ( v22 != nullptr )
        v23 = idEffectPhysicsRigidBody::idEffectPhysicsRigidBody(this: v22);
      else
        v23 = nullptr;
      idEffectPhysicsRigidBody::Setup(this: v23, props: PropertiesForTraceModel);
      v23->currentState.position = v32[0];
      idEffectPhysicsBroadPhase::SetObjectPosition(
        this: v23->properties->broadPhase,
        object: &v23->SPObject,
        origin: &v23->currentState.position,
        axis: &v23->currentState.orientation,
        bounds: nullptr);
      v23->currentState.orientation = v33;
      idEffectPhysicsBroadPhase::SetObjectPosition(
        this: v23->properties->broadPhase,
        object: &v23->SPObject,
        origin: &v23->currentState.position,
        axis: &v23->currentState.orientation,
        bounds: nullptr);
      y = vec3_origin.y;
      z = vec3_origin.z;
      mass = v23->properties->mass;
      v23->currentState.linearMomentum.x = v23->properties->mass * vec3_origin.x;
      v23->currentState.linearMomentum.y = (float)mass * (float)y;
      v23->currentState.linearMomentum.z = (float)mass * (float)z;
      x = v23->properties->inertiaTensor.mat[0].x;
      v28 = v23->properties->inertiaTensor.mat[0].z;
      v29 = vec3_origin.x;
      v30 = (float)((float)(v23->properties->inertiaTensor.mat[1].x * vec3_origin.y)
                  + (float)(v23->properties->inertiaTensor.mat[2].x * vec3_origin.z));
      ++v16;
      v31 = (float)((float)(v23->properties->inertiaTensor.mat[1].z * vec3_origin.y)
                  + (float)(v23->properties->inertiaTensor.mat[2].z * vec3_origin.z));
      v23->currentState.angularMomentum.y = (float)(v23->properties->inertiaTensor.mat[0].y * vec3_origin.x)
                                          + (float)((float)(v23->properties->inertiaTensor.mat[1].y * vec3_origin.y)
                                                  + (float)(v23->properties->inertiaTensor.mat[2].y * vec3_origin.z));
      v23->currentState.angularMomentum.x = (float)((float)x * (float)v29) + (float)v30;
      v23->currentState.angularMomentum.z = (float)((float)v28 * (float)v29) + (float)v31;
      v23->SPObject.entityNum = entNum;
      p_pieces->list[v17].rigidBody = v23;
      p_pieces->list[v17].emitTime = 0;
      p_pieces->list[v17++].firstCollisionTime = 0;
    }
    while ( v16 < model->transforms.num );
  }
}


// ========================================================================
// __unwind$248467
// EA  : 0x8270658C
// RVA : 0x0070658C
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicspieceemitter.cpp
// ========================================================================

void _unwind_248467()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 1856 + 80), tag: TAG_FXPHYSICS);
}


// ========================================================================
// ?UpdateSimulation@idEffectPhysicsPieceEmitter@@QAAXABVidVec3@@ABVidMat3@@HH@Z
// EA  : 0x827065C0
// RVA : 0x007065C0
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicspieceemitter.cpp
// ========================================================================

void __fastcall idEffectPhysicsPieceEmitter::UpdateSimulation(
        idEffectPhysicsPieceEmitter *this,
        const idVec3 *origin,
        const idMat3 *axis,
        signed int currentTime,
        const char *gameMsPerFrame)
{
  unsigned __int64 v7; // r6
  idEffectPhysicsCollision *ImpactSoundForMaterial; // r4
  _BYTE v10[12]; // r10
  int v11; // r24
  double v12; // fp30
  int v13; // r27
  idEffectPhysicsPieceEmitter::idBreakablePiece *v14; // r30
  idEffectPhysicsRigidBody *rigidBody; // r3
  int v16; // r11
  idRenderModelDiscreteAnimation *model; // r30
  int firstCollisionTime; // r11
  double v19; // fp0
  double v20; // fp13
  double pieceCollisionAgeDecay; // fp0
  float *v22; // r11
  double v23; // fp12
  double v24; // fp0
  double v25; // fp13
  idDeclImpactSound *impactTable; // r3
  __int64 v27; // r9
  double pieceCollisionVolumeDecay; // fp0
  double v29; // fp1
  float *v30; // r30
  float *v31; // r11
  double v32; // fp13
  double v33; // fp12
  double v34; // fp1
  double v35; // fp11
  double v36; // fp7
  double v37; // fp9
  float *v39; // r11
  double v41; // fp1
  double v42; // fp0
  double v43; // fp13
  double v44; // fp12
  double v45; // fp11
  double v46; // fp6
  double v47; // fp5
  idPLog *pLog; // r29
  idPLog::logEntry_t *v49; // r30
  int v50; // r3
  __int64 totalTicks; // r11
  __int64 v52; // r9
  idPLogScope v53[5]; // [sp+58h] [-B8h] BYREF
  idVec3 v54; // [sp+80h] [-90h] BYREF
  float v55; // [sp+90h] [-80h]
  float v56; // [sp+94h] [-7Ch]
  float v57; // [sp+98h] [-78h]

  LODWORD(v7) = "idEffectPhysicsPieceEmitter::UpdateSimulation";
  HIDWORD(v7) = 1;
  idPLogScope::idPLogScope(this: v53, pl: &::pLog, gMask: v7, label: gameMsPerFrame);
  *(_DWORD *)&v10[4] = gameMsPerFrame;
  *(_DWORD *)v10 = this->pieces.num;
  v11 = 0;
  v12 = (float)((float)*(__int64 *)v10 * (float)0.001);
  if ( *(int *)v10 > 0 )
  {
    *(_DWORD *)&v10[4] = 0x82000000;
    v13 = 0;
    do
    {
      v14 = &this->pieces.list[v13];
      rigidBody = v14->rigidBody;
      if ( v14->rigidBody->active )
      {
        *(_DWORD *)&v10[8] = this->pieceLifeTime;
        if ( currentTime < *(_DWORD *)&v10[8] + v14->emitTime )
        {
          firstCollisionTime = v14->firstCollisionTime;
          v19 = 0.0;
          if ( firstCollisionTime > 0 )
          {
            v53[1] = *(idPLogScope *)&v10[4];
            v20 = (float)*(__int64 *)&v10[4];
            if ( v20 > 0.0 )
            {
              pieceCollisionAgeDecay = this->pieceCollisionAgeDecay;
              *(_DWORD *)&v10[4] = firstCollisionTime;
              v53[2] = *(idPLogScope *)v10;
              v53[3] = (idPLogScope)__PAIR64__(firstCollisionTime, currentTime);
              v19 = (float)((float)((float)((float)__SPAIR64__(firstCollisionTime, currentTime) - (float)*(__int64 *)v10)
                                  * (float)pieceCollisionAgeDecay)
                          / (float)v20);
              if ( v19 >= 0.0 )
              {
                if ( v19 > 1.0 )
                  v19 = 1.0;
              }
              else
              {
                v19 = 0.0;
              }
            }
          }
          idEffectPhysicsRigidBody::Update(
            this: rigidBody,
            deltaTime: v12,
            extraMomentumDecay: v19,
            collision: ImpactSoundForMaterial);
          v22 = (float *)v14->rigidBody;
          *(_DWORD *)&v10[4] = v14->rigidBody->settled;
          if ( !v14->rigidBody->settled )
          {
            *(_DWORD *)&v10[4] = &v14->collision.collisionNormalVelocity;
            *(float *)v10 = v14->collision.collisionNormalVelocity.y;
            ImpactSoundForMaterial = (idEffectPhysicsCollision *)((LODWORD(v14->collision.collisionNormalVelocity.z)
                                                                 | *(_DWORD *)v10
                                                                 | LODWORD(v14->collision.collisionNormalVelocity.x))
                                                                & 0x7FFFFFFF);
            if ( ImpactSoundForMaterial != nullptr )
            {
              if ( v14->firstCollisionTime == 0 )
                v14->firstCollisionTime = currentTime;
              if ( this->soundInfo.soundWorld != nullptr )
              {
                impactTable = this->soundInfo.impactTable;
                if ( impactTable != nullptr && currentTime >= this->soundInfo.nextSoundTime )
                {
                  v25 = (float)((float)(v22[14] * *(float *)(*(_DWORD *)v22 + 60))
                              - (float)(*(float *)(*(_DWORD *)v22 + 40) * (float)v12));
                  v23 = (float)((float)(v22[13] * *(float *)(*(_DWORD *)v22 + 60))
                              - (float)((float)v12 * *(float *)(*(_DWORD *)v22 + 36)));
                  v24 = (float)((float)(v22[15] * *(float *)(*(_DWORD *)v22 + 60))
                              - (float)(*(float *)(*(_DWORD *)v22 + 44) * (float)v12));
                  if ( (float)((float)((float)v23 * (float)v23)
                             + (float)((float)((float)v24 * (float)v24) + (float)((float)v25 * (float)v25))) > (double)this->soundInfo.minBounceVelSqr )
                  {
                    ImpactSoundForMaterial = (idEffectPhysicsCollision *)idDeclImpactSound::GetImpactSoundForMaterial(
                                                                           this: impactTable,
                                                                           materialID: v14->collision.collisionSurfaceType);
                    if ( ImpactSoundForMaterial != nullptr )
                    {
                      pieceCollisionVolumeDecay = this->pieceCollisionVolumeDecay;
                      v29 = 0.0;
                      if ( pieceCollisionVolumeDecay > 0.0 )
                      {
                        LODWORD(v27) = currentTime - v14->firstCollisionTime;
                        v53[4] = (idPLogScope)v27;
                        v29 = -(float)((float)((float)v27 * (float)pieceCollisionVolumeDecay) * (float)0.001);
                      }
                      this->soundInfo.soundWorld->PlayPositionedShaderDirectly(
                        this: this->soundInfo.soundWorld,
                        a2: (const idSoundShader *)ImpactSoundForMaterial,
                        a3: (const idVec3 *)&v14->rigidBody->currentState,
                        a4: &mat3_identity,
                        a5: v29);
                      this->soundInfo.nextSoundTime = this->soundInfo.impactTable->soundInterval + currentTime;
                    }
                  }
                }
              }
              v30 = (float *)v14->rigidBody;
              v31 = *(float **)v30;
              v32 = v30[16];
              v33 = v30[18];
              v34 = *(float *)(*(_DWORD *)v30 + 140);
              v35 = *(float *)(*(_DWORD *)v30 + 112);
              v36 = (float)((float)(v31[31] * v30[17]) + (float)(v31[34] * v30[18]));
              v37 = (float)((float)(v31[29] * v30[16]) + (float)(v31[32] * v30[17]));
              v57 = (float)(v31[36] * v30[18]) + (float)((float)(v31[30] * v30[16]) + (float)(v31[33] * v30[17]));
              *(float *)&v10[4] = v57;
              v55 = (float)((float)v32 * (float)v35) + (float)v36;
              v56 = (float)((float)v34 * (float)v33) + (float)v37;
              *(_DWORD *)v10 = LODWORD(v55) | LODWORD(v56);
              if ( (COERCE_UNSIGNED_INT(fabs(v55)) | COERCE_UNSIGNED_INT(fabs(v56)) | LODWORD(v57) & 0x7FFFFFFF) != 0 )
              {
                v54.x = (float)((float)v32 * (float)v35) + (float)v36;
                v54.y = (float)((float)v34 * (float)v33) + (float)v37;
                v54.z = v57;
                _FP13 = (float)-(float)((float)(this->pieceFriction * (float)v12) - idVec3::NormalizeFast(this: &v54));
                v39 = *(float **)v30;
                __asm { fsel      f5, f13, f13, f31 }
                v41 = *(float *)(*(_DWORD *)v30 + 108);
                v42 = *(float *)(*(_DWORD *)v30 + 104);
                v43 = (float)(v54.z * (float)_FP5);
                v44 = (float)(v54.y * (float)_FP5);
                v46 = (float)((float)(v39[21] * (float)(v54.x * (float)_FP5))
                            + (float)(v39[24] * (float)(v54.y * (float)_FP5)));
                v45 = (float)(v54.x * (float)_FP5);
                v47 = (float)((float)(v39[20] * (float)(v54.x * (float)_FP5))
                            + (float)(v39[23] * (float)(v54.y * (float)_FP5)));
                v30[16] = (float)(*(float *)(*(_DWORD *)v30 + 76) * (float)v45)
                        + (float)((float)(*(float *)(*(_DWORD *)v30 + 88) * (float)v44)
                                + (float)(*(float *)(*(_DWORD *)v30 + 100) * (float)v43));
                v30[18] = (float)((float)v41 * (float)v43) + (float)v46;
                v30[17] = (float)((float)v42 * (float)v43) + (float)v47;
              }
            }
          }
        }
        else
        {
          v14->firstCollisionTime = 0;
          v14->emitTime = 0;
          rigidBody->active = false;
          v16 = this->numPiecesInUse - 1;
          this->numPiecesInUse = v16;
          if ( v16 == 0 )
          {
            model = this->model;
            this->hiddenOverride = true;
            if ( model != nullptr && !model->unlinked )
            {
              idRenderModel::CommitThisFrame(this: model);
              model->unlinked = true;
            }
          }
        }
      }
      ++v11;
      ++v13;
    }
    while ( v11 < this->pieces.num );
  }
  if ( v53[0].logIndex >= 0 )
  {
    pLog = v53[0].pLog;
    v49 = &v53[0].pLog->logEntries.list[v53[0].logIndex];
    v50 = (unsigned __int64)Sys_GetClockTicks() >> 32;
    totalTicks = v49->totalTicks;
    HIDWORD(totalTicks) = v49->parent;
    LODWORD(v52) = v50 - totalTicks;
    v49->totalTicks = v52;
    pLog->lastEntry = HIDWORD(totalTicks);
  }
}


// ========================================================================
// __unwind$248670
// EA  : 0x82706A50
// RVA : 0x00706A50
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicspieceemitter.cpp
// ========================================================================

void _unwind_248670()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 272 + 88));
}

