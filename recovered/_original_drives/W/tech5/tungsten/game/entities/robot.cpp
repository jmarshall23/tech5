
// ========================================================================
// ??1idPhysics_Robot@@UAA@XZ
// EA  : 0x82CADBE0
// RVA : 0x00CADBE0
// PDB : w:\tech5\tungsten\game\entities\robot.cpp
// ========================================================================

void __fastcall idPhysics_Robot::~idPhysics_Robot(idPhysics_Robot *this)
{
  idClipModel *clipModel; // r3

  this->__vftable = (idPhysics_Robot_vtbl *)&idPhysics_Robot::`vftable';
  clipModel = this->clipModel;
  if ( clipModel != nullptr )
    idClipModel::Delete(this: clipModel);
  this->clipModel = nullptr;
  idPhysics_DynamicBase::~idPhysics_DynamicBase(this);
}


// ========================================================================
// __unwind$490165
// EA  : 0x82CADC44
// RVA : 0x00CADC44
// PDB : w:\tech5\tungsten\game\entities\robot.cpp
// ========================================================================

void _unwind_490165()
{
  int v0; // r12

  idPhysics_DynamicBase::~idPhysics_DynamicBase(this: *(idPhysics_DynamicBase **)(v0 - 112 + 132));
}


// ========================================================================
// ?SetClipModel@idPhysics_Robot@@UAAXPAVidClipModel@@MH_N@Z
// EA  : 0x82CADC70
// RVA : 0x00CADC70
// PDB : w:\tech5\tungsten\game\entities\robot.cpp
// ========================================================================

void __fastcall idPhysics_Robot::SetClipModel(
        idPhysics_Robot *this,
        idClipModel *model,
        double density,
        int id,
        bool freeOld,
        char a6)
{
  idClipModel *clipModel; // r3

  if ( a6 != 0 )
  {
    clipModel = this->clipModel;
    if ( clipModel != nullptr )
      idClipModel::Delete(this: clipModel);
  }
  this->clipModel = model;
  ((void (__fastcall *)(idPhysics_Robot *, idClipModel *, int, bool, double))this->LinkClip)(
    a1: this,
    a2: model,
    a3: id,
    a4: freeOld,
    a5: density);
}


// ========================================================================
// ?GetNumClipModels@idPhysics_Robot@@UBAHXZ
// EA  : 0x82CADCD8
// RVA : 0x00CADCD8
// PDB : w:\tech5\tungsten\game\entities\robot.cpp
// ========================================================================

BOOL __fastcall idPhysics_Robot::GetNumClipModels(idPhysics_Robot *this)
{
  return this->clipModel != nullptr;
}


// ========================================================================
// ?SetMass@idPhysics_Robot@@UAAXMH@Z
// EA  : 0x82CADCF0
// RVA : 0x00CADCF0
// PDB : w:\tech5\tungsten\game\entities\robot.cpp
// ========================================================================

void __fastcall idPhysics_Robot::SetMass(idPhysics_Robot *this, double mass_, int id)
{
  this->mass = mass_;
  this->invMass = (float)1.0 / (float)mass_;
}


// ========================================================================
// ?GetMass@idPhysics_Robot@@UBAMH@Z
// EA  : 0x82CADD08
// RVA : 0x00CADD08
// PDB : w:\tech5\tungsten\game\entities\robot.cpp
// ========================================================================

float __fastcall idPhysics_Robot::GetMass(idPhysics_Robot *this, int id)
{
  double mass; // fp1

  mass = this->mass;
  return *((float *)&mass + 1);
}


// ========================================================================
// ?SetContents@idPhysics_Robot@@UAAXHH@Z
// EA  : 0x82CADD10
// RVA : 0x00CADD10
// PDB : w:\tech5\tungsten\game\entities\robot.cpp
// ========================================================================

void __fastcall idPhysics_Robot::SetContents(idPhysics_Robot *this, int contents, int id)
{
  idClipModel::SetContents(this: this->clipModel, newContents: contents);
}


// ========================================================================
// ?UnlinkClip@idPhysics_Robot@@UAAXXZ
// EA  : 0x82CADD18
// RVA : 0x00CADD18
// PDB : w:\tech5\tungsten\game\entities\robot.cpp
// ========================================================================

void __fastcall idPhysics_Robot::UnlinkClip(idPhysics_Robot *this)
{
  idClipModel *clipModel; // r3

  clipModel = this->clipModel;
  if ( clipModel != nullptr )
    idClipModel::Unlink(this: clipModel);
}


// ========================================================================
// ?GetLinearVelocity@idPhysics_Robot@@UBA?AVidVec3@@H@Z
// EA  : 0x82CADD30
// RVA : 0x00CADD30
// PDB : w:\tech5\tungsten\game\entities\robot.cpp
// ========================================================================

idPhysics_Robot *__fastcall idPhysics_Robot::GetLinearVelocity(idPhysics_Robot *this, idVec3 *result, int id)
{
  float z; // r10
  float x; // r9

  z = result[19].z;
  x = result[20].x;
  this->__vftable = (idPhysics_Robot_vtbl *)LODWORD(result[19].y);
  *((float *)&this->__vftable + 1) = z;
  *(float *)&this->type = x;
  return this;
}


// ========================================================================
// ?GetAngularVelocity@idPhysics_Robot@@UBA?AVidVec3@@H@Z
// EA  : 0x82CADD50
// RVA : 0x00CADD50
// PDB : w:\tech5\tungsten\game\entities\robot.cpp
// ========================================================================

idPhysics_Robot *__fastcall idPhysics_Robot::GetAngularVelocity(idPhysics_Robot *this, idVec3 *result, int id)
{
  float z; // r10
  float x; // r9

  z = result[20].z;
  x = result[21].x;
  this->__vftable = (idPhysics_Robot_vtbl *)LODWORD(result[20].y);
  *((float *)&this->__vftable + 1) = z;
  *(float *)&this->type = x;
  return this;
}


// ========================================================================
// ?GetImpactInfo@idPhysics_Robot@@UBAXHABVidVec3@@AAUimpactInfo_t@@@Z
// EA  : 0x82CADDD0
// RVA : 0x00CADDD0
// PDB : w:\tech5\tungsten\game\entities\robot.cpp
// ========================================================================

void __fastcall idPhysics_Robot::GetImpactInfo(
        idPhysics_Robot *this,
        const int id,
        const idVec3 *point,
        impactInfo_t *info)
{
  int i; // r9
  int v5; // r11
  int j; // ctr
  int v7; // r10

  info->invMass = this->invMass;
  for ( i = 0; i < 9; i += 3 )
  {
    v5 = 0;
    for ( j = 3; j != 0; --j )
    {
      v7 = i + v5++ + 1;
      *(&info->invMass + v7) = 0.0;
    }
  }
  info->position.z = 0.0;
  info->position.y = 0.0;
  info->position.x = 0.0;
  info->velocity = this->currentState.linearVelocity;
}


// ========================================================================
// ?ApplyImpulse@idPhysics_Robot@@UAAXHABVidVec3@@0@Z
// EA  : 0x82CADE40
// RVA : 0x00CADE40
// PDB : w:\tech5\tungsten\game\entities\robot.cpp
// ========================================================================

void __fastcall idPhysics_Robot::ApplyImpulse(
        idPhysics_Robot *this,
        const int id,
        const idVec3 *point,
        const idVec3 *impulse)
{
  double v5; // fp11
  double x; // fp7
  double v7; // fp8
  double z; // fp5
  idVec3 *p_linearVelocity; // r31
  double v10; // fp3
  double v11; // fp7
  double v14; // fp3
  double v15; // fp9
  double v16; // fp10
  double v17; // fp9

  if ( !this->noImpact )
  {
    v5 = (float)(impulse->x * this->invMass);
    x = this->currentState.linearVelocity.x;
    v7 = (float)(impulse->z * this->invMass);
    z = this->currentState.linearVelocity.z;
    p_linearVelocity = &this->currentState.linearVelocity;
    v10 = (float)(this->currentState.linearVelocity.y + (float)(impulse->y * this->invMass));
    this->currentState.linearVelocity.y = this->currentState.linearVelocity.y + (float)(impulse->y * this->invMass);
    this->currentState.linearVelocity.x = (float)x + (float)v5;
    this->currentState.linearVelocity.z = (float)z + (float)v7;
    v11 = (float)((float)((float)((float)z + (float)v7) * (float)((float)z + (float)v7))
                + (float)((float)((float)((float)x + (float)v5) * (float)((float)x + (float)v5))
                        + (float)((float)v10 * (float)v10)));
    _FP6 = (float)((float)v11 - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm { fsel      f4, f6, f7, f13 }
    v14 = __frsqrte(_FP4);
    v15 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v14
                                                                                        * (float)((float)v11 * (float)0.5))
                                                                                * (float)v14)
                                                                        - (float)1.5)
                                                        * (float)v14)
                                                * (float)((float)v11 * (float)0.5))
                                        * (float)((float)-(float)((float)((float)((float)v14
                                                                                * (float)((float)v11 * (float)0.5))
                                                                        * (float)v14)
                                                                - (float)1.5)
                                                * (float)v14))
                                - (float)1.5)
                * (float)((float)-(float)((float)((float)((float)v14 * (float)((float)v11 * (float)0.5)) * (float)v14)
                                        - (float)1.5)
                        * (float)v14));
    if ( (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v14 * (float)((float)v11 * (float)0.5)) * (float)v14) - (float)1.5) * (float)v14)
                                                                                               * (float)((float)v11 * (float)0.5))
                                                                                       * (float)((float)-(float)((float)((float)((float)v14 * (float)((float)v11 * (float)0.5)) * (float)v14) - (float)1.5)
                                                                                               * (float)v14))
                                                                               - (float)1.5)
                                                               * (float)((float)-(float)((float)((float)((float)v14 * (float)((float)v11 * (float)0.5))
                                                                                               * (float)v14)
                                                                                       - (float)1.5)
                                                                       * (float)v14))
                                                       * (float)((float)v11 * (float)0.5))
                                               * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v14 * (float)((float)v11 * (float)0.5)) * (float)v14) - (float)1.5)
                                                                                               * (float)v14)
                                                                                       * (float)((float)v11 * (float)0.5))
                                                                               * (float)((float)-(float)((float)((float)((float)v14 * (float)((float)v11 * (float)0.5)) * (float)v14) - (float)1.5)
                                                                                       * (float)v14))
                                                                       - (float)1.5)
                                                       * (float)((float)-(float)((float)((float)((float)v14
                                                                                               * (float)((float)v11 * (float)0.5))
                                                                                       * (float)v14)
                                                                               - (float)1.5)
                                                               * (float)v14)))
                                       - (float)1.5)
                       * (float)v15)
               * (float)v11) > 2000.0 )
    {
      idVec3::NormalizeFast(this: &this->currentState.linearVelocity);
      v16 = (float)(p_linearVelocity->y * (float)2000.0);
      v17 = (float)(p_linearVelocity->z * (float)2000.0);
      p_linearVelocity->x = p_linearVelocity->x * (float)2000.0;
      p_linearVelocity->y = v16;
      p_linearVelocity->z = v17;
    }
    ((void (__fastcall *)(idPhysicsCallbacks *, int, const idVec3 *))this->callbacks->ActivatePhysics)(
      a1: this->callbacks,
      a2: this->physicsId,
      a3: point);
  }
}


// ========================================================================
// ?PutToRest@idPhysics_Robot@@UAAXXZ
// EA  : 0x82CADF88
// RVA : 0x00CADF88
// PDB : w:\tech5\tungsten\game\entities\robot.cpp
// ========================================================================

void __fastcall idPhysics_Robot::PutToRest(idPhysics_Robot *this)
{
  this->currentState.linearVelocity.z = 0.0;
  this->currentState.linearVelocity.y = 0.0;
  this->currentState.linearVelocity.x = 0.0;
  this->currentState.angularVelocity.z = 0.0;
  this->currentState.angularVelocity.y = 0.0;
  this->currentState.angularVelocity.x = 0.0;
}


// ========================================================================
// ?SaveState@idPhysics_Robot@@UAAXXZ
// EA  : 0x82CADFB0
// RVA : 0x00CADFB0
// PDB : w:\tech5\tungsten\game\entities\robot.cpp
// ========================================================================

void __fastcall idPhysics_Robot::SaveState(idPhysics_Robot *this)
{
  this->savedState = this->currentState;
  this->savedState.worldOrigin = this->clipModel->origin;
}


// ========================================================================
// ?GetContents@idPhysics_Robot@@UBAHH@Z
// EA  : 0x82CAE028
// RVA : 0x00CAE028
// PDB : w:\tech5\tungsten\game\entities\robot.cpp
// ========================================================================

int __fastcall idPhysics_Robot::GetContents(idPhysics_Robot *this, int id)
{
  return this->clipModel->contents;
}


// ========================================================================
// ?GetBounds@idPhysics_Robot@@UBAABVidBounds@@H@Z
// EA  : 0x82CAE038
// RVA : 0x00CAE038
// PDB : w:\tech5\tungsten\game\entities\robot.cpp
// ========================================================================

const idBounds *__fastcall idPhysics_Robot::GetBounds(idPhysics_Robot *this, int id)
{
  return &this->clipModel->bounds;
}


// ========================================================================
// ?GetAbsBounds@idPhysics_Robot@@UBAABVidBounds@@H@Z
// EA  : 0x82CAE048
// RVA : 0x00CAE048
// PDB : w:\tech5\tungsten\game\entities\robot.cpp
// ========================================================================

const idBounds *__fastcall idPhysics_Robot::GetAbsBounds(idPhysics_Robot *this, int id)
{
  return &this->clipModel->absBounds;
}


// ========================================================================
// ?GetOrigin@idPhysics_Robot@@UBAABVidVec3@@H@Z
// EA  : 0x82CAE058
// RVA : 0x00CAE058
// PDB : w:\tech5\tungsten\game\entities\robot.cpp
// ========================================================================

const idVec3 *__fastcall idPhysics_Robot::GetOrigin(idPhysics_Robot *this, int id)
{
  return &this->clipModel->origin;
}


// ========================================================================
// ?GetAxis@idPhysics_Robot@@UBAABVidMat3@@H@Z
// EA  : 0x82CAE068
// RVA : 0x00CAE068
// PDB : w:\tech5\tungsten\game\entities\robot.cpp
// ========================================================================

const idMat3 *__fastcall idPhysics_Robot::GetAxis(idPhysics_Robot *this, int id)
{
  return &this->clipModel->axis;
}


// ========================================================================
// ?ClipTranslation@idPhysics_Robot@@UBAXAAUtrace_t@@ABVidVec3@@PBVidClipModel@@@Z
// EA  : 0x82CAE078
// RVA : 0x00CAE078
// PDB : w:\tech5\tungsten\game\entities\robot.cpp
// ========================================================================

void __fastcall idPhysics_Robot::ClipTranslation(
        idPhysics_Robot *this,
        trace_t *results,
        const idVec3 *translation,
        idClipModel *model)
{
  double z; // fp0
  idClipModel *clipModel; // r7
  int clipMask; // r9
  idClip *clip; // r3
  double v8; // fp8
  double v9; // fp7
  double x; // fp13
  double y; // fp12
  idClipModel *v13; // r8
  int v14; // r10
  idClip *v15; // r4
  double v16; // fp9
  double v17; // fp6
  const idVec3 *v18; // [sp+8h] [-A8h]
  const idMat3 *v19; // [sp+Ch] [-A4h]
  const char *v20; // [sp+10h] [-A0h]
  int v21; // [sp+14h] [-9Ch]
  int v22; // [sp+18h] [-98h]
  int v23; // [sp+1Ch] [-94h]
  int v24; // [sp+20h] [-90h]
  int v25; // [sp+24h] [-8Ch]
  int v26; // [sp+28h] [-88h]
  int v27; // [sp+2Ch] [-84h]
  int v28; // [sp+30h] [-80h]
  int v29; // [sp+34h] [-7Ch]
  int v30; // [sp+38h] [-78h]
  int v31; // [sp+3Ch] [-74h]
  int v32; // [sp+40h] [-70h]
  int v33; // [sp+44h] [-6Ch]
  int v34; // [sp+48h] [-68h]
  int v35; // [sp+4Ch] [-64h]
  int v36; // [sp+50h] [-60h]
  int entityNumber; // [sp+54h] [-5Ch]
  int v38; // [sp+58h] [-58h]
  int v39; // [sp+60h] [-50h]
  char v40; // [sp+70h] [-40h] BYREF
  idVec3 v41; // [sp+78h] [-38h] BYREF
  idVec3 v42; // [sp+88h] [-28h] BYREF

  z = translation->z;
  if ( model != nullptr )
  {
    clipModel = this->clipModel;
    clipMask = this->clipMask;
    clip = this->clip;
    v8 = (float)(clipModel->origin.z + translation->z);
    v9 = (float)(clipModel->origin.y + translation->y);
    v41.x = translation->x + clipModel->origin.x;
    v41.z = v8;
    v41.y = v9;
    idClip::TranslationModel(
      this: clip,
      result: results,
      start: &clipModel->origin,
      end: &v41,
      trm: clipModel,
      trmAxis: &clipModel->axis,
      clipMask,
      model,
      modelOrigin: v18,
      modelAxis: v19,
      a11: (int)v20,
      a12: v21,
      a13: v22,
      a14: v23,
      a15: v24,
      a16: v25,
      a17: v26,
      a18: v27,
      a19: v28,
      a20: v29,
      a21: v30,
      a22: v31,
      a23: v32,
      a24: v33,
      a25: v34,
      a26: v35,
      a27: v36,
      a28: &model->origin.x,
      a29: v38,
      a30: (float *)&model->axis);
  }
  else
  {
    x = translation->x;
    y = translation->y;
    v13 = this->clipModel;
    v14 = this->clipMask;
    entityNumber = this->entityNumber;
    v15 = this->clip;
    v16 = (float)(v13->origin.z + (float)z);
    v17 = (float)(v13->origin.y + (float)y);
    v42.x = v13->origin.x + (float)x;
    v42.z = v16;
    v42.y = v17;
    idClip::Translation(
      this: (idClip *)&v40,
      result: v15,
      a3: results,
      start: &v13->origin,
      end: &v42,
      clipModel: v13,
      startAxis: &v13->axis,
      clipMask: v14,
      passEntityNumber: (int)v18,
      moveClipModel: (bool)v19,
      userName: v20,
      a12: v21,
      a13: v22,
      a14: v23,
      a15: v24,
      a16: v25,
      a17: v26,
      a18: v27,
      a19: v28,
      a20: v29,
      a21: v30,
      a22: v31,
      a23: v32,
      a24: v33,
      a25: v34,
      a26: v35,
      a27: v36,
      a28: entityNumber,
      a29: v38,
      a30: false,
      a31: v39,
      a32: 0);
  }
}


// ========================================================================
// ?ClipRotation@idPhysics_Robot@@UBAXAAUtrace_t@@ABVidRotation@@PBVidClipModel@@@Z
// EA  : 0x82CAE180
// RVA : 0x00CAE180
// PDB : w:\tech5\tungsten\game\entities\robot.cpp
// ========================================================================

void __fastcall idPhysics_Robot::ClipRotation(
        idPhysics_Robot *this,
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
      start: (const idMat3 *)&this->clipModel->origin,
      rotation,
      trm: this->clipModel,
      trmAxis: &this->clipModel->axis,
      clipMask: (const idVec3 *)this->clipMask,
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
      start: (const idMat3 *)&this->clipModel->origin,
      rotation,
      clipModel: this->clipModel,
      startAxis: &this->clipModel->axis,
      clipMask: this->clipMask,
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
// ?DisableClip@idPhysics_Robot@@UAAXXZ
// EA  : 0x82CAE228
// RVA : 0x00CAE228
// PDB : w:\tech5\tungsten\game\entities\robot.cpp
// ========================================================================

void __fastcall idPhysics_Robot::DisableClip(idPhysics_Robot *this)
{
  this->clipModel->enabled = false;
}


// ========================================================================
// ?EnableClip@idPhysics_Robot@@UAAXXZ
// EA  : 0x82CAE238
// RVA : 0x00CAE238
// PDB : w:\tech5\tungsten\game\entities\robot.cpp
// ========================================================================

void __fastcall idPhysics_Robot::EnableClip(idPhysics_Robot *this)
{
  this->clipModel->enabled = true;
}


// ========================================================================
// ?LinkClip@idPhysics_Robot@@UAAXXZ
// EA  : 0x82CAE248
// RVA : 0x00CAE248
// PDB : w:\tech5\tungsten\game\entities\robot.cpp
// ========================================================================

void __fastcall idPhysics_Robot::LinkClip(idPhysics_Robot *this)
{
  idClipModel *clipModel; // r10

  clipModel = this->clipModel;
  if ( clipModel != nullptr )
    idClipModel::Link(
      this: this->clipModel,
      newEntityNumber: this->entityNumber,
      newPhysicsId: this->physicsId,
      newBodyId: 0,
      newOrigin: &clipModel->origin,
      newAxis: &this->clipAxis);
}


// ========================================================================
// ?EvaluateContacts@idPhysics_Robot@@UAA_NXZ
// EA  : 0x82CAE278
// RVA : 0x00CAE278
// PDB : w:\tech5\tungsten\game\entities\robot.cpp
// ========================================================================

BOOL __fastcall idPhysics_Robot::EvaluateContacts(idPhysics_Robot *this)
{
  this->ClearContacts(this);
  idPhysics_DynamicBase::AddGroundContacts(
    this,
    clipModel: (const idMat3 *)this->clipModel,
    clipMask: (const idBounds *)this->clipMask);
  idPhysics_DynamicBase::AddContactPhysicsForContacts(this);
  return this->contacts.num != 0;
}


// ========================================================================
// ?SetLinearVelocity@idPhysics_Robot@@UAAXABVidVec3@@H@Z
// EA  : 0x82CAE2D8
// RVA : 0x00CAE2D8
// PDB : w:\tech5\tungsten\game\entities\robot.cpp
// ========================================================================

void __fastcall idPhysics_Robot::SetLinearVelocity(idPhysics_Robot *this, const idVec3 *linearVelocity, int id)
{
  this->currentState.linearVelocity = *linearVelocity;
  ((void (__fastcall *)(idPhysicsCallbacks *, int, int))this->callbacks->ActivatePhysics)(
    a1: this->callbacks,
    a2: this->physicsId,
    a3: id);
}


// ========================================================================
// ?SetAngularVelocity@idPhysics_Robot@@UAAXABVidVec3@@H@Z
// EA  : 0x82CAE308
// RVA : 0x00CAE308
// PDB : w:\tech5\tungsten\game\entities\robot.cpp
// ========================================================================

void __fastcall idPhysics_Robot::SetAngularVelocity(idPhysics_Robot *this, const idVec3 *angularVelocity, int id)
{
  this->currentState.angularVelocity = *angularVelocity;
  ((void (__fastcall *)(idPhysicsCallbacks *, int, int))this->callbacks->ActivatePhysics)(
    a1: this->callbacks,
    a2: this->physicsId,
    a3: id);
}


// ========================================================================
// ?GetUserCommand@idRobot@@ABA_NPBVidEntity@@PAVusercmd_t@@1@Z
// EA  : 0x82CAE430
// RVA : 0x00CAE430
// PDB : w:\tech5\tungsten\game\entities\robot.cpp
// ========================================================================

int __fastcall idRobot::GetUserCommand(idRobot *this, idEntity *entity, usercmd_t *previous, usercmd_t *current)
{
  idPresentable *presentable; // r3
  int v8; // r3
  int v9; // r31

  if ( entity == nullptr )
    return 0;
  presentable = entity->presentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this: entity);
    presentable = entity->presentable;
  }
  v8 = (int)presentable->GetPlayerInterface_2(this: presentable);
  v9 = v8;
  if ( v8 == 0 || (*(_BYTE *)(v8 + 46321) & 0x80) != 0 )
    return 0;
  if ( previous != nullptr )
    memcpy(Dst: previous, Src: (const void *)(v8 + 46252), Size: sizeof(usercmd_t));
  if ( current != nullptr )
    memcpy(Dst: current, Src: (const void *)(v9 + 46312), Size: sizeof(usercmd_t));
  return 1;
}


// ========================================================================
// ?ModifyCrosshairInfo@idRobot@@UBA_NPBVidEntity@@ABVidFocusTrace@@W4usableState_t@@AAVidCrosshairInfo@@@Z
// EA  : 0x82CAE4F0
// RVA : 0x00CAE4F0
// PDB : w:\tech5\tungsten\game\entities\robot.cpp
// ========================================================================

int __fastcall idRobot::ModifyCrosshairInfo(
        idRobot *this,
        const idEntity *activator,
        const idFocusTrace *focusTrace,
        const usableState_t usable,
        idCrosshairInfo *info)
{
  if ( usable == USABLE_NOT_USABLE )
    return 0;
  idStrId::Set(this: &info->text, key: "#str_drive");
  return 1;
}


// ========================================================================
// ?GetInputSettings@idRobot@@UAA?AUinputSettings_t@@PAVidPlayer@@@Z
// EA  : 0x82CAE540
// RVA : 0x00CAE540
// PDB : w:\tech5\tungsten\game\entities\robot.cpp
// ========================================================================

idRobot *__fastcall idRobot::GetInputSettings(idRobot *this, inputSettings_t *result, idPlayer *player)
{
  bool v3; // r7
  double valueFloat; // fp13
  double v5; // fp12
  double v6; // fp11

  v3 = in_invertLook.valueInteger != 0;
  valueFloat = joy_pitchSpeed.valueFloat;
  v5 = joy_yawSpeed.valueFloat;
  v6 = m_sensitivity.valueFloat;
  this->__vftable = nullptr;
  *(float *)&this->listenerList = 1.0;
  this->name.baseBuffer[1] = v3;
  *(float *)&this->listeningToList = 1.0;
  this->name.baseBuffer[0] = 1;
  *(float *)&this->name.len = valueFloat;
  *(float *)&this->name.data = v5;
  *(float *)&this->name.allocedAndFlag = v6;
  return this;
}


// ========================================================================
// ??0idPhysics_Robot@@QAA@XZ
// EA  : 0x82CAE5B0
// RVA : 0x00CAE5B0
// PDB : w:\tech5\tungsten\game\entities\robot.cpp
// ========================================================================

idPhysics_Robot *__fastcall idPhysics_Robot::idPhysics_Robot(idPhysics_Robot *this)
{
  unsigned __int64 v2; // r11

  idPhysics_DynamicBase::idPhysics_DynamicBase(this);
  HIDWORD(v2) = 0x82000000;
  LODWORD(v2) = 0;
  this->__vftable = (idPhysics_Robot_vtbl *)&idPhysics_Robot::`vftable';
  this->stepMoveQuery.index = v2;
  this->type = PHYSICS_ROBOT;
  this->lastCollisionNormal.z = 0.0;
  this->lastCollisionNormal.y = 0.0;
  this->lastCollisionNormal.x = 0.0;
  this->clipModel = nullptr;
  this->clipAxis.mat[1].z = 0.0;
  this->clipAxis.mat[0].z = 0.0;
  this->clipAxis.mat[0].y = 0.0;
  this->clipAxis.mat[2].y = 0.0;
  this->clipAxis.mat[2].x = 0.0;
  this->clipAxis.mat[1].x = 0.0;
  this->clipAxis.mat[2].z = 1.0;
  this->clipAxis.mat[1].y = 1.0;
  this->clipAxis.mat[0].x = 1.0;
  this->currentState.linearVelocity = vec3_origin;
  this->currentState.angularVelocity = vec3_origin;
  this->currentState.worldOrigin = vec3_origin;
  this->currentState.onGround = false;
  this->savedState = this->currentState;
  this->maxStepHeight = 18.0;
  this->timeStep = 0.0;
  this->timeStepMS = 0;
  this->noImpact = false;
  this->minFloorCosine = 0.70710677;
  this->mass = 100.0;
  this->invMass = 0.0099999998;
  return this;
}


// ========================================================================
// ?RestoreState@idPhysics_Robot@@UAAXXZ
// EA  : 0x82CAE728
// RVA : 0x00CAE728
// PDB : w:\tech5\tungsten\game\entities\robot.cpp
// ========================================================================

void __fastcall idPhysics_Robot::RestoreState(idPhysics_Robot *this)
{
  this->currentState = this->savedState;
  this->clipAxis = this->clipModel->axis;
  idClipModel::Link(
    this: this->clipModel,
    newEntityNumber: this->entityNumber,
    newPhysicsId: this->physicsId,
    newBodyId: 0,
    newOrigin: &this->currentState.worldOrigin,
    newAxis: &this->clipAxis);
}


// ========================================================================
// ?SetOrigin@idPhysics_Robot@@UAAXABVidVec3@@H@Z
// EA  : 0x82CAE7E8
// RVA : 0x00CAE7E8
// PDB : w:\tech5\tungsten\game\entities\robot.cpp
// ========================================================================

void __fastcall idPhysics_Robot::SetOrigin(idPhysics_Robot *this, const idVec3 *newOrigin, int id)
{
  unsigned __int64 index; // r11

  index = this->stepMoveQuery.index;
  if ( (unsigned int)index >= *(_DWORD *)(HIDWORD(index) + 377212)
    && (unsigned int)index <= *(_DWORD *)(HIDWORD(index) + 377236) )
  {
    *(_DWORD *)(24 * ((index & 0xFFF) + 11621) + HIDWORD(index)) = 1;
  }
  LODWORD(index) = 0;
  this->stepMoveQuery.index = index;
  this->clipAxis = this->clipModel->axis;
  idClipModel::Link(
    this: this->clipModel,
    newEntityNumber: this->entityNumber,
    newPhysicsId: this->physicsId,
    newBodyId: 0,
    newOrigin,
    newAxis: &this->clipAxis);
  this->callbacks->ActivatePhysics(this: this->callbacks, a2: this->physicsId);
}


// ========================================================================
// ?SetAxis@idPhysics_Robot@@UAAXABVidMat3@@H@Z
// EA  : 0x82CAE8E8
// RVA : 0x00CAE8E8
// PDB : w:\tech5\tungsten\game\entities\robot.cpp
// ========================================================================

void __fastcall idPhysics_Robot::SetAxis(idPhysics_Robot *this, const idMat3 *newAxis, int id)
{
  unsigned __int64 index; // r11
  idClipModel *clipModel; // r11

  index = this->stepMoveQuery.index;
  if ( (unsigned int)index >= *(_DWORD *)(HIDWORD(index) + 377212)
    && (unsigned int)index <= *(_DWORD *)(HIDWORD(index) + 377236) )
  {
    *(_DWORD *)(24 * ((index & 0xFFF) + 11621) + HIDWORD(index)) = 1;
  }
  LODWORD(index) = 0;
  this->stepMoveQuery.index = index;
  clipModel = this->clipModel;
  this->clipAxis = *newAxis;
  idClipModel::Link(
    this: this->clipModel,
    newEntityNumber: this->entityNumber,
    newPhysicsId: this->physicsId,
    newBodyId: 0,
    newOrigin: &clipModel->origin,
    newAxis: &this->clipAxis);
  this->callbacks->ActivatePhysics(this: this->callbacks, a2: this->physicsId);
}


// ========================================================================
// ?ClipContents@idPhysics_Robot@@UBAHPBVidClipModel@@H@Z
// EA  : 0x82CAE9E8
// RVA : 0x00CAE9E8
// PDB : w:\tech5\tungsten\game\entities\robot.cpp
// ========================================================================

int __fastcall idPhysics_Robot::ClipContents(idPhysics_Robot *this, idClipModel *model, int clipMask_)
{
  int result; // r3
  int clipMask; // r8
  idClipModel *clipModel; // r10
  const idMat3 *v7; // [sp+8h] [-F8h]
  int v8; // [sp+Ch] [-F4h]
  int v9; // [sp+10h] [-F0h]
  int v10; // [sp+14h] [-ECh]
  int v11; // [sp+18h] [-E8h]
  int v12; // [sp+1Ch] [-E4h]
  int v13; // [sp+20h] [-E0h]
  int v14; // [sp+24h] [-DCh]
  int v15; // [sp+28h] [-D8h]
  int v16; // [sp+2Ch] [-D4h]
  int v17; // [sp+30h] [-D0h]
  int v18; // [sp+34h] [-CCh]
  int v19; // [sp+38h] [-C8h]
  int v20; // [sp+3Ch] [-C4h]
  int v21; // [sp+40h] [-C0h]
  int v22; // [sp+44h] [-BCh]
  int v23; // [sp+48h] [-B8h]
  int v24; // [sp+4Ch] [-B4h]
  int v25; // [sp+50h] [-B0h]
  char v26; // [sp+60h] [-A0h] BYREF
  trace_t v27; // [sp+70h] [-90h] BYREF

  result = 0;
  clipMask = clipMask_;
  if ( clipMask_ == 0 )
    clipMask = this->clipMask;
  clipModel = this->clipModel;
  if ( clipModel != nullptr )
  {
    if ( clipMask != 0 && clipModel->enabled )
    {
      idClip::ContentsModel(
        this: this->clip,
        result: &v27,
        start: &this->clipModel->origin,
        trm: this->clipModel,
        trmAxis: &this->clipModel->axis,
        clipMask,
        model,
        modelOrigin: &model->origin,
        modelAxis: v7,
        a10: v8,
        a11: v9,
        a12: v10,
        a13: v11,
        a14: v12,
        a15: v13,
        a16: v14,
        a17: v15,
        a18: v16,
        a19: v17,
        a20: v18,
        a21: v19,
        a22: v20,
        a23: v21,
        a24: v22,
        a25: v23,
        a26: v24,
        a27: v25,
        a28: (float *)&model->axis);
      return v27.c.contentFlags;
    }
    else
    {
      idClip::Contents(
        this: (idClip *)&v26,
        result: this->clip,
        a3: &v27,
        start: &this->clipModel->origin,
        clipModel: this->clipModel,
        startAxis: &this->clipModel->axis,
        clipMask,
        passEntityNumber: 0x1FFF,
        userName: (const char *)v7,
        a10: v8,
        a11: v9,
        a12: v10,
        a13: v11,
        a14: v12,
        a15: v13,
        a16: v14,
        a17: v15,
        a18: v16,
        a19: v17,
        a20: v18,
        a21: v19,
        a22: v20,
        a23: v21,
        a24: v22,
        a25: v23,
        a26: v24,
        a27: v25,
        a28: 0);
      return v27.c.contentFlags;
    }
  }
  return result;
}


// ========================================================================
// ?ActivateTargetTypes@idRobot@@AAAXW4targetListType_t@@PAVidEntity@@@Z
// EA  : 0x82CAEAA8
// RVA : 0x00CAEAA8
// PDB : w:\tech5\tungsten\game\entities\robot.cpp
// ========================================================================

void __fastcall idRobot::ActivateTargetTypes(idRobot *this, targetListType_t type, idEntity *activator)
{
  idList<idEntityPtr<idEntity>,5> *p_exitTargets; // r30
  int v5; // r28
  int v6; // r31
  int value; // r9
  idEntity *v8; // r3
  idEntity *v9; // r3

  if ( type != TARGETTYPE_ENTER )
  {
    if ( type == TARGETTYPE_EXIT )
    {
      p_exitTargets = &this->exitTargets;
    }
    else
    {
      if ( type != TARGETTYPE_SECONDARYFIRE )
        return;
      p_exitTargets = &this->secondaryFireTargets;
    }
  }
  else
  {
    p_exitTargets = &this->enterTargets;
  }
  if ( p_exitTargets != nullptr )
  {
    v5 = 0;
    if ( p_exitTargets->num > 0 )
    {
      v6 = 0;
      do
      {
        value = p_exitTargets->list[v6].spawnId.value;
        if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
        {
          v8 = gameLocal->entities.ptr[value & 0x1FFF];
          if ( v8 != nullptr )
          {
            v9 = idEntity::CastTo(c: v8);
            if ( v9 != nullptr )
              idEntity::Activate(this: v9, activator);
          }
        }
        ++v5;
        ++v6;
      }
      while ( v5 < p_exitTargets->num );
    }
  }
}


// ========================================================================
// ?GetCockpitSeatOriginAxis@idRobot@@QBAXHAAVidVec3@@AAVidMat3@@@Z
// EA  : 0x82CAEB70
// RVA : 0x00CAEB70
// PDB : w:\tech5\tungsten\game\entities\robot.cpp
// ========================================================================

void __fastcall idRobot::GetCockpitSeatOriginAxis(idRobot *this, int seatIndex, idVec3 *origin, idMat3 *axis)
{
  bool v7; // r27
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idTreeAnimator *v9; // r29
  idPropsCollection *decl; // r11
  const tagData_t *Tag; // r4
  idMat3 v12[2]; // [sp+50h] [-60h] BYREF

  v7 = false;
  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
  v9 = TreeAnimatorFromPresentable;
  if ( TreeAnimatorFromPresentable != nullptr )
  {
    decl = (idPropsCollection *)TreeAnimatorFromPresentable->decl;
    if ( decl != nullptr && decl != (idPropsCollection *)-352 )
    {
      Tag = idPropsCollection::GetTag(this: decl + 22, propName: "_info", tagName: "cockpit_pilot");
      if ( Tag->parentJoint.value != 0xFFFF )
        v7 = (unsigned __int8)idTreeAnimator::GetWorldSpaceTagTransform(this: v9, tagData: Tag, origin, axis) != 0;
    }
  }
  if ( !v7 )
  {
    origin->x = this->lowerOrigin.x;
    origin->y = this->lowerOrigin.y;
    origin->z = this->lowerOrigin.z;
    *axis = *idMat3::operator*(this: v12, result: &this->upperAxis, a: &this->lowerAxis);
  }
}


// ========================================================================
// ?IsInCockpit@idRobot@@QBA_NPBVidEntity@@@Z
// EA  : 0x82CAEC80
// RVA : 0x00CAEC80
// PDB : w:\tech5\tungsten\game\entities\robot.cpp
// ========================================================================

BOOL __fastcall idRobot::IsInCockpit(idRobot *this, const idEntity *entity)
{
  int num; // r7
  int v3; // r10
  int i; // r11

  num = this->cockpitSeatState.num;
  v3 = 0;
  if ( num <= 0 )
    return false;
  for ( i = 0; (this->cockpitSeatState.list[i].occupant.spawnId.value & 0x1FFF) != entity->entityNumber; ++i )
  {
    if ( ++v3 >= num )
      return false;
  }
  return v3 >= 0;
}


// ========================================================================
// ?HasSeatTypeOccupant@idRobot@@QBA_NW4cockpitSeatType_t@@@Z
// EA  : 0x82CAECD8
// RVA : 0x00CAECD8
// PDB : w:\tech5\tungsten\game\entities\robot.cpp
// ========================================================================

int __fastcall idRobot::HasSeatTypeOccupant(idRobot *this, cockpitSeatType_t type)
{
  int v4; // r29
  int v5; // r31
  idGameLocal *v6; // r10
  int value; // r9
  idEntity *v8; // r3

  v4 = 0;
  if ( this->cockpitSeatInfo.num <= 0 )
    return 0;
  v5 = 0;
  v6 = gameLocal;
  while ( 1 )
  {
    if ( this->cockpitSeatInfo.list[v5].type == type )
    {
      value = this->cockpitSeatState.list[v5].occupant.spawnId.value;
      if ( v6->spawnIds.ptr[value & 0x1FFF] != value >> 13 )
        goto LABEL_8;
      v8 = v6->entities.ptr[value & 0x1FFF];
      if ( v8 == nullptr )
        goto LABEL_8;
      if ( idEntity::CastTo(c: v8) != nullptr )
        return 1;
      v6 = gameLocal;
    }
LABEL_8:
    ++v4;
    ++v5;
    if ( v4 >= this->cockpitSeatInfo.num )
      return 0;
  }
}


// ========================================================================
// ?GetDriver@idRobot@@QBAPAVidEntity@@XZ
// EA  : 0x82CAED90
// RVA : 0x00CAED90
// PDB : w:\tech5\tungsten\game\entities\robot.cpp
// ========================================================================

idEntity *__fastcall idRobot::GetDriver(idRobot *this)
{
  int num; // r9
  int v2; // r11
  int i; // r10
  int value; // r9
  idEntity *v6; // r3

  num = this->cockpitSeatInfo.num;
  v2 = 0;
  if ( num <= 0 )
    return nullptr;
  for ( i = 0; this->cockpitSeatInfo.list[i].type != COCKPITSEAT_PILOT; ++i )
  {
    if ( ++v2 >= num )
      return nullptr;
  }
  value = this->cockpitSeatState.list[v2].occupant.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v6 = gameLocal->entities.ptr[this->cockpitSeatState.list[v2].occupant.spawnId.value & 0x1FFF]) != nullptr )
  {
    return idEntity::CastTo(c: v6);
  }
  else
  {
    return nullptr;
  }
}


// ========================================================================
// ?SetExitPosition@idRobot@@AAAXPAVidEntity@@@Z
// EA  : 0x82CAEE40
// RVA : 0x00CAEE40
// PDB : w:\tech5\tungsten\game\entities\robot.cpp
// ========================================================================

void __fastcall idRobot::SetExitPosition(idRobot *this, idPlayer *entity)
{
  char v4; // r23
  int v5; // r24
  idPhysics *Physics; // r30
  idPhysics *v7; // r3
  __int64 v8; // r11
  idPhysics *v9; // r26
  double v10; // fp27
  float *v11; // r3
  double v12; // fp27
  double v13; // fp26
  double v14; // fp25
  float *v15; // r3
  int v16; // r26
  double v17; // fp2
  double v18; // fp1
  float *v19; // r30
  idPhysics *v20; // r21
  idPhysics *v21; // r20
  double v22; // fp27
  float *v23; // r3
  double v24; // fp26
  double v25; // fp25
  double v26; // fp24
  double v27; // fp27
  float *v28; // r3
  double v29; // fp7
  double v30; // fp3
  idPhysics *v31; // r3
  idPlayer *v32; // r30
  idPhysics *v33; // r3
  int v34; // r3
  float v35; // r8
  int v36; // r6
  idPhysics *v37; // r3
  float *v38; // r3
  double v39; // fp0
  double v40; // fp12
  double v41; // fp8
  double v42; // fp7
  double v43; // fp6
  double v44; // fp5
  int v45; // [sp+8h] [-228h]
  bool v46; // [sp+Fh] [-221h]
  const char *v47; // [sp+10h] [-220h]
  int v48; // [sp+14h] [-21Ch]
  int v49; // [sp+18h] [-218h]
  int v50; // [sp+1Ch] [-214h]
  int v51; // [sp+20h] [-210h]
  int v52; // [sp+24h] [-20Ch]
  int v53; // [sp+28h] [-208h]
  int v54; // [sp+2Ch] [-204h]
  int v55; // [sp+30h] [-200h]
  int v56; // [sp+34h] [-1FCh]
  int v57; // [sp+38h] [-1F8h]
  int v58; // [sp+3Ch] [-1F4h]
  int v59; // [sp+40h] [-1F0h]
  int v60; // [sp+44h] [-1ECh]
  int v61; // [sp+48h] [-1E8h]
  int v62; // [sp+4Ch] [-1E4h]
  int v63; // [sp+50h] [-1E0h]
  int entityNumber; // [sp+54h] [-1DCh]
  int v65; // [sp+58h] [-1D8h]
  int v66; // [sp+60h] [-1D0h]
  idMat3 v67; // [sp+70h] [-1C0h] BYREF
  float v68; // [sp+94h] [-19Ch]
  float v69; // [sp+98h] [-198h]
  float v70; // [sp+A0h] [-190h] BYREF
  float v71; // [sp+A4h] [-18Ch]
  int v72; // [sp+A8h] [-188h]
  idMat3 v73; // [sp+B0h] [-180h] BYREF
  float v74[8]; // [sp+E0h] [-150h] BYREF
  trace_t v75; // [sp+100h] [-130h] BYREF

  v74[0] = 0.0;
  v4 = 0;
  v74[1] = 100.0;
  v5 = 0;
  v74[2] = 0.0;
  v74[3] = -100.0;
  v74[4] = 100.0;
  v74[5] = 0.0;
  v74[6] = -100.0;
  v74[7] = 0.0;
  do
  {
    if ( v4 != 0 )
      break;
    Physics = idEntity::GetPhysics(this);
    v7 = idEntity::GetPhysics(this);
    LODWORD(v8) = v5;
    HIDWORD(v8) = Physics->__vftable;
    v9 = v7;
    *(_QWORD *)&v67.mat[0].x = v8;
    v10 = (float)v8;
    v11 = (float *)(*(int (__fastcall **)(idPhysics *, _DWORD))(HIDWORD(v8) + 68))(a1: Physics, a2: 0);
    v13 = (float)((float)(v11[7] * (float)v10) * (float)4.0);
    v14 = (float)((float)(v11[8] * (float)v10) * (float)4.0);
    v12 = (float)((float)(v11[6] * (float)v10) * (float)4.0);
    v15 = (float *)v9->GetOrigin(this: v9, a2: 0);
    v16 = 0;
    v17 = (float)(v15[1] + (float)v13);
    v18 = (float)(v15[2] + (float)v14);
    v67.mat[1].y = (float)v12 + *v15;
    v67.mat[1].z = v17;
    v19 = v74;
    v67.mat[2].x = v18;
    while ( 1 )
    {
      v20 = idEntity::GetPhysics(this);
      v21 = idEntity::GetPhysics(this);
      v22 = v19[1];
      v23 = (float *)v20->GetAxis(this: v20, a2: 0);
      v24 = *v19;
      v25 = (float)(v23[3] * (float)v22);
      v26 = (float)(v23[4] * (float)v22);
      v27 = (float)(v23[5] * (float)v22);
      v28 = (float *)v21->GetAxis(this: v21, a2: 0);
      v29 = (float)(v28[2] * (float)v24);
      v30 = (float)(v28[1] * (float)v24);
      entityNumber = this->entityNumber;
      v67.mat[2].z = (float)((float)(*v28 * (float)v24) + v67.mat[1].y) + (float)v25;
      v68 = (float)((float)v30 + v67.mat[1].z) + (float)v26;
      v69 = (float)((float)((float)v29 + v67.mat[2].x) + (float)v27) + (float)10.0;
      idClip::Translation(
        this: (idClip *)&v70,
        result: &clientGame->clip,
        a3: &v75,
        start: (const idVec3 *)&v67.mat[1].y,
        end: (const idVec3 *)&v67.mat[2].z,
        clipModel: clientGame->clip.clip48x48x96,
        startAxis: &mat3_identity,
        clipMask: 107529,
        passEntityNumber: v45,
        moveClipModel: v46,
        userName: v47,
        a12: v48,
        a13: v49,
        a14: v50,
        a15: v51,
        a16: v52,
        a17: v53,
        a18: v54,
        a19: v55,
        a20: v56,
        a21: v57,
        a22: v58,
        a23: v59,
        a24: v60,
        a25: v61,
        a26: v62,
        a27: v63,
        a28: entityNumber,
        a29: v65,
        a30: false,
        a31: v66,
        a32: 0);
      if ( v75.fraction == 1.0 )
        break;
      ++v16;
      v19 += 2;
      if ( v16 >= 4 )
        goto LABEL_8;
    }
    v4 = 1;
LABEL_8:
    ++v5;
  }
  while ( v5 < 5 );
  v31 = idEntity::GetPhysics(this: entity);
  v31->SetOrigin(this: v31, a2: (const idVec3 *)&v67.mat[2].z, a3: -1);
  v32 = idPlayer::CastTo(c: entity);
  if ( v32 != nullptr )
  {
    v33 = idEntity::GetPhysics(this);
    v34 = (int)v33->GetAxis(this: v33, a2: 0);
    v35 = *(float *)v34;
    v36 = *(_DWORD *)(v34 + 8);
    v71 = *(float *)(v34 + 4);
    v73.mat[0].z = 0.0;
    v70 = v35;
    v73.mat[0].x = v35;
    v72 = v36;
    v73.mat[0].y = v71;
    v37 = idEntity::GetPhysics(this);
    v38 = (float *)v37->GetGravityNormal(this: v37);
    v39 = *v38;
    v40 = (float)(*v38 * v73.mat[0].y);
    v73.mat[2].x = *v38;
    v41 = (float)(v38[1] * v73.mat[0].z);
    v42 = (float)((float)(v38[1] * v73.mat[0].x) - (float)v40);
    v73.mat[2].y = v38[1];
    v43 = (float)(v38[2] * v73.mat[0].x);
    v44 = (float)((float)(v38[2] * v73.mat[0].y) - (float)v41);
    v73.mat[2].z = v38[2];
    v73.mat[1].z = v42;
    v73.mat[1].x = v44;
    v73.mat[1].y = (float)((float)v39 * v73.mat[0].z) - (float)v43;
    idMat3::OrthoNormalizeSelf(this: &v73);
    idMat3::ToAngles(this: &v67, result: (idAngles *)&v73);
    v67.mat[0].x = v67.mat[0].x + (float)10.0;
    idPlayer::SetViewAngles(this: v32, angles: (const idAngles *)&v67, force: true);
    v32->Teleport(this: v32, a2: (const idVec3 *)&v67.mat[2].z, a3: (const idAngles *)&v67);
    usercmdGen->ClearAngles(this: usercmdGen);
  }
}


// ========================================================================
// ?UpdateViewPilot@idRobot@@AAAXHABUcockpitUserCmd_t@@@Z
// EA  : 0x82CAF200
// RVA : 0x00CAF200
// PDB : w:\tech5\tungsten\game\entities\robot.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idRobot::UpdateViewPilot(idRobot *this, int seatIndex, const cockpitUserCmd_t *usercmd)
{
  BOOL havecmds; // r10
  double valueFloat; // fp8
  double v6; // fp7
  int buttons; // r11
  __int64 v8; // r7 OVERLAPPED
  __int64 v9; // r4
  __int64 v10; // r9 OVERLAPPED
  double v11; // fp27
  double v12; // fp29
  double v13; // fp28
  double v14; // fp13
  double v15; // fp0
  double v16; // fp13
  double v17; // fp12
  double v18; // fp0
  idAngles *p_fpsCurrViewAngles; // r31
  __int64 v20; // r7
  double v21; // fp0
  double yaw; // fp29
  double v23; // fp1
  double pitch; // fp31
  double v25; // fp27
  double v26; // fp1
  double roll; // fp29
  double v28; // fp31
  double v29; // fp1
  double v30; // fp1
  double v31; // fp0
  double v32; // fp1
  idAngles v33; // [sp+60h] [-80h] BYREF
  idAngles v34; // [sp+70h] [-70h] BYREF

  if ( this->cockpitSeatInfo.list[seatIndex].view == VIEWTYPE_FIRSTPERSON )
  {
    havecmds = usercmd->havecmds;
    valueFloat = robot_fps_stickAngle_minPitch.valueFloat;
    v6 = robot_fps_stickAngle_maxPitch.valueFloat;
    v34.pitch = robot_fps_stickAngle_minPitch.valueFloat;
    v34.yaw = robot_fps_stickAngle_minYaw.valueFloat;
    v33.pitch = robot_fps_stickAngle_maxPitch.valueFloat;
    v33.yaw = robot_fps_stickAngle_maxYaw.valueFloat;
    v34.roll = 0.0;
    v33.roll = 0.0;
    if ( !havecmds )
      goto LABEL_38;
    buttons = 0;
    if ( (*((_BYTE *)&usercmd->curr + 9) & 0x80) == 0 )
      buttons = usercmd->curr.buttons;
    if ( (buttons & 0x800000) != 0 )
    {
      LODWORD(v8) = usercmd->prev.angles[0];
      HIDWORD(v8) = (unsigned __int16)usercmd->prev.angles[1];
      LODWORD(v10) = usercmd->curr.angles[1];
      HIDWORD(v9) = usercmd->padInput;
      HIDWORD(v10) = usercmd->curr.angles[0];
      LODWORD(v9) = SWORD1(v8);
      v11 = (float)((float)v9 * (float)0.0054931641);
      v12 = (float)((float)v10 * (float)0.0054931641);
      if ( usercmd->padInput )
      {
        v13 = 1.0;
        v14 = __fabs((float)((float)((float)*(__int64 *)((char *)&v10 + 4) * (float)0.0054931641) * (float)0.011117288));
        v15 = (float)((float)((float)__fabs((float)((float)((float)v10 * (float)0.0054931641) * (float)0.011117288))
                            - (float)0.050000001)
                    * (float)1.052632);
        if ( v15 >= 0.0 )
        {
          if ( v15 > 1.0 )
            v15 = 1.0;
        }
        else
        {
          v15 = 0.0;
        }
        v16 = (float)((float)((float)v14 - (float)0.050000001) * (float)1.052632);
        if ( v16 >= 0.0 )
        {
          if ( v16 > 1.0 )
            v16 = 1.0;
        }
        else
        {
          v16 = 0.0;
        }
        if ( usercmd->curr.angles[1] >= 0 )
          v17 = robot_fps_stickAngle_minYaw.valueFloat;
        else
          v17 = robot_fps_stickAngle_maxYaw.valueFloat;
        this->fpsCurrViewAngles.yaw = (float)v17 * (float)v15;
        if ( (unsigned __int16)usercmd->curr.angles[0] < 0x8000u )
          v18 = valueFloat;
        else
          v18 = v6;
        this->fpsCurrViewAngles.roll = 0.0;
        this->fpsCurrViewAngles.pitch = (float)v18 * (float)v16;
        p_fpsCurrViewAngles = &this->fpsCurrViewAngles;
        LODWORD(v20) = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED)
                     - this->fpsLastUpdate;
        if ( (float)v20 < (double)robot_fps_view_lerp.valueFloat )
        {
          v21 = (float)((float)v20 / robot_fps_view_lerp.valueFloat);
          if ( v21 >= 0.0 )
          {
            if ( v21 <= 1.0 )
              v13 = (float)((float)v20 / robot_fps_view_lerp.valueFloat);
          }
          else
          {
            v13 = 0.0;
          }
          yaw = this->fpsLastViewAngles.yaw;
          v23 = idMath::AngleNormalize360(angle: (float)(this->fpsCurrViewAngles.yaw - this->fpsLastViewAngles.yaw));
          if ( v23 > 180.0 )
            v23 = (float)((float)v23 - (float)360.0);
          pitch = this->fpsLastViewAngles.pitch;
          v25 = (float)((float)((float)v23 * (float)v13) + (float)yaw);
          v26 = idMath::AngleNormalize360(angle: (float)(p_fpsCurrViewAngles->pitch - this->fpsLastViewAngles.pitch));
          if ( v26 > 180.0 )
            v26 = (float)((float)v26 - (float)360.0);
          roll = this->fpsLastViewAngles.roll;
          v28 = (float)((float)((float)v26 * (float)v13) + (float)pitch);
          v29 = idMath::AngleNormalize360(angle: (float)(this->fpsCurrViewAngles.roll - this->fpsLastViewAngles.roll));
          if ( v29 > 180.0 )
            v29 = (float)((float)v29 - (float)360.0);
          p_fpsCurrViewAngles->pitch = v28;
          this->fpsCurrViewAngles.yaw = v25;
          this->fpsCurrViewAngles.roll = (float)((float)v29 * (float)v13) + (float)roll;
        }
      }
      else
      {
        this->fpsCurrViewAngles.pitch = this->fpsLastViewAngles.pitch;
        p_fpsCurrViewAngles = &this->fpsCurrViewAngles;
        this->fpsCurrViewAngles.yaw = this->fpsLastViewAngles.yaw;
        this->fpsCurrViewAngles.roll = this->fpsLastViewAngles.roll;
        v30 = idMath::AngleNormalize360(angle: (float)((float)((float)v8 * (float)0.0054931641)
                                                     - (float)((float)*(__int64 *)((char *)&v10 + 4)
                                                             * (float)0.0054931641)));
        v31 = v30;
        if ( v30 > 180.0 )
          v31 = (float)((float)v30 - (float)360.0);
        p_fpsCurrViewAngles->pitch = p_fpsCurrViewAngles->pitch + (float)v31;
        v32 = idMath::AngleNormalize360(angle: (float)((float)v11 - (float)v12));
        if ( v32 > 180.0 )
          v32 = (float)((float)v32 - (float)360.0);
        this->fpsCurrViewAngles.yaw = this->fpsCurrViewAngles.yaw + (float)v32;
        this->fpsCurrViewAngles.roll = 0.0;
        idAngles::Clamp(this: &this->fpsCurrViewAngles, min: &v34, max: &v33);
      }
    }
    else
    {
LABEL_38:
      p_fpsCurrViewAngles = &this->fpsCurrViewAngles;
      this->fpsCurrViewAngles = ang_zero;
    }
    this->fpsLastUpdate = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    this->fpsLastViewAngles.pitch = p_fpsCurrViewAngles->pitch;
    this->fpsLastViewAngles.yaw = p_fpsCurrViewAngles->yaw;
    this->fpsLastViewAngles.roll = p_fpsCurrViewAngles->roll;
  }
}


// ========================================================================
// ?GetViewOriginAxis@idRobot@@ABAXHAAVidVec3@@AAVidMat3@@@Z
// EA  : 0x82CAF5C8
// RVA : 0x00CAF5C8
// PDB : w:\tech5\tungsten\game\entities\robot.cpp
// ========================================================================

void __fastcall idRobot::GetViewOriginAxis(idRobot *this, int seatIndex, idVec3 *origin, idMat3 *axis)
{
  int v6; // ctr
  float *p_y; // r10
  float *v10; // r9
  double v11; // fp8
  double x; // fp12
  double y; // fp13
  double z; // fp0
  double valueFloat; // fp0
  double v16; // fp4
  double v17; // fp3
  double v18; // fp1
  idVec3 v19; // [sp+50h] [-D0h] BYREF
  idVec3 v20; // [sp+60h] [-C0h] BYREF
  idMat3 v21[2]; // [sp+70h] [-B0h] BYREF
  idAngles v22[8]; // [sp+C0h] [-60h] BYREF

  v6 = 9;
  p_y = &mat2_identity.mat[1].y;
  v10 = &v21[0].mat[2].y;
  *(idVec3 *)&v21[0].mat[1].y = vec3_origin;
  v20 = (idVec3)ang_zero;
  v19 = vec3_origin;
  do
  {
    *++v10 = *++p_y;
    --v6;
  }
  while ( v6 != 0 );
  idRobot::GetCockpitSeatOriginAxis(this, seatIndex, origin: &v19, axis: (idMat3 *)&v21[0].mat[2].z);
  idMat3::ToAngles(this: v21, result: (idAngles *)&v21[0].mat[2].z);
  if ( seatIndex < 0 )
  {
    x = v19.x;
    y = v19.y;
    z = v19.z;
    v20.x = v21[0].mat[0].x;
    v20.y = v21[0].mat[0].y;
    v20.z = v21[0].mat[0].z;
  }
  else if ( this->cockpitSeatInfo.list[seatIndex].view != VIEWTYPE_FIRSTPERSON )
  {
    z = v21[0].mat[2].x;
    y = v21[0].mat[1].z;
    x = v21[0].mat[1].y;
  }
  else
  {
    v11 = (float)(this->fpsCurrViewAngles.pitch + v21[0].mat[0].x);
    x = v19.x;
    y = v19.y;
    z = v19.z;
    v20.y = this->fpsCurrViewAngles.yaw + v21[0].mat[0].y;
    v20.x = v11;
    v20.z = v21[0].mat[0].z;
  }
  origin->x = x;
  origin->y = y;
  origin->z = z;
  *axis = *idAngles::ToMat3(this: v22, result: (idMat3 *)&v20);
  valueFloat = robot_camera_height_offset.valueFloat;
  v16 = origin->x;
  v17 = (float)((float)(this->lowerAxis.mat[0].x * robot_camera_local_offset_x.valueFloat)
              + (float)((float)(this->lowerAxis.mat[2].x * robot_camera_local_offset_z.valueFloat)
                      + (float)(this->lowerAxis.mat[1].x * robot_camera_local_offset_y.valueFloat)));
  v18 = (float)(origin->z
              + (float)((float)(this->lowerAxis.mat[0].z * robot_camera_local_offset_x.valueFloat)
                      + (float)((float)(this->lowerAxis.mat[2].z * robot_camera_local_offset_z.valueFloat)
                              + (float)(this->lowerAxis.mat[1].z * robot_camera_local_offset_y.valueFloat))));
  origin->y = origin->y
            + (float)((float)(this->lowerAxis.mat[0].y * robot_camera_local_offset_x.valueFloat)
                    + (float)((float)(this->lowerAxis.mat[2].y * robot_camera_local_offset_z.valueFloat)
                            + (float)(this->lowerAxis.mat[1].y * robot_camera_local_offset_y.valueFloat)));
  origin->x = (float)v16 + (float)v17;
  origin->z = (float)v18 + (float)valueFloat;
}


// ========================================================================
// ?GetCockpitCommand@idRobot@@ABAXHAAUcockpitUserCmd_t@@@Z
// EA  : 0x82CAF820
// RVA : 0x00CAF820
// PDB : w:\tech5\tungsten\game\entities\robot.cpp
// ========================================================================

void __fastcall idRobot::GetCockpitCommand(idRobot *this, int seatIndex, cockpitUserCmd_t *usercmd)
{
  int value; // r9
  idEntity *v6; // r3
  idPlayer *v7; // r30
  idPlayer *v8; // r3
  idPlayer *v9; // r30
  idPresentable *presentable; // r3
  int v11; // r3
  int v12; // r3
  bool v13; // r3
  bool v14; // r11

  value = this->cockpitSeatState.list[seatIndex].occupant.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v6 = gameLocal->entities.ptr[this->cockpitSeatState.list[seatIndex].occupant.spawnId.value & 0x1FFF]) != nullptr )
  {
    v7 = (idPlayer *)idEntity::CastTo(c: v6);
  }
  else
  {
    v7 = nullptr;
  }
  usercmd->havecmds = idRobot::GetUserCommand(this, entity: v7, previous: &usercmd->curr, current: &usercmd->prev);
  v8 = idPlayer::CastTo(c: v7);
  v9 = v8;
  usercmd->haveGamePad = false;
  if ( v8 != nullptr )
  {
    presentable = v8->presentable;
    v11 = presentable != nullptr ? (int)presentable->GetPlayerInterface_2(this: presentable) : 0;
    if ( (*(unsigned __int8 (__fastcall **)(int))(*(_DWORD *)v11 + 300))(a1: v11) != 0 )
    {
      idClientGame::GetProfileFromPlayerIndex(this: clientGame, index: v9->entityNumber);
      usercmd->haveGamePad = *(_BYTE *)(v12 + 2066);
    }
  }
  if ( !usercmd->haveGamePad || (v13 = usercmdGen->GetUseAimAssist(this: usercmdGen), v14 = true, !v13) )
    v14 = false;
  usercmd->padInput = v14;
}


// ========================================================================
// ?GetUsableState@idRobot@@UBA?AW4usableState_t@@PBVidEntity@@ABVidFocusTrace@@@Z
// EA  : 0x82CAF958
// RVA : 0x00CAF958
// PDB : w:\tech5\tungsten\game\entities\robot.cpp
// ========================================================================

int __fastcall idRobot::GetUsableState(idRobot *this, const idEntity *activator, const idFocusTrace *focusTrace)
{
  int v4; // r28
  int i; // r31
  int value; // r9
  idEntity *v7; // r3

  v4 = 0;
  if ( this->cockpitSeatState.num <= 0 )
    return 0;
  for ( i = 0; ; ++i )
  {
    value = this->cockpitSeatState.list[i].occupant.spawnId.value;
    if ( gameLocal->spawnIds.ptr[value & 0x1FFF] != value >> 13 )
      break;
    v7 = gameLocal->entities.ptr[value & 0x1FFF];
    if ( v7 == nullptr || idEntity::CastTo(c: v7) == nullptr )
      break;
    if ( ++v4 >= this->cockpitSeatState.num )
      return 0;
  }
  return 10;
}


// ========================================================================
// ?Draw@idRobot@@UAA_NPAVidPlayer@@@Z
// EA  : 0x82CAF9F8
// RVA : 0x00CAF9F8
// PDB : w:\tech5\tungsten\game\entities\robot.cpp
// ========================================================================

int __fastcall idRobot::Draw(idRobot *this, idPlayer *player)
{
  idPresentable *presentable; // r3
  int v6; // r3
  int v7; // ctr
  idView *v8; // r30
  float *p_y; // r11
  int *v10; // r10
  int num; // r7
  int v12; // r10
  double valueFloat; // fp31
  int v14; // r11
  idPhysics *Physics; // r3
  float *v16; // r3
  double x; // fp12
  double y; // fp11
  double z; // fp10
  double v20; // fp13
  double v21; // fp9
  double v22; // fp8
  double v23; // fp4
  double v24; // fp3
  double v25; // fp2
  double v26; // fp31
  double v27; // fp30
  double v28; // fp29
  double v29; // fp28
  double v30; // fp27
  int GameMsPerFrame; // r3
  int v32; // r3
  int v33; // r3
  int v34; // r3
  idVec3 v35; // [sp+50h] [-110h] BYREF
  int v36; // [sp+5Ch] [-104h] BYREF
  idMat3 v37; // [sp+60h] [-100h] BYREF
  float v38[4]; // [sp+88h] [-D8h] BYREF
  float v39[4]; // [sp+98h] [-C8h] BYREF
  float v40[4]; // [sp+A8h] [-B8h] BYREF
  float v41[4]; // [sp+B8h] [-A8h] BYREF
  float v42[4]; // [sp+C8h] [-98h] BYREF
  float v43[4]; // [sp+D8h] [-88h] BYREF
  float v44[4]; // [sp+E8h] [-78h] BYREF
  float v45[4]; // [sp+F8h] [-68h] BYREF
  idPhysics v46; // [sp+108h] [-58h] BYREF

  if ( player == nullptr )
    return 0;
  presentable = player->presentable;
  if ( presentable == nullptr )
    return 0;
  v6 = (int)presentable->GetPlayerInterface_2(this: presentable);
  if ( v6 == 0 )
    return 0;
  v7 = 9;
  v8 = (idView *)(v6 + 16224);
  p_y = &mat2_identity.mat[1].y;
  v10 = &v36;
  v35 = vec3_origin;
  do
  {
    *++v10 = *(_DWORD *)++p_y;
    --v7;
  }
  while ( v7 != 0 );
  num = this->cockpitSeatState.num;
  v12 = 0;
  valueFloat = robot_baseFOV.valueFloat;
  if ( num <= 0 )
  {
LABEL_11:
    v12 = -1;
  }
  else
  {
    v14 = 0;
    while ( (this->cockpitSeatState.list[v14].occupant.spawnId.value & 0x1FFF) != player->entityNumber )
    {
      ++v12;
      ++v14;
      if ( v12 >= num )
        goto LABEL_11;
    }
  }
  idRobot::GetViewOriginAxis(this, seatIndex: v12, origin: &v35, axis: &v37);
  idView::SetViewPos(this: v8, origin: &v35, axis: &v37);
  Physics = idEntity::GetPhysics(this);
  v16 = (float *)Physics->GetLinearVelocity(this: &v46, result: (idVec3 *)Physics, a3: 0);
  v8->viewVelocity.x = *v16;
  v8->viewVelocity.y = v16[1];
  v8->viewVelocity.z = v16[2];
  idView::CalcFOV(this: v8, base_fov: valueFloat);
  idView::SetViewID(this: v8, id: this->entityNumber + 1);
  idView::Render(this: v8);
  idView::GetViewPos(this: v8, origin: &v35, axis: &v37);
  x = v35.x;
  y = v35.y;
  this->currentViewPos.x = v35.x;
  this->currentViewPos.y = y;
  z = v35.z;
  this->currentViewPos.z = v35.z;
  v20 = v37.mat[0].x;
  this->currentViewAxis.mat[0].x = v37.mat[0].x;
  v21 = v37.mat[0].y;
  v22 = v37.mat[0].z;
  this->currentViewAxis.mat[1].x = v37.mat[1].x;
  this->currentViewAxis.mat[0].y = v21;
  this->currentViewAxis.mat[0].z = v22;
  this->currentViewAxis.mat[1].y = v37.mat[1].y;
  v23 = v37.mat[2].x;
  this->currentViewAxis.mat[1].z = v37.mat[1].z;
  v24 = v37.mat[2].y;
  this->currentViewAxis.mat[2].x = v23;
  v25 = v37.mat[2].z;
  this->currentViewAxis.mat[2].y = v24;
  this->currentViewAxis.mat[2].z = v25;
  if ( robot_use_crosshair.valueInteger != 0 )
  {
    v26 = crossOffset;
    v27 = (float)(crossSize + crossOffset);
    v28 = (float)((float)((float)v20 * (float)8.0) + (float)x);
    v29 = (float)((float)((float)v21 * (float)8.0) + (float)y);
    v30 = (float)((float)((float)v22 * (float)8.0) + (float)z);
    GameMsPerFrame = idGameTimeManager::GetGameMsPerFrame(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    v45[0] = (float)(v37.mat[2].x * (float)v27) + (float)v28;
    v44[0] = (float)(v37.mat[2].x * (float)v26) + (float)v28;
    v45[1] = (float)(v37.mat[2].y * (float)v27) + (float)v29;
    v44[1] = (float)(v37.mat[2].y * (float)v26) + (float)v29;
    v45[2] = (float)(v37.mat[2].z * (float)v27) + (float)v30;
    v44[2] = (float)(v37.mat[2].z * (float)v26) + (float)v30;
    clientGame->renderWorld->DebugLine(
      this: clientGame->renderWorld,
      a2: (const idVec4 *)&idColor::colorGreen,
      a3: (const idVec3 *)v44,
      a4: (const idVec3 *)v45,
      a5: GameMsPerFrame,
      a6: false);
    v32 = idGameTimeManager::GetGameMsPerFrame(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    v43[0] = (float)v28 - (float)(v37.mat[2].x * (float)v27);
    v43[1] = (float)v29 - (float)(v37.mat[2].y * (float)v27);
    v43[2] = (float)v30 - (float)(v37.mat[2].z * (float)v27);
    v41[0] = (float)v28 - (float)(v37.mat[2].x * (float)v26);
    v41[1] = (float)v29 - (float)(v37.mat[2].y * (float)v26);
    v41[2] = (float)v30 - (float)(v37.mat[2].z * (float)v26);
    clientGame->renderWorld->DebugLine(
      this: clientGame->renderWorld,
      a2: (const idVec4 *)&idColor::colorGreen,
      a3: (const idVec3 *)v41,
      a4: (const idVec3 *)v43,
      a5: v32,
      a6: false);
    v33 = idGameTimeManager::GetGameMsPerFrame(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    v38[0] = (float)(v37.mat[1].x * (float)v27) + (float)v28;
    v38[1] = (float)(v37.mat[1].y * (float)v27) + (float)v29;
    v38[2] = (float)(v37.mat[1].z * (float)v27) + (float)v30;
    v39[0] = (float)(v37.mat[1].x * (float)v26) + (float)v28;
    v39[1] = (float)(v37.mat[1].y * (float)v26) + (float)v29;
    v39[2] = (float)(v37.mat[1].z * (float)v26) + (float)v30;
    clientGame->renderWorld->DebugLine(
      this: clientGame->renderWorld,
      a2: (const idVec4 *)&idColor::colorGreen,
      a3: (const idVec3 *)v39,
      a4: (const idVec3 *)v38,
      a5: v33,
      a6: false);
    v34 = idGameTimeManager::GetGameMsPerFrame(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    v42[0] = (float)v28 - (float)(v37.mat[1].x * (float)v26);
    v40[1] = (float)v29 - (float)(v37.mat[1].y * (float)v27);
    v42[1] = (float)v29 - (float)(v37.mat[1].y * (float)v26);
    v42[2] = (float)v30 - (float)(v37.mat[1].z * (float)v26);
    v40[0] = (float)v28 - (float)(v37.mat[1].x * (float)v27);
    v40[2] = (float)v30 - (float)(v37.mat[1].z * (float)v27);
    clientGame->renderWorld->DebugLine(
      this: clientGame->renderWorld,
      a2: (const idVec4 *)&idColor::colorGreen,
      a3: (const idVec3 *)v42,
      a4: (const idVec3 *)v40,
      a5: v34,
      a6: false);
  }
  return 1;
}


// ========================================================================
// ?GetFaction@idRobot@@UBAPBVidFaction@@XZ
// EA  : 0x82CAFEA0
// RVA : 0x00CAFEA0
// PDB : w:\tech5\tungsten\game\entities\robot.cpp
// ========================================================================

idFaction *__fastcall idRobot::GetFaction(idRobot *this)
{
  int v2; // r27
  int i; // r30
  int value; // r9
  idEntity *v5; // r3
  idPlayer *v6; // r3
  idPlayer *v7; // r3
  idPlayer *v8; // r31
  idPresentable *presentable; // r3
  int v10; // r3

  v2 = 0;
  if ( this->cockpitSeatInfo.num <= 0 )
    return nullptr;
  for ( i = 0; ; ++i )
  {
    if ( this->cockpitSeatInfo.list[i].type == COCKPITSEAT_PILOT )
    {
      value = this->cockpitSeatState.list[i].occupant.spawnId.value;
      if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
        && (v5 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
      {
        v6 = (idPlayer *)idEntity::CastTo(c: v5);
      }
      else
      {
        v6 = nullptr;
      }
      v7 = idPlayer::CastTo(c: v6);
      v8 = v7;
      if ( v7 != nullptr )
      {
        presentable = v7->presentable;
        v10 = presentable != nullptr ? (int)presentable->GetPlayerInterface_2(this: presentable) : 0;
        if ( (*(unsigned __int8 (__fastcall **)(int))(*(_DWORD *)v10 + 300))(a1: v10) != 0 )
          break;
      }
    }
    if ( ++v2 >= this->cockpitSeatInfo.num )
      return nullptr;
  }
  return v8->GetFaction(this: v8);
}


// ========================================================================
// ??1idRobot@@UAA@XZ
// EA  : 0x82CAFFB8
// RVA : 0x00CAFFB8
// PDB : w:\tech5\tungsten\game\entities\robot.cpp
// ========================================================================

void __fastcall idRobot::~idRobot(idRobot *this)
{
  idPhysics *Physics; // r29
  int v3; // r5
  idWeapon *primaryWeapon; // r3
  idWeapon *secondaryWeapon; // r3

  this->__vftable = (idRobot_vtbl *)&idRobot::`vftable';
  if ( idEntity::GetPhysics(this) != nullptr && idEntity::GetPhysics(this)->type == PHYSICS_ROBOT )
  {
    Physics = idEntity::GetPhysics(this);
    idEntity::SetPhysics(this, phys: nullptr, a3: v3);
    if ( Physics != nullptr )
      ((void (__fastcall *)(idPhysics *, int))Physics->dtr_idPhysics)(a1: Physics, a2: 1);
  }
  primaryWeapon = this->primaryWeapon;
  if ( primaryWeapon != nullptr )
  {
    ((void (__fastcall *)(idWeapon *, int))primaryWeapon->dtr_idClass)(a1: primaryWeapon, a2: 1);
    this->primaryWeapon = nullptr;
  }
  secondaryWeapon = this->secondaryWeapon;
  if ( secondaryWeapon != nullptr )
  {
    ((void (__fastcall *)(idWeapon *, int))secondaryWeapon->dtr_idClass)(a1: secondaryWeapon, a2: 1);
    this->secondaryWeapon = nullptr;
  }
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->primaryFireTargets);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->secondaryFireTargets);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->exitTargets);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->enterTargets);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->cockpitSeatState);
  idPhysics_AF::~idPhysics_AF(this: &this->physicsObjectAF);
  idPhysics_RigidBody::~idPhysics_RigidBody(this: &this->physicsObjectRB);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->cockpitSeatInfo);
  idStr::FreeData(this: &this->upperBodyModel);
  idStr::FreeData(this: &this->lowerBodyModel);
  idAnimatedEntity::~idAnimatedEntity(this);
}


// ========================================================================
// __unwind$495081
// EA  : 0x82CB00E8
// RVA : 0x00CB00E8
// PDB : w:\tech5\tungsten\game\entities\robot.cpp
// ========================================================================

void _unwind_495081()
{
  int v0; // r12

  idAnimatedEntity::~idAnimatedEntity(this: *(idAnimatedEntity **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$495082
// EA  : 0x82CB0110
// RVA : 0x00CB0110
// PDB : w:\tech5\tungsten\game\entities\robot.cpp
// ========================================================================

void _unwind_495082()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 128 + 148) + 5204));
}


// ========================================================================
// __unwind$495083
// EA  : 0x82CB013C
// RVA : 0x00CB013C
// PDB : w:\tech5\tungsten\game\entities\robot.cpp
// ========================================================================

void _unwind_495083()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 128 + 148) + 5236));
}


// ========================================================================
// __unwind$495084
// EA  : 0x82CB0168
// RVA : 0x00CB0168
// PDB : w:\tech5\tungsten\game\entities\robot.cpp
// ========================================================================

void _unwind_495084()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 5268));
}


// ========================================================================
// __unwind$495085
// EA  : 0x82CB0194
// RVA : 0x00CB0194
// PDB : w:\tech5\tungsten\game\entities\robot.cpp
// ========================================================================

void _unwind_495085()
{
  int v0; // r12

  idPhysics_RigidBody::~idPhysics_RigidBody(this: (idPhysics_RigidBody *)(*(_DWORD *)(v0 - 128 + 148) + 5368));
}


// ========================================================================
// __unwind$495086_0
// EA  : 0x82CB01C0
// RVA : 0x00CB01C0
// PDB : w:\tech5\tungsten\game\entities\robot.cpp
// ========================================================================

void _unwind_495086_0()
{
  int v0; // r12

  idPhysics_AF::~idPhysics_AF(this: (idPhysics_AF *)(*(_DWORD *)(v0 - 128 + 148) + 5992));
}


// ========================================================================
// __unwind$495087_0
// EA  : 0x82CB01EC
// RVA : 0x00CB01EC
// PDB : w:\tech5\tungsten\game\entities\robot.cpp
// ========================================================================

void _unwind_495087_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 6904));
}


// ========================================================================
// __unwind$495088_0
// EA  : 0x82CB0218
// RVA : 0x00CB0218
// PDB : w:\tech5\tungsten\game\entities\robot.cpp
// ========================================================================

void _unwind_495088_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 7092));
}


// ========================================================================
// __unwind$495089
// EA  : 0x82CB0244
// RVA : 0x00CB0244
// PDB : w:\tech5\tungsten\game\entities\robot.cpp
// ========================================================================

void _unwind_495089()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 7108));
}


// ========================================================================
// __unwind$495090
// EA  : 0x82CB0270
// RVA : 0x00CB0270
// PDB : w:\tech5\tungsten\game\entities\robot.cpp
// ========================================================================

void _unwind_495090()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 7124));
}


// ========================================================================
// __unwind$495091
// EA  : 0x82CB029C
// RVA : 0x00CB029C
// PDB : w:\tech5\tungsten\game\entities\robot.cpp
// ========================================================================

void _unwind_495091()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 7140));
}


// ========================================================================
// ?EnterCockpit@idRobot@@QAAXPAVidEntity@@@Z
// EA  : 0x82CB02C8
// RVA : 0x00CB02C8
// PDB : w:\tech5\tungsten\game\entities\robot.cpp
// ========================================================================

void __fastcall idRobot::EnterCockpit(idRobot *this, idActor *entity)
{
  idPlayer *v4; // r26
  idPlayer *v5; // r3
  idPlayer *v6; // r31
  idPresentable *presentable; // r3
  int v8; // r3
  idPresentable *v9; // r3
  int v10; // r3
  idPresentable *v11; // r3
  int v12; // r3
  idPresentable *v13; // r3
  int v14; // r3
  idPresentable *v15; // r3
  int v16; // r3
  idPresentable *v17; // r3
  int v18; // r3
  idPhysics *Physics; // r3
  const idVec3 *v20; // r3
  float y; // r5
  float z; // r4
  idPhysics *v23; // r3
  cockpitSeatState_t *list; // r9
  _DWORD v25[4]; // [sp+50h] [-60h] BYREF
  idVec4 v26; // [sp+60h] [-50h] BYREF

  idRobot::ActivateTargetTypes(this, type: TARGETTYPE_ENTER, activator: entity);
  v4 = (idPlayer *)idActor::CastTo(c: entity);
  v5 = idPlayer::CastTo(c: v4);
  v6 = v5;
  if ( v5 != nullptr )
  {
    presentable = v5->presentable;
    if ( presentable != nullptr )
      v8 = (int)presentable->GetPlayerInterface_2(this: presentable);
    else
      v8 = 0;
    *(_BYTE *)(v8 + 45880) = 0;
    v9 = v6->presentable;
    if ( v9 != nullptr )
      v10 = (int)v9->GetPlayerInterface_2(this: v9);
    else
      v10 = 0;
    *(idVec3 *)(v10 + 19044) = vec3_origin;
    *(idAngles *)(v10 + 19056) = ang_zero;
    v11 = v6->presentable;
    if ( v11 != nullptr )
      v12 = (int)v11->GetPlayerInterface_2(this: v11);
    else
      v12 = 0;
    if ( v12 != -37616 )
    {
      v13 = v6->presentable;
      if ( v13 != nullptr )
        v14 = (int)v13->GetPlayerInterface_2(this: v13);
      else
        v14 = 0;
      idHands::Hide(this: (idHands *)(v14 + 37616), hideReason: HAND_HIDE_VEHICLE);
    }
    v15 = v6->presentable;
    if ( v15 != nullptr )
      v16 = (int)v15->GetPlayerInterface_2(this: v15);
    else
      v16 = 0;
    idPhysics_Player::SetMovementType(this: (idPhysics_Player *)(v16 + 36264), type: PM_VEHICLE_NOCLIP);
    v26.x = 0.0;
    v26.z = 0.0;
    v26.w = 1.0;
    v26.y = 0.0;
    v17 = v6->presentable;
    if ( v17 != nullptr )
      v18 = (int)v17->GetPlayerInterface_2(this: v17);
    else
      v18 = 0;
    idView::Flash(this: (idView *)(v18 + 16224), color: &v26, time: 500);
    idPlayer::EnteredVehicle(this: v6, veh: nullptr);
    idPlayer::AddControl(this: v6, entity: this);
  }
  if ( v4 != nullptr )
  {
    v4->Hide_2(this: v4);
    Physics = idEntity::GetPhysics(this);
    v20 = Physics->GetOrigin(this: Physics, a2: 0);
    y = v20->y;
    z = v20->z;
    v25[0] = LODWORD(v20->x);
    *(float *)&v25[1] = y;
    *(float *)&v25[2] = z;
    v23 = idEntity::GetPhysics(this: v4);
    v23->SetOrigin(this: v23, a2: (const idVec3 *)v25, a3: -1);
    idEntity::Bind(this: v4, master: (idWorldspawn *)this, orientated: true);
  }
  list = this->cockpitSeatState.list;
  if ( entity != nullptr )
    list->occupant.spawnId.value = (gameLocal->spawnIds.ptr[entity->entityNumber] << 13) | entity->entityNumber;
  else
    list->occupant.spawnId.value = 0x1FFF;
  this->cockpitSeatState.list->timeStamp = idGameTimeManager::GetGameMs(
                                             this: &clientGame->gameTimeManager,
                                             type: GAMETIME_SCALED);
  this->fpsLastUpdate = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  this->fpsLastViewAngles = ang_zero;
  this->fpsCurrViewAngles = ang_zero;
  idEntity::BecomeActive(this, flags: 1);
}


// ========================================================================
// ?ExitCockpit@idRobot@@QAAXPAVidEntity@@@Z
// EA  : 0x82CB05E0
// RVA : 0x00CB05E0
// PDB : w:\tech5\tungsten\game\entities\robot.cpp
// ========================================================================

void __fastcall idRobot::ExitCockpit(idRobot *this, idPlayer *entity)
{
  idPlayer *v4; // r27
  idPlayer *v5; // r3
  idPlayer *v6; // r29
  idPhysics_Player *PhysicsObj; // r3
  idPresentable *presentable; // r3
  int v9; // r3
  idPresentable *v10; // r3
  int v11; // r3
  idPresentable *v12; // r3
  int v13; // r3
  idPresentable *v14; // r3
  int v15; // r3
  idPresentable *v16; // r31
  idPresentable *v17; // r3
  int v18; // r3
  idWeapon *v19; // r3
  idPresentable *v20; // r3
  int v21; // r3
  idPresentable *v22; // r3
  int v23; // r3
  idPresentable *v24; // r3
  int v25; // r3
  idPresentable *v26; // r3
  int v27; // r3
  idHandsItem *v28; // r3
  int num; // r7
  int v30; // r10
  int v31; // r11

  idRobot::ActivateTargetTypes(this, type: TARGETTYPE_EXIT, activator: entity);
  if ( idRobot::IsInCockpit(this, entity) )
  {
    v4 = (idPlayer *)idActor::CastTo(c: entity);
    v5 = idPlayer::CastTo(c: v4);
    v6 = v5;
    if ( v5 != nullptr )
    {
      PhysicsObj = idPlayer::GetPhysicsObj(this: v5);
      idPhysics_Player::SetMovementType(this: PhysicsObj, type: PM_VEHICLE_NOCLIP);
      presentable = v6->presentable;
      if ( presentable != nullptr )
        v9 = (int)presentable->GetPlayerInterface_2(this: presentable);
      else
        v9 = 0;
      idView::ResetControllerShake(this: (idView *)(v9 + 16224));
      v10 = v6->presentable;
      if ( v10 != nullptr )
        v11 = (int)v10->GetPlayerInterface_2(this: v10);
      else
        v11 = 0;
      *(float *)(v11 + 19128) = 0.0;
      v12 = v6->presentable;
      if ( v12 != nullptr )
        v13 = (int)v12->GetPlayerInterface_2(this: v12);
      else
        v13 = 0;
      if ( v13 != -37616 )
      {
        v14 = v6->presentable;
        v15 = v14 != nullptr ? (int)v14->GetPlayerInterface_2(this: v14) : 0;
        if ( idWeapon::CastTo(c: *(idWeapon **)(v15 + 42064)) != nullptr )
        {
          if ( this->presentable == nullptr )
            idEntity::InitPresentableInternal(this);
          v16 = this->presentable;
          v17 = v6->presentable;
          if ( v17 != nullptr )
            v18 = (int)v17->GetPlayerInterface_2(this: v17);
          else
            v18 = 0;
          v19 = idWeapon::CastTo(c: *(idWeapon **)(v18 + 42064));
          idWeapon::SetZoomed(this: v19, zoomed: false, fxMgr: &v16->fxManager);
        }
      }
      v20 = v6->presentable;
      if ( v20 != nullptr )
        v21 = (int)v20->GetPlayerInterface_2(this: v20);
      else
        v21 = 0;
      if ( v21 != -37616 )
      {
        v22 = v6->presentable;
        if ( v22 != nullptr )
          v23 = (int)v22->GetPlayerInterface_2(this: v22);
        else
          v23 = 0;
        idHands::ClearPendingAction(this: (idHands *)(v23 + 37616));
        v24 = v6->presentable;
        if ( v24 != nullptr )
          v25 = (int)v24->GetPlayerInterface_2(this: v24);
        else
          v25 = 0;
        idHands::Show(this: (idHands *)(v25 + 37616), hideReason: HAND_HIDE_VEHICLE);
        v26 = v6->presentable;
        if ( v26 != nullptr )
          v27 = (int)v26->GetPlayerInterface_2(this: v26);
        else
          v27 = 0;
        v28 = idHands::ItemForSlot(this: (idHands *)(v27 + 37616), slot: EQUIP_RIGHT_HAND);
        idHandsItem::StopVideo(this: v28);
      }
      idPlayer::ExitedVehicle(this: v6);
      idPlayer::RemoveControl(this: v6, entity: this);
    }
    if ( v4 != nullptr )
    {
      idEntity::Unbind(this: v4);
      idRobot::SetExitPosition(this, entity);
      v4->Show(this: v4);
    }
    num = this->cockpitSeatState.num;
    v30 = 0;
    if ( num <= 0 )
    {
LABEL_44:
      v30 = -1;
    }
    else
    {
      v31 = 0;
      while ( (this->cockpitSeatState.list[v31].occupant.spawnId.value & 0x1FFF) != entity->entityNumber )
      {
        ++v30;
        ++v31;
        if ( v30 >= num )
          goto LABEL_44;
      }
    }
    this->cockpitSeatState.list[v30].occupant.spawnId.value = 0x1FFF;
  }
}


// ========================================================================
// ?FireWeapon@idRobot@@AAAXPBVidDeclWeapon@@PAVidWeapon@@ABVidVec3@@@Z
// EA  : 0x82CB08C8
// RVA : 0x00CB08C8
// PDB : w:\tech5\tungsten\game\entities\robot.cpp
// ========================================================================

void __fastcall idRobot::FireWeapon(idRobot *this, const idDeclWeapon *decl, idWeapon *weapon, const idVec3 *muzzlePos)
{
  const idDeclAmmo *validAmmoDecl; // r11
  const idDeclProjectile *projectileDecl; // r28
  double z; // fp0
  float y; // r11
  double v12; // fp13
  float x; // r9
  double v14; // fp12
  __int64 v15; // r6
  double v16; // fp7
  double v17; // fp6
  double v18; // fp1
  idPresentable *presentable; // r11
  const idDeclWeapon *v20; // r11
  double v21; // fp13
  double v22; // fp12
  idMat3 *v23; // r3
  idFinishFireResults *v24; // r11
  int i; // ctr
  const idSoundShader *lastShotSound; // r28
  int v27; // r5
  soundChannel_t v28; // r26
  idEntity *entity; // r30
  int GameMs; // r3
  idProjectile *v31; // r3
  idProjectile *v32; // r26
  int v33; // r3
  int v34; // r8
  float v35; // [sp+50h] [-BE0h] BYREF
  float v36; // [sp+54h] [-BDCh]
  float v37; // [sp+58h] [-BD8h]
  idAIEventManager v38; // [sp+60h] [-BD0h] BYREF
  idProjectileTarget v39; // [sp+B0h] [-B80h] BYREF
  idFireParms v40; // [sp+D0h] [-B60h] BYREF
  idFinishFireResults v41; // [sp+170h] [-AC0h] BYREF
  float v42[32]; // [sp+1C0h] [-A70h] BYREF
  soundShaderParms_t v43; // [sp+240h] [-9F0h] BYREF
  idTestFireResults v44; // [sp+2E0h] [-950h] BYREF

  if ( decl->validAmmoClips.num > 0 )
  {
    validAmmoDecl = decl->validAmmoClips.list->validAmmoDecl;
    if ( validAmmoDecl != nullptr )
    {
      projectileDecl = validAmmoDecl->projectileDecl;
      if ( projectileDecl != nullptr )
      {
        z = this->currentViewPos.z;
        y = this->currentViewAxis.mat[0].y;
        v12 = this->currentViewPos.y;
        x = this->currentViewAxis.mat[0].x;
        v14 = this->currentViewPos.x;
        HIDWORD(v15) = &this->currentViewPos;
        LODWORD(v15) = projectileDecl->maxRange;
        v37 = this->currentViewAxis.mat[0].z;
        v38.eventList.num = v15;
        v38.eventList.list = (idAIEvent **)&this->currentViewPos;
        v37 = (float)z + (float)(v37 * (float)v15);
        v36 = (float)v12 + (float)(y * (float)v15);
        v35 = (float)v14 + (float)(x * (float)v15);
        if ( gameLocal->TracePoint(
               this: gameLocal,
               a2: (trace_t *)v42,
               a3: muzzlePos,
               a4: (const idVec3 *)&v35,
               a5: 8462469,
               a6: this) )
        {
          v35 = v42[1];
          v36 = v42[2];
          v37 = v42[3];
        }
        v16 = (float)(v37 - muzzlePos->z);
        v17 = (float)(v36 - muzzlePos->y);
        *(float *)&v38.eventList.size = v35 - muzzlePos->x;
        *(float *)&v38.eventHash.hash = v16;
        *(float *)&v38.eventList.granularity = v17;
        v18 = idVec3::NormalizeFast(this: (idVec3 *)&v38.eventList.size);
        if ( projectileDecl->hitscan )
        {
          idFireParms::idFireParms(this: &v40);
          presentable = this->presentable;
          v40.addSpread = projectileDecl->spread;
          if ( presentable == nullptr )
          {
            idEntity::InitPresentableInternal(this);
            presentable = this->presentable;
          }
          if ( presentable != nullptr )
            v40.attacker.spawnId = presentable->spawnId;
          else
            v40.attacker.spawnId = 0;
          v20 = (const idDeclWeapon *)weapon->decl;
          v21 = muzzlePos->y;
          v22 = muzzlePos->z;
          v40.start.x = muzzlePos->x;
          v40.start.y = v21;
          v40.start.z = v22;
          v40.wepDef = v20;
          v23 = idVec3::ToMat3(this: (idVec3 *)&v38.eventHash.granularity, result: (idMat3 *)&v38.eventList.size);
          v40.fireAxis.mat[0].x = v23->mat[0].x;
          v38.eventList.list = (idAIEvent **)&v23->mat[2];
          v40.fireAxis.mat[0].y = v23->mat[0].y;
          v40.fireAxis.mat[0].z = v23->mat[0].z;
          v40.fireAxis.mat[1] = v23->mat[1];
          v40.fireAxis.mat[2].x = v23->mat[2].x;
          v40.fireAxis.mat[2].y = v23->mat[2].y;
          v40.fireAxis.mat[2].z = v23->mat[2].z;
          v40.projDef = projectileDecl;
          memset(&v44, 0, sizeof(v44));
          if ( (unsigned __int8)idClientGame::TestFire(this: clientGame, fp: &v40, tfr: &v44) != 0 )
          {
            v24 = &v41;
            v41.numProjectiles = 0;
            for ( i = 16; i != 0; --i )
            {
              v24 = (idFinishFireResults *)((char *)v24 + 4);
              v24->numProjectiles = 0;
            }
            if ( idGameLocal::FinishFire(this: gameLocal, fp: &v40, tfr: &v44, ffr: &v41) )
            {
              lastShotSound = projectileDecl->lastShotSound;
              v38.eventHash.memTag = TAG_BITARRAY;
              v38.eventHash.granularity = 6;
              v38.eventHash.hashMask = 7;
              v38.eventHash.lookupMask = 8;
              v38.receivers.num = 11;
              v38.receivers.list = (idEntityPtr<idEntity> *)10;
              v38.receivers.size = 12;
              *(_DWORD *)&v38.receivers.granularity = 13;
              v27 = 4 * (fireChannel % 9);
              v38.eventPools.list = (idAIEventPool **)14;
              ++fireChannel;
              v28 = *(int *)((char *)&v38.eventHash.granularity + v27);
              soundShaderParms_t::Clear(this: &v43);
              v43.soundShaderFlags = 0;
              idEntity::StartSoundShader(this, channel: v28, shader: lastShotSound, parms: &v43, peerMask: 0xFFu);
              if ( common->IsServer(this: common) )
              {
                entity = idPresentablePtr<idPresentableProjectile>::operator->(this: &v40.attacker)->entity;
                GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
                idAIEventManager::AddEvent(
                  this: &v38,
                  result: &gameLocal->aiEventManager,
                  eventDecl: decl->gunfireEventDecl,
                  curTime: GameMs,
                  originator: entity,
                  instigator: nullptr,
                  origin: &v40.start,
                  delay: 0);
              }
            }
          }
          idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v40.targetList);
        }
        else
        {
          v31 = (idProjectile *)((int (__fastcall *)(idGameLocal *, const idDeclEntityDef *, int, int, int, double))gameLocal->SpawnEntityFromDef)(
                                  a1: gameLocal,
                                  a2: projectileDecl->notHitscanInfo.entityDef,
                                  a3: -1,
                                  a4: -1,
                                  a5: -1,
                                  a6: v18);
          v32 = idProjectile::CastTo(c: v31);
          if ( v32 != nullptr )
          {
            v39.type = TARGET_NONE;
            v39.presentable.spawnId = 0;
            v39.pos = vec3_origin;
            idVec3::ToMat3(this: (idVec3 *)&v38.eventHash.granularity, result: (idMat3 *)&v38.eventList.size);
            v33 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
            idProjectile::Launch(
              this: v32,
              attacker_: this,
              start: muzzlePos,
              fireAxis: (const idMat3 *)&v38.eventHash.granularity,
              target: &v39,
              initialSpeed: projectileDecl->notHitscanInfo.speed,
              startTime: v34,
              launchTimeOverride: v33);
          }
        }
      }
    }
  }
}


// ========================================================================
// __unwind$496031
// EA  : 0x82CB0D5C
// RVA : 0x00CB0D5C
// PDB : w:\tech5\tungsten\game\entities\robot.cpp
// ========================================================================

void _unwind_496031()
{
  int v0; // r12

  idFireParms::~idFireParms(this: (idAI2::idAIVolatile::idAIEventInfo *)(v0 - 3120 + 208));
}


// ========================================================================
// ?Use@idRobot@@UAA_NPAVidEntity@@W4usableState_t@@@Z
// EA  : 0x82CB0D88
// RVA : 0x00CB0D88
// PDB : w:\tech5\tungsten\game\entities\robot.cpp
// ========================================================================

int __fastcall idRobot::Use(idRobot *this, idPlayer *activator, usableState_t usable)
{
  BOOL v6; // r30
  idPlayer *v7; // r4

  v6 = idEntity::Use(this, activator, usable);
  v7 = idPlayer::CastTo(c: activator);
  if ( usable != USABLE_VEHICLE_DRIVE )
    return v6;
  idRobot::EnterCockpit(this, entity: v7);
  return 1;
}


// ========================================================================
// ?Damage@idRobot@@UAAMPAVidEntity@@0PBVidDeclDamage@@MABVidVec3@@PAUtrace_t@@@Z
// EA  : 0x82CB0DE0
// RVA : 0x00CB0DE0
// PDB : w:\tech5\tungsten\game\entities\robot.cpp
// ========================================================================

float __fastcall idRobot::Damage(
        idRobot *this,
        idEntity *inflictor,
        idEntity *attacker,
        const idDeclDamage *damageDef,
        double damageScale,
        const idVec3 *dir,
        trace_t *trace)
{
  double v13; // fp29
  int v16; // r29
  int v17; // r31
  int value; // r9
  idEntity *v19; // r3
  idPlayer *v20; // r4
  double v21; // fp28
  double v22; // fp27
  double v23; // fp26
  idPhysics *Physics; // r3
  float *v25; // r3
  int v26; // r27
  int v27; // r29
  int v28; // r9
  idEntity *v29; // r3
  idEntity *v30; // r3
  idPlayer *v31; // r31
  double v32; // fp1

  v13 = (float)(idDeclDamage::DamageAmount(this: damageDef) * (float)damageScale);
  if ( this->TakesDamage(this) )
  {
    _FP12 = -(float)(this->health - (float)v13);
    __asm { fsel      f11, f12, f31, f13 }
    this->health = _FP11;
    if ( _FP11 <= 0.0 )
    {
      v16 = 0;
      if ( this->cockpitSeatState.num > 0 )
      {
        v17 = 0;
        do
        {
          value = this->cockpitSeatState.list[v17].occupant.spawnId.value;
          if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
          {
            v19 = gameLocal->entities.ptr[value & 0x1FFF];
            if ( v19 != nullptr )
            {
              v20 = (idPlayer *)idEntity::CastTo(c: v19);
              if ( v20 != nullptr )
                idRobot::ExitCockpit(this, entity: v20);
            }
          }
          ++v16;
          ++v17;
        }
        while ( v16 < this->cockpitSeatState.num );
      }
    }
  }
  v21 = -trace->fraction;
  v22 = -trace->endpos.x;
  v23 = -trace->endpos.y;
  Physics = idEntity::GetPhysics(this);
  v25 = (float *)Physics->GetAxis(this: Physics, a2: 0);
  if ( (float)((float)(*v25 * (float)v21) + (float)((float)(v25[2] * (float)v23) + (float)(v25[1] * (float)v22))) < 0.0 )
  {
    v26 = 0;
    if ( this->cockpitSeatState.num > 0 )
    {
      v27 = 0;
      do
      {
        v28 = this->cockpitSeatState.list[v27].occupant.spawnId.value;
        if ( gameLocal->spawnIds.ptr[v28 & 0x1FFF] == v28 >> 13 )
        {
          v29 = gameLocal->entities.ptr[v28 & 0x1FFF];
          if ( v29 != nullptr )
          {
            v30 = idEntity::CastTo(c: v29);
            v31 = (idPlayer *)v30;
            if ( v30 != nullptr )
            {
              if ( v30->TakesDamage(this: v30) )
                ((void (__fastcall *)(idPlayer *, idEntity *, idEntity *, const idDeclDamage *, double))v31->Damage)(
                  a1: v31,
                  a2: inflictor,
                  a3: attacker,
                  a4: damageDef,
                  a5: damageScale);
              if ( (damageDef->damageTypes & 0x100) == 0 )
                idRobot::ExitCockpit(this, entity: v31);
            }
          }
        }
        ++v26;
        ++v27;
      }
      while ( v26 < this->cockpitSeatState.num );
    }
  }
  v32 = v13;
  return *((float *)&v32 + 1);
}


// ========================================================================
// ?PilotControl_Local@idRobot@@AAAXHABUcockpitUserCmd_t@@HH@Z
// EA  : 0x82CB1088
// RVA : 0x00CB1088
// PDB : w:\tech5\tungsten\game\entities\robot.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idRobot::PilotControl_Local(
        idRobot *this,
        int seatIndex,
        const cockpitUserCmd_t *usercmd,
        int startTime,
        int endTime)
{
  int v5; // r24
  int forwardmove; // r11
  bool v10; // r30
  unsigned __int8 v11; // r29
  double v12; // fp31
  __int64 v13; // r10
  unsigned __int8 v14; // r11
  idPhysics *Physics; // r3
  bool v16; // r3
  double maxSpeed; // fp0
  double v18; // fp13
  double v19; // fp12
  double currentSpeed; // fp0
  double v25; // fp0
  __int64 v33; // r11
  double currentTurnSpeed; // fp0
  double maxTurn; // fp0
  double v37; // fp30
  double v38; // fp13
  double v39; // fp31
  idPhysics *v40; // r3
  int v41; // r3
  float v42; // r7
  float v43; // r6
  idPhysics *v44; // r3
  idPhysics *v45; // r3
  double v50; // fp13
  double v51; // fp7
  double v52; // fp5
  double v53; // fp2
  double v54; // fp5
  double v55; // fp2
  double v56; // fp8
  double v57; // fp7
  double v58; // fp2
  double v59; // fp5
  double v60; // fp4
  double v61; // fp1
  idPhysics *v66; // r3
  const idVec3 *v67; // r30
  idPhysics *v68; // r3
  float *p_x; // r28
  idPhysics *v70; // r3
  int v71; // r3
  const idVec3 *v72; // r27
  char v73; // r11
  double v74; // fp11
  double v75; // fp4
  double v76; // fp2
  double v77; // fp11
  double y; // fp0
  double z; // fp13
  double x; // fp12
  idPhysics *v81; // r3
  idPhysics *v82; // r3
  idPhysics *v83; // r3
  int v84; // r2 OVERLAPPED
  cockpitSeatState_t *v85; // r9
  __int64 v86; // r8
  int v87; // r10
  int buttons; // r11
  int v89; // r11
  int v90; // r11
  int v91; // r11
  int value; // r9
  idEntity *v93; // r3
  idPlayer *v94; // r4
  usercmd_t *p_curr; // r28
  int v96; // r11
  int v97; // r9
  idEntity *v98; // r3
  double v99; // fp5
  double v100; // fp1
  double v101; // fp13
  int GameMs; // r3
  const idDeclWeapon *primaryWeaponDecl; // r4
  idWeapon *primaryWeapon; // r5
  int v105; // r11
  int v106; // r9
  idEntity *v107; // r3
  idEntity *v108; // r5
  idPhysics *v109; // r27
  idPhysics *v110; // r26
  float *v111; // r3
  double v112; // fp31
  double v113; // fp30
  double v114; // fp29
  float *v115; // r3
  double v116; // fp5
  double v117; // fp3
  int v118; // r3
  const idDeclWeapon *secondaryWeaponDecl; // r4
  idWeapon *secondaryWeapon; // r5
  int v121; // r11
  __int128 v122; // r11
  idMat3 *p_upperAxis; // r31
  int v124; // r3
  double v125; // fp29
  double v126; // fp30
  double v127; // fp31
  double v128; // fp28
  double v129; // fp11
  double v130; // fp0
  double v131; // fp11
  double v132; // fp13
  double v133; // fp0
  double v134; // fp1
  double v135; // fp1
  double v136; // fp12
  idQuat v137; // [sp+58h] [-128h] BYREF
  idMat3 v138; // [sp+68h] [-118h] BYREF
  float v139; // [sp+8Ch] [-F4h]
  float v140; // [sp+90h] [-F0h]
  idVec3 v141; // [sp+98h] [-E8h] BYREF
  idVec3 v142; // [sp+A8h] [-D8h] BYREF
  idQuat v143; // [sp+C0h] [-C0h] BYREF
  idAngles v144[8]; // [sp+D0h] [-B0h] BYREF

  v5 = seatIndex;
  if ( this->cockpitSeatInfo.list[seatIndex].type == COCKPITSEAT_PILOT )
    idRobot::UpdateViewPilot(this, seatIndex, usercmd);
  forwardmove = usercmd->curr.forwardmove;
  v10 = false;
  v11 = 0;
  v12 = 0.0;
  if ( abs8(usercmd->curr.forwardmove) >= 0x10u )
  {
    LODWORD(v13) = abs32(forwardmove - 16);
    if ( (int)v13 >= 0 )
    {
      if ( (int)v13 > 100 )
        LODWORD(v13) = 100;
    }
    else
    {
      LODWORD(v13) = 0;
    }
    HIDWORD(v13) = -forwardmove;
    v12 = (float)((float)v13 * (float)0.0099999998);
    if ( (-forwardmove & ~forwardmove) < 0 )
    {
      if ( this->currentSpeed < -0.0099999998 )
      {
LABEL_13:
        v14 = 1;
LABEL_15:
        v11 = v14;
        v10 = (_cntlzw(v14) & 0x20) != 0;
        goto LABEL_16;
      }
    }
    else
    {
      v12 = -v12;
      if ( this->currentSpeed > 0.0099999998 )
        goto LABEL_13;
    }
    v14 = 0;
    goto LABEL_15;
  }
LABEL_16:
  Physics = idEntity::GetPhysics(this);
  v16 = Physics->HasGroundContacts(this: Physics);
  if ( v10 && v16 )
  {
    maxSpeed = this->pilotSettings.maxSpeed;
    v18 = (float)((float)(this->pilotSettings.speedAccel * (float)v12) + this->currentSpeed);
    v19 = -(float)(this->pilotSettings.maxSpeed * (float)0.5);
    if ( v18 >= v19 )
    {
      if ( v18 <= maxSpeed )
        maxSpeed = (float)((float)(this->pilotSettings.speedAccel * (float)v12) + this->currentSpeed);
      this->currentSpeed = maxSpeed;
    }
    else
    {
      this->currentSpeed = v19;
    }
  }
  else if ( v11 == 0 || !v16 )
  {
    currentSpeed = this->currentSpeed;
    if ( currentSpeed <= 0.001 )
    {
      if ( currentSpeed >= 0.001 )
      {
        this->currentSpeed = 0.0;
      }
      else
      {
        _FP10 = -(float)(this->pilotSettings.speedDecel + this->currentSpeed);
        __asm { fsel      f9, f10, f12, f25 }
        this->currentSpeed = _FP9;
      }
    }
    else
    {
      _FP10 = -(float)(this->currentSpeed - this->pilotSettings.speedDecel);
      __asm { fsel      f9, f10, f25, f12 }
      this->currentSpeed = _FP9;
    }
  }
  if ( v11 != 0 && v16 )
  {
    v25 = this->currentSpeed;
    _FP8 = (float)(this->pilotSettings.speedDecel - (float)((float)__fabs(v12) * this->pilotSettings.speedAccel));
    __asm { fsel      f13, f8, f10, f9 }
    if ( v25 <= 0.001 )
    {
      if ( v25 >= 0.001 )
      {
        this->currentSpeed = 0.0;
      }
      else
      {
        _FP13 = -(float)(this->currentSpeed + (float)_FP13);
        __asm { fsel      f12, f13, f0, f25 }
        this->currentSpeed = _FP12;
      }
    }
    else
    {
      _FP13 = -(float)(this->currentSpeed - (float)_FP13);
      __asm { fsel      f12, f13, f25, f0 }
      this->currentSpeed = _FP12;
    }
  }
  _FP13 = 0.0;
  LODWORD(v33) = usercmd->curr.rightmove;
  BYTE3(v33) = abs8(usercmd->curr.rightmove) >= 0x10u;
  if ( v16 && (HIDWORD(v33) = BYTE3(v33), BYTE3(v33) != 0) )
  {
    if ( (int)v33 < 16 )
    {
      if ( (int)v33 <= -16 )
      {
        LODWORD(v33) = v33 + 16;
        if ( (int)v33 <= -100 )
          LODWORD(v33) = -100;
        _FP13 = (float)((float)(this->pilotSettings.turnAccel * (float)v33) * (float)-0.0099999998);
      }
    }
    else
    {
      LODWORD(v33) = v33 - 16;
      if ( (int)v33 >= 100 )
        LODWORD(v33) = 100;
      _FP13 = (float)((float)(this->pilotSettings.turnAccel * (float)v33) * (float)-0.0099999998);
    }
  }
  else
  {
    currentTurnSpeed = this->currentTurnSpeed;
    if ( __fabs(currentTurnSpeed) <= 0.001 )
    {
      this->currentTurnSpeed = 0.0;
    }
    else
    {
      _FP11 = (float)((float)__fabs(currentTurnSpeed) - this->pilotSettings.turnDecel);
      __asm { fsel      f13, f11, f12, f13 }
      if ( currentTurnSpeed >= 0.0099999998 )
        _FP13 = -_FP13;
    }
  }
  maxTurn = this->pilotSettings.maxTurn;
  v37 = -maxTurn;
  v38 = (float)(this->currentTurnSpeed + (float)_FP13);
  if ( v38 >= -maxTurn )
  {
    if ( v38 <= maxTurn )
      v37 = v38;
    else
      v37 = this->pilotSettings.maxTurn;
  }
  v39 = this->currentSpeed;
  this->currentTurnSpeed = v37;
  if ( !v16 )
  {
    v39 = 0.0;
    v37 = 0.0;
  }
  v40 = idEntity::GetPhysics(this);
  v41 = (int)v40->GetAxis(this: v40, a2: 0);
  v42 = *(float *)(v41 + 4);
  v43 = *(float *)(v41 + 8);
  v137.x = *(float *)v41;
  v137.y = v42;
  v137.z = v43;
  v44 = idEntity::GetPhysics(this);
  ((void (__fastcall *)(float *))v44->GetAngularVelocity)(a1: &v138.mat[1].y);
  v45 = idEntity::GetPhysics(this);
  v45->GetLinearVelocity(this: (idPhysics *)&v138.mat[2].z, result: (idVec3 *)v45, a3: 0);
  _FP2 = (float)((float)((float)(v138.mat[1].z * v138.mat[1].z) + (float)(v138.mat[1].y * v138.mat[1].y))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  _FP7 = (float)((float)((float)(v138.mat[2].z * v138.mat[2].z) + (float)((float)(v140 * v140) + (float)(v139 * v139)))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f5, f2, f4, f13 }
  __asm { fsel      f2, f7, f3, f13 }
  v50 = __frsqrte(_FP5);
  v51 = __frsqrte(_FP2);
  v52 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v50
                                                                                      * (float)((float)((float)(v138.mat[1].z * v138.mat[1].z) + (float)(v138.mat[1].y * v138.mat[1].y))
                                                                                              * (float)0.5))
                                                                              * (float)v50)
                                                                      - (float)1.5)
                                                      * (float)v50)
                                              * (float)((float)((float)(v138.mat[1].z * v138.mat[1].z)
                                                              + (float)(v138.mat[1].y * v138.mat[1].y))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v50
                                                                              * (float)((float)((float)(v138.mat[1].z * v138.mat[1].z)
                                                                                              + (float)(v138.mat[1].y * v138.mat[1].y))
                                                                                      * (float)0.5))
                                                                      * (float)v50)
                                                              - (float)1.5)
                                              * (float)v50))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v50
                                                      * (float)((float)((float)(v138.mat[1].z * v138.mat[1].z)
                                                                      + (float)(v138.mat[1].y * v138.mat[1].y))
                                                              * (float)0.5))
                                              * (float)v50)
                                      - (float)1.5)
                      * (float)v50));
  v53 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v51
                                                                                      * (float)((float)((float)(v138.mat[2].z * v138.mat[2].z) + (float)((float)(v140 * v140) + (float)(v139 * v139)))
                                                                                              * (float)0.5))
                                                                              * (float)v51)
                                                                      - (float)1.5)
                                                      * (float)v51)
                                              * (float)((float)((float)(v138.mat[2].z * v138.mat[2].z)
                                                              + (float)((float)(v140 * v140) + (float)(v139 * v139)))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v51
                                                                              * (float)((float)((float)(v138.mat[2].z * v138.mat[2].z)
                                                                                              + (float)((float)(v140 * v140) + (float)(v139 * v139)))
                                                                                      * (float)0.5))
                                                                      * (float)v51)
                                                              - (float)1.5)
                                              * (float)v51))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v51
                                                      * (float)((float)((float)(v138.mat[2].z * v138.mat[2].z)
                                                                      + (float)((float)(v140 * v140)
                                                                              + (float)(v139 * v139)))
                                                              * (float)0.5))
                                              * (float)v51)
                                      - (float)1.5)
                      * (float)v51));
  v54 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v50 * (float)((float)((float)(v138.mat[1].z * v138.mat[1].z) + (float)(v138.mat[1].y * v138.mat[1].y)) * (float)0.5)) * (float)v50) - (float)1.5)
                                                                                              * (float)v50)
                                                                                      * (float)((float)((float)(v138.mat[1].z * v138.mat[1].z) + (float)(v138.mat[1].y * v138.mat[1].y))
                                                                                              * (float)0.5))
                                                                              * (float)((float)-(float)((float)((float)((float)v50 * (float)((float)((float)(v138.mat[1].z * v138.mat[1].z) + (float)(v138.mat[1].y * v138.mat[1].y)) * (float)0.5)) * (float)v50) - (float)1.5)
                                                                                      * (float)v50))
                                                                      - (float)1.5)
                                                      * (float)((float)-(float)((float)((float)((float)v50
                                                                                              * (float)((float)((float)(v138.mat[1].z * v138.mat[1].z) + (float)(v138.mat[1].y * v138.mat[1].y)) * (float)0.5))
                                                                                      * (float)v50)
                                                                              - (float)1.5)
                                                              * (float)v50))
                                              * (float)((float)((float)(v138.mat[1].z * v138.mat[1].z)
                                                              + (float)(v138.mat[1].y * v138.mat[1].y))
                                                      * (float)0.5))
                                      * (float)v52)
                              - (float)1.5)
              * (float)v52);
  v55 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v51 * (float)((float)((float)(v138.mat[2].z * v138.mat[2].z) + (float)((float)(v140 * v140) + (float)(v139 * v139))) * (float)0.5)) * (float)v51) - (float)1.5)
                                                                                              * (float)v51)
                                                                                      * (float)((float)((float)(v138.mat[2].z * v138.mat[2].z) + (float)((float)(v140 * v140) + (float)(v139 * v139)))
                                                                                              * (float)0.5))
                                                                              * (float)((float)-(float)((float)((float)((float)v51 * (float)((float)((float)(v138.mat[2].z * v138.mat[2].z) + (float)((float)(v140 * v140) + (float)(v139 * v139))) * (float)0.5)) * (float)v51) - (float)1.5)
                                                                                      * (float)v51))
                                                                      - (float)1.5)
                                                      * (float)((float)-(float)((float)((float)((float)v51
                                                                                              * (float)((float)((float)(v138.mat[2].z * v138.mat[2].z) + (float)((float)(v140 * v140) + (float)(v139 * v139))) * (float)0.5))
                                                                                      * (float)v51)
                                                                              - (float)1.5)
                                                              * (float)v51))
                                              * (float)((float)((float)(v138.mat[2].z * v138.mat[2].z)
                                                              + (float)((float)(v140 * v140) + (float)(v139 * v139)))
                                                      * (float)0.5))
                                      * (float)v53)
                              - (float)1.5)
              * (float)v53);
  v56 = (float)(v138.mat[2].z * (float)v55);
  v57 = (float)((float)v55
              * (float)((float)(v138.mat[2].z * v138.mat[2].z) + (float)((float)(v140 * v140) + (float)(v139 * v139))));
  v60 = (float)((float)((float)(v139 * (float)v55) * vec3_up.y) + (float)((float)(v140 * (float)v55) * vec3_up.z));
  v58 = (float)((float)(v138.mat[1].z * (float)v54)
              * (float)((float)v54
                      * (float)((float)(v138.mat[1].z * v138.mat[1].z) + (float)(v138.mat[1].y * v138.mat[1].y))));
  v61 = (float)((float)((float)(v138.mat[1].y * (float)v54)
                      * (float)((float)v54
                              * (float)((float)(v138.mat[1].z * v138.mat[1].z) + (float)(v138.mat[1].y * v138.mat[1].y))))
              + (float)(vec3_up.x * (float)v37));
  v59 = (float)((float)((float)v54
                      * (float)((float)(v138.mat[1].z * v138.mat[1].z) + (float)(v138.mat[1].y * v138.mat[1].y)))
              * (float)((float)v54 * (float)0.0));
  v138.mat[1].y = v61;
  v138.mat[1].z = (float)v58 + (float)(vec3_up.y * (float)v37);
  v138.mat[2].x = (float)v59 + (float)(vec3_up.z * (float)v37);
  _FP5 = (float)((float)((float)v56 * vec3_up.x) + (float)v60);
  __asm { fsel      f4, f5, f25, f5 }
  _FP1 = (float)((float)((float)_FP4 * (float)v57) - (float)-750.0);
  __asm { fsel      f11, f1, f2, f11 }
  v138.mat[2].z = (float)(vec3_up.x * (float)_FP11) + (float)(v137.x * (float)v39);
  v139 = (float)(vec3_up.y * (float)_FP11) + (float)(v137.y * (float)v39);
  v140 = (float)(vec3_up.z * (float)_FP11) + (float)(v137.z * (float)v39);
  v66 = idEntity::GetPhysics(this);
  v67 = (const idVec3 *)v66->GetAxis(this: v66, a2: 0);
  v68 = idEntity::GetPhysics(this);
  p_x = &v68->GetAxis(this: v68, a2: 0)->mat[1].x;
  v70 = idEntity::GetPhysics(this);
  v71 = (int)v70->GetAxis(this: v70, a2: 0);
  v72 = (const idVec3 *)(v71 + 24);
  v73 = 0;
  if ( *(float *)(v71 + 32) < 0.17364813 || v67->z > 0.98480773 )
    v73 = 1;
  if ( v73 != 0 )
  {
    if ( __fabs(v67->z) >= __fabs((float)(*(float *)(v71 + 32) - (float)1.0)) )
    {
      v75 = (float)(p_x[2]
                  * (float)((float)(p_x[2] * (float)0.0) + (float)((float)(p_x[1] * v67->y) + (float)(*p_x * v67->x))));
      v76 = (float)(v67->y
                  - (float)(p_x[1]
                          * (float)((float)(p_x[2] * (float)0.0)
                                  + (float)((float)(p_x[1] * v67->y) + (float)(*p_x * v67->x)))));
      v137.x = v67->x
             - (float)(*p_x
                     * (float)((float)(p_x[2] * (float)0.0) + (float)((float)(p_x[1] * v67->y) + (float)(*p_x * v67->x))));
      v137.y = v76;
      v137.z = -v75;
      if ( idVec3::NormalizeFast(this: (idVec3 *)&v137) < (double)idMath::FLT_SMALLEST_NON_DENORMAL )
      {
        v77 = -v72->y;
        v137.x = -v72->x;
        v137.y = v77;
        v137.z = 0.0;
        idVec3::NormalizeFast(this: (idVec3 *)&v137);
      }
      idQuat::MakeRotation(this: &v143, from: v67, to: (const idVec3 *)&v137);
    }
    else
    {
      v74 = (float)(v67->x * v67->z);
      v137.z = -(float)((float)(v67->z * v67->z) - (float)1.0);
      v137.x = -v74;
      v137.y = v137.x;
      idVec3::NormalizeFast(this: (idVec3 *)&v137);
      idQuat::MakeRotation(this: &v143, from: v72, to: (const idVec3 *)&v137);
      if ( __fabs(v143.w) < 0.21643957 )
      {
        v143.x = v67->x;
        v143.y = v67->y;
        v143.z = v67->z;
        v143.w = 0.0;
      }
    }
    idQuat::ToAngularVelocity(this: &v137, result: (idVec3 *)&v143);
    y = (float)((float)((float)(v137.x - v138.mat[1].y) * (float)0.1) + v138.mat[1].y);
    v138.mat[1].y = (float)((float)(v137.x - v138.mat[1].y) * (float)0.1) + v138.mat[1].y;
    z = (float)((float)((float)(v137.y - v138.mat[1].z) * (float)0.1) + v138.mat[1].z);
    v138.mat[1].z = (float)((float)(v137.y - v138.mat[1].z) * (float)0.1) + v138.mat[1].z;
    x = (float)((float)((float)(v137.z - v138.mat[2].x) * (float)0.1) + v138.mat[2].x);
    v138.mat[2].x = (float)((float)(v137.z - v138.mat[2].x) * (float)0.1) + v138.mat[2].x;
  }
  else
  {
    x = v138.mat[2].x;
    z = v138.mat[1].z;
    y = v138.mat[1].y;
  }
  if ( (float)((float)(v138.mat[2].z * v138.mat[2].z) + (float)((float)(v140 * v140) + (float)(v139 * v139))) > 0.000099999997
    || (float)((float)((float)x * (float)x) + (float)((float)((float)z * (float)z) + (float)((float)y * (float)y))) > 0.000099999997 )
  {
    idEntity::BecomeActive(this, flags: 2);
    v81 = idEntity::GetPhysics(this);
    v81->Activate(this: v81);
  }
  v82 = idEntity::GetPhysics(this);
  v82->SetLinearVelocity(this: v82, a2: (const idVec3 *)&v138.mat[2].z, a3: 0);
  v83 = idEntity::GetPhysics(this);
  v83->SetAngularVelocity(this: v83, a2: (const idVec3 *)&v138.mat[1].y, a3: 0);
  v85 = &this->cockpitSeatState.list[v5];
  HIDWORD(v86) = v85->timeStamp;
  if ( endTime - HIDWORD(v86) > 250 )
  {
    v87 = *((unsigned __int8 *)&usercmd->curr + 9) >> 7;
    LOBYTE(buttons) = 0;
    if ( v87 == 0 )
      buttons = usercmd->curr.buttons;
    if ( (buttons & 4) != 0 )
    {
      LOBYTE(v89) = 0;
      if ( (*((_BYTE *)&usercmd->prev + 9) & 0x80) == 0 )
        v89 = usercmd->prev.buttons;
      if ( (v89 & 4) == 0 )
        goto LABEL_85;
    }
    LOBYTE(v90) = 0;
    if ( v87 == 0 )
      v90 = usercmd->curr.buttons;
    if ( (v90 & 0x20) != 0 )
    {
      LOBYTE(v91) = 0;
      if ( (*((_BYTE *)&usercmd->prev + 9) & 0x80) == 0 )
        v91 = usercmd->prev.buttons;
      if ( (v91 & 0x20) == 0 )
      {
LABEL_85:
        value = v85->occupant.spawnId.value;
        if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
          && (v93 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
        {
          v94 = (idPlayer *)idEntity::CastTo(c: v93);
        }
        else
        {
          v94 = nullptr;
        }
        idRobot::ExitCockpit(this, entity: v94);
      }
    }
  }
  p_curr = &usercmd->curr;
  LOBYTE(v96) = 0;
  if ( (*((_BYTE *)&usercmd->curr + 9) & 0x80) == 0 )
    v96 = p_curr->buttons;
  if ( (v96 & 1) != 0
    && (this->primaryFireTime == 0
     || this->primaryFireTime < idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED)) )
  {
    v97 = this->cockpitSeatState.list[v5].occupant.spawnId.value;
    if ( gameLocal->spawnIds.ptr[v97 & 0x1FFF] == v97 >> 13 )
    {
      v98 = gameLocal->entities.ptr[v97 & 0x1FFF];
      if ( v98 != nullptr )
        idEntity::CastTo(c: v98);
    }
    v99 = this->currentViewPos.z;
    v100 = (float)((float)(this->currentViewAxis.mat[2].z * this->primaryMuzzleOffset.z)
                 + (float)((float)(this->currentViewAxis.mat[0].z * this->primaryMuzzleOffset.x)
                         + (float)(this->currentViewAxis.mat[1].z * this->primaryMuzzleOffset.y)));
    v101 = (float)(this->currentViewPos.y
                 + (float)((float)(this->currentViewAxis.mat[2].y * this->primaryMuzzleOffset.z)
                         + (float)((float)(this->currentViewAxis.mat[0].y * this->primaryMuzzleOffset.x)
                                 + (float)(this->currentViewAxis.mat[1].y * this->primaryMuzzleOffset.y))));
    v141.x = this->currentViewPos.x
           + (float)((float)(this->primaryMuzzleOffset.x * this->currentViewAxis.mat[0].x)
                   + (float)((float)(this->currentViewAxis.mat[1].x * this->primaryMuzzleOffset.y)
                           + (float)(this->currentViewAxis.mat[2].x * this->primaryMuzzleOffset.z)));
    v141.y = v101;
    v141.z = (float)v99 + (float)v100;
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    primaryWeaponDecl = this->primaryWeaponDecl;
    primaryWeapon = this->primaryWeapon;
    this->primaryFireTime = primaryWeaponDecl->firingIntervals[0] + GameMs;
    idRobot::FireWeapon(this, decl: primaryWeaponDecl, weapon: primaryWeapon, muzzlePos: &v141);
  }
  LOBYTE(v105) = 0;
  if ( (*((_BYTE *)&usercmd->curr + 9) & 0x80) == 0 )
    v105 = p_curr->buttons;
  if ( (v105 & 8) != 0
    && (this->secondaryFireTime == 0
     || this->secondaryFireTime < idGameTimeManager::GetGameMs(
                                    this: &clientGame->gameTimeManager,
                                    type: GAMETIME_SCALED)) )
  {
    v106 = this->cockpitSeatState.list[v5].occupant.spawnId.value;
    if ( gameLocal->spawnIds.ptr[v106 & 0x1FFF] == v106 >> 13
      && (v107 = gameLocal->entities.ptr[v106 & 0x1FFF]) != nullptr )
    {
      v108 = idEntity::CastTo(c: v107);
    }
    else
    {
      v108 = nullptr;
    }
    idRobot::ActivateTargetTypes(this, type: TARGETTYPE_SECONDARYFIRE, activator: v108);
    v109 = idEntity::GetPhysics(this);
    v110 = idEntity::GetPhysics(this);
    v111 = (float *)v109->GetAxis(this: v109, a2: 0);
    v112 = (float)((float)(*v111 * this->secondaryMuzzleOffset.x)
                 + (float)((float)(v111[3] * this->secondaryMuzzleOffset.y)
                         + (float)(v111[6] * this->secondaryMuzzleOffset.z)));
    v113 = (float)((float)(v111[7] * this->secondaryMuzzleOffset.z)
                 + (float)((float)(v111[1] * this->secondaryMuzzleOffset.x)
                         + (float)(v111[4] * this->secondaryMuzzleOffset.y)));
    v114 = (float)((float)(v111[8] * this->secondaryMuzzleOffset.z)
                 + (float)((float)(v111[2] * this->secondaryMuzzleOffset.x)
                         + (float)(v111[5] * this->secondaryMuzzleOffset.y)));
    v115 = (float *)v110->GetOrigin(this: v110, a2: 0);
    v116 = (float)(v115[2] + (float)v114);
    v117 = (float)(v115[1] + (float)v113);
    v142.x = *v115 + (float)v112;
    v142.z = v116;
    v142.y = v117;
    v118 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    secondaryWeaponDecl = this->secondaryWeaponDecl;
    secondaryWeapon = this->secondaryWeapon;
    this->secondaryFireTime = secondaryWeaponDecl->firingIntervals[0] + v118;
    idRobot::FireWeapon(this, decl: secondaryWeaponDecl, weapon: secondaryWeapon, muzzlePos: &v142);
  }
  v121 = 0;
  if ( (*((_BYTE *)&usercmd->curr + 9) & 0x80) == 0 )
    v121 = p_curr->buttons;
  if ( (v121 & 0x800000) == 0 )
  {
    DWORD1(v122) = (unsigned __int16)usercmd->curr.angles[0];
    p_upperAxis = &this->upperAxis;
    v124 = usercmd->prev.angles[1];
    LODWORD(v122) = SWORD3(v122);
    DWORD2(v122) = usercmd->curr.angles[1];
    LODWORD(v86) = usercmd->prev.angles[0];
    *(_QWORD *)&v137.x = v86;
    v125 = (float)((float)*(__int64 *)(&v84 - 1) * (float)0.0054931641);
    v126 = (float)((float)(__int64)v122 * (float)0.0054931641);
    v127 = (float)((float)*(__int64 *)((char *)&v122 + 4) * (float)0.0054931641);
    v128 = (float)((float)v86 * (float)0.0054931641);
    idMat3::ToAngles(this: &v138, result: (idAngles *)p_upperAxis);
    if ( usercmd->padInput )
    {
      v129 = __fabs((float)((float)v126 * (float)0.011117288));
      v130 = (float)((float)((float)__fabs((float)((float)v127 * (float)0.011117288)) - (float)0.050000001)
                   * (float)1.052632);
      if ( v130 >= 0.0 )
      {
        if ( v130 > 1.0 )
          v130 = 1.0;
      }
      else
      {
        v130 = 0.0;
      }
      v131 = (float)((float)((float)v129 - (float)0.050000001) * (float)1.052632);
      if ( v131 >= 0.0 )
      {
        if ( v131 > 1.0 )
          v131 = 1.0;
      }
      else
      {
        v131 = 0.0;
      }
      if ( (unsigned __int16)usercmd->curr.angles[1] >= 0x8000u )
        v130 = -v130;
      if ( (unsigned __int16)usercmd->curr.angles[0] >= 0x8000u )
        v131 = -v131;
      v132 = (float)-(float)((float)((float)v130 * robot_fps_stickLookSpeed_yaw.valueFloat) - v138.mat[0].y);
      v138.mat[0].y = -(float)((float)((float)v130 * robot_fps_stickLookSpeed_yaw.valueFloat) - v138.mat[0].y);
      v133 = (float)-(float)((float)((float)v131 * robot_fps_stickLookSpeed_pitch.valueFloat) - v138.mat[0].x);
    }
    else
    {
      v134 = idMath::AngleNormalize360(angle: (float)((float)v125 - (float)v127));
      if ( v134 > 180.0 )
        v134 = (float)((float)v134 - (float)360.0);
      v138.mat[0].y = v138.mat[0].y + (float)v134;
      v135 = idMath::AngleNormalize360(angle: (float)((float)v128 - (float)v126));
      if ( v135 > 180.0 )
        v135 = (float)((float)v135 - (float)360.0);
      v132 = v138.mat[0].y;
      v133 = (float)(v138.mat[0].x + (float)v135);
    }
    v138.mat[0].x = v133;
    v136 = -65.0;
    if ( v133 < -65.0 || (v136 = 65.0, v133 > 65.0) )
      v138.mat[0].x = v136;
    if ( v132 >= -180.0 )
    {
      if ( v132 > 180.0 )
        v138.mat[0].y = 180.0;
    }
    else
    {
      v138.mat[0].y = -180.0;
    }
    if ( v138.mat[0].z < 0.0 || v138.mat[0].z > 0.0 )
      v138.mat[0].z = 0.0;
    *p_upperAxis = *idAngles::ToMat3(this: v144, result: &v138);
  }
}


// ========================================================================
// ?ResolveCollisions@idPhysics_Robot@@AAAXXZ
// EA  : 0x82CB1FD8
// RVA : 0x00CB1FD8
// PDB : w:\tech5\tungsten\game\entities\robot.cpp
// ========================================================================

void __fastcall idPhysics_Robot::ResolveCollisions(idPhysics_Robot *this)
{
  unsigned __int64 v1; // r22
  idClipQuery *p_stepMoveQuery; // r30
  idVec3 *p_lastCollisionNormal; // r28
  idClip *clip; // r29
  unsigned __int64 index; // r11
  unsigned __int8 *p_flags; // r10
  int v8; // ctr
  float *p_z; // r11
  float y; // r10
  float z; // r9
  double v12; // fp1
  double v13; // fp1
  double v14; // fp10
  double v15; // fp9
  double maxStepHeight; // fp8
  int clipMask; // r10
  idClipModel *clipModel; // r8
  idClip *v19; // r4
  int entityNumber; // r11
  int v21; // r10
  idClip *v22; // r4
  idClipModel *v23; // r8
  double v24; // fp9
  int v25; // r10
  double v26; // fp5
  double v27; // fp4
  idClipModel *v28; // r8
  idClip *v29; // r4
  char *v30; // r10
  float *v31; // r11
  int i; // ctr
  double v33; // fp13
  double v34; // fp12
  double v35; // fp13
  double v36; // fp12
  int v37; // r29
  contactInfo_t *contacts; // r30
  int v39; // r28
  int v40; // r27
  contactInfo_t *v41; // r11
  float v42; // r9
  float x; // r8
  float v44; // r6
  float v45; // r5
  int GameMsPerFrame; // r3
  int v47; // r3
  bool v48; // r30
  int v49; // r8
  double v50; // fp13
  double v51; // fp0
  double v52; // fp12
  contactInfo_t *list; // r6
  int v54; // r10
  double v57; // fp3
  double v58; // fp1
  double v59; // fp5
  double v60; // fp3
  double v61; // fp2
  int v62; // [sp+8h] [-858h]
  int v63; // [sp+8h] [-858h]
  int v64; // [sp+8h] [-858h]
  const char *v65; // [sp+Ch] [-854h]
  bool v66; // [sp+Fh] [-851h]
  bool v67; // [sp+Fh] [-851h]
  const char *v68; // [sp+10h] [-850h]
  const char *v69; // [sp+10h] [-850h]
  const char *v70; // [sp+10h] [-850h]
  int v71; // [sp+14h] [-84Ch]
  int v72; // [sp+14h] [-84Ch]
  int v73; // [sp+14h] [-84Ch]
  int v74; // [sp+18h] [-848h]
  int v75; // [sp+18h] [-848h]
  int v76; // [sp+18h] [-848h]
  int v77; // [sp+1Ch] [-844h]
  int v78; // [sp+1Ch] [-844h]
  int v79; // [sp+1Ch] [-844h]
  int v80; // [sp+20h] [-840h]
  int v81; // [sp+20h] [-840h]
  int v82; // [sp+20h] [-840h]
  int v83; // [sp+24h] [-83Ch]
  int v84; // [sp+24h] [-83Ch]
  int v85; // [sp+24h] [-83Ch]
  int v86; // [sp+28h] [-838h]
  int v87; // [sp+28h] [-838h]
  int v88; // [sp+28h] [-838h]
  int v89; // [sp+2Ch] [-834h]
  int v90; // [sp+2Ch] [-834h]
  int v91; // [sp+2Ch] [-834h]
  int v92; // [sp+30h] [-830h]
  int v93; // [sp+30h] [-830h]
  int v94; // [sp+30h] [-830h]
  int v95; // [sp+34h] [-82Ch]
  int v96; // [sp+34h] [-82Ch]
  int v97; // [sp+34h] [-82Ch]
  int v98; // [sp+38h] [-828h]
  int v99; // [sp+38h] [-828h]
  int v100; // [sp+38h] [-828h]
  int v101; // [sp+3Ch] [-824h]
  int v102; // [sp+3Ch] [-824h]
  int v103; // [sp+3Ch] [-824h]
  int v104; // [sp+40h] [-820h]
  int v105; // [sp+40h] [-820h]
  int v106; // [sp+40h] [-820h]
  int v107; // [sp+44h] [-81Ch]
  int v108; // [sp+44h] [-81Ch]
  int v109; // [sp+44h] [-81Ch]
  int v110; // [sp+48h] [-818h]
  int v111; // [sp+48h] [-818h]
  int v112; // [sp+48h] [-818h]
  int v113; // [sp+4Ch] [-814h]
  int v114; // [sp+4Ch] [-814h]
  int v115; // [sp+4Ch] [-814h]
  int v116; // [sp+50h] [-810h]
  int v117; // [sp+50h] [-810h]
  int v118; // [sp+50h] [-810h]
  int v119; // [sp+54h] [-80Ch]
  int v120; // [sp+54h] [-80Ch]
  int v121; // [sp+58h] [-808h]
  int v122; // [sp+58h] [-808h]
  int v123; // [sp+58h] [-808h]
  int v124; // [sp+60h] [-800h]
  int v125; // [sp+60h] [-800h]
  int v126; // [sp+60h] [-800h]
  idVec3 normal; // [sp+70h] [-7F0h] BYREF
  idVec3 endpos; // [sp+80h] [-7E0h] BYREF
  idMat3 v129; // [sp+90h] [-7D0h] BYREF
  float v130; // [sp+B4h] [-7ACh]
  float v131; // [sp+B8h] [-7A8h]
  idVec3 v132; // [sp+C0h] [-7A0h] BYREF
  float v133[4]; // [sp+D0h] [-790h] BYREF
  idVec3 v134; // [sp+E0h] [-780h] BYREF
  float v135[4]; // [sp+F0h] [-770h] BYREF
  idVec3 v136; // [sp+100h] [-760h] BYREF
  trace_t v137; // [sp+110h] [-750h] BYREF
  trace_t v138; // [sp+190h] [-6D0h] BYREF
  idMat3 v139; // [sp+210h] [-650h] BYREF
  char v140; // [sp+23Ch] [-624h] BYREF
  _BYTE v141[48]; // [sp+240h] [-620h] BYREF
  trace_t v142; // [sp+270h] [-5F0h] BYREF
  trace_t v143; // [sp+2F0h] [-570h] BYREF
  trace_t v144; // [sp+370h] [-4F0h] BYREF
  idRotation v145; // [sp+3F0h] [-470h] BYREF
  contactsResult_t v146; // [sp+440h] [-420h] BYREF

  p_stepMoveQuery = &this->stepMoveQuery;
  p_lastCollisionNormal = &this->lastCollisionNormal;
  this->lastCollisionNormal.x = 0.0;
  this->lastCollisionNormal.z = 0.0;
  this->lastCollisionNormal.y = 0.0;
  clip = this->clip;
  if ( (unsigned __int8)idClip::QueryIsValid(this: clip, clipQuery: &this->stepMoveQuery) != 0 )
  {
    LODWORD(v1) = 0;
    index = p_stepMoveQuery->index;
    p_stepMoveQuery->index = v1;
    idCollisionModelManager::GetContentsResult(
      this: collisionModelManager,
      result: &v143,
      query: &clip->collisionQueries[index & 0xFFF].query,
      peek: false);
    p_flags = &v138.c.flags;
    v8 = 9;
    endpos = v143.endpos;
    p_z = &this->clipModel->origin.z;
    do
    {
      ++p_z;
      p_flags += 4;
      *(float *)p_flags = *p_z;
      --v8;
    }
    while ( v8 != 0 );
    v137 = v143;
    y = this->currentState.angularVelocity.y;
    if ( ((LODWORD(this->currentState.angularVelocity.z) | LODWORD(y) | LODWORD(this->currentState.angularVelocity.x))
        & 0x7FFFFFFF) != 0 )
    {
      z = this->currentState.angularVelocity.z;
      normal.x = this->currentState.angularVelocity.x;
      normal.y = y;
      normal.z = z;
      v12 = idVec3::NormalizeFast(this: &normal);
      v13 = idMath::AngleNormalize360(angle: (float)((float)-(float)((float)v12 * idMath::M_RAD2DEG) * this->timeStep));
      if ( v13 > 180.0 )
        v13 = (float)((float)v13 - (float)360.0);
      if ( v13 == 0.0 )
      {
        normal.x = vec3_up.x;
        normal.y = vec3_up.y;
        normal.z = vec3_up.z;
      }
      idRotation::idRotation(this: &v145, rotationOrigin: &endpos, rotationVec: &normal, rotationAngle: v13);
      v14 = -this->gravityNormal.y;
      v15 = -this->gravityNormal.z;
      maxStepHeight = this->maxStepHeight;
      clipMask = this->clipMask;
      clipModel = this->clipModel;
      v19 = this->clip;
      entityNumber = this->entityNumber;
      v129.mat[0].x = endpos.x + (float)((float)-this->gravityNormal.x * this->maxStepHeight);
      v129.mat[0].y = endpos.y + (float)((float)v14 * (float)maxStepHeight);
      v129.mat[0].z = endpos.z + (float)((float)v15 * (float)maxStepHeight);
      idClip::Translation(
        this: (idClip *)&normal,
        result: v19,
        a3: &v144,
        start: &endpos,
        end: v129.mat,
        clipModel,
        startAxis: &v139,
        clipMask,
        passEntityNumber: v62,
        moveClipModel: (bool)v65,
        userName: v68,
        a12: v71,
        a13: v74,
        a14: v77,
        a15: v80,
        a16: v83,
        a17: v86,
        a18: v89,
        a19: v92,
        a20: v95,
        a21: v98,
        a22: v101,
        a23: v104,
        a24: v107,
        a25: v110,
        a26: v113,
        a27: v116,
        a28: entityNumber,
        a29: v121,
        a30: true,
        a31: v124,
        a32: (int)"w:\\tech5\\tungsten\\game\\entities\\Robot.cpp(331) : ResolveTranslationUp");
      v119 = this->entityNumber;
      v21 = this->clipMask;
      v22 = this->clip;
      v129.mat[0].x = v144.endpos.x;
      v23 = this->clipModel;
      v129.mat[0].y = v144.endpos.y;
      v129.mat[0].z = v144.endpos.z;
      idClip::Rotation(
        this: (idClip *)&normal,
        result: v22,
        a3: &v138,
        start: &v129,
        rotation: &v145,
        clipModel: v23,
        startAxis: &v139,
        clipMask: v21,
        passEntityNumber: v63,
        moveClipModel: v66,
        userName: v69,
        a12: v72,
        a13: v75,
        a14: v78,
        a15: v81,
        a16: v84,
        a17: v87,
        a18: v90,
        a19: v93,
        a20: v96,
        a21: v99,
        a22: v102,
        a23: v105,
        a24: v108,
        a25: v111,
        a26: v114,
        a27: v117,
        a28: v119,
        a29: v122,
        a30: true,
        a31: v125,
        a32: (int)"w:\\tech5\\tungsten\\game\\entities\\Robot.cpp(339) : ResolveRotation");
      v24 = this->maxStepHeight;
      v25 = this->clipMask;
      v26 = this->gravityNormal.y;
      v27 = this->gravityNormal.z;
      v28 = this->clipModel;
      v120 = this->entityNumber;
      v134.x = (float)(this->gravityNormal.x * this->maxStepHeight) + endpos.x;
      v134.y = (float)((float)v26 * (float)v24) + endpos.y;
      v29 = this->clip;
      v134.z = (float)((float)v27 * (float)v24) + endpos.z;
      idClip::Translation(
        this: (idClip *)&normal,
        result: v29,
        a3: &v142,
        start: &v138.endpos,
        end: &v134,
        clipModel: v28,
        startAxis: &v138.endAxis,
        clipMask: v25,
        passEntityNumber: v64,
        moveClipModel: v67,
        userName: v70,
        a12: v73,
        a13: v76,
        a14: v79,
        a15: v82,
        a16: v85,
        a17: v88,
        a18: v91,
        a19: v94,
        a20: v97,
        a21: v100,
        a22: v103,
        a23: v106,
        a24: v109,
        a25: v112,
        a26: v115,
        a27: v118,
        a28: v120,
        a29: v123,
        a30: true,
        a31: v126,
        a32: 0);
      trace_t::operator=(this: &v137, __that: &v142);
      v137.endpos.x = v142.endpos.x;
      v137.endpos.y = v142.endpos.y;
      v137.endpos.z = v142.endpos.z;
      v137.endAxis.mat[0].x = v138.endAxis.mat[0].x;
      v137.endAxis.mat[0].y = v138.endAxis.mat[0].y;
      v137.endAxis.mat[0].z = v138.endAxis.mat[0].z;
      v137.endAxis.mat[1].x = v138.endAxis.mat[1].x;
      v137.endAxis.mat[1].y = v138.endAxis.mat[1].y;
      v137.endAxis.mat[1].z = v138.endAxis.mat[1].z;
      v137.fraction = (float)(v142.fraction + v138.fraction) * (float)0.5;
      v137.endAxis.mat[2].x = v138.endAxis.mat[2].x;
      v137.endAxis.mat[2].y = v138.endAxis.mat[2].y;
      v137.endAxis.mat[2].z = v138.endAxis.mat[2].z;
    }
    v30 = &v140;
    v31 = &v137.endpos.z;
    v136 = v137.endpos;
    for ( i = 9; i != 0; --i )
    {
      ++v31;
      v30 += 4;
      *(float *)v30 = *v31;
    }
    v132 = vec3_origin;
    if ( !omniContactsDir )
    {
      v33 = this->gravityNormal.y;
      v34 = this->gravityNormal.z;
      v132.x = this->gravityNormal.x;
      v132.y = v33;
      v132.z = v34;
    }
    idClip::Contacts(
      this: (idClip *)&normal,
      result: this->clip,
      a3: &v146,
      start: &v136,
      dir: &v132,
      depth: 0.5,
      clipModel: (const idClipModel *)this->clipMask,
      startAxis: (const idMat3 *)this->clipModel,
      clipMask: (int)v141,
      passEntityNumber: v62,
      userName: v65,
      a12: (int)v68,
      a13: v71,
      a14: v74,
      a15: v77,
      a16: v80,
      a17: v83,
      a18: v86,
      a19: v89,
      a20: v92,
      a21: v95,
      a22: v98,
      a23: v101,
      a24: v104,
      a25: v107,
      a26: v110,
      a27: v113,
      a28: v116,
      a29: (const idBounds *)this->clipMask,
      a30: v121,
      a31: (const idClipModel *)this->entityNumber,
      a32: v124,
      a33: (int)"w:\\tech5\\tungsten\\game\\entities\\Robot.cpp(364) : ResolveContacts");
    v35 = v137.c.normal.y;
    v36 = v137.c.normal.z;
    p_lastCollisionNormal->x = v137.c.normal.x;
    p_lastCollisionNormal->y = v35;
    p_lastCollisionNormal->z = v36;
    idPhysics::UpdateCollisionResidency(this, contact: &v137.c);
    this->ClearContacts(this);
    v37 = 0;
    if ( v146.numContacts > 0 )
    {
      contacts = v146.contacts;
      do
      {
        idList<contactInfo_t,77>::Append(this: &this->contacts, obj: contacts);
        ++v37;
        ++contacts;
      }
      while ( v37 < v146.numContacts );
    }
    idPhysics_DynamicBase::AddContactPhysicsForContacts(this);
    v39 = 0;
    if ( this->contacts.num > 0 )
    {
      v40 = 0;
      do
      {
        v41 = &this->contacts.list[v40];
        v42 = v41->point.z;
        x = v41->point.x;
        v130 = v41->point.y;
        v131 = v42;
        v129.mat[2].z = x;
        v44 = v41->normal.y;
        v45 = v41->normal.z;
        normal.x = v41->normal.x;
        normal.z = v45;
        normal.y = v44;
        GameMsPerFrame = idGameTimeManager::GetGameMsPerFrame(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        clientGame->renderWorld->DebugPoint(
          this: clientGame->renderWorld,
          a2: (const idVec4 *)&idColor::colorRed,
          a3: (const idVec3 *)&v129.mat[2].z,
          a4: GameMsPerFrame,
          a5: false);
        idGameTimeManager::GetGameMsPerFrame(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        v135[0] = v129.mat[2].z + (float)(normal.x * arrowLn);
        v135[1] = v130 + (float)(normal.y * arrowLn);
        v135[2] = v131 + (float)(normal.z * arrowLn);
        ((void (__fastcall *)(idRenderWorld *, idColor *, float *, float *, double))clientGame->renderWorld->DebugArrow3)(
          a1: clientGame->renderWorld,
          a2: &idColor::colorGreen,
          a3: &v129.mat[2].z,
          a4: v135,
          a5: arrowSz);
        ++v39;
        ++v40;
      }
      while ( v39 < this->contacts.num );
    }
    *(idVec3 *)&v129.mat[1].y = v137.c.point;
    normal = v137.c.normal;
    v47 = idGameTimeManager::GetGameMsPerFrame(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    clientGame->renderWorld->DebugPoint(
      this: clientGame->renderWorld,
      a2: (const idVec4 *)&idColor::colorRed,
      a3: (const idVec3 *)&v129.mat[1].y,
      a4: v47,
      a5: false);
    idGameTimeManager::GetGameMsPerFrame(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    v133[0] = v129.mat[1].y + (float)(normal.x * arrowLn);
    v133[1] = v129.mat[1].z + (float)(normal.y * arrowLn);
    v133[2] = v129.mat[2].x + (float)(normal.z * arrowLn);
    ((void (__fastcall *)(idRenderWorld *, idColor *, float *, float *, double))clientGame->renderWorld->DebugArrow3)(
      a1: clientGame->renderWorld,
      a2: &idColor::colorGreen,
      a3: &v129.mat[1].y,
      a4: v133,
      a5: arrowSz);
    this->ActivateContactPhysics(this);
    v48 = false;
    if ( ((LODWORD(this->gravityNormal.y) | LODWORD(this->gravityNormal.x) | LODWORD(this->gravityNormal.z)) & 0x7FFFFFFF) != 0
      && this->contacts.num > 0 )
    {
      v49 = 0;
      normal = vec3_origin;
      v50 = vec3_origin.y;
      v51 = vec3_origin.z;
      v52 = vec3_origin.x;
      list = this->contacts.list;
      v54 = 0;
      do
      {
        ++v49;
        v52 = (float)(list[v54].normal.x + (float)v52);
        v50 = (float)(list[v54].normal.y + (float)v50);
        v51 = (float)(list[v54++].normal.z + (float)v51);
      }
      while ( v49 < this->contacts.num );
      _FP1 = (float)((float)((float)((float)v52 * (float)v52)
                           + (float)((float)((float)v51 * (float)v51) + (float)((float)v50 * (float)v50)))
                   - idMath::FLT_SMALLEST_NON_DENORMAL);
      __asm { fsel      f5, f1, f2, f10 }
      v57 = __frsqrte(_FP5);
      v58 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v57
                                                                                          * (float)((float)((float)((float)v52 * (float)v52) + (float)((float)((float)v51 * (float)v51) + (float)((float)v50 * (float)v50)))
                                                                                                  * (float)0.5))
                                                                                  * (float)v57)
                                                                          - (float)1.5)
                                                          * (float)v57)
                                                  * (float)((float)((float)((float)v52 * (float)v52)
                                                                  + (float)((float)((float)v51 * (float)v51)
                                                                          + (float)((float)v50 * (float)v50)))
                                                          * (float)0.5))
                                          * (float)((float)-(float)((float)((float)((float)v57
                                                                                  * (float)((float)((float)((float)v52 * (float)v52)
                                                                                                  + (float)((float)((float)v51 * (float)v51) + (float)((float)v50 * (float)v50)))
                                                                                          * (float)0.5))
                                                                          * (float)v57)
                                                                  - (float)1.5)
                                                  * (float)v57))
                                  - (float)1.5)
                  * (float)((float)-(float)((float)((float)((float)v57
                                                          * (float)((float)((float)((float)v52 * (float)v52)
                                                                          + (float)((float)((float)v51 * (float)v51)
                                                                                  + (float)((float)v50 * (float)v50)))
                                                                  * (float)0.5))
                                                  * (float)v57)
                                          - (float)1.5)
                          * (float)v57));
      v59 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v57 * (float)((float)((float)((float)v52 * (float)v52) + (float)((float)((float)v51 * (float)v51) + (float)((float)v50 * (float)v50))) * (float)0.5)) * (float)v57) - (float)1.5)
                                                                                                  * (float)v57)
                                                                                          * (float)((float)((float)((float)v52 * (float)v52) + (float)((float)((float)v51 * (float)v51) + (float)((float)v50 * (float)v50)))
                                                                                                  * (float)0.5))
                                                                                  * (float)((float)-(float)((float)((float)((float)v57 * (float)((float)((float)((float)v52 * (float)v52) + (float)((float)((float)v51 * (float)v51) + (float)((float)v50 * (float)v50))) * (float)0.5)) * (float)v57) - (float)1.5)
                                                                                          * (float)v57))
                                                                          - (float)1.5)
                                                          * (float)((float)-(float)((float)((float)((float)v57
                                                                                                  * (float)((float)((float)((float)v52 * (float)v52) + (float)((float)((float)v51 * (float)v51) + (float)((float)v50 * (float)v50))) * (float)0.5))
                                                                                          * (float)v57)
                                                                                  - (float)1.5)
                                                                  * (float)v57))
                                                  * (float)((float)((float)((float)v52 * (float)v52)
                                                                  + (float)((float)((float)v51 * (float)v51)
                                                                          + (float)((float)v50 * (float)v50)))
                                                          * (float)0.5))
                                          * (float)v58)
                                  - (float)1.5)
                  * (float)v58);
      v61 = (float)((float)v51
                  * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v57 * (float)((float)((float)((float)v52 * (float)v52) + (float)((float)((float)v51 * (float)v51) + (float)((float)v50 * (float)v50))) * (float)0.5)) * (float)v57) - (float)1.5) * (float)v57)
                                                                                                  * (float)((float)((float)((float)v52 * (float)v52) + (float)((float)((float)v51 * (float)v51) + (float)((float)v50 * (float)v50))) * (float)0.5))
                                                                                          * (float)((float)-(float)((float)((float)((float)v57 * (float)((float)((float)((float)v52 * (float)v52) + (float)((float)((float)v51 * (float)v51) + (float)((float)v50 * (float)v50))) * (float)0.5)) * (float)v57) - (float)1.5)
                                                                                                  * (float)v57))
                                                                                  - (float)1.5)
                                                                  * (float)((float)-(float)((float)((float)((float)v57 * (float)((float)((float)((float)v52 * (float)v52) + (float)((float)((float)v51 * (float)v51) + (float)((float)v50 * (float)v50))) * (float)0.5))
                                                                                                  * (float)v57)
                                                                                          - (float)1.5)
                                                                          * (float)v57))
                                                          * (float)((float)((float)((float)v52 * (float)v52)
                                                                          + (float)((float)((float)v51 * (float)v51)
                                                                                  + (float)((float)v50 * (float)v50)))
                                                                  * (float)0.5))
                                                  * (float)v58)
                                          - (float)1.5)
                          * (float)v58));
      v60 = (float)((float)v50
                  * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v57 * (float)((float)((float)((float)v52 * (float)v52) + (float)((float)((float)v51 * (float)v51) + (float)((float)v50 * (float)v50))) * (float)0.5)) * (float)v57) - (float)1.5) * (float)v57)
                                                                                                  * (float)((float)((float)((float)v52 * (float)v52) + (float)((float)((float)v51 * (float)v51) + (float)((float)v50 * (float)v50))) * (float)0.5))
                                                                                          * (float)((float)-(float)((float)((float)((float)v57 * (float)((float)((float)((float)v52 * (float)v52) + (float)((float)((float)v51 * (float)v51) + (float)((float)v50 * (float)v50))) * (float)0.5)) * (float)v57) - (float)1.5)
                                                                                                  * (float)v57))
                                                                                  - (float)1.5)
                                                                  * (float)((float)-(float)((float)((float)((float)v57 * (float)((float)((float)((float)v52 * (float)v52) + (float)((float)((float)v51 * (float)v51) + (float)((float)v50 * (float)v50))) * (float)0.5))
                                                                                                  * (float)v57)
                                                                                          - (float)1.5)
                                                                          * (float)v57))
                                                          * (float)((float)((float)((float)v52 * (float)v52)
                                                                          + (float)((float)((float)v51 * (float)v51)
                                                                                  + (float)((float)v50 * (float)v50)))
                                                                  * (float)0.5))
                                                  * (float)v58)
                                          - (float)1.5)
                          * (float)v58));
      if ( (float)((float)(this->gravityNormal.x * (float)((float)v59 * (float)v52))
                 + (float)((float)(this->gravityNormal.z * (float)v61) + (float)(this->gravityNormal.y * (float)v60))) < -this->minFloorCosine )
      {
        v48 = true;
        this->callbacks->Collide(
          this: this->callbacks,
          a2: this->physicsId,
          a3: &v137,
          a4: &this->currentState.linearVelocity);
      }
    }
    this->currentState.onGround = v48;
  }
}


// ========================================================================
// ?Translate@idPhysics_Robot@@UAAXABVidVec3@@H@Z
// EA  : 0x82CB2810
// RVA : 0x00CB2810
// PDB : w:\tech5\tungsten\game\entities\robot.cpp
// ========================================================================

void __fastcall idPhysics_Robot::Translate(idPhysics_Robot *this, const idVec3 *translation, int id)
{
  idClipModel *clipModel; // r11
  double v6; // fp9
  double v7; // fp7
  idVec3 v8; // [sp+50h] [-30h] BYREF

  idPhysics_Robot::ResolveCollisions(this);
  clipModel = this->clipModel;
  v6 = (float)(clipModel->origin.z + translation->z);
  v7 = (float)(clipModel->origin.y + translation->y);
  v8.x = clipModel->origin.x + translation->x;
  v8.z = v6;
  v8.y = v7;
  this->clipAxis = clipModel->axis;
  idClipModel::Link(
    this: this->clipModel,
    newEntityNumber: this->entityNumber,
    newPhysicsId: this->physicsId,
    newBodyId: 0,
    newOrigin: &v8,
    newAxis: &this->clipAxis);
  this->callbacks->ActivatePhysics(this: this->callbacks, a2: this->physicsId);
}


// ========================================================================
// ?Rotate@idPhysics_Robot@@UAAXABVidRotation@@H@Z
// EA  : 0x82CB2900
// RVA : 0x00CB2900
// PDB : w:\tech5\tungsten\game\entities\robot.cpp
// ========================================================================

void __fastcall idPhysics_Robot::Rotate(idPhysics_Robot *this, idRotation *rotation, int id)
{
  idClipModel *clipModel; // r11
  idMat3 *p_axis; // r30
  const idMat3 *v7; // r3
  idRotation v8; // [sp+50h] [-60h] BYREF

  idPhysics_Robot::ResolveCollisions(this);
  clipModel = this->clipModel;
  p_axis = &clipModel->axis;
  idRotation::operator*(this: &v8, result: rotation, v: &clipModel->origin);
  v7 = idRotation::ToMat3(this: rotation);
  this->clipAxis = *idMat3::operator*(this: (idMat3 *)&v8.vec.y, result: p_axis, a: v7);
  idClipModel::Link(
    this: this->clipModel,
    newEntityNumber: this->entityNumber,
    newPhysicsId: this->physicsId,
    newBodyId: 0,
    newOrigin: &v8.origin,
    newAxis: &this->clipAxis);
  this->callbacks->ActivatePhysics(this: this->callbacks, a2: this->physicsId);
}


// ========================================================================
// ??0idRobot@@QAA@XZ
// EA  : 0x82CB29D8
// RVA : 0x00CB29D8
// PDB : w:\tech5\tungsten\game\entities\robot.cpp
// ========================================================================

idRobot *__fastcall idRobot::idRobot(idRobot *this)
{
  breakableIsland_t *v2; // r3

  idAnimatedEntity::idAnimatedEntity(this);
  this->__vftable = (idRobot_vtbl *)&idRobot::`vftable';
  this->traceModel.str = &byte_8200D768;
  this->lowerBodyModel.allocedAndFlag = 20;
  this->lowerBodyModel.data = this->lowerBodyModel.baseBuffer;
  this->lowerBodyModel.len = 0;
  this->lowerBodyModel.baseBuffer[0] = 0;
  this->upperBodyModel.allocedAndFlag = 20;
  this->upperBodyModel.len = 0;
  this->upperBodyModel.data = this->upperBodyModel.baseBuffer;
  this->upperBodyModel.baseBuffer[0] = 0;
  this->cockpitSeatInfo.list = nullptr;
  this->cockpitSeatInfo.granularity = 0;
  this->cockpitSeatInfo.memTag = 5;
  this->cockpitSeatInfo.listStatic = 0;
  this->cockpitSeatInfo.size = 0;
  this->cockpitSeatInfo.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->cockpitSeatInfo);
  idPhysics_RigidBody::idPhysics_RigidBody(this: &this->physicsObjectRB);
  idPhysics_AF::idPhysics_AF(this: &this->physicsObjectAF);
  this->cockpitSeatState.list = nullptr;
  this->cockpitSeatState.granularity = 0;
  this->cockpitSeatState.memTag = 5;
  this->cockpitSeatState.listStatic = 0;
  this->cockpitSeatState.size = 0;
  this->cockpitSeatState.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->cockpitSeatState);
  this->enterTargets.list = nullptr;
  this->enterTargets.granularity = 0;
  this->enterTargets.memTag = 5;
  this->enterTargets.listStatic = 0;
  this->enterTargets.size = 0;
  this->enterTargets.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->enterTargets);
  this->exitTargets.list = nullptr;
  this->exitTargets.granularity = 0;
  this->exitTargets.memTag = 5;
  this->exitTargets.listStatic = 0;
  this->exitTargets.size = 0;
  this->exitTargets.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->exitTargets);
  this->secondaryFireTargets.list = nullptr;
  this->secondaryFireTargets.granularity = 0;
  this->secondaryFireTargets.memTag = 5;
  this->secondaryFireTargets.listStatic = 0;
  this->secondaryFireTargets.size = 0;
  this->secondaryFireTargets.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->secondaryFireTargets);
  this->primaryFireTargets.list = nullptr;
  this->primaryFireTargets.granularity = 0;
  this->primaryFireTargets.memTag = 5;
  this->primaryFireTargets.listStatic = 0;
  this->primaryFireTargets.size = 0;
  this->primaryFireTargets.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->primaryFireTargets);
  *(_BYTE *)&this->flags &= ~2u;
  this->maxHealth = 100.0;
  this->startHealth = 100.0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->cockpitSeatInfo);
  this->fpsCurrViewAngles = ang_zero;
  this->fpsLastViewAngles = ang_zero;
  this->fpsLastUpdate = 0;
  this->pilotSettings.maxSpeed = 500.0;
  this->pilotSettings.speedAccel = 15.0;
  this->pilotSettings.speedDecel = 10.0;
  this->pilotSettings.maxTurn = 4.0;
  this->pilotSettings.turnAccel = 0.1;
  this->pilotSettings.turnDecel = 0.25;
  this->currentSpeed = 0.0;
  this->currentTurnSpeed = 0.0;
  v2 = idList<breakableIsland_t,59>::Alloc(this: (idList<breakableIsland_t,59> *)&this->cockpitSeatInfo);
  v2->index = 0;
  v2->lowestPoint = 0.0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->enterTargets);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->exitTargets);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->secondaryFireTargets);
  this->primaryWeaponDecl = nullptr;
  this->secondaryWeaponDecl = nullptr;
  this->primaryWeapon = nullptr;
  this->secondaryWeapon = nullptr;
  this->currentViewPos = vec3_origin;
  this->currentViewAxis = mat3_identity;
  this->primaryMuzzleOffset = vec3_origin;
  this->secondaryMuzzleOffset = vec3_origin;
  this->primaryFireTime = 0;
  this->secondaryFireTime = 0;
  this->lowerOrigin = vec3_origin;
  this->lowerAxis = mat3_identity;
  this->upperAxis = mat3_identity;
  return this;
}


// ========================================================================
// __unwind$498193
// EA  : 0x82CB2E00
// RVA : 0x00CB2E00
// PDB : w:\tech5\tungsten\game\entities\robot.cpp
// ========================================================================

void _unwind_498193()
{
  int v0; // r12

  idAnimatedEntity::~idAnimatedEntity(this: *(idAnimatedEntity **)(v0 - 160 + 180));
}


// ========================================================================
// __unwind$498194
// EA  : 0x82CB2E28
// RVA : 0x00CB2E28
// PDB : w:\tech5\tungsten\game\entities\robot.cpp
// ========================================================================

void _unwind_498194()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 160 + 180) + 5204));
}


// ========================================================================
// __unwind$498195
// EA  : 0x82CB2E54
// RVA : 0x00CB2E54
// PDB : w:\tech5\tungsten\game\entities\robot.cpp
// ========================================================================

void _unwind_498195()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 160 + 180) + 5236));
}


// ========================================================================
// __unwind$498196
// EA  : 0x82CB2E80
// RVA : 0x00CB2E80
// PDB : w:\tech5\tungsten\game\entities\robot.cpp
// ========================================================================

void _unwind_498196()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 5268));
}


// ========================================================================
// __unwind$498197
// EA  : 0x82CB2EAC
// RVA : 0x00CB2EAC
// PDB : w:\tech5\tungsten\game\entities\robot.cpp
// ========================================================================

void _unwind_498197()
{
  int v0; // r12

  idPhysics_RigidBody::~idPhysics_RigidBody(this: (idPhysics_RigidBody *)(*(_DWORD *)(v0 - 160 + 180) + 5368));
}


// ========================================================================
// __unwind$498198
// EA  : 0x82CB2ED8
// RVA : 0x00CB2ED8
// PDB : w:\tech5\tungsten\game\entities\robot.cpp
// ========================================================================

void _unwind_498198()
{
  int v0; // r12

  idPhysics_AF::~idPhysics_AF(this: (idPhysics_AF *)(*(_DWORD *)(v0 - 160 + 180) + 5992));
}


// ========================================================================
// __unwind$498199
// EA  : 0x82CB2F04
// RVA : 0x00CB2F04
// PDB : w:\tech5\tungsten\game\entities\robot.cpp
// ========================================================================

void _unwind_498199()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 6904));
}


// ========================================================================
// __unwind$498200
// EA  : 0x82CB2F30
// RVA : 0x00CB2F30
// PDB : w:\tech5\tungsten\game\entities\robot.cpp
// ========================================================================

void _unwind_498200()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 7092));
}


// ========================================================================
// __unwind$498201
// EA  : 0x82CB2F5C
// RVA : 0x00CB2F5C
// PDB : w:\tech5\tungsten\game\entities\robot.cpp
// ========================================================================

void _unwind_498201()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 7108));
}


// ========================================================================
// __unwind$498202
// EA  : 0x82CB2F88
// RVA : 0x00CB2F88
// PDB : w:\tech5\tungsten\game\entities\robot.cpp
// ========================================================================

void _unwind_498202()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 7124));
}


// ========================================================================
// __unwind$498203
// EA  : 0x82CB2FB4
// RVA : 0x00CB2FB4
// PDB : w:\tech5\tungsten\game\entities\robot.cpp
// ========================================================================

void _unwind_498203()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 7140));
}


// ========================================================================
// ?PilotControl@idRobot@@AAAXH@Z
// EA  : 0x82CB2FE0
// RVA : 0x00CB2FE0
// PDB : w:\tech5\tungsten\game\entities\robot.cpp
// ========================================================================

void __fastcall idRobot::PilotControl(idRobot *this, int seatIndex)
{
  int GameMs; // r28
  int GameMsPerFrame; // r3
  idPresentablePlayer::moveBufferItem_t v6; // [sp+50h] [-B0h] BYREF

  if ( g_stopTime.valueInteger == 0 && g_freeCam.valueInteger != 1 )
  {
    cockpitUserCmd_t::cockpitUserCmd_t(this: &v6);
    idRobot::GetCockpitCommand(this, seatIndex, usercmd: (cockpitUserCmd_t *)&v6);
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    GameMsPerFrame = idGameTimeManager::GetGameMsPerFrame(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    idRobot::PilotControl_Local(
      this,
      seatIndex,
      usercmd: (const cockpitUserCmd_t *)&v6,
      startTime: GameMs - GameMsPerFrame,
      endTime: GameMs);
  }
}


// ========================================================================
// ?Evaluate@idPhysics_Robot@@UAA_NHH@Z
// EA  : 0x82CB3148
// RVA : 0x00CB3148
// PDB : w:\tech5\tungsten\game\entities\robot.cpp
// ========================================================================

int __fastcall idPhysics_Robot::Evaluate(idPhysics_Robot *this, unsigned int timeStepMSec, int endTimeMSec)
{
  double x; // fp7
  double y; // fp6
  double z; // fp5
  double maxStepHeight; // fp31
  double v10; // fp30
  double v11; // fp9
  double v12; // fp8
  double v13; // fp2
  double v14; // fp0
  double timeStep; // fp0
  double v16; // fp9
  double v17; // fp8
  double v18; // fp3
  double v19; // fp2
  idClipModel *clipModel; // r11
  const idClipModel *entityNumber; // r30
  const idBounds *clipMask; // r29
  idClip *clip; // r4
  double v24; // fp8
  double v25; // fp7
  int v26; // [sp+8h] [-E8h]
  int v27; // [sp+Ch] [-E4h]
  bool v28; // [sp+13h] [-DDh]
  const char *v29; // [sp+14h] [-DCh]
  int v30; // [sp+18h] [-D8h]
  int v31; // [sp+1Ch] [-D4h]
  int v32; // [sp+20h] [-D0h]
  int v33; // [sp+24h] [-CCh]
  int v34; // [sp+28h] [-C8h]
  int v35; // [sp+2Ch] [-C4h]
  int v36; // [sp+30h] [-C0h]
  int v37; // [sp+34h] [-BCh]
  int v38; // [sp+38h] [-B8h]
  int v39; // [sp+3Ch] [-B4h]
  int v40; // [sp+40h] [-B0h]
  int v41; // [sp+44h] [-ACh]
  int v42; // [sp+48h] [-A8h]
  int v43; // [sp+4Ch] [-A4h]
  int v44; // [sp+50h] [-A0h]
  int v45; // [sp+58h] [-98h]
  int v46; // [sp+60h] [-90h]
  int v47; // [sp+68h] [-88h]
  int v48; // [sp+70h] [-80h]
  int v49; // [sp+78h] [-78h]
  idVec3 v50; // [sp+80h] [-70h] BYREF
  idVec3 v51; // [sp+90h] [-60h] BYREF
  idVec3 v52; // [sp+A0h] [-50h] BYREF

  if ( this->clipModel == nullptr )
    return 0;
  this->ActivateContactPhysics(this);
  this->timeStepMS = timeStepMSec;
  *(_QWORD *)&v50.x = __PAIR64__(&unk_82390000, timeStepMSec);
  this->timeStep = (float)__SPAIR64__(&unk_82390000, timeStepMSec) * (float)0.001;
  idPhysics_Robot::ResolveCollisions(this);
  x = this->currentState.linearVelocity.x;
  y = this->currentState.linearVelocity.y;
  z = this->currentState.linearVelocity.z;
  maxStepHeight = this->maxStepHeight;
  v10 = (float)(this->maxStepHeight * (float)2.0);
  if ( this->currentState.onGround )
  {
    v13 = (float)(this->gravityNormal.x
                * (float)((float)(this->gravityNormal.x * this->currentState.linearVelocity.x)
                        + (float)((float)(this->gravityNormal.z * this->currentState.linearVelocity.z)
                                + (float)(this->gravityNormal.y * this->currentState.linearVelocity.y))));
    v14 = (float)(this->gravityNormal.z
                * (float)((float)(this->gravityNormal.x * this->currentState.linearVelocity.x)
                        + (float)((float)(this->gravityNormal.z * this->currentState.linearVelocity.z)
                                + (float)(this->gravityNormal.y * this->currentState.linearVelocity.y))));
    this->currentState.linearVelocity.y = this->currentState.linearVelocity.y
                                        - (float)(this->gravityNormal.y
                                                * (float)((float)(this->gravityNormal.x
                                                                * this->currentState.linearVelocity.x)
                                                        + (float)((float)(this->gravityNormal.z
                                                                        * this->currentState.linearVelocity.z)
                                                                + (float)(this->gravityNormal.y
                                                                        * this->currentState.linearVelocity.y))));
    this->currentState.linearVelocity.x = (float)x - (float)v13;
    this->currentState.linearVelocity.z = (float)z - (float)v14;
  }
  else
  {
    v11 = (float)(this->gravityVector.y * this->timeStep);
    v12 = (float)(this->gravityVector.z * this->timeStep);
    this->currentState.linearVelocity.x = this->currentState.linearVelocity.x
                                        + (float)(this->gravityVector.x * this->timeStep);
    this->currentState.linearVelocity.y = (float)v11 + (float)y;
    this->currentState.linearVelocity.z = (float)v12 + (float)z;
    this->currentState.angularVelocity.z = 0.0;
    this->currentState.angularVelocity.y = 0.0;
    this->currentState.angularVelocity.x = 0.0;
  }
  idVec3::ProjectOntoPlane(
    this: &this->currentState.linearVelocity,
    normal: &this->lastCollisionNormal,
    overBounce: 1.001);
  timeStep = this->timeStep;
  v16 = (float)(this->timeStep * this->currentState.linearVelocity.y);
  v17 = (float)(this->timeStep * this->currentState.linearVelocity.z);
  v50.x = this->currentState.linearVelocity.x * this->timeStep;
  v50.y = v16;
  v50.z = v17;
  v18 = (float)(this->currentState.angularVelocity.y * (float)timeStep);
  v19 = (float)(this->currentState.angularVelocity.z * (float)timeStep);
  v51.x = this->currentState.angularVelocity.x * (float)timeStep;
  v51.y = v18;
  v51.z = v19;
  idVec3::FixDenormals(this: &v50);
  idVec3::FixDenormals(this: &v51);
  if ( ((LODWORD(v50.y) | LODWORD(v50.z) | LODWORD(v50.x)) & 0x7FFFFFFF) != 0
    || ((LODWORD(v51.y) | LODWORD(v51.z) | LODWORD(v51.x)) & 0x7FFFFFFF) != 0 )
  {
    clipModel = this->clipModel;
    entityNumber = (const idClipModel *)this->entityNumber;
    clipMask = (const idBounds *)this->clipMask;
    clip = this->clip;
    v24 = (float)(clipModel->origin.z + v50.z);
    v25 = (float)(clipModel->origin.y + v50.y);
    v52.x = clipModel->origin.x + v50.x;
    v52.z = v24;
    v52.y = v25;
    this->stepMoveQuery.index = *(_QWORD *)&idClip::StepMove(
                                              this: (idClip *)&v50,
                                              result: clip,
                                              a3: nullptr,
                                              start: &clipModel->origin,
                                              end: &v52,
                                              downNormal: &this->gravityNormal,
                                              stepUp: maxStepHeight,
                                              stepDown: v10,
                                              clipModel: (const idClipModel *)"w:\\tech5\\tungsten\\game\\entities\\Robot.cpp(262) : StepMove",
                                              startAxis: &clipModel->axis,
                                              clipMask: v26,
                                              passEntityNumber: v27,
                                              moveClipModel: v28,
                                              userName: v29,
                                              a15: v30,
                                              a16: v31,
                                              a17: v32,
                                              a18: v33,
                                              a19: v34,
                                              a20: v35,
                                              a21: v36,
                                              a22: v37,
                                              a23: v38,
                                              a24: v39,
                                              a25: v40,
                                              a26: v41,
                                              a27: v42,
                                              a28: v43,
                                              a29: v44,
                                              a30: clipModel,
                                              a31: v45,
                                              a32: (int)&clipModel->axis,
                                              a33: v46,
                                              a34: clipMask,
                                              a35: v47,
                                              a36: entityNumber,
                                              a37: v48,
                                              clipModel_0_3: true,
                                              a39: v49,
                                              startAxis_0: (const idTraceModel **)"w:\\tech5\\tungsten\\game\\entities\\Robot.cpp(262) : StepMove")->world;
  }
  if ( this->IsOutsideWorld(this) )
    this->callbacks->DeactivatePhysics(this: this->callbacks, a2: this->physicsId);
  return 1;
}


// ========================================================================
// ?Think@idRobot@@UAAXXZ
// EA  : 0x82CB3418
// RVA : 0x00CB3418
// PDB : w:\tech5\tungsten\game\entities\robot.cpp
// ========================================================================

void __fastcall idRobot::Think(idRobot *this)
{
  int v2; // r30
  int v3; // r31
  int value; // r9
  idEntity *v5; // r3
  idPlayer *v6; // r3
  idPlayer *v7; // r3
  idPresentable *presentable; // r3
  int v9; // r3
  idPhysics *Physics; // r3
  float *v11; // r3
  idPhysics *v12; // r3
  float *v13; // r3
  double v14; // fp13
  double v15; // fp29
  double v16; // fp31
  double y; // fp28
  long double v18; // fp2
  long double v19; // fp2
  double v20; // fp0
  double z; // fp13
  double v22; // fp12
  double v23; // fp10
  double v24; // fp9
  double v25; // fp8
  double x; // fp7
  double v27; // fp6
  double v28; // fp5
  idMat3 *v29; // r3
  idPhysics *v30; // r3
  idBounds *v31; // r3
  idMat3 v32; // [sp+50h] [-160h] BYREF
  float v33; // [sp+74h] [-13Ch]
  float v34; // [sp+78h] [-138h]
  float v35; // [sp+7Ch] [-134h]
  float v36; // [sp+80h] [-130h]
  float v37; // [sp+84h] [-12Ch]
  float v38; // [sp+88h] [-128h]
  float v39; // [sp+8Ch] [-124h]
  float v40; // [sp+90h] [-120h]
  idMat3 v41; // [sp+A0h] [-110h] BYREF
  idMat3 v42; // [sp+D0h] [-E0h] BYREF
  idAngles v43[4]; // [sp+100h] [-B0h] BYREF
  idMat3 v44[2]; // [sp+130h] [-80h] BYREF

  if ( (this->thinkFlags & 1) != 0 && (unsigned __int8)idRobot::HasSeatTypeOccupant(this, type: COCKPITSEAT_PILOT) != 0 )
  {
    v2 = 0;
    if ( this->cockpitSeatInfo.num > 0 )
    {
      v3 = 0;
      do
      {
        if ( this->cockpitSeatInfo.list[v3].type == COCKPITSEAT_PILOT )
        {
          value = this->cockpitSeatState.list[v3].occupant.spawnId.value;
          if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
            && (v5 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
          {
            v6 = (idPlayer *)idEntity::CastTo(c: v5);
          }
          else
          {
            v6 = nullptr;
          }
          v7 = idPlayer::CastTo(c: v6);
          if ( v7 != nullptr )
          {
            presentable = v7->presentable;
            v9 = presentable != nullptr ? (int)presentable->GetPlayerInterface_2(this: presentable) : 0;
            if ( (*(unsigned __int8 (__fastcall **)(int))(*(_DWORD *)v9 + 300))(a1: v9) != 0 )
              idRobot::PilotControl(this, seatIndex: v2);
          }
        }
        ++v2;
        ++v3;
      }
      while ( v2 < this->cockpitSeatInfo.num );
    }
  }
  idEntity::RunPhysics(this);
  idMat3::operator*(this: &v41, result: &this->upperAxis, a: &this->lowerAxis);
  idMat3::ToAngles(this: (idMat3 *)&v32.mat[1].y, result: (idAngles *)&v41);
  Physics = idEntity::GetPhysics(this);
  v11 = (float *)Physics->GetAxis(this: Physics, a2: 0);
  this->lowerAxis.mat[0].x = *v11;
  this->lowerAxis.mat[0].y = v11[1];
  this->lowerAxis.mat[0].z = v11[2];
  this->lowerAxis.mat[1].x = v11[3];
  this->lowerAxis.mat[1].y = v11[4];
  this->lowerAxis.mat[1].z = v11[5];
  this->lowerAxis.mat[2].x = v11[6];
  this->lowerAxis.mat[2].y = v11[7];
  this->lowerAxis.mat[2].z = v11[8];
  v12 = idEntity::GetPhysics(this);
  v13 = (float *)v12->GetOrigin(this: v12, a2: 0);
  this->lowerOrigin.x = *v13;
  this->lowerOrigin.y = v13[1];
  this->lowerOrigin.z = v13[2];
  idMat3::operator*(this: &v42, result: &this->upperAxis, a: &this->lowerAxis);
  idMat3::ToAngles(this: &v32, result: (idAngles *)&v42);
  v32.mat[0].y = v32.mat[1].z;
  v32.mat[0].z = v32.mat[2].x;
  v14 = inheritPitch;
  if ( inheritPitch >= 0.0 )
  {
    if ( v14 > 1.0 )
      v14 = 1.0;
  }
  else
  {
    v14 = 0.0;
  }
  v15 = (float)((float)1.0 - (float)v14);
  v16 = (float)(v32.mat[0].x - v32.mat[1].y);
  y = v32.mat[1].y;
  if ( v16 >= 360.0 || v16 < 0.0 )
  {
    *(double *)&v18 = (float)((float)(v32.mat[0].x - v32.mat[1].y) * (float)0.0027777778);
    *((double *)&v18 + 1) = v32.mat[1].z;
    v19 = floor(x: v18);
    v16 = (float)-(float)((float)((float)*(double *)&v19 * (float)360.0) - (float)v16);
  }
  v20 = v16;
  if ( v16 > 180.0 )
    v20 = (float)((float)v16 - (float)360.0);
  v32.mat[0].x = (float)((float)v20 * (float)v15) + (float)y;
  z = this->lowerAxis.mat[2].z;
  v22 = this->lowerAxis.mat[1].z;
  v23 = this->lowerAxis.mat[2].y;
  v24 = this->lowerAxis.mat[1].y;
  v25 = this->lowerAxis.mat[0].y;
  x = this->lowerAxis.mat[2].x;
  v27 = this->lowerAxis.mat[1].x;
  v28 = this->lowerAxis.mat[0].x;
  v38 = this->lowerAxis.mat[0].z;
  v37 = v23;
  v36 = v24;
  v35 = v25;
  v34 = x;
  v33 = v27;
  v32.mat[2].z = v28;
  v39 = v22;
  v40 = z;
  v29 = idAngles::ToMat3(this: v43, result: &v32);
  this->upperAxis = *idMat3::operator*(this: v44, result: v29, a: (idMat3 *)&v32.mat[2].z);
  if ( (this->thinkFlags & 3) != 0 )
  {
    v30 = idEntity::GetPhysics(this);
    v31 = (idBounds *)v30->GetAbsBounds(this: v30, a2: -1);
    idEntity::UpdatePVSAreas(this, bounds: v31);
  }
  idAnimatedEntity::UpdateAnimation(this, forceNonDeferredBlend: false);
}


// ========================================================================
// ?Spawn@idRobot@@QAAXXZ
// EA  : 0x82CB37D0
// RVA : 0x00CB37D0
// PDB : w:\tech5\tungsten\game\entities\robot.cpp
// ========================================================================

void __fastcall idRobot::Spawn(idRobot *this)
{
  float y; // r6
  float z; // r4
  int *v3; // r10
  float *p_z; // r11
  int v6; // ctr
  idPhysics *Physics; // r3
  int num; // r30
  int size; // r11
  idAFBody *v10; // r30
  int v11; // r9
  int v12; // r11
  cockpitSeatState_t *v13; // r10
  float *v14; // r9
  int v15; // ctr
  idSysMutex *p_viewNoteMutex; // r10
  float *v17; // r9
  int v18; // ctr
  idSysMutex *v19; // r10
  float *v20; // r9
  int v21; // ctr
  idSysMutex *v22; // r10
  float *v23; // r9
  int v24; // ctr
  idSysMutex *v25; // r10
  float *v26; // r9
  int v27; // ctr
  idSysMutex *v28; // r10
  float *v29; // r9
  int v30; // ctr
  idSysMutex *v31; // r10
  float *v32; // r9
  int v33; // ctr
  idSysMutex *v34; // r10
  idSysMutex *v35; // r11
  int v36; // ctr
  float *v37; // r10
  int v38; // r28
  idClipModel *v39; // r3
  idClipModel *v40; // r26
  int v41; // r5
  idPhysics_Robot *v42; // r3
  int v43; // r5
  int entityNumber; // r6
  int v45; // r5
  idMat3 *v46; // r4
  idAFBody *v47; // r3
  int v48; // r10
  int v49; // r9
  int v50; // r8
  int v51; // r7
  int v52; // r6
  int v53; // r5
  idAFBody::afBodyFlags_t fl; // r6
  idPhysics *v55; // r3
  idPhysics *v56; // r3
  idPhysics *v57; // r3
  idPhysics *v58; // r3
  idPhysics *v59; // r3
  idPhysics *v60; // r3
  const idDeclWeapon *primaryWeaponDecl; // r3
  idWeapon *v62; // r3
  idWeapon *v63; // r30
  idWeapon *v64; // r3
  const idDeclWeapon *secondaryWeaponDecl; // r3
  idWeapon *v66; // r3
  idWeapon *v67; // r30
  idWeapon *v68; // r3
  idPhysics *v71; // r3
  float *v72; // r3
  idPhysics *v73; // r3
  float *v74; // r3
  int v75; // [sp+8h] [-3118h]
  int v76; // [sp+Ch] [-3114h]
  int v77; // [sp+10h] [-3110h]
  int v78; // [sp+14h] [-310Ch]
  int v79; // [sp+18h] [-3108h]
  idAFBody *v80; // [sp+1Ch] [-3104h]
  idVec2 v81; // [sp+58h] [-30C8h] BYREF
  idVec2 v82; // [sp+60h] [-30C0h] BYREF
  _DWORD v83[5]; // [sp+68h] [-30B8h] BYREF
  int v84; // [sp+7Ch] [-30A4h] BYREF
  int v85; // [sp+80h] [-30A0h] BYREF
  idTraceModel v86; // [sp+B0h] [-3070h] BYREF
  int v87; // [sp+C70h] [-24B0h]
  int v88; // [sp+C74h] [-24ACh]
  int v89; // [sp+C78h] [-24A8h]
  int v90; // [sp+C7Ch] [-24A4h]
  int v91; // [sp+C80h] [-24A0h]
  float v92; // [sp+C84h] [-249Ch]
  float v93; // [sp+C88h] [-2498h]
  float v94[8]; // [sp+C8Ch] [-2494h] BYREF
  __int16 v95; // [sp+CACh] [-2474h]
  __int16 v96; // [sp+CAEh] [-2472h]
  int v97; // [sp+1270h] [-1EB0h]
  int v98; // [sp+1274h] [-1EACh]
  int v99; // [sp+1278h] [-1EA8h]
  int v100; // [sp+127Ch] [-1EA4h]
  int v101; // [sp+1280h] [-1EA0h]
  float v102; // [sp+1284h] [-1E9Ch]
  float v103; // [sp+1288h] [-1E98h]
  float v104[8]; // [sp+128Ch] [-1E94h] BYREF
  __int16 v105; // [sp+12ACh] [-1E74h]
  __int16 v106; // [sp+12AEh] [-1E72h]
  int v107; // [sp+1870h] [-18B0h]
  int v108; // [sp+1874h] [-18ACh]
  int v109; // [sp+1878h] [-18A8h]
  int v110; // [sp+187Ch] [-18A4h]
  int v111; // [sp+1880h] [-18A0h]
  float v112; // [sp+1884h] [-189Ch]
  float v113; // [sp+1888h] [-1898h]
  float v114[8]; // [sp+188Ch] [-1894h] BYREF
  __int16 v115; // [sp+18ACh] [-1874h]
  __int16 v116; // [sp+18AEh] [-1872h]
  int v117; // [sp+1E70h] [-12B0h]
  int v118; // [sp+1E74h] [-12ACh]
  int v119; // [sp+1E78h] [-12A8h]
  int v120; // [sp+1E7Ch] [-12A4h]
  int v121; // [sp+1E80h] [-12A0h]
  float v122; // [sp+1E84h] [-129Ch]
  float v123; // [sp+1E88h] [-1298h]
  float v124[8]; // [sp+1E8Ch] [-1294h] BYREF
  __int16 v125; // [sp+1EACh] [-1274h]
  __int16 v126; // [sp+1EAEh] [-1272h]
  int v127; // [sp+2470h] [-CB0h]
  int v128; // [sp+2474h] [-CACh]
  int v129; // [sp+2478h] [-CA8h]
  int v130; // [sp+247Ch] [-CA4h]
  int v131; // [sp+2480h] [-CA0h]
  float v132; // [sp+2484h] [-C9Ch]
  float v133; // [sp+2488h] [-C98h]
  float v134[8]; // [sp+248Ch] [-C94h] BYREF
  __int16 v135; // [sp+24ACh] [-C74h]
  __int16 v136; // [sp+24AEh] [-C72h]
  int v137; // [sp+2A70h] [-6B0h]
  int v138; // [sp+2A74h] [-6ACh]
  int v139; // [sp+2A78h] [-6A8h]
  int v140; // [sp+2A7Ch] [-6A4h]
  int v141; // [sp+2A80h] [-6A0h]
  float v142; // [sp+2A84h] [-69Ch]
  float v143; // [sp+2A88h] [-698h]
  float v144[8]; // [sp+2A8Ch] [-694h] BYREF
  __int16 v145; // [sp+2AACh] [-674h]
  __int16 v146; // [sp+2AAEh] [-672h]
  int v147; // [sp+3070h] [-B0h]
  int v148; // [sp+3074h] [-ACh]
  int v149; // [sp+3078h] [-A8h]
  int v150; // [sp+307Ch] [-A4h]
  int v151; // [sp+3080h] [-A0h]
  float v152; // [sp+3084h] [-9Ch]
  float v153; // [sp+3088h] [-98h]
  float v154[8]; // [sp+308Ch] [-94h] BYREF
  __int16 v155; // [sp+30ACh] [-74h]
  __int16 v156; // [sp+30AEh] [-72h]

  y = this->spawnPosition.y;
  z = this->spawnPosition.z;
  v3 = &v84;
  p_z = &this->spawnPosition.z;
  v83[0] = LODWORD(this->spawnPosition.x);
  sbTempReset = true;
  v6 = 9;
  *(float *)&v83[1] = y;
  *(float *)&v83[2] = z;
  do
  {
    *++v3 = *(_DWORD *)++p_z;
    --v6;
  }
  while ( v6 != 0 );
  Physics = idEntity::GetPhysics(this);
  Physics->UnlinkClip(this: Physics);
  num = this->cockpitSeatInfo.num;
  if ( num <= this->cockpitSeatState.size
    || (unsigned __int8)idList<cockpitSeatState_t,5>::Resize(
                          this: &this->cockpitSeatState,
                          newsize: this->cockpitSeatInfo.num) != 0 )
  {
    size = this->cockpitSeatState.size;
    if ( num < size )
      size = num;
    this->cockpitSeatState.num = size;
  }
  v10 = nullptr;
  v11 = 0;
  if ( this->cockpitSeatInfo.num > 0 )
  {
    v12 = 0;
    do
    {
      ++v11;
      v13 = &this->cockpitSeatState.list[v12++];
      v13->occupant.spawnId.value = 0x1FFF;
      v13->timeStamp = 0;
    }
    while ( v11 < this->cockpitSeatInfo.num );
  }
  memset(&v86.type, 0, 20);
  v14 = &v86.offset.z;
  v15 = 6;
  p_viewNoteMutex = &analysisClient.viewNoteMutex;
  v86.offset.x = 0.0;
  v86.offset.y = 0.0;
  v86.offset.z = 0.0;
  do
  {
    ++p_viewNoteMutex;
    *++v14 = *(float *)&p_viewNoteMutex->handle;
    --v15;
  }
  while ( v15 != 0 );
  v86.radius = 0.0;
  v17 = v94;
  v92 = 0.0;
  v93 = 0.0;
  v86.isConvex = false;
  v94[0] = 0.0;
  v86.pad[2] = 0;
  v86.pad[1] = 0;
  v18 = 6;
  v86.pad[0] = 0;
  v87 = 0;
  v19 = &analysisClient.viewNoteMutex;
  v88 = 0;
  v89 = 0;
  v90 = 0;
  v91 = 0;
  do
  {
    ++v19;
    *++v17 = *(float *)&v19->handle;
    --v18;
  }
  while ( v18 != 0 );
  v94[7] = 0.0;
  v20 = v104;
  v102 = 0.0;
  v103 = 0.0;
  v104[0] = 0.0;
  v96 = 0;
  v21 = 6;
  v95 = 0;
  v97 = 0;
  v22 = &analysisClient.viewNoteMutex;
  v98 = 0;
  v99 = 0;
  v100 = 0;
  v101 = 0;
  do
  {
    ++v22;
    *++v20 = *(float *)&v22->handle;
    --v21;
  }
  while ( v21 != 0 );
  v104[7] = 0.0;
  v23 = v114;
  v112 = 0.0;
  v113 = 0.0;
  v114[0] = 0.0;
  v106 = 0;
  v24 = 6;
  v105 = 0;
  v107 = 0;
  v25 = &analysisClient.viewNoteMutex;
  v108 = 0;
  v109 = 0;
  v110 = 0;
  v111 = 0;
  do
  {
    ++v25;
    *++v23 = *(float *)&v25->handle;
    --v24;
  }
  while ( v24 != 0 );
  v114[7] = 0.0;
  v26 = v124;
  v122 = 0.0;
  v123 = 0.0;
  v124[0] = 0.0;
  v116 = 0;
  v27 = 6;
  v115 = 0;
  v117 = 0;
  v28 = &analysisClient.viewNoteMutex;
  v118 = 0;
  v119 = 0;
  v120 = 0;
  v121 = 0;
  do
  {
    ++v28;
    *++v26 = *(float *)&v28->handle;
    --v27;
  }
  while ( v27 != 0 );
  v124[7] = 0.0;
  v29 = v134;
  v132 = 0.0;
  v133 = 0.0;
  v134[0] = 0.0;
  v126 = 0;
  v30 = 6;
  v125 = 0;
  v127 = 0;
  v31 = &analysisClient.viewNoteMutex;
  v128 = 0;
  v129 = 0;
  v130 = 0;
  v131 = 0;
  do
  {
    ++v31;
    *++v29 = *(float *)&v31->handle;
    --v30;
  }
  while ( v30 != 0 );
  v134[7] = 0.0;
  v32 = v144;
  v142 = 0.0;
  v143 = 0.0;
  v144[0] = 0.0;
  v136 = 0;
  v33 = 6;
  v135 = 0;
  v137 = 0;
  v34 = &analysisClient.viewNoteMutex;
  v138 = 0;
  v139 = 0;
  v140 = 0;
  v141 = 0;
  do
  {
    ++v34;
    *++v32 = *(float *)&v34->handle;
    --v33;
  }
  while ( v33 != 0 );
  v144[7] = 0.0;
  v152 = 0.0;
  v153 = 0.0;
  v146 = 0;
  v35 = &analysisClient.viewNoteMutex;
  v145 = 0;
  v36 = 6;
  v37 = v154;
  v154[0] = 0.0;
  v147 = 0;
  v148 = 0;
  v149 = 0;
  v150 = 0;
  v151 = 0;
  do
  {
    ++v35;
    *++v37 = *(float *)&v35->handle;
    --v36;
  }
  while ( v36 != 0 );
  v154[7] = 0.0;
  v156 = 0;
  v155 = 0;
  v38 = idCollisionModelManager::CompoundTrmFromModel(
          this: collisionModelManager,
          modelName: this->traceModel.str,
          trms: &v86,
          maxTrms: 8,
          invalidSubmodelIndices: nullptr,
          numInvalidIndices: nullptr);
  v39 = (idClipModel *)idMem::AllocWithLocation(
                         this: &mem,
                         location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                         size: 0xD8u,
                         tag: TAG_CLIPMODEL,
                         zeroBuffer: false,
                         align: ALIGN_16,
                         heap: HEAP_DEFAULTHEAP);
  if ( v39 != nullptr )
    v40 = idClipModel::idClipModel(
            this: v39,
            clip: &clientGame->clip,
            trm: &v86,
            numTraceModels: v38,
            material: nullptr);
  else
    v40 = nullptr;
  idClipModel::SetContents(this: v40, newContents: 197120);
  idClipModel::SetLinkedPosition(this: v40, newOrigin: &vec3_origin, newAxis: &mat3_identity);
  if ( usePhysicsObjectRB )
  {
    idPhysics::InitPhysics(
      this: &this->physicsObjectRB,
      clip_: &clientGame->clip,
      callbacks_: &this->physicsCallbacks,
      entityNumber_: this->entityNumber);
    ((void (__fastcall *)(idPhysics_RigidBody *, idClipModel *, double))this->physicsObjectRB.SetClipModel)(
      a1: &this->physicsObjectRB,
      a2: v40,
      a3: densityRB);
    this->physicsObjectRB.SetGravity(this: &this->physicsObjectRB, a2: &clientGame->gravity);
    this->physicsObjectRB.SetClipMask(this: &this->physicsObjectRB, a2: 107553, a3: -1);
    this->physicsObjectRB.SetContents(this: &this->physicsObjectRB, a2: 197120, a3: -1);
    idPhysics_RigidBody::SetBouncyness(this: &this->physicsObjectRB, b: 0.050000001);
    idPhysics_RigidBody::SetFriction(this: &this->physicsObjectRB, linear: 0.0, angular: 0.0, contact: 0.85000002);
    idEntity::SetPhysics(this, phys: &this->physicsObjectRB, a3: v41);
  }
  else if ( usePhysicsObjectRobot )
  {
    v42 = (idPhysics_Robot *)idMem::AllocWithLocation(
                               this: &mem,
                               location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                               size: 0x120u,
                               tag: TAG_GAME,
                               zeroBuffer: false,
                               align: ALIGN_16,
                               heap: HEAP_DEFAULTHEAP);
    if ( v42 != nullptr )
      v10 = (idAFBody *)idPhysics_Robot::idPhysics_Robot(this: v42);
    idPhysics::InitPhysics(
      this: (idPhysics *)v10,
      clip_: &clientGame->clip,
      callbacks_: &this->physicsCallbacks,
      entityNumber_: this->entityNumber);
    ((void (__fastcall *)(idAFBody *, idClipModel *, double))v10->Serialize)(a1: v10, a2: v40, a3: 0.0099999998);
    ((void (__fastcall *)(idAFBody *, idVec3 *))v10->__vftable[12].dtr_idAFBody)(a1: v10, a2: &clientGame->gravity);
    ((void (__fastcall *)(idAFBody *, int, int))v10->__vftable[4].dtr_idAFBody)(a1: v10, a2: 107553, a3: -1);
    ((void (__fastcall *)(idAFBody *, int, int))v10->__vftable[3].dtr_idAFBody)(a1: v10, a2: 197120, a3: -1);
    idEntity::SetPhysics(this, phys: (idPhysics *)v10, a3: v43);
  }
  else
  {
    entityNumber = this->entityNumber;
    v81.x = 20.0;
    v81.y = 30.0;
    v82.x = 40.0;
    v82.y = 60.0;
    idPhysics::InitPhysics(
      this: &this->physicsObjectAF.idPhysics_DynamicBase,
      clip_: &clientGame->clip,
      callbacks_: &this->physicsCallbacks,
      entityNumber_: entityNumber);
    this->physicsObjectAF.SetGravity(this: &this->physicsObjectAF, a2: &clientGame->gravity);
    this->physicsObjectAF.SetClipMask(this: &this->physicsObjectAF, a2: 107553, a3: -1);
    idPhysics_AF::SetDefaultFriction(
      this: &this->physicsObjectAF,
      linear: 0.0099999998,
      angular: 0.0099999998,
      contact: 0.80000001);
    idPhysics_AF::SetSuspendSpeed(this: &this->physicsObjectAF, velocity: &v81, acceleration: &v82);
    idPhysics_AF::SetSuspendTolerance(
      this: &this->physicsObjectAF,
      noMoveTime: 1.0,
      noMoveTranslation: 10.0,
      noMoveRotation: 10.0);
    idPhysics_AF::SetSuspendTime(this: &this->physicsObjectAF, minTime: -1.0, maxTime: -1.0);
    this->physicsObjectAF.selfCollision = false;
    idEntity::SetPhysics(this, phys: &this->physicsObjectAF.idPhysics_DynamicBase, a3: v45);
    v47 = (idAFBody *)idMem::AllocWithLocation(
                        this: &mem,
                        location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                        size: 0x330u,
                        tag: TAG_AF,
                        zeroBuffer: false,
                        align: ALIGN_16,
                        heap: HEAP_DEFAULTHEAP);
    if ( v47 != nullptr )
      v10 = idAFBody::idAFBody(this: v47, name: "body1", clipModel: v40, density: bodyDensity);
    idAFBody::SetDensity(this: v10, density: bodyDensity, inertiaScale: v46, a4: &mat3_identity);
    idAFBody::SetFriction(
      this: v10,
      linear: bodyLinearFriction,
      angular: bodyAngularFriction,
      contact: bodyContactFriction);
    idPhysics_AF::AddBody(
      this: &this->physicsObjectAF,
      body: v10,
      a3: v53,
      a4: v52,
      a5: v51,
      a6: v50,
      a7: v49,
      a8: v48,
      a9: v75,
      a10: v76,
      a11: v77,
      a12: v78,
      a13: v79,
      a14: v80);
    fl = v10->fl;
    v10->clipMask = 107553;
    v10->fl = (idAFBody::afBodyFlags_t)(*(_BYTE *)&fl & 0x3F | 0x80);
    idAFBody::SetBouncyness(this: v10, bounce: bodyBouncyness);
    *(_BYTE *)&v10->fl &= ~2u;
  }
  v55 = idEntity::GetPhysics(this);
  v55->SetAxis(this: v55, a2: (const idMat3 *)&v85, a3: -1);
  v56 = idEntity::GetPhysics(this);
  v56->SetOrigin(this: v56, a2: (const idVec3 *)v83, a3: -1);
  v57 = idEntity::GetPhysics(this);
  v57->SetAngularVelocity(this: v57, a2: &vec3_origin, a3: 0);
  v58 = idEntity::GetPhysics(this);
  v58->SetLinearVelocity(this: v58, a2: &vec3_origin, a3: 0);
  v59 = idEntity::GetPhysics(this);
  v59->EnableClip(this: v59);
  v60 = idEntity::GetPhysics(this);
  v60->Activate(this: v60);
  primaryWeaponDecl = this->primaryWeaponDecl;
  if ( primaryWeaponDecl != nullptr )
  {
    v62 = (idWeapon *)idInventoryItem::Create(decl: primaryWeaponDecl);
    v63 = v62;
    if ( v62 != nullptr )
    {
      v64 = idWeapon::CastTo(c: v62);
      this->primaryWeapon = v64;
      if ( v64 == nullptr )
        ((void (__fastcall *)(idWeapon *, int))v63->dtr_idClass)(a1: v63, a2: 1);
    }
  }
  secondaryWeaponDecl = this->secondaryWeaponDecl;
  if ( secondaryWeaponDecl != nullptr )
  {
    v66 = (idWeapon *)idInventoryItem::Create(decl: secondaryWeaponDecl);
    v67 = v66;
    if ( v66 != nullptr )
    {
      v68 = idWeapon::CastTo(c: v66);
      this->secondaryWeapon = v68;
      if ( v68 == nullptr )
        ((void (__fastcall *)(idWeapon *, int))v67->dtr_idClass)(a1: v67, a2: 1);
    }
  }
  _FP12 = (float)(this->startHealth - this->maxHealth);
  __asm { fsel      f11, f12, f0, f13 }
  this->health = _FP11;
  v71 = idEntity::GetPhysics(this);
  v72 = (float *)v71->GetOrigin(this: v71, a2: 0);
  this->lowerOrigin.x = *v72;
  this->lowerOrigin.y = v72[1];
  this->lowerOrigin.z = v72[2];
  v73 = idEntity::GetPhysics(this);
  v74 = (float *)v73->GetAxis(this: v73, a2: 0);
  this->lowerAxis.mat[0].x = *v74;
  this->lowerAxis.mat[0].y = v74[1];
  this->lowerAxis.mat[0].z = v74[2];
  this->lowerAxis.mat[1].x = v74[3];
  this->lowerAxis.mat[1].y = v74[4];
  this->lowerAxis.mat[1].z = v74[5];
  this->lowerAxis.mat[2].x = v74[6];
  this->lowerAxis.mat[2].y = v74[7];
  this->lowerAxis.mat[2].z = v74[8];
  this->upperAxis = mat3_identity;
}


// ========================================================================
// __unwind$499016
// EA  : 0x82CB4214
// RVA : 0x00CB4214
// PDB : w:\tech5\tungsten\game\entities\robot.cpp
// ========================================================================

void _unwind_499016()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 12576 + 80), tag: TAG_CLIPMODEL);
}


// ========================================================================
// __unwind$499017
// EA  : 0x82CB4240
// RVA : 0x00CB4240
// PDB : w:\tech5\tungsten\game\entities\robot.cpp
// ========================================================================

void _unwind_499017()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 12576 + 80), tag: TAG_GAME);
}


// ========================================================================
// __unwind$499018
// EA  : 0x82CB426C
// RVA : 0x00CB426C
// PDB : w:\tech5\tungsten\game\entities\robot.cpp
// ========================================================================

void _unwind_499018()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 12576 + 80), tag: TAG_AF);
}


// ========================================================================
// `dynamic initializer for 'robot_fps_view_lerp''
// EA  : 0x833781D8
// RVA : 0x013781D8
// PDB : w:\tech5\tungsten\game\entities\robot.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__robot_fps_view_lerp__()
{
  idCVar::idCVar(
    this: &robot_fps_view_lerp,
    name: "robot_fps_view_lerp",
    value: "100",
    flags: 4,
    description: "ms to interpolate the fps view over",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__robot_fps_view_lerp__);
}


// ========================================================================
// `dynamic initializer for 'robot_fps_stickAngle_minPitch''
// EA  : 0x83378230
// RVA : 0x01378230
// PDB : w:\tech5\tungsten\game\entities\robot.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__robot_fps_stickAngle_minPitch__()
{
  idCVar::idCVar(
    this: &robot_fps_stickAngle_minPitch,
    name: "robot_fps_stickAngle_minPitch",
    value: "-28",
    flags: 4,
    description: "Min pitch allowed during fps view",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__robot_fps_stickAngle_minPitch__);
}


// ========================================================================
// `dynamic initializer for 'robot_fps_stickAngle_maxPitch''
// EA  : 0x83378288
// RVA : 0x01378288
// PDB : w:\tech5\tungsten\game\entities\robot.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__robot_fps_stickAngle_maxPitch__()
{
  idCVar::idCVar(
    this: &robot_fps_stickAngle_maxPitch,
    name: "robot_fps_stickAngle_maxPitch",
    value: "10",
    flags: 4,
    description: "Max pitch allowed during fps view",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__robot_fps_stickAngle_maxPitch__);
}


// ========================================================================
// `dynamic initializer for 'robot_fps_stickAngle_minYaw''
// EA  : 0x833782E0
// RVA : 0x013782E0
// PDB : w:\tech5\tungsten\game\entities\robot.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__robot_fps_stickAngle_minYaw__()
{
  idCVar::idCVar(
    this: &robot_fps_stickAngle_minYaw,
    name: "robot_fps_stickAngle_minYaw",
    value: "-100",
    flags: 4,
    description: "Min yaw allowed during fps view",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__robot_fps_stickAngle_minYaw__);
}


// ========================================================================
// `dynamic initializer for 'robot_fps_stickAngle_maxYaw''
// EA  : 0x83378338
// RVA : 0x01378338
// PDB : w:\tech5\tungsten\game\entities\robot.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__robot_fps_stickAngle_maxYaw__()
{
  idCVar::idCVar(
    this: &robot_fps_stickAngle_maxYaw,
    name: "robot_fps_stickAngle_maxYaw",
    value: "100",
    flags: 4,
    description: "Max yaw allowed during fps view",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__robot_fps_stickAngle_maxYaw__);
}


// ========================================================================
// `dynamic initializer for 'robot_fps_stickLookSpeed_yaw''
// EA  : 0x83378390
// RVA : 0x01378390
// PDB : w:\tech5\tungsten\game\entities\robot.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__robot_fps_stickLookSpeed_yaw__()
{
  idCVar::idCVar(
    this: &robot_fps_stickLookSpeed_yaw,
    name: "robot_fps_stickLookSpeed_yaw",
    value: "5",
    flags: 4,
    description: "Yaw look speed when using game-pad",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__robot_fps_stickLookSpeed_yaw__);
}


// ========================================================================
// `dynamic initializer for 'robot_fps_stickLookSpeed_pitch''
// EA  : 0x833783E8
// RVA : 0x013783E8
// PDB : w:\tech5\tungsten\game\entities\robot.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__robot_fps_stickLookSpeed_pitch__()
{
  idCVar::idCVar(
    this: &robot_fps_stickLookSpeed_pitch,
    name: "robot_fps_stickLookSpeed_pitch",
    value: "5",
    flags: 4,
    description: "Pitch look speed when using game-pad",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__robot_fps_stickLookSpeed_pitch__);
}


// ========================================================================
// `dynamic initializer for 'robot_baseFOV''
// EA  : 0x83378440
// RVA : 0x01378440
// PDB : w:\tech5\tungsten\game\entities\robot.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__robot_baseFOV__()
{
  idCVar::idCVar(
    this: &robot_baseFOV,
    name: "robot_baseFOV",
    value: "90",
    flags: 4,
    description: "FOV during robot control",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__robot_baseFOV__);
}


// ========================================================================
// `dynamic initializer for 'robot_camera_local_offset_x''
// EA  : 0x83378498
// RVA : 0x01378498
// PDB : w:\tech5\tungsten\game\entities\robot.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__robot_camera_local_offset_x__()
{
  idCVar::idCVar(
    this: &robot_camera_local_offset_x,
    name: "robot_camera_local_offset_x",
    value: "-30",
    flags: 4,
    description: "Local origin offset of camera on robot",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__robot_camera_local_offset_x__);
}


// ========================================================================
// `dynamic initializer for 'robot_camera_local_offset_y''
// EA  : 0x833784F0
// RVA : 0x013784F0
// PDB : w:\tech5\tungsten\game\entities\robot.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__robot_camera_local_offset_y__()
{
  idCVar::idCVar(
    this: &robot_camera_local_offset_y,
    name: "robot_camera_local_offset_y",
    value: "-30",
    flags: 4,
    description: "Local origin offset of camera on robot",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__robot_camera_local_offset_y__);
}


// ========================================================================
// `dynamic initializer for 'robot_camera_local_offset_z''
// EA  : 0x83378548
// RVA : 0x01378548
// PDB : w:\tech5\tungsten\game\entities\robot.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__robot_camera_local_offset_z__()
{
  idCVar::idCVar(
    this: &robot_camera_local_offset_z,
    name: "robot_camera_local_offset_z",
    value: "0",
    flags: 4,
    description: "Local origin offset of camera on robot",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__robot_camera_local_offset_z__);
}


// ========================================================================
// `dynamic initializer for 'robot_camera_height_offset''
// EA  : 0x833785A0
// RVA : 0x013785A0
// PDB : w:\tech5\tungsten\game\entities\robot.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__robot_camera_height_offset__()
{
  idCVar::idCVar(
    this: &robot_camera_height_offset,
    name: "robot_camera_height_offset",
    value: "150",
    flags: 4,
    description: "Height origin offset of camera on robot",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__robot_camera_height_offset__);
}


// ========================================================================
// `dynamic initializer for 'robot_use_crosshair''
// EA  : 0x833785F8
// RVA : 0x013785F8
// PDB : w:\tech5\tungsten\game\entities\robot.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__robot_use_crosshair__()
{
  idCVar::idCVar(
    this: &robot_use_crosshair,
    name: "robot_use_crosshair",
    value: "1",
    flags: 1,
    description: "Draw temporary crosshair when firing robots gun",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__robot_use_crosshair__);
}

