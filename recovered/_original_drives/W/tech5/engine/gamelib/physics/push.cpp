
// ========================================================================
// ?RestorePushedPhysicsObjectState@idPush@@QAAXXZ
// EA  : 0x82765B30
// RVA : 0x00765B30
// PDB : w:\tech5\engine\gamelib\physics\push.cpp
// ========================================================================

void __fastcall idPush::RestorePushedPhysicsObjectState(idPush *this)
{
  int v2; // r30
  int v3; // r31

  v2 = 0;
  if ( this->pushed.num > 0 )
  {
    v3 = 0;
    do
    {
      this->pushed.list[v3]->RestoreState(this: this->pushed.list[v3]);
      ++v2;
      ++v3;
    }
    while ( v2 < this->pushed.num );
  }
}


// ========================================================================
// ?SetPushedOnPushedPhysicsObjects@idPush@@QAAXH@Z
// EA  : 0x82765B88
// RVA : 0x00765B88
// PDB : w:\tech5\engine\gamelib\physics\push.cpp
// ========================================================================

void __fastcall idPush::SetPushedOnPushedPhysicsObjects(idPush *this, int deltaTime)
{
  int v4; // r31
  int v5; // r30

  v4 = 0;
  if ( this->pushed.num > 0 )
  {
    v5 = 0;
    do
    {
      this->pushed.list[v5]->SetPushed(this: this->pushed.list[v5], a2: deltaTime);
      ++v4;
      ++v5;
    }
    while ( v4 < this->pushed.num );
  }
}


// ========================================================================
// ?ClipPhysicsObjectRotation@idPush@@AAAXAAUtrace_t@@PBVidPhysics@@PBVidClipModel@@PAV4@ABVidRotation@@@Z
// EA  : 0x82765BE8
// RVA : 0x00765BE8
// PDB : w:\tech5\engine\gamelib\physics\push.cpp
// ========================================================================

void __fastcall idPush::ClipPhysicsObjectRotation(
        idPush *this,
        trace_t *trace,
        idPhysics *phys,
        const idClipModel *clipModel,
        idClipModel *skip,
        const idRotation *rotation)
{
  if ( skip != nullptr )
    skip->enabled = false;
  phys->ClipRotation(this: phys, a2: trace, a3: rotation, a4: clipModel);
  if ( skip != nullptr )
    skip->enabled = true;
}


// ========================================================================
// ?ClipPhysicsObjectTranslation@idPush@@AAAXAAUtrace_t@@PBVidPhysics@@PBVidClipModel@@PAV4@ABVidVec3@@@Z
// EA  : 0x82765C48
// RVA : 0x00765C48
// PDB : w:\tech5\engine\gamelib\physics\push.cpp
// ========================================================================

void __fastcall idPush::ClipPhysicsObjectTranslation(
        idPush *this,
        trace_t *trace,
        idPhysics *phys,
        const idClipModel *clipModel,
        idClipModel *skip,
        const idVec3 *translation)
{
  if ( skip != nullptr )
    skip->enabled = false;
  phys->ClipTranslation(this: phys, a2: trace, a3: translation, a4: clipModel);
  if ( skip != nullptr )
    skip->enabled = true;
}


// ========================================================================
// ?CanPushPhysicsObject@idPush@@AAA_NPAVidPhysics@@H0@Z
// EA  : 0x82765CA8
// RVA : 0x00765CA8
// PDB : w:\tech5\engine\gamelib\physics\push.cpp
// ========================================================================

int __fastcall idPush::CanPushPhysicsObject(idPush *this, idPhysics *phys, char flags, idPhysics *pusher)
{
  int result; // r3
  idPhysics_vtbl *v8; // r29
  int v9; // r3
  int v10; // r29
  physicsType_t type; // r11
  bool v12; // zf

  if ( phys == nullptr )
    return 0;
  v8 = phys->__vftable;
  v9 = pusher->GetContents(this: pusher, a2: -1);
  if ( !v8->IsPushable(this: phys, a2: v9) )
    return 0;
  v10 = phys->GetClipMask(this: phys, a2: -1);
  if ( (v10 & pusher->GetContents(this: pusher, a2: -1)) == 0 )
    return 0;
  type = phys->type;
  if ( type == PHYSICS_PLAYER && phys[12].entityNumber == 4 )
    return 0;
  if ( (flags & 4) != 0 && type != PHYSICS_RIGIDBODY )
    return 0;
  if ( (flags & 8) == 0 )
    return 1;
  v12 = pusher->IsGroundEntity(this: pusher, a2: phys->entityNumber);
  result = 0;
  if ( !v12 )
    return 1;
  return result;
}


// ========================================================================
// ?GetPhysicsObjectsTouchingBounds@idPush@@AAAHQAPAVidPhysics@@ABVidBounds@@HPAV2@@Z
// EA  : 0x82765DC0
// RVA : 0x00765DC0
// PDB : w:\tech5\engine\gamelib\physics\push.cpp
// ========================================================================

int __fastcall idPush::GetPhysicsObjectsTouchingBounds(
        idPush *this,
        idPhysics **physicsObjects,
        const idBounds *bounds,
        int flags,
        idPhysics *pusher,
        int a6,
        int a7,
        int a8,
        int a9,
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
        idClipModel *a27)
{
  __int64 v27; // r4
  idPhysics **v28; // r25
  char v29; // r6
  char v30; // r24
  int v31; // r7
  int v32; // r29
  const idBounds *v33; // r5
  const char *ClipModelsTouchingBounds; // r3
  int v35; // r30
  idPhysics **v36; // r27
  idClipModel **v37; // r28
  const char *i; // r26
  idPhysics *PhysicsForId; // r31
  idPhysics_vtbl *v40; // r23
  int v41; // r3
  char v42; // r11
  int v43; // r23
  physicsType_t type; // r11
  char v45; // r3
  int v46; // r10
  idPhysics **v47; // r11

  v27 = ((__int64 (*)(void))RtlCheckStack12)();
  v28 = (idPhysics **)v27;
  v30 = v29;
  v32 = v31;
  ClipModelsTouchingBounds = idClip::GetClipModelsTouchingBounds(
                               this: *(idClip **)HIDWORD(v27),
                               bounds: v33,
                               clipMask: -1,
                               clipModelList: &a27,
                               maxCount: (const char *)0x2000);
  v35 = 0;
  if ( (int)ClipModelsTouchingBounds > 0 )
  {
    v36 = v28 - 1;
    v37 = &a27;
    for ( i = ClipModelsTouchingBounds; i != nullptr; --i )
    {
      PhysicsForId = idPhysics::GetPhysicsForId(physicsId_: (*v37)->physicsId);
      if ( PhysicsForId != nullptr )
      {
        v40 = PhysicsForId->__vftable;
        v41 = (*(int (__fastcall **)(int, int))(*(_DWORD *)v32 + 28))(a1: v32, a2: -1);
        if ( v40->IsPushable(this: PhysicsForId, a2: v41) )
        {
          v43 = PhysicsForId->GetClipMask(this: PhysicsForId, a2: -1);
          if ( (v43 & (*(int (__fastcall **)(int, int))(*(_DWORD *)v32 + 28))(a1: v32, a2: -1)) != 0 )
          {
            type = PhysicsForId->type;
            if ( type == PHYSICS_PLAYER && PhysicsForId[12].entityNumber == 4 )
            {
              v42 = 0;
            }
            else if ( (v30 & 4) == 0 || type == PHYSICS_RIGIDBODY )
            {
              if ( (v30 & 8) == 0
                || (v45 = (*(int (__fastcall **)(int, int))(*(_DWORD *)v32 + 252))(
                            a1: v32,
                            a2: PhysicsForId->entityNumber),
                    v42 = 0,
                    v45 == 0) )
              {
                v42 = 1;
              }
            }
            else
            {
              v42 = 0;
            }
          }
          else
          {
            v42 = 0;
          }
        }
        else
        {
          v42 = 0;
        }
        if ( v42 != 0 )
        {
          v46 = 0;
          if ( v35 <= 0 )
            goto LABEL_24;
          v47 = v28;
          while ( *v47 != PhysicsForId )
          {
            ++v46;
            ++v47;
            if ( v46 >= v35 )
              goto LABEL_24;
          }
          if ( v46 >= v35 )
          {
LABEL_24:
            *++v36 = PhysicsForId;
            ++v35;
          }
        }
      }
      ++v37;
    }
  }
  return v35;
}


// ========================================================================
// ?RotatePhysicsObjectToAxial@idPush@@AAA_NPAVidPhysics@@ABVidVec3@@PBVidClipModel@@@Z
// EA  : 0x82765F90
// RVA : 0x00765F90
// PDB : w:\tech5\engine\gamelib\physics\push.cpp
// ========================================================================

int __fastcall idPush::RotatePhysicsObjectToAxial(
        idPush *this,
        idPhysics *phys,
        const idVec3 *rotationPoint,
        const idClipModel *clipModel)
{
  int v5; // r30
  double z; // fp29
  double y; // fp30
  double x; // fp31
  const idMat3 *v9; // r3
  char *v10; // r10
  _DWORD *p_z; // r11
  int i; // ctr
  idPhysics_vtbl *v13; // r11
  void (__fastcall *ClipRotation)(idPhysics *, trace_t *, const idRotation *, const idClipModel *); // ctr
  idMat3 v16; // [sp+60h] [-150h] BYREF
  char v17; // [sp+A0h] [-110h]
  float v18; // [sp+B0h] [-100h] BYREF
  _BYTE v19[12]; // [sp+B4h] [-FCh] BYREF
  _BYTE v20[40]; // [sp+C0h] [-F0h] BYREF
  float v21; // [sp+E8h] [-C8h]
  float v22; // [sp+ECh] [-C4h]
  float v23; // [sp+F0h] [-C0h]
  char v24; // [sp+12Ch] [-84h] BYREF
  idRotation v25; // [sp+130h] [-80h] BYREF

  v5 = 0;
  z = rotationPoint->z;
  y = rotationPoint->y;
  x = rotationPoint->x;
  while ( 1 )
  {
    v9 = phys->GetAxis(this: phys, a2: 0);
    v10 = &v24;
    p_z = (_DWORD *)&v9[-1].mat[2].z;
    for ( i = 9; i != 0; --i )
    {
      ++p_z;
      v10 += 4;
      *(_DWORD *)v10 = *p_z;
    }
    idMat3::ToRotation(this: &v16, result: &v25);
    v13 = phys->__vftable;
    if ( v16.mat[2].x == 0.0 )
    {
      v13->SetAxis(this: phys, a2: &mat3_identity, a3: -1);
      return 1;
    }
    v16.mat[2].x = v16.mat[2].x * (float)-1.0;
    v16.mat[0].x = x;
    v17 = 0;
    v16.mat[0].y = y;
    ClipRotation = v13->ClipRotation;
    v16.mat[0].z = z;
    ClipRotation(this: phys, a2: (trace_t *)&v18, a3: (const idRotation *)&v16, a4: nullptr);
    if ( v18 >= 1.0 )
      break;
    if ( v18 > 0.0 )
    {
      phys->SetOrigin(this: phys, a2: (const idVec3 *)v19, a3: -1);
      phys->SetAxis(this: phys, a2: (const idMat3 *)v20, a3: -1);
    }
    ++v5;
    x = v21;
    y = v22;
    z = v23;
    if ( v5 >= 4 )
      return 0;
  }
  phys->SetOrigin(this: phys, a2: (const idVec3 *)v19, a3: -1);
  phys->SetAxis(this: phys, a2: &mat3_identity, a3: -1);
  return 1;
}


// ========================================================================
// ?InitSavingPushedPhysicsObjectState@idPush@@QAAXXZ
// EA  : 0x82766238
// RVA : 0x00766238
// PDB : w:\tech5\engine\gamelib\physics\push.cpp
// ========================================================================

void __fastcall idPush::InitSavingPushedPhysicsObjectState(idPush *this)
{
  idList<idPhysics *,77> *p_pushed; // r31

  p_pushed = &this->pushed;
  if ( this->pushed.size < 0 )
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->pushed);
  p_pushed->num = __CFADD__(-p_pushed->size, p_pushed->size ^ 0x80000000) ? 0 : p_pushed->size;
}


// ========================================================================
// __unwind$248228
// EA  : 0x8276654C
// RVA : 0x0076654C
// PDB : w:\tech5\engine\gamelib\physics\push.cpp
// ========================================================================

void _unwind_248228()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 + 32624));
}


// ========================================================================
// ?RecursiveTryTranslatePushPhysicsObject@idPush@@AAAHAAUtrace_t@@0PAVidPhysics@@HABVidVec3@@AAM@Z
// EA  : 0x82766580
// RVA : 0x00766580
// PDB : w:\tech5\engine\gamelib\physics\push.cpp
// ========================================================================

// bad sp value at call has been detected, the output may be wrong!
int __fastcall idPush::RecursiveTryTranslatePushPhysicsObject(
        idPush *this,
        trace_t *results,
        trace_t *trace,
        idPhysics *pusher,
        const int flags,
        const idVec3 *translation,
        float *mass)
{
  __int64 v7; // r4
  float *v8; // r9
  float *v9; // r22
  idPush *v10; // r26
  trace_t *v11; // r24
  trace_t *v12; // r5
  trace_t *v13; // r23
  idPhysics *v14; // r6
  idPhysics *v15; // r30
  int v16; // r7
  int v17; // r25
  const idVec3 *v18; // r8
  const idVec3 *v19; // r28
  idPhysics *PhysicsForId; // r3
  idPhysics_vtbl *v21; // r11
  idPhysics *v22; // r29
  float *v23; // r3
  idPhysics_vtbl *v24; // r6
  double y; // fp13
  double v26; // fp10
  double v27; // fp9
  idClipModel *(__fastcall *GetClipModel)(idPhysics *, int); // r5
  idClipModel *v29; // r3
  int v30; // r3
  int v31; // r27
  int v32; // r3
  int v33; // r29
  double z; // fp13
  double v35; // fp9
  double v36; // fp9
  int v37; // r29
  int v38; // r30
  idPhysics *v40; // [sp+50h] [-80A0h] BYREF
  idVec3 v41; // [sp+58h] [-8098h] BYREF
  idList<enum encounterGroupRole_t,5> v42; // [sp+70h] [-8080h] BYREF
  int v43; // [sp+80h] [-8070h] BYREF

  v7 = ((__int64 (*)(void))RtlCheckStack12)();
  v42.granularity = 1;
  v9 = v8;
  v42.num = 0;
  v42.size = 0x2000;
  v42.list = (encounterGroupRole_t *)&v43;
  v10 = (idPush *)HIDWORD(v7);
  v42.memTag = 5;
  v11 = (trace_t *)v7;
  v13 = v12;
  v42.listStatic = 1;
  v15 = v14;
  v17 = v16;
  v19 = v18;
  while ( 1 )
  {
    PhysicsForId = idPhysics::GetPhysicsForId(physicsId_: v13->c.physicsId);
    v21 = v15->__vftable;
    v22 = PhysicsForId;
    v40 = PhysicsForId;
    if ( v21->GetNumClipModels(this: v15) != 1
      || (unsigned __int8)idPush::CanPushPhysicsObject(this: v10, phys: v22, flags: v17 & 0xF7, pusher: v15) == 0 )
    {
      break;
    }
    idList<idAnimWebBlendTree *,5>::Append(this: &v42, obj: (const encounterGroupRole_t *)&v40);
    v22->DisableClip(this: v22);
    v23 = (float *)v15->GetOrigin(this: v15, a2: 0);
    v24 = v15->__vftable;
    y = v19->y;
    v26 = v23[1];
    v27 = (float)(v23[2] + v19->z);
    v41.x = *v23 + v19->x;
    GetClipModel = v24->GetClipModel;
    v41.z = v27;
    v41.y = (float)v26 + (float)y;
    v29 = GetClipModel(this: v15, a2: 0);
    v30 = idPush::TryTranslatePushPhysicsObject(
            this: v10,
            results: v11,
            check: v22,
            clipModel: v29,
            flags: v17,
            newOrigin: &v41,
            translation: v19,
            mass: v9);
    v31 = v30;
    if ( v30 == 0 )
      goto LABEL_15;
    if ( v30 == 2 )
    {
      z = v11->c.normal.z;
      v35 = -v11->c.normal.y;
      v11->c.normal.x = -v11->c.normal.x;
      v11->c.normal.y = v35;
      goto LABEL_14;
    }
    v32 = (int)v15->GetClipModel(this: v15, a2: 0);
    v33 = v32;
    if ( v32 != 0 )
      *(_BYTE *)(v32 + 8) = 0;
    v15->ClipTranslation(this: v15, a2: v13, a3: v19, a4: nullptr);
    if ( v33 != 0 )
      *(_BYTE *)(v33 + 8) = 1;
    if ( v13->fraction >= 1.0 )
      goto LABEL_15;
  }
  v31 = 2;
  z = v11->c.normal.z;
  v36 = -v11->c.normal.x;
  v11->c.normal.y = -v11->c.normal.y;
  v11->c.normal.x = v36;
LABEL_14:
  v11->c.normal.z = -z;
  v11->c.dist = -v11->c.dist;
LABEL_15:
  v37 = 0;
  if ( v42.num > 0 )
  {
    v38 = 0;
    do
    {
      (*(void (__fastcall **)(encounterGroupRole_t))(*(_DWORD *)v42.list[v38] + 200))(a1: v42.list[v38]);
      ++v37;
      ++v38;
    }
    while ( v37 < v42.num );
  }
  if ( (v42.listStatic == 0 || v42.listStatic == 2) && v42.list != nullptr )
    idMem::Free(this: &mem, ptr: v42.list, align: ALIGN_16);
  return v31;
}


// ========================================================================
// __unwind$248380
// EA  : 0x8276683C
// RVA : 0x0076683C
// PDB : w:\tech5\engine\gamelib\physics\push.cpp
// ========================================================================

void _unwind_248380()
{
  idStaticList<idVehicleState *,4> *v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: v0 + 1020);
}


// ========================================================================
// ?SavePhysicsObjectState@idPush@@AAAXPAVidPhysics@@@Z
// EA  : 0x82766868
// RVA : 0x00766868
// PDB : w:\tech5\engine\gamelib\physics\push.cpp
// ========================================================================

void __fastcall idPush::SavePhysicsObjectState(idPush *this, idPhysics *phys)
{
  int num; // r9
  int v4; // r10
  int v5; // r11
  idList<idPhysics *,77> *p_pushed; // r31
  int v7; // r11
  int size; // r10
  idPhysics **list; // r9
  idPhysics **v10; // r11

  num = this->pushed.num;
  v4 = 0;
  if ( num <= 0 )
  {
LABEL_5:
    p_pushed = &this->pushed;
    idList<idMD6Node *,5>::PreAllocateWithGranularity(
      this: (idList<idMD6Filter *,5> *)&this->pushed,
      newSize: this->pushed.num + 1);
    v7 = p_pushed->num;
    size = p_pushed->size;
    list = p_pushed->list;
    if ( v7 >= size )
    {
      v10 = &list[size - 1];
    }
    else
    {
      p_pushed->num = v7 + 1;
      v10 = &list[v7];
    }
    *v10 = phys;
    phys->SaveState(this: phys);
  }
  else
  {
    v5 = 0;
    while ( this->pushed.list[v5] != phys )
    {
      ++v4;
      ++v5;
      if ( v4 >= num )
        goto LABEL_5;
    }
  }
}


// ========================================================================
// ?TryRotatePushPhysicsObject@idPush@@AAAHAAUtrace_t@@PAVidPhysics@@PAVidClipModel@@HABVidVec3@@ABVidMat3@@ABVidRotation@@AAM@Z
// EA  : 0x82766930
// RVA : 0x00766930
// PDB : w:\tech5\engine\gamelib\physics\push.cpp
// ========================================================================

int __fastcall idPush::TryRotatePushPhysicsObject(
        idPush *this,
        trace_t *results,
        idPhysics *check,
        idClipModel *clipModel,
        int flags,
        const idVec3 *newOrigin,
        const idMat3 *newAxis,
        idRotation *rotation,
        float *mass,
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
        float *a28)
{
  double angle; // fp30
  double fraction; // fp0
  bool v38; // mr_fpscr48
  double v39; // fp13
  double x; // fp12
  double y; // fp11
  idPhysics_vtbl *v42; // r11
  double z; // fp10
  double v44; // fp9
  double v45; // fp8
  double v46; // fp7
  void (__fastcall *ClipRotation)(idPhysics *, trace_t *, const idRotation *, const idClipModel *); // r10
  const idVec3 *v49; // r3
  double v50; // fp13
  double v51; // fp12
  const idRotation *v52; // r3
  double v53; // fp10
  double v54; // fp9
  double v55; // fp0
  double v56; // fp13
  double v57; // fp12
  double v58; // fp11
  double v59; // fp10
  double v60; // fp9
  double v61; // fp8
  double v62; // fp7
  double v63; // fp5
  double v64; // fp4
  idRenderWorld *v65; // r3
  idRenderWorld *v66; // r3
  double v67; // fp0
  double v68; // fp13
  double v69; // fp12
  double v70; // fp11
  double v71; // fp10
  double v72; // fp9
  unsigned __int8 *p_flags; // r10
  float *p_z; // r9
  int i; // ctr
  physicsType_t type; // r11
  double v77; // fp31
  double v78; // fp1
  double v79; // fp1
  double v80; // fp31
  double v81; // fp28
  double v82; // fp1
  double v83; // fp1
  idVec3 v84; // [sp+50h] [-1F0h] BYREF
  idRotation v85; // [sp+60h] [-1E0h] BYREF
  float v86[6]; // [sp+A8h] [-198h] BYREF
  trace_t v87; // [sp+C0h] [-180h] BYREF
  idVec3 v88[4]; // [sp+140h] [-100h] BYREF
  idRotation v89; // [sp+170h] [-D0h] BYREF

  angle = rotation->angle;
  results->fraction = 1.0;
  results->endpos = *newOrigin;
  results->endAxis = *newAxis;
  memset(Dst: &results->c, Val: 0, Size: sizeof(results->c));
  *a28 = check->GetMass(this: check, a2: -1) + *a28;
  if ( check->IsGroundClipModel(this: check, a2: clipModel->entityNumber, a3: clipModel->bodyId) )
  {
    clipModel->enabled = false;
    check->ClipRotation(this: check, a2: &v87, a3: rotation, a4: nullptr);
    fraction = v87.fraction;
    v38 = v87.fraction < 1.0;
    clipModel->enabled = true;
    if ( v38 )
    {
      v39 = rotation->angle;
      x = rotation->origin.x;
      v85.axisValid = false;
      y = rotation->origin.y;
      v42 = check->__vftable;
      z = rotation->origin.z;
      v44 = rotation->vec.x;
      v45 = rotation->vec.y;
      v46 = rotation->vec.z;
      v85.origin.x = x;
      ClipRotation = v42->ClipRotation;
      v85.origin.y = y;
      v85.origin.z = z;
      v85.vec.x = v44;
      v85.vec.y = v45;
      v85.vec.z = v46;
      v85.angle = (float)((float)fraction - (float)1.0) * (float)v39;
      ClipRotation(this: check, a2: results, a3: &v85, a4: clipModel);
      if ( results->fraction < 1.0
        && idPush::RecursiveTryRotatePushPhysicsObject(
             this,
             results,
             trace: &v87,
             pusher: check,
             flags,
             rotation,
             mass: a28) == 2 )
      {
        return 2;
      }
    }
    v49 = check->GetOrigin(this: check, a2: 0);
    v50 = v49->y;
    v51 = v49->z;
    v84.x = v49->x;
    v84.y = v50;
    v84.z = v51;
  }
  else
  {
    v52 = idRotation::operator-(this: &v89, result: rotation);
    check->ClipRotation(this: check, a2: results, a3: v52, a4: clipModel);
    if ( results->fraction >= 1.0 )
      return 0;
    if ( (flags & 2) != 0 )
    {
      v53 = -results->c.normal.x;
      v54 = -results->c.normal.z;
      results->c.normal.y = -results->c.normal.y;
      results->c.normal.x = v53;
      results->c.normal.z = v54;
      results->c.dist = -results->c.dist;
      return 2;
    }
    v55 = (float)((float)1.0 - results->fraction);
    v56 = rotation->angle;
    v57 = rotation->origin.x;
    v58 = rotation->origin.y;
    v59 = rotation->origin.z;
    v85.axisValid = false;
    v60 = rotation->vec.x;
    v61 = rotation->vec.y;
    v62 = rotation->vec.z;
    v85.origin.x = v57;
    v85.origin.y = v58;
    v85.origin.z = v59;
    angle = (float)((float)v55 * (float)v56);
    v85.vec.x = v60;
    v85.vec.y = v61;
    v85.vec.z = v62;
    v85.angle = (float)v55 * (float)v56;
    v63 = results->c.point.y;
    v64 = results->c.point.z;
    v84.x = results->c.point.x;
    v84.y = v63;
    v84.z = v64;
    idPush::ClipPhysicsObjectRotation(
      this,
      trace: &v87,
      phys: check,
      clipModel: nullptr,
      skip: clipModel,
      rotation: &v85);
    if ( v87.fraction < 1.0 )
    {
      if ( g_showPushHits.valueInteger != 0 && v87.fraction == 0.0 )
      {
        v65 = common->RW(this: common);
        v65->DebugPoint(this: v65, a2: (const idVec4 *)&idColor::colorYellow, a3: &v87.c.point, a4: 3000, a5: false);
        v66 = common->RW(this: common);
        v86[0] = (float)(v87.c.normal.x * (float)10.0) + v87.c.point.x;
        v86[1] = v87.c.point.y + (float)(v87.c.normal.y * (float)10.0);
        v86[2] = v87.c.point.z + (float)(v87.c.normal.z * (float)10.0);
        ((void (__fastcall *)(idRenderWorld *, idColor *, idVec3 *, float *, double))v66->DebugArrow)(
          a1: v66,
          a2: &idColor::colorGreen,
          a3: &v87.c.point,
          a4: v86,
          a5: 5.0);
      }
      if ( idPush::RecursiveTryRotatePushPhysicsObject(
             this,
             results,
             trace: &v87,
             pusher: check,
             flags,
             rotation: &v85,
             mass: a28) == 2 )
        return 2;
    }
  }
  idPush::SavePhysicsObjectState(this, phys: check);
  v67 = rotation->origin.x;
  v68 = rotation->origin.y;
  v85.axisValid = false;
  v69 = rotation->origin.z;
  v70 = rotation->vec.x;
  v71 = rotation->vec.y;
  v72 = rotation->vec.z;
  v85.angle = angle;
  v85.origin.x = v67;
  v85.origin.y = v68;
  v85.origin.z = v69;
  v85.vec.x = v70;
  v85.vec.y = v71;
  v85.vec.z = v72;
  idRotation::RotatePoint(this: &v85, point: &v84);
  check->Rotate(this: check, a2: &v85, a3: -1);
  p_flags = &v87.c.flags;
  p_z = &clipModel->origin.z;
  for ( i = 9; i != 0; --i )
  {
    ++p_z;
    p_flags += 4;
    *(float *)p_flags = *p_z;
  }
  idClipModel::Link(
    this: clipModel,
    newEntityNumber: clipModel->entityNumber,
    newPhysicsId: clipModel->physicsId,
    newBodyId: clipModel->bodyId,
    newOrigin,
    newAxis);
  type = check->type;
  if ( (type == PHYSICS_AI || type == PHYSICS_PLAYER)
    && (unsigned __int8)idPush::RotatePhysicsObjectToAxial(this, phys: check, rotationPoint: &v84, clipModel) == 0 )
  {
    return 2;
  }
  if ( check->type == PHYSICS_PLAYER
    && check->IsGroundClipModel(this: check, a2: clipModel->entityNumber, a3: clipModel->bodyId) )
  {
    v77 = idVec3::ToYaw(this: newAxis->mat);
    v78 = idVec3::ToYaw(this: v88);
    v79 = idMath::AngleNormalize360(angle: (float)((float)v78 - (float)v77));
    v80 = v79;
    if ( v79 > 180.0 )
      v80 = (float)((float)v79 - (float)360.0);
    v81 = idVec3::ToPitch(this: newAxis->mat);
    v82 = idVec3::ToPitch(this: v88);
    v83 = idMath::AngleNormalize360(angle: (float)((float)v82 - (float)v81));
    if ( v83 > 180.0 )
      v83 = (float)((float)v83 - (float)360.0);
    *((float *)&check[12].__vftable + 1) = *((float *)&check[12].__vftable + 1) + (float)v80;
    *(float *)&check[12].__vftable = *(float *)&check[12].__vftable + (float)v83;
  }
  return 1;
}


// ========================================================================
// ?TryTranslatePushPhysicsObject@idPush@@AAAHAAUtrace_t@@PAVidPhysics@@PAVidClipModel@@HABVidVec3@@3AAM@Z
// EA  : 0x82766F28
// RVA : 0x00766F28
// PDB : w:\tech5\engine\gamelib\physics\push.cpp
// ========================================================================

int __fastcall idPush::TryTranslatePushPhysicsObject(
        idPush *this,
        trace_t *results,
        idPhysics *check,
        idClipModel *clipModel,
        int flags,
        const idVec3 *newOrigin,
        const idVec3 *translation,
        float *mass)
{
  float x; // r9
  float y; // r7
  float z; // r6
  double v18; // fp12
  double v19; // fp11
  double v20; // fp1
  idPhysics_vtbl *v21; // r10
  double fraction; // fp0
  bool v23; // mr_fpscr48
  double v24; // fp0
  double v25; // fp11
  void (__fastcall *ClipTranslation)(idPhysics *, trace_t *, const idVec3 *, const idClipModel *); // r10
  double v27; // fp9
  int result; // r3
  idPhysics_vtbl *v29; // r11
  double v30; // fp10
  double v31; // fp9
  double v32; // fp10
  double v33; // fp9
  double v34; // fp0
  double v35; // fp11
  double v36; // fp9
  idRenderWorld *v37; // r3
  idRenderWorld *v38; // r3
  idVec3 v39; // [sp+50h] [-110h] BYREF
  float v40[4]; // [sp+60h] [-100h] BYREF
  float v41[4]; // [sp+70h] [-F0h] BYREF
  float v42[4]; // [sp+80h] [-E0h] BYREF
  trace_t v43; // [sp+90h] [-D0h] BYREF

  y = translation->y;
  z = translation->z;
  x = translation->x;
  results->fraction = 1.0;
  results->endpos.x = newOrigin->x;
  results->endpos.y = newOrigin->y;
  v18 = newOrigin->z;
  v39.x = x;
  results->endpos.z = v18;
  v39.y = y;
  v19 = clipModel->axis.mat[0].x;
  v39.z = z;
  results->endAxis.mat[0].x = v19;
  results->endAxis.mat[0].y = clipModel->axis.mat[0].y;
  results->endAxis.mat[0].z = clipModel->axis.mat[0].z;
  results->endAxis.mat[1] = clipModel->axis.mat[1];
  results->endAxis.mat[2] = clipModel->axis.mat[2];
  memset(Dst: &results->c, Val: 0, Size: sizeof(results->c));
  v20 = ((double (__fastcall *)(idPhysics *, int))check->GetMass)(a1: check, a2: -1);
  v21 = check->__vftable;
  *mass = (float)v20 + *mass;
  if ( v21->IsGroundClipModel(this: check, a2: clipModel->entityNumber, a3: clipModel->bodyId) )
  {
    clipModel->enabled = false;
    check->ClipTranslation(this: check, a2: &v43, a3: translation, a4: nullptr);
    fraction = v43.fraction;
    v23 = v43.fraction < 1.0;
    clipModel->enabled = true;
    if ( v23 )
    {
      v24 = (float)((float)fraction - (float)1.0);
      v25 = translation->z;
      ClipTranslation = check->ClipTranslation;
      v27 = (float)(translation->y * (float)v24);
      v42[0] = translation->x * (float)v24;
      v42[1] = v27;
      v42[2] = (float)v25 * (float)v24;
      ClipTranslation(this: check, a2: results, a3: (const idVec3 *)v42, a4: clipModel);
      if ( results->fraction < 1.0 )
      {
        result = idPush::RecursiveTryTranslatePushPhysicsObject(
                   this,
                   results,
                   trace: &v43,
                   pusher: check,
                   flags,
                   translation,
                   mass);
        if ( result == 2 )
          return result;
      }
    }
LABEL_15:
    idPush::SavePhysicsObjectState(this, phys: check);
    check->Translate(this: check, a2: &v39, a3: -1);
    return 1;
  }
  v29 = check->__vftable;
  v30 = -translation->y;
  v31 = -translation->z;
  v40[0] = -translation->x;
  v40[1] = v30;
  v40[2] = v31;
  v29->ClipTranslation(this: check, a2: results, a3: (const idVec3 *)v40, a4: clipModel);
  if ( results->fraction >= 1.0 )
    return 0;
  if ( (flags & 2) != 0 )
  {
    v32 = -results->c.normal.x;
    v33 = -results->c.normal.z;
    results->c.normal.y = -results->c.normal.y;
    results->c.normal.x = v32;
    results->c.normal.z = v33;
    results->c.dist = -results->c.dist;
    return 2;
  }
  v34 = (float)((float)1.0 - results->fraction);
  v35 = translation->z;
  v36 = (float)(translation->y * (float)((float)1.0 - results->fraction));
  v39.x = translation->x * (float)((float)1.0 - results->fraction);
  v39.y = v36;
  v39.z = (float)v35 * (float)v34;
  idPush::ClipPhysicsObjectTranslation(
    this,
    trace: &v43,
    phys: check,
    clipModel: nullptr,
    skip: clipModel,
    translation: &v39);
  if ( v43.fraction >= 1.0 )
    goto LABEL_15;
  if ( g_showPushHits.valueInteger != 0 && v43.fraction == 0.0 )
  {
    v37 = common->RW(this: common);
    v37->DebugPoint(this: v37, a2: (const idVec4 *)&idColor::colorYellow, a3: &v43.c.point, a4: 3000, a5: false);
    v38 = common->RW(this: common);
    v41[0] = (float)(v43.c.normal.x * (float)10.0) + v43.c.point.x;
    v41[1] = v43.c.point.y + (float)(v43.c.normal.y * (float)10.0);
    v41[2] = v43.c.point.z + (float)(v43.c.normal.z * (float)10.0);
    ((void (__fastcall *)(idRenderWorld *, idColor *, idVec3 *, float *, double))v38->DebugArrow)(
      a1: v38,
      a2: &idColor::colorGreen,
      a3: &v43.c.point,
      a4: v41,
      a5: 5.0);
  }
  result = idPush::RecursiveTryTranslatePushPhysicsObject(
             this,
             results,
             trace: &v43,
             pusher: check,
             flags,
             translation: &v39,
             mass);
  if ( result != 2 )
    goto LABEL_15;
  return result;
}


// ========================================================================
// ?ClipPush@idPush@@QAAMAAUtrace_t@@PAVidPhysics@@HABVidVec3@@ABVidMat3@@AAV4@AAV5@@Z
// EA  : 0x827681C0
// RVA : 0x007681C0
// PDB : w:\tech5\engine\gamelib\physics\push.cpp
// ========================================================================

float __fastcall idPush::ClipPush(
        idPush *this,
        trace_t *results,
        idPhysics *pusher,
        int flags,
        const idVec3 *oldOrigin,
        idMat3 *oldAxis,
        idVec3 *newOrigin,
        idMat3 *newAxis)
{
  idVec3 *v16; // r27
  idVec3 *v17; // r26
  double v18; // fp30
  double x; // fp12
  double v20; // fp0
  double v21; // fp11
  double v22; // fp10
  char v23; // r11
  double z; // fp0
  double v25; // fp13
  double y; // fp12
  idVec3 *v27; // r24
  double v28; // fp10
  idVec3 *v29; // r23
  double v30; // fp9
  double v31; // fp8
  double v32; // fp7
  double v33; // fp6
  idRotation *v34; // r3
  idRotation *v35; // r3
  double v36; // fp5
  double v37; // fp4
  double v38; // fp3
  bool axisValid; // r10
  const idMat3 *v40; // r3
  idMat3 *v41; // r3
  idClipModel *v42; // r3
  double v43; // fp1
  idRotation v45; // [sp+50h] [-190h] BYREF
  idVec3 v46; // [sp+98h] [-148h] BYREF
  idMat3 v47; // [sp+B0h] [-130h] BYREF
  idMat3 v48; // [sp+E0h] [-100h] BYREF
  idMat3 v49[2]; // [sp+110h] [-D0h] BYREF

  results->fraction = 1.0;
  results->endpos = *newOrigin;
  results->endAxis = *newAxis;
  v16 = &newAxis->mat[1];
  v17 = &newAxis->mat[2];
  v18 = 0.0;
  memset(Dst: &results->c, Val: 0, Size: sizeof(results->c));
  x = oldOrigin->x;
  v20 = (float)(newOrigin->x - oldOrigin->x);
  v21 = (float)(newOrigin->y - oldOrigin->y);
  v22 = (float)(newOrigin->z - oldOrigin->z);
  v46.x = newOrigin->x - oldOrigin->x;
  v46.y = v21;
  v46.z = v22;
  if ( v20 != vec3_origin.x || v21 != vec3_origin.y || (v23 = 1, v22 != vec3_origin.z) )
    v23 = 0;
  if ( v23 != 0 )
  {
    newOrigin->x = x;
    newOrigin->y = oldOrigin->y;
    newOrigin->z = oldOrigin->z;
  }
  else
  {
    v18 = idPush::ClipTranslationalPush(this, results, pusher, flags, newOrigin, translation: &v46);
    if ( results->fraction < 1.0 )
    {
      newOrigin->x = oldOrigin->x;
      newOrigin->y = oldOrigin->y;
      newOrigin->z = oldOrigin->z;
      newAxis->mat[0].x = oldAxis->mat[0].x;
      newAxis->mat[0].y = oldAxis->mat[0].y;
      newAxis->mat[0].z = oldAxis->mat[0].z;
      v16->x = oldAxis->mat[1].x;
      v16->y = oldAxis->mat[1].y;
      v16->z = oldAxis->mat[1].z;
      v17->x = oldAxis->mat[2].x;
      v17->y = oldAxis->mat[2].y;
      v17->z = oldAxis->mat[2].z;
      goto LABEL_13;
    }
  }
  z = oldAxis->mat[2].z;
  v25 = oldAxis->mat[1].z;
  y = oldAxis->mat[2].y;
  v27 = &oldAxis->mat[2];
  v28 = oldAxis->mat[0].x;
  v29 = &oldAxis->mat[1];
  v30 = oldAxis->mat[0].z;
  v31 = oldAxis->mat[0].y;
  v32 = oldAxis->mat[2].x;
  v33 = oldAxis->mat[1].x;
  v47.mat[1].y = oldAxis->mat[1].y;
  v47.mat[0].x = v28;
  v47.mat[1].z = y;
  v47.mat[1].x = v31;
  v47.mat[0].z = v32;
  v47.mat[0].y = v33;
  v47.mat[2].x = v30;
  v47.mat[2].y = v25;
  v47.mat[2].z = z;
  v34 = (idRotation *)idMat3::operator*(this: &v48, result: &v47, a: newAxis);
  v35 = idMat3::ToRotation(this: v49, result: v34);
  v36 = newOrigin->x;
  v37 = newOrigin->y;
  v38 = newOrigin->z;
  v45.origin.x = v35->origin.x;
  v45.origin.y = v35->origin.y;
  v45.origin.z = v35->origin.z;
  v45.vec.x = v35->vec.x;
  v45.vec.y = v35->vec.y;
  v45.vec.z = v35->vec.z;
  v45.angle = v35->angle;
  v45.axis.mat[0].x = v35->axis.mat[0].x;
  v45.axis.mat[0].y = v35->axis.mat[0].y;
  v45.axis.mat[0].z = v35->axis.mat[0].z;
  v45.axis.mat[1].x = v35->axis.mat[1].x;
  v45.axis.mat[1].y = v35->axis.mat[1].y;
  v45.axis.mat[1].z = v35->axis.mat[1].z;
  v45.axis.mat[2].x = v35->axis.mat[2].x;
  v45.axis.mat[2].y = v35->axis.mat[2].y;
  v45.axis.mat[2].z = v35->axis.mat[2].z;
  axisValid = v35->axisValid;
  v45.origin.x = v36;
  v45.origin.y = v37;
  v45.axisValid = axisValid;
  v45.origin.z = v38;
  idRotation::Normalize180(this: &v45);
  v45.axisValid = false;
  idRotation::ToMat3(this: &v45);
  if ( v45.angle == 0.0 )
  {
    newAxis->mat[0].x = oldAxis->mat[0].x;
    newAxis->mat[0].y = oldAxis->mat[0].y;
    newAxis->mat[0].z = oldAxis->mat[0].z;
    v16->x = v29->x;
    v16->y = oldAxis->mat[1].y;
    v16->z = oldAxis->mat[1].z;
    v17->x = v27->x;
    v17->y = oldAxis->mat[2].y;
    v17->z = oldAxis->mat[2].z;
  }
  else
  {
    v40 = idRotation::ToMat3(this: &v45);
    v41 = idMat3::operator*(this: &v48, result: oldAxis, a: v40);
    newAxis->mat[0] = v41->mat[0];
    *v16 = v41->mat[1];
    *v17 = v41->mat[2];
    idMat3::OrthoNormalizeSelf(this: newAxis);
    idMat3::FixDenormals(this: newAxis);
    idMat3::FixDegeneracies(this: newAxis);
    v42 = pusher->GetClipModel(this: pusher, a2: 0);
    idClipModel::SetLinkedPosition(this: v42, newOrigin, newAxis: oldAxis);
    v18 = (float)(idPush::ClipRotationalPush(this, results, pusher, flags, newAxis, rotation: &v45) + (float)v18);
    if ( results->fraction < 1.0 )
    {
      newOrigin->x = oldOrigin->x;
      newOrigin->y = oldOrigin->y;
      newOrigin->z = oldOrigin->z;
      newAxis->mat[0].x = oldAxis->mat[0].x;
      newAxis->mat[0].y = oldAxis->mat[0].y;
      newAxis->mat[0].z = oldAxis->mat[0].z;
      v16->x = v29->x;
      v16->y = oldAxis->mat[1].y;
      v16->z = oldAxis->mat[1].z;
      v17->x = v27->x;
      v17->y = oldAxis->mat[2].y;
      v17->z = oldAxis->mat[2].z;
    }
  }
LABEL_13:
  v43 = v18;
  return *((float *)&v43 + 1);
}


// ========================================================================
// `dynamic initializer for 'g_showPushHits''
// EA  : 0x833416C8
// RVA : 0x013416C8
// PDB : w:\tech5\engine\gamelib\physics\push.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_showPushHits__()
{
  idCVar::idCVar(
    this: &g_showPushHits,
    name: "g_showPushHits",
    value: "0",
    flags: 2,
    description: "Shows traces for pushers applying impulses on colliding objects",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_showPushHits__);
}

