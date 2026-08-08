
// ========================================================================
// ?Hide@idAnimatedSimplePhysics@@UAAXXZ
// EA  : 0x82C00C88
// RVA : 0x00C00C88
// PDB : w:\tech5\tungsten\game\entities\animatedsimplephysics.cpp
// ========================================================================

void __fastcall idAnimatedSimplePhysics::Hide(idAnimatedSimplePhysics *this)
{
  char idCombatStage_useRelaxedChatterVO; // r31
  int v3; // r29
  int v4; // r31
  idPresentableAnimatedPhysics *presentable; // r3
  idPhysics *Physics; // r3

  idCombatStage_useRelaxedChatterVO = Get_idCombatStage_useRelaxedChatterVO(ptr: this);
  idAnimatedSimple::Hide(this);
  if ( idCombatStage_useRelaxedChatterVO == 0 )
  {
    idEntity::BecomeInactive(this, flags: 4);
    v3 = 0;
    if ( this->collisionParts.num > 0 )
    {
      v4 = 0;
      do
      {
        presentable = this->collisionParts.list[v4].presentable;
        presentable->Hide(this: presentable, a2: true);
        idPresentableDoorAnimated::UnlinkCollision(this: this->collisionParts.list[v4].presentable);
        ++v3;
        ++v4;
      }
      while ( v3 < this->collisionParts.num );
    }
    Physics = idEntity::GetPhysics(this);
    Physics->UnlinkClip(this: Physics);
  }
}


// ========================================================================
// ?Show@idAnimatedSimplePhysics@@UAAXXZ
// EA  : 0x82C00D38
// RVA : 0x00C00D38
// PDB : w:\tech5\tungsten\game\entities\animatedsimplephysics.cpp
// ========================================================================

void __fastcall idAnimatedSimplePhysics::Show(idAnimatedSimplePhysics *this)
{
  char idCombatStage_useRelaxedChatterVO; // r31
  int v3; // r29
  int v4; // r31
  idPresentableAnimatedPhysics *presentable; // r3
  idPhysics *Physics; // r3

  idCombatStage_useRelaxedChatterVO = Get_idCombatStage_useRelaxedChatterVO(ptr: this);
  idAnimatedSimple::Show(this);
  if ( idCombatStage_useRelaxedChatterVO != 0 )
  {
    idEntity::BecomeActive(this, flags: 4);
    v3 = 0;
    if ( this->collisionParts.num > 0 )
    {
      v4 = 0;
      do
      {
        presentable = this->collisionParts.list[v4].presentable;
        presentable->Show(this: presentable);
        idPresentableAnimatedPhysics::LinkCollision(this: this->collisionParts.list[v4].presentable);
        ++v3;
        ++v4;
      }
      while ( v3 < this->collisionParts.num );
    }
    Physics = idEntity::GetPhysics(this);
    Physics->LinkClip(this: Physics);
  }
}


// ========================================================================
// ??0idAnimPhysicsPiece@@QAA@XZ
// EA  : 0x82C00DE8
// RVA : 0x00C00DE8
// PDB : w:\tech5\tungsten\game\entities\animatedsimplephysics.cpp
// ========================================================================

idAnimPhysicsPiece *__fastcall idAnimPhysicsPiece::idAnimPhysicsPiece(idAnimPhysicsPiece *this)
{
  this->clipModel.str = &byte_8200D768;
  this->joint.allocedAndFlag = 20;
  this->joint.data = this->joint.baseBuffer;
  this->joint.len = 0;
  this->joint.baseBuffer[0] = 0;
  this->entity.spawnId.value = 0x1FFF;
  this->isObstacle = false;
  this->jointIndex.value = -1;
  this->presentable = nullptr;
  return this;
}


// ========================================================================
// ?UpdateCollisionParts@idAnimatedSimplePhysics@@AAAXAAVidBounds@@_N@Z
// EA  : 0x82C00E30
// RVA : 0x00C00E30
// PDB : w:\tech5\tungsten\game\entities\animatedsimplephysics.cpp
// ========================================================================

void __fastcall idAnimatedSimplePhysics::UpdateCollisionParts(
        idAnimatedSimplePhysics *this,
        idBounds *bounds,
        bool push)
{
  idTreeAnimator *TreeAnimatorFromPresentable; // r17
  idPresentable *presentable; // r3
  int v8; // r23
  int i; // r25
  idAnimPhysicsPiece *v10; // r11
  idPresentableAnimatedPhysics *v11; // r29
  int value; // r9
  bool v13; // r27
  idEntity *v14; // r3
  idEntity *v15; // r3
  idEntity *v16; // r31
  double v17; // fp1
  idPhysics *Physics; // r3
  float *v19; // r3
  idPhysics *v20; // r3
  float *v21; // r3
  idAnimPhysicsPiece *v22; // r11
  const char *v23; // r3
  idAnimPhysicsPiece *v24; // r11
  const char *data; // r31
  __int16 v26; // r15
  const char *EntityDefName; // r3
  float *v28; // r11
  int v29; // r31
  float *v30; // r3
  double y; // fp1
  double z; // fp0
  double x; // fp13
  double v35; // fp12
  double v36; // fp9
  idVec3 v48; // [sp+50h] [-150h] BYREF
  idMat3 v49; // [sp+60h] [-140h] BYREF
  trace_t v50[2]; // [sp+90h] [-110h] BYREF

  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
  if ( TreeAnimatorFromPresentable != nullptr )
  {
    presentable = this->presentable;
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      presentable = this->presentable;
    }
    idPresentable::UpdateModelTransform(this: presentable);
    v8 = 0;
    bounds->b[0].z = 1.0e30;
    bounds->b[0].y = 1.0e30;
    bounds->b[0].x = 1.0e30;
    bounds->b[1].z = -1.0e30;
    bounds->b[1].y = -1.0e30;
    bounds->b[1].x = -1.0e30;
    if ( this->collisionParts.num > 0 )
    {
      for ( i = 0; ; ++i )
      {
        v10 = &this->collisionParts.list[i];
        v11 = v10->presentable;
        if ( v11 != nullptr )
          break;
LABEL_28:
        if ( ++v8 >= this->collisionParts.num )
          return;
      }
      value = v10->entity.spawnId.value;
      v13 = false;
      if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
      {
        v14 = gameLocal->entities.ptr[value & 0x1FFF];
        if ( v14 != nullptr )
        {
          v15 = idEntity::CastTo(c: v14);
          v16 = v15;
          if ( v15 != nullptr )
          {
            if ( idEntity::GetPhysics(this: v15) != nullptr )
            {
              Physics = idEntity::GetPhysics(this: v16);
              v19 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
              v48.x = *v19;
              v48.y = v19[1];
              v48.z = v19[2];
              v20 = idEntity::GetPhysics(this: v16);
              v21 = (float *)v20->GetAxis(this: v20, a2: 0);
              v13 = push;
              v49.mat[0].x = *v21;
              v49.mat[0].y = v21[1];
              v49.mat[0].z = v21[2];
              v49.mat[1].x = v21[3];
              v49.mat[1].y = v21[4];
              v49.mat[1].z = v21[5];
              v49.mat[2].x = v21[6];
              v49.mat[2].y = v21[7];
              v49.mat[2].z = v21[8];
            }
            else
            {
              v13 = push;
              v48.x = v16->spawnPosition.x;
              v48.y = v16->spawnPosition.y;
              v48.z = v16->spawnPosition.z;
              v49.mat[0].x = v16->spawnOrientation.mat[0].x;
              v49.mat[0].y = v16->spawnOrientation.mat[0].y;
              v49.mat[0].z = v16->spawnOrientation.mat[0].z;
              v49.mat[1].x = v16->spawnOrientation.mat[1].x;
              v49.mat[1].y = v16->spawnOrientation.mat[1].y;
              v49.mat[1].z = v16->spawnOrientation.mat[1].z;
              v49.mat[2].x = v16->spawnOrientation.mat[2].x;
              v49.mat[2].y = v16->spawnOrientation.mat[2].y;
              v49.mat[2].z = v16->spawnOrientation.mat[2].z;
            }
            goto LABEL_23;
          }
        }
      }
      v22 = &this->collisionParts.list[i];
      if ( (unsigned __int16)v22->jointIndex.value >= 0x8000u )
      {
        v24 = &this->collisionParts.list[i];
        data = v24->joint.data;
        v26 = v24->jointIndex.value;
        EntityDefName = idEntity::GetEntityDefName(this);
        idLib::Warning(
          fmt: "idAnimatedSimplePhysics::UpdateCollisionParts piece %d of entity %s at invalid joint %d from joint name %s",
          v8,
          EntityDefName,
          v26,
          data);
      }
      else
      {
        if ( (unsigned __int8)idTreeAnimator::GetWorldSpaceAttachmentTransform(
                                this: TreeAnimatorFromPresentable,
                                jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)v22->jointIndex.value,
                                translationOffset: &vec3_origin,
                                rotationOffset: (idMat3 *)&quat_identity,
                                origin: &v48,
                                axis: &v49) != 0 )
        {
          v13 = push;
LABEL_23:
          if ( v13 )
          {
            v29 = 0;
            if ( this->crush )
              v29 = 16;
            idPush::InitSavingPushedPhysicsObjectState(this: &clientGame->push);
            v17 = idPush::ClipPush(
                    this: &clientGame->push,
                    results: v50,
                    pusher: &v11->physicsObj,
                    flags: v29,
                    oldOrigin: &v11->origin,
                    oldAxis: &v11->axis,
                    newOrigin: &v48,
                    newAxis: &v49);
          }
          v11->axis = v49;
          v11->origin = v48;
          ((void (__fastcall *)(idPresentableAnimatedPhysics *, double))v11->Present)(a1: v11, a2: v17);
          v30 = (float *)v11->physicsObj.GetAbsBounds(this: &v11->physicsObj, a2: -1);
          _FP10 = (float)(bounds->b[0].x - *v30);
          y = bounds->b[0].y;
          z = bounds->b[0].z;
          x = bounds->b[1].x;
          v35 = bounds->b[1].y;
          v36 = bounds->b[1].z;
          __asm { fsel      f8, f10, f11, f2 }
          bounds->b[0].x = _FP8;
          _FP6 = (float)((float)y - v30[1]);
          __asm { fsel      f5, f6, f7, f1 }
          bounds->b[0].y = _FP5;
          _FP3 = (float)((float)z - v30[2]);
          __asm { fsel      f2, f3, f4, f0 }
          bounds->b[0].z = _FP2;
          _FP0 = (float)(v30[3] - (float)x);
          __asm { fsel      f13, f0, f1, f13 }
          bounds->b[1].x = _FP13;
          _FP10 = (float)(v30[4] - (float)v35);
          __asm { fsel      f8, f10, f11, f12 }
          bounds->b[1].y = _FP8;
          _FP6 = (float)(v30[5] - (float)v36);
          __asm { fsel      f5, f6, f7, f9 }
          bounds->b[1].z = _FP5;
          goto LABEL_28;
        }
        v23 = idEntity::GetEntityDefName(this);
        idLib::Warning(
          fmt: "idAnimatedSimplePhysics::UpdateCollisionParts piece %d of entity %s couldn't get world space attachment transform",
          v8,
          v23);
      }
      v28 = (float *)this->presentable;
      if ( v28 == nullptr )
      {
        idEntity::InitPresentableInternal(this);
        v28 = (float *)this->presentable;
      }
      v49.mat[0].x = v28[33];
      v49.mat[0].y = v28[34];
      v49.mat[0].z = v28[35];
      v49.mat[1].x = v28[36];
      v49.mat[1].y = v28[37];
      v49.mat[1].z = v28[38];
      v49.mat[2].x = v28[39];
      v49.mat[2].y = v28[40];
      v49.mat[2].z = v28[41];
      if ( v28 == nullptr )
      {
        idEntity::InitPresentableInternal(this);
        v28 = (float *)this->presentable;
      }
      v48.x = v28[30];
      v48.y = v28[31];
      v48.z = v28[32];
      goto LABEL_23;
    }
  }
}


// ========================================================================
// ?Spawn@idAnimatedSimplePhysics@@QAAXXZ
// EA  : 0x82C01300
// RVA : 0x00C01300
// PDB : w:\tech5\tungsten\game\entities\animatedsimplephysics.cpp
// ========================================================================

void __fastcall idAnimatedSimplePhysics::Spawn(idAnimatedSimplePhysics *this)
{
  int v2; // r27
  int v3; // r29
  idAnimPhysicsPiece *v4; // r28
  const char *data; // r21
  idIndex<short,enum invalidJointIndex_t> *TreeAnimatorFromPresentable; // r3
  idPresentableAnimatedPhysics *v7; // r3
  idPresentableAnimatedPhysics *v8; // r3
  idAnimPhysicsPiece *v9; // r28
  const char *Classname; // r3
  int presentable; // r9
  int v12; // r10
  int v13; // r7
  int v14; // [sp+8h] [-D8h]
  int v15; // [sp+Ch] [-D4h]
  int v16; // [sp+10h] [-D0h]
  int v17; // [sp+14h] [-CCh]
  int v18; // [sp+18h] [-C8h]
  idPresentable *v19; // [sp+1Ch] [-C4h]
  _DWORD v20[4]; // [sp+50h] [-90h] BYREF
  idBounds v21[5]; // [sp+60h] [-80h] BYREF

  v2 = 0;
  if ( this->collisionParts.num > 0 )
  {
    v3 = 0;
    do
    {
      if ( idStr::Cmp(s1: this->collisionParts.list[v3].joint.data, s2: &byte_8200D768) != 0
        && idAnimatedEntity::GetTreeAnimatorFromPresentable(this) != nullptr )
      {
        v4 = &this->collisionParts.list[v3];
        v20[1] = v4;
        data = v4->joint.data;
        TreeAnimatorFromPresentable = (idIndex<short,enum invalidJointIndex_t> *)idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
        v4->jointIndex.value = HIWORD(idTreeAnimator::GetJointIndex(
                                        this: (idTreeAnimator *)v20,
                                        result: TreeAnimatorFromPresentable,
                                        jointName: data)->__vftable);
      }
      else
      {
        this->collisionParts.list[v3].jointIndex.value = -1;
      }
      v7 = (idPresentableAnimatedPhysics *)idMem::AllocWithLocation(
                                             this: &mem,
                                             location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                             size: 0x568u,
                                             tag: TAG_PRESENTABLE,
                                             zeroBuffer: false,
                                             align: ALIGN_16,
                                             heap: HEAP_DEFAULTHEAP);
      v20[1] = v7;
      if ( v7 != nullptr )
        v8 = idPresentableAnimatedPhysics::idPresentableAnimatedPhysics(
               this: v7,
               entity: this,
               piece: &this->collisionParts.list[v3]);
      else
        v8 = nullptr;
      this->collisionParts.list[v3].presentable = v8;
      idPresentable::SetEntityNumber(this: this->collisionParts.list[v3].presentable, value: 0x1FFF);
      v9 = &this->collisionParts.list[v3];
      Classname = idClass::GetClassname(this);
      presentable = (int)v9->presentable;
      *(_DWORD *)(presentable + 1088) = Classname;
      idClientGame::AddPresentable(
        this: clientGame,
        presentable: this->collisionParts.list[v3].presentable,
        index: -1,
        skipReplication: false,
        a5: v13,
        a6: (int)&this->collisionParts.list[v3],
        a7: presentable,
        a8: v12,
        a9: v14,
        a10: v15,
        a11: v16,
        a12: v17,
        a13: v18,
        a14: v19);
      ++v2;
      ++v3;
    }
    while ( v2 < this->collisionParts.num );
  }
  idAnimatedSimplePhysics::UpdateCollisionParts(this, bounds: v21, push: false);
}


// ========================================================================
// __unwind$488785
// EA  : 0x82C0147C
// RVA : 0x00C0147C
// PDB : w:\tech5\tungsten\game\entities\animatedsimplephysics.cpp
// ========================================================================

void _unwind_488785()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 224 + 84), tag: TAG_PRESENTABLE);
}


// ========================================================================
// ?Think@idAnimatedSimplePhysics@@UAAXXZ
// EA  : 0x82C014A8
// RVA : 0x00C014A8
// PDB : w:\tech5\tungsten\game\entities\animatedsimplephysics.cpp
// ========================================================================

void __fastcall idAnimatedSimplePhysics::Think(idAnimatedSimplePhysics *this)
{
  idBounds v2; // [sp+50h] [-30h] BYREF

  idAnimatedSimple::Think(this);
  idAnimatedSimplePhysics::UpdateCollisionParts(this, bounds: &v2, push: true);
}


// ========================================================================
// ??0idAnimatedSimplePhysics@@QAA@XZ
// EA  : 0x82C01558
// RVA : 0x00C01558
// PDB : w:\tech5\tungsten\game\entities\animatedsimplephysics.cpp
// ========================================================================

idAnimatedSimplePhysics *__fastcall idAnimatedSimplePhysics::idAnimatedSimplePhysics(idAnimatedSimplePhysics *this)
{
  idAnimatedSimple::idAnimatedSimple(this);
  this->crush = false;
  this->__vftable = (idAnimatedSimplePhysics_vtbl *)&idAnimatedSimplePhysics::`vftable';
  this->collisionParts.granularity = 0;
  this->collisionParts.memTag = 5;
  this->collisionParts.listStatic = 0;
  this->collisionParts.list = nullptr;
  this->collisionParts.size = 0;
  this->collisionParts.num = 0;
  return this;
}


// ========================================================================
// __unwind$488959
// EA  : 0x82C015CC
// RVA : 0x00C015CC
// PDB : w:\tech5\tungsten\game\entities\animatedsimplephysics.cpp
// ========================================================================

void _unwind_488959()
{
  int v0; // r12

  idAnimatedSimple::~idAnimatedSimple(this: *(idAnimatedSimple **)(v0 - 112 + 132));
}


// ========================================================================
// ??1idAnimatedSimplePhysics@@UAA@XZ
// EA  : 0x82C01600
// RVA : 0x00C01600
// PDB : w:\tech5\tungsten\game\entities\animatedsimplephysics.cpp
// ========================================================================

void __fastcall idAnimatedSimplePhysics::~idAnimatedSimplePhysics(idAnimatedSimplePhysics *this)
{
  int v2; // r28
  int v3; // r29
  idPresentableAnimatedPhysics *presentable; // r3
  idAnimPhysicsPiece *list; // r27
  int size; // r29
  idStr *p_joint; // r28

  this->__vftable = (idAnimatedSimplePhysics_vtbl *)&idAnimatedSimplePhysics::`vftable';
  v2 = 0;
  if ( this->collisionParts.num > 0 )
  {
    v3 = 0;
    do
    {
      presentable = this->collisionParts.list[v3].presentable;
      if ( presentable != nullptr )
      {
        idPresentable::Delete(this: presentable);
        this->collisionParts.list[v3].presentable = nullptr;
      }
      ++v2;
      ++v3;
    }
    while ( v2 < this->collisionParts.num );
  }
  if ( this->collisionParts.listStatic == 0 || this->collisionParts.listStatic == 2 )
  {
    list = this->collisionParts.list;
    if ( list != nullptr )
    {
      size = this->collisionParts.size;
      if ( size > 0 )
      {
        p_joint = &list->joint;
        do
        {
          idStr::FreeData(this: p_joint);
          --size;
          p_joint = (idStr *)((char *)p_joint + 48);
        }
        while ( size != 0 );
      }
      idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
    }
    this->collisionParts.list = nullptr;
    this->collisionParts.size = 0;
  }
  this->collisionParts.num = 0;
  idAnimatedSimple::~idAnimatedSimple(this);
}


// ========================================================================
// __unwind$489233
// EA  : 0x82C016E8
// RVA : 0x00C016E8
// PDB : w:\tech5\tungsten\game\entities\animatedsimplephysics.cpp
// ========================================================================

void _unwind_489233()
{
  int v0; // r12

  idAnimatedSimple::~idAnimatedSimple(this: *(idAnimatedSimple **)(v0 - 144 + 164));
}


// ========================================================================
// __unwind$489234_1
// EA  : 0x82C01710
// RVA : 0x00C01710
// PDB : w:\tech5\tungsten\game\entities\animatedsimplephysics.cpp
// ========================================================================

void _unwind_489234_1()
{
  int v0; // r12

  idList<idAnimPhysicsPiece,5>::~idList<idAnimPhysicsPiece,5>(this: (idList<idAnimPhysicsPiece,5> *)(*(_DWORD *)(v0 - 144 + 164) + 7660));
}

