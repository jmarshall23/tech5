
// ========================================================================
// ?GetNumClipModels@idPhysics_Static@@UBAHXZ
// EA  : 0x82761DB0
// RVA : 0x00761DB0
// PDB : w:\tech5\engine\gamelib\physics\physics_static.cpp
// ========================================================================

BOOL __fastcall idPhysics_Static::GetNumClipModels(idPhysics_Static *this)
{
  return this->clipModel != nullptr;
}


// ========================================================================
// ?SetContents@idPhysics_Static@@UAAXHH@Z
// EA  : 0x82761DC0
// RVA : 0x00761DC0
// PDB : w:\tech5\engine\gamelib\physics\physics_static.cpp
// ========================================================================

void __fastcall idPhysics_Static::SetContents(idPhysics_Static *this, int contents, int id)
{
  idClipModel *clipModel; // r3

  clipModel = this->clipModel;
  if ( clipModel != nullptr )
    idClipModel::SetContents(this: clipModel, newContents: contents);
}


// ========================================================================
// ?GetImpactInfo@idPhysics_Static@@UBAXHABVidVec3@@AAUimpactInfo_t@@@Z
// EA  : 0x82761DD8
// RVA : 0x00761DD8
// PDB : w:\tech5\engine\gamelib\physics\physics_static.cpp
// ========================================================================

void __fastcall idPhysics_Static::GetImpactInfo(
        idPhysics_DynamicBase *this,
        const int id,
        const idVec3 *point,
        impactInfo_t *info)
{
  memset(Dst: info, Val: 0, Size: sizeof(impactInfo_t));
}


// ========================================================================
// ?GetOrigin@idPhysics_Static@@UBAABVidVec3@@H@Z
// EA  : 0x82761DE8
// RVA : 0x00761DE8
// PDB : w:\tech5\engine\gamelib\physics\physics_static.cpp
// ========================================================================

staticPState_t *__fastcall idPhysics_Static::GetOrigin(idPhysics_Static *this, int id)
{
  return &this->current;
}


// ========================================================================
// ?GetLocalOrigin@idPhysics_Static@@UBAABVidVec3@@H@Z
// EA  : 0x82761DF0
// RVA : 0x00761DF0
// PDB : w:\tech5\engine\gamelib\physics\physics_static.cpp
// ========================================================================

const idVec3 *__fastcall idPhysics_Static::GetLocalOrigin(idPhysics_Static *this, int id)
{
  return &this->current.localOrigin;
}


// ========================================================================
// ?GetObstacleInfo@idAIMoveState@@UAAAAVidObstacleInfo@@XZ
// EA  : 0x82761DF8
// RVA : 0x00761DF8
// PDB : w:\tech5\engine\gamelib\physics\physics_static.cpp
// ========================================================================

const idMat3 *__fastcall idAIMoveState::GetObstacleInfo(idPhysics_Static *this, int id)
{
  return &this->current.localAxis;
}


// ========================================================================
// ?GetGravityNormal@idPhysics_Static@@UBAABVidVec3@@XZ
// EA  : 0x82761E00
// RVA : 0x00761E00
// PDB : w:\tech5\engine\gamelib\physics\physics_static.cpp
// ========================================================================

const idVec3 *__fastcall idPhysics_Static::GetGravityNormal(idPhysics_Static *this)
{
  return &vec3_down;
}


// ========================================================================
// ?UnlinkClip@idPhysics_Static@@UAAXXZ
// EA  : 0x82761E10
// RVA : 0x00761E10
// PDB : w:\tech5\engine\gamelib\physics\physics_static.cpp
// ========================================================================

void __fastcall idPhysics_Static::UnlinkClip(idPhysics_Static *this)
{
  idClipModel *clipModel; // r3

  clipModel = this->clipModel;
  if ( clipModel != nullptr )
    idClipModel::Unlink(this: clipModel);
}


// ========================================================================
// ?SetClipModel@idPhysics_Static@@UAAXPAVidClipModel@@MH_N@Z
// EA  : 0x82761E28
// RVA : 0x00761E28
// PDB : w:\tech5\engine\gamelib\physics\physics_static.cpp
// ========================================================================

void __fastcall idPhysics_Static::SetClipModel(
        idPhysics_Static *this,
        idClipModel *model,
        double density,
        int id,
        int freeOld,
        char a6)
{
  idClipModel *clipModel; // r3

  clipModel = this->clipModel;
  if ( clipModel != nullptr && clipModel != model && a6 != 0 )
    idClipModel::Delete(this: clipModel);
  this->clipModel = model;
  if ( model != nullptr )
    idClipModel::Link(
      this: model,
      newEntityNumber: this->entityNumber,
      newPhysicsId: this->physicsId,
      newBodyId: freeOld,
      newOrigin: &this->current.worldOrigin,
      newAxis: &this->current.worldAxis);
}


// ========================================================================
// ?GetClipModel@idPhysics_Static@@UBAPAVidClipModel@@H@Z
// EA  : 0x82761E98
// RVA : 0x00761E98
// PDB : w:\tech5\engine\gamelib\physics\physics_static.cpp
// ========================================================================

idClipModel *__fastcall idPhysics_Static::GetClipModel(idPhysics_Static *this, int id)
{
  idClipModel *result; // r3

  result = this->clipModel;
  if ( result == nullptr )
    return this->clip->defaultClipModel;
  return result;
}


// ========================================================================
// ?GetContents@idPhysics_Static@@UBAHH@Z
// EA  : 0x82761EB8
// RVA : 0x00761EB8
// PDB : w:\tech5\engine\gamelib\physics\physics_static.cpp
// ========================================================================

int __fastcall idPhysics_Static::GetContents(idPhysics_Static *this, int id)
{
  idClipModel *clipModel; // r11

  clipModel = this->clipModel;
  if ( clipModel != nullptr )
    return clipModel->contents;
  else
    return 0;
}


// ========================================================================
// ?GetBounds@idPhysics_Static@@UBAABVidBounds@@H@Z
// EA  : 0x82761ED8
// RVA : 0x00761ED8
// PDB : w:\tech5\engine\gamelib\physics\physics_static.cpp
// ========================================================================

const idBounds *__fastcall idPhysics_Static::GetBounds(idPhysics_Static *this, int id)
{
  idClipModel *clipModel; // r11

  clipModel = this->clipModel;
  if ( clipModel != nullptr )
    return &clipModel->bounds;
  else
    return &bounds_zero;
}


// ========================================================================
// ?GetAbsBounds@idPhysics_Static@@UBAABVidBounds@@H@Z
// EA  : 0x82761EF8
// RVA : 0x00761EF8
// PDB : w:\tech5\engine\gamelib\physics\physics_static.cpp
// ========================================================================

const idBounds *__fastcall idPhysics_Static::GetAbsBounds(idPhysics_Static *this, int id)
{
  idClipModel *clipModel; // r11
  double x; // fp0
  double y; // fp13
  double z; // fp12

  clipModel = this->clipModel;
  if ( clipModel != nullptr )
    return &clipModel->absBounds;
  if ( (_S13_14 & 1) == 0 )
    _S13_14 |= 1u;
  x = this->current.worldOrigin.x;
  absBounds_0.b[1].x = this->current.worldOrigin.x;
  y = this->current.worldOrigin.y;
  absBounds_0.b[1].y = this->current.worldOrigin.y;
  z = this->current.worldOrigin.z;
  absBounds_0.b[1].z = this->current.worldOrigin.z;
  absBounds_0.b[0].x = x;
  absBounds_0.b[0].y = y;
  absBounds_0.b[0].z = z;
  return &absBounds_0;
}


// ========================================================================
// ?Evaluate@idPhysics_Static@@UAA_NHH@Z
// EA  : 0x82761F60
// RVA : 0x00761F60
// PDB : w:\tech5\engine\gamelib\physics\physics_static.cpp
// ========================================================================

int __fastcall idPhysics_Static::Evaluate(idPhysics_Static *this, int timeStepMSec, int endTimeMSec)
{
  idMat3 *p_worldAxis; // r29
  char *v5; // r10
  staticPState_t *p_current; // r30
  float *p_z; // r11
  int v8; // ctr
  double v9; // fp9
  double v10; // fp5
  double v11; // fp2
  double v12; // fp1
  float *p_localAxis; // r3
  idClipModel *clipModel; // r11
  char v15; // r11
  char v16; // r3
  unsigned __int8 v17; // r11
  float v21[4]; // [sp+60h] [-C0h] BYREF
  idMat3 v22; // [sp+70h] [-B0h] BYREF
  char v23; // [sp+9Ch] [-84h] BYREF
  idMat3 v24; // [sp+A0h] [-80h] BYREF
  idMat3 v25[2]; // [sp+D0h] [-50h] BYREF
  idVec3 worldOrigin; // 0:^50.12

  if ( (*((_BYTE *)this + 68) & 0x80) == 0 )
    return 0;
  p_worldAxis = &this->current.worldAxis;
  v5 = &v23;
  p_current = &this->current;
  p_z = &this->current.worldOrigin.z;
  v8 = 9;
  worldOrigin = this->current.worldOrigin;
  do
  {
    ++p_z;
    v5 += 4;
    *(float *)v5 = *p_z;
    --v8;
  }
  while ( v8 != 0 );
  this->callbacks->GetMasterPosition(this: this->callbacks, a2: (idVec3 *)v21, a3: &v22);
  v9 = v21[1];
  v10 = v21[2];
  v11 = (float)((float)(this->current.localOrigin.y * v22.mat[1].y)
              + (float)((float)(this->current.localOrigin.x * v22.mat[0].y)
                      + (float)(this->current.localOrigin.z * v22.mat[2].y)));
  v12 = (float)((float)(this->current.localOrigin.y * v22.mat[1].z)
              + (float)((float)(this->current.localOrigin.x * v22.mat[0].z)
                      + (float)(this->current.localOrigin.z * v22.mat[2].z)));
  p_current->worldOrigin.x = (float)((float)(this->current.localOrigin.x * v22.mat[0].x)
                                   + (float)((float)(this->current.localOrigin.z * v22.mat[2].x)
                                           + (float)(this->current.localOrigin.y * v22.mat[1].x)))
                           + v21[0];
  p_current->worldOrigin.y = (float)v9 + (float)v11;
  p_current->worldOrigin.z = (float)v10 + (float)v12;
  if ( (*((_BYTE *)this + 68) & 0x40) != 0 )
    p_localAxis = (float *)idMat3::operator*(this: v25, result: &this->current.localAxis, a: &v22);
  else
    p_localAxis = (float *)&this->current.localAxis;
  p_worldAxis->mat[0].x = *p_localAxis;
  p_worldAxis->mat[0].y = p_localAxis[1];
  p_worldAxis->mat[0].z = p_localAxis[2];
  p_worldAxis->mat[1].x = p_localAxis[3];
  p_worldAxis->mat[1].y = p_localAxis[4];
  p_worldAxis->mat[1].z = p_localAxis[5];
  p_worldAxis->mat[2].x = p_localAxis[6];
  p_worldAxis->mat[2].y = p_localAxis[7];
  p_worldAxis->mat[2].z = p_localAxis[8];
  clipModel = this->clipModel;
  if ( clipModel != nullptr )
    idClipModel::Link(
      this: this->clipModel,
      newEntityNumber: this->entityNumber,
      newPhysicsId: this->physicsId,
      newBodyId: clipModel->bodyId,
      newOrigin: &p_current->worldOrigin,
      newAxis: p_worldAxis);
  if ( p_current->worldOrigin.x != worldOrigin.x
    || p_current->worldOrigin.y != worldOrigin.y
    || (v15 = 1, p_current->worldOrigin.z != worldOrigin.z) )
  {
    v15 = 0;
  }
  if ( v15 == 0 )
    return 1;
  v16 = idMat3::Compare(this: p_worldAxis, a: &v24);
  v17 = 0;
  if ( v16 == 0 )
    return 1;
  return v17;
}


// ========================================================================
// ?SetOrigin@idPhysics_Static@@UAAXABVidVec3@@H@Z
// EA  : 0x82762168
// RVA : 0x00762168
// PDB : w:\tech5\engine\gamelib\physics\physics_static.cpp
// ========================================================================

void __fastcall idPhysics_Static::SetOrigin(idPhysics_Static *this, const idVec3 *newOrigin, int id)
{
  staticPState_t *p_current; // r29
  double v6; // fp2
  double v7; // fp9
  double v8; // fp6
  double v9; // fp4
  double v10; // fp3
  idClipModel *clipModel; // r11
  float v12; // [sp+50h] [-60h] BYREF
  float v13; // [sp+54h] [-5Ch]
  float v14; // [sp+58h] [-58h]
  float v15[20]; // [sp+60h] [-50h] BYREF

  this->current.worldOrigin = *newOrigin;
  p_current = &this->current;
  if ( (*((_BYTE *)this + 68) & 0x80) != 0 )
  {
    this->callbacks->GetMasterPosition(this: this->callbacks, a2: (idVec3 *)&v12, a3: (idMat3 *)v15);
    v6 = (float)(newOrigin->x - v12);
    v7 = v15[3];
    v8 = v15[6];
    v9 = (float)((float)(v15[4] * (float)(newOrigin->y - v13)) + (float)(v15[5] * (float)(newOrigin->z - v14)));
    v10 = (float)((float)(v15[7] * (float)(newOrigin->y - v13)) + (float)(v15[8] * (float)(newOrigin->z - v14)));
    this->current.localOrigin.x = (float)(v15[0] * (float)(newOrigin->x - v12))
                                + (float)((float)(v15[1] * (float)(newOrigin->y - v13))
                                        + (float)(v15[2] * (float)(newOrigin->z - v14)));
    this->current.localOrigin.y = (float)((float)v7 * (float)v6) + (float)v9;
    this->current.localOrigin.z = (float)((float)v8 * (float)v6) + (float)v10;
  }
  else
  {
    this->current.localOrigin = *newOrigin;
  }
  clipModel = this->clipModel;
  if ( clipModel != nullptr )
    idClipModel::Link(
      this: this->clipModel,
      newEntityNumber: this->entityNumber,
      newPhysicsId: this->physicsId,
      newBodyId: clipModel->bodyId,
      newOrigin: &p_current->worldOrigin,
      newAxis: &this->current.worldAxis);
}


// ========================================================================
// ?SetAxis@idPhysics_Static@@UAAXABVidMat3@@H@Z
// EA  : 0x82762288
// RVA : 0x00762288
// PDB : w:\tech5\engine\gamelib\physics\physics_static.cpp
// ========================================================================

void __fastcall idPhysics_Static::SetAxis(idPhysics_Static *this, idMat3 *newAxis, int id)
{
  idMat3 *p_worldAxis; // r30
  idClipModel *clipModel; // r11
  _BYTE v7[16]; // [sp+50h] [-C0h] BYREF
  float v8[12]; // [sp+60h] [-B0h] BYREF
  idMat3 v9; // [sp+90h] [-80h] BYREF
  idMat3 v10[2]; // [sp+C0h] [-50h] BYREF

  this->current.worldAxis = *newAxis;
  p_worldAxis = &this->current.worldAxis;
  if ( (*((_BYTE *)this + 68) & 0x80) != 0 && (*((_BYTE *)this + 68) & 0x40) != 0 )
  {
    this->callbacks->GetMasterPosition(this: this->callbacks, a2: (idVec3 *)v7, a3: (idMat3 *)v8);
    v9.mat[0].x = v8[0];
    v9.mat[0].y = v8[3];
    v9.mat[0].z = v8[6];
    v9.mat[1].x = v8[1];
    v9.mat[1].y = v8[4];
    v9.mat[1].z = v8[7];
    v9.mat[2].x = v8[2];
    v9.mat[2].y = v8[5];
    v9.mat[2].z = v8[8];
    this->current.localAxis = *idMat3::operator*(this: v10, result: newAxis, a: &v9);
  }
  else
  {
    this->current.localAxis = *newAxis;
  }
  clipModel = this->clipModel;
  if ( clipModel != nullptr )
    idClipModel::Link(
      this: this->clipModel,
      newEntityNumber: this->entityNumber,
      newPhysicsId: this->physicsId,
      newBodyId: clipModel->bodyId,
      newOrigin: &this->current.worldOrigin,
      newAxis: p_worldAxis);
}


// ========================================================================
// ?Translate@idPhysics_Static@@UAAXABVidVec3@@H@Z
// EA  : 0x82762448
// RVA : 0x00762448
// PDB : w:\tech5\engine\gamelib\physics\physics_static.cpp
// ========================================================================

void __fastcall idPhysics_Static::Translate(idPhysics_Static *this, const idVec3 *translation, int id)
{
  double y; // fp5
  double z; // fp4
  idClipModel *clipModel; // r11

  this->current.localOrigin.x = this->current.localOrigin.x + translation->x;
  this->current.localOrigin.y = translation->y + this->current.localOrigin.y;
  this->current.localOrigin.z = translation->z + this->current.localOrigin.z;
  y = this->current.worldOrigin.y;
  z = this->current.worldOrigin.z;
  this->current.worldOrigin.x = translation->x + this->current.worldOrigin.x;
  this->current.worldOrigin.y = translation->y + (float)y;
  this->current.worldOrigin.z = translation->z + (float)z;
  clipModel = this->clipModel;
  if ( clipModel != nullptr )
    idClipModel::Link(
      this: this->clipModel,
      newEntityNumber: this->entityNumber,
      newPhysicsId: this->physicsId,
      newBodyId: clipModel->bodyId,
      newOrigin: &this->current.worldOrigin,
      newAxis: &this->current.worldAxis);
}


// ========================================================================
// ?Rotate@idPhysics_Static@@UAAXABVidRotation@@H@Z
// EA  : 0x827624E0
// RVA : 0x007624E0
// PDB : w:\tech5\engine\gamelib\physics\physics_static.cpp
// ========================================================================

void __fastcall idPhysics_Static::Rotate(idPhysics_Static *this, idRotation *rotation, int id)
{
  staticPState_t *p_current; // r30
  idRotation *v6; // r3
  idMat3 *p_worldAxis; // r29
  const idMat3 *v8; // r3
  const idMat3 *v9; // r3
  double v10; // fp2
  double x; // fp9
  double v12; // fp4
  double v13; // fp6
  double v14; // fp3
  idClipModel *clipModel; // r11
  float v16; // [sp+50h] [-70h] BYREF
  float v17; // [sp+54h] [-6Ch]
  float v18; // [sp+58h] [-68h]
  idRotation v19; // [sp+60h] [-60h] BYREF

  p_current = &this->current;
  p_worldAxis = &this->current.worldAxis;
  v6 = idRotation::operator*(this: &v19, result: rotation, v: &this->current.worldOrigin);
  this->current.worldOrigin.x = v6->origin.x;
  this->current.worldOrigin.y = v6->origin.y;
  this->current.worldOrigin.z = v6->origin.z;
  v8 = idRotation::ToMat3(this: rotation);
  idMat3::operator*=(this: &this->current.worldAxis, a: v8);
  if ( (*((_BYTE *)this + 68) & 0x80) != 0 )
  {
    this->callbacks->GetMasterPosition(this: this->callbacks, a2: (idVec3 *)&v16, a3: (idMat3 *)&v19.vec.y);
    v9 = idRotation::ToMat3(this: rotation);
    idMat3::operator*=(this: &this->current.localAxis, a: v9);
    v10 = (float)(p_current->worldOrigin.x - v16);
    x = v19.axis.mat[0].x;
    v12 = (float)((float)(v19.axis.mat[0].y * (float)(p_current->worldOrigin.y - v17))
                + (float)(v19.axis.mat[0].z * (float)(p_current->worldOrigin.z - v18)));
    v13 = v19.axis.mat[1].x;
    v14 = (float)((float)(v19.axis.mat[1].y * (float)(p_current->worldOrigin.y - v17))
                + (float)(v19.axis.mat[1].z * (float)(p_current->worldOrigin.z - v18)));
    this->current.localOrigin.x = (float)(v19.vec.y * (float)(p_current->worldOrigin.x - v16))
                                + (float)((float)(v19.vec.z * (float)(p_current->worldOrigin.y - v17))
                                        + (float)(v19.angle * (float)(p_current->worldOrigin.z - v18)));
    this->current.localOrigin.y = (float)((float)x * (float)v10) + (float)v12;
    this->current.localOrigin.z = (float)((float)v13 * (float)v10) + (float)v14;
  }
  else
  {
    this->current.localAxis.mat[0].x = p_worldAxis->mat[0].x;
    this->current.localAxis.mat[0].y = this->current.worldAxis.mat[0].y;
    this->current.localAxis.mat[0].z = this->current.worldAxis.mat[0].z;
    this->current.localAxis.mat[1].x = this->current.worldAxis.mat[1].x;
    this->current.localAxis.mat[1].y = this->current.worldAxis.mat[1].y;
    this->current.localAxis.mat[1].z = this->current.worldAxis.mat[1].z;
    this->current.localAxis.mat[2].x = this->current.worldAxis.mat[2].x;
    this->current.localAxis.mat[2].y = this->current.worldAxis.mat[2].y;
    this->current.localAxis.mat[2].z = this->current.worldAxis.mat[2].z;
    this->current.localOrigin.x = p_current->worldOrigin.x;
    this->current.localOrigin.y = p_current->worldOrigin.y;
    this->current.localOrigin.z = p_current->worldOrigin.z;
  }
  clipModel = this->clipModel;
  if ( clipModel != nullptr )
    idClipModel::Link(
      this: this->clipModel,
      newEntityNumber: this->entityNumber,
      newPhysicsId: this->physicsId,
      newBodyId: clipModel->bodyId,
      newOrigin: &p_current->worldOrigin,
      newAxis: &this->current.worldAxis);
}


// ========================================================================
// ?ClipTranslation@idPhysics_Static@@UBAXAAUtrace_t@@ABVidVec3@@PBVidClipModel@@@Z
// EA  : 0x82762690
// RVA : 0x00762690
// PDB : w:\tech5\engine\gamelib\physics\physics_static.cpp
// ========================================================================

void __fastcall idPhysics_Static::ClipTranslation(
        idPhysics_Static *this,
        trace_t *results,
        const idVec3 *translation,
        idClipModel *model)
{
  double x; // fp0
  double y; // fp13
  staticPState_t *p_current; // r5
  idMat3 *p_worldAxis; // r8
  idClipModel *clipModel; // r7
  double v10; // fp8
  double v11; // fp7
  idClip *clip; // r3
  double v13; // fp6
  int entityNumber; // r8
  double v15; // fp9
  double v16; // fp6
  const idVec3 *v17; // [sp+8h] [-A8h]
  const idMat3 *v18; // [sp+Ch] [-A4h]
  const char *v19; // [sp+10h] [-A0h]
  int v20; // [sp+14h] [-9Ch]
  int v21; // [sp+18h] [-98h]
  int v22; // [sp+1Ch] [-94h]
  int v23; // [sp+20h] [-90h]
  int v24; // [sp+24h] [-8Ch]
  int v25; // [sp+28h] [-88h]
  int v26; // [sp+2Ch] [-84h]
  int v27; // [sp+30h] [-80h]
  int v28; // [sp+34h] [-7Ch]
  int v29; // [sp+38h] [-78h]
  int v30; // [sp+3Ch] [-74h]
  int v31; // [sp+40h] [-70h]
  int v32; // [sp+44h] [-6Ch]
  int v33; // [sp+48h] [-68h]
  int v34; // [sp+4Ch] [-64h]
  int v35; // [sp+50h] [-60h]
  int v36; // [sp+58h] [-58h]
  int v37; // [sp+60h] [-50h]
  char v38; // [sp+70h] [-40h] BYREF
  idVec3 v39; // [sp+78h] [-38h] BYREF
  idVec3 v40; // [sp+88h] [-28h] BYREF

  x = translation->x;
  y = translation->y;
  if ( model != nullptr )
  {
    p_current = &this->current;
    p_worldAxis = &this->current.worldAxis;
    clipModel = this->clipModel;
    v10 = (float)((float)x + this->current.worldOrigin.x);
    v11 = (float)(this->current.worldOrigin.y + (float)y);
    v13 = (float)(this->current.worldOrigin.z + translation->z);
    clip = this->clip;
    v39.x = v10;
    v39.y = v11;
    v39.z = v13;
    idClip::TranslationModel(
      this: clip,
      result: results,
      start: &p_current->worldOrigin,
      end: &v39,
      trm: clipModel,
      trmAxis: p_worldAxis,
      clipMask: 1,
      model,
      modelOrigin: v17,
      modelAxis: v18,
      a11: (int)v19,
      a12: v20,
      a13: v21,
      a14: v22,
      a15: v23,
      a16: v24,
      a17: v25,
      a18: v26,
      a19: v27,
      a20: v28,
      a21: v29,
      a22: v30,
      a23: v31,
      a24: v32,
      a25: v33,
      a26: v34,
      a27: v35,
      a28: &model->origin.x,
      a29: v36,
      a30: (float *)&model->axis);
  }
  else
  {
    entityNumber = this->entityNumber;
    v15 = (float)(this->current.worldOrigin.y + translation->y);
    v16 = (float)(this->current.worldOrigin.z + translation->z);
    v40.x = translation->x + this->current.worldOrigin.x;
    v40.y = v15;
    v40.z = v16;
    idClip::Translation(
      this: (idClip *)&v38,
      result: this->clip,
      a3: results,
      start: &this->current.worldOrigin,
      end: &v40,
      clipModel: this->clipModel,
      startAxis: &this->current.worldAxis,
      clipMask: 1,
      passEntityNumber: (int)v17,
      moveClipModel: (bool)v18,
      userName: v19,
      a12: v20,
      a13: v21,
      a14: v22,
      a15: v23,
      a16: v24,
      a17: v25,
      a18: v26,
      a19: v27,
      a20: v28,
      a21: v29,
      a22: v30,
      a23: v31,
      a24: v32,
      a25: v33,
      a26: v34,
      a27: v35,
      a28: entityNumber,
      a29: v36,
      a30: false,
      a31: v37,
      a32: 0);
  }
}


// ========================================================================
// ?ClipRotation@idPhysics_Static@@UBAXAAUtrace_t@@ABVidRotation@@PBVidClipModel@@@Z
// EA  : 0x82762790
// RVA : 0x00762790
// PDB : w:\tech5\engine\gamelib\physics\physics_static.cpp
// ========================================================================

void __fastcall idPhysics_Static::ClipRotation(
        idPhysics_Static *this,
        trace_t *results,
        idRotation *rotation,
        idClipModel *model)
{
  const idVec3 *v4; // [sp+8h] [-88h]
  const idMat3 *v5; // [sp+Ch] [-84h]
  const char *v6; // [sp+10h] [-80h]
  int v7; // [sp+14h] [-7Ch]
  int v8; // [sp+18h] [-78h]
  int v9; // [sp+1Ch] [-74h]
  int v10; // [sp+20h] [-70h]
  int v11; // [sp+24h] [-6Ch]
  int v12; // [sp+28h] [-68h]
  int v13; // [sp+2Ch] [-64h]
  int v14; // [sp+30h] [-60h]
  int v15; // [sp+34h] [-5Ch]
  int v16; // [sp+38h] [-58h]
  int v17; // [sp+3Ch] [-54h]
  int v18; // [sp+40h] [-50h]
  int v19; // [sp+44h] [-4Ch]
  int v20; // [sp+48h] [-48h]
  int v21; // [sp+4Ch] [-44h]
  int v22; // [sp+50h] [-40h]
  int v23; // [sp+58h] [-38h]
  int v24; // [sp+60h] [-30h]
  char v25; // [sp+70h] [-20h] BYREF

  if ( model != nullptr )
    idClip::RotationModel(
      this: this->clip,
      result: results,
      start: (const idMat3 *)&this->current,
      rotation,
      trm: this->clipModel,
      trmAxis: &this->current.worldAxis,
      clipMask: (const idVec3 *)1,
      model,
      modelOrigin: v4,
      modelAxis: v5,
      a11: (int)v6,
      a12: v7,
      a13: v8,
      a14: v9,
      a15: v10,
      a16: v11,
      a17: v12,
      a18: v13,
      a19: v14,
      a20: v15,
      a21: v16,
      a22: v17,
      a23: v18,
      a24: v19,
      a25: v20,
      a26: v21,
      a27: v22,
      a28: &model->origin.x,
      a29: v23,
      a30: (float *)&model->axis);
  else
    idClip::Rotation(
      this: (idClip *)&v25,
      result: this->clip,
      a3: results,
      start: (const idMat3 *)&this->current,
      rotation,
      clipModel: this->clipModel,
      startAxis: &this->current.worldAxis,
      clipMask: 1,
      passEntityNumber: (int)v4,
      moveClipModel: (bool)v5,
      userName: v6,
      a12: v7,
      a13: v8,
      a14: v9,
      a15: v10,
      a16: v11,
      a17: v12,
      a18: v13,
      a19: v14,
      a20: v15,
      a21: v16,
      a22: v17,
      a23: v18,
      a24: v19,
      a25: v20,
      a26: v21,
      a27: v22,
      a28: this->entityNumber,
      a29: v23,
      a30: false,
      a31: v24,
      a32: 0);
}


// ========================================================================
// ?DisableClip@idPhysics_Static@@UAAXXZ
// EA  : 0x82762840
// RVA : 0x00762840
// PDB : w:\tech5\engine\gamelib\physics\physics_static.cpp
// ========================================================================

void __fastcall idPhysics_Static::DisableClip(idPhysics_Static *this)
{
  idClipModel *clipModel; // r11

  clipModel = this->clipModel;
  if ( clipModel != nullptr )
    clipModel->enabled = false;
}


// ========================================================================
// ?EnableClip@idPhysics_Static@@UAAXXZ
// EA  : 0x82762858
// RVA : 0x00762858
// PDB : w:\tech5\engine\gamelib\physics\physics_static.cpp
// ========================================================================

void __fastcall idPhysics_Static::EnableClip(idPhysics_Static *this)
{
  idClipModel *clipModel; // r11

  clipModel = this->clipModel;
  if ( clipModel != nullptr )
    clipModel->enabled = true;
}


// ========================================================================
// ?LinkClip@idPhysics_Static@@UAAXXZ
// EA  : 0x82762870
// RVA : 0x00762870
// PDB : w:\tech5\engine\gamelib\physics\physics_static.cpp
// ========================================================================

void __fastcall idPhysics_Static::LinkClip(idPhysics_Static *this)
{
  idClipModel *clipModel; // r11

  clipModel = this->clipModel;
  if ( clipModel != nullptr )
    idClipModel::Link(
      this: this->clipModel,
      newEntityNumber: this->entityNumber,
      newPhysicsId: this->physicsId,
      newBodyId: clipModel->bodyId,
      newOrigin: &this->current.worldOrigin,
      newAxis: &this->current.worldAxis);
}


// ========================================================================
// ?GetContact@idPhysics_Static@@UBAABUcontactInfo_t@@H@Z
// EA  : 0x827628A0
// RVA : 0x007628A0
// PDB : w:\tech5\engine\gamelib\physics\physics_static.cpp
// ========================================================================

const contactInfo_t *__fastcall idPhysics_Static::GetContact(idPhysics_Static *this, int num)
{
  if ( (_S14_2 & 1) == 0 )
    _S14_2 |= 1u;
  memset(Dst: &info, Val: 0, Size: sizeof(info));
  return &info;
}


// ========================================================================
// ?RemoveContactPhysics@idPhysics_Static@@UAAXPAVidPhysics@@@Z
// EA  : 0x82762900
// RVA : 0x00762900
// PDB : w:\tech5\engine\gamelib\physics\physics_static.cpp
// ========================================================================

void __fastcall idPhysics_Static::RemoveContactPhysics(idPhysics_Static *this, idPhysics *phys)
{
  int v4; // r31
  idList<int,77> *p_contactPhysicsIds; // r30
  int v6; // r29
  idPhysics *PhysicsForId; // r3
  int num; // r11
  int v9; // r11

  v4 = 0;
  if ( this->contactPhysicsIds.num > 0 )
  {
    p_contactPhysicsIds = &this->contactPhysicsIds;
    v6 = 0;
    do
    {
      PhysicsForId = idPhysics::GetPhysicsForId(physicsId_: p_contactPhysicsIds->list[v6]);
      if ( PhysicsForId == nullptr || PhysicsForId == phys )
      {
        if ( v4 >= 0 )
        {
          num = p_contactPhysicsIds->num;
          if ( v4 < num )
          {
            v9 = num - 1;
            p_contactPhysicsIds->num = v9;
            if ( v4 != v9 )
              p_contactPhysicsIds->list[v6] = p_contactPhysicsIds->list[v9];
          }
        }
        --v6;
        --v4;
      }
      ++v4;
      ++v6;
    }
    while ( v4 < this->contactPhysicsIds.num );
  }
}


// ========================================================================
// ?GetContactPhysics@idPhysics_Static@@UBAPAVidPhysics@@H@Z
// EA  : 0x827629A0
// RVA : 0x007629A0
// PDB : w:\tech5\engine\gamelib\physics\physics_static.cpp
// ========================================================================

idPhysics *__fastcall idPhysics_Static::GetContactPhysics(idPhysics_Static *this, int index)
{
  return idPhysics::GetPhysicsForId(physicsId_: this->contactPhysicsIds.list[index]);
}


// ========================================================================
// ?ActivateContactPhysics@idPhysics_Static@@UAAXXZ
// EA  : 0x827629B0
// RVA : 0x007629B0
// PDB : w:\tech5\engine\gamelib\physics\physics_static.cpp
// ========================================================================

void __fastcall idPhysics_Static::ActivateContactPhysics(idPhysics_Static *this)
{
  int v2; // r31
  idList<int,77> *p_contactPhysicsIds; // r29
  int v4; // r30
  idPhysics *PhysicsForId; // r3
  int num; // r11
  int v7; // r11

  v2 = 0;
  if ( this->contactPhysicsIds.num > 0 )
  {
    p_contactPhysicsIds = &this->contactPhysicsIds;
    v4 = 0;
    do
    {
      PhysicsForId = idPhysics::GetPhysicsForId(physicsId_: p_contactPhysicsIds->list[v4]);
      if ( PhysicsForId != nullptr )
      {
        PhysicsForId->callbacks->ActivatePhysics(this: PhysicsForId->callbacks, a2: this->physicsId);
      }
      else
      {
        if ( v2 >= 0 )
        {
          num = p_contactPhysicsIds->num;
          if ( v2 < num )
          {
            v7 = num - 1;
            p_contactPhysicsIds->num = v7;
            if ( v2 != v7 )
              p_contactPhysicsIds->list[v4] = p_contactPhysicsIds->list[v7];
          }
        }
        --v2;
        --v4;
      }
      ++v2;
      ++v4;
    }
    while ( v2 < this->contactPhysicsIds.num );
  }
}


// ========================================================================
// ?SetMaster@idPhysics_Static@@UAAX_NABVidVec3@@ABVidMat3@@W4bindFlags_t@@@Z
// EA  : 0x82762A60
// RVA : 0x00762A60
// PDB : w:\tech5\engine\gamelib\physics\physics_static.cpp
// ========================================================================

void __fastcall idPhysics_Static::SetMaster(
        idPhysics_Static *this,
        bool enable,
        const idVec3 *masterOrigin,
        const idMat3 *masterAxis,
        const bindFlags_t bflags)
{
  char v6; // r30
  double v7; // fp2
  double x; // fp7
  double v9; // fp5
  double v10; // fp1
  double v11; // fp0
  double z; // fp13
  double v13; // fp12
  double y; // fp11
  double v15; // fp10
  double v16; // fp9
  double v17; // fp8
  double v18; // fp7
  double v19; // fp6
  idMat3 v20; // [sp+50h] [-70h] BYREF
  idMat3 v21; // [sp+80h] [-40h] BYREF

  if ( enable )
  {
    if ( (*((_BYTE *)this + 68) & 0x80) == 0 )
    {
      v6 = bflags & 1;
      v7 = (float)(this->current.worldOrigin.x - masterOrigin->x);
      x = masterAxis->mat[2].x;
      v9 = masterAxis->mat[1].x;
      v10 = (float)((float)((float)(this->current.worldOrigin.y - masterOrigin->y) * masterAxis->mat[1].y)
                  + (float)((float)(this->current.worldOrigin.z - masterOrigin->z) * masterAxis->mat[1].z));
      v11 = (float)((float)((float)(this->current.worldOrigin.y - masterOrigin->y) * masterAxis->mat[2].y)
                  + (float)((float)(this->current.worldOrigin.z - masterOrigin->z) * masterAxis->mat[2].z));
      this->current.localOrigin.x = (float)((float)(this->current.worldOrigin.x - masterOrigin->x) * masterAxis->mat[0].x)
                                  + (float)((float)((float)(this->current.worldOrigin.y - masterOrigin->y)
                                                  * masterAxis->mat[0].y)
                                          + (float)((float)(this->current.worldOrigin.z - masterOrigin->z)
                                                  * masterAxis->mat[0].z));
      this->current.localOrigin.y = (float)((float)v7 * (float)v9) + (float)v10;
      this->current.localOrigin.z = (float)((float)v7 * (float)x) + (float)v11;
      if ( (bflags & 1) != 0 )
      {
        z = masterAxis->mat[1].z;
        v13 = masterAxis->mat[0].z;
        y = masterAxis->mat[2].y;
        v15 = masterAxis->mat[1].y;
        v16 = masterAxis->mat[0].y;
        v17 = masterAxis->mat[2].x;
        v18 = masterAxis->mat[1].x;
        v19 = masterAxis->mat[0].x;
        v20.mat[2].z = masterAxis->mat[2].z;
        v20.mat[2].y = z;
        v20.mat[2].x = v13;
        v20.mat[1].z = y;
        v20.mat[1].y = v15;
        v20.mat[1].x = v16;
        v20.mat[0].z = v17;
        v20.mat[0].y = v18;
        v20.mat[0].x = v19;
        this->current.localAxis = *idMat3::operator*(this: &v21, result: &this->current.worldAxis, a: &v20);
      }
      else
      {
        this->current.localAxis = this->current.worldAxis;
      }
      *((_BYTE *)this + 68) = (v6 << 6) | 0x80 | *((_BYTE *)this + 68) & 0x3F;
    }
  }
  else if ( (*((_BYTE *)this + 68) & 0x80) != 0 )
  {
    *((_BYTE *)this + 68) &= ~0x80u;
  }
}


// ========================================================================
// ?SetLocalOrigin@idPhysics_Static@@UAAXABVidVec3@@H@Z
// EA  : 0x82762C50
// RVA : 0x00762C50
// PDB : w:\tech5\engine\gamelib\physics\physics_static.cpp
// ========================================================================

void __fastcall idPhysics_Static::SetLocalOrigin(idPhysics_Static *this, const idVec3 *newOrigin, int id)
{
  double v5; // fp9
  double v6; // fp6
  double v7; // fp2
  double v8; // fp1
  double z; // fp12
  idClipModel *clipModel; // r11
  float v11[4]; // [sp+50h] [-50h] BYREF
  float v12[10]; // [sp+60h] [-40h] BYREF

  this->current.localOrigin = *newOrigin;
  if ( (*((_BYTE *)this + 68) & 0x80) != 0 )
  {
    this->callbacks->GetMasterPosition(this: this->callbacks, a2: (idVec3 *)v11, a3: (idMat3 *)v12);
    v5 = v11[0];
    v6 = v11[2];
    v7 = (float)((float)(newOrigin->x * v12[0])
               + (float)((float)(newOrigin->y * v12[3]) + (float)(newOrigin->z * v12[6])));
    v8 = (float)((float)(newOrigin->x * v12[2])
               + (float)((float)(newOrigin->z * v12[8]) + (float)(newOrigin->y * v12[5])));
    this->current.worldOrigin.y = v11[1]
                                + (float)((float)(newOrigin->x * v12[1])
                                        + (float)((float)(newOrigin->z * v12[7]) + (float)(newOrigin->y * v12[4])));
    this->current.worldOrigin.x = (float)v7 + (float)v5;
    z = (float)((float)v6 + (float)v8);
  }
  else
  {
    this->current.worldOrigin.x = newOrigin->x;
    this->current.worldOrigin.y = newOrigin->y;
    z = newOrigin->z;
  }
  this->current.worldOrigin.z = z;
  clipModel = this->clipModel;
  if ( clipModel != nullptr )
    idClipModel::Link(
      this: this->clipModel,
      newEntityNumber: this->entityNumber,
      newPhysicsId: this->physicsId,
      newBodyId: clipModel->bodyId,
      newOrigin: &this->current.worldOrigin,
      newAxis: &this->current.worldAxis);
}


// ========================================================================
// ?SetLocalAxis@idPhysics_Static@@UAAXABVidMat3@@H@Z
// EA  : 0x82762D80
// RVA : 0x00762D80
// PDB : w:\tech5\engine\gamelib\physics\physics_static.cpp
// ========================================================================

void __fastcall idPhysics_Static::SetLocalAxis(idPhysics_Static *this, idMat3 *newAxis, int id)
{
  idVec3 *v5; // r3
  double z; // fp6
  idClipModel *clipModel; // r11
  _BYTE v8[16]; // [sp+50h] [-80h] BYREF
  idMat3 v9; // [sp+60h] [-70h] BYREF
  idMat3 v10; // [sp+90h] [-40h] BYREF

  this->current.localAxis = *newAxis;
  if ( (*((_BYTE *)this + 68) & 0x80) != 0 && (*((_BYTE *)this + 68) & 0x40) != 0 )
  {
    this->callbacks->GetMasterPosition(this: this->callbacks, a2: (idVec3 *)v8, a3: &v9);
    v5 = (idVec3 *)idMat3::operator*(this: &v10, result: newAxis, a: &v9);
    this->current.worldAxis.mat[0] = *v5;
    this->current.worldAxis.mat[1] = v5[1];
    this->current.worldAxis.mat[2].x = v5[2].x;
    this->current.worldAxis.mat[2].y = v5[2].y;
    z = v5[2].z;
  }
  else
  {
    this->current.worldAxis.mat[0] = newAxis->mat[0];
    this->current.worldAxis.mat[1] = newAxis->mat[1];
    this->current.worldAxis.mat[2].x = newAxis->mat[2].x;
    this->current.worldAxis.mat[2].y = newAxis->mat[2].y;
    z = newAxis->mat[2].z;
  }
  this->current.worldAxis.mat[2].z = z;
  clipModel = this->clipModel;
  if ( clipModel != nullptr )
    idClipModel::Link(
      this: this->clipModel,
      newEntityNumber: this->entityNumber,
      newPhysicsId: this->physicsId,
      newBodyId: clipModel->bodyId,
      newOrigin: &this->current.worldOrigin,
      newAxis: &this->current.worldAxis);
}


// ========================================================================
// ??0idPhysics_Static@@QAA@XZ
// EA  : 0x82762F10
// RVA : 0x00762F10
// PDB : w:\tech5\engine\gamelib\physics\physics_static.cpp
// ========================================================================

idPhysics_Static *__fastcall idPhysics_Static::idPhysics_Static(idPhysics_Static *this)
{
  idPhysics::idPhysics(this);
  this->__vftable = (idPhysics_Static_vtbl *)&idPhysics_Static::`vftable';
  this->contactPhysicsIds.list = nullptr;
  this->contactPhysicsIds.granularity = 0;
  this->contactPhysicsIds.memTag = 77;
  this->contactPhysicsIds.listStatic = 0;
  this->contactPhysicsIds.size = 0;
  this->contactPhysicsIds.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->contactPhysicsIds);
  this->clipModel = nullptr;
  this->type = PHYSICS_STATIC;
  this->current.worldOrigin.z = 0.0;
  this->current.worldOrigin.y = 0.0;
  this->current.worldOrigin.x = 0.0;
  this->current.worldAxis.mat[2].z = 1.0;
  this->current.worldAxis.mat[1].y = 1.0;
  this->current.worldAxis.mat[0].x = 1.0;
  this->current.worldAxis.mat[1].z = 0.0;
  this->current.worldAxis.mat[0].z = 0.0;
  this->current.worldAxis.mat[0].y = 0.0;
  this->current.worldAxis.mat[2].y = 0.0;
  this->current.worldAxis.mat[2].x = 0.0;
  this->current.worldAxis.mat[1].x = 0.0;
  this->current.localOrigin.z = 0.0;
  this->current.localOrigin.y = 0.0;
  this->current.localOrigin.x = 0.0;
  this->current.localAxis.mat[2].z = 1.0;
  this->current.localAxis.mat[1].y = 1.0;
  this->current.localAxis.mat[0].x = 1.0;
  this->current.localAxis.mat[1].z = 0.0;
  this->current.localAxis.mat[0].z = 0.0;
  this->current.localAxis.mat[0].y = 0.0;
  this->current.localAxis.mat[2].y = 0.0;
  this->current.localAxis.mat[2].x = 0.0;
  this->current.localAxis.mat[1].x = 0.0;
  *((_BYTE *)this + 68) &= 0x3Fu;
  return this;
}


// ========================================================================
// __unwind$248693
// EA  : 0x82763014
// RVA : 0x00763014
// PDB : w:\tech5\engine\gamelib\physics\physics_static.cpp
// ========================================================================

void _unwind_248693()
{
  int v0; // r12

  idPhysics::~idPhysics(this: *(idPhysics **)(v0 - 128 + 148));
}


// ========================================================================
// ??1idPhysics_Static@@UAA@XZ
// EA  : 0x82763048
// RVA : 0x00763048
// PDB : w:\tech5\engine\gamelib\physics\physics_static.cpp
// ========================================================================

void __fastcall idPhysics_Static::~idPhysics_Static(idPhysics_Static *this)
{
  idClipModel *clipModel; // r3

  this->__vftable = (idPhysics_Static_vtbl *)&idPhysics_Static::`vftable';
  clipModel = this->clipModel;
  if ( clipModel != nullptr )
    idClipModel::Delete(this: clipModel);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->contactPhysicsIds);
  idPhysics::~idPhysics(this);
}


// ========================================================================
// __unwind$248966
// EA  : 0x827630AC
// RVA : 0x007630AC
// PDB : w:\tech5\engine\gamelib\physics\physics_static.cpp
// ========================================================================

void _unwind_248966()
{
  int v0; // r12

  idPhysics::~idPhysics(this: *(idPhysics **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$248967
// EA  : 0x827630D4
// RVA : 0x007630D4
// PDB : w:\tech5\engine\gamelib\physics\physics_static.cpp
// ========================================================================

void _unwind_248967()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 52));
}


// ========================================================================
// ?ClipContents@idPhysics_Static@@UBAHPBVidClipModel@@H@Z
// EA  : 0x82763100
// RVA : 0x00763100
// PDB : w:\tech5\engine\gamelib\physics\physics_static.cpp
// ========================================================================

int __fastcall idPhysics_Static::ClipContents(idPhysics_Static *this, idClipModel *model, int clipMask)
{
  int v3; // r8
  int v5; // r9
  const idMat3 *v6; // [sp+8h] [-F8h]
  int v7; // [sp+Ch] [-F4h]
  int v8; // [sp+10h] [-F0h]
  int v9; // [sp+14h] [-ECh]
  int v10; // [sp+18h] [-E8h]
  int v11; // [sp+1Ch] [-E4h]
  int v12; // [sp+20h] [-E0h]
  int v13; // [sp+24h] [-DCh]
  int v14; // [sp+28h] [-D8h]
  int v15; // [sp+2Ch] [-D4h]
  int v16; // [sp+30h] [-D0h]
  int v17; // [sp+34h] [-CCh]
  int v18; // [sp+38h] [-C8h]
  int v19; // [sp+3Ch] [-C4h]
  int v20; // [sp+40h] [-C0h]
  int v21; // [sp+44h] [-BCh]
  int v22; // [sp+48h] [-B8h]
  int v23; // [sp+4Ch] [-B4h]
  int v24; // [sp+50h] [-B0h]
  char v25; // [sp+60h] [-A0h] BYREF
  trace_t v26; // [sp+70h] [-90h] BYREF

  if ( this->clipModel == nullptr )
    return 0;
  if ( model != nullptr )
  {
    v3 = clipMask;
    if ( clipMask == 0 )
      v3 = -1;
    idClip::ContentsModel(
      this: this->clip,
      result: &v26,
      start: &this->clipModel->origin,
      trm: this->clipModel,
      trmAxis: &this->clipModel->axis,
      clipMask: v3,
      model,
      modelOrigin: &model->origin,
      modelAxis: v6,
      a10: v7,
      a11: v8,
      a12: v9,
      a13: v10,
      a14: v11,
      a15: v12,
      a16: v13,
      a17: v14,
      a18: v15,
      a19: v16,
      a20: v17,
      a21: v18,
      a22: v19,
      a23: v20,
      a24: v21,
      a25: v22,
      a26: v23,
      a27: v24,
      a28: (float *)&model->axis);
    return v26.c.contentFlags;
  }
  else
  {
    v5 = clipMask;
    if ( clipMask == 0 )
      v5 = -1;
    idClip::Contents(
      this: (idClip *)&v25,
      result: this->clip,
      a3: &v26,
      start: &this->clipModel->origin,
      clipModel: this->clipModel,
      startAxis: &this->clipModel->axis,
      clipMask: v5,
      passEntityNumber: 0x1FFF,
      userName: (const char *)v6,
      a10: v7,
      a11: v8,
      a12: v9,
      a13: v10,
      a14: v11,
      a15: v12,
      a16: v13,
      a17: v14,
      a18: v15,
      a19: v16,
      a20: v17,
      a21: v18,
      a22: v19,
      a23: v20,
      a24: v21,
      a25: v22,
      a26: v23,
      a27: v24,
      a28: 0);
    return v26.c.contentFlags;
  }
}


// ========================================================================
// ?AddContactPhysics@idPhysics_Static@@UAAXPAVidPhysics@@@Z
// EA  : 0x82763230
// RVA : 0x00763230
// PDB : w:\tech5\engine\gamelib\physics\physics_static.cpp
// ========================================================================

void __fastcall idPhysics_Static::AddContactPhysics(idPhysics_Static *this, idPhysics *phys)
{
  char v4; // r26
  int v5; // r31
  idList<int,77> *p_contactPhysicsIds; // r29
  int v7; // r30
  idPhysics *PhysicsForId; // r3
  int num; // r11
  int v10; // r11
  int physicsId; // r30
  int v12; // r11
  int size; // r10
  int *list; // r9

  v4 = 0;
  v5 = 0;
  if ( this->contactPhysicsIds.num > 0 )
  {
    p_contactPhysicsIds = &this->contactPhysicsIds;
    v7 = 0;
    do
    {
      PhysicsForId = idPhysics::GetPhysicsForId(physicsId_: p_contactPhysicsIds->list[v7]);
      if ( PhysicsForId != nullptr )
      {
        if ( PhysicsForId == phys )
          v4 = 1;
      }
      else
      {
        if ( v5 >= 0 )
        {
          num = p_contactPhysicsIds->num;
          if ( v5 < num )
          {
            v10 = num - 1;
            p_contactPhysicsIds->num = v10;
            if ( v5 != v10 )
              p_contactPhysicsIds->list[v7] = p_contactPhysicsIds->list[v10];
          }
        }
        --v5;
        --v7;
      }
      ++v5;
      ++v7;
    }
    while ( v5 < this->contactPhysicsIds.num );
  }
  if ( v4 == 0 )
  {
    physicsId = phys->physicsId;
    idList<idMD6Node *,5>::PreAllocateWithGranularity(
      this: (idList<idMD6Filter *,5> *)&this->contactPhysicsIds,
      newSize: this->contactPhysicsIds.num + 1);
    v12 = this->contactPhysicsIds.num;
    size = this->contactPhysicsIds.size;
    list = this->contactPhysicsIds.list;
    if ( v12 >= size )
    {
      list[size - 1] = physicsId;
    }
    else
    {
      this->contactPhysicsIds.num = v12 + 1;
      list[v12] = physicsId;
    }
  }
}

