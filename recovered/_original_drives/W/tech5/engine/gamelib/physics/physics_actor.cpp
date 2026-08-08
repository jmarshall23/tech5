
// ========================================================================
// ??1idPhysics_Actor@@UAA@XZ
// EA  : 0x8273A640
// RVA : 0x0073A640
// PDB : w:\tech5\engine\gamelib\physics\physics_actor.cpp
// ========================================================================

void __fastcall idPhysics_Actor::~idPhysics_Actor(idPhysics_Actor *this)
{
  idClipModel **clipModels; // r30
  int i; // r29

  this->__vftable = (idPhysics_Actor_vtbl *)&idPhysics_Actor::`vftable';
  clipModels = this->clipModels;
  for ( i = 2; i != 0; --i )
  {
    if ( *clipModels != nullptr )
      idClipModel::Delete(this: *clipModels);
    ++clipModels;
  }
  idPhysics_DynamicBase::~idPhysics_DynamicBase(this);
}


// ========================================================================
// __unwind$246021
// EA  : 0x8273A698
// RVA : 0x0073A698
// PDB : w:\tech5\engine\gamelib\physics\physics_actor.cpp
// ========================================================================

void _unwind_246021()
{
  int v0; // r12

  idPhysics_DynamicBase::~idPhysics_DynamicBase(this: *(idPhysics_DynamicBase **)(v0 - 128 + 148));
}


// ========================================================================
// ?GetMasterDeltaYaw@idPhysics_Actor@@QBAMXZ
// EA  : 0x8273A6C0
// RVA : 0x0073A6C0
// PDB : w:\tech5\engine\gamelib\physics\physics_actor.cpp
// ========================================================================

float __fastcall idPhysics_Actor::GetMasterDeltaYaw(idPhysics_Actor *this)
{
  double masterDeltaYaw; // fp1

  masterDeltaYaw = this->masterDeltaYaw;
  return *((float *)&masterDeltaYaw + 1);
}


// ========================================================================
// ?SetClipModel@idPhysics_Actor@@UAAXPAVidClipModel@@MH_N@Z
// EA  : 0x8273A6C8
// RVA : 0x0073A6C8
// PDB : w:\tech5\engine\gamelib\physics\physics_actor.cpp
// ========================================================================

void __fastcall idPhysics_Actor::SetClipModel(
        idPhysics_Actor *this,
        idClipModel *model,
        double density,
        int id,
        unsigned int freeOld,
        char a6)
{
  int v8; // r30
  idClipModel *v9; // r3

  v8 = ((freeOld == 0) + (freeOld >> 31) - 1) & freeOld;
  if ( a6 != 0 )
  {
    v9 = this->clipModels[v8];
    if ( v9 != nullptr && v9 != model )
      idClipModel::Delete(this: v9);
  }
  this->clipModels[v8] = model;
  this->LinkClip(this);
}


// ========================================================================
// ?GetClipModel@idPhysics_Actor@@UBAPAVidClipModel@@H@Z
// EA  : 0x8273A740
// RVA : 0x0073A740
// PDB : w:\tech5\engine\gamelib\physics\physics_actor.cpp
// ========================================================================

idClipModel *__fastcall idPhysics_Actor::GetClipModel(idPhysics_Actor *this, unsigned int id)
{
  return this->clipModels[((id == 0) + (id >> 31) - 1) & id];
}


// ========================================================================
// ?GetNumClipModels@idPhysics_Actor@@UBAHXZ
// EA  : 0x8273A760
// RVA : 0x0073A760
// PDB : w:\tech5\engine\gamelib\physics\physics_actor.cpp
// ========================================================================

int __fastcall idPhysics_Actor::GetNumClipModels(idPhysics_Actor *this)
{
  BOOL v1; // r11
  idClipModel *v2; // r10
  int result; // r3

  v1 = this->clipModels[0] != nullptr;
  v2 = this->clipModels[1];
  result = v1 + 1;
  if ( v2 == nullptr )
    return v1;
  return result;
}


// ========================================================================
// ?SetMass@idPhysics_Actor@@UAAXMH@Z
// EA  : 0x8273A790
// RVA : 0x0073A790
// PDB : w:\tech5\engine\gamelib\physics\physics_actor.cpp
// ========================================================================

void __fastcall idPhysics_Actor::SetMass(idPhysics_Actor *this, double _mass, int id)
{
  this->mass = _mass;
  this->invMass = (float)1.0 / (float)_mass;
}


// ========================================================================
// ?GetMass@idPhysics_Actor@@UBAMH@Z
// EA  : 0x8273A7A8
// RVA : 0x0073A7A8
// PDB : w:\tech5\engine\gamelib\physics\physics_actor.cpp
// ========================================================================

float __fastcall idPhysics_Actor::GetMass(idPhysics_Actor *this, int id)
{
  double mass; // fp1

  mass = this->mass;
  return *((float *)&mass + 1);
}


// ========================================================================
// ?SetContents@idPhysics_Actor@@UAAXHH@Z
// EA  : 0x8273A7B0
// RVA : 0x0073A7B0
// PDB : w:\tech5\engine\gamelib\physics\physics_actor.cpp
// ========================================================================

void __fastcall idPhysics_Actor::SetContents(idPhysics_Actor *this, int contents, unsigned int id)
{
  idClipModel::SetContents(this: this->clipModels[((id == 0) + (id >> 31) - 1) & id], newContents: contents);
}


// ========================================================================
// ?SetClipMask@idPhysics_Actor@@UAAXHH@Z
// EA  : 0x8273A7D0
// RVA : 0x0073A7D0
// PDB : w:\tech5\engine\gamelib\physics\physics_actor.cpp
// ========================================================================

void __fastcall idPhysics_Actor::SetClipMask(idPhysics_Actor *this, int mask, int id)
{
  if ( id > 0 )
  {
    this->clipMasks[id] = mask;
  }
  else
  {
    this->clipMask = mask;
    this->clipMasks[0] = mask;
  }
}


// ========================================================================
// ?GetClipMask@idPhysics_Actor@@UBAHH@Z
// EA  : 0x8273A7F8
// RVA : 0x0073A7F8
// PDB : w:\tech5\engine\gamelib\physics\physics_actor.cpp
// ========================================================================

int __fastcall idPhysics_Actor::GetClipMask(idPhysics_Actor *this, unsigned int id)
{
  return this->clipMasks[((id == 0) + (id >> 31) - 1) & id];
}


// ========================================================================
// ?IsPushable@idPhysics_Actor@@UBA_NH@Z
// EA  : 0x8273A818
// RVA : 0x0073A818
// PDB : w:\tech5\engine\gamelib\physics\physics_actor.cpp
// ========================================================================

BOOL __fastcall idPhysics_Actor::IsPushable(idPhysics_Actor *this, int sourceContentType)
{
  return (_cntlzw(this->hasMaster) & 0x20) != 0;
}


// ========================================================================
// ?UnlinkClip@idPhysics_Actor@@UAAXXZ
// EA  : 0x8273A828
// RVA : 0x0073A828
// PDB : w:\tech5\engine\gamelib\physics\physics_actor.cpp
// ========================================================================

void __fastcall idPhysics_Actor::UnlinkClip(idPhysics_Actor *this)
{
  idClipModel **clipModels; // r31
  int i; // r30

  clipModels = this->clipModels;
  for ( i = 2; i != 0; --i )
  {
    if ( *clipModels != nullptr )
      idClipModel::Unlink(this: *clipModels);
    ++clipModels;
  }
}


// ========================================================================
// ?SetClipModelAxis@idPhysics_Actor@@QAAXXZ
// EA  : 0x8273A8E8
// RVA : 0x0073A8E8
// PDB : w:\tech5\engine\gamelib\physics\physics_actor.cpp
// ========================================================================

void __fastcall idPhysics_Actor::SetClipModelAxis(idPhysics_Actor *this)
{
  double x; // fp13
  char v3; // r11
  double y; // fp0
  double z; // fp12
  double v6; // fp5
  double v7; // fp4

  if ( this->gravityNormal.z == -1.0 )
    goto LABEL_8;
  x = this->gravityNormal.x;
  if ( x != vec3_origin.x || this->gravityNormal.y != vec3_origin.y || (v3 = 1, this->gravityNormal.z != vec3_origin.z) )
    v3 = 0;
  if ( v3 != 0 )
  {
LABEL_8:
    this->clipModelAxis.mat[2].z = 1.0;
    this->clipModelAxis.mat[1].y = 1.0;
    this->clipModelAxis.mat[0].x = 1.0;
    this->clipModelAxis.mat[1].z = 0.0;
    this->clipModelAxis.mat[0].z = 0.0;
    this->clipModelAxis.mat[0].y = 0.0;
    this->clipModelAxis.mat[2].y = 0.0;
    this->clipModelAxis.mat[2].x = 0.0;
    this->clipModelAxis.mat[1].x = 0.0;
  }
  else
  {
    y = this->gravityNormal.y;
    z = this->gravityNormal.z;
    this->clipModelAxis.mat[2].x = -x;
    this->clipModelAxis.mat[2].y = -y;
    this->clipModelAxis.mat[2].z = -z;
    idVec3::NormalVectors(
      this: &this->clipModelAxis.mat[2],
      left: this->clipModelAxis.mat,
      down: &this->clipModelAxis.mat[1]);
    v6 = -this->clipModelAxis.mat[1].y;
    v7 = -this->clipModelAxis.mat[1].z;
    this->clipModelAxis.mat[1].x = -this->clipModelAxis.mat[1].x;
    this->clipModelAxis.mat[1].y = v6;
    this->clipModelAxis.mat[1].z = v7;
  }
  this->LinkClip(this);
}


// ========================================================================
// ?GetContents@idPhysics_Actor@@UBAHH@Z
// EA  : 0x8273AA10
// RVA : 0x0073AA10
// PDB : w:\tech5\engine\gamelib\physics\physics_actor.cpp
// ========================================================================

int __fastcall idPhysics_Actor::GetContents(idPhysics_Actor *this, unsigned int id)
{
  return this->clipModels[((id == 0) + (id >> 31) - 1) & id]->contents;
}


// ========================================================================
// ?GetBounds@idPhysics_Actor@@UBAABVidBounds@@H@Z
// EA  : 0x8273AA38
// RVA : 0x0073AA38
// PDB : w:\tech5\engine\gamelib\physics\physics_actor.cpp
// ========================================================================

const idBounds *__fastcall idPhysics_Actor::GetBounds(idPhysics_Actor *this, unsigned int id)
{
  return &this->clipModels[((id == 0) + (id >> 31) - 1) & id]->bounds;
}


// ========================================================================
// ?GetAbsBounds@idPhysics_Actor@@UBAABVidBounds@@H@Z
// EA  : 0x8273AA60
// RVA : 0x0073AA60
// PDB : w:\tech5\engine\gamelib\physics\physics_actor.cpp
// ========================================================================

const idBounds *__fastcall idPhysics_Actor::GetAbsBounds(idPhysics_Actor *this, unsigned int id)
{
  return &this->clipModels[((id == 0) + (id >> 31) - 1) & id]->absBounds;
}


// ========================================================================
// ?GetOrigin@idPhysics_Actor@@UBAABVidVec3@@H@Z
// EA  : 0x8273AA88
// RVA : 0x0073AA88
// PDB : w:\tech5\engine\gamelib\physics\physics_actor.cpp
// ========================================================================

const idVec3 *__fastcall idPhysics_Actor::GetOrigin(idPhysics_Actor *this, unsigned int id)
{
  return &this->clipModels[((id == 0) + (id >> 31) - 1) & id]->origin;
}


// ========================================================================
// ?GetAxis@idPhysics_Actor@@UBAABVidMat3@@H@Z
// EA  : 0x8273AAB0
// RVA : 0x0073AAB0
// PDB : w:\tech5\engine\gamelib\physics\physics_actor.cpp
// ========================================================================

const idMat3 *__fastcall idPhysics_Actor::GetAxis(idPhysics_Actor *this, unsigned int id)
{
  return &this->clipModels[((id == 0) + (id >> 31) - 1) & id]->axis;
}


// ========================================================================
// ?SetGravity@idPhysics_Actor@@UAAXABVidVec3@@@Z
// EA  : 0x8273AAD8
// RVA : 0x0073AAD8
// PDB : w:\tech5\engine\gamelib\physics\physics_actor.cpp
// ========================================================================

void __fastcall idPhysics_Actor::SetGravity(idPhysics_Actor *this, const idVec3 *newGravity)
{
  char v3; // r11

  if ( newGravity->x != this->gravityVector.x
    || newGravity->y != this->gravityVector.y
    || (v3 = 1, newGravity->z != this->gravityVector.z) )
  {
    v3 = 0;
  }
  if ( v3 == 0 )
  {
    idPhysics_DynamicBase::SetGravity(this, newGravity);
    idVec3::FixDegenerateNormal(this: &this->gravityNormal);
    idPhysics_Actor::SetClipModelAxis(this);
  }
}


// ========================================================================
// ?DisableClip@idPhysics_Actor@@UAAXXZ
// EA  : 0x8273AB60
// RVA : 0x0073AB60
// PDB : w:\tech5\engine\gamelib\physics\physics_actor.cpp
// ========================================================================

void __fastcall idPhysics_Actor::DisableClip(idPhysics_Actor *this)
{
  idClipModel *v1; // r11

  v1 = this->clipModels[0];
  if ( v1 != nullptr )
    v1->enabled = false;
}


// ========================================================================
// ?EnableClip@idPhysics_Actor@@UAAXXZ
// EA  : 0x8273AB78
// RVA : 0x0073AB78
// PDB : w:\tech5\engine\gamelib\physics\physics_actor.cpp
// ========================================================================

void __fastcall idPhysics_Actor::EnableClip(idPhysics_Actor *this)
{
  idClipModel *v1; // r11

  v1 = this->clipModels[0];
  if ( v1 != nullptr )
    v1->enabled = true;
}


// ========================================================================
// ?DisableClip@idPhysics_Actor@@UAAXW4actorClipModel_t@1@@Z
// EA  : 0x8273AB90
// RVA : 0x0073AB90
// PDB : w:\tech5\engine\gamelib\physics\physics_actor.cpp
// ========================================================================

void __fastcall idPhysics_Actor::DisableClip(idPhysics_Actor *this, const idPhysics_Actor::actorClipModel_t clipType)
{
  idClipModel *v2; // r11

  v2 = this->clipModels[clipType];
  if ( v2 != nullptr )
    v2->enabled = false;
}


// ========================================================================
// ?EnableClip@idPhysics_Actor@@UAAXW4actorClipModel_t@1@@Z
// EA  : 0x8273ABB0
// RVA : 0x0073ABB0
// PDB : w:\tech5\engine\gamelib\physics\physics_actor.cpp
// ========================================================================

void __fastcall idPhysics_Actor::EnableClip(idPhysics_Actor *this, const idPhysics_Actor::actorClipModel_t clipType)
{
  idClipModel *v2; // r11

  v2 = this->clipModels[clipType];
  if ( v2 != nullptr )
    v2->enabled = true;
}


// ========================================================================
// ?LinkClip@idPhysics_Actor@@UAAXXZ
// EA  : 0x8273ABD0
// RVA : 0x0073ABD0
// PDB : w:\tech5\engine\gamelib\physics\physics_actor.cpp
// ========================================================================

void __fastcall idPhysics_Actor::LinkClip(idPhysics_Actor *this)
{
  idClipModel **clipModels; // r31
  int i; // r29

  clipModels = this->clipModels;
  for ( i = 2; i != 0; --i )
  {
    if ( *clipModels != nullptr )
      idClipModel::Link(
        this: *clipModels,
        newEntityNumber: this->entityNumber,
        newPhysicsId: this->physicsId,
        newBodyId: 0,
        newOrigin: &(*clipModels)->origin,
        newAxis: &this->clipModelAxis);
    ++clipModels;
  }
}


// ========================================================================
// ?LinkClip@idPhysics_Actor@@UAAXABVidVec3@@ABVidMat3@@@Z
// EA  : 0x8273AC28
// RVA : 0x0073AC28
// PDB : w:\tech5\engine\gamelib\physics\physics_actor.cpp
// ========================================================================

void __fastcall idPhysics_Actor::LinkClip(idPhysics_Actor *this, const idVec3 *newOrigin, const idMat3 *newAxis)
{
  idClipModel **clipModels; // r29
  int i; // r28

  this->clipModelAxis = *newAxis;
  clipModels = this->clipModels;
  for ( i = 2; i != 0; --i )
  {
    if ( *clipModels != nullptr )
      idClipModel::Link(
        this: *clipModels,
        newEntityNumber: this->entityNumber,
        newPhysicsId: this->physicsId,
        newBodyId: 0,
        newOrigin,
        newAxis);
    ++clipModels;
  }
}


// ========================================================================
// ?EvaluateContacts@idPhysics_Actor@@UAA_NXZ
// EA  : 0x8273ACD0
// RVA : 0x0073ACD0
// PDB : w:\tech5\engine\gamelib\physics\physics_actor.cpp
// ========================================================================

BOOL __fastcall idPhysics_Actor::EvaluateContacts(idPhysics_Actor *this)
{
  idClipModel **clipModels; // r31
  int i; // r29
  int v4; // r5

  clipModels = this->clipModels;
  this->ClearContacts(this);
  for ( i = 2; i != 0; --i )
  {
    if ( *clipModels != nullptr )
    {
      v4 = (int)clipModels[2];
      if ( v4 != 0 )
        idPhysics_DynamicBase::AddGroundContacts(this, clipModel: *clipModels, clipMask: v4);
    }
    ++clipModels;
  }
  idPhysics_DynamicBase::AddContactPhysicsForContacts(this);
  return this->contacts.num != 0;
}


// ========================================================================
// ?RememberHistorySample@idPhysics_Actor@@QAAXXZ
// EA  : 0x8273AD40
// RVA : 0x0073AD40
// PDB : w:\tech5\engine\gamelib\physics\physics_actor.cpp
// ========================================================================

void __fastcall idPhysics_Actor::RememberHistorySample(idPhysics_Actor *this)
{
  idGame *v2; // r3
  int v3; // r3
  signed int v4; // r27
  const idVec3 *v5; // r3
  float y; // r7
  float *v7; // r10
  float z; // r6
  float *v9; // r11
  double x; // fp12
  int i; // ctr
  int v12; // r10
  int v13; // r9
  int v14; // r11
  int v15; // r11
  float *p_z; // r28
  float *p_lastHistorySaveTime; // r30
  int v18; // r29
  const idVec3 *v19; // r3
  signed int v20; // r11
  int v21; // r30
  const idVec3 *v22; // r3
  float *v23; // r11

  v2 = common->Game(this: common);
  v3 = v2->GetGameMs(this: v2, a2: GAMETIME_SCALED);
  v4 = v3;
  if ( this->wasHistoryInitialized )
  {
    v15 = this->lastHistorySaveTime + 128;
    if ( v3 >= v15 )
    {
      this->lastHistorySaveTime = v15;
      if ( v15 >= v3 - 128 )
      {
        v21 = (v15 / 128) & 0xF;
        v22 = this->GetOrigin(this, a2: 0);
        v23 = (float *)((char *)this + 12 * v21);
        v23[50] = v22->x;
        v23[51] = v22->y;
        v23[52] = v22->z;
        this->yawHistory[v21] = this->masterYaw;
      }
      else
      {
        p_z = &this->originHistory[15].z;
        p_lastHistorySaveTime = (float *)&this->lastHistorySaveTime;
        v18 = 16;
        do
        {
          v19 = this->GetOrigin(this, a2: 0);
          --v18;
          p_lastHistorySaveTime[1] = v19->x;
          p_lastHistorySaveTime[2] = v19->y;
          p_lastHistorySaveTime += 3;
          *p_lastHistorySaveTime = v19->z;
          *++p_z = this->masterYaw;
        }
        while ( v18 != 0 );
        v20 = v4 & 0xFFFFFF80 | this->lastHistorySaveTime & 0x7F;
        this->lastHistorySaveTime = v20;
        if ( v20 > v4 )
          this->lastHistorySaveTime = v20 - 128;
      }
    }
  }
  else
  {
    v5 = this->GetOrigin(this, a2: 0);
    y = v5->y;
    v7 = &this->originHistory[15].z;
    z = v5->z;
    v9 = (float *)&this->lastHistorySaveTime;
    x = v5->x;
    for ( i = 2; i != 0; --i )
    {
      v9[1] = x;
      v9[2] = y;
      v9[3] = z;
      v7[1] = this->masterYaw;
      v9[4] = x;
      v9[5] = y;
      v9[6] = z;
      v7[2] = this->masterYaw;
      v9[7] = x;
      v9[8] = y;
      v9[9] = z;
      v7[3] = this->masterYaw;
      v9[10] = x;
      v9[11] = y;
      v9[12] = z;
      v7[4] = this->masterYaw;
      v9[13] = x;
      v9[14] = y;
      v9[15] = z;
      v7[5] = this->masterYaw;
      v9[16] = x;
      v9[17] = y;
      v9[18] = z;
      v7[6] = this->masterYaw;
      v9[19] = x;
      v9[20] = y;
      v9[21] = z;
      v7[7] = this->masterYaw;
      v9[22] = x;
      v9[23] = y;
      v9 += 24;
      *v9 = z;
      v7 += 8;
      *v7 = this->masterYaw;
    }
    v12 = (v4 & 0xFFFFFF80) + idPhysics_Actor::nextHistoryOffset;
    this->lastHistorySaveTime = v12;
    if ( v12 >= v4 && v12 > 128 )
      this->lastHistorySaveTime = v12 - 128;
    v13 = idPhysics_Actor::nextHistoryOffsetIncr + idPhysics_Actor::nextHistoryOffset;
    idPhysics_Actor::nextHistoryOffset = v13;
    if ( v13 >= 128 )
    {
      idPhysics_Actor::nextHistoryOffset = v13 - 128;
      v14 = idPhysics_Actor::nextHistoryOffsetIncr / 10 + idPhysics_Actor::nextHistoryOffsetIncr;
      idPhysics_Actor::nextHistoryOffsetIncr = v14;
      if ( v14 >= 118 )
        idPhysics_Actor::nextHistoryOffsetIncr = v14 / 3;
    }
    this->wasHistoryInitialized = true;
  }
}


// ========================================================================
// ?GetOriginHistory@idPhysics_Actor@@QBA?AVidVec3@@H@Z
// EA  : 0x8273AFF8
// RVA : 0x0073AFF8
// PDB : w:\tech5\engine\gamelib\physics\physics_actor.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
idPhysics_Actor *__fastcall idPhysics_Actor::GetOriginHistory(idPhysics_Actor *this, idVec3 *result, int timeBack)
{
  int v5; // r30
  idGame *v6; // r3
  int v7; // r3
  int v8; // r29
  int v9; // r27
  idVec3 *v10; // r3
  float x; // r11
  bool v12; // zf
  int v13; // r30
  int v14; // r28
  int v15; // r3
  __int64 v16; // r7 OVERLAPPED
  float y; // r11
  idVec3 *v18; // r10
  int v19; // r11
  idVec3 *v20; // r9
  double v21; // fp13
  double v22; // fp12
  idPhysics_Actor *v23; // r3
  int v24; // r8
  int v25; // r3
  int v26; // r7
  idPhysics_Actor_vtbl *v27; // r8
  float v28; // [sp+54h] [-5Ch]
  float v29; // [sp+58h] [-58h]
  float z; // [sp+60h] [-50h]
  float v31; // [sp+64h] [-4Ch]
  float v32; // [sp+68h] [-48h]

  v5 = timeBack;
  if ( timeBack <= 0 || HIBYTE(result[16].x) == 0 )
  {
    x = result->x;
    v10 = result;
LABEL_18:
    v25 = (*(int (__fastcall **)(idVec3 *, _DWORD))(LODWORD(x) + 64))(a1: v10, a2: 0);
    v26 = *(_DWORD *)(v25 + 4);
    v27 = *(idPhysics_Actor_vtbl **)v25;
    this->type = *(_DWORD *)(v25 + 8);
    *((_DWORD *)&this->__vftable + 1) = v26;
    this->__vftable = v27;
    return this;
  }
  if ( timeBack > 1664 )
    v5 = 1664;
  v6 = common->Game(this: common);
  v7 = v6->GetGameMs(this: v6, a2: GAMETIME_SCALED);
  v8 = v7 - v5;
  v9 = v7;
  x = result->x;
  v12 = v7 - v5 <= MIN_HISTORY_TIME_DESIRED;
  v10 = result;
  if ( v12 )
    goto LABEL_18;
  v13 = LODWORD(result[16].y) & 0x7F;
  v14 = SLODWORD(result[16].y) / 128 + 1;
  v15 = (*(int (__fastcall **)(idVec3 *, _DWORD))(LODWORD(x) + 64))(a1: result, a2: 0);
  HIDWORD(v16) = *(_DWORD *)(v15 + 4);
  y = result[16].y;
  z = *(float *)v15;
  v31 = *(float *)&v16;
  v32 = *(float *)(v15 + 8);
  if ( v8 < SLODWORD(y) )
  {
    if ( v8 > LODWORD(y) - 2032 )
    {
      v19 = (v8 - v13) / 128;
      v18 = (idVec3 *)((char *)result + 4 * (v19 & 0xF) + 4 * ((2 * v19) & 0x1E));
      v20 = &result[((_BYTE)v19 + 1) & 0xF];
      LODWORD(y) = (v19 << 7) + v13;
      v9 = LODWORD(y) + 128;
      z = v20[16].z;
      v31 = v20[17].x;
      v32 = v20[17].y;
    }
    else
    {
      y = *(float *)&v8;
      v18 = &result[((_BYTE)v14 + 1) & 0xF];
    }
  }
  else
  {
    v18 = &result[((_BYTE)v14 - 1) & 0xF];
  }
  v21 = v18[17].x;
  v22 = v18[17].y;
  v28 = v18[17].x;
  v29 = v18[17].y;
  if ( SLODWORD(y) >= v9 || v8 >= v9 )
  {
    *(float *)&this->__vftable = z;
    *((float *)&this->__vftable + 1) = v31;
    *(float *)&this->type = v32;
    return this;
  }
  else
  {
    v23 = this;
    if ( v8 > SLODWORD(y) )
    {
      v24 = v9 - LODWORD(y);
      LODWORD(v16) = v8 - LODWORD(y);
      *(float *)&this->__vftable = (float)((float)(z - v18[16].z)
                                         * (float)((float)v16 / (float)*(__int64 *)((char *)&v16 - 4)))
                                 + v18[16].z;
      *((float *)&this->__vftable + 1) = (float)((float)(v31 - (float)v21)
                                               * (float)((float)v16 / (float)*(__int64 *)((char *)&v16 - 4)))
                                       + (float)v21;
      *(float *)&this->type = (float)((float)(v32 - (float)v22)
                                    * (float)((float)v16 / (float)*(__int64 *)((char *)&v16 - 4)))
                            + (float)v22;
    }
    else
    {
      *(float *)&this->__vftable = v18[16].z;
      *((float *)&this->__vftable + 1) = v28;
      *(float *)&this->type = v29;
    }
  }
  return v23;
}


// ========================================================================
// ?GetVelocityHistory@idPhysics_Actor@@QBA?AVidVec3@@H@Z
// EA  : 0x8273B2C0
// RVA : 0x0073B2C0
// PDB : w:\tech5\engine\gamelib\physics\physics_actor.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
idPhysics_Actor *__fastcall idPhysics_Actor::GetVelocityHistory(idPhysics_Actor *this, idVec3 *result, int timeBack)
{
  int v5; // r30
  idGame *v6; // r3
  int v7; // r3
  int v8; // r30
  int v9; // r29
  float y; // r11
  int v11; // r8
  int v12; // r11
  bool v13; // zf
  idVec3 *v14; // r11
  int v15; // r10
  idVec3 *v16; // r10
  int (__fastcall *v17)(__int64 *, idVec3 *, _DWORD); // ctr
  idVec3 *v18; // r4
  int v19; // r31
  double v20; // fp31
  double v21; // fp30
  double v22; // fp29
  float *v23; // r3
  double v24; // fp0
  __int64 v25; // r8 OVERLAPPED
  double v26; // fp13
  double v27; // fp12
  int v28; // r7
  int v29; // r11
  int v30; // r4
  int v31; // r10
  int v32; // r9
  float *v33; // r11
  idVec3 *v34; // r9
  idVec3 *v35; // r10
  double v36; // fp11
  int v37; // r9
  __int64 v39; // [sp+50h] [-50h] BYREF

  v5 = timeBack;
  if ( timeBack <= 0 || HIBYTE(result[16].x) == 0 )
    goto LABEL_13;
  if ( timeBack > 1664 )
    v5 = 1664;
  v6 = common->Game(this: common);
  v7 = v6->GetGameMs(this: v6, a2: GAMETIME_SCALED);
  v8 = v7 - v5;
  v9 = v7;
  if ( v8 > MIN_HISTORY_TIME_DESIRED_0 )
  {
    y = result[16].y;
    v11 = LODWORD(y) - 64;
    v13 = v8 < LODWORD(y) - 64;
    v12 = (SLODWORD(y) / 128) & 0xF;
    if ( v13 )
    {
      v28 = v11 - v8 + 127;
      v29 = v12 - v28 / 128;
      v30 = (v28 / 128) << 7;
      v31 = (v29 - 1) & 0xF;
      v32 = ((_BYTE)v29 + 1) & 0xF;
      v33 = &result->x + (v29 & 0xF) + ((2 * v29) & 0x1E);
      v34 = &result[v32];
      HIDWORD(v25) = 3 * v31;
      v35 = &result[v31];
      v19 = v11 - v30;
      LODWORD(v25) = v11 - v30 + 128;
      v20 = (float)((float)(v33[50] - v35[16].z) * idPhysics_Actor::SAMPLE_RATE_TO_VELOCITY);
      v21 = (float)((float)(v33[51] - v35[17].x) * idPhysics_Actor::SAMPLE_RATE_TO_VELOCITY);
      v26 = (float)((float)(v34[17].x - v33[51]) * idPhysics_Actor::SAMPLE_RATE_TO_VELOCITY);
      v27 = (float)((float)(v34[17].y - v33[52]) * idPhysics_Actor::SAMPLE_RATE_TO_VELOCITY);
      v22 = (float)((float)(v33[52] - v35[17].y) * idPhysics_Actor::SAMPLE_RATE_TO_VELOCITY);
      v24 = (float)((float)(v34[16].z - v33[50]) * idPhysics_Actor::SAMPLE_RATE_TO_VELOCITY);
    }
    else
    {
      v15 = ((_BYTE)v12 - 1) & 0xF;
      v14 = &result[v12];
      v16 = &result[v15];
      v17 = *(int (__fastcall **)(__int64 *, idVec3 *, _DWORD))(LODWORD(result->x) + 88);
      v18 = result;
      v19 = v11;
      v20 = (float)((float)(v14[16].z - v16[16].z) * idPhysics_Actor::SAMPLE_RATE_TO_VELOCITY);
      v21 = (float)((float)(v14[17].x - v16[17].x) * idPhysics_Actor::SAMPLE_RATE_TO_VELOCITY);
      v22 = (float)((float)(v14[17].y - v16[17].y) * idPhysics_Actor::SAMPLE_RATE_TO_VELOCITY);
      v23 = (float *)v17(a1: &v39, a2: v18, a3: 0);
      v24 = *v23;
      LODWORD(v25) = v9;
      v26 = v23[1];
      v27 = v23[2];
    }
    if ( (_DWORD)v25 == v19 )
    {
      v36 = 1.0;
    }
    else
    {
      v37 = v25 - v19;
      LODWORD(v25) = v8 - v19;
      v39 = v25;
      v36 = (float)((float)v25 / (float)*(__int64 *)((char *)&v25 - 4));
    }
    *(float *)&this->__vftable = (float)((float)((float)v24 - (float)v20) * (float)v36) + (float)v20;
    *((float *)&this->__vftable + 1) = (float)((float)((float)v26 - (float)v21) * (float)v36) + (float)v21;
    *(float *)&this->type = (float)((float)((float)v27 - (float)v22) * (float)v36) + (float)v22;
  }
  else
  {
LABEL_13:
    (*(void (__fastcall **)(idPhysics_Actor *, idVec3 *, _DWORD))(LODWORD(result->x) + 88))(a1: this, a2: result, a3: 0);
  }
  return this;
}


// ========================================================================
// ??0idPhysics_Actor@@QAA@XZ
// EA  : 0x8273B590
// RVA : 0x0073B590
// PDB : w:\tech5\engine\gamelib\physics\physics_actor.cpp
// ========================================================================

idPhysics_Actor *__fastcall idPhysics_Actor::idPhysics_Actor(idPhysics_Actor *this)
{
  idClipModel **v2; // r11
  int i; // ctr
  float *p_z; // r9
  int v5; // ctr
  float *p_lastHistorySaveTime; // r11

  idPhysics_DynamicBase::idPhysics_DynamicBase(this);
  v2 = &this->clipModels[1];
  this->__vftable = (idPhysics_Actor_vtbl *)&idPhysics_Actor::`vftable';
  this->type = PHYSICS_INVALID;
  for ( i = 2; i != 0; --i )
  {
    *(v2++ - 1) = nullptr;
    *v2 = nullptr;
  }
  idPhysics_Actor::SetClipModelAxis(this);
  this->hasMaster = false;
  this->wasHistoryInitialized = false;
  this->lastHistorySaveTime = 0;
  p_z = &this->originHistory[15].z;
  v5 = 16;
  p_lastHistorySaveTime = (float *)&this->lastHistorySaveTime;
  this->mass = 100.0;
  this->invMass = 0.0099999998;
  this->masterYaw = 0.0;
  this->masterDeltaYaw = 0.0;
  do
  {
    p_lastHistorySaveTime[1] = vec3_origin.x;
    p_lastHistorySaveTime[2] = vec3_origin.y;
    p_lastHistorySaveTime += 3;
    *p_lastHistorySaveTime = vec3_origin.z;
    *++p_z = 0.0;
    --v5;
  }
  while ( v5 != 0 );
  return this;
}


// ========================================================================
// __unwind$247246
// EA  : 0x8273B658
// RVA : 0x0073B658
// PDB : w:\tech5\engine\gamelib\physics\physics_actor.cpp
// ========================================================================

void _unwind_247246()
{
  int v0; // r12

  idPhysics_DynamicBase::~idPhysics_DynamicBase(this: *(idPhysics_DynamicBase **)(v0 - 112 + 132));
}


// ========================================================================
// ?ClipRotation@idPhysics_Actor@@UBAXAAUtrace_t@@ABVidRotation@@PBVidClipModel@@@Z
// EA  : 0x8273B680
// RVA : 0x0073B680
// PDB : w:\tech5\engine\gamelib\physics\physics_actor.cpp
// ========================================================================

void __fastcall idPhysics_Actor::ClipRotation(
        idPhysics_Actor *this,
        trace_t *results,
        idRotation *rotation,
        idClipModel *model)
{
  idMat3 *p_axis; // r27
  idVec3 *p_origin; // r26
  idClipModel *v10; // r11
  const idVec3 *v11; // r9
  idClipModel *v12; // r11
  int v13; // r10
  const idVec3 *v14; // [sp+8h] [-138h]
  const idVec3 *v15; // [sp+8h] [-138h]
  int v16; // [sp+8h] [-138h]
  const idMat3 *v17; // [sp+Ch] [-134h]
  const idMat3 *v18; // [sp+Ch] [-134h]
  bool v19; // [sp+Fh] [-131h]
  const char *v20; // [sp+10h] [-130h]
  int v21; // [sp+10h] [-130h]
  const char *v22; // [sp+10h] [-130h]
  int v23; // [sp+14h] [-12Ch]
  int v24; // [sp+14h] [-12Ch]
  int v25; // [sp+14h] [-12Ch]
  int v26; // [sp+18h] [-128h]
  int v27; // [sp+18h] [-128h]
  int v28; // [sp+18h] [-128h]
  int v29; // [sp+1Ch] [-124h]
  int v30; // [sp+1Ch] [-124h]
  int v31; // [sp+1Ch] [-124h]
  int v32; // [sp+20h] [-120h]
  int v33; // [sp+20h] [-120h]
  int v34; // [sp+20h] [-120h]
  int v35; // [sp+24h] [-11Ch]
  int v36; // [sp+24h] [-11Ch]
  int v37; // [sp+24h] [-11Ch]
  int v38; // [sp+28h] [-118h]
  int v39; // [sp+28h] [-118h]
  int v40; // [sp+28h] [-118h]
  int v41; // [sp+2Ch] [-114h]
  int v42; // [sp+2Ch] [-114h]
  int v43; // [sp+2Ch] [-114h]
  int v44; // [sp+30h] [-110h]
  int v45; // [sp+30h] [-110h]
  int v46; // [sp+30h] [-110h]
  int v47; // [sp+34h] [-10Ch]
  int v48; // [sp+34h] [-10Ch]
  int v49; // [sp+34h] [-10Ch]
  int v50; // [sp+38h] [-108h]
  int v51; // [sp+38h] [-108h]
  int v52; // [sp+38h] [-108h]
  int v53; // [sp+3Ch] [-104h]
  int v54; // [sp+3Ch] [-104h]
  int v55; // [sp+3Ch] [-104h]
  int v56; // [sp+40h] [-100h]
  int v57; // [sp+40h] [-100h]
  int v58; // [sp+40h] [-100h]
  int v59; // [sp+44h] [-FCh]
  int v60; // [sp+44h] [-FCh]
  int v61; // [sp+44h] [-FCh]
  int v62; // [sp+48h] [-F8h]
  int v63; // [sp+48h] [-F8h]
  int v64; // [sp+48h] [-F8h]
  int v65; // [sp+4Ch] [-F4h]
  int v66; // [sp+4Ch] [-F4h]
  int v67; // [sp+4Ch] [-F4h]
  int v68; // [sp+50h] [-F0h]
  int v69; // [sp+50h] [-F0h]
  int v70; // [sp+50h] [-F0h]
  int v71; // [sp+58h] [-E8h]
  int v72; // [sp+58h] [-E8h]
  int v73; // [sp+58h] [-E8h]
  int v74; // [sp+60h] [-E0h]
  int v75; // [sp+60h] [-E0h]
  _BYTE v76[16]; // [sp+70h] [-D0h] BYREF
  trace_t v77; // [sp+80h] [-C0h] BYREF

  if ( model != nullptr )
  {
    p_axis = &model->axis;
    p_origin = &model->origin;
    idClip::RotationModel(
      this: this->clip,
      result: results,
      start: (const idMat3 *)&this->clipModels[0]->origin,
      rotation,
      trm: this->clipModels[0],
      trmAxis: &this->clipModels[0]->axis,
      clipMask: (const idVec3 *)this->clipMasks[0],
      model,
      modelOrigin: v14,
      modelAxis: v17,
      a11: (int)v20,
      a12: v23,
      a13: v26,
      a14: v29,
      a15: v32,
      a16: v35,
      a17: v38,
      a18: v41,
      a19: v44,
      a20: v47,
      a21: v50,
      a22: v53,
      a23: v56,
      a24: v59,
      a25: v62,
      a26: v65,
      a27: v68,
      a28: &model->origin.x,
      a29: v71,
      a30: (float *)&model->axis);
    if ( results->fraction > 0.0 )
    {
      v10 = this->clipModels[1];
      if ( v10 != nullptr )
      {
        v11 = (const idVec3 *)this->clipMasks[1];
        if ( v11 != nullptr && v10->enabled )
        {
          idClip::RotationModel(
            this: this->clip,
            result: &v77,
            start: (const idMat3 *)&this->clipModels[1]->origin,
            rotation,
            trm: this->clipModels[1],
            trmAxis: &this->clipModels[1]->axis,
            clipMask: v11,
            model,
            modelOrigin: v15,
            modelAxis: v18,
            a11: v21,
            a12: v24,
            a13: v27,
            a14: v30,
            a15: v33,
            a16: v36,
            a17: v39,
            a18: v42,
            a19: v45,
            a20: v48,
            a21: v51,
            a22: v54,
            a23: v57,
            a24: v60,
            a25: v63,
            a26: v66,
            a27: v69,
            a28: &p_origin->x,
            a29: v72,
            a30: (float *)p_axis);
          goto LABEL_12;
        }
      }
    }
  }
  else
  {
    idClip::Rotation(
      this: (idClip *)v76,
      result: this->clip,
      a3: results,
      start: (const idMat3 *)&this->clipModels[0]->origin,
      rotation,
      clipModel: this->clipModels[0],
      startAxis: &this->clipModels[0]->axis,
      clipMask: this->clipMasks[0],
      passEntityNumber: (int)v14,
      moveClipModel: (bool)v17,
      userName: v20,
      a12: v23,
      a13: v26,
      a14: v29,
      a15: v32,
      a16: v35,
      a17: v38,
      a18: v41,
      a19: v44,
      a20: v47,
      a21: v50,
      a22: v53,
      a23: v56,
      a24: v59,
      a25: v62,
      a26: v65,
      a27: v68,
      a28: this->entityNumber,
      a29: v71,
      a30: false,
      a31: v74,
      a32: 0);
    if ( results->fraction > 0.0 )
    {
      v12 = this->clipModels[1];
      if ( v12 != nullptr )
      {
        v13 = this->clipMasks[1];
        if ( v13 != 0 && v12->enabled )
        {
          idClip::Rotation(
            this: (idClip *)v76,
            result: this->clip,
            a3: results,
            start: (const idMat3 *)&this->clipModels[1]->origin,
            rotation,
            clipModel: this->clipModels[1],
            startAxis: &this->clipModels[1]->axis,
            clipMask: v13,
            passEntityNumber: v16,
            moveClipModel: v19,
            userName: v22,
            a12: v25,
            a13: v28,
            a14: v31,
            a15: v34,
            a16: v37,
            a17: v40,
            a18: v43,
            a19: v46,
            a20: v49,
            a21: v52,
            a22: v55,
            a23: v58,
            a24: v61,
            a25: v64,
            a26: v67,
            a27: v70,
            a28: this->entityNumber,
            a29: v73,
            a30: false,
            a31: v75,
            a32: 0);
LABEL_12:
          if ( v77.fraction < (double)results->fraction )
            trace_t::operator=(this: results, __that: &v77);
        }
      }
    }
  }
}


// ========================================================================
// ?ClipContents@idPhysics_Actor@@UBAHPBVidClipModel@@H@Z
// EA  : 0x8273B800
// RVA : 0x0073B800
// PDB : w:\tech5\engine\gamelib\physics\physics_actor.cpp
// ========================================================================

int __fastcall idPhysics_Actor::ClipContents(idPhysics_Actor *this, idClipModel *model, int clipMask)
{
  int v5; // r29
  int v6; // r27
  idClipModel **clipModels; // r31
  int i; // r26
  int j; // r30
  const idMat3 *v11; // [sp+8h] [-128h]
  int v12; // [sp+Ch] [-124h]
  int v13; // [sp+10h] [-120h]
  int v14; // [sp+14h] [-11Ch]
  int v15; // [sp+18h] [-118h]
  int v16; // [sp+1Ch] [-114h]
  int v17; // [sp+20h] [-110h]
  int v18; // [sp+24h] [-10Ch]
  int v19; // [sp+28h] [-108h]
  int v20; // [sp+2Ch] [-104h]
  int v21; // [sp+30h] [-100h]
  int v22; // [sp+34h] [-FCh]
  int v23; // [sp+38h] [-F8h]
  int v24; // [sp+3Ch] [-F4h]
  int v25; // [sp+40h] [-F0h]
  int v26; // [sp+44h] [-ECh]
  int v27; // [sp+48h] [-E8h]
  int v28; // [sp+4Ch] [-E4h]
  int v29; // [sp+50h] [-E0h]
  char v30; // [sp+60h] [-D0h] BYREF
  trace_t v31; // [sp+70h] [-C0h] BYREF

  v5 = 0;
  v6 = clipMask;
  if ( clipMask == 0 )
    v6 = this->clipMask;
  clipModels = this->clipModels;
  if ( model != nullptr )
  {
    for ( i = 2; i != 0; --i )
    {
      if ( *clipModels != nullptr && clipModels[2] != nullptr && (*clipModels)->enabled )
      {
        idClip::ContentsModel(
          this: this->clip,
          result: &v31,
          start: &(*clipModels)->origin,
          trm: *clipModels,
          trmAxis: &(*clipModels)->axis,
          clipMask: v6,
          model,
          modelOrigin: &model->origin,
          modelAxis: v11,
          a10: v12,
          a11: v13,
          a12: v14,
          a13: v15,
          a14: v16,
          a15: v17,
          a16: v18,
          a17: v19,
          a18: v20,
          a19: v21,
          a20: v22,
          a21: v23,
          a22: v24,
          a23: v25,
          a24: v26,
          a25: v27,
          a26: v28,
          a27: v29,
          a28: (float *)&model->axis);
        v5 |= v31.c.contentFlags;
      }
      ++clipModels;
    }
    return v5;
  }
  else
  {
    for ( j = 2; j != 0; --j )
    {
      if ( *clipModels != nullptr && clipModels[2] != nullptr && (*clipModels)->enabled )
      {
        idClip::Contents(
          this: (idClip *)&v30,
          result: this->clip,
          a3: &v31,
          start: &(*clipModels)->origin,
          clipModel: *clipModels,
          startAxis: &(*clipModels)->axis,
          clipMask: v6,
          passEntityNumber: 0x1FFF,
          userName: (const char *)v11,
          a10: v12,
          a11: v13,
          a12: v14,
          a13: v15,
          a14: v16,
          a15: v17,
          a16: v18,
          a17: v19,
          a18: v20,
          a19: v21,
          a20: v22,
          a21: v23,
          a22: v24,
          a23: v25,
          a24: v26,
          a25: v27,
          a26: v28,
          a27: v29,
          a28: 0);
        v5 |= v31.c.contentFlags;
      }
      ++clipModels;
    }
    return v5;
  }
}


// ========================================================================
// ?ClipTranslation@idPhysics_Actor@@UBAXAAUtrace_t@@ABVidVec3@@PBVidClipModel@@@Z
// EA  : 0x8273B920
// RVA : 0x0073B920
// PDB : w:\tech5\engine\gamelib\physics\physics_actor.cpp
// ========================================================================

void __fastcall idPhysics_Actor::ClipTranslation(
        idPhysics_Actor *this,
        trace_t *results,
        const idVec3 *translation,
        idClipModel *model)
{
  idClipModel *v8; // r7
  double x; // fp0
  idMat3 *p_axis; // r27
  idVec3 *p_origin; // r26
  int v12; // r9
  idClip *clip; // r3
  double v14; // fp9
  double v15; // fp7
  idClipModel *v16; // r11
  idClipModel *v17; // r7
  int v18; // r9
  idClip *v19; // r3
  double v20; // fp7
  double v21; // fp6
  idClipModel *v22; // r8
  double y; // fp0
  double v24; // fp13
  double z; // fp12
  int v26; // r10
  idClip *v28; // r4
  double v29; // fp7
  double v30; // fp6
  idClipModel *v31; // r11
  int v32; // r10
  idClipModel *v33; // r11
  int v34; // r27
  idClipModel *v35; // r8
  double v36; // fp12
  idClip *v37; // r4
  double v38; // fp8
  double v39; // fp7
  const idVec3 *v40; // [sp+8h] [-178h]
  const idVec3 *v41; // [sp+8h] [-178h]
  int v42; // [sp+8h] [-178h]
  const idMat3 *v43; // [sp+Ch] [-174h]
  const idMat3 *v44; // [sp+Ch] [-174h]
  bool v45; // [sp+Fh] [-171h]
  const char *v46; // [sp+10h] [-170h]
  int v47; // [sp+10h] [-170h]
  const char *v48; // [sp+10h] [-170h]
  int v49; // [sp+14h] [-16Ch]
  int v50; // [sp+14h] [-16Ch]
  int v51; // [sp+14h] [-16Ch]
  int v52; // [sp+18h] [-168h]
  int v53; // [sp+18h] [-168h]
  int v54; // [sp+18h] [-168h]
  int v55; // [sp+1Ch] [-164h]
  int v56; // [sp+1Ch] [-164h]
  int v57; // [sp+1Ch] [-164h]
  int v58; // [sp+20h] [-160h]
  int v59; // [sp+20h] [-160h]
  int v60; // [sp+20h] [-160h]
  int v61; // [sp+24h] [-15Ch]
  int v62; // [sp+24h] [-15Ch]
  int v63; // [sp+24h] [-15Ch]
  int v64; // [sp+28h] [-158h]
  int v65; // [sp+28h] [-158h]
  int v66; // [sp+28h] [-158h]
  int v67; // [sp+2Ch] [-154h]
  int v68; // [sp+2Ch] [-154h]
  int v69; // [sp+2Ch] [-154h]
  int v70; // [sp+30h] [-150h]
  int v71; // [sp+30h] [-150h]
  int v72; // [sp+30h] [-150h]
  int v73; // [sp+34h] [-14Ch]
  int v74; // [sp+34h] [-14Ch]
  int v75; // [sp+34h] [-14Ch]
  int v76; // [sp+38h] [-148h]
  int v77; // [sp+38h] [-148h]
  int v78; // [sp+38h] [-148h]
  int v79; // [sp+3Ch] [-144h]
  int v80; // [sp+3Ch] [-144h]
  int v81; // [sp+3Ch] [-144h]
  int v82; // [sp+40h] [-140h]
  int v83; // [sp+40h] [-140h]
  int v84; // [sp+40h] [-140h]
  int v85; // [sp+44h] [-13Ch]
  int v86; // [sp+44h] [-13Ch]
  int v87; // [sp+44h] [-13Ch]
  int v88; // [sp+48h] [-138h]
  int v89; // [sp+48h] [-138h]
  int v90; // [sp+48h] [-138h]
  int v91; // [sp+4Ch] [-134h]
  int v92; // [sp+4Ch] [-134h]
  int v93; // [sp+4Ch] [-134h]
  int v94; // [sp+50h] [-130h]
  int v95; // [sp+50h] [-130h]
  int v96; // [sp+50h] [-130h]
  int entityNumber; // [sp+54h] [-12Ch]
  int v98; // [sp+58h] [-128h]
  int v99; // [sp+58h] [-128h]
  int v100; // [sp+58h] [-128h]
  int v101; // [sp+60h] [-120h]
  int v102; // [sp+60h] [-120h]
  idVec3 v103; // [sp+70h] [-110h] BYREF
  idVec3 v104; // [sp+80h] [-100h] BYREF
  idVec3 v105; // [sp+90h] [-F0h] BYREF
  idVec3 v106; // [sp+A0h] [-E0h] BYREF
  _BYTE v107[16]; // [sp+B0h] [-D0h] BYREF
  trace_t v108; // [sp+C0h] [-C0h] BYREF

  if ( model != nullptr )
  {
    v8 = this->clipModels[0];
    x = translation->x;
    p_axis = &model->axis;
    p_origin = &model->origin;
    v12 = this->clipMasks[0];
    clip = this->clip;
    v14 = v8->origin.x;
    v15 = (float)(v8->origin.y + translation->y);
    v105.z = v8->origin.z + translation->z;
    v105.x = (float)x + (float)v14;
    v105.y = v15;
    idClip::TranslationModel(
      this: clip,
      result: results,
      start: &v8->origin,
      end: &v105,
      trm: v8,
      trmAxis: &v8->axis,
      clipMask: v12,
      model,
      modelOrigin: v40,
      modelAxis: v43,
      a11: (int)v46,
      a12: v49,
      a13: v52,
      a14: v55,
      a15: v58,
      a16: v61,
      a17: v64,
      a18: v67,
      a19: v70,
      a20: v73,
      a21: v76,
      a22: v79,
      a23: v82,
      a24: v85,
      a25: v88,
      a26: v91,
      a27: v94,
      a28: &model->origin.x,
      a29: v98,
      a30: (float *)&model->axis);
    if ( results->fraction > 0.0 )
    {
      v16 = this->clipModels[1];
      if ( v16 != nullptr && this->clipMasks[1] != 0 && v16->enabled )
      {
        v17 = this->clipModels[0];
        v18 = this->clipMasks[0];
        v19 = this->clip;
        v20 = (float)(v17->origin.y + translation->y);
        v21 = (float)(v17->origin.x + translation->x);
        v103.z = v17->origin.z + translation->z;
        v103.y = v20;
        v103.x = v21;
        idClip::TranslationModel(
          this: v19,
          result: &v108,
          start: &v17->origin,
          end: &v103,
          trm: v17,
          trmAxis: &v17->axis,
          clipMask: v18,
          model,
          modelOrigin: v41,
          modelAxis: v44,
          a11: v47,
          a12: v50,
          a13: v53,
          a14: v56,
          a15: v59,
          a16: v62,
          a17: v65,
          a18: v68,
          a19: v71,
          a20: v74,
          a21: v77,
          a22: v80,
          a23: v83,
          a24: v86,
          a25: v89,
          a26: v92,
          a27: v95,
          a28: &p_origin->x,
          a29: v99,
          a30: (float *)p_axis);
        goto LABEL_12;
      }
    }
  }
  else
  {
    v22 = this->clipModels[0];
    y = translation->y;
    v24 = translation->x;
    z = translation->z;
    v26 = this->clipMasks[0];
    entityNumber = this->entityNumber;
    v28 = this->clip;
    v29 = (float)(v22->origin.z + (float)z);
    v30 = (float)(v22->origin.x + (float)v24);
    v104.y = v22->origin.y + (float)y;
    v104.z = v29;
    v104.x = v30;
    idClip::Translation(
      this: (idClip *)v107,
      result: v28,
      a3: results,
      start: &v22->origin,
      end: &v104,
      clipModel: v22,
      startAxis: &v22->axis,
      clipMask: v26,
      passEntityNumber: (int)v40,
      moveClipModel: (bool)v43,
      userName: v46,
      a12: v49,
      a13: v52,
      a14: v55,
      a15: v58,
      a16: v61,
      a17: v64,
      a18: v67,
      a19: v70,
      a20: v73,
      a21: v76,
      a22: v79,
      a23: v82,
      a24: v85,
      a25: v88,
      a26: v91,
      a27: v94,
      a28: entityNumber,
      a29: v98,
      a30: false,
      a31: v101,
      a32: 0);
    if ( results->fraction > 0.0 )
    {
      v31 = this->clipModels[1];
      if ( v31 != nullptr )
      {
        v32 = this->clipMasks[1];
        if ( v32 != 0 && v31->enabled )
        {
          v33 = this->clipModels[0];
          v34 = this->entityNumber;
          v35 = this->clipModels[1];
          v36 = translation->y;
          v37 = this->clip;
          v38 = v33->origin.y;
          v39 = (float)(v33->origin.z + translation->z);
          v106.x = translation->x + v33->origin.x;
          v106.z = v39;
          v106.y = (float)v38 + (float)v36;
          idClip::Translation(
            this: (idClip *)v107,
            result: v37,
            a3: &v108,
            start: &v33->origin,
            end: &v106,
            clipModel: v35,
            startAxis: &v35->axis,
            clipMask: v32,
            passEntityNumber: v42,
            moveClipModel: v45,
            userName: v48,
            a12: v51,
            a13: v54,
            a14: v57,
            a15: v60,
            a16: v63,
            a17: v66,
            a18: v69,
            a19: v72,
            a20: v75,
            a21: v78,
            a22: v81,
            a23: v84,
            a24: v87,
            a25: v90,
            a26: v93,
            a27: v96,
            a28: v34,
            a29: v100,
            a30: false,
            a31: v102,
            a32: 0);
LABEL_12:
          if ( v108.fraction < (double)results->fraction )
            trace_t::operator=(this: results, __that: &v108);
        }
      }
    }
  }
}

